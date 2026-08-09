.section .text
.set noat
.set noreorder
glabel func_004f34b0
    /* 3F34B0 004F34B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F34B4 004F34B4 0000B0FF */  sd         $16, 0x0($29)
    /* 3F34B8 004F34B8 0800BFFF */  sd         $31, 0x8($29)
    /* 3F34BC 004F34BC 28CD130C */  jal        func_004f34a0
    /* 3F34C0 004F34C0 2D808000 */   daddu     $16, $4, $0
    /* 3F34C4 004F34C4 9200033C */  lui        $3, %hi(D_00925EA0)
    /* 3F34C8 004F34C8 A05E6324 */  addiu      $3, $3, %lo(D_00925EA0)
    /* 3F34CC 004F34CC 28D5130C */  jal        func_004f54a0
    /* 3F34D0 004F34D0 000062AC */   sw        $2, 0x0($3)
    /* 3F34D4 004F34D4 2D200002 */  daddu      $4, $16, $0
    /* 3F34D8 004F34D8 0800BFDF */  ld         $31, 0x8($29)
    /* 3F34DC 004F34DC 0000B0DF */  ld         $16, 0x0($29)
    /* 3F34E0 004F34E0 E0C71308 */  j          func_004f1f80
    /* 3F34E4 004F34E4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f34b0, 0x38
