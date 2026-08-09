.section .text
.set noat
.set noreorder
glabel func_003de9c0
    /* 2DE9C0 003DE9C0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2DE9C4 003DE9C4 01000224 */  addiu      $2, $0, 0x1
    /* 2DE9C8 003DE9C8 1000BFFF */  sd         $31, 0x10($29)
    /* 2DE9CC 003DE9CC 0000B07F */  sq         $16, 0x0($29)
    /* 2DE9D0 003DE9D0 3800838C */  lw         $3, 0x38($4)
    /* 2DE9D4 003DE9D4 03006214 */  bne        $3, $2, .L003DE9E4
    /* 2DE9D8 003DE9D8 2D808000 */   daddu     $16, $4, $0
  .L003DE9DC:
    /* 2DE9DC 003DE9DC 05000010 */  b          .L003DE9F4
    /* 2DE9E0 003DE9E0 3800028E */   lw        $2, 0x38($16)
  .L003DE9E4:
    /* 2DE9E4 003DE9E4 307A0F0C */  jal        func_003de8c0
    /* 2DE9E8 003DE9E8 2D280000 */   daddu     $5, $0, $0
    /* 2DE9EC 003DE9EC FBFF0010 */  b          .L003DE9DC
    /* 2DE9F0 003DE9F0 00000000 */   nop
  .L003DE9F4:
    /* 2DE9F4 003DE9F4 1000BFDF */  ld         $31, 0x10($29)
    /* 2DE9F8 003DE9F8 0000B07B */  lq         $16, 0x0($29)
    /* 2DE9FC 003DE9FC 0800E003 */  jr         $31
    /* 2DEA00 003DEA00 2000BD27 */   addiu     $29, $29, 0x20
    /* 2DEA04 003DEA04 00000000 */  nop
    /* 2DEA08 003DEA08 00000000 */  nop
    /* 2DEA0C 003DEA0C 00000000 */  nop
.size func_003de9c0, 0x50
