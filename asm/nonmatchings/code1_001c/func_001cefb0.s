.section .text
.set noat
.set noreorder
glabel func_001cefb0
    /* CEFB0 001CEFB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* CEFB4 001CEFB4 0000BFFF */  sd         $31, 0x0($29)
    /* CEFB8 001CEFB8 20C1023C */  lui        $2, (0xC1200000 >> 16)
    /* CEFBC 001CEFBC 00608244 */  mtc1       $2, $f12
    /* CEFC0 001CEFC0 003E023C */  lui        $2, (0x3E000000 >> 16)
    /* CEFC4 001CEFC4 00688244 */  mtc1       $2, $f13
    /* CEFC8 001CEFC8 9C808EC7 */  lwc1       $f14, -0x7F64($28)
    /* CEFCC 001CEFCC 8839070C */  jal        func_001ce620
    /* CEFD0 001CEFD0 00000000 */   nop
    /* CEFD4 001CEFD4 0000BFDF */  ld         $31, 0x0($29)
    /* CEFD8 001CEFD8 1000BD27 */  addiu      $29, $29, 0x10
    /* CEFDC 001CEFDC 0800E003 */  jr         $31
    /* CEFE0 001CEFE0 00000000 */   nop
    /* CEFE4 001CEFE4 00000000 */  nop
    /* CEFE8 001CEFE8 00000000 */  nop
    /* CEFEC 001CEFEC 00000000 */  nop
.size func_001cefb0, 0x40
