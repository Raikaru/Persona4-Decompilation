.section .text
.set noat
.set noreorder
glabel func_004f5b50
    /* 3F5B50 004F5B50 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F5B54 004F5B54 0000B0FF */  sd         $16, 0x0($29)
    /* 3F5B58 004F5B58 2D80A000 */  daddu      $16, $5, $0
    /* 3F5B5C 004F5B5C 0800BFFF */  sd         $31, 0x8($29)
    /* 3F5B60 004F5B60 A0CB130C */  jal        func_004f2e80
    /* 3F5B64 004F5B64 01000524 */   addiu     $5, $0, 0x1
    /* 3F5B68 004F5B68 2D280002 */  daddu      $5, $16, $0
    /* 3F5B6C 004F5B6C 2C004424 */  addiu      $4, $2, 0x2C
    /* 3F5B70 004F5B70 08000624 */  addiu      $6, $0, 0x8
    /* 3F5B74 004F5B74 2D380000 */  daddu      $7, $0, $0
    /* 3F5B78 004F5B78 0B004014 */  bnez       $2, .L004F5BA8
    /* 3F5B7C 004F5B7C 97FF0824 */   addiu     $8, $0, -0x69
    /* 3F5B80 004F5B80 7600043C */  lui        $4, %hi(D_0075D6C8)
    /* 3F5B84 004F5B84 7600063C */  lui        $6, %hi(D_0075D798)
    /* 3F5B88 004F5B88 0000B0DF */  ld         $16, 0x0($29)
    /* 3F5B8C 004F5B8C C8D68424 */  addiu      $4, $4, %lo(D_0075D6C8)
    /* 3F5B90 004F5B90 0800BFDF */  ld         $31, 0x8($29)
    /* 3F5B94 004F5B94 98D7C624 */  addiu      $6, $6, %lo(D_0075D798)
    /* 3F5B98 004F5B98 C9090524 */  addiu      $5, $0, 0x9C9
    /* 3F5B9C 004F5B9C F0D41308 */  j          func_004f53c0
    /* 3F5BA0 004F5BA0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F5BA4 004F5BA4 00000000 */  nop
  .L004F5BA8:
    /* 3F5BA8 004F5BA8 DEFD100C */  jal        func_0043f778
    /* 3F5BAC 004F5BAC 00000000 */   nop
    /* 3F5BB0 004F5BB0 91FF0324 */  addiu      $3, $0, -0x6F
    /* 3F5BB4 004F5BB4 0A180200 */  movz       $3, $0, $2
    /* 3F5BB8 004F5BB8 0000B0DF */  ld         $16, 0x0($29)
    /* 3F5BBC 004F5BBC 0800BFDF */  ld         $31, 0x8($29)
    /* 3F5BC0 004F5BC0 2D106000 */  daddu      $2, $3, $0
    /* 3F5BC4 004F5BC4 0800E003 */  jr         $31
    /* 3F5BC8 004F5BC8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F5BCC 004F5BCC 00000000 */  nop
.size func_004f5b50, 0x80
