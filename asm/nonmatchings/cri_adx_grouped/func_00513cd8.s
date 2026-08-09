.section .text
.set noat
.set noreorder
glabel func_00513cd8
    /* 413CD8 00513CD8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 413CDC 00513CDC 00FF053C */  lui        $5, (0xFF000C03 >> 16)
    /* 413CE0 00513CE0 0000BFFF */  sd         $31, 0x0($29)
    /* 413CE4 00513CE4 030CA534 */  ori        $5, $5, (0xFF000C03 & 0xFFFF)
    /* 413CE8 00513CE8 0000BFDF */  ld         $31, 0x0($29)
    /* 413CEC 00513CEC B45E1408 */  j          func_00517ad0
    /* 413CF0 00513CF0 1000BD27 */   addiu     $29, $29, 0x10
    /* 413CF4 00513CF4 00000000 */  nop
.size func_00513cd8, 0x20
