#include "include_asm.h"
#include "rw_geometry_internal.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "effect_vu0_internal.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

// 64 bytes. Layout from P3FES include/rw/rwplcore.h.
typedef struct RwMatrix
{
    RwV3d right;   // 0x00
    u32 flags;     // 0x0c
    RwV3d up;      // 0x10
    u32 pad1;      // 0x1c
    RwV3d at;      // 0x20
    u32 pad2;      // 0x2c
    RwV3d pos;     // 0x30
    u32 pad3;      // 0x3c
} RwMatrix;

extern void func_004861f0(u8 *arg0, f32 *arg1);
extern void effMiscQuatMultiplyVU(void);
extern void effMiscBuildRotationVU(void);
extern void func_00486400(u8 *arg0, f32 arg1);
extern void chkmemAllocSiteTag(const void *msg, s32 id);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void kAssertFail(void *file, s32 line);
extern u8 D_007132F0[];
extern u8 D_00713470[];
extern u8 D_00713488[];
extern u8 D_0071348C[];
extern u8 D_00713480[];
extern u8 D_00713494[];
extern u8 D_00713490[];
extern void *memset(void *dst, s32 value, u32 size);
extern u8 D_0071349C[];
extern u8 D_007134A0[];
extern u8 D_007134A8[];
extern u8 D_007134B0[];
extern char D_00713CE0[];
extern f32 fGpffff8044;


extern void (*jtbl_008873EC[])(void *);
static inline f32 code1_0048_mul(f32 left, f32 right) {
    return left * right;
}
static inline void code1_0048_call(s32 (*fn)(s32), s32 value) {
    fn(value);
}

/* Source unit: src/promoted/code1_0048.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0048.c; members 00485b20-004865c0 */

extern u_long128 func_00484b30(u8 *arg0);
extern void func_00486330(u8 *arg0, u8 *arg1);
extern void mdlEffectApplyPackedColor(u8 *arg0, s32 arg1);
static inline void model_normalize_packed_color(const u32 *source, f32 scale)
{
    u32 scaleBits;
    __asm__ volatile(
        "lw $2, 0(%1)\n"
        "pextlb $2, $zero, $2\n"
        "pextlh $2, $zero, $2\n"
        "qmtc2 $2, $vf10\n"
        "vitof0.xyzw $vf10, $vf10\n"
        "mfc1 %0, %2\n"
        "nop\n"
        "qmtc2 %0, $vf2\n"
        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
        : "=&r"(scaleBits)
        : "r"(source), "f"(scale), "m"(*source)
        : "$2", "$vf2", "$vf10", "memory");
}
/* measured: MWCCPS2 b210 -O2, 120B/window 128B, three relocations,
 * eight zero alignment bytes. IDA retains the result that Ghidra drops:
 * retail leaves the copied quadword in v0 through return. Preserve that
 * live-out; the current C callers discard it. The four hardware vf0 stores
 * produce (0,0,0,1), not a zero quadword. */
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
// FUN_00485B20
void func_00485b20(u8 *arg0)
{
    u8 *var_18;
    u8 *temp_17;
    u8 *temp_16;
    u8 *temp_4;
    u8 *temp_4_2;

    var_18 = *(u8 **)(arg0 + 0x8C);
    goto loop_00485b20_check;
loop_00485b20_body:
    temp_17 = *(u8 **)(var_18 + 0xAC);
    if ((*(s32 *)(var_18 + 0x98) & 1) == 0) {
        temp_16 = *(u8 **)(var_18 + 0x90);
        if (*(s32 *)(temp_16 + 8) != 0) {
            if (*(s32 *)(D_00713480 + (*(u16 *)(temp_16 + 4) << 6) + 0x10) == 0) {
                kAssertFail(D_00713470, 0x2EB);
            }
            (*(void (**)(s32))(D_00713480 + (*(u16 *)(temp_16 + 4) << 6) + 0x10))(
                *(s32 *)(temp_16 + 8));
        }
        temp_4 = *(u8 **)(temp_16 + 0x18);
        if (temp_4 != NULL) {
            jtbl_008873EC[0](temp_4);
            *(s32 *)(temp_16 + 0x10) = 0;
            *(s32 *)(temp_16 + 0x14) = 0;
            *(u8 **)(temp_16 + 0x18) = NULL;
        }
        temp_4_2 = *(u8 **)(temp_16 + 0x28);
        if (temp_4_2 != NULL) {
            jtbl_008873EC[0](temp_4_2);
            *(s32 *)(temp_16 + 0x20) = 0;
            *(s32 *)(temp_16 + 0x24) = 0;
            *(u8 **)(temp_16 + 0x28) = NULL;
        }
        jtbl_008873EC[0](temp_16);
    }
    jtbl_008873EC[0](var_18);
    var_18 = temp_17;
loop_00485b20_check:
    if (var_18 != NULL) {
        goto loop_00485b20_body;
    }
    jtbl_008873EC[0](arg0);
}

