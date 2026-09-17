/* owner: src/Event/evtPolygonMovie.c (func_0028fc40 @ 0x0028fc40)
 * status: floor (not MATCH) -- live stays INCLUDE_ASM, no regression (verify 7 MATCH / 1 ASM).
 * fndiff.py: obj 2088B / window 2096B (8B short, 0.38% emitted, within ~3%); differing words (reloc-masked) 14 (14/524 2.67%).
 * differing offsets: 0x20-0x30 (prologue daddu order high-first s5,s4,s3,s1,s0 vs retail low-first s1,s0,s5,s4,s3),
 *   0x54/0x398/0x790 (b to epilogue 0x290438 vs 0x290440, 8B-short shift), 0x79C-0x7B8 (third-loop hoisted addiu + regs + beq order),
 *   0x7F4+ (epilogue shift from 8B short).
 * draft: P4_UNIT_0028FC40 in src/generated/code1_0028.c (assignment notes 257 lines, noise 9 with M2C_FIELD/goto/irregular switches).
 *   This banked body: 257 lines, noise 0 (typed u8 ptr / s32, named d2/d3/d4/c0/wk/idx/entry/code/k/b1/b2/b3, if+switch, no M2C/goto).
 * conventions reused (movie-player, boring, no new abstractions):
 *   - u8 work/tables + s32 codes/offs as in func_0028fb90 (u8 *work 0x114) and func_00290710 (u8 * tables, 6-arg n32 with t0/t1) and evtPMFileReader func_002940a0 (u8 base + *(u32*)(base+off) + switch (*(u32*)elem)).
 *   - asserts func_0046d730(D_0063C6A0, 0x155/0x1C3/0x24D) for evtPolygonMovie.c (retail strings 0x63C6A0 evtPolygonMovie.c, 0x63C6C0 pm2 TypeTableCount=%d, 0x63C6E0 object table set ok.).
 *   - debug prints func_00440b68(D_0063C6C0, count) + func_00440b68(D_0063C6E0) as (u8 *fmt, ...) varargs (evtPMFileReader char *fmt, ... shape, u8 to match u8[] without cast).
 *   - func_00290880(c0, *(wk+0x4C)) as s32 (u8 *, s32) per evtMessage.c (second param carries pointer bits, same 32-bit ABI).
 *   - init store order retail-first (0x50 before 0x4C, 0x100/0x104 before 0xF8/0xFC) and reverse-retail case order in source (2-first/0-first) so b210 emits retail chain (23-first/26-first); b1/b2 base temps force lw-then-sll.
 * levers tried (measured fndiff.py; ~12 compiles):
 *   - v1 direct params, ascending cases (2-first): nd442 obj1912/window2096, wrong colors s5=arg0 vs s5=arg2.
 *   - v2 propagation-off param-copy ranking d2,d3,d4,idx,c0,wk (s5=arg2,s4=arg3,s3=arg4,s2=idx,s1=arg0,s0=wk, per matching.md reverse-decl rule): nd329 obj2080, colors ok, switch reversed (23-last).
 *   - v3 reverse-retail cases (2-first/0-first) for retail chain (23-first/26-first): nd44 obj2080, compares match.
 *   - v4/v5/v6 b1/b2 lw-first (entry=b+idx*16): first two loops lw/sll + compares/handlers match (v6 nd39).
 *   - schedule-off around copies: disaster obj1748 beql (branch-likely, retail beq), reverted (matching.md schedule entry).
 *   - schedule-on push/pop around copies: no effect (moves stay decl order), reverted.
 *   - b3/four swaps (four $a1 vs $v1): no effect, reverted; third-loop empty-then-else beq+b (+hoisted four) worse (nd39 vs 14), reverted.
 *   - third-loop switch(code) with code var (vs direct *(entry) / if bne): nd14 obj2088 (8B short), first two loops fully match.
 * floor (why not MATCH):
 *   - 5-word prologue daddu order: ours high-first (s5,s4,s3,s1,s0, decl order) vs retail low-first (s1,s0,s5,s4,s3, param order). With propagation-off locals, moves+ranking both follow decl order, so mapping (d2->s5) and order (c0-first) cannot both hold; mixed direct (arg2/3/4) + locals (c0/wk/idx) model needed (params-first vs locals ranking per matching.md) with assignment-order moves preserved (push/pop schedule tried, volatile would change frame). Needs mixed-model probe.
 *   - third-loop hoisted addiu $v1,0,4 outside (k $a2 first at 0x2903D8, four $v1 second) + beq $v0,$v1 (code $v0) + b inc (2 branches) vs ours addiu $v0,0,4 inside + beq $v1,$v0 (swapped regs, 1-branch switch shape). Needs temp-order probe for $v1 vs $a1 ($a0 vs $a1 for offset/entry) + hoisted-four + beq+b shape without extra regs.
 *   - 8B short (2 words: hoisted addiu + extra b) shifts b-to-epilogue (0x54/0x398/0x790) + tail; fixing third-loop size fixes those.
 * verify: python3 -E -s tools/verify.py src/Event/evtPolygonMovie.c -> 7 MATCH / 1 ASM (live INCLUDE_ASM, no regression from baseline 7/1); lint 0 errors; markers 8 (unchanged); pragmas balanced (live file untouched; banked body carries its own propagation off/on pair, loop_invariants on/off untouched in live).
 * guarded: banked body not live (archived here under docs/probe_archive, not compiled; live stays INCLUDE_ASM). Drop-in needs file-scope externs for func_00290880/func_00440b68/D_0063C6C0/E0 (or use block-scope below, no sibling change).
 */
