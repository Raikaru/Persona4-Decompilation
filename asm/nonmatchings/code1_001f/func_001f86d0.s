.section .text
.set noat
.set noreorder
glabel func_001f86d0
    /* F86D0 001F86D0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* F86D4 001F86D4 0000BFFF */  sd         $31, 0x0($29)
    /* F86D8 001F86D8 03000424 */  addiu      $4, $0, 0x3
    /* F86DC 001F86DC 2D280000 */  daddu      $5, $0, $0
    /* F86E0 001F86E0 08000624 */  addiu      $6, $0, 0x8
    /* F86E4 001F86E4 B06A110C */  jal        func_0045aac0
    /* F86E8 001F86E8 00000000 */   nop
    /* F86EC 001F86EC 0000BFDF */  ld         $31, 0x0($29)
    /* F86F0 001F86F0 1000BD27 */  addiu      $29, $29, 0x10
    /* F86F4 001F86F4 0800E003 */  jr         $31
    /* F86F8 001F86F8 00000000 */   nop
    /* F86FC 001F86FC 00000000 */  nop
.size func_001f86d0, 0x30
