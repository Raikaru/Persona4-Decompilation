.section .text
.set noat
.set noreorder
glabel func_001fc4a0
    /* FC4A0 001FC4A0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* FC4A4 001FC4A4 4000BFFF */  sd         $31, 0x40($29)
    /* FC4A8 001FC4A8 3000B37F */  sq         $19, 0x30($29)
    /* FC4AC 001FC4AC 2000B27F */  sq         $18, 0x20($29)
    /* FC4B0 001FC4B0 1000B17F */  sq         $17, 0x10($29)
    /* FC4B4 001FC4B4 0000B07F */  sq         $16, 0x0($29)
    /* FC4B8 001FC4B8 2D98A000 */  daddu      $19, $5, $0
    /* FC4BC 001FC4BC 2D88C000 */  daddu      $17, $6, $0
    /* FC4C0 001FC4C0 2D80E000 */  daddu      $16, $7, $0
    /* FC4C4 001FC4C4 6200043C */  lui        $4, %hi(D_00625230)
    /* FC4C8 001FC4C8 30528424 */  addiu      $4, $4, %lo(D_00625230)
    /* FC4CC 001FC4CC B1000524 */  addiu      $5, $0, 0xB1
    /* FC4D0 001FC4D0 A43A110C */  jal        func_0044ea90
    /* FC4D4 001FC4D4 00000000 */   nop
    /* FC4D8 001FC4D8 04000424 */  addiu      $4, $0, 0x4
    /* FC4DC 001FC4DC 0400053C */  lui        $5, (0x40000 >> 16)
    /* FC4E0 001FC4E0 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* FC4E4 001FC4E4 E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* FC4E8 001FC4E8 09F84000 */  jalr       $2
    /* FC4EC 001FC4EC 00000000 */   nop
    /* FC4F0 001FC4F0 2D904000 */  daddu      $18, $2, $0
    /* FC4F4 001FC4F4 0C002012 */  beqz       $17, .L001FC528
    /* FC4F8 001FC4F8 00000000 */   nop
    /* FC4FC 001FC4FC FFFF6332 */  andi       $3, $19, 0xFFFF
    /* FC500 001FC500 03000224 */  addiu      $2, $0, 0x3
    /* FC504 001FC504 08006214 */  bne        $3, $2, .L001FC528
    /* FC508 001FC508 00000000 */   nop
    /* FC50C 001FC50C 2D202002 */  daddu      $4, $17, $0
    /* FC510 001FC510 2D280002 */  daddu      $5, $16, $0
    /* FC514 001FC514 14AF120C */  jal        func_004abc50
    /* FC518 001FC518 00000000 */   nop
    /* FC51C 001FC51C 000042AE */  sw         $2, 0x0($18)
    /* FC520 001FC520 02000010 */  b          .L001FC52C
    /* FC524 001FC524 00000000 */   nop
  .L001FC528:
    /* FC528 001FC528 000040AE */  sw         $0, 0x0($18)
  .L001FC52C:
    /* FC52C 001FC52C 2D104002 */  daddu      $2, $18, $0
    /* FC530 001FC530 4000BFDF */  ld         $31, 0x40($29)
    /* FC534 001FC534 3000B37B */  lq         $19, 0x30($29)
    /* FC538 001FC538 2000B27B */  lq         $18, 0x20($29)
    /* FC53C 001FC53C 1000B17B */  lq         $17, 0x10($29)
    /* FC540 001FC540 0000B07B */  lq         $16, 0x0($29)
    /* FC544 001FC544 5000BD27 */  addiu      $29, $29, 0x50
    /* FC548 001FC548 0800E003 */  jr         $31
    /* FC54C 001FC54C 00000000 */   nop
.size func_001fc4a0, 0xb0
