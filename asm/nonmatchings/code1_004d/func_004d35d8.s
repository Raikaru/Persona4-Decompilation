.section .text
.set noat
.set noreorder
glabel func_004d35d8
    /* 3D35D8 004D35D8 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3D35DC 004D35DC 2D10A000 */  daddu      $2, $5, $0
    /* 3D35E0 004D35E0 FF07C724 */  addiu      $7, $6, 0x7FF
    /* 3D35E4 004D35E4 2D304000 */  daddu      $6, $2, $0
    /* 3D35E8 004D35E8 7600053C */  lui        $5, %hi(D_00758B20)
    /* 3D35EC 004D35EC 2000B0FF */  sd         $16, 0x20($29)
    /* 3D35F0 004D35F0 C23A0700 */  srl        $7, $7, 11
    /* 3D35F4 004D35F4 208BA524 */  addiu      $5, $5, %lo(D_00758B20)
    /* 3D35F8 004D35F8 2D808000 */  daddu      $16, $4, $0
    /* 3D35FC 004D35FC 2800BFFF */  sd         $31, 0x28($29)
    /* 3D3600 004D3600 2208110C */  jal        func_00442088
    /* 3D3604 004D3604 2D20A003 */   daddu     $4, $29, $0
    /* 3D3608 004D3608 2D28A003 */  daddu      $5, $29, $0
    /* 3D360C 004D360C CA2B130C */  jal        func_004caf28
    /* 3D3610 004D3610 2D200002 */   daddu     $4, $16, $0
    /* 3D3614 004D3614 2000B0DF */  ld         $16, 0x20($29)
    /* 3D3618 004D3618 2800BFDF */  ld         $31, 0x28($29)
    /* 3D361C 004D361C 0800E003 */  jr         $31
    /* 3D3620 004D3620 3000BD27 */   addiu     $29, $29, 0x30
    /* 3D3624 004D3624 00000000 */  nop
.size func_004d35d8, 0x50
