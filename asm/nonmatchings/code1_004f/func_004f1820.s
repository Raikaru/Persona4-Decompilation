.section .text
.set noat
.set noreorder
glabel func_004f1820
    /* 3F1820 004F1820 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F1824 004F1824 0000B0FF */  sd         $16, 0x0($29)
    /* 3F1828 004F1828 0800BFFF */  sd         $31, 0x8($29)
    /* 3F182C 004F182C 28D5130C */  jal        func_004f54a0
    /* 3F1830 004F1830 2D808000 */   daddu     $16, $4, $0
    /* 3F1834 004F1834 0800BFDF */  ld         $31, 0x8($29)
    /* 3F1838 004F1838 2D200002 */  daddu      $4, $16, $0
    /* 3F183C 004F183C 0000B0DF */  ld         $16, 0x0($29)
    /* 3F1840 004F1840 2D280000 */  daddu      $5, $0, $0
    /* 3F1844 004F1844 2D300000 */  daddu      $6, $0, $0
    /* 3F1848 004F1848 BAC91308 */  j          func_004f26e8
    /* 3F184C 004F184C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f1820, 0x30
