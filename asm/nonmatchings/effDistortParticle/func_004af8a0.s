.section .text
.set noat
.set noreorder
glabel func_004af8a0
    /* 3AF8A0 004AF8A0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3AF8A4 004AF8A4 1000BFFF */  sd         $31, 0x10($29)
    /* 3AF8A8 004AF8A8 0000B07F */  sq         $16, 0x0($29)
    /* 3AF8AC 004AF8AC 2D808000 */  daddu      $16, $4, $0
    /* 3AF8B0 004AF8B0 6000848C */  lw         $4, 0x60($4)
    /* 3AF8B4 004AF8B4 03008010 */  beqz       $4, .L004AF8C4
    /* 3AF8B8 004AF8B8 00000000 */   nop
    /* 3AF8BC 004AF8BC E8BC0F0C */  jal        func_003ef3a0
    /* 3AF8C0 004AF8C0 00000000 */   nop
  .L004AF8C4:
    /* 3AF8C4 004AF8C4 5C00048E */  lw         $4, 0x5C($16)
    /* 3AF8C8 004AF8C8 03008010 */  beqz       $4, .L004AF8D8
    /* 3AF8CC 004AF8CC 00000000 */   nop
    /* 3AF8D0 004AF8D0 344B120C */  jal        func_00492cd0
    /* 3AF8D4 004AF8D4 00000000 */   nop
  .L004AF8D8:
    /* 3AF8D8 004AF8D8 6800048E */  lw         $4, 0x68($16)
    /* 3AF8DC 004AF8DC 05008010 */  beqz       $4, .L004AF8F4
    /* 3AF8E0 004AF8E0 00000000 */   nop
    /* 3AF8E4 004AF8E4 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 3AF8E8 004AF8E8 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 3AF8EC 004AF8EC 09F84000 */  jalr       $2
    /* 3AF8F0 004AF8F0 00000000 */   nop
  .L004AF8F4:
    /* 3AF8F4 004AF8F4 2D200002 */  daddu      $4, $16, $0
    /* 3AF8F8 004AF8F8 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 3AF8FC 004AF8FC EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 3AF900 004AF900 09F84000 */  jalr       $2
    /* 3AF904 004AF904 00000000 */   nop
    /* 3AF908 004AF908 1000BFDF */  ld         $31, 0x10($29)
    /* 3AF90C 004AF90C 0000B07B */  lq         $16, 0x0($29)
    /* 3AF910 004AF910 2000BD27 */  addiu      $29, $29, 0x20
    /* 3AF914 004AF914 0800E003 */  jr         $31
    /* 3AF918 004AF918 00000000 */   nop
    /* 3AF91C 004AF91C 00000000 */  nop
.size func_004af8a0, 0x80
