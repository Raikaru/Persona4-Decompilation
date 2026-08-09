.section .text
.set noat
.set noreorder
glabel func_0042ab68
    /* 32AB68 0042AB68 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 32AB6C 0042AB6C 2D400000 */  daddu      $8, $0, $0
    /* 32AB70 0042AB70 1000BFFF */  sd         $31, 0x10($29)
    /* 32AB74 0042AB74 50AA100C */  jal        func_0042a940
    /* 32AB78 0042AB78 2D38A003 */   daddu     $7, $29, $0
    /* 32AB7C 0042AB7C 1000BFDF */  ld         $31, 0x10($29)
    /* 32AB80 0042AB80 0800E003 */  jr         $31
    /* 32AB84 0042AB84 2000BD27 */   addiu     $29, $29, 0x20
.size func_0042ab68, 0x20
