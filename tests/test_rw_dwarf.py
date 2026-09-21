from __future__ import annotations

import importlib.util
import json
import re
import struct
import sys
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))
SPEC = importlib.util.spec_from_file_location("p4_rw_dwarf",
                                              REPO / "tools" / "rw_dwarf.py")
assert SPEC is not None and SPEC.loader is not None
rw = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(rw)

HEADER = REPO / "include" / "rw" / "sky2priv" / "skypriv.h"
STRUCTS = REPO / "docs" / "sky2" / "ballers_structs.json"


def die(tag: int, attributes: bytes, children: bytes = b"", base: int = 0) -> bytes:
    """A DWARF 1 entry whose AT_sibling points past its children.

    An entry's own length covers only itself; children follow it in the
    section, and the sibling offset is how a reader knows where they end.
    """
    length = 4 + 2 + 2 + 4 + len(attributes)
    sibling = base + length + len(children)
    body = struct.pack("<HI", AT_SIBLING_REF, sibling) + attributes
    return struct.pack("<IH", length, tag) + body + children


AT_SIBLING_REF = 0x0010 | 2          # AT_sibling, FORM_REF
AT_NAME_STRING = 0x0030 | 8          # AT_name, FORM_STRING
AT_BYTE_SIZE_DATA4 = 0x00B0 | 6      # AT_byte_size, FORM_DATA4
AT_LOCATION_BLOCK2 = 0x0020 | 3      # AT_location, FORM_BLOCK2
AT_FUND_TYPE_DATA2 = 0x0050 | 5      # AT_fund_type, FORM_DATA2


def name(text: str) -> bytes:
    return struct.pack("<H", AT_NAME_STRING) + text.encode() + b"\0"


def byte_size(value: int) -> bytes:
    return struct.pack("<HI", AT_BYTE_SIZE_DATA4, value)


def at_offset(value: int) -> bytes:
    program = struct.pack("<BIB", rw.OP_CONST, value, rw.OP_ADD)
    return struct.pack("<HH", AT_LOCATION_BLOCK2, len(program)) + program


def fund(value: int) -> bytes:
    return struct.pack("<HH", AT_FUND_TYPE_DATA2, value)


class ParseDies(unittest.TestCase):
    def test_short_padding_entry_does_not_desynchronise_the_walk(self):
        """A 4- or 5-byte pad carries a length and no tag.

        Stepping a fixed word past one instead of its stated length lands
        inside the next entry's attributes, and the walk then reads garbage
        lengths for the rest of the section - which is exactly the failure
        that made the first version of this parser return 1132 entries out
        of 723634.
        """
        first = die(rw.TAG_STRUCTURE, name("Early") + byte_size(4))
        blob = first + struct.pack("<I", 5) + b"\0" + die(
            rw.TAG_STRUCTURE, name("Late") + byte_size(8))
        tags = [attrs.get(0x0030) for _off, _tag, attrs in rw.parse_dies(blob)]
        self.assertEqual(["Early", "Late"], tags)

    def test_members_belong_to_the_structure_that_precedes_them(self):
        members = (die(rw.TAG_MEMBER, name("lo") + at_offset(0) + fund(0x0007))
                   + die(rw.TAG_MEMBER, name("hi") + at_offset(4) + fund(0x0009)))
        blob = die(rw.TAG_STRUCTURE, name("Pair") + byte_size(8), members)
        found = rw.collect(blob)
        self.assertIn("Pair", found)
        self.assertEqual([("lo", 0), ("hi", 4)],
                         [(m["name"], m["offset"]) for m in found["Pair"]["members"]])


class MemberLocation(unittest.TestCase):
    def test_only_the_const_add_program_yields_an_offset(self):
        self.assertEqual(12, rw.member_offset(
            struct.pack("<BIB", rw.OP_CONST, 12, rw.OP_ADD)))
        # A register-relative location is a variable, not a member offset.
        self.assertIsNone(rw.member_offset(struct.pack("<BI", 0x01, 29)))
        self.assertIsNone(rw.member_offset(b""))


class EmitC(unittest.TestCase):
    def test_trailing_span_becomes_an_array_extent(self):
        entry = dict(size=16, kind="struct", unit="x.c", members=[
            dict(name="one", offset=0, type="RwInt32", bits=None),
            dict(name="rest", offset=4, type="RwInt32", bits=None)])
        self.assertIn("RwInt32 rest[3];", rw.emit_c("Thing", entry))

    def test_bitfield_crossing_the_first_word_widens_to_64_bits(self):
        """The GS register descriptions are 64-bit bitfields.

        Emitting them over RwUInt32 would not fit the declared widths and
        the compiler would silently lay the structure out differently.
        """
        entry = dict(size=8, kind="struct", unit="x.c", members=[
            dict(name="lo", offset=0, type="RwUInt32", bits=14, bit_offset=0),
            dict(name="hi", offset=0, type="RwUInt32", bits=45, bit_offset=19)])
        emitted = rw.emit_c("Reg", entry)
        self.assertIn("RwUInt64 hi : 45;", emitted)
        self.assertNotIn("RwUInt32", emitted)

    def test_value_members_are_ordered_after_what_they_embed(self):
        selected = {
            "Outer": dict(size=8, kind="struct", unit="x.c", members=[
                dict(name="inner", offset=0, type="struct Inner", bits=None)]),
            "Inner": dict(size=8, kind="struct", unit="x.c", members=[
                dict(name="value", offset=0, type="RwInt32", bits=None)]),
        }
        self.assertEqual(["Inner", "Outer"], rw.order_by_dependency(selected))


class GeneratedHeader(unittest.TestCase):
    """The checked-in header must still say what the recorded layouts say.

    It is generated, so the risk is a hand-edit drifting away from the debug
    information it claims to reproduce.
    """

    def test_every_declared_size_matches_the_recorded_layout(self):
        recorded = json.loads(STRUCTS.read_text())
        emitted = re.findall(r"^\} (\w+);\s+/\* 0x([0-9A-F]+) bytes \*/",
                             HEADER.read_text(), re.M)
        self.assertGreaterEqual(len(emitted), 13)
        for label, size in emitted:
            entry = recorded.get(label) or recorded.get("_" + label) \
                or recorded.get("__" + label)
            self.assertIsNotNone(entry, f"{label} is not in {STRUCTS.name}")
            self.assertEqual(entry["size"], int(size, 16), label)

    def test_every_member_lands_inside_its_structure(self):
        """A member at or past the end means the location program was misread.

        Offsets must also never go backwards: DWARF records members in
        declaration order, and a decode that loses its place produces a
        jumble. Repeats are legitimate - DWARF 1 flattens an anonymous
        union's members into the enclosing structure, as RpTeamOptElement
        does with staticRender and skinRender at 0xC.
        """
        recorded = json.loads(STRUCTS.read_text())
        self.assertGreater(len(recorded), 500)
        for label, entry in recorded.items():
            offsets = [member["offset"] for member in entry["members"]]
            self.assertEqual(offsets, sorted(offsets), label)
            self.assertLess(max(offsets), max(1, entry["size"]), label)


if __name__ == "__main__":
    unittest.main()
