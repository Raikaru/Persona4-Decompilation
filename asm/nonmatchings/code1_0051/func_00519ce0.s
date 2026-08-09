.section .text
.set noat
.set noreorder
glabel func_00519ce0
    /* 419CE0 00519CE0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 419CE4 00519CE4 00FF053C */  lui        $5, (0xFF000D0B >> 16)
    /* 419CE8 00519CE8 0000BFFF */  sd         $31, 0x0($29)
    /* 419CEC 00519CEC 0B0DA534 */  ori        $5, $5, (0xFF000D0B & 0xFFFF)
    /* 419CF0 00519CF0 0000BFDF */  ld         $31, 0x0($29)
    /* 419CF4 00519CF4 B45E1408 */  j          func_00517ad0
    /* 419CF8 00519CF8 1000BD27 */   addiu     $29, $29, 0x10
    /* 419CFC 00519CFC 00000000 */  nop
.size func_00519ce0, 0x20
