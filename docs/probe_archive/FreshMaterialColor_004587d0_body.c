/* Fresh material color callback: func_004587d0 is MATCH, 1136/1136 bytes,
 * 23 independently resolved relocations (15 calls and four HI/LO address pairs),
 * no alignment tail. All 59 prior owner instruction bodies and relocation lists
 * are unchanged, including both existing callers migrated to actual material
 * creation and integer-setter contracts. The callback retains its existing
 * u8-pointer input/return declarations; no invented complete RpMaterial layout.
 * 
 * Initial complete source: 1140/1136 bytes, 729 differing bytes. Separate userdata
 * lifetimes and direct initialization getter forwarding remove the extra move:
 * 1136/1136, 18 differences. Declaring the second search index before its saved
 * color and using unsigned >255 rather than >=256 comparisons close the final
 * register differences. No special pragmas, assembly or padding are introduced.
 * The high alpha packing shift explicitly promotes to u32 before shifting.
 * 
 * Runtime: 131072 guarded Wasm32 cases pass normally and with undefined-behavior,
 * float-cast-overflow and float-divide-by-zero sanitizer traps. Actual callback
 * and eight actual provider bodies are executed: material count/index accessors,
 * userdata name/format/int getters, integer setter, initial presence lookup, and
 * material add wrapper. Allocation and string comparison are deterministic
 * boundaries, not RenderWare allocation or rendering implementations.
 * 
 * Independent state model compares the complete guarded material, all userdata
 * records and integer values, float scales and creation counts. Eight layouts
 * include sparse data slots, wrong formats, absent keys and later matching integer
 * entries. All 256 byte values, sixteen scale combinations and four successive
 * states cover persistent original color, externally replaced current color,
 * updated userdata values, repeated scaling, saturation, and both sides of the
 * 2^31 unsigned-conversion branch. Products are finite with truncated values
 * representable in u32; no portable claim is made for NaN, infinities or values
 * outside that conversion domain. Retail key bytes spell per3modelMatColor.
 * 
 * Controller partner func_00452870 remains ASM; its separate evidence archive
 * proves a four-byte unwritten actuator payload tail consumed by the retail callee.
 *
 */

#include "type.h"
#include "Kosaka/k_clump_internal.h"
extern s32 D_00711870_abs[];
typedef struct {
    u8 red, green, blue, alpha;
} Code45RGBA;
extern u32 func_00457a90(const RpMaterial *material, const char *name);
extern s32 func_003bcfa0(RpMaterial *material, char *name, s32 format, s32 numElements);
extern void func_003bd0d0(u8 *userData, s32 index, s32 value);

// FUN_004587D0
u8 *func_004587d0(u8 *material, u8 *data)
{
    f32 *scale = (f32 *)data;
    s32 i;
    s32 found;

    if (func_00457a90((RpMaterial *)material, (const char *)D_00711870_abs) == 0)
    {
        u32 packedColor;
        s32 index;

        packedColor = ((u32)*(u8 *)(material + 7) << 24) |
                      (*(u8 *)(material + 4) << 16) |
                      (*(u8 *)(material + 5) << 8) |
                      *(u8 *)(material + 6);

        index = func_003bcfa0((RpMaterial *)material, (char *)D_00711870_abs, rpINTUSERDATA, 1);
        func_003bd0d0((u8 *)func_003bd000((RpMaterial *)material, index), 0, (s32)packedColor);
    }

    found = 0;
    for (i = 0; i < func_003bcfb0((RpMaterial *)material); i++)
    {
        RpUserDataArray *userData;
        userData = func_003bd000((RpMaterial *)material, i);
        func_003bd040(userData);
        if (func_004426e8(func_003bd040(userData), (const char *)D_00711870_abs) == 0)
        {
            found = 1;
            break;
        }
    }

    if (found == 1)
    {
        s32 j;
        u32 colorValue = 0;
        u32 red;
        u32 green;
        u32 blue;
        u32 alpha;
        Code45RGBA color;

        for (j = 0; j < func_003bcfb0((RpMaterial *)material); j++)
        {
            RpUserDataArray *userData;
            userData = func_003bd000((RpMaterial *)material, j);
            if (func_004426e8(func_003bd040(userData), (const char *)D_00711870_abs) == 0 &&
                func_003bd050(userData) == rpINTUSERDATA)
            {
                colorValue = (u32)func_003bd070(userData, 0);
                break;
            }
        }

        red = (u32)((f32)((colorValue >> 16) & 0xFF) * scale[0]);
        green = (u32)((f32)((colorValue >> 8) & 0xFF) * scale[1]);
        blue = (u32)((f32)(colorValue & 0xFF) * scale[2]);
        alpha = (u32)((f32)((colorValue >> 24) & 0xFF) * scale[3]);

        if (red > 0xFF)
        {
            red = 0xFF;
        }
        color.red = red;

        if (green > 0xFF)
        {
            green = 0xFF;
        }
        color.green = green;

        if (blue > 0xFF)
        {
            blue = 0xFF;
        }
        color.blue = blue;

        if (alpha > 0xFF)
        {
            alpha = 0xFF;
        }
        color.alpha = alpha;

        *(Code45RGBA *)(material + 4) = color;
    }

    return material;
}