.section .text
.set noat
.set noreorder
glabel func_0042bb40
    /* 32BB40 0042BB40 0000828C */  lw         $2, 0x0($4)
    /* 32BB44 0042BB44 0B004610 */  beq        $2, $6, .L0042BB74
    /* 32BB48 0042BB48 2B108500 */   sltu      $2, $4, $5
    /* 32BB4C 0042BB4C 0A004050 */  beql       $2, $0, .L0042BB78
    /* 32BB50 0042BB50 0A200200 */   movz      $4, $0, $2
    /* 32BB54 0042BB54 04008424 */  addiu      $4, $4, 0x4
  .L0042BB58:
    /* 32BB58 0042BB58 0000828C */  lw         $2, 0x0($4)
    /* 32BB5C 0042BB5C 05004610 */  beq        $2, $6, .L0042BB74
    /* 32BB60 0042BB60 2B108500 */   sltu      $2, $4, $5
    /* 32BB64 0042BB64 FCFF4054 */  bnel       $2, $0, .L0042BB58
    /* 32BB68 0042BB68 04008424 */   addiu     $4, $4, 0x4
    /* 32BB6C 0042BB6C 02000010 */  b          .L0042BB78
    /* 32BB70 0042BB70 0A200200 */   movz      $4, $0, $2
  .L0042BB74:
    /* 32BB74 0042BB74 0A200200 */  movz       $4, $0, $2
  .L0042BB78:
    /* 32BB78 0042BB78 0800E003 */  jr         $31
    /* 32BB7C 0042BB7C 2D108000 */   daddu     $2, $4, $0
.size func_0042bb40, 0x40
