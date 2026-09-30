#include "include_asm.h"
#include "sdk_sprite_loader.h"
#include "sdk_task_registration.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit btlResultSimple.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

void func_0021dda0(void);
extern u16 *func_00452560();
void func_001437b0(void *arg0, s32 arg1, s32 arg2);
s32 func_001b5fd0(void);
void func_0025cbc0(void *arg0, s32 arg1, s32 arg2);
s32 func_0025cc70(void);
u8 *func_0046d200(u32 arg0, u32 arg1);
u32 RpRandom(void);
extern u16 D_008C024C[];
extern u16 D_008C024E[];
extern s32 D_00629380[];
extern s32 D_006291A0[];
extern s8 D_00629170[];
extern s32 D_00629560[];
extern s32 D_006295F0[];
void H_Cdvd_Destroy(u8 *ptr);
void func_0046b0d0(void *ptr);
void func_0046d280(void *node);
extern void (*jtbl_008873EC[])(void *ptr);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
void func_0044ea90(const void *msg, s32 id);
void memset(void *dst, s32 value, u32 size);

extern char D_00629628[];
extern char D_006290F0[];
extern char D_00629610[];
extern s64 func_001060b0(void);
extern s32 func_00110d60(s32 arg0);
void func_00440b68(void *msg, const void *file, s32 line);
extern u8 *func_00454a60(u8 *param, s32 mode);
void func_0046d730(const void *file, s32 line);
s32 func_0046a770(u32 param);
s32 H_Cdvd_IsFileLoaded(u8 *ptr);
u8 *func_00455ea0(u8 *param, s32 a, s32 *b);
s32 func_0046a750(s32 param);
void func_0021fea0(u8 *arg0, u8 *work);
void func_002214d0(u8 *task);
void func_0034f2e0(void *arg0, f32 arg1, f32 arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6);
extern s32 sprintf(void *dst, const void *fmt, ...);
void func_00460ac0(void *param, void *work);
extern u32 D_00795F20[];
s32 func_0021f520(u8 *arg0);
s32 func_0021de60(void);
static inline u32 addBase(u32 base, u32 index) { return base + index; }
extern char iGpffffa5b8;
extern u8 *iGpffffa5a0[2];
extern s32 iGpffffa5a8[2];
extern s32 iGpffffa5b0;
extern char iGpffffa5b4;

/* Work buffer handed to the result state machine (see func_002215c0). */
typedef struct BtlResultWork BtlResultWork;
struct BtlResultWork
{
    u16 flags;         // 0x00
    u16 pad02;         // 0x02
    u32 state;         // 0x04
    s32 field08;       // 0x08
    s32 field0C;       // 0x0C
    u8 pad10[0x2C];    // 0x10..0x3B
    u16 field3C;       // 0x3C
    u8 pad3E[0x3C2];   // 0x3E..0x3FF
    s32 field400[3];   // 0x400..0x40B
    u8 pad40C[8];      // 0x40C..0x413
    s32 field414[0x2A];// 0x414..0x4BB
    s32 field4BC;      // 0x4BC
    u8 pad4C0[0xB0];   // 0x4C0..0x56F
    u8 *field570;      // 0x570
};

s32 func_0021f340(BtlResultWork *work);
void func_0021ef70(BtlResultWork *work);
extern u8 func_002baac0(u8 *message);
void func_002bad10(s32 param);
void func_002bb4e0(void);
s32 func_00353f50(s32 param);
extern s32 func_0021f790(u8 *arg0);

typedef struct BtlResultSubWork BtlResultSubWork;
struct BtlResultSubWork
{
    u8 pad[0x60];
    s32 field60;       // 0x60
    u8 pad64[0x8D0];   // 0x64..0x933
    s32 field934;      // 0x934
};

/* Matched: 604 bytes, seven resolved relocations and four zero tail bytes.
 * Grouped values are unsigned; the plain retail format is signed "%d".
 * Scoped loop invariants retain the digit-loop constants and allocation. */
// FUN_0021ED10
#pragma opt_loop_invariants on
void func_0021ed10(u8 *arg0, f32 *arg1, f32 arg5, s32 arg2, u32 arg3, s32 arg4)
{
    s8 rev[0x40];
    s8 buf[0x40];
    u8 hi;
    u8 mid;
    u8 lo;
    u8 ch;
    s32 i;
    s32 n;
    s32 tmp;
    s32 k;
    s32 j;
    s32 digit;
    (void)arg5;

    hi = (u8)((arg2 & 0xFF000000) >> 24);
    mid = (u8)((u32)(arg2 & 0xFF0000) >> 16);
    lo = (u8)((u32)(arg2 & 0xFF00) >> 8);
    ch = arg2 & 0xFF;
    if (ch != 0) {
        if (arg3 >= 1000 && arg4 != 0) {
            k = 0;
            j = 0;
            do {
                buf[k] = (u8)((arg3 % 10) + 0x30);
                k += 1;
                arg3 /= 10;
                if (arg3 != 0 && j == 2) {
                    buf[k] = 0x2E;
                    k += 1;
                }
                j += 1;
                if (j > 2) {
                    j = 0;
                }
            } while (arg3 != 0);
            n = 0;
            while (n < k) {
                tmp = n + 1;
                rev[n] = buf[k - tmp];
                n = tmp;
            }
            rev[n] = 0;
        } else {
            sprintf(rev, &iGpffffa5b4, (s32)arg3);
        }
        i = 0;
        while (rev[i] != 0) {
            switch (rev[i]) {
            case 0x2E:
                func_0034f2e0(*(void **)(arg0 + 0x4A0),
                              arg1[0], arg1[1], hi, mid, lo, ch);
                arg1[0] += 8.0f;
                break;
            default:
                digit = rev[i] - 0x30;
                if (digit < 0 || digit > 9) {
                    func_0046d730(&D_00629610, 0x119);
                }
                func_0034f2e0(
                    *(void **)(arg0 + digit * 4 + 0x478),
                    arg1[0], arg1[1], hi, mid, lo, ch);
                arg1[0] += 22.0f;
                break;
            }
            i += 1;
        }
    }
}
#pragma opt_loop_invariants off




/* Matched: 976 bytes and all 29 relocations. Pointer slots and unsigned
 * resource-bank loads preserve the real constructor contract; scoped loop
 * invariants retain the retail table bases and register allocation. */
