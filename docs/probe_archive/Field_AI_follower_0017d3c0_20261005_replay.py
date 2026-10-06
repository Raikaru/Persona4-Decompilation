"""Replay the installed guarded field follower's source-bound native proof."""
from __future__ import annotations

import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import struct
import sys

ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/"tools"))
import verify
import probe_variants
from Field_axis_contract_20261005_proof import prove
from Field_AI_follower_0017d3c0_20261005_proof import resolve


def sha(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main() -> None:
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--hashes-only",action="store_true")
    parser.add_argument("--out",type=Path,default=ROOT/"build/field-follower-20261005-replay")
    args=parser.parse_args()
    receipt=json.loads(Path(__file__).with_name("Field_AI_follower_0017d3c0_20261005_receipt.json").read_text())
    for relative,expected in receipt["portable_inputs"].items():
        actual=sha(ROOT/relative)
        if actual!=expected:
            raise SystemExit(f"Input changed: {relative}: expected {expected}, got {actual}")
    print(f"Authenticated {len(receipt['portable_inputs'])} project inputs.",flush=True)
    if args.hashes_only:
        return
    cfg=verify.load_config()
    meta=verify._read_json(verify.FUNCTION_WINDOWS)
    retail=verify.RetailElf(cfg["retail_elf"],verify._read_json(verify.TARGET),meta["sha1"])
    assert meta["sha1"]==receipt["retail_sha1"]
    source=ROOT/receipt["installation"]["owner"]
    compiler=Path(verify.unit_compiler(source,cfg))
    assert sha(compiler)==receipt["compiler_profile"]["compiler_sha256"]
    assert verify.unit_compile_flags(source,cfg["compile_flags"])==receipt["compiler_profile"]["flags"]
    output=args.out.resolve()
    output.mkdir(parents=True,exist_ok=True)
    if any(output.iterdir()):
        raise SystemExit(f"Replay output already contains evidence; choose a fresh --out: {output}")
    bounds={int(address,16) for address in meta["windows"]}
    bounds.update(int(address,16)+size for address,size in meta["windows"].items() if size)
    rows=verify.verify_file(source,cfg,retail,sorted(bounds),output)
    summary=dict(Counter(row["status"] for row in rows))
    assert summary==receipt["installation"]["summary"]
    default_object=output/(receipt["installation"]["owner"].replace("/","_")+".o")
    assert sha(default_object)==receipt["installation"]["default_object"]["sha256"]
    strict=prove(verify.ObjectFile(default_object),verify.scan_markers(source),retail,meta["windows"])
    assert {k:v for k,v in strict.items() if k not in ("functions","owned_data")}==receipt["installation"]["strict_default_summary"]
    guarded_source=output/"guarded.c"
    guarded_source.write_bytes(b"#define NON_MATCHING 1\n"+source.read_bytes())
    guarded_object=output/"guarded.o"
    ok,log=probe_variants._compile_in_context(guarded_source,source,cfg,guarded_object)
    (output/"guarded.compile.log").write_text(log,encoding="utf-8")
    assert ok,log
    assert sha(guarded_object)==receipt["installation"]["guarded_object"]["sha256"]
    diagnostic=resolve(verify.ObjectFile(guarded_object),"func_0017d3c0",0x0017D3C0,retail,meta["windows"]["0017d3c0"],False)
    assert diagnostic==receipt["proof"]["target_resolved_diagnostic"]
    target=retail.bytes_at(0x0017D3C0,meta["windows"]["0017d3c0"])
    retail_calls=Counter((word&0x03FFFFFF)<<2 for word, in struct.iter_unpack("<I",target) if word>>26==3)
    native_calls=Counter(row["symbol_address"]+row["addend"] for row in diagnostic["relocations"] if row["r_type"]==4)
    assert native_calls==retail_calls and sum(native_calls.values())==92
    (output/"default-proof.json").write_text(json.dumps(strict,indent=2)+"\n",encoding="utf-8")
    (output/"target-diagnostic.json").write_text(json.dumps(diagnostic,indent=2)+"\n",encoding="utf-8")
    result={"summary":summary,"default_code_relocations":strict["code_relocation_count"],
        "guarded_target_relocations":diagnostic["resolved_relocations"],
        "guarded_differing_words":diagnostic["fully_resolved_differing_words"],
        "retail_direct_call_inventory_identical":True,"new_functions":[]}
    (output/"completed.json").write_text(json.dumps(result,indent=2)+"\n",encoding="utf-8")
    print(json.dumps(result,indent=2),flush=True)


if __name__=="__main__":
    main()
