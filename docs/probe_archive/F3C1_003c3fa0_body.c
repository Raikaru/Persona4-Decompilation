/* func_003c3fa0: object_size=112, window=112, normalized_diff=48, differing_bytes=0x04,0x06,0x07,0x08,0x0a,0x0b,0x0c,0x0e,0x10,0x11,0x12,0x13,0x15,0x16,0x17; retail prologue is `lw $v0,8($a2)` before `sd $ra`/`sq $s1`/`sq $s0` (the saves are sq, not sd), and retail uses `movz $s1,$zero,$v0`; corrected three-s32-argument helper declaration, object-pointer local, direct field expressions, schedule/no_branch_likely pragmas, and branch polarity were measured; residual is MWCC prologue load/save ordering and conditional-move/return layout. */
#pragma schedule on
#pragma no_branch_likely on
extern s32 func_003df240(s32 arg0, s32 arg1, s32 arg2);
s32 func_003c3fa0(s32 arg0, s32 unused, u8 *arg2) {
    u8 *obj;
    s32 result;

    obj = arg2;
    result = arg0;
    if (func_003df240(arg0, *(s32 *)(obj + 8) + 0x2C, 4) == 0)
        goto retzero;
    goto second;
retzero:
    return 0;
second:
    if (func_003df240(arg0, *(s32 *)(obj + 8) + 0x30, 4) == 0)
        result = 0;
    return result;
}
#pragma no_branch_likely off
#pragma schedule off
