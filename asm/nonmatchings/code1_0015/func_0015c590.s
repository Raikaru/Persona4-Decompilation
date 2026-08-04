.section .text
.set noat
.set noreorder
glabel func_0015c590
    /* 5C590 0015C590 70FFBD27 */  addiu      $29, $29, -0x90
    /* 5C594 0015C594 0000BFFF */  sd         $31, 0x0($29)
    /* 5C598 0015C598 2D308000 */  daddu      $6, $4, $0
    /* 5C59C 0015C59C 1000A427 */  addiu      $4, $29, 0x10
    /* 5C5A0 0015C5A0 5F00053C */  lui        $5, %hi(D_005F0740)
    /* 5C5A4 0015C5A4 4007A524 */  addiu      $5, $5, %lo(D_005F0740)
    /* 5C5A8 0015C5A8 2208110C */  jal        func_00442088
    /* 5C5AC 0015C5AC 00000000 */   nop
    /* 5C5B0 0015C5B0 289E8427 */  addiu      $4, $28, -0x61D8
    /* 5C5B4 0015C5B4 5F00053C */  lui        $5, %hi(D_005F05E8)
    /* 5C5B8 0015C5B8 E805A524 */  addiu      $5, $5, %lo(D_005F05E8)
    /* 5C5BC 0015C5BC 490C0624 */  addiu      $6, $0, 0xC49
    /* 5C5C0 0015C5C0 DA02110C */  jal        func_00440b68
    /* 5C5C4 0015C5C4 00000000 */   nop
    /* 5C5C8 0015C5C8 1000A427 */  addiu      $4, $29, 0x10
    /* 5C5CC 0015C5CC 2D280000 */  daddu      $5, $0, $0
    /* 5C5D0 0015C5D0 9852110C */  jal        func_00454a60
    /* 5C5D4 0015C5D4 00000000 */   nop
    /* 5C5D8 0015C5D8 0000BFDF */  ld         $31, 0x0($29)
    /* 5C5DC 0015C5DC 9000BD27 */  addiu      $29, $29, 0x90
    /* 5C5E0 0015C5E0 0800E003 */  jr         $31
    /* 5C5E4 0015C5E4 00000000 */   nop
    /* 5C5E8 0015C5E8 00000000 */  nop
    /* 5C5EC 0015C5EC 00000000 */  nop
.size func_0015c590, 0x60
