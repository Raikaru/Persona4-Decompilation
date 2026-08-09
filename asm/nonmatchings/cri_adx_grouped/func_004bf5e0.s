.section .text
.set noat
.set noreorder
glabel func_004bf5e0
    /* 3BF5E0 004BF5E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BF5E4 004BF5E4 0000BFFF */  sd         $31, 0x0($29)
    /* 3BF5E8 004BF5E8 5000828C */  lw         $2, 0x50($4)
    /* 3BF5EC 004BF5EC 06004054 */  bnel       $2, $0, .L004BF608
    /* 3BF5F0 004BF5F0 9400838C */   lw        $3, 0x94($4)
    /* 3BF5F4 004BF5F4 7500043C */  lui        $4, %hi(D_00757178)
    /* 3BF5F8 004BF5F8 A8F5120C */  jal        func_004bd6a0
    /* 3BF5FC 004BF5FC 78718424 */   addiu     $4, $4, %lo(D_00757178)
    /* 3BF600 004BF600 09000010 */  b          .L004BF628
    /* 3BF604 004BF604 2D100000 */   daddu     $2, $0, $0
  .L004BF608:
    /* 3BF608 004BF608 07006010 */  beqz       $3, .L004BF628
    /* 3BF60C 004BF60C 2D100000 */   daddu     $2, $0, $0
    /* 3BF610 004BF610 0800828C */  lw         $2, 0x8($4)
    /* 3BF614 004BF614 0000438C */  lw         $3, 0x0($2)
    /* 3BF618 004BF618 2D204000 */  daddu      $4, $2, $0
    /* 3BF61C 004BF61C 3C00628C */  lw         $2, 0x3C($3)
    /* 3BF620 004BF620 09F84000 */  jalr       $2
    /* 3BF624 004BF624 00000000 */   nop
  .L004BF628:
    /* 3BF628 004BF628 0000BFDF */  ld         $31, 0x0($29)
    /* 3BF62C 004BF62C 0800E003 */  jr         $31
    /* 3BF630 004BF630 1000BD27 */   addiu     $29, $29, 0x10
    /* 3BF634 004BF634 00000000 */  nop
.size func_004bf5e0, 0x58
