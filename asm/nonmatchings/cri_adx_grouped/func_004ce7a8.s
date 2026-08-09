.section .text
.set noat
.set noreorder
glabel func_004ce7a8
    /* 3CE7A8 004CE7A8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3CE7AC 004CE7AC 0800B1FF */  sd         $17, 0x8($29)
    /* 3CE7B0 004CE7B0 2D888000 */  daddu      $17, $4, $0
    /* 3CE7B4 004CE7B4 0000B0FF */  sd         $16, 0x0($29)
    /* 3CE7B8 004CE7B8 1000BFFF */  sd         $31, 0x10($29)
    /* 3CE7BC 004CE7BC 0400308E */  lw         $16, 0x4($17)
    /* 3CE7C0 004CE7C0 D40F130C */  jal        func_004c3f50
    /* 3CE7C4 004CE7C4 2D200002 */   daddu     $4, $16, $0
    /* 3CE7C8 004CE7C8 03004014 */  bnez       $2, .L004CE7D8
    /* 3CE7CC 004CE7CC 00000000 */   nop
    /* 3CE7D0 004CE7D0 7A38130C */  jal        func_004ce1e8
    /* 3CE7D4 004CE7D4 2D202002 */   daddu     $4, $17, $0
  .L004CE7D8:
    /* 3CE7D8 004CE7D8 9011130C */  jal        func_004c4640
    /* 3CE7DC 004CE7DC 2D200002 */   daddu     $4, $16, $0
    /* 3CE7E0 004CE7E0 D40F130C */  jal        func_004c3f50
    /* 3CE7E4 004CE7E4 2D200002 */   daddu     $4, $16, $0
    /* 3CE7E8 004CE7E8 03000324 */  addiu      $3, $0, 0x3
    /* 3CE7EC 004CE7EC 04004354 */  bnel       $2, $3, .L004CE800
    /* 3CE7F0 004CE7F0 98000486 */   lh        $4, 0x98($16)
    /* 3CE7F4 004CE7F4 5439130C */  jal        func_004ce550
    /* 3CE7F8 004CE7F8 2D202002 */   daddu     $4, $17, $0
    /* 3CE7FC 004CE7FC 98000486 */  lh         $4, 0x98($16)
  .L004CE800:
    /* 3CE800 004CE800 0A000224 */  addiu      $2, $0, 0xA
    /* 3CE804 004CE804 09008210 */  beq        $4, $2, .L004CE82C
    /* 3CE808 004CE808 14000224 */   addiu     $2, $0, 0x14
    /* 3CE80C 004CE80C 07008210 */  beq        $4, $2, .L004CE82C
    /* 3CE810 004CE810 0B000224 */   addiu     $2, $0, 0xB
    /* 3CE814 004CE814 05008210 */  beq        $4, $2, .L004CE82C
    /* 3CE818 004CE818 0C000224 */   addiu     $2, $0, 0xC
    /* 3CE81C 004CE81C 03008210 */  beq        $4, $2, .L004CE82C
    /* 3CE820 004CE820 0F000224 */   addiu     $2, $0, 0xF
    /* 3CE824 004CE824 08008214 */  bne        $4, $2, .L004CE848
    /* 3CE828 004CE828 0000B0DF */   ld        $16, 0x0($29)
  .L004CE82C:
    /* 3CE82C 004CE82C 2D202002 */  daddu      $4, $17, $0
    /* 3CE830 004CE830 0800B1DF */  ld         $17, 0x8($29)
    /* 3CE834 004CE834 0000B0DF */  ld         $16, 0x0($29)
    /* 3CE838 004CE838 1000BFDF */  ld         $31, 0x10($29)
    /* 3CE83C 004CE83C C6391308 */  j          func_004ce718
    /* 3CE840 004CE840 2000BD27 */   addiu     $29, $29, 0x20
    /* 3CE844 004CE844 00000000 */  nop
  .L004CE848:
    /* 3CE848 004CE848 0800B1DF */  ld         $17, 0x8($29)
    /* 3CE84C 004CE84C 1000BFDF */  ld         $31, 0x10($29)
    /* 3CE850 004CE850 0800E003 */  jr         $31
    /* 3CE854 004CE854 2000BD27 */   addiu     $29, $29, 0x20
.size func_004ce7a8, 0xb0
