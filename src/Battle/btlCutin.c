/* Original translation unit btlCutin.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
extern u8 *iGpffffb3ac;
extern void mdlEffectDestroyWithNodes();
extern u8 *btlPacketAlloc();
extern s32 btlCutinPoll();
extern void memcpy();
extern void btlCutinLoad(u8 *arg0);
extern s32 btlCutinLoadStatus();
extern s32 H_Cdvd_IsFileLoaded();
extern void H_Cdvd_Destroy();
extern s32 mdlEffectIsFinished();
extern void func_00485630();
extern void func_00485870();
extern void *TnGetTableBase();
extern void TnSetTableBase();
extern u8 D_005DC8CC[];
extern char D_00625190[];
extern char D_00625090[];
extern char D_006251C0[];
extern char iGpffffa528[8];
extern const char *iGpffffa530[2];
extern s16 datGetDateIndex(void);
extern s32 calGetDayWindowFlags(s32 arg0);
extern u32 datGetFlag(s32 bit);
extern s32 cutinDrawTaskCreate();
extern s32 sprintf(char *dst, const char *format, ...);
extern s32 func_00440b68(const char *format, ...);
extern u8 *H_Cdvd_AcquireDirectory(u8 *path, s32 flags);
extern const char *iGpffffa520[2];
extern const char *D_00625050[3];
extern char D_00625060[];
extern char D_006250A0[];
extern char D_006250D0[];
extern char D_00625100[];
extern char D_00625130[];
extern char D_00625160[];


/* Exact under MWCC b210/O2: evaluate the case-0 count first, use the
   table element directly for the first format call, then retain the
   table-element address for the loop. */
// FUN_001F9CF0
void btlCutinLoad(u8 *arg0) {
    s32 temp_16;
    s32 temp_5;
    s32 var_19;
    char sp60[0x100];

    temp_5 = (calGetDayWindowFlags(datGetDateIndex()) & 1) != 0;
    switch (*(u16 *)arg0) {
    case 0: {
        const char **suffix;
        s32 count;
        count = *(s16 *)(arg0 + 8);
        sprintf(sp60, D_00625060, count + 1, count + 1, iGpffffa520[temp_5]);
        suffix = &iGpffffa520[temp_5];
        func_00440b68(iGpffffa528, D_00625090, 0x26);
        *(s32 *)(iGpffffb3ac + 0xB6C) = (u32)H_Cdvd_AcquireDirectory((u8 *)sp60, 0);
        var_19 = 0;
        while (var_19 < count) {
            temp_16 = var_19 * 4;
            sprintf(sp60, D_006250A0, count + 1, count + 1,
                          D_00625050[var_19],
                          *(s16 *)(arg0 + var_19 * 2 + 2), *suffix);
            func_00440b68(iGpffffa528, D_00625090, 0x2C);
            *(s32 *)(iGpffffb3ac + temp_16 + 0xB70) = (u32)H_Cdvd_AcquireDirectory((u8 *)sp60, 0);
            var_19++;
        }
        sprintf(sp60, D_006250D0, count + 1, count + 1);
        func_00440b68(iGpffffa528, D_00625090, 0x2F);
        *(s32 *)(iGpffffb3ac + 0xB58) = (u32)H_Cdvd_AcquireDirectory((u8 *)sp60, 0);
        break;
    }
    case 2:
        sprintf(sp60, D_00625100, *(s16 *)(arg0 + 2), iGpffffa520[temp_5]);
        func_00440b68(iGpffffa528, D_00625090, 0x35);
        *(s32 *)(iGpffffb3ac + 0xB58) = (u32)H_Cdvd_AcquireDirectory((u8 *)sp60, 0);
        break;
    case 4:
        if (*(s16 *)(arg0 + 2) < 0xB) sprintf(sp60, D_00625130, *(s16 *)(arg0 + 2));
        else sprintf(sp60, D_00625160, *(s16 *)(arg0 + 2));
        func_00440b68(iGpffffa528, D_00625090, 0x40);
        *(s32 *)(iGpffffb3ac + 0xB58) = (u32)H_Cdvd_AcquireDirectory((u8 *)sp60, 0);
        break;
    }
    *(u16 *)(iGpffffb3ac + 0xB50) = *(u16 *)arg0;
}



