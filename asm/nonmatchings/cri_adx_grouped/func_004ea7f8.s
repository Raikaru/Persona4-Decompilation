.section .text
.set noat
.set noreorder
glabel func_004ea7f8
    /* 3EA7F8 004EA7F8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EA7FC 004EA7FC 7400043C */  lui        $4, %hi(D_00739758)
    /* 3EA800 004EA800 0000BFFF */  sd         $31, 0x0($29)
    /* 3EA804 004EA804 58978424 */  addiu      $4, $4, %lo(D_00739758)
    /* 3EA808 004EA808 68010624 */  addiu      $6, $0, 0x168
    /* 3EA80C 004EA80C DEFD100C */  jal        func_0043f778
    /* 3EA810 004EA810 2D288000 */   daddu     $5, $4, $0
    /* 3EA814 004EA814 7400033C */  lui        $3, %hi(D_00739788)
    /* 3EA818 004EA818 88976324 */  addiu      $3, $3, %lo(D_00739788)
    /* 3EA81C 004EA81C 0000BFDF */  ld         $31, 0x0($29)
    /* 3EA820 004EA820 0000628C */  lw         $2, 0x0($3)
    /* 3EA824 004EA824 01004224 */  addiu      $2, $2, 0x1
    /* 3EA828 004EA828 000062AC */  sw         $2, 0x0($3)
    /* 3EA82C 004EA82C 0800E003 */  jr         $31
    /* 3EA830 004EA830 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EA834 004EA834 00000000 */  nop
.size func_004ea7f8, 0x40
