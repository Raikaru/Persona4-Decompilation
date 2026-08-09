.section .text
.set noat
.set noreorder
glabel func_0019be50
    /* 9BE50 0019BE50 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 9BE54 0019BE54 0000BFFF */  sd         $31, 0x0($29)
    /* 9BE58 0019BE58 0000828C */  lw         $2, 0x0($4)
    /* 9BE5C 0019BE5C 080A448C */  lw         $4, 0xA08($2)
    /* 9BE60 0019BE60 03008010 */  beqz       $4, .L0019BE70
    /* 9BE64 0019BE64 00000000 */   nop
    /* 9BE68 0019BE68 B85B070C */  jal        func_001d6ee0
    /* 9BE6C 0019BE6C 00000000 */   nop
  .L0019BE70:
    /* 9BE70 0019BE70 01000224 */  addiu      $2, $0, 0x1
    /* 9BE74 0019BE74 0000BFDF */  ld         $31, 0x0($29)
    /* 9BE78 0019BE78 1000BD27 */  addiu      $29, $29, 0x10
    /* 9BE7C 0019BE7C 0800E003 */  jr         $31
    /* 9BE80 0019BE80 00000000 */   nop
    /* 9BE84 0019BE84 00000000 */  nop
    /* 9BE88 0019BE88 00000000 */  nop
    /* 9BE8C 0019BE8C 00000000 */  nop
.size func_0019be50, 0x40
