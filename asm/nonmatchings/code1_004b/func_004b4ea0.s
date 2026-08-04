.section .text
.set noat
.set noreorder
glabel func_004b4ea0
    /* 3B4EA0 004B4EA0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3B4EA4 004B4EA4 1000BFFF */  sd         $31, 0x10($29)
    /* 3B4EA8 004B4EA8 0000B07F */  sq         $16, 0x0($29)
    /* 3B4EAC 004B4EAC 2D808000 */  daddu      $16, $4, $0
    /* 3B4EB0 004B4EB0 2000848C */  lw         $4, 0x20($4)
    /* 3B4EB4 004B4EB4 1800038E */  lw         $3, 0x18($16)
    /* 3B4EB8 004B4EB8 40100300 */  sll        $2, $3, 1
    /* 3B4EBC 004B4EBC 21104300 */  addu       $2, $2, $3
    /* 3B4EC0 004B4EC0 C0180200 */  sll        $3, $2, 3
    /* 3B4EC4 004B4EC4 7100023C */  lui        $2, %hi(D_00714658)
    /* 3B4EC8 004B4EC8 58464224 */  addiu      $2, $2, %lo(D_00714658)
    /* 3B4ECC 004B4ECC 21104300 */  addu       $2, $2, $3
    /* 3B4ED0 004B4ED0 0000428C */  lw         $2, 0x0($2)
    /* 3B4ED4 004B4ED4 09F84000 */  jalr       $2
    /* 3B4ED8 004B4ED8 00000000 */   nop
    /* 3B4EDC 004B4EDC 2D200002 */  daddu      $4, $16, $0
    /* 3B4EE0 004B4EE0 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 3B4EE4 004B4EE4 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 3B4EE8 004B4EE8 09F84000 */  jalr       $2
    /* 3B4EEC 004B4EEC 00000000 */   nop
    /* 3B4EF0 004B4EF0 1000BFDF */  ld         $31, 0x10($29)
    /* 3B4EF4 004B4EF4 0000B07B */  lq         $16, 0x0($29)
    /* 3B4EF8 004B4EF8 2000BD27 */  addiu      $29, $29, 0x20
    /* 3B4EFC 004B4EFC 0800E003 */  jr         $31
    /* 3B4F00 004B4F00 00000000 */   nop
    /* 3B4F04 004B4F04 00000000 */  nop
    /* 3B4F08 004B4F08 00000000 */  nop
    /* 3B4F0C 004B4F0C 00000000 */  nop
.size func_004b4ea0, 0x70
