/* Source-only packed-color reference, not MATCH: 396B / 288B, 91
 * reloc-masked differing words under configured b210 archive replay.
 * IDA: docs/ida_headstart/src/promoted/code1_0048.c:710-789.
 * Preserves parent-color snapshot, signed float-to-integer conversion,
 * four packed byte lanes, two-argument optional callback and post-callback
 * next-pointer reload. Native 32-bit smoke: 65540 cases, host rounding only.
 * This is not a VU emulator: VU register effects and PS2 rounding identity
 * remain unverified; production retains INCLUDE_ASM.
 * Historical scalar archive measurement was 860B / 211 differing words.
 * The former 260B / 51-word assembly draft was not an admissible floor:
 * it encoded ordinary instructions and hard-coded local stack offsets.
 * That draft is removed rather than presented as hardware-only source.
 */
void func_004865c0(u8 *arg0, s32 arg1)
{
    union ColorBits { u32 word; u8 channel[4]; } base, child, packed;
    f32 scale;
    f32 parent[4];
    s32 channel;
    u8 *node;
    u8 *data;
    void (*callback)(s32, u32);

    *(s32 *)(arg0 + 0x64) = arg1;
    base.word = (u32)arg1;
    scale = fGpffff8044;
    for (channel = 0; channel < 4; channel++)
        parent[channel] = (f32)base.channel[channel] * scale;
    node = *(u8 **)(arg0 + 0x8C);
    if (node != NULL) {
        while (node != NULL) {
            child.word = *(u32 *)(node + 0x64);
            for (channel = 0; channel < 4; channel++)
                packed.channel[channel] = (u8)(s32)((((f32)child.channel[channel] * scale) * parent[channel]) * 255.0f);
            data = *(u8 **)(node + 0x90);
            callback = *(void (**)(s32, u32))(D_00713480 + (*(u16 *)(data + 4) << 6) + 0x30);
            if (callback != NULL) callback(*(s32 *)(data + 8), packed.word);
            node = *(u8 **)(node + 0xAC);
        }
    }
}
