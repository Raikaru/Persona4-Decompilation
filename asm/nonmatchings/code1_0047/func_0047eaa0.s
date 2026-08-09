.section .text
.set noat
.set noreorder
glabel func_0047eaa0
    /* 37EAA0 0047EAA0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 37EAA4 0047EAA4 2000BFFF */  sd         $31, 0x20($29)
    /* 37EAA8 0047EAA8 1000B17F */  sq         $17, 0x10($29)
    /* 37EAAC 0047EAAC 0000B07F */  sq         $16, 0x0($29)
    /* 37EAB0 0047EAB0 2D808000 */  daddu      $16, $4, $0
    /* 37EAB4 0047EAB4 0000918C */  lw         $17, 0x0($4)
    /* 37EAB8 0047EAB8 13002012 */  beqz       $17, .L0047EB08
    /* 37EABC 0047EABC 00000000 */   nop
    /* 37EAC0 0047EAC0 0800238E */  lw         $3, 0x8($17)
    /* 37EAC4 0047EAC4 FFFF6324 */  addiu      $3, $3, -0x1
    /* 37EAC8 0047EAC8 080023AE */  sw         $3, 0x8($17)
    /* 37EACC 0047EACC 0D006014 */  bnez       $3, .L0047EB04
    /* 37EAD0 0047EAD0 00000000 */   nop
    /* 37EAD4 0047EAD4 0000248E */  lw         $4, 0x0($17)
    /* 37EAD8 0047EAD8 05008010 */  beqz       $4, .L0047EAF0
    /* 37EADC 0047EADC 00000000 */   nop
    /* 37EAE0 0047EAE0 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 37EAE4 0047EAE4 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 37EAE8 0047EAE8 09F84000 */  jalr       $2
    /* 37EAEC 0047EAEC 00000000 */   nop
  .L0047EAF0:
    /* 37EAF0 0047EAF0 2D202002 */  daddu      $4, $17, $0
    /* 37EAF4 0047EAF4 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 37EAF8 0047EAF8 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 37EAFC 0047EAFC 09F84000 */  jalr       $2
    /* 37EB00 0047EB00 00000000 */   nop
  .L0047EB04:
    /* 37EB04 0047EB04 000000AE */  sw         $0, 0x0($16)
  .L0047EB08:
    /* 37EB08 0047EB08 2000BFDF */  ld         $31, 0x20($29)
    /* 37EB0C 0047EB0C 1000B17B */  lq         $17, 0x10($29)
    /* 37EB10 0047EB10 0000B07B */  lq         $16, 0x0($29)
    /* 37EB14 0047EB14 3000BD27 */  addiu      $29, $29, 0x30
    /* 37EB18 0047EB18 0800E003 */  jr         $31
    /* 37EB1C 0047EB1C 00000000 */   nop
.size func_0047eaa0, 0x80
