/* permuter best: score 28 from base 45 (seed 4, 2648 compiles). NOT a match; raw permuter output, minimize with tools/permute_min.py before use. */
u8 *func_001dea90(u8 *p, u16 index)
{
  int new_var24;
  u16 new_var6;
  int new_var;
  int new_var22;
  u8 *new_var5;
  int new_var12;
  u32 new_var16;
  u8 *base;
  u32 *new_var17;
  int new_var7;
  u8 *new_var8;
  extern u32 func_00231d70();
  u8 *new_var25;
  int new_var23;
  int new_var11;
  u8 *node;
  int new_var21;
  u8 *result;
  u8 *new_var18;
  u8 *new_var15;
  u32 i;
  int new_var10;
  u32 sum;
  unsigned long long new_var26;
  u16 new_var4;
  u8 *new_var27;
  int new_var14;
  int new_var3;
  int new_var13;
  int new_var9;
  int new_var2;
  int new_var19;
  long long random;
  int new_var20;
  u32 weight;
  new_var5 = 0x30 + p;
  new_var2 = (weight = (new_var6 = *((u16 *) ((*((u32 *) new_var5)) + 0xA4)))) & 0xFFFFFFFFFFFFFFFF;
  new_var9 = 8;
  new_var = 164 * ((((((((((((weight ^ 0) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu);
  base = (node = iGpffffb3d0 + new_var);
  new_var24 = 8 * 0;
  new_var15 = base;
  new_var21 = new_var24;
  random = new_var14;
  if (i != 0.0f)
  {
    i = random;
    if (1)
    {
 do { } while (0);
    }
  }
  new_var6 = new_var21;
  i = new_var6;
  sum = new_var6;
 new_var4 = index; do { } while (new_var21);
  new_var26 = new_var7 != new_var6;
  if (new_var26 & 0xFFFFFFFFFFFFFFFFu)
  {
    new_var14 = (new_var11 = (new_var7 = 0xffff));
    node += (new_var6, (new_var4 & new_var14) * 40);
    new_var12 = new_var6;
  }
  else
  {
    new_var11 = (new_var7 = 0xffff);
    node += (new_var4 & new_var11) * 40;
    new_var12 = new_var6;
  }
  while (5 > ((u16) i))
  {
    new_var27 = (u8 *) (((((new_var6, i & new_var7)) * new_var9) + node) + 0x2c);
    new_var23 = (new_var13 = 0xFFu);
    sum = (sum + (*new_var27)) & new_var7;
    new_var6 = 1;
 if (new_var6) { if (new_var12) { if (1) { do { } while (0); } }
      i = (i + (new_var6 & new_var23)) & new_var7;
    }
  }

  new_var24 = new_var12;
  new_var10 = (i + new_var6) & new_var7;
  new_var11 = new_var3;
  new_var18 = new_var15;
  new_var22 = (sum & new_var7) != ((new_var11 & new_var10) * new_var24);
  if (new_var22)
  {
    goto choose;
    if (new_var9)
    {
    }
    new_var7 = 0xffff;
  }
  new_var25 = (u8 *) (&iGpffffa2a8);
  result = new_var25;
  goto ret;
  choose:
  random = func_00231d70((u32) new_var18) & new_var7;

  sum = 0;
  new_var14 = new_var12;
  i = new_var14;
  new_var3 = (new_var2 = new_var7);
  new_var16 = i;
  while (((u16) i) < 5)
  {
    new_var19 = 0x2c;
    weight = *((node + ((i & new_var3) * new_var9)) + new_var19);
    new_var10 = i;
    new_var10 = (new_var10 & new_var2) * 8;
    sum = (sum + weight) & (new_var6 = new_var2);
    if (random > sum)
    {
      goto advance;
    }
    new_var6 = 0xFFFF;
    new_var13 = !weight;
    new_var6 = new_var13 & new_var6;
    if (((float) ((!weight) && new_var6)) && (!weight))
    {
    }
    new_var11 = 0x2c;
    new_var13 = new_var10;
    new_var20 = !weight;
    if (new_var20 && new_var20)
    {
    }
    new_var17 = &new_var16;
    new_var8 = (node + new_var13) + new_var11;
    if (*new_var17)
    {
 } if (new_var14 >= weight) { new_var13++; new_var13--;
      goto advance;
    }
    result = new_var8;
    goto ret;
    advance:
    i = (i - -1) & new_var2;

  }

  result = (*((u8 *) ((node + ((i & new_var3) * new_var9)) + new_var19))) * 0;
  ret:
  return result;

}

