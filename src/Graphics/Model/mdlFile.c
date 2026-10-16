/* Source unit: src/Graphics/Model/mdlFile_00230bc0.c (1 function markers) */
#include "type.h"

#define MODEL_TYPE_BTLCHAR 1
#define MODEL_TYPE_ENEMY 2

typedef int (*code)();
extern code DAT_008873ec_abs[];
extern u64 Vpad_Activate();
extern u64 func_0047de90_wide(u32 *param_1);
extern u32 func_004b57a0_u32(u64 param_1, u64 param_2);
extern u32 K_Clump_MatUsrDataGetInt();
extern u32 func_004578b0_ptr(u32 param_1,u8 *param_2);
extern u8 DAT_00713200[];
extern u8 DAT_00713200_abs[];
extern u64 K_ClumpMatColorStore();

static inline u8 mdlFileToU8(f32 value)
{
  return (u8)value;
}

/* W409 measured: P3 donor carried NONMATCHING 204/224 nd74 -> MATCH 216/224 nd0 annotation; ported verbatim. */
extern u32 DAT_00922c30;
extern u8 DAT_00922c30_abs[];



// FUN_00230BC0
s32 mdlFileIsTypePac(u32 type, u16 id)
{
    switch ((u16)type)
    {
        case MODEL_TYPE_BTLCHAR: // fallthrough
        case MODEL_TYPE_ENEMY:   return 1;
    }

    return 0;
}



/* Releases one reference on a shared wrapper: frees the handle at +4, decrements the object's count at +0 (freeing the object at zero) and frees the wrapper. */
// FUN_0047DCC0
void mdlReleaseSharedWrapper(int *param_1)
{
    if (param_1[1] != 0) {
        Vpad_Activate(param_1[1]);
    }
    *(int*)(*param_1 + 4) = *(int*)(*param_1 + 4) - 1;
    if (*(int*)(*param_1 + 4) == 0) {
        ((void (*)())DAT_008873ec_abs[0])(*param_1);
    }
    ((void (*)())DAT_008873ec_abs[0])(param_1);
}




extern void (*iGpffffbb3c)();
extern void (*jtbl_008873EC[])(void *);
extern void Vpad_RefreshSelection(u8 *arg0);
extern void Vpad_Noop(u8 *arg0);
struct RuntimeWork;
extern void Vpad_SetColor(struct RuntimeWork* work, const u8* color);
static inline s32 viewAddReverse(s32 base, s32 offset)
{
    return offset + base;
}
extern f32 fGpffffbb4c;
extern f32 fGpffffbb48;
static inline f32 code1_0047_mul(f32 left, f32 right)
{
    return left * right;
}
static inline f32 code1_0047_madd_reverse(f32 left, f32 right, f32 addend)
{
    return 0.0f + addend + right * left;
}
typedef struct Code47Vec4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Code47Vec4;
extern Code47Vec4 D_00922C40;
// FUN_0047DD40
/* All three retail callers pass the owning model in a1 (00476808,
   00476BB0, 00478CC4); this secondary-effect updater does not read it. */
void mdlRefreshSecondaryEffect(u8 *arg0, void *model)
{
    u8 *effect;

    effect = *(u8 **)(arg0 + 4);
    if (effect != NULL) {
        Vpad_RefreshSelection(effect);
    }
}


// FUN_0047DDA0
void mdlNoopSecondaryEffect(u8 *arg0)
{
    u8 *effect;

    effect = *(u8 **)(arg0 + 4);
    if (effect != NULL) {
        Vpad_Noop(effect);
    }
}


/* Retail forwards the requested color in a1 to the runtime color consumer. */
// FUN_0047DDD0
void mdlSetAttachmentColor(u8* attachment, const u8* color)
{
    struct RuntimeWork* work;

    work = *(struct RuntimeWork**)(attachment + 4);
    if (work != NULL) {
        Vpad_SetColor(work, color);
    }
}


/* Stores a value at +4 of the wrapper, computed from the wrapper and the 64-bit argument through two helpers. */
// FUN_0047DE00
void mdlSetWrapperValue(int param_1,u64 param_2)
{
  u64 uVar1;

  u32 uVar2;

  uVar1 = func_0047de90_wide((u32 *)param_1);

  uVar2 = func_004b57a0_u32(uVar1,param_2);

  *(u32 *)(param_1 + 4) = uVar2;

  return;

}



