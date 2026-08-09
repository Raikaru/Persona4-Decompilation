.section .text
.set noat
.set noreorder
glabel func_00525a98
    /* 425A98 00525A98 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 425A9C 00525A9C 0000B0FF */  sd         $16, 0x0($29)
    /* 425AA0 00525AA0 0800BFFF */  sd         $31, 0x8($29)
    /* 425AA4 00525AA4 B696140C */  jal        func_00525ad8
    /* 425AA8 00525AA8 2D808000 */   daddu     $16, $4, $0
    /* 425AAC 00525AAC 00FF053C */  lui        $5, (0xFF000222 >> 16)
    /* 425AB0 00525AB0 04004010 */  beqz       $2, .L00525AC4
    /* 425AB4 00525AB4 2D200002 */   daddu     $4, $16, $0
    /* 425AB8 00525AB8 B45E140C */  jal        func_00517ad0
    /* 425ABC 00525ABC 2202A534 */   ori       $5, $5, (0xFF000222 & 0xFFFF)
    /* 425AC0 00525AC0 01000224 */  addiu      $2, $0, 0x1
  .L00525AC4:
    /* 425AC4 00525AC4 0000B0DF */  ld         $16, 0x0($29)
    /* 425AC8 00525AC8 0800BFDF */  ld         $31, 0x8($29)
    /* 425ACC 00525ACC 0800E003 */  jr         $31
    /* 425AD0 00525AD0 1000BD27 */   addiu     $29, $29, 0x10
    /* 425AD4 00525AD4 00000000 */  nop
.size func_00525a98, 0x40
