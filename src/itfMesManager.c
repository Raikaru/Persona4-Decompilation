/* Source unit: src/itfMesManager_002770d0.c */
#include "type.h"
#include "message_handle.h"
#include "message_procedure_api.h"
#include "sdk_task_registration.h"
#include "include_asm.h"
#include "fr_font_internal.h"

s32 scrGetMessageManager(void);
s32 scrGetParamInt(s32 index);
void itfMesWindowSetHandle(s32 mesHandleIdx, u32 param_2);
void func_00440b68();
extern char D_0063BE20[];
void itfMesWindowFormatValue(int param_1,int param_2,int param_3,u32 param_4);
u32 itfMesWindowSetParam(int param_1,int param_2,int param_3);
extern void itfMesWindowSetString(int a, int b, char *c);
extern int func_002438b0(int arg0);
extern int func_00243840(int arg0);
extern u8 *datPersonaGetRow(u16 arg0);
extern char iGpffffa760;
extern int iGpffffb444;

extern void itfMesWindowApplyStyle(s32 arg0, s16 arg1, s32 arg2);

typedef struct {
    u8 *unk0;
    u8 pad[28];
} D_00881808_t;

extern D_00881808_t D_00881808[];

void func_002746c0(int param_1, u32 param_2);

void frFontEnableList(int param_1);
extern u8 DAT_008817EC_abs[];
extern u8 DAT_008817E4_abs[];
extern u16 D_008817E8_abs[];
extern u8 *D_008817F4_abs[];
extern u8 D_008817FC_abs[];
void itfMesWindowUpdateLists(u32 param_1);
extern char D_0063BE10[];
void kAssertFail(const char *file, s32 line);
void func_002850f0();

s32 itfMesWindowTaskUpdate(u8 *task);
void itfMesWindowFreeAll(u8 *task);
extern char D_0063BF10[];
extern char D_0063BF20[];
void itfMesWindowFreeSlots();
void poolFree();
void func_0046a2d0();
void *func_0046a430();
void memset();
void func_0027a690();
void itfMesClearSlots();
void func_0027a6f0(s32 arg0);
void func_0027b830(s32 arg0);
void func_002851f0();
s8 frFontRunCommand(int param_1, int param_2, int param_3);
u8 *frFontBuildTextSimple(u32 param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8);
u32 itfMesRecordTextAt(int param_1, int param_2);
void func_0027a340(u8 *arg0, s32 arg1);
void itfMesListSetAlpha(int param_1, u32 param_2);
void itfMesWindowSetString(s32 arg0, s32 arg1, char *arg2);
void itfMesWindowSetNumber(s32 arg0, s32 arg1, s32 arg2);
s32 sprintf(char *buf, const char *fmt, ...);
s32 func_002438b0(s32 arg0);
s32 func_00243840(s32 arg0);
u32 datPersonaDisplayName(s16 arg0);
u32 datGetItemNameId(s16 arg0);
u8 *datPersonaGetRow(u16 arg0);
extern char iGpffffa760;
extern s32 iGpffffb444;
int itfMesRecordEntry(int param_1, int param_2);
s32 itfMesListWidth(int param_1);
void frFontLoadSystemSlot(u8 *arg0);
u8 *frFontBuildTextFull(u32 param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8, u32 param_9);
void memcpy(void *arg0, void *arg1, u32 arg2);
s32 strlen(const void *param_1);
void frFontSetGlyphAux(u8 *arg0, s32 arg1);
void frFontSetGlyphColor(u8 *arg0, s32 arg1);
void frFontExSetScale(u8 *arg0, f32 fparg0);
void *func_00285170(void *arg0);
extern char D_0063BE60[];
void func_0027b7c0(s32 arg0);
void itfMesWindowSetSelectionText(u8 *arg0, u8 *arg1);
void itfMesWindowBuildRow(u8 *arg0);
s32 frFontNodeWidth(u8 *arg0);
u8 *frFontAppendList(u8 *arg0, u8 *arg1, s32 arg2);
extern char D_0063BE80[];
extern char D_0063BEA0[];
typedef signed __int128 s128;
u32 frFontMaskFlags(u32 arg0);
s32 func_0027b6e0(s32 arg0, s32 arg1);
void func_0027bb60(s32 arg0);
void func_0027bbc0(s32 arg0);
int itfMesCountClearBits(int param_1, u32 param_2);
u8 *itfMesBuildGlyphRun(u32 *arg0, s32 arg1, u32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
s32 frFontListTail(int param_1);
void itfMesWindowSendLayoutLists(s32 arg0);
s32 itfMesLineCount(u8 *arg0, u8 *arg1);
void itfMesWindowSetMetrics(int param_1, int param_2);
void itfMesListEnableVisible(int param_1);
extern u8 D_00881530[];
void itfMesWindowSetLabel(u8 *arg0, u8 *arg1);
extern s32 iGpffffb4b0;
void itfMesApplySlotTable();
void frFontSetListSlot();
void frFontDrawListMode();
u8 *itfMesWindowBuildEntry(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
void itfMesWindowDrawCallback(u8 *arg0, s32 arg1);
void *func_00460990();
void func_00460ac0();
u8 *itfMesObjectSetRecord(u8 *arg0, u8 *arg1);
s32 itfMesWindowBindRecord(s32 arg0, s32 arg1, s32 arg2);
s32 itfMesWindowSetStyle(s32 arg0, s16 arg1);
void itfMesWindowRelease(s32 arg0);
void itfMesWindowSetFlagBits(s32 arg0, s32 arg1);
void itfMesWindowClearFlagBits(s32 arg0, s32 arg1);
extern s32 DAT_007245C4;
void func_0027b750(s32 arg0, s32 arg1, s32 arg2);
void func_0027b8a0(s32 arg0);
void itfMesWindowClear(s32 arg0, s32 arg1);
void itfMesWindowLayout(s32 arg0, s32 arg1);
void itfMesWindowEnd(s32 arg0);
void scrSetReturnInt(s32 arg0);
void itfMesWindowFree(s32 arg0);
void itfMesObjectFree(u8 *arg0);
s32 itfMesRecordIsValid(u8 *arg0);
u8 *itfMesObjectCreate(u8 *arg0);
extern u8 DAT_008817E0_abs[];
s32 frFontListKeepOrRelease(s32 arg0);
void itfMesSlotReset(void *arg0, s32 arg1);
void itfMesRecordReset(void *arg0, s32 arg1);
void func_0027baa0(s32 arg0);
void itfMesWindowClearObject(u8 *arg0, s32 arg1);
void frFontMoveListTo(s32 arg0, s32 arg1, s32 arg2);
void itfMesWindowResetObject(u8 *arg0);
void itfMesObjectSetString(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
void itfMesObjectSetNumber(u8 *arg0, s32 arg1, s32 arg2);
void itfMesRecordFixup(u8 *arg0);
void itfMesWindowSetProcedure(void *arg0, s16 arg1);
extern char D_0063BED0[];
s32 func_00454a60(char *arg0, s32 arg1);
void H_Cdvd_ReadSync(s32 arg0);
void msgWinStart(s32 arg0);
extern char D_0063BF00[];
extern char DAT_00723858;


// FUN_00276630
s32 itfMesCmdWindowOpen(void)
{
    s32 index;
    s32 handle;
    u8 *object;
    u8 *base;
    s8 flag;

    index = scrGetMessageManager();
    if (index < 0)
        return 1;

    object = D_00881808[index].unk0;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x165);

    handle = scrGetParamInt(0);
    base = object + 0x1C;
    flag = *(s8 *)(object + 0x24);
    if (flag == 0) {
        itfMesWindowSetStyle(index, 0);
        if (itfMesWindowBindRecord(index, handle, 0) == 0)
            return 1;
    } else if (flag < 0) {
        *(s8 *)(base + 8) = 0;
        return 1;
    }
    return 0;
}

// FUN_00276730
s32 itfMesCmdWindowClose(void)
{
    s32 index;
    s32 handle;
    s32 count;
    u8 *object;
    u8 *base;
    s8 flag;

    index = scrGetMessageManager();
    if (index < 0)
        return 1;

    object = D_00881808[index].unk0;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x18F);

    handle = scrGetParamInt(0);
    base = object + 0x1C;
    flag = *(s8 *)(object + 0x24);
    if (flag == 0) {
        itfMesWindowSetStyle(index, 1);
        itfMesWindowSetFlagBits(index, 0x200000);
        if (itfMesWindowBindRecord(index, handle, 0) == 0)
            return 1;
    } else if (flag < 0) {
        if (flag == -1) {
            itfMesWindowRelease(index);
            *(s8 *)(base + 8) = -2;
            DAT_007245C4 = 0;
        } else if (flag == -2) {
            count = DAT_007245C4 + 1;
            DAT_007245C4 = count;
            if (count > 0xA) {
                *(s8 *)(base + 8) = 0;
                return 1;
            }
        } else if ((*(u32 *)object & 0x300) == 0) {
            itfMesWindowRelease(index);
            itfMesWindowSetStyle(index, 0);
            itfMesWindowClearFlagBits(index, 0x400000);
            *(s8 *)(base + 8) = 0;
            return 1;
        }
    }
    return 0;
}

// FUN_002768E0
s32 itfMesCmdWindowOpenStyled(void)
{
    s32 index;
    s32 handle;
    s32 count;
    s32 result;
    u8 *object;
    u8 *base;
    s8 flag;

    index = scrGetMessageManager();
    if (index < 0)
        return 1;

    object = D_00881808[index].unk0;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x1CE);

    handle = scrGetParamInt(0);
    base = object + 0x1C;
    flag = *(s8 *)(object + 0x24);
    if (flag == 0) {
        itfMesWindowSetStyle(index, 1);
        itfMesWindowSetFlagBits(index, 0x200000);
        result = itfMesWindowBindRecord(index, handle, 0);
        func_0027b750(index, 0, scrGetParamInt(1));
        func_0027b8a0(index);
        if (result == 0)
            return 1;
    } else if (flag < 0) {
        if (flag == -1) {
            itfMesWindowRelease(index);
            *(s8 *)(base + 8) = -2;
            DAT_007245C4 = 0;
        } else if (flag == -2) {
            count = DAT_007245C4 + 1;
            DAT_007245C4 = count;
            if (count > 0xA) {
                *(s8 *)(base + 8) = 0;
                return 1;
            }
        } else if ((*(u32 *)object & 0x300) == 0) {
            itfMesWindowRelease(index);
            itfMesWindowSetStyle(index, 0);
            itfMesWindowClearFlagBits(index, 0x400000);
            *(s8 *)(base + 8) = 0;
            return 1;
        }
    }
    return 0;
}

