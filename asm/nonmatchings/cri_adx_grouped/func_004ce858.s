.section .text
.set noat
.set noreorder
glabel func_004ce858
    /* 3CE858 004CE858 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CE85C 004CE85C 0000B0FF */  sd         $16, 0x0($29)
    /* 3CE860 004CE860 2D808000 */  daddu      $16, $4, $0
    /* 3CE864 004CE864 0800BFFF */  sd         $31, 0x8($29)
    /* 3CE868 004CE868 A000028E */  lw         $2, 0xA0($16)
    /* 3CE86C 004CE86C 08004058 */  blezl      $2, .L004CE890
    /* 3CE870 004CE870 01000382 */   lb        $3, 0x1($16)
    /* 3CE874 004CE874 2A15130C */  jal        func_004c54a8
    /* 3CE878 004CE878 00000000 */   nop
    /* 3CE87C 004CE87C 403A130C */  jal        func_004ce900
    /* 3CE880 004CE880 2D200002 */   daddu     $4, $16, $0
    /* 3CE884 004CE884 3015130C */  jal        func_004c54c0
    /* 3CE888 004CE888 00000000 */   nop
    /* 3CE88C 004CE88C 01000382 */  lb         $3, 0x1($16)
  .L004CE890:
    /* 3CE890 004CE890 02000224 */  addiu      $2, $0, 0x2
    /* 3CE894 004CE894 06006254 */  bnel       $3, $2, .L004CE8B0
    /* 3CE898 004CE898 01000224 */   addiu     $2, $0, 0x1
    /* 3CE89C 004CE89C EA39130C */  jal        func_004ce7a8
    /* 3CE8A0 004CE8A0 2D200002 */   daddu     $4, $16, $0
    /* 3CE8A4 004CE8A4 07000010 */  b          .L004CE8C4
    /* 3CE8A8 004CE8A8 A400028E */   lw        $2, 0xA4($16)
    /* 3CE8AC 004CE8AC 00000000 */  nop
  .L004CE8B0:
    /* 3CE8B0 004CE8B0 04006254 */  bnel       $3, $2, .L004CE8C4
    /* 3CE8B4 004CE8B4 A400028E */   lw        $2, 0xA4($16)
    /* 3CE8B8 004CE8B8 7037130C */  jal        func_004cddc0
    /* 3CE8BC 004CE8BC 2D200002 */   daddu     $4, $16, $0
    /* 3CE8C0 004CE8C0 A400028E */  lw         $2, 0xA4($16)
  .L004CE8C4:
    /* 3CE8C4 004CE8C4 0A004058 */  blezl      $2, .L004CE8F0
    /* 3CE8C8 004CE8C8 0000B0DF */   ld        $16, 0x0($29)
    /* 3CE8CC 004CE8CC 2A15130C */  jal        func_004c54a8
    /* 3CE8D0 004CE8D0 00000000 */   nop
    /* 3CE8D4 004CE8D4 943A130C */  jal        func_004cea50
    /* 3CE8D8 004CE8D8 2D200002 */   daddu     $4, $16, $0
    /* 3CE8DC 004CE8DC 0000B0DF */  ld         $16, 0x0($29)
    /* 3CE8E0 004CE8E0 0800BFDF */  ld         $31, 0x8($29)
    /* 3CE8E4 004CE8E4 30151308 */  j          func_004c54c0
    /* 3CE8E8 004CE8E8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CE8EC 004CE8EC 00000000 */  nop
  .L004CE8F0:
    /* 3CE8F0 004CE8F0 0800BFDF */  ld         $31, 0x8($29)
    /* 3CE8F4 004CE8F4 0800E003 */  jr         $31
    /* 3CE8F8 004CE8F8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CE8FC 004CE8FC 00000000 */  nop
.size func_004ce858, 0xa8
