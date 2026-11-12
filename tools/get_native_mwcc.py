#!/usr/bin/env python3
"""Install the native b210 (from mweppc's release) to tools/mwccps2-native/mwccps2.

    python3 tools/get_native_mwcc.py [--archive FILE] [--force]

Enable it with P4_MWCC_NATIVE=1. --archive installs a local tarball.
"""
from __future__ import annotations

import argparse
import hashlib
import io
import os
import platform
import sys
import tarfile
import urllib.request
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
DEST = REPO / "tools" / "mwccps2-native" / "mwccps2"

RELEASE_URL = "https://github.com/sozud/mweppc/releases/download/mwccps2-v1.0.0"
SHA256 = {
    "mwccps2-native64-linux-amd64.tar.gz": "c16e3b23999fee2be7374e487813534b8408c3b74b8cbe58559647d23a0ed476",
    "mwccps2-native64-darwin-arm64.tar.gz": "4135deb8b88d634de43f2ce67ce15db99631e257d3315a299012d5675a0cb289",
    "mwccps2-native64-darwin-amd64.tar.gz": "a00c0f6cf743bf7d27c532831948bffdbaad9624c094fbd878d1118cef264a2c",
}


def asset_name() -> str:
    system = platform.system()
    machine = platform.machine().lower()
    arch = {"x86_64": "amd64", "amd64": "amd64", "arm64": "arm64", "aarch64": "arm64"}.get(machine)
    os_name = {"Linux": "linux", "Darwin": "darwin"}.get(system)
    name = f"mwccps2-native64-{os_name}-{arch}.tar.gz"
    if name not in SHA256:
        sys.exit(f"get_native_mwcc: no native mwccps2 build for {system} {machine}; "
                 f"use the original compiler (P4_MWCC_NATIVE=0)")
    return name


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--archive", type=Path, help="install this release tarball instead of downloading it")
    ap.add_argument("--force", action="store_true", help="replace an installed compiler")
    a = ap.parse_args()

    if DEST.is_file() and not a.force:
        print(f"{DEST.relative_to(REPO)} is already installed (--force to replace it)")
        return
    name = asset_name()
    if a.archive:
        data = a.archive.read_bytes()
    else:
        url = f"{os.environ.get('P4_MWCC_NATIVE_URL', RELEASE_URL)}/{name}"
        print(f"downloading {url}")
        with urllib.request.urlopen(url, timeout=120) as r:
            data = r.read()
    digest = hashlib.sha256(data).hexdigest()
    if SHA256[name] is not None and digest != SHA256[name]:
        sys.exit(f"get_native_mwcc: {name} has SHA-256 {digest}, expected {SHA256[name]}")
    if SHA256[name] is None:
        print(f"warning: no SHA-256 pinned for {name} (got {digest})")

    stem = name[: -len(".tar.gz")]
    with tarfile.open(fileobj=io.BytesIO(data), mode="r:gz") as tar:
        member = next((m for m in tar.getmembers() if m.isfile() and Path(m.name).name == stem), None)
        if member is None:
            sys.exit(f"get_native_mwcc: {name} does not contain {stem}")
        blob = tar.extractfile(member).read()
    DEST.parent.mkdir(parents=True, exist_ok=True)
    tmp = DEST.with_suffix(".tmp")
    tmp.write_bytes(blob)
    tmp.chmod(0o755)
    tmp.replace(DEST)
    print(f"installed {DEST.relative_to(REPO)}; enable it with P4_MWCC_NATIVE=1")


if __name__ == "__main__":
    main()
