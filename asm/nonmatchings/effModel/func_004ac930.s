.section .text
.set noat
.set noreorder
glabel func_004ac930
    /* 3AC930 004AC930 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3AC934 004AC934 2000BFFF */  sd         $31, 0x20($29)
    /* 3AC938 004AC938 1000B17F */  sq         $17, 0x10($29)
    /* 3AC93C 004AC93C 0000B07F */  sq         $16, 0x0($29)
    /* 3AC940 004AC940 2D888000 */  daddu      $17, $4, $0
    /* 3AC944 004AC944 2D200000 */  daddu      $4, $0, $0
    /* 3AC948 004AC948 90B1120C */  jal        func_004ac640
    /* 3AC94C 004AC94C 00000000 */   nop
    /* 3AC950 004AC950 2D804000 */  daddu      $16, $2, $0
    /* 3AC954 004AC954 10000426 */  addiu      $4, $16, 0x10
    /* 3AC958 004AC958 10002526 */  addiu      $5, $17, 0x10
    /* 3AC95C 004AC95C A4000624 */  addiu      $6, $0, 0xA4
    /* 3AC960 004AC960 04FE100C */  jal        func_0043f810
    /* 3AC964 004AC964 00000000 */   nop
    /* 3AC968 004AC968 2D200002 */  daddu      $4, $16, $0
    /* 3AC96C 004AC96C 2D282002 */  daddu      $5, $17, $0
    /* 3AC970 004AC970 68B2120C */  jal        func_004ac9a0
    /* 3AC974 004AC974 00000000 */   nop
    /* 3AC978 004AC978 2D100002 */  daddu      $2, $16, $0
    /* 3AC97C 004AC97C 2000BFDF */  ld         $31, 0x20($29)
    /* 3AC980 004AC980 1000B17B */  lq         $17, 0x10($29)
    /* 3AC984 004AC984 0000B07B */  lq         $16, 0x0($29)
    /* 3AC988 004AC988 3000BD27 */  addiu      $29, $29, 0x30
    /* 3AC98C 004AC98C 0800E003 */  jr         $31
    /* 3AC990 004AC990 00000000 */   nop
    /* 3AC994 004AC994 00000000 */  nop
    /* 3AC998 004AC998 00000000 */  nop
    /* 3AC99C 004AC99C 00000000 */  nop
.size func_004ac930, 0x70
