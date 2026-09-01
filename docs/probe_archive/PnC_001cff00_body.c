/* PnC probe body for func_001cff00 -- captured by Main from the working tree
 * after the lane yielded without archiving.
 *
 * object 704B / retail window 704B / normalized_diff 2 WORDS.
 * Differing offsets 0x78 and 0x7c, a pure adjacent load-order swap:
 *     retail     0xa000a2df  ld    $v0,0xa0($sp)
 *                0xa800a0c7  lwc1  $f0,0xa8($sp)
 *     candidate  0xa800a0c7  lwc1  $f0,0xa8($sp)
 *                0xa000a2df  ld    $v0,0xa0($sp)
 * No relocation, no HI16/LO16 pair, no literal mismatch, identical sizes --
 * only the order of two independent stack reloads.
 *
 * All six COP1 accumulator operations reproduced from ordinary C; the chain
 * was never the residual.
 *
 * Ruled out: the source ALREADY names the 64-bit value before the float and
 * mwcc reorders anyway, so this is the instruction scheduler rather than
 * source ordering. Hoisting the pair into a local immediately after
 * func_00195850 moved the load to 0x48, ahead of all target math, and
 * produced a large shifted residual. An off/on and tighter push/pop
 * `#pragma schedule off` probes were tested; neither altered the pair.
 * Push/pop `#pragma no_branch_likely on`, `#pragma opt_rebuildconditionals
 * off`, comma-copy expressions, and reversed first-use orders did not close;
 * reversing the shared helper regressed func_001ce470. Target-local Vec3 and
 * Pair aggregate copies did not close (708B/nd 138 and 704B/nd 4); Pair32
 * (u32,u32,f32) emitted an oversized 712B object with shifted math (nd 132).
 * Value-parameter, input-pointer-reordered, swapped-local-declaration, and
 * register-local helper variants shifted the frame/tail (nd 150); const locals
 * and u64 pointer types were COMPILE_ERROR. A packed s64/f32 aggregate sank
 * the copy before setup (680B/nd 198); `__builtin_memcpy(..., 0xC)` shifted
 * the tail (696B/nd 154). A byte-pointer helper sank the copy before setup
 * (680B/nd 198), and `opt_common_subs off` shifted setup/tail (712B/nd 140).
 * Push/pop `schedule on` shifted body/tail (696B/nd 166); push/pop
 * `opt_loop_invariants on`, `optimization_level 3`, and `optimization_level 1`
 * shifted frame/tail (696B/nd 150, 696B/nd 166, 712B/nd 140). All variants
 * were reverted.
 * NOTE: this body also carried temporary probe declarations
 * (func_003e4180/memcpy helpers) that were removed when the source was
 * reverted; re-add whatever it needs before recompiling.
 */

// FUN_001CFF00
void func_001cff00(u8 *arg0)
{
    struct Frame {
        f32 first[7];
        f32 result[3];
        u8 second[0x28];
        f32 source[4];
        f32 target[4];
    } frame;
    f32 speed;
    f32 half_speed;
    f32 scale;
    f32 length;
    f32 x;
    f32 y;
    f32 limit;
    u8 *work;

    func_001bd560(frame.first, arg0 + 0x9C);
    work = *(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30);
    func_00195850(work, frame.target);
    frame.target[1] = *(f32 *)(work + 0x84) * *(f32 *)(work + 0x2C);
    speed = *(f32 *)(work + 0x90) * *(f32 *)(work + 0x2C);
    half_speed = (*(f32 *)(work + 0x8C) * *(f32 *)(work + 0x2C)) * 0.5f;
    func_001c_copy_pair((s64 *)frame.source, &frame.source[2],
                        (s64 *)frame.target, &frame.target[2]);
    frame.source[1] += half_speed * 0.25f;
    if (speed > half_speed) {
        scale = (3.0f * speed) /
                func_0044b868(fGpffff8110 *
                              (0.5f * *(f32 *)(arg0 + 0xB8)));
    } else {
        scale = (3.0f * half_speed) /
                func_0044b868(0.5f * *(f32 *)(arg0 + 0xB8));
    }
    *(f32 *)(frame.second + 0x18) =
        frame.first[0] - frame.source[0];
    *(f32 *)(frame.second + 0x1C) =
        frame.first[1] - frame.source[1];
    *(f32 *)(frame.second + 0x20) =
        frame.first[2] - frame.source[2];
    length = func_003e4180((f32 *)(frame.second + 0x18));
    length *= fGpffff811c;
    *(f32 *)(frame.second + 0x18) =
        frame.first[0] - frame.source[0];
    *(f32 *)(frame.second + 0x1C) =
        frame.first[1] - frame.source[1];
    *(f32 *)(frame.second + 0x20) =
        frame.first[2] - frame.source[2];
    func_003e40b0((f32 *)(frame.second + 0x18),
                  (f32 *)(frame.second + 0x18));
    x = *(f32 *)(frame.second + 0x18) *
        ((scale > length) ? scale : length);
    y = *(f32 *)(frame.second + 0x1C) *
        ((scale > length) ? scale : length);
    scale = (scale > length) ? scale : length;
    frame.result[0] = frame.source[0] + x;
    frame.result[1] = frame.source[1] + y;
    frame.result[2] = frame.source[2] +
                      *(f32 *)(frame.second + 0x20) * scale;
    limit = frame.target[1] + half_speed * 1.25f;
    if (frame.result[1] < limit) {
        frame.result[1] = limit;
    }
    func_001bd780(frame.second, frame.result, frame.source, D_0060A0E0);
    func_001bac20(arg0, frame.first, frame.result, 1);
    func_001bbef0(arg0, 4.5f);
}