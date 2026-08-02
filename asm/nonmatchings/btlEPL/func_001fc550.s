.section .text
.set noat
.set noreorder
glabel func_001fc550
    /* FC550 001FC550 D0FFBD27 */  addiu      $29, $29, -0x30
    /* FC554 001FC554 2000BFFF */  sd         $31, 0x20($29)
    /* FC558 001FC558 1000B17F */  sq         $17, 0x10($29)
    /* FC55C 001FC55C 0000B07F */  sq         $16, 0x0($29)
    /* FC560 001FC560 3000908C */  lw         $16, 0x30($4)
    /* FC564 001FC564 6200043C */  lui        $4, %hi(D_00625230)
    /* FC568 001FC568 30528424 */  addiu      $4, $4, %lo(D_00625230)
    /* FC56C 001FC56C B1000524 */  addiu      $5, $0, 0xB1
    /* FC570 001FC570 A43A110C */  jal        func_0044ea90
    /* FC574 001FC574 00000000 */   nop
    /* FC578 001FC578 04000424 */  addiu      $4, $0, 0x4
    /* FC57C 001FC57C 0400053C */  lui        $5, (0x40000 >> 16)
    /* FC580 001FC580 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* FC584 001FC584 E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* FC588 001FC588 09F84000 */  jalr       $2
    /* FC58C 001FC58C 00000000 */   nop
    /* FC590 001FC590 2D884000 */  daddu      $17, $2, $0
    /* FC594 001FC594 0000048E */  lw         $4, 0x0($16)
    /* FC598 001FC598 06008010 */  beqz       $4, .L001FC5B4
    /* FC59C 001FC59C 00000000 */   nop
    /* FC5A0 001FC5A0 60AF120C */  jal        func_004abd80
    /* FC5A4 001FC5A4 00000000 */   nop
    /* FC5A8 001FC5A8 000022AE */  sw         $2, 0x0($17)
    /* FC5AC 001FC5AC 02000010 */  b          .L001FC5B8
    /* FC5B0 001FC5B0 00000000 */   nop
  .L001FC5B4:
    /* FC5B4 001FC5B4 000020AE */  sw         $0, 0x0($17)
  .L001FC5B8:
    /* FC5B8 001FC5B8 2D102002 */  daddu      $2, $17, $0
    /* FC5BC 001FC5BC 2000BFDF */  ld         $31, 0x20($29)
    /* FC5C0 001FC5C0 1000B17B */  lq         $17, 0x10($29)
    /* FC5C4 001FC5C4 0000B07B */  lq         $16, 0x0($29)
    /* FC5C8 001FC5C8 3000BD27 */  addiu      $29, $29, 0x30
    /* FC5CC 001FC5CC 0800E003 */  jr         $31
    /* FC5D0 001FC5D0 00000000 */   nop
    /* FC5D4 001FC5D4 00000000 */  nop
    /* FC5D8 001FC5D8 00000000 */  nop
    /* FC5DC 001FC5DC 00000000 */  nop
.size func_001fc550, 0x90
