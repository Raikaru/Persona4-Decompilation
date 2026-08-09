.section .text
.set noat
.set noreorder
glabel func_004bd760
    /* 3BD760 004BD760 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BD764 004BD764 0000B0FF */  sd         $16, 0x0($29)
    /* 3BD768 004BD768 2D808000 */  daddu      $16, $4, $0
    /* 3BD76C 004BD76C 0800BFFF */  sd         $31, 0x8($29)
    /* 3BD770 004BD770 08F7120C */  jal        func_004bdc20
    /* 3BD774 004BD774 1C0005AE */   sw        $5, 0x1C($16)
    /* 3BD778 004BD778 200002AE */  sw         $2, 0x20($16)
    /* 3BD77C 004BD77C 0800BFDF */  ld         $31, 0x8($29)
    /* 3BD780 004BD780 0000B0DF */  ld         $16, 0x0($29)
    /* 3BD784 004BD784 0800E003 */  jr         $31
    /* 3BD788 004BD788 1000BD27 */   addiu     $29, $29, 0x10
    /* 3BD78C 004BD78C 00000000 */  nop
.size func_004bd760, 0x30
