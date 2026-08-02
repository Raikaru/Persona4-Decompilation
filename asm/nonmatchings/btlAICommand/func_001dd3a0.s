.section .text
.set noat
.set noreorder
glabel func_001dd3a0
    /* DD3A0 001DD3A0 40FFBD27 */  addiu      $29, $29, -0xC0
    /* DD3A4 001DD3A4 9000BFFF */  sd         $31, 0x90($29)
    /* DD3A8 001DD3A8 8000BE7F */  sq         $30, 0x80($29)
    /* DD3AC 001DD3AC 7000B77F */  sq         $23, 0x70($29)
    /* DD3B0 001DD3B0 6000B67F */  sq         $22, 0x60($29)
    /* DD3B4 001DD3B4 5000B57F */  sq         $21, 0x50($29)
    /* DD3B8 001DD3B8 4000B47F */  sq         $20, 0x40($29)
    /* DD3BC 001DD3BC 3000B37F */  sq         $19, 0x30($29)
    /* DD3C0 001DD3C0 2000B27F */  sq         $18, 0x20($29)
    /* DD3C4 001DD3C4 1000B17F */  sq         $17, 0x10($29)
    /* DD3C8 001DD3C8 0000B07F */  sq         $16, 0x0($29)
    /* DD3CC 001DD3CC 2DA08000 */  daddu      $20, $4, $0
    /* DD3D0 001DD3D0 2D98A000 */  daddu      $19, $5, $0
    /* DD3D4 001DD3D4 2DF0C000 */  daddu      $30, $6, $0
    /* DD3D8 001DD3D8 2DB0E000 */  daddu      $22, $7, $0
    /* DD3DC 001DD3DC 2DA80001 */  daddu      $21, $8, $0
    /* DD3E0 001DD3E0 3000A28C */  lw         $2, 0x30($5)
    /* DD3E4 001DD3E4 640A448C */  lw         $4, 0xA64($2)
    /* DD3E8 001DD3E8 B4C7080C */  jal        func_00231ed0
    /* DD3EC 001DD3EC 00000000 */   nop
    /* DD3F0 001DD3F0 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* DD3F4 001DD3F4 B000A27F */  sq         $2, 0xB0($29)
    /* DD3F8 001DD3F8 3000628E */  lw         $2, 0x30($19)
    /* DD3FC 001DD3FC 640A448C */  lw         $4, 0xA64($2)
    /* DD400 001DD400 E0C7080C */  jal        func_00231f80
    /* DD404 001DD404 00000000 */   nop
    /* DD408 001DD408 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* DD40C 001DD40C A000A27F */  sq         $2, 0xA0($29)
    /* DD410 001DD410 FFFF1124 */  addiu      $17, $0, -0x1
    /* DD414 001DD414 FF00023C */  lui        $2, (0xFFFFFF >> 16)
    /* DD418 001DD418 FFFF5234 */  ori        $18, $2, (0xFFFFFF & 0xFFFF)
    /* DD41C 001DD41C 2D800000 */  daddu      $16, $0, $0
    /* DD420 001DD420 FFFFB532 */  andi       $21, $21, 0xFFFF
    /* DD424 001DD424 FFFFD732 */  andi       $23, $22, 0xFFFF
    /* DD428 001DD428 34000010 */  b          .L001DD4FC
    /* DD42C 001DD42C 00000000 */   nop
  .L001DD430:
    /* DD430 001DD430 FFFF0232 */  andi       $2, $16, 0xFFFF
    /* DD434 001DD434 40100200 */  sll        $2, $2, 1
    /* DD438 001DD438 21B0C203 */  addu       $22, $30, $2
    /* DD43C 001DD43C 0000C496 */  lhu        $4, 0x0($22)
    /* DD440 001DD440 2C008010 */  beqz       $4, .L001DD4F4
    /* DD444 001DD444 00000000 */   nop
    /* DD448 001DD448 B8018128 */  slti       $1, $4, 0x1B8
    /* DD44C 001DD44C 29002010 */  beqz       $1, .L001DD4F4
    /* DD450 001DD450 00000000 */   nop
    /* DD454 001DD454 80100400 */  sll        $2, $4, 2
    /* DD458 001DD458 21104400 */  addu       $2, $2, $4
    /* DD45C 001DD45C C0180200 */  sll        $3, $2, 3
    /* DD460 001DD460 B8B3828F */  lw         $2, -0x4C48($28)
    /* DD464 001DD464 21104300 */  addu       $2, $2, $3
    /* DD468 001DD468 08004590 */  lbu        $5, 0x8($2)
    /* DD46C 001DD46C 0500A016 */  bnez       $21, .L001DD484
    /* DD470 001DD470 00000000 */   nop
    /* DD474 001DD474 FF00A330 */  andi       $3, $5, 0xFF
    /* DD478 001DD478 01000224 */  addiu      $2, $0, 0x1
    /* DD47C 001DD47C 1D006214 */  bne        $3, $2, .L001DD4F4
    /* DD480 001DD480 00000000 */   nop
  .L001DD484:
    /* DD484 001DD484 01000224 */  addiu      $2, $0, 0x1
    /* DD488 001DD488 0400A216 */  bne        $21, $2, .L001DD49C
    /* DD48C 001DD48C 00000000 */   nop
    /* DD490 001DD490 FF00A230 */  andi       $2, $5, 0xFF
    /* DD494 001DD494 17004014 */  bnez       $2, .L001DD4F4
    /* DD498 001DD498 00000000 */   nop
  .L001DD49C:
    /* DD49C 001DD49C 3000838E */  lw         $3, 0x30($20)
    /* DD4A0 001DD4A0 3000628E */  lw         $2, 0x30($19)
    /* DD4A4 001DD4A4 640A658C */  lw         $5, 0xA64($3)
    /* DD4A8 001DD4A8 640A468C */  lw         $6, 0xA64($2)
    /* DD4AC 001DD4AC 01000724 */  addiu      $7, $0, 0x1
    /* DD4B0 001DD4B0 2D40E000 */  daddu      $8, $7, $0
    /* DD4B4 001DD4B4 2D48E000 */  daddu      $9, $7, $0
    /* DD4B8 001DD4B8 2D500000 */  daddu      $10, $0, $0
    /* DD4BC 001DD4BC 2D58E000 */  daddu      $11, $7, $0
    /* DD4C0 001DD4C0 48D5080C */  jal        func_00235520
    /* DD4C4 001DD4C4 00000000 */   nop
    /* DD4C8 001DD4C8 B000A37B */  lq         $3, 0xB0($29)
    /* DD4CC 001DD4CC 21186200 */  addu       $3, $3, $2
    /* DD4D0 001DD4D0 A000A27B */  lq         $2, 0xA0($29)
    /* DD4D4 001DD4D4 23204300 */  subu       $4, $2, $3
    /* DD4D8 001DD4D8 A8F1100C */  jal        func_0043c6a0
    /* DD4DC 001DD4DC 00000000 */   nop
    /* DD4E0 001DD4E0 2A085200 */  slt        $1, $2, $18
    /* DD4E4 001DD4E4 03002010 */  beqz       $1, .L001DD4F4
    /* DD4E8 001DD4E8 00000000 */   nop
    /* DD4EC 001DD4EC 0000D196 */  lhu        $17, 0x0($22)
    /* DD4F0 001DD4F0 2D904000 */  daddu      $18, $2, $0
  .L001DD4F4:
    /* DD4F4 001DD4F4 01000226 */  addiu      $2, $16, 0x1
    /* DD4F8 001DD4F8 FFFF5030 */  andi       $16, $2, 0xFFFF
  .L001DD4FC:
    /* DD4FC 001DD4FC FFFF0232 */  andi       $2, $16, 0xFFFF
    /* DD500 001DD500 2A105700 */  slt        $2, $2, $23
    /* DD504 001DD504 CAFF4014 */  bnez       $2, .L001DD430
    /* DD508 001DD508 00000000 */   nop
    /* DD50C 001DD50C 3000828E */  lw         $2, 0x30($20)
    /* DD510 001DD510 640A448C */  lw         $4, 0xA64($2)
    /* DD514 001DD514 ECCE080C */  jal        func_00233bb0
    /* DD518 001DD518 00000000 */   nop
    /* DD51C 001DD51C 3000628E */  lw         $2, 0x30($19)
    /* DD520 001DD520 640A448C */  lw         $4, 0xA64($2)
    /* DD524 001DD524 ECCE080C */  jal        func_00233bb0
    /* DD528 001DD528 00000000 */   nop
    /* DD52C 001DD52C 2D102002 */  daddu      $2, $17, $0
    /* DD530 001DD530 9000BFDF */  ld         $31, 0x90($29)
    /* DD534 001DD534 8000BE7B */  lq         $30, 0x80($29)
    /* DD538 001DD538 7000B77B */  lq         $23, 0x70($29)
    /* DD53C 001DD53C 6000B67B */  lq         $22, 0x60($29)
    /* DD540 001DD540 5000B57B */  lq         $21, 0x50($29)
    /* DD544 001DD544 4000B47B */  lq         $20, 0x40($29)
    /* DD548 001DD548 3000B37B */  lq         $19, 0x30($29)
    /* DD54C 001DD54C 2000B27B */  lq         $18, 0x20($29)
    /* DD550 001DD550 1000B17B */  lq         $17, 0x10($29)
    /* DD554 001DD554 0000B07B */  lq         $16, 0x0($29)
    /* DD558 001DD558 C000BD27 */  addiu      $29, $29, 0xC0
    /* DD55C 001DD55C 0800E003 */  jr         $31
    /* DD560 001DD560 00000000 */   nop
    /* DD564 001DD564 00000000 */  nop
    /* DD568 001DD568 00000000 */  nop
    /* DD56C 001DD56C 00000000 */  nop
.size func_001dd3a0, 0x1d0
