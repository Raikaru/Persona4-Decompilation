.section .text
.set noat
.set noreorder
glabel func_004fb250
    /* 3FB250 004FB250 7400033C */  lui        $3, %hi(D_00743C8C)
    /* 3FB254 004FB254 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3FB258 004FB258 8C3C638C */  lw         $3, %lo(D_00743C8C)($3)
    /* 3FB25C 004FB25C 2D100000 */  daddu      $2, $0, $0
    /* 3FB260 004FB260 03006010 */  beqz       $3, .L004FB270
    /* 3FB264 004FB264 0000BFFF */   sd        $31, 0x0($29)
    /* 3FB268 004FB268 09F86000 */  jalr       $3
    /* 3FB26C 004FB26C 00000000 */   nop
  .L004FB270:
    /* 3FB270 004FB270 0000BFDF */  ld         $31, 0x0($29)
    /* 3FB274 004FB274 0800E003 */  jr         $31
    /* 3FB278 004FB278 1000BD27 */   addiu     $29, $29, 0x10
    /* 3FB27C 004FB27C 00000000 */  nop
.size func_004fb250, 0x30
