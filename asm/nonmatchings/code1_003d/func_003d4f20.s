.section .text
.set noat
.set noreorder
glabel func_003d4f20
    /* 2D4F20 003D4F20 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2D4F24 003D4F24 8800083C */  lui        $8, %hi(D_00887150)
    /* 2D4F28 003D4F28 1000BFFF */  sd         $31, 0x10($29)
    /* 2D4F2C 003D4F2C 0400023C */  lui        $2, (0x4001B >> 16)
    /* 2D4F30 003D4F30 0000B07F */  sq         $16, 0x0($29)
    /* 2D4F34 003D4F34 04000624 */  addiu      $6, $0, 0x4
    /* 2D4F38 003D4F38 1CAB858F */  lw         $5, -0x54E4($28)
    /* 2D4F3C 003D4F3C 2D808000 */  daddu      $16, $4, $0
    /* 2D4F40 003D4F40 20AB878F */  lw         $7, -0x54E0($28)
    /* 2D4F44 003D4F44 18000424 */  addiu      $4, $0, 0x18
    /* 2D4F48 003D4F48 50710825 */  addiu      $8, $8, %lo(D_00887150)
    /* 2D4F4C 003D4F4C 88840F0C */  jal        func_003e1220
    /* 2D4F50 003D4F50 1B004934 */   ori       $9, $2, (0x4001B & 0xFFFF)
    /* 2D4F54 003D4F54 03004010 */  beqz       $2, .L003D4F64
    /* 2D4F58 003D4F58 38B782AF */   sw        $2, -0x48C8($28)
  .L003D4F5C:
    /* 2D4F5C 003D4F5C 03000010 */  b          .L003D4F6C
    /* 2D4F60 003D4F60 2D100002 */   daddu     $2, $16, $0
  .L003D4F64:
    /* 2D4F64 003D4F64 FDFF0010 */  b          .L003D4F5C
    /* 2D4F68 003D4F68 2D800000 */   daddu     $16, $0, $0
  .L003D4F6C:
    /* 2D4F6C 003D4F6C 1000BFDF */  ld         $31, 0x10($29)
    /* 2D4F70 003D4F70 0000B07B */  lq         $16, 0x0($29)
    /* 2D4F74 003D4F74 0800E003 */  jr         $31
    /* 2D4F78 003D4F78 2000BD27 */   addiu     $29, $29, 0x20
    /* 2D4F7C 003D4F7C 00000000 */  nop
.size func_003d4f20, 0x60
