.section .text
.set noat
.set noreorder
glabel func_001bbe80
    /* BBE80 001BBE80 E0FFBD27 */  addiu      $29, $29, -0x20
    /* BBE84 001BBE84 1000BFFF */  sd         $31, 0x10($29)
    /* BBE88 001BBE88 0000B07F */  sq         $16, 0x0($29)
    /* BBE8C 001BBE8C 2D808000 */  daddu      $16, $4, $0
    /* BBE90 001BBE90 7042023C */  lui        $2, (0x42700000 >> 16)
    /* BBE94 001BBE94 00008244 */  mtc1       $2, $f0
    /* BBE98 001BBE98 00000000 */  nop
    /* BBE9C 001BBE9C 42000C46 */  mul.s      $f1, $f0, $f12
    /* BBEA0 001BBEA0 0040023C */  lui        $2, (0x40000000 >> 16)
    /* BBEA4 001BBEA4 00008244 */  mtc1       $2, $f0
    /* BBEA8 001BBEA8 00000000 */  nop
    /* BBEAC 001BBEAC 030B0046 */  div.s      $f12, $f1, $f0
    /* BBEB0 001BBEB0 00000000 */  nop
    /* BBEB4 001BBEB4 00000000 */  nop
    /* BBEB8 001BBEB8 84000426 */  addiu      $4, $16, 0x84
    /* BBEBC 001BBEBC 78B1070C */  jal        func_001ec5e0
    /* BBEC0 001BBEC0 00000000 */   nop
    /* BBEC4 001BBEC4 00000396 */  lhu        $3, 0x0($16)
    /* BBEC8 001BBEC8 F3FF6330 */  andi       $3, $3, 0xFFF3
    /* BBECC 001BBECC 000003A6 */  sh         $3, 0x0($16)
    /* BBED0 001BBED0 00000396 */  lhu        $3, 0x0($16)
    /* BBED4 001BBED4 02006334 */  ori        $3, $3, 0x2
    /* BBED8 001BBED8 000003A6 */  sh         $3, 0x0($16)
    /* BBEDC 001BBEDC 1000BFDF */  ld         $31, 0x10($29)
    /* BBEE0 001BBEE0 0000B07B */  lq         $16, 0x0($29)
    /* BBEE4 001BBEE4 2000BD27 */  addiu      $29, $29, 0x20
    /* BBEE8 001BBEE8 0800E003 */  jr         $31
    /* BBEEC 001BBEEC 00000000 */   nop
.size func_001bbe80, 0x70
