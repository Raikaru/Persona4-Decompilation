.section .text
.set noat
.set noreorder
glabel func_003bee80
    /* 2BEE80 003BEE80 90FFBD27 */  addiu      $29, $29, -0x70
    /* 2BEE84 003BEE84 4000BFFF */  sd         $31, 0x40($29)
    /* 2BEE88 003BEE88 6800A627 */  addiu      $6, $29, 0x68
    /* 2BEE8C 003BEE8C 3000B37F */  sq         $19, 0x30($29)
    /* 2BEE90 003BEE90 6400A727 */  addiu      $7, $29, 0x64
    /* 2BEE94 003BEE94 2000B27F */  sq         $18, 0x20($29)
    /* 2BEE98 003BEE98 2D988000 */  daddu      $19, $4, $0
    /* 2BEE9C 003BEE9C 1000B17F */  sq         $17, 0x10($29)
    /* 2BEEA0 003BEEA0 0000B07F */  sq         $16, 0x0($29)
    /* 2BEEA4 003BEEA4 2D80A000 */  daddu      $16, $5, $0
    /* 2BEEA8 003BEEA8 147C0F0C */  jal        func_003df050
    /* 2BEEAC 003BEEAC 01000524 */   addiu     $5, $0, 0x1
    /* 2BEEB0 003BEEB0 1E004010 */  beqz       $2, .L003BEF2C
    /* 2BEEB4 003BEEB4 00000000 */   nop
    /* 2BEEB8 003BEEB8 6400A38F */  lw         $3, 0x64($29)
    /* 2BEEBC 003BEEBC 0300023C */  lui        $2, (0x35000 >> 16)
    /* 2BEEC0 003BEEC0 00504234 */  ori        $2, $2, (0x35000 & 0xFFFF)
    /* 2BEEC4 003BEEC4 2B106200 */  sltu       $2, $3, $2
    /* 2BEEC8 003BEEC8 A4004014 */  bnez       $2, .L003BF15C
    /* 2BEECC 003BEECC 00000000 */   nop
    /* 2BEED0 003BEED0 0300013C */  lui        $1, (0x37003 >> 16)
    /* 2BEED4 003BEED4 03702134 */  ori        $1, $1, (0x37003 & 0xFFFF)
    /* 2BEED8 003BEED8 2B086100 */  sltu       $1, $3, $1
    /* 2BEEDC 003BEEDC 9F002010 */  beqz       $1, .L003BF15C
    /* 2BEEE0 003BEEE0 00000000 */   nop
    /* 2BEEE4 003BEEE4 2D206002 */  daddu      $4, $19, $0
    /* 2BEEE8 003BEEE8 6C00A527 */  addiu      $5, $29, 0x6C
    /* 2BEEEC 003BEEEC 448A0F0C */  jal        func_003e2910
    /* 2BEEF0 003BEEF0 04000624 */   addiu     $6, $0, 0x4
    /* 2BEEF4 003BEEF4 04000324 */  addiu      $3, $0, 0x4
    /* 2BEEF8 003BEEF8 0E004314 */  bne        $2, $3, .L003BEF34
    /* 2BEEFC 003BEEFC 00000000 */   nop
    /* 2BEF00 003BEF00 040000AE */  sw         $0, 0x4($16)
    /* 2BEF04 003BEF04 6C00A28F */  lw         $2, 0x6C($29)
    /* 2BEF08 003BEF08 0C00401C */  bgtz       $2, .L003BEF3C
    /* 2BEF0C 003BEF0C 00000000 */   nop
    /* 2BEF10 003BEF10 000000AE */  sw         $0, 0x0($16)
  .L003BEF14:
    /* 2BEF14 003BEF14 6C00A28F */  lw         $2, 0x6C($29)
    /* 2BEF18 003BEF18 2A100200 */  slt        $2, $0, $2
    /* 2BEF1C 003BEF1C 1E004014 */  bnez       $2, .L003BEF98
    /* 2BEF20 003BEF20 2D900000 */   daddu     $18, $0, $0
  .L003BEF24:
    /* 2BEF24 003BEF24 96000010 */  b          .L003BF180
    /* 2BEF28 003BEF28 2D100002 */   daddu     $2, $16, $0
  .L003BEF2C:
    /* 2BEF2C 003BEF2C 94000010 */  b          .L003BF180
    /* 2BEF30 003BEF30 2D100000 */   daddu     $2, $0, $0
  .L003BEF34:
    /* 2BEF34 003BEF34 92000010 */  b          .L003BF180
    /* 2BEF38 003BEF38 2D100000 */   daddu     $2, $0, $0
  .L003BEF3C:
    /* 2BEF3C 003BEF3C 80200200 */  sll        $4, $2, 2
    /* 2BEF40 003BEF40 0300023C */  lui        $2, (0x3000F >> 16)
    /* 2BEF44 003BEF44 0F004534 */  ori        $5, $2, (0x3000F & 0xFFFF)
    /* 2BEF48 003BEF48 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 2BEF4C 003BEF4C E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 2BEF50 003BEF50 09F84000 */  jalr       $2
    /* 2BEF54 003BEF54 00000000 */   nop
    /* 2BEF58 003BEF58 000002AE */  sw         $2, 0x0($16)
    /* 2BEF5C 003BEF5C 0000028E */  lw         $2, 0x0($16)
    /* 2BEF60 003BEF60 ECFF4014 */  bnez       $2, .L003BEF14
    /* 2BEF64 003BEF64 00000000 */   nop
    /* 2BEF68 003BEF68 6C00A38F */  lw         $3, 0x6C($29)
    /* 2BEF6C 003BEF6C 02000224 */  addiu      $2, $0, 0x2
    /* 2BEF70 003BEF70 5800A2AF */  sw         $2, 0x58($29)
    /* 2BEF74 003BEF74 0080023C */  lui        $2, (0x80000013 >> 16)
    /* 2BEF78 003BEF78 13004434 */  ori        $4, $2, (0x80000013 & 0xFFFF)
    /* 2BEF7C 003BEF7C 647D0F0C */  jal        func_003df590
    /* 2BEF80 003BEF80 80280300 */   sll       $5, $3, 2
    /* 2BEF84 003BEF84 5C00A2AF */  sw         $2, 0x5C($29)
    /* 2BEF88 003BEF88 347D0F0C */  jal        func_003df4d0
    /* 2BEF8C 003BEF8C 5800A427 */   addiu     $4, $29, 0x58
    /* 2BEF90 003BEF90 7B000010 */  b          .L003BF180
    /* 2BEF94 003BEF94 2D100000 */   daddu     $2, $0, $0
  .L003BEF98:
    /* 2BEF98 003BEF98 2D880000 */  daddu      $17, $0, $0
  .L003BEF9C:
    /* 2BEF9C 003BEF9C 2D206002 */  daddu      $4, $19, $0
    /* 2BEFA0 003BEFA0 0F000524 */  addiu      $5, $0, 0xF
    /* 2BEFA4 003BEFA4 2D300000 */  daddu      $6, $0, $0
    /* 2BEFA8 003BEFA8 147C0F0C */  jal        func_003df050
    /* 2BEFAC 003BEFAC 6400A727 */   addiu     $7, $29, 0x64
    /* 2BEFB0 003BEFB0 0F004014 */  bnez       $2, .L003BEFF0
    /* 2BEFB4 003BEFB4 00000000 */   nop
    /* 2BEFB8 003BEFB8 0400028E */  lw         $2, 0x4($16)
    /* 2BEFBC 003BEFBC 2A100200 */  slt        $2, $0, $2
    /* 2BEFC0 003BEFC0 26004014 */  bnez       $2, .L003BF05C
    /* 2BEFC4 003BEFC4 2D900000 */   daddu     $18, $0, $0
    /* 2BEFC8 003BEFC8 0000048E */  lw         $4, 0x0($16)
  .L003BEFCC:
    /* 2BEFCC 003BEFCC 06008010 */  beqz       $4, .L003BEFE8
    /* 2BEFD0 003BEFD0 00000000 */   nop
    /* 2BEFD4 003BEFD4 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2BEFD8 003BEFD8 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2BEFDC 003BEFDC 09F84000 */  jalr       $2
    /* 2BEFE0 003BEFE0 00000000 */   nop
    /* 2BEFE4 003BEFE4 000000AE */  sw         $0, 0x0($16)
  .L003BEFE8:
    /* 2BEFE8 003BEFE8 65000010 */  b          .L003BF180
    /* 2BEFEC 003BEFEC 2D100000 */   daddu     $2, $0, $0
  .L003BEFF0:
    /* 2BEFF0 003BEFF0 6400A38F */  lw         $3, 0x64($29)
    /* 2BEFF4 003BEFF4 0300023C */  lui        $2, (0x35000 >> 16)
    /* 2BEFF8 003BEFF8 00504234 */  ori        $2, $2, (0x35000 & 0xFFFF)
    /* 2BEFFC 003BEFFC 2B106200 */  sltu       $2, $3, $2
    /* 2BF000 003BF000 3C004014 */  bnez       $2, .L003BF0F4
    /* 2BF004 003BF004 00000000 */   nop
    /* 2BF008 003BF008 0300013C */  lui        $1, (0x37003 >> 16)
    /* 2BF00C 003BF00C 03702134 */  ori        $1, $1, (0x37003 & 0xFFFF)
    /* 2BF010 003BF010 2B086100 */  sltu       $1, $3, $1
    /* 2BF014 003BF014 37002010 */  beqz       $1, .L003BF0F4
    /* 2BF018 003BF018 00000000 */   nop
    /* 2BF01C 003BF01C 2C0C0F0C */  jal        func_003c30b0
    /* 2BF020 003BF020 2D206002 */   daddu     $4, $19, $0
    /* 2BF024 003BF024 0000038E */  lw         $3, 0x0($16)
    /* 2BF028 003BF028 21187100 */  addu       $3, $3, $17
    /* 2BF02C 003BF02C 17004010 */  beqz       $2, .L003BF08C
    /* 2BF030 003BF030 000062AC */   sw        $2, 0x0($3)
    /* 2BF034 003BF034 0400028E */  lw         $2, 0x4($16)
    /* 2BF038 003BF038 01005226 */  addiu      $18, $18, 0x1
    /* 2BF03C 003BF03C 01004224 */  addiu      $2, $2, 0x1
    /* 2BF040 003BF040 040002AE */  sw         $2, 0x4($16)
    /* 2BF044 003BF044 6C00A28F */  lw         $2, 0x6C($29)
    /* 2BF048 003BF048 2A104202 */  slt        $2, $18, $2
    /* 2BF04C 003BF04C D3FF4014 */  bnez       $2, .L003BEF9C
    /* 2BF050 003BF050 04003126 */   addiu     $17, $17, 0x4
    /* 2BF054 003BF054 B3FF0010 */  b          .L003BEF24
    /* 2BF058 003BF058 00000000 */   nop
  .L003BF05C:
    /* 2BF05C 003BF05C 2D880000 */  daddu      $17, $0, $0
  .L003BF060:
    /* 2BF060 003BF060 0000028E */  lw         $2, 0x0($16)
    /* 2BF064 003BF064 21105100 */  addu       $2, $2, $17
    /* 2BF068 003BF068 A00A0F0C */  jal        func_003c2a80
    /* 2BF06C 003BF06C 0000448C */   lw        $4, 0x0($2)
    /* 2BF070 003BF070 0400028E */  lw         $2, 0x4($16)
    /* 2BF074 003BF074 01005226 */  addiu      $18, $18, 0x1
    /* 2BF078 003BF078 2A104202 */  slt        $2, $18, $2
    /* 2BF07C 003BF07C F8FF4014 */  bnez       $2, .L003BF060
    /* 2BF080 003BF080 04003126 */   addiu     $17, $17, 0x4
    /* 2BF084 003BF084 D1FF0010 */  b          .L003BEFCC
    /* 2BF088 003BF088 0000048E */   lw        $4, 0x0($16)
  .L003BF08C:
    /* 2BF08C 003BF08C 0400028E */  lw         $2, 0x4($16)
    /* 2BF090 003BF090 2A100200 */  slt        $2, $0, $2
    /* 2BF094 003BF094 0B004014 */  bnez       $2, .L003BF0C4
    /* 2BF098 003BF098 2D900000 */   daddu     $18, $0, $0
    /* 2BF09C 003BF09C 0000048E */  lw         $4, 0x0($16)
  .L003BF0A0:
    /* 2BF0A0 003BF0A0 06008010 */  beqz       $4, .L003BF0BC
    /* 2BF0A4 003BF0A4 00000000 */   nop
    /* 2BF0A8 003BF0A8 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2BF0AC 003BF0AC EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2BF0B0 003BF0B0 09F84000 */  jalr       $2
    /* 2BF0B4 003BF0B4 00000000 */   nop
    /* 2BF0B8 003BF0B8 000000AE */  sw         $0, 0x0($16)
  .L003BF0BC:
    /* 2BF0BC 003BF0BC 30000010 */  b          .L003BF180
    /* 2BF0C0 003BF0C0 2D100000 */   daddu     $2, $0, $0
  .L003BF0C4:
    /* 2BF0C4 003BF0C4 2D880000 */  daddu      $17, $0, $0
  .L003BF0C8:
    /* 2BF0C8 003BF0C8 0000028E */  lw         $2, 0x0($16)
    /* 2BF0CC 003BF0CC 21105100 */  addu       $2, $2, $17
    /* 2BF0D0 003BF0D0 A00A0F0C */  jal        func_003c2a80
    /* 2BF0D4 003BF0D4 0000448C */   lw        $4, 0x0($2)
    /* 2BF0D8 003BF0D8 0400028E */  lw         $2, 0x4($16)
    /* 2BF0DC 003BF0DC 01005226 */  addiu      $18, $18, 0x1
    /* 2BF0E0 003BF0E0 2A104202 */  slt        $2, $18, $2
    /* 2BF0E4 003BF0E4 F8FF4014 */  bnez       $2, .L003BF0C8
    /* 2BF0E8 003BF0E8 04003126 */   addiu     $17, $17, 0x4
    /* 2BF0EC 003BF0EC ECFF0010 */  b          .L003BF0A0
    /* 2BF0F0 003BF0F0 0000048E */   lw        $4, 0x0($16)
  .L003BF0F4:
    /* 2BF0F4 003BF0F4 0400028E */  lw         $2, 0x4($16)
    /* 2BF0F8 003BF0F8 2A100200 */  slt        $2, $0, $2
    /* 2BF0FC 003BF0FC 0B004014 */  bnez       $2, .L003BF12C
    /* 2BF100 003BF100 2D900000 */   daddu     $18, $0, $0
    /* 2BF104 003BF104 0000048E */  lw         $4, 0x0($16)
  .L003BF108:
    /* 2BF108 003BF108 06008010 */  beqz       $4, .L003BF124
    /* 2BF10C 003BF10C 00000000 */   nop
    /* 2BF110 003BF110 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2BF114 003BF114 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2BF118 003BF118 09F84000 */  jalr       $2
    /* 2BF11C 003BF11C 00000000 */   nop
    /* 2BF120 003BF120 000000AE */  sw         $0, 0x0($16)
  .L003BF124:
    /* 2BF124 003BF124 16000010 */  b          .L003BF180
    /* 2BF128 003BF128 2D100000 */   daddu     $2, $0, $0
  .L003BF12C:
    /* 2BF12C 003BF12C 2D880000 */  daddu      $17, $0, $0
  .L003BF130:
    /* 2BF130 003BF130 0000028E */  lw         $2, 0x0($16)
    /* 2BF134 003BF134 21105100 */  addu       $2, $2, $17
    /* 2BF138 003BF138 A00A0F0C */  jal        func_003c2a80
    /* 2BF13C 003BF13C 0000448C */   lw        $4, 0x0($2)
    /* 2BF140 003BF140 0400028E */  lw         $2, 0x4($16)
    /* 2BF144 003BF144 01005226 */  addiu      $18, $18, 0x1
    /* 2BF148 003BF148 2A104202 */  slt        $2, $18, $2
    /* 2BF14C 003BF14C F8FF4014 */  bnez       $2, .L003BF130
    /* 2BF150 003BF150 04003126 */   addiu     $17, $17, 0x4
    /* 2BF154 003BF154 ECFF0010 */  b          .L003BF108
    /* 2BF158 003BF158 0000048E */   lw        $4, 0x0($16)
  .L003BF15C:
    /* 2BF15C 003BF15C 02000324 */  addiu      $3, $0, 0x2
    /* 2BF160 003BF160 0080023C */  lui        $2, (0x80000004 >> 16)
    /* 2BF164 003BF164 5000A3AF */  sw         $3, 0x50($29)
    /* 2BF168 003BF168 647D0F0C */  jal        func_003df590
    /* 2BF16C 003BF16C 04004434 */   ori       $4, $2, (0x80000004 & 0xFFFF)
    /* 2BF170 003BF170 5400A2AF */  sw         $2, 0x54($29)
    /* 2BF174 003BF174 347D0F0C */  jal        func_003df4d0
    /* 2BF178 003BF178 5000A427 */   addiu     $4, $29, 0x50
    /* 2BF17C 003BF17C 2D100000 */  daddu      $2, $0, $0
  .L003BF180:
    /* 2BF180 003BF180 4000BFDF */  ld         $31, 0x40($29)
    /* 2BF184 003BF184 3000B37B */  lq         $19, 0x30($29)
    /* 2BF188 003BF188 2000B27B */  lq         $18, 0x20($29)
    /* 2BF18C 003BF18C 1000B17B */  lq         $17, 0x10($29)
    /* 2BF190 003BF190 0000B07B */  lq         $16, 0x0($29)
    /* 2BF194 003BF194 0800E003 */  jr         $31
    /* 2BF198 003BF198 7000BD27 */   addiu     $29, $29, 0x70
    /* 2BF19C 003BF19C 00000000 */  nop
.size func_003bee80, 0x320
