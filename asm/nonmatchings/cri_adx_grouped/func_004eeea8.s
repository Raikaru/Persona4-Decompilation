.section .text
.set noat
.set noreorder
glabel func_004eeea8
    /* 3EEEA8 004EEEA8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3EEEAC 004EEEAC 0000B0FF */  sd         $16, 0x0($29)
    /* 3EEEB0 004EEEB0 2D808000 */  daddu      $16, $4, $0
    /* 3EEEB4 004EEEB4 0800B1FF */  sd         $17, 0x8($29)
    /* 3EEEB8 004EEEB8 2D88A000 */  daddu      $17, $5, $0
    /* 3EEEBC 004EEEBC 1000B2FF */  sd         $18, 0x10($29)
    /* 3EEEC0 004EEEC0 1800BFFF */  sd         $31, 0x18($29)
    /* 3EEEC4 004EEEC4 14B5130C */  jal        func_004ed450
    /* 3EEEC8 004EEEC8 2D90C000 */   daddu     $18, $6, $0
    /* 3EEECC 004EEECC 2D200002 */  daddu      $4, $16, $0
    /* 3EEED0 004EEED0 2D282002 */  daddu      $5, $17, $0
    /* 3EEED4 004EEED4 BEBB130C */  jal        func_004eeef8
    /* 3EEED8 004EEED8 2D304002 */   daddu     $6, $18, $0
    /* 3EEEDC 004EEEDC 0000B0DF */  ld         $16, 0x0($29)
    /* 3EEEE0 004EEEE0 0800B1DF */  ld         $17, 0x8($29)
    /* 3EEEE4 004EEEE4 1000B2DF */  ld         $18, 0x10($29)
    /* 3EEEE8 004EEEE8 1800BFDF */  ld         $31, 0x18($29)
    /* 3EEEEC 004EEEEC 1AB51308 */  j          func_004ed468
    /* 3EEEF0 004EEEF0 2000BD27 */   addiu     $29, $29, 0x20
    /* 3EEEF4 004EEEF4 00000000 */  nop
.size func_004eeea8, 0x50