// FUN_00276AC0
s32 itfMesCmdWindowOpenAt(void)
{
    s32 index;
    s32 h0;
    s32 h1;
    s32 h2;
    u8 *object;
    u8 *base;
    s16 f;

    index = scrGetMessageManager();
    if (index < 0)
        return 1;

    object = D_00881808[index].unk0;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x210);

    h0 = scrGetParamInt(0);
    h1 = scrGetParamInt(1);
    h2 = scrGetParamInt(2);
    base = object + 0x3C;
    f = *(s16 *)(object + 0x48);
    if (f == 0) {
        itfMesWindowSetStyle(index, 3);
        itfMesWindowSetFlagBits(index, 0x200000);
        if (itfMesWindowBindRecord(index, h0, 0) == 0)
            return 1;
        itfMesWindowSetHandle(index, h2);
        itfMesWindowLayout(index, h1);
    } else if (f < 0) {
        *(s16 *)(base + 0xC) = 0;
        itfMesWindowClear(index, 0);
        *(s8 *)(object + 0x24) = 0;
        scrSetReturnInt(*(s16 *)(base + 0x10));
        itfMesWindowEnd(index);
        itfMesWindowRelease(index);
        return 1;
    }
    return 0;
}

// FUN_00276C60
s32 itfMesCmdWindowOpenHold(void)
{
    s32 index;
    s32 handle;
    s32 count;
    u8 *object;
    u8 *base;
    s8 flag;

    index = scrGetMessageManager();
    if (index < 0)
        return 1;

    object = D_00881808[index].unk0;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x249);

    handle = scrGetParamInt(0);
    base = object + 0x1C;
    flag = *(s8 *)(object + 0x24);
    if (flag == 0) {
        itfMesWindowSetStyle(index, 4);
        itfMesWindowSetFlagBits(index, 0x200000);
        if (itfMesWindowBindRecord(index, handle, 0) == 0)
            return 1;
    } else if (flag < 0) {
        if (flag == -1) {
            itfMesWindowRelease(index);
            *(s8 *)(base + 8) = -2;
            DAT_007245C4 = 0;
        } else if (flag == -2) {
            count = DAT_007245C4 + 1;
            DAT_007245C4 = count;
            if (count > 0x14) {
                *(s8 *)(base + 8) = 0;
                return 1;
            }
        } else if ((*(u32 *)object & 0x300) == 0) {
            itfMesWindowRelease(index);
            itfMesWindowSetStyle(index, 0);
            itfMesWindowClearFlagBits(index, 0x400000);
            *(s8 *)(base + 8) = 0;
            return 1;
        }
    }
    return 0;
}

// FUN_00276E10
s8 itfMesWindowState(s32 arg0)
{
    u8 *object;

    object = D_00881808[arg0].unk0;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x284);
    return *(s8 *)(object + 0x24);
}

// FUN_00276E70
void itfMesWindowSetState(s32 arg0, s8 arg1)
{
    u8 *object;

    object = D_00881808[arg0].unk0;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x29F);
    *(s8 *)(object + 0x24) = arg1;
}

// FUN_00276ED0
s32 itfMesCmdWindowResult(void)
{
    s32 index;
    s32 h;
    u8 *object;
    u8 *base;
    s16 f;

    index = scrGetMessageManager();
    if (index < 0)
        return 1;

    object = D_00881808[index].unk0;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x2C2);

    h = scrGetParamInt(0);
    base = object + 0x3C;
    f = *(s16 *)(object + 0x48);
    if (f == 0) {
        itfMesWindowLayout(index, h);
    } else if (f < 0) {
        *(s16 *)(base + 0xC) = 0;
        scrSetReturnInt(*(s16 *)(base + 0x10));
        itfMesWindowEnd(index);
        return 1;
    }
    return 0;
}

// FUN_00276FB0
s16 itfMesWindowGetAnim(s32 arg0)
{
    u8 *object;

    object = D_00881808[arg0].unk0;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x2F0);
    return *(s16 *)(object + 0x48);
}

// FUN_00277010
void itfMesWindowSetAnim(s32 arg0, s16 arg1)
{
    u8 *object;

    object = D_00881808[arg0].unk0;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x306);
    *(s16 *)(object + 0x48) = arg1;
}

// FUN_00277070
s32 itfMesWindowGetAnimAux(s32 arg0)
{
    u8 *object;

    object = D_00881808[arg0].unk0;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x31F);
    return *(s16 *)(object + 0x4A);
}
// FUN_002770D0
u32 itfMesCmdWindowSetHandle(void)
{
  int value;
  u32 other;

  value = scrGetMessageManager();
  if (value < 0)
    return 1;

  other = scrGetParamInt(0);
  itfMesWindowSetHandle(value, other);
  return 1;
}



// FUN_00277130
s32 itfMesCmdWindowReset(void)
{
    s32 index;

    index = scrGetMessageManager();
    if (index < 0)
        return 1;
    itfMesWindowApplyStyle(index, 0, 0);
    itfMesWindowSetFlagBits(index, 0x200000);
    return 1;
}

// FUN_002771A0
s32 itfMesCmdWindowIsIdle(void)
{
    s32 index;
    u8 *object;
    s32 flags;

    index = scrGetMessageManager();
    if (index < 0)
        return 1;

    object = D_00881808[index].unk0;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x398);

    flags = *(s32 *)object & 0x300;
    if (flags == 0x100 || flags == 0x200)
        itfMesWindowRelease(index);
    return flags == 0;
}

// FUN_00277250
void itfMesWindowRelease(s32 arg0)
{
    s32 v;
    s32 w;
    u8 *node;
    u8 *obj;

    obj = D_00881808[arg0].unk0;
    if (obj == NULL)
        kAssertFail(D_0063BE10, 0x3B8);

    node = *(u8 **)DAT_008817EC_abs;
    while (node != NULL) {
        if (*(u32 *)(node + 0xC) == (u32)obj) {
            v = *(s32 *)(node + 8);
            goto out;
        } else {
            node = *(u8 **)(node + 4);
        }
    }
    v = -1;
out:
    func_0027baa0(v);

    w = *(u32 *)obj;
    if (w & 0x300) {
        w = w & ~0x300;
        *(u32 *)obj = w;
        *(u32 *)obj = w | 0x300;
    }
    w = *(u32 *)obj;
    if (w & 0x3000) {
        w = w & ~0x3000;
        *(u32 *)obj = w;
        *(u32 *)obj = w | 0x3000;
    }
    itfMesWindowClear(arg0, 1);
    itfMesWindowEnd(arg0);
    *(u32 *)obj &= 0xFFDFFFFF;
}
// FUN_00277370
u32 itfMesCmdWindowSetValue(void)
{
  int lVar1;
  u32 uVar2;
  u32 uVar3;
  u32 uVar4;

  lVar1 = scrGetMessageManager();
  if (lVar1 < 0) {
    return 1;
  }
  uVar2 = scrGetParamInt(0);
  uVar3 = scrGetParamInt(1);
  uVar4 = scrGetParamInt(2);
  func_00440b68(D_0063BE20,uVar2,uVar3,uVar4);
  uVar2 = scrGetParamInt(0);
  uVar3 = scrGetParamInt(1);
  uVar4 = scrGetParamInt(2);
  itfMesWindowFormatValue(lVar1,uVar2,uVar3,uVar4);
  return 1;
}



// FUN_00277450
u32 itfMesCmdWindowSetParam(void)
{
  s32 lVar1;
  u32 uVar2;
  u32 uVar3;

  lVar1 = scrGetMessageManager();
  if (lVar1 < 0) {
    return 1;
  }
  uVar2 = scrGetParamInt(0);
  uVar3 = scrGetParamInt(1);
  itfMesWindowSetParam(lVar1,uVar2,uVar3);
  return 1;
}



/* Install the first free slot, retaining retail's diagnostic and copy ordering.
   measured: integer-address testing and pointer-address reloading prevent
   whole-slot CSE; propagation off keeps the scaled index across the copy call.
   Neither lever alone matches. Exact 452B instructions plus 12B zero tail. */
