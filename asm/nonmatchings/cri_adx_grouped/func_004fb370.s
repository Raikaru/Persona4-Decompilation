.section .text
.set noat
.set noreorder
glabel func_004fb370
    /* 3FB370 004FB370 7400023C */  lui        $2, %hi(D_00743CA8)
    /* 3FB374 004FB374 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3FB378 004FB378 A83C428C */  lw         $2, %lo(D_00743CA8)($2)
    /* 3FB37C 004FB37C 03004010 */  beqz       $2, .L004FB38C
    /* 3FB380 004FB380 0000BFFF */   sd        $31, 0x0($29)
    /* 3FB384 004FB384 09F84000 */  jalr       $2
    /* 3FB388 004FB388 00000000 */   nop
  .L004FB38C:
    /* 3FB38C 004FB38C 0000BFDF */  ld         $31, 0x0($29)
    /* 3FB390 004FB390 0800E003 */  jr         $31
    /* 3FB394 004FB394 1000BD27 */   addiu     $29, $29, 0x10
.size func_004fb370, 0x28
