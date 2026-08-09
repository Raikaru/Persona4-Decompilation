.section .text
.set noat
.set noreorder
glabel func_002bc860
    /* 1BC860 002BC860 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1BC864 002BC864 0000BFFF */  sd         $31, 0x0($29)
    /* 1BC868 002BC868 2D48E000 */  daddu      $9, $7, $0
    /* 1BC86C 002BC86C 01000724 */  addiu      $7, $0, 0x1
    /* 1BC870 002BC870 6400023C */  lui        $2, %hi(D_0063F2C8)
    /* 1BC874 002BC874 C8F2488C */  lw         $8, %lo(D_0063F2C8)($2)
    /* 1BC878 002BC878 7CE4090C */  jal        func_002791f0
    /* 1BC87C 002BC87C 00000000 */   nop
    /* 1BC880 002BC880 0000BFDF */  ld         $31, 0x0($29)
    /* 1BC884 002BC884 1000BD27 */  addiu      $29, $29, 0x10
    /* 1BC888 002BC888 0800E003 */  jr         $31
    /* 1BC88C 002BC88C 00000000 */   nop
.size func_002bc860, 0x30
