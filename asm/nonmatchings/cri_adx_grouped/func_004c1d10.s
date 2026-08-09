.section .text
.set noat
.set noreorder
glabel func_004c1d10
    /* 3C1D10 004C1D10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C1D14 004C1D14 0000BFFF */  sd         $31, 0x0($29)
    /* 3C1D18 004C1D18 B400828C */  lw         $2, 0xB4($4)
    /* 3C1D1C 004C1D1C 05004010 */  beqz       $2, .L004C1D34
    /* 3C1D20 004C1D20 2D204000 */   daddu     $4, $2, $0
    /* 3C1D24 004C1D24 7100023C */  lui        $2, %hi(D_00714A10)
    /* 3C1D28 004C1D28 104A438C */  lw         $3, %lo(D_00714A10)($2)
    /* 3C1D2C 004C1D2C 09F86000 */  jalr       $3
    /* 3C1D30 004C1D30 00000000 */   nop
  .L004C1D34:
    /* 3C1D34 004C1D34 0000BFDF */  ld         $31, 0x0($29)
    /* 3C1D38 004C1D38 0800E003 */  jr         $31
    /* 3C1D3C 004C1D3C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c1d10, 0x30
