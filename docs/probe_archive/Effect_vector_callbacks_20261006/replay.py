#!/usr/bin/env python3
"""Authenticate and replay the eight explicit vector callback forwards.

The current owners may be either the exact held proposal inputs or the exact
installed outputs. Both sources are reconstructed in private scratch. Default
operation compiles fresh full owners; --reuse-dir authenticates previously
completed source/object pairs and never invokes a compiler. No production
source, configuration, shared report, or Git state is written.
"""
import argparse
from collections import Counter
import json
from pathlib import Path
import struct
import subprocess
import sys
import tempfile

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
import proof as H
import fallbacks as A


def write_new(path, data):
    path.parent.mkdir(parents=True, exist_ok=True)
    require_new = data.encode("utf-8") if isinstance(data, str) else data
    with path.open("xb") as stream:
        stream.write(require_new)


def save(path, value):
    write_new(path, json.dumps(value, indent=2) + "\n")


def checked_path(root, relative):
    path = Path(relative)
    H.require(not path.is_absolute() and ".." not in path.parts,
              f"Nonportable receipt path: {relative}")
    resolved = (root / path).resolve()
    H.require(resolved.is_relative_to(root.resolve()), f"Path escapes input root: {relative}")
    return resolved


def authenticate_files(receipt):
    for root, group in ((ROOT, "tracked_inputs"), (HERE, "archive_inputs")):
        for relative, expected in receipt[group].items():
            path = checked_path(root, relative)
            H.require(path.is_file() and H.sha(path.read_bytes()) == expected,
                      f"Input changed: {relative}")


def transform(raw, edits, reverse=False):
    text = raw.decode("utf-8")
    for edit in reversed(edits) if reverse else edits:
        old, new = (edit["after"], edit["before"]) if reverse else (edit["before"], edit["after"])
        H.require(old and text.count(old) == 1, "Source edit does not identify exactly one region")
        text = text.replace(old, new, 1)
    return text.encode("utf-8")


def source_pair(raw, proposal):
    digest = H.sha(raw)
    if digest == proposal["before_sha256"]:
        before, after, state = raw, transform(raw, proposal["edits"]), "proposal awaiting installation"
    elif digest == proposal["after_sha256"]:
        before, after, state = transform(raw, proposal["edits"], reverse=True), raw, "installed"
    else:
        raise ValueError(f"Owner changed: {proposal['owner']}; re-audit before replay")
    H.require(H.sha(before) == proposal["before_sha256"], "Reconstructed before source differs")
    H.require(H.sha(after) == proposal["after_sha256"], "Reconstructed final source differs")
    H.require(transform(after, proposal["edits"], reverse=True) == before,
              "Proposal edits are not exactly reversible")
    return before, after, state


def configuration(args, receipt):
    if args.compiler is not None and args.retail is not None:
        cfg = dict(mwcc=str(args.compiler.resolve()), retail_elf=str(args.retail.resolve()),
                   compile_flags=receipt["compiler"]["base_flags"], mwcc_versions={})
    else:
        cfg = H.V.load_config()
        if args.compiler is not None:
            cfg["mwcc"] = str(args.compiler.resolve())
        if args.retail is not None:
            cfg["retail_elf"] = str(args.retail.resolve())
    if args.assembler is not None:
        cfg["as_path"] = str(args.assembler.resolve())
    for proposal in receipt["owners"]:
        owner = ROOT / proposal["owner"]
        compiler = Path(H.V.unit_compiler(owner, cfg))
        H.require(compiler.is_file() and H.sha(compiler.read_bytes()) == receipt["compiler"]["sha256"],
                  f"Compiler differs for {proposal['owner']}")
        flags = H.V.unit_compile_flags(owner, cfg["compile_flags"])
        H.require(flags == proposal["flags"], f"Owner flags differ: {proposal['owner']}")
        H.require(not H.V.is_gcc_unit(owner), "An owner changed compiler family")
    return cfg


def authenticate_retail(receipt, retail, gp, symbols):
    table = receipt["callback_table"]
    address = int(table["address"], 16)
    H.require(H.V.resolve_symbol(table["symbol"], gp, symbols) == address,
              "Callback-table symbol changed")
    payload = retail.bytes_at(address, table["bytes"])
    H.require(H.sha(payload) == table["sha256"], "Callback-table payload changed")
    for witness in table["wrapper_slots"]:
        value = struct.unpack_from("<I", payload, witness["row"] * table["stride"] + witness["slot"])[0]
        H.require(value == int(witness["address"], 16), "Callback-table wrapper binding changed")
    for provider in receipt["provider_retail"]:
        raw = retail.bytes_at(int(provider["address"], 16), provider["bytes"])
        H.require(H.sha(raw) == provider["sha256"], "Vector provider retail body changed")


