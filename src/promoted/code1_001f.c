#include "btl_camera_palette_internal.h"
#include "btl_skill_target_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "rw/plcore/barenderstate.h"
#include "btl_skill_internal.h"
#include "sdk_snd_internal.h"
#include "btl_target_state_packet_internal.h"
/* Force the offset operand into the first addu slot. */
static inline u32 addOffsetFirst(u32 offset, u32 base) {
    return offset + base;
}

/* Force the base operand into the first addu slot. */
static inline u32 addBaseFirst(u32 base, u32 offset) {
    return base + offset;
}
static inline s32 promoteS16(s16 value) {
    return value;
}
static inline u32 addOffsetAfterBase(u32 base, u32 offset) {
    return offset + base;
}

extern RwRenderState D_00625210[];
typedef s32 (*BattleRenderStateFunction)(RwRenderState state, void *value);
extern BattleRenderStateFunction D_00887300[];
extern BattleRenderStateFunction D_00887304[];
extern void func_001fb480(f32 scale, u8 *arg0, s32 arg1, s32 arg2, u8 *arg3);
extern u16 D_0076455C;
extern u16 D_0076455A;
extern f32 D_007613E0;
extern f32 D_007613E4;
extern f32 D_008872FC_abs[];
extern void func_00122640(s32 arg0, s32 arg1);
extern s32 func_00122720(void);
extern void func_00204690(u8 *unused, f32 scaleX, f32 scaleY, f32 depth, s32 color);
extern void func_003e8110(s32 arg0);
extern s32 func_003e8120(s32 arg0);
extern s32 func_003f6440(s32 command, void *value);
extern s32 func_00457120(void);
extern void func_0045c870(u8 *arg0, s32 arg1);
extern void func_00489f80(void);
extern void func_0048a000(void);
extern u32 func_00232710(s32 arg0, u32 arg1);
extern s32 func_002326e0(s32 arg0);
extern s32 func_00243ce0(s32 arg0);
extern u8 *iGpffffb3c4;
extern s32 func_00231ed0(u8 *arg0);
extern s32 func_00231ee0(u8 *arg0);
extern s32 func_00231f80(u8 *arg0);
extern u16 func_00232290(u8 *arg0);
extern s32 func_002326c0(u8 *arg0);
extern u32 func_002428f0(s32 unit, s32 hpDelta);
extern s32 func_00106330(s32 arg0);
extern s32 func_0010f420(s32 arg0, s32 arg1);
extern u8 *iGpffffb3d0;
extern u8 *iGpffffb3e0;

extern s32 func_001f56d0(s32 arg0, u16 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_001f62b0();
extern void func_001f58d0();
extern void (*jtbl_008873EC[])(void *ptr);
extern s32 (*D_00624FF0[])(u8 *arg0, s32 arg1, s32 arg2);
extern s32 func_0045af90(s32 arg0);

extern void memset(void *destination, s32 value, u32 size);

extern s32 func_001ef720(s32 arg0, s32 arg1);
extern s32 func_001ef5f0(s32 arg0, s32 arg1, s32 arg2);

extern u32 func_00231d70();
extern s32 func_00243950(s32 arg0);
extern s32 func_002439c0(s32 arg0);
extern u16 func_00243a30(u8 *arg0, s32 *arg1);
extern void func_0046d730(void *arg0, s32 arg1);
extern u8 D_0060AB08[];
extern s32 func_002340c0(u8 *unit, s32 flags);
extern void func_0045a3e0(s32 arg0, s32 arg1);
extern s16 func_001060b0(void);
extern s32 func_00110d60(s32 arg0);
extern u8 D_0060AC00[];
extern u8 D_00618AC0[];
extern u8 D_0061F000[];

extern u8 *iGpffffb3ac;
extern u8 *iGpffffb3b8;
extern u8 *iGpffffb414;
extern s32 iGpffffb460;
extern u8 *D_0076449C;
extern u16 D_00624FC0[];
extern u16 D_00624FD8[];
extern s32 func_001f65d0(u8 *arg0);
extern u8 D_00624B20[];
extern u8 D_00624B22[];
extern s32 func_001ef9a0(void);
extern void func_0045a9a0(s32 arg0, s32 arg1);
extern s32 func_00459880(void);

extern void func_00454bd0(u8 *arg0);
extern void func_00235020(s32 arg0);
extern void func_0045aac0(s32 arg0, s32 arg1, s32 arg2);
extern void func_002bd3c0(void);

extern s32 func_0045ae10(s32 arg0, s32 arg1, s32 arg2);
extern void func_002bd3e0(void);
extern void func_002bd410(void);
extern void func_0043f9c8(void *arg0, s32 arg1, s32 arg2);
extern s32 func_0022bad0(u8 *arg0, s16 arg1);
extern s32 func_0022bc80(s32 arg0);
extern s32 func_001fa7a0(s32 *arg0);
extern s32 func_001fa940(void);
extern s32 func_001faa00(void);
extern s32 func_0022bd00(void);
extern s32 func_00120ee0(s32 arg0);
extern s32 func_004553c0(u8 *arg0);
extern s32 func_00484bb0(s32 arg0, u8 *arg1);
extern void func_00243e70(s32 arg0);
extern void func_00231f20(s32 arg0, s32 arg1);
extern void func_002326f0(s32 arg0, s32 arg1);
extern void func_00232680(s32 arg0, s32 arg1);

extern void func_00485b20(s32 arg0);
extern void func_00486180(s32 arg0);
extern void func_00120f20(s32 arg0);
extern s32 func_00122520(s32 arg0, s32 arg1);
extern void func_001228a0(s32 arg0, s32 arg1, s32 arg2);
extern void func_0043f810(void *arg0, void *arg1, u32 arg2);
extern void func_001fa490(void);
extern s32 func_001fa660(void);
extern u8 iGpffffb468;
extern u8 iGpffffb469;
extern s16 iGpffffb46e;
extern u8 D_006251F0[];
extern s32 func_00452380(void *arg0);

extern s32 func_001fbb50(u8 *arg0);


extern void func_001f38e0(u8 **arg0);
extern u16 func_00109360(u16 arg0);
extern u16 *func_0010a900(u16 character);
extern s32 func_0010ce10(u8 *persona, u32 skill);
extern s32 func_001f3900(u8 **arg0);
extern void func_001f3930(void);
extern u8 *func_00194470(s32 type, s32 workSize);

extern void func_001f39b0(u8 **arg0);

extern s32 func_001f39d0(u8 **arg0);
extern void func_001f3b00(void);

extern s32 func_001f8380(u8 **arg0);
extern s32 func_00106600(s16 arg0);
extern void func_00106620(s32 arg0, u32 arg1);
extern s32 func_002325a0(s32 arg0, s32 arg1);
extern s32 func_00232610(s32 arg0, s32 arg1);
extern u32 func_0023d9b0(u8 *arg0, s32 arg1);

extern s32 func_001f8400(u8 **arg0);
extern s32 iGpffffb464;
extern void func_0044ea90(const void *file, s32 line);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void func_00442088(void *dst, void *fmt, ...);
extern s32 func_00456250(s32 arg0, void *arg1, s32 arg2, void *arg3);
extern s32 func_004c7ef8(s32 arg0);
extern u8 D_00624F50[];
extern u8 D_00624F60[];
extern u8 D_00624F80[];
extern u8 D_00624FA0[];

// FUN_001F01A0
s32 func_001f01a0(u8 *arg0, u8 *arg1)
{
    u16 temp_2;

    temp_2 = *(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4);
    switch (temp_2) {
    case 2:
        return 0x104;
    case 3:
        if ((arg1 != NULL) &&
            (func_00243ce0(*(s32 *)(*(u8 **)(arg1 + 0x30) + 0xA64)) != 0)) {
            return 0x10A;
        }
        return 0x105;
    case 4:
        return 0x106;
    case 6:
        return 0x107;
    case 7:
        return 0x109;
    case 8:
        return 0x108;
    default:
        return 0;
    }
}
// FUN_001F0260
s64 func_001f0260(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 0xDA:
    case 0xDB:
        return 0x40;
    case 0xDC:
    case 0xDD:
        return 0x42;
    case 0xDE:
    case 0xDF:
        return 0x44;
    case 0xE0:
        return 0x60;
    case 0xD3:
    case 0xD4:
        return 0x5A;
    case 0xD5:
    case 0xD6:
        return 0x5C;
    case 0xD7:
    case 0xD8:
        return 0x5E;
    case 0xD9:
        return 0x62;
    case 0xEA:
        return 0x4A;
    case 0xEB:
        return 0x4C;
    case 0xE3:
        return 0x64;
    case 0xE4:
        return 0x66;
    case 0x63:
    case 0x64:
        return 0x4E;
    case 0xEC:
        return 0x6A;
    case 0xED:
        return 0x6C;
    case 0xEE:
        return 0x70;
    case 0xEF:
        return 0x6E;
    case 0x103:
        return 0x72;
    case 0xE7:
        return 0x74;
    case 0xE8:
        return 0x76;
    case 0xF0:
        return 0x7A;
    case 0xF1:
        return 0x7C;
    case 0xF2:
        return 0x7E;
    case 0xF3:
        return 0x80;
    case 0xE1:
        return 0x46;
    case 0xE2:
        return 0x48;
    case 0x169:
        return 0xA5;
    case 0x17F:
        return 0xB0;
    case 0x180:
        return 0xB1;
    case 0x165:
        return 0xA3;
    case 0x16B:
        return 0xA6;
    case 0x17A:
        return 0xAE;
    case 0x178:
        return 0xA8;
    case 0x186:
        return 0xB5;
    case 0x181:
        return 0xB7;
    default:
        return 0;
    }
}



#pragma push
#pragma opt_rebuildconditionals off
// FUN_001F0620
s32 func_001f0620(u8 *arg0, s64 arg1)
{
    s32 temp_3_2;
    s64 temp_2;
    u16 temp_6;
    u8 *temp_3;
    u8 *temp_5;

    temp_6 = *(u16 *)(*(u8 **)(iGpffffb3ac + 0xC68) + 8);
    if ((temp_6 == 0x215) && ((s16)arg1 != 2)) {
        return 0;
    }
    temp_2 = (s16)arg1;
    switch (temp_2) {
    case 1:
        return 1;
    case 2:
        return !func_00232710(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64), 8);
    case 3:
        return !func_00106330(0x1438);
    case 4:
        temp_3 = *(u8 **)(arg0 + 0x30);
        if (temp_3[0xA2] != 0) return 0;
        if (*(u16 *)(temp_3 + 0xA4) != 1) return 0;
        if ((func_001ef720(1, 0) & 0xFFFF) < 2) return 0;
        return !func_00106330(0x1438);
    case 5:
        temp_5 = *(u8 **)(arg0 + 0x30);
        if (temp_5[0xA2] != 0) return 0;
        if (*(u16 *)(temp_5 + 0xA4) != 1) return 0;
        if ((*(u16 *)(arg0 + 0x18) & 0x400) == 0) return 0;
        if (func_00232710(*(s32 *)(temp_5 + 0xA64), 8) != 0) return 0;
        return !func_00106330(0x1438);
    case 6:
        temp_3_2 = *(s32 *)(iGpffffb414 + ((temp_6 & 0xFFFF) * 0x18));
        if (temp_3_2 & 0x20) return 0;
        if ((temp_3_2 & 1) == 0) return 0;
        return !func_001f5ea0(0);
    case 7:
    case 8:
    case 11:
    case 12:
        return 1;
    case 10:
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) return 0;
        return !func_00106330(0x1438);
    case 13:
        return 1;
    default:
        return 0;
    }
}
#pragma opt_rebuildconditionals on
#pragma pop
// FUN_001F08C0
s32 func_001f08c0(u8 *arg0)
{
    u16 temp_2;

    temp_2 = *(u16 *)(arg0 + 0xA4);
    switch (temp_2) {
    case 1:
        return 1;
    case 2:
        return 1;
    case 3:
        return 0;
    case 4:
        return 0;
    case 6:
        return 0;
    case 7:
        return 1;
    case 8:
        return 1;
    default:
        return 0;
    }
}
// FUN_001F0950
s32 func_001f0950(s32 arg0, s32 arg1)
{
    if (((*(u16 *)(iGpffffb3c4 + ((arg0 & 0xFFFF) * 0x3C)) & 0x4004) == 0) &&
        (func_00106330(0x1403) != 0)) {
        if (func_00106330(0x1408) != 0) {
            return 1;
        }
        if (func_00106330(0x1409) != 0) {
            return 0;
        }
    }
    return func_0010f420(arg0, arg1);
}
// FUN_001F0A10
void func_001f0a10(u8 *arg0) {
    memset(arg0, 0, 0x20);
}



// FUN_001F0A50
s32 func_001f0a50(u8 *arg0)
{
    s32 i;
    s32 j;
    s32 n;
    s32 innerCount;
    u8 *target;

    i = 0;
    n = *(u16 *)(arg0 + 0x6A);
    goto outer_test;
outer:
    target = *(u8 **)(arg0 + ((u16)i * 4) + 0x38);
    j = 0;
    innerCount = *(u8 *)(target + 0xD9);
    goto inner_test;
inner:
    if ((*(u16 *)(target + ((u16)j << 5) + 0x10E) & 4) != 0) {
        return 1;
    }
    j = (j + 1) & 0xFFFF;
inner_test:
    if ((j & 0xFFFF) < innerCount) {
        goto inner;
    }
    i = (i + 1) & 0xFFFF;
outer_test:
    if ((i & 0xFFFF) < n) {
        goto outer;
    }
    return 0;
}
/* measured: invariant mask materialisation needs opt_loop_invariants on to
   place the retail `lui` in the preheader. */
#pragma opt_loop_invariants on
// FUN_001F0AF0
s32 func_001f0af0(u8 *arg0)
{
    s32 i;
    s32 j;
    s32 n;
    s32 innerCount;
    s32 mask;
    u8 *target;

    i = 0;
    n = *(u16 *)(arg0 + 0x6A);
    mask = 0x100000;
    goto outer_test;
outer:
    target = *(u8 **)(arg0 + ((u16)i * 4) + 0x38);
    j = 0;
    innerCount = *(u8 *)(target + 0xD9);
    goto inner_test;
inner:
    if ((*(s32 *)(target + ((u16)j << 5) + 0xF8) & mask) != 0) {
        return 1;
    }
    j = (j + 1) & 0xFFFF;
inner_test:
    if ((j & 0xFFFF) < innerCount) {
        goto inner;
    }
    i = (i + 1) & 0xFFFF;
outer_test:
    if ((i & 0xFFFF) < n) {
        goto outer;
    }
    return 0;
}
/* measured: closes the invariant-hoist bracket for func_001f0af0. */
#pragma opt_loop_invariants off
// FUN_001F0B90
/* The two 0xFFFF masks are spelled differently on purpose: retail re-masks
   the counter separately for the index and for the loop bound, and writing
   both as `i & 0xFFFF` lets b210 common-subexpression them into one andi
   (nd 57, one word short). */
s32 func_001f0b90(u8 *arg0) {
    s32 i;
    s32 n;

    i = 0;
    n = *(u16 *)(arg0 + 0x6A);
    goto test;
loop:
    if (*(s32 *)(*(u8 **)(arg0 + ((u16)i * 4) + 0x38) + 0xE4) != 0) {
        return 1;
    }
    i = (i + 1) & 0xFFFF;
test:
    if ((i & 0xFFFF) < n) {
        goto loop;
    }
    return 0;
}

// FUN_001F0BF0
/* Mask spelling as in func_001f0b90: `(u16)i` for the index and
   `i & 0xFFFF` for the bound, so b210 does not fold retail's two andi
   instructions into one. */
s32 func_001f0bf0(u8 *arg0) {
    s32 i;
    s32 n;

    i = 0;
    n = *(u16 *)(arg0 + 0x6A);
    goto test;
loop:
    if ((*(u16 *)(*(u8 **)(arg0 + ((u16)i * 4) + 0x38) + 0xDE) & 6) != 0) {
        return 1;
    }
    i = (i + 1) & 0xFFFF;
test:
    if ((i & 0xFFFF) < n) {
        goto loop;
    }
    return 0;
}

/* measured: loop-invariant probe for func_001f0c50's shared true value. */
#pragma opt_loop_invariants on
// FUN_001F0C50
s32 func_001f0c50(u8 *arg0)
{
    s32 result;
    s32 i;
    s32 n;
    u8 *target;
    s32 j;
    s32 innerCount;
    s32 one;

    result = 0;
    i = 0;
    n = *(u16 *)(arg0 + 0x6A);
    one = 0x10000 >> 16;
    while ((i & 0xFFFF) < n) {
        target = *(u8 **)(arg0 + ((u16)i << 2) + 0x38);
        if (target != arg0) {
            if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) !=
                *(u8 *)(*(u8 **)(target + 0x30) + 0xA2)) {
                return 0;
            }
            if (result == 0) {
                j = 0;
                innerCount = *(u8 *)(target + 0xD9);
                while ((j & 0xFFFF) < innerCount) {
                    if (*(s32 *)(target + ((u16)j << 5) + 0xF0) > 0) {
                        result = one;
                    }
                    if (*(s32 *)(target + ((u16)j << 5) + 0xF4) > 0) {
                        result = one;
                    }
                    if (*(s32 *)(target + ((u16)j << 5) + 0xFC) != 0) {
                        result = one;
                    }
                    j = (j + 1) & 0xFFFF;
                }
            }
        }
        i = (i + 1) & 0xFFFF;
    }
    return result;
}
/* measured: close opt_loop_invariants after func_001f0c50 probe. */
#pragma opt_loop_invariants off
/* measured: invariant mask materialisation needs opt_loop_invariants on to
   place the retail `lui` in the preheader. */
#pragma opt_loop_invariants on
// FUN_001F0D30
s32 func_001f0d30(u8 *arg0)
{
    s32 i;
    s32 j;
    s32 n;
    s32 innerCount;
    s32 mask;
    u8 *target;

    i = 0;
    n = *(u16 *)(arg0 + 0x6A);
    mask = 0x80000;
    goto outer_test;
outer:
    target = *(u8 **)(arg0 + ((u16)i * 4) + 0x38);
    j = 0;
    innerCount = *(u8 *)(target + 0xD9);
    goto inner_test;
inner:
    if ((*(s32 *)(target + ((u16)j << 5) + 0xFC) & mask) != 0) {
        return 1;
    }
    j = (j + 1) & 0xFFFF;
inner_test:
    if ((j & 0xFFFF) < innerCount) {
        goto inner;
    }
    i = (i + 1) & 0xFFFF;
outer_test:
    if ((i & 0xFFFF) < n) {
        goto outer;
    }
    return 0;
}
/* measured: closes the invariant-hoist bracket for func_001f0d30. */
#pragma opt_loop_invariants off
/* measured: opt_loop_invariants on preserves the nonzero-path constant and loop preheaders for func_001f0dd0. */
#pragma opt_loop_invariants on
// FUN_001F0DD0
s32 func_001f0dd0(u8 *arg0, s32 arg1)
{
    s32 result;
    s32 one;
    s32 i_one;
    s32 j_one;
    s32 n;
    u8 *target;
    s32 innerCount;
    u8 *entry;
    s32 i_zero;
    s32 j_zero;

    result = 0;
    if (arg1 == 0) {
        goto path_zero;
    }
i_one = 0;
n = *(u16 *)(arg0 + 0x6A);
one = 1;
while ((i_one & 0xFFFF) < n) {
    target = *(u8 **)(arg0 + ((u16)i_one * 4) + 0x38);
    if (*(s32 *)(target + 0xE4) != 0) {
        result = 0;
        goto done;
    }
    if ((*(u16 *)(target + 0xDC) & 0x500) != 0) {
        result = 0;
        goto done;
    }
    if (result == 0) {
        innerCount = *(u8 *)(target + 0xD9);
        j_one = 0;
        goto inner_test_one;
inner_one:
        if (*(s32 *)(target + ((u16)j_one << 5) + 0xF0) < 0) {
            result = one;
            goto outer_step_one;
        }
        j_one = (j_one + 1) & 0xFFFF;
inner_test_one:
        if ((j_one & 0xFFFF) < innerCount) {
            goto inner_one;
        }
    }
outer_step_one:
    i_one = (i_one + 1) & 0xFFFF;
}
goto done;

path_zero:
    i_zero = 0;
    n = *(u16 *)(arg0 + 0x6A);
    goto outer_test_zero;
outer_zero:
    target = *(u8 **)(arg0 + ((u16)i_zero * 4) + 0x38);
    if ((*(u16 *)(target + 0xDC) & 0x106) != 0) {
        result = 1;
        goto done;
    }
    innerCount = *(u8 *)(target + 0xD9);
    j_zero = 0;
    goto inner_test_zero;
inner_zero:
    entry = target + ((u16)j_zero << 5);
    if (*(s32 *)(entry + 0xF0) == 0) {
        if (*(s32 *)(entry + 0xF8) != 0) {
            result = 1;
            goto done;
        }
    } else if (*(s32 *)(entry + 0xF0) < 0) {
        result = 1;
        goto done;
    }
    j_zero = (j_zero + 1) & 0xFFFF;
inner_test_zero:
    if ((j_zero & 0xFFFF) < innerCount) {
        goto inner_zero;
    }
    i_zero = (i_zero + 1) & 0xFFFF;
outer_test_zero:
    if ((i_zero & 0xFFFF) < n) {
        goto outer_zero;
    }
done:
    return result;
}
/* measured: close opt_loop_invariants after func_001f0dd0. */
#pragma opt_loop_invariants off
// FUN_001F0F70
u32 func_001f0f70(u8 *arg0)
{
    u8 *target;
    s32 targetCount;
    s32 targetIndex;

    targetIndex = 0;
    targetCount = *(u16 *)(arg0 + 0x6A);
    for (; (u16)targetIndex < targetCount;
         targetIndex = (u16)(targetIndex + 1))
    {
        target = *(u8 **)(arg0 + 0x38 + (u32)(u16)targetIndex * 4);
        if (*(s32 *)(target + 0xE4) != 0) {
            return 1;
        }
        if ((*(u16 *)(target + 0xDC) & 0x500) != 0) {
            return 1;
        }
    }
    return 0;
}

