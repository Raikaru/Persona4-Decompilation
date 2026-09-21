"""Recover RenderWare sky2 struct layouts from a DWARF 1 PlayStation 2 build.

The 3.7.0.2 source release this tree reconstructs RenderWare from ships no
platform driver, so the sky2 renderer has no source, no names, and - the
part that actually blocks writing it - no struct layouts. `include/rw/sky2`
holds the 3.5 SDK's exported headers, which declare the API but describe
the driver's internal objects only as far as a public header ever does.

NBA Ballers: Phenom (SLUS-21186, review build) compiled RenderWare FROM
SOURCE with debugging on: its `.debug` section carries
`C:\\mwy\\BALLER~1\\main\\Libs\\RW\\Graphics\\rwsdk\\driver\\sky2` and the
internal member names with it - dmaPkt, tcaaDisp, skyTexCache,
rwDMA_flipData. Its compiler is Metrowerks - every one of its 1341
RenderWare compilation units names `MW MIPS C Compiler (2.4.1.01)` as
producer, the same family as this tree's MWCCPS2 3.0.1 b119 block; the
`gcc2_compiled.` markers in the image belong to other code. Ballers is
a different RenderWare release, so its instructions are not Persona 4's
byte for byte, but its names DO transfer where whole functions are
relocation-identical (see tools/port_rw_names.py), and a struct layout
is a property of the source and the ABI besides.

The format is DWARF version 1, which binutils dropped long ago: `.debug` is
a flat sequence of DIEs, each a 4-byte total length, a 2-byte tag, then
attributes. An attribute's 16-bit code carries the form in its low four
bits, so the parser can skip attributes it does not understand without a
.debug_abbrev to consult. Children are the DIEs between a parent and the
offset its AT_sibling names.

usage: python3 -E -s tools/rw_dwarf.py <elf> --grep sky
       python3 -E -s tools/rw_dwarf.py <elf> --name rwDMA_flipData
"""
from __future__ import annotations

import argparse
import json
import os
import re
import struct
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))
import verify as V  # noqa: E402

TAG_STRUCTURE = 0x0013
TAG_UNION = 0x0017
TAG_MEMBER = 0x000D
TAG_TYPEDEF = 0x0016
TAG_ARRAY_TYPE = 0x0001
TAG_COMPILE_UNIT = 0x0011
TAG_GLOBAL_SUBROUTINE = 0x0006
TAG_SUBROUTINE = 0x0014
AT_LOW_PC = 0x0110
AT_HIGH_PC = 0x0120
TAG_ENUMERATION = 0x0004

AT_SIBLING = 0x0010
AT_LOCATION = 0x0020
AT_NAME = 0x0030
AT_BYTE_SIZE = 0x00B0
AT_BIT_OFFSET = 0x00C0
AT_BIT_SIZE = 0x00D0
AT_FUND_TYPE = 0x0050
AT_MOD_FUND_TYPE = 0x0060
AT_USER_DEF_TYPE = 0x0070
AT_MOD_U_D_TYPE = 0x0080

# DWARF 1 fundamental types, spelled the way RenderWare's headers spell them
# so the emitted C reads like the rest of the tree.
FUND_TYPES = {
    0x0001: "RwChar", 0x0002: "RwInt8", 0x0003: "RwUInt8",
    0x0004: "RwInt16", 0x0005: "RwInt16", 0x0006: "RwUInt16",
    0x0007: "RwInt32", 0x0008: "RwInt32", 0x0009: "RwUInt32",
    0x000A: "RwInt32", 0x000B: "RwInt32", 0x000C: "RwUInt32",
    0x000D: "void *", 0x000E: "RwReal", 0x000F: "RwFloat64",
    0x0014: "void", 0x0015: "RwBool",
    0x8008: "RwInt64", 0x8108: "RwUInt64",
}

MOD_POINTER_TO, MOD_REFERENCE_TO, MOD_CONST, MOD_VOLATILE = 0x01, 0x02, 0x03, 0x04

AT_SUBSCR_DATA = 0x00A0

