.section .text
.set noat
.set noreorder
glabel func_00446ed8
    /* 346ED8 00446ED8 90FFBD27 */  addiu      $29, $29, -0x70
    /* 346EDC 00446EDC 71000F3C */  lui        $15, %hi(D_00710070)
    /* 346EE0 00446EE0 6000BFFF */  sd         $31, 0x60($29)
    /* 346EE4 00446EE4 FF7F0E3C */  lui        $14, (0x7FFFFFFF >> 16)
    /* 346EE8 00446EE8 2D688000 */  daddu      $13, $4, $0
    /* 346EEC 00446EEC FFFFCE35 */  ori        $14, $14, (0x7FFFFFFF & 0xFFFF)
    /* 346EF0 00446EF0 7000EC8D */  lw         $12, %lo(D_00710070)($15)
    /* 346EF4 00446EF4 2D20A003 */  daddu      $4, $29, $0
    /* 346EF8 00446EF8 1000ADAF */  sw         $13, 0x10($29)
    /* 346EFC 00446EFC 08020F24 */  addiu      $15, $0, 0x208
    /* 346F00 00446F00 1400AEAF */  sw         $14, 0x14($29)
    /* 346F04 00446F04 0C00AFA7 */  sh         $15, 0xC($29)
    /* 346F08 00446F08 5400ACAF */  sw         $12, 0x54($29)
    /* 346F0C 00446F0C 0000ADAF */  sw         $13, 0x0($29)
    /* 346F10 00446F10 FE11110C */  jal        func_004447f8
    /* 346F14 00446F14 0800AEAF */   sw        $14, 0x8($29)
    /* 346F18 00446F18 0000AF8F */  lw         $15, 0x0($29)
    /* 346F1C 00446F1C 6000BFDF */  ld         $31, 0x60($29)
    /* 346F20 00446F20 0000E0A1 */  sb         $0, 0x0($15)
    /* 346F24 00446F24 0800E003 */  jr         $31
    /* 346F28 00446F28 7000BD27 */   addiu     $29, $29, 0x70
    /* 346F2C 00446F2C 00000000 */  nop
.size func_00446ed8, 0x58
