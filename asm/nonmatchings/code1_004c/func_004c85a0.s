.section .text
.set noat
.set noreorder
glabel func_004c85a0
    /* 3C85A0 004C85A0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3C85A4 004C85A4 0000B0FF */  sd         $16, 0x0($29)
    /* 3C85A8 004C85A8 2D808000 */  daddu      $16, $4, $0
    /* 3C85AC 004C85AC 0800B1FF */  sd         $17, 0x8($29)
    /* 3C85B0 004C85B0 1000BFFF */  sd         $31, 0x10($29)
    /* 3C85B4 004C85B4 4627130C */  jal        func_004c9d18
    /* 3C85B8 004C85B8 2D88A000 */   daddu     $17, $5, $0
    /* 3C85BC 004C85BC 2D200002 */  daddu      $4, $16, $0
    /* 3C85C0 004C85C0 7A21130C */  jal        func_004c85e8
    /* 3C85C4 004C85C4 2D282002 */   daddu     $5, $17, $0
    /* 3C85C8 004C85C8 4C27130C */  jal        func_004c9d30
    /* 3C85CC 004C85CC 2D804000 */   daddu     $16, $2, $0
    /* 3C85D0 004C85D0 0800B1DF */  ld         $17, 0x8($29)
    /* 3C85D4 004C85D4 2D100002 */  daddu      $2, $16, $0
    /* 3C85D8 004C85D8 1000BFDF */  ld         $31, 0x10($29)
    /* 3C85DC 004C85DC 0000B0DF */  ld         $16, 0x0($29)
    /* 3C85E0 004C85E0 0800E003 */  jr         $31
    /* 3C85E4 004C85E4 2000BD27 */   addiu     $29, $29, 0x20
.size func_004c85a0, 0x48
