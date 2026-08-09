.section .text
.set noat
.set noreorder
glabel func_0050bdc0
    /* 40BDC0 0050BDC0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40BDC4 0050BDC4 0000BFFF */  sd         $31, 0x0($29)
    /* 40BDC8 0050BDC8 D08B140C */  jal        func_00522f40
    /* 40BDCC 0050BDCC 3C00848C */   lw        $4, 0x3C($4)
    /* 40BDD0 0050BDD0 07004010 */  beqz       $2, .L0050BDF0
    /* 40BDD4 0050BDD4 CDFE0424 */   addiu     $4, $0, -0x133
    /* 40BDD8 0050BDD8 3C2E140C */  jal        func_0050b8f0
    /* 40BDDC 0050BDDC 00000000 */   nop
    /* 40BDE0 0050BDE0 7600043C */  lui        $4, %hi(D_0075ECD8)
    /* 40BDE4 0050BDE4 8844140C */  jal        func_00511220
    /* 40BDE8 0050BDE8 D8EC8424 */   addiu     $4, $4, %lo(D_0075ECD8)
    /* 40BDEC 0050BDEC CDFE0224 */  addiu      $2, $0, -0x133
  .L0050BDF0:
    /* 40BDF0 0050BDF0 0000BFDF */  ld         $31, 0x0($29)
    /* 40BDF4 0050BDF4 0800E003 */  jr         $31
    /* 40BDF8 0050BDF8 1000BD27 */   addiu     $29, $29, 0x10
    /* 40BDFC 0050BDFC 00000000 */  nop
.size func_0050bdc0, 0x40
