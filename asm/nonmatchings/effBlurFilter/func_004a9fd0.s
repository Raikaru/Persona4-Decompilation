.section .text
.set noat
.set noreorder
glabel func_004a9fd0
    /* 3A9FD0 004A9FD0 70FFBD27 */  addiu      $29, $29, -0x90
    /* 3A9FD4 004A9FD4 6000BFFF */  sd         $31, 0x60($29)
    /* 3A9FD8 004A9FD8 5000B57F */  sq         $21, 0x50($29)
    /* 3A9FDC 004A9FDC 4000B47F */  sq         $20, 0x40($29)
    /* 3A9FE0 004A9FE0 3000B37F */  sq         $19, 0x30($29)
    /* 3A9FE4 004A9FE4 2000B27F */  sq         $18, 0x20($29)
    /* 3A9FE8 004A9FE8 1000B17F */  sq         $17, 0x10($29)
    /* 3A9FEC 004A9FEC 0000B07F */  sq         $16, 0x0($29)
    /* 3A9FF0 004A9FF0 2DA08000 */  daddu      $20, $4, $0
    /* 3A9FF4 004A9FF4 2000958C */  lw         $21, 0x20($4)
    /* 3A9FF8 004A9FF8 2400938C */  lw         $19, 0x24($4)
    /* 3A9FFC 004A9FFC C0007226 */  addiu      $18, $19, 0xC0
    /* 3AA000 004AA000 B800708E */  lw         $16, 0xB8($19)
    /* 3AA004 004AA004 04000016 */  bnez       $16, .L004AA018
    /* 3AA008 004AA008 00000000 */   nop
    /* 3AA00C 004AA00C 2D880000 */  daddu      $17, $0, $0
    /* 3AA010 004AA010 02000010 */  b          .L004AA01C
    /* 3AA014 004AA014 00000000 */   nop
  .L004AA018:
    /* 3AA018 004AA018 1C00918E */  lw         $17, 0x1C($20)
  .L004AA01C:
    /* 3AA01C 004AA01C 2A181102 */  slt        $3, $16, $17
    /* 3AA020 004AA020 65006014 */  bnez       $3, .L004AA1B8
    /* 3AA024 004AA024 00000000 */   nop
    /* 3AA028 004AA028 8C006426 */  addiu      $4, $19, 0x8C
    /* 3AA02C 004AA02C 2D282002 */  daddu      $5, $17, $0
    /* 3AA030 004AA030 2D300002 */  daddu      $6, $16, $0
    /* 3AA034 004AA034 FC2B120C */  jal        func_0048aff0
    /* 3AA038 004AA038 00000000 */   nop
    /* 3AA03C 004AA03C BC006292 */  lbu        $2, 0xBC($19)
    /* 3AA040 004AA040 0B004010 */  beqz       $2, .L004AA070
    /* 3AA044 004AA044 00000000 */   nop
    /* 3AA048 004AA048 A043023C */  lui        $2, (0x43A00000 >> 16)
    /* 3AA04C 004AA04C 200042AE */  sw         $2, 0x20($18)
    /* 3AA050 004AA050 6043023C */  lui        $2, (0x43600000 >> 16)
    /* 3AA054 004AA054 240042AE */  sw         $2, 0x24($18)
    /* 3AA058 004AA058 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 3AA05C 004AA05C 00000244 */  mfc1       $2, $f0
    /* 3AA060 004AA060 00000000 */  nop
    /* 3AA064 004AA064 280042AE */  sw         $2, 0x28($18)
    /* 3AA068 004AA068 10000010 */  b          .L004AA0AC
    /* 3AA06C 004AA06C 00000000 */   nop
  .L004AA070:
    /* 3AA070 004AA070 140081C6 */  lwc1       $f1, 0x14($20)
    /* 3AA074 004AA074 02030146 */  mul.s      $f12, $f0, $f1
    /* 3AA078 004AA078 00008ADA */  lqc2       $vf10, 0x0($20)
    /* 3AA07C 004AA07C 9429120C */  jal        func_0048a650
    /* 3AA080 004AA080 00000000 */   nop
    /* 3AA084 004AA084 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 3AA088 004AA088 00000244 */  mfc1       $2, $f0
    /* 3AA08C 004AA08C 00000000 */  nop
    /* 3AA090 004AA090 280042AE */  sw         $2, 0x28($18)
    /* 3AA094 004AA094 7000A227 */  addiu      $2, $29, 0x70
    /* 3AA098 004AA098 00004AF8 */  sqc2       $vf10, 0x0($2)
    /* 3AA09C 004AA09C 7000A0C7 */  lwc1       $f0, 0x70($29)
    /* 3AA0A0 004AA0A0 200040E6 */  swc1       $f0, 0x20($18)
    /* 3AA0A4 004AA0A4 7400A0C7 */  lwc1       $f0, 0x74($29)
    /* 3AA0A8 004AA0A8 240040E6 */  swc1       $f0, 0x24($18)
  .L004AA0AC:
    /* 3AA0AC 004AA0AC 2D206002 */  daddu      $4, $19, $0
    /* 3AA0B0 004AA0B0 24006526 */  addiu      $5, $19, 0x24
    /* 3AA0B4 004AA0B4 2D302002 */  daddu      $6, $17, $0
    /* 3AA0B8 004AA0B8 2D380002 */  daddu      $7, $16, $0
    /* 3AA0BC 004AA0BC F42A120C */  jal        func_0048abd0
    /* 3AA0C0 004AA0C0 00000000 */   nop
    /* 3AA0C4 004AA0C4 2D184000 */  daddu      $3, $2, $0
    /* 3AA0C8 004AA0C8 1000828E */  lw         $2, 0x10($20)
    /* 3AA0CC 004AA0CC 8C00A2AF */  sw         $2, 0x8C($29)
    /* 3AA0D0 004AA0D0 8C00A227 */  addiu      $2, $29, 0x8C
    /* 3AA0D4 004AA0D4 448080C7 */  lwc1       $f0, -0x7FBC($28)
    /* 3AA0D8 004AA0D8 0000428C */  lw         $2, 0x0($2)
    /* 3AA0DC 004AA0DC 88160270 */  pextlb     $2, $0, $2
    /* 3AA0E0 004AA0E0 88150270 */  pextlh     $2, $0, $2
    /* 3AA0E4 004AA0E4 0050A248 */  qmtc2.ni   $2, $vf10
    /* 3AA0E8 004AA0E8 3C51EA4B */  vitof0.xyzw $vf10, $vf10
    /* 3AA0EC 004AA0EC 00000244 */  mfc1       $2, $f0
    /* 3AA0F0 004AA0F0 00000000 */  nop
    /* 3AA0F4 004AA0F4 0010A248 */  qmtc2.ni   $2, $vf2
    /* 3AA0F8 004AA0F8 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3AA0FC 004AA0FC 3C53EB4B */  vmove.xyzw $vf11, $vf10
    /* 3AA100 004AA100 8800A3AF */  sw         $3, 0x88($29)
    /* 3AA104 004AA104 8800A227 */  addiu      $2, $29, 0x88
    /* 3AA108 004AA108 0000428C */  lw         $2, 0x0($2)
    /* 3AA10C 004AA10C 88160270 */  pextlb     $2, $0, $2
    /* 3AA110 004AA110 88150270 */  pextlh     $2, $0, $2
    /* 3AA114 004AA114 0050A248 */  qmtc2.ni   $2, $vf10
    /* 3AA118 004AA118 3C51EA4B */  vitof0.xyzw $vf10, $vf10
    /* 3AA11C 004AA11C 00000244 */  mfc1       $2, $f0
    /* 3AA120 004AA120 00000000 */  nop
    /* 3AA124 004AA124 0010A248 */  qmtc2.ni   $2, $vf2
    /* 3AA128 004AA128 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3AA12C 004AA12C AA52EB4B */  vmul.xyzw  $vf10, $vf10, $vf11
    /* 3AA130 004AA130 7F43023C */  lui        $2, (0x437F0000 >> 16)
    /* 3AA134 004AA134 0010A248 */  qmtc2.ni   $2, $vf2
    /* 3AA138 004AA138 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3AA13C 004AA13C 7C51EA4B */  vftoi0.xyzw $vf10, $vf10
    /* 3AA140 004AA140 00502248 */  qmfc2.ni   $2, $vf10
    /* 3AA144 004AA144 C8150270 */  ppach      $2, $0, $2
    /* 3AA148 004AA148 C8160270 */  ppacb      $2, $0, $2
    /* 3AA14C 004AA14C 8400A2AF */  sw         $2, 0x84($29)
    /* 3AA150 004AA150 8400A28F */  lw         $2, 0x84($29)
    /* 3AA154 004AA154 0C0042AE */  sw         $2, 0xC($18)
    /* 3AA158 004AA158 34006426 */  addiu      $4, $19, 0x34
    /* 3AA15C 004AA15C 2D282002 */  daddu      $5, $17, $0
    /* 3AA160 004AA160 2D300002 */  daddu      $6, $16, $0
    /* 3AA164 004AA164 FC2B120C */  jal        func_0048aff0
    /* 3AA168 004AA168 00000000 */   nop
    /* 3AA16C 004AA16C F08081C7 */  lwc1       $f1, -0x7F10($28)
    /* 3AA170 004AA170 02080046 */  mul.s      $f0, $f1, $f0
    /* 3AA174 004AA174 1C0040E6 */  swc1       $f0, 0x1C($18)
    /* 3AA178 004AA178 60006426 */  addiu      $4, $19, 0x60
    /* 3AA17C 004AA17C 2D282002 */  daddu      $5, $17, $0
    /* 3AA180 004AA180 2D300002 */  daddu      $6, $16, $0
    /* 3AA184 004AA184 FC2B120C */  jal        func_0048aff0
    /* 3AA188 004AA188 00000000 */   nop
    /* 3AA18C 004AA18C F08081C7 */  lwc1       $f1, -0x7F10($28)
    /* 3AA190 004AA190 02080046 */  mul.s      $f0, $f1, $f0
    /* 3AA194 004AA194 140040E6 */  swc1       $f0, 0x14($18)
    /* 3AA198 004AA198 2800628E */  lw         $2, 0x28($19)
    /* 3AA19C 004AA19C 100042AE */  sw         $2, 0x10($18)
    /* 3AA1A0 004AA1A0 2D204002 */  daddu      $4, $18, $0
    /* 3AA1A4 004AA1A4 2D28A002 */  daddu      $5, $21, $0
    /* 3AA1A8 004AA1A8 60A4120C */  jal        func_004a9180
    /* 3AA1AC 004AA1AC 00000000 */   nop
    /* 3AA1B0 004AA1B0 02000010 */  b          .L004AA1BC
    /* 3AA1B4 004AA1B4 00000000 */   nop
  .L004AA1B8:
    /* 3AA1B8 004AA1B8 0C0040AE */  sw         $0, 0xC($18)
  .L004AA1BC:
    /* 3AA1BC 004AA1BC 6000BFDF */  ld         $31, 0x60($29)
    /* 3AA1C0 004AA1C0 5000B57B */  lq         $21, 0x50($29)
    /* 3AA1C4 004AA1C4 4000B47B */  lq         $20, 0x40($29)
    /* 3AA1C8 004AA1C8 3000B37B */  lq         $19, 0x30($29)
    /* 3AA1CC 004AA1CC 2000B27B */  lq         $18, 0x20($29)
    /* 3AA1D0 004AA1D0 1000B17B */  lq         $17, 0x10($29)
    /* 3AA1D4 004AA1D4 0000B07B */  lq         $16, 0x0($29)
    /* 3AA1D8 004AA1D8 9000BD27 */  addiu      $29, $29, 0x90
    /* 3AA1DC 004AA1DC 0800E003 */  jr         $31
    /* 3AA1E0 004AA1E0 00000000 */   nop
    /* 3AA1E4 004AA1E4 00000000 */  nop
    /* 3AA1E8 004AA1E8 00000000 */  nop
    /* 3AA1EC 004AA1EC 00000000 */  nop
.size func_004a9fd0, 0x220
