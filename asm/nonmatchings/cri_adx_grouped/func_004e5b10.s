.section .text
.set noat
.set noreorder
glabel func_004e5b10
    /* 3E5B10 004E5B10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E5B14 004E5B14 0000B0FF */  sd         $16, 0x0($29)
    /* 3E5B18 004E5B18 2D808000 */  daddu      $16, $4, $0
    /* 3E5B1C 004E5B1C 0800BFFF */  sd         $31, 0x8($29)
    /* 3E5B20 004E5B20 1C00028E */  lw         $2, 0x1C($16)
    /* 3E5B24 004E5B24 28004050 */  beql       $2, $0, .L004E5BC8
    /* 3E5B28 004E5B28 0000B0DF */   ld        $16, 0x0($29)
    /* 3E5B2C 004E5B2C 8EC1130C */  jal        func_004f0638
    /* 3E5B30 004E5B30 00000000 */   nop
    /* 3E5B34 004E5B34 6C8E130C */  jal        func_004e39b0
    /* 3E5B38 004E5B38 1C00048E */   lw        $4, 0x1C($16)
    /* 3E5B3C 004E5B3C 2D184000 */  daddu      $3, $2, $0
    /* 3E5B40 004E5B40 0A00622C */  sltiu      $2, $3, 0xA
    /* 3E5B44 004E5B44 1C004050 */  beql       $2, $0, .L004E5BB8
    /* 3E5B48 004E5B48 0000B0DF */   ld        $16, 0x0($29)
    /* 3E5B4C 004E5B4C 80100300 */  sll        $2, $3, 2
    /* 3E5B50 004E5B50 7600033C */  lui        $3, %hi(jtbl_0075B040)
    /* 3E5B54 004E5B54 21186200 */  addu       $3, $3, $2
    /* 3E5B58 004E5B58 40B0638C */  lw         $3, %lo(jtbl_0075B040)($3)
    /* 3E5B5C 004E5B5C 08006000 */  jr         $3
    /* 3E5B60 004E5B60 00000000 */   nop
    /* 3E5B64 004E5B64 00000000 */  nop
    /* 3E5B68 004E5B68 03000224 */  addiu      $2, $0, 0x3
    /* 3E5B6C 004E5B6C 1C00048E */  lw         $4, 0x1C($16)
    /* 3E5B70 004E5B70 0D000010 */  b          .L004E5BA8
    /* 3E5B74 004E5B74 020002A2 */   sb        $2, 0x2($16)
    /* 3E5B78 004E5B78 1000048E */  lw         $4, 0x10($16)
    /* 3E5B7C 004E5B7C 01000324 */  addiu      $3, $0, 0x1
    /* 3E5B80 004E5B80 0C00028E */  lw         $2, 0xC($16)
    /* 3E5B84 004E5B84 140004AE */  sw         $4, 0x14($16)
    /* 3E5B88 004E5B88 21104400 */  addu       $2, $2, $4
    /* 3E5B8C 004E5B8C 1C00048E */  lw         $4, 0x1C($16)
    /* 3E5B90 004E5B90 020003A2 */  sb         $3, 0x2($16)
    /* 3E5B94 004E5B94 04000010 */  b          .L004E5BA8
    /* 3E5B98 004E5B98 0C0002AE */   sw        $2, 0xC($16)
    /* 3E5B9C 004E5B9C 00000000 */  nop
    /* 3E5BA0 004E5BA0 020000A2 */  sb         $0, 0x2($16)
    /* 3E5BA4 004E5BA4 1C00048E */  lw         $4, 0x1C($16)
  .L004E5BA8:
    /* 3E5BA8 004E5BA8 DC8D130C */  jal        func_004e3770
    /* 3E5BAC 004E5BAC 00000000 */   nop
    /* 3E5BB0 004E5BB0 1C0000AE */  sw         $0, 0x1C($16)
    /* 3E5BB4 004E5BB4 0000B0DF */  ld         $16, 0x0($29)
  .L004E5BB8:
    /* 3E5BB8 004E5BB8 0800BFDF */  ld         $31, 0x8($29)
    /* 3E5BBC 004E5BBC ACC11308 */  j          func_004f06b0
    /* 3E5BC0 004E5BC0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3E5BC4 004E5BC4 00000000 */  nop
  .L004E5BC8:
    /* 3E5BC8 004E5BC8 0800BFDF */  ld         $31, 0x8($29)
    /* 3E5BCC 004E5BCC 0800E003 */  jr         $31
    /* 3E5BD0 004E5BD0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3E5BD4 004E5BD4 00000000 */  nop
.size func_004e5b10, 0xc8
