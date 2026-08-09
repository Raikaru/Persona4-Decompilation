.section .text
.set noat
.set noreorder
glabel func_003cb790
    /* 2CB790 003CB790 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2CB794 003CB794 2D28C000 */  daddu      $5, $6, $0
    /* 2CB798 003CB798 1000BFFF */  sd         $31, 0x10($29)
    /* 2CB79C 003CB79C 0000B07F */  sq         $16, 0x0($29)
    /* 2CB7A0 003CB7A0 58390F0C */  jal        func_003ce560
    /* 2CB7A4 003CB7A4 2D808000 */   daddu     $16, $4, $0
    /* 2CB7A8 003CB7A8 0A800200 */  movz       $16, $0, $2
    /* 2CB7AC 003CB7AC 2D100002 */  daddu      $2, $16, $0
    /* 2CB7B0 003CB7B0 1000BFDF */  ld         $31, 0x10($29)
    /* 2CB7B4 003CB7B4 0000B07B */  lq         $16, 0x0($29)
    /* 2CB7B8 003CB7B8 0800E003 */  jr         $31
    /* 2CB7BC 003CB7BC 2000BD27 */   addiu     $29, $29, 0x20
.size func_003cb790, 0x30
