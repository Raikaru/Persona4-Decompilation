.section .text
.set noat
.set noreorder
glabel func_00416df0
    /* 316DF0 00416DF0 0400828C */  lw         $2, 0x4($4)
    /* 316DF4 00416DF4 16000324 */  addiu      $3, $0, 0x16
    /* 316DF8 00416DF8 18106200 */  mult       $2, $3, $2
    /* 316DFC 00416DFC 0800E003 */  jr         $31
    /* 316E00 00416E00 18004224 */   addiu     $2, $2, 0x18
    /* 316E04 00416E04 00000000 */  nop
    /* 316E08 00416E08 00000000 */  nop
    /* 316E0C 00416E0C 00000000 */  nop
.size func_00416df0, 0x20
