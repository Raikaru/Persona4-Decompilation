.section .text
.set noat
.set noreorder
glabel func_0050bcd8
    /* 40BCD8 0050BCD8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40BCDC 0050BCDC 0000BFFF */  sd         $31, 0x0($29)
    /* 40BCE0 0050BCE0 F42C140C */  jal        func_0050b3d0
    /* 40BCE4 0050BCE4 00000000 */   nop
    /* 40BCE8 0050BCE8 3400428C */  lw         $2, 0x34($2)
    /* 40BCEC 0050BCEC 0000BFDF */  ld         $31, 0x0($29)
    /* 40BCF0 0050BCF0 0800E003 */  jr         $31
    /* 40BCF4 0050BCF4 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050bcd8, 0x20
