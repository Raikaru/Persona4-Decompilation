/* object 376 bytes, retail window 384 bytes, normalized_diff 3; differing offsets 68, 72, 92 plus 8-byte size shortfall. */
void func_00493080(u8 *arg0, u16 arg1, s32 *arg2) {
    u8 *o;

    if (*(u8 **)(arg0 + 0x2C) == NULL) {
        o = func_00486a50(*(s32 *)arg0);
        *(u8 **)(arg0 + 0x2C) = o;
        *(s32 *)(o + 0x4C) = *(s32 *)(arg0 + 0x30);
    }
    switch ((u32)arg1) {
    case 1:
        func_00487650(*(void **)(arg0 + 0x2C), *(void **)arg0);
        func_004877b0(*(void **)(arg0 + 0x2C), (void *)arg2);
        break;
    case 2:
        func_00487650(*(void **)(arg0 + 0x2C), *(void **)arg0);
        func_00487860(*(void **)(arg0 + 0x2C), (void *)arg2);
        break;
    case 4:
        func_00487650(*(void **)(arg0 + 0x2C), *(void **)arg0);
        func_00487710(*(void **)(arg0 + 0x2C), *(void **)arg2);
        break;
    case 5:
        func_004878c0(*(void **)(arg0 + 0x2C), (void *)arg2);
        break;
    case 6:
        func_00487a30(*(void **)(arg0 + 0x2C), (void *)arg2);
        break;
    case 7:
        func_00487650(*(void **)(arg0 + 0x2C), *(void **)arg0);
        func_00487ba0(*(void **)(arg0 + 0x2C), (void *)arg2);
        break;
    case 0:
    case 3:
    default:
        func_0046d730(D_00713E30, 0xA8);
        break;
    }
    *(s16 *)(*(u8 **)(arg0 + 0x2C) + 0xC) = (s16)arg1;
}
