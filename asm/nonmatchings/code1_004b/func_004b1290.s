.section .text
.set noat
.set noreorder
glabel func_004b1290
    /* 3B1290 004B1290 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3B1294 004B1294 1000BFFF */  sd         $31, 0x10($29)
    /* 3B1298 004B1298 0000B07F */  sq         $16, 0x0($29)
    /* 3B129C 004B129C 2D808000 */  daddu      $16, $4, $0
    /* 3B12A0 004B12A0 6C8380C7 */  lwc1       $f0, -0x7C94($28)
    /* 3B12A4 004B12A4 02030C46 */  mul.s      $f12, $f0, $f12
    /* 3B12A8 004B12A8 42030D46 */  mul.s      $f13, $f0, $f13
    /* 3B12AC 004B12AC 82030E46 */  mul.s      $f14, $f0, $f14
    /* 3B12B0 004B12B0 C8F3120C */  jal        func_004bcf20
    /* 3B12B4 004B12B4 00000000 */   nop
    /* 3B12B8 004B12B8 2000A527 */  addiu      $5, $29, 0x20
    /* 3B12BC 004B12BC 0000AAF8 */  sqc2       $vf10, 0x0($5)
    /* 3B12C0 004B12C0 2D200002 */  daddu      $4, $16, $0
    /* 3B12C4 004B12C4 CC18120C */  jal        func_00486330
    /* 3B12C8 004B12C8 00000000 */   nop
    /* 3B12CC 004B12CC 1000BFDF */  ld         $31, 0x10($29)
    /* 3B12D0 004B12D0 0000B07B */  lq         $16, 0x0($29)
    /* 3B12D4 004B12D4 3000BD27 */  addiu      $29, $29, 0x30
    /* 3B12D8 004B12D8 0800E003 */  jr         $31
    /* 3B12DC 004B12DC 00000000 */   nop
.size func_004b1290, 0x50
