.section .text
.set noat
.set noreorder
glabel func_004ee070
    /* 3EE070 004EE070 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EE074 004EE074 7400073C */  lui        $7, %hi(D_0073DFF0)
    /* 3EE078 004EE078 F0DFE224 */  addiu      $2, $7, %lo(D_0073DFF0)
    /* 3EE07C 004EE07C 0000B0FF */  sd         $16, 0x0($29)
    /* 3EE080 004EE080 0800BFFF */  sd         $31, 0x8($29)
    /* 3EE084 004EE084 04004324 */  addiu      $3, $2, 0x4
    /* 3EE088 004EE088 2D508000 */  daddu      $10, $4, $0
    /* 3EE08C 004EE08C 2D200000 */  daddu      $4, $0, $0
    /* 3EE090 004EE090 0000628C */  lw         $2, 0x0($3)
    /* 3EE094 004EE094 2D48A000 */  daddu      $9, $5, $0
    /* 3EE098 004EE098 0C004010 */  beqz       $2, .L004EE0CC
    /* 3EE09C 004EE09C 2D40C000 */   daddu     $8, $6, $0
    /* 3EE0A0 004EE0A0 01008424 */  addiu      $4, $4, 0x1
    /* 3EE0A4 004EE0A4 00000000 */  nop
  .L004EE0A8:
    /* 3EE0A8 004EE0A8 00018228 */  slti       $2, $4, 0x100
    /* 3EE0AC 004EE0AC 07004010 */  beqz       $2, .L004EE0CC
    /* 3EE0B0 004EE0B0 40006324 */   addiu     $3, $3, 0x40
    /* 3EE0B4 004EE0B4 0000628C */  lw         $2, 0x0($3)
    /* 3EE0B8 004EE0B8 00000000 */  nop
    /* 3EE0BC 004EE0BC 00000000 */  nop
    /* 3EE0C0 004EE0C0 00000000 */  nop
    /* 3EE0C4 004EE0C4 F8FF4054 */  bnel       $2, $0, .L004EE0A8
    /* 3EE0C8 004EE0C8 01008424 */   addiu     $4, $4, 0x1
  .L004EE0CC:
    /* 3EE0CC 004EE0CC 00010224 */  addiu      $2, $0, 0x100
    /* 3EE0D0 004EE0D0 15008210 */  beq        $4, $2, .L004EE128
    /* 3EE0D4 004EE0D4 2D800000 */   daddu     $16, $0, $0
    /* 3EE0D8 004EE0D8 80210400 */  sll        $4, $4, 6
    /* 3EE0DC 004EE0DC F0DFE224 */  addiu      $2, $7, %lo(D_0073DFF0)
    /* 3EE0E0 004EE0E0 7400033C */  lui        $3, %hi(D_0073DFB8)
    /* 3EE0E4 004EE0E4 7600053C */  lui        $5, %hi(D_0075CD70)
    /* 3EE0E8 004EE0E8 4F00063C */  lui        $6, %hi(func_004edeb0)
    /* 3EE0EC 004EE0EC 21808200 */  addu       $16, $4, $2
    /* 3EE0F0 004EE0F0 B8DF6324 */  addiu      $3, $3, %lo(D_0073DFB8)
    /* 3EE0F4 004EE0F4 70CDA524 */  addiu      $5, $5, %lo(D_0075CD70)
    /* 3EE0F8 004EE0F8 B0DEC624 */  addiu      $6, $6, %lo(func_004edeb0)
    /* 3EE0FC 004EE0FC 01000224 */  addiu      $2, $0, 0x1
    /* 3EE100 004EE100 040002AE */  sw         $2, 0x4($16)
    /* 3EE104 004EE104 2D200002 */  daddu      $4, $16, $0
    /* 3EE108 004EE108 000003AE */  sw         $3, 0x0($16)
    /* 3EE10C 004EE10C 1C000AAE */  sw         $10, 0x1C($16)
    /* 3EE110 004EE110 200009AE */  sw         $9, 0x20($16)
    /* 3EE114 004EE114 240008AE */  sw         $8, 0x24($16)
    /* 3EE118 004EE118 080005AE */  sw         $5, 0x8($16)
    /* 3EE11C 004EE11C 380006AE */  sw         $6, 0x38($16)
    /* 3EE120 004EE120 90B8130C */  jal        func_004ee240
    /* 3EE124 004EE124 3C0010AE */   sw        $16, 0x3C($16)
  .L004EE128:
    /* 3EE128 004EE128 2D100002 */  daddu      $2, $16, $0
    /* 3EE12C 004EE12C 0000B0DF */  ld         $16, 0x0($29)
    /* 3EE130 004EE130 0800BFDF */  ld         $31, 0x8($29)
    /* 3EE134 004EE134 0800E003 */  jr         $31
    /* 3EE138 004EE138 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EE13C 004EE13C 00000000 */  nop
.size func_004ee070, 0xd0
