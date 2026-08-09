.section .text
.set noat
.set noreorder
glabel func_004cd578
    /* 3CD578 004CD578 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD57C 004CD57C 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD580 004CD580 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD584 004CD584 B4AF1308 */  j          func_004ebed0
    /* 3CD588 004CD588 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD58C 004CD58C 00000000 */  nop
.size func_004cd578, 0x18
