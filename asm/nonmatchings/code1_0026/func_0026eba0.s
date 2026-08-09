.section .text
.set noat
.set noreorder
glabel func_0026eba0
    /* 16EBA0 0026EBA0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 16EBA4 0026EBA4 0000BFFF */  sd         $31, 0x0($29)
    /* 16EBA8 0026EBA8 01000424 */  addiu      $4, $0, 0x1
    /* 16EBAC 0026EBAC 2D288000 */  daddu      $5, $4, $0
    /* 16EBB0 0026EBB0 98D1090C */  jal        func_00274660
    /* 16EBB4 0026EBB4 00000000 */   nop
    /* 16EBB8 0026EBB8 02000424 */  addiu      $4, $0, 0x2
    /* 16EBBC 0026EBBC 01000524 */  addiu      $5, $0, 0x1
    /* 16EBC0 0026EBC0 98D1090C */  jal        func_00274660
    /* 16EBC4 0026EBC4 00000000 */   nop
    /* 16EBC8 0026EBC8 01000224 */  addiu      $2, $0, 0x1
    /* 16EBCC 0026EBCC 0000BFDF */  ld         $31, 0x0($29)
    /* 16EBD0 0026EBD0 1000BD27 */  addiu      $29, $29, 0x10
    /* 16EBD4 0026EBD4 0800E003 */  jr         $31
    /* 16EBD8 0026EBD8 00000000 */   nop
    /* 16EBDC 0026EBDC 00000000 */  nop
.size func_0026eba0, 0x40
