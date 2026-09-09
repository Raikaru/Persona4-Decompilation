/* Measured 2026-09-09 in the canonical current owner: 596/608 bytes,
 * normalized_diff 4, ten resolved relocations and twelve zero-tail bytes.
 * Only glyph stack offsets +0x1C4/+0x1D8/+0x1DC/+0x1EC differ: the genuine
 * glyph[3] lives at sp+0x6C..6E instead of retail sp+0x68..6A. No unsupported
 * buffer capacity or separated scalar bytes are used to fake a string.
 * Production remains ASM; this is not an exact-match claim.
 *
 * Declaring previous_character before the decoded operands closes the
 * five-register cycle. An ordinary register hint ties; a separate full-width
 * item local and word-width character snapshot tie the prior nd26 shape.
 * Retain the real s64 classifier input across its two calls, and the u16
 * projection when the second operand is replaced with the third item ID.
 * The first masked operand can never equal signed -1, so its conditional
 * initializes previous_character on every reachable rendering path. Do not
 * invent a 0xFFFF sentinel or initialize a dummy backup value.
 *
 * Replay prerequisites (not integrated): canonical u32 func_002746a0(void),
 * void func_00273cc0(u8 *, u8 *), u32 func_001067f0(s16), and the existing
 * s32 func_0026e360(s64). Place the new declarations before existing calls;
 * remove the stale getter argument at all four existing owner call sites;
 * cast the five signed sp20 buffers to u8 * at the string provider calls.
 * Reuse func_0026f1e0_add for the first stream sum, unsigned 32-bit sums for
 * the other two. Existing callers need their own verification on cutover.
 *
 * All six bytes are decoded before the mode early exit. The optional glyph
 * path calls the classifier twice; both paths still request the item name
 * through the signed-low-halfword provider after the final context update.
 * Only context+0xD is restored, after the final string insertion. The real
 * jump table at 007480D0 selects 0..6,9,11; other values use the default.
 * Valid input requires a live context/readable six-byte script window and
 * an item ID valid for the existing metadata/name providers. No new guard,
 * hidden argument, callback snapshot or fallback string was introduced.
 */
// FUN_0026FD90
#pragma push
/* measured: opt_common_subs off forces func_0026fd90 field reloads. */
#pragma opt_common_subs off
/* measured: opt_propagation off preserves func_0026fd90 decode scheduling. */
#pragma opt_propagation off
s32 func_0026fd90(s32 arg0, u8 *arg1)
{
    u8 previous_character;
    s32 first;
    s64 second;
    s32 third;
    s8 glyph[3];
    s32 stream_offset;
    s32 stream_base;
    u8 *stream;
    s32 low;
    s32 high_byte;
    s32 high_first;
    s32 high_second;
    s32 high_third;
    s32 force_character;

    stream_offset = *(s32 *)(arg1 + 0x18);
    stream_base = *(s32 *)(arg1 + 0x10);
    stream = func_0026f1e0_add((u8 *)stream_base, (u32)stream_offset);
    low = (stream[0] - 1) & 0xFF;
    high_byte = stream[1];
    if (high_byte == 0xFF) {
        high_first = 0;
    } else {
        high_first = (high_byte - 1) & 0xFF;
    }
    first = (u16)(s16)(((high_first & 0xFF) << 8) | (low & 0xFF));

    stream_offset = *(s32 *)(arg1 + 0x18);
    stream_base = *(s32 *)(arg1 + 0x10);
    stream = (u8 *)((u32)stream_offset + (u32)stream_base);
    low = (stream[2] - 1) & 0xFF;
    high_byte = stream[3];
    if (high_byte == 0xFF) {
        high_second = 0;
    } else {
        high_second = (high_byte - 1) & 0xFF;
    }
    second = (u16)(s16)(((high_second & 0xFF) << 8) | (low & 0xFF));

    stream_offset = *(s32 *)(arg1 + 0x18);
    stream_base = *(s32 *)(arg1 + 0x10);
    stream = (u8 *)((u32)stream_offset + (u32)stream_base);
    low = (stream[4] - 1) & 0xFF;
    high_byte = stream[5];
    if (high_byte == 0xFF) {
        high_third = 0;
    } else {
        high_third = (high_byte - 1) & 0xFF;
    }
    third = (u16)(s16)(((high_third & 0xFF) << 8) | (low & 0xFF));

    if (func_002746a0() != 0) {
        return 0;
    }
    if ((first & 0xFFFF) != -1) {
        previous_character = arg1[0xD];
        arg1[0xD] = first;
    }
    if ((u16)second != 0) {
        second = (u16)third;
        switch (func_0026e360(second)) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 9:
        case 11:
            force_character = 1;
            break;
        default:
            force_character = 0;
            break;
        }
        if (force_character != 0) {
            arg1[0xD] = 4;
        }
        glyph[0] = -0x7D;
        glyph[1] = func_0026e360(second) + 0xC7;
        glyph[2] = 0;
        func_00273f70(arg1);
        func_00273cc0((u8 *)glyph, arg1);
    }
    func_00273f70(arg1);
    func_00273cc0((u8 *)func_001067f0((s16)third), arg1);
    arg1[0xD] = previous_character;
    return 0;
}
#pragma pop
