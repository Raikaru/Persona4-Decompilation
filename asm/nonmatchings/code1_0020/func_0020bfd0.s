.section .text
.set noat
.set noreorder
glabel func_0020bfd0
    /* 10BFD0 0020BFD0 040080A4 */  sh         $0, 0x4($4)
    /* 10BFD4 0020BFD4 01000324 */  addiu      $3, $0, 0x1
    /* 10BFD8 0020BFD8 020083A4 */  sh         $3, 0x2($4)
    /* 10BFDC 0020BFDC 0800E003 */  jr         $31
    /* 10BFE0 0020BFE0 00000000 */   nop
    /* 10BFE4 0020BFE4 00000000 */  nop
    /* 10BFE8 0020BFE8 00000000 */  nop
    /* 10BFEC 0020BFEC 00000000 */  nop
.size func_0020bfd0, 0x20
