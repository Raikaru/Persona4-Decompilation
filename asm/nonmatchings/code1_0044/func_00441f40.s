.section .text
.set noat
.set noreorder
glabel func_00441f40
    /* 341F40 00441F40 00600D44 */  mfc1       $13, $f12
    /* 341F44 00441F44 FF7F0C3C */  lui        $12, (0x7FFFFFFF >> 16)
    /* 341F48 00441F48 00680F44 */  mfc1       $15, $f13
    /* 341F4C 00441F4C FFFF8C35 */  ori        $12, $12, (0x7FFFFFFF & 0xFFFF)
    /* 341F50 00441F50 00800E3C */  lui        $14, (0x80000000 >> 16)
    /* 341F54 00441F54 2468AC01 */  and        $13, $13, $12
    /* 341F58 00441F58 2478EE01 */  and        $15, $15, $14
    /* 341F5C 00441F5C 2568AF01 */  or         $13, $13, $15
    /* 341F60 00441F60 0800E003 */  jr         $31
    /* 341F64 00441F64 00008D44 */   mtc1      $13, $f0
.size func_00441f40, 0x28
