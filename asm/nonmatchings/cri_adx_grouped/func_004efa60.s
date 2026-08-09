.section .text
.set noat
.set noreorder
glabel func_004efa60
    /* 3EFA60 004EFA60 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3EFA64 004EFA64 0000B0FF */  sd         $16, 0x0($29)
    /* 3EFA68 004EFA68 2D808000 */  daddu      $16, $4, $0
    /* 3EFA6C 004EFA6C 0800B1FF */  sd         $17, 0x8($29)
    /* 3EFA70 004EFA70 2D88A000 */  daddu      $17, $5, $0
    /* 3EFA74 004EFA74 1000BFFF */  sd         $31, 0x10($29)
    /* 3EFA78 004EFA78 2D280000 */  daddu      $5, $0, $0
    /* 3EFA7C 004EFA7C 0000048E */  lw         $4, 0x0($16)
    /* 3EFA80 004EFA80 72FE100C */  jal        func_0043f9c8
    /* 3EFA84 004EFA84 0400068E */   lw        $6, 0x4($16)
    /* 3EFA88 004EFA88 0000048E */  lw         $4, 0x0($16)
    /* 3EFA8C 004EFA8C 2D282002 */  daddu      $5, $17, $0
    /* 3EFA90 004EFA90 7A0B110C */  jal        func_00442de8
    /* 3EFA94 004EFA94 07000624 */   addiu     $6, $0, 0x7
    /* 3EFA98 004EFA98 0400048E */  lw         $4, 0x4($16)
    /* 3EFA9C 004EFA9C 0000058E */  lw         $5, 0x0($16)
    /* 3EFAA0 004EFAA0 0800B1DF */  ld         $17, 0x8($29)
    /* 3EFAA4 004EFAA4 F0FF8424 */  addiu      $4, $4, -0x10
    /* 3EFAA8 004EFAA8 0000B0DF */  ld         $16, 0x0($29)
    /* 3EFAAC 004EFAAC 0800A524 */  addiu      $5, $5, 0x8
    /* 3EFAB0 004EFAB0 1000BFDF */  ld         $31, 0x10($29)
    /* 3EFAB4 004EFAB4 46BE1308 */  j          func_004ef918
    /* 3EFAB8 004EFAB8 2000BD27 */   addiu     $29, $29, 0x20
    /* 3EFABC 004EFABC 00000000 */  nop
.size func_004efa60, 0x60
