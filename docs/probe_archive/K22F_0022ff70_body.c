/* object 168B, retail window 176B, normalized_diff 5; differing bytes 78,81,82,85,89. */
/* Best preserved body uses the five-argument old-style call solely to retain
   the retail-sized window.  Residual is call-site register colouring:
   retail lhu $v0,110($a0), move $a2,$v0, move $a1,$zero, move $a3,$zero;
   candidate lhu's directly into $a2 and materializes an extra zero slot.
   Corrected ground-truth callee prototype func_001d7f10(u8 *,u8 *,u16,u32)
   and exact four-argument calls were measured.  Additional probes ruled out
   a wider u32 local with explicit (u16) cast, loading the value before all
   guards/other block statements, assigning named zero arguments after the
   value load, and a second post-call field load used in temp_3 (that body
   grew to 188B and did not preserve the target window).
   Earlier lanes ruled out direct field, u16/s16/s32/u32 locals, declaration
   orders, exact and old-style callee declarations, return widths, u32 casts,
   named pointer/aggregate/union loads, four- and five-argument calls, named
   argument locals in value-first and zero-first orders, loaded-value liveness
   copies, duplicate loads, inline load helpers, return/switch/goto layouts,
   identity uses, opt_rebuildconditionals, opt_propagation, optimization_level
   1, fifth-argument probes, and same-field no-op stores (scheduler-only). */
s32 func_0022ff70(u8 *arg0)
{
    u16 value;
    s32 temp_3;
    s32 result;

    if ((*(s32 *)(DAT_0076449c + 0xc) & 0x200000) == 0)
    {
        result = 0;
        goto done;
    }
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xa2) == 1)
    {
        result = 0;
        goto done;
    }
    value = *(u16 *)(arg0 + 0x6e);
    temp_3 = (s32)(func_001d7f10(arg0, NULL, value, 0, 0) & 0xffff);
    switch (temp_3)
    {
    case 1:
    case 2:
        result = 1;
        break;
    default:
        result = 0;
        break;
    }
done:
    return result;
}
