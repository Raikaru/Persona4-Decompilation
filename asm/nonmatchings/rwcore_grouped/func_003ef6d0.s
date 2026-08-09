.section .text
.set noat
.set noreorder
glabel func_003ef6d0
    /* 2EF6D0 003EF6D0 E0B7838F */  lw         $3, -0x4820($28)
    /* 2EF6D4 003EF6D4 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2EF6D8 003EF6D8 E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2EF6DC 003EF6DC 21104300 */  addu       $2, $2, $3
    /* 2EF6E0 003EF6E0 0800E003 */  jr         $31
    /* 2EF6E4 003EF6E4 1000428C */   lw        $2, 0x10($2)
    /* 2EF6E8 003EF6E8 00000000 */  nop
    /* 2EF6EC 003EF6EC 00000000 */  nop
.size func_003ef6d0, 0x20
