"""Split a *compiled* MWCC ELF32 object into contiguous text runs plus data.

No instruction, data byte or relocation addend is changed. Section/symbol
indices and names are rebuilt. Original local names remain local; references
crossing a fragment boundary use a collision-checked, hidden alias for the
same definition. The consumer relocation still targets a linked definition,
never a retail-address substitute. This is a deliberately strict prototype.
"""
from __future__ import annotations

from dataclasses import dataclass, replace
import hashlib
import re
import struct
from typing import Mapping, Sequence

NULL, PROGBITS, SYMTAB, STRTAB, RELA, NOBITS, REL = 0, 1, 2, 3, 4, 8, 9
MWCATS = 0xCA2A82C2
ALLOC, EXEC = 2, 4
UNDEF, ABS, COMMON = 0, 0xFFF1, 0xFFF2
LOCAL, GLOBAL, WEAK = 0, 1, 2
NOTYPE, OBJECT, FUNC, SECTION, FILE = 0, 1, 2, 3, 4


class SplitError(ValueError):
    """The input cannot be split with the invariants implemented here."""


def require(condition: bool, message: str) -> None:
    if not condition:
        raise SplitError(message)


@dataclass(frozen=True)
class Section:
    name: str
    type: int
    flags: int = 0
    addr: int = 0
    data: bytes = b''
    size: int = 0
    link: int = 0
    info: int = 0
    align: int = 1
    entsize: int = 0


@dataclass(frozen=True)
class Symbol:
    name: str
    value: int
    size: int
    info: int
    other: int
    section: int

    @property
    def bind(self) -> int:
        return self.info >> 4

    @property
    def type(self) -> int:
        return self.info & 15


@dataclass(frozen=True)
class Placement:
    name: str
    address: int
    window: int


@dataclass
class Fragment:
    label: str
    data: bytes
    original_sections: list[int]
    section_map: dict[int, int]
    symbol_map: dict[int, int]
    placements: list[Placement]


@dataclass
class Split:
    fragments: list[Fragment]
    bridges: list[dict]
    owners: dict[int, str]
    source_sha256: str


