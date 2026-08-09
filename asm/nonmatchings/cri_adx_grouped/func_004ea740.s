.section .text
.set noat
.set noreorder
glabel func_004ea740
    /* 3EA740 004EA740 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3EA744 004EA744 0000B0FF */  sd         $16, 0x0($29)
    /* 3EA748 004EA748 2D808000 */  daddu      $16, $4, $0
    /* 3EA74C 004EA74C 0800B1FF */  sd         $17, 0x8($29)
    /* 3EA750 004EA750 1000BFFF */  sd         $31, 0x10($29)
    /* 3EA754 004EA754 C4A9130C */  jal        func_004ea710
    /* 3EA758 004EA758 2D88A000 */   daddu     $17, $5, $0
    /* 3EA75C 004EA75C 2D200002 */  daddu      $4, $16, $0
    /* 3EA760 004EA760 E0A9130C */  jal        func_004ea780
    /* 3EA764 004EA764 2D282002 */   daddu     $5, $17, $0
    /* 3EA768 004EA768 0000B0DF */  ld         $16, 0x0($29)
    /* 3EA76C 004EA76C 0800B1DF */  ld         $17, 0x8($29)
    /* 3EA770 004EA770 1000BFDF */  ld         $31, 0x10($29)
    /* 3EA774 004EA774 CAA91308 */  j          func_004ea728
    /* 3EA778 004EA778 2000BD27 */   addiu     $29, $29, 0x20
    /* 3EA77C 004EA77C 00000000 */  nop
.size func_004ea740, 0x40
