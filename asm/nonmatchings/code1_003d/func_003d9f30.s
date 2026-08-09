.section .text
.set noat
.set noreorder
glabel func_003d9f30
    /* 2D9F30 003D9F30 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2D9F34 003D9F34 04008BC4 */  lwc1       $f11, 0x4($4)
    /* 2D9F38 003D9F38 0400A4C4 */  lwc1       $f4, 0x4($5)
    /* 2D9F3C 003D9F3C 0800B6E7 */  swc1       $f22, 0x8($29)
    /* 2D9F40 003D9F40 0400B5E7 */  swc1       $f21, 0x4($29)
    /* 2D9F44 003D9F44 36200B46 */  c.le.s     $f4, $f11
    /* 2D9F48 003D9F48 03000145 */  bc1t       .L003D9F58
    /* 2D9F4C 003D9F4C 0000B4E7 */   swc1      $f20, 0x0($29)
    /* 2D9F50 003D9F50 08000010 */  b          .L003D9F74
    /* 2D9F54 003D9F54 04000824 */   addiu     $8, $0, 0x4
  .L003D9F58:
    /* 2D9F58 003D9F58 100080C4 */  lwc1       $f0, 0x10($4)
    /* 2D9F5C 003D9F5C 34200046 */  c.lt.s     $f4, $f0
    /* 2D9F60 003D9F60 03000045 */  bc1f       .L003D9F70
    /* 2D9F64 003D9F64 00000000 */   nop
    /* 2D9F68 003D9F68 02000010 */  b          .L003D9F74
    /* 2D9F6C 003D9F6C 08000824 */   addiu     $8, $0, 0x8
  .L003D9F70:
    /* 2D9F70 003D9F70 2D400000 */  daddu      $8, $0, $0
  .L003D9F74:
    /* 2D9F74 003D9F74 00008AC4 */  lwc1       $f10, 0x0($4)
    /* 2D9F78 003D9F78 0000A5C4 */  lwc1       $f5, 0x0($5)
    /* 2D9F7C 003D9F7C 36280A46 */  c.le.s     $f5, $f10
    /* 2D9F80 003D9F80 03000145 */  bc1t       .L003D9F90
    /* 2D9F84 003D9F84 00000000 */   nop
    /* 2D9F88 003D9F88 08000010 */  b          .L003D9FAC
    /* 2D9F8C 003D9F8C 01000224 */   addiu     $2, $0, 0x1
  .L003D9F90:
    /* 2D9F90 003D9F90 0C0080C4 */  lwc1       $f0, 0xC($4)
    /* 2D9F94 003D9F94 34280046 */  c.lt.s     $f5, $f0
    /* 2D9F98 003D9F98 03000045 */  bc1f       .L003D9FA8
    /* 2D9F9C 003D9F9C 00000000 */   nop
    /* 2D9FA0 003D9FA0 02000010 */  b          .L003D9FAC
    /* 2D9FA4 003D9FA4 02000224 */   addiu     $2, $0, 0x2
  .L003D9FA8:
    /* 2D9FA8 003D9FA8 2D100000 */  daddu      $2, $0, $0
  .L003D9FAC:
    /* 2D9FAC 003D9FAC 080089C4 */  lwc1       $f9, 0x8($4)
    /* 2D9FB0 003D9FB0 0800A3C4 */  lwc1       $f3, 0x8($5)
    /* 2D9FB4 003D9FB4 36180946 */  c.le.s     $f3, $f9
    /* 2D9FB8 003D9FB8 03000145 */  bc1t       .L003D9FC8
    /* 2D9FBC 003D9FBC 00000000 */   nop
    /* 2D9FC0 003D9FC0 08000010 */  b          .L003D9FE4
    /* 2D9FC4 003D9FC4 10000324 */   addiu     $3, $0, 0x10
  .L003D9FC8:
    /* 2D9FC8 003D9FC8 140080C4 */  lwc1       $f0, 0x14($4)
    /* 2D9FCC 003D9FCC 34180046 */  c.lt.s     $f3, $f0
    /* 2D9FD0 003D9FD0 03000045 */  bc1f       .L003D9FE0
    /* 2D9FD4 003D9FD4 00000000 */   nop
    /* 2D9FD8 003D9FD8 02000010 */  b          .L003D9FE4
    /* 2D9FDC 003D9FDC 20000324 */   addiu     $3, $0, 0x20
  .L003D9FE0:
    /* 2D9FE0 003D9FE0 2D180000 */  daddu      $3, $0, $0
  .L003D9FE4:
    /* 2D9FE4 003D9FE4 25104800 */  or         $2, $2, $8
    /* 2D9FE8 003D9FE8 25186200 */  or         $3, $3, $2
    /* 2D9FEC 003D9FEC 3E016010 */  beqz       $3, .L003DA4E8
    /* 2D9FF0 003D9FF0 00000000 */   nop
    /* 2D9FF4 003D9FF4 0400C1C4 */  lwc1       $f1, 0x4($6)
    /* 2D9FF8 003D9FF8 36080B46 */  c.le.s     $f1, $f11
    /* 2D9FFC 003D9FFC 03000145 */  bc1t       .L003DA00C
    /* 2DA000 003DA000 00000000 */   nop
    /* 2DA004 003DA004 08000010 */  b          .L003DA028
    /* 2DA008 003DA008 04000824 */   addiu     $8, $0, 0x4
  .L003DA00C:
    /* 2DA00C 003DA00C 100080C4 */  lwc1       $f0, 0x10($4)
    /* 2DA010 003DA010 34080046 */  c.lt.s     $f1, $f0
    /* 2DA014 003DA014 03000045 */  bc1f       .L003DA024
    /* 2DA018 003DA018 00000000 */   nop
    /* 2DA01C 003DA01C 02000010 */  b          .L003DA028
    /* 2DA020 003DA020 08000824 */   addiu     $8, $0, 0x8
  .L003DA024:
    /* 2DA024 003DA024 2D400000 */  daddu      $8, $0, $0
  .L003DA028:
    /* 2DA028 003DA028 0000C2C4 */  lwc1       $f2, 0x0($6)
    /* 2DA02C 003DA02C 36100A46 */  c.le.s     $f2, $f10
    /* 2DA030 003DA030 03000145 */  bc1t       .L003DA040
    /* 2DA034 003DA034 00000000 */   nop
    /* 2DA038 003DA038 08000010 */  b          .L003DA05C
    /* 2DA03C 003DA03C 01000224 */   addiu     $2, $0, 0x1
  .L003DA040:
    /* 2DA040 003DA040 0C0080C4 */  lwc1       $f0, 0xC($4)
    /* 2DA044 003DA044 34100046 */  c.lt.s     $f2, $f0
    /* 2DA048 003DA048 03000045 */  bc1f       .L003DA058
    /* 2DA04C 003DA04C 00000000 */   nop
    /* 2DA050 003DA050 02000010 */  b          .L003DA05C
    /* 2DA054 003DA054 02000224 */   addiu     $2, $0, 0x2
  .L003DA058:
    /* 2DA058 003DA058 2D100000 */  daddu      $2, $0, $0
  .L003DA05C:
    /* 2DA05C 003DA05C 0800C0C4 */  lwc1       $f0, 0x8($6)
    /* 2DA060 003DA060 36000946 */  c.le.s     $f0, $f9
    /* 2DA064 003DA064 03000145 */  bc1t       .L003DA074
    /* 2DA068 003DA068 00000000 */   nop
    /* 2DA06C 003DA06C 08000010 */  b          .L003DA090
    /* 2DA070 003DA070 10000624 */   addiu     $6, $0, 0x10
  .L003DA074:
    /* 2DA074 003DA074 140086C4 */  lwc1       $f6, 0x14($4)
    /* 2DA078 003DA078 34000646 */  c.lt.s     $f0, $f6
    /* 2DA07C 003DA07C 03000045 */  bc1f       .L003DA08C
    /* 2DA080 003DA080 00000000 */   nop
    /* 2DA084 003DA084 02000010 */  b          .L003DA090
    /* 2DA088 003DA088 20000624 */   addiu     $6, $0, 0x20
  .L003DA08C:
    /* 2DA08C 003DA08C 2D300000 */  daddu      $6, $0, $0
  .L003DA090:
    /* 2DA090 003DA090 25104800 */  or         $2, $2, $8
    /* 2DA094 003DA094 2510C200 */  or         $2, $6, $2
    /* 2DA098 003DA098 15014010 */  beqz       $2, .L003DA4F0
    /* 2DA09C 003DA09C 00000000 */   nop
    /* 2DA0A0 003DA0A0 0400E8C4 */  lwc1       $f8, 0x4($7)
    /* 2DA0A4 003DA0A4 36400B46 */  c.le.s     $f8, $f11
    /* 2DA0A8 003DA0A8 03000145 */  bc1t       .L003DA0B8
    /* 2DA0AC 003DA0AC 00000000 */   nop
    /* 2DA0B0 003DA0B0 08000010 */  b          .L003DA0D4
    /* 2DA0B4 003DA0B4 04000824 */   addiu     $8, $0, 0x4
  .L003DA0B8:
    /* 2DA0B8 003DA0B8 100086C4 */  lwc1       $f6, 0x10($4)
    /* 2DA0BC 003DA0BC 34400646 */  c.lt.s     $f8, $f6
    /* 2DA0C0 003DA0C0 03000045 */  bc1f       .L003DA0D0
    /* 2DA0C4 003DA0C4 00000000 */   nop
    /* 2DA0C8 003DA0C8 02000010 */  b          .L003DA0D4
    /* 2DA0CC 003DA0CC 08000824 */   addiu     $8, $0, 0x8
  .L003DA0D0:
    /* 2DA0D0 003DA0D0 2D400000 */  daddu      $8, $0, $0
  .L003DA0D4:
    /* 2DA0D4 003DA0D4 0000E7C4 */  lwc1       $f7, 0x0($7)
    /* 2DA0D8 003DA0D8 36380A46 */  c.le.s     $f7, $f10
    /* 2DA0DC 003DA0DC 03000145 */  bc1t       .L003DA0EC
    /* 2DA0E0 003DA0E0 00000000 */   nop
    /* 2DA0E4 003DA0E4 08000010 */  b          .L003DA108
    /* 2DA0E8 003DA0E8 01000624 */   addiu     $6, $0, 0x1
  .L003DA0EC:
    /* 2DA0EC 003DA0EC 0C0086C4 */  lwc1       $f6, 0xC($4)
    /* 2DA0F0 003DA0F0 34380646 */  c.lt.s     $f7, $f6
    /* 2DA0F4 003DA0F4 03000045 */  bc1f       .L003DA104
    /* 2DA0F8 003DA0F8 00000000 */   nop
    /* 2DA0FC 003DA0FC 02000010 */  b          .L003DA108
    /* 2DA100 003DA100 02000624 */   addiu     $6, $0, 0x2
  .L003DA104:
    /* 2DA104 003DA104 2D300000 */  daddu      $6, $0, $0
  .L003DA108:
    /* 2DA108 003DA108 0800E6C4 */  lwc1       $f6, 0x8($7)
    /* 2DA10C 003DA10C 36300946 */  c.le.s     $f6, $f9
    /* 2DA110 003DA110 03000145 */  bc1t       .L003DA120
    /* 2DA114 003DA114 00000000 */   nop
    /* 2DA118 003DA118 08000010 */  b          .L003DA13C
    /* 2DA11C 003DA11C 10000724 */   addiu     $7, $0, 0x10
  .L003DA120:
    /* 2DA120 003DA120 14008CC4 */  lwc1       $f12, 0x14($4)
    /* 2DA124 003DA124 34300C46 */  c.lt.s     $f6, $f12
    /* 2DA128 003DA128 03000045 */  bc1f       .L003DA138
    /* 2DA12C 003DA12C 00000000 */   nop
    /* 2DA130 003DA130 02000010 */  b          .L003DA13C
    /* 2DA134 003DA134 20000724 */   addiu     $7, $0, 0x20
  .L003DA138:
    /* 2DA138 003DA138 2D380000 */  daddu      $7, $0, $0
  .L003DA13C:
    /* 2DA13C 003DA13C 2530C800 */  or         $6, $6, $8
    /* 2DA140 003DA140 2540E600 */  or         $8, $7, $6
    /* 2DA144 003DA144 EC000011 */  beqz       $8, .L003DA4F8
    /* 2DA148 003DA148 00000000 */   nop
    /* 2DA14C 003DA14C 24386200 */  and        $7, $3, $2
    /* 2DA150 003DA150 24300701 */  and        $6, $8, $7
    /* 2DA154 003DA154 EA00C014 */  bnez       $6, .L003DA500
    /* 2DA158 003DA158 00000000 */   nop
    /* 2DA15C 003DA15C 4A00E014 */  bnez       $7, .L003DA288
    /* 2DA160 003DA160 00000000 */   nop
    /* 2DA164 003DA164 10008EC4 */  lwc1       $f14, 0x10($4)
    /* 2DA168 003DA168 26386200 */  xor        $7, $3, $2
    /* 2DA16C 003DA16C 14008DC4 */  lwc1       $f13, 0x14($4)
    /* 2DA170 003DA170 0100E630 */  andi       $6, $7, 0x1
    /* 2DA174 003DA174 0C008FC4 */  lwc1       $f15, 0xC($4)
    /* 2DA178 003DA178 81140546 */  sub.s      $f18, $f2, $f5
    /* 2DA17C 003DA17C 01240E46 */  sub.s      $f16, $f4, $f14
    /* 2DA180 003DA180 411C0D46 */  sub.s      $f17, $f3, $f13
    /* 2DA184 003DA184 C10C0446 */  sub.s      $f19, $f1, $f4
    /* 2DA188 003DA188 01050346 */  sub.s      $f20, $f0, $f3
    /* 2DA18C 003DA18C 012B0A46 */  sub.s      $f12, $f5, $f10
    /* 2DA190 003DA190 C12B0F46 */  sub.s      $f15, $f5, $f15
    /* 2DA194 003DA194 41230B46 */  sub.s      $f13, $f4, $f11
    /* 2DA198 003DA198 DB00C014 */  bnez       $6, .L003DA508
    /* 2DA19C 003DA19C 811B0946 */   sub.s     $f14, $f3, $f9
  .L003DA1A0:
    /* 2DA1A0 003DA1A0 0200E630 */  andi       $6, $7, 0x2
    /* 2DA1A4 003DA1A4 0301C014 */  bnez       $6, .L003DA5B4
    /* 2DA1A8 003DA1A8 00000000 */   nop
  .L003DA1AC:
    /* 2DA1AC 003DA1AC 0400E630 */  andi       $6, $7, 0x4
    /* 2DA1B0 003DA1B0 2B01C014 */  bnez       $6, .L003DA660
    /* 2DA1B4 003DA1B4 00000000 */   nop
  .L003DA1B8:
    /* 2DA1B8 003DA1B8 0800E630 */  andi       $6, $7, 0x8
    /* 2DA1BC 003DA1BC 5301C014 */  bnez       $6, .L003DA70C
    /* 2DA1C0 003DA1C0 00000000 */   nop
  .L003DA1C4:
    /* 2DA1C4 003DA1C4 1000E630 */  andi       $6, $7, 0x10
    /* 2DA1C8 003DA1C8 7B01C014 */  bnez       $6, .L003DA7B8
    /* 2DA1CC 003DA1CC 00000000 */   nop
  .L003DA1D0:
    /* 2DA1D0 003DA1D0 2000E630 */  andi       $6, $7, 0x20
    /* 2DA1D4 003DA1D4 2C00C010 */  beqz       $6, .L003DA288
    /* 2DA1D8 003DA1D8 00000000 */   nop
    /* 2DA1DC 003DA1DC 00708044 */  mtc1       $0, $f14
    /* 2DA1E0 003DA1E0 00000000 */  nop
    /* 2DA1E4 003DA1E4 34A00E46 */  c.lt.s     $f20, $f14
    /* 2DA1E8 003DA1E8 14000045 */  bc1f       .L003DA23C
    /* 2DA1EC 003DA1EC 828C1246 */   mul.s     $f18, $f17, $f18
    /* 2DA1F0 003DA1F0 02631446 */  mul.s      $f12, $f12, $f20
    /* 2DA1F4 003DA1F4 34900C46 */  c.lt.s     $f18, $f12
    /* 2DA1F8 003DA1F8 23000045 */  bc1f       .L003DA288
    /* 2DA1FC 003DA1FC 00000000 */   nop
    /* 2DA200 003DA200 027B1446 */  mul.s      $f12, $f15, $f20
    /* 2DA204 003DA204 36900C46 */  c.le.s     $f18, $f12
    /* 2DA208 003DA208 1F000145 */  bc1t       .L003DA288
    /* 2DA20C 003DA20C 00000000 */   nop
    /* 2DA210 003DA210 828B1346 */  mul.s      $f14, $f17, $f19
    /* 2DA214 003DA214 026B1446 */  mul.s      $f12, $f13, $f20
    /* 2DA218 003DA218 34700C46 */  c.lt.s     $f14, $f12
    /* 2DA21C 003DA21C 1A000045 */  bc1f       .L003DA288
    /* 2DA220 003DA220 00000000 */   nop
    /* 2DA224 003DA224 02831446 */  mul.s      $f12, $f16, $f20
    /* 2DA228 003DA228 36700C46 */  c.le.s     $f14, $f12
    /* 2DA22C 003DA22C 16000145 */  bc1t       .L003DA288
    /* 2DA230 003DA230 00000000 */   nop
    /* 2DA234 003DA234 CE030010 */  b          .L003DB170
    /* 2DA238 003DA238 01000224 */   addiu     $2, $0, 0x1
  .L003DA23C:
    /* 2DA23C 003DA23C 02631446 */  mul.s      $f12, $f12, $f20
    /* 2DA240 003DA240 36900C46 */  c.le.s     $f18, $f12
    /* 2DA244 003DA244 10000145 */  bc1t       .L003DA288
    /* 2DA248 003DA248 00000000 */   nop
    /* 2DA24C 003DA24C 027B1446 */  mul.s      $f12, $f15, $f20
    /* 2DA250 003DA250 34900C46 */  c.lt.s     $f18, $f12
    /* 2DA254 003DA254 0C000045 */  bc1f       .L003DA288
    /* 2DA258 003DA258 00000000 */   nop
    /* 2DA25C 003DA25C 828B1346 */  mul.s      $f14, $f17, $f19
    /* 2DA260 003DA260 026B1446 */  mul.s      $f12, $f13, $f20
    /* 2DA264 003DA264 36700C46 */  c.le.s     $f14, $f12
    /* 2DA268 003DA268 07000145 */  bc1t       .L003DA288
    /* 2DA26C 003DA26C 00000000 */   nop
    /* 2DA270 003DA270 02831446 */  mul.s      $f12, $f16, $f20
    /* 2DA274 003DA274 34700C46 */  c.lt.s     $f14, $f12
    /* 2DA278 003DA278 03000045 */  bc1f       .L003DA288
    /* 2DA27C 003DA27C 00000000 */   nop
    /* 2DA280 003DA280 BB030010 */  b          .L003DB170
    /* 2DA284 003DA284 01000224 */   addiu     $2, $0, 0x1
  .L003DA288:
    /* 2DA288 003DA288 24306800 */  and        $6, $3, $8
    /* 2DA28C 003DA28C 4A00C014 */  bnez       $6, .L003DA3B8
    /* 2DA290 003DA290 00000000 */   nop
    /* 2DA294 003DA294 10008EC4 */  lwc1       $f14, 0x10($4)
    /* 2DA298 003DA298 26306800 */  xor        $6, $3, $8
    /* 2DA29C 003DA29C 14008DC4 */  lwc1       $f13, 0x14($4)
    /* 2DA2A0 003DA2A0 0100C330 */  andi       $3, $6, 0x1
    /* 2DA2A4 003DA2A4 0C008FC4 */  lwc1       $f15, 0xC($4)
    /* 2DA2A8 003DA2A8 813C0546 */  sub.s      $f18, $f7, $f5
    /* 2DA2AC 003DA2AC 01240E46 */  sub.s      $f16, $f4, $f14
    /* 2DA2B0 003DA2B0 411C0D46 */  sub.s      $f17, $f3, $f13
    /* 2DA2B4 003DA2B4 C1440446 */  sub.s      $f19, $f8, $f4
    /* 2DA2B8 003DA2B8 01350346 */  sub.s      $f20, $f6, $f3
    /* 2DA2BC 003DA2BC 012B0A46 */  sub.s      $f12, $f5, $f10
    /* 2DA2C0 003DA2C0 C12B0F46 */  sub.s      $f15, $f5, $f15
    /* 2DA2C4 003DA2C4 41230B46 */  sub.s      $f13, $f4, $f11
    /* 2DA2C8 003DA2C8 66016014 */  bnez       $3, .L003DA864
    /* 2DA2CC 003DA2CC 811B0946 */   sub.s     $f14, $f3, $f9
  .L003DA2D0:
    /* 2DA2D0 003DA2D0 0200C330 */  andi       $3, $6, 0x2
    /* 2DA2D4 003DA2D4 8E016014 */  bnez       $3, .L003DA910
    /* 2DA2D8 003DA2D8 00000000 */   nop
  .L003DA2DC:
    /* 2DA2DC 003DA2DC 0400C330 */  andi       $3, $6, 0x4
    /* 2DA2E0 003DA2E0 B6016014 */  bnez       $3, .L003DA9BC
    /* 2DA2E4 003DA2E4 00000000 */   nop
  .L003DA2E8:
    /* 2DA2E8 003DA2E8 0800C330 */  andi       $3, $6, 0x8
    /* 2DA2EC 003DA2EC DE016014 */  bnez       $3, .L003DAA68
    /* 2DA2F0 003DA2F0 00000000 */   nop
  .L003DA2F4:
    /* 2DA2F4 003DA2F4 1000C330 */  andi       $3, $6, 0x10
    /* 2DA2F8 003DA2F8 06026014 */  bnez       $3, .L003DAB14
    /* 2DA2FC 003DA2FC 00000000 */   nop
  .L003DA300:
    /* 2DA300 003DA300 2000C330 */  andi       $3, $6, 0x20
    /* 2DA304 003DA304 2C006010 */  beqz       $3, .L003DA3B8
    /* 2DA308 003DA308 00000000 */   nop
    /* 2DA30C 003DA30C 00708044 */  mtc1       $0, $f14
    /* 2DA310 003DA310 00000000 */  nop
    /* 2DA314 003DA314 34A00E46 */  c.lt.s     $f20, $f14
    /* 2DA318 003DA318 14000045 */  bc1f       .L003DA36C
    /* 2DA31C 003DA31C 828C1246 */   mul.s     $f18, $f17, $f18
    /* 2DA320 003DA320 02631446 */  mul.s      $f12, $f12, $f20
    /* 2DA324 003DA324 34900C46 */  c.lt.s     $f18, $f12
    /* 2DA328 003DA328 23000045 */  bc1f       .L003DA3B8
    /* 2DA32C 003DA32C 00000000 */   nop
    /* 2DA330 003DA330 027B1446 */  mul.s      $f12, $f15, $f20
    /* 2DA334 003DA334 36900C46 */  c.le.s     $f18, $f12
    /* 2DA338 003DA338 1F000145 */  bc1t       .L003DA3B8
    /* 2DA33C 003DA33C 00000000 */   nop
    /* 2DA340 003DA340 828B1346 */  mul.s      $f14, $f17, $f19
    /* 2DA344 003DA344 026B1446 */  mul.s      $f12, $f13, $f20
    /* 2DA348 003DA348 34700C46 */  c.lt.s     $f14, $f12
    /* 2DA34C 003DA34C 1A000045 */  bc1f       .L003DA3B8
    /* 2DA350 003DA350 00000000 */   nop
    /* 2DA354 003DA354 02831446 */  mul.s      $f12, $f16, $f20
    /* 2DA358 003DA358 36700C46 */  c.le.s     $f14, $f12
    /* 2DA35C 003DA35C 16000145 */  bc1t       .L003DA3B8
    /* 2DA360 003DA360 00000000 */   nop
    /* 2DA364 003DA364 82030010 */  b          .L003DB170
    /* 2DA368 003DA368 01000224 */   addiu     $2, $0, 0x1
  .L003DA36C:
    /* 2DA36C 003DA36C 02631446 */  mul.s      $f12, $f12, $f20
    /* 2DA370 003DA370 36900C46 */  c.le.s     $f18, $f12
    /* 2DA374 003DA374 10000145 */  bc1t       .L003DA3B8
    /* 2DA378 003DA378 00000000 */   nop
    /* 2DA37C 003DA37C 027B1446 */  mul.s      $f12, $f15, $f20
    /* 2DA380 003DA380 34900C46 */  c.lt.s     $f18, $f12
    /* 2DA384 003DA384 0C000045 */  bc1f       .L003DA3B8
    /* 2DA388 003DA388 00000000 */   nop
    /* 2DA38C 003DA38C 828B1346 */  mul.s      $f14, $f17, $f19
    /* 2DA390 003DA390 026B1446 */  mul.s      $f12, $f13, $f20
    /* 2DA394 003DA394 36700C46 */  c.le.s     $f14, $f12
    /* 2DA398 003DA398 07000145 */  bc1t       .L003DA3B8
    /* 2DA39C 003DA39C 00000000 */   nop
    /* 2DA3A0 003DA3A0 02831446 */  mul.s      $f12, $f16, $f20
    /* 2DA3A4 003DA3A4 34700C46 */  c.lt.s     $f14, $f12
    /* 2DA3A8 003DA3A8 03000045 */  bc1f       .L003DA3B8
    /* 2DA3AC 003DA3AC 00000000 */   nop
    /* 2DA3B0 003DA3B0 6F030010 */  b          .L003DB170
    /* 2DA3B4 003DA3B4 01000224 */   addiu     $2, $0, 0x1
  .L003DA3B8:
    /* 2DA3B8 003DA3B8 24184800 */  and        $3, $2, $8
    /* 2DA3BC 003DA3BC D7026014 */  bnez       $3, .L003DAF1C
    /* 2DA3C0 003DA3C0 00000000 */   nop
    /* 2DA3C4 003DA3C4 0C008CC4 */  lwc1       $f12, 0xC($4)
    /* 2DA3C8 003DA3C8 26184800 */  xor        $3, $2, $8
    /* 2DA3CC 003DA3CC 10008DC4 */  lwc1       $f13, 0x10($4)
    /* 2DA3D0 003DA3D0 01006230 */  andi       $2, $3, 0x1
    /* 2DA3D4 003DA3D4 14008EC4 */  lwc1       $f14, 0x14($4)
    /* 2DA3D8 003DA3D8 81120A46 */  sub.s      $f10, $f2, $f10
    /* 2DA3DC 003DA3DC C10A0B46 */  sub.s      $f11, $f1, $f11
    /* 2DA3E0 003DA3E0 41020946 */  sub.s      $f9, $f0, $f9
    /* 2DA3E4 003DA3E4 C13B0246 */  sub.s      $f15, $f7, $f2
    /* 2DA3E8 003DA3E8 01440146 */  sub.s      $f16, $f8, $f1
    /* 2DA3EC 003DA3EC 41340046 */  sub.s      $f17, $f6, $f0
    /* 2DA3F0 003DA3F0 01130C46 */  sub.s      $f12, $f2, $f12
    /* 2DA3F4 003DA3F4 410B0D46 */  sub.s      $f13, $f1, $f13
    /* 2DA3F8 003DA3F8 F1014014 */  bnez       $2, .L003DABC0
    /* 2DA3FC 003DA3FC 81030E46 */   sub.s     $f14, $f0, $f14
  .L003DA400:
    /* 2DA400 003DA400 02006230 */  andi       $2, $3, 0x2
    /* 2DA404 003DA404 19024014 */  bnez       $2, .L003DAC6C
    /* 2DA408 003DA408 00000000 */   nop
  .L003DA40C:
    /* 2DA40C 003DA40C 04006230 */  andi       $2, $3, 0x4
    /* 2DA410 003DA410 41024014 */  bnez       $2, .L003DAD18
    /* 2DA414 003DA414 00000000 */   nop
  .L003DA418:
    /* 2DA418 003DA418 08006230 */  andi       $2, $3, 0x8
    /* 2DA41C 003DA41C 69024014 */  bnez       $2, .L003DADC4
    /* 2DA420 003DA420 00000000 */   nop
  .L003DA424:
    /* 2DA424 003DA424 10006230 */  andi       $2, $3, 0x10
    /* 2DA428 003DA428 91024014 */  bnez       $2, .L003DAE70
    /* 2DA42C 003DA42C 00000000 */   nop
  .L003DA430:
    /* 2DA430 003DA430 20006230 */  andi       $2, $3, 0x20
    /* 2DA434 003DA434 B9024010 */  beqz       $2, .L003DAF1C
    /* 2DA438 003DA438 00000000 */   nop
    /* 2DA43C 003DA43C 00488044 */  mtc1       $0, $f9
    /* 2DA440 003DA440 00000000 */  nop
    /* 2DA444 003DA444 34880946 */  c.lt.s     $f17, $f9
    /* 2DA448 003DA448 14000045 */  bc1f       .L003DA49C
    /* 2DA44C 003DA44C C2730F46 */   mul.s     $f15, $f14, $f15
    /* 2DA450 003DA450 42521146 */  mul.s      $f9, $f10, $f17
    /* 2DA454 003DA454 34780946 */  c.lt.s     $f15, $f9
    /* 2DA458 003DA458 B0020045 */  bc1f       .L003DAF1C
    /* 2DA45C 003DA45C 00000000 */   nop
    /* 2DA460 003DA460 42621146 */  mul.s      $f9, $f12, $f17
    /* 2DA464 003DA464 36780946 */  c.le.s     $f15, $f9
    /* 2DA468 003DA468 AC020145 */  bc1t       .L003DAF1C
    /* 2DA46C 003DA46C 00000000 */   nop
    /* 2DA470 003DA470 82721046 */  mul.s      $f10, $f14, $f16
    /* 2DA474 003DA474 425A1146 */  mul.s      $f9, $f11, $f17
    /* 2DA478 003DA478 34500946 */  c.lt.s     $f10, $f9
    /* 2DA47C 003DA47C A7020045 */  bc1f       .L003DAF1C
    /* 2DA480 003DA480 00000000 */   nop
    /* 2DA484 003DA484 426A1146 */  mul.s      $f9, $f13, $f17
    /* 2DA488 003DA488 36500946 */  c.le.s     $f10, $f9
    /* 2DA48C 003DA48C A3020145 */  bc1t       .L003DAF1C
    /* 2DA490 003DA490 00000000 */   nop
    /* 2DA494 003DA494 36030010 */  b          .L003DB170
    /* 2DA498 003DA498 01000224 */   addiu     $2, $0, 0x1
  .L003DA49C:
    /* 2DA49C 003DA49C 42521146 */  mul.s      $f9, $f10, $f17
    /* 2DA4A0 003DA4A0 36780946 */  c.le.s     $f15, $f9
    /* 2DA4A4 003DA4A4 9D020145 */  bc1t       .L003DAF1C
    /* 2DA4A8 003DA4A8 00000000 */   nop
    /* 2DA4AC 003DA4AC 42621146 */  mul.s      $f9, $f12, $f17
    /* 2DA4B0 003DA4B0 34780946 */  c.lt.s     $f15, $f9
    /* 2DA4B4 003DA4B4 99020045 */  bc1f       .L003DAF1C
    /* 2DA4B8 003DA4B8 00000000 */   nop
    /* 2DA4BC 003DA4BC 82721046 */  mul.s      $f10, $f14, $f16
    /* 2DA4C0 003DA4C0 425A1146 */  mul.s      $f9, $f11, $f17
    /* 2DA4C4 003DA4C4 36500946 */  c.le.s     $f10, $f9
    /* 2DA4C8 003DA4C8 94020145 */  bc1t       .L003DAF1C
    /* 2DA4CC 003DA4CC 00000000 */   nop
    /* 2DA4D0 003DA4D0 426A1146 */  mul.s      $f9, $f13, $f17
    /* 2DA4D4 003DA4D4 34500946 */  c.lt.s     $f10, $f9
    /* 2DA4D8 003DA4D8 90020045 */  bc1f       .L003DAF1C
    /* 2DA4DC 003DA4DC 00000000 */   nop
    /* 2DA4E0 003DA4E0 23030010 */  b          .L003DB170
    /* 2DA4E4 003DA4E4 01000224 */   addiu     $2, $0, 0x1
  .L003DA4E8:
    /* 2DA4E8 003DA4E8 21030010 */  b          .L003DB170
    /* 2DA4EC 003DA4EC 01000224 */   addiu     $2, $0, 0x1
  .L003DA4F0:
    /* 2DA4F0 003DA4F0 1F030010 */  b          .L003DB170
    /* 2DA4F4 003DA4F4 01000224 */   addiu     $2, $0, 0x1
  .L003DA4F8:
    /* 2DA4F8 003DA4F8 1D030010 */  b          .L003DB170
    /* 2DA4FC 003DA4FC 01000224 */   addiu     $2, $0, 0x1
  .L003DA500:
    /* 2DA500 003DA500 1B030010 */  b          .L003DB170
    /* 2DA504 003DA504 2D100000 */   daddu     $2, $0, $0
  .L003DA508:
    /* 2DA508 003DA508 00A88044 */  mtc1       $0, $f21
    /* 2DA50C 003DA50C 00000000 */  nop
    /* 2DA510 003DA510 34901546 */  c.lt.s     $f18, $f21
    /* 2DA514 003DA514 14000045 */  bc1f       .L003DA568
    /* 2DA518 003DA518 82651346 */   mul.s     $f22, $f12, $f19
    /* 2DA51C 003DA51C 426D1246 */  mul.s      $f21, $f13, $f18
    /* 2DA520 003DA520 34B01546 */  c.lt.s     $f22, $f21
    /* 2DA524 003DA524 1EFF0045 */  bc1f       .L003DA1A0
    /* 2DA528 003DA528 00000000 */   nop
    /* 2DA52C 003DA52C 42851246 */  mul.s      $f21, $f16, $f18
    /* 2DA530 003DA530 36B01546 */  c.le.s     $f22, $f21
    /* 2DA534 003DA534 1AFF0145 */  bc1t       .L003DA1A0
    /* 2DA538 003DA538 00000000 */   nop
    /* 2DA53C 003DA53C 82651446 */  mul.s      $f22, $f12, $f20
    /* 2DA540 003DA540 42751246 */  mul.s      $f21, $f14, $f18
    /* 2DA544 003DA544 34B01546 */  c.lt.s     $f22, $f21
    /* 2DA548 003DA548 15FF0045 */  bc1f       .L003DA1A0
    /* 2DA54C 003DA54C 00000000 */   nop
    /* 2DA550 003DA550 428D1246 */  mul.s      $f21, $f17, $f18
    /* 2DA554 003DA554 36B01546 */  c.le.s     $f22, $f21
    /* 2DA558 003DA558 11FF0145 */  bc1t       .L003DA1A0
    /* 2DA55C 003DA55C 00000000 */   nop
    /* 2DA560 003DA560 03030010 */  b          .L003DB170
    /* 2DA564 003DA564 01000224 */   addiu     $2, $0, 0x1
  .L003DA568:
    /* 2DA568 003DA568 426D1246 */  mul.s      $f21, $f13, $f18
    /* 2DA56C 003DA56C 36B01546 */  c.le.s     $f22, $f21
    /* 2DA570 003DA570 0BFF0145 */  bc1t       .L003DA1A0
    /* 2DA574 003DA574 00000000 */   nop
    /* 2DA578 003DA578 42851246 */  mul.s      $f21, $f16, $f18
    /* 2DA57C 003DA57C 34B01546 */  c.lt.s     $f22, $f21
    /* 2DA580 003DA580 07FF0045 */  bc1f       .L003DA1A0
    /* 2DA584 003DA584 00000000 */   nop
    /* 2DA588 003DA588 82651446 */  mul.s      $f22, $f12, $f20
    /* 2DA58C 003DA58C 42751246 */  mul.s      $f21, $f14, $f18
    /* 2DA590 003DA590 36B01546 */  c.le.s     $f22, $f21
    /* 2DA594 003DA594 02FF0145 */  bc1t       .L003DA1A0
    /* 2DA598 003DA598 00000000 */   nop
    /* 2DA59C 003DA59C 428D1246 */  mul.s      $f21, $f17, $f18
    /* 2DA5A0 003DA5A0 34B01546 */  c.lt.s     $f22, $f21
    /* 2DA5A4 003DA5A4 FEFE0045 */  bc1f       .L003DA1A0
    /* 2DA5A8 003DA5A8 00000000 */   nop
    /* 2DA5AC 003DA5AC F0020010 */  b          .L003DB170
    /* 2DA5B0 003DA5B0 01000224 */   addiu     $2, $0, 0x1
  .L003DA5B4:
    /* 2DA5B4 003DA5B4 00A88044 */  mtc1       $0, $f21
    /* 2DA5B8 003DA5B8 00000000 */  nop
    /* 2DA5BC 003DA5BC 34901546 */  c.lt.s     $f18, $f21
    /* 2DA5C0 003DA5C0 14000045 */  bc1f       .L003DA614
    /* 2DA5C4 003DA5C4 827D1346 */   mul.s     $f22, $f15, $f19
    /* 2DA5C8 003DA5C8 426D1246 */  mul.s      $f21, $f13, $f18
    /* 2DA5CC 003DA5CC 34B01546 */  c.lt.s     $f22, $f21
    /* 2DA5D0 003DA5D0 F6FE0045 */  bc1f       .L003DA1AC
    /* 2DA5D4 003DA5D4 00000000 */   nop
    /* 2DA5D8 003DA5D8 42851246 */  mul.s      $f21, $f16, $f18
    /* 2DA5DC 003DA5DC 36B01546 */  c.le.s     $f22, $f21
    /* 2DA5E0 003DA5E0 F2FE0145 */  bc1t       .L003DA1AC
    /* 2DA5E4 003DA5E4 00000000 */   nop
    /* 2DA5E8 003DA5E8 827D1446 */  mul.s      $f22, $f15, $f20
    /* 2DA5EC 003DA5EC 42751246 */  mul.s      $f21, $f14, $f18
    /* 2DA5F0 003DA5F0 34B01546 */  c.lt.s     $f22, $f21
    /* 2DA5F4 003DA5F4 EDFE0045 */  bc1f       .L003DA1AC
    /* 2DA5F8 003DA5F8 00000000 */   nop
    /* 2DA5FC 003DA5FC 428D1246 */  mul.s      $f21, $f17, $f18
    /* 2DA600 003DA600 36B01546 */  c.le.s     $f22, $f21
    /* 2DA604 003DA604 E9FE0145 */  bc1t       .L003DA1AC
    /* 2DA608 003DA608 00000000 */   nop
    /* 2DA60C 003DA60C D8020010 */  b          .L003DB170
    /* 2DA610 003DA610 01000224 */   addiu     $2, $0, 0x1
  .L003DA614:
    /* 2DA614 003DA614 426D1246 */  mul.s      $f21, $f13, $f18
    /* 2DA618 003DA618 36B01546 */  c.le.s     $f22, $f21
    /* 2DA61C 003DA61C E3FE0145 */  bc1t       .L003DA1AC
    /* 2DA620 003DA620 00000000 */   nop
    /* 2DA624 003DA624 42851246 */  mul.s      $f21, $f16, $f18
    /* 2DA628 003DA628 34B01546 */  c.lt.s     $f22, $f21
    /* 2DA62C 003DA62C DFFE0045 */  bc1f       .L003DA1AC
    /* 2DA630 003DA630 00000000 */   nop
    /* 2DA634 003DA634 827D1446 */  mul.s      $f22, $f15, $f20
    /* 2DA638 003DA638 42751246 */  mul.s      $f21, $f14, $f18
    /* 2DA63C 003DA63C 36B01546 */  c.le.s     $f22, $f21
    /* 2DA640 003DA640 DAFE0145 */  bc1t       .L003DA1AC
    /* 2DA644 003DA644 00000000 */   nop
    /* 2DA648 003DA648 428D1246 */  mul.s      $f21, $f17, $f18
    /* 2DA64C 003DA64C 34B01546 */  c.lt.s     $f22, $f21
    /* 2DA650 003DA650 D6FE0045 */  bc1f       .L003DA1AC
    /* 2DA654 003DA654 00000000 */   nop
    /* 2DA658 003DA658 C5020010 */  b          .L003DB170
    /* 2DA65C 003DA65C 01000224 */   addiu     $2, $0, 0x1
  .L003DA660:
    /* 2DA660 003DA660 00A88044 */  mtc1       $0, $f21
    /* 2DA664 003DA664 00000000 */  nop
    /* 2DA668 003DA668 34981546 */  c.lt.s     $f19, $f21
    /* 2DA66C 003DA66C 14000045 */  bc1f       .L003DA6C0
    /* 2DA670 003DA670 826D1446 */   mul.s     $f22, $f13, $f20
    /* 2DA674 003DA674 42751346 */  mul.s      $f21, $f14, $f19
    /* 2DA678 003DA678 34B01546 */  c.lt.s     $f22, $f21
    /* 2DA67C 003DA67C CEFE0045 */  bc1f       .L003DA1B8
    /* 2DA680 003DA680 00000000 */   nop
    /* 2DA684 003DA684 428D1346 */  mul.s      $f21, $f17, $f19
    /* 2DA688 003DA688 36B01546 */  c.le.s     $f22, $f21
    /* 2DA68C 003DA68C CAFE0145 */  bc1t       .L003DA1B8
    /* 2DA690 003DA690 00000000 */   nop
    /* 2DA694 003DA694 826D1246 */  mul.s      $f22, $f13, $f18
    /* 2DA698 003DA698 42651346 */  mul.s      $f21, $f12, $f19
    /* 2DA69C 003DA69C 34B01546 */  c.lt.s     $f22, $f21
    /* 2DA6A0 003DA6A0 C5FE0045 */  bc1f       .L003DA1B8
    /* 2DA6A4 003DA6A4 00000000 */   nop
    /* 2DA6A8 003DA6A8 427D1346 */  mul.s      $f21, $f15, $f19
    /* 2DA6AC 003DA6AC 36B01546 */  c.le.s     $f22, $f21
    /* 2DA6B0 003DA6B0 C1FE0145 */  bc1t       .L003DA1B8
    /* 2DA6B4 003DA6B4 00000000 */   nop
    /* 2DA6B8 003DA6B8 AD020010 */  b          .L003DB170
    /* 2DA6BC 003DA6BC 01000224 */   addiu     $2, $0, 0x1
  .L003DA6C0:
    /* 2DA6C0 003DA6C0 42751346 */  mul.s      $f21, $f14, $f19
    /* 2DA6C4 003DA6C4 36B01546 */  c.le.s     $f22, $f21
    /* 2DA6C8 003DA6C8 BBFE0145 */  bc1t       .L003DA1B8
    /* 2DA6CC 003DA6CC 00000000 */   nop
    /* 2DA6D0 003DA6D0 428D1346 */  mul.s      $f21, $f17, $f19
    /* 2DA6D4 003DA6D4 34B01546 */  c.lt.s     $f22, $f21
    /* 2DA6D8 003DA6D8 B7FE0045 */  bc1f       .L003DA1B8
    /* 2DA6DC 003DA6DC 00000000 */   nop
    /* 2DA6E0 003DA6E0 826D1246 */  mul.s      $f22, $f13, $f18
    /* 2DA6E4 003DA6E4 42651346 */  mul.s      $f21, $f12, $f19
    /* 2DA6E8 003DA6E8 36B01546 */  c.le.s     $f22, $f21
    /* 2DA6EC 003DA6EC B2FE0145 */  bc1t       .L003DA1B8
    /* 2DA6F0 003DA6F0 00000000 */   nop
    /* 2DA6F4 003DA6F4 427D1346 */  mul.s      $f21, $f15, $f19
    /* 2DA6F8 003DA6F8 34B01546 */  c.lt.s     $f22, $f21
    /* 2DA6FC 003DA6FC AEFE0045 */  bc1f       .L003DA1B8
    /* 2DA700 003DA700 00000000 */   nop
    /* 2DA704 003DA704 9A020010 */  b          .L003DB170
    /* 2DA708 003DA708 01000224 */   addiu     $2, $0, 0x1
  .L003DA70C:
    /* 2DA70C 003DA70C 00A88044 */  mtc1       $0, $f21
    /* 2DA710 003DA710 00000000 */  nop
    /* 2DA714 003DA714 34981546 */  c.lt.s     $f19, $f21
    /* 2DA718 003DA718 14000045 */  bc1f       .L003DA76C
    /* 2DA71C 003DA71C 82851446 */   mul.s     $f22, $f16, $f20
    /* 2DA720 003DA720 42751346 */  mul.s      $f21, $f14, $f19
    /* 2DA724 003DA724 34B01546 */  c.lt.s     $f22, $f21
    /* 2DA728 003DA728 A6FE0045 */  bc1f       .L003DA1C4
    /* 2DA72C 003DA72C 00000000 */   nop
    /* 2DA730 003DA730 428D1346 */  mul.s      $f21, $f17, $f19
    /* 2DA734 003DA734 36B01546 */  c.le.s     $f22, $f21
    /* 2DA738 003DA738 A2FE0145 */  bc1t       .L003DA1C4
    /* 2DA73C 003DA73C 00000000 */   nop
    /* 2DA740 003DA740 82851246 */  mul.s      $f22, $f16, $f18
    /* 2DA744 003DA744 42651346 */  mul.s      $f21, $f12, $f19
    /* 2DA748 003DA748 34B01546 */  c.lt.s     $f22, $f21
    /* 2DA74C 003DA74C 9DFE0045 */  bc1f       .L003DA1C4
    /* 2DA750 003DA750 00000000 */   nop
    /* 2DA754 003DA754 427D1346 */  mul.s      $f21, $f15, $f19
    /* 2DA758 003DA758 36B01546 */  c.le.s     $f22, $f21
    /* 2DA75C 003DA75C 99FE0145 */  bc1t       .L003DA1C4
    /* 2DA760 003DA760 00000000 */   nop
    /* 2DA764 003DA764 82020010 */  b          .L003DB170
    /* 2DA768 003DA768 01000224 */   addiu     $2, $0, 0x1
  .L003DA76C:
    /* 2DA76C 003DA76C 42751346 */  mul.s      $f21, $f14, $f19
    /* 2DA770 003DA770 36B01546 */  c.le.s     $f22, $f21
    /* 2DA774 003DA774 93FE0145 */  bc1t       .L003DA1C4
    /* 2DA778 003DA778 00000000 */   nop
    /* 2DA77C 003DA77C 428D1346 */  mul.s      $f21, $f17, $f19
    /* 2DA780 003DA780 34B01546 */  c.lt.s     $f22, $f21
    /* 2DA784 003DA784 8FFE0045 */  bc1f       .L003DA1C4
    /* 2DA788 003DA788 00000000 */   nop
    /* 2DA78C 003DA78C 82851246 */  mul.s      $f22, $f16, $f18
    /* 2DA790 003DA790 42651346 */  mul.s      $f21, $f12, $f19
    /* 2DA794 003DA794 36B01546 */  c.le.s     $f22, $f21
    /* 2DA798 003DA798 8AFE0145 */  bc1t       .L003DA1C4
    /* 2DA79C 003DA79C 00000000 */   nop
    /* 2DA7A0 003DA7A0 427D1346 */  mul.s      $f21, $f15, $f19
    /* 2DA7A4 003DA7A4 34B01546 */  c.lt.s     $f22, $f21
    /* 2DA7A8 003DA7A8 86FE0045 */  bc1f       .L003DA1C4
    /* 2DA7AC 003DA7AC 00000000 */   nop
    /* 2DA7B0 003DA7B0 6F020010 */  b          .L003DB170
    /* 2DA7B4 003DA7B4 01000224 */   addiu     $2, $0, 0x1
  .L003DA7B8:
    /* 2DA7B8 003DA7B8 00A88044 */  mtc1       $0, $f21
    /* 2DA7BC 003DA7BC 00000000 */  nop
    /* 2DA7C0 003DA7C0 34A01546 */  c.lt.s     $f20, $f21
    /* 2DA7C4 003DA7C4 14000045 */  bc1f       .L003DA818
    /* 2DA7C8 003DA7C8 82751246 */   mul.s     $f22, $f14, $f18
    /* 2DA7CC 003DA7CC 42651446 */  mul.s      $f21, $f12, $f20
    /* 2DA7D0 003DA7D0 34B01546 */  c.lt.s     $f22, $f21
    /* 2DA7D4 003DA7D4 7EFE0045 */  bc1f       .L003DA1D0
    /* 2DA7D8 003DA7D8 00000000 */   nop
    /* 2DA7DC 003DA7DC 427D1446 */  mul.s      $f21, $f15, $f20
    /* 2DA7E0 003DA7E0 36B01546 */  c.le.s     $f22, $f21
    /* 2DA7E4 003DA7E4 7AFE0145 */  bc1t       .L003DA1D0
    /* 2DA7E8 003DA7E8 00000000 */   nop
    /* 2DA7EC 003DA7EC 42751346 */  mul.s      $f21, $f14, $f19
    /* 2DA7F0 003DA7F0 826B1446 */  mul.s      $f14, $f13, $f20
    /* 2DA7F4 003DA7F4 34A80E46 */  c.lt.s     $f21, $f14
    /* 2DA7F8 003DA7F8 75FE0045 */  bc1f       .L003DA1D0
    /* 2DA7FC 003DA7FC 00000000 */   nop
    /* 2DA800 003DA800 82831446 */  mul.s      $f14, $f16, $f20
    /* 2DA804 003DA804 36A80E46 */  c.le.s     $f21, $f14
    /* 2DA808 003DA808 71FE0145 */  bc1t       .L003DA1D0
    /* 2DA80C 003DA80C 00000000 */   nop
    /* 2DA810 003DA810 57020010 */  b          .L003DB170
    /* 2DA814 003DA814 01000224 */   addiu     $2, $0, 0x1
  .L003DA818:
    /* 2DA818 003DA818 42651446 */  mul.s      $f21, $f12, $f20
    /* 2DA81C 003DA81C 36B01546 */  c.le.s     $f22, $f21
    /* 2DA820 003DA820 6BFE0145 */  bc1t       .L003DA1D0
    /* 2DA824 003DA824 00000000 */   nop
    /* 2DA828 003DA828 427D1446 */  mul.s      $f21, $f15, $f20
    /* 2DA82C 003DA82C 34B01546 */  c.lt.s     $f22, $f21
    /* 2DA830 003DA830 67FE0045 */  bc1f       .L003DA1D0
    /* 2DA834 003DA834 00000000 */   nop
    /* 2DA838 003DA838 42751346 */  mul.s      $f21, $f14, $f19
    /* 2DA83C 003DA83C 826B1446 */  mul.s      $f14, $f13, $f20
    /* 2DA840 003DA840 36A80E46 */  c.le.s     $f21, $f14
    /* 2DA844 003DA844 62FE0145 */  bc1t       .L003DA1D0
    /* 2DA848 003DA848 00000000 */   nop
    /* 2DA84C 003DA84C 82831446 */  mul.s      $f14, $f16, $f20
    /* 2DA850 003DA850 34A80E46 */  c.lt.s     $f21, $f14
    /* 2DA854 003DA854 5EFE0045 */  bc1f       .L003DA1D0
    /* 2DA858 003DA858 00000000 */   nop
    /* 2DA85C 003DA85C 44020010 */  b          .L003DB170
    /* 2DA860 003DA860 01000224 */   addiu     $2, $0, 0x1
  .L003DA864:
    /* 2DA864 003DA864 00A88044 */  mtc1       $0, $f21
    /* 2DA868 003DA868 00000000 */  nop
    /* 2DA86C 003DA86C 34901546 */  c.lt.s     $f18, $f21
    /* 2DA870 003DA870 14000045 */  bc1f       .L003DA8C4
    /* 2DA874 003DA874 82651346 */   mul.s     $f22, $f12, $f19
    /* 2DA878 003DA878 426D1246 */  mul.s      $f21, $f13, $f18
    /* 2DA87C 003DA87C 34B01546 */  c.lt.s     $f22, $f21
    /* 2DA880 003DA880 93FE0045 */  bc1f       .L003DA2D0
    /* 2DA884 003DA884 00000000 */   nop
    /* 2DA888 003DA888 42851246 */  mul.s      $f21, $f16, $f18
    /* 2DA88C 003DA88C 36B01546 */  c.le.s     $f22, $f21
    /* 2DA890 003DA890 8FFE0145 */  bc1t       .L003DA2D0
    /* 2DA894 003DA894 00000000 */   nop
    /* 2DA898 003DA898 82651446 */  mul.s      $f22, $f12, $f20
    /* 2DA89C 003DA89C 42751246 */  mul.s      $f21, $f14, $f18
    /* 2DA8A0 003DA8A0 34B01546 */  c.lt.s     $f22, $f21
    /* 2DA8A4 003DA8A4 8AFE0045 */  bc1f       .L003DA2D0
    /* 2DA8A8 003DA8A8 00000000 */   nop
    /* 2DA8AC 003DA8AC 428D1246 */  mul.s      $f21, $f17, $f18
    /* 2DA8B0 003DA8B0 36B01546 */  c.le.s     $f22, $f21
    /* 2DA8B4 003DA8B4 86FE0145 */  bc1t       .L003DA2D0
    /* 2DA8B8 003DA8B8 00000000 */   nop
    /* 2DA8BC 003DA8BC 2C020010 */  b          .L003DB170
    /* 2DA8C0 003DA8C0 01000224 */   addiu     $2, $0, 0x1
  .L003DA8C4:
    /* 2DA8C4 003DA8C4 426D1246 */  mul.s      $f21, $f13, $f18
    /* 2DA8C8 003DA8C8 36B01546 */  c.le.s     $f22, $f21
    /* 2DA8CC 003DA8CC 80FE0145 */  bc1t       .L003DA2D0
    /* 2DA8D0 003DA8D0 00000000 */   nop
    /* 2DA8D4 003DA8D4 42851246 */  mul.s      $f21, $f16, $f18
    /* 2DA8D8 003DA8D8 34B01546 */  c.lt.s     $f22, $f21
    /* 2DA8DC 003DA8DC 7CFE0045 */  bc1f       .L003DA2D0
    /* 2DA8E0 003DA8E0 00000000 */   nop
    /* 2DA8E4 003DA8E4 82651446 */  mul.s      $f22, $f12, $f20
    /* 2DA8E8 003DA8E8 42751246 */  mul.s      $f21, $f14, $f18
    /* 2DA8EC 003DA8EC 36B01546 */  c.le.s     $f22, $f21
    /* 2DA8F0 003DA8F0 77FE0145 */  bc1t       .L003DA2D0
    /* 2DA8F4 003DA8F4 00000000 */   nop
    /* 2DA8F8 003DA8F8 428D1246 */  mul.s      $f21, $f17, $f18
    /* 2DA8FC 003DA8FC 34B01546 */  c.lt.s     $f22, $f21
    /* 2DA900 003DA900 73FE0045 */  bc1f       .L003DA2D0
    /* 2DA904 003DA904 00000000 */   nop
    /* 2DA908 003DA908 19020010 */  b          .L003DB170
    /* 2DA90C 003DA90C 01000224 */   addiu     $2, $0, 0x1
  .L003DA910:
    /* 2DA910 003DA910 00A88044 */  mtc1       $0, $f21
    /* 2DA914 003DA914 00000000 */  nop
    /* 2DA918 003DA918 34901546 */  c.lt.s     $f18, $f21
    /* 2DA91C 003DA91C 14000045 */  bc1f       .L003DA970
    /* 2DA920 003DA920 827D1346 */   mul.s     $f22, $f15, $f19
    /* 2DA924 003DA924 426D1246 */  mul.s      $f21, $f13, $f18
    /* 2DA928 003DA928 34B01546 */  c.lt.s     $f22, $f21
    /* 2DA92C 003DA92C 6BFE0045 */  bc1f       .L003DA2DC
    /* 2DA930 003DA930 00000000 */   nop
    /* 2DA934 003DA934 42851246 */  mul.s      $f21, $f16, $f18
    /* 2DA938 003DA938 36B01546 */  c.le.s     $f22, $f21
    /* 2DA93C 003DA93C 67FE0145 */  bc1t       .L003DA2DC
    /* 2DA940 003DA940 00000000 */   nop
    /* 2DA944 003DA944 827D1446 */  mul.s      $f22, $f15, $f20
    /* 2DA948 003DA948 42751246 */  mul.s      $f21, $f14, $f18
    /* 2DA94C 003DA94C 34B01546 */  c.lt.s     $f22, $f21
    /* 2DA950 003DA950 62FE0045 */  bc1f       .L003DA2DC
    /* 2DA954 003DA954 00000000 */   nop
    /* 2DA958 003DA958 428D1246 */  mul.s      $f21, $f17, $f18
    /* 2DA95C 003DA95C 36B01546 */  c.le.s     $f22, $f21
    /* 2DA960 003DA960 5EFE0145 */  bc1t       .L003DA2DC
    /* 2DA964 003DA964 00000000 */   nop
    /* 2DA968 003DA968 01020010 */  b          .L003DB170
    /* 2DA96C 003DA96C 01000224 */   addiu     $2, $0, 0x1
  .L003DA970:
    /* 2DA970 003DA970 426D1246 */  mul.s      $f21, $f13, $f18
    /* 2DA974 003DA974 36B01546 */  c.le.s     $f22, $f21
    /* 2DA978 003DA978 58FE0145 */  bc1t       .L003DA2DC
    /* 2DA97C 003DA97C 00000000 */   nop
    /* 2DA980 003DA980 42851246 */  mul.s      $f21, $f16, $f18
    /* 2DA984 003DA984 34B01546 */  c.lt.s     $f22, $f21
    /* 2DA988 003DA988 54FE0045 */  bc1f       .L003DA2DC
    /* 2DA98C 003DA98C 00000000 */   nop
    /* 2DA990 003DA990 827D1446 */  mul.s      $f22, $f15, $f20
    /* 2DA994 003DA994 42751246 */  mul.s      $f21, $f14, $f18
    /* 2DA998 003DA998 36B01546 */  c.le.s     $f22, $f21
    /* 2DA99C 003DA99C 4FFE0145 */  bc1t       .L003DA2DC
    /* 2DA9A0 003DA9A0 00000000 */   nop
    /* 2DA9A4 003DA9A4 428D1246 */  mul.s      $f21, $f17, $f18
    /* 2DA9A8 003DA9A8 34B01546 */  c.lt.s     $f22, $f21
    /* 2DA9AC 003DA9AC 4BFE0045 */  bc1f       .L003DA2DC
    /* 2DA9B0 003DA9B0 00000000 */   nop
    /* 2DA9B4 003DA9B4 EE010010 */  b          .L003DB170
    /* 2DA9B8 003DA9B8 01000224 */   addiu     $2, $0, 0x1
  .L003DA9BC:
    /* 2DA9BC 003DA9BC 00A88044 */  mtc1       $0, $f21
    /* 2DA9C0 003DA9C0 00000000 */  nop
    /* 2DA9C4 003DA9C4 34981546 */  c.lt.s     $f19, $f21
    /* 2DA9C8 003DA9C8 14000045 */  bc1f       .L003DAA1C
    /* 2DA9CC 003DA9CC 826D1446 */   mul.s     $f22, $f13, $f20
    /* 2DA9D0 003DA9D0 42751346 */  mul.s      $f21, $f14, $f19
    /* 2DA9D4 003DA9D4 34B01546 */  c.lt.s     $f22, $f21
    /* 2DA9D8 003DA9D8 43FE0045 */  bc1f       .L003DA2E8
    /* 2DA9DC 003DA9DC 00000000 */   nop
    /* 2DA9E0 003DA9E0 428D1346 */  mul.s      $f21, $f17, $f19
    /* 2DA9E4 003DA9E4 36B01546 */  c.le.s     $f22, $f21
    /* 2DA9E8 003DA9E8 3FFE0145 */  bc1t       .L003DA2E8
    /* 2DA9EC 003DA9EC 00000000 */   nop
    /* 2DA9F0 003DA9F0 826D1246 */  mul.s      $f22, $f13, $f18
    /* 2DA9F4 003DA9F4 42651346 */  mul.s      $f21, $f12, $f19
    /* 2DA9F8 003DA9F8 34B01546 */  c.lt.s     $f22, $f21
    /* 2DA9FC 003DA9FC 3AFE0045 */  bc1f       .L003DA2E8
    /* 2DAA00 003DAA00 00000000 */   nop
    /* 2DAA04 003DAA04 427D1346 */  mul.s      $f21, $f15, $f19
    /* 2DAA08 003DAA08 36B01546 */  c.le.s     $f22, $f21
    /* 2DAA0C 003DAA0C 36FE0145 */  bc1t       .L003DA2E8
    /* 2DAA10 003DAA10 00000000 */   nop
    /* 2DAA14 003DAA14 D6010010 */  b          .L003DB170
    /* 2DAA18 003DAA18 01000224 */   addiu     $2, $0, 0x1
  .L003DAA1C:
    /* 2DAA1C 003DAA1C 42751346 */  mul.s      $f21, $f14, $f19
    /* 2DAA20 003DAA20 36B01546 */  c.le.s     $f22, $f21
    /* 2DAA24 003DAA24 30FE0145 */  bc1t       .L003DA2E8
    /* 2DAA28 003DAA28 00000000 */   nop
    /* 2DAA2C 003DAA2C 428D1346 */  mul.s      $f21, $f17, $f19
    /* 2DAA30 003DAA30 34B01546 */  c.lt.s     $f22, $f21
    /* 2DAA34 003DAA34 2CFE0045 */  bc1f       .L003DA2E8
    /* 2DAA38 003DAA38 00000000 */   nop
    /* 2DAA3C 003DAA3C 826D1246 */  mul.s      $f22, $f13, $f18
    /* 2DAA40 003DAA40 42651346 */  mul.s      $f21, $f12, $f19
    /* 2DAA44 003DAA44 36B01546 */  c.le.s     $f22, $f21
    /* 2DAA48 003DAA48 27FE0145 */  bc1t       .L003DA2E8
    /* 2DAA4C 003DAA4C 00000000 */   nop
    /* 2DAA50 003DAA50 427D1346 */  mul.s      $f21, $f15, $f19
    /* 2DAA54 003DAA54 34B01546 */  c.lt.s     $f22, $f21
    /* 2DAA58 003DAA58 23FE0045 */  bc1f       .L003DA2E8
    /* 2DAA5C 003DAA5C 00000000 */   nop
    /* 2DAA60 003DAA60 C3010010 */  b          .L003DB170
    /* 2DAA64 003DAA64 01000224 */   addiu     $2, $0, 0x1
  .L003DAA68:
    /* 2DAA68 003DAA68 00A88044 */  mtc1       $0, $f21
    /* 2DAA6C 003DAA6C 00000000 */  nop
    /* 2DAA70 003DAA70 34981546 */  c.lt.s     $f19, $f21
    /* 2DAA74 003DAA74 14000045 */  bc1f       .L003DAAC8
    /* 2DAA78 003DAA78 82851446 */   mul.s     $f22, $f16, $f20
    /* 2DAA7C 003DAA7C 42751346 */  mul.s      $f21, $f14, $f19
    /* 2DAA80 003DAA80 34B01546 */  c.lt.s     $f22, $f21
    /* 2DAA84 003DAA84 1BFE0045 */  bc1f       .L003DA2F4
    /* 2DAA88 003DAA88 00000000 */   nop
    /* 2DAA8C 003DAA8C 428D1346 */  mul.s      $f21, $f17, $f19
    /* 2DAA90 003DAA90 36B01546 */  c.le.s     $f22, $f21
    /* 2DAA94 003DAA94 17FE0145 */  bc1t       .L003DA2F4
    /* 2DAA98 003DAA98 00000000 */   nop
    /* 2DAA9C 003DAA9C 82851246 */  mul.s      $f22, $f16, $f18
    /* 2DAAA0 003DAAA0 42651346 */  mul.s      $f21, $f12, $f19
    /* 2DAAA4 003DAAA4 34B01546 */  c.lt.s     $f22, $f21
    /* 2DAAA8 003DAAA8 12FE0045 */  bc1f       .L003DA2F4
    /* 2DAAAC 003DAAAC 00000000 */   nop
    /* 2DAAB0 003DAAB0 427D1346 */  mul.s      $f21, $f15, $f19
    /* 2DAAB4 003DAAB4 36B01546 */  c.le.s     $f22, $f21
    /* 2DAAB8 003DAAB8 0EFE0145 */  bc1t       .L003DA2F4
    /* 2DAABC 003DAABC 00000000 */   nop
    /* 2DAAC0 003DAAC0 AB010010 */  b          .L003DB170
    /* 2DAAC4 003DAAC4 01000224 */   addiu     $2, $0, 0x1
  .L003DAAC8:
    /* 2DAAC8 003DAAC8 42751346 */  mul.s      $f21, $f14, $f19
    /* 2DAACC 003DAACC 36B01546 */  c.le.s     $f22, $f21
    /* 2DAAD0 003DAAD0 08FE0145 */  bc1t       .L003DA2F4
    /* 2DAAD4 003DAAD4 00000000 */   nop
    /* 2DAAD8 003DAAD8 428D1346 */  mul.s      $f21, $f17, $f19
    /* 2DAADC 003DAADC 34B01546 */  c.lt.s     $f22, $f21
    /* 2DAAE0 003DAAE0 04FE0045 */  bc1f       .L003DA2F4
    /* 2DAAE4 003DAAE4 00000000 */   nop
    /* 2DAAE8 003DAAE8 82851246 */  mul.s      $f22, $f16, $f18
    /* 2DAAEC 003DAAEC 42651346 */  mul.s      $f21, $f12, $f19
    /* 2DAAF0 003DAAF0 36B01546 */  c.le.s     $f22, $f21
    /* 2DAAF4 003DAAF4 FFFD0145 */  bc1t       .L003DA2F4
    /* 2DAAF8 003DAAF8 00000000 */   nop
    /* 2DAAFC 003DAAFC 427D1346 */  mul.s      $f21, $f15, $f19
    /* 2DAB00 003DAB00 34B01546 */  c.lt.s     $f22, $f21
    /* 2DAB04 003DAB04 FBFD0045 */  bc1f       .L003DA2F4
    /* 2DAB08 003DAB08 00000000 */   nop
    /* 2DAB0C 003DAB0C 98010010 */  b          .L003DB170
    /* 2DAB10 003DAB10 01000224 */   addiu     $2, $0, 0x1
  .L003DAB14:
    /* 2DAB14 003DAB14 00A88044 */  mtc1       $0, $f21
    /* 2DAB18 003DAB18 00000000 */  nop
    /* 2DAB1C 003DAB1C 34A01546 */  c.lt.s     $f20, $f21
    /* 2DAB20 003DAB20 14000045 */  bc1f       .L003DAB74
    /* 2DAB24 003DAB24 82751246 */   mul.s     $f22, $f14, $f18
    /* 2DAB28 003DAB28 42651446 */  mul.s      $f21, $f12, $f20
    /* 2DAB2C 003DAB2C 34B01546 */  c.lt.s     $f22, $f21
    /* 2DAB30 003DAB30 F3FD0045 */  bc1f       .L003DA300
    /* 2DAB34 003DAB34 00000000 */   nop
    /* 2DAB38 003DAB38 427D1446 */  mul.s      $f21, $f15, $f20
    /* 2DAB3C 003DAB3C 36B01546 */  c.le.s     $f22, $f21
    /* 2DAB40 003DAB40 EFFD0145 */  bc1t       .L003DA300
    /* 2DAB44 003DAB44 00000000 */   nop
    /* 2DAB48 003DAB48 42751346 */  mul.s      $f21, $f14, $f19
    /* 2DAB4C 003DAB4C 826B1446 */  mul.s      $f14, $f13, $f20
    /* 2DAB50 003DAB50 34A80E46 */  c.lt.s     $f21, $f14
    /* 2DAB54 003DAB54 EAFD0045 */  bc1f       .L003DA300
    /* 2DAB58 003DAB58 00000000 */   nop
    /* 2DAB5C 003DAB5C 82831446 */  mul.s      $f14, $f16, $f20
    /* 2DAB60 003DAB60 36A80E46 */  c.le.s     $f21, $f14
    /* 2DAB64 003DAB64 E6FD0145 */  bc1t       .L003DA300
    /* 2DAB68 003DAB68 00000000 */   nop
    /* 2DAB6C 003DAB6C 80010010 */  b          .L003DB170
    /* 2DAB70 003DAB70 01000224 */   addiu     $2, $0, 0x1
  .L003DAB74:
    /* 2DAB74 003DAB74 42651446 */  mul.s      $f21, $f12, $f20
    /* 2DAB78 003DAB78 36B01546 */  c.le.s     $f22, $f21
    /* 2DAB7C 003DAB7C E0FD0145 */  bc1t       .L003DA300
    /* 2DAB80 003DAB80 00000000 */   nop
    /* 2DAB84 003DAB84 427D1446 */  mul.s      $f21, $f15, $f20
    /* 2DAB88 003DAB88 34B01546 */  c.lt.s     $f22, $f21
    /* 2DAB8C 003DAB8C DCFD0045 */  bc1f       .L003DA300
    /* 2DAB90 003DAB90 00000000 */   nop
    /* 2DAB94 003DAB94 42751346 */  mul.s      $f21, $f14, $f19
    /* 2DAB98 003DAB98 826B1446 */  mul.s      $f14, $f13, $f20
    /* 2DAB9C 003DAB9C 36A80E46 */  c.le.s     $f21, $f14
    /* 2DABA0 003DABA0 D7FD0145 */  bc1t       .L003DA300
    /* 2DABA4 003DABA4 00000000 */   nop
    /* 2DABA8 003DABA8 82831446 */  mul.s      $f14, $f16, $f20
    /* 2DABAC 003DABAC 34A80E46 */  c.lt.s     $f21, $f14
    /* 2DABB0 003DABB0 D3FD0045 */  bc1f       .L003DA300
    /* 2DABB4 003DABB4 00000000 */   nop
    /* 2DABB8 003DABB8 6D010010 */  b          .L003DB170
    /* 2DABBC 003DABBC 01000224 */   addiu     $2, $0, 0x1
  .L003DABC0:
    /* 2DABC0 003DABC0 00908044 */  mtc1       $0, $f18
    /* 2DABC4 003DABC4 00000000 */  nop
    /* 2DABC8 003DABC8 34781246 */  c.lt.s     $f15, $f18
    /* 2DABCC 003DABCC 14000045 */  bc1f       .L003DAC20
    /* 2DABD0 003DABD0 C2541046 */   mul.s     $f19, $f10, $f16
    /* 2DABD4 003DABD4 825C0F46 */  mul.s      $f18, $f11, $f15
    /* 2DABD8 003DABD8 34981246 */  c.lt.s     $f19, $f18
    /* 2DABDC 003DABDC 08FE0045 */  bc1f       .L003DA400
    /* 2DABE0 003DABE0 00000000 */   nop
    /* 2DABE4 003DABE4 826C0F46 */  mul.s      $f18, $f13, $f15
    /* 2DABE8 003DABE8 36981246 */  c.le.s     $f19, $f18
    /* 2DABEC 003DABEC 04FE0145 */  bc1t       .L003DA400
    /* 2DABF0 003DABF0 00000000 */   nop
    /* 2DABF4 003DABF4 C2541146 */  mul.s      $f19, $f10, $f17
    /* 2DABF8 003DABF8 824C0F46 */  mul.s      $f18, $f9, $f15
    /* 2DABFC 003DABFC 34981246 */  c.lt.s     $f19, $f18
    /* 2DAC00 003DAC00 FFFD0045 */  bc1f       .L003DA400
    /* 2DAC04 003DAC04 00000000 */   nop
    /* 2DAC08 003DAC08 82740F46 */  mul.s      $f18, $f14, $f15
    /* 2DAC0C 003DAC0C 36981246 */  c.le.s     $f19, $f18
    /* 2DAC10 003DAC10 FBFD0145 */  bc1t       .L003DA400
    /* 2DAC14 003DAC14 00000000 */   nop
    /* 2DAC18 003DAC18 55010010 */  b          .L003DB170
    /* 2DAC1C 003DAC1C 01000224 */   addiu     $2, $0, 0x1
  .L003DAC20:
    /* 2DAC20 003DAC20 825C0F46 */  mul.s      $f18, $f11, $f15
    /* 2DAC24 003DAC24 36981246 */  c.le.s     $f19, $f18
    /* 2DAC28 003DAC28 F5FD0145 */  bc1t       .L003DA400
    /* 2DAC2C 003DAC2C 00000000 */   nop
    /* 2DAC30 003DAC30 826C0F46 */  mul.s      $f18, $f13, $f15
    /* 2DAC34 003DAC34 34981246 */  c.lt.s     $f19, $f18
    /* 2DAC38 003DAC38 F1FD0045 */  bc1f       .L003DA400
    /* 2DAC3C 003DAC3C 00000000 */   nop
    /* 2DAC40 003DAC40 C2541146 */  mul.s      $f19, $f10, $f17
    /* 2DAC44 003DAC44 824C0F46 */  mul.s      $f18, $f9, $f15
    /* 2DAC48 003DAC48 36981246 */  c.le.s     $f19, $f18
    /* 2DAC4C 003DAC4C ECFD0145 */  bc1t       .L003DA400
    /* 2DAC50 003DAC50 00000000 */   nop
    /* 2DAC54 003DAC54 82740F46 */  mul.s      $f18, $f14, $f15
    /* 2DAC58 003DAC58 34981246 */  c.lt.s     $f19, $f18
    /* 2DAC5C 003DAC5C E8FD0045 */  bc1f       .L003DA400
    /* 2DAC60 003DAC60 00000000 */   nop
    /* 2DAC64 003DAC64 42010010 */  b          .L003DB170
    /* 2DAC68 003DAC68 01000224 */   addiu     $2, $0, 0x1
  .L003DAC6C:
    /* 2DAC6C 003DAC6C 00908044 */  mtc1       $0, $f18
    /* 2DAC70 003DAC70 00000000 */  nop
    /* 2DAC74 003DAC74 34781246 */  c.lt.s     $f15, $f18
    /* 2DAC78 003DAC78 14000045 */  bc1f       .L003DACCC
    /* 2DAC7C 003DAC7C C2641046 */   mul.s     $f19, $f12, $f16
    /* 2DAC80 003DAC80 825C0F46 */  mul.s      $f18, $f11, $f15
    /* 2DAC84 003DAC84 34981246 */  c.lt.s     $f19, $f18
    /* 2DAC88 003DAC88 E0FD0045 */  bc1f       .L003DA40C
    /* 2DAC8C 003DAC8C 00000000 */   nop
    /* 2DAC90 003DAC90 826C0F46 */  mul.s      $f18, $f13, $f15
    /* 2DAC94 003DAC94 36981246 */  c.le.s     $f19, $f18
    /* 2DAC98 003DAC98 DCFD0145 */  bc1t       .L003DA40C
    /* 2DAC9C 003DAC9C 00000000 */   nop
    /* 2DACA0 003DACA0 C2641146 */  mul.s      $f19, $f12, $f17
    /* 2DACA4 003DACA4 824C0F46 */  mul.s      $f18, $f9, $f15
    /* 2DACA8 003DACA8 34981246 */  c.lt.s     $f19, $f18
    /* 2DACAC 003DACAC D7FD0045 */  bc1f       .L003DA40C
    /* 2DACB0 003DACB0 00000000 */   nop
    /* 2DACB4 003DACB4 82740F46 */  mul.s      $f18, $f14, $f15
    /* 2DACB8 003DACB8 36981246 */  c.le.s     $f19, $f18
    /* 2DACBC 003DACBC D3FD0145 */  bc1t       .L003DA40C
    /* 2DACC0 003DACC0 00000000 */   nop
    /* 2DACC4 003DACC4 2A010010 */  b          .L003DB170
    /* 2DACC8 003DACC8 01000224 */   addiu     $2, $0, 0x1
  .L003DACCC:
    /* 2DACCC 003DACCC 825C0F46 */  mul.s      $f18, $f11, $f15
    /* 2DACD0 003DACD0 36981246 */  c.le.s     $f19, $f18
    /* 2DACD4 003DACD4 CDFD0145 */  bc1t       .L003DA40C
    /* 2DACD8 003DACD8 00000000 */   nop
    /* 2DACDC 003DACDC 826C0F46 */  mul.s      $f18, $f13, $f15
    /* 2DACE0 003DACE0 34981246 */  c.lt.s     $f19, $f18
    /* 2DACE4 003DACE4 C9FD0045 */  bc1f       .L003DA40C
    /* 2DACE8 003DACE8 00000000 */   nop
    /* 2DACEC 003DACEC C2641146 */  mul.s      $f19, $f12, $f17
    /* 2DACF0 003DACF0 824C0F46 */  mul.s      $f18, $f9, $f15
    /* 2DACF4 003DACF4 36981246 */  c.le.s     $f19, $f18
    /* 2DACF8 003DACF8 C4FD0145 */  bc1t       .L003DA40C
    /* 2DACFC 003DACFC 00000000 */   nop
    /* 2DAD00 003DAD00 82740F46 */  mul.s      $f18, $f14, $f15
    /* 2DAD04 003DAD04 34981246 */  c.lt.s     $f19, $f18
    /* 2DAD08 003DAD08 C0FD0045 */  bc1f       .L003DA40C
    /* 2DAD0C 003DAD0C 00000000 */   nop
    /* 2DAD10 003DAD10 17010010 */  b          .L003DB170
    /* 2DAD14 003DAD14 01000224 */   addiu     $2, $0, 0x1
  .L003DAD18:
    /* 2DAD18 003DAD18 00908044 */  mtc1       $0, $f18
    /* 2DAD1C 003DAD1C 00000000 */  nop
    /* 2DAD20 003DAD20 34801246 */  c.lt.s     $f16, $f18
    /* 2DAD24 003DAD24 14000045 */  bc1f       .L003DAD78
    /* 2DAD28 003DAD28 C25C1146 */   mul.s     $f19, $f11, $f17
    /* 2DAD2C 003DAD2C 824C1046 */  mul.s      $f18, $f9, $f16
    /* 2DAD30 003DAD30 34981246 */  c.lt.s     $f19, $f18
    /* 2DAD34 003DAD34 B8FD0045 */  bc1f       .L003DA418
    /* 2DAD38 003DAD38 00000000 */   nop
    /* 2DAD3C 003DAD3C 82741046 */  mul.s      $f18, $f14, $f16
    /* 2DAD40 003DAD40 36981246 */  c.le.s     $f19, $f18
    /* 2DAD44 003DAD44 B4FD0145 */  bc1t       .L003DA418
    /* 2DAD48 003DAD48 00000000 */   nop
    /* 2DAD4C 003DAD4C C25C0F46 */  mul.s      $f19, $f11, $f15
    /* 2DAD50 003DAD50 82541046 */  mul.s      $f18, $f10, $f16
    /* 2DAD54 003DAD54 34981246 */  c.lt.s     $f19, $f18
    /* 2DAD58 003DAD58 AFFD0045 */  bc1f       .L003DA418
    /* 2DAD5C 003DAD5C 00000000 */   nop
    /* 2DAD60 003DAD60 82641046 */  mul.s      $f18, $f12, $f16
    /* 2DAD64 003DAD64 36981246 */  c.le.s     $f19, $f18
    /* 2DAD68 003DAD68 ABFD0145 */  bc1t       .L003DA418
    /* 2DAD6C 003DAD6C 00000000 */   nop
    /* 2DAD70 003DAD70 FF000010 */  b          .L003DB170
    /* 2DAD74 003DAD74 01000224 */   addiu     $2, $0, 0x1
  .L003DAD78:
    /* 2DAD78 003DAD78 824C1046 */  mul.s      $f18, $f9, $f16
    /* 2DAD7C 003DAD7C 36981246 */  c.le.s     $f19, $f18
    /* 2DAD80 003DAD80 A5FD0145 */  bc1t       .L003DA418
    /* 2DAD84 003DAD84 00000000 */   nop
    /* 2DAD88 003DAD88 82741046 */  mul.s      $f18, $f14, $f16
    /* 2DAD8C 003DAD8C 34981246 */  c.lt.s     $f19, $f18
    /* 2DAD90 003DAD90 A1FD0045 */  bc1f       .L003DA418
    /* 2DAD94 003DAD94 00000000 */   nop
    /* 2DAD98 003DAD98 C25C0F46 */  mul.s      $f19, $f11, $f15
    /* 2DAD9C 003DAD9C 82541046 */  mul.s      $f18, $f10, $f16
    /* 2DADA0 003DADA0 36981246 */  c.le.s     $f19, $f18
    /* 2DADA4 003DADA4 9CFD0145 */  bc1t       .L003DA418
    /* 2DADA8 003DADA8 00000000 */   nop
    /* 2DADAC 003DADAC 82641046 */  mul.s      $f18, $f12, $f16
    /* 2DADB0 003DADB0 34981246 */  c.lt.s     $f19, $f18
    /* 2DADB4 003DADB4 98FD0045 */  bc1f       .L003DA418
    /* 2DADB8 003DADB8 00000000 */   nop
    /* 2DADBC 003DADBC EC000010 */  b          .L003DB170
    /* 2DADC0 003DADC0 01000224 */   addiu     $2, $0, 0x1
  .L003DADC4:
    /* 2DADC4 003DADC4 00908044 */  mtc1       $0, $f18
    /* 2DADC8 003DADC8 00000000 */  nop
    /* 2DADCC 003DADCC 34801246 */  c.lt.s     $f16, $f18
    /* 2DADD0 003DADD0 14000045 */  bc1f       .L003DAE24
    /* 2DADD4 003DADD4 C26C1146 */   mul.s     $f19, $f13, $f17
    /* 2DADD8 003DADD8 824C1046 */  mul.s      $f18, $f9, $f16
    /* 2DADDC 003DADDC 34981246 */  c.lt.s     $f19, $f18
    /* 2DADE0 003DADE0 90FD0045 */  bc1f       .L003DA424
    /* 2DADE4 003DADE4 00000000 */   nop
    /* 2DADE8 003DADE8 82741046 */  mul.s      $f18, $f14, $f16
    /* 2DADEC 003DADEC 36981246 */  c.le.s     $f19, $f18
    /* 2DADF0 003DADF0 8CFD0145 */  bc1t       .L003DA424
    /* 2DADF4 003DADF4 00000000 */   nop
    /* 2DADF8 003DADF8 C26C0F46 */  mul.s      $f19, $f13, $f15
    /* 2DADFC 003DADFC 82541046 */  mul.s      $f18, $f10, $f16
    /* 2DAE00 003DAE00 34981246 */  c.lt.s     $f19, $f18
    /* 2DAE04 003DAE04 87FD0045 */  bc1f       .L003DA424
    /* 2DAE08 003DAE08 00000000 */   nop
    /* 2DAE0C 003DAE0C 82641046 */  mul.s      $f18, $f12, $f16
    /* 2DAE10 003DAE10 36981246 */  c.le.s     $f19, $f18
    /* 2DAE14 003DAE14 83FD0145 */  bc1t       .L003DA424
    /* 2DAE18 003DAE18 00000000 */   nop
    /* 2DAE1C 003DAE1C D4000010 */  b          .L003DB170
    /* 2DAE20 003DAE20 01000224 */   addiu     $2, $0, 0x1
  .L003DAE24:
    /* 2DAE24 003DAE24 824C1046 */  mul.s      $f18, $f9, $f16
    /* 2DAE28 003DAE28 36981246 */  c.le.s     $f19, $f18
    /* 2DAE2C 003DAE2C 7DFD0145 */  bc1t       .L003DA424
    /* 2DAE30 003DAE30 00000000 */   nop
    /* 2DAE34 003DAE34 82741046 */  mul.s      $f18, $f14, $f16
    /* 2DAE38 003DAE38 34981246 */  c.lt.s     $f19, $f18
    /* 2DAE3C 003DAE3C 79FD0045 */  bc1f       .L003DA424
    /* 2DAE40 003DAE40 00000000 */   nop
    /* 2DAE44 003DAE44 C26C0F46 */  mul.s      $f19, $f13, $f15
    /* 2DAE48 003DAE48 82541046 */  mul.s      $f18, $f10, $f16
    /* 2DAE4C 003DAE4C 36981246 */  c.le.s     $f19, $f18
    /* 2DAE50 003DAE50 74FD0145 */  bc1t       .L003DA424
    /* 2DAE54 003DAE54 00000000 */   nop
    /* 2DAE58 003DAE58 82641046 */  mul.s      $f18, $f12, $f16
    /* 2DAE5C 003DAE5C 34981246 */  c.lt.s     $f19, $f18
    /* 2DAE60 003DAE60 70FD0045 */  bc1f       .L003DA424
    /* 2DAE64 003DAE64 00000000 */   nop
    /* 2DAE68 003DAE68 C1000010 */  b          .L003DB170
    /* 2DAE6C 003DAE6C 01000224 */   addiu     $2, $0, 0x1
  .L003DAE70:
    /* 2DAE70 003DAE70 00908044 */  mtc1       $0, $f18
    /* 2DAE74 003DAE74 00000000 */  nop
    /* 2DAE78 003DAE78 34881246 */  c.lt.s     $f17, $f18
    /* 2DAE7C 003DAE7C 14000045 */  bc1f       .L003DAED0
    /* 2DAE80 003DAE80 C24C0F46 */   mul.s     $f19, $f9, $f15
    /* 2DAE84 003DAE84 82541146 */  mul.s      $f18, $f10, $f17
    /* 2DAE88 003DAE88 34981246 */  c.lt.s     $f19, $f18
    /* 2DAE8C 003DAE8C 68FD0045 */  bc1f       .L003DA430
    /* 2DAE90 003DAE90 00000000 */   nop
    /* 2DAE94 003DAE94 82641146 */  mul.s      $f18, $f12, $f17
    /* 2DAE98 003DAE98 36981246 */  c.le.s     $f19, $f18
    /* 2DAE9C 003DAE9C 64FD0145 */  bc1t       .L003DA430
    /* 2DAEA0 003DAEA0 00000000 */   nop
    /* 2DAEA4 003DAEA4 824C1046 */  mul.s      $f18, $f9, $f16
    /* 2DAEA8 003DAEA8 425A1146 */  mul.s      $f9, $f11, $f17
    /* 2DAEAC 003DAEAC 34900946 */  c.lt.s     $f18, $f9
    /* 2DAEB0 003DAEB0 5FFD0045 */  bc1f       .L003DA430
    /* 2DAEB4 003DAEB4 00000000 */   nop
    /* 2DAEB8 003DAEB8 426A1146 */  mul.s      $f9, $f13, $f17
    /* 2DAEBC 003DAEBC 36900946 */  c.le.s     $f18, $f9
    /* 2DAEC0 003DAEC0 5BFD0145 */  bc1t       .L003DA430
    /* 2DAEC4 003DAEC4 00000000 */   nop
    /* 2DAEC8 003DAEC8 A9000010 */  b          .L003DB170
    /* 2DAECC 003DAECC 01000224 */   addiu     $2, $0, 0x1
  .L003DAED0:
    /* 2DAED0 003DAED0 82541146 */  mul.s      $f18, $f10, $f17
    /* 2DAED4 003DAED4 36981246 */  c.le.s     $f19, $f18
    /* 2DAED8 003DAED8 55FD0145 */  bc1t       .L003DA430
    /* 2DAEDC 003DAEDC 00000000 */   nop
    /* 2DAEE0 003DAEE0 82641146 */  mul.s      $f18, $f12, $f17
    /* 2DAEE4 003DAEE4 34981246 */  c.lt.s     $f19, $f18
    /* 2DAEE8 003DAEE8 51FD0045 */  bc1f       .L003DA430
    /* 2DAEEC 003DAEEC 00000000 */   nop
    /* 2DAEF0 003DAEF0 824C1046 */  mul.s      $f18, $f9, $f16
    /* 2DAEF4 003DAEF4 425A1146 */  mul.s      $f9, $f11, $f17
    /* 2DAEF8 003DAEF8 36900946 */  c.le.s     $f18, $f9
    /* 2DAEFC 003DAEFC 4CFD0145 */  bc1t       .L003DA430
    /* 2DAF00 003DAF00 00000000 */   nop
    /* 2DAF04 003DAF04 426A1146 */  mul.s      $f9, $f13, $f17
    /* 2DAF08 003DAF08 34900946 */  c.lt.s     $f18, $f9
    /* 2DAF0C 003DAF0C 48FD0045 */  bc1f       .L003DA430
    /* 2DAF10 003DAF10 00000000 */   nop
    /* 2DAF14 003DAF14 96000010 */  b          .L003DB170
    /* 2DAF18 003DAF18 01000224 */   addiu     $2, $0, 0x1
  .L003DAF1C:
    /* 2DAF1C 003DAF1C 810A0446 */  sub.s      $f10, $f1, $f4
    /* 2DAF20 003DAF20 1400A727 */  addiu      $7, $29, 0x14
    /* 2DAF24 003DAF24 1800A627 */  addiu      $6, $29, 0x18
    /* 2DAF28 003DAF28 81310346 */  sub.s      $f6, $f6, $f3
    /* 2DAF2C 003DAF2C 41120546 */  sub.s      $f9, $f2, $f5
    /* 2DAF30 003DAF30 01420446 */  sub.s      $f8, $f8, $f4
    /* 2DAF34 003DAF34 C1020346 */  sub.s      $f11, $f0, $f3
    /* 2DAF38 003DAF38 1A500646 */  mula.s     $f10, $f6
    /* 2DAF3C 003DAF3C 1D580846 */  msub.s     $f0, $f11, $f8
    /* 2DAF40 003DAF40 C1390546 */  sub.s      $f7, $f7, $f5
    /* 2DAF44 003DAF44 1000A0E7 */  swc1       $f0, 0x10($29)
    /* 2DAF48 003DAF48 1A580746 */  mula.s     $f11, $f7
    /* 2DAF4C 003DAF4C 1000A38F */  lw         $3, 0x10($29)
    /* 2DAF50 003DAF50 1D480646 */  msub.s     $f0, $f9, $f6
    /* 2DAF54 003DAF54 0000E0E4 */  swc1       $f0, 0x0($7)
    /* 2DAF58 003DAF58 1A480846 */  mula.s     $f9, $f8
    /* 2DAF5C 003DAF5C 0000E28C */  lw         $2, 0x0($7)
    /* 2DAF60 003DAF60 1D500746 */  msub.s     $f0, $f10, $f7
    /* 2DAF64 003DAF64 0000C0E4 */  swc1       $f0, 0x0($6)
    /* 2DAF68 003DAF68 0C0082C4 */  lwc1       $f2, 0xC($4)
    /* 2DAF6C 003DAF6C 000081C4 */  lwc1       $f1, 0x0($4)
    /* 2DAF70 003DAF70 0000A0C4 */  lwc1       $f0, 0x0($5)
    /* 2DAF74 003DAF74 26106200 */  xor        $2, $3, $2
    /* 2DAF78 003DAF78 01090246 */  sub.s      $f4, $f1, $f2
    /* 2DAF7C 003DAF7C 70004004 */  bltz       $2, .L003DB140
    /* 2DAF80 003DAF80 81100046 */   sub.s     $f2, $f2, $f0
    /* 2DAF84 003DAF84 100083C4 */  lwc1       $f3, 0x10($4)
    /* 2DAF88 003DAF88 040081C4 */  lwc1       $f1, 0x4($4)
    /* 2DAF8C 003DAF8C 0400A0C4 */  lwc1       $f0, 0x4($5)
    /* 2DAF90 003DAF90 41090346 */  sub.s      $f5, $f1, $f3
    /* 2DAF94 003DAF94 C1180046 */  sub.s      $f3, $f3, $f0
  .L003DAF98:
    /* 2DAF98 003DAF98 0000C28C */  lw         $2, 0x0($6)
    /* 2DAF9C 003DAF9C 26106200 */  xor        $2, $3, $2
    /* 2DAFA0 003DAFA0 6D004004 */  bltz       $2, .L003DB158
    /* 2DAFA4 003DAFA4 00000000 */   nop
    /* 2DAFA8 003DAFA8 0800A0C4 */  lwc1       $f0, 0x8($5)
    /* 2DAFAC 003DAFAC 14008CC4 */  lwc1       $f12, 0x14($4)
    /* 2DAFB0 003DAFB0 080081C4 */  lwc1       $f1, 0x8($4)
    /* 2DAFB4 003DAFB4 C1630046 */  sub.s      $f15, $f12, $f0
    /* 2DAFB8 003DAFB8 010C0C46 */  sub.s      $f16, $f1, $f12
  .L003DAFBC:
    /* 2DAFBC 003DAFBC 0000EEC4 */  lwc1       $f14, 0x0($7)
    /* 2DAFC0 003DAFC0 1000ACC7 */  lwc1       $f12, 0x10($29)
    /* 2DAFC4 003DAFC4 0000CDC4 */  lwc1       $f13, 0x0($6)
    /* 2DAFC8 003DAFC8 00088044 */  mtc1       $0, $f1
    /* 2DAFCC 003DAFCC 1A280E46 */  mula.s     $f5, $f14
    /* 2DAFD0 003DAFD0 1E200C46 */  madda.s    $f4, $f12
    /* 2DAFD4 003DAFD4 1C800D46 */  madd.s     $f0, $f16, $f13
    /* 2DAFD8 003DAFD8 07000046 */  neg.s      $f0, $f0
    /* 2DAFDC 003DAFDC 1A180E46 */  mula.s     $f3, $f14
    /* 2DAFE0 003DAFE0 1E100C46 */  madda.s    $f2, $f12
    /* 2DAFE4 003DAFE4 34000146 */  c.lt.s     $f0, $f1
    /* 2DAFE8 003DAFE8 2A000045 */  bc1f       .L003DB094
    /* 2DAFEC 003DAFEC 1C7B0D46 */   madd.s    $f12, $f15, $f13
    /* 2DAFF0 003DAFF0 36080C46 */  c.le.s     $f1, $f12
    /* 2DAFF4 003DAFF4 50000145 */  bc1t       .L003DB138
    /* 2DAFF8 003DAFF8 00000000 */   nop
    /* 2DAFFC 003DAFFC 36600046 */  c.le.s     $f12, $f0
    /* 2DB000 003DB000 4D000145 */  bc1t       .L003DB138
    /* 2DB004 003DB004 00000000 */   nop
    /* 2DB008 003DB008 021B1046 */  mul.s      $f12, $f3, $f16
    /* 2DB00C 003DB00C 18080C46 */  adda.s     $f1, $f12
    /* 2DB010 003DB010 027B0446 */  mul.s      $f12, $f15, $f4
    /* 2DB014 003DB014 5D7B0546 */  msub.s     $f13, $f15, $f5
    /* 2DB018 003DB018 18080C46 */  adda.s     $f1, $f12
    /* 2DB01C 003DB01C 1D131046 */  msub.s     $f12, $f2, $f16
    /* 2DB020 003DB020 82100546 */  mul.s      $f2, $f2, $f5
    /* 2DB024 003DB024 18080246 */  adda.s     $f1, $f2
    /* 2DB028 003DB028 82400C46 */  mul.s      $f2, $f8, $f12
    /* 2DB02C 003DB02C 1D190446 */  msub.s     $f4, $f3, $f4
    /* 2DB030 003DB030 18080246 */  adda.s     $f1, $f2
    /* 2DB034 003DB034 9C380D46 */  madd.s     $f2, $f7, $f13
    /* 2DB038 003DB038 18080246 */  adda.s     $f1, $f2
    /* 2DB03C 003DB03C DC300446 */  madd.s     $f3, $f6, $f4
    /* 2DB040 003DB040 36080346 */  c.le.s     $f1, $f3
    /* 2DB044 003DB044 3C000145 */  bc1t       .L003DB138
    /* 2DB048 003DB048 00000000 */   nop
    /* 2DB04C 003DB04C 36180046 */  c.le.s     $f3, $f0
    /* 2DB050 003DB050 39000145 */  bc1t       .L003DB138
    /* 2DB054 003DB054 00000000 */   nop
    /* 2DB058 003DB058 82500C46 */  mul.s      $f2, $f10, $f12
    /* 2DB05C 003DB05C 18080246 */  adda.s     $f1, $f2
    /* 2DB060 003DB060 9C480D46 */  madd.s     $f2, $f9, $f13
    /* 2DB064 003DB064 18080246 */  adda.s     $f1, $f2
    /* 2DB068 003DB068 9C580446 */  madd.s     $f2, $f11, $f4
    /* 2DB06C 003DB06C 87100046 */  neg.s      $f2, $f2
    /* 2DB070 003DB070 36080246 */  c.le.s     $f1, $f2
    /* 2DB074 003DB074 30000145 */  bc1t       .L003DB138
    /* 2DB078 003DB078 00000000 */   nop
    /* 2DB07C 003DB07C 40180246 */  add.s      $f1, $f3, $f2
    /* 2DB080 003DB080 36080046 */  c.le.s     $f1, $f0
    /* 2DB084 003DB084 2C000145 */  bc1t       .L003DB138
    /* 2DB088 003DB088 00000000 */   nop
    /* 2DB08C 003DB08C 38000010 */  b          .L003DB170
    /* 2DB090 003DB090 01000224 */   addiu     $2, $0, 0x1
  .L003DB094:
    /* 2DB094 003DB094 34080C46 */  c.lt.s     $f1, $f12
    /* 2DB098 003DB098 27000045 */  bc1f       .L003DB138
    /* 2DB09C 003DB09C 00000000 */   nop
    /* 2DB0A0 003DB0A0 34600046 */  c.lt.s     $f12, $f0
    /* 2DB0A4 003DB0A4 24000045 */  bc1f       .L003DB138
    /* 2DB0A8 003DB0A8 00000000 */   nop
    /* 2DB0AC 003DB0AC 021B1046 */  mul.s      $f12, $f3, $f16
    /* 2DB0B0 003DB0B0 18080C46 */  adda.s     $f1, $f12
    /* 2DB0B4 003DB0B4 027B0446 */  mul.s      $f12, $f15, $f4
    /* 2DB0B8 003DB0B8 5D7B0546 */  msub.s     $f13, $f15, $f5
    /* 2DB0BC 003DB0BC 18080C46 */  adda.s     $f1, $f12
    /* 2DB0C0 003DB0C0 1D131046 */  msub.s     $f12, $f2, $f16
    /* 2DB0C4 003DB0C4 82100546 */  mul.s      $f2, $f2, $f5
    /* 2DB0C8 003DB0C8 18080246 */  adda.s     $f1, $f2
    /* 2DB0CC 003DB0CC 82400C46 */  mul.s      $f2, $f8, $f12
    /* 2DB0D0 003DB0D0 1D190446 */  msub.s     $f4, $f3, $f4
    /* 2DB0D4 003DB0D4 18080246 */  adda.s     $f1, $f2
    /* 2DB0D8 003DB0D8 9C380D46 */  madd.s     $f2, $f7, $f13
    /* 2DB0DC 003DB0DC 18080246 */  adda.s     $f1, $f2
    /* 2DB0E0 003DB0E0 DC300446 */  madd.s     $f3, $f6, $f4
    /* 2DB0E4 003DB0E4 34080346 */  c.lt.s     $f1, $f3
    /* 2DB0E8 003DB0E8 13000045 */  bc1f       .L003DB138
    /* 2DB0EC 003DB0EC 00000000 */   nop
    /* 2DB0F0 003DB0F0 34180046 */  c.lt.s     $f3, $f0
    /* 2DB0F4 003DB0F4 10000045 */  bc1f       .L003DB138
    /* 2DB0F8 003DB0F8 00000000 */   nop
    /* 2DB0FC 003DB0FC 82500C46 */  mul.s      $f2, $f10, $f12
    /* 2DB100 003DB100 18080246 */  adda.s     $f1, $f2
    /* 2DB104 003DB104 9C480D46 */  madd.s     $f2, $f9, $f13
    /* 2DB108 003DB108 18080246 */  adda.s     $f1, $f2
    /* 2DB10C 003DB10C 9C580446 */  madd.s     $f2, $f11, $f4
    /* 2DB110 003DB110 87100046 */  neg.s      $f2, $f2
    /* 2DB114 003DB114 34080246 */  c.lt.s     $f1, $f2
    /* 2DB118 003DB118 07000045 */  bc1f       .L003DB138
    /* 2DB11C 003DB11C 00000000 */   nop
    /* 2DB120 003DB120 40180246 */  add.s      $f1, $f3, $f2
    /* 2DB124 003DB124 34080046 */  c.lt.s     $f1, $f0
    /* 2DB128 003DB128 03000045 */  bc1f       .L003DB138
    /* 2DB12C 003DB12C 00000000 */   nop
    /* 2DB130 003DB130 0F000010 */  b          .L003DB170
    /* 2DB134 003DB134 01000224 */   addiu     $2, $0, 0x1
  .L003DB138:
    /* 2DB138 003DB138 0D000010 */  b          .L003DB170
    /* 2DB13C 003DB13C 2D100000 */   daddu     $2, $0, $0
  .L003DB140:
    /* 2DB140 003DB140 040083C4 */  lwc1       $f3, 0x4($4)
    /* 2DB144 003DB144 100081C4 */  lwc1       $f1, 0x10($4)
    /* 2DB148 003DB148 0400A0C4 */  lwc1       $f0, 0x4($5)
    /* 2DB14C 003DB14C 41090346 */  sub.s      $f5, $f1, $f3
    /* 2DB150 003DB150 91FF0010 */  b          .L003DAF98
    /* 2DB154 003DB154 C1180046 */   sub.s     $f3, $f3, $f0
  .L003DB158:
    /* 2DB158 003DB158 0800A0C4 */  lwc1       $f0, 0x8($5)
    /* 2DB15C 003DB15C 08008CC4 */  lwc1       $f12, 0x8($4)
    /* 2DB160 003DB160 140081C4 */  lwc1       $f1, 0x14($4)
    /* 2DB164 003DB164 C1630046 */  sub.s      $f15, $f12, $f0
    /* 2DB168 003DB168 94FF0010 */  b          .L003DAFBC
    /* 2DB16C 003DB16C 010C0C46 */   sub.s     $f16, $f1, $f12
  .L003DB170:
    /* 2DB170 003DB170 0800B6C7 */  lwc1       $f22, 0x8($29)
    /* 2DB174 003DB174 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* 2DB178 003DB178 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 2DB17C 003DB17C 0800E003 */  jr         $31
    /* 2DB180 003DB180 2000BD27 */   addiu     $29, $29, 0x20
    /* 2DB184 003DB184 00000000 */  nop
    /* 2DB188 003DB188 00000000 */  nop
    /* 2DB18C 003DB18C 00000000 */  nop
.size func_003d9f30, 0x1260
