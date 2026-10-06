"""Verify the installed Fcl scope change and its unresolved native residual."""
from pathlib import Path
import argparse
import hashlib
import importlib.util
import json
import sys
import tempfile

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(ROOT / "tools"))
import verify as V
import probe_variants as P


def load(relative, name):
    spec = importlib.util.spec_from_file_location(name, ROOT / relative)
    result = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(result)
    return result


def validate(record, directory, output):
    shared = load("docs/probe_archive/Field_guard_cleanup_0016bdd0_20261005/replay.py", "fcl_preservation")
    default = directory / "src_Event_Fcl_y_fclCombineDraw.c.o"
    guarded_path = directory / "y_fclCombineDraw-guarded.o"
    shared.validate(record, default, guarded_path, output)
    core = load("docs/probe_archive/YDraw_update_002b6ec0_20261005/proof_core.py", "fcl_references")
    obj = V.ObjectFile(guarded_path)
    cfg = V.load_config()
    retail = V.RetailElf(cfg["retail_elf"], V._read_json(V.TARGET), record["retail_sha1"])
    target = retail.bytes_at(int(record["address"], 16), record["retail_window_bytes"])
    gp, symbols = core.globals_table()
    bases = {}
    for symbol in obj.symbols:
        if not 0 < symbol["shndx"] < len(obj.sections):
            continue
        address = V.resolve_symbol(symbol["name"], gp, symbols)
        if address is not None:
            base = address - symbol["value"]
            assert symbol["shndx"] not in bases or bases[symbol["shndx"]] == base
            bases[symbol["shndx"]] = base
    resolved, references, differences = core.resolve_function(obj, record["target"], target, bases)
    assert len(differences) == record["resolved_differing_words"] == 29
    assert all(row["target_bits_equal"] for row in references)
    assert len(references) == record["target_relocation_count"] == 57
    assert hashlib.sha256(resolved).hexdigest() == record["resolved_target_sha256"]
    assert len(resolved) <= len(target) and not any(target[len(resolved):])
    print("Fcl target:", len(resolved), "bytes;", len(differences), "resolved differing words; all references verified")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    mode = parser.add_mutually_exclusive_group(required=True)
    mode.add_argument("--hashes-only", action="store_true")
    mode.add_argument("--objects", type=Path)
    mode.add_argument("--output", type=Path)
    args = parser.parse_args()
    record = json.loads((HERE / "receipt.json").read_text(encoding="utf-8"))
    for relative, expected in record["inputs"].items():
        path = (ROOT / relative).resolve()
        if not path.is_relative_to(ROOT) or not path.is_file() or hashlib.sha256(path.read_bytes()).hexdigest() != expected:
            raise SystemExit("Recorded input changed: " + relative)
    print("Authenticated inputs:", len(record["inputs"]))
    if args.hashes_only:
        return
    if args.objects:
        with tempfile.TemporaryDirectory(prefix="fcl-scope-proof-", dir=ROOT / "build") as temporary:
            validate(record, args.objects.resolve(), Path(temporary))
        return
    directory = args.output.resolve()
    if not directory.is_relative_to((ROOT / "build").resolve()):
        raise SystemExit("Replay output must be inside this repository's build directory")
    directory.mkdir(parents=True, exist_ok=False)
    cfg = V.load_config()
    owner = ROOT / record["owner"]
    guarded = dict(cfg, compile_flags=[*cfg["compile_flags"], "-DNON_MATCHING"])
    for label, profile, filename in (("default", cfg, "src_Event_Fcl_y_fclCombineDraw.c.o"),
                                      ("guarded", guarded, "y_fclCombineDraw-guarded.o")):
        ok, log = P._compile_in_context(owner, owner, profile, directory / filename)
        (directory / (label + ".log")).write_text(log, encoding="utf-8")
        assert ok, log
    validate(record, directory, directory)


if __name__ == "__main__":
    main()
