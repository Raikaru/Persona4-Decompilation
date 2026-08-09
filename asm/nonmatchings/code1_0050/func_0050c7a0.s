.section .text
.set noat
.set noreorder
glabel func_0050c7a0
    /* 40C7A0 0050C7A0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 40C7A4 0050C7A4 2D10A000 */  daddu      $2, $5, $0
    /* 40C7A8 0050C7A8 FF07C724 */  addiu      $7, $6, 0x7FF
    /* 40C7AC 0050C7AC 2D304000 */  daddu      $6, $2, $0
    /* 40C7B0 0050C7B0 7600053C */  lui        $5, %hi(D_0075EFC0)
    /* 40C7B4 0050C7B4 2000B0FF */  sd         $16, 0x20($29)
    /* 40C7B8 0050C7B8 C23A0700 */  srl        $7, $7, 11
    /* 40C7BC 0050C7BC C0EFA524 */  addiu      $5, $5, %lo(D_0075EFC0)
    /* 40C7C0 0050C7C0 2D808000 */  daddu      $16, $4, $0
    /* 40C7C4 0050C7C4 2800BFFF */  sd         $31, 0x28($29)
    /* 40C7C8 0050C7C8 2208110C */  jal        func_00442088
    /* 40C7CC 0050C7CC 2D20A003 */   daddu     $4, $29, $0
    /* 40C7D0 0050C7D0 2D28A003 */  daddu      $5, $29, $0
    /* 40C7D4 0050C7D4 0230140C */  jal        func_0050c008
    /* 40C7D8 0050C7D8 2D200002 */   daddu     $4, $16, $0
    /* 40C7DC 0050C7DC 2000B0DF */  ld         $16, 0x20($29)
    /* 40C7E0 0050C7E0 2800BFDF */  ld         $31, 0x28($29)
    /* 40C7E4 0050C7E4 0800E003 */  jr         $31
    /* 40C7E8 0050C7E8 3000BD27 */   addiu     $29, $29, 0x30
    /* 40C7EC 0050C7EC 00000000 */  nop
.size func_0050c7a0, 0x50
