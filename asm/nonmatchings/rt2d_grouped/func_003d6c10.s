.section .text
.set noat
.set noreorder
glabel func_003d6c10
    /* 2D6C10 003D6C10 0000A5C4 */  lwc1       $f5, 0x0($5)
    /* 2D6C14 003D6C14 2D108000 */  daddu      $2, $4, $0
    /* 2D6C18 003D6C18 0400A4C4 */  lwc1       $f4, 0x4($5)
    /* 2D6C1C 003D6C1C 1000A3C4 */  lwc1       $f3, 0x10($5)
    /* 2D6C20 003D6C20 1400A2C4 */  lwc1       $f2, 0x14($5)
    /* 2D6C24 003D6C24 3000A1C4 */  lwc1       $f1, 0x30($5)
    /* 2D6C28 003D6C28 3400A0C4 */  lwc1       $f0, 0x34($5)
    /* 2D6C2C 003D6C2C 000085E4 */  swc1       $f5, 0x0($4)
    /* 2D6C30 003D6C30 040084E4 */  swc1       $f4, 0x4($4)
    /* 2D6C34 003D6C34 080083E4 */  swc1       $f3, 0x8($4)
    /* 2D6C38 003D6C38 0C0082E4 */  swc1       $f2, 0xC($4)
    /* 2D6C3C 003D6C3C 100081E4 */  swc1       $f1, 0x10($4)
    /* 2D6C40 003D6C40 0800E003 */  jr         $31
    /* 2D6C44 003D6C44 140080E4 */   swc1      $f0, 0x14($4)
    /* 2D6C48 003D6C48 00000000 */  nop
    /* 2D6C4C 003D6C4C 00000000 */  nop
.size func_003d6c10, 0x40
