.section .text
.set noat
.set noreorder
glabel func_003ddfd0
    /* 2DDFD0 003DDFD0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2DDFD4 003DDFD4 2D108000 */  daddu      $2, $4, $0
    /* 2DDFD8 003DDFD8 1000BFFF */  sd         $31, 0x10($29)
    /* 2DDFDC 003DDFDC 2D20E000 */  daddu      $4, $7, $0
    /* 2DDFE0 003DDFE0 0000B07F */  sq         $16, 0x0($29)
    /* 2DDFE4 003DDFE4 2D80A000 */  daddu      $16, $5, $0
    /* 2DDFE8 003DDFE8 18300602 */  mult       $6, $16, $6
    /* 2DDFEC 003DDFEC 2D284000 */  daddu      $5, $2, $0
    /* 2DDFF0 003DDFF0 5000E28C */  lw         $2, 0x50($7)
    /* 2DDFF4 003DDFF4 3400428C */  lw         $2, 0x34($2)
    /* 2DDFF8 003DDFF8 09F84000 */  jalr       $2
    /* 2DDFFC 003DDFFC 00000000 */   nop
    /* 2DE000 003DE000 1B005000 */  divu       $0, $2, $16
    /* 2DE004 003DE004 1000BFDF */  ld         $31, 0x10($29)
    /* 2DE008 003DE008 0000B07B */  lq         $16, 0x0($29)
    /* 2DE00C 003DE00C 12100000 */  mflo       $2
    /* 2DE010 003DE010 0800E003 */  jr         $31
    /* 2DE014 003DE014 2000BD27 */   addiu     $29, $29, 0x20
    /* 2DE018 003DE018 00000000 */  nop
    /* 2DE01C 003DE01C 00000000 */  nop
.size func_003ddfd0, 0x50
