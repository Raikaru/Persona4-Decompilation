.section .text
.set noat
.set noreorder
glabel func_004caeb8
    /* 3CAEB8 004CAEB8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3CAEBC 004CAEBC 0000B0FF */  sd         $16, 0x0($29)
    /* 3CAEC0 004CAEC0 2D808000 */  daddu      $16, $4, $0
    /* 3CAEC4 004CAEC4 0800B1FF */  sd         $17, 0x8($29)
    /* 3CAEC8 004CAEC8 1000BFFF */  sd         $31, 0x10($29)
    /* 3CAECC 004CAECC 3615130C */  jal        func_004c54d8
    /* 3CAED0 004CAED0 2D88A000 */   daddu     $17, $5, $0
    /* 3CAED4 004CAED4 2D200002 */  daddu      $4, $16, $0
    /* 3CAED8 004CAED8 BE2B130C */  jal        func_004caef8
    /* 3CAEDC 004CAEDC 2D282002 */   daddu     $5, $17, $0
    /* 3CAEE0 004CAEE0 0000B0DF */  ld         $16, 0x0($29)
    /* 3CAEE4 004CAEE4 0800B1DF */  ld         $17, 0x8($29)
    /* 3CAEE8 004CAEE8 1000BFDF */  ld         $31, 0x10($29)
    /* 3CAEEC 004CAEEC 38151308 */  j          func_004c54e0
    /* 3CAEF0 004CAEF0 2000BD27 */   addiu     $29, $29, 0x20
    /* 3CAEF4 004CAEF4 00000000 */  nop
.size func_004caeb8, 0x40
