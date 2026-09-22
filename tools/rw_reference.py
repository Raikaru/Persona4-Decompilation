"""Read function symbols and bodies from a linked reference ELF."""
from __future__ import annotations

import struct
from pathlib import Path

import verify as V

def words(data: bytes) -> list[int]:
    """Decode complete little-endian instruction words from a function body."""
    return [word for (word,) in struct.iter_unpack("<I", data[:len(data) & ~3])]



class ReferenceElf:
    """A linked ELF with a symbol table, read for its FUNC symbols."""

    def __init__(self, path: Path):
        self.data = path.read_bytes()
        endian, sections = V.elf_sections(self.data)
        self.endian = endian
        self.sections = sections
        self.functions: list[tuple[str, int, bytes]] = []

        for section in sections:
            if section["type"] != 2:  # SHT_SYMTAB
                continue
            strings = sections[section["link"]]
            blob = self.data[strings["offset"]:strings["offset"] + strings["size"]]
            entsize = section["entsize"] or 16
            for index in range(section["size"] // entsize):
                offset = section["offset"] + index * entsize
                name, value, size, info, _other, shndx = struct.unpack_from(
                    endian + "IIIBBH", self.data, offset)
                if info & 0xF != 2 or not size or shndx in (0, 0xFFF1):
                    continue
                if shndx >= len(sections):
                    continue
                host = sections[shndx]
                start = host["offset"] + (value - host["addr"])
                if start < 0 or start + size > len(self.data):
                    continue
                symbol = V._cstr(blob, name) if name < len(blob) else ""
                if symbol:
                    body = self.data[start:start + size]
                    self.functions.append((symbol, value, body))
