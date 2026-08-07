"""Park a candidate body behind #ifdef NON_MATCHING at a bare INCLUDE_ASM marker.

usage: python tools/park.py <spec.json>

<spec.json> is a list of entries:
  {"file": ..., "func": ..., "note": "...", "body": "..."}

For each entry the bare `// FUN_XXXXXXXX` marker line and the INCLUDE_ASM line
below it are replaced by the note comment, a `NONMATCHING`-suffixed marker, and
the guarded body.  Line endings are preserved.  Nothing is written unless every
entry resolves, so a typo cannot leave a file half-edited.
"""

import json
import pathlib
import sys


def main(spec_path):
    spec = json.load(open(spec_path))
    writes = {}
    for e in spec:
        path = pathlib.Path(e["file"])
        raw = writes.get(path, path.read_bytes())
        crlf = b"\r\n" in raw
        text = raw.decode("utf-8", "surrogateescape").replace("\r\n", "\n")
        unit = path.stem
        func = e["func"]
        marker = "// FUN_%s" % func.split("_")[1].upper()
        asm = 'INCLUDE_ASM("asm/nonmatchings/%s", %s);' % (unit, func)
        lines = text.split("\n")
        idx = [k for k, l in enumerate(lines) if l.strip() == marker]
        if len(idx) != 1:
            sys.exit("%s: %s marker count %d" % (path, marker, len(idx)))
        i = idx[0]
        if lines[i + 1].strip() != asm:
            sys.exit("%s: line after %s is not the bare INCLUDE_ASM" % (path, marker))
        block = e["note"].rstrip("\n").split("\n")
        block += [marker + " NONMATCHING", "#ifdef NON_MATCHING"]
        block += e["body"].rstrip("\n").split("\n")
        block += ["#else", asm, "#endif"]
        lines[i : i + 2] = block
        out = "\n".join(lines)
        writes[path] = (out.replace("\n", "\r\n") if crlf else out).encode(
            "utf-8", "surrogateescape"
        )
    for path, data in writes.items():
        path.write_bytes(data)
        print("parked in %s" % path)


if __name__ == "__main__":
    main(sys.argv[1])
