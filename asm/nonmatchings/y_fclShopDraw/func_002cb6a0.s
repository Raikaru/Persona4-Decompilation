.section .text
.set noat
.set noreorder
glabel func_002cb6a0
    /* 1CB6A0 002CB6A0 3800828C */  lw         $2, 0x38($4)
    /* 1CB6A4 002CB6A4 300F4280 */  lb         $2, 0xF30($2)
    /* 1CB6A8 002CB6A8 01004238 */  xori       $2, $2, 0x1
    /* 1CB6AC 002CB6AC 0100422C */  sltiu      $2, $2, 0x1
    /* 1CB6B0 002CB6B0 0800E003 */  jr         $31
    /* 1CB6B4 002CB6B4 00000000 */   nop
    /* 1CB6B8 002CB6B8 00000000 */  nop
    /* 1CB6BC 002CB6BC 00000000 */  nop
.size func_002cb6a0, 0x20
