.section .text
.set noat
.set noreorder
glabel func_004bee38
    /* 3BEE38 004BEE38 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BEE3C 004BEE3C 0000BFFF */  sd         $31, 0x0($29)
    /* 3BEE40 004BEE40 5000828C */  lw         $2, 0x50($4)
    /* 3BEE44 004BEE44 06004054 */  bnel       $2, $0, .L004BEE60
    /* 3BEE48 004BEE48 0800828C */   lw        $2, 0x8($4)
    /* 3BEE4C 004BEE4C 7500043C */  lui        $4, %hi(D_00756EE8)
    /* 3BEE50 004BEE50 A8F5120C */  jal        func_004bd6a0
    /* 3BEE54 004BEE54 E86E8424 */   addiu     $4, $4, %lo(D_00756EE8)
    /* 3BEE58 004BEE58 06000010 */  b          .L004BEE74
    /* 3BEE5C 004BEE5C 04000224 */   addiu     $2, $0, 0x4
  .L004BEE60:
    /* 3BEE60 004BEE60 0000438C */  lw         $3, 0x0($2)
    /* 3BEE64 004BEE64 2D204000 */  daddu      $4, $2, $0
    /* 3BEE68 004BEE68 2400628C */  lw         $2, 0x24($3)
    /* 3BEE6C 004BEE6C 09F84000 */  jalr       $2
    /* 3BEE70 004BEE70 00000000 */   nop
  .L004BEE74:
    /* 3BEE74 004BEE74 0000BFDF */  ld         $31, 0x0($29)
    /* 3BEE78 004BEE78 0800E003 */  jr         $31
    /* 3BEE7C 004BEE7C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004bee38, 0x48
