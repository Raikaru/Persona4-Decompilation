.section .text
.set noat
.set noreorder
glabel func_004e4990
    /* 3E4990 004E4990 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E4994 004E4994 0000B0FF */  sd         $16, 0x0($29)
    /* 3E4998 004E4998 0800BFFF */  sd         $31, 0x8($29)
    /* 3E499C 004E499C C091130C */  jal        func_004e4700
    /* 3E49A0 004E49A0 2D808000 */   daddu     $16, $4, $0
    /* 3E49A4 004E49A4 E09B100C */  jal        func_00426f80
    /* 3E49A8 004E49A8 2D200002 */   daddu     $4, $16, $0
    /* 3E49AC 004E49AC 7600043C */  lui        $4, %hi(D_0075AD80)
    /* 3E49B0 004E49B0 2D804000 */  daddu      $16, $2, $0
    /* 3E49B4 004E49B4 80AD8424 */  addiu      $4, $4, %lo(D_0075AD80)
    /* 3E49B8 004E49B8 03000106 */  bgez       $16, .L004E49C8
    /* 3E49BC 004E49BC 2D280002 */   daddu     $5, $16, $0
    /* 3E49C0 004E49C0 3291100C */  jal        func_004244c8
    /* 3E49C4 004E49C4 00000000 */   nop
  .L004E49C8:
    /* 3E49C8 004E49C8 CE91130C */  jal        func_004e4738
    /* 3E49CC 004E49CC 00000000 */   nop
    /* 3E49D0 004E49D0 2D100002 */  daddu      $2, $16, $0
    /* 3E49D4 004E49D4 0800BFDF */  ld         $31, 0x8($29)
    /* 3E49D8 004E49D8 0000B0DF */  ld         $16, 0x0($29)
    /* 3E49DC 004E49DC 0800E003 */  jr         $31
    /* 3E49E0 004E49E0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3E49E4 004E49E4 00000000 */  nop
.size func_004e4990, 0x58
