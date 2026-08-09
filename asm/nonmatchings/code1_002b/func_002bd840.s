.section .text
.set noat
.set noreorder
glabel func_002bd840
    /* 1BD840 002BD840 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 1BD844 002BD844 2000BFFF */  sd         $31, 0x20($29)
    /* 1BD848 002BD848 1000B17F */  sq         $17, 0x10($29)
    /* 1BD84C 002BD84C 0000B07F */  sq         $16, 0x0($29)
    /* 1BD850 002BD850 2D888000 */  daddu      $17, $4, $0
    /* 1BD854 002BD854 8800103C */  lui        $16, %hi(D_00882F60)
    /* 1BD858 002BD858 602F1026 */  addiu      $16, $16, %lo(D_00882F60)
    /* 1BD85C 002BD85C 0000048E */  lw         $4, 0x0($16)
    /* 1BD860 002BD860 04008104 */  bgez       $4, .L002BD874
    /* 1BD864 002BD864 00000000 */   nop
    /* 1BD868 002BD868 2D100000 */  daddu      $2, $0, $0
    /* 1BD86C 002BD86C 14000010 */  b          .L002BD8C0
    /* 1BD870 002BD870 00000000 */   nop
  .L002BD874:
    /* 1BD874 002BD874 01000524 */  addiu      $5, $0, 0x1
    /* 1BD878 002BD878 84E1090C */  jal        func_00278610
    /* 1BD87C 002BD87C 00000000 */   nop
    /* 1BD880 002BD880 0000048E */  lw         $4, 0x0($16)
    /* 1BD884 002BD884 2000053C */  lui        $5, (0x200000 >> 16)
    /* 1BD888 002BD888 5CE0090C */  jal        func_00278170
    /* 1BD88C 002BD88C 00000000 */   nop
    /* 1BD890 002BD890 0000048E */  lw         $4, 0x0($16)
    /* 1BD894 002BD894 2D282002 */  daddu      $5, $17, $0
    /* 1BD898 002BD898 2D300000 */  daddu      $6, $0, $0
    /* 1BD89C 002BD89C 30DE090C */  jal        func_002778c0
    /* 1BD8A0 002BD8A0 00000000 */   nop
    /* 1BD8A4 002BD8A4 01000224 */  addiu      $2, $0, 0x1
    /* 1BD8A8 002BD8A8 040002A2 */  sb         $2, 0x4($16)
    /* 1BD8AC 002BD8AC 0000048E */  lw         $4, 0x0($16)
    /* 1BD8B0 002BD8B0 FFFF0524 */  addiu      $5, $0, -0x1
    /* 1BD8B4 002BD8B4 04DC090C */  jal        func_00277010
    /* 1BD8B8 002BD8B8 00000000 */   nop
    /* 1BD8BC 002BD8BC 01000224 */  addiu      $2, $0, 0x1
  .L002BD8C0:
    /* 1BD8C0 002BD8C0 2000BFDF */  ld         $31, 0x20($29)
    /* 1BD8C4 002BD8C4 1000B17B */  lq         $17, 0x10($29)
    /* 1BD8C8 002BD8C8 0000B07B */  lq         $16, 0x0($29)
    /* 1BD8CC 002BD8CC 3000BD27 */  addiu      $29, $29, 0x30
    /* 1BD8D0 002BD8D0 0800E003 */  jr         $31
    /* 1BD8D4 002BD8D4 00000000 */   nop
    /* 1BD8D8 002BD8D8 00000000 */  nop
    /* 1BD8DC 002BD8DC 00000000 */  nop
.size func_002bd840, 0xa0
