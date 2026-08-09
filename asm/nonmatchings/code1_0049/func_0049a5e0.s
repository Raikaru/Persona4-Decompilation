.section .text
.set noat
.set noreorder
glabel func_0049a5e0
    /* 39A5E0 0049A5E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 39A5E4 0049A5E4 0000BFFF */  sd         $31, 0x0($29)
    /* 39A5E8 0049A5E8 2D108000 */  daddu      $2, $4, $0
    /* 39A5EC 0049A5EC 38008494 */  lhu        $4, 0x38($4)
    /* 39A5F0 0049A5F0 4000458C */  lw         $5, 0x40($2)
    /* 39A5F4 0049A5F4 DC68120C */  jal        func_0049a370
    /* 39A5F8 0049A5F8 00000000 */   nop
    /* 39A5FC 0049A5FC 0000BFDF */  ld         $31, 0x0($29)
    /* 39A600 0049A600 1000BD27 */  addiu      $29, $29, 0x10
    /* 39A604 0049A604 0800E003 */  jr         $31
    /* 39A608 0049A608 00000000 */   nop
    /* 39A60C 0049A60C 00000000 */  nop
.size func_0049a5e0, 0x30
