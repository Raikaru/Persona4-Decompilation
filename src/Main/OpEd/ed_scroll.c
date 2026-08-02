/* Source unit: src/Main/OpEd/ed_scroll_0038e6d0.c */
#include "type.h"
#include "include_asm.h"

extern void func_00271b70(u32 resource);

extern void func_00272950(u32 resource, s32 x, s32 y);
extern void func_00274a20(u32 resource, f32 angle);

extern void func_00272ba0(u32 resource, u32 color);
extern void func_00273170(u32 resource, s32 visible, s32 flags);

extern void func_0046d730(const char *file, s32 line);
extern char D_0064F220[];

extern u32 *D_007246A0;
extern s32 D_007246A4;
extern f32 fGpffff84fc;
extern f32 fGpffff8500;
extern s32 iGpffffa9ec;

extern u32 func_0038ee10(void);
extern u32 func_0038f950(void);
extern u32 func_0038f5e0(const u32 *stream);
extern u32 func_0038f5c0(const u32 *stream, u32 index);
extern u32 func_0038f5f0(const u32 *stream);
extern s32 func_00442948(const char *text);
extern void func_00442de8(void *dst, const void *src, s32 size);
extern void func_00272c60(s32 mode);
extern void func_00272c80(s32 mode);
extern u32 func_002724d0(const char *text, s32 style, s32 mode, s32 a, s32 b);
extern s32 func_002738d0(u32 handle);

typedef struct EdColor {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} EdColor;

void func_0038e6d0(u32 *record);
void func_0038e740(void);
u32 *func_0038e610(void);
void func_0038e810(u32 *work, char *text, s32 align);
void func_0038eae0(u32 *work, const f32 *pos);
void func_0038ebb0(u32 *work, const u8 *color);
u32 func_0038ec50(void);
s32 func_0038ecc0(void);
void func_0038ed30(void);

// FUN_0038DDF0
void func_0038ddf0(void)
{
    s32 i;
    u32 *work;

    if (D_007246A0 == NULL) {
        func_0046d730(D_0064F220, 0x6B);
    }
    work = D_007246A0;
    for (i = 0; i < 0x20; i++) {
        u32 *elem = (u32 *)((u8 *)work + i * 0x90);
        u32 *record = elem + 1;
        if ((~elem[1] & 1) == 0) {
            func_0038e6d0(record);
        }
    }
    D_007246A0 = NULL;
}

// FUN_0038DE90
void func_0038de90(void)
{
    u32 *work;

    if (D_007246A0 == NULL) {
        func_0046d730(D_0064F220, 0x6B);
    }
    work = D_007246A0;
    work[0x484] = 0;
    work[0x485] = 0;
    work[0x486] = 0x43e00000;
    work[0x487] = 0x43e00000;
    work[0x481] = 0;
    work[0x482] = 0;
    work[0x483] = 0;
    func_0038e740();
    work[0] |= 1;
    work[0x489] = 0;
}

// FUN_0038DF10
u32 func_0038df10(void)
{
    if (D_007246A0 == NULL) {
        func_0046d730(D_0064F220, 0x6B);
    }
    return D_007246A0[0] & 1;
}

