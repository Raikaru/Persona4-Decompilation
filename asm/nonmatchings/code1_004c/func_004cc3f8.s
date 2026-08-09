.section .text
.set noat
.set noreorder
glabel func_004cc3f8
    /* 3CC3F8 004CC3F8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CC3FC 004CC3FC 7200033C */  lui        $3, %hi(D_00719994)
    /* 3CC400 004CC400 0000BFFF */  sd         $31, 0x0($29)
    /* 3CC404 004CC404 94996324 */  addiu      $3, $3, %lo(D_00719994)
    /* 3CC408 004CC408 0000628C */  lw         $2, 0x0($3)
    /* 3CC40C 004CC40C FFFF4224 */  addiu      $2, $2, -0x1
    /* 3CC410 004CC410 1B004014 */  bnez       $2, .L004CC480
    /* 3CC414 004CC414 000062AC */   sw        $2, 0x0($3)
    /* 3CC418 004CC418 EA30130C */  jal        func_004cc3a8
    /* 3CC41C 004CC41C 00000000 */   nop
    /* 3CC420 004CC420 5831130C */  jal        func_004cc560
    /* 3CC424 004CC424 00000000 */   nop
    /* 3CC428 004CC428 C031130C */  jal        func_004cc700
    /* 3CC42C 004CC42C 00000000 */   nop
    /* 3CC430 004CC430 8C31130C */  jal        func_004cc630
    /* 3CC434 004CC434 00000000 */   nop
    /* 3CC438 004CC438 4032130C */  jal        func_004cc900
    /* 3CC43C 004CC43C 00000000 */   nop
    /* 3CC440 004CC440 7200023C */  lui        $2, %hi(D_00719A38)
    /* 3CC444 004CC444 7200033C */  lui        $3, %hi(D_007212C8)
    /* 3CC448 004CC448 389A4224 */  addiu      $2, $2, %lo(D_00719A38)
    /* 3CC44C 004CC44C C812658C */  lw         $5, %lo(D_007212C8)($3)
    /* 3CC450 004CC450 9C85100C */  jal        func_00421670
    /* 3CC454 004CC454 0000448C */   lw        $4, 0x0($2)
    /* 3CC458 004CC458 2D200000 */  daddu      $4, $0, $0
    /* 3CC45C 004CC45C B0C3130C */  jal        func_004f0ec0
    /* 3CC460 004CC460 2D280000 */   daddu     $5, $0, $0
    /* 3CC464 004CC464 2D200000 */  daddu      $4, $0, $0
    /* 3CC468 004CC468 B6C3130C */  jal        func_004f0ed8
    /* 3CC46C 004CC46C 2D280000 */   daddu     $5, $0, $0
    /* 3CC470 004CC470 0000BFDF */  ld         $31, 0x0($29)
    /* 3CC474 004CC474 88C41308 */  j          func_004f1220
    /* 3CC478 004CC478 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CC47C 004CC47C 00000000 */  nop
  .L004CC480:
    /* 3CC480 004CC480 0000BFDF */  ld         $31, 0x0($29)
    /* 3CC484 004CC484 0800E003 */  jr         $31
    /* 3CC488 004CC488 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CC48C 004CC48C 00000000 */  nop
.size func_004cc3f8, 0x98
