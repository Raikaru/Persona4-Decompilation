.section .text
.set noat
.set noreorder
glabel func_001e3d30
    /* E3D30 001E3D30 E0FFBD27 */  addiu      $29, $29, -0x20
    /* E3D34 001E3D34 1000BFFF */  sd         $31, 0x10($29)
    /* E3D38 001E3D38 0000B07F */  sq         $16, 0x0($29)
    /* E3D3C 001E3D3C 2D200000 */  daddu      $4, $0, $0
    /* E3D40 001E3D40 00730A0C */  jal        func_0029cc00
    /* E3D44 001E3D44 00000000 */   nop
    /* E3D48 001E3D48 3C1A0200 */  dsll32     $3, $2, 8
    /* E3D4C 001E3D4C 3E1A0300 */  dsrl32     $3, $3, 8
    /* E3D50 001E3D50 0046023C */  lui        $2, (0x46000000 >> 16)
    /* E3D54 001E3D54 25806200 */  or         $16, $3, $2
    /* E3D58 001E3D58 14740A0C */  jal        func_0029d050
    /* E3D5C 001E3D5C 00000000 */   nop
    /* E3D60 001E3D60 00FF033C */  lui        $3, (0xFF000000 >> 16)
    /* E3D64 001E3D64 24180302 */  and        $3, $16, $3
    /* E3D68 001E3D68 021E0300 */  srl        $3, $3, 24
    /* E3D6C 001E3D6C 3C2A1000 */  dsll32     $5, $16, 8
    /* E3D70 001E3D70 3E2A0500 */  dsrl32     $5, $5, 8
    /* E3D74 001E3D74 04006014 */  bnez       $3, .L001E3D88
    /* E3D78 001E3D78 00000000 */   nop
    /* E3D7C 001E3D7C 2D100000 */  daddu      $2, $0, $0
    /* E3D80 001E3D80 0B000010 */  b          .L001E3DB0
    /* E3D84 001E3D84 00000000 */   nop
  .L001E3D88:
    /* E3D88 001E3D88 2D204000 */  daddu      $4, $2, $0
    /* E3D8C 001E3D8C 40100300 */  sll        $2, $3, 1
    /* E3D90 001E3D90 21104300 */  addu       $2, $2, $3
    /* E3D94 001E3D94 80180200 */  sll        $3, $2, 2
    /* E3D98 001E3D98 6100023C */  lui        $2, %hi(D_00609850)
    /* E3D9C 001E3D9C 50984224 */  addiu      $2, $2, %lo(D_00609850)
    /* E3DA0 001E3DA0 21104300 */  addu       $2, $2, $3
    /* E3DA4 001E3DA4 0000428C */  lw         $2, 0x0($2)
    /* E3DA8 001E3DA8 09F84000 */  jalr       $2
    /* E3DAC 001E3DAC 00000000 */   nop
  .L001E3DB0:
    /* E3DB0 001E3DB0 2B200200 */  sltu       $4, $0, $2
    /* E3DB4 001E3DB4 D4730A0C */  jal        func_0029cf50
    /* E3DB8 001E3DB8 00000000 */   nop
    /* E3DBC 001E3DBC 01000224 */  addiu      $2, $0, 0x1
    /* E3DC0 001E3DC0 1000BFDF */  ld         $31, 0x10($29)
    /* E3DC4 001E3DC4 0000B07B */  lq         $16, 0x0($29)
    /* E3DC8 001E3DC8 2000BD27 */  addiu      $29, $29, 0x20
    /* E3DCC 001E3DCC 0800E003 */  jr         $31
    /* E3DD0 001E3DD0 00000000 */   nop
    /* E3DD4 001E3DD4 00000000 */  nop
    /* E3DD8 001E3DD8 00000000 */  nop
    /* E3DDC 001E3DDC 00000000 */  nop
.size func_001e3d30, 0xb0
