.section .text
.set noat
.set noreorder
glabel func_003d4fc0
    /* 2D4FC0 003D4FC0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2D4FC4 003D4FC4 3D00063C */  lui        $6, %hi(func_003d4f20)
    /* 2D4FC8 003D4FC8 3D00073C */  lui        $7, %hi(func_003d4f80)
    /* 2D4FCC 003D4FCC 0000BFFF */  sd         $31, 0x0($29)
    /* 2D4FD0 003D4FD0 2D200000 */  daddu      $4, $0, $0
    /* 2D4FD4 003D4FD4 B7010524 */  addiu      $5, $0, 0x1B7
    /* 2D4FD8 003D4FD8 204FC624 */  addiu      $6, $6, %lo(func_003d4f20)
    /* 2D4FDC 003D4FDC 4CA20F0C */  jal        func_003e8930
    /* 2D4FE0 003D4FE0 804FE724 */   addiu     $7, $7, %lo(func_003d4f80)
    /* 2D4FE4 003D4FE4 0000BFDF */  ld         $31, 0x0($29)
    /* 2D4FE8 003D4FE8 2A100200 */  slt        $2, $0, $2
    /* 2D4FEC 003D4FEC 0800E003 */  jr         $31
    /* 2D4FF0 003D4FF0 1000BD27 */   addiu     $29, $29, 0x10
    /* 2D4FF4 003D4FF4 00000000 */  nop
    /* 2D4FF8 003D4FF8 00000000 */  nop
    /* 2D4FFC 003D4FFC 00000000 */  nop
.size func_003d4fc0, 0x40
