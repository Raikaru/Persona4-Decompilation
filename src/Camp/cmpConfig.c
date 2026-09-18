#include "include_asm.h"
/* Persona 4 USA decompilation - cmpConfig.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"
#include "sdk_snd_internal.h"

typedef struct { f32 x, y; } Vec2f;

void func_0046d730(void* arg0, s32 arg1);
void func_0046d280(void *node);
void func_00460ac0(void* param, void* work);
void func_00106390(s32 a, s32 b);
s32 func_0035f0c0(u32* arg0, s32* arg1, u8* arg2);
s32 func_0034c210(void);
void func_0044ea90(void* file, s32 line);
void func_0043f9c8(void* dest, s32 value, s32 size);
s32 func_00451fc0(s32 arg0, const void* name, s32 prio, s32 a3, s32 a4,
                  void (*init)(u8*), void (*close)(u8*), u8* work);
void func_0034c260(s32 arg0);
void* func_0046a770(char* arg0);
s32 func_0046d200();
s32 func_00106330(s32 arg0);
void func_00113480(s32 a, s32 b, s32 c, s32 d);
void func_001437b0(void* arg0, s32 arg1, s32 arg2);
void func_0034f8f0(void* arg0);
void func_0034f1e0(void);
void func_0034c270(Vec2f arg0, u8 arg1, s32 arg2, f32 arg3);
void func_0034f2e0(void *arg0, f32 fparg0, f32 fparg1, u8 arg1, u8 arg2, u8 arg3, u32 arg4);
void func_0034f320(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2,
                   u8 arg1, u8 arg2, u8 arg3, u32 arg4,
                   u16 arg5, u16 arg6, s16 arg7, f32 fparg3, s16 arg_sp0);
f32 func_0044b7b0(f32 arg0);

void func_0034f9d0(Vec2f unused, f32 fparg0, u32 arg1, s32 arg2, s32 arg3);
void func_00489f80(void);
void func_0045c870(void* arg0, s32 arg1);
void func_0048a000(void);
void func_003f6440(s32 a, s32 b);
void func_0035e820(u8* arg0);
s32 func_0035e720(u8* arg0);
s32 func_0035ce10(u8* arg0, s32 mode);
s32 func_0035cc80(u8* arg0, s32 arg1, s32 arg2);
void func_0035d000(u8* arg0, u8* arg1);
void func_0035ddf0(u8* arg0);
void func_0035d0a0(u8 *arg0);
void func_0035dfb0(u8* arg0, s32 arg1, s32 arg2);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void (*D_00887300[])(u32, u32);
extern u8 D_0064D3C8[];
extern u8 D_0064D3D8[];
extern u8 D_005E5850[];
extern u8 D_005E57F0[];
extern u8 D_0064D3B8[];
extern u8 D_0064B2E0[];
extern u8 D_0064B2E8[];
extern u8 D_0064B2EC[];
extern u8 D_0064B304[];
extern s32 D_0064D230[];
extern s32 D_0064D380[];
extern f32 iGpffff8170;
extern f32 iGpffff8094;
extern u8 D_00793E80[];
extern s32 D_0064D3A0[];
extern u8 D_0064CD90[];
extern u8 D_0064CF00[];
extern u8 D_0064D070[];

// FUN_0035C690
s32 func_0035c690(void* arg0, s32 arg1) {
    s32 r;
    u8* work;

    func_0044ea90(D_0064D3C8, 0xC5);
    work = D_008873F4[0](1, 0x4B0, 0x40000);
    if (work == NULL) {
        func_0046d730(D_0064D3C8, 0xC6);
    }
    r = func_00451fc0((s32)arg0, D_0064D3D8, 0xC7, 0, 0,
                      (void (*)(u8 *))func_0035e720,
                      (void (*)(u8 *))func_0035e820, work);
    func_0043f9c8(work + 0x47C, 0, 0x30);
    *(s32 *)(work + 0x484) = (s32)func_0035d000;
    *(u8 **)(work + 0x48C) = work;
    *(u16 *)(work + 0x4AC) = 0xB1;
    *(s32 *)(work + 0x1C) = arg1;
    switch (arg1) {
    case 0:
        break;
    case 1:
        func_0034c260(1);
        break;
    default:
        func_0046d730(D_0064D3C8, 0xE6);
        break;
    }
    return r;
}

// FUN_0035C7D0
s32 func_0035c7d0(u8 *arg0) {
    return (s32)((*(u8 **)((s8 *)arg0 + 0x38))[4] & 1) != 0;
}

// FUN_0035C7F0
s32 func_0035c7f0(u8 *arg0) {
    return (s32)((*(u8 **)((s8 *)arg0 + 0x38))[4] & 4) != 0;
}

// FUN_0035C810
s32 func_0035c810(u8 *arg0) {
    return (s32)((*(u8 **)((s8 *)arg0 + 0x38))[4] & 2) != 0;
}

// FUN_0035C830
void func_0035c830(u8* arg0) {
    s32 resource;
    s16 i;
    s16 j;
    s16 k;
    s16 m;
    u8* table;
    u8* src;
    u8* dst;
    u8 code;
    s32 result;

    *(s32 *)(arg0 + 0x20) = -1;
    func_0035ce10(arg0, 0);
    *(s32 *)(arg0 + 0x08) = 0;
    *(s32 *)(arg0 + 0x0C) = 0;
    *(u8 *)(arg0 + 0x00) = 0xFF;
    *(s32 *)(arg0 + 0x18) = 0;
    *(s32 *)(arg0 + 0x20) = -1;
    for (i = 0; i <= 0; i++) {
        *(s32 *)(arg0 + i * 4 + 0x30) = 0;
    }
    j = 0;
    table = D_0064D070;
    for (; j < 18; j++) {
        src = table + j * 20;
        dst = arg0 + j * 48;
        *(f32 *)(dst + 0x88) = *(f32 *)(src + 0x00);
        *(f32 *)(dst + 0x8C) = *(f32 *)(src + 0x04);
        *(u8 *)(dst + 0x92) = *(u8 *)(src + 0x08);
    }
    resource = (s32)(u32)func_0046a770((char *)D_005E5850);
    if (resource == 0) {
        func_0046d730(D_0064D3C8, 0x12F);
    }
    result = (s32)(u32)func_0046a770((char *)D_005E57F0);
    *(s32 *)(arg0 + 0x474) = result;
    for (k = 0; k < 11; k++) {
        dst = arg0 + k * 4 + 0x448;
        code = D_0064D3B8[k];
        *(s32 *)dst = func_0046d200(resource, code);
        if (*(s32 *)dst == 0) {
            func_0046d730(D_0064D3C8, 0x136);
        }
    }
    for (m = 0; m < 6; m++) {
        *(u16 *)(arg0 + m * 2 + 0x3A) = 5;
        result = func_00106330(D_0064D3A0[m]);
        if (result != 0) {
            *(s32 *)(arg0 + m * 4 + 0x60) = 0;
            *(s32 *)(arg0 + m * 4 + 0x48) = 1;
        } else {
            *(s32 *)(arg0 + m * 4 + 0x60) = 1;
            *(s32 *)(arg0 + m * 4 + 0x48) = 0;
        }
    }
}


// FUN_0035CAB0
s32 func_0035cab0(u8 *arg0, s32 idx, s32 val) {
    s32 scaled = idx * 4;
    u8 *p = (u8 *)(scaled + (int)arg0);

    *(s32 *)(p + 0x34) = *(s32 *)(p + 0x30);
    *(s32 *)(p + 0x30) = val;
    if (idx == 0) {
        if (val == 6) {
            *(u16 *)(arg0 + 0x38) = 0;
        } else {
            *(u16 *)(arg0 + 0x38) = 0x12;
        }
    }
    return 1;
}

// FUN_0035CB00
s32 func_0035cb00(u8* arg0, s32 idx) {
    s32 scaled;
    s32 scaled2;
    s32* state_ptr;
    s32 state;
    s32 state_zero;
    s32 allowed;
    s32 temp;

    scaled = idx * 4;
    state_ptr = (s32 *)(scaled + (u32)arg0 + 0x48);
    state = *state_ptr;
    state_zero = ((u32)*state_ptr != 0) ^ 1;
    if (idx == 1) {
        if ((state_zero == 0) && (*(s32 *)(arg0 + 0x50) != 0)) {
            func_0035cc80(arg0, 2, 0);
        }
    } else if ((idx == 2) && (*(s32 *)(arg0 + 0x4C) == 0)) {
        func_0045af60(0, 0, 0, 8);
        allowed = 0;
        goto done;
    }
    allowed = 1;
done:
    if (allowed != 0) {
        goto apply;
    }
    return 0;
apply:
    *(s32 *)(scaled + (int)arg0 + 0x60) = state;
    *state_ptr = ((u32)state > 0) ^ 1;
    scaled2 = idx * 2;
    *(u16 *)(scaled2 + (int)arg0 + 0x3A) = 0;
    if ((idx == 0) && (*state_ptr == 1)) {
        temp = func_00106330(D_0064D3A0[0]);
        func_00106390(D_0064D3A0[0], 1);
        func_00113480(0xA, 0x96, 0xA, 0);
        func_00106390(D_0064D3A0[0], temp);
    }
    return 1;
}



// FUN_0035CC80
s32 func_0035cc80(u8 *arg0, s32 arg1, s32 arg2)
{
    typedef struct {
        u8 pad[0x48];
        s32 state;
    } ConfigEntry;
    s32 temp_16;
    s32 var_2;
    u8 *temp_2;

    temp_2 = (u8 *)&((ConfigEntry *)((u8 *)(arg1 * 4) + (u32)arg0))->state;
    if (*(s32 *)temp_2 == arg2) {
        return 0;
    }
    if (arg1 == 1) {
        if ((arg2 == 0) && (*(s32 *)(arg0 + 0x50) != 0)) {
            func_0035cc80(arg0, 2, 0);
        }
        goto block_9;
    }
    if ((arg1 == 2) && (*(s32 *)(arg0 + 0x4C) == 0)) {
        func_0045af60(0, 0, 0, 8);
        var_2 = 0;
    } else {
block_9:
        var_2 = 1;
    }
    if (var_2 == 0) {
        return 0;
    }
    *(s32 *)((u8 *)(arg1 * 4) + (u32)arg0 + 0x60) =
        *(s32 *)((u8 *)(arg1 * 4) + (u32)arg0 + 0x48);
    *(s32 *)((u8 *)(arg1 * 4) + (u32)arg0 + 0x48) = arg2;
    *(s16 *)((u8 *)(arg1 * 2) + (u32)arg0 + 0x3A) = 0;
    if ((arg1 == 0) && (*(s32 *)temp_2 == 1)) {
        temp_16 = func_00106330(D_0064D3A0[0]);
        func_00106390(D_0064D3A0[0], 1);
        func_00113480(0xA, 0x96, 0xA, 0);
        func_00106390(D_0064D3A0[0], temp_16);
    }
    return 1;
}


// FUN_0035CE10
s32 func_0035ce10(u8* arg0, s32 mode) {
    u8* tab = 0;
    s32 i;
    s32 j;

    if (*(s32*)(arg0 + 0x20) == mode) {
        return 0;
    }
    for (i = 0; i < 18; i++) {
        *(f32*)(arg0 + i * 48 + 0x78) = *(f32*)(arg0 + i * 48 + 0x88);
        *(f32*)(arg0 + i * 48 + 0x7C) = *(f32*)(arg0 + i * 48 + 0x8C);
        *(u8*)(arg0 + i * 48 + 0x90) = *(u8*)(arg0 + i * 48 + 0x92);
    }
    switch (mode) {
    case 0:
        tab = D_0064CD90;
        *(s32*)(arg0 + 0x24) = 3;
        *(u16*)(arg0 + 0x38) = 0x12;
        break;
    case 1:
        tab = D_0064D070;
        *(s32*)(arg0 + 0x24) = 3;
        break;
    case 2:
        tab = D_0064CF00;
        *(s32*)(arg0 + 0x24) = 3;
        break;
    default:
        func_0046d730(D_0064D3C8, 0x207);
        break;
    }
    if (tab != 0) {
        for (j = 0; j < 18; j++) {
            *(f32*)(arg0 + j * 48 + 0x80) = *(f32*)(tab + j * 20 + 0);
            *(f32*)(arg0 + j * 48 + 0x84) = *(f32*)(tab + j * 20 + 4);
            *(u8*)(arg0 + j * 48 + 0x91) = *(u8*)(tab + j * 20 + 8);
            *(s32*)(arg0 + j * 48 + 0xA0) = *(s32*)(tab + j * 20 + 0xC);
            *(s32*)(arg0 + j * 48 + 0xA4) = *(s32*)(tab + j * 20 + 0x10);
        }
        *(s32*)(arg0 + 0x20) = mode;
        *(u16*)(arg0 + 0x28) = 0;
    }
    return 1;
}

// FUN_0035CFB0
s32 func_0035cfb0(u8 *arg0) {
    s32 v = *(s32 *)(arg0 + 0x18);

    switch (v) {
    case 0:
        v += 1;
        *(s32 *)(arg0 + 0x18) = v;
        return 1;
    case 1:
        return 1;
    default:
        return 0;
    }
}

// FUN_0035D000
void func_0035d000(u8* arg0, u8* arg1) {
    s32 i;

    if (*(s16 *)(arg1 + 0x28) < 0x64) {
        *(s16 *)(arg1 + 0x28) = *(s16 *)(arg1 + 0x28) + 1;
    }
    for (i = 0; i < 18; i++) {
        s16 v = *(s16 *)(arg1 + 0x28);

        func_001437b0(arg1 + i * 48 + 0x78, v, 0);
    }
    func_0035ddf0(arg1);
    func_0035d0a0(arg1);
}

/* measured: GUARDED_SCORE 496 via measure_guarded (probe_variants base 533 -> v2c 496), obj 3092B window 3104B (99.6% within 3%), fnalign 773/773 instrs 370 edits +1 reloc-only; pragmas singly: loopinv 533 tie, nounroll 533 tie, nosched 533 tie, nocommon 736 (+203); subscript off-form tie; floats-first tie; x/y elimination -37. Residual: frame 0xE0 vs 0xD0, arg0 $s0 vs $s4, COP1 adda/madd scheduling, D_ word-copy (lwc1 vs lbu/sb), saved-reg colouring ($s0/$s5 vs $s4/$s0, $s3/$s4 vs $s3/$s4 class, time-boxed per 7m). No retail jump table (loops only); text/sprite helpers grepped from frFontEx.c (00274ed0/00275020) and cmpConfig idiom (0034c270/0034f2e0/0034f9d0/0035dfb0); decompilers m2c.c (303 lines) + rom.c (207 lines) + --types in /var/tmp/cold35d0a0/. Verify 17 MATCH 1 ASM (guarded self), lint 0 errors. */
// FUN_0035D0A0 NONMATCHING
#ifdef NON_MATCHING
void func_0035d0a0(u8 *arg0) {
    extern int func_00274ed0(f32 x, f32 y, f32 scale, int color, s8 chr, int id, const char *str, int flags, int charWidth);
    extern int func_00275020(f32 x, f32 y, f32 scale, int color, s8 chr, int id, const char *str, int flags, int charWidth);
    s32 sel;
    s32 flag;
    s32 i;
    s32 j;
    s32 prev;
    s32 isSel;
    u8 *row;
    u8 *sprite;
    u8 *colPtr;
    u8 r;
    u8 g;
    u8 b;
    u8 alpha;
    Vec2f pos;
    f32 fade;
    f32 baseX;
    f32 baseY;
    f32 x0;
    f32 y0;
    f32 f21;
    f32 f20;

    func_0034f1e0();
    baseX = *(f32 *)(arg0 + 8);
    baseY = *(f32 *)(arg0 + 0xC);
    fade = (f32)*arg0 / 255.0f;
    sel = *(s32 *)(arg0 + 0x30);
    flag = *(s32 *)(arg0 + 0x14);
    if (flag != 0) {
        pos.x = baseX;
        pos.y = baseY;
        alpha = (u8)(255.0f * fade);
        func_0034c270(pos, alpha, flag, 0.0f);
    }
    if ((*(u32 *)(arg0 + 0x24) & 1) != 0) {
        pos.x = 26.0f + (baseX + *(f32 *)(arg0 + 0x88));
        pos.y = 388.0f + (baseY + *(f32 *)(arg0 + 0x8C));
        alpha = (u8)((f32)*(u8 *)(arg0 + 0x92) * fade);
        func_0034f2e0(*(void **)(arg0 + 0x448), pos.x, pos.y, 0x5E, 0x37, 0xFF, alpha);
    }
    if ((*(u32 *)(arg0 + 0x24) & 2) != 0) {
        x0 = (baseX + *(f32 *)(arg0 + 0x3B8)) - 23.0f;
        y0 = baseY + *(f32 *)(arg0 + 0x3BC);
        alpha = (u8)((f32)*(u8 *)(arg0 + 0x3C2) * fade);
        sprite = *(u8 **)(arg0 + 0x470);
        f21 = iGpffff8170 * (f32)alpha;
        f20 = 0.5f * (f32)alpha;
        for (i = 0; i < 11; i++) {
            pos.x = x0 + (f32)(i * 45);
            row = arg0 + i * 10;
            for (j = 0; j < *(s16 *)(row + 0x3DA); j++) {
                if (j == *(s16 *)(row + 0x3DA) - 1) {
                    r = 0xFF;
                    g = 0xFF;
                    b = 0xA4;
                    alpha = (u8)f21;
                    pos.y = y0 + (f32)(j * 17);
                    func_0034f2e0(sprite, pos.x, pos.y, r, g, b, alpha);
                } else if (j < *(s16 *)(row + 0x3DE)) {
                    r = 0xFE;
                    g = 0xFF;
                    b = 0x56;
                    alpha = (u8)f20;
                    pos.y = y0 + (f32)(j * 17);
                    func_0034f2e0(sprite, pos.x, pos.y, r, g, b, alpha);
                }
            }
        }
        prev = -1;
        for (i = 0; i < 7; i++) {
            row = arg0 + i * 48;
            x0 = baseX + *(f32 *)(row + 0xB8);
            y0 = (f32)i * 32.0f + (baseY + *(f32 *)(row + 0xBC));
            pos.x = 219.0f + x0;
            pos.y = 119.0f + y0;
            alpha = (u8)((f32)*(u8 *)(row + 0xC2) * fade);
            if ((i == 2) && (*(s32 *)(arg0 + 0x4C) == 0)) {
                r = 0xA0;
                g = 0xA0;
                b = 0xA0;
            } else {
                r = D_0064B2E0[0];
                g = D_0064B2E0[1];
                b = D_0064B2E0[2];
            }
            func_0034f2e0(*(void **)(arg0 + 0x44C), pos.x, pos.y, r, g, b, alpha);
            func_0034f2e0(*(void **)(arg0 + 0x450), 380.0f + pos.x, pos.y, r, g, b, alpha);
            if (i == sel) {
                isSel = 1;
                func_0034f2e0(*(void **)(arg0 + 0x460), pos.x, pos.y, D_0064B2E8[0], D_0064B2E8[1], D_0064B2E8[2], alpha);
                func_0034f2e0(*(void **)(arg0 + 0x468), 247.0f + pos.x, pos.y, D_0064B2E8[0], D_0064B2E8[1], D_0064B2E8[2], alpha);
                if ((i == 2) && (*(s32 *)(arg0 + 0x4C) == 0)) {
                    flag = (alpha & 0xFF) | 0xB4B4B400;
                } else {
                    flag = (alpha & 0xFF) | 0xFFFFFF00;
                }
            } else {
                isSel = 0;
                if (i == 2) {
                    flag = (alpha & 0xFF) | 0x80808000;
                } else {
                    flag = (alpha & 0xFF) | 0x80808000;
                }
            }
            x0 = (f32)0x1C7 + x0;
            y0 = 122.0f + y0;
            func_00275020(x0, y0, 0.0f, flag, 8, 1, (const char *)D_0064D230[i], 2, -1);
            if (i != 6) {
                if (*(u16 *)(arg0 + i * 2 + 0x3A) < 5) {
                    if (prev != -1) {
                        func_0035dfb0(arg0, prev, 1);
                        func_0035dfb0(arg0, prev, 2);
                    }
                    prev = i;
                    *(u16 *)(arg0 + i * 2 + 0x3A) = *(u16 *)(arg0 + i * 2 + 0x3A) + 1;
                } else {
                    func_0035dfb0(arg0, i, 0);
                }
            } else {
                row = arg0 + i * 48;
                pos.x = (f32)0x1CF + (baseX + *(f32 *)(row + 0x208));
                pos.y = (f32)0x137 + (baseY + *(f32 *)(row + 0x20C));
                func_0034f2e0(*(void **)(arg0 + 0x464), pos.x, pos.y, D_0064B2E8[0], D_0064B2E8[1], D_0064B2E8[2], alpha);
                func_0034f2e0(*(void **)(arg0 + 0x468), 150.0f + pos.x, pos.y, D_0064B2E8[0], D_0064B2E8[1], D_0064B2E8[2], alpha);
                pos.x = (f32)0x205 + (baseX + *(f32 *)(row + 0x208));
                pos.y = (f32)0x13F + (baseY + *(f32 *)(row + 0x20C));
                if (isSel != 0) {
                    colPtr = D_0064B2EC;
                } else {
                    colPtr = D_0064B304;
                }
                func_0034f2e0(*(void **)(arg0 + 0x46C), pos.x, pos.y, colPtr[0], colPtr[1], colPtr[2], alpha);
            }
        }
        if (prev != -1) {
            func_0035dfb0(arg0, prev, 1);
            func_0035dfb0(arg0, prev, 2);
        }
        pos.x = (f32)0x26B + (baseX + *(f32 *)(arg0 + 0x358));
        pos.y = (f32)0x15B + (baseY + *(f32 *)(arg0 + 0x35C));
        alpha = (u8)((f32)*(u8 *)(arg0 + 0x362) * fade);
        func_00274ed0(pos.x, pos.y, 0.0f, (alpha | ~0xFF), 6, 1, (const char *)D_0064D380[sel], 2, 0);
    }
    pos.x = 640.0f + (baseX + *(f32 *)(arg0 + 0x388));
    pos.y = 400.0f + (baseY + *(f32 *)(arg0 + 0x38C));
    alpha = (u8)((f32)*(u8 *)(arg0 + 0x392) * fade);
    func_0034f9d0(pos, 0.0f, alpha, *(u16 *)(arg0 + 0x38), *(s32 *)(arg0 + 0x474));
}
#else
INCLUDE_ASM("asm/nonmatchings/cmpConfig", func_0035d0a0);
#endif

