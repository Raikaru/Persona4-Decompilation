.section .text
.set noat
.set noreorder
glabel func_0018e4d0
    /* 8E4D0 0018E4D0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 8E4D4 0018E4D4 1000BFFF */  sd         $31, 0x10($29)
    /* 8E4D8 0018E4D8 0000B07F */  sq         $16, 0x0($29)
    /* 8E4DC 0018E4DC 2D808000 */  daddu      $16, $4, $0
    /* 8E4E0 0018E4E0 3800828C */  lw         $2, 0x38($4)
    /* 8E4E4 0018E4E4 0400448C */  lw         $4, 0x4($2)
    /* 8E4E8 0018E4E8 03008010 */  beqz       $4, .L0018E4F8
    /* 8E4EC 0018E4EC 00000000 */   nop
    /* 8E4F0 0018E4F0 F8E1110C */  jal        func_004787e0
    /* 8E4F4 0018E4F4 00000000 */   nop
  .L0018E4F8:
    /* 8E4F8 0018E4F8 3800048E */  lw         $4, 0x38($16)
    /* 8E4FC 0018E4FC 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 8E500 0018E500 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 8E504 0018E504 09F84000 */  jalr       $2
    /* 8E508 0018E508 00000000 */   nop
    /* 8E50C 0018E50C 1000BFDF */  ld         $31, 0x10($29)
    /* 8E510 0018E510 0000B07B */  lq         $16, 0x0($29)
    /* 8E514 0018E514 2000BD27 */  addiu      $29, $29, 0x20
    /* 8E518 0018E518 0800E003 */  jr         $31
    /* 8E51C 0018E51C 00000000 */   nop
.size func_0018e4d0, 0x50
