.section .text
.set noat
.set noreorder
glabel func_002e0d60
    /* 1E0D60 002E0D60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1E0D64 002E0D64 0000BFFF */  sd         $31, 0x0($29)
    /* 1E0D68 002E0D68 30000424 */  addiu      $4, $0, 0x30
    /* 1E0D6C 002E0D6C 2D280000 */  daddu      $5, $0, $0
    /* 1E0D70 002E0D70 2D300000 */  daddu      $6, $0, $0
    /* 1E0D74 002E0D74 2D380000 */  daddu      $7, $0, $0
    /* 1E0D78 002E0D78 6C870B0C */  jal        func_002e1db0
    /* 1E0D7C 002E0D7C 00000000 */   nop
    /* 1E0D80 002E0D80 88B582AF */  sw         $2, -0x4A78($28)
    /* 1E0D84 002E0D84 2400428C */  lw         $2, 0x24($2)
    /* 1E0D88 002E0D88 0000BFDF */  ld         $31, 0x0($29)
    /* 1E0D8C 002E0D8C 1000BD27 */  addiu      $29, $29, 0x10
    /* 1E0D90 002E0D90 0800E003 */  jr         $31
    /* 1E0D94 002E0D94 00000000 */   nop
    /* 1E0D98 002E0D98 00000000 */  nop
    /* 1E0D9C 002E0D9C 00000000 */  nop
.size func_002e0d60, 0x40
