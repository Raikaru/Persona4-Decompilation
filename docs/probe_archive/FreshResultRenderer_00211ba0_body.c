/* Fresh result renderer func_00211ba0; production remains ASM.
 * Preferred unchanged-owner replay: 1000/1008 bytes, nd14, all 18 relocations
 * independently resolved, eight zero alignment bytes. All remaining differences
 * are the group/unit s3/s4 register permutation. No native behavior check.
 * 
 * Initial candidate1036/nd587 -> signed-word halfword-to-float conversion992/nd226.
 * Independent block scopes992/nd222. Explicit &0xFF does NOT restore the omitted
 * alpha conversion instructions. Direct float-to-u8 gives1004/nd232; staging the
 * easing callback result before the byte conversion gives1000/nd15. Per-unit draw
 * context lifetime reduces this to nd14; per-group cursor scope ties. Keeping the
 * accessor's raw u32 work value gives nd15. No declaration permutation sweep.
 * 
 * The real status provider is datCalcChkBadStatus (u32 return) at00232710; both
 * names resolve to that address. The agent's contrary warning was rejected.
 * The12-byte fade descriptor has alpha:u8 at0, step:s16 at2, flags:u16 at4,
 * scale:f32 at8, with natural alignment only. Its consumer compares the step field
 * against a highlight index; it is not a geometric displacement.
 * Preserve initial context for positioning/fade, and reacquire draw context after
 * the position callback for each accepted unit. Both linked lists are scanned.
 * Projection produces exactly two floats; world position exactly three.
 * 
 * Replay: add declarations below and replace only the owner's ASM slot. Its legacy
 * func_00452560 return declaration can stay unchanged for this measurement; the
 * scratch corrected-u32-return owner produces the identical target bytes. The
 * broader task-accessor contract migration remains deferred, not silently fixed
 * or promoted here. Complete explicit task arguments are used in this candidate.
 */

typedef struct BtlUnit BtlUnit;
typedef struct RwV3d { f32 x, y, z; } RwV3d;
extern void func_00195f70(BtlUnit *unit, RwV3d *position);
extern s32 func_001ec4a0(s32 position, u8 *screen);
extern u32 datCalcChkBadStatus(s32 unit, u32 mask);
extern void func_002012d0(u8 *context, f32 x, f32 y);
extern f32 func_0020e5c0(s32 frame, s32 start, s32 end, s32 curve);
extern void func_0020fa70(u8 *context, u8 *fade);
extern f32 fGpffff81e0;

// FUN_00211BA0
void func_00211ba0(u8 *unused, u8 *state)
{
    RwV3d world;
    Vec2f screen;
    struct {
        u8 alpha;
        s16 step;
        u16 flags;
        f32 scale;
    } fade;
    u8 *context;
    s16 frame;
    u16 flags;

    context = (u8 *)func_00452560(*(void **)(state + 4));
    if (*(u32 *)context & 1) {
        if (*(u16 *)(state + 8) & 1) {
            s32 group;
            u8 *unit;
            f32 pulse;

            func_00201350();
            for (group = 0; group < 2; group++) {
                for (unit = *(u8 **)(iGpffffb3ac + 0x178 + group * 8);
                     unit != NULL; unit = *(u8 **)(unit + 0xA6C)) {
                    u8 *draw;
                    if (!(*(u32 *)(unit + 0x9C) & 8)) {
                        continue;
                    }
                    if (!datCalcChkBadStatus(*(s32 *)(unit + 0xA64), 0x100000)) {
                        continue;
                    }
                    func_00195f70((BtlUnit *)unit, &world);
                    if (!func_001ec4a0((s32)&world, (u8 *)&screen)) {
                        continue;
                    }
                    func_002012d0(context, screen.x - 86.0f, screen.y - 86.0f);
                    draw = (u8 *)func_00452560(*(void **)(state + 4));
                    if (++*(u16 *)(unit + 0xA44) >= 25) {
                        *(u16 *)(unit + 0xA44) = 0;
                    }
                    pulse = func_0044b7b0((fGpffff81e0 * (f32)(s32)*(u16 *)(unit + 0xA44)) / 25.0f);
                    func_00201650(draw, 10, 17, 64.0f, (0.0f + 45.0f) + 10.0f * pulse,
                                   12, 79, 85, 255);
                    func_00201650(draw, 10, 17, 64.0f, (0.0f + 37.0f) + 5.0f * pulse,
                                   63, 255, 245, 255);
                    func_00201650(draw, 10, 8, 55.0f, 44.0f, 63, 255, 245, 255);
                    func_00201650(draw, 10, 7, 55.0f, 44.0f, 12, 79, 85, 255);
                }
            }
        }
        flags = *(u16 *)(state + 8);
        if (flags & 2) {
            if (*(u16 *)(state + 0xA) < 30) {
                frame = *(u16 *)(state + 0xA);
                fade.flags = flags;
                {
                    f32 opacity = func_0020e5c0(frame, 0, 5, 0);
                    fade.alpha = (u8)(255.0f * (1.0f - opacity));
                }
                fade.step = (s16)(s32)(12.0f * func_0020e5c0(frame, 1, 12, 0));
                fade.scale = 1.0f - func_0020e5c0(frame, 20, 30, 0);
                *(u16 *)(state + 0xA) += 1;
                func_0020fa70(context, (u8 *)&fade);
            } else {
                *(u16 *)(state + 8) = flags & 0xFFFD;
            }
        }
    }
}
