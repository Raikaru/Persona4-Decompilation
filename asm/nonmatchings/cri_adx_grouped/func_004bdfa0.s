.section .text
.set noat
.set noreorder
glabel func_004bdfa0
    /* 3BDFA0 004BDFA0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BDFA4 004BDFA4 0000BFFF */  sd         $31, 0x0($29)
    /* 3BDFA8 004BDFA8 FE50130C */  jal        func_004d43f8
    /* 3BDFAC 004BDFAC 0400848C */   lw        $4, 0x4($4)
    /* 3BDFB0 004BDFB0 2D184000 */  daddu      $3, $2, $0
    /* 3BDFB4 004BDFB4 0700622C */  sltiu      $2, $3, 0x7
    /* 3BDFB8 004BDFB8 10004050 */  beql       $2, $0, .L004BDFFC
    /* 3BDFBC 004BDFBC 04000324 */   addiu     $3, $0, 0x4
    /* 3BDFC0 004BDFC0 80100300 */  sll        $2, $3, 2
    /* 3BDFC4 004BDFC4 7500033C */  lui        $3, %hi(jtbl_00756A30)
    /* 3BDFC8 004BDFC8 21186200 */  addu       $3, $3, $2
    /* 3BDFCC 004BDFCC 306A638C */  lw         $3, %lo(jtbl_00756A30)($3)
    /* 3BDFD0 004BDFD0 08006000 */  jr         $3
    /* 3BDFD4 004BDFD4 00000000 */   nop
    /* 3BDFD8 004BDFD8 08000010 */  b          .L004BDFFC
    /* 3BDFDC 004BDFDC 2D180000 */   daddu     $3, $0, $0
    /* 3BDFE0 004BDFE0 06000010 */  b          .L004BDFFC
    /* 3BDFE4 004BDFE4 01000324 */   addiu     $3, $0, 0x1
    /* 3BDFE8 004BDFE8 04000010 */  b          .L004BDFFC
    /* 3BDFEC 004BDFEC 02000324 */   addiu     $3, $0, 0x2
    /* 3BDFF0 004BDFF0 02000010 */  b          .L004BDFFC
    /* 3BDFF4 004BDFF4 03000324 */   addiu     $3, $0, 0x3
    /* 3BDFF8 004BDFF8 04000324 */  addiu      $3, $0, 0x4
  .L004BDFFC:
    /* 3BDFFC 004BDFFC 0000BFDF */  ld         $31, 0x0($29)
    /* 3BE000 004BE000 2D106000 */  daddu      $2, $3, $0
    /* 3BE004 004BE004 0800E003 */  jr         $31
    /* 3BE008 004BE008 1000BD27 */   addiu     $29, $29, 0x10
    /* 3BE00C 004BE00C 00000000 */  nop
.size func_004bdfa0, 0x70