/* measured: object 852B/window 864B, nd 0. The allocator table address lives in
   a saved register (`alloc = jtbl_008873E8` after the first assert-log call),
   which needs opt_propagation off so the first call does not fold the constant
   back in; `> 0xD2` gives retail's `sltiu $at` form where `>= 0xD3` colours
   into $v0; the 16-byte stack quadword is zeroed with the tree's `sqc2 vf0`
   idiom before the two calls that read it. */
// FUN_00485C80
/* measured: opt_propagation off keeps `alloc` live in $s1 across all three
   allocations instead of re-materialising the table address at the first use. */
/* measured: func_00485c80 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
u8 *func_00485c80(u8 *arg0)
{
    u_long128 sp80;
    u8 *clone;
    u8 *node;
    u8 *nodeClone;
    u8 *src;
    u8 *prim;
    u16 kind;
    void *(**alloc)(u32, u32);

    if (*(u8 **)(arg0 + 0x8C) == NULL) {
        kAssertFail(D_00713470, 0x6B7);
    }
    chkmemAllocSiteTag(D_00713470, 0x546);
    alloc = jtbl_008873E8;
    clone = (u8 *)alloc[0](0x90, 0x40000);
    if (clone == NULL) {
        kAssertFail(D_00713470, 0x547);
    }
    memset(clone, 0, 0x90);
    *(s32 *)(clone + 0x80) = 0;
    *(s32 *)(clone + 0x84) = 0;
    func_00484b30(clone);
    *(u_long128 *)clone = *(u_long128 *)arg0;
    *(u_long128 *)(clone + 0x10) = *(u_long128 *)(arg0 + 0x10);
    *(f32 *)(clone + 0x74) = *(f32 *)(arg0 + 0x74);
    *(s32 *)(clone + 0x68) = *(s32 *)(arg0 + 0x68);
    for (node = *(u8 **)(arg0 + 0x8C); node != NULL; node = *(u8 **)(node + 0xAC)) {
        chkmemAllocSiteTag(D_00713470, 0x559);
        nodeClone = (u8 *)alloc[0](0xC0, 0x40000);
        if (nodeClone == NULL) {
            kAssertFail(D_00713470, 0x55A);
        }
        memset(nodeClone, 0, 0xC0);
        memset(nodeClone, 0, 0x90);
        *(s32 *)(nodeClone + 0x84) = 1;
        *(u8 *)(nodeClone + 0x88) = 8;
        *(u8 *)(nodeClone + 0x89) = 0;
        *(u8 *)(nodeClone + 0x8A) = 0;
        func_00484b30(nodeClone);
        src = *(u8 **)(node + 0x90);
        if (*(u32 *)src > 0xD2) {
            kAssertFail(D_00713470, 0x318);
        }
        kind = *(u16 *)(src + 4);
        chkmemAllocSiteTag(D_00713470, 0x21);
        prim = (u8 *)alloc[0](0x2C, 0x40000);
        if (prim == NULL) {
            kAssertFail(D_00713470, 0x22);
        }
        memset(prim, 0, 0x2C);
        *(s32 *)prim = 0xD2;
        *(u16 *)(prim + 4) = kind;
        *(u16 *)(prim + 0xC) = *(u16 *)(src + 0xC);
        *(u16 *)(prim + 0x1C) = *(u16 *)(src + 0x1C);
        if (*(EffectInstanceConstructor *)(D_00713480 + (*(u16 *)(prim + 4) << 6) + 0x14) == NULL) {
            kAssertFail(D_00713470, 0x321);
        }
        *(void **)(prim + 8) =
            (*(EffectInstanceConstructor *)(D_00713480 + (*(u16 *)(prim + 4) << 6) + 0x14))(*(void **)(src + 8));
        *(u8 **)(nodeClone + 0x90) = prim;
        mdlEffectCopyRecord(nodeClone, node);
        *(s32 *)(nodeClone + 0xAC) = 0;
        if (*(u8 **)(clone + 0x88) != NULL) {
            *(u8 **)(*(u8 **)(clone + 0x88) + 0xAC) = nodeClone;
            *(u8 **)(nodeClone + 0xB0) = *(u8 **)(clone + 0x88);
        } else {
            *(u8 **)(clone + 0x8C) = nodeClone;
            *(u8 **)(nodeClone + 0xB0) = NULL;
        }
        *(u8 **)(clone + 0x88) = nodeClone;
        *(s32 *)(clone + 0x80) += 1;
    }
    __asm__ volatile ("sqc2 vf0, 0(%0)" : : "r"(&sp80) : "memory");
    func_004861f0(clone, (f32 *)&sp80);
    func_00486330(clone, (u8 *)&sp80);
    func_00486400(clone, 1.0f);
    mdlEffectApplyPackedColor(clone, -1);
    return clone;
}

/* measured: closes the propagation bracket; the file default is on. */
// FUN_00485FE0
void func_00485fe0(u8 *arg0) {
    u8 *n = *(u8 **)(arg0 + 0x8C);
    u8 *o;
    void (*fn)(s32);

    while (n != NULL) {
        o = *(u8 **)(n + 0x90);
        fn = *(void (**)(s32))(D_00713480 + (*(u16 *)(o + 4) << 6) + 0x1C);
        if (fn != NULL) {
            fn(*(s32 *)(o + 8));
        }
        n = *(u8 **)(n + 0xAC);
    }
    *(s32 *)(arg0 + 0x84) = 0;
}

