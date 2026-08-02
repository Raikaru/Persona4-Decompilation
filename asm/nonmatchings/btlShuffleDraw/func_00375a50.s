.section .text
.set noat
.set noreorder
glabel func_00375a50
    /* 275A50 00375A50 DC008394 */  lhu        $3, 0xDC($4)
    /* 275A54 00375A54 DE008294 */  lhu        $2, 0xDE($4)
    /* 275A58 00375A58 2A106200 */  slt        $2, $3, $2
    /* 275A5C 00375A5C 01004238 */  xori       $2, $2, 0x1
    /* 275A60 00375A60 0800E003 */  jr         $31
    /* 275A64 00375A64 00000000 */   nop
    /* 275A68 00375A68 00000000 */  nop
    /* 275A6C 00375A6C 00000000 */  nop
.size func_00375a50, 0x20