// FUN_0035DCC0
s32 func_0035dcc0(u8 *arg0) {
    s32 flag = 1;
    s32 i = 0;
    s32 v = *(s16 *)(arg0 + 0x28);

    while (i < 18) {
        if (v < *(s32 *)(arg0 + i * 48 + 0xA4)) {
            flag = 0;
        }
        i++;
    }
    return flag & func_0034c210();
}

// FUN_0035DD40
void func_0035dd40(u8* arg0) {
    s32 i;

    *(u8*)(arg0 + 4) |= 2;
    for (i = 0; i < 6; i++) {
        if (*(s32*)(arg0 + i * 4 + 0x48) != 0) {
            func_00106390(D_0064D3A0[i], 1);
        } else {
            func_00106390(D_0064D3A0[i], 0);
        }
    }
}

// FUN_0035DDF0
void func_0035ddf0(u8 *arg0)
{
    s32 top; s32 bottom; s32 i; s32 d1; s32 d2; s64 score; s16 tmp1; s16 tmp2; u8 *p;
    *(s16 *)(arg0 + 0x2A) = *(s16 *)(arg0 + 0x2A) + 1;
    if (*(s16 *)(arg0 + 0x2A) >= 0x19) *(s16 *)(arg0 + 0x2A) = 0;
    *(s16 *)(arg0 + 0x2C) = *(s16 *)(arg0 + 0x2C) + 1;
    if (*(s16 *)(arg0 + 0x2C) >= 0x1E) *(s16 *)(arg0 + 0x2C) = 0;
    top = (s32)((11.0f * (f32)*(s16 *)(arg0 + 0x2A)) / 25.0f);
    bottom = (s32)(11.0f * (1.0f - ((f32)*(s16 *)(arg0 + 0x2C) / 30.0f)));
    i = 0;
    while (i < 0xB) {
        if (i < top) d1 = top - i; else d1 = i - top;
        if (i < bottom) d2 = bottom - i; else d2 = i - bottom;
        score = 1;
        tmp1 = (s16)(10 - d1 * 2);
        if (tmp1 > 1) score = tmp1;
        tmp2 = (s16)(8 - d2 * 2);
        if (score < tmp2) score = tmp2;
        p = arg0 + i * 0xA;
        *(s16 *)(p + 0x3D8) = (s16)score;
        func_0034f8f0(p + 0x3D8);
        i++;
    }
}







