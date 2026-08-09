.section .text
.set noat
.set noreorder
glabel func_0050ecb8
    /* 40ECB8 0050ECB8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40ECBC 0050ECBC 0000B0FF */  sd         $16, 0x0($29)
    /* 40ECC0 0050ECC0 0800BFFF */  sd         $31, 0x8($29)
    /* 40ECC4 0050ECC4 2E39140C */  jal        func_0050e4b8
    /* 40ECC8 0050ECC8 2D80A000 */   daddu     $16, $5, $0
    /* 40ECCC 0050ECCC 0800BFDF */  ld         $31, 0x8($29)
    /* 40ECD0 0050ECD0 2D280002 */  daddu      $5, $16, $0
    /* 40ECD4 0050ECD4 0000B0DF */  ld         $16, 0x0($29)
    /* 40ECD8 0050ECD8 2D204000 */  daddu      $4, $2, $0
    /* 40ECDC 0050ECDC 90AE1408 */  j          func_0052ba40
    /* 40ECE0 0050ECE0 1000BD27 */   addiu     $29, $29, 0x10
    /* 40ECE4 0050ECE4 00000000 */  nop
.size func_0050ecb8, 0x30
