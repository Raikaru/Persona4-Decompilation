.section .text
.set noat
.set noreorder
glabel func_003cb720
    /* 2CB720 003CB720 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2CB724 003CB724 2000BFFF */  sd         $31, 0x20($29)
    /* 2CB728 003CB728 1000B17F */  sq         $17, 0x10($29)
    /* 2CB72C 003CB72C 0000B07F */  sq         $16, 0x0($29)
    /* 2CB730 003CB730 2D888000 */  daddu      $17, $4, $0
    /* 2CB734 003CB734 2D80C000 */  daddu      $16, $6, $0
    /* 2CB738 003CB738 2D280002 */  daddu      $5, $16, $0
    /* 2CB73C 003CB73C 44170F0C */  jal        func_003c5d10
    /* 2CB740 003CB740 20000626 */   addiu     $6, $16, 0x20
    /* 2CB744 003CB744 540002AE */  sw         $2, 0x54($16)
    /* 2CB748 003CB748 5400028E */  lw         $2, 0x54($16)
    /* 2CB74C 003CB74C 0A880200 */  movz       $17, $0, $2
    /* 2CB750 003CB750 2D102002 */  daddu      $2, $17, $0
    /* 2CB754 003CB754 2000BFDF */  ld         $31, 0x20($29)
    /* 2CB758 003CB758 1000B17B */  lq         $17, 0x10($29)
    /* 2CB75C 003CB75C 0000B07B */  lq         $16, 0x0($29)
    /* 2CB760 003CB760 0800E003 */  jr         $31
    /* 2CB764 003CB764 3000BD27 */   addiu     $29, $29, 0x30
    /* 2CB768 003CB768 00000000 */  nop
    /* 2CB76C 003CB76C 00000000 */  nop
.size func_003cb720, 0x50
