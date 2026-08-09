.section .text
.set noat
.set noreorder
glabel func_001bb790
    /* BB790 001BB790 F0FFBD27 */  addiu      $29, $29, -0x10
    /* BB794 001BB794 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* BB798 001BB798 00008344 */  mtc1       $3, $f0
    /* BB79C 001BB79C 00000000 */  nop
    /* BB7A0 001BB7A0 C1000C46 */  sub.s      $f3, $f0, $f12
    /* BB7A4 001BB7A4 42180346 */  mul.s      $f1, $f3, $f3
    /* BB7A8 001BB7A8 02180146 */  mul.s      $f0, $f3, $f1
    /* BB7AC 001BB7AC 0000A0E7 */  swc1       $f0, 0x0($29)
    /* BB7B0 001BB7B0 02600146 */  mul.s      $f0, $f12, $f1
    /* BB7B4 001BB7B4 4040033C */  lui        $3, (0x40400000 >> 16)
    /* BB7B8 001BB7B8 00108344 */  mtc1       $3, $f2
    /* BB7BC 001BB7BC 00000000 */  nop
    /* BB7C0 001BB7C0 02100046 */  mul.s      $f0, $f2, $f0
    /* BB7C4 001BB7C4 0400A0E7 */  swc1       $f0, 0x4($29)
    /* BB7C8 001BB7C8 42600C46 */  mul.s      $f1, $f12, $f12
    /* BB7CC 001BB7CC 02180146 */  mul.s      $f0, $f3, $f1
    /* BB7D0 001BB7D0 02100046 */  mul.s      $f0, $f2, $f0
    /* BB7D4 001BB7D4 0800A0E7 */  swc1       $f0, 0x8($29)
    /* BB7D8 001BB7D8 02600146 */  mul.s      $f0, $f12, $f1
    /* BB7DC 001BB7DC 0C00A0E7 */  swc1       $f0, 0xC($29)
    /* BB7E0 001BB7E0 74008794 */  lhu        $7, 0x74($4)
    /* BB7E4 001BB7E4 8800033C */  lui        $3, %hi(D_00881430)
    /* BB7E8 001BB7E8 301462C4 */  lwc1       $f2, %lo(D_00881430)($3)
    /* BB7EC 001BB7EC 8800033C */  lui        $3, %hi(D_00881434)
    /* BB7F0 001BB7F0 341461C4 */  lwc1       $f1, %lo(D_00881434)($3)
    /* BB7F4 001BB7F4 8800033C */  lui        $3, %hi(D_00881438)
    /* BB7F8 001BB7F8 381460C4 */  lwc1       $f0, %lo(D_00881438)($3)
    /* BB7FC 001BB7FC 0000A2E4 */  swc1       $f2, 0x0($5)
    /* BB800 001BB800 0400A1E4 */  swc1       $f1, 0x4($5)
    /* BB804 001BB804 0800A0E4 */  swc1       $f0, 0x8($5)
    /* BB808 001BB808 2D400000 */  daddu      $8, $0, $0
    /* BB80C 001BB80C 00088044 */  mtc1       $0, $f1
    /* BB810 001BB810 22000010 */  b          .L001BB89C
    /* BB814 001BB814 00000000 */   nop
  .L001BB818:
    /* BB818 001BB818 FFFF0331 */  andi       $3, $8, 0xFFFF
    /* BB81C 001BB81C 80180300 */  sll        $3, $3, 2
    /* BB820 001BB820 21187D00 */  addu       $3, $3, $29
    /* BB824 001BB824 00006324 */  addiu      $3, $3, 0x0
    /* BB828 001BB828 000065C4 */  lwc1       $f5, 0x0($3)
    /* BB82C 001BB82C FFFFE630 */  andi       $6, $7, 0xFFFF
    /* BB830 001BB830 C0180600 */  sll        $3, $6, 3
    /* BB834 001BB834 23186600 */  subu       $3, $3, $6
    /* BB838 001BB838 80180300 */  sll        $3, $3, 2
    /* BB83C 001BB83C 21188300 */  addu       $3, $4, $3
    /* BB840 001BB840 080060C4 */  lwc1       $f0, 0x8($3)
    /* BB844 001BB844 02010546 */  mul.s      $f4, $f0, $f5
    /* BB848 001BB848 0C0060C4 */  lwc1       $f0, 0xC($3)
    /* BB84C 001BB84C C2000546 */  mul.s      $f3, $f0, $f5
    /* BB850 001BB850 040062C4 */  lwc1       $f2, 0x4($3)
    /* BB854 001BB854 0000A0C4 */  lwc1       $f0, 0x0($5)
    /* BB858 001BB858 18080046 */  adda.s     $f1, $f0
    /* BB85C 001BB85C 1C100546 */  madd.s     $f0, $f2, $f5
    /* BB860 001BB860 0000A0E4 */  swc1       $f0, 0x0($5)
    /* BB864 001BB864 0400A0C4 */  lwc1       $f0, 0x4($5)
    /* BB868 001BB868 00000446 */  add.s      $f0, $f0, $f4
    /* BB86C 001BB86C 0400A0E4 */  swc1       $f0, 0x4($5)
    /* BB870 001BB870 0800A0C4 */  lwc1       $f0, 0x8($5)
    /* BB874 001BB874 00000346 */  add.s      $f0, $f0, $f3
    /* BB878 001BB878 0800A0E4 */  swc1       $f0, 0x8($5)
    /* BB87C 001BB87C 0100E324 */  addiu      $3, $7, 0x1
    /* BB880 001BB880 FFFF6730 */  andi       $7, $3, 0xFFFF
    /* BB884 001BB884 0400E328 */  slti       $3, $7, 0x4
    /* BB888 001BB888 02006014 */  bnez       $3, .L001BB894
    /* BB88C 001BB88C 00000000 */   nop
    /* BB890 001BB890 2D380000 */  daddu      $7, $0, $0
  .L001BB894:
    /* BB894 001BB894 01000325 */  addiu      $3, $8, 0x1
    /* BB898 001BB898 FFFF6830 */  andi       $8, $3, 0xFFFF
  .L001BB89C:
    /* BB89C 001BB89C FFFF0331 */  andi       $3, $8, 0xFFFF
    /* BB8A0 001BB8A0 04006328 */  slti       $3, $3, 0x4
    /* BB8A4 001BB8A4 DCFF6014 */  bnez       $3, .L001BB818
    /* BB8A8 001BB8A8 00000000 */   nop
    /* BB8AC 001BB8AC 1000BD27 */  addiu      $29, $29, 0x10
    /* BB8B0 001BB8B0 0800E003 */  jr         $31
    /* BB8B4 001BB8B4 00000000 */   nop
    /* BB8B8 001BB8B8 00000000 */  nop
    /* BB8BC 001BB8BC 00000000 */  nop
.size func_001bb790, 0x130
