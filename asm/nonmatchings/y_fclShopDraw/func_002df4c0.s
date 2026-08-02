.section .text
.set noat
.set noreorder
glabel func_002df4c0
    /* 1DF4C0 002DF4C0 50FFBD27 */  addiu      $29, $29, -0xB0
    /* 1DF4C4 002DF4C4 2000BFFF */  sd         $31, 0x20($29)
    /* 1DF4C8 002DF4C8 1000B17F */  sq         $17, 0x10($29)
    /* 1DF4CC 002DF4CC 0000B07F */  sq         $16, 0x0($29)
    /* 1DF4D0 002DF4D0 3800908C */  lw         $16, 0x38($4)
    /* 1DF4D4 002DF4D4 240C0382 */  lb         $3, 0xC24($16)
    /* 1DF4D8 002DF4D8 01000224 */  addiu      $2, $0, 0x1
    /* 1DF4DC 002DF4DC FF006214 */  bne        $3, $2, .L002DF8DC
    /* 1DF4E0 002DF4E0 00000000 */   nop
    /* 1DF4E4 002DF4E4 280F048E */  lw         $4, 0xF28($16)
    /* 1DF4E8 002DF4E8 2B000524 */  addiu      $5, $0, 0x2B
    /* 1DF4EC 002DF4EC 80B4110C */  jal        func_0046d200
    /* 1DF4F0 002DF4F0 00000000 */   nop
    /* 1DF4F4 002DF4F4 2D884000 */  daddu      $17, $2, $0
    /* 1DF4F8 002DF4F8 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1DF4FC 002DF4FC 00608244 */  mtc1       $2, $f12
    /* 1DF500 002DF500 00788044 */  mtc1       $0, $f15
    /* 1DF504 002DF504 E40C048E */  lw         $4, 0xCE4($16)
    /* 1DF508 002DF508 46630046 */  mov.s      $f13, $f12
    /* 1DF50C 002DF50C 86630046 */  mov.s      $f14, $f12
    /* 1DF510 002DF510 2D280000 */  daddu      $5, $0, $0
    /* 1DF514 002DF514 05000624 */  addiu      $6, $0, 0x5
    /* 1DF518 002DF518 2D380000 */  daddu      $7, $0, $0
    /* 1DF51C 002DF51C B4810B0C */  jal        func_002e06d0
    /* 1DF520 002DF520 00000000 */   nop
    /* 1DF524 002DF524 8642023C */  lui        $2, (0x42860000 >> 16)
    /* 1DF528 002DF528 00608244 */  mtc1       $2, $f12
    /* 1DF52C 002DF52C 0C43023C */  lui        $2, (0x430C0000 >> 16)
    /* 1DF530 002DF530 00688244 */  mtc1       $2, $f13
    /* 1DF534 002DF534 A800A427 */  addiu      $4, $29, 0xA8
    /* 1DF538 002DF538 5CCA0A0C */  jal        func_002b2970
    /* 1DF53C 002DF53C 00000000 */   nop
    /* 1DF540 002DF540 2D202002 */  daddu      $4, $17, $0
    /* 1DF544 002DF544 BCAC110C */  jal        func_0046b2f0
    /* 1DF548 002DF548 00000000 */   nop
    /* 1DF54C 002DF54C 2041023C */  lui        $2, (0x41200000 >> 16)
    /* 1DF550 002DF550 00088244 */  mtc1       $2, $f1
    /* 1DF554 002DF554 00000000 */  nop
    /* 1DF558 002DF558 C3000146 */  div.s      $f3, $f0, $f1
    /* 1DF55C 002DF55C A040023C */  lui        $2, (0x40A00000 >> 16)
    /* 1DF560 002DF560 00108244 */  mtc1       $2, $f2
    /* 1DF564 002DF564 0C43023C */  lui        $2, (0x430C0000 >> 16)
    /* 1DF568 002DF568 00088244 */  mtc1       $2, $f1
    /* 1DF56C 002DF56C 00008044 */  mtc1       $0, $f0
    /* 1DF570 002DF570 00000000 */  nop
    /* 1DF574 002DF574 18000146 */  adda.s     $f0, $f1
    /* 1DF578 002DF578 5C130346 */  madd.s     $f13, $f2, $f3
    /* 1DF57C 002DF57C 8642023C */  lui        $2, (0x42860000 >> 16)
    /* 1DF580 002DF580 00608244 */  mtc1       $2, $f12
    /* 1DF584 002DF584 A000A427 */  addiu      $4, $29, 0xA0
    /* 1DF588 002DF588 5CCA0A0C */  jal        func_002b2970
    /* 1DF58C 002DF58C 00000000 */   nop
    /* 1DF590 002DF590 E40C048E */  lw         $4, 0xCE4($16)
    /* 1DF594 002DF594 A800A5DF */  ld         $5, 0xA8($29)
    /* 1DF598 002DF598 A000A6DF */  ld         $6, 0xA0($29)
    /* 1DF59C 002DF59C 2D380000 */  daddu      $7, $0, $0
    /* 1DF5A0 002DF5A0 05000824 */  addiu      $8, $0, 0x5
    /* 1DF5A4 002DF5A4 2D480000 */  daddu      $9, $0, $0
    /* 1DF5A8 002DF5A8 88810B0C */  jal        func_002e0620
    /* 1DF5AC 002DF5AC 00000000 */   nop
    /* 1DF5B0 002DF5B0 E40C048E */  lw         $4, 0xCE4($16)
    /* 1DF5B4 002DF5B4 FF000524 */  addiu      $5, $0, 0xFF
    /* 1DF5B8 002DF5B8 2D300000 */  daddu      $6, $0, $0
    /* 1DF5BC 002DF5BC 2D380000 */  daddu      $7, $0, $0
    /* 1DF5C0 002DF5C0 05000824 */  addiu      $8, $0, 0x5
    /* 1DF5C4 002DF5C4 2D480000 */  daddu      $9, $0, $0
    /* 1DF5C8 002DF5C8 98810B0C */  jal        func_002e0660
    /* 1DF5CC 002DF5CC 00000000 */   nop
    /* 1DF5D0 002DF5D0 2D202002 */  daddu      $4, $17, $0
    /* 1DF5D4 002DF5D4 A0B4110C */  jal        func_0046d280
    /* 1DF5D8 002DF5D8 00000000 */   nop
    /* 1DF5DC 002DF5DC 280F048E */  lw         $4, 0xF28($16)
    /* 1DF5E0 002DF5E0 2C000524 */  addiu      $5, $0, 0x2C
    /* 1DF5E4 002DF5E4 80B4110C */  jal        func_0046d200
    /* 1DF5E8 002DF5E8 00000000 */   nop
    /* 1DF5EC 002DF5EC 2D884000 */  daddu      $17, $2, $0
    /* 1DF5F0 002DF5F0 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1DF5F4 002DF5F4 00608244 */  mtc1       $2, $f12
    /* 1DF5F8 002DF5F8 00788044 */  mtc1       $0, $f15
    /* 1DF5FC 002DF5FC E80C048E */  lw         $4, 0xCE8($16)
    /* 1DF600 002DF600 46630046 */  mov.s      $f13, $f12
    /* 1DF604 002DF604 86630046 */  mov.s      $f14, $f12
    /* 1DF608 002DF608 2D280000 */  daddu      $5, $0, $0
    /* 1DF60C 002DF60C 05000624 */  addiu      $6, $0, 0x5
    /* 1DF610 002DF610 2D380000 */  daddu      $7, $0, $0
    /* 1DF614 002DF614 B4810B0C */  jal        func_002e06d0
    /* 1DF618 002DF618 00000000 */   nop
    /* 1DF61C 002DF61C 2F020224 */  addiu      $2, $0, 0x22F
    /* 1DF620 002DF620 00008244 */  mtc1       $2, $f0
    /* 1DF624 002DF624 00000000 */  nop
    /* 1DF628 002DF628 20038046 */  cvt.s.w    $f12, $f0
    /* 1DF62C 002DF62C 0C43023C */  lui        $2, (0x430C0000 >> 16)
    /* 1DF630 002DF630 00688244 */  mtc1       $2, $f13
    /* 1DF634 002DF634 9800A427 */  addiu      $4, $29, 0x98
    /* 1DF638 002DF638 5CCA0A0C */  jal        func_002b2970
    /* 1DF63C 002DF63C 00000000 */   nop
    /* 1DF640 002DF640 2D202002 */  daddu      $4, $17, $0
    /* 1DF644 002DF644 BCAC110C */  jal        func_0046b2f0
    /* 1DF648 002DF648 00000000 */   nop
    /* 1DF64C 002DF64C 2041023C */  lui        $2, (0x41200000 >> 16)
    /* 1DF650 002DF650 00088244 */  mtc1       $2, $f1
    /* 1DF654 002DF654 00000000 */  nop
    /* 1DF658 002DF658 C3000146 */  div.s      $f3, $f0, $f1
    /* 1DF65C 002DF65C A040023C */  lui        $2, (0x40A00000 >> 16)
    /* 1DF660 002DF660 00108244 */  mtc1       $2, $f2
    /* 1DF664 002DF664 0C43023C */  lui        $2, (0x430C0000 >> 16)
    /* 1DF668 002DF668 00088244 */  mtc1       $2, $f1
    /* 1DF66C 002DF66C 00008044 */  mtc1       $0, $f0
    /* 1DF670 002DF670 00000000 */  nop
    /* 1DF674 002DF674 18000146 */  adda.s     $f0, $f1
    /* 1DF678 002DF678 5C130346 */  madd.s     $f13, $f2, $f3
    /* 1DF67C 002DF67C 2F020224 */  addiu      $2, $0, 0x22F
    /* 1DF680 002DF680 00008244 */  mtc1       $2, $f0
    /* 1DF684 002DF684 00000000 */  nop
    /* 1DF688 002DF688 20038046 */  cvt.s.w    $f12, $f0
    /* 1DF68C 002DF68C 9000A427 */  addiu      $4, $29, 0x90
    /* 1DF690 002DF690 5CCA0A0C */  jal        func_002b2970
    /* 1DF694 002DF694 00000000 */   nop
    /* 1DF698 002DF698 E80C048E */  lw         $4, 0xCE8($16)
    /* 1DF69C 002DF69C 9800A5DF */  ld         $5, 0x98($29)
    /* 1DF6A0 002DF6A0 9000A6DF */  ld         $6, 0x90($29)
    /* 1DF6A4 002DF6A4 2D380000 */  daddu      $7, $0, $0
    /* 1DF6A8 002DF6A8 05000824 */  addiu      $8, $0, 0x5
    /* 1DF6AC 002DF6AC 2D480000 */  daddu      $9, $0, $0
    /* 1DF6B0 002DF6B0 88810B0C */  jal        func_002e0620
    /* 1DF6B4 002DF6B4 00000000 */   nop
    /* 1DF6B8 002DF6B8 E80C048E */  lw         $4, 0xCE8($16)
    /* 1DF6BC 002DF6BC FF000524 */  addiu      $5, $0, 0xFF
    /* 1DF6C0 002DF6C0 2D300000 */  daddu      $6, $0, $0
    /* 1DF6C4 002DF6C4 2D380000 */  daddu      $7, $0, $0
    /* 1DF6C8 002DF6C8 05000824 */  addiu      $8, $0, 0x5
    /* 1DF6CC 002DF6CC 2D480000 */  daddu      $9, $0, $0
    /* 1DF6D0 002DF6D0 98810B0C */  jal        func_002e0660
    /* 1DF6D4 002DF6D4 00000000 */   nop
    /* 1DF6D8 002DF6D8 2D202002 */  daddu      $4, $17, $0
    /* 1DF6DC 002DF6DC A0B4110C */  jal        func_0046d280
    /* 1DF6E0 002DF6E0 00000000 */   nop
    /* 1DF6E4 002DF6E4 280F048E */  lw         $4, 0xF28($16)
    /* 1DF6E8 002DF6E8 28000524 */  addiu      $5, $0, 0x28
    /* 1DF6EC 002DF6EC 80B4110C */  jal        func_0046d200
    /* 1DF6F0 002DF6F0 00000000 */   nop
    /* 1DF6F4 002DF6F4 2D884000 */  daddu      $17, $2, $0
    /* 1DF6F8 002DF6F8 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1DF6FC 002DF6FC 00608244 */  mtc1       $2, $f12
    /* 1DF700 002DF700 00788044 */  mtc1       $0, $f15
    /* 1DF704 002DF704 D80C048E */  lw         $4, 0xCD8($16)
    /* 1DF708 002DF708 46630046 */  mov.s      $f13, $f12
    /* 1DF70C 002DF70C 86630046 */  mov.s      $f14, $f12
    /* 1DF710 002DF710 2D280000 */  daddu      $5, $0, $0
    /* 1DF714 002DF714 05000624 */  addiu      $6, $0, 0x5
    /* 1DF718 002DF718 2D380000 */  daddu      $7, $0, $0
    /* 1DF71C 002DF71C B4810B0C */  jal        func_002e06d0
    /* 1DF720 002DF720 00000000 */   nop
    /* 1DF724 002DF724 D80C048E */  lw         $4, 0xCD8($16)
    /* 1DF728 002DF728 FF000524 */  addiu      $5, $0, 0xFF
    /* 1DF72C 002DF72C 2D300000 */  daddu      $6, $0, $0
    /* 1DF730 002DF730 2D380000 */  daddu      $7, $0, $0
    /* 1DF734 002DF734 05000824 */  addiu      $8, $0, 0x5
    /* 1DF738 002DF738 2D480000 */  daddu      $9, $0, $0
    /* 1DF73C 002DF73C 98810B0C */  jal        func_002e0660
    /* 1DF740 002DF740 00000000 */   nop
    /* 1DF744 002DF744 4042023C */  lui        $2, (0x42400000 >> 16)
    /* 1DF748 002DF748 00608244 */  mtc1       $2, $f12
    /* 1DF74C 002DF74C FE42023C */  lui        $2, (0x42FE0000 >> 16)
    /* 1DF750 002DF750 00688244 */  mtc1       $2, $f13
    /* 1DF754 002DF754 8800A427 */  addiu      $4, $29, 0x88
    /* 1DF758 002DF758 5CCA0A0C */  jal        func_002b2970
    /* 1DF75C 002DF75C 00000000 */   nop
    /* 1DF760 002DF760 2D202002 */  daddu      $4, $17, $0
    /* 1DF764 002DF764 BCAC110C */  jal        func_0046b2f0
    /* 1DF768 002DF768 00000000 */   nop
    /* 1DF76C 002DF76C 2041023C */  lui        $2, (0x41200000 >> 16)
    /* 1DF770 002DF770 00088244 */  mtc1       $2, $f1
    /* 1DF774 002DF774 00000000 */  nop
    /* 1DF778 002DF778 C3000146 */  div.s      $f3, $f0, $f1
    /* 1DF77C 002DF77C 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1DF780 002DF780 00108244 */  mtc1       $2, $f2
    /* 1DF784 002DF784 FE42023C */  lui        $2, (0x42FE0000 >> 16)
    /* 1DF788 002DF788 00088244 */  mtc1       $2, $f1
    /* 1DF78C 002DF78C 00008044 */  mtc1       $0, $f0
    /* 1DF790 002DF790 00000000 */  nop
    /* 1DF794 002DF794 18000146 */  adda.s     $f0, $f1
    /* 1DF798 002DF798 5C130346 */  madd.s     $f13, $f2, $f3
    /* 1DF79C 002DF79C 4042023C */  lui        $2, (0x42400000 >> 16)
    /* 1DF7A0 002DF7A0 00608244 */  mtc1       $2, $f12
    /* 1DF7A4 002DF7A4 8000A427 */  addiu      $4, $29, 0x80
    /* 1DF7A8 002DF7A8 5CCA0A0C */  jal        func_002b2970
    /* 1DF7AC 002DF7AC 00000000 */   nop
    /* 1DF7B0 002DF7B0 D80C048E */  lw         $4, 0xCD8($16)
    /* 1DF7B4 002DF7B4 8800A5DF */  ld         $5, 0x88($29)
    /* 1DF7B8 002DF7B8 8000A6DF */  ld         $6, 0x80($29)
    /* 1DF7BC 002DF7BC 2D380000 */  daddu      $7, $0, $0
    /* 1DF7C0 002DF7C0 05000824 */  addiu      $8, $0, 0x5
    /* 1DF7C4 002DF7C4 2D480000 */  daddu      $9, $0, $0
    /* 1DF7C8 002DF7C8 88810B0C */  jal        func_002e0620
    /* 1DF7CC 002DF7CC 00000000 */   nop
    /* 1DF7D0 002DF7D0 2D202002 */  daddu      $4, $17, $0
    /* 1DF7D4 002DF7D4 A0B4110C */  jal        func_0046d280
    /* 1DF7D8 002DF7D8 00000000 */   nop
    /* 1DF7DC 002DF7DC 280F048E */  lw         $4, 0xF28($16)
    /* 1DF7E0 002DF7E0 29000524 */  addiu      $5, $0, 0x29
    /* 1DF7E4 002DF7E4 80B4110C */  jal        func_0046d200
    /* 1DF7E8 002DF7E8 00000000 */   nop
    /* 1DF7EC 002DF7EC 2D884000 */  daddu      $17, $2, $0
    /* 1DF7F0 002DF7F0 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1DF7F4 002DF7F4 00608244 */  mtc1       $2, $f12
    /* 1DF7F8 002DF7F8 00788044 */  mtc1       $0, $f15
    /* 1DF7FC 002DF7FC DC0C048E */  lw         $4, 0xCDC($16)
    /* 1DF800 002DF800 46630046 */  mov.s      $f13, $f12
    /* 1DF804 002DF804 86630046 */  mov.s      $f14, $f12
    /* 1DF808 002DF808 2D280000 */  daddu      $5, $0, $0
    /* 1DF80C 002DF80C 05000624 */  addiu      $6, $0, 0x5
    /* 1DF810 002DF810 2D380000 */  daddu      $7, $0, $0
    /* 1DF814 002DF814 B4810B0C */  jal        func_002e06d0
    /* 1DF818 002DF818 00000000 */   nop
    /* 1DF81C 002DF81C DC0C048E */  lw         $4, 0xCDC($16)
    /* 1DF820 002DF820 FF000524 */  addiu      $5, $0, 0xFF
    /* 1DF824 002DF824 2D300000 */  daddu      $6, $0, $0
    /* 1DF828 002DF828 2D380000 */  daddu      $7, $0, $0
    /* 1DF82C 002DF82C 05000824 */  addiu      $8, $0, 0x5
    /* 1DF830 002DF830 2D480000 */  daddu      $9, $0, $0
    /* 1DF834 002DF834 98810B0C */  jal        func_002e0660
    /* 1DF838 002DF838 00000000 */   nop
    /* 1DF83C 002DF83C 1244023C */  lui        $2, (0x44120000 >> 16)
    /* 1DF840 002DF840 00608244 */  mtc1       $2, $f12
    /* 1DF844 002DF844 FE42023C */  lui        $2, (0x42FE0000 >> 16)
    /* 1DF848 002DF848 00688244 */  mtc1       $2, $f13
    /* 1DF84C 002DF84C 7800A427 */  addiu      $4, $29, 0x78
    /* 1DF850 002DF850 5CCA0A0C */  jal        func_002b2970
    /* 1DF854 002DF854 00000000 */   nop
    /* 1DF858 002DF858 2D202002 */  daddu      $4, $17, $0
    /* 1DF85C 002DF85C BCAC110C */  jal        func_0046b2f0
    /* 1DF860 002DF860 00000000 */   nop
    /* 1DF864 002DF864 2041023C */  lui        $2, (0x41200000 >> 16)
    /* 1DF868 002DF868 00088244 */  mtc1       $2, $f1
    /* 1DF86C 002DF86C 00000000 */  nop
    /* 1DF870 002DF870 C3000146 */  div.s      $f3, $f0, $f1
    /* 1DF874 002DF874 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1DF878 002DF878 00108244 */  mtc1       $2, $f2
    /* 1DF87C 002DF87C FE42023C */  lui        $2, (0x42FE0000 >> 16)
    /* 1DF880 002DF880 00088244 */  mtc1       $2, $f1
    /* 1DF884 002DF884 00008044 */  mtc1       $0, $f0
    /* 1DF888 002DF888 00000000 */  nop
    /* 1DF88C 002DF88C 18000146 */  adda.s     $f0, $f1
    /* 1DF890 002DF890 5C130346 */  madd.s     $f13, $f2, $f3
    /* 1DF894 002DF894 1244023C */  lui        $2, (0x44120000 >> 16)
    /* 1DF898 002DF898 00608244 */  mtc1       $2, $f12
    /* 1DF89C 002DF89C 7000A427 */  addiu      $4, $29, 0x70
    /* 1DF8A0 002DF8A0 5CCA0A0C */  jal        func_002b2970
    /* 1DF8A4 002DF8A4 00000000 */   nop
    /* 1DF8A8 002DF8A8 DC0C048E */  lw         $4, 0xCDC($16)
    /* 1DF8AC 002DF8AC 7800A5DF */  ld         $5, 0x78($29)
    /* 1DF8B0 002DF8B0 7000A6DF */  ld         $6, 0x70($29)
    /* 1DF8B4 002DF8B4 2D380000 */  daddu      $7, $0, $0
    /* 1DF8B8 002DF8B8 05000824 */  addiu      $8, $0, 0x5
    /* 1DF8BC 002DF8BC 2D480000 */  daddu      $9, $0, $0
    /* 1DF8C0 002DF8C0 88810B0C */  jal        func_002e0620
    /* 1DF8C4 002DF8C4 00000000 */   nop
    /* 1DF8C8 002DF8C8 2D202002 */  daddu      $4, $17, $0
    /* 1DF8CC 002DF8CC A0B4110C */  jal        func_0046d280
    /* 1DF8D0 002DF8D0 00000000 */   nop
    /* 1DF8D4 002DF8D4 01010010 */  b          .L002DFCDC
    /* 1DF8D8 002DF8D8 00000000 */   nop
  .L002DF8DC:
    /* 1DF8DC 002DF8DC 280F048E */  lw         $4, 0xF28($16)
    /* 1DF8E0 002DF8E0 2A000524 */  addiu      $5, $0, 0x2A
    /* 1DF8E4 002DF8E4 80B4110C */  jal        func_0046d200
    /* 1DF8E8 002DF8E8 00000000 */   nop
    /* 1DF8EC 002DF8EC 2D884000 */  daddu      $17, $2, $0
    /* 1DF8F0 002DF8F0 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1DF8F4 002DF8F4 00608244 */  mtc1       $2, $f12
    /* 1DF8F8 002DF8F8 00788044 */  mtc1       $0, $f15
    /* 1DF8FC 002DF8FC E00C048E */  lw         $4, 0xCE0($16)
    /* 1DF900 002DF900 46630046 */  mov.s      $f13, $f12
    /* 1DF904 002DF904 86630046 */  mov.s      $f14, $f12
    /* 1DF908 002DF908 2D280000 */  daddu      $5, $0, $0
    /* 1DF90C 002DF90C 05000624 */  addiu      $6, $0, 0x5
    /* 1DF910 002DF910 2D380000 */  daddu      $7, $0, $0
    /* 1DF914 002DF914 B4810B0C */  jal        func_002e06d0
    /* 1DF918 002DF918 00000000 */   nop
    /* 1DF91C 002DF91C 7C42023C */  lui        $2, (0x427C0000 >> 16)
    /* 1DF920 002DF920 00608244 */  mtc1       $2, $f12
    /* 1DF924 002DF924 1443023C */  lui        $2, (0x43140000 >> 16)
    /* 1DF928 002DF928 00688244 */  mtc1       $2, $f13
    /* 1DF92C 002DF92C 6800A427 */  addiu      $4, $29, 0x68
    /* 1DF930 002DF930 5CCA0A0C */  jal        func_002b2970
    /* 1DF934 002DF934 00000000 */   nop
    /* 1DF938 002DF938 2D202002 */  daddu      $4, $17, $0
    /* 1DF93C 002DF93C BCAC110C */  jal        func_0046b2f0
    /* 1DF940 002DF940 00000000 */   nop
    /* 1DF944 002DF944 2041023C */  lui        $2, (0x41200000 >> 16)
    /* 1DF948 002DF948 00088244 */  mtc1       $2, $f1
    /* 1DF94C 002DF94C 00000000 */  nop
    /* 1DF950 002DF950 C3000146 */  div.s      $f3, $f0, $f1
    /* 1DF954 002DF954 A040023C */  lui        $2, (0x40A00000 >> 16)
    /* 1DF958 002DF958 00108244 */  mtc1       $2, $f2
    /* 1DF95C 002DF95C 1443023C */  lui        $2, (0x43140000 >> 16)
    /* 1DF960 002DF960 00088244 */  mtc1       $2, $f1
    /* 1DF964 002DF964 00008044 */  mtc1       $0, $f0
    /* 1DF968 002DF968 00000000 */  nop
    /* 1DF96C 002DF96C 18000146 */  adda.s     $f0, $f1
    /* 1DF970 002DF970 5C130346 */  madd.s     $f13, $f2, $f3
    /* 1DF974 002DF974 7C42023C */  lui        $2, (0x427C0000 >> 16)
    /* 1DF978 002DF978 00608244 */  mtc1       $2, $f12
    /* 1DF97C 002DF97C 6000A427 */  addiu      $4, $29, 0x60
    /* 1DF980 002DF980 5CCA0A0C */  jal        func_002b2970
    /* 1DF984 002DF984 00000000 */   nop
    /* 1DF988 002DF988 E00C048E */  lw         $4, 0xCE0($16)
    /* 1DF98C 002DF98C 6800A5DF */  ld         $5, 0x68($29)
    /* 1DF990 002DF990 6000A6DF */  ld         $6, 0x60($29)
    /* 1DF994 002DF994 2D380000 */  daddu      $7, $0, $0
    /* 1DF998 002DF998 05000824 */  addiu      $8, $0, 0x5
    /* 1DF99C 002DF99C 2D480000 */  daddu      $9, $0, $0
    /* 1DF9A0 002DF9A0 88810B0C */  jal        func_002e0620
    /* 1DF9A4 002DF9A4 00000000 */   nop
    /* 1DF9A8 002DF9A8 E00C048E */  lw         $4, 0xCE0($16)
    /* 1DF9AC 002DF9AC FF000524 */  addiu      $5, $0, 0xFF
    /* 1DF9B0 002DF9B0 2D300000 */  daddu      $6, $0, $0
    /* 1DF9B4 002DF9B4 2D380000 */  daddu      $7, $0, $0
    /* 1DF9B8 002DF9B8 05000824 */  addiu      $8, $0, 0x5
    /* 1DF9BC 002DF9BC 2D480000 */  daddu      $9, $0, $0
    /* 1DF9C0 002DF9C0 98810B0C */  jal        func_002e0660
    /* 1DF9C4 002DF9C4 00000000 */   nop
    /* 1DF9C8 002DF9C8 2D202002 */  daddu      $4, $17, $0
    /* 1DF9CC 002DF9CC A0B4110C */  jal        func_0046d280
    /* 1DF9D0 002DF9D0 00000000 */   nop
    /* 1DF9D4 002DF9D4 280F048E */  lw         $4, 0xF28($16)
    /* 1DF9D8 002DF9D8 2C000524 */  addiu      $5, $0, 0x2C
    /* 1DF9DC 002DF9DC 80B4110C */  jal        func_0046d200
    /* 1DF9E0 002DF9E0 00000000 */   nop
    /* 1DF9E4 002DF9E4 2D884000 */  daddu      $17, $2, $0
    /* 1DF9E8 002DF9E8 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1DF9EC 002DF9EC 00608244 */  mtc1       $2, $f12
    /* 1DF9F0 002DF9F0 00788044 */  mtc1       $0, $f15
    /* 1DF9F4 002DF9F4 E80C048E */  lw         $4, 0xCE8($16)
    /* 1DF9F8 002DF9F8 46630046 */  mov.s      $f13, $f12
    /* 1DF9FC 002DF9FC 86630046 */  mov.s      $f14, $f12
    /* 1DFA00 002DFA00 2D280000 */  daddu      $5, $0, $0
    /* 1DFA04 002DFA04 05000624 */  addiu      $6, $0, 0x5
    /* 1DFA08 002DFA08 2D380000 */  daddu      $7, $0, $0
    /* 1DFA0C 002DFA0C B4810B0C */  jal        func_002e06d0
    /* 1DFA10 002DFA10 00000000 */   nop
    /* 1DFA14 002DFA14 22020224 */  addiu      $2, $0, 0x222
    /* 1DFA18 002DFA18 00008244 */  mtc1       $2, $f0
    /* 1DFA1C 002DFA1C 00000000 */  nop
    /* 1DFA20 002DFA20 20038046 */  cvt.s.w    $f12, $f0
    /* 1DFA24 002DFA24 1443023C */  lui        $2, (0x43140000 >> 16)
    /* 1DFA28 002DFA28 00688244 */  mtc1       $2, $f13
    /* 1DFA2C 002DFA2C 5800A427 */  addiu      $4, $29, 0x58
    /* 1DFA30 002DFA30 5CCA0A0C */  jal        func_002b2970
    /* 1DFA34 002DFA34 00000000 */   nop
    /* 1DFA38 002DFA38 2D202002 */  daddu      $4, $17, $0
    /* 1DFA3C 002DFA3C BCAC110C */  jal        func_0046b2f0
    /* 1DFA40 002DFA40 00000000 */   nop
    /* 1DFA44 002DFA44 2041023C */  lui        $2, (0x41200000 >> 16)
    /* 1DFA48 002DFA48 00088244 */  mtc1       $2, $f1
    /* 1DFA4C 002DFA4C 00000000 */  nop
    /* 1DFA50 002DFA50 C3000146 */  div.s      $f3, $f0, $f1
    /* 1DFA54 002DFA54 A040023C */  lui        $2, (0x40A00000 >> 16)
    /* 1DFA58 002DFA58 00108244 */  mtc1       $2, $f2
    /* 1DFA5C 002DFA5C 1443023C */  lui        $2, (0x43140000 >> 16)
    /* 1DFA60 002DFA60 00088244 */  mtc1       $2, $f1
    /* 1DFA64 002DFA64 00008044 */  mtc1       $0, $f0
    /* 1DFA68 002DFA68 00000000 */  nop
    /* 1DFA6C 002DFA6C 18000146 */  adda.s     $f0, $f1
    /* 1DFA70 002DFA70 5C130346 */  madd.s     $f13, $f2, $f3
    /* 1DFA74 002DFA74 22020224 */  addiu      $2, $0, 0x222
    /* 1DFA78 002DFA78 00008244 */  mtc1       $2, $f0
    /* 1DFA7C 002DFA7C 00000000 */  nop
    /* 1DFA80 002DFA80 20038046 */  cvt.s.w    $f12, $f0
    /* 1DFA84 002DFA84 5000A427 */  addiu      $4, $29, 0x50
    /* 1DFA88 002DFA88 5CCA0A0C */  jal        func_002b2970
    /* 1DFA8C 002DFA8C 00000000 */   nop
    /* 1DFA90 002DFA90 E80C048E */  lw         $4, 0xCE8($16)
    /* 1DFA94 002DFA94 5800A5DF */  ld         $5, 0x58($29)
    /* 1DFA98 002DFA98 5000A6DF */  ld         $6, 0x50($29)
    /* 1DFA9C 002DFA9C 2D380000 */  daddu      $7, $0, $0
    /* 1DFAA0 002DFAA0 05000824 */  addiu      $8, $0, 0x5
    /* 1DFAA4 002DFAA4 2D480000 */  daddu      $9, $0, $0
    /* 1DFAA8 002DFAA8 88810B0C */  jal        func_002e0620
    /* 1DFAAC 002DFAAC 00000000 */   nop
    /* 1DFAB0 002DFAB0 E80C048E */  lw         $4, 0xCE8($16)
    /* 1DFAB4 002DFAB4 FF000524 */  addiu      $5, $0, 0xFF
    /* 1DFAB8 002DFAB8 2D300000 */  daddu      $6, $0, $0
    /* 1DFABC 002DFABC 2D380000 */  daddu      $7, $0, $0
    /* 1DFAC0 002DFAC0 05000824 */  addiu      $8, $0, 0x5
    /* 1DFAC4 002DFAC4 2D480000 */  daddu      $9, $0, $0
    /* 1DFAC8 002DFAC8 98810B0C */  jal        func_002e0660
    /* 1DFACC 002DFACC 00000000 */   nop
    /* 1DFAD0 002DFAD0 2D202002 */  daddu      $4, $17, $0
    /* 1DFAD4 002DFAD4 A0B4110C */  jal        func_0046d280
    /* 1DFAD8 002DFAD8 00000000 */   nop
    /* 1DFADC 002DFADC 280F048E */  lw         $4, 0xF28($16)
    /* 1DFAE0 002DFAE0 27000524 */  addiu      $5, $0, 0x27
    /* 1DFAE4 002DFAE4 80B4110C */  jal        func_0046d200
    /* 1DFAE8 002DFAE8 00000000 */   nop
    /* 1DFAEC 002DFAEC 2D884000 */  daddu      $17, $2, $0
    /* 1DFAF0 002DFAF0 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1DFAF4 002DFAF4 00608244 */  mtc1       $2, $f12
    /* 1DFAF8 002DFAF8 00788044 */  mtc1       $0, $f15
    /* 1DFAFC 002DFAFC D40C048E */  lw         $4, 0xCD4($16)
    /* 1DFB00 002DFB00 46630046 */  mov.s      $f13, $f12
    /* 1DFB04 002DFB04 86630046 */  mov.s      $f14, $f12
    /* 1DFB08 002DFB08 2D280000 */  daddu      $5, $0, $0
    /* 1DFB0C 002DFB0C 05000624 */  addiu      $6, $0, 0x5
    /* 1DFB10 002DFB10 2D380000 */  daddu      $7, $0, $0
    /* 1DFB14 002DFB14 B4810B0C */  jal        func_002e06d0
    /* 1DFB18 002DFB18 00000000 */   nop
    /* 1DFB1C 002DFB1C D40C048E */  lw         $4, 0xCD4($16)
    /* 1DFB20 002DFB20 FF000524 */  addiu      $5, $0, 0xFF
    /* 1DFB24 002DFB24 2D300000 */  daddu      $6, $0, $0
    /* 1DFB28 002DFB28 2D380000 */  daddu      $7, $0, $0
    /* 1DFB2C 002DFB2C 05000824 */  addiu      $8, $0, 0x5
    /* 1DFB30 002DFB30 2D480000 */  daddu      $9, $0, $0
    /* 1DFB34 002DFB34 98810B0C */  jal        func_002e0660
    /* 1DFB38 002DFB38 00000000 */   nop
    /* 1DFB3C 002DFB3C 3842023C */  lui        $2, (0x42380000 >> 16)
    /* 1DFB40 002DFB40 00608244 */  mtc1       $2, $f12
    /* 1DFB44 002DFB44 0843023C */  lui        $2, (0x43080000 >> 16)
    /* 1DFB48 002DFB48 00688244 */  mtc1       $2, $f13
    /* 1DFB4C 002DFB4C 4800A427 */  addiu      $4, $29, 0x48
    /* 1DFB50 002DFB50 5CCA0A0C */  jal        func_002b2970
    /* 1DFB54 002DFB54 00000000 */   nop
    /* 1DFB58 002DFB58 2D202002 */  daddu      $4, $17, $0
    /* 1DFB5C 002DFB5C BCAC110C */  jal        func_0046b2f0
    /* 1DFB60 002DFB60 00000000 */   nop
    /* 1DFB64 002DFB64 2041023C */  lui        $2, (0x41200000 >> 16)
    /* 1DFB68 002DFB68 00088244 */  mtc1       $2, $f1
    /* 1DFB6C 002DFB6C 00000000 */  nop
    /* 1DFB70 002DFB70 C3000146 */  div.s      $f3, $f0, $f1
    /* 1DFB74 002DFB74 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1DFB78 002DFB78 00108244 */  mtc1       $2, $f2
    /* 1DFB7C 002DFB7C 0843023C */  lui        $2, (0x43080000 >> 16)
    /* 1DFB80 002DFB80 00088244 */  mtc1       $2, $f1
    /* 1DFB84 002DFB84 00008044 */  mtc1       $0, $f0
    /* 1DFB88 002DFB88 00000000 */  nop
    /* 1DFB8C 002DFB8C 18000146 */  adda.s     $f0, $f1
    /* 1DFB90 002DFB90 5C130346 */  madd.s     $f13, $f2, $f3
    /* 1DFB94 002DFB94 3842023C */  lui        $2, (0x42380000 >> 16)
    /* 1DFB98 002DFB98 00608244 */  mtc1       $2, $f12
    /* 1DFB9C 002DFB9C 4000A427 */  addiu      $4, $29, 0x40
    /* 1DFBA0 002DFBA0 5CCA0A0C */  jal        func_002b2970
    /* 1DFBA4 002DFBA4 00000000 */   nop
    /* 1DFBA8 002DFBA8 D40C048E */  lw         $4, 0xCD4($16)
    /* 1DFBAC 002DFBAC 4800A5DF */  ld         $5, 0x48($29)
    /* 1DFBB0 002DFBB0 4000A6DF */  ld         $6, 0x40($29)
    /* 1DFBB4 002DFBB4 2D380000 */  daddu      $7, $0, $0
    /* 1DFBB8 002DFBB8 05000824 */  addiu      $8, $0, 0x5
    /* 1DFBBC 002DFBBC 2D480000 */  daddu      $9, $0, $0
    /* 1DFBC0 002DFBC0 88810B0C */  jal        func_002e0620
    /* 1DFBC4 002DFBC4 00000000 */   nop
    /* 1DFBC8 002DFBC8 2D202002 */  daddu      $4, $17, $0
    /* 1DFBCC 002DFBCC A0B4110C */  jal        func_0046d280
    /* 1DFBD0 002DFBD0 00000000 */   nop
    /* 1DFBD4 002DFBD4 280F048E */  lw         $4, 0xF28($16)
    /* 1DFBD8 002DFBD8 29000524 */  addiu      $5, $0, 0x29
    /* 1DFBDC 002DFBDC 80B4110C */  jal        func_0046d200
    /* 1DFBE0 002DFBE0 00000000 */   nop
    /* 1DFBE4 002DFBE4 2D884000 */  daddu      $17, $2, $0
    /* 1DFBE8 002DFBE8 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1DFBEC 002DFBEC 00608244 */  mtc1       $2, $f12
    /* 1DFBF0 002DFBF0 00788044 */  mtc1       $0, $f15
    /* 1DFBF4 002DFBF4 DC0C048E */  lw         $4, 0xCDC($16)
    /* 1DFBF8 002DFBF8 46630046 */  mov.s      $f13, $f12
    /* 1DFBFC 002DFBFC 86630046 */  mov.s      $f14, $f12
    /* 1DFC00 002DFC00 2D280000 */  daddu      $5, $0, $0
    /* 1DFC04 002DFC04 05000624 */  addiu      $6, $0, 0x5
    /* 1DFC08 002DFC08 2D380000 */  daddu      $7, $0, $0
    /* 1DFC0C 002DFC0C B4810B0C */  jal        func_002e06d0
    /* 1DFC10 002DFC10 00000000 */   nop
    /* 1DFC14 002DFC14 DC0C048E */  lw         $4, 0xCDC($16)
    /* 1DFC18 002DFC18 FF000524 */  addiu      $5, $0, 0xFF
    /* 1DFC1C 002DFC1C 2D300000 */  daddu      $6, $0, $0
    /* 1DFC20 002DFC20 2D380000 */  daddu      $7, $0, $0
    /* 1DFC24 002DFC24 05000824 */  addiu      $8, $0, 0x5
    /* 1DFC28 002DFC28 2D480000 */  daddu      $9, $0, $0
    /* 1DFC2C 002DFC2C 98810B0C */  jal        func_002e0660
    /* 1DFC30 002DFC30 00000000 */   nop
    /* 1DFC34 002DFC34 32020224 */  addiu      $2, $0, 0x232
    /* 1DFC38 002DFC38 00008244 */  mtc1       $2, $f0
    /* 1DFC3C 002DFC3C 00000000 */  nop
    /* 1DFC40 002DFC40 20038046 */  cvt.s.w    $f12, $f0
    /* 1DFC44 002DFC44 0843023C */  lui        $2, (0x43080000 >> 16)
    /* 1DFC48 002DFC48 00688244 */  mtc1       $2, $f13
    /* 1DFC4C 002DFC4C 3800A427 */  addiu      $4, $29, 0x38
    /* 1DFC50 002DFC50 5CCA0A0C */  jal        func_002b2970
    /* 1DFC54 002DFC54 00000000 */   nop
    /* 1DFC58 002DFC58 2D202002 */  daddu      $4, $17, $0
    /* 1DFC5C 002DFC5C BCAC110C */  jal        func_0046b2f0
    /* 1DFC60 002DFC60 00000000 */   nop
    /* 1DFC64 002DFC64 2041023C */  lui        $2, (0x41200000 >> 16)
    /* 1DFC68 002DFC68 00088244 */  mtc1       $2, $f1
    /* 1DFC6C 002DFC6C 00000000 */  nop
    /* 1DFC70 002DFC70 C3000146 */  div.s      $f3, $f0, $f1
    /* 1DFC74 002DFC74 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1DFC78 002DFC78 00108244 */  mtc1       $2, $f2
    /* 1DFC7C 002DFC7C 0843023C */  lui        $2, (0x43080000 >> 16)
    /* 1DFC80 002DFC80 00088244 */  mtc1       $2, $f1
    /* 1DFC84 002DFC84 00008044 */  mtc1       $0, $f0
    /* 1DFC88 002DFC88 00000000 */  nop
    /* 1DFC8C 002DFC8C 18000146 */  adda.s     $f0, $f1
    /* 1DFC90 002DFC90 5C130346 */  madd.s     $f13, $f2, $f3
    /* 1DFC94 002DFC94 32020224 */  addiu      $2, $0, 0x232
    /* 1DFC98 002DFC98 00008244 */  mtc1       $2, $f0
    /* 1DFC9C 002DFC9C 00000000 */  nop
    /* 1DFCA0 002DFCA0 20038046 */  cvt.s.w    $f12, $f0
    /* 1DFCA4 002DFCA4 3000A427 */  addiu      $4, $29, 0x30
    /* 1DFCA8 002DFCA8 5CCA0A0C */  jal        func_002b2970
    /* 1DFCAC 002DFCAC 00000000 */   nop
    /* 1DFCB0 002DFCB0 DC0C048E */  lw         $4, 0xCDC($16)
    /* 1DFCB4 002DFCB4 3800A5DF */  ld         $5, 0x38($29)
    /* 1DFCB8 002DFCB8 3000A6DF */  ld         $6, 0x30($29)
    /* 1DFCBC 002DFCBC 2D380000 */  daddu      $7, $0, $0
    /* 1DFCC0 002DFCC0 05000824 */  addiu      $8, $0, 0x5
    /* 1DFCC4 002DFCC4 2D480000 */  daddu      $9, $0, $0
    /* 1DFCC8 002DFCC8 88810B0C */  jal        func_002e0620
    /* 1DFCCC 002DFCCC 00000000 */   nop
    /* 1DFCD0 002DFCD0 2D202002 */  daddu      $4, $17, $0
    /* 1DFCD4 002DFCD4 A0B4110C */  jal        func_0046d280
    /* 1DFCD8 002DFCD8 00000000 */   nop
  .L002DFCDC:
    /* 1DFCDC 002DFCDC 2000BFDF */  ld         $31, 0x20($29)
    /* 1DFCE0 002DFCE0 1000B17B */  lq         $17, 0x10($29)
    /* 1DFCE4 002DFCE4 0000B07B */  lq         $16, 0x0($29)
    /* 1DFCE8 002DFCE8 B000BD27 */  addiu      $29, $29, 0xB0
    /* 1DFCEC 002DFCEC 0800E003 */  jr         $31
    /* 1DFCF0 002DFCF0 00000000 */   nop
    /* 1DFCF4 002DFCF4 00000000 */  nop
    /* 1DFCF8 002DFCF8 00000000 */  nop
    /* 1DFCFC 002DFCFC 00000000 */  nop
.size func_002df4c0, 0x840
