.section .text
.set noat
.set noreorder
glabel func_003ab100
    /* 2AB100 003AB100 30FFBD27 */  addiu      $29, $29, -0xD0
    /* 2AB104 003AB104 003F033C */  lui        $3, (0x3F000000 >> 16)
    /* 2AB108 003AB108 A000BFFF */  sd         $31, 0xA0($29)
    /* 2AB10C 003AB10C 00108344 */  mtc1       $3, $f2
    /* 2AB110 003AB110 9000BE7F */  sq         $30, 0x90($29)
    /* 2AB114 003AB114 8000B77F */  sq         $23, 0x80($29)
    /* 2AB118 003AB118 7000B67F */  sq         $22, 0x70($29)
    /* 2AB11C 003AB11C 6000B57F */  sq         $21, 0x60($29)
    /* 2AB120 003AB120 5000B47F */  sq         $20, 0x50($29)
    /* 2AB124 003AB124 2DA8A000 */  daddu      $21, $5, $0
    /* 2AB128 003AB128 4000B37F */  sq         $19, 0x40($29)
    /* 2AB12C 003AB12C 2DA0C000 */  daddu      $20, $6, $0
    /* 2AB130 003AB130 3000B27F */  sq         $18, 0x30($29)
    /* 2AB134 003AB134 2D98E000 */  daddu      $19, $7, $0
    /* 2AB138 003AB138 2000B17F */  sq         $17, 0x20($29)
    /* 2AB13C 003AB13C 1000B07F */  sq         $16, 0x10($29)
    /* 2AB140 003AB140 0800B6E7 */  swc1       $f22, 0x8($29)
    /* 2AB144 003AB144 0400B5E7 */  swc1       $f21, 0x4($29)
    /* 2AB148 003AB148 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 2AB14C 003AB14C 700001C5 */  lwc1       $f1, 0x70($8)
    /* 2AB150 003AB150 3800038D */  lw         $3, 0x38($8)
    /* 2AB154 003AB154 740000C5 */  lwc1       $f0, 0x74($8)
    /* 2AB158 003AB158 08001E8D */  lw         $30, 0x8($8)
    /* 2AB15C 003AB15C 0400968C */  lw         $22, 0x4($4)
    /* 2AB160 003AB160 0400128D */  lw         $18, 0x4($8)
    /* 2AB164 003AB164 3400118D */  lw         $17, 0x34($8)
    /* 2AB168 003AB168 0000908C */  lw         $16, 0x0($4)
    /* 2AB16C 003AB16C 82150146 */  mul.s      $f22, $f2, $f1
    /* 2AB170 003AB170 B000A37F */  sq         $3, 0xB0($29)
    /* 2AB174 003AB174 0A03D617 */  bne        $30, $22, .L003ABDA0
    /* 2AB178 003AB178 42150046 */   mul.s     $f21, $f2, $f0
    /* 2AB17C 003AB17C 9886100C */  jal        func_00421a60
    /* 2AB180 003AB180 2D200000 */   daddu     $4, $0, $0
    /* 2AB184 003AB184 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AB188 003AB188 00D0648C */  lw         $4, -0x3000($3)
    /* 2AB18C 003AB18C 00018430 */  andi       $4, $4, 0x100
    /* 2AB190 003AB190 0C008010 */  beqz       $4, .L003AB1C4
    /* 2AB194 003AB194 00000000 */   nop
    /* 2AB198 003AB198 00010424 */  addiu      $4, $0, 0x100
    /* 2AB19C 003AB19C 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2AB1A0 003AB1A0 0F000000 */  sync
    /* 2AB1A4 003AB1A4 0F040000 */  sync.p
  .L003AB1A8:
    /* 2AB1A8 003AB1A8 00000000 */  nop
    /* 2AB1AC 003AB1AC 00000000 */  nop
    /* 2AB1B0 003AB1B0 00000000 */  nop
    /* 2AB1B4 003AB1B4 00000000 */  nop
    /* 2AB1B8 003AB1B8 00000000 */  nop
    /* 2AB1BC 003AB1BC FAFF0041 */  bc0f       .L003AB1A8 /* handwritten instruction */
    /* 2AB1C0 003AB1C0 00000000 */   nop
  .L003AB1C4:
    /* 2AB1C4 003AB1C4 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AB1C8 003AB1C8 00D4648C */  lw         $4, -0x2C00($3)
    /* 2AB1CC 003AB1CC 00018430 */  andi       $4, $4, 0x100
    /* 2AB1D0 003AB1D0 15008010 */  beqz       $4, .L003AB228
    /* 2AB1D4 003AB1D4 00000000 */   nop
    /* 2AB1D8 003AB1D8 00020424 */  addiu      $4, $0, 0x200
    /* 2AB1DC 003AB1DC 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2AB1E0 003AB1E0 0F000000 */  sync
    /* 2AB1E4 003AB1E4 0F040000 */  sync.p
  .L003AB1E8:
    /* 2AB1E8 003AB1E8 00000000 */  nop
    /* 2AB1EC 003AB1EC 00000000 */  nop
    /* 2AB1F0 003AB1F0 00000000 */  nop
    /* 2AB1F4 003AB1F4 00000000 */  nop
    /* 2AB1F8 003AB1F8 00000000 */  nop
    /* 2AB1FC 003AB1FC FAFF0041 */  bc0f       .L003AB1E8 /* handwritten instruction */
    /* 2AB200 003AB200 00000000 */   nop
    /* 2AB204 003AB204 0110033C */  lui        $3, (0x10010000 >> 16)
  .L003AB208:
    /* 2AB208 003AB208 00D4648C */  lw         $4, -0x2C00($3)
    /* 2AB20C 003AB20C 00018430 */  andi       $4, $4, 0x100
    /* 2AB210 003AB210 00000000 */  nop
    /* 2AB214 003AB214 00000000 */  nop
    /* 2AB218 003AB218 00000000 */  nop
    /* 2AB21C 003AB21C FAFF8014 */  bnez       $4, .L003AB208
    /* 2AB220 003AB220 00000000 */   nop
    /* 2AB224 003AB224 00000000 */  nop
  .L003AB228:
    /* 2AB228 003AB228 0070043C */  lui        $4, (0x70003F40 >> 16)
    /* 2AB22C 003AB22C 0000A2C6 */  lwc1       $f2, 0x0($21)
    /* 2AB230 003AB230 003F8934 */  ori        $9, $4, (0x70003F00 & 0xFFFF)
    /* 2AB234 003AB234 0400A1C6 */  lwc1       $f1, 0x4($21)
    /* 2AB238 003AB238 103F8834 */  ori        $8, $4, (0x70003F10 & 0xFFFF)
    /* 2AB23C 003AB23C 0800A0C6 */  lwc1       $f0, 0x8($21)
    /* 2AB240 003AB240 203F8334 */  ori        $3, $4, (0x70003F20 & 0xFFFF)
    /* 2AB244 003AB244 303F8734 */  ori        $7, $4, (0x70003F30 & 0xFFFF)
    /* 2AB248 003AB248 403F8634 */  ori        $6, $4, (0x70003F40 & 0xFFFF)
    /* 2AB24C 003AB24C 0100043C */  lui        $4, (0x10000 >> 16)
    /* 2AB250 003AB250 000022E5 */  swc1       $f2, 0x0($9)
    /* 2AB254 003AB254 040021E5 */  swc1       $f1, 0x4($9)
    /* 2AB258 003AB258 080020E5 */  swc1       $f0, 0x8($9)
    /* 2AB25C 003AB25C 000082C6 */  lwc1       $f2, 0x0($20)
    /* 2AB260 003AB260 040081C6 */  lwc1       $f1, 0x4($20)
    /* 2AB264 003AB264 080080C6 */  lwc1       $f0, 0x8($20)
    /* 2AB268 003AB268 000002E5 */  swc1       $f2, 0x0($8)
    /* 2AB26C 003AB26C 040001E5 */  swc1       $f1, 0x4($8)
    /* 2AB270 003AB270 080000E5 */  swc1       $f0, 0x8($8)
  .L003AB274:
    /* 2AB274 003AB274 39000042 */  di /* handwritten instruction */
    /* 2AB278 003AB278 0F040000 */  sync.p
    /* 2AB27C 003AB27C 00600540 */  mfc0       $5, $12 /* handwritten instruction */
    /* 2AB280 003AB280 2428A400 */  and        $5, $5, $4
    /* 2AB284 003AB284 00000000 */  nop
    /* 2AB288 003AB288 FAFFA014 */  bnez       $5, .L003AB274
    /* 2AB28C 003AB28C 00000000 */   nop
    /* 2AB290 003AB290 C93F013C */  lui        $1, (0x3FC90FDB >> 16)
    /* 2AB294 003AB294 DB0F2434 */  ori        $4, $1, (0x3FC90FDB & 0xFFFF)
    /* 2AB298 003AB298 00008444 */  mtc1       $4, $f0
    /* 2AB29C 003AB29C 00000444 */  mfc1       $4, $f0
    /* 2AB2A0 003AB2A0 00A8C448 */  ctc2.ni    $4, $vi21
    /* 2AB2A4 003AB2A4 FF02004A */  vnop
    /* 2AB2A8 003AB2A8 FF02004A */  vnop
    /* 2AB2AC 003AB2AC A202004B */  vaddi.x    $vf10, $vf0, $I
    /* 2AB2B0 003AB2B0 4940013C */  lui        $1, (0x40490FDB >> 16)
    /* 2AB2B4 003AB2B4 DB0F2534 */  ori        $5, $1, (0x40490FDB & 0xFFFF)
    /* 2AB2B8 003AB2B8 00008544 */  mtc1       $5, $f0
    /* 2AB2BC 003AB2BC 00000444 */  mfc1       $4, $f0
    /* 2AB2C0 003AB2C0 00A8C448 */  ctc2.ni    $4, $vi21
    /* 2AB2C4 003AB2C4 FF02004A */  vnop
    /* 2AB2C8 003AB2C8 FF02004A */  vnop
    /* 2AB2CC 003AB2CC A202804A */  vaddi.y    $vf10, $vf0, $I
    /* 2AB2D0 003AB2D0 0940013C */  lui        $1, (0x40090FDB >> 16)
    /* 2AB2D4 003AB2D4 DB0F2434 */  ori        $4, $1, (0x40090FDB & 0xFFFF)
    /* 2AB2D8 003AB2D8 00008444 */  mtc1       $4, $f0
    /* 2AB2DC 003AB2DC 00000444 */  mfc1       $4, $f0
    /* 2AB2E0 003AB2E0 00A8C448 */  ctc2.ni    $4, $vi21
    /* 2AB2E4 003AB2E4 FF02004A */  vnop
    /* 2AB2E8 003AB2E8 FF02004A */  vnop
    /* 2AB2EC 003AB2EC A202404A */  vaddi.z    $vf10, $vf0, $I
    /* 2AB2F0 003AB2F0 00008544 */  mtc1       $5, $f0
    /* 2AB2F4 003AB2F4 07000046 */  neg.s      $f0, $f0
    /* 2AB2F8 003AB2F8 00000444 */  mfc1       $4, $f0
    /* 2AB2FC 003AB2FC 00A8C448 */  ctc2.ni    $4, $vi21
    /* 2AB300 003AB300 FF02004A */  vnop
    /* 2AB304 003AB304 FF02004A */  vnop
    /* 2AB308 003AB308 E202004B */  vaddi.x    $vf11, $vf0, $I
    /* 2AB30C 003AB30C 8440013C */  lui        $1, (0x408487ED >> 16)
    /* 2AB310 003AB310 ED872434 */  ori        $4, $1, (0x408487ED & 0xFFFF)
    /* 2AB314 003AB314 00008444 */  mtc1       $4, $f0
    /* 2AB318 003AB318 07000046 */  neg.s      $f0, $f0
    /* 2AB31C 003AB31C 00000444 */  mfc1       $4, $f0
    /* 2AB320 003AB320 00A8C448 */  ctc2.ni    $4, $vi21
    /* 2AB324 003AB324 FF02004A */  vnop
    /* 2AB328 003AB328 FF02004A */  vnop
    /* 2AB32C 003AB32C E202804A */  vaddi.y    $vf11, $vf0, $I
    /* 2AB330 003AB330 00000434 */  ori        $4, $0, 0x0
    /* 2AB334 003AB334 38240400 */  dsll       $4, $4, 16
    /* 2AB338 003AB338 38240400 */  dsll       $4, $4, 16
    /* 2AB33C 003AB33C 4FB98434 */  ori        $4, $4, 0xB94F
    /* 2AB340 003AB340 38240400 */  dsll       $4, $4, 16
    /* 2AB344 003AB344 1FB28434 */  ori        $4, $4, 0xB21F
    /* 2AB348 003AB348 00A8C448 */  ctc2.ni    $4, $vi21
    /* 2AB34C 003AB34C FF02004A */  vnop
    /* 2AB350 003AB350 FF02004A */  vnop
    /* 2AB354 003AB354 E202404A */  vaddi.z    $vf11, $vf0, $I
    /* 2AB358 003AB358 00000434 */  ori        $4, $0, 0x0
    /* 2AB35C 003AB35C 38240400 */  dsll       $4, $4, 16
    /* 2AB360 003AB360 38240400 */  dsll       $4, $4, 16
    /* 2AB364 003AB364 2ABE8434 */  ori        $4, $4, 0xBE2A
    /* 2AB368 003AB368 38240400 */  dsll       $4, $4, 16
    /* 2AB36C 003AB36C A4AA8434 */  ori        $4, $4, 0xAAA4
    /* 2AB370 003AB370 00A8C448 */  ctc2.ni    $4, $vi21
    /* 2AB374 003AB374 FF02004A */  vnop
    /* 2AB378 003AB378 FF02004A */  vnop
    /* 2AB37C 003AB37C 2203004B */  vaddi.x    $vf12, $vf0, $I
    /* 2AB380 003AB380 083C013C */  lui        $1, (0x3C08873E >> 16)
    /* 2AB384 003AB384 3E872434 */  ori        $4, $1, (0x3C08873E & 0xFFFF)
    /* 2AB388 003AB388 00A8C448 */  ctc2.ni    $4, $vi21
    /* 2AB38C 003AB38C FF02004A */  vnop
    /* 2AB390 003AB390 FF02004A */  vnop
    /* 2AB394 003AB394 2203804A */  vaddi.y    $vf12, $vf0, $I
    /* 2AB398 003AB398 2E36013C */  lui        $1, (0x362E9C14 >> 16)
    /* 2AB39C 003AB39C 149C2434 */  ori        $4, $1, (0x362E9C14 & 0xFFFF)
    /* 2AB3A0 003AB3A0 00A8C448 */  ctc2.ni    $4, $vi21
    /* 2AB3A4 003AB3A4 FF02004A */  vnop
    /* 2AB3A8 003AB3A8 FF02004A */  vnop
    /* 2AB3AC 003AB3AC 2203404A */  vaddi.z    $vf12, $vf0, $I
    /* 2AB3B0 003AB3B0 803F043C */  lui        $4, (0x3F800000 >> 16)
    /* 2AB3B4 003AB3B4 00A8C448 */  ctc2.ni    $4, $vi21
    /* 2AB3B8 003AB3B8 FF02004A */  vnop
    /* 2AB3BC 003AB3BC FF02004A */  vnop
    /* 2AB3C0 003AB3C0 6203004B */  vaddi.x    $vf13, $vf0, $I
    /* 2AB3C4 003AB3C4 38000042 */  ei /* handwritten instruction */
    /* 2AB3C8 003AB3C8 0070043C */  lui        $4, (0x70003F40 >> 16)
    /* 2AB3CC 003AB3CC 3C3F96E4 */  swc1       $f22, (0x70003F3C & 0xFFFF)($4)
    /* 2AB3D0 003AB3D0 0100053C */  lui        $5, (0x10000 >> 16)
    /* 2AB3D4 003AB3D4 383F96E4 */  swc1       $f22, (0x70003F38 & 0xFFFF)($4)
    /* 2AB3D8 003AB3D8 343F96E4 */  swc1       $f22, (0x70003F34 & 0xFFFF)($4)
    /* 2AB3DC 003AB3DC 303F96E4 */  swc1       $f22, (0x70003F30 & 0xFFFF)($4)
    /* 2AB3E0 003AB3E0 4C3F95E4 */  swc1       $f21, (0x70003F4C & 0xFFFF)($4)
    /* 2AB3E4 003AB3E4 483F95E4 */  swc1       $f21, (0x70003F48 & 0xFFFF)($4)
    /* 2AB3E8 003AB3E8 443F95E4 */  swc1       $f21, (0x70003F44 & 0xFFFF)($4)
    /* 2AB3EC 003AB3EC 403F95E4 */  swc1       $f21, (0x70003F40 & 0xFFFF)($4)
  .L003AB3F0:
    /* 2AB3F0 003AB3F0 39000042 */  di /* handwritten instruction */
    /* 2AB3F4 003AB3F4 0F040000 */  sync.p
    /* 2AB3F8 003AB3F8 00600440 */  mfc0       $4, $12 /* handwritten instruction */
    /* 2AB3FC 003AB3FC 24208500 */  and        $4, $4, $5
    /* 2AB400 003AB400 00000000 */  nop
    /* 2AB404 003AB404 FAFF8014 */  bnez       $4, .L003AB3F0
    /* 2AB408 003AB408 00000000 */   nop
    /* 2AB40C 003AB40C 000022D9 */  lqc2       $vf2, 0x0($9)
    /* 2AB410 003AB410 0000E4D8 */  lqc2       $vf4, 0x0($7)
    /* 2AB414 003AB414 000003D9 */  lqc2       $vf3, 0x0($8)
    /* 2AB418 003AB418 0000C5D8 */  lqc2       $vf5, 0x0($6)
    /* 2AB41C 003AB41C FF02004A */  vnop
    /* 2AB420 003AB420 2A12E44B */  vmul.xyzw  $vf8, $vf2, $vf4
    /* 2AB424 003AB424 2A1CE44B */  vmul.xyzw  $vf16, $vf3, $vf4
    /* 2AB428 003AB428 6A12E54B */  vmul.xyzw  $vf9, $vf2, $vf5
    /* 2AB42C 003AB42C 6A1CE54B */  vmul.xyzw  $vf17, $vf3, $vf5
    /* 2AB430 003AB430 38000042 */  ei /* handwritten instruction */
    /* 2AB434 003AB434 C000642A */  slti       $4, $19, 0xC0
    /* 2AB438 003AB438 FD008014 */  bnez       $4, .L003AB830
    /* 2AB43C 003AB43C 00000000 */   nop
    /* 2AB440 003AB440 00700E3C */  lui        $14, (0x70000F00 >> 16)
    /* 2AB444 003AB444 0110083C */  lui        $8, (0x10010000 >> 16)
    /* 2AB448 003AB448 01000B3C */  lui        $11, (0x10000 >> 16)
    /* 2AB44C 003AB44C 00011824 */  addiu      $24, $0, 0x100
    /* 2AB450 003AB450 00021724 */  addiu      $23, $0, 0x200
    /* 2AB454 003AB454 30001524 */  addiu      $21, $0, 0x30
    /* 2AB458 003AB458 00031424 */  addiu      $20, $0, 0x300
    /* 2AB45C 003AB45C C0000F24 */  addiu      $15, $0, 0xC0
    /* 2AB460 003AB460 0003CD35 */  ori        $13, $14, (0x70000300 & 0xFFFF)
    /* 2AB464 003AB464 000FCC35 */  ori        $12, $14, (0x70000F00 & 0xFFFF)
    /* 2AB468 003AB468 000F0924 */  addiu      $9, $0, 0xF00
  .L003AB46C:
    /* 2AB46C 003AB46C 00D0048D */  lw         $4, -0x3000($8)
    /* 2AB470 003AB470 00018430 */  andi       $4, $4, 0x100
    /* 2AB474 003AB474 0C008010 */  beqz       $4, .L003AB4A8
    /* 2AB478 003AB478 00000000 */   nop
    /* 2AB47C 003AB47C 20E018AD */  sw         $24, -0x1FE0($8)
    /* 2AB480 003AB480 0F000000 */  sync
    /* 2AB484 003AB484 0F040000 */  sync.p
  .L003AB488:
    /* 2AB488 003AB488 00000000 */  nop
    /* 2AB48C 003AB48C 00000000 */  nop
    /* 2AB490 003AB490 00000000 */  nop
    /* 2AB494 003AB494 00000000 */  nop
    /* 2AB498 003AB498 00000000 */  nop
    /* 2AB49C 003AB49C FAFF0041 */  bc0f       .L003AB488 /* handwritten instruction */
    /* 2AB4A0 003AB4A0 00000000 */   nop
    /* 2AB4A4 003AB4A4 00000000 */  nop
  .L003AB4A8:
    /* 2AB4A8 003AB4A8 00D4048D */  lw         $4, -0x2C00($8)
    /* 2AB4AC 003AB4AC 00018430 */  andi       $4, $4, 0x100
    /* 2AB4B0 003AB4B0 15008010 */  beqz       $4, .L003AB508
    /* 2AB4B4 003AB4B4 00000000 */   nop
    /* 2AB4B8 003AB4B8 20E017AD */  sw         $23, -0x1FE0($8)
    /* 2AB4BC 003AB4BC 0F000000 */  sync
    /* 2AB4C0 003AB4C0 0F040000 */  sync.p
    /* 2AB4C4 003AB4C4 00000000 */  nop
  .L003AB4C8:
    /* 2AB4C8 003AB4C8 00000000 */  nop
    /* 2AB4CC 003AB4CC 00000000 */  nop
    /* 2AB4D0 003AB4D0 00000000 */  nop
    /* 2AB4D4 003AB4D4 00000000 */  nop
    /* 2AB4D8 003AB4D8 00000000 */  nop
    /* 2AB4DC 003AB4DC FAFF0041 */  bc0f       .L003AB4C8 /* handwritten instruction */
    /* 2AB4E0 003AB4E0 00000000 */   nop
    /* 2AB4E4 003AB4E4 00000000 */  nop
  .L003AB4E8:
    /* 2AB4E8 003AB4E8 00D4048D */  lw         $4, -0x2C00($8)
    /* 2AB4EC 003AB4EC 00018430 */  andi       $4, $4, 0x100
    /* 2AB4F0 003AB4F0 00000000 */  nop
    /* 2AB4F4 003AB4F4 00000000 */  nop
    /* 2AB4F8 003AB4F8 00000000 */  nop
    /* 2AB4FC 003AB4FC FAFF8014 */  bnez       $4, .L003AB4E8
    /* 2AB500 003AB500 00000000 */   nop
    /* 2AB504 003AB504 00000000 */  nop
  .L003AB508:
    /* 2AB508 003AB508 10E017AD */  sw         $23, -0x1FF0($8)
    /* 2AB50C 003AB50C 80D400AD */  sw         $0, -0x2B80($8)
    /* 2AB510 003AB510 10D411AD */  sw         $17, -0x2BF0($8)
    /* 2AB514 003AB514 20D415AD */  sw         $21, -0x2BE0($8)
    /* 2AB518 003AB518 00D418AD */  sw         $24, -0x2C00($8)
    /* 2AB51C 003AB51C 0F000000 */  sync
    /* 2AB520 003AB520 0F040000 */  sync.p
    /* 2AB524 003AB524 00D4048D */  lw         $4, -0x2C00($8)
    /* 2AB528 003AB528 00018430 */  andi       $4, $4, 0x100
    /* 2AB52C 003AB52C 14008010 */  beqz       $4, .L003AB580
    /* 2AB530 003AB530 00000000 */   nop
    /* 2AB534 003AB534 20E017AD */  sw         $23, -0x1FE0($8)
    /* 2AB538 003AB538 0F000000 */  sync
    /* 2AB53C 003AB53C 0F040000 */  sync.p
  .L003AB540:
    /* 2AB540 003AB540 00000000 */  nop
    /* 2AB544 003AB544 00000000 */  nop
    /* 2AB548 003AB548 00000000 */  nop
    /* 2AB54C 003AB54C 00000000 */  nop
    /* 2AB550 003AB550 00000000 */  nop
    /* 2AB554 003AB554 FAFF0041 */  bc0f       .L003AB540 /* handwritten instruction */
    /* 2AB558 003AB558 00000000 */   nop
    /* 2AB55C 003AB55C 00000000 */  nop
  .L003AB560:
    /* 2AB560 003AB560 00D4048D */  lw         $4, -0x2C00($8)
    /* 2AB564 003AB564 00018430 */  andi       $4, $4, 0x100
    /* 2AB568 003AB568 00000000 */  nop
    /* 2AB56C 003AB56C 00000000 */  nop
    /* 2AB570 003AB570 00000000 */  nop
    /* 2AB574 003AB574 FAFF8014 */  bnez       $4, .L003AB560
    /* 2AB578 003AB578 00000000 */   nop
    /* 2AB57C 003AB57C 00000000 */  nop
  .L003AB580:
    /* 2AB580 003AB580 10E017AD */  sw         $23, -0x1FF0($8)
    /* 2AB584 003AB584 80D414AD */  sw         $20, -0x2B80($8)
    /* 2AB588 003AB588 10D412AD */  sw         $18, -0x2BF0($8)
    /* 2AB58C 003AB58C 20D40FAD */  sw         $15, -0x2BE0($8)
    /* 2AB590 003AB590 00D418AD */  sw         $24, -0x2C00($8)
    /* 2AB594 003AB594 0F000000 */  sync
    /* 2AB598 003AB598 0F040000 */  sync.p
    /* 2AB59C 003AB59C 00D4048D */  lw         $4, -0x2C00($8)
    /* 2AB5A0 003AB5A0 00018430 */  andi       $4, $4, 0x100
    /* 2AB5A4 003AB5A4 14008010 */  beqz       $4, .L003AB5F8
    /* 2AB5A8 003AB5A8 00000000 */   nop
    /* 2AB5AC 003AB5AC 20E017AD */  sw         $23, -0x1FE0($8)
    /* 2AB5B0 003AB5B0 0F000000 */  sync
    /* 2AB5B4 003AB5B4 0F040000 */  sync.p
  .L003AB5B8:
    /* 2AB5B8 003AB5B8 00000000 */  nop
    /* 2AB5BC 003AB5BC 00000000 */  nop
    /* 2AB5C0 003AB5C0 00000000 */  nop
    /* 2AB5C4 003AB5C4 00000000 */  nop
    /* 2AB5C8 003AB5C8 00000000 */  nop
    /* 2AB5CC 003AB5CC FAFF0041 */  bc0f       .L003AB5B8 /* handwritten instruction */
    /* 2AB5D0 003AB5D0 00000000 */   nop
    /* 2AB5D4 003AB5D4 00000000 */  nop
  .L003AB5D8:
    /* 2AB5D8 003AB5D8 00D4048D */  lw         $4, -0x2C00($8)
    /* 2AB5DC 003AB5DC 00018430 */  andi       $4, $4, 0x100
    /* 2AB5E0 003AB5E0 00000000 */  nop
    /* 2AB5E4 003AB5E4 00000000 */  nop
    /* 2AB5E8 003AB5E8 00000000 */  nop
    /* 2AB5EC 003AB5EC FAFF8014 */  bnez       $4, .L003AB5D8
    /* 2AB5F0 003AB5F0 00000000 */   nop
    /* 2AB5F4 003AB5F4 00000000 */  nop
  .L003AB5F8:
    /* 2AB5F8 003AB5F8 2D30C001 */  daddu      $6, $14, $0
    /* 2AB5FC 003AB5FC 2D28A001 */  daddu      $5, $13, $0
    /* 2AB600 003AB600 2D208001 */  daddu      $4, $12, $0
    /* 2AB604 003AB604 2D380000 */  daddu      $7, $0, $0
  .L003AB608:
    /* 2AB608 003AB608 0000C0C4 */  lwc1       $f0, (0x70000000 & 0xFFFF)($6)
    /* 2AB60C 003AB60C 000060E4 */  swc1       $f0, 0x0($3)
    /* 2AB610 003AB610 0400C0C4 */  lwc1       $f0, (0x70000004 & 0xFFFF)($6)
    /* 2AB614 003AB614 040060E4 */  swc1       $f0, 0x4($3)
    /* 2AB618 003AB618 0000C0C4 */  lwc1       $f0, (0x70000000 & 0xFFFF)($6)
    /* 2AB61C 003AB61C 080060E4 */  swc1       $f0, 0x8($3)
    /* 2AB620 003AB620 0400C0C4 */  lwc1       $f0, (0x70000004 & 0xFFFF)($6)
    /* 2AB624 003AB624 0C0060E4 */  swc1       $f0, 0xC($3)
  .L003AB628:
    /* 2AB628 003AB628 39000042 */  di /* handwritten instruction */
    /* 2AB62C 003AB62C 0F040000 */  sync.p
    /* 2AB630 003AB630 00600A40 */  mfc0       $10, $12 /* handwritten instruction */
    /* 2AB634 003AB634 24504B01 */  and        $10, $10, $11
    /* 2AB638 003AB638 00000000 */  nop
    /* 2AB63C 003AB63C FAFF4015 */  bnez       $10, .L003AB628
    /* 2AB640 003AB640 00000000 */   nop
    /* 2AB644 003AB644 000061D8 */  lqc2       $vf1, 0x0($3)
    /* 2AB648 003AB648 0000B4D8 */  lqc2       $vf20, 0x0($5)
    /* 2AB64C 003AB64C 1000BBD8 */  lqc2       $vf27, 0x10($5)
    /* 2AB650 003AB650 FD09874B */  vabs.xy    $vf7, $vf1
    /* 2AB654 003AB654 3C00EA4B */  vaddax.xyzw $ACC, $vf0, $vf10x
    /* 2AB658 003AB658 CF39804B */  vmsubw.xy  $vf7, $vf7, $vf0w
    /* 2AB65C 003AB65C 3D00CA4B */  vadday.xyz $ACC, $vf0, $vf10y
    /* 2AB660 003AB660 3E002A4A */  vaddaz.w   $ACC, $vf0, $vf10z
    /* 2AB664 003AB664 8F08604A */  vmsubw.zw  $vf2, $vf1, $vf0w
    /* 2AB668 003AB668 3C00CB4B */  vaddax.xyz $ACC, $vf0, $vf11x
    /* 2AB66C 003AB66C 3D002B4A */  vadday.w   $ACC, $vf0, $vf11y
    /* 2AB670 003AB670 CF08604A */  vmsubw.zw  $vf3, $vf1, $vf0w
    /* 2AB674 003AB674 AF08624A */  vmini.zw   $vf2, $vf1, $vf2
    /* 2AB678 003AB678 EB11634A */  vmax.zw    $vf7, $vf2, $vf3
    /* 2AB67C 003AB67C AA38E74B */  vmul.xyzw  $vf2, $vf7, $vf7
    /* 2AB680 003AB680 9A39EB4B */  vmulz.xyzw $vf6, $vf7, $vf11z
    /* 2AB684 003AB684 1839EC4B */  vmulx.xyzw $vf4, $vf7, $vf12x
    /* 2AB688 003AB688 5939EC4B */  vmuly.xyzw $vf5, $vf7, $vf12y
    /* 2AB68C 003AB68C EA10E24B */  vmul.xyzw  $vf3, $vf2, $vf2
    /* 2AB690 003AB690 AA31E24B */  vmul.xyzw  $vf6, $vf6, $vf2
    /* 2AB694 003AB694 BE22E24B */  vmula.xyzw $ACC, $vf4, $vf2
    /* 2AB698 003AB698 1A39EC4B */  vmulz.xyzw $vf4, $vf7, $vf12z
    /* 2AB69C 003AB69C AA18E34B */  vmul.xyzw  $vf2, $vf3, $vf3
    /* 2AB6A0 003AB6A0 BD32E34B */  vmadda.xyzw $ACC, $vf6, $vf3
    /* 2AB6A4 003AB6A4 BD2AE34B */  vmadda.xyzw $ACC, $vf5, $vf3
    /* 2AB6A8 003AB6A8 BC38ED4B */  vmaddax.xyzw $ACC, $vf7, $vf13x
    /* 2AB6AC 003AB6AC E921E24B */  vmadd.xyzw $vf7, $vf4, $vf2
    /* 2AB6B0 003AB6B0 9840C74B */  vmulx.xyz  $vf2, $vf8, $vf7x
    /* 2AB6B4 003AB6B4 DA80C74B */  vmulz.xyz  $vf3, $vf16, $vf7z
    /* 2AB6B8 003AB6B8 1A49C74B */  vmulz.xyz  $vf4, $vf9, $vf7z
    /* 2AB6BC 003AB6BC 5889C74B */  vmulx.xyz  $vf5, $vf17, $vf7x
    /* 2AB6C0 003AB6C0 AC14E34B */  vsub.xyzw  $vf18, $vf2, $vf3
    /* 2AB6C4 003AB6C4 E824E54B */  vadd.xyzw  $vf19, $vf4, $vf5
    /* 2AB6C8 003AB6C8 9940C74B */  vmuly.xyz  $vf2, $vf8, $vf7y
    /* 2AB6CC 003AB6CC DB80C74B */  vmulw.xyz  $vf3, $vf16, $vf7w
    /* 2AB6D0 003AB6D0 1B49C74B */  vmulw.xyz  $vf4, $vf9, $vf7w
    /* 2AB6D4 003AB6D4 5989C74B */  vmuly.xyz  $vf5, $vf17, $vf7y
    /* 2AB6D8 003AB6D8 6C16E34B */  vsub.xyzw  $vf25, $vf2, $vf3
    /* 2AB6DC 003AB6DC A826E54B */  vadd.xyzw  $vf26, $vf4, $vf5
    /* 2AB6E0 003AB6E0 6CA5F24B */  vsub.xyzw  $vf21, $vf20, $vf18
    /* 2AB6E4 003AB6E4 A8A5F24B */  vadd.xyzw  $vf22, $vf20, $vf18
    /* 2AB6E8 003AB6E8 E8A5F24B */  vadd.xyzw  $vf23, $vf20, $vf18
    /* 2AB6EC 003AB6EC 2CA6F24B */  vsub.xyzw  $vf24, $vf20, $vf18
    /* 2AB6F0 003AB6F0 6CADF34B */  vsub.xyzw  $vf21, $vf21, $vf19
    /* 2AB6F4 003AB6F4 ACB5F34B */  vsub.xyzw  $vf22, $vf22, $vf19
    /* 2AB6F8 003AB6F8 E8BDF34B */  vadd.xyzw  $vf23, $vf23, $vf19
    /* 2AB6FC 003AB6FC 28C6F34B */  vadd.xyzw  $vf24, $vf24, $vf19
    /* 2AB700 003AB700 2CDFF94B */  vsub.xyzw  $vf28, $vf27, $vf25
    /* 2AB704 003AB704 68DFF94B */  vadd.xyzw  $vf29, $vf27, $vf25
    /* 2AB708 003AB708 A8DFF94B */  vadd.xyzw  $vf30, $vf27, $vf25
    /* 2AB70C 003AB70C ECDFF94B */  vsub.xyzw  $vf31, $vf27, $vf25
    /* 2AB710 003AB710 2CE7FA4B */  vsub.xyzw  $vf28, $vf28, $vf26
    /* 2AB714 003AB714 6CEFFA4B */  vsub.xyzw  $vf29, $vf29, $vf26
    /* 2AB718 003AB718 A8F7FA4B */  vadd.xyzw  $vf30, $vf30, $vf26
    /* 2AB71C 003AB71C E8FFFA4B */  vadd.xyzw  $vf31, $vf31, $vf26
    /* 2AB720 003AB720 000095F8 */  sqc2       $vf21, 0x0($4)
    /* 2AB724 003AB724 100096F8 */  sqc2       $vf22, 0x10($4)
    /* 2AB728 003AB728 200097F8 */  sqc2       $vf23, 0x20($4)
    /* 2AB72C 003AB72C 300098F8 */  sqc2       $vf24, 0x30($4)
    /* 2AB730 003AB730 40009CF8 */  sqc2       $vf28, 0x40($4)
    /* 2AB734 003AB734 50009DF8 */  sqc2       $vf29, 0x50($4)
    /* 2AB738 003AB738 60009EF8 */  sqc2       $vf30, 0x60($4)
    /* 2AB73C 003AB73C 70009FF8 */  sqc2       $vf31, 0x70($4)
    /* 2AB740 003AB740 38000042 */  ei /* handwritten instruction */
    /* 2AB744 003AB744 0200E724 */  addiu      $7, $7, 0x2
    /* 2AB748 003AB748 C000EA28 */  slti       $10, $7, 0xC0
    /* 2AB74C 003AB74C 2000A524 */  addiu      $5, $5, 0x20
    /* 2AB750 003AB750 0800C624 */  addiu      $6, $6, %lo(D_70000008)
    /* 2AB754 003AB754 ACFF4015 */  bnez       $10, .L003AB608
    /* 2AB758 003AB758 80008424 */   addiu     $4, $4, 0x80
    /* 2AB75C 003AB75C 00D0048D */  lw         $4, -0x3000($8)
    /* 2AB760 003AB760 00018430 */  andi       $4, $4, 0x100
    /* 2AB764 003AB764 0C008010 */  beqz       $4, .L003AB798
    /* 2AB768 003AB768 00000000 */   nop
    /* 2AB76C 003AB76C 20E018AD */  sw         $24, -0x1FE0($8)
    /* 2AB770 003AB770 0F000000 */  sync
    /* 2AB774 003AB774 0F040000 */  sync.p
  .L003AB778:
    /* 2AB778 003AB778 00000000 */  nop
    /* 2AB77C 003AB77C 00000000 */  nop
    /* 2AB780 003AB780 00000000 */  nop
    /* 2AB784 003AB784 00000000 */  nop
    /* 2AB788 003AB788 00000000 */  nop
    /* 2AB78C 003AB78C FAFF0041 */  bc0f       .L003AB778 /* handwritten instruction */
    /* 2AB790 003AB790 00000000 */   nop
    /* 2AB794 003AB794 00000000 */  nop
  .L003AB798:
    /* 2AB798 003AB798 00D4048D */  lw         $4, -0x2C00($8)
    /* 2AB79C 003AB79C 00018430 */  andi       $4, $4, 0x100
    /* 2AB7A0 003AB7A0 15008010 */  beqz       $4, .L003AB7F8
    /* 2AB7A4 003AB7A4 00000000 */   nop
    /* 2AB7A8 003AB7A8 20E017AD */  sw         $23, -0x1FE0($8)
    /* 2AB7AC 003AB7AC 0F000000 */  sync
    /* 2AB7B0 003AB7B0 0F040000 */  sync.p
    /* 2AB7B4 003AB7B4 00000000 */  nop
  .L003AB7B8:
    /* 2AB7B8 003AB7B8 00000000 */  nop
    /* 2AB7BC 003AB7BC 00000000 */  nop
    /* 2AB7C0 003AB7C0 00000000 */  nop
    /* 2AB7C4 003AB7C4 00000000 */  nop
    /* 2AB7C8 003AB7C8 00000000 */  nop
    /* 2AB7CC 003AB7CC FAFF0041 */  bc0f       .L003AB7B8 /* handwritten instruction */
    /* 2AB7D0 003AB7D0 00000000 */   nop
    /* 2AB7D4 003AB7D4 00000000 */  nop
  .L003AB7D8:
    /* 2AB7D8 003AB7D8 00D4048D */  lw         $4, -0x2C00($8)
    /* 2AB7DC 003AB7DC 00018430 */  andi       $4, $4, 0x100
    /* 2AB7E0 003AB7E0 00000000 */  nop
    /* 2AB7E4 003AB7E4 00000000 */  nop
    /* 2AB7E8 003AB7E8 00000000 */  nop
    /* 2AB7EC 003AB7EC FAFF8014 */  bnez       $4, .L003AB7D8
    /* 2AB7F0 003AB7F0 00000000 */   nop
    /* 2AB7F4 003AB7F4 00000000 */  nop
  .L003AB7F8:
    /* 2AB7F8 003AB7F8 10E018AD */  sw         $24, -0x1FF0($8)
    /* 2AB7FC 003AB7FC 80D009AD */  sw         $9, -0x2F80($8)
    /* 2AB800 003AB800 10D010AD */  sw         $16, -0x2FF0($8)
    /* 2AB804 003AB804 20D014AD */  sw         $20, -0x2FE0($8)
    /* 2AB808 003AB808 00D018AD */  sw         $24, -0x3000($8)
    /* 2AB80C 003AB80C 0F000000 */  sync
    /* 2AB810 003AB810 0F040000 */  sync.p
    /* 2AB814 003AB814 40FF7326 */  addiu      $19, $19, -0xC0
    /* 2AB818 003AB818 000C5226 */  addiu      $18, $18, 0xC00
    /* 2AB81C 003AB81C C000612A */  slti       $1, $19, 0xC0
    /* 2AB820 003AB820 00301026 */  addiu      $16, $16, 0x3000
    /* 2AB824 003AB824 11FF2010 */  beqz       $1, .L003AB46C
    /* 2AB828 003AB828 00033126 */   addiu     $17, $17, 0x300
    /* 2AB82C 003AB82C 00000000 */  nop
  .L003AB830:
    /* 2AB830 003AB830 0400612A */  slti       $1, $19, 0x4
    /* 2AB834 003AB834 1B012014 */  bnez       $1, .L003ABCA4
    /* 2AB838 003AB838 00000000 */   nop
    /* 2AB83C 003AB83C 03006106 */  bgez       $19, .L003AB84C
    /* 2AB840 003AB840 83201300 */   sra       $4, $19, 2
    /* 2AB844 003AB844 03006426 */  addiu      $4, $19, 0x3
    /* 2AB848 003AB848 83200400 */  sra        $4, $4, 2
  .L003AB84C:
    /* 2AB84C 003AB84C 80300400 */  sll        $6, $4, 2
    /* 2AB850 003AB850 0110043C */  lui        $4, (0x10010000 >> 16)
    /* 2AB854 003AB854 00D0858C */  lw         $5, -0x3000($4)
    /* 2AB858 003AB858 0001A530 */  andi       $5, $5, 0x100
    /* 2AB85C 003AB85C 0C00A010 */  beqz       $5, .L003AB890
    /* 2AB860 003AB860 00000000 */   nop
    /* 2AB864 003AB864 00010524 */  addiu      $5, $0, 0x100
    /* 2AB868 003AB868 20E085AC */  sw         $5, -0x1FE0($4)
    /* 2AB86C 003AB86C 0F000000 */  sync
    /* 2AB870 003AB870 0F040000 */  sync.p
  .L003AB874:
    /* 2AB874 003AB874 00000000 */  nop
    /* 2AB878 003AB878 00000000 */  nop
    /* 2AB87C 003AB87C 00000000 */  nop
    /* 2AB880 003AB880 00000000 */  nop
    /* 2AB884 003AB884 00000000 */  nop
    /* 2AB888 003AB888 FAFF0041 */  bc0f       .L003AB874 /* handwritten instruction */
    /* 2AB88C 003AB88C 00000000 */   nop
  .L003AB890:
    /* 2AB890 003AB890 0110043C */  lui        $4, (0x10010000 >> 16)
    /* 2AB894 003AB894 00D4858C */  lw         $5, -0x2C00($4)
    /* 2AB898 003AB898 0001A530 */  andi       $5, $5, 0x100
    /* 2AB89C 003AB89C 1400A010 */  beqz       $5, .L003AB8F0
    /* 2AB8A0 003AB8A0 00000000 */   nop
    /* 2AB8A4 003AB8A4 00020524 */  addiu      $5, $0, 0x200
    /* 2AB8A8 003AB8A8 20E085AC */  sw         $5, -0x1FE0($4)
    /* 2AB8AC 003AB8AC 0F000000 */  sync
    /* 2AB8B0 003AB8B0 0F040000 */  sync.p
  .L003AB8B4:
    /* 2AB8B4 003AB8B4 00000000 */  nop
    /* 2AB8B8 003AB8B8 00000000 */  nop
    /* 2AB8BC 003AB8BC 00000000 */  nop
    /* 2AB8C0 003AB8C0 00000000 */  nop
    /* 2AB8C4 003AB8C4 00000000 */  nop
    /* 2AB8C8 003AB8C8 FAFF0041 */  bc0f       .L003AB8B4 /* handwritten instruction */
    /* 2AB8CC 003AB8CC 00000000 */   nop
    /* 2AB8D0 003AB8D0 0110043C */  lui        $4, (0x10010000 >> 16)
  .L003AB8D4:
    /* 2AB8D4 003AB8D4 00D4858C */  lw         $5, -0x2C00($4)
    /* 2AB8D8 003AB8D8 0001A530 */  andi       $5, $5, 0x100
    /* 2AB8DC 003AB8DC 00000000 */  nop
    /* 2AB8E0 003AB8E0 00000000 */  nop
    /* 2AB8E4 003AB8E4 00000000 */  nop
    /* 2AB8E8 003AB8E8 FAFFA014 */  bnez       $5, .L003AB8D4
    /* 2AB8EC 003AB8EC 00000000 */   nop
  .L003AB8F0:
    /* 2AB8F0 003AB8F0 00020524 */  addiu      $5, $0, 0x200
    /* 2AB8F4 003AB8F4 0110043C */  lui        $4, (0x10010000 >> 16)
    /* 2AB8F8 003AB8F8 83380600 */  sra        $7, $6, 2
    /* 2AB8FC 003AB8FC 10E085AC */  sw         $5, -0x1FF0($4)
    /* 2AB900 003AB900 80D480AC */  sw         $0, -0x2B80($4)
    /* 2AB904 003AB904 0300C104 */  bgez       $6, .L003AB914
    /* 2AB908 003AB908 10D491AC */   sw        $17, -0x2BF0($4)
    /* 2AB90C 003AB90C 0300C424 */  addiu      $4, $6, 0x3
    /* 2AB910 003AB910 83380400 */  sra        $7, $4, 2
  .L003AB914:
    /* 2AB914 003AB914 0110043C */  lui        $4, (0x10010000 >> 16)
    /* 2AB918 003AB918 00010524 */  addiu      $5, $0, 0x100
    /* 2AB91C 003AB91C 20D487AC */  sw         $7, -0x2BE0($4)
    /* 2AB920 003AB920 00D485AC */  sw         $5, -0x2C00($4)
    /* 2AB924 003AB924 0F000000 */  sync
    /* 2AB928 003AB928 0F040000 */  sync.p
    /* 2AB92C 003AB92C 00D4858C */  lw         $5, -0x2C00($4)
    /* 2AB930 003AB930 0001A530 */  andi       $5, $5, 0x100
    /* 2AB934 003AB934 1400A010 */  beqz       $5, .L003AB988
    /* 2AB938 003AB938 00000000 */   nop
    /* 2AB93C 003AB93C 00020524 */  addiu      $5, $0, 0x200
    /* 2AB940 003AB940 20E085AC */  sw         $5, -0x1FE0($4)
    /* 2AB944 003AB944 0F000000 */  sync
    /* 2AB948 003AB948 0F040000 */  sync.p
  .L003AB94C:
    /* 2AB94C 003AB94C 00000000 */  nop
    /* 2AB950 003AB950 00000000 */  nop
    /* 2AB954 003AB954 00000000 */  nop
    /* 2AB958 003AB958 00000000 */  nop
    /* 2AB95C 003AB95C 00000000 */  nop
    /* 2AB960 003AB960 FAFF0041 */  bc0f       .L003AB94C /* handwritten instruction */
    /* 2AB964 003AB964 00000000 */   nop
    /* 2AB968 003AB968 0110043C */  lui        $4, (0x10010000 >> 16)
  .L003AB96C:
    /* 2AB96C 003AB96C 00D4858C */  lw         $5, -0x2C00($4)
    /* 2AB970 003AB970 0001A530 */  andi       $5, $5, 0x100
    /* 2AB974 003AB974 00000000 */  nop
    /* 2AB978 003AB978 00000000 */  nop
    /* 2AB97C 003AB97C 00000000 */  nop
    /* 2AB980 003AB980 FAFFA014 */  bnez       $5, .L003AB96C
    /* 2AB984 003AB984 00000000 */   nop
  .L003AB988:
    /* 2AB988 003AB988 00410700 */  sll        $8, $7, 4
    /* 2AB98C 003AB98C 00020724 */  addiu      $7, $0, 0x200
    /* 2AB990 003AB990 0110043C */  lui        $4, (0x10010000 >> 16)
    /* 2AB994 003AB994 10E087AC */  sw         $7, -0x1FF0($4)
    /* 2AB998 003AB998 00010524 */  addiu      $5, $0, 0x100
    /* 2AB99C 003AB99C 80D488AC */  sw         $8, -0x2B80($4)
    /* 2AB9A0 003AB9A0 10D492AC */  sw         $18, -0x2BF0($4)
    /* 2AB9A4 003AB9A4 20D486AC */  sw         $6, -0x2BE0($4)
    /* 2AB9A8 003AB9A8 00D485AC */  sw         $5, -0x2C00($4)
    /* 2AB9AC 003AB9AC 0F000000 */  sync
    /* 2AB9B0 003AB9B0 0F040000 */  sync.p
    /* 2AB9B4 003AB9B4 00D4858C */  lw         $5, -0x2C00($4)
    /* 2AB9B8 003AB9B8 0001A530 */  andi       $5, $5, 0x100
    /* 2AB9BC 003AB9BC 1400A010 */  beqz       $5, .L003ABA10
    /* 2AB9C0 003AB9C0 00000000 */   nop
    /* 2AB9C4 003AB9C4 20E087AC */  sw         $7, -0x1FE0($4)
    /* 2AB9C8 003AB9C8 0F000000 */  sync
    /* 2AB9CC 003AB9CC 0F040000 */  sync.p
  .L003AB9D0:
    /* 2AB9D0 003AB9D0 00000000 */  nop
    /* 2AB9D4 003AB9D4 00000000 */  nop
    /* 2AB9D8 003AB9D8 00000000 */  nop
    /* 2AB9DC 003AB9DC 00000000 */  nop
    /* 2AB9E0 003AB9E0 00000000 */  nop
    /* 2AB9E4 003AB9E4 FAFF0041 */  bc0f       .L003AB9D0 /* handwritten instruction */
    /* 2AB9E8 003AB9E8 00000000 */   nop
    /* 2AB9EC 003AB9EC 0110043C */  lui        $4, (0x10010000 >> 16)
  .L003AB9F0:
    /* 2AB9F0 003AB9F0 00D4858C */  lw         $5, -0x2C00($4)
    /* 2AB9F4 003AB9F4 0001A530 */  andi       $5, $5, 0x100
    /* 2AB9F8 003AB9F8 00000000 */  nop
    /* 2AB9FC 003AB9FC 00000000 */  nop
    /* 2ABA00 003ABA00 00000000 */  nop
    /* 2ABA04 003ABA04 FAFFA014 */  bnez       $5, .L003AB9F0
    /* 2ABA08 003ABA08 00000000 */   nop
    /* 2ABA0C 003ABA0C 00000000 */  nop
  .L003ABA10:
    /* 2ABA10 003ABA10 00700A3C */  lui        $10, (0x70000004 >> 16)
    /* 2ABA14 003ABA14 0300C104 */  bgez       $6, .L003ABA24
    /* 2ABA18 003ABA18 83200600 */   sra       $4, $6, 2
    /* 2ABA1C 003ABA1C 0300C424 */  addiu      $4, $6, 0x3
    /* 2ABA20 003ABA20 83200400 */  sra        $4, $4, 2
  .L003ABA24:
    /* 2ABA24 003ABA24 2120C400 */  addu       $4, $6, $4
    /* 2ABA28 003ABA28 0070073C */  lui        $7, (0x70000070 >> 16)
    /* 2ABA2C 003ABA2C 00210400 */  sll        $4, $4, 4
    /* 2ABA30 003ABA30 2A080600 */  slt        $1, $0, $6
    /* 2ABA34 003ABA34 25280701 */  or         $5, $8, $7
    /* 2ABA38 003ABA38 25208700 */  or         $4, $4, $7
    /* 2ABA3C 003ABA3C 58002010 */  beqz       $1, .L003ABBA0
    /* 2ABA40 003ABA40 2D480000 */   daddu     $9, $0, $0
    /* 2ABA44 003ABA44 0100083C */  lui        $8, (0x10000 >> 16)
  .L003ABA48:
    /* 2ABA48 003ABA48 000040C5 */  lwc1       $f0, (0x70000000 & 0xFFFF)($10)
    /* 2ABA4C 003ABA4C 000060E4 */  swc1       $f0, 0x0($3)
    /* 2ABA50 003ABA50 040040C5 */  lwc1       $f0, (0x70000004 & 0xFFFF)($10)
    /* 2ABA54 003ABA54 040060E4 */  swc1       $f0, 0x4($3)
    /* 2ABA58 003ABA58 000040C5 */  lwc1       $f0, (0x70000000 & 0xFFFF)($10)
    /* 2ABA5C 003ABA5C 080060E4 */  swc1       $f0, 0x8($3)
    /* 2ABA60 003ABA60 040040C5 */  lwc1       $f0, (0x70000004 & 0xFFFF)($10)
    /* 2ABA64 003ABA64 0C0060E4 */  swc1       $f0, 0xC($3)
  .L003ABA68:
    /* 2ABA68 003ABA68 39000042 */  di /* handwritten instruction */
    /* 2ABA6C 003ABA6C 0F040000 */  sync.p
    /* 2ABA70 003ABA70 00600740 */  mfc0       $7, $12 /* handwritten instruction */
    /* 2ABA74 003ABA74 2438E800 */  and        $7, $7, $8
    /* 2ABA78 003ABA78 00000000 */  nop
    /* 2ABA7C 003ABA7C FAFFE014 */  bnez       $7, .L003ABA68
    /* 2ABA80 003ABA80 00000000 */   nop
    /* 2ABA84 003ABA84 000061D8 */  lqc2       $vf1, 0x0($3)
    /* 2ABA88 003ABA88 0000B4D8 */  lqc2       $vf20, (0x70000000 & 0xFFFF)($5)
    /* 2ABA8C 003ABA8C 1000BBD8 */  lqc2       $vf27, (0x70000010 & 0xFFFF)($5)
    /* 2ABA90 003ABA90 FD09874B */  vabs.xy    $vf7, $vf1
    /* 2ABA94 003ABA94 3C00EA4B */  vaddax.xyzw $ACC, $vf0, $vf10x
    /* 2ABA98 003ABA98 CF39804B */  vmsubw.xy  $vf7, $vf7, $vf0w
    /* 2ABA9C 003ABA9C 3D00CA4B */  vadday.xyz $ACC, $vf0, $vf10y
    /* 2ABAA0 003ABAA0 3E002A4A */  vaddaz.w   $ACC, $vf0, $vf10z
    /* 2ABAA4 003ABAA4 8F08604A */  vmsubw.zw  $vf2, $vf1, $vf0w
    /* 2ABAA8 003ABAA8 3C00CB4B */  vaddax.xyz $ACC, $vf0, $vf11x
    /* 2ABAAC 003ABAAC 3D002B4A */  vadday.w   $ACC, $vf0, $vf11y
    /* 2ABAB0 003ABAB0 CF08604A */  vmsubw.zw  $vf3, $vf1, $vf0w
    /* 2ABAB4 003ABAB4 AF08624A */  vmini.zw   $vf2, $vf1, $vf2
    /* 2ABAB8 003ABAB8 EB11634A */  vmax.zw    $vf7, $vf2, $vf3
    /* 2ABABC 003ABABC AA38E74B */  vmul.xyzw  $vf2, $vf7, $vf7
    /* 2ABAC0 003ABAC0 9A39EB4B */  vmulz.xyzw $vf6, $vf7, $vf11z
    /* 2ABAC4 003ABAC4 1839EC4B */  vmulx.xyzw $vf4, $vf7, $vf12x
    /* 2ABAC8 003ABAC8 5939EC4B */  vmuly.xyzw $vf5, $vf7, $vf12y
    /* 2ABACC 003ABACC EA10E24B */  vmul.xyzw  $vf3, $vf2, $vf2
    /* 2ABAD0 003ABAD0 AA31E24B */  vmul.xyzw  $vf6, $vf6, $vf2
    /* 2ABAD4 003ABAD4 BE22E24B */  vmula.xyzw $ACC, $vf4, $vf2
    /* 2ABAD8 003ABAD8 1A39EC4B */  vmulz.xyzw $vf4, $vf7, $vf12z
    /* 2ABADC 003ABADC AA18E34B */  vmul.xyzw  $vf2, $vf3, $vf3
    /* 2ABAE0 003ABAE0 BD32E34B */  vmadda.xyzw $ACC, $vf6, $vf3
    /* 2ABAE4 003ABAE4 BD2AE34B */  vmadda.xyzw $ACC, $vf5, $vf3
    /* 2ABAE8 003ABAE8 BC38ED4B */  vmaddax.xyzw $ACC, $vf7, $vf13x
    /* 2ABAEC 003ABAEC E921E24B */  vmadd.xyzw $vf7, $vf4, $vf2
    /* 2ABAF0 003ABAF0 9840C74B */  vmulx.xyz  $vf2, $vf8, $vf7x
    /* 2ABAF4 003ABAF4 DA80C74B */  vmulz.xyz  $vf3, $vf16, $vf7z
    /* 2ABAF8 003ABAF8 1A49C74B */  vmulz.xyz  $vf4, $vf9, $vf7z
    /* 2ABAFC 003ABAFC 5889C74B */  vmulx.xyz  $vf5, $vf17, $vf7x
    /* 2ABB00 003ABB00 AC14E34B */  vsub.xyzw  $vf18, $vf2, $vf3
    /* 2ABB04 003ABB04 E824E54B */  vadd.xyzw  $vf19, $vf4, $vf5
    /* 2ABB08 003ABB08 9940C74B */  vmuly.xyz  $vf2, $vf8, $vf7y
    /* 2ABB0C 003ABB0C DB80C74B */  vmulw.xyz  $vf3, $vf16, $vf7w
    /* 2ABB10 003ABB10 1B49C74B */  vmulw.xyz  $vf4, $vf9, $vf7w
    /* 2ABB14 003ABB14 5989C74B */  vmuly.xyz  $vf5, $vf17, $vf7y
    /* 2ABB18 003ABB18 6C16E34B */  vsub.xyzw  $vf25, $vf2, $vf3
    /* 2ABB1C 003ABB1C A826E54B */  vadd.xyzw  $vf26, $vf4, $vf5
    /* 2ABB20 003ABB20 6CA5F24B */  vsub.xyzw  $vf21, $vf20, $vf18
    /* 2ABB24 003ABB24 A8A5F24B */  vadd.xyzw  $vf22, $vf20, $vf18
    /* 2ABB28 003ABB28 E8A5F24B */  vadd.xyzw  $vf23, $vf20, $vf18
    /* 2ABB2C 003ABB2C 2CA6F24B */  vsub.xyzw  $vf24, $vf20, $vf18
    /* 2ABB30 003ABB30 6CADF34B */  vsub.xyzw  $vf21, $vf21, $vf19
    /* 2ABB34 003ABB34 ACB5F34B */  vsub.xyzw  $vf22, $vf22, $vf19
    /* 2ABB38 003ABB38 E8BDF34B */  vadd.xyzw  $vf23, $vf23, $vf19
    /* 2ABB3C 003ABB3C 28C6F34B */  vadd.xyzw  $vf24, $vf24, $vf19
    /* 2ABB40 003ABB40 2CDFF94B */  vsub.xyzw  $vf28, $vf27, $vf25
    /* 2ABB44 003ABB44 68DFF94B */  vadd.xyzw  $vf29, $vf27, $vf25
    /* 2ABB48 003ABB48 A8DFF94B */  vadd.xyzw  $vf30, $vf27, $vf25
    /* 2ABB4C 003ABB4C ECDFF94B */  vsub.xyzw  $vf31, $vf27, $vf25
    /* 2ABB50 003ABB50 2CE7FA4B */  vsub.xyzw  $vf28, $vf28, $vf26
    /* 2ABB54 003ABB54 6CEFFA4B */  vsub.xyzw  $vf29, $vf29, $vf26
    /* 2ABB58 003ABB58 A8F7FA4B */  vadd.xyzw  $vf30, $vf30, $vf26
    /* 2ABB5C 003ABB5C E8FFFA4B */  vadd.xyzw  $vf31, $vf31, $vf26
    /* 2ABB60 003ABB60 000095F8 */  sqc2       $vf21, (0x70000000 & 0xFFFF)($4)
    /* 2ABB64 003ABB64 100096F8 */  sqc2       $vf22, (0x70000010 & 0xFFFF)($4)
    /* 2ABB68 003ABB68 200097F8 */  sqc2       $vf23, (0x70000020 & 0xFFFF)($4)
    /* 2ABB6C 003ABB6C 300098F8 */  sqc2       $vf24, (0x70000030 & 0xFFFF)($4)
    /* 2ABB70 003ABB70 40009CF8 */  sqc2       $vf28, (0x70000040 & 0xFFFF)($4)
    /* 2ABB74 003ABB74 50009DF8 */  sqc2       $vf29, (0x70000050 & 0xFFFF)($4)
    /* 2ABB78 003ABB78 60009EF8 */  sqc2       $vf30, (0x70000060 & 0xFFFF)($4)
    /* 2ABB7C 003ABB7C 70009FF8 */  sqc2       $vf31, (0x70000070 & 0xFFFF)($4)
    /* 2ABB80 003ABB80 38000042 */  ei /* handwritten instruction */
    /* 2ABB84 003ABB84 02002925 */  addiu      $9, $9, 0x2
    /* 2ABB88 003ABB88 2A382601 */  slt        $7, $9, $6
    /* 2ABB8C 003ABB8C 2000A524 */  addiu      $5, $5, %lo(D_70000020)
    /* 2ABB90 003ABB90 08004A25 */  addiu      $10, $10, %lo(D_70000008)
    /* 2ABB94 003ABB94 ACFFE014 */  bnez       $7, .L003ABA48
    /* 2ABB98 003ABB98 80008424 */   addiu     $4, $4, %lo(D_70000080)
    /* 2ABB9C 003ABB9C 00000000 */  nop
  .L003ABBA0:
    /* 2ABBA0 003ABBA0 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2ABBA4 003ABBA4 00D0648C */  lw         $4, -0x3000($3)
    /* 2ABBA8 003ABBA8 00018430 */  andi       $4, $4, 0x100
    /* 2ABBAC 003ABBAC 0C008010 */  beqz       $4, .L003ABBE0
    /* 2ABBB0 003ABBB0 00000000 */   nop
    /* 2ABBB4 003ABBB4 00010424 */  addiu      $4, $0, 0x100
    /* 2ABBB8 003ABBB8 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2ABBBC 003ABBBC 0F000000 */  sync
    /* 2ABBC0 003ABBC0 0F040000 */  sync.p
  .L003ABBC4:
    /* 2ABBC4 003ABBC4 00000000 */  nop
    /* 2ABBC8 003ABBC8 00000000 */  nop
    /* 2ABBCC 003ABBCC 00000000 */  nop
    /* 2ABBD0 003ABBD0 00000000 */  nop
    /* 2ABBD4 003ABBD4 00000000 */  nop
    /* 2ABBD8 003ABBD8 FAFF0041 */  bc0f       .L003ABBC4 /* handwritten instruction */
    /* 2ABBDC 003ABBDC 00000000 */   nop
  .L003ABBE0:
    /* 2ABBE0 003ABBE0 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2ABBE4 003ABBE4 00D4648C */  lw         $4, -0x2C00($3)
    /* 2ABBE8 003ABBE8 00018430 */  andi       $4, $4, 0x100
    /* 2ABBEC 003ABBEC 14008010 */  beqz       $4, .L003ABC40
    /* 2ABBF0 003ABBF0 00000000 */   nop
    /* 2ABBF4 003ABBF4 00020424 */  addiu      $4, $0, 0x200
    /* 2ABBF8 003ABBF8 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2ABBFC 003ABBFC 0F000000 */  sync
    /* 2ABC00 003ABC00 0F040000 */  sync.p
  .L003ABC04:
    /* 2ABC04 003ABC04 00000000 */  nop
    /* 2ABC08 003ABC08 00000000 */  nop
    /* 2ABC0C 003ABC0C 00000000 */  nop
    /* 2ABC10 003ABC10 00000000 */  nop
    /* 2ABC14 003ABC14 00000000 */  nop
    /* 2ABC18 003ABC18 FAFF0041 */  bc0f       .L003ABC04 /* handwritten instruction */
    /* 2ABC1C 003ABC1C 00000000 */   nop
    /* 2ABC20 003ABC20 0110033C */  lui        $3, (0x10010000 >> 16)
  .L003ABC24:
    /* 2ABC24 003ABC24 00D4648C */  lw         $4, -0x2C00($3)
    /* 2ABC28 003ABC28 00018430 */  andi       $4, $4, 0x100
    /* 2ABC2C 003ABC2C 00000000 */  nop
    /* 2ABC30 003ABC30 00000000 */  nop
    /* 2ABC34 003ABC34 00000000 */  nop
    /* 2ABC38 003ABC38 FAFF8014 */  bnez       $4, .L003ABC24
    /* 2ABC3C 003ABC3C 00000000 */   nop
  .L003ABC40:
    /* 2ABC40 003ABC40 00010424 */  addiu      $4, $0, 0x100
    /* 2ABC44 003ABC44 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2ABC48 003ABC48 83380600 */  sra        $7, $6, 2
    /* 2ABC4C 003ABC4C 0300C104 */  bgez       $6, .L003ABC5C
    /* 2ABC50 003ABC50 10E064AC */   sw        $4, -0x1FF0($3)
    /* 2ABC54 003ABC54 0300C324 */  addiu      $3, $6, 0x3
    /* 2ABC58 003ABC58 83380300 */  sra        $7, $3, 2
  .L003ABC5C:
    /* 2ABC5C 003ABC5C 2120C700 */  addu       $4, $6, $7
    /* 2ABC60 003ABC60 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2ABC64 003ABC64 00210400 */  sll        $4, $4, 4
    /* 2ABC68 003ABC68 80280600 */  sll        $5, $6, 2
    /* 2ABC6C 003ABC6C 80D064AC */  sw         $4, -0x2F80($3)
    /* 2ABC70 003ABC70 10D070AC */  sw         $16, -0x2FF0($3)
    /* 2ABC74 003ABC74 00010424 */  addiu      $4, $0, 0x100
    /* 2ABC78 003ABC78 20D065AC */  sw         $5, -0x2FE0($3)
    /* 2ABC7C 003ABC7C 00D064AC */  sw         $4, -0x3000($3)
    /* 2ABC80 003ABC80 0F000000 */  sync
    /* 2ABC84 003ABC84 0F040000 */  sync.p
    /* 2ABC88 003ABC88 00190700 */  sll        $3, $7, 4
    /* 2ABC8C 003ABC8C 00210500 */  sll        $4, $5, 4
    /* 2ABC90 003ABC90 21882302 */  addu       $17, $17, $3
    /* 2ABC94 003ABC94 21800402 */  addu       $16, $16, $4
    /* 2ABC98 003ABC98 00190600 */  sll        $3, $6, 4
    /* 2ABC9C 003ABC9C 23986602 */  subu       $19, $19, $6
    /* 2ABCA0 003ABCA0 21904302 */  addu       $18, $18, $3
  .L003ABCA4:
    /* 2ABCA4 003ABCA4 2A081300 */  slt        $1, $0, $19
    /* 2ABCA8 003ABCA8 9B002010 */  beqz       $1, .L003ABF18
    /* 2ABCAC 003ABCAC 2D380000 */   daddu     $7, $0, $0
    /* 2ABCB0 003ABCB0 C800A627 */  addiu      $6, $29, 0xC8
    /* 2ABCB4 003ABCB4 80201600 */  sll        $4, $22, 2
    /* 2ABCB8 003ABCB8 C000A527 */  addiu      $5, $29, 0xC0
  .L003ABCBC:
    /* 2ABCBC 003ABCBC 000020C6 */  lwc1       $f0, 0x0($17)
    /* 2ABCC0 003ABCC0 C000A0E7 */  swc1       $f0, 0xC0($29)
    /* 2ABCC4 003ABCC4 0000C0E4 */  swc1       $f0, 0x0($6)
    /* 2ABCC8 003ABCC8 0000A1D8 */  lqc2       $vf1, 0x0($5)
    /* 2ABCCC 003ABCCC 000054DA */  lqc2       $vf20, 0x0($18)
    /* 2ABCD0 003ABCD0 FD09874B */  vabs.xy    $vf7, $vf1
    /* 2ABCD4 003ABCD4 3C00EA4B */  vaddax.xyzw $ACC, $vf0, $vf10x
    /* 2ABCD8 003ABCD8 CF39804B */  vmsubw.xy  $vf7, $vf7, $vf0w
    /* 2ABCDC 003ABCDC 3D00CA4B */  vadday.xyz $ACC, $vf0, $vf10y
    /* 2ABCE0 003ABCE0 3E002A4A */  vaddaz.w   $ACC, $vf0, $vf10z
    /* 2ABCE4 003ABCE4 8F08604A */  vmsubw.zw  $vf2, $vf1, $vf0w
    /* 2ABCE8 003ABCE8 3C00CB4B */  vaddax.xyz $ACC, $vf0, $vf11x
    /* 2ABCEC 003ABCEC 3D002B4A */  vadday.w   $ACC, $vf0, $vf11y
    /* 2ABCF0 003ABCF0 CF08604A */  vmsubw.zw  $vf3, $vf1, $vf0w
    /* 2ABCF4 003ABCF4 AF08624A */  vmini.zw   $vf2, $vf1, $vf2
    /* 2ABCF8 003ABCF8 EB11634A */  vmax.zw    $vf7, $vf2, $vf3
    /* 2ABCFC 003ABCFC AA38E74B */  vmul.xyzw  $vf2, $vf7, $vf7
    /* 2ABD00 003ABD00 9A39EB4B */  vmulz.xyzw $vf6, $vf7, $vf11z
    /* 2ABD04 003ABD04 1839EC4B */  vmulx.xyzw $vf4, $vf7, $vf12x
    /* 2ABD08 003ABD08 5939EC4B */  vmuly.xyzw $vf5, $vf7, $vf12y
    /* 2ABD0C 003ABD0C EA10E24B */  vmul.xyzw  $vf3, $vf2, $vf2
    /* 2ABD10 003ABD10 AA31E24B */  vmul.xyzw  $vf6, $vf6, $vf2
    /* 2ABD14 003ABD14 BE22E24B */  vmula.xyzw $ACC, $vf4, $vf2
    /* 2ABD18 003ABD18 1A39EC4B */  vmulz.xyzw $vf4, $vf7, $vf12z
    /* 2ABD1C 003ABD1C AA18E34B */  vmul.xyzw  $vf2, $vf3, $vf3
    /* 2ABD20 003ABD20 BD32E34B */  vmadda.xyzw $ACC, $vf6, $vf3
    /* 2ABD24 003ABD24 BD2AE34B */  vmadda.xyzw $ACC, $vf5, $vf3
    /* 2ABD28 003ABD28 BC38ED4B */  vmaddax.xyzw $ACC, $vf7, $vf13x
    /* 2ABD2C 003ABD2C E921E24B */  vmadd.xyzw $vf7, $vf4, $vf2
    /* 2ABD30 003ABD30 9840C74B */  vmulx.xyz  $vf2, $vf8, $vf7x
    /* 2ABD34 003ABD34 DA80C74B */  vmulz.xyz  $vf3, $vf16, $vf7z
    /* 2ABD38 003ABD38 1A49C74B */  vmulz.xyz  $vf4, $vf9, $vf7z
    /* 2ABD3C 003ABD3C 5889C74B */  vmulx.xyz  $vf5, $vf17, $vf7x
    /* 2ABD40 003ABD40 AC14E34B */  vsub.xyzw  $vf18, $vf2, $vf3
    /* 2ABD44 003ABD44 E824E54B */  vadd.xyzw  $vf19, $vf4, $vf5
    /* 2ABD48 003ABD48 6CA5F24B */  vsub.xyzw  $vf21, $vf20, $vf18
    /* 2ABD4C 003ABD4C A8A5F24B */  vadd.xyzw  $vf22, $vf20, $vf18
    /* 2ABD50 003ABD50 E8A5F24B */  vadd.xyzw  $vf23, $vf20, $vf18
    /* 2ABD54 003ABD54 2CA6F24B */  vsub.xyzw  $vf24, $vf20, $vf18
    /* 2ABD58 003ABD58 6CADF34B */  vsub.xyzw  $vf21, $vf21, $vf19
    /* 2ABD5C 003ABD5C ACB5F34B */  vsub.xyzw  $vf22, $vf22, $vf19
    /* 2ABD60 003ABD60 E8BDF34B */  vadd.xyzw  $vf23, $vf23, $vf19
    /* 2ABD64 003ABD64 28C6F34B */  vadd.xyzw  $vf24, $vf24, $vf19
    /* 2ABD68 003ABD68 000015FA */  sqc2       $vf21, 0x0($16)
    /* 2ABD6C 003ABD6C 100016FA */  sqc2       $vf22, 0x10($16)
    /* 2ABD70 003ABD70 200017FA */  sqc2       $vf23, 0x20($16)
    /* 2ABD74 003ABD74 300018FA */  sqc2       $vf24, 0x30($16)
    /* 2ABD78 003ABD78 38000042 */  ei /* handwritten instruction */
    /* 2ABD7C 003ABD7C 0100E724 */  addiu      $7, $7, 0x1
    /* 2ABD80 003ABD80 B000A37B */  lq         $3, 0xB0($29)
    /* 2ABD84 003ABD84 21905E02 */  addu       $18, $18, $30
    /* 2ABD88 003ABD88 21882302 */  addu       $17, $17, $3
    /* 2ABD8C 003ABD8C 2A18F300 */  slt        $3, $7, $19
    /* 2ABD90 003ABD90 CAFF6014 */  bnez       $3, .L003ABCBC
    /* 2ABD94 003ABD94 21800402 */   addu      $16, $16, $4
    /* 2ABD98 003ABD98 5F000010 */  b          .L003ABF18
    /* 2ABD9C 003ABD9C 00000000 */   nop
  .L003ABDA0:
    /* 2ABDA0 003ABDA0 2A081300 */  slt        $1, $0, $19
    /* 2ABDA4 003ABDA4 5C002010 */  beqz       $1, .L003ABF18
    /* 2ABDA8 003ABDA8 2DB80000 */   daddu     $23, $0, $0
  .L003ABDAC:
    /* 2ABDAC 003ABDAC EC2D110C */  jal        func_0044b7b0
    /* 2ABDB0 003ABDB0 00002CC6 */   lwc1      $f12, 0x0($17)
    /* 2ABDB4 003ABDB4 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 2ABDB8 003ABDB8 842D110C */  jal        func_0044b610
    /* 2ABDBC 003ABDBC 06050046 */   mov.s     $f20, $f0
    /* 2ABDC0 003ABDC0 000089C6 */  lwc1       $f9, 0x0($20)
    /* 2ABDC4 003ABDC4 21301602 */  addu       $6, $16, $22
    /* 2ABDC8 003ABDC8 0000A2C6 */  lwc1       $f2, 0x0($21)
    /* 2ABDCC 003ABDCC 2128D600 */  addu       $5, $6, $22
    /* 2ABDD0 003ABDD0 C7A00046 */  neg.s      $f3, $f20
    /* 2ABDD4 003ABDD4 B000A37B */  lq         $3, 0xB0($29)
    /* 2ABDD8 003ABDD8 040088C6 */  lwc1       $f8, 0x4($20)
    /* 2ABDDC 003ABDDC 2120B600 */  addu       $4, $5, $22
    /* 2ABDE0 003ABDE0 0400A7C6 */  lwc1       $f7, 0x4($21)
    /* 2ABDE4 003ABDE4 0100F726 */  addiu      $23, $23, 0x1
    /* 2ABDE8 003ABDE8 080085C6 */  lwc1       $f5, 0x8($20)
    /* 2ABDEC 003ABDEC 1A180946 */  mula.s     $f3, $f9
    /* 2ABDF0 003ABDF0 5C000246 */  madd.s     $f1, $f0, $f2
    /* 2ABDF4 003ABDF4 82091646 */  mul.s      $f6, $f1, $f22
    /* 2ABDF8 003ABDF8 21882302 */  addu       $17, $17, $3
    /* 2ABDFC 003ABDFC 2A18F302 */  slt        $3, $23, $19
    /* 2ABE00 003ABE00 1A180846 */  mula.s     $f3, $f8
    /* 2ABE04 003ABE04 5C000746 */  madd.s     $f1, $f0, $f7
    /* 2ABE08 003ABE08 0800A4C6 */  lwc1       $f4, 0x8($21)
    /* 2ABE0C 003ABE0C 1A180546 */  mula.s     $f3, $f5
    /* 2ABE10 003ABE10 820A1646 */  mul.s      $f10, $f1, $f22
    /* 2ABE14 003ABE14 DC000446 */  madd.s     $f3, $f0, $f4
    /* 2ABE18 003ABE18 1A000946 */  mula.s     $f0, $f9
    /* 2ABE1C 003ABE1C 9CA00246 */  madd.s     $f2, $f20, $f2
    /* 2ABE20 003ABE20 1A000846 */  mula.s     $f0, $f8
    /* 2ABE24 003ABE24 5CA00746 */  madd.s     $f1, $f20, $f7
    /* 2ABE28 003ABE28 1A000546 */  mula.s     $f0, $f5
    /* 2ABE2C 003ABE2C C2091546 */  mul.s      $f7, $f1, $f21
    /* 2ABE30 003ABE30 1CA00446 */  madd.s     $f0, $f20, $f4
    /* 2ABE34 003ABE34 42111546 */  mul.s      $f5, $f2, $f21
    /* 2ABE38 003ABE38 02021546 */  mul.s      $f8, $f0, $f21
    /* 2ABE3C 003ABE3C 87300046 */  neg.s      $f2, $f6
    /* 2ABE40 003ABE40 01100546 */  sub.s      $f0, $f2, $f5
    /* 2ABE44 003ABE44 000041C6 */  lwc1       $f1, 0x0($18)
    /* 2ABE48 003ABE48 421A1646 */  mul.s      $f9, $f3, $f22
    /* 2ABE4C 003ABE4C 00080046 */  add.s      $f0, $f1, $f0
    /* 2ABE50 003ABE50 000000E6 */  swc1       $f0, 0x0($16)
    /* 2ABE54 003ABE54 47500046 */  neg.s      $f1, $f10
    /* 2ABE58 003ABE58 01080746 */  sub.s      $f0, $f1, $f7
    /* 2ABE5C 003ABE5C 040043C6 */  lwc1       $f3, 0x4($18)
    /* 2ABE60 003ABE60 80100546 */  add.s      $f2, $f2, $f5
    /* 2ABE64 003ABE64 40080746 */  add.s      $f1, $f1, $f7
    /* 2ABE68 003ABE68 00180046 */  add.s      $f0, $f3, $f0
    /* 2ABE6C 003ABE6C 040000E6 */  swc1       $f0, 0x4($16)
    /* 2ABE70 003ABE70 07480046 */  neg.s      $f0, $f9
    /* 2ABE74 003ABE74 C1000846 */  sub.s      $f3, $f0, $f8
    /* 2ABE78 003ABE78 080044C6 */  lwc1       $f4, 0x8($18)
    /* 2ABE7C 003ABE7C 00000846 */  add.s      $f0, $f0, $f8
    /* 2ABE80 003ABE80 C0200346 */  add.s      $f3, $f4, $f3
    /* 2ABE84 003ABE84 080003E6 */  swc1       $f3, 0x8($16)
    /* 2ABE88 003ABE88 C1300546 */  sub.s      $f3, $f6, $f5
    /* 2ABE8C 003ABE8C 21809600 */  addu       $16, $4, $22
    /* 2ABE90 003ABE90 000044C6 */  lwc1       $f4, 0x0($18)
    /* 2ABE94 003ABE94 40310546 */  add.s      $f5, $f6, $f5
    /* 2ABE98 003ABE98 C0200346 */  add.s      $f3, $f4, $f3
    /* 2ABE9C 003ABE9C 0000C3E4 */  swc1       $f3, 0x0($6)
    /* 2ABEA0 003ABEA0 040046C6 */  lwc1       $f6, 0x4($18)
    /* 2ABEA4 003ABEA4 C1500746 */  sub.s      $f3, $f10, $f7
    /* 2ABEA8 003ABEA8 00510746 */  add.s      $f4, $f10, $f7
    /* 2ABEAC 003ABEAC C0300346 */  add.s      $f3, $f6, $f3
    /* 2ABEB0 003ABEB0 0400C3E4 */  swc1       $f3, 0x4($6)
    /* 2ABEB4 003ABEB4 080047C6 */  lwc1       $f7, 0x8($18)
    /* 2ABEB8 003ABEB8 81490846 */  sub.s      $f6, $f9, $f8
    /* 2ABEBC 003ABEBC C0480846 */  add.s      $f3, $f9, $f8
    /* 2ABEC0 003ABEC0 80390646 */  add.s      $f6, $f7, $f6
    /* 2ABEC4 003ABEC4 0800C6E4 */  swc1       $f6, 0x8($6)
    /* 2ABEC8 003ABEC8 000046C6 */  lwc1       $f6, 0x0($18)
    /* 2ABECC 003ABECC 40310546 */  add.s      $f5, $f6, $f5
    /* 2ABED0 003ABED0 0000A5E4 */  swc1       $f5, 0x0($5)
    /* 2ABED4 003ABED4 040045C6 */  lwc1       $f5, 0x4($18)
    /* 2ABED8 003ABED8 00290446 */  add.s      $f4, $f5, $f4
    /* 2ABEDC 003ABEDC 0400A4E4 */  swc1       $f4, 0x4($5)
    /* 2ABEE0 003ABEE0 080044C6 */  lwc1       $f4, 0x8($18)
    /* 2ABEE4 003ABEE4 C0200346 */  add.s      $f3, $f4, $f3
    /* 2ABEE8 003ABEE8 0800A3E4 */  swc1       $f3, 0x8($5)
    /* 2ABEEC 003ABEEC 000043C6 */  lwc1       $f3, 0x0($18)
    /* 2ABEF0 003ABEF0 80180246 */  add.s      $f2, $f3, $f2
    /* 2ABEF4 003ABEF4 000082E4 */  swc1       $f2, 0x0($4)
    /* 2ABEF8 003ABEF8 040042C6 */  lwc1       $f2, 0x4($18)
    /* 2ABEFC 003ABEFC 40100146 */  add.s      $f1, $f2, $f1
    /* 2ABF00 003ABF00 040081E4 */  swc1       $f1, 0x4($4)
    /* 2ABF04 003ABF04 080041C6 */  lwc1       $f1, 0x8($18)
    /* 2ABF08 003ABF08 00080046 */  add.s      $f0, $f1, $f0
    /* 2ABF0C 003ABF0C 21905E02 */  addu       $18, $18, $30
    /* 2ABF10 003ABF10 A6FF6014 */  bnez       $3, .L003ABDAC
    /* 2ABF14 003ABF14 080080E4 */   swc1      $f0, 0x8($4)
  .L003ABF18:
    /* 2ABF18 003ABF18 A000BFDF */  ld         $31, 0xA0($29)
    /* 2ABF1C 003ABF1C 9000BE7B */  lq         $30, 0x90($29)
    /* 2ABF20 003ABF20 0800B6C7 */  lwc1       $f22, 0x8($29)
    /* 2ABF24 003ABF24 8000B77B */  lq         $23, 0x80($29)
    /* 2ABF28 003ABF28 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* 2ABF2C 003ABF2C 7000B67B */  lq         $22, 0x70($29)
    /* 2ABF30 003ABF30 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 2ABF34 003ABF34 6000B57B */  lq         $21, 0x60($29)
    /* 2ABF38 003ABF38 5000B47B */  lq         $20, 0x50($29)
    /* 2ABF3C 003ABF3C 4000B37B */  lq         $19, 0x40($29)
    /* 2ABF40 003ABF40 3000B27B */  lq         $18, 0x30($29)
    /* 2ABF44 003ABF44 2000B17B */  lq         $17, 0x20($29)
    /* 2ABF48 003ABF48 1000B07B */  lq         $16, 0x10($29)
    /* 2ABF4C 003ABF4C 0800E003 */  jr         $31
    /* 2ABF50 003ABF50 D000BD27 */   addiu     $29, $29, 0xD0
    /* 2ABF54 003ABF54 00000000 */  nop
    /* 2ABF58 003ABF58 00000000 */  nop
    /* 2ABF5C 003ABF5C 00000000 */  nop
.size func_003ab100, 0xe60
