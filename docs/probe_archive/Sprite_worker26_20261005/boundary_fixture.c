/* Extracted from the current owner; see extraction.json. */
#ifndef TYPE_H
#define TYPE_H

typedef unsigned char u8;
typedef signed char s8;

typedef unsigned short u16;
typedef signed short s16;

typedef unsigned int u32;
typedef signed int s32;

typedef unsigned long long u64;
typedef signed long long s64;

typedef float f32;
typedef double f64;

typedef s32 intptr_t;
typedef u32 uintptr_t;

typedef u32 size_t;

#define NULL ((void*)0)

#endif // TYPE_H

static inline u32 sdkAddOffset(u32 offset, u32 base) { return offset + base; }

#if BOUNDARY_OLD
static inline f32 sdkSpriteRight(u8 *sample, s32 includeBorder)
{
    u32 value;
    u32 offset;
    u8 *output;
    u8 *overrideBase;
    f32 extent;

    offset = *(u32 *)(sample + 4) * 0x80;
    output = *(u8 **)(*(u8 **)sample + 0x204);
    value = *(s32 *)(sdkAddOffset(offset, (u32)output) + 0x5C) -
            *(s32 *)(sdkAddOffset(offset, (u32)output) + 0x54);
    overrideBase = output + 0x74;
    if (*(s16 *)(overrideBase + offset) != 0) {
        value = *(s16 *)(overrideBase + offset);
    }
    if (*(u16 *)(sample + 0x20) != 0) {
        value = (value * *(u16 *)(sample + 0x20)) >> 12;
    }
    extent = (f32)value;
    if (includeBorder != 0) {
        f32 border = (f32)*(s32 *)(sdkAddOffset(offset, (u32)output) + 0x40);
        extent -= (f32)*(s16 *)(sample + 0x1C);
        return border + extent;
    }
    extent -= (f32)*(s16 *)(sample + 0x1C);
    return extent;
}

static inline f32 sdkSpriteBottom(u8 *sample, s32 includeBorder)
{
    u32 value;
    u32 offset;
    u8 *output;
    u8 *overrideBase;
    f32 extent;

    offset = *(u32 *)(sample + 4) * 0x80;
    output = *(u8 **)(*(u8 **)sample + 0x204);
    value = *(s32 *)(sdkAddOffset(offset, (u32)output) + 0x60) -
            *(s32 *)(sdkAddOffset(offset, (u32)output) + 0x58);
    overrideBase = output + 0x76;
    if (*(s16 *)(overrideBase + offset) != 0) {
        value = *(s16 *)(overrideBase + offset);
    }
    if (*(u16 *)(sample + 0x22) != 0) {
        value = (value * *(u16 *)(sample + 0x22)) >> 12;
    }
    extent = (f32)value;
    if (includeBorder != 0) {
        f32 border = (f32)*(s32 *)(sdkAddOffset(offset, (u32)output) + 0x38);
        extent -= (f32)*(s16 *)(sample + 0x1E);
        return border + extent;
    }
    extent -= (f32)*(s16 *)(sample + 0x1E);
    return extent;
}

#else
static inline f32 sdkSpriteRight(u8 *sample, s32 includeBorder)
{
    u32 value;
    u32 offset;
    u8 *output;
    u8 *overrideBase;
    f32 extent;

    offset = *(u32 *)(sample + 4) * 0x80;
    output = *(u8 **)(*(u8 **)sample + 0x204);
    value = (u32)*(s32 *)(sdkAddOffset(offset, (u32)output) + 0x5C) -
            (u32)*(s32 *)(sdkAddOffset(offset, (u32)output) + 0x54);
    overrideBase = output + 0x74;
    if (*(s16 *)(overrideBase + offset) != 0) {
        value = *(s16 *)(overrideBase + offset);
    }
    if (*(u16 *)(sample + 0x20) != 0) {
        value = (value * *(u16 *)(sample + 0x20)) >> 12;
    }
    extent = (f32)value;
    if (includeBorder != 0) {
        f32 border = (f32)*(s32 *)(sdkAddOffset(offset, (u32)output) + 0x40);
        extent -= (f32)*(s16 *)(sample + 0x1C);
        return border + extent;
    }
    extent -= (f32)*(s16 *)(sample + 0x1C);
    return extent;
}

static inline f32 sdkSpriteBottom(u8 *sample, s32 includeBorder)
{
    u32 value;
    u32 offset;
    u8 *output;
    u8 *overrideBase;
    f32 extent;

    offset = *(u32 *)(sample + 4) * 0x80;
    output = *(u8 **)(*(u8 **)sample + 0x204);
    value = (u32)*(s32 *)(sdkAddOffset(offset, (u32)output) + 0x60) -
            (u32)*(s32 *)(sdkAddOffset(offset, (u32)output) + 0x58);
    overrideBase = output + 0x76;
    if (*(s16 *)(overrideBase + offset) != 0) {
        value = *(s16 *)(overrideBase + offset);
    }
    if (*(u16 *)(sample + 0x22) != 0) {
        value = (value * *(u16 *)(sample + 0x22)) >> 12;
    }
    extent = (f32)value;
    if (includeBorder != 0) {
        f32 border = (f32)*(s32 *)(sdkAddOffset(offset, (u32)output) + 0x38);
        extent -= (f32)*(s16 *)(sample + 0x1E);
        return border + extent;
    }
    extent -= (f32)*(s16 *)(sample + 0x1E);
    return extent;
}

#endif

/* The oracle widens subtraction and multiplication to 64 bits before taking
 * a remainder. The two tested helpers above are copied without modification. */
typedef char PointerWidthCheck[sizeof(void *) == 4 ? 1 : -1];
typedef char WordWidthCheck[sizeof(u32) == 4 ? 1 : -1];
typedef char FloatWidthCheck[sizeof(f32) == 4 ? 1 : -1];

