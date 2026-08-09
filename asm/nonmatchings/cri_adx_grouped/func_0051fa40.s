.section .text
.set noat
.set noreorder
glabel func_0051fa40
    /* 41FA40 0051FA40 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 41FA44 0051FA44 0000B0FF */  sd         $16, 0x0($29)
    /* 41FA48 0051FA48 0800BFFF */  sd         $31, 0x8($29)
    /* 41FA4C 0051FA4C 3C5F140C */  jal        func_00517cf0
    /* 41FA50 0051FA50 2D808000 */   daddu     $16, $4, $0
    /* 41FA54 0051FA54 00FF053C */  lui        $5, (0xFF000183 >> 16)
    /* 41FA58 0051FA58 2D200002 */  daddu      $4, $16, $0
    /* 41FA5C 0051FA5C 06004010 */  beqz       $2, .L0051FA78
    /* 41FA60 0051FA60 8301A534 */   ori       $5, $5, (0xFF000183 & 0xFFFF)
    /* 41FA64 0051FA64 B45E140C */  jal        func_00517ad0
    /* 41FA68 0051FA68 2D200000 */   daddu     $4, $0, $0
    /* 41FA6C 0051FA6C 05000010 */  b          .L0051FA84
    /* 41FA70 0051FA70 2D100000 */   daddu     $2, $0, $0
    /* 41FA74 0051FA74 00000000 */  nop
  .L0051FA78:
    /* 41FA78 0051FA78 A67E140C */  jal        func_0051fa98
    /* 41FA7C 0051FA7C 00000000 */   nop
    /* 41FA80 0051FA80 2B100200 */  sltu       $2, $0, $2
  .L0051FA84:
    /* 41FA84 0051FA84 0000B0DF */  ld         $16, 0x0($29)
    /* 41FA88 0051FA88 0800BFDF */  ld         $31, 0x8($29)
    /* 41FA8C 0051FA8C 0800E003 */  jr         $31
    /* 41FA90 0051FA90 1000BD27 */   addiu     $29, $29, 0x10
    /* 41FA94 0051FA94 00000000 */  nop
.size func_0051fa40, 0x58
