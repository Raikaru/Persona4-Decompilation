"""Hash-validate the retail color extents, copies and first-family ordering."""
from pathlib import Path
import hashlib
import json
import struct
import sys

sys.path.insert(0, "tools")
import verify as V

cfg = V.load_config()
windows = V._read_json(V.FUNCTION_WINDOWS)
retail = V.RetailElf(cfg["retail_elf"], V._read_json(V.TARGET), windows["sha1"])
START, SIZE = 0x1265A0, 17616
body = retail.bytes_at(START, SIZE)


def word(address):
    return struct.unpack("<I", retail.bytes_at(address, 4))[0]


def check(address, expected):
    assert word(address) == expected, (hex(address), hex(word(address)), hex(expected))


def clear(address, offset):
    # addiu v1,sp,source; count=4; skip-null; four iterations of sb and +1.
    expected = [0x27A30000 | offset, 0x24020004, 0x10600008, 0,
                0xA0600000, 0x24630001, 0x2442FFFF, 0, 0, 0x1440FFFA, 0]
    for index, instruction in enumerate(expected):
        check(address + index * 4, instruction)


sites = [
    (0x126B68, 0x67C, 0x680, 0x126B30), (0x126D4C, 0x6A4, 0x6BC, 0x126D20),
    (0x127048, 0x6A0, 0x6BC, 0x127010), (0x128314, 0x674, 0x678, 0x1282DC),
    (0x128798, 0x66C, 0x670, 0x128760), (0x12896C, 0x664, 0x668, 0x128934),
    (0x128B24, 0x65C, 0x660, 0x128AEC), (0x128D74, 0x654, 0x658, 0x128D3C),
    (0x128ED8, 0x64C, 0x650, 0x128EA0), (0x129084, 0x644, 0x648, 0x12904C),
    (0x129408, 0x63C, 0x640, 0x1293D0), (0x1295D8, 0x634, 0x638, 0x1295A0),
    (0x129920, 0x62C, 0x630, 0x1298E8), (0x129AF8, 0x690, 0x6BC, 0x129AC0),
]
rows = []
for call, source, destination, copy in sites:
    clear(copy - 48, source)
    check(copy - 4, 0x27A40000 | destination)
    check(copy, 0xC7A00000 | source)
    check(copy + 4, 0xE7A00000 | destination)
    check(call, (3 << 26) | (0x2AAF20 >> 2))
    check(call + 4, 0)
    rows.append({"call": hex(call), "clear": hex(copy - 48), "copy": hex(copy),
                 "source_extent": [hex(source), hex(source + 3)],
                 "destination_extent": [hex(destination), hex(destination + 3)],
                 "shared_destination": destination == 0x6BC})
assert [START + i for i in range(0, SIZE, 4) if word(START + i) == (3 << 26) | (0x2AAF20 >> 2)] == [s[0] for s in sites]
clear(0x126A48, 0x684)
for address, instruction in {
    0x126A74: 0x240200FF, 0x126A78: 0xA3A20687, 0x126A7C: 0x27A40688,
    0x126A80: 0xC7A00684, 0x126A84: 0xE7A00688, 0x126A9C: 0x44806000,
    0x126AA0: 0x24060001, 0x126AA4: (3 << 26) | (0x45D6E0 >> 2),
    0x126AC0: 0x44806000, 0x126AC4: 0x27A40688, 0x126AC8: 0x24060001,
    0x126ACC: (3 << 26) | (0x45D6E0 >> 2), 0x126AEC: (3 << 26) | (0x126090 >> 2),
    0x126B70: (3 << 26) | (0x2AAAC0 >> 2), 0x126B88: 0x0040F809,
    0x126B90: (3 << 26) | (0x489F80 >> 2),
}.items():
    check(address, instruction)
# Matching 0045d6e0 preserves color a0, depth f12, state flag a2 and
# reads four f32 rectangle members from a1. These are separate ABI counters.
for address, instruction in {
    0x45D6FC: 0x0080982D, 0x45D700: 0x46006506, 0x45D704: 0x00C0902D,
    0x45D708: 0xC4A30000, 0x45D70C: 0xC4A20004,
    0x45D710: 0xC4A10008, 0x45D714: 0xC4A0000C,
}.items():
    check(address, instruction)
for call in (0x126AA4, 0x126ACC):
    check(call + 4, 0)
check(0x126A94, 0x27A504C0)
check(0x126AB8, 0x27A504C0)
# Include every direct stack memory access that overlaps these four objects,
# even if it starts outside the selected range. Include address materializers.
widths = {0x1E: 16, 0x1F: 16, 0x20: 1, 0x21: 2, 0x22: 4, 0x23: 4,
          0x24: 1, 0x25: 2, 0x26: 4, 0x27: 4, 0x28: 1, 0x29: 2,
          0x2A: 4, 0x2B: 4, 0x2C: 8, 0x2D: 8, 0x2E: 4,
          0x31: 4, 0x35: 8, 0x37: 8, 0x39: 4, 0x3D: 8, 0x3F: 8}
census = []
for offset in range(0, SIZE, 4):
    instruction = struct.unpack_from("<I", body, offset)[0]
    op, base, immediate = instruction >> 26, (instruction >> 21) & 31, instruction & 65535
    immediate = immediate - 65536 if immediate & 32768 else immediate
    if base != 29:
        continue
    width = widths.get(op)
    if (width and immediate < 0x68C and immediate + width > 0x67C) or (op == 9 and 0x67C <= immediate < 0x68C):
        census.append({"address": hex(START + offset), "word": f"{instruction:08x}",
                       "stack_offset": hex(immediate), "width": width})
assert [int(row["address"], 16) for row in census] == [0x126A48, 0x126A78, 0x126A7C, 0x126A80, 0x126A84,
                                                      0x126AC4, 0x126B00, 0x126B2C, 0x126B30, 0x126B34]
report = {"retail_sha1": windows["sha1"], "source_sha256": hashlib.sha256(Path("src/promoted/code1_0012.c").read_bytes()).hexdigest(),
          "rectangle_colors": rows, "first_family_complete_direct_stack_census": census,
          "first_family_extents": [[hex(offset), hex(offset + 3)] for offset in (0x67C, 0x680, 0x684, 0x688)],
          "alpha_alias": "sp+0x687 is byte 3 of sp+0x684", "opaque_destination_reused_without_recopy": True,
          "opaque_calls": ["0x126aa4", "0x126acc"],
          "layer_provider": "void func_0045d6e0(u8 *, f32 *, f32, s32)",
          "layer_call_arguments": {"a0": "sp+0x688", "a1": "sp+0x4c0", "f12": 0.0, "a2": 1},
          "layer_provider_prologue_verified": True, "post_rectangle_order": ["0x126b70", "0x126b88", "0x126b90"]}
Path("proof").mkdir(exist_ok=True)
Path("proof/retail-color-storage.json").write_text(json.dumps(report, indent=2) + "\n")
print("Verified 14 four-byte rectangle source/copy pairs, first-family alpha alias, complete direct access census and call order")
