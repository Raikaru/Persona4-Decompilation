.section .text
.set noat
.set noreorder
glabel func_0048a2b0
    /* 38A2B0 0048A2B0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 38A2B4 0048A2B4 2000BFFF */  sd         $31, 0x20($29)
    /* 38A2B8 0048A2B8 1000B17F */  sq         $17, 0x10($29)
    /* 38A2BC 0048A2BC 0000B07F */  sq         $16, 0x0($29)
    /* 38A2C0 0048A2C0 2D888000 */  daddu      $17, $4, $0
    /* 38A2C4 0048A2C4 2D80A000 */  daddu      $16, $5, $0
    /* 38A2C8 0048A2C8 485C110C */  jal        func_00457120
    /* 38A2CC 0048A2CC 00000000 */   nop
    /* 38A2D0 0048A2D0 0400448C */  lw         $4, 0x4($2)
    /* 38A2D4 0048A2D4 C0A50F0C */  jal        func_003e9700
    /* 38A2D8 0048A2D8 00000000 */   nop
    /* 38A2DC 0048A2DC 300040C4 */  lwc1       $f0, 0x30($2)
    /* 38A2E0 0048A2E0 3000A0E7 */  swc1       $f0, 0x30($29)
    /* 38A2E4 0048A2E4 340040C4 */  lwc1       $f0, 0x34($2)
    /* 38A2E8 0048A2E8 3400A0E7 */  swc1       $f0, 0x34($29)
    /* 38A2EC 0048A2EC 380040C4 */  lwc1       $f0, 0x38($2)
    /* 38A2F0 0048A2F0 3800A0E7 */  swc1       $f0, 0x38($29)
    /* 38A2F4 0048A2F4 3C00A0AF */  sw         $0, 0x3C($29)
    /* 38A2F8 0048A2F8 00002ADA */  lqc2       $vf10, 0x0($17)
    /* 38A2FC 0048A2FC 3000A327 */  addiu      $3, $29, 0x30
    /* 38A300 0048A300 00006BD8 */  lqc2       $vf11, 0x0($3)
    /* 38A304 0048A304 AC52EB4B */  vsub.xyzw  $vf10, $vf10, $vf11
    /* 38A308 0048A308 AA50CA4B */  vmul.xyz   $vf2, $vf10, $vf10
    /* 38A30C 0048A30C BC01224A */  vmulax.w   $ACC, $vf0, $vf2x
    /* 38A310 0048A310 BD00224A */  vmadday.w  $ACC, $vf0, $vf2y
    /* 38A314 0048A314 8A00224A */  vmaddz.w   $vf2, $vf0, $vf2z
    /* 38A318 0048A318 BE03E24B */  vrsqrt     $Q, $vf0w, $vf2w
    /* 38A31C 0048A31C BF03004A */  vwaitq
    /* 38A320 0048A320 9C52C04B */  vmulq.xyz  $vf10, $vf10, $Q
    /* 38A324 0048A324 00000AFA */  sqc2       $vf10, 0x0($16)
    /* 38A328 0048A328 2000BFDF */  ld         $31, 0x20($29)
    /* 38A32C 0048A32C 1000B17B */  lq         $17, 0x10($29)
    /* 38A330 0048A330 0000B07B */  lq         $16, 0x0($29)
    /* 38A334 0048A334 4000BD27 */  addiu      $29, $29, 0x40
    /* 38A338 0048A338 0800E003 */  jr         $31
    /* 38A33C 0048A33C 00000000 */   nop
.size func_0048a2b0, 0x90
