.section .text
.set noat
.set noreorder
glabel func_004ccc98
    /* 3CCC98 004CCC98 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CCC9C 004CCC9C 0000BFFF */  sd         $31, 0x0($29)
    /* 3CCCA0 004CCCA0 D4C4130C */  jal        func_004f1350
    /* 3CCCA4 004CCCA4 00000000 */   nop
    /* 3CCCA8 004CCCA8 DA32130C */  jal        func_004ccb68
    /* 3CCCAC 004CCCAC 00000000 */   nop
    /* 3CCCB0 004CCCB0 5C34130C */  jal        func_004cd170
    /* 3CCCB4 004CCCB4 00000000 */   nop
    /* 3CCCB8 004CCCB8 1C33130C */  jal        func_004ccc70
    /* 3CCCBC 004CCCBC 00000000 */   nop
    /* 3CCCC0 004CCCC0 0000BFDF */  ld         $31, 0x0($29)
    /* 3CCCC4 004CCCC4 E0C41308 */  j          func_004f1380
    /* 3CCCC8 004CCCC8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CCCCC 004CCCCC 00000000 */  nop
.size func_004ccc98, 0x38
