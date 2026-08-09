.section .text
.set noat
.set noreorder
glabel func_003dc610
    /* 2DC610 003DC610 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2DC614 003DC614 1000BFFF */  sd         $31, 0x10($29)
    /* 2DC618 003DC618 0000B07F */  sq         $16, 0x0($29)
    /* 2DC61C 003DC61C 2B800400 */  sltu       $16, $0, $4
    /* 2DC620 003DC620 02000012 */  beqz       $16, .L003DC62C
    /* 2DC624 003DC624 00000000 */   nop
    /* 2DC628 003DC628 2B800500 */  sltu       $16, $0, $5
  .L003DC62C:
    /* 2DC62C 003DC62C 21000012 */  beqz       $16, .L003DC6B4
    /* 2DC630 003DC630 00000000 */   nop
    /* 2DC634 003DC634 1400A5C4 */  lwc1       $f5, 0x14($5)
    /* 2DC638 003DC638 0000A4C4 */  lwc1       $f4, 0x0($5)
    /* 2DC63C 003DC63C 2800A3C4 */  lwc1       $f3, 0x28($5)
    /* 2DC640 003DC640 00008044 */  mtc1       $0, $f0
    /* 2DC644 003DC644 40200546 */  add.s      $f1, $f4, $f5
    /* 2DC648 003DC648 80180146 */  add.s      $f2, $f3, $f1
    /* 2DC64C 003DC64C 36100046 */  c.le.s     $f2, $f0
    /* 2DC650 003DC650 1A000045 */  bc1f       .L003DC6BC
    /* 2DC654 003DC654 00000000 */   nop
    /* 2DC658 003DC658 36200546 */  c.le.s     $f4, $f5
    /* 2DC65C 003DC65C 0B000145 */  bc1t       .L003DC68C
    /* 2DC660 003DC660 00000000 */   nop
    /* 2DC664 003DC664 36200346 */  c.le.s     $f4, $f3
    /* 2DC668 003DC668 04000145 */  bc1t       .L003DC67C
    /* 2DC66C 003DC66C 00000000 */   nop
    /* 2DC670 003DC670 3E00023C */  lui        $2, %hi(func_003dc490)
    /* 2DC674 003DC674 03000010 */  b          .L003DC684
    /* 2DC678 003DC678 90C44224 */   addiu     $2, $2, %lo(func_003dc490)
  .L003DC67C:
    /* 2DC67C 003DC67C 3E00023C */  lui        $2, %hi(func_003dc590)
    /* 2DC680 003DC680 90C54224 */  addiu      $2, $2, %lo(func_003dc590)
  .L003DC684:
    /* 2DC684 003DC684 09000010 */  b          .L003DC6AC
    /* 2DC688 003DC688 00000000 */   nop
  .L003DC68C:
    /* 2DC68C 003DC68C 36280346 */  c.le.s     $f5, $f3
    /* 2DC690 003DC690 04000145 */  bc1t       .L003DC6A4
    /* 2DC694 003DC694 00000000 */   nop
    /* 2DC698 003DC698 3E00023C */  lui        $2, %hi(func_003dc510)
    /* 2DC69C 003DC69C 03000010 */  b          .L003DC6AC
    /* 2DC6A0 003DC6A0 10C54224 */   addiu     $2, $2, %lo(func_003dc510)
  .L003DC6A4:
    /* 2DC6A4 003DC6A4 3E00023C */  lui        $2, %hi(func_003dc590)
    /* 2DC6A8 003DC6A8 90C54224 */  addiu      $2, $2, %lo(func_003dc590)
  .L003DC6AC:
    /* 2DC6AC 003DC6AC 09F84000 */  jalr       $2
    /* 2DC6B0 003DC6B0 00000000 */   nop
  .L003DC6B4:
    /* 2DC6B4 003DC6B4 1B000010 */  b          .L003DC724
    /* 2DC6B8 003DC6B8 2D100002 */   daddu     $2, $16, $0
  .L003DC6BC:
    /* 2DC6BC 003DC6BC 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* 2DC6C0 003DC6C0 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* 2DC6C4 003DC6C4 00008344 */  mtc1       $3, $f0
    /* 2DC6C8 003DC6C8 00088244 */  mtc1       $2, $f1
    /* 2DC6CC 003DC6CC 00000000 */  nop
    /* 2DC6D0 003DC6D0 00000246 */  add.s      $f0, $f0, $f2
    /* 2DC6D4 003DC6D4 84000046 */  c1         0x84
    /* 2DC6D8 003DC6D8 83090246 */  div.s      $f6, $f1, $f2
    /* 2DC6DC 003DC6DC 02080246 */  mul.s      $f0, $f1, $f2
    /* 2DC6E0 003DC6E0 0C0080E4 */  swc1       $f0, 0xC($4)
    /* 2DC6E4 003DC6E4 1800A5C4 */  lwc1       $f5, 0x18($5)
    /* 2DC6E8 003DC6E8 2400A4C4 */  lwc1       $f4, 0x24($5)
    /* 2DC6EC 003DC6EC 0400A1C4 */  lwc1       $f1, 0x4($5)
    /* 2DC6F0 003DC6F0 1000A0C4 */  lwc1       $f0, 0x10($5)
    /* 2DC6F4 003DC6F4 2000A3C4 */  lwc1       $f3, 0x20($5)
    /* 2DC6F8 003DC6F8 0800A2C4 */  lwc1       $f2, 0x8($5)
    /* 2DC6FC 003DC6FC 01290446 */  sub.s      $f4, $f5, $f4
    /* 2DC700 003DC700 01080046 */  sub.s      $f0, $f1, $f0
    /* 2DC704 003DC704 42300446 */  mul.s      $f1, $f6, $f4
    /* 2DC708 003DC708 81180246 */  sub.s      $f2, $f3, $f2
    /* 2DC70C 003DC70C 000081E4 */  swc1       $f1, 0x0($4)
    /* 2DC710 003DC710 42300246 */  mul.s      $f1, $f6, $f2
    /* 2DC714 003DC714 02300046 */  mul.s      $f0, $f6, $f0
    /* 2DC718 003DC718 040081E4 */  swc1       $f1, 0x4($4)
    /* 2DC71C 003DC71C E5FF0010 */  b          .L003DC6B4
    /* 2DC720 003DC720 080080E4 */   swc1      $f0, 0x8($4)
  .L003DC724:
    /* 2DC724 003DC724 1000BFDF */  ld         $31, 0x10($29)
    /* 2DC728 003DC728 0000B07B */  lq         $16, 0x0($29)
    /* 2DC72C 003DC72C 0800E003 */  jr         $31
    /* 2DC730 003DC730 2000BD27 */   addiu     $29, $29, 0x20
    /* 2DC734 003DC734 00000000 */  nop
    /* 2DC738 003DC738 00000000 */  nop
    /* 2DC73C 003DC73C 00000000 */  nop
.size func_003dc610, 0x130
