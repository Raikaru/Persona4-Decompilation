.section .text
.set noat
.set noreorder
glabel func_003a3d50
    /* 2A3D50 003A3D50 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 2A3D54 003A3D54 3000BFFF */  sd         $31, 0x30($29)
    /* 2A3D58 003A3D58 2000B27F */  sq         $18, 0x20($29)
    /* 2A3D5C 003A3D5C 1000B17F */  sq         $17, 0x10($29)
    /* 2A3D60 003A3D60 0000B07F */  sq         $16, 0x0($29)
    /* 2A3D64 003A3D64 10B6838F */  lw         $3, -0x49F0($28)
    /* 2A3D68 003A3D68 21188300 */  addu       $3, $4, $3
    /* 2A3D6C 003A3D6C 0000648C */  lw         $4, 0x0($3)
    /* 2A3D70 003A3D70 4400838C */  lw         $3, 0x44($4)
    /* 2A3D74 003A3D74 10006330 */  andi       $3, $3, 0x10
    /* 2A3D78 003A3D78 11006014 */  bnez       $3, .L003A3DC0
    /* 2A3D7C 003A3D7C 00000000 */   nop
    /* 2A3D80 003A3D80 9C00908C */  lw         $16, 0x9C($4)
    /* 2A3D84 003A3D84 2D900000 */  daddu      $18, $0, $0
    /* 2A3D88 003A3D88 2D880002 */  daddu      $17, $16, $0
  .L003A3D8C:
    /* 2A3D8C 003A3D8C 3801248E */  lw         $4, 0x138($17)
    /* 2A3D90 003A3D90 05008010 */  beqz       $4, .L003A3DA8
    /* 2A3D94 003A3D94 00000000 */   nop
    /* 2A3D98 003A3D98 A8870F0C */  jal        func_003e1ea0
    /* 2A3D9C 003A3D9C 00000000 */   nop
    /* 2A3DA0 003A3DA0 380120AE */  sw         $0, 0x138($17)
    /* 2A3DA4 003A3DA4 00000000 */  nop
  .L003A3DA8:
    /* 2A3DA8 003A3DA8 E800038E */  lw         $3, 0xE8($16)
    /* 2A3DAC 003A3DAC 01005226 */  addiu      $18, $18, 0x1
    /* 2A3DB0 003A3DB0 2B087200 */  sltu       $1, $3, $18
    /* 2A3DB4 003A3DB4 F5FF2010 */  beqz       $1, .L003A3D8C
    /* 2A3DB8 003A3DB8 04003126 */   addiu     $17, $17, 0x4
    /* 2A3DBC 003A3DBC 00000000 */  nop
  .L003A3DC0:
    /* 2A3DC0 003A3DC0 3000BFDF */  ld         $31, 0x30($29)
    /* 2A3DC4 003A3DC4 2000B27B */  lq         $18, 0x20($29)
    /* 2A3DC8 003A3DC8 1000B17B */  lq         $17, 0x10($29)
    /* 2A3DCC 003A3DCC 0000B07B */  lq         $16, 0x0($29)
    /* 2A3DD0 003A3DD0 0800E003 */  jr         $31
    /* 2A3DD4 003A3DD4 4000BD27 */   addiu     $29, $29, 0x40
    /* 2A3DD8 003A3DD8 00000000 */  nop
    /* 2A3DDC 003A3DDC 00000000 */  nop
.size func_003a3d50, 0x90
