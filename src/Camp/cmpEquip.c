#include "include_asm.h"
/* Persona 4 USA decompilation - cmpEquip.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"

void func_001437b0(void *arg0, s32 arg1, s32 arg2);
void func_001344d0(u8 *arg0);
void func_00131a00(u8 *arg0);
s16 func_00106cd0(s16 arg0, s16 arg1);
s32 func_00106600(s16 id);
s32 func_00106c30(s16 arg0, s16 arg1);
s32 func_00106c80(s16 arg0);
s16 func_00353ce0(void *arg0);
void memset(void *arg0, s32 arg1, s32 arg2);
void *func_0046a770(void *arg0);
s32 func_0046d200(void *arg0, s8 arg1);
void func_0046d730(void *arg0, s32 arg1);
extern u8 D_005E5830[];
extern u8 D_005E5850[];
extern u8 D_005E57F0[];
extern s8 D_005E76E0[];
extern u8 D_005E7BA0[];
extern u8 D_005E7720[];
extern u8 D_005E8020[];
extern u8 D_005E84A0[];
extern u8 D_005E8920[];
extern u8 D_005E8DA0[];
extern u8 D_005E9220[];
extern u8 D_005E96A0[];
extern u8 D_005E9B20[];
extern u8 D_005E9FA0[];
extern u8 D_0064B2E0[];
extern u8 D_0064B2E4[];
extern u8 D_0064B2E8[];
extern u8 D_0064B2EC[];
extern u8 D_0064B2F4[];
/* measured: both initializers hoist the conversion constants and table bases. */
#pragma opt_loop_invariants on
/* measured: initializer conversion and table setup match the retail window. */
// FUN_001312B0
void func_001312b0(u8 *arg0)
{
    s16 inner_i;
    s16 value;
    s32 offset;
    void *asset0;
    void *asset1;
    void *asset2;
    u8 *base;
    s32 *slot;
    s16 final_i;
    s16 clear_i;
    s16 second_i;
    s16 table_i;
    s16 outer_i;
    s16 inner_value;
    f32 float_value;
    s8 byte;

    memset(arg0, 0, 0x1598);
    base = arg0;
    *(s32 *)(base + 4) = 0;
    *(s32 *)(base + 8) = 0;
    *(u8 *)base = 0xFF;
    *(s32 *)(base + 0x18) = -1;
    *(s32 *)(base + 0x14) = 0;

    for (clear_i = 0; clear_i < 4; clear_i++) {
        *(s16 *)(base + clear_i * 2 + 0x28) = 0;
    }
    for (table_i = 0; table_i < 0x29; table_i++) {
        offset = table_i * 0x1C;
        *(f32 *)(base + table_i * 0x30 + 0xC90) = *(f32 *)(D_005E7BA0 + offset);
        *(f32 *)(base + table_i * 0x30 + 0xC94) = *(f32 *)(D_005E7BA0 + offset + 4);
        *(u8 *)(base + table_i * 0x30 + 0xC9A) = *(u8 *)(D_005E7BA0 + offset + 0x10);
        float_value = *(f32 *)(D_005E7BA0 + offset + 8);
        *(u16 *)(base + table_i * 0x30 + 0xCA0) = (u16)float_value;
        float_value = *(f32 *)(D_005E7BA0 + offset + 0xC);
        *(u16 *)(base + table_i * 0x30 + 0xCA6) = (u16)float_value;
    }
    for (second_i = 0; second_i < 3; second_i++) {
        *(s32 *)(base + second_i * 0x30 + 0x1440) = 0;
        *(s32 *)(base + second_i * 0x30 + 0x1430) = 0;
        *(s32 *)(base + second_i * 0x30 + 0x143C) = 0;
        *(s32 *)(base + second_i * 0x30 + 0x1434) = 0;
        *(u8 *)(base + second_i * 0x30 + 0x1449) = 0;
        *(u8 *)(base + second_i * 0x30 + 0x1448) = 0;
        *(s32 *)(base + second_i * 0x30 + 0x1458) = 0;
        *(s32 *)(base + second_i * 0x30 + 0x145C) = 3;
    }
    value = func_00353ce0(base + 0x38);
    *(s16 *)(base + 0x48) = value;
    for (outer_i = 0; outer_i < *(s16 *)(base + 0x48); outer_i++) {
        value = *(s16 *)(base + outer_i * 2 + 0x38);
        inner_i = 0;
        slot = (s32 *)(base + outer_i * 6);
        while (inner_i < 3) {
            inner_value = func_00106cd0(value, inner_i);
            ((s16 *)slot)[inner_i + 0x624] = inner_value;
            inner_i++;
        }
    }
    func_00134560(base, 0);
    asset0 = func_0046a770(D_005E5830);
    if (asset0 == 0) {
        func_0046d730(D_005E9FA0, 0x26A);
    }
    asset1 = func_0046a770(D_005E5850);
    if (asset1 == 0) {
        func_0046d730(D_005E9FA0, 0x26C);
    }
    *(s32 *)(base + 0x1590) = (s32)(asset2 = func_0046a770(D_005E57F0));
    if (asset2 == 0) {
        func_0046d730(D_005E9FA0, 0x26E);
    }
    for (final_i = 0; final_i < 0x34; final_i++) {
        if (final_i < 0x29) {
            slot = (s32 *)(base + final_i * 4 + 0x14C0);
            byte = D_005E76E0[final_i];
            *slot = func_0046d200(asset0, byte);
        } else if (final_i < 0x33) {
            slot = (s32 *)(base + final_i * 4 + 0x14C0);
            byte = D_005E76E0[final_i];
            *slot = func_0046d200(asset1, byte);
        } else {
            slot = (s32 *)(base + final_i * 4 + 0x14C0);
            byte = D_005E76E0[final_i];
            *slot = func_0046d200(asset2, byte);
        }
        if (*slot == 0) {
            func_0046d730(D_005E9FA0, 0x27B);
        }
    }
}

