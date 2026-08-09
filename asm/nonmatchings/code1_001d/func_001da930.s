.section .text
.set noat
.set noreorder
glabel func_001da930
    /* DA930 001DA930 C0FFBD27 */  addiu      $29, $29, -0x40
    /* DA934 001DA934 3000BFFF */  sd         $31, 0x30($29)
    /* DA938 001DA938 2000B27F */  sq         $18, 0x20($29)
    /* DA93C 001DA93C 1000B17F */  sq         $17, 0x10($29)
    /* DA940 001DA940 0000B07F */  sq         $16, 0x0($29)
    /* DA944 001DA944 3000918C */  lw         $17, 0x30($4)
    /* DA948 001DA948 640A248E */  lw         $4, 0xA64($17)
    /* DA94C 001DA94C 4CF8080C */  jal        func_0023e130
    /* DA950 001DA950 00000000 */   nop
    /* DA954 001DA954 FFFF5030 */  andi       $16, $2, 0xFFFF
    /* DA958 001DA958 640A248E */  lw         $4, 0xA64($17)
    /* DA95C 001DA95C 50F8080C */  jal        func_0023e140
    /* DA960 001DA960 00000000 */   nop
    /* DA964 001DA964 2D884000 */  daddu      $17, $2, $0
    /* DA968 001DA968 2D900000 */  daddu      $18, $0, $0
    /* DA96C 001DA96C FFFF1032 */  andi       $16, $16, 0xFFFF
    /* DA970 001DA970 13000010 */  b          .L001DA9C0
    /* DA974 001DA974 00000000 */   nop
  .L001DA978:
    /* DA978 001DA978 FFFF4232 */  andi       $2, $18, 0xFFFF
    /* DA97C 001DA97C 40100200 */  sll        $2, $2, 1
    /* DA980 001DA980 21102202 */  addu       $2, $17, $2
    /* DA984 001DA984 00004494 */  lhu        $4, 0x0($2)
    /* DA988 001DA988 0B008010 */  beqz       $4, .L001DA9B8
    /* DA98C 001DA98C 00000000 */   nop
    /* DA990 001DA990 B8018128 */  slti       $1, $4, 0x1B8
    /* DA994 001DA994 08002010 */  beqz       $1, .L001DA9B8
    /* DA998 001DA998 00000000 */   nop
    /* DA99C 001DA99C C8F7080C */  jal        func_0023df20
    /* DA9A0 001DA9A0 00000000 */   nop
    /* DA9A4 001DA9A4 04004010 */  beqz       $2, .L001DA9B8
    /* DA9A8 001DA9A8 00000000 */   nop
    /* DA9AC 001DA9AC 01000224 */  addiu      $2, $0, 0x1
    /* DA9B0 001DA9B0 08000010 */  b          .L001DA9D4
    /* DA9B4 001DA9B4 00000000 */   nop
  .L001DA9B8:
    /* DA9B8 001DA9B8 01004226 */  addiu      $2, $18, 0x1
    /* DA9BC 001DA9BC FFFF5230 */  andi       $18, $2, 0xFFFF
  .L001DA9C0:
    /* DA9C0 001DA9C0 FFFF4232 */  andi       $2, $18, 0xFFFF
    /* DA9C4 001DA9C4 2A105000 */  slt        $2, $2, $16
    /* DA9C8 001DA9C8 EBFF4014 */  bnez       $2, .L001DA978
    /* DA9CC 001DA9CC 00000000 */   nop
    /* DA9D0 001DA9D0 2D100000 */  daddu      $2, $0, $0
  .L001DA9D4:
    /* DA9D4 001DA9D4 3000BFDF */  ld         $31, 0x30($29)
    /* DA9D8 001DA9D8 2000B27B */  lq         $18, 0x20($29)
    /* DA9DC 001DA9DC 1000B17B */  lq         $17, 0x10($29)
    /* DA9E0 001DA9E0 0000B07B */  lq         $16, 0x0($29)
    /* DA9E4 001DA9E4 4000BD27 */  addiu      $29, $29, 0x40
    /* DA9E8 001DA9E8 0800E003 */  jr         $31
    /* DA9EC 001DA9EC 00000000 */   nop
.size func_001da930, 0xc0
