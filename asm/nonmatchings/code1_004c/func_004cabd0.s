.section .text
.set noat
.set noreorder
glabel func_004cabd0
    /* 3CABD0 004CABD0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CABD4 004CABD4 0F00073C */  lui        $7, (0xFFFFF >> 16)
    /* 3CABD8 004CABD8 0000BFFF */  sd         $31, 0x0($29)
    /* 3CABDC 004CABDC 2D300000 */  daddu      $6, $0, $0
    /* 3CABE0 004CABE0 FFFFE734 */  ori        $7, $7, (0xFFFFF & 0xFFFF)
    /* 3CABE4 004CABE4 0000BFDF */  ld         $31, 0x0($29)
    /* 3CABE8 004CABE8 142B1308 */  j          func_004cac50
    /* 3CABEC 004CABEC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cabd0, 0x20