/* measured: compiler residual in call argument materialization. Committed at nd 3. */
/* measured: optimization_level 1 probe for func_001f0ff0 call materialization. */
#pragma optimization_level 1
// FUN_001F0FF0
s32 func_001f0ff0(u32 arg0)
{
    s32 index;
    index = *(u16 *)(arg0 + 0x6E);
    return (func_001d7f10((u8 *)arg0, 0, index, 0) & 0xFFFF) == 0;
}
/* measured: close optimization_level 1 probe for func_001f0ff0. */
#pragma optimization_level 2
/* measured: opt_loop_invariants on preserves target loop preheaders and state materialisation. */
#pragma opt_loop_invariants on
// FUN_001F1030
s32 func_001f1030(u8 *arg0)
{
    u8 *value;
    s32 i;
    s32 j;
    u16 count;
    u8 state;
    u8 *base;
    u8 *unit;
    u8 *pointer;

    base = *(u8 **)(arg0 + 0x30);
    state = *(u8 *)(base + 0xA2);
    if ((*(u16 *)(arg0 + 0x1A) & 1) != 0) {
        pointer = *(u8 **)(base + 0xA64);
        if (pointer != NULL && func_00232710((s32)pointer, 0x100) != 0) {
            if ((state & 0xFF) == 0) {
                value = (u8 *)1;
            } else {
                value = NULL;
            }
            state = (u32)value & 0xFF;
        }
    }
    count = *(u16 *)(arg0 + 0x6A);
    if ((s32)count < 2) {
        if (count != 1) {
            goto single_done;
        }
        unit = *(u8 **)(arg0 + 0x38);
        if ((*(u16 *)(unit + 0x1A) & 1) == 0) {
            return 0;
        }
        base = *(u8 **)(unit + 0x30);
        if (*(u8 *)(base + 0xA2) != (state & 0xFF)) {
            return 0;
        }
        i = 0;
        goto single_test;
    single_loop:
        if ((*(u16 *)(unit + ((u16)i << 5) + 0x10E) & 0x20) != 0) {
            return 1;
        }
        i = (i + 1) & 0xFFFF;
    single_test:
        if ((i & 0xFFFF) < *(u8 *)(unit + 0xD9)) {
            goto single_loop;
        }
    single_done:
        return 0;
    }

    j = 0;
    goto many_test;
many_loop:
    unit = *(u8 **)(arg0 + ((u16)j * 4) + 0x38);
    if ((*(u16 *)(unit + 0x1A) & 1) != 0 &&
        *(u8 *)(*(u8 **)(unit + 0x30) + 0xA2) != (state & 0xFF)) {
        return 0;
    }
    j = (j + 1) & 0xFFFF;
many_test:
    if ((j & 0xFFFF) < count) {
        goto many_loop;
    }
    return 1;
}
/* measured: close opt_loop_invariants after func_001f1030 probe. */
#pragma opt_loop_invariants off
// FUN_001F11E0
s32 func_001f11e0(s64 arg0) {
    u8 *base;

    base = iGpffffb3b8;
    return (s32)(base[(s16)arg0 * 0x28 + 2] == 1);
}
/* Matched with direct-index and global-address helper spellings. */
// FUN_001F1210
s32 func_001f1210(u8 *arg0, s64 arg1, s32 arg2)
{
    s32 index;

    index = (s16)arg1;
    if (*(u8 *)((u32)addOffsetFirst(
        (u32)(index * 0x28),
        (u32)addBaseFirst((u32)iGpffffb3b8, 0)) + 2) != 1) {
        return 0;
    }
    if ((arg2 == 0) ||
        ((*(u16 *)(iGpffffb3e0 + (*(u16 *)(arg0 + 0xA4) * 0x58)) & 0x10) != 0) ||
        ((*(u16 *)((u32)addOffsetFirst(
            (u32)(index * 4),
            (u32)iGpffffb3bc) + 2) & 1) == 0)) {
        return 0;
    }
    return 1;
}
// FUN_001F12B0
s8 func_001f12b0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4)
{
    s32 temp_3;
    s32 temp_4;
    s8 var_16;
    s8 var_2;
    s8 var_2_2;
    s8 var_2_3;

    var_16 = -1;
    temp_4 = *(s32 *)(arg1 + 8);
    if ((temp_4 != 0) || (*(s32 *)(arg1 + 0x10) & 0x037C12AA)) {
        var_16 = -2;
    }
    if ((temp_4 & 0x100000) != 0) {
        var_16 = 9;
    } else if ((*(s32 *)arg1 < 0) || ((temp_4 & 0x80000) != 0)) {
        if ((*(u16 *)(arg1 + 0x1E) & 8) == 0) {
            if ((func_00232710(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64),
                               0x100000) != 0) &&
                ((*(s32 *)(*(u8 **)(arg0 + 0x30) + 0x9C) & 0x8000) == 0)) {
                var_16 = 9;
            } else {
                var_16 = 2;
            }
        } else {
            var_16 = 2;
        }
    } else if ((*(s32 *)(arg1 + 0xC) & 0x100000) != 0) {
        var_16 = 0xB;
    }
    temp_3 = arg2 & 0xFFFF;
    switch (temp_3) {
    case 4:
    case 2:
        if ((*(s32 *)(*(u8 **)(arg0 + 0x30) + 0x9C) & 0x80) != 0) {
            var_2 = 0x17;
        } else {
            var_2 = -4;
        }
        var_16 = var_2;
        break;
    default:
        break;
    }
    if ((*(u16 *)(arg1 + 0x1E) & 4) != 0) {
        if ((*(s32 *)(*(u8 **)(arg0 + 0x30) + 0x9C) & 0x80) != 0) {
            var_2_2 = 0x17;
        } else {
            var_2_2 = -3;
        }
        var_16 = var_2_2;
    }
    if (arg4 != 0) {
        if ((*(s32 *)(*(u8 **)(arg0 + 0x30) + 0x9C) & 0x20) != 0) {
            var_2_3 = 0x13;
        } else {
            var_2_3 = 2;
        }
        var_16 = var_2_3;
    }
    if (((*(s32 *)(arg1 + 0xC) & 0x80000) != 0) &&
        (func_00232710(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64),
                       0x80000) != 0) &&
        ((*(s32 *)(*(u8 **)(arg0 + 0x30) + 0x9C) & 0x200) != 0)) {
        var_16 = 0x14;
    }
    return var_16;
}
/* measured: GUARDED_SCORE 1416 via `python3 tools/measure_guarded.py src/promoted/code1_001f.c func_001f14f0` (romwright oracle de-noised: single-u8* signature from call sites code1_001a.c:2239/4325; void return per retail epilogue setting no $v0 and callers ignoring it; bare func_0043f9c8 call per retail sw $30 after jal ignoring $v0; u16-outer/u8-inner/s16-found loop counters with explicit &0xFFFF/&0xFF init-test-incr per retail F2A20-F2AF8; load signedness per-offset census 0x6C/0x70/0x6A/0x2C/0x3F4 lhu, 0xA2/0x11/0x14B/0x18B/0x24 lbu, 0xEE lh kept for == -1; (s32)/(u8*) casts per file idiom code1_001f.c:740/817); obj 1556I / retail 1524I (+32, +2.10% PASS, band 1478-1570, headroom 14). fnalign 1492 edits +2 reloc-only. */
/* wide-store 1416->1387 (-29 words), 1492->1406 edits (-86, -5.8%) via `python3 tools/fnalign.py src/promoted/code1_001f.c func_001f14f0 --candidate /tmp/1f14f0_wide.c`: byte-pair/quad stores widened to retail's half/word form per asymmetric sb/sh/sw runs (sb 96->38, sh deficit +20->+11, sw deficit +21->+11; lui unchanged +3). Sites: pbVar4/pbVar6 0x2c halfword 0, p/pbVar5 0xdc halfword 0, 0xe0/0xe4 word 0, 0xe8 word 0/1 (three 0xe8=1 sites), 0xec halfword 0, 0xee halfword 0xffff, pbVar5 0x3f4 halfword 0x240, pbVar5 0xe4 word 1. Obj 1516I vs retail 1523I (-7, -0.5% PASS, band 1477-1569); frame still 0x2c0 vs retail 0x310 (-80, alias not yet addressed); regsave clean (no GPR/FPR diff); jal still 22 vs 10 and dsll32/dsra32 surplus remain for next pass. Honest: no sltiu-for-slti, no s64 flat, no opt_propagation, no volatile, no asm; window alignment untouched. */
/* measured 001f14f0 (owner, 2026-09-19): fnalign **1406 -> 1384 edits** and the count from
   1516 to 1520 against retail 1523, by writing the dispatch as `switch (temp_v12)` with
   `case 3: case 4:` sharing one body.  The chain spelled it `(temp_v12 == 3) || (temp_v12 ==
   4)` followed by `else if (== 2)` and `else if (== 1)`, which the switch sweep's converter
   does not recognise - an OR of two equalities against the same variable is a pair of
   fallthrough cases, not a compound condition.
   Case ORDER is the whole lever here: ascending 1/2/3+4 is 1384, but keeping the source's
   3+4/2/1 order is 1443, worse than the chain it replaces.  Measure both directions.
   The same shape in func_001b2380 - `(temp_v4 == 1) || (temp_v4 == 0)` then `else if (== 2)`,
   with a `goto LAB_001b2a6c` from the second arm into the first - was converted the same way
   and is WORSE (1392 -> 1394, count 1014 -> 1016), so it stays a chain. */
/* measured 001f14f0 (owner, 2026-09-20): fnalign **1384 -> 1340 edits**, count 1520 -> 1505
   against retail 1523, by giving six float literals their `f` suffix.  A bare `1.5` in C
   is a DOUBLE, so every expression touching one is promoted to double, and the EE has no
   hardware doubles - MWCC calls the emulation library instead.  That is a correctness bug
   in the reconstruction, not a spelling preference.
   The lever came from func_00471370, where 86 unsuffixed constants were forcing about 155
   double-emulation calls and suffixing them took that floor 1971 -> 1551 edits and a +11%
   body to retail's exact length.
   Swept over every first-party floor carrying a bare literal.  Only this one improved:
   func_001441e0, func_001c9820, func_001ca590, func_00205ff0 and func_00348c40 are all
   exactly neutral, and func_001b2380 is WORSE (1392 -> 1418) while losing 91 instructions.
   The first run of that sweep also reported eleven 'compile failed' floors, which was my
   regex suffixing inside exponent literals - `2.1474836e9f` became `2.1474836fe9f`.  The
   pattern now excludes `e`/`E`, and those floors have no bare literal at all. */
// FUN_001F14F0 NONMATCHING
#ifdef NON_MATCHING
void func_001f14f0(u8 *arg0)

