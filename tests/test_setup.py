from __future__ import annotations

import importlib.util
import struct
import tempfile
import unittest
from pathlib import Path

MODULE_PATH = Path(__file__).resolve().parents[1] / "tools" / "setup.py"
SPEC = importlib.util.spec_from_file_location("p4_setup", MODULE_PATH)
assert SPEC is not None and SPEC.loader is not None
setup = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(setup)


def directory_record(extent: int, size: int, name: bytes, flags: int = 0) -> bytes:
    padding = b"\0" if len(name) % 2 == 0 else b""
    length = 33 + len(name) + len(padding)
    record = bytearray(length)
    record[0] = length
    record[2:6] = extent.to_bytes(4, "little")
    record[6:10] = extent.to_bytes(4, "big")
    record[10:14] = size.to_bytes(4, "little")
    record[14:18] = size.to_bytes(4, "big")
    record[25] = flags
    record[28:30] = (1).to_bytes(2, "little")
    record[30:32] = (1).to_bytes(2, "big")
    record[32] = len(name)
    record[33 : 33 + len(name)] = name
    return bytes(record)


def synthetic_iso(filename: str, payload: bytes) -> bytes:
    sector = setup.SECTOR_SIZE
    root_lba = 18
    file_lba = 19
    root_size = sector
    image = bytearray(20 * sector)

    pvd_offset = 16 * sector
    image[pvd_offset] = 1
    image[pvd_offset + 1 : pvd_offset + 6] = b"CD001"
    image[pvd_offset + 6] = 1
    root = directory_record(root_lba, root_size, b"\0", flags=2)
    image[pvd_offset + 156 : pvd_offset + 156 + len(root)] = root

    records = b"".join(
        (
            root,
            directory_record(root_lba, root_size, b"\1", flags=2),
            directory_record(file_lba, len(payload), f"{filename};1".encode("ascii")),
        )
    )
    image[root_lba * sector : root_lba * sector + len(records)] = records
    image[file_lba * sector : file_lba * sector + len(payload)] = payload
    return bytes(image)


def synthetic_elf(payload: bytes = b"0123456789ABCDEF") -> bytes:
    elf = bytearray(0x80 + len(payload))
    elf[:16] = b"\x7fELF\x01\x01\x01" + b"\0" * 9
    struct.pack_into(
        "<HHIIIIIHHHHHH",
        elf,
        16,
        2,
        8,
        1,
        0x100008,
        52,
        0,
        0,
        52,
        32,
        1,
        40,
        0,
        0,
    )
    struct.pack_into("<IIIIIIII", elf, 52, 1, 0x80, 0x100000, 0x100000, len(payload), len(payload), 5, 0x80)
    elf[0x80:] = payload
    return bytes(elf)


class IsoReaderTests(unittest.TestCase):
    def test_reads_versioned_root_file(self) -> None:
        payload = b"BOOT2 = cdrom0:\\SLUS_217.82;1\r\n"
        with tempfile.TemporaryDirectory() as temporary:
            iso_path = Path(temporary) / "disc.iso"
            iso_path.write_bytes(synthetic_iso("SYSTEM.CNF", payload))
            self.assertEqual(setup.read_iso_root_file(iso_path, "system.cnf"), payload)

    def test_rejects_missing_primary_volume_descriptor(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            iso_path = Path(temporary) / "bad.iso"
            iso_path.write_bytes(b"\0" * (20 * setup.SECTOR_SIZE))
            with self.assertRaisesRegex(setup.SetupError, "primary volume descriptor"):
                setup.read_iso_root_file(iso_path, "SYSTEM.CNF")


class ElfReaderTests(unittest.TestCase):
    def setUp(self) -> None:
        self.config = {
            "entry": "0x100008",
            "load_offset": "0x80",
            "load_vram": "0x100000",
            "load_size": "0x10",
        }

    def test_extracts_executable_load_containing_entry(self) -> None:
        payload = b"0123456789ABCDEF"
        image, load = setup.extract_load_image(synthetic_elf(payload), self.config)
        self.assertEqual(image, payload)
        self.assertEqual(load["vaddr"], 0x100000)

    def test_rejects_unexpected_target_layout(self) -> None:
        wrong = dict(self.config, load_size="0x20")
        with self.assertRaisesRegex(setup.SetupError, "PT_LOAD file size"):
            setup.extract_load_image(synthetic_elf(), wrong)


if __name__ == "__main__":
    unittest.main()
