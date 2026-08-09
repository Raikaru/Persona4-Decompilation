.section .text
.set noat
.set noreorder
glabel func_004c9c20
    /* 3C9C20 004C9C20 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C9C24 004C9C24 02000324 */  addiu      $3, $0, 0x2
    /* 3C9C28 004C9C28 0000BFFF */  sd         $31, 0x0($29)
    /* 3C9C2C 004C9C2C 01008280 */  lb         $2, 0x1($4)
    /* 3C9C30 004C9C30 05004314 */  bne        $2, $3, .L004C9C48
    /* 3C9C34 004C9C34 0000BFDF */   ld        $31, 0x0($29)
    /* 3C9C38 004C9C38 7600043C */  lui        $4, %hi(D_007585A0)
    /* 3C9C3C 004C9C3C A0858424 */  addiu      $4, $4, %lo(D_007585A0)
    /* 3C9C40 004C9C40 A61A1308 */  j          func_004c6a98
    /* 3C9C44 004C9C44 1000BD27 */   addiu     $29, $29, 0x10
  .L004C9C48:
    /* 3C9C48 004C9C48 2C0085AC */  sw         $5, 0x2C($4)
    /* 3C9C4C 004C9C4C 0800E003 */  jr         $31
    /* 3C9C50 004C9C50 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C9C54 004C9C54 00000000 */  nop
.size func_004c9c20, 0x38
