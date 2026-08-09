.section .text
.set noat
.set noreorder
glabel func_003fb9d0
    /* 2FB9D0 003FB9D0 50EFBD27 */  addiu      $29, $29, -0x10B0
    /* 2FB9D4 003FB9D4 6000B67F */  sq         $22, 0x60($29)
    /* 2FB9D8 003FB9D8 5000B57F */  sq         $21, 0x50($29)
    /* 2FB9DC 003FB9DC 4000B47F */  sq         $20, 0x40($29)
    /* 2FB9E0 003FB9E0 3000B37F */  sq         $19, 0x30($29)
    /* 2FB9E4 003FB9E4 2000B27F */  sq         $18, 0x20($29)
    /* 2FB9E8 003FB9E8 1000B17F */  sq         $17, 0x10($29)
    /* 2FB9EC 003FB9EC 0000B07F */  sq         $16, 0x0($29)
    /* 2FB9F0 003FB9F0 1000838C */  lw         $3, 0x10($4)
    /* 2FB9F4 003FB9F4 2A080300 */  slt        $1, $0, $3
    /* 2FB9F8 003FB9F8 8B002010 */  beqz       $1, .L003FBC28
    /* 2FB9FC 003FB9FC 2D780000 */   daddu     $15, $0, $0
    /* 2FBA00 003FBA00 2A080300 */  slt        $1, $0, $3
    /* 2FBA04 003FBA04 88002010 */  beqz       $1, .L003FBC28
    /* 2FBA08 003FBA08 7000AC27 */   addiu     $12, $29, 0x70
    /* 2FBA0C 003FBA0C 8000AB27 */  addiu      $11, $29, 0x80
    /* 2FBA10 003FBA10 9000AA27 */  addiu      $10, $29, 0x90
    /* 2FBA14 003FBA14 A000A927 */  addiu      $9, $29, 0xA0
    /* 2FBA18 003FBA18 B000B127 */  addiu      $17, $29, 0xB0
  .L003FBA1C:
    /* 2FBA1C 003FBA1C 0C008D8C */  lw         $13, 0xC($4)
    /* 2FBA20 003FBA20 2A080D00 */  slt        $1, $0, $13
    /* 2FBA24 003FBA24 62002010 */  beqz       $1, .L003FBBB0
    /* 2FBA28 003FBA28 2DC00000 */   daddu     $24, $0, $0
    /* 2FBA2C 003FBA2C 1800878C */  lw         $7, 0x18($4)
    /* 2FBA30 003FBA30 2D700000 */  daddu      $14, $0, $0
    /* 2FBA34 003FBA34 0400868C */  lw         $6, 0x4($4)
    /* 2FBA38 003FBA38 0400E831 */  andi       $8, $15, 0x4
    /* 2FBA3C 003FBA3C 0200E525 */  addiu      $5, $15, 0x2
  .L003FBA40:
    /* 2FBA40 003FBA40 1818E701 */  mult       $3, $15, $7
    /* 2FBA44 003FBA44 2118C300 */  addu       $3, $6, $3
    /* 2FBA48 003FBA48 21186E00 */  addu       $3, $3, $14
    /* 2FBA4C 003FBA4C 00006378 */  lq         $3, 0x0($3)
    /* 2FBA50 003FBA50 7000A37F */  sq         $3, 0x70($29)
    /* 2FBA54 003FBA54 1818E771 */  mult1      $3, $15, $7
    /* 2FBA58 003FBA58 2118C300 */  addu       $3, $6, $3
    /* 2FBA5C 003FBA5C 21186E00 */  addu       $3, $3, $14
    /* 2FBA60 003FBA60 10006378 */  lq         $3, 0x10($3)
    /* 2FBA64 003FBA64 0000637D */  sq         $3, 0x0($11)
    /* 2FBA68 003FBA68 1818A700 */  mult       $3, $5, $7
    /* 2FBA6C 003FBA6C 2118C300 */  addu       $3, $6, $3
    /* 2FBA70 003FBA70 21186E00 */  addu       $3, $3, $14
    /* 2FBA74 003FBA74 00006378 */  lq         $3, 0x0($3)
    /* 2FBA78 003FBA78 0000437D */  sq         $3, 0x0($10)
    /* 2FBA7C 003FBA7C 1818A770 */  mult1      $3, $5, $7
    /* 2FBA80 003FBA80 2D800000 */  daddu      $16, $0, $0
    /* 2FBA84 003FBA84 2118C300 */  addu       $3, $6, $3
    /* 2FBA88 003FBA88 21686E00 */  addu       $13, $3, $14
    /* 2FBA8C 003FBA8C 1000AD79 */  lq         $13, 0x10($13)
    /* 2FBA90 003FBA90 21181D03 */  addu       $3, $24, $29
    /* 2FBA94 003FBA94 B0006324 */  addiu      $3, $3, 0xB0
    /* 2FBA98 003FBA98 00002D7D */  sq         $13, 0x0($9)
    /* 2FBA9C 003FBA9C 00000000 */  nop
  .L003FBAA0:
    /* 2FBAA0 003FBAA0 2DC80000 */  daddu      $25, $0, $0
    /* 2FBAA4 003FBAA4 21689001 */  addu       $13, $12, $16
  .L003FBAA8:
    /* 2FBAA8 003FBAA8 19000011 */  beqz       $8, .L003FBB10
    /* 2FBAAC 003FBAAC 00000000 */   nop
    /* 2FBAB0 003FBAB0 21A01902 */  addu       $20, $16, $25
    /* 2FBAB4 003FBAB4 02009332 */  andi       $19, $20, 0x2
    /* 2FBAB8 003FBAB8 04009232 */  andi       $18, $20, 0x4
    /* 2FBABC 003FBABC 80981300 */  sll        $19, $19, 2
    /* 2FBAC0 003FBAC0 83901200 */  sra        $18, $18, 2
    /* 2FBAC4 003FBAC4 25A87202 */  or         $21, $19, $18
    /* 2FBAC8 003FBAC8 08009232 */  andi       $18, $20, 0x8
    /* 2FBACC 003FBACC 83981200 */  sra        $19, $18, 2
    /* 2FBAD0 003FBAD0 10009232 */  andi       $18, $20, 0x10
    /* 2FBAD4 003FBAD4 25987502 */  or         $19, $19, $21
    /* 2FBAD8 003FBAD8 83901200 */  sra        $18, $18, 2
    /* 2FBADC 003FBADC 25A85302 */  or         $21, $18, $19
    /* 2FBAE0 003FBAE0 20009232 */  andi       $18, $20, 0x20
    /* 2FBAE4 003FBAE4 43981200 */  sra        $19, $18, 1
    /* 2FBAE8 003FBAE8 01009232 */  andi       $18, $20, 0x1
    /* 2FBAEC 003FBAEC 25987502 */  or         $19, $19, $21
    /* 2FBAF0 003FBAF0 27A08002 */  not        $20, $20
    /* 2FBAF4 003FBAF4 40911200 */  sll        $18, $18, 5
    /* 2FBAF8 003FBAF8 01009432 */  andi       $20, $20, 0x1
    /* 2FBAFC 003FBAFC 80A01400 */  sll        $20, $20, 2
    /* 2FBB00 003FBB00 25905402 */  or         $18, $18, $20
    /* 2FBB04 003FBB04 16000010 */  b          .L003FBB60
    /* 2FBB08 003FBB08 26A07202 */   xor       $20, $19, $18
    /* 2FBB0C 003FBB0C 00000000 */  nop
  .L003FBB10:
    /* 2FBB10 003FBB10 21A01902 */  addu       $20, $16, $25
    /* 2FBB14 003FBB14 02009232 */  andi       $18, $20, 0x2
    /* 2FBB18 003FBB18 04009532 */  andi       $21, $20, 0x4
    /* 2FBB1C 003FBB1C 83B01500 */  sra        $22, $21, 2
    /* 2FBB20 003FBB20 80901200 */  sll        $18, $18, 2
    /* 2FBB24 003FBB24 08009532 */  andi       $21, $20, 0x8
    /* 2FBB28 003FBB28 25B05602 */  or         $22, $18, $22
    /* 2FBB2C 003FBB2C 83901500 */  sra        $18, $21, 2
    /* 2FBB30 003FBB30 01009332 */  andi       $19, $20, 0x1
    /* 2FBB34 003FBB34 10009532 */  andi       $21, $20, 0x10
    /* 2FBB38 003FBB38 25905602 */  or         $18, $18, $22
    /* 2FBB3C 003FBB3C 83A81500 */  sra        $21, $21, 2
    /* 2FBB40 003FBB40 20009432 */  andi       $20, $20, 0x20
    /* 2FBB44 003FBB44 25A8B202 */  or         $21, $21, $18
    /* 2FBB48 003FBB48 43901400 */  sra        $18, $20, 1
    /* 2FBB4C 003FBB4C 25A85502 */  or         $21, $18, $21
    /* 2FBB50 003FBB50 40A11300 */  sll        $20, $19, 5
    /* 2FBB54 003FBB54 80901300 */  sll        $18, $19, 2
    /* 2FBB58 003FBB58 25909202 */  or         $18, $20, $18
    /* 2FBB5C 003FBB5C 26A0B202 */  xor        $20, $21, $18
  .L003FBB60:
    /* 2FBB60 003FBB60 0000B291 */  lbu        $18, 0x0($13)
    /* 2FBB64 003FBB64 03991400 */  sra        $19, $20, 4
    /* 2FBB68 003FBB68 01003927 */  addiu      $25, $25, 0x1
    /* 2FBB6C 003FBB6C 809A1300 */  sll        $19, $19, 10
    /* 2FBB70 003FBB70 0F009432 */  andi       $20, $20, 0xF
    /* 2FBB74 003FBB74 21A87300 */  addu       $21, $3, $19
    /* 2FBB78 003FBB78 21A0B402 */  addu       $20, $21, $20
    /* 2FBB7C 003FBB7C 1000332B */  slti       $19, $25, 0x10
    /* 2FBB80 003FBB80 000092A2 */  sb         $18, 0x0($20)
    /* 2FBB84 003FBB84 C8FF6016 */  bnez       $19, .L003FBAA8
    /* 2FBB88 003FBB88 0100AD25 */   addiu     $13, $13, 0x1
    /* 2FBB8C 003FBB8C 10001026 */  addiu      $16, $16, 0x10
    /* 2FBB90 003FBB90 40000D2A */  slti       $13, $16, 0x40
    /* 2FBB94 003FBB94 C2FFA015 */  bnez       $13, .L003FBAA0
    /* 2FBB98 003FBB98 00000000 */   nop
    /* 2FBB9C 003FBB9C 0C008D8C */  lw         $13, 0xC($4)
    /* 2FBBA0 003FBBA0 10001827 */  addiu      $24, $24, 0x10
    /* 2FBBA4 003FBBA4 2A180D03 */  slt        $3, $24, $13
    /* 2FBBA8 003FBBA8 A5FF6014 */  bnez       $3, .L003FBA40
    /* 2FBBAC 003FBBAC 2000CE25 */   addiu     $14, $14, 0x20
  .L003FBBB0:
    /* 2FBBB0 003FBBB0 2D800000 */  daddu      $16, $0, $0
    /* 2FBBB4 003FBBB4 2D702002 */  daddu      $14, $17, $0
  .L003FBBB8:
    /* 2FBBB8 003FBBB8 2A080D00 */  slt        $1, $0, $13
    /* 2FBBBC 003FBBBC 10002010 */  beqz       $1, .L003FBC00
    /* 2FBBC0 003FBBC0 2D400000 */   daddu     $8, $0, $0
    /* 2FBBC4 003FBBC4 2138F001 */  addu       $7, $15, $16
  .L003FBBC8:
    /* 2FBBC8 003FBBC8 2118C801 */  addu       $3, $14, $8
    /* 2FBBCC 003FBBCC 00006678 */  lq         $6, 0x0($3)
    /* 2FBBD0 003FBBD0 1800838C */  lw         $3, 0x18($4)
    /* 2FBBD4 003FBBD4 18286700 */  mult       $5, $3, $7
    /* 2FBBD8 003FBBD8 0400838C */  lw         $3, 0x4($4)
    /* 2FBBDC 003FBBDC 21186500 */  addu       $3, $3, $5
    /* 2FBBE0 003FBBE0 21186800 */  addu       $3, $3, $8
    /* 2FBBE4 003FBBE4 0000667C */  sq         $6, 0x0($3)
    /* 2FBBE8 003FBBE8 10000825 */  addiu      $8, $8, 0x10
    /* 2FBBEC 003FBBEC 0C008D8C */  lw         $13, 0xC($4)
    /* 2FBBF0 003FBBF0 2A180D01 */  slt        $3, $8, $13
    /* 2FBBF4 003FBBF4 F4FF6014 */  bnez       $3, .L003FBBC8
    /* 2FBBF8 003FBBF8 00000000 */   nop
    /* 2FBBFC 003FBBFC 00000000 */  nop
  .L003FBC00:
    /* 2FBC00 003FBC00 01001026 */  addiu      $16, $16, 0x1
    /* 2FBC04 003FBC04 0400032A */  slti       $3, $16, 0x4
    /* 2FBC08 003FBC08 EBFF6014 */  bnez       $3, .L003FBBB8
    /* 2FBC0C 003FBC0C 0004CE25 */   addiu     $14, $14, 0x400
    /* 2FBC10 003FBC10 1000838C */  lw         $3, 0x10($4)
    /* 2FBC14 003FBC14 0400EF25 */  addiu      $15, $15, 0x4
    /* 2FBC18 003FBC18 2A18E301 */  slt        $3, $15, $3
    /* 2FBC1C 003FBC1C 7FFF6014 */  bnez       $3, .L003FBA1C
    /* 2FBC20 003FBC20 00000000 */   nop
    /* 2FBC24 003FBC24 00000000 */  nop
  .L003FBC28:
    /* 2FBC28 003FBC28 6000B67B */  lq         $22, 0x60($29)
    /* 2FBC2C 003FBC2C 5000B57B */  lq         $21, 0x50($29)
    /* 2FBC30 003FBC30 4000B47B */  lq         $20, 0x40($29)
    /* 2FBC34 003FBC34 3000B37B */  lq         $19, 0x30($29)
    /* 2FBC38 003FBC38 2000B27B */  lq         $18, 0x20($29)
    /* 2FBC3C 003FBC3C 1000B17B */  lq         $17, 0x10($29)
    /* 2FBC40 003FBC40 0000B07B */  lq         $16, 0x0($29)
    /* 2FBC44 003FBC44 0800E003 */  jr         $31
    /* 2FBC48 003FBC48 B010BD27 */   addiu     $29, $29, 0x10B0
    /* 2FBC4C 003FBC4C 00000000 */  nop
.size func_003fb9d0, 0x280
