#!/usr/bin/env python3
"""Install the project-pinned m2c revision into tools/vendor/m2c."""
from __future__ import annotations

import argparse
import io
import shutil
import tempfile
import urllib.request
import zipfile
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
M2C_REVISION = "94098d4de68c2fcc13fb8cf1096a1520eb171abe"
M2C_ARCHIVE = f"https://github.com/matt-kempster/m2c/archive/{M2C_REVISION}.zip"


def install(destination: Path) -> None:
    revision_file = destination / ".m2c-revision"
    if revision_file.is_file() and revision_file.read_text().strip() == M2C_REVISION:
        print(f"m2c {M2C_REVISION} already installed at {destination}")
        return

    print(f"downloading m2c {M2C_REVISION}")
    with urllib.request.urlopen(M2C_ARCHIVE) as response:
        archive = zipfile.ZipFile(io.BytesIO(response.read()))

    with tempfile.TemporaryDirectory(dir=destination.parent) as temporary:
        staging = Path(temporary) / "m2c"
        staging.mkdir()
        for member in archive.infolist():
            parts = Path(member.filename).parts
            if len(parts) < 2 or member.is_dir():
                continue
            relative = Path(*parts[1:])
            if ".." in relative.parts:
                raise RuntimeError(f"unsafe archive member: {member.filename}")
            output = staging / relative
            output.parent.mkdir(parents=True, exist_ok=True)
            with archive.open(member) as source, output.open("wb") as target:
                shutil.copyfileobj(source, target)
        (staging / ".m2c-revision").write_text(M2C_REVISION + "\n")
        if destination.exists():
            shutil.rmtree(destination)
        shutil.move(str(staging), destination)

    print(f"installed m2c at {destination}")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "--destination",
        type=Path,
        default=REPO / "tools" / "vendor" / "m2c",
    )
    args = parser.parse_args()
    args.destination.parent.mkdir(parents=True, exist_ok=True)
    install(args.destination.resolve())


if __name__ == "__main__":
    main()