# AT_subscr_data is a list of subscripts, each introduced by a format byte.
# The four `FMT_*_C_C` shapes are the only ones a C array of constant extent
# produces, and FMT_ET introduces the element type as a lone attribute.
FMT_FT_C_C, FMT_UT_C_C, FMT_ET = 0x00, 0x04, 0x08

# Widths the PlayStation 2 EABI gives the above, used to turn a member's byte
# span into an array extent without decoding AT_subscr_data.
TYPE_WIDTH = {
    "RwChar": 1, "RwInt8": 1, "RwUInt8": 1, "RwInt16": 2, "RwUInt16": 2,
    "RwInt32": 4, "RwUInt32": 4, "RwReal": 4, "RwBool": 4,
    "RwFloat64": 8, "RwInt64": 8, "RwUInt64": 8,
}

# DWARF 1 location opcodes. A member's location is the one-entry program
# `OP_CONST <offset>; OP_ADD`, applied to the object's base address.
OP_CONST, OP_ADD = 0x04, 0x07

FORM_ADDR, FORM_REF, FORM_BLOCK2, FORM_BLOCK4 = 1, 2, 3, 4
FORM_DATA2, FORM_DATA4, FORM_DATA8, FORM_STRING = 5, 6, 7, 8


def _cstring(blob: bytes, offset: int) -> tuple[str, int]:
    end = blob.index(b"\0", offset)
    return blob[offset:end].decode("latin-1"), end + 1


def parse_dies(blob: bytes):
    """Yield (offset, tag, attributes) for every DIE in a DWARF 1 section."""
    cursor = 0
    size = len(blob)
    while cursor + 4 <= size:
        start = cursor
        length = struct.unpack_from("<I", blob, cursor)[0]
        if length < 4 or start + length > size:
            # Not a length we can trust; step a word and try to resynchronise.
            cursor += 4
            continue
        if length < 8:
            # DWARF 1 pads a sibling chain out to its parent's AT_sibling with
            # short entries that carry a length and nothing else. Advancing by
            # a fixed word here instead of by the stated length is what makes
            # the walk drift into the middle of the next DIE's attributes.
            cursor += length
            continue
        tag = struct.unpack_from("<H", blob, cursor + 4)[0]
        pos, end = cursor + 6, start + length
        attrs: dict[int, object] = {}
        while pos + 2 <= end:
            code = struct.unpack_from("<H", blob, pos)[0]
            pos += 2
            form, name = code & 0xF, code & 0xFFF0
            try:
                if form == FORM_ADDR or form == FORM_REF:
                    value = struct.unpack_from("<I", blob, pos)[0]; pos += 4
                elif form == FORM_DATA2:
                    value = struct.unpack_from("<H", blob, pos)[0]; pos += 2
                elif form == FORM_DATA4:
                    value = struct.unpack_from("<I", blob, pos)[0]; pos += 4
                elif form == FORM_DATA8:
                    value = struct.unpack_from("<Q", blob, pos)[0]; pos += 8
                elif form == FORM_STRING:
                    value, pos = _cstring(blob, pos)
                elif form == FORM_BLOCK2:
                    n = struct.unpack_from("<H", blob, pos)[0]; pos += 2
                    value = blob[pos:pos + n]; pos += n
                elif form == FORM_BLOCK4:
                    n = struct.unpack_from("<I", blob, pos)[0]; pos += 4
                    value = blob[pos:pos + n]; pos += n
                else:
                    break
            except (struct.error, ValueError):
                break
            attrs[name] = value
        yield start, tag, attrs
        cursor = end


def member_offset(location: bytes) -> int | None:
    """A DWARF 1 member location is `OP_CONST <offset>; OP_ADD` and no more."""
    if len(location) >= 6 and location[0] == OP_CONST and location[5] == OP_ADD:
        return struct.unpack_from("<I", location, 1)[0]
    return None


def _modifier_chain(modifiers: bytes, base: str) -> str:
    """DWARF 1 lists modifiers outermost first; C spells them the other way."""
    for modifier in reversed(modifiers):
        if modifier == MOD_POINTER_TO:
            base += " *" if not base.endswith("*") else "*"
        elif modifier == MOD_REFERENCE_TO:
            base += " &"
        elif modifier == MOD_CONST:
            base = "const " + base
        elif modifier == MOD_VOLATILE:
            base = "volatile " + base
    return base


