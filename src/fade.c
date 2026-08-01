#include "include_asm.h"
/* Source unit: src/fade_00122430.c */
#include "type.h"

extern char D_005E5068[];
extern char D_005E5078[];
extern char iGpffff9c60;
extern u8 *iGpffffb1cc;
extern u8 *(*D_008873F4[])(s32, s32, s32);

void func_0044ea90();
s32 func_00451fc0();
void func_00121b70();
void func_00121db0();
void func_001223d0();

extern char D_005E5090[];
extern char iGpffffb1d8;
extern char iGpffffb1d4;
extern char iGpffffb1d0;

void func_0046d740();

extern char D_005E50B0[];



// FUN_00122430
s32 func_00122430(s32 arg0)
{
    s32 temp_17;
    u8 *temp_2;

    func_0044ea90(&iGpffff9c60, 0x14D);
    temp_2 = D_008873F4[0](1, 0x20, 0x40000);
    if (temp_2 == NULL) {
        return 0;
    }
    iGpffffb1cc = temp_2;
    temp_17 = func_00451fc0(arg0, D_005E5068, 0x98, 0, 0, func_00121b70,
                            func_00121db0, temp_2);
    *(s32 *)(temp_2 + 4) = 1;
    func_00451fc0(temp_17, D_005E5078, 0x99, 0, 0, func_001223d0, NULL, NULL);
    return temp_17;
}



// FUN_00122520 NONMATCHING
// Measured floor nd=19: retail keeps a dead `addiu v0,1` return-value
// materialization in the shared return block (if1 branches to it and the
// out-of-line tail falls into it), so ret0's branch targets the epilogue
// 4 bytes later. MWCC b210 DCE removes the addiu whenever v0=1 is provable
// at the return point; probed if/else, goto-label, two-return, and
// pragma (schedule/optimization_level/propagation/loop_invariants) shapes
// -- all nd>=19.
#ifdef NON_MATCHING
s32 func_00122520(s32 arg0, s32 arg1)
{
    u8 *temp_16;
    s32 ret;

    temp_16 = iGpffffb1cc;
    if (temp_16 == NULL) {
        return 0;
    }
    if (arg0 == 4 && *(s32 *)temp_16 == 3) {
        *(s32 *)(temp_16 + 4) = arg0;
        *(s32 *)(temp_16 + 0x18) = 1;
        iGpffffb1d8 = 0;
        iGpffffb1d4 = 0;
        iGpffffb1d0 = 0;
        ret = 1;
        return ret;
    }
    if (*(s32 *)temp_16 == 0) {
        if (arg0 == 0) {
            func_0046d740(D_005E5090, &iGpffff9c60, 0x17D);
            if (*(s32 *)(temp_16 + 4) == 0) {
                *(s32 *)(temp_16 + 4) = 1;
            }
        } else {
            *(s32 *)(temp_16 + 4) = arg0;
        }
        if (arg1 > 0) {
            *(s32 *)(temp_16 + 8) = arg1;
        } else {
            *(s32 *)(temp_16 + 8) = 0x1E;
        }
        *(s32 *)temp_16 = 1;
        *(s32 *)(temp_16 + 0xC) = 0;
    } else {
        return 0;
    }
    *(s32 *)(temp_16 + 0x18) = 1;
    iGpffffb1d8 = 0;
    iGpffffb1d4 = 0;
    iGpffffb1d0 = 0;
    ret = 1;
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/fade", func_00122520);
#endif



// FUN_00122640
s32 func_00122640(s32 arg0, s32 arg1)
{
    u8 *temp_16;

    temp_16 = iGpffffb1cc;
    if (temp_16 == NULL) {
        return 0;
    }
    if (*(s32 *)temp_16 == 3) {
        if (arg0 == 0) {
            if (*(s32 *)(temp_16 + 4) == 0) {
                func_0046d740(D_005E50B0, &iGpffff9c60, 0x19E);
                *(s32 *)(temp_16 + 4) = 1;
            }
        } else {
            *(s32 *)(temp_16 + 4) = arg0;
        }
        if (arg1 > 0) {
            *(s32 *)(temp_16 + 8) = arg1;
            *(s32 *)(temp_16 + 0xC) = arg1;
        } else {
            *(s32 *)(temp_16 + 8) = 0x1E;
            *(s32 *)(temp_16 + 0xC) = 0x1E;
        }
        *(s32 *)temp_16 = 4;
    } else {
        return 0;
    }
    return 1;
}
