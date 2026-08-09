.section .text
.set noat
.set noreorder
glabel func_004ed858
    /* 3ED858 004ED858 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3ED85C 004ED85C 0000B0FF */  sd         $16, 0x0($29)
    /* 3ED860 004ED860 2D808000 */  daddu      $16, $4, $0
    /* 3ED864 004ED864 0800B1FF */  sd         $17, 0x8($29)
    /* 3ED868 004ED868 2D88A000 */  daddu      $17, $5, $0
    /* 3ED86C 004ED86C 1000B2FF */  sd         $18, 0x10($29)
    /* 3ED870 004ED870 1800BFFF */  sd         $31, 0x18($29)
    /* 3ED874 004ED874 14B5130C */  jal        func_004ed450
    /* 3ED878 004ED878 2D90C000 */   daddu     $18, $6, $0
    /* 3ED87C 004ED87C 2D200002 */  daddu      $4, $16, $0
    /* 3ED880 004ED880 2D282002 */  daddu      $5, $17, $0
    /* 3ED884 004ED884 2AB6130C */  jal        func_004ed8a8
    /* 3ED888 004ED888 2D304002 */   daddu     $6, $18, $0
    /* 3ED88C 004ED88C 0000B0DF */  ld         $16, 0x0($29)
    /* 3ED890 004ED890 0800B1DF */  ld         $17, 0x8($29)
    /* 3ED894 004ED894 1000B2DF */  ld         $18, 0x10($29)
    /* 3ED898 004ED898 1800BFDF */  ld         $31, 0x18($29)
    /* 3ED89C 004ED89C 1AB51308 */  j          func_004ed468
    /* 3ED8A0 004ED8A0 2000BD27 */   addiu     $29, $29, 0x20
    /* 3ED8A4 004ED8A4 00000000 */  nop
.size func_004ed858, 0x50
