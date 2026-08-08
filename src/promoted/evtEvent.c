/* Consolidated Persona 4 source units. */
/* Original translation unit evtEvent.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"
extern s32 func_00286350();

void func_00452080(s32 arg0);
/* Old-style: this unit calls it both with no argument (func_002856a0) and with
   one (func_00285480), exactly as retail does. */
s32 *func_00452560();
extern void (*jtbl_008873EC[])(void *);
void func_002852a0(s32 arg0, s32 arg1);

s32 func_00452380(void *arg0);
extern s32 D_0063C2F8[];
extern void func_0046d730(u8 *file, s32 line);
extern u8 D_0063C2C8[];
extern u8 D_00748340[];
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern void func_0044ea90(const void *file, s32 line);
extern s32 func_00451de0(void *data, s32 a, s32 b, s32 c, void *init, void *close, void *buf);
extern void func_0043f9c8(void *dest, s32 value, s32 size);
extern s32 func_002862a0(s32, s32);
extern void func_002863e0(u32, s32, s32, s32);
extern void func_00286380();
extern s32 func_002863b0(s32);
extern void func_0028aaf0(s32, s32 *);
extern void func_0028c3f0(s32 *);
extern s32 func_002909a0(s32 *);
extern void func_00290bc0(s32 *);
void func_002854e0(u8 *arg0);
extern s32 func_00290de0(u8 *);
extern s32 func_00120ee0(s32);
extern s32 func_00122720(void);
extern s32 func_0028f8e0(s32);
extern void func_00287310(u8 *);
extern void func_00440b68(void *);
extern u8 D_0063C2E0[];
s32 func_002857c0(void);
void func_002853c0(void);



// FUN_00285480
s32 func_00285480(u8 *arg0)
{
    s32 handle;

    if (arg0 == 0) {
        func_0046d730(D_0063C2C8, 0x2E);
    }
    handle = *(s32 *)(arg0 + 0xC);
    if (handle == 0) {
        return 0;
    }
    return (s32)func_00452560(handle);
}

// FUN_002854E0
void func_002854e0(u8 *arg0)
{
    s32 temp_4_4;
    s32 var_4;
    s32 temp_4;
    s32 temp_4_2;
    s32 temp_4_3;

    if (arg0 != NULL) {
        if ((*(s32 *)(arg0 + 0) & 0x20) && (func_00290de0(arg0 + 0x678) == 1)) {
            *(s32 *)(arg0 + 0) &= ~0x20;
        }
        if ((*(s32 *)(arg0 + 0) & 0x200) && ((temp_4 = *(s32 *)(arg0 + 0x6C4), temp_4 != 0) || (func_00120ee0(temp_4) != 0))) {
            *(s32 *)(arg0 + 0) &= ~0x200;
        }
        if ((*(s32 *)(arg0 + 0) & 0x400) && ((temp_4_2 = *(s32 *)(arg0 + 0x6C8), temp_4_2 != 0) || (func_00120ee0(temp_4_2) != 0))) {
            *(s32 *)(arg0 + 0) &= ~0x400;
        }
        if ((*(s32 *)(arg0 + 0) & 0x800) && ((temp_4_3 = *(s32 *)(arg0 + 0x6CC), temp_4_3 != 0) || (func_00120ee0(temp_4_3) != 0))) {
            *(s32 *)(arg0 + 0) &= ~0x800;
        }
        if ((*(s32 *)(arg0 + 0) & 0x2000) && (func_00122720() != 1)) {
            *(s32 *)(arg0 + 0) &= ~0x2000;
        }
        if ((*(s32 *)(arg0 + 0) & 0x4000) && (func_00452490(*(s32 *)(arg0 + 0x75C)) == 0)) {
            *(s32 *)(arg0 + 0) &= ~0x4000;
            *(s32 *)(arg0 + 0x75C) = 0;
        }
        if ((*(s32 *)(arg0 + 0) & 0x80000) && (func_0028f8e0(*(s32 *)(arg0 + 0x760)) != 0)) {
            *(s32 *)(arg0 + 0) &= 0xFFF7FFFF;
        }
        temp_4_4 = *(s32 *)(arg0 + 0);
        if ((temp_4_4 & 1) || (temp_4_4 & 0x20) || (temp_4_4 & 0x200) || (temp_4_4 & 0x400) || (temp_4_4 & 0x800) || (temp_4_4 & 0x1000) || (temp_4_4 & 0x2000) || (temp_4_4 & 0x80000) || (temp_4_4 & 0x4000) || (temp_4_4 & 0x100000)) {
            var_4 = 1;
        } else {
            var_4 = 0;
        }
        if (*(s32 *)(arg0 + 0x5D4) != var_4) {
            *(s32 *)(arg0 + 0x5D4) = var_4;
            func_00287310(arg0);
            func_00440b68(&D_0063C2E0);
        }
    }
}

// FUN_00285760
s32 func_00285760(u8 *arg0)
{
    s32 var_5;
    s32 var_2;

    var_5 = *(s32 *)(arg0 + 0x14);
    var_2 = 0;
    if (*(s32 *)(arg0 + 0x5D4) == 0) {
        if (var_5 >= *(s32 *)(arg0 + 0x10)) {
            var_2 = 1;
        } else {
            var_5 += 1;
        }
    }
    if (*(s32 *)(arg0 + 0x1C) != 0) {
        var_5 = *(s32 *)(arg0 + 0x20);
        *(s32 *)(arg0 + 0x1C) = 0;
    }
    *(s32 *)(arg0 + 0x14) = var_5;
    return var_2;
}

