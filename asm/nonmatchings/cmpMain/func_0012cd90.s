.section .text
.set noat
.set noreorder
glabel func_0012cd90
    /* 2CD90 0012CD90 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 2CD94 0012CD94 3000BFFF */  sd         $31, 0x30($29)
    /* 2CD98 0012CD98 2000B27F */  sq         $18, 0x20($29)
    /* 2CD9C 0012CD9C 1000B17F */  sq         $17, 0x10($29)
    /* 2CDA0 0012CDA0 0000B07F */  sq         $16, 0x0($29)
    /* 2CDA4 0012CDA4 01001224 */  addiu      $18, $0, 0x1
    /* 2CDA8 0012CDA8 ECB1918F */  lw         $17, -0x4E14($28)
    /* 2CDAC 0012CDAC 8C002012 */  beqz       $17, .L0012CFE0
    /* 2CDB0 0012CDB0 00000000 */   nop
    /* 2CDB4 0012CDB4 0E000424 */  addiu      $4, $0, 0xE
    /* 2CDB8 0012CDB8 4C00A527 */  addiu      $5, $29, 0x4C
    /* 2CDBC 0012CDBC 8800023C */  lui        $2, %hi(D_00887304)
    /* 2CDC0 0012CDC0 0473428C */  lw         $2, %lo(D_00887304)($2)
    /* 2CDC4 0012CDC4 09F84000 */  jalr       $2
    /* 2CDC8 0012CDC8 00000000 */   nop
    /* 2CDCC 0012CDCC 8800103C */  lui        $16, %hi(D_00887300)
    /* 2CDD0 0012CDD0 00731026 */  addiu      $16, $16, %lo(D_00887300)
    /* 2CDD4 0012CDD4 0E000424 */  addiu      $4, $0, 0xE
    /* 2CDD8 0012CDD8 2D280000 */  daddu      $5, $0, $0
    /* 2CDDC 0012CDDC 0000028E */  lw         $2, 0x0($16)
    /* 2CDE0 0012CDE0 09F84000 */  jalr       $2
    /* 2CDE4 0012CDE4 00000000 */   nop
    /* 2CDE8 0012CDE8 1000228E */  lw         $2, 0x10($17)
    /* 2CDEC 0012CDEC 01004230 */  andi       $2, $2, 0x1
    /* 2CDF0 0012CDF0 0B004010 */  beqz       $2, .L0012CE20
    /* 2CDF4 0012CDF4 00000000 */   nop
    /* 2CDF8 0012CDF8 18002426 */  addiu      $4, $17, 0x18
    /* 2CDFC 0012CDFC 8CB5040C */  jal        func_0012d630
    /* 2CE00 0012CE00 00000000 */   nop
    /* 2CE04 0012CE04 2D904000 */  daddu      $18, $2, $0
    /* 2CE08 0012CE08 05004012 */  beqz       $18, .L0012CE20
    /* 2CE0C 0012CE0C 00000000 */   nop
    /* 2CE10 0012CE10 1000238E */  lw         $3, 0x10($17)
    /* 2CE14 0012CE14 FEFF0224 */  addiu      $2, $0, -0x2
    /* 2CE18 0012CE18 24106200 */  and        $2, $3, $2
    /* 2CE1C 0012CE1C 100022AE */  sw         $2, 0x10($17)
  .L0012CE20:
    /* 2CE20 0012CE20 1000228E */  lw         $2, 0x10($17)
    /* 2CE24 0012CE24 02004230 */  andi       $2, $2, 0x2
    /* 2CE28 0012CE28 0B004010 */  beqz       $2, .L0012CE58
    /* 2CE2C 0012CE2C 00000000 */   nop
    /* 2CE30 0012CE30 BC022426 */  addiu      $4, $17, 0x2BC
    /* 2CE34 0012CE34 40BA040C */  jal        func_0012e900
    /* 2CE38 0012CE38 00000000 */   nop
    /* 2CE3C 0012CE3C 2D904000 */  daddu      $18, $2, $0
    /* 2CE40 0012CE40 05004012 */  beqz       $18, .L0012CE58
    /* 2CE44 0012CE44 00000000 */   nop
    /* 2CE48 0012CE48 1000238E */  lw         $3, 0x10($17)
    /* 2CE4C 0012CE4C FDFF0224 */  addiu      $2, $0, -0x3
    /* 2CE50 0012CE50 24106200 */  and        $2, $3, $2
    /* 2CE54 0012CE54 100022AE */  sw         $2, 0x10($17)
  .L0012CE58:
    /* 2CE58 0012CE58 1000228E */  lw         $2, 0x10($17)
    /* 2CE5C 0012CE5C 04004230 */  andi       $2, $2, 0x4
    /* 2CE60 0012CE60 0B004010 */  beqz       $2, .L0012CE90
    /* 2CE64 0012CE64 00000000 */   nop
    /* 2CE68 0012CE68 A41E2426 */  addiu      $4, $17, 0x1EA4
    /* 2CE6C 0012CE6C C8E2040C */  jal        func_00138b20
    /* 2CE70 0012CE70 00000000 */   nop
    /* 2CE74 0012CE74 2D904000 */  daddu      $18, $2, $0
    /* 2CE78 0012CE78 05004012 */  beqz       $18, .L0012CE90
    /* 2CE7C 0012CE7C 00000000 */   nop
    /* 2CE80 0012CE80 1000238E */  lw         $3, 0x10($17)
    /* 2CE84 0012CE84 FBFF0224 */  addiu      $2, $0, -0x5
    /* 2CE88 0012CE88 24106200 */  and        $2, $3, $2
    /* 2CE8C 0012CE8C 100022AE */  sw         $2, 0x10($17)
  .L0012CE90:
    /* 2CE90 0012CE90 1000228E */  lw         $2, 0x10($17)
    /* 2CE94 0012CE94 08004230 */  andi       $2, $2, 0x8
    /* 2CE98 0012CE98 0B004010 */  beqz       $2, .L0012CEC8
    /* 2CE9C 0012CE9C 00000000 */   nop
    /* 2CEA0 0012CEA0 74472426 */  addiu      $4, $17, 0x4774
    /* 2CEA4 0012CEA4 1C5A0D0C */  jal        func_00356870
    /* 2CEA8 0012CEA8 00000000 */   nop
    /* 2CEAC 0012CEAC 2D904000 */  daddu      $18, $2, $0
    /* 2CEB0 0012CEB0 05004012 */  beqz       $18, .L0012CEC8
    /* 2CEB4 0012CEB4 00000000 */   nop
    /* 2CEB8 0012CEB8 1000238E */  lw         $3, 0x10($17)
    /* 2CEBC 0012CEBC F7FF0224 */  addiu      $2, $0, -0x9
    /* 2CEC0 0012CEC0 24106200 */  and        $2, $3, $2
    /* 2CEC4 0012CEC4 100022AE */  sw         $2, 0x10($17)
  .L0012CEC8:
    /* 2CEC8 0012CEC8 1000228E */  lw         $2, 0x10($17)
    /* 2CECC 0012CECC 10004230 */  andi       $2, $2, 0x10
    /* 2CED0 0012CED0 0B004010 */  beqz       $2, .L0012CF00
    /* 2CED4 0012CED4 00000000 */   nop
    /* 2CED8 0012CED8 DC312426 */  addiu      $4, $17, 0x31DC
    /* 2CEDC 0012CEDC 44C6040C */  jal        func_00131910
    /* 2CEE0 0012CEE0 00000000 */   nop
    /* 2CEE4 0012CEE4 2D904000 */  daddu      $18, $2, $0
    /* 2CEE8 0012CEE8 05004012 */  beqz       $18, .L0012CF00
    /* 2CEEC 0012CEEC 00000000 */   nop
    /* 2CEF0 0012CEF0 1000238E */  lw         $3, 0x10($17)
    /* 2CEF4 0012CEF4 EFFF0224 */  addiu      $2, $0, -0x11
    /* 2CEF8 0012CEF8 24106200 */  and        $2, $3, $2
    /* 2CEFC 0012CEFC 100022AE */  sw         $2, 0x10($17)
  .L0012CF00:
    /* 2CF00 0012CF00 1000228E */  lw         $2, 0x10($17)
    /* 2CF04 0012CF04 20004230 */  andi       $2, $2, 0x20
    /* 2CF08 0012CF08 0B004010 */  beqz       $2, .L0012CF38
    /* 2CF0C 0012CF0C 00000000 */   nop
    /* 2CF10 0012CF10 8C5A2426 */  addiu      $4, $17, 0x5A8C
    /* 2CF14 0012CF14 3CD7040C */  jal        func_00135cf0
    /* 2CF18 0012CF18 00000000 */   nop
    /* 2CF1C 0012CF1C 2D904000 */  daddu      $18, $2, $0
    /* 2CF20 0012CF20 05004012 */  beqz       $18, .L0012CF38
    /* 2CF24 0012CF24 00000000 */   nop
    /* 2CF28 0012CF28 1000238E */  lw         $3, 0x10($17)
    /* 2CF2C 0012CF2C DFFF0224 */  addiu      $2, $0, -0x21
    /* 2CF30 0012CF30 24106200 */  and        $2, $3, $2
    /* 2CF34 0012CF34 100022AE */  sw         $2, 0x10($17)
  .L0012CF38:
    /* 2CF38 0012CF38 1000228E */  lw         $2, 0x10($17)
    /* 2CF3C 0012CF3C 40004230 */  andi       $2, $2, 0x40
    /* 2CF40 0012CF40 0B004010 */  beqz       $2, .L0012CF70
    /* 2CF44 0012CF44 00000000 */   nop
    /* 2CF48 0012CF48 50772426 */  addiu      $4, $17, 0x7750
    /* 2CF4C 0012CF4C F4FF040C */  jal        func_0013ffd0
    /* 2CF50 0012CF50 00000000 */   nop
    /* 2CF54 0012CF54 2D904000 */  daddu      $18, $2, $0
    /* 2CF58 0012CF58 05004012 */  beqz       $18, .L0012CF70
    /* 2CF5C 0012CF5C 00000000 */   nop
    /* 2CF60 0012CF60 1000238E */  lw         $3, 0x10($17)
    /* 2CF64 0012CF64 BFFF0224 */  addiu      $2, $0, -0x41
    /* 2CF68 0012CF68 24106200 */  and        $2, $3, $2
    /* 2CF6C 0012CF6C 100022AE */  sw         $2, 0x10($17)
  .L0012CF70:
    /* 2CF70 0012CF70 1000228E */  lw         $2, 0x10($17)
    /* 2CF74 0012CF74 80004230 */  andi       $2, $2, 0x80
    /* 2CF78 0012CF78 0C004010 */  beqz       $2, .L0012CFAC
    /* 2CF7C 0012CF7C 00000000 */   nop
    /* 2CF80 0012CF80 00900134 */  ori        $1, $0, 0x9000
    /* 2CF84 0012CF84 21202102 */  addu       $4, $17, $1
    /* 2CF88 0012CF88 247F0D0C */  jal        func_0035fc90
    /* 2CF8C 0012CF8C 00000000 */   nop
    /* 2CF90 0012CF90 2D904000 */  daddu      $18, $2, $0
    /* 2CF94 0012CF94 05004012 */  beqz       $18, .L0012CFAC
    /* 2CF98 0012CF98 00000000 */   nop
    /* 2CF9C 0012CF9C 1000238E */  lw         $3, 0x10($17)
    /* 2CFA0 0012CFA0 7FFF0224 */  addiu      $2, $0, -0x81
    /* 2CFA4 0012CFA4 24106200 */  and        $2, $3, $2
    /* 2CFA8 0012CFA8 100022AE */  sw         $2, 0x10($17)
  .L0012CFAC:
    /* 2CFAC 0012CFAC 0000238E */  lw         $3, 0x0($17)
    /* 2CFB0 0012CFB0 0D000224 */  addiu      $2, $0, 0xD
    /* 2CFB4 0012CFB4 05006214 */  bne        $3, $2, .L0012CFCC
    /* 2CFB8 0012CFB8 00000000 */   nop
    /* 2CFBC 0012CFBC 03004012 */  beqz       $18, .L0012CFCC
    /* 2CFC0 0012CFC0 00000000 */   nop
    /* 2CFC4 0012CFC4 01000224 */  addiu      $2, $0, 0x1
    /* 2CFC8 0012CFC8 140022AE */  sw         $2, 0x14($17)
  .L0012CFCC:
    /* 2CFCC 0012CFCC 0E000424 */  addiu      $4, $0, 0xE
    /* 2CFD0 0012CFD0 4C00A58F */  lw         $5, 0x4C($29)
    /* 2CFD4 0012CFD4 0000028E */  lw         $2, 0x0($16)
    /* 2CFD8 0012CFD8 09F84000 */  jalr       $2
    /* 2CFDC 0012CFDC 00000000 */   nop
  .L0012CFE0:
    /* 2CFE0 0012CFE0 3000BFDF */  ld         $31, 0x30($29)
    /* 2CFE4 0012CFE4 2000B27B */  lq         $18, 0x20($29)
    /* 2CFE8 0012CFE8 1000B17B */  lq         $17, 0x10($29)
    /* 2CFEC 0012CFEC 0000B07B */  lq         $16, 0x0($29)
    /* 2CFF0 0012CFF0 5000BD27 */  addiu      $29, $29, 0x50
    /* 2CFF4 0012CFF4 0800E003 */  jr         $31
    /* 2CFF8 0012CFF8 00000000 */   nop
    /* 2CFFC 0012CFFC 00000000 */  nop
.size func_0012cd90, 0x270
