.section .text
.set noat
.set noreorder
glabel func_004a2c90
    /* 3A2C90 004A2C90 50FFBD27 */  addiu      $29, $29, -0xB0
    /* 3A2C94 004A2C94 8000BFFF */  sd         $31, 0x80($29)
    /* 3A2C98 004A2C98 7000B77F */  sq         $23, 0x70($29)
    /* 3A2C9C 004A2C9C 6000B67F */  sq         $22, 0x60($29)
    /* 3A2CA0 004A2CA0 5000B57F */  sq         $21, 0x50($29)
    /* 3A2CA4 004A2CA4 4000B47F */  sq         $20, 0x40($29)
    /* 3A2CA8 004A2CA8 3000B37F */  sq         $19, 0x30($29)
    /* 3A2CAC 004A2CAC 2000B27F */  sq         $18, 0x20($29)
    /* 3A2CB0 004A2CB0 1000B17F */  sq         $17, 0x10($29)
    /* 3A2CB4 004A2CB4 0000B07F */  sq         $16, 0x0($29)
    /* 3A2CB8 004A2CB8 2DA08000 */  daddu      $20, $4, $0
    /* 3A2CBC 004A2CBC 3C00838C */  lw         $3, 0x3C($4)
    /* 3A2CC0 004A2CC0 4000928C */  lw         $18, 0x40($4)
    /* 3A2CC4 004A2CC4 0400708C */  lw         $16, 0x4($3)
    /* 3A2CC8 004A2CC8 3400868C */  lw         $6, 0x34($4)
    /* 3A2CCC 004A2CCC 3400478E */  lw         $7, 0x34($18)
    /* 3A2CD0 004A2CD0 2B08E600 */  sltu       $1, $7, $6
    /* 3A2CD4 004A2CD4 03002010 */  beqz       $1, .L004A2CE4
    /* 3A2CD8 004A2CD8 00000000 */   nop
    /* 3A2CDC 004A2CDC BD00E014 */  bnez       $7, .L004A2FD4
    /* 3A2CE0 004A2CE0 00000000 */   nop
  .L004A2CE4:
    /* 3A2CE4 004A2CE4 0000738C */  lw         $19, 0x0($3)
    /* 3A2CE8 004A2CE8 2D204002 */  daddu      $4, $18, $0
    /* 3A2CEC 004A2CEC 24004526 */  addiu      $5, $18, 0x24
    /* 3A2CF0 004A2CF0 F42A120C */  jal        func_0048abd0
    /* 3A2CF4 004A2CF4 00000000 */   nop
    /* 3A2CF8 004A2CF8 2D184000 */  daddu      $3, $2, $0
    /* 3A2CFC 004A2CFC 3000828E */  lw         $2, 0x30($20)
    /* 3A2D00 004A2D00 A800A2AF */  sw         $2, 0xA8($29)
    /* 3A2D04 004A2D04 A800A227 */  addiu      $2, $29, 0xA8
    /* 3A2D08 004A2D08 448080C7 */  lwc1       $f0, -0x7FBC($28)
    /* 3A2D0C 004A2D0C 0000428C */  lw         $2, 0x0($2)
    /* 3A2D10 004A2D10 88160270 */  pextlb     $2, $0, $2
    /* 3A2D14 004A2D14 88150270 */  pextlh     $2, $0, $2
    /* 3A2D18 004A2D18 0050A248 */  qmtc2.ni   $2, $vf10
    /* 3A2D1C 004A2D1C 3C51EA4B */  vitof0.xyzw $vf10, $vf10
    /* 3A2D20 004A2D20 00000244 */  mfc1       $2, $f0
    /* 3A2D24 004A2D24 00000000 */  nop
    /* 3A2D28 004A2D28 0010A248 */  qmtc2.ni   $2, $vf2
    /* 3A2D2C 004A2D2C 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3A2D30 004A2D30 3C53EB4B */  vmove.xyzw $vf11, $vf10
    /* 3A2D34 004A2D34 A400A3AF */  sw         $3, 0xA4($29)
    /* 3A2D38 004A2D38 A400A227 */  addiu      $2, $29, 0xA4
    /* 3A2D3C 004A2D3C 0000428C */  lw         $2, 0x0($2)
    /* 3A2D40 004A2D40 88160270 */  pextlb     $2, $0, $2
    /* 3A2D44 004A2D44 88150270 */  pextlh     $2, $0, $2
    /* 3A2D48 004A2D48 0050A248 */  qmtc2.ni   $2, $vf10
    /* 3A2D4C 004A2D4C 3C51EA4B */  vitof0.xyzw $vf10, $vf10
    /* 3A2D50 004A2D50 00000244 */  mfc1       $2, $f0
    /* 3A2D54 004A2D54 00000000 */  nop
    /* 3A2D58 004A2D58 0010A248 */  qmtc2.ni   $2, $vf2
    /* 3A2D5C 004A2D5C 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3A2D60 004A2D60 AA52EB4B */  vmul.xyzw  $vf10, $vf10, $vf11
    /* 3A2D64 004A2D64 7F43023C */  lui        $2, (0x437F0000 >> 16)
    /* 3A2D68 004A2D68 0010A248 */  qmtc2.ni   $2, $vf2
    /* 3A2D6C 004A2D6C 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3A2D70 004A2D70 7C51EA4B */  vftoi0.xyzw $vf10, $vf10
    /* 3A2D74 004A2D74 00502248 */  qmfc2.ni   $2, $vf10
    /* 3A2D78 004A2D78 C8150270 */  ppach      $2, $0, $2
    /* 3A2D7C 004A2D7C C8160270 */  ppacb      $2, $0, $2
    /* 3A2D80 004A2D80 A000A2AF */  sw         $2, 0xA0($29)
    /* 3A2D84 004A2D84 A000B68F */  lw         $22, 0xA0($29)
    /* 3A2D88 004A2D88 3800578E */  lw         $23, 0x38($18)
    /* 3A2D8C 004A2D8C 8000558E */  lw         $21, 0x80($18)
    /* 3A2D90 004A2D90 2D880000 */  daddu      $17, $0, $0
    /* 3A2D94 004A2D94 77000010 */  b          .L004A2F74
    /* 3A2D98 004A2D98 00000000 */   nop
  .L004A2D9C:
    /* 3A2D9C 004A2D9C 0000668E */  lw         $6, 0x0($19)
    /* 3A2DA0 004A2DA0 2B08D500 */  sltu       $1, $6, $21
    /* 3A2DA4 004A2DA4 4E002010 */  beqz       $1, .L004A2EE0
    /* 3A2DA8 004A2DA8 00000000 */   nop
    /* 3A2DAC 004A2DAC 3C004426 */  addiu      $4, $18, 0x3C
    /* 3A2DB0 004A2DB0 60004526 */  addiu      $5, $18, 0x60
    /* 3A2DB4 004A2DB4 2D38A002 */  daddu      $7, $21, $0
    /* 3A2DB8 004A2DB8 F42A120C */  jal        func_0048abd0
    /* 3A2DBC 004A2DBC 00000000 */   nop
    /* 3A2DC0 004A2DC0 9C00A2AF */  sw         $2, 0x9C($29)
    /* 3A2DC4 004A2DC4 9C00A227 */  addiu      $2, $29, 0x9C
    /* 3A2DC8 004A2DC8 448080C7 */  lwc1       $f0, -0x7FBC($28)
    /* 3A2DCC 004A2DCC 0000428C */  lw         $2, 0x0($2)
    /* 3A2DD0 004A2DD0 88160270 */  pextlb     $2, $0, $2
    /* 3A2DD4 004A2DD4 88150270 */  pextlh     $2, $0, $2
    /* 3A2DD8 004A2DD8 0050A248 */  qmtc2.ni   $2, $vf10
    /* 3A2DDC 004A2DDC 3C51EA4B */  vitof0.xyzw $vf10, $vf10
    /* 3A2DE0 004A2DE0 00000244 */  mfc1       $2, $f0
    /* 3A2DE4 004A2DE4 00000000 */  nop
    /* 3A2DE8 004A2DE8 0010A248 */  qmtc2.ni   $2, $vf2
    /* 3A2DEC 004A2DEC 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3A2DF0 004A2DF0 3C53EB4B */  vmove.xyzw $vf11, $vf10
    /* 3A2DF4 004A2DF4 9800B6AF */  sw         $22, 0x98($29)
    /* 3A2DF8 004A2DF8 9800A227 */  addiu      $2, $29, 0x98
    /* 3A2DFC 004A2DFC 0000428C */  lw         $2, 0x0($2)
    /* 3A2E00 004A2E00 88160270 */  pextlb     $2, $0, $2
    /* 3A2E04 004A2E04 88150270 */  pextlh     $2, $0, $2
    /* 3A2E08 004A2E08 0050A248 */  qmtc2.ni   $2, $vf10
    /* 3A2E0C 004A2E0C 3C51EA4B */  vitof0.xyzw $vf10, $vf10
    /* 3A2E10 004A2E10 00000244 */  mfc1       $2, $f0
    /* 3A2E14 004A2E14 00000000 */  nop
    /* 3A2E18 004A2E18 0010A248 */  qmtc2.ni   $2, $vf2
    /* 3A2E1C 004A2E1C 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3A2E20 004A2E20 AA52EB4B */  vmul.xyzw  $vf10, $vf10, $vf11
    /* 3A2E24 004A2E24 7F43023C */  lui        $2, (0x437F0000 >> 16)
    /* 3A2E28 004A2E28 0010A248 */  qmtc2.ni   $2, $vf2
    /* 3A2E2C 004A2E2C 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3A2E30 004A2E30 7C51EA4B */  vftoi0.xyzw $vf10, $vf10
    /* 3A2E34 004A2E34 00502248 */  qmfc2.ni   $2, $vf10
    /* 3A2E38 004A2E38 C8150270 */  ppach      $2, $0, $2
    /* 3A2E3C 004A2E3C C8160270 */  ppacb      $2, $0, $2
    /* 3A2E40 004A2E40 9400A2AF */  sw         $2, 0x94($29)
    /* 3A2E44 004A2E44 9400A28F */  lw         $2, 0x94($29)
    /* 3A2E48 004A2E48 AC00A2AF */  sw         $2, 0xAC($29)
    /* 3A2E4C 004A2E4C AF00A293 */  lbu        $2, 0xAF($29)
    /* 3A2E50 004A2E50 FF000724 */  addiu      $7, $0, 0xFF
    /* 3A2E54 004A2E54 10004710 */  beq        $2, $7, .L004A2E98
    /* 3A2E58 004A2E58 00000000 */   nop
    /* 3A2E5C 004A2E5C FFFF2232 */  andi       $2, $17, 0xFFFF
    /* 3A2E60 004A2E60 80180200 */  sll        $3, $2, 2
    /* 3A2E64 004A2E64 5400028E */  lw         $2, 0x54($16)
    /* 3A2E68 004A2E68 21104300 */  addu       $2, $2, $3
    /* 3A2E6C 004A2E6C 0000468C */  lw         $6, 0x0($2)
    /* 3A2E70 004A2E70 AC00A593 */  lbu        $5, 0xAC($29)
    /* 3A2E74 004A2E74 AD00A493 */  lbu        $4, 0xAD($29)
    /* 3A2E78 004A2E78 AE00A393 */  lbu        $3, 0xAE($29)
    /* 3A2E7C 004A2E7C AF00A293 */  lbu        $2, 0xAF($29)
    /* 3A2E80 004A2E80 0400C5A0 */  sb         $5, 0x4($6)
    /* 3A2E84 004A2E84 0500C4A0 */  sb         $4, 0x5($6)
    /* 3A2E88 004A2E88 0600C3A0 */  sb         $3, 0x6($6)
    /* 3A2E8C 004A2E8C 0700C2A0 */  sb         $2, 0x7($6)
    /* 3A2E90 004A2E90 36000010 */  b          .L004A2F6C
    /* 3A2E94 004A2E94 00000000 */   nop
  .L004A2E98:
    /* 3A2E98 004A2E98 FE000224 */  addiu      $2, $0, 0xFE
    /* 3A2E9C 004A2E9C AF00A2A3 */  sb         $2, 0xAF($29)
    /* 3A2EA0 004A2EA0 FFFF2232 */  andi       $2, $17, 0xFFFF
    /* 3A2EA4 004A2EA4 80180200 */  sll        $3, $2, 2
    /* 3A2EA8 004A2EA8 5400028E */  lw         $2, 0x54($16)
    /* 3A2EAC 004A2EAC 21104300 */  addu       $2, $2, $3
    /* 3A2EB0 004A2EB0 0000468C */  lw         $6, 0x0($2)
    /* 3A2EB4 004A2EB4 AC00A593 */  lbu        $5, 0xAC($29)
    /* 3A2EB8 004A2EB8 AD00A493 */  lbu        $4, 0xAD($29)
    /* 3A2EBC 004A2EBC AE00A393 */  lbu        $3, 0xAE($29)
    /* 3A2EC0 004A2EC0 AF00A293 */  lbu        $2, 0xAF($29)
    /* 3A2EC4 004A2EC4 0400C5A0 */  sb         $5, 0x4($6)
    /* 3A2EC8 004A2EC8 0500C4A0 */  sb         $4, 0x5($6)
    /* 3A2ECC 004A2ECC 0600C3A0 */  sb         $3, 0x6($6)
    /* 3A2ED0 004A2ED0 0700C2A0 */  sb         $2, 0x7($6)
    /* 3A2ED4 004A2ED4 AF00A7A3 */  sb         $7, 0xAF($29)
    /* 3A2ED8 004A2ED8 24000010 */  b          .L004A2F6C
    /* 3A2EDC 004A2EDC 00000000 */   nop
  .L004A2EE0:
    /* 3A2EE0 004A2EE0 67BB8293 */  lbu        $2, -0x4499($28)
    /* 3A2EE4 004A2EE4 FF000724 */  addiu      $7, $0, 0xFF
    /* 3A2EE8 004A2EE8 10004710 */  beq        $2, $7, .L004A2F2C
    /* 3A2EEC 004A2EEC 00000000 */   nop
    /* 3A2EF0 004A2EF0 FFFF2232 */  andi       $2, $17, 0xFFFF
    /* 3A2EF4 004A2EF4 80180200 */  sll        $3, $2, 2
    /* 3A2EF8 004A2EF8 5400028E */  lw         $2, 0x54($16)
    /* 3A2EFC 004A2EFC 21104300 */  addu       $2, $2, $3
    /* 3A2F00 004A2F00 0000468C */  lw         $6, 0x0($2)
    /* 3A2F04 004A2F04 64BB8593 */  lbu        $5, -0x449C($28)
    /* 3A2F08 004A2F08 65BB8493 */  lbu        $4, -0x449B($28)
    /* 3A2F0C 004A2F0C 66BB8393 */  lbu        $3, -0x449A($28)
    /* 3A2F10 004A2F10 67BB8293 */  lbu        $2, -0x4499($28)
    /* 3A2F14 004A2F14 0400C5A0 */  sb         $5, 0x4($6)
    /* 3A2F18 004A2F18 0500C4A0 */  sb         $4, 0x5($6)
    /* 3A2F1C 004A2F1C 0600C3A0 */  sb         $3, 0x6($6)
    /* 3A2F20 004A2F20 0700C2A0 */  sb         $2, 0x7($6)
    /* 3A2F24 004A2F24 11000010 */  b          .L004A2F6C
    /* 3A2F28 004A2F28 00000000 */   nop
  .L004A2F2C:
    /* 3A2F2C 004A2F2C FE000224 */  addiu      $2, $0, 0xFE
    /* 3A2F30 004A2F30 67BB82A3 */  sb         $2, -0x4499($28)
    /* 3A2F34 004A2F34 FFFF2232 */  andi       $2, $17, 0xFFFF
    /* 3A2F38 004A2F38 80180200 */  sll        $3, $2, 2
    /* 3A2F3C 004A2F3C 5400028E */  lw         $2, 0x54($16)
    /* 3A2F40 004A2F40 21104300 */  addu       $2, $2, $3
    /* 3A2F44 004A2F44 0000468C */  lw         $6, 0x0($2)
    /* 3A2F48 004A2F48 64BB8593 */  lbu        $5, -0x449C($28)
    /* 3A2F4C 004A2F4C 65BB8493 */  lbu        $4, -0x449B($28)
    /* 3A2F50 004A2F50 66BB8393 */  lbu        $3, -0x449A($28)
    /* 3A2F54 004A2F54 67BB8293 */  lbu        $2, -0x4499($28)
    /* 3A2F58 004A2F58 0400C5A0 */  sb         $5, 0x4($6)
    /* 3A2F5C 004A2F5C 0500C4A0 */  sb         $4, 0x5($6)
    /* 3A2F60 004A2F60 0600C3A0 */  sb         $3, 0x6($6)
    /* 3A2F64 004A2F64 0700C2A0 */  sb         $2, 0x7($6)
    /* 3A2F68 004A2F68 67BB87A3 */  sb         $7, -0x4499($28)
  .L004A2F6C:
    /* 3A2F6C 004A2F6C 01003126 */  addiu      $17, $17, 0x1
    /* 3A2F70 004A2F70 30007326 */  addiu      $19, $19, 0x30
  .L004A2F74:
    /* 3A2F74 004A2F74 2B103702 */  sltu       $2, $17, $23
    /* 3A2F78 004A2F78 88FF4014 */  bnez       $2, .L004A2D9C
    /* 3A2F7C 004A2F7C 00000000 */   nop
    /* 3A2F80 004A2F80 2D200002 */  daddu      $4, $16, $0
    /* 3A2F84 004A2F84 2D288002 */  daddu      $5, $20, $0
    /* 3A2F88 004A2F88 10008626 */  addiu      $6, $20, 0x10
    /* 3A2F8C 004A2F8C 20008726 */  addiu      $7, $20, 0x20
    /* 3A2F90 004A2F90 E810120C */  jal        func_004843a0
    /* 3A2F94 004A2F94 00000000 */   nop
    /* 3A2F98 004A2F98 B9004292 */  lbu        $2, 0xB9($18)
    /* 3A2F9C 004A2F9C 06004010 */  beqz       $2, .L004A2FB8
    /* 3A2FA0 004A2FA0 00000000 */   nop
    /* 3A2FA4 004A2FA4 00000296 */  lhu        $2, 0x0($16)
    /* 3A2FA8 004A2FA8 01004234 */  ori        $2, $2, 0x1
    /* 3A2FAC 004A2FAC 000002A6 */  sh         $2, 0x0($16)
    /* 3A2FB0 004A2FB0 04000010 */  b          .L004A2FC4
    /* 3A2FB4 004A2FB4 00000000 */   nop
  .L004A2FB8:
    /* 3A2FB8 004A2FB8 00000296 */  lhu        $2, 0x0($16)
    /* 3A2FBC 004A2FBC FEFF4230 */  andi       $2, $2, 0xFFFE
    /* 3A2FC0 004A2FC0 000002A6 */  sh         $2, 0x0($16)
  .L004A2FC4:
    /* 3A2FC4 004A2FC4 28004596 */  lhu        $5, 0x28($18)
    /* 3A2FC8 004A2FC8 2D200002 */  daddu      $4, $16, $0
    /* 3A2FCC 004A2FCC A010120C */  jal        func_00484280
    /* 3A2FD0 004A2FD0 00000000 */   nop
  .L004A2FD4:
    /* 3A2FD4 004A2FD4 8000BFDF */  ld         $31, 0x80($29)
    /* 3A2FD8 004A2FD8 7000B77B */  lq         $23, 0x70($29)
    /* 3A2FDC 004A2FDC 6000B67B */  lq         $22, 0x60($29)
    /* 3A2FE0 004A2FE0 5000B57B */  lq         $21, 0x50($29)
    /* 3A2FE4 004A2FE4 4000B47B */  lq         $20, 0x40($29)
    /* 3A2FE8 004A2FE8 3000B37B */  lq         $19, 0x30($29)
    /* 3A2FEC 004A2FEC 2000B27B */  lq         $18, 0x20($29)
    /* 3A2FF0 004A2FF0 1000B17B */  lq         $17, 0x10($29)
    /* 3A2FF4 004A2FF4 0000B07B */  lq         $16, 0x0($29)
    /* 3A2FF8 004A2FF8 B000BD27 */  addiu      $29, $29, 0xB0
    /* 3A2FFC 004A2FFC 0800E003 */  jr         $31
    /* 3A3000 004A3000 00000000 */   nop
    /* 3A3004 004A3004 00000000 */  nop
    /* 3A3008 004A3008 00000000 */  nop
    /* 3A300C 004A300C 00000000 */  nop
.size func_004a2c90, 0x380
