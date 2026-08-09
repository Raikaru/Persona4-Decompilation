.section .text
.set noat
.set noreorder
glabel func_004b1590
    /* 3B1590 004B1590 9200033C */  lui        $3, %hi(D_00922DA0)
    /* 3B1594 004B1594 A02D64AC */  sw         $4, %lo(D_00922DA0)($3)
    /* 3B1598 004B1598 9200033C */  lui        $3, %hi(D_00922DA4)
    /* 3B159C 004B159C A42D65A4 */  sh         $5, %lo(D_00922DA4)($3)
    /* 3B15A0 004B15A0 9200033C */  lui        $3, %hi(D_00922DA8)
    /* 3B15A4 004B15A4 A82D60AC */  sw         $0, %lo(D_00922DA8)($3)
    /* 3B15A8 004B15A8 9200033C */  lui        $3, %hi(D_00922DAC)
    /* 3B15AC 004B15AC AC2D60AC */  sw         $0, %lo(D_00922DAC)($3)
    /* 3B15B0 004B15B0 94BB80AF */  sw         $0, -0x446C($28)
    /* 3B15B4 004B15B4 01000324 */  addiu      $3, $0, 0x1
    /* 3B15B8 004B15B8 98BB83AF */  sw         $3, -0x4468($28)
    /* 3B15BC 004B15BC 0800E003 */  jr         $31
    /* 3B15C0 004B15C0 00000000 */   nop
    /* 3B15C4 004B15C4 00000000 */  nop
    /* 3B15C8 004B15C8 00000000 */  nop
    /* 3B15CC 004B15CC 00000000 */  nop
.size func_004b1590, 0x40