class TypeResolver:
    """Turns a DIE's type attributes into a C type spelling."""

    def __init__(self, by_offset):
        self.by_offset = by_offset

    def named(self, offset: int, depth: int = 0) -> str:
        """The name of a user-defined type DIE, chasing typedefs one hop."""
        entry = self.by_offset.get(offset)
        if entry is None or depth > 4:
            return "void *"
        tag, attrs = entry
        name = attrs.get(AT_NAME)
        if isinstance(name, str):
            if tag == TAG_STRUCTURE:
                return "struct " + name
            if tag == TAG_UNION:
                return "union " + name
            if tag == TAG_ENUMERATION:
                return "enum " + name
            return name
        if tag == TAG_ARRAY_TYPE:
            decoded = self.array(attrs, depth)
            if decoded is not None:
                element, extents = decoded
                return element + "".join(f"[{n}]" for n in extents)
            return self.of(attrs, depth + 1)
        return "void *"

    def array(self, attrs, depth: int = 0):
        """(element type, extents) for an array DIE, or None."""
        blob = attrs.get(AT_SUBSCR_DATA)
        if not isinstance(blob, bytes):
            return None
        pos, extents, element = 0, [], None
        while pos < len(blob):
            fmt = blob[pos]; pos += 1
            if fmt in (FMT_FT_C_C, FMT_UT_C_C):
                pos += 2 if fmt == FMT_FT_C_C else 4
                if pos + 8 > len(blob):
                    break
                low, high = struct.unpack_from("<ii", blob, pos); pos += 8
                extents.append(high - low + 1)
            elif fmt == FMT_ET:
                if pos + 2 > len(blob):
                    break
                code = struct.unpack_from("<H", blob, pos)[0]; pos += 2
                form, name = code & 0xF, code & 0xFFF0
                if form == FORM_DATA2:
                    element = self.of({name: struct.unpack_from("<H", blob, pos)[0]},
                                      depth + 1); pos += 2
                elif form == FORM_REF:
                    element = self.of({name: struct.unpack_from("<I", blob, pos)[0]},
                                      depth + 1); pos += 4
                elif form == FORM_BLOCK2:
                    n = struct.unpack_from("<H", blob, pos)[0]; pos += 2
                    element = self.of({name: blob[pos:pos + n]}, depth + 1); pos += n
                else:
                    break
            else:
                break
        if element is None:
            return None
        return element, [n for n in extents if n > 0]

    def of(self, attrs, depth: int = 0) -> str:
        fundamental = attrs.get(AT_FUND_TYPE)
        if isinstance(fundamental, int):
            return FUND_TYPES.get(fundamental, "RwInt32")
        modified = attrs.get(AT_MOD_FUND_TYPE)
        if isinstance(modified, bytes) and len(modified) >= 2:
            base = FUND_TYPES.get(
                struct.unpack_from("<H", modified, len(modified) - 2)[0], "RwInt32")
            return _modifier_chain(modified[:-2], base)
        user = attrs.get(AT_USER_DEF_TYPE)
        if isinstance(user, int):
            return self.named(user, depth)
        modified_user = attrs.get(AT_MOD_U_D_TYPE)
        if isinstance(modified_user, bytes) and len(modified_user) >= 4:
            target = struct.unpack_from("<I", modified_user, len(modified_user) - 4)[0]
            return _modifier_chain(modified_user[:-4], self.named(target, depth))
        return "RwInt32"


