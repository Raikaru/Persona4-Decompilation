.section .text
.set noat
.set noreorder
glabel func_001ec3d0
    /* EC3D0 001EC3D0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* EC3D4 001EC3D4 3000BFFF */  sd         $31, 0x30($29)
    /* EC3D8 001EC3D8 2000B27F */  sq         $18, 0x20($29)
    /* EC3DC 001EC3DC 1000B17F */  sq         $17, 0x10($29)
    /* EC3E0 001EC3E0 0000B07F */  sq         $16, 0x0($29)
    /* EC3E4 001EC3E4 2D908000 */  daddu      $18, $4, $0
    /* EC3E8 001EC3E8 2D88C000 */  daddu      $17, $6, $0
    /* EC3EC 001EC3EC 2D80E000 */  daddu      $16, $7, $0
    /* EC3F0 001EC3F0 000081C4 */  lwc1       $f1, 0x0($4)
    /* EC3F4 001EC3F4 0000A0C4 */  lwc1       $f0, 0x0($5)
    /* EC3F8 001EC3F8 01080046 */  sub.s      $f0, $f1, $f0
    /* EC3FC 001EC3FC 4800A0E7 */  swc1       $f0, 0x48($29)
    /* EC400 001EC400 040081C4 */  lwc1       $f1, 0x4($4)
    /* EC404 001EC404 0400A0C4 */  lwc1       $f0, 0x4($5)
    /* EC408 001EC408 01080046 */  sub.s      $f0, $f1, $f0
    /* EC40C 001EC40C 4C00A0E7 */  swc1       $f0, 0x4C($29)
    /* EC410 001EC410 4800A427 */  addiu      $4, $29, 0x48
    /* EC414 001EC414 2D288000 */  daddu      $5, $4, $0
    /* EC418 001EC418 78900F0C */  jal        func_003e41e0
    /* EC41C 001EC41C 00000000 */   nop
    /* EC420 001EC420 4C00A5C7 */  lwc1       $f5, 0x4C($29)
    /* EC424 001EC424 000024C6 */  lwc1       $f4, 0x0($17)
    /* EC428 001EC428 000040C6 */  lwc1       $f0, 0x0($18)
    /* EC42C 001EC42C C1200046 */  sub.s      $f3, $f4, $f0
    /* EC430 001EC430 040021C6 */  lwc1       $f1, 0x4($17)
    /* EC434 001EC434 040040C6 */  lwc1       $f0, 0x4($18)
    /* EC438 001EC438 41080046 */  sub.s      $f1, $f1, $f0
    /* EC43C 001EC43C 4800A0C7 */  lwc1       $f0, 0x48($29)
    /* EC440 001EC440 07000046 */  neg.s      $f0, $f0
    /* EC444 001EC444 1A080046 */  mula.s     $f1, $f0
    /* EC448 001EC448 00108044 */  mtc1       $0, $f2
    /* EC44C 001EC44C 00000000 */  nop
    /* EC450 001EC450 DC180546 */  madd.s     $f3, $f3, $f5
    /* EC454 001EC454 0A000012 */  beqz       $16, .L001EC480
    /* EC458 001EC458 00000000 */   nop
    /* EC45C 001EC45C 18100446 */  adda.s     $f2, $f4
    /* EC460 001EC460 1D180546 */  msub.s     $f0, $f3, $f5
    /* EC464 001EC464 000000E6 */  swc1       $f0, 0x0($16)
    /* EC468 001EC468 4800A0C7 */  lwc1       $f0, 0x48($29)
    /* EC46C 001EC46C 47000046 */  neg.s      $f1, $f0
    /* EC470 001EC470 040020C6 */  lwc1       $f0, 0x4($17)
    /* EC474 001EC474 18100046 */  adda.s     $f2, $f0
    /* EC478 001EC478 1D180146 */  msub.s     $f0, $f3, $f1
    /* EC47C 001EC47C 040000E6 */  swc1       $f0, 0x4($16)
  .L001EC480:
    /* EC480 001EC480 05180046 */  abs.s      $f0, $f3
    /* EC484 001EC484 3000BFDF */  ld         $31, 0x30($29)
    /* EC488 001EC488 2000B27B */  lq         $18, 0x20($29)
    /* EC48C 001EC48C 1000B17B */  lq         $17, 0x10($29)
    /* EC490 001EC490 0000B07B */  lq         $16, 0x0($29)
    /* EC494 001EC494 5000BD27 */  addiu      $29, $29, 0x50
    /* EC498 001EC498 0800E003 */  jr         $31
    /* EC49C 001EC49C 00000000 */   nop
.size func_001ec3d0, 0xd0
