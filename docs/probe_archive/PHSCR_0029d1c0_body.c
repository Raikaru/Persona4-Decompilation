/* object 152B / window 176B / normalized_diff 50; artifact condition was not accepted by mwccps2, so this archive records the parse-safe replay candidate. */
void func_0029d1c0(void *arg0, void *arg1)
{
  u8 *node;
  u8 *new_var;
  u8 **new_var3;
  void *new_var2;
  if (arg0 == ((void *) 0))
  {
    func_0046d730(D_0063E3D0, 0x6A);
  }
  new_var2 = arg1;
  if (new_var2 == (node = (void *) 0))
  {
    if (1)
    {
    }
    func_0046d730(D_0063E3D0, 0x6B);
  }
  node = ((u8 *) arg1) - 8;
  if (1)
  {
    new_var = (*((u8 **) (node + 4)) = *(new_var3 = (u8 **) (((u8 *) arg0) + 0xC)));
    if (1)
    {
      *((u8 **) (((u8 *) arg0) + 0xC)) = node;
      *((s32 *) (((u8 *) arg0) + 8)) = (*((s32 *) (((u8 *) arg0) + 8))) - 1;
      func_0043f9c8(new_var2, 0, *((s32 *) arg0));
    }
  }
 if (1) { }
}
