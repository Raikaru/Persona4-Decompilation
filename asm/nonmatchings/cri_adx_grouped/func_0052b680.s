.section .text
.set noat
.set noreorder
glabel func_0052b680
    /* 42B680 0052B680 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 42B684 0052B684 2D280000 */  daddu      $5, $0, $0
    /* 42B688 0052B688 0000B0FF */  sd         $16, 0x0($29)
    /* 42B68C 0052B68C 7400103C */  lui        $16, %hi(D_00745C70)
    /* 42B690 0052B690 705C1026 */  addiu      $16, $16, %lo(D_00745C70)
    /* 42B694 0052B694 C8040624 */  addiu      $6, $0, 0x4C8
    /* 42B698 0052B698 0800BFFF */  sd         $31, 0x8($29)
    /* 42B69C 0052B69C 72FE100C */  jal        func_0043f9c8
    /* 42B6A0 0052B6A0 2D200002 */   daddu     $4, $16, $0
    /* 42B6A4 0052B6A4 08000324 */  addiu      $3, $0, 0x8
    /* 42B6A8 0052B6A8 040003AE */  sw         $3, 0x4($16)
    /* 42B6AC 0052B6AC 78AE140C */  jal        func_0052b9e0
    /* 42B6B0 0052B6B0 01000424 */   addiu     $4, $0, 0x1
    /* 42B6B4 0052B6B4 0000B0DF */  ld         $16, 0x0($29)
    /* 42B6B8 0052B6B8 0800BFDF */  ld         $31, 0x8($29)
    /* 42B6BC 0052B6BC AEE61308 */  j          func_004f9ab8
    /* 42B6C0 0052B6C0 1000BD27 */   addiu     $29, $29, 0x10
    /* 42B6C4 0052B6C4 00000000 */  nop
.size func_0052b680, 0x48
