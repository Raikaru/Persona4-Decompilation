.section .text
.set noat
.set noreorder
glabel func_0052b6c8
    /* 42B6C8 0052B6C8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 42B6CC 0052B6CC 7400023C */  lui        $2, %hi(D_00745C68)
    /* 42B6D0 0052B6D0 0000B0FF */  sd         $16, 0x0($29)
    /* 42B6D4 0052B6D4 685C5024 */  addiu      $16, $2, %lo(D_00745C68)
    /* 42B6D8 0052B6D8 0000038E */  lw         $3, 0x0($16)
    /* 42B6DC 0052B6DC 0C006018 */  blez       $3, .L0052B710
    /* 42B6E0 0052B6E0 0800BFFF */   sd        $31, 0x8($29)
    /* 42B6E4 0052B6E4 D4AF140C */  jal        func_0052bf50
    /* 42B6E8 0052B6E8 00000000 */   nop
    /* 42B6EC 0052B6EC 24A9140C */  jal        func_0052a490
    /* 42B6F0 0052B6F0 00000000 */   nop
    /* 42B6F4 0052B6F4 B8AF140C */  jal        func_0052bee0
    /* 42B6F8 0052B6F8 00000000 */   nop
    /* 42B6FC 0052B6FC B8E6130C */  jal        func_004f9ae0
    /* 42B700 0052B700 00000000 */   nop
    /* 42B704 0052B704 0000028E */  lw         $2, 0x0($16)
    /* 42B708 0052B708 FFFF4224 */  addiu      $2, $2, -0x1
    /* 42B70C 0052B70C 000002AE */  sw         $2, 0x0($16)
  .L0052B710:
    /* 42B710 0052B710 0000B0DF */  ld         $16, 0x0($29)
    /* 42B714 0052B714 0800BFDF */  ld         $31, 0x8($29)
    /* 42B718 0052B718 0800E003 */  jr         $31
    /* 42B71C 0052B71C 1000BD27 */   addiu     $29, $29, 0x10
.size func_0052b6c8, 0x58
