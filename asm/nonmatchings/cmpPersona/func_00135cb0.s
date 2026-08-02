.section .text
.set noat
.set noreorder
glabel func_00135cb0
    /* 35CB0 00135CB0 1400828C */  lw         $2, 0x14($4)
    /* 35CB4 00135CB4 03004010 */  beqz       $2, .L00135CC4
    /* 35CB8 00135CB8 00000000 */   nop
    /* 35CBC 00135CBC 06000010 */  b          .L00135CD8
    /* 35CC0 00135CC0 00000000 */   nop
  .L00135CC4:
    /* 35CC4 00135CC4 01004224 */  addiu      $2, $2, 0x1
    /* 35CC8 00135CC8 140082AC */  sw         $2, 0x14($4)
    /* 35CCC 00135CCC 01000224 */  addiu      $2, $0, 0x1
    /* 35CD0 00135CD0 02000010 */  b          .L00135CDC
    /* 35CD4 00135CD4 00000000 */   nop
  .L00135CD8:
    /* 35CD8 00135CD8 01000224 */  addiu      $2, $0, 0x1
  .L00135CDC:
    /* 35CDC 00135CDC 0800E003 */  jr         $31
    /* 35CE0 00135CE0 00000000 */   nop
    /* 35CE4 00135CE4 00000000 */  nop
    /* 35CE8 00135CE8 00000000 */  nop
    /* 35CEC 00135CEC 00000000 */  nop
.size func_00135cb0, 0x40