def collect(blob: bytes):
    """Structures, each with its members' names, offsets, C types, and the
    compilation unit that defined them."""
    dies = list(parse_dies(blob))
    by_offset = {offset: (tag, attrs) for offset, tag, attrs in dies}
    order = [offset for offset, _tag, _attrs in dies]
    index = {offset: i for i, offset in enumerate(order)}
    resolver = TypeResolver(by_offset)
    # A struct declared inside a typedef has no name of its own - DWARF 1
    # calls it `@anonNN`. The typedef pointing at it carries the name the
    # source actually used, which is the one worth emitting.
    alias: dict[int, str] = {}
    for _offset, tag, attrs in dies:
        if tag == TAG_TYPEDEF:
            target, label = attrs.get(AT_USER_DEF_TYPE), attrs.get(AT_NAME)
            if isinstance(target, int) and isinstance(label, str):
                alias.setdefault(target, label)
    out: dict[str, dict] = {}
    unit = ""
    for offset, tag, attrs in dies:
        if tag == TAG_COMPILE_UNIT:
            source = attrs.get(AT_NAME)
            unit = source.replace("\\", "/") if isinstance(source, str) else ""
        if tag not in (TAG_STRUCTURE, TAG_UNION):
            continue
        name = attrs.get(AT_NAME)
        size = attrs.get(AT_BYTE_SIZE)
        if not isinstance(name, str) or not isinstance(size, int):
            continue
        if name.startswith("@"):
            name = alias.get(offset, name)
        sibling = attrs.get(AT_SIBLING)
        members = []
        i = index[offset] + 1
        while i < len(order):
            child_offset = order[i]
            if isinstance(sibling, int) and child_offset >= sibling:
                break
            child_tag, child_attrs = by_offset[child_offset]
            if child_tag == TAG_MEMBER:
                child_name = child_attrs.get(AT_NAME)
                location = child_attrs.get(AT_LOCATION)
                where = member_offset(location) if isinstance(location, bytes) else None
                if isinstance(child_name, str) and where is not None:
                    members.append(dict(name=child_name, offset=where,
                                        type=resolver.of(child_attrs),
                                        bits=child_attrs.get(AT_BIT_SIZE),
                                        bit_offset=child_attrs.get(AT_BIT_OFFSET)))
            i += 1
        if not members:
            continue
        record = dict(size=size, kind="union" if tag == TAG_UNION else "struct",
                      unit=unit, members=members)
        # Anonymous structs repeat their names across units, so they are kept
        # per unit; a named one is global and the richest copy wins.
        key = f"{unit}|{name}" if name.startswith("@") else name
        previous = out.get(key)
        if previous is None or len(members) > len(previous["members"]):
            out[key] = record
    return out


def emit_c(name: str, entry: dict, lookup=None, indent: str = "    ") -> str:
    """A C declaration whose layout is the one the reference build used.

    Array extents are recovered from the gap to the next member rather than
    from AT_subscr_data: the gap is what actually has to be reproduced, and
    it stays right even where the element type resolves only approximately.
    """
    members = sorted(entry["members"],
                     key=lambda m: (m["offset"], m.get("bit_offset") or 0))
    wide = any((m.get("bit_offset") or 0) + (m.get("bits") or 0) > 32
               for m in members)
    lines = [f"typedef {entry['kind']} {name}", "{"]
    lookup = lookup or {}
    for position, member in enumerate(members):
        following = (members[position + 1]["offset"] if position + 1 < len(members)
                     else entry["size"])
        span = max(0, following - member["offset"])
        spelling, suffix = member["type"], ""
        if "[" in spelling:
            spelling, _, extent = spelling.partition("[")
            suffix = "[" + extent
        if member.get("bits"):
            suffix = f" : {member['bits']}"
            if wide:
                spelling = "RwUInt64"
        elif suffix:
            pass
        elif spelling.endswith("*"):
            if span > 4 and span % 4 == 0:
                suffix = f"[{span // 4}]"
        else:
            width = TYPE_WIDTH.get(spelling)
            if width and span > width and span % width == 0:
                suffix = f"[{span // width}]"
            elif width and span and span < width:
                spelling = "RwUInt8"
                suffix = f"[{span}]" if span > 1 else ""
        bare = spelling.replace("struct ", "").replace("union ", "").strip()
        nested = lookup.get(f"{entry['unit']}|{bare}") if bare.startswith("@") else None
        if nested is not None:
            # An anonymous struct has no name to refer to, so the only legal C
            # is the definition itself, written where the member is declared.
            lines.append(f"{indent}/* 0x{member['offset']:04X} */ {nested['kind']}")
            lines.append(indent + "{")
            body = emit_c(bare, nested, lookup, indent + "    ").splitlines()
            lines.extend(body[2:-1])
            lines.append(f"{indent}}} {member['name']}{suffix};")
            continue
        joiner = "" if spelling.endswith("*") else " "
        lines.append(f"{indent}/* 0x{member['offset']:04X} */ "
                     f"{spelling}{joiner}{member['name']}{suffix};")
    lines.append(f"}} {name.lstrip('_')};   /* 0x{entry['size']:X} bytes */")
    if indent != "    ":                      # nested: no typedef, no trailer
        lines[0] = f"{entry['kind']}"
        lines[-1] = "}"
    return "\n".join(lines)


