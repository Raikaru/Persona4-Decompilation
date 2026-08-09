.section .text
.set noat
.set noreorder
glabel func_003cb7e0
    /* 2CB7E0 003CB7E0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2CB7E4 003CB7E4 2D28C000 */  daddu      $5, $6, $0
    /* 2CB7E8 003CB7E8 1000BFFF */  sd         $31, 0x10($29)
    /* 2CB7EC 003CB7EC 0000B07F */  sq         $16, 0x0($29)
    /* 2CB7F0 003CB7F0 EC3A0F0C */  jal        func_003cebb0
    /* 2CB7F4 003CB7F4 2D808000 */   daddu     $16, $4, $0
    /* 2CB7F8 003CB7F8 0A800200 */  movz       $16, $0, $2
    /* 2CB7FC 003CB7FC 2D100002 */  daddu      $2, $16, $0
    /* 2CB800 003CB800 1000BFDF */  ld         $31, 0x10($29)
    /* 2CB804 003CB804 0000B07B */  lq         $16, 0x0($29)
    /* 2CB808 003CB808 0800E003 */  jr         $31
    /* 2CB80C 003CB80C 2000BD27 */   addiu     $29, $29, 0x20
.size func_003cb7e0, 0x30
