.section .text
.set noat
.set noreorder
glabel func_004f8aa0
    /* 3F8AA0 004F8AA0 7400023C */  lui        $2, %hi(D_00743C34)
    /* 3F8AA4 004F8AA4 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F8AA8 004F8AA8 343C438C */  lw         $3, %lo(D_00743C34)($2)
    /* 3F8AAC 004F8AAC 2D288000 */  daddu      $5, $4, $0
    /* 3F8AB0 004F8AB0 04006010 */  beqz       $3, .L004F8AC4
    /* 3F8AB4 004F8AB4 0000BFFF */   sd        $31, 0x0($29)
    /* 3F8AB8 004F8AB8 7400023C */  lui        $2, %hi(D_00743C38)
    /* 3F8ABC 004F8ABC 09F86000 */  jalr       $3
    /* 3F8AC0 004F8AC0 383C448C */   lw        $4, %lo(D_00743C38)($2)
  .L004F8AC4:
    /* 3F8AC4 004F8AC4 0000BFDF */  ld         $31, 0x0($29)
    /* 3F8AC8 004F8AC8 2D100000 */  daddu      $2, $0, $0
    /* 3F8ACC 004F8ACC 0800E003 */  jr         $31
    /* 3F8AD0 004F8AD0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F8AD4 004F8AD4 00000000 */  nop
.size func_004f8aa0, 0x38
