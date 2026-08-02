.section .text
.set noat
.set noreorder
glabel func_004aaee0
    /* 3AAEE0 004AAEE0 90FFBD27 */  addiu      $29, $29, -0x70
    /* 3AAEE4 004AAEE4 6000BFFF */  sd         $31, 0x60($29)
    /* 3AAEE8 004AAEE8 5000B57F */  sq         $21, 0x50($29)
    /* 3AAEEC 004AAEEC 4000B47F */  sq         $20, 0x40($29)
    /* 3AAEF0 004AAEF0 3000B37F */  sq         $19, 0x30($29)
    /* 3AAEF4 004AAEF4 2000B27F */  sq         $18, 0x20($29)
    /* 3AAEF8 004AAEF8 1000B17F */  sq         $17, 0x10($29)
    /* 3AAEFC 004AAEFC 0000B07F */  sq         $16, 0x0($29)
    /* 3AAF00 004AAF00 2DA88000 */  daddu      $21, $4, $0
    /* 3AAF04 004AAF04 2DA0A000 */  daddu      $20, $5, $0
    /* 3AAF08 004AAF08 60001124 */  addiu      $17, $0, 0x60
    /* 3AAF0C 004AAF0C FFFFB032 */  andi       $16, $21, 0xFFFF
    /* 3AAF10 004AAF10 40101000 */  sll        $2, $16, 1
    /* 3AAF14 004AAF14 21105000 */  addu       $2, $2, $16
    /* 3AAF18 004AAF18 C0180200 */  sll        $3, $2, 3
    /* 3AAF1C 004AAF1C 7100023C */  lui        $2, %hi(D_007143A4)
    /* 3AAF20 004AAF20 A4434224 */  addiu      $2, $2, %lo(D_007143A4)
    /* 3AAF24 004AAF24 21104300 */  addu       $2, $2, $3
    /* 3AAF28 004AAF28 0000528C */  lw         $18, 0x0($2)
    /* 3AAF2C 004AAF2C 60004226 */  addiu      $2, $18, 0x60
    /* 3AAF30 004AAF30 0002422C */  sltiu      $2, $2, 0x200
    /* 3AAF34 004AAF34 06004014 */  bnez       $2, .L004AAF50
    /* 3AAF38 004AAF38 00000000 */   nop
    /* 3AAF3C 004AAF3C 7100043C */  lui        $4, %hi(D_00714450)
    /* 3AAF40 004AAF40 50448424 */  addiu      $4, $4, %lo(D_00714450)
    /* 3AAF44 004AAF44 70010524 */  addiu      $5, $0, 0x170
    /* 3AAF48 004AAF48 CCB5110C */  jal        func_0046d730
    /* 3AAF4C 004AAF4C 00000000 */   nop
  .L004AAF50:
    /* 3AAF50 004AAF50 7100043C */  lui        $4, %hi(D_00714450)
    /* 3AAF54 004AAF54 50448424 */  addiu      $4, $4, %lo(D_00714450)
    /* 3AAF58 004AAF58 71010524 */  addiu      $5, $0, 0x171
    /* 3AAF5C 004AAF5C A43A110C */  jal        func_0044ea90
    /* 3AAF60 004AAF60 00000000 */   nop
    /* 3AAF64 004AAF64 60004426 */  addiu      $4, $18, 0x60
    /* 3AAF68 004AAF68 0400053C */  lui        $5, (0x40000 >> 16)
    /* 3AAF6C 004AAF6C 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 3AAF70 004AAF70 E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 3AAF74 004AAF74 09F84000 */  jalr       $2
    /* 3AAF78 004AAF78 00000000 */   nop
    /* 3AAF7C 004AAF7C 2D984000 */  daddu      $19, $2, $0
    /* 3AAF80 004AAF80 60004626 */  addiu      $6, $18, 0x60
    /* 3AAF84 004AAF84 2D206002 */  daddu      $4, $19, $0
    /* 3AAF88 004AAF88 2D280000 */  daddu      $5, $0, $0
    /* 3AAF8C 004AAF8C 72FE100C */  jal        func_0043f9c8
    /* 3AAF90 004AAF90 00000000 */   nop
    /* 3AAF94 004AAF94 06006016 */  bnez       $19, .L004AAFB0
    /* 3AAF98 004AAF98 00000000 */   nop
    /* 3AAF9C 004AAF9C 7100043C */  lui        $4, %hi(D_00714380)
    /* 3AAFA0 004AAFA0 80438424 */  addiu      $4, $4, %lo(D_00714380)
    /* 3AAFA4 004AAFA4 3B060524 */  addiu      $5, $0, 0x63B
    /* 3AAFA8 004AAFA8 CCB5110C */  jal        func_0046d730
    /* 3AAFAC 004AAFAC 00000000 */   nop
  .L004AAFB0:
    /* 3AAFB0 004AAFB0 180070AE */  sw         $16, 0x18($19)
    /* 3AAFB4 004AAFB4 FFFF0224 */  addiu      $2, $0, -0x1
    /* 3AAFB8 004AAFB8 100062AE */  sw         $2, 0x10($19)
    /* 3AAFBC 004AAFBC 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 3AAFC0 004AAFC0 140062AE */  sw         $2, 0x14($19)
    /* 3AAFC4 004AAFC4 280060AE */  sw         $0, 0x28($19)
    /* 3AAFC8 004AAFC8 000060FA */  sqc2       $vf0, 0x0($19)
    /* 3AAFCC 004AAFCC 21207102 */  addu       $4, $19, $17
    /* 3AAFD0 004AAFD0 240064AE */  sw         $4, 0x24($19)
    /* 3AAFD4 004AAFD4 2D288002 */  daddu      $5, $20, $0
    /* 3AAFD8 004AAFD8 2D304002 */  daddu      $6, $18, $0
    /* 3AAFDC 004AAFDC 04FE100C */  jal        func_0043f810
    /* 3AAFE0 004AAFE0 00000000 */   nop
    /* 3AAFE4 004AAFE4 FFFFA332 */  andi       $3, $21, 0xFFFF
    /* 3AAFE8 004AAFE8 40100300 */  sll        $2, $3, 1
    /* 3AAFEC 004AAFEC 21104300 */  addu       $2, $2, $3
    /* 3AAFF0 004AAFF0 C0180200 */  sll        $3, $2, 3
    /* 3AAFF4 004AAFF4 7100023C */  lui        $2, %hi(D_00714390)
    /* 3AAFF8 004AAFF8 90434224 */  addiu      $2, $2, %lo(D_00714390)
    /* 3AAFFC 004AAFFC 21104300 */  addu       $2, $2, $3
    /* 3AB000 004AB000 0000428C */  lw         $2, 0x0($2)
    /* 3AB004 004AB004 05004010 */  beqz       $2, .L004AB01C
    /* 3AB008 004AB008 00000000 */   nop
    /* 3AB00C 004AB00C 2400648E */  lw         $4, 0x24($19)
    /* 3AB010 004AB010 09F84000 */  jalr       $2
    /* 3AB014 004AB014 00000000 */   nop
    /* 3AB018 004AB018 200062AE */  sw         $2, 0x20($19)
  .L004AB01C:
    /* 3AB01C 004AB01C 16000224 */  addiu      $2, $0, 0x16
    /* 3AB020 004AB020 440062A6 */  sh         $2, 0x44($19)
    /* 3AB024 004AB024 480073AE */  sw         $19, 0x48($19)
    /* 3AB028 004AB028 2D106002 */  daddu      $2, $19, $0
    /* 3AB02C 004AB02C 6000BFDF */  ld         $31, 0x60($29)
    /* 3AB030 004AB030 5000B57B */  lq         $21, 0x50($29)
    /* 3AB034 004AB034 4000B47B */  lq         $20, 0x40($29)
    /* 3AB038 004AB038 3000B37B */  lq         $19, 0x30($29)
    /* 3AB03C 004AB03C 2000B27B */  lq         $18, 0x20($29)
    /* 3AB040 004AB040 1000B17B */  lq         $17, 0x10($29)
    /* 3AB044 004AB044 0000B07B */  lq         $16, 0x0($29)
    /* 3AB048 004AB048 7000BD27 */  addiu      $29, $29, 0x70
    /* 3AB04C 004AB04C 0800E003 */  jr         $31
    /* 3AB050 004AB050 00000000 */   nop
    /* 3AB054 004AB054 00000000 */  nop
    /* 3AB058 004AB058 00000000 */  nop
    /* 3AB05C 004AB05C 00000000 */  nop
.size func_004aaee0, 0x180
