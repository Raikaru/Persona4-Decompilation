.section .text
.set noat
.set noreorder
glabel func_003b7110
    /* 2B7110 003B7110 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2B7114 003B7114 3B00063C */  lui        $6, %hi(func_003b6e70)
    /* 2B7118 003B7118 3B00073C */  lui        $7, %hi(func_003b6e00)
    /* 2B711C 003B711C 0000BFFF */  sd         $31, 0x0($29)
    /* 2B7120 003B7120 10000424 */  addiu      $4, $0, 0x10
    /* 2B7124 003B7124 0C010524 */  addiu      $5, $0, 0x10C
    /* 2B7128 003B7128 706EC624 */  addiu      $6, $6, %lo(func_003b6e70)
    /* 2B712C 003B712C 4CA20F0C */  jal        func_003e8930
    /* 2B7130 003B7130 006EE724 */   addiu     $7, $7, %lo(func_003b6e00)
    /* 2B7134 003B7134 18B682AF */  sw         $2, -0x49E8($28)
    /* 2B7138 003B7138 0000BFDF */  ld         $31, 0x0($29)
    /* 2B713C 003B713C 2A104000 */  slt        $2, $2, $0
    /* 2B7140 003B7140 01004238 */  xori       $2, $2, 0x1
    /* 2B7144 003B7144 0800E003 */  jr         $31
    /* 2B7148 003B7148 1000BD27 */   addiu     $29, $29, 0x10
    /* 2B714C 003B714C 00000000 */  nop
.size func_003b7110, 0x40
