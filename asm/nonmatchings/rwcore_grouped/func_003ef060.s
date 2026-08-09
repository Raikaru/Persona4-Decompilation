.section .text
.set noat
.set noreorder
glabel func_003ef060
    /* 2EF060 003EF060 E0B7838F */  lw         $3, -0x4820($28)
    /* 2EF064 003EF064 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2EF068 003EF068 E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2EF06C 003EF06C 21104300 */  addu       $2, $2, $3
    /* 2EF070 003EF070 0800E003 */  jr         $31
    /* 2EF074 003EF074 2000428C */   lw        $2, 0x20($2)
    /* 2EF078 003EF078 00000000 */  nop
    /* 2EF07C 003EF07C 00000000 */  nop
.size func_003ef060, 0x20
