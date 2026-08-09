.section .text
.set noat
.set noreorder
glabel func_0050caa0
    /* 40CAA0 0050CAA0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40CAA4 0050CAA4 0000B0FF */  sd         $16, 0x0($29)
    /* 40CAA8 0050CAA8 0800BFFF */  sd         $31, 0x8($29)
    /* 40CAAC 0050CAAC A032140C */  jal        func_0050ca80
    /* 40CAB0 0050CAB0 2D808000 */   daddu     $16, $4, $0
    /* 40CAB4 0050CAB4 7400033C */  lui        $3, %hi(D_0074587C)
    /* 40CAB8 0050CAB8 2D284000 */  daddu      $5, $2, $0
    /* 40CABC 0050CABC 7C58628C */  lw         $2, %lo(D_0074587C)($3)
    /* 40CAC0 0050CAC0 03004010 */  beqz       $2, .L0050CAD0
    /* 40CAC4 0050CAC4 2D200002 */   daddu     $4, $16, $0
    /* 40CAC8 0050CAC8 09F84000 */  jalr       $2
    /* 40CACC 0050CACC 00000000 */   nop
  .L0050CAD0:
    /* 40CAD0 0050CAD0 0000B0DF */  ld         $16, 0x0($29)
    /* 40CAD4 0050CAD4 0800BFDF */  ld         $31, 0x8($29)
    /* 40CAD8 0050CAD8 0800E003 */  jr         $31
    /* 40CADC 0050CADC 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050caa0, 0x40
