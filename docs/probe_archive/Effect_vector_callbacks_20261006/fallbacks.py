"""Reproduce missing fallback listings from tracked recipes and the retail ELF.

Existing listings are optional authenticated caches. A clean checkout generates
only the eleven listings needed by these owners into private scratch, using the
repository's pinned splitter and official render function. Nothing is installed
under the production asm directory.
"""
import hashlib
import json
from pathlib import Path
import shutil
import subprocess
import sys

import proof as H

ROOT = Path(__file__).resolve().parents[3]


def authenticate(receipt):
    manifest = json.loads((ROOT / "config/generated_asm.json").read_text(encoding="utf-8"))
    entries = {entry["path"]: entry for entry in manifest["generated"]}
    selected = []
    for relative, expected in receipt["generated_assembly"].items():
        H.require(relative in entries and entries[relative]["sha256"] == expected,
                  f"Fallback recipe changed: {relative}")
        path = ROOT / relative
        if path.exists():
            H.require(path.is_file() and H.sha(path.read_bytes()) == expected,
                      f"Existing generated fallback differs: {relative}")
        selected.append(entries[relative])
    return manifest, selected


def prepare(receipt, retail, work, force=False):
    manifest, selected = authenticate(receipt)
    if not force and all((ROOT / entry["path"]).is_file() for entry in selected):
        return ROOT
    # The renderer imports only tracked scripts. Its package/version check and
    # its own manifest checks remain in force for a fresh split.
    import regenerate_asm as G
    G.check_inputs(ROOT, manifest)
    scratch = work / "fallback-split"
    scratch.mkdir(parents=True, exist_ok=False)
    (scratch / "config").mkdir()
    shutil.copyfile(ROOT / "config/slus21782.yaml", scratch / "config/slus21782.yaml")
    shutil.copyfile(ROOT / "config/asm_symbol_baseline.txt", scratch / "config/symbol_addrs.txt")
    target = H.V._read_json(H.V.TARGET)
    image = retail.bytes_at(int(target["elf"]["load_vram"], 16), int(target["elf"]["load_size"], 16))
    H.require(hashlib.sha1(image).hexdigest() == target["image"]["sha1"], "Retail image identity differs")
    (scratch / "image.bin").write_bytes(image)
    process = subprocess.run([sys.executable, "-m", "splat", "split", "config/slus21782.yaml"],
                             cwd=scratch, text=True, capture_output=True)
    (scratch / "split.log").write_text(process.stdout + process.stderr, encoding="utf-8", newline="\n")
    H.require(process.returncode == 0, "Fresh fallback split failed; inspect fallback-split/split.log")
    index = G.SplitIndex(scratch / "asm")
    windows = H.V._read_json(H.V.FUNCTION_WINDOWS)["windows"]
    names = G.canonical_names(ROOT, windows)
    output_root = work / "fallback-root"
    for entry in selected:
        raw = G.render(entry, index, retail, windows, names)
        H.require(H.sha(raw) == receipt["generated_assembly"][entry["path"]], "Regenerated fallback hash differs")
        destination = output_root / entry["path"]
        destination.parent.mkdir(parents=True, exist_ok=True)
        with destination.open("xb") as stream:
            stream.write(raw)
    print(f"Authenticated {len(selected)} privately regenerated fallback listings", flush=True)
    return output_root
