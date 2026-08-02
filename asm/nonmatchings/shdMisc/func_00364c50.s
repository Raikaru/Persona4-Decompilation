.section .text
.set noat
.set noreorder
glabel func_00364c50
    /* 264C50 00364C50 E8AB83DF */  ld         $3, -0x5418($28)
    /* 264C54 00364C54 80006334 */  ori        $3, $3, 0x80
    /* 264C58 00364C58 E8AB83FF */  sd         $3, -0x5418($28)
    /* 264C5C 00364C5C 0800E003 */  jr         $31
    /* 264C60 00364C60 00000000 */   nop
    /* 264C64 00364C64 00000000 */  nop
    /* 264C68 00364C68 00000000 */  nop
    /* 264C6C 00364C6C 00000000 */  nop
.size func_00364c50, 0x20
