.section .text
.set noat
.set noreorder
glabel func_001acf50
    /* ACF50 001ACF50 B0FFBD27 */  addiu      $29, $29, -0x50
    /* ACF54 001ACF54 2000BFFF */  sd         $31, 0x20($29)
    /* ACF58 001ACF58 1000B17F */  sq         $17, 0x10($29)
    /* ACF5C 001ACF5C 0000B07F */  sq         $16, 0x0($29)
    /* ACF60 001ACF60 2D888000 */  daddu      $17, $4, $0
    /* ACF64 001ACF64 6C008394 */  lhu        $3, 0x6C($4)
    /* ACF68 001ACF68 0B000224 */  addiu      $2, $0, 0xB
    /* ACF6C 001ACF6C A3006210 */  beq        $3, $2, .L001AD1FC
    /* ACF70 001ACF70 00000000 */   nop
    /* ACF74 001ACF74 08000224 */  addiu      $2, $0, 0x8
    /* ACF78 001ACF78 A0006210 */  beq        $3, $2, .L001AD1FC
    /* ACF7C 001ACF7C 00000000 */   nop
    /* ACF80 001ACF80 07000224 */  addiu      $2, $0, 0x7
    /* ACF84 001ACF84 03006210 */  beq        $3, $2, .L001ACF94
    /* ACF88 001ACF88 00000000 */   nop
    /* ACF8C 001ACF8C 9B000010 */  b          .L001AD1FC
    /* ACF90 001ACF90 00000000 */   nop
  .L001ACF94:
    /* ACF94 001ACF94 EC80060C */  jal        func_001a03b0
    /* ACF98 001ACF98 00000000 */   nop
    /* ACF9C 001ACF9C 2D200000 */  daddu      $4, $0, $0
    /* ACFA0 001ACFA0 03000524 */  addiu      $5, $0, 0x3
    /* ACFA4 001ACFA4 F079060C */  jal        func_0019e7c0
    /* ACFA8 001ACFA8 00000000 */   nop
    /* ACFAC 001ACFAC 2D204000 */  daddu      $4, $2, $0
    /* ACFB0 001ACFB0 000023DE */  ld         $3, 0x0($17)
    /* ACFB4 001ACFB4 600043FC */  sd         $3, 0x60($2)
    /* ACFB8 001ACFB8 2D280000 */  daddu      $5, $0, $0
    /* ACFBC 001ACFBC 6451060C */  jal        func_00194590
    /* ACFC0 001ACFC0 00000000 */   nop
    /* ACFC4 001ACFC4 EC002586 */  lh         $5, 0xEC($17)
    /* ACFC8 001ACFC8 0C00A010 */  beqz       $5, .L001ACFFC
    /* ACFCC 001ACFCC 00000000 */   nop
    /* ACFD0 001ACFD0 3000248E */  lw         $4, 0x30($17)
    /* ACFD4 001ACFD4 0009080C */  jal        func_00202400
    /* ACFD8 001ACFD8 00000000 */   nop
    /* ACFDC 001ACFDC 2D204000 */  daddu      $4, $2, $0
    /* ACFE0 001ACFE0 000023DE */  ld         $3, 0x0($17)
    /* ACFE4 001ACFE4 600043FC */  sd         $3, 0x60($2)
    /* ACFE8 001ACFE8 03000524 */  addiu      $5, $0, 0x3
    /* ACFEC 001ACFEC 6451060C */  jal        func_00194590
    /* ACFF0 001ACFF0 00000000 */   nop
    /* ACFF4 001ACFF4 13000010 */  b          .L001AD044
    /* ACFF8 001ACFF8 00000000 */   nop
  .L001ACFFC:
    /* ACFFC 001ACFFC 3000248E */  lw         $4, 0x30($17)
    /* AD000 001AD000 9C00828C */  lw         $2, 0x9C($4)
    /* AD004 001AD004 00404230 */  andi       $2, $2, 0x4000
    /* AD008 001AD008 04004010 */  beqz       $2, .L001AD01C
    /* AD00C 001AD00C 00000000 */   nop
    /* AD010 001AD010 6C002296 */  lhu        $2, 0x6C($17)
    /* AD014 001AD014 02000010 */  b          .L001AD020
    /* AD018 001AD018 00000000 */   nop
  .L001AD01C:
    /* AD01C 001AD01C 08000224 */  addiu      $2, $0, 0x8
  .L001AD020:
    /* AD020 001AD020 FFFF4530 */  andi       $5, $2, 0xFFFF
    /* AD024 001AD024 B808080C */  jal        func_002022e0
    /* AD028 001AD028 00000000 */   nop
    /* AD02C 001AD02C 2D204000 */  daddu      $4, $2, $0
    /* AD030 001AD030 000023DE */  ld         $3, 0x0($17)
    /* AD034 001AD034 600043FC */  sd         $3, 0x60($2)
    /* AD038 001AD038 03000524 */  addiu      $5, $0, 0x3
    /* AD03C 001AD03C 6451060C */  jal        func_00194590
    /* AD040 001AD040 00000000 */   nop
  .L001AD044:
    /* AD044 001AD044 2D202002 */  daddu      $4, $17, $0
    /* AD048 001AD048 16000524 */  addiu      $5, $0, 0x16
    /* AD04C 001AD04C 2D300000 */  daddu      $6, $0, $0
    /* AD050 001AD050 2D380000 */  daddu      $7, $0, $0
    /* AD054 001AD054 2D400000 */  daddu      $8, $0, $0
    /* AD058 001AD058 70E6070C */  jal        func_001f99c0
    /* AD05C 001AD05C 00000000 */   nop
    /* AD060 001AD060 2D204000 */  daddu      $4, $2, $0
    /* AD064 001AD064 000023DE */  ld         $3, 0x0($17)
    /* AD068 001AD068 600043FC */  sd         $3, 0x60($2)
    /* AD06C 001AD06C 01000524 */  addiu      $5, $0, 0x1
    /* AD070 001AD070 6451060C */  jal        func_00194590
    /* AD074 001AD074 00000000 */   nop
    /* AD078 001AD078 3000228E */  lw         $2, 0x30($17)
    /* AD07C 001AD07C 9C00428C */  lw         $2, 0x9C($2)
    /* AD080 001AD080 00404230 */  andi       $2, $2, 0x4000
    /* AD084 001AD084 53004010 */  beqz       $2, .L001AD1D4
    /* AD088 001AD088 00000000 */   nop
    /* AD08C 001AD08C 2D202002 */  daddu      $4, $17, $0
    /* AD090 001AD090 32000524 */  addiu      $5, $0, 0x32
    /* AD094 001AD094 48F2060C */  jal        func_001bc920
    /* AD098 001AD098 00000000 */   nop
    /* AD09C 001AD09C 2D204000 */  daddu      $4, $2, $0
    /* AD0A0 001AD0A0 000023DE */  ld         $3, 0x0($17)
    /* AD0A4 001AD0A4 600043FC */  sd         $3, 0x60($2)
    /* AD0A8 001AD0A8 2D280000 */  daddu      $5, $0, $0
    /* AD0AC 001AD0AC 6451060C */  jal        func_00194590
    /* AD0B0 001AD0B0 00000000 */   nop
    /* AD0B4 001AD0B4 3000248E */  lw         $4, 0x30($17)
    /* AD0B8 001AD0B8 0462060C */  jal        func_00198810
    /* AD0BC 001AD0BC 00000000 */   nop
    /* AD0C0 001AD0C0 3C1C0200 */  dsll32     $3, $2, 16
    /* AD0C4 001AD0C4 3F1C0300 */  dsra32     $3, $3, 16
    /* AD0C8 001AD0C8 11000224 */  addiu      $2, $0, 0x11
    /* AD0CC 001AD0CC 0D006210 */  beq        $3, $2, .L001AD104
    /* AD0D0 001AD0D0 00000000 */   nop
    /* AD0D4 001AD0D4 3000248E */  lw         $4, 0x30($17)
    /* AD0D8 001AD0D8 606A060C */  jal        func_0019a980
    /* AD0DC 001AD0DC 00000000 */   nop
    /* AD0E0 001AD0E0 2D804000 */  daddu      $16, $2, $0
    /* AD0E4 001AD0E4 000023DE */  ld         $3, 0x0($17)
    /* AD0E8 001AD0E8 600043FC */  sd         $3, 0x60($2)
    /* AD0EC 001AD0EC 2D200002 */  daddu      $4, $16, $0
    /* AD0F0 001AD0F0 2D280000 */  daddu      $5, $0, $0
    /* AD0F4 001AD0F4 6451060C */  jal        func_00194590
    /* AD0F8 001AD0F8 00000000 */   nop
    /* AD0FC 001AD0FC 0A000010 */  b          .L001AD128
    /* AD100 001AD100 00000000 */   nop
  .L001AD104:
    /* AD104 001AD104 D852060C */  jal        func_00194b60
    /* AD108 001AD108 00000000 */   nop
    /* AD10C 001AD10C 2D804000 */  daddu      $16, $2, $0
    /* AD110 001AD110 000023DE */  ld         $3, 0x0($17)
    /* AD114 001AD114 600043FC */  sd         $3, 0x60($2)
    /* AD118 001AD118 2D200002 */  daddu      $4, $16, $0
    /* AD11C 001AD11C 2D280000 */  daddu      $5, $0, $0
    /* AD120 001AD120 6451060C */  jal        func_00194590
    /* AD124 001AD124 00000000 */   nop
  .L001AD128:
    /* AD128 001AD128 3000A427 */  addiu      $4, $29, 0x30
    /* AD12C 001AD12C 84C2070C */  jal        func_001f0a10
    /* AD130 001AD130 00000000 */   nop
    /* AD134 001AD134 4E00A297 */  lhu        $2, 0x4E($29)
    /* AD138 001AD138 80004234 */  ori        $2, $2, 0x80
    /* AD13C 001AD13C 4E00A2A7 */  sh         $2, 0x4E($29)
    /* AD140 001AD140 2D202002 */  daddu      $4, $17, $0
    /* AD144 001AD144 2D282002 */  daddu      $5, $17, $0
    /* AD148 001AD148 3000A627 */  addiu      $6, $29, 0x30
    /* AD14C 001AD14C 01000724 */  addiu      $7, $0, 0x1
    /* AD150 001AD150 2D40E000 */  daddu      $8, $7, $0
    /* AD154 001AD154 B8CD070C */  jal        func_001f36e0
    /* AD158 001AD158 00000000 */   nop
    /* AD15C 001AD15C 2D204000 */  daddu      $4, $2, $0
    /* AD160 001AD160 04000324 */  addiu      $3, $0, 0x4
    /* AD164 001AD164 000043A0 */  sb         $3, 0x0($2)
    /* AD168 001AD168 580003DE */  ld         $3, 0x58($16)
    /* AD16C 001AD16C 080043FC */  sd         $3, 0x8($2)
    /* AD170 001AD170 000023DE */  ld         $3, 0x0($17)
    /* AD174 001AD174 600043FC */  sd         $3, 0x60($2)
    /* AD178 001AD178 01000524 */  addiu      $5, $0, 0x1
    /* AD17C 001AD17C 6451060C */  jal        func_00194590
    /* AD180 001AD180 00000000 */   nop
    /* AD184 001AD184 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* AD188 001AD188 00608244 */  mtc1       $2, $f12
    /* AD18C 001AD18C 3000248E */  lw         $4, 0x30($17)
    /* AD190 001AD190 18000524 */  addiu      $5, $0, 0x18
    /* AD194 001AD194 06000624 */  addiu      $6, $0, 0x6
    /* AD198 001AD198 01000724 */  addiu      $7, $0, 0x1
    /* AD19C 001AD19C B867060C */  jal        func_00199ee0
    /* AD1A0 001AD1A0 00000000 */   nop
    /* AD1A4 001AD1A4 2D204000 */  daddu      $4, $2, $0
    /* AD1A8 001AD1A8 04000324 */  addiu      $3, $0, 0x4
    /* AD1AC 001AD1AC 000043A0 */  sb         $3, 0x0($2)
    /* AD1B0 001AD1B0 580003DE */  ld         $3, 0x58($16)
    /* AD1B4 001AD1B4 080043FC */  sd         $3, 0x8($2)
    /* AD1B8 001AD1B8 000023DE */  ld         $3, 0x0($17)
    /* AD1BC 001AD1BC 600043FC */  sd         $3, 0x60($2)
    /* AD1C0 001AD1C0 2D280000 */  daddu      $5, $0, $0
    /* AD1C4 001AD1C4 6451060C */  jal        func_00194590
    /* AD1C8 001AD1C8 00000000 */   nop
    /* AD1CC 001AD1CC 0B000010 */  b          .L001AD1FC
    /* AD1D0 001AD1D0 00000000 */   nop
  .L001AD1D4:
    /* AD1D4 001AD1D4 2D202002 */  daddu      $4, $17, $0
    /* AD1D8 001AD1D8 0A000524 */  addiu      $5, $0, 0xA
    /* AD1DC 001AD1DC 48F2060C */  jal        func_001bc920
    /* AD1E0 001AD1E0 00000000 */   nop
    /* AD1E4 001AD1E4 2D204000 */  daddu      $4, $2, $0
    /* AD1E8 001AD1E8 000023DE */  ld         $3, 0x0($17)
    /* AD1EC 001AD1EC 600043FC */  sd         $3, 0x60($2)
    /* AD1F0 001AD1F0 2D280000 */  daddu      $5, $0, $0
    /* AD1F4 001AD1F4 6451060C */  jal        func_00194590
    /* AD1F8 001AD1F8 00000000 */   nop
  .L001AD1FC:
    /* AD1FC 001AD1FC 2D202002 */  daddu      $4, $17, $0
    /* AD200 001AD200 2D280000 */  daddu      $5, $0, $0
    /* AD204 001AD204 1CCE070C */  jal        func_001f3870
    /* AD208 001AD208 00000000 */   nop
    /* AD20C 001AD20C 2D204000 */  daddu      $4, $2, $0
    /* AD210 001AD210 01000524 */  addiu      $5, $0, 0x1
    /* AD214 001AD214 6451060C */  jal        func_00194590
    /* AD218 001AD218 00000000 */   nop
    /* AD21C 001AD21C 2D202002 */  daddu      $4, $17, $0
    /* AD220 001AD220 38DA070C */  jal        func_001f68e0
    /* AD224 001AD224 00000000 */   nop
    /* AD228 001AD228 0B004010 */  beqz       $2, .L001AD258
    /* AD22C 001AD22C 00000000 */   nop
    /* AD230 001AD230 6C002396 */  lhu        $3, 0x6C($17)
    /* AD234 001AD234 08000224 */  addiu      $2, $0, 0x8
    /* AD238 001AD238 07006210 */  beq        $3, $2, .L001AD258
    /* AD23C 001AD23C 00000000 */   nop
    /* AD240 001AD240 2D202002 */  daddu      $4, $17, $0
    /* AD244 001AD244 1B000524 */  addiu      $5, $0, 0x1B
    /* AD248 001AD248 00C2060C */  jal        func_001b0800
    /* AD24C 001AD24C 00000000 */   nop
    /* AD250 001AD250 05000010 */  b          .L001AD268
    /* AD254 001AD254 00000000 */   nop
  .L001AD258:
    /* AD258 001AD258 2D202002 */  daddu      $4, $17, $0
    /* AD25C 001AD25C 20000524 */  addiu      $5, $0, 0x20
    /* AD260 001AD260 00C2060C */  jal        func_001b0800
    /* AD264 001AD264 00000000 */   nop
  .L001AD268:
    /* AD268 001AD268 2000BFDF */  ld         $31, 0x20($29)
    /* AD26C 001AD26C 1000B17B */  lq         $17, 0x10($29)
    /* AD270 001AD270 0000B07B */  lq         $16, 0x0($29)
    /* AD274 001AD274 5000BD27 */  addiu      $29, $29, 0x50
    /* AD278 001AD278 0800E003 */  jr         $31
    /* AD27C 001AD27C 00000000 */   nop
.size func_001acf50, 0x330
