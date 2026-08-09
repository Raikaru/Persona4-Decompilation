.section .text
.set noat
.set noreorder
glabel func_003dff20
    /* 2DFF20 003DFF20 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2DFF24 003DFF24 1400A7C4 */  lwc1       $f7, 0x14($5)
    /* 2DFF28 003DFF28 2800A6C4 */  lwc1       $f6, 0x28($5)
    /* 2DFF2C 003DFF2C 1800A9C4 */  lwc1       $f9, 0x18($5)
    /* 2DFF30 003DFF30 2400A8C4 */  lwc1       $f8, 0x24($5)
    /* 2DFF34 003DFF34 0400A3C4 */  lwc1       $f3, 0x4($5)
    /* 2DFF38 003DFF38 0800A5C4 */  lwc1       $f5, 0x8($5)
    /* 2DFF3C 003DFF3C 1000A0C4 */  lwc1       $f0, 0x10($5)
    /* 2DFF40 003DFF40 1A380646 */  mula.s     $f7, $f6
    /* 2DFF44 003DFF44 0000A2C4 */  lwc1       $f2, 0x0($5)
    /* 2DFF48 003DFF48 5D480846 */  msub.s     $f1, $f9, $f8
    /* 2DFF4C 003DFF4C 000081E4 */  swc1       $f1, 0x0($4)
    /* 2DFF50 003DFF50 1A180646 */  mula.s     $f3, $f6
    /* 2DFF54 003DFF54 5D280846 */  msub.s     $f1, $f5, $f8
    /* 2DFF58 003DFF58 1A180946 */  mula.s     $f3, $f9
    /* 2DFF5C 003DFF5C 47080046 */  neg.s      $f1, $f1
    /* 2DFF60 003DFF60 5D290746 */  msub.s     $f5, $f5, $f7
    /* 2DFF64 003DFF64 040081E4 */  swc1       $f1, 0x4($4)
    /* 2DFF68 003DFF68 080085E4 */  swc1       $f5, 0x8($4)
    /* 2DFF6C 003DFF6C 040081C4 */  lwc1       $f1, 0x4($4)
    /* 2DFF70 003DFF70 000083C4 */  lwc1       $f3, 0x0($4)
    /* 2DFF74 003DFF74 2000A4C4 */  lwc1       $f4, 0x20($5)
    /* 2DFF78 003DFF78 1A080046 */  mula.s     $f1, $f0
    /* 2DFF7C 003DFF7C 1E180246 */  madda.s    $f3, $f2
    /* 2DFF80 003DFF80 1C280446 */  madd.s     $f0, $f5, $f4
    /* 2DFF84 003DFF84 0C00A0E7 */  swc1       $f0, 0xC($29)
    /* 2DFF88 003DFF88 0C00A28F */  lw         $2, 0xC($29)
    /* 2DFF8C 003DFF8C 0A004010 */  beqz       $2, .L003DFFB8
    /* 2DFF90 003DFF90 00000000 */   nop
    /* 2DFF94 003DFF94 0C00A0C7 */  lwc1       $f0, 0xC($29)
    /* 2DFF98 003DFF98 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 2DFF9C 003DFF9C 00088244 */  mtc1       $2, $f1
    /* 2DFFA0 003DFFA0 00000000 */  nop
    /* 2DFFA4 003DFFA4 030B0046 */  div.s      $f12, $f1, $f0
    /* 2DFFA8 003DFFA8 00000000 */  nop
    /* 2DFFAC 003DFFAC 00000000 */  nop
    /* 2DFFB0 003DFFB0 03000010 */  b          .L003DFFC0
    /* 2DFFB4 003DFFB4 00000000 */   nop
  .L003DFFB8:
    /* 2DFFB8 003DFFB8 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 2DFFBC 003DFFBC 00608244 */  mtc1       $2, $f12
  .L003DFFC0:
    /* 2DFFC0 003DFFC0 000080C4 */  lwc1       $f0, 0x0($4)
    /* 2DFFC4 003DFFC4 2D108000 */  daddu      $2, $4, $0
    /* 2DFFC8 003DFFC8 1000A8C4 */  lwc1       $f8, 0x10($5)
    /* 2DFFCC 003DFFCC 2800A7C4 */  lwc1       $f7, 0x28($5)
    /* 2DFFD0 003DFFD0 1800AAC4 */  lwc1       $f10, 0x18($5)
    /* 2DFFD4 003DFFD4 2000A9C4 */  lwc1       $f9, 0x20($5)
    /* 2DFFD8 003DFFD8 0000A4C4 */  lwc1       $f4, 0x0($5)
    /* 2DFFDC 003DFFDC 02000C46 */  mul.s      $f0, $f0, $f12
    /* 2DFFE0 003DFFE0 000080E4 */  swc1       $f0, 0x0($4)
    /* 2DFFE4 003DFFE4 1A400746 */  mula.s     $f8, $f7
    /* 2DFFE8 003DFFE8 1D500946 */  msub.s     $f0, $f10, $f9
    /* 2DFFEC 003DFFEC 07000046 */  neg.s      $f0, $f0
    /* 2DFFF0 003DFFF0 040082C4 */  lwc1       $f2, 0x4($4)
    /* 2DFFF4 003DFFF4 42600046 */  mul.s      $f1, $f12, $f0
    /* 2DFFF8 003DFFF8 02100C46 */  mul.s      $f0, $f2, $f12
    /* 2DFFFC 003DFFFC 040080E4 */  swc1       $f0, 0x4($4)
    /* 2E0000 003E0000 08008BC4 */  lwc1       $f11, 0x8($4)
    /* 2E0004 003E0004 0800A6C4 */  lwc1       $f6, 0x8($5)
    /* 2E0008 003E0008 1A200746 */  mula.s     $f4, $f7
    /* 2E000C 003E000C 2400A2C4 */  lwc1       $f2, 0x24($5)
    /* 2E0010 003E0010 1400A3C4 */  lwc1       $f3, 0x14($5)
    /* 2E0014 003E0014 0400A0C4 */  lwc1       $f0, 0x4($5)
    /* 2E0018 003E0018 C25A0C46 */  mul.s      $f11, $f11, $f12
    /* 2E001C 003E001C 08008BE4 */  swc1       $f11, 0x8($4)
    /* 2E0020 003E0020 100081E4 */  swc1       $f1, 0x10($4)
    /* 2E0024 003E0024 5D300946 */  msub.s     $f1, $f6, $f9
    /* 2E0028 003E0028 42600146 */  mul.s      $f1, $f12, $f1
    /* 2E002C 003E002C 1A200A46 */  mula.s     $f4, $f10
    /* 2E0030 003E0030 140081E4 */  swc1       $f1, 0x14($4)
    /* 2E0034 003E0034 5D300846 */  msub.s     $f1, $f6, $f8
    /* 2E0038 003E0038 47080046 */  neg.s      $f1, $f1
    /* 2E003C 003E003C 42600146 */  mul.s      $f1, $f12, $f1
    /* 2E0040 003E0040 180081E4 */  swc1       $f1, 0x18($4)
    /* 2E0044 003E0044 1A400246 */  mula.s     $f8, $f2
    /* 2E0048 003E0048 5D180946 */  msub.s     $f1, $f3, $f9
    /* 2E004C 003E004C 42600146 */  mul.s      $f1, $f12, $f1
    /* 2E0050 003E0050 1A200246 */  mula.s     $f4, $f2
    /* 2E0054 003E0054 200081E4 */  swc1       $f1, 0x20($4)
    /* 2E0058 003E0058 5D000946 */  msub.s     $f1, $f0, $f9
    /* 2E005C 003E005C 1A200346 */  mula.s     $f4, $f3
    /* 2E0060 003E0060 47080046 */  neg.s      $f1, $f1
    /* 2E0064 003E0064 1D000846 */  msub.s     $f0, $f0, $f8
    /* 2E0068 003E0068 42600146 */  mul.s      $f1, $f12, $f1
    /* 2E006C 003E006C 02600046 */  mul.s      $f0, $f12, $f0
    /* 2E0070 003E0070 240081E4 */  swc1       $f1, 0x24($4)
    /* 2E0074 003E0074 280080E4 */  swc1       $f0, 0x28($4)
    /* 2E0078 003E0078 3400A3C4 */  lwc1       $f3, 0x34($5)
    /* 2E007C 003E007C 100080C4 */  lwc1       $f0, 0x10($4)
    /* 2E0080 003E0080 3000A4C4 */  lwc1       $f4, 0x30($5)
    /* 2E0084 003E0084 000081C4 */  lwc1       $f1, 0x0($4)
    /* 2E0088 003E0088 3800A5C4 */  lwc1       $f5, 0x38($5)
    /* 2E008C 003E008C 200082C4 */  lwc1       $f2, 0x20($4)
    /* 2E0090 003E0090 1A180046 */  mula.s     $f3, $f0
    /* 2E0094 003E0094 1E200146 */  madda.s    $f4, $f1
    /* 2E0098 003E0098 1C280246 */  madd.s     $f0, $f5, $f2
    /* 2E009C 003E009C 07000046 */  neg.s      $f0, $f0
    /* 2E00A0 003E00A0 300080E4 */  swc1       $f0, 0x30($4)
    /* 2E00A4 003E00A4 140080C4 */  lwc1       $f0, 0x14($4)
    /* 2E00A8 003E00A8 040081C4 */  lwc1       $f1, 0x4($4)
    /* 2E00AC 003E00AC 240082C4 */  lwc1       $f2, 0x24($4)
    /* 2E00B0 003E00B0 1A180046 */  mula.s     $f3, $f0
    /* 2E00B4 003E00B4 1E200146 */  madda.s    $f4, $f1
    /* 2E00B8 003E00B8 1C280246 */  madd.s     $f0, $f5, $f2
    /* 2E00BC 003E00BC 07000046 */  neg.s      $f0, $f0
    /* 2E00C0 003E00C0 340080E4 */  swc1       $f0, 0x34($4)
    /* 2E00C4 003E00C4 180080C4 */  lwc1       $f0, 0x18($4)
    /* 2E00C8 003E00C8 080081C4 */  lwc1       $f1, 0x8($4)
    /* 2E00CC 003E00CC 280082C4 */  lwc1       $f2, 0x28($4)
    /* 2E00D0 003E00D0 1A180046 */  mula.s     $f3, $f0
    /* 2E00D4 003E00D4 1E200146 */  madda.s    $f4, $f1
    /* 2E00D8 003E00D8 1C280246 */  madd.s     $f0, $f5, $f2
    /* 2E00DC 003E00DC 07000046 */  neg.s      $f0, $f0
    /* 2E00E0 003E00E0 380080E4 */  swc1       $f0, 0x38($4)
    /* 2E00E4 003E00E4 0C0080AC */  sw         $0, 0xC($4)
    /* 2E00E8 003E00E8 0800E003 */  jr         $31
    /* 2E00EC 003E00EC 1000BD27 */   addiu     $29, $29, 0x10
.size func_003dff20, 0x1d0