typedef struct BoundsRecord {
    u8 reserved00[0x38];
    s32 bottomBorder;
    u8 reserved3C[4];
    s32 rightBorder;
    u8 reserved44[0x10];
    s32 left, top, right, bottom;
    u8 reserved64[0x10];
    s16 widthOverride, heightOverride;
    u8 reserved78[8];
} BoundsRecord;
typedef struct BoundsContainer {
    u8 reserved00[0x204];
    u8 *records;
    u8 reserved208[0x38];
} BoundsContainer;
typedef struct BoundsSample {
    u8 *container;
    u32 index;
    u8 reserved08[0x14];
    s16 pivotX, pivotY;
    u16 scaleX, scaleY;
    u8 reserved24[0x0C];
} BoundsSample;
typedef char RecordSizeCheck[sizeof(BoundsRecord) == 0x80 ? 1 : -1];
typedef char ContainerSizeCheck[sizeof(BoundsContainer) == 0x240 ? 1 : -1];
typedef char SampleSizeCheck[sizeof(BoundsSample) == 0x30 ? 1 : -1];
static BoundsContainer container;
static BoundsRecord records[2];
static BoundsSample sample;
static u32 failure;

static f32 reference(s32 upper, s32 lower, s16 replacement,
                     u16 scale, s16 pivot, s32 border, s32 includeBorder)
{
    const u64 modulus = 4294967296ULL;
    s64 difference = (s64)upper - (s64)lower;
    u64 extent = difference < 0 ? (u64)(difference + (s64)modulus) : (u64)difference;
    f32 result;
    if (replacement != 0) {
        s64 wide = replacement;
        extent = wide < 0 ? (u64)(wide + (s64)modulus) : (u64)wide;
    }
    if (scale != 0) {
        extent = ((extent * (u64)scale) % modulus) / 4096ULL;
    }
    result = (f32)extent;
    result -= (f32)pivot;
    return includeBorder != 0 ? (f32)border + result : result;
}

static u32 bits(f32 value)
{
    union { f32 f; u32 u; } view;
    view.f = value;
    return view.u;
}

static void prepare(s32 upper, s32 lower, s16 replacement, u16 scale,
                    s16 pivot, s32 border, u32 index)
{
    BoundsRecord *record = &records[index];
    sample.container = (u8 *)&container;
    sample.index = index;
    container.records = (u8 *)records;
    record->left = lower;
    record->top = lower;
    record->right = upper;
    record->bottom = upper;
    record->bottomBorder = border;
    record->rightBorder = border;
    record->widthOverride = replacement;
    record->heightOverride = replacement;
    sample.pivotX = pivot;
    sample.pivotY = pivot;
    sample.scaleX = scale;
    sample.scaleY = scale;
}

static u32 check(s32 upper, s32 lower, s16 replacement, u16 scale,
                 s16 pivot, s32 border, u32 index)
{
    s32 includeBorder;
    prepare(upper, lower, replacement, scale, pivot, border, index);
    for (includeBorder = 0; includeBorder < 2; includeBorder++) {
        f32 expected = reference(upper, lower, replacement, scale, pivot, border, includeBorder);
        if (bits(sdkSpriteRight((u8 *)&sample, includeBorder)) != bits(expected)) {
            failure = 1;
            return 0;
        }
        if (bits(sdkSpriteBottom((u8 *)&sample, includeBorder)) != bits(expected)) {
            failure = 2;
            return 0;
        }
    }
    return 4;
}

__attribute__((visibility("default"))) u32 run_ordinary(void)
{
    u32 count = 0;
    failure = 0;
    count += check(96, 16, 0, 0, 0, 7, 0);
    count += check(96, 16, 0, 4096, 7, -11, 1);
    count += check(96, 16, 27, 8192, -13, 4, 0);
    count += check(-16, -96, 0, 2048, 32767, -4, 1);
    count += check(8, 20, 0, 0, -32768, 4, 0);
    count += check(20, 8, -2, 65535, 0, 0, 1);
    return failure ? 0x80000000U | failure : count;
}

__attribute__((visibility("default"))) u32 run_extremes(void)
{
    const s32 bounds[][2] = {
        {2147483647, -1}, {-2147483647 - 1, 1},
        {2147483647, -2147483647 - 1}, {-2147483647 - 1, 2147483647},
        {2147483647, 0}, {-2147483647 - 1, 0},
        {0, -2147483647 - 1}, {-1, 2147483647}
    };
    const u16 scales[] = {0, 1, 4095, 4096, 8192, 65535};
    const s16 replacements[] = {0, 1, -1, 32767, -32768};
    u32 a, b, c, count = 0;
    failure = 0;
    for (a = 0; a < sizeof(bounds) / sizeof(bounds[0]); a++) {
        for (b = 0; b < sizeof(scales) / sizeof(scales[0]); b++) {
            for (c = 0; c < sizeof(replacements) / sizeof(replacements[0]); c++) {
                count += check(bounds[a][0], bounds[a][1], replacements[c], scales[b],
                               (a & 1) ? -32768 : 32767, (a & 2) ? -17 : 23, a & 1);
                if (failure) return 0x80000000U | failure;
            }
        }
    }
    return count;
}

__attribute__((visibility("default"))) u32 old_width_overflow(void)
{
    prepare(2147483647, -1, 0, 0, 0, 0, 0);
    return bits(sdkSpriteRight((u8 *)&sample, 0));
}

__attribute__((visibility("default"))) u32 old_height_overflow(void)
{
    prepare(-2147483647 - 1, 1, 0, 0, 0, 0, 1);
    return bits(sdkSpriteBottom((u8 *)&sample, 0));
}
