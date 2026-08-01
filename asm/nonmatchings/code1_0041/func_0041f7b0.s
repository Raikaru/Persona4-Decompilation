.section .text
.set noat
.set noreorder
glabel func_0041f7b0
    /* 31F7B0 0041F7B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 31F7B4 0041F7B4 0000BFFF */  sd         $31, 0x0($29)
    /* 31F7B8 0041F7B8 4000848C */  lw         $4, 0x40($4)
    /* 31F7BC 0041F7BC CE83100C */  jal        func_00420f38
    /* 31F7C0 0041F7C0 68008424 */   addiu     $4, $4, 0x68
    /* 31F7C4 0041F7C4 0000BFDF */  ld         $31, 0x0($29)
    /* 31F7C8 0041F7C8 01000224 */  addiu      $2, $0, 0x1
    /* 31F7CC 0041F7CC 0800E003 */  jr         $31
    /* 31F7D0 0041F7D0 1000BD27 */   addiu     $29, $29, 0x10
    /* 31F7D4 0041F7D4 00000000 */  nop
.size func_0041f7b0, 0x28
