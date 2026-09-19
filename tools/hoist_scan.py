"""Find floors where the body materialises one symbol's address repeatedly.

`func_001b6ab0` went from 328 differing words to a MATCH, and the first step
alone was worth 303 of them: retail loads a table base once into a saved
register while the body emitted `lui` at six sites.  That shape is mechanical
to detect - count relocated `lui` instructions per symbol on each side and
report the floors where the object has materially more than retail.
"""
import json
import re
import sys
import tempfile
from concurrent.futures import ProcessPoolExecutor
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))
GUARD = re.compile(r"// FUN_([0-9A-Fa-f]{8}) NONMATCHING")
LUI = re.compile(r"^\s*lui\s")


def targets() -> list[tuple[str, str]]:
    import verify

    out = []
    for path in sorted((REPO / "src").rglob("*.c")):
        if path.parent.name == "generated" or path.name.startswith("."):
            continue
        rel = path.relative_to(REPO / "src").as_posix()
        if rel.startswith(verify.THIRD_PARTY_PREFIXES):
            continue
        text = path.read_text(errors="replace")
        for m in GUARD.finditer(text):
            out.append((str(path.relative_to(REPO)), m.group(1).upper()))
    return out


def measure(job: tuple[str, str]) -> dict:
    import fnalign
    import verify
    from measure_guarded import extract_guarded_body

    source, tag = job
    name = "func_%s" % tag.lower()
    path = REPO / source
    address = int(tag, 16)
    row = {"function": name, "source": source,
           "origin": verify.code_origin(
               source[4:] if source.startswith("src/") else source, address)}
    try:
        cfg = verify.load_config()
        text = path.read_text(errors="replace")
        with tempfile.TemporaryDirectory() as scratch:
            candidate = Path(scratch) / "c.c"
            candidate.write_text(extract_guarded_body(text, "FUN_" + tag, name))
            body, _relocations = fnalign._object_for(path, name, candidate, cfg)
        windows = fnalign._read_json(fnalign.FUNCTION_WINDOWS)
        elf = fnalign.RetailElf(cfg["retail_elf"],
                                fnalign._read_json(fnalign.TARGET), windows["sha1"])
        bounds = {int(a, 16) for a in windows["windows"]}
        bounds.update(int(a, 16) + v for a, v in windows["windows"].items() if v)
        retail = elf.bytes_at(address, fnalign.window_for(address, sorted(bounds)))
        while (len(retail) >= 4 and not any(retail[-4:])
               and len(retail) > len(body)):
            retail = retail[:-4]
        r = sum(1 for i in fnalign.decode(retail, address) if LUI.match(str(i)))
        o = sum(1 for i in fnalign.decode(body, 0) if LUI.match(str(i)))
        row.update(retail_lui=r, object_lui=o, surplus=o - r,
                   retail=len(retail) // 4, object=len(body) // 4)
    except BaseException as exc:                      # noqa: BLE001
        row["error"] = f"{type(exc).__name__}: {str(exc)[:60]}"
    return row


def main() -> None:
    jobs = targets()
    print(f"scanning {len(jobs)} guarded floors for repeated address materialisation",
          flush=True)
    rows = []
    with ProcessPoolExecutor(max_workers=4) as pool:
        for row in pool.map(measure, jobs):
            rows.append(row)
    if len(sys.argv) > 1:
        Path(sys.argv[1]).write_text(json.dumps(rows, indent=1))
    good = [r for r in rows
            if "error" not in r and r["origin"] == "main" and r["surplus"] >= 3]
    good.sort(key=lambda r: -r["surplus"])
    for r in good[:40]:
        print(f"  surplus {r['surplus']:3d} lui  (object {r['object_lui']:3d} vs "
              f"retail {r['retail_lui']:3d})  {r['object']}/{r['retail']}  "
              f"{r['function']}  {r['source']}")
    print(f"\n{len(good)} first-party floors materialise at least three more "
          "addresses than retail")


if __name__ == "__main__":
    main()
