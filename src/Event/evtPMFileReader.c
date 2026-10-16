#include "include_asm.h"
#include "sdk_task_registration.h"
/* Persona 4 USA decompilation - evtPMFileReader.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"
extern s32 kwlnTaskIsLinked();
extern u32 kwlnTaskGetWork(void *task);
extern u8 D_0063C970[];
extern u8 D_0063C990[];
extern char iGpffffa7c0;
extern void evtPolygonMovieFormatNames(s32 arg0, s32 arg1, u8 *arg2, u8 *arg3, u8 *arg4, u8 *arg5);
extern u8 *H_Cdvd_AcquireDirectory(u8 *arg0, s32 arg1);
extern s32 H_Cdvd_IsFileLoaded(u8 *arg0);
extern s32 H_Cdvd_LookupRequest(u8 *arg0, s32 *arg1);
extern s32 *evtPolygonMovieAllocTableA(s32 **arg0);
extern s32 *evtPolygonMovieAllocTableB(s32 **arg0);
extern s32 *evtPolygonMovieAllocTableC(s32 **arg0);
extern void chkmemAllocSiteTag(u8 *file, s32 line);
extern void evtMemAccount(s32 arg0, s32 arg1);
extern void memset(void *dest, s32 value, s32 size);

extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00748340[];
extern u8 D_0063CAA0[];
extern s32 evtPMFileReaderTaskUpdate(u8 *task);
extern void evtPMFileReaderTaskDestroy(u8 *task);
extern void datSetFlag(s32 a, s32 b);
extern void H_Cdvd_Destroy(s32 a);
extern void func_00440b68(char *fmt, ...);
extern void (*jtbl_008873EC[])(void *ptr);
extern u8 D_0063C9B0[];
extern u8 D_0063C9D0[];
extern u8 D_0063CA00[];
extern u8 D_0063CA20[];
extern u8 D_0063CA50[];
extern u8 D_0063CA70[];

/* measured: nd 126. The two else-branch flag checks (case 2: `if (p->flag == 1)`
   and case 4) emit `lw; addiu $v0,1; bne` in b210, but retail emits
   `lw; xori $v0,$v0,1; sltiu $v0,$v0,1; beqz` (the boolean-then-test form).
   Every spelling probed (==1 / !=1 / struct field / pointer cast / named local /
   u8/u16/u32 types / switch on flag) folds to `beq`/`bne`, never the xori/sltiu
   pair; the 4-byte residual from this floor propagates to every branch target
   in the else-branch (nd 126). Same family as cmpConfig func_0035cb00's
   documented sltu/xori booleanization floor. INCLUDE_ASM restored. */
/* measured: matched by typing the context pointer as a byte pointer (the
   u8 ** draft scaled every field offset by four), materialising the
   `*(s32 *)(ctx + 4) == 1` tests as boolean values rather than branches,
   restoring the empty `case 7` the second dispatch needs for its eight-
   entry jump table, writing the cases in ascending order, taking the
   format buffer through its small-data name, and giving evtPolygonMovieFormatNames
   the pointer parameters its own body already requires. */
