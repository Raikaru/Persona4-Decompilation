.section .text
.set noat
.set noreorder
glabel func_003e1b10
    /* 2E1B10 003E1B10 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2E1B14 003E1B14 10000524 */  addiu      $5, $0, 0x10
    /* 2E1B18 003E1B18 1000BFFF */  sd         $31, 0x10($29)
    /* 2E1B1C 003E1B1C 8800083C */  lui        $8, %hi(D_008871F0)
    /* 2E1B20 003E1B20 0000B07F */  sq         $16, 0x0($29)
    /* 2E1B24 003E1B24 78B78327 */  addiu      $3, $28, -0x4888
    /* 2E1B28 003E1B28 2D808000 */  daddu      $16, $4, $0
    /* 2E1B2C 003E1B2C 01000224 */  addiu      $2, $0, 0x1
    /* 2E1B30 003E1B30 70B782AF */  sw         $2, -0x4890($28)
    /* 2E1B34 003E1B34 24000424 */  addiu      $4, $0, 0x24
    /* 2E1B38 003E1B38 78B783AF */  sw         $3, -0x4888($28)
    /* 2E1B3C 003E1B3C 2D30A000 */  daddu      $6, $5, $0
    /* 2E1B40 003E1B40 7CB783AF */  sw         $3, -0x4884($28)
    /* 2E1B44 003E1B44 2D380000 */  daddu      $7, $0, $0
    /* 2E1B48 003E1B48 F0710825 */  addiu      $8, $8, %lo(D_008871F0)
    /* 2E1B4C 003E1B4C 0C840F0C */  jal        func_003e1030
    /* 2E1B50 003E1B50 0400093C */   lui       $9, (0x40000 >> 16)
    /* 2E1B54 003E1B54 1B004010 */  beqz       $2, .L003E1BC4
    /* 2E1B58 003E1B58 74B782AF */   sw        $2, -0x488C($28)
    /* 2E1B5C 003E1B5C 1C00438C */  lw         $3, 0x1C($2)
    /* 2E1B60 003E1B60 01000424 */  addiu      $4, $0, 0x1
    /* 2E1B64 003E1B64 2000428C */  lw         $2, 0x20($2)
    /* 2E1B68 003E1B68 000043AC */  sw         $3, 0x0($2)
    /* 2E1B6C 003E1B6C 74B7828F */  lw         $2, -0x488C($28)
    /* 2E1B70 003E1B70 2000438C */  lw         $3, 0x20($2)
    /* 2E1B74 003E1B74 1C00428C */  lw         $2, 0x1C($2)
    /* 2E1B78 003E1B78 040043AC */  sw         $3, 0x4($2)
  .L003E1B7C:
    /* 2E1B7C 003E1B7C 14008010 */  beqz       $4, .L003E1BD0
    /* 2E1B80 003E1B80 00000000 */   nop
    /* 2E1B84 003E1B84 14000012 */  beqz       $16, .L003E1BD8
    /* 2E1B88 003E1B88 00000000 */   nop
    /* 2E1B8C 003E1B8C 000003C6 */  lwc1       $f3, 0x0($16)
    /* 2E1B90 003E1B90 8800053C */  lui        $5, %hi(jtbl_008873E8)
    /* 2E1B94 003E1B94 040002C6 */  lwc1       $f2, 0x4($16)
    /* 2E1B98 003E1B98 8800043C */  lui        $4, %hi(jtbl_008873EC)
    /* 2E1B9C 003E1B9C 080001C6 */  lwc1       $f1, 0x8($16)
    /* 2E1BA0 003E1BA0 8800033C */  lui        $3, %hi(D_008873F0)
    /* 2E1BA4 003E1BA4 0C0000C6 */  lwc1       $f0, 0xC($16)
    /* 2E1BA8 003E1BA8 8800023C */  lui        $2, %hi(D_008873F4)
    /* 2E1BAC 003E1BAC E873A3E4 */  swc1       $f3, %lo(jtbl_008873E8)($5)
    /* 2E1BB0 003E1BB0 EC7382E4 */  swc1       $f2, %lo(jtbl_008873EC)($4)
    /* 2E1BB4 003E1BB4 F07361E4 */  swc1       $f1, %lo(D_008873F0)($3)
    /* 2E1BB8 003E1BB8 F47340E4 */  swc1       $f0, %lo(D_008873F4)($2)
  .L003E1BBC:
    /* 2E1BBC 003E1BBC 17000010 */  b          .L003E1C1C
    /* 2E1BC0 003E1BC0 01000224 */   addiu     $2, $0, 0x1
  .L003E1BC4:
    /* 2E1BC4 003E1BC4 70B780AF */  sw         $0, -0x4890($28)
    /* 2E1BC8 003E1BC8 ECFF0010 */  b          .L003E1B7C
    /* 2E1BCC 003E1BCC 2D200000 */   daddu     $4, $0, $0
  .L003E1BD0:
    /* 2E1BD0 003E1BD0 12000010 */  b          .L003E1C1C
    /* 2E1BD4 003E1BD4 2D100000 */   daddu     $2, $0, $0
  .L003E1BD8:
    /* 2E1BD8 003E1BD8 3E00033C */  lui        $3, %hi(func_003e1ae0)
    /* 2E1BDC 003E1BDC 4400043C */  lui        $4, %hi(func_0043ed08)
    /* 2E1BE0 003E1BE0 E01A6324 */  addiu      $3, $3, %lo(func_003e1ae0)
    /* 2E1BE4 003E1BE4 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 2E1BE8 003E1BE8 E87343AC */  sw         $3, %lo(jtbl_008873E8)($2)
    /* 2E1BEC 003E1BEC 08ED8424 */  addiu      $4, $4, %lo(func_0043ed08)
    /* 2E1BF0 003E1BF0 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2E1BF4 003E1BF4 3E00033C */  lui        $3, %hi(func_003e1af0)
    /* 2E1BF8 003E1BF8 EC7344AC */  sw         $4, %lo(jtbl_008873EC)($2)
    /* 2E1BFC 003E1BFC F01A6324 */  addiu      $3, $3, %lo(func_003e1af0)
    /* 2E1C00 003E1C00 8800023C */  lui        $2, %hi(D_008873F0)
    /* 2E1C04 003E1C04 F07343AC */  sw         $3, %lo(D_008873F0)($2)
    /* 2E1C08 003E1C08 3E00033C */  lui        $3, %hi(func_003e1b00)
    /* 2E1C0C 003E1C0C 8800023C */  lui        $2, %hi(D_008873F4)
    /* 2E1C10 003E1C10 001B6324 */  addiu      $3, $3, %lo(func_003e1b00)
    /* 2E1C14 003E1C14 E9FF0010 */  b          .L003E1BBC
    /* 2E1C18 003E1C18 F47343AC */   sw        $3, %lo(D_008873F4)($2)
  .L003E1C1C:
    /* 2E1C1C 003E1C1C 1000BFDF */  ld         $31, 0x10($29)
    /* 2E1C20 003E1C20 0000B07B */  lq         $16, 0x0($29)
    /* 2E1C24 003E1C24 0800E003 */  jr         $31
    /* 2E1C28 003E1C28 2000BD27 */   addiu     $29, $29, 0x20
    /* 2E1C2C 003E1C2C 00000000 */  nop
.size func_003e1b10, 0x120
