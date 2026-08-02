.section .text
.set noat
.set noreorder
glabel func_004f3ff8
    /* 3F3FF8 004F3FF8 7400023C */  lui        $2, %hi(D_00743A50)
    /* 3F3FFC 004F3FFC 503A438C */  lw         $3, %lo(D_00743A50)($2)
    /* 3F4000 004F4000 2C00628C */  lw         $2, 0x2C($3)
    /* 3F4004 004F4004 00004438 */  xori       $4, $2, 0x0
    /* 3F4008 004F4008 16004224 */  addiu      $2, $2, 0x16
    /* 3F400C 004F400C 0800E003 */  jr         $31
    /* 3F4010 004F4010 0A100400 */   movz      $2, $0, $4
    /* 3F4014 004F4014 00000000 */  nop
.size func_004f3ff8, 0x20
