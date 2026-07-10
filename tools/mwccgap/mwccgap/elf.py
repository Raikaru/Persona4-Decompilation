import struct
from typing import Optional

SECTION_HEADER_SIZE = 0x28

SHT_SYMTAB = 2
SHT_STRTAB = 3
SHT_RELA = 4
SHT_NOBITS = 8
SHT_REL = 9

FUNCTION_ST_INFOS = (
    0x12,  # global functions
    0x02,  # local functions
    0xD2,  # MWCC C++ virtual destructors
)


class Elf:
    e_ident: int
    e_type: int
    e_machine: int
    e_version: int
    e_entry: int
    e_phoff: int
    e_shoff: int
    e_flags: int
    e_ehsize: int
    e_phentsize: int
    e_phnum: int
    e_shentsize: int
    e_shnum: int
    e_shstrndx: int

    sections: list["Section"]

    symtab: "Symtab"
    shstrtab: "Strtab"
    strtab: "Strtab"

    fmt = "<16sHHIIIIIHHHHHH"

    def __init__(
        self,
        data: bytes,
    ):
        (
            self.e_ident,
            self.e_type,
            self.e_machine,
            self.e_version,
            self.e_entry,
            self.e_phoff,
            self.e_shoff,
            self.e_flags,
            self.e_ehsize,
            self.e_phentsize,
            self.e_phnum,
            self.e_shentsize,
            self.e_shnum,
            self.e_shstrndx,
        ) = Elf.unpack(data)

        self.sections: list[Section] = []
        self.relocations: list[RelocationRecord] = []
        self.functions: list[TextSection] = []

        self.rodata_sections: list[Section] = []

        self.symtab = None  # type: ignore
        self.shstrtab = None  # type: ignore
        self.strtab = None  # type: ignore

        e_shoff = self.e_shoff
        e_shnum = self.e_shnum

        ptr = e_shoff
        while ptr < e_shoff + e_shnum * SECTION_HEADER_SIZE:
            (
                sh_name,
                sh_type,
                sh_flags,
                sh_addr,
                sh_offset,
                sh_size,
                sh_link,
                sh_info,
                sh_addralign,
                sh_entsize,
            ) = Section.unpack_header(data[ptr : ptr + SECTION_HEADER_SIZE])

            section_data = data[sh_offset : sh_offset + sh_size]

            if sh_type == SHT_SYMTAB:
                self.symtab_index = (ptr - e_shoff) // SECTION_HEADER_SIZE

                symtab = Symtab(
                    sh_name,
                    sh_type,
                    sh_flags,
                    sh_addr,
                    sh_offset,
                    sh_size,
                    sh_link,
                    sh_info,
                    sh_addralign,
                    sh_entsize,
                    section_data,
                )
                assert self.symtab is None, "Only 1 symtab is currently supported"
                self.symtab = symtab
                self.sections.append(symtab)

            elif sh_type == SHT_STRTAB:
                strtab = Strtab(
                    sh_name,
                    sh_type,
                    sh_flags,
                    sh_addr,
                    sh_offset,
                    sh_size,
                    sh_link,
                    sh_info,
                    sh_addralign,
                    sh_entsize,
                    section_data,
                )
                if len(self.sections) == self.e_shstrndx:
                    assert self.shstrtab is None, "Only 1 strtab is currently supported"
                    self.shstrtab = strtab
                else:
                    assert self.strtab is None, "Only 1 strtab is currently supported"
                    self.strtab = strtab
                self.sections.append(strtab)

            elif sh_type == SHT_REL:
                relocation_record = RelocationRecord(
                    sh_name,
                    sh_type,
                    sh_flags,
                    sh_addr,
                    sh_offset,
                    sh_size,
                    sh_link,
                    sh_info,
                    sh_addralign,
                    sh_entsize,
                    section_data,
                )
                self.sections.append(relocation_record)

            elif sh_type == SHT_RELA:
                raise Exception("FIXME: No support for RELA sections")

            elif sh_type == SHT_NOBITS:
                bss_section = BssSection(
                    sh_name,
                    sh_type,
                    sh_flags,
                    sh_addr,
                    sh_offset,
                    sh_size,
                    sh_link,
                    sh_info,
                    sh_addralign,
                    sh_entsize,
                    section_data,
                )
                self.sections.append(bss_section)

            else:
                section = Section(
                    sh_name,
                    sh_type,
                    sh_flags,
                    sh_addr,
                    sh_offset,
                    sh_size,
                    sh_link,
                    sh_info,
                    sh_addralign,
                    sh_entsize,
                    section_data,
                )
                self.sections.append(section)

            ptr += SECTION_HEADER_SIZE

        assert self.shstrtab is not None, "no shstrtab!"
        assert self.strtab is not None, "no strtab!"
        assert self.symtab is not None, "no symtab!"

        for section in self.sections:
            section.name = self.shstrtab.get_symbol_by_index(section.sh_name)

        for symbol in self.symtab.symbols:
            symbol.name = self.strtab.get_symbol_by_index(symbol.st_name)

        # To be refined
        function_names = [
            s.name
            for s in sorted(
                filter(lambda x: x.st_info in FUNCTION_ST_INFOS, self.symtab.symbols),
                key=lambda x: x.st_shndx,
            )
        ]

        for i, section in enumerate(self.sections):
            if isinstance(section, RelocationRecord):
                for reloc in section.relocations:
                    reloc.symbol = self.symtab.symbols[reloc.symbol_index].name
                self.relocations.append(section)
            else:
                if section.name == ".text":
                    text_section = TextSection.from_section(section)
                    self.sections[i] = text_section
                    if len(function_names) == 0:
                        # FIXME: without globl label, ASM has no functions
                        pass
                    else:
                        function_name = function_names[len(self.functions)]
                        text_section.function_name = function_name
                    self.functions.append(text_section)
                elif section.name == ".rodata":
                    self.rodata_sections.append(section)

    def add_sh_symbol(self, symbol_name: str):
        return self.shstrtab.add_symbol(symbol_name)

    def add_symbol(self, symbol: "Symbol", force=False) -> int:
        index, _ = self.symtab.get_symbol_by_name(symbol.name)
        if index is None or force:
            if symbol.name != "":
                symbol.st_name = self.strtab.add_symbol(symbol.name)
            index = self.symtab.add_symbol(symbol)

        return index

    def add_section(self, section) -> int:
        self.sections.append(section)
        self.e_shnum += 1  # not strictly necessary

        if isinstance(section, RelocationRecord):
            self.relocations.append(section)

        return len(self.sections) - 1

    def get_relocations(self) -> list["RelocationRecord"]:
        return self.relocations

    def get_functions(self) -> list["TextSection"]:
        return self.functions

    @staticmethod
    def unpack(data):
        return struct.unpack(Elf.fmt, data[:0x34])

    def pack(self):
        elf_header_size = 0x40

        sh_offset = elf_header_size  # 0x34 + 0xC alignment

        section_headers = bytes()
        section_data = bytes()
        for section in self.sections:
            section.sh_offset = sh_offset
            header, data = section.pack()

            section_headers += header
            section_data += data

            sh_offset += len(data)

            alignment = section.sh_addralign
            if alignment:
                if sh_offset % alignment:
                    bytes_needed = alignment - (sh_offset % alignment)
                    section_data += bytes(bytes_needed)
                    sh_offset += bytes_needed

        if sh_offset % 4:
            bytes_needed = 4 - (sh_offset % 4)
            section_data += bytes(bytes_needed)
            sh_offset += bytes_needed

        elf_header = struct.pack(
            Elf.fmt,
            *[
                self.e_ident,
                self.e_type,
                self.e_machine,
                self.e_version,
                self.e_entry,
                self.e_phoff,
                len(section_data) + elf_header_size,  # self.e_shoff,
                self.e_flags,
                self.e_ehsize,
                self.e_phentsize,
                self.e_phnum,
                self.e_shentsize,
                len(self.sections),  # self.e_shnum,
                self.e_shstrndx,
            ],
        )

        elf_header += bytes(0xC)  # pad to 0x40

        return elf_header + section_data + section_headers


