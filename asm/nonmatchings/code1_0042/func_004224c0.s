.section .text
.set noat
.set noreorder
glabel func_004224c0
    /* 3224C0 004224C0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3224C4 004224C4 0000BFFF */  sd         $31, 0x0($29)
    /* 3224C8 004224C8 6C85100C */  jal        func_004215b0
    /* 3224CC 004224CC 00000000 */   nop
    /* 3224D0 004224D0 0F000000 */  sync
    /* 3224D4 004224D4 0000BFDF */  ld         $31, 0x0($29)
    /* 3224D8 004224D8 0800E003 */  jr         $31
    /* 3224DC 004224DC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004224c0, 0x20
