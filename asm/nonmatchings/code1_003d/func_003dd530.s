.section .text
.set noat
.set noreorder
glabel func_003dd530
    /* 2DD530 003DD530 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2DD534 003DD534 01000624 */  addiu      $6, $0, 0x1
    /* 2DD538 003DD538 1000BFFF */  sd         $31, 0x10($29)
    /* 2DD53C 003DD53C 2D380000 */  daddu      $7, $0, $0
    /* 2DD540 003DD540 0000B07F */  sq         $16, 0x0($29)
    /* 2DD544 003DD544 2D400000 */  daddu      $8, $0, $0
    /* 2DD548 003DD548 94760F0C */  jal        func_003dda50
    /* 2DD54C 003DD54C 2D808000 */   daddu     $16, $4, $0
    /* 2DD550 003DD550 07004010 */  beqz       $2, .L003DD570
    /* 2DD554 003DD554 00000000 */   nop
    /* 2DD558 003DD558 2D204000 */  daddu      $4, $2, $0
    /* 2DD55C 003DD55C 2C00028E */  lw         $2, 0x2C($16)
    /* 2DD560 003DD560 09F84000 */  jalr       $2
    /* 2DD564 003DD564 00000000 */   nop
    /* 2DD568 003DD568 02000010 */  b          .L003DD574
    /* 2DD56C 003DD56C 01000224 */   addiu     $2, $0, 0x1
  .L003DD570:
    /* 2DD570 003DD570 2D100000 */  daddu      $2, $0, $0
  .L003DD574:
    /* 2DD574 003DD574 1000BFDF */  ld         $31, 0x10($29)
    /* 2DD578 003DD578 0000B07B */  lq         $16, 0x0($29)
    /* 2DD57C 003DD57C 0800E003 */  jr         $31
    /* 2DD580 003DD580 2000BD27 */   addiu     $29, $29, 0x20
    /* 2DD584 003DD584 00000000 */  nop
    /* 2DD588 003DD588 00000000 */  nop
    /* 2DD58C 003DD58C 00000000 */  nop
.size func_003dd530, 0x60
