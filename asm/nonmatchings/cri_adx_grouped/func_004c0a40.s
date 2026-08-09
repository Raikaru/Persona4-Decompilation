.section .text
.set noat
.set noreorder
glabel func_004c0a40
    /* 3C0A40 004C0A40 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3C0A44 004C0A44 2D108000 */  daddu      $2, $4, $0
    /* 3C0A48 004C0A48 0800B1FF */  sd         $17, 0x8($29)
    /* 3C0A4C 004C0A4C 2D88A000 */  daddu      $17, $5, $0
    /* 3C0A50 004C0A50 0000B0FF */  sd         $16, 0x0($29)
    /* 3C0A54 004C0A54 12002012 */  beqz       $17, .L004C0AA0
    /* 3C0A58 004C0A58 1000BFFF */   sd        $31, 0x10($29)
    /* 3C0A5C 004C0A5C 2D202002 */  daddu      $4, $17, $0
    /* 3C0A60 004C0A60 70FA120C */  jal        func_004be9c0
    /* 3C0A64 004C0A64 2D804000 */   daddu     $16, $2, $0
    /* 3C0A68 004C0A68 2D180000 */  daddu      $3, $0, $0
    /* 3C0A6C 004C0A6C 00000000 */  nop
  .L004C0A70:
    /* 3C0A70 004C0A70 10006228 */  slti       $2, $3, 0x10
    /* 3C0A74 004C0A74 0A004010 */  beqz       $2, .L004C0AA0
    /* 3C0A78 004C0A78 01006324 */   addiu     $3, $3, 0x1
    /* 3C0A7C 004C0A7C 0000028E */  lw         $2, 0x0($16)
    /* 3C0A80 004C0A80 00000000 */  nop
    /* 3C0A84 004C0A84 00000000 */  nop
    /* 3C0A88 004C0A88 00000000 */  nop
    /* 3C0A8C 004C0A8C F8FF5154 */  bnel       $2, $17, .L004C0A70
    /* 3C0A90 004C0A90 04001026 */   addiu     $16, $16, 0x4
    /* 3C0A94 004C0A94 20F9120C */  jal        func_004be480
    /* 3C0A98 004C0A98 2D202002 */   daddu     $4, $17, $0
    /* 3C0A9C 004C0A9C 000000AE */  sw         $0, 0x0($16)
  .L004C0AA0:
    /* 3C0AA0 004C0AA0 0000B0DF */  ld         $16, 0x0($29)
    /* 3C0AA4 004C0AA4 0800B1DF */  ld         $17, 0x8($29)
    /* 3C0AA8 004C0AA8 1000BFDF */  ld         $31, 0x10($29)
    /* 3C0AAC 004C0AAC 0800E003 */  jr         $31
    /* 3C0AB0 004C0AB0 2000BD27 */   addiu     $29, $29, 0x20
    /* 3C0AB4 004C0AB4 00000000 */  nop
.size func_004c0a40, 0x78