// Intent: Reader task update: loads the movie's CD files (sections 0x0C..0x38) in stages and advances the reader state machine to done (state 7) [inferred]
// FUN_002938C0
s32 evtPMFileReaderTaskUpdate(u8 *task) {
    s32 sp12C;
    u8 spE0[64];
    u8 spA0[64];
    u8 sp60[64];
    u8 sp20[64];
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_2_4;
    u16 temp_4;
    u8 *temp_2;
    u8 *temp_3;
    s32 ready;

    temp_2 = (u8 *)kwlnTaskGetWork(task);
    evtPolygonMovieFormatNames(*(s32 *)(temp_2 + 0x0C), *(s32 *)(temp_2 + 0x10), spE0, spA0, sp60, sp20);
    if (*(s32 *)(temp_2 + 8) != 0) {
        temp_3 = *(u8 **)temp_2;
        switch ((s32)temp_3) {
        case 0:
            *(s32 *)(temp_2 + 0x28) = 0;
            *(s32 *)(temp_2 + 0x2C) = 0;
            *(s32 *)(temp_2 + 0x30) = 0;
            *(s32 *)(temp_2 + 0x34) = 0;
            *(s32 *)(temp_2 + 0x38) = 0;
            *(s32 *)(temp_2 + 0x3C) = 0;
            func_00440b68(&iGpffffa7c0, D_0063C970, 0x3F);
            *(s32 *)(temp_2 + 0x1C) = (s32)H_Cdvd_AcquireDirectory(sp20, 1);
            *(u8 **)temp_2 = (u8 *)1;
            break;
        case 1:
            if (H_Cdvd_IsFileLoaded(*(u8 **)(temp_2 + 0x1C)) == 1) {
                temp_2_2 = H_Cdvd_LookupRequest(spE0, &sp12C);
                *(s32 *)(temp_2 + 0x34) = temp_2_2;
                if (temp_2_2 == 0) {
                    *(s32 *)(temp_2 + 0x28) = (s32)evtPolygonMovieAllocTableA((s32 **)(temp_2 + 0x34));
                }
                evtMemAccount(4, sp12C);
                temp_2_3 = H_Cdvd_LookupRequest(spA0, &sp12C);
                *(s32 *)(temp_2 + 0x38) = temp_2_3;
                if (temp_2_3 == 0) {
                    *(s32 *)(temp_2 + 0x2C) = (s32)evtPolygonMovieAllocTableB((s32 **)(temp_2 + 0x38));
                }
                evtMemAccount(5, sp12C);
                temp_2_4 = H_Cdvd_LookupRequest(sp60, &sp12C);
                *(s32 *)(temp_2 + 0x3C) = temp_2_4;
                if (temp_2_4 == 0) {
                    *(s32 *)(temp_2 + 0x30) = (s32)evtPolygonMovieAllocTableC((s32 **)(temp_2 + 0x3C));
                }
                evtMemAccount(6, sp12C);
                *(u8 **)temp_2 = (u8 *)7;
            }
            break;
        case 7:
            break;
        }
    } else {
        temp_3 = *(u8 **)temp_2;
        switch ((s32)temp_3) {
        case 0:
            func_00440b68(&iGpffffa7c0, D_0063C970, 0x6C);
            *(s32 *)(temp_2 + 0x1C) = (s32)H_Cdvd_AcquireDirectory(spE0, 0);
            *(u8 **)temp_2 = (u8 *)1;
            break;
        case 1:
            if (H_Cdvd_IsFileLoaded(*(u8 **)(temp_2 + 0x1C)) == 1) {
                *(s32 *)(temp_2 + 0x28) = 0;
                *(s32 *)(temp_2 + 0x34) = H_Cdvd_LookupRequest(spE0, &sp12C);
                evtMemAccount(4, sp12C);
                *(u8 **)temp_2 = (u8 *)2;
            }
            break;
        case 2:
            ready = (*(s32 *)(temp_2 + 4) == 1);
            if (ready != 0) {
                *(s32 *)(temp_2 + 0x2C) = (s32)evtPolygonMovieAllocTableB((s32 **)(temp_2 + 0x38));
                if (*(s32 *)(temp_2 + 0x38) == 0) {
                    kAssertFail(D_0063C970, 0x88);
                }
                *(u8 **)temp_2 = (u8 *)4;
            } else {
                func_00440b68(&iGpffffa7c0, D_0063C970, 0x8C);
                *(s32 *)(temp_2 + 0x20) = (s32)H_Cdvd_AcquireDirectory(spA0, 0);
                *(u8 **)temp_2 = (u8 *)3;
            }
            break;
        case 3:
            if (H_Cdvd_IsFileLoaded(*(u8 **)(temp_2 + 0x20)) == 1) {
                *(u8 **)temp_2 = (u8 *)4;
                *(s32 *)(temp_2 + 0x2C) = 0;
                *(s32 *)(temp_2 + 0x38) = H_Cdvd_LookupRequest(spA0, &sp12C);
                evtMemAccount(5, sp12C);
            }
            break;
        case 4:
            ready = (*(s32 *)(temp_2 + 4) == 1);
            if (ready != 0) {
                *(s32 *)(temp_2 + 0x30) = (s32)evtPolygonMovieAllocTableC((s32 **)(temp_2 + 0x3C));
                if (*(s32 *)(temp_2 + 0x3C) == 0) {
                    kAssertFail(D_0063C970, 0xA4);
                }
                *(u8 **)temp_2 = (u8 *)6;
            } else {
                func_00440b68(&iGpffffa7c0, D_0063C970, 0xA8);
                *(s32 *)(temp_2 + 0x24) = (s32)H_Cdvd_AcquireDirectory(sp60, 0);
                *(u8 **)temp_2 = (u8 *)5;
            }
            break;
        case 5:
            if (H_Cdvd_IsFileLoaded(*(u8 **)(temp_2 + 0x24)) == 1) {
                *(u8 **)temp_2 = (u8 *)6;
                *(s32 *)(temp_2 + 0x30) = 0;
                *(s32 *)(temp_2 + 0x3C) = H_Cdvd_LookupRequest(sp60, &sp12C);
                evtMemAccount(6, sp12C);
            }
            break;
        case 6:
            *(u16 *)(temp_2 + 0x18) = 0;
            temp_4 = *(u16 *)(temp_2 + 0x18);
            if ((s32)temp_4 > 0) {
                datSetFlag(temp_4, 1);
            }
            *(u8 **)temp_2 = (u8 *)7;
            func_00440b68((char *)D_0063C990);
            break;
        case 7:
            break;
        }
    }
    return 0;
}

