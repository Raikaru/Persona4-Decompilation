.section .text
.set noat
.set noreorder
glabel func_004a6dc0
    /* 3A6DC0 004A6DC0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3A6DC4 004A6DC4 1000BFFF */  sd         $31, 0x10($29)
    /* 3A6DC8 004A6DC8 0000B07F */  sq         $16, 0x0($29)
    /* 3A6DCC 004A6DCC 2D808000 */  daddu      $16, $4, $0
    /* 3A6DD0 004A6DD0 5800848C */  lw         $4, 0x58($4)
    /* 3A6DD4 004A6DD4 7010120C */  jal        func_004841c0
    /* 3A6DD8 004A6DD8 00000000 */   nop
    /* 3A6DDC 004A6DDC 2D200002 */  daddu      $4, $16, $0
    /* 3A6DE0 004A6DE0 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 3A6DE4 004A6DE4 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 3A6DE8 004A6DE8 09F84000 */  jalr       $2
    /* 3A6DEC 004A6DEC 00000000 */   nop
    /* 3A6DF0 004A6DF0 1000BFDF */  ld         $31, 0x10($29)
    /* 3A6DF4 004A6DF4 0000B07B */  lq         $16, 0x0($29)
    /* 3A6DF8 004A6DF8 2000BD27 */  addiu      $29, $29, 0x20
    /* 3A6DFC 004A6DFC 0800E003 */  jr         $31
    /* 3A6E00 004A6E00 00000000 */   nop
    /* 3A6E04 004A6E04 00000000 */  nop
    /* 3A6E08 004A6E08 00000000 */  nop
    /* 3A6E0C 004A6E0C 00000000 */  nop
.size func_004a6dc0, 0x50