{
    extern s32 func_00235520(s32, u8 *, u8 *, s32, s32, s32, s32, s32);
    extern s32 func_0023e6f0(u8 *, u8 *, s32, s32);
    extern void func_001f9cd0(void);
    extern s32 func_001fb170(s32);
    extern s32 func_001fb1f0(u8 *, s32);
    extern s32 func_001fb360(u8 *, s32);
    extern s32 func_00242990(u8 *, s32);
    extern s32 func_002411a0(u8 *, u8 *, s32, s32, s32);
    extern s32 func_0023d8e0(u8 *, u16);

    extern u8 iGpffffb3cc[];
    extern f32 fGpffff812c;
    extern f32 fGpffff80d4;
    u8 *p = arg0;
    u16 oi;
    u8 ii;
  char temp_v0;
  char temp_v1;
  unsigned short temp_v2;
  unsigned char *pbVar4;
  unsigned char *pbVar5;
  unsigned char *pbVar6;
  unsigned int temp_v3;
  int temp_v4;
  unsigned char temp_v5;
  unsigned char temp_v6;
  unsigned char temp_v7;
  unsigned short temp_v8;
  unsigned short temp_v9;
  short temp_v10;
  int temp_v11;
  unsigned int temp_v12;
  int temp_v13;
  unsigned int temp_v14;
  unsigned int temp_v15;
  unsigned int temp_v16;
  unsigned int temp_v17;
  unsigned char *pbVar22;
  unsigned int *puVar23;
  unsigned char *pbVar24;
  unsigned int temp_v18;
  long long temp_v19;
  long temp_v20;
  char temp_v21;
  int temp_v22;
  int temp_v23;
  unsigned short *puVar31;
  unsigned int temp_v24;
  float temp_v25;
  float temp_v26;
  unsigned short uStack_170;
  int iStack_ec;
  int iStack_e8;
  int iStack_e4;
  unsigned char bStack_e0;
  unsigned char bStack_d0;
  unsigned char bStack_c0;
  unsigned char bStack_b0;
  short sStack_a0;
  short sStack_80;
  unsigned int uStack_70;
  int iStack_60;
  int iStack_50;
  int iStack_40;
  int iStack_2c;
  int iStack_28;
  unsigned char *pbStack_24;
  unsigned char *pbStack_4;
  
  sStack_a0 = 0;
  temp_v2 = *(unsigned short *)(p + 0x6e);
  *(unsigned short *)(p + 0x72) = temp_v2;
  temp_v18 = (unsigned int)(*(short *)(p + 0x6c) == 3);
  temp_v11 = (unsigned int)temp_v2 * 0x28;
  temp_v0 = *(unsigned char *)(temp_v11 + (s32)iGpffffb3b8 + 0x11);
  pbVar4 = *(unsigned char **)(*(int *)(p + 0x30) + 0xa64);
  *(unsigned short *)(pbVar4 + 0x2c) = 0;
  if ((*(short *)(p + 0x6c) == 3) && (*(short *)(p + 0x70) != 0)) {
    temp_v18 = 1;
  }
  temp_v12 = func_0023d8e0(pbVar4,temp_v2);
  temp_v21 = (char)temp_v12;
  p[0xd9] = 0;
  *(unsigned short *)(p + 0xdc) = 0;
  *(unsigned int *)(p + 0xe0) = 0;
  *(unsigned int *)(p + 0xe4) = 0;
  p[0xdb] = 0;
  p[0xda] = 0;
  *(unsigned int *)(p + 0xe8) = 0;
  *(unsigned short *)(p + 0xec) = 0;
  *(unsigned short *)(p + 0xee) = 0xffff;
  if ((temp_v18 == 0) && (temp_v12 = func_0023df70((unsigned int)temp_v2), temp_v12 == 0)) {
    temp_v12 = func_0023ddc0(pbVar4,(unsigned int)temp_v2);
    switch (temp_v12) {
    case 1:
      *(unsigned int *)(p + 0xe8) = 1;
      if (*(unsigned char *)(*(int *)(p + 0x30) + 0xa2) == '\0') {
        temp_v9 = 0x36;
      }
      else {
        temp_v9 = 0x37;
      }
      *(unsigned short *)(p + 0xec) = temp_v9;
        break;
    case 2:
      *(unsigned int *)(p + 0xe8) = 1;
      if (*(unsigned char *)(*(int *)(p + 0x30) + 0xa2) == '\0') {
        temp_v9 = 0x38;
      }
      else {
        temp_v9 = 0x39;
      }
      *(unsigned short *)(p + 0xec) = temp_v9;
        break;
    case 3:
    case 4:
      *(unsigned int *)(p + 0xe8) = 1;
      if (*(unsigned char *)(*(int *)(p + 0x30) + 0xa2) == '\0') {
        temp_v9 = 0x3a;
      }
      else {
        temp_v9 = 0x3b;
      }
      *(unsigned short *)(p + 0xec) = temp_v9;
        break;
    }
  }
  if (*(int *)(p + 0xe8) == 1) {
    p[0xdb] = 0;
  }
  else {
    temp_v12 = (unsigned int)*(unsigned short *)(p + 0x6a);
    if (1 < temp_v12) {
      temp_v14 = 0;
      while ((temp_v14 < temp_v12 && (*(unsigned char **)(p + temp_v14 * 4 + 0x38) != p))) {
        temp_v14 = (temp_v14 + 1) & 0xffff;
      }
      if (temp_v14 != temp_v12) {
        while ((int)temp_v14 < (int)(*(unsigned short *)(p + 0x6a) - 1)) {
          *(unsigned int *)(p + temp_v14 * 4 + 0x38) =
               *(unsigned int *)(p + temp_v14 * 4 + 0x3c);
        }
        *(unsigned char **)(p + temp_v14 * 4 + 0x38) = p;
      }
    }
    temp_v26 = 1.0f;
    if (*(unsigned char *)(*(int *)(p + 0x30) + 0xa2) == '\x01') {
      temp_v13 = func_00243fa0((unsigned int)temp_v2,1);
      temp_v26 = 1.0f;
      if (temp_v13 == 0) {
        temp_v8 = *(unsigned short *)(*(int *)(p + 0x30) + 0xa4);
        temp_v25 = *(float *)(*(int *)(p + 0x30) + 0x2c) /
                 ((float)*(unsigned short *)(((unsigned int)temp_v8 * 0x1c + (unsigned int)temp_v8) * 8 + iGpffffb3cc + 0x14)
                 / 100.0f);
        temp_v26 = fGpffff812c;
        if ((temp_v25 <= fGpffff812c) && (temp_v26 = fGpffff80d4, fGpffff80d4 <= temp_v25)) {
          temp_v26 = temp_v25;
        }
        temp_v26 = temp_v26 * 1.0f;
      }
    }
    p[0x3f4] = 0x40;
    p[0x3f5] = 2;
    bStack_e0 = 0;
    sStack_80 = 0;
    iStack_40 = 0;
    temp_v12 = (unsigned int)temp_v2;
    while (uStack_170 < *(unsigned short *)(p + 0x6a)) {
      pbVar5 = *(unsigned char **)(p + (unsigned int)uStack_170 * 4 + 0x38);
      pbVar6 = *(unsigned char **)(*(int *)(pbVar5 + 0x30) + 0xa64);
      iStack_50 = 0;
      iStack_60 = 0;
      iStack_ec = 0;
      temp_v6 = 0;
      *(unsigned short *)(pbVar5 + 0x3f4) = 0x240;
      *(unsigned short *)(pbVar6 + 0x2c) = 0;
      pbVar5[0xd9] = 0;
      *(unsigned short *)(pbVar5 + 0xdc) = 0;
      *(unsigned int *)(pbVar5 + 0xe0) = 0;
      *(unsigned int *)(pbVar5 + 0xe4) = 0;
      pbVar5[0xdb] = 0;
      pbVar5[0xda] = 0;
      *(unsigned int *)(pbVar5 + 0xe8) = 0;
      *(unsigned short *)(pbVar5 + 0xec) = 0;
      *(unsigned short *)(pbVar5 + 0xee) = 0xffff;
      temp_v14 = func_0023e6f0(pbVar4,pbVar6,temp_v2,temp_v18);
      temp_v14 = temp_v14 & 0xffff;
      pbStack_24 = pbVar6;
      pbStack_4 = pbVar5;
      if (temp_v14 == 0x200) {
        temp_v14 = func_0023e6f0(pbVar4,pbVar4,temp_v2,temp_v18 | 2);
        temp_v14 = temp_v14 & 0xffff;
        if ((temp_v14 == 4) || (temp_v14 == 2)) {
          temp_v14 = 1;
        }
        else if (temp_v14 == 0x200) {
          temp_v14 = 0x100;
        }
        *(unsigned int *)(pbVar5 + 0xe4) = 1;
        pbStack_24 = pbVar4;
        pbStack_4 = p;
      }
      if (*(int *)(pbVar5 + 0xe4) == 0) {
        temp_v8 = func_002411a0(pbVar4,pbStack_24,temp_v2,temp_v14,temp_v18);
      }
      else {
        temp_v8 = 1;
      }
      temp_v24 = (unsigned int)temp_v8;
      temp_v13 = func_0023df70((unsigned int)temp_v2);
      if (temp_v13 == 0) {
        bStack_c0 = func_00243650(pbVar4,(unsigned int)temp_v2,temp_v24);
        bStack_d0 = 1;
      }
      else {
        bStack_c0 = 1;
        func_0023e1f0(*(unsigned char **)(*(int *)(p + 0x30) + 0xa64));
        temp_v13 = func_0023e2f0(pbVar4,temp_v24);
        bStack_d0 = (unsigned char)temp_v13;
      }
      if (*(int *)(pbVar5 + 0xe4) == 0) {
        if ((((temp_v14 == 0x100) || (temp_v14 == 4)) || (temp_v14 == 2)) ||
           ((temp_v14 == 0x400 || (temp_v14 == 0x200)))) {
          bStack_c0 = 1;
          bStack_d0 = 1;
        }
      }
      else {
        bStack_c0 = 1;
        bStack_d0 = 1;
      }
      if (*(int *)(pbVar5 + 0xe4) == 0) {
        iStack_e4 = func_00241de0(pbVar4,pbStack_24,(unsigned int)temp_v2,temp_v14,temp_v24);
        iStack_e8 = func_00241f00(pbVar4,pbVar6,(unsigned int)temp_v2,temp_v14);
        if ((iStack_e4 != 0) || (temp_v20 = func_00232710((s32)pbVar6,0x100000), temp_v20 != 0)) {
          iStack_ec = func_00242360(pbVar4,pbVar6,(unsigned int)temp_v2,temp_v14,temp_v24);
        }
      }
      else {
        iStack_e4 = 0;
        iStack_e8 = 0;
      }
      temp_v15 = func_002397d0((unsigned int)temp_v2,pbVar4,pbStack_24,temp_v14,temp_v24,temp_v18);
      temp_v16 = func_00239e40((unsigned int)temp_v2,pbVar4,pbStack_24,temp_v14,temp_v24,temp_v18);
      temp_v13 = temp_v11 + (s32)iGpffffb3b8;
      if ((((*(unsigned char *)(temp_v13 + 0x18) == '\x01') && ((*(unsigned int *)(temp_v13 + 0x1c) & 0x80000) != 0)) &&
          (*(char *)(temp_v13 + 0x24) != '\t')) && ((temp_v15 & 0x80000) == 0)) {
        iStack_e4 = 0;
      }
      if (temp_v15 == 0x80000) {
        pbVar5[0xe0] = 1;
        pbVar5[0xe1] = 0;
        pbVar5[0xe2] = 0;
        pbVar5[0xe3] = 0;
      }
      temp_v17 = func_001fb360(pbVar5,temp_v12);
      if (((temp_v14 != 1) || (*(int *)(pbVar5 + 0xe4) != 0)) || ((short)temp_v17 != 0)) {
        uStack_70 = 0;
      }
      else {
        uStack_70 = *(unsigned int *)(temp_v11 + (s32)iGpffffb3b8 + 0x20);
      }
      *(short *)(pbVar5 + 0xdc) = (short)temp_v14;
      *(unsigned short *)(pbVar5 + 0xde) = temp_v8;
      temp_v5 = (temp_v16 & 0x80000) == 0;
      while ((unsigned int)bStack_b0 < (unsigned int)bStack_c0) {
        puVar31 = (unsigned short *)(pbVar5 + (unsigned int)bStack_b0 * 0x20 + 0x10e);
        (pbVar5 + (unsigned int)bStack_b0 * 0x20 + 0x10e)[0] = 0;
        (pbVar5 + (unsigned int)bStack_b0 * 0x20 + 0x10e)[1] = 0;
        pbVar22 = pbVar5 + (unsigned int)bStack_b0 * 0x20 + 0x108;
        (pbVar5 + (unsigned int)bStack_b0 * 0x20 + 0x108)[0] = 0;
        (pbVar5 + (unsigned int)bStack_b0 * 0x20 + 0x108)[1] = 0;
        (pbVar5 + (unsigned int)bStack_b0 * 0x20 + 0x10a)[0] = 0;
        (pbVar5 + (unsigned int)bStack_b0 * 0x20 + 0x10a)[1] = 0;
        iStack_28 = func_00235520(temp_v2,pbVar4,pbStack_24,1,temp_v14,temp_v24,temp_v18,1);
        iStack_2c = func_00235520(temp_v2,pbVar4,pbStack_24,1,temp_v14,temp_v24,temp_v18,2);
        if ((int)((float)iStack_28 * temp_v26) != 0) {
          iStack_28 = (int)((float)iStack_28 * temp_v26);
        }
        if ((int)((float)iStack_2c * 1.0f) != 0) {
          iStack_2c = (int)((float)iStack_2c * 1.0f);
        }
        puVar23 = (unsigned int *)(pbVar5 + (unsigned int)bStack_b0 * 0x20 + 0xf8);
        *(unsigned int *)(pbVar5 + (unsigned int)bStack_b0 * 0x20 + 0xf8) = temp_v15;
        *(unsigned int *)(pbVar5 + (unsigned int)bStack_b0 * 0x20 + 0xfc) = temp_v16;
        temp_v13 = func_002384b0((unsigned int)temp_v2,pbVar4,(int)pbStack_24);
        temp_v1 = *(unsigned char *)(temp_v11 + (s32)iGpffffb3b8 + 0x11);
        if ((temp_v1 == '\r') || (temp_v1 == '\f')) {
          temp_v9 = func_0043c6a0(iStack_28);
          *(unsigned short *)pbVar22 = temp_v9;
        }
        temp_v1 = *(unsigned char *)(temp_v11 + (s32)iGpffffb3b8 + 0x14);
        if ((temp_v1 == '\r') || (temp_v1 == '\f')) {
          temp_v9 = func_0043c6a0(iStack_2c);
          *(unsigned short *)(pbVar5 + (unsigned int)bStack_b0 * 0x20 + 0x10a) = temp_v9;
        }
        *(unsigned int *)(pbVar5 + (unsigned int)bStack_b0 * 0x20 + 0x100) = uStack_70;
        *(int *)(pbVar5 + (unsigned int)bStack_b0 * 0x20 + 0x104) = temp_v13;
        pbVar24 = pbVar5 + (unsigned int)bStack_b0 * 0x20 + 0xf0;
        *(int *)(pbVar5 + (unsigned int)bStack_b0 * 0x20 + 0xf0) = iStack_28;
        *(int *)(pbVar5 + (unsigned int)bStack_b0 * 0x20 + 0xf4) = iStack_2c;
        iStack_50 = iStack_50 + iStack_28;
        iStack_60 = iStack_60 + iStack_2c;
        if (pbStack_4 == p) {
          iStack_40 = iStack_40 + iStack_28;
        }
        if (*(unsigned char *)(temp_v11 + (s32)iGpffffb3b8 + 0x24) == '\x02') {
          *puVar31 = *puVar31 | 0x20;
        }
        if ((*(unsigned char *)(temp_v11 + (s32)iGpffffb3b8) & 1) != 0) {
          *puVar31 = *puVar31 | 0x40;
        }
        if (temp_v0 == '\x10') {
          *puVar31 = *puVar31 | 8;
        }
        if (pbStack_4 == p) {
          temp_v20 = (s32)func_002428f0((s32)(pbStack_24),iStack_40);
          temp_v6 = temp_v20 != 0;
          if ((temp_v20 == 0) && (temp_v6 = 0, (temp_v15 & 0x80000) != 0)) {
            temp_v6 = temp_v5;
          }
        }
        else {
          temp_v20 = (s32)func_002428f0((s32)(pbStack_24),iStack_50);
          temp_v6 = temp_v20 != 0;
          if ((temp_v20 == 0) && (temp_v6 = 0, (temp_v15 & 0x80000) != 0)) {
            temp_v6 = temp_v5;
          }
        }
        if ((bStack_b0 + 1 == (unsigned int)bStack_c0) || (temp_v6)) {
          if (iStack_e4 == 0) {
            if ((((((iStack_50 < 0) || (temp_v14 == 0x100)) || (temp_v14 == 0x400)) &&
                 (temp_v20 = func_00232710((s32)pbStack_24,0x100000), temp_v20 != 0)) ||
                ((*(int *)(pbVar5 + 0xe4) == 1 &&
                 (temp_v20 = func_00232710((s32)pbVar6,0x100000), temp_v20 != 0)))) &&
               ((*puVar31 = *puVar31 | 1, *(int *)(pbVar5 + 0xe4) == 1 ||
                ((temp_v14 == 0x100 || (temp_v14 == 0x400)))))) {
              *puVar31 = *puVar31 | 2;
            }
          }
          else {
            *puVar23 = *puVar23 | 0x100000;
          }
          if (((iStack_ec == 0) || (-1 < iStack_50)) || (temp_v15 != 0)) {
            iStack_ec = 0;
          }
          else {
            *puVar23 = *puVar23 | 1;
          }
          if (iStack_e8 != 0) {
            *puVar31 = *puVar31 | 4;
          }
          if (((temp_v14 != 1) || (*(int *)(pbVar5 + 0xe4) == 1)) || (iStack_e8 == 1)) {
            bStack_e0 = 2;
          }
          else if (iStack_e4 != 0) {
            sStack_80 = sStack_80 + 1;
          }
        }
        if (temp_v6) {
          temp_v10 = *(unsigned short *)(pbStack_4 + 0x3f4);
          if (temp_v10 == 0x240) {
            temp_v10 = func_00242990((u8 *)*(unsigned int *)(*(int *)(pbStack_4 + 0x30) + 0xa64),temp_v2);
          }
          if (temp_v10 < 0) {
            temp_v7 = func_001f12b0(pbStack_4,pbVar24,temp_v14,temp_v24,1);
            pbVar5[(unsigned int)bStack_b0 * 0x20 + 0x10c] = temp_v7;
            pbVar5[0xe0] = 1;
            pbVar5[0xe1] = 0;
            pbVar5[0xe2] = 0;
            pbVar5[0xe3] = 0;
            if (p == pbStack_4) {
              pbVar22[0] = 0;
              pbVar22[1] = 0;
            }
          }
          else {
            *(unsigned short *)(pbStack_4 + 0x3f4) = temp_v10;
            *puVar31 = *puVar31 | 0x10;
            temp_v7 = func_001f12b0(pbStack_4,pbVar24,temp_v14,temp_v24,0);
            pbVar5[(unsigned int)bStack_b0 * 0x20 + 0x10c] = temp_v7;
          }
          bStack_c0 = (unsigned char)(bStack_b0 + 1);
          break;
        }
        temp_v7 = func_001f12b0(pbStack_4,pbVar24,temp_v14,temp_v24,0);
        pbVar5[(unsigned int)bStack_b0 * 0x20 + 0x10c] = temp_v7;
      }
      if (((*(int *)(pbVar5 + 0xe4) == 1) || ((temp_v14 & 0x700) != 0)) ||
         ((iStack_50 != 0 || (((iStack_60 != 0 || (temp_v15 != 0)) || (temp_v16 != 0)))))) {
        if ((*(int *)(pbVar5 + 0xe4) == 1) || ((temp_v14 & 0x500) != 0)) {
          func_001f9cd0();
        }
        if (((*(unsigned char *)(*(int *)(pbVar5 + 0x30) + 0xa2) == '\x01') &&
            (romwright_piece_4_4((int)(((long)temp_v21 << 0x38) >> 0x3f),(int)temp_v21) < 8)) &&
           ((temp_v14 & 6) == 0)) {
          func_0010f3d0((unsigned int)*(unsigned short *)(*(int *)(pbVar5 + 0x30) + 0xa4),
                        (unsigned int)(unsigned short)(short)temp_v21);
        }
      }
      temp_v10 = *(unsigned short *)(pbVar4 + 0x2c);
      if (*(unsigned short *)(pbVar4 + 0x2c) == 0) {
        temp_v10 = sStack_a0;
        if (*(unsigned short *)(pbVar6 + 0x2c) != 0) {
          temp_v10 = *(unsigned short *)(pbVar6 + 0x2c);
        }
      }
      sStack_a0 = temp_v10;
      if ((short)temp_v17 == 0) {
        if ((temp_v14 & 6) == 0) {
          temp_v19 = func_001f0260(temp_v12);
          temp_v10 = (short)temp_v19;
        }
        else {
          temp_v10 = 0;
        }
      }
      else {
        temp_v13 = func_001fb170(temp_v17 & 0xffff);
        temp_v10 = (short)temp_v13;
        p[0xd8] = p[0xd8] | 1;
      }
      if (temp_v10 == 0) {
        if (sStack_a0 == 0) {
          if (!temp_v6) {
            if ((iStack_ec != 0) || ((temp_v15 & 1) != 0)) {
              if (*(unsigned char *)(*(int *)(pbVar5 + 0x30) + 0xa2) == '\0') {
                temp_v9 = 0x18;
              }
              else {
                temp_v9 = 0x19;
              }
              *(unsigned short *)(pbVar5 + 0xec) = temp_v9;
            }
            else if (temp_v15 != 0) {
              if ((temp_v15 & 2) == 0) {
                if ((temp_v15 & 4) == 0) {
                  if ((temp_v15 & 8) == 0) {
                    if ((temp_v15 & 0x10) == 0) {
                      if ((temp_v15 & 0x20) == 0) {
                        if ((temp_v15 & 0x40) == 0) {
                          if ((temp_v15 & 0x80) != 0) {
                            if (*(unsigned char *)(*(int *)(pbVar5 + 0x30) + 0xa2) == '\0') {
                              temp_v9 = 0xe;
                            }
                            else {
                              temp_v9 = 0xf;
                            }
                            *(unsigned short *)(pbVar5 + 0xec) = temp_v9;
                          }
                        }
                        else {
                          if (*(unsigned char *)(*(int *)(pbVar5 + 0x30) + 0xa2) == '\0') {
                            temp_v9 = 0x1a;
                          }
                          else {
                            temp_v9 = 0x1b;
                          }
                          *(unsigned short *)(pbVar5 + 0xec) = temp_v9;
                        }
                      }
                      else {
                        if (*(unsigned char *)(*(int *)(pbVar5 + 0x30) + 0xa2) == '\0') {
                          temp_v9 = 0x10;
                        }
                        else {
                          temp_v9 = 0x11;
                        }
                        *(unsigned short *)(pbVar5 + 0xec) = temp_v9;
                      }
                    }
                    else {
                      if (*(unsigned char *)(*(int *)(pbVar5 + 0x30) + 0xa2) == '\0') {
                        temp_v9 = 0x12;
                      }
                      else {
                        temp_v9 = 0x13;
                      }
                      *(unsigned short *)(pbVar5 + 0xec) = temp_v9;
                    }
                  }
                  else {
                    if (*(unsigned char *)(*(int *)(pbVar5 + 0x30) + 0xa2) == '\0') {
                      temp_v9 = 0x1c;
                    }
                    else {
                      temp_v9 = 0x1d;
                    }
                    *(unsigned short *)(pbVar5 + 0xec) = temp_v9;
                  }
                }
                else {
                  if (*(unsigned char *)(*(int *)(pbVar5 + 0x30) + 0xa2) == '\0') {
                    temp_v9 = 0x14;
                  }
                  else {
                    temp_v9 = 0x15;
                  }
                  *(unsigned short *)(pbVar5 + 0xec) = temp_v9;
                }
              }
              else {
                if (*(unsigned char *)(*(int *)(pbVar5 + 0x30) + 0xa2) == '\0') {
                  temp_v9 = 0x16;
                }
                else {
                  temp_v9 = 0x17;
                }
                *(unsigned short *)(pbVar5 + 0xec) = temp_v9;
              }
            }
          }
        }
        else {
          *(short *)(pbVar5 + 0xec) = sStack_a0;
        }
      }
      else {
        *(short *)(pbVar5 + 0xec) = temp_v10;
      }
      pbVar5[0xd9] = bStack_c0;
      pbVar5[0xda] = bStack_d0;
    }
    if (sStack_80 != 0) {
      bStack_e0 = 1;
    }
    if (*(short *)(p + 0xee) == -1) {
      temp_v10 = func_001f0610();
      *(short *)(p + 0xee) = temp_v10;
    }
    if (*(unsigned char *)(temp_v11 + (s32)iGpffffb3b8 + 0x24) == '\x06') {
      *(unsigned short *)(p + 0x1a) = *(unsigned short *)(p + 0x1a) | 0x4000;
    }
    temp_v12 = func_001fb1f0(p,temp_v12);
    if (((temp_v12 & 0xffff) != 0) && (*(int *)(p + 0xe8) != 1)) {
      temp_v12 = func_001fb170(temp_v12 & 0xffff);
      *(short *)(p + 0xec) = (short)temp_v12;
    }
    p[0xdb] = bStack_e0;
    if ((((*(unsigned char *)(*(int *)(p + 0x30) + 0xa2) == '\x01') &&
         (*(short *)(p + 0x6a) == 1)) &&
        (*(int *)(p + 0x38) == *(int *)(iGpffffb3ac + 0x170))) &&
       (*(int *)(*(int *)(p + 0x38) + 0xe0) == 1)) {
      temp_v6 = 0;
      while (!temp_v6) {
        if (*(int *)(*(int *)(p + 0x38) + 0xe4) != 0) {
          temp_v6 = 1;
          goto LAB_001f27e8;
        }
        temp_v6 = 1;
      }
      temp_v6 = 0;
LAB_001f27e8:
      if (!temp_v6) {
        temp_v18 = func_001efd50(p);
        *(unsigned int *)(p + 0x88) = temp_v18;
        if (temp_v18 == 0) {
          return;
        }
        temp_v13 = *(int *)(p + 0x38);
        temp_v3 = *(unsigned int *)(*(int *)(temp_v18 + 0x30) + 0xa64);
        if (*(unsigned char *)(temp_v11 + (s32)iGpffffb3b8 + 0x24) == '\r') {
          *(unsigned short *)(temp_v18 + 0xec) = *(unsigned short *)(temp_v13 + 0xec);
        }
        else {
          *(unsigned short *)(temp_v18 + 0xec) = 0;
        }
        p[0xdb] = 0;
        *(unsigned char *)(temp_v13 + 0xdb) = 0;
        *(unsigned short *)(temp_v13 + 0xdc) = 1;
        *(unsigned short *)(temp_v13 + 0xde) = 1;
        *(unsigned int *)(temp_v13 + 0xe0) = 0;
        *(unsigned int *)(temp_v13 + 0xe4) = 0;
        *(unsigned int *)(temp_v13 + 0xe8) = 0;
        *(unsigned short *)(temp_v13 + 0xec) = 0;
        *(unsigned short *)(temp_v13 + 0xee) = 0xffff;
        temp_v6 = 0;
        temp_v22 = 0;
        temp_v7 = *(unsigned char *)(temp_v13 + 0xd9);
        temp_v12 = 0;
        while(1) {
          if (temp_v7 <= temp_v12) {
            return;
          }
          temp_v23 = temp_v13 + temp_v12 * 0x20;
          temp_v4 = *(int *)(temp_v23 + 0xf0);
          temp_v22 = temp_v22 + temp_v4;
          temp_v20 = (s32)func_002428f0((s32)((u8 *)temp_v3),temp_v22);
          if ((temp_v20 != 0) ||
             (((*(unsigned int *)(temp_v23 + 0xf8) & 0x80000) != 0 &&
              ((*(unsigned int *)(temp_v23 + 0xfc) & 0x80000) == 0)))) {
            temp_v6 = 1;
          }
          temp_v23 = temp_v13 + temp_v12 * 0x20;
          func_0043f9c8((int *)(temp_v23 + 0xf0),0,0x20);
          *(int *)(temp_v23 + 0xf0) = temp_v4;
          *(unsigned char *)(temp_v23 + 0x10c) = 2;
          *(unsigned short *)(temp_v23 + 0x10e) = *(unsigned short *)(temp_v23 + 0x10e) | 0x200;
          if (*(unsigned char *)(temp_v11 + (s32)iGpffffb3b8 + 0x24) == '\r') break;
          if (temp_v6) {
            temp_v11 = temp_v12 * 0x20 + temp_v13;
            *(unsigned int *)(temp_v11 + 0xf8) = *(unsigned int *)(temp_v11 + 0xf8) | 0x80000;
            *(unsigned short *)(*(int *)(p + 0x88) + 0x3f4) = 0;
            *(unsigned short *)(temp_v23 + 0x10e) = *(unsigned short *)(temp_v23 + 0x10e) | 0x10;
            *(char *)(temp_v13 + 0xd9) = (char)temp_v12 + '\x01';
            return;
          }
          temp_v12 = (temp_v12 + 1) & 0xff;
        }
        temp_v11 = temp_v12 * 0x20 + temp_v13;
        *(unsigned int *)(temp_v11 + 0xf8) = *(unsigned int *)(temp_v11 + 0xf8) | 0x80000;
        *(unsigned int *)(temp_v11 + 0xfc) = *(unsigned int *)(temp_v11 + 0xfc) & 0xfff7ffff;
        *(char *)(temp_v13 + 0xd9) = (char)temp_v12 + '\x01';
        return;
      }
    }
    if ((((p[0xdb] & 1) != 0) && ((*(unsigned short *)(p + 0x18) & 4) == 0)) &&
       ((*(unsigned char *)(*(int *)(p + 0x30) + 0xa2) == '\0' && (*(short *)(p + 0x6a) != 0))))
    {
      temp_v10 = 0;
      oi = 0;
      while ((oi & 0xFFFF) < *(unsigned short *)(p + 0x6a)) {
        temp_v11 = *(int *)(p + (oi & 0xFFFF) * 4 + 0x38);
        if ((*(int *)(temp_v11 + 0xe0) != 1) ||
           (temp_v12 = func_00232710(*(unsigned int *)(*(int *)(temp_v11 + 0x30) + 0xa64),0x100000),
           temp_v12 != 0)) {
          ii = 0;
          while ((ii & 0xFF) < *(unsigned char *)(temp_v11 + 0xd9)) {
            if ((*(unsigned char *)(*(int *)(temp_v11 + 0x30) + 0xa2) == '\x01') &&
               ((*(unsigned int *)(temp_v11 + ii * 0x20 + 0xf8) & 0x100000) != 0)) {
              temp_v10 = temp_v10 + 1;
              break;
            }
            ii = (ii + 1) & 0xFF;
          }
        }
        else {
          temp_v10 = temp_v10 + 1;
        }
        oi = (oi + 1) & 0xFFFF;
      }
      while (temp_v11 != 0) {
        if (((((*(unsigned short *)(temp_v11 + 0x1a) & 1) != 0) &&
             (temp_v13 = *(int *)(temp_v11 + 0x30), *(char *)(temp_v13 + 0xa2) == '\x01')) &&
            ((*(unsigned int *)(temp_v13 + 0x9c) & 8) != 0)) &&
           ((temp_v12 = (s32)func_002428f0((s32)((u8 *)(*(unsigned int *)(temp_v13 + 0xa64))),0), temp_v12 == 0 &&
            (temp_v12 = func_00232710(*(unsigned int *)(*(int *)(temp_v11 + 0x30) + 0xa64),0x100000),
            temp_v12 == 0)))) {
          temp_v10 = temp_v10 - 1;
        }
      }
      if ((*(int *)(iGpffffb3ac + 0x170) != 0) &&
         (temp_v12 = func_00232710(*(unsigned int *)
                                 (*(int *)(*(int *)(iGpffffb3ac + 0x170) + 0x30) + 0xa64),0x100117),
         temp_v12 != 0)) {
        temp_v10 = 1;
      }
      if (temp_v10 != 0) {
        temp_v18 = func_001eff50(p);
        if (temp_v18 == 0) {
          temp_v11 = func_001ef9c0(p);
          temp_v12 = 0;
          if (temp_v11 != 0) {
            p[0x16] = 0xc;
            p[0x17] = 0;
            temp_v12 = func_001b0e30((int)p);
          }
        }
        else {
          if (*(unsigned short *)(p + 0x6a) < 2) {
            *(unsigned int *)(temp_v18 + 0x90) = *(unsigned int *)(p + 0x38);
            temp_v12 = temp_v18;
          }
          else {
            temp_v12 = func_00231d70((unsigned int)*(unsigned short *)(p + 0x6a));
            *(unsigned int *)(temp_v18 + 0x90) = *(unsigned int *)(p + temp_v12 * 4 + 0x38);
          }
          if (*(int *)(*(int *)(temp_v18 + 0x90) + 0xe0) == 0) {
            *(unsigned int *)(p + 0x8c) = temp_v18;
            *(unsigned short *)(temp_v18 + 0x16) = 0xd;
            temp_v12 = func_001b0e30(temp_v18);
          }
        }
      }
    }
  }
  return;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f14f0);
#endif
/* measured: the second loop's slot index is `(u16)var_8_2 * 4` (its own mask, not CSE'd
   with the loop test's `& 0xFFFF`) while the stored count is `(var_8_2 & 0xFFFF) + 1`
   (CSE'd with the test, retail's $a0); the counter store address is offset-first
   integer arithmetic `temp_6_2 + (u32)D_0076449C`. */
// FUN_001F2CC0
void func_001f2cc0(u8 *arg0)
{
    s32 sp3C;
    u8 *base;
    u8 *entry;
    u8 *base2;
    u8 *slot;
    s32 temp_6;
    s32 temp_6_2;
    s32 var_8;
    s64 var_7;
    s32 var_8_2;
    u16 temp_4;
    u16 var_16;
    u8 *temp_16;

    temp_4 = *(u16 *)(arg0 + 0x1A);
    if ((temp_4 & 1) != 0) {
        temp_16 = *(u8 **)(arg0 + 0x30);
        if (*(u8 *)(temp_16 + 0xA2) == 1) {
            if (*(u16 *)(temp_16 + 0xA4) >= 0x150) {
                func_0046d730((void *)D_0060AB08, 0x4F5);
            }
            temp_4 = *(u16 *)(arg0 + 0x1A);
            if ((temp_4 & 0x20) == 0) {
                *(u16 *)(arg0 + 0x1A) = (u16)(temp_4 | 0x20);
                *(s32 *)(D_0076449C + 0xCB0) =
                    *(s32 *)(D_0076449C + 0xCB0) +
                    func_00243950(*(s32 *)(temp_16 + 0xA64));
                *(s32 *)(D_0076449C + 0xCB4) =
                    *(s32 *)(D_0076449C + 0xCB4) +
                    func_002439c0(*(s32 *)(temp_16 + 0xA64));
                var_16 = (u16)(func_00243a30(
                    *(u8 **)(temp_16 + 0xA64), &sp3C) & 0xFFFF);
                if ((sp3C != 1) &&
                    (*(u16 *)(arg0 + 0x80) != 0) &&
                    ((s32)(func_00231d70(0x64) & 0xFF) <
                     (s32)*(u8 *)(arg0 + 0x82))) {
                    var_16 = *(u16 *)(arg0 + 0x80);
                }
                temp_6 = var_16 & 0xFFFF;
                if (temp_6 != 0) {
                    var_7 = 0;
                    var_8 = 0;
                    base = D_0076449C;
                    while ((var_8 & 0xFFFF) < 3) {
                        entry = base + ((u16)var_8 * 4);
                        if (*(u16 *)(entry + 0xCD0) == temp_6) {
                            *(s16 *)(entry + 0xCD2) =
                                (s16)(*(s16 *)(entry + 0xCD2) + 1);
                            var_7 = 1;
                            break;
                        }
                        var_8 = (var_8 + 1) & 0xFFFF;
                    }
                    if (var_7 == 0) {
                        var_8_2 = 0;
                        base2 = D_0076449C;
                        while ((var_8_2 & 0xFFFF) < 3) {
                            temp_6_2 = (u16)var_8_2 * 4;
                            slot = base2 + temp_6_2;
                            if (*(u16 *)(slot + 0xCD0) == 0) {
                                *(u16 *)(slot + 0xCD0) = var_16;
                                *(s16 *)(temp_6_2 + (u32)D_0076449C + 0xCD2) = 1;
                                *(s32 *)(D_0076449C + 0xCDC) = (var_8_2 & 0xFFFF) + 1;
                                return;
                            }
                            var_8_2 = (var_8_2 + 1) & 0xFFFF;
                        }
                    }
                }
            }
        }
    }
}
// FUN_001F2EB0
void func_001f2eb0(u8 *arg0, s32 arg1)
{
    s32 value;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    func_00243e70(*(s32 *)(work + 0xA64));
    if (arg1 == 1) {
        if (*(u16 *)(arg0 + 0x3F4) != 0x154) {
            func_00231f20(*(s32 *)(work + 0xA64), 1);
        }
        func_002326f0(*(s32 *)(work + 0xA64), 0x80000);
        *(s32 *)(work + 0x9C) |= 0x10;
        return;
    }
    func_00231f20(*(s32 *)(work + 0xA64), 0);
    func_002326f0(*(s32 *)(work + 0xA64), 0xFFFFFF);
    func_00232680(*(s32 *)(work + 0xA64), 0x80000);
    value = *(s32 *)(work + 0x9C) | 1;
    *(s32 *)(work + 0x9C) = value;
    *(s32 *)(work + 0x9C) = value & ~0x10;
}
// FUN_001F2F90
s32 func_001f2f90(u8 *arg0) {
    u8 *p;

    p = iGpffffb3b8 + *(s16 *)(arg0 + 0x6E) * 40;
    if ((p[0] & 2) != 0) {
        return 0;
    }
    return (p[0x24] ^ 6) != 0;
}

// FUN_001F3870
/* The allocator result remains in v0 through packet initialization; all eleven
 * retail callers use it for submission or dependency setup. */
u8 *func_001f3870(u8 *action, u8 flags)
{
    u8 *packet;
    u8 *work;

    packet = func_00194470(0x701, 8);
    *(BtlTargetStateHook *)(packet + 0x68) = func_001f37b0;
    *(BtlTargetStateUpdate *)(packet + 0x6C) = func_001f37d0;
    *(BtlTargetStateHook *)(packet + 0x70) = func_001f3850;
    work = *(u8 **)(packet + 0x78);
    *(u8 **)(work + 0) = action;
    *(u8 *)(work + 4) = flags;
    return packet;
}

// FUN_001F38E0
void func_001f38e0(u8 **arg0)
{
    u8 *temp_4;

    temp_4 = *(u8 **)(*arg0 + 0x30);
    *(u16 *)(temp_4 + 0xA0) = (u16)(*(u16 *)(temp_4 + 0xA0) + 1);
}
// FUN_001F3900
s32 func_001f3900(u8 **arg0) {
    func_00235020(*(s32 *)(*(u8 **)(*arg0 + 0x30) + 0xA64));
    return 1;
}
// FUN_001F3950
u8 *func_001f3950(u8 *arg0)
{
    u8 *packet;

    packet = (u8 *)func_00194470(0x703, 4);
    *(void **)(packet + 0x68) = (void *)func_001f38e0;
    *(void **)(packet + 0x6C) = (void *)func_001f3900;
    *(void **)(packet + 0x70) = (void *)func_001f3930;
    **(u8 ***)(packet + 0x78) = arg0;
    return packet;
}

// FUN_001F39B0
void func_001f39b0(u8 **arg0)
{
    u8 *temp_4;

    temp_4 = *(u8 **)(*arg0 + 0x30);
    *(u16 *)(temp_4 + 0xA0) = (u16)(*(u16 *)(temp_4 + 0xA0) + 1);
}
// FUN_001F39D0
/* measured: opt_propagation off keeps the iGpffffb3b8 base load ahead of the
   index arithmetic and the 0x70 field load in a temporary before its saved copy. */
