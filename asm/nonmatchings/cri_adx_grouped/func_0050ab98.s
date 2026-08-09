.section .text
.set noat
.set noreorder
glabel func_0050ab98
    /* 40AB98 0050AB98 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40AB9C 0050AB9C 0000B0FF */  sd         $16, 0x0($29)
    /* 40ABA0 0050ABA0 0800BFFF */  sd         $31, 0x8($29)
    /* 40ABA4 0050ABA4 0A35140C */  jal        func_0050d428
    /* 40ABA8 0050ABA8 2D808000 */   daddu     $16, $4, $0
    /* 40ABAC 0050ABAC 01000324 */  addiu      $3, $0, 0x1
    /* 40ABB0 0050ABB0 07004310 */  beq        $2, $3, .L0050ABD0
    /* 40ABB4 0050ABB4 2D200002 */   daddu     $4, $16, $0
    /* 40ABB8 0050ABB8 7600043C */  lui        $4, %hi(D_0075E7A8)
    /* 40ABBC 0050ABBC 8844140C */  jal        func_00511220
    /* 40ABC0 0050ABC0 A8E78424 */   addiu     $4, $4, %lo(D_0075E7A8)
    /* 40ABC4 0050ABC4 0C000010 */  b          .L0050ABF8
    /* 40ABC8 0050ABC8 2D100000 */   daddu     $2, $0, $0
    /* 40ABCC 0050ABCC 00000000 */  nop
  .L0050ABD0:
    /* 40ABD0 0050ABD0 9833140C */  jal        func_0050ce60
    /* 40ABD4 0050ABD4 00000000 */   nop
    /* 40ABD8 0050ABD8 2D184000 */  daddu      $3, $2, $0
    /* 40ABDC 0050ABDC 06006010 */  beqz       $3, .L0050ABF8
    /* 40ABE0 0050ABE0 2D206000 */   daddu     $4, $3, $0
    /* 40ABE4 0050ABE4 0000B0DF */  ld         $16, 0x0($29)
    /* 40ABE8 0050ABE8 0800BFDF */  ld         $31, 0x8($29)
    /* 40ABEC 0050ABEC 907E1408 */  j          func_0051fa40
    /* 40ABF0 0050ABF0 1000BD27 */   addiu     $29, $29, 0x10
    /* 40ABF4 0050ABF4 00000000 */  nop
  .L0050ABF8:
    /* 40ABF8 0050ABF8 0000B0DF */  ld         $16, 0x0($29)
    /* 40ABFC 0050ABFC 0800BFDF */  ld         $31, 0x8($29)
    /* 40AC00 0050AC00 0800E003 */  jr         $31
    /* 40AC04 0050AC04 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050ab98, 0x70
