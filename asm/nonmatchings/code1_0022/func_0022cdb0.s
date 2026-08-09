.section .text
.set noat
.set noreorder
glabel func_0022cdb0
    /* 12CDB0 0022CDB0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 12CDB4 0022CDB4 1000BFFF */  sd         $31, 0x10($29)
    /* 12CDB8 0022CDB8 0000B07F */  sq         $16, 0x0($29)
    /* 12CDBC 0022CDBC 2D808000 */  daddu      $16, $4, $0
    /* 12CDC0 0022CDC0 ACB3828F */  lw         $2, -0x4C54($28)
    /* 12CDC4 0022CDC4 1000428C */  lw         $2, 0x10($2)
    /* 12CDC8 0022CDC8 10004230 */  andi       $2, $2, 0x10
    /* 12CDCC 0022CDCC 04004014 */  bnez       $2, .L0022CDE0
    /* 12CDD0 0022CDD0 00000000 */   nop
    /* 12CDD4 0022CDD4 2D100000 */  daddu      $2, $0, $0
    /* 12CDD8 0022CDD8 38000010 */  b          .L0022CEBC
    /* 12CDDC 0022CDDC 00000000 */   nop
  .L0022CDE0:
    /* 12CDE0 0022CDE0 68BE070C */  jal        func_001ef9a0
    /* 12CDE4 0022CDE4 00000000 */   nop
    /* 12CDE8 0022CDE8 15020324 */  addiu      $3, $0, 0x215
    /* 12CDEC 0022CDEC 1C004310 */  beq        $2, $3, .L0022CE60
    /* 12CDF0 0022CDF0 00000000 */   nop
    /* 12CDF4 0022CDF4 0B020324 */  addiu      $3, $0, 0x20B
    /* 12CDF8 0022CDF8 03004310 */  beq        $2, $3, .L0022CE08
    /* 12CDFC 0022CDFC 00000000 */   nop
    /* 12CE00 0022CE00 20000010 */  b          .L0022CE84
    /* 12CE04 0022CE04 00000000 */   nop
  .L0022CE08:
    /* 12CE08 0022CE08 ACB3828F */  lw         $2, -0x4C54($28)
    /* 12CE0C 0022CE0C 400C428C */  lw         $2, 0xC40($2)
    /* 12CE10 0022CE10 0A004014 */  bnez       $2, .L0022CE3C
    /* 12CE14 0022CE14 00000000 */   nop
    /* 12CE18 0022CE18 FFFF0332 */  andi       $3, $16, 0xFFFF
    /* 12CE1C 0022CE1C 80100300 */  sll        $2, $3, 2
    /* 12CE20 0022CE20 21104300 */  addu       $2, $2, $3
    /* 12CE24 0022CE24 80180200 */  sll        $3, $2, 2
    /* 12CE28 0022CE28 6300023C */  lui        $2, %hi(D_00634CB0)
    /* 12CE2C 0022CE2C B04C4224 */  addiu      $2, $2, %lo(D_00634CB0)
    /* 12CE30 0022CE30 21104300 */  addu       $2, $2, $3
    /* 12CE34 0022CE34 1A000010 */  b          .L0022CEA0
    /* 12CE38 0022CE38 00000000 */   nop
  .L0022CE3C:
    /* 12CE3C 0022CE3C FFFF0332 */  andi       $3, $16, 0xFFFF
    /* 12CE40 0022CE40 80100300 */  sll        $2, $3, 2
    /* 12CE44 0022CE44 21104300 */  addu       $2, $2, $3
    /* 12CE48 0022CE48 80180200 */  sll        $3, $2, 2
    /* 12CE4C 0022CE4C 6300023C */  lui        $2, %hi(D_006350B0)
    /* 12CE50 0022CE50 B0504224 */  addiu      $2, $2, %lo(D_006350B0)
    /* 12CE54 0022CE54 21104300 */  addu       $2, $2, $3
    /* 12CE58 0022CE58 11000010 */  b          .L0022CEA0
    /* 12CE5C 0022CE5C 00000000 */   nop
  .L0022CE60:
    /* 12CE60 0022CE60 FFFF0332 */  andi       $3, $16, 0xFFFF
    /* 12CE64 0022CE64 80100300 */  sll        $2, $3, 2
    /* 12CE68 0022CE68 21104300 */  addu       $2, $2, $3
    /* 12CE6C 0022CE6C 80180200 */  sll        $3, $2, 2
    /* 12CE70 0022CE70 6300023C */  lui        $2, %hi(D_006350B0)
    /* 12CE74 0022CE74 B0504224 */  addiu      $2, $2, %lo(D_006350B0)
    /* 12CE78 0022CE78 21104300 */  addu       $2, $2, $3
    /* 12CE7C 0022CE7C 08000010 */  b          .L0022CEA0
    /* 12CE80 0022CE80 00000000 */   nop
  .L0022CE84:
    /* 12CE84 0022CE84 FFFF0332 */  andi       $3, $16, 0xFFFF
    /* 12CE88 0022CE88 80100300 */  sll        $2, $3, 2
    /* 12CE8C 0022CE8C 21104300 */  addu       $2, $2, $3
    /* 12CE90 0022CE90 80180200 */  sll        $3, $2, 2
    /* 12CE94 0022CE94 6300023C */  lui        $2, %hi(D_006348B0)
    /* 12CE98 0022CE98 B0484224 */  addiu      $2, $2, %lo(D_006348B0)
    /* 12CE9C 0022CE9C 21104300 */  addu       $2, $2, $3
  .L0022CEA0:
    /* 12CEA0 0022CEA0 0000438C */  lw         $3, 0x0($2)
    /* 12CEA4 0022CEA4 05006014 */  bnez       $3, .L0022CEBC
    /* 12CEA8 0022CEA8 00000000 */   nop
    /* 12CEAC 0022CEAC 0400438C */  lw         $3, 0x4($2)
    /* 12CEB0 0022CEB0 02006014 */  bnez       $3, .L0022CEBC
    /* 12CEB4 0022CEB4 00000000 */   nop
    /* 12CEB8 0022CEB8 2D100000 */  daddu      $2, $0, $0
  .L0022CEBC:
    /* 12CEBC 0022CEBC 1000BFDF */  ld         $31, 0x10($29)
    /* 12CEC0 0022CEC0 0000B07B */  lq         $16, 0x0($29)
    /* 12CEC4 0022CEC4 2000BD27 */  addiu      $29, $29, 0x20
    /* 12CEC8 0022CEC8 0800E003 */  jr         $31
    /* 12CECC 0022CECC 00000000 */   nop
.size func_0022cdb0, 0x120
