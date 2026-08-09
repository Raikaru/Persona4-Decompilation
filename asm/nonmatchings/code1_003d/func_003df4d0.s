.section .text
.set noat
.set noreorder
glabel func_003df4d0
    /* 2DF4D0 003DF4D0 60B7838F */  lw         $3, -0x48A0($28)
    /* 2DF4D4 003DF4D4 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2DF4D8 003DF4D8 E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2DF4DC 003DF4DC 21284300 */  addu       $5, $2, $3
    /* 2DF4E0 003DF4E0 0000A28C */  lw         $2, 0x0($5)
    /* 2DF4E4 003DF4E4 11004014 */  bnez       $2, .L003DF52C
    /* 2DF4E8 003DF4E8 00000000 */   nop
    /* 2DF4EC 003DF4EC 0400A28C */  lw         $2, 0x4($5)
    /* 2DF4F0 003DF4F0 0080033C */  lui        $3, (0x80000000 >> 16)
    /* 2DF4F4 003DF4F4 0D004314 */  bne        $2, $3, .L003DF52C
    /* 2DF4F8 003DF4F8 00000000 */   nop
    /* 2DF4FC 003DF4FC 0400828C */  lw         $2, 0x4($4)
    /* 2DF500 003DF500 24104300 */  and        $2, $2, $3
    /* 2DF504 003DF504 0B004014 */  bnez       $2, .L003DF534
    /* 2DF508 003DF508 00000000 */   nop
    /* 2DF50C 003DF50C 0000828C */  lw         $2, 0x0($4)
    /* 2DF510 003DF510 0000A2AC */  sw         $2, 0x0($5)
  .L003DF514:
    /* 2DF514 003DF514 60B7838F */  lw         $3, -0x48A0($28)
    /* 2DF518 003DF518 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2DF51C 003DF51C 0400858C */  lw         $5, 0x4($4)
    /* 2DF520 003DF520 E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2DF524 003DF524 21104300 */  addu       $2, $2, $3
    /* 2DF528 003DF528 040045AC */  sw         $5, 0x4($2)
  .L003DF52C:
    /* 2DF52C 003DF52C 03000010 */  b          .L003DF53C
    /* 2DF530 003DF530 2D108000 */   daddu     $2, $4, $0
  .L003DF534:
    /* 2DF534 003DF534 F7FF0010 */  b          .L003DF514
    /* 2DF538 003DF538 0000A0AC */   sw        $0, 0x0($5)
  .L003DF53C:
    /* 2DF53C 003DF53C 0800E003 */  jr         $31
    /* 2DF540 003DF540 00000000 */   nop
    /* 2DF544 003DF544 00000000 */  nop
    /* 2DF548 003DF548 00000000 */  nop
    /* 2DF54C 003DF54C 00000000 */  nop
.size func_003df4d0, 0x80
