.section .text
.set noat
.set noreorder
glabel func_004eb890
    /* 3EB890 004EB890 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3EB894 004EB894 7400023C */  lui        $2, %hi(D_0073CBA0)
    /* 3EB898 004EB898 0800B1FF */  sd         $17, 0x8($29)
    /* 3EB89C 004EB89C 2D88A000 */  daddu      $17, $5, $0
    /* 3EB8A0 004EB8A0 10002F26 */  addiu      $15, $17, 0x10
    /* 3EB8A4 004EB8A4 7400033C */  lui        $3, %hi(D_0073A774)
    /* 3EB8A8 004EB8A8 7400043C */  lui        $4, %hi(D_007397A0)
    /* 3EB8AC 004EB8AC 0000B0FF */  sd         $16, 0x0($29)
    /* 3EB8B0 004EB8B0 1000B2FF */  sd         $18, 0x10($29)
    /* 3EB8B4 004EB8B4 A0979224 */  addiu      $18, $4, %lo(D_007397A0)
    /* 3EB8B8 004EB8B8 1800B3FF */  sd         $19, 0x18($29)
    /* 3EB8BC 004EB8BC 74A77324 */  addiu      $19, $3, %lo(D_0073A774)
    /* 3EB8C0 004EB8C0 A0CB4724 */  addiu      $7, $2, %lo(D_0073CBA0)
    /* 3EB8C4 004EB8C4 2D500000 */  daddu      $10, $0, $0
    /* 3EB8C8 004EB8C8 2DC00000 */  daddu      $24, $0, $0
    /* 3EB8CC 004EB8CC 01001024 */  addiu      $16, $0, 0x1
    /* 3EB8D0 004EB8D0 02001924 */  addiu      $25, $0, 0x2
    /* 3EB8D4 004EB8D4 2D30E001 */  daddu      $6, $15, $0
  .L004EB8D8:
    /* 3EB8D8 004EB8D8 0000E280 */  lb         $2, 0x0($7)
    /* 3EB8DC 004EB8DC BD005054 */  bnel       $2, $16, .L004EBBD4
    /* 3EB8E0 004EB8E0 01001827 */   addiu     $24, $24, 0x1
    /* 3EB8E4 004EB8E4 80000824 */  addiu      $8, $0, 0x80
    /* 3EB8E8 004EB8E8 BD004811 */  beq        $10, $8, .L004EBBE0
    /* 3EB8EC 004EB8EC 7400033C */   lui       $3, %hi(D_0073A778)
    /* 3EB8F0 004EB8F0 0000648E */  lw         $4, 0x0($19)
    /* 3EB8F4 004EB8F4 78A76324 */  addiu      $3, $3, %lo(D_0073A778)
    /* 3EB8F8 004EB8F8 0000628C */  lw         $2, 0x0($3)
    /* 3EB8FC 004EB8FC 07008210 */  beq        $4, $2, .L004EB91C
    /* 3EB900 004EB900 0B000224 */   addiu     $2, $0, 0xB
    /* 3EB904 004EB904 0400C0AC */  sw         $0, 0x4($6)
    /* 3EB908 004EB908 0000C2A4 */  sh         $2, 0x0($6)
    /* 3EB90C 004EB90C 01004A25 */  addiu      $10, $10, 0x1
    /* 3EB910 004EB910 0800C4AC */  sw         $4, 0x8($6)
    /* 3EB914 004EB914 1000C624 */  addiu      $6, $6, 0x10
    /* 3EB918 004EB918 000064AC */  sw         $4, 0x0($3)
  .L004EB91C:
    /* 3EB91C 004EB91C B1004851 */  beql       $10, $8, .L004EBBE4
    /* 3EB920 004EB920 00002AAE */   sw        $10, 0x0($17)
    /* 3EB924 004EB924 5B00E380 */  lb         $3, 0x5B($7)
    /* 3EB928 004EB928 5A00E280 */  lb         $2, 0x5A($7)
    /* 3EB92C 004EB92C 0A006210 */  beq        $3, $2, .L004EB958
    /* 3EB930 004EB930 08000224 */   addiu     $2, $0, 0x8
    /* 3EB934 004EB934 2000E38C */  lw         $3, 0x20($7)
    /* 3EB938 004EB938 0000C2A4 */  sh         $2, 0x0($6)
    /* 3EB93C 004EB93C 01004A25 */  addiu      $10, $10, 0x1
    /* 3EB940 004EB940 0400C3AC */  sw         $3, 0x4($6)
    /* 3EB944 004EB944 5B00E280 */  lb         $2, 0x5B($7)
    /* 3EB948 004EB948 0800C2AC */  sw         $2, 0x8($6)
    /* 3EB94C 004EB94C 1000C624 */  addiu      $6, $6, 0x10
    /* 3EB950 004EB950 5B00E290 */  lbu        $2, 0x5B($7)
    /* 3EB954 004EB954 5A00E2A0 */  sb         $2, 0x5A($7)
  .L004EB958:
    /* 3EB958 004EB958 A1004811 */  beq        $10, $8, .L004EBBE0
    /* 3EB95C 004EB95C 00010224 */   addiu     $2, $0, 0x100
    /* 3EB960 004EB960 5000E394 */  lhu        $3, 0x50($7)
    /* 3EB964 004EB964 0A006214 */  bne        $3, $2, .L004EB990
    /* 3EB968 004EB968 00000000 */   nop
    /* 3EB96C 004EB96C 2000E28C */  lw         $2, 0x20($7)
    /* 3EB970 004EB970 01004A25 */  addiu      $10, $10, 0x1
    /* 3EB974 004EB974 0000D9A4 */  sh         $25, 0x0($6)
    /* 3EB978 004EB978 0400C2AC */  sw         $2, 0x4($6)
    /* 3EB97C 004EB97C 5000E380 */  lb         $3, 0x50($7)
    /* 3EB980 004EB980 0800C3AC */  sw         $3, 0x8($6)
    /* 3EB984 004EB984 1000C624 */  addiu      $6, $6, 0x10
    /* 3EB988 004EB988 5000E290 */  lbu        $2, 0x50($7)
    /* 3EB98C 004EB98C 5100E2A0 */  sb         $2, 0x51($7)
  .L004EB990:
    /* 3EB990 004EB990 94004851 */  beql       $10, $8, .L004EBBE4
    /* 3EB994 004EB994 00002AAE */   sw        $10, 0x0($17)
    /* 3EB998 004EB998 5400E380 */  lb         $3, 0x54($7)
    /* 3EB99C 004EB99C 5500E280 */  lb         $2, 0x55($7)
    /* 3EB9A0 004EB9A0 0A006210 */  beq        $3, $2, .L004EB9CC
    /* 3EB9A4 004EB9A4 0A000224 */   addiu     $2, $0, 0xA
    /* 3EB9A8 004EB9A8 2000E38C */  lw         $3, 0x20($7)
    /* 3EB9AC 004EB9AC 0000C2A4 */  sh         $2, 0x0($6)
    /* 3EB9B0 004EB9B0 01004A25 */  addiu      $10, $10, 0x1
    /* 3EB9B4 004EB9B4 0400C3AC */  sw         $3, 0x4($6)
    /* 3EB9B8 004EB9B8 5400E280 */  lb         $2, 0x54($7)
    /* 3EB9BC 004EB9BC 0800C2AC */  sw         $2, 0x8($6)
    /* 3EB9C0 004EB9C0 1000C624 */  addiu      $6, $6, 0x10
    /* 3EB9C4 004EB9C4 5400E290 */  lbu        $2, 0x54($7)
    /* 3EB9C8 004EB9C8 5500E2A0 */  sb         $2, 0x55($7)
  .L004EB9CC:
    /* 3EB9CC 004EB9CC 85004851 */  beql       $10, $8, .L004EBBE4
    /* 3EB9D0 004EB9D0 00002AAE */   sw        $10, 0x0($17)
    /* 3EB9D4 004EB9D4 5600E380 */  lb         $3, 0x56($7)
    /* 3EB9D8 004EB9D8 5700E280 */  lb         $2, 0x57($7)
    /* 3EB9DC 004EB9DC 0A006210 */  beq        $3, $2, .L004EBA08
    /* 3EB9E0 004EB9E0 0C000224 */   addiu     $2, $0, 0xC
    /* 3EB9E4 004EB9E4 2000E38C */  lw         $3, 0x20($7)
    /* 3EB9E8 004EB9E8 0000C2A4 */  sh         $2, 0x0($6)
    /* 3EB9EC 004EB9EC 01004A25 */  addiu      $10, $10, 0x1
    /* 3EB9F0 004EB9F0 0400C3AC */  sw         $3, 0x4($6)
    /* 3EB9F4 004EB9F4 5600E280 */  lb         $2, 0x56($7)
    /* 3EB9F8 004EB9F8 0800C2AC */  sw         $2, 0x8($6)
    /* 3EB9FC 004EB9FC 1000C624 */  addiu      $6, $6, 0x10
    /* 3EBA00 004EBA00 5600E290 */  lbu        $2, 0x56($7)
    /* 3EBA04 004EBA04 5700E2A0 */  sb         $2, 0x57($7)
  .L004EBA08:
    /* 3EBA08 004EBA08 76004851 */  beql       $10, $8, .L004EBBE4
    /* 3EBA0C 004EBA0C 00002AAE */   sw        $10, 0x0($17)
    /* 3EBA10 004EBA10 5200E380 */  lb         $3, 0x52($7)
    /* 3EBA14 004EBA14 5300E280 */  lb         $2, 0x53($7)
    /* 3EBA18 004EBA18 0A006210 */  beq        $3, $2, .L004EBA44
    /* 3EBA1C 004EBA1C 03000224 */   addiu     $2, $0, 0x3
    /* 3EBA20 004EBA20 2000E38C */  lw         $3, 0x20($7)
    /* 3EBA24 004EBA24 0000C2A4 */  sh         $2, 0x0($6)
    /* 3EBA28 004EBA28 01004A25 */  addiu      $10, $10, 0x1
    /* 3EBA2C 004EBA2C 0400C3AC */  sw         $3, 0x4($6)
    /* 3EBA30 004EBA30 5200E280 */  lb         $2, 0x52($7)
    /* 3EBA34 004EBA34 0800C2AC */  sw         $2, 0x8($6)
    /* 3EBA38 004EBA38 1000C624 */  addiu      $6, $6, 0x10
    /* 3EBA3C 004EBA3C 5200E290 */  lbu        $2, 0x52($7)
    /* 3EBA40 004EBA40 5300E2A0 */  sb         $2, 0x53($7)
  .L004EBA44:
    /* 3EBA44 004EBA44 67004851 */  beql       $10, $8, .L004EBBE4
    /* 3EBA48 004EBA48 00002AAE */   sw        $10, 0x0($17)
    /* 3EBA4C 004EBA4C 3000E38C */  lw         $3, 0x30($7)
    /* 3EBA50 004EBA50 3400E28C */  lw         $2, 0x34($7)
    /* 3EBA54 004EBA54 09006210 */  beq        $3, $2, .L004EBA7C
    /* 3EBA58 004EBA58 04000224 */   addiu     $2, $0, 0x4
    /* 3EBA5C 004EBA5C 0800C3AC */  sw         $3, 0x8($6)
    /* 3EBA60 004EBA60 2000E48C */  lw         $4, 0x20($7)
    /* 3EBA64 004EBA64 01004A25 */  addiu      $10, $10, 0x1
    /* 3EBA68 004EBA68 3000E38C */  lw         $3, 0x30($7)
    /* 3EBA6C 004EBA6C 0000C2A4 */  sh         $2, 0x0($6)
    /* 3EBA70 004EBA70 3400E3AC */  sw         $3, 0x34($7)
    /* 3EBA74 004EBA74 0400C4AC */  sw         $4, 0x4($6)
    /* 3EBA78 004EBA78 1000C624 */  addiu      $6, $6, 0x10
  .L004EBA7C:
    /* 3EBA7C 004EBA7C 59004851 */  beql       $10, $8, .L004EBBE4
    /* 3EBA80 004EBA80 00002AAE */   sw        $10, 0x0($17)
    /* 3EBA84 004EBA84 3800E38C */  lw         $3, 0x38($7)
    /* 3EBA88 004EBA88 3C00E28C */  lw         $2, 0x3C($7)
    /* 3EBA8C 004EBA8C 0D006210 */  beq        $3, $2, .L004EBAC4
    /* 3EBA90 004EBA90 80100300 */   sll       $2, $3, 2
    /* 3EBA94 004EBA94 2000E58C */  lw         $5, 0x20($7)
    /* 3EBA98 004EBA98 23104202 */  subu       $2, $18, $2
    /* 3EBA9C 004EBA9C 05000424 */  addiu      $4, $0, 0x5
    /* 3EBAA0 004EBAA0 0000438C */  lw         $3, 0x0($2)
    /* 3EBAA4 004EBAA4 01004A25 */  addiu      $10, $10, 0x1
    /* 3EBAA8 004EBAA8 0800C0AC */  sw         $0, 0x8($6)
    /* 3EBAAC 004EBAAC 0C00C3AC */  sw         $3, 0xC($6)
    /* 3EBAB0 004EBAB0 0000C4A4 */  sh         $4, 0x0($6)
    /* 3EBAB4 004EBAB4 3800E28C */  lw         $2, 0x38($7)
    /* 3EBAB8 004EBAB8 0400C5AC */  sw         $5, 0x4($6)
    /* 3EBABC 004EBABC 1000C624 */  addiu      $6, $6, 0x10
    /* 3EBAC0 004EBAC0 3C00E2AC */  sw         $2, 0x3C($7)
  .L004EBAC4:
    /* 3EBAC4 004EBAC4 46004811 */  beq        $10, $8, .L004EBBE0
    /* 3EBAC8 004EBAC8 7F000224 */   addiu     $2, $0, 0x7F
    /* 3EBACC 004EBACC 45004251 */  beql       $10, $2, .L004EBBE4
    /* 3EBAD0 004EBAD0 00002AAE */   sw        $10, 0x0($17)
    /* 3EBAD4 004EBAD4 5200E280 */  lb         $2, 0x52($7)
    /* 3EBAD8 004EBAD8 2D600000 */  daddu      $12, $0, $0
    /* 3EBADC 004EBADC 1F004018 */  blez       $2, .L004EBB5C
    /* 3EBAE0 004EBAE0 5200E990 */   lbu       $9, 0x52($7)
    /* 3EBAE4 004EBAE4 00110A00 */  sll        $2, $10, 4
    /* 3EBAE8 004EBAE8 0800ED24 */  addiu      $13, $7, 0x8
    /* 3EBAEC 004EBAEC 21204F00 */  addu       $4, $2, $15
    /* 3EBAF0 004EBAF0 09000E24 */  addiu      $14, $0, 0x9
    /* 3EBAF4 004EBAF4 40000B24 */  addiu      $11, $0, 0x40
    /* 3EBAF8 004EBAF8 2128EB00 */  addu       $5, $7, $11
    /* 3EBAFC 004EBAFC 00000000 */  nop
  .L004EBB00:
    /* 3EBB00 004EBB00 2140AB01 */  addu       $8, $13, $11
    /* 3EBB04 004EBB04 0000A38C */  lw         $3, 0x0($5)
    /* 3EBB08 004EBB08 0000028D */  lw         $2, 0x0($8)
    /* 3EBB0C 004EBB0C 0D006210 */  beq        $3, $2, .L004EBB44
    /* 3EBB10 004EBB10 04006B25 */   addiu     $11, $11, 0x4
    /* 3EBB14 004EBB14 08008CAC */  sw         $12, 0x8($4)
    /* 3EBB18 004EBB18 1000C624 */  addiu      $6, $6, 0x10
    /* 3EBB1C 004EBB1C 2000E38C */  lw         $3, 0x20($7)
    /* 3EBB20 004EBB20 01004A25 */  addiu      $10, $10, 0x1
    /* 3EBB24 004EBB24 0000A28C */  lw         $2, 0x0($5)
    /* 3EBB28 004EBB28 00008EA4 */  sh         $14, 0x0($4)
    /* 3EBB2C 004EBB2C 0C0082AC */  sw         $2, 0xC($4)
    /* 3EBB30 004EBB30 040083AC */  sw         $3, 0x4($4)
    /* 3EBB34 004EBB34 10008424 */  addiu      $4, $4, 0x10
    /* 3EBB38 004EBB38 0000A28C */  lw         $2, 0x0($5)
    /* 3EBB3C 004EBB3C 000002AD */  sw         $2, 0x0($8)
    /* 3EBB40 004EBB40 5200E990 */  lbu        $9, 0x52($7)
  .L004EBB44:
    /* 3EBB44 004EBB44 00160900 */  sll        $2, $9, 24
    /* 3EBB48 004EBB48 01008C25 */  addiu      $12, $12, 0x1
    /* 3EBB4C 004EBB4C 03160200 */  sra        $2, $2, 24
    /* 3EBB50 004EBB50 2A108201 */  slt        $2, $12, $2
    /* 3EBB54 004EBB54 EAFF4014 */  bnez       $2, .L004EBB00
    /* 3EBB58 004EBB58 2128EB00 */   addu      $5, $7, $11
  .L004EBB5C:
    /* 3EBB5C 004EBB5C 5C00E38C */  lw         $3, 0x5C($7)
    /* 3EBB60 004EBB60 6000E28C */  lw         $2, 0x60($7)
    /* 3EBB64 004EBB64 09006210 */  beq        $3, $2, .L004EBB8C
    /* 3EBB68 004EBB68 0D000224 */   addiu     $2, $0, 0xD
    /* 3EBB6C 004EBB6C 0800C3AC */  sw         $3, 0x8($6)
    /* 3EBB70 004EBB70 2000E48C */  lw         $4, 0x20($7)
    /* 3EBB74 004EBB74 01004A25 */  addiu      $10, $10, 0x1
    /* 3EBB78 004EBB78 5C00E38C */  lw         $3, 0x5C($7)
    /* 3EBB7C 004EBB7C 0000C2A4 */  sh         $2, 0x0($6)
    /* 3EBB80 004EBB80 6000E3AC */  sw         $3, 0x60($7)
    /* 3EBB84 004EBB84 0400C4AC */  sw         $4, 0x4($6)
    /* 3EBB88 004EBB88 1000C624 */  addiu      $6, $6, 0x10
  .L004EBB8C:
    /* 3EBB8C 004EBB8C 80000424 */  addiu      $4, $0, 0x80
    /* 3EBB90 004EBB90 14004451 */  beql       $10, $4, .L004EBBE4
    /* 3EBB94 004EBB94 00002AAE */   sw        $10, 0x0($17)
    /* 3EBB98 004EBB98 5000E294 */  lhu        $2, 0x50($7)
    /* 3EBB9C 004EBB9C 0A005014 */  bne        $2, $16, .L004EBBC8
    /* 3EBBA0 004EBBA0 00000000 */   nop
    /* 3EBBA4 004EBBA4 2000E28C */  lw         $2, 0x20($7)
    /* 3EBBA8 004EBBA8 01004A25 */  addiu      $10, $10, 0x1
    /* 3EBBAC 004EBBAC 0000D9A4 */  sh         $25, 0x0($6)
    /* 3EBBB0 004EBBB0 0400C2AC */  sw         $2, 0x4($6)
    /* 3EBBB4 004EBBB4 5000E380 */  lb         $3, 0x50($7)
    /* 3EBBB8 004EBBB8 0800C3AC */  sw         $3, 0x8($6)
    /* 3EBBBC 004EBBBC 1000C624 */  addiu      $6, $6, 0x10
    /* 3EBBC0 004EBBC0 5000E290 */  lbu        $2, 0x50($7)
    /* 3EBBC4 004EBBC4 5100E2A0 */  sb         $2, 0x51($7)
  .L004EBBC8:
    /* 3EBBC8 004EBBC8 06004451 */  beql       $10, $4, .L004EBBE4
    /* 3EBBCC 004EBBCC 00002AAE */   sw        $10, 0x0($17)
    /* 3EBBD0 004EBBD0 01001827 */  addiu      $24, $24, 0x1
  .L004EBBD4:
    /* 3EBBD4 004EBBD4 1000022B */  slti       $2, $24, 0x10
    /* 3EBBD8 004EBBD8 3FFF4014 */  bnez       $2, .L004EB8D8
    /* 3EBBDC 004EBBDC 6400E724 */   addiu     $7, $7, 0x64
  .L004EBBE0:
    /* 3EBBE0 004EBBE0 00002AAE */  sw         $10, 0x0($17)
  .L004EBBE4:
    /* 3EBBE4 004EBBE4 0000B0DF */  ld         $16, 0x0($29)
    /* 3EBBE8 004EBBE8 0800B1DF */  ld         $17, 0x8($29)
    /* 3EBBEC 004EBBEC 1000B2DF */  ld         $18, 0x10($29)
    /* 3EBBF0 004EBBF0 1800B3DF */  ld         $19, 0x18($29)
    /* 3EBBF4 004EBBF4 0800E003 */  jr         $31
    /* 3EBBF8 004EBBF8 2000BD27 */   addiu     $29, $29, 0x20
    /* 3EBBFC 004EBBFC 00000000 */  nop
.size func_004eb890, 0x370
