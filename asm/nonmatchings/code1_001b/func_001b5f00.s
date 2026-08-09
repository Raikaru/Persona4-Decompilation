.section .text
.set noat
.set noreorder
glabel func_001b5f00
    /* B5F00 001B5F00 F0FFBD27 */  addiu      $29, $29, -0x10
    /* B5F04 001B5F04 0000BFFF */  sd         $31, 0x0($29)
    /* B5F08 001B5F08 2D200000 */  daddu      $4, $0, $0
    /* B5F0C 001B5F0C 2D280000 */  daddu      $5, $0, $0
    /* B5F10 001B5F10 C0A80A0C */  jal        func_002aa300
    /* B5F14 001B5F14 00000000 */   nop
    /* B5F18 001B5F18 ACB3838F */  lw         $3, -0x4C54($28)
    /* B5F1C 001B5F1C CC0D62AC */  sw         $2, 0xDCC($3)
    /* B5F20 001B5F20 0000BFDF */  ld         $31, 0x0($29)
    /* B5F24 001B5F24 1000BD27 */  addiu      $29, $29, 0x10
    /* B5F28 001B5F28 0800E003 */  jr         $31
    /* B5F2C 001B5F2C 00000000 */   nop
.size func_001b5f00, 0x30
