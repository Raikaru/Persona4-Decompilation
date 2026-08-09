.section .text
.set noat
.set noreorder
glabel func_004f0e80
    /* 3F0E80 004F0E80 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3F0E84 004F0E84 0000B0FF */  sd         $16, 0x0($29)
    /* 3F0E88 004F0E88 2D80A000 */  daddu      $16, $5, $0
    /* 3F0E8C 004F0E8C 0800B1FF */  sd         $17, 0x8($29)
    /* 3F0E90 004F0E90 1000BFFF */  sd         $31, 0x10($29)
    /* 3F0E94 004F0E94 82C1130C */  jal        func_004f0608
    /* 3F0E98 004F0E98 2D888000 */   daddu     $17, $4, $0
    /* 3F0E9C 004F0E9C 9200023C */  lui        $2, %hi(D_00925E70)
    /* 3F0EA0 004F0EA0 1000BFDF */  ld         $31, 0x10($29)
    /* 3F0EA4 004F0EA4 705E4224 */  addiu      $2, $2, %lo(D_00925E70)
    /* 3F0EA8 004F0EA8 040050AC */  sw         $16, 0x4($2)
    /* 3F0EAC 004F0EAC 000051AC */  sw         $17, 0x0($2)
    /* 3F0EB0 004F0EB0 0000B0DF */  ld         $16, 0x0($29)
    /* 3F0EB4 004F0EB4 0800B1DF */  ld         $17, 0x8($29)
    /* 3F0EB8 004F0EB8 88C11308 */  j          func_004f0620
    /* 3F0EBC 004F0EBC 2000BD27 */   addiu     $29, $29, 0x20
.size func_004f0e80, 0x40
