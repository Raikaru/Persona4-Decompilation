.section .text
.set noat
.set noreorder
glabel func_001f0ff0
    /* F0FF0 001F0FF0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* F0FF4 001F0FF4 0000BFFF */  sd         $31, 0x0($29)
    /* F0FF8 001F0FF8 6E008294 */  lhu        $2, 0x6E($4)
    /* F0FFC 001F0FFC 2D304000 */  daddu      $6, $2, $0
    /* F1000 001F1000 2D280000 */  daddu      $5, $0, $0
    /* F1004 001F1004 2D380000 */  daddu      $7, $0, $0
    /* F1008 001F1008 C45F070C */  jal        func_001d7f10
    /* F100C 001F100C 00000000 */   nop
    /* F1010 001F1010 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* F1014 001F1014 26104000 */  xor        $2, $2, $0
    /* F1018 001F1018 0100422C */  sltiu      $2, $2, 0x1
    /* F101C 001F101C 0000BFDF */  ld         $31, 0x0($29)
    /* F1020 001F1020 1000BD27 */  addiu      $29, $29, 0x10
    /* F1024 001F1024 0800E003 */  jr         $31
    /* F1028 001F1028 00000000 */   nop
    /* F102C 001F102C 00000000 */  nop
.size func_001f0ff0, 0x40
