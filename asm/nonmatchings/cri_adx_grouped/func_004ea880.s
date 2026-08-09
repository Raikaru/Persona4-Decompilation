.section .text
.set noat
.set noreorder
glabel func_004ea880
    /* 3EA880 004EA880 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3EA884 004EA884 0000B0FF */  sd         $16, 0x0($29)
    /* 3EA888 004EA888 2D808000 */  daddu      $16, $4, $0
    /* 3EA88C 004EA88C 0800B1FF */  sd         $17, 0x8($29)
    /* 3EA890 004EA890 1000BFFF */  sd         $31, 0x10($29)
    /* 3EA894 004EA894 C4A9130C */  jal        func_004ea710
    /* 3EA898 004EA898 2D88A000 */   daddu     $17, $5, $0
    /* 3EA89C 004EA89C 2D200002 */  daddu      $4, $16, $0
    /* 3EA8A0 004EA8A0 32AA130C */  jal        func_004ea8c8
    /* 3EA8A4 004EA8A4 2D282002 */   daddu     $5, $17, $0
    /* 3EA8A8 004EA8A8 CAA9130C */  jal        func_004ea728
    /* 3EA8AC 004EA8AC 2D804000 */   daddu     $16, $2, $0
    /* 3EA8B0 004EA8B0 0800B1DF */  ld         $17, 0x8($29)
    /* 3EA8B4 004EA8B4 2D100002 */  daddu      $2, $16, $0
    /* 3EA8B8 004EA8B8 1000BFDF */  ld         $31, 0x10($29)
    /* 3EA8BC 004EA8BC 0000B0DF */  ld         $16, 0x0($29)
    /* 3EA8C0 004EA8C0 0800E003 */  jr         $31
    /* 3EA8C4 004EA8C4 2000BD27 */   addiu     $29, $29, 0x20
.size func_004ea880, 0x48
