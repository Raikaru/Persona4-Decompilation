.section .text
.set noat
.set noreorder
glabel func_004be248
    /* 3BE248 004BE248 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BE24C 004BE24C 2D300000 */  daddu      $6, $0, $0
    /* 3BE250 004BE250 0000BFFF */  sd         $31, 0x0($29)
    /* 3BE254 004BE254 0400848C */  lw         $4, 0x4($4)
    /* 3BE258 004BE258 0000BFDF */  ld         $31, 0x0($29)
    /* 3BE25C 004BE25C CE7A1308 */  j          func_004deb38
    /* 3BE260 004BE260 1000BD27 */   addiu     $29, $29, 0x10
    /* 3BE264 004BE264 00000000 */  nop
.size func_004be248, 0x20
