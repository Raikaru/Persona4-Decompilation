.section .text
.set noat
.set noreorder
glabel func_003bbe20
    /* 2BBE20 003BBE20 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2BBE24 003BBE24 3C00063C */  lui        $6, %hi(func_003bb0d0)
    /* 2BBE28 003BBE28 3C00073C */  lui        $7, %hi(func_003bb030)
    /* 2BBE2C 003BBE2C 0000BFFF */  sd         $31, 0x0($29)
    /* 2BBE30 003BBE30 2D200000 */  daddu      $4, $0, $0
    /* 2BBE34 003BBE34 02010524 */  addiu      $5, $0, 0x102
    /* 2BBE38 003BBE38 D0B0C624 */  addiu      $6, $6, %lo(func_003bb0d0)
    /* 2BBE3C 003BBE3C 4CA20F0C */  jal        func_003e8930
    /* 2BBE40 003BBE40 30B0E724 */   addiu     $7, $7, %lo(func_003bb030)
    /* 2BBE44 003BBE44 0000BFDF */  ld         $31, 0x0($29)
    /* 2BBE48 003BBE48 2A104000 */  slt        $2, $2, $0
    /* 2BBE4C 003BBE4C 01004238 */  xori       $2, $2, 0x1
    /* 2BBE50 003BBE50 0800E003 */  jr         $31
    /* 2BBE54 003BBE54 1000BD27 */   addiu     $29, $29, 0x10
    /* 2BBE58 003BBE58 00000000 */  nop
    /* 2BBE5C 003BBE5C 00000000 */  nop
.size func_003bbe20, 0x40
