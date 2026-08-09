.section .text
.set noat
.set noreorder
glabel func_001d3d00
    /* D3D00 001D3D00 E0FFBD27 */  addiu      $29, $29, -0x20
    /* D3D04 001D3D04 1000BFFF */  sd         $31, 0x10($29)
    /* D3D08 001D3D08 0000B07F */  sq         $16, 0x0($29)
    /* D3D0C 001D3D0C 2D808000 */  daddu      $16, $4, $0
    /* D3D10 001D3D10 070B0424 */  addiu      $4, $0, 0xB07
    /* D3D14 001D3D14 04000524 */  addiu      $5, $0, 0x4
    /* D3D18 001D3D18 1C51060C */  jal        func_00194470
    /* D3D1C 001D3D1C 00000000 */   nop
    /* D3D20 001D3D20 1D00033C */  lui        $3, %hi(func_001d3ba0)
    /* D3D24 001D3D24 A03B6324 */  addiu      $3, $3, %lo(func_001d3ba0)
    /* D3D28 001D3D28 6C0043AC */  sw         $3, 0x6C($2)
    /* D3D2C 001D3D2C 7800438C */  lw         $3, 0x78($2)
    /* D3D30 001D3D30 000070AC */  sw         $16, 0x0($3)
    /* D3D34 001D3D34 1000BFDF */  ld         $31, 0x10($29)
    /* D3D38 001D3D38 0000B07B */  lq         $16, 0x0($29)
    /* D3D3C 001D3D3C 2000BD27 */  addiu      $29, $29, 0x20
    /* D3D40 001D3D40 0800E003 */  jr         $31
    /* D3D44 001D3D44 00000000 */   nop
    /* D3D48 001D3D48 00000000 */  nop
    /* D3D4C 001D3D4C 00000000 */  nop
.size func_001d3d00, 0x50