// FUN_0021EF70
#pragma opt_loop_invariants on
void func_0021ef70(BtlResultWork *work)
{
    u8 *base;
    u8 *row;
    u8 *src;
    u8 *p;
    u8 **out;
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    f32 base_value;
    f32 x;
    f32 y;
    u8 c;

    base = (u8 *)work;
    for (i = 0; i < 20; i++) {
        src = (u8 *)D_006291A0 + i * 0x18;
        row = base + i * 0x30;
        x = *(f32 *)(src + 0);
        *(f32 *)(row + 0x40) = x;
        *(f32 *)(row + 0x50) = x;
        y = *(f32 *)(src + 4);
        *(f32 *)(row + 0x44) = y;
        *(f32 *)(row + 0x54) = y;
        c = *(u8 *)(src + 8);
        *(u8 *)(row + 0x58) = c;
        *(u8 *)(row + 0x5A) = c;
        src = (u8 *)D_00629380 + i * 0x18;
        *(f32 *)(row + 0x48) = *(f32 *)(src + 0);
        *(f32 *)(row + 0x4C) = *(f32 *)(src + 4);
        *(u8 *)(row + 0x59) = *(u8 *)(src + 8);
        *(s32 *)(row + 0x68) = *(s32 *)(src + 0xC);
        *(s32 *)(row + 0x6C) = *(s32 *)(src + 0x10);
    }
    for (j = 0; j < 42; j++) {
        if (j < 13) {
            out = (u8 **)(base + j * 4 + 0x414);
            *out = func_0046d200(*(u32 *)(base + 0x400), (u32)D_00629170[j]);
        } else if (j < 15) {
            out = (u8 **)(base + j * 4 + 0x414);
            *out = func_0046d200(*(u32 *)(base + 0x404), (u32)D_00629170[j]);
        } else if (j < 25) {
            out = (u8 **)(base + j * 4 + 0x414);
            *out = func_0046d200(*(u32 *)(base + 0x40C), (u32)D_00629170[j]);
        } else if (j < 36) {
            out = (u8 **)(base + j * 4 + 0x414);
            *out = func_0046d200(*(u32 *)(base + 0x410), (u32)D_00629170[j]);
        } else {
            out = (u8 **)(base + j * 4 + 0x414);
            *out = func_0046d200(*(u32 *)(base + 0x408), (u32)D_00629170[j]);
        }
        if (*out == 0) {
            func_0046d730(&D_00629610, 0x159);
        }
    }
    for (k = 0; k < 5; k++) {
        p = base + k * 0x20;
        *(u32 *)(p + 0x4C8) = 0x43560000;
        row = p + 0x4C0;
        *(f32 *)(p + 0x4D0) = *(f32 *)(p + 0x4C8);
        *(f32 *)(row + 0x18) =
            (f32)((RpRandom() & 0xFFF) * 214) / 4096.0f;
        src = (u8 *)D_00629560 + k * 0x1C;
        base_value = *(f32 *)(src + 0x14);
        *(f32 *)(row + 4) = base_value +
            ((*(f32 *)(src + 0x18) - base_value) *
             (f32)(RpRandom() & 0xFFF)) / 4096.0f;
        *(s16 *)(row + 0) = 0;
        *(s16 *)(row + 2) =
            *(s32 *)(src + 8) + RpRandom() % *(u32 *)(src + 0xC);
    }
    for (m = 0; m < 2; m++) {
        row = base + m * 8;
        *(s16 *)(row + 0x564) = 0;
        *(f32 *)(row + 0x560) = *(f32 *)((u8 *)D_006295F0 + m * 0xC + 4);
    }
    *(s16 *)(base + 0x3C) = 0;
    *(s32 *)(base + 0x38) = 0;
}
#pragma opt_loop_invariants off
/* measured 2026-08-07: discarded raw_alias body reached nd 57 with object
   472B vs the 480B window. Retail precomputes the indexed field400 store
   address before func_0046af60; b210 keeps the loop/index colouring in the
   wrong saved registers and recomputes that address after the call. The
   direct, slot-pointer, reload, and add-base spellings all stayed at nd 254+
   or nd 275. Register-colouring/pre-call-hoist floor; leave the marker bare. */
/* measured 2026-08-08: raw u8* alias body reached object 472B / window
   480B but normalized_diff 57, so the body is discarded rather than parked.
   Exact residual fndiff offsets are 40, 44, 52, 60, 64, 68, 72, 76, 84, 88,
   92, 100, 104, 108, 112, 116, 120, 124, 156, 160, 164, 168, 324; first
   differing row is offset 40 (`lw $s2,0x4bc($s1)` vs retail
   `lw $a0,0x4bc($s1)`). The discarded body is archived in
   build/WCBattleUI_btlResultSimple_prepark_validate.c. */
// FUN_0021F340
s32 func_0021f340(BtlResultWork *work)
{
    s32 temp_4_2;
    s32 temp_4_3;
    s32 temp_4_4;
    s32 var_16;
    s32 var_18;
    s32 var_18_2;
    u16 temp_3;
    u8 *arg0;
    s32 *dest;

    arg0 = (u8 *)work;
    if (!(*(u16 *)(arg0 + 0) & 0x100)) {
        if (*(s32 *)(arg0 + 0x4BC) != 0 &&
            H_Cdvd_IsFileLoaded((u8 *)*(s32 *)(arg0 + 0x4BC)) != 0) {
            var_18 = 0;
            while (var_18 < 3) {
                dest = (s32 *)(arg0 + var_18 * 4 + 0x400);
                *dest = (s32)func_0046af60((u32)func_00455ea0(*(u8 **)(arg0 + 0x4BC), var_18, 0));
                if (*dest == 0) {
                    func_0046d730(&D_00629610, 0x181);
                }
                var_18 += 1;
            }
            *(u16 *)(arg0 + 0) |= 0x100;
        } else {
            return 0;
        }
    }
    if (!(*(u16 *)(arg0 + 0) & 0x20)) {
        var_18_2 = 0;
        var_16 = 0;
        while (var_18_2 < 3) {
            temp_4_2 = *(s32 *)(arg0 + var_18_2 * 4 + 0x400);
            if (temp_4_2 != 0 && func_0046a750(temp_4_2) != 0) {
                var_16 += 1;
            }
            var_18_2 += 1;
        }
        if (var_16 == 3) {
            *(u16 *)(arg0 + 0) |= 0x20;
            temp_4_3 = *(s32 *)(arg0 + 0x4BC);
            if (temp_4_3 != 0) {
                H_Cdvd_Destroy((u8 *)temp_4_3);
                *(s32 *)(arg0 + 0x4BC) = 0;
            }
        }
    }
    if (!(*(u16 *)(arg0 + 0) & 0x40)) {
        temp_4_4 = *(s32 *)(*(u8 **)(arg0 + 0x570) + 0x934);
        if (temp_4_4 != 0 && H_Cdvd_IsFileLoaded((u8 *)temp_4_4) != 0) {
            *(u16 *)(arg0 + 0) |= 0x40;
        }
    }
    temp_3 = *(u16 *)(arg0 + 0);
    if ((temp_3 & 0x20) && (temp_3 & 0x40)) {
        return 1;
    }
    return 0;
}