class Elf32:
    def __init__(self, raw: bytes):
        require(len(raw) >= 52 and raw[:7] == b'\x7fELF\x01\x01\x01',
                'Expected ELF32 little-endian version 1')
        header = struct.unpack_from('<16sHHIIIIIHHHHHH', raw)
        require(header[1:4] == (1, 8, 1), 'Expected a MIPS relocatable object')
        # 16s, type, machine, version, entry, phoff, shoff, flags, ehsize,
        # phentsize, phnum, shentsize, shnum, shstrndx.
        self.ident, self.flags = header[0], header[7]
        shoff, shentsize, shnum, shstridx = header[6], header[11], header[12], header[13]
        require(header[8] == 52 and header[10] == 0, 'Program headers are not supported')
        require(shentsize == 40 and 0 < shnum < 0xFF00 and 0 < shstridx < shnum,
                'Invalid or extended section headers')
        require(shoff + shnum * 40 <= len(raw), 'Truncated section header table')
        headers = [struct.unpack_from('<10I', raw, shoff + i * 40) for i in range(shnum)]
        # mwccgap may leave the zero-length null section's file offset at 64.
        # No payload or index-extension fields are accepted in that section.
        require(headers[0][:4] + headers[0][5:] == (0,) * 9, 'Nonempty null section')
        for h in headers:
            require(h[1] == NOBITS or h[4] + h[5] <= len(raw), 'Truncated section data')
            require(h[8] == 0 or not h[8] & (h[8] - 1), 'Non-power-of-two section alignment')
        strings = headers[shstridx]
        require(strings[1] == STRTAB, 'Invalid section-name string table')
        names = raw[strings[4]:strings[4]+strings[5]]
        self.sections = [Section(self.cstring(names,h[0]), h[1], h[2], h[3],
            b'' if h[1] == NOBITS else raw[h[4]:h[4]+h[5]], h[5], h[6], h[7], h[8], h[9])
            for h in headers]
        tabs = [i for i,s in enumerate(self.sections) if s.type == SYMTAB]
        require(len(tabs) == 1, 'Exactly one symbol table is required')
        self.symtab = tabs[0]
        tab = self.sections[self.symtab]
        require(tab.entsize == 16 and tab.size % 16 == 0, 'Invalid ELF32 symbol table')
        require(0 < tab.link < shnum and self.sections[tab.link].type == STRTAB,
                'Invalid symbol-name string table')
        self.strtab, self.shstrtab = tab.link, shstridx
        names = self.sections[tab.link].data
        self.symbols = []
        for pos in range(0, tab.size, 16):
            name,value,size,info,other,section = struct.unpack_from('<IIIBBH', tab.data, pos)
            self.symbols.append(Symbol(self.cstring(names,name), value,size,info,other,section))
        require(bool(self.symbols) and self.symbols[0] == Symbol('',0,0,0,0,0), 'Invalid null symbol')
        require(tab.info <= len(self.symbols), 'Invalid local-symbol boundary')
        for i,s in enumerate(self.symbols):
            require(s.bind in (LOCAL,GLOBAL,WEAK), 'Unsupported symbol binding')
            require((i < tab.info) == (s.bind == LOCAL), 'Incorrect local/global symbol ordering')
            require(s.section < shnum or s.section in (ABS,COMMON), 'Invalid/extended symbol index')
        self.raw = raw

    @staticmethod
    def cstring(data: bytes, offset: int) -> str:
        require(0 <= offset < len(data), 'Invalid string offset')
        end = data.find(b'\0', offset)
        require(end >= 0, 'Unterminated ELF string')
        return data[offset:end].decode('utf-8', 'surrogateescape')

    def relocations(self, index: int) -> list[tuple[int,int,int,int | None]]:
        s = self.sections[index]
        require(s.type in (REL,RELA), 'Not a relocation section')
        stride = 8 if s.type == REL else 12
        require(s.link == self.symtab and s.entsize == stride and s.size % stride == 0,
                'Invalid relocation table')
        require(0 < s.info < len(self.sections), 'Invalid relocation target section')
        result=[]
        for off in range(0, s.size, stride):
            place,info = struct.unpack_from('<II',s.data,off)
            require(info >> 8 < len(self.symbols), 'Invalid relocation symbol')
            require(place < self.sections[s.info].size, 'Relocation outside target section')
            addend = struct.unpack_from('<i',s.data,off+8)[0] if stride == 12 else None
            result.append((place, info >> 8, info & 255, addend))
        return result


def serialize(ident: bytes, flags: int, sections: Sequence[Section], symbols: Sequence[Symbol],
              symtab: int, strtab: int, shstrtab: int) -> bytes:
    """Write fresh metadata around exact section payloads."""
    sections = list(sections)
    require(sections[0].type == NULL, 'Missing null section')
    require(symbols[0] == Symbol('',0,0,0,0,0), 'Missing null symbol')
    strings = bytearray(b'\0')
    def add(value: str) -> int:
        offset = len(strings)
        strings.extend(value.encode('utf-8','surrogateescape') + b'\0')
        return offset
    symdata = bytearray()
    for sym in symbols:
        symdata.extend(struct.pack('<IIIBBH', add(sym.name) if sym.name else 0,
            sym.value,sym.size,sym.info,sym.other,sym.section))
    first_global = next((i for i,s in enumerate(symbols) if s.bind != LOCAL),len(symbols))
    require(all(s.bind != LOCAL for s in symbols[first_global:]), 'Symbols are not local-first')
    sections[symtab] = replace(sections[symtab], data=bytes(symdata),size=len(symdata),
        link=strtab,info=first_global,entsize=16,align=4)
    sections[strtab] = replace(sections[strtab],data=bytes(strings),size=len(strings))
    strings = bytearray(b'\0')
    name_offsets=[add(s.name) if s.name else 0 for s in sections]
    sections[shstrtab] = replace(sections[shstrtab],data=bytes(strings),size=len(strings))
    raw = bytearray(52)
    headers=[]
    for i,s in enumerate(sections):
        if i == 0:
            headers.append((0,)*10)
            continue
        alignment=max(1,s.align)
        raw.extend(b'\0' * (-len(raw) % alignment))
        offset=len(raw)
        if s.type != NOBITS:
            require(len(s.data) == s.size, f'Section {s.name} size disagrees with payload')
            raw.extend(s.data)
        headers.append((name_offsets[i],s.type,s.flags,s.addr,offset,s.size,s.link,s.info,s.align,s.entsize))
    raw.extend(b'\0' * (-len(raw) % 4))
    shoff=len(raw)
    for h in headers:
        raw.extend(struct.pack('<10I',*h))
    struct.pack_into('<16sHHIIIIIHHHHHH',raw,0,ident,1,8,1,0,0,shoff,flags,
                     52,0,0,40,len(sections),shstrtab)
    return bytes(raw)


