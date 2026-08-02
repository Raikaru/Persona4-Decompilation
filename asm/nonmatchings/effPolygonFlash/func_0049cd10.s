.section .text
.set noat
.set noreorder
glabel func_0049cd10
    /* 39CD10 0049CD10 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 39CD14 0049CD14 3000BFFF */  sd         $31, 0x30($29)
    /* 39CD18 0049CD18 2000B27F */  sq         $18, 0x20($29)
    /* 39CD1C 0049CD1C 1000B17F */  sq         $17, 0x10($29)
    /* 39CD20 0049CD20 0000B07F */  sq         $16, 0x0($29)
    /* 39CD24 0049CD24 2D908000 */  daddu      $18, $4, $0
    /* 39CD28 0049CD28 3C00838C */  lw         $3, 0x3C($4)
    /* 39CD2C 0049CD2C 4000918C */  lw         $17, 0x40($4)
    /* 39CD30 0049CD30 0400708C */  lw         $16, 0x4($3)
    /* 39CD34 0049CD34 3400868C */  lw         $6, 0x34($4)
    /* 39CD38 0049CD38 3400278E */  lw         $7, 0x34($17)
    /* 39CD3C 0049CD3C 2B08E600 */  sltu       $1, $7, $6
    /* 39CD40 0049CD40 03002010 */  beqz       $1, .L0049CD50
    /* 39CD44 0049CD44 00000000 */   nop
    /* 39CD48 0049CD48 5A00E014 */  bnez       $7, .L0049CEB4
    /* 39CD4C 0049CD4C 00000000 */   nop
  .L0049CD50:
    /* 39CD50 0049CD50 2D202002 */  daddu      $4, $17, $0
    /* 39CD54 0049CD54 24002526 */  addiu      $5, $17, 0x24
    /* 39CD58 0049CD58 F42A120C */  jal        func_0048abd0
    /* 39CD5C 0049CD5C 00000000 */   nop
    /* 39CD60 0049CD60 2D184000 */  daddu      $3, $2, $0
    /* 39CD64 0049CD64 3000428E */  lw         $2, 0x30($18)
    /* 39CD68 0049CD68 4800A2AF */  sw         $2, 0x48($29)
    /* 39CD6C 0049CD6C 4800A227 */  addiu      $2, $29, 0x48
    /* 39CD70 0049CD70 448080C7 */  lwc1       $f0, -0x7FBC($28)
    /* 39CD74 0049CD74 0000428C */  lw         $2, 0x0($2)
    /* 39CD78 0049CD78 88160270 */  pextlb     $2, $0, $2
    /* 39CD7C 0049CD7C 88150270 */  pextlh     $2, $0, $2
    /* 39CD80 0049CD80 0050A248 */  qmtc2.ni   $2, $vf10
    /* 39CD84 0049CD84 3C51EA4B */  vitof0.xyzw $vf10, $vf10
    /* 39CD88 0049CD88 00000244 */  mfc1       $2, $f0
    /* 39CD8C 0049CD8C 00000000 */  nop
    /* 39CD90 0049CD90 0010A248 */  qmtc2.ni   $2, $vf2
    /* 39CD94 0049CD94 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 39CD98 0049CD98 3C53EB4B */  vmove.xyzw $vf11, $vf10
    /* 39CD9C 0049CD9C 4400A3AF */  sw         $3, 0x44($29)
    /* 39CDA0 0049CDA0 4400A227 */  addiu      $2, $29, 0x44
    /* 39CDA4 0049CDA4 0000428C */  lw         $2, 0x0($2)
    /* 39CDA8 0049CDA8 88160270 */  pextlb     $2, $0, $2
    /* 39CDAC 0049CDAC 88150270 */  pextlh     $2, $0, $2
    /* 39CDB0 0049CDB0 0050A248 */  qmtc2.ni   $2, $vf10
    /* 39CDB4 0049CDB4 3C51EA4B */  vitof0.xyzw $vf10, $vf10
    /* 39CDB8 0049CDB8 00000244 */  mfc1       $2, $f0
    /* 39CDBC 0049CDBC 00000000 */  nop
    /* 39CDC0 0049CDC0 0010A248 */  qmtc2.ni   $2, $vf2
    /* 39CDC4 0049CDC4 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 39CDC8 0049CDC8 AA52EB4B */  vmul.xyzw  $vf10, $vf10, $vf11
    /* 39CDCC 0049CDCC 7F43023C */  lui        $2, (0x437F0000 >> 16)
    /* 39CDD0 0049CDD0 0010A248 */  qmtc2.ni   $2, $vf2
    /* 39CDD4 0049CDD4 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 39CDD8 0049CDD8 7C51EA4B */  vftoi0.xyzw $vf10, $vf10
    /* 39CDDC 0049CDDC 00502248 */  qmfc2.ni   $2, $vf10
    /* 39CDE0 0049CDE0 C8150270 */  ppach      $2, $0, $2
    /* 39CDE4 0049CDE4 C8160270 */  ppacb      $2, $0, $2
    /* 39CDE8 0049CDE8 4000A2AF */  sw         $2, 0x40($29)
    /* 39CDEC 0049CDEC 4000A28F */  lw         $2, 0x40($29)
    /* 39CDF0 0049CDF0 4C00A2AF */  sw         $2, 0x4C($29)
    /* 39CDF4 0049CDF4 4F00A293 */  lbu        $2, 0x4F($29)
    /* 39CDF8 0049CDF8 FF000724 */  addiu      $7, $0, 0xFF
    /* 39CDFC 0049CDFC 0C004710 */  beq        $2, $7, .L0049CE30
    /* 39CE00 0049CE00 00000000 */   nop
    /* 39CE04 0049CE04 1400068E */  lw         $6, 0x14($16)
    /* 39CE08 0049CE08 4C00A593 */  lbu        $5, 0x4C($29)
    /* 39CE0C 0049CE0C 4D00A493 */  lbu        $4, 0x4D($29)
    /* 39CE10 0049CE10 4E00A393 */  lbu        $3, 0x4E($29)
    /* 39CE14 0049CE14 4F00A293 */  lbu        $2, 0x4F($29)
    /* 39CE18 0049CE18 0400C5A0 */  sb         $5, 0x4($6)
    /* 39CE1C 0049CE1C 0500C4A0 */  sb         $4, 0x5($6)
    /* 39CE20 0049CE20 0600C3A0 */  sb         $3, 0x6($6)
    /* 39CE24 0049CE24 0700C2A0 */  sb         $2, 0x7($6)
    /* 39CE28 0049CE28 0D000010 */  b          .L0049CE60
    /* 39CE2C 0049CE2C 00000000 */   nop
  .L0049CE30:
    /* 39CE30 0049CE30 FE000224 */  addiu      $2, $0, 0xFE
    /* 39CE34 0049CE34 4F00A2A3 */  sb         $2, 0x4F($29)
    /* 39CE38 0049CE38 1400068E */  lw         $6, 0x14($16)
    /* 39CE3C 0049CE3C 4C00A593 */  lbu        $5, 0x4C($29)
    /* 39CE40 0049CE40 4D00A493 */  lbu        $4, 0x4D($29)
    /* 39CE44 0049CE44 4E00A393 */  lbu        $3, 0x4E($29)
    /* 39CE48 0049CE48 4F00A293 */  lbu        $2, 0x4F($29)
    /* 39CE4C 0049CE4C 0400C5A0 */  sb         $5, 0x4($6)
    /* 39CE50 0049CE50 0500C4A0 */  sb         $4, 0x5($6)
    /* 39CE54 0049CE54 0600C3A0 */  sb         $3, 0x6($6)
    /* 39CE58 0049CE58 0700C2A0 */  sb         $2, 0x7($6)
    /* 39CE5C 0049CE5C 4F00A7A3 */  sb         $7, 0x4F($29)
  .L0049CE60:
    /* 39CE60 0049CE60 2D200002 */  daddu      $4, $16, $0
    /* 39CE64 0049CE64 2D284002 */  daddu      $5, $18, $0
    /* 39CE68 0049CE68 10004626 */  addiu      $6, $18, 0x10
    /* 39CE6C 0049CE6C 20004726 */  addiu      $7, $18, 0x20
    /* 39CE70 0049CE70 AC0D120C */  jal        func_004836b0
    /* 39CE74 0049CE74 00000000 */   nop
    /* 39CE78 0049CE78 56002292 */  lbu        $2, 0x56($17)
    /* 39CE7C 0049CE7C 06004010 */  beqz       $2, .L0049CE98
    /* 39CE80 0049CE80 00000000 */   nop
    /* 39CE84 0049CE84 00000296 */  lhu        $2, 0x0($16)
    /* 39CE88 0049CE88 01004234 */  ori        $2, $2, 0x1
    /* 39CE8C 0049CE8C 000002A6 */  sh         $2, 0x0($16)
    /* 39CE90 0049CE90 04000010 */  b          .L0049CEA4
    /* 39CE94 0049CE94 00000000 */   nop
  .L0049CE98:
    /* 39CE98 0049CE98 00000296 */  lhu        $2, 0x0($16)
    /* 39CE9C 0049CE9C FEFF4230 */  andi       $2, $2, 0xFFFE
    /* 39CEA0 0049CEA0 000002A6 */  sh         $2, 0x0($16)
  .L0049CEA4:
    /* 39CEA4 0049CEA4 28002596 */  lhu        $5, 0x28($17)
    /* 39CEA8 0049CEA8 2D200002 */  daddu      $4, $16, $0
    /* 39CEAC 0049CEAC 240D120C */  jal        func_00483490
    /* 39CEB0 0049CEB0 00000000 */   nop
  .L0049CEB4:
    /* 39CEB4 0049CEB4 3000BFDF */  ld         $31, 0x30($29)
    /* 39CEB8 0049CEB8 2000B27B */  lq         $18, 0x20($29)
    /* 39CEBC 0049CEBC 1000B17B */  lq         $17, 0x10($29)
    /* 39CEC0 0049CEC0 0000B07B */  lq         $16, 0x0($29)
    /* 39CEC4 0049CEC4 5000BD27 */  addiu      $29, $29, 0x50
    /* 39CEC8 0049CEC8 0800E003 */  jr         $31
    /* 39CECC 0049CECC 00000000 */   nop
.size func_0049cd10, 0x1c0
