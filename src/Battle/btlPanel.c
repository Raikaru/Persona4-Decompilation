#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit btlPanel.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
typedef struct BtlPanel BtlPanel;
struct BtlPanel
{
    u8* records;    // 0x00
    u8 pad4[0x30];
    s32 field34;    // 0x34
    u8 pad38[4];
    s16 state;      // 0x3C
    s16 index;      // 0x3E
};

void func_00440b68();
extern u8* func_00454a60(u8* param, s32 mode);
void func_00454bd0(u8* ptr);
s32 func_004553c0(u8* ptr);
s32 func_00106330(s32 id);
s32 func_0019ef90(s32 a, s32 b);
s32 func_0046b000(u32 param);
s32 func_0046a750(s32 param);
s32 func_0046a770(u32 param);
extern u8* func_00452560(s32 param);
extern char iGpffffa578;
extern s32 iGpffffa570;
extern char D_00626780[];
extern u8 D_00626790[];
extern u8 D_006267B0[];
extern u32 D_00626720[];
extern u8* func_00194470(u32 type, u32 workSize);
void func_0043f9c8(void* dst, s32 value, u32 size);
void func_00456150(u8* ptr);
s32 func_00481360(s32 param);
extern s32 iGpffffb470;
extern u8 D_006267D0[];



// FUN_00202890 NONMATCHING
// measured: nd 310 at -O2 (obj 696B/720B). Residual is one MWCC register-content
// choice: retail keeps idx*4 in $s0 and recomputes the slot address per store
// (`addu $v1,$s0,$s2; sw $v0,0x2c($v1)`); b210 instead materializes the full
// address recs+idx*4+0x2C into $s0 and stores with offset 0, re-materializing
// idx*4 per D_00626720 access. Register-agnostic content diff: call sequence,
// offsets and constants are 100% correct; every difference traces to that one
// allocation decision. Probed 15+ shapes (struct/raw-pointer/array-index forms,
// off variable, two-statement stores, -O1/-O3, schedule/opt pragmas) - all
// compile to the identical hoist; no C source reaches retail's allocation.
#ifdef NON_MATCHING
s32 func_00202890(BtlPanel* panel)
{
    u8* recs = func_00452560(panel->field34);
    s16 done = 0;
    s32 idx;
    u8* rec;

    switch (panel->state) {
    case 0:
        rec = panel->records;
        if (rec == NULL) {
            if (func_00106330(0x1438) == 0) {
                func_00440b68(&iGpffffa578, D_00626780, 0x532);
                panel->records = func_00454a60(D_00626790, 1);
            } else {
                func_00440b68(&iGpffffa578, D_00626780, 0x534);
                panel->records = func_00454a60(D_006267B0, 1);
            }
            goto check;
        }
        if (func_004553c0(rec) != 0) {
            panel->state = 1;
        case 1:
            idx = panel->index;
            if (*(s32*)(recs + idx * 4 + 0x2C) == 0) {
                if (idx < 8) {
                    if (func_0019ef90(0, (idx + 1) & 0xFFFF) != 0) {
                        if (func_00106330(0x1438) == 0 || idx != 0) {
                            *(s32*)(recs + idx * 4 + 0x2C) = func_0046b000(D_00626720[idx]);
                        } else {
                            *(s32*)(recs + idx * 4 + 0x2C) = func_0046b000(iGpffffa570);
                        }
                    } else {
                        *(s32*)(recs + idx * 4 + 0x2C) = 0;
                        panel->index++;
                    }
                } else if (idx < 0xC) {
                    *(s32*)(recs + idx * 4 + 0x2C) = func_0046b000(D_00626720[idx]);
                }
            } else if (func_0046a750(*(s32*)(recs + idx * 4 + 0x2C)) != 0) {
                if (++panel->index == 0xC) {
                    func_00454bd0(panel->records);
                    panel->records = NULL;
                    done = 0xC;
                }
            }
        }
        break;
    default:
        break;
    }
check:
    if (done == 0xC) {
        for (idx = 0xC; idx < 0x10; idx++) {
            *(s32*)(recs + idx * 4 + 0x2C) = func_0046a770(D_00626720[idx]);
        }
        *(u32*)recs |= 1;
        return 1;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/btlPanel", func_00202890);
#endif



// FUN_00202B60
s32 func_00202890(void* panel);

u8* func_00202b60(s32 param)
{
    u8* p = func_00194470(0x508, 0x40);
    u8* rec;

    p[0x47] &= 0xFE;
    *(u32*)(p + 0x6C) = (u32)func_00202890;
    rec = *(u8**)(p + 0x78);
    func_0043f9c8(rec, 0, 0x40);
    *(s32*)(rec + 0x34) = param;
    return p;
}



// FUN_00202BE0
void func_00202be0(void)
{
    u8* t;

    func_00440b68(&iGpffffa578, D_00626780, 0x5FB);
    t = func_00454a60(D_006267D0, 0);
    func_00456150(t);
    iGpffffb470 = func_00481360(*(s32*)(t + 0x110));
    func_00454bd0(t);
}