// FUN_0021F520
s32 func_0021f520(u8 *arg0) {
    u8 *work;
    u8 *sub;
    u32 state;
    s32 i;
    s32 v;

    work = *(u8 **)(arg0 + 0x38);
    sub = *(u8 **)(work + 0x570);
    state = *(u32 *)(work + 0x38);
    switch (state) {
    case 0:
        v = *(u16 *)(work + 0x3C);
        if (v >= 0x1E) {
            goto L;
        }
        *(u16 *)(work + 0x3C) = v + 1;
        for (i = 0; i < 0x14; i++) {
            switch (*(s32 *)((u8 *)D_00629380 + i * 0x18 + 0x14)) {
            case 0:
                func_001437b0(work + i * 0x30 + 0x40, *(u16 *)(work + 0x3C), 0);
                break;
            case 1:
                func_001437b0(work + i * 0x30 + 0x40, *(u16 *)(work + 0x3C), 1);
                break;
            }
        }
        if (*(u16 *)(work + 0x3C) != 0x1E) {
            goto L;
        }
        *(u16 *)(work + 0) |= 0x10;
        *(u16 *)(work + 0x3C) = 0;
        *(u32 *)(work + 0x38) = 1;
        goto L;
    case 1:
        v = (*(u16 *)(work + 0x3C) += 1);
        if ((v & 0xFFFF) < 4) {
            goto L;
        }
        if (func_001b5fd0() != 0x10) {
            goto L;
        }
        *(u32 *)(work + 0x38) = 2;
        goto L;
    case 2:
        if ((D_008C024E[0] & 0x40) || (D_008C024C[0] & 0x10)) {
            if (*(s16 *)(sub + 0x6F8) > 0) {
                func_002baac0((u8 *)((s32)func_00455ea0(*(u8 **)(sub + 0x934), 0, 0)));
                func_002bad10(0x17);
                *(u32 *)(work + 0x38) = 3;
            } else {
                *(u32 *)(work + 0x38) = 5;
            }
        }
        goto L;
    case 3:
        if (func_00353f50(1) != 0) {
            goto L;
        }
        func_002bb4e0();
        func_0025cbc0(arg0, 0, *(s16 *)(sub + 0x6F8));
        *(u32 *)(work + 0x38) = 4;
        goto L;
    case 4:
        if (func_0025cc70() != 0) {
            goto L;
        }
        *(u32 *)(work + 0x38) = 5;
        goto L;
    case 5:
        return 1;
    default:
    L:
        return 0;
    }
}
// FUN_0021F790
s32 func_0021f790(u8 *arg0) {
    BtlResultWork *work;
    u32 state;
    s32 v;

    work = (BtlResultWork *)func_00452560();
    work->field08 = 0;
    work->field0C = 0;
    func_00460ac0(&D_00795F20, &work->field08);
    state = work->state;
    switch (state) {
    case 0:
        work->state = 1;
        goto L;
    case 1:
        v = work->flags;
        if ((v & 1) && (v & 8)) {
            goto case2;
        }
        if ((v & 4) && (func_0021f340(work) != 0)) {
            work->flags &= 0xFFFB;
            work->flags |= 8;
        }
        goto L;
    case 2:
    case2:
        func_0021ef70(work);
        work->flags |= 2;
        work->state = 3;
        goto L;
    case 3:
        if (func_0021f520(arg0) != 0) {
            v = *(s32 *)(work->field570 + 0x60);
            if (v & 2) {
                work->state = 4;
                func_002baac0((u8 *)((s32)func_00455ea0(*(u8 **)(work->field570 + 0x934), 0, 0)));
                func_002bad10(2);
            } else if (v & 8) {
                work->state = 4;
                func_002baac0((u8 *)((s32)func_00455ea0(*(u8 **)(work->field570 + 0x934), 0, 0)));
                func_002bad10(1);
            } else if (v & 0x10) {
                work->flags &= 0xFFFE;
                work->state = 7;
            } else {
                work->flags &= 0xFFFE;
                work->state = 7;
                work->flags |= 0x80;
            }
        }
        goto L;
    case 4:
        if (func_00353f50(1) == 0) {
            func_002bb4e0();
            work->flags &= 0xFFFE;
            work->state = 7;
        }
        goto L;
    case 5:
        if (func_0021de60() != 0) {
            work->state = 6;
        case 6:
            if (work->flags & 0x80) {
                goto R1;
            }
            v = (work->field3C += 1);
            if ((v & 0xFFFF) < 5) {
                goto L;
            }
        R1:
            work->flags &= 0xFFFD;
            return -1;
        }
        goto L;
    case 7:
        goto L;
    default:
    L:
        return 0;
    }
}
/* Five 32-byte animation records begin at work+0x4C0. The initializer
 * in func_0021ef70 writes the same timer and coordinate fields. */
typedef struct ResultParticleState {
    u16 age;
    u16 duration;
    f32 amplitude;
    f32 position[2];
    f32 previous[2];
    f32 next[2];
} ResultParticleState;

typedef struct ResultParticleStyle {
    f32 originX;
    s32 resource;
    u32 minimumDuration;
    u32 durationRange;
    s32 motion;
    f32 minimumAmplitude;
    f32 maximumAmplitude;
} ResultParticleStyle;

/* Preserve the range-then-sample operand order of the native product. */
static inline f32 resultParticleProduct(f32 range, f32 sample)
{
    return range * sample;
}

/* Native b210 O2: 1108/1120 bytes, seventeen resolved relocations and
 * twelve zero alignment bytes. Update and draw the five result-screen
 * sprites using their individual motion and random-duration styles.
 * See docs/probe_archive/Result_particles_0021fa40_20260924.md. */
