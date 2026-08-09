.section .text
.set noat
.set noreorder
glabel func_001ed060
    /* ED060 001ED060 80FFBD27 */  addiu      $29, $29, -0x80
    /* ED064 001ED064 7000BFFF */  sd         $31, 0x70($29)
    /* ED068 001ED068 6000B67F */  sq         $22, 0x60($29)
    /* ED06C 001ED06C 5000B57F */  sq         $21, 0x50($29)
    /* ED070 001ED070 4000B47F */  sq         $20, 0x40($29)
    /* ED074 001ED074 3000B37F */  sq         $19, 0x30($29)
    /* ED078 001ED078 2000B27F */  sq         $18, 0x20($29)
    /* ED07C 001ED07C 1000B17F */  sq         $17, 0x10($29)
    /* ED080 001ED080 0000B07F */  sq         $16, 0x0($29)
    /* ED084 001ED084 2DA08000 */  daddu      $20, $4, $0
    /* ED088 001ED088 2D98A000 */  daddu      $19, $5, $0
    /* ED08C 001ED08C 1000A28C */  lw         $2, 0x10($5)
    /* ED090 001ED090 04005414 */  bne        $2, $20, .L001ED0A4
    /* ED094 001ED094 00000000 */   nop
    /* ED098 001ED098 01000224 */  addiu      $2, $0, 0x1
    /* ED09C 001ED09C 97000010 */  b          .L001ED2FC
    /* ED0A0 001ED0A0 00000000 */   nop
  .L001ED0A4:
    /* ED0A4 001ED0A4 ACB3828F */  lw         $2, -0x4C54($28)
    /* ED0A8 001ED0A8 1803528C */  lw         $18, 0x318($2)
    /* ED0AC 001ED0AC 47000010 */  b          .L001ED1CC
    /* ED0B0 001ED0B0 00000000 */   nop
  .L001ED0B4:
    /* ED0B4 001ED0B4 2D880000 */  daddu      $17, $0, $0
    /* ED0B8 001ED0B8 40000010 */  b          .L001ED1BC
    /* ED0BC 001ED0BC 00000000 */   nop
  .L001ED0C0:
    /* ED0C0 001ED0C0 01002226 */  addiu      $2, $17, 0x1
    /* ED0C4 001ED0C4 03004330 */  andi       $3, $2, 0x3
    /* ED0C8 001ED0C8 C0101100 */  sll        $2, $17, 3
    /* ED0CC 001ED0CC 21105100 */  addu       $2, $2, $17
    /* ED0D0 001ED0D0 40100200 */  sll        $2, $2, 1
    /* ED0D4 001ED0D4 21105100 */  addu       $2, $2, $17
    /* ED0D8 001ED0D8 00110200 */  sll        $2, $2, 4
    /* ED0DC 001ED0DC 21104202 */  addu       $2, $18, $2
    /* ED0E0 001ED0E0 08005024 */  addiu      $16, $2, 0x8
    /* ED0E4 001ED0E4 34001412 */  beq        $16, $20, .L001ED1B8
    /* ED0E8 001ED0E8 00000000 */   nop
    /* ED0EC 001ED0EC 32001312 */  beq        $16, $19, .L001ED1B8
    /* ED0F0 001ED0F0 00000000 */   nop
    /* ED0F4 001ED0F4 C0100300 */  sll        $2, $3, 3
    /* ED0F8 001ED0F8 21104300 */  addu       $2, $2, $3
    /* ED0FC 001ED0FC 40100200 */  sll        $2, $2, 1
    /* ED100 001ED100 21104300 */  addu       $2, $2, $3
    /* ED104 001ED104 00110200 */  sll        $2, $2, 4
    /* ED108 001ED108 21104202 */  addu       $2, $18, $2
    /* ED10C 001ED10C 08005524 */  addiu      $21, $2, 0x8
    /* ED110 001ED110 2900B412 */  beq        $21, $20, .L001ED1B8
    /* ED114 001ED114 00000000 */   nop
    /* ED118 001ED118 2700B312 */  beq        $21, $19, .L001ED1B8
    /* ED11C 001ED11C 00000000 */   nop
    /* ED120 001ED120 2D200002 */  daddu      $4, $16, $0
    /* ED124 001ED124 2D28A002 */  daddu      $5, $21, $0
    /* ED128 001ED128 2D308002 */  daddu      $6, $20, $0
    /* ED12C 001ED12C CCB4070C */  jal        func_001ed330
    /* ED130 001ED130 00000000 */   nop
    /* ED134 001ED134 2DB04000 */  daddu      $22, $2, $0
    /* ED138 001ED138 2D200002 */  daddu      $4, $16, $0
    /* ED13C 001ED13C 2D28A002 */  daddu      $5, $21, $0
    /* ED140 001ED140 2D306002 */  daddu      $6, $19, $0
    /* ED144 001ED144 CCB4070C */  jal        func_001ed330
    /* ED148 001ED148 00000000 */   nop
    /* ED14C 001ED14C 1400C212 */  beq        $22, $2, .L001ED1A0
    /* ED150 001ED150 00000000 */   nop
    /* ED154 001ED154 2D208002 */  daddu      $4, $20, $0
    /* ED158 001ED158 2D286002 */  daddu      $5, $19, $0
    /* ED15C 001ED15C 2D300002 */  daddu      $6, $16, $0
    /* ED160 001ED160 CCB4070C */  jal        func_001ed330
    /* ED164 001ED164 00000000 */   nop
    /* ED168 001ED168 2D804000 */  daddu      $16, $2, $0
    /* ED16C 001ED16C 2D208002 */  daddu      $4, $20, $0
    /* ED170 001ED170 2D286002 */  daddu      $5, $19, $0
    /* ED174 001ED174 2D30A002 */  daddu      $6, $21, $0
    /* ED178 001ED178 CCB4070C */  jal        func_001ed330
    /* ED17C 001ED17C 00000000 */   nop
    /* ED180 001ED180 04000212 */  beq        $16, $2, .L001ED194
    /* ED184 001ED184 00000000 */   nop
    /* ED188 001ED188 01000224 */  addiu      $2, $0, 0x1
    /* ED18C 001ED18C 05000010 */  b          .L001ED1A4
    /* ED190 001ED190 00000000 */   nop
  .L001ED194:
    /* ED194 001ED194 2D100000 */  daddu      $2, $0, $0
    /* ED198 001ED198 02000010 */  b          .L001ED1A4
    /* ED19C 001ED19C 00000000 */   nop
  .L001ED1A0:
    /* ED1A0 001ED1A0 2D100000 */  daddu      $2, $0, $0
  .L001ED1A4:
    /* ED1A4 001ED1A4 04004010 */  beqz       $2, .L001ED1B8
    /* ED1A8 001ED1A8 00000000 */   nop
    /* ED1AC 001ED1AC 01000224 */  addiu      $2, $0, 0x1
    /* ED1B0 001ED1B0 52000010 */  b          .L001ED2FC
    /* ED1B4 001ED1B4 00000000 */   nop
  .L001ED1B8:
    /* ED1B8 001ED1B8 01003126 */  addiu      $17, $17, 0x1
  .L001ED1BC:
    /* ED1BC 001ED1BC 0400222A */  slti       $2, $17, 0x4
    /* ED1C0 001ED1C0 BFFF4014 */  bnez       $2, .L001ED0C0
    /* ED1C4 001ED1C4 00000000 */   nop
    /* ED1C8 001ED1C8 CC04528E */  lw         $18, 0x4CC($18)
  .L001ED1CC:
    /* ED1CC 001ED1CC B9FF4016 */  bnez       $18, .L001ED0B4
    /* ED1D0 001ED1D0 00000000 */   nop
    /* ED1D4 001ED1D4 ACB3828F */  lw         $2, -0x4C54($28)
    /* ED1D8 001ED1D8 1803518C */  lw         $17, 0x318($2)
    /* ED1DC 001ED1DC 44000010 */  b          .L001ED2F0
    /* ED1E0 001ED1E0 00000000 */   nop
  .L001ED1E4:
    /* ED1E4 001ED1E4 2D800000 */  daddu      $16, $0, $0
    /* ED1E8 001ED1E8 3D000010 */  b          .L001ED2E0
    /* ED1EC 001ED1EC 00000000 */   nop
  .L001ED1F0:
    /* ED1F0 001ED1F0 C0101000 */  sll        $2, $16, 3
    /* ED1F4 001ED1F4 21105000 */  addu       $2, $2, $16
    /* ED1F8 001ED1F8 40100200 */  sll        $2, $2, 1
    /* ED1FC 001ED1FC 21105000 */  addu       $2, $2, $16
    /* ED200 001ED200 00110200 */  sll        $2, $2, 4
    /* ED204 001ED204 21102202 */  addu       $2, $17, $2
    /* ED208 001ED208 08005224 */  addiu      $18, $2, 0x8
    /* ED20C 001ED20C 04005416 */  bne        $18, $20, .L001ED220
    /* ED210 001ED210 00000000 */   nop
    /* ED214 001ED214 2D100000 */  daddu      $2, $0, $0
    /* ED218 001ED218 38000010 */  b          .L001ED2FC
    /* ED21C 001ED21C 00000000 */   nop
  .L001ED220:
    /* ED220 001ED220 1C0041C4 */  lwc1       $f1, 0x1C($2)
    /* ED224 001ED224 00008044 */  mtc1       $0, $f0
    /* ED228 001ED228 00000000 */  nop
    /* ED22C 001ED22C 36080046 */  c.le.s     $f1, $f0
    /* ED230 001ED230 2A000145 */  bc1t       .L001ED2DC
    /* ED234 001ED234 00000000 */   nop
    /* ED238 001ED238 1800558C */  lw         $21, 0x18($2)
    /* ED23C 001ED23C 2700A012 */  beqz       $21, .L001ED2DC
    /* ED240 001ED240 00000000 */   nop
    /* ED244 001ED244 2D204002 */  daddu      $4, $18, $0
    /* ED248 001ED248 2D28A002 */  daddu      $5, $21, $0
    /* ED24C 001ED24C 2D308002 */  daddu      $6, $20, $0
    /* ED250 001ED250 CCB4070C */  jal        func_001ed330
    /* ED254 001ED254 00000000 */   nop
    /* ED258 001ED258 2DB04000 */  daddu      $22, $2, $0
    /* ED25C 001ED25C 2D204002 */  daddu      $4, $18, $0
    /* ED260 001ED260 2D28A002 */  daddu      $5, $21, $0
    /* ED264 001ED264 2D306002 */  daddu      $6, $19, $0
    /* ED268 001ED268 CCB4070C */  jal        func_001ed330
    /* ED26C 001ED26C 00000000 */   nop
    /* ED270 001ED270 1400C212 */  beq        $22, $2, .L001ED2C4
    /* ED274 001ED274 00000000 */   nop
    /* ED278 001ED278 2D208002 */  daddu      $4, $20, $0
    /* ED27C 001ED27C 2D286002 */  daddu      $5, $19, $0
    /* ED280 001ED280 2D304002 */  daddu      $6, $18, $0
    /* ED284 001ED284 CCB4070C */  jal        func_001ed330
    /* ED288 001ED288 00000000 */   nop
    /* ED28C 001ED28C 2D904000 */  daddu      $18, $2, $0
    /* ED290 001ED290 2D208002 */  daddu      $4, $20, $0
    /* ED294 001ED294 2D286002 */  daddu      $5, $19, $0
    /* ED298 001ED298 2D30A002 */  daddu      $6, $21, $0
    /* ED29C 001ED29C CCB4070C */  jal        func_001ed330
    /* ED2A0 001ED2A0 00000000 */   nop
    /* ED2A4 001ED2A4 04004212 */  beq        $18, $2, .L001ED2B8
    /* ED2A8 001ED2A8 00000000 */   nop
    /* ED2AC 001ED2AC 01000224 */  addiu      $2, $0, 0x1
    /* ED2B0 001ED2B0 05000010 */  b          .L001ED2C8
    /* ED2B4 001ED2B4 00000000 */   nop
  .L001ED2B8:
    /* ED2B8 001ED2B8 2D100000 */  daddu      $2, $0, $0
    /* ED2BC 001ED2BC 02000010 */  b          .L001ED2C8
    /* ED2C0 001ED2C0 00000000 */   nop
  .L001ED2C4:
    /* ED2C4 001ED2C4 2D100000 */  daddu      $2, $0, $0
  .L001ED2C8:
    /* ED2C8 001ED2C8 04004010 */  beqz       $2, .L001ED2DC
    /* ED2CC 001ED2CC 00000000 */   nop
    /* ED2D0 001ED2D0 01000224 */  addiu      $2, $0, 0x1
    /* ED2D4 001ED2D4 09000010 */  b          .L001ED2FC
    /* ED2D8 001ED2D8 00000000 */   nop
  .L001ED2DC:
    /* ED2DC 001ED2DC 01001026 */  addiu      $16, $16, 0x1
  .L001ED2E0:
    /* ED2E0 001ED2E0 0400022A */  slti       $2, $16, 0x4
    /* ED2E4 001ED2E4 C2FF4014 */  bnez       $2, .L001ED1F0
    /* ED2E8 001ED2E8 00000000 */   nop
    /* ED2EC 001ED2EC CC04318E */  lw         $17, 0x4CC($17)
  .L001ED2F0:
    /* ED2F0 001ED2F0 BCFF2016 */  bnez       $17, .L001ED1E4
    /* ED2F4 001ED2F4 00000000 */   nop
    /* ED2F8 001ED2F8 2D100000 */  daddu      $2, $0, $0
  .L001ED2FC:
    /* ED2FC 001ED2FC 7000BFDF */  ld         $31, 0x70($29)
    /* ED300 001ED300 6000B67B */  lq         $22, 0x60($29)
    /* ED304 001ED304 5000B57B */  lq         $21, 0x50($29)
    /* ED308 001ED308 4000B47B */  lq         $20, 0x40($29)
    /* ED30C 001ED30C 3000B37B */  lq         $19, 0x30($29)
    /* ED310 001ED310 2000B27B */  lq         $18, 0x20($29)
    /* ED314 001ED314 1000B17B */  lq         $17, 0x10($29)
    /* ED318 001ED318 0000B07B */  lq         $16, 0x0($29)
    /* ED31C 001ED31C 8000BD27 */  addiu      $29, $29, 0x80
    /* ED320 001ED320 0800E003 */  jr         $31
    /* ED324 001ED324 00000000 */   nop
    /* ED328 001ED328 00000000 */  nop
    /* ED32C 001ED32C 00000000 */  nop
.size func_001ed060, 0x2d0
