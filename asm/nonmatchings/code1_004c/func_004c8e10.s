.section .text
.set noat
.set noreorder
glabel func_004c8e10
    /* 3C8E10 004C8E10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C8E14 004C8E14 0000BFFF */  sd         $31, 0x0($29)
    /* 3C8E18 004C8E18 0000BFDF */  ld         $31, 0x0($29)
    /* 3C8E1C 004C8E1C 4A231308 */  j          func_004c8d28
    /* 3C8E20 004C8E20 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C8E24 004C8E24 00000000 */  nop
.size func_004c8e10, 0x18