// FUN_0028FC40
/* measured: floor nd14 obj2088B/window2096B (8B short, 0.38% emitted; 14/524 words 2.67%) via fndiff.py; first two loops match, third-loop + prologue floor. */
#pragma opt_propagation off
u8 *func_0028fc40(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, u8 *arg4)
{
    u8 *d2;
    u8 *d3;
    u8 *d4;
    s32 idx;
    u8 *c0;
    u8 *wk;
    u8 *entry;
    s32 code;
    s32 k;
    u8 *b1;
    u8 *b2;
    u8 *b3;
    /* block-scope externs so this body drops into src/Event/evtPolygonMovie.c without file-scope changes (no sibling regression). */
    extern void func_0046d730(u8 *, s32);
    extern s32 func_00290880(u8 *, s32);
    extern void func_00440b68(u8 *, ...);
    extern u8 D_0063C6A0[];
    extern u8 D_0063C6C0[];
    extern u8 D_0063C6E0[];

    c0 = arg0;
    wk = arg1;
    d2 = arg2;
    d3 = arg3;
    d4 = arg4;
    if (d2 == NULL) {
        func_0046d730(D_0063C6A0, 0x155);
        return NULL;
    }
    *(s32 *)(wk + 0x110) = 0;
    *(u8 **)(wk + 0x10) = d2;
    *(u8 **)(wk + 0x14) = d2 + 0x20;
    *(s32 *)(wk + 0x18) = 0;
    *(s32 *)(wk + 0x1C) = 0;
    *(s32 *)(wk + 0x20) = 0;
    *(s32 *)(wk + 0x24) = 0;
    *(s32 *)(wk + 0x28) = 0;
    *(s32 *)(wk + 0x2C) = 0;
    *(s32 *)(wk + 0x30) = 0;
    *(s32 *)(wk + 0x34) = 0;
    *(s32 *)(wk + 0x38) = 0;
    *(s32 *)(wk + 0x3C) = 0;
    *(s32 *)(wk + 0x40) = 0;
    *(s32 *)(wk + 0x44) = 0;
    *(s32 *)(wk + 0x48) = 0;
    *(s32 *)(wk + 0x50) = 0;
    *(s32 *)(wk + 0x4C) = 0;
    *(s32 *)(wk + 0x54) = 0;
    *(s32 *)(wk + 0x58) = 0;
    *(s32 *)(wk + 0x5C) = 0;
    for (idx = 0; idx < *(s32 *)(*(u8 **)(wk + 0x10) + 0x10); idx++) {
        b1 = *(u8 **)(wk + 0x14);
        entry = b1 + idx * 0x10;
        code = *(s32 *)entry;
        if (code == 0x1B) {
            continue;
        }
        switch (code) {
        case 2:
            *(u8 **)(wk + 0x20) = d2 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0x24) = *(s32 *)(*(u8 **)(wk + 0x14) + idx * 0x10 + 8);
            break;
        case 10:
            *(u8 **)(wk + 0x28) = d2 + *(s32 *)(entry + 0xC);
            break;
        case 11:
            *(u8 **)(wk + 0x2C) = d2 + *(s32 *)(entry + 0xC);
            break;
        case 12:
            *(u8 **)(wk + 0x30) = d2 + *(s32 *)(entry + 0xC);
            break;
        case 3:
            *(u8 **)(wk + 0x34) = d2 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0x38) = *(s32 *)(*(u8 **)(wk + 0x14) + idx * 0x10 + 8);
            break;
        case 9:
            *(u8 **)(wk + 0x3C) = d2 + *(s32 *)(entry + 0xC);
            break;
        case 1:
            *(u8 **)(wk + 0x18) = d2 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0x1C) = *(s32 *)(*(u8 **)(wk + 0x14) + idx * 0x10 + 8);
            break;
        case 6:
            *(u8 **)(wk + 0x4C) = d2 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0x50) = *(s32 *)(*(u8 **)(wk + 0x14) + idx * 0x10 + 8);
            break;
        case 7:
            *(u8 **)(wk + 0x40) = d2 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0x44) = *(s32 *)(*(u8 **)(wk + 0x14) + idx * 0x10 + 8);
            break;
        case 8:
            *(u8 **)(wk + 0x48) = d2 + *(s32 *)(entry + 0xC);
            break;
        case 22:
            *(u8 **)(wk + 0x54) = d2 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0x58) = *(s32 *)(*(u8 **)(wk + 0x14) + idx * 0x10 + 8);
            break;
        case 23:
            *(u8 **)(wk + 0x5C) = d2 + *(s32 *)(entry + 0xC);
            break;
        default:
            func_0046d730(D_0063C6A0, 0x1C3);
            break;
        }
    }
    *(u8 **)(wk + 0x80) = d3;
    if (d3 != NULL) {
        *(u8 **)(wk + 0x84) = d3 + 0x20;
    } else {
        *(s32 *)(wk + 0x84) = 0;
    }
    *(s32 *)(wk + 0x88) = 0;
    *(s32 *)(wk + 0x8C) = 0;
    *(s32 *)(wk + 0x90) = 0;
    *(s32 *)(wk + 0x94) = 0;
    *(s32 *)(wk + 0xAC) = 0;
    *(s32 *)(wk + 0xB0) = 0;
    *(s32 *)(wk + 0xB4) = 0;
    *(s32 *)(wk + 0xB8) = 0;
    *(s32 *)(wk + 0xBC) = 0;
    *(s32 *)(wk + 0xC0) = 0;
    *(s32 *)(wk + 0xC4) = 0;
    *(s32 *)(wk + 0xC8) = 0;
    *(s32 *)(wk + 0xCC) = 0;
    *(s32 *)(wk + 0xD0) = 0;
    *(s32 *)(wk + 0xD4) = 0;
    *(s32 *)(wk + 0xD8) = 0;
    *(s32 *)(wk + 0xDC) = 0;
    *(s32 *)(wk + 0xE0) = 0;
    *(s32 *)(wk + 0xE4) = 0;
    *(s32 *)(wk + 0xE8) = 0;
    *(s32 *)(wk + 0xEC) = 0;
    *(s32 *)(wk + 0xF0) = 0;
    *(s32 *)(wk + 0xF4) = 0;
    *(s32 *)(wk + 0x100) = 0;
    *(s32 *)(wk + 0x104) = 0;
    *(s32 *)(wk + 0xF8) = 0;
    *(s32 *)(wk + 0xFC) = 0;
    *(s32 *)(wk + 0x108) = 0;
    *(s32 *)(wk + 0x10C) = 0;
    *(s32 *)(wk + 0x60) = 0;
    *(s32 *)(wk + 0x64) = 0;
    if (d3 == NULL) {
        return wk;
    }
    func_00440b68(D_0063C6C0, *(s32 *)(*(u8 **)(wk + 0x80) + 0x10));
    for (idx = 0; idx < *(s32 *)(*(u8 **)(wk + 0x80) + 0x10); idx++) {
        b2 = *(u8 **)(wk + 0x84);
        entry = b2 + idx * 0x10;
        code = *(s32 *)entry;
        switch (code) {
        case 0:
            *(u8 **)(wk + 0x90) = d3 + *(s32 *)(entry + 0xC);
            break;
        case 4:
            if (*(s32 *)(*(u8 **)(wk + 0x80) + 0x14) == 4) {
                *(u8 **)(wk + 0x94) = d3 + *(s32 *)(entry + 0xC);
                *(s32 *)(wk + 0x98) = 0;
            } else {
                *(u8 **)(wk + 0x98) = d3 + *(s32 *)(entry + 0xC);
                *(s32 *)(wk + 0x94) = 0;
            }
            *(s32 *)(wk + 0xAC) = *(s32 *)(*(u8 **)(wk + 0x84) + idx * 0x10 + 8);
            break;
        case 1:
            *(u8 **)(wk + 0x88) = d3 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0x8C) = *(s32 *)(*(u8 **)(wk + 0x84) + idx * 0x10 + 8);
            break;
        case 5:
            *(u8 **)(wk + 0xB0) = d3 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0xB4) = *(s32 *)(*(u8 **)(wk + 0x84) + idx * 0x10 + 8);
            break;
        case 13:
            *(u8 **)(wk + 0xB8) = d3 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0xBC) = *(s32 *)(*(u8 **)(wk + 0x84) + idx * 0x10 + 8);
            break;
        case 14:
            *(u8 **)(wk + 0xC0) = d3 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0xC4) = *(s32 *)(*(u8 **)(wk + 0x84) + idx * 0x10 + 8);
            break;
        case 15:
            *(u8 **)(wk + 0xC8) = d3 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0xCC) = *(s32 *)(*(u8 **)(wk + 0x84) + idx * 0x10 + 8);
            break;
        case 16:
            *(u8 **)(wk + 0xD0) = d3 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0xD4) = *(s32 *)(*(u8 **)(wk + 0x84) + idx * 0x10 + 8);
            break;
        case 17:
            *(u8 **)(wk + 0xD8) = d3 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0xDC) = *(s32 *)(*(u8 **)(wk + 0x84) + idx * 0x10 + 8);
            break;
        case 18:
            *(u8 **)(wk + 0xE0) = d3 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0xE4) = *(s32 *)(*(u8 **)(wk + 0x84) + idx * 0x10 + 8);
            break;
        case 19:
            *(u8 **)(wk + 0xE8) = d3 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0xEC) = *(s32 *)(*(u8 **)(wk + 0x84) + idx * 0x10 + 8);
            break;
        case 20:
            *(u8 **)(wk + 0xF0) = d3 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0xF4) = *(s32 *)(*(u8 **)(wk + 0x84) + idx * 0x10 + 8);
            break;
        case 24:
            *(u8 **)(wk + 0xF8) = d3 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0xFC) = *(s32 *)(*(u8 **)(wk + 0x84) + idx * 0x10 + 8);
            break;
        case 21:
            *(u8 **)(wk + 0x100) = d3 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0x104) = *(s32 *)(*(u8 **)(wk + 0x84) + idx * 0x10 + 8);
            func_00440b68(D_0063C6E0);
            break;
        case 25:
            *(u8 **)(wk + 0x108) = d3 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0x10C) = *(s32 *)(*(u8 **)(wk + 0x84) + idx * 0x10 + 8);
            break;
        case 26:
            *(u8 **)(wk + 0x60) = d3 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0x64) = *(s32 *)(*(u8 **)(wk + 0x84) + idx * 0x10 + 8);
            break;
        default:
            func_0046d730(D_0063C6A0, 0x24D);
            break;
        }
    }
    if (*(u8 **)(wk + 0x90) != NULL) {
        if (*(u8 **)(wk + 0x4C) != NULL && *(s32 *)(wk + 0x50) > 0) {
            func_00290880(c0, *(s32 *)(wk + 0x4C));
        }
    }
    *(u8 **)(wk + 0x9C) = d4;
    if (d4 != NULL) {
        *(u8 **)(wk + 0xA0) = d4 + 0x20;
    } else {
        *(s32 *)(wk + 0xA0) = 0;
    }
    *(s32 *)(wk + 0xA4) = 0;
    *(s32 *)(wk + 0xA8) = 0;
    if (d4 == NULL) {
        return wk;
    }
    for (k = 0; k < *(s32 *)(*(u8 **)(wk + 0x9C) + 0x10); k++) {
        b3 = *(u8 **)(wk + 0xA0);
        entry = b3 + k * 0x10;
        code = *(s32 *)entry;
        switch (code) {
        case 4:
            *(u8 **)(wk + 0xA4) = d4 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0xA8) = *(s32 *)(*(u8 **)(wk + 0xA0) + k * 0x10 + 8);
            break;
        default:
            break;
        }
    }
    return wk;
}
/* measured: restore propagation after retail register-coloring experiment. */
#pragma opt_propagation on
