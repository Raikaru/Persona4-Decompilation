#include "include_asm.h"
#include "type.h"

/* gp-relative global at 0x0072467C (gp - 0x4A74): pointer to the active list. */
static u8 *iGpffffb58c;
/* gp-relative global at 0x007644C4 (gp - 0x4C2C). */
static u8 *iGpffffb3d4;

extern char D_0063FC48[];
extern char D_0063FC58[];
extern u8 *D_00882F70[];
extern s32 func_00312b60(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_00312b90(u16 *arg0, u8 *arg1, u8 *arg2, u8 *arg3);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void (*jtbl_008873EC[])(void *);

extern s32 func_002b2d00(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4);
extern void func_0044ea90(void *msg, s32 id);
extern void func_00452080(s32 handle);
extern s32 func_00451de0(const void *data, s32 a, s32 b, s32 c, s32 (*init)(u8 *),
                        void (*close)(u8 *), void *buf);
extern s32 func_00451fc0(s32 arg0, const void *data, s32 a, s32 b, s32 c,
                         s32 (*init)(u8 *), void (*close)(u8 *), u8 *buf);
extern s32 func_002e23b0(u8 *arg0);
extern s32 func_002e2410(u8 *arg0);
extern void func_002e2470(u8 *arg0);
extern s32 func_002e4090(u8 *arg0);
extern void func_002e29a0(void);
extern s8 func_002e47b0(void);
extern void func_002e4820(s8 arg0);
extern void *func_0043f9c8(void *dest, s32 value, s32 size);
extern s32 func_002e6b20(s16 *arg0, s16 *arg1);
extern s32 func_002e6630(s16 *arg0, s16 *arg1);
extern s32 func_00440bb8();
extern void *func_0010fcb0();
extern s32 func_0010aa80(s32 arg0);
extern u16 *func_0010ac10(s32 arg0);

extern void func_0010cad0(u8 *dest, u16 id);
extern s32 func_0010b5b0(void);
extern s32 func_0010abd0(s16 arg0);
extern u16 *func_0010ace0(s16 arg0);
extern s32 func_0010a900(u16 arg0);
extern void func_0010ffa0(s32 arg0);
extern s32 func_002e5270(u8 *arg0, u8 *arg1);
extern s16 func_002b2cb0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_00311d00(u16 id);
extern s32 func_00311d60(u16 id);
extern s32 func_00311e40(u16 id);
extern void func_0043f810(void *dst, void *src, u32 size);

/* 228/240 bytes; fifteen resolved relocations and twelve zero alignment bytes. */
// FUN_002E24A0
void func_002e24a0(s32 arg0, s32 arg1, s8 arg2, s8 arg3) {
    u8 *buf;

    if (iGpffffb58c != NULL) {
        func_002e29a0();
    }
    func_0044ea90(D_0063FC48, 0x67);
    buf = D_008873F4[0](1, 0x1810, 0x40000);
    iGpffffb58c = (u8 *)func_00451de0(D_0063FC58, 0xF, 0, 0, func_002e23b0,
                                       func_002e2470, buf);
    *(s32 *)(buf + 4) = arg0;
    *(s32 *)(buf + 8) = arg1;
    *(s8 *)(buf + 1) = arg2;
    *(s8 *)(buf + 0) = 1;
    *(s8 *)(buf + 0xC) = arg3;
}

// FUN_002E2590
void func_002e2590(s32 arg0, s32 arg1, s32 arg2, s8 arg3, s8 arg4) {
    u8 *buf;

    func_0044ea90(D_0063FC48, 0x82);
    buf = D_008873F4[0](1, 0x1810, 0x40000);
    func_00451fc0(arg0, D_0063FC58, 0xF, 0, 0, func_002e2410, func_002e2470,
                  buf);
    *(s32 *)(buf + 4) = arg1;
    *(s32 *)(buf + 8) = arg2;
    *(s8 *)(buf + 1) = arg3;
    *(s8 *)(buf + 0) = 1;
    *(s8 *)(buf + 0xC) = arg4;
}

// FUN_002E2670
s16 func_002e2670(void) {
    u8 *g = iGpffffb58c;

    if (g == NULL) {
        return -1;
    }
    return *(s16 *)(*(u8 **)(g + 0x38) + 2);
}

// FUN_002E26A0
s32 func_002e26a0(void) {
    u8 *g = iGpffffb58c;

    if (g == NULL) {
        return -1;
    }
    return func_002b2d00(*(s16 *)(*(u8 **)(g + 0x38) + 2), 1, 0, 0, 1);
}

// FUN_002E26F0
s16 func_002e26f0(void *arg0) {
    return *(s16 *)(*(u8 **)((u8 *)arg0 + 0x38) + 2);
}

// FUN_002E2700
void func_002e2700(void *arg0) {
    func_002b2d00(*(s16 *)(*(u8 **)((u8 *)arg0 + 0x38) + 2), 1, 0, 0, 1);
}

// FUN_002E2740
s16 func_002e2740(s32 arg0) {
    u8 *g = iGpffffb58c;
    u8 *p;
    s32 count;

    if (g == NULL) {
        return -1;
    }
    p = *(u8 **)(g + 0x38);
    if (g == NULL) {
        count = -1;
    } else {
        count = *(s16 *)(p + 2);
    }
    if (count < arg0) {
        return -1;
    }
    switch (*(s8 *)(p + 1)) {
    case 1: {
        s32 idx = arg0 * 4;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0xE);
    }
    case 2: {
        s32 idx = arg0 * 4;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0xE);
    }
    case 3: {
        s32 idx = arg0 * 2;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0xE);
    }
    case 4: {
        s32 idx = arg0 * 4;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0xE);
    }
    default:
        return -1;
    }
}

// FUN_002E2830
s16 func_002e2830(u8 *arg0, s32 arg1) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    if (*(s16 *)(p + 2) < arg1) {
        return -1;
    }
    switch (*(s8 *)(p + 1)) {
    case 1: {
        s32 idx = arg1 * 4;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0xE);
    }
    case 2: {
        s32 idx = arg1 * 4;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0xE);
    }
    case 3: {
        s32 idx = arg1 * 2;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0xE);
    }
    case 4: {
        s32 idx = arg1 * 4;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0xE);
    }
    default:
        return -1;
    }
}

// FUN_002E28F0
s16 func_002e28f0(u8 *arg0, s32 arg1) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    if (*(s16 *)(p + 2) < arg1) {
        return -1;
    }
    switch (*(s8 *)(p + 1)) {
    case 1: {
        s32 idx = arg1 * 4;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0x10);
    }
    case 2:
        return 1;
    case 3:
        return 1;
    case 4: {
        s32 idx = arg1 * 4;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0x10);
    }
    default:
        return -1;
    }
}

// FUN_002E29A0
void func_002e29a0(void) {
    u8 *g = iGpffffb58c;

    if (g != NULL) {
        func_00452080((s32)g);
        iGpffffb58c = NULL;
    }
}

// FUN_002E29D0
s8 func_002e29d0(void) {
    u8 *g = iGpffffb58c;

    if (g != NULL) {
        return *(s8 *)(*(void **)(g + 0x38));
    }
    return -1;
}

