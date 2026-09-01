/* measured: artifact replay produced object_size 456B against the 448B retail window, normalized_diff 303, and 108 differing words (reloc-masked). */
s32 func_0021de90(s32 arg0, u8 *arg1)
{
  s32 var_16;
  int new_var3;
  int new_var5;
  s32 *new_var8;
  s32 *new_var2;
  int new_var10;
  short new_var7;
  f32 temp_f2;
  f32 new_var;
  u8 *new_var6;
  int new_var4;
  s32 var_2;
  s32 temp_3;
  int new_var12;
  int new_var9;
  u8 *new_var11;
  s32 var_2_2;
  new_var7 = 4;
  new_var9 = 0;
  new_var2 = (s32 *) (arg1 + new_var7);
  var_16 = *new_var2;
  if (var_16 <= new_var9)
  {
    return new_var9;
  }
  new_var3 = ((*((u16 *) arg1)) & 8) == 0;
  if (new_var3 && (func_00106330(0x1403) != 0))
  {
    if (func_00106330(0x1428) != 0)
    {
      var_16 = (s32) (2.0f * ((f32) var_16));
    }
    else
      if (func_00106330(0x1429) != 0)
    {
 do { var_16 = 0; } while (0);
    }
  }
  temp_f2 = 1.0f / ((f32) (*((s32 *) (arg1 + 0x20))));
  new_var4 = (new_var3 = *((s32 *) ((new_var11 = arg1) + 0xC)));
  new_var12 = 0;
  new_var6 = iGpffffb414 + (new_var4 * 0x18);
  new_var8 = (s32 *) new_var6;
  if (((*new_var8) & 0x80) != 0)
  {
    var_2 = (s32) (((f32) var_16) * temp_f2);
  }
  else
  {
    new_var10 = (*((s32 *) (new_var11 + 0x38))) - arg0;
    temp_3 = new_var10;
    new_var5 = temp_3 >= ((int) 0xA);
    if (new_var5)
    {
      var_2_2 = 0x14;
    }
    else
      if (temp_3 < (-9))
    {
      if (var_2)
      {
      }
      var_2_2 = new_var12;
    }
    else
    {
      var_2_2 = temp_3 + 0xA;
    }
    var_2 = (s32) ((inline_fn(iGpffffb40c, var_2_2) * (new_var = (f32) var_16)) * temp_f2);
  }
  if (var_2 > (((0, 0x10000)) - 1))
  {
    return 0xFFFF;
  }
  if (var_2 <= 0)
  {
    var_2 = 1;
  }
  return var_2;
  if (temp_3)
  {
    if (new_var11)
    {
    }
  }
}
