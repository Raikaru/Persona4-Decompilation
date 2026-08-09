.section .text
.set noat
.set noreorder
glabel func_003a2d90
    /* 2A2D90 003A2D90 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2A2D94 003A2D94 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2A2D98 003A2D98 2000BFFF */  sd         $31, 0x20($29)
    /* 2A2D9C 003A2D9C E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2A2DA0 003A2DA0 1000B17F */  sq         $17, 0x10($29)
    /* 2A2DA4 003A2DA4 0000B07F */  sq         $16, 0x0($29)
    /* 2A2DA8 003A2DA8 14B6838F */  lw         $3, -0x49EC($28)
    /* 2A2DAC 003A2DAC 21104300 */  addu       $2, $2, $3
    /* 2A2DB0 003A2DB0 0000518C */  lw         $17, 0x0($2)
    /* 2A2DB4 003A2DB4 23002012 */  beqz       $17, .L003A2E44
    /* 2A2DB8 003A2DB8 2D808000 */   daddu     $16, $4, $0
    /* 2A2DBC 003A2DBC 0800248E */  lw         $4, 0x8($17)
    /* 2A2DC0 003A2DC0 03008010 */  beqz       $4, .L003A2DD0
    /* 2A2DC4 003A2DC4 00000000 */   nop
    /* 2A2DC8 003A2DC8 9C45100C */  jal        func_00411670
    /* 2A2DCC 003A2DCC 00000000 */   nop
  .L003A2DD0:
    /* 2A2DD0 003A2DD0 0400248E */  lw         $4, 0x4($17)
    /* 2A2DD4 003A2DD4 03008010 */  beqz       $4, .L003A2DE4
    /* 2A2DD8 003A2DD8 00000000 */   nop
    /* 2A2DDC 003A2DDC 9C45100C */  jal        func_00411670
    /* 2A2DE0 003A2DE0 00000000 */   nop
  .L003A2DE4:
    /* 2A2DE4 003A2DE4 1000248E */  lw         $4, 0x10($17)
    /* 2A2DE8 003A2DE8 03008010 */  beqz       $4, .L003A2DF8
    /* 2A2DEC 003A2DEC 00000000 */   nop
    /* 2A2DF0 003A2DF0 9C45100C */  jal        func_00411670
    /* 2A2DF4 003A2DF4 00000000 */   nop
  .L003A2DF8:
    /* 2A2DF8 003A2DF8 0C00248E */  lw         $4, 0xC($17)
    /* 2A2DFC 003A2DFC 03008010 */  beqz       $4, .L003A2E0C
    /* 2A2E00 003A2E00 00000000 */   nop
    /* 2A2E04 003A2E04 9C45100C */  jal        func_00411670
    /* 2A2E08 003A2E08 00000000 */   nop
  .L003A2E0C:
    /* 2A2E0C 003A2E0C 1400248E */  lw         $4, 0x14($17)
    /* 2A2E10 003A2E10 03008010 */  beqz       $4, .L003A2E20
    /* 2A2E14 003A2E14 00000000 */   nop
    /* 2A2E18 003A2E18 9C45100C */  jal        func_00411670
    /* 2A2E1C 003A2E1C 00000000 */   nop
  .L003A2E20:
    /* 2A2E20 003A2E20 0000248E */  lw         $4, 0x0($17)
    /* 2A2E24 003A2E24 03008010 */  beqz       $4, .L003A2E34
    /* 2A2E28 003A2E28 00000000 */   nop
    /* 2A2E2C 003A2E2C 9C45100C */  jal        func_00411670
    /* 2A2E30 003A2E30 00000000 */   nop
  .L003A2E34:
    /* 2A2E34 003A2E34 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2A2E38 003A2E38 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2A2E3C 003A2E3C 09F84000 */  jalr       $2
    /* 2A2E40 003A2E40 2D202002 */   daddu     $4, $17, $0
  .L003A2E44:
    /* 2A2E44 003A2E44 2D100002 */  daddu      $2, $16, $0
    /* 2A2E48 003A2E48 2000BFDF */  ld         $31, 0x20($29)
    /* 2A2E4C 003A2E4C 1000B17B */  lq         $17, 0x10($29)
    /* 2A2E50 003A2E50 0000B07B */  lq         $16, 0x0($29)
    /* 2A2E54 003A2E54 0800E003 */  jr         $31
    /* 2A2E58 003A2E58 3000BD27 */   addiu     $29, $29, 0x30
    /* 2A2E5C 003A2E5C 00000000 */  nop
.size func_003a2d90, 0xd0
