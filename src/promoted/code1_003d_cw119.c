#include "include_asm.h"
#include "type.h"

/* RenderWare-derived functions verified with MWCCPS2 3.0.1 b119 (see
   config/compiler_units.txt and docs/matching.md). Fallbacks stay under
   asm/nonmatchings/code1_003d. */
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define va_start(ap, last) (ap = (va_list)(s32)(__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8))
extern void func_003cfa80(u8 *arg0, s32 arg1, f32 arg2, f32 arg3);
extern u8 *func_003dda50(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_004217e0(u8 *arg0);
extern s32 **func_003ce050();
extern s32 iGpffffb728;
extern s32 iGpffffb730;
extern s32 iGpffffb72c;
extern s32 iGpffffab50;
extern s32 D_00887180[];
extern s32 D_00887184[];
extern s32 D_00887188[];
extern s32 D_0088718C[];
extern void *D_00887194[];
extern u8 D_008871A0[];
extern s32 D_008871A4[];
extern s32 D_008871A8[];
extern s32 D_00724840;
extern u8 D_008872E0[];
extern u8 D_00887150[];
extern s32 iGpffffab1c;
extern s32 iGpffffab20;
extern s32 iGpffffb760;
extern s32 D_00724844;
extern u8 D_0070C260[];
extern s32 func_003d2720(void);
extern u8 *func_003db360(u8 *arg0, u8 *arg1);
extern u8 *func_003d5790(s32 arg0, s32 arg1);
extern s32 func_003db480(s32 *arg0, s32 arg1);
extern s32 func_003dd530(u8 *arg0, s32 arg1);
extern s32 D_0070B470[];
extern void func_003d3e60(void);
extern void func_003d0fa0(void);
extern void func_003cdfa0(u8 *arg0);
extern s32 func_003e8930(s32 arg0, s32 arg1, void *arg2, void *arg3);
extern u8 *func_00412520();
extern u8 **func_004125d0();
extern s32 func_003d4f20(s32 arg0);
extern void (*jtbl_008873EC[])();
extern s32 func_003e2ab0();
extern s32 func_003de8c0(u8 *arg0, s32 arg1);
extern s32 func_003d59d0(u8 *arg0, f32 amount);
extern s32 func_003d5bc0(u8 *arg0, f32 amount);
extern s32 iGpffffb738;
extern s32 iGpffffb734;
extern void func_003e12f0();
extern void func_0043f810(void *dst, void *src, u32 size);
extern u8 *(*jtbl_008873E8[])(s32 arg0, s32 arg1);
extern void func_00426f80(s32 arg0);
extern s32 func_003c1ab0();
extern s32 func_003c1b40();
extern s32 func_003c2b70();
extern s32 func_003c8d00();
extern s32 func_003c8d60();
extern s32 D_00886E50[];
extern s32 func_003df590(s64 arg0, ...);
extern u8 *func_003df4d0();
extern void func_003d5840(u8 *arg0, u8 *arg1);
extern s32 **func_003ddc10(void);
extern void func_00421800(s32 arg0);
extern void func_00421820(s32 arg0);
extern s32 iGpffffb754;
static inline s32 func_003d_add_offset(s32 base, s32 offset) {
    return base + offset;
}
extern s32 D_0072483C;
extern s32 D_0072484C;
extern s32 (*D_008873C8[])(u8 *, u8 *);
extern s32 (*D_008873D0[])(u8 *, s32);
extern void func_00421800(s32 arg0);
extern void func_00421820(s32 arg0);
extern s32 iGpffffb754;
extern s32 D_0072484C;
extern s32 D_00724854;

// FUN_003D86A0
/* F3D1 archive func_003d86a0: object 188B/window 192B, normalized_diff 41, differing words 0x34 (0x1000 addiu vs retail lui), 0x58 (branch target), and 0x84-0xBC (cleanup indirect-call sequence shifted one word; object is 4B short); classification: near-match with exact prologue/first callback/loop body, but cleanup entry needs one retail nop and the immediate materialisation remains addiu. Retail uses sq, not the GCC sd separator. Corrected func_003d8500 to five parameters including hidden t0 argument, swapped temp/count declaration order to recover $s4/$s5, and used explicit count<0 guard plus do/while with no_branch_likely; these made offsets 0x00-0x30 and 0x38-0x80 byte-exact. */
#pragma schedule on
#pragma no_branch_likely on
s32 func_003d86a0(s8 *arg0, s32 arg1, u8 *arg2) {
    s32 result;
    s32 count;
    u8 *temp;
    s32 value;
    extern s32 func_003d8500(s8 *, u8 *, s32, s32, u8 *);

    result = 0;
    temp = jtbl_008873E8[0](3 * *(s32 *)(arg2 + 4), 0x10000);
    count = *(s32 *)(arg2 + 8) - 1;
    if (count < 0) {
        goto cleanup;
    }
    do {
        value = func_003d8500(arg0, arg2, count, arg1, temp);
        count--;
        result += value;
    } while (count >= 0);
cleanup:
    jtbl_008873EC[0](temp);
    return result;
}
#pragma no_branch_likely off
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off

// FUN_003DE280
/* Lane P3DE_0003: func_003de280 under -O2,p. Tried: direct u32 value local with schedule on + no_branch_likely on. Residual: lw $v0,0x58($a0) and the first sll are swapped in the positive branch; object 52 vs window 64. */
#pragma push
#pragma schedule on
#pragma no_branch_likely on
s32 func_003de280(u8 *arg0, u32 arg1) {
    u32 base;
    u32 offset;
    if (!(arg1 < *(u32 *)(arg0 + 4))) {
        goto zero;
    }
    offset = arg1 << 3;
    offset -= arg1;
    offset <<= 4;
    base = *(u32 *)(arg0 + 0x58);
    return base + offset;
zero:
    return 0;
}
#pragma pop

#define va_end(ap) ((void)0)
/* Archived b210 near-miss (Y3D5_003d0460); exact under b119 with schedule on. */
// FUN_003D0460
#pragma schedule on
void func_003d0460(u8 *arg0, u32 **arg1, s32 arg2, s32 arg3) {
    extern u8 *func_003e1ff0(u8 *arg0);
    u32 *var_2;
    u8 *temp_16;

    if (*(s32 *)(arg0 + 0x24) == 0) {
        temp_16 = *(u8 **)(*(u8 **)(arg0 + 8) + 0x18);
        if (*(s32 *)(temp_16 + 8) & 0x02000000) {
            *arg1 = (u32 *)(*jtbl_008873E8)(arg2 + 0x18, 0x3050D);
            *(u32 *)(*arg1) = 0;
            *(s32 *)((u8 *)(*arg1) + 4) = 0;
            *(u8 **)((u8 *)(*arg1) + 0xC) = temp_16;
            *(s32 *)((u8 *)(*arg1) + 8) = arg2;
            *(s32 *)((u8 *)(*arg1) + 0x10) = (s32)arg1;
            *(s32 *)((u8 *)(*arg1) + 0x14) = arg3;
        } else {
            var_2 = (u32 *)func_003e1ff0(temp_16);
            *arg1 = var_2;
        }
    } else {
        var_2 = (u32 *)func_003e1ff0(*(u8 **)(arg0 + 8));
        *arg1 = var_2;
    }
}
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off

/* Archived b210 near-miss (Y3D5_003d0850); exact under b119 with schedule on. */
// FUN_003D0850
#pragma schedule on
u32 *func_003d0850(u8 *arg0, u32 **arg1, s32 arg2, s32 arg3) {
    extern u8 D_008872E4[];
    extern u8 *func_003e1ff0(u8 *arg0);
    extern void func_003d0460(u8 *arg0, u32 **arg1, s32 arg2, s32 arg3);
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 8);
    if (*temp_16 == 0xFF) {
        if (*(s32 *)(*(u8 **)(D_008872E4) + 8) & 0x02000000) {
            *arg1 = (u32 *)(*jtbl_008873E8)(arg2 + 0x18, 0x3050D);
            *(u32 *)(*arg1) = 0;
            *(s32 *)((u8 *)(*arg1) + 4) = 0;
            *(u8 **)((u8 *)(*arg1) + 0xC) = temp_16;
            *(s32 *)((u8 *)(*arg1) + 8) = arg2;
            *(s32 *)((u8 *)(*arg1) + 0x10) = (s32)arg1;
            *(s32 *)((u8 *)(*arg1) + 0x14) = arg3;
        } else {
            *arg1 = (u32 *)func_003e1ff0(temp_16);
        }
    } else {
        func_003d0460(arg0, arg1, arg2, arg3);
    }
    return *arg1;
}
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off

