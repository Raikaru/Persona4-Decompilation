.section .text
.set noat
.set noreorder
glabel func_004d3588
    /* 3D3588 004D3588 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3D358C 004D358C 2D10A000 */  daddu      $2, $5, $0
    /* 3D3590 004D3590 FF07C724 */  addiu      $7, $6, 0x7FF
    /* 3D3594 004D3594 2D304000 */  daddu      $6, $2, $0
    /* 3D3598 004D3598 7600053C */  lui        $5, %hi(D_00758B20)
    /* 3D359C 004D359C 2000B0FF */  sd         $16, 0x20($29)
    /* 3D35A0 004D35A0 C23A0700 */  srl        $7, $7, 11
    /* 3D35A4 004D35A4 208BA524 */  addiu      $5, $5, %lo(D_00758B20)
    /* 3D35A8 004D35A8 2D808000 */  daddu      $16, $4, $0
    /* 3D35AC 004D35AC 2800BFFF */  sd         $31, 0x28($29)
    /* 3D35B0 004D35B0 2208110C */  jal        func_00442088
    /* 3D35B4 004D35B4 2D20A003 */   daddu     $4, $29, $0
    /* 3D35B8 004D35B8 2D28A003 */  daddu      $5, $29, $0
    /* 3D35BC 004D35BC DE5B130C */  jal        func_004d6f78
    /* 3D35C0 004D35C0 2D200002 */   daddu     $4, $16, $0
    /* 3D35C4 004D35C4 2000B0DF */  ld         $16, 0x20($29)
    /* 3D35C8 004D35C8 2800BFDF */  ld         $31, 0x28($29)
    /* 3D35CC 004D35CC 0800E003 */  jr         $31
    /* 3D35D0 004D35D0 3000BD27 */   addiu     $29, $29, 0x30
    /* 3D35D4 004D35D4 00000000 */  nop
.size func_004d3588, 0x50
