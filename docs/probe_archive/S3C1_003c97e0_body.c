/* object 352B/window 352B normalized_diff 213; exact size/frame (stack frame 1824B), 79 differing words; instruction deficit/surplus 0. Classification NEAR_MISS: structurally complete positive/negative list compaction transcription, but register allocation, FP load/store scheduling, and branch layout differ; no movz/movn, standalone MMI, framed tail-jump, or sd/sq mixed-unit floor. Prologue saves 0 $s registers; signature (u8 *arg0). Declarations: u8 stack[1824], f32 temporaries, s32 index/offset, pointer locals. Candidate body not retained. */
// FUN_003C97E0
u8 *func_003c97e0(u8 *arg0) {
    u8 stack[1824];
    f32 temp_f0;
    f32 temp_f1;
    s32 index;
    s32 offset;
    u8 *node;
    u8 *entry;
    u8 *data;

    node = *(u8 **)(arg0 + 0x1C);
    *(f32 *)(stack + 0x600) = *(f32 *)(arg0 + 0x50);
    index = 0;
    *(f32 *)(stack + 0x604) = *(f32 *)(arg0 + 0x54);
    *(f32 *)(stack + 0x608) = *(f32 *)(arg0 + 0x58);
    *(f32 *)(stack + 0x60C) = *(f32 *)(arg0 + 0x5C);
    *(f32 *)(stack + 0x610) = *(f32 *)(arg0 + 0x60);
    *(f32 *)(stack + 0x614) = *(f32 *)(arg0 + 0x64);
loop:
    if (*(s32 *)node < 0)
        goto negative;
    index += 1;
    entry = stack + index * 0x18;
    offset = *(s32 *)node;
    temp_f1 = *(f32 *)(node + 0x14);
    *(s32 *)(stack + 0x620 + index * 4) = *(s32 *)(node + 0xC);
    temp_f0 = *(f32 *)(node + 0x10);
    *(f32 *)(entry + 0x00) = *(f32 *)(stack + 0x600);
    node = *(u8 **)(node + 8);
    *(f32 *)(entry + 0x04) = *(f32 *)(stack + 0x604);
    *(f32 *)(entry + 0x08) = *(f32 *)(stack + 0x608);
    *(f32 *)(entry + 0x0C) = *(f32 *)(stack + 0x60C);
    *(f32 *)(entry + 0x10) = *(f32 *)(stack + 0x610);
    *(f32 *)(entry + 0x14) = *(f32 *)(stack + 0x614);
    *(f32 *)(entry + offset + 0x0C) = temp_f1;
    *(f32 *)(stack + offset + 0x600) = temp_f0;
    if (index < 0)
        goto done;
    goto loop;
negative:
    *(f32 *)(node + 0x48) = *(f32 *)(stack + 0x600);
    *(f32 *)(node + 0x4C) = *(f32 *)(stack + 0x604);
    *(f32 *)(node + 0x50) = *(f32 *)(stack + 0x608);
    *(f32 *)(node + 0x54) = *(f32 *)(stack + 0x60C);
    *(f32 *)(node + 0x58) = *(f32 *)(stack + 0x610);
    *(f32 *)(node + 0x5C) = *(f32 *)(stack + 0x614);
    data = stack + index * 0x18;
    entry = stack + index * 4;
    index -= 1;
    node = *(u8 **)(entry + 0x620);
    *(f32 *)(stack + 0x600) = *(f32 *)(data + 0x00);
    *(f32 *)(stack + 0x604) = *(f32 *)(data + 0x04);
    *(f32 *)(stack + 0x608) = *(f32 *)(data + 0x08);
    *(f32 *)(stack + 0x60C) = *(f32 *)(data + 0x0C);
    *(f32 *)(stack + 0x610) = *(f32 *)(data + 0x10);
    *(f32 *)(stack + 0x614) = *(f32 *)(data + 0x14);
    if (index >= 0)
        goto loop;
done:
    return arg0;
}