// FUN_001F9FA0
s32 btlCutinLoadStatus(void) {
    s32 var_18;
    s32 var_17;
    s32 temp_16;

    var_17 = 1;
    for (var_18 = 0; var_18 < 4; var_18++) {
        u8 *temp_4 = *(u8 **)((u32)var_18 * 4 + (u32)iGpffffb3ac + 0xB6C);
        if (temp_4 != NULL) {
            if (H_Cdvd_IsFileLoaded(temp_4) != 0) {
                if (!(*(s32 *)(iGpffffb3ac + 0xB4C) & 1)) {
                    temp_16 = var_18 * 4;
                    *(u8 **)(iGpffffb3ac + temp_16 + 0xB5C) = func_00484bb0(*(u8 **)(*(u8 **)(iGpffffb3ac + temp_16 + 0xB6C) + 0x110));
                }
                temp_16 = var_18 * 4;
                H_Cdvd_Destroy(*(u8 **)(iGpffffb3ac + temp_16 + 0xB6C));
                *(u8 **)(iGpffffb3ac + temp_16 + 0xB6C) = 0;
            } else {
                var_17 = 0;
            }
        }
    }
    if (var_17 != 0 && H_Cdvd_IsFileLoaded(*(u8 **)(iGpffffb3ac + 0xB58)) != 0) {
        s32 temp_3_2 = *(s32 *)(iGpffffb3ac + 0xB4C);
        if (!(temp_3_2 & 1)) {
            *(u8 **)(iGpffffb3ac + 0xB54) = func_00484bb0(*(u8 **)(*(u8 **)(iGpffffb3ac + 0xB58) + 0x110));
        } else {
            *(s32 *)(iGpffffb3ac + 0xB4C) = temp_3_2 & ~1;
        }
        H_Cdvd_Destroy(*(u8 **)(iGpffffb3ac + 0xB58));
        *(u8 **)(iGpffffb3ac + 0xB58) = 0;
        return 1;
    }
    return 0;
}

// FUN_001FA110
u8 *btlCutinCreatePacket(u8 *arg0) {
    u8 *p = btlPacketAlloc(0xC00, 0xA);

    *(u8 *)(p + 0x47) &= 0xEE;
    *(void **)(p + 0x68) = (void *)btlCutinLoad;
    *(void **)(p + 0x6C) = (void *)btlCutinLoadStatus;
    memcpy(*(s32 **)(p + 0x78), arg0, 0xA);
    return p;
}

// FUN_001FA190
s32 btlCutinUpdate(s32 *arg0) {
    u8 *temp_17;
    s32 temp_19;
    s32 temp_4;
    s32 temp_4_2;
    s32 var_16;
    s32 var_20;

    var_20 = 1;
    temp_17 = TnGetTableBase();
    TnSetTableBase(&D_005DC8CC);
    for (var_16 = 0; var_16 < 4; var_16++) {
        temp_4 = *(s32 *)((u32)var_16 * 4 + (u32)iGpffffb3ac + 0xB5C);
        if (temp_4 != 0) {
            if (mdlEffectIsFinished(temp_4) == 0) {
                temp_19 = var_16 * 4;
                func_00485630(*(s32 *)(iGpffffb3ac + temp_19 + 0xB5C));
                func_00485870(*(s32 *)(iGpffffb3ac + temp_19 + 0xB5C));
                var_20 = 0;
            } else {
                temp_19 = var_16 * 4;
                mdlEffectDestroyWithNodes(*(s32 *)(iGpffffb3ac + temp_19 + 0xB5C));
                *(s32 *)(iGpffffb3ac + temp_19 + 0xB5C) = 0;
            }
        }
    }
    temp_4_2 = *(s32 *)(iGpffffb3ac + 0xB54);
    if (temp_4_2 != 0) {
        if (mdlEffectIsFinished(temp_4_2) == 0) {
            func_00485630(*(s32 *)(iGpffffb3ac + 0xB54));
            func_00485870(*(s32 *)(iGpffffb3ac + 0xB54));
            var_20 = 0;
        } else {
            mdlEffectDestroyWithNodes(*(s32 *)(iGpffffb3ac + 0xB54));
            *(s32 *)(iGpffffb3ac + 0xB54) = 0;
        }
    }
    TnSetTableBase(temp_17);
    *arg0 += 1;
    return var_20;
}

