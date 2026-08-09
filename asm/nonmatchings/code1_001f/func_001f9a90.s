.section .text
.set noat
.set noreorder
glabel func_001f9a90
    /* F9A90 001F9A90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* F9A94 001F9A94 0000BFFF */  sd         $31, 0x0($29)
    /* F9A98 001F9A98 01000424 */  addiu      $4, $0, 0x1
    /* F9A9C 001F9A9C 2D280000 */  daddu      $5, $0, $0
    /* F9AA0 001F9AA0 08000624 */  addiu      $6, $0, 0x8
    /* F9AA4 001F9AA4 B06A110C */  jal        func_0045aac0
    /* F9AA8 001F9AA8 00000000 */   nop
    /* F9AAC 001F9AAC 0000BFDF */  ld         $31, 0x0($29)
    /* F9AB0 001F9AB0 1000BD27 */  addiu      $29, $29, 0x10
    /* F9AB4 001F9AB4 0800E003 */  jr         $31
    /* F9AB8 001F9AB8 00000000 */   nop
    /* F9ABC 001F9ABC 00000000 */  nop
.size func_001f9a90, 0x30
