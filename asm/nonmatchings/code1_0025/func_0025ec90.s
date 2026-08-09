.section .text
.set noat
.set noreorder
glabel func_0025ec90
    /* 15EC90 0025EC90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 15EC94 0025EC94 0000BFFF */  sd         $31, 0x0($29)
    /* 15EC98 0025EC98 2D582001 */  daddu      $11, $9, $0
    /* 15EC9C 0025EC9C 00788044 */  mtc1       $0, $f15
    /* 15ECA0 0025ECA0 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 15ECA4 0025ECA4 00808244 */  mtc1       $2, $f16
    /* 15ECA8 0025ECA8 2D480000 */  daddu      $9, $0, $0
    /* 15ECAC 0025ECAC 2D500000 */  daddu      $10, $0, $0
    /* 15ECB0 0025ECB0 46840046 */  mov.s      $f17, $f16
    /* 15ECB4 0025ECB4 347B090C */  jal        func_0025ecd0
    /* 15ECB8 0025ECB8 00000000 */   nop
    /* 15ECBC 0025ECBC 0000BFDF */  ld         $31, 0x0($29)
    /* 15ECC0 0025ECC0 1000BD27 */  addiu      $29, $29, 0x10
    /* 15ECC4 0025ECC4 0800E003 */  jr         $31
    /* 15ECC8 0025ECC8 00000000 */   nop
    /* 15ECCC 0025ECCC 00000000 */  nop
.size func_0025ec90, 0x40
