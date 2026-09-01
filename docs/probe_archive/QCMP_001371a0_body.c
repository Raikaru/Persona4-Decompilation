/* object_size=828; window=816; normalized_diff=291; differing_offsets_first=[28,29,30,31,32,34,35,36,38,39,40,41,44,45,47,48]; differing_word_count=95; classification=OBJECT_LARGER_THAN_WINDOW+RECONSTRUCTION_SCALE; ruled_out=retail has no movz/movn, COP1 accumulator chain, standalone MMI, framed tail-jump forwarder, or sd-saved s-register; plain (u16) float casts compile and were measured, so the prior explicit overflow-guard floor classification is rejected; candidate retains an oversized/reordered reconstruction. */
s32 func_001371a0(u8* arg0, u32 arg1) {
 extern void func_0011cee0(u8* arg0);
 extern u8 D_005E9FD0[];
 extern u8 D_005EA2E0[];
 extern u8 D_005EA5F0[];
 extern u8 D_005EA900[];
 extern u8 D_005EAC10[];
 extern u8 D_005EAF20[];
 extern u8 D_005EB230[];
 u8* data;
 s32 i;
 u8* p;
 u8* src;

 if (*(u32*)(arg0 + 0x18) == arg1) {
  return 0;
 }
 for (i = 0; i < 28; i++) {
  p = arg0 + i * 0x30;
  *(f32*)(p + 0x1054) = *(f32*)(p + 0x1064);
  *(f32*)(p + 0x1058) = *(f32*)(p + 0x1068);
  *(u16*)(p + 0x1070) = *(u16*)(p + 0x1074);
  *(u16*)(p + 0x1076) = *(u16*)(p + 0x107A);
  *(u8*)(p + 0x106C) = *(u8*)(p + 0x106E);
 }
 data = NULL;
 switch (arg1) {
 case 0:
  data = D_005E9FD0;
  *(s32*)(arg0 + 0x1C) = 0x243;
  *(s16*)(arg0 + 0x60) = 0;
  break;
 case 1:
  data = D_005EA2E0;
  break;
 case 2:
  data = D_005EA5F0;
  *(s32*)(arg0 + 0x1C) = 0xA43;
  *(s16*)(arg0 + 0x60) = 0;
  break;
 case 3:
  data = D_005EA900;
  *(s32*)(arg0 + 0x1C) = 0xFE7;
  *(s16*)(arg0 + 0x60) = 8;
  break;
 case 4:
 case 5:
  data = D_005EAC10;
  *(s32*)(arg0 + 0x1C) = 0x5A5;
  *(s16*)(arg0 + 0x60) = 8;
  break;
 case 6:
  data = D_005EAF20;
  *(s32*)(arg0 + 0x1C) = 0x48D;
  *(s16*)(arg0 + 0x60) = -1;
  func_0011cee0(*(u8**)(arg0 + 0x1CB4));
  break;
 case 7:
  data = D_005EAF20;
  *(s32*)(arg0 + 0x1C) = 9;
  break;
 case 8:
  data = D_005EB230;
  *(s32*)(arg0 + 0x1C) = 0xA13;
  *(s16*)(arg0 + 0x60) = 0xE;
  func_0011cee0(*(u8**)(arg0 + 0x1CB4));
  break;
 case 10:
  *(s32*)(arg0 + 0x1C) = 8;
  *(s16*)(arg0 + 0x60) = -1;
  break;
 case 11:
  *(s32*)(arg0 + 0x1C) = 0x5A5;
  *(s16*)(arg0 + 0x60) = 8;
  break;
 case 12:
  *(s32*)(arg0 + 0x1C) = 0x5A5;
  *(s16*)(arg0 + 0x60) = 8;
  break;
 default:
  func_0046d730(&D_005EB580[0], 0x3BA);
  break;
 }
 if (data != NULL) {
  for (i = 0; i < 28; i++) {
   src = data + i * 0x1C;
   p = arg0 + i * 0x30;
   *(f32*)(p + 0x105C) = *(f32*)(src + 0);
   *(f32*)(p + 0x1060) = *(f32*)(src + 4);
   *(u16*)(p + 0x1072) = (u16)*(f32*)(src + 8);
   *(u16*)(p + 0x1078) = (u16)*(f32*)(src + 0xC);
   *(u8*)(p + 0x106D) = *(u8*)(src + 0x10);
   *(s32*)(p + 0x107C) = *(s32*)(src + 0x14);
   *(s32*)(p + 0x1080) = *(s32*)(src + 0x18);
  }
  *(s16*)(arg0 + 0x20) = 0;
  *(u32*)(arg0 + 0x18) = arg1;
 }
 return 1;
}
