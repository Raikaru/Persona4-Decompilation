.section .text
.set noat
.set noreorder
glabel func_002afbc0
    /* 1AFBC0 002AFBC0 90FFBD27 */  addiu      $29, $29, -0x70
    /* 1AFBC4 002AFBC4 5000BFFF */  sd         $31, 0x50($29)
    /* 1AFBC8 002AFBC8 4000B47F */  sq         $20, 0x40($29)
    /* 1AFBCC 002AFBCC 3000B37F */  sq         $19, 0x30($29)
    /* 1AFBD0 002AFBD0 2000B27F */  sq         $18, 0x20($29)
    /* 1AFBD4 002AFBD4 1000B17F */  sq         $17, 0x10($29)
    /* 1AFBD8 002AFBD8 0000B07F */  sq         $16, 0x0($29)
    /* 1AFBDC 002AFBDC 2D988000 */  daddu      $19, $4, $0
    /* 1AFBE0 002AFBE0 3800918C */  lw         $17, 0x38($4)
    /* 1AFBE4 002AFBE4 FF000424 */  addiu      $4, $0, 0xFF
    /* 1AFBE8 002AFBE8 2D288000 */  daddu      $5, $4, $0
    /* 1AFBEC 002AFBEC 2D308000 */  daddu      $6, $4, $0
    /* 1AFBF0 002AFBF0 2D388000 */  daddu      $7, $4, $0
    /* 1AFBF4 002AFBF4 8CCA0A0C */  jal        func_002b2a30
    /* 1AFBF8 002AFBF8 00000000 */   nop
    /* 1AFBFC 002AFBFC 2D904000 */  daddu      $18, $2, $0
    /* 1AFC00 002AFC00 FC42023C */  lui        $2, (0x42FC0000 >> 16)
    /* 1AFC04 002AFC04 00608244 */  mtc1       $2, $f12
    /* 1AFC08 002AFC08 A841023C */  lui        $2, (0x41A80000 >> 16)
    /* 1AFC0C 002AFC0C 00708244 */  mtc1       $2, $f14
    /* 1AFC10 002AFC10 B041023C */  lui        $2, (0x41B00000 >> 16)
    /* 1AFC14 002AFC14 00788244 */  mtc1       $2, $f15
    /* 1AFC18 002AFC18 6000A427 */  addiu      $4, $29, 0x60
    /* 1AFC1C 002AFC1C 2D280000 */  daddu      $5, $0, $0
    /* 1AFC20 002AFC20 46630046 */  mov.s      $f13, $f12
    /* 1AFC24 002AFC24 F4CA0A0C */  jal        func_002b2bd0
    /* 1AFC28 002AFC28 00000000 */   nop
    /* 1AFC2C 002AFC2C 6000A1C7 */  lwc1       $f1, 0x60($29)
    /* 1AFC30 002AFC30 6400A0C7 */  lwc1       $f0, 0x64($29)
    /* 1AFC34 002AFC34 6800A1E7 */  swc1       $f1, 0x68($29)
    /* 1AFC38 002AFC38 6C00A0E7 */  swc1       $f0, 0x6C($29)
    /* 1AFC3C 002AFC3C 5CB5828F */  lw         $2, -0x4AA4($28)
    /* 1AFC40 002AFC40 04004014 */  bnez       $2, .L002AFC54
    /* 1AFC44 002AFC44 00000000 */   nop
    /* 1AFC48 002AFC48 2D100000 */  daddu      $2, $0, $0
    /* 1AFC4C 002AFC4C 69010010 */  b          .L002B01F4
    /* 1AFC50 002AFC50 00000000 */   nop
  .L002AFC54:
    /* 1AFC54 002AFC54 17140424 */  addiu      $4, $0, 0x1417
    /* 1AFC58 002AFC58 CC18040C */  jal        func_00106330
    /* 1AFC5C 002AFC5C 00000000 */   nop
    /* 1AFC60 002AFC60 04004010 */  beqz       $2, .L002AFC74
    /* 1AFC64 002AFC64 00000000 */   nop
    /* 1AFC68 002AFC68 2D100000 */  daddu      $2, $0, $0
    /* 1AFC6C 002AFC6C 61010010 */  b          .L002B01F4
    /* 1AFC70 002AFC70 00000000 */   nop
  .L002AFC74:
    /* 1AFC74 002AFC74 44012382 */  lb         $3, 0x144($17)
    /* 1AFC78 002AFC78 C6006014 */  bnez       $3, .L002AFF94
    /* 1AFC7C 002AFC7C 00000000 */   nop
    /* 1AFC80 002AFC80 16140424 */  addiu      $4, $0, 0x1416
    /* 1AFC84 002AFC84 CC18040C */  jal        func_00106330
    /* 1AFC88 002AFC88 00000000 */   nop
    /* 1AFC8C 002AFC8C 07004014 */  bnez       $2, .L002AFCAC
    /* 1AFC90 002AFC90 00000000 */   nop
    /* 1AFC94 002AFC94 43012282 */  lb         $2, 0x143($17)
    /* 1AFC98 002AFC98 04004014 */  bnez       $2, .L002AFCAC
    /* 1AFC9C 002AFC9C 00000000 */   nop
    /* 1AFCA0 002AFCA0 2D100000 */  daddu      $2, $0, $0
    /* 1AFCA4 002AFCA4 53010010 */  b          .L002B01F4
    /* 1AFCA8 002AFCA8 00000000 */   nop
  .L002AFCAC:
    /* 1AFCAC 002AFCAC 5A012282 */  lb         $2, 0x15A($17)
    /* 1AFCB0 002AFCB0 04004014 */  bnez       $2, .L002AFCC4
    /* 1AFCB4 002AFCB4 00000000 */   nop
    /* 1AFCB8 002AFCB8 2D100000 */  daddu      $2, $0, $0
    /* 1AFCBC 002AFCBC 4D010010 */  b          .L002B01F4
    /* 1AFCC0 002AFCC0 00000000 */   nop
  .L002AFCC4:
    /* 1AFCC4 002AFCC4 40012292 */  lbu        $2, 0x140($17)
    /* 1AFCC8 002AFCC8 06004004 */  bltz       $2, .L002AFCE4
    /* 1AFCCC 002AFCCC 00000000 */   nop
    /* 1AFCD0 002AFCD0 00008244 */  mtc1       $2, $f0
    /* 1AFCD4 002AFCD4 00000000 */  nop
    /* 1AFCD8 002AFCD8 E0008046 */  cvt.s.w    $f3, $f0
    /* 1AFCDC 002AFCDC 08000010 */  b          .L002AFD00
    /* 1AFCE0 002AFCE0 00000000 */   nop
  .L002AFCE4:
    /* 1AFCE4 002AFCE4 42180200 */  srl        $3, $2, 1
    /* 1AFCE8 002AFCE8 01004230 */  andi       $2, $2, 0x1
    /* 1AFCEC 002AFCEC 25186200 */  or         $3, $3, $2
    /* 1AFCF0 002AFCF0 00008344 */  mtc1       $3, $f0
    /* 1AFCF4 002AFCF4 00000000 */  nop
    /* 1AFCF8 002AFCF8 E0008046 */  cvt.s.w    $f3, $f0
    /* 1AFCFC 002AFCFC C0180346 */  add.s      $f3, $f3, $f3
  .L002AFD00:
    /* 1AFD00 002AFD00 9041023C */  lui        $2, (0x41900000 >> 16)
    /* 1AFD04 002AFD04 00108244 */  mtc1       $2, $f2
    /* 1AFD08 002AFD08 E040023C */  lui        $2, (0x40E00000 >> 16)
    /* 1AFD0C 002AFD0C 00088244 */  mtc1       $2, $f1
    /* 1AFD10 002AFD10 00008044 */  mtc1       $0, $f0
    /* 1AFD14 002AFD14 00000000 */  nop
    /* 1AFD18 002AFD18 18000146 */  adda.s     $f0, $f1
    /* 1AFD1C 002AFD1C 5C100346 */  madd.s     $f1, $f2, $f3
    /* 1AFD20 002AFD20 6800A0C7 */  lwc1       $f0, 0x68($29)
    /* 1AFD24 002AFD24 40080046 */  add.s      $f1, $f1, $f0
    /* 1AFD28 002AFD28 70B58393 */  lbu        $3, -0x4A90($28)
    /* 1AFD2C 002AFD2C C0100300 */  sll        $2, $3, 3
    /* 1AFD30 002AFD30 21104300 */  addu       $2, $2, $3
    /* 1AFD34 002AFD34 40100200 */  sll        $2, $2, 1
    /* 1AFD38 002AFD38 00008244 */  mtc1       $2, $f0
    /* 1AFD3C 002AFD3C 00000000 */  nop
    /* 1AFD40 002AFD40 20008046 */  cvt.s.w    $f0, $f0
    /* 1AFD44 002AFD44 41080046 */  sub.s      $f1, $f1, $f0
    /* 1AFD48 002AFD48 7041023C */  lui        $2, (0x41700000 >> 16)
    /* 1AFD4C 002AFD4C 00008244 */  mtc1       $2, $f0
    /* 1AFD50 002AFD50 00000000 */  nop
    /* 1AFD54 002AFD54 40000146 */  add.s      $f1, $f0, $f1
    /* 1AFD58 002AFD58 100020C6 */  lwc1       $f0, 0x10($17)
    /* 1AFD5C 002AFD5C 40000146 */  add.s      $f1, $f0, $f1
    /* 1AFD60 002AFD60 2041023C */  lui        $2, (0x41200000 >> 16)
    /* 1AFD64 002AFD64 00008244 */  mtc1       $2, $f0
    /* 1AFD68 002AFD68 00000000 */  nop
    /* 1AFD6C 002AFD6C 01080046 */  sub.s      $f0, $f1, $f0
    /* 1AFD70 002AFD70 080020E6 */  swc1       $f0, 0x8($17)
    /* 1AFD74 002AFD74 41012292 */  lbu        $2, 0x141($17)
    /* 1AFD78 002AFD78 06004004 */  bltz       $2, .L002AFD94
    /* 1AFD7C 002AFD7C 00000000 */   nop
    /* 1AFD80 002AFD80 00008244 */  mtc1       $2, $f0
    /* 1AFD84 002AFD84 00000000 */  nop
    /* 1AFD88 002AFD88 E0008046 */  cvt.s.w    $f3, $f0
    /* 1AFD8C 002AFD8C 08000010 */  b          .L002AFDB0
    /* 1AFD90 002AFD90 00000000 */   nop
  .L002AFD94:
    /* 1AFD94 002AFD94 42180200 */  srl        $3, $2, 1
    /* 1AFD98 002AFD98 01004230 */  andi       $2, $2, 0x1
    /* 1AFD9C 002AFD9C 25186200 */  or         $3, $3, $2
    /* 1AFDA0 002AFDA0 00008344 */  mtc1       $3, $f0
    /* 1AFDA4 002AFDA4 00000000 */  nop
    /* 1AFDA8 002AFDA8 E0008046 */  cvt.s.w    $f3, $f0
    /* 1AFDAC 002AFDAC C0180346 */  add.s      $f3, $f3, $f3
  .L002AFDB0:
    /* 1AFDB0 002AFDB0 9041023C */  lui        $2, (0x41900000 >> 16)
    /* 1AFDB4 002AFDB4 00108244 */  mtc1       $2, $f2
    /* 1AFDB8 002AFDB8 6343023C */  lui        $2, (0x43630000 >> 16)
    /* 1AFDBC 002AFDBC 00088244 */  mtc1       $2, $f1
    /* 1AFDC0 002AFDC0 00008044 */  mtc1       $0, $f0
    /* 1AFDC4 002AFDC4 00000000 */  nop
    /* 1AFDC8 002AFDC8 18000146 */  adda.s     $f0, $f1
    /* 1AFDCC 002AFDCC 5C100346 */  madd.s     $f1, $f2, $f3
    /* 1AFDD0 002AFDD0 6C00A0C7 */  lwc1       $f0, 0x6C($29)
    /* 1AFDD4 002AFDD4 40080046 */  add.s      $f1, $f1, $f0
    /* 1AFDD8 002AFDD8 6CB58393 */  lbu        $3, -0x4A94($28)
    /* 1AFDDC 002AFDDC C0100300 */  sll        $2, $3, 3
    /* 1AFDE0 002AFDE0 21104300 */  addu       $2, $2, $3
    /* 1AFDE4 002AFDE4 40100200 */  sll        $2, $2, 1
    /* 1AFDE8 002AFDE8 00008244 */  mtc1       $2, $f0
    /* 1AFDEC 002AFDEC 00000000 */  nop
    /* 1AFDF0 002AFDF0 20008046 */  cvt.s.w    $f0, $f0
    /* 1AFDF4 002AFDF4 41080046 */  sub.s      $f1, $f1, $f0
    /* 1AFDF8 002AFDF8 7041023C */  lui        $2, (0x41700000 >> 16)
    /* 1AFDFC 002AFDFC 00008244 */  mtc1       $2, $f0
    /* 1AFE00 002AFE00 00000000 */  nop
    /* 1AFE04 002AFE04 40000146 */  add.s      $f1, $f0, $f1
    /* 1AFE08 002AFE08 140020C6 */  lwc1       $f0, 0x14($17)
    /* 1AFE0C 002AFE0C 40000146 */  add.s      $f1, $f0, $f1
    /* 1AFE10 002AFE10 8041023C */  lui        $2, (0x41800000 >> 16)
    /* 1AFE14 002AFE14 00008244 */  mtc1       $2, $f0
    /* 1AFE18 002AFE18 00000000 */  nop
    /* 1AFE1C 002AFE1C 00000146 */  add.s      $f0, $f0, $f1
    /* 1AFE20 002AFE20 0C0020E6 */  swc1       $f0, 0xC($17)
    /* 1AFE24 002AFE24 4C012382 */  lb         $3, 0x14C($17)
    /* 1AFE28 002AFE28 01000224 */  addiu      $2, $0, 0x1
    /* 1AFE2C 002AFE2C 46006214 */  bne        $3, $2, .L002AFF48
    /* 1AFE30 002AFE30 00000000 */   nop
    /* 1AFE34 002AFE34 A054050C */  jal        func_00155280
    /* 1AFE38 002AFE38 00000000 */   nop
    /* 1AFE3C 002AFE3C 47004390 */  lbu        $3, 0x47($2)
    /* 1AFE40 002AFE40 59012282 */  lb         $2, 0x159($17)
    /* 1AFE44 002AFE44 21104300 */  addu       $2, $2, $3
    /* 1AFE48 002AFE48 FF005030 */  andi       $16, $2, 0xFF
    /* 1AFE4C 002AFE4C A054050C */  jal        func_00155280
    /* 1AFE50 002AFE50 00000000 */   nop
    /* 1AFE54 002AFE54 46004390 */  lbu        $3, 0x46($2)
    /* 1AFE58 002AFE58 58012282 */  lb         $2, 0x158($17)
    /* 1AFE5C 002AFE5C 21104300 */  addu       $2, $2, $3
    /* 1AFE60 002AFE60 FF005430 */  andi       $20, $2, 0xFF
    /* 1AFE64 002AFE64 16140424 */  addiu      $4, $0, 0x1416
    /* 1AFE68 002AFE68 CC18040C */  jal        func_00106330
    /* 1AFE6C 002AFE6C 00000000 */   nop
    /* 1AFE70 002AFE70 10004014 */  bnez       $2, .L002AFEB4
    /* 1AFE74 002AFE74 00000000 */   nop
    /* 1AFE78 002AFE78 FF008432 */  andi       $4, $20, 0xFF
    /* 1AFE7C 002AFE7C FF000232 */  andi       $2, $16, 0xFF
    /* 1AFE80 002AFE80 40180200 */  sll        $3, $2, 1
    /* 1AFE84 002AFE84 68B5828F */  lw         $2, -0x4A98($28)
    /* 1AFE88 002AFE88 21104300 */  addu       $2, $2, $3
    /* 1AFE8C 002AFE8C 00004394 */  lhu        $3, 0x0($2)
    /* 1AFE90 002AFE90 01000224 */  addiu      $2, $0, 0x1
    /* 1AFE94 002AFE94 04108200 */  sllv       $2, $2, $4
    /* 1AFE98 002AFE98 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* 1AFE9C 002AFE9C 24104300 */  and        $2, $2, $3
    /* 1AFEA0 002AFEA0 07108200 */  srav       $2, $2, $4
    /* 1AFEA4 002AFEA4 3C160200 */  dsll32     $2, $2, 24
    /* 1AFEA8 002AFEA8 3F160200 */  dsra32     $2, $2, 24
    /* 1AFEAC 002AFEAC 02000010 */  b          .L002AFEB8
    /* 1AFEB0 002AFEB0 00000000 */   nop
  .L002AFEB4:
    /* 1AFEB4 002AFEB4 01000224 */  addiu      $2, $0, 0x1
  .L002AFEB8:
    /* 1AFEB8 002AFEB8 3C1E0200 */  dsll32     $3, $2, 24
    /* 1AFEBC 002AFEBC 3F1E0300 */  dsra32     $3, $3, 24
    /* 1AFEC0 002AFEC0 01000224 */  addiu      $2, $0, 0x1
    /* 1AFEC4 002AFEC4 20006214 */  bne        $3, $2, .L002AFF48
    /* 1AFEC8 002AFEC8 00000000 */   nop
    /* 1AFECC 002AFECC FF000424 */  addiu      $4, $0, 0xFF
    /* 1AFED0 002AFED0 2D288000 */  daddu      $5, $4, $0
    /* 1AFED4 002AFED4 2D308000 */  daddu      $6, $4, $0
    /* 1AFED8 002AFED8 2D388000 */  daddu      $7, $4, $0
    /* 1AFEDC 002AFEDC 8CCA0A0C */  jal        func_002b2a30
    /* 1AFEE0 002AFEE0 00000000 */   nop
    /* 1AFEE4 002AFEE4 080021C6 */  lwc1       $f1, 0x8($17)
    /* 1AFEE8 002AFEE8 500120C6 */  lwc1       $f0, 0x150($17)
    /* 1AFEEC 002AFEEC 000B0046 */  add.s      $f12, $f1, $f0
    /* 1AFEF0 002AFEF0 0C0021C6 */  lwc1       $f1, 0xC($17)
    /* 1AFEF4 002AFEF4 540120C6 */  lwc1       $f0, 0x154($17)
    /* 1AFEF8 002AFEF8 400B0046 */  add.s      $f13, $f1, $f0
    /* 1AFEFC 002AFEFC 67EA0334 */  ori        $3, $0, 0xEA67
    /* 1AFF00 002AFF00 00008344 */  mtc1       $3, $f0
    /* 1AFF04 002AFF04 00000000 */  nop
    /* 1AFF08 002AFF08 A0038046 */  cvt.s.w    $f14, $f0
    /* 1AFF0C 002AFF0C 00788044 */  mtc1       $0, $f15
    /* 1AFF10 002AFF10 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* 1AFF14 002AFF14 00808344 */  mtc1       $3, $f16
    /* 1AFF18 002AFF18 2D204000 */  daddu      $4, $2, $0
    /* 1AFF1C 002AFF1C FF000524 */  addiu      $5, $0, 0xFF
    /* 1AFF20 002AFF20 13000624 */  addiu      $6, $0, 0x13
    /* 1AFF24 002AFF24 54B5878F */  lw         $7, -0x4AAC($28)
    /* 1AFF28 002AFF28 01000824 */  addiu      $8, $0, 0x1
    /* 1AFF2C 002AFF2C 2D480000 */  daddu      $9, $0, $0
    /* 1AFF30 002AFF30 2D500000 */  daddu      $10, $0, $0
    /* 1AFF34 002AFF34 46840046 */  mov.s      $f17, $f16
    /* 1AFF38 002AFF38 79000B3C */  lui        $11, %hi(D_00794DB0)
    /* 1AFF3C 002AFF3C B04D6B25 */  addiu      $11, $11, %lo(D_00794DB0)
    /* 1AFF40 002AFF40 347B090C */  jal        func_0025ecd0
    /* 1AFF44 002AFF44 00000000 */   nop
  .L002AFF48:
    /* 1AFF48 002AFF48 68EA0234 */  ori        $2, $0, 0xEA68
    /* 1AFF4C 002AFF4C 00008244 */  mtc1       $2, $f0
    /* 1AFF50 002AFF50 00000000 */  nop
    /* 1AFF54 002AFF54 A0038046 */  cvt.s.w    $f14, $f0
    /* 1AFF58 002AFF58 2D206002 */  daddu      $4, $19, $0
    /* 1AFF5C 002AFF5C 0800256E */  ldr        $5, 0x8($17)
    /* 1AFF60 002AFF60 0F00256A */  ldl        $5, 0xF($17)
    /* 1AFF64 002AFF64 2C002CC6 */  lwc1       $f12, 0x2C($17)
    /* 1AFF68 002AFF68 30002DC6 */  lwc1       $f13, 0x30($17)
    /* 1AFF6C 002AFF6C 18002692 */  lbu        $6, 0x18($17)
    /* 1AFF70 002AFF70 34002FC6 */  lwc1       $f15, 0x34($17)
    /* 1AFF74 002AFF74 2D384002 */  daddu      $7, $18, $0
    /* 1AFF78 002AFF78 42012882 */  lb         $8, 0x142($17)
    /* 1AFF7C 002AFF7C 50000924 */  addiu      $9, $0, 0x50
    /* 1AFF80 002AFF80 C4C20A0C */  jal        func_002b0b10
    /* 1AFF84 002AFF84 00000000 */   nop
    /* 1AFF88 002AFF88 5A0120A2 */  sb         $0, 0x15A($17)
    /* 1AFF8C 002AFF8C 98000010 */  b          .L002B01F0
    /* 1AFF90 002AFF90 00000000 */   nop
  .L002AFF94:
    /* 1AFF94 002AFF94 01000224 */  addiu      $2, $0, 0x1
    /* 1AFF98 002AFF98 95006214 */  bne        $3, $2, .L002B01F0
    /* 1AFF9C 002AFF9C 00000000 */   nop
    /* 1AFFA0 002AFFA0 16140424 */  addiu      $4, $0, 0x1416
    /* 1AFFA4 002AFFA4 CC18040C */  jal        func_00106330
    /* 1AFFA8 002AFFA8 00000000 */   nop
    /* 1AFFAC 002AFFAC 07004014 */  bnez       $2, .L002AFFCC
    /* 1AFFB0 002AFFB0 00000000 */   nop
    /* 1AFFB4 002AFFB4 43012282 */  lb         $2, 0x143($17)
    /* 1AFFB8 002AFFB8 04004014 */  bnez       $2, .L002AFFCC
    /* 1AFFBC 002AFFBC 00000000 */   nop
    /* 1AFFC0 002AFFC0 2D100000 */  daddu      $2, $0, $0
    /* 1AFFC4 002AFFC4 8B000010 */  b          .L002B01F4
    /* 1AFFC8 002AFFC8 00000000 */   nop
  .L002AFFCC:
    /* 1AFFCC 002AFFCC 40012292 */  lbu        $2, 0x140($17)
    /* 1AFFD0 002AFFD0 06004004 */  bltz       $2, .L002AFFEC
    /* 1AFFD4 002AFFD4 00000000 */   nop
    /* 1AFFD8 002AFFD8 00008244 */  mtc1       $2, $f0
    /* 1AFFDC 002AFFDC 00000000 */  nop
    /* 1AFFE0 002AFFE0 E0008046 */  cvt.s.w    $f3, $f0
    /* 1AFFE4 002AFFE4 08000010 */  b          .L002B0008
    /* 1AFFE8 002AFFE8 00000000 */   nop
  .L002AFFEC:
    /* 1AFFEC 002AFFEC 42180200 */  srl        $3, $2, 1
    /* 1AFFF0 002AFFF0 01004230 */  andi       $2, $2, 0x1
    /* 1AFFF4 002AFFF4 25186200 */  or         $3, $3, $2
    /* 1AFFF8 002AFFF8 00008344 */  mtc1       $3, $f0
    /* 1AFFFC 002AFFFC 00000000 */  nop
    /* 1B0000 002B0000 E0008046 */  cvt.s.w    $f3, $f0
    /* 1B0004 002B0004 C0180346 */  add.s      $f3, $f3, $f3
  .L002B0008:
    /* 1B0008 002B0008 9041023C */  lui        $2, (0x41900000 >> 16)
    /* 1B000C 002B000C 00108244 */  mtc1       $2, $f2
    /* 1B0010 002B0010 2C43023C */  lui        $2, (0x432C0000 >> 16)
    /* 1B0014 002B0014 00088244 */  mtc1       $2, $f1
    /* 1B0018 002B0018 00008044 */  mtc1       $0, $f0
    /* 1B001C 002B001C 00000000 */  nop
    /* 1B0020 002B0020 18000146 */  adda.s     $f0, $f1
    /* 1B0024 002B0024 1C100346 */  madd.s     $f0, $f2, $f3
    /* 1B0028 002B0028 080020E6 */  swc1       $f0, 0x8($17)
    /* 1B002C 002B002C 41012292 */  lbu        $2, 0x141($17)
    /* 1B0030 002B0030 06004004 */  bltz       $2, .L002B004C
    /* 1B0034 002B0034 00000000 */   nop
    /* 1B0038 002B0038 00008244 */  mtc1       $2, $f0
    /* 1B003C 002B003C 00000000 */  nop
    /* 1B0040 002B0040 E0008046 */  cvt.s.w    $f3, $f0
    /* 1B0044 002B0044 08000010 */  b          .L002B0068
    /* 1B0048 002B0048 00000000 */   nop
  .L002B004C:
    /* 1B004C 002B004C 42180200 */  srl        $3, $2, 1
    /* 1B0050 002B0050 01004230 */  andi       $2, $2, 0x1
    /* 1B0054 002B0054 25186200 */  or         $3, $3, $2
    /* 1B0058 002B0058 00008344 */  mtc1       $3, $f0
    /* 1B005C 002B005C 00000000 */  nop
    /* 1B0060 002B0060 E0008046 */  cvt.s.w    $f3, $f0
    /* 1B0064 002B0064 C0180346 */  add.s      $f3, $f3, $f3
  .L002B0068:
    /* 1B0068 002B0068 9041023C */  lui        $2, (0x41900000 >> 16)
    /* 1B006C 002B006C 00108244 */  mtc1       $2, $f2
    /* 1B0070 002B0070 1041023C */  lui        $2, (0x41100000 >> 16)
    /* 1B0074 002B0074 00088244 */  mtc1       $2, $f1
    /* 1B0078 002B0078 00008044 */  mtc1       $0, $f0
    /* 1B007C 002B007C 00000000 */  nop
    /* 1B0080 002B0080 18000146 */  adda.s     $f0, $f1
    /* 1B0084 002B0084 1C100346 */  madd.s     $f0, $f2, $f3
    /* 1B0088 002B0088 0C0020E6 */  swc1       $f0, 0xC($17)
    /* 1B008C 002B008C 4C012382 */  lb         $3, 0x14C($17)
    /* 1B0090 002B0090 01000224 */  addiu      $2, $0, 0x1
    /* 1B0094 002B0094 46006214 */  bne        $3, $2, .L002B01B0
    /* 1B0098 002B0098 00000000 */   nop
    /* 1B009C 002B009C A054050C */  jal        func_00155280
    /* 1B00A0 002B00A0 00000000 */   nop
    /* 1B00A4 002B00A4 47004390 */  lbu        $3, 0x47($2)
    /* 1B00A8 002B00A8 59012282 */  lb         $2, 0x159($17)
    /* 1B00AC 002B00AC 21104300 */  addu       $2, $2, $3
    /* 1B00B0 002B00B0 FF005030 */  andi       $16, $2, 0xFF
    /* 1B00B4 002B00B4 A054050C */  jal        func_00155280
    /* 1B00B8 002B00B8 00000000 */   nop
    /* 1B00BC 002B00BC 46004390 */  lbu        $3, 0x46($2)
    /* 1B00C0 002B00C0 58012282 */  lb         $2, 0x158($17)
    /* 1B00C4 002B00C4 21104300 */  addu       $2, $2, $3
    /* 1B00C8 002B00C8 FF005430 */  andi       $20, $2, 0xFF
    /* 1B00CC 002B00CC 16140424 */  addiu      $4, $0, 0x1416
    /* 1B00D0 002B00D0 CC18040C */  jal        func_00106330
    /* 1B00D4 002B00D4 00000000 */   nop
    /* 1B00D8 002B00D8 10004014 */  bnez       $2, .L002B011C
    /* 1B00DC 002B00DC 00000000 */   nop
    /* 1B00E0 002B00E0 FF008432 */  andi       $4, $20, 0xFF
    /* 1B00E4 002B00E4 FF000232 */  andi       $2, $16, 0xFF
    /* 1B00E8 002B00E8 40180200 */  sll        $3, $2, 1
    /* 1B00EC 002B00EC 68B5828F */  lw         $2, -0x4A98($28)
    /* 1B00F0 002B00F0 21104300 */  addu       $2, $2, $3
    /* 1B00F4 002B00F4 00004394 */  lhu        $3, 0x0($2)
    /* 1B00F8 002B00F8 01000224 */  addiu      $2, $0, 0x1
    /* 1B00FC 002B00FC 04108200 */  sllv       $2, $2, $4
    /* 1B0100 002B0100 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* 1B0104 002B0104 24104300 */  and        $2, $2, $3
    /* 1B0108 002B0108 07108200 */  srav       $2, $2, $4
    /* 1B010C 002B010C 3C160200 */  dsll32     $2, $2, 24
    /* 1B0110 002B0110 3F160200 */  dsra32     $2, $2, 24
    /* 1B0114 002B0114 02000010 */  b          .L002B0120
    /* 1B0118 002B0118 00000000 */   nop
  .L002B011C:
    /* 1B011C 002B011C 01000224 */  addiu      $2, $0, 0x1
  .L002B0120:
    /* 1B0120 002B0120 3C1E0200 */  dsll32     $3, $2, 24
    /* 1B0124 002B0124 3F1E0300 */  dsra32     $3, $3, 24
    /* 1B0128 002B0128 01000224 */  addiu      $2, $0, 0x1
    /* 1B012C 002B012C 20006214 */  bne        $3, $2, .L002B01B0
    /* 1B0130 002B0130 00000000 */   nop
    /* 1B0134 002B0134 FF000424 */  addiu      $4, $0, 0xFF
    /* 1B0138 002B0138 2D288000 */  daddu      $5, $4, $0
    /* 1B013C 002B013C 2D308000 */  daddu      $6, $4, $0
    /* 1B0140 002B0140 2D388000 */  daddu      $7, $4, $0
    /* 1B0144 002B0144 8CCA0A0C */  jal        func_002b2a30
    /* 1B0148 002B0148 00000000 */   nop
    /* 1B014C 002B014C 080021C6 */  lwc1       $f1, 0x8($17)
    /* 1B0150 002B0150 500120C6 */  lwc1       $f0, 0x150($17)
    /* 1B0154 002B0154 000B0046 */  add.s      $f12, $f1, $f0
    /* 1B0158 002B0158 0C0021C6 */  lwc1       $f1, 0xC($17)
    /* 1B015C 002B015C 540120C6 */  lwc1       $f0, 0x154($17)
    /* 1B0160 002B0160 400B0046 */  add.s      $f13, $f1, $f0
    /* 1B0164 002B0164 67EA0334 */  ori        $3, $0, 0xEA67
    /* 1B0168 002B0168 00008344 */  mtc1       $3, $f0
    /* 1B016C 002B016C 00000000 */  nop
    /* 1B0170 002B0170 A0038046 */  cvt.s.w    $f14, $f0
    /* 1B0174 002B0174 00788044 */  mtc1       $0, $f15
    /* 1B0178 002B0178 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* 1B017C 002B017C 00808344 */  mtc1       $3, $f16
    /* 1B0180 002B0180 2D204000 */  daddu      $4, $2, $0
    /* 1B0184 002B0184 FF000524 */  addiu      $5, $0, 0xFF
    /* 1B0188 002B0188 13000624 */  addiu      $6, $0, 0x13
    /* 1B018C 002B018C 54B5878F */  lw         $7, -0x4AAC($28)
    /* 1B0190 002B0190 01000824 */  addiu      $8, $0, 0x1
    /* 1B0194 002B0194 2D480000 */  daddu      $9, $0, $0
    /* 1B0198 002B0198 2D500000 */  daddu      $10, $0, $0
    /* 1B019C 002B019C 46840046 */  mov.s      $f17, $f16
    /* 1B01A0 002B01A0 79000B3C */  lui        $11, %hi(D_00794CF0)
    /* 1B01A4 002B01A4 F04C6B25 */  addiu      $11, $11, %lo(D_00794CF0)
    /* 1B01A8 002B01A8 347B090C */  jal        func_0025ecd0
    /* 1B01AC 002B01AC 00000000 */   nop
  .L002B01B0:
    /* 1B01B0 002B01B0 68EA0234 */  ori        $2, $0, 0xEA68
    /* 1B01B4 002B01B4 00008244 */  mtc1       $2, $f0
    /* 1B01B8 002B01B8 00000000 */  nop
    /* 1B01BC 002B01BC A0038046 */  cvt.s.w    $f14, $f0
    /* 1B01C0 002B01C0 2D206002 */  daddu      $4, $19, $0
    /* 1B01C4 002B01C4 0800256E */  ldr        $5, 0x8($17)
    /* 1B01C8 002B01C8 0F00256A */  ldl        $5, 0xF($17)
    /* 1B01CC 002B01CC 2C002CC6 */  lwc1       $f12, 0x2C($17)
    /* 1B01D0 002B01D0 30002DC6 */  lwc1       $f13, 0x30($17)
    /* 1B01D4 002B01D4 18002692 */  lbu        $6, 0x18($17)
    /* 1B01D8 002B01D8 34002FC6 */  lwc1       $f15, 0x34($17)
    /* 1B01DC 002B01DC 2D384002 */  daddu      $7, $18, $0
    /* 1B01E0 002B01E0 42012882 */  lb         $8, 0x142($17)
    /* 1B01E4 002B01E4 4C000924 */  addiu      $9, $0, 0x4C
    /* 1B01E8 002B01E8 C4C20A0C */  jal        func_002b0b10
    /* 1B01EC 002B01EC 00000000 */   nop
  .L002B01F0:
    /* 1B01F0 002B01F0 2D100000 */  daddu      $2, $0, $0
  .L002B01F4:
    /* 1B01F4 002B01F4 5000BFDF */  ld         $31, 0x50($29)
    /* 1B01F8 002B01F8 4000B47B */  lq         $20, 0x40($29)
    /* 1B01FC 002B01FC 3000B37B */  lq         $19, 0x30($29)
    /* 1B0200 002B0200 2000B27B */  lq         $18, 0x20($29)
    /* 1B0204 002B0204 1000B17B */  lq         $17, 0x10($29)
    /* 1B0208 002B0208 0000B07B */  lq         $16, 0x0($29)
    /* 1B020C 002B020C 7000BD27 */  addiu      $29, $29, 0x70
    /* 1B0210 002B0210 0800E003 */  jr         $31
    /* 1B0214 002B0214 00000000 */   nop
    /* 1B0218 002B0218 00000000 */  nop
    /* 1B021C 002B021C 00000000 */  nop
.size func_002afbc0, 0x660
