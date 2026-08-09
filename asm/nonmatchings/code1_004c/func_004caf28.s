.section .text
.set noat
.set noreorder
glabel func_004caf28
    /* 3CAF28 004CAF28 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3CAF2C 004CAF2C 0000B0FF */  sd         $16, 0x0($29)
    /* 3CAF30 004CAF30 2D808000 */  daddu      $16, $4, $0
    /* 3CAF34 004CAF34 0800B1FF */  sd         $17, 0x8($29)
    /* 3CAF38 004CAF38 1000BFFF */  sd         $31, 0x10($29)
    /* 3CAF3C 004CAF3C 3615130C */  jal        func_004c54d8
    /* 3CAF40 004CAF40 2D88A000 */   daddu     $17, $5, $0
    /* 3CAF44 004CAF44 2D200002 */  daddu      $4, $16, $0
    /* 3CAF48 004CAF48 DA2B130C */  jal        func_004caf68
    /* 3CAF4C 004CAF4C 2D282002 */   daddu     $5, $17, $0
    /* 3CAF50 004CAF50 0000B0DF */  ld         $16, 0x0($29)
    /* 3CAF54 004CAF54 0800B1DF */  ld         $17, 0x8($29)
    /* 3CAF58 004CAF58 1000BFDF */  ld         $31, 0x10($29)
    /* 3CAF5C 004CAF5C 38151308 */  j          func_004c54e0
    /* 3CAF60 004CAF60 2000BD27 */   addiu     $29, $29, 0x20
    /* 3CAF64 004CAF64 00000000 */  nop
.size func_004caf28, 0x40