#pragma push
#pragma opt_propagation off
// FUN_002774D0
s32 itfMesWindowInstall(u8 *arg0)
{
    s32 sp50[0x4C];
    s32 result;
    s32 i;
    s32 found;
    s32 *old_list;
    u8 *manager;
    u8 *obj;

    if (itfMesRecordIsValid(arg0) != 1)
        kAssertFail(D_0063BE10, 0x525);
    manager = (u8 *)func_00285170(DAT_008817EC_abs);
    if (manager == NULL)
        kAssertFail(D_0063BE10, 0x529);
    result = *(s32 *)(manager + 8);
    obj = itfMesObjectCreate(arg0);
    if (manager == NULL || obj == NULL)
        kAssertFail(D_0063BE10, 0x4F4);
    i = 0;
    goto slot_test;
slot_loop:
    if (*(s32 *)(manager + i * 4 + 0x10) == 0) {
        *(u8 **)(manager + i * 4 + 0x10) = obj;
        goto slot_done;
    }
    i++;
slot_test:
    if (i < 4)
        goto slot_loop;
    i = -1;
slot_done:
    if (i != 0)
        kAssertFail(D_0063BE10, 0x530);
    found = 0;
    if (i >= 0 || i < 4) {
        i *= 4;
        if (*(s32 *)(i + (u32)manager + 0x10) != 0) {
            old_list = *(s32 **)(manager + 0xC);
            if (old_list != NULL) {
                memcpy(sp50, old_list, 0x130);
                found = 1;
            }
            *(s32 **)(manager + 0xC) = *(s32 **)(manager + i + 0x10);
            if (found)
                **(s32 **)(manager + 0xC) = sp50[0];
        }
    }
    *(s32 *)DAT_008817E0_abs += 1;
    func_00440b68(D_0063BE60, *(s32 *)(obj + 0x10));
    return result;
}
#pragma pop
// FUN_002776A0
u8 *itfMesObjectCreate(u8 *arg0)
{
    u8 *obj;

    if (itfMesRecordIsValid(arg0) != 1)
        kAssertFail(D_0063BE10, 0x55A);
    func_0046a2d0(D_0063BE10, 0x567);
    obj = func_0046a430(0x130);
    memset(obj, 0, 0x130);
    *(s32 *)(obj + 4) = 0;
    itfMesObjectSetRecord(obj, arg0);
    *(s32 *)obj = 0;
    *(s32 *)(obj + 0xC) = 0;
    *(s32 *)(obj + 0x10) = 0;
    itfMesWindowSetProcedure(obj + 0x114, 0);
    itfMesSlotReset(obj + 0x14, 1);
    itfMesRecordReset(obj + 0x1C, 1);
    func_0027a690(obj + 0x3C);
    itfMesClearSlots(obj + 0x94);
    return obj;
}

// FUN_002777A0
s32 itfMesRecordCount(u8 *arg0)
{
    if (itfMesRecordIsValid(arg0) != 1)
        kAssertFail(D_0063BE10, 0x589);
    return *(s32 *)(arg0 + 0x18);
}

// FUN_002777F0
void itfMesWindowReleaseIfActive(s32 arg0)
{
    if (arg0 >= 0) {
        if (*(s32 *)(DAT_008817E0_abs + (arg0 << 5) + 0x28) != 0)
            itfMesWindowFree(arg0);
    }
}

// FUN_00277840
s32 itfMesWindowGetSubTable(s32 arg0)
{
    u8 *object;

    if (arg0 < 0 || arg0 >= 0x40)
        kAssertFail(D_0063BE10, 0x134);
    object = D_00881808[arg0].unk0;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x5C7);
    return (s32)object + 0x114;
}

// FUN_002778C0
s32 itfMesWindowBindRecord(s32 arg0, s32 arg1, s32 arg2)
{
    s32 bits;
    s32 m3;
    s32 v;
    u8 *base;
    u8 *obj;
    u8 *r;
    u8 *r2;

    if (arg0 < 0 || arg0 >= 0x40)
        kAssertFail(D_0063BE10, 0x134);
    obj = D_00881808[arg0].unk0;
    if (obj == NULL)
        kAssertFail(D_0063BE10, 0x5DE);
    r = (u8 *)itfMesRecordEntry((s32)obj, arg1);
    if (*(s32 *)r == 1) {
        itfMesWindowLayout(arg0, arg1);
        return 1;
    }
    r2 = *(u8 **)(r + 4);
    base = obj + 0x1C;
    *(u8 **)base = r2;
    *(s16 *)(base + 0x10) = (s16)arg2;
    *(s16 *)(base + 0x12) = *(s16 *)(r2 + 0x18);
    if (*(s16 *)(r2 + 0x18) == 0)
        return 0;
    itfMesWindowSetSelectionText(obj, r2);
    itfMesApplySlotTable(obj + 0x94);
    v = *(s32 *)(obj + 8);
    if (v != 0)
        frFontLoadSystemSlot((u8 *)v);
    func_0027b7c0(arg0);
    itfMesWindowBuildRow(obj);
    bits = *(s32 *)obj;
    m3 = bits & 0x300;
    if ((bits & 0x200000) && (m3 == 0 || m3 == 0x300)) {
        func_00440b68(D_0063BE80);
        v = *(s32 *)obj & ~0x300;
        *(s32 *)obj = v;
        v |= 0x100;
        *(s32 *)obj = v;
        v &= ~7;
        *(s32 *)obj = v;
        *(s32 *)obj = v | 2;
    } else {
        v = (s32)(*(u32 *)obj & ~7u);
        *(s32 *)obj = v;
        *(s32 *)obj = v | 3;
    }
    *(s8 *)(base + 8) = 1;
    *(s32 *)obj |= 0x1000000;
    func_00440b68(D_0063BEA0, *(s32 *)(obj + 0x10));
    return 1;
}

// FUN_00277AD0
void itfMesWindowClear(s32 arg0, s32 arg1)
{
    if (arg0 >= 0)
        itfMesWindowClearObject(D_00881808[arg0].unk0, arg1);
}

// FUN_00277B10
void itfMesWindowClearObject(u8 *arg0, s32 arg1)
{
    u8 *base;
    u8 *base2;
    s32 v;

    base = arg0 + 0x1C;
    if (*(s32 *)(arg0 + 0x20) != 0) {
        frFontListKeepOrRelease(*(s32 *)(arg0 + 0x20));
        *(s32 *)(base + 4) = 0;
    }
    itfMesRecordReset(base, 0);
    v = *(s32 *)arg0 & ~7;
    *(s32 *)arg0 = v;
    v = v & ~0x300;
    *(s32 *)arg0 = v;
    *(s32 *)arg0 = v & 0xFFFDFFFF;
    if (arg1 != 0) {
        base2 = arg0 + 0x14;
        if (*(s32 *)base2 != 0) {
            frFontListKeepOrRelease(*(s32 *)base2);
            *(s32 *)base2 = 0;
        }
        itfMesSlotReset(arg0 + 0x14, 0);
    }
}

/* Instruction-exact candidate: docs/probe_archive/BoA_00277be0_best_body.c,
   664B/672B; fndiff differs only in two absent zero-tail words.
   An s32 count still spills with SQ/LQ; declaring the second getter result
   before the third reproduces the retail register/stack assignment.
   Retain ASM pending semantic closure: the candidate's 1U << index requires
   index < 32, but the signed table count has no proven bound. Retail SLLV
   wraps the shift count; explicitly masking adds an instruction. */
/* Recovered: this body was measured at zero differing words in
   docs/probe_archive/MessagePrepareRecovery_00277be0_body.c and never
   installed. */
// FUN_00277BE0
void itfMesWindowLayout(s32 arg0, s32 arg1)
{
    u8 *object;
    s32 flags;
    s32 index;
    s32 *text;
    s32 x;
    s32 y;
    s32 saved_font;
    u32 remaining_mask;
    u8 *base;
    s32 font;
    s32 active_flags;
    s32 mode_flags;
    s32 count;
    u32 mask;
    s32 old_font;
    u32 new_mask;
    u8 *record;
    s32 spacing;
    u8 *data;
    s32 visible_count;

    object = D_00881808[arg0].unk0;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x686);
    record = (u8 *)itfMesRecordEntry((s32)object, arg1);
    if (*(s32 *)record != 1)
        kAssertFail(D_0063BE10, 0x68A);
    base = object + 0x3C;
    old_font = *(s32 *)(object + 0x40);
    if (old_font != 0) {
        frFontListKeepOrRelease(old_font);
        *(s32 *)(base + 4) = 0;
    }
    data = *(u8 **)(record + 4);
    remaining_mask = *(u32 *)(base + 8);
    count = (s32)*(s16 *)(data + 0x1A);
    text = (s32 *)(data + 0x20);
    new_mask = 0;
    index = 0;
    while (index < count) {
        if (remaining_mask & 1U) {
            remaining_mask >>= 1;
        } else {
            frFontRunCommand(*text, 2, 0);
            if (frFontMaskFlags(8) != 0)
                new_mask |= 1U << index;
        }
        index += 1;
        text++;
    }
    mask = *(u32 *)(base + 8) | new_mask;
    *(u32 *)(base + 8) = mask;
    visible_count = itfMesCountClearBits(*(s16 *)(data + 0x1A), mask);
    func_0027b750(arg0, 0, visible_count);
    func_0027bb60(arg0);
    x = func_0027b6e0(arg0, 0);
    y = func_0027b6e0(arg0, 1);
    spacing = func_0027b6e0(arg0, 2);
    itfMesApplySlotTable(object + 0x94);
    font = *(s32 *)(object + 8);
    if (font != 0)
        frFontLoadSystemSlot((u8 *)font);
    saved_font = iGpffffb4b0;
    if (saved_font == 0)
        iGpffffb4b0 = 0x7B;
    *(s32 *)(base + 4) = (s32)itfMesBuildGlyphRun(
        (u32 *)(data + 0x20),
        *(s16 *)(data + 0x1A),
        *(u32 *)(base + 8),
        x, y, *(s32 *)(object + 0xC), spacing, 0);
    iGpffffb4b0 = saved_font;
    func_0027bbc0(arg0);
    *(s16 *)(base + 0x12) = (s16)visible_count;
    flags = *(s32 *)object & ~0x38;
    *(s32 *)object = flags;
    active_flags = flags | 0x10;
    *(s32 *)object = active_flags;
    mode_flags = active_flags & ~0xC00;
    *(s32 *)object = mode_flags;
    *(s32 *)object = mode_flags | 0x400;
    *(s16 *)(base + 0xC) = 1;
    *(s32 *)base = arg1;
}
// FUN_00277E80
void itfMesWindowEnd(s32 arg0)
{
    itfMesWindowResetObject(D_00881808[arg0].unk0);
}

