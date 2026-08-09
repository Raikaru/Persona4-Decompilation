.section .text
.set noat
.set noreorder
glabel func_004ca990
    /* 3CA990 004CA990 90FFBD27 */  addiu      $29, $29, -0x70
    /* 3CA994 004CA994 3000B0FF */  sd         $16, 0x30($29)
    /* 3CA998 004CA998 7200103C */  lui        $16, %hi(D_00719940)
    /* 3CA99C 004CA99C 3800B1FF */  sd         $17, 0x38($29)
    /* 3CA9A0 004CA9A0 2D888000 */  daddu      $17, $4, $0
    /* 3CA9A4 004CA9A4 4000B2FF */  sd         $18, 0x40($29)
    /* 3CA9A8 004CA9A8 2D90A000 */  daddu      $18, $5, $0
    /* 3CA9AC 004CA9AC 4800B3FF */  sd         $19, 0x48($29)
    /* 3CA9B0 004CA9B0 2D98C000 */  daddu      $19, $6, $0
    /* 3CA9B4 004CA9B4 5000B4FF */  sd         $20, 0x50($29)
    /* 3CA9B8 004CA9B8 2DA0E000 */  daddu      $20, $7, $0
    /* 3CA9BC 004CA9BC 5800B5FF */  sd         $21, 0x58($29)
    /* 3CA9C0 004CA9C0 6000BFFF */  sd         $31, 0x60($29)
    /* 3CA9C4 004CA9C4 7A43130C */  jal        func_004d0de8
    /* 3CA9C8 004CA9C8 40991026 */   addiu     $16, $16, %lo(D_00719940)
    /* 3CA9CC 004CA9CC 7200043C */  lui        $4, %hi(D_00719540)
    /* 3CA9D0 004CA9D0 2D300000 */  daddu      $6, $0, $0
    /* 3CA9D4 004CA9D4 40958424 */  addiu      $4, $4, %lo(D_00719540)
    /* 3CA9D8 004CA9D8 06B8130C */  jal        func_004ee018
    /* 3CA9DC 004CA9DC 00040524 */   addiu     $5, $0, 0x400
    /* 3CA9E0 004CA9E0 20000524 */  addiu      $5, $0, 0x20
    /* 3CA9E4 004CA9E4 2D200002 */  daddu      $4, $16, $0
    /* 3CA9E8 004CA9E8 80B5130C */  jal        func_004ed600
    /* 3CA9EC 004CA9EC 2DA84000 */   daddu     $21, $2, $0
    /* 3CA9F0 004CA9F0 20000426 */  addiu      $4, $16, 0x20
    /* 3CA9F4 004CA9F4 20000524 */  addiu      $5, $0, 0x20
    /* 3CA9F8 004CA9F8 80B5130C */  jal        func_004ed600
    /* 3CA9FC 004CA9FC 0000A2AF */   sw        $2, 0x0($29)
    /* 3CAA00 004CAA00 1400308E */  lw         $16, 0x14($17)
    /* 3CAA04 004CAA04 2D28A003 */  daddu      $5, $29, $0
    /* 3CAA08 004CAA08 02000424 */  addiu      $4, $0, 0x2
    /* 3CAA0C 004CAA0C 2D30A002 */  daddu      $6, $21, $0
    /* 3CAA10 004CAA10 A643130C */  jal        func_004d0e98
    /* 3CAA14 004CAA14 0400A2AF */   sw        $2, 0x4($29)
    /* 3CAA18 004CAA18 2D284002 */  daddu      $5, $18, $0
    /* 3CAA1C 004CAA1C 2D884000 */  daddu      $17, $2, $0
    /* 3CAA20 004CAA20 2D306002 */  daddu      $6, $19, $0
    /* 3CAA24 004CAA24 2D388002 */  daddu      $7, $20, $0
    /* 3CAA28 004CAA28 3245130C */  jal        func_004d14c8
    /* 3CAA2C 004CAA2C 2D202002 */   daddu     $4, $17, $0
    /* 3CAA30 004CAA30 3644130C */  jal        func_004d10d8
    /* 3CAA34 004CAA34 2D202002 */   daddu     $4, $17, $0
    /* 3CAA38 004CAA38 0846130C */  jal        func_004d1820
    /* 3CAA3C 004CAA3C 00000000 */   nop
    /* 3CAA40 004CAA40 0000A38E */  lw         $3, 0x0($21)
    /* 3CAA44 004CAA44 1000B327 */  addiu      $19, $29, 0x10
    /* 3CAA48 004CAA48 00040624 */  addiu      $6, $0, 0x400
    /* 3CAA4C 004CAA4C 2D20A002 */  daddu      $4, $21, $0
    /* 3CAA50 004CAA50 1800628C */  lw         $2, 0x18($3)
    /* 3CAA54 004CAA54 01000524 */  addiu      $5, $0, 0x1
    /* 3CAA58 004CAA58 09F84000 */  jalr       $2
    /* 3CAA5C 004CAA5C 2D386002 */   daddu     $7, $19, $0
    /* 3CAA60 004CAA60 1400A68F */  lw         $6, 0x14($29)
    /* 3CAA64 004CAA64 0A00C054 */  bnel       $6, $0, .L004CAA90
    /* 3CAA68 004CAA68 0000028E */   lw        $2, 0x0($16)
    /* 3CAA6C 004CAA6C 00000000 */  nop
  .L004CAA70:
    /* 3CAA70 004CAA70 00000000 */  nop
    /* 3CAA74 004CAA74 00000000 */  nop
    /* 3CAA78 004CAA78 00000000 */  nop
    /* 3CAA7C 004CAA7C 00000000 */  nop
    /* 3CAA80 004CAA80 00000000 */  nop
    /* 3CAA84 004CAA84 FAFF0010 */  b          .L004CAA70
    /* 3CAA88 004CAA88 00000000 */   nop
    /* 3CAA8C 004CAA8C 00000000 */  nop
  .L004CAA90:
    /* 3CAA90 004CAA90 2000B227 */  addiu      $18, $29, 0x20
    /* 3CAA94 004CAA94 2D200002 */  daddu      $4, $16, $0
    /* 3CAA98 004CAA98 2D280000 */  daddu      $5, $0, $0
    /* 3CAA9C 004CAA9C 1800438C */  lw         $3, 0x18($2)
    /* 3CAAA0 004CAAA0 09F86000 */  jalr       $3
    /* 3CAAA4 004CAAA4 2D384002 */   daddu     $7, $18, $0
    /* 3CAAA8 004CAAA8 2400A28F */  lw         $2, 0x24($29)
    /* 3CAAAC 004CAAAC 1400A68F */  lw         $6, 0x14($29)
    /* 3CAAB0 004CAAB0 2A104600 */  slt        $2, $2, $6
    /* 3CAAB4 004CAAB4 0A004010 */  beqz       $2, .L004CAAE0
    /* 3CAAB8 004CAAB8 2000A48F */   lw        $4, 0x20($29)
    /* 3CAABC 004CAABC 00000000 */  nop
  .L004CAAC0:
    /* 3CAAC0 004CAAC0 00000000 */  nop
    /* 3CAAC4 004CAAC4 00000000 */  nop
    /* 3CAAC8 004CAAC8 00000000 */  nop
    /* 3CAACC 004CAACC 00000000 */  nop
    /* 3CAAD0 004CAAD0 00000000 */  nop
    /* 3CAAD4 004CAAD4 FAFF0010 */  b          .L004CAAC0
    /* 3CAAD8 004CAAD8 00000000 */   nop
    /* 3CAADC 004CAADC 00000000 */  nop
  .L004CAAE0:
    /* 3CAAE0 004CAAE0 04FE100C */  jal        func_0043f810
    /* 3CAAE4 004CAAE4 1000A58F */   lw        $5, 0x10($29)
    /* 3CAAE8 004CAAE8 0000A38E */  lw         $3, 0x0($21)
    /* 3CAAEC 004CAAEC 2D306002 */  daddu      $6, $19, $0
    /* 3CAAF0 004CAAF0 2D20A002 */  daddu      $4, $21, $0
    /* 3CAAF4 004CAAF4 2000628C */  lw         $2, 0x20($3)
    /* 3CAAF8 004CAAF8 09F84000 */  jalr       $2
    /* 3CAAFC 004CAAFC 2D280000 */   daddu     $5, $0, $0
    /* 3CAB00 004CAB00 0000038E */  lw         $3, 0x0($16)
    /* 3CAB04 004CAB04 2D304002 */  daddu      $6, $18, $0
    /* 3CAB08 004CAB08 01000524 */  addiu      $5, $0, 0x1
    /* 3CAB0C 004CAB0C 2000628C */  lw         $2, 0x20($3)
    /* 3CAB10 004CAB10 09F84000 */  jalr       $2
    /* 3CAB14 004CAB14 2D200002 */   daddu     $4, $16, $0
    /* 3CAB18 004CAB18 8044130C */  jal        func_004d1200
    /* 3CAB1C 004CAB1C 2D202002 */   daddu     $4, $17, $0
    /* 3CAB20 004CAB20 1A44130C */  jal        func_004d1068
    /* 3CAB24 004CAB24 2D202002 */   daddu     $4, $17, $0
    /* 3CAB28 004CAB28 0000A38E */  lw         $3, 0x0($21)
    /* 3CAB2C 004CAB2C 0C00628C */  lw         $2, 0xC($3)
    /* 3CAB30 004CAB30 09F84000 */  jalr       $2
    /* 3CAB34 004CAB34 2D20A002 */   daddu     $4, $21, $0
    /* 3CAB38 004CAB38 0400A48F */  lw         $4, 0x4($29)
    /* 3CAB3C 004CAB3C 0000838C */  lw         $3, 0x0($4)
    /* 3CAB40 004CAB40 0C00628C */  lw         $2, 0xC($3)
    /* 3CAB44 004CAB44 09F84000 */  jalr       $2
    /* 3CAB48 004CAB48 00000000 */   nop
    /* 3CAB4C 004CAB4C 0000A48F */  lw         $4, 0x0($29)
    /* 3CAB50 004CAB50 0000838C */  lw         $3, 0x0($4)
    /* 3CAB54 004CAB54 0C00628C */  lw         $2, 0xC($3)
    /* 3CAB58 004CAB58 09F84000 */  jalr       $2
    /* 3CAB5C 004CAB5C 00000000 */   nop
    /* 3CAB60 004CAB60 9043130C */  jal        func_004d0e40
    /* 3CAB64 004CAB64 00000000 */   nop
    /* 3CAB68 004CAB68 3000B0DF */  ld         $16, 0x30($29)
    /* 3CAB6C 004CAB6C 3800B1DF */  ld         $17, 0x38($29)
    /* 3CAB70 004CAB70 4000B2DF */  ld         $18, 0x40($29)
    /* 3CAB74 004CAB74 4800B3DF */  ld         $19, 0x48($29)
    /* 3CAB78 004CAB78 5000B4DF */  ld         $20, 0x50($29)
    /* 3CAB7C 004CAB7C 5800B5DF */  ld         $21, 0x58($29)
    /* 3CAB80 004CAB80 6000BFDF */  ld         $31, 0x60($29)
    /* 3CAB84 004CAB84 0800E003 */  jr         $31
    /* 3CAB88 004CAB88 7000BD27 */   addiu     $29, $29, 0x70
    /* 3CAB8C 004CAB8C 00000000 */  nop
.size func_004ca990, 0x200