#pragma opt_propagation off
s32 func_001f39d0(u8 **arg0) {
    u8 *temp_4;
    u16 temp_17;
    u8 *temp_16;
    s32 temp_2;
    u16 temp_3;
    u8 temp_4_2;
    s32 off;
    u8 *base;
    u8 *ptr;
    s32 itemId;

    temp_4 = *arg0;
    temp_16 = *(u8 **)(temp_4 + 0x30);
    temp_3 = *(u16 *)(temp_4 + 0x6C);
    switch (temp_3) {
    case 2:
        temp_17 = *(u16 *)(temp_4 + 0x6E);
        temp_2 = func_0023d9b0(*(u8 **)(temp_16 + 0xA64), temp_17);
        if (temp_2 != 0) {
            base = iGpffffb3b8;
            off = (s32)((temp_17 & 0xFFFF) * 0x28);
            ptr = (u8 *)(off + (s32)base);
            temp_4_2 = ptr[3];
            switch (temp_4_2) {
            case 1:
                func_002325a0(*(s32 *)(temp_16 + 0xA64), -temp_2);
                break;
            case 2:
                func_00232610(*(s32 *)(temp_16 + 0xA64), -temp_2);
                break;
            }
        }
        break;
    case 3:
        if (*(u8 *)(temp_16 + 0xA2) == 0) {
            temp_3 = *(u16 *)(temp_4 + 0x70);
            itemId = (s16)temp_3;
            func_00106620(itemId, ((func_00106600((s16)temp_3) & 0xFF) - 1) & 0xFF);
        }
        break;
    case 9:
    case 1:
        break;
    }
    return 1;
}
/* measured: restore propagation for the rest of the unit. */
#pragma opt_propagation on
// FUN_001F3B20
u8 *func_001f3b20(u8 *arg0)
{
    u8 *packet;

    packet = (u8 *)func_00194470(0x702, 4);
    *(void **)(packet + 0x68) = (void *)func_001f39b0;
    *(void **)(packet + 0x6C) = (void *)func_001f39d0;
    *(void **)(packet + 0x70) = (void *)func_001f3b00;
    **(u8 ***)(packet + 0x78) = arg0;
    return packet;
}

// FUN_001F3B80
s32 func_001f3b80(s32 arg0) {
    s32 temp_5;
    s32 value;

    temp_5 = *(s32 *)(*(u8 **)(iGpffffb3ac + 0xA54) + 0x110);
    value = *(s32 *)((u8 *)addOffsetFirst((u32)((arg0 & 0xFFFF) * 0xC),
                                          (u32)temp_5) + 4);
    return (s32)addBaseFirst((u32)temp_5, (u32)value);
}
/* Native b210 -O2 recovery: 932 bytes plus 12 zero tail bytes.
   Keep both message results at function scope. One native word holds the
   first pass's element index, then the second pass's node address; each
   phase initializes it before use. The first head survives the flags scan,
   while the second head is reloaded after the first pass's query callbacks.
   The four unused arguments retain D_0060AB20's callback contract.
   See docs/probe_archive/BattleAction_20260922_resume.md. */
// FUN_001F3BB0
s32 func_001f3bb0(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    extern s32 func_001ef4d0(s32 arg0, s32 arg1);
    extern s32 func_00231e20(u8 *arg0);
    extern s32 func_00242800(u8 *arg0, s32 arg1);
    typedef struct ResistanceScanNode {
        u8 reserved000[0xA4];
        u16 id;
        u8 reserved0A6[0x9BE];
        u8 *data;
        u8 reservedA68[4];
        struct ResistanceScanNode *next;
    } ResistanceScanNode;
    s32 secondaryMessage;
    s32 primaryMessage;
    s32 enemyCount;
    s32 actorId;
    s32 hasSkill;
    s32 averageLevel;
    s32 referenceLevel;
    s32 levelAdvantage;
    ResistanceScanNode *firstNode;
    ResistanceScanNode *flagNode;
    u8 *metadata;
    u32 flags;

    enemyCount = func_001ef720(2, 0x80000) & 0xFFFF;
    if (enemyCount > 5) {
        return -1;
    }

    if (func_00106330(0x38) != 0) {
        actorId = 5;
    } else {
        actorId = 8;
    }
    hasSkill = func_0010ce10((u8 *)func_0010a900(actorId & 0xFFFF), 0x10D) != -1;

    averageLevel = func_001ef4d0(2, 0x80000) & 0xFFFF;
    referenceLevel = func_00231e20(*(u8 **)(*(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30) + 0xA64)) & 0xFF;
    levelAdvantage = (averageLevel - referenceLevel) >= 4;

    firstNode = *(ResistanceScanNode **)(iGpffffb3ac + 0x180);
    flagNode = firstNode;
    metadata = iGpffffb3c4;
    for (; flagNode != NULL; flagNode = flagNode->next) {
        flags = *(u16 *)(metadata + (flagNode->id * 0x3C));
        if ((flags & 0x40) != 0) {
            return 1;
        }
        if ((flags & 0x80) != 0) {
            return 0;
        }
    }

    if (hasSkill) {
        /* The first pass uses an element index; the second uses a node address. */
        uintptr_t scanPosition;

        secondaryMessage = -1;
        primaryMessage = secondaryMessage;

        {
            for (; firstNode != NULL; firstNode = firstNode->next) {
                for (scanPosition = 0; (s32)scanPosition < 8; scanPosition++) {
                    if ((func_00242800(firstNode->data, (s16)scanPosition) & 0x07000000) != 0) {
                        switch (scanPosition) {
                        case 0:
                            primaryMessage = 0x17;
                            break;
                        case 1:
                            primaryMessage = 0x18;
                            break;
                        case 2:
                            primaryMessage = 0x19;
                            break;
                        case 3:
                            primaryMessage = 0x1B;
                            break;
                        case 4:
                            primaryMessage = 0x1A;
                            break;
                        case 6:
                            primaryMessage = 0x1C;
                            break;
                        case 7:
                            primaryMessage = 0x1D;
                            break;
                        }
                    }
                }
            }
        }

        {
            s32 secondElement;

            for (scanPosition = (uintptr_t)*(ResistanceScanNode **)(iGpffffb3ac + 0x180);
                 scanPosition != 0;
                 scanPosition = (uintptr_t)((ResistanceScanNode *)scanPosition)->next) {
                for (secondElement = 0; secondElement < 8; secondElement++) {
                    if ((func_00242800(((ResistanceScanNode *)scanPosition)->data, (s16)secondElement) & 0x08000000) != 0) {
                        switch (secondElement) {
                        case 0:
                            secondaryMessage = 0x1E;
                            break;
                        case 1:
                            secondaryMessage = 0x1F;
                            break;
                        case 2:
                            secondaryMessage = 0x20;
                            break;
                        case 3:
                            secondaryMessage = 0x22;
                            break;
                        case 4:
                            secondaryMessage = 0x21;
                            break;
                        case 6:
                            secondaryMessage = 0x23;
                            break;
                        case 7:
                            secondaryMessage = 0x24;
                            break;
                        }
                    }
                }
            }
        }

        if (primaryMessage != -1) {
            return primaryMessage;
        }
        if (secondaryMessage != -1) {
            return secondaryMessage;
        }
    }

    if (levelAdvantage) {
        return 2;
    }

    switch (*(u16 *)(iGpffffb3ac + 0x1A)) {
    case 0:
        return enemyCount + 2;
    case 1:
        return enemyCount + 7;
    case 2:
        return enemyCount + 12;
    default:
        return -1;
    }
}
// FUN_001F3F60
s32 func_001f3f60(void)
{
    s32 state;

    state = *(s32 *)(iGpffffb3ac + 0xA58);
    if (state == 0xFC) {
        return -1;
    }
    if ((func_001ef720(1, 0x80000) & 0xFFFF) < 2) {
        return -1;
    }
    return 0xFC;
}

// FUN_001F3FE0
s32 func_001f3fe0(u8 *arg0)
{
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return -1;
    }
    return 0xCC;
}
// FUN_001F4010
s32 func_001f4010(u8 *arg0)
{
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return -1;
    }
    return 0x67;
}
// FUN_001F4040
s32 func_001f4040(u8 *arg0) {
    if (*(u8 *)((u8 *)(*(u8 **)(arg0 + 0x30)) + 0xA2) != 0) {
        return -1;
    }
    if (func_001f5ea0(0) != 0) {
        return 0xCD;
    }
    return 0xCE;
}

// FUN_001F40A0
s32 func_001f40a0(void) {
    s32 temp_3;

    temp_3 = func_001ef720(2, 0x80000) & 0xFFFF;
    if (temp_3 >= 5) {
        return -1;
    }
    if (temp_3 == 0) {
        return -1;
    }
    return 0x58 - temp_3;
}

// FUN_001F4100
s32 func_001f4100(u8 *arg0)
{
    u16 temp_2;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_3 + 0xA2) != 0) {
        return -1;
    }
    temp_2 = *(u16 *)(temp_3 + 0xA4);
    switch (temp_2) {
    case 1:
        return -1;
    case 2:
        return 0x15F;
    case 3:
        return 0x160;
    case 4:
        return 0x161;
    case 6:
        return 0x162;
    case 7:
        return 0x163;
    case 8:
        return 0x164;
    default:
        return -1;
    }
}
// FUN_001F41B0
s32 func_001f41b0(u8 *arg0)
{
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return -1;
    }
    return 0xCB;
}
// FUN_001F41E0
s32 func_001f41e0(void) {
    s32 temp_3;

    temp_3 = func_001ef720(2, 0x80000) & 0xFFFF;
    if (temp_3 > 5) {
        return -1;
    }
    if (temp_3 < 2) {
        return -1;
    }
    return 0x5E - temp_3;
}



// FUN_001F42A0
s32 func_001f42a0(s32 arg0) {
    if (*(s32 *)(iGpffffb3ac + 0x170) != arg0) {
        return -1;
    }
    return 0x173;
}
// FUN_001F42D0
s32 func_001f42d0(void) {
    if ((*(s32 *)(iGpffffb3ac + 0x10) & 0x20000000) != 0) {
        if (func_001ef9a0() == 0x20B) {
            return 0x18B;
        }
    }
    return 0x165;
}

// FUN_001F4330
s32 func_001f4330(u8 *arg0)
{
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return 0x99;
    }
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) == 1) {
        return 0x5D;
    }
    return -1;
}

// FUN_001F4380
s32 func_001f4380(u8 *arg0)
{
    u16 temp_2;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_3 + 0xA2) != 0) {
        return -1;
    }
    temp_2 = *(u16 *)(temp_3 + 0xA4);
    switch (temp_2) {
    case 1:
        return 0x68;
    case 2:
        return 0x69;
    case 3:
        return 0x6A;
    case 4:
        return 0x6B;
    case 6:
        return 0x6C;
    case 7:
        return 0x6D;
    case 8:
        return 0x6E;
    default:
        return -1;
    }
}
// FUN_001F4430
s32 func_001f4430(u8 *arg0, s32 arg1) {
    s32 temp_4;
    u16 temp_2;

    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return -1;
    }
    if (arg1 <= 0) {
        return -1;
    }
    if (!(func_001ef720(2, 0x80000) & 0xFFFF)) {
        return -1;
    }
    temp_4 = (5 - arg1) * 7;
    temp_2 = *(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4);
    switch (temp_2) {
    case 1:
        return temp_4 + 0xFD;
    case 2:
        return temp_4 + 0xFE;
    case 3:
        return temp_4 + 0xFF;
    case 4:
        return temp_4 + 0x100;
    case 6:
        return temp_4 + 0x101;
    case 7:
        return temp_4 + 0x102;
    case 8:
        return temp_4 + 0x103;
    default:
        return -1;
    }
}



// FUN_001F4550
s32 func_001f4550(u8 *arg0)
{
    u16 temp_2;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_3 + 0xA2) != 0) {
        return -1;
    }
    temp_2 = *(u16 *)(temp_3 + 0xA4);
    switch (temp_2) {
    case 1:
        return 0x3D;
    case 2:
        return 0x3E;
    case 3:
        return 0x3F;
    case 4:
        return 0x40;
    case 6:
        return 0x41;
    case 7:
        return 0x42;
    case 8:
        return 0x43;
    default:
        return -1;
    }
}
// FUN_001F4600
s32 func_001f4600(u8 *arg0)
{
    u16 temp_2;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_3 + 0xA2) != 0) {
        return -1;
    }
    temp_2 = *(u16 *)(temp_3 + 0xA4);
    switch (temp_2) {
    case 1:
        return 0x35;
    case 2:
        return 0x36;
    case 3:
        return 0x37;
    case 4:
        return 0x38;
    case 6:
        return 0x39;
    case 7:
        return 0x3A;
    case 8:
        return 0x3B;
    default:
        return -1;
    }
}
// FUN_001F46B0
s32 func_001f46b0(u8 *arg0)
{
    u16 temp_2;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_3 + 0xA2) != 0) {
        return -1;
    }
    temp_2 = *(u16 *)(temp_3 + 0xA4);
    switch (temp_2) {
    case 1:
        return 0x14A;
    case 2:
        return 0x14B;
    case 3:
        return 0x14C;
    case 4:
        return 0x14D;
    case 6:
        return 0x14E;
    case 7:
        return 0x14F;
    case 8:
        return 0x150;
    default:
        return -1;
    }
}
// FUN_001F4760
s32 func_001f4760(u8 *arg0)
{
    u16 temp_2;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_3 + 0xA2) != 0) {
        return -1;
    }
    temp_2 = *(u16 *)(temp_3 + 0xA4);
    switch (temp_2) {
    case 1:
        return 0x143;
    case 2:
        return 0x144;
    case 3:
        return 0x145;
    case 4:
        return 0x146;
    case 6:
        return 0x147;
    case 7:
        return 0x148;
    case 8:
        return 0x149;
    default:
        return -1;
    }
}
// FUN_001F4810
s32 func_001f4810(u8 *arg0, s32 arg1, s32 arg2) {
    s32 temp_4;

    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return -1;
    }
    if ((arg2 >= 6) || (arg2 <= 0)) {
        return -1;
    }
    if (arg2 == 1) {
        if ((arg1 & 2) && (func_00231d70(0x64) < 0x1E)) {
            s32 var_2_2;
            if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
                var_2_2 = -1;
            } else {
                switch (*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)) {
                case 1:
                    var_2_2 = 0x14A;
                    break;
                case 2:
                    var_2_2 = 0x14B;
                    break;
                case 3:
                    var_2_2 = 0x14C;
                    break;
                case 4:
                    var_2_2 = 0x14D;
                    break;
                case 6:
                    var_2_2 = 0x14E;
                    break;
                case 7:
                    var_2_2 = 0x14F;
                    break;
                case 8:
                    var_2_2 = 0x150;
                    break;
                default:
                    var_2_2 = -1;
                    break;
                }
            }
            return var_2_2;
        }
        if ((arg1 & 4) && (func_00231d70(0x64) < 0x1E)) {
            s32 var_2;
            if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
                var_2 = -1;
            } else {
                switch (*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)) {
                case 1:
                    var_2 = 0x143;
                    break;
                case 2:
                    var_2 = 0x144;
                    break;
                case 3:
                    var_2 = 0x145;
                    break;
                case 4:
                    var_2 = 0x146;
                    break;
                case 6:
                    var_2 = 0x147;
                    break;
                case 7:
                    var_2 = 0x148;
                    break;
                case 8:
                    var_2 = 0x149;
                    break;
                default:
                    var_2 = -1;
                    break;
                }
            }
            return var_2;
        }
    }
    temp_4 = (5 - arg2) * 7;
    switch (*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)) {
    case 1:
        return temp_4 + 0x120;
    case 2:
        return temp_4 + 0x121;
    case 3:
        return temp_4 + 0x122;
    case 4:
        return temp_4 + 0x123;
    case 6:
        return temp_4 + 0x124;
    case 7:
        return temp_4 + 0x125;
    case 8:
        return temp_4 + 0x126;
    default:
        return -1;
    }
}



// FUN_001F4AD0
s32 func_001f4ad0(u8 *arg0)
{
    u16 temp_2;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_3 + 0xA2) != 0) {
        return -1;
    }
    temp_2 = *(u16 *)(temp_3 + 0xA4);
    switch (temp_2) {
    case 1:
        return 0x158;
    case 2:
        return 0x159;
    case 3:
        return 0x15A;
    case 4:
        return 0x15B;
    case 6:
        return 0x15C;
    case 7:
        return 0x15D;
    case 8:
        return 0x15E;
    default:
        return -1;
    }
}
// FUN_001F4B80
s32 func_001f4b80(u8 *arg0)
{
    u16 temp_2;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_3 + 0xA2) != 0) {
        return -1;
    }
    temp_2 = *(u16 *)(temp_3 + 0xA4);
    switch (temp_2) {
    case 1:
        return 0x4D;
    case 2:
        return 0x4E;
    case 3:
        return 0x4F;
    case 4:
        return 0x50;
    case 6:
        return 0x51;
    case 7:
        return 0x52;
    case 8:
        return 0x53;
    default:
        return -1;
    }
}
// FUN_001F4C30
s32 func_001f4c30(u8 *arg0)
{
    u16 temp_2;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_3 + 0xA2) != 0) {
        return -1;
    }
    temp_2 = *(u16 *)(temp_3 + 0xA4);
    switch (temp_2) {
    case 1:
        return 0x2D;
    case 2:
        return 0x2E;
    case 3:
        return 0x2F;
    case 4:
        return 0x30;
    case 6:
        return 0x31;
    case 7:
        return 0x32;
    case 8:
        return 0x33;
    default:
        return -1;
    }
}
// FUN_001F4CE0
s32 func_001f4ce0(u8 *arg0)
{
    u16 temp_2;
    u16 temp_2_2;
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0x30);
    if (temp_4[0xA2] != 0) {
        return -1;
    }
    if ((*(s32 *)(iGpffffb3ac + 0x10) & 0x20000000) != 0) {
        if (func_001ef9a0() != 0x20B) {
            goto high_default_4ce0;
        }
        temp_2 = *(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4);
        switch (temp_2) {
        case 2:
            return 0x18C;
        case 3:
            return 0x18D;
        case 4:
            return 0x18E;
        case 6:
            return 0x18F;
        case 7:
            return 0x190;
        case 8:
            return 0x18A;
        case 0:
        case 1:
        case 5:
        default:
            goto high_default_4ce0;
        }
    }
    goto low_switch_4ce0;
high_default_4ce0:
    return -1;
low_switch_4ce0:
    temp_2_2 = *(u16 *)(temp_4 + 0xA4);
    switch (temp_2_2) {
    case 2:
        return 0x26;
    case 3:
        return 0x27;
    case 4:
        return 0x28;
    case 6:
        return 0x29;
    case 7:
        return 0x2A;
    case 8:
        return 0x2B;
    case 0:
    case 1:
    case 5:
    default:
        return -1;
    }
}
extern u32 func_00242930(s32 unit);
extern u8 *func_001b0c80(s32 arg0);
/* Native b210 -O2 recovery: 1876 bytes plus 12 zero tail bytes.
   Each selected field has its own uintptr_t address, derived from that
   field's array base. The byte offset stays live across the previous-code
   check; the actor address is formed after recording the selected code.
   This preserves both addiu/LH-at-zero pairs and the signed actor guard.
   The owned nine-entry switch table resolves to retail at 0x00747500.
   See docs/probe_archive/BattleAction_20260922_resume.md. */
// FUN_001F4E50
s64 func_001f4e50(u8 *arg0) {
    struct ActionMessageChoice {
        s16 code;
        s16 actor;
    } choices[64];
    s16 selectedCode;
    u8 *unit;
    s32 choiceCount;
    s32 code8ACount;
    s32 enemyCount;
    u8 *battle;

    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return -1;
    }
    choiceCount = 0;
    code8ACount = 0;
    battle = iGpffffb3ac;
    unit = *(u8 **)(battle + 0x178);
    while (unit != NULL) {
        if (func_002428f0((s32)(*(u8 **)(unit + 0xA64)), 0) == 0) {
            u8 *unitWork = (u8 *)func_001b0c80((s32)unit);
            if ((unitWork == NULL) || !(*(u16 *)(unitWork + 0x18) & 0x20)) {
                if (func_00242930((s32)((void *)*(u8 **)(unit + 0xA64))) != 0) {
                    struct ActionMessageChoice *choice = &choices[choiceCount & 0xFFFF];
                    choice->code = 0x8A;
                    choice->actor = *(u16 *)(unit + 0xA4);
                    choiceCount = (choiceCount + 1) & 0xFFFF;
                    code8ACount = (code8ACount + 1) & 0xFFFF;
                }
                if (*(u16 *)(unit + 0xA4) != 1) {
                    if (func_00232710(*(s32 *)(unit + 0xA64), 0x10) != 0) {
                        struct ActionMessageChoice *choice = &choices[choiceCount & 0xFFFF];
                        choice->code = 0x99;
                        choice->actor = *(u16 *)(unit + 0xA4);
                        choiceCount = (choiceCount + 1) & 0xFFFF;
                    } else if (func_00232710(*(s32 *)(unit + 0xA64), 0x20) != 0) {
                        struct ActionMessageChoice *choice = &choices[choiceCount & 0xFFFF];
                        choice->code = 0x9f;
                        choice->actor = *(u16 *)(unit + 0xA4);
                        choiceCount = (choiceCount + 1) & 0xFFFF;
                    } else if (func_00232710(*(s32 *)(unit + 0xA64), 0x4) != 0) {
                        struct ActionMessageChoice *choice = &choices[choiceCount & 0xFFFF];
                        choice->code = 0xa5;
                        choice->actor = *(u16 *)(unit + 0xA4);
                        choiceCount = (choiceCount + 1) & 0xFFFF;
                    } else if (func_00232710(*(s32 *)(unit + 0xA64), 0x2) != 0) {
                        struct ActionMessageChoice *choice = &choices[choiceCount & 0xFFFF];
                        choice->code = 0xab;
                        choice->actor = *(u16 *)(unit + 0xA4);
                        choiceCount = (choiceCount + 1) & 0xFFFF;
                    } else if (func_00232710(*(s32 *)(unit + 0xA64), 0x1) != 0) {
                        struct ActionMessageChoice *choice = &choices[choiceCount & 0xFFFF];
                        choice->code = 0xb1;
                        choice->actor = *(u16 *)(unit + 0xA4);
                        choiceCount = (choiceCount + 1) & 0xFFFF;
                    } else if (func_00232710(*(s32 *)(unit + 0xA64), 0x40) != 0) {
                        struct ActionMessageChoice *choice = &choices[choiceCount & 0xFFFF];
                        choice->code = 0xb7;
                        choice->actor = *(u16 *)(unit + 0xA4);
                        choiceCount = (choiceCount + 1) & 0xFFFF;
                    } else if (func_00232710(*(s32 *)(unit + 0xA64), 0x80) != 0) {
                        struct ActionMessageChoice *choice = &choices[choiceCount & 0xFFFF];
                        choice->code = 0xbd;
                        choice->actor = *(u16 *)(unit + 0xA4);
                        choiceCount = (choiceCount + 1) & 0xFFFF;
                    } else if (func_00232710(*(s32 *)(unit + 0xA64), 0x8) != 0) {
                        struct ActionMessageChoice *choice = &choices[choiceCount & 0xFFFF];
                        choice->code = 0xc3;
                        choice->actor = *(u16 *)(unit + 0xA4);
                        choiceCount = (choiceCount + 1) & 0xFFFF;
                    }
                }
                if (func_002340c0((u8 *)(*(s32 *)(unit + 0xA64)), 0xA) != 0) {
                    struct ActionMessageChoice *choice = &choices[choiceCount & 0xFFFF];
                    choice->code = 0x6F;
                    choice->actor = *(u16 *)(unit + 0xA4);
                    choiceCount = (choiceCount + 1) & 0xFFFF;
                }
                if (func_002340c0((u8 *)(*(s32 *)(unit + 0xA64)), 0x80) != 0) {
                    struct ActionMessageChoice *choice = &choices[choiceCount & 0xFFFF];
                    choice->code = 0x76;
                    choice->actor = *(u16 *)(unit + 0xA4);
                    choiceCount = (choiceCount + 1) & 0xFFFF;
                }
                if (func_002340c0((u8 *)(*(s32 *)(unit + 0xA64)), 0x220) != 0) {
                    struct ActionMessageChoice *choice = &choices[choiceCount & 0xFFFF];
                    choice->code = 0x7D;
                    choice->actor = *(u16 *)(unit + 0xA4);
                    choiceCount = (choiceCount + 1) & 0xFFFF;
                }
            }
        }
        unit = *(u8 **)(unit + 0xA6C);
    }
    {
        u8 *sourceUnit = *(u8 **)(arg0 + 0x30);
        if (*(u16 *)(sourceUnit + 0xA4) == 1) {
            if (func_00232710(*(s32 *)(sourceUnit + 0xA64), 0x20) != 0) {
                choices[choiceCount & 0xFFFF].code = 0x92;
                choices[choiceCount & 0xFFFF].actor = -1;
                choiceCount = (choiceCount + 1) & 0xFFFF;
            } else if (func_00232710(*(s32 *)(sourceUnit + 0xA64), 0x2) != 0) {
                choices[choiceCount & 0xFFFF].code = 0x94;
                choices[choiceCount & 0xFFFF].actor = -1;
                choiceCount = (choiceCount + 1) & 0xFFFF;
            } else if (func_00232710(*(s32 *)(sourceUnit + 0xA64), 0x1) != 0) {
                choices[choiceCount & 0xFFFF].code = 0x95;
                choices[choiceCount & 0xFFFF].actor = -1;
                choiceCount = (choiceCount + 1) & 0xFFFF;
            } else if (func_00232710(*(s32 *)(sourceUnit + 0xA64), 0x40) != 0) {
                choices[choiceCount & 0xFFFF].code = 0x96;
                choices[choiceCount & 0xFFFF].actor = -1;
                choiceCount = (choiceCount + 1) & 0xFFFF;
            } else if (func_00232710(*(s32 *)(sourceUnit + 0xA64), 0x80) != 0) {
                choices[choiceCount & 0xFFFF].code = 0x97;
                choices[choiceCount & 0xFFFF].actor = -1;
                choiceCount = (choiceCount + 1) & 0xFFFF;
            } else if (func_00232710(*(s32 *)(sourceUnit + 0xA64), 0x8) != 0) {
                choices[choiceCount & 0xFFFF].code = 0x98;
                choices[choiceCount & 0xFFFF].actor = -1;
                choiceCount = (choiceCount + 1) & 0xFFFF;
            }
        }
    }
    if ((code8ACount & 0xFFFF) >= 2) {
        choices[choiceCount & 0xFFFF].code = 0x89;
        choices[choiceCount & 0xFFFF].actor = -1;
        choiceCount = (choiceCount + 1) & 0xFFFF;
    }
    enemyCount = func_001ef720(2, 0x80000) & 0xFFFF;
    {
        u8 *battleCounts = iGpffffb3ac;
        s16 *savedEnemyCount = (s16 *)(battleCounts + 0xA6C);
        if (*(s16 *)(battleCounts + 0xA6C) == enemyCount) {
            if ((enemyCount < 6) && (enemyCount > 0)) {
                choices[choiceCount & 0xFFFF].code = 0x89 - enemyCount;
                choices[choiceCount & 0xFFFF].actor = -1;
                choiceCount = (choiceCount + 1) & 0xFFFF;
            }
        } else {
            *savedEnemyCount = enemyCount;
        }
    }
    if ((choiceCount & 0xFFFF) <= 0) {
        return -1;
    }
    {
        u32 selectedOffset = (func_00231d70(choiceCount & 0xFFFF) & 0xFFFF) * 4;
        /* These are two field addresses within the same selected row. */
        uintptr_t codeAddress = (uintptr_t)((u8 *)choices + selectedOffset);
        s16 actorId;
        uintptr_t actorAddress;
        u8 *battleSelection;
        s32 *previousCode;
        selectedCode = *(s16 *)codeAddress;
        battleSelection = iGpffffb3ac;
        previousCode = (s32 *)(battleSelection + 0xA68);
        if (*(s32 *)(battleSelection + 0xA68) == selectedCode) {
            return -1;
        }
        *previousCode = selectedCode;
        actorAddress = (uintptr_t)((u8 *)&choices[0].actor + selectedOffset);
        actorId = *(s16 *)actorAddress;
        if (actorId >= 0) {
            switch (actorId) {
            case 2:
                selectedCode = selectedCode + 1;
                break;
            case 3:
                selectedCode = selectedCode + 2;
                break;
            case 4:
                selectedCode = selectedCode + 3;
                break;
            case 6:
                selectedCode = selectedCode + 4;
                break;
            case 7:
                selectedCode = selectedCode + 5;
                break;
            case 8:
                selectedCode = selectedCode + 6;
                break;
            }
        }
    }
    return selectedCode;
}
// FUN_001F55B0
s32 func_001f55b0(u8 *arg0)
{
    u8 *work;

    if (*(u8 **)(iGpffffb3ac + 0x170) != arg0) {
        return -1;
    }
    work = *(u8 **)(arg0 + 0x30);
    switch (*(u16 *)(arg0 + 0x6C)) {
    case 0xB:
        if (func_00232710(*(s32 *)(work + 0xA64), 0x10) != 0) {
            return 0x91;
        }
        if (func_00232710(*(s32 *)(work + 0xA64), 4) != 0) {
            return 0x93;
        }
        if (func_00232710(*(s32 *)(work + 0xA64), 2) != 0) {
            return 0x94;
        }
        break;
    default:
        break;
    }
    return -1;
}
// FUN_001F5680
/* The `return -1` and `return v + 0x11` blocks are reached by goto so they
   land in retail's order; writing both as plain returns emits them the other
   way round. */