/* Archived b210 near-miss (K3D5_003d5790); exact under b119 with schedule on. */
// FUN_003D5790
#pragma schedule on
u8 *func_003d5790(s32 arg0, s32 arg1) {
    u8 *temp_2;
    s32 size;

    size = arg0 * arg1;
    temp_2 = jtbl_008873E8[0](size + 0x4C, 0x3001B);
    *(s32 *)(temp_2 + 0x2C) = arg0;
    *(s32 *)(temp_2 + 0x0) = 0;
    *(s32 *)(temp_2 + 0x8) = 0;
    *(s32 *)(temp_2 + 0x4) = 0;
    *(s32 *)(temp_2 + 0xC) = 0;
    *(s32 *)(temp_2 + 0x14) = 0xBF800000;
    *(s32 *)(temp_2 + 0x10) = 0;
    *(s32 *)(temp_2 + 0x18) = 0;
    *(s32 *)(temp_2 + 0x1C) = 0;
    *(s32 *)(temp_2 + 0x24) = arg1;
    *(s32 *)(temp_2 + 0x28) = -1;
    *(s32 *)(temp_2 + 0x20) = arg1;
    *(s32 *)(temp_2 + 0x30) = 0;
    *(s32 *)(temp_2 + 0x34) = 0;
    *(s32 *)(temp_2 + 0x38) = (s32)temp_2;
    *(s32 *)(temp_2 + 0x3C) = 0;
    *(s32 *)(temp_2 + 0x44) = 0;
    *(s32 *)(temp_2 + 0x40) = 0;
    *(s32 *)(temp_2 + 0x48) = 0;
}
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off