// FUN_0021FA40
void func_0021fa40(u8 *work)
{
    extern void func_00364c50(void);
    extern void func_00364c70(void);
    extern f32 sinf(f32 angle);
    extern f32 iGpffff83d8;
    extern f32 fGpffff81e0;
    u8 opacity;
    ResultParticleState *particle;
    const ResultParticleStyle *style;
    s32 i;
    void *resource;
    f32 x;
    f32 y;
    f32 amount;
    f32 minimum;
    u32 random;
    s32 nextAge;

    func_00364c50();
    for (i = 0; i < 5; i++) {
        particle = (ResultParticleState *)(work + 0x4C0 + i * sizeof(ResultParticleState));
        if ((*(u16 *)(*(u8 **)(work + 0x570) + 8) & 4) == 0 && *(s32 *)(work + 0x38) != 0) {
            /* Use the stored halfword result, including its wrap at 65535. */
            nextAge = (particle->age += 1);
            if (nextAge >= particle->duration) {
                particle->previous[0] = particle->position[0];
                random = RpRandom();
                particle->next[0] = (f32)((random & 0xFFF) * 214U) / 4096.0f;
                style = (const ResultParticleStyle *)((u8 *)D_00629560 + i * sizeof(ResultParticleStyle));
                minimum = style->minimumAmplitude;
                random = RpRandom();
                amount = (f32)(random & 0xFFF);
                amount = resultParticleProduct(style->maximumAmplitude - minimum, amount);
                /* The low twelve random bits select a fraction in [0, 1). */
                particle->amplitude = minimum + amount / 4096.0f;
                particle->age = 0;
                random = RpRandom();
                particle->duration = style->minimumDuration + random % style->durationRange;
            }
        }
        x = *(f32 *)(work + 0x2F0) + (*(f32 *)(work + 0x290) + *(f32 *)(work + 0x2C0));
        y = *(f32 *)(work + 0x294) + *(f32 *)(work + 0x2C4);
        opacity = *(u8 *)(work + 0x29A);
        style = (const ResultParticleStyle *)((u8 *)D_00629560 + i * sizeof(ResultParticleStyle));
        /* The sprite and opacity are captured before either motion callback. */
        resource = *(void **)(work + 0x414 + style->resource * 4);
        switch (style->motion) {
        case 0:
            amount = sinf((iGpffff83d8 * (f32)(u32)particle->age) / (f32)(u32)particle->duration);
            particle->position[0] = 0.0f + particle->previous[0] + amount * (particle->next[0] - particle->previous[0]);
            particle->position[1] = 0.0f + particle->previous[1] + amount * (particle->next[1] - particle->previous[1]);
            x += (f32)0x19F + particle->position[0];
            y += particle->position[1];
            break;
        case 1:
            amount = sinf((fGpffff81e0 * (f32)(u32)particle->age) / (f32)(u32)particle->duration);
            amount = -amount;
            x += 0.0f + style->originX + particle->amplitude * amount;
            break;
        default:
            func_0046d730(D_00629610, 0x2AD);
            break;
        }
        func_0034f2e0(resource, x, y, 0xFF, 0xFF, 0xFF, opacity);
    }
    func_00364c70();
}

/* Matched 2026-09-30: 5676/5680B, 65 resolved relocations and one zero
 * tail word. Typed flags and by-value positions recover the 0x120 frame;
 * separate position snapshots replace the former overlapping union.
 * Scoped loop invariants retain the interpolation constants. Per-dimension
 * scale lvalue views preserve the retail reloads, while scoped const draw
 * coordinates retain the anchor across both sprites without caching dy.
 */
