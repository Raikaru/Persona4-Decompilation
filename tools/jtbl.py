"""Decode a MIPS switch jump table out of the retail image.

    python tools/jtbl.py 0x007466C0 6
    python tools/jtbl.py 0x007466C0 6 --func 0x00122720

Reading the table is the only way to recover a switch's real case order.
`verify.py` masks relocation-owned bytes, so a body can look byte-exact while
its `.rodata` table is permuted; and a decompiler that never resolved the
table prints an if-chain in whatever order it guessed.

With `--func`, each target is also reported as a byte offset from that
function's entry, which is what you need to line the entries up against a
disassembly listing.
"""
import struct
import sys
from pathlib import Path

LOAD_OFF = 0x80
LOAD_VRAM = 0x00100000
IMAGE = Path("orig/SLUS_217.82")


def read_words(image: bytes, addr: int, count: int) -> list[int]:
    off = LOAD_OFF + (addr - LOAD_VRAM)
    if off < 0 or off + count * 4 > len(image):
        raise SystemExit(f"0x{addr:08x} is outside the load image")
    return list(struct.unpack(f"<{count}I", image[off:off + count * 4]))


def main() -> None:
    args = [a for a in sys.argv[1:] if not a.startswith("--")]
    if len(args) < 2:
        raise SystemExit(__doc__)
    table, count = int(args[0], 0), int(args[1], 0)
    func = None
    for i, a in enumerate(sys.argv):
        if a == "--func":
            func = int(sys.argv[i + 1], 0)

    image = IMAGE.read_bytes()
    entries = read_words(image, table, count)

    # Group the cases that share a target: that grouping IS the source's
    # fallthrough structure, and the distinct targets in ascending address
    # order are the order the case bodies appear in the object.
    by_target: dict[int, list[int]] = {}
    for case, target in enumerate(entries):
        by_target.setdefault(target, []).append(case)

    print(f"jump table 0x{table:08x}, {count} entries")
    for case, target in enumerate(entries):
        rel = f"  (+0x{target - func:x})" if func is not None else ""
        print(f"  case {case}: 0x{target:08x}{rel}")
    print("\ndistinct targets in object order:")
    for target in sorted(by_target):
        cases = ", ".join(str(c) for c in by_target[target])
        rel = f"  (+0x{target - func:x})" if func is not None else ""
        print(f"  0x{target:08x}{rel}  <- case {cases}")


if __name__ == "__main__":
    main()