class Symbol:
    st_name: int
    st_info: int
    st_other: int
    st_shndx: int
    st_value: int
    st_size: int

    name: str

    fmt = "<IIIBBH"

    def __init__(
        self,
        st_name,
        st_value,
        st_size,
        st_info,
        st_other,
        st_shndx,
    ):
        self.st_name = st_name
        self.st_value = st_value
        self.st_size = st_size
        self.st_info = st_info
        self.st_other = st_other
        self.st_shndx = st_shndx

        self.bind = st_info >> 4
        self.type = st_info & 0xF

        self.name = ""

    def __str__(self):
        if self.name:
            res = self.name
        else:
            res = "NO_NAME"
        return f"{res} st_name: 0x{self.st_name:X}, st_info: 0x{self.st_info:X}, st_other: 0x{self.st_other:X}, st_shndx: 0x{self.st_shndx:X}, st_value: 0x{self.st_value:X}, st_size: 0x{self.st_size:X}"

    @staticmethod
    def from_data(data):
        args = Symbol.unpack(data)
        return Symbol(*args)

    @staticmethod
    def unpack(data):
        return struct.unpack(Symbol.fmt, data)

    def pack(self):
        return struct.pack(
            Symbol.fmt,
            *[
                self.st_name,
                self.st_value,
                self.st_size,
                (self.bind << 4) | self.type,
                self.st_other,
                self.st_shndx,
            ],
        )


