.section .text
.set noat
.set noreorder
glabel func_00272BA0
    /* 172BA0 00272BA0 0C000010 */  b          .L00272BD4
    /* 172BA4 00272BA4 00000000 */   nop
  .L00272BA8:
    /* 172BA8 00272BA8 1C00838C */  lw         $3, 0x1C($4)
    /* 172BAC 00272BAC 03000010 */  b          .L00272BBC
    /* 172BB0 00272BB0 00000000 */   nop
  .L00272BB4:
    /* 172BB4 00272BB4 100065AC */  sw         $5, 0x10($3)
    /* 172BB8 00272BB8 2800638C */  lw         $3, 0x28($3)
  .L00272BBC:
    /* 172BBC 00272BBC 00000000 */  nop
    /* 172BC0 00272BC0 00000000 */  nop
    /* 172BC4 00272BC4 00000000 */  nop
    /* 172BC8 00272BC8 FAFF6014 */  bnez       $3, .L00272BB4
    /* 172BCC 00272BCC 00000000 */   nop
    /* 172BD0 00272BD0 2400848C */  lw         $4, 0x24($4)
  .L00272BD4:
    /* 172BD4 00272BD4 F4FF8014 */  bnez       $4, .L00272BA8
    /* 172BD8 00272BD8 00000000 */   nop
    /* 172BDC 00272BDC 0800E003 */  jr         $31
    /* 172BE0 00272BE0 00000000 */   nop
    /* 172BE4 00272BE4 00000000 */  nop
    /* 172BE8 00272BE8 00000000 */  nop
    /* 172BEC 00272BEC 00000000 */  nop
.size func_00272ba0, 0x50
