#include "byte_address_internal.h"
#include "operand_order_internal.h"
#include "member_access.h"
#include "mdl_file_internal.h"
/* Source unit: src/Graphics/Model/mdlFile_00230bc0.c (1 function markers) */
#include "type.h"

#define MODEL_TYPE_BTLCHAR 1
#define MODEL_TYPE_ENEMY 2

typedef int (*code)();
extern code DAT_008873ec_abs[];
extern u64 Vpad_Activate();
extern u64 func_0047de90_wide(u32 *wrapper);
extern u32 func_004b57a0_u32(u64 wrapper, u64 value);
extern u32 K_Clump_MatUsrDataGetInt();
extern u32 func_004578b0_ptr(u32 wrapper,u8 *value);
extern u8 DAT_00713200[];
extern u8 DAT_00713200_abs[];
extern u64 K_ClumpMatColorStore();


/* W409 measured: P3 donor carried NONMATCHING 204/224 nd74 -> MATCH 216/224 nd0 annotation; ported verbatim. */
extern u32 DAT_00922c30;
extern u8 DAT_00922c30_abs[];



/* Return whether the narrowed model type uses PAC resources; the ID is not consulted. */
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



/* Releases one reference on a shared wrapper: frees the handle at +4, decrements the object's count at +4 (freeing the object at zero) and frees the wrapper. */
// FUN_0047DCC0
void mdlReleaseSharedWrapper(int *wrapper)
{
    if (wrapper[1] != 0) {
        Vpad_Activate(wrapper[1]);
    }
    ((MdlFileSharedResource *)*wrapper)->references = ((MdlFileSharedResource *)*wrapper)->references - 1;
    if (((MdlFileSharedResource *)*wrapper)->references == 0) {
        ((void (*)())DAT_008873ec_abs[0])(*wrapper);
    }
    ((void (*)())DAT_008873ec_abs[0])(wrapper);
}




extern void (*iGpffffbb3c)();
extern void (*jtbl_008873EC[])(void *);
extern void Vpad_RefreshSelection(u8 *work);
extern void Vpad_Noop(u8 *track);
struct RuntimeWork;
extern void Vpad_SetColor(struct RuntimeWork* work, const u8* color);
extern f32 fGpffffbb4c;
extern f32 fGpffffbb48;
typedef struct Code47Vec4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Code47Vec4;
extern Code47Vec4 D_00922C40;
/* Refresh the attached secondary effect when its handle is present; the owning model argument is unused. */
// FUN_0047DD40
/* All three retail callers pass the owning model in a1 (00476808,
   00476BB0, 00478CC4); this secondary-effect updater does not read it. */
void mdlRefreshSecondaryEffect(u8 *attachment, void *model)
{
    u8 *effect;

    effect = (u8 *)((MdlFileAttachment *)attachment)->handle;
    if (effect != NULL) {
        Vpad_RefreshSelection(effect);
    }
}


/* Forward an existing secondary effect to its no-op callback. */
// FUN_0047DDA0
void mdlNoopSecondaryEffect(u8 *attachment)
{
    u8 *effect;

    effect = (u8 *)((MdlFileAttachment *)attachment)->handle;
    if (effect != NULL) {
        Vpad_Noop(effect);
    }
}


/* Retail forwards the requested color in a1 to the runtime color consumer. */
// FUN_0047DDD0
void mdlSetAttachmentColor(u8* attachment, const u8* color)
{
    struct RuntimeWork* work;

    work = (struct RuntimeWork*)((MdlFileAttachment *)attachment)->handle;
    if (work != NULL) {
        Vpad_SetColor(work, color);
    }
}


/* Stores a value at +4 of the wrapper, computed from the wrapper and the 64-bit argument through two helpers. */
// FUN_0047DE00
void mdlSetWrapperValue(int wrapper,u64 value)
{
  u64 resource;

  u32 result;

  resource = func_0047de90_wide((u32 *)wrapper);

  result = func_004b57a0_u32(resource,value);

  ((MdlFileAttachment *)wrapper)->handle = result;

  return;

}



