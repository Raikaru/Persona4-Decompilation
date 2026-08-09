.section .text
.set noat
.set noreorder
glabel func_003c9a80
    /* 2C9A80 003C9A80 C0FEBD27 */  addiu      $29, $29, -0x140
    /* 2C9A84 003C9A84 3000BFFF */  sd         $31, 0x30($29)
    /* 2C9A88 003C9A88 2000B27F */  sq         $18, 0x20($29)
    /* 2C9A8C 003C9A8C 1000B17F */  sq         $17, 0x10($29)
    /* 2C9A90 003C9A90 2D908000 */  daddu      $18, $4, $0
    /* 2C9A94 003C9A94 0000B07F */  sq         $16, 0x0($29)
    /* 2C9A98 003C9A98 1C00918C */  lw         $17, 0x1C($4)
    /* 2C9A9C 003C9A9C 0E002012 */  beqz       $17, .L003C9AD8
    /* 2C9AA0 003C9AA0 2D800000 */   daddu     $16, $0, $0
  .L003C9AA4:
    /* 2C9AA4 003C9AA4 0000228E */  lw         $2, 0x0($17)
    /* 2C9AA8 003C9AA8 0D004004 */  bltz       $2, .L003C9AE0
    /* 2C9AAC 003C9AAC 00000000 */   nop
    /* 2C9AB0 003C9AB0 0C00238E */  lw         $3, 0xC($17)
    /* 2C9AB4 003C9AB4 01001026 */  addiu      $16, $16, 0x1
    /* 2C9AB8 003C9AB8 80101000 */  sll        $2, $16, 2
    /* 2C9ABC 003C9ABC 21105D00 */  addu       $2, $2, $29
    /* 2C9AC0 003C9AC0 0800318E */  lw         $17, 0x8($17)
    /* 2C9AC4 003C9AC4 400043AC */  sw         $3, 0x40($2)
  .L003C9AC8:
    /* 2C9AC8 003C9AC8 F6FF0106 */  bgez       $16, .L003C9AA4
    /* 2C9ACC 003C9ACC 00000000 */   nop
    /* 2C9AD0 003C9AD0 0F000010 */  b          .L003C9B10
    /* 2C9AD4 003C9AD4 2D104002 */   daddu     $2, $18, $0
  .L003C9AD8:
    /* 2C9AD8 003C9AD8 0D000010 */  b          .L003C9B10
    /* 2C9ADC 003C9ADC 2D100000 */   daddu     $2, $0, $0
  .L003C9AE0:
    /* 2C9AE0 003C9AE0 7800248E */  lw         $4, 0x78($17)
    /* 2C9AE4 003C9AE4 04008010 */  beqz       $4, .L003C9AF8
    /* 2C9AE8 003C9AE8 00000000 */   nop
    /* 2C9AEC 003C9AEC D8150F0C */  jal        func_003c5760
    /* 2C9AF0 003C9AF0 00000000 */   nop
    /* 2C9AF4 003C9AF4 780020AE */  sw         $0, 0x78($17)
  .L003C9AF8:
    /* 2C9AF8 003C9AF8 80101000 */  sll        $2, $16, 2
    /* 2C9AFC 003C9AFC 21105D00 */  addu       $2, $2, $29
    /* 2C9B00 003C9B00 4000518C */  lw         $17, 0x40($2)
    /* 2C9B04 003C9B04 F0FF0010 */  b          .L003C9AC8
    /* 2C9B08 003C9B08 FFFF1026 */   addiu     $16, $16, -0x1
    /* 2C9B0C 003C9B0C 00000000 */  nop
  .L003C9B10:
    /* 2C9B10 003C9B10 3000BFDF */  ld         $31, 0x30($29)
    /* 2C9B14 003C9B14 2000B27B */  lq         $18, 0x20($29)
    /* 2C9B18 003C9B18 1000B17B */  lq         $17, 0x10($29)
    /* 2C9B1C 003C9B1C 0000B07B */  lq         $16, 0x0($29)
    /* 2C9B20 003C9B20 0800E003 */  jr         $31
    /* 2C9B24 003C9B24 4001BD27 */   addiu     $29, $29, 0x140
    /* 2C9B28 003C9B28 00000000 */  nop
    /* 2C9B2C 003C9B2C 00000000 */  nop
.size func_003c9a80, 0xb0
