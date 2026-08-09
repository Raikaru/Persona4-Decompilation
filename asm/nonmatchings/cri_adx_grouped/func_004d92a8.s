.section .text
.set noat
.set noreorder
glabel func_004d92a8
    /* 3D92A8 004D92A8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D92AC 004D92AC 7300023C */  lui        $2, %hi(D_007282A0)
    /* 3D92B0 004D92B0 0000B0FF */  sd         $16, 0x0($29)
    /* 3D92B4 004D92B4 A0825024 */  addiu      $16, $2, %lo(D_007282A0)
    /* 3D92B8 004D92B8 0000028E */  lw         $2, 0x0($16)
    /* 3D92BC 004D92BC 07004014 */  bnez       $2, .L004D92DC
    /* 3D92C0 004D92C0 0800BFFF */   sd        $31, 0x8($29)
    /* 3D92C4 004D92C4 7300043C */  lui        $4, %hi(D_00728330)
    /* 3D92C8 004D92C8 2D280000 */  daddu      $5, $0, $0
    /* 3D92CC 004D92CC 30838424 */  addiu      $4, $4, %lo(D_00728330)
    /* 3D92D0 004D92D0 72FE100C */  jal        func_0043f9c8
    /* 3D92D4 004D92D4 C0020624 */   addiu     $6, $0, 0x2C0
    /* 3D92D8 004D92D8 0000028E */  lw         $2, 0x0($16)
  .L004D92DC:
    /* 3D92DC 004D92DC 01004224 */  addiu      $2, $2, 0x1
    /* 3D92E0 004D92E0 0800BFDF */  ld         $31, 0x8($29)
    /* 3D92E4 004D92E4 000002AE */  sw         $2, 0x0($16)
    /* 3D92E8 004D92E8 0000B0DF */  ld         $16, 0x0($29)
    /* 3D92EC 004D92EC 0800E003 */  jr         $31
    /* 3D92F0 004D92F0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D92F4 004D92F4 00000000 */  nop
.size func_004d92a8, 0x50
