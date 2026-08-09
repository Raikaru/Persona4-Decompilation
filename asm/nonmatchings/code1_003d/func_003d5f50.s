.section .text
.set noat
.set noreorder
glabel func_003d5f50
    /* 2D5F50 003D5F50 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2D5F54 003D5F54 FFFF0224 */  addiu      $2, $0, -0x1
    /* 2D5F58 003D5F58 2000BFFF */  sd         $31, 0x20($29)
    /* 2D5F5C 003D5F5C 1000B17F */  sq         $17, 0x10($29)
    /* 2D5F60 003D5F60 0000B07F */  sq         $16, 0x0($29)
    /* 2D5F64 003D5F64 2D888000 */  daddu      $17, $4, $0
    /* 2D5F68 003D5F68 0200E214 */  bne        $7, $2, .L003D5F74
    /* 2D5F6C 003D5F6C 2D80A000 */   daddu     $16, $5, $0
    /* 2D5F70 003D5F70 2000278E */  lw         $7, 0x20($17)
  .L003D5F74:
    /* 2D5F74 003D5F74 2D20C000 */  daddu      $4, $6, $0
    /* 2D5F78 003D5F78 E4550F0C */  jal        func_003d5790
    /* 2D5F7C 003D5F7C 2D28E000 */   daddu     $5, $7, $0
    /* 2D5F80 003D5F80 380051AC */  sw         $17, 0x38($2)
    /* 2D5F84 003D5F84 01000324 */  addiu      $3, $0, 0x1
    /* 2D5F88 003D5F88 340050AC */  sw         $16, 0x34($2)
    /* 2D5F8C 003D5F8C 300043AC */  sw         $3, 0x30($2)
    /* 2D5F90 003D5F90 2000BFDF */  ld         $31, 0x20($29)
    /* 2D5F94 003D5F94 1000B17B */  lq         $17, 0x10($29)
    /* 2D5F98 003D5F98 0000B07B */  lq         $16, 0x0($29)
    /* 2D5F9C 003D5F9C 0800E003 */  jr         $31
    /* 2D5FA0 003D5FA0 3000BD27 */   addiu     $29, $29, 0x30
    /* 2D5FA4 003D5FA4 00000000 */  nop
    /* 2D5FA8 003D5FA8 00000000 */  nop
    /* 2D5FAC 003D5FAC 00000000 */  nop
.size func_003d5f50, 0x60
