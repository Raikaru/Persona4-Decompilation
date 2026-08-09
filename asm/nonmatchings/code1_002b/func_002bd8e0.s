.section .text
.set noat
.set noreorder
glabel func_002bd8e0
    /* 1BD8E0 002BD8E0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 1BD8E4 002BD8E4 2000BFFF */  sd         $31, 0x20($29)
    /* 1BD8E8 002BD8E8 1000B17F */  sq         $17, 0x10($29)
    /* 1BD8EC 002BD8EC 0000B07F */  sq         $16, 0x0($29)
    /* 1BD8F0 002BD8F0 3800908C */  lw         $16, 0x38($4)
    /* 1BD8F4 002BD8F4 00000382 */  lb         $3, 0x0($16)
    /* 1BD8F8 002BD8F8 23000224 */  addiu      $2, $0, 0x23
    /* 1BD8FC 002BD8FC 78006210 */  beq        $3, $2, .L002BDAE0
    /* 1BD900 002BD900 00000000 */   nop
    /* 1BD904 002BD904 11000224 */  addiu      $2, $0, 0x11
    /* 1BD908 002BD908 72006210 */  beq        $3, $2, .L002BDAD4
    /* 1BD90C 002BD90C 00000000 */   nop
    /* 1BD910 002BD910 07000224 */  addiu      $2, $0, 0x7
    /* 1BD914 002BD914 65006210 */  beq        $3, $2, .L002BDAAC
    /* 1BD918 002BD918 00000000 */   nop
    /* 1BD91C 002BD91C 06000224 */  addiu      $2, $0, 0x6
    /* 1BD920 002BD920 5A006210 */  beq        $3, $2, .L002BDA8C
    /* 1BD924 002BD924 00000000 */   nop
    /* 1BD928 002BD928 05000224 */  addiu      $2, $0, 0x5
    /* 1BD92C 002BD92C 51006210 */  beq        $3, $2, .L002BDA74
    /* 1BD930 002BD930 00000000 */   nop
    /* 1BD934 002BD934 04000524 */  addiu      $5, $0, 0x4
    /* 1BD938 002BD938 42006510 */  beq        $3, $5, .L002BDA44
    /* 1BD93C 002BD93C 00000000 */   nop
    /* 1BD940 002BD940 03000224 */  addiu      $2, $0, 0x3
    /* 1BD944 002BD944 39006210 */  beq        $3, $2, .L002BDA2C
    /* 1BD948 002BD948 00000000 */   nop
    /* 1BD94C 002BD94C 02000224 */  addiu      $2, $0, 0x2
    /* 1BD950 002BD950 0B006210 */  beq        $3, $2, .L002BD980
    /* 1BD954 002BD954 00000000 */   nop
    /* 1BD958 002BD958 01000224 */  addiu      $2, $0, 0x1
    /* 1BD95C 002BD95C 03006210 */  beq        $3, $2, .L002BD96C
    /* 1BD960 002BD960 00000000 */   nop
    /* 1BD964 002BD964 61000010 */  b          .L002BDAEC
    /* 1BD968 002BD968 00000000 */   nop
  .L002BD96C:
    /* 1BD96C 002BD96C 08000424 */  addiu      $4, $0, 0x8
    /* 1BD970 002BD970 2413050C */  jal        func_00144c90
    /* 1BD974 002BD974 00000000 */   nop
    /* 1BD978 002BD978 02000224 */  addiu      $2, $0, 0x2
    /* 1BD97C 002BD97C 000002A2 */  sb         $2, 0x0($16)
  .L002BD980:
    /* 1BD980 002BD980 D813050C */  jal        func_00144f60
    /* 1BD984 002BD984 00000000 */   nop
    /* 1BD988 002BD988 58004010 */  beqz       $2, .L002BDAEC
    /* 1BD98C 002BD98C 00000000 */   nop
    /* 1BD990 002BD990 987D050C */  jal        func_0015f660
    /* 1BD994 002BD994 00000000 */   nop
    /* 1BD998 002BD998 54004010 */  beqz       $2, .L002BDAEC
    /* 1BD99C 002BD99C 00000000 */   nop
    /* 1BD9A0 002BD9A0 0400048E */  lw         $4, 0x4($16)
    /* 1BD9A4 002BD9A4 A82D0B0C */  jal        func_002cb6a0
    /* 1BD9A8 002BD9A8 00000000 */   nop
    /* 1BD9AC 002BD9AC 04004014 */  bnez       $2, .L002BD9C0
    /* 1BD9B0 002BD9B0 00000000 */   nop
    /* 1BD9B4 002BD9B4 2D100000 */  daddu      $2, $0, $0
    /* 1BD9B8 002BD9B8 4D000010 */  b          .L002BDAF0
    /* 1BD9BC 002BD9BC 00000000 */   nop
  .L002BD9C0:
    /* 1BD9C0 002BD9C0 15000424 */  addiu      $4, $0, 0x15
    /* 1BD9C4 002BD9C4 01000524 */  addiu      $5, $0, 0x1
    /* 1BD9C8 002BD9C8 F868110C */  jal        func_0045a3e0
    /* 1BD9CC 002BD9CC 00000000 */   nop
    /* 1BD9D0 002BD9D0 485C110C */  jal        func_00457120
    /* 1BD9D4 002BD9D4 00000000 */   nop
    /* 1BD9D8 002BD9D8 2D884000 */  daddu      $17, $2, $0
    /* 1BD9DC 002BD9DC 342D050C */  jal        func_0014b4d0
    /* 1BD9E0 002BD9E0 00000000 */   nop
    /* 1BD9E4 002BD9E4 2D202002 */  daddu      $4, $17, $0
    /* 1BD9E8 002BD9E8 06030046 */  mov.s      $f12, $f0
    /* 1BD9EC 002BD9EC F45D110C */  jal        func_004577d0
    /* 1BD9F0 002BD9F0 00000000 */   nop
    /* 1BD9F4 002BD9F4 485C110C */  jal        func_00457120
    /* 1BD9F8 002BD9F8 00000000 */   nop
    /* 1BD9FC 002BD9FC 2D884000 */  daddu      $17, $2, $0
    /* 1BDA00 002BDA00 142D050C */  jal        func_0014b450
    /* 1BDA04 002BDA04 00000000 */   nop
    /* 1BDA08 002BDA08 0400248E */  lw         $4, 0x4($17)
    /* 1BDA0C 002BDA0C 2D284000 */  daddu      $5, $2, $0
    /* 1BDA10 002BDA10 2D300000 */  daddu      $6, $0, $0
    /* 1BDA14 002BDA14 2CA70F0C */  jal        func_003e9cb0
    /* 1BDA18 002BDA18 00000000 */   nop
    /* 1BDA1C 002BDA1C 03000224 */  addiu      $2, $0, 0x3
    /* 1BDA20 002BDA20 000002A2 */  sb         $2, 0x0($16)
    /* 1BDA24 002BDA24 31000010 */  b          .L002BDAEC
    /* 1BDA28 002BDA28 00000000 */   nop
  .L002BDA2C:
    /* 1BDA2C 002BDA2C 01000424 */  addiu      $4, $0, 0x1
    /* 1BDA30 002BDA30 2D280000 */  daddu      $5, $0, $0
    /* 1BDA34 002BDA34 9089040C */  jal        func_00122640
    /* 1BDA38 002BDA38 00000000 */   nop
    /* 1BDA3C 002BDA3C 04000224 */  addiu      $2, $0, 0x4
    /* 1BDA40 002BDA40 000002A2 */  sb         $2, 0x0($16)
  .L002BDA44:
    /* 1BDA44 002BDA44 C889040C */  jal        func_00122720
    /* 1BDA48 002BDA48 00000000 */   nop
    /* 1BDA4C 002BDA4C 27004010 */  beqz       $2, .L002BDAEC
    /* 1BDA50 002BDA50 00000000 */   nop
    /* 1BDA54 002BDA54 0400048E */  lw         $4, 0x4($16)
    /* 1BDA58 002BDA58 0D000524 */  addiu      $5, $0, 0xD
    /* 1BDA5C 002BDA5C 802A0B0C */  jal        func_002caa00
    /* 1BDA60 002BDA60 00000000 */   nop
    /* 1BDA64 002BDA64 07000224 */  addiu      $2, $0, 0x7
    /* 1BDA68 002BDA68 000002A2 */  sb         $2, 0x0($16)
    /* 1BDA6C 002BDA6C 1F000010 */  b          .L002BDAEC
    /* 1BDA70 002BDA70 00000000 */   nop
  .L002BDA74:
    /* 1BDA74 002BDA74 01000424 */  addiu      $4, $0, 0x1
    /* 1BDA78 002BDA78 2D280000 */  daddu      $5, $0, $0
    /* 1BDA7C 002BDA7C 4889040C */  jal        func_00122520
    /* 1BDA80 002BDA80 00000000 */   nop
    /* 1BDA84 002BDA84 06000224 */  addiu      $2, $0, 0x6
    /* 1BDA88 002BDA88 000002A2 */  sb         $2, 0x0($16)
  .L002BDA8C:
    /* 1BDA8C 002BDA8C C889040C */  jal        func_00122720
    /* 1BDA90 002BDA90 00000000 */   nop
    /* 1BDA94 002BDA94 15004010 */  beqz       $2, .L002BDAEC
    /* 1BDA98 002BDA98 00000000 */   nop
    /* 1BDA9C 002BDA9C 11000224 */  addiu      $2, $0, 0x11
    /* 1BDAA0 002BDAA0 000002A2 */  sb         $2, 0x0($16)
    /* 1BDAA4 002BDAA4 11000010 */  b          .L002BDAEC
    /* 1BDAA8 002BDAA8 00000000 */   nop
  .L002BDAAC:
    /* 1BDAAC 002BDAAC 6400043C */  lui        $4, %hi(D_0063F3B0)
    /* 1BDAB0 002BDAB0 B0F38424 */  addiu      $4, $4, %lo(D_0063F3B0)
    /* 1BDAB4 002BDAB4 E048110C */  jal        func_00452380
    /* 1BDAB8 002BDAB8 00000000 */   nop
    /* 1BDABC 002BDABC 0B004014 */  bnez       $2, .L002BDAEC
    /* 1BDAC0 002BDAC0 00000000 */   nop
    /* 1BDAC4 002BDAC4 05000224 */  addiu      $2, $0, 0x5
    /* 1BDAC8 002BDAC8 000002A2 */  sb         $2, 0x0($16)
    /* 1BDACC 002BDACC 07000010 */  b          .L002BDAEC
    /* 1BDAD0 002BDAD0 00000000 */   nop
  .L002BDAD4:
    /* 1BDAD4 002BDAD4 FFFF0224 */  addiu      $2, $0, -0x1
    /* 1BDAD8 002BDAD8 05000010 */  b          .L002BDAF0
    /* 1BDADC 002BDADC 00000000 */   nop
  .L002BDAE0:
    /* 1BDAE0 002BDAE0 FFFF0224 */  addiu      $2, $0, -0x1
    /* 1BDAE4 002BDAE4 02000010 */  b          .L002BDAF0
    /* 1BDAE8 002BDAE8 00000000 */   nop
  .L002BDAEC:
    /* 1BDAEC 002BDAEC 2D100000 */  daddu      $2, $0, $0
  .L002BDAF0:
    /* 1BDAF0 002BDAF0 2000BFDF */  ld         $31, 0x20($29)
    /* 1BDAF4 002BDAF4 1000B17B */  lq         $17, 0x10($29)
    /* 1BDAF8 002BDAF8 0000B07B */  lq         $16, 0x0($29)
    /* 1BDAFC 002BDAFC 3000BD27 */  addiu      $29, $29, 0x30
    /* 1BDB00 002BDB00 0800E003 */  jr         $31
    /* 1BDB04 002BDB04 00000000 */   nop
    /* 1BDB08 002BDB08 00000000 */  nop
    /* 1BDB0C 002BDB0C 00000000 */  nop
.size func_002bd8e0, 0x230
