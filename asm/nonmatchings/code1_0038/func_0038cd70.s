.section .text
.set noat
.set noreorder
glabel func_0038cd70
    /* 28CD70 0038CD70 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 28CD74 0038CD74 1000BFFF */  sd         $31, 0x10($29)
    /* 28CD78 0038CD78 0000B07F */  sq         $16, 0x0($29)
    /* 28CD7C 0038CD7C 2D80A000 */  daddu      $16, $5, $0
    /* 28CD80 0038CD80 783C0D0C */  jal        func_0034f1e0
    /* 28CD84 0038CD84 00000000 */   nop
    /* 28CD88 0038CD88 04000396 */  lhu        $3, 0x4($16)
    /* 28CD8C 0038CD8C 20006330 */  andi       $3, $3, 0x20
    /* 28CD90 0038CD90 04006010 */  beqz       $3, .L0038CDA4
    /* 28CD94 0038CD94 00000000 */   nop
    /* 28CD98 0038CD98 2D200002 */  daddu      $4, $16, $0
    /* 28CD9C 0038CD9C 342B0E0C */  jal        func_0038acd0
    /* 28CDA0 0038CDA0 00000000 */   nop
  .L0038CDA4:
    /* 28CDA4 0038CDA4 04000396 */  lhu        $3, 0x4($16)
    /* 28CDA8 0038CDA8 01006330 */  andi       $3, $3, 0x1
    /* 28CDAC 0038CDAC 04006010 */  beqz       $3, .L0038CDC0
    /* 28CDB0 0038CDB0 00000000 */   nop
    /* 28CDB4 0038CDB4 2D200002 */  daddu      $4, $16, $0
    /* 28CDB8 0038CDB8 AC2E0E0C */  jal        func_0038bab0
    /* 28CDBC 0038CDBC 00000000 */   nop
  .L0038CDC0:
    /* 28CDC0 0038CDC0 04000396 */  lhu        $3, 0x4($16)
    /* 28CDC4 0038CDC4 02006330 */  andi       $3, $3, 0x2
    /* 28CDC8 0038CDC8 04006010 */  beqz       $3, .L0038CDDC
    /* 28CDCC 0038CDCC 00000000 */   nop
    /* 28CDD0 0038CDD0 2D200002 */  daddu      $4, $16, $0
    /* 28CDD4 0038CDD4 40300E0C */  jal        func_0038c100
    /* 28CDD8 0038CDD8 00000000 */   nop
  .L0038CDDC:
    /* 28CDDC 0038CDDC 04000396 */  lhu        $3, 0x4($16)
    /* 28CDE0 0038CDE0 04006330 */  andi       $3, $3, 0x4
    /* 28CDE4 0038CDE4 04006010 */  beqz       $3, .L0038CDF8
    /* 28CDE8 0038CDE8 00000000 */   nop
    /* 28CDEC 0038CDEC 2D200002 */  daddu      $4, $16, $0
    /* 28CDF0 0038CDF0 DC310E0C */  jal        func_0038c770
    /* 28CDF4 0038CDF4 00000000 */   nop
  .L0038CDF8:
    /* 28CDF8 0038CDF8 04000396 */  lhu        $3, 0x4($16)
    /* 28CDFC 0038CDFC 08006330 */  andi       $3, $3, 0x8
    /* 28CE00 0038CE00 04006010 */  beqz       $3, .L0038CE14
    /* 28CE04 0038CE04 00000000 */   nop
    /* 28CE08 0038CE08 2D200002 */  daddu      $4, $16, $0
    /* 28CE0C 0038CE0C AC320E0C */  jal        func_0038cab0
    /* 28CE10 0038CE10 00000000 */   nop
  .L0038CE14:
    /* 28CE14 0038CE14 1000BFDF */  ld         $31, 0x10($29)
    /* 28CE18 0038CE18 0000B07B */  lq         $16, 0x0($29)
    /* 28CE1C 0038CE1C 2000BD27 */  addiu      $29, $29, 0x20
    /* 28CE20 0038CE20 0800E003 */  jr         $31
    /* 28CE24 0038CE24 00000000 */   nop
    /* 28CE28 0038CE28 00000000 */  nop
    /* 28CE2C 0038CE2C 00000000 */  nop
.size func_0038cd70, 0xc0