// FUN_00486060
s32 func_00486060(u8 *arg0) {
    s32 (*temp_2)(s32);
    s32 var_2;
    u8 *temp_4;
    u8 *var_16;

    var_16 = *(u8 **)(arg0 + 0x8C);
    goto loop_00486060_check;
loop_00486060_body:
    temp_4 = *(u8 **)(var_16 + 0x90);
    temp_2 = *(s32 (**)(s32))(D_00713480 +
        (*(u16 *)(temp_4 + 4) << 6) + 0x34);
    if (temp_2 != NULL) {
        var_2 = temp_2(*(s32 *)(temp_4 + 8));
    } else {
        var_2 = 1;
    }
    if (var_2 == 0) {
        return 0;
    }
    var_16 = *(u8 **)(var_16 + 0xAC);
loop_00486060_check:
    if (var_16 != NULL) {
        goto loop_00486060_body;
    }
    return 1;
}

// FUN_004860F0
s32 func_004860f0(u8 *arg0) {
    s32 (*temp_2)(s32);
    s32 var_2;
    u8 *temp_4;
    u8 *var_16;

    var_16 = *(u8 **)(arg0 + 0x8C);
    goto loop_004860f0_check;
loop_004860f0_body:
    temp_4 = *(u8 **)(var_16 + 0x90);
    temp_2 = *(s32 (**)(s32))(D_00713480 +
        (*(u16 *)(temp_4 + 4) << 6) + 0x38);
    if (temp_2 != NULL) {
        var_2 = temp_2(*(s32 *)(temp_4 + 8));
    } else {
        var_2 = 0;
    }
    if (var_2 != 0) {
        return 1;
    }
    var_16 = *(u8 **)(var_16 + 0xAC);
loop_004860f0_check:
    if (var_16 != NULL) {
        goto loop_004860f0_body;
    }
    return 0;
}

// FUN_00486180
void func_00486180(u8 *arg0)
{
    u8 *var_16 = *(u8 **)(arg0 + 0x8C);

    while (var_16 != NULL) {
        u8 *temp_5 = *(u8 **)(var_16 + 0x90);
        void (*temp_3)(s32, u8 *) =
            *(void (**)(s32, u8 *))(D_00713480 + (*(u16 *)(temp_5 + 4) << 6) + 0x3C);

        if (temp_3 != NULL) {
            temp_3(*(s32 *)(temp_5 + 8), temp_5);
        }
        var_16 = *(u8 **)(var_16 + 0xAC);
    }
}

