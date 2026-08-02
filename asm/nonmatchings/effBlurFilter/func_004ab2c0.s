.section .text
.set noat
.set noreorder
glabel func_004ab2c0
    /* 3AB2C0 004AB2C0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3AB2C4 004AB2C4 0000BFFF */  sd         $31, 0x0($29)
    /* 3AB2C8 004AB2C8 1800838C */  lw         $3, 0x18($4)
    /* 3AB2CC 004AB2CC 40100300 */  sll        $2, $3, 1
    /* 3AB2D0 004AB2D0 21104300 */  addu       $2, $2, $3
    /* 3AB2D4 004AB2D4 C0180200 */  sll        $3, $2, 3
    /* 3AB2D8 004AB2D8 7100023C */  lui        $2, %hi(D_0071439C)
    /* 3AB2DC 004AB2DC 9C434224 */  addiu      $2, $2, %lo(D_0071439C)
    /* 3AB2E0 004AB2E0 21104300 */  addu       $2, $2, $3
    /* 3AB2E4 004AB2E4 0000428C */  lw         $2, 0x0($2)
    /* 3AB2E8 004AB2E8 09F84000 */  jalr       $2
    /* 3AB2EC 004AB2EC 00000000 */   nop
    /* 3AB2F0 004AB2F0 0000BFDF */  ld         $31, 0x0($29)
    /* 3AB2F4 004AB2F4 1000BD27 */  addiu      $29, $29, 0x10
    /* 3AB2F8 004AB2F8 0800E003 */  jr         $31
    /* 3AB2FC 004AB2FC 00000000 */   nop
.size func_004ab2c0, 0x40