// FUN_002E2A00
s8 func_002e2a00(void *arg0) {
    return *(s8 *)(*(void **)((u8 *)arg0 + 0x38));
}

/* measured: structure fully recovered (iGpffffb58c null-check, p=e+0x38 with
   the four state stores, the descending-test switch on p->1 with the four
   0x600 loops and 4-way ok-chains, the case-2 6b20/6b50/2be160/2bdff0/1462
   chains, the 2b2cb0 count stores, the arg3==1 -1-init/compaction loops with
   10830/10810 into arr[0x600], the arg3==2 sortbuf copy + 40bb8 sort +
   re-store loops; case order 1,2,3,4 reproduces retail's descending test
   chain and ascending body layout exactly) but mwcc b210 rotates the saved
   registers: mine arg3=$s5 p=$s1 e2=$s2 i=$s0 (frame 0x3070 matches) vs
   retail arg3=$s1 p=$s0 e2=$s2 i=$s3 j=$s4 n=$s5, so every instruction in
   the six loops differs (nd 603). Tried 3 declaration orders, separate
   m/k loop counters for the arg3==1/2 blocks, a shared loop variable;
   all nd 603. Same saved-reg rotation floor as func_002e3560 (this file),
   mdlManager func_0047c660 and mdlMatAnim func_00480670. */
// FUN_002E2A10
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e2a10);

/* measured: closest clean-C probe was object 2780B over a 2864B window
   (normalized diff 639); retail frame 0x3070 and saved-register allocation
   remained different, so the archived probe is intentionally not committed. */
// FUN_002E3560
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e3560);

/* measured: de-noised m2c floor with truthful externs (0010b5b0/0010abd0/0010ace0/0010a900/0010ffa0/002e5270), s16 counters, (u16)/(void *)(u32) casts, for-loop form, iGpffffb3d4+i*0xE idiom; 74 differing words (was 310 implicit); production stays ASM. */
// FUN_002E4090 NONMATCHING
#ifdef NON_MATCHING
s32 func_002e4090(u8 *arg0) {
    u8 sp40[0x30];
    u8 sp70[0x30];
    s16 i;
    s32 tmp;
    u8 *p;
    u32 sw;
    p = *(u8 **)(arg0 + 0x38);
    if (*(s8 *)p == 1) {
        return 0;
    }
    *(s32 *)(p + 8) = 0;
    sw = *(u32 *)(p + 4);
    switch (sw) {
    case 0:
        for (i = 1; i < 0xC; i++) {
            func_0010cad0(p + ((i - 1) * 0x30) + 0x14, (u16)i);
            *(s32 *)(p + 8) += 1;
        }
        break;
    case 1:
        for (i = 0; i < (func_0010b5b0() & 0xFFFF); i++) {
            if (func_0010abd0(i) == 1) {
                func_0043f9c8(p + (*(s32 *)(p + 8) * 0x30) + 0xA4, 0, 0x30);
                func_0043f810(p + (*(s32 *)(p + 8) * 0x30) + 0xA4, (void *)(u32)func_0010ace0(i), 0x30);
                *(s32 *)(p + 8) += 1;
            }
        }
        break;
    case 2:
        for (i = 0; i < 0x100; i++) {
            if ((void *)(u32)func_0010fcb0(i) != 0) {
                func_0043f9c8(p + (*(s32 *)(p + 8) * 0x30) + 0x14, 0, 0x30);
                func_0043f810(p + (*(s32 *)(p + 8) * 0x30) + 0x14, (void *)(u32)func_0010fcb0(i), 0x30);
                *(s32 *)(p + 8) += 1;
            }
        }
        break;
    case 5:
        for (i = 0; i < (func_0010b5b0() & 0xFFFF); i++) {
            if (func_0010abd0(i) == 1) {
                tmp = func_0010a900(1);
                if (tmp != (s32)(u32)func_0010ace0(i)) {
                    func_0043f9c8(p + (*(s32 *)(p + 8) * 0x30) + 0xA4, 0, 0x30);
                    func_0043f810(p + (*(s32 *)(p + 8) * 0x30) + 0xA4, (void *)(u32)func_0010ace0(i), 0x30);
                    *(s32 *)(p + 8) += 1;
                }
            }
        }
        break;
    case 6:
        for (i = 0; i < (func_0010b5b0() & 0xFFFF); i++) {
            if (func_0010abd0(i) == 1) {
                func_0043f810(sp40, (void *)(u32)func_0010ace0(i), 0x30);
                if (*(u8 *)(iGpffffb3d4 + i * 0xE + 2) < 0x16) {
                    func_0043f810(sp70, (void *)(u32)func_0010fcb0(i), 0x30);
                    if (func_002e5270(sp40, sp70) == 1) {
                        func_0043f9c8(p + (*(s32 *)(p + 8) * 0x30) + 0xA4, 0, 0x30);
                        func_0043f810(p + (*(s32 *)(p + 8) * 0x30) + 0xA4, (void *)(u32)func_0010ace0(i), 0x30);
                        *(s32 *)(p + 8) += 1;
                    }
                }
            }
        }
        break;
    case 7:
        for (i = 1; i < 0xC0; i++) {
            func_0010cad0(p + ((i - 1) * 0x30) + 0x14, (u16)i);
            *(s32 *)(p + 8) += 1;
        }
        break;
    case 8:
        func_0010ffa0(1);
        for (i = 1; i < 0xC0; i++) {
            func_0010cad0(p + ((i - 1) * 0x30) + 0x14, (u16)i);
            *(s32 *)(p + 8) += 1;
        }
        break;
    default:
        break;
    }
    *p = 1;
    return 0;
}

#else
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e4090);
#endif

// FUN_002E45E0
void func_002e45e0(void *arg0) {
    jtbl_008873EC[0](*(void **)((u8 *)arg0 + 0x38));
}

// FUN_002E4610
void func_002e4610(s32 arg0, s8 arg1) {
    u8 *buf;
    u8 **slot;
    u8 *base;
    s16 i;
    s16 j;

    func_002e47b0();
    slot = &D_00882F70[arg1];
    if (*slot != NULL) {
        func_002e4820(arg1);
    }
    func_0044ea90(D_0063FC48, 0x38F);
    buf = D_008873F4[0](1, 0x3014, 0x40000);
    *slot = (u8 *)func_00451de0(D_0063FC58, 0xF, 0, 0, func_002e4090, (void (*)(u8 *))func_002e45e0, buf);
    buf[0] = 0;
    *(s32 *)(buf + 4) = arg0;
    *(s32 *)(buf + 8) = 0;
    switch (arg0) {
    case 1:
    case 0xA:
    case 6:
        for (i = 0; i < 0xC; i++) {
            j = 0;
            base = buf + i * 12;
            while (j < 0xC) {
                *(u8 *)(base + 0x14 + j) = 0;
                j++;
            }
        }
        break;
    default:
        break;
    }
    if (arg0 == 0xA) {
        buf[0] = 1;
    }
}
// FUN_002E47B0
s8 func_002e47b0(void) {
    s16 i = 0;
    u8 **base = D_00882F70;

    while (i < 15) {
        if (*(u8 **)((u32)base + i * 4) == NULL) {
            return (s8)i;
        }
        i++;
    }
    return -1;
}

