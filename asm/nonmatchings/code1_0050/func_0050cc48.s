.section .text
.set noat
.set noreorder
glabel func_0050cc48
    /* 40CC48 0050CC48 2D108000 */  daddu      $2, $4, $0
    /* 40CC4C 0050CC4C 0070043C */  lui        $4, (0x70000000 >> 16)
    /* 40CC50 0050CC50 21208600 */  addu       $4, $4, $6
    /* 40CC54 0050CC54 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40CC58 0050CC58 2D30A000 */  daddu      $6, $5, $0
    /* 40CC5C 0050CC5C 0000BFFF */  sd         $31, 0x0($29)
    /* 40CC60 0050CC60 04FE100C */  jal        func_0043f810
    /* 40CC64 0050CC64 2D284000 */   daddu     $5, $2, $0
    /* 40CC68 0050CC68 2D100000 */  daddu      $2, $0, $0
    /* 40CC6C 0050CC6C 0000BFDF */  ld         $31, 0x0($29)
    /* 40CC70 0050CC70 0800E003 */  jr         $31
    /* 40CC74 0050CC74 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050cc48, 0x30
