/* Original translation unit sdkUttmx.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

extern u8 *func_003e2f60(s32 mode, s32 arg1, u8 *name);
extern s32 func_003e2910(u8 *fh, void *dst, s32 size);
extern void func_003e2e40(u8 *fh, s32 arg1);
extern void func_0044ea90(u8 *file, s32 line);
extern void func_0043f810(u8 *dst, void *src, s32 size);
extern s32 func_00463930(u8 *arg0);
extern u8 *(*jtbl_008873E8[])(s32 size, s32 align);
extern void (*jtbl_008873EC[])(u8 *ptr);
extern u8 D_00712688[];
extern void func_003ec2a0(s32 arg0);
extern void func_003ec2e0(s32 arg0);
extern u32 func_003ec3d0(s32 arg0, s32 arg1);
extern s32 func_003ec590(u16 arg0, u16 arg1, s32 arg2, s32 arg3);
extern u32 func_003ec6a0(s32 arg0, s32 arg1, s32 arg2);
extern void func_0046d730(u8 *file, s32 line);
extern void func_00463ea0(u32 arg0, u32 arg1, u32 arg2);

// FUN_00463D60
s32 func_00463d60(u8 *name)
{
    u8 hdr[0x40];
    u8 *fh;
    s32 ret;
    u8 *buf;

    ret = 0;
    fh = func_003e2f60(2, 1, name);
    if (fh != NULL) {
        func_003e2910(fh, hdr, 0x40);
        func_0044ea90(D_00712688, 0x3BE);
        buf = jtbl_008873E8[0](*(s32 *)(hdr + 4), 0x40000);
        func_003e2910(fh, buf + 0x40, *(s32 *)(hdr + 4) - 0x40);
        func_0043f810(buf, hdr, 0x40);
        ret = func_00463930(buf);
        jtbl_008873EC[0](buf);
        func_003e2e40(fh, 0);
    }
    return ret;
}
// FUN_00463EA0
INCLUDE_ASM("asm/nonmatchings/sdkUttmx", func_00463ea0);

/* measured: plain-C reconstruction is 1240B against the 1248B retail window at
   verify normalized_diff 10. The header checks, format switch, allocation and
   upload/copy paths match; only the func_003ec590 argument setup differs:
   fndiff 0x218/0x21C/0x220 (candidate ori,lhu,lhu; retail lhu,lhu,ori).
   Tried direct flag expression, named flag temporary, dimension temporaries,
   separate pointer-pinned dimensions, comma sequencing, and both switch-case
   declaration orders; all either retained these rows or worsened coloring.
   Committed at nd 10. */
