.section .text
.set noat
.set noreorder
glabel func_0042c290
    /* 32C290 0042C290 00600340 */  mfc0       $3, $12 /* handwritten instruction */
    /* 32C294 0042C294 0100023C */  lui        $2, (0x10000 >> 16)
    /* 32C298 0042C298 24186200 */  and        $3, $3, $2
    /* 32C29C 0042C29C 0B006010 */  beqz       $3, .L0042C2CC
    /* 32C2A0 0042C2A0 0100063C */   lui       $6, (0x10000 >> 16)
    /* 32C2A4 0042C2A4 00000000 */  nop
  .L0042C2A8:
    /* 32C2A8 0042C2A8 39000042 */  di /* handwritten instruction */
    /* 32C2AC 0042C2AC 0F040000 */  sync.p
    /* 32C2B0 0042C2B0 00600240 */  mfc0       $2, $12 /* handwritten instruction */
    /* 32C2B4 0042C2B4 24104600 */  and        $2, $2, $6
    /* 32C2B8 0042C2B8 00000000 */  nop
    /* 32C2BC 0042C2BC 00000000 */  nop
    /* 32C2C0 0042C2C0 00000000 */  nop
    /* 32C2C4 0042C2C4 F8FF4014 */  bnez       $2, .L0042C2A8
    /* 32C2C8 0042C2C8 00000000 */   nop
  .L0042C2CC:
    /* 32C2CC 0042C2CC 00600240 */  mfc0       $2, $12 /* handwritten instruction */
    /* 32C2D0 0042C2D0 0F040000 */  sync.p
    /* 32C2D4 0042C2D4 06004234 */  ori        $2, $2, 0x6
    /* 32C2D8 0042C2D8 02004238 */  xori       $2, $2, 0x2
    /* 32C2DC 0042C2DC 25104300 */  or         $2, $2, $3
    /* 32C2E0 0042C2E0 00608240 */  mtc0       $2, $12 /* handwritten instruction */
    /* 32C2E4 0042C2E4 0F040000 */  sync.p
    /* 32C2E8 0042C2E8 000085AC */  sw         $5, 0x0($4)
    /* 32C2EC 0042C2EC 00F09F40 */  mtc0       $31, $30 /* handwritten instruction */
    /* 32C2F0 0042C2F0 0F040000 */  sync.p
    /* 32C2F4 0042C2F4 18000042 */  eret /* handwritten instruction */
    /* 32C2F8 0042C2F8 0800E003 */  jr         $31
    /* 32C2FC 0042C2FC 00000000 */   nop
.size func_0042c290, 0x70
