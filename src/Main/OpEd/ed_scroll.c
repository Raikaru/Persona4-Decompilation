/* Source unit: src/Main/OpEd/ed_scroll_0038e6d0.c */
#include "type.h"
#include "include_asm.h"
#include "fr_font_internal.h"
#include "ed_staff_internal.h"
#include "ed_scroll_internal.h"

extern void frFontListKeepOrRelease(u32 list);

extern void frFontMoveListTo(u32 list, s32 x, s32 y);
extern void frFontExSetScale(u32 font, f32 scale);

extern void frFontSetGlyphColor(u32 list, u32 color);

extern void kAssertFail(const char *file, s32 line);
extern char D_0064F220[];

extern u32 *D_007246A0;
extern s32 D_007246A4;
extern f32 fGpffff84fc;
extern f32 fGpffff8500;
extern s32 iGpffffa9ec;

extern u32 edScrollShortHoldEnabled(void);
extern u32 edResGetStream(void);
extern s32 strlen(const char *text);
extern void strncpy(void *dst, const void *src, s32 size);
extern void frFontSetFlagBits(s32 bits);
extern void frFontClearFlagBits(s32 bits);
extern s32 frFontNodeWidth(u32 node);

typedef struct EdColor {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} EdColor;

void edScrollFreeRecord(u32 *record);
void edScrollLayoutRecords(void);
u32 *edScrollAllocRecord(void);
void edScrollLayoutText(u32 *work, char *text, s32 align);
void edScrollMoveRecord(u32 *work, const f32 *pos);
void edScrollSetRecordColor(u32 *work, const u8 *color);
u32 edScrollStreamCommand(void);
s32 edScrollStreamOperand(void);
void edScrollStreamAdvance(void);

// Intent: Release every scroll record and clear the work pointer [inferred]
// FUN_0038DDF0
void edScrollRelease(void)
{
    s32 i;
    u32 *work;

    if (D_007246A0 == NULL) {
        kAssertFail(D_0064F220, 0x6B);
    }
    work = D_007246A0;
    for (i = 0; i < 0x20; i++) {
        u32 *elem = (u32 *)((u8 *)work + i * 0x90);
        u32 *record = elem + 1;
        if ((~elem[1] & 1) == 0) {
            edScrollFreeRecord(record);
        }
    }
    D_007246A0 = NULL;
}

// Intent: Start the roll: reset the scroll offsets and timers, lay out the records and set the active bit [inferred]
// FUN_0038DE90
void edScrollStart(void)
{
    u32 *work;

    if (D_007246A0 == NULL) {
        kAssertFail(D_0064F220, 0x6B);
    }
    work = D_007246A0;
    ((EdScrollWork *)work)->unk1210 = 0;
    ((EdScrollWork *)work)->unk1214 = 0;
    *(u32 *)&((EdScrollWork *)work)->unk1218 = 0x43e00000;
    *(u32 *)&((EdScrollWork *)work)->nextY = 0x43e00000;
    ((EdScrollWork *)work)->phaseFrame = 0;
    ((EdScrollWork *)work)->textIndex = 0;
    ((EdScrollWork *)work)->streamOffset = 0;
    edScrollLayoutRecords();
    ((EdScrollWork *)work)->flags |= 1;
    ((EdScrollWork *)work)->phase = 0;
}

// Intent: Report whether the roll is active [inferred]
// FUN_0038DF10
u32 edScrollIsActive(void)
{
    if (D_007246A0 == NULL) {
        kAssertFail(D_0064F220, 0x6B);
    }
    return D_007246A0[0] & 1;
}

// Intent: Per-frame roll step: run the hold and scroll phases, parse stream commands into new text records and drift them up [inferred]
// FUN_0038DF60
/* Typed staff-roll members change b210 address materialization; retain byte/word
 * accesses to ed_scroll_internal.h layouts to keep the retail instructions. */
