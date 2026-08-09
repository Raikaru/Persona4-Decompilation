.section .text
.set noat
.set noreorder
glabel func_004c1a68
    /* 3C1A68 004C1A68 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C1A6C 004C1A6C 0000BFFF */  sd         $31, 0x0($29)
    /* 3C1A70 004C1A70 C000828C */  lw         $2, 0xC0($4)
    /* 3C1A74 004C1A74 05004010 */  beqz       $2, .L004C1A8C
    /* 3C1A78 004C1A78 2D204000 */   daddu     $4, $2, $0
    /* 3C1A7C 004C1A7C 7100023C */  lui        $2, %hi(D_007149F8)
    /* 3C1A80 004C1A80 F849438C */  lw         $3, %lo(D_007149F8)($2)
    /* 3C1A84 004C1A84 09F86000 */  jalr       $3
    /* 3C1A88 004C1A88 00000000 */   nop
  .L004C1A8C:
    /* 3C1A8C 004C1A8C 0000BFDF */  ld         $31, 0x0($29)
    /* 3C1A90 004C1A90 0800E003 */  jr         $31
    /* 3C1A94 004C1A94 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c1a68, 0x30