// FUN_004861F0
void func_004861f0(u8 *arg0, f32 *arg1)
{
    u_long128 sp50[4];
    u_long128 sp40;
    u_long128 sp30;
    f32 var_21;
    f32 var_20;
    s32 flags;
    u8 *temp_4;
    s32 (*temp_2)(s32, void *, u8 *);

    __asm__ volatile("lqc2 $vf10, 0($5)" : : : "$vf10", "memory");
    __asm__ volatile("sqc2 $vf10, 0x40(%0)" : : "r"(arg0) : "$vf10", "memory");
    __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(arg0) : "$vf11", "memory");
    __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(&sp40) : "$vf10", "memory");
    __asm__ volatile("lqc2 $vf10, 0x50(%0)" : : "r"(arg0) : "$vf10", "memory");
    effMiscBuildRotationVU();
    __asm__ volatile(
        "sqc2 $vf28, 0(%0)     \n"
        "sqc2 $vf29, 16(%0)    \n"
        "sqc2 $vf30, 32(%0)    \n"
        "sqc2 $vf31, 48(%0)    \n"
        :
        : "r"(&sp50)
        : "$vf28", "$vf29", "$vf30", "$vf31", "memory");
    var_21 = *(f32 *)(arg0 + 0x60) * *(f32 *)(arg0 + 0x74);
    arg0 = *(u8 **)(arg0 + 0x8C);
    var_20 = 5.0f;
    goto loop_004861f0_check;
loop_004861f0_body:
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&sp40) : "$vf10", "memory");
    flags = *(s32 *)(arg0 + 0x68);
    if ((flags & 4) != 0) {
        __asm__ volatile(
            "mfc1 $2, %0       \n"
            "nop               \n"
            "qmtc2.ni $2, $vf2 \n"
            "vaddx.y $vf10, $vf0, $vf2x \n"
            :
            : "f"(var_20)
            : "$2", "$vf2", "$vf10", "memory");
    }
    __asm__ volatile("lqc2 $vf11, 0x40(%0)" : : "r"(arg0) : "$vf11", "memory");
    if ((flags & 0x80) != 0) {
        __asm__ volatile(
            "mfc1 $3, %0       \n"
            "nop               \n"
            "qmtc2.ni $3, $vf2 \n"
            "vmulx.xyzw $vf11, $vf11, $vf2x \n"
            :
            : "f"(var_21)
            : "$3", "$vf2", "$vf11", "memory");
    }
    __asm__ volatile(
        "lqc2 $vf28, 0(%0)     \n"
        "lqc2 $vf29, 16(%0)    \n"
        "lqc2 $vf30, 32(%0)    \n"
        "lqc2 $vf31, 48(%0)    \n"
        :
        : "r"(&sp50)
        : "$vf28", "$vf29", "$vf30", "$vf31", "memory");
    __asm__ volatile(
        "vmulax.xyzw $ACC, $vf28, $vf11x \n"
        "vmadday.xyzw $ACC, $vf29, $vf11y \n"
        "vmaddz.xyzw $vf11, $vf30, $vf11z \n"
        "vadd.xyzw $vf10, $vf10, $vf11 \n"
        :
        :
        : "$vf10", "$vf11", "ACC", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(&sp30) : "$vf10", "memory");
    temp_4 = *(u8 **)(arg0 + 0x90);
    temp_2 = *(s32 (**)(s32, void *, u8 *))(D_00713480 + (*(u16 *)(temp_4 + 4) << 6) + 0x20);
    if (temp_2 != NULL) {
        temp_2(*(s32 *)(temp_4 + 8), &sp30, temp_4);
    }
    arg0 = *(u8 **)(arg0 + 0xAC);
loop_004861f0_check:
    if (arg0 != NULL) {
        goto loop_004861f0_body;
    }
}

