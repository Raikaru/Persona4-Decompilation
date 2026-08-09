.section .text
.set noat
.set noreorder
glabel func_003e9d50
    /* 2E9D50 003E9D50 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2E9D54 003E9D54 1000BFFF */  sd         $31, 0x10($29)
    /* 2E9D58 003E9D58 0000B07F */  sq         $16, 0x0($29)
    /* 2E9D5C 003E9D5C 2D808000 */  daddu      $16, $4, $0
    /* 2E9D60 003E9D60 1C820F0C */  jal        func_003e0870
    /* 2E9D64 003E9D64 10000426 */   addiu     $4, $16, 0x10
    /* 2E9D68 003E9D68 A000038E */  lw         $3, 0xA0($16)
    /* 2E9D6C 003E9D6C 03006590 */  lbu        $5, 0x3($3)
    /* 2E9D70 003E9D70 0300A230 */  andi       $2, $5, 0x3
    /* 2E9D74 003E9D74 09004010 */  beqz       $2, .L003E9D9C
    /* 2E9D78 003E9D78 00000000 */   nop
  .L003E9D7C:
    /* 2E9D7C 003E9D7C A000038E */  lw         $3, 0xA0($16)
    /* 2E9D80 003E9D80 0300A434 */  ori        $4, $5, 0x3
    /* 2E9D84 003E9D84 2D100002 */  daddu      $2, $16, $0
    /* 2E9D88 003E9D88 030064A0 */  sb         $4, 0x3($3)
    /* 2E9D8C 003E9D8C 03000392 */  lbu        $3, 0x3($16)
    /* 2E9D90 003E9D90 0C006334 */  ori        $3, $3, 0xC
    /* 2E9D94 003E9D94 0F000010 */  b          .L003E9DD4
    /* 2E9D98 003E9D98 030003A2 */   sb        $3, 0x3($16)
  .L003E9D9C:
    /* 2E9D9C 003E9D9C 8800043C */  lui        $4, %hi(D_0088739C)
    /* 2E9DA0 003E9DA0 9C738424 */  addiu      $4, $4, %lo(D_0088739C)
    /* 2E9DA4 003E9DA4 0000828C */  lw         $2, 0x0($4)
    /* 2E9DA8 003E9DA8 080062AC */  sw         $2, 0x8($3)
    /* 2E9DAC 003E9DAC A000028E */  lw         $2, 0xA0($16)
    /* 2E9DB0 003E9DB0 0C0044AC */  sw         $4, 0xC($2)
    /* 2E9DB4 003E9DB4 A000038E */  lw         $3, 0xA0($16)
    /* 2E9DB8 003E9DB8 0000828C */  lw         $2, 0x0($4)
    /* 2E9DBC 003E9DBC 08006324 */  addiu      $3, $3, 0x8
    /* 2E9DC0 003E9DC0 040043AC */  sw         $3, 0x4($2)
    /* 2E9DC4 003E9DC4 A000028E */  lw         $2, 0xA0($16)
    /* 2E9DC8 003E9DC8 08004224 */  addiu      $2, $2, 0x8
    /* 2E9DCC 003E9DCC EBFF0010 */  b          .L003E9D7C
    /* 2E9DD0 003E9DD0 000082AC */   sw        $2, 0x0($4)
  .L003E9DD4:
    /* 2E9DD4 003E9DD4 1000BFDF */  ld         $31, 0x10($29)
    /* 2E9DD8 003E9DD8 0000B07B */  lq         $16, 0x0($29)
    /* 2E9DDC 003E9DDC 0800E003 */  jr         $31
    /* 2E9DE0 003E9DE0 2000BD27 */   addiu     $29, $29, 0x20
    /* 2E9DE4 003E9DE4 00000000 */  nop
    /* 2E9DE8 003E9DE8 00000000 */  nop
    /* 2E9DEC 003E9DEC 00000000 */  nop
.size func_003e9d50, 0xa0
