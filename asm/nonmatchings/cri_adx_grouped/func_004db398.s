.section .text
.set noat
.set noreorder
glabel func_004db398
    /* 3DB398 004DB398 7200023C */  lui        $2, %hi(D_00724E74)
    /* 3DB39C 004DB39C F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DB3A0 004DB3A0 744E428C */  lw         $2, %lo(D_00724E74)($2)
    /* 3DB3A4 004DB3A4 03004010 */  beqz       $2, .L004DB3B4
    /* 3DB3A8 004DB3A8 0000BFFF */   sd        $31, 0x0($29)
    /* 3DB3AC 004DB3AC 09F84000 */  jalr       $2
    /* 3DB3B0 004DB3B0 00000000 */   nop
  .L004DB3B4:
    /* 3DB3B4 004DB3B4 0000BFDF */  ld         $31, 0x0($29)
    /* 3DB3B8 004DB3B8 0800E003 */  jr         $31
    /* 3DB3BC 004DB3BC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004db398, 0x28
