.section .text
.set noat
.set noreorder
glabel func_004aa690
    /* 3AA690 004AA690 70FFBD27 */  addiu      $29, $29, -0x90
    /* 3AA694 004AA694 6000BFFF */  sd         $31, 0x60($29)
    /* 3AA698 004AA698 5000B57F */  sq         $21, 0x50($29)
    /* 3AA69C 004AA69C 4000B47F */  sq         $20, 0x40($29)
    /* 3AA6A0 004AA6A0 3000B37F */  sq         $19, 0x30($29)
    /* 3AA6A4 004AA6A4 2000B27F */  sq         $18, 0x20($29)
    /* 3AA6A8 004AA6A8 1000B17F */  sq         $17, 0x10($29)
    /* 3AA6AC 004AA6AC 0000B07F */  sq         $16, 0x0($29)
    /* 3AA6B0 004AA6B0 2DA08000 */  daddu      $20, $4, $0
    /* 3AA6B4 004AA6B4 2000958C */  lw         $21, 0x20($4)
    /* 3AA6B8 004AA6B8 2400938C */  lw         $19, 0x24($4)
    /* 3AA6BC 004AA6BC C0007226 */  addiu      $18, $19, 0xC0
    /* 3AA6C0 004AA6C0 B800708E */  lw         $16, 0xB8($19)
    /* 3AA6C4 004AA6C4 04000016 */  bnez       $16, .L004AA6D8
    /* 3AA6C8 004AA6C8 00000000 */   nop
    /* 3AA6CC 004AA6CC 2D880000 */  daddu      $17, $0, $0
    /* 3AA6D0 004AA6D0 02000010 */  b          .L004AA6DC
    /* 3AA6D4 004AA6D4 00000000 */   nop
  .L004AA6D8:
    /* 3AA6D8 004AA6D8 1C00918E */  lw         $17, 0x1C($20)
  .L004AA6DC:
    /* 3AA6DC 004AA6DC 2A181102 */  slt        $3, $16, $17
    /* 3AA6E0 004AA6E0 5F006014 */  bnez       $3, .L004AA860
    /* 3AA6E4 004AA6E4 00000000 */   nop
    /* 3AA6E8 004AA6E8 8C006426 */  addiu      $4, $19, 0x8C
    /* 3AA6EC 004AA6EC 2D282002 */  daddu      $5, $17, $0
    /* 3AA6F0 004AA6F0 2D300002 */  daddu      $6, $16, $0
    /* 3AA6F4 004AA6F4 FC2B120C */  jal        func_0048aff0
    /* 3AA6F8 004AA6F8 00000000 */   nop
    /* 3AA6FC 004AA6FC BC006292 */  lbu        $2, 0xBC($19)
    /* 3AA700 004AA700 08004010 */  beqz       $2, .L004AA724
    /* 3AA704 004AA704 00000000 */   nop
    /* 3AA708 004AA708 A043023C */  lui        $2, (0x43A00000 >> 16)
    /* 3AA70C 004AA70C 1C0042AE */  sw         $2, 0x1C($18)
    /* 3AA710 004AA710 6043023C */  lui        $2, (0x43600000 >> 16)
    /* 3AA714 004AA714 200042AE */  sw         $2, 0x20($18)
    /* 3AA718 004AA718 240040E6 */  swc1       $f0, 0x24($18)
    /* 3AA71C 004AA71C 0D000010 */  b          .L004AA754
    /* 3AA720 004AA720 00000000 */   nop
  .L004AA724:
    /* 3AA724 004AA724 140081C6 */  lwc1       $f1, 0x14($20)
    /* 3AA728 004AA728 02030146 */  mul.s      $f12, $f0, $f1
    /* 3AA72C 004AA72C 00008ADA */  lqc2       $vf10, 0x0($20)
    /* 3AA730 004AA730 9429120C */  jal        func_0048a650
    /* 3AA734 004AA734 00000000 */   nop
    /* 3AA738 004AA738 240040E6 */  swc1       $f0, 0x24($18)
    /* 3AA73C 004AA73C 7000A227 */  addiu      $2, $29, 0x70
    /* 3AA740 004AA740 00004AF8 */  sqc2       $vf10, 0x0($2)
    /* 3AA744 004AA744 7000A0C7 */  lwc1       $f0, 0x70($29)
    /* 3AA748 004AA748 1C0040E6 */  swc1       $f0, 0x1C($18)
    /* 3AA74C 004AA74C 7400A0C7 */  lwc1       $f0, 0x74($29)
    /* 3AA750 004AA750 200040E6 */  swc1       $f0, 0x20($18)
  .L004AA754:
    /* 3AA754 004AA754 2D206002 */  daddu      $4, $19, $0
    /* 3AA758 004AA758 24006526 */  addiu      $5, $19, 0x24
    /* 3AA75C 004AA75C 2D302002 */  daddu      $6, $17, $0
    /* 3AA760 004AA760 2D380002 */  daddu      $7, $16, $0
    /* 3AA764 004AA764 F42A120C */  jal        func_0048abd0
    /* 3AA768 004AA768 00000000 */   nop
    /* 3AA76C 004AA76C 2D184000 */  daddu      $3, $2, $0
    /* 3AA770 004AA770 1000828E */  lw         $2, 0x10($20)
    /* 3AA774 004AA774 8C00A2AF */  sw         $2, 0x8C($29)
    /* 3AA778 004AA778 8C00A227 */  addiu      $2, $29, 0x8C
    /* 3AA77C 004AA77C 448080C7 */  lwc1       $f0, -0x7FBC($28)
    /* 3AA780 004AA780 0000428C */  lw         $2, 0x0($2)
    /* 3AA784 004AA784 88160270 */  pextlb     $2, $0, $2
    /* 3AA788 004AA788 88150270 */  pextlh     $2, $0, $2
    /* 3AA78C 004AA78C 0050A248 */  qmtc2.ni   $2, $vf10
    /* 3AA790 004AA790 3C51EA4B */  vitof0.xyzw $vf10, $vf10
    /* 3AA794 004AA794 00000244 */  mfc1       $2, $f0
    /* 3AA798 004AA798 00000000 */  nop
    /* 3AA79C 004AA79C 0010A248 */  qmtc2.ni   $2, $vf2
    /* 3AA7A0 004AA7A0 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3AA7A4 004AA7A4 3C53EB4B */  vmove.xyzw $vf11, $vf10
    /* 3AA7A8 004AA7A8 8800A3AF */  sw         $3, 0x88($29)
    /* 3AA7AC 004AA7AC 8800A227 */  addiu      $2, $29, 0x88
    /* 3AA7B0 004AA7B0 0000428C */  lw         $2, 0x0($2)
    /* 3AA7B4 004AA7B4 88160270 */  pextlb     $2, $0, $2
    /* 3AA7B8 004AA7B8 88150270 */  pextlh     $2, $0, $2
    /* 3AA7BC 004AA7BC 0050A248 */  qmtc2.ni   $2, $vf10
    /* 3AA7C0 004AA7C0 3C51EA4B */  vitof0.xyzw $vf10, $vf10
    /* 3AA7C4 004AA7C4 00000244 */  mfc1       $2, $f0
    /* 3AA7C8 004AA7C8 00000000 */  nop
    /* 3AA7CC 004AA7CC 0010A248 */  qmtc2.ni   $2, $vf2
    /* 3AA7D0 004AA7D0 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3AA7D4 004AA7D4 AA52EB4B */  vmul.xyzw  $vf10, $vf10, $vf11
    /* 3AA7D8 004AA7D8 7F43023C */  lui        $2, (0x437F0000 >> 16)
    /* 3AA7DC 004AA7DC 0010A248 */  qmtc2.ni   $2, $vf2
    /* 3AA7E0 004AA7E0 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3AA7E4 004AA7E4 7C51EA4B */  vftoi0.xyzw $vf10, $vf10
    /* 3AA7E8 004AA7E8 00502248 */  qmfc2.ni   $2, $vf10
    /* 3AA7EC 004AA7EC C8150270 */  ppach      $2, $0, $2
    /* 3AA7F0 004AA7F0 C8160270 */  ppacb      $2, $0, $2
    /* 3AA7F4 004AA7F4 8400A2AF */  sw         $2, 0x84($29)
    /* 3AA7F8 004AA7F8 8400A28F */  lw         $2, 0x84($29)
    /* 3AA7FC 004AA7FC 0C0042AE */  sw         $2, 0xC($18)
    /* 3AA800 004AA800 34006426 */  addiu      $4, $19, 0x34
    /* 3AA804 004AA804 2D282002 */  daddu      $5, $17, $0
    /* 3AA808 004AA808 2D300002 */  daddu      $6, $16, $0
    /* 3AA80C 004AA80C FC2B120C */  jal        func_0048aff0
    /* 3AA810 004AA810 00000000 */   nop
    /* 3AA814 004AA814 F08081C7 */  lwc1       $f1, -0x7F10($28)
    /* 3AA818 004AA818 02080046 */  mul.s      $f0, $f1, $f0
    /* 3AA81C 004AA81C 180040E6 */  swc1       $f0, 0x18($18)
    /* 3AA820 004AA820 60006426 */  addiu      $4, $19, 0x60
    /* 3AA824 004AA824 2D282002 */  daddu      $5, $17, $0
    /* 3AA828 004AA828 2D300002 */  daddu      $6, $16, $0
    /* 3AA82C 004AA82C FC2B120C */  jal        func_0048aff0
    /* 3AA830 004AA830 00000000 */   nop
    /* 3AA834 004AA834 F08081C7 */  lwc1       $f1, -0x7F10($28)
    /* 3AA838 004AA838 02080046 */  mul.s      $f0, $f1, $f0
    /* 3AA83C 004AA83C 140040E6 */  swc1       $f0, 0x14($18)
    /* 3AA840 004AA840 2800628E */  lw         $2, 0x28($19)
    /* 3AA844 004AA844 100042AE */  sw         $2, 0x10($18)
    /* 3AA848 004AA848 2D204002 */  daddu      $4, $18, $0
    /* 3AA84C 004AA84C 2D28A002 */  daddu      $5, $21, $0
    /* 3AA850 004AA850 E4A3120C */  jal        func_004a8f90
    /* 3AA854 004AA854 00000000 */   nop
    /* 3AA858 004AA858 02000010 */  b          .L004AA864
    /* 3AA85C 004AA85C 00000000 */   nop
  .L004AA860:
    /* 3AA860 004AA860 0C0040AE */  sw         $0, 0xC($18)
  .L004AA864:
    /* 3AA864 004AA864 6000BFDF */  ld         $31, 0x60($29)
    /* 3AA868 004AA868 5000B57B */  lq         $21, 0x50($29)
    /* 3AA86C 004AA86C 4000B47B */  lq         $20, 0x40($29)
    /* 3AA870 004AA870 3000B37B */  lq         $19, 0x30($29)
    /* 3AA874 004AA874 2000B27B */  lq         $18, 0x20($29)
    /* 3AA878 004AA878 1000B17B */  lq         $17, 0x10($29)
    /* 3AA87C 004AA87C 0000B07B */  lq         $16, 0x0($29)
    /* 3AA880 004AA880 9000BD27 */  addiu      $29, $29, 0x90
    /* 3AA884 004AA884 0800E003 */  jr         $31
    /* 3AA888 004AA888 00000000 */   nop
    /* 3AA88C 004AA88C 00000000 */  nop
.size func_004aa690, 0x200
