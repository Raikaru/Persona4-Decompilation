.section .text
.set noat
.set noreorder
glabel func_0014cef0
    /* 4CEF0 0014CEF0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 4CEF4 0014CEF4 2000BFFF */  sd         $31, 0x20($29)
    /* 4CEF8 0014CEF8 1000B17F */  sq         $17, 0x10($29)
    /* 4CEFC 0014CEFC 0000B07F */  sq         $16, 0x0($29)
    /* 4CF00 0014CF00 2D888000 */  daddu      $17, $4, $0
    /* 4CF04 0014CF04 2D80A000 */  daddu      $16, $5, $0
    /* 4CF08 0014CF08 0F000424 */  addiu      $4, $0, 0xF
    /* 4CF0C 0014CF0C AC14050C */  jal        func_001452b0
    /* 4CF10 0014CF10 00000000 */   nop
    /* 4CF14 0014CF14 1644033C */  lui        $3, (0x44160000 >> 16)
    /* 4CF18 0014CF18 00108344 */  mtc1       $3, $f2
    /* 4CF1C 0014CF1C 9644033C */  lui        $3, (0x44960000 >> 16)
    /* 4CF20 0014CF20 00088344 */  mtc1       $3, $f1
    /* 4CF24 0014CF24 01002426 */  addiu      $4, $17, 0x1
    /* 4CF28 0014CF28 01000326 */  addiu      $3, $16, 0x1
    /* 4CF2C 0014CF2C 1F000010 */  b          .L0014CFAC
    /* 4CF30 0014CF30 00000000 */   nop
  .L0014CF34:
    /* 4CF34 0014CF34 400140C4 */  lwc1       $f0, 0x140($2)
    /* 4CF38 0014CF38 00100046 */  add.s      $f0, $f2, $f0
    /* 4CF3C 0014CF3C 03000146 */  div.s      $f0, $f0, $f1
    /* 4CF40 0014CF40 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 4CF44 0014CF44 00000644 */  mfc1       $6, $f0
    /* 4CF48 0014CF48 480140C4 */  lwc1       $f0, 0x148($2)
    /* 4CF4C 0014CF4C 00100046 */  add.s      $f0, $f2, $f0
    /* 4CF50 0014CF50 03000146 */  div.s      $f0, $f0, $f1
    /* 4CF54 0014CF54 00000000 */  nop
    /* 4CF58 0014CF58 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 4CF5C 0014CF5C 00000544 */  mfc1       $5, $f0
    /* 4CF60 0014CF60 0300D114 */  bne        $6, $17, .L0014CF70
    /* 4CF64 0014CF64 00000000 */   nop
    /* 4CF68 0014CF68 0D00B010 */  beq        $5, $16, .L0014CFA0
    /* 4CF6C 0014CF6C 00000000 */   nop
  .L0014CF70:
    /* 4CF70 0014CF70 0300C414 */  bne        $6, $4, .L0014CF80
    /* 4CF74 0014CF74 00000000 */   nop
    /* 4CF78 0014CF78 0900B010 */  beq        $5, $16, .L0014CFA0
    /* 4CF7C 0014CF7C 00000000 */   nop
  .L0014CF80:
    /* 4CF80 0014CF80 0300D114 */  bne        $6, $17, .L0014CF90
    /* 4CF84 0014CF84 00000000 */   nop
    /* 4CF88 0014CF88 0500A310 */  beq        $5, $3, .L0014CFA0
    /* 4CF8C 0014CF8C 00000000 */   nop
  .L0014CF90:
    /* 4CF90 0014CF90 0500C414 */  bne        $6, $4, .L0014CFA8
    /* 4CF94 0014CF94 00000000 */   nop
    /* 4CF98 0014CF98 0300A314 */  bne        $5, $3, .L0014CFA8
    /* 4CF9C 0014CF9C 00000000 */   nop
  .L0014CFA0:
    /* 4CFA0 0014CFA0 05000010 */  b          .L0014CFB8
    /* 4CFA4 0014CFA4 00000000 */   nop
  .L0014CFA8:
    /* 4CFA8 0014CFA8 3801428C */  lw         $2, 0x138($2)
  .L0014CFAC:
    /* 4CFAC 0014CFAC E1FF4014 */  bnez       $2, .L0014CF34
    /* 4CFB0 0014CFB0 00000000 */   nop
    /* 4CFB4 0014CFB4 2D100000 */  daddu      $2, $0, $0
  .L0014CFB8:
    /* 4CFB8 0014CFB8 2000BFDF */  ld         $31, 0x20($29)
    /* 4CFBC 0014CFBC 1000B17B */  lq         $17, 0x10($29)
    /* 4CFC0 0014CFC0 0000B07B */  lq         $16, 0x0($29)
    /* 4CFC4 0014CFC4 3000BD27 */  addiu      $29, $29, 0x30
    /* 4CFC8 0014CFC8 0800E003 */  jr         $31
    /* 4CFCC 0014CFCC 00000000 */   nop
.size func_0014cef0, 0xe0
