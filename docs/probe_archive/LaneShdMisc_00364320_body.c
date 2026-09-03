/* Lane: LaneShdMisc
 * Address: 00364320
 * object: 648B over window 672B
 * normalized diff: 60
 * status: MISMATCH
 * differing offsets (reloc-masked, first words): 24-31, 36, 330-331, 334-335, 338, 384-385, plus tail branch/loop-test form
 * levers tried:
 *   - #pragma opt_common_subs off (required; without it register reuse for color/alpha differs)
 *   - s32 ch instead of s8 ch (avoids dsll32/dsra32 s8->s64 canonicalisation in arithmetic)
 *   - for (;;) { ch = tmp[i]; if (ch == 0) break; ... } loop form
 *   - pos.x += 36.0f before the digit loop
 *   - #pragma push / #pragma pop around the function
 *   - Vec2f pos, s32 color, s32 num, f32 z parameter spelling
 * residual:
 *   - prologue order: object emits `move $s1,$a1` then `mov.s $f20,$f12`; retail is the reverse
 *   - beqz target (object 0x36458c, retail 0x364598) because object is 24B shorter
 *   - loop test form: object is top-test with `b` to test at end of each branch; retail is bottom-test
 *     with `bnez` at the bottom of the loop
 *   - `i = 0` placement / loop prologue order differs
 */

#include "include_asm.h"
#include "type.h"

/* These supporting decls are required for the body to compile. */
typedef void (*D_00887300_fn)(u32, u32);
typedef struct {
    f32 x;
    f32 y;
} Vec2f;

extern s32 iGpffffb5a8;
extern f32 D_0064E310[];
extern f32 D_0064E314[];
extern f32 D_0064E318[];
extern f32 D_0064E31C[];
extern f32 D_008872F8[];
extern f32 iGpffff8094;
extern f32 iGpffff81e0;
extern void (*D_00887300[])(u32 state, u32 value);
extern void (*D_00887310[])(s32, void *, s32);
extern char D_005E5810[];
extern char D_0064E2F8[];

u32 func_00105ed0(void);
s32 func_0046a770(char *param);
void func_0046d730(char *, s32);
void func_0046d3b0(s32 parent, s32 arg0, s32 arg1, f32 x, f32 y, u8 arg2, u8 arg3,
                   f32 z, s32 arg4);

// FUN_00364320
#pragma push
#pragma opt_common_subs off
void func_00364320(Vec2f pos, s32 color, s32 num, f32 z)
{
    char tmp[64];
    s32 ch;
    s32 i;
    s32 alpha;

    if (color & 0xFF) {
        if (num <= 0) {
            num = func_00105ed0();
        }
        func_003645c0(tmp, num);
        if (iGpffffb5a8 == 0) {
            s32 temp = func_0046a770(D_005E5810);
            iGpffffb5a8 = temp;
            if (temp == 0) {
                func_0046d730(D_0064E2F8, 0x31);
            }
        }
        {
            u32 *base = (u32 *)D_00887300;
            ((D_00887300_fn)base[0])(6, 1);
            ((D_00887300_fn)base[0])(7, 2);
            ((D_00887300_fn)base[0])(8, 1);
            ((D_00887300_fn)base[0])(9, 2);
            ((D_00887300_fn)base[0])(0xC, 1);
            ((D_00887300_fn)base[0])(0xB, 6);
            ((D_00887300_fn)base[0])(0xA, 5);
            ((D_00887300_fn)base[0])(2, 4);
            ((D_00887300_fn)base[0])(0xE, 0);
        }
        alpha = 0xFF - (color & 0xFF);
        func_0046d3b0(0, iGpffffb5a8, 0x19, pos.x, pos.y, 0, alpha, z, 0);
        pos.x += 36.0f;
        for (i = 0; ; i++) {
            ch = tmp[i];
            if (ch == 0) {
                break;
            }
            if (ch == '.') {
                func_0046d3b0(0, iGpffffb5a8, 0x18, pos.x, pos.y + 20.0f, 0, alpha, z, 0);
                pos.x += 8.0f;
            } else {
                func_0046d3b0(0, iGpffffb5a8, ch - 0x22, pos.x, pos.y + 20.0f, 0, alpha, z, 0);
                pos.x += 19.0f;
            }
        }
    }
}
#pragma pop