def text_runs(rows: Sequence[tuple[int,int,int,int]]) -> list[list[tuple[int,int,int,int]]]:
    """Reject overlaps/overruns/shared sections, preserving foreign windows as gaps."""
    rows=sorted(rows)
    require(bool(rows), 'No text placements')
    require(len({r[3] for r in rows}) == len(rows), 'Two placed functions share a section')
    runs=[]
    end=None
    for row in rows:
        address,window,size,section=row
        require(address >= 0 and window > 0 and 0 <= size <= window and section > 0,
                'Invalid or overlong function window')
        require(address + window <= 0x100000000, 'Function window wraps the address space')
        require(end is None or address >= end, 'Overlapping function windows')
        if address != end:
            runs.append([])
        runs[-1].append(row)
        end=address+window
    return runs


def _object_layout(raw: bytes, placements: Sequence[Placement]):
    """Validate native sections and ownership before choosing a linker layout."""
    elf=Elf32(raw)
    meta={0,elf.symtab,elf.strtab,elf.shstrtab}
    require(len(meta) == 4, 'Aliased ELF metadata tables')
    placed={}
    names=set()
    for p in placements:
        require(p.name not in names, 'Duplicate placed symbol')
        names.add(p.name)
        definitions=[s for s in elf.symbols if s.name == p.name and s.type == FUNC and 0 < s.section < len(elf.sections)]
        require(len(definitions) == 1, f'Expected one function definition for {p.name}')
        symbol=definitions[0]
        sec=elf.sections[symbol.section]
        require(sec.type == PROGBITS and sec.flags & EXEC and sec.flags & ALLOC,
                f'{p.name} is not allocated executable PROGBITS')
        require(sec.name == '.text' or sec.name == '.text.'+p.name, 'Unrecognized text section name')
        require(symbol.value == 0 and symbol.size > 0 and symbol.size <= sec.size,
                f'{p.name} does not start its entire section')
        require(symbol.section not in placed, 'Two placed functions share a section')
        placed[symbol.section]=p
    rows=[(p.address,p.window,elf.sections[i].size,i) for i,p in placed.items()]
    runs=text_runs(rows)
    groups={f'run{n:03d}':{r[3] for r in run} for n,run in enumerate(runs)}
    groups['data']=set()
    owner={i:name for name,items in groups.items() for i in items}
    for i,s in enumerate(elf.sections):
        if i in meta or s.type in (REL,RELA,MWCATS) or i in owner:
            continue
        require(s.type in (PROGBITS,NOBITS),f'Unsupported section type {s.type:#x}: {s.name}')
        require(not s.flags & ~(ALLOC|EXEC|1|0x10000000),f'Unsupported section flags: {s.name}')
        require(s.link == 0 and s.info == 0,f'Unknown section-index metadata: {s.name}')
        require(not (s.flags & EXEC) or s.size == 0,f'Unowned emitted text: {s.name}')
        groups['data'].add(i)
        owner[i]='data'
    # MWCC function metadata follows its linked text section. It is not discarded.
    for i,s in enumerate(elf.sections):
        if s.type == MWCATS:
            require(s.link in placed and s.info == 0 and not s.flags,
                    'Unsupported MWCC association section')
            owner[i]=owner[s.link]
            groups[owner[i]].add(i)
    for i,s in enumerate(elf.sections):
        if s.type in (REL,RELA):
            require(s.info in owner,'Relocations target non-content metadata')
            elf.relocations(i)
            owner[i]=owner[s.info]
            groups[owner[i]].add(i)
    require(set(owner) | meta == set(range(len(elf.sections))), 'An input section is unassigned')
    for sym in elf.symbols[1:]:
        require(sym.section in (UNDEF,ABS,COMMON) or sym.section in owner,
                'Symbol defines non-content metadata')
        if sym.section in owner:
            sec=elf.sections[sym.section]
            require(sym.value <= sec.size and sym.value + sym.size <= sec.size,
                    f'Symbol outside section: {sym.name}')
        require(sym.type != SECTION or sym.bind == LOCAL,'Non-local section symbol')
        require(sym.section != UNDEF or sym.bind != LOCAL,'Undefined local symbol')
    return elf,meta,placed,groups,owner


