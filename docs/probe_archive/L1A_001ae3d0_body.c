// func_001ae3d0 (0x001ae3d0-0x001ae800, 1072B) — measured wall @123nd/1076B (+4B overrun: REVERTED to ASM per overrun gate).
// Wins: list-node-bits (not arg0) at list-loop packet fill; byte-select arm-swap (==0/arg-first);
// v=0-first structural (killed 3 merge-b, 204->124); u32 sel (a2v->a2, 124->123).
// Walls: s3-hoist (2672-half hoisted pre-1d15a0-jal into s3; s0 reserved for cu by use-lookahead;
//   scope-tricks (cu-block, t/h2/entryp/entry-block-locals) all neutral; inline-h2 STILL s3-hoisted) ~36 rows+frame;
//   deep-lookahead temp coloring (base/n/i/index homes a1/a0/v0 vs a0/v1/a1; tbl/s32-n/idx-name/combined all neutral);
//   pr-stack-slot layout (0x5c vs 0x40; first/3rd/last all neutral-or-worse); bne-operand canonicalization;
//   (s16)-cast extend-pair load-bearing (removal catastrophizes 123->212); DN forms normalize identically.
// Best body below (123nd). Decls kept in TU: 1d3900/19e9f0(K&R u8*)/1d3d00(K&R u8*).
void func_001ae3d0(u8 *arg0)
{
    u8 *lst;
    u8 *found;
    u32 entry;
    u8 *entryp;
    u8 *pkt;
    u16 pr[2];
    u32 sel;
    s32 v;
    u32 t;
    s16 h2;
    s32 cu;

    lst = *(u8 **)(iGpffffb3ac + 372);
    while (lst != NULL) {
        if (func_001a05f0(lst) != 0) {
            pkt = func_0019b6a0((s32)*(u8 **)(*(u8 **)(lst + 48) + 2572));
            *(s64 *)(pkt + 96) = *(s64 *)lst;
            func_00194590(pkt, 1);
        }
        lst = *(u8 **)(lst + 1104);
    }
    found = NULL;
    if (*(u8 *)(*(u8 **)(arg0 + 48) + 162) == 0) {
        sel = (u32)arg0;
    } else {
        sel = (u32)*(u8 **)(arg0 + 56);
    }
    if (sel != 0) {
        u32 n = *(u16 *)(iGpffffb3ac + 3160);
        u16 i = 0;
        while (((i & 0xFFFF)) < n) {
            if (*(u32 *)(iGpffffb3ac + ((i & 0xFFFF) * 4) + 3144) == sel) {
                found = (u8 *)sel;
                break;
            }
            i = (i + 1) & 0xFFFF;
        }
    }
    if (found == NULL) {
        found = *(u8 **)(iGpffffb3ac + (func_00231d70(*(u16 *)(iGpffffb3ac + 3160)) & 0xFFFF) * 4 + 3144);
    }
    pr[0] = 1;
    pr[1] = *(u16 *)(*(u8 **)(found + 48) + 164);
    pkt = func_001fa720((u8 *)pr);
    *(s64 *)(pkt + 96) = *(s64 *)arg0;
    func_00194590(pkt, 1);
    v = 0;
    if (*(u8 *)(*(u8 **)(arg0 + 48) + 162) == 0) {
        if (*(s16 *)(iGpffffb3ac + 2672) != -1) {
            t = func_001ef720(2, 0x80000) & 0xFFFF;
            if ((u32)((s16)(*(s16 *)(iGpffffb3ac + 2674) >> 1)) < t) {
                v = 0;
            } else {
                h2 = *(s16 *)(iGpffffb3ac + 2672);
                if (h2 == (s16)func_001d15a0((s32)t)) {
                    v = 0;
                } else {
                    v = 1;
                }
            }
        }
    }
    if (v != 0) {
        pkt = (u8 *)func_001d3900(1);
        *(s64 *)(pkt + 96) = *(s64 *)arg0;
        func_00194590(pkt, 0);
    }
    pkt = func_00199ee0(*(u8 **)(*(u8 **)(iGpffffb3ac + 368) + 48), 0, 0, 1, 1.0f);
    *(s64 *)(pkt + 96) = *(s64 *)arg0;
    func_00194590(pkt, 0);
    cu = 0;
    while (((cu & 0xFFFF)) < *(u16 *)(iGpffffb3ac + 3160)) {
        entryp = *(u8 **)(iGpffffb3ac + ((cu & 0xFFFF) * 4) + 3144);
        pkt = func_00199ee0(*(u8 **)(entryp + 48), 0, 0, 1, 1.0f);
        *(s64 *)(pkt + 96) = *(s64 *)arg0;
        func_00194590(pkt, 0);
        cu = (cu + 1) & 0xFFFF;
    }
    pkt = (u8 *)func_001d3700(3, 0xFFF);
    *(s64 *)(pkt + 96) = *(s64 *)arg0;
    func_00194590(pkt, 0);
    pkt = func_0019e9f0(0, 3);
    *(s64 *)(pkt + 96) = *(s64 *)arg0;
    func_00194590(pkt, 1);
    pkt = func_0019e7c0(0, 3);
    *(s64 *)(pkt + 96) = *(s64 *)arg0;
    func_00194590(pkt, 1);
    pkt = func_001d3d00(arg0);
    *(s64 *)(pkt + 96) = *(s64 *)arg0;
    func_00194590(pkt, 0);
    pkt = (u8 *)func_001ba090(0);
    *(s64 *)(pkt + 96) = *(s64 *)arg0;
    func_00194590(pkt, 0);
    pkt = func_001bc920(arg0, 7);
    *(s64 *)(pkt + 96) = *(s64 *)arg0;
    func_00194590(pkt, 0);
    entry = *(u32 *)(iGpffffb3ac + 12);
    entry = entry & 0xFFBFFFFF;
    *(u32 *)(iGpffffb3ac + 12) = entry;
    *(u16 *)(iGpffffb3ac + 24) = 0;
    if (func_001eb860() == 1) {
        entry = *(u32 *)(iGpffffb3ac + 12);
        entry = entry & ~0x2000;
        *(u32 *)(iGpffffb3ac + 12) = entry;
        func_00212240(*(u8 **)(iGpffffb3ac + 3540), 0);
    }
    *(u8 **)(arg0 + 1052) = found;
    *(s32 *)(arg0 + 1056) = 0;
    *(s32 *)(arg0 + 1060) = 0;
    *(s32 *)(arg0 + 1064) = 0;
    *(u16 *)(arg0 + 1068) = 12;
}