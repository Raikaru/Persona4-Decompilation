#!/usr/bin/env python3
"""Replay the guarded Model00471370 candidate with existing private inputs.

Only temporary source copies are edited. Stdout is a public-safe JSON receipt;
objects use a deleted temporary directory, and compiler output is not published.
"""
import argparse
import difflib
import hashlib
import importlib
import json
import os
from pathlib import Path
import re
import struct
import subprocess
import sys
import tempfile

sys.dont_write_bytecode = True
import model_replay_elf as A

OWNER = "src/Graphics/Model/mdlManager.c"
BASELINE = "ff2f5f96ab71399cea76af2eb715823d306b8d7d"
TARGET = "func_00471370"
GUARDS = {TARGET, "func_0047b0c0"}
EXPECTED_OBJECT = "95fb96ebab91d2744c4f30b49af8cd7f74db46eda7a2ee93dbaee18d34c50942"
sha = lambda data: hashlib.sha256(data).hexdigest()


class ReplayError(RuntimeError):
    """A deliberately path-free diagnostic safe for the public receipt."""


def require(condition, message):
    if not condition:
        raise ReplayError(message)


def enable_target(source):
    """Change precisely the target guard, never define NON_MATCHING globally."""
    pattern = rb"(// FUN_00471370 NONMATCHING\r?\n)#ifdef NON_MATCHING(?=\r?\n)"
    result, count = re.subn(pattern, rb"\g<1>#if 1", source)
    require(count == 1, "expected exactly one guarded target marker")
    require(result.count(b"#ifdef NON_MATCHING") == source.count(b"#ifdef NON_MATCHING") - 1,
            "unexpected non-target guard change")
    return result


