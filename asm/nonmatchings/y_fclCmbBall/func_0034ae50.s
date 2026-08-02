.section .text
.set noat
.set noreorder
glabel func_0034ae50
    /* 24AE50 0034AE50 3C160500 */  dsll32     $2, $5, 24
    /* 24AE54 0034AE54 3F160200 */  dsra32     $2, $2, 24
    /* 24AE58 0034AE58 401A0200 */  sll        $3, $2, 9
    /* 24AE5C 0034AE5C 3800828C */  lw         $2, 0x38($4)
    /* 24AE60 0034AE60 21104300 */  addu       $2, $2, $3
    /* 24AE64 0034AE64 04014224 */  addiu      $2, $2, 0x104
    /* 24AE68 0034AE68 0800E003 */  jr         $31
    /* 24AE6C 0034AE6C 00000000 */   nop
.size func_0034ae50, 0x20
