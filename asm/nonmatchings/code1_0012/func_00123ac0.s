.section .text
.set noat
.set noreorder
glabel func_00123ac0
    /* 23AC0 00123AC0 DCB1848F */  lw         $4, -0x4E24($28)
    /* 23AC4 00123AC4 03008010 */  beqz       $4, .L00123AD4
    /* 23AC8 00123AC8 00000000 */   nop
    /* 23ACC 00123ACC 0A008384 */  lh         $3, 0xA($4)
    /* 23AD0 00123AD0 080083A4 */  sh         $3, 0x8($4)
  .L00123AD4:
    /* 23AD4 00123AD4 0800E003 */  jr         $31
    /* 23AD8 00123AD8 00000000 */   nop
    /* 23ADC 00123ADC 00000000 */  nop
.size func_00123ac0, 0x20