// FUN_0038DF60
void func_0038df60(void)
{
    u32 *work;
    u32 *entry;
    u32 text;
    u32 stream;
    u32 frame;
    s32 i;
    s32 segmentFrames;
    s32 phaseEnd;
    s32 parse;
    s32 align;
    u32 type;
    f32 step;
    f32 drift;
    f32 height;
    f32 fade;
    f32 elapsed;

    if (D_007246A0 == NULL) {
        func_0046d730(D_0064F220, 0x6B);
    }
    work = D_007246A0;
    if ((~work[0] & 1) == 0) {
        if ((work[0] & 4) != 0) {
            *(f32 *)(work + 0x48a) = *(f32 *)((u8 *)(uintptr_t)work[0x488] + 0x8c);
            work[0x481] = 0;
            work[0x489] = 1;
            work[0] &= ~4u;
        }
        if (func_0038ee10() != 0) {
            iGpffffa9ec = 0x1e;
        } else {
            iGpffffa9ec = 0x12c;
        }
        switch (work[0x489]) {
        case 0:
            func_0038ee10();
            drift = fGpffff84fc;
            break;
        case 1:
            func_0038ee10();
            step = fGpffff8500 / ((*(f32 *)(work + 0x48a) - 208.0f) * 2.0f);
            segmentFrames = (s32)(fGpffff84fc / step);
            frame = work[0x481];
            if ((s32)frame < segmentFrames) {
                work[0x481] = frame + 1;
                func_0038ee10();
                elapsed = (f32)(s32)work[0x481];
                drift = fGpffff84fc - step * elapsed;
                *(f32 *)((u8 *)(uintptr_t)work[0x488] + 0x8c) =
                    *(f32 *)(work + 0x48a) -
                    (fGpffff84fc * elapsed - (step * 0.5f) * elapsed * elapsed);
            } else {
                phaseEnd = segmentFrames + iGpffffa9ec;
                if ((s32)frame < phaseEnd) {
                    work[0x481] = frame + 1;
                    drift = 0.0f;
                    *(f32 *)((u8 *)(uintptr_t)work[0x488] + 0x8c) = 208.0f;
                } else if ((s32)frame < phaseEnd + 0x2d) {
                    work[0x481] = frame + 1;
                    fade = ((f32)(segmentFrames + iGpffffa9ec + 0x2d -
                                  (s32)(frame + 1)) *
                            255.0f) /
                           45.0f;
                    ((u8 *)work)[0x122f] = (u8)fade;
                    drift = 0.0f;
                    *(f32 *)((u8 *)(uintptr_t)work[0x488] + 0x8c) = 208.0f;
                } else {
                    drift = 0.0f;
                    *(f32 *)((u8 *)(uintptr_t)work[0x488] + 0x8c) = 208.0f;
                    work[0] &= ~1u;
                }
            }
            break;
        default:
            break;
        }
        stream = func_0038f950();
        if ((~work[0] & 2) != 0) {
            height = *(f32 *)(work + 0x487) - drift;
            parse = 1;
            align = 0;
            while ((!(height < 448.0f)) == 0 && parse != 0) {
                type = func_0038ec50();
                switch (type) {
                case 0:
                    work[0] |= 2;
                    parse = 0;
                    *(f32 *)(work + 0x487) += drift;
                    break;
                case 1:
                {
                    entry = func_0038e610();
                    align = align != 0;
                    text = func_0038f5c0((const u32 *)(uintptr_t)stream, work[0x482]);
                    func_0038e810(entry, (char *)(uintptr_t)text, align);
                    frame = work[0x482];
                    work[0x482] = frame + 1;
                    if (frame + 1 == func_0038f5f0((const u32 *)(uintptr_t)stream)) {
                        work[0x488] = (u32)entry;
                        work[0] |= 4;
                    }
                    *(f32 *)((u8 *)entry + 0x8c) = *(f32 *)(work + 0x487);
                    *(f32 *)(work + 0x487) += 27.0f;
                    align = 0;
                    break;
                }
                case 2:
                    align = 1;
                    break;
                case 3:
                    *(f32 *)(work + 0x487) =
                        (f32)func_0038ecc0() * 25.0f + *(f32 *)(work + 0x487) + 0.0f;
                    break;
                case 4:
                    *(f32 *)(work + 0x487) += 10.0f;
                    break;
                default:
                    break;
                }
                func_0038ed30();
                height = *(f32 *)(work + 0x487) - drift;
            }
        }
        for (i = 0; i < 0x20; i++) {
            u32 *elem = (u32 *)((u8 *)work + i * 0x90);
            u32 *record = elem + 1;
            if ((~elem[1] & 1) == 0) {
                if ((*(f32 *)(record + 0x23) - drift) + 27.0f < 0.0f) {
                    func_0038e6d0(record);
                }
                *(f32 *)(record + 0x23) -= drift;
            }
        }
        *(f32 *)(work + 0x487) -= drift;
        func_0038e740();
    }
}

