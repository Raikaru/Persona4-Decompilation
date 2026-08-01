/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_002818A0)
#include "type.h"

s32 *func_0027be60(void);

// FUN_002818A0
void func_002818a0(u32 arg0, s32 arg1) {
    s32 *temp_2;

    temp_2 = func_0027be60();
    if (temp_2 != NULL) {
        *temp_2 = arg1;
    }
}
#endif /* P4_UNIT_002818A0 */

#if defined(P4_UNIT_00285980)
#include "type.h"

void func_00452080(s32 arg0);
s32 *func_00452560(void);
extern void (*jtbl_008873EC[])(void *);
void func_002852a0(s32 arg0, s32 arg1);

// FUN_00285980
void func_00285980(void) {
    s32 *temp_2;

    temp_2 = func_00452560();
    func_00452080(*(s32 *)((u8 *)temp_2 + 0xC));
    jtbl_008873EC[0](temp_2);
    func_002852a0(0, -0x60);
}
#endif /* P4_UNIT_00285980 */

#if defined(P4_UNIT_00285AF0)
#include "type.h"

s32 func_00452380(void *arg0);
extern s32 D_0063C2F8[];
void func_002853c0(void);

// FUN_00285AF0
void func_00285af0(void) {
    if (func_00452380(D_0063C2F8) == 0) {
        func_002853c0();
    }
}
#endif /* P4_UNIT_00285AF0 */

#if defined(P4_UNIT_00286350)
#include "type.h"

s32 func_00452380(void *arg0);
extern s32 D_0063C368[];

// FUN_00286350
void func_00286350(void) {
    func_00452380(D_0063C368);
}
#endif /* P4_UNIT_00286350 */

#if defined(P4_UNIT_002863E0)
#include "type.h"

s32 *func_00452560(void);

// FUN_002863E0
void func_002863e0(u32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 *temp_2;

    temp_2 = func_00452560();
    *(s32 *)((u8 *)temp_2 + 0x78C) = arg1;
    *(s32 *)((u8 *)temp_2 + 0x790) = arg2;
    *(s32 *)((u8 *)temp_2 + 0x794) = arg3;
}
#endif /* P4_UNIT_002863E0 */

#if defined(P4_UNIT_002865E0)
#include "type.h"

void func_0043f9c8(void *arg0, s32 arg1, s32 arg2);
void func_00285260(void);

typedef struct {
    u8 pad[0x76C];
    s32 field_76C[15];
} UnkStruct_002865E0;

// FUN_002865E0
void func_002865e0(UnkStruct_002865E0 *arg0) {
    s32 sp30[15];
    s32 *var_5;
    s32 *var_4;
    s32 *var_5_2;
    s32 *var_4_2;
    s32 temp_17;
    s32 temp_2;
    s32 temp_2_2;
    s32 var_3;
    s32 var_3_2;

    var_5 = arg0->field_76C;
    var_4 = sp30;
    var_3 = 0xF;
    do {
        temp_2 = *var_5;
        var_5++;
        var_3--;
        *var_4 = temp_2;
        var_4++;
    } while (var_3 > 0);
    temp_17 = *(s32 *)((u8 *)arg0 + 0);
    func_0043f9c8(arg0, 0, 0x7B0);
    var_5_2 = sp30;
    var_4_2 = (s32 *)((u8 *)arg0 + 0x76C);
    var_3_2 = 0xF;
    do {
        temp_2_2 = *var_5_2;
        var_5_2++;
        var_3_2--;
        *var_4_2 = temp_2_2;
        var_4_2++;
    } while (var_3_2 > 0);
    *(s32 *)((u8 *)arg0 + 0) = temp_17;
    func_00285260();
    *(s32 *)((u8 *)arg0 + 0) |= 1;
    *(s32 *)((u8 *)arg0 + 8) = 0x21C;
    *(s32 *)((u8 *)arg0 + 0x10) = *(s32 *)((u8 *)arg0 + 8) - 1;
    if (*(s32 *)((u8 *)arg0 + 0) & 0x80000000) {
        *(s32 *)((u8 *)arg0 + 0x54) = 1;
    }
}
#endif /* P4_UNIT_002865E0 */

#if defined(P4_UNIT_00287BF0)
#include "type.h"

s32 func_00286430(u8 *arg0);

// FUN_00287BF0
void func_00287bf0(s32 arg0, u8 *arg1) {
    u8 *var_17;
    u8 *var_16;
    u16 temp_4;

    var_17 = *(u8 **)(arg1 + 0x4C);
    while (var_17 != NULL) {
        if (*(s32 *)var_17 == 0x26) {
            var_16 = *(u8 **)(var_17 + 0x68);
            while (var_16 != NULL) {
                if (func_00286430(var_16) != 0) {
                    temp_4 = *(u16 *)var_16;
                    if (((s32)temp_4 <= arg0) && ((temp_4 + *(s16 *)(var_16 + 0x12)) >= arg0)) {
                        *(s32 *)(arg1 + 0x20) = *(s16 *)(var_16 + 0x10);
                        *(s32 *)(arg1 + 0x1C) = 1;
                        return;
                    }
                }
                var_16 = *(u8 **)(var_16 + 0x4C);
            }
        }
        var_17 = *(u8 **)(var_17 + 0x90);
    }
}
#endif /* P4_UNIT_00287BF0 */

#if defined(P4_UNIT_0028D020)
#include "type.h"

extern s32 D_008825F0[10];

// FUN_0028D020
void func_0028d020(s32 arg0, s32 arg1) {
    if ((arg0 >= 0xA) || (arg0 < 0)) {
        return;
    }
    D_008825F0[arg0] = arg1;
}
#endif /* P4_UNIT_0028D020 */

#if defined(P4_UNIT_0028D060)
#include "type.h"

extern s32 D_008825F0[10];

// FUN_0028D060
s32 func_0028d060(s32 arg0) {
    if (arg0 >= 0xA) {
        return -1;
    }
    return D_008825F0[arg0];
}
#endif /* P4_UNIT_0028D060 */

#if defined(P4_UNIT_0028D310)
#include "type.h"

s32 *func_00452560(void);
void func_004ab680(s32 arg0);
void func_004ab140(s32 arg0);
extern void (*jtbl_008873EC[])(void *);

// FUN_0028D310
void func_0028d310(void) {
    s32 *temp_2;
    s32 temp_3;

    temp_2 = func_00452560();
    temp_3 = temp_2[0];
    switch (temp_3) {
    case 0:
        func_004ab680(temp_2[1]);
        break;
    case 1:
        func_004ab140(temp_2[1]);
        break;
    }
    jtbl_008873EC[0](temp_2);
}
#endif /* P4_UNIT_0028D310 */
