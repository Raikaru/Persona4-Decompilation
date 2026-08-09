.section .text
.set noat
.set noreorder
glabel func_0051abd8
    /* 41ABD8 0051ABD8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 41ABDC 0051ABDC 0000B0FF */  sd         $16, 0x0($29)
    /* 41ABE0 0051ABE0 2D808000 */  daddu      $16, $4, $0
    /* 41ABE4 0051ABE4 0800B1FF */  sd         $17, 0x8($29)
    /* 41ABE8 0051ABE8 1000BFFF */  sd         $31, 0x10($29)
    /* 41ABEC 0051ABEC 7A7D140C */  jal        func_0051f5e8
    /* 41ABF0 0051ABF0 2D88A000 */   daddu     $17, $5, $0
    /* 41ABF4 0051ABF4 0E004010 */  beqz       $2, .L0051AC30
    /* 41ABF8 0051ABF8 2D100000 */   daddu     $2, $0, $0
    /* 41ABFC 0051ABFC 0C002012 */  beqz       $17, .L0051AC30
    /* 41AC00 0051AC00 01000224 */   addiu     $2, $0, 0x1
    /* 41AC04 0051AC04 5800038E */  lw         $3, 0x58($16)
    /* 41AC08 0051AC08 09006254 */  bnel       $3, $2, .L0051AC30
    /* 41AC0C 0051AC0C 2D100000 */   daddu     $2, $0, $0
    /* 41AC10 0051AC10 07002356 */  bnel       $17, $3, .L0051AC30
    /* 41AC14 0051AC14 2D100000 */   daddu     $2, $0, $0
    /* 41AC18 0051AC18 6C09038E */  lw         $3, 0x96C($16)
    /* 41AC1C 0051AC1C 6809048E */  lw         $4, 0x968($16)
    /* 41AC20 0051AC20 2A186400 */  slt        $3, $3, $4
    /* 41AC24 0051AC24 03006014 */  bnez       $3, .L0051AC34
    /* 41AC28 0051AC28 0000B0DF */   ld        $16, 0x0($29)
    /* 41AC2C 0051AC2C 2D100000 */  daddu      $2, $0, $0
  .L0051AC30:
    /* 41AC30 0051AC30 0000B0DF */  ld         $16, 0x0($29)
  .L0051AC34:
    /* 41AC34 0051AC34 0800B1DF */  ld         $17, 0x8($29)
    /* 41AC38 0051AC38 1000BFDF */  ld         $31, 0x10($29)
    /* 41AC3C 0051AC3C 0800E003 */  jr         $31
    /* 41AC40 0051AC40 2000BD27 */   addiu     $29, $29, 0x20
    /* 41AC44 0051AC44 00000000 */  nop
.size func_0051abd8, 0x70
