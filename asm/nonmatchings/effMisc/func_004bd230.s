.section .text
.set noat
.set noreorder
glabel func_004bd230
    /* 3BD230 004BD230 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 3BD234 004BD234 3000BFFF */  sd         $31, 0x30($29)
    /* 3BD238 004BD238 2000B17F */  sq         $17, 0x20($29)
    /* 3BD23C 004BD23C 1000B07F */  sq         $16, 0x10($29)
    /* 3BD240 004BD240 0400B5E7 */  swc1       $f21, 0x4($29)
    /* 3BD244 004BD244 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 3BD248 004BD248 46650046 */  mov.s      $f21, $f12
    /* 3BD24C 004BD24C 2D888000 */  daddu      $17, $4, $0
    /* 3BD250 004BD250 2D80A000 */  daddu      $16, $5, $0
    /* 3BD254 004BD254 842D110C */  jal        func_0044b610
    /* 3BD258 004BD258 00000000 */   nop
    /* 3BD25C 004BD25C 06050046 */  mov.s      $f20, $f0
    /* 3BD260 004BD260 06AB0046 */  mov.s      $f12, $f21
    /* 3BD264 004BD264 EC2D110C */  jal        func_0044b7b0
    /* 3BD268 004BD268 00000000 */   nop
    /* 3BD26C 004BD26C 00002ADA */  lqc2       $vf10, 0x0($17)
    /* 3BD270 004BD270 AA50CA4B */  vmul.xyz   $vf2, $vf10, $vf10
    /* 3BD274 004BD274 BC01224A */  vmulax.w   $ACC, $vf0, $vf2x
    /* 3BD278 004BD278 BD00224A */  vmadday.w  $ACC, $vf0, $vf2y
    /* 3BD27C 004BD27C 8A00224A */  vmaddz.w   $vf2, $vf0, $vf2z
    /* 3BD280 004BD280 BE03E24B */  vrsqrt     $Q, $vf0w, $vf2w
    /* 3BD284 004BD284 BF03004A */  vwaitq
    /* 3BD288 004BD288 9C52C04B */  vmulq.xyz  $vf10, $vf10, $Q
    /* 3BD28C 004BD28C 4000A327 */  addiu      $3, $29, 0x40
    /* 3BD290 004BD290 00006AF8 */  sqc2       $vf10, 0x0($3)
    /* 3BD294 004BD294 4000ABC7 */  lwc1       $f11, 0x40($29)
    /* 3BD298 004BD298 4400AAC7 */  lwc1       $f10, 0x44($29)
    /* 3BD29C 004BD29C 4800A9C7 */  lwc1       $f9, 0x48($29)
    /* 3BD2A0 004BD2A0 82580B46 */  mul.s      $f2, $f11, $f11
    /* 3BD2A4 004BD2A4 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* 3BD2A8 004BD2A8 00408344 */  mtc1       $3, $f8
    /* 3BD2AC 004BD2AC 00000000 */  nop
    /* 3BD2B0 004BD2B0 41400246 */  sub.s      $f1, $f8, $f2
    /* 3BD2B4 004BD2B4 00388044 */  mtc1       $0, $f7
    /* 3BD2B8 004BD2B8 00000000 */  nop
    /* 3BD2BC 004BD2BC 18380246 */  adda.s     $f7, $f2
    /* 3BD2C0 004BD2C0 5C081446 */  madd.s     $f1, $f1, $f20
    /* 3BD2C4 004BD2C4 000001E6 */  swc1       $f1, 0x0($16)
    /* 3BD2C8 004BD2C8 42580A46 */  mul.s      $f1, $f11, $f10
    /* 3BD2CC 004BD2CC 81411446 */  sub.s      $f6, $f8, $f20
    /* 3BD2D0 004BD2D0 42490046 */  mul.s      $f5, $f9, $f0
    /* 3BD2D4 004BD2D4 82080646 */  mul.s      $f2, $f1, $f6
    /* 3BD2D8 004BD2D8 40280246 */  add.s      $f1, $f5, $f2
    /* 3BD2DC 004BD2DC 040001E6 */  swc1       $f1, 0x4($16)
    /* 3BD2E0 004BD2E0 42580946 */  mul.s      $f1, $f11, $f9
    /* 3BD2E4 004BD2E4 02510046 */  mul.s      $f4, $f10, $f0
    /* 3BD2E8 004BD2E8 C2080646 */  mul.s      $f3, $f1, $f6
    /* 3BD2EC 004BD2EC 41180446 */  sub.s      $f1, $f3, $f4
    /* 3BD2F0 004BD2F0 080001E6 */  swc1       $f1, 0x8($16)
    /* 3BD2F4 004BD2F4 0C0000AE */  sw         $0, 0xC($16)
    /* 3BD2F8 004BD2F8 41100546 */  sub.s      $f1, $f2, $f5
    /* 3BD2FC 004BD2FC 100001E6 */  swc1       $f1, 0x10($16)
    /* 3BD300 004BD300 82500A46 */  mul.s      $f2, $f10, $f10
    /* 3BD304 004BD304 41400246 */  sub.s      $f1, $f8, $f2
    /* 3BD308 004BD308 18380246 */  adda.s     $f7, $f2
    /* 3BD30C 004BD30C 5C081446 */  madd.s     $f1, $f1, $f20
    /* 3BD310 004BD310 140001E6 */  swc1       $f1, 0x14($16)
    /* 3BD314 004BD314 42500946 */  mul.s      $f1, $f10, $f9
    /* 3BD318 004BD318 82580046 */  mul.s      $f2, $f11, $f0
    /* 3BD31C 004BD31C 42080646 */  mul.s      $f1, $f1, $f6
    /* 3BD320 004BD320 00100146 */  add.s      $f0, $f2, $f1
    /* 3BD324 004BD324 180000E6 */  swc1       $f0, 0x18($16)
    /* 3BD328 004BD328 1C0000AE */  sw         $0, 0x1C($16)
    /* 3BD32C 004BD32C 00200346 */  add.s      $f0, $f4, $f3
    /* 3BD330 004BD330 200000E6 */  swc1       $f0, 0x20($16)
    /* 3BD334 004BD334 01080246 */  sub.s      $f0, $f1, $f2
    /* 3BD338 004BD338 240000E6 */  swc1       $f0, 0x24($16)
    /* 3BD33C 004BD33C 42480946 */  mul.s      $f1, $f9, $f9
    /* 3BD340 004BD340 01400146 */  sub.s      $f0, $f8, $f1
    /* 3BD344 004BD344 18380146 */  adda.s     $f7, $f1
    /* 3BD348 004BD348 1C001446 */  madd.s     $f0, $f0, $f20
    /* 3BD34C 004BD34C 280000E6 */  swc1       $f0, 0x28($16)
    /* 3BD350 004BD350 2C0000AE */  sw         $0, 0x2C($16)
    /* 3BD354 004BD354 300000FA */  sqc2       $vf0, 0x30($16)
    /* 3BD358 004BD358 3000BFDF */  ld         $31, 0x30($29)
    /* 3BD35C 004BD35C 2000B17B */  lq         $17, 0x20($29)
    /* 3BD360 004BD360 1000B07B */  lq         $16, 0x10($29)
    /* 3BD364 004BD364 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* 3BD368 004BD368 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 3BD36C 004BD36C 5000BD27 */  addiu      $29, $29, 0x50
    /* 3BD370 004BD370 0800E003 */  jr         $31
    /* 3BD374 004BD374 00000000 */   nop
    /* 3BD378 004BD378 00000000 */  nop
    /* 3BD37C 004BD37C 00000000 */  nop
.size func_004bd230, 0x150