class Section:
    sh_name: int
    sh_type: int
    sh_flags: int
    sh_addr: int
    sh_offset: int
    sh_size: int
    sh_link: int
    sh_info: int
    sh_addralign: int
    sh_entsize: int

    name: Optional[str]

    fmt = "<IIIIIIIIII"

    def __init__(
        self,
        sh_name,
        sh_type,
        sh_flags,
        sh_addr,
        sh_offset,
        sh_size,
        sh_link,
        sh_info,
        sh_addralign,
        sh_entsize,
        data,
    ):
        self.sh_name = sh_name
        self.sh_type = sh_type
        self.sh_flags = sh_flags
        self.sh_addr = sh_addr
        self.sh_offset = sh_offset
        self.sh_size = sh_size
        self.sh_link = sh_link
        self.sh_info = sh_info
        self.sh_addralign = sh_addralign
        self.sh_entsize = sh_entsize

        self.data = self._handle_data(data)

        self.name = ""

    def __str__(self):
        return f"sh_name: 0x{self.sh_name:X} sh_type: 0x{self.sh_type:X} sh_flags: 0x{self.sh_flags:X} sh_addr: 0x{self.sh_addr:X} sh_offset: 0x{self.sh_offset:X} sh_size: 0x{self.sh_size:X} sh_link: 0x{self.sh_link:X} sh_info: 0x{self.sh_info:X} sh_addralign: 0x{self.sh_addralign:X} sh_entsize: 0x{self.sh_entsize:X}"

    def _handle_data(self, data: bytes) -> bytes:
        return data

    @staticmethod
    def unpack_header(data):
        return struct.unpack(Section.fmt, data[0:SECTION_HEADER_SIZE])

    def pack_header(self) -> bytes:
        return struct.pack(
            Section.fmt,
            *[
                self.sh_name,
                self.sh_type,
                self.sh_flags,
                self.sh_addr,
                self.sh_offset,
                len(self.data),  # self.sh_size,  # raw size, no padding
                self.sh_link,
                self.sh_info,
                self.sh_addralign,
                self.sh_entsize,
            ],
        )

    def pack_data(self) -> bytes:
        return self.data

    def pack(self) -> tuple[bytes, bytes]:
        data = self.pack_data()
        header = self.pack_header()
        return (header, data)