/* Releases the handle at +4 of the wrapper and clears it to zero. */
// FUN_0047DE50
void mdlClearWrapperHandle(int wrapper)
{
  /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
  if (MEMBER(int, wrapper, MdlFileAttachment, handle) != 0) {
    /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
    Vpad_Activate(MEMBER(int, wrapper, MdlFileAttachment, handle));
    ((MdlFileAttachment *)wrapper)->handle = 0;
  }
  return;
}



/* Samples a scalar track at fparg0 by linear interpolation between the surrounding keys, clamped to the last key. Writes the value to fGpffffbb4c and returns &fGpffffbb48, which holds the time. */
// FUN_0047EF70
u8 *mdlSampleTrackScalar(u8 *track, f32 time)
{
    s32 lastIndex;
    s32 pairs;
    s32 mid;
    s32 hi;
    s32 lo;
    s32 stride;

    pairs = (s32)((MdlFileTrack *)track)->keys;
    lo = 0;
    lastIndex = *(s32 *)track - 1;
    hi = lastIndex;
    stride = ((MdlFileTrack *)track)->stride;
    do {
        mid = (lo + hi + 1) >> 1;
        /* Key times use the file-provided byte stride; only the interpolation payload has a fixed key layout. */
        if (time < ((MdlFileScalarKey *)(pairs + stride * mid))->time) {
            mid = mid - 1;
            hi = mid;
        } else {
            lo = mid;
        }
    } while (lo < hi);
    if ((u32)mid >= (u32)lastIndex) {
        fGpffffbb4c = ((MdlFileScalarKey *)((s32)byteAddressAdd((u32)(mid * 8), (u8 *)(pairs))))->value;
    } else {
        f32 x0;
        f32 y0;
        f32 x1;
        f32 y1;
        f32 ratio;

        x0 = ((MdlFileScalarKey *)pairs)[mid].time;
        y0 = ((MdlFileScalarKey *)pairs)[mid].value;
        ratio = time - x0;
        x1 = ((MdlFileScalarKey *)pairs)[mid + 1].time;
        ratio = ratio / (x1 - x0);
        y1 = ((MdlFileScalarKey *)pairs)[mid + 1].value;
        fGpffffbb4c = y0 + operandOrderMultiply(y1 - y0, ratio);
    }
    fGpffffbb48 = time;
    return (u8 *)&fGpffffbb48;
}


/* Apply callback for the colour row: takes the RGB word for the target and an alpha byte (1 minus the row's second float, scaled to 255), then writes the four bytes to the target material's colour user data. */
// FUN_0047F2C0
void mdlApplyMaterialColorRow(void *row,void *material)
{
  u32 packedColor;
  float opacity;
  u8 rgba[4];
  u32 alpha;

  packedColor = func_004578b0_ptr((u32)material,DAT_00713200_abs);

  opacity = (1.0f - ((f32 *)row)[1]) * 255.0f;

  alpha = ((u8)(opacity));
  rgba[2] = (u8)packedColor;
  rgba[1] = (u8)((u32)packedColor >> 8);
  rgba[0] = (u8)((u32)packedColor >> 0x10);
  rgba[3] = (u8)alpha;

  K_ClumpMatColorStore((u32)material,rgba);
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
    /* Key times use the file-provided byte stride; only the interpolation payload has a fixed key layout. */
    if (t < ((Code47Vec4 *)(keys + stride * mid))->x) {
      hi = --mid;
    }
    else {
      lo = mid;
    }
  } while (lo < hi);
  if ((u32)mid >= (u32)(*table - 1)) {
    entryAddr = mid * 0x10;
    entryAddr += (u32)keys;
    ((Code47Vec4 *)DAT_00922c30_abs)->y = ((Code47Vec4 *)entryAddr)->y;
    ((Code47Vec4 *)DAT_00922c30_abs)->z = ((Code47Vec4 *)entryAddr)->z;
    ((Code47Vec4 *)DAT_00922c30_abs)->w = ((Code47Vec4 *)entryAddr)->w;
  }
  else {
    entry = (float *)((u32)(mid * 0x10) + (u32)keys);
    start = entry[0];
    fraction = t - start;
    fraction /= entry[4] - start;
    value = entry[1];
    delta = entry[5] - value;
    ((Code47Vec4 *)DAT_00922c30_abs)->y = fraction * delta + value;
    value = entry[2];
    delta = entry[6] - value;
    ((Code47Vec4 *)DAT_00922c30_abs)->z = fraction * delta + value;
    value = entry[3];
    delta = entry[7] - value;
    ((Code47Vec4 *)DAT_00922c30_abs)->w = fraction * delta + value;
  }
  *(float *)DAT_00922c30_abs = t;
  return (u32 *)DAT_00922c30_abs;
}


