import idapro, json, collections
idapro.open_database("/home/raikaru/Projects/Persona 3 Decomp/source/Persona4-Decompilation/orig/SLUS_217.82", False)
import ida_hexrays, ida_funcs, ida_ua

assert ida_hexrays.init_hexrays_plugin()

MMI = set("pcpyld pcpyud pcpyh pextlw pextuw pextlb pextub pextlh pand por pxor pnor "
          "ppacw ppacb ppach qfsrv prot3w pexow paddw psubw padduw".split())

insn = ida_ua.insn_t()
mmi_funcs, sq_funcs = [], []
for i in range(ida_funcs.get_func_qty()):
    f = ida_funcs.getn_func(i)
    ea = f.start_ea
    nmmi = nsq = 0
    while ea < f.end_ea:
        if ida_ua.decode_insn(insn, ea) <= 0:
            ea += 4; continue
        m = (insn.get_canon_mnem() or "").strip().lower()
        if m in MMI: nmmi += 1
        elif m in ("sq", "lq"): nsq += 1
        ea += insn.size
    if nmmi: mmi_funcs.append(f.start_ea)
    if nsq: sq_funcs.append(f.start_ea)

print(f"functions with MMI: {len(mmi_funcs)}   with sq/lq: {len(sq_funcs)}")

def probe(eas, label):
    ok = fail = 0
    asm_island = 0
    errs = collections.Counter()
    for ea in eas:
        try:
            cf = ida_hexrays.decompile(ea)
            if cf is None:
                fail += 1; errs["None"] += 1; continue
            ok += 1
            if "__asm" in str(cf): asm_island += 1
        except Exception as e:
            fail += 1; errs[str(e)[:70]] += 1
    print(f"[{label}] ok={ok} fail={fail} with_asm_island={asm_island}")
    for k, v in errs.most_common(6): print(f"    {v:5d}  {k}")
    return ok, fail

probe(mmi_funcs, "MMI")
probe(sq_funcs, "SQ/LQ")

# Does an sq/lq island degrade the BODY? Measure decompiled-line count and
# whether locals analysis survived, on sq/lq functions that contain no MMI.
pure_sq = [e for e in sq_funcs if e not in set(mmi_funcs)]
print(f"\npure sq/lq (no MMI) functions: {len(pure_sq)}")
degraded = clean = 0
for ea in pure_sq[:400]:
    try:
        cf = ida_hexrays.decompile(ea)
        if cf is None: continue
        t = str(cf)
        body = [l for l in t.splitlines() if "__asm" not in l and "sq " not in l and "lq " not in l]
        # crude degradation signal: asm island appearing OUTSIDE the first/last 25% of the body
        lines = t.splitlines()
        idxs = [i for i, l in enumerate(lines) if "sq " in l or "lq " in l]
        if idxs and any(0.25 * len(lines) < i < 0.75 * len(lines) for i in idxs):
            degraded += 1
        else:
            clean += 1
    except Exception:
        pass
print(f"sq/lq islands confined to prologue/epilogue: {clean}   intruding into body: {degraded}")
idapro.close_database(False)
