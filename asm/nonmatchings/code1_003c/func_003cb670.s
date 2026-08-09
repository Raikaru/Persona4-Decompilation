.section .text
.set noat
.set noreorder
glabel func_003cb670
    /* 2CB670 003CB670 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2CB674 003CB674 1000BFFF */  sd         $31, 0x10($29)
    /* 2CB678 003CB678 0000B07F */  sq         $16, 0x0($29)
    /* 2CB67C 003CB67C 2D808000 */  daddu      $16, $4, $0
    /* 2CB680 003CB680 2D20A000 */  daddu      $4, $5, $0
    /* 2CB684 003CB684 242F0F0C */  jal        func_003cbc90
    /* 2CB688 003CB688 2D280002 */   daddu     $5, $16, $0
    /* 2CB68C 003CB68C 2D100002 */  daddu      $2, $16, $0
    /* 2CB690 003CB690 1000BFDF */  ld         $31, 0x10($29)
    /* 2CB694 003CB694 0000B07B */  lq         $16, 0x0($29)
    /* 2CB698 003CB698 0800E003 */  jr         $31
    /* 2CB69C 003CB69C 2000BD27 */   addiu     $29, $29, 0x20
.size func_003cb670, 0x30