class TextSection(Section):
    function_name: str = ""

    @staticmethod
    def from_section(section) -> "TextSection":
        return TextSection(
            section.sh_name,
            section.sh_type,
            section.sh_flags,
            section.sh_addr,
            section.sh_offset,
            section.sh_size,
            section.sh_link,
            section.sh_info,
            section.sh_addralign,
            section.sh_entsize,
            section.data,
        )


class BssSection(Section):
    def pack_header(self) -> bytes:
        return struct.pack(
            Section.fmt,
            *[
                self.sh_name,
                self.sh_type,
                self.sh_flags,
                self.sh_addr,
                self.sh_offset,
                self.sh_size,
                self.sh_link,
                self.sh_info,
                self.sh_addralign,
                self.sh_entsize,
            ],
        )

    def pack_data(self) -> bytes:
        return b""


class Symtab(Section):
    symbols: list[Symbol]

    def _handle_data(self, data: bytes) -> bytes:
        self.symbols = []
        ptr = 0
        while ptr < len(data):
            self.symbols.append(Symbol.from_data(data[ptr : ptr + 0x10]))
            ptr += 0x10
        return data

    def get_symbol_by_name(self, name) -> tuple[Optional[int], Optional[Symbol]]:
        for i, symbol in enumerate(self.symbols):
            if symbol.name == name:
                return (i, symbol)
        return (None, None)

    def add_symbol(self, symbol: Symbol) -> int:
        # sh_info is the index of the first non-local symbol.
        if symbol.bind == 0:  # STB_LOCAL
            # insert local symbol before sh_info
            index = self.sh_info
            self.symbols.insert(index, symbol)
            self.sh_info += 1
            return index

        # assume global?
        index = len(self.symbols)
        self.symbols.append(symbol)
        return index

    def pack_data(self) -> bytes:
        self.data = b"".join(s.pack() for s in self.symbols)
        return self.data


class Strtab(Section):
    symbols: list[str]

    def _handle_data(self, data: bytes) -> bytes:
        self.symbols = []

        ptr = start = 0
        while ptr < len(data):
            if data[ptr] == 0:
                self.symbols.append(data[start:ptr].decode("utf"))
                start = ptr + 1
            ptr += 1

        return data

    def pack_data(self) -> bytes:
        self.data = bytes()
        for symbol in self.symbols:
            # print(f"Packing symbol: {symbol}")
            self.data += symbol.encode("utf") + b"\x00"
        return self.data

    def get_symbol_by_index(self, index) -> str:
        ptr = index
        while ptr < len(self.data):
            if self.data[ptr] == 0:
                return self.data[index:ptr].decode("utf")
            ptr += 1
        raise Exception(f"Symbol not found at index: {index}")

    def add_symbol(self, symbol_name: str) -> int:
        encoded_name = symbol_name.encode("utf8") + b"\x00"
        idx = self.data.find(encoded_name)
        if idx != -1:
            return idx

        idx = len(self.data)
        self.data = self.data + encoded_name
        self.symbols.append(symbol_name)
        return idx


class Relocation:
    symbol: Optional[Symbol]

    def __init__(self, r_offset, r_info):
        self.r_offset = r_offset
        self.r_info = r_info

        self.reloc_type = r_info & 0xFF
        self.symbol_index = r_info >> 0x8

        self.symbol = None

    def __str__(self) -> str:
        return f"r_offset: 0x{self.r_offset:X}, r_info: 0x{self.r_info:X}, reloc_type: 0x{self.reloc_type:X}, symbol_index: 0x{self.symbol_index:X}"

    def pack(self) -> bytes:
        return struct.pack(
            "<II",
            *[
                self.r_offset,
                (self.symbol_index << 0x8) + self.reloc_type,
            ],
        )


class RelocationRecord(Section):
    def _handle_data(self, data: bytes) -> bytes:
        self.relocations = [
            Relocation(offset, info)
            for (offset, info) in struct.iter_unpack("<II", data)
        ]
        return data

    def pack_data(self) -> bytes:
        # print(f"Packing {len(self.relocations)} relocation(s)")
        self.data = b"".join(r.pack() for r in self.relocations)
        return self.data
