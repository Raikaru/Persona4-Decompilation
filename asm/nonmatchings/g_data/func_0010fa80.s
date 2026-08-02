.section .text
.set noat
.set noreorder
glabel func_0010fa80
    /* FA80 0010FA80 80FFBD27 */  addiu      $29, $29, -0x80
    /* FA84 0010FA84 7000BFFF */  sd         $31, 0x70($29)
    /* FA88 0010FA88 6000B67F */  sq         $22, 0x60($29)
    /* FA8C 0010FA8C 5000B57F */  sq         $21, 0x50($29)
    /* FA90 0010FA90 4000B47F */  sq         $20, 0x40($29)
    /* FA94 0010FA94 3000B37F */  sq         $19, 0x30($29)
    /* FA98 0010FA98 2000B27F */  sq         $18, 0x20($29)
    /* FA9C 0010FA9C 1000B17F */  sq         $17, 0x10($29)
    /* FAA0 0010FAA0 0000B07F */  sq         $16, 0x0($29)
    /* FAA4 0010FAA4 2DA8A000 */  daddu      $21, $5, $0
    /* FAA8 0010FAA8 2DA0C000 */  daddu      $20, $6, $0
    /* FAAC 0010FAAC 2D98E000 */  daddu      $19, $7, $0
    /* FAB0 0010FAB0 2D900001 */  daddu      $18, $8, $0
    /* FAB4 0010FAB4 2D882001 */  daddu      $17, $9, $0
    /* FAB8 0010FAB8 2DB04001 */  daddu      $22, $10, $0
    /* FABC 0010FABC 3C840400 */  dsll32     $16, $4, 16
    /* FAC0 0010FAC0 3F841000 */  dsra32     $16, $16, 16
    /* FAC4 0010FAC4 01000224 */  addiu      $2, $0, 0x1
    /* FAC8 0010FAC8 05000216 */  bne        $16, $2, .L0010FAE0
    /* FACC 0010FACC 00000000 */   nop
    /* FAD0 0010FAD0 7900103C */  lui        $16, %hi(D_007973C4)
    /* FAD4 0010FAD4 C4731026 */  addiu      $16, $16, %lo(D_007973C4)
    /* FAD8 0010FAD8 11000010 */  b          .L0010FB20
    /* FADC 0010FADC 00000000 */   nop
  .L0010FAE0:
    /* FAE0 0010FAE0 0B00022A */  slti       $2, $16, 0xB
    /* FAE4 0010FAE4 06004014 */  bnez       $2, .L0010FB00
    /* FAE8 0010FAE8 00000000 */   nop
    /* FAEC 0010FAEC 5E00043C */  lui        $4, %hi(D_005E4298)
    /* FAF0 0010FAF0 98428424 */  addiu      $4, $4, %lo(D_005E4298)
    /* FAF4 0010FAF4 34020524 */  addiu      $5, $0, 0x234
    /* FAF8 0010FAF8 CCB5110C */  jal        func_0046d730
    /* FAFC 0010FAFC 00000000 */   nop
  .L0010FB00:
    /* FB00 0010FB00 FEFF0326 */  addiu      $3, $16, -0x2
    /* FB04 0010FB04 00110300 */  sll        $2, $3, 4
    /* FB08 0010FB08 21104300 */  addu       $2, $2, $3
    /* FB0C 0010FB0C C0180200 */  sll        $3, $2, 3
    /* FB10 0010FB10 7900023C */  lui        $2, %hi(D_00796E50)
    /* FB14 0010FB14 506E4224 */  addiu      $2, $2, %lo(D_00796E50)
    /* FB18 0010FB18 21104300 */  addu       $2, $2, $3
    /* FB1C 0010FB1C 04005024 */  addiu      $16, $2, 0x4
  .L0010FB20:
    /* FB20 0010FB20 3CAC1500 */  dsll32     $21, $21, 16
    /* FB24 0010FB24 3FAC1500 */  dsra32     $21, $21, 16
    /* FB28 0010FB28 01000224 */  addiu      $2, $0, 0x1
    /* FB2C 0010FB2C 0500A216 */  bne        $21, $2, .L0010FB44
    /* FB30 0010FB30 00000000 */   nop
    /* FB34 0010FB34 7900063C */  lui        $6, %hi(D_007973C4)
    /* FB38 0010FB38 C473C624 */  addiu      $6, $6, %lo(D_007973C4)
    /* FB3C 0010FB3C 11000010 */  b          .L0010FB84
    /* FB40 0010FB40 00000000 */   nop
  .L0010FB44:
    /* FB44 0010FB44 0B00A22A */  slti       $2, $21, 0xB
    /* FB48 0010FB48 06004014 */  bnez       $2, .L0010FB64
    /* FB4C 0010FB4C 00000000 */   nop
    /* FB50 0010FB50 5E00043C */  lui        $4, %hi(D_005E4298)
    /* FB54 0010FB54 98428424 */  addiu      $4, $4, %lo(D_005E4298)
    /* FB58 0010FB58 34020524 */  addiu      $5, $0, 0x234
    /* FB5C 0010FB5C CCB5110C */  jal        func_0046d730
    /* FB60 0010FB60 00000000 */   nop
  .L0010FB64:
    /* FB64 0010FB64 FEFFA326 */  addiu      $3, $21, -0x2
    /* FB68 0010FB68 00110300 */  sll        $2, $3, 4
    /* FB6C 0010FB6C 21104300 */  addu       $2, $2, $3
    /* FB70 0010FB70 C0180200 */  sll        $3, $2, 3
    /* FB74 0010FB74 7900023C */  lui        $2, %hi(D_00796E50)
    /* FB78 0010FB78 506E4224 */  addiu      $2, $2, %lo(D_00796E50)
    /* FB7C 0010FB7C 21104300 */  addu       $2, $2, $3
    /* FB80 0010FB80 04004624 */  addiu      $6, $2, 0x4
  .L0010FB84:
    /* FB84 0010FB84 2D208002 */  daddu      $4, $20, $0
    /* FB88 0010FB88 2D280002 */  daddu      $5, $16, $0
    /* FB8C 0010FB8C 2D386002 */  daddu      $7, $19, $0
    /* FB90 0010FB90 2D404002 */  daddu      $8, $18, $0
    /* FB94 0010FB94 2D482002 */  daddu      $9, $17, $0
    /* FB98 0010FB98 2D50C002 */  daddu      $10, $22, $0
    /* FB9C 0010FB9C 24E9080C */  jal        func_0023a490
    /* FBA0 0010FBA0 00000000 */   nop
    /* FBA4 0010FBA4 7000BFDF */  ld         $31, 0x70($29)
    /* FBA8 0010FBA8 6000B67B */  lq         $22, 0x60($29)
    /* FBAC 0010FBAC 5000B57B */  lq         $21, 0x50($29)
    /* FBB0 0010FBB0 4000B47B */  lq         $20, 0x40($29)
    /* FBB4 0010FBB4 3000B37B */  lq         $19, 0x30($29)
    /* FBB8 0010FBB8 2000B27B */  lq         $18, 0x20($29)
    /* FBBC 0010FBBC 1000B17B */  lq         $17, 0x10($29)
    /* FBC0 0010FBC0 0000B07B */  lq         $16, 0x0($29)
    /* FBC4 0010FBC4 8000BD27 */  addiu      $29, $29, 0x80
    /* FBC8 0010FBC8 0800E003 */  jr         $31
    /* FBCC 0010FBCC 00000000 */   nop
.size func_0010fa80, 0x150
