.section .text
.set noat
.set noreorder
glabel func_004f0b88
    /* 3F0B88 004F0B88 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3F0B8C 004F0B8C 0000B0FF */  sd         $16, 0x0($29)
    /* 3F0B90 004F0B90 2D808000 */  daddu      $16, $4, $0
    /* 3F0B94 004F0B94 0800B1FF */  sd         $17, 0x8($29)
    /* 3F0B98 004F0B98 1000BFFF */  sd         $31, 0x10($29)
    /* 3F0B9C 004F0B9C 82C1130C */  jal        func_004f0608
    /* 3F0BA0 004F0BA0 2D88A000 */   daddu     $17, $5, $0
    /* 3F0BA4 004F0BA4 2D200002 */  daddu      $4, $16, $0
    /* 3F0BA8 004F0BA8 F2C2130C */  jal        func_004f0bc8
    /* 3F0BAC 004F0BAC 2D282002 */   daddu     $5, $17, $0
    /* 3F0BB0 004F0BB0 0000B0DF */  ld         $16, 0x0($29)
    /* 3F0BB4 004F0BB4 0800B1DF */  ld         $17, 0x8($29)
    /* 3F0BB8 004F0BB8 1000BFDF */  ld         $31, 0x10($29)
    /* 3F0BBC 004F0BBC 88C11308 */  j          func_004f0620
    /* 3F0BC0 004F0BC0 2000BD27 */   addiu     $29, $29, 0x20
    /* 3F0BC4 004F0BC4 00000000 */  nop
.size func_004f0b88, 0x40
