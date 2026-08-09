.section .text
.set noat
.set noreorder
glabel func_004bedf0
    /* 3BEDF0 004BEDF0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BEDF4 004BEDF4 0000BFFF */  sd         $31, 0x0($29)
    /* 3BEDF8 004BEDF8 5000828C */  lw         $2, 0x50($4)
    /* 3BEDFC 004BEDFC 06004054 */  bnel       $2, $0, .L004BEE18
    /* 3BEE00 004BEE00 0800828C */   lw        $2, 0x8($4)
    /* 3BEE04 004BEE04 7500043C */  lui        $4, %hi(D_00756EB0)
    /* 3BEE08 004BEE08 A8F5120C */  jal        func_004bd6a0
    /* 3BEE0C 004BEE0C B06E8424 */   addiu     $4, $4, %lo(D_00756EB0)
    /* 3BEE10 004BEE10 06000010 */  b          .L004BEE2C
    /* 3BEE14 004BEE14 04000224 */   addiu     $2, $0, 0x4
  .L004BEE18:
    /* 3BEE18 004BEE18 0000438C */  lw         $3, 0x0($2)
    /* 3BEE1C 004BEE1C 2D204000 */  daddu      $4, $2, $0
    /* 3BEE20 004BEE20 2000628C */  lw         $2, 0x20($3)
    /* 3BEE24 004BEE24 09F84000 */  jalr       $2
    /* 3BEE28 004BEE28 00000000 */   nop
  .L004BEE2C:
    /* 3BEE2C 004BEE2C 0000BFDF */  ld         $31, 0x0($29)
    /* 3BEE30 004BEE30 0800E003 */  jr         $31
    /* 3BEE34 004BEE34 1000BD27 */   addiu     $29, $29, 0x10
.size func_004bedf0, 0x48
