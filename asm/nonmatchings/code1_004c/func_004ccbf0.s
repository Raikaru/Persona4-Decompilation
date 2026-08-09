.section .text
.set noat
.set noreorder
glabel func_004ccbf0
    /* 3CCBF0 004CCBF0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 3CCBF4 004CCBF4 7200023C */  lui        $2, %hi(D_007199EC)
    /* 3CCBF8 004CCBF8 3800B1FF */  sd         $17, 0x38($29)
    /* 3CCBFC 004CCBFC EC995124 */  addiu      $17, $2, %lo(D_007199EC)
    /* 3CCC00 004CCC00 0000238E */  lw         $3, 0x0($17)
    /* 3CCC04 004CCC04 01000424 */  addiu      $4, $0, 0x1
    /* 3CCC08 004CCC08 3000B0FF */  sd         $16, 0x30($29)
    /* 3CCC0C 004CCC0C 12006414 */  bne        $3, $4, .L004CCC58
    /* 3CCC10 004CCC10 4000BFFF */   sd        $31, 0x40($29)
    /* 3CCC14 004CCC14 7200023C */  lui        $2, %hi(D_00719A38)
    /* 3CCC18 004CCC18 2D28A003 */  daddu      $5, $29, $0
    /* 3CCC1C 004CCC1C 389A5024 */  addiu      $16, $2, %lo(D_00719A38)
    /* 3CCC20 004CCC20 B885100C */  jal        func_004216e0
    /* 3CCC24 004CCC24 0000048E */   lw        $4, 0x0($16)
    /* 3CCC28 004CCC28 0000A38F */  lw         $3, 0x0($29)
    /* 3CCC2C 004CCC2C 04000224 */  addiu      $2, $0, 0x4
    /* 3CCC30 004CCC30 03006210 */  beq        $3, $2, .L004CCC40
    /* 3CCC34 004CCC34 0C000424 */   addiu     $4, $0, 0xC
    /* 3CCC38 004CCC38 08006454 */  bnel       $3, $4, .L004CCC5C
    /* 3CCC3C 004CCC3C 3000B0DF */   ld        $16, 0x30($29)
  .L004CCC40:
    /* 3CCC40 004CCC40 0000048E */  lw         $4, 0x0($16)
    /* 3CCC44 004CCC44 C485100C */  jal        func_00421710
    /* 3CCC48 004CCC48 00000000 */   nop
    /* 3CCC4C 004CCC4C 0000038E */  lw         $3, 0x0($16)
    /* 3CCC50 004CCC50 01004350 */  beql       $2, $3, .L004CCC58
    /* 3CCC54 004CCC54 000020AE */   sw        $0, 0x0($17)
  .L004CCC58:
    /* 3CCC58 004CCC58 3000B0DF */  ld         $16, 0x30($29)
  .L004CCC5C:
    /* 3CCC5C 004CCC5C 3800B1DF */  ld         $17, 0x38($29)
    /* 3CCC60 004CCC60 4000BFDF */  ld         $31, 0x40($29)
    /* 3CCC64 004CCC64 0800E003 */  jr         $31
    /* 3CCC68 004CCC68 5000BD27 */   addiu     $29, $29, 0x50
    /* 3CCC6C 004CCC6C 00000000 */  nop
.size func_004ccbf0, 0x80
