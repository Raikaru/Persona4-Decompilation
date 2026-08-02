.section .text
.set noat
.set noreorder
glabel func_002db400
    /* 1DB400 002DB400 F0FDBD27 */  addiu      $29, $29, -0x210
    /* 1DB404 002DB404 5000BFFF */  sd         $31, 0x50($29)
    /* 1DB408 002DB408 4000B37F */  sq         $19, 0x40($29)
    /* 1DB40C 002DB40C 3000B27F */  sq         $18, 0x30($29)
    /* 1DB410 002DB410 2000B17F */  sq         $17, 0x20($29)
    /* 1DB414 002DB414 1000B07F */  sq         $16, 0x10($29)
    /* 1DB418 002DB418 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 1DB41C 002DB41C 3800908C */  lw         $16, 0x38($4)
    /* 1DB420 002DB420 EC0D048E */  lw         $4, 0xDEC($16)
    /* 1DB424 002DB424 2D280000 */  daddu      $5, $0, $0
    /* 1DB428 002DB428 01000624 */  addiu      $6, $0, 0x1
    /* 1DB42C 002DB42C 3C810B0C */  jal        func_002e04f0
    /* 1DB430 002DB430 00000000 */   nop
    /* 1DB434 002DB434 6400113C */  lui        $17, %hi(D_0063F5B8)
    /* 1DB438 002DB438 B8F53126 */  addiu      $17, $17, %lo(D_0063F5B8)
    /* 1DB43C 002DB43C 1D43023C */  lui        $2, (0x431D0000 >> 16)
    /* 1DB440 002DB440 00608244 */  mtc1       $2, $f12
    /* 1DB444 002DB444 640C048E */  lw         $4, 0xC64($16)
    /* 1DB448 002DB448 41000524 */  addiu      $5, $0, 0x41
    /* 1DB44C 002DB44C 78820B0C */  jal        func_002e09e0
    /* 1DB450 002DB450 00000000 */   nop
    /* 1DB454 002DB454 040021C6 */  lwc1       $f1, 0x4($17)
    /* 1DB458 002DB458 96C3023C */  lui        $2, (0xC3960000 >> 16)
    /* 1DB45C 002DB45C 00008244 */  mtc1       $2, $f0
    /* 1DB460 002DB460 00000000 */  nop
    /* 1DB464 002DB464 40030146 */  add.s      $f13, $f0, $f1
    /* 1DB468 002DB468 9801A427 */  addiu      $4, $29, 0x198
    /* 1DB46C 002DB46C 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1DB470 002DB470 5CCA0A0C */  jal        func_002b2970
    /* 1DB474 002DB474 00000000 */   nop
    /* 1DB478 002DB478 9001A427 */  addiu      $4, $29, 0x190
    /* 1DB47C 002DB47C 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1DB480 002DB480 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1DB484 002DB484 5CCA0A0C */  jal        func_002b2970
    /* 1DB488 002DB488 00000000 */   nop
    /* 1DB48C 002DB48C 640C048E */  lw         $4, 0xC64($16)
    /* 1DB490 002DB490 9801A5DF */  ld         $5, 0x198($29)
    /* 1DB494 002DB494 9001A6DF */  ld         $6, 0x190($29)
    /* 1DB498 002DB498 2D380000 */  daddu      $7, $0, $0
    /* 1DB49C 002DB49C 07000824 */  addiu      $8, $0, 0x7
    /* 1DB4A0 002DB4A0 2D480000 */  daddu      $9, $0, $0
    /* 1DB4A4 002DB4A4 88810B0C */  jal        func_002e0620
    /* 1DB4A8 002DB4A8 00000000 */   nop
    /* 1DB4AC 002DB4AC 640C048E */  lw         $4, 0xC64($16)
    /* 1DB4B0 002DB4B0 2D280000 */  daddu      $5, $0, $0
    /* 1DB4B4 002DB4B4 CC000624 */  addiu      $6, $0, 0xCC
    /* 1DB4B8 002DB4B8 2D380000 */  daddu      $7, $0, $0
    /* 1DB4BC 002DB4BC 07000824 */  addiu      $8, $0, 0x7
    /* 1DB4C0 002DB4C0 2D480000 */  daddu      $9, $0, $0
    /* 1DB4C4 002DB4C4 98810B0C */  jal        func_002e0660
    /* 1DB4C8 002DB4C8 00000000 */   nop
    /* 1DB4CC 002DB4CC 0C02A427 */  addiu      $4, $29, 0x20C
    /* 1DB4D0 002DB4D0 2D280000 */  daddu      $5, $0, $0
    /* 1DB4D4 002DB4D4 2D300000 */  daddu      $6, $0, $0
    /* 1DB4D8 002DB4D8 2D380000 */  daddu      $7, $0, $0
    /* 1DB4DC 002DB4DC FF000824 */  addiu      $8, $0, 0xFF
    /* 1DB4E0 002DB4E0 98CA0A0C */  jal        func_002b2a60
    /* 1DB4E4 002DB4E4 00000000 */   nop
    /* 1DB4E8 002DB4E8 640C048E */  lw         $4, 0xC64($16)
    /* 1DB4EC 002DB4EC 38810B0C */  jal        func_002e04e0
    /* 1DB4F0 002DB4F0 00000000 */   nop
    /* 1DB4F4 002DB4F4 0C02A693 */  lbu        $6, 0x20C($29)
    /* 1DB4F8 002DB4F8 0D02A593 */  lbu        $5, 0x20D($29)
    /* 1DB4FC 002DB4FC 0E02A493 */  lbu        $4, 0x20E($29)
    /* 1DB500 002DB500 0F02A393 */  lbu        $3, 0x20F($29)
    /* 1DB504 002DB504 790046A0 */  sb         $6, 0x79($2)
    /* 1DB508 002DB508 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DB50C 002DB50C 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DB510 002DB510 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DB514 002DB514 00608044 */  mtc1       $0, $f12
    /* 1DB518 002DB518 80C0023C */  lui        $2, (0xC0800000 >> 16)
    /* 1DB51C 002DB51C 00688244 */  mtc1       $2, $f13
    /* 1DB520 002DB520 640C048E */  lw         $4, 0xC64($16)
    /* 1DB524 002DB524 2D280000 */  daddu      $5, $0, $0
    /* 1DB528 002DB528 2D300000 */  daddu      $6, $0, $0
    /* 1DB52C 002DB52C 2D380000 */  daddu      $7, $0, $0
    /* 1DB530 002DB530 50820B0C */  jal        func_002e0940
    /* 1DB534 002DB534 00000000 */   nop
    /* 1DB538 002DB538 A043023C */  lui        $2, (0x43A00000 >> 16)
    /* 1DB53C 002DB53C 00088244 */  mtc1       $2, $f1
    /* 1DB540 002DB540 000020C6 */  lwc1       $f0, 0x0($17)
    /* 1DB544 002DB544 01080046 */  sub.s      $f0, $f1, $f0
    /* 1DB548 002DB548 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1DB54C 002DB54C 00000244 */  mfc1       $2, $f0
    /* 1DB550 002DB550 00000000 */  nop
    /* 1DB554 002DB554 3C940200 */  dsll32     $18, $2, 16
    /* 1DB558 002DB558 3F941200 */  dsra32     $18, $18, 16
    /* 1DB55C 002DB55C 640C048E */  lw         $4, 0xC64($16)
    /* 1DB560 002DB560 38810B0C */  jal        func_002e04e0
    /* 1DB564 002DB564 00000000 */   nop
    /* 1DB568 002DB568 000152A4 */  sh         $18, 0x100($2)
    /* 1DB56C 002DB56C 040021C6 */  lwc1       $f1, 0x4($17)
    /* 1DB570 002DB570 A642023C */  lui        $2, (0x42A60000 >> 16)
    /* 1DB574 002DB574 00008244 */  mtc1       $2, $f0
    /* 1DB578 002DB578 00000000 */  nop
    /* 1DB57C 002DB57C 01080046 */  sub.s      $f0, $f1, $f0
    /* 1DB580 002DB580 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1DB584 002DB584 00000244 */  mfc1       $2, $f0
    /* 1DB588 002DB588 00000000 */  nop
    /* 1DB58C 002DB58C 3C8C0200 */  dsll32     $17, $2, 16
    /* 1DB590 002DB590 3F8C1100 */  dsra32     $17, $17, 16
    /* 1DB594 002DB594 640C048E */  lw         $4, 0xC64($16)
    /* 1DB598 002DB598 38810B0C */  jal        func_002e04e0
    /* 1DB59C 002DB59C 00000000 */   nop
    /* 1DB5A0 002DB5A0 020151A4 */  sh         $17, 0x102($2)
    /* 1DB5A4 002DB5A4 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1DB5A8 002DB5A8 00608244 */  mtc1       $2, $f12
    /* 1DB5AC 002DB5AC C03F023C */  lui        $2, (0x3FC00000 >> 16)
    /* 1DB5B0 002DB5B0 00688244 */  mtc1       $2, $f13
    /* 1DB5B4 002DB5B4 640C048E */  lw         $4, 0xC64($16)
    /* 1DB5B8 002DB5B8 86630046 */  mov.s      $f14, $f12
    /* 1DB5BC 002DB5BC C6630046 */  mov.s      $f15, $f12
    /* 1DB5C0 002DB5C0 2D280000 */  daddu      $5, $0, $0
    /* 1DB5C4 002DB5C4 2D300000 */  daddu      $6, $0, $0
    /* 1DB5C8 002DB5C8 2D380000 */  daddu      $7, $0, $0
    /* 1DB5CC 002DB5CC B4810B0C */  jal        func_002e06d0
    /* 1DB5D0 002DB5D0 00000000 */   nop
    /* 1DB5D4 002DB5D4 280F048E */  lw         $4, 0xF28($16)
    /* 1DB5D8 002DB5D8 44000524 */  addiu      $5, $0, 0x44
    /* 1DB5DC 002DB5DC 80B4110C */  jal        func_0046d200
    /* 1DB5E0 002DB5E0 00000000 */   nop
    /* 1DB5E4 002DB5E4 2D904000 */  daddu      $18, $2, $0
    /* 1DB5E8 002DB5E8 6400113C */  lui        $17, %hi(D_0063FA70)
    /* 1DB5EC 002DB5EC 70FA3126 */  addiu      $17, $17, %lo(D_0063FA70)
    /* 1DB5F0 002DB5F0 5442023C */  lui        $2, (0x42540000 >> 16)
    /* 1DB5F4 002DB5F4 00608244 */  mtc1       $2, $f12
    /* 1DB5F8 002DB5F8 480D048E */  lw         $4, 0xD48($16)
    /* 1DB5FC 002DB5FC 56000524 */  addiu      $5, $0, 0x56
    /* 1DB600 002DB600 78820B0C */  jal        func_002e09e0
    /* 1DB604 002DB604 00000000 */   nop
    /* 1DB608 002DB608 71020224 */  addiu      $2, $0, 0x271
    /* 1DB60C 002DB60C 00008244 */  mtc1       $2, $f0
    /* 1DB610 002DB610 00000000 */  nop
    /* 1DB614 002DB614 20038046 */  cvt.s.w    $f12, $f0
    /* 1DB618 002DB618 48C3023C */  lui        $2, (0xC3480000 >> 16)
    /* 1DB61C 002DB61C 00688244 */  mtc1       $2, $f13
    /* 1DB620 002DB620 8801A427 */  addiu      $4, $29, 0x188
    /* 1DB624 002DB624 5CCA0A0C */  jal        func_002b2970
    /* 1DB628 002DB628 00000000 */   nop
    /* 1DB62C 002DB62C 71020224 */  addiu      $2, $0, 0x271
    /* 1DB630 002DB630 00008244 */  mtc1       $2, $f0
    /* 1DB634 002DB634 00000000 */  nop
    /* 1DB638 002DB638 20038046 */  cvt.s.w    $f12, $f0
    /* 1DB63C 002DB63C 9643023C */  lui        $2, (0x43960000 >> 16)
    /* 1DB640 002DB640 00688244 */  mtc1       $2, $f13
    /* 1DB644 002DB644 8001A427 */  addiu      $4, $29, 0x180
    /* 1DB648 002DB648 5CCA0A0C */  jal        func_002b2970
    /* 1DB64C 002DB64C 00000000 */   nop
    /* 1DB650 002DB650 480D048E */  lw         $4, 0xD48($16)
    /* 1DB654 002DB654 8801A5DF */  ld         $5, 0x188($29)
    /* 1DB658 002DB658 8001A6DF */  ld         $6, 0x180($29)
    /* 1DB65C 002DB65C 02000724 */  addiu      $7, $0, 0x2
    /* 1DB660 002DB660 05000824 */  addiu      $8, $0, 0x5
    /* 1DB664 002DB664 2D480001 */  daddu      $9, $8, $0
    /* 1DB668 002DB668 88810B0C */  jal        func_002e0620
    /* 1DB66C 002DB66C 00000000 */   nop
    /* 1DB670 002DB670 0802A427 */  addiu      $4, $29, 0x208
    /* 1DB674 002DB674 E4000524 */  addiu      $5, $0, 0xE4
    /* 1DB678 002DB678 FF000624 */  addiu      $6, $0, 0xFF
    /* 1DB67C 002DB67C 2D380000 */  daddu      $7, $0, $0
    /* 1DB680 002DB680 2D40C000 */  daddu      $8, $6, $0
    /* 1DB684 002DB684 98CA0A0C */  jal        func_002b2a60
    /* 1DB688 002DB688 00000000 */   nop
    /* 1DB68C 002DB68C 480D048E */  lw         $4, 0xD48($16)
    /* 1DB690 002DB690 38810B0C */  jal        func_002e04e0
    /* 1DB694 002DB694 00000000 */   nop
    /* 1DB698 002DB698 0802A693 */  lbu        $6, 0x208($29)
    /* 1DB69C 002DB69C 0902A593 */  lbu        $5, 0x209($29)
    /* 1DB6A0 002DB6A0 0A02A493 */  lbu        $4, 0x20A($29)
    /* 1DB6A4 002DB6A4 0B02A393 */  lbu        $3, 0x20B($29)
    /* 1DB6A8 002DB6A8 790046A0 */  sb         $6, 0x79($2)
    /* 1DB6AC 002DB6AC 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DB6B0 002DB6B0 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DB6B4 002DB6B4 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DB6B8 002DB6B8 00A08044 */  mtc1       $0, $f20
    /* 1DB6BC 002DB6BC 480D048E */  lw         $4, 0xD48($16)
    /* 1DB6C0 002DB6C0 38810B0C */  jal        func_002e04e0
    /* 1DB6C4 002DB6C4 00000000 */   nop
    /* 1DB6C8 002DB6C8 C40054E4 */  swc1       $f20, 0xC4($2)
    /* 1DB6CC 002DB6CC 2D204002 */  daddu      $4, $18, $0
    /* 1DB6D0 002DB6D0 98AC110C */  jal        func_0046b260
    /* 1DB6D4 002DB6D4 00000000 */   nop
    /* 1DB6D8 002DB6D8 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1DB6DC 002DB6DC 00088244 */  mtc1       $2, $f1
    /* 1DB6E0 002DB6E0 00000000 */  nop
    /* 1DB6E4 002DB6E4 03000146 */  div.s      $f0, $f0, $f1
    /* 1DB6E8 002DB6E8 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1DB6EC 002DB6EC 00000244 */  mfc1       $2, $f0
    /* 1DB6F0 002DB6F0 00000000 */  nop
    /* 1DB6F4 002DB6F4 3C9C0200 */  dsll32     $19, $2, 16
    /* 1DB6F8 002DB6F8 3F9C1300 */  dsra32     $19, $19, 16
    /* 1DB6FC 002DB6FC 480D048E */  lw         $4, 0xD48($16)
    /* 1DB700 002DB700 38810B0C */  jal        func_002e04e0
    /* 1DB704 002DB704 00000000 */   nop
    /* 1DB708 002DB708 000153A4 */  sh         $19, 0x100($2)
    /* 1DB70C 002DB70C 2D204002 */  daddu      $4, $18, $0
    /* 1DB710 002DB710 BCAC110C */  jal        func_0046b2f0
    /* 1DB714 002DB714 00000000 */   nop
    /* 1DB718 002DB718 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1DB71C 002DB71C 00088244 */  mtc1       $2, $f1
    /* 1DB720 002DB720 00000000 */  nop
    /* 1DB724 002DB724 03000146 */  div.s      $f0, $f0, $f1
    /* 1DB728 002DB728 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1DB72C 002DB72C 00000244 */  mfc1       $2, $f0
    /* 1DB730 002DB730 00000000 */  nop
    /* 1DB734 002DB734 3C9C0200 */  dsll32     $19, $2, 16
    /* 1DB738 002DB738 3F9C1300 */  dsra32     $19, $19, 16
    /* 1DB73C 002DB73C 480D048E */  lw         $4, 0xD48($16)
    /* 1DB740 002DB740 38810B0C */  jal        func_002e04e0
    /* 1DB744 002DB744 00000000 */   nop
    /* 1DB748 002DB748 020153A4 */  sh         $19, 0x102($2)
    /* 1DB74C 002DB74C 04002286 */  lh         $2, 0x4($17)
    /* 1DB750 002DB750 00008244 */  mtc1       $2, $f0
    /* 1DB754 002DB754 00000000 */  nop
    /* 1DB758 002DB758 20038046 */  cvt.s.w    $f12, $f0
    /* 1DB75C 002DB75C 480D048E */  lw         $4, 0xD48($16)
    /* 1DB760 002DB760 06002586 */  lh         $5, 0x6($17)
    /* 1DB764 002DB764 6C820B0C */  jal        func_002e09b0
    /* 1DB768 002DB768 00000000 */   nop
    /* 1DB76C 002DB76C 3443023C */  lui        $2, (0x43340000 >> 16)
    /* 1DB770 002DB770 00688244 */  mtc1       $2, $f13
    /* 1DB774 002DB774 000020C6 */  lwc1       $f0, 0x0($17)
    /* 1DB778 002DB778 006B0046 */  add.s      $f12, $f13, $f0
    /* 1DB77C 002DB77C 06002286 */  lh         $2, 0x6($17)
    /* 1DB780 002DB780 05004624 */  addiu      $6, $2, 0x5
    /* 1DB784 002DB784 480D048E */  lw         $4, 0xD48($16)
    /* 1DB788 002DB788 2D280000 */  daddu      $5, $0, $0
    /* 1DB78C 002DB78C 05000724 */  addiu      $7, $0, 0x5
    /* 1DB790 002DB790 50820B0C */  jal        func_002e0940
    /* 1DB794 002DB794 00000000 */   nop
    /* 1DB798 002DB798 2D204002 */  daddu      $4, $18, $0
    /* 1DB79C 002DB79C A0B4110C */  jal        func_0046d280
    /* 1DB7A0 002DB7A0 00000000 */   nop
    /* 1DB7A4 002DB7A4 280F048E */  lw         $4, 0xF28($16)
    /* 1DB7A8 002DB7A8 43000524 */  addiu      $5, $0, 0x43
    /* 1DB7AC 002DB7AC 80B4110C */  jal        func_0046d200
    /* 1DB7B0 002DB7B0 00000000 */   nop
    /* 1DB7B4 002DB7B4 2D904000 */  daddu      $18, $2, $0
    /* 1DB7B8 002DB7B8 6400113C */  lui        $17, %hi(D_0063FA78)
    /* 1DB7BC 002DB7BC 78FA3126 */  addiu      $17, $17, %lo(D_0063FA78)
    /* 1DB7C0 002DB7C0 5842023C */  lui        $2, (0x42580000 >> 16)
    /* 1DB7C4 002DB7C4 00608244 */  mtc1       $2, $f12
    /* 1DB7C8 002DB7C8 440D048E */  lw         $4, 0xD44($16)
    /* 1DB7CC 002DB7CC 56000524 */  addiu      $5, $0, 0x56
    /* 1DB7D0 002DB7D0 78820B0C */  jal        func_002e09e0
    /* 1DB7D4 002DB7D4 00000000 */   nop
    /* 1DB7D8 002DB7D8 FD43023C */  lui        $2, (0x43FD0000 >> 16)
    /* 1DB7DC 002DB7DC 00608244 */  mtc1       $2, $f12
    /* 1DB7E0 002DB7E0 15C3023C */  lui        $2, (0xC3150000 >> 16)
    /* 1DB7E4 002DB7E4 00688244 */  mtc1       $2, $f13
    /* 1DB7E8 002DB7E8 7801A427 */  addiu      $4, $29, 0x178
    /* 1DB7EC 002DB7EC 5CCA0A0C */  jal        func_002b2970
    /* 1DB7F0 002DB7F0 00000000 */   nop
    /* 1DB7F4 002DB7F4 FD43023C */  lui        $2, (0x43FD0000 >> 16)
    /* 1DB7F8 002DB7F8 00608244 */  mtc1       $2, $f12
    /* 1DB7FC 002DB7FC 5F010224 */  addiu      $2, $0, 0x15F
    /* 1DB800 002DB800 00008244 */  mtc1       $2, $f0
    /* 1DB804 002DB804 00000000 */  nop
    /* 1DB808 002DB808 60038046 */  cvt.s.w    $f13, $f0
    /* 1DB80C 002DB80C 7001A427 */  addiu      $4, $29, 0x170
    /* 1DB810 002DB810 5CCA0A0C */  jal        func_002b2970
    /* 1DB814 002DB814 00000000 */   nop
    /* 1DB818 002DB818 440D048E */  lw         $4, 0xD44($16)
    /* 1DB81C 002DB81C 7801A5DF */  ld         $5, 0x178($29)
    /* 1DB820 002DB820 7001A6DF */  ld         $6, 0x170($29)
    /* 1DB824 002DB824 02000724 */  addiu      $7, $0, 0x2
    /* 1DB828 002DB828 05000824 */  addiu      $8, $0, 0x5
    /* 1DB82C 002DB82C 2D48E000 */  daddu      $9, $7, $0
    /* 1DB830 002DB830 88810B0C */  jal        func_002e0620
    /* 1DB834 002DB834 00000000 */   nop
    /* 1DB838 002DB838 0402A427 */  addiu      $4, $29, 0x204
    /* 1DB83C 002DB83C E4000524 */  addiu      $5, $0, 0xE4
    /* 1DB840 002DB840 FF000624 */  addiu      $6, $0, 0xFF
    /* 1DB844 002DB844 2D380000 */  daddu      $7, $0, $0
    /* 1DB848 002DB848 2D40C000 */  daddu      $8, $6, $0
    /* 1DB84C 002DB84C 98CA0A0C */  jal        func_002b2a60
    /* 1DB850 002DB850 00000000 */   nop
    /* 1DB854 002DB854 440D048E */  lw         $4, 0xD44($16)
    /* 1DB858 002DB858 38810B0C */  jal        func_002e04e0
    /* 1DB85C 002DB85C 00000000 */   nop
    /* 1DB860 002DB860 0402A693 */  lbu        $6, 0x204($29)
    /* 1DB864 002DB864 0502A593 */  lbu        $5, 0x205($29)
    /* 1DB868 002DB868 0602A493 */  lbu        $4, 0x206($29)
    /* 1DB86C 002DB86C 0702A393 */  lbu        $3, 0x207($29)
    /* 1DB870 002DB870 790046A0 */  sb         $6, 0x79($2)
    /* 1DB874 002DB874 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DB878 002DB878 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DB87C 002DB87C 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DB880 002DB880 2D204002 */  daddu      $4, $18, $0
    /* 1DB884 002DB884 98AC110C */  jal        func_0046b260
    /* 1DB888 002DB888 00000000 */   nop
    /* 1DB88C 002DB88C 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1DB890 002DB890 00088244 */  mtc1       $2, $f1
    /* 1DB894 002DB894 00000000 */  nop
    /* 1DB898 002DB898 03000146 */  div.s      $f0, $f0, $f1
    /* 1DB89C 002DB89C 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1DB8A0 002DB8A0 00000244 */  mfc1       $2, $f0
    /* 1DB8A4 002DB8A4 00000000 */  nop
    /* 1DB8A8 002DB8A8 3C9C0200 */  dsll32     $19, $2, 16
    /* 1DB8AC 002DB8AC 3F9C1300 */  dsra32     $19, $19, 16
    /* 1DB8B0 002DB8B0 440D048E */  lw         $4, 0xD44($16)
    /* 1DB8B4 002DB8B4 38810B0C */  jal        func_002e04e0
    /* 1DB8B8 002DB8B8 00000000 */   nop
    /* 1DB8BC 002DB8BC 000153A4 */  sh         $19, 0x100($2)
    /* 1DB8C0 002DB8C0 2D204002 */  daddu      $4, $18, $0
    /* 1DB8C4 002DB8C4 BCAC110C */  jal        func_0046b2f0
    /* 1DB8C8 002DB8C8 00000000 */   nop
    /* 1DB8CC 002DB8CC 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1DB8D0 002DB8D0 00088244 */  mtc1       $2, $f1
    /* 1DB8D4 002DB8D4 00000000 */  nop
    /* 1DB8D8 002DB8D8 03000146 */  div.s      $f0, $f0, $f1
    /* 1DB8DC 002DB8DC 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1DB8E0 002DB8E0 00000244 */  mfc1       $2, $f0
    /* 1DB8E4 002DB8E4 00000000 */  nop
    /* 1DB8E8 002DB8E8 3C9C0200 */  dsll32     $19, $2, 16
    /* 1DB8EC 002DB8EC 3F9C1300 */  dsra32     $19, $19, 16
    /* 1DB8F0 002DB8F0 440D048E */  lw         $4, 0xD44($16)
    /* 1DB8F4 002DB8F4 38810B0C */  jal        func_002e04e0
    /* 1DB8F8 002DB8F8 00000000 */   nop
    /* 1DB8FC 002DB8FC 020153A4 */  sh         $19, 0x102($2)
    /* 1DB900 002DB900 04002286 */  lh         $2, 0x4($17)
    /* 1DB904 002DB904 00008244 */  mtc1       $2, $f0
    /* 1DB908 002DB908 00000000 */  nop
    /* 1DB90C 002DB90C 20038046 */  cvt.s.w    $f12, $f0
    /* 1DB910 002DB910 440D048E */  lw         $4, 0xD44($16)
    /* 1DB914 002DB914 06002586 */  lh         $5, 0x6($17)
    /* 1DB918 002DB918 6C820B0C */  jal        func_002e09b0
    /* 1DB91C 002DB91C 00000000 */   nop
    /* 1DB920 002DB920 3443023C */  lui        $2, (0x43340000 >> 16)
    /* 1DB924 002DB924 00688244 */  mtc1       $2, $f13
    /* 1DB928 002DB928 000020C6 */  lwc1       $f0, 0x0($17)
    /* 1DB92C 002DB92C 006B0046 */  add.s      $f12, $f13, $f0
    /* 1DB930 002DB930 06002286 */  lh         $2, 0x6($17)
    /* 1DB934 002DB934 05004624 */  addiu      $6, $2, 0x5
    /* 1DB938 002DB938 440D048E */  lw         $4, 0xD44($16)
    /* 1DB93C 002DB93C 2D280000 */  daddu      $5, $0, $0
    /* 1DB940 002DB940 02000724 */  addiu      $7, $0, 0x2
    /* 1DB944 002DB944 50820B0C */  jal        func_002e0940
    /* 1DB948 002DB948 00000000 */   nop
    /* 1DB94C 002DB94C 2D204002 */  daddu      $4, $18, $0
    /* 1DB950 002DB950 A0B4110C */  jal        func_0046d280
    /* 1DB954 002DB954 00000000 */   nop
    /* 1DB958 002DB958 280F048E */  lw         $4, 0xF28($16)
    /* 1DB95C 002DB95C 45000524 */  addiu      $5, $0, 0x45
    /* 1DB960 002DB960 80B4110C */  jal        func_0046d200
    /* 1DB964 002DB964 00000000 */   nop
    /* 1DB968 002DB968 2D904000 */  daddu      $18, $2, $0
    /* 1DB96C 002DB96C 6400113C */  lui        $17, %hi(D_0063FA80)
    /* 1DB970 002DB970 80FA3126 */  addiu      $17, $17, %lo(D_0063FA80)
    /* 1DB974 002DB974 5C42023C */  lui        $2, (0x425C0000 >> 16)
    /* 1DB978 002DB978 00608244 */  mtc1       $2, $f12
    /* 1DB97C 002DB97C 4C0D048E */  lw         $4, 0xD4C($16)
    /* 1DB980 002DB980 56000524 */  addiu      $5, $0, 0x56
    /* 1DB984 002DB984 78820B0C */  jal        func_002e09e0
    /* 1DB988 002DB988 00000000 */   nop
    /* 1DB98C 002DB98C 1444023C */  lui        $2, (0x44140000 >> 16)
    /* 1DB990 002DB990 00608244 */  mtc1       $2, $f12
    /* 1DB994 002DB994 3FC3023C */  lui        $2, (0xC33F0000 >> 16)
    /* 1DB998 002DB998 00688244 */  mtc1       $2, $f13
    /* 1DB99C 002DB99C 6801A427 */  addiu      $4, $29, 0x168
    /* 1DB9A0 002DB9A0 5CCA0A0C */  jal        func_002b2970
    /* 1DB9A4 002DB9A4 00000000 */   nop
    /* 1DB9A8 002DB9A8 1444023C */  lui        $2, (0x44140000 >> 16)
    /* 1DB9AC 002DB9AC 00608244 */  mtc1       $2, $f12
    /* 1DB9B0 002DB9B0 35010224 */  addiu      $2, $0, 0x135
    /* 1DB9B4 002DB9B4 00008244 */  mtc1       $2, $f0
    /* 1DB9B8 002DB9B8 00000000 */  nop
    /* 1DB9BC 002DB9BC 60038046 */  cvt.s.w    $f13, $f0
    /* 1DB9C0 002DB9C0 6001A427 */  addiu      $4, $29, 0x160
    /* 1DB9C4 002DB9C4 5CCA0A0C */  jal        func_002b2970
    /* 1DB9C8 002DB9C8 00000000 */   nop
    /* 1DB9CC 002DB9CC 4C0D048E */  lw         $4, 0xD4C($16)
    /* 1DB9D0 002DB9D0 6801A5DF */  ld         $5, 0x168($29)
    /* 1DB9D4 002DB9D4 6001A6DF */  ld         $6, 0x160($29)
    /* 1DB9D8 002DB9D8 02000724 */  addiu      $7, $0, 0x2
    /* 1DB9DC 002DB9DC 05000824 */  addiu      $8, $0, 0x5
    /* 1DB9E0 002DB9E0 04000924 */  addiu      $9, $0, 0x4
    /* 1DB9E4 002DB9E4 88810B0C */  jal        func_002e0620
    /* 1DB9E8 002DB9E8 00000000 */   nop
    /* 1DB9EC 002DB9EC 0002A427 */  addiu      $4, $29, 0x200
    /* 1DB9F0 002DB9F0 E4000524 */  addiu      $5, $0, 0xE4
    /* 1DB9F4 002DB9F4 FF000624 */  addiu      $6, $0, 0xFF
    /* 1DB9F8 002DB9F8 2D380000 */  daddu      $7, $0, $0
    /* 1DB9FC 002DB9FC 2D40C000 */  daddu      $8, $6, $0
    /* 1DBA00 002DBA00 98CA0A0C */  jal        func_002b2a60
    /* 1DBA04 002DBA04 00000000 */   nop
    /* 1DBA08 002DBA08 4C0D048E */  lw         $4, 0xD4C($16)
    /* 1DBA0C 002DBA0C 38810B0C */  jal        func_002e04e0
    /* 1DBA10 002DBA10 00000000 */   nop
    /* 1DBA14 002DBA14 0002A693 */  lbu        $6, 0x200($29)
    /* 1DBA18 002DBA18 0102A593 */  lbu        $5, 0x201($29)
    /* 1DBA1C 002DBA1C 0202A493 */  lbu        $4, 0x202($29)
    /* 1DBA20 002DBA20 0302A393 */  lbu        $3, 0x203($29)
    /* 1DBA24 002DBA24 790046A0 */  sb         $6, 0x79($2)
    /* 1DBA28 002DBA28 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DBA2C 002DBA2C 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DBA30 002DBA30 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DBA34 002DBA34 2D204002 */  daddu      $4, $18, $0
    /* 1DBA38 002DBA38 98AC110C */  jal        func_0046b260
    /* 1DBA3C 002DBA3C 00000000 */   nop
    /* 1DBA40 002DBA40 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1DBA44 002DBA44 00088244 */  mtc1       $2, $f1
    /* 1DBA48 002DBA48 00000000 */  nop
    /* 1DBA4C 002DBA4C 03000146 */  div.s      $f0, $f0, $f1
    /* 1DBA50 002DBA50 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1DBA54 002DBA54 00000244 */  mfc1       $2, $f0
    /* 1DBA58 002DBA58 00000000 */  nop
    /* 1DBA5C 002DBA5C 3C9C0200 */  dsll32     $19, $2, 16
    /* 1DBA60 002DBA60 3F9C1300 */  dsra32     $19, $19, 16
    /* 1DBA64 002DBA64 4C0D048E */  lw         $4, 0xD4C($16)
    /* 1DBA68 002DBA68 38810B0C */  jal        func_002e04e0
    /* 1DBA6C 002DBA6C 00000000 */   nop
    /* 1DBA70 002DBA70 000153A4 */  sh         $19, 0x100($2)
    /* 1DBA74 002DBA74 2D204002 */  daddu      $4, $18, $0
    /* 1DBA78 002DBA78 BCAC110C */  jal        func_0046b2f0
    /* 1DBA7C 002DBA7C 00000000 */   nop
    /* 1DBA80 002DBA80 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1DBA84 002DBA84 00088244 */  mtc1       $2, $f1
    /* 1DBA88 002DBA88 00000000 */  nop
    /* 1DBA8C 002DBA8C 03000146 */  div.s      $f0, $f0, $f1
    /* 1DBA90 002DBA90 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1DBA94 002DBA94 00000244 */  mfc1       $2, $f0
    /* 1DBA98 002DBA98 00000000 */  nop
    /* 1DBA9C 002DBA9C 3C9C0200 */  dsll32     $19, $2, 16
    /* 1DBAA0 002DBAA0 3F9C1300 */  dsra32     $19, $19, 16
    /* 1DBAA4 002DBAA4 4C0D048E */  lw         $4, 0xD4C($16)
    /* 1DBAA8 002DBAA8 38810B0C */  jal        func_002e04e0
    /* 1DBAAC 002DBAAC 00000000 */   nop
    /* 1DBAB0 002DBAB0 020153A4 */  sh         $19, 0x102($2)
    /* 1DBAB4 002DBAB4 04002286 */  lh         $2, 0x4($17)
    /* 1DBAB8 002DBAB8 00008244 */  mtc1       $2, $f0
    /* 1DBABC 002DBABC 00000000 */  nop
    /* 1DBAC0 002DBAC0 20038046 */  cvt.s.w    $f12, $f0
    /* 1DBAC4 002DBAC4 4C0D048E */  lw         $4, 0xD4C($16)
    /* 1DBAC8 002DBAC8 06002586 */  lh         $5, 0x6($17)
    /* 1DBACC 002DBACC 6C820B0C */  jal        func_002e09b0
    /* 1DBAD0 002DBAD0 00000000 */   nop
    /* 1DBAD4 002DBAD4 3443023C */  lui        $2, (0x43340000 >> 16)
    /* 1DBAD8 002DBAD8 00688244 */  mtc1       $2, $f13
    /* 1DBADC 002DBADC 000020C6 */  lwc1       $f0, 0x0($17)
    /* 1DBAE0 002DBAE0 006B0046 */  add.s      $f12, $f13, $f0
    /* 1DBAE4 002DBAE4 06002286 */  lh         $2, 0x6($17)
    /* 1DBAE8 002DBAE8 05004624 */  addiu      $6, $2, 0x5
    /* 1DBAEC 002DBAEC 4C0D048E */  lw         $4, 0xD4C($16)
    /* 1DBAF0 002DBAF0 2D280000 */  daddu      $5, $0, $0
    /* 1DBAF4 002DBAF4 04000724 */  addiu      $7, $0, 0x4
    /* 1DBAF8 002DBAF8 50820B0C */  jal        func_002e0940
    /* 1DBAFC 002DBAFC 00000000 */   nop
    /* 1DBB00 002DBB00 2D204002 */  daddu      $4, $18, $0
    /* 1DBB04 002DBB04 A0B4110C */  jal        func_0046d280
    /* 1DBB08 002DBB08 00000000 */   nop
    /* 1DBB0C 002DBB0C 280F048E */  lw         $4, 0xF28($16)
    /* 1DBB10 002DBB10 46000524 */  addiu      $5, $0, 0x46
    /* 1DBB14 002DBB14 80B4110C */  jal        func_0046d200
    /* 1DBB18 002DBB18 00000000 */   nop
    /* 1DBB1C 002DBB1C 2D904000 */  daddu      $18, $2, $0
    /* 1DBB20 002DBB20 6400113C */  lui        $17, %hi(D_0063FA88)
    /* 1DBB24 002DBB24 88FA3126 */  addiu      $17, $17, %lo(D_0063FA88)
    /* 1DBB28 002DBB28 6042023C */  lui        $2, (0x42600000 >> 16)
    /* 1DBB2C 002DBB2C 00608244 */  mtc1       $2, $f12
    /* 1DBB30 002DBB30 500D048E */  lw         $4, 0xD50($16)
    /* 1DBB34 002DBB34 56000524 */  addiu      $5, $0, 0x56
    /* 1DBB38 002DBB38 78820B0C */  jal        func_002e09e0
    /* 1DBB3C 002DBB3C 00000000 */   nop
    /* 1DBB40 002DBB40 D3010224 */  addiu      $2, $0, 0x1D3
    /* 1DBB44 002DBB44 00008244 */  mtc1       $2, $f0
    /* 1DBB48 002DBB48 00000000 */  nop
    /* 1DBB4C 002DBB4C 20038046 */  cvt.s.w    $f12, $f0
    /* 1DBB50 002DBB50 F6C2023C */  lui        $2, (0xC2F60000 >> 16)
    /* 1DBB54 002DBB54 00688244 */  mtc1       $2, $f13
    /* 1DBB58 002DBB58 5801A427 */  addiu      $4, $29, 0x158
    /* 1DBB5C 002DBB5C 5CCA0A0C */  jal        func_002b2970
    /* 1DBB60 002DBB60 00000000 */   nop
    /* 1DBB64 002DBB64 D3010224 */  addiu      $2, $0, 0x1D3
    /* 1DBB68 002DBB68 00008244 */  mtc1       $2, $f0
    /* 1DBB6C 002DBB6C 00000000 */  nop
    /* 1DBB70 002DBB70 20038046 */  cvt.s.w    $f12, $f0
    /* 1DBB74 002DBB74 79010224 */  addiu      $2, $0, 0x179
    /* 1DBB78 002DBB78 00008244 */  mtc1       $2, $f0
    /* 1DBB7C 002DBB7C 00000000 */  nop
    /* 1DBB80 002DBB80 60038046 */  cvt.s.w    $f13, $f0
    /* 1DBB84 002DBB84 5001A427 */  addiu      $4, $29, 0x150
    /* 1DBB88 002DBB88 5CCA0A0C */  jal        func_002b2970
    /* 1DBB8C 002DBB8C 00000000 */   nop
    /* 1DBB90 002DBB90 500D048E */  lw         $4, 0xD50($16)
    /* 1DBB94 002DBB94 5801A5DF */  ld         $5, 0x158($29)
    /* 1DBB98 002DBB98 5001A6DF */  ld         $6, 0x150($29)
    /* 1DBB9C 002DBB9C 02000724 */  addiu      $7, $0, 0x2
    /* 1DBBA0 002DBBA0 05000824 */  addiu      $8, $0, 0x5
    /* 1DBBA4 002DBBA4 01000924 */  addiu      $9, $0, 0x1
    /* 1DBBA8 002DBBA8 88810B0C */  jal        func_002e0620
    /* 1DBBAC 002DBBAC 00000000 */   nop
    /* 1DBBB0 002DBBB0 FC01A427 */  addiu      $4, $29, 0x1FC
    /* 1DBBB4 002DBBB4 E4000524 */  addiu      $5, $0, 0xE4
    /* 1DBBB8 002DBBB8 FF000624 */  addiu      $6, $0, 0xFF
    /* 1DBBBC 002DBBBC 2D380000 */  daddu      $7, $0, $0
    /* 1DBBC0 002DBBC0 2D40C000 */  daddu      $8, $6, $0
    /* 1DBBC4 002DBBC4 98CA0A0C */  jal        func_002b2a60
    /* 1DBBC8 002DBBC8 00000000 */   nop
    /* 1DBBCC 002DBBCC 500D048E */  lw         $4, 0xD50($16)
    /* 1DBBD0 002DBBD0 38810B0C */  jal        func_002e04e0
    /* 1DBBD4 002DBBD4 00000000 */   nop
    /* 1DBBD8 002DBBD8 FC01A693 */  lbu        $6, 0x1FC($29)
    /* 1DBBDC 002DBBDC FD01A593 */  lbu        $5, 0x1FD($29)
    /* 1DBBE0 002DBBE0 FE01A493 */  lbu        $4, 0x1FE($29)
    /* 1DBBE4 002DBBE4 FF01A393 */  lbu        $3, 0x1FF($29)
    /* 1DBBE8 002DBBE8 790046A0 */  sb         $6, 0x79($2)
    /* 1DBBEC 002DBBEC 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DBBF0 002DBBF0 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DBBF4 002DBBF4 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DBBF8 002DBBF8 2D204002 */  daddu      $4, $18, $0
    /* 1DBBFC 002DBBFC 98AC110C */  jal        func_0046b260
    /* 1DBC00 002DBC00 00000000 */   nop
    /* 1DBC04 002DBC04 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1DBC08 002DBC08 00088244 */  mtc1       $2, $f1
    /* 1DBC0C 002DBC0C 00000000 */  nop
    /* 1DBC10 002DBC10 03000146 */  div.s      $f0, $f0, $f1
    /* 1DBC14 002DBC14 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1DBC18 002DBC18 00000244 */  mfc1       $2, $f0
    /* 1DBC1C 002DBC1C 00000000 */  nop
    /* 1DBC20 002DBC20 3C9C0200 */  dsll32     $19, $2, 16
    /* 1DBC24 002DBC24 3F9C1300 */  dsra32     $19, $19, 16
    /* 1DBC28 002DBC28 500D048E */  lw         $4, 0xD50($16)
    /* 1DBC2C 002DBC2C 38810B0C */  jal        func_002e04e0
    /* 1DBC30 002DBC30 00000000 */   nop
    /* 1DBC34 002DBC34 000153A4 */  sh         $19, 0x100($2)
    /* 1DBC38 002DBC38 2D204002 */  daddu      $4, $18, $0
    /* 1DBC3C 002DBC3C BCAC110C */  jal        func_0046b2f0
    /* 1DBC40 002DBC40 00000000 */   nop
    /* 1DBC44 002DBC44 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1DBC48 002DBC48 00088244 */  mtc1       $2, $f1
    /* 1DBC4C 002DBC4C 00000000 */  nop
    /* 1DBC50 002DBC50 03000146 */  div.s      $f0, $f0, $f1
    /* 1DBC54 002DBC54 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1DBC58 002DBC58 00000244 */  mfc1       $2, $f0
    /* 1DBC5C 002DBC5C 00000000 */  nop
    /* 1DBC60 002DBC60 3C9C0200 */  dsll32     $19, $2, 16
    /* 1DBC64 002DBC64 3F9C1300 */  dsra32     $19, $19, 16
    /* 1DBC68 002DBC68 500D048E */  lw         $4, 0xD50($16)
    /* 1DBC6C 002DBC6C 38810B0C */  jal        func_002e04e0
    /* 1DBC70 002DBC70 00000000 */   nop
    /* 1DBC74 002DBC74 020153A4 */  sh         $19, 0x102($2)
    /* 1DBC78 002DBC78 04002286 */  lh         $2, 0x4($17)
    /* 1DBC7C 002DBC7C 00008244 */  mtc1       $2, $f0
    /* 1DBC80 002DBC80 00000000 */  nop
    /* 1DBC84 002DBC84 20038046 */  cvt.s.w    $f12, $f0
    /* 1DBC88 002DBC88 500D048E */  lw         $4, 0xD50($16)
    /* 1DBC8C 002DBC8C 06002586 */  lh         $5, 0x6($17)
    /* 1DBC90 002DBC90 6C820B0C */  jal        func_002e09b0
    /* 1DBC94 002DBC94 00000000 */   nop
    /* 1DBC98 002DBC98 3443023C */  lui        $2, (0x43340000 >> 16)
    /* 1DBC9C 002DBC9C 00688244 */  mtc1       $2, $f13
    /* 1DBCA0 002DBCA0 000020C6 */  lwc1       $f0, 0x0($17)
    /* 1DBCA4 002DBCA4 006B0046 */  add.s      $f12, $f13, $f0
    /* 1DBCA8 002DBCA8 06002286 */  lh         $2, 0x6($17)
    /* 1DBCAC 002DBCAC 05004624 */  addiu      $6, $2, 0x5
    /* 1DBCB0 002DBCB0 500D048E */  lw         $4, 0xD50($16)
    /* 1DBCB4 002DBCB4 2D280000 */  daddu      $5, $0, $0
    /* 1DBCB8 002DBCB8 01000724 */  addiu      $7, $0, 0x1
    /* 1DBCBC 002DBCBC 50820B0C */  jal        func_002e0940
    /* 1DBCC0 002DBCC0 00000000 */   nop
    /* 1DBCC4 002DBCC4 2D204002 */  daddu      $4, $18, $0
    /* 1DBCC8 002DBCC8 A0B4110C */  jal        func_0046d280
    /* 1DBCCC 002DBCCC 00000000 */   nop
    /* 1DBCD0 002DBCD0 280F048E */  lw         $4, 0xF28($16)
    /* 1DBCD4 002DBCD4 47000524 */  addiu      $5, $0, 0x47
    /* 1DBCD8 002DBCD8 80B4110C */  jal        func_0046d200
    /* 1DBCDC 002DBCDC 00000000 */   nop
    /* 1DBCE0 002DBCE0 2D904000 */  daddu      $18, $2, $0
    /* 1DBCE4 002DBCE4 6400113C */  lui        $17, %hi(D_0063FA90)
    /* 1DBCE8 002DBCE8 90FA3126 */  addiu      $17, $17, %lo(D_0063FA90)
    /* 1DBCEC 002DBCEC 6442023C */  lui        $2, (0x42640000 >> 16)
    /* 1DBCF0 002DBCF0 00608244 */  mtc1       $2, $f12
    /* 1DBCF4 002DBCF4 540D048E */  lw         $4, 0xD54($16)
    /* 1DBCF8 002DBCF8 56000524 */  addiu      $5, $0, 0x56
    /* 1DBCFC 002DBCFC 78820B0C */  jal        func_002e09e0
    /* 1DBD00 002DBD00 00000000 */   nop
    /* 1DBD04 002DBD04 25020224 */  addiu      $2, $0, 0x225
    /* 1DBD08 002DBD08 00008244 */  mtc1       $2, $f0
    /* 1DBD0C 002DBD0C 00000000 */  nop
    /* 1DBD10 002DBD10 20038046 */  cvt.s.w    $f12, $f0
    /* 1DBD14 002DBD14 5DC3023C */  lui        $2, (0xC35D0000 >> 16)
    /* 1DBD18 002DBD18 00688244 */  mtc1       $2, $f13
    /* 1DBD1C 002DBD1C 4801A427 */  addiu      $4, $29, 0x148
    /* 1DBD20 002DBD20 5CCA0A0C */  jal        func_002b2970
    /* 1DBD24 002DBD24 00000000 */   nop
    /* 1DBD28 002DBD28 25020224 */  addiu      $2, $0, 0x225
    /* 1DBD2C 002DBD2C 00008244 */  mtc1       $2, $f0
    /* 1DBD30 002DBD30 00000000 */  nop
    /* 1DBD34 002DBD34 20038046 */  cvt.s.w    $f12, $f0
    /* 1DBD38 002DBD38 17010224 */  addiu      $2, $0, 0x117
    /* 1DBD3C 002DBD3C 00008244 */  mtc1       $2, $f0
    /* 1DBD40 002DBD40 00000000 */  nop
    /* 1DBD44 002DBD44 60038046 */  cvt.s.w    $f13, $f0
    /* 1DBD48 002DBD48 4001A427 */  addiu      $4, $29, 0x140
    /* 1DBD4C 002DBD4C 5CCA0A0C */  jal        func_002b2970
    /* 1DBD50 002DBD50 00000000 */   nop
    /* 1DBD54 002DBD54 540D048E */  lw         $4, 0xD54($16)
    /* 1DBD58 002DBD58 4801A5DF */  ld         $5, 0x148($29)
    /* 1DBD5C 002DBD5C 4001A6DF */  ld         $6, 0x140($29)
    /* 1DBD60 002DBD60 02000724 */  addiu      $7, $0, 0x2
    /* 1DBD64 002DBD64 05000824 */  addiu      $8, $0, 0x5
    /* 1DBD68 002DBD68 03000924 */  addiu      $9, $0, 0x3
    /* 1DBD6C 002DBD6C 88810B0C */  jal        func_002e0620
    /* 1DBD70 002DBD70 00000000 */   nop
    /* 1DBD74 002DBD74 F801A427 */  addiu      $4, $29, 0x1F8
    /* 1DBD78 002DBD78 E4000524 */  addiu      $5, $0, 0xE4
    /* 1DBD7C 002DBD7C FF000624 */  addiu      $6, $0, 0xFF
    /* 1DBD80 002DBD80 2D380000 */  daddu      $7, $0, $0
    /* 1DBD84 002DBD84 2D40C000 */  daddu      $8, $6, $0
    /* 1DBD88 002DBD88 98CA0A0C */  jal        func_002b2a60
    /* 1DBD8C 002DBD8C 00000000 */   nop
    /* 1DBD90 002DBD90 540D048E */  lw         $4, 0xD54($16)
    /* 1DBD94 002DBD94 38810B0C */  jal        func_002e04e0
    /* 1DBD98 002DBD98 00000000 */   nop
    /* 1DBD9C 002DBD9C F801A693 */  lbu        $6, 0x1F8($29)
    /* 1DBDA0 002DBDA0 F901A593 */  lbu        $5, 0x1F9($29)
    /* 1DBDA4 002DBDA4 FA01A493 */  lbu        $4, 0x1FA($29)
    /* 1DBDA8 002DBDA8 FB01A393 */  lbu        $3, 0x1FB($29)
    /* 1DBDAC 002DBDAC 790046A0 */  sb         $6, 0x79($2)
    /* 1DBDB0 002DBDB0 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DBDB4 002DBDB4 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DBDB8 002DBDB8 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DBDBC 002DBDBC 2D204002 */  daddu      $4, $18, $0
    /* 1DBDC0 002DBDC0 98AC110C */  jal        func_0046b260
    /* 1DBDC4 002DBDC4 00000000 */   nop
    /* 1DBDC8 002DBDC8 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1DBDCC 002DBDCC 00088244 */  mtc1       $2, $f1
    /* 1DBDD0 002DBDD0 00000000 */  nop
    /* 1DBDD4 002DBDD4 03000146 */  div.s      $f0, $f0, $f1
    /* 1DBDD8 002DBDD8 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1DBDDC 002DBDDC 00000244 */  mfc1       $2, $f0
    /* 1DBDE0 002DBDE0 00000000 */  nop
    /* 1DBDE4 002DBDE4 3C9C0200 */  dsll32     $19, $2, 16
    /* 1DBDE8 002DBDE8 3F9C1300 */  dsra32     $19, $19, 16
    /* 1DBDEC 002DBDEC 540D048E */  lw         $4, 0xD54($16)
    /* 1DBDF0 002DBDF0 38810B0C */  jal        func_002e04e0
    /* 1DBDF4 002DBDF4 00000000 */   nop
    /* 1DBDF8 002DBDF8 000153A4 */  sh         $19, 0x100($2)
    /* 1DBDFC 002DBDFC 2D204002 */  daddu      $4, $18, $0
    /* 1DBE00 002DBE00 BCAC110C */  jal        func_0046b2f0
    /* 1DBE04 002DBE04 00000000 */   nop
    /* 1DBE08 002DBE08 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1DBE0C 002DBE0C 00088244 */  mtc1       $2, $f1
    /* 1DBE10 002DBE10 00000000 */  nop
    /* 1DBE14 002DBE14 03000146 */  div.s      $f0, $f0, $f1
    /* 1DBE18 002DBE18 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1DBE1C 002DBE1C 00000244 */  mfc1       $2, $f0
    /* 1DBE20 002DBE20 00000000 */  nop
    /* 1DBE24 002DBE24 3C9C0200 */  dsll32     $19, $2, 16
    /* 1DBE28 002DBE28 3F9C1300 */  dsra32     $19, $19, 16
    /* 1DBE2C 002DBE2C 540D048E */  lw         $4, 0xD54($16)
    /* 1DBE30 002DBE30 38810B0C */  jal        func_002e04e0
    /* 1DBE34 002DBE34 00000000 */   nop
    /* 1DBE38 002DBE38 020153A4 */  sh         $19, 0x102($2)
    /* 1DBE3C 002DBE3C 04002286 */  lh         $2, 0x4($17)
    /* 1DBE40 002DBE40 00008244 */  mtc1       $2, $f0
    /* 1DBE44 002DBE44 00000000 */  nop
    /* 1DBE48 002DBE48 20038046 */  cvt.s.w    $f12, $f0
    /* 1DBE4C 002DBE4C 540D048E */  lw         $4, 0xD54($16)
    /* 1DBE50 002DBE50 06002586 */  lh         $5, 0x6($17)
    /* 1DBE54 002DBE54 6C820B0C */  jal        func_002e09b0
    /* 1DBE58 002DBE58 00000000 */   nop
    /* 1DBE5C 002DBE5C 3443023C */  lui        $2, (0x43340000 >> 16)
    /* 1DBE60 002DBE60 00688244 */  mtc1       $2, $f13
    /* 1DBE64 002DBE64 000020C6 */  lwc1       $f0, 0x0($17)
    /* 1DBE68 002DBE68 006B0046 */  add.s      $f12, $f13, $f0
    /* 1DBE6C 002DBE6C 06002286 */  lh         $2, 0x6($17)
    /* 1DBE70 002DBE70 05004624 */  addiu      $6, $2, 0x5
    /* 1DBE74 002DBE74 540D048E */  lw         $4, 0xD54($16)
    /* 1DBE78 002DBE78 2D280000 */  daddu      $5, $0, $0
    /* 1DBE7C 002DBE7C 03000724 */  addiu      $7, $0, 0x3
    /* 1DBE80 002DBE80 50820B0C */  jal        func_002e0940
    /* 1DBE84 002DBE84 00000000 */   nop
    /* 1DBE88 002DBE88 2D204002 */  daddu      $4, $18, $0
    /* 1DBE8C 002DBE8C A0B4110C */  jal        func_0046d280
    /* 1DBE90 002DBE90 00000000 */   nop
    /* 1DBE94 002DBE94 280F048E */  lw         $4, 0xF28($16)
    /* 1DBE98 002DBE98 48000524 */  addiu      $5, $0, 0x48
    /* 1DBE9C 002DBE9C 80B4110C */  jal        func_0046d200
    /* 1DBEA0 002DBEA0 00000000 */   nop
    /* 1DBEA4 002DBEA4 2D904000 */  daddu      $18, $2, $0
    /* 1DBEA8 002DBEA8 6400113C */  lui        $17, %hi(D_0063FA98)
    /* 1DBEAC 002DBEAC 98FA3126 */  addiu      $17, $17, %lo(D_0063FA98)
    /* 1DBEB0 002DBEB0 6842023C */  lui        $2, (0x42680000 >> 16)
    /* 1DBEB4 002DBEB4 00608244 */  mtc1       $2, $f12
    /* 1DBEB8 002DBEB8 580D048E */  lw         $4, 0xD58($16)
    /* 1DBEBC 002DBEBC 56000524 */  addiu      $5, $0, 0x56
    /* 1DBEC0 002DBEC0 78820B0C */  jal        func_002e09e0
    /* 1DBEC4 002DBEC4 00000000 */   nop
    /* 1DBEC8 002DBEC8 95010224 */  addiu      $2, $0, 0x195
    /* 1DBECC 002DBECC 00008244 */  mtc1       $2, $f0
    /* 1DBED0 002DBED0 00000000 */  nop
    /* 1DBED4 002DBED4 20038046 */  cvt.s.w    $f12, $f0
    /* 1DBED8 002DBED8 E2C2023C */  lui        $2, (0xC2E20000 >> 16)
    /* 1DBEDC 002DBEDC 00688244 */  mtc1       $2, $f13
    /* 1DBEE0 002DBEE0 3801A427 */  addiu      $4, $29, 0x138
    /* 1DBEE4 002DBEE4 5CCA0A0C */  jal        func_002b2970
    /* 1DBEE8 002DBEE8 00000000 */   nop
    /* 1DBEEC 002DBEEC 95010224 */  addiu      $2, $0, 0x195
    /* 1DBEF0 002DBEF0 00008244 */  mtc1       $2, $f0
    /* 1DBEF4 002DBEF4 00000000 */  nop
    /* 1DBEF8 002DBEF8 20038046 */  cvt.s.w    $f12, $f0
    /* 1DBEFC 002DBEFC 83010224 */  addiu      $2, $0, 0x183
    /* 1DBF00 002DBF00 00008244 */  mtc1       $2, $f0
    /* 1DBF04 002DBF04 00000000 */  nop
    /* 1DBF08 002DBF08 60038046 */  cvt.s.w    $f13, $f0
    /* 1DBF0C 002DBF0C 3001A427 */  addiu      $4, $29, 0x130
    /* 1DBF10 002DBF10 5CCA0A0C */  jal        func_002b2970
    /* 1DBF14 002DBF14 00000000 */   nop
    /* 1DBF18 002DBF18 580D048E */  lw         $4, 0xD58($16)
    /* 1DBF1C 002DBF1C 3801A5DF */  ld         $5, 0x138($29)
    /* 1DBF20 002DBF20 3001A6DF */  ld         $6, 0x130($29)
    /* 1DBF24 002DBF24 02000724 */  addiu      $7, $0, 0x2
    /* 1DBF28 002DBF28 05000824 */  addiu      $8, $0, 0x5
    /* 1DBF2C 002DBF2C 2D480000 */  daddu      $9, $0, $0
    /* 1DBF30 002DBF30 88810B0C */  jal        func_002e0620
    /* 1DBF34 002DBF34 00000000 */   nop
    /* 1DBF38 002DBF38 F401A427 */  addiu      $4, $29, 0x1F4
    /* 1DBF3C 002DBF3C E4000524 */  addiu      $5, $0, 0xE4
    /* 1DBF40 002DBF40 FF000624 */  addiu      $6, $0, 0xFF
    /* 1DBF44 002DBF44 2D380000 */  daddu      $7, $0, $0
    /* 1DBF48 002DBF48 2D40C000 */  daddu      $8, $6, $0
    /* 1DBF4C 002DBF4C 98CA0A0C */  jal        func_002b2a60
    /* 1DBF50 002DBF50 00000000 */   nop
    /* 1DBF54 002DBF54 580D048E */  lw         $4, 0xD58($16)
    /* 1DBF58 002DBF58 38810B0C */  jal        func_002e04e0
    /* 1DBF5C 002DBF5C 00000000 */   nop
    /* 1DBF60 002DBF60 F401A693 */  lbu        $6, 0x1F4($29)
    /* 1DBF64 002DBF64 F501A593 */  lbu        $5, 0x1F5($29)
    /* 1DBF68 002DBF68 F601A493 */  lbu        $4, 0x1F6($29)
    /* 1DBF6C 002DBF6C F701A393 */  lbu        $3, 0x1F7($29)
    /* 1DBF70 002DBF70 790046A0 */  sb         $6, 0x79($2)
    /* 1DBF74 002DBF74 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DBF78 002DBF78 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DBF7C 002DBF7C 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DBF80 002DBF80 2D204002 */  daddu      $4, $18, $0
    /* 1DBF84 002DBF84 98AC110C */  jal        func_0046b260
    /* 1DBF88 002DBF88 00000000 */   nop
    /* 1DBF8C 002DBF8C 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1DBF90 002DBF90 00088244 */  mtc1       $2, $f1
    /* 1DBF94 002DBF94 00000000 */  nop
    /* 1DBF98 002DBF98 03000146 */  div.s      $f0, $f0, $f1
    /* 1DBF9C 002DBF9C 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1DBFA0 002DBFA0 00000244 */  mfc1       $2, $f0
    /* 1DBFA4 002DBFA4 00000000 */  nop
    /* 1DBFA8 002DBFA8 3C9C0200 */  dsll32     $19, $2, 16
    /* 1DBFAC 002DBFAC 3F9C1300 */  dsra32     $19, $19, 16
    /* 1DBFB0 002DBFB0 580D048E */  lw         $4, 0xD58($16)
    /* 1DBFB4 002DBFB4 38810B0C */  jal        func_002e04e0
    /* 1DBFB8 002DBFB8 00000000 */   nop
    /* 1DBFBC 002DBFBC 000153A4 */  sh         $19, 0x100($2)
    /* 1DBFC0 002DBFC0 2D204002 */  daddu      $4, $18, $0
    /* 1DBFC4 002DBFC4 BCAC110C */  jal        func_0046b2f0
    /* 1DBFC8 002DBFC8 00000000 */   nop
    /* 1DBFCC 002DBFCC 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1DBFD0 002DBFD0 00088244 */  mtc1       $2, $f1
    /* 1DBFD4 002DBFD4 00000000 */  nop
    /* 1DBFD8 002DBFD8 03000146 */  div.s      $f0, $f0, $f1
    /* 1DBFDC 002DBFDC 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1DBFE0 002DBFE0 00000244 */  mfc1       $2, $f0
    /* 1DBFE4 002DBFE4 00000000 */  nop
    /* 1DBFE8 002DBFE8 3C9C0200 */  dsll32     $19, $2, 16
    /* 1DBFEC 002DBFEC 3F9C1300 */  dsra32     $19, $19, 16
    /* 1DBFF0 002DBFF0 580D048E */  lw         $4, 0xD58($16)
    /* 1DBFF4 002DBFF4 38810B0C */  jal        func_002e04e0
    /* 1DBFF8 002DBFF8 00000000 */   nop
    /* 1DBFFC 002DBFFC 020153A4 */  sh         $19, 0x102($2)
    /* 1DC000 002DC000 04002286 */  lh         $2, 0x4($17)
    /* 1DC004 002DC004 00008244 */  mtc1       $2, $f0
    /* 1DC008 002DC008 00000000 */  nop
    /* 1DC00C 002DC00C 20038046 */  cvt.s.w    $f12, $f0
    /* 1DC010 002DC010 580D048E */  lw         $4, 0xD58($16)
    /* 1DC014 002DC014 06002586 */  lh         $5, 0x6($17)
    /* 1DC018 002DC018 6C820B0C */  jal        func_002e09b0
    /* 1DC01C 002DC01C 00000000 */   nop
    /* 1DC020 002DC020 3443023C */  lui        $2, (0x43340000 >> 16)
    /* 1DC024 002DC024 00688244 */  mtc1       $2, $f13
    /* 1DC028 002DC028 000020C6 */  lwc1       $f0, 0x0($17)
    /* 1DC02C 002DC02C 006B0046 */  add.s      $f12, $f13, $f0
    /* 1DC030 002DC030 06002286 */  lh         $2, 0x6($17)
    /* 1DC034 002DC034 05004624 */  addiu      $6, $2, 0x5
    /* 1DC038 002DC038 580D048E */  lw         $4, 0xD58($16)
    /* 1DC03C 002DC03C 2D280000 */  daddu      $5, $0, $0
    /* 1DC040 002DC040 2D380000 */  daddu      $7, $0, $0
    /* 1DC044 002DC044 50820B0C */  jal        func_002e0940
    /* 1DC048 002DC048 00000000 */   nop
    /* 1DC04C 002DC04C 2D204002 */  daddu      $4, $18, $0
    /* 1DC050 002DC050 A0B4110C */  jal        func_0046d280
    /* 1DC054 002DC054 00000000 */   nop
    /* 1DC058 002DC058 3041023C */  lui        $2, (0x41300000 >> 16)
    /* 1DC05C 002DC05C 00608244 */  mtc1       $2, $f12
    /* 1DC060 002DC060 740D048E */  lw         $4, 0xD74($16)
    /* 1DC064 002DC064 56000524 */  addiu      $5, $0, 0x56
    /* 1DC068 002DC068 78820B0C */  jal        func_002e09e0
    /* 1DC06C 002DC06C 00000000 */   nop
    /* 1DC070 002DC070 740D048E */  lw         $4, 0xD74($16)
    /* 1DC074 002DC074 2D280000 */  daddu      $5, $0, $0
    /* 1DC078 002DC078 FF000624 */  addiu      $6, $0, 0xFF
    /* 1DC07C 002DC07C 2D380000 */  daddu      $7, $0, $0
    /* 1DC080 002DC080 0A000824 */  addiu      $8, $0, 0xA
    /* 1DC084 002DC084 2D480000 */  daddu      $9, $0, $0
    /* 1DC088 002DC088 98810B0C */  jal        func_002e0660
    /* 1DC08C 002DC08C 00000000 */   nop
    /* 1DC090 002DC090 1041023C */  lui        $2, (0x41100000 >> 16)
    /* 1DC094 002DC094 00608244 */  mtc1       $2, $f12
    /* 1DC098 002DC098 800D048E */  lw         $4, 0xD80($16)
    /* 1DC09C 002DC09C 56000524 */  addiu      $5, $0, 0x56
    /* 1DC0A0 002DC0A0 78820B0C */  jal        func_002e09e0
    /* 1DC0A4 002DC0A4 00000000 */   nop
    /* 1DC0A8 002DC0A8 800D048E */  lw         $4, 0xD80($16)
    /* 1DC0AC 002DC0AC 2D280000 */  daddu      $5, $0, $0
    /* 1DC0B0 002DC0B0 FF000624 */  addiu      $6, $0, 0xFF
    /* 1DC0B4 002DC0B4 2D380000 */  daddu      $7, $0, $0
    /* 1DC0B8 002DC0B8 0A000824 */  addiu      $8, $0, 0xA
    /* 1DC0BC 002DC0BC 2D480000 */  daddu      $9, $0, $0
    /* 1DC0C0 002DC0C0 98810B0C */  jal        func_002e0660
    /* 1DC0C4 002DC0C4 00000000 */   nop
    /* 1DC0C8 002DC0C8 180F048E */  lw         $4, 0xF18($16)
    /* 1DC0CC 002DC0CC 0400053C */  lui        $5, (0x40000 >> 16)
    /* 1DC0D0 002DC0D0 2D300000 */  daddu      $6, $0, $0
    /* 1DC0D4 002DC0D4 04000724 */  addiu      $7, $0, 0x4
    /* 1DC0D8 002DC0D8 2D400000 */  daddu      $8, $0, $0
    /* 1DC0DC 002DC0DC 588D0B0C */  jal        func_002e3560
    /* 1DC0E0 002DC0E0 00000000 */   nop
    /* 1DC0E4 002DC0E4 1C0F048E */  lw         $4, 0xF1C($16)
    /* 1DC0E8 002DC0E8 FFFF0534 */  ori        $5, $0, 0xFFFF
    /* 1DC0EC 002DC0EC E01F0624 */  addiu      $6, $0, 0x1FE0
    /* 1DC0F0 002DC0F0 01000724 */  addiu      $7, $0, 0x1
    /* 1DC0F4 002DC0F4 2D400000 */  daddu      $8, $0, $0
    /* 1DC0F8 002DC0F8 588D0B0C */  jal        func_002e3560
    /* 1DC0FC 002DC0FC 00000000 */   nop
    /* 1DC100 002DC100 200F048E */  lw         $4, 0xF20($16)
    /* 1DC104 002DC104 0100053C */  lui        $5, (0x10000 >> 16)
    /* 1DC108 002DC108 2D300000 */  daddu      $6, $0, $0
    /* 1DC10C 002DC10C 01000724 */  addiu      $7, $0, 0x1
    /* 1DC110 002DC110 2D400000 */  daddu      $8, $0, $0
    /* 1DC114 002DC114 588D0B0C */  jal        func_002e3560
    /* 1DC118 002DC118 00000000 */   nop
    /* 1DC11C 002DC11C 0B43023C */  lui        $2, (0x430B0000 >> 16)
    /* 1DC120 002DC120 00608244 */  mtc1       $2, $f12
    /* 1DC124 002DC124 8C0C048E */  lw         $4, 0xC8C($16)
    /* 1DC128 002DC128 41000524 */  addiu      $5, $0, 0x41
    /* 1DC12C 002DC12C 78820B0C */  jal        func_002e09e0
    /* 1DC130 002DC130 00000000 */   nop
    /* 1DC134 002DC134 8C0C048E */  lw         $4, 0xC8C($16)
    /* 1DC138 002DC138 2D280000 */  daddu      $5, $0, $0
    /* 1DC13C 002DC13C FF000624 */  addiu      $6, $0, 0xFF
    /* 1DC140 002DC140 2D380000 */  daddu      $7, $0, $0
    /* 1DC144 002DC144 06000824 */  addiu      $8, $0, 0x6
    /* 1DC148 002DC148 07000924 */  addiu      $9, $0, 0x7
    /* 1DC14C 002DC14C 98810B0C */  jal        func_002e0660
    /* 1DC150 002DC150 00000000 */   nop
    /* 1DC154 002DC154 F001A427 */  addiu      $4, $29, 0x1F0
    /* 1DC158 002DC158 CE000524 */  addiu      $5, $0, 0xCE
    /* 1DC15C 002DC15C 71000624 */  addiu      $6, $0, 0x71
    /* 1DC160 002DC160 02000724 */  addiu      $7, $0, 0x2
    /* 1DC164 002DC164 FF000824 */  addiu      $8, $0, 0xFF
    /* 1DC168 002DC168 98CA0A0C */  jal        func_002b2a60
    /* 1DC16C 002DC16C 00000000 */   nop
    /* 1DC170 002DC170 8C0C048E */  lw         $4, 0xC8C($16)
    /* 1DC174 002DC174 38810B0C */  jal        func_002e04e0
    /* 1DC178 002DC178 00000000 */   nop
    /* 1DC17C 002DC17C F001A693 */  lbu        $6, 0x1F0($29)
    /* 1DC180 002DC180 F101A593 */  lbu        $5, 0x1F1($29)
    /* 1DC184 002DC184 F201A493 */  lbu        $4, 0x1F2($29)
    /* 1DC188 002DC188 F301A393 */  lbu        $3, 0x1F3($29)
    /* 1DC18C 002DC18C 790046A0 */  sb         $6, 0x79($2)
    /* 1DC190 002DC190 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DC194 002DC194 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DC198 002DC198 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DC19C 002DC19C 0C43023C */  lui        $2, (0x430C0000 >> 16)
    /* 1DC1A0 002DC1A0 00608244 */  mtc1       $2, $f12
    /* 1DC1A4 002DC1A4 900C048E */  lw         $4, 0xC90($16)
    /* 1DC1A8 002DC1A8 41000524 */  addiu      $5, $0, 0x41
    /* 1DC1AC 002DC1AC 78820B0C */  jal        func_002e09e0
    /* 1DC1B0 002DC1B0 00000000 */   nop
    /* 1DC1B4 002DC1B4 900C048E */  lw         $4, 0xC90($16)
    /* 1DC1B8 002DC1B8 2D280000 */  daddu      $5, $0, $0
    /* 1DC1BC 002DC1BC FF000624 */  addiu      $6, $0, 0xFF
    /* 1DC1C0 002DC1C0 2D380000 */  daddu      $7, $0, $0
    /* 1DC1C4 002DC1C4 06000824 */  addiu      $8, $0, 0x6
    /* 1DC1C8 002DC1C8 07000924 */  addiu      $9, $0, 0x7
    /* 1DC1CC 002DC1CC 98810B0C */  jal        func_002e0660
    /* 1DC1D0 002DC1D0 00000000 */   nop
    /* 1DC1D4 002DC1D4 EC01A427 */  addiu      $4, $29, 0x1EC
    /* 1DC1D8 002DC1D8 CE000524 */  addiu      $5, $0, 0xCE
    /* 1DC1DC 002DC1DC 71000624 */  addiu      $6, $0, 0x71
    /* 1DC1E0 002DC1E0 02000724 */  addiu      $7, $0, 0x2
    /* 1DC1E4 002DC1E4 FF000824 */  addiu      $8, $0, 0xFF
    /* 1DC1E8 002DC1E8 98CA0A0C */  jal        func_002b2a60
    /* 1DC1EC 002DC1EC 00000000 */   nop
    /* 1DC1F0 002DC1F0 900C048E */  lw         $4, 0xC90($16)
    /* 1DC1F4 002DC1F4 38810B0C */  jal        func_002e04e0
    /* 1DC1F8 002DC1F8 00000000 */   nop
    /* 1DC1FC 002DC1FC EC01A693 */  lbu        $6, 0x1EC($29)
    /* 1DC200 002DC200 ED01A593 */  lbu        $5, 0x1ED($29)
    /* 1DC204 002DC204 EE01A493 */  lbu        $4, 0x1EE($29)
    /* 1DC208 002DC208 EF01A393 */  lbu        $3, 0x1EF($29)
    /* 1DC20C 002DC20C 790046A0 */  sb         $6, 0x79($2)
    /* 1DC210 002DC210 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DC214 002DC214 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DC218 002DC218 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DC21C 002DC21C 280F048E */  lw         $4, 0xF28($16)
    /* 1DC220 002DC220 03000524 */  addiu      $5, $0, 0x3
    /* 1DC224 002DC224 80B4110C */  jal        func_0046d200
    /* 1DC228 002DC228 00000000 */   nop
    /* 1DC22C 002DC22C 2D884000 */  daddu      $17, $2, $0
    /* 1DC230 002DC230 0343023C */  lui        $2, (0x43030000 >> 16)
    /* 1DC234 002DC234 00608244 */  mtc1       $2, $f12
    /* 1DC238 002DC238 C40E048E */  lw         $4, 0xEC4($16)
    /* 1DC23C 002DC23C 56000524 */  addiu      $5, $0, 0x56
    /* 1DC240 002DC240 78820B0C */  jal        func_002e09e0
    /* 1DC244 002DC244 00000000 */   nop
    /* 1DC248 002DC248 C041023C */  lui        $2, (0x41C00000 >> 16)
    /* 1DC24C 002DC24C 00608244 */  mtc1       $2, $f12
    /* 1DC250 002DC250 70C2023C */  lui        $2, (0xC2700000 >> 16)
    /* 1DC254 002DC254 00688244 */  mtc1       $2, $f13
    /* 1DC258 002DC258 2801A427 */  addiu      $4, $29, 0x128
    /* 1DC25C 002DC25C 5CCA0A0C */  jal        func_002b2970
    /* 1DC260 002DC260 00000000 */   nop
    /* 1DC264 002DC264 C041023C */  lui        $2, (0x41C00000 >> 16)
    /* 1DC268 002DC268 00608244 */  mtc1       $2, $f12
    /* 1DC26C 002DC26C 4042023C */  lui        $2, (0x42400000 >> 16)
    /* 1DC270 002DC270 00688244 */  mtc1       $2, $f13
    /* 1DC274 002DC274 2001A427 */  addiu      $4, $29, 0x120
    /* 1DC278 002DC278 5CCA0A0C */  jal        func_002b2970
    /* 1DC27C 002DC27C 00000000 */   nop
    /* 1DC280 002DC280 C40E048E */  lw         $4, 0xEC4($16)
    /* 1DC284 002DC284 2801A5DF */  ld         $5, 0x128($29)
    /* 1DC288 002DC288 2001A6DF */  ld         $6, 0x120($29)
    /* 1DC28C 002DC28C 02000724 */  addiu      $7, $0, 0x2
    /* 1DC290 002DC290 07000824 */  addiu      $8, $0, 0x7
    /* 1DC294 002DC294 05000924 */  addiu      $9, $0, 0x5
    /* 1DC298 002DC298 88810B0C */  jal        func_002e0620
    /* 1DC29C 002DC29C 00000000 */   nop
    /* 1DC2A0 002DC2A0 FF001224 */  addiu      $18, $0, 0xFF
    /* 1DC2A4 002DC2A4 C40E048E */  lw         $4, 0xEC4($16)
    /* 1DC2A8 002DC2A8 38810B0C */  jal        func_002e04e0
    /* 1DC2AC 002DC2AC 00000000 */   nop
    /* 1DC2B0 002DC2B0 620052A0 */  sb         $18, 0x62($2)
    /* 1DC2B4 002DC2B4 55001224 */  addiu      $18, $0, 0x55
    /* 1DC2B8 002DC2B8 C40E048E */  lw         $4, 0xEC4($16)
    /* 1DC2BC 002DC2BC 38810B0C */  jal        func_002e04e0
    /* 1DC2C0 002DC2C0 00000000 */   nop
    /* 1DC2C4 002DC2C4 000152A4 */  sh         $18, 0x100($2)
    /* 1DC2C8 002DC2C8 17001224 */  addiu      $18, $0, 0x17
    /* 1DC2CC 002DC2CC C40E048E */  lw         $4, 0xEC4($16)
    /* 1DC2D0 002DC2D0 38810B0C */  jal        func_002e04e0
    /* 1DC2D4 002DC2D4 00000000 */   nop
    /* 1DC2D8 002DC2D8 020152A4 */  sh         $18, 0x102($2)
    /* 1DC2DC 002DC2DC 40C0023C */  lui        $2, (0xC0400000 >> 16)
    /* 1DC2E0 002DC2E0 00608244 */  mtc1       $2, $f12
    /* 1DC2E4 002DC2E4 C40E048E */  lw         $4, 0xEC4($16)
    /* 1DC2E8 002DC2E8 46630046 */  mov.s      $f13, $f12
    /* 1DC2EC 002DC2EC 2D280000 */  daddu      $5, $0, $0
    /* 1DC2F0 002DC2F0 2D300000 */  daddu      $6, $0, $0
    /* 1DC2F4 002DC2F4 2D380000 */  daddu      $7, $0, $0
    /* 1DC2F8 002DC2F8 50820B0C */  jal        func_002e0940
    /* 1DC2FC 002DC2FC 00000000 */   nop
    /* 1DC300 002DC300 E801A427 */  addiu      $4, $29, 0x1E8
    /* 1DC304 002DC304 FF000524 */  addiu      $5, $0, 0xFF
    /* 1DC308 002DC308 96000624 */  addiu      $6, $0, 0x96
    /* 1DC30C 002DC30C 2D380000 */  daddu      $7, $0, $0
    /* 1DC310 002DC310 2D40A000 */  daddu      $8, $5, $0
    /* 1DC314 002DC314 98CA0A0C */  jal        func_002b2a60
    /* 1DC318 002DC318 00000000 */   nop
    /* 1DC31C 002DC31C C40E048E */  lw         $4, 0xEC4($16)
    /* 1DC320 002DC320 38810B0C */  jal        func_002e04e0
    /* 1DC324 002DC324 00000000 */   nop
    /* 1DC328 002DC328 E801A693 */  lbu        $6, 0x1E8($29)
    /* 1DC32C 002DC32C E901A593 */  lbu        $5, 0x1E9($29)
    /* 1DC330 002DC330 EA01A493 */  lbu        $4, 0x1EA($29)
    /* 1DC334 002DC334 EB01A393 */  lbu        $3, 0x1EB($29)
    /* 1DC338 002DC338 790046A0 */  sb         $6, 0x79($2)
    /* 1DC33C 002DC33C 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DC340 002DC340 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DC344 002DC344 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DC348 002DC348 2D202002 */  daddu      $4, $17, $0
    /* 1DC34C 002DC34C A0B4110C */  jal        func_0046d280
    /* 1DC350 002DC350 00000000 */   nop
    /* 1DC354 002DC354 280F048E */  lw         $4, 0xF28($16)
    /* 1DC358 002DC358 04000524 */  addiu      $5, $0, 0x4
    /* 1DC35C 002DC35C 80B4110C */  jal        func_0046d200
    /* 1DC360 002DC360 00000000 */   nop
    /* 1DC364 002DC364 2D884000 */  daddu      $17, $2, $0
    /* 1DC368 002DC368 0443023C */  lui        $2, (0x43040000 >> 16)
    /* 1DC36C 002DC36C 00608244 */  mtc1       $2, $f12
    /* 1DC370 002DC370 C80E048E */  lw         $4, 0xEC8($16)
    /* 1DC374 002DC374 56000524 */  addiu      $5, $0, 0x56
    /* 1DC378 002DC378 78820B0C */  jal        func_002e09e0
    /* 1DC37C 002DC37C 00000000 */   nop
    /* 1DC380 002DC380 8042023C */  lui        $2, (0x42800000 >> 16)
    /* 1DC384 002DC384 00608244 */  mtc1       $2, $f12
    /* 1DC388 002DC388 70C2023C */  lui        $2, (0xC2700000 >> 16)
    /* 1DC38C 002DC38C 00688244 */  mtc1       $2, $f13
    /* 1DC390 002DC390 1801A427 */  addiu      $4, $29, 0x118
    /* 1DC394 002DC394 5CCA0A0C */  jal        func_002b2970
    /* 1DC398 002DC398 00000000 */   nop
    /* 1DC39C 002DC39C 8042023C */  lui        $2, (0x42800000 >> 16)
    /* 1DC3A0 002DC3A0 00608244 */  mtc1       $2, $f12
    /* 1DC3A4 002DC3A4 4042023C */  lui        $2, (0x42400000 >> 16)
    /* 1DC3A8 002DC3A8 00688244 */  mtc1       $2, $f13
    /* 1DC3AC 002DC3AC 1001A427 */  addiu      $4, $29, 0x110
    /* 1DC3B0 002DC3B0 5CCA0A0C */  jal        func_002b2970
    /* 1DC3B4 002DC3B4 00000000 */   nop
    /* 1DC3B8 002DC3B8 C80E048E */  lw         $4, 0xEC8($16)
    /* 1DC3BC 002DC3BC 1801A5DF */  ld         $5, 0x118($29)
    /* 1DC3C0 002DC3C0 1001A6DF */  ld         $6, 0x110($29)
    /* 1DC3C4 002DC3C4 02000724 */  addiu      $7, $0, 0x2
    /* 1DC3C8 002DC3C8 07000824 */  addiu      $8, $0, 0x7
    /* 1DC3CC 002DC3CC 05000924 */  addiu      $9, $0, 0x5
    /* 1DC3D0 002DC3D0 88810B0C */  jal        func_002e0620
    /* 1DC3D4 002DC3D4 00000000 */   nop
    /* 1DC3D8 002DC3D8 FF001224 */  addiu      $18, $0, 0xFF
    /* 1DC3DC 002DC3DC C80E048E */  lw         $4, 0xEC8($16)
    /* 1DC3E0 002DC3E0 38810B0C */  jal        func_002e04e0
    /* 1DC3E4 002DC3E4 00000000 */   nop
    /* 1DC3E8 002DC3E8 620052A0 */  sb         $18, 0x62($2)
    /* 1DC3EC 002DC3EC 2D202002 */  daddu      $4, $17, $0
    /* 1DC3F0 002DC3F0 98AC110C */  jal        func_0046b260
    /* 1DC3F4 002DC3F4 00000000 */   nop
    /* 1DC3F8 002DC3F8 AA42023C */  lui        $2, (0x42AA0000 >> 16)
    /* 1DC3FC 002DC3FC 00088244 */  mtc1       $2, $f1
    /* 1DC400 002DC400 00000000 */  nop
    /* 1DC404 002DC404 01000146 */  sub.s      $f0, $f0, $f1
    /* 1DC408 002DC408 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1DC40C 002DC40C 00000244 */  mfc1       $2, $f0
    /* 1DC410 002DC410 00000000 */  nop
    /* 1DC414 002DC414 3C940200 */  dsll32     $18, $2, 16
    /* 1DC418 002DC418 3F941200 */  dsra32     $18, $18, 16
    /* 1DC41C 002DC41C C80E048E */  lw         $4, 0xEC8($16)
    /* 1DC420 002DC420 38810B0C */  jal        func_002e04e0
    /* 1DC424 002DC424 00000000 */   nop
    /* 1DC428 002DC428 000152A4 */  sh         $18, 0x100($2)
    /* 1DC42C 002DC42C 17001224 */  addiu      $18, $0, 0x17
    /* 1DC430 002DC430 C80E048E */  lw         $4, 0xEC8($16)
    /* 1DC434 002DC434 38810B0C */  jal        func_002e04e0
    /* 1DC438 002DC438 00000000 */   nop
    /* 1DC43C 002DC43C 020152A4 */  sh         $18, 0x102($2)
    /* 1DC440 002DC440 40C0023C */  lui        $2, (0xC0400000 >> 16)
    /* 1DC444 002DC444 00608244 */  mtc1       $2, $f12
    /* 1DC448 002DC448 C80E048E */  lw         $4, 0xEC8($16)
    /* 1DC44C 002DC44C 46630046 */  mov.s      $f13, $f12
    /* 1DC450 002DC450 2D280000 */  daddu      $5, $0, $0
    /* 1DC454 002DC454 2D300000 */  daddu      $6, $0, $0
    /* 1DC458 002DC458 2D380000 */  daddu      $7, $0, $0
    /* 1DC45C 002DC45C 50820B0C */  jal        func_002e0940
    /* 1DC460 002DC460 00000000 */   nop
    /* 1DC464 002DC464 E401A427 */  addiu      $4, $29, 0x1E4
    /* 1DC468 002DC468 FF000524 */  addiu      $5, $0, 0xFF
    /* 1DC46C 002DC46C 96000624 */  addiu      $6, $0, 0x96
    /* 1DC470 002DC470 2D380000 */  daddu      $7, $0, $0
    /* 1DC474 002DC474 2D40A000 */  daddu      $8, $5, $0
    /* 1DC478 002DC478 98CA0A0C */  jal        func_002b2a60
    /* 1DC47C 002DC47C 00000000 */   nop
    /* 1DC480 002DC480 C80E048E */  lw         $4, 0xEC8($16)
    /* 1DC484 002DC484 38810B0C */  jal        func_002e04e0
    /* 1DC488 002DC488 00000000 */   nop
    /* 1DC48C 002DC48C E401A693 */  lbu        $6, 0x1E4($29)
    /* 1DC490 002DC490 E501A593 */  lbu        $5, 0x1E5($29)
    /* 1DC494 002DC494 E601A493 */  lbu        $4, 0x1E6($29)
    /* 1DC498 002DC498 E701A393 */  lbu        $3, 0x1E7($29)
    /* 1DC49C 002DC49C 790046A0 */  sb         $6, 0x79($2)
    /* 1DC4A0 002DC4A0 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DC4A4 002DC4A4 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DC4A8 002DC4A8 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DC4AC 002DC4AC 2D202002 */  daddu      $4, $17, $0
    /* 1DC4B0 002DC4B0 A0B4110C */  jal        func_0046d280
    /* 1DC4B4 002DC4B4 00000000 */   nop
    /* 1DC4B8 002DC4B8 0243023C */  lui        $2, (0x43020000 >> 16)
    /* 1DC4BC 002DC4BC 00608244 */  mtc1       $2, $f12
    /* 1DC4C0 002DC4C0 380E048E */  lw         $4, 0xE38($16)
    /* 1DC4C4 002DC4C4 57000524 */  addiu      $5, $0, 0x57
    /* 1DC4C8 002DC4C8 78820B0C */  jal        func_002e09e0
    /* 1DC4CC 002DC4CC 00000000 */   nop
    /* 1DC4D0 002DC4D0 5042023C */  lui        $2, (0x42500000 >> 16)
    /* 1DC4D4 002DC4D4 00608244 */  mtc1       $2, $f12
    /* 1DC4D8 002DC4D8 70C2023C */  lui        $2, (0xC2700000 >> 16)
    /* 1DC4DC 002DC4DC 00688244 */  mtc1       $2, $f13
    /* 1DC4E0 002DC4E0 0801A427 */  addiu      $4, $29, 0x108
    /* 1DC4E4 002DC4E4 5CCA0A0C */  jal        func_002b2970
    /* 1DC4E8 002DC4E8 00000000 */   nop
    /* 1DC4EC 002DC4EC 5042023C */  lui        $2, (0x42500000 >> 16)
    /* 1DC4F0 002DC4F0 00608244 */  mtc1       $2, $f12
    /* 1DC4F4 002DC4F4 6C42023C */  lui        $2, (0x426C0000 >> 16)
    /* 1DC4F8 002DC4F8 00688244 */  mtc1       $2, $f13
    /* 1DC4FC 002DC4FC 0001A427 */  addiu      $4, $29, 0x100
    /* 1DC500 002DC500 5CCA0A0C */  jal        func_002b2970
    /* 1DC504 002DC504 00000000 */   nop
    /* 1DC508 002DC508 380E048E */  lw         $4, 0xE38($16)
    /* 1DC50C 002DC50C 0801A5DF */  ld         $5, 0x108($29)
    /* 1DC510 002DC510 0001A6DF */  ld         $6, 0x100($29)
    /* 1DC514 002DC514 02000724 */  addiu      $7, $0, 0x2
    /* 1DC518 002DC518 07000824 */  addiu      $8, $0, 0x7
    /* 1DC51C 002DC51C 05000924 */  addiu      $9, $0, 0x5
    /* 1DC520 002DC520 88810B0C */  jal        func_002e0620
    /* 1DC524 002DC524 00000000 */   nop
    /* 1DC528 002DC528 40C0023C */  lui        $2, (0xC0400000 >> 16)
    /* 1DC52C 002DC52C 00608244 */  mtc1       $2, $f12
    /* 1DC530 002DC530 380E048E */  lw         $4, 0xE38($16)
    /* 1DC534 002DC534 46630046 */  mov.s      $f13, $f12
    /* 1DC538 002DC538 2D280000 */  daddu      $5, $0, $0
    /* 1DC53C 002DC53C 2D300000 */  daddu      $6, $0, $0
    /* 1DC540 002DC540 2D380000 */  daddu      $7, $0, $0
    /* 1DC544 002DC544 50820B0C */  jal        func_002e0940
    /* 1DC548 002DC548 00000000 */   nop
    /* 1DC54C 002DC54C FF001124 */  addiu      $17, $0, 0xFF
    /* 1DC550 002DC550 380E048E */  lw         $4, 0xE38($16)
    /* 1DC554 002DC554 38810B0C */  jal        func_002e04e0
    /* 1DC558 002DC558 00000000 */   nop
    /* 1DC55C 002DC55C 620051A0 */  sb         $17, 0x62($2)
    /* 1DC560 002DC560 E001A427 */  addiu      $4, $29, 0x1E0
    /* 1DC564 002DC564 2D282002 */  daddu      $5, $17, $0
    /* 1DC568 002DC568 F2000624 */  addiu      $6, $0, 0xF2
    /* 1DC56C 002DC56C 95000724 */  addiu      $7, $0, 0x95
    /* 1DC570 002DC570 2D40A000 */  daddu      $8, $5, $0
    /* 1DC574 002DC574 98CA0A0C */  jal        func_002b2a60
    /* 1DC578 002DC578 00000000 */   nop
    /* 1DC57C 002DC57C 380E048E */  lw         $4, 0xE38($16)
    /* 1DC580 002DC580 38810B0C */  jal        func_002e04e0
    /* 1DC584 002DC584 00000000 */   nop
    /* 1DC588 002DC588 E001A693 */  lbu        $6, 0x1E0($29)
    /* 1DC58C 002DC58C E101A593 */  lbu        $5, 0x1E1($29)
    /* 1DC590 002DC590 E201A493 */  lbu        $4, 0x1E2($29)
    /* 1DC594 002DC594 E301A393 */  lbu        $3, 0x1E3($29)
    /* 1DC598 002DC598 790046A0 */  sb         $6, 0x79($2)
    /* 1DC59C 002DC59C 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DC5A0 002DC5A0 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DC5A4 002DC5A4 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DC5A8 002DC5A8 180F048E */  lw         $4, 0xF18($16)
    /* 1DC5AC 002DC5AC BC890B0C */  jal        func_002e26f0
    /* 1DC5B0 002DC5B0 00000000 */   nop
    /* 1DC5B4 002DC5B4 7500033C */  lui        $3, %hi(D_00748908)
    /* 1DC5B8 002DC5B8 08896380 */  lb         $3, %lo(D_00748908)($3)
    /* 1DC5BC 002DC5BC 2A086200 */  slt        $1, $3, $2
    /* 1DC5C0 002DC5C0 37002014 */  bnez       $1, .L002DC6A0
    /* 1DC5C4 002DC5C4 00000000 */   nop
    /* 1DC5C8 002DC5C8 DC01A427 */  addiu      $4, $29, 0x1DC
    /* 1DC5CC 002DC5CC 9C000524 */  addiu      $5, $0, 0x9C
    /* 1DC5D0 002DC5D0 2D30A000 */  daddu      $6, $5, $0
    /* 1DC5D4 002DC5D4 2D38A000 */  daddu      $7, $5, $0
    /* 1DC5D8 002DC5D8 2D402002 */  daddu      $8, $17, $0
    /* 1DC5DC 002DC5DC 98CA0A0C */  jal        func_002b2a60
    /* 1DC5E0 002DC5E0 00000000 */   nop
    /* 1DC5E4 002DC5E4 C40E048E */  lw         $4, 0xEC4($16)
    /* 1DC5E8 002DC5E8 38810B0C */  jal        func_002e04e0
    /* 1DC5EC 002DC5EC 00000000 */   nop
    /* 1DC5F0 002DC5F0 DC01A693 */  lbu        $6, 0x1DC($29)
    /* 1DC5F4 002DC5F4 DD01A593 */  lbu        $5, 0x1DD($29)
    /* 1DC5F8 002DC5F8 DE01A493 */  lbu        $4, 0x1DE($29)
    /* 1DC5FC 002DC5FC DF01A393 */  lbu        $3, 0x1DF($29)
    /* 1DC600 002DC600 790046A0 */  sb         $6, 0x79($2)
    /* 1DC604 002DC604 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DC608 002DC608 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DC60C 002DC60C 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DC610 002DC610 D801A427 */  addiu      $4, $29, 0x1D8
    /* 1DC614 002DC614 9C000524 */  addiu      $5, $0, 0x9C
    /* 1DC618 002DC618 2D30A000 */  daddu      $6, $5, $0
    /* 1DC61C 002DC61C 2D38A000 */  daddu      $7, $5, $0
    /* 1DC620 002DC620 2D402002 */  daddu      $8, $17, $0
    /* 1DC624 002DC624 98CA0A0C */  jal        func_002b2a60
    /* 1DC628 002DC628 00000000 */   nop
    /* 1DC62C 002DC62C C80E048E */  lw         $4, 0xEC8($16)
    /* 1DC630 002DC630 38810B0C */  jal        func_002e04e0
    /* 1DC634 002DC634 00000000 */   nop
    /* 1DC638 002DC638 D801A693 */  lbu        $6, 0x1D8($29)
    /* 1DC63C 002DC63C D901A593 */  lbu        $5, 0x1D9($29)
    /* 1DC640 002DC640 DA01A493 */  lbu        $4, 0x1DA($29)
    /* 1DC644 002DC644 DB01A393 */  lbu        $3, 0x1DB($29)
    /* 1DC648 002DC648 790046A0 */  sb         $6, 0x79($2)
    /* 1DC64C 002DC64C 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DC650 002DC650 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DC654 002DC654 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DC658 002DC658 D401A427 */  addiu      $4, $29, 0x1D4
    /* 1DC65C 002DC65C 2D282002 */  daddu      $5, $17, $0
    /* 1DC660 002DC660 2D30A000 */  daddu      $6, $5, $0
    /* 1DC664 002DC664 2D38A000 */  daddu      $7, $5, $0
    /* 1DC668 002DC668 2D40A000 */  daddu      $8, $5, $0
    /* 1DC66C 002DC66C 98CA0A0C */  jal        func_002b2a60
    /* 1DC670 002DC670 00000000 */   nop
    /* 1DC674 002DC674 380E048E */  lw         $4, 0xE38($16)
    /* 1DC678 002DC678 38810B0C */  jal        func_002e04e0
    /* 1DC67C 002DC67C 00000000 */   nop
    /* 1DC680 002DC680 D401A693 */  lbu        $6, 0x1D4($29)
    /* 1DC684 002DC684 D501A593 */  lbu        $5, 0x1D5($29)
    /* 1DC688 002DC688 D601A493 */  lbu        $4, 0x1D6($29)
    /* 1DC68C 002DC68C D701A393 */  lbu        $3, 0x1D7($29)
    /* 1DC690 002DC690 790046A0 */  sb         $6, 0x79($2)
    /* 1DC694 002DC694 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DC698 002DC698 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DC69C 002DC69C 7C0043A0 */  sb         $3, 0x7C($2)
  .L002DC6A0:
    /* 1DC6A0 002DC6A0 280F048E */  lw         $4, 0xF28($16)
    /* 1DC6A4 002DC6A4 03000524 */  addiu      $5, $0, 0x3
    /* 1DC6A8 002DC6A8 80B4110C */  jal        func_0046d200
    /* 1DC6AC 002DC6AC 00000000 */   nop
    /* 1DC6B0 002DC6B0 2D884000 */  daddu      $17, $2, $0
    /* 1DC6B4 002DC6B4 0943023C */  lui        $2, (0x43090000 >> 16)
    /* 1DC6B8 002DC6B8 00608244 */  mtc1       $2, $f12
    /* 1DC6BC 002DC6BC B40E048E */  lw         $4, 0xEB4($16)
    /* 1DC6C0 002DC6C0 41000524 */  addiu      $5, $0, 0x41
    /* 1DC6C4 002DC6C4 78820B0C */  jal        func_002e09e0
    /* 1DC6C8 002DC6C8 00000000 */   nop
    /* 1DC6CC 002DC6CC 1243023C */  lui        $2, (0x43120000 >> 16)
    /* 1DC6D0 002DC6D0 00608244 */  mtc1       $2, $f12
    /* 1DC6D4 002DC6D4 70C2023C */  lui        $2, (0xC2700000 >> 16)
    /* 1DC6D8 002DC6D8 00688244 */  mtc1       $2, $f13
    /* 1DC6DC 002DC6DC F800A427 */  addiu      $4, $29, 0xF8
    /* 1DC6E0 002DC6E0 5CCA0A0C */  jal        func_002b2970
    /* 1DC6E4 002DC6E4 00000000 */   nop
    /* 1DC6E8 002DC6E8 1243023C */  lui        $2, (0x43120000 >> 16)
    /* 1DC6EC 002DC6EC 00608244 */  mtc1       $2, $f12
    /* 1DC6F0 002DC6F0 2042023C */  lui        $2, (0x42200000 >> 16)
    /* 1DC6F4 002DC6F4 00688244 */  mtc1       $2, $f13
    /* 1DC6F8 002DC6F8 F000A427 */  addiu      $4, $29, 0xF0
    /* 1DC6FC 002DC6FC 5CCA0A0C */  jal        func_002b2970
    /* 1DC700 002DC700 00000000 */   nop
    /* 1DC704 002DC704 B40E048E */  lw         $4, 0xEB4($16)
    /* 1DC708 002DC708 F800A5DF */  ld         $5, 0xF8($29)
    /* 1DC70C 002DC70C F000A6DF */  ld         $6, 0xF0($29)
    /* 1DC710 002DC710 02000724 */  addiu      $7, $0, 0x2
    /* 1DC714 002DC714 07000824 */  addiu      $8, $0, 0x7
    /* 1DC718 002DC718 05000924 */  addiu      $9, $0, 0x5
    /* 1DC71C 002DC71C 88810B0C */  jal        func_002e0620
    /* 1DC720 002DC720 00000000 */   nop
    /* 1DC724 002DC724 FF001224 */  addiu      $18, $0, 0xFF
    /* 1DC728 002DC728 B40E048E */  lw         $4, 0xEB4($16)
    /* 1DC72C 002DC72C 38810B0C */  jal        func_002e04e0
    /* 1DC730 002DC730 00000000 */   nop
    /* 1DC734 002DC734 620052A0 */  sb         $18, 0x62($2)
    /* 1DC738 002DC738 55001224 */  addiu      $18, $0, 0x55
    /* 1DC73C 002DC73C B40E048E */  lw         $4, 0xEB4($16)
    /* 1DC740 002DC740 38810B0C */  jal        func_002e04e0
    /* 1DC744 002DC744 00000000 */   nop
    /* 1DC748 002DC748 000152A4 */  sh         $18, 0x100($2)
    /* 1DC74C 002DC74C 17001224 */  addiu      $18, $0, 0x17
    /* 1DC750 002DC750 B40E048E */  lw         $4, 0xEB4($16)
    /* 1DC754 002DC754 38810B0C */  jal        func_002e04e0
    /* 1DC758 002DC758 00000000 */   nop
    /* 1DC75C 002DC75C 020152A4 */  sh         $18, 0x102($2)
    /* 1DC760 002DC760 D001A427 */  addiu      $4, $29, 0x1D0
    /* 1DC764 002DC764 BD000524 */  addiu      $5, $0, 0xBD
    /* 1DC768 002DC768 68000624 */  addiu      $6, $0, 0x68
    /* 1DC76C 002DC76C 03000724 */  addiu      $7, $0, 0x3
    /* 1DC770 002DC770 FF000824 */  addiu      $8, $0, 0xFF
    /* 1DC774 002DC774 98CA0A0C */  jal        func_002b2a60
    /* 1DC778 002DC778 00000000 */   nop
    /* 1DC77C 002DC77C B40E048E */  lw         $4, 0xEB4($16)
    /* 1DC780 002DC780 38810B0C */  jal        func_002e04e0
    /* 1DC784 002DC784 00000000 */   nop
    /* 1DC788 002DC788 D001A693 */  lbu        $6, 0x1D0($29)
    /* 1DC78C 002DC78C D101A593 */  lbu        $5, 0x1D1($29)
    /* 1DC790 002DC790 D201A493 */  lbu        $4, 0x1D2($29)
    /* 1DC794 002DC794 D301A393 */  lbu        $3, 0x1D3($29)
    /* 1DC798 002DC798 790046A0 */  sb         $6, 0x79($2)
    /* 1DC79C 002DC79C 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DC7A0 002DC7A0 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DC7A4 002DC7A4 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DC7A8 002DC7A8 2D202002 */  daddu      $4, $17, $0
    /* 1DC7AC 002DC7AC A0B4110C */  jal        func_0046d280
    /* 1DC7B0 002DC7B0 00000000 */   nop
    /* 1DC7B4 002DC7B4 280F048E */  lw         $4, 0xF28($16)
    /* 1DC7B8 002DC7B8 04000524 */  addiu      $5, $0, 0x4
    /* 1DC7BC 002DC7BC 80B4110C */  jal        func_0046d200
    /* 1DC7C0 002DC7C0 00000000 */   nop
    /* 1DC7C4 002DC7C4 2D884000 */  daddu      $17, $2, $0
    /* 1DC7C8 002DC7C8 0A43023C */  lui        $2, (0x430A0000 >> 16)
    /* 1DC7CC 002DC7CC 00608244 */  mtc1       $2, $f12
    /* 1DC7D0 002DC7D0 B80E048E */  lw         $4, 0xEB8($16)
    /* 1DC7D4 002DC7D4 41000524 */  addiu      $5, $0, 0x41
    /* 1DC7D8 002DC7D8 78820B0C */  jal        func_002e09e0
    /* 1DC7DC 002DC7DC 00000000 */   nop
    /* 1DC7E0 002DC7E0 3A43023C */  lui        $2, (0x433A0000 >> 16)
    /* 1DC7E4 002DC7E4 00608244 */  mtc1       $2, $f12
    /* 1DC7E8 002DC7E8 70C2023C */  lui        $2, (0xC2700000 >> 16)
    /* 1DC7EC 002DC7EC 00688244 */  mtc1       $2, $f13
    /* 1DC7F0 002DC7F0 E800A427 */  addiu      $4, $29, 0xE8
    /* 1DC7F4 002DC7F4 5CCA0A0C */  jal        func_002b2970
    /* 1DC7F8 002DC7F8 00000000 */   nop
    /* 1DC7FC 002DC7FC 3A43023C */  lui        $2, (0x433A0000 >> 16)
    /* 1DC800 002DC800 00608244 */  mtc1       $2, $f12
    /* 1DC804 002DC804 2042023C */  lui        $2, (0x42200000 >> 16)
    /* 1DC808 002DC808 00688244 */  mtc1       $2, $f13
    /* 1DC80C 002DC80C E000A427 */  addiu      $4, $29, 0xE0
    /* 1DC810 002DC810 5CCA0A0C */  jal        func_002b2970
    /* 1DC814 002DC814 00000000 */   nop
    /* 1DC818 002DC818 B80E048E */  lw         $4, 0xEB8($16)
    /* 1DC81C 002DC81C E800A5DF */  ld         $5, 0xE8($29)
    /* 1DC820 002DC820 E000A6DF */  ld         $6, 0xE0($29)
    /* 1DC824 002DC824 02000724 */  addiu      $7, $0, 0x2
    /* 1DC828 002DC828 07000824 */  addiu      $8, $0, 0x7
    /* 1DC82C 002DC82C 05000924 */  addiu      $9, $0, 0x5
    /* 1DC830 002DC830 88810B0C */  jal        func_002e0620
    /* 1DC834 002DC834 00000000 */   nop
    /* 1DC838 002DC838 FF001224 */  addiu      $18, $0, 0xFF
    /* 1DC83C 002DC83C B80E048E */  lw         $4, 0xEB8($16)
    /* 1DC840 002DC840 38810B0C */  jal        func_002e04e0
    /* 1DC844 002DC844 00000000 */   nop
    /* 1DC848 002DC848 620052A0 */  sb         $18, 0x62($2)
    /* 1DC84C 002DC84C 2D202002 */  daddu      $4, $17, $0
    /* 1DC850 002DC850 98AC110C */  jal        func_0046b260
    /* 1DC854 002DC854 00000000 */   nop
    /* 1DC858 002DC858 AA42023C */  lui        $2, (0x42AA0000 >> 16)
    /* 1DC85C 002DC85C 00088244 */  mtc1       $2, $f1
    /* 1DC860 002DC860 00000000 */  nop
    /* 1DC864 002DC864 01000146 */  sub.s      $f0, $f0, $f1
    /* 1DC868 002DC868 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1DC86C 002DC86C 00000244 */  mfc1       $2, $f0
    /* 1DC870 002DC870 00000000 */  nop
    /* 1DC874 002DC874 3C940200 */  dsll32     $18, $2, 16
    /* 1DC878 002DC878 3F941200 */  dsra32     $18, $18, 16
    /* 1DC87C 002DC87C B80E048E */  lw         $4, 0xEB8($16)
    /* 1DC880 002DC880 38810B0C */  jal        func_002e04e0
    /* 1DC884 002DC884 00000000 */   nop
    /* 1DC888 002DC888 000152A4 */  sh         $18, 0x100($2)
    /* 1DC88C 002DC88C 17001224 */  addiu      $18, $0, 0x17
    /* 1DC890 002DC890 B80E048E */  lw         $4, 0xEB8($16)
    /* 1DC894 002DC894 38810B0C */  jal        func_002e04e0
    /* 1DC898 002DC898 00000000 */   nop
    /* 1DC89C 002DC89C 020152A4 */  sh         $18, 0x102($2)
    /* 1DC8A0 002DC8A0 CC01A427 */  addiu      $4, $29, 0x1CC
    /* 1DC8A4 002DC8A4 BD000524 */  addiu      $5, $0, 0xBD
    /* 1DC8A8 002DC8A8 68000624 */  addiu      $6, $0, 0x68
    /* 1DC8AC 002DC8AC 03000724 */  addiu      $7, $0, 0x3
    /* 1DC8B0 002DC8B0 FF000824 */  addiu      $8, $0, 0xFF
    /* 1DC8B4 002DC8B4 98CA0A0C */  jal        func_002b2a60
    /* 1DC8B8 002DC8B8 00000000 */   nop
    /* 1DC8BC 002DC8BC B80E048E */  lw         $4, 0xEB8($16)
    /* 1DC8C0 002DC8C0 38810B0C */  jal        func_002e04e0
    /* 1DC8C4 002DC8C4 00000000 */   nop
    /* 1DC8C8 002DC8C8 CC01A693 */  lbu        $6, 0x1CC($29)
    /* 1DC8CC 002DC8CC CD01A593 */  lbu        $5, 0x1CD($29)
    /* 1DC8D0 002DC8D0 CE01A493 */  lbu        $4, 0x1CE($29)
    /* 1DC8D4 002DC8D4 CF01A393 */  lbu        $3, 0x1CF($29)
    /* 1DC8D8 002DC8D8 790046A0 */  sb         $6, 0x79($2)
    /* 1DC8DC 002DC8DC 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DC8E0 002DC8E0 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DC8E4 002DC8E4 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DC8E8 002DC8E8 2D202002 */  daddu      $4, $17, $0
    /* 1DC8EC 002DC8EC A0B4110C */  jal        func_0046d280
    /* 1DC8F0 002DC8F0 00000000 */   nop
    /* 1DC8F4 002DC8F4 0843023C */  lui        $2, (0x43080000 >> 16)
    /* 1DC8F8 002DC8F8 00608244 */  mtc1       $2, $f12
    /* 1DC8FC 002DC8FC C40C048E */  lw         $4, 0xCC4($16)
    /* 1DC900 002DC900 56000524 */  addiu      $5, $0, 0x56
    /* 1DC904 002DC904 78820B0C */  jal        func_002e09e0
    /* 1DC908 002DC908 00000000 */   nop
    /* 1DC90C 002DC90C 3C43023C */  lui        $2, (0x433C0000 >> 16)
    /* 1DC910 002DC910 00608244 */  mtc1       $2, $f12
    /* 1DC914 002DC914 70C2023C */  lui        $2, (0xC2700000 >> 16)
    /* 1DC918 002DC918 00688244 */  mtc1       $2, $f13
    /* 1DC91C 002DC91C D800A427 */  addiu      $4, $29, 0xD8
    /* 1DC920 002DC920 5CCA0A0C */  jal        func_002b2970
    /* 1DC924 002DC924 00000000 */   nop
    /* 1DC928 002DC928 3C43023C */  lui        $2, (0x433C0000 >> 16)
    /* 1DC92C 002DC92C 00608244 */  mtc1       $2, $f12
    /* 1DC930 002DC930 4C42023C */  lui        $2, (0x424C0000 >> 16)
    /* 1DC934 002DC934 00688244 */  mtc1       $2, $f13
    /* 1DC938 002DC938 D000A427 */  addiu      $4, $29, 0xD0
    /* 1DC93C 002DC93C 5CCA0A0C */  jal        func_002b2970
    /* 1DC940 002DC940 00000000 */   nop
    /* 1DC944 002DC944 C40C048E */  lw         $4, 0xCC4($16)
    /* 1DC948 002DC948 D800A5DF */  ld         $5, 0xD8($29)
    /* 1DC94C 002DC94C D000A6DF */  ld         $6, 0xD0($29)
    /* 1DC950 002DC950 02000724 */  addiu      $7, $0, 0x2
    /* 1DC954 002DC954 07000824 */  addiu      $8, $0, 0x7
    /* 1DC958 002DC958 05000924 */  addiu      $9, $0, 0x5
    /* 1DC95C 002DC95C 88810B0C */  jal        func_002e0620
    /* 1DC960 002DC960 00000000 */   nop
    /* 1DC964 002DC964 FF001124 */  addiu      $17, $0, 0xFF
    /* 1DC968 002DC968 C40C048E */  lw         $4, 0xCC4($16)
    /* 1DC96C 002DC96C 38810B0C */  jal        func_002e04e0
    /* 1DC970 002DC970 00000000 */   nop
    /* 1DC974 002DC974 620051A0 */  sb         $17, 0x62($2)
    /* 1DC978 002DC978 C801A427 */  addiu      $4, $29, 0x1C8
    /* 1DC97C 002DC97C 2D000524 */  addiu      $5, $0, 0x2D
    /* 1DC980 002DC980 2D30A000 */  daddu      $6, $5, $0
    /* 1DC984 002DC984 2D38A000 */  daddu      $7, $5, $0
    /* 1DC988 002DC988 2D402002 */  daddu      $8, $17, $0
    /* 1DC98C 002DC98C 98CA0A0C */  jal        func_002b2a60
    /* 1DC990 002DC990 00000000 */   nop
    /* 1DC994 002DC994 C40C048E */  lw         $4, 0xCC4($16)
    /* 1DC998 002DC998 38810B0C */  jal        func_002e04e0
    /* 1DC99C 002DC99C 00000000 */   nop
    /* 1DC9A0 002DC9A0 C801A693 */  lbu        $6, 0x1C8($29)
    /* 1DC9A4 002DC9A4 C901A593 */  lbu        $5, 0x1C9($29)
    /* 1DC9A8 002DC9A8 CA01A493 */  lbu        $4, 0x1CA($29)
    /* 1DC9AC 002DC9AC CB01A393 */  lbu        $3, 0x1CB($29)
    /* 1DC9B0 002DC9B0 790046A0 */  sb         $6, 0x79($2)
    /* 1DC9B4 002DC9B4 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DC9B8 002DC9B8 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DC9BC 002DC9BC 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DC9C0 002DC9C0 1C0F048E */  lw         $4, 0xF1C($16)
    /* 1DC9C4 002DC9C4 BC890B0C */  jal        func_002e26f0
    /* 1DC9C8 002DC9C8 00000000 */   nop
    /* 1DC9CC 002DC9CC 7500033C */  lui        $3, %hi(D_00748909)
    /* 1DC9D0 002DC9D0 09896380 */  lb         $3, %lo(D_00748909)($3)
    /* 1DC9D4 002DC9D4 2A086200 */  slt        $1, $3, $2
    /* 1DC9D8 002DC9D8 37002014 */  bnez       $1, .L002DCAB8
    /* 1DC9DC 002DC9DC 00000000 */   nop
    /* 1DC9E0 002DC9E0 C401A427 */  addiu      $4, $29, 0x1C4
    /* 1DC9E4 002DC9E4 2D280000 */  daddu      $5, $0, $0
    /* 1DC9E8 002DC9E8 2D300000 */  daddu      $6, $0, $0
    /* 1DC9EC 002DC9EC 2D380000 */  daddu      $7, $0, $0
    /* 1DC9F0 002DC9F0 2D402002 */  daddu      $8, $17, $0
    /* 1DC9F4 002DC9F4 98CA0A0C */  jal        func_002b2a60
    /* 1DC9F8 002DC9F8 00000000 */   nop
    /* 1DC9FC 002DC9FC B40E048E */  lw         $4, 0xEB4($16)
    /* 1DCA00 002DCA00 38810B0C */  jal        func_002e04e0
    /* 1DCA04 002DCA04 00000000 */   nop
    /* 1DCA08 002DCA08 C401A693 */  lbu        $6, 0x1C4($29)
    /* 1DCA0C 002DCA0C C501A593 */  lbu        $5, 0x1C5($29)
    /* 1DCA10 002DCA10 C601A493 */  lbu        $4, 0x1C6($29)
    /* 1DCA14 002DCA14 C701A393 */  lbu        $3, 0x1C7($29)
    /* 1DCA18 002DCA18 790046A0 */  sb         $6, 0x79($2)
    /* 1DCA1C 002DCA1C 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DCA20 002DCA20 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DCA24 002DCA24 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DCA28 002DCA28 C001A427 */  addiu      $4, $29, 0x1C0
    /* 1DCA2C 002DCA2C 2D280000 */  daddu      $5, $0, $0
    /* 1DCA30 002DCA30 2D300000 */  daddu      $6, $0, $0
    /* 1DCA34 002DCA34 2D380000 */  daddu      $7, $0, $0
    /* 1DCA38 002DCA38 2D402002 */  daddu      $8, $17, $0
    /* 1DCA3C 002DCA3C 98CA0A0C */  jal        func_002b2a60
    /* 1DCA40 002DCA40 00000000 */   nop
    /* 1DCA44 002DCA44 B80E048E */  lw         $4, 0xEB8($16)
    /* 1DCA48 002DCA48 38810B0C */  jal        func_002e04e0
    /* 1DCA4C 002DCA4C 00000000 */   nop
    /* 1DCA50 002DCA50 C001A693 */  lbu        $6, 0x1C0($29)
    /* 1DCA54 002DCA54 C101A593 */  lbu        $5, 0x1C1($29)
    /* 1DCA58 002DCA58 C201A493 */  lbu        $4, 0x1C2($29)
    /* 1DCA5C 002DCA5C C301A393 */  lbu        $3, 0x1C3($29)
    /* 1DCA60 002DCA60 790046A0 */  sb         $6, 0x79($2)
    /* 1DCA64 002DCA64 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DCA68 002DCA68 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DCA6C 002DCA6C 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DCA70 002DCA70 BC01A427 */  addiu      $4, $29, 0x1BC
    /* 1DCA74 002DCA74 6F000524 */  addiu      $5, $0, 0x6F
    /* 1DCA78 002DCA78 2D30A000 */  daddu      $6, $5, $0
    /* 1DCA7C 002DCA7C 2D38A000 */  daddu      $7, $5, $0
    /* 1DCA80 002DCA80 2D402002 */  daddu      $8, $17, $0
    /* 1DCA84 002DCA84 98CA0A0C */  jal        func_002b2a60
    /* 1DCA88 002DCA88 00000000 */   nop
    /* 1DCA8C 002DCA8C C40C048E */  lw         $4, 0xCC4($16)
    /* 1DCA90 002DCA90 38810B0C */  jal        func_002e04e0
    /* 1DCA94 002DCA94 00000000 */   nop
    /* 1DCA98 002DCA98 BC01A693 */  lbu        $6, 0x1BC($29)
    /* 1DCA9C 002DCA9C BD01A593 */  lbu        $5, 0x1BD($29)
    /* 1DCAA0 002DCAA0 BE01A493 */  lbu        $4, 0x1BE($29)
    /* 1DCAA4 002DCAA4 BF01A393 */  lbu        $3, 0x1BF($29)
    /* 1DCAA8 002DCAA8 790046A0 */  sb         $6, 0x79($2)
    /* 1DCAAC 002DCAAC 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DCAB0 002DCAB0 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DCAB4 002DCAB4 7C0043A0 */  sb         $3, 0x7C($2)
  .L002DCAB8:
    /* 1DCAB8 002DCAB8 280F048E */  lw         $4, 0xF28($16)
    /* 1DCABC 002DCABC 03000524 */  addiu      $5, $0, 0x3
    /* 1DCAC0 002DCAC0 80B4110C */  jal        func_0046d200
    /* 1DCAC4 002DCAC4 00000000 */   nop
    /* 1DCAC8 002DCAC8 2D884000 */  daddu      $17, $2, $0
    /* 1DCACC 002DCACC 0643023C */  lui        $2, (0x43060000 >> 16)
    /* 1DCAD0 002DCAD0 00608244 */  mtc1       $2, $f12
    /* 1DCAD4 002DCAD4 BC0E048E */  lw         $4, 0xEBC($16)
    /* 1DCAD8 002DCAD8 56000524 */  addiu      $5, $0, 0x56
    /* 1DCADC 002DCADC 78820B0C */  jal        func_002e09e0
    /* 1DCAE0 002DCAE0 00000000 */   nop
    /* 1DCAE4 002DCAE4 8643023C */  lui        $2, (0x43860000 >> 16)
    /* 1DCAE8 002DCAE8 00608244 */  mtc1       $2, $f12
    /* 1DCAEC 002DCAEC 70C2023C */  lui        $2, (0xC2700000 >> 16)
    /* 1DCAF0 002DCAF0 00688244 */  mtc1       $2, $f13
    /* 1DCAF4 002DCAF4 C800A427 */  addiu      $4, $29, 0xC8
    /* 1DCAF8 002DCAF8 5CCA0A0C */  jal        func_002b2970
    /* 1DCAFC 002DCAFC 00000000 */   nop
    /* 1DCB00 002DCB00 8643023C */  lui        $2, (0x43860000 >> 16)
    /* 1DCB04 002DCB04 00608244 */  mtc1       $2, $f12
    /* 1DCB08 002DCB08 4042023C */  lui        $2, (0x42400000 >> 16)
    /* 1DCB0C 002DCB0C 00688244 */  mtc1       $2, $f13
    /* 1DCB10 002DCB10 C000A427 */  addiu      $4, $29, 0xC0
    /* 1DCB14 002DCB14 5CCA0A0C */  jal        func_002b2970
    /* 1DCB18 002DCB18 00000000 */   nop
    /* 1DCB1C 002DCB1C BC0E048E */  lw         $4, 0xEBC($16)
    /* 1DCB20 002DCB20 C800A5DF */  ld         $5, 0xC8($29)
    /* 1DCB24 002DCB24 C000A6DF */  ld         $6, 0xC0($29)
    /* 1DCB28 002DCB28 02000724 */  addiu      $7, $0, 0x2
    /* 1DCB2C 002DCB2C 07000824 */  addiu      $8, $0, 0x7
    /* 1DCB30 002DCB30 05000924 */  addiu      $9, $0, 0x5
    /* 1DCB34 002DCB34 88810B0C */  jal        func_002e0620
    /* 1DCB38 002DCB38 00000000 */   nop
    /* 1DCB3C 002DCB3C FF001224 */  addiu      $18, $0, 0xFF
    /* 1DCB40 002DCB40 BC0E048E */  lw         $4, 0xEBC($16)
    /* 1DCB44 002DCB44 38810B0C */  jal        func_002e04e0
    /* 1DCB48 002DCB48 00000000 */   nop
    /* 1DCB4C 002DCB4C 620052A0 */  sb         $18, 0x62($2)
    /* 1DCB50 002DCB50 55001224 */  addiu      $18, $0, 0x55
    /* 1DCB54 002DCB54 BC0E048E */  lw         $4, 0xEBC($16)
    /* 1DCB58 002DCB58 38810B0C */  jal        func_002e04e0
    /* 1DCB5C 002DCB5C 00000000 */   nop
    /* 1DCB60 002DCB60 000152A4 */  sh         $18, 0x100($2)
    /* 1DCB64 002DCB64 17001224 */  addiu      $18, $0, 0x17
    /* 1DCB68 002DCB68 BC0E048E */  lw         $4, 0xEBC($16)
    /* 1DCB6C 002DCB6C 38810B0C */  jal        func_002e04e0
    /* 1DCB70 002DCB70 00000000 */   nop
    /* 1DCB74 002DCB74 020152A4 */  sh         $18, 0x102($2)
    /* 1DCB78 002DCB78 B801A427 */  addiu      $4, $29, 0x1B8
    /* 1DCB7C 002DCB7C 90000524 */  addiu      $5, $0, 0x90
    /* 1DCB80 002DCB80 4F000624 */  addiu      $6, $0, 0x4F
    /* 1DCB84 002DCB84 01000724 */  addiu      $7, $0, 0x1
    /* 1DCB88 002DCB88 FF000824 */  addiu      $8, $0, 0xFF
    /* 1DCB8C 002DCB8C 98CA0A0C */  jal        func_002b2a60
    /* 1DCB90 002DCB90 00000000 */   nop
    /* 1DCB94 002DCB94 BC0E048E */  lw         $4, 0xEBC($16)
    /* 1DCB98 002DCB98 38810B0C */  jal        func_002e04e0
    /* 1DCB9C 002DCB9C 00000000 */   nop
    /* 1DCBA0 002DCBA0 B801A693 */  lbu        $6, 0x1B8($29)
    /* 1DCBA4 002DCBA4 B901A593 */  lbu        $5, 0x1B9($29)
    /* 1DCBA8 002DCBA8 BA01A493 */  lbu        $4, 0x1BA($29)
    /* 1DCBAC 002DCBAC BB01A393 */  lbu        $3, 0x1BB($29)
    /* 1DCBB0 002DCBB0 790046A0 */  sb         $6, 0x79($2)
    /* 1DCBB4 002DCBB4 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DCBB8 002DCBB8 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DCBBC 002DCBBC 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DCBC0 002DCBC0 2D202002 */  daddu      $4, $17, $0
    /* 1DCBC4 002DCBC4 A0B4110C */  jal        func_0046d280
    /* 1DCBC8 002DCBC8 00000000 */   nop
    /* 1DCBCC 002DCBCC 280F048E */  lw         $4, 0xF28($16)
    /* 1DCBD0 002DCBD0 04000524 */  addiu      $5, $0, 0x4
    /* 1DCBD4 002DCBD4 80B4110C */  jal        func_0046d200
    /* 1DCBD8 002DCBD8 00000000 */   nop
    /* 1DCBDC 002DCBDC 2D884000 */  daddu      $17, $2, $0
    /* 1DCBE0 002DCBE0 0743023C */  lui        $2, (0x43070000 >> 16)
    /* 1DCBE4 002DCBE4 00608244 */  mtc1       $2, $f12
    /* 1DCBE8 002DCBE8 C00E048E */  lw         $4, 0xEC0($16)
    /* 1DCBEC 002DCBEC 56000524 */  addiu      $5, $0, 0x56
    /* 1DCBF0 002DCBF0 78820B0C */  jal        func_002e09e0
    /* 1DCBF4 002DCBF4 00000000 */   nop
    /* 1DCBF8 002DCBF8 9A43023C */  lui        $2, (0x439A0000 >> 16)
    /* 1DCBFC 002DCBFC 00608244 */  mtc1       $2, $f12
    /* 1DCC00 002DCC00 70C2023C */  lui        $2, (0xC2700000 >> 16)
    /* 1DCC04 002DCC04 00688244 */  mtc1       $2, $f13
    /* 1DCC08 002DCC08 B800A427 */  addiu      $4, $29, 0xB8
    /* 1DCC0C 002DCC0C 5CCA0A0C */  jal        func_002b2970
    /* 1DCC10 002DCC10 00000000 */   nop
    /* 1DCC14 002DCC14 9A43023C */  lui        $2, (0x439A0000 >> 16)
    /* 1DCC18 002DCC18 00608244 */  mtc1       $2, $f12
    /* 1DCC1C 002DCC1C 4042023C */  lui        $2, (0x42400000 >> 16)
    /* 1DCC20 002DCC20 00688244 */  mtc1       $2, $f13
    /* 1DCC24 002DCC24 B000A427 */  addiu      $4, $29, 0xB0
    /* 1DCC28 002DCC28 5CCA0A0C */  jal        func_002b2970
    /* 1DCC2C 002DCC2C 00000000 */   nop
    /* 1DCC30 002DCC30 C00E048E */  lw         $4, 0xEC0($16)
    /* 1DCC34 002DCC34 B800A5DF */  ld         $5, 0xB8($29)
    /* 1DCC38 002DCC38 B000A6DF */  ld         $6, 0xB0($29)
    /* 1DCC3C 002DCC3C 02000724 */  addiu      $7, $0, 0x2
    /* 1DCC40 002DCC40 07000824 */  addiu      $8, $0, 0x7
    /* 1DCC44 002DCC44 05000924 */  addiu      $9, $0, 0x5
    /* 1DCC48 002DCC48 88810B0C */  jal        func_002e0620
    /* 1DCC4C 002DCC4C 00000000 */   nop
    /* 1DCC50 002DCC50 2D202002 */  daddu      $4, $17, $0
    /* 1DCC54 002DCC54 98AC110C */  jal        func_0046b260
    /* 1DCC58 002DCC58 00000000 */   nop
    /* 1DCC5C 002DCC5C AA42023C */  lui        $2, (0x42AA0000 >> 16)
    /* 1DCC60 002DCC60 00088244 */  mtc1       $2, $f1
    /* 1DCC64 002DCC64 00000000 */  nop
    /* 1DCC68 002DCC68 01000146 */  sub.s      $f0, $f0, $f1
    /* 1DCC6C 002DCC6C 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1DCC70 002DCC70 00000244 */  mfc1       $2, $f0
    /* 1DCC74 002DCC74 00000000 */  nop
    /* 1DCC78 002DCC78 3C940200 */  dsll32     $18, $2, 16
    /* 1DCC7C 002DCC7C 3F941200 */  dsra32     $18, $18, 16
    /* 1DCC80 002DCC80 C00E048E */  lw         $4, 0xEC0($16)
    /* 1DCC84 002DCC84 38810B0C */  jal        func_002e04e0
    /* 1DCC88 002DCC88 00000000 */   nop
    /* 1DCC8C 002DCC8C 000152A4 */  sh         $18, 0x100($2)
    /* 1DCC90 002DCC90 17001224 */  addiu      $18, $0, 0x17
    /* 1DCC94 002DCC94 C00E048E */  lw         $4, 0xEC0($16)
    /* 1DCC98 002DCC98 38810B0C */  jal        func_002e04e0
    /* 1DCC9C 002DCC9C 00000000 */   nop
    /* 1DCCA0 002DCCA0 020152A4 */  sh         $18, 0x102($2)
    /* 1DCCA4 002DCCA4 FF001224 */  addiu      $18, $0, 0xFF
    /* 1DCCA8 002DCCA8 C00E048E */  lw         $4, 0xEC0($16)
    /* 1DCCAC 002DCCAC 38810B0C */  jal        func_002e04e0
    /* 1DCCB0 002DCCB0 00000000 */   nop
    /* 1DCCB4 002DCCB4 620052A0 */  sb         $18, 0x62($2)
    /* 1DCCB8 002DCCB8 B401A427 */  addiu      $4, $29, 0x1B4
    /* 1DCCBC 002DCCBC 90000524 */  addiu      $5, $0, 0x90
    /* 1DCCC0 002DCCC0 4F000624 */  addiu      $6, $0, 0x4F
    /* 1DCCC4 002DCCC4 01000724 */  addiu      $7, $0, 0x1
    /* 1DCCC8 002DCCC8 2D404002 */  daddu      $8, $18, $0
    /* 1DCCCC 002DCCCC 98CA0A0C */  jal        func_002b2a60
    /* 1DCCD0 002DCCD0 00000000 */   nop
    /* 1DCCD4 002DCCD4 C00E048E */  lw         $4, 0xEC0($16)
    /* 1DCCD8 002DCCD8 38810B0C */  jal        func_002e04e0
    /* 1DCCDC 002DCCDC 00000000 */   nop
    /* 1DCCE0 002DCCE0 B401A693 */  lbu        $6, 0x1B4($29)
    /* 1DCCE4 002DCCE4 B501A593 */  lbu        $5, 0x1B5($29)
    /* 1DCCE8 002DCCE8 B601A493 */  lbu        $4, 0x1B6($29)
    /* 1DCCEC 002DCCEC B701A393 */  lbu        $3, 0x1B7($29)
    /* 1DCCF0 002DCCF0 790046A0 */  sb         $6, 0x79($2)
    /* 1DCCF4 002DCCF4 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DCCF8 002DCCF8 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DCCFC 002DCCFC 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DCD00 002DCD00 2D202002 */  daddu      $4, $17, $0
    /* 1DCD04 002DCD04 A0B4110C */  jal        func_0046d280
    /* 1DCD08 002DCD08 00000000 */   nop
    /* 1DCD0C 002DCD0C 0543023C */  lui        $2, (0x43050000 >> 16)
    /* 1DCD10 002DCD10 00608244 */  mtc1       $2, $f12
    /* 1DCD14 002DCD14 C00C048E */  lw         $4, 0xCC0($16)
    /* 1DCD18 002DCD18 57000524 */  addiu      $5, $0, 0x57
    /* 1DCD1C 002DCD1C 78820B0C */  jal        func_002e09e0
    /* 1DCD20 002DCD20 00000000 */   nop
    /* 1DCD24 002DCD24 9043023C */  lui        $2, (0x43900000 >> 16)
    /* 1DCD28 002DCD28 00608244 */  mtc1       $2, $f12
    /* 1DCD2C 002DCD2C 70C2023C */  lui        $2, (0xC2700000 >> 16)
    /* 1DCD30 002DCD30 00688244 */  mtc1       $2, $f13
    /* 1DCD34 002DCD34 A800A427 */  addiu      $4, $29, 0xA8
    /* 1DCD38 002DCD38 5CCA0A0C */  jal        func_002b2970
    /* 1DCD3C 002DCD3C 00000000 */   nop
    /* 1DCD40 002DCD40 9043023C */  lui        $2, (0x43900000 >> 16)
    /* 1DCD44 002DCD44 00608244 */  mtc1       $2, $f12
    /* 1DCD48 002DCD48 6C42023C */  lui        $2, (0x426C0000 >> 16)
    /* 1DCD4C 002DCD4C 00688244 */  mtc1       $2, $f13
    /* 1DCD50 002DCD50 A000A427 */  addiu      $4, $29, 0xA0
    /* 1DCD54 002DCD54 5CCA0A0C */  jal        func_002b2970
    /* 1DCD58 002DCD58 00000000 */   nop
    /* 1DCD5C 002DCD5C C00C048E */  lw         $4, 0xCC0($16)
    /* 1DCD60 002DCD60 A800A5DF */  ld         $5, 0xA8($29)
    /* 1DCD64 002DCD64 A000A6DF */  ld         $6, 0xA0($29)
    /* 1DCD68 002DCD68 02000724 */  addiu      $7, $0, 0x2
    /* 1DCD6C 002DCD6C 07000824 */  addiu      $8, $0, 0x7
    /* 1DCD70 002DCD70 05000924 */  addiu      $9, $0, 0x5
    /* 1DCD74 002DCD74 88810B0C */  jal        func_002e0620
    /* 1DCD78 002DCD78 00000000 */   nop
    /* 1DCD7C 002DCD7C 2D884002 */  daddu      $17, $18, $0
    /* 1DCD80 002DCD80 C00C048E */  lw         $4, 0xCC0($16)
    /* 1DCD84 002DCD84 38810B0C */  jal        func_002e04e0
    /* 1DCD88 002DCD88 00000000 */   nop
    /* 1DCD8C 002DCD8C 620051A0 */  sb         $17, 0x62($2)
    /* 1DCD90 002DCD90 23001124 */  addiu      $17, $0, 0x23
    /* 1DCD94 002DCD94 C00C048E */  lw         $4, 0xCC0($16)
    /* 1DCD98 002DCD98 38810B0C */  jal        func_002e04e0
    /* 1DCD9C 002DCD9C 00000000 */   nop
    /* 1DCDA0 002DCDA0 000151A4 */  sh         $17, 0x100($2)
    /* 1DCDA4 002DCDA4 B001A427 */  addiu      $4, $29, 0x1B0
    /* 1DCDA8 002DCDA8 2D000524 */  addiu      $5, $0, 0x2D
    /* 1DCDAC 002DCDAC 2D30A000 */  daddu      $6, $5, $0
    /* 1DCDB0 002DCDB0 2D38A000 */  daddu      $7, $5, $0
    /* 1DCDB4 002DCDB4 2D404002 */  daddu      $8, $18, $0
    /* 1DCDB8 002DCDB8 98CA0A0C */  jal        func_002b2a60
    /* 1DCDBC 002DCDBC 00000000 */   nop
    /* 1DCDC0 002DCDC0 C00C048E */  lw         $4, 0xCC0($16)
    /* 1DCDC4 002DCDC4 38810B0C */  jal        func_002e04e0
    /* 1DCDC8 002DCDC8 00000000 */   nop
    /* 1DCDCC 002DCDCC B001A693 */  lbu        $6, 0x1B0($29)
    /* 1DCDD0 002DCDD0 B101A593 */  lbu        $5, 0x1B1($29)
    /* 1DCDD4 002DCDD4 B201A493 */  lbu        $4, 0x1B2($29)
    /* 1DCDD8 002DCDD8 B301A393 */  lbu        $3, 0x1B3($29)
    /* 1DCDDC 002DCDDC 790046A0 */  sb         $6, 0x79($2)
    /* 1DCDE0 002DCDE0 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DCDE4 002DCDE4 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DCDE8 002DCDE8 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DCDEC 002DCDEC 200F048E */  lw         $4, 0xF20($16)
    /* 1DCDF0 002DCDF0 BC890B0C */  jal        func_002e26f0
    /* 1DCDF4 002DCDF4 00000000 */   nop
    /* 1DCDF8 002DCDF8 7500033C */  lui        $3, %hi(D_0074890A)
    /* 1DCDFC 002DCDFC 0A896380 */  lb         $3, %lo(D_0074890A)($3)
    /* 1DCE00 002DCE00 2A086200 */  slt        $1, $3, $2
    /* 1DCE04 002DCE04 37002014 */  bnez       $1, .L002DCEE4
    /* 1DCE08 002DCE08 00000000 */   nop
    /* 1DCE0C 002DCE0C AC01A427 */  addiu      $4, $29, 0x1AC
    /* 1DCE10 002DCE10 2D000524 */  addiu      $5, $0, 0x2D
    /* 1DCE14 002DCE14 2D30A000 */  daddu      $6, $5, $0
    /* 1DCE18 002DCE18 2D38A000 */  daddu      $7, $5, $0
    /* 1DCE1C 002DCE1C 2D404002 */  daddu      $8, $18, $0
    /* 1DCE20 002DCE20 98CA0A0C */  jal        func_002b2a60
    /* 1DCE24 002DCE24 00000000 */   nop
    /* 1DCE28 002DCE28 BC0E048E */  lw         $4, 0xEBC($16)
    /* 1DCE2C 002DCE2C 38810B0C */  jal        func_002e04e0
    /* 1DCE30 002DCE30 00000000 */   nop
    /* 1DCE34 002DCE34 AC01A693 */  lbu        $6, 0x1AC($29)
    /* 1DCE38 002DCE38 AD01A593 */  lbu        $5, 0x1AD($29)
    /* 1DCE3C 002DCE3C AE01A493 */  lbu        $4, 0x1AE($29)
    /* 1DCE40 002DCE40 AF01A393 */  lbu        $3, 0x1AF($29)
    /* 1DCE44 002DCE44 790046A0 */  sb         $6, 0x79($2)
    /* 1DCE48 002DCE48 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DCE4C 002DCE4C 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DCE50 002DCE50 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DCE54 002DCE54 A801A427 */  addiu      $4, $29, 0x1A8
    /* 1DCE58 002DCE58 2D000524 */  addiu      $5, $0, 0x2D
    /* 1DCE5C 002DCE5C 2D30A000 */  daddu      $6, $5, $0
    /* 1DCE60 002DCE60 2D38A000 */  daddu      $7, $5, $0
    /* 1DCE64 002DCE64 2D404002 */  daddu      $8, $18, $0
    /* 1DCE68 002DCE68 98CA0A0C */  jal        func_002b2a60
    /* 1DCE6C 002DCE6C 00000000 */   nop
    /* 1DCE70 002DCE70 C00E048E */  lw         $4, 0xEC0($16)
    /* 1DCE74 002DCE74 38810B0C */  jal        func_002e04e0
    /* 1DCE78 002DCE78 00000000 */   nop
    /* 1DCE7C 002DCE7C A801A693 */  lbu        $6, 0x1A8($29)
    /* 1DCE80 002DCE80 A901A593 */  lbu        $5, 0x1A9($29)
    /* 1DCE84 002DCE84 AA01A493 */  lbu        $4, 0x1AA($29)
    /* 1DCE88 002DCE88 AB01A393 */  lbu        $3, 0x1AB($29)
    /* 1DCE8C 002DCE8C 790046A0 */  sb         $6, 0x79($2)
    /* 1DCE90 002DCE90 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DCE94 002DCE94 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DCE98 002DCE98 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DCE9C 002DCE9C A401A427 */  addiu      $4, $29, 0x1A4
    /* 1DCEA0 002DCEA0 6F000524 */  addiu      $5, $0, 0x6F
    /* 1DCEA4 002DCEA4 2D30A000 */  daddu      $6, $5, $0
    /* 1DCEA8 002DCEA8 2D38A000 */  daddu      $7, $5, $0
    /* 1DCEAC 002DCEAC 2D404002 */  daddu      $8, $18, $0
    /* 1DCEB0 002DCEB0 98CA0A0C */  jal        func_002b2a60
    /* 1DCEB4 002DCEB4 00000000 */   nop
    /* 1DCEB8 002DCEB8 C00C048E */  lw         $4, 0xCC0($16)
    /* 1DCEBC 002DCEBC 38810B0C */  jal        func_002e04e0
    /* 1DCEC0 002DCEC0 00000000 */   nop
    /* 1DCEC4 002DCEC4 A401A693 */  lbu        $6, 0x1A4($29)
    /* 1DCEC8 002DCEC8 A501A593 */  lbu        $5, 0x1A5($29)
    /* 1DCECC 002DCECC A601A493 */  lbu        $4, 0x1A6($29)
    /* 1DCED0 002DCED0 A701A393 */  lbu        $3, 0x1A7($29)
    /* 1DCED4 002DCED4 790046A0 */  sb         $6, 0x79($2)
    /* 1DCED8 002DCED8 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DCEDC 002DCEDC 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DCEE0 002DCEE0 7C0043A0 */  sb         $3, 0x7C($2)
  .L002DCEE4:
    /* 1DCEE4 002DCEE4 4442023C */  lui        $2, (0x42440000 >> 16)
    /* 1DCEE8 002DCEE8 00608244 */  mtc1       $2, $f12
    /* 1DCEEC 002DCEEC DC0D048E */  lw         $4, 0xDDC($16)
    /* 1DCEF0 002DCEF0 57000524 */  addiu      $5, $0, 0x57
    /* 1DCEF4 002DCEF4 78820B0C */  jal        func_002e09e0
    /* 1DCEF8 002DCEF8 00000000 */   nop
    /* 1DCEFC 002DCEFC DC0D048E */  lw         $4, 0xDDC($16)
    /* 1DCF00 002DCF00 2D280000 */  daddu      $5, $0, $0
    /* 1DCF04 002DCF04 FF000624 */  addiu      $6, $0, 0xFF
    /* 1DCF08 002DCF08 2D380000 */  daddu      $7, $0, $0
    /* 1DCF0C 002DCF0C 0A000824 */  addiu      $8, $0, 0xA
    /* 1DCF10 002DCF10 2D480000 */  daddu      $9, $0, $0
    /* 1DCF14 002DCF14 98810B0C */  jal        func_002e0660
    /* 1DCF18 002DCF18 00000000 */   nop
    /* 1DCF1C 002DCF1C 3842023C */  lui        $2, (0x42380000 >> 16)
    /* 1DCF20 002DCF20 00608244 */  mtc1       $2, $f12
    /* 1DCF24 002DCF24 E80D048E */  lw         $4, 0xDE8($16)
    /* 1DCF28 002DCF28 57000524 */  addiu      $5, $0, 0x57
    /* 1DCF2C 002DCF2C 78820B0C */  jal        func_002e09e0
    /* 1DCF30 002DCF30 00000000 */   nop
    /* 1DCF34 002DCF34 E80D048E */  lw         $4, 0xDE8($16)
    /* 1DCF38 002DCF38 2D280000 */  daddu      $5, $0, $0
    /* 1DCF3C 002DCF3C FF000624 */  addiu      $6, $0, 0xFF
    /* 1DCF40 002DCF40 2D380000 */  daddu      $7, $0, $0
    /* 1DCF44 002DCF44 0A000824 */  addiu      $8, $0, 0xA
    /* 1DCF48 002DCF48 2D480000 */  daddu      $9, $0, $0
    /* 1DCF4C 002DCF4C 98810B0C */  jal        func_002e0660
    /* 1DCF50 002DCF50 00000000 */   nop
    /* 1DCF54 002DCF54 4443023C */  lui        $2, (0x43440000 >> 16)
    /* 1DCF58 002DCF58 00608244 */  mtc1       $2, $f12
    /* 1DCF5C 002DCF5C CA43023C */  lui        $2, (0x43CA0000 >> 16)
    /* 1DCF60 002DCF60 00688244 */  mtc1       $2, $f13
    /* 1DCF64 002DCF64 9800A427 */  addiu      $4, $29, 0x98
    /* 1DCF68 002DCF68 5CCA0A0C */  jal        func_002b2970
    /* 1DCF6C 002DCF6C 00000000 */   nop
    /* 1DCF70 002DCF70 4443023C */  lui        $2, (0x43440000 >> 16)
    /* 1DCF74 002DCF74 00608244 */  mtc1       $2, $f12
    /* 1DCF78 002DCF78 CA43023C */  lui        $2, (0x43CA0000 >> 16)
    /* 1DCF7C 002DCF7C 00688244 */  mtc1       $2, $f13
    /* 1DCF80 002DCF80 9000A427 */  addiu      $4, $29, 0x90
    /* 1DCF84 002DCF84 5CCA0A0C */  jal        func_002b2970
    /* 1DCF88 002DCF88 00000000 */   nop
    /* 1DCF8C 002DCF8C E80D048E */  lw         $4, 0xDE8($16)
    /* 1DCF90 002DCF90 9800A5DF */  ld         $5, 0x98($29)
    /* 1DCF94 002DCF94 9000A6DF */  ld         $6, 0x90($29)
    /* 1DCF98 002DCF98 2D380000 */  daddu      $7, $0, $0
    /* 1DCF9C 002DCF9C 2D400000 */  daddu      $8, $0, $0
    /* 1DCFA0 002DCFA0 2D480000 */  daddu      $9, $0, $0
    /* 1DCFA4 002DCFA4 88810B0C */  jal        func_002e0620
    /* 1DCFA8 002DCFA8 00000000 */   nop
    /* 1DCFAC 002DCFAC 3C42023C */  lui        $2, (0x423C0000 >> 16)
    /* 1DCFB0 002DCFB0 00608244 */  mtc1       $2, $f12
    /* 1DCFB4 002DCFB4 F00D048E */  lw         $4, 0xDF0($16)
    /* 1DCFB8 002DCFB8 57000524 */  addiu      $5, $0, 0x57
    /* 1DCFBC 002DCFBC 78820B0C */  jal        func_002e09e0
    /* 1DCFC0 002DCFC0 00000000 */   nop
    /* 1DCFC4 002DCFC4 F00D048E */  lw         $4, 0xDF0($16)
    /* 1DCFC8 002DCFC8 2D280000 */  daddu      $5, $0, $0
    /* 1DCFCC 002DCFCC FF000624 */  addiu      $6, $0, 0xFF
    /* 1DCFD0 002DCFD0 2D380000 */  daddu      $7, $0, $0
    /* 1DCFD4 002DCFD4 0A000824 */  addiu      $8, $0, 0xA
    /* 1DCFD8 002DCFD8 2D480000 */  daddu      $9, $0, $0
    /* 1DCFDC 002DCFDC 98810B0C */  jal        func_002e0660
    /* 1DCFE0 002DCFE0 00000000 */   nop
    /* 1DCFE4 002DCFE4 03010224 */  addiu      $2, $0, 0x103
    /* 1DCFE8 002DCFE8 00008244 */  mtc1       $2, $f0
    /* 1DCFEC 002DCFEC 00000000 */  nop
    /* 1DCFF0 002DCFF0 20038046 */  cvt.s.w    $f12, $f0
    /* 1DCFF4 002DCFF4 CA43023C */  lui        $2, (0x43CA0000 >> 16)
    /* 1DCFF8 002DCFF8 00688244 */  mtc1       $2, $f13
    /* 1DCFFC 002DCFFC 8800A427 */  addiu      $4, $29, 0x88
    /* 1DD000 002DD000 5CCA0A0C */  jal        func_002b2970
    /* 1DD004 002DD004 00000000 */   nop
    /* 1DD008 002DD008 03010224 */  addiu      $2, $0, 0x103
    /* 1DD00C 002DD00C 00008244 */  mtc1       $2, $f0
    /* 1DD010 002DD010 00000000 */  nop
    /* 1DD014 002DD014 20038046 */  cvt.s.w    $f12, $f0
    /* 1DD018 002DD018 CA43023C */  lui        $2, (0x43CA0000 >> 16)
    /* 1DD01C 002DD01C 00688244 */  mtc1       $2, $f13
    /* 1DD020 002DD020 8000A427 */  addiu      $4, $29, 0x80
    /* 1DD024 002DD024 5CCA0A0C */  jal        func_002b2970
    /* 1DD028 002DD028 00000000 */   nop
    /* 1DD02C 002DD02C F00D048E */  lw         $4, 0xDF0($16)
    /* 1DD030 002DD030 8800A5DF */  ld         $5, 0x88($29)
    /* 1DD034 002DD034 8000A6DF */  ld         $6, 0x80($29)
    /* 1DD038 002DD038 2D380000 */  daddu      $7, $0, $0
    /* 1DD03C 002DD03C 2D400000 */  daddu      $8, $0, $0
    /* 1DD040 002DD040 2D480000 */  daddu      $9, $0, $0
    /* 1DD044 002DD044 88810B0C */  jal        func_002e0620
    /* 1DD048 002DD048 00000000 */   nop
    /* 1DD04C 002DD04C 3C42023C */  lui        $2, (0x423C0000 >> 16)
    /* 1DD050 002DD050 00608244 */  mtc1       $2, $f12
    /* 1DD054 002DD054 E40D048E */  lw         $4, 0xDE4($16)
    /* 1DD058 002DD058 57000524 */  addiu      $5, $0, 0x57
    /* 1DD05C 002DD05C 78820B0C */  jal        func_002e09e0
    /* 1DD060 002DD060 00000000 */   nop
    /* 1DD064 002DD064 E40D048E */  lw         $4, 0xDE4($16)
    /* 1DD068 002DD068 2D280000 */  daddu      $5, $0, $0
    /* 1DD06C 002DD06C FF000624 */  addiu      $6, $0, 0xFF
    /* 1DD070 002DD070 2D380000 */  daddu      $7, $0, $0
    /* 1DD074 002DD074 0A000824 */  addiu      $8, $0, 0xA
    /* 1DD078 002DD078 2D480000 */  daddu      $9, $0, $0
    /* 1DD07C 002DD07C 98810B0C */  jal        func_002e0660
    /* 1DD080 002DD080 00000000 */   nop
    /* 1DD084 002DD084 A943023C */  lui        $2, (0x43A90000 >> 16)
    /* 1DD088 002DD088 00608244 */  mtc1       $2, $f12
    /* 1DD08C 002DD08C CA43023C */  lui        $2, (0x43CA0000 >> 16)
    /* 1DD090 002DD090 00688244 */  mtc1       $2, $f13
    /* 1DD094 002DD094 7800A427 */  addiu      $4, $29, 0x78
    /* 1DD098 002DD098 5CCA0A0C */  jal        func_002b2970
    /* 1DD09C 002DD09C 00000000 */   nop
    /* 1DD0A0 002DD0A0 A943023C */  lui        $2, (0x43A90000 >> 16)
    /* 1DD0A4 002DD0A4 00608244 */  mtc1       $2, $f12
    /* 1DD0A8 002DD0A8 CA43023C */  lui        $2, (0x43CA0000 >> 16)
    /* 1DD0AC 002DD0AC 00688244 */  mtc1       $2, $f13
    /* 1DD0B0 002DD0B0 7000A427 */  addiu      $4, $29, 0x70
    /* 1DD0B4 002DD0B4 5CCA0A0C */  jal        func_002b2970
    /* 1DD0B8 002DD0B8 00000000 */   nop
    /* 1DD0BC 002DD0BC E40D048E */  lw         $4, 0xDE4($16)
    /* 1DD0C0 002DD0C0 7800A5DF */  ld         $5, 0x78($29)
    /* 1DD0C4 002DD0C4 7000A6DF */  ld         $6, 0x70($29)
    /* 1DD0C8 002DD0C8 2D380000 */  daddu      $7, $0, $0
    /* 1DD0CC 002DD0CC 2D400000 */  daddu      $8, $0, $0
    /* 1DD0D0 002DD0D0 2D480000 */  daddu      $9, $0, $0
    /* 1DD0D4 002DD0D4 88810B0C */  jal        func_002e0620
    /* 1DD0D8 002DD0D8 00000000 */   nop
    /* 1DD0DC 002DD0DC 3C42023C */  lui        $2, (0x423C0000 >> 16)
    /* 1DD0E0 002DD0E0 00608244 */  mtc1       $2, $f12
    /* 1DD0E4 002DD0E4 E00D048E */  lw         $4, 0xDE0($16)
    /* 1DD0E8 002DD0E8 57000524 */  addiu      $5, $0, 0x57
    /* 1DD0EC 002DD0EC 78820B0C */  jal        func_002e09e0
    /* 1DD0F0 002DD0F0 00000000 */   nop
    /* 1DD0F4 002DD0F4 E00D048E */  lw         $4, 0xDE0($16)
    /* 1DD0F8 002DD0F8 2D280000 */  daddu      $5, $0, $0
    /* 1DD0FC 002DD0FC FF000624 */  addiu      $6, $0, 0xFF
    /* 1DD100 002DD100 2D380000 */  daddu      $7, $0, $0
    /* 1DD104 002DD104 0A000824 */  addiu      $8, $0, 0xA
    /* 1DD108 002DD108 2D480000 */  daddu      $9, $0, $0
    /* 1DD10C 002DD10C 98810B0C */  jal        func_002e0660
    /* 1DD110 002DD110 00000000 */   nop
    /* 1DD114 002DD114 A943023C */  lui        $2, (0x43A90000 >> 16)
    /* 1DD118 002DD118 00608244 */  mtc1       $2, $f12
    /* 1DD11C 002DD11C CA43023C */  lui        $2, (0x43CA0000 >> 16)
    /* 1DD120 002DD120 00688244 */  mtc1       $2, $f13
    /* 1DD124 002DD124 6800A427 */  addiu      $4, $29, 0x68
    /* 1DD128 002DD128 5CCA0A0C */  jal        func_002b2970
    /* 1DD12C 002DD12C 00000000 */   nop
    /* 1DD130 002DD130 A943023C */  lui        $2, (0x43A90000 >> 16)
    /* 1DD134 002DD134 00608244 */  mtc1       $2, $f12
    /* 1DD138 002DD138 CA43023C */  lui        $2, (0x43CA0000 >> 16)
    /* 1DD13C 002DD13C 00688244 */  mtc1       $2, $f13
    /* 1DD140 002DD140 6000A427 */  addiu      $4, $29, 0x60
    /* 1DD144 002DD144 5CCA0A0C */  jal        func_002b2970
    /* 1DD148 002DD148 00000000 */   nop
    /* 1DD14C 002DD14C E00D048E */  lw         $4, 0xDE0($16)
    /* 1DD150 002DD150 6800A5DF */  ld         $5, 0x68($29)
    /* 1DD154 002DD154 6000A6DF */  ld         $6, 0x60($29)
    /* 1DD158 002DD158 2D380000 */  daddu      $7, $0, $0
    /* 1DD15C 002DD15C 2D400000 */  daddu      $8, $0, $0
    /* 1DD160 002DD160 2D480000 */  daddu      $9, $0, $0
    /* 1DD164 002DD164 88810B0C */  jal        func_002e0620
    /* 1DD168 002DD168 00000000 */   nop
    /* 1DD16C 002DD16C E00D048E */  lw         $4, 0xDE0($16)
    /* 1DD170 002DD170 2D280000 */  daddu      $5, $0, $0
    /* 1DD174 002DD174 01000624 */  addiu      $6, $0, 0x1
    /* 1DD178 002DD178 3C810B0C */  jal        func_002e04f0
    /* 1DD17C 002DD17C 00000000 */   nop
    /* 1DD180 002DD180 F642023C */  lui        $2, (0x42F60000 >> 16)
    /* 1DD184 002DD184 00608244 */  mtc1       $2, $f12
    /* 1DD188 002DD188 CC0D048E */  lw         $4, 0xDCC($16)
    /* 1DD18C 002DD18C 41000524 */  addiu      $5, $0, 0x41
    /* 1DD190 002DD190 78820B0C */  jal        func_002e09e0
    /* 1DD194 002DD194 00000000 */   nop
    /* 1DD198 002DD198 CC0D048E */  lw         $4, 0xDCC($16)
    /* 1DD19C 002DD19C 2D280000 */  daddu      $5, $0, $0
    /* 1DD1A0 002DD1A0 FF000624 */  addiu      $6, $0, 0xFF
    /* 1DD1A4 002DD1A4 2D380000 */  daddu      $7, $0, $0
    /* 1DD1A8 002DD1A8 06000824 */  addiu      $8, $0, 0x6
    /* 1DD1AC 002DD1AC 07000924 */  addiu      $9, $0, 0x7
    /* 1DD1B0 002DD1B0 98810B0C */  jal        func_002e0660
    /* 1DD1B4 002DD1B4 00000000 */   nop
    /* 1DD1B8 002DD1B8 FA42023C */  lui        $2, (0x42FA0000 >> 16)
    /* 1DD1BC 002DD1BC 00608244 */  mtc1       $2, $f12
    /* 1DD1C0 002DD1C0 D00D048E */  lw         $4, 0xDD0($16)
    /* 1DD1C4 002DD1C4 41000524 */  addiu      $5, $0, 0x41
    /* 1DD1C8 002DD1C8 78820B0C */  jal        func_002e09e0
    /* 1DD1CC 002DD1CC 00000000 */   nop
    /* 1DD1D0 002DD1D0 D00D048E */  lw         $4, 0xDD0($16)
    /* 1DD1D4 002DD1D4 2D280000 */  daddu      $5, $0, $0
    /* 1DD1D8 002DD1D8 FF000624 */  addiu      $6, $0, 0xFF
    /* 1DD1DC 002DD1DC 2D380000 */  daddu      $7, $0, $0
    /* 1DD1E0 002DD1E0 06000824 */  addiu      $8, $0, 0x6
    /* 1DD1E4 002DD1E4 07000924 */  addiu      $9, $0, 0x7
    /* 1DD1E8 002DD1E8 98810B0C */  jal        func_002e0660
    /* 1DD1EC 002DD1EC 00000000 */   nop
    /* 1DD1F0 002DD1F0 110000A2 */  sb         $0, 0x11($16)
    /* 1DD1F4 002DD1F4 020000A6 */  sh         $0, 0x2($16)
    /* 1DD1F8 002DD1F8 040000A6 */  sh         $0, 0x4($16)
    /* 1DD1FC 002DD1FC 24000324 */  addiu      $3, $0, 0x24
    /* 1DD200 002DD200 000003A2 */  sb         $3, 0x0($16)
    /* 1DD204 002DD204 5000BFDF */  ld         $31, 0x50($29)
    /* 1DD208 002DD208 4000B37B */  lq         $19, 0x40($29)
    /* 1DD20C 002DD20C 3000B27B */  lq         $18, 0x30($29)
    /* 1DD210 002DD210 2000B17B */  lq         $17, 0x20($29)
    /* 1DD214 002DD214 1000B07B */  lq         $16, 0x10($29)
    /* 1DD218 002DD218 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 1DD21C 002DD21C 1002BD27 */  addiu      $29, $29, 0x210
    /* 1DD220 002DD220 0800E003 */  jr         $31
    /* 1DD224 002DD224 00000000 */   nop
    /* 1DD228 002DD228 00000000 */  nop
    /* 1DD22C 002DD22C 00000000 */  nop
.size func_002db400, 0x1e30
