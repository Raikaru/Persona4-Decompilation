.section .text
.set noat
.set noreorder
glabel func_00106a90
    /* 6A90 00106A90 3C1C0400 */  dsll32     $3, $4, 16
    /* 6A94 00106A94 3F1C0300 */  dsra32     $3, $3, 16
    /* 6A98 00106A98 00110300 */  sll        $2, $3, 4
    /* 6A9C 00106A9C 21104300 */  addu       $2, $2, $3
    /* 6AA0 00106AA0 80180200 */  sll        $3, $2, 2
    /* 6AA4 00106AA4 B0B1828F */  lw         $2, -0x4E50($28)
    /* 6AA8 00106AA8 21104300 */  addu       $2, $2, $3
    /* 6AAC 00106AAC 3400428C */  lw         $2, 0x34($2)
    /* 6AB0 00106AB0 0800E003 */  jr         $31
    /* 6AB4 00106AB4 00000000 */   nop
    /* 6AB8 00106AB8 00000000 */  nop
    /* 6ABC 00106ABC 00000000 */  nop
.size func_00106a90, 0x30