// FUN_00486330
void func_00486330(u8 *arg0, u8 *arg1)
{
    u_long128 scratch[2];
    u8 *temp_4;
    u8 *var_16;
    s32 (*temp_2)(s32, void *);

    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(arg1) : "$vf10", "memory");
    __asm__ volatile("sqc2 $vf10, 0x50(%0)" : : "r"(arg0) : "$vf10", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(scratch + 1) : "$vf10", "memory");
    effMiscBuildRotationVU();
    __asm__ volatile(
        "lqc2 $vf10, 0x10(%0)       \n"
        "vmulax.xyzw $ACC, $vf28, $vf10x \n"
        "vmadday.xyzw $ACC, $vf29, $vf10y \n"
        "vmaddz.xyzw $vf10, $vf30, $vf10z \n"
        "sqc2 $vf10, 0(%0)          \n"
        :
        : "r"(arg0)
        : "$vf10", "ACC", "memory");
    var_16 = *(u8 **)(arg0 + 0x8C);
    goto loop_00486330_check;
loop_00486330_body:
    __asm__ volatile("lqc2 $vf10, 0x50(%0)" : : "r"(var_16) : "$vf10", "memory");
    __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(scratch + 1) : "$vf11", "memory");
    effMiscQuatMultiplyVU();
    __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(scratch) : "$vf10", "memory");
    temp_4 = *(u8 **)(var_16 + 0x90);
    temp_2 = *(s32 (**)(s32, void *))(D_00713480 + (*(u16 *)(temp_4 + 4) << 6) + 0x24);
    if (temp_2 != NULL) {
        temp_2(*(s32 *)(temp_4 + 8), scratch);
    }
    var_16 = *(u8 **)(var_16 + 0xAC);
loop_00486330_check:
    if (var_16 != NULL) {
        goto loop_00486330_body;
    }
    func_004861f0(arg0, (f32 *)(arg0 + 0x40));
}

// FUN_00486400
void func_00486400(u8 *arg0, f32 arg1)
{
    u_long128 sp50;
    u_long128 sp40;
    f32 var_21;
    f32 var_20;
    f32 temp_f12;
    f32 temp_f0;
    s32 flags;
    u8 *temp_4;
    u8 *var_16;
    void (*temp_3)(s32, u8 *, f32);
    void (*temp_3_2)(s32, void *, u8 *);
    void (*temp_3_3)(s32, void *, u8 *);

    *(f32 *)(arg0 + 0x60) = arg1;
    var_21 = arg1 * *(f32 *)(arg0 + 0x74);
    var_16 = *(u8 **)(arg0 + 0x8C);
    var_20 = 5.0f;
    goto loop_00486400_check;
loop_00486400_body:
    flags = *(s32 *)(var_16 + 0x68);
    if ((flags & 0x100) == 0) {
        temp_f12 = *(f32 *)(var_16 + 0x60);
        if ((*(s32 *)(var_16 + 0x84) & 1) != 0) {
            temp_f12 *= var_21;
        }
        temp_4 = *(u8 **)(var_16 + 0x90);
        temp_3 = *(void (**)(s32, u8 *, f32))(D_00713480 + (*(u16 *)(temp_4 + 4) << 6) + 0x28);
        if (temp_3 != NULL) {
            temp_3(*(s32 *)(temp_4 + 8), temp_4, temp_f12);
        }
        goto loop_00486400_tail;
    }
    __asm__ volatile("lqc2 $vf10, 0x20(%0)" : : "r"(var_16) : "$vf10", "memory");
    temp_f0 = *(f32 *)(var_16 + 0x60);
    if ((*(s32 *)(var_16 + 0x84) & 1) != 0) {
        temp_f0 *= var_21;
    }
    __asm__ volatile(
        "mfc1 $3, %0       \n"
        "nop               \n"
        "qmtc2.ni $3, $vf2 \n"
        "vmulx.xyzw $vf10, $vf10, $vf2x \n"
        :
        : "f"(temp_f0)
        : "$3", "$vf2", "$vf10", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(&sp40) : "$vf10", "memory");
    temp_4 = *(u8 **)(var_16 + 0x90);
    temp_3_2 = *(void (**)(s32, void *, u8 *))(D_00713480 + (*(u16 *)(temp_4 + 4) << 6) + 0x2C);
    if (temp_3_2 != NULL) {
        temp_3_2(*(s32 *)(temp_4 + 8), &sp40, temp_4);
    }
loop_00486400_tail:
    flags = *(s32 *)(var_16 + 0x68);
    if ((flags & 0x80) != 0) {
        __asm__ volatile("lqc2 $vf10, 0x40(%0)" : : "r"(arg0) : "$vf10", "memory");
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(arg0) : "$vf11", "memory");
        __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
        if ((flags & 4) != 0) {
            __asm__ volatile(
                "mfc1 $2, %0       \n"
                "nop               \n"
                "qmtc2.ni $2, $vf2 \n"
                "vaddx.y $vf10, $vf0, $vf2x \n"
                :
                : "f"(var_20)
                : "$2", "$vf2", "$vf10", "memory");
        }
        __asm__ volatile("lqc2 $vf11, 0x40(%0)" : : "r"(var_16) : "$vf11", "memory");
        __asm__ volatile(
            "mfc1 $3, %0       \n"
            "nop               \n"
            "qmtc2.ni $3, $vf2 \n"
            "vmulx.xyzw $vf11, $vf11, $vf2x \n"
            :
            : "f"(var_21)
            : "$3", "$vf2", "$vf11", "memory");
        __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(&sp50) : "$vf10", "memory");
        temp_4 = *(u8 **)(var_16 + 0x90);
        temp_3_3 = *(void (**)(s32, void *, u8 *))(D_00713480 + (*(u16 *)(temp_4 + 4) << 6) + 0x20);
        if (temp_3_3 != NULL) {
            temp_3_3(*(s32 *)(temp_4 + 8), &sp50, temp_4);
        }
    }
    var_16 = *(u8 **)(var_16 + 0xAC);
