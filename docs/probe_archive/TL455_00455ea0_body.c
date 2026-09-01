/* object_size=200 window=208 normalized_diff=7 differing_offsets=0x50,0x58,0x5c,0x60,0x68,0x74 plus one zero-tail word; current re-measure of the q=t>>=7 mutation. Residual is temporary/register materialization in the rounded-size update: retail keeps entry+0x100 in $a0 and size+0x3F in $v1, while b210 uses $v1 for the base and $v0 for size+0x3F. Existing archive probes (base/t/q locals and declaration orders, pointer/integer bases, operation order, direct/pointer output forms, and schedule-on) remain ruled out. */
u8* func_00455ea0(u8* arg0, s32 arg1, void* arg2) {
    struct Header { u8 pad[0xFC]; s32 size; } header;
    s32 out_local; s32 count; s32* out; s32 i; u8* entry; s32 size; s32 t; s32 q;
    out = (s32*)arg2; if (out == NULL) out = &out_local; count = arg1; entry = *(u8**)(arg0 + 0x110);
    for (i = 0; i < count; i++) {
        func_0043f810(&header, entry, sizeof(header)); entry += sizeof(header);
        size = header.size; t = size; t += 0x3F; q = t >>= 7;
        if (t < 0) q = (t + 0x3F) >> 6;
        q <<= 6; entry += q;
    }
    func_0043f810(&header, entry, sizeof(header)); *out = header.size;
    return entry + sizeof(header);
}
