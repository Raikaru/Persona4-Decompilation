.section .text
.set noat
.set noreorder
glabel func_004c9c90
    /* 3C9C90 004C9C90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C9C94 004C9C94 2D100000 */  daddu      $2, $0, $0
    /* 3C9C98 004C9C98 07008010 */  beqz       $4, .L004C9CB8
    /* 3C9C9C 004C9C9C 0000BFFF */   sd        $31, 0x0($29)
    /* 3C9CA0 004C9CA0 0400838C */  lw         $3, 0x4($4)
    /* 3C9CA4 004C9CA4 04006010 */  beqz       $3, .L004C9CB8
    /* 3C9CA8 004C9CA8 2D206000 */   daddu     $4, $3, $0
    /* 3C9CAC 004C9CAC 0000BFDF */  ld         $31, 0x0($29)
    /* 3C9CB0 004C9CB0 7A4C1308 */  j          func_004d31e8
    /* 3C9CB4 004C9CB4 1000BD27 */   addiu     $29, $29, 0x10
  .L004C9CB8:
    /* 3C9CB8 004C9CB8 0000BFDF */  ld         $31, 0x0($29)
    /* 3C9CBC 004C9CBC 0800E003 */  jr         $31
    /* 3C9CC0 004C9CC0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C9CC4 004C9CC4 00000000 */  nop
.size func_004c9c90, 0x38