loop_00486400_check:
    if (var_16 != NULL) {
        goto loop_00486400_body;
    }
}

// Stores arg1 at +0x64 and normalises it into each child node's packed colour (node +0x64), walking the child list at +0x8C.
// FUN_004865C0
/* measured: 276B/288B, instruction-exact after relocation normalization; 12B zero tail.
 * Only the packed-word/VU bridges are assembly; locals and traversal remain C. */
void mdlEffectApplyPackedColor(u8 *arg0, s32 arg1)
{
    u32 baseColor;
    u32 childColor;
    u32 packedColor;
    f32 parent[4] __attribute__((aligned(16)));
    f32 scale;
    const u32 *source;
    u8 *node;
    u8 *data;
    void (*callback)(s32, u32);
    u32 color;
    u32 work;

    *(s32 *)(arg0 + 0x64) = arg1;
    baseColor = (u32)arg1;
    source = &baseColor;
    scale = fGpffff8044;
    model_normalize_packed_color(source, scale);
    __asm__ volatile("sqc2 $vf10, 0(%1)\n"
        : "=m"(parent) : "r"(parent) : "memory");

    node = *(u8 **)(arg0 + 0x8C);
    if (node != NULL) {
        while (node != NULL) {
            childColor = *(u32 *)(node + 0x64);
            source = &childColor;
            model_normalize_packed_color(source, scale);
            __asm__ volatile(
                "lqc2 $vf11, 0(%0)\n"
                "vmul.xyzw $vf10, $vf10, $vf11\n"
                : : "r"(parent), "m"(parent)
                : "$vf10", "$vf11", "memory");
            work = 0x437F0000U; /* Binary32 255.0f, transferred to VF2.x. */
            __asm__ volatile(
                "qmtc2 %0, $vf2\n"
                "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                "vftoi0.xyzw $vf10, $vf10\n"
                "qmfc2 %0, $vf10\n"
                "ppach %0, $zero, %0\n"
                "ppacb %0, $zero, %0\n"
                "sw %0, packedColor\n"
                : "+r"(work), "=m"(packedColor)
                : : "$vf2", "$vf10", "memory");
            color = packedColor;
            data = *(u8 **)(node + 0x90);
            callback = *(void (**)(s32, u32))(
                D_00713480 + *(u16 *)(data + 4) * 0x40 + 0x30);
            if (callback != NULL) {
                callback(*(s32 *)(data + 8), color);
            }
            node = *(u8 **)(node + 0xAC);
        }
    }
}

