#include "include_asm.h"
/* Persona 4 USA decompilation - evtLoadSave.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"

typedef struct { u8 c[4]; } Rgba8;
typedef struct { s16 a; s16 b; s16 c; s16 d; } S16x4;


extern u8 *func_00286780(u8 *, u16, u8 *);
extern void func_00294610(u8 *, u8 *, s32);
extern s32 func_00291980(s32, s32, s32 *, s32 *);
extern s32 func_00477f10(s32, u16, s32, s32, s32);
extern void func_0047aa30(s32, u8 *);
extern s32 func_002919d0(s32);
extern u16 func_00145780(u16, s32, s32);
extern void func_00269c20(u16, s32);
extern void func_00146e60(u16, f32 *, s32);
extern u16 *func_00145270(u16);
extern void func_0046d730(u8 *, s32);
extern void func_00286ff0(u8 *, u16, u16 *);
extern u8 *func_0047a250(s32);
extern u8 *func_00286f00(s32, u8 *);
extern void func_0028d110(u8 *);
extern void func_0043f810(u8 *, u8 *, s32);
extern u8 D_005DC7D0[];
extern u8 D_005DC878[];
extern u8 D_0063CAB0[];

// FUN_00294610
void func_00294610(u8 *arg0, u8 *arg1, s32 arg2) {
    S16x4 sp48;
    s16 *coord;
    s32 temp_3;
    s16 temp_9;
    s16 temp_8;
    s16 temp_7;
    s16 temp_10;
    s32 type;
    s32 type2;
    s32 v38;
    s32 v40;
    s32 v16;
    s32 v28;
    s32 v2A;
    u8 *q;

    temp_3 = arg2 * 0x3C;
    coord = &temp_9;
    *coord = *(s16 *)((u32)temp_3 + (u32)*(s32 *)(arg0 + 0x98) + 0xC);
    coord = &temp_8;
    *coord = *(s16 *)(*(s32 *)(arg0 + 0x98) + temp_3 + 0xE);
    coord = &temp_7;
    *coord = *(s16 *)(*(s32 *)(arg0 + 0x98) + temp_3 + 0x10);
    coord = &temp_10;
    *coord = *(s16 *)(*(s32 *)(arg0 + 0x98) + temp_3 + 0x12);
    sp48.a = temp_9;
    sp48.b = temp_8;
    sp48.c = temp_7;
    sp48.d = temp_10;
    *(S16x4 *)(arg1 + 8) = sp48;
    if (*(s32 *)(*(s32 *)(arg0 + 0x80) + 0x14) == 4) {
        q = (u8 *)(*(s32 *)(arg0 + 0x94) + (arg2 * 0x10) + 8);
    } else {
        q = (u8 *)(*(s32 *)(arg0 + 0x98) + temp_3 + 0x14);
    }
    *(s8 *)(arg1 + 0x10) = *(s8 *)q;
    if (*(s32 *)(*(s32 *)(arg0 + 0x80) + 0x14) == 4) {
        q = (u8 *)(*(s32 *)(arg0 + 0x94) + (arg2 * 0x10) + 8);
    } else {
        q = (u8 *)(*(s32 *)(arg0 + 0x98) + temp_3 + 0x14);
    }
    *(s32 *)(arg1 + 0x14) = *(s32 *)(q + 4);
    if (*(s32 *)(*(s32 *)(arg0 + 0x80) + 0x14) == 4) {
        q = (u8 *)(*(s32 *)(arg0 + 0x94) + (arg2 * 0x10) + 8);
    } else {
        q = (u8 *)(*(s32 *)(arg0 + 0x98) + temp_3 + 0x14);
    }
    *(s32 *)(arg1 + 0x18) = *(s32 *)(q + 8);
    if (*(s32 *)(*(s32 *)(arg0 + 0x80) + 0x14) == 4) {
        q = (u8 *)(*(s32 *)(arg0 + 0x94) + (arg2 * 0x10) + 8);
    } else {
        q = (u8 *)(*(s32 *)(arg0 + 0x98) + temp_3 + 0x14);
    }
    *(s32 *)(arg1 + 0x1C) = *(s32 *)(q + 0xC);
    if (*(s32 *)(*(s32 *)(arg0 + 0x80) + 0x14) == 4) {
        q = (u8 *)(*(s32 *)(arg0 + 0x94) + (arg2 * 0x10) + 8);
    } else {
        q = (u8 *)(*(s32 *)(arg0 + 0x98) + temp_3 + 0x14);
    }
    *(s32 *)(arg1 + 0x20) = *(s32 *)(q + 0x10);
    if (*(s32 *)(*(s32 *)(arg0 + 0x80) + 0x14) == 4) {
        q = (u8 *)(*(s32 *)(arg0 + 0x94) + (arg2 * 0x10) + 8);
    } else {
        q = (u8 *)(*(s32 *)(arg0 + 0x98) + temp_3 + 0x14);
    }
    *(s32 *)(arg1 + 0x24) = *(s32 *)(q + 0x14);
    if (*(s32 *)(*(s32 *)(arg0 + 0x80) + 0x14) == 4) {
        q = (u8 *)(*(s32 *)(arg0 + 0x94) + (arg2 * 0x10) + 8);
    } else {
        q = (u8 *)(*(s32 *)(arg0 + 0x98) + temp_3 + 0x14);
    }
    *(s32 *)(arg1 + 0x28) = *(s32 *)(q + 0x18);
    if (*(s32 *)(*(s32 *)(arg0 + 0x80) + 0x14) == 4) {
        q = (u8 *)(*(s32 *)(arg0 + 0x94) + (arg2 * 0x10) + 8);
    } else {
        q = (u8 *)(*(s32 *)(arg0 + 0x98) + temp_3 + 0x14);
    }
    *(s32 *)(arg1 + 0x2C) = *(s32 *)(q + 0x1C);
    v38 = *(s32 *)(arg1 + 0x38);
    if (v38 == 1) {
        *(s32 *)(arg1 + 0x30) = 0;
    } else if (v38 == 0x30) {
        if (*(s32 *)(*(s32 *)(arg0 + 0x80) + 0x14) == 4) {
            q = (u8 *)(*(s32 *)(arg0 + 0x94) + (arg2 * 0x10) + 8);
        } else {
            q = (u8 *)(*(s32 *)(arg0 + 0x98) + temp_3 + 0x14);
        }
        *(s32 *)(arg1 + 0x30) = *(s32 *)(q + 0x20);
    }
    type2 = *(s32 *)(*(s32 *)(arg0 + 0x80) + 0x14);
    if (type2 < 0xC) {
        if (*(s32 *)(arg1 + 0x38) == 1) {
            if (type2 == 4) {
                q = (u8 *)(*(s32 *)(arg0 + 0x94) + (arg2 * 0x10) + 8);
            } else {
                q = (u8 *)(*(s32 *)(arg0 + 0x98) + temp_3 + 0x14);
            }
            *(s32 *)(arg1 + 0x34) = *(s32 *)(q + 0x20);
        }
    } else {
        if (type2 == 4) {
            q = (u8 *)(*(s32 *)(arg0 + 0x94) + (arg2 * 0x10) + 8);
        } else {
            q = (u8 *)(*(s32 *)(arg0 + 0x98) + temp_3 + 0x14);
        }
        *(s32 *)(arg1 + 0x34) = *(s32 *)(q + 0x24);
    }
    *(s32 *)(arg1 + 4) = -1;
    switch (*(s8 *)(arg1 + 0x10)) {
    case 1:
        switch (*(s8 *)(arg1 + 0x14)) {
        case 1:
            v16 = *(s16 *)(temp_3 + (s32)*(s32 *)(arg0 + 0x98) + 0xA);
            func_0028d110(arg1);
            if (*(s32 *)(arg1 + 0x40) == 0) {
                func_0046d730(D_0063CAB0, 0x726);
            }
            func_0043f810((u8 *)(*(s32 *)(arg1 + 0x40)), (u8 *)(*(s32 *)(arg0 + 0x60) + (v16 * 0x130)), 0x130);
            break;
        }
        break;
    case 2:
        v28 = *(s16 *)(arg1 + 0x28);
        if ((v28 < 0) || (v28 > 0x1F4)) {
            *(s16 *)(arg1 + 0x28) = 0x64;
        }
        v2A = *(s16 *)(arg1 + 0x2A);
        if ((v2A < 0) || (v2A > 0x1F4)) {
            *(s16 *)(arg1 + 0x2A) = 0x64;
        }
        break;
    default:
        break;
    }
}

// FUN_00294A90
void func_00294a90(u8 *arg0, u8 *arg1, u8 *arg2, u16 arg3) {
    s32 i;
    s32 type;
    u16 var_4;
    u16 var_2;
    s32 count;
    s32 off;
    u8 *temp_5;

    if ((arg0 == NULL) || (arg2 == NULL)) {
        return;
    }
    count = arg3 & 0xFFFF;
    if (count != 0) {
        for (i = 0; i < *(s32 *)(arg0 + 0xAC); i++) {
            type = *(s32 *)(*(s32 *)(arg0 + 0x80) + 0x14);
            if (type == 4) {
                var_4 = *(u16 *)(*(s32 *)(arg0 + 0x94) + (i * 0x10));
            } else {
                var_4 = *(u16 *)(*(s32 *)(arg0 + 0x98) + (i * 0x3C));
            }
            if ((var_4 & 0xFFFF) == 1) {
                off = i * 0x3C;
                temp_5 = (u8 *)((s32)(*(s32 *)(arg0 + 0x98)) + off);
                if (count == *(u16 *)(temp_5 + 8)) {
                    if (type == 4) {
                        var_2 = *(u16 *)(*(s32 *)(arg0 + 0x94) + (i * 0x10) + 2);
                    } else {
                        var_2 = *(u16 *)(temp_5 + 2);
                    }
                    func_00294610(arg0, func_00286780(arg2, var_2 & 0xFFFF, arg1), i);
                }
            }
        }
    }
}

/* measured: resource setup and tag-0x21 field-copy reconstruction was
   attempted in plain C; best candidate measured nd 861 with object 1384B
   against the 1504B retail window. Saved-register assignment, stack layout,
   and repeated source-branch structure remain substantially different; skip
   rather than leave a non-byte-exact body. */