/* Releases the handle at +4 of the wrapper and clears it to zero. */
// FUN_0047DE50
void mdlClearWrapperHandle(int param_1)
{
  if (*(int *)(param_1 + 4) != 0) {
    Vpad_Activate(*(int *)(param_1 + 4));
    *(u32 *)(param_1 + 4) = 0;
  }
  return;
}



/* Samples a scalar track at fparg0 by linear interpolation between the surrounding keys, clamped to the last key. Writes the value to fGpffffbb4c and returns &fGpffffbb48, which holds the time. */
// FUN_0047EF70
u8 *mdlSampleTrackScalar(u8 *arg0, f32 fparg0)
{
    s32 lastIndex;
    s32 pairs;
    s32 mid;
    s32 hi;
    s32 lo;
    s32 stride;

    pairs = (s32)*(u8 **)(arg0 + 0xC);
    lo = 0;
    lastIndex = *(s32 *)arg0 - 1;
    hi = lastIndex;
    stride = *(s32 *)(arg0 + 8);
    do {
        mid = (lo + hi + 1) >> 1;
        if (fparg0 < *(f32 *)(pairs + (stride * mid))) {
            mid = mid - 1;
            hi = mid;
        } else {
            lo = mid;
        }
    } while (lo < hi);
    if ((u32)mid >= (u32)lastIndex) {
        fGpffffbb4c = *(f32 *)(viewAddReverse(pairs, mid * 8) + 4);
    } else {
        f32 x0;
        f32 y0;
        f32 x1;
        f32 y1;
        f32 ratio;

        x0 = *(f32 *)(pairs + (mid * 8));
        y0 = *(f32 *)(pairs + (mid * 8) + 4);
        ratio = fparg0 - x0;
        x1 = *(f32 *)(pairs + (mid * 8) + 8);
        ratio = ratio / (x1 - x0);
        y1 = *(f32 *)(pairs + (mid * 8) + 0xC);
        fGpffffbb4c = y0 + code1_0047_mul(y1 - y0, ratio);
    }
    fGpffffbb48 = fparg0;
    return (u8 *)&fGpffffbb48;
}


/* Apply callback for the colour row: takes the RGB word for the target and an alpha byte (1 minus the row's second float, scaled to 255), then writes the four bytes to the target material's colour user data. */
// FUN_0047F2C0
void mdlApplyMaterialColorRow(void *param_1,void *param_2)
{
  u32 uVar1;
  float fVar2;
  u8 rgba[4];
  u32 alpha;

  uVar1 = func_004578b0_ptr((u32)param_2,DAT_00713200_abs);

  fVar2 = (1.0f - ((f32 *)param_1)[1]) * 255.0f;

  alpha = mdlFileToU8(fVar2);
  rgba[2] = (u8)uVar1;
  rgba[1] = (u8)((u32)uVar1 >> 8);
  rgba[0] = (u8)((u32)uVar1 >> 0x10);
  rgba[3] = (u8)alpha;

  K_ClumpMatColorStore((u32)param_2,rgba);
  return;
}







/* measured: mdlSampleVec4Track remains 300B in a 304B retail window with
 * only one retail zero-tail word. Keeping the exact helper static in this
 * code1 TU exposes its real register clobbers to MWCC, so mdlBlendVec4Tracks
 * retains $t1/$f13/$f14 across both calls. The pointer-first source signature
 * preserves the independent integer/float ABI while ordering the second
 * call's $a0 setup before $f12; mdlBlendVec4Tracks is 216B in a 224B window with
 * only two retail zero-tail words. */
/* Samples the Vec4 track table at t: binary search over the key times, interpolates the four components into DAT_00922c30, and returns that buffer with t in its first word. */
// FUN_0047F3A0
static u32 *mdlSampleVec4Track(int *table, float t)
{
  float *entry;
  float fraction;
  float start;
  float value;
  float delta;
  int hi;
  int lo;
  int stride;
  u8 *keys;
  int mid;
  u32 entryAddr;

  keys = (u8 *)table[3];
  lo = 0;
  hi = *table - 1;
  stride = table[2];
  do {
    mid = (lo + hi + 1) >> 1;
    if (t < *(float *)(keys + stride * mid)) {
      hi = --mid;
    }
    else {
      lo = mid;
    }
  } while (lo < hi);
  if ((u32)mid >= (u32)(*table - 1)) {
    entryAddr = mid * 0x10;
    entryAddr += (u32)keys;
    *(float *)(DAT_00922c30_abs + 4) = *(float *)(entryAddr + 4);
    *(float *)(DAT_00922c30_abs + 8) = *(float *)(entryAddr + 8);
    *(float *)(DAT_00922c30_abs + 12) = *(float *)(entryAddr + 0xc);
  }
  else {
    entry = (float *)((u32)(mid * 0x10) + (u32)keys);
    start = entry[0];
    fraction = t - start;
    fraction /= entry[4] - start;
    value = entry[1];
    delta = entry[5] - value;
    *(float *)(DAT_00922c30_abs + 4) = fraction * delta + value;
    value = entry[2];
    delta = entry[6] - value;
    *(float *)(DAT_00922c30_abs + 8) = fraction * delta + value;
    value = entry[3];
    delta = entry[7] - value;
    *(float *)(DAT_00922c30_abs + 12) = fraction * delta + value;
  }
  *(float *)DAT_00922c30_abs = t;
  return (u32 *)DAT_00922c30_abs;
}


