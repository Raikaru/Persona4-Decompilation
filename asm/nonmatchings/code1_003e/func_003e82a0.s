.section .text
.set noat
.set noreorder
glabel func_003e82a0
    /* 2E82A0 003E82A0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2E82A4 003E82A4 8800023C */  lui        $2, %hi(D_0088737C)
    /* 2E82A8 003E82A8 1000BFFF */  sd         $31, 0x10($29)
    /* 2E82AC 003E82AC 0000B07F */  sq         $16, 0x0($29)
    /* 2E82B0 003E82B0 7C73428C */  lw         $2, %lo(D_0088737C)($2)
    /* 2E82B4 003E82B4 09F84000 */  jalr       $2
    /* 2E82B8 003E82B8 2D808000 */   daddu     $16, $4, $0
    /* 2E82BC 003E82BC 0A800200 */  movz       $16, $0, $2
    /* 2E82C0 003E82C0 2D100002 */  daddu      $2, $16, $0
    /* 2E82C4 003E82C4 1000BFDF */  ld         $31, 0x10($29)
    /* 2E82C8 003E82C8 0000B07B */  lq         $16, 0x0($29)
    /* 2E82CC 003E82CC 0800E003 */  jr         $31
    /* 2E82D0 003E82D0 2000BD27 */   addiu     $29, $29, 0x20
    /* 2E82D4 003E82D4 00000000 */  nop
    /* 2E82D8 003E82D8 00000000 */  nop
    /* 2E82DC 003E82DC 00000000 */  nop
.size func_003e82a0, 0x40