/* Archived b210 near-miss (F3D0_003d59a0); exact under b119 with schedule on. */
// FUN_003D59A0
#pragma schedule on
s32 func_003d59a0(u8 *arg0, u8 *arg1) {
    func_0043f810(arg0 + 0x4C, arg1 + 0x4C,
        *(s32 *)(arg0 + 0x24) * *(s32 *)(arg0 + 0x2C));
    return 1;
}
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off

extern s32 func_003db440(s32 arg0, u8 *arg1);
/* Archived b210 near-miss (Y3DB_003db490); exact under b119 with schedule on. */
// FUN_003DB490
#pragma schedule on
s32 func_003db490(s32 arg0, u8 *arg1) {
    f32 value;
    s32 count;
    extern u8 *func_003ca320(u8 *arg0, s32 (*arg1)(u8 *, s32), s32 arg2);
    extern s32 func_003db440(s32 arg0, u8 *arg1);
    extern f32 func_0044b968(f32 arg0);
    extern s32 *func_003f6800(s32 *arg0, f32 fparg0);

    *(s32 *)(arg1 + 8) = arg0;
    *(s32 *)(arg1 + 0xC) = 0;
    *(s32 *)(arg1 + 0x10) = 0;
    func_003ca320(*(u8 **)(arg1 + 4),
                  (s32 (*)(u8 *, s32))func_003db440, (s32)arg1);
    count = *(s32 *)(arg1 + 0x10);
    if (count > 0) {
        value = func_0044b968(*(f32 *)(arg1 + 0xC) / (f32)count);
        func_003f6800((s32 *)arg0, -(value / func_0044b968(2.0f)));
    }
    return arg0;
}
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off

