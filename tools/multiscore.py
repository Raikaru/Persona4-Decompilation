#!/usr/bin/env python3
"""Score many candidate bodies for one function with few compiler runs.

    multiscore.py OWNER ADDR CAND [CAND ...] [--chunk N] [--jobs J]

Each candidate is a replacement for the function's guarded region, as for
`fnalign.py --candidate`. Candidates whose text around the function (helpers,
typedefs, pragmas) is identical are compiled together. One translation unit
holds up to N copies of the function, renamed `func_ADDR__vK`, so the owner's
headers are parsed once per chunk instead of once per candidate. Each copy is
cut from the object and aligned against retail exactly as fnalign does.

Output, one line per candidate in input order:
    EDITS  (retail_instrs, object_instrs)  PATH
EDITS is `ERR ...` when the candidate does not compile; a failing chunk is
split until the bad candidates are isolated.
"""
from __future__ import annotations

import argparse
import re
import sys
import tempfile
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import fnalign as F  # noqa: E402
import probe_variants as probe  # noqa: E402
from verify import load_config  # noqa: E402


def split_candidate(text: str, func: str):
    """(prefix, definition, suffix) of a candidate body around FUNC's definition."""
    for m in re.finditer(rf"(?m)^[^\n;{{}}]*\b{re.escape(func)}\s*\(", text):
        brace = text.find("{", m.end())
        semi = text.find(";", m.end())
        if brace < 0 or (0 <= semi < brace):
            continue  # a prototype, not the definition
        depth = 0
        for i in range(brace, len(text)):
            if text[i] == "{":
                depth += 1
            elif text[i] == "}":
                depth -= 1
                if depth == 0:
                    end = i + 1
                    return text[:m.start()], text[m.start():end], text[end:]
    raise ValueError(f"no definition of {func}")


class Scorer:
    def __init__(self, owner: Path, addr: str):
        self.owner = owner.resolve()
        self.func = "func_" + addr.lower()
        self.cfg = load_config()
        target, windows = F._read_json(F.TARGET), F._read_json(F.FUNCTION_WINDOWS)
        retail_elf = F.RetailElf(self.cfg["retail_elf"], target, windows["sha1"])
        address = int(addr, 16)
        boundaries = {int(i, 16) for i in windows["windows"]}
        boundaries.update(int(i, 16) + s for i, s in windows["windows"].items() if s)
        for path in (F.REPO / "src").rglob("*.c"):
            try:
                boundaries.update(m["addr"] for m in F.scan_markers(path))
            except OSError:
                continue
        window = F.window_for(address, sorted(boundaries))
        self.retail_bytes = retail_elf.bytes_at(address, window)
        self.address = address
        self.text = probe._read_text(self.owner)
        self.newline = probe._newline_for(self.owner.read_bytes())
        self.start, self.end = probe.region_for(
            self.text, probe.address_of(self.func, self.owner), self.func)

    def score_object(self, data: bytes, relocations: list) -> tuple[int, int, int]:
        retail = self.retail_bytes
        while len(retail) >= 4 and not any(retail[-4:]) and len(retail) > len(data):
            retail = retail[:-4]
        r, o = F.decode(retail, self.address), F.decode(data, 0)
        relocated = {rel["offset"] // 4 for rel in relocations}
        _, edits, _ = F.align(r, o, relocated)
        return edits, len(r), len(o)

    def compile_group(self, prefix: str, defs: list[str], suffix: str):
        """Compile one TU holding every definition; return per-def results or None."""
        names = [f"{self.func}__v{k}" for k in range(len(defs))]
        body = prefix
        for name, d in zip(names, defs):
            body += re.sub(rf"\b{re.escape(self.func)}\b", name, d) + "\n"
        body += suffix
        body = probe._normalise_candidate(body, self.newline)
        patched = probe.splice_region(self.text, self.start, self.end, body, self.newline)
        with tempfile.TemporaryDirectory(prefix="p4multi_") as directory:
            output = Path(directory) / "out.o"
            with probe.scratch_source(self.owner) as scratch:
                scratch.write_bytes(patched.encode("utf-8", errors="surrogateescape"))
                ok, log = probe._compile_in_context(scratch, self.owner, self.cfg, output)
            if not ok:
                return None, log
            obj = F.ObjectFile(output)
            out = []
            for name in names:
                try:
                    data, relocs = obj.function(name)
                    out.append(self.score_object(data, relocs))
                except KeyError:
                    out.append(None)
            return out, ""

    def score_group(self, prefix, items, suffix, results):
        """items: list of (index, definition). Fills results[index]."""
        got, log = self.compile_group(prefix, [d for _, d in items], suffix)
        if got is not None:
            for (i, _), r in zip(items, got):
                results[i] = r if r is not None else ("ERR symbol missing",)
            return
        if len(items) == 1:
            results[items[0][0]] = ("ERR " + " ".join(log.split())[-200:],)
            return
        half = len(items) // 2
        self.score_group(prefix, items[:half], suffix, results)
        self.score_group(prefix, items[half:], suffix, results)


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0], fromfile_prefix_chars="@")
    ap.add_argument("owner")
    ap.add_argument("addr")
    ap.add_argument("candidates", nargs="+")
    ap.add_argument("--chunk", type=int, default=64)
    ap.add_argument("--jobs", type=int, default=1,
                    help="parallel chunks; probe_variants serialises compiles per owner")
    args = ap.parse_args()
    scorer = Scorer(Path(args.owner), args.addr)
    texts = [Path(c).read_text(encoding="utf-8", errors="surrogateescape") for c in args.candidates]
    results: list = [None] * len(texts)
    groups: dict = {}
    for i, t in enumerate(texts):
        t = t.replace("\r\n", "\n")
        try:
            pre, d, suf = split_candidate(t, scorer.func)
        except ValueError as e:
            results[i] = (f"ERR {e}",)
            continue
        groups.setdefault((pre, suf), []).append((i, d))
    work = []
    for (pre, suf), items in groups.items():
        for k in range(0, len(items), args.chunk):
            work.append((pre, items[k:k + args.chunk], suf))
    with ThreadPoolExecutor(max(1, args.jobs)) as pool:
        list(pool.map(lambda w: scorer.score_group(w[0], w[1], w[2], results), work))
    for path, r in zip(args.candidates, results):
        if r is None or isinstance(r[0], str):
            print(f"{(r or ('ERR',))[0]}  ()  {path}")
        else:
            print(f"{r[0]:>6}  ('{r[1]}', '{r[2]}')  {path}")


if __name__ == "__main__":
    main()