s32 func_001f5680(void) {
    u8 *p;
    s32 v;

    p = *(u8 **)(iGpffffb3ac + 0xC68);
    if (p == NULL) {
        return -1;
    }
    v = *(u16 *)(p + 2);
    if (v < 6) {
        if (v != 0) {
            goto add;
        }
    }
    return -1;
add:
    return v + 0x11;
}
// FUN_001F56D0
s32 func_001f56d0(s32 arg0, u16 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 flags;
    s32 mode;
    s32 index;
    s32 value;
    s32 (*callback)(s32, s32, s32, s32);
    s32 result;
    u8 *table;

    extern s32 (*D_0060AB20[])(s32, s32, s32, s32);
    extern s32 func_001f6220(u16, s32);

    flags = *(s32 *)(iGpffffb3ac + 0xC);
    if ((flags & 0x1000000) == 0) {
        return 1;
    }
    if (*(u16 *)(iGpffffb3ac + 0xA50) != 0) {
        return 0;
    }
    mode = arg4 & 6;
    if ((mode == 0) && ((*(u16 *)(iGpffffb3ac + 0xA4E) & 1) != 0)) {
        return 1;
    }
    table = iGpffffb414 + (*(u16 *)(*(u8 **)(iGpffffb3ac + 0xC68) + 8) * 0x18);
    if ((*(s32 *)table & 0x400) != 0) {
        return 1;
    }
    if ((*(u16 *)(iGpffffb3ac + 0xA4E) & 1) != 0) {
        index = arg1 & 0xFFFF;
        if (*(s16 *)(iGpffffb3ac + 0xA5C) == index) {
            return 1;
        }
        if (*(s16 *)(iGpffffb3ac + 0xA64) == index) {
            return 1;
        }
    }
    callback = D_0060AB20[arg1 & 0xFFFF];
    if (callback == NULL) {
        return 1;
    }
    value = callback(arg0, arg2, arg3, 0);
    if (value < 0) {
        return 1;
    }
    if ((*(s32 *)table & 0x1000) != 0) {
        u8 *pool;
        u8 *entries;
        s32 slot;
        pool = *(u8 **)(iGpffffb3ac + 0xA54);
        slot = value & 0xFFFF;
        entries = *(u8 **)(pool + 0x110);
        if (*(u8 *)(entries + slot * 0xC) != 0) {
            return 1;
        }
    }
    if ((arg4 & 2) != 0) {
        func_001f62b0();
        *(u16 *)(iGpffffb3ac + 0xA6E) = 2;
    } else {
        *(u16 *)(iGpffffb3ac + 0xA6E) = 0;
    }
    result = func_001f6220(arg1, value);
    return result;
}
// FUN_001F58D0
void func_001f58d0(void)
{
    s16 temp_2;
    u8 *state_ptr;
    u8 *temp_2_ptr;
    u8 *temp_16;
    u8 *temp_4;
    u16 temp_3;
    u8 *temp_3_2;
    u8 *temp_3_3;
    u8 *temp_3_4;
    u8 *temp_3_5;
    u8 *temp_4_2;
    u8 *temp_6;

    temp_6 = iGpffffb3ac;
    state_ptr = temp_6 + 0xA50;
    temp_3 = *(u16 *)state_ptr;
    switch (temp_3) {
    case 0:
        goto done;
    case 1:
        goto case1;
    case 2:
        goto case2;
    default:
        goto done;
    }
case1:
    temp_2_ptr = temp_6 + 0xA6E;
    temp_2 = *(s16 *)temp_2_ptr;
    if (temp_2 > 0) {
        *(s16 *)temp_2_ptr = (s16)(temp_2 - 1);
        goto done;
    }
    *(u16 *)state_ptr = 2;
case2:
    temp_3_2 = iGpffffb3ac;
    temp_4 = *(u8 **)(*(u8 **)(temp_3_2 + 0xA54) + 0x110);
    temp_16 = temp_4 + ((s32 *)(temp_4 + 4))[*(u16 *)(temp_3_2 + 0xA60) * 3];
    func_002bd270(temp_16, state_ptr, temp_6);
    func_002bd280(*(u16 *)(iGpffffb3ac + 0xA4C),
                  func_00231d70(func_002777a0(temp_16)), 0, 0);
    temp_3_3 = iGpffffb3ac;
    *(s32 *)(temp_3_3 + 0xA58) = *(s32 *)(temp_3_3 + 0xA60);
    temp_3_4 = iGpffffb3ac;
    *(s16 *)(temp_3_4 + 0xA5C) = *(s16 *)(temp_3_4 + 0xA64);
    temp_3_5 = iGpffffb3ac;
    *(u16 *)(temp_3_5 + 0xA4E) =
        (u16)(*(u16 *)(temp_3_5 + 0xA4E) | 1);
    *(u16 *)(iGpffffb3ac + 0xA50) = 0;
done:
    if (func_002bd340() == 0) {
        temp_4_2 = iGpffffb3ac;
        *(u16 *)(temp_4_2 + 0xA4E) =
            (u16)(*(u16 *)(temp_4_2 + 0xA4E) & 0xFFFE);
    }
}
// FUN_001F5A00
void func_001f5a00(s32 arg0)
{
    extern s32 func_001b1540(void);
    extern s32 func_001b1550(void);
    extern s32 func_001b0e30(s32 arg0);
    s32 i;
    s32 result;
    u8 *current;
    u8 *global;

    result = 0;
    i = 0;
    while (((i & 0xFFFF) <= 0) && (result == 0)) {
        if ((*(u16 *)(iGpffffb3ac + 0xA48) &
             ((1 << (i & 0xFFFF)) & 0xFFFF)) != 0) {
            switch (((1 << (i & 0xFFFF)) & 0xFFFF)) {
            case 1:
                current = (u8 *)func_001b1540();
                if ((current != NULL) &&
                    ((*(u16 *)(current + 0x1A) & 1) != 0) &&
                    (arg0 != 0) &&
                    (*(u8 *)(*(u8 **)(current + 0x30) + 0xA2) == 0)) {
                    *(u16 *)(iGpffffb3ac + ((i & 0xFFFF) * 4) + 0xA44) =
                        (u16)(*(u16 *)(iGpffffb3ac +
                                       ((i & 0xFFFF) * 4) + 0xA44) + 1);
                    if ((arg0 != 0) &&
                        (*(u16 *)(iGpffffb3ac +
                                  ((i & 0xFFFF) * 4) + 0xA46) >= 4) &&
                        (*(u16 *)(iGpffffb3ac +
                                  ((i & 0xFFFF) * 4) + 0xA44) ==
                         (*(u16 *)(iGpffffb3ac +
                                   ((i & 0xFFFF) * 4) + 0xA46) >> 1))) {
                        func_001f56d0(
                            *(s32 *)(iGpffffb3ac + 0x170), 4, 0, 0, 4);
                    } else {
                        global = iGpffffb3ac;
                        if ((*(u16 *)(global +
                                      ((i & 0xFFFF) * 4) + 0xA44) >=
                             *(u16 *)(global +
                                      ((i & 0xFFFF) * 4) + 0xA46)) &&
                            (func_00232710(
                                 *(s32 *)(*(u8 **)(*(u8 **)(global + 0x170) +
                                                   0x30) + 0xA64),
                                 0x180010) == 0) &&
                            (func_001b1550() == 0)) {
                            *(u16 *)(*(u8 **)(iGpffffb3ac + 0x170) + 0x16) =
                                0x1C;
                            func_001b0e30(
                                *(s32 *)(iGpffffb3ac + 0x170));
                            result = 1;
                            *(u16 *)(iGpffffb3ac + 0xA48) =
                                (u16)(*(u16 *)(iGpffffb3ac + 0xA48) &
                                      0xFFFE);
                        }
                    }
                }
                break;
            default:
                break;
            }
        }
        i = (i + 1) & 0xFFFF;
    }
}
/* measured: 708/720B MATCH; the remaining 12 bytes are zero tail padding.
   Paired group statistics stay in FPRs and preserve the retail operation
   tree and unsigned conversions without additional storage. */
// FUN_001F5BD0
#pragma push
#pragma opt_propagation off
void func_001f5bd0(s32 arg0)
{
    u32 mask;
    unsigned int random_value;
    struct { f32 stat3; f32 stat4; } group1, group2;
    f32 random_ratio;
    f32 ratio;
    u16 result;

    mask = ((1 << (u16)arg0) & 0xFFFF);
    *(u16 *)(iGpffffb3ac + 0xA48) =
        (u16)(*(u16 *)(iGpffffb3ac + 0xA48) | mask);
    switch ((u16)arg0) {
    case 0:
        goto body;
    default:
        goto done;
    }
body:
    group1.stat3 = (f32)(u32)func_001ef5f0(1, 3, 0x80000);
    group2.stat3 = (f32)(u32)func_001ef5f0(2, 3, 0x80000);
    group1.stat4 = (f32)(u32)func_001ef5f0(1, 4, 0x80000);
    group2.stat4 = (f32)(u32)func_001ef5f0(2, 4, 0x80000);

    random_value = func_00231d70(0xF) + 5;
    random_ratio = (f32)random_value;
    random_ratio /= 10.0f;
    ratio = random_ratio * (30.0f * ((group1.stat3 / group2.stat3) * (group1.stat4 / group2.stat4)));
    if (ratio > 50.0f) {
        ratio = 50.0f;
    } else if (ratio < 10.0f) {
        ratio = 10.0f;
    }
    {
        s32 offset;
        u8 *p;
        offset = (u16)arg0 * 4;
        p = (u8 *)(offset + (s32)iGpffffb3ac);
        *(u16 *)(p + 0xA44) = 0;
        result = (u16)(100.0f / ratio);
        offset = (u16)arg0 * 4;
        p = (u8 *)(offset + (s32)iGpffffb3ac);
        *(u16 *)(p + 0xA46) = result;
    }
done:
    ;
}
#pragma opt_propagation on
#pragma pop

// FUN_001F5EA0
s32 func_001f5ea0(s32 arg0) {
    return (s32)((*(u16 *)((u8 *)iGpffffb3ac + 0xA48) & (1 << (arg0 & 0xFFFF))) != 0);
}



// FUN_001F5ED0
s32 func_001f5ed0(u8 *arg0)
{
    s32 result;
    u8 *global;

    if (*(s32 *)(arg0 + 0x14) == 0) {
        *(s32 *)(arg0 + 0x14) = func_001f56d0(
            *(s32 *)(arg0 + 0),
            *(u16 *)(arg0 + 4),
            *(s32 *)(arg0 + 8),
            *(s32 *)(arg0 + 0xC),
            *(s32 *)(arg0 + 0x10));
    }
    result = *(s32 *)(arg0 + 0x14);
    if ((result == 1) && (*(s32 *)(arg0 + 0x10) & 1) != 0) {
        global = iGpffffb3ac;
        if (((*(u16 *)(global + 0xA4E) & 1) != 0) ||
            (*(u16 *)(global + 0xA50) != 0)) {
            result = 0;
        }
    }
    return result;
}
// FUN_001F6090
s32 func_001f6090(void)
{
    func_001f62b0();
    return 1;
}

// FUN_001F6100
void func_001f6100(void)
{
    func_0043f9c8(iGpffffb3ac + 0xA44, 0, 0x2C);
    *(s32 *)(iGpffffb3ac + 0xA54) = 0;
    *(s32 *)(iGpffffb3ac + 0xA58) = -1;
    *(s16 *)(iGpffffb3ac + 0xA5C) = -1;
    *(s32 *)(iGpffffb3ac + 0xA60) = -1;
    *(s16 *)(iGpffffb3ac + 0xA64) = -1;
    *(s32 *)(iGpffffb3ac + 0xA68) = -1;
    *(s16 *)(iGpffffb3ac + 0xA6C) = -1;
    *(s16 *)(iGpffffb3ac + 0xA50) = 0;
    *(s16 *)(iGpffffb3ac + 0xA4E) = 0;
    *(s16 *)(iGpffffb3ac + 0xA4C) = 8;
    *(s16 *)(iGpffffb3ac + 0xA6E) = 0;
}
// FUN_001F6190
void func_001f6190(void)
{
    func_001f58d0();
}

// FUN_001F61B0
void func_001f61b0(void)
{
    u8 *temp_3;
    u8 *var_4;

    var_4 = *(u8 **)(iGpffffb3ac + 0xA54);
    if (var_4 != NULL) {
        func_00454bd0(var_4);
        *(u8 **)(iGpffffb3ac + 0xA54) = NULL;
        temp_3 = iGpffffb3ac;
        *(s32 *)(temp_3 + 0xC) = *(s32 *)(temp_3 + 0xC) & 0xFEFFFFFF;
    }
    temp_3 = iGpffffb3ac;
    *(u16 *)(temp_3 + 0xA4E) = *(u16 *)(temp_3 + 0xA4E) & 0xFFFE;
    func_002bd3c0();
}

// FUN_001F6220
s32 func_001f6220(s16 arg0, s32 arg1)
{
    u8 *temp_3;

    temp_3 = iGpffffb3ac;
    if ((*(u16 *)(temp_3 + 0xA4E) & 1) != 0) {
        if (*(s32 *)(temp_3 + 0xA58) == arg1) {
            return 1;
        }
        if (*(s32 *)(temp_3 + 0xA60) == arg1) {
            return 1;
        }
    }
    *(s16 *)(temp_3 + 0xA64) = arg0;
    *(s32 *)(iGpffffb3ac + 0xA60) = arg1;
    *(s16 *)(iGpffffb3ac + 0xA50) = 1;
    return 1;
}

// FUN_001F6290
s32 func_001f6290(void) {
    return (s32)((*(u16 *)((u8 *)iGpffffb3ac + 0xA4E) & 1) != 0);
}



// FUN_001F62B0
void func_001f62b0(void) {
    u8 *temp_4;

    func_002bd3e0();
    func_002bd410();
    *(s16 *)(iGpffffb3ac + 0xA50) = 0;
    temp_4 = iGpffffb3ac;
    *(u16 *)(temp_4 + 0xA4E) &= 0xFFFE;
}
/* 728/736 bytes; thirteen resolved code relocations and seven jump-table
 * entries; eight zero tail bytes. Preserve eligibility-argument timing. */
struct EffRandState;

static inline s32 battleMessageBand(s32 value, s32 band)
{
    return value + band;
}

// FUN_001F62F0
s32 func_001f62f0(u8 *arg0)
{
    extern s32 func_001ef4d0(s32 arg0, s32 arg1);
    extern s32 func_00231e20(u8 *arg0);
    extern s32 func_0023a6b0(u8 *arg0, s32 arg1);
    extern u32 effMiscRand(struct EffRandState *state);
    s32 code;
    s32 base;
    s32 random;
    u16 mode;
    u16 count;
    s16 i;
    s32 flags;
    s32 offset;
    u16 values[8];

    base = func_00106330(0x38) != 0 ? 0xFA : 0xC8;
    random = func_001ef4d0(2, 0x80000) & 0xFFFF;
    flags = func_00231e20(
        *(u8 **)(*(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30) + 0xA64)) &
        0xFF;
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) != 0) {
        mode = 0;
    } else if ((random - flags) >= 4) {
        mode = 0;
    } else if ((flags - random) >= 4) {
        mode = 2;
    } else {
        mode = 1;
    }
    count = 0;
    i = 0;
    offset = mode * 0x1E;
    for (; i < 7; i++) {
        switch (i) {
        case 0:
            code = 0;
            break;
        case 1:
            code = 1;
            break;
        case 2:
            code = 2;
            break;
        case 3:
            code = 4;
            break;
        case 4:
            code = 3;
            break;
        case 5:
            code = 6;
            break;
        case 6:
            code = 7;
            break;
        default:
            break;
        }
        if ((*(u8 *)(arg0 + 0xA2) != 1) ||
            ((flags = (u16)code, func_001f0950(*(u16 *)(arg0 + 0xA4), flags)) != 0)) {
            flags = func_0023a6b0(*(u8 **)(arg0 + 0xA64), code);
            if ((flags & 0x08000000) != 0) {
                values[count++] =
                    (u16)(battleMessageBand(base + (i * 2), offset) + 2 +
                          (effMiscRand(NULL) & 1));
            } else if ((flags & 0x07000000) != 0) {
                values[count++] =
                    (u16)(battleMessageBand(base + (i * 2), offset) + 2 +
                          (effMiscRand(NULL) & 1) + 0xE);
            }
        }
    }
    if (count > 0) {
        return values[func_00231d70(count)];
    }
    return base + (effMiscRand(NULL) & 1) + offset;
}
// FUN_001F65D0
s32 func_001f65d0(u8 *arg0)
{
    extern void func_002bd240(u32 arg0);
    extern void func_00440b68();
    extern s32 func_00454a60();
    extern u8 iGpffffa4e8;
    extern u8 iGpffffa4e0;
    extern u8 D_0060ABE8[];
    u16 temp_3;
    u16 var_3;
    u8 *temp_4;

    temp_3 = *(u16 *)(arg0 + 6);
    switch (temp_3) {
    case 0:
        if (*(u16 *)(arg0 + 4) == 0) {
            var_3 = 8;
        } else {
            var_3 = 5;
        }
        *(u16 *)(iGpffffb3ac + 0xA4C) = var_3;
    case 1:
        func_00440b68(&iGpffffa4e8, D_0060ABE8, 0x713);
        *(s32 *)(iGpffffb3ac + 0xA54) =
            func_00454a60(
                *(u8 **)((u8 *)&iGpffffa4e0 +
                         (*(u16 *)(arg0 + 4) * 4)),
                0);
        *(u16 *)(arg0 + 6) = 2;
        goto block_14;
    case 2:
        if (func_004553c0(*(u8 **)(iGpffffb3ac + 0xA54)) != 0) {
    case 3:
            func_002bd240(
                (1 << *(u16 *)(iGpffffb3ac + 0xA4C)) | 1);
            *(u16 *)(arg0 + 6) = 4;
    case 4:
            temp_4 = iGpffffb3ac;
            *(s32 *)(temp_4 + 0xC) =
                *(s32 *)(temp_4 + 0xC) | 0x01000000;
            return 1;
        }
        goto block_14;
    block_14:
    default:
        return 0;
    }
}
// FUN_001F6710
u8 *func_001f6710(s32 arg0) {
    u8 *p;
    u8 *q;

    p = (u8 *)func_00194470(0x803, 8);
    p[0x47] &= 0xFE;
    *(void **)(p + 0x6C) = (void *)func_001f65d0;
    q = *(u8 **)(p + 0x78);
    *(s16 *)(q + 4) = (s16)arg0;
    *(s16 *)(q + 6) = 0;
    return p;
}

/* measured: opt_loop_invariants on hoists the loop's one constant before the entry test. */
#pragma opt_loop_invariants on
// FUN_001F6770
s32 func_001f6770(u8 *arg0)
{
    extern u32 func_00231d70(s32 arg0);
    extern s32 func_00232730(u8 *arg0, s32 arg1);
    u16 chance;
    u8 *status;
    u32 mask;
    u32 one;
    u32 i;

    status = *(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64);
    if (func_00232710((s32)status, 0x100000) != 0) {
        return 1;
    }
    if (func_00232710((s32)status, 0x1001DF) == 0) {
        return 0;
    }
    chance = 100;
    mask = 0;
    switch (func_002326c0(status)) {
    case 4:
        chance = 70;
        mask = 4;
        break;
    default:
        break;
    }
    chance &= 0xFFFF;
    if (chance == 100) {
        return 1;
    }
    chance = func_00231d70(100) < chance;
    if (chance == 0 && func_00232730(status, 0x230) != 0) {
        one = 1;
        i = 0;
        while (i < 0x18U) {
            if ((mask & (one << i)) != 0) {
                if (*(u8 *)((u8 *)addOffsetFirst(i, (u32)arg0) + 0x3F6) > 0) {
                    return 1;
                }
                *(u8 *)((u8 *)addOffsetFirst(i, (u32)arg0) + 0x3F6) += 1;
                break;
            }
            i++;
        }
    }
    return chance;
}
/* measured: close opt_loop_invariants after func_001f6770. */
#pragma opt_loop_invariants off
// FUN_001F68E0
s32 func_001f68e0(u8 *arg0)
{
    u8 *unit;
    s32 status;

    unit = *(u8 **)(arg0 + 0x30);
    status = *(s32 *)(unit + 0xA64);
    if ((*(u16 *)(arg0 + 0x18) & 4) != 0) {
        return 0;
    }
    return (func_00232710(status, 0x60) != 0);
}

