"""Verify the two repaired layer calls and both four-byte candidate copies."""
from pathlib import Path
import hashlib
import json
import struct

ROOT = Path("proof/title-color-owner")
record = json.loads((ROOT / "after-guard.json").read_text())
assert record["source_sha256"] == hashlib.sha256(Path("src/promoted/code1_0012.c").read_bytes()).hexdigest()
target = record["functions"]["func_001265a0"]
body = bytes.fromhex(target["bytes"])


def word(offset):
    return struct.unpack_from("<I", body, offset)[0]


def setup(call):
    gpr, fpr = {0: 0, 29: ("sp", 0)}, {}
    for pos in range(call - 40, call, 4):
        instruction = word(pos)
        op, rs, rt = instruction >> 26, (instruction >> 21) & 31, (instruction >> 16) & 31
        imm = instruction & 65535
        signed = imm - 65536 if imm & 32768 else imm
        if op == 9:
            base = gpr.get(rs)
            gpr[rt] = ("sp", base[1] + signed) if isinstance(base, tuple) else base + signed if isinstance(base, int) else None
        elif op == 17 and rs == 4:
            fpr[(instruction >> 11) & 31] = gpr.get(rt)
        elif op == 15:
            gpr[rt] = imm << 16
        elif op in (30, 32, 33, 35, 36, 37, 39, 55):
            gpr[rt] = None
        elif op == 3:
            # No argument value survives a prior opaque call by assumption.
            gpr, fpr = {0: 0, 29: ("sp", 0)}, {}
    assert word(call + 4) == 0
    return gpr, fpr


layers = [r["offset"] for r in target["relocations"] if r["symbol"] == "func_0045d6e0"]
assert len(layers) == 30
rows = []
for call in layers[2:4]:
    gpr, fpr = setup(call)
    assert gpr.get(4) == ("sp", 0x4B8) and gpr.get(5) == ("sp", 0x3A0)
    assert gpr.get(6) == 1 and fpr.get(12) == 0
    rows.append({"target_relative_call_offset": hex(call), "a0": "sp+0x4b8", "a1": "sp+0x3a0", "a2": 1, "f12_bits": "00000000"})
for pos in range(layers[2] + 8, layers[3], 4):
    instruction = word(pos)
    # No direct store overlaps the copied layer color between its two calls.
    width = {0x1F: 16, 0x28: 1, 0x29: 2, 0x2B: 4, 0x39: 4, 0x3F: 8}.get(instruction >> 26)
    offset = instruction & 65535
    assert not (width and ((instruction >> 21) & 31) == 29 and offset < 0x4BC and offset + width > 0x4B8)
# Complete measured clear loops: byte stores, +1 advancement, four bytes.
for start, source in ((1052, 0x4B4), (1224, 0x4AC)):
    expected = [0x27A30000 | source, 0x24020004, 0x10600008, 0,
                0xA0600000, 0x24630001, 0x2442FFFF, 0, 0, 0x1440FFFA, 0]
    assert [word(start + i * 4) for i in range(len(expected))] == expected
assert word(1100) == 0xA3A204B7  # alpha is byte 3 of the first source
for offset, source, destination in ((1108, 0x4B4, 0x4B8), (1272, 0x4AC, 0x4B0)):
    assert word(offset) == 0xC7A00000 | source
    assert word(offset + 4) == 0xE7A00000 | destination
report = {"source_sha256": record["source_sha256"], "target_bytes": target["size"],
          "frame_bytes": -((word(0) & 65535) - 65536), "layer_call_arguments": rows,
          "four_byte_clear_loops_verified": 2, "raw_four_byte_copies_verified": 2,
          "layer_alpha_byte_offset": 3, "no_color_recopy_between_layer_calls": True}
Path("proof/candidate-color-storage.json").write_text(json.dumps(report, indent=2) + "\n")
print("Verified candidate four-byte clears/copies and both canonical layer argument transports")