// FUN_00131730
void func_00131730(s16 *arg0) {
    s16 i;
    s16 count;
    s16 id;
    s32 type;
    s64 call_type;
    s32 found;
    s32 filter;
    s16 value;
    s16 *entry;

    id = arg0[arg0[20] + 28];
    type = arg0[21];
    call_type = type;
    for (i = 0, count = 0; i < 0x2FF; i++) {
        found = i == func_00106cd0(id, call_type);
        if (!found) {
            filter = (u8)func_00106600((s16)i) != 0;
            if (filter) {
                filter = func_00106c30(i, id) != 0;
            }
            if (filter) {
                filter = (s32)type == func_00106c80(i);
            }
            if (!filter) {
                goto skip;
            }
        }
        value = found + (u8)func_00106600((s16)i);
        if (value > 99) {
            value = 99;
        }
        entry = &arg0[2 * count];
        entry[37] = i;
        entry[38] = value;
        count++;
    skip:
        ;
    }
    arg0[1571] = count;
    if (count > 0x2FF) {
        func_0046d730(D_005E9FA0, 0x299);
    }
}
// FUN_001318C0
s32 func_001318c0(u8 *arg0) {
    s32 v = *(s32 *)(arg0 + 0x14);

    switch (v) {
    case 0:
        v += 1;
        *(s32 *)(arg0 + 0x14) = v;
        return 1;
    case 1:
        return 1;
    default:
        return 0;
    }
}

// FUN_00131910
s32 func_00131910(u8 *arg0) {
    s32 i;
    s32 rv;
    u8 *p;

    rv = 1;
    if (*(s16 *)(arg0 + 0x20) < 0x64) {
        *(s16 *)(arg0 + 0x20) = *(s16 *)(arg0 + 0x20) + 1;
    }
    for (i = 0; i < 0x29; i++) {
        p = arg0 + i * 0x30;
        func_001437b0(p + 0xC80, *(s16 *)(arg0 + 0x20), 0);
        if (*(u8 *)(p + 0xC9A) != 0) {
            rv = 0;
        }
    }
    *(s16 *)(arg0 + 0x22) = *(s16 *)(arg0 + 0x22) + 1;
    if (*(s16 *)(arg0 + 0x22) >= 0x168) {
        *(s16 *)(arg0 + 0x22) = 0;
    }
    func_001344d0(arg0);
    func_00131a00(arg0);
    return rv;
}
/* Equipment-menu renderer. Whole-owner MWCCPS2 b210 -O2 match (2026-09-30):
 * 10920 bytes plus the retail window's 8-byte zero tail; frame 0x110.
 * Byte/halfword conversion and coordinate snapshots preserve the retail ABI.
 * The two local records hold logical actor/opacity snapshots only. Pointer
 * address accumulation below uses the EE's 32-bit unsigned address domain.
 * opt_lifetimes retains the original call-crossing values; dead assignments
 * remain enabled. Both settings are scoped to this function.
 */
// FUN_00131A00
#pragma push
#pragma opt_lifetimes on
#pragma opt_dead_assignments on
void func_00131a00(u8 *arg0)

