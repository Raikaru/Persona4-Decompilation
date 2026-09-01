/* object_size=96B window=96B normalized_diff=8 differing word offsets=0x08,0x10 */
/* Best plain-C reconstruction before reverting: retail 0x08 is
   `sd $a0,0x10($sp)` and 0x10 is `move $t1,$a2`; candidate emits those two
   words in the reverse order. These are prologue scheduling words, not
   saved-register saves/moves, so saved-register COUNT/ASSIGNMENT rules do
   not apply. */
void func_00356170(s64 arg0, s32 arg1, s32 arg2, s32 arg3,
                   f32 f0, f32 f1, f32 f2)
{
    s64 saved0[1];
    s32 saved1[1];
    s32 var8;
    u8 sel;

    saved1[0] = arg1;
    saved0[0] = arg0;
    var8 = arg3;
    sel = ((u8 *)saved1)[3];
    if (sel != 0xFF) {
        var8 = 0;
    }
    func_00365f00(f0, f1, f2, 1.0f, *(s64 *)((u8 *)saved0),
                  *(s32 *)((u8 *)saved1), saved1[0], arg2, var8, 1.0f);
}

/* Probes: callee old-style declaration, target parameter interleave, reversed
   assignments, initialized/struct locals, delayed/named argument staging,
   schedule/opt_propagation/opt_common_subs settings all retained nd8 or
   regressed. The call setup is byte-identical to retail. */
