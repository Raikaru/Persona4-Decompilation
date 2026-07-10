#!/usr/bin/env python3
"""Validate a Persona 4 USA ISO and extract the decompilation target.

Only the root-directory SYSTEM.CNF and SLUS_217.82 files are read. The tool uses
Python's standard library, validates the Redump-confirmed disc hash, validates
the ELF structure and hashes, and writes only gitignored local inputs.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import re
import struct
import sys
from pathlib import Path

SECTOR_SIZE = 2048
REPO = Path(__file__).resolve().parents[1]
TARGET_CONFIG = REPO / "config" / "target.json"


class SetupError(RuntimeError):
    pass


def parse_int(value: int | str) -> int:
    return value if isinstance(value, int) else int(value, 0)


def sha1_bytes(data: bytes) -> str:
    return hashlib.sha1(data).hexdigest()


def sha1_file(path: Path) -> str:
    digest = hashlib.sha1()
    with path.open("rb") as stream:
        for chunk in iter(lambda: stream.read(4 * 1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def require_equal(label: str, actual: object, expected: object) -> None:
    if actual != expected:
        raise SetupError(f"{label}: expected {expected!r}, got {actual!r}")


def read_iso_root_file(iso_path: Path, requested_name: str) -> bytes:
    """Read one regular file from an ISO9660 root directory."""
    with iso_path.open("rb") as iso:
        iso.seek(16 * SECTOR_SIZE)
        pvd = iso.read(SECTOR_SIZE)
        if len(pvd) != SECTOR_SIZE or pvd[0] != 1 or pvd[1:6] != b"CD001":
            raise SetupError("disc does not contain a valid ISO9660 primary volume descriptor")

        root_length = pvd[156]
        if root_length < 34:
            raise SetupError("ISO9660 root directory record is malformed")
        root = pvd[156 : 156 + root_length]
        root_lba = int.from_bytes(root[2:6], "little")
        root_size = int.from_bytes(root[10:14], "little")

        iso.seek(root_lba * SECTOR_SIZE)
        directory = iso.read(root_size)
        if len(directory) != root_size:
            raise SetupError("ISO9660 root directory is truncated")

        wanted = requested_name.upper()
        offset = 0
        while offset < len(directory):
            record_length = directory[offset]
            if record_length == 0:
                offset = ((offset // SECTOR_SIZE) + 1) * SECTOR_SIZE
                continue

            record = directory[offset : offset + record_length]
            if len(record) != record_length or record_length < 34:
                raise SetupError("ISO9660 directory record is malformed")

            name_length = record[32]
            raw_name = record[33 : 33 + name_length]
            name = raw_name.decode("ascii", errors="strict").split(";", 1)[0].upper()
            is_directory = bool(record[25] & 0x02)
            if not is_directory and name == wanted:
                file_lba = int.from_bytes(record[2:6], "little")
                file_size = int.from_bytes(record[10:14], "little")
                iso.seek(file_lba * SECTOR_SIZE)
                data = iso.read(file_size)
                if len(data) != file_size:
                    raise SetupError(f"{requested_name} is truncated in the ISO")
                return data

            offset += record_length

    raise SetupError(f"{requested_name} was not found in the ISO root directory")


def extract_load_image(elf: bytes, config: dict[str, object]) -> tuple[bytes, dict[str, int]]:
    if len(elf) < 52 or elf[:4] != b"\x7fELF":
        raise SetupError("SLUS_217.82 is not an ELF executable")
    if elf[4] != 1 or elf[5] != 1:
        raise SetupError("target ELF must be 32-bit little-endian")

    header = struct.unpack_from("<HHIIIIIHHHHHH", elf, 16)
    elf_type, machine, _version, entry, phoff = header[:5]
    phentsize, phnum = header[8], header[9]
    require_equal("ELF type", elf_type, 2)
    require_equal("ELF machine", machine, 8)

    executable_loads: list[dict[str, int]] = []
    for index in range(phnum):
        offset = phoff + index * phentsize
        if offset + 32 > len(elf):
            raise SetupError("ELF program header table is truncated")
        fields = struct.unpack_from("<IIIIIIII", elf, offset)
        segment = dict(zip(("type", "offset", "vaddr", "paddr", "filesz", "memsz", "flags", "align"), fields))
        if segment["type"] == 1 and segment["filesz"] and (segment["flags"] & 1):
            executable_loads.append(segment)

    candidates = [segment for segment in executable_loads if segment["vaddr"] <= entry < segment["vaddr"] + segment["memsz"]]
    if len(candidates) != 1:
        raise SetupError(f"expected one executable PT_LOAD containing entry point, found {len(candidates)}")
    load = candidates[0]

    expected_entry = parse_int(config["entry"])
    expected_offset = parse_int(config["load_offset"])
    expected_vram = parse_int(config["load_vram"])
    expected_size = parse_int(config["load_size"])
    require_equal("ELF entry point", entry, expected_entry)
    require_equal("PT_LOAD file offset", load["offset"], expected_offset)
    require_equal("PT_LOAD virtual address", load["vaddr"], expected_vram)
    require_equal("PT_LOAD file size", load["filesz"], expected_size)

    end = load["offset"] + load["filesz"]
    if end > len(elf):
        raise SetupError("ELF PT_LOAD extends beyond the file")
    return elf[load["offset"] : end], load


def write_atomic(path: Path, data: bytes) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    temporary = path.with_name(path.name + ".tmp")
    temporary.write_bytes(data)
    temporary.replace(path)


def setup(iso_path: Path, output_root: Path) -> None:
    target = json.loads(TARGET_CONFIG.read_text(encoding="utf-8"))
    disc_config = target["disc"]
    elf_config = target["elf"]
    image_config = target["image"]

    if not iso_path.is_file():
        raise SetupError(f"ISO does not exist: {iso_path}")
    require_equal("disc size", iso_path.stat().st_size, disc_config["size"])
    disc_sha1 = sha1_file(iso_path)
    require_equal("disc SHA-1", disc_sha1, disc_config["sha1"])

    system_cnf = read_iso_root_file(iso_path, "SYSTEM.CNF")
    elf = read_iso_root_file(iso_path, elf_config["filename"])
    boot_match = re.search(rb"BOOT2\s*=\s*cdrom0:\\([^;\r\n]+);1", system_cnf, re.IGNORECASE)
    if not boot_match:
        raise SetupError("SYSTEM.CNF does not contain a valid BOOT2 entry")
    boot_name = boot_match.group(1).decode("ascii").replace("\\", "/").rsplit("/", 1)[-1]
    require_equal("SYSTEM.CNF boot executable", boot_name.upper(), elf_config["filename"].upper())

    require_equal("retail ELF size", len(elf), elf_config["size"])
    elf_sha1 = sha1_bytes(elf)
    require_equal("retail ELF SHA-1", elf_sha1, elf_config["sha1"])

    image, load = extract_load_image(elf, elf_config)
    require_equal("load image size", len(image), image_config["size"])
    image_sha1 = sha1_bytes(image)
    require_equal("load image SHA-1", image_sha1, image_config["sha1"])

    write_atomic(output_root / "orig" / "SYSTEM.CNF", system_cnf)
    write_atomic(output_root / "orig" / elf_config["filename"], elf)
    write_atomic(output_root / image_config["filename"], image)

    print(f"disc:  {disc_sha1}  OK")
    print(f"ELF:   {elf_sha1}  OK  ({len(elf)} bytes)")
    print(f"image: {image_sha1}  OK  ({len(image):#x} bytes at {load['vaddr']:#010x})")
    print(f"entry: {parse_int(elf_config['entry']):#010x}")
    print(f"gp:    {parse_int(elf_config['gp']):#010x}")


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("iso", type=Path, help="path to the user-supplied Persona 4 USA ISO")
    parser.add_argument(
        "--output-root",
        type=Path,
        default=REPO,
        help="repository root receiving orig/ and image.bin (default: this repository)",
    )
    args = parser.parse_args()

    try:
        setup(args.iso.resolve(), args.output_root.resolve())
    except (OSError, SetupError, UnicodeError, json.JSONDecodeError) as error:
        print(f"setup: {error}", file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
