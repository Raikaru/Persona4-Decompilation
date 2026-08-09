.section .text
.set noat
.set noreorder
glabel func_001ce390
    /* CE390 001CE390 C0FFBD27 */  addiu      $29, $29, -0x40
    /* CE394 001CE394 2000BFFF */  sd         $31, 0x20($29)
    /* CE398 001CE398 1000B17F */  sq         $17, 0x10($29)
    /* CE39C 001CE39C 0000B07F */  sq         $16, 0x0($29)
    /* CE3A0 001CE3A0 2D888000 */  daddu      $17, $4, $0
    /* CE3A4 001CE3A4 E000848C */  lw         $4, 0xE0($4)
    /* CE3A8 001CE3A8 17008010 */  beqz       $4, .L001CE408
    /* CE3AC 001CE3AC 00000000 */   nop
    /* CE3B0 001CE3B0 1A008394 */  lhu        $3, 0x1A($4)
    /* CE3B4 001CE3B4 01006330 */  andi       $3, $3, 0x1
    /* CE3B8 001CE3B8 13006010 */  beqz       $3, .L001CE408
    /* CE3BC 001CE3BC 00000000 */   nop
    /* CE3C0 001CE3C0 3000908C */  lw         $16, 0x30($4)
    /* CE3C4 001CE3C4 2D200002 */  daddu      $4, $16, $0
    /* CE3C8 001CE3C8 3000A527 */  addiu      $5, $29, 0x30
    /* CE3CC 001CE3CC 1456060C */  jal        func_00195850
    /* CE3D0 001CE3D0 00000000 */   nop
    /* CE3D4 001CE3D4 900001C6 */  lwc1       $f1, 0x90($16)
    /* CE3D8 001CE3D8 2C0000C6 */  lwc1       $f0, 0x2C($16)
    /* CE3DC 001CE3DC 42080046 */  mul.s      $f1, $f1, $f0
    /* CE3E0 001CE3E0 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CE3E4 001CE3E4 00008244 */  mtc1       $2, $f0
    /* CE3E8 001CE3E8 00000000 */  nop
    /* CE3EC 001CE3EC 02030146 */  mul.s      $f12, $f0, $f1
    /* CE3F0 001CE3F0 E000248E */  lw         $4, 0xE0($17)
    /* CE3F4 001CE3F4 9C002526 */  addiu      $5, $17, 0x9C
    /* CE3F8 001CE3F8 3000A627 */  addiu      $6, $29, 0x30
    /* CE3FC 001CE3FC C1000724 */  addiu      $7, $0, 0xC1
    /* CE400 001CE400 50F3060C */  jal        func_001bcd40
    /* CE404 001CE404 00000000 */   nop
  .L001CE408:
    /* CE408 001CE408 2000BFDF */  ld         $31, 0x20($29)
    /* CE40C 001CE40C 1000B17B */  lq         $17, 0x10($29)
    /* CE410 001CE410 0000B07B */  lq         $16, 0x0($29)
    /* CE414 001CE414 4000BD27 */  addiu      $29, $29, 0x40
    /* CE418 001CE418 0800E003 */  jr         $31
    /* CE41C 001CE41C 00000000 */   nop
    /* CE420 001CE420 0800E003 */  jr         $31
    /* CE424 001CE424 00000000 */   nop
    /* CE428 001CE428 00000000 */  nop
    /* CE42C 001CE42C 00000000 */  nop
.size func_001ce390, 0xa0
