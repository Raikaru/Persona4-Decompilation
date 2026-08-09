.section .text
.set noat
.set noreorder
glabel func_003beb10
    /* 2BEB10 003BEB10 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 2BEB14 003BEB14 3000BFFF */  sd         $31, 0x30($29)
    /* 2BEB18 003BEB18 2000B27F */  sq         $18, 0x20($29)
    /* 2BEB1C 003BEB1C 1000B17F */  sq         $17, 0x10($29)
    /* 2BEB20 003BEB20 2D908000 */  daddu      $18, $4, $0
    /* 2BEB24 003BEB24 0000B07F */  sq         $16, 0x0($29)
    /* 2BEB28 003BEB28 0400828C */  lw         $2, 0x4($4)
    /* 2BEB2C 003BEB2C 2A100200 */  slt        $2, $0, $2
    /* 2BEB30 003BEB30 0B004014 */  bnez       $2, .L003BEB60
    /* 2BEB34 003BEB34 2D880000 */   daddu     $17, $0, $0
    /* 2BEB38 003BEB38 0000448E */  lw         $4, 0x0($18)
  .L003BEB3C:
    /* 2BEB3C 003BEB3C 06008010 */  beqz       $4, .L003BEB58
    /* 2BEB40 003BEB40 00000000 */   nop
    /* 2BEB44 003BEB44 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2BEB48 003BEB48 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2BEB4C 003BEB4C 09F84000 */  jalr       $2
    /* 2BEB50 003BEB50 00000000 */   nop
    /* 2BEB54 003BEB54 000040AE */  sw         $0, 0x0($18)
  .L003BEB58:
    /* 2BEB58 003BEB58 0D000010 */  b          .L003BEB90
    /* 2BEB5C 003BEB5C 2D104002 */   daddu     $2, $18, $0
  .L003BEB60:
    /* 2BEB60 003BEB60 2D800000 */  daddu      $16, $0, $0
  .L003BEB64:
    /* 2BEB64 003BEB64 0000428E */  lw         $2, 0x0($18)
    /* 2BEB68 003BEB68 21105000 */  addu       $2, $2, $16
    /* 2BEB6C 003BEB6C A00A0F0C */  jal        func_003c2a80
    /* 2BEB70 003BEB70 0000448C */   lw        $4, 0x0($2)
    /* 2BEB74 003BEB74 0400428E */  lw         $2, 0x4($18)
    /* 2BEB78 003BEB78 01003126 */  addiu      $17, $17, 0x1
    /* 2BEB7C 003BEB7C 2A102202 */  slt        $2, $17, $2
    /* 2BEB80 003BEB80 F8FF4014 */  bnez       $2, .L003BEB64
    /* 2BEB84 003BEB84 04001026 */   addiu     $16, $16, 0x4
    /* 2BEB88 003BEB88 ECFF0010 */  b          .L003BEB3C
    /* 2BEB8C 003BEB8C 0000448E */   lw        $4, 0x0($18)
  .L003BEB90:
    /* 2BEB90 003BEB90 3000BFDF */  ld         $31, 0x30($29)
    /* 2BEB94 003BEB94 2000B27B */  lq         $18, 0x20($29)
    /* 2BEB98 003BEB98 1000B17B */  lq         $17, 0x10($29)
    /* 2BEB9C 003BEB9C 0000B07B */  lq         $16, 0x0($29)
    /* 2BEBA0 003BEBA0 0800E003 */  jr         $31
    /* 2BEBA4 003BEBA4 4000BD27 */   addiu     $29, $29, 0x40
    /* 2BEBA8 003BEBA8 00000000 */  nop
    /* 2BEBAC 003BEBAC 00000000 */  nop
.size func_003beb10, 0xa0
