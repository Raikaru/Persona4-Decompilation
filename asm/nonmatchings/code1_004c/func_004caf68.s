.section .text
.set noat
.set noreorder
glabel func_004caf68
    /* 3CAF68 004CAF68 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CAF6C 004CAF6C 0F00073C */  lui        $7, (0xFFFFF >> 16)
    /* 3CAF70 004CAF70 0000BFFF */  sd         $31, 0x0($29)
    /* 3CAF74 004CAF74 2D300000 */  daddu      $6, $0, $0
    /* 3CAF78 004CAF78 FFFFE734 */  ori        $7, $7, (0xFFFFF & 0xFFFF)
    /* 3CAF7C 004CAF7C 0000BFDF */  ld         $31, 0x0($29)
    /* 3CAF80 004CAF80 FA2B1308 */  j          func_004cafe8
    /* 3CAF84 004CAF84 1000BD27 */   addiu     $29, $29, 0x10
.size func_004caf68, 0x20
