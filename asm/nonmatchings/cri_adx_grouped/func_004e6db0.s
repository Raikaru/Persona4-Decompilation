.section .text
.set noat
.set noreorder
glabel func_004e6db0
    /* 3E6DB0 004E6DB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E6DB4 004E6DB4 0000B0FF */  sd         $16, 0x0($29)
    /* 3E6DB8 004E6DB8 0800BFFF */  sd         $31, 0x8($29)
    /* 3E6DBC 004E6DBC 520A110C */  jal        func_00442948
    /* 3E6DC0 004E6DC0 2D808000 */   daddu     $16, $4, $0
    /* 3E6DC4 004E6DC4 11000324 */  addiu      $3, $0, 0x11
    /* 3E6DC8 004E6DC8 04004314 */  bne        $2, $3, .L004E6DDC
    /* 3E6DCC 004E6DCC 2D100000 */   daddu     $2, $0, $0
    /* 3E6DD0 004E6DD0 08000282 */  lb         $2, 0x8($16)
    /* 3E6DD4 004E6DD4 2E004238 */  xori       $2, $2, 0x2E
    /* 3E6DD8 004E6DD8 0100422C */  sltiu      $2, $2, 0x1
  .L004E6DDC:
    /* 3E6DDC 004E6DDC 0000B0DF */  ld         $16, 0x0($29)
    /* 3E6DE0 004E6DE0 0800BFDF */  ld         $31, 0x8($29)
    /* 3E6DE4 004E6DE4 0800E003 */  jr         $31
    /* 3E6DE8 004E6DE8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3E6DEC 004E6DEC 00000000 */  nop
.size func_004e6db0, 0x40
