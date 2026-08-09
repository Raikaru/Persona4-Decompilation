.section .text
.set noat
.set noreorder
glabel func_004c40a0
    /* 3C40A0 004C40A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C40A4 004C40A4 48008224 */  addiu      $2, $4, 0x48
    /* 3C40A8 004C40A8 0800BFFF */  sd         $31, 0x8($29)
    /* 3C40AC 004C40AC 2D30A000 */  daddu      $6, $5, $0
    /* 3C40B0 004C40B0 0000B0FF */  sd         $16, 0x0($29)
    /* 3C40B4 004C40B4 2D400000 */  daddu      $8, $0, $0
    /* 3C40B8 004C40B8 2000478C */  lw         $7, 0x20($2)
    /* 3C40BC 004C40BC 0800908C */  lw         $16, 0x8($4)
    /* 3C40C0 004C40C0 1400438C */  lw         $3, 0x14($2)
    /* 3C40C4 004C40C4 40380700 */  sll        $7, $7, 1
    /* 3C40C8 004C40C8 0000458C */  lw         $5, 0x0($2)
    /* 3C40CC 004C40CC 2D200002 */  daddu      $4, $16, $0
    /* 3C40D0 004C40D0 8662130C */  jal        func_004d8a18
    /* 3C40D4 004C40D4 21386700 */   addu      $7, $3, $7
    /* 3C40D8 004C40D8 2D200002 */  daddu      $4, $16, $0
    /* 3C40DC 004C40DC 0800BFDF */  ld         $31, 0x8($29)
    /* 3C40E0 004C40E0 0000B0DF */  ld         $16, 0x0($29)
    /* 3C40E4 004C40E4 AA621308 */  j          func_004d8aa8
    /* 3C40E8 004C40E8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C40EC 004C40EC 00000000 */  nop
.size func_004c40a0, 0x50
