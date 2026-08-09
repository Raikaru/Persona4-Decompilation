.section .text
.set noat
.set noreorder
glabel func_002bdb10
    /* 1BDB10 002BDB10 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 1BDB14 002BDB14 1000BFFF */  sd         $31, 0x10($29)
    /* 1BDB18 002BDB18 0000B07F */  sq         $16, 0x0($29)
    /* 1BDB1C 002BDB1C 2D808000 */  daddu      $16, $4, $0
    /* 1BDB20 002BDB20 2014050C */  jal        func_00145080
    /* 1BDB24 002BDB24 00000000 */   nop
    /* 1BDB28 002BDB28 3800048E */  lw         $4, 0x38($16)
    /* 1BDB2C 002BDB2C 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 1BDB30 002BDB30 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 1BDB34 002BDB34 09F84000 */  jalr       $2
    /* 1BDB38 002BDB38 00000000 */   nop
    /* 1BDB3C 002BDB3C 1000BFDF */  ld         $31, 0x10($29)
    /* 1BDB40 002BDB40 0000B07B */  lq         $16, 0x0($29)
    /* 1BDB44 002BDB44 2000BD27 */  addiu      $29, $29, 0x20
    /* 1BDB48 002BDB48 0800E003 */  jr         $31
    /* 1BDB4C 002BDB4C 00000000 */   nop
.size func_002bdb10, 0x40
