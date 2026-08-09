.section .text
.set noat
.set noreorder
glabel func_004b1a00
    /* 3B1A00 004B1A00 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3B1A04 004B1A04 2000BFFF */  sd         $31, 0x20($29)
    /* 3B1A08 004B1A08 1000B17F */  sq         $17, 0x10($29)
    /* 3B1A0C 004B1A0C 0000B07F */  sq         $16, 0x0($29)
    /* 3B1A10 004B1A10 2D888000 */  daddu      $17, $4, $0
    /* 3B1A14 004B1A14 2D80A000 */  daddu      $16, $5, $0
    /* 3B1A18 004B1A18 AC00A38C */  lw         $3, 0xAC($5)
    /* 3B1A1C 004B1A1C 0C006010 */  beqz       $3, .L004B1A50
    /* 3B1A20 004B1A20 00000000 */   nop
    /* 3B1A24 004B1A24 AC00248E */  lw         $4, 0xAC($17)
    /* 3B1A28 004B1A28 03008010 */  beqz       $4, .L004B1A38
    /* 3B1A2C 004B1A2C 00000000 */   nop
    /* 3B1A30 004B1A30 B807120C */  jal        func_00481ee0
    /* 3B1A34 004B1A34 00000000 */   nop
  .L004B1A38:
    /* 3B1A38 004B1A38 AC00048E */  lw         $4, 0xAC($16)
    /* 3B1A3C 004B1A3C 8C07120C */  jal        func_00481e30
    /* 3B1A40 004B1A40 00000000 */   nop
    /* 3B1A44 004B1A44 AC0022AE */  sw         $2, 0xAC($17)
    /* 3B1A48 004B1A48 0D000010 */  b          .L004B1A80
    /* 3B1A4C 004B1A4C 00000000 */   nop
  .L004B1A50:
    /* 3B1A50 004B1A50 A800038E */  lw         $3, 0xA8($16)
    /* 3B1A54 004B1A54 0A006010 */  beqz       $3, .L004B1A80
    /* 3B1A58 004B1A58 00000000 */   nop
    /* 3B1A5C 004B1A5C A800248E */  lw         $4, 0xA8($17)
    /* 3B1A60 004B1A60 03008010 */  beqz       $4, .L004B1A70
    /* 3B1A64 004B1A64 00000000 */   nop
    /* 3B1A68 004B1A68 700A120C */  jal        func_004829c0
    /* 3B1A6C 004B1A6C 00000000 */   nop
  .L004B1A70:
    /* 3B1A70 004B1A70 A800048E */  lw         $4, 0xA8($16)
    /* 3B1A74 004B1A74 9C0A120C */  jal        func_00482a70
    /* 3B1A78 004B1A78 00000000 */   nop
    /* 3B1A7C 004B1A7C A80022AE */  sw         $2, 0xA8($17)
  .L004B1A80:
    /* 3B1A80 004B1A80 2000BFDF */  ld         $31, 0x20($29)
    /* 3B1A84 004B1A84 1000B17B */  lq         $17, 0x10($29)
    /* 3B1A88 004B1A88 0000B07B */  lq         $16, 0x0($29)
    /* 3B1A8C 004B1A8C 3000BD27 */  addiu      $29, $29, 0x30
    /* 3B1A90 004B1A90 0800E003 */  jr         $31
    /* 3B1A94 004B1A94 00000000 */   nop
    /* 3B1A98 004B1A98 00000000 */  nop
    /* 3B1A9C 004B1A9C 00000000 */  nop
.size func_004b1a00, 0xa0
