/* Original translation unit k_field.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */

#include "include_asm.h"
#include "type.h"

extern s32 iGpffffb20c;
extern s32 iGpffffb4e4;
extern u8 *iGpffff9db0;
extern s32 D_007E8060[];
extern u8 D_007E80A0[];
extern s32 D_007D2510[];

#define KFIELD_D_007D2540 (*(s32 *)0x007D2540)
#define KFIELD_D_007E8060 (D_007E8060)
#define KFIELD_D_007E80A0 (D_007E80A0)
#define KFIELD_D_007D2510 (D_007D2510)
#define KFIELD_JTBL_008873EC (*(void (**)(s32))((u8 *)0x00880000 + 0x73EC))

extern void func_00123ac0(void);
extern void func_00167530(void);
extern void func_002bd410(void);
extern void func_002bd3e0(void);
extern void func_00149690(s32);
extern void func_00452080(s32);
extern void func_00151f80(s32);
extern s32 func_00102980(void);
extern void func_001622d0(void);
extern void func_00164170(void);
extern void func_001641d0(void);
extern void func_0043f9c8(void *, s32, s32);
extern void func_00156750(u8 *);
extern u8 *func_00457120(void);
extern void func_003e9df0(s32);

// FUN_00155360
INCLUDE_ASM("asm/nonmatchings/k_field", func_00155360);

/* measured: func_00155bf0 near-match parked at normalized_diff 2 (object 540B/window 544B); the retail window includes one trailing nop beyond the C object, and the GP symbol iGpffffb20c is not recovered. */
// FUN_00155BF0 NONMATCHING
#ifdef NON_MATCHING
void func_00155bf0(u8 *arg0)
{
    u8 *temp_17;
    s32 temp_4;
    s32 temp_4_2;
    s32 temp_4_3;
    s32 temp_16;
    s32 *temp_20;
    s32 *temp_2;
    s32 var_18;

    temp_17 = *(u8 **)(arg0 + 0x38);
    if (iGpffffb20c == 1) {
        func_00123ac0();
    }
    func_00167530();
    func_002bd410();
    func_002bd3e0();
    KFIELD_D_007D2540 = 0;
    func_00149690(0);
    temp_4 = *(s32 *)(temp_17 + 0x3C);
    if (temp_4 != 0) {
        func_00452080(temp_4);
        var_18 = 0;
        while (var_18 < 0x10) {
            temp_16 = var_18 * 4;
            temp_20 = (s32 *)((u8 *)KFIELD_D_007E8060 - 0x7FA0) + var_18;
            temp_4_2 = *temp_20;
            if (temp_4_2 != 0) {
                func_00151f80(temp_4_2);
                *temp_20 = 0;
                *(s32 *)(iGpffff9db0 + temp_16 + 0x28) = 0;
            }
            var_18 += 1;
        }
    }
    if (func_00102980() != 9 &&
        func_00102980() != 0xB &&
        func_00102980() != 0xA) {
        func_001622d0();
    }
    if ((u16)*(u16 *)(temp_17 + 0x18) < 0x15) {
        goto field_special;
    }
    if ((u16)*(u16 *)(temp_17 + 0x18) < 0x1F) {
        goto field_call;
    }
field_special:
    if (*(u16 *)(temp_17 + 0x18) != 6) {
        goto field_done;
    }
    if (*(u16 *)(temp_17 + 0x1A) != 1) {
        goto field_done;
    }
field_call:
    func_001622d0();
field_done:
    func_00164170();
    func_001641d0();
    func_0043f9c8((u8 *)KFIELD_D_007E80A0 - 0x7F60, 0, 0xB40);
    iGpffffb4e4 = 0;
    func_00156750(arg0);
    temp_16 = 0;
    while (temp_16 < 3) {
        temp_2 = (s32 *)((u8 *)KFIELD_D_007D2510 + 0x2510) + temp_16;
        temp_4_3 = *(s32 *)((u8 *)temp_2 + 0x34);
        if (temp_4_3 != 0) {
            func_00452080(temp_4_3);
            *(s32 *)((u8 *)temp_2 + 0x34) = 0;
        }
        temp_16 += 1;
    }
    func_003e9df0(*(s32 *)(func_00457120() + 4));
    KFIELD_JTBL_008873EC(*(s32 *)(arg0 + 0x38));
}
#else
INCLUDE_ASM("asm/nonmatchings/k_field", func_00155bf0);
#endif

// FUN_00155E10
INCLUDE_ASM("asm/nonmatchings/k_field", func_00155e10);
