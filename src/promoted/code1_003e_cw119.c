#include "include_asm.h"
#include "type.h"

/* RenderWare-derived functions verified with MWCCPS2 3.0.1 b119 (see
   config/compiler_units.txt and docs/matching.md). Fallbacks stay under
   asm/nonmatchings/code1_003e. */

extern s32 (*DAT_0088737c_abs[])(void);
extern s32 func_003ec480(s32 arg0);

/* `movz $s0,$zero,$v0` is the b119 lowering of `call() ? arg0 : 0`. */
// FUN_003E82A0
#pragma schedule on
u8 *func_003e82a0(u8 *arg0) {
    return DAT_0088737c_abs[0]() ? arg0 : NULL;
}
// FUN_003E82E0
u8 *func_003e82e0(u8 *arg0) {
    return func_003ec480(*(s32 *)(arg0 + 0x60)) ? arg0 : NULL;
}
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off

/* The alignment nop after the filled back-edge slot is the unit's -O2,p; the
   b210 residual (nd 16) is gone under b119. */
// FUN_003E3070
#pragma schedule on
s32 func_003e3070(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *node;

    node = *(u8 **)(arg0 + 0x10);
    if (node != NULL) {
    loop:
        if (*(s32 *)(node + 8) != arg1) {
            node = *(u8 **)(node + 0x30);
            if (node == NULL) {
            } else {
                goto loop;
            }
        }
    }
    if (node != NULL) {
        *(s32 *)(node + 0x18) = arg2;
        return *(s32 *)(node + 0);
    }
    return -1;
}
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off

extern s32 D_008866D8;
extern s32 D_0088731C;
extern s32 D_00886700;
extern s32 D_00887330;
extern s32 iGpffffb7b8;
extern u8 D_008872E0[];
extern u8 D_008871C0[];
extern s32 iGpffffab50;
extern s32 iGpffffb768;
extern u8 *iGpffffb778;
extern s32 D_00724870;
extern s32 (*D_008873D4[])(char *arg0);
extern u8 D_00887250[];
extern s32 D_00763C68;
extern s32 D_00763C6C;
extern s32 D_00764874;
extern s32 D_00764878;
extern s32 D_0076487C;
extern s32 D_00764884;
extern s32 D_00764888;
extern s32 D_00764890;
extern s32 D_00764898;
extern s32 D_0076489C;
extern s32 D_00763C54;
extern s32 D_00763C58;
extern s32 D_00763C70;
extern s32 D_00763C74;
extern s32 D_00764860;
extern s32 D_007648A0;
extern s32 D_007648A4;
extern s32 D_0070B800[];
extern u8 D_00887220[];
extern u8 D_00887280[];
extern s32 (*D_0088732C[])(s32, s32, s32);
extern s32 (*D_00887350[])(s32, s32, s32);
extern s32 (*D_0088737C)(void);
extern u8 D_008872F0[];
extern s32 func_003e87f0();
extern s32 func_003df590(s32 arg0, ...);
extern u8 D_0070B730[];
extern s32 func_003ec480();
extern u8 *func_003df9f0(u8 *arg0, u8 *arg1);
extern s32 func_003e1030(s32 arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4, s32 arg5);
extern s32 func_003e3830(u8 *arg0, s32 arg1);
extern u8 D_0070B760[];
extern u8 D_0070B710[];
extern u8 D_0070B7A0[];
extern s32 iGpffffb76c;
extern s32 iGpffffb7c0;
extern s32 iGpffffb7c4;
extern s32 iGpffffb7a4;
extern s32 iGpffffb780;
extern s32 iGpffffb7a0;
extern s32 iGpffffb770;
extern s32 iGpffffb77C;
extern s32 iGpffffb78C;
extern s32 iGpffffb788;
extern s32 D_008871F0;
extern u8 D_008873F0[];
extern s32 func_003ddf20(void *arg0);
extern s32 func_003e3370(u8 *arg0, s32 arg1);
extern s32 func_003e2ab0(u8 *arg0, u8 *arg1, s32 arg2);
extern u8 D_008873A4[];
extern u8 D_008873A8[];
extern u8 D_008873AC[];
extern u8 D_008873B0[];
extern u8 D_008873B4[];
extern u8 D_008873B8[];
extern u8 D_008873BC[];
extern u8 D_008873C0[];
extern u8 D_008873C4[];
extern u8 D_008873C8[];
extern u8 D_008873CC[];
extern u8 D_008873D0[];
extern s32 (*D_008873D4[])(char *arg0);
extern u8 D_008873D8[];
extern u8 D_008873DC[];
extern u8 D_008873E0[];
extern u8 D_008873E4[];
extern u8 D_008873F4[];
extern s32 iGpffffb780;
typedef s32 M2C_UNK;
typedef s32 M2C_UNK32;
typedef u8 *(*Fn3f80A)(u8 *, u8 *, u8 *);
typedef u8 *(*Fn3f80B)(u8 *, s32, u8 *);
typedef u8 *(*Callback66c0)(u8 *, u8 *);
extern s32 (*D_0088738C[])(s32 *, Callback66c0, s32);
typedef u8 *(*Callback6770)(u8 *, u8 *);
extern s32 (*D_0088738C[])(s32 *, Callback6770, s32);
extern s32 (*D_00887394[])(s32, Callback6770, u32);
extern s32 func_003deff0(s32, s32, s32, s32, s32);
extern u8 *func_003e33f0(u8 *, s32, Callback6770);
/* The archived nd 18 residual (b210) is gone under b119. */
// FUN_003E3830
#pragma schedule on
s32 func_003e3830(u8 *arg0, s32 arg1) {
    u8 *node;
    node = *(u8 **)(arg0 + 0x10);
    if (node != NULL) {
    loop:
        if (*(s32 *)(node + 8) == arg1) {
            return *(s32 *)(node + 0);
        }
        node = *(u8 **)(node + 0x30);
        if (node == NULL) {
            goto done;
        }
        goto loop;
    }
done:
    return -1;
}
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off


