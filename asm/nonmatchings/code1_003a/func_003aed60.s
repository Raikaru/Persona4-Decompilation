.section .text
.set noat
.set noreorder
glabel func_003aed60
    /* 2AED60 003AED60 00FFBD27 */  addiu      $29, $29, -0x100
    /* 2AED64 003AED64 9000BFFF */  sd         $31, 0x90($29)
    /* 2AED68 003AED68 8000BE7F */  sq         $30, 0x80($29)
    /* 2AED6C 003AED6C 7000B77F */  sq         $23, 0x70($29)
    /* 2AED70 003AED70 6000B67F */  sq         $22, 0x60($29)
    /* 2AED74 003AED74 5000B57F */  sq         $21, 0x50($29)
    /* 2AED78 003AED78 2DB00001 */  daddu      $22, $8, $0
    /* 2AED7C 003AED7C 4000B47F */  sq         $20, 0x40($29)
    /* 2AED80 003AED80 2DA8A000 */  daddu      $21, $5, $0
    /* 2AED84 003AED84 3000B37F */  sq         $19, 0x30($29)
    /* 2AED88 003AED88 2DA0C000 */  daddu      $20, $6, $0
    /* 2AED8C 003AED8C 2000B27F */  sq         $18, 0x20($29)
    /* 2AED90 003AED90 2D98E000 */  daddu      $19, $7, $0
    /* 2AED94 003AED94 1000B17F */  sq         $17, 0x10($29)
    /* 2AED98 003AED98 0000B07F */  sq         $16, 0x0($29)
    /* 2AED9C 003AED9C 0400828C */  lw         $2, 0x4($4)
    /* 2AEDA0 003AEDA0 0800178D */  lw         $23, 0x8($8)
    /* 2AEDA4 003AEDA4 0400128D */  lw         $18, 0x4($8)
    /* 2AEDA8 003AEDA8 1C00118D */  lw         $17, 0x1C($8)
    /* 2AEDAC 003AEDAC 20001E8D */  lw         $30, 0x20($8)
    /* 2AEDB0 003AEDB0 0000908C */  lw         $16, 0x0($4)
    /* 2AEDB4 003AEDB4 9902E216 */  bne        $23, $2, .L003AF81C
    /* 2AEDB8 003AEDB8 A000A27F */   sq        $2, 0xA0($29)
    /* 2AEDBC 003AEDBC 9886100C */  jal        func_00421a60
    /* 2AEDC0 003AEDC0 2D200000 */   daddu     $4, $0, $0
    /* 2AEDC4 003AEDC4 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AEDC8 003AEDC8 00D0648C */  lw         $4, -0x3000($3)
    /* 2AEDCC 003AEDCC 00018430 */  andi       $4, $4, 0x100
    /* 2AEDD0 003AEDD0 0C008010 */  beqz       $4, .L003AEE04
    /* 2AEDD4 003AEDD4 00000000 */   nop
    /* 2AEDD8 003AEDD8 00010424 */  addiu      $4, $0, 0x100
    /* 2AEDDC 003AEDDC 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2AEDE0 003AEDE0 0F000000 */  sync
    /* 2AEDE4 003AEDE4 0F040000 */  sync.p
  .L003AEDE8:
    /* 2AEDE8 003AEDE8 00000000 */  nop
    /* 2AEDEC 003AEDEC 00000000 */  nop
    /* 2AEDF0 003AEDF0 00000000 */  nop
    /* 2AEDF4 003AEDF4 00000000 */  nop
    /* 2AEDF8 003AEDF8 00000000 */  nop
    /* 2AEDFC 003AEDFC FAFF0041 */  bc0f       .L003AEDE8 /* handwritten instruction */
    /* 2AEE00 003AEE00 00000000 */   nop
  .L003AEE04:
    /* 2AEE04 003AEE04 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AEE08 003AEE08 00D4648C */  lw         $4, -0x2C00($3)
    /* 2AEE0C 003AEE0C 00018430 */  andi       $4, $4, 0x100
    /* 2AEE10 003AEE10 15008010 */  beqz       $4, .L003AEE68
    /* 2AEE14 003AEE14 00000000 */   nop
    /* 2AEE18 003AEE18 00020424 */  addiu      $4, $0, 0x200
    /* 2AEE1C 003AEE1C 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2AEE20 003AEE20 0F000000 */  sync
    /* 2AEE24 003AEE24 0F040000 */  sync.p
  .L003AEE28:
    /* 2AEE28 003AEE28 00000000 */  nop
    /* 2AEE2C 003AEE2C 00000000 */  nop
    /* 2AEE30 003AEE30 00000000 */  nop
    /* 2AEE34 003AEE34 00000000 */  nop
    /* 2AEE38 003AEE38 00000000 */  nop
    /* 2AEE3C 003AEE3C FAFF0041 */  bc0f       .L003AEE28 /* handwritten instruction */
    /* 2AEE40 003AEE40 00000000 */   nop
    /* 2AEE44 003AEE44 0110033C */  lui        $3, (0x10010000 >> 16)
  .L003AEE48:
    /* 2AEE48 003AEE48 00D4648C */  lw         $4, -0x2C00($3)
    /* 2AEE4C 003AEE4C 00018430 */  andi       $4, $4, 0x100
    /* 2AEE50 003AEE50 00000000 */  nop
    /* 2AEE54 003AEE54 00000000 */  nop
    /* 2AEE58 003AEE58 00000000 */  nop
    /* 2AEE5C 003AEE5C FAFF8014 */  bnez       $4, .L003AEE48
    /* 2AEE60 003AEE60 00000000 */   nop
    /* 2AEE64 003AEE64 00000000 */  nop
  .L003AEE68:
    /* 2AEE68 003AEE68 0070063C */  lui        $6, (0x70003F94 >> 16)
    /* 2AEE6C 003AEE6C 0000A2C6 */  lwc1       $f2, 0x0($21)
    /* 2AEE70 003AEE70 503FC734 */  ori        $7, $6, (0x70003F50 & 0xFFFF)
    /* 2AEE74 003AEE74 0400A1C6 */  lwc1       $f1, 0x4($21)
    /* 2AEE78 003AEE78 603FC534 */  ori        $5, $6, (0x70003F60 & 0xFFFF)
    /* 2AEE7C 003AEE7C 0800A0C6 */  lwc1       $f0, 0x8($21)
    /* 2AEE80 003AEE80 903FC434 */  ori        $4, $6, (0x70003F90 & 0xFFFF)
    /* 2AEE84 003AEE84 0100033C */  lui        $3, (0x10000 >> 16)
    /* 2AEE88 003AEE88 0000E2E4 */  swc1       $f2, 0x0($7)
    /* 2AEE8C 003AEE8C 0400E1E4 */  swc1       $f1, 0x4($7)
    /* 2AEE90 003AEE90 0800E0E4 */  swc1       $f0, 0x8($7)
    /* 2AEE94 003AEE94 000082C6 */  lwc1       $f2, 0x0($20)
    /* 2AEE98 003AEE98 040081C6 */  lwc1       $f1, 0x4($20)
    /* 2AEE9C 003AEE9C 080080C6 */  lwc1       $f0, 0x8($20)
    /* 2AEEA0 003AEEA0 0000A2E4 */  swc1       $f2, 0x0($5)
    /* 2AEEA4 003AEEA4 0400A1E4 */  swc1       $f1, 0x4($5)
    /* 2AEEA8 003AEEA8 0800A0E4 */  swc1       $f0, 0x8($5)
    /* 2AEEAC 003AEEAC 6800C0C6 */  lwc1       $f0, 0x68($22)
    /* 2AEEB0 003AEEB0 903FC0E4 */  swc1       $f0, (0x70003F90 & 0xFFFF)($6)
    /* 2AEEB4 003AEEB4 6C00C0C6 */  lwc1       $f0, 0x6C($22)
    /* 2AEEB8 003AEEB8 943FC0E4 */  swc1       $f0, (0x70003F94 & 0xFFFF)($6)
  .L003AEEBC:
    /* 2AEEBC 003AEEBC 39000042 */  di /* handwritten instruction */
    /* 2AEEC0 003AEEC0 0F040000 */  sync.p
    /* 2AEEC4 003AEEC4 00600640 */  mfc0       $6, $12 /* handwritten instruction */
    /* 2AEEC8 003AEEC8 2430C300 */  and        $6, $6, $3
    /* 2AEECC 003AEECC 00000000 */  nop
    /* 2AEED0 003AEED0 FAFFC014 */  bnez       $6, .L003AEEBC
    /* 2AEED4 003AEED4 00000000 */   nop
    /* 2AEED8 003AEED8 003F033C */  lui        $3, (0x3F000000 >> 16)
    /* 2AEEDC 003AEEDC 00008344 */  mtc1       $3, $f0
    /* 2AEEE0 003AEEE0 00000344 */  mfc1       $3, $f0
    /* 2AEEE4 003AEEE4 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2AEEE8 003AEEE8 FF02004A */  vnop
    /* 2AEEEC 003AEEEC FF02004A */  vnop
    /* 2AEEF0 003AEEF0 0000E1D8 */  lqc2       $vf1, 0x0($7)
    /* 2AEEF4 003AEEF4 0000A2D8 */  lqc2       $vf2, 0x0($5)
    /* 2AEEF8 003AEEF8 000083D8 */  lqc2       $vf3, 0x0($4)
    /* 2AEEFC 003AEEFC BC09E34B */  vmulax.xyzw $ACC, $vf1, $vf3x
    /* 2AEF00 003AEF00 BD10E34B */  vmadday.xyzw $ACC, $vf2, $vf3y
    /* 2AEF04 003AEF04 6905E04B */  vmadd.xyzw $vf21, $vf0, $vf0
    /* 2AEF08 003AEF08 5E08E04B */  vmuli.xyzw $vf1, $vf1, $I
    /* 2AEF0C 003AEF0C 9E10E04B */  vmuli.xyzw $vf2, $vf2, $I
    /* 2AEF10 003AEF10 38000042 */  ei /* handwritten instruction */
    /* 2AEF14 003AEF14 B800632A */  slti       $3, $19, 0xB8
    /* 2AEF18 003AEF18 FB006014 */  bnez       $3, .L003AF308
    /* 2AEF1C 003AEF1C 00000000 */   nop
    /* 2AEF20 003AEF20 00700E3C */  lui        $14, (0x70001140 >> 16)
    /* 2AEF24 003AEF24 0110073C */  lui        $7, (0x10010000 >> 16)
    /* 2AEF28 003AEF28 01000B3C */  lui        $11, (0x10000 >> 16)
    /* 2AEF2C 003AEF2C 00011824 */  addiu      $24, $0, 0x100
    /* 2AEF30 003AEF30 00021624 */  addiu      $22, $0, 0x200
    /* 2AEF34 003AEF34 5C001524 */  addiu      $21, $0, 0x5C
    /* 2AEF38 003AEF38 C0051424 */  addiu      $20, $0, 0x5C0
    /* 2AEF3C 003AEF3C B8000F24 */  addiu      $15, $0, 0xB8
    /* 2AEF40 003AEF40 C005CD35 */  ori        $13, $14, (0x700005C0 & 0xFFFF)
    /* 2AEF44 003AEF44 4011CC35 */  ori        $12, $14, (0x70001140 & 0xFFFF)
    /* 2AEF48 003AEF48 40110924 */  addiu      $9, $0, 0x1140
    /* 2AEF4C 003AEF4C E0020824 */  addiu      $8, $0, 0x2E0
  .L003AEF50:
    /* 2AEF50 003AEF50 00D0E38C */  lw         $3, -0x3000($7)
    /* 2AEF54 003AEF54 00016330 */  andi       $3, $3, 0x100
    /* 2AEF58 003AEF58 0D006010 */  beqz       $3, .L003AEF90
    /* 2AEF5C 003AEF5C 00000000 */   nop
    /* 2AEF60 003AEF60 20E0F8AC */  sw         $24, -0x1FE0($7)
    /* 2AEF64 003AEF64 0F000000 */  sync
    /* 2AEF68 003AEF68 0F040000 */  sync.p
    /* 2AEF6C 003AEF6C 00000000 */  nop
  .L003AEF70:
    /* 2AEF70 003AEF70 00000000 */  nop
    /* 2AEF74 003AEF74 00000000 */  nop
    /* 2AEF78 003AEF78 00000000 */  nop
    /* 2AEF7C 003AEF7C 00000000 */  nop
    /* 2AEF80 003AEF80 00000000 */  nop
    /* 2AEF84 003AEF84 FAFF0041 */  bc0f       .L003AEF70 /* handwritten instruction */
    /* 2AEF88 003AEF88 00000000 */   nop
    /* 2AEF8C 003AEF8C 00000000 */  nop
  .L003AEF90:
    /* 2AEF90 003AEF90 00D4E38C */  lw         $3, -0x2C00($7)
    /* 2AEF94 003AEF94 00016330 */  andi       $3, $3, 0x100
    /* 2AEF98 003AEF98 15006010 */  beqz       $3, .L003AEFF0
    /* 2AEF9C 003AEF9C 00000000 */   nop
    /* 2AEFA0 003AEFA0 20E0F6AC */  sw         $22, -0x1FE0($7)
    /* 2AEFA4 003AEFA4 0F000000 */  sync
    /* 2AEFA8 003AEFA8 0F040000 */  sync.p
    /* 2AEFAC 003AEFAC 00000000 */  nop
  .L003AEFB0:
    /* 2AEFB0 003AEFB0 00000000 */  nop
    /* 2AEFB4 003AEFB4 00000000 */  nop
    /* 2AEFB8 003AEFB8 00000000 */  nop
    /* 2AEFBC 003AEFBC 00000000 */  nop
    /* 2AEFC0 003AEFC0 00000000 */  nop
    /* 2AEFC4 003AEFC4 FAFF0041 */  bc0f       .L003AEFB0 /* handwritten instruction */
    /* 2AEFC8 003AEFC8 00000000 */   nop
    /* 2AEFCC 003AEFCC 00000000 */  nop
  .L003AEFD0:
    /* 2AEFD0 003AEFD0 00D4E38C */  lw         $3, -0x2C00($7)
    /* 2AEFD4 003AEFD4 00016330 */  andi       $3, $3, 0x100
    /* 2AEFD8 003AEFD8 00000000 */  nop
    /* 2AEFDC 003AEFDC 00000000 */  nop
    /* 2AEFE0 003AEFE0 00000000 */  nop
    /* 2AEFE4 003AEFE4 FAFF6014 */  bnez       $3, .L003AEFD0
    /* 2AEFE8 003AEFE8 00000000 */   nop
    /* 2AEFEC 003AEFEC 00000000 */  nop
  .L003AEFF0:
    /* 2AEFF0 003AEFF0 10E0F6AC */  sw         $22, -0x1FF0($7)
    /* 2AEFF4 003AEFF4 80D4E0AC */  sw         $0, -0x2B80($7)
    /* 2AEFF8 003AEFF8 10D4F1AC */  sw         $17, -0x2BF0($7)
    /* 2AEFFC 003AEFFC 20D4F5AC */  sw         $21, -0x2BE0($7)
    /* 2AF000 003AF000 00D4F8AC */  sw         $24, -0x2C00($7)
    /* 2AF004 003AF004 0F000000 */  sync
    /* 2AF008 003AF008 0F040000 */  sync.p
    /* 2AF00C 003AF00C 00D4E38C */  lw         $3, -0x2C00($7)
    /* 2AF010 003AF010 00016330 */  andi       $3, $3, 0x100
    /* 2AF014 003AF014 14006010 */  beqz       $3, .L003AF068
    /* 2AF018 003AF018 00000000 */   nop
    /* 2AF01C 003AF01C 20E0F6AC */  sw         $22, -0x1FE0($7)
    /* 2AF020 003AF020 0F000000 */  sync
    /* 2AF024 003AF024 0F040000 */  sync.p
  .L003AF028:
    /* 2AF028 003AF028 00000000 */  nop
    /* 2AF02C 003AF02C 00000000 */  nop
    /* 2AF030 003AF030 00000000 */  nop
    /* 2AF034 003AF034 00000000 */  nop
    /* 2AF038 003AF038 00000000 */  nop
    /* 2AF03C 003AF03C FAFF0041 */  bc0f       .L003AF028 /* handwritten instruction */
    /* 2AF040 003AF040 00000000 */   nop
    /* 2AF044 003AF044 00000000 */  nop
  .L003AF048:
    /* 2AF048 003AF048 00D4E38C */  lw         $3, -0x2C00($7)
    /* 2AF04C 003AF04C 00016330 */  andi       $3, $3, 0x100
    /* 2AF050 003AF050 00000000 */  nop
    /* 2AF054 003AF054 00000000 */  nop
    /* 2AF058 003AF058 00000000 */  nop
    /* 2AF05C 003AF05C FAFF6014 */  bnez       $3, .L003AF048
    /* 2AF060 003AF060 00000000 */   nop
    /* 2AF064 003AF064 00000000 */  nop
  .L003AF068:
    /* 2AF068 003AF068 10E0F6AC */  sw         $22, -0x1FF0($7)
    /* 2AF06C 003AF06C 80D4F4AC */  sw         $20, -0x2B80($7)
    /* 2AF070 003AF070 10D4F2AC */  sw         $18, -0x2BF0($7)
    /* 2AF074 003AF074 20D4EFAC */  sw         $15, -0x2BE0($7)
    /* 2AF078 003AF078 00D4F8AC */  sw         $24, -0x2C00($7)
    /* 2AF07C 003AF07C 0F000000 */  sync
    /* 2AF080 003AF080 0F040000 */  sync.p
    /* 2AF084 003AF084 00D4E38C */  lw         $3, -0x2C00($7)
    /* 2AF088 003AF088 00016330 */  andi       $3, $3, 0x100
    /* 2AF08C 003AF08C 14006010 */  beqz       $3, .L003AF0E0
    /* 2AF090 003AF090 00000000 */   nop
    /* 2AF094 003AF094 20E0F6AC */  sw         $22, -0x1FE0($7)
    /* 2AF098 003AF098 0F000000 */  sync
    /* 2AF09C 003AF09C 0F040000 */  sync.p
  .L003AF0A0:
    /* 2AF0A0 003AF0A0 00000000 */  nop
    /* 2AF0A4 003AF0A4 00000000 */  nop
    /* 2AF0A8 003AF0A8 00000000 */  nop
    /* 2AF0AC 003AF0AC 00000000 */  nop
    /* 2AF0B0 003AF0B0 00000000 */  nop
    /* 2AF0B4 003AF0B4 FAFF0041 */  bc0f       .L003AF0A0 /* handwritten instruction */
    /* 2AF0B8 003AF0B8 00000000 */   nop
    /* 2AF0BC 003AF0BC 00000000 */  nop
  .L003AF0C0:
    /* 2AF0C0 003AF0C0 00D4E38C */  lw         $3, -0x2C00($7)
    /* 2AF0C4 003AF0C4 00016330 */  andi       $3, $3, 0x100
    /* 2AF0C8 003AF0C8 00000000 */  nop
    /* 2AF0CC 003AF0CC 00000000 */  nop
    /* 2AF0D0 003AF0D0 00000000 */  nop
    /* 2AF0D4 003AF0D4 FAFF6014 */  bnez       $3, .L003AF0C0
    /* 2AF0D8 003AF0D8 00000000 */   nop
    /* 2AF0DC 003AF0DC 00000000 */  nop
  .L003AF0E0:
    /* 2AF0E0 003AF0E0 2D28C001 */  daddu      $5, $14, $0
    /* 2AF0E4 003AF0E4 2D20A001 */  daddu      $4, $13, $0
    /* 2AF0E8 003AF0E8 2D188001 */  daddu      $3, $12, $0
    /* 2AF0EC 003AF0EC 2D300000 */  daddu      $6, $0, $0
  .L003AF0F0:
    /* 2AF0F0 003AF0F0 39000042 */  di /* handwritten instruction */
    /* 2AF0F4 003AF0F4 0F040000 */  sync.p
    /* 2AF0F8 003AF0F8 00600A40 */  mfc0       $10, $12 /* handwritten instruction */
    /* 2AF0FC 003AF0FC 24504B01 */  and        $10, $10, $11
    /* 2AF100 003AF100 00000000 */  nop
    /* 2AF104 003AF104 FAFF4015 */  bnez       $10, .L003AF0F0
    /* 2AF108 003AF108 00000000 */   nop
    /* 2AF10C 003AF10C 0000A3D8 */  lqc2       $vf3, (0x70000000 & 0xFFFF)($5)
    /* 2AF110 003AF110 1809C34B */  vmulx.xyz  $vf4, $vf1, $vf3x
    /* 2AF114 003AF114 5911C34B */  vmuly.xyz  $vf5, $vf2, $vf3y
    /* 2AF118 003AF118 DA0AC34B */  vmulz.xyz  $vf11, $vf1, $vf3z
    /* 2AF11C 003AF11C 1B13C34B */  vmulw.xyz  $vf12, $vf2, $vf3w
    /* 2AF120 003AF120 000086D8 */  lqc2       $vf6, 0x0($4)
    /* 2AF124 003AF124 A831F54B */  vadd.xyzw  $vf6, $vf6, $vf21
    /* 2AF128 003AF128 10008DD8 */  lqc2       $vf13, 0x10($4)
    /* 2AF12C 003AF12C 686BF54B */  vadd.xyzw  $vf13, $vf13, $vf21
    /* 2AF130 003AF130 200094D8 */  lqc2       $vf20, 0x20($4)
    /* 2AF134 003AF134 28A5F54B */  vadd.xyzw  $vf20, $vf20, $vf21
    /* 2AF138 003AF138 1000A3D8 */  lqc2       $vf3, (0x70000010 & 0xFFFF)($5)
    /* 2AF13C 003AF13C 30009BD8 */  lqc2       $vf27, 0x30($4)
    /* 2AF140 003AF140 E8DEF54B */  vadd.xyzw  $vf27, $vf27, $vf21
    /* 2AF144 003AF144 980CC34B */  vmulx.xyz  $vf18, $vf1, $vf3x
    /* 2AF148 003AF148 D914C34B */  vmuly.xyz  $vf19, $vf2, $vf3y
    /* 2AF14C 003AF14C 5A0EC34B */  vmulz.xyz  $vf25, $vf1, $vf3z
    /* 2AF150 003AF150 9B16C34B */  vmulw.xyz  $vf26, $vf2, $vf3w
    /* 2AF154 003AF154 EC31C44B */  vsub.xyz   $vf7, $vf6, $vf4
    /* 2AF158 003AF158 2832C44B */  vadd.xyz   $vf8, $vf6, $vf4
    /* 2AF15C 003AF15C 6832C44B */  vadd.xyz   $vf9, $vf6, $vf4
    /* 2AF160 003AF160 AC32C44B */  vsub.xyz   $vf10, $vf6, $vf4
    /* 2AF164 003AF164 EC39C54B */  vsub.xyz   $vf7, $vf7, $vf5
    /* 2AF168 003AF168 2C42C54B */  vsub.xyz   $vf8, $vf8, $vf5
    /* 2AF16C 003AF16C 684AC54B */  vadd.xyz   $vf9, $vf9, $vf5
    /* 2AF170 003AF170 A852C54B */  vadd.xyz   $vf10, $vf10, $vf5
    /* 2AF174 003AF174 AC6BCB4B */  vsub.xyz   $vf14, $vf13, $vf11
    /* 2AF178 003AF178 E86BCB4B */  vadd.xyz   $vf15, $vf13, $vf11
    /* 2AF17C 003AF17C 286CCB4B */  vadd.xyz   $vf16, $vf13, $vf11
    /* 2AF180 003AF180 6C6CCB4B */  vsub.xyz   $vf17, $vf13, $vf11
    /* 2AF184 003AF184 AC73CC4B */  vsub.xyz   $vf14, $vf14, $vf12
    /* 2AF188 003AF188 EC7BCC4B */  vsub.xyz   $vf15, $vf15, $vf12
    /* 2AF18C 003AF18C 2884CC4B */  vadd.xyz   $vf16, $vf16, $vf12
    /* 2AF190 003AF190 688CCC4B */  vadd.xyz   $vf17, $vf17, $vf12
    /* 2AF194 003AF194 000067F8 */  sqc2       $vf7, 0x0($3)
    /* 2AF198 003AF198 100068F8 */  sqc2       $vf8, 0x10($3)
    /* 2AF19C 003AF19C 200069F8 */  sqc2       $vf9, 0x20($3)
    /* 2AF1A0 003AF1A0 30006AF8 */  sqc2       $vf10, 0x30($3)
    /* 2AF1A4 003AF1A4 40006EF8 */  sqc2       $vf14, 0x40($3)
    /* 2AF1A8 003AF1A8 50006FF8 */  sqc2       $vf15, 0x50($3)
    /* 2AF1AC 003AF1AC 600070F8 */  sqc2       $vf16, 0x60($3)
    /* 2AF1B0 003AF1B0 700071F8 */  sqc2       $vf17, 0x70($3)
    /* 2AF1B4 003AF1B4 ECA1D24B */  vsub.xyz   $vf7, $vf20, $vf18
    /* 2AF1B8 003AF1B8 28A2D24B */  vadd.xyz   $vf8, $vf20, $vf18
    /* 2AF1BC 003AF1BC 68A2D24B */  vadd.xyz   $vf9, $vf20, $vf18
    /* 2AF1C0 003AF1C0 ACA2D24B */  vsub.xyz   $vf10, $vf20, $vf18
    /* 2AF1C4 003AF1C4 EC39D34B */  vsub.xyz   $vf7, $vf7, $vf19
    /* 2AF1C8 003AF1C8 2C42D34B */  vsub.xyz   $vf8, $vf8, $vf19
    /* 2AF1CC 003AF1CC 684AD34B */  vadd.xyz   $vf9, $vf9, $vf19
    /* 2AF1D0 003AF1D0 A852D34B */  vadd.xyz   $vf10, $vf10, $vf19
    /* 2AF1D4 003AF1D4 ACDBD94B */  vsub.xyz   $vf14, $vf27, $vf25
    /* 2AF1D8 003AF1D8 E8DBD94B */  vadd.xyz   $vf15, $vf27, $vf25
    /* 2AF1DC 003AF1DC 28DCD94B */  vadd.xyz   $vf16, $vf27, $vf25
    /* 2AF1E0 003AF1E0 6CDCD94B */  vsub.xyz   $vf17, $vf27, $vf25
    /* 2AF1E4 003AF1E4 AC73DA4B */  vsub.xyz   $vf14, $vf14, $vf26
    /* 2AF1E8 003AF1E8 EC7BDA4B */  vsub.xyz   $vf15, $vf15, $vf26
    /* 2AF1EC 003AF1EC 2884DA4B */  vadd.xyz   $vf16, $vf16, $vf26
    /* 2AF1F0 003AF1F0 688CDA4B */  vadd.xyz   $vf17, $vf17, $vf26
    /* 2AF1F4 003AF1F4 800067F8 */  sqc2       $vf7, 0x80($3)
    /* 2AF1F8 003AF1F8 900068F8 */  sqc2       $vf8, 0x90($3)
    /* 2AF1FC 003AF1FC A00069F8 */  sqc2       $vf9, 0xA0($3)
    /* 2AF200 003AF200 B0006AF8 */  sqc2       $vf10, 0xB0($3)
    /* 2AF204 003AF204 C0006EF8 */  sqc2       $vf14, 0xC0($3)
    /* 2AF208 003AF208 D0006FF8 */  sqc2       $vf15, 0xD0($3)
    /* 2AF20C 003AF20C E00070F8 */  sqc2       $vf16, 0xE0($3)
    /* 2AF210 003AF210 F00071F8 */  sqc2       $vf17, 0xF0($3)
    /* 2AF214 003AF214 38000042 */  ei /* handwritten instruction */
    /* 2AF218 003AF218 0400C624 */  addiu      $6, $6, 0x4
    /* 2AF21C 003AF21C B800CA28 */  slti       $10, $6, 0xB8
    /* 2AF220 003AF220 2000A524 */  addiu      $5, $5, %lo(D_70000020)
    /* 2AF224 003AF224 00016324 */  addiu      $3, $3, 0x100
    /* 2AF228 003AF228 B1FF4015 */  bnez       $10, .L003AF0F0
    /* 2AF22C 003AF22C 40008424 */   addiu     $4, $4, 0x40
    /* 2AF230 003AF230 00D0E38C */  lw         $3, -0x3000($7)
    /* 2AF234 003AF234 00016330 */  andi       $3, $3, 0x100
    /* 2AF238 003AF238 0D006010 */  beqz       $3, .L003AF270
    /* 2AF23C 003AF23C 00000000 */   nop
    /* 2AF240 003AF240 20E0F8AC */  sw         $24, -0x1FE0($7)
    /* 2AF244 003AF244 0F000000 */  sync
    /* 2AF248 003AF248 0F040000 */  sync.p
    /* 2AF24C 003AF24C 00000000 */  nop
  .L003AF250:
    /* 2AF250 003AF250 00000000 */  nop
    /* 2AF254 003AF254 00000000 */  nop
    /* 2AF258 003AF258 00000000 */  nop
    /* 2AF25C 003AF25C 00000000 */  nop
    /* 2AF260 003AF260 00000000 */  nop
    /* 2AF264 003AF264 FAFF0041 */  bc0f       .L003AF250 /* handwritten instruction */
    /* 2AF268 003AF268 00000000 */   nop
    /* 2AF26C 003AF26C 00000000 */  nop
  .L003AF270:
    /* 2AF270 003AF270 00D4E38C */  lw         $3, -0x2C00($7)
    /* 2AF274 003AF274 00016330 */  andi       $3, $3, 0x100
    /* 2AF278 003AF278 15006010 */  beqz       $3, .L003AF2D0
    /* 2AF27C 003AF27C 00000000 */   nop
    /* 2AF280 003AF280 20E0F6AC */  sw         $22, -0x1FE0($7)
    /* 2AF284 003AF284 0F000000 */  sync
    /* 2AF288 003AF288 0F040000 */  sync.p
    /* 2AF28C 003AF28C 00000000 */  nop
  .L003AF290:
    /* 2AF290 003AF290 00000000 */  nop
    /* 2AF294 003AF294 00000000 */  nop
    /* 2AF298 003AF298 00000000 */  nop
    /* 2AF29C 003AF29C 00000000 */  nop
    /* 2AF2A0 003AF2A0 00000000 */  nop
    /* 2AF2A4 003AF2A4 FAFF0041 */  bc0f       .L003AF290 /* handwritten instruction */
    /* 2AF2A8 003AF2A8 00000000 */   nop
    /* 2AF2AC 003AF2AC 00000000 */  nop
  .L003AF2B0:
    /* 2AF2B0 003AF2B0 00D4E38C */  lw         $3, -0x2C00($7)
    /* 2AF2B4 003AF2B4 00016330 */  andi       $3, $3, 0x100
    /* 2AF2B8 003AF2B8 00000000 */  nop
    /* 2AF2BC 003AF2BC 00000000 */  nop
    /* 2AF2C0 003AF2C0 00000000 */  nop
    /* 2AF2C4 003AF2C4 FAFF6014 */  bnez       $3, .L003AF2B0
    /* 2AF2C8 003AF2C8 00000000 */   nop
    /* 2AF2CC 003AF2CC 00000000 */  nop
  .L003AF2D0:
    /* 2AF2D0 003AF2D0 10E0F8AC */  sw         $24, -0x1FF0($7)
    /* 2AF2D4 003AF2D4 80D0E9AC */  sw         $9, -0x2F80($7)
    /* 2AF2D8 003AF2D8 10D0F0AC */  sw         $16, -0x2FF0($7)
    /* 2AF2DC 003AF2DC 20D0E8AC */  sw         $8, -0x2FE0($7)
    /* 2AF2E0 003AF2E0 00D0F8AC */  sw         $24, -0x3000($7)
    /* 2AF2E4 003AF2E4 0F000000 */  sync
    /* 2AF2E8 003AF2E8 0F040000 */  sync.p
    /* 2AF2EC 003AF2EC 48FF7326 */  addiu      $19, $19, -0xB8
    /* 2AF2F0 003AF2F0 800B5226 */  addiu      $18, $18, 0xB80
    /* 2AF2F4 003AF2F4 B800612A */  slti       $1, $19, 0xB8
    /* 2AF2F8 003AF2F8 002E1026 */  addiu      $16, $16, 0x2E00
    /* 2AF2FC 003AF2FC 14FF2010 */  beqz       $1, .L003AEF50
    /* 2AF300 003AF300 C0053126 */   addiu     $17, $17, 0x5C0
    /* 2AF304 003AF304 00000000 */  nop
  .L003AF308:
    /* 2AF308 003AF308 0400612A */  slti       $1, $19, 0x4
    /* 2AF30C 003AF30C 15012014 */  bnez       $1, .L003AF764
    /* 2AF310 003AF310 00000000 */   nop
    /* 2AF314 003AF314 03006106 */  bgez       $19, .L003AF324
    /* 2AF318 003AF318 83181300 */   sra       $3, $19, 2
    /* 2AF31C 003AF31C 03006326 */  addiu      $3, $19, 0x3
    /* 2AF320 003AF320 83180300 */  sra        $3, $3, 2
  .L003AF324:
    /* 2AF324 003AF324 80300300 */  sll        $6, $3, 2
    /* 2AF328 003AF328 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AF32C 003AF32C 00D0648C */  lw         $4, -0x3000($3)
    /* 2AF330 003AF330 00018430 */  andi       $4, $4, 0x100
    /* 2AF334 003AF334 0C008010 */  beqz       $4, .L003AF368
    /* 2AF338 003AF338 00000000 */   nop
    /* 2AF33C 003AF33C 00010424 */  addiu      $4, $0, 0x100
    /* 2AF340 003AF340 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2AF344 003AF344 0F000000 */  sync
    /* 2AF348 003AF348 0F040000 */  sync.p
  .L003AF34C:
    /* 2AF34C 003AF34C 00000000 */  nop
    /* 2AF350 003AF350 00000000 */  nop
    /* 2AF354 003AF354 00000000 */  nop
    /* 2AF358 003AF358 00000000 */  nop
    /* 2AF35C 003AF35C 00000000 */  nop
    /* 2AF360 003AF360 FAFF0041 */  bc0f       .L003AF34C /* handwritten instruction */
    /* 2AF364 003AF364 00000000 */   nop
  .L003AF368:
    /* 2AF368 003AF368 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AF36C 003AF36C 00D4648C */  lw         $4, -0x2C00($3)
    /* 2AF370 003AF370 00018430 */  andi       $4, $4, 0x100
    /* 2AF374 003AF374 14008010 */  beqz       $4, .L003AF3C8
    /* 2AF378 003AF378 00000000 */   nop
    /* 2AF37C 003AF37C 00020424 */  addiu      $4, $0, 0x200
    /* 2AF380 003AF380 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2AF384 003AF384 0F000000 */  sync
    /* 2AF388 003AF388 0F040000 */  sync.p
  .L003AF38C:
    /* 2AF38C 003AF38C 00000000 */  nop
    /* 2AF390 003AF390 00000000 */  nop
    /* 2AF394 003AF394 00000000 */  nop
    /* 2AF398 003AF398 00000000 */  nop
    /* 2AF39C 003AF39C 00000000 */  nop
    /* 2AF3A0 003AF3A0 FAFF0041 */  bc0f       .L003AF38C /* handwritten instruction */
    /* 2AF3A4 003AF3A4 00000000 */   nop
    /* 2AF3A8 003AF3A8 0110033C */  lui        $3, (0x10010000 >> 16)
  .L003AF3AC:
    /* 2AF3AC 003AF3AC 00D4648C */  lw         $4, -0x2C00($3)
    /* 2AF3B0 003AF3B0 00018430 */  andi       $4, $4, 0x100
    /* 2AF3B4 003AF3B4 00000000 */  nop
    /* 2AF3B8 003AF3B8 00000000 */  nop
    /* 2AF3BC 003AF3BC 00000000 */  nop
    /* 2AF3C0 003AF3C0 FAFF8014 */  bnez       $4, .L003AF3AC
    /* 2AF3C4 003AF3C4 00000000 */   nop
  .L003AF3C8:
    /* 2AF3C8 003AF3C8 00020424 */  addiu      $4, $0, 0x200
    /* 2AF3CC 003AF3CC 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AF3D0 003AF3D0 43280600 */  sra        $5, $6, 1
    /* 2AF3D4 003AF3D4 10E064AC */  sw         $4, -0x1FF0($3)
    /* 2AF3D8 003AF3D8 80D460AC */  sw         $0, -0x2B80($3)
    /* 2AF3DC 003AF3DC 0300C104 */  bgez       $6, .L003AF3EC
    /* 2AF3E0 003AF3E0 10D471AC */   sw        $17, -0x2BF0($3)
    /* 2AF3E4 003AF3E4 0100C324 */  addiu      $3, $6, 0x1
    /* 2AF3E8 003AF3E8 43280300 */  sra        $5, $3, 1
  .L003AF3EC:
    /* 2AF3EC 003AF3EC 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AF3F0 003AF3F0 00010424 */  addiu      $4, $0, 0x100
    /* 2AF3F4 003AF3F4 20D465AC */  sw         $5, -0x2BE0($3)
    /* 2AF3F8 003AF3F8 00D464AC */  sw         $4, -0x2C00($3)
    /* 2AF3FC 003AF3FC 0F000000 */  sync
    /* 2AF400 003AF400 0F040000 */  sync.p
    /* 2AF404 003AF404 00D4648C */  lw         $4, -0x2C00($3)
    /* 2AF408 003AF408 00018430 */  andi       $4, $4, 0x100
    /* 2AF40C 003AF40C 14008010 */  beqz       $4, .L003AF460
    /* 2AF410 003AF410 00000000 */   nop
    /* 2AF414 003AF414 00020424 */  addiu      $4, $0, 0x200
    /* 2AF418 003AF418 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2AF41C 003AF41C 0F000000 */  sync
    /* 2AF420 003AF420 0F040000 */  sync.p
  .L003AF424:
    /* 2AF424 003AF424 00000000 */  nop
    /* 2AF428 003AF428 00000000 */  nop
    /* 2AF42C 003AF42C 00000000 */  nop
    /* 2AF430 003AF430 00000000 */  nop
    /* 2AF434 003AF434 00000000 */  nop
    /* 2AF438 003AF438 FAFF0041 */  bc0f       .L003AF424 /* handwritten instruction */
    /* 2AF43C 003AF43C 00000000 */   nop
    /* 2AF440 003AF440 0110033C */  lui        $3, (0x10010000 >> 16)
  .L003AF444:
    /* 2AF444 003AF444 00D4648C */  lw         $4, -0x2C00($3)
    /* 2AF448 003AF448 00018430 */  andi       $4, $4, 0x100
    /* 2AF44C 003AF44C 00000000 */  nop
    /* 2AF450 003AF450 00000000 */  nop
    /* 2AF454 003AF454 00000000 */  nop
    /* 2AF458 003AF458 FAFF8014 */  bnez       $4, .L003AF444
    /* 2AF45C 003AF45C 00000000 */   nop
  .L003AF460:
    /* 2AF460 003AF460 00410500 */  sll        $8, $5, 4
    /* 2AF464 003AF464 00020524 */  addiu      $5, $0, 0x200
    /* 2AF468 003AF468 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AF46C 003AF46C 10E065AC */  sw         $5, -0x1FF0($3)
    /* 2AF470 003AF470 00010424 */  addiu      $4, $0, 0x100
    /* 2AF474 003AF474 80D468AC */  sw         $8, -0x2B80($3)
    /* 2AF478 003AF478 10D472AC */  sw         $18, -0x2BF0($3)
    /* 2AF47C 003AF47C 20D466AC */  sw         $6, -0x2BE0($3)
    /* 2AF480 003AF480 00D464AC */  sw         $4, -0x2C00($3)
    /* 2AF484 003AF484 0F000000 */  sync
    /* 2AF488 003AF488 0F040000 */  sync.p
    /* 2AF48C 003AF48C 00D4648C */  lw         $4, -0x2C00($3)
    /* 2AF490 003AF490 00018430 */  andi       $4, $4, 0x100
    /* 2AF494 003AF494 14008010 */  beqz       $4, .L003AF4E8
    /* 2AF498 003AF498 00000000 */   nop
    /* 2AF49C 003AF49C 20E065AC */  sw         $5, -0x1FE0($3)
    /* 2AF4A0 003AF4A0 0F000000 */  sync
    /* 2AF4A4 003AF4A4 0F040000 */  sync.p
  .L003AF4A8:
    /* 2AF4A8 003AF4A8 00000000 */  nop
    /* 2AF4AC 003AF4AC 00000000 */  nop
    /* 2AF4B0 003AF4B0 00000000 */  nop
    /* 2AF4B4 003AF4B4 00000000 */  nop
    /* 2AF4B8 003AF4B8 00000000 */  nop
    /* 2AF4BC 003AF4BC FAFF0041 */  bc0f       .L003AF4A8 /* handwritten instruction */
    /* 2AF4C0 003AF4C0 00000000 */   nop
    /* 2AF4C4 003AF4C4 0110033C */  lui        $3, (0x10010000 >> 16)
  .L003AF4C8:
    /* 2AF4C8 003AF4C8 00D4648C */  lw         $4, -0x2C00($3)
    /* 2AF4CC 003AF4CC 00018430 */  andi       $4, $4, 0x100
    /* 2AF4D0 003AF4D0 00000000 */  nop
    /* 2AF4D4 003AF4D4 00000000 */  nop
    /* 2AF4D8 003AF4D8 00000000 */  nop
    /* 2AF4DC 003AF4DC FAFF8014 */  bnez       $4, .L003AF4C8
    /* 2AF4E0 003AF4E0 00000000 */   nop
    /* 2AF4E4 003AF4E4 00000000 */  nop
  .L003AF4E8:
    /* 2AF4E8 003AF4E8 0070053C */  lui        $5, (0x70000010 >> 16)
    /* 2AF4EC 003AF4EC 0300C104 */  bgez       $6, .L003AF4FC
    /* 2AF4F0 003AF4F0 43180600 */   sra       $3, $6, 1
    /* 2AF4F4 003AF4F4 0100C324 */  addiu      $3, $6, 0x1
    /* 2AF4F8 003AF4F8 43180300 */  sra        $3, $3, 1
  .L003AF4FC:
    /* 2AF4FC 003AF4FC 2118C300 */  addu       $3, $6, $3
    /* 2AF500 003AF500 0070073C */  lui        $7, (0x700000F0 >> 16)
    /* 2AF504 003AF504 00190300 */  sll        $3, $3, 4
    /* 2AF508 003AF508 2A080600 */  slt        $1, $0, $6
    /* 2AF50C 003AF50C 25200701 */  or         $4, $8, $7
    /* 2AF510 003AF510 25186700 */  or         $3, $3, $7
    /* 2AF514 003AF514 52002010 */  beqz       $1, .L003AF660
    /* 2AF518 003AF518 2D480000 */   daddu     $9, $0, $0
    /* 2AF51C 003AF51C 0100083C */  lui        $8, (0x10000 >> 16)
  .L003AF520:
    /* 2AF520 003AF520 39000042 */  di /* handwritten instruction */
    /* 2AF524 003AF524 0F040000 */  sync.p
    /* 2AF528 003AF528 00600740 */  mfc0       $7, $12 /* handwritten instruction */
    /* 2AF52C 003AF52C 2438E800 */  and        $7, $7, $8
    /* 2AF530 003AF530 00000000 */  nop
    /* 2AF534 003AF534 FAFFE014 */  bnez       $7, .L003AF520
    /* 2AF538 003AF538 00000000 */   nop
    /* 2AF53C 003AF53C 0000A3D8 */  lqc2       $vf3, (0x70000000 & 0xFFFF)($5)
    /* 2AF540 003AF540 1809C34B */  vmulx.xyz  $vf4, $vf1, $vf3x
    /* 2AF544 003AF544 5911C34B */  vmuly.xyz  $vf5, $vf2, $vf3y
    /* 2AF548 003AF548 DA0AC34B */  vmulz.xyz  $vf11, $vf1, $vf3z
    /* 2AF54C 003AF54C 1B13C34B */  vmulw.xyz  $vf12, $vf2, $vf3w
    /* 2AF550 003AF550 000086D8 */  lqc2       $vf6, (0x70000000 & 0xFFFF)($4)
    /* 2AF554 003AF554 A831F54B */  vadd.xyzw  $vf6, $vf6, $vf21
    /* 2AF558 003AF558 10008DD8 */  lqc2       $vf13, (0x70000010 & 0xFFFF)($4)
    /* 2AF55C 003AF55C 686BF54B */  vadd.xyzw  $vf13, $vf13, $vf21
    /* 2AF560 003AF560 200094D8 */  lqc2       $vf20, (0x70000020 & 0xFFFF)($4)
    /* 2AF564 003AF564 28A5F54B */  vadd.xyzw  $vf20, $vf20, $vf21
    /* 2AF568 003AF568 1000A3D8 */  lqc2       $vf3, (0x70000010 & 0xFFFF)($5)
    /* 2AF56C 003AF56C 30009BD8 */  lqc2       $vf27, (0x70000030 & 0xFFFF)($4)
    /* 2AF570 003AF570 E8DEF54B */  vadd.xyzw  $vf27, $vf27, $vf21
    /* 2AF574 003AF574 980CC34B */  vmulx.xyz  $vf18, $vf1, $vf3x
    /* 2AF578 003AF578 D914C34B */  vmuly.xyz  $vf19, $vf2, $vf3y
    /* 2AF57C 003AF57C 5A0EC34B */  vmulz.xyz  $vf25, $vf1, $vf3z
    /* 2AF580 003AF580 9B16C34B */  vmulw.xyz  $vf26, $vf2, $vf3w
    /* 2AF584 003AF584 EC31C44B */  vsub.xyz   $vf7, $vf6, $vf4
    /* 2AF588 003AF588 2832C44B */  vadd.xyz   $vf8, $vf6, $vf4
    /* 2AF58C 003AF58C 6832C44B */  vadd.xyz   $vf9, $vf6, $vf4
    /* 2AF590 003AF590 AC32C44B */  vsub.xyz   $vf10, $vf6, $vf4
    /* 2AF594 003AF594 EC39C54B */  vsub.xyz   $vf7, $vf7, $vf5
    /* 2AF598 003AF598 2C42C54B */  vsub.xyz   $vf8, $vf8, $vf5
    /* 2AF59C 003AF59C 684AC54B */  vadd.xyz   $vf9, $vf9, $vf5
    /* 2AF5A0 003AF5A0 A852C54B */  vadd.xyz   $vf10, $vf10, $vf5
    /* 2AF5A4 003AF5A4 AC6BCB4B */  vsub.xyz   $vf14, $vf13, $vf11
    /* 2AF5A8 003AF5A8 E86BCB4B */  vadd.xyz   $vf15, $vf13, $vf11
    /* 2AF5AC 003AF5AC 286CCB4B */  vadd.xyz   $vf16, $vf13, $vf11
    /* 2AF5B0 003AF5B0 6C6CCB4B */  vsub.xyz   $vf17, $vf13, $vf11
    /* 2AF5B4 003AF5B4 AC73CC4B */  vsub.xyz   $vf14, $vf14, $vf12
    /* 2AF5B8 003AF5B8 EC7BCC4B */  vsub.xyz   $vf15, $vf15, $vf12
    /* 2AF5BC 003AF5BC 2884CC4B */  vadd.xyz   $vf16, $vf16, $vf12
    /* 2AF5C0 003AF5C0 688CCC4B */  vadd.xyz   $vf17, $vf17, $vf12
    /* 2AF5C4 003AF5C4 000067F8 */  sqc2       $vf7, (0x70000000 & 0xFFFF)($3)
    /* 2AF5C8 003AF5C8 100068F8 */  sqc2       $vf8, (0x70000010 & 0xFFFF)($3)
    /* 2AF5CC 003AF5CC 200069F8 */  sqc2       $vf9, (0x70000020 & 0xFFFF)($3)
    /* 2AF5D0 003AF5D0 30006AF8 */  sqc2       $vf10, (0x70000030 & 0xFFFF)($3)
    /* 2AF5D4 003AF5D4 40006EF8 */  sqc2       $vf14, (0x70000040 & 0xFFFF)($3)
    /* 2AF5D8 003AF5D8 50006FF8 */  sqc2       $vf15, (0x70000050 & 0xFFFF)($3)
    /* 2AF5DC 003AF5DC 600070F8 */  sqc2       $vf16, (0x70000060 & 0xFFFF)($3)
    /* 2AF5E0 003AF5E0 700071F8 */  sqc2       $vf17, (0x70000070 & 0xFFFF)($3)
    /* 2AF5E4 003AF5E4 ECA1D24B */  vsub.xyz   $vf7, $vf20, $vf18
    /* 2AF5E8 003AF5E8 28A2D24B */  vadd.xyz   $vf8, $vf20, $vf18
    /* 2AF5EC 003AF5EC 68A2D24B */  vadd.xyz   $vf9, $vf20, $vf18
    /* 2AF5F0 003AF5F0 ACA2D24B */  vsub.xyz   $vf10, $vf20, $vf18
    /* 2AF5F4 003AF5F4 EC39D34B */  vsub.xyz   $vf7, $vf7, $vf19
    /* 2AF5F8 003AF5F8 2C42D34B */  vsub.xyz   $vf8, $vf8, $vf19
    /* 2AF5FC 003AF5FC 684AD34B */  vadd.xyz   $vf9, $vf9, $vf19
    /* 2AF600 003AF600 A852D34B */  vadd.xyz   $vf10, $vf10, $vf19
    /* 2AF604 003AF604 ACDBD94B */  vsub.xyz   $vf14, $vf27, $vf25
    /* 2AF608 003AF608 E8DBD94B */  vadd.xyz   $vf15, $vf27, $vf25
    /* 2AF60C 003AF60C 28DCD94B */  vadd.xyz   $vf16, $vf27, $vf25
    /* 2AF610 003AF610 6CDCD94B */  vsub.xyz   $vf17, $vf27, $vf25
    /* 2AF614 003AF614 AC73DA4B */  vsub.xyz   $vf14, $vf14, $vf26
    /* 2AF618 003AF618 EC7BDA4B */  vsub.xyz   $vf15, $vf15, $vf26
    /* 2AF61C 003AF61C 2884DA4B */  vadd.xyz   $vf16, $vf16, $vf26
    /* 2AF620 003AF620 688CDA4B */  vadd.xyz   $vf17, $vf17, $vf26
    /* 2AF624 003AF624 800067F8 */  sqc2       $vf7, (0x70000080 & 0xFFFF)($3)
    /* 2AF628 003AF628 900068F8 */  sqc2       $vf8, (0x70000090 & 0xFFFF)($3)
    /* 2AF62C 003AF62C A00069F8 */  sqc2       $vf9, (0x700000A0 & 0xFFFF)($3)
    /* 2AF630 003AF630 B0006AF8 */  sqc2       $vf10, (0x700000B0 & 0xFFFF)($3)
    /* 2AF634 003AF634 C0006EF8 */  sqc2       $vf14, (0x700000C0 & 0xFFFF)($3)
    /* 2AF638 003AF638 D0006FF8 */  sqc2       $vf15, (0x700000D0 & 0xFFFF)($3)
    /* 2AF63C 003AF63C E00070F8 */  sqc2       $vf16, (0x700000E0 & 0xFFFF)($3)
    /* 2AF640 003AF640 F00071F8 */  sqc2       $vf17, (0x700000F0 & 0xFFFF)($3)
    /* 2AF644 003AF644 38000042 */  ei /* handwritten instruction */
    /* 2AF648 003AF648 04002925 */  addiu      $9, $9, 0x4
    /* 2AF64C 003AF64C 2A382601 */  slt        $7, $9, $6
    /* 2AF650 003AF650 2000A524 */  addiu      $5, $5, %lo(D_70000020)
    /* 2AF654 003AF654 00016324 */  addiu      $3, $3, %lo(D_70000100)
    /* 2AF658 003AF658 B1FFE014 */  bnez       $7, .L003AF520
    /* 2AF65C 003AF65C 40008424 */   addiu     $4, $4, %lo(D_70000040)
  .L003AF660:
    /* 2AF660 003AF660 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AF664 003AF664 00D0648C */  lw         $4, -0x3000($3)
    /* 2AF668 003AF668 00018430 */  andi       $4, $4, 0x100
    /* 2AF66C 003AF66C 0C008010 */  beqz       $4, .L003AF6A0
    /* 2AF670 003AF670 00000000 */   nop
    /* 2AF674 003AF674 00010424 */  addiu      $4, $0, 0x100
    /* 2AF678 003AF678 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2AF67C 003AF67C 0F000000 */  sync
    /* 2AF680 003AF680 0F040000 */  sync.p
  .L003AF684:
    /* 2AF684 003AF684 00000000 */  nop
    /* 2AF688 003AF688 00000000 */  nop
    /* 2AF68C 003AF68C 00000000 */  nop
    /* 2AF690 003AF690 00000000 */  nop
    /* 2AF694 003AF694 00000000 */  nop
    /* 2AF698 003AF698 FAFF0041 */  bc0f       .L003AF684 /* handwritten instruction */
    /* 2AF69C 003AF69C 00000000 */   nop
  .L003AF6A0:
    /* 2AF6A0 003AF6A0 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AF6A4 003AF6A4 00D4648C */  lw         $4, -0x2C00($3)
    /* 2AF6A8 003AF6A8 00018430 */  andi       $4, $4, 0x100
    /* 2AF6AC 003AF6AC 14008010 */  beqz       $4, .L003AF700
    /* 2AF6B0 003AF6B0 00000000 */   nop
    /* 2AF6B4 003AF6B4 00020424 */  addiu      $4, $0, 0x200
    /* 2AF6B8 003AF6B8 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2AF6BC 003AF6BC 0F000000 */  sync
    /* 2AF6C0 003AF6C0 0F040000 */  sync.p
  .L003AF6C4:
    /* 2AF6C4 003AF6C4 00000000 */  nop
    /* 2AF6C8 003AF6C8 00000000 */  nop
    /* 2AF6CC 003AF6CC 00000000 */  nop
    /* 2AF6D0 003AF6D0 00000000 */  nop
    /* 2AF6D4 003AF6D4 00000000 */  nop
    /* 2AF6D8 003AF6D8 FAFF0041 */  bc0f       .L003AF6C4 /* handwritten instruction */
    /* 2AF6DC 003AF6DC 00000000 */   nop
    /* 2AF6E0 003AF6E0 0110033C */  lui        $3, (0x10010000 >> 16)
  .L003AF6E4:
    /* 2AF6E4 003AF6E4 00D4648C */  lw         $4, -0x2C00($3)
    /* 2AF6E8 003AF6E8 00018430 */  andi       $4, $4, 0x100
    /* 2AF6EC 003AF6EC 00000000 */  nop
    /* 2AF6F0 003AF6F0 00000000 */  nop
    /* 2AF6F4 003AF6F4 00000000 */  nop
    /* 2AF6F8 003AF6F8 FAFF8014 */  bnez       $4, .L003AF6E4
    /* 2AF6FC 003AF6FC 00000000 */   nop
  .L003AF700:
    /* 2AF700 003AF700 00010424 */  addiu      $4, $0, 0x100
    /* 2AF704 003AF704 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AF708 003AF708 43380600 */  sra        $7, $6, 1
    /* 2AF70C 003AF70C 0300C104 */  bgez       $6, .L003AF71C
    /* 2AF710 003AF710 10E064AC */   sw        $4, -0x1FF0($3)
    /* 2AF714 003AF714 0100C324 */  addiu      $3, $6, 0x1
    /* 2AF718 003AF718 43380300 */  sra        $7, $3, 1
  .L003AF71C:
    /* 2AF71C 003AF71C 2120C700 */  addu       $4, $6, $7
    /* 2AF720 003AF720 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AF724 003AF724 00210400 */  sll        $4, $4, 4
    /* 2AF728 003AF728 80280600 */  sll        $5, $6, 2
    /* 2AF72C 003AF72C 80D064AC */  sw         $4, -0x2F80($3)
    /* 2AF730 003AF730 10D070AC */  sw         $16, -0x2FF0($3)
    /* 2AF734 003AF734 00010424 */  addiu      $4, $0, 0x100
    /* 2AF738 003AF738 20D065AC */  sw         $5, -0x2FE0($3)
    /* 2AF73C 003AF73C 00D064AC */  sw         $4, -0x3000($3)
    /* 2AF740 003AF740 0F000000 */  sync
    /* 2AF744 003AF744 0F040000 */  sync.p
    /* 2AF748 003AF748 00190700 */  sll        $3, $7, 4
    /* 2AF74C 003AF74C 00210500 */  sll        $4, $5, 4
    /* 2AF750 003AF750 21882302 */  addu       $17, $17, $3
    /* 2AF754 003AF754 21800402 */  addu       $16, $16, $4
    /* 2AF758 003AF758 00190600 */  sll        $3, $6, 4
    /* 2AF75C 003AF75C 23986602 */  subu       $19, $19, $6
    /* 2AF760 003AF760 21904302 */  addu       $18, $18, $3
  .L003AF764:
    /* 2AF764 003AF764 2A081300 */  slt        $1, $0, $19
    /* 2AF768 003AF768 7D002010 */  beqz       $1, .L003AF960
    /* 2AF76C 003AF76C 2D400000 */   daddu     $8, $0, $0
    /* 2AF770 003AF770 A000A37B */  lq         $3, 0xA0($29)
    /* 2AF774 003AF774 F400A727 */  addiu      $7, $29, 0xF4
    /* 2AF778 003AF778 F000A527 */  addiu      $5, $29, 0xF0
    /* 2AF77C 003AF77C 0100063C */  lui        $6, (0x10000 >> 16)
    /* 2AF780 003AF780 80200300 */  sll        $4, $3, 2
  .L003AF784:
    /* 2AF784 003AF784 000021C6 */  lwc1       $f1, 0x0($17)
    /* 2AF788 003AF788 040020C6 */  lwc1       $f0, 0x4($17)
    /* 2AF78C 003AF78C F000A1E7 */  swc1       $f1, 0xF0($29)
    /* 2AF790 003AF790 0000E0E4 */  swc1       $f0, 0x0($7)
    /* 2AF794 003AF794 00000000 */  nop
  .L003AF798:
    /* 2AF798 003AF798 39000042 */  di /* handwritten instruction */
    /* 2AF79C 003AF79C 0F040000 */  sync.p
    /* 2AF7A0 003AF7A0 00600340 */  mfc0       $3, $12 /* handwritten instruction */
    /* 2AF7A4 003AF7A4 24186600 */  and        $3, $3, $6
    /* 2AF7A8 003AF7A8 00000000 */  nop
    /* 2AF7AC 003AF7AC FAFF6014 */  bnez       $3, .L003AF798
    /* 2AF7B0 003AF7B0 00000000 */   nop
    /* 2AF7B4 003AF7B4 0000A3D8 */  lqc2       $vf3, 0x0($5)
    /* 2AF7B8 003AF7B8 1809C34B */  vmulx.xyz  $vf4, $vf1, $vf3x
    /* 2AF7BC 003AF7BC 5911C34B */  vmuly.xyz  $vf5, $vf2, $vf3y
    /* 2AF7C0 003AF7C0 000046DA */  lqc2       $vf6, 0x0($18)
    /* 2AF7C4 003AF7C4 A831F54B */  vadd.xyzw  $vf6, $vf6, $vf21
    /* 2AF7C8 003AF7C8 EC31C44B */  vsub.xyz   $vf7, $vf6, $vf4
    /* 2AF7CC 003AF7CC 2832C44B */  vadd.xyz   $vf8, $vf6, $vf4
    /* 2AF7D0 003AF7D0 6832C44B */  vadd.xyz   $vf9, $vf6, $vf4
    /* 2AF7D4 003AF7D4 AC32C44B */  vsub.xyz   $vf10, $vf6, $vf4
    /* 2AF7D8 003AF7D8 EC39C54B */  vsub.xyz   $vf7, $vf7, $vf5
    /* 2AF7DC 003AF7DC 2C42C54B */  vsub.xyz   $vf8, $vf8, $vf5
    /* 2AF7E0 003AF7E0 684AC54B */  vadd.xyz   $vf9, $vf9, $vf5
    /* 2AF7E4 003AF7E4 A852C54B */  vadd.xyz   $vf10, $vf10, $vf5
    /* 2AF7E8 003AF7E8 000007FA */  sqc2       $vf7, 0x0($16)
    /* 2AF7EC 003AF7EC 100008FA */  sqc2       $vf8, 0x10($16)
    /* 2AF7F0 003AF7F0 200009FA */  sqc2       $vf9, 0x20($16)
    /* 2AF7F4 003AF7F4 30000AFA */  sqc2       $vf10, 0x30($16)
    /* 2AF7F8 003AF7F8 38000042 */  ei /* handwritten instruction */
    /* 2AF7FC 003AF7FC 01000825 */  addiu      $8, $8, 0x1
    /* 2AF800 003AF800 2A181301 */  slt        $3, $8, $19
    /* 2AF804 003AF804 21883E02 */  addu       $17, $17, $30
    /* 2AF808 003AF808 21800402 */  addu       $16, $16, $4
    /* 2AF80C 003AF80C DDFF6014 */  bnez       $3, .L003AF784
    /* 2AF810 003AF810 21905702 */   addu      $18, $18, $23
    /* 2AF814 003AF814 52000010 */  b          .L003AF960
    /* 2AF818 003AF818 00000000 */   nop
  .L003AF81C:
    /* 2AF81C 003AF81C D000A427 */  addiu      $4, $29, 0xD0
    /* 2AF820 003AF820 04FE100C */  jal        func_0043f810
    /* 2AF824 003AF824 0C000624 */   addiu     $6, $0, 0xC
    /* 2AF828 003AF828 2D288002 */  daddu      $5, $20, $0
    /* 2AF82C 003AF82C C000A427 */  addiu      $4, $29, 0xC0
    /* 2AF830 003AF830 04FE100C */  jal        func_0043f810
    /* 2AF834 003AF834 0C000624 */   addiu     $6, $0, 0xC
    /* 2AF838 003AF838 6800C1C6 */  lwc1       $f1, 0x68($22)
    /* 2AF83C 003AF83C 0100033C */  lui        $3, (0x10000 >> 16)
    /* 2AF840 003AF840 6C00C0C6 */  lwc1       $f0, 0x6C($22)
    /* 2AF844 003AF844 E000A1E7 */  swc1       $f1, 0xE0($29)
    /* 2AF848 003AF848 E400A0E7 */  swc1       $f0, 0xE4($29)
  .L003AF84C:
    /* 2AF84C 003AF84C 39000042 */  di /* handwritten instruction */
    /* 2AF850 003AF850 0F040000 */  sync.p
    /* 2AF854 003AF854 00600440 */  mfc0       $4, $12 /* handwritten instruction */
    /* 2AF858 003AF858 24208300 */  and        $4, $4, $3
    /* 2AF85C 003AF85C 00000000 */  nop
    /* 2AF860 003AF860 FAFF8014 */  bnez       $4, .L003AF84C
    /* 2AF864 003AF864 00000000 */   nop
    /* 2AF868 003AF868 003F033C */  lui        $3, (0x3F000000 >> 16)
    /* 2AF86C 003AF86C D000A627 */  addiu      $6, $29, 0xD0
    /* 2AF870 003AF870 00008344 */  mtc1       $3, $f0
    /* 2AF874 003AF874 C000A527 */  addiu      $5, $29, 0xC0
    /* 2AF878 003AF878 E000A427 */  addiu      $4, $29, 0xE0
    /* 2AF87C 003AF87C 00000344 */  mfc1       $3, $f0
    /* 2AF880 003AF880 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2AF884 003AF884 FF02004A */  vnop
    /* 2AF888 003AF888 FF02004A */  vnop
    /* 2AF88C 003AF88C 0000C1D8 */  lqc2       $vf1, 0x0($6)
    /* 2AF890 003AF890 0000A2D8 */  lqc2       $vf2, 0x0($5)
    /* 2AF894 003AF894 000083D8 */  lqc2       $vf3, 0x0($4)
    /* 2AF898 003AF898 BC09E34B */  vmulax.xyzw $ACC, $vf1, $vf3x
    /* 2AF89C 003AF89C BD10E34B */  vmadday.xyzw $ACC, $vf2, $vf3y
    /* 2AF8A0 003AF8A0 6905E04B */  vmadd.xyzw $vf21, $vf0, $vf0
    /* 2AF8A4 003AF8A4 5E08E04B */  vmuli.xyzw $vf1, $vf1, $I
    /* 2AF8A8 003AF8A8 9E10E04B */  vmuli.xyzw $vf2, $vf2, $I
    /* 2AF8AC 003AF8AC 38000042 */  ei /* handwritten instruction */
    /* 2AF8B0 003AF8B0 2A081300 */  slt        $1, $0, $19
    /* 2AF8B4 003AF8B4 2A002010 */  beqz       $1, .L003AF960
    /* 2AF8B8 003AF8B8 2D400000 */   daddu     $8, $0, $0
    /* 2AF8BC 003AF8BC A000A37B */  lq         $3, 0xA0($29)
    /* 2AF8C0 003AF8C0 B400A727 */  addiu      $7, $29, 0xB4
    /* 2AF8C4 003AF8C4 B000A527 */  addiu      $5, $29, 0xB0
    /* 2AF8C8 003AF8C8 0100063C */  lui        $6, (0x10000 >> 16)
    /* 2AF8CC 003AF8CC 80200300 */  sll        $4, $3, 2
  .L003AF8D0:
    /* 2AF8D0 003AF8D0 000021C6 */  lwc1       $f1, 0x0($17)
    /* 2AF8D4 003AF8D4 040020C6 */  lwc1       $f0, 0x4($17)
    /* 2AF8D8 003AF8D8 B000A1E7 */  swc1       $f1, 0xB0($29)
    /* 2AF8DC 003AF8DC 0000E0E4 */  swc1       $f0, 0x0($7)
  .L003AF8E0:
    /* 2AF8E0 003AF8E0 39000042 */  di /* handwritten instruction */
    /* 2AF8E4 003AF8E4 0F040000 */  sync.p
    /* 2AF8E8 003AF8E8 00600340 */  mfc0       $3, $12 /* handwritten instruction */
    /* 2AF8EC 003AF8EC 24186600 */  and        $3, $3, $6
    /* 2AF8F0 003AF8F0 00000000 */  nop
    /* 2AF8F4 003AF8F4 FAFF6014 */  bnez       $3, .L003AF8E0
    /* 2AF8F8 003AF8F8 00000000 */   nop
    /* 2AF8FC 003AF8FC 0000A3D8 */  lqc2       $vf3, 0x0($5)
    /* 2AF900 003AF900 1809C34B */  vmulx.xyz  $vf4, $vf1, $vf3x
    /* 2AF904 003AF904 5911C34B */  vmuly.xyz  $vf5, $vf2, $vf3y
    /* 2AF908 003AF908 000046DA */  lqc2       $vf6, 0x0($18)
    /* 2AF90C 003AF90C A831F54B */  vadd.xyzw  $vf6, $vf6, $vf21
    /* 2AF910 003AF910 EC31C44B */  vsub.xyz   $vf7, $vf6, $vf4
    /* 2AF914 003AF914 2832C44B */  vadd.xyz   $vf8, $vf6, $vf4
    /* 2AF918 003AF918 6832C44B */  vadd.xyz   $vf9, $vf6, $vf4
    /* 2AF91C 003AF91C AC32C44B */  vsub.xyz   $vf10, $vf6, $vf4
    /* 2AF920 003AF920 EC39C54B */  vsub.xyz   $vf7, $vf7, $vf5
    /* 2AF924 003AF924 2C42C54B */  vsub.xyz   $vf8, $vf8, $vf5
    /* 2AF928 003AF928 684AC54B */  vadd.xyz   $vf9, $vf9, $vf5
    /* 2AF92C 003AF92C A852C54B */  vadd.xyz   $vf10, $vf10, $vf5
    /* 2AF930 003AF930 000007FA */  sqc2       $vf7, 0x0($16)
    /* 2AF934 003AF934 100008FA */  sqc2       $vf8, 0x10($16)
    /* 2AF938 003AF938 200009FA */  sqc2       $vf9, 0x20($16)
    /* 2AF93C 003AF93C 30000AFA */  sqc2       $vf10, 0x30($16)
    /* 2AF940 003AF940 38000042 */  ei /* handwritten instruction */
    /* 2AF944 003AF944 01000825 */  addiu      $8, $8, 0x1
    /* 2AF948 003AF948 2A181301 */  slt        $3, $8, $19
    /* 2AF94C 003AF94C 21883E02 */  addu       $17, $17, $30
    /* 2AF950 003AF950 21800402 */  addu       $16, $16, $4
    /* 2AF954 003AF954 DEFF6014 */  bnez       $3, .L003AF8D0
    /* 2AF958 003AF958 21905702 */   addu      $18, $18, $23
    /* 2AF95C 003AF95C 00000000 */  nop
  .L003AF960:
    /* 2AF960 003AF960 9000BFDF */  ld         $31, 0x90($29)
    /* 2AF964 003AF964 8000BE7B */  lq         $30, 0x80($29)
    /* 2AF968 003AF968 7000B77B */  lq         $23, 0x70($29)
    /* 2AF96C 003AF96C 6000B67B */  lq         $22, 0x60($29)
    /* 2AF970 003AF970 5000B57B */  lq         $21, 0x50($29)
    /* 2AF974 003AF974 4000B47B */  lq         $20, 0x40($29)
    /* 2AF978 003AF978 3000B37B */  lq         $19, 0x30($29)
    /* 2AF97C 003AF97C 2000B27B */  lq         $18, 0x20($29)
    /* 2AF980 003AF980 1000B17B */  lq         $17, 0x10($29)
    /* 2AF984 003AF984 0000B07B */  lq         $16, 0x0($29)
    /* 2AF988 003AF988 0800E003 */  jr         $31
    /* 2AF98C 003AF98C 0001BD27 */   addiu     $29, $29, 0x100
.size func_003aed60, 0xc30
