.section .text
.set noat
.set noreorder
glabel func_004cd2a0
    /* 3CD2A0 004CD2A0 01000224 */  addiu      $2, $0, 0x1
    /* 3CD2A4 004CD2A4 02000324 */  addiu      $3, $0, 0x2
    /* 3CD2A8 004CD2A8 26208200 */  xor        $4, $4, $2
    /* 3CD2AC 004CD2AC 0800E003 */  jr         $31
    /* 3CD2B0 004CD2B0 0B106400 */   movn      $2, $3, $4
    /* 3CD2B4 004CD2B4 00000000 */  nop
.size func_004cd2a0, 0x18
