.section .text
.set noat
.set noreorder
glabel func_004ac8e0
    /* 3AC8E0 004AC8E0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3AC8E4 004AC8E4 1000BFFF */  sd         $31, 0x10($29)
    /* 3AC8E8 004AC8E8 0000B07F */  sq         $16, 0x0($29)
    /* 3AC8EC 004AC8EC 2D808000 */  daddu      $16, $4, $0
    /* 3AC8F0 004AC8F0 B400848C */  lw         $4, 0xB4($4)
    /* 3AC8F4 004AC8F4 03008010 */  beqz       $4, .L004AC904
    /* 3AC8F8 004AC8F8 00000000 */   nop
    /* 3AC8FC 004AC8FC F8E1110C */  jal        func_004787e0
    /* 3AC900 004AC900 00000000 */   nop
  .L004AC904:
    /* 3AC904 004AC904 2D200002 */  daddu      $4, $16, $0
    /* 3AC908 004AC908 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 3AC90C 004AC90C EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 3AC910 004AC910 09F84000 */  jalr       $2
    /* 3AC914 004AC914 00000000 */   nop
    /* 3AC918 004AC918 1000BFDF */  ld         $31, 0x10($29)
    /* 3AC91C 004AC91C 0000B07B */  lq         $16, 0x0($29)
    /* 3AC920 004AC920 2000BD27 */  addiu      $29, $29, 0x20
    /* 3AC924 004AC924 0800E003 */  jr         $31
    /* 3AC928 004AC928 00000000 */   nop
    /* 3AC92C 004AC92C 00000000 */  nop
.size func_004ac8e0, 0x50