// FUN_001FA320
u8 *btlCutinCreateEndPacket(void) {
    u8 *p = btlPacketAlloc(0xC01, 4);

    *(u8 *)(p + 0x47) &= 0xEE;
    *(void **)(p + 0x6C) = (void *)btlCutinUpdate;
    **(s32 **)(p + 0x78) = 0;
    return p;
}

// FUN_001FA370
s32 btlCutinPoll(void) {
    s32 i;
    s32 off;
    u8 *base;
    u8 *p;
    s32 h;

    for (i = 0; i < 4; i++) {
        base = iGpffffb3ac;
        off = i * 4;
        p = base + off;
        if (*(s32 *)(p + 0xB6C) != 0) {
            *(s32 *)(base + 0xB4C) |= 1;
        } else {
            h = *(s32 *)(p + 0xB5C);
            if (h != 0) {
                mdlEffectDestroyWithNodes(h);
                *(s32 *)(iGpffffb3ac + off + 0xB5C) = 0;
            }
        }
    }
    base = iGpffffb3ac;
    if (*(s32 *)(base + 0xB58) != 0) {
        *(s32 *)(base + 0xB4C) |= 1;
    } else {
        h = *(s32 *)(base + 0xB54);
        if (h != 0) {
            mdlEffectDestroyWithNodes(h);
            *(s32 *)(iGpffffb3ac + 0xB54) = 0;
        }
    }
    return 1;
}

// FUN_001FA450
void btlCutinCreateStartPacket(void) {
    u8 *p = btlPacketAlloc(0xC02, 0);

    *(u8 *)(p + 0x47) &= 0xEE;
    *(void **)(p + 0x6C) = (void *)btlCutinPoll;
}

// FUN_001FA490
void btlCutinSetupName(u8 *arg0) {
    struct { s16 a; s16 b; } sp12;
    char sp20[0x10C];
    s32 temp_5;
    u16 temp_4;

    temp_5 = (calGetDayWindowFlags(datGetDateIndex()) & 1) != 0;
    temp_4 = *(u16 *)arg0;
    switch (temp_4) {
    case 1:
        sprintf(sp20, D_00625190, *(s16 *)(arg0 + 2), iGpffffa530[temp_5]);
        func_00440b68(iGpffffa528, D_00625090, 0x152);
        *(s32 *)(iGpffffb3ac + 0xB84) = (u32)H_Cdvd_AcquireDirectory((u8 *)sp20, 0);
        break;
    case 3:
        sprintf(sp20, D_006251C0, *(s16 *)(arg0 + 2), iGpffffa530[temp_5]);
        func_00440b68(iGpffffa528, D_00625090, 0x158);
        *(s32 *)(iGpffffb3ac + 0xB84) = (u32)H_Cdvd_AcquireDirectory((u8 *)sp20, 0);
        break;
    case 5:
        if (datGetFlag(0x38) != 0) {
            sp12.a = 5;
            if (calGetDayWindowFlags(datGetDateIndex()) & 1) {
                sp12.b = 0x1E;
            } else {
                sp12.b = 0x14;
            }
        } else {
            sp12.a = 8;
            sp12.b = 0x1E;
        }
        *(s32 *)(iGpffffb3ac + 0xB88) = cutinDrawTaskCreate(*(s32 *)(iGpffffb3ac + 0xDC8), *(s32 *)&sp12);
        break;
    }
    *(u16 *)(iGpffffb3ac + 0xB7C) = *(u16 *)arg0;
}
