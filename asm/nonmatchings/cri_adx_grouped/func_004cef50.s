.section .text
.set noat
.set noreorder
glabel func_004cef50
    /* 3CEF50 004CEF50 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3CEF54 004CEF54 0000B0FF */  sd         $16, 0x0($29)
    /* 3CEF58 004CEF58 2D808000 */  daddu      $16, $4, $0
    /* 3CEF5C 004CEF5C 0800B1FF */  sd         $17, 0x8($29)
    /* 3CEF60 004CEF60 2D88A000 */  daddu      $17, $5, $0
    /* 3CEF64 004CEF64 1000BFFF */  sd         $31, 0x10($29)
    /* 3CEF68 004CEF68 320F130C */  jal        func_004c3cc8
    /* 3CEF6C 004CEF6C 0400048E */   lw        $4, 0x4($16)
    /* 3CEF70 004CEF70 0B004018 */  blez       $2, .L004CEFA0
    /* 3CEF74 004CEF74 80FF0224 */   addiu     $2, $0, -0x80
    /* 3CEF78 004CEF78 01000292 */  lbu        $2, 0x1($16)
    /* 3CEF7C 004CEF7C FEFF4224 */  addiu      $2, $2, -0x2
    /* 3CEF80 004CEF80 0200422C */  sltiu      $2, $2, 0x2
    /* 3CEF84 004CEF84 06004050 */  beql       $2, $0, .L004CEFA0
    /* 3CEF88 004CEF88 80FF0224 */   addiu     $2, $0, -0x80
    /* 3CEF8C 004CEF8C 0400048E */  lw         $4, 0x4($16)
    /* 3CEF90 004CEF90 360F130C */  jal        func_004c3cd8
    /* 3CEF94 004CEF94 2D282002 */   daddu     $5, $17, $0
    /* 3CEF98 004CEF98 02000010 */  b          .L004CEFA4
    /* 3CEF9C 004CEF9C 0000B0DF */   ld        $16, 0x0($29)
  .L004CEFA0:
    /* 3CEFA0 004CEFA0 0000B0DF */  ld         $16, 0x0($29)
  .L004CEFA4:
    /* 3CEFA4 004CEFA4 0800B1DF */  ld         $17, 0x8($29)
    /* 3CEFA8 004CEFA8 1000BFDF */  ld         $31, 0x10($29)
    /* 3CEFAC 004CEFAC 0800E003 */  jr         $31
    /* 3CEFB0 004CEFB0 2000BD27 */   addiu     $29, $29, 0x20
    /* 3CEFB4 004CEFB4 00000000 */  nop
.size func_004cef50, 0x68
