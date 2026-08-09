.section .text
.set noat
.set noreorder
glabel func_004b1680
    /* 3B1680 004B1680 9200033C */  lui        $3, %hi(D_00922DA0)
    /* 3B1684 004B1684 A02D64AC */  sw         $4, %lo(D_00922DA0)($3)
    /* 3B1688 004B1688 9200033C */  lui        $3, %hi(D_00922DA4)
    /* 3B168C 004B168C A42D65A4 */  sh         $5, %lo(D_00922DA4)($3)
    /* 3B1690 004B1690 9200033C */  lui        $3, %hi(D_00922DA8)
    /* 3B1694 004B1694 A82D66AC */  sw         $6, %lo(D_00922DA8)($3)
    /* 3B1698 004B1698 9200033C */  lui        $3, %hi(D_00922DAC)
    /* 3B169C 004B169C AC2D67AC */  sw         $7, %lo(D_00922DAC)($3)
    /* 3B16A0 004B16A0 94BB80AF */  sw         $0, -0x446C($28)
    /* 3B16A4 004B16A4 01000324 */  addiu      $3, $0, 0x1
    /* 3B16A8 004B16A8 98BB83AF */  sw         $3, -0x4468($28)
    /* 3B16AC 004B16AC 0800E003 */  jr         $31
    /* 3B16B0 004B16B0 00000000 */   nop
    /* 3B16B4 004B16B4 00000000 */  nop
    /* 3B16B8 004B16B8 00000000 */  nop
    /* 3B16BC 004B16BC 00000000 */  nop
.size func_004b1680, 0x40
