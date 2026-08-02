.section .text
.set noat
.set noreorder
glabel func_001ff3b0
    /* FF3B0 001FF3B0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* FF3B4 001FF3B4 2000BFFF */  sd         $31, 0x20($29)
    /* FF3B8 001FF3B8 1000B17F */  sq         $17, 0x10($29)
    /* FF3BC 001FF3BC 0000B07F */  sq         $16, 0x0($29)
    /* FF3C0 001FF3C0 3000908C */  lw         $16, 0x30($4)
    /* FF3C4 001FF3C4 6200043C */  lui        $4, %hi(D_00625230)
    /* FF3C8 001FF3C8 30528424 */  addiu      $4, $4, %lo(D_00625230)
    /* FF3CC 001FF3CC 29040524 */  addiu      $5, $0, 0x429
    /* FF3D0 001FF3D0 A43A110C */  jal        func_0044ea90
    /* FF3D4 001FF3D4 00000000 */   nop
    /* FF3D8 001FF3D8 24000424 */  addiu      $4, $0, 0x24
    /* FF3DC 001FF3DC 0400053C */  lui        $5, (0x40000 >> 16)
    /* FF3E0 001FF3E0 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* FF3E4 001FF3E4 E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* FF3E8 001FF3E8 09F84000 */  jalr       $2
    /* FF3EC 001FF3EC 00000000 */   nop
    /* FF3F0 001FF3F0 2D884000 */  daddu      $17, $2, $0
    /* FF3F4 001FF3F4 0000048E */  lw         $4, 0x0($16)
    /* FF3F8 001FF3F8 06008010 */  beqz       $4, .L001FF414
    /* FF3FC 001FF3FC 00000000 */   nop
    /* FF400 001FF400 60AF120C */  jal        func_004abd80
    /* FF404 001FF404 00000000 */   nop
    /* FF408 001FF408 000022AE */  sw         $2, 0x0($17)
    /* FF40C 001FF40C 02000010 */  b          .L001FF418
    /* FF410 001FF410 00000000 */   nop
  .L001FF414:
    /* FF414 001FF414 000020AE */  sw         $0, 0x0($17)
  .L001FF418:
    /* FF418 001FF418 2D102002 */  daddu      $2, $17, $0
    /* FF41C 001FF41C 2000BFDF */  ld         $31, 0x20($29)
    /* FF420 001FF420 1000B17B */  lq         $17, 0x10($29)
    /* FF424 001FF424 0000B07B */  lq         $16, 0x0($29)
    /* FF428 001FF428 3000BD27 */  addiu      $29, $29, 0x30
    /* FF42C 001FF42C 0800E003 */  jr         $31
    /* FF430 001FF430 00000000 */   nop
    /* FF434 001FF434 00000000 */  nop
    /* FF438 001FF438 00000000 */  nop
    /* FF43C 001FF43C 00000000 */  nop
.size func_001ff3b0, 0x90