/* measured: every instruction matches and the object is exactly the 80-byte
   window; the only residual is that retail materialises the shift constant
   (`addiu $v1,$zero,1`) BEFORE the branch into the loop test while b210 puts
   it after, which also shifts the back-edge displacement by one word (nd 9).
   Measured identical at nd 9: an inline `1 << i`, a hoisted `one` local, and
   an explicit goto loop with the test at the bottom. Preheader hoist-order
   floor. Committed at nd 9. */

#pragma push
#pragma opt_propagation off
// FUN_001F6930
s32 func_001f6930(u8 *arg0)
{
    extern s32 func_00232730(s32 arg0, s32 arg1);
    extern s32 func_00244f60(u32 arg0, u16 *arg1, u16 *arg2, u16 arg3, s32 arg4);
    s32 var_22;
    u32 var_21;
    s32 var_20;
    s32 var_19;
    s32 var_3;
    u8 *temp_17;
    s32 temp_16;
    s32 temp_30;
    u16 *temp_5;
    u16 *temp_5_2;
    u16 *temp_5_3;
    u16 *temp_5_4;
    u16 *temp_5_5;
    u16 *temp_5_6;
    s32 temp_3;

    temp_17 = *(u8 **)(arg0 + 0x30);
    temp_30 = func_002326e0(*(s32 *)(temp_17 + 0xA64));
    var_22 = 0;
    var_21 = 0;
    goto loop_31_test;
loop_31_body:
    var_3 = 1;
    temp_16 = 1 << var_21;
    if (temp_30 & temp_16) {
        switch (temp_16) {
        case 0x10:
            temp_5 = *(u16 **)(temp_17 + 0xA64);
            var_20 = func_00244f60(8, temp_5, temp_5, 0xFFFF, 0x10);
            var_19 = 3;
            temp_3 = var_3;
            break;
        case 0x4:
            temp_5_2 = *(u16 **)(temp_17 + 0xA64);
            var_20 = func_00244f60(8, temp_5_2, temp_5_2, 0xFFFF, 4);
            var_19 = 3;
            temp_3 = var_3;
            break;
        case 0x2:
            temp_5_3 = *(u16 **)(temp_17 + 0xA64);
            var_20 = func_00244f60(8, temp_5_3, temp_5_3, 0xFFFF, 2);
            var_19 = 3;
            temp_3 = var_3;
            break;
        case 0x40:
            temp_5_4 = *(u16 **)(temp_17 + 0xA64);
            var_20 = func_00244f60(8, temp_5_4, temp_5_4, 0xFFFF, 0x40);
            var_19 = 3;
            temp_3 = var_3;
            break;
        case 0x80:
            temp_5_5 = *(u16 **)(temp_17 + 0xA64);
            var_20 = func_00244f60(8, temp_5_5, temp_5_5, 0xFFFF, 0x80);
            var_19 = 6;
            temp_3 = var_3;
            break;
        case 8:
            temp_5_6 = *(u16 **)(temp_17 + 0xA64);
            var_20 = func_00244f60(8, temp_5_6, temp_5_6, 0xFFFF, 8);
            var_19 = 6;
            temp_3 = var_3;
            break;
        default:
            var_20 = 0;
            var_19 = 0;
            temp_3 = 0;
            break;
        }
        if ((temp_3 == 1) && (var_19 != 0)) {
            if (func_00232730(*(s32 *)(temp_17 + 0xA64), 0x22F) != 0) {
                var_19 = var_19 >> 1;
                if (var_19 <= 0) {
                    var_19 = 1;
                }
            }
            if (func_00232730(*(s32 *)(temp_17 + 0xA64), 0x230) != 0) {
                var_19 = 1;
            }
        }
        if (var_3 == 1) {
            if (*(u8 *)(arg0 + var_21 + 0x3F6) <= 1) {
                goto loop_31_increment;
            }
        }
        if ((*(u8 *)(arg0 + var_21 + 0x3F6) >= var_19) && (var_19 != 0)) {
            var_22 |= temp_16;
        } else if ((s32)func_00231d70(0x64) < var_20) {
            var_22 |= temp_16;
        }
    }
loop_31_increment:
    var_21 += 1;
loop_31_test:
    if (var_21 < 0x18U) {
        goto loop_31_body;
    }
    return var_22;
}
#pragma opt_propagation on
#pragma pop
// FUN_001F6BF0
/* measured: retail materialises this loop's invariant in the preheader; plain
   -O2 rematerialises it in the body (nd 9 -> byte-exact with the hoist). */
#pragma opt_loop_invariants on
s32 func_001f6bf0(u8 *arg0) {
    s32 i;
    s32 one;

    i = 0;
    one = 1;
    while ((u32)i < 0x18) {
        if ((one << i) == one) {
            return arg0[i + 0x3F6] >= 2;
        }
        i++;
    }
    return 1;
}
/* measured: closes the hoist bracket opened above and restores the -O2
   baseline for the rest of the file. */
#pragma opt_loop_invariants off

// measured: required for exact retail loop codegen in func_001f7260.
#pragma opt_loop_invariants on

// FUN_001F6C40
void func_001f6c40(u8 *arg0, s32 arg1)
{
    s32 temp_2;
    s32 temp_4;
    u32 var_6;

    if (arg1 != 0) {
        temp_2 = func_002326e0(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64));
        var_6 = 0;
        goto loop_test_6;
loop_6:
        temp_4 = 1 << var_6;
        if ((arg1 & temp_4) && !(temp_2 & temp_4)) {
            *(s8 *)(arg0 + var_6 + 0x3F6) = 0;
        }
        var_6 += 1;
loop_test_6:
        if (var_6 < 0x18U) {
            goto loop_6;
        }
    }
}
// FUN_001F6CD0
void func_001f6cd0(u8 *arg0)
{
    s32 temp_2;
    u32 var_6;
    u8 temp_3_2;
    u8 *temp_3;
    u8 *temp_4;

    temp_2 = func_002326e0(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64));
    var_6 = 0;
    goto loop_test_5;
loop_5:
    if ((temp_2 & (1 << var_6)) != 0) {
        temp_3 = arg0 + var_6;
        temp_4 = temp_3 + 0x3F6;
        temp_3_2 = *(u8 *)(temp_3 + 0x3F6);
        if ((s32)temp_3_2 < 0xFF) {
            *temp_4 = (u8)(temp_3_2 + 1);
        }
    }
    var_6 += 1;
loop_test_5:
    if (var_6 < 0x18U) {
        goto loop_5;
    }
}

// FUN_001F6D60
s16 func_001f6d60(u8 *arg0)
{
    u8 *temp_17;
    s16 var_16;
    s32 temp_16;
    s32 temp_2;
    s32 temp_4;
    s32 temp_4_2;
    u16 temp_3;

    temp_17 = *(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64);
    var_16 = 0;
    temp_2 = func_002326c0(temp_17);
    switch (temp_2) {
    case 0x20:
        temp_4 = func_00231f80(temp_17) & 0xFFFF;
        if ((*(u16 *)temp_17 & 4) == 0) {
            var_16 = -((temp_4 & 0xFFFF) * 0x64) / 1000;
        } else {
            temp_3 = *(u16 *)(iGpffffb3c4 +
                              (*(u16 *)(temp_17 + 2) * 0x3C));
            if ((temp_3 & 0x400) != 0) {
                var_16 = -0x32;
            } else if ((temp_3 & 0x800) != 0) {
                var_16 = -0x64;
            } else {
                var_16 = -((temp_4 & 0xFFFF) * 0x64) / 1000;
            }
            if (var_16 > 0x3E7) {
                var_16 = 0x3E7;
            }
            }
        if (func_002428f0((s32)(temp_17), var_16) != 0) {
            var_16 = -((func_00231ed0(temp_17) & 0xFFFF) - 1);
        }
        break;
    case 0x40:
        temp_16 = func_00232290(temp_17) & 0xFFFF;
        temp_4_2 = func_00231ee0(temp_17) & 0xFFFF;
        var_16 = -((temp_16 & 0xFFFF) * 0x64) / 1000;
        if (temp_4_2 < var_16) {
            var_16 = temp_4_2;
        }
        break;
    default:
        break;
    }
    return var_16;
}

/* measured: opt_rebuildconditionals off probe for func_001f6f60 final branch. */
#pragma opt_rebuildconditionals off
// FUN_001F6F60
s32 func_001f6f60(u8 *arg0)
{
    u8 *temp_16;
    s32 var_17;
    s32 temp_18;
    s32 temp_2;
    u16 temp_3;
    u16 temp_3_2;

    if ((*(u16 *)(arg0 + 0x1A) & 1) == 0) {
        return -1;
    }
    temp_16 = *(u8 **)(arg0 + 0x30);
    var_17 = -1;
    temp_2 = func_002326c0(*(u8 **)(temp_16 + 0xA64));
    switch (temp_2) {
    case 2:
        if ((*(u8 *)(arg0 + 0x28) == 0) &&
            (*(u8 *)(arg0 + 0x29) == 0)) {
            var_17 = 0xC;
        }
        break;
    case 4:
        temp_3 = *(u16 *)(arg0 + 0x6C);
        switch (temp_3) {
        case 6:
        case 12:
            var_17 = 8;
            break;
        case 7:
        case 8:
        case 11:
            var_17 = 0xA;
            break;
        default:
            break;
        }
        break;
    case 8:
        break;
    case 0x10:
        switch (*(u16 *)(arg0 + 0x6C)) {
        case 1:
            var_17 = 4;
            break;
        default:
            var_17 = 6;
            break;
        }
        break;
    case 0x100:
        temp_3_2 = *(u16 *)(arg0 + 0x6C);
        switch (temp_3_2) {
        case 2:
        case 1:
            var_17 = 0xAA;
            break;
        case 7:
        case 8:
        case 11:
            var_17 = 0xAB;
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
    if (var_17 < 0) {
        return -1;
    }
    {
        if (*(u8 *)(temp_16 + 0xA2) != 0)
            goto increment_6f60;
        temp_18 = var_17;
        goto done_6f60;
    increment_6f60:
        temp_18 = var_17 + 1;
    done_6f60:
        ;
    }
    var_17 = temp_18;
    return var_17;
}
/* measured: close opt_rebuildconditionals after func_001f6f60 probe. */
#pragma opt_rebuildconditionals on

/* measured: opt_rebuildconditionals off preserves func_001f7140's positive flag branch. */
#pragma opt_rebuildconditionals off
// FUN_001F7140
s32 func_001f7140(u8 *arg0)
{
    u8 *temp_16;
    s32 var_17;
    s32 temp_18;
    s32 temp_2;

    if ((*(u16 *)(arg0 + 0x1A) & 1) == 0) {
        return -1;
    }
    temp_16 = *(u8 **)(arg0 + 0x30);
    var_17 = -1;
    temp_2 = func_002326c0(*(u8 **)(temp_16 + 0xA64));
    switch (temp_2) {
    case 2:
        var_17 = 0x2E;
        break;
    case 4:
        var_17 = 0x2C;
        break;
    case 8:
        var_17 = 0x34;
        break;
    case 0x10:
        var_17 = 0x2A;
        break;
    case 0x40:
        var_17 = 0x30;
        break;
    case 0x80:
        var_17 = 0x32;
        break;
    default:
        break;
    }
    if (var_17 < 0) {
        return -1;
    }
    {
        if (*(u8 *)(temp_16 + 0xA2) != 0)
            goto increment_7140;
        temp_18 = var_17;
        goto done_7140;
    increment_7140:
        temp_18 = var_17 + 1;
    done_7140:
        ;
    }
    var_17 = temp_18;
    return var_17;
}
/* measured: close opt_rebuildconditionals after func_001f7140. */
#pragma opt_rebuildconditionals on
// FUN_001F7260
void func_001f7260(void)
{
    s32 offset;
    s32 empty;
    u16 i;
    u8 state;

    *(s16 *)(iGpffffb3ac + 0xAC8) = 5;
    empty = -1;
    *(s8 *)(iGpffffb3ac + 0xACA) = empty;
    i = 0;
    state = 3;
    for (; i < 0x10; i++) {
        offset = (u32)i * 6;
        *(s16 *)(iGpffffb3ac + offset + 0xACC) = empty;
        *(s16 *)(iGpffffb3ac + offset + 0xACE) = empty;
        *(s8 *)(iGpffffb3ac + offset + 0xAD0) = state;
    }
}
// measured: required for exact retail loop codegen in func_001f7260.
/* measured: optimization_level 1 required for exact func_001f72e0 codegen. */
#pragma optimization_level 1
/* measured: opt_loop_invariants off baseline for func_001f72e0. */
#pragma opt_loop_invariants off
// FUN_001F72E0
void func_001f72e0(void)
{
    s32 var_8;
    u8 *temp_3_4;
    u8 *temp_3_8;
    s32 temp_6;
    s32 index_8;
    s32 empty;
    s32 temp_3_5;

    {
        u8 *temp_3;
        u8 *temp_3_7;
        s32 temp_3_2;

        temp_3 = iGpffffb3ac;
        temp_3_7 = temp_3 + 0xACA;
        temp_3_2 = *(s8 *)temp_3_7;
        if (temp_3_2 >= 0) {
            temp_3_2 = temp_3_2 + 1;
            *(s8 *)temp_3_7 = (s8)temp_3_2;
            if ((s8)temp_3_2 >= 3) {
                *(s8 *)(iGpffffb3ac + 0xACA) = -1;
            }
        }
    }
    var_8 = 0;
    empty = -1;
    goto loop_test_8;
loop_8:
    temp_3_4 = iGpffffb3ac;
    index_8 = var_8 & 0xFFFF;
    temp_6 = index_8 * 6;
    temp_3_8 = temp_3_4 + temp_6;
    index_8 = (s32)(temp_3_8 + 0xAD0);
    temp_3_5 = *(s8 *)(temp_3_8 + 0xAD0);
    if (temp_3_5 >= 0) {
        temp_3_5 = temp_3_5 + 1;
        *(s8 *)index_8 = (s8)temp_3_5;
        if ((s8)temp_3_5 >= 3) {
            *(s16 *)(iGpffffb3ac + temp_6 + 0xACC) = empty;
            *(s16 *)(iGpffffb3ac + temp_6 + 0xACE) = empty;
            *(s8 *)(iGpffffb3ac + temp_6 + 0xAD0) = empty;
        }
    }
    var_8 = (var_8 + 1) & 0xFFFF;
loop_test_8:
    if ((var_8 & 0xFFFF) < 0x10) {
        goto loop_8;
    }
}
/* measured: restore optimization_level 2 after func_001f72e0. */
#pragma optimization_level 2
// FUN_001F73C0
void func_001f73c0(void)
{
}

/* Retail selectors 4/5/6 request tracks 5/6/4. Preserve block order:
 * the eleven resolved jump-table entries at 0x00747550 must also match. */
// FUN_001F73D0
void func_001f73d0(void)
{
    u16 temp_2;
    u8 *temp_4;

    temp_4 = iGpffffb3ac;
    if (*(s32 *)(temp_4 + 0xC) & 0x40) {
        temp_2 = *(u16 *)(*(u8 **)(temp_4 + 0xC68) + 8);
        temp_2 = *(u16 *)(iGpffffb414 + (temp_2 * 0x18) + 0x16);
        switch (temp_2) {
        case 2:
            func_0045a3e0(2, 1);
            break;
        case 3:
            func_0045a3e0(3, 1);
            break;
        case 6:
            func_0045a3e0(4, 1);
            break;
        case 4:
            func_0045a3e0(5, 1);
            break;
        case 5:
            func_0045a3e0(6, 1);
            break;
        case 7:
            func_0045a3e0(0x29, 1);
            break;
        case 8:
            func_0045a3e0(0x30, 1);
            break;
        case 9:
            func_0045a3e0(0x2F, 1);
            break;
        case 10:
            func_0045a3e0(0x2D, 1);
            break;
        default:
            func_0045a3e0(1, 1);
            break;
        }
    }
}
// FUN_001F75B0
void func_001f75b0(void)
{
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x40) != 0) {
        func_0045a9a0(1, 0);
        func_0045a9a0(2, 0);
        func_0045a9a0(3, 0);
        func_00459880();
    }
}

// FUN_001F7650
u8 *func_001f7650(u8 *arg0)
{
    u8 *var_2;
    u32 temp_3;

    if (*(u8 *)(arg0 + 0xA2) == 0) {
        if (func_00110d60((s16)func_001060b0()) & 1) {
            var_2 = D_0060AC00 + (*(u16 *)(arg0 + 0xA4) * 0xA20);
        } else {
            var_2 = D_0060AC00 + (*(u16 *)(arg0 + 0xA4) * 0xA20) + 0x6F60;
        }
        return var_2;
    }
    temp_3 = *(u16 *)(arg0 + 0xA4);
    if ((s32)temp_3 < 0x100) {
        return NULL;
    }
    if ((s32)temp_3 <= 0x112) {
        goto dispatch;
    }
    return NULL;
dispatch:
    if (temp_3 == 0x214) {
        goto return_214;
    } else if (temp_3 == 0x112) {
        goto return_group;
    } else if (temp_3 == 0x10E) {
        goto return_group;
    } else if (temp_3 == 0x10B) {
        goto return_group;
    } else if (temp_3 == 0x10A) {
        goto return_group;
    } else if (temp_3 == 0x109) {
        goto return_group;
    } else if (temp_3 == 0x108) {
        goto return_group;
    } else if (temp_3 == 0x107) {
        goto return_group;
    } else if (temp_3 == 0x106) {
        goto return_group;
    } else if (temp_3 == 0x105) {
        goto return_group;
    } else if (temp_3 == 0x104) {
        goto return_group;
    } else if (temp_3 == 0x103) {
        goto return_group;
    } else if (temp_3 == 0x102) {
        goto return_group;
    } else if (temp_3 == 0x101) {
        goto return_group;
    } else {
        switch (temp_3) {
        case 0x100:
            goto return_group;
        default:
            goto return_null;
        }
    }
return_group:
    return D_00618AC0 + ((temp_3 - 0x100) * 0xA20);
return_214:
    return D_0061F000;
return_null:
    var_2 = NULL;
    return var_2;
}
// FUN_001F7830
void func_001f7830(u8 *arg0, s32 arg1, s32 arg2, s16 *arg3, s16 *arg4)
{
    s32 temp_5;

    if (*(u8 *)(arg0 + 0xA2) == 0) {
        temp_5 = (s32)func_0023e270(*(u8 **)(arg0 + 0xA64)) & 0xFFFF;
        switch (*(u16 *)(arg0 + 0xA4)) {
        case 7:
            if (arg2 != 0) {
                if (arg1 == 3) {
                    *arg3 = -1;
                    *arg4 = -1;
                    goto done;
                }
            }
        default:
            *arg3 = 0;
            *arg4 = *(s16 *)(D_00624B20 + (temp_5 * 4));
            goto done;
        }
    }
    *arg3 = -1;
    *arg4 = -1;
done:
    ;
}
// FUN_001F7910
void func_001f7910(u8 *arg0, u32 arg1, s32 arg2, s16 *arg3, s16 *arg4)
{
    s32 temp_5;
    u16 temp_4;

    if (*(u8 *)(arg0 + 0xA2) == 0) {
        temp_5 = (s32)func_0023e270(*(u8 **)(arg0 + 0xA64)) & 0xFFFF;
        *arg3 = 0;
        temp_4 = *(u16 *)(arg0 + 0xA4);
        switch (temp_4) {
        case 4:
            if ((arg2 != 0) && (arg1 < 2U)) {
                *arg4 = 4;
                return;
            }
            *arg4 = *(s16 *)(D_00624B22 + (temp_5 * 4));
            return;
        case 6:
            if ((arg2 != 0) && ((u32)(arg1 - 1) < 2U)) {
                *arg4 = 4;
                return;
            }
            *arg4 = *(s16 *)(D_00624B22 + (temp_5 * 4));
            return;
        case 7:
            if ((arg2 != 0) && (arg1 == 3)) {
                *arg4 = 4;
                return;
            }
            *arg4 = *(s16 *)(D_00624B22 + (temp_5 * 4));
            return;
        default:
            *arg4 = *(s16 *)(D_00624B22 + (temp_5 * 4));
            return;
        }
    }
    *arg3 = 0;
    switch (*(u16 *)(arg0 + 0xA4)) {
    case 0x109:
        *arg4 = 8;
        break;
    default:
        *arg4 = 0;
        break;
    }
}
// FUN_001F7AD0
void func_001f7ad0(u8 *arg0)
{
    u16 temp_7;
    u8 *temp_6;
    u32 offset;

    temp_7 = *(u16 *)arg0;
    offset = temp_7 * 6;
    temp_6 = (u8 *)(offset + (u32)iGpffffb3ac);
    if ((*(s16 *)(temp_6 + 0xACC) != *(u16 *)(arg0 + 2)) ||
        (*(s16 *)(temp_6 + 0xACE) != *(u16 *)(arg0 + 4))) {
        func_0045aa90(1, (s16)temp_7);
    }
}
// FUN_001F7B40
s32 func_001f7b40(u8 *arg0)
{
    u16 temp_4;
    u16 temp_6;
    u8 *temp_3;
    u32 offset;

    temp_6 = *(u16 *)(arg0 + 2);
    temp_4 = *(u16 *)arg0;
    offset = temp_4 * 6;
    temp_3 = (u8 *)(offset + (u32)iGpffffb3ac);
    if ((*(s16 *)(temp_3 + 0xACC) != temp_6) ||
        (*(s16 *)(temp_3 + 0xACE) != *(u16 *)(arg0 + 4))) {
        func_0045af60(1, (s16)temp_4, (s16)temp_6,
                      (s16)*(u16 *)(arg0 + 4));
        temp_6 = *(u16 *)(arg0 + 2);
        temp_3 = iGpffffb3ac;
        offset = (u32)temp_3;
        temp_4 = *(u16 *)arg0;
        offset = addOffsetFirst(temp_4 * 6, offset);
        *(u16 *)((u8 *)offset + 0xACC) = temp_6;
        temp_6 = *(u16 *)(arg0 + 4);
        temp_3 = iGpffffb3ac;
        offset = (u32)temp_3;
        temp_4 = *(u16 *)arg0;
        offset = addOffsetFirst(temp_4 * 6, offset);
        *(u16 *)((u8 *)offset + 0xACE) = temp_6;
        temp_3 = iGpffffb3ac;
        offset = (u32)temp_3;
        temp_4 = *(u16 *)arg0;
        offset = addOffsetFirst(temp_4 * 6, offset);
        *(u8 *)((u8 *)offset + 0xAD0) = 0;
    }
    return 1;
}
// FUN_001F8380
s32 func_001f8380(u8 **arg0)
{
    u8 *temp_3;
    u8 *temp_3_2;

    temp_3 = *arg0;
    if (*(s32 *)(temp_3 + 0x98) & 2) {
        temp_3_2 = *(u8 **)(temp_3 + 0xA00);
        *(u16 *)(temp_3_2 + 0x2E0) |= 0x40;
    }
    return 1;
}
// FUN_001F83B0
void func_001f83b0(u32 value)
{
    u8 *packet;

    packet = (u8 *)func_00194470(0x90B, 0x4);
    *(void **)(packet + 0x6C) = (void *)func_001f8380;
    *(u32 *)*(u8 **)(packet + 0x78) = value;
}

// FUN_001F8400
s32 func_001f8400(u8 **arg0)
{
    u8 *temp_3;
    u8 *temp_3_2;

    temp_3 = *arg0;
    if (*(s32 *)(temp_3 + 0x98) & 2) {
        temp_3_2 = *(u8 **)(temp_3 + 0xA00);
        *(u16 *)(temp_3_2 + 0x2E0) &= 0xFFBF;
    }
    return 1;
}
// FUN_001F8430
void func_001f8430(u32 value)
{
    u8 *packet;

    packet = (u8 *)func_00194470(0x90C, 0x4);
    *(void **)(packet + 0x6C) = (void *)func_001f8400;
    *(u32 *)*(u8 **)(packet + 0x78) = value;
}

