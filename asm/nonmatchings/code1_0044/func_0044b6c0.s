.section .text
.set noat
.set noreorder
glabel func_0044b6c0
    /* 34B6C0 0044B6C0 00600E44 */  mfc1       $14, $f12
    /* 34B6C4 0044B6C4 FF7F0F3C */  lui        $15, (0x7FFFFFFF >> 16)
    /* 34B6C8 0044B6C8 FFFFEF35 */  ori        $15, $15, (0x7FFFFFFF & 0xFFFF)
    /* 34B6CC 0044B6CC 2470CF01 */  and        $14, $14, $15
    /* 34B6D0 0044B6D0 0800E003 */  jr         $31
    /* 34B6D4 0044B6D4 00008E44 */   mtc1      $14, $f0
.size func_0044b6c0, 0x18
