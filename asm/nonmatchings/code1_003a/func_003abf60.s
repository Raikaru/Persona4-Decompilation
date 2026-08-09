.section .text
.set noat
.set noreorder
glabel func_003abf60
    /* 2ABF60 003ABF60 20FFBD27 */  addiu      $29, $29, -0xE0
    /* 2ABF64 003ABF64 9000BFFF */  sd         $31, 0x90($29)
    /* 2ABF68 003ABF68 8000BE7F */  sq         $30, 0x80($29)
    /* 2ABF6C 003ABF6C 7000B77F */  sq         $23, 0x70($29)
    /* 2ABF70 003ABF70 6000B67F */  sq         $22, 0x60($29)
    /* 2ABF74 003ABF74 5000B57F */  sq         $21, 0x50($29)
    /* 2ABF78 003ABF78 4000B47F */  sq         $20, 0x40($29)
    /* 2ABF7C 003ABF7C 2DA8A000 */  daddu      $21, $5, $0
    /* 2ABF80 003ABF80 3000B37F */  sq         $19, 0x30($29)
    /* 2ABF84 003ABF84 2DA0C000 */  daddu      $20, $6, $0
    /* 2ABF88 003ABF88 2000B27F */  sq         $18, 0x20($29)
    /* 2ABF8C 003ABF8C 1000B17F */  sq         $17, 0x10($29)
    /* 2ABF90 003ABF90 0000B07F */  sq         $16, 0x0($29)
    /* 2ABF94 003ABF94 0800168D */  lw         $22, 0x8($8)
    /* 2ABF98 003ABF98 04009E8C */  lw         $30, 0x4($4)
    /* 2ABF9C 003ABF9C 0400128D */  lw         $18, 0x4($8)
    /* 2ABFA0 003ABFA0 1C00118D */  lw         $17, 0x1C($8)
    /* 2ABFA4 003ABFA4 2000178D */  lw         $23, 0x20($8)
    /* 2ABFA8 003ABFA8 0000908C */  lw         $16, 0x0($4)
    /* 2ABFAC 003ABFAC 8402DE16 */  bne        $22, $30, .L003AC9C0
    /* 2ABFB0 003ABFB0 2D98E000 */   daddu     $19, $7, $0
    /* 2ABFB4 003ABFB4 9886100C */  jal        func_00421a60
    /* 2ABFB8 003ABFB8 2D200000 */   daddu     $4, $0, $0
    /* 2ABFBC 003ABFBC 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2ABFC0 003ABFC0 00D0648C */  lw         $4, -0x3000($3)
    /* 2ABFC4 003ABFC4 00018430 */  andi       $4, $4, 0x100
    /* 2ABFC8 003ABFC8 0C008010 */  beqz       $4, .L003ABFFC
    /* 2ABFCC 003ABFCC 00000000 */   nop
    /* 2ABFD0 003ABFD0 00010424 */  addiu      $4, $0, 0x100
    /* 2ABFD4 003ABFD4 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2ABFD8 003ABFD8 0F000000 */  sync
    /* 2ABFDC 003ABFDC 0F040000 */  sync.p
  .L003ABFE0:
    /* 2ABFE0 003ABFE0 00000000 */  nop
    /* 2ABFE4 003ABFE4 00000000 */  nop
    /* 2ABFE8 003ABFE8 00000000 */  nop
    /* 2ABFEC 003ABFEC 00000000 */  nop
    /* 2ABFF0 003ABFF0 00000000 */  nop
    /* 2ABFF4 003ABFF4 FAFF0041 */  bc0f       .L003ABFE0 /* handwritten instruction */
    /* 2ABFF8 003ABFF8 00000000 */   nop
  .L003ABFFC:
    /* 2ABFFC 003ABFFC 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AC000 003AC000 00D4648C */  lw         $4, -0x2C00($3)
    /* 2AC004 003AC004 00018430 */  andi       $4, $4, 0x100
    /* 2AC008 003AC008 15008010 */  beqz       $4, .L003AC060
    /* 2AC00C 003AC00C 00000000 */   nop
    /* 2AC010 003AC010 00020424 */  addiu      $4, $0, 0x200
    /* 2AC014 003AC014 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2AC018 003AC018 0F000000 */  sync
    /* 2AC01C 003AC01C 0F040000 */  sync.p
  .L003AC020:
    /* 2AC020 003AC020 00000000 */  nop
    /* 2AC024 003AC024 00000000 */  nop
    /* 2AC028 003AC028 00000000 */  nop
    /* 2AC02C 003AC02C 00000000 */  nop
    /* 2AC030 003AC030 00000000 */  nop
    /* 2AC034 003AC034 FAFF0041 */  bc0f       .L003AC020 /* handwritten instruction */
    /* 2AC038 003AC038 00000000 */   nop
    /* 2AC03C 003AC03C 0110033C */  lui        $3, (0x10010000 >> 16)
  .L003AC040:
    /* 2AC040 003AC040 00D4648C */  lw         $4, -0x2C00($3)
    /* 2AC044 003AC044 00018430 */  andi       $4, $4, 0x100
    /* 2AC048 003AC048 00000000 */  nop
    /* 2AC04C 003AC04C 00000000 */  nop
    /* 2AC050 003AC050 00000000 */  nop
    /* 2AC054 003AC054 FAFF8014 */  bnez       $4, .L003AC040
    /* 2AC058 003AC058 00000000 */   nop
    /* 2AC05C 003AC05C 00000000 */  nop
  .L003AC060:
    /* 2AC060 003AC060 0070033C */  lui        $3, (0x70003F60 >> 16)
    /* 2AC064 003AC064 0000A2C6 */  lwc1       $f2, 0x0($21)
    /* 2AC068 003AC068 503F6534 */  ori        $5, $3, (0x70003F50 & 0xFFFF)
    /* 2AC06C 003AC06C 0400A1C6 */  lwc1       $f1, 0x4($21)
    /* 2AC070 003AC070 603F6434 */  ori        $4, $3, (0x70003F60 & 0xFFFF)
    /* 2AC074 003AC074 0800A0C6 */  lwc1       $f0, 0x8($21)
    /* 2AC078 003AC078 0100033C */  lui        $3, (0x10000 >> 16)
    /* 2AC07C 003AC07C 0000A2E4 */  swc1       $f2, 0x0($5)
    /* 2AC080 003AC080 0400A1E4 */  swc1       $f1, 0x4($5)
    /* 2AC084 003AC084 0800A0E4 */  swc1       $f0, 0x8($5)
    /* 2AC088 003AC088 000082C6 */  lwc1       $f2, 0x0($20)
    /* 2AC08C 003AC08C 040081C6 */  lwc1       $f1, 0x4($20)
    /* 2AC090 003AC090 080080C6 */  lwc1       $f0, 0x8($20)
    /* 2AC094 003AC094 000082E4 */  swc1       $f2, 0x0($4)
    /* 2AC098 003AC098 040081E4 */  swc1       $f1, 0x4($4)
    /* 2AC09C 003AC09C 080080E4 */  swc1       $f0, 0x8($4)
  .L003AC0A0:
    /* 2AC0A0 003AC0A0 39000042 */  di /* handwritten instruction */
    /* 2AC0A4 003AC0A4 0F040000 */  sync.p
    /* 2AC0A8 003AC0A8 00600640 */  mfc0       $6, $12 /* handwritten instruction */
    /* 2AC0AC 003AC0AC 2430C300 */  and        $6, $6, $3
    /* 2AC0B0 003AC0B0 00000000 */  nop
    /* 2AC0B4 003AC0B4 FAFFC014 */  bnez       $6, .L003AC0A0
    /* 2AC0B8 003AC0B8 00000000 */   nop
    /* 2AC0BC 003AC0BC 003F033C */  lui        $3, (0x3F000000 >> 16)
    /* 2AC0C0 003AC0C0 00008344 */  mtc1       $3, $f0
    /* 2AC0C4 003AC0C4 00000344 */  mfc1       $3, $f0
    /* 2AC0C8 003AC0C8 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2AC0CC 003AC0CC FF02004A */  vnop
    /* 2AC0D0 003AC0D0 FF02004A */  vnop
    /* 2AC0D4 003AC0D4 0000A1D8 */  lqc2       $vf1, 0x0($5)
    /* 2AC0D8 003AC0D8 000082D8 */  lqc2       $vf2, 0x0($4)
    /* 2AC0DC 003AC0DC 5E08E04B */  vmuli.xyzw $vf1, $vf1, $I
    /* 2AC0E0 003AC0E0 9E10E04B */  vmuli.xyzw $vf2, $vf2, $I
    /* 2AC0E4 003AC0E4 38000042 */  ei /* handwritten instruction */
    /* 2AC0E8 003AC0E8 B800632A */  slti       $3, $19, 0xB8
    /* 2AC0EC 003AC0EC F6006014 */  bnez       $3, .L003AC4C8
    /* 2AC0F0 003AC0F0 00000000 */   nop
    /* 2AC0F4 003AC0F4 00700E3C */  lui        $14, (0x70001140 >> 16)
    /* 2AC0F8 003AC0F8 0110073C */  lui        $7, (0x10010000 >> 16)
    /* 2AC0FC 003AC0FC 01000B3C */  lui        $11, (0x10000 >> 16)
    /* 2AC100 003AC100 00011924 */  addiu      $25, $0, 0x100
    /* 2AC104 003AC104 00021824 */  addiu      $24, $0, 0x200
    /* 2AC108 003AC108 5C001524 */  addiu      $21, $0, 0x5C
    /* 2AC10C 003AC10C C0051424 */  addiu      $20, $0, 0x5C0
    /* 2AC110 003AC110 B8000F24 */  addiu      $15, $0, 0xB8
    /* 2AC114 003AC114 C005CD35 */  ori        $13, $14, (0x700005C0 & 0xFFFF)
    /* 2AC118 003AC118 4011CC35 */  ori        $12, $14, (0x70001140 & 0xFFFF)
    /* 2AC11C 003AC11C 40110924 */  addiu      $9, $0, 0x1140
    /* 2AC120 003AC120 E0020824 */  addiu      $8, $0, 0x2E0
  .L003AC124:
    /* 2AC124 003AC124 00D0E38C */  lw         $3, -0x3000($7)
    /* 2AC128 003AC128 00016330 */  andi       $3, $3, 0x100
    /* 2AC12C 003AC12C 0C006010 */  beqz       $3, .L003AC160
    /* 2AC130 003AC130 00000000 */   nop
    /* 2AC134 003AC134 20E0F9AC */  sw         $25, -0x1FE0($7)
    /* 2AC138 003AC138 0F000000 */  sync
    /* 2AC13C 003AC13C 0F040000 */  sync.p
  .L003AC140:
    /* 2AC140 003AC140 00000000 */  nop
    /* 2AC144 003AC144 00000000 */  nop
    /* 2AC148 003AC148 00000000 */  nop
    /* 2AC14C 003AC14C 00000000 */  nop
    /* 2AC150 003AC150 00000000 */  nop
    /* 2AC154 003AC154 FAFF0041 */  bc0f       .L003AC140 /* handwritten instruction */
    /* 2AC158 003AC158 00000000 */   nop
    /* 2AC15C 003AC15C 00000000 */  nop
  .L003AC160:
    /* 2AC160 003AC160 00D4E38C */  lw         $3, -0x2C00($7)
    /* 2AC164 003AC164 00016330 */  andi       $3, $3, 0x100
    /* 2AC168 003AC168 15006010 */  beqz       $3, .L003AC1C0
    /* 2AC16C 003AC16C 00000000 */   nop
    /* 2AC170 003AC170 20E0F8AC */  sw         $24, -0x1FE0($7)
    /* 2AC174 003AC174 0F000000 */  sync
    /* 2AC178 003AC178 0F040000 */  sync.p
    /* 2AC17C 003AC17C 00000000 */  nop
  .L003AC180:
    /* 2AC180 003AC180 00000000 */  nop
    /* 2AC184 003AC184 00000000 */  nop
    /* 2AC188 003AC188 00000000 */  nop
    /* 2AC18C 003AC18C 00000000 */  nop
    /* 2AC190 003AC190 00000000 */  nop
    /* 2AC194 003AC194 FAFF0041 */  bc0f       .L003AC180 /* handwritten instruction */
    /* 2AC198 003AC198 00000000 */   nop
    /* 2AC19C 003AC19C 00000000 */  nop
  .L003AC1A0:
    /* 2AC1A0 003AC1A0 00D4E38C */  lw         $3, -0x2C00($7)
    /* 2AC1A4 003AC1A4 00016330 */  andi       $3, $3, 0x100
    /* 2AC1A8 003AC1A8 00000000 */  nop
    /* 2AC1AC 003AC1AC 00000000 */  nop
    /* 2AC1B0 003AC1B0 00000000 */  nop
    /* 2AC1B4 003AC1B4 FAFF6014 */  bnez       $3, .L003AC1A0
    /* 2AC1B8 003AC1B8 00000000 */   nop
    /* 2AC1BC 003AC1BC 00000000 */  nop
  .L003AC1C0:
    /* 2AC1C0 003AC1C0 10E0F8AC */  sw         $24, -0x1FF0($7)
    /* 2AC1C4 003AC1C4 80D4E0AC */  sw         $0, -0x2B80($7)
    /* 2AC1C8 003AC1C8 10D4F1AC */  sw         $17, -0x2BF0($7)
    /* 2AC1CC 003AC1CC 20D4F5AC */  sw         $21, -0x2BE0($7)
    /* 2AC1D0 003AC1D0 00D4F9AC */  sw         $25, -0x2C00($7)
    /* 2AC1D4 003AC1D4 0F000000 */  sync
    /* 2AC1D8 003AC1D8 0F040000 */  sync.p
    /* 2AC1DC 003AC1DC 00D4E38C */  lw         $3, -0x2C00($7)
    /* 2AC1E0 003AC1E0 00016330 */  andi       $3, $3, 0x100
    /* 2AC1E4 003AC1E4 14006010 */  beqz       $3, .L003AC238
    /* 2AC1E8 003AC1E8 00000000 */   nop
    /* 2AC1EC 003AC1EC 20E0F8AC */  sw         $24, -0x1FE0($7)
    /* 2AC1F0 003AC1F0 0F000000 */  sync
    /* 2AC1F4 003AC1F4 0F040000 */  sync.p
  .L003AC1F8:
    /* 2AC1F8 003AC1F8 00000000 */  nop
    /* 2AC1FC 003AC1FC 00000000 */  nop
    /* 2AC200 003AC200 00000000 */  nop
    /* 2AC204 003AC204 00000000 */  nop
    /* 2AC208 003AC208 00000000 */  nop
    /* 2AC20C 003AC20C FAFF0041 */  bc0f       .L003AC1F8 /* handwritten instruction */
    /* 2AC210 003AC210 00000000 */   nop
    /* 2AC214 003AC214 00000000 */  nop
  .L003AC218:
    /* 2AC218 003AC218 00D4E38C */  lw         $3, -0x2C00($7)
    /* 2AC21C 003AC21C 00016330 */  andi       $3, $3, 0x100
    /* 2AC220 003AC220 00000000 */  nop
    /* 2AC224 003AC224 00000000 */  nop
    /* 2AC228 003AC228 00000000 */  nop
    /* 2AC22C 003AC22C FAFF6014 */  bnez       $3, .L003AC218
    /* 2AC230 003AC230 00000000 */   nop
    /* 2AC234 003AC234 00000000 */  nop
  .L003AC238:
    /* 2AC238 003AC238 10E0F8AC */  sw         $24, -0x1FF0($7)
    /* 2AC23C 003AC23C 80D4F4AC */  sw         $20, -0x2B80($7)
    /* 2AC240 003AC240 10D4F2AC */  sw         $18, -0x2BF0($7)
    /* 2AC244 003AC244 20D4EFAC */  sw         $15, -0x2BE0($7)
    /* 2AC248 003AC248 00D4F9AC */  sw         $25, -0x2C00($7)
    /* 2AC24C 003AC24C 0F000000 */  sync
    /* 2AC250 003AC250 0F040000 */  sync.p
    /* 2AC254 003AC254 00D4E38C */  lw         $3, -0x2C00($7)
    /* 2AC258 003AC258 00016330 */  andi       $3, $3, 0x100
    /* 2AC25C 003AC25C 14006010 */  beqz       $3, .L003AC2B0
    /* 2AC260 003AC260 00000000 */   nop
    /* 2AC264 003AC264 20E0F8AC */  sw         $24, -0x1FE0($7)
    /* 2AC268 003AC268 0F000000 */  sync
    /* 2AC26C 003AC26C 0F040000 */  sync.p
  .L003AC270:
    /* 2AC270 003AC270 00000000 */  nop
    /* 2AC274 003AC274 00000000 */  nop
    /* 2AC278 003AC278 00000000 */  nop
    /* 2AC27C 003AC27C 00000000 */  nop
    /* 2AC280 003AC280 00000000 */  nop
    /* 2AC284 003AC284 FAFF0041 */  bc0f       .L003AC270 /* handwritten instruction */
    /* 2AC288 003AC288 00000000 */   nop
    /* 2AC28C 003AC28C 00000000 */  nop
  .L003AC290:
    /* 2AC290 003AC290 00D4E38C */  lw         $3, -0x2C00($7)
    /* 2AC294 003AC294 00016330 */  andi       $3, $3, 0x100
    /* 2AC298 003AC298 00000000 */  nop
    /* 2AC29C 003AC29C 00000000 */  nop
    /* 2AC2A0 003AC2A0 00000000 */  nop
    /* 2AC2A4 003AC2A4 FAFF6014 */  bnez       $3, .L003AC290
    /* 2AC2A8 003AC2A8 00000000 */   nop
    /* 2AC2AC 003AC2AC 00000000 */  nop
  .L003AC2B0:
    /* 2AC2B0 003AC2B0 2D28C001 */  daddu      $5, $14, $0
    /* 2AC2B4 003AC2B4 2D20A001 */  daddu      $4, $13, $0
    /* 2AC2B8 003AC2B8 2D188001 */  daddu      $3, $12, $0
    /* 2AC2BC 003AC2BC 2D300000 */  daddu      $6, $0, $0
  .L003AC2C0:
    /* 2AC2C0 003AC2C0 39000042 */  di /* handwritten instruction */
    /* 2AC2C4 003AC2C4 0F040000 */  sync.p
    /* 2AC2C8 003AC2C8 00600A40 */  mfc0       $10, $12 /* handwritten instruction */
    /* 2AC2CC 003AC2CC 24504B01 */  and        $10, $10, $11
    /* 2AC2D0 003AC2D0 00000000 */  nop
    /* 2AC2D4 003AC2D4 FAFF4015 */  bnez       $10, .L003AC2C0
    /* 2AC2D8 003AC2D8 00000000 */   nop
    /* 2AC2DC 003AC2DC 0000A3D8 */  lqc2       $vf3, (0x70000000 & 0xFFFF)($5)
    /* 2AC2E0 003AC2E0 1809C34B */  vmulx.xyz  $vf4, $vf1, $vf3x
    /* 2AC2E4 003AC2E4 5911C34B */  vmuly.xyz  $vf5, $vf2, $vf3y
    /* 2AC2E8 003AC2E8 DA0AC34B */  vmulz.xyz  $vf11, $vf1, $vf3z
    /* 2AC2EC 003AC2EC 1B13C34B */  vmulw.xyz  $vf12, $vf2, $vf3w
    /* 2AC2F0 003AC2F0 000086D8 */  lqc2       $vf6, 0x0($4)
    /* 2AC2F4 003AC2F4 10008DD8 */  lqc2       $vf13, 0x10($4)
    /* 2AC2F8 003AC2F8 200094D8 */  lqc2       $vf20, 0x20($4)
    /* 2AC2FC 003AC2FC 1000A3D8 */  lqc2       $vf3, (0x70000010 & 0xFFFF)($5)
    /* 2AC300 003AC300 30009BD8 */  lqc2       $vf27, 0x30($4)
    /* 2AC304 003AC304 980CC34B */  vmulx.xyz  $vf18, $vf1, $vf3x
    /* 2AC308 003AC308 D914C34B */  vmuly.xyz  $vf19, $vf2, $vf3y
    /* 2AC30C 003AC30C 5A0EC34B */  vmulz.xyz  $vf25, $vf1, $vf3z
    /* 2AC310 003AC310 9B16C34B */  vmulw.xyz  $vf26, $vf2, $vf3w
    /* 2AC314 003AC314 EC31C44B */  vsub.xyz   $vf7, $vf6, $vf4
    /* 2AC318 003AC318 2832C44B */  vadd.xyz   $vf8, $vf6, $vf4
    /* 2AC31C 003AC31C 6832C44B */  vadd.xyz   $vf9, $vf6, $vf4
    /* 2AC320 003AC320 AC32C44B */  vsub.xyz   $vf10, $vf6, $vf4
    /* 2AC324 003AC324 EC39C54B */  vsub.xyz   $vf7, $vf7, $vf5
    /* 2AC328 003AC328 2C42C54B */  vsub.xyz   $vf8, $vf8, $vf5
    /* 2AC32C 003AC32C 684AC54B */  vadd.xyz   $vf9, $vf9, $vf5
    /* 2AC330 003AC330 A852C54B */  vadd.xyz   $vf10, $vf10, $vf5
    /* 2AC334 003AC334 AC6BCB4B */  vsub.xyz   $vf14, $vf13, $vf11
    /* 2AC338 003AC338 E86BCB4B */  vadd.xyz   $vf15, $vf13, $vf11
    /* 2AC33C 003AC33C 286CCB4B */  vadd.xyz   $vf16, $vf13, $vf11
    /* 2AC340 003AC340 6C6CCB4B */  vsub.xyz   $vf17, $vf13, $vf11
    /* 2AC344 003AC344 AC73CC4B */  vsub.xyz   $vf14, $vf14, $vf12
    /* 2AC348 003AC348 EC7BCC4B */  vsub.xyz   $vf15, $vf15, $vf12
    /* 2AC34C 003AC34C 2884CC4B */  vadd.xyz   $vf16, $vf16, $vf12
    /* 2AC350 003AC350 688CCC4B */  vadd.xyz   $vf17, $vf17, $vf12
    /* 2AC354 003AC354 6CA5D24B */  vsub.xyz   $vf21, $vf20, $vf18
    /* 2AC358 003AC358 A8A5D24B */  vadd.xyz   $vf22, $vf20, $vf18
    /* 2AC35C 003AC35C E8A5D24B */  vadd.xyz   $vf23, $vf20, $vf18
    /* 2AC360 003AC360 2CA6D24B */  vsub.xyz   $vf24, $vf20, $vf18
    /* 2AC364 003AC364 6CADD34B */  vsub.xyz   $vf21, $vf21, $vf19
    /* 2AC368 003AC368 ACB5D34B */  vsub.xyz   $vf22, $vf22, $vf19
    /* 2AC36C 003AC36C E8BDD34B */  vadd.xyz   $vf23, $vf23, $vf19
    /* 2AC370 003AC370 28C6D34B */  vadd.xyz   $vf24, $vf24, $vf19
    /* 2AC374 003AC374 2CDFD94B */  vsub.xyz   $vf28, $vf27, $vf25
    /* 2AC378 003AC378 68DFD94B */  vadd.xyz   $vf29, $vf27, $vf25
    /* 2AC37C 003AC37C A8DFD94B */  vadd.xyz   $vf30, $vf27, $vf25
    /* 2AC380 003AC380 ECDFD94B */  vsub.xyz   $vf31, $vf27, $vf25
    /* 2AC384 003AC384 2CE7DA4B */  vsub.xyz   $vf28, $vf28, $vf26
    /* 2AC388 003AC388 6CEFDA4B */  vsub.xyz   $vf29, $vf29, $vf26
    /* 2AC38C 003AC38C A8F7DA4B */  vadd.xyz   $vf30, $vf30, $vf26
    /* 2AC390 003AC390 E8FFDA4B */  vadd.xyz   $vf31, $vf31, $vf26
    /* 2AC394 003AC394 000067F8 */  sqc2       $vf7, 0x0($3)
    /* 2AC398 003AC398 100068F8 */  sqc2       $vf8, 0x10($3)
    /* 2AC39C 003AC39C 200069F8 */  sqc2       $vf9, 0x20($3)
    /* 2AC3A0 003AC3A0 30006AF8 */  sqc2       $vf10, 0x30($3)
    /* 2AC3A4 003AC3A4 40006EF8 */  sqc2       $vf14, 0x40($3)
    /* 2AC3A8 003AC3A8 50006FF8 */  sqc2       $vf15, 0x50($3)
    /* 2AC3AC 003AC3AC 600070F8 */  sqc2       $vf16, 0x60($3)
    /* 2AC3B0 003AC3B0 700071F8 */  sqc2       $vf17, 0x70($3)
    /* 2AC3B4 003AC3B4 800075F8 */  sqc2       $vf21, 0x80($3)
    /* 2AC3B8 003AC3B8 900076F8 */  sqc2       $vf22, 0x90($3)
    /* 2AC3BC 003AC3BC A00077F8 */  sqc2       $vf23, 0xA0($3)
    /* 2AC3C0 003AC3C0 B00078F8 */  sqc2       $vf24, 0xB0($3)
    /* 2AC3C4 003AC3C4 C0007CF8 */  sqc2       $vf28, 0xC0($3)
    /* 2AC3C8 003AC3C8 D0007DF8 */  sqc2       $vf29, 0xD0($3)
    /* 2AC3CC 003AC3CC E0007EF8 */  sqc2       $vf30, 0xE0($3)
    /* 2AC3D0 003AC3D0 F0007FF8 */  sqc2       $vf31, 0xF0($3)
    /* 2AC3D4 003AC3D4 38000042 */  ei /* handwritten instruction */
    /* 2AC3D8 003AC3D8 0400C624 */  addiu      $6, $6, 0x4
    /* 2AC3DC 003AC3DC B800CA28 */  slti       $10, $6, 0xB8
    /* 2AC3E0 003AC3E0 2000A524 */  addiu      $5, $5, %lo(D_70000020)
    /* 2AC3E4 003AC3E4 00016324 */  addiu      $3, $3, 0x100
    /* 2AC3E8 003AC3E8 B5FF4015 */  bnez       $10, .L003AC2C0
    /* 2AC3EC 003AC3EC 40008424 */   addiu     $4, $4, 0x40
    /* 2AC3F0 003AC3F0 00D0E38C */  lw         $3, -0x3000($7)
    /* 2AC3F4 003AC3F4 00016330 */  andi       $3, $3, 0x100
    /* 2AC3F8 003AC3F8 0D006010 */  beqz       $3, .L003AC430
    /* 2AC3FC 003AC3FC 00000000 */   nop
    /* 2AC400 003AC400 20E0F9AC */  sw         $25, -0x1FE0($7)
    /* 2AC404 003AC404 0F000000 */  sync
    /* 2AC408 003AC408 0F040000 */  sync.p
    /* 2AC40C 003AC40C 00000000 */  nop
  .L003AC410:
    /* 2AC410 003AC410 00000000 */  nop
    /* 2AC414 003AC414 00000000 */  nop
    /* 2AC418 003AC418 00000000 */  nop
    /* 2AC41C 003AC41C 00000000 */  nop
    /* 2AC420 003AC420 00000000 */  nop
    /* 2AC424 003AC424 FAFF0041 */  bc0f       .L003AC410 /* handwritten instruction */
    /* 2AC428 003AC428 00000000 */   nop
    /* 2AC42C 003AC42C 00000000 */  nop
  .L003AC430:
    /* 2AC430 003AC430 00D4E38C */  lw         $3, -0x2C00($7)
    /* 2AC434 003AC434 00016330 */  andi       $3, $3, 0x100
    /* 2AC438 003AC438 15006010 */  beqz       $3, .L003AC490
    /* 2AC43C 003AC43C 00000000 */   nop
    /* 2AC440 003AC440 20E0F8AC */  sw         $24, -0x1FE0($7)
    /* 2AC444 003AC444 0F000000 */  sync
    /* 2AC448 003AC448 0F040000 */  sync.p
    /* 2AC44C 003AC44C 00000000 */  nop
  .L003AC450:
    /* 2AC450 003AC450 00000000 */  nop
    /* 2AC454 003AC454 00000000 */  nop
    /* 2AC458 003AC458 00000000 */  nop
    /* 2AC45C 003AC45C 00000000 */  nop
    /* 2AC460 003AC460 00000000 */  nop
    /* 2AC464 003AC464 FAFF0041 */  bc0f       .L003AC450 /* handwritten instruction */
    /* 2AC468 003AC468 00000000 */   nop
    /* 2AC46C 003AC46C 00000000 */  nop
  .L003AC470:
    /* 2AC470 003AC470 00D4E38C */  lw         $3, -0x2C00($7)
    /* 2AC474 003AC474 00016330 */  andi       $3, $3, 0x100
    /* 2AC478 003AC478 00000000 */  nop
    /* 2AC47C 003AC47C 00000000 */  nop
    /* 2AC480 003AC480 00000000 */  nop
    /* 2AC484 003AC484 FAFF6014 */  bnez       $3, .L003AC470
    /* 2AC488 003AC488 00000000 */   nop
    /* 2AC48C 003AC48C 00000000 */  nop
  .L003AC490:
    /* 2AC490 003AC490 10E0F9AC */  sw         $25, -0x1FF0($7)
    /* 2AC494 003AC494 80D0E9AC */  sw         $9, -0x2F80($7)
    /* 2AC498 003AC498 10D0F0AC */  sw         $16, -0x2FF0($7)
    /* 2AC49C 003AC49C 20D0E8AC */  sw         $8, -0x2FE0($7)
    /* 2AC4A0 003AC4A0 00D0F9AC */  sw         $25, -0x3000($7)
    /* 2AC4A4 003AC4A4 0F000000 */  sync
    /* 2AC4A8 003AC4A8 0F040000 */  sync.p
    /* 2AC4AC 003AC4AC 48FF7326 */  addiu      $19, $19, -0xB8
    /* 2AC4B0 003AC4B0 800B5226 */  addiu      $18, $18, 0xB80
    /* 2AC4B4 003AC4B4 B800612A */  slti       $1, $19, 0xB8
    /* 2AC4B8 003AC4B8 002E1026 */  addiu      $16, $16, 0x2E00
    /* 2AC4BC 003AC4BC 19FF2010 */  beqz       $1, .L003AC124
    /* 2AC4C0 003AC4C0 C0053126 */   addiu     $17, $17, 0x5C0
    /* 2AC4C4 003AC4C4 00000000 */  nop
  .L003AC4C8:
    /* 2AC4C8 003AC4C8 0400612A */  slti       $1, $19, 0x4
    /* 2AC4CC 003AC4CC 11012014 */  bnez       $1, .L003AC914
    /* 2AC4D0 003AC4D0 00000000 */   nop
    /* 2AC4D4 003AC4D4 03006106 */  bgez       $19, .L003AC4E4
    /* 2AC4D8 003AC4D8 83181300 */   sra       $3, $19, 2
    /* 2AC4DC 003AC4DC 03006326 */  addiu      $3, $19, 0x3
    /* 2AC4E0 003AC4E0 83180300 */  sra        $3, $3, 2
  .L003AC4E4:
    /* 2AC4E4 003AC4E4 80300300 */  sll        $6, $3, 2
    /* 2AC4E8 003AC4E8 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AC4EC 003AC4EC 00D0648C */  lw         $4, -0x3000($3)
    /* 2AC4F0 003AC4F0 00018430 */  andi       $4, $4, 0x100
    /* 2AC4F4 003AC4F4 0C008010 */  beqz       $4, .L003AC528
    /* 2AC4F8 003AC4F8 00000000 */   nop
    /* 2AC4FC 003AC4FC 00010424 */  addiu      $4, $0, 0x100
    /* 2AC500 003AC500 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2AC504 003AC504 0F000000 */  sync
    /* 2AC508 003AC508 0F040000 */  sync.p
  .L003AC50C:
    /* 2AC50C 003AC50C 00000000 */  nop
    /* 2AC510 003AC510 00000000 */  nop
    /* 2AC514 003AC514 00000000 */  nop
    /* 2AC518 003AC518 00000000 */  nop
    /* 2AC51C 003AC51C 00000000 */  nop
    /* 2AC520 003AC520 FAFF0041 */  bc0f       .L003AC50C /* handwritten instruction */
    /* 2AC524 003AC524 00000000 */   nop
  .L003AC528:
    /* 2AC528 003AC528 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AC52C 003AC52C 00D4648C */  lw         $4, -0x2C00($3)
    /* 2AC530 003AC530 00018430 */  andi       $4, $4, 0x100
    /* 2AC534 003AC534 14008010 */  beqz       $4, .L003AC588
    /* 2AC538 003AC538 00000000 */   nop
    /* 2AC53C 003AC53C 00020424 */  addiu      $4, $0, 0x200
    /* 2AC540 003AC540 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2AC544 003AC544 0F000000 */  sync
    /* 2AC548 003AC548 0F040000 */  sync.p
  .L003AC54C:
    /* 2AC54C 003AC54C 00000000 */  nop
    /* 2AC550 003AC550 00000000 */  nop
    /* 2AC554 003AC554 00000000 */  nop
    /* 2AC558 003AC558 00000000 */  nop
    /* 2AC55C 003AC55C 00000000 */  nop
    /* 2AC560 003AC560 FAFF0041 */  bc0f       .L003AC54C /* handwritten instruction */
    /* 2AC564 003AC564 00000000 */   nop
    /* 2AC568 003AC568 0110033C */  lui        $3, (0x10010000 >> 16)
  .L003AC56C:
    /* 2AC56C 003AC56C 00D4648C */  lw         $4, -0x2C00($3)
    /* 2AC570 003AC570 00018430 */  andi       $4, $4, 0x100
    /* 2AC574 003AC574 00000000 */  nop
    /* 2AC578 003AC578 00000000 */  nop
    /* 2AC57C 003AC57C 00000000 */  nop
    /* 2AC580 003AC580 FAFF8014 */  bnez       $4, .L003AC56C
    /* 2AC584 003AC584 00000000 */   nop
  .L003AC588:
    /* 2AC588 003AC588 00020424 */  addiu      $4, $0, 0x200
    /* 2AC58C 003AC58C 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AC590 003AC590 43280600 */  sra        $5, $6, 1
    /* 2AC594 003AC594 10E064AC */  sw         $4, -0x1FF0($3)
    /* 2AC598 003AC598 80D460AC */  sw         $0, -0x2B80($3)
    /* 2AC59C 003AC59C 0300C104 */  bgez       $6, .L003AC5AC
    /* 2AC5A0 003AC5A0 10D471AC */   sw        $17, -0x2BF0($3)
    /* 2AC5A4 003AC5A4 0100C324 */  addiu      $3, $6, 0x1
    /* 2AC5A8 003AC5A8 43280300 */  sra        $5, $3, 1
  .L003AC5AC:
    /* 2AC5AC 003AC5AC 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AC5B0 003AC5B0 00010424 */  addiu      $4, $0, 0x100
    /* 2AC5B4 003AC5B4 20D465AC */  sw         $5, -0x2BE0($3)
    /* 2AC5B8 003AC5B8 00D464AC */  sw         $4, -0x2C00($3)
    /* 2AC5BC 003AC5BC 0F000000 */  sync
    /* 2AC5C0 003AC5C0 0F040000 */  sync.p
    /* 2AC5C4 003AC5C4 00D4648C */  lw         $4, -0x2C00($3)
    /* 2AC5C8 003AC5C8 00018430 */  andi       $4, $4, 0x100
    /* 2AC5CC 003AC5CC 14008010 */  beqz       $4, .L003AC620
    /* 2AC5D0 003AC5D0 00000000 */   nop
    /* 2AC5D4 003AC5D4 00020424 */  addiu      $4, $0, 0x200
    /* 2AC5D8 003AC5D8 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2AC5DC 003AC5DC 0F000000 */  sync
    /* 2AC5E0 003AC5E0 0F040000 */  sync.p
  .L003AC5E4:
    /* 2AC5E4 003AC5E4 00000000 */  nop
    /* 2AC5E8 003AC5E8 00000000 */  nop
    /* 2AC5EC 003AC5EC 00000000 */  nop
    /* 2AC5F0 003AC5F0 00000000 */  nop
    /* 2AC5F4 003AC5F4 00000000 */  nop
    /* 2AC5F8 003AC5F8 FAFF0041 */  bc0f       .L003AC5E4 /* handwritten instruction */
    /* 2AC5FC 003AC5FC 00000000 */   nop
    /* 2AC600 003AC600 0110033C */  lui        $3, (0x10010000 >> 16)
  .L003AC604:
    /* 2AC604 003AC604 00D4648C */  lw         $4, -0x2C00($3)
    /* 2AC608 003AC608 00018430 */  andi       $4, $4, 0x100
    /* 2AC60C 003AC60C 00000000 */  nop
    /* 2AC610 003AC610 00000000 */  nop
    /* 2AC614 003AC614 00000000 */  nop
    /* 2AC618 003AC618 FAFF8014 */  bnez       $4, .L003AC604
    /* 2AC61C 003AC61C 00000000 */   nop
  .L003AC620:
    /* 2AC620 003AC620 00410500 */  sll        $8, $5, 4
    /* 2AC624 003AC624 00020524 */  addiu      $5, $0, 0x200
    /* 2AC628 003AC628 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AC62C 003AC62C 10E065AC */  sw         $5, -0x1FF0($3)
    /* 2AC630 003AC630 00010424 */  addiu      $4, $0, 0x100
    /* 2AC634 003AC634 80D468AC */  sw         $8, -0x2B80($3)
    /* 2AC638 003AC638 10D472AC */  sw         $18, -0x2BF0($3)
    /* 2AC63C 003AC63C 20D466AC */  sw         $6, -0x2BE0($3)
    /* 2AC640 003AC640 00D464AC */  sw         $4, -0x2C00($3)
    /* 2AC644 003AC644 0F000000 */  sync
    /* 2AC648 003AC648 0F040000 */  sync.p
    /* 2AC64C 003AC64C 00D4648C */  lw         $4, -0x2C00($3)
    /* 2AC650 003AC650 00018430 */  andi       $4, $4, 0x100
    /* 2AC654 003AC654 14008010 */  beqz       $4, .L003AC6A8
    /* 2AC658 003AC658 00000000 */   nop
    /* 2AC65C 003AC65C 20E065AC */  sw         $5, -0x1FE0($3)
    /* 2AC660 003AC660 0F000000 */  sync
    /* 2AC664 003AC664 0F040000 */  sync.p
  .L003AC668:
    /* 2AC668 003AC668 00000000 */  nop
    /* 2AC66C 003AC66C 00000000 */  nop
    /* 2AC670 003AC670 00000000 */  nop
    /* 2AC674 003AC674 00000000 */  nop
    /* 2AC678 003AC678 00000000 */  nop
    /* 2AC67C 003AC67C FAFF0041 */  bc0f       .L003AC668 /* handwritten instruction */
    /* 2AC680 003AC680 00000000 */   nop
    /* 2AC684 003AC684 0110033C */  lui        $3, (0x10010000 >> 16)
  .L003AC688:
    /* 2AC688 003AC688 00D4648C */  lw         $4, -0x2C00($3)
    /* 2AC68C 003AC68C 00018430 */  andi       $4, $4, 0x100
    /* 2AC690 003AC690 00000000 */  nop
    /* 2AC694 003AC694 00000000 */  nop
    /* 2AC698 003AC698 00000000 */  nop
    /* 2AC69C 003AC69C FAFF8014 */  bnez       $4, .L003AC688
    /* 2AC6A0 003AC6A0 00000000 */   nop
    /* 2AC6A4 003AC6A4 00000000 */  nop
  .L003AC6A8:
    /* 2AC6A8 003AC6A8 0070053C */  lui        $5, (0x70000010 >> 16)
    /* 2AC6AC 003AC6AC 0300C104 */  bgez       $6, .L003AC6BC
    /* 2AC6B0 003AC6B0 43180600 */   sra       $3, $6, 1
    /* 2AC6B4 003AC6B4 0100C324 */  addiu      $3, $6, 0x1
    /* 2AC6B8 003AC6B8 43180300 */  sra        $3, $3, 1
  .L003AC6BC:
    /* 2AC6BC 003AC6BC 2118C300 */  addu       $3, $6, $3
    /* 2AC6C0 003AC6C0 0070073C */  lui        $7, (0x700000F0 >> 16)
    /* 2AC6C4 003AC6C4 00190300 */  sll        $3, $3, 4
    /* 2AC6C8 003AC6C8 2A080600 */  slt        $1, $0, $6
    /* 2AC6CC 003AC6CC 25200701 */  or         $4, $8, $7
    /* 2AC6D0 003AC6D0 25186700 */  or         $3, $3, $7
    /* 2AC6D4 003AC6D4 4E002010 */  beqz       $1, .L003AC810
    /* 2AC6D8 003AC6D8 2D480000 */   daddu     $9, $0, $0
    /* 2AC6DC 003AC6DC 0100083C */  lui        $8, (0x10000 >> 16)
  .L003AC6E0:
    /* 2AC6E0 003AC6E0 39000042 */  di /* handwritten instruction */
    /* 2AC6E4 003AC6E4 0F040000 */  sync.p
    /* 2AC6E8 003AC6E8 00600740 */  mfc0       $7, $12 /* handwritten instruction */
    /* 2AC6EC 003AC6EC 2438E800 */  and        $7, $7, $8
    /* 2AC6F0 003AC6F0 00000000 */  nop
    /* 2AC6F4 003AC6F4 FAFFE014 */  bnez       $7, .L003AC6E0
    /* 2AC6F8 003AC6F8 00000000 */   nop
    /* 2AC6FC 003AC6FC 0000A3D8 */  lqc2       $vf3, (0x70000000 & 0xFFFF)($5)
    /* 2AC700 003AC700 1809C34B */  vmulx.xyz  $vf4, $vf1, $vf3x
    /* 2AC704 003AC704 5911C34B */  vmuly.xyz  $vf5, $vf2, $vf3y
    /* 2AC708 003AC708 DA0AC34B */  vmulz.xyz  $vf11, $vf1, $vf3z
    /* 2AC70C 003AC70C 1B13C34B */  vmulw.xyz  $vf12, $vf2, $vf3w
    /* 2AC710 003AC710 000086D8 */  lqc2       $vf6, (0x70000000 & 0xFFFF)($4)
    /* 2AC714 003AC714 10008DD8 */  lqc2       $vf13, (0x70000010 & 0xFFFF)($4)
    /* 2AC718 003AC718 200094D8 */  lqc2       $vf20, (0x70000020 & 0xFFFF)($4)
    /* 2AC71C 003AC71C 1000A3D8 */  lqc2       $vf3, (0x70000010 & 0xFFFF)($5)
    /* 2AC720 003AC720 30009BD8 */  lqc2       $vf27, (0x70000030 & 0xFFFF)($4)
    /* 2AC724 003AC724 980CC34B */  vmulx.xyz  $vf18, $vf1, $vf3x
    /* 2AC728 003AC728 D914C34B */  vmuly.xyz  $vf19, $vf2, $vf3y
    /* 2AC72C 003AC72C 5A0EC34B */  vmulz.xyz  $vf25, $vf1, $vf3z
    /* 2AC730 003AC730 9B16C34B */  vmulw.xyz  $vf26, $vf2, $vf3w
    /* 2AC734 003AC734 EC31C44B */  vsub.xyz   $vf7, $vf6, $vf4
    /* 2AC738 003AC738 2832C44B */  vadd.xyz   $vf8, $vf6, $vf4
    /* 2AC73C 003AC73C 6832C44B */  vadd.xyz   $vf9, $vf6, $vf4
    /* 2AC740 003AC740 AC32C44B */  vsub.xyz   $vf10, $vf6, $vf4
    /* 2AC744 003AC744 EC39C54B */  vsub.xyz   $vf7, $vf7, $vf5
    /* 2AC748 003AC748 2C42C54B */  vsub.xyz   $vf8, $vf8, $vf5
    /* 2AC74C 003AC74C 684AC54B */  vadd.xyz   $vf9, $vf9, $vf5
    /* 2AC750 003AC750 A852C54B */  vadd.xyz   $vf10, $vf10, $vf5
    /* 2AC754 003AC754 AC6BCB4B */  vsub.xyz   $vf14, $vf13, $vf11
    /* 2AC758 003AC758 E86BCB4B */  vadd.xyz   $vf15, $vf13, $vf11
    /* 2AC75C 003AC75C 286CCB4B */  vadd.xyz   $vf16, $vf13, $vf11
    /* 2AC760 003AC760 6C6CCB4B */  vsub.xyz   $vf17, $vf13, $vf11
    /* 2AC764 003AC764 AC73CC4B */  vsub.xyz   $vf14, $vf14, $vf12
    /* 2AC768 003AC768 EC7BCC4B */  vsub.xyz   $vf15, $vf15, $vf12
    /* 2AC76C 003AC76C 2884CC4B */  vadd.xyz   $vf16, $vf16, $vf12
    /* 2AC770 003AC770 688CCC4B */  vadd.xyz   $vf17, $vf17, $vf12
    /* 2AC774 003AC774 6CA5D24B */  vsub.xyz   $vf21, $vf20, $vf18
    /* 2AC778 003AC778 A8A5D24B */  vadd.xyz   $vf22, $vf20, $vf18
    /* 2AC77C 003AC77C E8A5D24B */  vadd.xyz   $vf23, $vf20, $vf18
    /* 2AC780 003AC780 2CA6D24B */  vsub.xyz   $vf24, $vf20, $vf18
    /* 2AC784 003AC784 6CADD34B */  vsub.xyz   $vf21, $vf21, $vf19
    /* 2AC788 003AC788 ACB5D34B */  vsub.xyz   $vf22, $vf22, $vf19
    /* 2AC78C 003AC78C E8BDD34B */  vadd.xyz   $vf23, $vf23, $vf19
    /* 2AC790 003AC790 28C6D34B */  vadd.xyz   $vf24, $vf24, $vf19
    /* 2AC794 003AC794 2CDFD94B */  vsub.xyz   $vf28, $vf27, $vf25
    /* 2AC798 003AC798 68DFD94B */  vadd.xyz   $vf29, $vf27, $vf25
    /* 2AC79C 003AC79C A8DFD94B */  vadd.xyz   $vf30, $vf27, $vf25
    /* 2AC7A0 003AC7A0 ECDFD94B */  vsub.xyz   $vf31, $vf27, $vf25
    /* 2AC7A4 003AC7A4 2CE7DA4B */  vsub.xyz   $vf28, $vf28, $vf26
    /* 2AC7A8 003AC7A8 6CEFDA4B */  vsub.xyz   $vf29, $vf29, $vf26
    /* 2AC7AC 003AC7AC A8F7DA4B */  vadd.xyz   $vf30, $vf30, $vf26
    /* 2AC7B0 003AC7B0 E8FFDA4B */  vadd.xyz   $vf31, $vf31, $vf26
    /* 2AC7B4 003AC7B4 000067F8 */  sqc2       $vf7, (0x70000000 & 0xFFFF)($3)
    /* 2AC7B8 003AC7B8 100068F8 */  sqc2       $vf8, (0x70000010 & 0xFFFF)($3)
    /* 2AC7BC 003AC7BC 200069F8 */  sqc2       $vf9, (0x70000020 & 0xFFFF)($3)
    /* 2AC7C0 003AC7C0 30006AF8 */  sqc2       $vf10, (0x70000030 & 0xFFFF)($3)
    /* 2AC7C4 003AC7C4 40006EF8 */  sqc2       $vf14, (0x70000040 & 0xFFFF)($3)
    /* 2AC7C8 003AC7C8 50006FF8 */  sqc2       $vf15, (0x70000050 & 0xFFFF)($3)
    /* 2AC7CC 003AC7CC 600070F8 */  sqc2       $vf16, (0x70000060 & 0xFFFF)($3)
    /* 2AC7D0 003AC7D0 700071F8 */  sqc2       $vf17, (0x70000070 & 0xFFFF)($3)
    /* 2AC7D4 003AC7D4 800075F8 */  sqc2       $vf21, (0x70000080 & 0xFFFF)($3)
    /* 2AC7D8 003AC7D8 900076F8 */  sqc2       $vf22, (0x70000090 & 0xFFFF)($3)
    /* 2AC7DC 003AC7DC A00077F8 */  sqc2       $vf23, (0x700000A0 & 0xFFFF)($3)
    /* 2AC7E0 003AC7E0 B00078F8 */  sqc2       $vf24, (0x700000B0 & 0xFFFF)($3)
    /* 2AC7E4 003AC7E4 C0007CF8 */  sqc2       $vf28, (0x700000C0 & 0xFFFF)($3)
    /* 2AC7E8 003AC7E8 D0007DF8 */  sqc2       $vf29, (0x700000D0 & 0xFFFF)($3)
    /* 2AC7EC 003AC7EC E0007EF8 */  sqc2       $vf30, (0x700000E0 & 0xFFFF)($3)
    /* 2AC7F0 003AC7F0 F0007FF8 */  sqc2       $vf31, (0x700000F0 & 0xFFFF)($3)
    /* 2AC7F4 003AC7F4 38000042 */  ei /* handwritten instruction */
    /* 2AC7F8 003AC7F8 04002925 */  addiu      $9, $9, 0x4
    /* 2AC7FC 003AC7FC 2A382601 */  slt        $7, $9, $6
    /* 2AC800 003AC800 2000A524 */  addiu      $5, $5, %lo(D_70000020)
    /* 2AC804 003AC804 00016324 */  addiu      $3, $3, %lo(D_70000100)
    /* 2AC808 003AC808 B5FFE014 */  bnez       $7, .L003AC6E0
    /* 2AC80C 003AC80C 40008424 */   addiu     $4, $4, %lo(D_70000040)
  .L003AC810:
    /* 2AC810 003AC810 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AC814 003AC814 00D0648C */  lw         $4, -0x3000($3)
    /* 2AC818 003AC818 00018430 */  andi       $4, $4, 0x100
    /* 2AC81C 003AC81C 0C008010 */  beqz       $4, .L003AC850
    /* 2AC820 003AC820 00000000 */   nop
    /* 2AC824 003AC824 00010424 */  addiu      $4, $0, 0x100
    /* 2AC828 003AC828 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2AC82C 003AC82C 0F000000 */  sync
    /* 2AC830 003AC830 0F040000 */  sync.p
  .L003AC834:
    /* 2AC834 003AC834 00000000 */  nop
    /* 2AC838 003AC838 00000000 */  nop
    /* 2AC83C 003AC83C 00000000 */  nop
    /* 2AC840 003AC840 00000000 */  nop
    /* 2AC844 003AC844 00000000 */  nop
    /* 2AC848 003AC848 FAFF0041 */  bc0f       .L003AC834 /* handwritten instruction */
    /* 2AC84C 003AC84C 00000000 */   nop
  .L003AC850:
    /* 2AC850 003AC850 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AC854 003AC854 00D4648C */  lw         $4, -0x2C00($3)
    /* 2AC858 003AC858 00018430 */  andi       $4, $4, 0x100
    /* 2AC85C 003AC85C 14008010 */  beqz       $4, .L003AC8B0
    /* 2AC860 003AC860 00000000 */   nop
    /* 2AC864 003AC864 00020424 */  addiu      $4, $0, 0x200
    /* 2AC868 003AC868 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2AC86C 003AC86C 0F000000 */  sync
    /* 2AC870 003AC870 0F040000 */  sync.p
  .L003AC874:
    /* 2AC874 003AC874 00000000 */  nop
    /* 2AC878 003AC878 00000000 */  nop
    /* 2AC87C 003AC87C 00000000 */  nop
    /* 2AC880 003AC880 00000000 */  nop
    /* 2AC884 003AC884 00000000 */  nop
    /* 2AC888 003AC888 FAFF0041 */  bc0f       .L003AC874 /* handwritten instruction */
    /* 2AC88C 003AC88C 00000000 */   nop
    /* 2AC890 003AC890 0110033C */  lui        $3, (0x10010000 >> 16)
  .L003AC894:
    /* 2AC894 003AC894 00D4648C */  lw         $4, -0x2C00($3)
    /* 2AC898 003AC898 00018430 */  andi       $4, $4, 0x100
    /* 2AC89C 003AC89C 00000000 */  nop
    /* 2AC8A0 003AC8A0 00000000 */  nop
    /* 2AC8A4 003AC8A4 00000000 */  nop
    /* 2AC8A8 003AC8A8 FAFF8014 */  bnez       $4, .L003AC894
    /* 2AC8AC 003AC8AC 00000000 */   nop
  .L003AC8B0:
    /* 2AC8B0 003AC8B0 00010424 */  addiu      $4, $0, 0x100
    /* 2AC8B4 003AC8B4 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AC8B8 003AC8B8 43380600 */  sra        $7, $6, 1
    /* 2AC8BC 003AC8BC 0300C104 */  bgez       $6, .L003AC8CC
    /* 2AC8C0 003AC8C0 10E064AC */   sw        $4, -0x1FF0($3)
    /* 2AC8C4 003AC8C4 0100C324 */  addiu      $3, $6, 0x1
    /* 2AC8C8 003AC8C8 43380300 */  sra        $7, $3, 1
  .L003AC8CC:
    /* 2AC8CC 003AC8CC 2120C700 */  addu       $4, $6, $7
    /* 2AC8D0 003AC8D0 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AC8D4 003AC8D4 00210400 */  sll        $4, $4, 4
    /* 2AC8D8 003AC8D8 80280600 */  sll        $5, $6, 2
    /* 2AC8DC 003AC8DC 80D064AC */  sw         $4, -0x2F80($3)
    /* 2AC8E0 003AC8E0 10D070AC */  sw         $16, -0x2FF0($3)
    /* 2AC8E4 003AC8E4 00010424 */  addiu      $4, $0, 0x100
    /* 2AC8E8 003AC8E8 20D065AC */  sw         $5, -0x2FE0($3)
    /* 2AC8EC 003AC8EC 00D064AC */  sw         $4, -0x3000($3)
    /* 2AC8F0 003AC8F0 0F000000 */  sync
    /* 2AC8F4 003AC8F4 0F040000 */  sync.p
    /* 2AC8F8 003AC8F8 00190700 */  sll        $3, $7, 4
    /* 2AC8FC 003AC8FC 00210500 */  sll        $4, $5, 4
    /* 2AC900 003AC900 21882302 */  addu       $17, $17, $3
    /* 2AC904 003AC904 21800402 */  addu       $16, $16, $4
    /* 2AC908 003AC908 00190600 */  sll        $3, $6, 4
    /* 2AC90C 003AC90C 23986602 */  subu       $19, $19, $6
    /* 2AC910 003AC910 21904302 */  addu       $18, $18, $3
  .L003AC914:
    /* 2AC914 003AC914 2A081300 */  slt        $1, $0, $19
    /* 2AC918 003AC918 6F002010 */  beqz       $1, .L003ACAD8
    /* 2AC91C 003AC91C 2D400000 */   daddu     $8, $0, $0
    /* 2AC920 003AC920 D400A727 */  addiu      $7, $29, 0xD4
    /* 2AC924 003AC924 80201E00 */  sll        $4, $30, 2
    /* 2AC928 003AC928 D000A527 */  addiu      $5, $29, 0xD0
    /* 2AC92C 003AC92C 0100063C */  lui        $6, (0x10000 >> 16)
  .L003AC930:
    /* 2AC930 003AC930 000021C6 */  lwc1       $f1, 0x0($17)
    /* 2AC934 003AC934 040020C6 */  lwc1       $f0, 0x4($17)
    /* 2AC938 003AC938 D000A1E7 */  swc1       $f1, 0xD0($29)
    /* 2AC93C 003AC93C 0000E0E4 */  swc1       $f0, 0x0($7)
  .L003AC940:
    /* 2AC940 003AC940 39000042 */  di /* handwritten instruction */
    /* 2AC944 003AC944 0F040000 */  sync.p
    /* 2AC948 003AC948 00600340 */  mfc0       $3, $12 /* handwritten instruction */
    /* 2AC94C 003AC94C 24186600 */  and        $3, $3, $6
    /* 2AC950 003AC950 00000000 */  nop
    /* 2AC954 003AC954 FAFF6014 */  bnez       $3, .L003AC940
    /* 2AC958 003AC958 00000000 */   nop
    /* 2AC95C 003AC95C 0000A3D8 */  lqc2       $vf3, 0x0($5)
    /* 2AC960 003AC960 1809C34B */  vmulx.xyz  $vf4, $vf1, $vf3x
    /* 2AC964 003AC964 5911C34B */  vmuly.xyz  $vf5, $vf2, $vf3y
    /* 2AC968 003AC968 000046DA */  lqc2       $vf6, 0x0($18)
    /* 2AC96C 003AC96C EC31C44B */  vsub.xyz   $vf7, $vf6, $vf4
    /* 2AC970 003AC970 2832C44B */  vadd.xyz   $vf8, $vf6, $vf4
    /* 2AC974 003AC974 6832C44B */  vadd.xyz   $vf9, $vf6, $vf4
    /* 2AC978 003AC978 AC32C44B */  vsub.xyz   $vf10, $vf6, $vf4
    /* 2AC97C 003AC97C EC39C54B */  vsub.xyz   $vf7, $vf7, $vf5
    /* 2AC980 003AC980 2C42C54B */  vsub.xyz   $vf8, $vf8, $vf5
    /* 2AC984 003AC984 684AC54B */  vadd.xyz   $vf9, $vf9, $vf5
    /* 2AC988 003AC988 A852C54B */  vadd.xyz   $vf10, $vf10, $vf5
    /* 2AC98C 003AC98C 000007FA */  sqc2       $vf7, 0x0($16)
    /* 2AC990 003AC990 100008FA */  sqc2       $vf8, 0x10($16)
    /* 2AC994 003AC994 200009FA */  sqc2       $vf9, 0x20($16)
    /* 2AC998 003AC998 30000AFA */  sqc2       $vf10, 0x30($16)
    /* 2AC99C 003AC99C 38000042 */  ei /* handwritten instruction */
    /* 2AC9A0 003AC9A0 01000825 */  addiu      $8, $8, 0x1
    /* 2AC9A4 003AC9A4 2A181301 */  slt        $3, $8, $19
    /* 2AC9A8 003AC9A8 21883702 */  addu       $17, $17, $23
    /* 2AC9AC 003AC9AC 21800402 */  addu       $16, $16, $4
    /* 2AC9B0 003AC9B0 DFFF6014 */  bnez       $3, .L003AC930
    /* 2AC9B4 003AC9B4 21905602 */   addu      $18, $18, $22
    /* 2AC9B8 003AC9B8 47000010 */  b          .L003ACAD8
    /* 2AC9BC 003AC9BC 00000000 */   nop
  .L003AC9C0:
    /* 2AC9C0 003AC9C0 C000A427 */  addiu      $4, $29, 0xC0
    /* 2AC9C4 003AC9C4 04FE100C */  jal        func_0043f810
    /* 2AC9C8 003AC9C8 0C000624 */   addiu     $6, $0, 0xC
    /* 2AC9CC 003AC9CC 2D288002 */  daddu      $5, $20, $0
    /* 2AC9D0 003AC9D0 B000A427 */  addiu      $4, $29, 0xB0
    /* 2AC9D4 003AC9D4 04FE100C */  jal        func_0043f810
    /* 2AC9D8 003AC9D8 0C000624 */   addiu     $6, $0, 0xC
    /* 2AC9DC 003AC9DC 0100033C */  lui        $3, (0x10000 >> 16)
  .L003AC9E0:
    /* 2AC9E0 003AC9E0 39000042 */  di /* handwritten instruction */
    /* 2AC9E4 003AC9E4 0F040000 */  sync.p
    /* 2AC9E8 003AC9E8 00600440 */  mfc0       $4, $12 /* handwritten instruction */
    /* 2AC9EC 003AC9EC 24208300 */  and        $4, $4, $3
    /* 2AC9F0 003AC9F0 00000000 */  nop
    /* 2AC9F4 003AC9F4 FAFF8014 */  bnez       $4, .L003AC9E0
    /* 2AC9F8 003AC9F8 00000000 */   nop
    /* 2AC9FC 003AC9FC 003F033C */  lui        $3, (0x3F000000 >> 16)
    /* 2ACA00 003ACA00 C000A527 */  addiu      $5, $29, 0xC0
    /* 2ACA04 003ACA04 00008344 */  mtc1       $3, $f0
    /* 2ACA08 003ACA08 B000A427 */  addiu      $4, $29, 0xB0
    /* 2ACA0C 003ACA0C 00000344 */  mfc1       $3, $f0
    /* 2ACA10 003ACA10 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2ACA14 003ACA14 FF02004A */  vnop
    /* 2ACA18 003ACA18 FF02004A */  vnop
    /* 2ACA1C 003ACA1C 0000A1D8 */  lqc2       $vf1, 0x0($5)
    /* 2ACA20 003ACA20 000082D8 */  lqc2       $vf2, 0x0($4)
    /* 2ACA24 003ACA24 5E08E04B */  vmuli.xyzw $vf1, $vf1, $I
    /* 2ACA28 003ACA28 9E10E04B */  vmuli.xyzw $vf2, $vf2, $I
    /* 2ACA2C 003ACA2C 38000042 */  ei /* handwritten instruction */
    /* 2ACA30 003ACA30 2A081300 */  slt        $1, $0, $19
    /* 2ACA34 003ACA34 28002010 */  beqz       $1, .L003ACAD8
    /* 2ACA38 003ACA38 2D400000 */   daddu     $8, $0, $0
    /* 2ACA3C 003ACA3C A400A727 */  addiu      $7, $29, 0xA4
    /* 2ACA40 003ACA40 80201E00 */  sll        $4, $30, 2
    /* 2ACA44 003ACA44 A000A527 */  addiu      $5, $29, 0xA0
    /* 2ACA48 003ACA48 0100063C */  lui        $6, (0x10000 >> 16)
  .L003ACA4C:
    /* 2ACA4C 003ACA4C 000021C6 */  lwc1       $f1, 0x0($17)
    /* 2ACA50 003ACA50 040020C6 */  lwc1       $f0, 0x4($17)
    /* 2ACA54 003ACA54 A000A1E7 */  swc1       $f1, 0xA0($29)
    /* 2ACA58 003ACA58 0000E0E4 */  swc1       $f0, 0x0($7)
    /* 2ACA5C 003ACA5C 00000000 */  nop
  .L003ACA60:
    /* 2ACA60 003ACA60 39000042 */  di /* handwritten instruction */
    /* 2ACA64 003ACA64 0F040000 */  sync.p
    /* 2ACA68 003ACA68 00600340 */  mfc0       $3, $12 /* handwritten instruction */
    /* 2ACA6C 003ACA6C 24186600 */  and        $3, $3, $6
    /* 2ACA70 003ACA70 00000000 */  nop
    /* 2ACA74 003ACA74 FAFF6014 */  bnez       $3, .L003ACA60
    /* 2ACA78 003ACA78 00000000 */   nop
    /* 2ACA7C 003ACA7C 0000A3D8 */  lqc2       $vf3, 0x0($5)
    /* 2ACA80 003ACA80 1809C34B */  vmulx.xyz  $vf4, $vf1, $vf3x
    /* 2ACA84 003ACA84 5911C34B */  vmuly.xyz  $vf5, $vf2, $vf3y
    /* 2ACA88 003ACA88 000046DA */  lqc2       $vf6, 0x0($18)
    /* 2ACA8C 003ACA8C EC31C44B */  vsub.xyz   $vf7, $vf6, $vf4
    /* 2ACA90 003ACA90 2832C44B */  vadd.xyz   $vf8, $vf6, $vf4
    /* 2ACA94 003ACA94 6832C44B */  vadd.xyz   $vf9, $vf6, $vf4
    /* 2ACA98 003ACA98 AC32C44B */  vsub.xyz   $vf10, $vf6, $vf4
    /* 2ACA9C 003ACA9C EC39C54B */  vsub.xyz   $vf7, $vf7, $vf5
    /* 2ACAA0 003ACAA0 2C42C54B */  vsub.xyz   $vf8, $vf8, $vf5
    /* 2ACAA4 003ACAA4 684AC54B */  vadd.xyz   $vf9, $vf9, $vf5
    /* 2ACAA8 003ACAA8 A852C54B */  vadd.xyz   $vf10, $vf10, $vf5
    /* 2ACAAC 003ACAAC 000007FA */  sqc2       $vf7, 0x0($16)
    /* 2ACAB0 003ACAB0 100008FA */  sqc2       $vf8, 0x10($16)
    /* 2ACAB4 003ACAB4 200009FA */  sqc2       $vf9, 0x20($16)
    /* 2ACAB8 003ACAB8 30000AFA */  sqc2       $vf10, 0x30($16)
    /* 2ACABC 003ACABC 38000042 */  ei /* handwritten instruction */
    /* 2ACAC0 003ACAC0 01000825 */  addiu      $8, $8, 0x1
    /* 2ACAC4 003ACAC4 2A181301 */  slt        $3, $8, $19
    /* 2ACAC8 003ACAC8 21883702 */  addu       $17, $17, $23
    /* 2ACACC 003ACACC 21800402 */  addu       $16, $16, $4
    /* 2ACAD0 003ACAD0 DEFF6014 */  bnez       $3, .L003ACA4C
    /* 2ACAD4 003ACAD4 21905602 */   addu      $18, $18, $22
  .L003ACAD8:
    /* 2ACAD8 003ACAD8 9000BFDF */  ld         $31, 0x90($29)
    /* 2ACADC 003ACADC 8000BE7B */  lq         $30, 0x80($29)
    /* 2ACAE0 003ACAE0 7000B77B */  lq         $23, 0x70($29)
    /* 2ACAE4 003ACAE4 6000B67B */  lq         $22, 0x60($29)
    /* 2ACAE8 003ACAE8 5000B57B */  lq         $21, 0x50($29)
    /* 2ACAEC 003ACAEC 4000B47B */  lq         $20, 0x40($29)
    /* 2ACAF0 003ACAF0 3000B37B */  lq         $19, 0x30($29)
    /* 2ACAF4 003ACAF4 2000B27B */  lq         $18, 0x20($29)
    /* 2ACAF8 003ACAF8 1000B17B */  lq         $17, 0x10($29)
    /* 2ACAFC 003ACAFC 0000B07B */  lq         $16, 0x0($29)
    /* 2ACB00 003ACB00 0800E003 */  jr         $31
    /* 2ACB04 003ACB04 E000BD27 */   addiu     $29, $29, 0xE0
    /* 2ACB08 003ACB08 00000000 */  nop
    /* 2ACB0C 003ACB0C 00000000 */  nop
.size func_003abf60, 0xbb0
