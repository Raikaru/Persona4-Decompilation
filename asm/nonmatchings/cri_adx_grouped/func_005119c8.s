.section .text
.set noat
.set noreorder
glabel func_005119c8
    /* 4119C8 005119C8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4119CC 005119CC 0000BFFF */  sd         $31, 0x0($29)
    /* 4119D0 005119D0 0000BFDF */  ld         $31, 0x0($29)
    /* 4119D4 005119D4 48461408 */  j          func_00511920
    /* 4119D8 005119D8 1000BD27 */   addiu     $29, $29, 0x10
    /* 4119DC 005119DC 00000000 */  nop
.size func_005119c8, 0x18
