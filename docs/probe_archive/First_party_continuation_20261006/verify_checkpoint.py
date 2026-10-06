"""Authenticate the October 6 checkpoint without modifying or rebuilding it."""
from pathlib import Path
import hashlib
import json
import sys

ROOT = Path(__file__).resolve().parents[3]
ARCHIVE = Path(__file__).resolve().parent
sys.path.insert(0, str(ROOT / "tools"))
import verify as V


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def load(path):
    return json.loads(path.read_text(encoding="utf-8"))


def main():
    checkpoint = load(ARCHIVE / "checkpoint.json")
    inputs = load(ARCHIVE / "source-inputs.json")
    remaining = load(ARCHIVE / "remaining.json")
    errors = []
    for name, expected in checkpoint["archive_sha256"].items():
        path = ARCHIVE / name
        if not path.is_file() or digest(path) != expected:
            errors.append(f"archive differs: {name}")
    for name, expected in inputs.items():
        path = ROOT / name
        if not path.is_file() or digest(path) != expected:
            errors.append(f"input differs: {name}")
    assert len(inputs) == 1922
    assert len(remaining) == 88
    owners = {row["owner"] for row in remaining}
    markers = {owner: {f"{m['addr']:08x}": m for m in V.scan_markers(ROOT / owner)}
               for owner in owners if (ROOT / owner).is_file()}
    for row in remaining:
        marker = markers.get(row["owner"], {}).get(row["address"])
        if not marker or not marker.get("asm") or marker["name"] != row["name"]:
            errors.append(f"remaining marker differs: {row['address']} in {row['owner']}")
        if row["source_sha256"] != inputs[row["owner"]]:
            errors.append(f"remaining owner hash differs: {row['owner']}")
    # Build reports are intentionally private. Verify any that remain available
    # without requiring a binary artifact or an ignored directory after clone.
    available = []
    for name, expected in checkpoint["private_artifact_sha256"].items():
        path = ROOT / name
        if path.is_file():
            available.append(name)
            if digest(path) != expected:
                errors.append(f"private evidence differs: {name}")
    result = {"input_count": len(inputs), "remaining_first_party_ASM": len(remaining),
              "available_private_artifacts_checked": len(available), "errors": errors}
    print(json.dumps(result, indent=2))
    if errors:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
