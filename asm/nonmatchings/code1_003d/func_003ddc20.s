.section .text
.set noat
.set noreorder
glabel func_003ddc20
    /* 2DDC20 003DDC20 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 2DDC24 003DDC24 8800023C */  lui        $2, %hi(D_00887180)
    /* 2DDC28 003DDC28 3000BFFF */  sd         $31, 0x30($29)
    /* 2DDC2C 003DDC2C 2000B27F */  sq         $18, 0x20($29)
    /* 2DDC30 003DDC30 1000B17F */  sq         $17, 0x10($29)
    /* 2DDC34 003DDC34 0000B07F */  sq         $16, 0x0($29)
    /* 2DDC38 003DDC38 8071518C */  lw         $17, %lo(D_00887180)($2)
    /* 2DDC3C 003DDC3C 0E002012 */  beqz       $17, .L003DDC78
    /* 2DDC40 003DDC40 2D908000 */   daddu     $18, $4, $0
    /* 2DDC44 003DDC44 8800103C */  lui        $16, %hi(D_008873D0)
    /* 2DDC48 003DDC48 D0731026 */  addiu      $16, $16, %lo(D_008873D0)
  .L003DDC4C:
    /* 2DDC4C 003DDC4C 0C00258E */  lw         $5, 0xC($17)
    /* 2DDC50 003DDC50 0000028E */  lw         $2, 0x0($16)
    /* 2DDC54 003DDC54 09F84000 */  jalr       $2
    /* 2DDC58 003DDC58 2D204002 */   daddu     $4, $18, $0
    /* 2DDC5C 003DDC5C 03004014 */  bnez       $2, .L003DDC6C
    /* 2DDC60 003DDC60 00000000 */   nop
    /* 2DDC64 003DDC64 05000010 */  b          .L003DDC7C
    /* 2DDC68 003DDC68 2D102002 */   daddu     $2, $17, $0
  .L003DDC6C:
    /* 2DDC6C 003DDC6C 0000318E */  lw         $17, 0x0($17)
    /* 2DDC70 003DDC70 F6FF2016 */  bnez       $17, .L003DDC4C
    /* 2DDC74 003DDC74 00000000 */   nop
  .L003DDC78:
    /* 2DDC78 003DDC78 2D100000 */  daddu      $2, $0, $0
  .L003DDC7C:
    /* 2DDC7C 003DDC7C 3000BFDF */  ld         $31, 0x30($29)
    /* 2DDC80 003DDC80 2000B27B */  lq         $18, 0x20($29)
    /* 2DDC84 003DDC84 1000B17B */  lq         $17, 0x10($29)
    /* 2DDC88 003DDC88 0000B07B */  lq         $16, 0x0($29)
    /* 2DDC8C 003DDC8C 0800E003 */  jr         $31
    /* 2DDC90 003DDC90 4000BD27 */   addiu     $29, $29, 0x40
    /* 2DDC94 003DDC94 00000000 */  nop
    /* 2DDC98 003DDC98 00000000 */  nop
    /* 2DDC9C 003DDC9C 00000000 */  nop
.size func_003ddc20, 0x80