extern s32 *func_003ddc20(u8 *arg0);
/* Archived b210 near-miss (Y3DA_003dd620); exact under b119 with schedule on. */
// FUN_003DD620
#pragma schedule on
s32 func_003dd620(u8 *arg0, u8 *arg1) {
    extern s32 *func_003ddc20(u8 *arg0);
    extern void (*D_008873AC[])(u8 *arg0, u8 *arg1);
    extern s32 (*D_008873D4[])(u8 *arg0);

    if (func_003ddc20(arg1) != NULL) {
        return 7;
    }
    if (*(u8 **)(arg0 + 0xC) != NULL) {
        (*jtbl_008873EC)(*(u8 **)(arg0 + 0xC));
    }
    *(u8 **)(arg0 + 0xC) = (*jtbl_008873E8)(D_008873D4[0](arg1) + 1, 0x401BE);
    D_008873AC[0](*(u8 **)(arg0 + 0xC), arg1);
    return 1;
}
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off

/* Archived b210 near-miss (K3D5_003df1a0); exact under b119 with schedule on. */
#pragma schedule on
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off

/* measured: switch with direct returns in ascending case order; 0xd returns 0. */
#pragma schedule on
/* measured: closes the schedule bracket. */
#pragma schedule off

// FUN_003D3460
#pragma schedule on
s32 func_003d3460(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 **var_2;
    u8 *temp_2;
    u32 var_5;
    u8 *var_4;
    s32 var_5_2;

    if (arg0 == 0) {
        return 0;
    }
    if (arg1 <= 0) {
        return 0;
    }
    if (arg2 < 3) {
        return 0;
    }
    if (arg3 <= 0) {
        return 0;
    }

    var_2 = (u8 **)(func_004125d0());
    if ((var_2 != NULL) && (M2C_FIELD(var_2, s32 *, 0x3C) & 0x1C)) {
        return 0;
    }
    if (var_2 == NULL) {
        temp_2 = (u8 *)(func_00412520(arg0, 0x40));
        if (temp_2 != NULL) {
            var_5 = 0;
            var_4 = temp_2;
            do {
                M2C_FIELD(var_4, s32 *, 0) = 0;
                var_5 += 5;
                M2C_FIELD(var_4, s32 *, 4) = 0;
                M2C_FIELD(var_4, s32 *, 8) = 0;
                M2C_FIELD(var_4, s32 *, 0xC) = 0;
                M2C_FIELD(var_4, s32 *, 0x10) = 0;
                var_4 += 0x14;
            } while (var_5 < 0xA);

            M2C_FIELD(temp_2, s32 *, 0x3C) = 0;
            M2C_FIELD(temp_2, s32 *, 0x38) = 4;
            M2C_FIELD(temp_2, s32 *, 0x34) = (s32) (M2C_FIELD(temp_2, s32 *, 0x38) * 0x45);
            M2C_FIELD(temp_2, s32 *, 0x30) = (s32) (M2C_FIELD(temp_2, s32 *, 0x38) * 0x45);
            var_5_2 = 1;
        } else {
            var_5_2 = 0;
        }
        if (var_5_2 == 0) {
            return 0;
        }
        var_2 = (u8 **)(func_004125d0(arg0, var_5_2));
    }

    M2C_FIELD(var_2, s32 *, 0x34) = (s32) (arg1 * (arg3 * 3));
    M2C_FIELD(var_2, s32 *, 0x30) = (s32) (arg2 * arg1);
    M2C_FIELD(var_2, s32 *, 0x38) = arg1;
    M2C_FIELD(var_2, s32 *, 0x3C) = 3;
    return arg0;
}
#pragma schedule off
// FUN_003D35F0
#pragma schedule on
s32 func_003d35f0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 **var_2;
    u8 *temp_2;
    u32 var_5;
    u8 *var_4;
    s32 var_5_2;

    if (arg0 == 0) {
        return 0;
    }
    if (arg1 <= 0) {
        return 0;
    }
    if (arg2 < 2) {
        return 0;
    }
    if (arg3 <= 0) {
        return 0;
    }

    var_2 = (u8 **)(func_004125d0());
    if ((var_2 != NULL) && (M2C_FIELD(var_2, s32 *, 0x3C) & 0x13)) {
        return 0;
    }
    if (var_2 == NULL) {
        temp_2 = (u8 *)(func_00412520(arg0, 0x40));
        if (temp_2 != NULL) {
            var_5 = 0;
            var_4 = temp_2;
            do {
                M2C_FIELD(var_4, s32 *, 0) = 0;
                var_5 += 5;
                M2C_FIELD(var_4, s32 *, 4) = 0;
                M2C_FIELD(var_4, s32 *, 8) = 0;
                M2C_FIELD(var_4, s32 *, 0xC) = 0;
                M2C_FIELD(var_4, s32 *, 0x10) = 0;
                var_4 += 0x14;
            } while (var_5 < 0xA);

            M2C_FIELD(temp_2, s32 *, 0x3C) = 0;
            M2C_FIELD(temp_2, s32 *, 0x38) = 4;
            M2C_FIELD(temp_2, s32 *, 0x34) = (s32) (M2C_FIELD(temp_2, s32 *, 0x38) * 0x45);
            M2C_FIELD(temp_2, s32 *, 0x30) = (s32) (M2C_FIELD(temp_2, s32 *, 0x38) * 0x45);
            var_5_2 = 1;
        } else {
            var_5_2 = 0;
        }
        if (var_5_2 == 0) {
            return 0;
        }
        var_2 = (u8 **)(func_004125d0(arg0, var_5_2));
    }

    M2C_FIELD(var_2, s32 *, 0x34) = (s32) (arg1 * (arg3 * 2));
    M2C_FIELD(var_2, s32 *, 0x30) = (s32) (arg2 * arg1);
    M2C_FIELD(var_2, s32 *, 0x38) = arg1;
    M2C_FIELD(var_2, s32 *, 0x3C) = 0xC;
    return arg0;
}
/* measured: closes the schedule bracket. */
#pragma schedule off

// FUN_003D5E90
#pragma schedule on
s32 func_003d5e90(u8 *arg0, u8 *arg1, u8 *arg2, f32 fparg0) {
    s32 index;
    s32 has_items;
    s32 count;

    index = 0;
    count = *(s32 *)(arg0 + 0x2C);
    has_items = (0 < count);
    if (has_items == 0) {
        goto done;
    }
    do {
        s32 off0;
        s32 off1;
        s32 off2;
        u8 *p0;
        u8 *p1;
        u8 *p2;

        off0 = index * *(s32 *)(arg0 + 0x24);
        p0 = (u8 *)(off0 + (s32)arg0);
        off1 = index * *(s32 *)(arg1 + 0x24);
        p1 = (u8 *)(off1 + (s32)arg1);
        off2 = index * *(s32 *)(arg2 + 0x24);
        p2 = (u8 *)(off2 + (s32)arg2);
        ((void (*)(u8 *, u8 *, u8 *, f32))(*(u32 *)(arg0 + 0x40)))(
            p0 + 0x4C,
            p1 + 0x4C,
            p2 + 0x4C,
            fparg0);
        index += 1;
    } while (*(s32 *)(arg0 + 0x2C) > index);
done:
    return 1;
}
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off

