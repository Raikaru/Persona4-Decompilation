.section .text
.set noat
.set noreorder
glabel func_004e7a58
    /* 3E7A58 004E7A58 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3E7A5C 004E7A5C 1800B1FF */  sd         $17, 0x18($29)
    /* 3E7A60 004E7A60 2D888000 */  daddu      $17, $4, $0
    /* 3E7A64 004E7A64 1000B0FF */  sd         $16, 0x10($29)
    /* 3E7A68 004E7A68 2000B2FF */  sd         $18, 0x20($29)
    /* 3E7A6C 004E7A6C 2800BFFF */  sd         $31, 0x28($29)
    /* 3E7A70 004E7A70 05002016 */  bnez       $17, .L004E7A88
    /* 3E7A74 004E7A74 0000A0FF */   sd        $0, 0x0($29)
    /* 3E7A78 004E7A78 7600053C */  lui        $5, %hi(D_0075B5E8)
    /* 3E7A7C 004E7A7C 10000010 */  b          .L004E7AC0
    /* 3E7A80 004E7A80 E8B5A524 */   addiu     $5, $5, %lo(D_0075B5E8)
    /* 3E7A84 004E7A84 00000000 */  nop
  .L004E7A88:
    /* 3E7A88 004E7A88 0500C010 */  beqz       $6, .L004E7AA0
    /* 3E7A8C 004E7A8C 7600053C */   lui       $5, %hi(D_0075B610)
    /* 3E7A90 004E7A90 2D200000 */  daddu      $4, $0, $0
    /* 3E7A94 004E7A94 0A000010 */  b          .L004E7AC0
    /* 3E7A98 004E7A98 10B6A524 */   addiu     $5, $5, %lo(D_0075B610)
    /* 3E7A9C 004E7A9C 00000000 */  nop
  .L004E7AA0:
    /* 3E7AA0 004E7AA0 809E130C */  jal        func_004e7a00
    /* 3E7AA4 004E7AA4 00000000 */   nop
    /* 3E7AA8 004E7AA8 2D804000 */  daddu      $16, $2, $0
    /* 3E7AAC 004E7AAC 08000016 */  bnez       $16, .L004E7AD0
    /* 3E7AB0 004E7AB0 2D202002 */   daddu     $4, $17, $0
    /* 3E7AB4 004E7AB4 7600053C */  lui        $5, %hi(D_0075B638)
    /* 3E7AB8 004E7AB8 2D200000 */  daddu      $4, $0, $0
    /* 3E7ABC 004E7ABC 38B6A524 */  addiu      $5, $5, %lo(D_0075B638)
  .L004E7AC0:
    /* 3E7AC0 004E7AC0 169D130C */  jal        func_004e7458
    /* 3E7AC4 004E7AC4 00000000 */   nop
    /* 3E7AC8 004E7AC8 3B000010 */  b          .L004E7BB8
    /* 3E7ACC 004E7ACC 2D100000 */   daddu     $2, $0, $0
  .L004E7AD0:
    /* 3E7AD0 004E7AD0 E6A2130C */  jal        func_004e8b98
    /* 3E7AD4 004E7AD4 2D28A003 */   daddu     $5, $29, $0
    /* 3E7AD8 004E7AD8 0400A28F */  lw         $2, 0x4($29)
    /* 3E7ADC 004E7ADC 24004014 */  bnez       $2, .L004E7B70
    /* 3E7AE0 004E7AE0 01000224 */   addiu     $2, $0, 0x1
    /* 3E7AE4 004E7AE4 7300023C */  lui        $2, %hi(D_00734240)
    /* 3E7AE8 004E7AE8 2D202002 */  daddu      $4, $17, $0
    /* 3E7AEC 004E7AEC 40425224 */  addiu      $18, $2, %lo(D_00734240)
    /* 3E7AF0 004E7AF0 A8A0130C */  jal        func_004e82a0
    /* 3E7AF4 004E7AF4 2D284002 */   daddu     $5, $18, $0
    /* 3E7AF8 004E7AF8 7600043C */  lui        $4, %hi(D_0075B668)
    /* 3E7AFC 004E7AFC 68B68424 */  addiu      $4, $4, %lo(D_0075B668)
    /* 3E7B00 004E7B00 DE34130C */  jal        func_004cd378
    /* 3E7B04 004E7B04 2D282002 */   daddu     $5, $17, $0
    /* 3E7B08 004E7B08 F09D130C */  jal        func_004e77c0
    /* 3E7B0C 004E7B0C 2D202002 */   daddu     $4, $17, $0
    /* 3E7B10 004E7B10 2D184000 */  daddu      $3, $2, $0
    /* 3E7B14 004E7B14 2D100000 */  daddu      $2, $0, $0
    /* 3E7B18 004E7B18 27006010 */  beqz       $3, .L004E7BB8
    /* 3E7B1C 004E7B1C 080003FE */   sd        $3, 0x8($16)
    /* 3E7B20 004E7B20 8691130C */  jal        func_004e4618
    /* 3E7B24 004E7B24 00490424 */   addiu     $4, $0, 0x4900
    /* 3E7B28 004E7B28 7300023C */  lui        $2, %hi(D_00734380)
    /* 3E7B2C 004E7B2C 8043458C */  lw         $5, %lo(D_00734380)($2)
    /* 3E7B30 004E7B30 4A92130C */  jal        func_004e4928
    /* 3E7B34 004E7B34 2D204002 */   daddu     $4, $18, $0
    /* 3E7B38 004E7B38 01490424 */  addiu      $4, $0, 0x4901
    /* 3E7B3C 004E7B3C 8691130C */  jal        func_004e4618
    /* 3E7B40 004E7B40 180002AE */   sw        $2, 0x18($16)
    /* 3E7B44 004E7B44 1800028E */  lw         $2, 0x18($16)
    /* 3E7B48 004E7B48 0E004304 */  bgezl      $2, .L004E7B84
    /* 3E7B4C 004E7B4C 010000A2 */   sb        $0, 0x1($16)
    /* 3E7B50 004E7B50 7600053C */  lui        $5, %hi(D_0075B690)
    /* 3E7B54 004E7B54 2D200000 */  daddu      $4, $0, $0
    /* 3E7B58 004E7B58 169D130C */  jal        func_004e7458
    /* 3E7B5C 004E7B5C 90B6A524 */   addiu     $5, $5, %lo(D_0075B690)
    /* 3E7B60 004E7B60 8E9E130C */  jal        func_004e7a38
    /* 3E7B64 004E7B64 2D200002 */   daddu     $4, $16, $0
    /* 3E7B68 004E7B68 13000010 */  b          .L004E7BB8
    /* 3E7B6C 004E7B6C 2D100000 */   daddu     $2, $0, $0
  .L004E7B70:
    /* 3E7B70 004E7B70 010002A2 */  sb         $2, 0x1($16)
    /* 3E7B74 004E7B74 0000A38F */  lw         $3, 0x0($29)
    /* 3E7B78 004E7B78 180003AE */  sw         $3, 0x18($16)
    /* 3E7B7C 004E7B7C 0400A28F */  lw         $2, 0x4($29)
    /* 3E7B80 004E7B80 080002FE */  sd         $2, 0x8($16)
  .L004E7B84:
    /* 3E7B84 004E7B84 080003DE */  ld         $3, 0x8($16)
    /* 3E7B88 004E7B88 01000224 */  addiu      $2, $0, 0x1
    /* 3E7B8C 004E7B8C 1C0000AE */  sw         $0, 0x1C($16)
    /* 3E7B90 004E7B90 FF076364 */  daddiu     $3, $3, 0x7FF
    /* 3E7B94 004E7B94 200000AE */  sw         $0, 0x20($16)
    /* 3E7B98 004E7B98 781D0300 */  dsll       $3, $3, 21
    /* 3E7B9C 004E7B9C 3F180300 */  dsra32     $3, $3, 0
    /* 3E7BA0 004E7BA0 240000AE */  sw         $0, 0x24($16)
    /* 3E7BA4 004E7BA4 100003AE */  sw         $3, 0x10($16)
    /* 3E7BA8 004E7BA8 140000AE */  sw         $0, 0x14($16)
    /* 3E7BAC 004E7BAC 020000A2 */  sb         $0, 0x2($16)
    /* 3E7BB0 004E7BB0 000002A2 */  sb         $2, 0x0($16)
    /* 3E7BB4 004E7BB4 2D100002 */  daddu      $2, $16, $0
  .L004E7BB8:
    /* 3E7BB8 004E7BB8 1000B0DF */  ld         $16, 0x10($29)
    /* 3E7BBC 004E7BBC 1800B1DF */  ld         $17, 0x18($29)
    /* 3E7BC0 004E7BC0 2000B2DF */  ld         $18, 0x20($29)
    /* 3E7BC4 004E7BC4 2800BFDF */  ld         $31, 0x28($29)
    /* 3E7BC8 004E7BC8 0800E003 */  jr         $31
    /* 3E7BCC 004E7BCC 3000BD27 */   addiu     $29, $29, 0x30
.size func_004e7a58, 0x178
