.section .text
.set noat
.set noreorder
glabel func_003ef6b0
    /* 2EF6B0 003EF6B0 E0B7858F */  lw         $5, -0x4820($28)
    /* 2EF6B4 003EF6B4 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2EF6B8 003EF6B8 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2EF6BC 003EF6BC 2D108000 */  daddu      $2, $4, $0
    /* 2EF6C0 003EF6C0 21186500 */  addu       $3, $3, $5
    /* 2EF6C4 003EF6C4 0800E003 */  jr         $31
    /* 2EF6C8 003EF6C8 100064AC */   sw        $4, 0x10($3)
    /* 2EF6CC 003EF6CC 00000000 */  nop
.size func_003ef6b0, 0x20
