/* object_size=96 window=96 normalized_diff=8 differing_offsets=0x08,0x10 */
void func_00356170(s64 arg0, s32 arg1, s32 arg2, s32 arg3, f32 f0, f32 f1, f32 f2) {
    s64 saved0[1];
    s32 saved1[1];
    s32 var8;
    u8 sel;
    saved1[0] = arg1;
    saved0[0] = arg0;
    var8 = arg3;
    sel = ((u8 *)saved1)[3];
    if (sel != 0xFF)
        var8 = 0;
    func_00365f00(f0, f1, f2, 1.0f, *(s64 *)((u8 *)saved0), *(s32 *)((u8 *)saved1), saved1[0], arg2, var8, 1.0f);
}

/* Archive probes and measurements:
- Original 6-parameter body with s64 stack array and direct saved0 dereference: normalized_diff 19, object/window 96/96; fndiff words 0x08,0x0C,0x10,0x30,0x38,0x3C.
- Integer-first callee prototype probe: normalized_diff 37, object/window 92/96.
- Float-forwarding and interleaved target parameter-order probes: normalized_diff 37/26, no closure.
- saved1 pointer reload / named call-load probes: normalized_diff 26; direct saved1[0] call expression improved fndiff to 3 words.
- Assignment-order probe (saved1 store before saved0 store), with an added unused f32 parameter and f32 call arguments matching retail: normalized_diff 8; best body above.
- Struct-frame, struct padding/initializer, named float constant, call-local lifetime, local declaration, condition spelling, parameter signedness, opt_propagation, opt_rebuildconditionals, schedule, tailcall, and optimization_level 1 probes did not close the two prologue word residual.
- Permuter (1628 compiles / 143s) best score 16; source-level best improved to normalized_diff 8.
 */
