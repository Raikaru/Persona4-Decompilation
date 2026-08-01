.section .text
.set noat
.set noreorder
glabel func_00178c00
    /* 78C00 00178C00 01000224 */  addiu      $2, $0, 0x1
    /* 78C04 00178C04 E0B2838F */  lw         $3, -0x4D20($28)
    /* 78C08 00178C08 080062AC */  sw         $2, 0x8($3)
    /* 78C0C 00178C0C E0B280AF */  sw         $0, -0x4D20($28)
    /* 78C10 00178C10 0800E003 */  jr         $31
    /* 78C14 00178C14 00000000 */   nop
    /* 78C18 00178C18 00000000 */  nop
    /* 78C1C 00178C1C 00000000 */  nop
.size func_00178c00, 0x20
