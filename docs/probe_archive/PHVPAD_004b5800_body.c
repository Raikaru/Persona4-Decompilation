/* measured: AST_HIT_UNREPRODUCIBLE replay normalized_diff 245; fndiff differing words (reloc-masked) 78; object 364B/window 336B */
void func_004b5800(RuntimeWork *work)
{
  s32 i;
  RuntimeMatrix *firstMatrix;
  RuntimeMatrix *secondMatrix;
  if (func_004b6de0((RuntimeListNode *) work) == 0)
  {
 do { return; } while (0);
  }
  if (!secondMatrix)
  {
  }
  firstMatrix = func_003e0f80();
  secondMatrix = func_003e0f80();
  i = 0;
  while (i < (*((s16 *) (((u8 *) ((uintptr_t) inline_fn(work))) + 4))))
  {
    func_0047a510(*((void **) (((u8 *) ((uintptr_t) inline_fn(work))) + 0x20)), *((void **) (((u8 *) (*((void **) (((u8 *) ((uintptr_t) inline_fn(work))) + 0x18)))) + (i * 8))), firstMatrix);
    func_0047a510(*((void **) (((u8 *) ((uintptr_t) work->requestFlags)) + 0x20)), *((void **) ((((u8 *) (*((void **) (((u8 *) ((uintptr_t) work->requestFlags)) + 0x18)))) + (i * 8)) + 4)), secondMatrix);
    ((RuntimeVec3 *) ((uintptr_t) work->selection))[i * 2] = *((RuntimeVec3 *) (((u8 *) firstMatrix) + 0x30));
    ((RuntimeVec3 *) ((uintptr_t) work->selection))[(i * 2) + 1] = *((RuntimeVec3 *) (((u8 *) secondMatrix) + 0x30));
    i++;
  }

  work->flags |= 2;
  func_003e0f40(firstMatrix);
  func_003e0f40(secondMatrix);
  i = i;
}