// FUN_0021FEA0
#pragma push
#pragma opt_loop_invariants on
void func_0021fea0(u8 *arg0, u8 *arg1)
{
    typedef struct { f32 x, y; } Vec2f;
    typedef union { Vec2f xy; f32 v[2]; s64 bits; } ResultPosition;
    u8 *w;
    u8 *sprite;
    /* Typed flags avoid extending a cached byte-address lifetime across calls. */
    struct ResultSubHeader { u8 pad[8]; u16 flags; } *p16;
    u8 c19;
    u8 c18;
    u8 c17;
    u8 c193;
    u8 c182;
    u8 c172;
    s32 s19;
    u8 b18;
    u32 vt;
    u8 bEA;
    u8 b11A;
    u8 b22;
    u8 b17;
    u8 b172;
    u8 b173;
    u8 b174;
    u8 b175;
    s32 w444;
    s32 w4B0;
    s32 w4B4;
    s32 w4B8;
    s32 s21;
    s32 s7;
    s32 s16c;
    s32 s16c2;
    s32 fld64;
    u32 eret;
    s8 sidx;
    u8 *t3;
    u8 *t32;
    u8 *t6;
    u8 *t4;
    u32 v2;
    u32 v1;
    f32 rf2;
    f32 rf1;
    f32 f3;
    f32 f8;
    f32 scale;
    f32 coordinate;

    f32 nextDrawX;
    f32 secondaryNextX;
    u8 c11[4];
    u8 opacity;
    ResultPosition position;
    ResultPosition basePosition;
    ResultPosition offsetSnapshot;
    /* Separate copies correspond to the retail stack snapshots at F8, F0 and E8. */
    ResultPosition shadowBase;
    ResultPosition secondaryOffset;
    ResultPosition secondaryBase;
    s8 numberText[0x18];
    s32 sC[4];
    struct {
        u16 a0;
        s16 a2;
        u8 _pad[18];
        s16 b6;
        s16 b8;
    } aA0;
    extern f32 fGpffff8410;
    extern f32 fGpffff8414;
    extern f32 fGpffff8418;
    extern s32 (*D_00887300[])(s32, void *);
    void func_0034f320(u8 *, f32, f32, f32, u8, u8, u8, u8, u16, u16, s16, f32, s16);
    void func_0045db40(u8 *, u8 *, f32, s32, s32, s32, f32, f32, f32);
    void func_0045d6e0(u8 *, f32 *, f32, s32);
    s32 RpSkyRenderStateSet(s32, void *);
    void func_00364c50(void);
    void func_00364c70(void);
    s32 func_00104c70(s32);
    u32 func_0010d6d0(s16);
    s32 func_0021e050(u8 *);
    void func_001125d0(u8 *);
    void func_00112300(Vec2f, f32, u8, u8 *);
    int func_00274ed0(f32, f32, f32, s32, s8, s32, const char *, s32, s32);

    (void)arg0;
    w = arg1;
    if ((*(u16 *)w) & 2) {
        p16 = (*(struct ResultSubHeader **)(w + 0x570));
        vt = (u32)D_00887300;
        ((s32 (*)(s32, void *))*(u32 *)vt)(6, (void *)0);
        ((s32 (*)(s32, void *))*(u32 *)vt)(8, (void *)0);
        ((s32 (*)(s32, void *))*(u32 *)vt)(7, (void *)2);
        ((s32 (*)(s32, void *))*(u32 *)vt)(9, (void *)2);
        ((s32 (*)(s32, void *))*(u32 *)vt)(0xC, (void *)1);
        ((s32 (*)(s32, void *))*(u32 *)vt)(0xB, (void *)6);
        ((s32 (*)(s32, void *))*(u32 *)vt)(0xA, (void *)5);
        ((s32 (*)(s32, void *))*(u32 *)vt)(2, (void *)4);
        ((s32 (*)(s32, void *))*(u32 *)vt)(0xE, (void *)0);
        ((s32 (*)(s32, void *))*(u32 *)vt)(3, (void *)1);
        ((s32 (*)(s32, void *))*(u32 *)vt)(4, (void *)1);
        RpSkyRenderStateSet(3, (void *)0x717FB);
        RpSkyRenderStateSet(2, (void *)0x44);
        sC[0] = (s32)(-224.0f + (*(f32 *)(w + 0x1D0)));
        sC[1] = (s32)(224.0f + (*(f32 *)(w + 0x1D4)));
        sC[2] = 0x30C;
        sC[3] = 0x30C;
        c11[0] = 0xFF;
        c11[1] = 0xEA;
        c11[2] = 0x2C;
        c11[3] = 0xFF;
        ((s32 (*)(s32, void *))*(u32 *)vt)(1, (void *)0);
        func_00364c50();
        func_0045db40(&c11[0], (u8 *)&sC[0], 0.0f, 0, 0, 0, 45.0f, 1.0f, 1.0f);
        func_00364c70();
        sC[0] = (s32)(-224.0f + (*(f32 *)(w + 0x200)));
        sC[1] = (s32)(224.0f + (*(f32 *)(w + 0x204)));
        sC[2] = 0x30C;
        sC[3] = 0x30C;
        c11[0] = 0xFF;
        c11[1] = 0xAE;
        c11[2] = 0x20;
        c11[3] = 0xFF;
        func_00364c50();
        ((s32 (*)(s32, void *))*(u32 *)vt)(1, (void *)0);
        func_0045db40(&c11[0], (u8 *)&sC[0], 0.0f, 0, 0, 0, 45.0f, 1.0f, 1.0f);
        func_00364c70();
        position.v[0] =(386.0f + (*(f32 *)(w + 0x1A0)));
        position.v[1] =(35.0f + (*(f32 *)(w + 0x1A4)));
        opacity = *(u8 *)(w + 0x1AA);
        sprite = *(u8 **)(w + 0x4A4);
        func_0034f2e0(sprite, position.v[0], position.v[1], 0x32, 0x32, 0x32, opacity);
        ((s32 (*)(s32, void *))*(u32 *)vt)(1, (void *)0);
        sC[0] = (s32)((*(f32 *)(w + 0x1D0)));
        sC[1] = (s32)((*(f32 *)(w + 0x1D4)));
        sC[2] = 0x19F;
        sC[3] = 0x1C0;
        c11[0] = 0xFF;
        c11[1] = 0xEA;
        c11[2] = 0x2C;
        c11[3] = 0xFF;
        func_0045d6e0(&c11[0], (f32 *)&sC[0], 0.0f, 0);
        coordinate = (f32)0x275;
        coordinate += (*(f32 *)(w + 0x1D0));
        sC[0] = (s32)(coordinate);
        sC[1] = (s32)((*(f32 *)(w + 0x1D4)));
        sC[2] = 0x12;
        sC[3] = 0x1C0;
        c11[0] = 0xFF;
        c11[1] = 0xEA;
        c11[2] = 0x2C;
        c11[3] = 0xFF;
        func_0045d6e0(&c11[0], (f32 *)&sC[0], 0.0f, 0);
        func_0021fa40(w);
        RpSkyRenderStateSet(3, (void *)0x32801);
        ((s32 (*)(s32, void *))*(u32 *)vt)(8, (void *)1);
        sC[0] = 0;
        sC[1] = 0;
        sC[2] = 0x280;
        sC[3] = 0x1C0;
        c11[0] = 0;
        c11[1] = 0;
        c11[2] = 0;
        c11[3] = 0;
        func_0045d6e0(&c11[0], (f32 *)&sC[0], 20.0f, 0);
        coordinate = (f32)0x19F;
        coordinate += (*(f32 *)(w + 0x260));
        sC[0] = (s32)(coordinate);
        sC[1] = (s32)(35.0f + (*(f32 *)(w + 0x264)));
        sC[2] = 0xFE;
        sC[3] = 0x1F4;
        c11[0] = 0xFF;
        c11[1] = 0xFF;
        c11[2] = 0xFF;
        c11[3] = 0;
        func_0045d6e0(&c11[0], (f32 *)&sC[0], 0.0f, 0);
        RpSkyRenderStateSet(3, (void *)0x717FB);
        ((s32 (*)(s32, void *))*(u32 *)vt)(8, (void *)0);
        ((s32 (*)(s32, void *))*(u32 *)vt)(6, (void *)1);
        b18 = (*(u8 *)(w + 0x17A));
        position.v[0] =(73.0f + (*(f32 *)(w + 0x170)));
        coordinate = (f32)0x187;
        coordinate += (*(f32 *)(w + 0x174));
        position.v[1] = coordinate;
                sprite = *(u8 **)(w + 0x448);
                func_0034f320(sprite, position.v[0], position.v[1], 10.0f, 0x2DU, 0x2DU, 0x2DU,
                    b18, 0x1000, 0x1000, 0, 0.0f, (s64)0);
        coordinate = (f32)0x111;
        coordinate += (*(f32 *)(w + 0x170));
        position.v[0] = coordinate;
        coordinate = (f32)0x187;
        coordinate += (*(f32 *)(w + 0x174));
        position.v[1] = coordinate;
                sprite = *(u8 **)(w + 0x44C);
                func_0034f320(sprite, position.v[0], position.v[1], 10.0f, 0x2DU, 0x2DU, 0x2DU,
                    b18, 0x1000, 0x1000, 0, 0.0f, (s64)0);
        ((s32 (*)(s32, void *))*(u32 *)vt)(6, (void *)0);
        ((s32 (*)(s32, void *))*(u32 *)vt)(6, (void *)1);
        position.v[0] =(76.0f + (*(f32 *)(w + 0x170)));
        coordinate = (f32)0x171;
        coordinate += (*(f32 *)(w + 0x174));
        position.v[1] = coordinate;
                sprite = *(u8 **)(w + 0x434);
                func_0034f320(sprite, position.v[0], position.v[1], 10.0f, 0x2DU, 0x2DU, 0x2DU,
                    b18, 0x1000, 0x1000, 0, 0.0f, (s64)0);
        if (p16->flags & 4) {
            c11[0] = 0;
            c11[1] = 0;
            c11[2] = 0;
        } else {
            c11[0] = 0xEC;
            c11[1] = 0x7C;
            c11[2] = 0;
        }
        position.v[0] =(1.0f + (117.0f + (*(f32 *)(w + 0x170))));
        coordinate = (f32)0x175;
        coordinate += (*(f32 *)(w + 0x174));
        position.v[1] = coordinate;
        sprintf(numberText, &iGpffffa5b4, func_00104c70(1) & 0xFF);
        s19 = 0;
        while (numberText[s19] != 0) {
            sidx = numberText[s19];
                sprite = *(u8 **)(w + sidx * 4 + 0x390);
            func_0034f320(sprite, position.v[0], position.v[1], 10.0f,
                    c11[0], c11[1], c11[2], b18, 0x1000, 0x1000, 0, 0.0f, (s64)0);
            position.v[0] += 16.0f;
            s19 += 1;
        }
        position.v[0] =(157.0f + (*(f32 *)(w + 0x170)));
        position.v[1] =((366.0f + (*(f32 *)(w + 0x174))) - 2.0f);
        func_00274ed0(position.v[0], position.v[1], 10.0f, (((u8)b18 & 0xFF) | ~0xFF), 5, 1, (const char *)func_0010d6d0(1), 0, 0);
        ((s32 (*)(s32, void *))*(u32 *)vt)(6, (void *)0);
        if (p16->flags & 4) {
            c19 = 0x67;
            c18 = 0x5F;
            c17 = 0x1F;
            w444 = (s32)(*(s32 *)(w + 0x444));
            position.v[0] =(78.0f + (*(f32 *)(w + 0xE0)));
            position.v[1] =(53.0f + (*(f32 *)(w + 0xE4)));
            opacity = *(u8 *)(w + 0xEA);
            func_0034f2e0((void *)(w444), position.v[0], position.v[1], 0x95, 0x88, 0x17, opacity);
            position.v[0] =(75.0f + (*(f32 *)(w + 0x110)));
            position.v[1] =(113.0f + (*(f32 *)(w + 0x114)));
            opacity = *(u8 *)(w + 0x11A);
            func_0034f2e0((void *)(w444), position.v[0], position.v[1], 0x95, 0x88, 0x17, opacity);
            position.v[0] =(75.0f + (*(f32 *)(w + 0x140)));
            position.v[1] =(172.0f + (*(f32 *)(w + 0x144)));
            opacity = *(u8 *)(w + 0x14A);
            func_0034f2e0((void *)(w444), position.v[0], position.v[1], 0x95, 0x88, 0x17, opacity);
        } else {
            c18 = 0;
            c17 = 0;
            c19 = 0;
            fld64 = (*(s32 *)((u8 *)p16 + 0x64));
            position.v[0] =(75.0f + (*(f32 *)(w + 0xE0)));
            position.v[1] =(52.0f + (*(f32 *)(w + 0xE4)));
            bEA = (u8)((*(u8 *)(w + 0xEA)));
            func_0021ed10(w, &position.v[0], 0.0f, bEA | (s32)0xEC7C0000, fld64, 0);
            sprite = *(u8 **)(w + 0x42C);
            func_0034f2e0(sprite, 5.0f + position.v[0], 9.0f + position.v[1], 0xEC, 0x7C, 0, bEA);
            eret = (u32)(func_0021e050((u8 *)&p16->flags));
            position.v[0] =(75.0f + (*(f32 *)(w + 0x110)));
            position.v[1] =(112.0f + (*(f32 *)(w + 0x114)));
            b11A = (u8)((*(u8 *)(w + 0x11A)));
            func_0021ed10(w, &position.v[0], 0.0f, b11A | (s32)0xEC7C0000, eret, 1);
            sprite = *(u8 **)(w + 0x430);
            func_0034f2e0(sprite, 5.0f + position.v[0], 9.0f + position.v[1], 0xEC, 0x7C, 0, b11A);
            position.v[0] =(73.0f + (*(f32 *)(w + 0x140)));
            position.v[1] =(162.0f + (*(f32 *)(w + 0x144)));
            b22 = (u8)((*(u8 *)(w + 0x14A)));
            s21 = 0;
            while (s21 < (*(s32 *)((u8 *)(p16) + 0x38))) {
                func_001125d0((u8 *)&aA0);
                t3 = (u8 *)((u8 *)p16 + (s21 * 4));
                aA0.a0 = (u16)((*(u16 *)((u8 *)(t3) + 0x2C)));
                aA0.a2 = (s16)((*(s16 *)((u8 *)(t3) + 0x2E)));
                aA0.b6 = 6;
                aA0.b8 = 5;
                func_00112300(position.xy, 0.0f, b22, (u8 *)&aA0);
                position.v[1] += 34.0f;
                s21 += 1;
            }
        }
        position.v[0] =(68.0f + (*(f32 *)(w + 0xE0)));
        position.v[1] =(20.0f + (*(f32 *)(w + 0xE4)));
        opacity = *(u8 *)(w + 0xEA);
        sprite = *(u8 **)(w + 0x418);
        func_0034f2e0(sprite, position.v[0], position.v[1], c19, c18, c17, opacity);
        position.v[0] =(67.0f + (*(f32 *)(w + 0x110)));
        position.v[1] =(80.0f + (*(f32 *)(w + 0x114)));
        opacity = *(u8 *)(w + 0x11A);
        sprite = *(u8 **)(w + 0x414);
        func_0034f2e0(sprite, position.v[0], position.v[1], c19, c18, c17, opacity);
        position.v[0] =(68.0f + (*(f32 *)(w + 0x140)));
        position.v[1] =(139.0f + (*(f32 *)(w + 0x144)));
        opacity = *(u8 *)(w + 0x14A);
        sprite = *(u8 **)(w + 0x41C);
        func_0034f2e0(sprite, position.v[0], position.v[1], c19, c18, c17, opacity);
        sC[0] = 0;
        sC[1] = 0x14;
        sC[2] = 0x46;
        sC[3] = 0xFA;
        c11[0] = 0xFF;
        c11[1] = 0xE9;
        c11[2] = 0xE;
        c11[3] = (u8)((*(u8 *)(w + 0x23A)));
        func_0045d6e0(&c11[0], (f32 *)&sC[0], 0.0f, 1);
        if (p16->flags & 4) {
            c193 = 0x67;
            c182 = 0x5F;
            c172 = 0x1F;
        } else {
            c193 = 0;
            c182 = 0;
            c172 = 0;
        }
        position.v[0] =(17.0f + (*(f32 *)(w + 0x50)));
        position.v[1] =(20.0f + (*(f32 *)(w + 0x54)));
        opacity = *(u8 *)(w + 0x5A);
        sprite = *(u8 **)(w + 0x420);
        func_0034f2e0(sprite, position.v[0], position.v[1], c193, c182, c172, opacity);
        position.v[0] =(17.0f + (*(f32 *)(w + 0x80)));
        position.v[1] =(80.0f + (*(f32 *)(w + 0x84)));
        opacity = *(u8 *)(w + 0x8A);
        sprite = *(u8 **)(w + 0x424);
        func_0034f2e0(sprite, position.v[0], position.v[1], c193, c182, c172, opacity);
        position.v[0] =(17.0f + (*(f32 *)(w + 0xB0)));
        position.v[1] =(139.0f + (*(f32 *)(w + 0xB4)));
        opacity = *(u8 *)(w + 0xBA);
        sprite = *(u8 **)(w + 0x428);
        func_0034f2e0(sprite, position.v[0], position.v[1], c193, c182, c172, opacity);
        if (p16->flags & 4) {
            s7 = 0;
            while (s7 < 2) {
                t32 = (u8 *)(w + (s7 * 8));
                t6 = (u8 *)(t32 + 0x560);
                t4 = (u8 *)D_006295F0 + s7 * 0xC;
                if (++(*(u16 *)(t32 + 0x564)) < (*(u16 *)t4)) {
                    goto skip_zero;
                }
                (*(u16 *)(t6 + 4)) = 0;
            skip_zero:
                f3 = (*(f32 *)(t4 + 4));
                v2 = (*(u16 *)(t6 + 4));
                rf2 = (f32)v2;
                v1 = (*(u16 *)t4);
                rf1 = (f32)v1;
                f8 = (*(f32 *)(t4 + 8));
                (*(f32 *)t6) = f3 + (rf2 / rf1) * (f8 - f3);
                s7 += 1;
            }
            coordinate = (f32)0x1D7;
            coordinate += (*(f32 *)(w + 0x320));
            position.v[0] = coordinate;
            position.v[1] =(506.0f + (*(f32 *)(w + 0x324)));
            b17 = (*(u8 *)(w + 0x32A));
            w4B0 = (s32)(*(s32 *)(w + 0x4B0));
            func_00364c50();
            func_0034f320((u8 *)w4B0, position.v[0], position.v[1], 0.0f, 0xFFU, 0xFFU, 0xFFU, b17, 0x1000, 0x1000, 0, -72.0f, (s64)0);
            func_00364c70();
            coordinate = (f32)0x107;
            coordinate += (*(f32 *)(w + 0x350));
            position.v[0] = coordinate;
            basePosition.v[0] = position.v[0];
            position.v[1] = (464.0f + (*(f32 *)(w + 0x354)));
            basePosition.v[1] = position.v[1];
            b172 = (*(u8 *)(w + 0x35A));
            w4B4 = (s32)(*(s32 *)(w + 0x4B4));
            func_00364c50();
            func_0034f320((u8 *)w4B4, position.v[0], position.v[1], 0.0f, 0xFFU, 0xFFU, 0xFFU, b172, 0x1000, 0x1000, 0, -30.0f, (s64)0);
            func_00364c70();
            position.v[0] =((*(f32 *)(w + 0x3B0)) + (*(f32 *)(w + 0x560)));
            position.v[1] =((*(f32 *)(w + 0x3B4)));
            b173 = (*(u8 *)(w + 0x3BA));
            s16c = 0;
            while (s16c < 3) {
                shadowBase = basePosition;
                offsetSnapshot = position;
                shadowBase.xy.y += 5.5f;
                /* Immutable snapshots keep the two draws on the same origin. */
                {
                    const f32 anchorY = shadowBase.xy.y;
                    const f32 drawX = offsetSnapshot.v[0] + shadowBase.xy.x;
                    const f32 drawY = offsetSnapshot.v[1] + anchorY;
                    sprite = *(u8 **)(w + 0x4A8);
                    func_0034f320(sprite, drawX, drawY, 0.0f, 0, 0, 0, b173, (u16)fGpffff8410,
                        (u16)*(f32 *)&fGpffff8410, (s16)(shadowBase.xy.x - drawX), -30.0f, (s16)(shadowBase.xy.y - drawY));
                    nextDrawX = (fGpffff8414 + drawX);
                    func_0034f320(*(u8 **)(w + 0x4AC), nextDrawX, drawY, 0.0f, 0, 0, 0, b173, (u16)fGpffff8410,
                        (u16)*(f32 *)&fGpffff8410, (s16)(shadowBase.xy.x - nextDrawX), -30.0f, (s16)(anchorY - drawY));
                }
                position.v[0] += fGpffff8418;
                s16c += 1;
            }
            position.v[0] = ((*(f32 *)(w + 0x380)) - 88.0f);
            basePosition.v[0] = position.v[0];
            position.v[1] = (200.0f + (*(f32 *)(w + 0x384)));
            basePosition.v[1] = position.v[1];
            b174 = (*(u8 *)(w + 0x38A));
            w4B8 = (s32)(*(s32 *)(w + 0x4B8));
            func_00364c50();
            func_0034f320((u8 *)w4B8, position.v[0], position.v[1], 0.0f, 0xFFU, 0xFFU, 0xFFU, b174, 0x1000, 0x1000, 0, 15.0f, (s64)0);
            func_00364c70();
            position.v[0] =((*(f32 *)(w + 0x3E0)) + (*(f32 *)(w + 0x568)));
            position.v[1] =((*(f32 *)(w + 0x3E4)));
            b175 = (*(u8 *)(w + 0x3EA));
            s16c2 = 0;
            while (s16c2 < 3) {
                secondaryBase = basePosition;
                secondaryOffset = position;
                secondaryBase.xy.y += 10.0f;
                {
                    const f32 secondaryAnchorY = secondaryBase.xy.y;
                    const f32 secondaryDrawX = secondaryOffset.xy.x + secondaryBase.xy.x;
                    const f32 secondaryDrawY = secondaryOffset.xy.y + secondaryAnchorY;
                    /* A named floating scale preserves the per-argument conversion. */
                    scale = 4096.0f;
                    sprite = *(u8 **)(w + 0x4A8);
                    func_0034f320(sprite, secondaryDrawX, secondaryDrawY, 0.0f, 0, 0, 0, b175,
                        (u16)scale, (u16)scale, (s16)(secondaryBase.xy.x - secondaryDrawX), 15.0f,
                        (s16)(secondaryBase.xy.y - secondaryDrawY));
                    secondaryNextX = 225.0f + secondaryDrawX;
                    func_0034f320(*(u8 **)(w + 0x4AC), secondaryNextX, secondaryDrawY, 0.0f, 0, 0, 0, b175,
                        (u16)scale, (u16)scale, (s16)(secondaryBase.xy.x - secondaryNextX), 15.0f,
                        (s16)(secondaryAnchorY - secondaryDrawY));
                }
                position.v[0] -= (f32) 0x157;
                s16c2 += 1;
            }
        }
    }

}

