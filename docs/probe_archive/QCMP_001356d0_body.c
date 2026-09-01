/* object_size=1288; window=1344; normalized_diff=860; differing_offsets_first=[85,88,96,97,100,101,102,103,104,105,106,107,108,109,110,111]; differing_word_count=860; classification=RECONSTRUCTION_SCALE+LARGE_RESIDUAL; ruled_out=retail has no movz/movn, standalone MMI, framed tail-jump forwarder, or sd-saved s-register; plain (u16) float casts compile and were measured, so the prior explicit overflow-guard floor classification is rejected; candidate remains substantially different despite corrected callee declarations and s16 loop counters. */
void func_001356d0(u8* arg0) {
 extern void func_00135c10(u8* arg0);
 extern s64 func_00353c10(s16* arg0);
 extern void func_0043f9c8(void* dst, s32 value, s32 size);
 extern s32 func_0046a770(u32 arg0);
 extern s32 func_0046d200(s32 arg0, s32 arg1);
 extern void func_002baac0(void* arg0);
 extern u8* func_00354a50(s32 arg0, s32 arg1);
 extern u8* func_00117780(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
 extern void func_00117580(u8* arg0, s16 arg1);
 extern s32 func_001371a0(u8* arg0, u32 arg1);
 extern u8 D_005E57F0[];
 extern u8 D_005E5830[];
 extern u8 D_005E5850[];
 extern u8 D_005E9FB0[];
 extern u8 D_005EA2E0[];
 extern u8 D_0064A790[];
 s16 i;
 s32 resource0;
 s32 resource1;
 s32 resource2;
 s32* slot;
 u8* p;
 u8* src;

 func_0043f9c8(arg0, 0, 0x1CC4);
 *(s32*)(arg0 + 4) = 0;
 *(s32*)(arg0 + 8) = 0;
 *(u8*)arg0 = 0xFF;
 *(s32*)(arg0 + 0x18) = -1;
 *(s16*)(arg0 + 0x20) = 0;
 *(s32*)(arg0 + 0x14) = 0;
 for (i = 0; i < 4; i++) {
  p = arg0 + i * 2;
  *(s16*)(p + 0x50) = 0;
  *(s16*)(p + 0x58) = 0;
 }
 for (i = 0; i < 28; i++) {
  src = D_005EA2E0 + i * 0x1C;
  p = arg0 + i * 0x30;
  *(f32*)(p + 0x1064) = *(f32*)(src + 0);
  *(f32*)(p + 0x1068) = *(f32*)(src + 4);
  *(u16*)(p + 0x1074) = (u16)*(f32*)(src + 8);
  *(u16*)(p + 0x107A) = (u16)*(f32*)(src + 0xC);
  *(u8*)(p + 0x106E) = *(u8*)(src + 0x10);
 }
 for (i = 0; i < 120; i++) {
  p = arg0 + i * 0x14;
  *(s32*)(p + 0x68) = i % 10;
  *(s32*)(p + 0x70) = 10;
  *(s32*)(p + 0x6C) = i / 10;
  *(s32*)(p + 0x74) = 12;
 }
 for (i = 0; i < 84; i++) {
  p = arg0 + i * 0x14;
  *(s32*)(p + 0x9C8) = i % 7;
  *(s32*)(p + 0x9D0) = 7;
  *(s32*)(p + 0x9CC) = i / 7;
  *(s32*)(p + 0x9D4) = 12;
 }
 for (i = 0; i < 36; i++) {
  p = arg0 + i * 0x30;
  *(s32*)(p + 0x15A4) = 0;
  *(s32*)(p + 0x1594) = 0;
  *(s32*)(p + 0x15A0) = (s32)0xC2C80000;
  *(s32*)(p + 0x1598) = (s32)0xC2C80000;
  *(s8*)(p + 0x15AD) = 0x7F;
  *(s8*)(p + 0x15AC) = 0x7F;
  *(s32*)(p + 0x15BC) = 0;
  *(s32*)(p + 0x15C0) = 10;
 }
 *(s16*)(arg0 + 0x34) = func_00353c10((s16*)(arg0 + 0x24));
 resource0 = func_0046a770((u32)D_005E5830);
 if (resource0 == 0) {
  func_0046d730(&D_005EB580[0], 0x199);
 }
 resource1 = func_0046a770((u32)D_005E5850);
 if (resource1 == 0) {
  func_0046d730(&D_005EB580[0], 0x19B);
 }
 resource2 = func_0046a770((u32)D_005E57F0);
 *(s32*)(arg0 + 0x1CB0) = resource2;
 if (resource2 == 0) {
  func_0046d730(&D_005EB580[0], 0x19D);
 }
 for (i = 0; i < 23; i++) {
  slot = (s32*)(arg0 + i * 4 + 0x1C54);
  if (i < 6) {
   *slot = func_0046d200(resource0, *(u8*)(D_005E9FB0 + i));
  } else if (i < 9) {
   *slot = func_0046d200(resource2, *(u8*)(D_005E9FB0 + i));
  } else {
   *slot = func_0046d200(resource1, *(u8*)(D_005E9FB0 + i));
  }
  if (*slot == 0) {
   func_0046d730(&D_005EB580[0], 0x1AB);
  }
 }
 func_002baac0(D_0064A790);
 func_00135c10(arg0);
 *(s32*)(arg0 + 0x1CB8) = (s32)func_00354a50(0, 1);
 *(s32*)(arg0 + 0x1CB4) = (s32)func_00117780(0, 0xC7, 0, 8, 3);
 func_00117580(*(u8**)(arg0 + 0x1CB4), 0xB0);
 func_001371a0(arg0, 0);
}
