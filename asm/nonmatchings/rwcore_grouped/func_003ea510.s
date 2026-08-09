.section .text
.set noat
.set noreorder
glabel func_003ea510
    /* 2EA510 003EA510 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2EA514 003EA514 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2EA518 003EA518 1000BFFF */  sd         $31, 0x10($29)
    /* 2EA51C 003EA51C 0000B07F */  sq         $16, 0x0($29)
    /* 2EA520 003EA520 2D808000 */  daddu      $16, $4, $0
    /* 2EA524 003EA524 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2EA528 003EA528 09F84000 */  jalr       $2
    /* 2EA52C 003EA52C 1400848C */   lw        $4, 0x14($4)
    /* 2EA530 003EA530 140000AE */  sw         $0, 0x14($16)
    /* 2EA534 003EA534 FEFF0324 */  addiu      $3, $0, -0x2
    /* 2EA538 003EA538 180000AE */  sw         $0, 0x18($16)
    /* 2EA53C 003EA53C 2D100002 */  daddu      $2, $16, $0
    /* 2EA540 003EA540 0000048E */  lw         $4, 0x0($16)
    /* 2EA544 003EA544 24188300 */  and        $3, $4, $3
    /* 2EA548 003EA548 000003AE */  sw         $3, 0x0($16)
    /* 2EA54C 003EA54C 1000BFDF */  ld         $31, 0x10($29)
    /* 2EA550 003EA550 0000B07B */  lq         $16, 0x0($29)
    /* 2EA554 003EA554 0800E003 */  jr         $31
    /* 2EA558 003EA558 2000BD27 */   addiu     $29, $29, 0x20
    /* 2EA55C 003EA55C 00000000 */  nop
.size func_003ea510, 0x50
