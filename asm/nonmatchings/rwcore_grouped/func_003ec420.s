.section .text
.set noat
.set noreorder
glabel func_003ec420
    /* 2EC420 003EC420 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2EC424 003EC424 0000BFFF */  sd         $31, 0x0($29)
    /* 2EC428 003EC428 23008290 */  lbu        $2, 0x23($4)
    /* 2EC42C 003EC42C 00120200 */  sll        $2, $2, 8
    /* 2EC430 003EC430 00804230 */  andi       $2, $2, 0x8000
    /* 2EC434 003EC434 03004014 */  bnez       $2, .L003EC444
    /* 2EC438 003EC438 2D288000 */   daddu     $5, $4, $0
    /* 2EC43C 003EC43C 0B000010 */  b          .L003EC46C
    /* 2EC440 003EC440 01000224 */   addiu     $2, $0, 0x1
  .L003EC444:
    /* 2EC444 003EC444 8800023C */  lui        $2, %hi(D_00887398)
    /* 2EC448 003EC448 1C00A427 */  addiu      $4, $29, 0x1C
    /* 2EC44C 003EC44C 9873428C */  lw         $2, %lo(D_00887398)($2)
    /* 2EC450 003EC450 09F84000 */  jalr       $2
    /* 2EC454 003EC454 2D300000 */   daddu     $6, $0, $0
    /* 2EC458 003EC458 03004010 */  beqz       $2, .L003EC468
    /* 2EC45C 003EC45C 00000000 */   nop
    /* 2EC460 003EC460 02000010 */  b          .L003EC46C
    /* 2EC464 003EC464 1C00A28F */   lw        $2, 0x1C($29)
  .L003EC468:
    /* 2EC468 003EC468 FFFF0224 */  addiu      $2, $0, -0x1
  .L003EC46C:
    /* 2EC46C 003EC46C 0000BFDF */  ld         $31, 0x0($29)
    /* 2EC470 003EC470 0800E003 */  jr         $31
    /* 2EC474 003EC474 2000BD27 */   addiu     $29, $29, 0x20
    /* 2EC478 003EC478 00000000 */  nop
    /* 2EC47C 003EC47C 00000000 */  nop
.size func_003ec420, 0x60