// FUN_002E4820
void func_002e4820(s8 arg0) {
    u8 **p = &D_00882F70[arg0];

    if (*p != NULL) {
        func_00452080((s32)*p);
        *p = NULL;
    }
}

// FUN_002E4870
u8 *func_002e4870(s8 arg0) {
    return *(void **)(D_00882F70[arg0] + 0x38);
}

// FUN_002E48A0
u8 *func_002e48a0(s8 arg0, s16 arg1) {
    u8 *p = *(u8 **)(D_00882F70[arg0] + 0x38);

    switch (*(u32 *)(p + 4)) {
    case 0:
    case 2:
    case 7:
    case 8:
        return p + ((arg1 * 3) * 0x10) + 0x14;
    case 1:
    case 5:
    case 6:
    case 10:
        return p + ((arg1 * 3) * 0x10) + 0xA4;
    default:
        return p + ((arg1 * 3) * 0x10) + 0x14;
    }
}

/* measured 2026-08-08: this reconstruction is a park at object
   348B/window 352B and nd 16.  The scheduling lever is retained: the
   dispatch operations are in retail order at 0x1C..0x28 (lw pointer,
   lw type, addiu literal 6, beq), after moving the named n3=6 assignment
   into the default loop and using the direct switch expression.  The
   remaining thirteen instruction rows are scratch-register colouring only
   ($a3 versus $t0), plus retail's final zero-padding word at 0x15C:
   0x1C lw a3,38(v1) vs lw t0,38(v1); 0x20 lw a1,4(a3) vs lw a1,4(t0);
   0x24 addiu t0,zero,6 vs addiu a3,zero,6; 0x28 beq a1,t0 vs beq a1,a3;
   0x90/0xDC/0x128 addu v1,v1,a3 vs addu v1,v1,t0;
   0x12C addiu a3,v1,14 vs addiu a2,v1,14; 0x130/0x134 lw via a3 vs a2;
   0x138 addiu a3,a3,8 vs addiu a2,a2,8; 0x13C addiu t0,t0,-1 vs
   addiu a3,a3,-1; 0x14C bgtz t0 vs bgtz a3; 0x15C retail-only nop.
   Ruled out declaration order, pointer type, assignment order, integer
   base spelling, counter-first source, operand-order changes, removal of
   the named type local, removal of the early named constant, and the
   direct switch rewrite; all retained nd 19 or worsened the object.
   Committed at nd 16. */
// FUN_002E4960
void func_002e4960(u8 *arg0, s8 arg1, s16 arg2) {
 u8 *p; u8 *p0; u8 *p1; s32 n3; u8 *src; u8 *src2; s32 n; p=*(u8 **)(D_00882F70[arg1]+0x38); switch(*(s32 *)(p+4)) {
 case 0: case 7: case 8: p0=p; src=p0; src=(u8 *)(u32)src; src=(u8 *)((s32)arg2*0x30)+(u32)src; src+=0x14; n=6; do{s32 v0=*(s32*)src;s32 v1=*(s32*)(src+4);src+=8;n--;*(s32*)arg0=v0;*(s32*)(arg0+4)=v1;arg0+=8;}while(n>0);break;
 case 1: case 10: case 5: case 6: p1=p; src=p1; src=(u8 *)(u32)src; src=(u8 *)((s32)arg2*0x30)+(u32)src; src+=0xa4; n=6; do{s32 v0=*(s32*)src;s32 v1=*(s32*)(src+4);src+=8;n--;*(s32*)arg0=v0;*(s32*)(arg0+4)=v1;arg0+=8;}while(n>0);break;
 default: src2=p; src2=(u8 *)(u32)src2; src2=(u8 *)((s32)arg2*0x30)+(u32)src2; src2+=0x14; n3=6; do{s32 v0=*(s32*)src2;s32 v1=*(s32*)(src2+4);src2+=8;n3--;*(s32*)arg0=v0;*(s32*)(arg0+4)=v1;arg0+=8;}while(n3>0);break;} }





