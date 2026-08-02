.section .text
.set noat
.set noreorder
glabel func_002da0a0
    /* 1DA0A0 002DA0A0 A0FEBD27 */  addiu      $29, $29, -0x160
    /* 1DA0A4 002DA0A4 6000BFFF */  sd         $31, 0x60($29)
    /* 1DA0A8 002DA0A8 5000B47F */  sq         $20, 0x50($29)
    /* 1DA0AC 002DA0AC 4000B37F */  sq         $19, 0x40($29)
    /* 1DA0B0 002DA0B0 3000B27F */  sq         $18, 0x30($29)
    /* 1DA0B4 002DA0B4 2000B17F */  sq         $17, 0x20($29)
    /* 1DA0B8 002DA0B8 1000B07F */  sq         $16, 0x10($29)
    /* 1DA0BC 002DA0BC 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 1DA0C0 002DA0C0 2D908000 */  daddu      $18, $4, $0
    /* 1DA0C4 002DA0C4 3800908C */  lw         $16, 0x38($4)
    /* 1DA0C8 002DA0C8 EC0D048E */  lw         $4, 0xDEC($16)
    /* 1DA0CC 002DA0CC 2D280000 */  daddu      $5, $0, $0
    /* 1DA0D0 002DA0D0 01000624 */  addiu      $6, $0, 0x1
    /* 1DA0D4 002DA0D4 3C810B0C */  jal        func_002e04f0
    /* 1DA0D8 002DA0D8 00000000 */   nop
    /* 1DA0DC 002DA0DC 6400113C */  lui        $17, %hi(D_0063F5A0)
    /* 1DA0E0 002DA0E0 A0F53126 */  addiu      $17, $17, %lo(D_0063F5A0)
    /* 1DA0E4 002DA0E4 2243023C */  lui        $2, (0x43220000 >> 16)
    /* 1DA0E8 002DA0E8 00608244 */  mtc1       $2, $f12
    /* 1DA0EC 002DA0EC 580C048E */  lw         $4, 0xC58($16)
    /* 1DA0F0 002DA0F0 41000524 */  addiu      $5, $0, 0x41
    /* 1DA0F4 002DA0F4 78820B0C */  jal        func_002e09e0
    /* 1DA0F8 002DA0F8 00000000 */   nop
    /* 1DA0FC 002DA0FC 040021C6 */  lwc1       $f1, 0x4($17)
    /* 1DA100 002DA100 E143023C */  lui        $2, (0x43E10000 >> 16)
    /* 1DA104 002DA104 00008244 */  mtc1       $2, $f0
    /* 1DA108 002DA108 00000000 */  nop
    /* 1DA10C 002DA10C 410B0046 */  sub.s      $f13, $f1, $f0
    /* 1DA110 002DA110 2801A427 */  addiu      $4, $29, 0x128
    /* 1DA114 002DA114 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1DA118 002DA118 5CCA0A0C */  jal        func_002b2970
    /* 1DA11C 002DA11C 00000000 */   nop
    /* 1DA120 002DA120 2001A427 */  addiu      $4, $29, 0x120
    /* 1DA124 002DA124 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1DA128 002DA128 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1DA12C 002DA12C 5CCA0A0C */  jal        func_002b2970
    /* 1DA130 002DA130 00000000 */   nop
    /* 1DA134 002DA134 580C048E */  lw         $4, 0xC58($16)
    /* 1DA138 002DA138 2801A5DF */  ld         $5, 0x128($29)
    /* 1DA13C 002DA13C 2001A6DF */  ld         $6, 0x120($29)
    /* 1DA140 002DA140 2D380000 */  daddu      $7, $0, $0
    /* 1DA144 002DA144 04000824 */  addiu      $8, $0, 0x4
    /* 1DA148 002DA148 2D480000 */  daddu      $9, $0, $0
    /* 1DA14C 002DA14C 88810B0C */  jal        func_002e0620
    /* 1DA150 002DA150 00000000 */   nop
    /* 1DA154 002DA154 580C048E */  lw         $4, 0xC58($16)
    /* 1DA158 002DA158 2D280000 */  daddu      $5, $0, $0
    /* 1DA15C 002DA15C CC000624 */  addiu      $6, $0, 0xCC
    /* 1DA160 002DA160 2D380000 */  daddu      $7, $0, $0
    /* 1DA164 002DA164 02000824 */  addiu      $8, $0, 0x2
    /* 1DA168 002DA168 2D480000 */  daddu      $9, $0, $0
    /* 1DA16C 002DA16C 98810B0C */  jal        func_002e0660
    /* 1DA170 002DA170 00000000 */   nop
    /* 1DA174 002DA174 5C01A427 */  addiu      $4, $29, 0x15C
    /* 1DA178 002DA178 2D280000 */  daddu      $5, $0, $0
    /* 1DA17C 002DA17C 2D300000 */  daddu      $6, $0, $0
    /* 1DA180 002DA180 2D380000 */  daddu      $7, $0, $0
    /* 1DA184 002DA184 FF000824 */  addiu      $8, $0, 0xFF
    /* 1DA188 002DA188 98CA0A0C */  jal        func_002b2a60
    /* 1DA18C 002DA18C 00000000 */   nop
    /* 1DA190 002DA190 580C048E */  lw         $4, 0xC58($16)
    /* 1DA194 002DA194 38810B0C */  jal        func_002e04e0
    /* 1DA198 002DA198 00000000 */   nop
    /* 1DA19C 002DA19C 5C01A693 */  lbu        $6, 0x15C($29)
    /* 1DA1A0 002DA1A0 5D01A593 */  lbu        $5, 0x15D($29)
    /* 1DA1A4 002DA1A4 5E01A493 */  lbu        $4, 0x15E($29)
    /* 1DA1A8 002DA1A8 5F01A393 */  lbu        $3, 0x15F($29)
    /* 1DA1AC 002DA1AC 790046A0 */  sb         $6, 0x79($2)
    /* 1DA1B0 002DA1B0 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DA1B4 002DA1B4 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DA1B8 002DA1B8 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DA1BC 002DA1BC 6400113C */  lui        $17, %hi(D_0063F5A8)
    /* 1DA1C0 002DA1C0 A8F53126 */  addiu      $17, $17, %lo(D_0063F5A8)
    /* 1DA1C4 002DA1C4 2343023C */  lui        $2, (0x43230000 >> 16)
    /* 1DA1C8 002DA1C8 00608244 */  mtc1       $2, $f12
    /* 1DA1CC 002DA1CC 5C0C048E */  lw         $4, 0xC5C($16)
    /* 1DA1D0 002DA1D0 41000524 */  addiu      $5, $0, 0x41
    /* 1DA1D4 002DA1D4 78820B0C */  jal        func_002e09e0
    /* 1DA1D8 002DA1D8 00000000 */   nop
    /* 1DA1DC 002DA1DC 040021C6 */  lwc1       $f1, 0x4($17)
    /* 1DA1E0 002DA1E0 E143023C */  lui        $2, (0x43E10000 >> 16)
    /* 1DA1E4 002DA1E4 00008244 */  mtc1       $2, $f0
    /* 1DA1E8 002DA1E8 00000000 */  nop
    /* 1DA1EC 002DA1EC 410B0046 */  sub.s      $f13, $f1, $f0
    /* 1DA1F0 002DA1F0 1801A427 */  addiu      $4, $29, 0x118
    /* 1DA1F4 002DA1F4 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1DA1F8 002DA1F8 5CCA0A0C */  jal        func_002b2970
    /* 1DA1FC 002DA1FC 00000000 */   nop
    /* 1DA200 002DA200 1001A427 */  addiu      $4, $29, 0x110
    /* 1DA204 002DA204 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1DA208 002DA208 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1DA20C 002DA20C 5CCA0A0C */  jal        func_002b2970
    /* 1DA210 002DA210 00000000 */   nop
    /* 1DA214 002DA214 5C0C048E */  lw         $4, 0xC5C($16)
    /* 1DA218 002DA218 1801A5DF */  ld         $5, 0x118($29)
    /* 1DA21C 002DA21C 1001A6DF */  ld         $6, 0x110($29)
    /* 1DA220 002DA220 2D380000 */  daddu      $7, $0, $0
    /* 1DA224 002DA224 04000824 */  addiu      $8, $0, 0x4
    /* 1DA228 002DA228 2D480000 */  daddu      $9, $0, $0
    /* 1DA22C 002DA22C 88810B0C */  jal        func_002e0620
    /* 1DA230 002DA230 00000000 */   nop
    /* 1DA234 002DA234 5C0C048E */  lw         $4, 0xC5C($16)
    /* 1DA238 002DA238 2D280000 */  daddu      $5, $0, $0
    /* 1DA23C 002DA23C CC000624 */  addiu      $6, $0, 0xCC
    /* 1DA240 002DA240 2D380000 */  daddu      $7, $0, $0
    /* 1DA244 002DA244 02000824 */  addiu      $8, $0, 0x2
    /* 1DA248 002DA248 2D480000 */  daddu      $9, $0, $0
    /* 1DA24C 002DA24C 98810B0C */  jal        func_002e0660
    /* 1DA250 002DA250 00000000 */   nop
    /* 1DA254 002DA254 5801A427 */  addiu      $4, $29, 0x158
    /* 1DA258 002DA258 2D280000 */  daddu      $5, $0, $0
    /* 1DA25C 002DA25C 2D300000 */  daddu      $6, $0, $0
    /* 1DA260 002DA260 2D380000 */  daddu      $7, $0, $0
    /* 1DA264 002DA264 FF000824 */  addiu      $8, $0, 0xFF
    /* 1DA268 002DA268 98CA0A0C */  jal        func_002b2a60
    /* 1DA26C 002DA26C 00000000 */   nop
    /* 1DA270 002DA270 5C0C048E */  lw         $4, 0xC5C($16)
    /* 1DA274 002DA274 38810B0C */  jal        func_002e04e0
    /* 1DA278 002DA278 00000000 */   nop
    /* 1DA27C 002DA27C 5801A693 */  lbu        $6, 0x158($29)
    /* 1DA280 002DA280 5901A593 */  lbu        $5, 0x159($29)
    /* 1DA284 002DA284 5A01A493 */  lbu        $4, 0x15A($29)
    /* 1DA288 002DA288 5B01A393 */  lbu        $3, 0x15B($29)
    /* 1DA28C 002DA28C 790046A0 */  sb         $6, 0x79($2)
    /* 1DA290 002DA290 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DA294 002DA294 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DA298 002DA298 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DA29C 002DA29C 2D200000 */  daddu      $4, $0, $0
    /* 1DA2A0 002DA2A0 0C000010 */  b          .L002DA2D4
    /* 1DA2A4 002DA2A4 00000000 */   nop
  .L002DA2A8:
    /* 1DA2A8 002DA2A8 3C1C0400 */  dsll32     $3, $4, 16
    /* 1DA2AC 002DA2AC 3F1C0300 */  dsra32     $3, $3, 16
    /* 1DA2B0 002DA2B0 40100300 */  sll        $2, $3, 1
    /* 1DA2B4 002DA2B4 21100202 */  addu       $2, $16, $2
    /* 1DA2B8 002DA2B8 460F40A4 */  sh         $0, 0xF46($2)
    /* 1DA2BC 002DA2BC 580F40A4 */  sh         $0, 0xF58($2)
    /* 1DA2C0 002DA2C0 21100302 */  addu       $2, $16, $3
    /* 1DA2C4 002DA2C4 6A0F40A0 */  sb         $0, 0xF6A($2)
    /* 1DA2C8 002DA2C8 01008224 */  addiu      $2, $4, 0x1
    /* 1DA2CC 002DA2CC 3C240200 */  dsll32     $4, $2, 16
    /* 1DA2D0 002DA2D0 3F240400 */  dsra32     $4, $4, 16
  .L002DA2D4:
    /* 1DA2D4 002DA2D4 3C1C0400 */  dsll32     $3, $4, 16
    /* 1DA2D8 002DA2D8 3F1C0300 */  dsra32     $3, $3, 16
    /* 1DA2DC 002DA2DC 09000282 */  lb         $2, 0x9($16)
    /* 1DA2E0 002DA2E0 2A106200 */  slt        $2, $3, $2
    /* 1DA2E4 002DA2E4 F0FF4014 */  bnez       $2, .L002DA2A8
    /* 1DA2E8 002DA2E8 00000000 */   nop
    /* 1DA2EC 002DA2EC FC42023C */  lui        $2, (0x42FC0000 >> 16)
    /* 1DA2F0 002DA2F0 00608244 */  mtc1       $2, $f12
    /* 1DA2F4 002DA2F4 D40E048E */  lw         $4, 0xED4($16)
    /* 1DA2F8 002DA2F8 41000524 */  addiu      $5, $0, 0x41
    /* 1DA2FC 002DA2FC 78820B0C */  jal        func_002e09e0
    /* 1DA300 002DA300 00000000 */   nop
    /* 1DA304 002DA304 08001182 */  lb         $17, 0x8($16)
    /* 1DA308 002DA308 00009144 */  mtc1       $17, $f0
    /* 1DA30C 002DA30C 00000000 */  nop
    /* 1DA310 002DA310 E0008046 */  cvt.s.w    $f3, $f0
    /* 1DA314 002DA314 0C42023C */  lui        $2, (0x420C0000 >> 16)
    /* 1DA318 002DA318 00108244 */  mtc1       $2, $f2
    /* 1DA31C 002DA31C 9C42023C */  lui        $2, (0x429C0000 >> 16)
    /* 1DA320 002DA320 00088244 */  mtc1       $2, $f1
    /* 1DA324 002DA324 00008044 */  mtc1       $0, $f0
    /* 1DA328 002DA328 00000000 */  nop
    /* 1DA32C 002DA32C 18000146 */  adda.s     $f0, $f1
    /* 1DA330 002DA330 5C100346 */  madd.s     $f1, $f2, $f3
    /* 1DA334 002DA334 E143023C */  lui        $2, (0x43E10000 >> 16)
    /* 1DA338 002DA338 00008244 */  mtc1       $2, $f0
    /* 1DA33C 002DA33C 00000000 */  nop
    /* 1DA340 002DA340 410B0046 */  sub.s      $f13, $f1, $f0
    /* 1DA344 002DA344 3C42023C */  lui        $2, (0x423C0000 >> 16)
    /* 1DA348 002DA348 00608244 */  mtc1       $2, $f12
    /* 1DA34C 002DA34C 0801A427 */  addiu      $4, $29, 0x108
    /* 1DA350 002DA350 5CCA0A0C */  jal        func_002b2970
    /* 1DA354 002DA354 00000000 */   nop
    /* 1DA358 002DA358 0C42023C */  lui        $2, (0x420C0000 >> 16)
    /* 1DA35C 002DA35C 00188244 */  mtc1       $2, $f3
    /* 1DA360 002DA360 00009144 */  mtc1       $17, $f0
    /* 1DA364 002DA364 00000000 */  nop
    /* 1DA368 002DA368 A0008046 */  cvt.s.w    $f2, $f0
    /* 1DA36C 002DA36C 9C42023C */  lui        $2, (0x429C0000 >> 16)
    /* 1DA370 002DA370 00088244 */  mtc1       $2, $f1
    /* 1DA374 002DA374 00008044 */  mtc1       $0, $f0
    /* 1DA378 002DA378 00000000 */  nop
    /* 1DA37C 002DA37C 18000146 */  adda.s     $f0, $f1
    /* 1DA380 002DA380 5C1B0246 */  madd.s     $f13, $f3, $f2
    /* 1DA384 002DA384 3C42023C */  lui        $2, (0x423C0000 >> 16)
    /* 1DA388 002DA388 00608244 */  mtc1       $2, $f12
    /* 1DA38C 002DA38C 0001A427 */  addiu      $4, $29, 0x100
    /* 1DA390 002DA390 5CCA0A0C */  jal        func_002b2970
    /* 1DA394 002DA394 00000000 */   nop
    /* 1DA398 002DA398 3C161100 */  dsll32     $2, $17, 24
    /* 1DA39C 002DA39C 3F160200 */  dsra32     $2, $2, 24
    /* 1DA3A0 002DA3A0 40100200 */  sll        $2, $2, 1
    /* 1DA3A4 002DA3A4 21105000 */  addu       $2, $2, $16
    /* 1DA3A8 002DA3A8 D40E048E */  lw         $4, 0xED4($16)
    /* 1DA3AC 002DA3AC 0801A5DF */  ld         $5, 0x108($29)
    /* 1DA3B0 002DA3B0 0001A6DF */  ld         $6, 0x100($29)
    /* 1DA3B4 002DA3B4 2D380000 */  daddu      $7, $0, $0
    /* 1DA3B8 002DA3B8 06000824 */  addiu      $8, $0, 0x6
    /* 1DA3BC 002DA3BC 460F4984 */  lh         $9, 0xF46($2)
    /* 1DA3C0 002DA3C0 88810B0C */  jal        func_002e0620
    /* 1DA3C4 002DA3C4 00000000 */   nop
    /* 1DA3C8 002DA3C8 5401A427 */  addiu      $4, $29, 0x154
    /* 1DA3CC 002DA3CC FE000524 */  addiu      $5, $0, 0xFE
    /* 1DA3D0 002DA3D0 C6000624 */  addiu      $6, $0, 0xC6
    /* 1DA3D4 002DA3D4 31000724 */  addiu      $7, $0, 0x31
    /* 1DA3D8 002DA3D8 FF000824 */  addiu      $8, $0, 0xFF
    /* 1DA3DC 002DA3DC 98CA0A0C */  jal        func_002b2a60
    /* 1DA3E0 002DA3E0 00000000 */   nop
    /* 1DA3E4 002DA3E4 D40E048E */  lw         $4, 0xED4($16)
    /* 1DA3E8 002DA3E8 38810B0C */  jal        func_002e04e0
    /* 1DA3EC 002DA3EC 00000000 */   nop
    /* 1DA3F0 002DA3F0 5401A693 */  lbu        $6, 0x154($29)
    /* 1DA3F4 002DA3F4 5501A593 */  lbu        $5, 0x155($29)
    /* 1DA3F8 002DA3F8 5601A493 */  lbu        $4, 0x156($29)
    /* 1DA3FC 002DA3FC 5701A393 */  lbu        $3, 0x157($29)
    /* 1DA400 002DA400 790046A0 */  sb         $6, 0x79($2)
    /* 1DA404 002DA404 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DA408 002DA408 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DA40C 002DA40C 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DA410 002DA410 FE42023C */  lui        $2, (0x42FE0000 >> 16)
    /* 1DA414 002DA414 00608244 */  mtc1       $2, $f12
    /* 1DA418 002DA418 D80E048E */  lw         $4, 0xED8($16)
    /* 1DA41C 002DA41C 41000524 */  addiu      $5, $0, 0x41
    /* 1DA420 002DA420 78820B0C */  jal        func_002e09e0
    /* 1DA424 002DA424 00000000 */   nop
    /* 1DA428 002DA428 5001A427 */  addiu      $4, $29, 0x150
    /* 1DA42C 002DA42C FE000524 */  addiu      $5, $0, 0xFE
    /* 1DA430 002DA430 C6000624 */  addiu      $6, $0, 0xC6
    /* 1DA434 002DA434 31000724 */  addiu      $7, $0, 0x31
    /* 1DA438 002DA438 FF000824 */  addiu      $8, $0, 0xFF
    /* 1DA43C 002DA43C 98CA0A0C */  jal        func_002b2a60
    /* 1DA440 002DA440 00000000 */   nop
    /* 1DA444 002DA444 D80E048E */  lw         $4, 0xED8($16)
    /* 1DA448 002DA448 38810B0C */  jal        func_002e04e0
    /* 1DA44C 002DA44C 00000000 */   nop
    /* 1DA450 002DA450 5001A693 */  lbu        $6, 0x150($29)
    /* 1DA454 002DA454 5101A593 */  lbu        $5, 0x151($29)
    /* 1DA458 002DA458 5201A493 */  lbu        $4, 0x152($29)
    /* 1DA45C 002DA45C 5301A393 */  lbu        $3, 0x153($29)
    /* 1DA460 002DA460 790046A0 */  sb         $6, 0x79($2)
    /* 1DA464 002DA464 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DA468 002DA468 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DA46C 002DA46C 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DA470 002DA470 08000282 */  lb         $2, 0x8($16)
    /* 1DA474 002DA474 00008244 */  mtc1       $2, $f0
    /* 1DA478 002DA478 00000000 */  nop
    /* 1DA47C 002DA47C E0008046 */  cvt.s.w    $f3, $f0
    /* 1DA480 002DA480 0C42023C */  lui        $2, (0x420C0000 >> 16)
    /* 1DA484 002DA484 00108244 */  mtc1       $2, $f2
    /* 1DA488 002DA488 9C42023C */  lui        $2, (0x429C0000 >> 16)
    /* 1DA48C 002DA48C 00088244 */  mtc1       $2, $f1
    /* 1DA490 002DA490 00008044 */  mtc1       $0, $f0
    /* 1DA494 002DA494 00000000 */  nop
    /* 1DA498 002DA498 18000146 */  adda.s     $f0, $f1
    /* 1DA49C 002DA49C 5C100346 */  madd.s     $f1, $f2, $f3
    /* 1DA4A0 002DA4A0 E143023C */  lui        $2, (0x43E10000 >> 16)
    /* 1DA4A4 002DA4A4 00008244 */  mtc1       $2, $f0
    /* 1DA4A8 002DA4A8 00000000 */  nop
    /* 1DA4AC 002DA4AC 410B0046 */  sub.s      $f13, $f1, $f0
    /* 1DA4B0 002DA4B0 FC42023C */  lui        $2, (0x42FC0000 >> 16)
    /* 1DA4B4 002DA4B4 00608244 */  mtc1       $2, $f12
    /* 1DA4B8 002DA4B8 F800A427 */  addiu      $4, $29, 0xF8
    /* 1DA4BC 002DA4BC 5CCA0A0C */  jal        func_002b2970
    /* 1DA4C0 002DA4C0 00000000 */   nop
    /* 1DA4C4 002DA4C4 08000282 */  lb         $2, 0x8($16)
    /* 1DA4C8 002DA4C8 00008244 */  mtc1       $2, $f0
    /* 1DA4CC 002DA4CC 00000000 */  nop
    /* 1DA4D0 002DA4D0 E0008046 */  cvt.s.w    $f3, $f0
    /* 1DA4D4 002DA4D4 0C42023C */  lui        $2, (0x420C0000 >> 16)
    /* 1DA4D8 002DA4D8 00108244 */  mtc1       $2, $f2
    /* 1DA4DC 002DA4DC 9C42023C */  lui        $2, (0x429C0000 >> 16)
    /* 1DA4E0 002DA4E0 00088244 */  mtc1       $2, $f1
    /* 1DA4E4 002DA4E4 00008044 */  mtc1       $0, $f0
    /* 1DA4E8 002DA4E8 00000000 */  nop
    /* 1DA4EC 002DA4EC 18000146 */  adda.s     $f0, $f1
    /* 1DA4F0 002DA4F0 5C130346 */  madd.s     $f13, $f2, $f3
    /* 1DA4F4 002DA4F4 FC42023C */  lui        $2, (0x42FC0000 >> 16)
    /* 1DA4F8 002DA4F8 00608244 */  mtc1       $2, $f12
    /* 1DA4FC 002DA4FC F000A427 */  addiu      $4, $29, 0xF0
    /* 1DA500 002DA500 5CCA0A0C */  jal        func_002b2970
    /* 1DA504 002DA504 00000000 */   nop
    /* 1DA508 002DA508 D80E048E */  lw         $4, 0xED8($16)
    /* 1DA50C 002DA50C F800A5DF */  ld         $5, 0xF8($29)
    /* 1DA510 002DA510 F000A6DF */  ld         $6, 0xF0($29)
    /* 1DA514 002DA514 2D380000 */  daddu      $7, $0, $0
    /* 1DA518 002DA518 06000824 */  addiu      $8, $0, 0x6
    /* 1DA51C 002DA51C 2D480000 */  daddu      $9, $0, $0
    /* 1DA520 002DA520 88810B0C */  jal        func_002e0620
    /* 1DA524 002DA524 00000000 */   nop
    /* 1DA528 002DA528 3800528E */  lw         $18, 0x38($18)
    /* 1DA52C 002DA52C 280F448E */  lw         $4, 0xF28($18)
    /* 1DA530 002DA530 04000524 */  addiu      $5, $0, 0x4
    /* 1DA534 002DA534 80B4110C */  jal        func_0046d200
    /* 1DA538 002DA538 00000000 */   nop
    /* 1DA53C 002DA53C 2D984000 */  daddu      $19, $2, $0
    /* 1DA540 002DA540 2D206002 */  daddu      $4, $19, $0
    /* 1DA544 002DA544 98AC110C */  jal        func_0046b260
    /* 1DA548 002DA548 00000000 */   nop
    /* 1DA54C 002DA54C 9E42023C */  lui        $2, (0x429E0000 >> 16)
    /* 1DA550 002DA550 00088244 */  mtc1       $2, $f1
    /* 1DA554 002DA554 00000000 */  nop
    /* 1DA558 002DA558 40080046 */  add.s      $f1, $f1, $f0
    /* 1DA55C 002DA55C 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1DA560 002DA560 00008244 */  mtc1       $2, $f0
    /* 1DA564 002DA564 00000000 */  nop
    /* 1DA568 002DA568 03080046 */  div.s      $f0, $f1, $f0
    /* 1DA56C 002DA56C 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1DA570 002DA570 00000244 */  mfc1       $2, $f0
    /* 1DA574 002DA574 00000000 */  nop
    /* 1DA578 002DA578 3C8C0200 */  dsll32     $17, $2, 16
    /* 1DA57C 002DA57C 3F8C1100 */  dsra32     $17, $17, 16
    /* 1DA580 002DA580 D40E448E */  lw         $4, 0xED4($18)
    /* 1DA584 002DA584 38810B0C */  jal        func_002e04e0
    /* 1DA588 002DA588 00000000 */   nop
    /* 1DA58C 002DA58C 000151A4 */  sh         $17, 0x100($2)
    /* 1DA590 002DA590 2D206002 */  daddu      $4, $19, $0
    /* 1DA594 002DA594 BCAC110C */  jal        func_0046b2f0
    /* 1DA598 002DA598 00000000 */   nop
    /* 1DA59C 002DA59C 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1DA5A0 002DA5A0 00088244 */  mtc1       $2, $f1
    /* 1DA5A4 002DA5A4 00000000 */  nop
    /* 1DA5A8 002DA5A8 03000146 */  div.s      $f0, $f0, $f1
    /* 1DA5AC 002DA5AC 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1DA5B0 002DA5B0 00000244 */  mfc1       $2, $f0
    /* 1DA5B4 002DA5B4 00000000 */  nop
    /* 1DA5B8 002DA5B8 3CA40200 */  dsll32     $20, $2, 16
    /* 1DA5BC 002DA5BC 3FA41400 */  dsra32     $20, $20, 16
    /* 1DA5C0 002DA5C0 D40E448E */  lw         $4, 0xED4($18)
    /* 1DA5C4 002DA5C4 38810B0C */  jal        func_002e04e0
    /* 1DA5C8 002DA5C8 00000000 */   nop
    /* 1DA5CC 002DA5CC 020154A4 */  sh         $20, 0x102($2)
    /* 1DA5D0 002DA5D0 3C141100 */  dsll32     $2, $17, 16
    /* 1DA5D4 002DA5D4 3F140200 */  dsra32     $2, $2, 16
    /* 1DA5D8 002DA5D8 B1FF4224 */  addiu      $2, $2, -0x4F
    /* 1DA5DC 002DA5DC 3C8C0200 */  dsll32     $17, $2, 16
    /* 1DA5E0 002DA5E0 3F8C1100 */  dsra32     $17, $17, 16
    /* 1DA5E4 002DA5E4 D80E448E */  lw         $4, 0xED8($18)
    /* 1DA5E8 002DA5E8 38810B0C */  jal        func_002e04e0
    /* 1DA5EC 002DA5EC 00000000 */   nop
    /* 1DA5F0 002DA5F0 000151A4 */  sh         $17, 0x100($2)
    /* 1DA5F4 002DA5F4 2D206002 */  daddu      $4, $19, $0
    /* 1DA5F8 002DA5F8 BCAC110C */  jal        func_0046b2f0
    /* 1DA5FC 002DA5FC 00000000 */   nop
    /* 1DA600 002DA600 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1DA604 002DA604 00088244 */  mtc1       $2, $f1
    /* 1DA608 002DA608 00000000 */  nop
    /* 1DA60C 002DA60C 03000146 */  div.s      $f0, $f0, $f1
    /* 1DA610 002DA610 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1DA614 002DA614 00000244 */  mfc1       $2, $f0
    /* 1DA618 002DA618 00000000 */  nop
    /* 1DA61C 002DA61C 3C8C0200 */  dsll32     $17, $2, 16
    /* 1DA620 002DA620 3F8C1100 */  dsra32     $17, $17, 16
    /* 1DA624 002DA624 D80E448E */  lw         $4, 0xED8($18)
    /* 1DA628 002DA628 38810B0C */  jal        func_002e04e0
    /* 1DA62C 002DA62C 00000000 */   nop
    /* 1DA630 002DA630 020151A4 */  sh         $17, 0x102($2)
    /* 1DA634 002DA634 18DC0E0C */  jal        func_003b7060
    /* 1DA638 002DA638 00000000 */   nop
    /* 1DA63C 002DA63C 14000324 */  addiu      $3, $0, 0x14
    /* 1DA640 002DA640 1B004300 */  divu       $0, $2, $3
    /* 1DA644 002DA644 10100000 */  mfhi       $2
    /* 1DA648 002DA648 06004004 */  bltz       $2, .L002DA664
    /* 1DA64C 002DA64C 00000000 */   nop
    /* 1DA650 002DA650 00008244 */  mtc1       $2, $f0
    /* 1DA654 002DA654 00000000 */  nop
    /* 1DA658 002DA658 60008046 */  cvt.s.w    $f1, $f0
    /* 1DA65C 002DA65C 08000010 */  b          .L002DA680
    /* 1DA660 002DA660 00000000 */   nop
  .L002DA664:
    /* 1DA664 002DA664 42180200 */  srl        $3, $2, 1
    /* 1DA668 002DA668 01004230 */  andi       $2, $2, 0x1
    /* 1DA66C 002DA66C 25186200 */  or         $3, $3, $2
    /* 1DA670 002DA670 00008344 */  mtc1       $3, $f0
    /* 1DA674 002DA674 00000000 */  nop
    /* 1DA678 002DA678 60008046 */  cvt.s.w    $f1, $f0
    /* 1DA67C 002DA67C 40080146 */  add.s      $f1, $f1, $f1
  .L002DA680:
    /* 1DA680 002DA680 2041023C */  lui        $2, (0x41200000 >> 16)
    /* 1DA684 002DA684 00008244 */  mtc1       $2, $f0
    /* 1DA688 002DA688 00000000 */  nop
    /* 1DA68C 002DA68C 43080046 */  div.s      $f1, $f1, $f0
    /* 1DA690 002DA690 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1DA694 002DA694 00008244 */  mtc1       $2, $f0
    /* 1DA698 002DA698 00000000 */  nop
    /* 1DA69C 002DA69C 000D0046 */  add.s      $f20, $f1, $f0
    /* 1DA6A0 002DA6A0 D40E448E */  lw         $4, 0xED4($18)
    /* 1DA6A4 002DA6A4 38810B0C */  jal        func_002e04e0
    /* 1DA6A8 002DA6A8 00000000 */   nop
    /* 1DA6AC 002DA6AC C40041C4 */  lwc1       $f1, 0xC4($2)
    /* 1DA6B0 002DA6B0 00008044 */  mtc1       $0, $f0
    /* 1DA6B4 002DA6B4 00000000 */  nop
    /* 1DA6B8 002DA6B8 36080046 */  c.le.s     $f1, $f0
    /* 1DA6BC 002DA6BC 05000145 */  bc1t       .L002DA6D4
    /* 1DA6C0 002DA6C0 00000000 */   nop
    /* 1DA6C4 002DA6C4 80BF023C */  lui        $2, (0xBF800000 >> 16)
    /* 1DA6C8 002DA6C8 00008244 */  mtc1       $2, $f0
    /* 1DA6CC 002DA6CC 00000000 */  nop
    /* 1DA6D0 002DA6D0 02A50046 */  mul.s      $f20, $f20, $f0
  .L002DA6D4:
    /* 1DA6D4 002DA6D4 00608044 */  mtc1       $0, $f12
    /* 1DA6D8 002DA6D8 D40E448E */  lw         $4, 0xED4($18)
    /* 1DA6DC 002DA6DC 46A30046 */  mov.s      $f13, $f20
    /* 1DA6E0 002DA6E0 2D280000 */  daddu      $5, $0, $0
    /* 1DA6E4 002DA6E4 2D300000 */  daddu      $6, $0, $0
    /* 1DA6E8 002DA6E8 2D380000 */  daddu      $7, $0, $0
    /* 1DA6EC 002DA6EC 50820B0C */  jal        func_002e0940
    /* 1DA6F0 002DA6F0 00000000 */   nop
    /* 1DA6F4 002DA6F4 00608044 */  mtc1       $0, $f12
    /* 1DA6F8 002DA6F8 D80E448E */  lw         $4, 0xED8($18)
    /* 1DA6FC 002DA6FC 46A30046 */  mov.s      $f13, $f20
    /* 1DA700 002DA700 2D280000 */  daddu      $5, $0, $0
    /* 1DA704 002DA704 2D300000 */  daddu      $6, $0, $0
    /* 1DA708 002DA708 2D380000 */  daddu      $7, $0, $0
    /* 1DA70C 002DA70C 50820B0C */  jal        func_002e0940
    /* 1DA710 002DA710 00000000 */   nop
    /* 1DA714 002DA714 2D206002 */  daddu      $4, $19, $0
    /* 1DA718 002DA718 A0B4110C */  jal        func_0046d280
    /* 1DA71C 002DA71C 00000000 */   nop
    /* 1DA720 002DA720 0043023C */  lui        $2, (0x43000000 >> 16)
    /* 1DA724 002DA724 00608244 */  mtc1       $2, $f12
    /* 1DA728 002DA728 3C0D048E */  lw         $4, 0xD3C($16)
    /* 1DA72C 002DA72C 41000524 */  addiu      $5, $0, 0x41
    /* 1DA730 002DA730 78820B0C */  jal        func_002e09e0
    /* 1DA734 002DA734 00000000 */   nop
    /* 1DA738 002DA738 3C0D048E */  lw         $4, 0xD3C($16)
    /* 1DA73C 002DA73C 2D280000 */  daddu      $5, $0, $0
    /* 1DA740 002DA740 FF000624 */  addiu      $6, $0, 0xFF
    /* 1DA744 002DA744 2D380000 */  daddu      $7, $0, $0
    /* 1DA748 002DA748 0A000824 */  addiu      $8, $0, 0xA
    /* 1DA74C 002DA74C 2D480000 */  daddu      $9, $0, $0
    /* 1DA750 002DA750 98810B0C */  jal        func_002e0660
    /* 1DA754 002DA754 00000000 */   nop
    /* 1DA758 002DA758 6400113C */  lui        $17, %hi(D_0063F7B0)
    /* 1DA75C 002DA75C B0F73126 */  addiu      $17, $17, %lo(D_0063F7B0)
    /* 1DA760 002DA760 9C42023C */  lui        $2, (0x429C0000 >> 16)
    /* 1DA764 002DA764 00608244 */  mtc1       $2, $f12
    /* 1DA768 002DA768 600D048E */  lw         $4, 0xD60($16)
    /* 1DA76C 002DA76C 41000524 */  addiu      $5, $0, 0x41
    /* 1DA770 002DA770 78820B0C */  jal        func_002e09e0
    /* 1DA774 002DA774 00000000 */   nop
    /* 1DA778 002DA778 040021C6 */  lwc1       $f1, 0x4($17)
    /* 1DA77C 002DA77C 26020224 */  addiu      $2, $0, 0x226
    /* 1DA780 002DA780 00008244 */  mtc1       $2, $f0
    /* 1DA784 002DA784 00000000 */  nop
    /* 1DA788 002DA788 20008046 */  cvt.s.w    $f0, $f0
    /* 1DA78C 002DA78C 410B0046 */  sub.s      $f13, $f1, $f0
    /* 1DA790 002DA790 E800A427 */  addiu      $4, $29, 0xE8
    /* 1DA794 002DA794 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1DA798 002DA798 5CCA0A0C */  jal        func_002b2970
    /* 1DA79C 002DA79C 00000000 */   nop
    /* 1DA7A0 002DA7A0 E000A427 */  addiu      $4, $29, 0xE0
    /* 1DA7A4 002DA7A4 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1DA7A8 002DA7A8 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1DA7AC 002DA7AC 5CCA0A0C */  jal        func_002b2970
    /* 1DA7B0 002DA7B0 00000000 */   nop
    /* 1DA7B4 002DA7B4 600D048E */  lw         $4, 0xD60($16)
    /* 1DA7B8 002DA7B8 E800A5DF */  ld         $5, 0xE8($29)
    /* 1DA7BC 002DA7BC E000A6DF */  ld         $6, 0xE0($29)
    /* 1DA7C0 002DA7C0 02000724 */  addiu      $7, $0, 0x2
    /* 1DA7C4 002DA7C4 04000824 */  addiu      $8, $0, 0x4
    /* 1DA7C8 002DA7C8 2D480000 */  daddu      $9, $0, $0
    /* 1DA7CC 002DA7CC 88810B0C */  jal        func_002e0620
    /* 1DA7D0 002DA7D0 00000000 */   nop
    /* 1DA7D4 002DA7D4 600D048E */  lw         $4, 0xD60($16)
    /* 1DA7D8 002DA7D8 38810B0C */  jal        func_002e04e0
    /* 1DA7DC 002DA7DC 00000000 */   nop
    /* 1DA7E0 002DA7E0 020140A4 */  sh         $0, 0x102($2)
    /* 1DA7E4 002DA7E4 3C8C0000 */  dsll32     $17, $0, 16
    /* 1DA7E8 002DA7E8 3F8C1100 */  dsra32     $17, $17, 16
    /* 1DA7EC 002DA7EC 600D048E */  lw         $4, 0xD60($16)
    /* 1DA7F0 002DA7F0 38810B0C */  jal        func_002e04e0
    /* 1DA7F4 002DA7F4 00000000 */   nop
    /* 1DA7F8 002DA7F8 000151A4 */  sh         $17, 0x100($2)
    /* 1DA7FC 002DA7FC A0C0023C */  lui        $2, (0xC0A00000 >> 16)
    /* 1DA800 002DA800 00608244 */  mtc1       $2, $f12
    /* 1DA804 002DA804 600D048E */  lw         $4, 0xD60($16)
    /* 1DA808 002DA808 2C858DC7 */  lwc1       $f13, -0x7AD4($28)
    /* 1DA80C 002DA80C 02000524 */  addiu      $5, $0, 0x2
    /* 1DA810 002DA810 2D30A000 */  daddu      $6, $5, $0
    /* 1DA814 002DA814 2D38A000 */  daddu      $7, $5, $0
    /* 1DA818 002DA818 50820B0C */  jal        func_002e0940
    /* 1DA81C 002DA81C 00000000 */   nop
    /* 1DA820 002DA820 4C01A427 */  addiu      $4, $29, 0x14C
    /* 1DA824 002DA824 FF000524 */  addiu      $5, $0, 0xFF
    /* 1DA828 002DA828 96000624 */  addiu      $6, $0, 0x96
    /* 1DA82C 002DA82C 2D380000 */  daddu      $7, $0, $0
    /* 1DA830 002DA830 2D40A000 */  daddu      $8, $5, $0
    /* 1DA834 002DA834 98CA0A0C */  jal        func_002b2a60
    /* 1DA838 002DA838 00000000 */   nop
    /* 1DA83C 002DA83C 600D048E */  lw         $4, 0xD60($16)
    /* 1DA840 002DA840 38810B0C */  jal        func_002e04e0
    /* 1DA844 002DA844 00000000 */   nop
    /* 1DA848 002DA848 4C01A693 */  lbu        $6, 0x14C($29)
    /* 1DA84C 002DA84C 4D01A593 */  lbu        $5, 0x14D($29)
    /* 1DA850 002DA850 4E01A493 */  lbu        $4, 0x14E($29)
    /* 1DA854 002DA854 4F01A393 */  lbu        $3, 0x14F($29)
    /* 1DA858 002DA858 790046A0 */  sb         $6, 0x79($2)
    /* 1DA85C 002DA85C 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DA860 002DA860 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DA864 002DA864 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DA868 002DA868 6400113C */  lui        $17, %hi(D_0063F7B8)
    /* 1DA86C 002DA86C B8F73126 */  addiu      $17, $17, %lo(D_0063F7B8)
    /* 1DA870 002DA870 9C42023C */  lui        $2, (0x429C0000 >> 16)
    /* 1DA874 002DA874 00608244 */  mtc1       $2, $f12
    /* 1DA878 002DA878 640D048E */  lw         $4, 0xD64($16)
    /* 1DA87C 002DA87C 41000524 */  addiu      $5, $0, 0x41
    /* 1DA880 002DA880 78820B0C */  jal        func_002e09e0
    /* 1DA884 002DA884 00000000 */   nop
    /* 1DA888 002DA888 040021C6 */  lwc1       $f1, 0x4($17)
    /* 1DA88C 002DA88C 26020224 */  addiu      $2, $0, 0x226
    /* 1DA890 002DA890 00008244 */  mtc1       $2, $f0
    /* 1DA894 002DA894 00000000 */  nop
    /* 1DA898 002DA898 20008046 */  cvt.s.w    $f0, $f0
    /* 1DA89C 002DA89C 410B0046 */  sub.s      $f13, $f1, $f0
    /* 1DA8A0 002DA8A0 D800A427 */  addiu      $4, $29, 0xD8
    /* 1DA8A4 002DA8A4 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1DA8A8 002DA8A8 5CCA0A0C */  jal        func_002b2970
    /* 1DA8AC 002DA8AC 00000000 */   nop
    /* 1DA8B0 002DA8B0 D000A427 */  addiu      $4, $29, 0xD0
    /* 1DA8B4 002DA8B4 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1DA8B8 002DA8B8 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1DA8BC 002DA8BC 5CCA0A0C */  jal        func_002b2970
    /* 1DA8C0 002DA8C0 00000000 */   nop
    /* 1DA8C4 002DA8C4 640D048E */  lw         $4, 0xD64($16)
    /* 1DA8C8 002DA8C8 D800A5DF */  ld         $5, 0xD8($29)
    /* 1DA8CC 002DA8CC D000A6DF */  ld         $6, 0xD0($29)
    /* 1DA8D0 002DA8D0 02000724 */  addiu      $7, $0, 0x2
    /* 1DA8D4 002DA8D4 04000824 */  addiu      $8, $0, 0x4
    /* 1DA8D8 002DA8D8 2D480000 */  daddu      $9, $0, $0
    /* 1DA8DC 002DA8DC 88810B0C */  jal        func_002e0620
    /* 1DA8E0 002DA8E0 00000000 */   nop
    /* 1DA8E4 002DA8E4 CEFF1124 */  addiu      $17, $0, -0x32
    /* 1DA8E8 002DA8E8 640D048E */  lw         $4, 0xD64($16)
    /* 1DA8EC 002DA8EC 38810B0C */  jal        func_002e04e0
    /* 1DA8F0 002DA8F0 00000000 */   nop
    /* 1DA8F4 002DA8F4 000151A4 */  sh         $17, 0x100($2)
    /* 1DA8F8 002DA8F8 25FF1124 */  addiu      $17, $0, -0xDB
    /* 1DA8FC 002DA8FC 640D048E */  lw         $4, 0xD64($16)
    /* 1DA900 002DA900 38810B0C */  jal        func_002e04e0
    /* 1DA904 002DA904 00000000 */   nop
    /* 1DA908 002DA908 020151A4 */  sh         $17, 0x102($2)
    /* 1DA90C 002DA90C A0C0023C */  lui        $2, (0xC0A00000 >> 16)
    /* 1DA910 002DA910 00608244 */  mtc1       $2, $f12
    /* 1DA914 002DA914 640D048E */  lw         $4, 0xD64($16)
    /* 1DA918 002DA918 2C858DC7 */  lwc1       $f13, -0x7AD4($28)
    /* 1DA91C 002DA91C 02000524 */  addiu      $5, $0, 0x2
    /* 1DA920 002DA920 2D30A000 */  daddu      $6, $5, $0
    /* 1DA924 002DA924 2D38A000 */  daddu      $7, $5, $0
    /* 1DA928 002DA928 50820B0C */  jal        func_002e0940
    /* 1DA92C 002DA92C 00000000 */   nop
    /* 1DA930 002DA930 6400113C */  lui        $17, %hi(D_0063F8C0)
    /* 1DA934 002DA934 C0F83126 */  addiu      $17, $17, %lo(D_0063F8C0)
    /* 1DA938 002DA938 3842023C */  lui        $2, (0x42380000 >> 16)
    /* 1DA93C 002DA93C 00608244 */  mtc1       $2, $f12
    /* 1DA940 002DA940 E80D048E */  lw         $4, 0xDE8($16)
    /* 1DA944 002DA944 41000524 */  addiu      $5, $0, 0x41
    /* 1DA948 002DA948 78820B0C */  jal        func_002e09e0
    /* 1DA94C 002DA94C 00000000 */   nop
    /* 1DA950 002DA950 E80D048E */  lw         $4, 0xDE8($16)
    /* 1DA954 002DA954 2D280000 */  daddu      $5, $0, $0
    /* 1DA958 002DA958 FF000624 */  addiu      $6, $0, 0xFF
    /* 1DA95C 002DA95C 2D380000 */  daddu      $7, $0, $0
    /* 1DA960 002DA960 06000824 */  addiu      $8, $0, 0x6
    /* 1DA964 002DA964 2D480000 */  daddu      $9, $0, $0
    /* 1DA968 002DA968 98810B0C */  jal        func_002e0660
    /* 1DA96C 002DA96C 00000000 */   nop
    /* 1DA970 002DA970 000034C6 */  lwc1       $f20, 0x0($17)
    /* 1DA974 002DA974 E80D048E */  lw         $4, 0xDE8($16)
    /* 1DA978 002DA978 38810B0C */  jal        func_002e04e0
    /* 1DA97C 002DA97C 00000000 */   nop
    /* 1DA980 002DA980 2C0054E4 */  swc1       $f20, 0x2C($2)
    /* 1DA984 002DA984 040034C6 */  lwc1       $f20, 0x4($17)
    /* 1DA988 002DA988 E80D048E */  lw         $4, 0xDE8($16)
    /* 1DA98C 002DA98C 38810B0C */  jal        func_002e04e0
    /* 1DA990 002DA990 00000000 */   nop
    /* 1DA994 002DA994 300054E4 */  swc1       $f20, 0x30($2)
    /* 1DA998 002DA998 3C42023C */  lui        $2, (0x423C0000 >> 16)
    /* 1DA99C 002DA99C 00608244 */  mtc1       $2, $f12
    /* 1DA9A0 002DA9A0 F00D048E */  lw         $4, 0xDF0($16)
    /* 1DA9A4 002DA9A4 41000524 */  addiu      $5, $0, 0x41
    /* 1DA9A8 002DA9A8 78820B0C */  jal        func_002e09e0
    /* 1DA9AC 002DA9AC 00000000 */   nop
    /* 1DA9B0 002DA9B0 F00D048E */  lw         $4, 0xDF0($16)
    /* 1DA9B4 002DA9B4 2D280000 */  daddu      $5, $0, $0
    /* 1DA9B8 002DA9B8 FF000624 */  addiu      $6, $0, 0xFF
    /* 1DA9BC 002DA9BC 2D380000 */  daddu      $7, $0, $0
    /* 1DA9C0 002DA9C0 06000824 */  addiu      $8, $0, 0x6
    /* 1DA9C4 002DA9C4 2D480000 */  daddu      $9, $0, $0
    /* 1DA9C8 002DA9C8 98810B0C */  jal        func_002e0660
    /* 1DA9CC 002DA9CC 00000000 */   nop
    /* 1DA9D0 002DA9D0 280F048E */  lw         $4, 0xF28($16)
    /* 1DA9D4 002DA9D4 44000524 */  addiu      $5, $0, 0x44
    /* 1DA9D8 002DA9D8 80B4110C */  jal        func_0046d200
    /* 1DA9DC 002DA9DC 00000000 */   nop
    /* 1DA9E0 002DA9E0 2D884000 */  daddu      $17, $2, $0
    /* 1DA9E4 002DA9E4 6400123C */  lui        $18, %hi(D_0063F780)
    /* 1DA9E8 002DA9E8 80F75226 */  addiu      $18, $18, %lo(D_0063F780)
    /* 1DA9EC 002DA9EC 5442023C */  lui        $2, (0x42540000 >> 16)
    /* 1DA9F0 002DA9F0 00608244 */  mtc1       $2, $f12
    /* 1DA9F4 002DA9F4 480D048E */  lw         $4, 0xD48($16)
    /* 1DA9F8 002DA9F8 56000524 */  addiu      $5, $0, 0x56
    /* 1DA9FC 002DA9FC 78820B0C */  jal        func_002e09e0
    /* 1DAA00 002DAA00 00000000 */   nop
    /* 1DAA04 002DAA04 02C3023C */  lui        $2, (0xC3020000 >> 16)
    /* 1DAA08 002DAA08 00688244 */  mtc1       $2, $f13
    /* 1DAA0C 002DAA0C C800A427 */  addiu      $4, $29, 0xC8
    /* 1DAA10 002DAA10 00004CC6 */  lwc1       $f12, 0x0($18)
    /* 1DAA14 002DAA14 5CCA0A0C */  jal        func_002b2970
    /* 1DAA18 002DAA18 00000000 */   nop
    /* 1DAA1C 002DAA1C C000A427 */  addiu      $4, $29, 0xC0
    /* 1DAA20 002DAA20 00004CC6 */  lwc1       $f12, 0x0($18)
    /* 1DAA24 002DAA24 04004DC6 */  lwc1       $f13, 0x4($18)
    /* 1DAA28 002DAA28 5CCA0A0C */  jal        func_002b2970
    /* 1DAA2C 002DAA2C 00000000 */   nop
    /* 1DAA30 002DAA30 480D048E */  lw         $4, 0xD48($16)
    /* 1DAA34 002DAA34 C800A5DF */  ld         $5, 0xC8($29)
    /* 1DAA38 002DAA38 C000A6DF */  ld         $6, 0xC0($29)
    /* 1DAA3C 002DAA3C 02000724 */  addiu      $7, $0, 0x2
    /* 1DAA40 002DAA40 05000824 */  addiu      $8, $0, 0x5
    /* 1DAA44 002DAA44 2D480000 */  daddu      $9, $0, $0
    /* 1DAA48 002DAA48 88810B0C */  jal        func_002e0620
    /* 1DAA4C 002DAA4C 00000000 */   nop
    /* 1DAA50 002DAA50 4801A427 */  addiu      $4, $29, 0x148
    /* 1DAA54 002DAA54 E4000524 */  addiu      $5, $0, 0xE4
    /* 1DAA58 002DAA58 FF000624 */  addiu      $6, $0, 0xFF
    /* 1DAA5C 002DAA5C 2D380000 */  daddu      $7, $0, $0
    /* 1DAA60 002DAA60 2D40C000 */  daddu      $8, $6, $0
    /* 1DAA64 002DAA64 98CA0A0C */  jal        func_002b2a60
    /* 1DAA68 002DAA68 00000000 */   nop
    /* 1DAA6C 002DAA6C 480D048E */  lw         $4, 0xD48($16)
    /* 1DAA70 002DAA70 38810B0C */  jal        func_002e04e0
    /* 1DAA74 002DAA74 00000000 */   nop
    /* 1DAA78 002DAA78 4801A693 */  lbu        $6, 0x148($29)
    /* 1DAA7C 002DAA7C 4901A593 */  lbu        $5, 0x149($29)
    /* 1DAA80 002DAA80 4A01A493 */  lbu        $4, 0x14A($29)
    /* 1DAA84 002DAA84 4B01A393 */  lbu        $3, 0x14B($29)
    /* 1DAA88 002DAA88 790046A0 */  sb         $6, 0x79($2)
    /* 1DAA8C 002DAA8C 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DAA90 002DAA90 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DAA94 002DAA94 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DAA98 002DAA98 2D202002 */  daddu      $4, $17, $0
    /* 1DAA9C 002DAA9C 98AC110C */  jal        func_0046b260
    /* 1DAAA0 002DAAA0 00000000 */   nop
    /* 1DAAA4 002DAAA4 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1DAAA8 002DAAA8 00088244 */  mtc1       $2, $f1
    /* 1DAAAC 002DAAAC 00000000 */  nop
    /* 1DAAB0 002DAAB0 03000146 */  div.s      $f0, $f0, $f1
    /* 1DAAB4 002DAAB4 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1DAAB8 002DAAB8 00000244 */  mfc1       $2, $f0
    /* 1DAABC 002DAABC 00000000 */  nop
    /* 1DAAC0 002DAAC0 3C940200 */  dsll32     $18, $2, 16
    /* 1DAAC4 002DAAC4 3F941200 */  dsra32     $18, $18, 16
    /* 1DAAC8 002DAAC8 480D048E */  lw         $4, 0xD48($16)
    /* 1DAACC 002DAACC 38810B0C */  jal        func_002e04e0
    /* 1DAAD0 002DAAD0 00000000 */   nop
    /* 1DAAD4 002DAAD4 000152A4 */  sh         $18, 0x100($2)
    /* 1DAAD8 002DAAD8 2D202002 */  daddu      $4, $17, $0
    /* 1DAADC 002DAADC BCAC110C */  jal        func_0046b2f0
    /* 1DAAE0 002DAAE0 00000000 */   nop
    /* 1DAAE4 002DAAE4 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1DAAE8 002DAAE8 00088244 */  mtc1       $2, $f1
    /* 1DAAEC 002DAAEC 00000000 */  nop
    /* 1DAAF0 002DAAF0 03000146 */  div.s      $f0, $f0, $f1
    /* 1DAAF4 002DAAF4 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1DAAF8 002DAAF8 00000244 */  mfc1       $2, $f0
    /* 1DAAFC 002DAAFC 00000000 */  nop
    /* 1DAB00 002DAB00 3C940200 */  dsll32     $18, $2, 16
    /* 1DAB04 002DAB04 3F941200 */  dsra32     $18, $18, 16
    /* 1DAB08 002DAB08 480D048E */  lw         $4, 0xD48($16)
    /* 1DAB0C 002DAB0C 38810B0C */  jal        func_002e04e0
    /* 1DAB10 002DAB10 00000000 */   nop
    /* 1DAB14 002DAB14 020152A4 */  sh         $18, 0x102($2)
    /* 1DAB18 002DAB18 6400023C */  lui        $2, %hi(D_0063FA44)
    /* 1DAB1C 002DAB1C 44FA4284 */  lh         $2, %lo(D_0063FA44)($2)
    /* 1DAB20 002DAB20 00008244 */  mtc1       $2, $f0
    /* 1DAB24 002DAB24 00000000 */  nop
    /* 1DAB28 002DAB28 20038046 */  cvt.s.w    $f12, $f0
    /* 1DAB2C 002DAB2C 480D048E */  lw         $4, 0xD48($16)
    /* 1DAB30 002DAB30 6400023C */  lui        $2, %hi(D_0063FA46)
    /* 1DAB34 002DAB34 46FA4584 */  lh         $5, %lo(D_0063FA46)($2)
    /* 1DAB38 002DAB38 6C820B0C */  jal        func_002e09b0
    /* 1DAB3C 002DAB3C 00000000 */   nop
    /* 1DAB40 002DAB40 00688044 */  mtc1       $0, $f13
    /* 1DAB44 002DAB44 6400023C */  lui        $2, %hi(D_0063FA46)
    /* 1DAB48 002DAB48 46FA4284 */  lh         $2, %lo(D_0063FA46)($2)
    /* 1DAB4C 002DAB4C 05004624 */  addiu      $6, $2, 0x5
    /* 1DAB50 002DAB50 480D048E */  lw         $4, 0xD48($16)
    /* 1DAB54 002DAB54 6400023C */  lui        $2, %hi(D_0063FA40)
    /* 1DAB58 002DAB58 40FA4CC4 */  lwc1       $f12, %lo(D_0063FA40)($2)
    /* 1DAB5C 002DAB5C 02000524 */  addiu      $5, $0, 0x2
    /* 1DAB60 002DAB60 2D380000 */  daddu      $7, $0, $0
    /* 1DAB64 002DAB64 50820B0C */  jal        func_002e0940
    /* 1DAB68 002DAB68 00000000 */   nop
    /* 1DAB6C 002DAB6C 2D202002 */  daddu      $4, $17, $0
    /* 1DAB70 002DAB70 A0B4110C */  jal        func_0046d280
    /* 1DAB74 002DAB74 00000000 */   nop
    /* 1DAB78 002DAB78 280F048E */  lw         $4, 0xF28($16)
    /* 1DAB7C 002DAB7C 43000524 */  addiu      $5, $0, 0x43
    /* 1DAB80 002DAB80 80B4110C */  jal        func_0046d200
    /* 1DAB84 002DAB84 00000000 */   nop
    /* 1DAB88 002DAB88 2D904000 */  daddu      $18, $2, $0
    /* 1DAB8C 002DAB8C 6400133C */  lui        $19, %hi(D_0063F778)
    /* 1DAB90 002DAB90 78F77326 */  addiu      $19, $19, %lo(D_0063F778)
    /* 1DAB94 002DAB94 6400113C */  lui        $17, %hi(D_0063FA48)
    /* 1DAB98 002DAB98 48FA3126 */  addiu      $17, $17, %lo(D_0063FA48)
    /* 1DAB9C 002DAB9C 5842023C */  lui        $2, (0x42580000 >> 16)
    /* 1DABA0 002DABA0 00608244 */  mtc1       $2, $f12
    /* 1DABA4 002DABA4 440D048E */  lw         $4, 0xD44($16)
    /* 1DABA8 002DABA8 56000524 */  addiu      $5, $0, 0x56
    /* 1DABAC 002DABAC 78820B0C */  jal        func_002e09e0
    /* 1DABB0 002DABB0 00000000 */   nop
    /* 1DABB4 002DABB4 3DC3023C */  lui        $2, (0xC33D0000 >> 16)
    /* 1DABB8 002DABB8 00688244 */  mtc1       $2, $f13
    /* 1DABBC 002DABBC B800A427 */  addiu      $4, $29, 0xB8
    /* 1DABC0 002DABC0 00006CC6 */  lwc1       $f12, 0x0($19)
    /* 1DABC4 002DABC4 5CCA0A0C */  jal        func_002b2970
    /* 1DABC8 002DABC8 00000000 */   nop
    /* 1DABCC 002DABCC B000A427 */  addiu      $4, $29, 0xB0
    /* 1DABD0 002DABD0 00006CC6 */  lwc1       $f12, 0x0($19)
    /* 1DABD4 002DABD4 04006DC6 */  lwc1       $f13, 0x4($19)
    /* 1DABD8 002DABD8 5CCA0A0C */  jal        func_002b2970
    /* 1DABDC 002DABDC 00000000 */   nop
    /* 1DABE0 002DABE0 440D048E */  lw         $4, 0xD44($16)
    /* 1DABE4 002DABE4 B800A5DF */  ld         $5, 0xB8($29)
    /* 1DABE8 002DABE8 B000A6DF */  ld         $6, 0xB0($29)
    /* 1DABEC 002DABEC 02000724 */  addiu      $7, $0, 0x2
    /* 1DABF0 002DABF0 05000824 */  addiu      $8, $0, 0x5
    /* 1DABF4 002DABF4 03000924 */  addiu      $9, $0, 0x3
    /* 1DABF8 002DABF8 88810B0C */  jal        func_002e0620
    /* 1DABFC 002DABFC 00000000 */   nop
    /* 1DAC00 002DAC00 4401A427 */  addiu      $4, $29, 0x144
    /* 1DAC04 002DAC04 E4000524 */  addiu      $5, $0, 0xE4
    /* 1DAC08 002DAC08 FF000624 */  addiu      $6, $0, 0xFF
    /* 1DAC0C 002DAC0C 2D380000 */  daddu      $7, $0, $0
    /* 1DAC10 002DAC10 2D40C000 */  daddu      $8, $6, $0
    /* 1DAC14 002DAC14 98CA0A0C */  jal        func_002b2a60
    /* 1DAC18 002DAC18 00000000 */   nop
    /* 1DAC1C 002DAC1C 440D048E */  lw         $4, 0xD44($16)
    /* 1DAC20 002DAC20 38810B0C */  jal        func_002e04e0
    /* 1DAC24 002DAC24 00000000 */   nop
    /* 1DAC28 002DAC28 4401A693 */  lbu        $6, 0x144($29)
    /* 1DAC2C 002DAC2C 4501A593 */  lbu        $5, 0x145($29)
    /* 1DAC30 002DAC30 4601A493 */  lbu        $4, 0x146($29)
    /* 1DAC34 002DAC34 4701A393 */  lbu        $3, 0x147($29)
    /* 1DAC38 002DAC38 790046A0 */  sb         $6, 0x79($2)
    /* 1DAC3C 002DAC3C 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DAC40 002DAC40 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DAC44 002DAC44 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DAC48 002DAC48 2D204002 */  daddu      $4, $18, $0
    /* 1DAC4C 002DAC4C 98AC110C */  jal        func_0046b260
    /* 1DAC50 002DAC50 00000000 */   nop
    /* 1DAC54 002DAC54 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1DAC58 002DAC58 00088244 */  mtc1       $2, $f1
    /* 1DAC5C 002DAC5C 00000000 */  nop
    /* 1DAC60 002DAC60 03000146 */  div.s      $f0, $f0, $f1
    /* 1DAC64 002DAC64 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1DAC68 002DAC68 00000244 */  mfc1       $2, $f0
    /* 1DAC6C 002DAC6C 00000000 */  nop
    /* 1DAC70 002DAC70 3C9C0200 */  dsll32     $19, $2, 16
    /* 1DAC74 002DAC74 3F9C1300 */  dsra32     $19, $19, 16
    /* 1DAC78 002DAC78 440D048E */  lw         $4, 0xD44($16)
    /* 1DAC7C 002DAC7C 38810B0C */  jal        func_002e04e0
    /* 1DAC80 002DAC80 00000000 */   nop
    /* 1DAC84 002DAC84 000153A4 */  sh         $19, 0x100($2)
    /* 1DAC88 002DAC88 2D204002 */  daddu      $4, $18, $0
    /* 1DAC8C 002DAC8C BCAC110C */  jal        func_0046b2f0
    /* 1DAC90 002DAC90 00000000 */   nop
    /* 1DAC94 002DAC94 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1DAC98 002DAC98 00088244 */  mtc1       $2, $f1
    /* 1DAC9C 002DAC9C 00000000 */  nop
    /* 1DACA0 002DACA0 03000146 */  div.s      $f0, $f0, $f1
    /* 1DACA4 002DACA4 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1DACA8 002DACA8 00000244 */  mfc1       $2, $f0
    /* 1DACAC 002DACAC 00000000 */  nop
    /* 1DACB0 002DACB0 3C9C0200 */  dsll32     $19, $2, 16
    /* 1DACB4 002DACB4 3F9C1300 */  dsra32     $19, $19, 16
    /* 1DACB8 002DACB8 440D048E */  lw         $4, 0xD44($16)
    /* 1DACBC 002DACBC 38810B0C */  jal        func_002e04e0
    /* 1DACC0 002DACC0 00000000 */   nop
    /* 1DACC4 002DACC4 020153A4 */  sh         $19, 0x102($2)
    /* 1DACC8 002DACC8 04002286 */  lh         $2, 0x4($17)
    /* 1DACCC 002DACCC 00008244 */  mtc1       $2, $f0
    /* 1DACD0 002DACD0 00000000 */  nop
    /* 1DACD4 002DACD4 20038046 */  cvt.s.w    $f12, $f0
    /* 1DACD8 002DACD8 440D048E */  lw         $4, 0xD44($16)
    /* 1DACDC 002DACDC 06002586 */  lh         $5, 0x6($17)
    /* 1DACE0 002DACE0 6C820B0C */  jal        func_002e09b0
    /* 1DACE4 002DACE4 00000000 */   nop
    /* 1DACE8 002DACE8 00688044 */  mtc1       $0, $f13
    /* 1DACEC 002DACEC 06002286 */  lh         $2, 0x6($17)
    /* 1DACF0 002DACF0 05004624 */  addiu      $6, $2, 0x5
    /* 1DACF4 002DACF4 440D048E */  lw         $4, 0xD44($16)
    /* 1DACF8 002DACF8 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1DACFC 002DACFC 02000524 */  addiu      $5, $0, 0x2
    /* 1DAD00 002DAD00 03000724 */  addiu      $7, $0, 0x3
    /* 1DAD04 002DAD04 50820B0C */  jal        func_002e0940
    /* 1DAD08 002DAD08 00000000 */   nop
    /* 1DAD0C 002DAD0C 2D204002 */  daddu      $4, $18, $0
    /* 1DAD10 002DAD10 A0B4110C */  jal        func_0046d280
    /* 1DAD14 002DAD14 00000000 */   nop
    /* 1DAD18 002DAD18 280F048E */  lw         $4, 0xF28($16)
    /* 1DAD1C 002DAD1C 45000524 */  addiu      $5, $0, 0x45
    /* 1DAD20 002DAD20 80B4110C */  jal        func_0046d200
    /* 1DAD24 002DAD24 00000000 */   nop
    /* 1DAD28 002DAD28 2D904000 */  daddu      $18, $2, $0
    /* 1DAD2C 002DAD2C 6400133C */  lui        $19, %hi(D_0063F788)
    /* 1DAD30 002DAD30 88F77326 */  addiu      $19, $19, %lo(D_0063F788)
    /* 1DAD34 002DAD34 6400113C */  lui        $17, %hi(D_0063FA50)
    /* 1DAD38 002DAD38 50FA3126 */  addiu      $17, $17, %lo(D_0063FA50)
    /* 1DAD3C 002DAD3C 5C42023C */  lui        $2, (0x425C0000 >> 16)
    /* 1DAD40 002DAD40 00608244 */  mtc1       $2, $f12
    /* 1DAD44 002DAD44 4C0D048E */  lw         $4, 0xD4C($16)
    /* 1DAD48 002DAD48 56000524 */  addiu      $5, $0, 0x56
    /* 1DAD4C 002DAD4C 78820B0C */  jal        func_002e09e0
    /* 1DAD50 002DAD50 00000000 */   nop
    /* 1DAD54 002DAD54 96C2023C */  lui        $2, (0xC2960000 >> 16)
    /* 1DAD58 002DAD58 00688244 */  mtc1       $2, $f13
    /* 1DAD5C 002DAD5C A800A427 */  addiu      $4, $29, 0xA8
    /* 1DAD60 002DAD60 00006CC6 */  lwc1       $f12, 0x0($19)
    /* 1DAD64 002DAD64 5CCA0A0C */  jal        func_002b2970
    /* 1DAD68 002DAD68 00000000 */   nop
    /* 1DAD6C 002DAD6C A000A427 */  addiu      $4, $29, 0xA0
    /* 1DAD70 002DAD70 00006CC6 */  lwc1       $f12, 0x0($19)
    /* 1DAD74 002DAD74 04006DC6 */  lwc1       $f13, 0x4($19)
    /* 1DAD78 002DAD78 5CCA0A0C */  jal        func_002b2970
    /* 1DAD7C 002DAD7C 00000000 */   nop
    /* 1DAD80 002DAD80 4C0D048E */  lw         $4, 0xD4C($16)
    /* 1DAD84 002DAD84 A800A5DF */  ld         $5, 0xA8($29)
    /* 1DAD88 002DAD88 A000A6DF */  ld         $6, 0xA0($29)
    /* 1DAD8C 002DAD8C 02000724 */  addiu      $7, $0, 0x2
    /* 1DAD90 002DAD90 05000824 */  addiu      $8, $0, 0x5
    /* 1DAD94 002DAD94 01000924 */  addiu      $9, $0, 0x1
    /* 1DAD98 002DAD98 88810B0C */  jal        func_002e0620
    /* 1DAD9C 002DAD9C 00000000 */   nop
    /* 1DADA0 002DADA0 4001A427 */  addiu      $4, $29, 0x140
    /* 1DADA4 002DADA4 E4000524 */  addiu      $5, $0, 0xE4
    /* 1DADA8 002DADA8 FF000624 */  addiu      $6, $0, 0xFF
    /* 1DADAC 002DADAC 2D380000 */  daddu      $7, $0, $0
    /* 1DADB0 002DADB0 2D40C000 */  daddu      $8, $6, $0
    /* 1DADB4 002DADB4 98CA0A0C */  jal        func_002b2a60
    /* 1DADB8 002DADB8 00000000 */   nop
    /* 1DADBC 002DADBC 4C0D048E */  lw         $4, 0xD4C($16)
    /* 1DADC0 002DADC0 38810B0C */  jal        func_002e04e0
    /* 1DADC4 002DADC4 00000000 */   nop
    /* 1DADC8 002DADC8 4001A693 */  lbu        $6, 0x140($29)
    /* 1DADCC 002DADCC 4101A593 */  lbu        $5, 0x141($29)
    /* 1DADD0 002DADD0 4201A493 */  lbu        $4, 0x142($29)
    /* 1DADD4 002DADD4 4301A393 */  lbu        $3, 0x143($29)
    /* 1DADD8 002DADD8 790046A0 */  sb         $6, 0x79($2)
    /* 1DADDC 002DADDC 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DADE0 002DADE0 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DADE4 002DADE4 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DADE8 002DADE8 2D204002 */  daddu      $4, $18, $0
    /* 1DADEC 002DADEC 98AC110C */  jal        func_0046b260
    /* 1DADF0 002DADF0 00000000 */   nop
    /* 1DADF4 002DADF4 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1DADF8 002DADF8 00088244 */  mtc1       $2, $f1
    /* 1DADFC 002DADFC 00000000 */  nop
    /* 1DAE00 002DAE00 03000146 */  div.s      $f0, $f0, $f1
    /* 1DAE04 002DAE04 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1DAE08 002DAE08 00000244 */  mfc1       $2, $f0
    /* 1DAE0C 002DAE0C 00000000 */  nop
    /* 1DAE10 002DAE10 3C9C0200 */  dsll32     $19, $2, 16
    /* 1DAE14 002DAE14 3F9C1300 */  dsra32     $19, $19, 16
    /* 1DAE18 002DAE18 4C0D048E */  lw         $4, 0xD4C($16)
    /* 1DAE1C 002DAE1C 38810B0C */  jal        func_002e04e0
    /* 1DAE20 002DAE20 00000000 */   nop
    /* 1DAE24 002DAE24 000153A4 */  sh         $19, 0x100($2)
    /* 1DAE28 002DAE28 2D204002 */  daddu      $4, $18, $0
    /* 1DAE2C 002DAE2C BCAC110C */  jal        func_0046b2f0
    /* 1DAE30 002DAE30 00000000 */   nop
    /* 1DAE34 002DAE34 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1DAE38 002DAE38 00088244 */  mtc1       $2, $f1
    /* 1DAE3C 002DAE3C 00000000 */  nop
    /* 1DAE40 002DAE40 03000146 */  div.s      $f0, $f0, $f1
    /* 1DAE44 002DAE44 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1DAE48 002DAE48 00000244 */  mfc1       $2, $f0
    /* 1DAE4C 002DAE4C 00000000 */  nop
    /* 1DAE50 002DAE50 3C9C0200 */  dsll32     $19, $2, 16
    /* 1DAE54 002DAE54 3F9C1300 */  dsra32     $19, $19, 16
    /* 1DAE58 002DAE58 4C0D048E */  lw         $4, 0xD4C($16)
    /* 1DAE5C 002DAE5C 38810B0C */  jal        func_002e04e0
    /* 1DAE60 002DAE60 00000000 */   nop
    /* 1DAE64 002DAE64 020153A4 */  sh         $19, 0x102($2)
    /* 1DAE68 002DAE68 04002286 */  lh         $2, 0x4($17)
    /* 1DAE6C 002DAE6C 00008244 */  mtc1       $2, $f0
    /* 1DAE70 002DAE70 00000000 */  nop
    /* 1DAE74 002DAE74 20038046 */  cvt.s.w    $f12, $f0
    /* 1DAE78 002DAE78 4C0D048E */  lw         $4, 0xD4C($16)
    /* 1DAE7C 002DAE7C 06002586 */  lh         $5, 0x6($17)
    /* 1DAE80 002DAE80 6C820B0C */  jal        func_002e09b0
    /* 1DAE84 002DAE84 00000000 */   nop
    /* 1DAE88 002DAE88 00688044 */  mtc1       $0, $f13
    /* 1DAE8C 002DAE8C 06002286 */  lh         $2, 0x6($17)
    /* 1DAE90 002DAE90 05004624 */  addiu      $6, $2, 0x5
    /* 1DAE94 002DAE94 4C0D048E */  lw         $4, 0xD4C($16)
    /* 1DAE98 002DAE98 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1DAE9C 002DAE9C 02000524 */  addiu      $5, $0, 0x2
    /* 1DAEA0 002DAEA0 01000724 */  addiu      $7, $0, 0x1
    /* 1DAEA4 002DAEA4 50820B0C */  jal        func_002e0940
    /* 1DAEA8 002DAEA8 00000000 */   nop
    /* 1DAEAC 002DAEAC 2D204002 */  daddu      $4, $18, $0
    /* 1DAEB0 002DAEB0 A0B4110C */  jal        func_0046d280
    /* 1DAEB4 002DAEB4 00000000 */   nop
    /* 1DAEB8 002DAEB8 280F048E */  lw         $4, 0xF28($16)
    /* 1DAEBC 002DAEBC 46000524 */  addiu      $5, $0, 0x46
    /* 1DAEC0 002DAEC0 80B4110C */  jal        func_0046d200
    /* 1DAEC4 002DAEC4 00000000 */   nop
    /* 1DAEC8 002DAEC8 2D904000 */  daddu      $18, $2, $0
    /* 1DAECC 002DAECC 6400133C */  lui        $19, %hi(D_0063F790)
    /* 1DAED0 002DAED0 90F77326 */  addiu      $19, $19, %lo(D_0063F790)
    /* 1DAED4 002DAED4 6400113C */  lui        $17, %hi(D_0063FA58)
    /* 1DAED8 002DAED8 58FA3126 */  addiu      $17, $17, %lo(D_0063FA58)
    /* 1DAEDC 002DAEDC 6042023C */  lui        $2, (0x42600000 >> 16)
    /* 1DAEE0 002DAEE0 00608244 */  mtc1       $2, $f12
    /* 1DAEE4 002DAEE4 500D048E */  lw         $4, 0xD50($16)
    /* 1DAEE8 002DAEE8 56000524 */  addiu      $5, $0, 0x56
    /* 1DAEEC 002DAEEC 78820B0C */  jal        func_002e09e0
    /* 1DAEF0 002DAEF0 00000000 */   nop
    /* 1DAEF4 002DAEF4 25C3023C */  lui        $2, (0xC3250000 >> 16)
    /* 1DAEF8 002DAEF8 00688244 */  mtc1       $2, $f13
    /* 1DAEFC 002DAEFC 9800A427 */  addiu      $4, $29, 0x98
    /* 1DAF00 002DAF00 00006CC6 */  lwc1       $f12, 0x0($19)
    /* 1DAF04 002DAF04 5CCA0A0C */  jal        func_002b2970
    /* 1DAF08 002DAF08 00000000 */   nop
    /* 1DAF0C 002DAF0C 9000A427 */  addiu      $4, $29, 0x90
    /* 1DAF10 002DAF10 00006CC6 */  lwc1       $f12, 0x0($19)
    /* 1DAF14 002DAF14 04006DC6 */  lwc1       $f13, 0x4($19)
    /* 1DAF18 002DAF18 5CCA0A0C */  jal        func_002b2970
    /* 1DAF1C 002DAF1C 00000000 */   nop
    /* 1DAF20 002DAF20 500D048E */  lw         $4, 0xD50($16)
    /* 1DAF24 002DAF24 9800A5DF */  ld         $5, 0x98($29)
    /* 1DAF28 002DAF28 9000A6DF */  ld         $6, 0x90($29)
    /* 1DAF2C 002DAF2C 02000724 */  addiu      $7, $0, 0x2
    /* 1DAF30 002DAF30 05000824 */  addiu      $8, $0, 0x5
    /* 1DAF34 002DAF34 04000924 */  addiu      $9, $0, 0x4
    /* 1DAF38 002DAF38 88810B0C */  jal        func_002e0620
    /* 1DAF3C 002DAF3C 00000000 */   nop
    /* 1DAF40 002DAF40 3C01A427 */  addiu      $4, $29, 0x13C
    /* 1DAF44 002DAF44 E4000524 */  addiu      $5, $0, 0xE4
    /* 1DAF48 002DAF48 FF000624 */  addiu      $6, $0, 0xFF
    /* 1DAF4C 002DAF4C 2D380000 */  daddu      $7, $0, $0
    /* 1DAF50 002DAF50 2D40C000 */  daddu      $8, $6, $0
    /* 1DAF54 002DAF54 98CA0A0C */  jal        func_002b2a60
    /* 1DAF58 002DAF58 00000000 */   nop
    /* 1DAF5C 002DAF5C 500D048E */  lw         $4, 0xD50($16)
    /* 1DAF60 002DAF60 38810B0C */  jal        func_002e04e0
    /* 1DAF64 002DAF64 00000000 */   nop
    /* 1DAF68 002DAF68 3C01A693 */  lbu        $6, 0x13C($29)
    /* 1DAF6C 002DAF6C 3D01A593 */  lbu        $5, 0x13D($29)
    /* 1DAF70 002DAF70 3E01A493 */  lbu        $4, 0x13E($29)
    /* 1DAF74 002DAF74 3F01A393 */  lbu        $3, 0x13F($29)
    /* 1DAF78 002DAF78 790046A0 */  sb         $6, 0x79($2)
    /* 1DAF7C 002DAF7C 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DAF80 002DAF80 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DAF84 002DAF84 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DAF88 002DAF88 2D204002 */  daddu      $4, $18, $0
    /* 1DAF8C 002DAF8C 98AC110C */  jal        func_0046b260
    /* 1DAF90 002DAF90 00000000 */   nop
    /* 1DAF94 002DAF94 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1DAF98 002DAF98 00088244 */  mtc1       $2, $f1
    /* 1DAF9C 002DAF9C 00000000 */  nop
    /* 1DAFA0 002DAFA0 03000146 */  div.s      $f0, $f0, $f1
    /* 1DAFA4 002DAFA4 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1DAFA8 002DAFA8 00000244 */  mfc1       $2, $f0
    /* 1DAFAC 002DAFAC 00000000 */  nop
    /* 1DAFB0 002DAFB0 3C9C0200 */  dsll32     $19, $2, 16
    /* 1DAFB4 002DAFB4 3F9C1300 */  dsra32     $19, $19, 16
    /* 1DAFB8 002DAFB8 500D048E */  lw         $4, 0xD50($16)
    /* 1DAFBC 002DAFBC 38810B0C */  jal        func_002e04e0
    /* 1DAFC0 002DAFC0 00000000 */   nop
    /* 1DAFC4 002DAFC4 000153A4 */  sh         $19, 0x100($2)
    /* 1DAFC8 002DAFC8 2D204002 */  daddu      $4, $18, $0
    /* 1DAFCC 002DAFCC BCAC110C */  jal        func_0046b2f0
    /* 1DAFD0 002DAFD0 00000000 */   nop
    /* 1DAFD4 002DAFD4 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1DAFD8 002DAFD8 00088244 */  mtc1       $2, $f1
    /* 1DAFDC 002DAFDC 00000000 */  nop
    /* 1DAFE0 002DAFE0 03000146 */  div.s      $f0, $f0, $f1
    /* 1DAFE4 002DAFE4 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1DAFE8 002DAFE8 00000244 */  mfc1       $2, $f0
    /* 1DAFEC 002DAFEC 00000000 */  nop
    /* 1DAFF0 002DAFF0 3C9C0200 */  dsll32     $19, $2, 16
    /* 1DAFF4 002DAFF4 3F9C1300 */  dsra32     $19, $19, 16
    /* 1DAFF8 002DAFF8 500D048E */  lw         $4, 0xD50($16)
    /* 1DAFFC 002DAFFC 38810B0C */  jal        func_002e04e0
    /* 1DB000 002DB000 00000000 */   nop
    /* 1DB004 002DB004 020153A4 */  sh         $19, 0x102($2)
    /* 1DB008 002DB008 00A08044 */  mtc1       $0, $f20
    /* 1DB00C 002DB00C 500D048E */  lw         $4, 0xD50($16)
    /* 1DB010 002DB010 38810B0C */  jal        func_002e04e0
    /* 1DB014 002DB014 00000000 */   nop
    /* 1DB018 002DB018 C40054E4 */  swc1       $f20, 0xC4($2)
    /* 1DB01C 002DB01C 04002286 */  lh         $2, 0x4($17)
    /* 1DB020 002DB020 00008244 */  mtc1       $2, $f0
    /* 1DB024 002DB024 00000000 */  nop
    /* 1DB028 002DB028 20038046 */  cvt.s.w    $f12, $f0
    /* 1DB02C 002DB02C 500D048E */  lw         $4, 0xD50($16)
    /* 1DB030 002DB030 06002586 */  lh         $5, 0x6($17)
    /* 1DB034 002DB034 6C820B0C */  jal        func_002e09b0
    /* 1DB038 002DB038 00000000 */   nop
    /* 1DB03C 002DB03C 46A30046 */  mov.s      $f13, $f20
    /* 1DB040 002DB040 06002286 */  lh         $2, 0x6($17)
    /* 1DB044 002DB044 05004624 */  addiu      $6, $2, 0x5
    /* 1DB048 002DB048 500D048E */  lw         $4, 0xD50($16)
    /* 1DB04C 002DB04C 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1DB050 002DB050 02000524 */  addiu      $5, $0, 0x2
    /* 1DB054 002DB054 04000724 */  addiu      $7, $0, 0x4
    /* 1DB058 002DB058 50820B0C */  jal        func_002e0940
    /* 1DB05C 002DB05C 00000000 */   nop
    /* 1DB060 002DB060 2D204002 */  daddu      $4, $18, $0
    /* 1DB064 002DB064 A0B4110C */  jal        func_0046d280
    /* 1DB068 002DB068 00000000 */   nop
    /* 1DB06C 002DB06C 280F048E */  lw         $4, 0xF28($16)
    /* 1DB070 002DB070 47000524 */  addiu      $5, $0, 0x47
    /* 1DB074 002DB074 80B4110C */  jal        func_0046d200
    /* 1DB078 002DB078 00000000 */   nop
    /* 1DB07C 002DB07C 2D904000 */  daddu      $18, $2, $0
    /* 1DB080 002DB080 6400133C */  lui        $19, %hi(D_0063F798)
    /* 1DB084 002DB084 98F77326 */  addiu      $19, $19, %lo(D_0063F798)
    /* 1DB088 002DB088 6400113C */  lui        $17, %hi(D_0063FA60)
    /* 1DB08C 002DB08C 60FA3126 */  addiu      $17, $17, %lo(D_0063FA60)
    /* 1DB090 002DB090 6442023C */  lui        $2, (0x42640000 >> 16)
    /* 1DB094 002DB094 00608244 */  mtc1       $2, $f12
    /* 1DB098 002DB098 540D048E */  lw         $4, 0xD54($16)
    /* 1DB09C 002DB09C 56000524 */  addiu      $5, $0, 0x56
    /* 1DB0A0 002DB0A0 78820B0C */  jal        func_002e09e0
    /* 1DB0A4 002DB0A4 00000000 */   nop
    /* 1DB0A8 002DB0A8 FCC2023C */  lui        $2, (0xC2FC0000 >> 16)
    /* 1DB0AC 002DB0AC 00688244 */  mtc1       $2, $f13
    /* 1DB0B0 002DB0B0 8800A427 */  addiu      $4, $29, 0x88
    /* 1DB0B4 002DB0B4 00006CC6 */  lwc1       $f12, 0x0($19)
    /* 1DB0B8 002DB0B8 5CCA0A0C */  jal        func_002b2970
    /* 1DB0BC 002DB0BC 00000000 */   nop
    /* 1DB0C0 002DB0C0 8000A427 */  addiu      $4, $29, 0x80
    /* 1DB0C4 002DB0C4 00006CC6 */  lwc1       $f12, 0x0($19)
    /* 1DB0C8 002DB0C8 04006DC6 */  lwc1       $f13, 0x4($19)
    /* 1DB0CC 002DB0CC 5CCA0A0C */  jal        func_002b2970
    /* 1DB0D0 002DB0D0 00000000 */   nop
    /* 1DB0D4 002DB0D4 540D048E */  lw         $4, 0xD54($16)
    /* 1DB0D8 002DB0D8 8800A5DF */  ld         $5, 0x88($29)
    /* 1DB0DC 002DB0DC 8000A6DF */  ld         $6, 0x80($29)
    /* 1DB0E0 002DB0E0 02000724 */  addiu      $7, $0, 0x2
    /* 1DB0E4 002DB0E4 05000824 */  addiu      $8, $0, 0x5
    /* 1DB0E8 002DB0E8 2D48E000 */  daddu      $9, $7, $0
    /* 1DB0EC 002DB0EC 88810B0C */  jal        func_002e0620
    /* 1DB0F0 002DB0F0 00000000 */   nop
    /* 1DB0F4 002DB0F4 3801A427 */  addiu      $4, $29, 0x138
    /* 1DB0F8 002DB0F8 E4000524 */  addiu      $5, $0, 0xE4
    /* 1DB0FC 002DB0FC FF000624 */  addiu      $6, $0, 0xFF
    /* 1DB100 002DB100 2D380000 */  daddu      $7, $0, $0
    /* 1DB104 002DB104 2D40C000 */  daddu      $8, $6, $0
    /* 1DB108 002DB108 98CA0A0C */  jal        func_002b2a60
    /* 1DB10C 002DB10C 00000000 */   nop
    /* 1DB110 002DB110 540D048E */  lw         $4, 0xD54($16)
    /* 1DB114 002DB114 38810B0C */  jal        func_002e04e0
    /* 1DB118 002DB118 00000000 */   nop
    /* 1DB11C 002DB11C 3801A693 */  lbu        $6, 0x138($29)
    /* 1DB120 002DB120 3901A593 */  lbu        $5, 0x139($29)
    /* 1DB124 002DB124 3A01A493 */  lbu        $4, 0x13A($29)
    /* 1DB128 002DB128 3B01A393 */  lbu        $3, 0x13B($29)
    /* 1DB12C 002DB12C 790046A0 */  sb         $6, 0x79($2)
    /* 1DB130 002DB130 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DB134 002DB134 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DB138 002DB138 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DB13C 002DB13C 2D204002 */  daddu      $4, $18, $0
    /* 1DB140 002DB140 98AC110C */  jal        func_0046b260
    /* 1DB144 002DB144 00000000 */   nop
    /* 1DB148 002DB148 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1DB14C 002DB14C 00088244 */  mtc1       $2, $f1
    /* 1DB150 002DB150 00000000 */  nop
    /* 1DB154 002DB154 03000146 */  div.s      $f0, $f0, $f1
    /* 1DB158 002DB158 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1DB15C 002DB15C 00000244 */  mfc1       $2, $f0
    /* 1DB160 002DB160 00000000 */  nop
    /* 1DB164 002DB164 3C9C0200 */  dsll32     $19, $2, 16
    /* 1DB168 002DB168 3F9C1300 */  dsra32     $19, $19, 16
    /* 1DB16C 002DB16C 540D048E */  lw         $4, 0xD54($16)
    /* 1DB170 002DB170 38810B0C */  jal        func_002e04e0
    /* 1DB174 002DB174 00000000 */   nop
    /* 1DB178 002DB178 000153A4 */  sh         $19, 0x100($2)
    /* 1DB17C 002DB17C 2D204002 */  daddu      $4, $18, $0
    /* 1DB180 002DB180 BCAC110C */  jal        func_0046b2f0
    /* 1DB184 002DB184 00000000 */   nop
    /* 1DB188 002DB188 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1DB18C 002DB18C 00088244 */  mtc1       $2, $f1
    /* 1DB190 002DB190 00000000 */  nop
    /* 1DB194 002DB194 03000146 */  div.s      $f0, $f0, $f1
    /* 1DB198 002DB198 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1DB19C 002DB19C 00000244 */  mfc1       $2, $f0
    /* 1DB1A0 002DB1A0 00000000 */  nop
    /* 1DB1A4 002DB1A4 3C9C0200 */  dsll32     $19, $2, 16
    /* 1DB1A8 002DB1A8 3F9C1300 */  dsra32     $19, $19, 16
    /* 1DB1AC 002DB1AC 540D048E */  lw         $4, 0xD54($16)
    /* 1DB1B0 002DB1B0 38810B0C */  jal        func_002e04e0
    /* 1DB1B4 002DB1B4 00000000 */   nop
    /* 1DB1B8 002DB1B8 020153A4 */  sh         $19, 0x102($2)
    /* 1DB1BC 002DB1BC 540D048E */  lw         $4, 0xD54($16)
    /* 1DB1C0 002DB1C0 38810B0C */  jal        func_002e04e0
    /* 1DB1C4 002DB1C4 00000000 */   nop
    /* 1DB1C8 002DB1C8 C40054E4 */  swc1       $f20, 0xC4($2)
    /* 1DB1CC 002DB1CC 04002286 */  lh         $2, 0x4($17)
    /* 1DB1D0 002DB1D0 00008244 */  mtc1       $2, $f0
    /* 1DB1D4 002DB1D4 00000000 */  nop
    /* 1DB1D8 002DB1D8 20038046 */  cvt.s.w    $f12, $f0
    /* 1DB1DC 002DB1DC 540D048E */  lw         $4, 0xD54($16)
    /* 1DB1E0 002DB1E0 06002586 */  lh         $5, 0x6($17)
    /* 1DB1E4 002DB1E4 6C820B0C */  jal        func_002e09b0
    /* 1DB1E8 002DB1E8 00000000 */   nop
    /* 1DB1EC 002DB1EC 46A30046 */  mov.s      $f13, $f20
    /* 1DB1F0 002DB1F0 06002286 */  lh         $2, 0x6($17)
    /* 1DB1F4 002DB1F4 05004624 */  addiu      $6, $2, 0x5
    /* 1DB1F8 002DB1F8 540D048E */  lw         $4, 0xD54($16)
    /* 1DB1FC 002DB1FC 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1DB200 002DB200 01000524 */  addiu      $5, $0, 0x1
    /* 1DB204 002DB204 02000724 */  addiu      $7, $0, 0x2
    /* 1DB208 002DB208 50820B0C */  jal        func_002e0940
    /* 1DB20C 002DB20C 00000000 */   nop
    /* 1DB210 002DB210 2D204002 */  daddu      $4, $18, $0
    /* 1DB214 002DB214 A0B4110C */  jal        func_0046d280
    /* 1DB218 002DB218 00000000 */   nop
    /* 1DB21C 002DB21C 280F048E */  lw         $4, 0xF28($16)
    /* 1DB220 002DB220 48000524 */  addiu      $5, $0, 0x48
    /* 1DB224 002DB224 80B4110C */  jal        func_0046d200
    /* 1DB228 002DB228 00000000 */   nop
    /* 1DB22C 002DB22C 2D904000 */  daddu      $18, $2, $0
    /* 1DB230 002DB230 6400133C */  lui        $19, %hi(D_0063F7A0)
    /* 1DB234 002DB234 A0F77326 */  addiu      $19, $19, %lo(D_0063F7A0)
    /* 1DB238 002DB238 6400113C */  lui        $17, %hi(D_0063FA68)
    /* 1DB23C 002DB23C 68FA3126 */  addiu      $17, $17, %lo(D_0063FA68)
    /* 1DB240 002DB240 6842023C */  lui        $2, (0x42680000 >> 16)
    /* 1DB244 002DB244 00608244 */  mtc1       $2, $f12
    /* 1DB248 002DB248 580D048E */  lw         $4, 0xD58($16)
    /* 1DB24C 002DB24C 56000524 */  addiu      $5, $0, 0x56
    /* 1DB250 002DB250 78820B0C */  jal        func_002e09e0
    /* 1DB254 002DB254 00000000 */   nop
    /* 1DB258 002DB258 45C3023C */  lui        $2, (0xC3450000 >> 16)
    /* 1DB25C 002DB25C 00688244 */  mtc1       $2, $f13
    /* 1DB260 002DB260 7800A427 */  addiu      $4, $29, 0x78
    /* 1DB264 002DB264 00006CC6 */  lwc1       $f12, 0x0($19)
    /* 1DB268 002DB268 5CCA0A0C */  jal        func_002b2970
    /* 1DB26C 002DB26C 00000000 */   nop
    /* 1DB270 002DB270 7000A427 */  addiu      $4, $29, 0x70
    /* 1DB274 002DB274 00006CC6 */  lwc1       $f12, 0x0($19)
    /* 1DB278 002DB278 04006DC6 */  lwc1       $f13, 0x4($19)
    /* 1DB27C 002DB27C 5CCA0A0C */  jal        func_002b2970
    /* 1DB280 002DB280 00000000 */   nop
    /* 1DB284 002DB284 580D048E */  lw         $4, 0xD58($16)
    /* 1DB288 002DB288 7800A5DF */  ld         $5, 0x78($29)
    /* 1DB28C 002DB28C 7000A6DF */  ld         $6, 0x70($29)
    /* 1DB290 002DB290 02000724 */  addiu      $7, $0, 0x2
    /* 1DB294 002DB294 05000824 */  addiu      $8, $0, 0x5
    /* 1DB298 002DB298 2D480001 */  daddu      $9, $8, $0
    /* 1DB29C 002DB29C 88810B0C */  jal        func_002e0620
    /* 1DB2A0 002DB2A0 00000000 */   nop
    /* 1DB2A4 002DB2A4 3401A427 */  addiu      $4, $29, 0x134
    /* 1DB2A8 002DB2A8 E4000524 */  addiu      $5, $0, 0xE4
    /* 1DB2AC 002DB2AC FF000624 */  addiu      $6, $0, 0xFF
    /* 1DB2B0 002DB2B0 2D380000 */  daddu      $7, $0, $0
    /* 1DB2B4 002DB2B4 2D40C000 */  daddu      $8, $6, $0
    /* 1DB2B8 002DB2B8 98CA0A0C */  jal        func_002b2a60
    /* 1DB2BC 002DB2BC 00000000 */   nop
    /* 1DB2C0 002DB2C0 580D048E */  lw         $4, 0xD58($16)
    /* 1DB2C4 002DB2C4 38810B0C */  jal        func_002e04e0
    /* 1DB2C8 002DB2C8 00000000 */   nop
    /* 1DB2CC 002DB2CC 3401A693 */  lbu        $6, 0x134($29)
    /* 1DB2D0 002DB2D0 3501A593 */  lbu        $5, 0x135($29)
    /* 1DB2D4 002DB2D4 3601A493 */  lbu        $4, 0x136($29)
    /* 1DB2D8 002DB2D8 3701A393 */  lbu        $3, 0x137($29)
    /* 1DB2DC 002DB2DC 790046A0 */  sb         $6, 0x79($2)
    /* 1DB2E0 002DB2E0 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DB2E4 002DB2E4 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DB2E8 002DB2E8 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DB2EC 002DB2EC 2D204002 */  daddu      $4, $18, $0
    /* 1DB2F0 002DB2F0 98AC110C */  jal        func_0046b260
    /* 1DB2F4 002DB2F4 00000000 */   nop
    /* 1DB2F8 002DB2F8 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1DB2FC 002DB2FC 00088244 */  mtc1       $2, $f1
    /* 1DB300 002DB300 00000000 */  nop
    /* 1DB304 002DB304 03000146 */  div.s      $f0, $f0, $f1
    /* 1DB308 002DB308 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1DB30C 002DB30C 00000244 */  mfc1       $2, $f0
    /* 1DB310 002DB310 00000000 */  nop
    /* 1DB314 002DB314 3C9C0200 */  dsll32     $19, $2, 16
    /* 1DB318 002DB318 3F9C1300 */  dsra32     $19, $19, 16
    /* 1DB31C 002DB31C 580D048E */  lw         $4, 0xD58($16)
    /* 1DB320 002DB320 38810B0C */  jal        func_002e04e0
    /* 1DB324 002DB324 00000000 */   nop
    /* 1DB328 002DB328 000153A4 */  sh         $19, 0x100($2)
    /* 1DB32C 002DB32C 2D204002 */  daddu      $4, $18, $0
    /* 1DB330 002DB330 BCAC110C */  jal        func_0046b2f0
    /* 1DB334 002DB334 00000000 */   nop
    /* 1DB338 002DB338 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1DB33C 002DB33C 00088244 */  mtc1       $2, $f1
    /* 1DB340 002DB340 00000000 */  nop
    /* 1DB344 002DB344 03000146 */  div.s      $f0, $f0, $f1
    /* 1DB348 002DB348 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1DB34C 002DB34C 00000244 */  mfc1       $2, $f0
    /* 1DB350 002DB350 00000000 */  nop
    /* 1DB354 002DB354 3C9C0200 */  dsll32     $19, $2, 16
    /* 1DB358 002DB358 3F9C1300 */  dsra32     $19, $19, 16
    /* 1DB35C 002DB35C 580D048E */  lw         $4, 0xD58($16)
    /* 1DB360 002DB360 38810B0C */  jal        func_002e04e0
    /* 1DB364 002DB364 00000000 */   nop
    /* 1DB368 002DB368 020153A4 */  sh         $19, 0x102($2)
    /* 1DB36C 002DB36C 580D048E */  lw         $4, 0xD58($16)
    /* 1DB370 002DB370 38810B0C */  jal        func_002e04e0
    /* 1DB374 002DB374 00000000 */   nop
    /* 1DB378 002DB378 C40054E4 */  swc1       $f20, 0xC4($2)
    /* 1DB37C 002DB37C 04002286 */  lh         $2, 0x4($17)
    /* 1DB380 002DB380 00008244 */  mtc1       $2, $f0
    /* 1DB384 002DB384 00000000 */  nop
    /* 1DB388 002DB388 20038046 */  cvt.s.w    $f12, $f0
    /* 1DB38C 002DB38C 580D048E */  lw         $4, 0xD58($16)
    /* 1DB390 002DB390 06002586 */  lh         $5, 0x6($17)
    /* 1DB394 002DB394 6C820B0C */  jal        func_002e09b0
    /* 1DB398 002DB398 00000000 */   nop
    /* 1DB39C 002DB39C 46A30046 */  mov.s      $f13, $f20
    /* 1DB3A0 002DB3A0 06002286 */  lh         $2, 0x6($17)
    /* 1DB3A4 002DB3A4 05004624 */  addiu      $6, $2, 0x5
    /* 1DB3A8 002DB3A8 580D048E */  lw         $4, 0xD58($16)
    /* 1DB3AC 002DB3AC 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1DB3B0 002DB3B0 02000524 */  addiu      $5, $0, 0x2
    /* 1DB3B4 002DB3B4 05000724 */  addiu      $7, $0, 0x5
    /* 1DB3B8 002DB3B8 50820B0C */  jal        func_002e0940
    /* 1DB3BC 002DB3BC 00000000 */   nop
    /* 1DB3C0 002DB3C0 2D204002 */  daddu      $4, $18, $0
    /* 1DB3C4 002DB3C4 A0B4110C */  jal        func_0046d280
    /* 1DB3C8 002DB3C8 00000000 */   nop
    /* 1DB3CC 002DB3CC 14000324 */  addiu      $3, $0, 0x14
    /* 1DB3D0 002DB3D0 000003A2 */  sb         $3, 0x0($16)
    /* 1DB3D4 002DB3D4 6000BFDF */  ld         $31, 0x60($29)
    /* 1DB3D8 002DB3D8 5000B47B */  lq         $20, 0x50($29)
    /* 1DB3DC 002DB3DC 4000B37B */  lq         $19, 0x40($29)
    /* 1DB3E0 002DB3E0 3000B27B */  lq         $18, 0x30($29)
    /* 1DB3E4 002DB3E4 2000B17B */  lq         $17, 0x20($29)
    /* 1DB3E8 002DB3E8 1000B07B */  lq         $16, 0x10($29)
    /* 1DB3EC 002DB3EC 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 1DB3F0 002DB3F0 6001BD27 */  addiu      $29, $29, 0x160
    /* 1DB3F4 002DB3F4 0800E003 */  jr         $31
    /* 1DB3F8 002DB3F8 00000000 */   nop
    /* 1DB3FC 002DB3FC 00000000 */  nop
.size func_002da0a0, 0x1360
