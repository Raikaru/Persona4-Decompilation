.section .text
.set noat
.set noreorder
glabel func_004a5fa0
    /* 3A5FA0 004A5FA0 2C00838C */  lw         $3, 0x2C($4)
    /* 3A5FA4 004A5FA4 01006324 */  addiu      $3, $3, 0x1
    /* 3A5FA8 004A5FA8 2C0083AC */  sw         $3, 0x2C($4)
    /* 3A5FAC 004A5FAC 0800E003 */  jr         $31
    /* 3A5FB0 004A5FB0 00000000 */   nop
    /* 3A5FB4 004A5FB4 00000000 */  nop
    /* 3A5FB8 004A5FB8 00000000 */  nop
    /* 3A5FBC 004A5FBC 00000000 */  nop
.size func_004a5fa0, 0x20