// FUN_00277EC0
void itfMesWindowResetObject(u8 *arg0)
{
    u8 *base;
    s32 v;

    if (arg0 == NULL)
        kAssertFail(D_0063BE10, 0x6F0);
    base = arg0 + 0x3C;
    if (*(s32 *)(arg0 + 0x40) != 0) {
        frFontListKeepOrRelease(*(s32 *)(arg0 + 0x40));
        *(s32 *)(base + 4) = 0;
    }
    *(s16 *)(base + 0xC) = 0;
    *(s16 *)(base + 0x12) = 0;
    *(s16 *)(base + 0xE) = -1;
    *(s32 *)(base + 8) = 0;
    v = *(s32 *)arg0 & ~0x38;
    *(s32 *)arg0 = v;
    v = v & ~0xC00;
    *(s32 *)arg0 = v;
    *(s32 *)arg0 = v & 0xFFFBFFFF;
}

// FUN_00277F70
void itfMesWindowSetHandle(s32 arg0, u32 arg1)
{
    u8 *object;

    object = D_00881808[arg0].unk0;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x714);
    *(u32 *)(object + 0x44) = arg1;
}

// FUN_00277FD0
void itfMesWindowSetCursor(s32 arg0, s32 arg1)
{
    u8 *object;
    u8 *base;
    u32 bits;
    s32 i;
    s32 zeros;
    s32 bit;
    s32 v;

    object = D_00881808[arg0].unk0;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x729);
    base = object + 0x3C;
    zeros = 0;
    bits = *(u32 *)(object + 0x44);
    i = 0;
    while (1) {
        bit = bits & 1;
        if (bit == 0)
            zeros += 1;
        if (i >= arg1)
            break;
        i += 1;
        bits >>= 1;
    }
    if (bit != 0)
        v = 0;
    else
        v = zeros - 1;
    *(s16 *)(base + 0xE) = (s16)v;
    *(s16 *)(base + 0x10) = (s16)v;
}

// FUN_00278090
void itfMesWindowMove(s32 arg0, s32 arg1, s32 arg2)
{
    u8 *object;

    object = D_00881808[arg0].unk0;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x769);
    frFontMoveListTo(*(s32 *)(object + 0x20), arg1, arg2);
}

// FUN_00278110
s32 itfMesWindowGetFlags(s32 arg0)
{
    u8 *object;

    object = D_00881808[arg0].unk0;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x7A7);
    return *(s32 *)object;
}

// FUN_00278170
void itfMesWindowSetFlagBits(s32 arg0, s32 arg1)
{
    u8 *object;

    object = D_00881808[arg0].unk0;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x7E8);
    *(u32 *)object |= (u32)arg1 & 0xFFFF0000;
}

// FUN_002781E0
void itfMesWindowClearFlagBits(s32 arg0, s32 arg1)
{
    u8 *object;

    object = D_00881808[arg0].unk0;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x7FD);
    *(u32 *)object &= ~((u32)arg1 & 0xFFFF0000);
}

// FUN_00278260
s16 func_00278260(s32 arg0)
{
    u8 *object;

    object = D_00881808[arg0].unk0;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x810);
    return *(s16 *)(object + 0x4A);
}

/* measured: re-measured 2026-08-03: nd 6 confirmed (verify normalized_diff
   10, bytes 80-91 = the case-0 arg order only; everything else byte-identical
   including the switch jtbl dispatch). New finding: the buf local must be
   u32 buf[4] (16B) to land at $sp+0x30 like retail - char buf[4] lands at
   0x3C (nd 7). The 3-word residual is unchanged from the floor: retail
   move $a0,$s1; move $a1,$s0; addiu $a2,$sp,0x30 (address-of last), mwcc b210
   always hoists the pure address-of addiu above the moves. Tried: (s32)buf,
   &buf[0], char buf[4], u32 buf[4] - identical. Address-of-in-argument-list
   scheduler floor (documented non-applicable case), not source-drivable. */
/* Case values decoded from jtbl_00748120 with tools/jtbl.py: eight dense
   entries, each with its own body, in the order written below (b210 lays case
   bodies out in declaration order). Case 1 calls func_002784e0 with $a0/$a1/$a2
   still holding the entry arguments, so it takes all three.
   measured: nd 10, obj 388 in a 400-byte window. The only residual is case 0's
   argument order -- retail materialises $a0 and $a1 before the sp+0x30 buffer
   address in $a2, b210 emits the addiu first (3 words). Naming the buffer in
   an int local and taking &sp30[0] both measure nd 10; schedule on is far
   worse (nd 203). Call-argument setup order floor. Committed at nd 10. */
/* object_size=388; window=400; normalized_diff=10; differing_word_offsets=80,84,88; first_diff_bytes=80,81,82,83,85,86,88,89,90,91. Corrected matched-callee declarations: datPersonaDisplayName(s16) and datGetItemNameId(s16), both with u32 return, replacing file-scope s64 declarations. Retail prologue checks for open callees confirmed func_00442088's existing variadic call shape and s32 signatures for func_00243840, func_002438b0 and func_00109220. Residual remains case-0 func_00278450 argument materialization: retail emits move a0,s1; move a1,s0; addiu a2,sp,0x30, while MWCC b210 emits addiu first. Probes retained from prior lane: char sp30[16]; u32/s32 sp30[4]; &sp30[0], integer/pointer casts; named a0/a1/a2 and dst/src/count locals with assignments in retail and reverse order; case-scoped/register locals; pointer local; comma-sequenced arguments; nested old-style callee declaration; fixed and variadic func_00442088 prototypes; optimization_level 1 (object 404, nd67); schedule-on (nd203); fresh permute (best nd10). No volatile or inline asm used. */
/* measured: the case-0 argument order (move a0 / move a1 / addiu a2,sp) is
   produced by passing the buffer to a pointer-typed parameter; casting it
   to an integer materialises the address first. Same lever as the "call-
   argument setup order" floor entry, which this closes. */
// FUN_002782C0
void itfMesWindowFormatValue(int param_1, int param_2, int param_3, u32 param_4) {
    char sp30[16];

    switch (param_4) {
    case 0:
        sprintf(sp30, &iGpffffa760, param_3);
        itfMesWindowSetString(param_1, param_2, sp30);
        break;
    case 1:
        itfMesWindowSetNumber(param_1, param_2, param_3);
        break;
    case 2:
        itfMesWindowSetString(param_1, param_2, (char *)(iGpffffb444 + param_3 * 21));
        break;
    case 3:
        itfMesWindowSetString(param_1, param_2, (char *)func_002438b0(param_3 & 0xFF));
        break;
    case 4:
        itfMesWindowSetString(param_1, param_2, (char *)datPersonaDisplayName((s16)param_3));
        break;
    case 5:
        itfMesWindowSetString(param_1, param_2, (char *)datGetItemNameId((s16)param_3));
        break;
    case 6:
        itfMesWindowSetString(param_1, param_2, (char *)func_00243840(param_3 & 0xFFFF));
        break;
    case 7:
        itfMesWindowSetString(param_1, param_2, (char *)datPersonaGetRow(param_3 & 0xFFFF));
        break;
    }
}

// FUN_00278450
void itfMesWindowSetString(s32 arg0, s32 arg1, char *arg2)
{
    if (arg0 < 0 || arg0 >= 0x40)
        kAssertFail(D_0063BE10, 0x134);
    itfMesObjectSetString(D_00881808[arg0].unk0, arg1, (s32)arg2, 0);
}

// FUN_002784E0
void itfMesWindowSetNumber(s32 arg0, s32 arg1, s32 arg2)
{
    if (arg0 < 0 || arg0 >= 0x40)
        kAssertFail(D_0063BE10, 0x134);
    itfMesObjectSetNumber(D_00881808[arg0].unk0, arg1, arg2);
}