def order_by_dependency(selected: dict[str, dict]) -> list[str]:
    """Emit a struct after every struct it embeds BY VALUE.

    Pointer members need no definition, so only value members constrain the
    order, and cycles can only be built from pointers. A stable alphabetical
    tie-break keeps the generated header diffable.
    """
    remaining = dict(sorted(selected.items()))
    emitted: list[str] = []
    done: set[str] = set()
    while remaining:
        progressed = False
        for name in list(remaining):
            needs = set()
            for member in remaining[name]["members"]:
                spelling = member["type"]
                if spelling.endswith("*"):
                    continue
                bare = spelling.replace("struct ", "").replace("union ", "").strip()
                if bare in remaining and bare != name:
                    needs.add(bare)
            if not needs - done:
                emitted.append(name)
                done.add(name)
                del remaining[name]
                progressed = True
        if not progressed:                      # a value cycle cannot exist
            emitted.extend(sorted(remaining))   # in valid C; emit and move on
            break
    return emitted


def write_header(path: Path, elf: Path, selected: dict[str, dict], units,
                 lookup=None) -> None:
    forwards = sorted({member["type"].replace(" *", "").replace("*", "").strip()
                       for entry in selected.values() for member in entry["members"]
                       if member["type"].endswith("*")
                       and member["type"].startswith(("struct ", "union "))})
    body = [
        "/* RenderWare PlayStation 2 driver-internal layouts, recovered from",
        " * DWARF 1 debugging information. GENERATED - do not hand-edit; see",
        " * the README beside this file and regenerate with tools/rw_dwarf.py.",
        " *",
        f" * source: {elf.name}",
        f" * units:  {', '.join(units)}",
        " */",
        "#ifndef RW_SKY2_PRIVATE_H",
        "#define RW_SKY2_PRIVATE_H",
        "",
        '#include "rwcore.h"',
        "",
    ]
    if forwards:
        body.append("/* Referenced only through pointers, so left incomplete. */")
        body.extend(f"{forward};" for forward in forwards)
        body.append("")
    for name in order_by_dependency(selected):
        body.append(f"/* {selected[name]['unit'].split('/')[-1]} */")
        body.append(emit_c(name, selected[name], lookup))
        body.append("")
    body.append("#endif /* RW_SKY2_PRIVATE_H */")
    path.write_text("\n".join(body) + "\n")


def collect_functions(blob: bytes, wanted: str):
    """Functions each compilation unit defines, for units matching `wanted`.

    This is the object ownership a linker map would give, except it survives
    stripping and it names the source file rather than the archive member.
    """
    units: dict[str, list] = {}
    unit = ""
    for _offset, tag, attrs in parse_dies(blob):
        if tag == TAG_COMPILE_UNIT:
            source = attrs.get(AT_NAME)
            unit = source.replace("\\", "/") if isinstance(source, str) else ""
        elif tag in (TAG_GLOBAL_SUBROUTINE, TAG_SUBROUTINE) and wanted in unit:
            name, low = attrs.get(AT_NAME), attrs.get(AT_LOW_PC)
            high = attrs.get(AT_HIGH_PC)
            if isinstance(name, str) and isinstance(low, int):
                units.setdefault(unit.split("/")[-1], []).append(dict(
                    name=name, addr=f"{low:08x}",
                    size=(high - low) if isinstance(high, int) else None,
                    static=tag == TAG_SUBROUTINE))
    return units


