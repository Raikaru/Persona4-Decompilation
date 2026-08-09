.section .text
.set noat
.set noreorder
glabel func_003ef8c0
    /* 2EF8C0 003EF8C0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2EF8C4 003EF8C4 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2EF8C8 003EF8C8 0000BFFF */  sd         $31, 0x0($29)
    /* 2EF8CC 003EF8CC E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2EF8D0 003EF8D0 E0B7838F */  lw         $3, -0x4820($28)
    /* 2EF8D4 003EF8D4 21104300 */  addu       $2, $2, $3
    /* 2EF8D8 003EF8D8 2C00428C */  lw         $2, 0x2C($2)
    /* 2EF8DC 003EF8DC 09F84000 */  jalr       $2
    /* 2EF8E0 003EF8E0 00000000 */   nop
    /* 2EF8E4 003EF8E4 0000BFDF */  ld         $31, 0x0($29)
    /* 2EF8E8 003EF8E8 2B100200 */  sltu       $2, $0, $2
    /* 2EF8EC 003EF8EC 0800E003 */  jr         $31
    /* 2EF8F0 003EF8F0 1000BD27 */   addiu     $29, $29, 0x10
    /* 2EF8F4 003EF8F4 00000000 */  nop
    /* 2EF8F8 003EF8F8 00000000 */  nop
    /* 2EF8FC 003EF8FC 00000000 */  nop
.size func_003ef8c0, 0x40
