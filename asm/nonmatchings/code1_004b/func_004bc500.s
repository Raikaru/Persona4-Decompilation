.section .text
.set noat
.set noreorder
glabel func_004bc500
    /* 3BC500 004BC500 040080AC */  sw         $0, 0x4($4)
    /* 3BC504 004BC504 2C0080AC */  sw         $0, 0x2C($4)
    /* 3BC508 004BC508 080080AC */  sw         $0, 0x8($4)
    /* 3BC50C 004BC50C 0C0080AC */  sw         $0, 0xC($4)
    /* 3BC510 004BC510 0800E003 */  jr         $31
    /* 3BC514 004BC514 00000000 */   nop
    /* 3BC518 004BC518 00000000 */  nop
    /* 3BC51C 004BC51C 00000000 */  nop
.size func_004bc500, 0x20
