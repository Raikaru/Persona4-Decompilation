.section .text
.set noat
.set noreorder
glabel func_0033bdc0
    /* 23BDC0 0033BDC0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 23BDC4 0033BDC4 2000BFFF */  sd         $31, 0x20($29)
    /* 23BDC8 0033BDC8 1000B17F */  sq         $17, 0x10($29)
    /* 23BDCC 0033BDCC 0000B07F */  sq         $16, 0x0($29)
    /* 23BDD0 0033BDD0 2D888000 */  daddu      $17, $4, $0
    /* 23BDD4 0033BDD4 3800908C */  lw         $16, 0x38($4)
    /* 23BDD8 0033BDD8 688A0B0C */  jal        func_002e29a0
    /* 23BDDC 0033BDDC 00000000 */   nop
    /* 23BDE0 0033BDE0 2804048E */  lw         $4, 0x428($16)
    /* 23BDE4 0033BDE4 03008010 */  beqz       $4, .L0033BDF4
    /* 23BDE8 0033BDE8 00000000 */   nop
    /* 23BDEC 0033BDEC F452110C */  jal        func_00454bd0
    /* 23BDF0 0033BDF0 00000000 */   nop
  .L0033BDF4:
    /* 23BDF4 0033BDF4 0C00048E */  lw         $4, 0xC($16)
    /* 23BDF8 0033BDF8 04008010 */  beqz       $4, .L0033BE0C
    /* 23BDFC 0033BDFC 00000000 */   nop
    /* 23BE00 0033BE00 34AC110C */  jal        func_0046b0d0
    /* 23BE04 0033BE04 00000000 */   nop
    /* 23BE08 0033BE08 0C0000AE */  sw         $0, 0xC($16)
  .L0033BE0C:
    /* 23BE0C 0033BE0C 3800248E */  lw         $4, 0x38($17)
    /* 23BE10 0033BE10 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 23BE14 0033BE14 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 23BE18 0033BE18 09F84000 */  jalr       $2
    /* 23BE1C 0033BE1C 00000000 */   nop
    /* 23BE20 0033BE20 2000BFDF */  ld         $31, 0x20($29)
    /* 23BE24 0033BE24 1000B17B */  lq         $17, 0x10($29)
    /* 23BE28 0033BE28 0000B07B */  lq         $16, 0x0($29)
    /* 23BE2C 0033BE2C 3000BD27 */  addiu      $29, $29, 0x30
    /* 23BE30 0033BE30 0800E003 */  jr         $31
    /* 23BE34 0033BE34 00000000 */   nop
    /* 23BE38 0033BE38 00000000 */  nop
    /* 23BE3C 0033BE3C 00000000 */  nop
.size func_0033bdc0, 0x80