// FUN_00278570
u8 *itfMesObjectSetRecord(u8 *arg0, u8 *arg1)
{
    u8 *old;
    u8 *temp;
    s32 v;

    if (arg0 == NULL)
        kAssertFail(D_0063BE10, 0x8F4);
    old = *(u8 **)(arg0 + 4);
    *(u8 **)(arg0 + 4) = arg1;
    itfMesRecordFixup(arg1);
    temp = (u8 *)itfMesRecordTail((int)arg1);
    if (*(u32 *)(arg1 + 8) == 0x3147534D)
        v = *(s32 *)(temp + 8);
    else
        v = 0;
    *(s32 *)(arg0 + 8) = v;
    return old;
}

// FUN_00278610
s32 itfMesWindowSetStyle(s32 arg0, s16 arg1)
{
    itfMesWindowApplyStyle(arg0, arg1, 0);
    return 0;
}

// FUN_00278640
void itfMesWindowApplyStyle(s32 arg0, s16 arg1, s32 arg2)
{
    u8 *object;

    object = D_00881808[arg0].unk0;
    if (!(*(u32 *)object & 0x3300)) {
        *(s32 *)(object + 0x10) = arg1;
        func_00440b68(D_0063BED0);
        itfMesWindowSetProcedure(object + 0x114, arg1);
    }
}

// FUN_002786C0
u32 itfMesWindowSetParam(int arg0, int arg1, int arg2)
{
    s32 count;
    u8 *slot;
    u8 *base;
    s32 i;

    base = D_00881808[arg0].unk0 + 0x3C;
    slot = NULL;
    if (arg1 < 0 || arg1 >= 0x10)
        return 0;
    if (arg1 == 6)
        arg1 = 5;
    if (arg1 == 0x40 || arg1 == 0x1000 || arg1 == 0x4000)
        return 0;
    i = 0;
    count = *(s16 *)(base + 0x16);
    while (i < count) {
        u8 *entry = base + i * 4;
        if (*(s16 *)(entry + 0x18) == arg1) {
            slot = entry + 0x18;
            break;
        }
        i += 1;
    }
    if (slot == NULL) {
        if (count >= 0xF)
            return 0;
        slot = base + count * 4 + 0x18;
        *(s16 *)(base + 0x16) += 1;
    }
    *(s16 *)slot = (s16)arg1;
    *(s16 *)(slot + 2) = (s16)arg2;
    return 1;
}

/* MATCH (wave14): the old "$v0/$v1-coalescing + saved-reg-reuse floor" was
   a lever-1 miss - the function was INCLUDE_ASM with no prototype, but retail
   RETURNS a value (e.g. frFontBuildTextFull/0027a520 result). Writing the body as
   s32 func_002787d0(s32,s32,s32,s32) with the 9-arg frFontBuildTextFull call and
   returning func_0027a520's result matched byte-exact (nd 0). mwcc requires
   explicit casts (u8*<->int) at the func_00278de0/00279740 call sites. */
// FUN_002787D0
s32 itfMesWindowMeasureText(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *obj;
    u8 *t;
    s32 r;
    s32 res;
    s32 final;
    s32 local;

    obj = D_00881808[arg0].unk0;
    if (obj == NULL) {
        kAssertFail(D_0063BE10, 0x9AE);
    }
    t = (u8 *)itfMesRecordEntry((int)obj, arg1);
    if (*(s32 *)t != 0) {
        kAssertFail(D_0063BE10, 0x9B3);
    }
    t = *(u8 **)(t + 4);
    if (*(s16 *)(t + 0x18) == 0) {
        return 0;
    }
    itfMesApplySlotTable(obj + 0x94);
    r = *(s32 *)(obj + 8);
    if (r != 0) {
        frFontLoadSystemSlot((u8 *)r);
    }
    r = itfMesRecordTextAt((int)t, arg2);
    if (r == 0) {
        return 0;
    }
    local = iGpffffb4b0;
    if (local == 0) {
        iGpffffb4b0 = 0x7B;
    }
    res = (s32)frFontBuildTextFull(0, 0, 0, arg3 & 0xFF, 0, 0, 0xFF, r, 0);
    iGpffffb4b0 = local;
    final = itfMesListWidth(res);
    frFontListKeepOrRelease(res);
    return final;
}
// FUN_00278940
void itfMesLoadData(void)
{
    func_00440b68(&DAT_00723858, D_0063BE10, 0xA00);
    H_Cdvd_ReadSync(func_00454a60(D_0063BF00, 1));
    msgWinStart(0);
}

// FUN_002789A0
void itfMesInitManager(void)
{
    u8 *entry;

    *(u32 *)DAT_008817E0_abs = 0;
    *(u32 *)DAT_008817E4_abs = 0;
    *(u16 *)D_008817E8_abs = 0;
    func_002850f0(DAT_008817EC_abs, D_008817FC_abs, 0x40, 0x20);
    entry = D_008817F4_abs[0];
    while (entry != NULL) {
        *(s32 *)(entry + 0xC) = 0;
        entry = *(u8 **)(entry + 4);
    }
    kwlnTaskCreate((const void *)(D_0063BF10), 0xF, 0, 0, itfMesWindowTaskUpdate, itfMesWindowFreeAll, (u8 *)(0));
    func_00440b68(D_0063BF20, D_0063BE10);
}

// FUN_00278A70
void itfMesWindowFree(s32 arg0)
{
    u8 *base;
    u8 *row;
    s32 i;
    s32 v;

    row = (u8 *)&DAT_008817E0_abs[arg0 * 0x20];
    base = row + 0x1C;
    if (*(s32 *)(row + 0x28) != 0)
        func_0027a6f0(*(s32 *)(row + 0x28));
    func_0027b830(arg0);
    *(s32 *)(base + 0xC) = 0;
    for (i = 0; i < 4; i++) {
        if (base == NULL || i < 0 || i >= 4)
            kAssertFail(D_0063BE10, 0x501);
        v = *(s32 *)(base + i * 4 + 0x10);
        if (v != 0) {
            *(s32 *)(base + i * 4 + 0x10) = 0;
        } else {
            v = 0;
        }
        if (v != 0) {
            itfMesObjectFree((u8 *)v);
        }
    }
    func_002851f0(base, DAT_008817EC_abs);
    *(u32 *)DAT_008817E0_abs -= 1;
}

// FUN_00278B80
void itfMesObjectFree(u8 *arg0)
{
    u8 *base;
    s32 v;

    if (arg0 != NULL) {
        itfMesWindowClearObject(arg0, 1);
        if (arg0 == NULL)
            kAssertFail(D_0063BE10, 0x6F0);
        base = arg0 + 0x3C;
        if (*(s32 *)(arg0 + 0x40) != 0) {
            frFontListKeepOrRelease(*(s32 *)(arg0 + 0x40));
            *(s32 *)(base + 4) = 0;
        }
        *(s16 *)(base + 0xC) = 0;
        *(s16 *)(base + 0x12) = 0;
        *(s16 *)(base + 0xE) = -1;
        *(s32 *)(base + 8) = 0;
        v = *(s32 *)arg0 & ~0x38;
        *(s32 *)arg0 = v;
        v = v & ~0xC00;
        *(s32 *)arg0 = v;
        *(s32 *)arg0 = v & 0xFFFBFFFF;
        itfMesWindowFreeSlots(arg0 + 0x94);
        *(s32 *)arg0 = 0;
        poolFree(arg0);
    }
}
// FUN_00278C60
static void itfMesApplyRelocs(int *param_1, int param_2, u8 *param_3, int param_4)
{
  u8 bVar1;
  u8 *pbVar3;
  int iVar4;
  int iVar5;
  int updateOffset;

  pbVar3 = param_3;
  goto check;
  do {
    bVar1 = *pbVar3;
    pbVar3 = pbVar3 + 1;
    if ((bVar1 & 1) == 0) {
      updateOffset = (int)(u32)bVar1 >> 1;
      goto update;
    }
    if ((bVar1 & 2) == 0) {
      updateOffset = (bVar1 | ((int)*pbVar3 << 8)) >> 2;
      pbVar3 = pbVar3 + 1;
      goto update;
    }
    if ((bVar1 & 4) == 0) {
      updateOffset = ((bVar1 | ((int)*pbVar3 << 8)) | ((int)pbVar3[1] << 16)) >> 3;
      pbVar3 = pbVar3 + 2;
      goto update;
    }
    iVar5 = ((int)(u32)bVar1 >> 3) + 2;
    for (iVar4 = 0; iVar4 < iVar5; iVar4 = iVar4 + 1) {
      param_1 = param_1 + 1;
      *param_1 = *param_1 + param_2;
    }
    goto check;
update:
    param_1 = param_1 + updateOffset;
    *param_1 = *param_1 + param_2;
check:
    updateOffset = ((int)pbVar3 - (int)param_3 < param_4);
    if (updateOffset == 0) {
      return;
    }
  } while (1);
}



/* Private helper knowledge keeps arg0 in t3 across relocation. Staged
   arguments with propagation off preserve the load/move order.
   Measured: 76B of matching instructions and a 4B zero tail; helper 240B MATCH. */
