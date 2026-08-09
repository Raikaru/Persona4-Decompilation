.section .text
.set noat
.set noreorder
glabel func_001ea2d0
    /* EA2D0 001EA2D0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* EA2D4 001EA2D4 3000BFFF */  sd         $31, 0x30($29)
    /* EA2D8 001EA2D8 2000B27F */  sq         $18, 0x20($29)
    /* EA2DC 001EA2DC 1000B17F */  sq         $17, 0x10($29)
    /* EA2E0 001EA2E0 0000B07F */  sq         $16, 0x0($29)
    /* EA2E4 001EA2E4 14740A0C */  jal        func_0029d050
    /* EA2E8 001EA2E8 00000000 */   nop
    /* EA2EC 001EA2EC 2D904000 */  daddu      $18, $2, $0
    /* EA2F0 001EA2F0 2D200000 */  daddu      $4, $0, $0
    /* EA2F4 001EA2F4 00730A0C */  jal        func_0029cc00
    /* EA2F8 001EA2F8 00000000 */   nop
    /* EA2FC 001EA2FC 2D884000 */  daddu      $17, $2, $0
    /* EA300 001EA300 01000424 */  addiu      $4, $0, 0x1
    /* EA304 001EA304 00730A0C */  jal        func_0029cc00
    /* EA308 001EA308 00000000 */   nop
    /* EA30C 001EA30C 2D804000 */  daddu      $16, $2, $0
    /* EA310 001EA310 3000448E */  lw         $4, 0x30($18)
    /* EA314 001EA314 2D282002 */  daddu      $5, $17, $0
    /* EA318 001EA318 CC7B060C */  jal        func_0019ef30
    /* EA31C 001EA31C 00000000 */   nop
    /* EA320 001EA320 FFFF0632 */  andi       $6, $16, 0xFFFF
    /* EA324 001EA324 2D204002 */  daddu      $4, $18, $0
    /* EA328 001EA328 38004526 */  addiu      $5, $18, 0x38
    /* EA32C 001EA32C 9079070C */  jal        func_001de640
    /* EA330 001EA330 00000000 */   nop
    /* EA334 001EA334 01000224 */  addiu      $2, $0, 0x1
    /* EA338 001EA338 3000BFDF */  ld         $31, 0x30($29)
    /* EA33C 001EA33C 2000B27B */  lq         $18, 0x20($29)
    /* EA340 001EA340 1000B17B */  lq         $17, 0x10($29)
    /* EA344 001EA344 0000B07B */  lq         $16, 0x0($29)
    /* EA348 001EA348 4000BD27 */  addiu      $29, $29, 0x40
    /* EA34C 001EA34C 0800E003 */  jr         $31
    /* EA350 001EA350 00000000 */   nop
    /* EA354 001EA354 00000000 */  nop
    /* EA358 001EA358 00000000 */  nop
    /* EA35C 001EA35C 00000000 */  nop
.size func_001ea2d0, 0x90
