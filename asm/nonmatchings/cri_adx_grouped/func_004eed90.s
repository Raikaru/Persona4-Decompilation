.section .text
.set noat
.set noreorder
glabel func_004eed90
    /* 3EED90 004EED90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EED94 004EED94 0000B0FF */  sd         $16, 0x0($29)
    /* 3EED98 004EED98 2D808000 */  daddu      $16, $4, $0
    /* 3EED9C 004EED9C 0A000016 */  bnez       $16, .L004EEDC8
    /* 3EEDA0 004EEDA0 0800BFFF */   sd        $31, 0x8($29)
    /* 3EEDA4 004EEDA4 7600043C */  lui        $4, %hi(D_0075CEE8)
    /* 3EEDA8 004EEDA8 7600053C */  lui        $5, %hi(D_0075CEF8)
    /* 3EEDAC 004EEDAC 0000B0DF */  ld         $16, 0x0($29)
    /* 3EEDB0 004EEDB0 E8CE8424 */  addiu      $4, $4, %lo(D_0075CEE8)
    /* 3EEDB4 004EEDB4 0800BFDF */  ld         $31, 0x8($29)
    /* 3EEDB8 004EEDB8 F8CEA524 */  addiu      $5, $5, %lo(D_0075CEF8)
    /* 3EEDBC 004EEDBC B6BA1308 */  j          func_004eead8
    /* 3EEDC0 004EEDC0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EEDC4 004EEDC4 00000000 */  nop
  .L004EEDC8:
    /* 3EEDC8 004EEDC8 04000282 */  lb         $2, 0x4($16)
    /* 3EEDCC 004EEDCC 0A004014 */  bnez       $2, .L004EEDF8
    /* 3EEDD0 004EEDD0 2D280000 */   daddu     $5, $0, $0
    /* 3EEDD4 004EEDD4 7600043C */  lui        $4, %hi(D_0075CF18)
    /* 3EEDD8 004EEDD8 7600053C */  lui        $5, %hi(D_0075CF28)
    /* 3EEDDC 004EEDDC 0000B0DF */  ld         $16, 0x0($29)
    /* 3EEDE0 004EEDE0 18CF8424 */  addiu      $4, $4, %lo(D_0075CF18)
    /* 3EEDE4 004EEDE4 0800BFDF */  ld         $31, 0x8($29)
    /* 3EEDE8 004EEDE8 28CFA524 */  addiu      $5, $5, %lo(D_0075CF28)
    /* 3EEDEC 004EEDEC B6BA1308 */  j          func_004eead8
    /* 3EEDF0 004EEDF0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EEDF4 004EEDF4 00000000 */  nop
  .L004EEDF8:
    /* 3EEDF8 004EEDF8 72FE100C */  jal        func_0043f9c8
    /* 3EEDFC 004EEDFC 30000624 */   addiu     $6, $0, 0x30
    /* 3EEE00 004EEE00 040000A2 */  sb         $0, 0x4($16)
    /* 3EEE04 004EEE04 0800BFDF */  ld         $31, 0x8($29)
    /* 3EEE08 004EEE08 0000B0DF */  ld         $16, 0x0($29)
    /* 3EEE0C 004EEE0C 0800E003 */  jr         $31
    /* 3EEE10 004EEE10 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EEE14 004EEE14 00000000 */  nop
.size func_004eed90, 0x88
