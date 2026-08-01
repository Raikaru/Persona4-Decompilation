.section .text
.set noat
.set noreorder
glabel func_003df8a0
    /* 2DF8A0 003DF8A0 0C00838C */  lw         $3, 0xC($4)
    /* 2DF8A4 003DF8A4 0400828C */  lw         $2, 0x4($4)
    /* 2DF8A8 003DF8A8 18186200 */  mult       $3, $3, $2
    /* 2DF8AC 003DF8AC 0000828C */  lw         $2, 0x0($4)
    /* 2DF8B0 003DF8B0 0800E003 */  jr         $31
    /* 2DF8B4 003DF8B4 21104300 */   addu      $2, $2, $3
    /* 2DF8B8 003DF8B8 00000000 */  nop
    /* 2DF8BC 003DF8BC 00000000 */  nop
.size func_003df8a0, 0x20
