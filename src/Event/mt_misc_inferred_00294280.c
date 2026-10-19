#include "mt_scene_internal.h"
#include "h_cdvd_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scene_event_internal.h"
#include "sdk_snd_internal.h"
typedef char *va_list;
#define va_start(ap, last) (ap = (va_list)__builtin_args_info(2))
#define va_end(ap) ((void)0)
extern u8 *iGpffffb510;
extern s32 iGpffffa7c8;

s32 mtMiscResourceValue(s32 arg0);


extern s32 iGpffffb538;
extern u8 D_00882ED0[];
extern u8 D_00882EF0[];
extern u8 D_00882EDE[];
extern u8 D_00882EFE[];
extern char D_0063CB30[];
extern char D_0063D050[];



extern s32 D_0063CB50[];
extern u8 D_0063CFA0[];
static inline u8 *code29AddOff(s32 offset, u8 *base) {
    return (u8 *)((u32)offset + (u32)base);
}
// lint: allow H011 -- measured: u16 prototype regresses func_00291a60 (145 diff, wide id args)
extern u32 yTimeTrackAppendKey(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                          s32 arg4, f32 farg0, s32 arg5, s32 arg6,
                          s32 arg7);
extern f32 fGpffff8204;
extern void mtMiscDrawSpriteAt(s32 arg0, f32 farg0, f32 farg1, f32 farg2,
                          f32 farg3, s32 arg1, s32 arg2);
extern char D_0063C8F0[];
extern char D_0063C910[];
extern s32 D_0076462C;
extern u8 iGpffffa7e8;

