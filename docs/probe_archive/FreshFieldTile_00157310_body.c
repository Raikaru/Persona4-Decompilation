/* Fresh field tile-placement candidate: func_00157310.
 * Owner src/promoted/code1_0015.c. PRODUCTION REMAINS ASM.
 * Preferred defined-anchor arithmetic replay:1076/1008 bytes,nd723,26 object
 * relocations,68 overrun bytes. Separating placement/neighbor loop cursors ties
 * size and regresses to nd724. Scoped opt_loop_invariants on applies only here.
 * The old unprototyped func_00157310 declaration must be replaced by the complete
 * (u8*,u16,u16,s16) declaration in a disposable owner when replaying. Production
 * callers/prototype are intentionally unchanged while this candidate remains ASM.
 * 
 * Negative signed anchors pass retail's signed upper-bound-only comparisons.
 * The agent's signed left shifts on those values were replaced with multiplication
 * by256/16, preserving defined arithmetic for negative offsets. Do not invent a
 * nonnegative-anchor invariant or turn returning assertions into early exits.
 * Actual pointers must still refer to valid storage; no total work-buffer capacity
 * or all-input memory-safety claim is inferred from the per-cell stride.
 * 
 * Retail uses16-byte cell stride and256-byte row stride, with occupancy at
 * work+0x54+row*256+column*16. These offsets are relative to work, not offsets
 * inside a16-byte cell. Tile templates are86 bytes in the existing001579B0 caller;
 * the5x5 mask occupies0x18..0x30, per-block attributes occupy0x32..0x55. Preserve
 * every work accessor and subsequent source/anchor reload; callbacks are not pure.
 * The assertion checks do not establish coordinate ranges because they return.
 * No native/Wasm behavioral verification or exact-match claim is made.
 */

extern void func_00157310(u8 *,u16,u16,s16);
#pragma push
#pragma opt_loop_invariants on
/* Fresh field tile placement recovery: func_00157310.
 * Owner: src/promoted/code1_0015.c marker 432. Retail window 1008 bytes (0x3F0).
 * Reconstructed ordinary C preserving all 16-bit parameter truncation,
 * tile shape offsets, pointer shifts, callback reloads, and GP-relative counters.
 */

extern u32 D_00764318;
extern u32 D_0076431C;
extern u32 D_00764320;

// FUN_00157310
void func_00157310(u8 *tile, u16 x, u16 y, s16 direction)
{
    s32 i;
    s32 j;
    s32 placed = 0;

    if ((s32)(x + tile[1] - 1) >= 0x10) {
        func_0046d730(D_005F05E8, 0x20B);
    }
    if ((s32)(y + tile[2] - 1) >= 0x18) {
        func_0046d730(D_005F05E8, 0x20C);
    }

    *((u8 *)func_00155280() + (y << 8) + (x << 4) + 0x55) = 1;

    for (j = 0; j < tile[2]; j++) {
        for (i = 0; i < tile[1]; i++) {
            if (*((u8 *)func_00155280() + ((y + j) << 8) + ((x + i) << 4) + 0x54) == 0 &&
                tile[0x18 + (j - (s8)tile[0x17]) * 5 + (i - (s8)tile[0x16])] == 1) {
                *((u8 *)func_00155280() + ((y + j) << 8) + ((x + i) << 4) + 0x54) = 1;
                *((u8 *)func_00155280() + ((y + j) << 8) + ((x + i) << 4) + 0x55) |= tile[0xD + j * 3 + i];
                *((u8 *)func_00155280() + ((y + j) << 8) + ((x + i) << 4) + 0x5E) = tile[0x32 + (j * 3 + i) * 4];
                *((u8 *)func_00155280() + ((y + j) << 8) + ((x + i) << 4) + 0x5A) = tile[1];
                *((u8 *)func_00155280() + ((y + j) << 8) + ((x + i) << 4) + 0x5B) = tile[2];
                *((u8 *)func_00155280() + ((y + j) << 8) + ((x + i) << 4) + 0x58) = tile[0];
                *((u8 *)func_00155280() + ((y + j) << 8) + ((x + i) << 4) + 0x59) = (u8)direction;
                *((u8 *)func_00155280() + ((y + j) << 8) + ((x + i) << 4) + 0x5F) = tile[0x33 + (j * 3 + i) * 4];
                placed = 1;
            }
        }
    }

    if (placed == 1) {
        for (j = 0; j < 5; j++) {
            for (i = 0; i < 5; i++) {
                if (((s8)tile[0x17] + y + j < 24) &&
                    ((s8)tile[0x16] + x + i < 16)) {
                    if (*((u8 *)func_00155280() + (((s8)tile[0x17] + y + j) * 0x100) + (((s8)tile[0x16] + x + i) * 0x10) + 0x54) == 0 &&
                        tile[0x18 + j * 5 + i] != 0) {
                        *((u8 *)func_00155280() + (((s8)tile[0x17] + y + j) * 0x100) + (((s8)tile[0x16] + x + i) * 0x10) + 0x54) = 2;
                    }
                }
            }
        }
    }

    D_00764320++;
    if ((s8)tile[0] == 2) {
        D_00764318++;
    }
    if ((s8)tile[0] >= 9) {
        D_0076431C++;
    }
    D_00764314 += tile[1] * tile[2];
}

#pragma pop
