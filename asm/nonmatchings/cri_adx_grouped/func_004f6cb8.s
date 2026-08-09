.section .text
.set noat
.set noreorder
glabel func_004f6cb8
    /* 3F6CB8 004F6CB8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3F6CBC 004F6CBC 0000B0FF */  sd         $16, 0x0($29)
    /* 3F6CC0 004F6CC0 2D808000 */  daddu      $16, $4, $0
    /* 3F6CC4 004F6CC4 0C000426 */  addiu      $4, $16, 0xC
    /* 3F6CC8 004F6CC8 0800B1FF */  sd         $17, 0x8($29)
    /* 3F6CCC 004F6CCC 1000BFFF */  sd         $31, 0x10($29)
    /* 3F6CD0 004F6CD0 ACDA130C */  jal        func_004f6ab0
    /* 3F6CD4 004F6CD4 2D88A000 */   daddu     $17, $5, $0
    /* 3F6CD8 004F6CD8 1C004054 */  bnel       $2, $0, .L004F6D4C
    /* 3F6CDC 004F6CDC 0000B0DF */   ld        $16, 0x0($29)
    /* 3F6CE0 004F6CE0 6400228E */  lw         $2, 0x64($17)
    /* 3F6CE4 004F6CE4 00010626 */  addiu      $6, $16, 0x100
    /* 3F6CE8 004F6CE8 16004018 */  blez       $2, .L004F6D44
    /* 3F6CEC 004F6CEC 2D400000 */   daddu     $8, $0, $0
    /* 3F6CF0 004F6CF0 70002726 */  addiu      $7, $17, 0x70
    /* 3F6CF4 004F6CF4 00000000 */  nop
  .L004F6CF8:
    /* 3F6CF8 004F6CF8 0000C58C */  lw         $5, 0x0($6)
    /* 3F6CFC 004F6CFC 01000825 */  addiu      $8, $8, 0x1
    /* 3F6D00 004F6D00 0000C290 */  lbu        $2, 0x0($6)
    /* 3F6D04 004F6D04 0400C624 */  addiu      $6, $6, 0x4
    /* 3F6D08 004F6D08 031A0500 */  sra        $3, $5, 8
    /* 3F6D0C 004F6D0C 022E0500 */  srl        $5, $5, 24
    /* 3F6D10 004F6D10 2D206000 */  daddu      $4, $3, $0
    /* 3F6D14 004F6D14 FF006330 */  andi       $3, $3, 0xFF
    /* 3F6D18 004F6D18 00160200 */  sll        $2, $2, 24
    /* 3F6D1C 004F6D1C 00FF8430 */  andi       $4, $4, 0xFF00
    /* 3F6D20 004F6D20 001C0300 */  sll        $3, $3, 16
    /* 3F6D24 004F6D24 25104500 */  or         $2, $2, $5
    /* 3F6D28 004F6D28 25208300 */  or         $4, $4, $3
    /* 3F6D2C 004F6D2C 25104400 */  or         $2, $2, $4
    /* 3F6D30 004F6D30 0000E2AC */  sw         $2, 0x0($7)
    /* 3F6D34 004F6D34 6400228E */  lw         $2, 0x64($17)
    /* 3F6D38 004F6D38 2A100201 */  slt        $2, $8, $2
    /* 3F6D3C 004F6D3C EEFF4014 */  bnez       $2, .L004F6CF8
    /* 3F6D40 004F6D40 0400E724 */   addiu     $7, $7, 0x4
  .L004F6D44:
    /* 3F6D44 004F6D44 2D100000 */  daddu      $2, $0, $0
    /* 3F6D48 004F6D48 0000B0DF */  ld         $16, 0x0($29)
  .L004F6D4C:
    /* 3F6D4C 004F6D4C 0800B1DF */  ld         $17, 0x8($29)
    /* 3F6D50 004F6D50 1000BFDF */  ld         $31, 0x10($29)
    /* 3F6D54 004F6D54 0800E003 */  jr         $31
    /* 3F6D58 004F6D58 2000BD27 */   addiu     $29, $29, 0x20
    /* 3F6D5C 004F6D5C 00000000 */  nop
.size func_004f6cb8, 0xa8
