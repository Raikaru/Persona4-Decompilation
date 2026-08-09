.section .text
.set noat
.set noreorder
glabel func_004d4b80
    /* 3D4B80 004D4B80 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D4B84 004D4B84 06008014 */  bnez       $4, .L004D4BA0
    /* 3D4B88 004D4B88 0000BFFF */   sd        $31, 0x0($29)
    /* 3D4B8C 004D4B8C 7600043C */  lui        $4, %hi(D_00758CA8)
    /* 3D4B90 004D4B90 A61A130C */  jal        func_004c6a98
    /* 3D4B94 004D4B94 A88C8424 */   addiu     $4, $4, %lo(D_00758CA8)
    /* 3D4B98 004D4B98 09000010 */  b          .L004D4BC0
    /* 3D4B9C 004D4B9C FFFF0224 */   addiu     $2, $0, -0x1
  .L004D4BA0:
    /* 3D4BA0 004D4BA0 01008280 */  lb         $2, 0x1($4)
    /* 3D4BA4 004D4BA4 02004228 */  slti       $2, $2, 0x2
    /* 3D4BA8 004D4BA8 05004054 */  bnel       $2, $0, .L004D4BC0
    /* 3D4BAC 004D4BAC 2D100000 */   daddu     $2, $0, $0
    /* 3D4BB0 004D4BB0 0400848C */  lw         $4, 0x4($4)
    /* 3D4BB4 004D4BB4 0000BFDF */  ld         $31, 0x0($29)
    /* 3D4BB8 004D4BB8 823B1308 */  j          func_004cee08
    /* 3D4BBC 004D4BBC 1000BD27 */   addiu     $29, $29, 0x10
  .L004D4BC0:
    /* 3D4BC0 004D4BC0 0000BFDF */  ld         $31, 0x0($29)
    /* 3D4BC4 004D4BC4 0800E003 */  jr         $31
    /* 3D4BC8 004D4BC8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D4BCC 004D4BCC 00000000 */  nop
.size func_004d4b80, 0x50
