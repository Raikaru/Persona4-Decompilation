.section .text
.set noat
.set noreorder
glabel func_004cd780
    /* 3CD780 004CD780 7600043C */  lui        $4, %hi(D_007589B8)
    /* 3CD784 004CD784 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD788 004CD788 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD78C 004CD78C FC34130C */  jal        func_004cd3f0
    /* 3CD790 004CD790 B8898424 */   addiu     $4, $4, %lo(D_007589B8)
    /* 3CD794 004CD794 00000000 */  nop
  .L004CD798:
    /* 3CD798 004CD798 00000000 */  nop
    /* 3CD79C 004CD79C 00000000 */  nop
    /* 3CD7A0 004CD7A0 00000000 */  nop
    /* 3CD7A4 004CD7A4 00000000 */  nop
    /* 3CD7A8 004CD7A8 00000000 */  nop
    /* 3CD7AC 004CD7AC FAFF0010 */  b          .L004CD798
    /* 3CD7B0 004CD7B0 00000000 */   nop
    /* 3CD7B4 004CD7B4 00000000 */  nop
.size func_004cd780, 0x38
