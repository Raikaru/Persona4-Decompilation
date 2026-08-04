.section .text
.set noat
.set noreorder
glabel func_003c3f20
    /* 2C3F20 003C3F20 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2C3F24 003C3F24 04000624 */  addiu      $6, $0, 0x4
    /* 2C3F28 003C3F28 2000BFFF */  sd         $31, 0x20($29)
    /* 2C3F2C 003C3F2C 1000B17F */  sq         $17, 0x10($29)
    /* 2C3F30 003C3F30 0000B07F */  sq         $16, 0x0($29)
    /* 2C3F34 003C3F34 2D888000 */  daddu      $17, $4, $0
    /* 2C3F38 003C3F38 2D80A000 */  daddu      $16, $5, $0
    /* 2C3F3C 003C3F3C D87C0F0C */  jal        func_003df360
    /* 2C3F40 003C3F40 DCB68527 */   addiu     $5, $28, -0x4924
    /* 2C3F44 003C3F44 06004010 */  beqz       $2, .L003C3F60
    /* 2C3F48 003C3F48 00000000 */   nop
    /* 2C3F4C 003C3F4C 08000224 */  addiu      $2, $0, 0x8
    /* 2C3F50 003C3F50 05000212 */  beq        $16, $2, .L003C3F68
    /* 2C3F54 003C3F54 00000000 */   nop
  .L003C3F58:
    /* 2C3F58 003C3F58 0A000010 */  b          .L003C3F84
    /* 2C3F5C 003C3F5C 2D102002 */   daddu     $2, $17, $0
  .L003C3F60:
    /* 2C3F60 003C3F60 08000010 */  b          .L003C3F84
    /* 2C3F64 003C3F64 2D100000 */   daddu     $2, $0, $0
  .L003C3F68:
    /* 2C3F68 003C3F68 2D202002 */  daddu      $4, $17, $0
    /* 2C3F6C 003C3F6C D8B68527 */  addiu      $5, $28, -0x4928
    /* 2C3F70 003C3F70 D87C0F0C */  jal        func_003df360
    /* 2C3F74 003C3F74 04000624 */   addiu     $6, $0, 0x4
    /* 2C3F78 003C3F78 F7FF4014 */  bnez       $2, .L003C3F58
    /* 2C3F7C 003C3F7C 00000000 */   nop
    /* 2C3F80 003C3F80 2D100000 */  daddu      $2, $0, $0
  .L003C3F84:
    /* 2C3F84 003C3F84 2000BFDF */  ld         $31, 0x20($29)
    /* 2C3F88 003C3F88 1000B17B */  lq         $17, 0x10($29)
    /* 2C3F8C 003C3F8C 0000B07B */  lq         $16, 0x0($29)
    /* 2C3F90 003C3F90 0800E003 */  jr         $31
    /* 2C3F94 003C3F94 3000BD27 */   addiu     $29, $29, 0x30
    /* 2C3F98 003C3F98 00000000 */  nop
    /* 2C3F9C 003C3F9C 00000000 */  nop
.size func_003c3f20, 0x80
