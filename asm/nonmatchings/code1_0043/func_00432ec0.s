.section .text
.set noat
.set noreorder
glabel func_00432ec0
    /* 332EC0 00432EC0 2D30A000 */  daddu      $6, $5, $0
    /* 332EC4 00432EC4 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 332EC8 00432EC8 2D288000 */  daddu      $5, $4, $0
    /* 332ECC 00432ECC 0000BFFF */  sd         $31, 0x0($29)
    /* 332ED0 00432ED0 86CB100C */  jal        func_00432e18
    /* 332ED4 00432ED4 01000424 */   addiu     $4, $0, 0x1
    /* 332ED8 00432ED8 0000BFDF */  ld         $31, 0x0($29)
    /* 332EDC 00432EDC 0800E003 */  jr         $31
    /* 332EE0 00432EE0 1000BD27 */   addiu     $29, $29, 0x10
    /* 332EE4 00432EE4 00000000 */  nop
.size func_00432ec0, 0x28
