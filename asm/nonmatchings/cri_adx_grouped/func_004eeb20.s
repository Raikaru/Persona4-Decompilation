.section .text
.set noat
.set noreorder
glabel func_004eeb20
    /* 3EEB20 004EEB20 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EEB24 004EEB24 0000BFFF */  sd         $31, 0x0($29)
    /* 3EEB28 004EEB28 FAB4130C */  jal        func_004ed3e8
    /* 3EEB2C 004EEB2C 00000000 */   nop
    /* 3EEB30 004EEB30 14B5130C */  jal        func_004ed450
    /* 3EEB34 004EEB34 00000000 */   nop
    /* 3EEB38 004EEB38 D4BA130C */  jal        func_004eeb50
    /* 3EEB3C 004EEB3C 00000000 */   nop
    /* 3EEB40 004EEB40 0000BFDF */  ld         $31, 0x0($29)
    /* 3EEB44 004EEB44 1AB51308 */  j          func_004ed468
    /* 3EEB48 004EEB48 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EEB4C 004EEB4C 00000000 */  nop
.size func_004eeb20, 0x30
