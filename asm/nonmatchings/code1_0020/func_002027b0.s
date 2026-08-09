.section .text
.set noat
.set noreorder
glabel func_002027b0
    /* 1027B0 002027B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1027B4 002027B4 0000BFFF */  sd         $31, 0x0($29)
    /* 1027B8 002027B8 ACB3828F */  lw         $2, -0x4C54($28)
    /* 1027BC 002027BC D40D448C */  lw         $4, 0xDD4($2)
    /* 1027C0 002027C0 D44E080C */  jal        func_00213b50
    /* 1027C4 002027C4 00000000 */   nop
    /* 1027C8 002027C8 01000224 */  addiu      $2, $0, 0x1
    /* 1027CC 002027CC 0000BFDF */  ld         $31, 0x0($29)
    /* 1027D0 002027D0 1000BD27 */  addiu      $29, $29, 0x10
    /* 1027D4 002027D4 0800E003 */  jr         $31
    /* 1027D8 002027D8 00000000 */   nop
    /* 1027DC 002027DC 00000000 */  nop
.size func_002027b0, 0x30