def metrics(retail, candidate):
    a = struct.unpack("<%dI" % (len(retail) // 4), retail)
    b = struct.unpack("<%dI" % (len(candidate) // 4), candidate)
    previous = list(range(len(b) + 1))
    for i, x in enumerate(a, 1):
        row = [i]
        for j, y in enumerate(b, 1):
            row.append(min(row[-1] + 1, previous[j] + 1, previous[j - 1] + (x != y)))
        previous = row
    ops = difflib.SequenceMatcher(None, a, b, autojunk=False).get_opcodes()
    return dict(retail_bytes=len(retail), candidate_bytes=len(candidate),
                unit_word_levenshtein=previous[-1],
                sequence_matcher_block_edits=sum(max(j-i, l-k) for t, i, j, k, l in ops if t != "equal"),
                equal_words=sum(j-i for t, i, j, k, l in ops if t == "equal"),
                positional_word_differences=sum(x != y for x, y in zip(a, b)) + abs(len(a)-len(b)),
                positional_byte_differences=sum(x != y for x, y in zip(retail, candidate)) + abs(len(retail)-len(candidate)))


def analyze(obj, source, V, B, retail, windows, gp, target_enabled):
    """Resolve every emitted function/data reference, retaining no retail dump."""
    byname = {m["name"]: m for m in V.scan_markers(source)}
    require(len(byname) == 126, "owner marker census changed")
    definitions = [s for s in obj.symbols if s["info"] & 15 == 2
                   and 0 < s["shndx"] < len(obj.sections) and s["size"]]
    expected = set(byname) - (GUARDS - {TARGET} if target_enabled else GUARDS)
    require({s["name"] for s in definitions} == expected, "unexpected emitted function census")
    witnesses = []
    for s in definitions:
        marker = byname[s["name"]]
        raw, refs = obj.function(s["name"])
        rw = retail.bytes_at(marker["addr"], windows[f'{marker["addr"]:08x}'])
        if s["name"] not in GUARDS and V.compare(raw, refs, rw)[0] == 0 and len(raw) <= len(rw) and not any(rw[len(raw):]):
            witnesses.append(marker)
    votes = B._section_base_votes(obj, witnesses, retail, gp)
    require(all(len(v) == 1 for v in votes.values()), "ambiguous owned data address")
    bases = {index: next(iter(v)) for index, v in votes.items()}
    for s in definitions:
        base = byname[s["name"]]["addr"] - s["value"]
        require(bases.setdefault(s["shndx"], base) == base, "inconsistent code base")
    siblings, data, controls, target = {}, {}, set(), {}
    code_references = data_references = 0
    for s in definitions:
        name = s["name"]
        raw, refs = obj.function(name)
        linked, bindings = A.resolve(obj, raw, refs, bases)
        require(not any("error" in r for r in bindings), "unresolved code reference")
        code_references += len(bindings)
        marker = byname[name]
        rw = retail.bytes_at(marker["addr"], windows[f'{marker["addr"]:08x}'])
        exact = len(linked) <= len(rw) and linked == rw[:len(linked)] and not any(rw[len(linked):])
        if name != TARGET:
            require(exact, "a production C sibling is not strict exact")
            siblings[name] = (sha(raw), sha(linked), len(raw))
        else:
            words = struct.unpack("<%dI" % (len(rw) // 4), rw)
            live = max(i * 4 + 8 for i, word in enumerate(words) if word == 0x03e00008)
            require(not any(rw[live:]), "nonzero target alignment tail")
            cw = struct.unpack("<%dI" % (len(linked) // 4), linked)
            target = dict(metrics=metrics(rw[:live], linked),
                          frame=hex(-struct.unpack_from("<h", raw)[0]),
                          retail_frame=hex(-struct.unpack_from("<h", rw)[0]),
                          raw_sha256=sha(raw), resolved_sha256=sha(linked),
                          direct_calls=sum(w >> 26 == 3 for w in cw),
                          indirect_calls=sum(w >> 26 == 0 and w & 63 == 9 for w in cw))
        for kind in (4, 5, 7, 8):
            key = ("target" if name == TARGET else "sibling", kind)
            if key in controls:
                continue
            found = next((r for r in bindings if r["r_type"] == kind and r.get("symbol")), None)
            if found:
                wrong, wr = A.resolve(obj, raw, refs, bases, {found["symbol"]: found["address"] + 4})
                require(not any("error" in r for r in wr) and wrong != linked, "ineffective reference negative control")
                require(not exact or wrong != rw[:len(wrong)], "bad reference accepted as exact")
                controls.add(key)
    for sec in obj.sections:
        if not sec["flags"] & 2 or sec["flags"] & 4 or not sec["size"]:
            continue
        raw = bytes(sec["size"]) if sec["type"] == 8 else obj.data[sec["offset"]:sec["offset"] + sec["size"]]
        linked, refs = A.resolve(obj, raw, A.refs(obj, sec["idx"]), bases)
        require(not any("error" in r for r in refs), "unresolved data reference")
        data_references += len(refs)
        base = bases.get(sec["idx"])
        require(base is not None, "missing actual owned data address")
        require(linked == retail.bytes_at(base, len(linked)), "owned data differs from retail")
        require(base not in data, "duplicate owned data address")
        data[base] = (sha(raw), sha(linked), sec["size"], sec["type"], sec["addralign"], sec["flags"])
    for sec in obj.sections:
        if not sec["flags"] & 4 or not sec["size"]:
            continue
        covered = bytearray(sec["size"])
        for s in definitions:
            if s["shndx"] == sec["idx"]:
                covered[s["value"]:s["value"] + s["size"]] = bytes([1]) * s["size"]
        raw = obj.data[sec["offset"]:sec["offset"] + sec["size"]]
        require(not any(b for b, c in zip(raw, covered) if not c), "unowned nonzero executable bytes")
    require(len(siblings) == 124 and len(data) == 11, "sibling/data census changed")
    needed = {("sibling", k) for k in (4, 5, 7, 8)}
    if target_enabled:
        needed |= {("target", k) for k in (4, 5, 7)}
    require(controls == needed, "reference negative-control coverage changed")
    return dict(siblings=siblings, data=data, target=target,
                code_references=code_references, data_references=data_references,
                negative_controls=len(controls))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--repo", type=Path, default=Path(__file__).resolve().parents[1])
    parser.add_argument("--owner-source", type=Path, help="read-only guarded-owner override for integration review")
    parser.add_argument("--private-dir", type=Path, help="temporary work parent; default: system temporary directory")
    parser.add_argument("--skip-production-splice", action="store_true", help="check C-only objects; report production splice as not checked")
    args = parser.parse_args()
    repo = args.repo.resolve()
    sys.path.insert(0, str(repo / "tools"))
    V, B = importlib.import_module("verify"), importlib.import_module("build")
    require(V.REPO.resolve() == repo and B.REPO.resolve() == repo, "wrong repository tools imported")
    for name in ("P4_MWCC", "P4_RETAIL_ELF", "P4_AS"):
        require(bool(os.environ.get(name)) and Path(os.environ[name]).is_file(), "set existing authorized " + name)
    cfg = V.load_config()
    require(not any("NON_MATCHING" in flag for flag in V.unit_compile_flags(repo / OWNER, cfg["compile_flags"])),
            "NON_MATCHING must not be enabled globally")
    current = (args.owner_source or repo / OWNER).read_bytes()
    enabled = enable_target(current)
    baseline = subprocess.check_output(["git", "show", BASELINE + ":" + OWNER], cwd=repo, stderr=subprocess.PIPE)
    wm, target = V._read_json(V.FUNCTION_WINDOWS), V._read_json(V.TARGET)
    retail = V.RetailElf(cfg["retail_elf"], target, wm["sha1"])
    gp, values = int(target["elf"]["gp"], 0), {}
    for name in ("symbol_addrs.txt", "symbol_data_addrs.txt", "symbols_recovered.txt"):
        for line in (repo / "config" / name).read_text().splitlines():
            match = re.match(r"\s*([\w.$]+)\s*=\s*(0x[0-9A-Fa-f]+)\s*;", line)
            if match:
                name, value = match[1], int(match[2], 16)
                require(values.setdefault(name, value) == value, "inconsistent repository symbol values")
    A.V, A.values, A.gp = V, values, gp
    with tempfile.TemporaryDirectory(prefix="model00471370-", dir=args.private_dir) as temp:
        work = Path(temp)
        env = dict(os.environ, PYTHONDONTWRITEBYTECODE="1", TMPDIR=temp, TEMP=temp, TMP=temp)

        def compile_owner(label, source, skip_asm=True):
            path, output = work / (label + ".c"), work / (label + ".o")
            path.write_bytes(source)
            command = V._mwccgap_command(repo / OWNER, cfg, output)
            command[2] = str(path)
            if skip_asm:
                command.append("--skip-asm")
            result = subprocess.run(command, cwd=repo, env=env, stdout=subprocess.PIPE,
                                    stderr=subprocess.STDOUT, timeout=300)
            # Do not print compiler output: it can contain private paths/bytes.
            require(result.returncode == 0 and output.is_file(), "compilation failed: " + label)
            return path, V.ObjectFile(output)

        bp, bo = compile_owner("baseline", baseline)
        cp, co = compile_owner("guarded", current)
        ep, eo = compile_owner("target", enabled)
        _, repeat = compile_owner("repeat", enabled)
        require(bo.data == co.data, "guarded C-only production object changed")
        require(eo.data == repeat.data, "candidate repeat object changed")
        require(sha(eo.data) == EXPECTED_OBJECT, "canonical candidate object hash changed")
        base = analyze(bo, bp, V, B, retail, wm["windows"], gp, False)
        guarded = analyze(co, cp, V, B, retail, wm["windows"], gp, False)
        candidate = analyze(eo, ep, V, B, retail, wm["windows"], gp, True)
        for proof in (guarded, candidate):
            require(proof["siblings"] == base["siblings"], "sibling bytes changed")
            require(proof["data"] == base["data"], "owned data changed")
        result = candidate["target"]
        require(result["metrics"]["unit_word_levenshtein"] == 812 and result["metrics"]["candidate_bytes"] == 7084
                and result["metrics"]["retail_bytes"] == 7104 and result["frame"] == result["retail_frame"] == "0x550",
                "accepted candidate metrics changed")
        production = dict(status="not checked")
        if not args.skip_production_splice:
            _, old = compile_owner("baseline-spliced", baseline, False)
            _, new = compile_owner("guarded-spliced", current, False)
            require(old.data == new.data, "assembly-spliced production object changed")
            production = dict(status="identical", object_sha256=sha(new.data))
        result.update(status="PASS; target remains NONMATCHING", baseline_commit=BASELINE,
                      baseline_source_sha256=sha(baseline), guarded_source_sha256=sha(current),
                      target_only_source_sha256=sha(enabled), candidate_object_sha256=sha(eo.data),
                      guarded_c_only_object_sha256=sha(co.data), guarded_c_only_identical=True,
                      production_splice=production, repeated_identical=True,
                      exact_unchanged_siblings=len(candidate["siblings"]),
                      unchanged_owned_data_sections=len(candidate["data"]),
                      actual_reference_errors=0, code_references=candidate["code_references"],
                      data_references=candidate["data_references"],
                      rejected_reference_negative_controls=candidate["negative_controls"])
    print(json.dumps(result, indent=2, sort_keys=True))


if __name__ == "__main__":
    try:
        main()
    except Exception as error:
        # Only our deliberately path-free diagnostics are public-safe.
        message = str(error) if type(error) is ReplayError else type(error).__name__
        print(json.dumps(dict(status="FAIL", error=message)))
        sys.exit(1)
