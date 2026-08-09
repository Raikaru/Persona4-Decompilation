.section .text
.set noat
.set noreorder
glabel func_002a1b20
    /* 1A1B20 002A1B20 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 1A1B24 002A1B24 1000BFFF */  sd         $31, 0x10($29)
    /* 1A1B28 002A1B28 0000B07F */  sq         $16, 0x0($29)
    /* 1A1B2C 002A1B2C 3800908C */  lw         $16, 0x38($4)
    /* 1A1B30 002A1B30 0800028E */  lw         $2, 0x8($16)
    /* 1A1B34 002A1B34 11004014 */  bnez       $2, .L002A1B7C
    /* 1A1B38 002A1B38 00000000 */   nop
    /* 1A1B3C 002A1B3C 78010426 */  addiu      $4, $16, 0x178
    /* 1A1B40 002A1B40 E0890A0C */  jal        func_002a2780
    /* 1A1B44 002A1B44 00000000 */   nop
    /* 1A1B48 002A1B48 78010426 */  addiu      $4, $16, 0x178
    /* 1A1B4C 002A1B4C 2D280000 */  daddu      $5, $0, $0
    /* 1A1B50 002A1B50 2D300000 */  daddu      $6, $0, $0
    /* 1A1B54 002A1B54 2D380000 */  daddu      $7, $0, $0
    /* 1A1B58 002A1B58 2D400000 */  daddu      $8, $0, $0
    /* 1A1B5C 002A1B5C 04828CC7 */  lwc1       $f12, -0x7DFC($28)
    /* 1A1B60 002A1B60 2D480000 */  daddu      $9, $0, $0
    /* 1A1B64 002A1B64 0A000A24 */  addiu      $10, $0, 0xA
    /* 1A1B68 002A1B68 14000B24 */  addiu      $11, $0, 0x14
    /* 1A1B6C 002A1B6C F0890A0C */  jal        func_002a27c0
    /* 1A1B70 002A1B70 00000000 */   nop
    /* 1A1B74 002A1B74 01000224 */  addiu      $2, $0, 0x1
    /* 1A1B78 002A1B78 080002AE */  sw         $2, 0x8($16)
  .L002A1B7C:
    /* 1A1B7C 002A1B7C 78010426 */  addiu      $4, $16, 0x178
    /* 1A1B80 002A1B80 608A0A0C */  jal        func_002a2980
    /* 1A1B84 002A1B84 00000000 */   nop
    /* 1A1B88 002A1B88 78010426 */  addiu      $4, $16, 0x178
    /* 1A1B8C 002A1B8C 1C8B0A0C */  jal        func_002a2c70
    /* 1A1B90 002A1B90 00000000 */   nop
    /* 1A1B94 002A1B94 05004014 */  bnez       $2, .L002A1BAC
    /* 1A1B98 002A1B98 00000000 */   nop
    /* 1A1B9C 002A1B9C 080000AE */  sw         $0, 0x8($16)
    /* 1A1BA0 002A1BA0 01000224 */  addiu      $2, $0, 0x1
    /* 1A1BA4 002A1BA4 02000010 */  b          .L002A1BB0
    /* 1A1BA8 002A1BA8 00000000 */   nop
  .L002A1BAC:
    /* 1A1BAC 002A1BAC 2D100000 */  daddu      $2, $0, $0
  .L002A1BB0:
    /* 1A1BB0 002A1BB0 1000BFDF */  ld         $31, 0x10($29)
    /* 1A1BB4 002A1BB4 0000B07B */  lq         $16, 0x0($29)
    /* 1A1BB8 002A1BB8 2000BD27 */  addiu      $29, $29, 0x20
    /* 1A1BBC 002A1BBC 0800E003 */  jr         $31
    /* 1A1BC0 002A1BC0 00000000 */   nop
    /* 1A1BC4 002A1BC4 00000000 */  nop
    /* 1A1BC8 002A1BC8 00000000 */  nop
    /* 1A1BCC 002A1BCC 00000000 */  nop
.size func_002a1b20, 0xb0
