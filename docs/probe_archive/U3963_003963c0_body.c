/* Re-measured 2026-09-02 (Main): NOT a COP1 floor - every mula/madda/madd/msub/adda
   chain reproduces from plain C. Object 316B vs window 352B, nd199 under schedule on.
   The residual is the frame: retail keeps the saved quaternion `s` (sp+0..0xC, stored
   after the loads, never reloaded) and the inverse `inv` (sp+0x10..0x1C, loaded at the
   top before the n<=0 branch, computed into the same registers, never stored) as
   memory-homed locals while b210 fully register-promotes them (no frame). Probed in
   isolation: struct/array/union locals (promoted), pointer-aliased struct (real stores
   through $a2 plus loads), static inline helper writing through a pointer (promoted),
   struct copy `q = inv` (lq/sq), -O0..-O4 with/without ,p, casts through (f32 *)&inv.
   Nothing gives "loads from an uninitialised home with no stores". The sibling
   func_00396520 has the same shape. */
#pragma schedule on
// FUN_003963C0
void func_003963c0(u8 *arg0, u8 *arg1)
{
    struct { f32 x, y, z, w; } s;
    struct { f32 x, y, z, w; } inv;
    f32 n;
    f32 r;

    n = *(f32 *)(arg1 + 0xC) * *(f32 *)(arg1 + 0xC) + *(f32 *)(arg1 + 8) * *(f32 *)(arg1 + 8) +
        *(f32 *)(arg1 + 0x10) * *(f32 *)(arg1 + 0x10) + *(f32 *)(arg1 + 0x14) * *(f32 *)(arg1 + 0x14);
    if (!(n <= 0.0f)) {
        r = 1.0f / n;
        inv.w = *(f32 *)(arg1 + 0x14) * r;
        r = -r;
        inv.x = *(f32 *)(arg1 + 8) * r;
        inv.y = *(f32 *)(arg1 + 0xC) * r;
        inv.z = *(f32 *)(arg1 + 0x10) * r;
    }
    s.w = *(f32 *)(arg0 + 0x14);
    s.y = *(f32 *)(arg0 + 0xC);
    s.x = *(f32 *)(arg0 + 8);
    s.z = *(f32 *)(arg0 + 0x10);
    *(f32 *)(arg0 + 0x14) = inv.w * s.w - (inv.y * s.y + inv.x * s.x + inv.z * s.z);
    *(f32 *)(arg0 + 8) = inv.y * s.z - inv.z * s.y;
    *(f32 *)(arg0 + 0xC) = inv.z * s.x - inv.x * s.z;
    *(f32 *)(arg0 + 0x10) = inv.x * s.y - inv.y * s.x;
    *(f32 *)(arg0 + 8) += s.x * inv.w;
    *(f32 *)(arg0 + 0xC) += s.y * inv.w;
    *(f32 *)(arg0 + 0x10) += s.z * inv.w;
    *(f32 *)(arg0 + 8) += inv.x * s.w;
    *(f32 *)(arg0 + 0xC) += inv.y * s.w;
    *(f32 *)(arg0 + 0x10) += inv.z * s.w;
    *(f32 *)(arg0 + 0x18) -= *(f32 *)(arg1 + 0x18);
    *(f32 *)(arg0 + 0x1C) -= *(f32 *)(arg1 + 0x1C);
    *(f32 *)(arg0 + 0x20) -= *(f32 *)(arg1 + 0x20);
}
#pragma schedule off
