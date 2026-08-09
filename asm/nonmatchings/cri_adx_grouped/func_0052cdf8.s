.section .text
.set noat
.set noreorder
glabel func_0052cdf8
    /* 42CDF8 0052CDF8 7400023C */  lui        $2, %hi(D_007463A8)
    /* 42CDFC 0052CDFC A8634224 */  addiu      $2, $2, %lo(D_007463A8)
    /* 42CE00 0052CE00 0000438C */  lw         $3, 0x0($2)
    /* 42CE04 0052CE04 02006018 */  blez       $3, .L0052CE10
    /* 42CE08 0052CE08 FFFF6424 */   addiu     $4, $3, -0x1
    /* 42CE0C 0052CE0C 000044AC */  sw         $4, 0x0($2)
  .L0052CE10:
    /* 42CE10 0052CE10 0800E003 */  jr         $31
    /* 42CE14 0052CE14 00000000 */   nop
.size func_0052cdf8, 0x20