#pragma pop
/* measured: retail allocates p=$s0, loop-addr=$s1, counter=$s2; mwcc b210
   invariantly allocates the named values to $s1/$s0 and the indexed store
   address temp to $s2 (counter<->addr rotation, nd 12, rest byte-identical).
   Tried: struct-vs-pointer arith for the 0x4BC block, every declaration order
   of p/w/i (8 variants), loop-local addr pointers, shared addr var, u16/u32
   counters; all give the identical 12-word rotation. Register-coloring floor. */
// FUN_002214D0
void func_002214d0(u8 *unusedTask) {
    BtlResultWork *p;
    s32 i;
    s32 j;

    p = (BtlResultWork *)func_00452560();
    if (p->field4BC != 0) {
        H_Cdvd_Destroy((void *)p->field4BC);
        p->field4BC = 0;
    }
    for (i = 0; i < 3; i++) {
        s32 *el = (s32 *)(addBase((u32)p, (u32)(i * 4)) + 0x400);
        if (*el != 0) {
            func_0046b0d0((void *)*el);
            *el = 0;
        }
    }
    for (j = 0; j < 0x2A; j++) {
        s32 *el = (s32 *)(addBase((u32)p, (u32)(j * 4)) + 0x414);
        if (*el != 0) {
            func_0046d280((void *)*el);
            *el = 0;
        }
    }
    jtbl_008873EC[0](p);
}
// FUN_002215C0
s32 func_002215c0(s32 arg0) {
    u8 *buf;
    u16 *q;
    s32 r;

    func_0044ea90(&D_00629628, 0x3A);
    buf = (u8 *)(*jtbl_008873E8)(0x578, 0x40000);
    memset(buf, 0, 0x578);
    r = (s32)func_00451fc0((void *)(arg0), (const void *)(D_006290F0), 0xF, 0, 0, func_0021f790, func_002214d0, (u8 *)(buf));
    q = func_00452560(arg0);
    *(s32 *)(buf + 4) = 0;
    *(u16 **)(buf + 0x570) = q;
    memset(buf + 8, 0, 0x30);
    *(void (**)(u8 *, u8 *))(buf + 0x10) = func_0021fea0;
    *(u8 **)(buf + 0x18) = buf;
    return r;
}

