.section .text
.set noat
.set noreorder
glabel func_001d3d50
    /* D3D50 001D3D50 E0FFBD27 */  addiu      $29, $29, -0x20
    /* D3D54 001D3D54 1000BFFF */  sd         $31, 0x10($29)
    /* D3D58 001D3D58 0000B07F */  sq         $16, 0x0($29)
    /* D3D5C 001D3D5C 2D808000 */  daddu      $16, $4, $0
    /* D3D60 001D3D60 6100043C */  lui        $4, %hi(D_00609498)
    /* D3D64 001D3D64 98948424 */  addiu      $4, $4, %lo(D_00609498)
    /* D3D68 001D3D68 3A000524 */  addiu      $5, $0, 0x3A
    /* D3D6C 001D3D6C A43A110C */  jal        func_0044ea90
    /* D3D70 001D3D70 00000000 */   nop
    /* D3D74 001D3D74 38060424 */  addiu      $4, $0, 0x638
    /* D3D78 001D3D78 0400053C */  lui        $5, (0x40000 >> 16)
    /* D3D7C 001D3D7C 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* D3D80 001D3D80 E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* D3D84 001D3D84 09F84000 */  jalr       $2
    /* D3D88 001D3D88 00000000 */   nop
    /* D3D8C 001D3D8C FFFF0432 */  andi       $4, $16, 0xFFFF
    /* D3D90 001D3D90 02000324 */  addiu      $3, $0, 0x2
    /* D3D94 001D3D94 0E008310 */  beq        $4, $3, .L001D3DD0
    /* D3D98 001D3D98 00000000 */   nop
    /* D3D9C 001D3D9C 01000324 */  addiu      $3, $0, 0x1
    /* D3DA0 001D3DA0 08008310 */  beq        $4, $3, .L001D3DC4
    /* D3DA4 001D3DA4 00000000 */   nop
    /* D3DA8 001D3DA8 03008010 */  beqz       $4, .L001D3DB8
    /* D3DAC 001D3DAC 00000000 */   nop
    /* D3DB0 001D3DB0 09000010 */  b          .L001D3DD8
    /* D3DB4 001D3DB4 00000000 */   nop
  .L001D3DB8:
    /* D3DB8 001D3DB8 300640A4 */  sh         $0, 0x630($2)
    /* D3DBC 001D3DBC 06000010 */  b          .L001D3DD8
    /* D3DC0 001D3DC0 00000000 */   nop
  .L001D3DC4:
    /* D3DC4 001D3DC4 300640A4 */  sh         $0, 0x630($2)
    /* D3DC8 001D3DC8 03000010 */  b          .L001D3DD8
    /* D3DCC 001D3DCC 00000000 */   nop
  .L001D3DD0:
    /* D3DD0 001D3DD0 08000324 */  addiu      $3, $0, 0x8
    /* D3DD4 001D3DD4 300643A4 */  sh         $3, 0x630($2)
  .L001D3DD8:
    /* D3DD8 001D3DD8 01000324 */  addiu      $3, $0, 0x1
    /* D3DDC 001D3DDC 320643A4 */  sh         $3, 0x632($2)
    /* D3DE0 001D3DE0 340640AC */  sw         $0, 0x634($2)
    /* D3DE4 001D3DE4 1000BFDF */  ld         $31, 0x10($29)
    /* D3DE8 001D3DE8 0000B07B */  lq         $16, 0x0($29)
    /* D3DEC 001D3DEC 2000BD27 */  addiu      $29, $29, 0x20
    /* D3DF0 001D3DF0 0800E003 */  jr         $31
    /* D3DF4 001D3DF4 00000000 */   nop
    /* D3DF8 001D3DF8 00000000 */  nop
    /* D3DFC 001D3DFC 00000000 */  nop
.size func_001d3d50, 0xb0
