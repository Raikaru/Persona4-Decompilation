.section .text
.set noat
.set noreorder
glabel func_003cb870
    /* 2CB870 003CB870 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2CB874 003CB874 2000BFFF */  sd         $31, 0x20($29)
    /* 2CB878 003CB878 1000B17F */  sq         $17, 0x10($29)
    /* 2CB87C 003CB87C 0000B07F */  sq         $16, 0x0($29)
    /* 2CB880 003CB880 2D888000 */  daddu      $17, $4, $0
    /* 2CB884 003CB884 2D80C000 */  daddu      $16, $6, $0
    /* 2CB888 003CB888 08270F0C */  jal        func_003c9c20
    /* 2CB88C 003CB88C 2D200002 */   daddu     $4, $16, $0
    /* 2CB890 003CB890 2D202002 */  daddu      $4, $17, $0
    /* 2CB894 003CB894 2D284000 */  daddu      $5, $2, $0
    /* 2CB898 003CB898 44170F0C */  jal        func_003c5d10
    /* 2CB89C 003CB89C 10004624 */   addiu     $6, $2, 0x10
    /* 2CB8A0 003CB8A0 780002AE */  sw         $2, 0x78($16)
    /* 2CB8A4 003CB8A4 7800028E */  lw         $2, 0x78($16)
    /* 2CB8A8 003CB8A8 0A880200 */  movz       $17, $0, $2
    /* 2CB8AC 003CB8AC 2D102002 */  daddu      $2, $17, $0
    /* 2CB8B0 003CB8B0 2000BFDF */  ld         $31, 0x20($29)
    /* 2CB8B4 003CB8B4 1000B17B */  lq         $17, 0x10($29)
    /* 2CB8B8 003CB8B8 0000B07B */  lq         $16, 0x0($29)
    /* 2CB8BC 003CB8BC 0800E003 */  jr         $31
    /* 2CB8C0 003CB8C0 3000BD27 */   addiu     $29, $29, 0x30
    /* 2CB8C4 003CB8C4 00000000 */  nop
    /* 2CB8C8 003CB8C8 00000000 */  nop
    /* 2CB8CC 003CB8CC 00000000 */  nop
.size func_003cb870, 0x60
