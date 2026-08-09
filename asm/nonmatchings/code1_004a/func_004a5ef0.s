.section .text
.set noat
.set noreorder
glabel func_004a5ef0
    /* 3A5EF0 004A5EF0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3A5EF4 004A5EF4 2000BFFF */  sd         $31, 0x20($29)
    /* 3A5EF8 004A5EF8 1000B17F */  sq         $17, 0x10($29)
    /* 3A5EFC 004A5EFC 0000B07F */  sq         $16, 0x0($29)
    /* 3A5F00 004A5F00 2D888000 */  daddu      $17, $4, $0
    /* 3A5F04 004A5F04 2D80A000 */  daddu      $16, $5, $0
    /* 3A5F08 004A5F08 D000A38C */  lw         $3, 0xD0($5)
    /* 3A5F0C 004A5F0C 0C006010 */  beqz       $3, .L004A5F40
    /* 3A5F10 004A5F10 00000000 */   nop
    /* 3A5F14 004A5F14 D000248E */  lw         $4, 0xD0($17)
    /* 3A5F18 004A5F18 03008010 */  beqz       $4, .L004A5F28
    /* 3A5F1C 004A5F1C 00000000 */   nop
    /* 3A5F20 004A5F20 B807120C */  jal        func_00481ee0
    /* 3A5F24 004A5F24 00000000 */   nop
  .L004A5F28:
    /* 3A5F28 004A5F28 D000048E */  lw         $4, 0xD0($16)
    /* 3A5F2C 004A5F2C 8C07120C */  jal        func_00481e30
    /* 3A5F30 004A5F30 00000000 */   nop
    /* 3A5F34 004A5F34 D00022AE */  sw         $2, 0xD0($17)
    /* 3A5F38 004A5F38 0D000010 */  b          .L004A5F70
    /* 3A5F3C 004A5F3C 00000000 */   nop
  .L004A5F40:
    /* 3A5F40 004A5F40 CC00038E */  lw         $3, 0xCC($16)
    /* 3A5F44 004A5F44 0A006010 */  beqz       $3, .L004A5F70
    /* 3A5F48 004A5F48 00000000 */   nop
    /* 3A5F4C 004A5F4C CC00248E */  lw         $4, 0xCC($17)
    /* 3A5F50 004A5F50 03008010 */  beqz       $4, .L004A5F60
    /* 3A5F54 004A5F54 00000000 */   nop
    /* 3A5F58 004A5F58 700A120C */  jal        func_004829c0
    /* 3A5F5C 004A5F5C 00000000 */   nop
  .L004A5F60:
    /* 3A5F60 004A5F60 CC00048E */  lw         $4, 0xCC($16)
    /* 3A5F64 004A5F64 9C0A120C */  jal        func_00482a70
    /* 3A5F68 004A5F68 00000000 */   nop
    /* 3A5F6C 004A5F6C CC0022AE */  sw         $2, 0xCC($17)
  .L004A5F70:
    /* 3A5F70 004A5F70 2000BFDF */  ld         $31, 0x20($29)
    /* 3A5F74 004A5F74 1000B17B */  lq         $17, 0x10($29)
    /* 3A5F78 004A5F78 0000B07B */  lq         $16, 0x0($29)
    /* 3A5F7C 004A5F7C 3000BD27 */  addiu      $29, $29, 0x30
    /* 3A5F80 004A5F80 0800E003 */  jr         $31
    /* 3A5F84 004A5F84 00000000 */   nop
    /* 3A5F88 004A5F88 00000000 */  nop
    /* 3A5F8C 004A5F8C 00000000 */  nop
.size func_004a5ef0, 0xa0
