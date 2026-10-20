/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0045b430-0045b430 */

#include "include_asm.h"
#include "type.h"
#include "primitive_rectangle_packet.h"
#include "shd_misc_internal.h"
#include "Kosaka/k_clump_internal.h"
#include "rw_types_internal.h"
/* Six 0x44-byte render slots; initialization proves the fields below. */
typedef struct MdlRenderSlot {
    s16 state;
    u8 pad2[2];
    s32 unk4;
    u8 pad8[2];
    s16 index;
    u8 padC[0xC];
    s32 unk18;
    u8 pad1C[0x28];
} MdlRenderSlot;

extern void func_00430e28(void);
extern void func_00430f80();
extern void func_0043bb70();
extern void func_0043c008(s32 value);
extern void func_0043c010(s32 value);
extern void func_0043c0c0();
extern s32 func_0043bcb8();
extern u8 D_008E4090[];
extern u8 D_008E4230[];
extern s32 D_008E4018_abs[];
extern s32 D_008E40B4_abs[];
extern s32 D_008E40F8_abs[];
extern s32 D_008E413C_abs[];
extern s32 D_008E4180_abs[];
extern s32 D_008E41C4_abs[];
extern s32 D_008E4208_abs[];
#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants on
/* Initialize render state, reset six slots, and allocate their backing buffers. */
/* Initialize render state, reset six slots and allocate their backing buffers. */
// FUN_0045B430
void mdlRenderInitializeBuffers(void) {
    s16 i;
    s16 j;

    func_00430e28();
    func_0043c008(0);
    func_0043c010(0x20);
    func_0043bb70(D_008E4230, 0x20, 0);
    func_0043c0c0(0, 0x8F, 0);
    func_0043c0c0(3, 0x83, 0x105, 0x3C, 0);
    func_0043c0c0(3, 0x84, 0x3C, 0x3C);
    func_0043c0c0(3, 0x82, 1);
    func_00430f80(1, 0x8010, 0x800, 0xFC0);
    func_00430f80(1, 0x8010, 0x801, 0xFCC);
    func_0043c0c0(3, 0x80, 0x7F, 0x7F);
    for (i = 0; i < 6; i++) {
        ((MdlRenderSlot *)(D_008E4090 + i * 0x44))->state = 0;
        ((MdlRenderSlot *)(D_008E4090 + i * 0x44))->unk4 = 0;
        ((MdlRenderSlot *)(D_008E4090 + i * 0x44))->unk18 = 0;
        ((MdlRenderSlot *)(D_008E4090 + i * 0x44))->index = i;
    }
    j = 0;
    D_008E4018_abs[0] = 0;
    /* Preserve the retail setup loop even though this recovered body has no loop stores. */
    for (; j < 0x10; j++) {
    }
    D_008E40B4_abs[0] = func_0043bcb8(0x64000);
    D_008E40F8_abs[0] = func_0043bcb8(0xE1000);
    D_008E413C_abs[0] = func_0043bcb8(0x19000);
    D_008E4180_abs[0] = func_0043bcb8(0x19000);
    D_008E41C4_abs[0] = func_0043bcb8(0x19000);
    D_008E4208_abs[0] = func_0043bcb8(0x19000);
}
#pragma pop
