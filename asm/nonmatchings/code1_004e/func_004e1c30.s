.section .text
.set noat
.set noreorder
glabel func_004e1c30
    /* 3E1C30 004E1C30 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3E1C34 004E1C34 0800B1FF */  sd         $17, 0x8($29)
    /* 3E1C38 004E1C38 2D888000 */  daddu      $17, $4, $0
    /* 3E1C3C 004E1C3C 1000B2FF */  sd         $18, 0x10($29)
    /* 3E1C40 004E1C40 2D90A000 */  daddu      $18, $5, $0
    /* 3E1C44 004E1C44 1800B3FF */  sd         $19, 0x18($29)
    /* 3E1C48 004E1C48 0000B0FF */  sd         $16, 0x0($29)
    /* 3E1C4C 004E1C4C 2000BFFF */  sd         $31, 0x20($29)
    /* 3E1C50 004E1C50 00002282 */  lb         $2, 0x0($17)
    /* 3E1C54 004E1C54 06004014 */  bnez       $2, .L004E1C70
    /* 3E1C58 004E1C58 2D98C000 */   daddu     $19, $6, $0
    /* 3E1C5C 004E1C5C F087130C */  jal        func_004e1fc0
    /* 3E1C60 004E1C60 00000000 */   nop
    /* 3E1C64 004E1C64 00002382 */  lb         $3, 0x0($17)
    /* 3E1C68 004E1C68 14006010 */  beqz       $3, .L004E1CBC
    /* 3E1C6C 004E1C6C 2D100000 */   daddu     $2, $0, $0
  .L004E1C70:
    /* 3E1C70 004E1C70 2D284002 */  daddu      $5, $18, $0
    /* 3E1C74 004E1C74 E48C130C */  jal        func_004e3390
    /* 3E1C78 004E1C78 2D202002 */   daddu     $4, $17, $0
    /* 3E1C7C 004E1C7C 4286130C */  jal        func_004e1908
    /* 3E1C80 004E1C80 2D202002 */   daddu     $4, $17, $0
    /* 3E1C84 004E1C84 2D804000 */  daddu      $16, $2, $0
    /* 3E1C88 004E1C88 0B000016 */  bnez       $16, .L004E1CB8
    /* 3E1C8C 004E1C8C 2D202002 */   daddu     $4, $17, $0
    /* 3E1C90 004E1C90 F087130C */  jal        func_004e1fc0
    /* 3E1C94 004E1C94 00000000 */   nop
    /* 3E1C98 004E1C98 4286130C */  jal        func_004e1908
    /* 3E1C9C 004E1C9C 2D202002 */   daddu     $4, $17, $0
    /* 3E1CA0 004E1CA0 2D204002 */  daddu      $4, $18, $0
    /* 3E1CA4 004E1CA4 2D804000 */  daddu      $16, $2, $0
    /* 3E1CA8 004E1CA8 04000012 */  beqz       $16, .L004E1CBC
    /* 3E1CAC 004E1CAC 2D286002 */   daddu     $5, $19, $0
    /* 3E1CB0 004E1CB0 0C0A110C */  jal        func_00442830
    /* 3E1CB4 004E1CB4 00000000 */   nop
  .L004E1CB8:
    /* 3E1CB8 004E1CB8 2D100002 */  daddu      $2, $16, $0
  .L004E1CBC:
    /* 3E1CBC 004E1CBC 0000B0DF */  ld         $16, 0x0($29)
    /* 3E1CC0 004E1CC0 0800B1DF */  ld         $17, 0x8($29)
    /* 3E1CC4 004E1CC4 1000B2DF */  ld         $18, 0x10($29)
    /* 3E1CC8 004E1CC8 1800B3DF */  ld         $19, 0x18($29)
    /* 3E1CCC 004E1CCC 2000BFDF */  ld         $31, 0x20($29)
    /* 3E1CD0 004E1CD0 0800E003 */  jr         $31
    /* 3E1CD4 004E1CD4 3000BD27 */   addiu     $29, $29, 0x30
.size func_004e1c30, 0xa8