// FUN_00294BE0
INCLUDE_ASM("asm/nonmatchings/evtLoadSave", func_00294be0);

// FUN_002951C0
void func_002951c0(u8 *arg0, u8 *arg1) {
    u8 *arr[3];
    S16x4 sp58;
    s16 *coord;
    s32 i;
    s32 type;
    s32 idx;
    u16 id;
    u16 var_2;
    s32 temp_3;
    s16 temp_6;
    s16 temp_5_2;
    s16 temp_4;
    s16 temp_7_2;
    u8 *p;
    u8 *dest;
    u8 *q;

    for (i = 0; i < 3; i++) {
        arr[i] = func_00286f00(0x24, arg1);
        *(s32 *)(arr[i] + 8) = -1;
        *(s32 *)(arr[i] + 0x34) = 0;
        *(s32 *)(arr[i] + 4) = i;
    }
    for (i = 0; i < *(s32 *)(arg0 + 0xAC); i++) {
        type = *(s32 *)(*(s32 *)(arg0 + 0x80) + 0x14);
        if (type == 4) {
            id = *(u16 *)(*(s32 *)(arg0 + 0x94) + (i * 0x10));
        } else {
            id = *(u16 *)(*(s32 *)(arg0 + 0x98) + (i * 0x3C));
        }
        if ((id & 0xFFFF) == 0x24) {
            if (type == 4) {
                p = (u8 *)(*(s32 *)(arg0 + 0x94) + (i * 0x10) + 8);
            } else {
                p = (u8 *)(*(s32 *)(arg0 + 0x98) + (i * 0x3C) + 0x14);
            }
            idx = *(s8 *)(p + 1);
            if (type == 4) {
                var_2 = *(u16 *)(*(s32 *)(arg0 + 0x94) + (i * 0x10) + 2);
            } else {
                var_2 = *(u16 *)(*(s32 *)(arg0 + 0x98) + (i * 0x3C) + 2);
            }
            dest = func_00286780(arr[idx], var_2 & 0xFFFF, arg1);
            temp_3 = i * 0x3C;
            coord = &temp_6;
            *coord = *(s16 *)(*(s32 *)(arg0 + 0x98) + temp_3 + 0xC);
            coord = &temp_5_2;
            *coord = *(s16 *)(*(s32 *)(arg0 + 0x98) + temp_3 + 0xE);
            coord = &temp_4;
            *coord = *(s16 *)(*(s32 *)(arg0 + 0x98) + temp_3 + 0x10);
            coord = &temp_7_2;
            *coord = *(s16 *)(*(s32 *)(arg0 + 0x98) + temp_3 + 0x12);
            sp58.a = temp_6;
            sp58.b = temp_5_2;
            sp58.c = temp_4;
            sp58.d = temp_7_2;
            *(S16x4 *)(dest + 8) = sp58;
            if (*(s32 *)(*(s32 *)(arg0 + 0x80) + 0x14) == 4) {
                q = (u8 *)(*(s32 *)(arg0 + 0x94) + (i * 0x10) + 8);
            } else {
                q = (u8 *)(*(s32 *)(arg0 + 0x98) + temp_3 + 0x14);
            }
            *(s32 *)(dest + 0x10) = *(s32 *)q;
            if (*(s32 *)(*(s32 *)(arg0 + 0x80) + 0x14) == 4) {
                q = (u8 *)(*(s32 *)(arg0 + 0x94) + (i * 0x10) + 8);
            } else {
                q = (u8 *)(*(s32 *)(arg0 + 0x98) + temp_3 + 0x14);
            }
            *(s32 *)(dest + 0x14) = *(s32 *)(q + 4);
            if (*(s32 *)(*(s32 *)(arg0 + 0x80) + 0x14) == 4) {
                q = (u8 *)(*(s32 *)(arg0 + 0x94) + (i * 0x10) + 8);
            } else {
                q = (u8 *)(*(s32 *)(arg0 + 0x98) + temp_3 + 0x14);
            }
            *(s32 *)(dest + 0x18) = *(s32 *)(q + 8);
            if (*(s32 *)(*(s32 *)(arg0 + 0x80) + 0x14) == 4) {
                q = (u8 *)(*(s32 *)(arg0 + 0x94) + (i * 0x10) + 8);
            } else {
                q = (u8 *)(*(s32 *)(arg0 + 0x98) + temp_3 + 0x14);
            }
            *(s32 *)(dest + 0x1C) = *(s32 *)(q + 0xC);
            if (*(s32 *)(*(s32 *)(arg0 + 0x80) + 0x14) == 4) {
                q = (u8 *)(*(s32 *)(arg0 + 0x94) + (i * 0x10) + 8);
            } else {
                q = (u8 *)(*(s32 *)(arg0 + 0x98) + temp_3 + 0x14);
            }
            *(s32 *)(dest + 0x20) = *(s32 *)(q + 0x10);
        }
    }
}