// FUN_0038E4B0
void func_0038e4b0(void)
{
    s32 i;
    s32 j;
    u32 packed;
    EdColor color;
    u32 *work;

    if (D_007246A0 == NULL) {
        func_0046d730(D_0064F220, 0x6B);
    }
    work = D_007246A0;
    if ((~work[0] & 1) != 0) {
        return;
    }
    color = *(EdColor *)((u8 *)work + 0x122c);
    for (i = 0, packed = (u32)color.r << 24 | (u32)color.g << 16 |
                         (u32)color.b << 8 | (u32)color.a;
         i < 0x20; i++) {
        u32 *elem = (u32 *)((u8 *)work + i * 0x90);
        u32 *record = elem + 1;
        if ((~elem[1] & 1) == 0) {
            for (j = 0; j < (s32)record[0x21]; j++) {
                u32 *handlePtr = (u32 *)((u8 *)record + j * 8 + 8);
                func_00272ba0(*(u32 *)((u8 *)record + j * 8 + 8), packed);
                func_00273170(*handlePtr, 1, 0);
            }
        }
    }
}

// FUN_0038E610
u32 *func_0038e610(void)
{
    s32 i;
    u32 *work;
    u32 *elem;
    u32 *record;

    if (D_007246A0 == NULL) {
        func_0046d730(D_0064F220, 0x6B);
    }
    work = D_007246A0;
    for (i = 0; i < 0x20; i++) {
        elem = (u32 *)((u8 *)work + i * 0x90);
        record = elem + 1;
        if ((elem[1] & 1) == 0) {
            break;
        }
    }
    if (!(i < 0x20)) {
        func_0046d730(D_0064F220, 0x1AA);
    }
    record[0] |= 1;
    return record;
}

// FUN_0038E6D0
void func_0038e6d0(u32* record)
{
    s32 i;

    for (i = 0; i < (s32)record[0x21]; i++) {
        func_00271b70(*(u32*)((u8*)record + i * 8 + 8));
    }
    record[0] &= ~1u;
}

// FUN_0038E740
void func_0038e740(void)
{
    u32 *work;
    u32 *elem;
    u32 *record;
    s32 i;
    f32 pos[2];

    if (D_007246A0 == NULL) {
        func_0046d730(D_0064F220, 0x6B);
    }
    work = D_007246A0;
    for (i = 0; i < 0x20; i++) {
        elem = (u32 *)((u8 *)work + i * 0x90);
        record = elem + 1;
        if ((~elem[1] & 1) == 0) {
            pos[0] = 57.0f;
            pos[1] = *(f32 *)((u8 *)record + 0x8c);
            func_0038eae0(record, pos);
            func_0038ebb0(record, (const u8 *)((u8 *)work + 0x122c));
        }
    }
}

