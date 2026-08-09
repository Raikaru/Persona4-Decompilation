.section .text
.set noat
.set noreorder
glabel func_001cf020
    /* CF020 001CF020 C0FFBD27 */  addiu      $29, $29, -0x40
    /* CF024 001CF024 1000BFFF */  sd         $31, 0x10($29)
    /* CF028 001CF028 0000B07F */  sq         $16, 0x0($29)
    /* CF02C 001CF02C 2D808000 */  daddu      $16, $4, $0
    /* CF030 001CF030 2D280000 */  daddu      $5, $0, $0
    /* CF034 001CF034 2D300000 */  daddu      $6, $0, $0
    /* CF038 001CF038 2D380000 */  daddu      $7, $0, $0
    /* CF03C 001CF03C 2000A827 */  addiu      $8, $29, 0x20
    /* CF040 001CF040 D01B070C */  jal        func_001c6f40
    /* CF044 001CF044 00000000 */   nop
    /* CF048 001CF048 2D200002 */  daddu      $4, $16, $0
    /* CF04C 001CF04C 2000A527 */  addiu      $5, $29, 0x20
    /* CF050 001CF050 C0EA060C */  jal        func_001bab00
    /* CF054 001CF054 00000000 */   nop
    /* CF058 001CF058 1000BFDF */  ld         $31, 0x10($29)
    /* CF05C 001CF05C 0000B07B */  lq         $16, 0x0($29)
    /* CF060 001CF060 4000BD27 */  addiu      $29, $29, 0x40
    /* CF064 001CF064 0800E003 */  jr         $31
    /* CF068 001CF068 00000000 */   nop
    /* CF06C 001CF06C 00000000 */  nop
.size func_001cf020, 0x50
