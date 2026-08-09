.section .text
.set noat
.set noreorder
glabel func_004d9d68
    /* 3D9D68 004D9D68 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D9D6C 004D9D6C 7300023C */  lui        $2, %hi(D_007288B8)
    /* 3D9D70 004D9D70 0000B0FF */  sd         $16, 0x0($29)
    /* 3D9D74 004D9D74 B8885024 */  addiu      $16, $2, %lo(D_007288B8)
    /* 3D9D78 004D9D78 0000028E */  lw         $2, 0x0($16)
    /* 3D9D7C 004D9D7C 09004014 */  bnez       $2, .L004D9DA4
    /* 3D9D80 004D9D80 0800BFFF */   sd        $31, 0x8($29)
    /* 3D9D84 004D9D84 8875130C */  jal        func_004dd620
    /* 3D9D88 004D9D88 00000000 */   nop
    /* 3D9D8C 004D9D8C 7300043C */  lui        $4, %hi(D_007288E8)
    /* 3D9D90 004D9D90 E8888424 */  addiu      $4, $4, %lo(D_007288E8)
    /* 3D9D94 004D9D94 2D280000 */  daddu      $5, $0, $0
    /* 3D9D98 004D9D98 72FE100C */  jal        func_0043f9c8
    /* 3D9D9C 004D9D9C 40000624 */   addiu     $6, $0, 0x40
    /* 3D9DA0 004D9DA0 0000028E */  lw         $2, 0x0($16)
  .L004D9DA4:
    /* 3D9DA4 004D9DA4 01004224 */  addiu      $2, $2, 0x1
    /* 3D9DA8 004D9DA8 0800BFDF */  ld         $31, 0x8($29)
    /* 3D9DAC 004D9DAC 000002AE */  sw         $2, 0x0($16)
    /* 3D9DB0 004D9DB0 0000B0DF */  ld         $16, 0x0($29)
    /* 3D9DB4 004D9DB4 0800E003 */  jr         $31
    /* 3D9DB8 004D9DB8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D9DBC 004D9DBC 00000000 */  nop
.size func_004d9d68, 0x58