// FUN_001F8480
void func_001f8480(void)
{
    void **allocator;
    u8 sp30[0x100];
    u8 *temp_16;
    u8 *temp_17;
    u8 *temp_17_2;
    s32 temp_2;
    s32 temp_2_2;
    s32 temp_2_3;

    func_0044ea90(&D_00624F50, 0x3A);
    allocator = (void **)jtbl_008873E8;
    temp_17 = ((u8 *(*)(u32, u32))allocator[0])(0xBE4, 0x40000);
    func_00442088(sp30, &D_00624F60);
    func_00456250(3, sp30, 0, temp_17);
    goto loop_3_test;
loop_3_retry:
    if (temp_2 != 4) {
        goto loop_3_test;
    }
    func_00456250(3, sp30, 0, temp_17);
loop_3_test:
    temp_2 = func_004c7ef8(3);
    if (temp_2 != 3) {
        goto loop_3_retry;
    }
    iGpffffb460 = 1;
    func_0044ea90(&D_00624F50, 0x3A);
    temp_17_2 = ((u8 *(*)(u32, u32))allocator[0])(0x630, 0x40000);
    func_00442088(sp30, &D_00624F80);
    func_00456250(4, sp30, 0, temp_17_2);
    goto loop_7_test;
loop_7_retry:
    if (temp_2_2 != 4) {
        goto loop_7_test;
    }
    func_00456250(4, sp30, 0, temp_17_2);
loop_7_test:
    temp_2_2 = func_004c7ef8(4);
    if (temp_2_2 != 3) {
        goto loop_7_retry;
    }
    func_0044ea90(&D_00624F50, 0x3A);
    temp_16 = ((u8 *(*)(u32, u32))allocator[0])(0x4A0, 0x40000);
    func_00442088(sp30, &D_00624FA0);
    func_00456250(5, sp30, 0, temp_16);
    goto loop_11_test;
loop_11_retry:
    if (temp_2_3 != 4) {
        goto loop_11_test;
    }
    func_00456250(5, sp30, 0, temp_16);
loop_11_test:
    temp_2_3 = func_004c7ef8(5);
    if (temp_2_3 != 3) {
        goto loop_11_retry;
    }
    iGpffffb464 = 1;
}
// FUN_001F8690
void func_001f8690(s32 arg0) {
    s32 value;
    u16 index;

    value = *(u16 *)(iGpffffb3ac + 0xB30);
    index = (u16)arg0;
    func_0045ae10(value, 3, index);
}
// FUN_001F86D0
void func_001f86d0(void) {
    func_0045aac0(3, 0, 8);
}
// FUN_001F8700
s32 func_001f8700(u8 *arg0, s32 arg1)
{
    s32 temp_2;
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0x30);
    if (*(s32 *)(temp_4 + 0xA0C) == 0)
    {
        return -1;
    }
    if (*(u8 *)(temp_4 + 0xA2) == 1)
    {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0)
    {
        return arg1 - 1;
    }
    temp_2 = func_00109360(*(u16 *)(temp_4 + 0xA4)) & 0xFFFF;
    switch (temp_2)
    {
    case 0xC0:
    case 0xC2:
    case 0xC4:
    case 0xC6:
    case 0xC8:
    case 0xCA:
    case 0xCC:
        return (s32)D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] + 0x22;
    case 0xC1:
    case 0xC3:
    case 0xC5:
    case 0xC7:
    case 0xC9:
    case 0xCB:
    case 0xCD:
        return (s32)D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] + 0x23;
    default:
        return -1;
    }
}
// FUN_001F8810
s32 func_001f8810(u8 *arg0, s32 arg1)
{
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_4 + 0xA2) == 1)
    {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0)
    {
        return -1;
    }
    if (arg1 >= 5)
    {
        return -1;
    }
    if (func_002428f0((s32)((u8 *)*(s32 *)(temp_4 + 0xA64)), 0) != 0)
    {
        return -1;
    }
    if (func_00232710(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64), 0x1001D7) != 0)
    {
        return -1;
    }
    return (s32)D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] +
           (s32)D_00624FD8[arg1];
}
// FUN_001F8920
s32 func_001f8920(u8 *arg0)
{
    extern s32 func_0022bd20(void);
    s32 temp_16;
    s32 var_2;
    u16 temp_2;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_3 + 0xA2) == 0) {
        if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
            var_2 = -1;
        } else {
            temp_16 = (s32)D_00624FC0[*(u16 *)(temp_3 + 0xA4)] + 7;
            var_2 = temp_16 + func_00231d70(3);
        }
        return var_2;
    }
    if (func_0022bd20() == 0) {
        return -1;
    }
    temp_2 = *(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4);
    switch (temp_2) {
    case 0x100:
        return func_00231d70(3) + 0x417;
    case 0x101:
        return func_00231d70(3) + 0x429;
    case 0x102:
        return func_00231d70(3) + 0x43C;
    case 0x103:
        return func_00231d70(3) + 0x44F;
    case 0x104:
        return func_00231d70(3) + 0x462;
    case 0x105:
        return func_00231d70(3) + 0x475;
    case 0x106:
        return func_00231d70(3) + 0x488;
    case 0x107:
        return func_00231d70(3) + 0x49B;
    case 0x108:
        return func_00231d70(3) + 0x4AE;
    case 0x109:
        return func_00231d70(3) + 0x4C3;
    case 0x112:
        return func_00231d70(3) + 0x4FC;
    case 0x10A:
    case 0x10B:
    case 0x10C:
    case 0x10D:
    case 0x10E:
    case 0x10F:
    case 0x110:
    case 0x111:
    default:
        return -1;
    }
}
// FUN_001F8B00
s32 func_001f8b00(u8 *arg0)
{
    s32 value;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(work + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    value = D_00624FC0[*(u16 *)(work + 0xA4)] + 0x78;
    return value + func_00231d70(5);
}
// FUN_001F8B90
s32 func_001f8b90(u8 *arg0)
{
    s32 value;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(work + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    value = D_00624FC0[*(u16 *)(work + 0xA4)] + 0x63;
    return value + func_00231d70(3);
}
// FUN_001F8C20
s32 func_001f8c20(u8 *arg0, s32 arg1)
{
    s32 value;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(work + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    if (arg1 != 0) {
        value = D_00624FC0[*(u16 *)(work + 0xA4)] + 0x6F;
        return value + func_00231d70(3);
    }
    value = D_00624FC0[*(u16 *)(work + 0xA4)] + 0x72;
    return value + func_00231d70(3);
}
// FUN_001F8CE0
s32 func_001f8ce0(u8 *arg0)
{
    s32 value;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(work + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    value = D_00624FC0[*(u16 *)(work + 0xA4)] + 0x75;
    return value + func_00231d70(3);
}
// FUN_001F8D70
s32 func_001f8d70(u8 *arg0, s32 arg1)
{
    s32 value;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(work + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    if (arg1 != 0) {
        return -1;
    }
    value = D_00624FC0[*(u16 *)(work + 0xA4)] + 0x2C;
    return value + func_00231d70(3);
}
// FUN_001F8E10
s32 func_001f8e10(u8 *arg0)
{
    s32 value;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(work + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    value = D_00624FC0[*(u16 *)(work + 0xA4)] + 0x29;
    return value + func_00231d70(3);
}
/* measured: opt_propagation off preserves func_001f8ea0's loop constants. */
#pragma opt_propagation off
// FUN_001F8EA0
s32 func_001f8ea0(u8 *arg0, s32 arg1)
{
    s32 five;
    s32 value;
    s32 i;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(work + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    value = 0x10;
    i = 1;
    five = 5;
    while (i <= 8) {
        if (i == arg1) {
            break;
        }
        if ((i != five) && (i != *(u16 *)(work + 0xA4))) {
            value += 1;
        }
        i += 1;
    }
done:
    return value + D_00624FC0[*(u16 *)(work + 0xA4)];
}
/* measured: close opt_propagation after func_001f8ea0 probe. */
#pragma opt_propagation on
/* measured: opt_propagation off preserves func_001f8f40's loop constants. */
#pragma opt_propagation off
// FUN_001F8F40
s32 func_001f8f40(u8 *arg0, s32 arg1)
{
    s32 five;
    s32 value;
    s32 i;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(work + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    value = 0x16;
    i = 1;
    five = 5;
    while (i <= 8) {
        if (i == arg1) {
            break;
        }
        if ((i != five) && (i != *(u16 *)(work + 0xA4))) {
            value += 1;
        }
        i += 1;
    }
    return value + D_00624FC0[*(u16 *)(work + 0xA4)];
}
/* measured: close opt_propagation after func_001f8f40 probe. */
#pragma opt_propagation on
/* measured: opt_propagation off preserves func_001f8fe0's loop constants. */
#pragma opt_propagation off
// FUN_001F8FE0
s32 func_001f8fe0(u8 *arg0, s32 arg1)
{
    s32 five;
    s32 value;
    s32 i;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(work + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    value = 0x1C;
    i = 1;
    five = 5;
    while (i <= 8) {
        if (i == arg1) {
            break;
        }
        if ((i != five) && (i != *(u16 *)(work + 0xA4))) {
            value += 1;
        }
        i += 1;
    }
    return value + D_00624FC0[*(u16 *)(work + 0xA4)];
}
/* measured: close opt_propagation after func_001f8fe0 probe. */
#pragma opt_propagation on
// FUN_001F9080
s32 func_001f9080(u8 *arg0) {
    u8 *p;

    p = *(u8 **)(arg0 + 0x30);
    if (p[0xA2] != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    return D_00624FC0[*(u16 *)(p + 0xA4)] + 0x45;
}

/* measured: opt_propagation off tested for func_001f90e0; retains loop constants. */
#pragma opt_propagation off
// FUN_001F90E0
s32 func_001f90e0(u8 *arg0)
{
    s32 temp_16;
    s32 temp_4;
    u8 *var_17;
    s32 var_16;
    s32 var_5;
    u32 var_6;
    s32 var_7;
    u8 *temp_3;
    u8 *temp_4_2;
    u8 *sp60[12];

    if (func_0045af90(3) == 1) {
        return -1;
    }
    temp_3 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_3 + 0xA2) != 0) {
        return -1;
    }
    if (func_00232710(*(s32 *)(temp_3 + 0xA64), 0x110) != 0) {
        return -1;
    }
    var_16 = 0;
    var_17 = *(u8 **)(iGpffffb3ac + 0x178);
    while (var_17 != NULL) {
        if ((func_002428f0((s32)(*(u8 **)(var_17 + 0xA64)), 0) == 0) &&
            (func_00232710(*(s32 *)(var_17 + 0xA64), 0x1001D7) == 0) &&
            (*(u16 *)(var_17 + 0xA4) != 1) &&
            (var_17 != *(u8 **)(arg0 + 0x30))) {
            sp60[(u16)var_16] = var_17;
            var_16 = (u16)(var_16 + 1);
        }
        var_17 = *(u8 **)(var_17 + 0xA6C);
    }
    temp_4 = (u16)var_16;
    if (temp_4 == 0) {
        return -1;
    }
    temp_4_2 = sp60[func_00231d70(temp_4)];
    if (temp_4_2 == NULL) {
        return -1;
    }
    var_6 = 0x32;
    var_5 = 1;
    var_7 = 5;
    while (var_5 <= 8) {
        if (var_5 == *(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)) {
            break;
        }
        if ((var_5 != var_7) && (var_5 != *(u16 *)(temp_4_2 + 0xA4))) {
            var_6 += 3;
        }
        var_5 += 1;
    }
    temp_16 = var_6 + D_00624FC0[*(u16 *)(temp_4_2 + 0xA4)];
    return temp_16 + func_00231d70(3, var_5, var_6);
}
/* measured: close opt_propagation after func_001f90e0. */
#pragma opt_propagation on
// FUN_001F92C0
s32 func_001f92c0(u8 *arg0)
{
    s32 value;

    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) != 0) {
        return -1;
    }
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    if (func_00232710(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64),
                      0x1001D7) != 0) {
        return -1;
    }
    value = D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] + 0x51;
    return value + func_00231d70(3);
}
// FUN_001F93A0
s32 func_001f93a0(u8 *arg0)
{
    s32 type;
    s32 value;

    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) != 0) {
        return -1;
    }
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    if (func_00232710(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64),
                      0x1001D7) != 0) {
        return -1;
    }
    type = func_001ef720(2, 0x80000) & 0xFFFF;
    switch (type) {
    case 4:
        value = D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] + 0x54;
        return value + func_00231d70(3);
    case 3:
        value = D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] + 0x57;
        return value + func_00231d70(3);
    case 2:
        value = D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] + 0x5A;
        return value + func_00231d70(3);
    case 1:
        value = D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] + 0x5D;
        return value + func_00231d70(3);
    }
    return -1;
}
// FUN_001F9570
s32 func_001f9570(u8 *arg0)
{
    s32 value;

    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) != 0) {
        return -1;
    }
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    if (func_00232710(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64),
                      0x1001D7) != 0) {
        return -1;
    }
    value = D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] + 0x69;
    return value + func_00231d70(3);
}
// FUN_001F9650
s32 func_001f9650(u8 *arg0)
{
    s32 value;

    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    if (func_00232710(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64),
                      0x1001D7) != 0) {
        return -1;
    }
    value = D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] + 0x66;
    return value + func_00231d70(3);
}
// FUN_001F9740
s32 func_001f9740(void)
{
    return -1;
}

// FUN_001F9750
s32 func_001f9750(s32 *arg0) {
    s32 r;

    if (arg0[1] == 0) {
        if (iGpffffb460 != 0) {
            arg0[0] = 0;
        }
        arg0[1] = 1;
    }
    if (arg0[0] == 0) {
        *(u16 *)(D_0076449C + 0xB2E) |= 1;
        r = 1;
    } else {
        r = 0;
    }
    return r;
}

// FUN_001F9800
s32 func_001f9800(u8 *arg0)
{
    s32 temp_2;
    u8 *temp_16;
    u8 *temp_3;
    u8 *temp_3_2;
    u8 *temp_3_3;
    u8 *temp_3_4;

    if ((*(u16 *)(iGpffffb3ac + 0xB2E) & 1) == 0) {
        return 1;
    }
    temp_16 = *(u8 **)arg0;
    if (*(s32 *)(arg0 + 0x14) == 0) {
        if ((temp_16 != NULL) &&
            ((*(u16 *)(temp_16 + 0x1A) & 1) == 0)) {
            return 1;
        }
        temp_2 = D_00624FF0[*(u16 *)(arg0 + 4)](
            temp_16, *(s32 *)(arg0 + 8), *(s32 *)(arg0 + 0xC));
        if (temp_2 == -1) {
            return 1;
        }
        func_0045ae10(*(u16 *)(iGpffffb3ac + 0xB30), 3, (u16)temp_2);
        *(s32 *)(arg0 + 0x14) = 1;
        goto block_15_9800;
    }
    if (func_0045af90(3) != 1) {
        if ((*(u16 *)(arg0 + 0x10) & 1) == 0 && (temp_16 != NULL)) {
            temp_3 = *(u8 **)(temp_16 + 0x30);
            if ((*(s32 *)(temp_3 + 0x98) & 2) != 0) {
                *(u16 *)(temp_3 + 0x9D8) &= 0xFFEF;
                temp_3_2 = *(u8 **)(*(u8 **)(temp_16 + 0x30) + 0xA00);
                *(u16 *)(temp_3_2 + 0x2E0) |= 0x20;
            }
        }
        return 1;
    }
block_15_9800:
    if ((*(u16 *)(arg0 + 0x10) & 1) == 0 &&
        *(s32 *)(arg0 + 0x14) == 1 && (temp_16 != NULL)) {
        temp_3_3 = *(u8 **)(temp_16 + 0x30);
        if ((*(s32 *)(temp_3_3 + 0x98) & 2) != 0) {
            *(u16 *)(temp_3_3 + 0x9D8) |= 0x10;
            temp_3_4 = *(u8 **)(*(u8 **)(temp_16 + 0x30) + 0xA00);
            *(u16 *)(temp_3_4 + 0x2E0) &= 0xFFDF;
        }
    }
    return 0;
}
// FUN_001F9A50
void func_001f9a50(s32 arg0, s32 arg1) {
    s32 f = *(u16 *)((u8 *)iGpffffb3ac + 0xB3A);
    func_0045ae10((u16)f, (u16)arg1, (u16)arg0);
}

// FUN_001F9A90
void func_001f9a90(void) {
    func_0045aac0(1, 0, 8);
}
/* measured: opt_propagation off preserves 9ac0's explicit boolean branch. */
#pragma opt_propagation off
// FUN_001F9AC0
s32 func_001f9ac0(u8 *arg0)
{
    s32 value;
    s32 code;
    s32 flag;

    if (*(s32 *)(arg0 + 4) == 0) {
        if (*(u16 *)(arg0 + 8) == 0) {
            value = 0x6C;
        } else {
            value = 0x69;
        }
        code = value & 0xFFFF;
        switch (code) {
        case 0x6C:
            *(s16 *)(iGpffffb3ac + 0xB3A) = 5;
            break;
        case 0x69:
            *(s16 *)(iGpffffb3ac + 0xB3A) = 4;
            break;
        default:
            break;
        }
        *(s32 *)(arg0 + 0) = 0;
        *(s32 *)(arg0 + 4) = 1;
    }
    if (*(s32 *)(arg0 + 0) == 0) {
        goto return_one_a;
    }
    flag = (*(u16 *)(iGpffffb3ac + 0xB38) & 1) != 0;
    if (flag == 0) {
        goto return_zero;
    }
return_one_b:
    return 1;
return_one_a:
    return 1;
return_zero:
    return 0;
}
/* measured: close opt_propagation after func_001f9ac0 probe. */
#pragma opt_propagation on
// FUN_001F9BE0
void func_001f9be0(void)
{
}
// FUN_001F9BF0
void func_001f9bf0(void) {
    func_0043f9c8(iGpffffb3ac + 0xB2C, 0, 0x14);
    *(s16 *)(iGpffffb3ac + 0xB30) = 3;
    *(s16 *)(iGpffffb3ac + 0xB3A) = 0;
}
// FUN_001F9C40
void func_001f9c40(void)
{
    if (*(s32 *)(iGpffffb3ac + 0xB34) != 0) {
        jtbl_008873EC[0](*(void **)(iGpffffb3ac + 0xB34));
        *(s32 *)(iGpffffb3ac + 0xB34) = 0;
        *(u16 *)(iGpffffb3ac + 0xB2E) &= 0xFFFE;
    }
    if (*(s32 *)(iGpffffb3ac + 0xB3C) != 0) {
        jtbl_008873EC[0](*(void **)(iGpffffb3ac + 0xB3C));
        *(s32 *)(iGpffffb3ac + 0xB3C) = 0;
        *(u16 *)(iGpffffb3ac + 0xB38) &= 0xFFFE;
    }
}
// FUN_001F9CD0
void func_001f9cd0(void)
{
}
// FUN_001F9CE0
s32 func_001f9ce0(void)
{
    return 0;
}
// FUN_001FA660
s32 func_001fa660(void)
{
    s32 flags;
    u8 *base;
    u8 *work;
    u8 *flag_ptr;

    base = iGpffffb3ac;
    if (*(u16 *)(base + 0xB7C) == 5) {
        return func_00120ee0(*(s32 *)(base + 0xB88));
    }
    if (func_004553c0(*(u8 **)(base + 0xB84)) != 0) {
        base = iGpffffb3ac;
        flag_ptr = base + 0xB4C;
        flags = *(s32 *)flag_ptr;
        if ((flags & 2) == 0) {
            work = *(u8 **)(base + 0xB84);
            *(s32 *)(iGpffffb3ac + 0xB80) =
                func_00484bb0(*(s32 *)(work + 0x110), base);
        } else {
            *(s32 *)flag_ptr = flags & ~2;
        }
        func_00454bd0(*(u8 **)(iGpffffb3ac + 0xB84));
        *(u8 **)(iGpffffb3ac + 0xB84) = NULL;
        return 1;
    }
    return 0;
}
// FUN_001FA720
u8 *func_001fa720(s32 arg0) {
    u8 *temp_2;

    temp_2 = (u8 *)func_00194470(0xC04, 0xA);
    temp_2[0x47] &= 0xEE;
    *(void **)(temp_2 + 0x68) = (void *)func_001fa490;
    *(void **)(temp_2 + 0x6C) = (void *)func_001fa660;
    func_0043f810(*(s32 **)(temp_2 + 0x78), (void *)arg0, 0xA);
    return temp_2;
}
// FUN_001FA7A0
s32 func_001fa7a0(s32 *arg0)
{
    extern void func_00120f00(s32 arg0);
    extern s32 func_004b1520(s32 arg0);
    extern s32 func_00481450(void);
    extern void func_00481440(void *arg0);
    extern void func_00485630(s32 arg0);
    extern void func_00485870(s32 arg0);
    extern void func_00485b20(s32 arg0);
    extern u8 D_005DC8CC[];
    void *temp_17;
    s32 temp_4_2;
    s32 temp_4_3;
    u8 *temp_4;

    temp_4 = iGpffffb3ac;
    if (*(u16 *)(temp_4 + 0xB7C) == 5) {
        temp_4_2 = *(s32 *)(temp_4 + 0xB88);
        if (temp_4_2 == 0) {
            return 1;
        }
        if (*arg0 == 0) {
            func_00120f00(temp_4_2);
        }
        goto block_12;
    }
    temp_4_3 = *(s32 *)(temp_4 + 0xB80);
    if (temp_4_3 == 0) {
        return 1;
    }
    if (func_004b1520(temp_4_3) == 0) {
        if (*arg0 == 0) {
            func_0045af60(1, 0xE, 2, 0x10);
        }
        temp_17 = (void *)func_00481450();
        func_00481440(&D_005DC8CC);
        func_00485630(*(s32 *)(iGpffffb3ac + 0xB80));
        func_00485870(*(s32 *)(iGpffffb3ac + 0xB80));
        func_00481440(temp_17);
        *arg0 += 1;
        goto block_12;
    }
    func_00485b20(*(s32 *)(iGpffffb3ac + 0xB80));
    *(s32 *)(iGpffffb3ac + 0xB80) = 0;
    return 1;
block_12:
        return 0;
}
// FUN_001FA8F0
void func_001fa8f0(void) {
    u8 *temp_2;

    temp_2 = (u8 *)func_00194470(0xC05, 4);
    temp_2[0x47] &= 0xEE;
    *(void **)(temp_2 + 0x6C) = (void *)func_001fa7a0;
    *(s32 **)(*(u8 **)(temp_2 + 0x78)) = NULL;
}
// FUN_001FA940
s32 func_001fa940(void) {
    s32 temp_4;
    s32 temp_4_2;
    u8 *temp_3;

    temp_3 = D_0076449C;
    if (*(s32 *)(temp_3 + 0xB84) != 0) {
        *(s32 *)(temp_3 + 0xB4C) |= 2;
    } else {
        temp_4 = *(s32 *)(temp_3 + 0xB80);
        if (temp_4 != 0) {
            func_00485b20(temp_4);
            *(s32 *)(D_0076449C + 0xB80) = 0;
        }
    }
    temp_4_2 = *(s32 *)(D_0076449C + 0xB88);
    if (temp_4_2 != 0) {
        func_00120f20(temp_4_2);
        *(s32 *)(D_0076449C + 0xB88) = 0;
    }
    return 1;
}
// FUN_001FA9C0
void func_001fa9c0(void) {
    u8 *temp_2;

    temp_2 = (u8 *)func_00194470(0xC06, 0);
    temp_2[0x47] &= 0xEE;
    *(void **)(temp_2 + 0x6C) = (void *)func_001fa940;
}
// FUN_001FAA00
s32 func_001faa00(void) {
    s32 temp_4;
    s32 temp_4_2;

    temp_4 = *(s32 *)(D_0076449C + 0xB80);
    if (temp_4 != 0) {
        func_00486180(temp_4);
    }
    temp_4_2 = *(s32 *)(D_0076449C + 0xB88);
    if (temp_4_2 != 0) {
        func_00120f20(temp_4_2);
        *(s32 *)(D_0076449C + 0xB88) = 0;
    }
    return 1;
}
// FUN_001FAA60
void func_001faa60(void) {
    u8 *temp_2;

    temp_2 = (u8 *)func_00194470(0xC07, 0);
    temp_2[0x47] &= 0xEE;
    *(void **)(temp_2 + 0x6C) = (void *)func_001faa00;
}
// FUN_001FAAA0
s32 func_001faaa0(u8 *arg0) {
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) {
        return func_0022bad0(arg0, 0);
    }
    return 0;
}
// FUN_001FAAF0
s32 func_001faaf0(void) {
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) {
        return func_0022bc80(0);
    }
    return 0;
}
// FUN_001FAB40
s32 func_001fab40(u8 *arg0) {
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) {
        return func_0022bad0(arg0, 1);
    }
    return 0;
}
// FUN_001FAB90
s32 func_001fab90(void) {
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) {
        return func_0022bc80(1);
    }
    return 0;
}
// FUN_001FABE0
s32 func_001fabe0(u8 *arg0) {
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) {
        return func_0022bad0(arg0, 2);
    }
    return 0;
}
// FUN_001FAC30
s32 func_001fac30(void) {
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) {
        return func_0022bc80(2);
    }
    return 0;
}
// FUN_001FAC80
s32 func_001fac80(u8 *arg0)
{
    u8 *base;

    base = iGpffffb3ac;
    if ((*(s32 *)(base + 0xC) & 0x200000) == 0) {
        goto return_zero;
    }
    if (func_0022bd00() == 0) {
        base = iGpffffb3ac;
        if (*(s32 *)(base + 0xB40) != 0) {
            ((void (*)(void *))(*(void **)(base + 0xB40)))(
                *(void **)(base + 0xB48));
            return 1;
        }
    }
    return func_0022bad0(arg0, 3);
return_zero:
    return 0;
}
// FUN_001FAD10
s32 func_001fad10(void)
{
    s32 (*callback)(s32);
    s32 result;
    u8 *base;

    result = 0;
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) {
        if (func_0022bd00() == 0) {
            base = iGpffffb3ac;
            callback = *(s32 (**)(s32))(base + 0xB44);
            if (callback != NULL) {
                result = callback(*(s32 *)(base + 0xB48));
                if (result == 0) {
                    *(s32 *)(iGpffffb3ac + 0xB40) = 0;
                    *(s32 *)(iGpffffb3ac + 0xB44) = 0;
                    *(s32 *)(iGpffffb3ac + 0xB48) = 0;
                }
            }
        }
        if (result == 0) {
            result = func_0022bc80(3);
        }
    }
    return result;
}
// FUN_001FADC0
s32 func_001fadc0(u8 *arg0) {
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) {
        return func_0022bad0(arg0, 4);
    }
    return 0;
}
// FUN_001FAE10
s32 func_001fae10(void) {
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) {
        return func_0022bc80(4);
    }
    return 0;
}
// FUN_001FAE60
void func_001fae60(s32 arg0, s32 arg1, s32 arg2)
{
    *(s32 *)(D_0076449C + 0xB40) = arg0;
    *(s32 *)(D_0076449C + 0xB44) = arg1;
    *(s32 *)(D_0076449C + 0xB48) = arg2;
}
// FUN_001FAE80
s32 func_001fae80(u8 *arg0, s32 arg1)
{
    extern void func_001d7c60(u8 *arg0, u8 *arg1, u8 arg2, u8 arg3,
                              u32 arg4);
    u8 sp30[0x38];
    s32 temp_16;
    u8 *temp_3;

    if (arg1 <= 0) {
        return 0;
    }
    temp_16 = arg1 * 0x28;
    temp_3 = (u8 *)((u32)iGpffffb3b8 + temp_16);
    if ((*(u8 *)temp_3 & 8) == 0) {
        return 0;
    }
    func_001d7c60(arg0, sp30,
                   *(u8 *)(temp_3 + 9),
                   *(u8 *)(temp_3 + 0xA),
                   *(u16 *)(temp_3 + 0xC));
    if (*(u16 *)(sp30 + 0x38) == 0) {
        return 2;
    }
    switch (*(u8 *)((u8 *)addOffsetFirst((u32)temp_16,
                                         (u32)iGpffffb3b8) + 0x24)) {
    case 2:
        if (func_001da130(arg0, 0) == 0) {
            return 6;
        }
        break;
    default:
        break;
    }
    return 0;
}
// FUN_001FAF70
s32 func_001faf70(u8 *arg0, s32 arg1, s32 arg2)
{
    extern s32 func_0023a1e0(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3);
    s32 temp_18;
    u32 var_21;
    u32 var_20;
    s32 temp_19;
    s32 temp_2;
    s32 var_2;
    u32 var_18;
    u8 *temp_3;

    if (arg1 <= 0) {
        return 0;
    }
    temp_3 = iGpffffb3b8 + (arg1 * 0x28);
    if (!( *(u8 *)(temp_3 + 0) & 8)) {
        return 0;
    }
    temp_18 = *(s32 *)(temp_3 + 0x20);
    if ((temp_18 & 0x7F7FFFFF) && !(temp_18 & 0x80800000)) {
        var_21 = 0;
        goto loop_outer_test;
loop_outer_body:
        temp_19 = 1 << var_21;
        if (temp_18 & temp_19) {
            var_20 = 0;
            goto loop_inner_test;
loop_inner_body:
            if (func_002340c0((u8 *)(
                    *(s32 *)(*(u8 **)(*(u8 **)(arg0 + (var_20 * 4) + 0x38) +
                                      0x30) + 0xA64)),
                    temp_19) != 0) {
                var_20 += 1;
                goto loop_inner_test;
            } else {
                goto loop_inner_exit;
            }
loop_inner_test:
            if (var_20 < *(u16 *)(arg0 + 0x6A)) {
                goto loop_inner_body;
            }
loop_inner_exit:
            if (var_20 != *(u16 *)(arg0 + 0x6A)) {
                goto loop_outer_after;
            }
        }
loop_outer_increment:
        var_21 += 1;
loop_outer_test:
        if (var_21 < 0x20U) {
            goto loop_outer_body;
        }
loop_outer_after:
        if (var_21 == 0x20) {
            if (temp_18 & 0x3000) {
                var_2 = 5;
            } else {
                var_2 = 3;
            }
            return var_2;
        }
    }
    var_18 = 0;
    goto loop_24_test;
loop_24_body:
    temp_2 = func_0023a1e0(
        arg1 & 0xFFFF,
        (u8 *)*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64),
        (u8 *)*(s32 *)(*(u8 **)(*(u8 **)(arg0 + (var_18 * 4) + 0x38) +
                            0x30) + 0xA64),
        arg2);
    if (temp_2 != 0 && temp_2 != 0xFFFF) {
        var_18 += 1;
        goto loop_24_test;
    } else {
        goto loop_24_exit;
    }
