.section .text
.set noat
.set noreorder
glabel func_003e42a0
    /* 2E42A0 003E42A0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2E42A4 003E42A4 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2E42A8 003E42A8 1000BFFF */  sd         $31, 0x10($29)
    /* 2E42AC 003E42AC E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2E42B0 003E42B0 0000B07F */  sq         $16, 0x0($29)
    /* 2E42B4 003E42B4 A0B7838F */  lw         $3, -0x4860($28)
    /* 2E42B8 003E42B8 21104300 */  addu       $2, $2, $3
    /* 2E42BC 003E42BC 0800428C */  lw         $2, 0x8($2)
    /* 2E42C0 003E42C0 09F84000 */  jalr       $2
    /* 2E42C4 003E42C4 2D808000 */   daddu     $16, $4, $0
    /* 2E42C8 003E42C8 2D100002 */  daddu      $2, $16, $0
    /* 2E42CC 003E42CC 1000BFDF */  ld         $31, 0x10($29)
    /* 2E42D0 003E42D0 0000B07B */  lq         $16, 0x0($29)
    /* 2E42D4 003E42D4 0800E003 */  jr         $31
    /* 2E42D8 003E42D8 2000BD27 */   addiu     $29, $29, 0x20
    /* 2E42DC 003E42DC 00000000 */  nop
.size func_003e42a0, 0x40