// FUN_00464100
s32 func_00464100(u8 *arg0, s32 arg1)
{
  u8 *data_ptr;
  s32 texel_scale;
  s32 copy_mode;
  u32 texture_buffer;
  u8 palette_present;
  s32 source_addr;
  s32 texture_handle;
  u32 *palette_handle_ptr;
  u32 resource_value;
  s32 bits_per_pixel;
  u8 format_code;
  int palette_format;
  unsigned int width;
  u16 height;
  texture_handle = (source_addr = 0);
  if (arg0 == ((void *) 0))
  {
    func_0046d730(D_00712688, 0x453);
  }
  if ((*((u8 *) (arg0 + 0))) != 2)
  {
    func_0046d730(D_00712688, 0x457);
  }
  if ((*((u8 *) (arg0 + 1))) != 0)
  {
    func_0046d730(D_00712688, 0x458);
  }
  if (((((*((u8 *) (arg0 + 8))) != 0x54) || ((*((u8 *) (arg0 + 9))) != 0x4D)) || ((*((u8 *) (arg0 + 0xA))) != 0x58)) && ((*((u8 *) (arg0 + 0xB))) != 0x30))
  {
    func_0046d730(D_00712688, 0x459);
  }
  format_code = *((u8 *) (arg0 + 0x16));
  switch (format_code)
  {
    case 0:
      bits_per_pixel = 0x20;
      break;

    case 1:
      bits_per_pixel = 0x18;
      break;

    case 10:

    case 2:
      bits_per_pixel = 0x10;
      break;

    case 27:

    case 19:
      bits_per_pixel = 8;
      texture_handle = 0x2000;
      break;

    case 36:

    case 44:

    case 20:
      bits_per_pixel = 4;
      texture_handle = 0x4000;
      break;

    default:
      bits_per_pixel = 0;
      break;

  }

  palette_present = *((u8 *) (arg0 + 0x10));
  if (palette_present != 0)
  {
    palette_format = 0xFFFFFFFFu;
    palette_format = (*((u8 *) (arg0 + 0x11))) & (((0xFFFF & 0xFFFFFFFFu) & palette_format) & 0xFFFFFFFFu);
    switch (palette_format)
    {
      case 0:
        source_addr = 0x20;
        break;

      case 2:

      case 10:
        source_addr = 0x10;
        break;

      default:
        source_addr = 0;
        break;

    }

  }
  data_ptr = arg0 + 0x40;
  texel_scale = 1 << bits_per_pixel;
  source_addr = (s32) (data_ptr + ((source_addr * (palette_present * texel_scale)) >> 3));
  width = *((u16 *) (arg0 + 0x12));
  height = *((u16 *) (arg0 + 0x14));
  resource_value = texture_handle | 0x504;
  texture_handle = func_003ec590(width, height, bits_per_pixel, resource_value);
  if (texture_handle == 0)
  {
    func_0046d730(D_00712688, 0x48D);
  }
  texture_buffer = func_003ec6a0(texture_handle, 0, 1);
  copy_mode = arg1;
  if (texture_buffer == 0)
  {
    func_0046d730(D_00712688, 0x48F);
  }
  switch (bits_per_pixel)
  {
    case 32:

    case 24:
      if (arg1 != 0)
    {
      func_00463ea0(texture_buffer, (u32) source_addr, (((*((u16 *) (arg0 + 0x12))) & 0xFFFFFFFFu) * (*((u16 *) (arg0 + 0x14)))) * 4);
    }
    else
    {
      func_0043f810((u8 *) texture_buffer, (void *) source_addr, ((*((u16 *) (arg0 + 0x12))) * (*((u16 *) (arg0 + 0x14)))) * 4);
    }
      break;

    case 16:
      if (copy_mode)
    {
      func_00463ea0(texture_buffer, (u32) source_addr, ((*((u16 *) (arg0 + 0x12))) * (*((u16 *) (arg0 + 0x14)))) * 2);
    }
    else
    {
      func_0043f810((u8 *) texture_buffer, (void *) source_addr, ((*((u16 *) (arg0 + 0x12))) * (*((u16 *) (arg0 + 0x14)))) * 2);
    }
      break;

    case 8:
      if (arg1 != 0)
    {
      func_00463ea0(texture_buffer, (u32) source_addr, (*((u16 *) (arg0 + 0x12))) * (*((u16 *) (arg0 + 0x14))));
    }
    else
    {
      func_0043f810((u8 *) texture_buffer, (void *) source_addr, (*((u16 *) (arg0 + 0x12))) * (*((u16 *) (arg0 + 0x14))));
    }
      break;

    case 4:
      if (arg1 != 0)
    {
      func_00463ea0(texture_buffer, (u32) source_addr, ((*((u16 *) (arg0 + 0x12))) >> 1) * (*((u16 *) (arg0 + 0x14))));
    }
    else
    {
      func_0043f810((u8 *) texture_buffer, (void *) source_addr, ((*((u16 *) (arg0 + 0x12))) >> 1) * (*((u16 *) (arg0 + 0x14))));
    }
      break;

  }

  func_003ec2a0(texture_handle);
  if (*((u8 *) (arg0 + 0x10)))
  {
    resource_value = func_003ec3d0(texture_handle, 1);
    if (resource_value == 0)
    {
      func_0046d730(D_00712688, 0x4C2);
    }
    if (arg1 != 0)
    {
      palette_handle_ptr = &resource_value;
      func_00463ea0(*palette_handle_ptr, (u32) data_ptr, texel_scale * 4);
    }
    else
    {
      func_0043f810((u8 *) resource_value, data_ptr, texel_scale * 4);
    }
    func_003ec2e0(texture_handle);
  }
  return texture_handle;
}

