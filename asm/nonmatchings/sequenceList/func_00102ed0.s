.section .text
.set noat
.set noreorder
glabel func_00102ed0
    /* 2ED0 00102ED0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2ED4 00102ED4 0000BFFF */  sd         $31, 0x0($29)
    /* 2ED8 00102ED8 C04D060C */  jal        func_00193700
    /* 2EDC 00102EDC 00000000 */   nop
    /* 2EE0 00102EE0 2D204000 */  daddu      $4, $2, $0
    /* 2EE4 00102EE4 03008010 */  beqz       $4, .L00102EF4
    /* 2EE8 00102EE8 00000000 */   nop
    /* 2EEC 00102EEC 2048110C */  jal        func_00452080
    /* 2EF0 00102EF0 00000000 */   nop
  .L00102EF4:
    /* 2EF4 00102EF4 0000BFDF */  ld         $31, 0x0($29)
    /* 2EF8 00102EF8 1000BD27 */  addiu      $29, $29, 0x10
    /* 2EFC 00102EFC 0800E003 */  jr         $31
    /* 2F00 00102F00 00000000 */   nop
    /* 2F04 00102F04 00000000 */  nop
    /* 2F08 00102F08 00000000 */  nop
    /* 2F0C 00102F0C 00000000 */  nop
.size func_00102ed0, 0x40
