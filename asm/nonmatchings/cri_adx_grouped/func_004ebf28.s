.section .text
.set noat
.set noreorder
glabel func_004ebf28
    /* 3EBF28 004EBF28 7400023C */  lui        $2, %hi(D_0073A748)
    /* 3EBF2C 004EBF2C E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3EBF30 004EBF30 48A7438C */  lw         $3, %lo(D_0073A748)($2)
    /* 3EBF34 004EBF34 01000424 */  addiu      $4, $0, 0x1
    /* 3EBF38 004EBF38 1000B0FF */  sd         $16, 0x10($29)
    /* 3EBF3C 004EBF3C 05006414 */  bne        $3, $4, .L004EBF54
    /* 3EBF40 004EBF40 1800BFFF */   sd        $31, 0x18($29)
    /* 3EBF44 004EBF44 7400023C */  lui        $2, %hi(D_0073A740)
    /* 3EBF48 004EBF48 40A7438C */  lw         $3, %lo(D_0073A740)($2)
    /* 3EBF4C 004EBF4C 2A006018 */  blez       $3, .L004EBFF8
    /* 3EBF50 004EBF50 1000B0DF */   ld        $16, 0x10($29)
  .L004EBF54:
    /* 3EBF54 004EBF54 7600043C */  lui        $4, %hi(D_0075C988)
    /* 3EBF58 004EBF58 2D28A003 */  daddu      $5, $29, $0
    /* 3EBF5C 004EBF5C 4A85130C */  jal        func_004e1528
    /* 3EBF60 004EBF60 88C98424 */   addiu     $4, $4, %lo(D_0075C988)
    /* 3EBF64 004EBF64 7400033C */  lui        $3, %hi(D_0073A788)
    /* 3EBF68 004EBF68 0C000424 */  addiu      $4, $0, 0xC
    /* 3EBF6C 004EBF6C 0400A527 */  addiu      $5, $29, 0x4
    /* 3EBF70 004EBF70 01000624 */  addiu      $6, $0, 0x1
    /* 3EBF74 004EBF74 0800A727 */  addiu      $7, $29, 0x8
    /* 3EBF78 004EBF78 01000824 */  addiu      $8, $0, 0x1
    /* 3EBF7C 004EBF7C 04004014 */  bnez       $2, .L004EBF90
    /* 3EBF80 004EBF80 88A77024 */   addiu     $16, $3, %lo(D_0073A788)
    /* 3EBF84 004EBF84 03000010 */  b          .L004EBF94
    /* 3EBF88 004EBF88 0000A28F */   lw        $2, 0x0($29)
    /* 3EBF8C 004EBF8C 00000000 */  nop
  .L004EBF90:
    /* 3EBF90 004EBF90 80BB0234 */  ori        $2, $0, 0xBB80
  .L004EBF94:
    /* 3EBF94 004EBF94 2896130C */  jal        func_004e58a0
    /* 3EBF98 004EBF98 0400A2AF */   sw        $2, 0x4($29)
    /* 3EBF9C 004EBF9C 7400043C */  lui        $4, %hi(D_0073A780)
    /* 3EBFA0 004EBFA0 04000324 */  addiu      $3, $0, 0x4
    /* 3EBFA4 004EBFA4 80A78424 */  addiu      $4, $4, %lo(D_0073A780)
    /* 3EBFA8 004EBFA8 0B180200 */  movn       $3, $0, $2
    /* 3EBFAC 004EBFAC 80280200 */  sll        $5, $2, 2
    /* 3EBFB0 004EBFB0 21486400 */  addu       $9, $3, $4
    /* 3EBFB4 004EBFB4 7400033C */  lui        $3, %hi(D_0073A774)
    /* 3EBFB8 004EBFB8 2130A400 */  addu       $6, $5, $4
    /* 3EBFBC 004EBFBC 02000524 */  addiu      $5, $0, 0x2
    /* 3EBFC0 004EBFC0 2D408000 */  daddu      $8, $4, $0
    /* 3EBFC4 004EBFC4 7400043C */  lui        $4, %hi(D_0073A778)
    /* 3EBFC8 004EBFC8 01000724 */  addiu      $7, $0, 0x1
    /* 3EBFCC 004EBFCC 000002AE */  sw         $2, 0x0($16)
    /* 3EBFD0 004EBFD0 74A760AC */  sw         $0, %lo(D_0073A774)($3)
    /* 3EBFD4 004EBFD4 04004514 */  bne        $2, $5, .L004EBFE8
    /* 3EBFD8 004EBFD8 78A780AC */   sw        $0, %lo(D_0073A778)($4)
    /* 3EBFDC 004EBFDC 040007AD */  sw         $7, 0x4($8)
    /* 3EBFE0 004EBFE0 04000010 */  b          .L004EBFF4
    /* 3EBFE4 004EBFE4 000007AD */   sw        $7, 0x0($8)
  .L004EBFE8:
    /* 3EBFE8 004EBFE8 01000224 */  addiu      $2, $0, 0x1
    /* 3EBFEC 004EBFEC 0000C2AC */  sw         $2, 0x0($6)
    /* 3EBFF0 004EBFF0 000020AD */  sw         $0, 0x0($9)
  .L004EBFF4:
    /* 3EBFF4 004EBFF4 1000B0DF */  ld         $16, 0x10($29)
  .L004EBFF8:
    /* 3EBFF8 004EBFF8 1800BFDF */  ld         $31, 0x18($29)
    /* 3EBFFC 004EBFFC 0800E003 */  jr         $31
    /* 3EC000 004EC000 2000BD27 */   addiu     $29, $29, 0x20
    /* 3EC004 004EC004 00000000 */  nop
.size func_004ebf28, 0xe0