// FUN_002216B0
void func_002216b0(void) {
    u16 *temp_2;

    temp_2 = func_00452560();
    *temp_2 |= 1;
}

// FUN_002216E0
void func_002216e0(void) {
    u16 *temp_2;

    temp_2 = func_00452560();
    if (temp_2[0] & 0x80) {
        func_0021dda0();
        *(s32 *)(temp_2 + 2) = 5;
        return;
    }
    *(s16 *)((u8 *)temp_2 + 0x3C) = 0;
    *(s32 *)(temp_2 + 2) = 6;
}

// FUN_00221740
u16 func_00221740(void) {
    u16 *temp_2;

    temp_2 = func_00452560();
    return temp_2[0] & 1;
}

/* measured 2026-08-14: retail frame 64B with work=$s0, index=$s1, and
   field400 destination=$s2. Complete iGp declarations, a u32 masked result
   local, and the explicit field400 destination expression reproduce the
   368B window exactly. */
// FUN_00221770
void func_00221770(void) {
    s32 *dst;
    s32 i;
    BtlResultWork *work;

    work = (BtlResultWork *)func_00452560();
    {
        u32 r;
        r = (u32)func_00110d60((s16)func_001060b0()) & 1;
        i = (0U < r) ^ 1U;
    }
    func_00440b68(&iGpffffa5b8, &D_00629610, 1410);
    work->field4BC = (s32)func_00454a60(iGpffffa5a0[i], 1);
    if (work->field4BC == 0) {
        func_0046d730(&D_00629610, 1411);
    }
    i = 3;
    for (; i < 5; i++) {
        dst = (s32 *)((u8 *)work + i * 4 + 0x400);
        *dst = func_0046a770(*(s32 *)((u8 *)iGpffffa5a8 + i * 4 - 12));
        if (*dst == 0) {
            func_0046d730(&D_00629610, 1419);
        }
    }
    func_00440b68(&iGpffffa5b8, &D_00629610, 1423);
    ((BtlResultSubWork *)work->field570)->field934 =
        (s32)func_00454a60((u8 *)iGpffffa5b0, 1);
    if (((BtlResultSubWork *)work->field570)->field934 == 0) {
        func_0046d730(&D_00629610, 1424);
    }
    work->flags |= 4;
}
