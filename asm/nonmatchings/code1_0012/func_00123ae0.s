.section .text
.set noat
.set noreorder
glabel func_00123ae0
    /* 23AE0 00123AE0 DCB1828F */  lw         $2, -0x4E24($28)
    /* 23AE4 00123AE4 04004010 */  beqz       $2, .L00123AF8
    /* 23AE8 00123AE8 00000000 */   nop
    /* 23AEC 00123AEC 08004280 */  lb         $2, 0x8($2)
    /* 23AF0 00123AF0 02000010 */  b          .L00123AFC
    /* 23AF4 00123AF4 00000000 */   nop
  .L00123AF8:
    /* 23AF8 00123AF8 FFFF0224 */  addiu      $2, $0, -0x1
  .L00123AFC:
    /* 23AFC 00123AFC 0800E003 */  jr         $31
    /* 23B00 00123B00 00000000 */   nop
    /* 23B04 00123B04 00000000 */  nop
    /* 23B08 00123B08 00000000 */  nop
    /* 23B0C 00123B0C 00000000 */  nop
.size func_00123ae0, 0x30