// Intent: Reader task destroy: destroys the CD requests and flags, frees the reader's sections and releases the work block [inferred]
// FUN_00293D30
void evtPMFileReaderTaskDestroy(u8 *task) {
    s32 *p;
    u16 h18;

    p = (s32 *)kwlnTaskGetWork(task);
    h18 = *(u16 *)(p + 0x18 / 4);
    if ((s32)h18 > 0) {
        datSetFlag(h18, 0);
    }
    if (p[0x1C / 4] != 0) {
        H_Cdvd_Destroy(p[0x1C / 4]);
        p[0x1C / 4] = 0;
        func_00440b68((char *)D_0063C9B0);
    }
    if (p[0x28 / 4] != 0) {
        jtbl_008873EC[0]((void *)p[0x28 / 4]);
        evtMemAccount(4, 0);
        p[0x28 / 4] = 0;
        func_00440b68((char *)D_0063C9D0);
    }
    if (p[0x20 / 4] != 0) {
        H_Cdvd_Destroy(p[0x20 / 4]);
        p[0x20 / 4] = 0;
        func_00440b68((char *)D_0063CA00);
    }
    if (p[0x2C / 4] != 0) {
        jtbl_008873EC[0]((void *)p[0x2C / 4]);
        evtMemAccount(5, 0);
        p[0x2C / 4] = 0;
        func_00440b68((char *)D_0063CA20);
    }
    if (p[0x24 / 4] != 0) {
        H_Cdvd_Destroy(p[0x24 / 4]);
        p[0x24 / 4] = 0;
        func_00440b68((char *)D_0063CA50);
    }
    if (p[0x30 / 4] != 0) {
        jtbl_008873EC[0]((void *)p[0x30 / 4]);
        evtMemAccount(6, 0);
        p[0x30 / 4] = 0;
        func_00440b68((char *)D_0063CA70);
    }
    jtbl_008873EC[0](p);
    evtMemAccount(1, -0x40);
}

