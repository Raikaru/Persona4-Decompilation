.section .text
.set noat
.set noreorder
glabel func_00106ac0
    /* 6AC0 00106AC0 3C1C0400 */  dsll32     $3, $4, 16
    /* 6AC4 00106AC4 3F1C0300 */  dsra32     $3, $3, 16
    /* 6AC8 00106AC8 00110300 */  sll        $2, $3, 4
    /* 6ACC 00106ACC 21104300 */  addu       $2, $2, $3
    /* 6AD0 00106AD0 80180200 */  sll        $3, $2, 2
    /* 6AD4 00106AD4 B0B1828F */  lw         $2, -0x4E50($28)
    /* 6AD8 00106AD8 21104300 */  addu       $2, $2, $3
    /* 6ADC 00106ADC 38004280 */  lb         $2, 0x38($2)
    /* 6AE0 00106AE0 0800E003 */  jr         $31
    /* 6AE4 00106AE4 00000000 */   nop
    /* 6AE8 00106AE8 00000000 */  nop
    /* 6AEC 00106AEC 00000000 */  nop
.size func_00106ac0, 0x30
