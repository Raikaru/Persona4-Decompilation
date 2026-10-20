/* Whole-file translation unit (functions contiguous in retail). */
#include "type.h"
#include "model_callbacks_internal.h"

typedef struct MdlAppObj
{
    u8  pad0[0xD4];
    u16 id;          /* 0xD4 */
    u16 subId;       /* 0xD6 */
    u8  pad1[0x2D0 - 0xD8];
    void *bc;        /* 0x2D0 */
} MdlAppObj;

typedef struct MdlAppBc
{
    u32 unk0;
    s32 slot;
    u8  pad8[0x12 - 0x08];
    u16 flags;       /* 0x12: bit 0 loaded, bit 1 primary read requested */
    s32 primaryRead; /* 0x14 */
    s32 secondaryRead; /* 0x18 */
} MdlAppBc;

extern s32 mdlSeIsLoaded(u32 type, u16 id);
extern void *mdlSeCreateRecord(u32 type, u16 id, s32 kind);
extern s32 mdlSeAcquireSlot(u32 type, u16 id);
extern s32 datGetFlag(s32 bit);
extern s64 datGetDateIndex(void);
extern s32 calGetDayWindowFlags(s16 day);
extern s32 sprintf(char *buf, char *fmt, ...);
extern void func_00440b68(char *fmt, ...);
extern s32 H_Cdvd_AcquireDirectory(void *path, s32 flags);
extern void H_Cdvd_ReadSync(s32 cdvd);
extern s32 btlBossResolveModelName(u32 modelKind, u16 modelId, char *path);
extern s32 mdlFileIsTypePac(u32 type, u16 id);
extern s32 mdlResolvePacPath(u32 type, u16 id, char *path);
extern s32 mdlAttachWeaponModelSlots(void *model);
extern void mdlAppBindSecondaryText(MdlAppObj *obj);

extern char D_00635820[];
extern char D_00635840[];
extern char D_00635860[];
extern char D_00635878[];
extern char D_00635890[];
extern char D_00635678[];
extern char D_006358B0[];
extern char D_006358D0[];
extern char D_007636e0;
extern char D_007636e8;

/* Binds the per-object sound record: kind 1 gets text chosen from the day window, kind 2 gets a slot and text; sets the loaded flag. Returns 0 for other ids. Registered as the model object callback. */
// FUN_00230F20
s32 mdlAppBindObjectRecord(MdlAppObj *obj)
{
    char buf[0x100];
    void **bcp = &obj->bc;
    u32 id = obj->id;
    u16 subId = obj->subId;

    if (mdlSeIsLoaded(id, subId) != 0)
        return 1;
    if (*bcp != 0 && (((MdlAppBc *)*bcp)->flags & 1))
        return 1;
    switch (id & 0xFFFF)
    {
    case 1:
        if (*bcp == 0)
            *bcp = mdlSeCreateRecord(id, subId, 1);
        if (datGetFlag(0x1438) != 0 && (subId & 0xFFFF) == 1)
            sprintf(buf, D_00635820, &D_007636e0, subId & 0xFFFF);
        else if (calGetDayWindowFlags((s16)datGetDateIndex()) & 1)
            sprintf(buf, D_00635840, &D_007636e0, subId & 0xFFFF);
        else
            sprintf(buf, D_00635860, &D_007636e0, subId & 0xFFFF);
        func_00440b68(&D_007636e8, D_00635878, 0x10F);
        ((MdlAppBc *)*bcp)->primaryRead = H_Cdvd_AcquireDirectory(buf, 0);
        ((MdlAppBc *)*bcp)->flags |= 2;
        break;
    case 2:
        if (*bcp == 0)
            *bcp = mdlSeCreateRecord(id, subId, 2);
        mdlAppBindSecondaryText(obj);
        ((MdlAppBc *)*bcp)->slot = mdlSeAcquireSlot(id, subId);
        sprintf(buf, D_00635890, D_00635678, subId & 0xFFFF);
        func_00440b68(&D_007636e8, D_00635878, 0x12F);
        ((MdlAppBc *)*bcp)->primaryRead = H_Cdvd_AcquireDirectory(buf, 1);
        ((MdlAppBc *)*bcp)->flags |= 2;
        break;
    default:
        return 0;
    }
    return 1;
}

/* For kind 2 records, binds the secondary text string for the listed sub-ids and clears it otherwise. */
// FUN_002311A0
void mdlAppBindSecondaryText(MdlAppObj *obj)
{
    char buf[0x100];
    void **bcp = &obj->bc;
    u32 id = obj->id;
    u16 subId = obj->subId;
    void *bc;

    if (mdlSeIsLoaded(id, subId) != 0)
        return;
    bc = *bcp;
    if (bc != 0 && (((MdlAppBc *)bc)->flags & 1))
        return;
    switch (id & 0xFFFF)
    {
    case 1:
        break;
    case 2:
        if (bc == 0)
            *bcp = mdlSeCreateRecord(id, subId, 2);
        switch (subId & 0xFFFF)
        {
        case 0x100:
        case 0x101:
        case 0x102:
        case 0x103:
        case 0x104:
        case 0x105:
        case 0x106:
        case 0x107:
        case 0x108:
        case 0x109:
        case 0x10A:
        case 0x10B:
        case 0x10E:
        case 0x112:
            sprintf(buf, D_006358B0, D_00635678, subId & 0xFFFF);
            func_00440b68(&D_007636e8, D_00635878, 0x16E);
            ((MdlAppBc *)*bcp)->secondaryRead = H_Cdvd_AcquireDirectory(buf, 0);
            break;
        default:
            ((MdlAppBc *)*bcp)->secondaryRead = 0;
            break;
        }
        break;
    default:
        break;
    }
}

/* Registers the model callbacks: boss-name resolver, PAC-file test, PAC path resolver, weapon-slot attach and object record binding. */
// FUN_002312E0
void mdlAppRegisterModelCallbacks(void)
{
    mdlSetModelCallbacks(btlBossResolveModelName, mdlFileIsTypePac, mdlResolvePacPath,
                  mdlAttachWeaponModelSlots, mdlAppBindObjectRecord);
}

/* Reads the startup resource: emits the preload message, then synchronously reads the file named by the string at D_006358D0. */
// FUN_00231330
void mdlAppPreloadResource(void)
{
    func_00440b68(&D_007636e8, D_00635878, 0x1A2);
    H_Cdvd_ReadSync(H_Cdvd_AcquireDirectory(D_006358D0, 0));
}