void edScrollStep(void)
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
        kAssertFail(D_0064F220, 0x6B);
    }
    work = D_007246A0;
    if ((~work[0] & 1) == 0) {
        if ((work[0] & 4) != 0) {
            *(f32 *)(work + 0x48a) = *(f32 *)((u8 *)(uintptr_t)work[0x488] + 0x8c);
            work[0x481] = 0;
            work[0x489] = 1;
            work[0] &= ~4u;
        }
        if (edScrollShortHoldEnabled() != 0) {
            iGpffffa9ec = 0x1e;
        } else {
            iGpffffa9ec = 0x12c;
        }
        switch (work[0x489]) {
        case 0:
            edScrollShortHoldEnabled();
            drift = fGpffff84fc;
            break;
        case 1:
            edScrollShortHoldEnabled();
            step = fGpffff8500 / ((*(f32 *)(work + 0x48a) - 208.0f) * 2.0f);
            segmentFrames = (s32)(fGpffff84fc / step);
            frame = work[0x481];
            if ((s32)frame < segmentFrames) {
                work[0x481] = frame + 1;
                edScrollShortHoldEnabled();
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
        stream = edResGetStream();
        if ((~work[0] & 2) != 0) {
            height = *(f32 *)(work + 0x487) - drift;
            parse = 1;
            align = 0;
            while ((!(height < 448.0f)) == 0 && parse != 0) {
                type = edScrollStreamCommand();
                switch (type) {
                case 0:
                    work[0] |= 2;
                    parse = 0;
                    *(f32 *)(work + 0x487) += drift;
                    break;
                case 1:
                {
                    entry = edScrollAllocRecord();
                    align = align != 0;
                    text = brpParamGetEntry((const u32 *)(uintptr_t)stream, work[0x482]);
                    edScrollLayoutText(entry, (char *)(uintptr_t)text, align);
                    frame = work[0x482];
                    work[0x482] = frame + 1;
                    if (frame + 1 == brpParamReadWord1((const u32 *)(uintptr_t)stream)) {
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
                        (f32)edScrollStreamOperand() * 25.0f + *(f32 *)(work + 0x487) + 0.0f;
                    break;
                case 4:
                    *(f32 *)(work + 0x487) += 10.0f;
                    break;
                default:
                    break;
                }
                edScrollStreamAdvance();
                height = *(f32 *)(work + 0x487) - drift;
            }
        }
        for (i = 0; i < 0x20; i++) {
            u32 *elem = (u32 *)((u8 *)work + i * 0x90);
            u32 *record = elem + 1;
            if ((~elem[1] & 1) == 0) {
                if ((*(f32 *)(record + 0x23) - drift) + 27.0f < 0.0f) {
                    edScrollFreeRecord(record);
                }
                *(f32 *)(record + 0x23) -= drift;
            }
        }
        *(f32 *)(work + 0x487) -= drift;
        edScrollLayoutRecords();
    }
}

// Intent: Colour and draw each active record's glyph lists while the roll is active [inferred]
// FUN_0038E4B0
/* The glyph handle pointer is a field-address transport into EdScrollRecord.glyphs (eight-byte pairs), not an independent allocation. */
void edScrollDrawLines(void)
{
    s32 i;
    s32 j;
    u32 packed;
    EdColor color;
    u32 *work;

    if (D_007246A0 == NULL) {
        kAssertFail(D_0064F220, 0x6B);
    }
    work = D_007246A0;
    if ((~((EdScrollWork *)work)->flags & 1) != 0) {
        return;
    }
    color = *(EdColor *)((EdScrollWork *)work)->color;
    for (i = 0, packed = (u32)color.r << 24 | (u32)color.g << 16 |
                         (u32)color.b << 8 | (u32)color.a;
         i < 0x20; i++) {
        u32 *elem = (u32 *)((u8 *)work + i * 0x90);
        u32 *record = elem + 1;
        if ((~elem[1] & 1) == 0) {
            for (j = 0; j < (s32)record[0x21]; j++) {
                u32 *handlePtr = (u32 *)((u8 *)record + j * 8 + 8);
                frFontSetGlyphColor(((EdScrollRecord *)record)->glyphs[j].handle, packed);
                frFontDrawList((void *)*handlePtr, 1, 0);
            }
        }
    }
}

// Intent: Allocate the first free record and mark it in use [inferred]
// FUN_0038E610
u32 *edScrollAllocRecord(void)
{
    s32 i;
    u32 *work;
    u32 *elem;
    u32 *record;

    if (D_007246A0 == NULL) {
        kAssertFail(D_0064F220, 0x6B);
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
        kAssertFail(D_0064F220, 0x1AA);
    }
    record[0] |= 1;
    return record;
}

// Intent: Release a record's font lists and clear its in-use bit [inferred]
// FUN_0038E6D0
void edScrollFreeRecord(u32* record)
{
    s32 i;

    for (i = 0; i < (s32)record[0x21]; i++) {
        frFontListKeepOrRelease(((EdScrollRecord *)record)->glyphs[i].handle);
    }
    record[0] &= ~1u;
}

// Intent: Position and colour every active record at its current row [inferred]
// FUN_0038E740
void edScrollLayoutRecords(void)
{
    u32 *work;
    u32 *elem;
    u32 *record;
    s32 i;
    f32 pos[2];

    if (D_007246A0 == NULL) {
        kAssertFail(D_0064F220, 0x6B);
    }
    work = D_007246A0;
    for (i = 0; i < 0x20; i++) {
        elem = (u32 *)((u8 *)work + i * 0x90);
        record = elem + 1;
        if ((~elem[1] & 1) == 0) {
            pos[0] = 57.0f;
            pos[1] = ((EdScrollRecord *)record)->y;
            edScrollMoveRecord(record, pos);
            edScrollSetRecordColor(record, (const u8 *)((u8 *)work + 0x122c));
        }
    }
}

// Intent: Lay out one text line into a record's glyph lists, token by token [inferred]
// FUN_0038E810
void edScrollLayoutText(u32 *work, char *text, s32 align)
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
    length = strlen(text);
    count = 0;
    frFontSetFlagBits(1);
    frFontClearFlagBits(2);
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
                strncpy(token, start, tokenLength);
                token[tokenLength] = 0;
                switch (align) {
                case 0:
                    style = 6;
                    D_007246A4 = style;
                    if (edScrollShortHoldEnabled() != 0) {
                        mode = 0xB;
                    } else {
                        mode = 9;
                    }
                    break;
                case 1:
                    style = 6;
                    D_007246A4 = style;
                    if (edScrollShortHoldEnabled() != 0) {
                        mode = 0xC;
                    } else {
                        mode = 0xA;
                    }
                    break;
                default:
                    break;
                }
                {
                    u32 handle = (u32)frFontCreateTextList((u8 *)token, (s8)style, (s8)mode, 0, NULL);
                    frFontExSetScale(handle, 0.0f);
                    ((EdScrollRecord *)work)->glyphs[count].handle = handle;
                    ((EdScrollRecord *)work)->glyphs[count].x = width;
                    count++;
                    start += tokenLength;
                    width += (f32)frFontNodeWidth(handle);
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
    frFontClearFlagBits(1);
    frFontSetFlagBits(2);
    ((EdScrollRecord *)work)->count = count;
}

// Intent: Move a record's glyph lists to its row and reset their scale [inferred]
// FUN_0038EAE0
/* The float cursor addresses an EdScrollGlyph pair; its second word is a handle, so keep the bit-preserving word reinterpretation for the font ABI. */
void edScrollMoveRecord(u32* work, const f32* pos)
{
    s32 i;

    for (i = 0; i < (s32)((EdScrollRecord *)work)->count; i++) {
        f32* entry = (f32*)((u8*)work + i * 8 + 4);
        frFontMoveListTo(*(u32*)(entry + 1), (s32)((pos[0] + entry[0]) * 16.0f),
                      (s32)(pos[1] * 8.0f));
        frFontExSetScale(*(u32*)(entry + 1), 0.0f);
    }
}

// Intent: Set the colour of a record's glyph lists from a packed RGBA value [inferred]
// FUN_0038EBB0
void edScrollSetRecordColor(u32* work, const u8* color)
{
    s32 i;
    u32 packed;

    packed = (u32)color[0] << 24 | (u32)color[1] << 16 |
             (u32)color[2] << 8 | (u32)color[3];
    for (i = 0; i < (s32)((EdScrollRecord *)work)->count; i++) {
        frFontSetGlyphColor(((EdScrollRecord *)work)->glyphs[i].handle, packed);
    }
}

// Intent: Return the stream command byte at the current read offset [inferred]
// FUN_0038EC50
/* The parameter header returns a byte-stream base address; no object layout applies to its command bytes. */
u32 edScrollStreamCommand(void)
{
    u32 *work;
    u32 stream;
    u32 base;

    if (D_007246A0 == NULL) {
        kAssertFail(D_0064F220, 0x6B);
    }
    work = D_007246A0;
    stream = edResGetStream();
    base = brpParamReadWord4((const u32 *)(uintptr_t)stream);
    return *(u8 *)(uintptr_t)(base + ((EdScrollWork *)work)->streamOffset);
}

// Intent: Return the byte after the current stream command, used as its operand [inferred]
// FUN_0038ECC0
/* The parameter header returns a byte stream; the operand is the next raw byte rather than a struct field. */
s32 edScrollStreamOperand(void)
{
    u32 *work;
    u32 stream;
    u32 base;

    if (D_007246A0 == NULL) {
        kAssertFail(D_0064F220, 0x6B);
    }
    work = D_007246A0;
    stream = edResGetStream();
    base = brpParamReadWord4((const u32 *)(uintptr_t)stream);
    return *(u8 *)(uintptr_t)(((EdScrollWork *)work)->streamOffset + base + 1);
}

// Intent: Advance the stream read offset by the length of the current command [inferred]
// FUN_0038ED30
/* Typed staff-roll members change b210 address materialization; retain byte/word
 * accesses to ed_scroll_internal.h layouts to keep the retail instructions. */
void edScrollStreamAdvance(void)
{
    u32 *work;
    u32 stream;
    u32 base;
    s32 offset;
    u8 command;

    if (D_007246A0 == NULL) {
        kAssertFail(D_0064F220, 0x6B);
    }
    work = D_007246A0;
    stream = edResGetStream();
    base = brpParamReadWord4((const u32 *)(uintptr_t)stream);
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