// FUN_00278D50
#pragma push
#pragma opt_propagation off
void itfMesRecordFixup(u8 *arg0)
{
    u8 *base;
    u8 *fixups;
    s32 size;

    if (*(u8 *)(arg0 + 0x1C) == 0) {
        base = arg0 + 0x20;
        fixups = arg0 + *(s32 *)(arg0 + 0x10);
        size = *(s32 *)(arg0 + 0x14);
        itfMesApplyRelocs((int *)base, (int)base, fixups, size);
        *(u8 *)(arg0 + 0x1C) = 1;
    }
}
#pragma pop
// FUN_00278DA0
s32 itfMesRecordIsValid(u8 *arg0)
{
    s32 tag;
    s32 result;

    result = 1;
    tag = *(s32 *)(arg0 + 8);
    if ((tag != 0x3047534D) && (tag != 0x3147534D)) {
        result = 0;
    }
    return result != 0;
}
/* wave14: the former inline `volatile` on this load (which forced the
   `lw $v1, 4($a0)` ahead of the sll; removing it plain lost MATCH -> nd 9)
   is REPLACED by the lever-6 integer-domain spelling
   `(s32)*(s32 **)((u32)param_1 + 4)` - measured to tie the volatile byte-
   for-byte (fndiff 2 = benign tail padding; verify MATCH, decomp_lint clean).
   No volatile remains in this file. */
// FUN_00278DE0
int itfMesRecordEntry(int param_1,int param_2)
{
  s32 base;
  s32 index;

  base = (s32)*(s32 **)((u32)param_1 + 4);
  index = param_2 * 8;
  return index + base + 0x20;
}
// FUN_00278E00
int itfMesRecordTail(int param_1)
{
  int iVar1;

  iVar1 = *(int *)(param_1 + 0x18) * 8;
  return iVar1 + param_1 + 0x20;
}



// FUN_00278E20
s32 itfMesWindowEntryValue(s32 arg0, s32 arg1)
{
    u8 *object;
    s32 off;

    object = D_00881808[arg0].unk0;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0xB3E);
    off = arg1 * 8;
    return *(s32 *)(off + (s32)(*(s32 *)(object + 4)) + 0x20);
}

// FUN_00278E90
s32 itfMesWindowRecordCount(s32 arg0)
{
    u8 *object;

    object = D_00881808[arg0].unk0;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0xB55);
    return *(s32 *)(*(s32 *)(object + 4) + 0x18);
}

// FUN_00278EF0
void itfMesWindowSetGlyphStyle(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s64 arg4)
{
    u8 *object;
    u8 *tmp;

    object = D_00881808[arg0].unk0;
    tmp = *(u8 **)(object + 0x20);
    if (tmp != NULL) {
        frFontSetListFlag(tmp, arg3 & 0xFF);
        frFontSetNodeId(tmp, (s64)(s16)arg4);
        frFontSetListSlot(tmp, arg1);
        frFontSetGlyphAux(tmp, arg2 & 0xFF);
        return;
    }
    *(s8 *)(object + 0x26) = arg1;
    *(s8 *)(object + 0x27) = arg2;
    *(s8 *)(object + 0x29) = arg3;
}
// FUN_00278FB0
s32 itfMesWindowGetTextList(s32 arg0)
{
    return *(s32 *)(D_00881808[arg0].unk0 + 0x20);
}



// FUN_00278FD0
s32 itfMesWindowGetBodyList(s32 arg0)
{
    return *(s32 *)(D_00881808[arg0].unk0 + 0x14);
}



// FUN_00278FF0
s32 itfMesWindowGetFontList(s32 arg0)
{
    return *(s32 *)(D_00881808[arg0].unk0 + 0x40);
}

// FUN_00279010
s32 func_00279010(s32 arg0)
{
    return *(s16 *)(D_00881808[arg0].unk0 + 0x4E);
}

/* Measured: 448B/448B MATCH. The integer-address load preserves base-before-
   index evaluation; mixed byte cast/mask forms avoid call-crossing mask reuse.
   The unsigned index shift preserves EE wrapping arithmetic. */
// FUN_00279030
u8 *itfMesWindowBuildEntry(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5)
{
    u8 *obj;
    u8 *result;
    u8 *entry;
    u8 *slot;

    obj = D_00881808[arg4].unk0;
    if (obj == NULL)
        kAssertFail(D_0063BE10, 0xBDD);
    slot = (u8 *)(((u32)arg5 << 3) + (s32)*(s32 **)((u32)obj + 4) + 0x20);
    if (slot == NULL)
        kAssertFail(D_0063BE10, 0xBE0);
    entry = *(u8 **)(slot + 4);
    if (entry == NULL)
        kAssertFail(D_0063BE10, 0xBE3);
    result = (u8 *)itfMesRecordTextAt((s32)entry, 0);
    if (result == NULL)
        kAssertFail(D_0063BE10, 0xBE6);
    result = frFontBuildTextSimple(
        (s32)(16.0f * fparg0),
        (s32)(8.0f * fparg1),
        (u32)arg1 & 0xFF,
        (u8)arg2,
        0U,
        0xFFU,
        (u32)result,
        0U
    );
    if (arg3 & 1)
        frFontSetGlyphAux(result, (u32)arg2 & 0xFF);
    frFontSetGlyphColor(result, arg0);
    frFontExSetScale(result, fparg2);
    return result;
}
// FUN_002791F0
s32 itfMesWindowDrawEntry(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5)
{
    u8 *obj;

    itfMesApplySlotTable(D_00881808[arg4].unk0 + 0x94);
    obj = itfMesWindowBuildEntry(fparg0, fparg1, fparg2, arg0, arg1, arg2, arg3, arg4, arg5);
    frFontSetListSlot(obj, arg1);
    frFontDrawListMode(obj, 1);
    frFontListKeepOrRelease((s32)obj);
    return 0;
}

// FUN_00279300
void itfMesWindowDrawCallback(u8 *arg0, s32 arg1) {
    frFontDrawList((void *)arg1, 1, 0);
    frFontListKeepOrRelease(arg1);
}

// FUN_00279350
s32 itfMesWindowQueueEntry(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, u8 *arg6)
{
    u8 *obj;
    u8 *cb;

    itfMesApplySlotTable(D_00881808[arg4].unk0 + 0x94);
    obj = itfMesWindowBuildEntry(fparg0, fparg1, fparg2, arg0, arg1, arg2, arg3, arg4, arg5);
    frFontSetListSlot(obj, arg1);
    cb = func_00460990();
    *(void (**)(void))(cb + 8) = (void (*)(void))itfMesWindowDrawCallback;
    *(u8 **)(cb + 0x10) = obj;
    func_00460ac0(arg6, cb);
    return 0;
}

// FUN_00279470
s32 itfMesWindowDrawPair(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7)
{
    u8 *obj;
    u8 *r;
    u8 *r2;

    obj = D_00881808[arg4].unk0;
    if (arg4 < 0)
        kAssertFail(D_0063BE10, 0xC32);
    if (arg6 < 0)
        kAssertFail(D_0063BE10, 0xC33);
    itfMesApplySlotTable(obj + 0x94);
    r = itfMesWindowBuildEntry(fparg0, fparg1, fparg2, arg0, arg1, arg2, arg3, arg4, arg5);
    if (arg7 != 0) {
        if (*(s32 *)(r + 0x24) == 0) {
            r2 = itfMesWindowBuildEntry(fparg0, 25.0f + fparg1, fparg2, arg0, arg1, arg2, arg3, arg6, arg7);
        } else {
            r2 = itfMesWindowBuildEntry(fparg0 + (f32)frFontNodeWidth(r), 25.0f + fparg1, fparg2, arg0, arg1, arg2, arg3, arg6, arg7);
        }
        r = frFontAppendList(r, r2, 0);
    }
    frFontSetListSlot(r, arg1);
    frFontDrawListMode(r, 1);
    frFontListKeepOrRelease((s32)r);
    return 0;
}

/* measured: integer-domain index-first address `(u8 *)(arg1 * 8) + (u32)base` preserves retail's addu operand order; normalized_diff 0, object 172B/176B (trailing word is alignment padding). */
// FUN_00279690
s64 itfMesWindowRunEntry(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    u8 *obj;
    u8 *base;
    u8 *address;

    obj = D_00881808[arg0].unk0;
    if (obj == NULL)
        kAssertFail(D_0063BE10, 0xC50);
    base = (u8 *)*(s32 *)(obj + 4);
    address = (u8 *)(arg1 * 8) + (u32)base;
    return frFontRunCommand(itfMesRecordTextAt(*(s32 *)(address + 0x24), 0), arg2, arg3);
}
// FUN_00279740
u32 itfMesRecordTextAt(int param_1,int param_2)
{
  u32 uVar1;
  int count = *(short *)(param_1 + 0x18);

  if ((param_2 < 0) || (param_2 >= count)) {
    uVar1 = 0;
  }
  else {
    int address = param_2 * 4;
    address = address + param_1;
    uVar1 = *(u32 *)(address + 0x1c);
  }
  return uVar1;
}



/* Measured: 768B/window 768B, exact match. Named zero origins with
   opt_propagation off preserve constructor argument order. The binding
   helper consumes a text pointer; its pointer parameter also restores
   the final argument-move ordering. */
