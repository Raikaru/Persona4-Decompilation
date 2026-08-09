.section .text
.set noat
.set noreorder
glabel func_00509fb0
    /* 409FB0 00509FB0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 409FB4 00509FB4 0000B0FF */  sd         $16, 0x0($29)
    /* 409FB8 00509FB8 2D80A000 */  daddu      $16, $5, $0
    /* 409FBC 00509FBC 0800B1FF */  sd         $17, 0x8($29)
    /* 409FC0 00509FC0 1000BFFF */  sd         $31, 0x10($29)
    /* 409FC4 00509FC4 9833140C */  jal        func_0050ce60
    /* 409FC8 00509FC8 2D88C000 */   daddu     $17, $6, $0
    /* 409FCC 00509FCC 1000BFDF */  ld         $31, 0x10($29)
    /* 409FD0 00509FD0 2D280002 */  daddu      $5, $16, $0
    /* 409FD4 00509FD4 2D302002 */  daddu      $6, $17, $0
    /* 409FD8 00509FD8 0800B1DF */  ld         $17, 0x8($29)
    /* 409FDC 00509FDC 0000B0DF */  ld         $16, 0x0($29)
    /* 409FE0 00509FE0 2D204000 */  daddu      $4, $2, $0
    /* 409FE4 00509FE4 CA601408 */  j          func_00518328
    /* 409FE8 00509FE8 2000BD27 */   addiu     $29, $29, 0x20
    /* 409FEC 00509FEC 00000000 */  nop
.size func_00509fb0, 0x40
