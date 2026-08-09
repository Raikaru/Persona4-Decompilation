.section .text
.set noat
.set noreorder
glabel func_004bccf0
    /* 3BCCF0 004BCCF0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BCCF4 004BCCF4 38008684 */  lh         $6, 0x38($4)
    /* 3BCCF8 004BCCF8 02000324 */  addiu      $3, $0, 0x2
    /* 3BCCFC 004BCCFC 1500C310 */  beq        $6, $3, .L004BCD54
    /* 3BCD00 004BCD00 00000000 */   nop
    /* 3BCD04 004BCD04 01000324 */  addiu      $3, $0, 0x1
    /* 3BCD08 004BCD08 0B00C310 */  beq        $6, $3, .L004BCD38
    /* 3BCD0C 004BCD0C 00000000 */   nop
    /* 3BCD10 004BCD10 0300C010 */  beqz       $6, .L004BCD20
    /* 3BCD14 004BCD14 00000000 */   nop
    /* 3BCD18 004BCD18 13000010 */  b          .L004BCD68
    /* 3BCD1C 004BCD1C 00000000 */   nop
  .L004BCD20:
    /* 3BCD20 004BCD20 0000838C */  lw         $3, 0x0($4)
    /* 3BCD24 004BCD24 0C00638C */  lw         $3, 0xC($3)
    /* 3BCD28 004BCD28 40180300 */  sll        $3, $3, 1
    /* 3BCD2C 004BCD2C 01006724 */  addiu      $7, $3, 0x1
    /* 3BCD30 004BCD30 0D000010 */  b          .L004BCD68
    /* 3BCD34 004BCD34 00000000 */   nop
  .L004BCD38:
    /* 3BCD38 004BCD38 0000838C */  lw         $3, 0x0($4)
    /* 3BCD3C 004BCD3C 0C00648C */  lw         $4, 0xC($3)
    /* 3BCD40 004BCD40 40180400 */  sll        $3, $4, 1
    /* 3BCD44 004BCD44 21186400 */  addu       $3, $3, $4
    /* 3BCD48 004BCD48 06006724 */  addiu      $7, $3, 0x6
    /* 3BCD4C 004BCD4C 06000010 */  b          .L004BCD68
    /* 3BCD50 004BCD50 00000000 */   nop
  .L004BCD54:
    /* 3BCD54 004BCD54 0000838C */  lw         $3, 0x0($4)
    /* 3BCD58 004BCD58 0C00648C */  lw         $4, 0xC($3)
    /* 3BCD5C 004BCD5C 40180400 */  sll        $3, $4, 1
    /* 3BCD60 004BCD60 21186400 */  addu       $3, $3, $4
    /* 3BCD64 004BCD64 06006724 */  addiu      $7, $3, 0x6
  .L004BCD68:
    /* 3BCD68 004BCD68 3000A48C */  lw         $4, 0x30($5)
    /* 3BCD6C 004BCD6C 2D300000 */  daddu      $6, $0, $0
    /* 3BCD70 004BCD70 07000010 */  b          .L004BCD90
    /* 3BCD74 004BCD74 00000000 */   nop
  .L004BCD78:
    /* 3BCD78 004BCD78 000080A0 */  sb         $0, 0x0($4)
    /* 3BCD7C 004BCD7C 010080A0 */  sb         $0, 0x1($4)
    /* 3BCD80 004BCD80 020080A0 */  sb         $0, 0x2($4)
    /* 3BCD84 004BCD84 030080A0 */  sb         $0, 0x3($4)
    /* 3BCD88 004BCD88 0100C624 */  addiu      $6, $6, 0x1
    /* 3BCD8C 004BCD8C 04008424 */  addiu      $4, $4, 0x4
  .L004BCD90:
    /* 3BCD90 004BCD90 2A18C700 */  slt        $3, $6, $7
    /* 3BCD94 004BCD94 F8FF6014 */  bnez       $3, .L004BCD78
    /* 3BCD98 004BCD98 00000000 */   nop
    /* 3BCD9C 004BCD9C 5C00A38C */  lw         $3, 0x5C($5)
    /* 3BCDA0 004BCDA0 1400668C */  lw         $6, 0x14($3)
    /* 3BCDA4 004BCDA4 2D200000 */  daddu      $4, $0, $0
    /* 3BCDA8 004BCDA8 06000010 */  b          .L004BCDC4
    /* 3BCDAC 004BCDAC 00000000 */   nop
  .L004BCDB0:
    /* 3BCDB0 004BCDB0 0000C0AC */  sw         $0, 0x0($6)
    /* 3BCDB4 004BCDB4 0400C0AC */  sw         $0, 0x4($6)
    /* 3BCDB8 004BCDB8 0800C0AC */  sw         $0, 0x8($6)
    /* 3BCDBC 004BCDBC 01008424 */  addiu      $4, $4, 0x1
    /* 3BCDC0 004BCDC0 0C00C624 */  addiu      $6, $6, 0xC
  .L004BCDC4:
    /* 3BCDC4 004BCDC4 2A188700 */  slt        $3, $4, $7
    /* 3BCDC8 004BCDC8 F9FF6014 */  bnez       $3, .L004BCDB0
    /* 3BCDCC 004BCDCC 00000000 */   nop
    /* 3BCDD0 004BCDD0 0000A0AF */  sw         $0, 0x0($29)
    /* 3BCDD4 004BCDD4 0400A0AF */  sw         $0, 0x4($29)
    /* 3BCDD8 004BCDD8 0800A0AF */  sw         $0, 0x8($29)
    /* 3BCDDC 004BCDDC 9A3B033C */  lui        $3, (0x3B9ACA00 >> 16)
    /* 3BCDE0 004BCDE0 00CA6334 */  ori        $3, $3, (0x3B9ACA00 & 0xFFFF)
    /* 3BCDE4 004BCDE4 00008344 */  mtc1       $3, $f0
    /* 3BCDE8 004BCDE8 00000000 */  nop
    /* 3BCDEC 004BCDEC 20008046 */  cvt.s.w    $f0, $f0
    /* 3BCDF0 004BCDF0 0C00A0E7 */  swc1       $f0, 0xC($29)
    /* 3BCDF4 004BCDF4 5C00A38C */  lw         $3, 0x5C($5)
    /* 3BCDF8 004BCDF8 0000A3C7 */  lwc1       $f3, 0x0($29)
    /* 3BCDFC 004BCDFC 0400A2C7 */  lwc1       $f2, 0x4($29)
    /* 3BCE00 004BCE00 0800A1C7 */  lwc1       $f1, 0x8($29)
    /* 3BCE04 004BCE04 0C00A0C7 */  lwc1       $f0, 0xC($29)
    /* 3BCE08 004BCE08 040063E4 */  swc1       $f3, 0x4($3)
    /* 3BCE0C 004BCE0C 080062E4 */  swc1       $f2, 0x8($3)
    /* 3BCE10 004BCE10 0C0061E4 */  swc1       $f1, 0xC($3)
    /* 3BCE14 004BCE14 100060E4 */  swc1       $f0, 0x10($3)
    /* 3BCE18 004BCE18 1000BD27 */  addiu      $29, $29, 0x10
    /* 3BCE1C 004BCE1C 0800E003 */  jr         $31
    /* 3BCE20 004BCE20 00000000 */   nop
    /* 3BCE24 004BCE24 00000000 */  nop
    /* 3BCE28 004BCE28 00000000 */  nop
    /* 3BCE2C 004BCE2C 00000000 */  nop
.size func_004bccf0, 0x140
