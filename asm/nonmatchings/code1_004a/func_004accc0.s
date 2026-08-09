.section .text
.set noat
.set noreorder
glabel func_004accc0
    /* 3ACCC0 004ACCC0 30FFBD27 */  addiu      $29, $29, -0xD0
    /* 3ACCC4 004ACCC4 3000BFFF */  sd         $31, 0x30($29)
    /* 3ACCC8 004ACCC8 2000B17F */  sq         $17, 0x20($29)
    /* 3ACCCC 004ACCCC 1000B07F */  sq         $16, 0x10($29)
    /* 3ACCD0 004ACCD0 0C00B7E7 */  swc1       $f23, 0xC($29)
    /* 3ACCD4 004ACCD4 0800B6E7 */  swc1       $f22, 0x8($29)
    /* 3ACCD8 004ACCD8 0400B5E7 */  swc1       $f21, 0x4($29)
    /* 3ACCDC 004ACCDC 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 3ACCE0 004ACCE0 2D808000 */  daddu      $16, $4, $0
    /* 3ACCE4 004ACCE4 7100023C */  lui        $2, %hi(D_007144C8)
    /* 3ACCE8 004ACCE8 C84443DC */  ld         $3, %lo(D_007144C8)($2)
    /* 3ACCEC 004ACCEC 7100023C */  lui        $2, %hi(D_007144D0)
    /* 3ACCF0 004ACCF0 D04440C4 */  lwc1       $f0, %lo(D_007144D0)($2)
    /* 3ACCF4 004ACCF4 C000A3FF */  sd         $3, 0xC0($29)
    /* 3ACCF8 004ACCF8 C800A0E7 */  swc1       $f0, 0xC8($29)
    /* 3ACCFC 004ACCFC 7100023C */  lui        $2, %hi(D_007144D8)
    /* 3ACD00 004ACD00 D84443DC */  ld         $3, %lo(D_007144D8)($2)
    /* 3ACD04 004ACD04 7100023C */  lui        $2, %hi(D_007144E0)
    /* 3ACD08 004ACD08 E04440C4 */  lwc1       $f0, %lo(D_007144E0)($2)
    /* 3ACD0C 004ACD0C B000A3FF */  sd         $3, 0xB0($29)
    /* 3ACD10 004ACD10 B800A0E7 */  swc1       $f0, 0xB8($29)
    /* 3ACD14 004ACD14 7100023C */  lui        $2, %hi(D_007144E8)
    /* 3ACD18 004ACD18 E84443DC */  ld         $3, %lo(D_007144E8)($2)
    /* 3ACD1C 004ACD1C 7100023C */  lui        $2, %hi(D_007144F0)
    /* 3ACD20 004ACD20 F04440C4 */  lwc1       $f0, %lo(D_007144F0)($2)
    /* 3ACD24 004ACD24 A000A3FF */  sd         $3, 0xA0($29)
    /* 3ACD28 004ACD28 A800A0E7 */  swc1       $f0, 0xA8($29)
    /* 3ACD2C 004ACD2C B400848C */  lw         $4, 0xB4($4)
    /* 3ACD30 004ACD30 2D280000 */  daddu      $5, $0, $0
    /* 3ACD34 004ACD34 20E8110C */  jal        func_0047a080
    /* 3ACD38 004ACD38 00000000 */   nop
    /* 3ACD3C 004ACD3C 004F033C */  lui        $3, (0x4F000000 >> 16)
    /* 3ACD40 004ACD40 00088344 */  mtc1       $3, $f1
    /* 3ACD44 004ACD44 00000000 */  nop
    /* 3ACD48 004ACD48 36080046 */  c.le.s     $f1, $f0
    /* 3ACD4C 004ACD4C 05000145 */  bc1t       .L004ACD64
    /* 3ACD50 004ACD50 00000000 */   nop
    /* 3ACD54 004ACD54 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 3ACD58 004ACD58 00000544 */  mfc1       $5, $f0
    /* 3ACD5C 004ACD5C 06000010 */  b          .L004ACD78
    /* 3ACD60 004ACD60 00000000 */   nop
  .L004ACD64:
    /* 3ACD64 004ACD64 01000146 */  sub.s      $f0, $f0, $f1
    /* 3ACD68 004ACD68 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 3ACD6C 004ACD6C 00000544 */  mfc1       $5, $f0
    /* 3ACD70 004ACD70 0080033C */  lui        $3, (0x80000000 >> 16)
    /* 3ACD74 004ACD74 2528A300 */  or         $5, $5, $3
  .L004ACD78:
    /* 3ACD78 004ACD78 9C00068E */  lw         $6, 0x9C($16)
    /* 3ACD7C 004ACD7C 2A08C500 */  slt        $1, $6, $5
    /* 3ACD80 004ACD80 03002010 */  beqz       $1, .L004ACD90
    /* 3ACD84 004ACD84 00000000 */   nop
    /* 3ACD88 004ACD88 9D00C014 */  bnez       $6, .L004AD000
    /* 3ACD8C 004ACD8C 00000000 */   nop
  .L004ACD90:
    /* 3ACD90 004ACD90 44000426 */  addiu      $4, $16, 0x44
    /* 3ACD94 004ACD94 FC2B120C */  jal        func_0048aff0
    /* 3ACD98 004ACD98 00000000 */   nop
    /* 3ACD9C 004ACD9C 2041023C */  lui        $2, (0x41200000 >> 16)
    /* 3ACDA0 004ACDA0 00088244 */  mtc1       $2, $f1
    /* 3ACDA4 004ACDA4 00000000 */  nop
    /* 3ACDA8 004ACDA8 03050146 */  div.s      $f20, $f0, $f1
    /* 3ACDAC 004ACDAC 00000000 */  nop
    /* 3ACDB0 004ACDB0 00000000 */  nop
    /* 3ACDB4 004ACDB4 00000000 */  nop
    /* 3ACDB8 004ACDB8 485C110C */  jal        func_00457120
    /* 3ACDBC 004ACDBC 00000000 */   nop
    /* 3ACDC0 004ACDC0 68005124 */  addiu      $17, $2, 0x68
    /* 3ACDC4 004ACDC4 485C110C */  jal        func_00457120
    /* 3ACDC8 004ACDC8 00000000 */   nop
    /* 3ACDCC 004ACDCC 800055C4 */  lwc1       $f21, 0x80($2)
    /* 3ACDD0 004ACDD0 485C110C */  jal        func_00457120
    /* 3ACDD4 004ACDD4 00000000 */   nop
    /* 3ACDD8 004ACDD8 840043C4 */  lwc1       $f3, 0x84($2)
    /* 3ACDDC 004ACDDC 81181546 */  sub.s      $f2, $f3, $f21
    /* 3ACDE0 004ACDE0 F8C1023C */  lui        $2, (0xC1F80000 >> 16)
    /* 3ACDE4 004ACDE4 00088244 */  mtc1       $2, $f1
    /* 3ACDE8 004ACDE8 FFFF023C */  lui        $2, (0xFFFF0001 >> 16)
    /* 3ACDEC 004ACDEC 01004234 */  ori        $2, $2, (0xFFFF0001 & 0xFFFF)
    /* 3ACDF0 004ACDF0 00008244 */  mtc1       $2, $f0
    /* 3ACDF4 004ACDF4 00000000 */  nop
    /* 3ACDF8 004ACDF8 20008046 */  cvt.s.w    $f0, $f0
    /* 3ACDFC 004ACDFC 1A000346 */  mula.s     $f0, $f3
    /* 3ACE00 004ACE00 5D080246 */  msub.s     $f1, $f1, $f2
    /* 3ACE04 004ACE04 02001546 */  mul.s      $f0, $f0, $f21
    /* 3ACE08 004ACE08 02000346 */  mul.s      $f0, $f0, $f3
    /* 3ACE0C 004ACE0C C3050146 */  div.s      $f23, $f0, $f1
    /* 3ACE10 004ACE10 000020C6 */  lwc1       $f0, 0x0($17)
    /* 3ACE14 004ACE14 02001746 */  mul.s      $f0, $f0, $f23
    /* 3ACE18 004ACE18 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 3ACE1C 004ACE1C 00088244 */  mtc1       $2, $f1
    /* 3ACE20 004ACE20 00000000 */  nop
    /* 3ACE24 004ACE24 820D0046 */  mul.s      $f22, $f1, $f0
    /* 3ACE28 004ACE28 040020C6 */  lwc1       $f0, 0x4($17)
    /* 3ACE2C 004ACE2C 02001746 */  mul.s      $f0, $f0, $f23
    /* 3ACE30 004ACE30 420D0046 */  mul.s      $f21, $f1, $f0
    /* 3ACE34 004ACE34 485C110C */  jal        func_00457120
    /* 3ACE38 004ACE38 00000000 */   nop
    /* 3ACE3C 004ACE3C 0400448C */  lw         $4, 0x4($2)
    /* 3ACE40 004ACE40 C0A50F0C */  jal        func_003e9700
    /* 3ACE44 004ACE44 00000000 */   nop
    /* 3ACE48 004ACE48 2D884000 */  daddu      $17, $2, $0
    /* 3ACE4C 004ACE4C 4000A427 */  addiu      $4, $29, 0x40
    /* 3ACE50 004ACE50 C000A527 */  addiu      $5, $29, 0xC0
    /* 3ACE54 004ACE54 90000CC6 */  lwc1       $f12, 0x90($16)
    /* 3ACE58 004ACE58 2D300000 */  daddu      $6, $0, $0
    /* 3ACE5C 004ACE5C 1C820F0C */  jal        func_003e0870
    /* 3ACE60 004ACE60 00000000 */   nop
    /* 3ACE64 004ACE64 94000CC6 */  lwc1       $f12, 0x94($16)
    /* 3ACE68 004ACE68 00008044 */  mtc1       $0, $f0
    /* 3ACE6C 004ACE6C 00000000 */  nop
    /* 3ACE70 004ACE70 32000C46 */  c.eq.s     $f0, $f12
    /* 3ACE74 004ACE74 06000145 */  bc1t       .L004ACE90
    /* 3ACE78 004ACE78 00000000 */   nop
    /* 3ACE7C 004ACE7C 4000A427 */  addiu      $4, $29, 0x40
    /* 3ACE80 004ACE80 B000A527 */  addiu      $5, $29, 0xB0
    /* 3ACE84 004ACE84 02000624 */  addiu      $6, $0, 0x2
    /* 3ACE88 004ACE88 1C820F0C */  jal        func_003e0870
    /* 3ACE8C 004ACE8C 00000000 */   nop
  .L004ACE90:
    /* 3ACE90 004ACE90 98000CC6 */  lwc1       $f12, 0x98($16)
    /* 3ACE94 004ACE94 00008044 */  mtc1       $0, $f0
    /* 3ACE98 004ACE98 00000000 */  nop
    /* 3ACE9C 004ACE9C 32000C46 */  c.eq.s     $f0, $f12
    /* 3ACEA0 004ACEA0 06000145 */  bc1t       .L004ACEBC
    /* 3ACEA4 004ACEA4 00000000 */   nop
    /* 3ACEA8 004ACEA8 4000A427 */  addiu      $4, $29, 0x40
    /* 3ACEAC 004ACEAC A000A527 */  addiu      $5, $29, 0xA0
    /* 3ACEB0 004ACEB0 02000624 */  addiu      $6, $0, 0x2
    /* 3ACEB4 004ACEB4 1C820F0C */  jal        func_003e0870
    /* 3ACEB8 004ACEB8 00000000 */   nop
  .L004ACEBC:
    /* 3ACEBC 004ACEBC 2044023C */  lui        $2, (0x44200000 >> 16)
    /* 3ACEC0 004ACEC0 00008244 */  mtc1       $2, $f0
    /* 3ACEC4 004ACEC4 00000000 */  nop
    /* 3ACEC8 004ACEC8 03B00046 */  div.s      $f0, $f22, $f0
    /* 3ACECC 004ACECC 02001446 */  mul.s      $f0, $f0, $f20
    /* 3ACED0 004ACED0 9800A0E7 */  swc1       $f0, 0x98($29)
    /* 3ACED4 004ACED4 9400A0E7 */  swc1       $f0, 0x94($29)
    /* 3ACED8 004ACED8 9000A0E7 */  swc1       $f0, 0x90($29)
    /* 3ACEDC 004ACEDC 4000A427 */  addiu      $4, $29, 0x40
    /* 3ACEE0 004ACEE0 9000A527 */  addiu      $5, $29, 0x90
    /* 3ACEE4 004ACEE4 02000624 */  addiu      $6, $0, 0x2
    /* 3ACEE8 004ACEE8 A4820F0C */  jal        func_003e0a90
    /* 3ACEEC 004ACEEC 00000000 */   nop
    /* 3ACEF0 004ACEF0 B400048E */  lw         $4, 0xB4($16)
    /* 3ACEF4 004ACEF4 BCE8110C */  jal        func_0047a2f0
    /* 3ACEF8 004ACEF8 00000000 */   nop
    /* 3ACEFC 004ACEFC 2D204000 */  daddu      $4, $2, $0
    /* 3ACF00 004ACF00 4000A527 */  addiu      $5, $29, 0x40
    /* 3ACF04 004ACF04 2D302002 */  daddu      $6, $17, $0
    /* 3ACF08 004ACF08 7C810F0C */  jal        func_003e05f0
    /* 3ACF0C 004ACF0C 00000000 */   nop
    /* 3ACF10 004ACF10 000001C6 */  lwc1       $f1, 0x0($16)
    /* 3ACF14 004ACF14 840000C6 */  lwc1       $f0, 0x84($16)
    /* 3ACF18 004ACF18 00080046 */  add.s      $f0, $f1, $f0
    /* 3ACF1C 004ACF1C 47000046 */  neg.s      $f1, $f0
    /* 3ACF20 004ACF20 2044023C */  lui        $2, (0x44200000 >> 16)
    /* 3ACF24 004ACF24 00008244 */  mtc1       $2, $f0
    /* 3ACF28 004ACF28 00000000 */  nop
    /* 3ACF2C 004ACF2C 03080046 */  div.s      $f0, $f1, $f0
    /* 3ACF30 004ACF30 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* 3ACF34 004ACF34 00108244 */  mtc1       $2, $f2
    /* 3ACF38 004ACF38 00000000 */  nop
    /* 3ACF3C 004ACF3C 00100046 */  add.s      $f0, $f2, $f0
    /* 3ACF40 004ACF40 02B00046 */  mul.s      $f0, $f22, $f0
    /* 3ACF44 004ACF44 9000A0E7 */  swc1       $f0, 0x90($29)
    /* 3ACF48 004ACF48 040001C6 */  lwc1       $f1, 0x4($16)
    /* 3ACF4C 004ACF4C 880000C6 */  lwc1       $f0, 0x88($16)
    /* 3ACF50 004ACF50 00080046 */  add.s      $f0, $f1, $f0
    /* 3ACF54 004ACF54 47000046 */  neg.s      $f1, $f0
    /* 3ACF58 004ACF58 E043023C */  lui        $2, (0x43E00000 >> 16)
    /* 3ACF5C 004ACF5C 00008244 */  mtc1       $2, $f0
    /* 3ACF60 004ACF60 00000000 */  nop
    /* 3ACF64 004ACF64 03080046 */  div.s      $f0, $f1, $f0
    /* 3ACF68 004ACF68 00100046 */  add.s      $f0, $f2, $f0
    /* 3ACF6C 004ACF6C 02A80046 */  mul.s      $f0, $f21, $f0
    /* 3ACF70 004ACF70 9400A0E7 */  swc1       $f0, 0x94($29)
    /* 3ACF74 004ACF74 8C0000C6 */  lwc1       $f0, 0x8C($16)
    /* 3ACF78 004ACF78 00001746 */  add.s      $f0, $f0, $f23
    /* 3ACF7C 004ACF7C 9800A0E7 */  swc1       $f0, 0x98($29)
    /* 3ACF80 004ACF80 8000A427 */  addiu      $4, $29, 0x80
    /* 3ACF84 004ACF84 9000A527 */  addiu      $5, $29, 0x90
    /* 3ACF88 004ACF88 2D302002 */  daddu      $6, $17, $0
    /* 3ACF8C 004ACF8C C8900F0C */  jal        func_003e4320
    /* 3ACF90 004ACF90 00000000 */   nop
    /* 3ACF94 004ACF94 300021C6 */  lwc1       $f1, 0x30($17)
    /* 3ACF98 004ACF98 8000A0C7 */  lwc1       $f0, 0x80($29)
    /* 3ACF9C 004ACF9C 000D0046 */  add.s      $f20, $f1, $f0
    /* 3ACFA0 004ACFA0 B400048E */  lw         $4, 0xB4($16)
    /* 3ACFA4 004ACFA4 BCE8110C */  jal        func_0047a2f0
    /* 3ACFA8 004ACFA8 00000000 */   nop
    /* 3ACFAC 004ACFAC 300054E4 */  swc1       $f20, 0x30($2)
    /* 3ACFB0 004ACFB0 340021C6 */  lwc1       $f1, 0x34($17)
    /* 3ACFB4 004ACFB4 8400A0C7 */  lwc1       $f0, 0x84($29)
    /* 3ACFB8 004ACFB8 000D0046 */  add.s      $f20, $f1, $f0
    /* 3ACFBC 004ACFBC B400048E */  lw         $4, 0xB4($16)
    /* 3ACFC0 004ACFC0 BCE8110C */  jal        func_0047a2f0
    /* 3ACFC4 004ACFC4 00000000 */   nop
    /* 3ACFC8 004ACFC8 340054E4 */  swc1       $f20, 0x34($2)
    /* 3ACFCC 004ACFCC 380021C6 */  lwc1       $f1, 0x38($17)
    /* 3ACFD0 004ACFD0 8800A0C7 */  lwc1       $f0, 0x88($29)
    /* 3ACFD4 004ACFD4 000D0046 */  add.s      $f20, $f1, $f0
    /* 3ACFD8 004ACFD8 B400048E */  lw         $4, 0xB4($16)
    /* 3ACFDC 004ACFDC BCE8110C */  jal        func_0047a2f0
    /* 3ACFE0 004ACFE0 00000000 */   nop
    /* 3ACFE4 004ACFE4 380054E4 */  swc1       $f20, 0x38($2)
    /* 3ACFE8 004ACFE8 B400048E */  lw         $4, 0xB4($16)
    /* 3ACFEC 004ACFEC 70E2110C */  jal        func_004789c0
    /* 3ACFF0 004ACFF0 00000000 */   nop
    /* 3ACFF4 004ACFF4 B400048E */  lw         $4, 0xB4($16)
    /* 3ACFF8 004ACFF8 C8E8110C */  jal        func_0047a320
    /* 3ACFFC 004ACFFC 00000000 */   nop
  .L004AD000:
    /* 3AD000 004AD000 3000BFDF */  ld         $31, 0x30($29)
    /* 3AD004 004AD004 2000B17B */  lq         $17, 0x20($29)
    /* 3AD008 004AD008 1000B07B */  lq         $16, 0x10($29)
    /* 3AD00C 004AD00C 0C00B7C7 */  lwc1       $f23, 0xC($29)
    /* 3AD010 004AD010 0800B6C7 */  lwc1       $f22, 0x8($29)
    /* 3AD014 004AD014 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* 3AD018 004AD018 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 3AD01C 004AD01C D000BD27 */  addiu      $29, $29, 0xD0
    /* 3AD020 004AD020 0800E003 */  jr         $31
    /* 3AD024 004AD024 00000000 */   nop
    /* 3AD028 004AD028 00000000 */  nop
    /* 3AD02C 004AD02C 00000000 */  nop
.size func_004accc0, 0x370
