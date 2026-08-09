.section .text
.set noat
.set noreorder
glabel func_004bf718
    /* 3BF718 004BF718 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BF71C 004BF71C 0000BFFF */  sd         $31, 0x0($29)
    /* 3BF720 004BF720 5000828C */  lw         $2, 0x50($4)
    /* 3BF724 004BF724 06004054 */  bnel       $2, $0, .L004BF740
    /* 3BF728 004BF728 9400838C */   lw        $3, 0x94($4)
    /* 3BF72C 004BF72C 7500043C */  lui        $4, %hi(D_00757218)
    /* 3BF730 004BF730 A8F5120C */  jal        func_004bd6a0
    /* 3BF734 004BF734 18728424 */   addiu     $4, $4, %lo(D_00757218)
    /* 3BF738 004BF738 04000010 */  b          .L004BF74C
    /* 3BF73C 004BF73C 2D100000 */   daddu     $2, $0, $0
  .L004BF740:
    /* 3BF740 004BF740 02006010 */  beqz       $3, .L004BF74C
    /* 3BF744 004BF744 2D100000 */   daddu     $2, $0, $0
    /* 3BF748 004BF748 A000828C */  lw         $2, 0xA0($4)
  .L004BF74C:
    /* 3BF74C 004BF74C 0000BFDF */  ld         $31, 0x0($29)
    /* 3BF750 004BF750 0800E003 */  jr         $31
    /* 3BF754 004BF754 1000BD27 */   addiu     $29, $29, 0x10
.size func_004bf718, 0x40