// FUN_002857C0
s32 func_002857c0(void)
{
    u8 *temp_2;
    u8 *temp_2_2;
    s32 temp_4;
    s32 temp_4_2;
    s32 temp_4_3;
    s32 var_2;

    temp_2 = (u8 *)func_00452560();
    if (temp_2 == NULL) {
        func_0046d730(D_0063C2C8, 0x2E);
    }
    temp_4 = *(s32 *)(temp_2 + 0xC);
    if (temp_4 != 0) {
        func_00452560(temp_4);
    }
    temp_4_2 = *(s32 *)(temp_2 + 0);
    switch (temp_4_2) {
    case 0:
        *(s32 *)(temp_2 + 0) = 5;
        /* fallthrough */
    case 5:
        if (func_002863b0(*(s32 *)(temp_2 + 0xC)) != 0) {
            *(s32 *)(temp_2 + 0) = 3;
        }
        goto done;
    case 3:
        *(s32 *)(temp_2 + 0) = 4;
        /* fallthrough */
    case 4:
        temp_2_2 = (u8 *)func_00452560(*(s32 *)(temp_2 + 0xC));
        *(s32 *)(temp_2_2 + 0) &= ~1;
        temp_4_3 = *(s32 *)(temp_2_2 + 0x14);
        if (temp_4_3 != *(s32 *)(temp_2_2 + 0x18)) {
            func_0028aaf0(temp_4_3, (s32 *)temp_2_2);
        }
        *(s32 *)(temp_2_2 + 0x18) = *(s32 *)(temp_2_2 + 0x14);
        func_0028c3f0((s32 *)temp_2_2);
        if ((*(s32 *)(temp_2_2 + 4) != 0) && (func_002909a0((s32 *)(temp_2_2 + 0x678)) != 0)) {
            func_00290bc0((s32 *)(temp_2_2 + 0x678));
        }
        func_002854e0(temp_2_2);
        if (*(s32 *)(temp_2_2 + 0x14) >= *(s32 *)(temp_2_2 + 0x10)) {
            var_2 = 1;
        } else {
            func_00285760(temp_2_2);
            var_2 = 0;
        }
        if (var_2 != 0) {
            *(s32 *)(temp_2 + 0) = 6;
        }
        goto done;
    case 6:
        return -1;
    default:
    done:
        return 0;
    }
}
// FUN_00285980
void func_00285980(void) {
    s32 *temp_2;

    temp_2 = func_00452560();
    func_00452080(*(s32 *)((u8 *)temp_2 + 0xC));
    jtbl_008873EC[0](temp_2);
    func_002852a0(0, -0x60);
}



// FUN_002859E0
s32 func_002859e0(s32 arg0, s32 arg1)
{
    s32 temp_17;
    u8 *temp_16;
    s32 temp_2;

    func_0044ea90(&D_00748340, 0x52);
    temp_16 = D_008873F4[0](1, 0x60, 0x40000);
    func_002852a0(0, 0x60);
    func_0043f9c8(temp_16, 0, 0x60);
    temp_17 = func_00451de0(&D_0063C2F8, 0xF, 0, 0, (void *)func_002857c0, (void *)func_00285980, temp_16);
    temp_2 = func_002862a0(0, 0);
    *(s32 *)(temp_16 + 0xC) = temp_2;
    func_002863e0(temp_2, arg0, arg1, 0);
    func_00286380(*(s32 *)(temp_16 + 0xC));
    *(s32 *)(temp_16 + 0) = 0;
    return temp_17;
}
// FUN_00285AF0
void func_00285af0(void) {
    if (func_00452380(D_0063C2F8) == 0) {
        func_002853c0();
    }
}

// FUN_00285B30
s32 func_00285b30(void) {
    s32 h = func_00286350();

    if (h == 0) {
        return -1;
    }
    return *(s32 *)((u8 *)func_00452560(h) + 0x14);
}

/* Retail's outer-loop count check uses `sltu $at,$s3,$v0; bnez $at`, while
   b210 reuses $v0 for the result (`sltu $v0,$s3,$v0; bnez $v0`). Exact
   executable body otherwise; fndiff offsets 68 and 72 are that register
   choice, offsets 120 and 124 are the D_0063C2C8 relocations, and offset
   308 is the retail-only tail padding. Comparison polarity, >=/< /> forms,
   u32 loads, and loop declaration reorder were ruled out. obj 308B/window
   320B, nd 2. Committed at nd 2. */
// FUN_00285B80 NONMATCHING
#ifdef NON_MATCHING
u8 *func_00285b80(u8 *arg0, s32 arg1)
{
    s32 count;
    s32 i;
    s32 matched;
    u8 *p;
    u32 j;
    u16 flags;
    s32 type;
    s32 id;

    matched = 0;
    count = *(s32 *)(arg0 + 0x48);
    i = 0;
    goto outer_check;

process_entry:
    if ((u32)i < (u32)*(s32 *)(arg0 + 0x48)) {
        goto traverse;
    }
    p = NULL;
    goto classify;

traverse:
    p = *(u8 **)(arg0 + 0x4C);
    j = 0;
    goto inner_check;

inner_body:
    if (*(u8 **)(p + 0x90) == NULL) {
        func_0046d730(D_0063C2C8, 0x18F);
    }
    p = *(u8 **)(p + 0x90);
    j += 1;

inner_check:
    if (j < (u32)i) {
        goto inner_body;
    }
    goto classify;

classify:
    flags = *(u16 *)(p + 0xC);
    type = (s32)(flags & 0xFFC00) >> 10;
    if (type == 3) {
        id = flags & 0x3FF;
        if (id >= 0x384 && id < 0x387) {
            if (matched == arg1) {
                return p;
            }
            matched += 1;
        }
    }
    i += 1;

outer_check:
    if (i < count) {
        goto process_entry;
    }
    return NULL;
}
#else
INCLUDE_ASM("asm/nonmatchings/evtEvent", func_00285b80);
#endif
