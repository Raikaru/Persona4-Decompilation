.section .text
.set noat
.set noreorder
glabel func_0028bf90
    /* 18BF90 0028BF90 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 18BF94 0028BF94 00088244 */  mtc1       $2, $f1
    /* 18BF98 0028BF98 00008444 */  mtc1       $4, $f0
    /* 18BF9C 0028BF9C 00000000 */  nop
    /* 18BFA0 0028BFA0 20008046 */  cvt.s.w    $f0, $f0
    /* 18BFA4 0028BFA4 00080046 */  add.s      $f0, $f1, $f0
    /* 18BFA8 0028BFA8 0800E003 */  jr         $31
    /* 18BFAC 0028BFAC 00000000 */   nop
.size func_0028bf90, 0x20
