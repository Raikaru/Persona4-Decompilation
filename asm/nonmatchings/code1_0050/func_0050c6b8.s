.section .text
.set noat
.set noreorder
glabel func_0050c6b8
    /* 40C6B8 0050C6B8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40C6BC 0050C6BC 0F00073C */  lui        $7, (0xFFFFF >> 16)
    /* 40C6C0 0050C6C0 0000BFFF */  sd         $31, 0x0($29)
    /* 40C6C4 0050C6C4 2D300000 */  daddu      $6, $0, $0
    /* 40C6C8 0050C6C8 FFFFE734 */  ori        $7, $7, (0xFFFFF & 0xFFFF)
    /* 40C6CC 0050C6CC 0000BFDF */  ld         $31, 0x0($29)
    /* 40C6D0 0050C6D0 B6311408 */  j          func_0050c6d8
    /* 40C6D4 0050C6D4 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050c6b8, 0x20
