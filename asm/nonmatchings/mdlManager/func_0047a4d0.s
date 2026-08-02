.section .text
.set noat
.set noreorder
glabel func_0047a4d0
    /* 37A4D0 0047A4D0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 37A4D4 0047A4D4 0000BFFF */  sd         $31, 0x0($29)
    /* 37A4D8 0047A4D8 1C00A5AF */  sw         $5, 0x1C($29)
    /* 37A4DC 0047A4DC DC00848C */  lw         $4, 0xDC($4)
    /* 37A4E0 0047A4E0 4800053C */  lui        $5, %hi(func_0047a4a0)
    /* 37A4E4 0047A4E4 A0A4A524 */  addiu      $5, $5, %lo(func_0047a4a0)
    /* 37A4E8 0047A4E8 1C00A627 */  addiu      $6, $29, 0x1C
    /* 37A4EC 0047A4EC CCFF0E0C */  jal        func_003bff30
    /* 37A4F0 0047A4F0 00000000 */   nop
    /* 37A4F4 0047A4F4 0000BFDF */  ld         $31, 0x0($29)
    /* 37A4F8 0047A4F8 2000BD27 */  addiu      $29, $29, 0x20
    /* 37A4FC 0047A4FC 0800E003 */  jr         $31
    /* 37A500 0047A500 00000000 */   nop
    /* 37A504 0047A504 00000000 */  nop
    /* 37A508 0047A508 00000000 */  nop
    /* 37A50C 0047A50C 00000000 */  nop
.size func_0047a4d0, 0x40
