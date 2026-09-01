/* func_003cf070 archive: object 216B/window 208B, normalized_diff 167.
   Best of six probes (reload/nested/direct-store/lo-hi/schedule/O2).
   Over-window everywhere. */
/* measured: enable_vu0_registers + vu0_mmi_reg_binding reproduce the MMI
   pcpyld/sq tail; optimization_level 1 preserves retail's packet order. */
#pragma enable_vu0_registers on
#pragma vu0_mmi_reg_binding on
#pragma optimization_level 1
void func_003cf070(u8 *arg0) {
    typedef unsigned int u_long128 __attribute__((mode(TI)));
    u8 *work;
    u8 *list;
    u64 lo;
    u64 hi;
    u64 src;
    u_long128 packed;

    work = *(u8 **)(arg0 + 0x14);
    *(s32 *)(work + 0x18) = 0;
    *(s32 *)(work + 0x1C) = 0x3D0;
    *(s32 *)(work + 0x20) = 0x20;
    *(s32 *)(work + 0x24) = (s32)((u32)(work + 0x28 + 0xF) & ~0xFU);
    list = *(u8 **)(work + 0x24);
    *(s32 *)(list + 0x10) = 0;
    list = *(u8 **)(work + 0x24);
    *(s32 *)(list + 0x14) = 0;
    list = *(u8 **)(work + 0x24);
    *(s32 *)(list + 0x18) = 0;
    list = *(u8 **)(work + 0x24);
    *(s32 *)(list + 0x1C) = 0;
    lo = 0x01000404ULL;
    hi = (*(s32 *)(work + 0x1C) + 4) | 0x6C010000;
    src = (hi << 32) | lo;
    packed = _pcpyld(src, 0);
    *(u_long128 *)list = packed;
    *(s32 *)(work + 0x10) = 0;
    *(s32 *)(work + 0x14) = 0;
    *(u8 *)(work + 1) = 1;
    *(u8 *)(work + 2) = 2;
    *(u8 *)(work + 3) = 1;
    *(u8 *)(work + 4) = 1;
    *(u8 *)(work + 5) = 3;
    *(u8 *)(work + 6) = 1;
    *(u8 *)(work + 8) = 0;
    *(u8 *)(work + 9) = 1;
    *(u8 *)(work + 0xA) = 0;
    *(u8 *)(work + 0xB) = 2;
    *(u8 *)(work + 0xC) = 2;
    *(u8 *)(work + 0xD) = 0;
}
