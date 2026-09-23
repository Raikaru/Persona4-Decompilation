"""Behavioral ELF-splitting tests; native linker checks use the same saved fixtures."""
from __future__ import annotations

from pathlib import Path
import struct
import sys
import unittest

sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'tools'))

from elf_text_runs import (ABS, ALLOC, EXEC, FILE, FUNC, GLOBAL, LOCAL, MWCATS,
    NOBITS, NOTYPE, OBJECT, PROGBITS, REL, RELA, SECTION, STRTAB, SYMTAB, UNDEF,
    WEAK, Elf32, Placement, Section, SplitError, Symbol, serialize, split_object, text_runs)


def words(*values):
    return struct.pack('<'+'I'*len(values),*values)


def fixture(suffix='', offset=0, literal_kind=7):
    """Real MIPS relocations across two text runs and a separate data owner.

    first materializes secret+4, loads small data and a literal, and calls helper;
    the dispatch table points at helper+4 and at the local text-section symbol.
    The same local names can be used by an unrelated object without collision.
    """
    def sec(name,kind=PROGBITS,flags=0,data=b'',**kw):
        return Section(name,kind,flags,data=data,size=len(data),**kw)
    sections=[Section('',0,align=0),sec('.symtab',SYMTAB,entsize=16,align=4,link=2),
        sec('.strtab',STRTAB),sec('.shstrtab',STRTAB),sec('.comment',data=b'link-runs-test\0'),
        sec('.text',flags=ALLOC|EXEC,data=words(0x3c020000,0x24420004,0x8f830000,0xc7800004,
            0x0c000000,0,0x03e00008,0),align=16),
        sec('.text',flags=ALLOC|EXEC,data=words(0x03e00008,0x24020009),align=16),
        sec('.text',flags=ALLOC|EXEC,data=words(0x03e00008,0x24020007),align=16),
        sec('.rodata',flags=ALLOC,data=words(4,4,0,0),align=8),
        sec('.sdata',flags=ALLOC|1,data=words(0x55667788),align=4),
        Section('.bss',NOBITS,ALLOC|1,size=16,align=16),
        sec('.lit4',flags=ALLOC,data=words(0x3f800000,0x40000000),align=4),
        sec('.mwcats',MWCATS,data=words((32 << 16) | 2,0),link=5,align=4)]
    symbols=[Symbol('',0,0,0,0,UNDEF),Symbol('fixture.c',0,0,FILE,0,ABS),
        Symbol('helper',0,8,FUNC,0,7),
        Symbol('secret',0,16,OBJECT,0,8),
        Symbol('small',0,4,OBJECT,0,9),
        Symbol('literal',0,8,OBJECT,0,11),
        Symbol('',0,0,SECTION,0,7),
        Symbol('private_bss',0,16,OBJECT,0,10),
        Symbol('first'+suffix,0,32,(GLOBAL<<4)|FUNC,0,5),
        Symbol('second'+suffix,0,8,(GLOBAL<<4)|FUNC,0,6),
        Symbol('maybe',0,0,(WEAK<<4)|NOTYPE,0,UNDEF)]
    # Independent relocation records by exact symbol index.
    rels=[('.rel.text',5,[(0,3,5),(4,3,6),(8,4,7),(12,5,literal_kind),(16,2,4)]),
          ('.rel.rodata',8,[(0,2,2),(4,6,2),(8,7,2),(12,10,2)]),
          ('.rel.mwcats',12,[(4,8,2)])]
    for name,target,rows in rels:
        sections.append(sec(name,REL,data=b''.join(words(place,(index<<8)|kind) for place,index,kind in rows),
            info=target,link=1,align=4,entsize=8))
    raw=serialize(b'\x7fELF\x01\x01\x01'+b'\0'*9,0x20924001,sections,symbols,1,2,3)
    placements=[Placement('first'+suffix,0x100000+offset,32),
                Placement('second'+suffix,0x100020+offset,16),
                Placement('helper',0x100060+offset,16)]
    data_bases={8:0x101000+offset,9:0x101100+offset,10:0x101200+offset,11:0x101300+offset}
    return raw,placements,data_bases


def projected_target(elf,sym,section_addresses,external):
    if sym.section == ABS:
        return sym.value
    if sym.section == UNDEF:
        return external[sym.name]
    return section_addresses[sym.section]+sym.value