def complete_types(header: str, includes, candidates) -> set:
    """Which candidate structs the given header already defines COMPLETELY.

    Decided by compiling, not by pattern: RenderWare's sky2 header declares
    several of these only inside `#if defined(_LIBGRAPH_H) && ...`, so the
    text contains a definition that the preprocessor never reaches. An
    incomplete type is one this tree cannot actually use.
    """
    import subprocess
    import eegcc_shim
    config = V.load_config()
    names = sorted(candidates)
    probe = [f'#include "{header}"', ""]
    probe += [f"char probe_{i}[sizeof(struct {name})];"
              for i, name in enumerate(names)]
    scratch = Path(os.environ.get("TMPDIR", "/tmp")) / "rw_dwarf_probe.c"
    scratch.write_text("\n".join(probe) + "\n")
    command = [config["eegcc_root"] + "/bin/ee-gcc", "-fsyntax-only",
               "-Bbuild/toolchain/ee/bin/"]
    for directory in includes:
        command += ["-I" + directory]
    command.append(str(scratch))
    result = subprocess.run(command, capture_output=True, env=eegcc_shim._cc_env())
    broken = set()
    for line in result.stderr.decode().splitlines():
        match = re.search(r"probe\.c:(\d+):", line) or re.search(r":(\d+):", line)
        if match:
            index = int(match.group(1)) - 3
            if 0 <= index < len(names):
                broken.add(names[index])
    return set(names) - broken


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("elf")
    parser.add_argument("--grep", default=None)
    parser.add_argument("--name", action="append", default=[])
    parser.add_argument("--header", default=None,
                        help="write a C header of the structs a unit defines")
    parser.add_argument("--from-unit", default="driver/sky2",
                        help="substring of the defining source path to select on")
    parser.add_argument("--skip-complete-in", default=None,
                        help="header to include; structs it already defines "
                             "COMPLETELY are left out of the generated one")
    parser.add_argument("--include", action="append", default=[],
                        help="include directory for --skip-complete-in")
    parser.add_argument("--functions", default=None,
                        help="write the unit -> function inventory here")
    parser.add_argument("--json", default=None)
    args = parser.parse_args()

    data = Path(args.elf).read_bytes()
    _endian, sections = V.elf_sections(data)
    debug = next((s for s in sections if s.get("name") == ".debug"), None)
    if debug is None:
        print("no .debug section", file=sys.stderr)
        return 2
    blob = data[debug["offset"]:debug["offset"] + debug["size"]]
    print(f".debug is {len(blob)} bytes", file=sys.stderr)
    found = collect(blob)
    print(f"{len(found)} structures with members", file=sys.stderr)

    if args.json:
        Path(args.json).write_text(json.dumps(
            {k: v for k, v in sorted(found.items())}, indent=1) + "\n")
    if args.grep is not None:
        for name in sorted(found):
            if args.grep.lower() in name.lower():
                print(f"{name:<34} {found[name]['size']:>6} bytes  "
                      f"{len(found[name]['members']):>3} members")
    for name in args.name:
        entry = found.get(name)
        if entry is None:
            print(f"/* {name}: not present in this build */")
            continue
        print()
        print(emit_c(name, entry))
    if args.functions:
        inventory = collect_functions(blob, args.from_unit)
        Path(args.functions).write_text(json.dumps(inventory, indent=1) + "\n")
        total = sum(len(v) for v in inventory.values())
        print(f"{total} functions in {len(inventory)} units -> {args.functions}",
              file=sys.stderr)
    if args.header:
        chosen = {name: entry for name, entry in found.items()
                  if args.from_unit in entry["unit"] and not name.startswith("@")
                  and "|" not in name}
        if args.skip_complete_in:
            already = complete_types(args.skip_complete_in, args.include, chosen)
            for name in already:
                del chosen[name]
            print(f"already complete in {args.skip_complete_in}, so omitted: "
                  f"{', '.join(sorted(already)) or 'none'}", file=sys.stderr)
        units = sorted({entry["unit"].split("/")[-1] for entry in chosen.values()})
        write_header(Path(args.header), Path(args.elf), chosen, units, found)
        print(f"{len(chosen)} structs from {len(units)} units -> {args.header}",
              file=sys.stderr)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
