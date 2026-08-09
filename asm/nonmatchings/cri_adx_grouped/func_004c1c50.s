.section .text
.set noat
.set noreorder
glabel func_004c1c50
    /* 3C1C50 004C1C50 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C1C54 004C1C54 0000BFFF */  sd         $31, 0x0($29)
    /* 3C1C58 004C1C58 B400828C */  lw         $2, 0xB4($4)
    /* 3C1C5C 004C1C5C 05004010 */  beqz       $2, .L004C1C74
    /* 3C1C60 004C1C60 2D204000 */   daddu     $4, $2, $0
    /* 3C1C64 004C1C64 7100023C */  lui        $2, %hi(D_00714A08)
    /* 3C1C68 004C1C68 084A438C */  lw         $3, %lo(D_00714A08)($2)
    /* 3C1C6C 004C1C6C 09F86000 */  jalr       $3
    /* 3C1C70 004C1C70 00000000 */   nop
  .L004C1C74:
    /* 3C1C74 004C1C74 0000BFDF */  ld         $31, 0x0($29)
    /* 3C1C78 004C1C78 0800E003 */  jr         $31
    /* 3C1C7C 004C1C7C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c1c50, 0x30
