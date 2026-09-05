/* IDA-backed floor: 444B / 448B, 4 differing words (3 argument-setup
 * instructions plus one zero-tail word). Production remains ASM.
 * IDA: docs/ida_headstart/src/promoted/code1_0046.c:2147-2212.
 * Signed integer rectangle and byte-color aggregates; size uses x/y,
 * not width/height. Native 32-bit consumer smoke: 2704 cases.
 * Types stay local so archive replay retains the target marker.
 */
#pragma push
#pragma opt_propagation off
extern s32 func_0046d750(u8 *);
extern void func_0044ea90(void *, s32);
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern u8 D_007130F8[], D_00713108[];
// FUN_0046E850
u8 *func_0046e850(u8 *parent, void *rect_arg, void *first_arg, void *second_arg)
{
typedef struct WindowRect { s32 x, y, width, height; } WindowRect;
typedef struct WindowColor { u8 r, g, b, a; } WindowColor;
typedef struct WindowWork {
    s32 state, enabled;
    u8 reserved08[4];
    WindowRect rect;
    WindowColor first, second;
    u8 reserved24[32];
    s32 buffer_size;
    u8 *buffer, *cursor;
} WindowWork;
    WindowRect *rect = (WindowRect *)rect_arg;
    WindowColor *first = (WindowColor *)first_arg;
    WindowColor *second = (WindowColor *)second_arg;
    s32 result;
    WindowWork *work;
    u8 *buffer;
    s32 *size;
    u8 *(**allocator)(s32, s32, s32);
    func_0044ea90(D_007130F8, 379);
    allocator = D_008873F4;
    work = (WindowWork *)allocator[0](1, 0x560, 0x40000);
    if (work == NULL) return NULL;
    result = func_00451fc0((s32)parent, (s32)D_00713108, 0x101, 0, 0,
        (void (*)(u8 *))func_0046d750, func_0046e7f0, (u8 *)work);
    work->enabled = 1;
    work->rect = *rect;
    work->first = *first;
    work->second = *second;
    size = &work->buffer_size;
    *size = (rect->x / 8) * (rect->y / 8) + 32;
    func_0044ea90(D_007130F8, 396);
    buffer = allocator[0](1, *size, 0x40000);
    work->buffer = buffer;
    work->cursor = buffer;
    return (u8 *)result;
}
#pragma pop
