.section .text
.set noat
.set noreorder
glabel func_0044bc68
    /* 34BC68 0044BC68 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 34BC6C 0044BC6C 0000B0FF */  sd         $16, 0x0($29)
    /* 34BC70 0044BC70 0800B1FF */  sd         $17, 0x8($29)
    /* 34BC74 0044BC74 2D800000 */  daddu      $16, $0, $0
    /* 34BC78 0044BC78 1000BFFF */  sd         $31, 0x10($29)
    /* 34BC7C 0044BC7C 2D888000 */  daddu      $17, $4, $0
    /* 34BC80 0044BC80 8239110C */  jal        func_0044e608
    /* 34BC84 0044BC84 2D280002 */   daddu     $5, $16, $0
    /* 34BC88 0044BC88 2D282002 */  daddu      $5, $17, $0
    /* 34BC8C 0044BC8C 07004004 */  bltz       $2, .L0044BCAC
    /* 34BC90 0044BC90 2D200002 */   daddu     $4, $16, $0
    /* 34BC94 0044BC94 2D202002 */  daddu      $4, $17, $0
    /* 34BC98 0044BC98 0000B0DF */  ld         $16, 0x0($29)
    /* 34BC9C 0044BC9C 0800B1DF */  ld         $17, 0x8($29)
    /* 34BCA0 0044BCA0 1000BFDF */  ld         $31, 0x10($29)
    /* 34BCA4 0044BCA4 D82E1108 */  j          func_0044bb60
    /* 34BCA8 0044BCA8 2000BD27 */   addiu     $29, $29, 0x20
  .L0044BCAC:
    /* 34BCAC 0044BCAC 4038110C */  jal        func_0044e100
    /* 34BCB0 0044BCB0 00000000 */   nop
    /* 34BCB4 0044BCB4 D82E110C */  jal        func_0044bb60
    /* 34BCB8 0044BCB8 2D204000 */   daddu     $4, $2, $0
    /* 34BCBC 0044BCBC 0000B0DF */  ld         $16, 0x0($29)
    /* 34BCC0 0044BCC0 2F100200 */  dsubu      $2, $0, $2
    /* 34BCC4 0044BCC4 0800B1DF */  ld         $17, 0x8($29)
    /* 34BCC8 0044BCC8 1000BFDF */  ld         $31, 0x10($29)
    /* 34BCCC 0044BCCC 0800E003 */  jr         $31
    /* 34BCD0 0044BCD0 2000BD27 */   addiu     $29, $29, 0x20
    /* 34BCD4 0044BCD4 00000000 */  nop
.size func_0044bc68, 0x70
