.section .text
.set noat
.set noreorder
glabel func_004cf920
    /* 3CF920 004CF920 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CF924 004CF924 2D108000 */  daddu      $2, $4, $0
    /* 3CF928 004CF928 07004010 */  beqz       $2, .L004CF948
    /* 3CF92C 004CF92C 0000BFFF */   sd        $31, 0x0($29)
    /* 3CF930 004CF930 0000BFDF */  ld         $31, 0x0($29)
    /* 3CF934 004CF934 2D280000 */  daddu      $5, $0, $0
    /* 3CF938 004CF938 90000624 */  addiu      $6, $0, 0x90
    /* 3CF93C 004CF93C 000040A0 */  sb         $0, 0x0($2)
    /* 3CF940 004CF940 72FE1008 */  j          func_0043f9c8
    /* 3CF944 004CF944 1000BD27 */   addiu     $29, $29, 0x10
  .L004CF948:
    /* 3CF948 004CF948 0000BFDF */  ld         $31, 0x0($29)
    /* 3CF94C 004CF94C 0800E003 */  jr         $31
    /* 3CF950 004CF950 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CF954 004CF954 00000000 */  nop
.size func_004cf920, 0x38
