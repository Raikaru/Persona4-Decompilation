.section .text
.set noat
.set noreorder
glabel func_0041f788
    /* 31F788 0041F788 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 31F78C 0041F78C 0000BFFF */  sd         $31, 0x0($29)
    /* 31F790 0041F790 4000848C */  lw         $4, 0x40($4)
    /* 31F794 0041F794 9483100C */  jal        func_00420e50
    /* 31F798 0041F798 68008424 */   addiu     $4, $4, 0x68
    /* 31F79C 0041F79C 0000BFDF */  ld         $31, 0x0($29)
    /* 31F7A0 0041F7A0 01000224 */  addiu      $2, $0, 0x1
    /* 31F7A4 0041F7A4 0800E003 */  jr         $31
    /* 31F7A8 0041F7A8 1000BD27 */   addiu     $29, $29, 0x10
    /* 31F7AC 0041F7AC 00000000 */  nop
.size func_0041f788, 0x28
