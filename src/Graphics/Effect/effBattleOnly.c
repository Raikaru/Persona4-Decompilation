#include "include_asm.h"
/* Source unit: src/Graphics/Effect/effBattleOnly_004b50f0.c */
#include "type.h"

void func_0046d730(u8 *file, s32 line);
void func_0044ea90(u8 *file, s32 line);
void *memcpy(void *dst, const void *src, s32 size);

extern u8 D_007146A0[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);

typedef struct EffBattleEntry
{
    void (*postCreate)(void *obj);       // 0x00
    s32 (*setup)(void *obj, u16 id, s32 a, s32 b); // 0x04
    u8 pad[0x10];                        // 0x08
    s32 size;                            // 0x18
} EffBattleEntry;                        // 0x1C

typedef struct EffBattleWork
{
    u8 zero[0x20];  // 0x00
    f32 alpha;      // 0x20
    u32 color;      // 0x24
    s32 count;      // 0x28
    s32 id;         // 0x2C
    s32 setupResult;// 0x30
    u8 pad[4];      // 0x34
    u8 *data;       // 0x38
} EffBattleWork;    // 0x40

/* BSS: per-type effect hook table pointer (gp -0x4460) and the "battle
 * effect active" check callback (gp -0x445C), initialised by startup code.
 * Storage is DEFINED by this unit so the linker can place it at 0x00764c90. */
EffBattleEntry *D_00764C90;  // 0x00764c90
s32 (*D_00764C94)(void);     // 0x00764c94
u8 *func_00484490(u8 *obj);
s32 func_004844d0(u8 *obj);

u8 *func_004b50f0(u16 id, s32 arg1);



// FUN_004B50F0 NONMATCHING
/* measured floor: nd 13/272 (8 words). b210 colours the u16 check mask into
 * $s0 and the table base into $a0 (retail: mask into $v0, base into $v1) and
 * transposes the table re-mask with the base load; every differing word is a
 * register-only permutation or an independent-instruction order swap with
 * identical save count/frame. Probed 15+ source shapes (tid locals, explicit
 * masks, element-typed offsets, base-first address groupings) - all stable. */
#ifdef NON_MATCHING
u8 *func_004b50f0(u16 id, s32 arg1)
{
    EffBattleWork *work;
    s32 size;

    if (id >= 0xD) {
        func_0046d730(D_007146A0, 0x1B);
    } else {
    }
    size = D_00764C90[id].size;
    func_0044ea90(D_007146A0, 0x1F);
    work = (EffBattleWork *)(*jtbl_008873E8)(size + 0x40, 0x40000);
    if (work == NULL) {
        func_0046d730(D_007146A0, 0x20);
    }
    work->data = (u8 *)work + 0x40;
    work->count = 0;
    work->id = (s32)id;
    work->color = 0x80808080;
    work->alpha = 1.0f;
    __asm__ volatile ("sqc2 vf0, 0(%0)" : : "r"(work) : "memory");
    __asm__ volatile ("sqc2 vf0, 16(%0)" : : "r"(work) : "memory");
    memcpy(work->data, (const void *)arg1, size);
    return (u8 *)work;
}
#else
INCLUDE_ASM("asm/nonmatchings/effBattleOnly", func_004b50f0);
#endif



// FUN_004B5200 NONMATCHING
/* measured floor: nd 7/320 (3 words). b210 folds the +4 setup-pointer offset
 * into the load displacement (lw 4(base+off)) and materialises (4+off) before
 * the base load; retail emits lw base, addiu base+4, addu off, lw 0. Probed
 * paren groupings, member-address (&D_00764C90->setup) forms, element-typed
 * +1 offsets and intermediate base locals - the (4+off) grouping is the
 * closest reachable shape; the transposition is b210-internal. */
#ifdef NON_MATCHING
u8 *func_004b5200(u8 *arg0)
{
    u8 *tex;
    s32 value;
    s32 param;
    u16 id16;
    u16 id;
    u8 *work;

    tex = func_00484490(arg0);
    if (tex == NULL) {
        func_0046d730(D_007146A0, 0x58);
    }
    value = func_004844d0(arg0);
    id16 = *(u16 *)(arg0 + 0x1C);
    param = *(s32 *)(arg0 + 0x24);
    id = *(u16 *)(arg0 + 0xC);
    work = func_004b50f0(id, (s32)tex);
    if ((*D_00764C94)() != 0) {
        s32 off = (id & 0xFFFF) * 0x1C;
        s32 (*setup)(void *, u16, s32, s32) =
            *(s32 (**)(void *, u16, s32, s32))((u8 *)D_00764C90 + (4 + off));
        if (setup != NULL) {
            *(s32 *)(work + 0x30) = setup(tex, id16, value, param);
        }
        {
            void (*post)(void *) =
                *(void (**)(void *))((u8 *)D_00764C90 + off);
            if (post != NULL) {
                post(work);
            }
        }
    }
    if (work == NULL) {
        func_0046d730(D_007146A0, 0x5D);
    }
    return work;
}
#else
INCLUDE_ASM("asm/nonmatchings/effBattleOnly", func_004b5200);
#endif