// Intent: Creates the reader task for the four given arguments and returns its handle [inferred]
// FUN_00293ED0
s32 evtPMFileReaderCreate(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 *temp_20;

    chkmemAllocSiteTag(D_00748340, 0x52);
    temp_20 = (s32 *)D_008873F4[0](1, 0x40, 0x40000);
    evtMemAccount(1, 0x40);
    memset(temp_20, 0, 0x40);
    temp_20[0xC / 4] = arg0;
    temp_20[0x10 / 4] = arg1;
    temp_20[0x14 / 4] = arg2;
    temp_20[0x4 / 4] = arg3;
    temp_20[0x8 / 4] = 0;
    return (s32)kwlnTaskCreate((const void *)(D_0063CAA0), 0xF, 1, 1, evtPMFileReaderTaskUpdate, evtPMFileReaderTaskDestroy, (u8 *)(temp_20));
}

// Intent: Returns 1 when the reader task has finished loading (state 7) [inferred]
// FUN_00293FC0
s32 evtPMFileReaderIsDone(s32 arg0) {
    if (kwlnTaskIsLinked(arg0) == 0) {
        kAssertFail(D_0063C970, 0x123);
    }
    if (((s32 *)kwlnTaskGetWork((void *)arg0))[0] == 7) {
        return 1;
    }
    return 0;
}

// Intent: Returns the reader task's work block; asserts the task is linked [inferred]
// FUN_00294040
u8 *evtPMFileReaderGetWork(s32 arg0) {
    if (kwlnTaskIsLinked(arg0) == 0) {
        kAssertFail(D_0063C970, 0x131);
    }
    return (u8 *)kwlnTaskGetWork((void *)arg0);
}

// Intent: Returns the first kind-0 record of the reader's table through the output pointers, or 0 when none is found or the reader is not done [inferred]
// FUN_002940A0
s32 evtPMFileReaderGetFirstEntry(s32 arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4) {
    u8 sp70[0x114];
    u8 *base = sp70;
    s32 *temp_2;
    s32 i;
    s32 count;
    u8 *elem;
    u8 *p;

    memset(base, 0, 0x114);
    if (kwlnTaskIsLinked(arg0) == 0) {
        kAssertFail((char *)D_0063C970, 0x123);
    }
    if (((s32 *)kwlnTaskGetWork((void *)arg0))[0] != 7) {
        if (kwlnTaskIsLinked(arg0) == 0) {
            kAssertFail((char *)D_0063C970, 0x123);
        }
        if (((s32 *)kwlnTaskGetWork((void *)arg0))[0] != 7) {
            kAssertFail((char *)D_0063C970, 0x143);
        }
        return 0;
    }
    temp_2 = (s32 *)kwlnTaskGetWork((void *)arg0);
    *(u32 *)(base + 0x80) = (u32)temp_2[0x38 / 4];
    if (temp_2[0x38 / 4] != 0) {
        *(u32 *)(base + 0x84) = (u32)(temp_2[0x38 / 4] + 0x20);
    } else {
        *(u32 *)(base + 0x84) = 0;
    }
    i = 0;
    count = *(u32 *)(*(u32 *)(base + 0x80) + 0x10);
    for (; i < count; i++) {
        elem = *(u8 **)(base + 0x84);
        elem = (u8 *)((u32)elem + i * 16);
        switch (*(u32 *)elem) {
        case 0:
            p = (u8 *)(temp_2[0x38 / 4] + *(u32 *)(elem + 0xC));
            *(u32 *)(base + 0x90) = (u32)p;
            *arg1 = *(u32 *)(p + 0x10);
            *arg2 = *(u32 *)(*(u32 *)(base + 0x90) + 0x14);
            *arg3 = *(u8 *)(*(u32 *)(base + 0x90) + 0x1A);
            *arg4 = *(s16 *)(*(u32 *)(base + 0x90) + 0x1C);
            return 1;
        default:
            break;
        }
    }
    return 0;
}

