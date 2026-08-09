.section .text
.set noat
.set noreorder
glabel func_004cefb8
    /* 3CEFB8 004CEFB8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CEFBC 004CEFBC 0000B0FF */  sd         $16, 0x0($29)
    /* 3CEFC0 004CEFC0 2D808000 */  daddu      $16, $4, $0
    /* 3CEFC4 004CEFC4 0800BFFF */  sd         $31, 0x8($29)
    /* 3CEFC8 004CEFC8 320F130C */  jal        func_004c3cc8
    /* 3CEFCC 004CEFCC 0400048E */   lw        $4, 0x4($16)
    /* 3CEFD0 004CEFD0 0B004058 */  blezl      $2, .L004CF000
    /* 3CEFD4 004CEFD4 0000B0DF */   ld        $16, 0x0($29)
    /* 3CEFD8 004CEFD8 01000292 */  lbu        $2, 0x1($16)
    /* 3CEFDC 004CEFDC FEFF4224 */  addiu      $2, $2, -0x2
    /* 3CEFE0 004CEFE0 0200422C */  sltiu      $2, $2, 0x2
    /* 3CEFE4 004CEFE4 06004050 */  beql       $2, $0, .L004CF000
    /* 3CEFE8 004CEFE8 0000B0DF */   ld        $16, 0x0($29)
    /* 3CEFEC 004CEFEC 0400048E */  lw         $4, 0x4($16)
    /* 3CEFF0 004CEFF0 0800BFDF */  ld         $31, 0x8($29)
    /* 3CEFF4 004CEFF4 0000B0DF */  ld         $16, 0x0($29)
    /* 3CEFF8 004CEFF8 3A0F1308 */  j          func_004c3ce8
    /* 3CEFFC 004CEFFC 1000BD27 */   addiu     $29, $29, 0x10
  .L004CF000:
    /* 3CF000 004CF000 2D100000 */  daddu      $2, $0, $0
    /* 3CF004 004CF004 0800BFDF */  ld         $31, 0x8($29)
    /* 3CF008 004CF008 0800E003 */  jr         $31
    /* 3CF00C 004CF00C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cefb8, 0x58
