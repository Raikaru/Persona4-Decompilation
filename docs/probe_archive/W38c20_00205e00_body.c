/* Current command-label floor: 488B/496B, two differing bytes/words at
 * +0x58/+0x64: addiu versus retail daddiu for 27/255. Seven relocations
 * fully resolved; eight zero-tail bytes. This ties the prior instruction
 * floor; it is not a new MATCH. All 115 owner C matches remain intact.
 * Signed/narrow/wide colors, enum/reuse and statement-lifetime variants
 * do not close the residual. No private callee declaration workaround.
 *
 * The index addition now wraps in the unsigned domain. The old body traps
 * at INT_MAX+63 under UBSan; this body passes 115,200 native32 UB-trap cases
 * with actual sprite, font-flag and message-submission providers. Packet
 * emission, message allocation/setters and queue backends are instrumented.
 * Covers coordinate rounding, low opacity bytes, nonzero predicates, packet
 * reset state, late handle reload and clearing (not restoring) font bit 0x40.
 * Enabled messages use valid fixture handles/indices. Boundary sprite IDs
 * prove producer arithmetic, not valid texture-bank indexing or raster output.
 * Production remains ASM.
 */
extern s32 func_002791f0(f32 x, f32 y, f32 scale, s32 color, s32 mode,
                           s32 style, s32 flags, s32 handle, s32 index);
// FUN_00205E00 candidate
void func_00205e00(u8 *arg0, s32 index, f32 x, f32 y,
                   s32 opacity, s32 selected, s32 draw_text)
{
    u8 *work;
    s32 color;
    f32 line_y;

    work = func_00452560(*(s32 *)(arg0 + 0x5B0));
    if (selected != 0) color = 0x1B;
    else color = 0xFF;
    line_y = 8.0f + y;
    func_00201650(work, 9, 0x3C, 48.0f + x, line_y, color, color, color, opacity);
    func_00201650(work, 9, 0x3C, 270.0f + x, line_y, color, color, color, opacity);
    func_00201650(work, 9, (s32)((u32)index + 0x3FU), 71.0f + x, y,
                  color, color, color, opacity);
    if (draw_text != 0) {
        func_00272c60(0x40);
        func_002791f0(10.0f + (2.0f + (42.0f + x) - 1.0f), 36.0f + y, 0.0f,
                      (s32)(0xFFFFFF00U | (u8)opacity), 1, 0, 0,
                      *(s32 *)(work + 0x98), index);
        func_00272c80(0x40);
    }
}
