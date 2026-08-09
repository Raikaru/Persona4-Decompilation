.section .text
.set noat
.set noreorder
glabel func_0043fa88
    /* 33FA88 0043FA88 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 33FA8C 0043FA8C 0000B0FF */  sd         $16, 0x0($29)
    /* 33FA90 0043FA90 0800BFFF */  sd         $31, 0x8($29)
    /* 33FA94 0043FA94 AC88100C */  jal        QueryIntrContext
    /* 33FA98 0043FA98 00000000 */   nop
    /* 33FA9C 0043FA9C 01000F24 */  addiu      $15, $0, 0x1
    /* 33FAA0 0043FAA0 0B004F10 */  beq        $2, $15, .L0043FAD0
    /* 33FAA4 0043FAA4 7100103C */   lui       $16, %hi(D_007104D8)
    /* 33FAA8 0043FAA8 D8040F8E */  lw         $15, %lo(D_007104D8)($16)
    /* 33FAAC 0043FAAC 0700E015 */  bnez       $15, .L0043FACC
    /* 33FAB0 0043FAB0 0100EF25 */   addiu     $15, $15, 0x1
    /* 33FAB4 0043FAB4 88AE100C */  jal        func_0042ba20
    /* 33FAB8 0043FAB8 00000000 */   nop
    /* 33FABC 0043FABC 71000F3C */  lui        $15, %hi(D_007104DC)
    /* 33FAC0 0043FAC0 DC04E2AD */  sw         $2, %lo(D_007104DC)($15)
    /* 33FAC4 0043FAC4 D8040F8E */  lw         $15, %lo(D_007104D8)($16)
    /* 33FAC8 0043FAC8 0100EF25 */  addiu      $15, $15, 0x1
  .L0043FACC:
    /* 33FACC 0043FACC D8040FAE */  sw         $15, %lo(D_007104D8)($16)
  .L0043FAD0:
    /* 33FAD0 0043FAD0 0000B0DF */  ld         $16, 0x0($29)
    /* 33FAD4 0043FAD4 0800BFDF */  ld         $31, 0x8($29)
    /* 33FAD8 0043FAD8 0800E003 */  jr         $31
    /* 33FADC 0043FADC 1000BD27 */   addiu     $29, $29, 0x10
.size func_0043fa88, 0x58
