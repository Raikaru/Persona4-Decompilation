.section .text
.set noat
.set noreorder
glabel func_00104c50
    /* 4C50 00104C50 7A00033C */  lui        $3, %hi(D_0079BF00)
    /* 4C54 00104C54 00BF6324 */  addiu      $3, $3, %lo(D_0079BF00)
    /* 4C58 00104C58 10006324 */  addiu      $3, $3, 0x10
    /* 4C5C 00104C5C B0B183AF */  sw         $3, -0x4E50($28)
    /* 4C60 00104C60 0800E003 */  jr         $31
    /* 4C64 00104C64 00000000 */   nop
    /* 4C68 00104C68 00000000 */  nop
    /* 4C6C 00104C6C 00000000 */  nop
.size func_00104c50, 0x20
