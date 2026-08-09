.section .text
.set noat
.set noreorder
glabel func_00123aa0
    /* 23AA0 00123AA0 DCB1858F */  lw         $5, -0x4E24($28)
    /* 23AA4 00123AA4 0400A010 */  beqz       $5, .L00123AB8
    /* 23AA8 00123AA8 00000000 */   nop
    /* 23AAC 00123AAC 0800A384 */  lh         $3, 0x8($5)
    /* 23AB0 00123AB0 0A00A3A4 */  sh         $3, 0xA($5)
    /* 23AB4 00123AB4 0800A4A4 */  sh         $4, 0x8($5)
  .L00123AB8:
    /* 23AB8 00123AB8 0800E003 */  jr         $31
    /* 23ABC 00123ABC 00000000 */   nop
.size func_00123aa0, 0x20
