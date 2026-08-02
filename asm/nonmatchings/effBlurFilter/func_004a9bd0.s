.section .text
.set noat
.set noreorder
glabel func_004a9bd0
    /* 3A9BD0 004A9BD0 70FFBD27 */  addiu      $29, $29, -0x90
    /* 3A9BD4 004A9BD4 6000BFFF */  sd         $31, 0x60($29)
    /* 3A9BD8 004A9BD8 5000B57F */  sq         $21, 0x50($29)
    /* 3A9BDC 004A9BDC 4000B47F */  sq         $20, 0x40($29)
    /* 3A9BE0 004A9BE0 3000B37F */  sq         $19, 0x30($29)
    /* 3A9BE4 004A9BE4 2000B27F */  sq         $18, 0x20($29)
    /* 3A9BE8 004A9BE8 1000B17F */  sq         $17, 0x10($29)
    /* 3A9BEC 004A9BEC 0000B07F */  sq         $16, 0x0($29)
    /* 3A9BF0 004A9BF0 2DA08000 */  daddu      $20, $4, $0
    /* 3A9BF4 004A9BF4 2000958C */  lw         $21, 0x20($4)
    /* 3A9BF8 004A9BF8 2400938C */  lw         $19, 0x24($4)
    /* 3A9BFC 004A9BFC C0007226 */  addiu      $18, $19, 0xC0
    /* 3A9C00 004A9C00 B800708E */  lw         $16, 0xB8($19)
    /* 3A9C04 004A9C04 04000016 */  bnez       $16, .L004A9C18
    /* 3A9C08 004A9C08 00000000 */   nop
    /* 3A9C0C 004A9C0C 2D880000 */  daddu      $17, $0, $0
    /* 3A9C10 004A9C10 02000010 */  b          .L004A9C1C
    /* 3A9C14 004A9C14 00000000 */   nop
  .L004A9C18:
    /* 3A9C18 004A9C18 1C00918E */  lw         $17, 0x1C($20)
  .L004A9C1C:
    /* 3A9C1C 004A9C1C 2A181102 */  slt        $3, $16, $17
    /* 3A9C20 004A9C20 5F006014 */  bnez       $3, .L004A9DA0
    /* 3A9C24 004A9C24 00000000 */   nop
    /* 3A9C28 004A9C28 8C006426 */  addiu      $4, $19, 0x8C
    /* 3A9C2C 004A9C2C 2D282002 */  daddu      $5, $17, $0
    /* 3A9C30 004A9C30 2D300002 */  daddu      $6, $16, $0
    /* 3A9C34 004A9C34 FC2B120C */  jal        func_0048aff0
    /* 3A9C38 004A9C38 00000000 */   nop
    /* 3A9C3C 004A9C3C BC006292 */  lbu        $2, 0xBC($19)
    /* 3A9C40 004A9C40 08004010 */  beqz       $2, .L004A9C64
    /* 3A9C44 004A9C44 00000000 */   nop
    /* 3A9C48 004A9C48 A043023C */  lui        $2, (0x43A00000 >> 16)
    /* 3A9C4C 004A9C4C 1C0042AE */  sw         $2, 0x1C($18)
    /* 3A9C50 004A9C50 6043023C */  lui        $2, (0x43600000 >> 16)
    /* 3A9C54 004A9C54 200042AE */  sw         $2, 0x20($18)
    /* 3A9C58 004A9C58 240040E6 */  swc1       $f0, 0x24($18)
    /* 3A9C5C 004A9C5C 0D000010 */  b          .L004A9C94
    /* 3A9C60 004A9C60 00000000 */   nop
  .L004A9C64:
    /* 3A9C64 004A9C64 140081C6 */  lwc1       $f1, 0x14($20)
    /* 3A9C68 004A9C68 02030146 */  mul.s      $f12, $f0, $f1
    /* 3A9C6C 004A9C6C 00008ADA */  lqc2       $vf10, 0x0($20)
    /* 3A9C70 004A9C70 9429120C */  jal        func_0048a650
    /* 3A9C74 004A9C74 00000000 */   nop
    /* 3A9C78 004A9C78 240040E6 */  swc1       $f0, 0x24($18)
    /* 3A9C7C 004A9C7C 7000A227 */  addiu      $2, $29, 0x70
    /* 3A9C80 004A9C80 00004AF8 */  sqc2       $vf10, 0x0($2)
    /* 3A9C84 004A9C84 7000A0C7 */  lwc1       $f0, 0x70($29)
    /* 3A9C88 004A9C88 1C0040E6 */  swc1       $f0, 0x1C($18)
    /* 3A9C8C 004A9C8C 7400A0C7 */  lwc1       $f0, 0x74($29)
    /* 3A9C90 004A9C90 200040E6 */  swc1       $f0, 0x20($18)
  .L004A9C94:
    /* 3A9C94 004A9C94 2D206002 */  daddu      $4, $19, $0
    /* 3A9C98 004A9C98 24006526 */  addiu      $5, $19, 0x24
    /* 3A9C9C 004A9C9C 2D302002 */  daddu      $6, $17, $0
    /* 3A9CA0 004A9CA0 2D380002 */  daddu      $7, $16, $0
    /* 3A9CA4 004A9CA4 F42A120C */  jal        func_0048abd0
    /* 3A9CA8 004A9CA8 00000000 */   nop
    /* 3A9CAC 004A9CAC 2D184000 */  daddu      $3, $2, $0
    /* 3A9CB0 004A9CB0 1000828E */  lw         $2, 0x10($20)
    /* 3A9CB4 004A9CB4 8C00A2AF */  sw         $2, 0x8C($29)
    /* 3A9CB8 004A9CB8 8C00A227 */  addiu      $2, $29, 0x8C
    /* 3A9CBC 004A9CBC 448080C7 */  lwc1       $f0, -0x7FBC($28)
    /* 3A9CC0 004A9CC0 0000428C */  lw         $2, 0x0($2)
    /* 3A9CC4 004A9CC4 88160270 */  pextlb     $2, $0, $2
    /* 3A9CC8 004A9CC8 88150270 */  pextlh     $2, $0, $2
    /* 3A9CCC 004A9CCC 0050A248 */  qmtc2.ni   $2, $vf10
    /* 3A9CD0 004A9CD0 3C51EA4B */  vitof0.xyzw $vf10, $vf10
    /* 3A9CD4 004A9CD4 00000244 */  mfc1       $2, $f0
    /* 3A9CD8 004A9CD8 00000000 */  nop
    /* 3A9CDC 004A9CDC 0010A248 */  qmtc2.ni   $2, $vf2
    /* 3A9CE0 004A9CE0 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3A9CE4 004A9CE4 3C53EB4B */  vmove.xyzw $vf11, $vf10
    /* 3A9CE8 004A9CE8 8800A3AF */  sw         $3, 0x88($29)
    /* 3A9CEC 004A9CEC 8800A227 */  addiu      $2, $29, 0x88
    /* 3A9CF0 004A9CF0 0000428C */  lw         $2, 0x0($2)
    /* 3A9CF4 004A9CF4 88160270 */  pextlb     $2, $0, $2
    /* 3A9CF8 004A9CF8 88150270 */  pextlh     $2, $0, $2
    /* 3A9CFC 004A9CFC 0050A248 */  qmtc2.ni   $2, $vf10
    /* 3A9D00 004A9D00 3C51EA4B */  vitof0.xyzw $vf10, $vf10
    /* 3A9D04 004A9D04 00000244 */  mfc1       $2, $f0
    /* 3A9D08 004A9D08 00000000 */  nop
    /* 3A9D0C 004A9D0C 0010A248 */  qmtc2.ni   $2, $vf2
    /* 3A9D10 004A9D10 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3A9D14 004A9D14 AA52EB4B */  vmul.xyzw  $vf10, $vf10, $vf11
    /* 3A9D18 004A9D18 7F43023C */  lui        $2, (0x437F0000 >> 16)
    /* 3A9D1C 004A9D1C 0010A248 */  qmtc2.ni   $2, $vf2
    /* 3A9D20 004A9D20 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3A9D24 004A9D24 7C51EA4B */  vftoi0.xyzw $vf10, $vf10
    /* 3A9D28 004A9D28 00502248 */  qmfc2.ni   $2, $vf10
    /* 3A9D2C 004A9D2C C8150270 */  ppach      $2, $0, $2
    /* 3A9D30 004A9D30 C8160270 */  ppacb      $2, $0, $2
    /* 3A9D34 004A9D34 8400A2AF */  sw         $2, 0x84($29)
    /* 3A9D38 004A9D38 8400A28F */  lw         $2, 0x84($29)
    /* 3A9D3C 004A9D3C 0C0042AE */  sw         $2, 0xC($18)
    /* 3A9D40 004A9D40 34006426 */  addiu      $4, $19, 0x34
    /* 3A9D44 004A9D44 2D282002 */  daddu      $5, $17, $0
    /* 3A9D48 004A9D48 2D300002 */  daddu      $6, $16, $0
    /* 3A9D4C 004A9D4C FC2B120C */  jal        func_0048aff0
    /* 3A9D50 004A9D50 00000000 */   nop
    /* 3A9D54 004A9D54 F08081C7 */  lwc1       $f1, -0x7F10($28)
    /* 3A9D58 004A9D58 02080046 */  mul.s      $f0, $f1, $f0
    /* 3A9D5C 004A9D5C 180040E6 */  swc1       $f0, 0x18($18)
    /* 3A9D60 004A9D60 60006426 */  addiu      $4, $19, 0x60
    /* 3A9D64 004A9D64 2D282002 */  daddu      $5, $17, $0
    /* 3A9D68 004A9D68 2D300002 */  daddu      $6, $16, $0
    /* 3A9D6C 004A9D6C FC2B120C */  jal        func_0048aff0
    /* 3A9D70 004A9D70 00000000 */   nop
    /* 3A9D74 004A9D74 F08081C7 */  lwc1       $f1, -0x7F10($28)
    /* 3A9D78 004A9D78 02080046 */  mul.s      $f0, $f1, $f0
    /* 3A9D7C 004A9D7C 140040E6 */  swc1       $f0, 0x14($18)
    /* 3A9D80 004A9D80 2800628E */  lw         $2, 0x28($19)
    /* 3A9D84 004A9D84 100042AE */  sw         $2, 0x10($18)
    /* 3A9D88 004A9D88 2D204002 */  daddu      $4, $18, $0
    /* 3A9D8C 004A9D8C 2D28A002 */  daddu      $5, $21, $0
    /* 3A9D90 004A9D90 ECA2120C */  jal        func_004a8bb0
    /* 3A9D94 004A9D94 00000000 */   nop
    /* 3A9D98 004A9D98 02000010 */  b          .L004A9DA4
    /* 3A9D9C 004A9D9C 00000000 */   nop
  .L004A9DA0:
    /* 3A9DA0 004A9DA0 0C0040AE */  sw         $0, 0xC($18)
  .L004A9DA4:
    /* 3A9DA4 004A9DA4 6000BFDF */  ld         $31, 0x60($29)
    /* 3A9DA8 004A9DA8 5000B57B */  lq         $21, 0x50($29)
    /* 3A9DAC 004A9DAC 4000B47B */  lq         $20, 0x40($29)
    /* 3A9DB0 004A9DB0 3000B37B */  lq         $19, 0x30($29)
    /* 3A9DB4 004A9DB4 2000B27B */  lq         $18, 0x20($29)
    /* 3A9DB8 004A9DB8 1000B17B */  lq         $17, 0x10($29)
    /* 3A9DBC 004A9DBC 0000B07B */  lq         $16, 0x0($29)
    /* 3A9DC0 004A9DC0 9000BD27 */  addiu      $29, $29, 0x90
    /* 3A9DC4 004A9DC4 0800E003 */  jr         $31
    /* 3A9DC8 004A9DC8 00000000 */   nop
    /* 3A9DCC 004A9DCC 00000000 */  nop
.size func_004a9bd0, 0x200