class SplitTests(unittest.TestCase):
    def setUp(self):
        self.raw,self.placements,self.data_bases=fixture()
        self.elf=Elf32(self.raw)
        self.result=split_object(self.raw,self.placements,'src/fixture.c')

    def test_foreign_window_survives_between_two_contiguous_runs(self):
        self.assertEqual([f.label for f in self.result.fragments],['run000','run001','data'])
        runs=[f for f in self.result.fragments if f.placements]
        self.assertEqual([[p.address for p in f.placements] for f in runs],
                         [[0x100000,0x100020],[0x100060]])
        self.assertNotIn(0x100030,{p.address for f in runs for p in f.placements})

    def test_every_payload_occurs_once_and_mwcats_follows_its_function(self):
        seen=[]
        for part in self.result.fragments:
            out=Elf32(part.data)
            for old in part.original_sections:
                source=self.elf.sections[old]
                emitted=out.sections[part.section_map[old]]
                if source.type not in (REL,RELA):
                    self.assertEqual(emitted.data,source.data)
                    self.assertEqual(emitted.size,source.size)
                    self.assertEqual(emitted.type,source.type)
                    self.assertEqual(emitted.flags,source.flags)
                if source.type == MWCATS:
                    self.assertEqual(emitted.link,part.section_map[source.link])
                    self.assertIn(source.link,part.original_sections)
                seen.append(old)
        self.assertCountEqual(seen,[i for i in range(len(self.elf.sections)) if i not in (0,1,2,3)])
        self.assertEqual(len(seen),len(set(seen)))

    def test_original_local_names_stay_local_and_original_exports_are_exact(self):
        originals={s.name for s in self.elf.symbols if s.bind != LOCAL and s.section != UNDEF}
        exports=set()
        for f in self.result.fragments:
            e=Elf32(f.data)
            for s in e.symbols:
                if s.name in ('helper','secret','small','literal','private_bss'):
                    self.assertEqual(s.bind,LOCAL)
                if s.section != UNDEF and s.bind != LOCAL and not s.other & 3:
                    exports.add(s.name)
        self.assertEqual(exports,originals)
        for bridge in self.result.bridges:
            definitions=[s for f in self.result.fragments for s in Elf32(f.data).symbols
                         if s.name==bridge['name'] and s.section!=UNDEF]
            self.assertEqual(len(definitions),1)
            self.assertEqual(definitions[0].other & 3,2)
            self.assertEqual(definitions[0].size,0)

    def test_relocation_types_offsets_addends_and_actual_targets_are_preserved(self):
        bases=dict(self.data_bases)
        for p in self.placements:
            s=next(s for s in self.elf.symbols if s.name==p.name)
            bases[s.section]=p.address
        # Non-allocated metadata is never used as a relocation target here.
        addresses={}
        for f in self.result.fragments:
            out=Elf32(f.data)
            for s in out.symbols:
                if s.bind != LOCAL and s.section not in (UNDEF,ABS):
                    old=next(old for old,new in f.section_map.items() if new==s.section)
                    addresses[s.name]=bases[old]+s.value
        addresses['maybe']=0
        for f in self.result.fragments:
            out=Elf32(f.data)
            new_bases={f.section_map[i]:a for i,a in bases.items() if i in f.section_map}
            for old in f.original_sections:
                if self.elf.sections[old].type not in (REL,RELA):
                    continue
                before=self.elf.relocations(old)
                after=out.relocations(f.section_map[old])
                self.assertEqual(len(before),len(after))
                for a,b in zip(before,after):
                    self.assertEqual((a[0],a[2],a[3]),(b[0],b[2],b[3]))
                    old_target=projected_target(self.elf,self.elf.symbols[a[1]],bases,{'maybe':0})
                    new_target=projected_target(out,out.symbols[b[1]],new_bases,addresses)
                    self.assertEqual(old_target,new_target)

    def test_equal_local_names_in_another_owner_cannot_capture_bridges(self):
        raw,places,_=fixture('_foreign',0x2000)
        foreign=split_object(raw,places,'src/foreign.c')
        self.assertTrue(self.result.bridges)
        self.assertTrue(foreign.bridges)
        self.assertFalse({r['name'] for r in self.result.bridges} & {r['name'] for r in foreign.bridges})
        self.assertEqual(split_object(self.raw,self.placements,'src/fixture.c').fragments[0].data,
                         self.result.fragments[0].data)

    def test_missing_function_is_rejected_without_dropping_text(self):
        with self.assertRaisesRegex(SplitError,'Unowned emitted text'):
            split_object(self.raw,self.placements[:-1],'src/fixture.c')

    def test_cross_fragment_literal_relocation_is_rejected_before_linker(self):
        raw,places,_=fixture(literal_kind=8)
        with self.assertRaisesRegex(SplitError,'R_MIPS_LITERAL cannot cross fragment boundaries'):
            split_object(raw,places,'src/literal.c')

    def test_unsupported_got_relocation_is_rejected_without_changing_its_type(self):
        raw,places,_=fixture(literal_kind=9)
        with self.assertRaisesRegex(SplitError,'Unsupported native MIPS relocation 9'):
            split_object(raw,places,'src/got.c')

    def test_overlong_shared_and_overlapping_windows_are_rejected(self):
        for rows in ([(0x1000,4,8,1)],[(0x1000,8,8,1),(0x1008,8,8,1)],
                     [(0x1000,16,8,1),(0x1008,16,8,2)]):
            with self.subTest(rows=rows),self.assertRaises(SplitError):
                text_runs(rows)

    def test_empty_truncated_wrong_endian_and_executable_files_are_rejected(self):
        for raw in (b'',self.raw[:60],self.raw[:5]+b'\x02'+self.raw[6:],
                    self.raw[:16]+b'\x02\0'+self.raw[18:]):
            with self.subTest(size=len(raw)),self.assertRaises(SplitError):
                Elf32(raw)

    def test_mwccgap_null_section_offset_has_no_payload(self):
        raw=bytearray(self.raw)
        shoff=struct.unpack_from('<I',raw,32)[0]
        struct.pack_into('<I',raw,shoff+16,64)
        result=split_object(bytes(raw),self.placements,'src/fixture.c')
        self.assertEqual([Elf32(f.data).sections[0].size for f in result.fragments],[0,0,0])

    def test_symbol_table_keeps_undefined_weak_reference(self):
        out=Elf32(next(f.data for f in self.result.fragments if f.label=='data'))
        weak=next(s for s in out.symbols if s.name=='maybe')
        self.assertEqual((weak.bind,weak.section),(WEAK,UNDEF))

    def test_data_alignment_and_nobits_do_not_turn_into_padding_in_splitter(self):
        part=next(f for f in self.result.fragments if f.label=='data')
        out=Elf32(part.data)
        for old in self.data_bases:
            a,b=self.elf.sections[old],out.sections[part.section_map[old]]
            self.assertEqual((a.align,a.size,a.type,a.data),(b.align,b.size,b.type,b.data))


if __name__ == '__main__':
    unittest.main(verbosity=2)
