.section .text
.set noat
.set noreorder
glabel func_004d7018
    /* 3D7018 004D7018 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D701C 004D701C 0040063C */  lui        $6, (0x40000000 >> 16)
    /* 3D7020 004D7020 0000BFFF */  sd         $31, 0x0($29)
    /* 3D7024 004D7024 0000BFDF */  ld         $31, 0x0($29)
    /* 3D7028 004D7028 205C1308 */  j          func_004d7080
    /* 3D702C 004D702C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d7018, 0x18