{
    typedef struct { f32 x, y; } Vec2f;
    typedef union { Vec2f xy; s64 packed; } PackedVec2f;
    PackedVec2f drawPosition;
    extern void func_0034f1e0(void);
    extern void func_0034c270(Vec2f arg0, s32 arg1, s32 arg2, f32 arg3);
    extern void func_0034f2e0(void *arg0, f32 fparg0, f32 fparg1, u8 arg1, u8 arg2, u8 arg3, u8 arg4);
    extern void func_0034f320(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u16 arg5, u16 arg6, s16 arg7, f32 fparg3, s16 arg_sp0);
    extern void func_00112300(Vec2f arg0, f32 fparg0, u8 arg1, u8 *arg2);
    extern void func_001125d0(u8 *arg0);
    extern u32 func_00106880(s16 arg0);
    extern s16 func_00106cd0(s16 arg0, s16 arg1);
    extern u32 func_0010d6d0(s16 arg0);
    extern s32 func_00134da0(s32 arg0);
    extern void func_00134e50(u8 *arg0, s64 arg1, s64 arg2, u8 arg3);
    extern void func_00134f40(u8 *arg0, s64 arg1, s64 arg2, u8 arg3);
    extern void func_00135130(u8 *arg0, s64 arg1, u8 arg2, u8 *arg3);
    extern void func_00135520(u8 *arg0, PackedVec2f arg1, u8 arg2, u16 arg3);
    extern s32 func_00274ed0(f32 x, f32 y, f32 scale, s32 color, s8 chr, s32 id, const char *str, s32 flags, s32 extra);
    extern void func_0034f9d0(Vec2f arg0, f32 fparg0, u8 arg1, s32 arg2, s32 arg3);
    extern void func_0046d730(void *arg0, s32 arg1);
  s16 temp_v2;
  /* Logical snapshots of values preserved across the draw calls, not external layouts. */
  struct { s16 id; } actor;
  s16 temp_v8;
  s16 selectedItemId;
  s8 labelStyle;
  s64 rowSelected;
  u8 alpha;
  struct { u8 value; } opacity;
  u8 *actorPalette;
  s16 rowIcon;
  u8 descriptorAlpha;
  u8 *pbVar7;
  u8 *work;
  u8 *pbVar9;
  u8 *pbVar11;
  s16 *partyIds;
  u8 *drawSprite;
  typedef struct { u8 r, g, b, a; } EquipColor;
  EquipColor *palette;
  s16 temp_v1;
  u16 temp_v12;
  u16 temp_v13;
  u32 temp_v3;
  s32 packedColor;
  typedef struct { s16 itemId; s16 quantity; u16 _pad; s16 _2a; u32 _28; u32 _24; u32 _20; u16 _1c; u16 _1a; u16 _18; } EquipItemDescriptor;
  EquipItemDescriptor descriptor;
  s32 temp_v4;
  char *labelText;
  u16 borderMode;
  f32 opacityScale;
  f32 originX, originY;
  f32 temp_v9;
  f32 temp_v10;
  f32 drawY;
  f32 scaleX;
  f32 scaleY;


  work = (u8 *)arg0;
  partyIds = (s16 *)(work + 0x38);
  actor.id = partyIds[*(s16 *)(work + 0x28)];
  func_0034f1e0();
  originX = *(f32 *)(work + 4);
  originY = *(f32 *)(work + 8);
  opacityScale = (f32)*work / 255.0f;
  if (*(s32 *)(work + 0x10) != 0) {
    drawPosition.xy.x = originX;
    drawPosition.xy.y = originY;
    temp_v9 = opacityScale * 255.0f;
    alpha = (u8)temp_v9;
    func_0034c270(drawPosition.xy,alpha,*(s32 *)(work + 0x10),0.0f);
  }
  if ((*(u32 *)(work + 0x1c) & 0x1000) != 0) {
    pbVar7 = *(u8 **)(work + 0x157c);
    *(u16 *)(pbVar7 + 0x1c) = 0x3d;
    *(u16 *)(pbVar7 + 0x1e) = 0x3f;
    drawPosition.xy.x = originX + *(f32 *)(work + 0x1260) + (f32)0x212;
    drawPosition.xy.y = (originY + *(f32 *)(work + 0x1264)) - 3.0f;
    temp_v9 = (f32)work[0x126a];
    temp_v9 *= opacityScale;
    alpha = (u8)temp_v9;
    scaleX = (f32)*(u16 *)(work + 0x1270);
    scaleY = (f32)*(u16 *)(work + 0x1276);
    func_0034f320(pbVar7,drawPosition.xy.x,drawPosition.xy.y,0.0f,0xff,0xff,0x81,alpha,(u16)scaleX,(u16)scaleY,0x3d,
                  (f32)(s32)*(s16 *)(work + 0x22),0x3f);
    drawPosition.xy.x = originX + *(f32 *)(work + 0x1290) + (f32)0x226;
    drawPosition.xy.y = (originY + *(f32 *)(work + 0x1294)) - 22.0f;
    temp_v9 = (f32)work[0x129a];
    temp_v9 *= opacityScale;
    alpha = (u8)temp_v9;
    scaleX = (f32)*(u16 *)(work + 0x12a0);
    scaleY = (f32)*(u16 *)(work + 0x12a6);
    func_0034f320(pbVar7,drawPosition.xy.x,drawPosition.xy.y,0.0f,0xfb,0xa2,0,alpha,(u16)scaleX,(u16)scaleY,0x3d,
                  (f32)(s32)*(s16 *)(work + 0x22),0x3f);
  }
  if ((*(u32 *)(work + 0x1c) & 0x400) != 0) {
    pbVar9 = *(u8 **)(work + 0x158c);
    drawPosition.xy.x = originX + *(f32 *)(work + 0xc90) + 20.0f;
    drawPosition.xy.y = originY + *(f32 *)(work + 0xc94) + 358.0f;
    temp_v9 = (f32)work[0xc9a];
    temp_v9 *= opacityScale;
    alpha = (u8)temp_v9;
    func_0034f2e0(pbVar9,drawPosition.xy.x,drawPosition.xy.y,0xff,0xff,0xff,alpha);
  }
  if ((*(u32 *)(work + 0x1c) & 0x800) != 0) {
    pbVar9 = *(u8 **)(work + 0x158c);
    drawPosition.xy.x = originX + *(f32 *)(work + 0xcc0) + (f32)0x1D1;
    drawPosition.xy.y = originY + *(f32 *)(work + 0xcc4) + 20.0f;
    temp_v9 = (f32)work[0xcca];
    temp_v9 *= opacityScale;
    alpha = (u8)temp_v9;
    func_0034f2e0(pbVar9,drawPosition.xy.x,drawPosition.xy.y,0xff,0xff,0xff,alpha);
  }
  if ((*(u32 *)(work + 0x1c) & 0x80) != 0) {
    pbVar9 = *(u8 **)(work + 0x1564);
    drawPosition.xy.x = originX + *(f32 *)(work + 0x12c0) + 20.0f;
    drawPosition.xy.y = originY + *(f32 *)(work + 0x12c4) + (f32)0x195;
    temp_v9 = (f32)work[0x12ca];
    temp_v9 *= opacityScale;
    alpha = (u8)temp_v9;
    func_0034f2e0(pbVar9,drawPosition.xy.x,drawPosition.xy.y,0xff,0xff,0xff,alpha);
  }
  if ((*(u32 *)(work + 0x1c) & 0x100) != 0) {
    pbVar9 = *(u8 **)(work + 0x1568);
    drawPosition.xy.x = originX + *(f32 *)(work + 0x12f0) + 146.0f;
    drawPosition.xy.y = originY + *(f32 *)(work + 0x12f4) + (f32)0x195;
    temp_v9 = (f32)work[0x12fa];
    temp_v9 *= opacityScale;
    alpha = (u8)temp_v9;
    func_0034f2e0(pbVar9,drawPosition.xy.x,drawPosition.xy.y,0xff,0xff,0xff,alpha);
  }
  if ((*(u32 *)(work + 0x1c) & 0x200) != 0) {
    pbVar9 = *(u8 **)(work + 0x1564);
    drawPosition.xy.x = originX + *(f32 *)(work + 0x1320) + 20.0f;
    drawPosition.xy.y = originY + *(f32 *)(work + 0x1324) + (f32)0x195;
    temp_v9 = (f32)work[0x132a];
    temp_v9 *= opacityScale;
    alpha = (u8)temp_v9;
    func_0034f2e0(pbVar9,drawPosition.xy.x,drawPosition.xy.y,0xff,0xff,0xff,alpha);
  }
  if ((*(u32 *)(work + 0x1c) & 4) != 0) {
    temp_v4 = 0;
    while (temp_v8 = (s16)temp_v4, temp_v8 < *(s16 *)(work + 0x48)) {
      drawPosition.xy.x = originX + *(f32 *)(work + (s16)temp_v4 * 0x30 + 0x1080) + 35.0f;
      {
      drawPosition.xy.y = 20.0f + (33.0f * (f32)temp_v4 + (0.0f + (originY + *(f32 *)(work + (s16)temp_v4 * 0x30 + 0x1084))));
      scaleX = (f32)*(u16 *)(work + (s16)temp_v4 * 0x30 + 0x1090);
      scaleY = (f32)*(u16 *)(work + (s16)temp_v4 * 0x30 + 0x1096);
      temp_v9 = (f32)work[(s16)temp_v4 * 0x30 + 0x108a];
    temp_v9 *= opacityScale;
      opacity.value = (u8)temp_v9;
      packedColor = opacity.value | 0xffffff00;
      if (*(s16 *)(work + 0x28) == (s16)temp_v4) {
        actorPalette = D_0064B2E8;
        labelStyle = 8;
      }
      else {
        actorPalette = D_0064B2E0;
        labelStyle = 6;
      }
      drawSprite = *(u8 **)(work + 0x14c0);
      drawY = drawPosition.xy.y;
      func_0034f320(drawSprite,drawPosition.xy.x,drawY,0.0f,*actorPalette,actorPalette[1],actorPalette[2],
                    opacity.value,(u16)scaleX,(u16)scaleY,0,0.0f,0);
      drawSprite = *(u8 **)(work + 0x14c4);
      func_0034f320(drawSprite,drawPosition.xy.x + 202.0f,drawY,0.0f,*actorPalette,actorPalette[1],
                    actorPalette[2],opacity.value,(u16)scaleX,(u16)scaleY,0,0.0f,0);
      labelText = (char *)func_0010d6d0(*(s16 *)(work + temp_v8 * 2 + 0x38));
      func_00274ed0(drawPosition.xy.x + 105.0f,drawY,0.0f,packedColor,labelStyle,1,labelText,8,0);
      }
      temp_v4 = (s32)(s16)(temp_v4 + 1);
    }
  }
  if ((*(u32 *)(work + 0x1c) & 0x10) != 0) {
    s16 rowCounter;
    u8 *pbVar7;
    for (rowCounter = 0; rowCounter < 3; ++rowCounter) {
      rowSelected = 0;
      if ((*(u32 *)(work + 0x1c) & 0x20) != 0) {
        drawPosition.xy.x = originX + *(f32 *)(work + rowCounter * 0x30 + 0xf90) + 253.0f;
        drawPosition.xy.y = originY + *(f32 *)(work + rowCounter * 0x30 + 0xf94) + 190.0f +
                   (f32)(rowCounter * 0x3f);
        temp_v9 = (f32)work[rowCounter * 0x30 + 0xf9a];
    temp_v9 *= opacityScale;
        alpha = (u8)temp_v9;
        {
          s64 selectedMode;
          if (*(s16 *)(work + 0x2a) == rowCounter) {
            selectedMode = 1;
            rowSelected = selectedMode;
          } else {
            selectedMode = 0;
          }
          func_00134e50(work, drawPosition.packed, selectedMode, (u8)(alpha));
        }
      }
      drawPosition.xy.x = originX + *(f32 *)(work + rowCounter * 0x30 + 0xf00) + 253.0f;
      drawPosition.xy.y = originY + *(f32 *)(work + rowCounter * 0x30 + 0xf04) + 190.0f +
                 (f32)(rowCounter * 0x3f);
      temp_v9 = (f32)work[rowCounter * 0x30 + 0xf0a];
    temp_v9 *= opacityScale;
      alpha = (u8)temp_v9;
      {
      scaleX = (f32)*(u16 *)(work + rowCounter * 0x30 + 0xf10);
      scaleY = (f32)*(u16 *)(work + rowCounter * 0x30 + 0xf16);
      switch (rowCounter) {
      case 0:
        temp_v3 = func_00106880(func_00106cd0(actor.id, 0));
        temp_v4 = func_00134da0(temp_v3);
        rowIcon = (s16)temp_v4;
        break;
      case 1:
        rowIcon = 0xe;
        break;
      case 2:
        rowIcon = 0xf;
        break;
      }
      if (rowSelected) {
        pbVar7 = D_0064B2EC;
        pbVar11 = D_0064B2E8;
      }
      else {
        pbVar7 = D_0064B2E4;
        pbVar11 = D_0064B2E0;
      }
      if (rowIcon < 0xe) {
        pbVar9 = *(u8 **)(work + 0x14c8);
      }
      else {
        pbVar9 = *(u8 **)(work + 0x14cc);
      }
      {
      drawY = drawPosition.xy.y;
      func_0034f320(pbVar9,drawPosition.xy.x,drawPosition.xy.y,0.0f,*pbVar7,pbVar7[1],pbVar7[2],alpha,
                    (u16)scaleX,(u16)scaleY,0,0.0f,0);
      drawSprite = *(u8 **)(work + rowIcon * 4 + 0x14c0);
      func_0034f320(drawSprite,drawPosition.xy.x + 3.0f,drawY + 2.0f,0.0f,
                    *pbVar11,pbVar11[1],pbVar11[2],alpha,(u16)scaleX,(u16)scaleY,0,0.0f,0);
      }
      }
      drawPosition.xy.x = originX + *(f32 *)(work + rowCounter * 0x30 + 0xe70) + 255.0f;
      drawPosition.xy.y = originY + *(f32 *)(work + rowCounter * 0x30 + 0xe74) + 193.0f +
                 (f32)(rowCounter * 0x3f);
      temp_v9 = (f32)work[rowCounter * 0x30 + 0xe7a];
    temp_v9 *= opacityScale;
      alpha = (u8)temp_v9;
      drawSprite = *(u8 **)(work + rowCounter * 4 + 0x14d0);
      if (rowSelected) {
        pbVar7 = D_0064B2EC;
      }
      else {
        pbVar7 = D_0064B2E4;
      }
      func_0034f2e0(drawSprite,drawPosition.xy.x + 42.0f,drawPosition.xy.y + 1.0f,*pbVar7,
                    pbVar7[1],pbVar7[2],alpha);
      drawPosition.xy.x = drawPosition.xy.x + 42.0f;
      drawPosition.xy.y = drawPosition.xy.y + 24.0f;
      temp_v9 = (f32)work[rowCounter * 0x30 + 0xe7a];
    temp_v9 *= opacityScale;
      descriptorAlpha = (u8)temp_v9;
      func_001125d0((u8 *)&descriptor);
      if ((*(u32 *)(work + 0x1c) & 0x20) != 0) {
        if (rowSelected) {
          descriptor._1a = 3;
        } else {
          descriptor._1a = 2;
        }
      } else {
        descriptor._1a = 4;
      }
      descriptor.itemId = func_00106cd0(actor.id,rowCounter);
      descriptor.quantity = 0xffff;
      descriptor._28 = 0xffffffff;
      descriptor._24 = 1;
      descriptor._20 = 0;
      descriptor._1c = 0;
      descriptor._18 = 3;
      func_00112300(drawPosition.xy, 0.0f, descriptorAlpha, (u8 *)&descriptor);
    }
  }
  if ((*(u32 *)(work + 0x1c) & 8) != 0) {
    f32 pairY, pairScaleX, pairScaleY;
    drawPosition.xy.x = originX + *(f32 *)(work + 0x1200) + 35.0f;
    {
      drawPosition.xy.y = originY + *(f32 *)(work + 0x1204) + 20.0f;
    temp_v9 = (f32)work[0x120a];
    temp_v9 *= opacityScale;
    alpha = (u8)temp_v9;
    pairScaleX = (f32)*(u16 *)(work + 0x1210);
    pairScaleY = (f32)*(u16 *)(work + 0x1216);
    palette = (EquipColor *)D_0064B2F4;
    drawSprite = *(u8 **)(work + 0x14c0);
    pairY = drawPosition.xy.y;
    func_0034f320(drawSprite,drawPosition.xy.x,pairY,0.0f,palette->r,palette->g,
                  palette->b,alpha,(u16)pairScaleX,(u16)pairScaleY,0,0.0f,0);
    drawSprite = *(u8 **)(work + 0x14c4);
    func_0034f320(drawSprite,drawPosition.xy.x + 202.0f,pairY,0.0f,palette->r,palette->g,
                  palette->b,alpha,(u16)pairScaleX,(u16)pairScaleY,0,0.0f,0);
    }
    drawPosition.xy.x = originX + *(f32 *)(work + 0x1230) + 35.0f;
    drawPosition.xy.y = originY + *(f32 *)(work + 0x1234) + 20.0f;
    temp_v9 = (f32)work[0x123a];
    temp_v9 *= opacityScale;
    alpha = (u8)temp_v9;
    packedColor = (alpha) - 0x100;
    {
      /* EE addresses are 32-bit; accumulate the signed index as an unsigned address. */
      u32 partyAddress = *(s16 *)(work + 0x28) * 2;
      partyAddress += (u32)work;
      labelText = (char *)func_0010d6d0(*(s16 *)(partyAddress + 0x38));
    }
    func_00274ed0(drawPosition.xy.x + 105.0f,drawPosition.xy.y,0.0f,packedColor,7,1,labelText,8,0);
  }
  if ((*(u32 *)(work + 0x1c) & 2) != 0) {
    u8 headerAlpha, layoutAlpha;
    palette = (EquipColor *)D_0064B2F4;
    temp_v9 = (f32)work[0x105a];
    temp_v9 *= opacityScale;
    headerAlpha = (u8)temp_v9;
    drawSprite = *(u8 **)(work + 0x1570);
    drawPosition.xy.x = originX + *(f32 *)(work + 0x1050) + 18.0f;
    drawPosition.xy.y = originY + *(f32 *)(work + 0x1054) + 51.0f;
    func_0034f2e0(drawSprite,drawPosition.xy.x,drawPosition.xy.y,palette->r,palette->g,
                  palette->b,headerAlpha);
    drawSprite = *(u8 **)(work + 0x1574);
    drawPosition.xy.x = originX + *(f32 *)(work + 0x1050) + 186.0f;
    drawPosition.xy.y = originY + *(f32 *)(work + 0x1054) + 51.0f;
    func_0034f2e0(drawSprite,drawPosition.xy.x,drawPosition.xy.y,palette->r,palette->g,
                  palette->b,headerAlpha);
    drawSprite = *(u8 **)(work + 0x1578);
    drawPosition.xy.x = originX + *(f32 *)(work + 0x1050) + (f32)0x25F;
    drawPosition.xy.y = originY + *(f32 *)(work + 0x1054) + 90.0f;
    func_0034f2e0(drawSprite,drawPosition.xy.x,drawPosition.xy.y,palette->r,palette->g,
                  palette->b,headerAlpha);
    drawPosition.xy.x = originX + *(f32 *)(work + 0x1410) + 18.0f;
    drawPosition.xy.y = originY + *(f32 *)(work + 0x1414) + 60.0f;
    temp_v9 = (f32)work[0x141a];
    temp_v9 *= opacityScale;
    alpha = (u8)temp_v9;
    packedColor = (alpha) | 0xffffff00;
    labelText = (char *)func_0010d6d0(*(s16 *)(work + 0xc7e));
    func_00274ed0(drawPosition.xy.x + 88.0f,drawPosition.xy.y,0.0f,packedColor,7,1,labelText,8,0);
    drawPosition.xy.x = originX + *(f32 *)(work + 0x13e0) + 18.0f;
    drawPosition.xy.y = originY + *(f32 *)(work + 0x13e4) + 60.0f;
    temp_v9 = (f32)work[0x13ea];
    temp_v9 *= opacityScale;
    alpha = (u8)temp_v9;
    packedColor = (alpha) | 0xffffff00;
    {
      u32 partyAddress = *(s16 *)(work + 0x28) * 2;
      partyAddress += (u32)work;
      labelText = (char *)func_0010d6d0(*(s16 *)(partyAddress + 0x38));
    }
    func_00274ed0(drawPosition.xy.x + 88.0f,drawPosition.xy.y,0.0f,packedColor,7,1,labelText,8,0);
    palette = (EquipColor *)D_0064B2E0;
    temp_v9 = (f32)work[0x13ba];
    temp_v9 *= opacityScale;
    layoutAlpha = (u8)temp_v9;
    temp_v8 = *(s16 *)(work + 0x2a);
    switch (temp_v8) {
    case 0: {
      drawPosition.xy.x = originX + *(f32 *)(work + 0x13b0) + 48.0f;
      drawPosition.xy.y = originY + *(f32 *)(work + 0x13b4) + 96.0f;
      func_0034f2e0(*(void **)(work + 0x1528),drawPosition.xy.x,drawPosition.xy.y,(u8)palette->r,
                    palette->g,palette->b,layoutAlpha);
      drawPosition.xy.x = originX + *(f32 *)(work + 0x13b0) + (f32)0x171;
      drawPosition.xy.y = originY + *(f32 *)(work + 0x13b4) + 66.0f;
      func_0034f2e0(*(void **)(work + 0x150c),drawPosition.xy.x,drawPosition.xy.y,0xff,0xff,0xff,layoutAlpha);
      drawPosition.xy.x = originX + *(f32 *)(work + 0x13b0) + 460.0f;
      drawPosition.xy.y = originY + *(f32 *)(work + 0x13b4) + 66.0f;
      func_0034f2e0(*(void **)(work + 0x1510),drawPosition.xy.x,drawPosition.xy.y,0xff,0xff,0xff,layoutAlpha);

      break;
    }
    case 1: {
      drawPosition.xy.x = originX + *(f32 *)(work + 0x13b0) + 33.0f;
      drawPosition.xy.y = originY + *(f32 *)(work + 0x13b4) + 96.0f;
      func_0034f2e0(*(void **)(work + 0x152c),drawPosition.xy.x,drawPosition.xy.y,(u8)palette->r,
                    palette->g,palette->b,layoutAlpha);
      drawPosition.xy.x = originX + *(f32 *)(work + 0x13b0) + 71.0f;
      drawPosition.xy.y = originY + *(f32 *)(work + 0x13b4) + 103.0f;
      func_0034f2e0(*(void **)(work + 0x1530),drawPosition.xy.x,drawPosition.xy.y,(u8)palette->r,
                    palette->g,palette->b,layoutAlpha);
      drawPosition.xy.x = originX + *(f32 *)(work + 0x13b0) + (f32)0x171;
      drawPosition.xy.y = originY + *(f32 *)(work + 0x13b4) + 66.0f;
      func_0034f2e0(*(void **)(work + 0x1514),drawPosition.xy.x,drawPosition.xy.y,0xff,0xff,0xff,layoutAlpha);
      drawPosition.xy.x = originX + *(f32 *)(work + 0x13b0) + 460.0f;
      drawPosition.xy.y = originY + *(f32 *)(work + 0x13b4) + 66.0f;
      func_0034f2e0(*(void **)(work + 0x1518),drawPosition.xy.x,drawPosition.xy.y,0xff,0xff,0xff,layoutAlpha);

      break;
    }
    case 2: {
      drawPosition.xy.x = originX + *(f32 *)(work + 0x13b0) + 34.0f;
      drawPosition.xy.y = originY + *(f32 *)(work + 0x13b4) + 91.0f;
      func_0034f2e0(*(void **)(work + 0x1534),drawPosition.xy.x,drawPosition.xy.y,(u8)palette->r,
                    palette->g,palette->b,layoutAlpha);

      break;
    }
    }
    drawPosition.xy.x = originX + *(f32 *)(work + 0x1020) + 122.0f;
    drawPosition.xy.y = originY + *(f32 *)(work + 0x1024) + 94.0f;
    temp_v9 = (f32)work[0x102a];
    temp_v9 *= opacityScale;
    descriptorAlpha = (u8)temp_v9;
    func_001125d0((u8 *)&descriptor);
    selectedItemId = func_00106cd0(actor.id,*(s16 *)(work + 0x2a));
    descriptor.itemId = selectedItemId;
    descriptor.quantity = 0xffff;
    descriptor._28 = 0xffffffff;
    descriptor._24 = 1;
    descriptor._20 = 1;
    descriptor._1c = 1;
    descriptor._1a = 4;
    descriptor._18 = 3;
    func_00112300(drawPosition.xy, 0.0f, descriptorAlpha, (u8 *)&descriptor);
    drawPosition.xy.x = originX + *(f32 *)(work + 0x1380) + 122.0f;
    drawPosition.xy.y = originY + *(f32 *)(work + 0x1384) + 94.0f;
    temp_v9 = (f32)work[0x138a];
    temp_v9 *= opacityScale;
    descriptorAlpha = (u8)temp_v9;
    descriptor.itemId = *(s16 *)(work + 0xc7a);
    func_00112300(drawPosition.xy, 0.0f, descriptorAlpha, (u8 *)&descriptor);
  }
  if ((*(u32 *)(work + 0x1c) & 0x2000) != 0) {
    u8 scrollbarAlpha;
    f32 rawAlpha;
    f32 baseX;
    baseX = *(f32 *)(work + 0x1470) + (originX + *(f32 *)(work + 0xe10));
    temp_v10 = *(f32 *)(work + 0x1474) + (originY + *(f32 *)(work + 0xe14));
    rawAlpha = (f32)work[0xe1a];
    rawAlpha *= opacityScale;
    scrollbarAlpha = (u8)rawAlpha;
    drawPosition.xy.x = ((f32)0x25E + baseX);
    drawPosition.xy.y = temp_v10 + 133.0f;
    func_0034f2e0(*(void **)(work + 0x151c),((f32)0x25E + baseX),drawPosition.xy.y,0xff,0xff,0xff,scrollbarAlpha);
    drawPosition.xy.x = ((f32)0x25E + baseX);
    drawPosition.xy.y = temp_v10 + 298.0f;
    func_0034f2e0(*(void **)(work + 0x1520),((f32)0x25E + baseX),drawPosition.xy.y,0xff,0xff,0xff,scrollbarAlpha);
    drawPosition.xy.x = ((f32)0x25E + baseX);
    drawPosition.xy.y = temp_v10 + 136.0f;
    if (0 < *(s16 *)(work + 0xc46) - 5) {
      drawPosition.xy.y = drawPosition.xy.y +
                 (f32)(((*(s16 *)(work + 0x2c) * 0x42 + (s32)*(s16 *)(work + 0x2c)) * 2) /
                        (*(s16 *)(work + 0xc46) - 5));
    }
    palette = (EquipColor *)D_0064B2E8;
    func_0034f2e0(*(void **)(work + 0x1524),drawPosition.xy.x,drawPosition.xy.y,palette->r,palette->g,palette->b
                  ,scrollbarAlpha);
  }
  if ((*(u32 *)(work + 0x1c) & 1) != 0) {
    u8 panelAlpha;
    if (*(s16 *)(work + 0xc46) == 0) {
      func_0046d730(D_005E9FA0,0x507);
    }
    panelAlpha = work[0x144a];
    if (0 < (s32)panelAlpha) {
      drawPosition.xy.x = originX + *(f32 *)(work + 0x1440);
      drawPosition.xy.y = originY + *(f32 *)(work + 0x1444);
      func_00134f40(work, drawPosition.packed, 0, panelAlpha);
    }
    {
    s16 rowIndex;
    s32 lookupIndex;
    u8 rowAlpha;
    for (temp_v4 = 0; (s16)temp_v4 < 5; temp_v4 = (s16)(temp_v4 + 1)) {
      if ((s32)((s32)(s16)temp_v4 + (s32)*(s16 *)(work + 0x2c)) < (s32)*(s16 *)(work + 0xc46)) {
        rowIndex = (s16)temp_v4;
        drawPosition.xy.x = originX + *(f32 *)(work + rowIndex * 0x30 + 0xd20) + 122.0f;
        drawPosition.xy.y = *(f32 *)(work + rowIndex * 0x30 + 0xd24) + (originY + (f32)(rowIndex * 0x22)) +
                   137.0f;
        temp_v9 = (f32)work[rowIndex * 0x30 + 0xd2a];
        temp_v9 *= opacityScale;
        rowAlpha = (u8)temp_v9;
        lookupIndex = (s32)((s16 *)work)[0x16] + (s32)rowIndex;
        temp_v8 = *(s16 *)(work + lookupIndex * 4 + 0x4a);
        temp_v1 = *(s16 *)(work + lookupIndex * 4 + 0x4c);
        func_001125d0((u8 *)&descriptor);
        if (*(s16 *)(work + 0x2e) == rowIndex) {
          descriptor._1a = 3;
          func_00134f40(work, drawPosition.packed, 1, rowAlpha);
        }
        else {
          descriptor._1a = 5;
          func_00134f40(work, drawPosition.packed, 0, rowAlpha);
        }
        descriptor.itemId = temp_v8;
        descriptor.quantity = temp_v1;
        descriptor._28 = 0xffffffff;
        descriptor._24 = 1;
        descriptor._20 = 1;
        descriptor._1c = 1;
        descriptor._2a = selectedItemId;
        descriptor._18 = 3;
        func_00112300(drawPosition.xy, 0.0f, rowAlpha, (u8 *)&descriptor);
      }
    }
    }
  }
  if (((*(u32 *)(work + 0x1c) & 0x40) != 0) && (0 < *(s16 *)(work + 0xc46))) {
    borderMode = 0;
    func_001125d0((u8 *)&descriptor);
    drawPosition.xy.x = originX + *(f32 *)(work + 0x14a0) + 124.0f;
    drawPosition.xy.y = originY + *(f32 *)(work + 0x14a4) + 147.0f;
    descriptor._28 = 0xffffffff;
    descriptor._1c = 0;
    descriptor._24 = 0;
    descriptor._20 = 0;
    if (*(f32 *)(work + 0x149c) < 0.0f) {
      borderMode = 1;
    }
    else if (!(*(f32 *)(work + 0x149c) <= 0.0f)) {
      borderMode = 2;
    }
    func_00135520(arg0, drawPosition, work[0x14aa], borderMode);
    drawPosition.xy.x = originX + *(f32 *)(work + 0xe40) + 124.0f;
    drawPosition.xy.y = originY + *(f32 *)(work + 0xe44) + 147.0f;
    {
      u32 entryAddress = ((s32)*(s16 *)(work + 0x2c) + (s32)*(s16 *)(work + 0x2e)) * 4;
      entryAddress += (u32)work;
      descriptor.itemId = *(s16 *)(entryAddress + 0x4a);
      descriptor.quantity = *(s16 *)(entryAddress + 0x4c);
    }
    descriptor._28 = 0xffffffff;
    descriptor._24 = 1;
    descriptor._20 = 1;
    descriptor._2a = selectedItemId;
    descriptor._1a = 3;
    descriptor._1c = 1;
    descriptor._18 = 3;
    temp_v9 = (f32)work[0xe4a];
    temp_v9 *= opacityScale;
    func_00135130(arg0, drawPosition.packed, (u8)temp_v9, (u8 *)&descriptor);
  }
  drawPosition.xy.x = originX + *(f32 *)(work + 0x1350) + 640.0f;
  drawPosition.xy.y = originY + *(f32 *)(work + 0x1354) + 400.0f;
  temp_v9 = (f32)work[0x135a];
  temp_v9 *= opacityScale;
  alpha = (u8)temp_v9;
  func_0034f9d0(drawPosition.xy, 0.0f, (u8)(alpha), *(s16 *)(work + 0xc78), *(s32 *)(work + 0x1590));
  return;
}
#pragma opt_dead_assignments on

