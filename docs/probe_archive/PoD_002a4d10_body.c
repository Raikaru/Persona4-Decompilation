/* Current reconstruction: 524B/528B, 59 fully relocated executable differing
 * words and four omitted zero-tail bytes. All 13 relocations resolve.
 * Bounded O1 gives the retail 0x60 frame and saved owner in s0, but color/
 * outgoing-pointer scheduling and aggregate stack placement remain open.
 * All 23 existing owner C functions preserve bytes/relocations.
 * 1,470 ASan/UBSan cases cover rectangle/color values, clamp boundaries,
 * callback-driven frame reloads, cached work ownership and completion.
 * Native easing/drawing are controlled fixtures, not PS2 rendering.
 * The primitive's current owner declaration is retained here; promotion
 * still requires reconciling its float-typed rectangle API with s32 fields.
 */
typedef struct { u8 rgba[4]; } McColor;
typedef struct { s32 x, y, width, height; } McRect;
extern u32 func_00452560(void *task);
extern f32 func_0044b7b0(f32 angle);
extern void func_0045d6e0(void *, void *, f32, s32);
extern McColor iGpffffa818;
extern McColor iGpffffa81c;
extern McRect D_0063ED50;
extern McRect D_0063ED60;
extern f32 D_00761184;
#pragma optimization_level 1
s32 func_002a4d10(s32 task) {
    u8 *work;
    s32 frame;
    f32 eased;
    McColor first_color;
    McColor second_color;
    McRect first;
    McRect second;
    McColor color;
    McRect rectangle;
    work = (u8 *)func_00452560((void *)task);
    frame = *(s32 *)(work + 0x568);
    if (frame > 20) frame = 20;
    eased = func_0044b7b0((D_00761184 * (f32)frame) / 20.0f);
    first_color = iGpffffa818;
    color = first_color;
    first = D_0063ED50;
    first.y = (s32)(178.0f * (1.0f - eased));
    first.height = (s32)(448.0f * eased);
    rectangle = first;
    func_0045d6e0(&color, &rectangle, 0.0f, 1);
    frame = *(s32 *)(work + 0x568);
    if (frame > 5) {
        frame -= 5;
        if (frame > 15) frame = 15;
        eased = func_0044b7b0((D_00761184 * (f32)frame) / 15.0f);
        second_color = iGpffffa81c;
        color = second_color;
        second = D_0063ED60;
        {
        f32 extent = 94.0f * eased;
        second.y = (s32)(178.0f - extent / 2.0f);
        second.height = (s32)extent;
        }
        rectangle = second;
        func_0045d6e0(&color, &rectangle, 0.0f, 1);
    }
    frame = ++*(s32 *)(work + 0x568);
    if (frame >= 20) {
        *(s32 *)(work + 0x568) = 0;
        return 1;
    }
    return 0;
}
#pragma optimization_level 2
