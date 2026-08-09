.section .text
.set noat
.set noreorder
glabel func_002bcfb0
    /* 1BCFB0 002BCFB0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 1BCFB4 002BCFB4 3000BFFF */  sd         $31, 0x30($29)
    /* 1BCFB8 002BCFB8 2000B27F */  sq         $18, 0x20($29)
    /* 1BCFBC 002BCFBC 1000B17F */  sq         $17, 0x10($29)
    /* 1BCFC0 002BCFC0 0000B07F */  sq         $16, 0x0($29)
    /* 1BCFC4 002BCFC4 2D888000 */  daddu      $17, $4, $0
    /* 1BCFC8 002BCFC8 2D80A000 */  daddu      $16, $5, $0
    /* 1BCFCC 002BCFCC 0400A38C */  lw         $3, 0x4($5)
    /* 1BCFD0 002BCFD0 04006230 */  andi       $2, $3, 0x4
    /* 1BCFD4 002BCFD4 3D004010 */  beqz       $2, .L002BD0CC
    /* 1BCFD8 002BCFD8 00000000 */   nop
    /* 1BCFDC 002BCFDC 1000048E */  lw         $4, 0x10($16)
    /* 1BCFE0 002BCFE0 44E0090C */  jal        func_00278110
    /* 1BCFE4 002BCFE4 00000000 */   nop
    /* 1BCFE8 002BCFE8 00334230 */  andi       $2, $2, 0x3300
    /* 1BCFEC 002BCFEC 34004014 */  bnez       $2, .L002BD0C0
    /* 1BCFF0 002BCFF0 00000000 */   nop
    /* 1BCFF4 002BCFF4 10000426 */  addiu      $4, $16, 0x10
    /* 1BCFF8 002BCFF8 4CF50A0C */  jal        func_002bd530
    /* 1BCFFC 002BCFFC 00000000 */   nop
    /* 1BD000 002BD000 1400228E */  lw         $2, 0x14($17)
    /* 1BD004 002BD004 01004230 */  andi       $2, $2, 0x1
    /* 1BD008 002BD008 0B004014 */  bnez       $2, .L002BD038
    /* 1BD00C 002BD00C 00000000 */   nop
    /* 1BD010 002BD010 06002016 */  bnez       $17, .L002BD02C
    /* 1BD014 002BD014 00000000 */   nop
    /* 1BD018 002BD018 6400043C */  lui        $4, %hi(D_0063F2A0)
    /* 1BD01C 002BD01C A0F28424 */  addiu      $4, $4, %lo(D_0063F2A0)
    /* 1BD020 002BD020 8F050524 */  addiu      $5, $0, 0x58F
    /* 1BD024 002BD024 CCB5110C */  jal        func_0046d730
    /* 1BD028 002BD028 00000000 */   nop
  .L002BD02C:
    /* 1BD02C 002BD02C 1C00228E */  lw         $2, 0x1C($17)
    /* 1BD030 002BD030 04004234 */  ori        $2, $2, 0x4
    /* 1BD034 002BD034 1C0022AE */  sw         $2, 0x1C($17)
  .L002BD038:
    /* 1BD038 002BD038 2C00108E */  lw         $16, 0x2C($16)
    /* 1BD03C 002BD03C 01000224 */  addiu      $2, $0, 0x1
    /* 1BD040 002BD040 04180202 */  sllv       $3, $2, $16
    /* 1BD044 002BD044 1400228E */  lw         $2, 0x14($17)
    /* 1BD048 002BD048 24104300 */  and        $2, $2, $3
    /* 1BD04C 002BD04C 19004014 */  bnez       $2, .L002BD0B4
    /* 1BD050 002BD050 00000000 */   nop
    /* 1BD054 002BD054 06002016 */  bnez       $17, .L002BD070
    /* 1BD058 002BD058 00000000 */   nop
    /* 1BD05C 002BD05C 6400043C */  lui        $4, %hi(D_0063F2A0)
    /* 1BD060 002BD060 A0F28424 */  addiu      $4, $4, %lo(D_0063F2A0)
    /* 1BD064 002BD064 8F050524 */  addiu      $5, $0, 0x58F
    /* 1BD068 002BD068 CCB5110C */  jal        func_0046d730
    /* 1BD06C 002BD06C 00000000 */   nop
  .L002BD070:
    /* 1BD070 002BD070 04000006 */  bltz       $16, .L002BD084
    /* 1BD074 002BD074 00000000 */   nop
    /* 1BD078 002BD078 0C00012A */  slti       $1, $16, 0xC
    /* 1BD07C 002BD07C 06002014 */  bnez       $1, .L002BD098
    /* 1BD080 002BD080 00000000 */   nop
  .L002BD084:
    /* 1BD084 002BD084 6400043C */  lui        $4, %hi(D_0063F2A0)
    /* 1BD088 002BD088 A0F28424 */  addiu      $4, $4, %lo(D_0063F2A0)
    /* 1BD08C 002BD08C 90050524 */  addiu      $5, $0, 0x590
    /* 1BD090 002BD090 CCB5110C */  jal        func_0046d730
    /* 1BD094 002BD094 00000000 */   nop
  .L002BD098:
    /* 1BD098 002BD098 40101000 */  sll        $2, $16, 1
    /* 1BD09C 002BD09C 21105000 */  addu       $2, $2, $16
    /* 1BD0A0 002BD0A0 80100200 */  sll        $2, $2, 2
    /* 1BD0A4 002BD0A4 21182202 */  addu       $3, $17, $2
    /* 1BD0A8 002BD0A8 1C00628C */  lw         $2, 0x1C($3)
    /* 1BD0AC 002BD0AC 04004234 */  ori        $2, $2, 0x4
    /* 1BD0B0 002BD0B0 1C0062AC */  sw         $2, 0x1C($3)
  .L002BD0B4:
    /* 1BD0B4 002BD0B4 01000224 */  addiu      $2, $0, 0x1
    /* 1BD0B8 002BD0B8 40000010 */  b          .L002BD1BC
    /* 1BD0BC 002BD0BC 00000000 */   nop
  .L002BD0C0:
    /* 1BD0C0 002BD0C0 2D100000 */  daddu      $2, $0, $0
    /* 1BD0C4 002BD0C4 3D000010 */  b          .L002BD1BC
    /* 1BD0C8 002BD0C8 00000000 */   nop
  .L002BD0CC:
    /* 1BD0CC 002BD0CC 01006230 */  andi       $2, $3, 0x1
    /* 1BD0D0 002BD0D0 2B004010 */  beqz       $2, .L002BD180
    /* 1BD0D4 002BD0D4 00000000 */   nop
    /* 1BD0D8 002BD0D8 06002016 */  bnez       $17, .L002BD0F4
    /* 1BD0DC 002BD0DC 00000000 */   nop
    /* 1BD0E0 002BD0E0 6400043C */  lui        $4, %hi(D_0063F2A0)
    /* 1BD0E4 002BD0E4 A0F28424 */  addiu      $4, $4, %lo(D_0063F2A0)
    /* 1BD0E8 002BD0E8 87050524 */  addiu      $5, $0, 0x587
    /* 1BD0EC 002BD0EC CCB5110C */  jal        func_0046d730
    /* 1BD0F0 002BD0F0 00000000 */   nop
  .L002BD0F4:
    /* 1BD0F4 002BD0F4 1C00228E */  lw         $2, 0x1C($17)
    /* 1BD0F8 002BD0F8 02004230 */  andi       $2, $2, 0x2
    /* 1BD0FC 002BD0FC 04004014 */  bnez       $2, .L002BD110
    /* 1BD100 002BD100 00000000 */   nop
    /* 1BD104 002BD104 2D100000 */  daddu      $2, $0, $0
    /* 1BD108 002BD108 2C000010 */  b          .L002BD1BC
    /* 1BD10C 002BD10C 00000000 */   nop
  .L002BD110:
    /* 1BD110 002BD110 2C00128E */  lw         $18, 0x2C($16)
    /* 1BD114 002BD114 06002016 */  bnez       $17, .L002BD130
    /* 1BD118 002BD118 00000000 */   nop
    /* 1BD11C 002BD11C 6400043C */  lui        $4, %hi(D_0063F2A0)
    /* 1BD120 002BD120 A0F28424 */  addiu      $4, $4, %lo(D_0063F2A0)
    /* 1BD124 002BD124 87050524 */  addiu      $5, $0, 0x587
    /* 1BD128 002BD128 CCB5110C */  jal        func_0046d730
    /* 1BD12C 002BD12C 00000000 */   nop
  .L002BD130:
    /* 1BD130 002BD130 40101200 */  sll        $2, $18, 1
    /* 1BD134 002BD134 21105200 */  addu       $2, $2, $18
    /* 1BD138 002BD138 80100200 */  sll        $2, $2, 2
    /* 1BD13C 002BD13C 21102202 */  addu       $2, $17, $2
    /* 1BD140 002BD140 1C00428C */  lw         $2, 0x1C($2)
    /* 1BD144 002BD144 02004230 */  andi       $2, $2, 0x2
    /* 1BD148 002BD148 04004014 */  bnez       $2, .L002BD15C
    /* 1BD14C 002BD14C 00000000 */   nop
    /* 1BD150 002BD150 2D100000 */  daddu      $2, $0, $0
    /* 1BD154 002BD154 19000010 */  b          .L002BD1BC
    /* 1BD158 002BD158 00000000 */   nop
  .L002BD15C:
    /* 1BD15C 002BD15C 0400038E */  lw         $3, 0x4($16)
    /* 1BD160 002BD160 FEFF0224 */  addiu      $2, $0, -0x2
    /* 1BD164 002BD164 24106200 */  and        $2, $3, $2
    /* 1BD168 002BD168 040002AE */  sw         $2, 0x4($16)
    /* 1BD16C 002BD16C 10000426 */  addiu      $4, $16, 0x10
    /* 1BD170 002BD170 2C00058E */  lw         $5, 0x2C($16)
    /* 1BD174 002BD174 2000068E */  lw         $6, 0x20($16)
    /* 1BD178 002BD178 60F50A0C */  jal        func_002bd580
    /* 1BD17C 002BD17C 00000000 */   nop
  .L002BD180:
    /* 1BD180 002BD180 10000426 */  addiu      $4, $16, 0x10
    /* 1BD184 002BD184 98F50A0C */  jal        func_002bd660
    /* 1BD188 002BD188 00000000 */   nop
    /* 1BD18C 002BD18C 10000426 */  addiu      $4, $16, 0x10
    /* 1BD190 002BD190 84F50A0C */  jal        func_002bd610
    /* 1BD194 002BD194 00000000 */   nop
    /* 1BD198 002BD198 07004014 */  bnez       $2, .L002BD1B8
    /* 1BD19C 002BD19C 00000000 */   nop
    /* 1BD1A0 002BD1A0 10000426 */  addiu      $4, $16, 0x10
    /* 1BD1A4 002BD1A4 CCF50A0C */  jal        func_002bd730
    /* 1BD1A8 002BD1A8 00000000 */   nop
    /* 1BD1AC 002BD1AC 0400028E */  lw         $2, 0x4($16)
    /* 1BD1B0 002BD1B0 04004234 */  ori        $2, $2, 0x4
    /* 1BD1B4 002BD1B4 040002AE */  sw         $2, 0x4($16)
  .L002BD1B8:
    /* 1BD1B8 002BD1B8 2D100000 */  daddu      $2, $0, $0
  .L002BD1BC:
    /* 1BD1BC 002BD1BC 3000BFDF */  ld         $31, 0x30($29)
    /* 1BD1C0 002BD1C0 2000B27B */  lq         $18, 0x20($29)
    /* 1BD1C4 002BD1C4 1000B17B */  lq         $17, 0x10($29)
    /* 1BD1C8 002BD1C8 0000B07B */  lq         $16, 0x0($29)
    /* 1BD1CC 002BD1CC 4000BD27 */  addiu      $29, $29, 0x40
    /* 1BD1D0 002BD1D0 0800E003 */  jr         $31
    /* 1BD1D4 002BD1D4 00000000 */   nop
    /* 1BD1D8 002BD1D8 00000000 */  nop
    /* 1BD1DC 002BD1DC 00000000 */  nop
.size func_002bcfb0, 0x230