extern u8 *iGpffffb540;
extern u8 D_0063E810[];
extern u16 D_008C024E[];
extern s32 D_0063E830[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0029; members 00294280-00294280 */

extern void mtMiscCollectType1Records(u8 *arg0);
extern void mtMiscCollectType2Records(u8 *arg0);
/* measured probe: preserve local constant with opt_propagation off. */
/* measured probe: close opt_propagation bracket after func_00291530. */
/* measured: opt_propagation off keeps `weapon` materialised between the index
   shift and the base add (retail sll/andi/addu); with propagation on the CSE'd
   address is finished before any argument. The index/five locals must stay
   literal under this pragma or they take a sixth saved register. Attachment
   helpers retain block-scoped u16 parameters for per-call masks. */
/* measured: restore propagation for the rest of the unit. */
/* measured probe: preserve the retail type constant and close bracket below. */
/* measured probe: close opt_propagation bracket after func_00291810. */
/* measured: O1 float-local register mapping probe for func_00293710. */
/* measured: closes O1 float-local register mapping probe for func_00293710. */
/* 908/912 bytes; thirty resolved relocations and four zero alignment bytes.
 * Keep separate binary64 diagnostic lifetimes and reload resource links after
 * allocation. Keep binary64 arguments despite the retail format's %d fields. */
// Builds the scene's fixed event nodes: resource 0x400, one node per kind-3
// resource, and three icon nodes. Copies the kind-5 resource's transform and
// eight words into the record at +0x6F0 and +0x710.
// FUN_00294280
void mtMiscBuildSceneNodes(u8 *arg0)
{
    typedef struct Resrc Resrc;
    typedef struct ResrcManager ResrcManager;
    extern u32 MT_Scene_GetResManager(void);
    extern Resrc *MT_Scene_GetRes(u16 arg0);
    extern Resrc *resrcMngGetListHead(ResrcManager *arg0, u8 arg1);
    extern u32 resrcMngGetTotalResInList(u8 *arg0, u8 arg1);
    extern void *evtNodeAlloc(s32 arg0, s32 arg1);
    extern void evtNodeSetRes(s32 arg0, s32 arg1, s32 arg2);
    extern void *evtNodeAllocWithRes(s32 arg0, u8 *arg1, u16 arg2, s32 arg3);
    extern void evtNpcResourceHook(u8 *arg0);
    extern void func_00440b68(char *fmt, ...);
    extern f64 fptodp(f32 arg0);
    extern void *mdlGetColor(void *arg0);
    extern char D_0063CAC0[];
    extern char D_0063CAD0[];
    s32 temp_20_2;
    f64 diagnostic_x;
    f64 diagnostic_y;
    s32 temp_3;
    s32 temp_4;
    s32 var_16;
    u16 *temp_2_2;
    u8 *temp_2_4;
    u8 *temp_2_6;
    u8 *temp_2_7;
    u8 *var_7;
    u8 *var_6;
    s32 var_5;
    f64 first_x;
    f64 first_y;
    s32 temp_20;
    s32 temp_19;
    s32 temp_2;
    u8 *temp_2_2b;
    s32 temp_2_3;
    f32 value_0;
    f32 value_1;
    f32 value_2;
    f32 value_3;

    temp_2 = MT_Scene_GetResManager();
    if (temp_2 != 0) {
        temp_2_2 = (u16 *)MT_Scene_GetRes(0x400);
        if (temp_2_2 != NULL) {
            temp_2_3 = (s32)evtNodeAlloc(1, (s32)arg0);
            evtNodeSetRes(temp_2_3, 0x400, (s32)temp_2_2);
            ((MtMiscSceneNode *)temp_2_3)->unk_08 = -1;
            value_2 = *(f32 *)((u8 *)temp_2_2 + 4);
            value_1 = *(f32 *)((u8 *)temp_2_2 + 8);
            value_0 = *(f32 *)((u8 *)temp_2_2 + 0xC);
            ((MtMiscSceneNode *)temp_2_3)->unk_38.x = value_2;
            ((MtMiscSceneNode *)temp_2_3)->unk_38.y = value_1;
            ((MtMiscSceneNode *)temp_2_3)->unk_38.z = value_0;
            value_2 = *(f32 *)((u8 *)temp_2_2 + 0x10);
            value_1 = *(f32 *)((u8 *)temp_2_2 + 0x14);
            value_0 = *(f32 *)((u8 *)temp_2_2 + 0x18);
            ((MtMiscSceneNode *)temp_2_3)->unk_44.x = value_2;
            ((MtMiscSceneNode *)temp_2_3)->unk_44.y = value_1;
            ((MtMiscSceneNode *)temp_2_3)->unk_44.z = value_0;
            first_x = fptodp(*(f32 *)(temp_2_2 + 2));
            first_y = fptodp(*(f32 *)(temp_2_2 + 4));
            func_00440b68(D_0063CAC0, first_x, first_y,
                          fptodp(*(f32 *)(temp_2_2 + 6)));
            temp_2_4 = mdlGetColor(*(void **)((u8 *)temp_2_2 + 0x164));
            temp_3 = *(u8 *)(temp_2_4 + 0);
            temp_4 = *(u8 *)(temp_2_4 + 1);
            temp_20 = *(u8 *)(temp_2_4 + 2);
            temp_19 = *(u8 *)(temp_2_4 + 3);
            ((MtMiscSceneNode *)temp_2_3)->unk_50[0] = (u8)temp_3;
            ((MtMiscSceneNode *)temp_2_3)->unk_50[1] = (u8)temp_4;
            ((MtMiscSceneNode *)temp_2_3)->unk_50[2] = (u8)temp_20;
            ((MtMiscSceneNode *)temp_2_3)->unk_50[3] = (u8)temp_19;
        } else {
            evtNodeSetRes((s32)evtNodeAlloc(1, (s32)arg0), 0x400, 0);
        }
        temp_20 = resrcMngGetTotalResInList((u8 *)temp_2, 3);
        temp_2_2b = (u8 *)resrcMngGetListHead((ResrcManager *)temp_2, 3);
        func_00440b68(D_0063CAD0, temp_20);
        temp_19 = 0;
        goto loop_6_test;
loop_6_body:
        evtNpcResourceHook(temp_2_2b);
        temp_2_3 = (s32)evtNodeAllocWithRes(
            1, arg0, *(u16 *)temp_2_2b, (s32)temp_2_2b);
        ((MtMiscSceneNode *)temp_2_3)->unk_08 = -1;
        value_2 = *(f32 *)(temp_2_2b + 4);
        value_1 = *(f32 *)(temp_2_2b + 8);
        value_0 = *(f32 *)(temp_2_2b + 0xC);
        ((MtMiscSceneNode *)temp_2_3)->unk_38.x = value_2;
        ((MtMiscSceneNode *)temp_2_3)->unk_38.y = value_1;
        ((MtMiscSceneNode *)temp_2_3)->unk_38.z = value_0;
        value_2 = *(f32 *)(temp_2_2b + 0x10);
        value_1 = *(f32 *)(temp_2_2b + 0x14);
        value_0 = *(f32 *)(temp_2_2b + 0x18);
        ((MtMiscSceneNode *)temp_2_3)->unk_44.x = value_2;
        ((MtMiscSceneNode *)temp_2_3)->unk_44.y = value_1;
        ((MtMiscSceneNode *)temp_2_3)->unk_44.z = value_0;
        diagnostic_x = fptodp(*(f32 *)(temp_2_2b + 4));
        diagnostic_y = fptodp(*(f32 *)(temp_2_2b + 8));
        func_00440b68(D_0063CAC0, diagnostic_x, diagnostic_y,
                      fptodp(*(f32 *)(temp_2_2b + 0xC)));
        temp_2_6 = mdlGetColor(*(void **)(temp_2_2b + 0x164));
        temp_3 = *(u8 *)(temp_2_6 + 0);
        temp_4 = *(u8 *)(temp_2_6 + 1);
        var_16 = *(u8 *)(temp_2_6 + 2);
        temp_20_2 = *(u8 *)(temp_2_6 + 3);
        ((MtMiscSceneNode *)temp_2_3)->unk_50[0] = (u8)temp_3;
        ((MtMiscSceneNode *)temp_2_3)->unk_50[1] = (u8)temp_4;
        ((MtMiscSceneNode *)temp_2_3)->unk_50[2] = (u8)var_16;
        ((MtMiscSceneNode *)temp_2_3)->unk_50[3] = (u8)temp_20_2;
        temp_19++;
        temp_2_2b = *(u8 **)(temp_2_2b + 0x138);
loop_6_test:
        if (temp_19 < temp_20)
            goto loop_6_body;
        temp_2_3 = 0;
        goto loop_9_test;
loop_9_body:
        temp_2_7 = evtNodeAlloc(1, (s32)arg0);
        temp_4 = temp_2_3 + 0x384;
        temp_4 = (temp_4 & 0x3FF) | 0xC00;
        evtNodeSetRes((s32)temp_2_7, temp_4 & 0xFFFF, 0);
        temp_2_3++;
loop_9_test:
        if (temp_2_3 < 3)
            goto loop_9_body;
        temp_2_7 = (u8 *)resrcMngGetListHead((ResrcManager *)temp_2, 5);
        if (temp_2_7 != NULL) {
            value_0 = *(f32 *)(temp_2_7 + 0x140);
            value_1 = *(f32 *)(temp_2_7 + 0x144);
            value_2 = *(f32 *)(temp_2_7 + 0x148);
            value_3 = *(f32 *)(temp_2_7 + 0x14C);
            *(f32 *)(arg0 + 0x6F0) = value_0;
            *(f32 *)(arg0 + 0x6F4) = value_1;
            *(f32 *)(arg0 + 0x6F8) = value_2;
            *(f32 *)(arg0 + 0x6FC) = value_3;
            value_0 = *(f32 *)(temp_2_7 + 0x150);
            value_1 = *(f32 *)(temp_2_7 + 0x154);
            value_2 = *(f32 *)(temp_2_7 + 0x158);
            value_3 = *(f32 *)(temp_2_7 + 0x15C);
            *(f32 *)(arg0 + 0x700) = value_0;
            *(f32 *)(arg0 + 0x704) = value_1;
            *(f32 *)(arg0 + 0x708) = value_2;
            *(f32 *)(arg0 + 0x70C) = value_3;
            var_7 = temp_2_7 + 0x160;
            var_6 = arg0 + 0x710;
            var_5 = 8;
loop_9_copy:
            temp_4 = *(s32 *)var_7;
            temp_3 = *(s32 *)(var_7 + 4);
            var_7 += 8;
            var_5--;
            *(s32 *)var_6 = temp_4;
            *(s32 *)(var_6 + 4) = temp_3;
            var_6 += 8;
            if (var_5 > 0)
                goto loop_9_copy;
        }
    }
}

