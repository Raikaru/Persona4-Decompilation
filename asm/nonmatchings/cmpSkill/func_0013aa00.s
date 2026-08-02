.section .text
.set noat
.set noreorder
glabel func_0013aa00
    /* 3AA00 0013AA00 2D380000 */  daddu      $7, $0, $0
    /* 3AA04 0013AA04 C841053C */  lui        $5, (0x41C80000 >> 16)
    /* 3AA08 0013AA08 1B000010 */  b          .L0013AA78
    /* 3AA0C 0013AA0C 00000000 */   nop
  .L0013AA10:
    /* 3AA10 0013AA10 40180700 */  sll        $3, $7, 1
    /* 3AA14 0013AA14 21186700 */  addu       $3, $3, $7
    /* 3AA18 0013AA18 00190300 */  sll        $3, $3, 4
    /* 3AA1C 0013AA1C 21308300 */  addu       $6, $4, $3
    /* 3AA20 0013AA20 140AC0C4 */  lwc1       $f0, 0xA14($6)
    /* 3AA24 0013AA24 040AC0E4 */  swc1       $f0, 0xA04($6)
    /* 3AA28 0013AA28 180AC0C4 */  lwc1       $f0, 0xA18($6)
    /* 3AA2C 0013AA2C 080AC0E4 */  swc1       $f0, 0xA08($6)
    /* 3AA30 0013AA30 1E0AC390 */  lbu        $3, 0xA1E($6)
    /* 3AA34 0013AA34 1C0AC3A0 */  sb         $3, 0xA1C($6)
    /* 3AA38 0013AA38 D40AC0C4 */  lwc1       $f0, 0xAD4($6)
    /* 3AA3C 0013AA3C C40AC0E4 */  swc1       $f0, 0xAC4($6)
    /* 3AA40 0013AA40 D80AC0C4 */  lwc1       $f0, 0xAD8($6)
    /* 3AA44 0013AA44 C80AC0E4 */  swc1       $f0, 0xAC8($6)
    /* 3AA48 0013AA48 DE0AC390 */  lbu        $3, 0xADE($6)
    /* 3AA4C 0013AA4C DC0AC3A0 */  sb         $3, 0xADC($6)
    /* 3AA50 0013AA50 62008384 */  lh         $3, 0x62($4)
    /* 3AA54 0013AA54 05006714 */  bne        $3, $7, .L0013AA6C
    /* 3AA58 0013AA58 00000000 */   nop
    /* 3AA5C 0013AA5C 0C0AC5AC */  sw         $5, 0xA0C($6)
    /* 3AA60 0013AA60 CC0AC5AC */  sw         $5, 0xACC($6)
    /* 3AA64 0013AA64 03000010 */  b          .L0013AA74
    /* 3AA68 0013AA68 00000000 */   nop
  .L0013AA6C:
    /* 3AA6C 0013AA6C 0C0AC0AC */  sw         $0, 0xA0C($6)
    /* 3AA70 0013AA70 CC0AC0AC */  sw         $0, 0xACC($6)
  .L0013AA74:
    /* 3AA74 0013AA74 0100E724 */  addiu      $7, $7, 0x1
  .L0013AA78:
    /* 3AA78 0013AA78 0400E328 */  slti       $3, $7, 0x4
    /* 3AA7C 0013AA7C E4FF6014 */  bnez       $3, .L0013AA10
    /* 3AA80 0013AA80 00000000 */   nop
    /* 3AA84 0013AA84 200080A4 */  sh         $0, 0x20($4)
    /* 3AA88 0013AA88 0800E003 */  jr         $31
    /* 3AA8C 0013AA8C 00000000 */   nop
.size func_0013aa00, 0x90
