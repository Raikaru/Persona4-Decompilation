.section .text
.set noat
.set noreorder
glabel func_001eaca0
    /* EACA0 001EACA0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* EACA4 001EACA4 4000BFFF */  sd         $31, 0x40($29)
    /* EACA8 001EACA8 3000B37F */  sq         $19, 0x30($29)
    /* EACAC 001EACAC 2000B27F */  sq         $18, 0x20($29)
    /* EACB0 001EACB0 1000B17F */  sq         $17, 0x10($29)
    /* EACB4 001EACB4 0000B07F */  sq         $16, 0x0($29)
    /* EACB8 001EACB8 2D200000 */  daddu      $4, $0, $0
    /* EACBC 001EACBC 544F070C */  jal        func_001d3d50
    /* EACC0 001EACC0 00000000 */   nop
    /* EACC4 001EACC4 2D804000 */  daddu      $16, $2, $0
    /* EACC8 001EACC8 2D200000 */  daddu      $4, $0, $0
    /* EACCC 001EACCC 00730A0C */  jal        func_0029cc00
    /* EACD0 001EACD0 00000000 */   nop
    /* EACD4 001EACD4 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* EACD8 001EACD8 01004224 */  addiu      $2, $2, 0x1
    /* EACDC 001EACDC FFFF4430 */  andi       $4, $2, 0xFFFF
    /* EACE0 001EACE0 B4B3080C */  jal        func_0022ced0
    /* EACE4 001EACE4 00000000 */   nop
    /* EACE8 001EACE8 2D200002 */  daddu      $4, $16, $0
    /* EACEC 001EACEC 2D284000 */  daddu      $5, $2, $0
    /* EACF0 001EACF0 A84F070C */  jal        func_001d3ea0
    /* EACF4 001EACF4 00000000 */   nop
    /* EACF8 001EACF8 ACB3838F */  lw         $3, -0x4C54($28)
    /* EACFC 001EACFC 7001628C */  lw         $2, 0x170($3)
    /* EAD00 001EAD00 3000528C */  lw         $18, 0x30($2)
    /* EAD04 001EAD04 8001718C */  lw         $17, 0x180($3)
    /* EAD08 001EAD08 18000010 */  b          .L001EAD6C
    /* EAD0C 001EAD0C 00000000 */   nop
  .L001EAD10:
    /* EAD10 001EAD10 640A248E */  lw         $4, 0xA64($17)
    /* EAD14 001EAD14 14008010 */  beqz       $4, .L001EAD68
    /* EAD18 001EAD18 00000000 */   nop
    /* EAD1C 001EAD1C 380F090C */  jal        func_00243ce0
    /* EAD20 001EAD20 00000000 */   nop
    /* EAD24 001EAD24 10004010 */  beqz       $2, .L001EAD68
    /* EAD28 001EAD28 00000000 */   nop
    /* EAD2C 001EAD2C A4002396 */  lhu        $3, 0xA4($17)
    /* EAD30 001EAD30 11010224 */  addiu      $2, $0, 0x111
    /* EAD34 001EAD34 0C006210 */  beq        $3, $2, .L001EAD68
    /* EAD38 001EAD38 00000000 */   nop
    /* EAD3C 001EAD3C 10010224 */  addiu      $2, $0, 0x110
    /* EAD40 001EAD40 09006210 */  beq        $3, $2, .L001EAD68
    /* EAD44 001EAD44 00000000 */   nop
    /* EAD48 001EAD48 0F010224 */  addiu      $2, $0, 0x10F
    /* EAD4C 001EAD4C 06006210 */  beq        $3, $2, .L001EAD68
    /* EAD50 001EAD50 00000000 */   nop
    /* EAD54 001EAD54 0D010224 */  addiu      $2, $0, 0x10D
    /* EAD58 001EAD58 03006210 */  beq        $3, $2, .L001EAD68
    /* EAD5C 001EAD5C 00000000 */   nop
    /* EAD60 001EAD60 04000010 */  b          .L001EAD74
    /* EAD64 001EAD64 00000000 */   nop
  .L001EAD68:
    /* EAD68 001EAD68 6C0A318E */  lw         $17, 0xA6C($17)
  .L001EAD6C:
    /* EAD6C 001EAD6C E8FF2016 */  bnez       $17, .L001EAD10
    /* EAD70 001EAD70 00000000 */   nop
  .L001EAD74:
    /* EAD74 001EAD74 02002016 */  bnez       $17, .L001EAD80
    /* EAD78 001EAD78 00000000 */   nop
    /* EAD7C 001EAD7C 2D884002 */  daddu      $17, $18, $0
  .L001EAD80:
    /* EAD80 001EAD80 2D200002 */  daddu      $4, $16, $0
    /* EAD84 001EAD84 2D284002 */  daddu      $5, $18, $0
    /* EAD88 001EAD88 2D302002 */  daddu      $6, $17, $0
    /* EAD8C 001EAD8C 2D380000 */  daddu      $7, $0, $0
    /* EAD90 001EAD90 00020824 */  addiu      $8, $0, 0x200
    /* EAD94 001EAD94 9058070C */  jal        func_001d6240
    /* EAD98 001EAD98 00000000 */   nop
    /* EAD9C 001EAD9C 2D984000 */  daddu      $19, $2, $0
    /* EADA0 001EADA0 2D206002 */  daddu      $4, $19, $0
    /* EADA4 001EADA4 02000524 */  addiu      $5, $0, 0x2
    /* EADA8 001EADA8 6451060C */  jal        func_00194590
    /* EADAC 001EADAC 00000000 */   nop
    /* EADB0 001EADB0 580063DE */  ld         $3, 0x58($19)
    /* EADB4 001EADB4 ACB3828F */  lw         $2, -0x4C54($28)
    /* EADB8 001EADB8 D00B43FC */  sd         $3, 0xBD0($2)
    /* EADBC 001EADBC 2D200002 */  daddu      $4, $16, $0
    /* EADC0 001EADC0 2D284002 */  daddu      $5, $18, $0
    /* EADC4 001EADC4 2D302002 */  daddu      $6, $17, $0
    /* EADC8 001EADC8 01000724 */  addiu      $7, $0, 0x1
    /* EADCC 001EADCC 00020824 */  addiu      $8, $0, 0x200
    /* EADD0 001EADD0 9058070C */  jal        func_001d6240
    /* EADD4 001EADD4 00000000 */   nop
    /* EADD8 001EADD8 2D884000 */  daddu      $17, $2, $0
    /* EADDC 001EADDC 2D202002 */  daddu      $4, $17, $0
    /* EADE0 001EADE0 02000524 */  addiu      $5, $0, 0x2
    /* EADE4 001EADE4 6451060C */  jal        func_00194590
    /* EADE8 001EADE8 00000000 */   nop
    /* EADEC 001EADEC 580023DE */  ld         $3, 0x58($17)
    /* EADF0 001EADF0 ACB3828F */  lw         $2, -0x4C54($28)
    /* EADF4 001EADF4 D80B43FC */  sd         $3, 0xBD8($2)
    /* EADF8 001EADF8 2D200002 */  daddu      $4, $16, $0
    /* EADFC 001EADFC 804F070C */  jal        func_001d3e00
    /* EAE00 001EAE00 00000000 */   nop
    /* EAE04 001EAE04 01000224 */  addiu      $2, $0, 0x1
    /* EAE08 001EAE08 4000BFDF */  ld         $31, 0x40($29)
    /* EAE0C 001EAE0C 3000B37B */  lq         $19, 0x30($29)
    /* EAE10 001EAE10 2000B27B */  lq         $18, 0x20($29)
    /* EAE14 001EAE14 1000B17B */  lq         $17, 0x10($29)
    /* EAE18 001EAE18 0000B07B */  lq         $16, 0x0($29)
    /* EAE1C 001EAE1C 5000BD27 */  addiu      $29, $29, 0x50
    /* EAE20 001EAE20 0800E003 */  jr         $31
    /* EAE24 001EAE24 00000000 */   nop
    /* EAE28 001EAE28 00000000 */  nop
    /* EAE2C 001EAE2C 00000000 */  nop
.size func_001eaca0, 0x190
