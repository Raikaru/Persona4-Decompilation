.section .text
.set noat
.set noreorder
glabel func_003ed0b0
    /* 2ED0B0 003ED0B0 00FFBD27 */  addiu      $29, $29, -0x100
    /* 2ED0B4 003ED0B4 0000A68C */  lw         $6, 0x0($5)
    /* 2ED0B8 003ED0B8 9000BFFF */  sd         $31, 0x90($29)
    /* 2ED0BC 003ED0BC 0400A3C4 */  lwc1       $f3, 0x4($5)
    /* 2ED0C0 003ED0C0 8000BE7F */  sq         $30, 0x80($29)
    /* 2ED0C4 003ED0C4 0800A0C4 */  lwc1       $f0, 0x8($5)
    /* 2ED0C8 003ED0C8 7000B77F */  sq         $23, 0x70($29)
    /* 2ED0CC 003ED0CC 2D108000 */  daddu      $2, $4, $0
    /* 2ED0D0 003ED0D0 6000B67F */  sq         $22, 0x60($29)
    /* 2ED0D4 003ED0D4 2DF00000 */  daddu      $30, $0, $0
    /* 2ED0D8 003ED0D8 5000B57F */  sq         $21, 0x50($29)
    /* 2ED0DC 003ED0DC 4000B47F */  sq         $20, 0x40($29)
    /* 2ED0E0 003ED0E0 3000B37F */  sq         $19, 0x30($29)
    /* 2ED0E4 003ED0E4 E0188046 */  cvt.s.w    $f3, $f3
    /* 2ED0E8 003ED0E8 2000B27F */  sq         $18, 0x20($29)
    /* 2ED0EC 003ED0EC 1000B17F */  sq         $17, 0x10($29)
    /* 2ED0F0 003ED0F0 0000B07F */  sq         $16, 0x0($29)
    /* 2ED0F4 003ED0F4 0400928C */  lw         $18, 0x4($4)
    /* 2ED0F8 003ED0F8 0800838C */  lw         $3, 0x8($4)
    /* 2ED0FC 003ED0FC EC00A5AF */  sw         $5, 0xEC($29)
    /* 2ED100 003ED100 0000858C */  lw         $5, 0x0($4)
    /* 2ED104 003ED104 00089244 */  mtc1       $18, $f1
    /* 2ED108 003ED108 B000A37F */  sq         $3, 0xB0($29)
    /* 2ED10C 003ED10C 60088046 */  cvt.s.w    $f1, $f1
    /* 2ED110 003ED110 8047033C */  lui        $3, (0x47800000 >> 16)
    /* 2ED114 003ED114 43180146 */  div.s      $f1, $f3, $f1
    /* 2ED118 003ED118 00108344 */  mtc1       $3, $f2
    /* 2ED11C 003ED11C 00000000 */  nop
    /* 2ED120 003ED120 42100146 */  mul.s      $f1, $f2, $f1
    /* 2ED124 003ED124 0200C330 */  andi       $3, $6, 0x2
    /* 2ED128 003ED128 2518A300 */  or         $3, $5, $3
    /* 2ED12C 003ED12C 000083AC */  sw         $3, 0x0($4)
    /* 2ED130 003ED130 B000A37B */  lq         $3, 0xB0($29)
    /* 2ED134 003ED134 64080046 */  .word      0x46000864                    # cvt.w.s    $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 2ED138 003ED138 00081144 */  mfc1       $17, $f1
    /* 2ED13C 003ED13C 60008046 */  cvt.s.w    $f1, $f0
    /* 2ED140 003ED140 00008344 */  mtc1       $3, $f0
    /* 2ED144 003ED144 00000000 */  nop
    /* 2ED148 003ED148 20008046 */  cvt.s.w    $f0, $f0
    /* 2ED14C 003ED14C 03080046 */  div.s      $f0, $f1, $f0
    /* 2ED150 003ED150 02100046 */  mul.s      $f0, $f2, $f0
    /* 2ED154 003ED154 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 2ED158 003ED158 00000344 */  mfc1       $3, $f0
    /* 2ED15C 003ED15C 00000000 */  nop
    /* 2ED160 003ED160 A000A37F */  sq         $3, 0xA0($29)
    /* 2ED164 003ED164 B000A37B */  lq         $3, 0xB0($29)
    /* 2ED168 003ED168 2A080300 */  slt        $1, $0, $3
    /* 2ED16C 003ED16C 14002010 */  beqz       $1, .L003ED1C0
    /* 2ED170 003ED170 D000A0AF */   sw        $0, 0xD0($29)
    /* 2ED174 003ED174 F400B027 */  addiu      $16, $29, 0xF4
    /* 2ED178 003ED178 F800B627 */  addiu      $22, $29, 0xF8
    /* 2ED17C 003ED17C FC00B727 */  addiu      $23, $29, 0xFC
  .L003ED180:
    /* 2ED180 003ED180 1000438C */  lw         $3, 0x10($2)
    /* 2ED184 003ED184 18287E00 */  mult       $5, $3, $30
    /* 2ED188 003ED188 1400448C */  lw         $4, 0x14($2)
    /* 2ED18C 003ED18C 2DA00000 */  daddu      $20, $0, $0
    /* 2ED190 003ED190 2DA80000 */  daddu      $21, $0, $0
    /* 2ED194 003ED194 2A181200 */  slt        $3, $0, $18
    /* 2ED198 003ED198 0B006014 */  bnez       $3, .L003ED1C8
    /* 2ED19C 003ED19C 21988500 */   addu      $19, $4, $5
  .L003ED1A0:
    /* 2ED1A0 003ED1A0 D000A48F */  lw         $4, 0xD0($29)
    /* 2ED1A4 003ED1A4 A000A37B */  lq         $3, 0xA0($29)
    /* 2ED1A8 003ED1A8 0100DE27 */  addiu      $30, $30, 0x1
    /* 2ED1AC 003ED1AC 21208300 */  addu       $4, $4, $3
    /* 2ED1B0 003ED1B0 B000A37B */  lq         $3, 0xB0($29)
    /* 2ED1B4 003ED1B4 2A18C303 */  slt        $3, $30, $3
    /* 2ED1B8 003ED1B8 F1FF6014 */  bnez       $3, .L003ED180
    /* 2ED1BC 003ED1BC D000A4AF */   sw        $4, 0xD0($29)
  .L003ED1C0:
    /* 2ED1C0 003ED1C0 35000010 */  b          .L003ED298
    /* 2ED1C4 003ED1C4 00000000 */   nop
  .L003ED1C8:
    /* 2ED1C8 003ED1C8 D000A48F */  lw         $4, 0xD0($29)
    /* 2ED1CC 003ED1CC A000A37B */  lq         $3, 0xA0($29)
    /* 2ED1D0 003ED1D0 21188300 */  addu       $3, $4, $3
    /* 2ED1D4 003ED1D4 FFFF6324 */  addiu      $3, $3, -0x1
    /* 2ED1D8 003ED1D8 C000A3AF */  sw         $3, 0xC0($29)
    /* 2ED1DC 003ED1DC 00000000 */  nop
  .L003ED1E0:
    /* 2ED1E0 003ED1E0 EC00A48F */  lw         $4, 0xEC($29)
    /* 2ED1E4 003ED1E4 D000A78F */  lw         $7, 0xD0($29)
    /* 2ED1E8 003ED1E8 21189102 */  addu       $3, $20, $17
    /* 2ED1EC 003ED1EC C000A88F */  lw         $8, 0xC0($29)
    /* 2ED1F0 003ED1F0 FFFF6624 */  addiu      $6, $3, -0x1
    /* 2ED1F4 003ED1F4 2D288002 */  daddu      $5, $20, $0
    /* 2ED1F8 003ED1F8 90B30F0C */  jal        func_003ece40
    /* 2ED1FC 003ED1FC F000A927 */   addiu     $9, $29, 0xF0
    /* 2ED200 003ED200 7F43033C */  lui        $3, (0x437F0000 >> 16)
    /* 2ED204 003ED204 0100B526 */  addiu      $21, $21, 0x1
    /* 2ED208 003ED208 00188344 */  mtc1       $3, $f3
    /* 2ED20C 003ED20C 21A09102 */  addu       $20, $20, $17
    /* 2ED210 003ED210 F000A0C7 */  lwc1       $f0, 0xF0($29)
    /* 2ED214 003ED214 003F033C */  lui        $3, (0x3F000000 >> 16)
    /* 2ED218 003ED218 00108344 */  mtc1       $3, $f2
    /* 2ED21C 003ED21C 00088044 */  mtc1       $0, $f1
    /* 2ED220 003ED220 2A18B202 */  slt        $3, $21, $18
    /* 2ED224 003ED224 18080246 */  adda.s     $f1, $f2
    /* 2ED228 003ED228 1C180046 */  madd.s     $f0, $f3, $f0
    /* 2ED22C 003ED22C 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 2ED230 003ED230 00000444 */  mfc1       $4, $f0
    /* 2ED234 003ED234 18080246 */  adda.s     $f1, $f2
    /* 2ED238 003ED238 000064A2 */  sb         $4, 0x0($19)
    /* 2ED23C 003ED23C 000000C6 */  lwc1       $f0, 0x0($16)
    /* 2ED240 003ED240 1C180046 */  madd.s     $f0, $f3, $f0
    /* 2ED244 003ED244 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 2ED248 003ED248 00000444 */  mfc1       $4, $f0
    /* 2ED24C 003ED24C 18080246 */  adda.s     $f1, $f2
    /* 2ED250 003ED250 010064A2 */  sb         $4, 0x1($19)
    /* 2ED254 003ED254 0000C0C6 */  lwc1       $f0, 0x0($22)
    /* 2ED258 003ED258 1C180046 */  madd.s     $f0, $f3, $f0
    /* 2ED25C 003ED25C 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 2ED260 003ED260 00000444 */  mfc1       $4, $f0
    /* 2ED264 003ED264 18080246 */  adda.s     $f1, $f2
    /* 2ED268 003ED268 020064A2 */  sb         $4, 0x2($19)
    /* 2ED26C 003ED26C 0000E0C6 */  lwc1       $f0, 0x0($23)
    /* 2ED270 003ED270 1C180046 */  madd.s     $f0, $f3, $f0
    /* 2ED274 003ED274 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 2ED278 003ED278 00000444 */  mfc1       $4, $f0
    /* 2ED27C 003ED27C 00000000 */  nop
    /* 2ED280 003ED280 030064A2 */  sb         $4, 0x3($19)
    /* 2ED284 003ED284 D6FF6014 */  bnez       $3, .L003ED1E0
    /* 2ED288 003ED288 04007326 */   addiu     $19, $19, 0x4
    /* 2ED28C 003ED28C C4FF0010 */  b          .L003ED1A0
    /* 2ED290 003ED290 00000000 */   nop
    /* 2ED294 003ED294 00000000 */  nop
  .L003ED298:
    /* 2ED298 003ED298 9000BFDF */  ld         $31, 0x90($29)
    /* 2ED29C 003ED29C 8000BE7B */  lq         $30, 0x80($29)
    /* 2ED2A0 003ED2A0 7000B77B */  lq         $23, 0x70($29)
    /* 2ED2A4 003ED2A4 6000B67B */  lq         $22, 0x60($29)
    /* 2ED2A8 003ED2A8 5000B57B */  lq         $21, 0x50($29)
    /* 2ED2AC 003ED2AC 4000B47B */  lq         $20, 0x40($29)
    /* 2ED2B0 003ED2B0 3000B37B */  lq         $19, 0x30($29)
    /* 2ED2B4 003ED2B4 2000B27B */  lq         $18, 0x20($29)
    /* 2ED2B8 003ED2B8 1000B17B */  lq         $17, 0x10($29)
    /* 2ED2BC 003ED2BC 0000B07B */  lq         $16, 0x0($29)
    /* 2ED2C0 003ED2C0 0800E003 */  jr         $31
    /* 2ED2C4 003ED2C4 0001BD27 */   addiu     $29, $29, 0x100
    /* 2ED2C8 003ED2C8 00000000 */  nop
    /* 2ED2CC 003ED2CC 00000000 */  nop
.size func_003ed0b0, 0x220
