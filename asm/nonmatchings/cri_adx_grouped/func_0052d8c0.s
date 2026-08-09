.section .text
.set noat
.set noreorder
glabel func_0052d8c0
    /* 42D8C0 0052D8C0 3C200400 */  dsll32     $4, $4, 0
    /* 42D8C4 0052D8C4 3F200400 */  dsra32     $4, $4, 0
    /* 42D8C8 0052D8C8 7449013C */  lui        $1, (0x49742400 >> 16)
    /* 42D8CC 0052D8CC 00242134 */  ori        $1, $1, (0x49742400 & 0xFFFF)
    /* 42D8D0 0052D8D0 00108144 */  mtc1       $1, $f2
    /* 42D8D4 0052D8D4 00008444 */  mtc1       $4, $f0
    /* 42D8D8 0052D8D8 20008046 */  cvt.s.w    $f0, $f0
    /* 42D8DC 0052D8DC 7400023C */  lui        $2, %hi(D_007463B0)
    /* 42D8E0 0052D8E0 B06341C4 */  lwc1       $f1, %lo(D_007463B0)($2)
    /* 42D8E4 0052D8E4 60088046 */  cvt.s.w    $f1, $f1
    /* 42D8E8 0052D8E8 02000246 */  mul.s      $f0, $f0, $f2
    /* 42D8EC 0052D8EC 00000000 */  nop
    /* 42D8F0 0052D8F0 00000000 */  nop
    /* 42D8F4 0052D8F4 03000146 */  div.s      $f0, $f0, $f1
    /* 42D8F8 0052D8F8 0800E003 */  jr         $31
    /* 42D8FC 0052D8FC 00000000 */   nop
.size func_0052d8c0, 0x40
