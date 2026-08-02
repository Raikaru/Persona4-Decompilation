.section .text
.set noat
.set noreorder
glabel func_00474a90
    /* 374A90 00474A90 0800A0C4 */  lwc1       $f0, 0x8($5)
    /* 374A94 00474A94 080080E4 */  swc1       $f0, 0x8($4)
    /* 374A98 00474A98 0C00A0C4 */  lwc1       $f0, 0xC($5)
    /* 374A9C 00474A9C 0C0080E4 */  swc1       $f0, 0xC($4)
    /* 374AA0 00474AA0 1000A0C4 */  lwc1       $f0, 0x10($5)
    /* 374AA4 00474AA4 100080E4 */  swc1       $f0, 0x10($4)
    /* 374AA8 00474AA8 1400A0C4 */  lwc1       $f0, 0x14($5)
    /* 374AAC 00474AAC 140080E4 */  swc1       $f0, 0x14($4)
    /* 374AB0 00474AB0 1800A0C4 */  lwc1       $f0, 0x18($5)
    /* 374AB4 00474AB4 180080E4 */  swc1       $f0, 0x18($4)
    /* 374AB8 00474AB8 1C00A0C4 */  lwc1       $f0, 0x1C($5)
    /* 374ABC 00474ABC 1C0080E4 */  swc1       $f0, 0x1C($4)
    /* 374AC0 00474AC0 0800E003 */  jr         $31
    /* 374AC4 00474AC4 00000000 */   nop
    /* 374AC8 00474AC8 00000000 */  nop
    /* 374ACC 00474ACC 00000000 */  nop
.size func_00474a90, 0x40
