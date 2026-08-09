.section .text
.set noat
.set noreorder
glabel func_004c8a90
    /* 3C8A90 004C8A90 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3C8A94 004C8A94 2D280000 */  daddu      $5, $0, $0
    /* 3C8A98 004C8A98 0800B1FF */  sd         $17, 0x8($29)
    /* 3C8A9C 004C8A9C 2D888000 */  daddu      $17, $4, $0
    /* 3C8AA0 004C8AA0 2D302002 */  daddu      $6, $17, $0
    /* 3C8AA4 004C8AA4 FFFF0724 */  addiu      $7, $0, -0x1
    /* 3C8AA8 004C8AA8 03000424 */  addiu      $4, $0, 0x3
    /* 3C8AAC 004C8AAC 0000B0FF */  sd         $16, 0x0($29)
    /* 3C8AB0 004C8AB0 1000BFFF */  sd         $31, 0x10($29)
    /* 3C8AB4 004C8AB4 981C130C */  jal        func_004c7260
    /* 3C8AB8 004C8AB8 FFFF0824 */   addiu     $8, $0, -0x1
    /* 3C8ABC 004C8ABC 1C002012 */  beqz       $17, .L004C8B30
    /* 3C8AC0 004C8AC0 02000324 */   addiu     $3, $0, 0x2
    /* 3C8AC4 004C8AC4 01002282 */  lb         $2, 0x1($17)
    /* 3C8AC8 004C8AC8 04004354 */  bnel       $2, $3, .L004C8ADC
    /* 3C8ACC 004C8ACC 0400308E */   lw        $16, 0x4($17)
    /* 3C8AD0 004C8AD0 3824130C */  jal        func_004c90e0
    /* 3C8AD4 004C8AD4 2D202002 */   daddu     $4, $17, $0
    /* 3C8AD8 004C8AD8 0400308E */  lw         $16, 0x4($17)
  .L004C8ADC:
    /* 3C8ADC 004C8ADC 06000012 */  beqz       $16, .L004C8AF8
    /* 3C8AE0 004C8AE0 2D200002 */   daddu     $4, $16, $0
    /* 3C8AE4 004C8AE4 000020A2 */  sb         $0, 0x0($17)
    /* 3C8AE8 004C8AE8 DC47130C */  jal        func_004d1f70
    /* 3C8AEC 004C8AEC 040020AE */   sw        $0, 0x4($17)
    /* 3C8AF0 004C8AF0 3A47130C */  jal        func_004d1ce8
    /* 3C8AF4 004C8AF4 2D200002 */   daddu     $4, $16, $0
  .L004C8AF8:
    /* 3C8AF8 004C8AF8 2D202002 */  daddu      $4, $17, $0
    /* 3C8AFC 004C8AFC 2D280000 */  daddu      $5, $0, $0
    /* 3C8B00 004C8B00 72FE100C */  jal        func_0043f9c8
    /* 3C8B04 004C8B04 44000624 */   addiu     $6, $0, 0x44
    /* 3C8B08 004C8B08 03000424 */  addiu      $4, $0, 0x3
    /* 3C8B0C 004C8B0C 2D302002 */  daddu      $6, $17, $0
    /* 3C8B10 004C8B10 0800B1DF */  ld         $17, 0x8($29)
    /* 3C8B14 004C8B14 0000B0DF */  ld         $16, 0x0($29)
    /* 3C8B18 004C8B18 01000524 */  addiu      $5, $0, 0x1
    /* 3C8B1C 004C8B1C 1000BFDF */  ld         $31, 0x10($29)
    /* 3C8B20 004C8B20 FFFF0724 */  addiu      $7, $0, -0x1
    /* 3C8B24 004C8B24 FFFF0824 */  addiu      $8, $0, -0x1
    /* 3C8B28 004C8B28 981C1308 */  j          func_004c7260
    /* 3C8B2C 004C8B2C 2000BD27 */   addiu     $29, $29, 0x20
  .L004C8B30:
    /* 3C8B30 004C8B30 0000B0DF */  ld         $16, 0x0($29)
    /* 3C8B34 004C8B34 0800B1DF */  ld         $17, 0x8($29)
    /* 3C8B38 004C8B38 1000BFDF */  ld         $31, 0x10($29)
    /* 3C8B3C 004C8B3C 0800E003 */  jr         $31
    /* 3C8B40 004C8B40 2000BD27 */   addiu     $29, $29, 0x20
    /* 3C8B44 004C8B44 00000000 */  nop
.size func_004c8a90, 0xb8
