.section .text
.set noat
.set noreorder
glabel func_003ef000
    /* 2EF000 003EF000 E0B7858F */  lw         $5, -0x4820($28)
    /* 2EF004 003EF004 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2EF008 003EF008 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2EF00C 003EF00C 01000224 */  addiu      $2, $0, 0x1
    /* 2EF010 003EF010 21186500 */  addu       $3, $3, $5
    /* 2EF014 003EF014 0800E003 */  jr         $31
    /* 2EF018 003EF018 1C0064AC */   sw        $4, 0x1C($3)
    /* 2EF01C 003EF01C 00000000 */  nop
.size func_003ef000, 0x20
