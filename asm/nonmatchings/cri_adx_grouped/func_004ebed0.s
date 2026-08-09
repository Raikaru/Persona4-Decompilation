.section .text
.set noat
.set noreorder
glabel func_004ebed0
    /* 3EBED0 004EBED0 7400023C */  lui        $2, %hi(D_0073A748)
    /* 3EBED4 004EBED4 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3EBED8 004EBED8 48A7438C */  lw         $3, %lo(D_0073A748)($2)
    /* 3EBEDC 004EBEDC 01000524 */  addiu      $5, $0, 0x1
    /* 3EBEE0 004EBEE0 2D488000 */  daddu      $9, $4, $0
    /* 3EBEE4 004EBEE4 0B000424 */  addiu      $4, $0, 0xB
    /* 3EBEE8 004EBEE8 05006514 */  bne        $3, $5, .L004EBF00
    /* 3EBEEC 004EBEEC 1000BFFF */   sd        $31, 0x10($29)
    /* 3EBEF0 004EBEF0 7400023C */  lui        $2, %hi(D_0073A740)
    /* 3EBEF4 004EBEF4 40A7438C */  lw         $3, %lo(D_0073A740)($2)
    /* 3EBEF8 004EBEF8 08006058 */  blezl      $3, .L004EBF1C
    /* 3EBEFC 004EBEFC 1000BFDF */   ld        $31, 0x10($29)
  .L004EBF00:
    /* 3EBF00 004EBF00 2D28A003 */  daddu      $5, $29, $0
    /* 3EBF04 004EBF04 01000624 */  addiu      $6, $0, 0x1
    /* 3EBF08 004EBF08 2D380000 */  daddu      $7, $0, $0
    /* 3EBF0C 004EBF0C 2D400000 */  daddu      $8, $0, $0
    /* 3EBF10 004EBF10 2896130C */  jal        func_004e58a0
    /* 3EBF14 004EBF14 0000A9AF */   sw        $9, 0x0($29)
    /* 3EBF18 004EBF18 1000BFDF */  ld         $31, 0x10($29)
  .L004EBF1C:
    /* 3EBF1C 004EBF1C 0800E003 */  jr         $31
    /* 3EBF20 004EBF20 2000BD27 */   addiu     $29, $29, 0x20
    /* 3EBF24 004EBF24 00000000 */  nop
.size func_004ebed0, 0x58
