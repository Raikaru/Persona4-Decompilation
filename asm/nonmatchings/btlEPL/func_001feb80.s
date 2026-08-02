.section .text
.set noat
.set noreorder
glabel func_001feb80
    /* FEB80 001FEB80 F0FFBD27 */  addiu      $29, $29, -0x10
    /* FEB84 001FEB84 0000BFFF */  sd         $31, 0x0($29)
    /* FEB88 001FEB88 6200043C */  lui        $4, %hi(D_00625230)
    /* FEB8C 001FEB8C 30528424 */  addiu      $4, $4, %lo(D_00625230)
    /* FEB90 001FEB90 89030524 */  addiu      $5, $0, 0x389
    /* FEB94 001FEB94 A43A110C */  jal        func_0044ea90
    /* FEB98 001FEB98 00000000 */   nop
    /* FEB9C 001FEB9C 10000424 */  addiu      $4, $0, 0x10
    /* FEBA0 001FEBA0 0400053C */  lui        $5, (0x40000 >> 16)
    /* FEBA4 001FEBA4 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* FEBA8 001FEBA8 E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* FEBAC 001FEBAC 09F84000 */  jalr       $2
    /* FEBB0 001FEBB0 00000000 */   nop
    /* FEBB4 001FEBB4 0000BFDF */  ld         $31, 0x0($29)
    /* FEBB8 001FEBB8 1000BD27 */  addiu      $29, $29, 0x10
    /* FEBBC 001FEBBC 0800E003 */  jr         $31
    /* FEBC0 001FEBC0 00000000 */   nop
    /* FEBC4 001FEBC4 00000000 */  nop
    /* FEBC8 001FEBC8 00000000 */  nop
    /* FEBCC 001FEBCC 00000000 */  nop
.size func_001feb80, 0x50
