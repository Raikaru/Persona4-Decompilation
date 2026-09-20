extern s32 func_00199d00(s32, u8 *, s64, s32);
extern s32 func_001f1210(u8 *, s64, s32);
extern void func_001951f0(u8 *, u8 *, u8 *, s32, f32 *, f32 *, s32);
static inline u32 placeFormation(s64 mode, u8 * raw, u8 * node, u8 * unit, s32 paired)
{
    struct { f32 rotation[4]; f32 position[3]; } frame;

    s32 category;
    s32 kind;
    category = (s16)func_00199d00((s32)node, unit, mode, paired);
    if (func_001f1210(node, mode, paired) == 0) {
        kind = (s16)func_00199d00((s32)node, unit, mode, paired);
        switch (kind) {
        case 0:
        case 2:
            func_001951f0(node, unit, NULL, category, frame.position, frame.rotation, 0);
            break;
        case 1:
        case 3:
            func_001951f0(node, unit, NULL, category, frame.position, frame.rotation, 1);
            break;
        }
        func_00194f10(node, frame.rotation);
        func_00194ee0(node, frame.position);
    } else {
        func_001951f0(node, unit, *(u8 **)(*(u8 **)(raw + 8) + 0x30),
                      category, frame.position, frame.rotation, 2);
        func_00194f10(node, frame.rotation);
        func_00194ee0(node, frame.position);
    }
    return 1;
}
u32 func_001d2e20(u8 *raw)
{
    u8 *node;
    u8 *unit;
    s64 mode;
    s32 paired;
    node = *(u8 **)raw;
    unit = *(u8 **)(*(u8 **)(raw + 4) + 0x30);
    mode = *(s16 *)(raw + 12);
    paired = *(u8 **)(raw + 8) != NULL;
    return placeFormation(mode, raw, node, unit, paired);
}
