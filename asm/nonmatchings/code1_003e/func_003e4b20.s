.section .text
.set noat
.set noreorder
glabel func_003e4b20
    /* 2E4B20 003E4B20 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 2E4B24 003E4B24 3000BFFF */  sd         $31, 0x30($29)
    /* 2E4B28 003E4B28 2000B27F */  sq         $18, 0x20($29)
    /* 2E4B2C 003E4B2C 1000B17F */  sq         $17, 0x10($29)
    /* 2E4B30 003E4B30 0000B07F */  sq         $16, 0x0($29)
    /* 2E4B34 003E4B34 2D888000 */  daddu      $17, $4, $0
    /* 2E4B38 003E4B38 15002012 */  beqz       $17, .L003E4B90
    /* 2E4B3C 003E4B3C 2D80A000 */   daddu     $16, $5, $0
  .L003E4B40:
    /* 2E4B40 003E4B40 16002012 */  beqz       $17, .L003E4B9C
    /* 2E4B44 003E4B44 2D202002 */   daddu     $4, $17, $0
  .L003E4B48:
    /* 2E4B48 003E4B48 8800023C */  lui        $2, %hi(D_008873D4)
    /* 2E4B4C 003E4B4C D473428C */  lw         $2, %lo(D_008873D4)($2)
    /* 2E4B50 003E4B50 09F84000 */  jalr       $2
    /* 2E4B54 003E4B54 00000000 */   nop
    /* 2E4B58 003E4B58 04004324 */  addiu      $3, $2, 0x4
    /* 2E4B5C 003E4B5C 2D200002 */  daddu      $4, $16, $0
    /* 2E4B60 003E4B60 FCFF0224 */  addiu      $2, $0, -0x4
    /* 2E4B64 003E4B64 02000524 */  addiu      $5, $0, 0x2
    /* 2E4B68 003E4B68 24906200 */  and        $18, $3, $2
    /* 2E4B6C 003E4B6C 37000824 */  addiu      $8, $0, 0x37
    /* 2E4B70 003E4B70 0300023C */  lui        $2, (0x37002 >> 16)
    /* 2E4B74 003E4B74 2D304002 */  daddu      $6, $18, $0
    /* 2E4B78 003E4B78 FC7B0F0C */  jal        func_003deff0
    /* 2E4B7C 003E4B7C 02704734 */   ori       $7, $2, (0x37002 & 0xFFFF)
    /* 2E4B80 003E4B80 09004014 */  bnez       $2, .L003E4BA8
    /* 2E4B84 003E4B84 00000000 */   nop
    /* 2E4B88 003E4B88 0D000010 */  b          .L003E4BC0
    /* 2E4B8C 003E4B8C 2D100000 */   daddu     $2, $0, $0
  .L003E4B90:
    /* 2E4B90 003E4B90 7500113C */  lui        $17, %hi(D_00752FA8)
    /* 2E4B94 003E4B94 EAFF0010 */  b          .L003E4B40
    /* 2E4B98 003E4B98 A82F3126 */   addiu     $17, $17, %lo(D_00752FA8)
  .L003E4B9C:
    /* 2E4B9C 003E4B9C 7500043C */  lui        $4, %hi(D_00752FA8)
    /* 2E4BA0 003E4BA0 E9FF0010 */  b          .L003E4B48
    /* 2E4BA4 003E4BA4 A82F8424 */   addiu     $4, $4, %lo(D_00752FA8)
  .L003E4BA8:
    /* 2E4BA8 003E4BA8 2D200002 */  daddu      $4, $16, $0
    /* 2E4BAC 003E4BAC 2D304002 */  daddu      $6, $18, $0
    /* 2E4BB0 003E4BB0 AC8A0F0C */  jal        func_003e2ab0
    /* 2E4BB4 003E4BB4 2D282002 */   daddu     $5, $17, $0
    /* 2E4BB8 003E4BB8 0A880200 */  movz       $17, $0, $2
    /* 2E4BBC 003E4BBC 2D102002 */  daddu      $2, $17, $0
  .L003E4BC0:
    /* 2E4BC0 003E4BC0 3000BFDF */  ld         $31, 0x30($29)
    /* 2E4BC4 003E4BC4 2000B27B */  lq         $18, 0x20($29)
    /* 2E4BC8 003E4BC8 1000B17B */  lq         $17, 0x10($29)
    /* 2E4BCC 003E4BCC 0000B07B */  lq         $16, 0x0($29)
    /* 2E4BD0 003E4BD0 0800E003 */  jr         $31
    /* 2E4BD4 003E4BD4 4000BD27 */   addiu     $29, $29, 0x40
    /* 2E4BD8 003E4BD8 00000000 */  nop
    /* 2E4BDC 003E4BDC 00000000 */  nop
.size func_003e4b20, 0xc0
