.section .text
.set noat
.set noreorder
glabel func_004edfc8
    /* 3EDFC8 004EDFC8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EDFCC 004EDFCC 7400033C */  lui        $3, %hi(D_0073DFE8)
    /* 3EDFD0 004EDFD0 0000BFFF */  sd         $31, 0x0($29)
    /* 3EDFD4 004EDFD4 E8DF6324 */  addiu      $3, $3, %lo(D_0073DFE8)
    /* 3EDFD8 004EDFD8 0000628C */  lw         $2, 0x0($3)
    /* 3EDFDC 004EDFDC FFFF4224 */  addiu      $2, $2, -0x1
    /* 3EDFE0 004EDFE0 09004014 */  bnez       $2, .L004EE008
    /* 3EDFE4 004EDFE4 000062AC */   sw        $2, 0x0($3)
    /* 3EDFE8 004EDFE8 7400043C */  lui        $4, %hi(D_0073DFF0)
    /* 3EDFEC 004EDFEC 0000BFDF */  ld         $31, 0x0($29)
    /* 3EDFF0 004EDFF0 2D280000 */  daddu      $5, $0, $0
    /* 3EDFF4 004EDFF4 F0DF8424 */  addiu      $4, $4, %lo(D_0073DFF0)
    /* 3EDFF8 004EDFF8 00400624 */  addiu      $6, $0, 0x4000
    /* 3EDFFC 004EDFFC 72FE1008 */  j          func_0043f9c8
    /* 3EE000 004EE000 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EE004 004EE004 00000000 */  nop
  .L004EE008:
    /* 3EE008 004EE008 0000BFDF */  ld         $31, 0x0($29)
    /* 3EE00C 004EE00C 0800E003 */  jr         $31
    /* 3EE010 004EE010 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EE014 004EE014 00000000 */  nop
.size func_004edfc8, 0x50
