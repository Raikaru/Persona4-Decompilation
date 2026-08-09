.section .text
.set noat
.set noreorder
glabel func_0035ac60
    /* 25AC60 0035AC60 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 25AC64 0035AC64 4000BFFF */  sd         $31, 0x40($29)
    /* 25AC68 0035AC68 3000B37F */  sq         $19, 0x30($29)
    /* 25AC6C 0035AC6C 2000B27F */  sq         $18, 0x20($29)
    /* 25AC70 0035AC70 1000B17F */  sq         $17, 0x10($29)
    /* 25AC74 0035AC74 0000B07F */  sq         $16, 0x0($29)
    /* 25AC78 0035AC78 2D908000 */  daddu      $18, $4, $0
    /* 25AC7C 0035AC7C 2D88A000 */  daddu      $17, $5, $0
    /* 25AC80 0035AC80 2D80C000 */  daddu      $16, $6, $0
    /* 25AC84 0035AC84 2D98E000 */  daddu      $19, $7, $0
    /* 25AC88 0035AC88 04002006 */  bltz       $17, .L0035AC9C
    /* 25AC8C 0035AC8C 00000000 */   nop
    /* 25AC90 0035AC90 0200222A */  slti       $2, $17, 0x2
    /* 25AC94 0035AC94 06004014 */  bnez       $2, .L0035ACB0
    /* 25AC98 0035AC98 00000000 */   nop
  .L0035AC9C:
    /* 25AC9C 0035AC9C 6500043C */  lui        $4, %hi(D_0064CC98)
    /* 25ACA0 0035ACA0 98CC8424 */  addiu      $4, $4, %lo(D_0064CC98)
    /* 25ACA4 0035ACA4 B8060524 */  addiu      $5, $0, 0x6B8
    /* 25ACA8 0035ACA8 CCB5110C */  jal        func_0046d730
    /* 25ACAC 0035ACAC 00000000 */   nop
  .L0035ACB0:
    /* 25ACB0 0035ACB0 06004016 */  bnez       $18, .L0035ACCC
    /* 25ACB4 0035ACB4 00000000 */   nop
    /* 25ACB8 0035ACB8 6500043C */  lui        $4, %hi(D_0064CC98)
    /* 25ACBC 0035ACBC 98CC8424 */  addiu      $4, $4, %lo(D_0064CC98)
    /* 25ACC0 0035ACC0 B9060524 */  addiu      $5, $0, 0x6B9
    /* 25ACC4 0035ACC4 CCB5110C */  jal        func_0046d730
    /* 25ACC8 0035ACC8 00000000 */   nop
  .L0035ACCC:
    /* 25ACCC 0035ACCC 0A006012 */  beqz       $19, .L0035ACF8
    /* 25ACD0 0035ACD0 00000000 */   nop
    /* 25ACD4 0035ACD4 C0101100 */  sll        $2, $17, 3
    /* 25ACD8 0035ACD8 23105100 */  subu       $2, $2, $17
    /* 25ACDC 0035ACDC 80180200 */  sll        $3, $2, 2
    /* 25ACE0 0035ACE0 6500023C */  lui        $2, %hi(D_0064CC60)
    /* 25ACE4 0035ACE4 60CC4224 */  addiu      $2, $2, %lo(D_0064CC60)
    /* 25ACE8 0035ACE8 21304300 */  addu       $6, $2, $3
    /* 25ACEC 0035ACEC 0800C524 */  addiu      $5, $6, 0x8
    /* 25ACF0 0035ACF0 08000010 */  b          .L0035AD14
    /* 25ACF4 0035ACF4 00000000 */   nop
  .L0035ACF8:
    /* 25ACF8 0035ACF8 C0101100 */  sll        $2, $17, 3
    /* 25ACFC 0035ACFC 23105100 */  subu       $2, $2, $17
    /* 25AD00 0035AD00 80180200 */  sll        $3, $2, 2
    /* 25AD04 0035AD04 6500023C */  lui        $2, %hi(D_0064CC60)
    /* 25AD08 0035AD08 60CC4224 */  addiu      $2, $2, %lo(D_0064CC60)
    /* 25AD0C 0035AD0C 21284300 */  addu       $5, $2, $3
    /* 25AD10 0035AD10 0800A624 */  addiu      $6, $5, 0x8
  .L0035AD14:
    /* 25AD14 0035AD14 C0101100 */  sll        $2, $17, 3
    /* 25AD18 0035AD18 23105100 */  subu       $2, $2, $17
    /* 25AD1C 0035AD1C 80180200 */  sll        $3, $2, 2
    /* 25AD20 0035AD20 6500023C */  lui        $2, %hi(D_0064CC70)
    /* 25AD24 0035AD24 70CC4224 */  addiu      $2, $2, %lo(D_0064CC70)
    /* 25AD28 0035AD28 21104300 */  addu       $2, $2, $3
    /* 25AD2C 0035AD2C 000041C4 */  lwc1       $f1, 0x0($2)
    /* 25AD30 0035AD30 040040C4 */  lwc1       $f0, 0x4($2)
    /* 25AD34 0035AD34 5800A1E7 */  swc1       $f1, 0x58($29)
    /* 25AD38 0035AD38 5C00A0E7 */  swc1       $f0, 0x5C($29)
    /* 25AD3C 0035AD3C 6500023C */  lui        $2, %hi(D_0064CC78)
    /* 25AD40 0035AD40 78CC4224 */  addiu      $2, $2, %lo(D_0064CC78)
    /* 25AD44 0035AD44 21104300 */  addu       $2, $2, $3
    /* 25AD48 0035AD48 0000518C */  lw         $17, 0x0($2)
    /* 25AD4C 0035AD4C 06000012 */  beqz       $16, .L0035AD68
    /* 25AD50 0035AD50 00000000 */   nop
    /* 25AD54 0035AD54 2D204002 */  daddu      $4, $18, $0
    /* 25AD58 0035AD58 34540D0C */  jal        func_003550d0
    /* 25AD5C 0035AD5C 00000000 */   nop
    /* 25AD60 0035AD60 05000010 */  b          .L0035AD78
    /* 25AD64 0035AD64 00000000 */   nop
  .L0035AD68:
    /* 25AD68 0035AD68 2D204002 */  daddu      $4, $18, $0
    /* 25AD6C 0035AD6C 2D28C000 */  daddu      $5, $6, $0
    /* 25AD70 0035AD70 1C540D0C */  jal        func_00355070
    /* 25AD74 0035AD74 00000000 */   nop
  .L0035AD78:
    /* 25AD78 0035AD78 2D204002 */  daddu      $4, $18, $0
    /* 25AD7C 0035AD7C 5800A5DF */  ld         $5, 0x58($29)
    /* 25AD80 0035AD80 B4540D0C */  jal        func_003552d0
    /* 25AD84 0035AD84 00000000 */   nop
    /* 25AD88 0035AD88 2D204002 */  daddu      $4, $18, $0
    /* 25AD8C 0035AD8C 2D282002 */  daddu      $5, $17, $0
    /* 25AD90 0035AD90 C0540D0C */  jal        func_00355300
    /* 25AD94 0035AD94 00000000 */   nop
    /* 25AD98 0035AD98 4000BFDF */  ld         $31, 0x40($29)
    /* 25AD9C 0035AD9C 3000B37B */  lq         $19, 0x30($29)
    /* 25ADA0 0035ADA0 2000B27B */  lq         $18, 0x20($29)
    /* 25ADA4 0035ADA4 1000B17B */  lq         $17, 0x10($29)
    /* 25ADA8 0035ADA8 0000B07B */  lq         $16, 0x0($29)
    /* 25ADAC 0035ADAC 6000BD27 */  addiu      $29, $29, 0x60
    /* 25ADB0 0035ADB0 0800E003 */  jr         $31
    /* 25ADB4 0035ADB4 00000000 */   nop
    /* 25ADB8 0035ADB8 00000000 */  nop
    /* 25ADBC 0035ADBC 00000000 */  nop
.size func_0035ac60, 0x160
