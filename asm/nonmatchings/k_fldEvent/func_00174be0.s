.section .text
.set noat
.set noreorder
glabel func_00174be0
    /* 74BE0 00174BE0 03008010 */  beqz       $4, .L00174BF0
    /* 74BE4 00174BE4 00000000 */   nop
    /* 74BE8 00174BE8 3800838C */  lw         $3, 0x38($4)
    /* 74BEC 00174BEC 080065AC */  sw         $5, 0x8($3)
  .L00174BF0:
    /* 74BF0 00174BF0 0800E003 */  jr         $31
    /* 74BF4 00174BF4 00000000 */   nop
    /* 74BF8 00174BF8 00000000 */  nop
    /* 74BFC 00174BFC 00000000 */  nop
.size func_00174be0, 0x20
