.section .text
.set noat
.set noreorder
glabel func_001de640
    /* DE640 001DE640 E0FFBD27 */  addiu      $29, $29, -0x20
    /* DE644 001DE644 1000BFFF */  sd         $31, 0x10($29)
    /* DE648 001DE648 0000B07F */  sq         $16, 0x0($29)
    /* DE64C 001DE64C 2D80A000 */  daddu      $16, $5, $0
    /* DE650 001DE650 FFFFC330 */  andi       $3, $6, 0xFFFF
    /* DE654 001DE654 00F06730 */  andi       $7, $3, 0xF000
    /* DE658 001DE658 00800534 */  ori        $5, $0, 0x8000
    /* DE65C 001DE65C 0400E514 */  bne        $7, $5, .L001DE670
    /* DE660 001DE660 00000000 */   nop
    /* DE664 001DE664 2D28C000 */  daddu      $5, $6, $0
    /* DE668 001DE668 02000010 */  b          .L001DE674
    /* DE66C 001DE66C 00000000 */   nop
  .L001DE670:
    /* DE670 001DE670 FFFFE530 */  andi       $5, $7, 0xFFFF
  .L001DE674:
    /* DE674 001DE674 FFFFA730 */  andi       $7, $5, 0xFFFF
    /* DE678 001DE678 04800534 */  ori        $5, $0, 0x8004
    /* DE67C 001DE67C 5100E510 */  beq        $7, $5, .L001DE7C4
    /* DE680 001DE680 00000000 */   nop
    /* DE684 001DE684 09800534 */  ori        $5, $0, 0x8009
    /* DE688 001DE688 4900E510 */  beq        $7, $5, .L001DE7B0
    /* DE68C 001DE68C 00000000 */   nop
    /* DE690 001DE690 08800534 */  ori        $5, $0, 0x8008
    /* DE694 001DE694 4200E510 */  beq        $7, $5, .L001DE7A0
    /* DE698 001DE698 00000000 */   nop
    /* DE69C 001DE69C 01800534 */  ori        $5, $0, 0x8001
    /* DE6A0 001DE6A0 3B00E510 */  beq        $7, $5, .L001DE790
    /* DE6A4 001DE6A4 00000000 */   nop
    /* DE6A8 001DE6A8 06800534 */  ori        $5, $0, 0x8006
    /* DE6AC 001DE6AC 3400E510 */  beq        $7, $5, .L001DE780
    /* DE6B0 001DE6B0 00000000 */   nop
    /* DE6B4 001DE6B4 05800534 */  ori        $5, $0, 0x8005
    /* DE6B8 001DE6B8 4A00E510 */  beq        $7, $5, .L001DE7E4
    /* DE6BC 001DE6BC 00000000 */   nop
    /* DE6C0 001DE6C0 07800534 */  ori        $5, $0, 0x8007
    /* DE6C4 001DE6C4 2A00E510 */  beq        $7, $5, .L001DE770
    /* DE6C8 001DE6C8 00000000 */   nop
    /* DE6CC 001DE6CC 02800534 */  ori        $5, $0, 0x8002
    /* DE6D0 001DE6D0 2300E510 */  beq        $7, $5, .L001DE760
    /* DE6D4 001DE6D4 00000000 */   nop
    /* DE6D8 001DE6D8 00200524 */  addiu      $5, $0, 0x2000
    /* DE6DC 001DE6DC 1C00E510 */  beq        $7, $5, .L001DE750
    /* DE6E0 001DE6E0 00000000 */   nop
    /* DE6E4 001DE6E4 00100524 */  addiu      $5, $0, 0x1000
    /* DE6E8 001DE6E8 0F00E510 */  beq        $7, $5, .L001DE728
    /* DE6EC 001DE6EC 00000000 */   nop
    /* DE6F0 001DE6F0 00800334 */  ori        $3, $0, 0x8000
    /* DE6F4 001DE6F4 0300E310 */  beq        $7, $3, .L001DE704
    /* DE6F8 001DE6F8 00000000 */   nop
    /* DE6FC 001DE6FC 36000010 */  b          .L001DE7D8
    /* DE700 001DE700 00000000 */   nop
  .L001DE704:
    /* DE704 001DE704 01000224 */  addiu      $2, $0, 0x1
    /* DE708 001DE708 340002A6 */  sh         $2, 0x34($16)
    /* DE70C 001DE70C 3000828C */  lw         $2, 0x30($4)
    /* DE710 001DE710 640A448C */  lw         $4, 0xA64($2)
    /* DE714 001DE714 F8F7080C */  jal        func_0023dfe0
    /* DE718 001DE718 00000000 */   nop
    /* DE71C 001DE71C 360002A6 */  sh         $2, 0x36($16)
    /* DE720 001DE720 30000010 */  b          .L001DE7E4
    /* DE724 001DE724 00000000 */   nop
  .L001DE728:
    /* DE728 001DE728 09000424 */  addiu      $4, $0, 0x9
    /* DE72C 001DE72C 340004A6 */  sh         $4, 0x34($16)
    /* DE730 001DE730 11010424 */  addiu      $4, $0, 0x111
    /* DE734 001DE734 360004A6 */  sh         $4, 0x36($16)
    /* DE738 001DE738 FFFF043C */  lui        $4, (0xFFFF0FFF >> 16)
    /* DE73C 001DE73C FF0F8434 */  ori        $4, $4, (0xFFFF0FFF & 0xFFFF)
    /* DE740 001DE740 24186400 */  and        $3, $3, $4
    /* DE744 001DE744 3E0003A6 */  sh         $3, 0x3E($16)
    /* DE748 001DE748 26000010 */  b          .L001DE7E4
    /* DE74C 001DE74C 00000000 */   nop
  .L001DE750:
    /* DE750 001DE750 FFFF053C */  lui        $5, (0xFFFF0FFF >> 16)
    /* DE754 001DE754 FF0FA534 */  ori        $5, $5, (0xFFFF0FFF & 0xFFFF)
    /* DE758 001DE758 24186500 */  and        $3, $3, $5
    /* DE75C 001DE75C EC0083A4 */  sh         $3, 0xEC($4)
  .L001DE760:
    /* DE760 001DE760 07000324 */  addiu      $3, $0, 0x7
    /* DE764 001DE764 340003A6 */  sh         $3, 0x34($16)
    /* DE768 001DE768 1E000010 */  b          .L001DE7E4
    /* DE76C 001DE76C 00000000 */   nop
  .L001DE770:
    /* DE770 001DE770 08000324 */  addiu      $3, $0, 0x8
    /* DE774 001DE774 340003A6 */  sh         $3, 0x34($16)
    /* DE778 001DE778 1A000010 */  b          .L001DE7E4
    /* DE77C 001DE77C 00000000 */   nop
  .L001DE780:
    /* DE780 001DE780 0B000324 */  addiu      $3, $0, 0xB
    /* DE784 001DE784 340003A6 */  sh         $3, 0x34($16)
    /* DE788 001DE788 16000010 */  b          .L001DE7E4
    /* DE78C 001DE78C 00000000 */   nop
  .L001DE790:
    /* DE790 001DE790 06000324 */  addiu      $3, $0, 0x6
    /* DE794 001DE794 340003A6 */  sh         $3, 0x34($16)
    /* DE798 001DE798 12000010 */  b          .L001DE7E4
    /* DE79C 001DE79C 00000000 */   nop
  .L001DE7A0:
    /* DE7A0 001DE7A0 0C000324 */  addiu      $3, $0, 0xC
    /* DE7A4 001DE7A4 340003A6 */  sh         $3, 0x34($16)
    /* DE7A8 001DE7A8 0E000010 */  b          .L001DE7E4
    /* DE7AC 001DE7AC 00000000 */   nop
  .L001DE7B0:
    /* DE7B0 001DE7B0 2D280002 */  daddu      $5, $16, $0
    /* DE7B4 001DE7B4 00AF070C */  jal        func_001ebc00
    /* DE7B8 001DE7B8 00000000 */   nop
    /* DE7BC 001DE7BC 09000010 */  b          .L001DE7E4
    /* DE7C0 001DE7C0 00000000 */   nop
  .L001DE7C4:
    /* DE7C4 001DE7C4 3000828C */  lw         $2, 0x30($4)
    /* DE7C8 001DE7C8 640A448C */  lw         $4, 0xA64($2)
    /* DE7CC 001DE7CC FCF7080C */  jal        func_0023dff0
    /* DE7D0 001DE7D0 00000000 */   nop
    /* DE7D4 001DE7D4 FFFF4630 */  andi       $6, $2, 0xFFFF
  .L001DE7D8:
    /* DE7D8 001DE7D8 02000324 */  addiu      $3, $0, 0x2
    /* DE7DC 001DE7DC 340003A6 */  sh         $3, 0x34($16)
    /* DE7E0 001DE7E0 360006A6 */  sh         $6, 0x36($16)
  .L001DE7E4:
    /* DE7E4 001DE7E4 1000BFDF */  ld         $31, 0x10($29)
    /* DE7E8 001DE7E8 0000B07B */  lq         $16, 0x0($29)
    /* DE7EC 001DE7EC 2000BD27 */  addiu      $29, $29, 0x20
    /* DE7F0 001DE7F0 0800E003 */  jr         $31
    /* DE7F4 001DE7F4 00000000 */   nop
    /* DE7F8 001DE7F8 00000000 */  nop
    /* DE7FC 001DE7FC 00000000 */  nop
.size func_001de640, 0x1c0
