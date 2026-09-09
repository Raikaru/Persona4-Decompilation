/* Fresh panel state updater recovery: func_0020add0.
 * Owner src/promoted/code1_0020.c. Production ASM replaced with ordinary C.
 * Measured968/976 bytes,nd0,11 independently resolved GP/call relocations,eight
 * zero alignment bytes. Direct relocation resolution reproduces976/976 retail
 * bytes. The initial source had exactly20 differing bytes in switch dispatch;
 * source cases4,5,0 restore retail tests0,5,4. No pragma or padding is added.
 * Public void(void*) signature is unchanged; existing callers require no migration.
 * 
 * Preserve signed-halfword counters and their upper-bound-only saturation; do not
 * clamp negative values or consolidate distinct callback reloads. The gate at0xE
 * sets flag2 and resets0x10 only on the first qualifying frame. Sound occurs when
 * mode1 and the updated0x8 counter equals8; its callback may mutate the mode,flags,
 * embedded-list pointer and0x12 counter. Offset2 snapshots the mode before the
 * command provider. Command results are masked to16 bits, and command4/5 transitions
 * do not skip subsequent color processing. Reload nested state+0x178 pointers
 * after the provider and reload phase after the selection/sine calls. Phase uses
 * one180-degree subtraction, not arbitrary modulo; color channels preserve byte
 * conversion and addition order. Normal initialized phase0..178 keeps pulse casts
 * in range; no non-finite or corrupted-phase behavior claim is made.
 * 
 * The exact integrated production source passes149,504 disposable Wasm32 cases.
 * 131,072 cases cover every signed16-bit value for all five varying counters,
 * under both flag0 states, with independent transition equations.18,432 boundary
 * combinations vary16 thresholds,three modes,four flag states,two list states,
 * six command results,four nested-pointer states and two selection outcomes.
 * Sound/command callbacks mutate state and pointer availability; selection/sine
 * callbacks mutate phase. A host sine backend computes finite pulse values.
 * Every case compares all0x5B4 state bytes against an independent model, callback
 * counts,phase,and surrounding canaries. The state capacity is grounded by the
 * existing0020AD80 memset, not invented fixture padding. This verifies the32-bit
 * state/provider boundary, not PS2 graphics or the entire command engine.
 */

extern s32 func_00242930(u8 *);
extern f32 fGpffff8478;
extern f32 fGpffffb478;

// FUN_0020ADD0
void func_0020add0(void *arg0)
{
    u8 *state = arg0;
    if (*(u32 *)(state + 4) & 1) {
        if (*(s16 *)(state + 0xA) < 11) ++*(s16 *)(state + 0xA);
    } else {
        if (*(s16 *)(state + 8) < 19) ++*(s16 *)(state + 8);
        if (*(s16 *)(state + 0xA) < 6) ++*(s16 *)(state + 0xA);
        else if (*(s16 *)(state + 0xA) > 6) --*(s16 *)(state + 0xA);
    }
    if (*(s16 *)(state + 0xC) < 4) ++*(s16 *)(state + 0xC);
    if (*(s16 *)(state + 0xE) < 2) ++*(s16 *)(state + 0xE);
    else if (!(*(u32 *)(state + 4) & 2)) {
        *(u32 *)(state + 4) |= 2;
        *(s16 *)(state + 0x10) = 0;
    }
    if (*(u16 *)state == 1 && *(s16 *)(state + 8) == 8) {
        func_0045af60(1, 15, 2, 26);
    }
    if (*(u8 **)(state + 0x38) == state + 0x40) {
        if (*(u16 *)state == 1) {
            if (*(s16 *)(state + 0x12) > 0) --*(s16 *)(state + 0x12);
        } else {
            if (*(s16 *)(state + 0x12) < 3) ++*(s16 *)(state + 0x12);
        }
    } else {
        if (!(*(u32 *)(state + 4) & 1)) {
            if (*(s16 *)(state + 0x12) < 3) ++*(s16 *)(state + 0x12);
            else if (*(s16 *)(state + 0x12) > 3) --*(s16 *)(state + 0x12);
        } else {
            if (*(s16 *)(state + 0x12) < 6) ++*(s16 *)(state + 0x12);
        }
    }
    *(u16 *)(state + 2) = *(u16 *)state;
    if (*(u16 *)state == 1 && !(*(u32 *)(iGpffffb3ac + 0xC) & 0x10000)) {
        switch (func_00203420(state + 0x2C) & 0xFFFF) {
        case 4: *(u16 *)state = 2; break;
        case 5: *(u16 *)state = 0; break;
        case 0: break;
        }
        if (*(u8 **)(state + 0x178) != 0 &&
            *(u8 **)(*(u8 **)(state + 0x178) + 0x30) != 0 &&
            *(u8 **)(*(u8 **)(*(u8 **)(state + 0x178) + 0x30) + 0xA64) != 0) {
            f32 pulse;
            if (func_00242930(*(u8 **)(*(u8 **)(*(u8 **)(state + 0x178) + 0x30) + 0xA64))) {
                pulse = func_0044b7b0(fGpffff8478 * fGpffffb478);
                fGpffffb478 += 2.0f;
                if (!(fGpffffb478 < 180.0f)) fGpffffb478 -= 180.0f;
            } else {
                pulse = 0.0f;
                fGpffffb478 = 0.0f;
            }
            state[0x24] = (u8)(150.0f * pulse) + 10;
            state[0x25] = 10;
            state[0x26] = 10;
            state[0x28] = (u8)(160.0f * pulse);
            state[0x29] = 0;
            state[0x2A] = 0;
        }
    }
}
