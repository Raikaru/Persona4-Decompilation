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

/* measured: retail groups the 4 s16 field loads (lh x4 into $t1/$t0/$a3/$t2)
   before the 4 stack stores (sh x4); mwcc b210 sinks each load to its
   struct-field store (lh;sh;lh;sh;lh;sh;lh;sh) — nd 8, the only residual in an
   otherwise byte-exact 1152B function. Same mechanism and nd as the
   func_00295b80/002954f0/002951c0 floors; all struct/scalar/temp spellings give
   nd 8. Load-sinking floor. */
// FUN_00294610
INCLUDE_ASM("asm/nonmatchings/evtLoadSave", func_00294610);

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

// FUN_00294BE0
INCLUDE_ASM("asm/nonmatchings/evtLoadSave", func_00294be0);

/* measured: retail groups the 4 s16 field loads from the entry struct (lh x4
   into $a2/$a1/$a0/$a3) before storing them to the stack temp (sh x4); mwcc
   b210 sinks each load to its struct-field store, emitting lh;sh;lh;sh;lh;sh;
   lh;sh — identical residual (nd 8) and identical mechanism to the func_00295b80
   floor. Tried: separate s16/s32 temps, direct struct-field loads, S16x4 struct
   local + value copy, struct pointer copy, compound literal, scalar locals —
   all nd 8. Load-sinking floor. */
/* measured: retail groups the 4 s16 field loads (lh x4) before the 4 stack
   stores (sh x4); mwcc b210 sinks each load to its struct-field store
   (lh;sh;lh;sh;lh;sh;lh;sh) — identical nd 8 to the func_00295b80 and
   func_002954f0 floors. Tried: separate s16/s32 temps, direct field loads,
   S16x4 struct local + value copy, struct pointer copy — all nd 8. Load-sinking
   floor. */
// FUN_002951C0
INCLUDE_ASM("asm/nonmatchings/evtLoadSave", func_002951c0);

// FUN_002954F0
INCLUDE_ASM("asm/nonmatchings/evtLoadSave", func_002954f0);

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

/* measured: retail loads the 4 s16 fields from entry+0xC..0x12 GROUPED (lh x4)
   before storing them to the stack temp (sh x4); mwcc b210 sinks each load to
   its struct-field store, emitting lh;sh;lh;sh;lh;sh;lh;sh. Tried: separate s16
   and s32 temps, direct field loads, S16x4 struct local + value copy, struct
   pointer copy, compound literal (memcpy loop), __builtin_memcpy (frame 0x90)
   — all give nd 8 with the identical interleaved pattern. Load-sinking floor;
   hoisting into locals does not move it. */
// FUN_00295B80
INCLUDE_ASM("asm/nonmatchings/evtLoadSave", func_00295b80);

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

// FUN_00295DB0
INCLUDE_ASM("asm/nonmatchings/evtLoadSave", func_00295db0);


