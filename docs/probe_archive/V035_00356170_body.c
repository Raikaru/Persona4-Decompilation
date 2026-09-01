/* object_size=96B; window=96B; normalized_diff=8; differing_offsets=0x08,0x10. */
/* Best plain-C reconstruction. Retail stores $a0 and $a1 before moving $a2 to
   $t1; MWCC schedules that move before the two saves. Scalar locals, alternate
   assignment/call staging, declaration/parameter-order, callee-order,
   signedness, optimization, scheduling, and register-hint probes were ruled
   out. The mandated reversed-local-declaration probe stayed nd 8. Delaying the
   first read/copy of arg1 until just before the call worsened the body to
   15 differing words (still 96B/96B). A u32 arg1 width probe stayed nd 8; O3
   and schedule-on probes worsened the object to 84B/96B with nd 22. The
   residual is a prologue save/move-scheduling compiler floor. */
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
