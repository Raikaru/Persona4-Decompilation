.section .text
.set noat
.set noreorder
glabel func_004ed580
    /* 3ED580 004ED580 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3ED584 004ED584 0000BFFF */  sd         $31, 0x0($29)
    /* 3ED588 004ED588 14B5130C */  jal        func_004ed450
    /* 3ED58C 004ED58C 00000000 */   nop
    /* 3ED590 004ED590 6CB5130C */  jal        func_004ed5b0
    /* 3ED594 004ED594 00000000 */   nop
    /* 3ED598 004ED598 1AB5130C */  jal        func_004ed468
    /* 3ED59C 004ED59C 00000000 */   nop
    /* 3ED5A0 004ED5A0 0000BFDF */  ld         $31, 0x0($29)
    /* 3ED5A4 004ED5A4 08B51308 */  j          func_004ed420
    /* 3ED5A8 004ED5A8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3ED5AC 004ED5AC 00000000 */  nop
.size func_004ed580, 0x30
