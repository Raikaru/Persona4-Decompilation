.section .text
.set noat
.set noreorder
glabel func_003cb8d0
    /* 2CB8D0 003CB8D0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2CB8D4 003CB8D4 1000BFFF */  sd         $31, 0x10($29)
    /* 2CB8D8 003CB8D8 0000B07F */  sq         $16, 0x0($29)
    /* 2CB8DC 003CB8DC 08270F0C */  jal        func_003c9c20
    /* 2CB8E0 003CB8E0 2D808000 */   daddu     $16, $4, $0
    /* 2CB8E4 003CB8E4 7800048E */  lw         $4, 0x78($16)
    /* 2CB8E8 003CB8E8 F4170F0C */  jal        func_003c5fd0
    /* 2CB8EC 003CB8EC 2D284000 */   daddu     $5, $2, $0
    /* 2CB8F0 003CB8F0 1000BFDF */  ld         $31, 0x10($29)
    /* 2CB8F4 003CB8F4 0000B07B */  lq         $16, 0x0($29)
    /* 2CB8F8 003CB8F8 0800E003 */  jr         $31
    /* 2CB8FC 003CB8FC 2000BD27 */   addiu     $29, $29, 0x20
.size func_003cb8d0, 0x30
