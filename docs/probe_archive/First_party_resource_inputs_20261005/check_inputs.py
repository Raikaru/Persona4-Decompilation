"""Authenticate the recorded source and optional retail witnesses without compiling."""
from pathlib import Path
import argparse
import hashlib
import json
import sys

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--retail", action="store_true")
    args = parser.parse_args()
    record = json.loads((HERE / "receipt.json").read_text(encoding="utf-8"))
    for relative, expected in record["source_sha256"].items():
        path = (ROOT / relative).resolve()
        if not path.is_relative_to(ROOT) or not path.is_file() or digest(path) != expected:
            raise SystemExit("Recorded source changed: " + relative)
    print("Authenticated source inputs:", len(record["source_sha256"]))
    if not args.retail:
        return
    sys.path.insert(0, str(ROOT / "tools"))
    import verify as V
    cfg = V.load_config()
    retail = V.RetailElf(cfg["retail_elf"], V._read_json(V.TARGET), record["retail_sha1"])
    for row in record["retail_strings"]:
        expected = row["text"].encode("ascii") + b"\0"
        if retail.bytes_at(int(row["address"], 16), len(expected)) != expected:
            raise SystemExit("Retail string changed: " + row["address"])
    for row in record["instruction_witnesses"]:
        raw = retail.bytes_at(int(row["address"], 16), 4)
        if raw.hex() != row["bytes_le"]:
            raise SystemExit("Retail instruction changed: " + row["address"])
    print("Authenticated retail strings/instructions:", len(record["retail_strings"]), len(record["instruction_witnesses"]))
    print("Required resource payloads remain separate inputs.")


if __name__ == "__main__":
    main()
