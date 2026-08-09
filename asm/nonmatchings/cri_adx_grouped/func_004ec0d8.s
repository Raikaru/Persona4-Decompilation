.section .text
.set noat
.set noreorder
glabel func_004ec0d8
    /* 3EC0D8 004EC0D8 7400023C */  lui        $2, %hi(D_0073A748)
    /* 3EC0DC 004EC0DC F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EC0E0 004EC0E0 48A7438C */  lw         $3, %lo(D_0073A748)($2)
    /* 3EC0E4 004EC0E4 01000424 */  addiu      $4, $0, 0x1
    /* 3EC0E8 004EC0E8 0000B0FF */  sd         $16, 0x0($29)
    /* 3EC0EC 004EC0EC 05006414 */  bne        $3, $4, .L004EC104
    /* 3EC0F0 004EC0F0 0800BFFF */   sd        $31, 0x8($29)
    /* 3EC0F4 004EC0F4 7400023C */  lui        $2, %hi(D_0073A740)
    /* 3EC0F8 004EC0F8 40A7438C */  lw         $3, %lo(D_0073A740)($2)
    /* 3EC0FC 004EC0FC 0D006018 */  blez       $3, .L004EC134
    /* 3EC100 004EC100 0000B0DF */   ld        $16, 0x0($29)
  .L004EC104:
    /* 3EC104 004EC104 7400023C */  lui        $2, %hi(D_0073A770)
    /* 3EC108 004EC108 70A75024 */  addiu      $16, $2, %lo(D_0073A770)
    /* 3EC10C 004EC10C 0000038E */  lw         $3, 0x0($16)
    /* 3EC110 004EC110 07006010 */  beqz       $3, .L004EC130
    /* 3EC114 004EC114 0F000424 */   addiu     $4, $0, 0xF
    /* 3EC118 004EC118 2D280000 */  daddu      $5, $0, $0
    /* 3EC11C 004EC11C 2D300000 */  daddu      $6, $0, $0
    /* 3EC120 004EC120 2D380000 */  daddu      $7, $0, $0
    /* 3EC124 004EC124 2896130C */  jal        func_004e58a0
    /* 3EC128 004EC128 2D400000 */   daddu     $8, $0, $0
    /* 3EC12C 004EC12C 000000AE */  sw         $0, 0x0($16)
  .L004EC130:
    /* 3EC130 004EC130 0000B0DF */  ld         $16, 0x0($29)
  .L004EC134:
    /* 3EC134 004EC134 0800BFDF */  ld         $31, 0x8($29)
    /* 3EC138 004EC138 0800E003 */  jr         $31
    /* 3EC13C 004EC13C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004ec0d8, 0x68