/* Samples two Vec4 tracks at fparg0 and fparg1 and linearly blends their y, z and w components by fparg2 into D_00922C40. */
// FUN_0047F4D0
void *mdlBlendVec4Tracks(u8 *leftTrack, f32 leftTime, u8 *rightTrack, f32 rightTime,
                   f32 weight)
{
    Code47Vec4 first;
    Code47Vec4 second;

    first = *(Code47Vec4 *)mdlSampleVec4Track((int *)leftTrack, leftTime);
    second = *(Code47Vec4 *)mdlSampleVec4Track((int *)rightTrack, rightTime);
    D_00922C40.y = 0.0f + first.y + weight * (second.y - first.y);
    D_00922C40.z = 0.0f + first.z + weight * (second.z - first.z);
    D_00922C40.w = 0.0f + first.w + weight * (second.w - first.w);
    return &D_00922C40;
}


/* Samples the Vec4 leftTrack leftTrack at leftTime, then blends its three components toward the byte colour in rightTrack (bytes 0..2 divided by 255) by rightTime. Returns the sampled buffer. */
// FUN_0047F5B0
void *mdlBlendTrackColorBytes(u8 *track, f32 time, u8 *color, f32 weight)
{
    f32 *out;
    f32 second;
    f32 third;
    f32 first;
    f32 addend;
    f32 difference;

    out = (f32 *)mdlSampleVec4Track((int *)track, time);
    second = (f32)(u32)color[1] / 255.0f;
    third = (f32)(u32)color[2] / 255.0f;
    first = (f32)(u32)color[0] / 255.0f;

    difference = first;
    addend = out[1];
    difference -= addend;
    out[1] = (0.0f + (addend) + (weight) * (difference));

    difference = second;
    addend = out[2];
    difference -= addend;
    out[2] = (0.0f + (addend) + (weight) * (difference));

    difference = third;
    addend = out[3];
    difference -= addend;
    out[3] = (0.0f + (addend) + (weight) * (difference));
    return out;
}


/* Converts the float RGB components of track (words 1..3) to bytes at color + 4. */
// FUN_0047F710
void mdlStoreColorBytes(void *sample, void *material)
{
    u8 *dst;

    dst = (u8 *)material + 4;
    dst[0] = (u8)(255.0f * ((f32 *)sample)[1]);
    dst[1] = (u8)(255.0f * ((f32 *)sample)[2]);
    dst[2] = (u8)(255.0f * ((f32 *)sample)[3]);
}


/* 64/64 bytes; two resolved relocations. Pass the released object explicitly
 * rather than relying on an incidental live argument register. */
/* Drops one u16 reference at +8 and frees the object at zero. */
// FUN_004808B0
void mdlReleaseU16Ref(int wrapper)
{
  ((MdlFileReference *)wrapper)->references = ((MdlFileReference *)wrapper)->references - 1;
  if (((MdlFileReference *)wrapper)->references == 0) {
    ((void (*)(void *))DAT_008873ec_abs[0])((void *)wrapper);
  }
  return;
}



/* Adds one u16 reference at +8 and returns the object. */
// FUN_004808F0
u32 mdlRetainU16Ref(int wrapper)
{
  ((MdlFileReference *)wrapper)->references = ((MdlFileReference *)wrapper)->references + 1;

  return wrapper;

}



/* Appends one u32 to the table at *wrapper: stores it at the index given by the u16 count at +4, then increments the count. */
// FUN_00480910
void mdlAppendU32Entry(int *wrapper,u32 value)
{
  /* The append helper receives a word-shaped table header; the count shares its second word and keeps the original halfword representation. */
  ((MdlFileU32Table *)wrapper)->entries[((MdlFileU32Table *)wrapper)->count] = value;

  /* The append helper receives a word-shaped table header; the count shares its second word and keeps the original halfword representation. */
  MEMBER(short, (u8 *)wrapper, MdlFileU32Table, count) = (u16)wrapper[1] + 1;

  return;

}
