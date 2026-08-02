.section .text
.set noat
.set noreorder
glabel func_0025cc70
    /* 15CC70 0025CC70 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 15CC74 0025CC74 0000BFFF */  sd         $31, 0x0($29)
    /* 15CC78 0025CC78 6300043C */  lui        $4, %hi(D_00636A30)
    /* 15CC7C 0025CC7C 306A8424 */  addiu      $4, $4, %lo(D_00636A30)
    /* 15CC80 0025CC80 E048110C */  jal        func_00452380
    /* 15CC84 0025CC84 00000000 */   nop
    /* 15CC88 0025CC88 2D204000 */  daddu      $4, $2, $0
    /* 15CC8C 0025CC8C 2449110C */  jal        func_00452490
    /* 15CC90 0025CC90 00000000 */   nop
    /* 15CC94 0025CC94 2B100200 */  sltu       $2, $0, $2
    /* 15CC98 0025CC98 0000BFDF */  ld         $31, 0x0($29)
    /* 15CC9C 0025CC9C 1000BD27 */  addiu      $29, $29, 0x10
    /* 15CCA0 0025CCA0 0800E003 */  jr         $31
    /* 15CCA4 0025CCA4 00000000 */   nop
    /* 15CCA8 0025CCA8 00000000 */  nop
    /* 15CCAC 0025CCAC 00000000 */  nop
.size func_0025cc70, 0x40
