.section .text
.set noat
.set noreorder
glabel func_003ef020
    /* 2EF020 003EF020 E0B7838F */  lw         $3, -0x4820($28)
    /* 2EF024 003EF024 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2EF028 003EF028 E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2EF02C 003EF02C 21104300 */  addu       $2, $2, $3
    /* 2EF030 003EF030 0800E003 */  jr         $31
    /* 2EF034 003EF034 1C00428C */   lw        $2, 0x1C($2)
    /* 2EF038 003EF038 00000000 */  nop
    /* 2EF03C 003EF03C 00000000 */  nop
.size func_003ef020, 0x20
