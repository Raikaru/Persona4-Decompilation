.section .text
.set noat
.set noreorder
glabel func_004f94b8
    /* 3F94B8 004F94B8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F94BC 004F94BC 9CFF0224 */  addiu      $2, $0, -0x64
    /* 3F94C0 004F94C0 0300A010 */  beqz       $5, .L004F94D0
    /* 3F94C4 004F94C4 0000BFFF */   sd        $31, 0x0($29)
    /* 3F94C8 004F94C8 4CE4130C */  jal        func_004f9130
    /* 3F94CC 004F94CC 00000000 */   nop
  .L004F94D0:
    /* 3F94D0 004F94D0 0000BFDF */  ld         $31, 0x0($29)
    /* 3F94D4 004F94D4 0800E003 */  jr         $31
    /* 3F94D8 004F94D8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F94DC 004F94DC 00000000 */  nop
.size func_004f94b8, 0x28
