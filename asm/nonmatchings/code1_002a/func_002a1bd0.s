.section .text
.set noat
.set noreorder
glabel func_002a1bd0
    /* 1A1BD0 002A1BD0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 1A1BD4 002A1BD4 1000BFFF */  sd         $31, 0x10($29)
    /* 1A1BD8 002A1BD8 0000B07F */  sq         $16, 0x0($29)
    /* 1A1BDC 002A1BDC 3800908C */  lw         $16, 0x38($4)
    /* 1A1BE0 002A1BE0 0800028E */  lw         $2, 0x8($16)
    /* 1A1BE4 002A1BE4 11004014 */  bnez       $2, .L002A1C2C
    /* 1A1BE8 002A1BE8 00000000 */   nop
    /* 1A1BEC 002A1BEC 10020426 */  addiu      $4, $16, 0x210
    /* 1A1BF0 002A1BF0 E0890A0C */  jal        func_002a2780
    /* 1A1BF4 002A1BF4 00000000 */   nop
    /* 1A1BF8 002A1BF8 10020426 */  addiu      $4, $16, 0x210
    /* 1A1BFC 002A1BFC 12000524 */  addiu      $5, $0, 0x12
    /* 1A1C00 002A1C00 F9000624 */  addiu      $6, $0, 0xF9
    /* 1A1C04 002A1C04 2D38A000 */  daddu      $7, $5, $0
    /* 1A1C08 002A1C08 DB000824 */  addiu      $8, $0, 0xDB
    /* 1A1C0C 002A1C0C 04828CC7 */  lwc1       $f12, -0x7DFC($28)
    /* 1A1C10 002A1C10 2D480000 */  daddu      $9, $0, $0
    /* 1A1C14 002A1C14 2D500000 */  daddu      $10, $0, $0
    /* 1A1C18 002A1C18 0A000B24 */  addiu      $11, $0, 0xA
    /* 1A1C1C 002A1C1C F0890A0C */  jal        func_002a27c0
    /* 1A1C20 002A1C20 00000000 */   nop
    /* 1A1C24 002A1C24 01000224 */  addiu      $2, $0, 0x1
    /* 1A1C28 002A1C28 080002AE */  sw         $2, 0x8($16)
  .L002A1C2C:
    /* 1A1C2C 002A1C2C 10020426 */  addiu      $4, $16, 0x210
    /* 1A1C30 002A1C30 608A0A0C */  jal        func_002a2980
    /* 1A1C34 002A1C34 00000000 */   nop
    /* 1A1C38 002A1C38 10020426 */  addiu      $4, $16, 0x210
    /* 1A1C3C 002A1C3C 1C8B0A0C */  jal        func_002a2c70
    /* 1A1C40 002A1C40 00000000 */   nop
    /* 1A1C44 002A1C44 05004014 */  bnez       $2, .L002A1C5C
    /* 1A1C48 002A1C48 00000000 */   nop
    /* 1A1C4C 002A1C4C 080000AE */  sw         $0, 0x8($16)
    /* 1A1C50 002A1C50 01000224 */  addiu      $2, $0, 0x1
    /* 1A1C54 002A1C54 02000010 */  b          .L002A1C60
    /* 1A1C58 002A1C58 00000000 */   nop
  .L002A1C5C:
    /* 1A1C5C 002A1C5C 2D100000 */  daddu      $2, $0, $0
  .L002A1C60:
    /* 1A1C60 002A1C60 1000BFDF */  ld         $31, 0x10($29)
    /* 1A1C64 002A1C64 0000B07B */  lq         $16, 0x0($29)
    /* 1A1C68 002A1C68 2000BD27 */  addiu      $29, $29, 0x20
    /* 1A1C6C 002A1C6C 0800E003 */  jr         $31
    /* 1A1C70 002A1C70 00000000 */   nop
    /* 1A1C74 002A1C74 00000000 */  nop
    /* 1A1C78 002A1C78 00000000 */  nop
    /* 1A1C7C 002A1C7C 00000000 */  nop
.size func_002a1bd0, 0xb0
