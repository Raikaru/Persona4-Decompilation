.section .text
.set noat
.set noreorder
glabel func_003cb820
    /* 2CB820 003CB820 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2CB824 003CB824 2000BFFF */  sd         $31, 0x20($29)
    /* 2CB828 003CB828 1000B17F */  sq         $17, 0x10($29)
    /* 2CB82C 003CB82C 0000B07F */  sq         $16, 0x0($29)
    /* 2CB830 003CB830 2D888000 */  daddu      $17, $4, $0
    /* 2CB834 003CB834 2D80C000 */  daddu      $16, $6, $0
    /* 2CB838 003CB838 08270F0C */  jal        func_003c9c20
    /* 2CB83C 003CB83C 2D200002 */   daddu     $4, $16, $0
    /* 2CB840 003CB840 7800048E */  lw         $4, 0x78($16)
    /* 2CB844 003CB844 2D302002 */  daddu      $6, $17, $0
    /* 2CB848 003CB848 2D284000 */  daddu      $5, $2, $0
    /* 2CB84C 003CB84C A4160F0C */  jal        func_003c5a90
    /* 2CB850 003CB850 10004724 */   addiu     $7, $2, 0x10
    /* 2CB854 003CB854 2000BFDF */  ld         $31, 0x20($29)
    /* 2CB858 003CB858 1000B17B */  lq         $17, 0x10($29)
    /* 2CB85C 003CB85C 0000B07B */  lq         $16, 0x0($29)
    /* 2CB860 003CB860 0800E003 */  jr         $31
    /* 2CB864 003CB864 3000BD27 */   addiu     $29, $29, 0x30
    /* 2CB868 003CB868 00000000 */  nop
    /* 2CB86C 003CB86C 00000000 */  nop
.size func_003cb820, 0x50
