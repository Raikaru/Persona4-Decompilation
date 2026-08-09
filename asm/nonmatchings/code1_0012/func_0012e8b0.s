.section .text
.set noat
.set noreorder
glabel func_0012e8b0
    /* 2E8B0 0012E8B0 1800838C */  lw         $3, 0x18($4)
    /* 2E8B4 0012E8B4 01000224 */  addiu      $2, $0, 0x1
    /* 2E8B8 0012E8B8 09006210 */  beq        $3, $2, .L0012E8E0
    /* 2E8BC 0012E8BC 00000000 */   nop
    /* 2E8C0 0012E8C0 03006010 */  beqz       $3, .L0012E8D0
    /* 2E8C4 0012E8C4 00000000 */   nop
    /* 2E8C8 0012E8C8 07000010 */  b          .L0012E8E8
    /* 2E8CC 0012E8CC 00000000 */   nop
  .L0012E8D0:
    /* 2E8D0 0012E8D0 01006324 */  addiu      $3, $3, 0x1
    /* 2E8D4 0012E8D4 180083AC */  sw         $3, 0x18($4)
    /* 2E8D8 0012E8D8 04000010 */  b          .L0012E8EC
    /* 2E8DC 0012E8DC 00000000 */   nop
  .L0012E8E0:
    /* 2E8E0 0012E8E0 02000010 */  b          .L0012E8EC
    /* 2E8E4 0012E8E4 00000000 */   nop
  .L0012E8E8:
    /* 2E8E8 0012E8E8 2D100000 */  daddu      $2, $0, $0
  .L0012E8EC:
    /* 2E8EC 0012E8EC 0800E003 */  jr         $31
    /* 2E8F0 0012E8F0 00000000 */   nop
    /* 2E8F4 0012E8F4 00000000 */  nop
    /* 2E8F8 0012E8F8 00000000 */  nop
    /* 2E8FC 0012E8FC 00000000 */  nop
.size func_0012e8b0, 0x50
