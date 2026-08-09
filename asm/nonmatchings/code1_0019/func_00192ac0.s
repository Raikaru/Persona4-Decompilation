.section .text
.set noat
.set noreorder
glabel func_00192ac0
    /* 92AC0 00192AC0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 92AC4 00192AC4 0000BFFF */  sd         $31, 0x0($29)
    /* 92AC8 00192AC8 344B060C */  jal        func_00192cd0
    /* 92ACC 00192ACC 00000000 */   nop
    /* 92AD0 00192AD0 0000BFDF */  ld         $31, 0x0($29)
    /* 92AD4 00192AD4 1000BD27 */  addiu      $29, $29, 0x10
    /* 92AD8 00192AD8 0800E003 */  jr         $31
    /* 92ADC 00192ADC 00000000 */   nop
.size func_00192ac0, 0x20
