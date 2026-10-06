"""Capture one actual owner's compiler stages, rejecting instrumentation drift.

Private diagnostic only: no source, project configuration or cache is changed.
The direct and debug compiles use exactly the same arguments and output path.
"""
from __future__ import annotations

import argparse
from collections import Counter
import hashlib
import importlib.util
import json
from pathlib import Path
import subprocess
import sys
import time

ROOT = Path(__file__).resolve().parents[3]
TOOL = ROOT / "build/finish94-20261005/mwccps2-debugger"
sys.path.insert(0, str(ROOT / "tools"))
import verify as V


def sha(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("owner")
    parser.add_argument("function")
    parser.add_argument("label")
    parser.add_argument("--guarded", action="store_true")
    args = parser.parse_args()
    if not args.label.replace("-", "").isalnum():
        raise SystemExit("Use an alphanumeric/hyphen label")
    source = (ROOT / args.owner).resolve(strict=True)
    source.relative_to(ROOT / "build/finish-20261006/after-worker7")
    logical = ROOT / "src/Graphics/Effect/eff_after.c"
    output = ROOT / "build/finish-20261006/after-worker7/captures" / args.label
    cfg = V.load_config()
    compiler = Path(V.unit_compiler(logical, cfg))
    gdb = Path("C:/msys64/mingw64/bin/gdb.exe")
    assert gdb.is_file()
    spec = importlib.util.spec_from_file_location("capture_driver", TOOL / "mwccps2_debugger.py")
    driver = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(driver)
    # The current human launcher accepts schema 2 only; b210's checked-in live
    # profile is schema 1 and belongs to the existing b210 snapshot command.
    # Select it by its full fingerprint rather than altering any binary layout.
    profile = TOOL / "profiles/mwcps2-3.0.1-b210.json"
    schema = json.loads(profile.read_text(encoding="utf-8"))
    assert schema["schema_version"] == 1
    assert sha(compiler) == schema["binary"]["sha256"]
    assert compiler.stat().st_size == schema["binary"]["size"]
    if output.exists():
        assert not any(output.iterdir()), "Existing capture contains evidence; use a new label"
    else:
        output.mkdir(parents=True)
    inputs = {args.owner: sha(source)}
    inputs.update({p.relative_to(ROOT).as_posix(): sha(p) for p in (ROOT / "include").rglob("*.h")})
    native = output / "native.o"
    flags = V.unit_compile_flags(logical, cfg["compile_flags"])
    if args.guarded:
        flags += ["-DNON_MATCHING"]
    command_args = [*flags, "-c", str(source), "-o", str(native)]
    started = time.monotonic()
    direct = subprocess.run([str(compiler), *command_args], cwd=ROOT,
                            stdout=subprocess.PIPE, stderr=subprocess.STDOUT, timeout=120)
    (output / "direct.log").write_bytes(direct.stdout)
    assert direct.returncode == 0 and native.is_file(), direct.stdout.decode(errors="replace")
    raw = native.read_bytes()
    (output / "direct.o").write_bytes(raw)
    quote = driver._quote
    capture = output / "capture"
    lines = ["set pagination off", "set confirm off", "set breakpoint pending on",
             "file " + quote(str(compiler.resolve())),
             "set args " + " ".join(quote(arg) for arg in command_args),
             "starti", "source " + str(TOOL / "gdb/mwccps2_b210_snapshot.py").replace("\\", "/"),
             "b210-snapshot start --profile " + quote(str(profile)) + " --output " + quote(str(capture)),
             "continue", "b210-snapshot stop", "quit", ""]
    commands = output / "capture.gdb"
    commands.write_text("\n".join(lines), encoding="utf-8", newline="\n")
    with (output / "gdb.log").open("wb") as log:
        result = subprocess.run([str(gdb), "--batch", "--nx", "--quiet", "--command", str(commands)],
                                cwd=ROOT, stdout=log, stderr=subprocess.STDOUT, timeout=600)
    manifest_file = output / "capture/snapshot-manifest.json"
    manifest = json.loads(manifest_file.read_text()) if manifest_file.exists() else {}
    drift = [name for name, digest in inputs.items() if sha(ROOT / name) != digest]
    record = {
        "owner": args.owner, "function": args.function,
        "source_sha256": inputs[args.owner], "input_sha256": inputs,
        "compiler_sha256": sha(compiler), "gdb_sha256": sha(gdb),
        "debugger_commit": subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=TOOL, text=True).strip(),
        "profile_sha256": sha(profile), "compiler_flags": flags,
        "direct_exit_code": direct.returncode, "gdb_exit_code": result.returncode,
        "direct_object_sha256": hashlib.sha256(raw).hexdigest(),
        "captured_object_sha256": sha(native) if native.exists() else None,
        "whole_object_identical": native.exists() and native.read_bytes() == raw,
        "source_drift": drift,
        "capture_scope": "All generated functions of the unchanged complete owner; requested function is the analysis target",
        "capture_status_counts": dict(Counter(a.get("capture_status") for a in manifest.get("stages", []))),
        "capture_errors": [a for a in manifest.get("stages", []) if a.get("capture_status") == "instrumentation_error"],
        "artifacts": dict(Counter(a.get("stage", "unknown") for a in manifest.get("stages", []))),
        "seconds": round(time.monotonic() - started, 3),
    }
    (output / "receipt.json").write_text(json.dumps(record, indent=2) + "\n", encoding="utf-8", newline="\n")
    print(json.dumps({k:v for k,v in record.items() if k != "input_sha256"}, indent=2), flush=True)
    assert result.returncode == 0 and manifest and not record["capture_errors"], "Inspect gdb.log and capture manifest"
    assert record["whole_object_identical"] and not drift, "Instrumented object or source changed"


if __name__ == "__main__":
    main()
