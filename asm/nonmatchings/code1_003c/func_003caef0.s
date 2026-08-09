.section .text
.set noat
.set noreorder
glabel func_003caef0
    /* 2CAEF0 003CAEF0 40FEBD27 */  addiu      $29, $29, -0x1C0
    /* 2CAEF4 003CAEF4 8000BFFF */  sd         $31, 0x80($29)
    /* 2CAEF8 003CAEF8 7000B67F */  sq         $22, 0x70($29)
    /* 2CAEFC 003CAEFC 6000B57F */  sq         $21, 0x60($29)
    /* 2CAF00 003CAF00 5000B47F */  sq         $20, 0x50($29)
    /* 2CAF04 003CAF04 4000B37F */  sq         $19, 0x40($29)
    /* 2CAF08 003CAF08 2DA08000 */  daddu      $20, $4, $0
    /* 2CAF0C 003CAF0C 3000B27F */  sq         $18, 0x30($29)
    /* 2CAF10 003CAF10 2000B17F */  sq         $17, 0x20($29)
    /* 2CAF14 003CAF14 1000B07F */  sq         $16, 0x10($29)
    /* 2CAF18 003CAF18 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 2CAF1C 003CAF1C 14B7828F */  lw         $2, -0x48EC($28)
    /* 2CAF20 003CAF20 21808202 */  addu       $16, $20, $2
    /* 2CAF24 003CAF24 0400028E */  lw         $2, 0x4($16)
    /* 2CAF28 003CAF28 09F84000 */  jalr       $2
    /* 2CAF2C 003CAF2C 00000000 */   nop
    /* 2CAF30 003CAF30 93004010 */  beqz       $2, .L003CB180
    /* 2CAF34 003CAF34 00000000 */   nop
    /* 2CAF38 003CAF38 01008292 */  lbu        $2, 0x1($20)
    /* 2CAF3C 003CAF3C 80004228 */  slti       $2, $2, 0x80
    /* 2CAF40 003CAF40 28004014 */  bnez       $2, .L003CAFE4
    /* 2CAF44 003CAF44 00000000 */   nop
    /* 2CAF48 003CAF48 0000168E */  lw         $22, 0x0($16)
    /* 2CAF4C 003CAF4C 2300C012 */  beqz       $22, .L003CAFDC
    /* 2CAF50 003CAF50 0400958E */   lw        $21, 0x4($20)
    /* 2CAF54 003CAF54 2100A012 */  beqz       $21, .L003CAFDC
    /* 2CAF58 003CAF58 00000000 */   nop
    /* 2CAF5C 003CAF5C 2C00928E */  lw         $18, 0x2C($20)
    /* 2CAF60 003CAF60 140094C6 */  lwc1       $f20, 0x14($20)
    /* 2CAF64 003CAF64 2C009126 */  addiu      $17, $20, 0x2C
    /* 2CAF68 003CAF68 20005112 */  beq        $18, $17, .L003CAFEC
    /* 2CAF6C 003CAF6C 2D980000 */   daddu     $19, $0, $0
    /* 2CAF70 003CAF70 8800103C */  lui        $16, %hi(jtbl_008873FC)
    /* 2CAF74 003CAF74 FC731026 */  addiu      $16, $16, %lo(jtbl_008873FC)
  .L003CAF78:
    /* 2CAF78 003CAF78 F4FF4526 */  addiu      $5, $18, -0xC
    /* 2CAF7C 003CAF7C 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2CAF80 003CAF80 0000528E */  lw         $18, 0x0($18)
    /* 2CAF84 003CAF84 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2CAF88 003CAF88 0C00A48C */  lw         $4, 0xC($5)
    /* 2CAF8C 003CAF8C 1000A28C */  lw         $2, 0x10($5)
    /* 2CAF90 003CAF90 000044AC */  sw         $4, 0x0($2)
    /* 2CAF94 003CAF94 1000A48C */  lw         $4, 0x10($5)
    /* 2CAF98 003CAF98 0C00A28C */  lw         $2, 0xC($5)
    /* 2CAF9C 003CAF9C 040044AC */  sw         $4, 0x4($2)
    /* 2CAFA0 003CAFA0 0000A48C */  lw         $4, 0x0($5)
    /* 2CAFA4 003CAFA4 0400A28C */  lw         $2, 0x4($5)
    /* 2CAFA8 003CAFA8 000044AC */  sw         $4, 0x0($2)
    /* 2CAFAC 003CAFAC 0400A48C */  lw         $4, 0x4($5)
    /* 2CAFB0 003CAFB0 0000A28C */  lw         $2, 0x0($5)
    /* 2CAFB4 003CAFB4 040044AC */  sw         $4, 0x4($2)
    /* 2CAFB8 003CAFB8 18B7848F */  lw         $4, -0x48E8($28)
    /* 2CAFBC 003CAFBC 0000028E */  lw         $2, 0x0($16)
    /* 2CAFC0 003CAFC0 21186400 */  addu       $3, $3, $4
    /* 2CAFC4 003CAFC4 09F84000 */  jalr       $2
    /* 2CAFC8 003CAFC8 0400648C */   lw        $4, 0x4($3)
    /* 2CAFCC 003CAFCC EAFF5116 */  bne        $18, $17, .L003CAF78
    /* 2CAFD0 003CAFD0 00000000 */   nop
    /* 2CAFD4 003CAFD4 06000010 */  b          .L003CAFF0
    /* 2CAFD8 003CAFD8 2D20A002 */   daddu     $4, $21, $0
  .L003CAFDC:
    /* 2CAFDC 003CAFDC 72000010 */  b          .L003CB1A8
    /* 2CAFE0 003CAFE0 2D108002 */   daddu     $2, $20, $0
  .L003CAFE4:
    /* 2CAFE4 003CAFE4 70000010 */  b          .L003CB1A8
    /* 2CAFE8 003CAFE8 2D108002 */   daddu     $2, $20, $0
  .L003CAFEC:
    /* 2CAFEC 003CAFEC 2D20A002 */  daddu      $4, $21, $0
  .L003CAFF0:
    /* 2CAFF0 003CAFF0 C0A50F0C */  jal        func_003e9700
    /* 2CAFF4 003CAFF4 00000000 */   nop
    /* 2CAFF8 003CAFF8 300043C4 */  lwc1       $f3, 0x30($2)
    /* 2CAFFC 003CAFFC 8800103C */  lui        $16, %hi(D_008873F8)
    /* 2CB000 003CB000 340042C4 */  lwc1       $f2, 0x34($2)
    /* 2CB004 003CB004 B401A527 */  addiu      $5, $29, 0x1B4
    /* 2CB008 003CB008 380041C4 */  lwc1       $f1, 0x38($2)
    /* 2CB00C 003CB00C A401A427 */  addiu      $4, $29, 0x1A4
    /* 2CB010 003CB010 B801A327 */  addiu      $3, $29, 0x1B8
    /* 2CB014 003CB014 1C00D18E */  lw         $17, 0x1C($22)
    /* 2CB018 003CB018 F8731026 */  addiu      $16, $16, %lo(D_008873F8)
    /* 2CB01C 003CB01C 00181446 */  add.s      $f0, $f3, $f20
    /* 2CB020 003CB020 A801A227 */  addiu      $2, $29, 0x1A8
    /* 2CB024 003CB024 B401A2E7 */  swc1       $f2, 0x1B4($29)
    /* 2CB028 003CB028 A001A0E7 */  swc1       $f0, 0x1A0($29)
    /* 2CB02C 003CB02C 01181446 */  sub.s      $f0, $f3, $f20
    /* 2CB030 003CB030 0000A2C4 */  lwc1       $f2, 0x0($5)
    /* 2CB034 003CB034 B001A0E7 */  swc1       $f0, 0x1B0($29)
    /* 2CB038 003CB038 B801A1E7 */  swc1       $f1, 0x1B8($29)
    /* 2CB03C 003CB03C 000061C4 */  lwc1       $f1, 0x0($3)
    /* 2CB040 003CB040 00101446 */  add.s      $f0, $f2, $f20
    /* 2CB044 003CB044 000080E4 */  swc1       $f0, 0x0($4)
    /* 2CB048 003CB048 01101446 */  sub.s      $f0, $f2, $f20
    /* 2CB04C 003CB04C 0000A0E4 */  swc1       $f0, 0x0($5)
    /* 2CB050 003CB050 00081446 */  add.s      $f0, $f1, $f20
    /* 2CB054 003CB054 000040E4 */  swc1       $f0, 0x0($2)
    /* 2CB058 003CB058 01081446 */  sub.s      $f0, $f1, $f20
    /* 2CB05C 003CB05C 000060E4 */  swc1       $f0, 0x0($3)
  .L003CB060:
    /* 2CB060 003CB060 0000228E */  lw         $2, 0x0($17)
    /* 2CB064 003CB064 20004004 */  bltz       $2, .L003CB0E8
    /* 2CB068 003CB068 00000000 */   nop
    /* 2CB06C 003CB06C 21105D00 */  addu       $2, $2, $29
    /* 2CB070 003CB070 B00141C4 */  lwc1       $f1, 0x1B0($2)
    /* 2CB074 003CB074 100020C6 */  lwc1       $f0, 0x10($17)
    /* 2CB078 003CB078 34080046 */  c.lt.s     $f1, $f0
    /* 2CB07C 003CB07C 0E000045 */  bc1f       .L003CB0B8
    /* 2CB080 003CB080 2D182002 */   daddu     $3, $17, $0
    /* 2CB084 003CB084 0000628C */  lw         $2, 0x0($3)
    /* 2CB088 003CB088 140060C4 */  lwc1       $f0, 0x14($3)
    /* 2CB08C 003CB08C 21105D00 */  addu       $2, $2, $29
    /* 2CB090 003CB090 A00141C4 */  lwc1       $f1, 0x1A0($2)
    /* 2CB094 003CB094 34000146 */  c.lt.s     $f0, $f1
    /* 2CB098 003CB098 0F000045 */  bc1f       .L003CB0D8
    /* 2CB09C 003CB09C 0800318E */   lw        $17, 0x8($17)
    /* 2CB0A0 003CB0A0 0C00638C */  lw         $3, 0xC($3)
    /* 2CB0A4 003CB0A4 01007326 */  addiu      $19, $19, 0x1
    /* 2CB0A8 003CB0A8 80101300 */  sll        $2, $19, 2
    /* 2CB0AC 003CB0AC 21105D00 */  addu       $2, $2, $29
    /* 2CB0B0 003CB0B0 09000010 */  b          .L003CB0D8
    /* 2CB0B4 003CB0B4 900043AC */   sw        $3, 0x90($2)
  .L003CB0B8:
    /* 2CB0B8 003CB0B8 0000228E */  lw         $2, 0x0($17)
    /* 2CB0BC 003CB0BC 140020C6 */  lwc1       $f0, 0x14($17)
    /* 2CB0C0 003CB0C0 21105D00 */  addu       $2, $2, $29
    /* 2CB0C4 003CB0C4 A00141C4 */  lwc1       $f1, 0x1A0($2)
    /* 2CB0C8 003CB0C8 34000146 */  c.lt.s     $f0, $f1
    /* 2CB0CC 003CB0CC 26000045 */  bc1f       .L003CB168
    /* 2CB0D0 003CB0D0 00000000 */   nop
    /* 2CB0D4 003CB0D4 0C00318E */  lw         $17, 0xC($17)
  .L003CB0D8:
    /* 2CB0D8 003CB0D8 E1FF6106 */  bgez       $19, .L003CB060
    /* 2CB0DC 003CB0DC 00000000 */   nop
    /* 2CB0E0 003CB0E0 BEFF0010 */  b          .L003CAFDC
    /* 2CB0E4 003CB0E4 00000000 */   nop
  .L003CB0E8:
    /* 2CB0E8 003CB0E8 18B7868F */  lw         $6, -0x48E8($28)
    /* 2CB0EC 003CB0EC 8800043C */  lui        $4, %hi(D_008872E0)
    /* 2CB0F0 003CB0F0 0300033C */  lui        $3, (0x30507 >> 16)
    /* 2CB0F4 003CB0F4 E0728424 */  addiu      $4, $4, %lo(D_008872E0)
    /* 2CB0F8 003CB0F8 07056534 */  ori        $5, $3, (0x30507 & 0xFFFF)
    /* 2CB0FC 003CB0FC 0000028E */  lw         $2, 0x0($16)
    /* 2CB100 003CB100 21188600 */  addu       $3, $4, $6
    /* 2CB104 003CB104 09F84000 */  jalr       $2
    /* 2CB108 003CB108 0400648C */   lw        $4, 0x4($3)
    /* 2CB10C 003CB10C 140051AC */  sw         $17, 0x14($2)
    /* 2CB110 003CB110 80181300 */  sll        $3, $19, 2
    /* 2CB114 003CB114 080054AC */  sw         $20, 0x8($2)
    /* 2CB118 003CB118 40002726 */  addiu      $7, $17, 0x40
    /* 2CB11C 003CB11C 4000268E */  lw         $6, 0x40($17)
    /* 2CB120 003CB120 21187D00 */  addu       $3, $3, $29
    /* 2CB124 003CB124 2C008526 */  addiu      $5, $20, 0x2C
    /* 2CB128 003CB128 0C004424 */  addiu      $4, $2, 0xC
    /* 2CB12C 003CB12C FFFF7326 */  addiu      $19, $19, -0x1
    /* 2CB130 003CB130 000046AC */  sw         $6, 0x0($2)
    /* 2CB134 003CB134 040047AC */  sw         $7, 0x4($2)
    /* 2CB138 003CB138 4000268E */  lw         $6, 0x40($17)
    /* 2CB13C 003CB13C 0400C2AC */  sw         $2, 0x4($6)
    /* 2CB140 003CB140 400022AE */  sw         $2, 0x40($17)
    /* 2CB144 003CB144 9000718C */  lw         $17, 0x90($3)
    /* 2CB148 003CB148 2C00838E */  lw         $3, 0x2C($20)
    /* 2CB14C 003CB14C 0C0043AC */  sw         $3, 0xC($2)
    /* 2CB150 003CB150 100045AC */  sw         $5, 0x10($2)
    /* 2CB154 003CB154 2C00828E */  lw         $2, 0x2C($20)
    /* 2CB158 003CB158 040044AC */  sw         $4, 0x4($2)
    /* 2CB15C 003CB15C DEFF0010 */  b          .L003CB0D8
    /* 2CB160 003CB160 2C0084AE */   sw        $4, 0x2C($20)
    /* 2CB164 003CB164 00000000 */  nop
  .L003CB168:
    /* 2CB168 003CB168 80101300 */  sll        $2, $19, 2
    /* 2CB16C 003CB16C 21105D00 */  addu       $2, $2, $29
    /* 2CB170 003CB170 9000518C */  lw         $17, 0x90($2)
    /* 2CB174 003CB174 D8FF0010 */  b          .L003CB0D8
    /* 2CB178 003CB178 FFFF7326 */   addiu     $19, $19, -0x1
    /* 2CB17C 003CB17C 00000000 */  nop
  .L003CB180:
    /* 2CB180 003CB180 02000224 */  addiu      $2, $0, 0x2
    /* 2CB184 003CB184 9801A2AF */  sw         $2, 0x198($29)
    /* 2CB188 003CB188 0080023C */  lui        $2, (0x80000016 >> 16)
    /* 2CB18C 003CB18C 647D0F0C */  jal        func_003df590
    /* 2CB190 003CB190 16004434 */   ori       $4, $2, (0x80000016 & 0xFFFF)
    /* 2CB194 003CB194 9C01A2AF */  sw         $2, 0x19C($29)
    /* 2CB198 003CB198 347D0F0C */  jal        func_003df4d0
    /* 2CB19C 003CB19C 9801A427 */   addiu     $4, $29, 0x198
    /* 2CB1A0 003CB1A0 8EFF0010 */  b          .L003CAFDC
    /* 2CB1A4 003CB1A4 00000000 */   nop
  .L003CB1A8:
    /* 2CB1A8 003CB1A8 8000BFDF */  ld         $31, 0x80($29)
    /* 2CB1AC 003CB1AC 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 2CB1B0 003CB1B0 7000B67B */  lq         $22, 0x70($29)
    /* 2CB1B4 003CB1B4 6000B57B */  lq         $21, 0x60($29)
    /* 2CB1B8 003CB1B8 5000B47B */  lq         $20, 0x50($29)
    /* 2CB1BC 003CB1BC 4000B37B */  lq         $19, 0x40($29)
    /* 2CB1C0 003CB1C0 3000B27B */  lq         $18, 0x30($29)
    /* 2CB1C4 003CB1C4 2000B17B */  lq         $17, 0x20($29)
    /* 2CB1C8 003CB1C8 1000B07B */  lq         $16, 0x10($29)
    /* 2CB1CC 003CB1CC 0800E003 */  jr         $31
    /* 2CB1D0 003CB1D0 C001BD27 */   addiu     $29, $29, 0x1C0
    /* 2CB1D4 003CB1D4 00000000 */  nop
    /* 2CB1D8 003CB1D8 00000000 */  nop
    /* 2CB1DC 003CB1DC 00000000 */  nop
.size func_003caef0, 0x2f0
