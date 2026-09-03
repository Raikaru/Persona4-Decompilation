/* REJECTED closure (2026-09-02): scores MATCH (224/224 nd0) but depends on `volatile` staging of ordinary
   data (D_0064A5A0/D_0064A5A8 -> sp.sp40) and a packed struct, both banned (H001). Kept as a lever record:
   the ld/lwc1/sd/swc1 staging order is what retail needs; find a non-volatile spelling. */
   ld/lwc1, and a pack(4) 12-byte copy degrades to three lwc1s. (2) The shared
   (s32)arg1*0x84 mul for the p84 address is CSE-hoisted above the arg0 chain
   (base+idx+0x2758) in every spelling (inline, locals, u32-cast trees, 132-vs-0x84
   literals, declaration/statement reorderings); retail computes it in place between
   arg0 and the float. Both measured across 15+ variants. Scheduler-CSE floor. */
// FUN_0033FA30
#pragma push
#pragma opt_propagation off /* measured: keeps &sp40 in $a1 and p84 below a0 */
void func_0033fa30(u8 *arg0, s8 arg1) {
    typedef struct CmbS64F32 { u64 a; f32 b; } __attribute__((packed)) CmbS64F32;
    struct { f32 sp30[4]; CmbS64F32 sp40; } sp;
    u64 txy;
    f32 tz;
    f32 *p40;
    u8 *obj;
    u8 *table;
    u8 *pFB0;
    u8 *arg0_for_dd;
    u8 *p84;

    obj = *(u8 **)(arg0 + 0x38);
    p40 = (f32 *)&sp.sp40;
    txy = ((volatile CmbS64F32 *)D_0064A5A0)->a;
    tz = *(volatile f32 *)D_0064A5A8;
    *(volatile u64 *)&sp.sp40.a = txy;
    *(volatile f32 *)&sp.sp40.b = tz;
    func_003dc740(&sp.sp30, p40, 0);
    table = *(u8 **)(*(u8 **)(obj + 4) + 0x38);
    if ((s8)*table == 4) {
        pFB0 = table + (s32)arg1 * 0xFB0;
        arg0_for_dd = pFB0 + 0x2758;
        p84 = obj + (s32)arg1 * 0x84;
        func_0036dd10(arg0_for_dd, p84 + 0x20, 90.0f * *(f32 *)(p84 + 0x8C));
        func_0036de20(*(u8 **)(*(u8 **)(obj + 4) + 0x38) + (s32)arg1 * 0xFB0 + 0x2758, &sp.sp30);
    }
}
#pragma pop
// FUN_0033FB10
void func_0033fb10(u8 *arg0, s8 arg1, s64 arg2) {
    u8 *obj = *(u8 **)(arg0 + 0x38);
    u32 scaled = (s32)arg1 * 0x84;
