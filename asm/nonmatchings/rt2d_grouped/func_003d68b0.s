.section .text
.set noat
.set noreorder
glabel func_003d68b0
    /* 2D68B0 003D68B0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2D68B4 003D68B4 2000BFFF */  sd         $31, 0x20($29)
    /* 2D68B8 003D68B8 1000B17F */  sq         $17, 0x10($29)
    /* 2D68BC 003D68BC 2D888000 */  daddu      $17, $4, $0
    /* 2D68C0 003D68C0 0000B07F */  sq         $16, 0x0($29)
    /* 2D68C4 003D68C4 1400848C */  lw         $4, 0x14($4)
    /* 2D68C8 003D68C8 CC5E0F0C */  jal        func_003d7b30
    /* 2D68CC 003D68CC 04001024 */   addiu     $16, $0, 0x4
    /* 2D68D0 003D68D0 21180202 */  addu       $3, $16, $2
    /* 2D68D4 003D68D4 2000BFDF */  ld         $31, 0x20($29)
    /* 2D68D8 003D68D8 0400228E */  lw         $2, 0x4($17)
    /* 2D68DC 003D68DC 0000B07B */  lq         $16, 0x0($29)
    /* 2D68E0 003D68E0 1000B17B */  lq         $17, 0x10($29)
    /* 2D68E4 003D68E4 40110200 */  sll        $2, $2, 5
    /* 2D68E8 003D68E8 21106200 */  addu       $2, $3, $2
    /* 2D68EC 003D68EC 0800E003 */  jr         $31
    /* 2D68F0 003D68F0 3000BD27 */   addiu     $29, $29, 0x30
    /* 2D68F4 003D68F4 00000000 */  nop
    /* 2D68F8 003D68F8 00000000 */  nop
    /* 2D68FC 003D68FC 00000000 */  nop
.size func_003d68b0, 0x50