/* The archived b210 residual is gone under b119. */
// FUN_003E3020
#pragma schedule on
s32 func_003e3020(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 *node;

    node = *(u8 **)(arg0 + 0x10);
    if (node != NULL) {
    loop:
        if (*(s32 *)(node + 8) != arg1) {
            node = *(u8 **)(node + 0x30);
            if (node == NULL) {
            } else {
                goto loop;
            }
        }
    }
    if (node != NULL) {
        *(s32 *)(node + 0x0c) = arg2;
        *(s32 *)(node + 0x10) = arg3;
        *(s32 *)(node + 0x14) = arg4;
        return *(s32 *)(node + 0);
    }
    return -1;
}
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off

typedef void (*Callback003e)(u8 *, u8 *, u8 *);
typedef struct {
    void *next;
    void *prev;
    s32 size;
    void *owner;
    void *dtor;
    void *cb;
} Node2430003e;
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 count;
    s32 unkC;
    void *head_next;
    void *head_prev;
    void *tail_next;
    void *tail_prev;
} Ctx2430003e;
/* Archived b210 near-miss (Y3EA_003e3370); exact under b119 with schedule on. */
// FUN_003E3370
#pragma schedule on
s32 func_003e3370(u8 *arg0, s32 arg1) {
    s32 (*callback)(s32, s32, s32);
    s32 callback_result;
    s32 total;
    u8 *node;

    node = *(u8 **)(arg0 + 0x10);
    total = 0;
    if (node != NULL) {
        do {
            callback = *(s32 (**)(s32, s32, s32))(node + 0x14);
            if (callback != NULL) {
                callback_result = callback(arg1, *(s32 *)(node + 0), *(s32 *)(node + 4));
                if (callback_result > 0) {
                    total += callback_result + 0xC;
                }
            }
            node = *(u8 **)(node + 0x30);
        } while (node != NULL);
    }
    return total;
}
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off

extern void *D_00887408[];
extern void *D_00764864;
extern void *D_00764868;
extern void func_003df4d0(void *arg0);
extern void func_0043ece8(s32 arg0);
extern void func_00441558(u8 *arg0, u8 *arg1);
extern void func_0043c710(s32 arg0, s32 arg1);
extern void func_003e3870(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern void func_003ef3a0(void);
extern void func_003df8c0(u8 *, u8 *, u8 *);
extern void func_003e6db0();
extern void func_003e9680(void *arg0);
extern void (*jtbl_008873EC[])(u8 *arg0);
extern void *(*jtbl_008873E8[])(void *arg0, s32 arg1);
extern void (*jtbl_008873FC[])(u8 *arg0, u8 *arg1);
extern void func_003efda0(u8 *arg0);
extern void func_0043ed08(s32 arg0);
extern void func_003e4520(void *arg0, s32 arg1);
extern void func_003e4960();
extern void func_003e4920();
extern void func_003e47c0();
extern void func_00442088();
extern void func_00446ed8();
extern void func_00442830();
extern void func_00442de8();
extern void func_00442428();
extern void func_00442a80();
extern void func_00443010();
extern void func_004426e8();
extern void func_00442c30();
extern void func_00442948();
extern void func_00443f18();
extern void func_00442100();
/* Archived b210 near-miss (P3E3_003e3c20); exact under b119 with schedule on. */
// FUN_003E3C20
#pragma schedule on
u8 *func_003e3c20(u8 *arg0, s32 arg1) {
    u8 *node = *(u8 **)(arg0 + 0x14);
    if (node) {
        do {
            ((void (*)(s32, s32, s32))(*(s32 *)(node + 0x24)))(
                arg1, *(s32 *)(node + 0), *(s32 *)(node + 4));
            node = *(u8 **)(node + 0x34);
        } while (node);
    }
    return arg0;
}
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off