def validate_whole_object(raw: bytes, placements: Sequence[Placement]) -> None:
    """Validate direct section placement without changing native local targets.

    GNU ld can revisit one object's sections. R_MIPS_LITERAL therefore stays
    local to its original pool even when foreign functions separate text runs.
    All other section, ownership and native-relocation restrictions are shared
    with the MWLD splitter.
    """
    elf,_meta,_placed,_groups,owner=_object_layout(raw,placements)
    for index,section in enumerate(elf.sections):
        if section.type not in (REL,RELA):
            continue
        require(section.type == REL, 'Only native MIPS REL relocations are supported')
        for _offset,symbol_index,kind,_addend in elf.relocations(index):
            require(kind in (0,2,4,5,6,7,8), f'Unsupported native MIPS relocation {kind}')
            if kind == 8:
                symbol=elf.symbols[symbol_index]
                require(symbol.bind == LOCAL and symbol.section in owner and
                        elf.sections[symbol.section].flags & ALLOC,
                        'R_MIPS_LITERAL requires its original local allocated target')


def split_object(raw: bytes, placements: Sequence[Placement], identity: str) -> Split:
    require(bool(identity), 'Owner identity is required for private symbol names')
    elf,meta,placed,groups,owner=_object_layout(raw,placements)
    # Determine cross-fragment local references by original symbol INDEX.
    bridges={}
    nonce=hashlib.sha256(identity.encode()+b'\0'+raw).hexdigest()[:24]
    existing_names={s.name for s in elf.symbols if s.name}
    for name,items in groups.items():
        for i in items:
            if elf.sections[i].type not in (REL,RELA):
                continue
            require(elf.sections[i].type == REL, 'Only native MIPS REL relocations are supported')
            for _offset,index,kind,_addend in elf.relocations(i):
                sym=elf.symbols[index]
                require(kind in (0,2,4,5,6,7,8), f'Unsupported native MIPS relocation {kind}')
                if kind == 8:
                    # Measured MWLD access violation when a literal-pool
                    # reference is made external, even with a hidden alias and
                    # the original pool's GP flags. Do not turn this into GPREL
                    # or duplicate the pool: those would alter the input contract.
                    require(sym.section in owner and owner[sym.section] == name,
                            'R_MIPS_LITERAL cannot cross fragment boundaries')
                if sym.bind == LOCAL and sym.section in owner and owner[sym.section] != name:
                    alias=f'__p4run_{nonce}_{index:x}'
                    require(alias not in existing_names,'Private bridge collides with an original name')
                    bridges[index]=alias
    fragments=[]
    for label,items in groups.items():
        # Original section order keeps concatenated data groups and metadata stable.
        keep=sorted(items | meta)
        section_map={old:new for new,old in enumerate(keep)}
        referenced={index for i in items if elf.sections[i].type in (REL,RELA)
                    for _offset,index,_kind,_addend in elf.relocations(i)}
        entries=[(('original',0),elf.symbols[0])]
        for i,sym in enumerate(elf.symbols[1:],1):
            if sym.section in items:
                entries.append((('original',i),replace(sym,section=section_map[sym.section])))
            elif sym.section in (ABS,COMMON) and (label == 'data' or (sym.bind == LOCAL and i in referenced)):
                entries.append((('original',i),sym))
            elif i in referenced:
                if sym.bind == LOCAL:
                    require(i in bridges,'Missing cross-fragment local bridge')
                    entries.append((('original',i),Symbol(bridges[i],0,0,
                        (GLOBAL<<4)|NOTYPE,2,UNDEF)))
                else:
                    entries.append((('original',i),replace(sym,value=0,size=0,section=UNDEF)))
        for i,alias in bridges.items():
            sym=elf.symbols[i]
            if sym.section in items:
                # A bridge is an address alias, not another allocation. MWLD
                # sums defined symbol sizes when validating an input section.
                entries.append((('bridge',i),Symbol(alias,sym.value,0,
                    (GLOBAL<<4)|NOTYPE,2,section_map[sym.section])))
        entries.sort(key=lambda item: item[1].bind != LOCAL)
        symbol_map={i:new for new,((kind,i),sym) in enumerate(entries) if kind == 'original'}
        sections=[]
        for i in keep:
            s=elf.sections[i]
            if i in meta:
                sections.append(s)
                continue
            if s.type in (REL,RELA):
                data=bytearray(s.data)
                stride=8 if s.type == REL else 12
                for n,(_offset,index,kind,_addend) in enumerate(elf.relocations(i)):
                    struct.pack_into('<I',data,n*stride+4,(symbol_map[index]<<8)|kind)
                s=replace(s,data=bytes(data),link=section_map[s.link],info=section_map[s.info])
            elif s.type == MWCATS:
                s=replace(s,link=section_map[s.link])
            if i in placed:
                s=replace(s,name='.text.'+placed[i].name,align=1)
            sections.append(s)
        encoded=serialize(elf.ident,elf.flags,sections,[s for _,s in entries],
            section_map[elf.symtab],section_map[elf.strtab],section_map[elf.shstrtab])
        fragments.append(Fragment(label,encoded,sorted(items),section_map,symbol_map,
            sorted((p for i,p in placed.items() if i in items),key=lambda p:p.address)))
    bridge_rows=[dict(original_symbol=i,name=alias,original_name=elf.symbols[i].name,
        section=elf.symbols[i].section,value=elf.symbols[i].value,
        defining_fragment=owner[elf.symbols[i].section]) for i,alias in sorted(bridges.items())]
    return Split(fragments,bridge_rows,owner,hashlib.sha256(raw).hexdigest())


