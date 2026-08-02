#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit sdkChkmem.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

// FUN_0044EAA0
INCLUDE_ASM("asm/nonmatchings/sdkChkmem", func_0044eaa0);

typedef struct ChkMemEntry {
    s32 size;   /* 0x00 */
    u16 pad_04; /* 0x04 */
    s16 pad_06; /* 0x06 */
    u8  cls;    /* 0x08 */
} ChkMemEntry;

typedef struct ChkMemPool {
    ChkMemEntry *first;    /* 0x00 */
    ChkMemEntry *last;     /* 0x04 */
    s32 total;             /* 0x08 */
    u8 pad_0C[0x0C];       /* 0x0C */
    s32 count;             /* 0x18 */
    s32 bytes;             /* 0x1C */
    u8 pad_20[0x10];       /* 0x20 */
    void (*fn_30)(void);   /* 0x30 */
    u16 classes;           /* 0x34 */
    s32 classBytes[8];     /* 0x38 */
    s32 classCount[8];     /* 0x58 */
} ChkMemPool;

extern ChkMemPool *D_00763D1C; /* sdkChkmem pool */
extern s32 D_00764AC0;         /* sdkChkmem lock */

// FUN_0044EC30
s32 func_0044ec30(void) {
    return D_00763D1C->bytes;
}

// FUN_0044EC40
u16 func_0044ec40(void) {
    return D_00763D1C->classes;
}

// FUN_0044EC50
void func_0044ec50(s32 arg0) {
    D_00764AC0 = arg0;
}

// FUN_0044EC60
INCLUDE_ASM("asm/nonmatchings/sdkChkmem", func_0044ec60);

// FUN_0044EE70
INCLUDE_ASM("asm/nonmatchings/sdkChkmem", func_0044ee70);

// FUN_0044EF70
INCLUDE_ASM("asm/nonmatchings/sdkChkmem", func_0044ef70);

// FUN_0044F140
INCLUDE_ASM("asm/nonmatchings/sdkChkmem", func_0044f140);

// FUN_0044F3A0
INCLUDE_ASM("asm/nonmatchings/sdkChkmem", func_0044f3a0);
