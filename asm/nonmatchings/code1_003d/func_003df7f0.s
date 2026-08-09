.section .text
.set noat
.set noreorder
glabel func_003df7f0
    /* 2DF7F0 003DF7F0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2DF7F4 003DF7F4 1000BFFF */  sd         $31, 0x10($29)
    /* 2DF7F8 003DF7F8 0000B07F */  sq         $16, 0x0($29)
    /* 2DF7FC 003DF7FC 2D808000 */  daddu      $16, $4, $0
    /* 2DF800 003DF800 0000848C */  lw         $4, 0x0($4)
    /* 2DF804 003DF804 0A008010 */  beqz       $4, .L003DF830
    /* 2DF808 003DF808 00000000 */   nop
    /* 2DF80C 003DF80C 0800028E */  lw         $2, 0x8($16)
    /* 2DF810 003DF810 07004010 */  beqz       $2, .L003DF830
    /* 2DF814 003DF814 00000000 */   nop
    /* 2DF818 003DF818 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2DF81C 003DF81C EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2DF820 003DF820 09F84000 */  jalr       $2
    /* 2DF824 003DF824 00000000 */   nop
    /* 2DF828 003DF828 000000AE */  sw         $0, 0x0($16)
    /* 2DF82C 003DF82C 080000AE */  sw         $0, 0x8($16)
  .L003DF830:
    /* 2DF830 003DF830 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2DF834 003DF834 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2DF838 003DF838 09F84000 */  jalr       $2
    /* 2DF83C 003DF83C 2D200002 */   daddu     $4, $16, $0
    /* 2DF840 003DF840 1000BFDF */  ld         $31, 0x10($29)
    /* 2DF844 003DF844 01000224 */  addiu      $2, $0, 0x1
    /* 2DF848 003DF848 0000B07B */  lq         $16, 0x0($29)
    /* 2DF84C 003DF84C 0800E003 */  jr         $31
    /* 2DF850 003DF850 2000BD27 */   addiu     $29, $29, 0x20
    /* 2DF854 003DF854 00000000 */  nop
    /* 2DF858 003DF858 00000000 */  nop
    /* 2DF85C 003DF85C 00000000 */  nop
.size func_003df7f0, 0x70