#pragma push
#pragma opt_propagation off
// FUN_00279780
void itfMesWindowBuildRow(u8 *arg0)
{
    u8 *base;
    u8 *table;
    u8 *slot;
    u8 *obj;
    u8 *node;
    s32 index;
    s32 count;
    s32 flags;
    s32 found;

    base = arg0 + 0x1C;
    if (*(s32 *)(arg0 + 0x20) != 0) {
        frFontListKeepOrRelease(*(s32 *)(arg0 + 0x20));
        *(s32 *)(base + 4) = 0;
    }
    index = *(s16 *)(base + 0x10);
    table = *(u8 **)base;
    count = *(s16 *)(table + 0x18);
    if (index < 0 || index >= count)
        slot = NULL;
    else
        slot = *(u8 **)(((u32)index << 2) + (s32)table + 0x1C);
    if (slot == NULL)
        kAssertFail(D_0063BE10, 0xC82);
    iGpffffb4b0 = 0x7B;
    {
        u32 originX = 0;
        u32 originY = 0;
        obj = frFontBuildTextSimple(
            originX, originY, *(u8 *)(base + 0xA), *(u8 *)(base + 0xB),
            *(u8 *)(base + 0xC), *(u8 *)(base + 0xD), (u32)slot, 0);
    }
    iGpffffb4b0 = 0;
    if (obj == NULL)
        kAssertFail(D_0063BE10, 0xCAA);
    *(u8 **)(base + 4) = obj;
    if (obj != NULL)
        *(s16 *)(base + 0xE) = itfMesLineCount((u8 *)frFontListTail((s32)obj), obj);
    flags = frFontMaskFlags(3);
    *(u8 *)(base + 9) = (u8)flags;
    if (*(u8 *)(base + 9) & 2U)
        *(s32 *)arg0 |= 0x10000;
    else
        *(s32 *)arg0 &= ~0x10000;
    flags = frFontMaskFlags(0x30);
    if (flags != 0)
        *(s32 *)arg0 |= 0x08000000;
    else
        *(s32 *)arg0 &= ~0x08000000;
    if (flags & 0x20)
        *(s32 *)arg0 |= 0x04000000;
    else
        *(s32 *)arg0 &= ~0x04000000;
    func_0027a340(obj, *(s32 *)(arg0 + 0xC));
    if (frFontMaskFlags(4) != 0)
        itfMesWindowSetLabel(arg0, D_00881530);
    node = *(u8 **)DAT_008817EC_abs;
    goto list_test;
list_body:
    if (*(u8 **)(node + 0xC) == arg0) {
        found = *(s32 *)(node + 8);
        goto list_done;
    }
    node = *(u8 **)(node + 4);
list_test:
    if (node != NULL)
        goto list_body;
    found = -1;
list_done:
    itfMesWindowSendLayoutLists(found);
    if ((*(s32 *)arg0 & 0x400000) == 0 &&
        (*(u16 *)D_008817E8_abs & 1U) != 0)
        itfMesListEnableVisible((s32)obj);
    itfMesWindowSetMetrics((s32)obj, (s32)base);
    if ((*(s32 *)arg0 & 0x300) == 0x200) {
        s32 value;

        index = *(s16 *)(arg0 + 0x2C);
        table = *(u8 **)(arg0 + 0x1C);
        count = *(s16 *)(table + 0x18);
        if (index < 0 || index >= count)
            value = 0;
        else
            value = *(s32 *)(((u32)index << 2) + (s32)table + 0x1C);
        frFontRunCommand(value, 1, 0);
    }
}
#pragma pop
// FUN_00279A80
void itfMesObjectSetString(u8 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    s32 size;
    s32 base;
    s32 *slot;
    s32 *res;

    if (arg0 == NULL)
        kAssertFail(D_0063BE10, 0xCF1);
    if ((arg1 < 0) || (arg1 >= 0x20))
        kAssertFail(D_0063BE10, 0xCF2);
    base = (s32)arg0 + 0x94;
    slot = (s32 *)(base + arg1 * 4);
    if (*slot != 0) {
        poolFree(*slot);
        *slot = 0;
    }
    if (arg3 <= 0) {
        size = (strlen((const void *)arg2) + 4) & ~3;
        func_0046a2d0(D_0063BE10, 0xD0F);
        res = (s32 *)func_0046a430(size);
        *(s32 **)((u32)base + (u32)arg1 * 4) = res;
        memcpy(res, (void *)arg2, size);
    } else {
        size = (arg3 + 5) & ~3;
        func_0046a2d0(D_0063BE10, 0xD22);
        res = (s32 *)func_0046a430(size);
        *(s32 **)((u32)base + (u32)arg1 * 4) = res;
        memset(res, 0, size);
        memcpy(*(s32 **)((u32)base + (u32)arg1 * 4), (void *)arg2, arg3);
    }
}

/* MATCH (wave14): the old "CSE/allocator floor" was broken by lever 6 -
   spelling the POST-call slot store with integer-domain address arithmetic,
   `*(s32 **)((u32)base + (u32)arg1 * 4) = res;`, so its CSE key differs from
   the pre-call `slot = (s32 *)(base + arg1 * 4)` read. mwcc then RE-derives
   base+arg1*4 after the calls exactly like retail (sll $v1,$s3,2; addu
   $v1,$s2,$v1) instead of holding the full slot address live across the
   func_0046a2d0/func_0046a430 jals; base stays live in $s2 and the arg->$s
   mapping falls into retail's $s1/$s3/$s0. Prior attempts (slot local, bare
   expr, arg1<<2, s32/u8-star lvalue casts, opt_propagation off) all stayed
   nd 51; the DISTINCT-CAST address spelling is the only thing that worked.
   obj 220B vs window 224B (benign tail pad). */
// FUN_00279C00
void itfMesObjectSetNumber(u8 *arg0, s32 arg1, s32 arg2) {
    s32 base;
    s32 *slot;
    u8 *v;
    s32 *res;

    if (arg0 == NULL) {
        kAssertFail(D_0063BE10, 0xD38);
    }
    if ((arg1 < 0) || (arg1 >= 0x20)) {
        kAssertFail(D_0063BE10, 0xD39);
    }
    base = (s32)arg0 + 0x94;
    slot = (s32 *)(base + arg1 * 4);
    v = *(u8 **)slot;
    if (v != NULL) {
        poolFree((s32)v);
        *(u8 **)slot = NULL;
    }
    func_0046a2d0(D_0063BE10, 0xD55);
    res = (s32 *)func_0046a430(4);
    *(s32 **)((u32)base + (u32)arg1 * 4) = res;
    *res = arg2;
}
// FUN_00279CE0
void itfMesApplySlotTable(int param_1)
{
  int iVar1;

  for (iVar1 = 0; iVar1 < 0x20; iVar1 = iVar1 + 1) {
    func_002746c0(iVar1,*(u32 *)(param_1 + iVar1 * 4));
  }

  return;
}



// FUN_00279D40
void itfMesWindowApplySlots(s32 arg0)
{
    u8 *entry;
    s32 i;

    entry = D_00881808[arg0].unk0;
    if (entry == 0) {
        kAssertFail(D_0063BE10, 0xD76);
    }
    for (i = 0; i < 0x20; i++) {
        func_002746c0(i, *(u32 *)(entry + i * 4 + 0x94));
    }
}

// FUN_00279DD0
void itfMesWindowSetLabel(u8 *arg0, u8 *arg1)
{
    s32 global;
    u8 *base;

    if (arg0 == NULL)
        kAssertFail(D_0063BE10, 0xD96);
    base = arg0 + 0x14;
    if (*(s32 *)(arg0 + 0x14) != 0)
        frFontListKeepOrRelease(*(s32 *)(arg0 + 0x14));
    global = iGpffffb4b0;
    if (global == 0)
        iGpffffb4b0 = 0x7B;
    *(s32 *)(base + 0) = (s32)frFontBuildTextSimple(0, 0, 0, 2, 0, 0xFF, (u32)arg1, 0);
    iGpffffb4b0 = global;
    *(u16 *)(base + 4) = 0xFFFF;
}

static inline s32 addOff7e90(s32 off, s32 base) { return off + base; }

/* measured: func_00279e90 now matches exactly (object 316B, retail window
   320B, normalized_diff 0). The existing saved halfword/local and index-first
   addOff7e90 helper preserve retail's frame and address calculation. The
   first branch's unsigned handle load matches the canonical u32 constructor
   parameter without a conflicting local prototype. The second branch's
   explicit u32 cast preserves its load-before-argument-moves order. */
