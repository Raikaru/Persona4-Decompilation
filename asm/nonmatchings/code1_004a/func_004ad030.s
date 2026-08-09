.section .text
.set noat
.set noreorder
glabel func_004ad030
    /* 3AD030 004AD030 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 3AD034 004AD034 4000BFFF */  sd         $31, 0x40($29)
    /* 3AD038 004AD038 3000B37F */  sq         $19, 0x30($29)
    /* 3AD03C 004AD03C 2000B27F */  sq         $18, 0x20($29)
    /* 3AD040 004AD040 1000B17F */  sq         $17, 0x10($29)
    /* 3AD044 004AD044 0000B07F */  sq         $16, 0x0($29)
    /* 3AD048 004AD048 2D988000 */  daddu      $19, $4, $0
    /* 3AD04C 004AD04C 2D90A000 */  daddu      $18, $5, $0
    /* 3AD050 004AD050 B400A48C */  lw         $4, 0xB4($5)
    /* 3AD054 004AD054 2D280000 */  daddu      $5, $0, $0
    /* 3AD058 004AD058 20E8110C */  jal        func_0047a080
    /* 3AD05C 004AD05C 00000000 */   nop
    /* 3AD060 004AD060 004F033C */  lui        $3, (0x4F000000 >> 16)
    /* 3AD064 004AD064 00088344 */  mtc1       $3, $f1
    /* 3AD068 004AD068 00000000 */  nop
    /* 3AD06C 004AD06C 36080046 */  c.le.s     $f1, $f0
    /* 3AD070 004AD070 05000145 */  bc1t       .L004AD088
    /* 3AD074 004AD074 00000000 */   nop
    /* 3AD078 004AD078 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 3AD07C 004AD07C 00001144 */  mfc1       $17, $f0
    /* 3AD080 004AD080 06000010 */  b          .L004AD09C
    /* 3AD084 004AD084 00000000 */   nop
  .L004AD088:
    /* 3AD088 004AD088 01000146 */  sub.s      $f0, $f0, $f1
    /* 3AD08C 004AD08C 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 3AD090 004AD090 00001144 */  mfc1       $17, $f0
    /* 3AD094 004AD094 0080033C */  lui        $3, (0x80000000 >> 16)
    /* 3AD098 004AD098 25882302 */  or         $17, $17, $3
  .L004AD09C:
    /* 3AD09C 004AD09C 9C00508E */  lw         $16, 0x9C($18)
    /* 3AD0A0 004AD0A0 2B081102 */  sltu       $1, $16, $17
    /* 3AD0A4 004AD0A4 03002010 */  beqz       $1, .L004AD0B4
    /* 3AD0A8 004AD0A8 00000000 */   nop
    /* 3AD0AC 004AD0AC 5B000016 */  bnez       $16, .L004AD21C
    /* 3AD0B0 004AD0B0 00000000 */   nop
  .L004AD0B4:
    /* 3AD0B4 004AD0B4 10004426 */  addiu      $4, $18, 0x10
    /* 3AD0B8 004AD0B8 34004526 */  addiu      $5, $18, 0x34
    /* 3AD0BC 004AD0BC 2D302002 */  daddu      $6, $17, $0
    /* 3AD0C0 004AD0C0 2D380002 */  daddu      $7, $16, $0
    /* 3AD0C4 004AD0C4 F42A120C */  jal        func_0048abd0
    /* 3AD0C8 004AD0C8 00000000 */   nop
    /* 3AD0CC 004AD0CC 2D184000 */  daddu      $3, $2, $0
    /* 3AD0D0 004AD0D0 0C00428E */  lw         $2, 0xC($18)
    /* 3AD0D4 004AD0D4 5800A2AF */  sw         $2, 0x58($29)
    /* 3AD0D8 004AD0D8 5800A227 */  addiu      $2, $29, 0x58
    /* 3AD0DC 004AD0DC 448080C7 */  lwc1       $f0, -0x7FBC($28)
    /* 3AD0E0 004AD0E0 0000428C */  lw         $2, 0x0($2)
    /* 3AD0E4 004AD0E4 88160270 */  pextlb     $2, $0, $2
    /* 3AD0E8 004AD0E8 88150270 */  pextlh     $2, $0, $2
    /* 3AD0EC 004AD0EC 0050A248 */  qmtc2.ni   $2, $vf10
    /* 3AD0F0 004AD0F0 3C51EA4B */  vitof0.xyzw $vf10, $vf10
    /* 3AD0F4 004AD0F4 00000244 */  mfc1       $2, $f0
    /* 3AD0F8 004AD0F8 00000000 */  nop
    /* 3AD0FC 004AD0FC 0010A248 */  qmtc2.ni   $2, $vf2
    /* 3AD100 004AD100 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3AD104 004AD104 3C53EB4B */  vmove.xyzw $vf11, $vf10
    /* 3AD108 004AD108 5400A3AF */  sw         $3, 0x54($29)
    /* 3AD10C 004AD10C 5400A227 */  addiu      $2, $29, 0x54
    /* 3AD110 004AD110 0000428C */  lw         $2, 0x0($2)
    /* 3AD114 004AD114 88160270 */  pextlb     $2, $0, $2
    /* 3AD118 004AD118 88150270 */  pextlh     $2, $0, $2
    /* 3AD11C 004AD11C 0050A248 */  qmtc2.ni   $2, $vf10
    /* 3AD120 004AD120 3C51EA4B */  vitof0.xyzw $vf10, $vf10
    /* 3AD124 004AD124 00000244 */  mfc1       $2, $f0
    /* 3AD128 004AD128 00000000 */  nop
    /* 3AD12C 004AD12C 0010A248 */  qmtc2.ni   $2, $vf2
    /* 3AD130 004AD130 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3AD134 004AD134 AA52EB4B */  vmul.xyzw  $vf10, $vf10, $vf11
    /* 3AD138 004AD138 7F43023C */  lui        $2, (0x437F0000 >> 16)
    /* 3AD13C 004AD13C 0010A248 */  qmtc2.ni   $2, $vf2
    /* 3AD140 004AD140 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3AD144 004AD144 7C51EA4B */  vftoi0.xyzw $vf10, $vf10
    /* 3AD148 004AD148 00502248 */  qmfc2.ni   $2, $vf10
    /* 3AD14C 004AD14C C8150270 */  ppach      $2, $0, $2
    /* 3AD150 004AD150 C8160270 */  ppacb      $2, $0, $2
    /* 3AD154 004AD154 5000A2AF */  sw         $2, 0x50($29)
    /* 3AD158 004AD158 5000A28F */  lw         $2, 0x50($29)
    /* 3AD15C 004AD15C 5C00A2AF */  sw         $2, 0x5C($29)
    /* 3AD160 004AD160 B400448E */  lw         $4, 0xB4($18)
    /* 3AD164 004AD164 5C00A527 */  addiu      $5, $29, 0x5C
    /* 3AD168 004AD168 88E8110C */  jal        func_0047a220
    /* 3AD16C 004AD16C 00000000 */   nop
    /* 3AD170 004AD170 44004426 */  addiu      $4, $18, 0x44
    /* 3AD174 004AD174 2D282002 */  daddu      $5, $17, $0
    /* 3AD178 004AD178 2D300002 */  daddu      $6, $16, $0
    /* 3AD17C 004AD17C FC2B120C */  jal        func_0048aff0
    /* 3AD180 004AD180 00000000 */   nop
    /* 3AD184 004AD184 B400448E */  lw         $4, 0xB4($18)
    /* 3AD188 004AD188 D800838C */  lw         $3, 0xD8($4)
    /* 3AD18C 004AD18C FFFE0224 */  addiu      $2, $0, -0x101
    /* 3AD190 004AD190 24106200 */  and        $2, $3, $2
    /* 3AD194 004AD194 D80082AC */  sw         $2, 0xD8($4)
    /* 3AD198 004AD198 A1004292 */  lbu        $2, 0xA1($18)
    /* 3AD19C 004AD19C 0A004010 */  beqz       $2, .L004AD1C8
    /* 3AD1A0 004AD1A0 00000000 */   nop
    /* 3AD1A4 004AD1A4 A400428E */  lw         $2, 0xA4($18)
    /* 3AD1A8 004AD1A8 07004014 */  bnez       $2, .L004AD1C8
    /* 3AD1AC 004AD1AC 00000000 */   nop
    /* 3AD1B0 004AD1B0 B400438E */  lw         $3, 0xB4($18)
    /* 3AD1B4 004AD1B4 D800628C */  lw         $2, 0xD8($3)
    /* 3AD1B8 004AD1B8 18004234 */  ori        $2, $2, 0x18
    /* 3AD1BC 004AD1BC D80062AC */  sw         $2, 0xD8($3)
    /* 3AD1C0 004AD1C0 06000010 */  b          .L004AD1DC
    /* 3AD1C4 004AD1C4 00000000 */   nop
  .L004AD1C8:
    /* 3AD1C8 004AD1C8 B400448E */  lw         $4, 0xB4($18)
    /* 3AD1CC 004AD1CC D800838C */  lw         $3, 0xD8($4)
    /* 3AD1D0 004AD1D0 E7FF0224 */  addiu      $2, $0, -0x19
    /* 3AD1D4 004AD1D4 24106200 */  and        $2, $3, $2
    /* 3AD1D8 004AD1D8 D80082AC */  sw         $2, 0xD8($4)
  .L004AD1DC:
    /* 3AD1DC 004AD1DC B400448E */  lw         $4, 0xB4($18)
    /* 3AD1E0 004AD1E0 2D280000 */  daddu      $5, $0, $0
    /* 3AD1E4 004AD1E4 08004CC6 */  lwc1       $f12, 0x8($18)
    /* 3AD1E8 004AD1E8 38E8110C */  jal        func_0047a0e0
    /* 3AD1EC 004AD1EC 00000000 */   nop
    /* 3AD1F0 004AD1F0 1405120C */  jal        func_00481450
    /* 3AD1F4 004AD1F4 00000000 */   nop
    /* 3AD1F8 004AD1F8 B400448E */  lw         $4, 0xB4($18)
    /* 3AD1FC 004AD1FC 2D284000 */  daddu      $5, $2, $0
    /* 3AD200 004AD200 8CEA110C */  jal        func_0047aa30
    /* 3AD204 004AD204 00000000 */   nop
    /* 3AD208 004AD208 2D206002 */  daddu      $4, $19, $0
    /* 3AD20C 004AD20C B400458E */  lw         $5, 0xB4($18)
    /* 3AD210 004AD210 40E4110C */  jal        func_00479100
    /* 3AD214 004AD214 00000000 */   nop
    /* 3AD218 004AD218 080040AE */  sw         $0, 0x8($18)
  .L004AD21C:
    /* 3AD21C 004AD21C 4000BFDF */  ld         $31, 0x40($29)
    /* 3AD220 004AD220 3000B37B */  lq         $19, 0x30($29)
    /* 3AD224 004AD224 2000B27B */  lq         $18, 0x20($29)
    /* 3AD228 004AD228 1000B17B */  lq         $17, 0x10($29)
    /* 3AD22C 004AD22C 0000B07B */  lq         $16, 0x0($29)
    /* 3AD230 004AD230 6000BD27 */  addiu      $29, $29, 0x60
    /* 3AD234 004AD234 0800E003 */  jr         $31
    /* 3AD238 004AD238 00000000 */   nop
    /* 3AD23C 004AD23C 00000000 */  nop
.size func_004ad030, 0x210
