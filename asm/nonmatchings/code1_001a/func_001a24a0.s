.section .text
.set noat
.set noreorder
glabel func_001a24a0
    /* A24A0 001A24A0 01000324 */  addiu      $3, $0, 0x1
    /* A24A4 001A24A4 1C0483AC */  sw         $3, 0x41C($4)
    /* A24A8 001A24A8 0800E003 */  jr         $31
    /* A24AC 001A24AC 00000000 */   nop
.size func_001a24a0, 0x10
