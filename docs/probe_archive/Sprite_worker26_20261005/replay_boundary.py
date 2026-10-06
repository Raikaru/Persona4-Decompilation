"""Authenticate the boundary text proof or build and run its wasm32 fixture.

--hashes-only reads the installed owner and archive without compiling.
--compile requires clang with wasm32 support and node, and writes a new private
build directory. It never rebuilds the matching owner or modifies production.
"""
from pathlib import Path
import argparse
import hashlib
import json
import shutil
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[3]
ARCHIVE = Path(__file__).resolve().parent


def sha(data):
    return hashlib.sha256(data).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    mode = parser.add_mutually_exclusive_group(required=True)
    mode.add_argument("--hashes-only", action="store_true")
    mode.add_argument("--compile", action="store_true")
    parser.add_argument("--clang", default="clang")
    parser.add_argument("--node", default="node")
    args = parser.parse_args()
    receipt = json.loads((ARCHIVE / "receipt.json").read_text())
    boundary = receipt["boundary_validation"]
    owner = ROOT / receipt["owner"]
    assert sha(owner.read_bytes()) == receipt["installation"]["source_after_sha256"]
    fixture = ARCHIVE / "boundary_fixture.c"
    runner = ARCHIVE / "boundary_run.mjs"
    assert sha(fixture.read_bytes()) == boundary["extraction"]["fixture_sha256"]
    assert sha(runner.read_bytes()) == boundary["execution"]["runner_sha256"]
    source = owner.read_text()
    start = source.index("static inline f32 sdkSpriteRight(")
    end = source.index("/* Keep byte-color arithmetic", start)
    helpers = source[start:end]
    assert sha(helpers.encode()) == boundary["extraction"]["current_helpers_sha256"]
    code = fixture.read_text()
    previous = code.split("#if BOUNDARY_OLD\n", 1)[1].split("#else\n", 1)[0]
    current = code.split("#else\n", 1)[1].split("#endif\n", 1)[0]
    assert helpers == current
    assert sha(previous.encode()) == boundary["extraction"]["previous_helpers_sha256"]
    if args.hashes_only:
        print("PASS: installed owner and unmodified current/previous helpers, fixture and runner; no compilation")
        return
    parent = ROOT / "build/resume-cos20999/sprite"
    parent.mkdir(parents=True, exist_ok=True)
    output = Path(tempfile.mkdtemp(prefix="boundary-replay-", dir=parent))
    shutil.copyfile(fixture, output / "fixture.c")
    shutil.copyfile(runner, output / "run.mjs")
    compiled = json.loads(json.dumps(boundary["compilation"]))
    compiled["compiler_version"] = subprocess.check_output([args.clang, "--version"], text=True)
    for profile in compiled["profiles"]:
        binary = output / (profile["name"] + ".wasm")
        command = [args.clang, *compiled["flags"], "-D" + profile["define"],
                   str(output / "fixture.c"), "-o", str(binary)]
        result = subprocess.run(command, text=True, capture_output=True, check=True)
        profile.update(wasm_sha256=sha(binary.read_bytes()), bytes=binary.stat().st_size,
                       stdout=result.stdout, stderr=result.stderr)
    (output / "compile.json").write_text(json.dumps(compiled, indent=2) + "\n")
    subprocess.run([args.node, str(output / "run.mjs")], check=True)
    assert sha(owner.read_bytes()) == receipt["installation"]["source_after_sha256"]
    print("Boundary execution:", output.relative_to(ROOT).as_posix())


if __name__ == "__main__":
    main()