// FUN_0038E810
void func_0038e810(u32 *work, char *text, s32 align)
{
    char *cursor;
    s32 length;
    char *start;
    s32 count;
    s32 tokenLength;
    f32 width;
    s32 i;
    s32 inToken;
    s32 style;
    s32 mode;
    char token[256];

    cursor = text;
    start = text;
    length = func_00442948(text);
    count = 0;
    func_00272c60(1);
    func_00272c80(2);
    inToken = 0;
    width = 0.0f;
    for (i = 0; i < length + 1; i++, cursor++) {
        char c = *cursor;
        switch (c) {
        case ' ':
        case '\0':
        case '\t':
            if (inToken != 0) {
                tokenLength = (s32)(cursor - start);
                func_00442de8(token, start, tokenLength);
                token[tokenLength] = 0;
                switch (align) {
                case 0:
                    style = 6;
                    D_007246A4 = style;
                    if (func_0038ee10() != 0) {
                        mode = 0xB;
                    } else {
                        mode = 9;
                    }
                    break;
                case 1:
                    style = 6;
                    D_007246A4 = style;
                    if (func_0038ee10() != 0) {
                        mode = 0xC;
                    } else {
                        mode = 0xA;
                    }
                    break;
                default:
                    break;
                }
                {
                    u32 handle = func_002724d0(token, (s8)style, (s8)mode, 0, 0);
                    func_00274a20(handle, 0.0f);
                    *(u32 *)((u8 *)work + count * 8 + 8) = handle;
                    *(f32 *)((u8 *)work + 4 + count * 8) = width;
                    count++;
                    start += tokenLength;
                    width += (f32)func_002738d0(handle);
                    inToken = 0;
                }
            }
            break;
        default:
            inToken = 1;
            break;
        }
        c = *cursor;
        switch (c) {
        case '\0':
            break;
        case ' ':
            width += 10.0f;
            break;
        case '\t':
            width += 14.0f;
            break;
        default:
            break;
        }
        switch (c) {
        case '\0':
            break;
        case ' ':
            start++;
            break;
        case '\t':
            start++;
            break;
        default:
            break;
        }
    }
    func_00272c80(1);
    func_00272c60(2);
    work[0x84 / 4] = count;
}

// FUN_0038EAE0
void func_0038eae0(u32* work, const f32* pos)
{
    s32 i;

    for (i = 0; i < (s32)work[0x84 / 4]; i++) {
        f32* entry = (f32*)((u8*)work + i * 8 + 4);
        func_00272950(*(u32*)(entry + 1), (s32)((pos[0] + entry[0]) * 16.0f),
                      (s32)(pos[1] * 8.0f));
        func_00274a20(*(u32*)(entry + 1), 0.0f);
    }
}

// FUN_0038EBB0
void func_0038ebb0(u32* work, const u8* color)
{
    s32 i;
    u32 packed;

    packed = (u32)color[0] << 24 | (u32)color[1] << 16 |
             (u32)color[2] << 8 | (u32)color[3];
    for (i = 0; i < (s32)work[0x84 / 4]; i++) {
        func_00272ba0(*(u32*)((u8*)work + i * 8 + 8), packed);
    }
}

// FUN_0038EC50
u32 func_0038ec50(void)
{
    u32 *work;
    u32 stream;
    u32 base;

    if (D_007246A0 == NULL) {
        func_0046d730(D_0064F220, 0x6B);
    }
    work = D_007246A0;
    stream = func_0038f950();
    base = func_0038f5e0((const u32 *)(uintptr_t)stream);
    return *(u8 *)(uintptr_t)(base + work[0x120c / 4]);
}

// FUN_0038ECC0
s32 func_0038ecc0(void)
{
    u32 *work;
    u32 stream;
    u32 base;

    if (D_007246A0 == NULL) {
        func_0046d730(D_0064F220, 0x6B);
    }
    work = D_007246A0;
    stream = func_0038f950();
    base = func_0038f5e0((const u32 *)(uintptr_t)stream);
    return *(u8 *)(uintptr_t)(work[0x120c / 4] + base + 1);
}

// FUN_0038ED30
void func_0038ed30(void)
{
    u32 *work;
    u32 stream;
    u32 base;
    s32 offset;
    u8 command;

    if (D_007246A0 == NULL) {
        func_0046d730(D_0064F220, 0x6B);
    }
    work = D_007246A0;
    stream = func_0038f950();
    base = func_0038f5e0((const u32 *)(uintptr_t)stream);
    offset = work[0x120c / 4];
    command = *(u8 *)(uintptr_t)(base + offset);
    switch (command) {
    case 0:
        break;
    case 1:
        work[0x120c / 4] = offset + 1;
        break;
    case 2:
        work[0x120c / 4] = offset + 1;
        break;
    case 3:
        work[0x120c / 4] = offset + 2;
        break;
    case 4:
        work[0x120c / 4] = offset + 1;
        break;
    }
}
