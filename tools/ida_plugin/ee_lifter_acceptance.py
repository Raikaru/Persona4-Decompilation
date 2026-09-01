import idapro, collections
idapro.open_database("/home/raikaru/Projects/Persona 3 Decomp/source/Persona4-Decompilation/orig/SLUS_217.82", False)
import ida_hexrays, ida_funcs, ida_ua
assert ida_hexrays.init_hexrays_plugin()
MMI=set("pcpyld pcpyud pcpyh pextlw pextuw pextlb pextub pextlh pand por pxor pnor ppacw ppacb ppach qfsrv prot3w pexow paddw psubw padduw".split())
insn=ida_ua.insn_t(); mmi=[]; sq=[]
for i in range(ida_funcs.get_func_qty()):
    f=ida_funcs.getn_func(i); ea=f.start_ea; a=b=0
    while ea<f.end_ea:
        if ida_ua.decode_insn(insn,ea)<=0: ea+=4; continue
        m=(insn.get_canon_mnem() or "").strip().lower()
        if m in MMI: a+=1
        elif m in ("sq","lq"): b+=1
        ea+=insn.size
    if a: mmi.append(f.start_ea)
    if b: sq.append(f.start_ea)
def run(pop,label):
    ok=fail=isl=0
    for ea in pop:
        try:
            cf=ida_hexrays.decompile(ea)
            if cf is None: fail+=1; continue
            ok+=1
            if "__asm" in str(cf): isl+=1
        except Exception: fail+=1
    print(f"[{label}] n={len(pop)} ok={ok} fail={fail} island={isl}")
    return fail,isl
mf,mi = run(mmi,"MMI")
sf,si = run(sq,"SQ/LQ")
print("\n=== BASELINES (no plugin): MMI fail=0 ; SQ/LQ fail=0 island=5099 ===")
print("PLUGIN RESULT:", "PASS" if mf==0 and sf==0 and si<5099 else "FAIL")
idapro.close_database(False)