// FUN_00279E90
void itfMesWindowSetSelectionText(u8 *arg0, u8 *arg1)
{
    s32 global;
    u8 *base;
    s32 X;
    u16 v;
    s32 masked;

    base = arg0 + 0x14;
    v = *(u16 *)(arg1 + 0x1A);
    if (*(u16 *)(arg0 + 0x18) == v)
        return;
    if (*(s32 *)base != 0) {
        frFontListKeepOrRelease(*(s32 *)base);
        *(s32 *)base = 0;
    }
    *(u16 *)(base + 4) = v;
    global = iGpffffb4b0;
    if (global == 0)
        iGpffffb4b0 = 0x7B;
    masked = v & 0xFFFF;
    if (masked != 0xFFFF) {
        if (masked & 0x8000) {
            s32 off;
            u32 p7;
            off = (masked & 0x7FFF) << 2;
            p7 = *(u32 *)(addOff7e90(off, (s32)arg0) + 0x94);
            *(s32 *)base = (s32)frFontBuildTextSimple(0, 0, 0, 0, 0, 0xFF, p7, 0);
        } else {
            s32 ep;
            s32 v2;
            v2 = *(u16 *)(arg0 + 0x18);
            ep = *(s32 *)((*(s32 *)(*(s32 *)(arg0 + 4) + 0x18) << 3) + *(s32 *)(arg0 + 4) + 0x20);
            *(s32 *)base = (s32)frFontBuildTextSimple(0, 0, 0, 0, 0, 0xFF,
                (u32)*(s32 *)(ep + (v2 << 2)), 0);
        }
        func_0027a340((u8 *)*(s32 *)base, *(s32 *)(arg0 + 0xC));
    }
    iGpffffb4b0 = global;
}
// FUN_00279FD0
int itfMesCountClearBits(int param_1,u32 param_2)
{
  int iVar1;

  iVar1 = 0;
  for (; 0 < param_1;) {
    if ((param_2 & 1) == 0) {
      iVar1 = iVar1 + 1;
    }
    param_1 = param_1 + -1;
    param_2 = param_2 >> 1;
  }
  return iVar1;
}



// FUN_0027A010
u8 *itfMesBuildGlyphRun(u32 *arg0, s32 arg1, u32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7)
{
    s32 i;
    u8 *result;

    result = NULL;
    i = 0;
    while (i < arg1) {
        if (arg2 & 1) {
            arg2 >>= 1;
        } else {
            result = frFontBuildTextSimple(arg3, arg4, (u8)arg7, 5, 0, 0xFF, *arg0, (u32)result);
            if (arg6 == 0)
                arg4 += *(s16 *)(result + 0x12) * 8;
            else
                arg4 += arg6;
            arg2 >>= 1;
        }
        i++;
        arg0++;
    }
    if (result != NULL) {
        func_0027a340(result, arg5);
        itfMesListSetAlpha((int)result, 0xFF);
    }
    return result;
}

/* Detach one node before the release helper can consume its linked chain.
   Keep the successor locally: release may retain the node while glyphs fade. */
static inline void releaseMessageListNode(u8 **link)
{
    u8 *node = *link;
    u8 *next = *(u8 **)(node + 0x24);

    *(u8 **)(node + 0x24) = NULL;
    *(u8 **)(node + 0x28) = NULL;
    *(u8 **)(node + 0x2C) = node;
    frFontListKeepOrRelease((s32)node);
    *link = next;
}

/* measured: b210 -O2, 332 executable bytes / 336B window, all five
   relocations exact. Local traversal ownership and head-before-tail
   declarations close the saved-register floor; the final word is alignment. */
// FUN_0027A150
u8 *itfMesReleaseTagRun(u8 *arg0, s32 arg1, s32 arg2)
{
    s32 remaining;
    s32 tag;
    u8 *head;
    u8 *tail;
    u8 *cursor;
    s32 value;
    u8 *current;

    current = arg0;
    if (current == NULL)
        kAssertFail(D_0063BE10, 0xE3E);
    remaining = arg2 - arg1 - 1;
    tag = *(s32 *)(current + 8);
    while (remaining > 0) {
        while (tag == *(s32 *)(current + 8)) {
            releaseMessageListNode(&current);
            if (current == NULL)
                return NULL;
        }
        value = *(s32 *)(current + 8);
        remaining--;
        tag = value;
    }
    head = current;
    do {
        tail = current;
        current = *(u8 **)(current + 0x24);
    } while (current != NULL && tag == *(s32 *)(current + 8));
    while (current != NULL) {
        releaseMessageListNode(&current);
    }
    *(s32 *)(head + 0x28) = 0;
    *(s32 *)(tail + 0x24) = 0;
    for (cursor = head; cursor != NULL; cursor = *(u8 **)(cursor + 0x24)) {
        *(u8 **)(cursor + 0x2C) = tail;
    }
    return head;
}
// FUN_0027A2A0
void itfMesWindowSetMetrics(int param_1, int param_2)
{
    int ptr;

    ptr = *(int *)(param_1 + 0x20);
    *(char *)(param_2 + 0xD) = (char)((int)(u32)*(u8 *)(param_1 + 2) >> 1);
    *(u8 *)(param_2 + 0xA) = *(u8 *)(ptr + 0x15);
    *(u8 *)(param_2 + 0xB) = *(u8 *)(ptr + 0x14);
    *(u8 *)(param_2 + 0xC) = *(u8 *)(ptr + 0x16);
}

// FUN_0027A2D0
s32 itfMesLineCount(u8 *arg0, u8 *arg1)
{
    if (*(s16 *)(arg1 + 0x12) <= 0) {
        kAssertFail(D_0063BE10, 0xE9F);
    }
    return ((*(s32 *)(arg1 + 8) - *(s32 *)(arg0 + 8)) >> 3) /
               *(s16 *)(arg1 + 0x12) + 1;
}

/* Recovered after withdrawing the branch-landing boundary 0x0027A350: this
   function opens with `b 0x0027A350` into its own loop test, which spimdisasm
   recorded as a separate function, leaving only a 16-byte window here. 0x0027A340
   has 3 jal sites, 0x0027A350 none. See reconcile.BRANCH_LANDING_ENTRIES. */
// FUN_0027A340
void func_0027a340(u8 *arg0, int arg1)
{
    while (arg0 != NULL) {
        *(int *)(arg0 + 0x14) = arg1;
        arg0 = *(u8 **)(arg0 + 0x24);
    }
}

// FUN_0027A370
/* Not `static`: the symbol must stay global so the linker can resolve the
 * retail asm blob's jal to this address (measured: mwldps2 reports Undefined
 * "func_0027a370" if local).
 * The K&R parameter list below is the donor's form and is load-bearing. */
int itfMesListSetColor(param_1,param_2,param_3,param_4)
int param_1;
int param_2;
int param_3;
u8 param_4;
{
  int color;
  int diff;
  int cat;
  int candidate;

  diff = param_3 - param_2;
  param_2 = diff - 1;
  cat = *(int *)(param_1 + 8);
  goto count_check;

advance:
  param_1 = *(int *)(param_1 + 0x24);
  if (param_1 == 0) {
    goto done;
  }

load:
  candidate = *(int *)(param_1 + 8);
  if (cat == candidate) {
    goto advance;
  }
  param_2 = param_2 - 1;
  cat = candidate;

count_check:
  if (param_2 > 0) {
    goto load;
  }

set_start:
  color = (u8)param_4;
set_load:
  candidate = *(int *)(param_1 + 0x1c);
  goto set_check;

set_store:
  *(u8 *)(candidate + 0x14) = (u8)color;
  candidate = *(int *)(candidate + 0x28);

set_check:
  if (candidate != 0) {
    goto set_store;
  }
  param_1 = *(int *)(param_1 + 0x24);
  switch (param_1) {
  case 0:
    goto done;
  }
  candidate = *(int *)(param_1 + 8);
  if (cat == candidate) {
    goto set_load;
  }
  goto done;
done:
  return;
}


/* Removing this loses FUN_0027A4D0 (MATCH nd0 -> MISMATCH nd24) - measured W161. */
#pragma opt_loop_invariants on

// FUN_0027A4D0
void itfMesListSetAlpha(int param_1,u32 param_2)
{
  int iVar1;

  for (; param_1 != 0; param_1 = *(int *)(param_1 + 0x24)) {
    for (iVar1 = *(int *)(param_1 + 0x1c); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x28)) {
      *(u32 *)(iVar1 + 0x10) = *(u32 *)(iVar1 + 0x10) & 0xffffff00 | param_2;
    }
  }
  return;
}
#pragma opt_loop_invariants off



// FUN_0027A520
int itfMesListWidth(int param_1)
{
  int iVar3;
  int iVar1;
  int iVar2;

  iVar3 = 0;
  goto outer_test;
outer_body:
  iVar1 = *(int *)(param_1 + 8);
  iVar2 = 0;
  do {
    iVar2 += *(int *)(param_1 + 0xc);
    param_1 = *(int *)(param_1 + 0x24);
    if (param_1 == 0) {
      break;
    }
  } while (iVar1 == *(int *)(param_1 + 8));
  if (iVar3 < iVar2) {
    iVar3 = iVar2;
  }
outer_test:
  if (param_1 != 0) {
    goto outer_body;
  }
  return iVar3 << 4;
}



// FUN_0027A580
void itfMesListEnableVisible(int param_1)
{
  for (; param_1 != 0; param_1 = *(int *)(param_1 + 0x24)) {
    if (*(u8 *)(*(int *)(param_1 + 0x1c) + 0x16) == '\0') {
      frFontEnableList(param_1);
    }
  }

  return;
}



// FUN_0027A6C0
void itfMesClearSlots(int param_1)
{
  int iVar1;

  for (iVar1 = 0; iVar1 < 0x20; iVar1 = iVar1 + 1) {
    *(u32 *)(param_1 + iVar1 * 4) = 0;
  }

  return;
}




// FUN_0027B620
u64 itfMesFlushPending(void)
{
    int current;
    u32 count;

    current = *(int*)DAT_008817EC_abs;
    while (current != 0) {
        itfMesWindowUpdateLists(*(u32*)(current + 0xc));
        current = *(int*)(current + 4);
    }
    count = *(u32*)DAT_008817E4_abs;
    *(u32*)DAT_008817E4_abs = count + 1;
    return 0;
}
