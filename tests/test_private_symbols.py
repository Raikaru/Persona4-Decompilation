"""Private scope restoration on linked ELF metadata, including live relocations."""
from __future__ import annotations
from pathlib import Path
import struct
import sys
import unittest

sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'tools'))

from elf_text_runs import (ALLOC, EXEC, NOTYPE, PROGBITS, REL, STRTAB, SYMTAB,
    Section, Symbol, SplitError, serialize, localize_private_bridges)

NAME='__p4run_0123456789abcdef01234567_3'


def fixture():
    names=[Symbol('',0,0,0,0,0),Symbol('private',4,4,1,0,5),
           Symbol('public',0x100000,8,0x12,0,4),Symbol(NAME,0x101004,0,0x10,0,5)]
    sections=[Section('',0,align=0),Section('.symtab',SYMTAB,link=2,align=4,entsize=16),
        Section('.strtab',STRTAB),Section('.shstrtab',STRTAB),
        Section('.text',PROGBITS,ALLOC|EXEC,data=b'ABCDEFGH',size=8,align=4),
        Section('.data',PROGBITS,ALLOC|1,data=b'12345678',size=8,align=4),
        Section('.rel.data',REL,data=struct.pack('<II',0,(3<<8)|2),size=8,link=1,info=5,align=4,entsize=8)]
    raw=bytearray(serialize(b'\x7fELF\x01\x01\x01'+b'\0'*9,0x20924001,sections,names,1,2,3))
    shoff=struct.unpack_from('<I',raw,32)[0]
    first=struct.unpack_from('<10I',raw,shoff+4*40)
    last=struct.unpack_from('<10I',raw,shoff+5*40)
    phoff=len(raw)
    raw.extend(struct.pack('<8I',1,first[4],0x100000,0x100000,last[4]+last[5]-first[4],16,7,4))
    struct.pack_into('<H',raw,16,2)
    struct.pack_into('<I',raw,28,phoff)
    struct.pack_into('<HH',raw,42,32,1)
    return bytes(raw)


def inspect(raw):
    shoff=struct.unpack_from('<I',raw,32)[0]
    sections=[struct.unpack_from('<10I',raw,shoff+i*40) for i in range(7)]
    table,strings=sections[1],sections[2]
    symbols=[]
    blob=raw[strings[4]:strings[4]+strings[5]]
    for off in range(table[4],table[4]+table[5],16):
        fields=struct.unpack_from('<IIIBBH',raw,off)
        name=blob[fields[0]:blob.index(0,fields[0])].decode()
        symbols.append((name,*fields[1:]))
    rel=struct.unpack_from('<II',raw,sections[6][4])
    return symbols,table,rel


class PrivateScopeTests(unittest.TestCase):
    def test_original_scope_payload_and_relocation_target_are_preserved(self):
        raw=fixture()
        fixed=localize_private_bridges(raw,[NAME])
        before,oldtable,oldrel=inspect(raw)
        after,newtable,newrel=inspect(fixed)
        self.assertEqual(len(raw),len(fixed))
        original={s[0]:s for s in before if s[0]!=NAME}
        self.assertEqual(original,{s[0]:s for s in after if s[0]!=NAME})
        bridge=next(s for s in after if s[0]==NAME)
        self.assertEqual(bridge[3]>>4,0)
        self.assertEqual(bridge[4]&3,2)
        self.assertEqual(newtable[7],oldtable[7]+1)
        self.assertEqual(before[oldrel[1]>>8][0],after[newrel[1]>>8][0])
        self.assertEqual(oldrel[0],newrel[0])
        self.assertEqual(oldrel[1]&255,newrel[1]&255)
        phoff=struct.unpack_from('<I',raw,28)[0]
        p=struct.unpack_from('<8I',raw,phoff)
        self.assertEqual(raw[p[1]:p[1]+p[4]],fixed[p[1]:p[1]+p[4]])

    def test_missing_or_nonprivate_names_are_rejected(self):
        for names in (['public'],[NAME,NAME],['__p4run_ffffffffffffffffffffffff_3']):
            with self.subTest(names=names),self.assertRaises(SplitError):
                localize_private_bridges(fixture(),names)

    def test_localization_refuses_mapped_metadata(self):
        raw=bytearray(fixture())
        phoff=struct.unpack_from('<I',raw,28)[0]
        struct.pack_into('<I',raw,phoff+4,0)
        struct.pack_into('<I',raw,phoff+16,len(raw))
        with self.assertRaisesRegex(SplitError,'overlaps loadable'):
            localize_private_bridges(bytes(raw),[NAME])

    def test_nonzero_sized_alias_is_not_a_private_bridge(self):
        raw=bytearray(fixture())
        _symbols,table,_rel=inspect(raw)
        struct.pack_into('<I',raw,table[4]+3*16+8,8)
        with self.assertRaisesRegex(SplitError,'binding/type/size'):
            localize_private_bridges(bytes(raw),[NAME])

    def test_no_bridges_is_a_byte_identical_noop(self):
        raw=fixture()
        self.assertEqual(localize_private_bridges(raw,[]),raw)


if __name__=='__main__':
    unittest.main(verbosity=2)
