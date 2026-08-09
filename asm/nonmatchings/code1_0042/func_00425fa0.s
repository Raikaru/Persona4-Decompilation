.section .text
.set noat
.set noreorder
glabel func_00425fa0
    /* 325FA0 00425FA0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 325FA4 00425FA4 0000B0FF */  sd         $16, 0x0($29)
    /* 325FA8 00425FA8 1000BFFF */  sd         $31, 0x10($29)
    /* 325FAC 00425FAC 04000010 */  b          .L00425FC0
    /* 325FB0 00425FB0 2D808000 */   daddu     $16, $4, $0
    /* 325FB4 00425FB4 00000000 */  nop
  .L00425FB8:
    /* 325FB8 00425FB8 7697100C */  jal        func_00425dd8
    /* 325FBC 00425FBC 00000000 */   nop
  .L00425FC0:
    /* 325FC0 00425FC0 6097100C */  jal        func_00425d80
    /* 325FC4 00425FC4 2D200002 */   daddu     $4, $16, $0
    /* 325FC8 00425FC8 FBFF4014 */  bnez       $2, .L00425FB8
    /* 325FCC 00425FCC 2D204000 */   daddu     $4, $2, $0
    /* 325FD0 00425FD0 C085100C */  jal        func_00421700
    /* 325FD4 00425FD4 00000000 */   nop
    /* 325FD8 00425FD8 F9FF0010 */  b          .L00425FC0
    /* 325FDC 00425FDC 00000000 */   nop
.size func_00425fa0, 0x40