/* 1764/1776 bytes; seventeen resolved relocations and twelve zero tail bytes.
 * Member-first array bases preserve the four retail ADDU operand orders.
 * The second arrow reloads its counter/selection, but keeps the first
 * sprite/coordinate snapshot; both text draws reload their field data. */
// FUN_0035DFB0
void func_0035dfb0(u8 *arg0, s32 arg1, s32 arg2)
{
    u8 color[4];
    f32 opacity;
    f32 baseX;
    f32 baseY;
    f32 x;
    f32 y;
    f32 phase;
    f32 angle;
    f32 rowY;
    f32 rowOpacity;
    u32 arrowAlpha;
    u8 otherColor;
    u8 *sprite;
    u32 alpha;
    u8 *row;
    u16 counter;
    u32 counterAddress;
    u32 rowAddress;
    f32 *rowXField;
    f32 *rowYField;

    baseX = *(f32 *)(arg0 + 8);
    baseY = *(f32 *)(arg0 + 0xC);
    opacity = (f32)*arg0 / 255.0f;
    if (arg2 != 1) {
        rowAddress = arg1 * 0x30;
        rowAddress += (u32)arg0;
        row = (u8 *)rowAddress;
        x = 60.0f + (464.0f + (baseX + *(f32 *)(row + 0x208)));
        y = (119.0f + (baseY + *(f32 *)(row + 0x20C))) + 32.0f * (f32)arg1;
        arrowAlpha = (u8)((f32)*(u8 *)(row + 0x212) * opacity);
        sprite = *(u8 **)(arg0 + 0x45C);
        counterAddress = arg1 * 2;
        counterAddress += (u32)arg0;
        counter = *(u16 *)(counterAddress + 0x3A);
        if ((s32)counter < 5)
            phase = func_0044b7b0((iGpffff8094 * (f32)counter) / 5.0f);
        else
            phase = 1.0f;
        if (((s32 *)(arg0 + 0x48))[arg1] != 0)
            angle = (90.0f + 180.0f * phase) - 180.0f;
        else
            angle = (-90.0f + 180.0f * phase) - 180.0f;
        func_0034f320(sprite, x, y, 0.0f, 0xFF, 0xFF, 0xFF, arrowAlpha,
                      0x1000, 0x1000, 0x11, angle, 0x11);
    }
    if (arg2 == 2) {
        func_00489f80();
        D_00887300[0](1, 0);
        color[0] = 0;
        color[1] = 0;
        color[2] = 0;
        color[3] = 0;
        func_0045c870(color, 0);
        counterAddress = arg1 * 2;
        counterAddress += (u32)arg0;
        counter = *(u16 *)(counterAddress + 0x3A);
        if ((s32)counter < 5)
            phase = func_0044b7b0((iGpffff8094 * (f32)counter) / 5.0f);
        else
            phase = 1.0f;
        if (((s32 *)(arg0 + 0x48))[arg1] != 0)
            angle = (90.0f + 180.0f * phase) - 180.0f;
        else
            angle = (-90.0f + 180.0f * phase) - 180.0f;
        func_0034f320(sprite, x, y, 0.0f, 0xFF, 0xFF, 0xFF, 0xFF,
                      0x1000, 0x1000, 0x11, angle, 0x11);
        func_0048a000();
        func_003f6440(3, 0x2D801);
        func_003f6440(2, 0x44);
    }
    rowOpacity = (f32)arg0[arg1 * 0x30 + 0xC2];
    rowOpacity *= opacity;
    alpha = (u8)rowOpacity;
    if (arg2 == 1) {
        color[0] = 0x80; color[1] = 0x80; color[2] = 0x80; otherColor = 0x80;
    } else if (arg2 == 2) {
        color[0] = 0xFF; color[1] = 0xFF; color[2] = 0xFF; otherColor = 0xFF;
    } else {
        counterAddress = arg1 * 4;
        counterAddress += (u32)arg0;
        if (*(s32 *)(counterAddress + 0x48) != 0) {
            color[0] = 0xFF; color[1] = 0xFF; color[2] = 0xFF; otherColor = 0x80;
        } else {
            color[0] = 0x80; color[1] = 0x80; color[2] = 0x80; otherColor = 0xFF;
        }
    }
    rowXField = &((f32 *)(arg0 + 0x208))[arg1 * 12];
    x = (f32)0x1DD;
    x = x + (baseX + *rowXField);
    rowYField = (f32 *)(arg1 * 0x30 + arg0 + 0x20C);
    rowY = 32.0f * (f32)arg1;
    func_0034f2e0(*(u8 **)(arg0 + 0x454), x,
                  rowY + (121.0f + (baseY + *rowYField)),
                  color[0], color[1], color[2], alpha);
    func_0034f2e0(*(u8 **)(arg0 + 0x458),
                  556.0f + (baseX + *rowXField),
                  rowY + (131.0f + (baseY + *rowYField)),
                  otherColor, otherColor, otherColor, alpha);
    if (arg2 == 2) {
        func_003f6440(3, 0x717FB);
        func_003f6440(2, 0x44);
    }
}

// FUN_0035E6A0
void func_0035e6a0(u8* arg0) {
    s32 i;

    for (i = 0; i < 0xB; i++) {
        u8* q = arg0 + i * 4;
        s32 v = *(s32*)(q + 0x448);

        if (v != 0) {
            func_0046d280((void *)v);
            *(s32*)(arg0 + i * 4 + 0x448) = 0;
        }
    }
    *(s32*)(arg0 + 0x24) = 0;
}

// FUN_0035E720
s32 func_0035e720(u8* arg0) {
    u8* p = *(u8**)(arg0 + 0x38);
    s32 local;

    if (p[4] & 1) {
        return 0;
    }
    switch (func_0035f0c0((u32*)(p + 0x478), &local, p)) {
    case 0:
        if (local != 0) {
            *(s32*)(p + 0x47C) = 0;
            *(s32*)(p + 0x480) = 0;
            func_00460ac0(D_00793E80 + *(u16*)(p + 0x4AC) * 48, p + 0x47C);
        }
        break;
    case 2:
        p[4] |= 4;
        /* fallthrough */
    case 1:
        p[4] |= 1;
        break;
    default:
        func_0046d730(D_0064D3C8, 0x49E);
        break;
    }
    return 0;
}
