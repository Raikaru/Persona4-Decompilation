.section .text
.set noat
.set noreorder
glabel func_003df480
    /* 2DF480 003DF480 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2DF484 003DF484 2D108000 */  daddu      $2, $4, $0
    /* 2DF488 003DF488 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2DF48C 003DF48C 60B785AF */  sw         $5, -0x48A0($28)
    /* 2DF490 003DF490 21206500 */  addu       $4, $3, $5
    /* 2DF494 003DF494 64B7858F */  lw         $5, -0x489C($28)
    /* 2DF498 003DF498 0080033C */  lui        $3, (0x80000000 >> 16)
    /* 2DF49C 003DF49C 000080AC */  sw         $0, 0x0($4)
    /* 2DF4A0 003DF4A0 040083AC */  sw         $3, 0x4($4)
    /* 2DF4A4 003DF4A4 0100A324 */  addiu      $3, $5, 0x1
    /* 2DF4A8 003DF4A8 0800E003 */  jr         $31
    /* 2DF4AC 003DF4AC 64B783AF */   sw        $3, -0x489C($28)
.size func_003df480, 0x30