#pragma pop

// FUN_001344B0
s32 func_001344b0(u8 *arg0, s32 arg1, s16 arg2) {
    /* The offset must be computed before the base is added: writing
       `arg0 + arg1 * 2` makes mwcc emit `addu $v1,$a0,$v0`, retail has
       `addu $v1,$v0,$a0`. */
    s32 off = arg1 * 2;
    u8 *p = (u8 *)(off + (s32)arg0);

    *(s16 *)(p + 0x30) = *(s16 *)(p + 0x28);
    *(s16 *)(p + 0x28) = arg2;
    return 1;
}

// FUN_001344D0
void func_001344d0(u8 *arg0) {
    s32 i;
    s16 v;

    v = *(s16 *)(arg0 + 0x24);
    if (v < 0x64) {
        *(s16 *)(arg0 + 0x24) = v + 1;
    }
    for (i = 0; i < 3; i++) {
        func_001437b0(arg0 + i * 0x30 + 0x1430, *(s16 *)(arg0 + 0x24), 0);
    }
}

/* measured: equipment-mode switch and table update match the retail window. */
/* measured: common-subexpression elimination is disabled for the setup and switch layout. */
#pragma opt_common_subs off
// FUN_00134560
s32 func_00134560(u8 *arg0, s32 arg1)
{
    s32 i;
    s32 j;
    u8 *table;
    u8 *src;
    u8 *dst;
    f32 value;

    if (arg1 == *(s32 *)(arg0 + 0x18)) {
        return 0;
    }
    for (i = 0; i < 0x29; i++) {
        dst = arg0 + i * 0x30;
        *(f32 *)(dst + 0xC80) = *(f32 *)(dst + 0xC90);
        *(f32 *)(dst + 0xC84) = *(f32 *)(dst + 0xC94);
        *(u8 *)(dst + 0xC98) = *(u8 *)(dst + 0xC9A);
        *(u16 *)(dst + 0xC9C) = *(u16 *)(dst + 0xCA0);
        *(u16 *)(dst + 0xCA2) = *(u16 *)(dst + 0xCA6);
    }
    switch (arg1) {
    case 0:
        table = D_005E7720;
        *(s32 *)(arg0 + 0x1C) = 0x494;
        *(s16 *)(arg0 + 0xC78) = 0;
        break;
    case 1:
        table = D_005E7BA0;
        break;
    case 2:
        table = D_005E8020;
        *(s32 *)(arg0 + 0x1C) = 0x494;
        *(s16 *)(arg0 + 0xC78) = 0;
        break;
    case 3:
        table = D_005E84A0;
        *(s32 *)(arg0 + 0x1C) = 0x5BC;
        *(s16 *)(arg0 + 0xC78) = 0;
        *(f32 *)(arg0 + 0x11F4) =
            30.0f * (f32)*(s16 *)(arg0 + 0x28);
        *(f32 *)(arg0 + 0x1224) =
            30.0f * (f32)*(s16 *)(arg0 + 0x28);
        break;
    case 4:
        table = D_005E8920;
        *(s32 *)(arg0 + 0x1C) = 0x538;
        *(s16 *)(arg0 + 0xC78) = 0;
        break;
    case 5:
        table = D_005E8DA0;
        *(s32 *)(arg0 + 0x1C) = 0x538;
        *(s16 *)(arg0 + 0xC78) = 0;
        break;
    case 6:
        table = D_005E9220;
        func_00131730((s16 *)arg0);
        *(s32 *)(arg0 + 0x1C) = 0x3A0B;
        *(s16 *)(arg0 + 0xC78) = 3;
        break;
    case 7:
        table = D_005E96A0;
        *(s32 *)(arg0 + 0x1C) = 0x3A0B;
        *(s16 *)(arg0 + 0xC78) = 3;
        break;
    case 8:
    case 9:
        table = D_005E9B20;
        *(s32 *)(arg0 + 0x1C) = 0x3A4A;
        *(s16 *)(arg0 + 0xC78) = 4;
        break;
    default:
        func_0046d730(D_005E9FA0, 0x5F8);
        break;
    }
    if (table != 0) {
#pragma opt_common_subs on
        for (j = 0; j < 0x29; j++) {
            src = table + j * 0x1C;
            dst = arg0 + j * 0x30;
            *(f32 *)(dst + 0xC88) = *(f32 *)(src + 0);
            *(f32 *)(dst + 0xC8C) = *(f32 *)(src + 4);
            *(u8 *)(dst + 0xC99) = *(u8 *)(src + 0x10);
            value = *(f32 *)(src + 8);
            *(u16 *)(dst + 0xC9E) = (u16)value;
            value = *(f32 *)(src + 0xC);
            *(u16 *)(dst + 0xCA4) = (u16)value;
            *(s32 *)(dst + 0xCA8) = *(s32 *)(src + 0x14);
            *(s32 *)(dst + 0xCAC) = *(s32 *)(src + 0x18);
        }
    }
    *(s32 *)(arg0 + 0x18) = arg1;
    *(s16 *)(arg0 + 0x20) = 0;
    return 1;
}
#pragma opt_loop_invariants off
