.section .text
.set noat
.set noreorder
glabel func_0050ff20
    /* 40FF20 0050FF20 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 40FF24 0050FF24 0000B0FF */  sd         $16, 0x0($29)
    /* 40FF28 0050FF28 2D808000 */  daddu      $16, $4, $0
    /* 40FF2C 0050FF2C 0800B1FF */  sd         $17, 0x8($29)
    /* 40FF30 0050FF30 1000BFFF */  sd         $31, 0x10($29)
    /* 40FF34 0050FF34 0A35140C */  jal        func_0050d428
    /* 40FF38 0050FF38 2D88A000 */   daddu     $17, $5, $0
    /* 40FF3C 0050FF3C 7600043C */  lui        $4, %hi(D_0075FD70)
    /* 40FF40 0050FF40 01000324 */  addiu      $3, $0, 0x1
    /* 40FF44 0050FF44 06004310 */  beq        $2, $3, .L0050FF60
    /* 40FF48 0050FF48 70FD8424 */   addiu     $4, $4, %lo(D_0075FD70)
    /* 40FF4C 0050FF4C 0000B0DF */  ld         $16, 0x0($29)
    /* 40FF50 0050FF50 0800B1DF */  ld         $17, 0x8($29)
    /* 40FF54 0050FF54 1000BFDF */  ld         $31, 0x10($29)
    /* 40FF58 0050FF58 88441408 */  j          func_00511220
    /* 40FF5C 0050FF5C 2000BD27 */   addiu     $29, $29, 0x20
  .L0050FF60:
    /* 40FF60 0050FF60 09002016 */  bnez       $17, .L0050FF88
    /* 40FF64 0050FF64 2D282002 */   daddu     $5, $17, $0
    /* 40FF68 0050FF68 7600043C */  lui        $4, %hi(D_0075FDA0)
    /* 40FF6C 0050FF6C 0000B0DF */  ld         $16, 0x0($29)
    /* 40FF70 0050FF70 0800B1DF */  ld         $17, 0x8($29)
    /* 40FF74 0050FF74 A0FD8424 */  addiu      $4, $4, %lo(D_0075FDA0)
    /* 40FF78 0050FF78 1000BFDF */  ld         $31, 0x10($29)
    /* 40FF7C 0050FF7C 88441408 */  j          func_00511220
    /* 40FF80 0050FF80 2000BD27 */   addiu     $29, $29, 0x20
    /* 40FF84 0050FF84 00000000 */  nop
  .L0050FF88:
    /* 40FF88 0050FF88 9031140C */  jal        func_0050c640
    /* 40FF8C 0050FF8C 2D200002 */   daddu     $4, $16, $0
    /* 40FF90 0050FF90 BEA4130C */  jal        func_004e92f8
    /* 40FF94 0050FF94 4800048E */   lw        $4, 0x48($16)
    /* 40FF98 0050FF98 2D200002 */  daddu      $4, $16, $0
    /* 40FF9C 0050FF9C 583F140C */  jal        func_0050fd60
    /* 40FFA0 0050FFA0 A401058E */   lw        $5, 0x1A4($16)
    /* 40FFA4 0050FFA4 2D200002 */  daddu      $4, $16, $0
    /* 40FFA8 0050FFA8 B03F140C */  jal        func_0050fec0
    /* 40FFAC 0050FFAC 01000524 */   addiu     $5, $0, 0x1
    /* 40FFB0 0050FFB0 2D200002 */  daddu      $4, $16, $0
    /* 40FFB4 0050FFB4 0800B1DF */  ld         $17, 0x8($29)
    /* 40FFB8 0050FFB8 0000B0DF */  ld         $16, 0x0($29)
    /* 40FFBC 0050FFBC 1000BFDF */  ld         $31, 0x10($29)
    /* 40FFC0 0050FFC0 883F1408 */  j          func_0050fe20
    /* 40FFC4 0050FFC4 2000BD27 */   addiu     $29, $29, 0x20
.size func_0050ff20, 0xa8
