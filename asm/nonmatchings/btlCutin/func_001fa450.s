.section .text
.set noat
.set noreorder
glabel func_001fa450
    /* FA450 001FA450 F0FFBD27 */  addiu      $29, $29, -0x10
    /* FA454 001FA454 0000BFFF */  sd         $31, 0x0($29)
    /* FA458 001FA458 020C0424 */  addiu      $4, $0, 0xC02
    /* FA45C 001FA45C 2D280000 */  daddu      $5, $0, $0
    /* FA460 001FA460 1C51060C */  jal        func_00194470
    /* FA464 001FA464 00000000 */   nop
    /* FA468 001FA468 47004390 */  lbu        $3, 0x47($2)
    /* FA46C 001FA46C EE006330 */  andi       $3, $3, 0xEE
    /* FA470 001FA470 470043A0 */  sb         $3, 0x47($2)
    /* FA474 001FA474 2000033C */  lui        $3, %hi(func_001fa370)
    /* FA478 001FA478 70A36324 */  addiu      $3, $3, %lo(func_001fa370)
    /* FA47C 001FA47C 6C0043AC */  sw         $3, 0x6C($2)
    /* FA480 001FA480 0000BFDF */  ld         $31, 0x0($29)
    /* FA484 001FA484 1000BD27 */  addiu      $29, $29, 0x10
    /* FA488 001FA488 0800E003 */  jr         $31
    /* FA48C 001FA48C 00000000 */   nop
.size func_001fa450, 0x40
