.section .text
.set noat
.set noreorder
glabel func_004be380
    /* 3BE380 004BE380 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BE384 004BE384 2D280000 */  daddu      $5, $0, $0
    /* 3BE388 004BE388 0000BFFF */  sd         $31, 0x0($29)
    /* 3BE38C 004BE38C B07B130C */  jal        func_004deec0
    /* 3BE390 004BE390 0400848C */   lw        $4, 0x4($4)
    /* 3BE394 004BE394 0000BFDF */  ld         $31, 0x0($29)
    /* 3BE398 004BE398 2D204000 */  daddu      $4, $2, $0
    /* 3BE39C 004BE39C 70541308 */  j          func_004d51c0
    /* 3BE3A0 004BE3A0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3BE3A4 004BE3A4 00000000 */  nop
.size func_004be380, 0x28
