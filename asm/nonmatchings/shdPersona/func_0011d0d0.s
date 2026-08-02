.section .text
.set noat
.set noreorder
glabel func_0011d0d0
    /* 1D0D0 0011D0D0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1D0D4 0011D0D4 0000BFFF */  sd         $31, 0x0($29)
    /* 1D0D8 0011D0D8 3800828C */  lw         $2, 0x38($4)
    /* 1D0DC 0011D0DC F804448C */  lw         $4, 0x4F8($2)
    /* 1D0E0 0011D0E0 9078040C */  jal        func_0011e240
    /* 1D0E4 0011D0E4 00000000 */   nop
    /* 1D0E8 0011D0E8 0000BFDF */  ld         $31, 0x0($29)
    /* 1D0EC 0011D0EC 1000BD27 */  addiu      $29, $29, 0x10
    /* 1D0F0 0011D0F0 0800E003 */  jr         $31
    /* 1D0F4 0011D0F4 00000000 */   nop
    /* 1D0F8 0011D0F8 00000000 */  nop
    /* 1D0FC 0011D0FC 00000000 */  nop
.size func_0011d0d0, 0x30
