/* object_size=420 window=416 normalized_diff=288 differing_offsets=[44,48,52,56,60,64,68,72,76,80,84,88,92,96,100,104,108,112,116,120,124,128,132,136,140,144,148,152,160,164,172,176,180,184,188,192,196,200,204,208,212,216,220,224,228,232,236,240,244,248,252,256,260,264,268,272,276,280,284,288,292,296,300,304,308,312,316,320,324,332,336,340,344,348,352,356,360,364,368,372,376,380,384,388,392,396,400,404,408,412,416] classification=attempted-not-closed; retail adda.s and msub.s confirmed at the coordinate-adjustment chain, but a compliant plain-C expression (var_f21 + 0.0f) - (f32)count * 9.5f emits that chain, so COP1 fusion was not treated as a hard floor. Ruled out: direct M2C-shaped body, s8/s32/u32/s64 parameter and local-width variants, pointer/context aliases, split count-result intermediates, color declaration orders and assignment orders, mixed parameter order, permitted pragma probes, and alternate extraction spellings. Residual is saved-register allocation plus byte-extraction/order scheduling. */

extern u8 D_00763C70[];
extern void func_00442088(void *arg0, const void *arg1, s32 arg2);
extern s32 func_00442948(const void *arg0);
extern void func_00201650(u8 *arg0, s32 arg1, s32 arg2, f32 fparg0,
                           f32 fparg1, s32 arg5, s32 arg6, s32 arg7, s32 arg8);
// FUN_0020E420
void func_0020e420(u8 *arg0, s32 arg1, s32 arg2, s32 arg3,
                   f32 fparg0, f32 fparg1)
{
    u8 sp90[0x40];
    u8 *context;
    u8 *context2;
    f32 var_f21;
    f32 var_f20;
    s32 allocated;
    s32 count;
    s32 count2;
    s32 var_20;
    s64 temp_17;
    s64 temp_18;
    s64 temp_19;
    s64 temp_16;

    var_f21 = fparg0;
    context = arg0;
    context2 = context;
    var_f20 = fparg1;
    temp_17 = (s8)(((arg3 & 0xFF000000) >> 24) & 0xFF);
    temp_18 = (s8)(((arg3 & 0x00FF0000) >> 16) & 0xFF);
    temp_19 = (s8)(((arg3 & 0x0000FF00) >> 8) & 0xFF);
    temp_16 = (s8)((arg3 & 0x000000FF) & 0xFF);
    if (temp_16 != 0) {
        func_00442088(sp90, D_00763C70, arg1);
        count = func_00442948(sp90);
        allocated = count;
        count2 = allocated;
        if (arg2 != 0) {
            var_f21 = (var_f21 + 0.0f) - (f32)allocated * 9.5f;
            var_f20 -= 11.0f;
        }
        var_20 = 0;
        while (var_20 < count2) {
            func_00201650(context2, 10, (s8)sp90[var_20] - 0x19,
                          var_f21, var_f20, temp_17 & 0xFF, temp_18 & 0xFF,
                          temp_19 & 0xFF, temp_16 & 0xFF);
            var_f21 += 19.0f;
            var_20++;
        }
    }
}