// FUN_002E4AC0 NONMATCHING
#ifdef SKIP_ASM
void func_002e4ac0(s32 arg0, s32 arg1) {
    typedef signed __int128 s128;
    s128 spE0;
    s128 spD0;
    s128 spC0;
    s128 spB0;
    s128 spA0;
    s64 var_4;
    s64 temp_30;
    s64 temp_22;
    s64 temp_23;
    s16 var_20;
    s16 var_19;
    s16 temp_18;
    s16 temp_16;
    s32 temp_7;
    s32 temp_17;
    s32 var_2;
    s32 var_2_3;
    s32 temp_2;
    u8 *temp_21;
    u8 *var_3;
    u8 *temp_5;
    u8 *var_4_2;
    u8 *var_7;
    u8 *var_2_2;
    u8 *var_4_3;
    u8 *var_5;
    u8 *var_6;
    u8 *var_7_2;

    var_4 = arg0;
    temp_21 = *(u8 **)(D_00882F70[0] + 0x38);
    var_3 = temp_21;
    temp_7 = *(s32 *)(temp_21 + 4);
    if ((temp_7 != 6) && (temp_7 != 10) && (temp_7 != 1)) {
        return;
    }
    var_20 = 0;
    temp_30 = (s64)(s8)var_4;
    temp_22 = (s64)(s8)arg1;
    temp_23 = temp_22 * 0x30;
loop_58:
    if (var_20 < *(s32 *)(var_3 + 8)) {
        temp_18 = var_20;
        *(s8 *)(temp_21 + temp_18 + 0x2E4) = 0;
        var_19 = 0;
        spE0 = (s128)(temp_18 * 12);
        spD0 = (s128)(temp_21 + temp_18 * 12);
        spC0 = (s128)&D_00882F70[temp_18 + 1];
        temp_17 = temp_18 * 0x30;
        spB0 = (s128)&D_00882F70[temp_18];
loop_56:
        var_3 = *(u8 **)(D_00882F70[0] + 0x38);
        temp_16 = var_19;
        if (temp_16 < *(s32 *)(var_3 + 8)) {
            temp_5 = (u8 *)((s32)spD0 + temp_16);
            *(s128 *)&spA0 = (s128)(s32)(temp_5 + 0x14);
            *(s8 *)(temp_5 + 0x14) = 0;
            if (temp_18 != var_19) {
                if (temp_30 == 0) {
                    u8 *temp_4 = *(u8 **)((u8 *)spC0 + 0x38);
                    switch (*(u32 *)(temp_4 + 4)) {
                    case 0: case 2: case 7: case 8:
                        var_2 = temp_16 * 0x30;
                        var_4_2 = temp_4 + var_2 + 0x14;
                        break;
                    case 1: case 5: case 6: case 10:
                        var_2 = temp_16 * 0x30;
                        var_4_2 = temp_4 + var_2 + 0xA4;
                        break;
                    default:
                        var_2 = temp_16 * 0x30;
                        var_4_2 = temp_4 + var_2 + 0x14;
                        break;
                    }
                    {
                        u8 *t32 = *(u8 **)(D_00882F70[0] + 0x38);
                        switch (*(u32 *)(t32 + 4)) {
                        case 0: case 2: case 7: case 8:
                            var_7 = t32 + temp_17 + 0x14;
                            break;
                        case 1: case 5: case 6: case 10:
                            var_7 = t32 + temp_17 + 0xA4;
                            break;
                        default:
                            var_7 = t32 + temp_17 + 0x14;
                            break;
                        }
                        {
                            switch (*(u32 *)(t32 + 4)) {
                            case 0: case 2: case 7: case 8:
                                var_2_2 = t32 + var_2 + 0x14;
                                break;
                            case 1: case 5: case 6: case 10:
                                var_2_2 = t32 + var_2 + 0xA4;
                                break;
                            default:
                                var_2_2 = t32 + var_2 + 0x14;
                                break;
                            }
                        }
                    }
                    var_4 = (s64)(s8)func_00312b60((s32)var_4_2, *(s16 *)(var_7 + 2), *(s16 *)(var_4_2 + 2));
                } else if (temp_30 == 1) {
                    if ((temp_22 == temp_18) || (temp_22 == temp_16)) {
                        var_4 = 0;
                    } else {
                        u8 *temp_42 = *(u8 **)((u8 *)spC0 + 0x38);
                        switch (*(u32 *)(temp_42 + 4)) {
                        case 0: case 2: case 7: case 8:
                            var_2_3 = temp_16 * 0x30;
                            var_4_3 = temp_42 + var_2_3 + 0x14;
                            break;
                        case 1: case 5: case 6: case 10:
                            var_2_3 = temp_16 * 0x30;
                            var_4_3 = temp_42 + var_2_3 + 0xA4;
                            break;
                        default:
                            var_2_3 = temp_16 * 0x30;
                            var_4_3 = temp_42 + var_2_3 + 0x14;
                            break;
                        }
                        {
                            u8 *t33 = *(u8 **)(D_00882F70[0] + 0x38);
                            switch (*(u32 *)(t33 + 4)) {
                            case 0: case 2: case 7: case 8:
                                var_5 = t33 + temp_23 + 0x14;
                                break;
                            case 1: case 5: case 6: case 10:
                                var_5 = t33 + temp_23 + 0xA4;
                                break;
                            default:
                                var_5 = t33 + temp_23 + 0x14;
                                break;
                            }
                            {
                                switch (*(u32 *)(t33 + 4)) {
                                case 0: case 2: case 7: case 8:
                                    var_6 = t33 + temp_17 + 0x14;
                                    break;
                                case 1: case 5: case 6: case 10:
                                    var_6 = t33 + temp_17 + 0xA4;
                                    break;
                                default:
                                    var_6 = t33 + temp_17 + 0x14;
                                    break;
                                }
                            }
                            {
                                switch (*(u32 *)(t33 + 4)) {
                                case 0: case 2: case 7: case 8:
                                    var_7_2 = t33 + var_2_3 + 0x14;
                                    break;
                                case 1: case 5: case 6: case 10:
                                    var_7_2 = t33 + var_2_3 + 0xA4;
                                    break;
                                default:
                                    var_7_2 = t33 + var_2_3 + 0x14;
                                    break;
                                }
                            }
                        }
                        var_4 = (s64)(s8)func_00312b90((u16 *)var_4_3, var_5, var_6, var_7_2);
                    }
                }
            }
            {
                u8 *t34 = (u8 *)((s32)spE0 + *(s32 *)(*(u8 **)((u8 *)spB0 + 4) + 0x38) + temp_16);
                *(s8 *)(t34 + 0x14) = 0;
                if (((s64)(s8)var_4) != 0) {
                    *(s8 *)(t34 + 0x14) = 1;
                    if (((s64)(s8)var_4) == 2) {
                        *(s8 *)(t34 + 0x14) = 2;
                    }
                }
            }
            {
                if (((s64)(s8)var_4) != 0) {
                    *(s32 *)&spA0 = 1;
                    if (((s64)(s8)var_4) == 2) {
                        *(s32 *)&spA0 = 2;
                    }
                }
            }
            var_19++;
            goto loop_56;
        }
        var_20++;
        goto loop_58;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e4ac0);
#endif

/* measured: object 604B/window 624B/normalized_diff 260 (90 differing words, fnalign per current tree). */
/* measured: saved-order dst-nextp-i-j-base-row-outer_offset plus outer-invariant row-nextp-outer_offset and for-loop form already applied per archive (103 to 90); slti-at N-A (both sides sltiu-at with a1-vs-a2 input), no 2-3-instr short tail (151 vs 152 instrs), arg-setup already fixed to 3-arg func_003129b0 with D_00882F70-zero symbol, opt_loop_invariants neutral; residual is a1-a2 slot-base plus a3-t0 outer plus v1-a3 slot2 coloring with inner-bound reload and scheduling. */
/* measured (this pass): chased the 1-instruction shortfall to its mechanism instead of
   repeating the register work. fnalign shows the only length-changing sites are
   retail[68:73]/object[68:71] (5-vs-3: retail rematerializes D_00882F70/active2/bound
   with lui+lw+lw+lw+sltiu, the build reuses a loop-carried $a1 = D[0]+0x38 with
   lw+lw+sltiu) and retail[124:127]/object[121:125] (3-vs-4: the build keeps a dead
   `addiu $a1,$v1,0x38` at the inner latch) plus one trailing alignment nop; net
   151-vs-152. The $a1 is set at the inner back-edge and consumed by the mid-body
   active2 reload with no call between, so the forward CSE is valid and retail's twin
   reloads cannot be forced from any same-iteration duplicate-load spelling. Killed
   leads, all scored by probe_variants: while+bottom-reload and reload-first (both
   141); for+body-tail and body-top reloads (141/143); commutative `0x38 + D[0]` and
   scoped opt_common_subs off around the active2 reload (both neutral at 90). Any
   change to the assignment-in-condition collapses loop codegen into the 131-143
   family (same as the recorded explicit-goto 131), so the latch sharing is
   structural. No empty if/else arm exists for the trailing-dead-arm lever: all three
   switches carry complete default paths and the call-test is a plain bne+sb. The
   90-word / 151-vs-152 / 46+6 floor stands. */
// FUN_002E5000 NONMATCHING
#ifdef NON_MATCHING
// func_002e5000 (0x002e5000-0x002e5270, 624B) — clean floor at 90 differing words.
// Retail 152 instrs, object 151 instrs (604B/624B); fnalign 46 edits plus 6 reloc-only.
// Retail relocs 15: 4x D_00882F70 HI16/LO16 pairs, 3x jtbl HI16/LO16
// (jtbl_00748C50/00748C20/00748BF0), 1x func_003129b0 R_MIPS_26. Frame 0x80 with
// s16-s22 plus ra matches; production stays INCLUDE_ASM (no TU regression).
// Source is the 108-line P4_UNIT_002E5000 M2C block de-noised: M2C_FIELD/M2C_UNK,
// s64 shift guards, s128 stack slots, loop gotos and the spurious 4th call arg
// removed; file idiom kept (u8*, *(u8 **)(...+0x38), *(s32 *)(...+4/8),
// *(u16 *)(...+2), &D_00882F70[(s8)(i+1)], 0/2/7/8 -> +0x14 / 1/5/6/10 -> +0xA4).
// Wins: saved-order dst,nextp,i,j,base,row,outer_offset (reverse-assigns to retail
// s6..s0) 103 -> 90; outer-invariant order row,nextp,outer_offset; for-loop form
// (explicit-goto variant scores 131); active temp retained (removing it scores 137).
// Neutral: ((i*3)*0x10) vs i*0x30 and ((j*3)*0x10) vs j*0x30; opt_loop_invariants on;
// temp-declaration permutations. Prior best W8 107 words (goto, split active/base2),
// IoG archive MISMATCH-nd288, WT16 shape reference. Walls: $a1/$a2 slot-base colour,
// $a3/$t0 outer colour, $v1/$a3 slot2 colour, inner-bound reload addiu, scheduling.
// Semantic gate: D_00882F70[0] is correct per retail HI16/LO16 (iGpffffb58c would be
// GPREL and is the wrong symbol); func_003129b0 takes 3 args (u8*,s32,s32) per
// src/Event/Fcl/fclCombineMisc.c — M2C's 4th arg is the dead $a3 (outer) leftover,
// not a parameter; three switches must stay switches (all three jtbl_ present);
// s16 i/j for the dsll32/dsra32 guards, u16 loads for the lhu pair. Non-goals
// func_002e2a10 / func_002e3560 untouched with their own measured notes.
extern s32 func_003129b0(u8 *arg0, s32 arg1, s32 arg2);
void func_002e5000(void) {
    u8 *dst;
    u8 **nextp;
    s16 i;
    s16 j;
    u8 *base;
    u8 *row;
    s32 outer_offset;
    s32 inner_offset;
    u8 *active;
    u8 *active2;
    u8 *slot;
    u8 *inner;
    u8 *outer;
    u8 *slot2;
    base = *(u8 **)(D_00882F70[0] + 0x38);
    active = base;
    for (i = 0; i < *(s32 *)(active + 8); i++) {
        j = 0;
        row = base + i * 0xC;
        nextp = &D_00882F70[(s8)(i + 1)];
        outer_offset = i * 0x30;
        for (; (active = *(u8 **)(D_00882F70[0] + 0x38)), j < *(s32 *)(active + 8); j++) {
            dst = row + j + 0x14;
            *dst = 0;
            slot = *(u8 **)(*nextp + 0x38);
            switch (*(s32 *)(slot + 4)) {
            case 0:
            case 2:
            case 7:
            case 8:
                inner_offset = j * 0x30;
                inner = slot + inner_offset + 0x14;
                break;
            case 1:
            case 5:
            case 6:
            case 10:
                inner_offset = j * 0x30;
                inner = slot + inner_offset + 0xA4;
                break;
            default:
                inner_offset = j * 0x30;
                inner = slot + inner_offset + 0x14;
                break;
            }
            active2 = *(u8 **)(D_00882F70[0] + 0x38);
            switch (*(s32 *)(active2 + 4)) {
            case 0:
            case 2:
            case 7:
            case 8:
                outer = active2 + outer_offset + 0x14;
                break;
            case 1:
            case 5:
            case 6:
            case 10:
                outer = active2 + outer_offset + 0xA4;
                break;
            default:
                outer = active2 + outer_offset + 0x14;
                break;
            }
            switch (*(s32 *)(active2 + 4)) {
            case 0:
            case 2:
            case 7:
            case 8:
                slot2 = active2 + inner_offset + 0x14;
                break;
            case 1:
            case 5:
            case 6:
            case 10:
                slot2 = active2 + inner_offset + 0xA4;
                break;
            default:
                slot2 = active2 + inner_offset + 0x14;
                break;
            }
            if (func_003129b0(inner, *(u16 *)(outer + 2), *(u16 *)(slot2 + 2)) == 1) {
                *dst = 1;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e5000);
#endif
// FUN_002E5270
s32 func_002e5270(u8 *arg0, u8 *arg1) {
    s16 i;
    s16 j;
    s16 k;

    if (*(u8 *)(arg0 + 4) != *(u8 *)(arg1 + 4)) {
        return 1;
    }
    for (i = 0; i < 5; i++) {
        if (*(u8 *)(arg0 + 0x1C + i) != *(u8 *)(arg1 + 0x1C + i)) {
            return 1;
        }
    }
    for (j = 0; j < 5; j++) {
        if (*(u8 *)(arg0 + 0x26 + j) != *(u8 *)(arg1 + 0x26 + j)) {
            return 1;
        }
    }
    for (k = 0; k < 8; k++) {
        if (*(u16 *)(arg0 + 0xC + k * 2) != *(u16 *)(arg1 + 0xC + k * 2)) {
            return 1;
        }
    }
    return *(u32 *)(arg0 + 8) != *(u32 *)(arg1 + 8);
}
// FUN_002E53B0
/* measured: without `opt_loop_invariants on` MWCC rematerializes the switch
   jump-table base (lui/addiu) inside the loop body instead of hoisting it into
   the preheader as retail does, giving nd 30+. */
#pragma opt_loop_invariants on
/* measured: without `opt_loop_invariants on` the switch jump-table base is
   rematerialized in the loop body instead of hoisted to the preheader (nd 30+). */
s32 func_002e53b0(s8 arg0, s16 arg1) {
    u8 **entryp = &D_00882F70[arg0];
    u8 *entry;
    u8 *p;
    u8 *q;
    s32 count;
    s32 key;
    s16 i = 0;

    if (*(u32 *)entryp != 0) {
        i = 0;
        key = (s16)arg1;
        p = *(u8 **)((u8 *)*(u32 *)entryp + 0x38);
        count = *(s32 *)(p + 8);
        for (; i < count; i++) {
            entry = *entryp;
            p = *(u8 **)(entry + 0x38);
            switch (*(u32 *)(p + 4)) {
            case 0:
            case 2:
            case 7:
            case 8:
                q = p + ((i * 3) * 0x10) + 0x14;
                break;
            case 1:
            case 5:
            case 6:
            case 10:
                q = p + ((i * 3) * 0x10) + 0xA4;
                break;
            default:
                q = p + ((i * 3) * 0x10) + 0x14;
                break;
            }
            if (key == *(u16 *)(q + 2)) {
                return 1;
            }
        }
    }
    return 0;
}
/* measured: see the annotation above the matching `on` pragma (func_002e53b0). */
#pragma opt_loop_invariants off

// FUN_002E54C0
/* measured: without `opt_loop_invariants on` MWCC rematerializes the switch
   jump-table base (lui/addiu) inside the loop body instead of hoisting it into
   the preheader as retail does, giving nd 30+. */
#pragma opt_loop_invariants on
s16 func_002e54c0(s8 arg0, s16 arg1) {
    s16 i = 0;
    u8 **entryp = &D_00882F70[arg0];
    u8 *entry;
    u8 *p;
    u8 *q;
    s32 count;
    s32 key;

    if (*(u32 *)entryp != 0) {
        i = 0;
        key = (s16)arg1;
        p = *(u8 **)((u8 *)*(u32 *)entryp + 0x38);
        count = *(s32 *)(p + 8);
        for (; i < count; i++) {
            entry = *entryp;
            p = *(u8 **)(entry + 0x38);
            switch (*(u32 *)(p + 4)) {
            case 0:
            case 2:
            case 7:
            case 8:
                q = p + ((i * 3) * 0x10) + 0x14;
                break;
            case 1:
            case 5:
            case 6:
            case 10:
                q = p + ((i * 3) * 0x10) + 0xA4;
                break;
            default:
                q = p + ((i * 3) * 0x10) + 0x14;
                break;
            }
            if (key == *(u16 *)(q + 2)) {
                return i;
            }
        }
    }
    return -1;
}
/* measured: see the annotation above the matching `on` pragma (func_002e54c0). */
#pragma opt_loop_invariants off

/* measured: direct C reconstruction. Disabling common-subexpression
   elimination preserves retail's repeated D_00882F70[arg0] address
   materialization; explicit (u16)arg1 preserves ac10's 16-bit argument. */
#pragma opt_common_subs off
// FUN_002E55C0
void func_002e55c0(s8 arg0, s32 arg1, s8 arg2) {
    u8 **entryp;
    u8 *entry;

    entryp = &D_00882F70[arg0];
    entry = *entryp;
    if (entry != NULL) {
        if (arg2 == 0) {
            u8 *p;
            u8 *q;
            s16 index;

            p = *(u8 **)(entry + 0x38);
            index = *(s16 *)(p + 8);
            switch (*(s32 *)(p + 4)) {
            case 0:
            case 2:
            case 7:
            case 8:
                q = p + ((index * 3) * 0x10) + 0x14;
                break;
            case 1:
            case 5:
            case 6:
            case 10:
                q = p + ((index * 3) * 0x10) + 0xA4;
                break;
            default:
                q = p + ((index * 3) * 0x10) + 0x14;
                break;
            }
            func_0010cad0(q, arg1 & 0xFFFF);
        } else if ((s16)func_0010aa80(arg1) == -1) {
            {
                u8 *p;
                u8 *q;
                s16 index;

                p = *(u8 **)(D_00882F70[arg0] + 0x38);
                index = *(s16 *)(p + 8);
                switch (*(s32 *)(p + 4)) {
                case 0:
                case 2:
                case 7:
                case 8:
                    q = p + ((index * 3) * 0x10) + 0x14;
                    break;
                case 1:
                case 5:
                case 6:
                case 10:
                    q = p + ((index * 3) * 0x10) + 0xA4;
                    break;
                default:
                    q = p + ((index * 3) * 0x10) + 0x14;
                    break;
                }
                func_0010cad0(q, arg1 & 0xFFFF);
            }
            {
                u8 *p;
                u8 *q;
                s16 index;

                p = *(u8 **)(D_00882F70[arg0] + 0x38);
                index = *(s16 *)(p + 8);
                switch (*(s32 *)(p + 4)) {
                case 0:
                case 2:
                case 7:
                case 8:
                    q = p + ((index * 3) * 0x10) + 0x14;
                    break;
                case 1:
                case 5:
                case 6:
                case 10:
                    q = p + ((index * 3) * 0x10) + 0xA4;
                    break;
                default:
                    q = p + ((index * 3) * 0x10) + 0x14;
                    break;
                }
                *(u8 *)(q + 4) = 0;
            }
        } else {
            u8 *p;
            u8 *q;
            u16 *src;
            s16 index;

            p = *(u8 **)(D_00882F70[arg0] + 0x38);
            index = *(s16 *)(p + 8);
            switch (*(s32 *)(p + 4)) {
            case 0:
            case 2:
            case 7:
            case 8:
                q = p + ((index * 3) * 0x10) + 0x14;
                break;
            case 1:
            case 5:
            case 6:
            case 10:
                q = p + ((index * 3) * 0x10) + 0xA4;
                break;
            default:
                q = p + ((index * 3) * 0x10) + 0x14;
                break;
            }
            src = func_0010ac10((u16)arg1);
            func_0043f810(q, src, 0x30);
        }
        (*(s32 *)(*(u8 **)(*entryp + 0x38) + 8))++;
    }
}

/* measured: restore common-subexpression elimination after func_002e55c0. */
#pragma opt_common_subs on
// FUN_002E5960
void func_002e5960(s8 arg0) {
    u8 *p;
    s16 i;
    s16 j;
    s32 type;

    if (D_00882F70[arg0] == NULL) {
        return;
    }
    p = *(u8 **)(D_00882F70[arg0] + 0x38);
    type = *(s32 *)(p + 4);
    switch (type) {
    case 0:
    case 7:
    case 8:
        for (i = 0; i < 0x100; i++) {
            func_0043f9c8(p + ((i * 3) * 0x10) + 0x14, 0, 0x30);
        }
        break;
    case 1:
    case 10:
    case 5:
    case 6:
        for (j = 0; j < 0xC; j++) {
            func_0043f9c8(p + ((j * 3) * 0x10) + 0xA4, 0, 0x30);
            *(u8 *)(p + j + 0x2E4) = 0;
        }
        break;
    default:
        break;
    }
    *(s16 *)(p + 0xE) = 0;
    *(s16 *)(p + 0x10) = 0;
    *(s32 *)(p + 8) = 0;
}

/* measured: structure fully recovered (slotp/entry/p chain, func_002e5960
   calls, the 0xC0 i-loop with the iGpffffb3d4+i*14 entry2 checks, the
   311d00/311d60/2e6230 gates, the func_002e48a0 j-loop, the 311e40 gate,
   the spE0/spD0 range compare and the two jump-table switches with
   memset/cad0 + p->8++, the 0x3C tail gate and the 5-iteration do-loop with
   spC0/spB0/spA0 slot writes) but the five 16-byte stack slots spE0/spD0/
   spC0/spB0/spA0 hold s16-extended values: retail sq's the value directly
   after its dsll32/dsra32 and lq's it into a raw 32-bit compare (slt), while
   mwcc b210 emits a dsll32/dsrl32 widening pair before every sq and after
   every lq of a u_long128 local holding a 32-bit value. Same mixed-width
   u_long128 floor measured in this file at func_002e4ac0 (nd 302, best of
   u_long128/s128/u64/aligned-u64 with direct/(u64)/(u32) casts and
   typed-alias reads) and recorded in mdlManager func_0047c660 / mdlMatAnim
   func_00480670 / P3 W414. Not transcribed further; floor. */
// FUN_002E5AE0
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e5ae0);

// FUN_002E6230
s32 func_002e6230(u16 arg0, u16 *arg1) {
    s32 i = 0;
    s32 key = arg0 & 0xFFFF;

    while (i < 13) {
        if (*(u16 *)((u8 *)arg1 + i * 2) == key) {
            return 1;
        }
        i++;
    }
    return 0;
}

/* measured: object 888B/window 944B/normalized_diff 523 (183 differing words, fnalign per current tree). */
/* measured: current 100-line body re-measured live (was nd73 at 936B in old note, now 888B with TU drift); saved-reg rotation-spill floor with single materialization vs retail v1-retained plus post-j sink and k-join rematerialization; declaration-order, loop-invariant, slti, dead-store and arg-setup levers to be worked top-down via fnalign; full-window body preserved. */
// FUN_002E6280 NONMATCHING
#ifdef NON_MATCHING
void func_002e6280(s8 arg0, u8 *arg1, s8 arg2)
{
    u8 **slotp;
    s16 cnt;
    s16 i;
    u16 j;
    u16 k;
    s16 found;
    u8 *q;
    s16 h8;
    u32 sw1;
    u32 sw2;
    u8 *dst1;
    u8 *dst2;
    s32 spA0;
    u8 *gp_tbl;

    slotp = &D_00882F70[(s8)arg0];
    if (*slotp == NULL) {
        return;
    }
    gp_tbl = iGpffffb3d4;
    func_002e5960(arg0);
    spA0 = (s16)func_002b2cb0((s16)arg2, 3, 99, 1, 1);
    i = 0;
    while (((i & 0xFFFF)) < 192) {
        {
            u8 *t = *(u8 **)(gp_tbl + i * 14);
            if (*(t + 2) == 1 && (*(t) & 8) == 0) {
                u16 id = (u16)i;
                if (func_00311d00(id) != 0 && func_00311d60(id) != 0) {
                    found = 0;
                    j = 0;
                    while (((j & 0xFFFF)) < 13) {
                        if (id == *(u16 *)(arg1 + (j & 0xFFFF) * 2)) {
                            found = 1;
                            break;
                        }
                        j = (j + 1) & 0xFFFF;
                    }
                    if (found == 0) {
                        if (*slotp != NULL) {
                            k = 0;
                            found = 0;
                            while (((s16)k) < *(s32 *)(*(u8 **)(*slotp + 56) + 8)) {
                                if (i == *(s16 *)(func_002e48a0(arg0, k) + 2)) {
                                    found = 1;
                                    break;
                                }
                                k = (((s16)k + 1) & 0xFFFF);
                            }
                        }
                        if (found == 0 && func_00311e40(id) == 0 && spA0 >= *(t + 3)) {
                            h8 = *(s16 *)(*(u8 **)(*slotp + 56) + 8);
                            q = *(u8 **)(*slotp + 56);
                            sw1 = *(u32 *)(q + 4);
                            switch (sw1) {
                            case 0:
                            case 2:
                            case 7:
                            case 8:
                            default:
                                dst1 = q + (h8 * 48) + 20;
                                break;
                            case 1:
                            case 5:
                            case 6:
                            case 10:
                                dst1 = q + (h8 * 48) + 164;
                                break;
                            }
                            func_0043f9c8(dst1, 0, 48);
                            h8 = *(s16 *)(*(u8 **)(*slotp + 56) + 8);
                            q = *(u8 **)(*slotp + 56);
                            sw2 = *(u32 *)(q + 4);
                            switch (sw2) {
                            case 0:
                            case 2:
                            case 7:
                            case 8:
                            default:
                                dst2 = q + (h8 * 48) + 20;
                                break;
                            case 1:
                            case 5:
                            case 6:
                            case 10:
                                dst2 = q + (h8 * 48) + 164;
                                break;
                            }
                            func_0010cad0(dst2, id);
                            *(s16 *)(*(u8 **)(*slotp + 56) + 8) = h8 + 1;
                        }
                    }
                }
            }
        }
        i = (((s16)i + 1) & 0xFFFF);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e6280);
#endif

/* measured: 640B/640B, exact instructions and all 44 jump-table entries.
   Keep each signed index's byte offset across its repeated accessor pair.
   The comparator's O1 scope preserves the retail selector and key lifetimes. */
// FUN_002E6630
#pragma optimization_level 1
s32 func_002e6630(s16 *arg0, s16 *arg1) {
    s16 ia = *arg0;
    s16 ib = *arg1;
    u8 *base = *(u8 **)(D_00882F70[0] + 0x38);
    u8 *pa;
    u8 *qa;
    u8 *pb;
    u8 *qb;
    s32 offset_a;
    s32 offset_b;
    u8 *metadata;
    u16 va;
    s32 vb;
    s32 va_mask;
    switch (*(u32 *)(base + 4)) {
    case 0:
    case 2:
    case 7:
    case 8:
        offset_a = (ia * 3) * 0x10;
        pa = base + offset_a + 0x14;
        break;
    case 1:
    case 5:
    case 6:
    case 10:
        offset_a = (ia * 3) * 0x10;
        pa = base + offset_a + 0xA4;
        break;
    default:
        offset_a = (ia * 3) * 0x10;
        pa = base + offset_a + 0x14;
        break;
    }
    switch (*(u32 *)(base + 4)) {
    case 0:
    case 2:
    case 7:
    case 8:
        qa = base + offset_a + 0x14;
        break;
    case 1:
    case 5:
    case 6:
    case 10:
        qa = base + offset_a + 0xA4;
        break;
    default:
        qa = base + offset_a + 0x14;
        break;
    }
    metadata = iGpffffb3d4 + 2;
    va = pa[4] + 100 * metadata[14 * *(u16 *)(qa + 2)];
    switch (*(u32 *)(base + 4)) {
    case 0:
    case 2:
    case 7:
    case 8:
        offset_b = (ib * 3) * 0x10;
        pb = base + offset_b + 0x14;
        break;
    case 1:
    case 5:
    case 6:
    case 10:
        offset_b = (ib * 3) * 0x10;
        pb = base + offset_b + 0xA4;
        break;
    default:
        offset_b = (ib * 3) * 0x10;
        pb = base + offset_b + 0x14;
        break;
    }
    switch (*(u32 *)(base + 4)) {
    case 0:
    case 2:
    case 7:
    case 8:
        qb = base + offset_b + 0x14;
        break;
    case 1:
    case 5:
    case 6:
    case 10:
        qb = base + offset_b + 0xA4;
        break;
    default:
        qb = base + offset_b + 0x14;
        break;
    }
    vb = (u16)(pb[4] + 100 * metadata[14 * *(u16 *)(qb + 2)]);
    va_mask = va & 0xFFFF;
    if (vb < va_mask) {
        return 1;
    }
    return -(va_mask < vb);
}
#pragma optimization_level 2





// FUN_002E68B0
/* measured: without `opt_loop_invariants on` MWCC keeps the loop2 switch
   jump-table base (lui/addiu) inside the dispatch instead of hoisting it
   into the preheader as retail does. */
#pragma opt_loop_invariants on
void func_002e68b0(s8 arg0) {
    u8 **slotp = &D_00882F70[arg0];
    u8 *entry;
    u8 *p;
    u8 **ep;
    u8 *p2;
    s32 count2;
    s16 k;
    s16 j;
    u8 *dst;
    s16 i;
    s16 idx;
    s16 arr1[0x100];
    s16 arr2[0x100];

    entry = *slotp;
    if (entry == NULL) {
        return;
    }
    ep = (u8 **)(entry + 0x38);
    p = *(u8 **)(entry + 0x38);
    for (k = 0; k < *(s32 *)(*(u8 **)(entry + 0x38) + 8); k++) {
        arr1[k] = k;
    }
    func_00440bb8(arr1, *(u16 *)((u8 *)*ep + 8), 2, func_002e6630);
    j = 0;
    count2 = *(s32 *)(*(u8 **)((u8 *)*slotp + 0x38) + 8);
    if (count2 > 0) {
        p2 = *(u8 **)((u8 *)*(u8 **)((u8 *)D_00882F70 + (u32)(s8)arg0 * 4) + 0x38);
        for (; j < count2; j++) {
            u8 *q;

            idx = arr1[j];
            switch (*(u32 *)(p2 + 4)) {
            case 0:
            case 2:
            case 7:
            case 8:
                q = p2 + ((idx * 3) * 0x10) + 0x14;
                break;
            case 1:
            case 5:
            case 6:
            case 10:
                q = p2 + ((idx * 3) * 0x10) + 0xA4;
                break;
            default:
                q = p2 + ((idx * 3) * 0x10) + 0x14;
                break;
            }
            arr2[j] = *(u16 *)(q + 2);
        }
    }
    for (i = 0; i < *(s32 *)(*(u8 **)((u8 *)*slotp + 0x38) + 8); i++) {
        dst = p + ((i * 3) * 0x10) + 0x14;

        func_0043f9c8(dst, 0, 0x30);
        func_0043f810(dst, func_0010fcb0(arr2[i]), 0x30);
    }
}
/* measured: see the annotation above the matching `on` pragma (func_002e68b0). */
#pragma opt_loop_invariants off

/* measured 2026-08-12: best plain-C comparator body is archived at
   build/D2E6_002e6b20_body.c (object 360B/window 368B, normalized_diff 10;
   differing byte offsets 6,7,10,11,12,13,14,16,18,19). The direct body has
   no calls and its s16 *arg0/s16 *arg1 signature is confirmed. The remaining
   residual is the initial retail load order (lh arg0, lh arg1, then the
   global base) versus MWCCPS2's lh arg0, global base, lh arg1 schedule.
   Retained: s32 vb, s32 va_mask, opt_common_subs off. Ruled out:
   schedule-on, propagation-off, declaration-order, pointer-load,
   ordered-assignment/initializer, const/alias typed-load, optimization_level
   1, dependent-index, and split-global forms. */
/* measured: unmodified m2c candidate from src/generated, installed as a permuter seed; not a verified body. */
// FUN_002E6B20
#pragma schedule on
#pragma optimization_level 1
s32 func_002e6b20(s16 *arg0, s16 *arg1) {
    s16 * arg1_p = arg1;
    s16 * arg0_p = arg0;
    s16 ia;
    u8 *base;
    s16 ib;
    u8 *pa;
    u8 *pb;
    s32 vb;
    u16 va;
    s32 va_mask;
    ia = *arg0_p;
    ib = *arg1_p;
    base = *(u8 **)(D_00882F70[0] + 0x38);
    switch ((u32)*(s32 *)(base + 4)) {
    case 0:
    case 2:
    case 7:
    case 8:
        pa = base + ia * 0x30 + 0x14;
        break;
    case 1:
    case 5:
    case 6:
    case 10:
        pa = base + ia * 0x30 + 0xA4;
        break;
    case 3:
    case 4:
    case 9:
    default:
        pa = base + ia * 0x30 + 0x14;
        break;
    }
    va = *(u8 *)(pa + 4);
    switch ((u32)*(s32 *)(base + 4)) {
    case 0:
    case 2:
    case 7:
    case 8:
        pb = base + ib * 0x30 + 0x14;
        break;
    case 1:
    case 5:
    case 6:
    case 10:
        pb = base + ib * 0x30 + 0xA4;
        break;
    case 3:
    case 4:
    case 9:
    default:
        pb = base + ib * 0x30 + 0x14;
        break;
    }
    vb = *(u8 *)(pb + 4);
    va_mask = va & 0xFFFF;
    if (vb < va_mask) {
        return 1;
    }
    return -(va_mask < vb);
}
#pragma optimization_level 2
#pragma schedule off



/* func_002e6c90 was closed by porting the MATCHED sibling func_002e68b0: same
   declaration order, same p2 re-index spelling
   `(u8 *)*(u8 **)((u8 *)D_00882F70 + (u32)(s8)arg0 * 4)`, same loop2/loop3
   shapes, with func_002e6b20 as the sort comparator. That fixed the old
   "arg0 not saved to $s2" defect and the missing p2 re-index, taking the
   recorded nd 140 to 52; the remaining loop2 register rotation then cleared.
   measured: `opt_loop_invariants on` is required here — without it MWCC keeps
   the loop-invariant slot address live in the loop body instead of hoisting it
   into the preheader, which is the rotation retail does not have. */
// FUN_002E6C90
/* measured: open opt_loop_invariants scope for func_002e6c90. */
#pragma opt_loop_invariants on
void func_002e6c90(s8 arg0) {
    u8 **slotp = &D_00882F70[arg0];
    u8 *entry;
    u8 *p;
    u8 **ep;
    u8 *p2;
    s32 count2;
    s16 k;
    s16 j;
    u8 *dst;
    s16 i;
    s16 idx;
    s16 arr1[0x100];
    s16 arr2[0x100];

    entry = *slotp;
    if (entry == NULL) {
        return;
    }
    ep = (u8 **)(entry + 0x38);
    p = *(u8 **)(entry + 0x38);
    for (k = 0; k < *(s32 *)(*(u8 **)(entry + 0x38) + 8); k++) {
        arr1[k] = k;
    }
    func_00440bb8(arr1, *(u16 *)((u8 *)*ep + 8), 2, func_002e6b20);
    j = 0;
    count2 = *(s32 *)(*(u8 **)((u8 *)*slotp + 0x38) + 8);
    if (count2 > 0) {
        p2 = *(u8 **)(*(u8 **)((u8 *)D_00882F70 +
              (u32)(s8)arg0 * 4) + 0x38);
        for (; j < count2; j++) {
            u8 *q;

            idx = arr1[j];
            switch (*(u32 *)(p2 + 4)) {
            case 0:
            case 2:
            case 7:
            case 8:
                q = p2 + ((idx * 3) * 0x10) + 0x14;
                break;
            case 1:
            case 5:
            case 6:
            case 10:
                q = p2 + ((idx * 3) * 0x10) + 0xA4;
                break;
            default:
                q = p2 + ((idx * 3) * 0x10) + 0x14;
                break;
            }
            arr2[j] = *(u16 *)(q + 2);
        }
    }
    for (i = 0; i < *(s32 *)(*(u8 **)((u8 *)*slotp + 0x38) + 8); i++) {
        dst = p + ((i * 3) * 0x10) + 0x14;

        func_0043f9c8(dst, 0, 0x30);
        func_0043f810(dst, func_0010fcb0(arr2[i]), 0x30);
    }
}
/* measured: closing the scope restores the file baseline; leaving
   `opt_loop_invariants on` open inflates the following functions. */
#pragma opt_loop_invariants off
// FUN_002E6F00
/* measured: without `opt_loop_invariants on` MWCC rematerializes the -1 store
   constant at the top of the loop body (nd 6) instead of hoisting it into the
   preheader as retail does (addiu $a1,$zero,-1 before the initial branch). */
#pragma opt_loop_invariants on
u8 *func_002e6f00(void) {
    s16 *buf;
    s16 i;
    s16 value;

    func_0044ea90(D_0063FC48, 0x649);
    buf = (s16 *)D_008873F4[0](1, 0x62, 0x40000);
    i = 0;
    value = -1;
    while (i < 0x30) {
        buf[i] = value;
        i++;
    }
    buf[0x30] = 0;
    return (u8 *)buf;
}
/* measured: see the annotation above the matching `on` pragma (func_002e6f00). */
#pragma opt_loop_invariants off
