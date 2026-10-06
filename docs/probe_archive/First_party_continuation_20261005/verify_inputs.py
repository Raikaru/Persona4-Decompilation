"""Authenticate the recorded continuation without recompiling old work."""
from collections import Counter
from pathlib import Path
import hashlib
import json
import sys

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / "tools"))
import verify as V


def main():
    receipt = json.loads(Path(__file__).with_name("receipt.json").read_text())
    differences = [relative for relative, digest in receipt["source_sha256"].items()
                   if not (ROOT / relative).is_file()
                   or hashlib.sha256((ROOT / relative).read_bytes()).hexdigest() != digest]
    if differences:
        raise SystemExit("Recorded source changed: " + ", ".join(differences))
    counts = Counter()
    remaining = []
    for path in sorted((ROOT / "src").rglob("*.c")):
        if V.is_generated(path):
            continue
        relative = path.relative_to(ROOT).as_posix()
        for marker in V.scan_markers(path):
            if V.code_origin(relative, marker["addr"]) != "main":
                continue
            counts["ASM" if marker.get("asm") else "MATCH"] += 1
            if marker.get("asm"):
                remaining.append({"address": f'{marker["addr"]:08x}', "name": marker.get("name"),
                                  "file": relative, "guarded_c": bool(marker.get("nonmatching"))})
    assert dict(counts) == receipt["first_party"], counts
    assert remaining == receipt["remaining_first_party"]
    metrics = json.loads((ROOT / "progress/metrics.json").read_text())
    assert metrics["categories"]["main"]["matching_count"] == counts["MATCH"]
    assert metrics["categories"]["main"]["total"] == sum(counts.values())
    assert metrics["status_counts"] == receipt["all_functions"]
    assert metrics["hashes"]["image_sha1"] == receipt["verification"]["motion_relink"]["retail_image_sha1"]
    assert metrics["hashes"]["retail_sha1"] == receipt["verification"]["motion_relink"]["retail_elf_sha1"]
    print("Recorded source hashes:", len(receipt["source_sha256"]))
    print("First-party inventory:", dict(counts), "(source classification; native proof is recorded separately)")
    print("Exact fallback queue and published progress authenticated")


if __name__ == "__main__":
    main()
