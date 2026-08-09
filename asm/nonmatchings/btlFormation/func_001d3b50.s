.section .text
.set noat
.set noreorder
glabel func_001d3b50
    /* D3B50 001D3B50 E0FFBD27 */  addiu      $29, $29, -0x20
    /* D3B54 001D3B54 1000BFFF */  sd         $31, 0x10($29)
    /* D3B58 001D3B58 0000B07F */  sq         $16, 0x0($29)
    /* D3B5C 001D3B5C 2D808000 */  daddu      $16, $4, $0
    /* D3B60 001D3B60 060B0424 */  addiu      $4, $0, 0xB06
    /* D3B64 001D3B64 04000524 */  addiu      $5, $0, 0x4
    /* D3B68 001D3B68 1C51060C */  jal        func_00194470
    /* D3B6C 001D3B6C 00000000 */   nop
    /* D3B70 001D3B70 1D00033C */  lui        $3, %hi(func_001d3950)
    /* D3B74 001D3B74 50396324 */  addiu      $3, $3, %lo(func_001d3950)
    /* D3B78 001D3B78 6C0043AC */  sw         $3, 0x6C($2)
    /* D3B7C 001D3B7C 7800438C */  lw         $3, 0x78($2)
    /* D3B80 001D3B80 000070AC */  sw         $16, 0x0($3)
    /* D3B84 001D3B84 1000BFDF */  ld         $31, 0x10($29)
    /* D3B88 001D3B88 0000B07B */  lq         $16, 0x0($29)
    /* D3B8C 001D3B8C 2000BD27 */  addiu      $29, $29, 0x20
    /* D3B90 001D3B90 0800E003 */  jr         $31
    /* D3B94 001D3B94 00000000 */   nop
    /* D3B98 001D3B98 00000000 */  nop
    /* D3B9C 001D3B9C 00000000 */  nop
.size func_001d3b50, 0x50
