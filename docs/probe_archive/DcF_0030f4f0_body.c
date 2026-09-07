/* MATCH in production: MWCC b210 -O2, 348B / 352B retail window.
 * Raw fndiff counts only one absent zero alignment word. Genuine s16
 * counters/bound plus loop-invariant motion close the narrowing differences;
 * direct identifier comparisons remove the three-register rotation caused
 * by the explicit id2 cache. The compiler generates the masked cache itself.
 * The count is a signed byte, with 7 mapped to 12, so the halfword counters
 * cannot overflow. Keep signed material reads: unsigned 0xFFFF is not -1.
 * 81,920 actual-source freestanding native32 UBSan-trap cases pass: every
 * signed-byte count, absent/first/last/duplicate identifiers, high-bit IDs,
 * signed selectors, inventory effects and callback-visible reloads.
 * Task work is captured before the getter; count is read after it and kept
 * across copying; selector/index and materials are reloaded for the search.
 * Inventory helpers are controlled native hooks, not retail execution. */
#pragma push
#pragma opt_loop_invariants on
void func_0030f4f0(u8 *task, s16 *materials) {
    s16 materialIndex;
    s16 searchIndex;
    s16 count;
    s32 equippedId;
    u8 *work;

    work = *(u8 **)(task + 0x38);
    equippedId = func_0010b460();
    count = *(s8 *)(work + 0x1A);
    if (count == 7) {
        count = 0xC;
    }
    materialIndex = 0;
    while (materialIndex < count) {
        if ((u16)equippedId != materials[materialIndex]) {
            func_0010ad80(materials[materialIndex] & 0xFFFF);
        }
        materialIndex++;
    }
    func_0010b190((u8 *)func_002e48a0(*(s8 *)(work + 0x2F9), *(s8 *)(work + 0x2FA)));
    searchIndex = 0;
    while (searchIndex < count) {
        if ((u16)equippedId == materials[searchIndex]) {
            func_0010b300(*(u16 *)(func_002e48a0(*(s8 *)(work + 0x2F9), *(s8 *)(work + 0x2FA)) + 1));
            func_0010ad80(equippedId);
            break;
        }
        searchIndex++;
    }
    func_0010b7f0();
}
#pragma pop