/* measured: taking the address of each coordinate local before its load reproduces retail's grouped lh x4 then stack sh x4, reducing normalized_diff 20 -> 2 with object 592/592. Remaining checklist-1 residual is the clamp compare register: candidate slti $v1,$v1,0x1f5; bnez $v1,... versus retail slti $at,$v1,0x1f5; bnez $at,.... Nested/positive-arm/continue forms, >0x1F4, and s16 local probes did not change it. Committed at nd 2. */
// FUN_002954F0 NONMATCHING
#ifdef NON_MATCHING
void func_002954f0(u8 *arg0, u8 *arg1) {
    u8 *temp_17;
    S16x4 sp58;
    s16 *coord;
    s32 temp_3;
    s32 var_16;
    s32 temp_5;
    u16 var_2;
    u16 var_3;
    s16 temp_6;
    s16 temp_5_2;
    s16 temp_4;
    s16 temp_7_2;
    u8 *temp_2;
    u8 *var_3_2;
    s32 *var_4;
    u8 *var_4_2;
    s32 temp_3_2;

    temp_17 = (u8 *)(func_00286f00(0x2F, arg1));
    for (var_16 = 0; var_16 < *(s32 *)(arg0 + 0xAC); var_16++) {
        temp_5 = (s32)(*(s32 *)(*(s32 *)(arg0 + 0x80) + 0x14));
        if (temp_5 == 4) {
            var_3 = *(u16 *)(*(s32 *)(arg0 + 0x94) + (var_16 * 0x10));
        } else {
            var_3 = *(u16 *)(*(s32 *)(arg0 + 0x98) + (var_16 * 0x3C));
        }
        if ((var_3 & 0xFFFF) == 0x2F) {
            if (temp_5 == 4) {
                var_2 = *(u16 *)(*(s32 *)(arg0 + 0x94) + (var_16 * 0x10) + 2);
            } else {
                var_2 = *(u16 *)(*(s32 *)(arg0 + 0x98) + (var_16 * 0x3C) + 2);
            }
            temp_2 = (u8 *)(func_00286780(temp_17, var_2 & 0xFFFF, arg1));
            temp_3 = var_16 * 0x3C;
            coord = &temp_6;
            *coord = *(s16 *)(*(s32 *)(arg0 + 0x98) + temp_3 + 0xC);
            coord = &temp_5_2;
            *coord = *(s16 *)(*(s32 *)(arg0 + 0x98) + temp_3 + 0xE);
            coord = &temp_4;
            *coord = *(s16 *)(*(s32 *)(arg0 + 0x98) + temp_3 + 0x10);
            coord = &temp_7_2;
            *coord = *(s16 *)(*(s32 *)(arg0 + 0x98) + temp_3 + 0x12);
            sp58.a = temp_6;
            sp58.b = temp_5_2;
            sp58.c = temp_4;
            sp58.d = temp_7_2;
            *(S16x4 *)(temp_2 + 8) = sp58;
            if (*(s32 *)(*(s32 *)(arg0 + 0x80) + 0x14) == 4) {
                var_4 = (s32 *)(*(s32 *)(arg0 + 0x94) + (var_16 * 0x10) + 8);
            } else {
                var_4 = (s32 *)(*(s32 *)(arg0 + 0x98) + temp_3 + 0x14);
            }
            *(s32 *)(temp_2 + 0x10) = *(s32 *)var_4;
            if (*(s32 *)(*(s32 *)(arg0 + 0x80) + 0x14) == 4) {
                var_4_2 = (u8 *)(*(s32 *)(arg0 + 0x94) + (var_16 * 0x10) + 8);
            } else {
                var_4_2 = (u8 *)(*(s32 *)(arg0 + 0x98) + temp_3 + 0x14);
            }
            *(s32 *)(temp_2 + 0x14) = *(s32 *)(var_4_2 + 4);
            if (*(s32 *)(*(s32 *)(arg0 + 0x80) + 0x14) == 4) {
                var_3_2 = (u8 *)(*(s32 *)(arg0 + 0x94) + (var_16 * 0x10) + 8);
            } else {
                var_3_2 = (u8 *)(*(s32 *)(arg0 + 0x98) + temp_3 + 0x14);
            }
            *(s32 *)(temp_2 + 0x18) = *(s32 *)(var_3_2 + 8);
            if (*(s8 *)(temp_2 + 0x10) == 1) {
                temp_3_2 = *(s16 *)(temp_2 + 0x1A);
                if ((temp_3_2 < 0) || (temp_3_2 >= 0x1F5)) {
                    *(s16 *)(temp_2 + 0x1A) = 0x64;
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/evtLoadSave", func_002954f0);
#endif

// FUN_00295740
void func_00295740(s32 arg0, u8 *arg1) {
    s32 sp6C;
    s32 sp68;
    struct {
        f32 x;
        s32 y;
        f32 z;
    } sp58;
    s32 temp_17;
    s32 temp_2;
    s32 temp_2_2;
    s8 temp_5;
    u16 *temp_2_3;
    u16 temp_16;
    u8 *temp_2_4;

    temp_5 = (s8)arg1[0x1E];
    if (temp_5 >= 0) {
        temp_2 = func_00291980(arg0, temp_5, &sp68, (s32 *)&sp6C);
        if (temp_2 != 0) {
            temp_17 = func_00477f10(5, (u16)sp6C, temp_2, sp68, 1);
            if (*(s8 *)(arg1 + 0x1F) & 1) {
                func_0047aa30(temp_17, D_005DC7D0);
            } else {
                func_0047aa30(temp_17, D_005DC878);
            }
            temp_16 = (u16)(func_00145780((u16)(func_002919d0(*(s32 *)(arg1 + 4)) & 0xFFFF), 0, temp_17) & 0xFFFF);
            func_00269c20(temp_16, 1);
            temp_2_2 = (s32)(*(s32 *)(arg1 + 4) * 0x1E);
            sp58.x = (f32)temp_2_2;
            sp58.y = 0;
            sp58.z = (f32)-temp_2_2;
            func_00146e60(temp_16, &sp58.x, 0);
            temp_2_3 = (u16 *)(func_00145270(temp_16));
            if (temp_2_3 == NULL) {
                func_0046d730(D_0063CAB0, 0x9C5);
            }
            func_00286ff0(arg1, temp_16, temp_2_3);
            temp_2_4 = (u8 *)(func_0047a250(temp_17));
            *(Rgba8 *)(arg1 + 0x50) = *(Rgba8 *)(temp_2_4);
            return;
        }
        func_00286ff0(arg1, 0U, NULL);
    }
}

// FUN_00295B80
void func_00295b80(u8 *arg0, u8 *arg1) {
    u8 *arr[3];
    S16x4 sp58;
    s32 i;
    s32 type;
    u16 id;
    u8 *entry;
    u8 *var_2;
    u16 var_2_2;
    u8 *temp_2_2;
    s32 temp_8;
    s32 temp_7;
    s16 temp_5;
    s16 temp_4;
    s16 temp_3_2;
    s16 temp_6_2;
    s16 *q;
    s32 idx;

    for (i = 0; i < 3; i++) {
        arr[i] = func_00286f00(0x34, arg1);
        *(s32 *)(arr[i] + 8) = -1;
        *(s32 *)(arr[i] + 0x34) = 0;
        *(s32 *)(arr[i] + 4) = i;
    }
    for (i = 0; i < *(s32 *)(arg0 + 0xAC); i++) {
        type = *(s32 *)(*(s32 *)(arg0 + 0x80) + 0x14);
        if (type == 4) {
            id = *(u16 *)(*(s32 *)(arg0 + 0x94) + (i * 0x10));
        } else {
            id = *(u16 *)(*(s32 *)(arg0 + 0x98) + (i * 0x3C));
        }
        if ((id & 0xFFFF) == 0x34) {
            if (type == 4) {
                var_2 = (u8 *)(*(s32 *)(arg0 + 0x94) + (i * 0x10) + 8);
            } else {
                var_2 = (u8 *)(*(s32 *)(arg0 + 0x98) + (i * 0x3C) + 0x14);
            }
            if (type == 4) {
                var_2_2 = *(u16 *)(*(s32 *)(arg0 + 0x94) + (i * 0x10) + 2);
            } else {
                var_2_2 = *(u16 *)(*(s32 *)(arg0 + 0x98) + (i * 0x3C) + 2);
            }
            idx = (u8)(*(u8 *)(var_2 + 2)) >> 4;
            temp_2_2 = func_00286780(arr[idx], var_2_2 & 0xFFFF, arg1);
            temp_8 = i * 0x10;
            temp_7 = i * 0x3C;
            entry = (u8 *)(*(s32 *)(arg0 + 0x98) + temp_7);
            q = &temp_5;
            *q = *(s16 *)(entry + 0xC);
            q = &temp_4;
            *q = *(s16 *)(entry + 0xE);
            q = &temp_3_2;
            *q = *(s16 *)(entry + 0x10);
            q = &temp_6_2;
            *q = *(s16 *)(entry + 0x12);
            sp58.a = temp_5;
            sp58.b = temp_4;
            sp58.c = temp_3_2;
            sp58.d = temp_6_2;
            *(S16x4 *)(temp_2_2 + 8) = sp58;
            if (*(s32 *)(*(s32 *)(arg0 + 0x80) + 0x14) == 4) {
                var_2 = (u8 *)(*(s32 *)(arg0 + 0x94) + temp_8 + 8);
            } else {
                var_2 = (u8 *)(*(s32 *)(arg0 + 0x98) + temp_7 + 0x14);
            }
            func_0043f810(temp_2_2 + 0x10, var_2, 0x28);
        }
    }
}

// FUN_00295910
void func_00295910(u8 *arg0, u8 *arg1) {
    u8 *temp_2;
    u8 *var_5;
    u8 *var_4;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 var_19;
    s32 var_20;
    s32 var_19_2;
    s32 off2;
    s32 var_3_3;
    u16 var_2;
    u16 var_3;
    u8 *var_3_2;

    for (var_20 = 0; var_20 < 8; var_20++) {
        temp_2 = (u8 *)(func_00286f00(0x30, arg1));
        *(s32 *)(temp_2 + 4) = var_20;
        for (var_19 = 0; var_19 < *(s32 *)(arg0 + 0xAC); var_19++) {
            temp_2_2 = (s32)(*(s32 *)(*(s32 *)(arg0 + 0x80) + 0x14));
            if (temp_2_2 == 4) {
                var_3 = *(u16 *)(*(s32 *)(arg0 + 0x94) + (var_19 * 0x10));
            } else {
                var_3 = *(u16 *)(*(s32 *)(arg0 + 0x98) + (var_19 * 0x3C));
            }
            if ((var_3 & 0xFFFF) == 0x30) {
                if (temp_2_2 == 4) {
                    var_3_2 = (u8 *)(*(s32 *)(arg0 + 0x94) + (var_19 * 0x10) + 8);
                } else {
                    var_3_2 = (u8 *)(*(s32 *)(arg0 + 0x98) + (var_19 * 0x3C) + 0x14);
                }
                if (*(s32 *)(temp_2 + 4) == *(s8 *)(var_3_2 + 0x20)) {
                    if (temp_2_2 == 4) {
                        var_2 = *(u16 *)(*(s32 *)(arg0 + 0x94) + (var_19 * 0x10) + 2);
                    } else {
                        var_2 = *(u16 *)(*(s32 *)(arg0 + 0x98) + (var_19 * 0x3C) + 2);
                    }
                    func_00294610(arg0, func_00286780(temp_2, var_2 & 0xFFFF, arg1), var_19);
                }
            }
        }
        if (*(s32 *)(arg0 + 0x100) != 0) {
            for (var_19_2 = 0; var_19_2 < *(s32 *)(arg0 + 0x104); var_19_2++) {
                off2 = var_19_2 * 0x14;
                var_5 = (u8 *)((s32)*(s32 *)(arg0 + 0x100) + off2);
                if (*(s16 *)(var_5 + 2) != -1) {
                    func_0046d730(D_0063CAB0, 0x822);
                    continue;
                }
                if ((*(s32 *)(temp_2 + 0) == *(u8 *)(var_5 + 0)) && (*(s32 *)(temp_2 + 4) == *(u8 *)(var_5 + 1))) {
                    var_4 = temp_2 + 0x18;
                    var_3_3 = 5;
                    do {
                        temp_2_3 = *(s32 *)var_5;
                        var_5 += 4;
                        var_3_3 -= 1;
                        *(s32 *)var_4 = temp_2_3;
                        var_4 += 4;
                    } while (var_3_3 > 0);
                    break;
                }
            }
        }
        func_00295740((s32)arg1, temp_2);
    }
}

/* measured: the plain-C reconstruction of the three outer tag-0xA objects,
   nested source dispatch, coordinate copy, and descriptor search scored best
   at nd 788 with object 1312B against the 1344B retail window. The candidate
   still had a short 0x80 frame versus retail 0x90 and different saved-register
   and coordinate stack-load/store structure; skip rather than preserve it. */
// FUN_00295DB0
INCLUDE_ASM("asm/nonmatchings/evtLoadSave", func_00295db0);


