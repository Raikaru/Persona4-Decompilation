.section .text
.set noat
.set noreorder
glabel func_003ddf80
    /* 2DDF80 003DDF80 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2DDF84 003DDF84 2D108000 */  daddu      $2, $4, $0
    /* 2DDF88 003DDF88 1000BFFF */  sd         $31, 0x10($29)
    /* 2DDF8C 003DDF8C 2D20E000 */  daddu      $4, $7, $0
    /* 2DDF90 003DDF90 0000B07F */  sq         $16, 0x0($29)
    /* 2DDF94 003DDF94 2D80A000 */  daddu      $16, $5, $0
    /* 2DDF98 003DDF98 18300602 */  mult       $6, $16, $6
    /* 2DDF9C 003DDF9C 2D284000 */  daddu      $5, $2, $0
    /* 2DDFA0 003DDFA0 5000E28C */  lw         $2, 0x50($7)
    /* 2DDFA4 003DDFA4 3000428C */  lw         $2, 0x30($2)
    /* 2DDFA8 003DDFA8 09F84000 */  jalr       $2
    /* 2DDFAC 003DDFAC 00000000 */   nop
    /* 2DDFB0 003DDFB0 1B005000 */  divu       $0, $2, $16
    /* 2DDFB4 003DDFB4 1000BFDF */  ld         $31, 0x10($29)
    /* 2DDFB8 003DDFB8 0000B07B */  lq         $16, 0x0($29)
    /* 2DDFBC 003DDFBC 12100000 */  mflo       $2
    /* 2DDFC0 003DDFC0 0800E003 */  jr         $31
    /* 2DDFC4 003DDFC4 2000BD27 */   addiu     $29, $29, 0x20
    /* 2DDFC8 003DDFC8 00000000 */  nop
    /* 2DDFCC 003DDFCC 00000000 */  nop
.size func_003ddf80, 0x50
