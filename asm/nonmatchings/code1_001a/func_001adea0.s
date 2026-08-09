.section .text
.set noat
.set noreorder
glabel func_001adea0
    /* ADEA0 001ADEA0 80FFBD27 */  addiu      $29, $29, -0x80
    /* ADEA4 001ADEA4 5000BFFF */  sd         $31, 0x50($29)
    /* ADEA8 001ADEA8 4000B37F */  sq         $19, 0x40($29)
    /* ADEAC 001ADEAC 3000B27F */  sq         $18, 0x30($29)
    /* ADEB0 001ADEB0 2000B17F */  sq         $17, 0x20($29)
    /* ADEB4 001ADEB4 1000B07F */  sq         $16, 0x10($29)
    /* ADEB8 001ADEB8 2D988000 */  daddu      $19, $4, $0
    /* ADEBC 001ADEBC 00070424 */  addiu      $4, $0, 0x700
    /* ADEC0 001ADEC0 344F060C */  jal        func_00193cd0
    /* ADEC4 001ADEC4 00000000 */   nop
    /* ADEC8 001ADEC8 35014014 */  bnez       $2, .L001AE3A0
    /* ADECC 001ADECC 00000000 */   nop
    /* ADED0 001ADED0 06050424 */  addiu      $4, $0, 0x506
    /* ADED4 001ADED4 344F060C */  jal        func_00193cd0
    /* ADED8 001ADED8 00000000 */   nop
    /* ADEDC 001ADEDC 30014014 */  bnez       $2, .L001AE3A0
    /* ADEE0 001ADEE0 00000000 */   nop
    /* ADEE4 001ADEE4 07050424 */  addiu      $4, $0, 0x507
    /* ADEE8 001ADEE8 344F060C */  jal        func_00193cd0
    /* ADEEC 001ADEEC 00000000 */   nop
    /* ADEF0 001ADEF0 2B014014 */  bnez       $2, .L001AE3A0
    /* ADEF4 001ADEF4 00000000 */   nop
    /* ADEF8 001ADEF8 3000728E */  lw         $18, 0x30($19)
    /* ADEFC 001ADEFC 640A448E */  lw         $4, 0xA64($18)
    /* ADF00 001ADF00 B8C9080C */  jal        func_002326e0
    /* ADF04 001ADF04 00000000 */   nop
    /* ADF08 001ADF08 000070DE */  ld         $16, 0x0($19)
    /* ADF0C 001ADF0C 3C1B0200 */  dsll32     $3, $2, 12
    /* ADF10 001ADF10 3E1B0300 */  dsrl32     $3, $3, 12
    /* ADF14 001ADF14 40000224 */  addiu      $2, $0, 0x40
    /* ADF18 001ADF18 8A006210 */  beq        $3, $2, .L001AE144
    /* ADF1C 001ADF1C 00000000 */   nop
    /* ADF20 001ADF20 20000424 */  addiu      $4, $0, 0x20
    /* ADF24 001ADF24 03006410 */  beq        $3, $4, .L001ADF34
    /* ADF28 001ADF28 00000000 */   nop
    /* ADF2C 001ADF2C 09010010 */  b          .L001AE354
    /* ADF30 001ADF30 00000000 */   nop
  .L001ADF34:
    /* ADF34 001ADF34 6000A427 */  addiu      $4, $29, 0x60
    /* ADF38 001ADF38 84C2070C */  jal        func_001f0a10
    /* ADF3C 001ADF3C 00000000 */   nop
    /* ADF40 001ADF40 7E00A297 */  lhu        $2, 0x7E($29)
    /* ADF44 001ADF44 00014234 */  ori        $2, $2, 0x100
    /* ADF48 001ADF48 7E00A2A7 */  sh         $2, 0x7E($29)
    /* ADF4C 001ADF4C 2D206002 */  daddu      $4, $19, $0
    /* ADF50 001ADF50 58DB070C */  jal        func_001f6d60
    /* ADF54 001ADF54 00000000 */   nop
    /* ADF58 001ADF58 3C140200 */  dsll32     $2, $2, 16
    /* ADF5C 001ADF5C 3F140200 */  dsra32     $2, $2, 16
    /* ADF60 001ADF60 6000A2AF */  sw         $2, 0x60($29)
    /* ADF64 001ADF64 62004104 */  bgez       $2, .L001AE0F0
    /* ADF68 001ADF68 00000000 */   nop
    /* ADF6C 001ADF6C 2D206002 */  daddu      $4, $19, $0
    /* ADF70 001ADF70 2D286002 */  daddu      $5, $19, $0
    /* ADF74 001ADF74 6000A627 */  addiu      $6, $29, 0x60
    /* ADF78 001ADF78 01000724 */  addiu      $7, $0, 0x1
    /* ADF7C 001ADF7C 2D40E000 */  daddu      $8, $7, $0
    /* ADF80 001ADF80 B8CD070C */  jal        func_001f36e0
    /* ADF84 001ADF84 00000000 */   nop
    /* ADF88 001ADF88 2D884000 */  daddu      $17, $2, $0
    /* ADF8C 001ADF8C 0C000324 */  addiu      $3, $0, 0xC
    /* ADF90 001ADF90 480043A4 */  sh         $3, 0x48($2)
    /* ADF94 001ADF94 2D202002 */  daddu      $4, $17, $0
    /* ADF98 001ADF98 01000524 */  addiu      $5, $0, 0x1
    /* ADF9C 001ADF9C 6451060C */  jal        func_00194590
    /* ADFA0 001ADFA0 00000000 */   nop
    /* ADFA4 001ADFA4 2D204002 */  daddu      $4, $18, $0
    /* ADFA8 001ADFA8 D009080C */  jal        func_00202740
    /* ADFAC 001ADFAC 00000000 */   nop
    /* ADFB0 001ADFB0 2D204000 */  daddu      $4, $2, $0
    /* ADFB4 001ADFB4 04000324 */  addiu      $3, $0, 0x4
    /* ADFB8 001ADFB8 000043A0 */  sb         $3, 0x0($2)
    /* ADFBC 001ADFBC 580023DE */  ld         $3, 0x58($17)
    /* ADFC0 001ADFC0 080043FC */  sd         $3, 0x8($2)
    /* ADFC4 001ADFC4 01000524 */  addiu      $5, $0, 0x1
    /* ADFC8 001ADFC8 6451060C */  jal        func_00194590
    /* ADFCC 001ADFCC 00000000 */   nop
    /* ADFD0 001ADFD0 0000A0FF */  sd         $0, 0x0($29)
    /* ADFD4 001ADFD4 2D204002 */  daddu      $4, $18, $0
    /* ADFD8 001ADFD8 2D284002 */  daddu      $5, $18, $0
    /* ADFDC 001ADFDC FFFF0624 */  addiu      $6, $0, -0x1
    /* ADFE0 001ADFE0 2D380000 */  daddu      $7, $0, $0
    /* ADFE4 001ADFE4 2D400000 */  daddu      $8, $0, $0
    /* ADFE8 001ADFE8 2D480000 */  daddu      $9, $0, $0
    /* ADFEC 001ADFEC 01000A24 */  addiu      $10, $0, 0x1
    /* ADFF0 001ADFF0 6000AB27 */  addiu      $11, $29, 0x60
    /* ADFF4 001ADFF4 7807080C */  jal        func_00201de0
    /* ADFF8 001ADFF8 00000000 */   nop
    /* ADFFC 001ADFFC 2D204000 */  daddu      $4, $2, $0
    /* AE000 001AE000 04000324 */  addiu      $3, $0, 0x4
    /* AE004 001AE004 000043A0 */  sb         $3, 0x0($2)
    /* AE008 001AE008 580023DE */  ld         $3, 0x58($17)
    /* AE00C 001AE00C 080043FC */  sd         $3, 0x8($2)
    /* AE010 001AE010 47004390 */  lbu        $3, 0x47($2)
    /* AE014 001AE014 DF006330 */  andi       $3, $3, 0xDF
    /* AE018 001AE018 470043A0 */  sb         $3, 0x47($2)
    /* AE01C 001AE01C 03000524 */  addiu      $5, $0, 0x3
    /* AE020 001AE020 6451060C */  jal        func_00194590
    /* AE024 001AE024 00000000 */   nop
    /* AE028 001AE028 2D204002 */  daddu      $4, $18, $0
    /* AE02C 001AE02C 2D280000 */  daddu      $5, $0, $0
    /* AE030 001AE030 2D300000 */  daddu      $6, $0, $0
    /* AE034 001AE034 6409080C */  jal        func_00202590
    /* AE038 001AE038 00000000 */   nop
    /* AE03C 001AE03C 2D204000 */  daddu      $4, $2, $0
    /* AE040 001AE040 04000324 */  addiu      $3, $0, 0x4
    /* AE044 001AE044 000043A0 */  sb         $3, 0x0($2)
    /* AE048 001AE048 580023DE */  ld         $3, 0x58($17)
    /* AE04C 001AE04C 080043FC */  sd         $3, 0x8($2)
    /* AE050 001AE050 47004390 */  lbu        $3, 0x47($2)
    /* AE054 001AE054 DF006330 */  andi       $3, $3, 0xDF
    /* AE058 001AE058 470043A0 */  sb         $3, 0x47($2)
    /* AE05C 001AE05C 03000524 */  addiu      $5, $0, 0x3
    /* AE060 001AE060 6451060C */  jal        func_00194590
    /* AE064 001AE064 00000000 */   nop
    /* AE068 001AE068 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* AE06C 001AE06C 00608244 */  mtc1       $2, $f12
    /* AE070 001AE070 3000648E */  lw         $4, 0x30($19)
    /* AE074 001AE074 FEFF0524 */  addiu      $5, $0, -0x2
    /* AE078 001AE078 2D300000 */  daddu      $6, $0, $0
    /* AE07C 001AE07C 2D380000 */  daddu      $7, $0, $0
    /* AE080 001AE080 B867060C */  jal        func_00199ee0
    /* AE084 001AE084 00000000 */   nop
    /* AE088 001AE088 2D204000 */  daddu      $4, $2, $0
    /* AE08C 001AE08C 04000324 */  addiu      $3, $0, 0x4
    /* AE090 001AE090 000043A0 */  sb         $3, 0x0($2)
    /* AE094 001AE094 580023DE */  ld         $3, 0x58($17)
    /* AE098 001AE098 080043FC */  sd         $3, 0x8($2)
    /* AE09C 001AE09C 0A000324 */  addiu      $3, $0, 0xA
    /* AE0A0 001AE0A0 200043A0 */  sb         $3, 0x20($2)
    /* AE0A4 001AE0A4 01030324 */  addiu      $3, $0, 0x301
    /* AE0A8 001AE0A8 280043A4 */  sh         $3, 0x28($2)
    /* AE0AC 001AE0AC 600050FC */  sd         $16, 0x60($2)
    /* AE0B0 001AE0B0 2D280000 */  daddu      $5, $0, $0
    /* AE0B4 001AE0B4 6451060C */  jal        func_00194590
    /* AE0B8 001AE0B8 00000000 */   nop
    /* AE0BC 001AE0BC 0A000424 */  addiu      $4, $0, 0xA
    /* AE0C0 001AE0C0 02000524 */  addiu      $5, $0, 0x2
    /* AE0C4 001AE0C4 18000624 */  addiu      $6, $0, 0x18
    /* AE0C8 001AE0C8 08DF070C */  jal        func_001f7c20
    /* AE0CC 001AE0CC 00000000 */   nop
    /* AE0D0 001AE0D0 2D204000 */  daddu      $4, $2, $0
    /* AE0D4 001AE0D4 04000324 */  addiu      $3, $0, 0x4
    /* AE0D8 001AE0D8 000043A0 */  sb         $3, 0x0($2)
    /* AE0DC 001AE0DC 580023DE */  ld         $3, 0x58($17)
    /* AE0E0 001AE0E0 080043FC */  sd         $3, 0x8($2)
    /* AE0E4 001AE0E4 01000524 */  addiu      $5, $0, 0x1
    /* AE0E8 001AE0E8 6451060C */  jal        func_00194590
    /* AE0EC 001AE0EC 00000000 */   nop
  .L001AE0F0:
    /* AE0F0 001AE0F0 6C006396 */  lhu        $3, 0x6C($19)
    /* AE0F4 001AE0F4 02000224 */  addiu      $2, $0, 0x2
    /* AE0F8 001AE0F8 09006210 */  beq        $3, $2, .L001AE120
    /* AE0FC 001AE0FC 00000000 */   nop
    /* AE100 001AE100 03000224 */  addiu      $2, $0, 0x3
    /* AE104 001AE104 06006210 */  beq        $3, $2, .L001AE120
    /* AE108 001AE108 00000000 */   nop
    /* AE10C 001AE10C 01000224 */  addiu      $2, $0, 0x1
    /* AE110 001AE110 03006210 */  beq        $3, $2, .L001AE120
    /* AE114 001AE114 00000000 */   nop
    /* AE118 001AE118 04000010 */  b          .L001AE12C
    /* AE11C 001AE11C 00000000 */   nop
  .L001AE120:
    /* AE120 001AE120 20000564 */  daddiu     $5, $0, 0x20
    /* AE124 001AE124 02000010 */  b          .L001AE130
    /* AE128 001AE128 00000000 */   nop
  .L001AE12C:
    /* AE12C 001AE12C 20000564 */  daddiu     $5, $0, 0x20
  .L001AE130:
    /* AE130 001AE130 2D206002 */  daddu      $4, $19, $0
    /* AE134 001AE134 00C2060C */  jal        func_001b0800
    /* AE138 001AE138 00000000 */   nop
    /* AE13C 001AE13C 98000010 */  b          .L001AE3A0
    /* AE140 001AE140 00000000 */   nop
  .L001AE144:
    /* AE144 001AE144 6000A427 */  addiu      $4, $29, 0x60
    /* AE148 001AE148 84C2070C */  jal        func_001f0a10
    /* AE14C 001AE14C 00000000 */   nop
    /* AE150 001AE150 7E00A297 */  lhu        $2, 0x7E($29)
    /* AE154 001AE154 00014234 */  ori        $2, $2, 0x100
    /* AE158 001AE158 7E00A2A7 */  sh         $2, 0x7E($29)
    /* AE15C 001AE15C 2D206002 */  daddu      $4, $19, $0
    /* AE160 001AE160 58DB070C */  jal        func_001f6d60
    /* AE164 001AE164 00000000 */   nop
    /* AE168 001AE168 3C140200 */  dsll32     $2, $2, 16
    /* AE16C 001AE16C 3F140200 */  dsra32     $2, $2, 16
    /* AE170 001AE170 6400A2AF */  sw         $2, 0x64($29)
    /* AE174 001AE174 62004104 */  bgez       $2, .L001AE300
    /* AE178 001AE178 00000000 */   nop
    /* AE17C 001AE17C 2D206002 */  daddu      $4, $19, $0
    /* AE180 001AE180 2D286002 */  daddu      $5, $19, $0
    /* AE184 001AE184 6000A627 */  addiu      $6, $29, 0x60
    /* AE188 001AE188 01000724 */  addiu      $7, $0, 0x1
    /* AE18C 001AE18C 2D40E000 */  daddu      $8, $7, $0
    /* AE190 001AE190 B8CD070C */  jal        func_001f36e0
    /* AE194 001AE194 00000000 */   nop
    /* AE198 001AE198 2D884000 */  daddu      $17, $2, $0
    /* AE19C 001AE19C 0C000324 */  addiu      $3, $0, 0xC
    /* AE1A0 001AE1A0 480043A4 */  sh         $3, 0x48($2)
    /* AE1A4 001AE1A4 2D202002 */  daddu      $4, $17, $0
    /* AE1A8 001AE1A8 01000524 */  addiu      $5, $0, 0x1
    /* AE1AC 001AE1AC 6451060C */  jal        func_00194590
    /* AE1B0 001AE1B0 00000000 */   nop
    /* AE1B4 001AE1B4 2D204002 */  daddu      $4, $18, $0
    /* AE1B8 001AE1B8 D009080C */  jal        func_00202740
    /* AE1BC 001AE1BC 00000000 */   nop
    /* AE1C0 001AE1C0 2D204000 */  daddu      $4, $2, $0
    /* AE1C4 001AE1C4 04000324 */  addiu      $3, $0, 0x4
    /* AE1C8 001AE1C8 000043A0 */  sb         $3, 0x0($2)
    /* AE1CC 001AE1CC 580023DE */  ld         $3, 0x58($17)
    /* AE1D0 001AE1D0 080043FC */  sd         $3, 0x8($2)
    /* AE1D4 001AE1D4 01000524 */  addiu      $5, $0, 0x1
    /* AE1D8 001AE1D8 6451060C */  jal        func_00194590
    /* AE1DC 001AE1DC 00000000 */   nop
    /* AE1E0 001AE1E0 0000A0FF */  sd         $0, 0x0($29)
    /* AE1E4 001AE1E4 2D204002 */  daddu      $4, $18, $0
    /* AE1E8 001AE1E8 2D284002 */  daddu      $5, $18, $0
    /* AE1EC 001AE1EC FFFF0624 */  addiu      $6, $0, -0x1
    /* AE1F0 001AE1F0 2D380000 */  daddu      $7, $0, $0
    /* AE1F4 001AE1F4 2D400000 */  daddu      $8, $0, $0
    /* AE1F8 001AE1F8 2D480000 */  daddu      $9, $0, $0
    /* AE1FC 001AE1FC 01000A24 */  addiu      $10, $0, 0x1
    /* AE200 001AE200 6000AB27 */  addiu      $11, $29, 0x60
    /* AE204 001AE204 7807080C */  jal        func_00201de0
    /* AE208 001AE208 00000000 */   nop
    /* AE20C 001AE20C 2D204000 */  daddu      $4, $2, $0
    /* AE210 001AE210 04000324 */  addiu      $3, $0, 0x4
    /* AE214 001AE214 000043A0 */  sb         $3, 0x0($2)
    /* AE218 001AE218 580023DE */  ld         $3, 0x58($17)
    /* AE21C 001AE21C 080043FC */  sd         $3, 0x8($2)
    /* AE220 001AE220 47004390 */  lbu        $3, 0x47($2)
    /* AE224 001AE224 DF006330 */  andi       $3, $3, 0xDF
    /* AE228 001AE228 470043A0 */  sb         $3, 0x47($2)
    /* AE22C 001AE22C 03000524 */  addiu      $5, $0, 0x3
    /* AE230 001AE230 6451060C */  jal        func_00194590
    /* AE234 001AE234 00000000 */   nop
    /* AE238 001AE238 2D204002 */  daddu      $4, $18, $0
    /* AE23C 001AE23C 01000524 */  addiu      $5, $0, 0x1
    /* AE240 001AE240 2D300000 */  daddu      $6, $0, $0
    /* AE244 001AE244 6409080C */  jal        func_00202590
    /* AE248 001AE248 00000000 */   nop
    /* AE24C 001AE24C 2D204000 */  daddu      $4, $2, $0
    /* AE250 001AE250 04000324 */  addiu      $3, $0, 0x4
    /* AE254 001AE254 000043A0 */  sb         $3, 0x0($2)
    /* AE258 001AE258 580023DE */  ld         $3, 0x58($17)
    /* AE25C 001AE25C 080043FC */  sd         $3, 0x8($2)
    /* AE260 001AE260 47004390 */  lbu        $3, 0x47($2)
    /* AE264 001AE264 DF006330 */  andi       $3, $3, 0xDF
    /* AE268 001AE268 470043A0 */  sb         $3, 0x47($2)
    /* AE26C 001AE26C 03000524 */  addiu      $5, $0, 0x3
    /* AE270 001AE270 6451060C */  jal        func_00194590
    /* AE274 001AE274 00000000 */   nop
    /* AE278 001AE278 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* AE27C 001AE27C 00608244 */  mtc1       $2, $f12
    /* AE280 001AE280 3000648E */  lw         $4, 0x30($19)
    /* AE284 001AE284 FEFF0524 */  addiu      $5, $0, -0x2
    /* AE288 001AE288 2D300000 */  daddu      $6, $0, $0
    /* AE28C 001AE28C 2D380000 */  daddu      $7, $0, $0
    /* AE290 001AE290 B867060C */  jal        func_00199ee0
    /* AE294 001AE294 00000000 */   nop
    /* AE298 001AE298 2D204000 */  daddu      $4, $2, $0
    /* AE29C 001AE29C 04000324 */  addiu      $3, $0, 0x4
    /* AE2A0 001AE2A0 000043A0 */  sb         $3, 0x0($2)
    /* AE2A4 001AE2A4 580023DE */  ld         $3, 0x58($17)
    /* AE2A8 001AE2A8 080043FC */  sd         $3, 0x8($2)
    /* AE2AC 001AE2AC 0A000324 */  addiu      $3, $0, 0xA
    /* AE2B0 001AE2B0 200043A0 */  sb         $3, 0x20($2)
    /* AE2B4 001AE2B4 01030324 */  addiu      $3, $0, 0x301
    /* AE2B8 001AE2B8 280043A4 */  sh         $3, 0x28($2)
    /* AE2BC 001AE2BC 600050FC */  sd         $16, 0x60($2)
    /* AE2C0 001AE2C0 2D280000 */  daddu      $5, $0, $0
    /* AE2C4 001AE2C4 6451060C */  jal        func_00194590
    /* AE2C8 001AE2C8 00000000 */   nop
    /* AE2CC 001AE2CC 0A000424 */  addiu      $4, $0, 0xA
    /* AE2D0 001AE2D0 02000524 */  addiu      $5, $0, 0x2
    /* AE2D4 001AE2D4 18000624 */  addiu      $6, $0, 0x18
    /* AE2D8 001AE2D8 08DF070C */  jal        func_001f7c20
    /* AE2DC 001AE2DC 00000000 */   nop
    /* AE2E0 001AE2E0 2D204000 */  daddu      $4, $2, $0
    /* AE2E4 001AE2E4 04000324 */  addiu      $3, $0, 0x4
    /* AE2E8 001AE2E8 000043A0 */  sb         $3, 0x0($2)
    /* AE2EC 001AE2EC 580023DE */  ld         $3, 0x58($17)
    /* AE2F0 001AE2F0 080043FC */  sd         $3, 0x8($2)
    /* AE2F4 001AE2F4 01000524 */  addiu      $5, $0, 0x1
    /* AE2F8 001AE2F8 6451060C */  jal        func_00194590
    /* AE2FC 001AE2FC 00000000 */   nop
  .L001AE300:
    /* AE300 001AE300 6C006396 */  lhu        $3, 0x6C($19)
    /* AE304 001AE304 02000224 */  addiu      $2, $0, 0x2
    /* AE308 001AE308 09006210 */  beq        $3, $2, .L001AE330
    /* AE30C 001AE30C 00000000 */   nop
    /* AE310 001AE310 03000224 */  addiu      $2, $0, 0x3
    /* AE314 001AE314 06006210 */  beq        $3, $2, .L001AE330
    /* AE318 001AE318 00000000 */   nop
    /* AE31C 001AE31C 01000224 */  addiu      $2, $0, 0x1
    /* AE320 001AE320 03006210 */  beq        $3, $2, .L001AE330
    /* AE324 001AE324 00000000 */   nop
    /* AE328 001AE328 04000010 */  b          .L001AE33C
    /* AE32C 001AE32C 00000000 */   nop
  .L001AE330:
    /* AE330 001AE330 20000564 */  daddiu     $5, $0, 0x20
    /* AE334 001AE334 02000010 */  b          .L001AE340
    /* AE338 001AE338 00000000 */   nop
  .L001AE33C:
    /* AE33C 001AE33C 20000564 */  daddiu     $5, $0, 0x20
  .L001AE340:
    /* AE340 001AE340 2D206002 */  daddu      $4, $19, $0
    /* AE344 001AE344 00C2060C */  jal        func_001b0800
    /* AE348 001AE348 00000000 */   nop
    /* AE34C 001AE34C 14000010 */  b          .L001AE3A0
    /* AE350 001AE350 00000000 */   nop
  .L001AE354:
    /* AE354 001AE354 6C006396 */  lhu        $3, 0x6C($19)
    /* AE358 001AE358 02000224 */  addiu      $2, $0, 0x2
    /* AE35C 001AE35C 09006210 */  beq        $3, $2, .L001AE384
    /* AE360 001AE360 00000000 */   nop
    /* AE364 001AE364 03000224 */  addiu      $2, $0, 0x3
    /* AE368 001AE368 06006210 */  beq        $3, $2, .L001AE384
    /* AE36C 001AE36C 00000000 */   nop
    /* AE370 001AE370 01000224 */  addiu      $2, $0, 0x1
    /* AE374 001AE374 03006210 */  beq        $3, $2, .L001AE384
    /* AE378 001AE378 00000000 */   nop
    /* AE37C 001AE37C 04000010 */  b          .L001AE390
    /* AE380 001AE380 00000000 */   nop
  .L001AE384:
    /* AE384 001AE384 20000564 */  daddiu     $5, $0, 0x20
    /* AE388 001AE388 02000010 */  b          .L001AE394
    /* AE38C 001AE38C 00000000 */   nop
  .L001AE390:
    /* AE390 001AE390 FFFF8530 */  andi       $5, $4, 0xFFFF
  .L001AE394:
    /* AE394 001AE394 2D206002 */  daddu      $4, $19, $0
    /* AE398 001AE398 00C2060C */  jal        func_001b0800
    /* AE39C 001AE39C 00000000 */   nop
  .L001AE3A0:
    /* AE3A0 001AE3A0 5000BFDF */  ld         $31, 0x50($29)
    /* AE3A4 001AE3A4 4000B37B */  lq         $19, 0x40($29)
    /* AE3A8 001AE3A8 3000B27B */  lq         $18, 0x30($29)
    /* AE3AC 001AE3AC 2000B17B */  lq         $17, 0x20($29)
    /* AE3B0 001AE3B0 1000B07B */  lq         $16, 0x10($29)
    /* AE3B4 001AE3B4 8000BD27 */  addiu      $29, $29, 0x80
    /* AE3B8 001AE3B8 0800E003 */  jr         $31
    /* AE3BC 001AE3BC 00000000 */   nop
.size func_001adea0, 0x520
