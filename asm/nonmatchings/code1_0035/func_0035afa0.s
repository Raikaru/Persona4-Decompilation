.section .text
.set noat
.set noreorder
glabel func_0035afa0
    /* 25AFA0 0035AFA0 3800838C */  lw         $3, 0x38($4)
    /* 25AFA4 0035AFA4 2C00628C */  lw         $2, 0x2C($3)
    /* 25AFA8 0035AFA8 04004010 */  beqz       $2, .L0035AFBC
    /* 25AFAC 0035AFAC 00000000 */   nop
    /* 25AFB0 0035AFB0 20006280 */  lb         $2, 0x20($3)
    /* 25AFB4 0035AFB4 04004014 */  bnez       $2, .L0035AFC8
    /* 25AFB8 0035AFB8 00000000 */   nop
  .L0035AFBC:
    /* 25AFBC 0035AFBC 2D100000 */  daddu      $2, $0, $0
    /* 25AFC0 0035AFC0 02000010 */  b          .L0035AFCC
    /* 25AFC4 0035AFC4 00000000 */   nop
  .L0035AFC8:
    /* 25AFC8 0035AFC8 01000224 */  addiu      $2, $0, 0x1
  .L0035AFCC:
    /* 25AFCC 0035AFCC 05004010 */  beqz       $2, .L0035AFE4
    /* 25AFD0 0035AFD0 00000000 */   nop
    /* 25AFD4 0035AFD4 3C00628C */  lw         $2, 0x3C($3)
    /* 25AFD8 0035AFD8 0000428C */  lw         $2, 0x0($2)
    /* 25AFDC 0035AFDC 02000010 */  b          .L0035AFE8
    /* 25AFE0 0035AFE0 00000000 */   nop
  .L0035AFE4:
    /* 25AFE4 0035AFE4 2D100000 */  daddu      $2, $0, $0
  .L0035AFE8:
    /* 25AFE8 0035AFE8 0800E003 */  jr         $31
    /* 25AFEC 0035AFEC 00000000 */   nop
.size func_0035afa0, 0x50