/* Samples two Vec4 tracks at fparg0 and fparg1 and linearly blends their y, z and w components by fparg2 into D_00922C40. */
// FUN_0047F4D0
void *mdlBlendVec4Tracks(u8 *arg0, f32 fparg0, u8 *arg1, f32 fparg1,
                   f32 fparg2)
{
    Code47Vec4 first;
    Code47Vec4 second;

    first = *(Code47Vec4 *)mdlSampleVec4Track((int *)arg0, fparg0);
    second = *(Code47Vec4 *)mdlSampleVec4Track((int *)arg1, fparg1);
    D_00922C40.y = 0.0f + first.y + fparg2 * (second.y - first.y);
    D_00922C40.z = 0.0f + first.z + fparg2 * (second.z - first.z);
    D_00922C40.w = 0.0f + first.w + fparg2 * (second.w - first.w);
    return &D_00922C40;
}


/* Samples the Vec4 track arg0 at fparg0, then blends its three components toward the byte colour in arg1 (bytes 0..2 divided by 255) by fparg1. Returns the sampled buffer. */
// FUN_0047F5B0
void *mdlBlendTrackColorBytes(u8 *arg0, f32 fparg0, u8 *arg1, f32 fparg1)
{
    f32 *out;
    f32 second;
    f32 third;
    f32 first;
    f32 addend;
    f32 difference;

    out = (f32 *)mdlSampleVec4Track((int *)arg0, fparg0);
    second = (f32)(u32)arg1[1] / 255.0f;
    third = (f32)(u32)arg1[2] / 255.0f;
    first = (f32)(u32)arg1[0] / 255.0f;

    difference = first;
    addend = out[1];
    difference -= addend;
    out[1] = code1_0047_madd_reverse(difference, fparg1, addend);

    difference = second;
    addend = out[2];
    difference -= addend;
    out[2] = code1_0047_madd_reverse(difference, fparg1, addend);

    difference = third;
    addend = out[3];
    difference -= addend;
    out[3] = code1_0047_madd_reverse(difference, fparg1, addend);
    return out;
}


/* Converts the float RGB components of arg0 (words 1..3) to bytes at arg1 + 4. */
// FUN_0047F710
void mdlStoreColorBytes(void *arg0, void *arg1)
{
    u8 *dst;

    dst = (u8 *)arg1 + 4;
    dst[0] = (u8)(255.0f * ((f32 *)arg0)[1]);
    dst[1] = (u8)(255.0f * ((f32 *)arg0)[2]);
    dst[2] = (u8)(255.0f * ((f32 *)arg0)[3]);
}


/* 64/64 bytes; two resolved relocations. Pass the released object explicitly
 * rather than relying on an incidental live argument register. */
/* Drops one u16 reference at +8 and frees the object at zero. */
// FUN_004808B0
void mdlReleaseU16Ref(int param_1)
{
  *(u16 *)(param_1 + 8) = *(u16 *)(param_1 + 8) - 1;
  if (*(u16 *)(param_1 + 8) == 0) {
    ((void (*)(void *))DAT_008873ec_abs[0])((void *)param_1);
  }
  return;
}



/* Adds one u16 reference at +8 and returns the object. */
// FUN_004808F0
u32 mdlRetainU16Ref(int param_1)
{
  *(u16 *)(param_1 + 8) = *(u16 *)(param_1 + 8) + 1;

  return param_1;

}



/* Appends one u32 to the table at *param_1: stores it at the index given by the u16 count at +4, then increments the count. */
// FUN_00480910
void mdlAppendU32Entry(int *param_1,u32 param_2)
{
  *(u32 *)(*param_1 + (u32)*(u16 *)(param_1 + 1) * 4) = param_2;

  *(short *)(param_1 + 1) = (u16)param_1[1] + 1;

  return;

}
