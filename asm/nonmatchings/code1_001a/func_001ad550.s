.section .text
.set noat
.set noreorder
glabel func_001ad550
    /* AD550 001AD550 10FFBD27 */  addiu      $29, $29, -0xF0
    /* AD554 001AD554 7000BFFF */  sd         $31, 0x70($29)
    /* AD558 001AD558 6000B67F */  sq         $22, 0x60($29)
    /* AD55C 001AD55C 5000B57F */  sq         $21, 0x50($29)
    /* AD560 001AD560 4000B47F */  sq         $20, 0x40($29)
    /* AD564 001AD564 3000B37F */  sq         $19, 0x30($29)
    /* AD568 001AD568 2000B27F */  sq         $18, 0x20($29)
    /* AD56C 001AD56C 1000B17F */  sq         $17, 0x10($29)
    /* AD570 001AD570 0000B07F */  sq         $16, 0x0($29)
    /* AD574 001AD574 2DA08000 */  daddu      $20, $4, $0
    /* AD578 001AD578 EC80060C */  jal        func_001a03b0
    /* AD57C 001AD57C 00000000 */   nop
    /* AD580 001AD580 3000848E */  lw         $4, 0x30($20)
    /* AD584 001AD584 06000524 */  addiu      $5, $0, 0x6
    /* AD588 001AD588 B808080C */  jal        func_002022e0
    /* AD58C 001AD58C 00000000 */   nop
    /* AD590 001AD590 2D984000 */  daddu      $19, $2, $0
    /* AD594 001AD594 000083DE */  ld         $3, 0x0($20)
    /* AD598 001AD598 600043FC */  sd         $3, 0x60($2)
    /* AD59C 001AD59C 2D206002 */  daddu      $4, $19, $0
    /* AD5A0 001AD5A0 03000524 */  addiu      $5, $0, 0x3
    /* AD5A4 001AD5A4 6451060C */  jal        func_00194590
    /* AD5A8 001AD5A8 00000000 */   nop
    /* AD5AC 001AD5AC 2D280000 */  daddu      $5, $0, $0
    /* AD5B0 001AD5B0 2DA80000 */  daddu      $21, $0, $0
    /* AD5B4 001AD5B4 2D800000 */  daddu      $16, $0, $0
    /* AD5B8 001AD5B8 2D900000 */  daddu      $18, $0, $0
    /* AD5BC 001AD5BC 3000828E */  lw         $2, 0x30($20)
    /* AD5C0 001AD5C0 A2004290 */  lbu        $2, 0xA2($2)
    /* AD5C4 001AD5C4 01000424 */  addiu      $4, $0, 0x1
    /* AD5C8 001AD5C8 3E004410 */  beq        $2, $4, .L001AD6C4
    /* AD5CC 001AD5CC 00000000 */   nop
    /* AD5D0 001AD5D0 03004010 */  beqz       $2, .L001AD5E0
    /* AD5D4 001AD5D4 00000000 */   nop
    /* AD5D8 001AD5D8 42000010 */  b          .L001AD6E4
    /* AD5DC 001AD5DC 00000000 */   nop
  .L001AD5E0:
    /* AD5E0 001AD5E0 6C008396 */  lhu        $3, 0x6C($20)
    /* AD5E4 001AD5E4 0C000224 */  addiu      $2, $0, 0xC
    /* AD5E8 001AD5E8 2C006210 */  beq        $3, $2, .L001AD69C
    /* AD5EC 001AD5EC 00000000 */   nop
    /* AD5F0 001AD5F0 ACB3838F */  lw         $3, -0x4C54($28)
    /* AD5F4 001AD5F4 5E0C6294 */  lhu        $2, 0xC5E($3)
    /* AD5F8 001AD5F8 01004224 */  addiu      $2, $2, 0x1
    /* AD5FC 001AD5FC 5E0C62A4 */  sh         $2, 0xC5E($3)
    /* AD600 001AD600 2DA88000 */  daddu      $21, $4, $0
    /* AD604 001AD604 ACB3828F */  lw         $2, -0x4C54($28)
    /* AD608 001AD608 7401518C */  lw         $17, 0x174($2)
    /* AD60C 001AD60C 1E000010 */  b          .L001AD688
    /* AD610 001AD610 00000000 */   nop
  .L001AD614:
    /* AD614 001AD614 1A002296 */  lhu        $2, 0x1A($17)
    /* AD618 001AD618 01004230 */  andi       $2, $2, 0x1
    /* AD61C 001AD61C 19004010 */  beqz       $2, .L001AD684
    /* AD620 001AD620 00000000 */   nop
    /* AD624 001AD624 3000238E */  lw         $3, 0x30($17)
    /* AD628 001AD628 A2006290 */  lbu        $2, 0xA2($3)
    /* AD62C 001AD62C 15004014 */  bnez       $2, .L001AD684
    /* AD630 001AD630 00000000 */   nop
    /* AD634 001AD634 640A648C */  lw         $4, 0xA64($3)
    /* AD638 001AD638 2D280000 */  daddu      $5, $0, $0
    /* AD63C 001AD63C 3C0A090C */  jal        func_002428f0
    /* AD640 001AD640 00000000 */   nop
    /* AD644 001AD644 0F004014 */  bnez       $2, .L001AD684
    /* AD648 001AD648 00000000 */   nop
    /* AD64C 001AD64C 3000228E */  lw         $2, 0x30($17)
    /* AD650 001AD650 640A448C */  lw         $4, 0xA64($2)
    /* AD654 001AD654 1000023C */  lui        $2, (0x100001 >> 16)
    /* AD658 001AD658 01004534 */  ori        $5, $2, (0x100001 & 0xFFFF)
    /* AD65C 001AD65C C4C9080C */  jal        func_00232710
    /* AD660 001AD660 00000000 */   nop
    /* AD664 001AD664 07004014 */  bnez       $2, .L001AD684
    /* AD668 001AD668 00000000 */   nop
    /* AD66C 001AD66C FFFF0232 */  andi       $2, $16, 0xFFFF
    /* AD670 001AD670 80100200 */  sll        $2, $2, 2
    /* AD674 001AD674 21105D00 */  addu       $2, $2, $29
    /* AD678 001AD678 900051AC */  sw         $17, 0x90($2)
    /* AD67C 001AD67C 01000226 */  addiu      $2, $16, 0x1
    /* AD680 001AD680 FFFF5030 */  andi       $16, $2, 0xFFFF
  .L001AD684:
    /* AD684 001AD684 5004318E */  lw         $17, 0x450($17)
  .L001AD688:
    /* AD688 001AD688 E2FF2016 */  bnez       $17, .L001AD614
    /* AD68C 001AD68C 00000000 */   nop
    /* AD690 001AD690 01000524 */  addiu      $5, $0, 0x1
    /* AD694 001AD694 13000010 */  b          .L001AD6E4
    /* AD698 001AD698 00000000 */   nop
  .L001AD69C:
    /* AD69C 001AD69C 9000B4AF */  sw         $20, 0x90($29)
    /* AD6A0 001AD6A0 FFFF9030 */  andi       $16, $4, 0xFFFF
    /* AD6A4 001AD6A4 18008296 */  lhu        $2, 0x18($20)
    /* AD6A8 001AD6A8 20004234 */  ori        $2, $2, 0x20
    /* AD6AC 001AD6AC 180082A6 */  sh         $2, 0x18($20)
    /* AD6B0 001AD6B0 1A008296 */  lhu        $2, 0x1A($20)
    /* AD6B4 001AD6B4 F7FF4230 */  andi       $2, $2, 0xFFF7
    /* AD6B8 001AD6B8 1A0082A6 */  sh         $2, 0x1A($20)
    /* AD6BC 001AD6BC 09000010 */  b          .L001AD6E4
    /* AD6C0 001AD6C0 00000000 */   nop
  .L001AD6C4:
    /* AD6C4 001AD6C4 9000B4AF */  sw         $20, 0x90($29)
    /* AD6C8 001AD6C8 FFFF9030 */  andi       $16, $4, 0xFFFF
    /* AD6CC 001AD6CC 18008296 */  lhu        $2, 0x18($20)
    /* AD6D0 001AD6D0 20004234 */  ori        $2, $2, 0x20
    /* AD6D4 001AD6D4 180082A6 */  sh         $2, 0x18($20)
    /* AD6D8 001AD6D8 1A008296 */  lhu        $2, 0x1A($20)
    /* AD6DC 001AD6DC F7FF4230 */  andi       $2, $2, 0xFFF7
    /* AD6E0 001AD6E0 1A0082A6 */  sh         $2, 0x1A($20)
  .L001AD6E4:
    /* AD6E4 001AD6E4 0B00A014 */  bnez       $5, .L001AD714
    /* AD6E8 001AD6E8 00000000 */   nop
    /* AD6EC 001AD6EC 9000A48F */  lw         $4, 0x90($29)
    /* AD6F0 001AD6F0 0A000524 */  addiu      $5, $0, 0xA
    /* AD6F4 001AD6F4 48F2060C */  jal        func_001bc920
    /* AD6F8 001AD6F8 00000000 */   nop
    /* AD6FC 001AD6FC 2D204000 */  daddu      $4, $2, $0
    /* AD700 001AD700 000083DE */  ld         $3, 0x0($20)
    /* AD704 001AD704 600043FC */  sd         $3, 0x60($2)
    /* AD708 001AD708 2D280000 */  daddu      $5, $0, $0
    /* AD70C 001AD70C 6451060C */  jal        func_00194590
    /* AD710 001AD710 00000000 */   nop
  .L001AD714:
    /* AD714 001AD714 3000828E */  lw         $2, 0x30($20)
    /* AD718 001AD718 A2004290 */  lbu        $2, 0xA2($2)
    /* AD71C 001AD71C 38004014 */  bnez       $2, .L001AD800
    /* AD720 001AD720 00000000 */   nop
    /* AD724 001AD724 0F000424 */  addiu      $4, $0, 0xF
    /* AD728 001AD728 02000524 */  addiu      $5, $0, 0x2
    /* AD72C 001AD72C 2D300000 */  daddu      $6, $0, $0
    /* AD730 001AD730 44DF070C */  jal        func_001f7d10
    /* AD734 001AD734 00000000 */   nop
    /* AD738 001AD738 2D204000 */  daddu      $4, $2, $0
    /* AD73C 001AD73C 05000324 */  addiu      $3, $0, 0x5
    /* AD740 001AD740 000043A0 */  sb         $3, 0x0($2)
    /* AD744 001AD744 580063DE */  ld         $3, 0x58($19)
    /* AD748 001AD748 080043FC */  sd         $3, 0x8($2)
    /* AD74C 001AD74C 1A000324 */  addiu      $3, $0, 0x1A
    /* AD750 001AD750 480043A4 */  sh         $3, 0x48($2)
    /* AD754 001AD754 000083DE */  ld         $3, 0x0($20)
    /* AD758 001AD758 600043FC */  sd         $3, 0x60($2)
    /* AD75C 001AD75C 01000524 */  addiu      $5, $0, 0x1
    /* AD760 001AD760 6451060C */  jal        func_00194590
    /* AD764 001AD764 00000000 */   nop
    /* AD768 001AD768 6C008396 */  lhu        $3, 0x6C($20)
    /* AD76C 001AD76C 0C000224 */  addiu      $2, $0, 0xC
    /* AD770 001AD770 10006214 */  bne        $3, $2, .L001AD7B4
    /* AD774 001AD774 00000000 */   nop
    /* AD778 001AD778 2D208002 */  daddu      $4, $20, $0
    /* AD77C 001AD77C 07000524 */  addiu      $5, $0, 0x7
    /* AD780 001AD780 2D300000 */  daddu      $6, $0, $0
    /* AD784 001AD784 2D380000 */  daddu      $7, $0, $0
    /* AD788 001AD788 2D400000 */  daddu      $8, $0, $0
    /* AD78C 001AD78C DCD7070C */  jal        func_001f5f70
    /* AD790 001AD790 00000000 */   nop
    /* AD794 001AD794 2D204000 */  daddu      $4, $2, $0
    /* AD798 001AD798 000083DE */  ld         $3, 0x0($20)
    /* AD79C 001AD79C 600043FC */  sd         $3, 0x60($2)
    /* AD7A0 001AD7A0 01000524 */  addiu      $5, $0, 0x1
    /* AD7A4 001AD7A4 6451060C */  jal        func_00194590
    /* AD7A8 001AD7A8 00000000 */   nop
    /* AD7AC 001AD7AC 34000010 */  b          .L001AD880
    /* AD7B0 001AD7B0 00000000 */   nop
  .L001AD7B4:
    /* AD7B4 001AD7B4 01000224 */  addiu      $2, $0, 0x1
    /* AD7B8 001AD7B8 3100A216 */  bne        $21, $2, .L001AD880
    /* AD7BC 001AD7BC 00000000 */   nop
    /* AD7C0 001AD7C0 140A080C */  jal        func_00202850
    /* AD7C4 001AD7C4 00000000 */   nop
    /* AD7C8 001AD7C8 2D204000 */  daddu      $4, $2, $0
    /* AD7CC 001AD7CC 05000324 */  addiu      $3, $0, 0x5
    /* AD7D0 001AD7D0 000043A0 */  sb         $3, 0x0($2)
    /* AD7D4 001AD7D4 580063DE */  ld         $3, 0x58($19)
    /* AD7D8 001AD7D8 080043FC */  sd         $3, 0x8($2)
    /* AD7DC 001AD7DC 10000324 */  addiu      $3, $0, 0x10
    /* AD7E0 001AD7E0 480043A4 */  sh         $3, 0x48($2)
    /* AD7E4 001AD7E4 000083DE */  ld         $3, 0x0($20)
    /* AD7E8 001AD7E8 600043FC */  sd         $3, 0x60($2)
    /* AD7EC 001AD7EC 01000524 */  addiu      $5, $0, 0x1
    /* AD7F0 001AD7F0 6451060C */  jal        func_00194590
    /* AD7F4 001AD7F4 00000000 */   nop
    /* AD7F8 001AD7F8 21000010 */  b          .L001AD880
    /* AD7FC 001AD7FC 00000000 */   nop
  .L001AD800:
    /* AD800 001AD800 0C000424 */  addiu      $4, $0, 0xC
    /* AD804 001AD804 02000524 */  addiu      $5, $0, 0x2
    /* AD808 001AD808 0F000624 */  addiu      $6, $0, 0xF
    /* AD80C 001AD80C 08DF070C */  jal        func_001f7c20
    /* AD810 001AD810 00000000 */   nop
    /* AD814 001AD814 2D204000 */  daddu      $4, $2, $0
    /* AD818 001AD818 05000324 */  addiu      $3, $0, 0x5
    /* AD81C 001AD81C 000043A0 */  sb         $3, 0x0($2)
    /* AD820 001AD820 580063DE */  ld         $3, 0x58($19)
    /* AD824 001AD824 080043FC */  sd         $3, 0x8($2)
    /* AD828 001AD828 16000324 */  addiu      $3, $0, 0x16
    /* AD82C 001AD82C 480043A4 */  sh         $3, 0x48($2)
    /* AD830 001AD830 000083DE */  ld         $3, 0x0($20)
    /* AD834 001AD834 600043FC */  sd         $3, 0x60($2)
    /* AD838 001AD838 01000524 */  addiu      $5, $0, 0x1
    /* AD83C 001AD83C 6451060C */  jal        func_00194590
    /* AD840 001AD840 00000000 */   nop
    /* AD844 001AD844 2D208002 */  daddu      $4, $20, $0
    /* AD848 001AD848 06000524 */  addiu      $5, $0, 0x6
    /* AD84C 001AD84C 2D300000 */  daddu      $6, $0, $0
    /* AD850 001AD850 2D380000 */  daddu      $7, $0, $0
    /* AD854 001AD854 2D400000 */  daddu      $8, $0, $0
    /* AD858 001AD858 DCD7070C */  jal        func_001f5f70
    /* AD85C 001AD85C 00000000 */   nop
    /* AD860 001AD860 2D204000 */  daddu      $4, $2, $0
    /* AD864 001AD864 0C000324 */  addiu      $3, $0, 0xC
    /* AD868 001AD868 480043A4 */  sh         $3, 0x48($2)
    /* AD86C 001AD86C 000083DE */  ld         $3, 0x0($20)
    /* AD870 001AD870 600043FC */  sd         $3, 0x60($2)
    /* AD874 001AD874 01000524 */  addiu      $5, $0, 0x1
    /* AD878 001AD878 6451060C */  jal        func_00194590
    /* AD87C 001AD87C 00000000 */   nop
  .L001AD880:
    /* AD880 001AD880 2D880000 */  daddu      $17, $0, $0
    /* AD884 001AD884 FFFF1632 */  andi       $22, $16, 0xFFFF
    /* AD888 001AD888 8A000010 */  b          .L001ADAB4
    /* AD88C 001AD88C 00000000 */   nop
  .L001AD890:
    /* AD890 001AD890 FFFF2232 */  andi       $2, $17, 0xFFFF
    /* AD894 001AD894 80100200 */  sll        $2, $2, 2
    /* AD898 001AD898 21105D00 */  addu       $2, $2, $29
    /* AD89C 001AD89C 9000508C */  lw         $16, 0x90($2)
    /* AD8A0 001AD8A0 3000048E */  lw         $4, 0x30($16)
    /* AD8A4 001AD8A4 D000A527 */  addiu      $5, $29, 0xD0
    /* AD8A8 001AD8A8 1456060C */  jal        func_00195850
    /* AD8AC 001AD8AC 00000000 */   nop
    /* AD8B0 001AD8B0 3000048E */  lw         $4, 0x30($16)
    /* AD8B4 001AD8B4 2D280000 */  daddu      $5, $0, $0
    /* AD8B8 001AD8B8 8000A627 */  addiu      $6, $29, 0x80
    /* AD8BC 001AD8BC 2D380000 */  daddu      $7, $0, $0
    /* AD8C0 001AD8C0 FC53060C */  jal        func_00194ff0
    /* AD8C4 001AD8C4 00000000 */   nop
    /* AD8C8 001AD8C8 C000A427 */  addiu      $4, $29, 0xC0
    /* AD8CC 001AD8CC 6100053C */  lui        $5, %hi(D_0060A100)
    /* AD8D0 001AD8D0 00A1A524 */  addiu      $5, $5, %lo(D_0060A100)
    /* AD8D4 001AD8D4 01000624 */  addiu      $6, $0, 0x1
    /* AD8D8 001AD8D8 8000A727 */  addiu      $7, $29, 0x80
    /* AD8DC 001AD8DC D0720F0C */  jal        func_003dcb40
    /* AD8E0 001AD8E0 00000000 */   nop
    /* AD8E4 001AD8E4 3000828E */  lw         $2, 0x30($20)
    /* AD8E8 001AD8E8 A2004290 */  lbu        $2, 0xA2($2)
    /* AD8EC 001AD8EC 1F004014 */  bnez       $2, .L001AD96C
    /* AD8F0 001AD8F0 00000000 */   nop
    /* AD8F4 001AD8F4 FA43023C */  lui        $2, (0x43FA0000 >> 16)
    /* AD8F8 001AD8F8 00088244 */  mtc1       $2, $f1
    /* AD8FC 001AD8FC C000A0C7 */  lwc1       $f0, 0xC0($29)
    /* AD900 001AD900 C2000146 */  mul.s      $f3, $f0, $f1
    /* AD904 001AD904 C000A3E7 */  swc1       $f3, 0xC0($29)
    /* AD908 001AD908 C400A0C7 */  lwc1       $f0, 0xC4($29)
    /* AD90C 001AD90C 82000146 */  mul.s      $f2, $f0, $f1
    /* AD910 001AD910 C400A2E7 */  swc1       $f2, 0xC4($29)
    /* AD914 001AD914 C800A0C7 */  lwc1       $f0, 0xC8($29)
    /* AD918 001AD918 42000146 */  mul.s      $f1, $f0, $f1
    /* AD91C 001AD91C C800A1E7 */  swc1       $f1, 0xC8($29)
    /* AD920 001AD920 D000A0C7 */  lwc1       $f0, 0xD0($29)
    /* AD924 001AD924 00000346 */  add.s      $f0, $f0, $f3
    /* AD928 001AD928 E000A0E7 */  swc1       $f0, 0xE0($29)
    /* AD92C 001AD92C D400A0C7 */  lwc1       $f0, 0xD4($29)
    /* AD930 001AD930 00000246 */  add.s      $f0, $f0, $f2
    /* AD934 001AD934 E400A0E7 */  swc1       $f0, 0xE4($29)
    /* AD938 001AD938 D800A0C7 */  lwc1       $f0, 0xD8($29)
    /* AD93C 001AD93C 00000146 */  add.s      $f0, $f0, $f1
    /* AD940 001AD940 E800A0E7 */  swc1       $f0, 0xE8($29)
    /* AD944 001AD944 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* AD948 001AD948 00608244 */  mtc1       $2, $f12
    /* AD94C 001AD94C 3000048E */  lw         $4, 0x30($16)
    /* AD950 001AD950 E000A527 */  addiu      $5, $29, 0xE0
    /* AD954 001AD954 2D300000 */  daddu      $6, $0, $0
    /* AD958 001AD958 FC5C060C */  jal        func_001973f0
    /* AD95C 001AD95C 00000000 */   nop
    /* AD960 001AD960 2D904000 */  daddu      $18, $2, $0
    /* AD964 001AD964 2E000010 */  b          .L001ADA20
    /* AD968 001AD968 00000000 */   nop
  .L001AD96C:
    /* AD96C 001AD96C 3000028E */  lw         $2, 0x30($16)
    /* AD970 001AD970 A4004394 */  lhu        $3, 0xA4($2)
    /* AD974 001AD974 C0100300 */  sll        $2, $3, 3
    /* AD978 001AD978 23104300 */  subu       $2, $2, $3
    /* AD97C 001AD97C 80100200 */  sll        $2, $2, 2
    /* AD980 001AD980 21104300 */  addu       $2, $2, $3
    /* AD984 001AD984 C0180200 */  sll        $3, $2, 3
    /* AD988 001AD988 CCB3828F */  lw         $2, -0x4C34($28)
    /* AD98C 001AD98C 21104300 */  addu       $2, $2, $3
    /* AD990 001AD990 22004384 */  lh         $3, 0x22($2)
    /* AD994 001AD994 01000224 */  addiu      $2, $0, 0x1
    /* AD998 001AD998 16006210 */  beq        $3, $2, .L001AD9F4
    /* AD99C 001AD99C 00000000 */   nop
    /* AD9A0 001AD9A0 C000A0C7 */  lwc1       $f0, 0xC0($29)
    /* AD9A4 001AD9A4 508381C7 */  lwc1       $f1, -0x7CB0($28)
    /* AD9A8 001AD9A8 C2000146 */  mul.s      $f3, $f0, $f1
    /* AD9AC 001AD9AC C000A3E7 */  swc1       $f3, 0xC0($29)
    /* AD9B0 001AD9B0 C400A0C7 */  lwc1       $f0, 0xC4($29)
    /* AD9B4 001AD9B4 82000146 */  mul.s      $f2, $f0, $f1
    /* AD9B8 001AD9B8 C400A2E7 */  swc1       $f2, 0xC4($29)
    /* AD9BC 001AD9BC C800A0C7 */  lwc1       $f0, 0xC8($29)
    /* AD9C0 001AD9C0 42000146 */  mul.s      $f1, $f0, $f1
    /* AD9C4 001AD9C4 C800A1E7 */  swc1       $f1, 0xC8($29)
    /* AD9C8 001AD9C8 D000A0C7 */  lwc1       $f0, 0xD0($29)
    /* AD9CC 001AD9CC 00000346 */  add.s      $f0, $f0, $f3
    /* AD9D0 001AD9D0 E000A0E7 */  swc1       $f0, 0xE0($29)
    /* AD9D4 001AD9D4 D400A0C7 */  lwc1       $f0, 0xD4($29)
    /* AD9D8 001AD9D8 00000246 */  add.s      $f0, $f0, $f2
    /* AD9DC 001AD9DC E400A0E7 */  swc1       $f0, 0xE4($29)
    /* AD9E0 001AD9E0 D800A0C7 */  lwc1       $f0, 0xD8($29)
    /* AD9E4 001AD9E4 00000146 */  add.s      $f0, $f0, $f1
    /* AD9E8 001AD9E8 E800A0E7 */  swc1       $f0, 0xE8($29)
    /* AD9EC 001AD9EC 05000010 */  b          .L001ADA04
    /* AD9F0 001AD9F0 00000000 */   nop
  .L001AD9F4:
    /* AD9F4 001AD9F4 D000A2DF */  ld         $2, 0xD0($29)
    /* AD9F8 001AD9F8 D800A0C7 */  lwc1       $f0, 0xD8($29)
    /* AD9FC 001AD9FC E000A2FF */  sd         $2, 0xE0($29)
    /* ADA00 001ADA00 E800A0E7 */  swc1       $f0, 0xE8($29)
  .L001ADA04:
    /* ADA04 001ADA04 3000048E */  lw         $4, 0x30($16)
    /* ADA08 001ADA08 E000A527 */  addiu      $5, $29, 0xE0
    /* ADA0C 001ADA0C 18828CC7 */  lwc1       $f12, -0x7DE8($28)
    /* ADA10 001ADA10 04000624 */  addiu      $6, $0, 0x4
    /* ADA14 001ADA14 FC5C060C */  jal        func_001973f0
    /* ADA18 001ADA18 00000000 */   nop
    /* ADA1C 001ADA1C 2D904000 */  daddu      $18, $2, $0
  .L001ADA20:
    /* ADA20 001ADA20 05000224 */  addiu      $2, $0, 0x5
    /* ADA24 001ADA24 000042A2 */  sb         $2, 0x0($18)
    /* ADA28 001ADA28 580062DE */  ld         $2, 0x58($19)
    /* ADA2C 001ADA2C 080042FE */  sd         $2, 0x8($18)
    /* ADA30 001ADA30 10000224 */  addiu      $2, $0, 0x10
    /* ADA34 001ADA34 480042A6 */  sh         $2, 0x48($18)
    /* ADA38 001ADA38 000082DE */  ld         $2, 0x0($20)
    /* ADA3C 001ADA3C 600042FE */  sd         $2, 0x60($18)
    /* ADA40 001ADA40 2D204002 */  daddu      $4, $18, $0
    /* ADA44 001ADA44 01000524 */  addiu      $5, $0, 0x1
    /* ADA48 001ADA48 6451060C */  jal        func_00194590
    /* ADA4C 001ADA4C 00000000 */   nop
    /* ADA50 001ADA50 3000048E */  lw         $4, 0x30($16)
    /* ADA54 001ADA54 FF00023C */  lui        $2, (0xFFFFFF >> 16)
    /* ADA58 001ADA58 FFFF4534 */  ori        $5, $2, (0xFFFFFF & 0xFFFF)
    /* ADA5C 001ADA5C 08000624 */  addiu      $6, $0, 0x8
    /* ADA60 001ADA60 2D380000 */  daddu      $7, $0, $0
    /* ADA64 001ADA64 04000824 */  addiu      $8, $0, 0x4
    /* ADA68 001ADA68 2D480000 */  daddu      $9, $0, $0
    /* ADA6C 001ADA6C F86E060C */  jal        func_0019bbe0
    /* ADA70 001ADA70 00000000 */   nop
    /* ADA74 001ADA74 2D804000 */  daddu      $16, $2, $0
    /* ADA78 001ADA78 05000324 */  addiu      $3, $0, 0x5
    /* ADA7C 001ADA7C 000043A0 */  sb         $3, 0x0($2)
    /* ADA80 001ADA80 580043DE */  ld         $3, 0x58($18)
    /* ADA84 001ADA84 080043FC */  sd         $3, 0x8($2)
    /* ADA88 001ADA88 0C000324 */  addiu      $3, $0, 0xC
    /* ADA8C 001ADA8C 480043A4 */  sh         $3, 0x48($2)
    /* ADA90 001ADA90 000083DE */  ld         $3, 0x0($20)
    /* ADA94 001ADA94 600043FC */  sd         $3, 0x60($2)
    /* ADA98 001ADA98 2D200002 */  daddu      $4, $16, $0
    /* ADA9C 001ADA9C 01000524 */  addiu      $5, $0, 0x1
    /* ADAA0 001ADAA0 6451060C */  jal        func_00194590
    /* ADAA4 001ADAA4 00000000 */   nop
    /* ADAA8 001ADAA8 580012DE */  ld         $18, 0x58($16)
    /* ADAAC 001ADAAC 01002226 */  addiu      $2, $17, 0x1
    /* ADAB0 001ADAB0 FFFF5130 */  andi       $17, $2, 0xFFFF
  .L001ADAB4:
    /* ADAB4 001ADAB4 FFFF2232 */  andi       $2, $17, 0xFFFF
    /* ADAB8 001ADAB8 2A105600 */  slt        $2, $2, $22
    /* ADABC 001ADABC 74FF4014 */  bnez       $2, .L001AD890
    /* ADAC0 001ADAC0 00000000 */   nop
    /* ADAC4 001ADAC4 1400A012 */  beqz       $21, .L001ADB18
    /* ADAC8 001ADAC8 00000000 */   nop
    /* ADACC 001ADACC 80000424 */  addiu      $4, $0, 0x80
    /* ADAD0 001ADAD0 DC4D060C */  jal        func_00193770
    /* ADAD4 001ADAD4 00000000 */   nop
    /* ADAD8 001ADAD8 2D204000 */  daddu      $4, $2, $0
    /* ADADC 001ADADC 04000324 */  addiu      $3, $0, 0x4
    /* ADAE0 001ADAE0 000043A0 */  sb         $3, 0x0($2)
    /* ADAE4 001ADAE4 080052FC */  sd         $18, 0x8($2)
    /* ADAE8 001ADAE8 0A000324 */  addiu      $3, $0, 0xA
    /* ADAEC 001ADAEC 100043A0 */  sb         $3, 0x10($2)
    /* ADAF0 001ADAF0 01080324 */  addiu      $3, $0, 0x801
    /* ADAF4 001ADAF4 180043A4 */  sh         $3, 0x18($2)
    /* ADAF8 001ADAF8 000083DE */  ld         $3, 0x0($20)
    /* ADAFC 001ADAFC 600043FC */  sd         $3, 0x60($2)
    /* ADB00 001ADB00 01000524 */  addiu      $5, $0, 0x1
    /* ADB04 001ADB04 6451060C */  jal        func_00194590
    /* ADB08 001ADB08 00000000 */   nop
    /* ADB0C 001ADB0C 03000324 */  addiu      $3, $0, 0x3
    /* ADB10 001ADB10 ACB3828F */  lw         $2, -0x4C54($28)
    /* ADB14 001ADB14 1C0043A4 */  sh         $3, 0x1C($2)
  .L001ADB18:
    /* ADB18 001ADB18 2D208002 */  daddu      $4, $20, $0
    /* ADB1C 001ADB1C 2D280000 */  daddu      $5, $0, $0
    /* ADB20 001ADB20 1CCE070C */  jal        func_001f3870
    /* ADB24 001ADB24 00000000 */   nop
    /* ADB28 001ADB28 2D204000 */  daddu      $4, $2, $0
    /* ADB2C 001ADB2C 000083DE */  ld         $3, 0x0($20)
    /* ADB30 001ADB30 600043FC */  sd         $3, 0x60($2)
    /* ADB34 001ADB34 01000524 */  addiu      $5, $0, 0x1
    /* ADB38 001ADB38 6451060C */  jal        func_00194590
    /* ADB3C 001ADB3C 00000000 */   nop
    /* ADB40 001ADB40 2D208002 */  daddu      $4, $20, $0
    /* ADB44 001ADB44 20000524 */  addiu      $5, $0, 0x20
    /* ADB48 001ADB48 00C2060C */  jal        func_001b0800
    /* ADB4C 001ADB4C 00000000 */   nop
    /* ADB50 001ADB50 7000BFDF */  ld         $31, 0x70($29)
    /* ADB54 001ADB54 6000B67B */  lq         $22, 0x60($29)
    /* ADB58 001ADB58 5000B57B */  lq         $21, 0x50($29)
    /* ADB5C 001ADB5C 4000B47B */  lq         $20, 0x40($29)
    /* ADB60 001ADB60 3000B37B */  lq         $19, 0x30($29)
    /* ADB64 001ADB64 2000B27B */  lq         $18, 0x20($29)
    /* ADB68 001ADB68 1000B17B */  lq         $17, 0x10($29)
    /* ADB6C 001ADB6C 0000B07B */  lq         $16, 0x0($29)
    /* ADB70 001ADB70 F000BD27 */  addiu      $29, $29, 0xF0
    /* ADB74 001ADB74 0800E003 */  jr         $31
    /* ADB78 001ADB78 00000000 */   nop
    /* ADB7C 001ADB7C 00000000 */  nop
.size func_001ad550, 0x630
