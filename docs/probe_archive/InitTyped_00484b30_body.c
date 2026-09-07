/* Faithful typed floor: 120B/128B, normalized_diff=6. Six executable
 * v1/v0 color differences at +0x2c/+0x30/+0x38/+0x3c/+0x40/+0x44;
 * fndiff additionally counts two retail zero-tail words.
 * All five inspected callers discard the result: keep void(u8*).
 * Historical F480 archive remains preserved. No promotion. */
#include "type.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));

/* The retail initializer owns the first 0x80 bytes of both 0x90-byte and
 * 0xc0-byte allocations. Unidentified fields keep offset-based names. */
typedef struct Code48InitialState {
    f32 vector00[4];
    f32 vector10[4];
    u_long128 quad20;
    u8 unknown30[0x10];
    f32 vector40[4];
    f32 vector50[4];
    f32 scale60;
    u32 packedRGBA;
    u32 flags;
    u32 unknown6c;
    u32 unknown70;
    f32 scale74;
    u32 unknown78[2];
} Code48InitialState;

extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern char D_00713CE0[];

#pragma push
#pragma opt_propagation off
// FUN_00484B30
void func_00484b30(u8 *arg0)
{
    Code48InitialState *state = (Code48InitialState *)(void *)arg0;
    const u_long128 *quadSource;

    func_0043f9c8(state, 0, sizeof(*state));
    /* VF0 is the hardware unit vector (0,0,0,1), not a zero quadword. */
    __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(state) : "memory");
    __asm__ volatile("sqc2 vf0, 16(%0)" : : "r"(state) : "memory");
    __asm__ volatile("sqc2 vf0, 64(%0)" : : "r"(state) : "memory");
    state->vector40[1] = 5.0f;
    __asm__ volatile("sqc2 vf0, 80(%0)" : : "r"(state) : "memory");
    quadSource = (const u_long128 *)(const void *)D_00713CE0;
    state->quad20 = *quadSource;
    state->scale60 = 1.0f;
    state->scale74 = 1.0f;
    state->packedRGBA = 0xFFFFFFFF;
    state->flags = 0x80;
}
#pragma pop
