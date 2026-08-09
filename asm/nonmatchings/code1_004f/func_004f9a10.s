.section .text
.set noat
.set noreorder
glabel func_004f9a10
    /* 3F9A10 004F9A10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F9A14 004F9A14 0800BFFF */  sd         $31, 0x8($29)
    /* 3F9A18 004F9A18 0000B0FF */  sd         $16, 0x0($29)
    /* 3F9A1C 004F9A1C 01001024 */  addiu      $16, $0, 0x1
  .L004F9A20:
    /* 3F9A20 004F9A20 6090130C */  jal        func_004e4180
    /* 3F9A24 004F9A24 00000000 */   nop
    /* 3F9A28 004F9A28 FDFF5010 */  beq        $2, $16, .L004F9A20
    /* 3F9A2C 004F9A2C 00000000 */   nop
    /* 3F9A30 004F9A30 82C1130C */  jal        func_004f0608
    /* 3F9A34 004F9A34 00000000 */   nop
    /* 3F9A38 004F9A38 6090130C */  jal        func_004e4180
    /* 3F9A3C 004F9A3C 00000000 */   nop
    /* 3F9A40 004F9A40 01004238 */  xori       $2, $2, 0x1
    /* 3F9A44 004F9A44 0000B0DF */  ld         $16, 0x0($29)
    /* 3F9A48 004F9A48 0800BFDF */  ld         $31, 0x8($29)
    /* 3F9A4C 004F9A4C 2B100200 */  sltu       $2, $0, $2
    /* 3F9A50 004F9A50 0800E003 */  jr         $31
    /* 3F9A54 004F9A54 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f9a10, 0x48
