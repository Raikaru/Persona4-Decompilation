.section .text
.set noat
.set noreorder
glabel func_0050b5b0
    /* 40B5B0 0050B5B0 5100053C */  lui        $5, %hi(func_00511838)
    /* 40B5B4 0050B5B4 7600073C */  lui        $7, %hi(D_0075E9C0)
    /* 40B5B8 0050B5B8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40B5BC 0050B5BC C0E9E724 */  addiu      $7, $7, %lo(D_0075E9C0)
    /* 40B5C0 0050B5C0 3818A524 */  addiu      $5, $5, %lo(func_00511838)
    /* 40B5C4 0050B5C4 02000424 */  addiu      $4, $0, 0x2
    /* 40B5C8 0050B5C8 0000BFFF */  sd         $31, 0x0($29)
    /* 40B5CC 0050B5CC E243140C */  jal        func_00510f88
    /* 40B5D0 0050B5D0 2D300000 */   daddu     $6, $0, $0
    /* 40B5D4 0050B5D4 5100043C */  lui        $4, %hi(func_00511850)
    /* 40B5D8 0050B5D8 7600063C */  lui        $6, %hi(D_0075E9D8)
    /* 40B5DC 0050B5DC 50188424 */  addiu      $4, $4, %lo(func_00511850)
    /* 40B5E0 0050B5E0 D8E9C624 */  addiu      $6, $6, %lo(D_0075E9D8)
    /* 40B5E4 0050B5E4 1244140C */  jal        func_00511048
    /* 40B5E8 0050B5E8 2D280000 */   daddu     $5, $0, $0
    /* 40B5EC 0050B5EC 5100043C */  lui        $4, %hi(func_00511898)
    /* 40B5F0 0050B5F0 7600063C */  lui        $6, %hi(D_0075E9F0)
    /* 40B5F4 0050B5F4 98188424 */  addiu      $4, $4, %lo(func_00511898)
    /* 40B5F8 0050B5F8 F0E9C624 */  addiu      $6, $6, %lo(D_0075E9F0)
    /* 40B5FC 0050B5FC FC43140C */  jal        func_00510ff0
    /* 40B600 0050B600 2D280000 */   daddu     $5, $0, $0
    /* 40B604 0050B604 0000BFDF */  ld         $31, 0x0($29)
    /* 40B608 0050B608 28441408 */  j          func_005110a0
    /* 40B60C 0050B60C 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050b5b0, 0x60
