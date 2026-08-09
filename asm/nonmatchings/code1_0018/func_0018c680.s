.section .text
.set noat
.set noreorder
glabel func_0018c680
    /* 8C680 0018C680 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 8C684 0018C684 1000BFFF */  sd         $31, 0x10($29)
    /* 8C688 0018C688 0000B07F */  sq         $16, 0x0($29)
    /* 8C68C 0018C68C 2D808000 */  daddu      $16, $4, $0
    /* 8C690 0018C690 2D30A000 */  daddu      $6, $5, $0
    /* 8C694 0018C694 1800848C */  lw         $4, 0x18($4)
    /* 8C698 0018C698 1900053C */  lui        $5, %hi(func_0018c610)
    /* 8C69C 0018C69C 10C6A524 */  addiu      $5, $5, %lo(func_0018c610)
    /* 8C6A0 0018C6A0 78080F0C */  jal        func_003c21e0
    /* 8C6A4 0018C6A4 00000000 */   nop
    /* 8C6A8 0018C6A8 2D100002 */  daddu      $2, $16, $0
    /* 8C6AC 0018C6AC 1000BFDF */  ld         $31, 0x10($29)
    /* 8C6B0 0018C6B0 0000B07B */  lq         $16, 0x0($29)
    /* 8C6B4 0018C6B4 2000BD27 */  addiu      $29, $29, 0x20
    /* 8C6B8 0018C6B8 0800E003 */  jr         $31
    /* 8C6BC 0018C6BC 00000000 */   nop
.size func_0018c680, 0x40
