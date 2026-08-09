.section .text
.set noat
.set noreorder
glabel func_004f0ce8
    /* 3F0CE8 004F0CE8 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3F0CEC 004F0CEC 0600A22C */  sltiu      $2, $5, 0x6
    /* 3F0CF0 004F0CF0 0800B1FF */  sd         $17, 0x8($29)
    /* 3F0CF4 004F0CF4 2D880001 */  daddu      $17, $8, $0
    /* 3F0CF8 004F0CF8 1000B2FF */  sd         $18, 0x10($29)
    /* 3F0CFC 004F0CFC 2D90C000 */  daddu      $18, $6, $0
    /* 3F0D00 004F0D00 1800B3FF */  sd         $19, 0x18($29)
    /* 3F0D04 004F0D04 2D98E000 */  daddu      $19, $7, $0
    /* 3F0D08 004F0D08 0000B0FF */  sd         $16, 0x0($29)
    /* 3F0D0C 004F0D0C 0800832C */  sltiu      $3, $4, 0x8
    /* 3F0D10 004F0D10 0B004014 */  bnez       $2, .L004F0D40
    /* 3F0D14 004F0D14 2000BFFF */   sd        $31, 0x20($29)
    /* 3F0D18 004F0D18 7600043C */  lui        $4, %hi(D_0075D290)
    /* 3F0D1C 004F0D1C 0000B0DF */  ld         $16, 0x0($29)
    /* 3F0D20 004F0D20 0800B1DF */  ld         $17, 0x8($29)
    /* 3F0D24 004F0D24 90D28424 */  addiu      $4, $4, %lo(D_0075D290)
    /* 3F0D28 004F0D28 1000B2DF */  ld         $18, 0x10($29)
    /* 3F0D2C 004F0D2C 1800B3DF */  ld         $19, 0x18($29)
    /* 3F0D30 004F0D30 2000BFDF */  ld         $31, 0x20($29)
    /* 3F0D34 004F0D34 F8C11308 */  j          func_004f07e0
    /* 3F0D38 004F0D38 3000BD27 */   addiu     $29, $29, 0x30
    /* 3F0D3C 004F0D3C 00000000 */  nop
  .L004F0D40:
    /* 3F0D40 004F0D40 0B006014 */  bnez       $3, .L004F0D70
    /* 3F0D44 004F0D44 C0100400 */   sll       $2, $4, 3
    /* 3F0D48 004F0D48 7600043C */  lui        $4, %hi(D_0075D2B8)
    /* 3F0D4C 004F0D4C 0000B0DF */  ld         $16, 0x0($29)
    /* 3F0D50 004F0D50 0800B1DF */  ld         $17, 0x8($29)
    /* 3F0D54 004F0D54 B8D28424 */  addiu      $4, $4, %lo(D_0075D2B8)
    /* 3F0D58 004F0D58 1000B2DF */  ld         $18, 0x10($29)
    /* 3F0D5C 004F0D5C 1800B3DF */  ld         $19, 0x18($29)
    /* 3F0D60 004F0D60 2000BFDF */  ld         $31, 0x20($29)
    /* 3F0D64 004F0D64 F8C11308 */  j          func_004f07e0
    /* 3F0D68 004F0D68 3000BD27 */   addiu     $29, $29, 0x30
    /* 3F0D6C 004F0D6C 00000000 */  nop
  .L004F0D70:
    /* 3F0D70 004F0D70 40180500 */  sll        $3, $5, 1
    /* 3F0D74 004F0D74 21104400 */  addu       $2, $2, $4
    /* 3F0D78 004F0D78 21186500 */  addu       $3, $3, $5
    /* 3F0D7C 004F0D7C 80180300 */  sll        $3, $3, 2
    /* 3F0D80 004F0D80 C0100200 */  sll        $2, $2, 3
    /* 3F0D84 004F0D84 21104300 */  addu       $2, $2, $3
    /* 3F0D88 004F0D88 9200103C */  lui        $16, %hi(D_00925BE0)
    /* 3F0D8C 004F0D8C E05B1026 */  addiu      $16, $16, %lo(D_00925BE0)
    /* 3F0D90 004F0D90 21800202 */  addu       $16, $16, $2
    /* 3F0D94 004F0D94 0000038E */  lw         $3, 0x0($16)
    /* 3F0D98 004F0D98 05006050 */  beql       $3, $0, .L004F0DB0
    /* 3F0D9C 004F0D9C 000012AE */   sw        $18, 0x0($16)
    /* 3F0DA0 004F0DA0 7600043C */  lui        $4, %hi(D_0075D2E0)
    /* 3F0DA4 004F0DA4 F8C1130C */  jal        func_004f07e0
    /* 3F0DA8 004F0DA8 E0D28424 */   addiu     $4, $4, %lo(D_0075D2E0)
    /* 3F0DAC 004F0DAC 000012AE */  sw         $18, 0x0($16)
  .L004F0DB0:
    /* 3F0DB0 004F0DB0 03002012 */  beqz       $17, .L004F0DC0
    /* 3F0DB4 004F0DB4 040013AE */   sw        $19, 0x4($16)
    /* 3F0DB8 004F0DB8 04000010 */  b          .L004F0DCC
    /* 3F0DBC 004F0DBC 080011AE */   sw        $17, 0x8($16)
  .L004F0DC0:
    /* 3F0DC0 004F0DC0 7600023C */  lui        $2, %hi(D_0075D210)
    /* 3F0DC4 004F0DC4 10D24224 */  addiu      $2, $2, %lo(D_0075D210)
    /* 3F0DC8 004F0DC8 080002AE */  sw         $2, 0x8($16)
  .L004F0DCC:
    /* 3F0DCC 004F0DCC 0000B0DF */  ld         $16, 0x0($29)
    /* 3F0DD0 004F0DD0 0800B1DF */  ld         $17, 0x8($29)
    /* 3F0DD4 004F0DD4 1000B2DF */  ld         $18, 0x10($29)
    /* 3F0DD8 004F0DD8 1800B3DF */  ld         $19, 0x18($29)
    /* 3F0DDC 004F0DDC 2000BFDF */  ld         $31, 0x20($29)
    /* 3F0DE0 004F0DE0 0800E003 */  jr         $31
    /* 3F0DE4 004F0DE4 3000BD27 */   addiu     $29, $29, 0x30
.size func_004f0ce8, 0x100
