.section .text
.set noat
.set noreorder
glabel func_004eebd0
    /* 3EEBD0 004EEBD0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EEBD4 004EEBD4 7400033C */  lui        $3, %hi(D_00742020)
    /* 3EEBD8 004EEBD8 0000BFFF */  sd         $31, 0x0($29)
    /* 3EEBDC 004EEBDC 20206324 */  addiu      $3, $3, %lo(D_00742020)
    /* 3EEBE0 004EEBE0 0000628C */  lw         $2, 0x0($3)
    /* 3EEBE4 004EEBE4 FFFF4224 */  addiu      $2, $2, -0x1
    /* 3EEBE8 004EEBE8 09004014 */  bnez       $2, .L004EEC10
    /* 3EEBEC 004EEBEC 000062AC */   sw        $2, 0x0($3)
    /* 3EEBF0 004EEBF0 7400043C */  lui        $4, %hi(D_00742028)
    /* 3EEBF4 004EEBF4 0000BFDF */  ld         $31, 0x0($29)
    /* 3EEBF8 004EEBF8 2D280000 */  daddu      $5, $0, $0
    /* 3EEBFC 004EEBFC 28208424 */  addiu      $4, $4, %lo(D_00742028)
    /* 3EEC00 004EEC00 000C0624 */  addiu      $6, $0, 0xC00
    /* 3EEC04 004EEC04 72FE1008 */  j          func_0043f9c8
    /* 3EEC08 004EEC08 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EEC0C 004EEC0C 00000000 */  nop
  .L004EEC10:
    /* 3EEC10 004EEC10 0000BFDF */  ld         $31, 0x0($29)
    /* 3EEC14 004EEC14 0800E003 */  jr         $31
    /* 3EEC18 004EEC18 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EEC1C 004EEC1C 00000000 */  nop
.size func_004eebd0, 0x50
