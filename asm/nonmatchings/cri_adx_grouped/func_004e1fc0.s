.section .text
.set noat
.set noreorder
glabel func_004e1fc0
    /* 3E1FC0 004E1FC0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3E1FC4 004E1FC4 0000B0FF */  sd         $16, 0x0($29)
    /* 3E1FC8 004E1FC8 9200103C */  lui        $16, %hi(D_00923640)
    /* 3E1FCC 004E1FCC 40361026 */  addiu      $16, $16, %lo(D_00923640)
    /* 3E1FD0 004E1FD0 0800B1FF */  sd         $17, 0x8($29)
    /* 3E1FD4 004E1FD4 2D888000 */  daddu      $17, $4, $0
    /* 3E1FD8 004E1FD8 1000BFFF */  sd         $31, 0x10($29)
    /* 3E1FDC 004E1FDC 520A110C */  jal        func_00442948
    /* 3E1FE0 004E1FE0 2D200002 */   daddu     $4, $16, $0
    /* 3E1FE4 004E1FE4 01004624 */  addiu      $6, $2, 0x1
    /* 3E1FE8 004E1FE8 00000282 */  lb         $2, 0x0($16)
    /* 3E1FEC 004E1FEC 2D202002 */  daddu      $4, $17, $0
    /* 3E1FF0 004E1FF0 07004014 */  bnez       $2, .L004E2010
    /* 3E1FF4 004E1FF4 2D280002 */   daddu     $5, $16, $0
    /* 3E1FF8 004E1FF8 000020A2 */  sb         $0, 0x0($17)
    /* 3E1FFC 004E1FFC 0000B0DF */  ld         $16, 0x0($29)
    /* 3E2000 004E2000 0800B1DF */  ld         $17, 0x8($29)
    /* 3E2004 004E2004 1000BFDF */  ld         $31, 0x10($29)
    /* 3E2008 004E2008 0800E003 */  jr         $31
    /* 3E200C 004E200C 2000BD27 */   addiu     $29, $29, 0x20
  .L004E2010:
    /* 3E2010 004E2010 0000B0DF */  ld         $16, 0x0($29)
    /* 3E2014 004E2014 0800B1DF */  ld         $17, 0x8($29)
    /* 3E2018 004E2018 1000BFDF */  ld         $31, 0x10($29)
    /* 3E201C 004E201C 04FE1008 */  j          func_0043f810
    /* 3E2020 004E2020 2000BD27 */   addiu     $29, $29, 0x20
    /* 3E2024 004E2024 00000000 */  nop
.size func_004e1fc0, 0x68
