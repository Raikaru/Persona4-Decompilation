.section .text
.set noat
.set noreorder
glabel func_003dcc70
    /* 2DCC70 003DCC70 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2DCC74 003DCC74 000084C4 */  lwc1       $f4, 0x0($4)
    /* 2DCC78 003DCC78 040083C4 */  lwc1       $f3, 0x4($4)
    /* 2DCC7C 003DCC7C 080082C4 */  lwc1       $f2, 0x8($4)
    /* 2DCC80 003DCC80 0C0081C4 */  lwc1       $f1, 0xC($4)
    /* 2DCC84 003DCC84 00008044 */  mtc1       $0, $f0
    /* 2DCC88 003DCC88 0000C4E4 */  swc1       $f4, 0x0($6)
    /* 2DCC8C 003DCC8C 0400C3E4 */  swc1       $f3, 0x4($6)
    /* 2DCC90 003DCC90 0800C2E4 */  swc1       $f2, 0x8($6)
    /* 2DCC94 003DCC94 0C00C1E4 */  swc1       $f1, 0xC($6)
    /* 2DCC98 003DCC98 040082C4 */  lwc1       $f2, 0x4($4)
    /* 2DCC9C 003DCC9C 0400A1C4 */  lwc1       $f1, 0x4($5)
    /* 2DCCA0 003DCCA0 000084C4 */  lwc1       $f4, 0x0($4)
    /* 2DCCA4 003DCCA4 0000A3C4 */  lwc1       $f3, 0x0($5)
    /* 2DCCA8 003DCCA8 080086C4 */  lwc1       $f6, 0x8($4)
    /* 2DCCAC 003DCCAC 0800A5C4 */  lwc1       $f5, 0x8($5)
    /* 2DCCB0 003DCCB0 0C00A8C4 */  lwc1       $f8, 0xC($5)
    /* 2DCCB4 003DCCB4 1A100146 */  mula.s     $f2, $f1
    /* 2DCCB8 003DCCB8 0C0087C4 */  lwc1       $f7, 0xC($4)
    /* 2DCCBC 003DCCBC 1E200346 */  madda.s    $f4, $f3
    /* 2DCCC0 003DCCC0 1E300546 */  madda.s    $f6, $f5
    /* 2DCCC4 003DCCC4 5C380846 */  madd.s     $f1, $f7, $f8
    /* 2DCCC8 003DCCC8 34080046 */  c.lt.s     $f1, $f0
    /* 2DCCCC 003DCCCC 18000045 */  bc1f       .L003DCD30
    /* 2DCCD0 003DCCD0 00000000 */   nop
    /* 2DCCD4 003DCCD4 80BF033C */  lui        $3, (0xBF800000 >> 16)
    /* 2DCCD8 003DCCD8 00008344 */  mtc1       $3, $f0
    /* 2DCCDC 003DCCDC 00000000 */  nop
    /* 2DCCE0 003DCCE0 34080046 */  c.lt.s     $f1, $f0
    /* 2DCCE4 003DCCE4 05000045 */  bc1f       .L003DCCFC
    /* 2DCCE8 003DCCE8 00000000 */   nop
    /* 2DCCEC 003DCCEC 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* 2DCCF0 003DCCF0 00008344 */  mtc1       $3, $f0
    /* 2DCCF4 003DCCF4 03000010 */  b          .L003DCD04
    /* 2DCCF8 003DCCF8 47400046 */   neg.s     $f1, $f8
  .L003DCCFC:
    /* 2DCCFC 003DCCFC 07080046 */  neg.s      $f0, $f1
    /* 2DCD00 003DCD00 47400046 */  neg.s      $f1, $f8
  .L003DCD04:
    /* 2DCD04 003DCD04 1C00C1E4 */  swc1       $f1, 0x1C($6)
    /* 2DCD08 003DCD08 0000A1C4 */  lwc1       $f1, 0x0($5)
    /* 2DCD0C 003DCD0C 47080046 */  neg.s      $f1, $f1
    /* 2DCD10 003DCD10 1000C1E4 */  swc1       $f1, 0x10($6)
    /* 2DCD14 003DCD14 0400A1C4 */  lwc1       $f1, 0x4($5)
    /* 2DCD18 003DCD18 47080046 */  neg.s      $f1, $f1
    /* 2DCD1C 003DCD1C 1400C1E4 */  swc1       $f1, 0x14($6)
    /* 2DCD20 003DCD20 0800A1C4 */  lwc1       $f1, 0x8($5)
    /* 2DCD24 003DCD24 47080046 */  neg.s      $f1, $f1
    /* 2DCD28 003DCD28 12000010 */  b          .L003DCD74
    /* 2DCD2C 003DCD2C 1800C1E4 */   swc1      $f1, 0x18($6)
  .L003DCD30:
    /* 2DCD30 003DCD30 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* 2DCD34 003DCD34 00008344 */  mtc1       $3, $f0
    /* 2DCD38 003DCD38 00000000 */  nop
    /* 2DCD3C 003DCD3C 36080046 */  c.le.s     $f1, $f0
    /* 2DCD40 003DCD40 03000145 */  bc1t       .L003DCD50
    /* 2DCD44 003DCD44 00000000 */   nop
    /* 2DCD48 003DCD48 03000010 */  b          .L003DCD58
    /* 2DCD4C 003DCD4C 0000A4C4 */   lwc1      $f4, 0x0($5)
  .L003DCD50:
    /* 2DCD50 003DCD50 06080046 */  mov.s      $f0, $f1
    /* 2DCD54 003DCD54 0000A4C4 */  lwc1       $f4, 0x0($5)
  .L003DCD58:
    /* 2DCD58 003DCD58 0400A3C4 */  lwc1       $f3, 0x4($5)
    /* 2DCD5C 003DCD5C 0800A2C4 */  lwc1       $f2, 0x8($5)
    /* 2DCD60 003DCD60 0C00A1C4 */  lwc1       $f1, 0xC($5)
    /* 2DCD64 003DCD64 1000C4E4 */  swc1       $f4, 0x10($6)
    /* 2DCD68 003DCD68 1400C3E4 */  swc1       $f3, 0x14($6)
    /* 2DCD6C 003DCD6C 1800C2E4 */  swc1       $f2, 0x18($6)
    /* 2DCD70 003DCD70 1C00C1E4 */  swc1       $f1, 0x1C($6)
  .L003DCD74:
    /* 2DCD74 003DCD74 0C00A0E7 */  swc1       $f0, 0xC($29)
    /* 2DCD78 003DCD78 803F013C */  lui        $1, (0x3F800000 >> 16)
    /* 2DCD7C 003DCD7C 0C00A48F */  lw         $4, 0xC($29)
    /* 2DCD80 003DCD80 7C180400 */  dsll32     $3, $4, 1
    /* 2DCD84 003DCD84 7E180300 */  dsrl32     $3, $3, 1
    /* 2DCD88 003DCD88 2A086100 */  slt        $1, $3, $1
    /* 2DCD8C 003DCD8C 5E002010 */  beqz       $1, .L003DCF08
    /* 2DCD90 003DCD90 00000000 */   nop
    /* 2DCD94 003DCD94 003F013C */  lui        $1, (0x3F000000 >> 16)
    /* 2DCD98 003DCD98 2A086100 */  slt        $1, $3, $1
    /* 2DCD9C 003DCD9C 62002010 */  beqz       $1, .L003DCF28
    /* 2DCDA0 003DCDA0 00000000 */   nop
    /* 2DCDA4 003DCDA4 0023013C */  lui        $1, (0x23000001 >> 16)
    /* 2DCDA8 003DCDA8 01002134 */  ori        $1, $1, (0x23000001 & 0xFFFF)
    /* 2DCDAC 003DCDAC 2A086100 */  slt        $1, $3, $1
    /* 2DCDB0 003DCDB0 05002010 */  beqz       $1, .L003DCDC8
    /* 2DCDB4 003DCDB4 00000000 */   nop
    /* 2DCDB8 003DCDB8 C93F033C */  lui        $3, (0x3FC90FDB >> 16)
    /* 2DCDBC 003DCDBC DB0F6334 */  ori        $3, $3, (0x3FC90FDB & 0xFFFF)
    /* 2DCDC0 003DCDC0 43000010 */  b          .L003DCED0
    /* 2DCDC4 003DCDC4 2000C3AC */   sw        $3, 0x20($6)
  .L003DCDC8:
    /* 2DCDC8 003DCDC8 1138033C */  lui        $3, (0x3811EF08 >> 16)
    /* 2DCDCC 003DCDCC 08EF6434 */  ori        $4, $3, (0x3811EF08 & 0xFFFF)
    /* 2DCDD0 003DCDD0 4F3A033C */  lui        $3, (0x3A4F7F04 >> 16)
    /* 2DCDD4 003DCDD4 047F6834 */  ori        $8, $3, (0x3A4F7F04 & 0xFFFF)
    /* 2DCDD8 003DCDD8 24BD033C */  lui        $3, (0xBD241146 >> 16)
    /* 2DCDDC 003DCDDC 46116534 */  ori        $5, $3, (0xBD241146 & 0xFFFF)
    /* 2DCDE0 003DCDE0 4E3E033C */  lui        $3, (0x3E4E0AA8 >> 16)
    /* 2DCDE4 003DCDE4 A80A6734 */  ori        $7, $3, (0x3E4E0AA8 & 0xFFFF)
    /* 2DCDE8 003DCDE8 00708444 */  mtc1       $4, $f14
    /* 2DCDEC 003DCDEC A6BE033C */  lui        $3, (0xBEA6B090 >> 16)
    /* 2DCDF0 003DCDF0 C2030046 */  mul.s      $f15, $f0, $f0
    /* 2DCDF4 003DCDF4 90B06434 */  ori        $4, $3, (0xBEA6B090 & 0xFFFF)
    /* 2DCDF8 003DCDF8 2A3E033C */  lui        $3, (0x3E2AAAAB >> 16)
    /* 2DCDFC 003DCDFC 00588544 */  mtc1       $5, $f11
    /* 2DCE00 003DCE00 00688844 */  mtc1       $8, $f13
    /* 2DCE04 003DCE04 ABAA6534 */  ori        $5, $3, (0x3E2AAAAB & 0xFFFF)
    /* 2DCE08 003DCE08 00608044 */  mtc1       $0, $f12
    /* 2DCE0C 003DCE0C 9D3D033C */  lui        $3, (0x3D9DC62E >> 16)
    /* 2DCE10 003DCE10 00488444 */  mtc1       $4, $f9
    /* 2DCE14 003DCE14 18600D46 */  adda.s     $f12, $f13
    /* 2DCE18 003DCE18 2EC66434 */  ori        $4, $3, (0x3D9DC62E & 0xFFFF)
    /* 2DCE1C 003DCE1C 30BF033C */  lui        $3, (0xBF303361 >> 16)
    /* 2DCE20 003DCE20 5C730F46 */  madd.s     $f13, $f14, $f15
    /* 2DCE24 003DCE24 61336334 */  ori        $3, $3, (0xBF303361 & 0xFFFF)
    /* 2DCE28 003DCE28 18600B46 */  adda.s     $f12, $f11
    /* 2DCE2C 003DCE2C 00308344 */  mtc1       $3, $f6
    /* 2DCE30 003DCE30 00508744 */  mtc1       $7, $f10
    /* 2DCE34 003DCE34 DC7A0D46 */  madd.s     $f11, $f15, $f13
    /* 2DCE38 003DCE38 0140033C */  lui        $3, (0x4001572D >> 16)
    /* 2DCE3C 003DCE3C 00388444 */  mtc1       $4, $f7
    /* 2DCE40 003DCE40 18600A46 */  adda.s     $f12, $f10
    /* 2DCE44 003DCE44 2D576434 */  ori        $4, $3, (0x4001572D & 0xFFFF)
    /* 2DCE48 003DCE48 9C7A0B46 */  madd.s     $f10, $f15, $f11
    /* 2DCE4C 003DCE4C 19C0033C */  lui        $3, (0xC019D139 >> 16)
    /* 2DCE50 003DCE50 18600946 */  adda.s     $f12, $f9
    /* 2DCE54 003DCE54 39D16334 */  ori        $3, $3, (0xC019D139 & 0xFFFF)
    /* 2DCE58 003DCE58 00208344 */  mtc1       $3, $f4
    /* 2DCE5C 003DCE5C 00408544 */  mtc1       $5, $f8
    /* 2DCE60 003DCE60 5C7A0A46 */  madd.s     $f9, $f15, $f10
    /* 2DCE64 003DCE64 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* 2DCE68 003DCE68 18600846 */  adda.s     $f12, $f8
    /* 2DCE6C 003DCE6C 1C7A0946 */  madd.s     $f8, $f15, $f9
    /* 2DCE70 003DCE70 18600646 */  adda.s     $f12, $f6
    /* 2DCE74 003DCE74 00188344 */  mtc1       $3, $f3
    /* 2DCE78 003DCE78 00288444 */  mtc1       $4, $f5
    /* 2DCE7C 003DCE7C 9C390F46 */  madd.s     $f6, $f7, $f15
    /* 2DCE80 003DCE80 A233033C */  lui        $3, (0x33A22168 >> 16)
    /* 2DCE84 003DCE84 68216434 */  ori        $4, $3, (0x33A22168 & 0xFFFF)
    /* 2DCE88 003DCE88 18600546 */  adda.s     $f12, $f5
    /* 2DCE8C 003DCE8C C93F033C */  lui        $3, (0x3FC90FDA >> 16)
    /* 2DCE90 003DCE90 5C790646 */  madd.s     $f5, $f15, $f6
    /* 2DCE94 003DCE94 DA0F6334 */  ori        $3, $3, (0x3FC90FDA & 0xFFFF)
    /* 2DCE98 003DCE98 18600446 */  adda.s     $f12, $f4
    /* 2DCE9C 003DCE9C 1C790546 */  madd.s     $f4, $f15, $f5
    /* 2DCEA0 003DCEA0 18600346 */  adda.s     $f12, $f3
    /* 2DCEA4 003DCEA4 027A0846 */  mul.s      $f8, $f15, $f8
    /* 2DCEA8 003DCEA8 00108444 */  mtc1       $4, $f2
    /* 2DCEAC 003DCEAC DC780446 */  madd.s     $f3, $f15, $f4
    /* 2DCEB0 003DCEB0 18600246 */  adda.s     $f12, $f2
    /* 2DCEB4 003DCEB4 83400346 */  div.s      $f2, $f8, $f3
    /* 2DCEB8 003DCEB8 9D000246 */  msub.s     $f2, $f0, $f2
    /* 2DCEBC 003DCEBC 81000246 */  sub.s      $f2, $f0, $f2
    /* 2DCEC0 003DCEC0 00088344 */  mtc1       $3, $f1
    /* 2DCEC4 003DCEC4 00000000 */  nop
    /* 2DCEC8 003DCEC8 41080246 */  sub.s      $f1, $f1, $f2
    /* 2DCECC 003DCECC 2000C1E4 */  swc1       $f1, 0x20($6)
  .L003DCED0:
    /* 2DCED0 003DCED0 7F3F033C */  lui        $3, (0x3F7FFF58 >> 16)
    /* 2DCED4 003DCED4 58FF6334 */  ori        $3, $3, (0x3F7FFF58 & 0xFFFF)
    /* 2DCED8 003DCED8 00088344 */  mtc1       $3, $f1
    /* 2DCEDC 003DCEDC 00000000 */  nop
    /* 2DCEE0 003DCEE0 34000146 */  c.lt.s     $f0, $f1
    /* 2DCEE4 003DCEE4 02000045 */  bc1f       .L003DCEF0
    /* 2DCEE8 003DCEE8 01000424 */   addiu     $4, $0, 0x1
    /* 2DCEEC 003DCEEC 2D200000 */  daddu      $4, $0, $0
  .L003DCEF0:
    /* 2DCEF0 003DCEF0 2400C4AC */  sw         $4, 0x24($6)
    /* 2DCEF4 003DCEF4 2400C38C */  lw         $3, 0x24($6)
    /* 2DCEF8 003DCEF8 A4006010 */  beqz       $3, .L003DD18C
    /* 2DCEFC 003DCEFC 00000000 */   nop
  .L003DCF00:
    /* 2DCF00 003DCF00 E1000010 */  b          .L003DD288
    /* 2DCF04 003DCF04 1000BD27 */   addiu     $29, $29, 0x10
  .L003DCF08:
    /* 2DCF08 003DCF08 03008018 */  blez       $4, .L003DCF18
    /* 2DCF0C 003DCF0C 00000000 */   nop
    /* 2DCF10 003DCF10 EFFF0010 */  b          .L003DCED0
    /* 2DCF14 003DCF14 2000C0AC */   sw        $0, 0x20($6)
  .L003DCF18:
    /* 2DCF18 003DCF18 4940033C */  lui        $3, (0x40490FDB >> 16)
    /* 2DCF1C 003DCF1C DB0F6334 */  ori        $3, $3, (0x40490FDB & 0xFFFF)
    /* 2DCF20 003DCF20 EBFF0010 */  b          .L003DCED0
    /* 2DCF24 003DCF24 2000C3AC */   sw        $3, 0x20($6)
  .L003DCF28:
    /* 2DCF28 003DCF28 4F008004 */  bltz       $4, .L003DD068
    /* 2DCF2C 003DCF2C 00000000 */   nop
    /* 2DCF30 003DCF30 803F043C */  lui        $4, (0x3F800000 >> 16)
    /* 2DCF34 003DCF34 003F033C */  lui        $3, (0x3F000000 >> 16)
    /* 2DCF38 003DCF38 00708444 */  mtc1       $4, $f14
    /* 2DCF3C 003DCF3C 00688344 */  mtc1       $3, $f13
    /* 2DCF40 003DCF40 1138043C */  lui        $4, (0x3811EF08 >> 16)
    /* 2DCF44 003DCF44 08EF8534 */  ori        $5, $4, (0x3811EF08 & 0xFFFF)
    /* 2DCF48 003DCF48 00F00324 */  addiu      $3, $0, -0x1000
    /* 2DCF4C 003DCF4C 4F3A043C */  lui        $4, (0x3A4F7F04 >> 16)
    /* 2DCF50 003DCF50 047F8434 */  ori        $4, $4, (0x3A4F7F04 & 0xFFFF)
    /* 2DCF54 003DCF54 00588444 */  mtc1       $4, $f11
    /* 2DCF58 003DCF58 81720046 */  sub.s      $f10, $f14, $f0
    /* 2DCF5C 003DCF5C 24BD043C */  lui        $4, (0xBD241146 >> 16)
    /* 2DCF60 003DCF60 426B0A46 */  mul.s      $f13, $f13, $f10
    /* 2DCF64 003DCF64 00608544 */  mtc1       $5, $f12
    /* 2DCF68 003DCF68 00508044 */  mtc1       $0, $f10
    /* 2DCF6C 003DCF6C 46118534 */  ori        $5, $4, (0xBD241146 & 0xFFFF)
    /* 2DCF70 003DCF70 4E3E043C */  lui        $4, (0x3E4E0AA8 >> 16)
    /* 2DCF74 003DCF74 A80A8434 */  ori        $4, $4, (0x3E4E0AA8 & 0xFFFF)
    /* 2DCF78 003DCF78 00408444 */  mtc1       $4, $f8
    /* 2DCF7C 003DCF7C 18500B46 */  adda.s     $f10, $f11
    /* 2DCF80 003DCF80 C4030D46 */  c1         0xD03C4
    /* 2DCF84 003DCF84 A6BE043C */  lui        $4, (0xBEA6B090 >> 16)
    /* 2DCF88 003DCF88 00488544 */  mtc1       $5, $f9
    /* 2DCF8C 003DCF8C DC620D46 */  madd.s     $f11, $f12, $f13
    /* 2DCF90 003DCF90 90B08534 */  ori        $5, $4, (0xBEA6B090 & 0xFFFF)
    /* 2DCF94 003DCF94 2A3E043C */  lui        $4, (0x3E2AAAAB >> 16)
    /* 2DCF98 003DCF98 ABAA8434 */  ori        $4, $4, (0x3E2AAAAB & 0xFFFF)
    /* 2DCF9C 003DCF9C 00388444 */  mtc1       $4, $f7
    /* 2DCFA0 003DCFA0 18500946 */  adda.s     $f10, $f9
    /* 2DCFA4 003DCFA4 5C6A0B46 */  madd.s     $f9, $f13, $f11
    /* 2DCFA8 003DCFA8 9D3D043C */  lui        $4, (0x3D9DC62E >> 16)
    /* 2DCFAC 003DCFAC 00208544 */  mtc1       $5, $f4
    /* 2DCFB0 003DCFB0 18500846 */  adda.s     $f10, $f8
    /* 2DCFB4 003DCFB4 2EC68534 */  ori        $5, $4, (0x3D9DC62E & 0xFFFF)
    /* 2DCFB8 003DCFB8 30BF043C */  lui        $4, (0xBF303361 >> 16)
    /* 2DCFBC 003DCFBC 61338434 */  ori        $4, $4, (0xBF303361 & 0xFFFF)
    /* 2DCFC0 003DCFC0 1C6A0946 */  madd.s     $f8, $f13, $f9
    /* 2DCFC4 003DCFC4 00288444 */  mtc1       $4, $f5
    /* 2DCFC8 003DCFC8 00000000 */  nop
    /* 2DCFCC 003DCFCC 18500446 */  adda.s     $f10, $f4
    /* 2DCFD0 003DCFD0 1C6A0846 */  madd.s     $f8, $f13, $f8
    /* 2DCFD4 003DCFD4 0140043C */  lui        $4, (0x4001572D >> 16)
    /* 2DCFD8 003DCFD8 00308544 */  mtc1       $5, $f6
    /* 2DCFDC 003DCFDC 00000000 */  nop
    /* 2DCFE0 003DCFE0 18500746 */  adda.s     $f10, $f7
    /* 2DCFE4 003DCFE4 2D578534 */  ori        $5, $4, (0x4001572D & 0xFFFF)
    /* 2DCFE8 003DCFE8 DC690846 */  madd.s     $f7, $f13, $f8
    /* 2DCFEC 003DCFEC 19C0043C */  lui        $4, (0xC019D139 >> 16)
    /* 2DCFF0 003DCFF0 18500546 */  adda.s     $f10, $f5
    /* 2DCFF4 003DCFF4 39D18434 */  ori        $4, $4, (0xC019D139 & 0xFFFF)
    /* 2DCFF8 003DCFF8 00108444 */  mtc1       $4, $f2
    /* 2DCFFC 003DCFFC 00188544 */  mtc1       $5, $f3
    /* 2DD000 003DD000 5C310D46 */  madd.s     $f5, $f6, $f13
    /* 2DD004 003DD004 0040043C */  lui        $4, (0x40000000 >> 16)
    /* 2DD008 003DD008 18500346 */  adda.s     $f10, $f3
    /* 2DD00C 003DD00C DC680546 */  madd.s     $f3, $f13, $f5
    /* 2DD010 003DD010 18500246 */  adda.s     $f10, $f2
    /* 2DD014 003DD014 9C680346 */  madd.s     $f2, $f13, $f3
    /* 2DD018 003DD018 18500E46 */  adda.s     $f10, $f14
    /* 2DD01C 003DD01C 9C680246 */  madd.s     $f2, $f13, $f2
    /* 2DD020 003DD020 C2690746 */  mul.s      $f7, $f13, $f7
    /* 2DD024 003DD024 43390246 */  div.s      $f5, $f7, $f2
    /* 2DD028 003DD028 00088444 */  mtc1       $4, $f1
    /* 2DD02C 003DD02C 0800AFE7 */  swc1       $f15, 0x8($29)
    /* 2DD030 003DD030 0800A48F */  lw         $4, 0x8($29)
    /* 2DD034 003DD034 18500D46 */  adda.s     $f10, $f13
    /* 2DD038 003DD038 24188300 */  and        $3, $4, $3
    /* 2DD03C 003DD03C 0400A3AF */  sw         $3, 0x4($29)
    /* 2DD040 003DD040 0400A4C7 */  lwc1       $f4, 0x4($29)
    /* 2DD044 003DD044 80780446 */  add.s      $f2, $f15, $f4
    /* 2DD048 003DD048 DD200446 */  msub.s     $f3, $f4, $f4
    /* 2DD04C 003DD04C 83180246 */  div.s      $f2, $f3, $f2
    /* 2DD050 003DD050 18500246 */  adda.s     $f10, $f2
    /* 2DD054 003DD054 9C280F46 */  madd.s     $f2, $f5, $f15
    /* 2DD058 003DD058 80200246 */  add.s      $f2, $f4, $f2
    /* 2DD05C 003DD05C 42080246 */  mul.s      $f1, $f1, $f2
    /* 2DD060 003DD060 9BFF0010 */  b          .L003DCED0
    /* 2DD064 003DD064 2000C1E4 */   swc1      $f1, 0x20($6)
  .L003DD068:
    /* 2DD068 003DD068 003F033C */  lui        $3, (0x3F000000 >> 16)
    /* 2DD06C 003DD06C 803F043C */  lui        $4, (0x3F800000 >> 16)
    /* 2DD070 003DD070 00788344 */  mtc1       $3, $f15
    /* 2DD074 003DD074 00808444 */  mtc1       $4, $f16
    /* 2DD078 003DD078 1138033C */  lui        $3, (0x3811EF08 >> 16)
    /* 2DD07C 003DD07C 08EF6334 */  ori        $3, $3, (0x3811EF08 & 0xFFFF)
    /* 2DD080 003DD080 00708344 */  mtc1       $3, $f14
    /* 2DD084 003DD084 00830046 */  add.s      $f12, $f16, $f0
    /* 2DD088 003DD088 4F3A033C */  lui        $3, (0x3A4F7F04 >> 16)
    /* 2DD08C 003DD08C 047F6434 */  ori        $4, $3, (0x3A4F7F04 & 0xFFFF)
    /* 2DD090 003DD090 24BD033C */  lui        $3, (0xBD241146 >> 16)
    /* 2DD094 003DD094 46116334 */  ori        $3, $3, (0xBD241146 & 0xFFFF)
    /* 2DD098 003DD098 00588344 */  mtc1       $3, $f11
    /* 2DD09C 003DD09C 00688444 */  mtc1       $4, $f13
    /* 2DD0A0 003DD0A0 4E3E033C */  lui        $3, (0x3E4E0AA8 >> 16)
    /* 2DD0A4 003DD0A4 A80A6434 */  ori        $4, $3, (0x3E4E0AA8 & 0xFFFF)
    /* 2DD0A8 003DD0A8 A6BE033C */  lui        $3, (0xBEA6B090 >> 16)
    /* 2DD0AC 003DD0AC 90B06334 */  ori        $3, $3, (0xBEA6B090 & 0xFFFF)
    /* 2DD0B0 003DD0B0 00488344 */  mtc1       $3, $f9
    /* 2DD0B4 003DD0B4 00508444 */  mtc1       $4, $f10
    /* 2DD0B8 003DD0B8 C27B0C46 */  mul.s      $f15, $f15, $f12
    /* 2DD0BC 003DD0BC 2A3E033C */  lui        $3, (0x3E2AAAAB >> 16)
    /* 2DD0C0 003DD0C0 ABAA6434 */  ori        $4, $3, (0x3E2AAAAB & 0xFFFF)
    /* 2DD0C4 003DD0C4 9D3D033C */  lui        $3, (0x3D9DC62E >> 16)
    /* 2DD0C8 003DD0C8 2EC66334 */  ori        $3, $3, (0x3D9DC62E & 0xFFFF)
    /* 2DD0CC 003DD0CC 00388344 */  mtc1       $3, $f7
    /* 2DD0D0 003DD0D0 00608044 */  mtc1       $0, $f12
    /* 2DD0D4 003DD0D4 00408444 */  mtc1       $4, $f8
    /* 2DD0D8 003DD0D8 30BF033C */  lui        $3, (0xBF303361 >> 16)
    /* 2DD0DC 003DD0DC 18600D46 */  adda.s     $f12, $f13
    /* 2DD0E0 003DD0E0 61336434 */  ori        $4, $3, (0xBF303361 & 0xFFFF)
    /* 2DD0E4 003DD0E4 0140033C */  lui        $3, (0x4001572D >> 16)
    /* 2DD0E8 003DD0E8 5C730F46 */  madd.s     $f13, $f14, $f15
    /* 2DD0EC 003DD0EC 2D576334 */  ori        $3, $3, (0x4001572D & 0xFFFF)
    /* 2DD0F0 003DD0F0 18600B46 */  adda.s     $f12, $f11
    /* 2DD0F4 003DD0F4 00288344 */  mtc1       $3, $f5
    /* 2DD0F8 003DD0F8 DC7A0D46 */  madd.s     $f11, $f15, $f13
    /* 2DD0FC 003DD0FC 18600A46 */  adda.s     $f12, $f10
    /* 2DD100 003DD100 19C0033C */  lui        $3, (0xC019D139 >> 16)
    /* 2DD104 003DD104 00308444 */  mtc1       $4, $f6
    /* 2DD108 003DD108 9C7A0B46 */  madd.s     $f10, $f15, $f11
    /* 2DD10C 003DD10C 39D16434 */  ori        $4, $3, (0xC019D139 & 0xFFFF)
    /* 2DD110 003DD110 18600946 */  adda.s     $f12, $f9
    /* 2DD114 003DD114 A233033C */  lui        $3, (0x33A22168 >> 16)
    /* 2DD118 003DD118 5C7A0A46 */  madd.s     $f9, $f15, $f10
    /* 2DD11C 003DD11C 68216334 */  ori        $3, $3, (0x33A22168 & 0xFFFF)
    /* 2DD120 003DD120 18600846 */  adda.s     $f12, $f8
    /* 2DD124 003DD124 1C7A0946 */  madd.s     $f8, $f15, $f9
    /* 2DD128 003DD128 00188344 */  mtc1       $3, $f3
    /* 2DD12C 003DD12C 18600646 */  adda.s     $f12, $f6
    /* 2DD130 003DD130 0040033C */  lui        $3, (0x40000000 >> 16)
    /* 2DD134 003DD134 9C390F46 */  madd.s     $f6, $f7, $f15
    /* 2DD138 003DD138 00108344 */  mtc1       $3, $f2
    /* 2DD13C 003DD13C 18600546 */  adda.s     $f12, $f5
    /* 2DD140 003DD140 4940033C */  lui        $3, (0x40490FDA >> 16)
    /* 2DD144 003DD144 DA0F6334 */  ori        $3, $3, (0x40490FDA & 0xFFFF)
    /* 2DD148 003DD148 00208444 */  mtc1       $4, $f4
    /* 2DD14C 003DD14C 5C790646 */  madd.s     $f5, $f15, $f6
    /* 2DD150 003DD150 18600446 */  adda.s     $f12, $f4
    /* 2DD154 003DD154 1C790546 */  madd.s     $f4, $f15, $f5
    /* 2DD158 003DD158 18601046 */  adda.s     $f12, $f16
    /* 2DD15C 003DD15C 027A0846 */  mul.s      $f8, $f15, $f8
    /* 2DD160 003DD160 00088344 */  mtc1       $3, $f1
    /* 2DD164 003DD164 1C790446 */  madd.s     $f4, $f15, $f4
    /* 2DD168 003DD168 18600146 */  adda.s     $f12, $f1
    /* 2DD16C 003DD16C 44040F46 */  c1         0xF0444
    /* 2DD170 003DD170 43400446 */  div.s      $f1, $f8, $f4
    /* 2DD174 003DD174 42081146 */  mul.s      $f1, $f1, $f17
    /* 2DD178 003DD178 41080346 */  sub.s      $f1, $f1, $f3
    /* 2DD17C 003DD17C 40880146 */  add.s      $f1, $f17, $f1
    /* 2DD180 003DD180 5D100146 */  msub.s     $f1, $f2, $f1
    /* 2DD184 003DD184 52FF0010 */  b          .L003DCED0
    /* 2DD188 003DD188 2000C1E4 */   swc1      $f1, 0x20($6)
  .L003DD18C:
    /* 2DD18C 003DD18C 2000CAC4 */  lwc1       $f10, 0x20($6)
    /* 2DD190 003DD190 2E2F033C */  lui        $3, (0x2F2EC9D3 >> 16)
    /* 2DD194 003DD194 D3C96434 */  ori        $4, $3, (0x2F2EC9D3 & 0xFFFF)
    /* 2DD198 003DD198 D7B2033C */  lui        $3, (0xB2D72F34 >> 16)
    /* 2DD19C 003DD19C 342F6334 */  ori        $3, $3, (0xB2D72F34 & 0xFFFF)
    /* 2DD1A0 003DD1A0 00388344 */  mtc1       $3, $f7
    /* 2DD1A4 003DD1A4 00408444 */  mtc1       $4, $f8
    /* 2DD1A8 003DD1A8 3836033C */  lui        $3, (0x3638EF1B >> 16)
    /* 2DD1AC 003DD1AC 1BEF6434 */  ori        $4, $3, (0x3638EF1B & 0xFFFF)
    /* 2DD1B0 003DD1B0 42520A46 */  mul.s      $f9, $f10, $f10
    /* 2DD1B4 003DD1B4 50B9033C */  lui        $3, (0xB9500D01 >> 16)
    /* 2DD1B8 003DD1B8 010D6334 */  ori        $3, $3, (0xB9500D01 & 0xFFFF)
    /* 2DD1BC 003DD1BC 00308044 */  mtc1       $0, $f6
    /* 2DD1C0 003DD1C0 00208344 */  mtc1       $3, $f4
    /* 2DD1C4 003DD1C4 18300746 */  adda.s     $f6, $f7
    /* 2DD1C8 003DD1C8 00288444 */  mtc1       $4, $f5
    /* 2DD1CC 003DD1CC 083C033C */  lui        $3, (0x3C088889 >> 16)
    /* 2DD1D0 003DD1D0 DC410946 */  madd.s     $f7, $f8, $f9
    /* 2DD1D4 003DD1D4 89886434 */  ori        $4, $3, (0x3C088889 & 0xFFFF)
    /* 2DD1D8 003DD1D8 18300546 */  adda.s     $f6, $f5
    /* 2DD1DC 003DD1DC 2ABE033C */  lui        $3, (0xBE2AAAAB >> 16)
    /* 2DD1E0 003DD1E0 5C490746 */  madd.s     $f5, $f9, $f7
    /* 2DD1E4 003DD1E4 ABAA6334 */  ori        $3, $3, (0xBE2AAAAB & 0xFFFF)
    /* 2DD1E8 003DD1E8 18300446 */  adda.s     $f6, $f4
    /* 2DD1EC 003DD1EC 00108344 */  mtc1       $3, $f2
    /* 2DD1F0 003DD1F0 00188444 */  mtc1       $4, $f3
    /* 2DD1F4 003DD1F4 1C490546 */  madd.s     $f4, $f9, $f5
    /* 2DD1F8 003DD1F8 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* 2DD1FC 003DD1FC 18300346 */  adda.s     $f6, $f3
    /* 2DD200 003DD200 DC480446 */  madd.s     $f3, $f9, $f4
    /* 2DD204 003DD204 18300246 */  adda.s     $f6, $f2
    /* 2DD208 003DD208 9C480346 */  madd.s     $f2, $f9, $f3
    /* 2DD20C 003DD20C 42480A46 */  mul.s      $f1, $f9, $f10
    /* 2DD210 003DD210 18300A46 */  adda.s     $f6, $f10
    /* 2DD214 003DD214 00008344 */  mtc1       $3, $f0
    /* 2DD218 003DD218 00000000 */  nop
    /* 2DD21C 003DD21C 5C080246 */  madd.s     $f1, $f1, $f2
    /* 2DD220 003DD220 43000146 */  div.s      $f1, $f0, $f1
    /* 2DD224 003DD224 0C00C0C4 */  lwc1       $f0, 0xC($6)
    /* 2DD228 003DD228 02000146 */  mul.s      $f0, $f0, $f1
    /* 2DD22C 003DD22C 0C00C0E4 */  swc1       $f0, 0xC($6)
    /* 2DD230 003DD230 0000C0C4 */  lwc1       $f0, 0x0($6)
    /* 2DD234 003DD234 02000146 */  mul.s      $f0, $f0, $f1
    /* 2DD238 003DD238 0000C0E4 */  swc1       $f0, 0x0($6)
    /* 2DD23C 003DD23C 0400C0C4 */  lwc1       $f0, 0x4($6)
    /* 2DD240 003DD240 02000146 */  mul.s      $f0, $f0, $f1
    /* 2DD244 003DD244 0400C0E4 */  swc1       $f0, 0x4($6)
    /* 2DD248 003DD248 0800C0C4 */  lwc1       $f0, 0x8($6)
    /* 2DD24C 003DD24C 02000146 */  mul.s      $f0, $f0, $f1
    /* 2DD250 003DD250 0800C0E4 */  swc1       $f0, 0x8($6)
    /* 2DD254 003DD254 1C00C0C4 */  lwc1       $f0, 0x1C($6)
    /* 2DD258 003DD258 02000146 */  mul.s      $f0, $f0, $f1
    /* 2DD25C 003DD25C 1C00C0E4 */  swc1       $f0, 0x1C($6)
    /* 2DD260 003DD260 1000C0C4 */  lwc1       $f0, 0x10($6)
    /* 2DD264 003DD264 02000146 */  mul.s      $f0, $f0, $f1
    /* 2DD268 003DD268 1000C0E4 */  swc1       $f0, 0x10($6)
    /* 2DD26C 003DD26C 1400C0C4 */  lwc1       $f0, 0x14($6)
    /* 2DD270 003DD270 02000146 */  mul.s      $f0, $f0, $f1
    /* 2DD274 003DD274 1400C0E4 */  swc1       $f0, 0x14($6)
    /* 2DD278 003DD278 1800C0C4 */  lwc1       $f0, 0x18($6)
    /* 2DD27C 003DD27C 02000146 */  mul.s      $f0, $f0, $f1
    /* 2DD280 003DD280 1FFF0010 */  b          .L003DCF00
    /* 2DD284 003DD284 1800C0E4 */   swc1      $f0, 0x18($6)
  .L003DD288:
    /* 2DD288 003DD288 0800E003 */  jr         $31
    /* 2DD28C 003DD28C 00000000 */   nop
.size func_003dcc70, 0x620