def localize_private_bridges(raw: bytes, names: Sequence[str]) -> bytes:
    """Restore private bridge scope after MWLD drops STV_HIDDEN.

    Only non-loadable symbol/relocation metadata changes. Original names,
    addresses, bindings and public definitions are preserved. Generated bridge
    aliases become local symbols, with local-first ordering and every surviving
    relocation index remapped. Refuse layouts whose metadata overlaps PT_LOAD.
    """
    if not names:
        return raw
    wanted=set(names)
    require(len(wanted)==len(names),'Duplicate private bridge name')
    require(all(re.fullmatch(r'__p4run_[0-9a-f]{24}_[0-9a-f]+',name) for name in names),
            'Only generated bridge names may be localized')
    require(len(raw)>=52 and raw[:7]==b'\x7fELF\x01\x01\x01','Expected ELF32 little-endian output')
    h=struct.unpack_from('<16sHHIIIIIHHHHHH',raw)
    require(h[1:4]==(2,8,1) and h[8]==52,'Expected a MIPS executable')
    phoff,shoff,phentsize,phnum,shentsize,shnum=h[5],h[6],h[9],h[10],h[11],h[12]
    require(shentsize==40 and 0<shnum<0xff00 and shoff+shnum*40<=len(raw),'Invalid output sections')
    require(not phnum or (phentsize>=32 and phoff+phnum*phentsize<=len(raw)),'Invalid program headers')
    sections=[struct.unpack_from('<10I',raw,shoff+i*40) for i in range(shnum)]
    tables=[i for i,s in enumerate(sections) if s[1]==SYMTAB]
    require(len(tables)==1,'Exactly one output symbol table is required')
    require(not any(s[1] in (6,11) for s in sections),'Dynamic symbol metadata is unsupported')
    table=tables[0]
    symtab=sections[table]
    require(not symtab[2]&ALLOC and symtab[9]==16 and symtab[5]%16==0,
            'Invalid or allocated output symbol table')
    require(symtab[4]+symtab[5]<=len(raw) and 0<symtab[6]<shnum,'Truncated output symbols')
    strings=sections[symtab[6]]
    require(strings[1]==STRTAB and strings[4]+strings[5]<=len(raw),'Invalid output symbol strings')
    blob=raw[strings[4]:strings[4]+strings[5]]
    symbols=[struct.unpack_from('<IIIBBH',raw,off)
             for off in range(symtab[4],symtab[4]+symtab[5],16)]
    require(bool(symbols) and symbols[0]==(0,0,0,0,0,0),'Invalid output null symbol')
    require(symtab[7]<=len(symbols),'Invalid output local-symbol boundary')
    for i,sym in enumerate(symbols):
        require((i<symtab[7])==(sym[3]>>4==LOCAL),'Output symbols are not local-first')
    found={}
    for index,sym in enumerate(symbols):
        name=Elf32.cstring(blob,sym[0])
        if name in wanted:
            require(name not in found,'Multiple output bridge definitions')
            require(sym[3]>>4==GLOBAL and sym[3]&15==NOTYPE and sym[2]==0,
                    'Unexpected output bridge binding/type/size')
            require(0<sym[5]<shnum,'Undefined or absolute output bridge')
            found[name]=index
    require(set(found)==wanted,'Missing output bridge definition')
    updated=list(symbols)
    for index in found.values():
        name,value,size,info,other,section=updated[index]
        updated[index]=(name,value,size,info&15,(other&~3)|2,section)
    order=sorted(range(len(updated)),key=lambda index:updated[index][3]>>4!=LOCAL)
    mapping={old:new for new,old in enumerate(order)}
    data=bytearray(raw)
    for index,old in enumerate(order):
        struct.pack_into('<IIIBBH',data,symtab[4]+index*16,*updated[old])
    struct.pack_into('<I',data,shoff+table*40+28,sum(s[3]>>4==LOCAL for s in updated))
    for section in sections:
        if section[6]!=table:
            continue
        require(section[1] in (REL,RELA),'Unsupported metadata linked to output symbols')
        stride=8 if section[1]==REL else 12
        require(not section[2]&ALLOC and section[9]==stride and section[5]%stride==0,
                'Invalid output relocation table')
        require(section[4]+section[5]<=len(raw),'Truncated output relocations')
        for offset in range(section[4],section[4]+section[5],stride):
            info=struct.unpack_from('<I',raw,offset+4)[0]
            require(info>>8<len(symbols),'Invalid output relocation symbol')
            struct.pack_into('<I',data,offset+4,(mapping[info>>8]<<8)|(info&255))
    # This applies to every load, even non-executable data loads. It also
    # protects a section-header table if an unusual ELF maps that into memory.
    for index in range(phnum):
        p=struct.unpack_from('<8I',raw,phoff+index*phentsize)
        require(p[1]+p[4]<=len(raw),'Truncated program segment')
        if p[0]==1:
            require(raw[p[1]:p[1]+p[4]]==data[p[1]:p[1]+p[4]],
                    'Symbol metadata overlaps loadable program bytes')
    require(len(data)==len(raw),'Metadata localization changed ELF size')
    return bytes(data)
