.section .text
.set noat
.set noreorder
glabel func_0019bd80
    /* 9BD80 0019BD80 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 9BD84 0019BD84 0000BFFF */  sd         $31, 0x0($29)
    /* 9BD88 0019BD88 0000848C */  lw         $4, 0x0($4)
    /* 9BD8C 0019BD8C 3074060C */  jal        func_0019d0c0
    /* 9BD90 0019BD90 00000000 */   nop
    /* 9BD94 0019BD94 01000224 */  addiu      $2, $0, 0x1
    /* 9BD98 0019BD98 0000BFDF */  ld         $31, 0x0($29)
    /* 9BD9C 0019BD9C 1000BD27 */  addiu      $29, $29, 0x10
    /* 9BDA0 0019BDA0 0800E003 */  jr         $31
    /* 9BDA4 0019BDA4 00000000 */   nop
    /* 9BDA8 0019BDA8 00000000 */  nop
    /* 9BDAC 0019BDAC 00000000 */  nop
.size func_0019bd80, 0x30
