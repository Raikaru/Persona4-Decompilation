.section .text
.set noat
.set noreorder
glabel func_0044af20
    /* 34AF20 0044AF20 24600046 */  .word      0x46006024                    # cvt.w.s    $f0, $f12 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 34AF24 0044AF24 FF7F0D3C */  lui        $13, (0x7FFFFFFF >> 16)
    /* 34AF28 0044AF28 00600F44 */  mfc1       $15, $f12
    /* 34AF2C 0044AF2C FFFFAD35 */  ori        $13, $13, (0x7FFFFFFF & 0xFFFF)
    /* 34AF30 0044AF30 FF310E3C */  lui        $14, (0x31FFFFFF >> 16)
    /* 34AF34 0044AF34 FFFFCE35 */  ori        $14, $14, (0x31FFFFFF & 0xFFFF)
    /* 34AF38 0044AF38 2478ED01 */  and        $15, $15, $13
    /* 34AF3C 0044AF3C 00000C44 */  mfc1       $12, $f0
    /* 34AF40 0044AF40 2A70CF01 */  slt        $14, $14, $15
    /* 34AF44 0044AF44 0300C015 */  bnez       $14, .L0044AF54
    /* 34AF48 0044AF48 06600046 */   mov.s     $f0, $f12
    /* 34AF4C 0044AF4C 2F008011 */  beqz       $12, .L0044B00C
    /* 34AF50 0044AF50 00000000 */   nop
  .L0044AF54:
    /* 34AF54 0044AF54 82600C46 */  mul.s      $f2, $f12, $f12
    /* 34AF58 0044AF58 75000F3C */  lui        $15, %hi(D_0075629C)
    /* 34AF5C 0044AF5C 9C62EF25 */  addiu      $15, $15, %lo(D_0075629C)
    /* 34AF60 0044AF60 0000E0C5 */  lwc1       $f0, 0x0($15)
    /* 34AF64 0044AF64 75000F3C */  lui        $15, %hi(D_007562A0)
    /* 34AF68 0044AF68 02100046 */  mul.s      $f0, $f2, $f0
    /* 34AF6C 0044AF6C A062EF25 */  addiu      $15, $15, %lo(D_007562A0)
    /* 34AF70 0044AF70 C2100C46 */  mul.s      $f3, $f2, $f12
    /* 34AF74 0044AF74 0000E1C5 */  lwc1       $f1, 0x0($15)
    /* 34AF78 0044AF78 00000146 */  add.s      $f0, $f0, $f1
    /* 34AF7C 0044AF7C 75000F3C */  lui        $15, %hi(D_007562A4)
    /* 34AF80 0044AF80 A462EF25 */  addiu      $15, $15, %lo(D_007562A4)
    /* 34AF84 0044AF84 02100046 */  mul.s      $f0, $f2, $f0
    /* 34AF88 0044AF88 0000E1C5 */  lwc1       $f1, 0x0($15)
    /* 34AF8C 0044AF8C 75000F3C */  lui        $15, %hi(D_007562A8)
    /* 34AF90 0044AF90 00000146 */  add.s      $f0, $f0, $f1
    /* 34AF94 0044AF94 A862EF25 */  addiu      $15, $15, %lo(D_007562A8)
    /* 34AF98 0044AF98 02100046 */  mul.s      $f0, $f2, $f0
    /* 34AF9C 0044AF9C 0000E1C5 */  lwc1       $f1, 0x0($15)
    /* 34AFA0 0044AFA0 75000F3C */  lui        $15, %hi(D_007562AC)
    /* 34AFA4 0044AFA4 00000146 */  add.s      $f0, $f0, $f1
    /* 34AFA8 0044AFA8 AC62EF25 */  addiu      $15, $15, %lo(D_007562AC)
    /* 34AFAC 0044AFAC 02100046 */  mul.s      $f0, $f2, $f0
    /* 34AFB0 0044AFB0 0000E1C5 */  lwc1       $f1, 0x0($15)
    /* 34AFB4 0044AFB4 09008014 */  bnez       $4, .L0044AFDC
    /* 34AFB8 0044AFB8 00000146 */   add.s     $f0, $f0, $f1
    /* 34AFBC 0044AFBC 02100046 */  mul.s      $f0, $f2, $f0
    /* 34AFC0 0044AFC0 75000F3C */  lui        $15, %hi(D_007562B0)
    /* 34AFC4 0044AFC4 B062EF25 */  addiu      $15, $15, %lo(D_007562B0)
    /* 34AFC8 0044AFC8 0000E1C5 */  lwc1       $f1, 0x0($15)
    /* 34AFCC 0044AFCC 00000146 */  add.s      $f0, $f0, $f1
    /* 34AFD0 0044AFD0 02180046 */  mul.s      $f0, $f3, $f0
    /* 34AFD4 0044AFD4 0800E003 */  jr         $31
    /* 34AFD8 0044AFD8 00600046 */   add.s     $f0, $f12, $f0
  .L0044AFDC:
    /* 34AFDC 0044AFDC 75000F3C */  lui        $15, %hi(D_007562B4)
    /* 34AFE0 0044AFE0 B462EF25 */  addiu      $15, $15, %lo(D_007562B4)
    /* 34AFE4 0044AFE4 0000E1C5 */  lwc1       $f1, 0x0($15)
    /* 34AFE8 0044AFE8 1A680146 */  mula.s     $f13, $f1
    /* 34AFEC 0044AFEC 75000F3C */  lui        $15, %hi(D_007562B0)
    /* 34AFF0 0044AFF0 1D180046 */  msub.s     $f0, $f3, $f0
    /* 34AFF4 0044AFF4 B062EF25 */  addiu      $15, $15, %lo(D_007562B0)
    /* 34AFF8 0044AFF8 0000E1C5 */  lwc1       $f1, 0x0($15)
    /* 34AFFC 0044AFFC 02100046 */  mul.s      $f0, $f2, $f0
    /* 34B000 0044B000 19000D46 */  suba.s     $f0, $f13
    /* 34B004 0044B004 1D180146 */  msub.s     $f0, $f3, $f1
    /* 34B008 0044B008 01600046 */  sub.s      $f0, $f12, $f0
  .L0044B00C:
    /* 34B00C 0044B00C 0800E003 */  jr         $31
    /* 34B010 0044B010 00000000 */   nop
    /* 34B014 0044B014 00000000 */  nop
.size func_0044af20, 0xf8
