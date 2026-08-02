.section .text
.set noat
.set noreorder
glabel func_001ff300
    /* FF300 001FF300 B0FFBD27 */  addiu      $29, $29, -0x50
    /* FF304 001FF304 4000BFFF */  sd         $31, 0x40($29)
    /* FF308 001FF308 3000B37F */  sq         $19, 0x30($29)
    /* FF30C 001FF30C 2000B27F */  sq         $18, 0x20($29)
    /* FF310 001FF310 1000B17F */  sq         $17, 0x10($29)
    /* FF314 001FF314 0000B07F */  sq         $16, 0x0($29)
    /* FF318 001FF318 2D98A000 */  daddu      $19, $5, $0
    /* FF31C 001FF31C 2D88C000 */  daddu      $17, $6, $0
    /* FF320 001FF320 2D80E000 */  daddu      $16, $7, $0
    /* FF324 001FF324 6200043C */  lui        $4, %hi(D_00625230)
    /* FF328 001FF328 30528424 */  addiu      $4, $4, %lo(D_00625230)
    /* FF32C 001FF32C 29040524 */  addiu      $5, $0, 0x429
    /* FF330 001FF330 A43A110C */  jal        func_0044ea90
    /* FF334 001FF334 00000000 */   nop
    /* FF338 001FF338 24000424 */  addiu      $4, $0, 0x24
    /* FF33C 001FF33C 0400053C */  lui        $5, (0x40000 >> 16)
    /* FF340 001FF340 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* FF344 001FF344 E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* FF348 001FF348 09F84000 */  jalr       $2
    /* FF34C 001FF34C 00000000 */   nop
    /* FF350 001FF350 2D904000 */  daddu      $18, $2, $0
    /* FF354 001FF354 0C002012 */  beqz       $17, .L001FF388
    /* FF358 001FF358 00000000 */   nop
    /* FF35C 001FF35C FFFF6332 */  andi       $3, $19, 0xFFFF
    /* FF360 001FF360 03000224 */  addiu      $2, $0, 0x3
    /* FF364 001FF364 08006214 */  bne        $3, $2, .L001FF388
    /* FF368 001FF368 00000000 */   nop
    /* FF36C 001FF36C 2D202002 */  daddu      $4, $17, $0
    /* FF370 001FF370 2D280002 */  daddu      $5, $16, $0
    /* FF374 001FF374 14AF120C */  jal        func_004abc50
    /* FF378 001FF378 00000000 */   nop
    /* FF37C 001FF37C 000042AE */  sw         $2, 0x0($18)
    /* FF380 001FF380 02000010 */  b          .L001FF38C
    /* FF384 001FF384 00000000 */   nop
  .L001FF388:
    /* FF388 001FF388 000040AE */  sw         $0, 0x0($18)
  .L001FF38C:
    /* FF38C 001FF38C 2D104002 */  daddu      $2, $18, $0
    /* FF390 001FF390 4000BFDF */  ld         $31, 0x40($29)
    /* FF394 001FF394 3000B37B */  lq         $19, 0x30($29)
    /* FF398 001FF398 2000B27B */  lq         $18, 0x20($29)
    /* FF39C 001FF39C 1000B17B */  lq         $17, 0x10($29)
    /* FF3A0 001FF3A0 0000B07B */  lq         $16, 0x0($29)
    /* FF3A4 001FF3A4 5000BD27 */  addiu      $29, $29, 0x50
    /* FF3A8 001FF3A8 0800E003 */  jr         $31
    /* FF3AC 001FF3AC 00000000 */   nop
.size func_001ff300, 0xb0
