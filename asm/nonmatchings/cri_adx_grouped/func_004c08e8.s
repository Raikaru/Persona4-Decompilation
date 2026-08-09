.section .text
.set noat
.set noreorder
glabel func_004c08e8
    /* 3C08E8 004C08E8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C08EC 004C08EC 0000B0FF */  sd         $16, 0x0($29)
    /* 3C08F0 004C08F0 2D808000 */  daddu      $16, $4, $0
    /* 3C08F4 004C08F4 04000010 */  b          .L004C0908
    /* 3C08F8 004C08F8 0800BFFF */   sd        $31, 0x8($29)
    /* 3C08FC 004C08FC 00000000 */  nop
  .L004C0900:
    /* 3C0900 004C0900 FC01130C */  jal        func_004c07f0
    /* 3C0904 004C0904 00000000 */   nop
  .L004C0908:
    /* 3C0908 004C0908 9003130C */  jal        func_004c0e40
    /* 3C090C 004C090C 2D200002 */   daddu     $4, $16, $0
    /* 3C0910 004C0910 FBFF4014 */  bnez       $2, .L004C0900
    /* 3C0914 004C0914 2D200002 */   daddu     $4, $16, $0
    /* 3C0918 004C0918 0000B0DF */  ld         $16, 0x0($29)
    /* 3C091C 004C091C 0800BFDF */  ld         $31, 0x8($29)
    /* 3C0920 004C0920 0800E003 */  jr         $31
    /* 3C0924 004C0924 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c08e8, 0x40
