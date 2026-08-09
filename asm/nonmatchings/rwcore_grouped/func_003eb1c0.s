.section .text
.set noat
.set noreorder
glabel func_003eb1c0
    /* 2EB1C0 003EB1C0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2EB1C4 003EB1C4 3F00063C */  lui        $6, %hi(func_003eb0d0)
    /* 2EB1C8 003EB1C8 0000BFFF */  sd         $31, 0x0($29)
    /* 2EB1CC 003EB1CC 14000524 */  addiu      $5, $0, 0x14
    /* 2EB1D0 003EB1D0 D0B0C624 */  addiu      $6, $6, %lo(func_003eb0d0)
    /* 2EB1D4 003EB1D4 1C00A727 */  addiu      $7, $29, 0x1C
    /* 2EB1D8 003EB1D8 DCAA0F0C */  jal        func_003eab70
    /* 2EB1DC 003EB1DC 1C00A0AF */   sw        $0, 0x1C($29)
    /* 2EB1E0 003EB1E0 1C00A28F */  lw         $2, 0x1C($29)
    /* 2EB1E4 003EB1E4 0000BFDF */  ld         $31, 0x0($29)
    /* 2EB1E8 003EB1E8 0800E003 */  jr         $31
    /* 2EB1EC 003EB1EC 2000BD27 */   addiu     $29, $29, 0x20
.size func_003eb1c0, 0x30
