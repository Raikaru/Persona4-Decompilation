.section .text
.set noat
.set noreorder
glabel func_001df5d0
    /* DF5D0 001DF5D0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* DF5D4 001DF5D4 1000BFFF */  sd         $31, 0x10($29)
    /* DF5D8 001DF5D8 0000B07F */  sq         $16, 0x0($29)
    /* DF5DC 001DF5DC 2D200000 */  daddu      $4, $0, $0
    /* DF5E0 001DF5E0 00730A0C */  jal        func_0029cc00
    /* DF5E4 001DF5E4 00000000 */   nop
    /* DF5E8 001DF5E8 3C1A0200 */  dsll32     $3, $2, 8
    /* DF5EC 001DF5EC 3E1A0300 */  dsrl32     $3, $3, 8
    /* DF5F0 001DF5F0 0005023C */  lui        $2, (0x5000000 >> 16)
    /* DF5F4 001DF5F4 25806200 */  or         $16, $3, $2
    /* DF5F8 001DF5F8 14740A0C */  jal        func_0029d050
    /* DF5FC 001DF5FC 00000000 */   nop
    /* DF600 001DF600 00FF033C */  lui        $3, (0xFF000000 >> 16)
    /* DF604 001DF604 24180302 */  and        $3, $16, $3
    /* DF608 001DF608 021E0300 */  srl        $3, $3, 24
    /* DF60C 001DF60C 3C2A1000 */  dsll32     $5, $16, 8
    /* DF610 001DF610 3E2A0500 */  dsrl32     $5, $5, 8
    /* DF614 001DF614 04006014 */  bnez       $3, .L001DF628
    /* DF618 001DF618 00000000 */   nop
    /* DF61C 001DF61C 2D100000 */  daddu      $2, $0, $0
    /* DF620 001DF620 0B000010 */  b          .L001DF650
    /* DF624 001DF624 00000000 */   nop
  .L001DF628:
    /* DF628 001DF628 2D204000 */  daddu      $4, $2, $0
    /* DF62C 001DF62C 40100300 */  sll        $2, $3, 1
    /* DF630 001DF630 21104300 */  addu       $2, $2, $3
    /* DF634 001DF634 80180200 */  sll        $3, $2, 2
    /* DF638 001DF638 6100023C */  lui        $2, %hi(D_00609850)
    /* DF63C 001DF63C 50984224 */  addiu      $2, $2, %lo(D_00609850)
    /* DF640 001DF640 21104300 */  addu       $2, $2, $3
    /* DF644 001DF644 0000428C */  lw         $2, 0x0($2)
    /* DF648 001DF648 09F84000 */  jalr       $2
    /* DF64C 001DF64C 00000000 */   nop
  .L001DF650:
    /* DF650 001DF650 2B200200 */  sltu       $4, $0, $2
    /* DF654 001DF654 D4730A0C */  jal        func_0029cf50
    /* DF658 001DF658 00000000 */   nop
    /* DF65C 001DF65C 01000224 */  addiu      $2, $0, 0x1
    /* DF660 001DF660 1000BFDF */  ld         $31, 0x10($29)
    /* DF664 001DF664 0000B07B */  lq         $16, 0x0($29)
    /* DF668 001DF668 2000BD27 */  addiu      $29, $29, 0x20
    /* DF66C 001DF66C 0800E003 */  jr         $31
    /* DF670 001DF670 00000000 */   nop
    /* DF674 001DF674 00000000 */  nop
    /* DF678 001DF678 00000000 */  nop
    /* DF67C 001DF67C 00000000 */  nop
.size func_001df5d0, 0xb0