loop_24_test:
    if (var_18 < *(u16 *)(arg0 + 0x6A)) {
        goto loop_24_body;
    }
loop_24_exit:
    if (var_18 == *(u16 *)(arg0 + 0x6A)) {
        return 4;
    }
    return 0;
}
// FUN_001FB170
s32 func_001fb170(s32 arg0) {
    u32 temp_2;

    temp_2 = arg0 & 0xFFFF;
    switch (temp_2) {
    case 2:
        return 0x8A;
    case 3:
        return 0x8B;
    case 4:
        return 0x8C;
    case 5:
        return 0x8D;
    case 6:
        return 0x8E;
    case 7:
        return 0x98;
    default:
        return 0;
    }
}
// FUN_001FB1F0
s32 func_001fb1f0(u8 *arg0, s32 arg1)
{
    s32 temp_16;
    u32 var_19;
    u32 var_18;
    s32 temp_17;
    s32 var_2;
    u8 *temp_3;

    if (arg1 <= 0) {
        return 0;
    }
    temp_3 = iGpffffb3b8 + (arg1 * 0x28);
    if (!(*(u8 *)(temp_3 + 0) & 8)) {
        return 0;
    }
    temp_16 = *(s32 *)(temp_3 + 0x20);
    if ((temp_16 & 0x7F7FFFFF) && !(temp_16 & 0x80800000)) {
        var_19 = 0;
        goto loop_outer_test;
loop_outer_body:
        temp_17 = 1 << var_19;
        if (temp_16 & temp_17) {
            var_18 = 0;
            goto loop_inner_test;
loop_inner_body:
            if (func_002340c0((u8 *)(
                *(s32 *)(*(u8 **)(*(u8 **)(arg0 + (var_18 * 4) + 0x38) + 0x30) + 0xA64)),
                temp_17) != 0) {
                var_18 += 1;
                goto loop_inner_test;
            } else {
                goto loop_inner_exit;
            }
loop_inner_test:
            if (var_18 < *(u16 *)(arg0 + 0x6A)) {
                goto loop_inner_body;
            }
loop_inner_exit:
            if (var_18 != *(u16 *)(arg0 + 0x6A)) {
                goto loop_outer_after;
            }
        }
loop_outer_increment:
        var_19 += 1;
loop_outer_test:
        if (var_19 < 0x20U) {
            goto loop_outer_body;
        }
loop_outer_after:
        if (var_19 == 0x20) {
            if (temp_16 & 0x3000) {
                var_2 = 7;
            } else {
                var_2 = 3;
            }
            return var_2;
        }
    }
done:
        return 0;
}
/* measured: candidate object 284B/window 288B, normalized_diff 1. Committed at nd 1. */
// FUN_001FB360
s32 func_001fb360(u8 *arg0, s32 arg1)
{
    s32 temp_16;
    s32 temp_5;
    s32 var_2;
    u32 var_17;
    u8 *temp_3;

    if (arg1 <= 0) {
        return 0;
    }
    temp_3 = iGpffffb3b8 + (arg1 * 0x28);
    if (!(*(u8 *)(temp_3 + 0) & 8)) {
        return 0;
    }
    temp_16 = *(s32 *)(temp_3 + 0x20);
    if ((temp_16 & 0x7C7FFFFF) && !(temp_16 & 0x83800000)) {
        var_17 = 0;
        goto loop_test;
loop_body:
        temp_5 = 1 << var_17;
        if (!(temp_16 & temp_5)) {
            goto loop_increment;
        }
        if (func_002340c0((u8 *)(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64)),
                          temp_5) == 0) {
            goto loop_after_call;
        }
loop_increment:
        var_17 += 1;
loop_test:
        if (var_17 < 0x20U) {
            goto loop_body;
        }
loop_after_call:
        if (var_17 == 0x20) {
            if (temp_16 & 0x3000) {
                var_2 = 7;
            } else {
                var_2 = 3;
            }
            return var_2;
        }
    }
    return 0;
}
/* Matched: the textured colour-quad Im2D upload (four 0x40-byte vertices).
   Conventions follow the matched code1_004b func_004b2780 (640/448 display
   scales, D_008872FC_abs depth, raw-offset stores) and the (f32)(u32)
   byte-colour idiom.  Levers: `x = a + (-b) * c` contracts to
   adda.s/madd.s; staging each negation as its own local emits lui + neg.s
   instead of a folded negative constant; staging each display-field
   conversion in a float local puts the lwc1 before the divide; the
   float-first signature is ABI-identical to the draft's order and fixes
   the mov.s materialisation order.  The opt_propagation-off bracket is
   load-bearing: without it the D_00887300 base rematerialises per call
   and the frame shrinks from 0x1A0 to 0x190. */
#pragma push
#pragma opt_propagation off
// FUN_001FB480
void func_001fb480(f32 scale, u8 *arg0, s32 arg1, s32 arg2, u8 *arg3)
{
    struct {
        u8 packet[0xF0];
        u8 pad[0x10];
    } work;
    f32 sx;
    f32 sy;
    f32 x0;
    f32 y0;
    f32 x1;
    f32 y1;
    f32 z;
    f32 inv;
    f32 cx;
    f32 cy;
    f32 w320;
    f32 w224;
    f32 n320;
    f32 n224;
    f32 f;
    f32 g;
    BattleRenderStateFunction *base;
    u8 *cam;
    u8 *disp;
    extern u8 *func_00401b80(void);
    extern void (*D_00887310[])(u32 arg0, void *arg1, u32 arg2);
    extern f32 fGpffff82e8;
    extern f32 fGpffff82ec;

    cam = (u8 *)func_00457120();
    disp = func_00401b80();
    f = (f32)*(s32 *)(disp + 0xC);
    sx = 640.0f / f;
    g = (f32)*(s32 *)(disp + 0x10);
    sy = 448.0f / g;
    x1 = 640.0f;
    y1 = 448.0f;
    if (scale == 0.0f) {
        x0 = 0.0f;
        y0 = 0.0f;
    } else {
        w320 = 320.0f;
        n320 = -w320;
        cx = fGpffff82e8;
        x0 = cx + n320 * scale;
        w224 = 224.0f;
        n224 = -w224;
        cy = fGpffff82ec;
        y0 = cy + n224 * scale;
        x1 = cx + w320 * scale;
        y1 = cy + w224 * scale;
    }
    base = D_00887300;
    base[0](rwRENDERSTATESHADEMODE, (void *)2);
    base[0](rwRENDERSTATECULLMODE, (void *)1);
    base[0](rwRENDERSTATEFOGENABLE, (void *)0);
    base[0](rwRENDERSTATEZTESTENABLE, (void *)0);
    base[0](rwRENDERSTATEZWRITEENABLE, (void *)0);
    base[0](rwRENDERSTATETEXTUREFILTER, arg3);
    base[0](rwRENDERSTATEVERTEXALPHAENABLE, (void *)1);
    base[0](rwRENDERSTATETEXTURERASTER, disp);
    func_003f6440(2, (void *)arg1);
    func_003f6440(3, (void *)arg2);
    z = *(f32 *)D_008872FC_abs;
    inv = 1.0f / *(f32 *)(cam + 0x84);
    *(f32 *)(work.packet + 0x00) = x0;
    *(f32 *)(work.packet + 0x04) = y0;
    *(f32 *)(work.packet + 0x08) = z;
    *(f32 *)(work.packet + 0x20) = (f32)(u32)arg0[0];
    *(f32 *)(work.packet + 0x24) = (f32)(u32)arg0[1];
    *(f32 *)(work.packet + 0x28) = (f32)(u32)arg0[2];
    *(f32 *)(work.packet + 0x2C) = (f32)(u32)arg0[3];
    *(f32 *)(work.packet + 0x18) = inv;
    *(s32 *)(work.packet + 0x10) = 0;
    *(s32 *)(work.packet + 0x14) = 0;
    *(f32 *)(work.packet + 0x40) = x0;
    *(f32 *)(work.packet + 0x44) = y1;
    *(f32 *)(work.packet + 0x48) = z;
    *(f32 *)(work.packet + 0x60) = (f32)(u32)arg0[0];
    *(f32 *)(work.packet + 0x64) = (f32)(u32)arg0[1];
    *(f32 *)(work.packet + 0x68) = (f32)(u32)arg0[2];
    *(f32 *)(work.packet + 0x6C) = (f32)(u32)arg0[3];
    *(f32 *)(work.packet + 0x58) = inv;
    *(s32 *)(work.packet + 0x50) = 0;
    *(f32 *)(work.packet + 0x54) = sy;
    *(f32 *)(work.packet + 0x80) = x1;
    *(f32 *)(work.packet + 0x84) = y0;
    *(f32 *)(work.packet + 0x88) = z;
    *(f32 *)(work.packet + 0xA0) = (f32)(u32)arg0[0];
    *(f32 *)(work.packet + 0xA4) = (f32)(u32)arg0[1];
    *(f32 *)(work.packet + 0xA8) = (f32)(u32)arg0[2];
    *(f32 *)(work.packet + 0xAC) = (f32)(u32)arg0[3];
    *(f32 *)(work.packet + 0x98) = inv;
    *(f32 *)(work.packet + 0x90) = sx;
    *(s32 *)(work.packet + 0x94) = 0;
    *(f32 *)(work.packet + 0xC0) = x1;
    *(f32 *)(work.packet + 0xC4) = y1;
    *(f32 *)(work.packet + 0xC8) = z;
    *(f32 *)(work.packet + 0xE0) = (f32)(u32)arg0[0];
    *(f32 *)(work.packet + 0xE4) = (f32)(u32)arg0[1];
    *(f32 *)(work.packet + 0xE8) = (f32)(u32)arg0[2];
    *(f32 *)(work.packet + 0xEC) = (f32)(u32)arg0[3];
    *(f32 *)(work.packet + 0xD8) = inv;
    *(f32 *)(work.packet + 0xD0) = sx;
    *(f32 *)(work.packet + 0xD4) = sy;
    D_00887310[0](4, work.packet, 4);
    base[0](1, 0);
}
#pragma pop
/* Native b210 -O2 recovery: 1620 bytes plus 12 zero tail bytes.
   The state table is addressed through uintptr_t so ordinary propagation
   retains its base while reloading each callback. Ordinary common-subexpression
   optimization gives both unsigned alpha conversions their retail temporaries.
   The radial draw takes depth before packed color in both owners.
   See docs/probe_archive/BattleAction_20260922_resume.md. */
// FUN_001FBB50
#pragma push
#pragma opt_propagation on
#pragma opt_common_subs on
s32 func_001fbb50(u8 *work) {
    void *savedStates[7];
    struct {
        union { s32 word; u8 bytes[4]; } radial;
        u8 screen[4];
    } colors;
    f32 fadeProgress;
    f32 layerScale;
    s32 result;
    u32 stateIndex;

    if (func_003e8120(func_00457120()) == 0) {
        return 0;
    }
    result = 0;
    for (stateIndex = 0; stateIndex < 7; stateIndex++) {
        u32 offset = stateIndex * sizeof(savedStates[0]);
        D_00887304[0](*(RwRenderState *)((u8 *)D_00625210 + offset), (u8 *)savedStates + offset);
    }
    work = *(u8 **)(work + 0x38);
    {
        u32 state = *work;
        switch (state) {
        case 0:
            break;
        case 1: {
            u32 countdown = D_0076455C;
            if (countdown == 0) {
                f32 square;
                uintptr_t stateInterface;

                D_0076455A++;
                fadeProgress = (f32)(u32)D_0076455A / 20.0f;
                /* Keep the table address; each draw state reloads its callback. */
                stateInterface = (uintptr_t)D_00887300;
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATESHADEMODE, (void *)2);
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATECULLMODE, (void *)1);
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATEFOGENABLE, (void *)0);
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATEZTESTENABLE, (void *)0);
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATEZWRITEENABLE, (void *)0);
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATEVERTEXALPHAENABLE, (void *)1);
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATETEXTURERASTER, (void *)0);
                func_003f6440(2, (void *)0x44);
                func_003f6440(3, (void *)0x31801);
                func_00489f80();
                colors.screen[2] = colors.screen[1] = colors.screen[0] = 0xFF;
                square = fadeProgress * fadeProgress;
                {
                    f32 progressCubed = fadeProgress * square;
                    f32 progressFourth = fadeProgress * progressCubed;
                    f32 progressFifth = fadeProgress * progressFourth;
                    f32 screenOpacity = 255.0f * (1.0f - fadeProgress * progressFifth);
                    u8 screenAlpha = (u8)screenOpacity;
                    colors.screen[3] = screenAlpha;
                }
                func_0045c870(colors.screen, 0);
                colors.radial.bytes[2] = colors.radial.bytes[1] = colors.radial.bytes[0] = 0xFF;
                {
                    f32 radialOpacity = 160.0f * (1.0f - square);
                    u8 radialAlpha = (u8)radialOpacity;
                    colors.radial.bytes[3] = radialAlpha;
                }
                layerScale = 1.5f * ((f32)(u32)D_0076455A / 20.0f);
                func_00457120();
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATESHADEMODE, (void *)2);
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATECULLMODE, (void *)1);
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATEFOGENABLE, (void *)0);
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATEZTESTENABLE, (void *)0);
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATEZWRITEENABLE, (void *)0);
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATEVERTEXALPHAENABLE, (void *)1);
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATETEXTURERASTER, (void *)0);
                func_003f6440(2, (void *)0x44);
                func_003f6440(3, (void *)0x31801);
                func_00204690(0, layerScale, layerScale, D_008872FC_abs[0], colors.radial.word);
                func_0048a000();
                func_001fb480(1.0f, (u8 *)&D_007635C8, 0x54, 0x31801, (u8 *)1);
                if ((s32)D_0076455A >= 0x14) {
                    *work = 3;
                }
                break;
            }
            D_0076455C = countdown - 1;
            /* Continue the waiting-state draw after decrementing. */
        }
        case 2: {
            if (iGpffffb469 == 0) {
                func_001fb480(1.0f, (u8 *)&D_007635C8, 0x44, 0x31801, (u8 *)1);
                if (*(u16 *)(work + 6) == 1) {
                    layerScale = D_007613E0;
                } else {
                    layerScale = D_007613E4;
                }
                colors.screen[2] = colors.screen[1] = colors.screen[0] = 0xFF;
                {
                    u8 alpha;

                    if (*(u16 *)(work + 6) == 1) {
                        alpha = 6;
                    } else {
                        alpha = 0x0A;
                    }
                    colors.screen[3] = alpha;
                }
                func_001fb480(layerScale, colors.screen, 0x44, 0x31801, (u8 *)2);
                colors.screen[3] = 5;
                func_001fb480(layerScale, colors.screen, 0x48, 0x31801, (u8 *)2);
            }
            break;
        }
        case 3: {
            if (func_00122720() != 0) {
                func_00122640(1, 0x1E);
                iGpffffb468 = 0;
                result = -1;
            }
            break;
        }
        default:
            break;
        }
        {
            u32 k;

            for (k = 0; k < 7; k++) {
                u32 offset = k * sizeof(savedStates[0]);
                D_00887300[0](*(RwRenderState *)((u8 *)D_00625210 + offset), *(void **)((u8 *)savedStates + offset));
            }
        }
        D_00887300[0](rwRENDERSTATETEXTURERASTER, NULL);
        func_003f6440(2, (void *)0x44);
        func_003f6440(3, (void *)0x717FB);
        func_003e8110(func_00457120());
    }
    return result;
}
#pragma pop
// FUN_001FC1B0
void func_001fc1b0(s16 arg0) {
    if (func_00452380(&D_006251F0) == 0) {
        iGpffffb468 = 2;
        iGpffffb46e = arg0;
        iGpffffb469 = 0;
        (s32)func_00451de0((const void *)(&D_006251F0), 0xC9, 0, 0, func_001fbb50, 0, (u8 *)((void *)&iGpffffb468));
    }
}
// FUN_001FC270
s32 func_001fc270(void)
{
    return 1;
}
// FUN_001FC280
void func_001fc280(void) {
    iGpffffb469 = 1;
    func_00122520(1, 1);
    func_001228a0(0xFF, 0xFF, 0xFF);
}
/* measured: opt_loop_invariants on keeps the table base and the constant 1 hoisted above the
   scan loop as retail; the mode-1 blocks are `var = 1; if (slot == arg0) { t = var; } else
   { var = 0; t = var; } return (s8)t;` - the copy at the join keeps the then-branch as
   retail's `b join` trampoline (the plain if/else folds to xor/sltiu under rebuildconditionals,
   which must stay off for these two blocks). */
// FUN_001FC300
#pragma opt_loop_invariants on
#pragma opt_rebuildconditionals off
s64 func_001fc300(u8 *arg0, u8 *arg1)
{
    extern s32 D_00881440_abs[];
    u8 *table;
    s32 temp_8;
    s32 var_10;
    s32 one;
    s64 var_2;
    s64 t;
    s64 var_2_2;
    u32 temp_6;
    u8 temp_3;
    u8 temp_3_2;

    if (*(u8 *)(arg1 + 3) != 0) {
        return 1;
    }
    var_10 = 0;
    table = (u8 *)D_00881440_abs;
    one = 1;
    goto loop_test;
loop_body:
    temp_8 = *(s32 *)(table + ((u16)var_10 * 4) + 8);
    if (temp_8 != 0) {
        if ((*(u8 *)(arg1 + 2) & (one << temp_6)) &&
            ((u8 *)temp_8 == arg0)) {
            return 1;
        }
        var_10 = (var_10 + 1) & 0xFFFF;
        goto loop_test;
    }
    goto block_9;
loop_test:
    temp_6 = var_10 & 0xFFFF;
    if (temp_6 < 3U) {
        goto loop_body;
    }
block_9:
    if ((D_00881440_abs[0] != 0) &&
        (*(u8 *)(arg0 + 0xA2) ==
         *(u8 *)(D_00881440_abs[0] + 0xA2))) {
        temp_3 = *(u8 *)(arg1 + 0);
        switch (temp_3) {
        case 0:
            return 0;
        case 1:
            var_2_2 = 1;
            if (D_00881440_abs[0] == (s32)arg0) {
                t = var_2_2;
            } else {
                var_2_2 = 0;
                t = var_2_2;
            }
            return (s64)(t << 0x38) >> 0x38;
        case 2:
            return 1;
        }
    }
    if ((D_00881440_abs[1] != 0) &&
        (*(u8 *)(arg0 + 0xA2) ==
         *(u8 *)(D_00881440_abs[1] + 0xA2))) {
        temp_3_2 = *(u8 *)(arg1 + 1);
        switch (temp_3_2) {
        case 0:
            return 0;
        case 1:
            var_2 = 1;
            if (D_00881440_abs[1] == (s32)arg0) {
                t = var_2;
            } else {
                var_2 = 0;
                t = var_2;
            }
            return (s64)(t << 0x38) >> 0x38;
        case 2:
            return 1;
        }
    }
    return 0;
}
/* measured: restore rebuildconditionals after func_001fc300. */
#pragma opt_rebuildconditionals on
/* measured: restore the unit default after func_001fc300. */
#pragma opt_loop_invariants off
