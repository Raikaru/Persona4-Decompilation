.section .text
.set noat
.set noreorder
glabel func_004fbaa8
    /* 3FBAA8 004FBAA8 0300A010 */  beqz       $5, .L004FBAB8
    /* 3FBAAC 004FBAAC 48018424 */   addiu     $4, $4, 0x148
    /* 3FBAB0 004FBAB0 0000828C */  lw         $2, 0x0($4)
    /* 3FBAB4 004FBAB4 0000A2AC */  sw         $2, 0x0($5)
  .L004FBAB8:
    /* 3FBAB8 004FBAB8 0300C010 */  beqz       $6, .L004FBAC8
    /* 3FBABC 004FBABC 00000000 */   nop
    /* 3FBAC0 004FBAC0 0800828C */  lw         $2, 0x8($4)
    /* 3FBAC4 004FBAC4 0000C2AC */  sw         $2, 0x0($6)
  .L004FBAC8:
    /* 3FBAC8 004FBAC8 0800E003 */  jr         $31
    /* 3FBACC 004FBACC 00000000 */   nop
.size func_004fbaa8, 0x28