def run(args):
    receipt = json.loads((HERE / "receipt.json").read_text(encoding="utf-8"))
    H.require(receipt["schema_version"] == 1, "Unsupported receipt schema")
    authenticate_files(receipt)
    A.authenticate(receipt)
    cfg = configuration(args, receipt)
    metadata = H.V._read_json(H.V.FUNCTION_WINDOWS)
    retail = H.V.RetailElf(cfg["retail_elf"], H.V._read_json(H.V.TARGET), metadata["sha1"])
    H.require(metadata["sha1"] == receipt["retail_sha1"], "Retail identity changed")
    gp, symbols = H.addresses()
    H.require(f"{gp:08x}" == receipt["gp"], "Recovered GP changed")
    authenticate_retail(receipt, retail, gp, symbols)
    H.require(not args.output.exists(), "Output already exists; choose a new report path")
    if args.reuse_dir is not None:
        work = args.reuse_dir.resolve()
        H.require(work.is_dir(), "Completed-object directory does not exist")
    elif args.work_dir is not None:
        work = args.work_dir.resolve()
        H.require(not work.exists(), "Work directory already exists")
        work.mkdir(parents=True)
    else:
        build = ROOT / "build"
        build.mkdir(exist_ok=True)
        work = Path(tempfile.mkdtemp(prefix="effect-vector-replay-", dir=build))
    asm_root = ROOT
    if args.regenerate_fallbacks or (args.reuse_dir is None and not args.emit_only):
        asm_root = A.prepare(receipt, retail, work, force=args.regenerate_fallbacks)
    totals = {mode: Counter() for mode in ("default", "guarded")}
    code_totals = Counter()
    data_totals = Counter()
    reports = []
    captured = {}
    for proposal in receipt["owners"]:
        owner = ROOT / proposal["owner"]
        raw = owner.read_bytes()
        captured[proposal["owner"]] = raw
        before, after, state = source_pair(raw, proposal)
        markers = H.V.scan_markers(owner)
        H.require(len(markers) == proposal["function_count"], "Owner function denominator changed")
        by_mode = {}
        for mode in ("default", "guarded"):
            profile = proposal["profiles"][mode]
            phase_reports, phase_functions = {}, {}
            for phase, source in (("before", before), ("after", after)):
                complete = (b"#define NON_MATCHING 1\n" if mode == "guarded" else b"") + source
                expected = profile[phase]
                H.require(H.sha(complete) == expected["source_sha256"], "Profile source hash differs")
                folder = work / owner.stem / (phase + "-" + mode)
                cpath, opath = folder / "owner.c", folder / "owner.o"
                if args.reuse_dir is not None:
                    H.require(cpath.is_file() and cpath.read_bytes() == complete,
                              f"Completed source differs: {owner.stem}/{phase}-{mode}")
                    H.require(opath.is_file() and H.sha(opath.read_bytes()) == expected["object_sha256"],
                              f"Completed object differs: {owner.stem}/{phase}-{mode}")
                else:
                    write_new(cpath, complete)
                    if args.emit_only:
                        continue
                    command = H.V._mwccgap_command(owner, cfg, opath)
                    command[2] = str(cpath.resolve())
                    command[command.index("--asm-dir-prefix") + 1] = str(asm_root.resolve())
                    with H.P._owner_lock(owner.resolve()):
                        process = subprocess.run(command, cwd=ROOT, text=True,
                                                 stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
                    ok, log = process.returncode == 0 and opath.is_file(), process.stdout
                    write_new(folder / "compile.log", log)
                    H.require(ok, f"Complete owner compile failed: {owner.stem}/{phase}-{mode}; see compile.log")
                report, functions = H.inspect(opath, markers, source.decode("utf-8"), mode,
                                               retail, metadata["windows"], symbols, gp)
                H.require(H.fingerprint(report) == profile["proof_fingerprint"],
                          f"Code, references, status or storage drift: {owner.stem}/{phase}-{mode}")
                phase_reports[phase], phase_functions[phase] = report, functions
            if args.emit_only:
                continue
            H.require(phase_reports["before"] == phase_reports["after"], "Before/after proofs differ")
            H.require(phase_functions["before"] == phase_functions["after"], "Before/after functions differ")
            report = phase_reports["after"]
            for address in proposal["wrappers"]:
                rows = [row for row in report["functions"] if row["address"] == address]
                H.require(len(rows) == 1 and rows[0]["status"] == "MATCH", "Corrected wrapper lost its match")
            totals[mode].update(report["status_counts"])
            code_totals[mode] += report["code_relocations"]
            data_totals[mode] += report["data_relocations"]
            by_mode[mode] = phase_functions["after"]
            reports.append(dict(owner=proposal["owner"], mode=mode, source_state=state,
                                all_functions_preserved=True, proof=report,
                                profile_objects={phase: H.sha((work / owner.stem / (phase + "-" + mode) / "owner.o").read_bytes())
                                                 for phase in ("before", "after")}))
            print(proposal["owner"], mode, len(report["functions"]), report["status_counts"],
                  "code refs", report["code_relocations"], "data refs", report["data_relocations"], flush=True)
        if not args.emit_only:
            # Existing matching C must also survive when every available guard is enabled.
            for marker in markers:
                if not marker.get("asm"):
                    H.require(by_mode["default"][marker["name"]] == by_mode["guarded"][marker["name"]],
                              f"Guard profile changed existing C: {marker['name']}")
    if not args.emit_only:
        for mode, expected in receipt["totals"].items():
            H.require(dict(totals[mode]) == expected["status_counts"], "Profile status denominator differs")
            H.require(sum(totals[mode].values()) == 256 and totals[mode]["MATCH"] == 245,
                      "Expected 256 preserved functions and 245 existing matching C")
            H.require(code_totals[mode] == expected["code_relocations"], "Code-reference count differs")
            H.require(data_totals[mode] == expected["data_relocations"], "Data-reference count differs")
    authenticate_files(receipt)
    for relative, raw in captured.items():
        H.require((ROOT / relative).read_bytes() == raw, f"Production changed during replay: {relative}")
    save(args.output, dict(schema_version=1, new_C_matches=0, corrected_wrappers=8,
                           production_source_edited=False,
                           compilation="source emission only" if args.emit_only else
                           "authenticated completed objects" if args.reuse_dir is not None else "fresh complete owners",
                           fresh_compilations=0 if args.emit_only or args.reuse_dir is not None else 16,
                           proof_completed=not args.emit_only, totals={k: dict(v) for k, v in totals.items()},
                           code_relocations=dict(code_totals), data_relocations=dict(data_totals), reports=reports))
    print("PASS: authenticated source emission; no compiler invoked" if args.emit_only else
          "PASS: 8 forwards; 256 functions / 245 matching C preserved in both profiles; all code/data resolved",
          flush=True)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--output", type=Path, required=True, help="new JSON report path")
    modes = parser.add_mutually_exclusive_group()
    modes.add_argument("--reuse-dir", type=Path, help="portable completed objects laid out as OWNER/PHASE-PROFILE/owner.{c,o}")
    modes.add_argument("--emit-only", action="store_true", help="authenticate inputs and emit exact profile sources without compiling")
    parser.add_argument("--work-dir", type=Path, help="new scratch directory for fresh compilation or source emission")
    parser.add_argument("--regenerate-fallbacks", action="store_true",
                        help="reproduce all eleven fallback listings in scratch, also with --emit-only")
    parser.add_argument("--compiler", type=Path, help="explicit configured b210 compiler; SHA-256 must match")
    parser.add_argument("--retail", type=Path, help="explicit retail ELF; repository hash validation remains required")
    parser.add_argument("--assembler", type=Path, help="assembler for fresh compilation, when absent from configured defaults")
    args = parser.parse_args()
    if args.reuse_dir is not None and args.work_dir is not None:
        parser.error("--reuse-dir and --work-dir are mutually exclusive")
    if args.reuse_dir is not None and args.regenerate_fallbacks:
        parser.error("--reuse-dir and --regenerate-fallbacks are mutually exclusive")
    try:
        run(args)
    except (OSError, ValueError, KeyError) as error:
        raise SystemExit(f"Effect vector callback replay failed: {error}") from error


if __name__ == "__main__":
    main()
