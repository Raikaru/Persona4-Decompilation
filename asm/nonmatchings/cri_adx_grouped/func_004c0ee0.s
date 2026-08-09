.section .text
.set noat
.set noreorder
glabel func_004c0ee0
    /* 3C0EE0 004C0EE0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C0EE4 004C0EE4 04008010 */  beqz       $4, .L004C0EF8
    /* 3C0EE8 004C0EE8 0000BFFF */   sd        $31, 0x0($29)
    /* 3C0EEC 004C0EEC 0000BFDF */  ld         $31, 0x0($29)
    /* 3C0EF0 004C0EF0 92041308 */  j          func_004c1248
    /* 3C0EF4 004C0EF4 1000BD27 */   addiu     $29, $29, 0x10
  .L004C0EF8:
    /* 3C0EF8 004C0EF8 0000BFDF */  ld         $31, 0x0($29)
    /* 3C0EFC 004C0EFC 0800E003 */  jr         $31
    /* 3C0F00 004C0F00 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C0F04 004C0F04 00000000 */  nop
.size func_004c0ee0, 0x28
