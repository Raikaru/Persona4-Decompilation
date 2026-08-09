.section .text
.set noat
.set noreorder
glabel func_001ccdb0
    /* CCDB0 001CCDB0 30FFBD27 */  addiu      $29, $29, -0xD0
    /* CCDB4 001CCDB4 3000BFFF */  sd         $31, 0x30($29)
    /* CCDB8 001CCDB8 2000B17F */  sq         $17, 0x20($29)
    /* CCDBC 001CCDBC 1000B07F */  sq         $16, 0x10($29)
    /* CCDC0 001CCDC0 0000B4E7 */  swc1       $f20, 0x0($29)
    /* CCDC4 001CCDC4 2D888000 */  daddu      $17, $4, $0
    /* CCDC8 001CCDC8 E000828C */  lw         $2, 0xE0($4)
    /* CCDCC 001CCDCC 3000508C */  lw         $16, 0x30($2)
    /* CCDD0 001CCDD0 ACB3858F */  lw         $5, -0x4C54($28)
    /* CCDD4 001CCDD4 0C00A38C */  lw         $3, 0xC($5)
    /* CCDD8 001CCDD8 0020023C */  lui        $2, (0x20000000 >> 16)
    /* CCDDC 001CCDDC 24106200 */  and        $2, $3, $2
    /* CCDE0 001CCDE0 69014014 */  bnez       $2, .L001CD388
    /* CCDE4 001CCDE4 00000000 */   nop
    /* CCDE8 001CCDE8 1A00A394 */  lhu        $3, 0x1A($5)
    /* CCDEC 001CCDEC 02000424 */  addiu      $4, $0, 0x2
    /* CCDF0 001CCDF0 8F006410 */  beq        $3, $4, .L001CD030
    /* CCDF4 001CCDF4 00000000 */   nop
    /* CCDF8 001CCDF8 01000224 */  addiu      $2, $0, 0x1
    /* CCDFC 001CCDFC 05006210 */  beq        $3, $2, .L001CCE14
    /* CCE00 001CCE00 00000000 */   nop
    /* CCE04 001CCE04 03006010 */  beqz       $3, .L001CCE14
    /* CCE08 001CCE08 00000000 */   nop
    /* CCE0C 001CCE0C DB010010 */  b          .L001CD57C
    /* CCE10 001CCE10 00000000 */   nop
  .L001CCE14:
    /* CCE14 001CCE14 03000424 */  addiu      $4, $0, 0x3
    /* CCE18 001CCE18 2D280000 */  daddu      $5, $0, $0
    /* CCE1C 001CCE1C 2D300000 */  daddu      $6, $0, $0
    /* CCE20 001CCE20 CC00A727 */  addiu      $7, $29, 0xCC
    /* CCE24 001CCE24 2D400000 */  daddu      $8, $0, $0
    /* CCE28 001CCE28 2D480000 */  daddu      $9, $0, $0
    /* CCE2C 001CCE2C 1058060C */  jal        func_00196040
    /* CCE30 001CCE30 00000000 */   nop
    /* CCE34 001CCE34 06050046 */  mov.s      $f20, $f0
    /* CCE38 001CCE38 02000424 */  addiu      $4, $0, 0x2
    /* CCE3C 001CCE3C 2D280000 */  daddu      $5, $0, $0
    /* CCE40 001CCE40 B000A627 */  addiu      $6, $29, 0xB0
    /* CCE44 001CCE44 2D380000 */  daddu      $7, $0, $0
    /* CCE48 001CCE48 2D400000 */  daddu      $8, $0, $0
    /* CCE4C 001CCE4C 2D480000 */  daddu      $9, $0, $0
    /* CCE50 001CCE50 1058060C */  jal        func_00196040
    /* CCE54 001CCE54 00000000 */   nop
    /* CCE58 001CCE58 803E023C */  lui        $2, (0x3E800000 >> 16)
    /* CCE5C 001CCE5C 00088244 */  mtc1       $2, $f1
    /* CCE60 001CCE60 CC00A0C7 */  lwc1       $f0, 0xCC($29)
    /* CCE64 001CCE64 02080046 */  mul.s      $f0, $f1, $f0
    /* CCE68 001CCE68 B400A0E7 */  swc1       $f0, 0xB4($29)
    /* CCE6C 001CCE6C 2D200002 */  daddu      $4, $16, $0
    /* CCE70 001CCE70 C000A527 */  addiu      $5, $29, 0xC0
    /* CCE74 001CCE74 1456060C */  jal        func_00195850
    /* CCE78 001CCE78 00000000 */   nop
    /* CCE7C 001CCE7C 8C0001C6 */  lwc1       $f1, 0x8C($16)
    /* CCE80 001CCE80 2C0000C6 */  lwc1       $f0, 0x2C($16)
    /* CCE84 001CCE84 C2080046 */  mul.s      $f3, $f1, $f0
    /* CCE88 001CCE88 3C8082C7 */  lwc1       $f2, -0x7FC4($28)
    /* CCE8C 001CCE8C C400A1C7 */  lwc1       $f1, 0xC4($29)
    /* CCE90 001CCE90 00008044 */  mtc1       $0, $f0
    /* CCE94 001CCE94 00000000 */  nop
    /* CCE98 001CCE98 18000146 */  adda.s     $f0, $f1
    /* CCE9C 001CCE9C 1D100346 */  msub.s     $f0, $f2, $f3
    /* CCEA0 001CCEA0 C400A0E7 */  swc1       $f0, 0xC4($29)
    /* CCEA4 001CCEA4 4C00A427 */  addiu      $4, $29, 0x4C
    /* CCEA8 001CCEA8 C000A527 */  addiu      $5, $29, 0xC0
    /* CCEAC 001CCEAC B000A627 */  addiu      $6, $29, 0xB0
    /* CCEB0 001CCEB0 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* CCEB4 001CCEB4 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* CCEB8 001CCEB8 E0F5060C */  jal        func_001bd780
    /* CCEBC 001CCEBC 00000000 */   nop
    /* CCEC0 001CCEC0 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CCEC4 001CCEC4 00088244 */  mtc1       $2, $f1
    /* CCEC8 001CCEC8 B80020C6 */  lwc1       $f0, 0xB8($17)
    /* CCECC 001CCECC 42080046 */  mul.s      $f1, $f1, $f0
    /* CCED0 001CCED0 108180C7 */  lwc1       $f0, -0x7EF0($28)
    /* CCED4 001CCED4 02030146 */  mul.s      $f12, $f0, $f1
    /* CCED8 001CCED8 1A2E110C */  jal        func_0044b868
    /* CCEDC 001CCEDC 00000000 */   nop
    /* CCEE0 001CCEE0 403F023C */  lui        $2, (0x3F400000 >> 16)
    /* CCEE4 001CCEE4 00088244 */  mtc1       $2, $f1
    /* CCEE8 001CCEE8 00000000 */  nop
    /* CCEEC 001CCEEC 42081446 */  mul.s      $f1, $f1, $f20
    /* CCEF0 001CCEF0 030D0046 */  div.s      $f20, $f1, $f0
    /* CCEF4 001CCEF4 ACB3828F */  lw         $2, -0x4C54($28)
    /* CCEF8 001CCEF8 640C4290 */  lbu        $2, 0xC64($2)
    /* CCEFC 001CCEFC 02004128 */  slti       $1, $2, 0x2
    /* CCF00 001CCF00 0B002014 */  bnez       $1, .L001CCF30
    /* CCF04 001CCF04 00000000 */   nop
    /* CCF08 001CCF08 4041023C */  lui        $2, (0x41400000 >> 16)
    /* CCF0C 001CCF0C 00608244 */  mtc1       $2, $f12
    /* CCF10 001CCF10 4C00A427 */  addiu      $4, $29, 0x4C
    /* CCF14 001CCF14 6100053C */  lui        $5, %hi(D_0060A0E0)
    /* CCF18 001CCF18 E0A0A524 */  addiu      $5, $5, %lo(D_0060A0E0)
    /* CCF1C 001CCF1C 02000624 */  addiu      $6, $0, 0x2
    /* CCF20 001CCF20 D0710F0C */  jal        func_003dc740
    /* CCF24 001CCF24 00000000 */   nop
    /* CCF28 001CCF28 09000010 */  b          .L001CCF50
    /* CCF2C 001CCF2C 00000000 */   nop
  .L001CCF30:
    /* CCF30 001CCF30 A040023C */  lui        $2, (0x40A00000 >> 16)
    /* CCF34 001CCF34 00608244 */  mtc1       $2, $f12
    /* CCF38 001CCF38 4C00A427 */  addiu      $4, $29, 0x4C
    /* CCF3C 001CCF3C 6100053C */  lui        $5, %hi(D_0060A0E0)
    /* CCF40 001CCF40 E0A0A524 */  addiu      $5, $5, %lo(D_0060A0E0)
    /* CCF44 001CCF44 02000624 */  addiu      $6, $0, 0x2
    /* CCF48 001CCF48 D0710F0C */  jal        func_003dc740
    /* CCF4C 001CCF4C 00000000 */   nop
  .L001CCF50:
    /* CCF50 001CCF50 A000A427 */  addiu      $4, $29, 0xA0
    /* CCF54 001CCF54 6100053C */  lui        $5, %hi(D_0060A100)
    /* CCF58 001CCF58 00A1A524 */  addiu      $5, $5, %lo(D_0060A100)
    /* CCF5C 001CCF5C 01000624 */  addiu      $6, $0, 0x1
    /* CCF60 001CCF60 4C00A727 */  addiu      $7, $29, 0x4C
    /* CCF64 001CCF64 D0720F0C */  jal        func_003dcb40
    /* CCF68 001CCF68 00000000 */   nop
    /* CCF6C 001CCF6C A000A0C7 */  lwc1       $f0, 0xA0($29)
    /* CCF70 001CCF70 C2001446 */  mul.s      $f3, $f0, $f20
    /* CCF74 001CCF74 A000A3E7 */  swc1       $f3, 0xA0($29)
    /* CCF78 001CCF78 A400A0C7 */  lwc1       $f0, 0xA4($29)
    /* CCF7C 001CCF7C 82001446 */  mul.s      $f2, $f0, $f20
    /* CCF80 001CCF80 A400A2E7 */  swc1       $f2, 0xA4($29)
    /* CCF84 001CCF84 A800A0C7 */  lwc1       $f0, 0xA8($29)
    /* CCF88 001CCF88 42001446 */  mul.s      $f1, $f0, $f20
    /* CCF8C 001CCF8C A800A1E7 */  swc1       $f1, 0xA8($29)
    /* CCF90 001CCF90 B000A0C7 */  lwc1       $f0, 0xB0($29)
    /* CCF94 001CCF94 00000346 */  add.s      $f0, $f0, $f3
    /* CCF98 001CCF98 4000A0E7 */  swc1       $f0, 0x40($29)
    /* CCF9C 001CCF9C B400A0C7 */  lwc1       $f0, 0xB4($29)
    /* CCFA0 001CCFA0 00000246 */  add.s      $f0, $f0, $f2
    /* CCFA4 001CCFA4 4400A0E7 */  swc1       $f0, 0x44($29)
    /* CCFA8 001CCFA8 B800A0C7 */  lwc1       $f0, 0xB8($29)
    /* CCFAC 001CCFAC 00000146 */  add.s      $f0, $f0, $f1
    /* CCFB0 001CCFB0 4800A0E7 */  swc1       $f0, 0x48($29)
    /* CCFB4 001CCFB4 4000A427 */  addiu      $4, $29, 0x40
    /* CCFB8 001CCFB8 2D288000 */  daddu      $5, $4, $0
    /* CCFBC 001CCFBC E8F0060C */  jal        func_001bc3a0
    /* CCFC0 001CCFC0 00000000 */   nop
    /* CCFC4 001CCFC4 4400A1C7 */  lwc1       $f1, 0x44($29)
    /* CCFC8 001CCFC8 C841023C */  lui        $2, (0x41C80000 >> 16)
    /* CCFCC 001CCFCC 00008244 */  mtc1       $2, $f0
    /* CCFD0 001CCFD0 00000000 */  nop
    /* CCFD4 001CCFD4 34080046 */  c.lt.s     $f1, $f0
    /* CCFD8 001CCFD8 02000045 */  bc1f       .L001CCFE4
    /* CCFDC 001CCFDC 00000000 */   nop
    /* CCFE0 001CCFE0 4400A0E7 */  swc1       $f0, 0x44($29)
  .L001CCFE4:
    /* CCFE4 001CCFE4 2D202002 */  daddu      $4, $17, $0
    /* CCFE8 001CCFE8 01000524 */  addiu      $5, $0, 0x1
    /* CCFEC 001CCFEC 2D30A000 */  daddu      $6, $5, $0
    /* CCFF0 001CCFF0 2D380000 */  daddu      $7, $0, $0
    /* CCFF4 001CCFF4 7800A827 */  addiu      $8, $29, 0x78
    /* CCFF8 001CCFF8 D01B070C */  jal        func_001c6f40
    /* CCFFC 001CCFFC 00000000 */   nop
    /* CD000 001CD000 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CD004 001CD004 00608244 */  mtc1       $2, $f12
    /* CD008 001CD008 5C00A427 */  addiu      $4, $29, 0x5C
    /* CD00C 001CD00C 4000A527 */  addiu      $5, $29, 0x40
    /* CD010 001CD010 7800A627 */  addiu      $6, $29, 0x78
    /* CD014 001CD014 E4E9060C */  jal        func_001ba790
    /* CD018 001CD018 00000000 */   nop
    /* CD01C 001CD01C 4400A0C7 */  lwc1       $f0, 0x44($29)
    /* CD020 001CD020 6000A0E7 */  swc1       $f0, 0x60($29)
    /* CD024 001CD024 A08194C7 */  lwc1       $f20, -0x7E60($28)
    /* CD028 001CD028 54010010 */  b          .L001CD57C
    /* CD02C 001CD02C 00000000 */   nop
  .L001CD030:
    /* CD030 001CD030 2D280000 */  daddu      $5, $0, $0
    /* CD034 001CD034 B000A627 */  addiu      $6, $29, 0xB0
    /* CD038 001CD038 CC00A727 */  addiu      $7, $29, 0xCC
    /* CD03C 001CD03C 2D400000 */  daddu      $8, $0, $0
    /* CD040 001CD040 2D480000 */  daddu      $9, $0, $0
    /* CD044 001CD044 1058060C */  jal        func_00196040
    /* CD048 001CD048 00000000 */   nop
    /* CD04C 001CD04C 288181C7 */  lwc1       $f1, -0x7ED8($28)
    /* CD050 001CD050 CC00A0C7 */  lwc1       $f0, 0xCC($29)
    /* CD054 001CD054 02080046 */  mul.s      $f0, $f1, $f0
    /* CD058 001CD058 B400A0E7 */  swc1       $f0, 0xB4($29)
    /* CD05C 001CD05C 2D200002 */  daddu      $4, $16, $0
    /* CD060 001CD060 C000A527 */  addiu      $5, $29, 0xC0
    /* CD064 001CD064 1456060C */  jal        func_00195850
    /* CD068 001CD068 00000000 */   nop
    /* CD06C 001CD06C 8C0001C6 */  lwc1       $f1, 0x8C($16)
    /* CD070 001CD070 2C0000C6 */  lwc1       $f0, 0x2C($16)
    /* CD074 001CD074 42080046 */  mul.s      $f1, $f1, $f0
    /* CD078 001CD078 308080C7 */  lwc1       $f0, -0x7FD0($28)
    /* CD07C 001CD07C 02000146 */  mul.s      $f0, $f0, $f1
    /* CD080 001CD080 C400A0E7 */  swc1       $f0, 0xC4($29)
    /* CD084 001CD084 4C00A427 */  addiu      $4, $29, 0x4C
    /* CD088 001CD088 C000A527 */  addiu      $5, $29, 0xC0
    /* CD08C 001CD08C B000A627 */  addiu      $6, $29, 0xB0
    /* CD090 001CD090 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* CD094 001CD094 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* CD098 001CD098 E0F5060C */  jal        func_001bd780
    /* CD09C 001CD09C 00000000 */   nop
    /* CD0A0 001CD0A0 C000A1C7 */  lwc1       $f1, 0xC0($29)
    /* CD0A4 001CD0A4 B000A0C7 */  lwc1       $f0, 0xB0($29)
    /* CD0A8 001CD0A8 01080046 */  sub.s      $f0, $f1, $f0
    /* CD0AC 001CD0AC A000A0E7 */  swc1       $f0, 0xA0($29)
    /* CD0B0 001CD0B0 C400A1C7 */  lwc1       $f1, 0xC4($29)
    /* CD0B4 001CD0B4 B400A0C7 */  lwc1       $f0, 0xB4($29)
    /* CD0B8 001CD0B8 01080046 */  sub.s      $f0, $f1, $f0
    /* CD0BC 001CD0BC A400A0E7 */  swc1       $f0, 0xA4($29)
    /* CD0C0 001CD0C0 C800A1C7 */  lwc1       $f1, 0xC8($29)
    /* CD0C4 001CD0C4 B800A0C7 */  lwc1       $f0, 0xB8($29)
    /* CD0C8 001CD0C8 01080046 */  sub.s      $f0, $f1, $f0
    /* CD0CC 001CD0CC A800A0E7 */  swc1       $f0, 0xA8($29)
    /* CD0D0 001CD0D0 A000A427 */  addiu      $4, $29, 0xA0
    /* CD0D4 001CD0D4 60900F0C */  jal        func_003e4180
    /* CD0D8 001CD0D8 00000000 */   nop
    /* CD0DC 001CD0DC 06050046 */  mov.s      $f20, $f0
    /* CD0E0 001CD0E0 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CD0E4 001CD0E4 00088244 */  mtc1       $2, $f1
    /* CD0E8 001CD0E8 B80020C6 */  lwc1       $f0, 0xB8($17)
    /* CD0EC 001CD0EC 42080046 */  mul.s      $f1, $f1, $f0
    /* CD0F0 001CD0F0 108180C7 */  lwc1       $f0, -0x7EF0($28)
    /* CD0F4 001CD0F4 02030146 */  mul.s      $f12, $f0, $f1
    /* CD0F8 001CD0F8 1A2E110C */  jal        func_0044b868
    /* CD0FC 001CD0FC 00000000 */   nop
    /* CD100 001CD100 900002C6 */  lwc1       $f2, 0x90($16)
    /* CD104 001CD104 2C0001C6 */  lwc1       $f1, 0x2C($16)
    /* CD108 001CD108 82100146 */  mul.s      $f2, $f2, $f1
    /* CD10C 001CD10C 8040023C */  lui        $2, (0x40800000 >> 16)
    /* CD110 001CD110 00088244 */  mtc1       $2, $f1
    /* CD114 001CD114 00000000 */  nop
    /* CD118 001CD118 42080246 */  mul.s      $f1, $f1, $f2
    /* CD11C 001CD11C 03080046 */  div.s      $f0, $f1, $f0
    /* CD120 001CD120 00A50046 */  add.s      $f20, $f20, $f0
    /* CD124 001CD124 A0C0023C */  lui        $2, (0xC0A00000 >> 16)
    /* CD128 001CD128 00608244 */  mtc1       $2, $f12
    /* CD12C 001CD12C 4C00A427 */  addiu      $4, $29, 0x4C
    /* CD130 001CD130 6100053C */  lui        $5, %hi(D_0060A0E0)
    /* CD134 001CD134 E0A0A524 */  addiu      $5, $5, %lo(D_0060A0E0)
    /* CD138 001CD138 02000624 */  addiu      $6, $0, 0x2
    /* CD13C 001CD13C D0710F0C */  jal        func_003dc740
    /* CD140 001CD140 00000000 */   nop
    /* CD144 001CD144 A000A427 */  addiu      $4, $29, 0xA0
    /* CD148 001CD148 6100053C */  lui        $5, %hi(D_0060A100)
    /* CD14C 001CD14C 00A1A524 */  addiu      $5, $5, %lo(D_0060A100)
    /* CD150 001CD150 01000624 */  addiu      $6, $0, 0x1
    /* CD154 001CD154 4C00A727 */  addiu      $7, $29, 0x4C
    /* CD158 001CD158 D0720F0C */  jal        func_003dcb40
    /* CD15C 001CD15C 00000000 */   nop
    /* CD160 001CD160 A000A0C7 */  lwc1       $f0, 0xA0($29)
    /* CD164 001CD164 C2001446 */  mul.s      $f3, $f0, $f20
    /* CD168 001CD168 A000A3E7 */  swc1       $f3, 0xA0($29)
    /* CD16C 001CD16C A400A0C7 */  lwc1       $f0, 0xA4($29)
    /* CD170 001CD170 82001446 */  mul.s      $f2, $f0, $f20
    /* CD174 001CD174 A400A2E7 */  swc1       $f2, 0xA4($29)
    /* CD178 001CD178 A800A0C7 */  lwc1       $f0, 0xA8($29)
    /* CD17C 001CD17C 42001446 */  mul.s      $f1, $f0, $f20
    /* CD180 001CD180 A800A1E7 */  swc1       $f1, 0xA8($29)
    /* CD184 001CD184 B000A0C7 */  lwc1       $f0, 0xB0($29)
    /* CD188 001CD188 00000346 */  add.s      $f0, $f0, $f3
    /* CD18C 001CD18C 4000A0E7 */  swc1       $f0, 0x40($29)
    /* CD190 001CD190 B400A0C7 */  lwc1       $f0, 0xB4($29)
    /* CD194 001CD194 00000246 */  add.s      $f0, $f0, $f2
    /* CD198 001CD198 4400A0E7 */  swc1       $f0, 0x44($29)
    /* CD19C 001CD19C B800A0C7 */  lwc1       $f0, 0xB8($29)
    /* CD1A0 001CD1A0 00000146 */  add.s      $f0, $f0, $f1
    /* CD1A4 001CD1A4 4800A0E7 */  swc1       $f0, 0x48($29)
    /* CD1A8 001CD1A8 4000A427 */  addiu      $4, $29, 0x40
    /* CD1AC 001CD1AC 2D288000 */  daddu      $5, $4, $0
    /* CD1B0 001CD1B0 E8F0060C */  jal        func_001bc3a0
    /* CD1B4 001CD1B4 00000000 */   nop
    /* CD1B8 001CD1B8 4400A1C7 */  lwc1       $f1, 0x44($29)
    /* CD1BC 001CD1BC C841023C */  lui        $2, (0x41C80000 >> 16)
    /* CD1C0 001CD1C0 00008244 */  mtc1       $2, $f0
    /* CD1C4 001CD1C4 00000000 */  nop
    /* CD1C8 001CD1C8 34080046 */  c.lt.s     $f1, $f0
    /* CD1CC 001CD1CC 02000045 */  bc1f       .L001CD1D8
    /* CD1D0 001CD1D0 00000000 */   nop
    /* CD1D4 001CD1D4 4400A0E7 */  swc1       $f0, 0x44($29)
  .L001CD1D8:
    /* CD1D8 001CD1D8 2D200002 */  daddu      $4, $16, $0
    /* CD1DC 001CD1DC C000A527 */  addiu      $5, $29, 0xC0
    /* CD1E0 001CD1E0 3C56060C */  jal        func_001958f0
    /* CD1E4 001CD1E4 00000000 */   nop
    /* CD1E8 001CD1E8 8C0001C6 */  lwc1       $f1, 0x8C($16)
    /* CD1EC 001CD1EC 2C0000C6 */  lwc1       $f0, 0x2C($16)
    /* CD1F0 001CD1F0 82080046 */  mul.s      $f2, $f1, $f0
    /* CD1F4 001CD1F4 C400A2E7 */  swc1       $f2, 0xC4($29)
    /* CD1F8 001CD1F8 C000A1C7 */  lwc1       $f1, 0xC0($29)
    /* CD1FC 001CD1FC B000A0C7 */  lwc1       $f0, 0xB0($29)
    /* CD200 001CD200 01080046 */  sub.s      $f0, $f1, $f0
    /* CD204 001CD204 A000A0E7 */  swc1       $f0, 0xA0($29)
    /* CD208 001CD208 B400A0C7 */  lwc1       $f0, 0xB4($29)
    /* CD20C 001CD20C 01100046 */  sub.s      $f0, $f2, $f0
    /* CD210 001CD210 A400A0E7 */  swc1       $f0, 0xA4($29)
    /* CD214 001CD214 C800A1C7 */  lwc1       $f1, 0xC8($29)
    /* CD218 001CD218 B800A0C7 */  lwc1       $f0, 0xB8($29)
    /* CD21C 001CD21C 01080046 */  sub.s      $f0, $f1, $f0
    /* CD220 001CD220 A800A0E7 */  swc1       $f0, 0xA8($29)
    /* CD224 001CD224 A000A427 */  addiu      $4, $29, 0xA0
    /* CD228 001CD228 60900F0C */  jal        func_003e4180
    /* CD22C 001CD22C 00000000 */   nop
    /* CD230 001CD230 06050046 */  mov.s      $f20, $f0
    /* CD234 001CD234 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CD238 001CD238 00088244 */  mtc1       $2, $f1
    /* CD23C 001CD23C B80020C6 */  lwc1       $f0, 0xB8($17)
    /* CD240 001CD240 42080046 */  mul.s      $f1, $f1, $f0
    /* CD244 001CD244 108180C7 */  lwc1       $f0, -0x7EF0($28)
    /* CD248 001CD248 02030146 */  mul.s      $f12, $f0, $f1
    /* CD24C 001CD24C 1A2E110C */  jal        func_0044b868
    /* CD250 001CD250 00000000 */   nop
    /* CD254 001CD254 900002C6 */  lwc1       $f2, 0x90($16)
    /* CD258 001CD258 2C0001C6 */  lwc1       $f1, 0x2C($16)
    /* CD25C 001CD25C 82100146 */  mul.s      $f2, $f2, $f1
    /* CD260 001CD260 A040023C */  lui        $2, (0x40A00000 >> 16)
    /* CD264 001CD264 00088244 */  mtc1       $2, $f1
    /* CD268 001CD268 00000000 */  nop
    /* CD26C 001CD26C 42080246 */  mul.s      $f1, $f1, $f2
    /* CD270 001CD270 03080046 */  div.s      $f0, $f1, $f0
    /* CD274 001CD274 00A50046 */  add.s      $f20, $f20, $f0
    /* CD278 001CD278 8400A427 */  addiu      $4, $29, 0x84
    /* CD27C 001CD27C C000A527 */  addiu      $5, $29, 0xC0
    /* CD280 001CD280 B000A627 */  addiu      $6, $29, 0xB0
    /* CD284 001CD284 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* CD288 001CD288 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* CD28C 001CD28C E0F5060C */  jal        func_001bd780
    /* CD290 001CD290 00000000 */   nop
    /* CD294 001CD294 ACB3828F */  lw         $2, -0x4C54($28)
    /* CD298 001CD298 640C4290 */  lbu        $2, 0xC64($2)
    /* CD29C 001CD29C 02004128 */  slti       $1, $2, 0x2
    /* CD2A0 001CD2A0 0B002014 */  bnez       $1, .L001CD2D0
    /* CD2A4 001CD2A4 00000000 */   nop
    /* CD2A8 001CD2A8 6041023C */  lui        $2, (0x41600000 >> 16)
    /* CD2AC 001CD2AC 00608244 */  mtc1       $2, $f12
    /* CD2B0 001CD2B0 8400A427 */  addiu      $4, $29, 0x84
    /* CD2B4 001CD2B4 6100053C */  lui        $5, %hi(D_0060A0E0)
    /* CD2B8 001CD2B8 E0A0A524 */  addiu      $5, $5, %lo(D_0060A0E0)
    /* CD2BC 001CD2BC 02000624 */  addiu      $6, $0, 0x2
    /* CD2C0 001CD2C0 D0710F0C */  jal        func_003dc740
    /* CD2C4 001CD2C4 00000000 */   nop
    /* CD2C8 001CD2C8 09000010 */  b          .L001CD2F0
    /* CD2CC 001CD2CC 00000000 */   nop
  .L001CD2D0:
    /* CD2D0 001CD2D0 2040023C */  lui        $2, (0x40200000 >> 16)
    /* CD2D4 001CD2D4 00608244 */  mtc1       $2, $f12
    /* CD2D8 001CD2D8 8400A427 */  addiu      $4, $29, 0x84
    /* CD2DC 001CD2DC 6100053C */  lui        $5, %hi(D_0060A0E0)
    /* CD2E0 001CD2E0 E0A0A524 */  addiu      $5, $5, %lo(D_0060A0E0)
    /* CD2E4 001CD2E4 02000624 */  addiu      $6, $0, 0x2
    /* CD2E8 001CD2E8 D0710F0C */  jal        func_003dc740
    /* CD2EC 001CD2EC 00000000 */   nop
  .L001CD2F0:
    /* CD2F0 001CD2F0 A000A427 */  addiu      $4, $29, 0xA0
    /* CD2F4 001CD2F4 6100053C */  lui        $5, %hi(D_0060A100)
    /* CD2F8 001CD2F8 00A1A524 */  addiu      $5, $5, %lo(D_0060A100)
    /* CD2FC 001CD2FC 01000624 */  addiu      $6, $0, 0x1
    /* CD300 001CD300 8400A727 */  addiu      $7, $29, 0x84
    /* CD304 001CD304 D0720F0C */  jal        func_003dcb40
    /* CD308 001CD308 00000000 */   nop
    /* CD30C 001CD30C A000A0C7 */  lwc1       $f0, 0xA0($29)
    /* CD310 001CD310 C2001446 */  mul.s      $f3, $f0, $f20
    /* CD314 001CD314 A000A3E7 */  swc1       $f3, 0xA0($29)
    /* CD318 001CD318 A400A0C7 */  lwc1       $f0, 0xA4($29)
    /* CD31C 001CD31C 82001446 */  mul.s      $f2, $f0, $f20
    /* CD320 001CD320 A400A2E7 */  swc1       $f2, 0xA4($29)
    /* CD324 001CD324 A800A0C7 */  lwc1       $f0, 0xA8($29)
    /* CD328 001CD328 42001446 */  mul.s      $f1, $f0, $f20
    /* CD32C 001CD32C A800A1E7 */  swc1       $f1, 0xA8($29)
    /* CD330 001CD330 B000A0C7 */  lwc1       $f0, 0xB0($29)
    /* CD334 001CD334 00000346 */  add.s      $f0, $f0, $f3
    /* CD338 001CD338 7800A0E7 */  swc1       $f0, 0x78($29)
    /* CD33C 001CD33C B400A0C7 */  lwc1       $f0, 0xB4($29)
    /* CD340 001CD340 00000246 */  add.s      $f0, $f0, $f2
    /* CD344 001CD344 7C00A0E7 */  swc1       $f0, 0x7C($29)
    /* CD348 001CD348 B800A0C7 */  lwc1       $f0, 0xB8($29)
    /* CD34C 001CD34C 00000146 */  add.s      $f0, $f0, $f1
    /* CD350 001CD350 8000A0E7 */  swc1       $f0, 0x80($29)
    /* CD354 001CD354 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CD358 001CD358 00608244 */  mtc1       $2, $f12
    /* CD35C 001CD35C 5C00A427 */  addiu      $4, $29, 0x5C
    /* CD360 001CD360 4000A527 */  addiu      $5, $29, 0x40
    /* CD364 001CD364 7800A627 */  addiu      $6, $29, 0x78
    /* CD368 001CD368 E4E9060C */  jal        func_001ba790
    /* CD36C 001CD36C 00000000 */   nop
    /* CD370 001CD370 4400A0C7 */  lwc1       $f0, 0x44($29)
    /* CD374 001CD374 6000A0E7 */  swc1       $f0, 0x60($29)
    /* CD378 001CD378 6040023C */  lui        $2, (0x40600000 >> 16)
    /* CD37C 001CD37C 00A08244 */  mtc1       $2, $f20
    /* CD380 001CD380 7E000010 */  b          .L001CD57C
    /* CD384 001CD384 00000000 */   nop
  .L001CD388:
    /* CD388 001CD388 01000524 */  addiu      $5, $0, 0x1
    /* CD38C 001CD38C 2D30A000 */  daddu      $6, $5, $0
    /* CD390 001CD390 2D380000 */  daddu      $7, $0, $0
    /* CD394 001CD394 7800A827 */  addiu      $8, $29, 0x78
    /* CD398 001CD398 D01B070C */  jal        func_001c6f40
    /* CD39C 001CD39C 00000000 */   nop
    /* CD3A0 001CD3A0 01000424 */  addiu      $4, $0, 0x1
    /* CD3A4 001CD3A4 2D280000 */  daddu      $5, $0, $0
    /* CD3A8 001CD3A8 2D300000 */  daddu      $6, $0, $0
    /* CD3AC 001CD3AC CC00A727 */  addiu      $7, $29, 0xCC
    /* CD3B0 001CD3B0 2D400000 */  daddu      $8, $0, $0
    /* CD3B4 001CD3B4 2D480000 */  daddu      $9, $0, $0
    /* CD3B8 001CD3B8 1058060C */  jal        func_00196040
    /* CD3BC 001CD3BC 00000000 */   nop
    /* CD3C0 001CD3C0 06050046 */  mov.s      $f20, $f0
    /* CD3C4 001CD3C4 02000424 */  addiu      $4, $0, 0x2
    /* CD3C8 001CD3C8 2D280000 */  daddu      $5, $0, $0
    /* CD3CC 001CD3CC B000A627 */  addiu      $6, $29, 0xB0
    /* CD3D0 001CD3D0 2D380000 */  daddu      $7, $0, $0
    /* CD3D4 001CD3D4 2D400000 */  daddu      $8, $0, $0
    /* CD3D8 001CD3D8 2D480000 */  daddu      $9, $0, $0
    /* CD3DC 001CD3DC 1058060C */  jal        func_00196040
    /* CD3E0 001CD3E0 00000000 */   nop
    /* CD3E4 001CD3E4 4843023C */  lui        $2, (0x43480000 >> 16)
    /* CD3E8 001CD3E8 00008244 */  mtc1       $2, $f0
    /* CD3EC 001CD3EC 00000000 */  nop
    /* CD3F0 001CD3F0 36001446 */  c.le.s     $f0, $f20
    /* CD3F4 001CD3F4 02000145 */  bc1t       .L001CD400
    /* CD3F8 001CD3F8 00000000 */   nop
    /* CD3FC 001CD3FC 06050046 */  mov.s      $f20, $f0
  .L001CD400:
    /* CD400 001CD400 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CD404 001CD404 00208244 */  mtc1       $2, $f4
    /* CD408 001CD408 CC00A0C7 */  lwc1       $f0, 0xCC($29)
    /* CD40C 001CD40C 02200046 */  mul.s      $f0, $f4, $f0
    /* CD410 001CD410 B400A0E7 */  swc1       $f0, 0xB4($29)
    /* CD414 001CD414 8400A3C7 */  lwc1       $f3, 0x84($29)
    /* CD418 001CD418 8800A2C7 */  lwc1       $f2, 0x88($29)
    /* CD41C 001CD41C 8C00A1C7 */  lwc1       $f1, 0x8C($29)
    /* CD420 001CD420 9000A0C7 */  lwc1       $f0, 0x90($29)
    /* CD424 001CD424 4C00A3E7 */  swc1       $f3, 0x4C($29)
    /* CD428 001CD428 5000A2E7 */  swc1       $f2, 0x50($29)
    /* CD42C 001CD42C 5400A1E7 */  swc1       $f1, 0x54($29)
    /* CD430 001CD430 5800A0E7 */  swc1       $f0, 0x58($29)
    /* CD434 001CD434 B80020C6 */  lwc1       $f0, 0xB8($17)
    /* CD438 001CD438 42200046 */  mul.s      $f1, $f4, $f0
    /* CD43C 001CD43C 108180C7 */  lwc1       $f0, -0x7EF0($28)
    /* CD440 001CD440 02030146 */  mul.s      $f12, $f0, $f1
    /* CD444 001CD444 1A2E110C */  jal        func_0044b868
    /* CD448 001CD448 00000000 */   nop
    /* CD44C 001CD44C 403F023C */  lui        $2, (0x3F400000 >> 16)
    /* CD450 001CD450 00088244 */  mtc1       $2, $f1
    /* CD454 001CD454 00000000 */  nop
    /* CD458 001CD458 42081446 */  mul.s      $f1, $f1, $f20
    /* CD45C 001CD45C 030D0046 */  div.s      $f20, $f1, $f0
    /* CD460 001CD460 ACB3828F */  lw         $2, -0x4C54($28)
    /* CD464 001CD464 640C4290 */  lbu        $2, 0xC64($2)
    /* CD468 001CD468 02004128 */  slti       $1, $2, 0x2
    /* CD46C 001CD46C 0B002014 */  bnez       $1, .L001CD49C
    /* CD470 001CD470 00000000 */   nop
    /* CD474 001CD474 4041023C */  lui        $2, (0x41400000 >> 16)
    /* CD478 001CD478 00608244 */  mtc1       $2, $f12
    /* CD47C 001CD47C 4C00A427 */  addiu      $4, $29, 0x4C
    /* CD480 001CD480 6100053C */  lui        $5, %hi(D_0060A0E0)
    /* CD484 001CD484 E0A0A524 */  addiu      $5, $5, %lo(D_0060A0E0)
    /* CD488 001CD488 02000624 */  addiu      $6, $0, 0x2
    /* CD48C 001CD48C D0710F0C */  jal        func_003dc740
    /* CD490 001CD490 00000000 */   nop
    /* CD494 001CD494 09000010 */  b          .L001CD4BC
    /* CD498 001CD498 00000000 */   nop
  .L001CD49C:
    /* CD49C 001CD49C A040023C */  lui        $2, (0x40A00000 >> 16)
    /* CD4A0 001CD4A0 00608244 */  mtc1       $2, $f12
    /* CD4A4 001CD4A4 4C00A427 */  addiu      $4, $29, 0x4C
    /* CD4A8 001CD4A8 6100053C */  lui        $5, %hi(D_0060A0E0)
    /* CD4AC 001CD4AC E0A0A524 */  addiu      $5, $5, %lo(D_0060A0E0)
    /* CD4B0 001CD4B0 02000624 */  addiu      $6, $0, 0x2
    /* CD4B4 001CD4B4 D0710F0C */  jal        func_003dc740
    /* CD4B8 001CD4B8 00000000 */   nop
  .L001CD4BC:
    /* CD4BC 001CD4BC A000A427 */  addiu      $4, $29, 0xA0
    /* CD4C0 001CD4C0 6100053C */  lui        $5, %hi(D_0060A100)
    /* CD4C4 001CD4C4 00A1A524 */  addiu      $5, $5, %lo(D_0060A100)
    /* CD4C8 001CD4C8 01000624 */  addiu      $6, $0, 0x1
    /* CD4CC 001CD4CC 4C00A727 */  addiu      $7, $29, 0x4C
    /* CD4D0 001CD4D0 D0720F0C */  jal        func_003dcb40
    /* CD4D4 001CD4D4 00000000 */   nop
    /* CD4D8 001CD4D8 A000A0C7 */  lwc1       $f0, 0xA0($29)
    /* CD4DC 001CD4DC C2001446 */  mul.s      $f3, $f0, $f20
    /* CD4E0 001CD4E0 A000A3E7 */  swc1       $f3, 0xA0($29)
    /* CD4E4 001CD4E4 A400A0C7 */  lwc1       $f0, 0xA4($29)
    /* CD4E8 001CD4E8 82001446 */  mul.s      $f2, $f0, $f20
    /* CD4EC 001CD4EC A400A2E7 */  swc1       $f2, 0xA4($29)
    /* CD4F0 001CD4F0 A800A0C7 */  lwc1       $f0, 0xA8($29)
    /* CD4F4 001CD4F4 42001446 */  mul.s      $f1, $f0, $f20
    /* CD4F8 001CD4F8 A800A1E7 */  swc1       $f1, 0xA8($29)
    /* CD4FC 001CD4FC B000A0C7 */  lwc1       $f0, 0xB0($29)
    /* CD500 001CD500 00000346 */  add.s      $f0, $f0, $f3
    /* CD504 001CD504 4000A0E7 */  swc1       $f0, 0x40($29)
    /* CD508 001CD508 B400A0C7 */  lwc1       $f0, 0xB4($29)
    /* CD50C 001CD50C 00000246 */  add.s      $f0, $f0, $f2
    /* CD510 001CD510 4400A0E7 */  swc1       $f0, 0x44($29)
    /* CD514 001CD514 B800A0C7 */  lwc1       $f0, 0xB8($29)
    /* CD518 001CD518 00000146 */  add.s      $f0, $f0, $f1
    /* CD51C 001CD51C 4800A0E7 */  swc1       $f0, 0x48($29)
    /* CD520 001CD520 4000A427 */  addiu      $4, $29, 0x40
    /* CD524 001CD524 2D288000 */  daddu      $5, $4, $0
    /* CD528 001CD528 E8F0060C */  jal        func_001bc3a0
    /* CD52C 001CD52C 00000000 */   nop
    /* CD530 001CD530 4400A1C7 */  lwc1       $f1, 0x44($29)
    /* CD534 001CD534 C841023C */  lui        $2, (0x41C80000 >> 16)
    /* CD538 001CD538 00008244 */  mtc1       $2, $f0
    /* CD53C 001CD53C 00000000 */  nop
    /* CD540 001CD540 34080046 */  c.lt.s     $f1, $f0
    /* CD544 001CD544 02000045 */  bc1f       .L001CD550
    /* CD548 001CD548 00000000 */   nop
    /* CD54C 001CD54C 4400A0E7 */  swc1       $f0, 0x44($29)
  .L001CD550:
    /* CD550 001CD550 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CD554 001CD554 00608244 */  mtc1       $2, $f12
    /* CD558 001CD558 5C00A427 */  addiu      $4, $29, 0x5C
    /* CD55C 001CD55C 4000A527 */  addiu      $5, $29, 0x40
    /* CD560 001CD560 7800A627 */  addiu      $6, $29, 0x78
    /* CD564 001CD564 E4E9060C */  jal        func_001ba790
    /* CD568 001CD568 00000000 */   nop
    /* CD56C 001CD56C 4400A0C7 */  lwc1       $f0, 0x44($29)
    /* CD570 001CD570 6000A0E7 */  swc1       $f0, 0x60($29)
    /* CD574 001CD574 0040023C */  lui        $2, (0x40000000 >> 16)
    /* CD578 001CD578 00A08244 */  mtc1       $2, $f20
  .L001CD57C:
    /* CD57C 001CD57C 00608044 */  mtc1       $0, $f12
    /* CD580 001CD580 E000248E */  lw         $4, 0xE0($17)
    /* CD584 001CD584 2D280000 */  daddu      $5, $0, $0
    /* CD588 001CD588 2D300000 */  daddu      $6, $0, $0
    /* CD58C 001CD58C 01000724 */  addiu      $7, $0, 0x1
    /* CD590 001CD590 50F3060C */  jal        func_001bcd40
    /* CD594 001CD594 00000000 */   nop
    /* CD598 001CD598 00608044 */  mtc1       $0, $f12
    /* CD59C 001CD59C E000248E */  lw         $4, 0xE0($17)
    /* CD5A0 001CD5A0 2D280000 */  daddu      $5, $0, $0
    /* CD5A4 001CD5A4 2D300000 */  daddu      $6, $0, $0
    /* CD5A8 001CD5A8 00010724 */  addiu      $7, $0, 0x100
    /* CD5AC 001CD5AC 50F3060C */  jal        func_001bcd40
    /* CD5B0 001CD5B0 00000000 */   nop
    /* CD5B4 001CD5B4 2D202002 */  daddu      $4, $17, $0
    /* CD5B8 001CD5B8 4000A527 */  addiu      $5, $29, 0x40
    /* CD5BC 001CD5BC 5C00A627 */  addiu      $6, $29, 0x5C
    /* CD5C0 001CD5C0 7800A727 */  addiu      $7, $29, 0x78
    /* CD5C4 001CD5C4 01000824 */  addiu      $8, $0, 0x1
    /* CD5C8 001CD5C8 FCEB060C */  jal        func_001baff0
    /* CD5CC 001CD5CC 00000000 */   nop
    /* CD5D0 001CD5D0 2D202002 */  daddu      $4, $17, $0
    /* CD5D4 001CD5D4 06A30046 */  mov.s      $f12, $f20
    /* CD5D8 001CD5D8 BCEF060C */  jal        func_001bbef0
    /* CD5DC 001CD5DC 00000000 */   nop
    /* CD5E0 001CD5E0 3000BFDF */  ld         $31, 0x30($29)
    /* CD5E4 001CD5E4 2000B17B */  lq         $17, 0x20($29)
    /* CD5E8 001CD5E8 1000B07B */  lq         $16, 0x10($29)
    /* CD5EC 001CD5EC 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* CD5F0 001CD5F0 D000BD27 */  addiu      $29, $29, 0xD0
    /* CD5F4 001CD5F4 0800E003 */  jr         $31
    /* CD5F8 001CD5F8 00000000 */   nop
    /* CD5FC 001CD5FC 00000000 */  nop
.size func_001ccdb0, 0x850
