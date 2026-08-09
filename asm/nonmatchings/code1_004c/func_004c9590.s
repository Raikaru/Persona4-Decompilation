.section .text
.set noat
.set noreorder
glabel func_004c9590
    /* 3C9590 004C9590 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C9594 004C9594 0000B0FF */  sd         $16, 0x0($29)
    /* 3C9598 004C9598 0800BFFF */  sd         $31, 0x8($29)
    /* 3C959C 004C959C 4627130C */  jal        func_004c9d18
    /* 3C95A0 004C95A0 2D808000 */   daddu     $16, $4, $0
    /* 3C95A4 004C95A4 7225130C */  jal        func_004c95c8
    /* 3C95A8 004C95A8 2D200002 */   daddu     $4, $16, $0
    /* 3C95AC 004C95AC 4C27130C */  jal        func_004c9d30
    /* 3C95B0 004C95B0 2D804000 */   daddu     $16, $2, $0
    /* 3C95B4 004C95B4 0800BFDF */  ld         $31, 0x8($29)
    /* 3C95B8 004C95B8 2D100002 */  daddu      $2, $16, $0
    /* 3C95BC 004C95BC 0000B0DF */  ld         $16, 0x0($29)
    /* 3C95C0 004C95C0 0800E003 */  jr         $31
    /* 3C95C4 004C95C4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c9590, 0x38
