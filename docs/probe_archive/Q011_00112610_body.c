// measured: object_size 540, window 544, normalized_diff 28; differing offsets 120,124,128,132,296,300,304,328,332,336,408,412,416,420,424,468,472,476, etc.; classification: near-match with exact frame/prologue/branch skeleton, residual aggregate color stack-slot order, alpha operand materialisation order, and helper-call argument order; ruled out floor families (no movz/movn, COP1 accumulator, standalone MMI, framed tail-jump, or sd callee-saved save), corrected helper prototype, Color4 aggregate copy, and exact saved-register count.
typedef struct { f32 x; f32 y; } Vec2f;
typedef struct { u8 b[4]; } Color4;
extern u8 D_005E4710[];
extern u8 D_005E4730[];
extern u32 func_00106880(s16);
extern void func_0046d4c0(s32,s32,s32,f32,f32,u8,u8,u8,u8,f32,s32);
extern void func_00113280(Vec2f,f32,s32,s16,s32,s32);
void func_00112610(Vec2f arg0, f32 fparg0, u8 arg1, u8 *arg2, s32 arg3, s32 arg4)
{
    Color4 color_b;
    Color4 color_a;
    Vec2f pos;
    s32 flags;
    s32 mode;
    s32 selected;
    u8 *table;
    flags = func_00106880(*(s16 *)(arg2 + 0));
    if (*(u16 *)(arg2 + 0x14) & 2) {
        table = &D_005E4710[(*(s16 *)(arg2 + 0x16)) * 4];
        color_a = *(Color4 *)table;
        mode = -1;
        if (flags & 0x3FFF) { mode = 2; selected = arg3; }
        else if (flags & 0xC000) { mode = 3; selected = arg3; }
        else if (flags & 0x10000) { mode = 2; selected = arg3; }
        else if (flags & 0x20000) { mode = 2; selected = arg3; }
        else if (flags & 0x40000) { mode = 2; selected = arg3; }
        if (mode != -1)
            func_0046d4c0(0, selected, mode, arg0.x, arg0.y,
                          (255 - (arg1 & 0xFF)) & 0xFF,
                          color_a.b[0], color_a.b[1], color_a.b[2], fparg0, 0);
    }
    if (*(u16 *)(arg2 + 0x14) & 1) {
        table = &D_005E4730[(*(s16 *)(arg2 + 0x16)) * 4];
        color_b = *(Color4 *)table;
        color_b.b[3] = arg1;
        pos.x = arg0.x + 3.0f;
        pos.y = arg0.y + 2.0f;
        func_00113280(pos, fparg0, *(u32 *)color_b.b,
                      *(s16 *)(arg2 + 0), arg3, arg4);
    }
}
