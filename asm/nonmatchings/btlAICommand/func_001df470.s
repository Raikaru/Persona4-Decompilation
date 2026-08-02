.section .text
.set noat
.set noreorder
glabel func_001df470
    /* DF470 001DF470 E0FFBD27 */  addiu      $29, $29, -0x20
    /* DF474 001DF474 1000BFFF */  sd         $31, 0x10($29)
    /* DF478 001DF478 0000B07F */  sq         $16, 0x0($29)
    /* DF47C 001DF47C 2D200000 */  daddu      $4, $0, $0
    /* DF480 001DF480 00730A0C */  jal        func_0029cc00
    /* DF484 001DF484 00000000 */   nop
    /* DF488 001DF488 3C1A0200 */  dsll32     $3, $2, 8
    /* DF48C 001DF48C 3E1A0300 */  dsrl32     $3, $3, 8
    /* DF490 001DF490 0003023C */  lui        $2, (0x3000000 >> 16)
    /* DF494 001DF494 25806200 */  or         $16, $3, $2
    /* DF498 001DF498 14740A0C */  jal        func_0029d050
    /* DF49C 001DF49C 00000000 */   nop
    /* DF4A0 001DF4A0 00FF033C */  lui        $3, (0xFF000000 >> 16)
    /* DF4A4 001DF4A4 24180302 */  and        $3, $16, $3
    /* DF4A8 001DF4A8 021E0300 */  srl        $3, $3, 24
    /* DF4AC 001DF4AC 3C2A1000 */  dsll32     $5, $16, 8
    /* DF4B0 001DF4B0 3E2A0500 */  dsrl32     $5, $5, 8
    /* DF4B4 001DF4B4 04006014 */  bnez       $3, .L001DF4C8
    /* DF4B8 001DF4B8 00000000 */   nop
    /* DF4BC 001DF4BC 2D100000 */  daddu      $2, $0, $0
    /* DF4C0 001DF4C0 0B000010 */  b          .L001DF4F0
    /* DF4C4 001DF4C4 00000000 */   nop
  .L001DF4C8:
    /* DF4C8 001DF4C8 2D204000 */  daddu      $4, $2, $0
    /* DF4CC 001DF4CC 40100300 */  sll        $2, $3, 1
    /* DF4D0 001DF4D0 21104300 */  addu       $2, $2, $3
    /* DF4D4 001DF4D4 80180200 */  sll        $3, $2, 2
    /* DF4D8 001DF4D8 6100023C */  lui        $2, %hi(D_00609850)
    /* DF4DC 001DF4DC 50984224 */  addiu      $2, $2, %lo(D_00609850)
    /* DF4E0 001DF4E0 21104300 */  addu       $2, $2, $3
    /* DF4E4 001DF4E4 0000428C */  lw         $2, 0x0($2)
    /* DF4E8 001DF4E8 09F84000 */  jalr       $2
    /* DF4EC 001DF4EC 00000000 */   nop
  .L001DF4F0:
    /* DF4F0 001DF4F0 2B200200 */  sltu       $4, $0, $2
    /* DF4F4 001DF4F4 D4730A0C */  jal        func_0029cf50
    /* DF4F8 001DF4F8 00000000 */   nop
    /* DF4FC 001DF4FC 01000224 */  addiu      $2, $0, 0x1
    /* DF500 001DF500 1000BFDF */  ld         $31, 0x10($29)
    /* DF504 001DF504 0000B07B */  lq         $16, 0x0($29)
    /* DF508 001DF508 2000BD27 */  addiu      $29, $29, 0x20
    /* DF50C 001DF50C 0800E003 */  jr         $31
    /* DF510 001DF510 00000000 */   nop
    /* DF514 001DF514 00000000 */  nop
    /* DF518 001DF518 00000000 */  nop
    /* DF51C 001DF51C 00000000 */  nop
.size func_001df470, 0xb0
