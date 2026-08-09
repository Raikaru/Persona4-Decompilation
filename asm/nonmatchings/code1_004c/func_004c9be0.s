.section .text
.set noat
.set noreorder
glabel func_004c9be0
    /* 3C9BE0 004C9BE0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3C9BE4 004C9BE4 0000B0FF */  sd         $16, 0x0($29)
    /* 3C9BE8 004C9BE8 2D808000 */  daddu      $16, $4, $0
    /* 3C9BEC 004C9BEC 0800B1FF */  sd         $17, 0x8($29)
    /* 3C9BF0 004C9BF0 1000BFFF */  sd         $31, 0x10($29)
    /* 3C9BF4 004C9BF4 4627130C */  jal        func_004c9d18
    /* 3C9BF8 004C9BF8 2D88A000 */   daddu     $17, $5, $0
    /* 3C9BFC 004C9BFC 2D200002 */  daddu      $4, $16, $0
    /* 3C9C00 004C9C00 0827130C */  jal        func_004c9c20
    /* 3C9C04 004C9C04 2D282002 */   daddu     $5, $17, $0
    /* 3C9C08 004C9C08 0000B0DF */  ld         $16, 0x0($29)
    /* 3C9C0C 004C9C0C 0800B1DF */  ld         $17, 0x8($29)
    /* 3C9C10 004C9C10 1000BFDF */  ld         $31, 0x10($29)
    /* 3C9C14 004C9C14 4C271308 */  j          func_004c9d30
    /* 3C9C18 004C9C18 2000BD27 */   addiu     $29, $29, 0x20
    /* 3C9C1C 004C9C1C 00000000 */  nop
.size func_004c9be0, 0x40
