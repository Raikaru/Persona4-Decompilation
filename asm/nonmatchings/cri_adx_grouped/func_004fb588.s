.section .text
.set noat
.set noreorder
glabel func_004fb588
    /* 3FB588 004FB588 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3FB58C 004FB58C 0000B0FF */  sd         $16, 0x0($29)
    /* 3FB590 004FB590 2D808000 */  daddu      $16, $4, $0
    /* 3FB594 004FB594 0800B1FF */  sd         $17, 0x8($29)
    /* 3FB598 004FB598 1000BFFF */  sd         $31, 0x10($29)
    /* 3FB59C 004FB59C 1E04140C */  jal        func_00501078
    /* 3FB5A0 004FB5A0 2D88A000 */   daddu     $17, $5, $0
    /* 3FB5A4 004FB5A4 03FF053C */  lui        $5, (0xFF030204 >> 16)
    /* 3FB5A8 004FB5A8 07004010 */  beqz       $2, .L004FB5C8
    /* 3FB5AC 004FB5AC 2D200000 */   daddu     $4, $0, $0
    /* 3FB5B0 004FB5B0 0000B0DF */  ld         $16, 0x0($29)
    /* 3FB5B4 004FB5B4 0402A534 */  ori        $5, $5, (0xFF030204 & 0xFFFF)
    /* 3FB5B8 004FB5B8 0800B1DF */  ld         $17, 0x8($29)
    /* 3FB5BC 004FB5BC 1000BFDF */  ld         $31, 0x10($29)
    /* 3FB5C0 004FB5C0 82ED1308 */  j          func_004fb608
    /* 3FB5C4 004FB5C4 2000BD27 */   addiu     $29, $29, 0x20
  .L004FB5C8:
    /* 3FB5C8 004FB5C8 0B00026A */  ldl        $2, 0xB($16)
    /* 3FB5CC 004FB5CC 0400026E */  ldr        $2, 0x4($16)
    /* 3FB5D0 004FB5D0 1300036A */  ldl        $3, 0x13($16)
    /* 3FB5D4 004FB5D4 0C00036E */  ldr        $3, 0xC($16)
    /* 3FB5D8 004FB5D8 1400048E */  lw         $4, 0x14($16)
    /* 3FB5DC 004FB5DC 070022B2 */  sdl        $2, 0x7($17)
    /* 3FB5E0 004FB5E0 000022B6 */  sdr        $2, 0x0($17)
    /* 3FB5E4 004FB5E4 0F0023B2 */  sdl        $3, 0xF($17)
    /* 3FB5E8 004FB5E8 080023B6 */  sdr        $3, 0x8($17)
    /* 3FB5EC 004FB5EC 100024AE */  sw         $4, 0x10($17)
    /* 3FB5F0 004FB5F0 1000BFDF */  ld         $31, 0x10($29)
    /* 3FB5F4 004FB5F4 0000B0DF */  ld         $16, 0x0($29)
    /* 3FB5F8 004FB5F8 0800B1DF */  ld         $17, 0x8($29)
    /* 3FB5FC 004FB5FC 0800E003 */  jr         $31
    /* 3FB600 004FB600 2000BD27 */   addiu     $29, $29, 0x20
    /* 3FB604 004FB604 00000000 */  nop
.size func_004fb588, 0x80
