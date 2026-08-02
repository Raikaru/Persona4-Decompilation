.section .text
.set noat
.set noreorder
glabel func_002caef0
    /* 1CAEF0 002CAEF0 D0FEBD27 */  addiu      $29, $29, -0x130
    /* 1CAEF4 002CAEF4 2000BFFF */  sd         $31, 0x20($29)
    /* 1CAEF8 002CAEF8 1000B17F */  sq         $17, 0x10($29)
    /* 1CAEFC 002CAEFC 0000B07F */  sq         $16, 0x0($29)
    /* 1CAF00 002CAF00 3800908C */  lw         $16, 0x38($4)
    /* 1CAF04 002CAF04 6400113C */  lui        $17, %hi(D_0063F5B0)
    /* 1CAF08 002CAF08 B0F53126 */  addiu      $17, $17, %lo(D_0063F5B0)
    /* 1CAF0C 002CAF0C DA42023C */  lui        $2, (0x42DA0000 >> 16)
    /* 1CAF10 002CAF10 00608244 */  mtc1       $2, $f12
    /* 1CAF14 002CAF14 EC0E048E */  lw         $4, 0xEEC($16)
    /* 1CAF18 002CAF18 41000524 */  addiu      $5, $0, 0x41
    /* 1CAF1C 002CAF1C 98820B0C */  jal        func_002e0a60
    /* 1CAF20 002CAF20 00000000 */   nop
    /* 1CAF24 002CAF24 1001A427 */  addiu      $4, $29, 0x110
    /* 1CAF28 002CAF28 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1CAF2C 002CAF2C 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1CAF30 002CAF30 5CCA0A0C */  jal        func_002b2970
    /* 1CAF34 002CAF34 00000000 */   nop
    /* 1CAF38 002CAF38 000021C6 */  lwc1       $f1, 0x0($17)
    /* 1CAF3C 002CAF3C EE020224 */  addiu      $2, $0, 0x2EE
    /* 1CAF40 002CAF40 00008244 */  mtc1       $2, $f0
    /* 1CAF44 002CAF44 00000000 */  nop
    /* 1CAF48 002CAF48 20008046 */  cvt.s.w    $f0, $f0
    /* 1CAF4C 002CAF4C 010B0046 */  sub.s      $f12, $f1, $f0
    /* 1CAF50 002CAF50 0801A427 */  addiu      $4, $29, 0x108
    /* 1CAF54 002CAF54 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1CAF58 002CAF58 5CCA0A0C */  jal        func_002b2970
    /* 1CAF5C 002CAF5C 00000000 */   nop
    /* 1CAF60 002CAF60 EC0E048E */  lw         $4, 0xEEC($16)
    /* 1CAF64 002CAF64 1001A5DF */  ld         $5, 0x110($29)
    /* 1CAF68 002CAF68 0801A6DF */  ld         $6, 0x108($29)
    /* 1CAF6C 002CAF6C 2D380000 */  daddu      $7, $0, $0
    /* 1CAF70 002CAF70 04000824 */  addiu      $8, $0, 0x4
    /* 1CAF74 002CAF74 2D480000 */  daddu      $9, $0, $0
    /* 1CAF78 002CAF78 88810B0C */  jal        func_002e0620
    /* 1CAF7C 002CAF7C 00000000 */   nop
    /* 1CAF80 002CAF80 CC001124 */  addiu      $17, $0, 0xCC
    /* 1CAF84 002CAF84 EC0E048E */  lw         $4, 0xEEC($16)
    /* 1CAF88 002CAF88 38810B0C */  jal        func_002e04e0
    /* 1CAF8C 002CAF8C 00000000 */   nop
    /* 1CAF90 002CAF90 620051A0 */  sb         $17, 0x62($2)
    /* 1CAF94 002CAF94 2C01A427 */  addiu      $4, $29, 0x12C
    /* 1CAF98 002CAF98 2D280000 */  daddu      $5, $0, $0
    /* 1CAF9C 002CAF9C 2D300000 */  daddu      $6, $0, $0
    /* 1CAFA0 002CAFA0 2D380000 */  daddu      $7, $0, $0
    /* 1CAFA4 002CAFA4 FF000824 */  addiu      $8, $0, 0xFF
    /* 1CAFA8 002CAFA8 98CA0A0C */  jal        func_002b2a60
    /* 1CAFAC 002CAFAC 00000000 */   nop
    /* 1CAFB0 002CAFB0 EC0E048E */  lw         $4, 0xEEC($16)
    /* 1CAFB4 002CAFB4 38810B0C */  jal        func_002e04e0
    /* 1CAFB8 002CAFB8 00000000 */   nop
    /* 1CAFBC 002CAFBC 2C01A693 */  lbu        $6, 0x12C($29)
    /* 1CAFC0 002CAFC0 2D01A593 */  lbu        $5, 0x12D($29)
    /* 1CAFC4 002CAFC4 2E01A493 */  lbu        $4, 0x12E($29)
    /* 1CAFC8 002CAFC8 2F01A393 */  lbu        $3, 0x12F($29)
    /* 1CAFCC 002CAFCC 790046A0 */  sb         $6, 0x79($2)
    /* 1CAFD0 002CAFD0 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1CAFD4 002CAFD4 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1CAFD8 002CAFD8 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1CAFDC 002CAFDC 6400113C */  lui        $17, %hi(D_0063F5F0)
    /* 1CAFE0 002CAFE0 F0F53126 */  addiu      $17, $17, %lo(D_0063F5F0)
    /* 1CAFE4 002CAFE4 DA42023C */  lui        $2, (0x42DA0000 >> 16)
    /* 1CAFE8 002CAFE8 00608244 */  mtc1       $2, $f12
    /* 1CAFEC 002CAFEC F40E048E */  lw         $4, 0xEF4($16)
    /* 1CAFF0 002CAFF0 41000524 */  addiu      $5, $0, 0x41
    /* 1CAFF4 002CAFF4 98820B0C */  jal        func_002e0a60
    /* 1CAFF8 002CAFF8 00000000 */   nop
    /* 1CAFFC 002CAFFC 0001A427 */  addiu      $4, $29, 0x100
    /* 1CB000 002CB000 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1CB004 002CB004 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1CB008 002CB008 5CCA0A0C */  jal        func_002b2970
    /* 1CB00C 002CB00C 00000000 */   nop
    /* 1CB010 002CB010 000021C6 */  lwc1       $f1, 0x0($17)
    /* 1CB014 002CB014 EE020224 */  addiu      $2, $0, 0x2EE
    /* 1CB018 002CB018 00008244 */  mtc1       $2, $f0
    /* 1CB01C 002CB01C 00000000 */  nop
    /* 1CB020 002CB020 20008046 */  cvt.s.w    $f0, $f0
    /* 1CB024 002CB024 010B0046 */  sub.s      $f12, $f1, $f0
    /* 1CB028 002CB028 F800A427 */  addiu      $4, $29, 0xF8
    /* 1CB02C 002CB02C 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1CB030 002CB030 5CCA0A0C */  jal        func_002b2970
    /* 1CB034 002CB034 00000000 */   nop
    /* 1CB038 002CB038 F40E048E */  lw         $4, 0xEF4($16)
    /* 1CB03C 002CB03C 0001A5DF */  ld         $5, 0x100($29)
    /* 1CB040 002CB040 F800A6DF */  ld         $6, 0xF8($29)
    /* 1CB044 002CB044 2D380000 */  daddu      $7, $0, $0
    /* 1CB048 002CB048 04000824 */  addiu      $8, $0, 0x4
    /* 1CB04C 002CB04C 2D480000 */  daddu      $9, $0, $0
    /* 1CB050 002CB050 88810B0C */  jal        func_002e0620
    /* 1CB054 002CB054 00000000 */   nop
    /* 1CB058 002CB058 CC001124 */  addiu      $17, $0, 0xCC
    /* 1CB05C 002CB05C F40E048E */  lw         $4, 0xEF4($16)
    /* 1CB060 002CB060 38810B0C */  jal        func_002e04e0
    /* 1CB064 002CB064 00000000 */   nop
    /* 1CB068 002CB068 620051A0 */  sb         $17, 0x62($2)
    /* 1CB06C 002CB06C 2801A427 */  addiu      $4, $29, 0x128
    /* 1CB070 002CB070 2D280000 */  daddu      $5, $0, $0
    /* 1CB074 002CB074 2D300000 */  daddu      $6, $0, $0
    /* 1CB078 002CB078 2D380000 */  daddu      $7, $0, $0
    /* 1CB07C 002CB07C FF000824 */  addiu      $8, $0, 0xFF
    /* 1CB080 002CB080 98CA0A0C */  jal        func_002b2a60
    /* 1CB084 002CB084 00000000 */   nop
    /* 1CB088 002CB088 F40E048E */  lw         $4, 0xEF4($16)
    /* 1CB08C 002CB08C 38810B0C */  jal        func_002e04e0
    /* 1CB090 002CB090 00000000 */   nop
    /* 1CB094 002CB094 2801A693 */  lbu        $6, 0x128($29)
    /* 1CB098 002CB098 2901A593 */  lbu        $5, 0x129($29)
    /* 1CB09C 002CB09C 2A01A493 */  lbu        $4, 0x12A($29)
    /* 1CB0A0 002CB0A0 2B01A393 */  lbu        $3, 0x12B($29)
    /* 1CB0A4 002CB0A4 790046A0 */  sb         $6, 0x79($2)
    /* 1CB0A8 002CB0A8 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1CB0AC 002CB0AC 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1CB0B0 002CB0B0 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1CB0B4 002CB0B4 6400113C */  lui        $17, %hi(D_0063F5D0)
    /* 1CB0B8 002CB0B8 D0F53126 */  addiu      $17, $17, %lo(D_0063F5D0)
    /* 1CB0BC 002CB0BC DE42023C */  lui        $2, (0x42DE0000 >> 16)
    /* 1CB0C0 002CB0C0 00608244 */  mtc1       $2, $f12
    /* 1CB0C4 002CB0C4 F80E048E */  lw         $4, 0xEF8($16)
    /* 1CB0C8 002CB0C8 41000524 */  addiu      $5, $0, 0x41
    /* 1CB0CC 002CB0CC 98820B0C */  jal        func_002e0a60
    /* 1CB0D0 002CB0D0 00000000 */   nop
    /* 1CB0D4 002CB0D4 F000A427 */  addiu      $4, $29, 0xF0
    /* 1CB0D8 002CB0D8 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1CB0DC 002CB0DC 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1CB0E0 002CB0E0 5CCA0A0C */  jal        func_002b2970
    /* 1CB0E4 002CB0E4 00000000 */   nop
    /* 1CB0E8 002CB0E8 000021C6 */  lwc1       $f1, 0x0($17)
    /* 1CB0EC 002CB0EC EE020224 */  addiu      $2, $0, 0x2EE
    /* 1CB0F0 002CB0F0 00008244 */  mtc1       $2, $f0
    /* 1CB0F4 002CB0F4 00000000 */  nop
    /* 1CB0F8 002CB0F8 20008046 */  cvt.s.w    $f0, $f0
    /* 1CB0FC 002CB0FC 010B0046 */  sub.s      $f12, $f1, $f0
    /* 1CB100 002CB100 E800A427 */  addiu      $4, $29, 0xE8
    /* 1CB104 002CB104 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1CB108 002CB108 5CCA0A0C */  jal        func_002b2970
    /* 1CB10C 002CB10C 00000000 */   nop
    /* 1CB110 002CB110 F80E048E */  lw         $4, 0xEF8($16)
    /* 1CB114 002CB114 F000A5DF */  ld         $5, 0xF0($29)
    /* 1CB118 002CB118 E800A6DF */  ld         $6, 0xE8($29)
    /* 1CB11C 002CB11C 2D380000 */  daddu      $7, $0, $0
    /* 1CB120 002CB120 04000824 */  addiu      $8, $0, 0x4
    /* 1CB124 002CB124 2D480000 */  daddu      $9, $0, $0
    /* 1CB128 002CB128 88810B0C */  jal        func_002e0620
    /* 1CB12C 002CB12C 00000000 */   nop
    /* 1CB130 002CB130 CC001124 */  addiu      $17, $0, 0xCC
    /* 1CB134 002CB134 F80E048E */  lw         $4, 0xEF8($16)
    /* 1CB138 002CB138 38810B0C */  jal        func_002e04e0
    /* 1CB13C 002CB13C 00000000 */   nop
    /* 1CB140 002CB140 620051A0 */  sb         $17, 0x62($2)
    /* 1CB144 002CB144 2401A427 */  addiu      $4, $29, 0x124
    /* 1CB148 002CB148 2D280000 */  daddu      $5, $0, $0
    /* 1CB14C 002CB14C 2D300000 */  daddu      $6, $0, $0
    /* 1CB150 002CB150 2D380000 */  daddu      $7, $0, $0
    /* 1CB154 002CB154 FF000824 */  addiu      $8, $0, 0xFF
    /* 1CB158 002CB158 98CA0A0C */  jal        func_002b2a60
    /* 1CB15C 002CB15C 00000000 */   nop
    /* 1CB160 002CB160 F80E048E */  lw         $4, 0xEF8($16)
    /* 1CB164 002CB164 38810B0C */  jal        func_002e04e0
    /* 1CB168 002CB168 00000000 */   nop
    /* 1CB16C 002CB16C 2401A693 */  lbu        $6, 0x124($29)
    /* 1CB170 002CB170 2501A593 */  lbu        $5, 0x125($29)
    /* 1CB174 002CB174 2601A493 */  lbu        $4, 0x126($29)
    /* 1CB178 002CB178 2701A393 */  lbu        $3, 0x127($29)
    /* 1CB17C 002CB17C 790046A0 */  sb         $6, 0x79($2)
    /* 1CB180 002CB180 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1CB184 002CB184 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1CB188 002CB188 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1CB18C 002CB18C DA42023C */  lui        $2, (0x42DA0000 >> 16)
    /* 1CB190 002CB190 00608244 */  mtc1       $2, $f12
    /* 1CB194 002CB194 F00E048E */  lw         $4, 0xEF0($16)
    /* 1CB198 002CB198 41000524 */  addiu      $5, $0, 0x41
    /* 1CB19C 002CB19C 98820B0C */  jal        func_002e0a60
    /* 1CB1A0 002CB1A0 00000000 */   nop
    /* 1CB1A4 002CB1A4 AC42023C */  lui        $2, (0x42AC0000 >> 16)
    /* 1CB1A8 002CB1A8 00608244 */  mtc1       $2, $f12
    /* 1CB1AC 002CB1AC 7243023C */  lui        $2, (0x43720000 >> 16)
    /* 1CB1B0 002CB1B0 00688244 */  mtc1       $2, $f13
    /* 1CB1B4 002CB1B4 E000A427 */  addiu      $4, $29, 0xE0
    /* 1CB1B8 002CB1B8 5CCA0A0C */  jal        func_002b2970
    /* 1CB1BC 002CB1BC 00000000 */   nop
    /* 1CB1C0 002CB1C0 12030224 */  addiu      $2, $0, 0x312
    /* 1CB1C4 002CB1C4 00008244 */  mtc1       $2, $f0
    /* 1CB1C8 002CB1C8 00000000 */  nop
    /* 1CB1CC 002CB1CC 20038046 */  cvt.s.w    $f12, $f0
    /* 1CB1D0 002CB1D0 7243023C */  lui        $2, (0x43720000 >> 16)
    /* 1CB1D4 002CB1D4 00688244 */  mtc1       $2, $f13
    /* 1CB1D8 002CB1D8 D800A427 */  addiu      $4, $29, 0xD8
    /* 1CB1DC 002CB1DC 5CCA0A0C */  jal        func_002b2970
    /* 1CB1E0 002CB1E0 00000000 */   nop
    /* 1CB1E4 002CB1E4 F00E048E */  lw         $4, 0xEF0($16)
    /* 1CB1E8 002CB1E8 E000A5DF */  ld         $5, 0xE0($29)
    /* 1CB1EC 002CB1EC D800A6DF */  ld         $6, 0xD8($29)
    /* 1CB1F0 002CB1F0 2D380000 */  daddu      $7, $0, $0
    /* 1CB1F4 002CB1F4 04000824 */  addiu      $8, $0, 0x4
    /* 1CB1F8 002CB1F8 2D480000 */  daddu      $9, $0, $0
    /* 1CB1FC 002CB1FC 88810B0C */  jal        func_002e0620
    /* 1CB200 002CB200 00000000 */   nop
    /* 1CB204 002CB204 2001A427 */  addiu      $4, $29, 0x120
    /* 1CB208 002CB208 FF000524 */  addiu      $5, $0, 0xFF
    /* 1CB20C 002CB20C CB000624 */  addiu      $6, $0, 0xCB
    /* 1CB210 002CB210 35000724 */  addiu      $7, $0, 0x35
    /* 1CB214 002CB214 2D40A000 */  daddu      $8, $5, $0
    /* 1CB218 002CB218 98CA0A0C */  jal        func_002b2a60
    /* 1CB21C 002CB21C 00000000 */   nop
    /* 1CB220 002CB220 F00E048E */  lw         $4, 0xEF0($16)
    /* 1CB224 002CB224 38810B0C */  jal        func_002e04e0
    /* 1CB228 002CB228 00000000 */   nop
    /* 1CB22C 002CB22C 2001A693 */  lbu        $6, 0x120($29)
    /* 1CB230 002CB230 2101A593 */  lbu        $5, 0x121($29)
    /* 1CB234 002CB234 2201A493 */  lbu        $4, 0x122($29)
    /* 1CB238 002CB238 2301A393 */  lbu        $3, 0x123($29)
    /* 1CB23C 002CB23C 790046A0 */  sb         $6, 0x79($2)
    /* 1CB240 002CB240 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1CB244 002CB244 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1CB248 002CB248 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1CB24C 002CB24C 6400113C */  lui        $17, %hi(D_0063F5F8)
    /* 1CB250 002CB250 F8F53126 */  addiu      $17, $17, %lo(D_0063F5F8)
    /* 1CB254 002CB254 E042023C */  lui        $2, (0x42E00000 >> 16)
    /* 1CB258 002CB258 00608244 */  mtc1       $2, $f12
    /* 1CB25C 002CB25C FC0E048E */  lw         $4, 0xEFC($16)
    /* 1CB260 002CB260 41000524 */  addiu      $5, $0, 0x41
    /* 1CB264 002CB264 98820B0C */  jal        func_002e0a60
    /* 1CB268 002CB268 00000000 */   nop
    /* 1CB26C 002CB26C D000A427 */  addiu      $4, $29, 0xD0
    /* 1CB270 002CB270 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1CB274 002CB274 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1CB278 002CB278 5CCA0A0C */  jal        func_002b2970
    /* 1CB27C 002CB27C 00000000 */   nop
    /* 1CB280 002CB280 2F44023C */  lui        $2, (0x442F0000 >> 16)
    /* 1CB284 002CB284 00088244 */  mtc1       $2, $f1
    /* 1CB288 002CB288 000020C6 */  lwc1       $f0, 0x0($17)
    /* 1CB28C 002CB28C 000B0046 */  add.s      $f12, $f1, $f0
    /* 1CB290 002CB290 C800A427 */  addiu      $4, $29, 0xC8
    /* 1CB294 002CB294 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1CB298 002CB298 5CCA0A0C */  jal        func_002b2970
    /* 1CB29C 002CB29C 00000000 */   nop
    /* 1CB2A0 002CB2A0 FC0E048E */  lw         $4, 0xEFC($16)
    /* 1CB2A4 002CB2A4 D000A5DF */  ld         $5, 0xD0($29)
    /* 1CB2A8 002CB2A8 C800A6DF */  ld         $6, 0xC8($29)
    /* 1CB2AC 002CB2AC 2D380000 */  daddu      $7, $0, $0
    /* 1CB2B0 002CB2B0 04000824 */  addiu      $8, $0, 0x4
    /* 1CB2B4 002CB2B4 2D480000 */  daddu      $9, $0, $0
    /* 1CB2B8 002CB2B8 88810B0C */  jal        func_002e0620
    /* 1CB2BC 002CB2BC 00000000 */   nop
    /* 1CB2C0 002CB2C0 1C01A427 */  addiu      $4, $29, 0x11C
    /* 1CB2C4 002CB2C4 FF000524 */  addiu      $5, $0, 0xFF
    /* 1CB2C8 002CB2C8 CB000624 */  addiu      $6, $0, 0xCB
    /* 1CB2CC 002CB2CC 35000724 */  addiu      $7, $0, 0x35
    /* 1CB2D0 002CB2D0 2D40A000 */  daddu      $8, $5, $0
    /* 1CB2D4 002CB2D4 98CA0A0C */  jal        func_002b2a60
    /* 1CB2D8 002CB2D8 00000000 */   nop
    /* 1CB2DC 002CB2DC FC0E048E */  lw         $4, 0xEFC($16)
    /* 1CB2E0 002CB2E0 38810B0C */  jal        func_002e04e0
    /* 1CB2E4 002CB2E4 00000000 */   nop
    /* 1CB2E8 002CB2E8 1C01A693 */  lbu        $6, 0x11C($29)
    /* 1CB2EC 002CB2EC 1D01A593 */  lbu        $5, 0x11D($29)
    /* 1CB2F0 002CB2F0 1E01A493 */  lbu        $4, 0x11E($29)
    /* 1CB2F4 002CB2F4 1F01A393 */  lbu        $3, 0x11F($29)
    /* 1CB2F8 002CB2F8 790046A0 */  sb         $6, 0x79($2)
    /* 1CB2FC 002CB2FC 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1CB300 002CB300 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1CB304 002CB304 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1CB308 002CB308 6400113C */  lui        $17, %hi(D_0063F5D8)
    /* 1CB30C 002CB30C D8F53126 */  addiu      $17, $17, %lo(D_0063F5D8)
    /* 1CB310 002CB310 E242023C */  lui        $2, (0x42E20000 >> 16)
    /* 1CB314 002CB314 00608244 */  mtc1       $2, $f12
    /* 1CB318 002CB318 000F048E */  lw         $4, 0xF00($16)
    /* 1CB31C 002CB31C 41000524 */  addiu      $5, $0, 0x41
    /* 1CB320 002CB320 98820B0C */  jal        func_002e0a60
    /* 1CB324 002CB324 00000000 */   nop
    /* 1CB328 002CB328 C000A427 */  addiu      $4, $29, 0xC0
    /* 1CB32C 002CB32C 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1CB330 002CB330 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1CB334 002CB334 5CCA0A0C */  jal        func_002b2970
    /* 1CB338 002CB338 00000000 */   nop
    /* 1CB33C 002CB33C 2F44023C */  lui        $2, (0x442F0000 >> 16)
    /* 1CB340 002CB340 00088244 */  mtc1       $2, $f1
    /* 1CB344 002CB344 000020C6 */  lwc1       $f0, 0x0($17)
    /* 1CB348 002CB348 000B0046 */  add.s      $f12, $f1, $f0
    /* 1CB34C 002CB34C B800A427 */  addiu      $4, $29, 0xB8
    /* 1CB350 002CB350 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1CB354 002CB354 5CCA0A0C */  jal        func_002b2970
    /* 1CB358 002CB358 00000000 */   nop
    /* 1CB35C 002CB35C 000F048E */  lw         $4, 0xF00($16)
    /* 1CB360 002CB360 C000A5DF */  ld         $5, 0xC0($29)
    /* 1CB364 002CB364 B800A6DF */  ld         $6, 0xB8($29)
    /* 1CB368 002CB368 2D380000 */  daddu      $7, $0, $0
    /* 1CB36C 002CB36C 04000824 */  addiu      $8, $0, 0x4
    /* 1CB370 002CB370 2D480000 */  daddu      $9, $0, $0
    /* 1CB374 002CB374 88810B0C */  jal        func_002e0620
    /* 1CB378 002CB378 00000000 */   nop
    /* 1CB37C 002CB37C 6400113C */  lui        $17, %hi(D_0063F5E0)
    /* 1CB380 002CB380 E0F53126 */  addiu      $17, $17, %lo(D_0063F5E0)
    /* 1CB384 002CB384 E442023C */  lui        $2, (0x42E40000 >> 16)
    /* 1CB388 002CB388 00608244 */  mtc1       $2, $f12
    /* 1CB38C 002CB38C 040F048E */  lw         $4, 0xF04($16)
    /* 1CB390 002CB390 41000524 */  addiu      $5, $0, 0x41
    /* 1CB394 002CB394 98820B0C */  jal        func_002e0a60
    /* 1CB398 002CB398 00000000 */   nop
    /* 1CB39C 002CB39C B000A427 */  addiu      $4, $29, 0xB0
    /* 1CB3A0 002CB3A0 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1CB3A4 002CB3A4 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1CB3A8 002CB3A8 5CCA0A0C */  jal        func_002b2970
    /* 1CB3AC 002CB3AC 00000000 */   nop
    /* 1CB3B0 002CB3B0 2F44023C */  lui        $2, (0x442F0000 >> 16)
    /* 1CB3B4 002CB3B4 00088244 */  mtc1       $2, $f1
    /* 1CB3B8 002CB3B8 000020C6 */  lwc1       $f0, 0x0($17)
    /* 1CB3BC 002CB3BC 000B0046 */  add.s      $f12, $f1, $f0
    /* 1CB3C0 002CB3C0 A800A427 */  addiu      $4, $29, 0xA8
    /* 1CB3C4 002CB3C4 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1CB3C8 002CB3C8 5CCA0A0C */  jal        func_002b2970
    /* 1CB3CC 002CB3CC 00000000 */   nop
    /* 1CB3D0 002CB3D0 040F048E */  lw         $4, 0xF04($16)
    /* 1CB3D4 002CB3D4 B000A5DF */  ld         $5, 0xB0($29)
    /* 1CB3D8 002CB3D8 A800A6DF */  ld         $6, 0xA8($29)
    /* 1CB3DC 002CB3DC 2D380000 */  daddu      $7, $0, $0
    /* 1CB3E0 002CB3E0 04000824 */  addiu      $8, $0, 0x4
    /* 1CB3E4 002CB3E4 2D480000 */  daddu      $9, $0, $0
    /* 1CB3E8 002CB3E8 88810B0C */  jal        func_002e0620
    /* 1CB3EC 002CB3EC 00000000 */   nop
    /* 1CB3F0 002CB3F0 6400113C */  lui        $17, %hi(D_0063F5B0)
    /* 1CB3F4 002CB3F4 B0F53126 */  addiu      $17, $17, %lo(D_0063F5B0)
    /* 1CB3F8 002CB3F8 2544023C */  lui        $2, (0x44250000 >> 16)
    /* 1CB3FC 002CB3FC 00088244 */  mtc1       $2, $f1
    /* 1CB400 002CB400 000020C6 */  lwc1       $f0, 0x0($17)
    /* 1CB404 002CB404 000B0046 */  add.s      $f12, $f1, $f0
    /* 1CB408 002CB408 A000A427 */  addiu      $4, $29, 0xA0
    /* 1CB40C 002CB40C 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1CB410 002CB410 5CCA0A0C */  jal        func_002b2970
    /* 1CB414 002CB414 00000000 */   nop
    /* 1CB418 002CB418 9800A427 */  addiu      $4, $29, 0x98
    /* 1CB41C 002CB41C 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1CB420 002CB420 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1CB424 002CB424 5CCA0A0C */  jal        func_002b2970
    /* 1CB428 002CB428 00000000 */   nop
    /* 1CB42C 002CB42C 600C048E */  lw         $4, 0xC60($16)
    /* 1CB430 002CB430 A000A5DF */  ld         $5, 0xA0($29)
    /* 1CB434 002CB434 9800A6DF */  ld         $6, 0x98($29)
    /* 1CB438 002CB438 2D380000 */  daddu      $7, $0, $0
    /* 1CB43C 002CB43C 04000824 */  addiu      $8, $0, 0x4
    /* 1CB440 002CB440 06000924 */  addiu      $9, $0, 0x6
    /* 1CB444 002CB444 88810B0C */  jal        func_002e0620
    /* 1CB448 002CB448 00000000 */   nop
    /* 1CB44C 002CB44C 6400113C */  lui        $17, %hi(D_0063F5F0)
    /* 1CB450 002CB450 F0F53126 */  addiu      $17, $17, %lo(D_0063F5F0)
    /* 1CB454 002CB454 2544023C */  lui        $2, (0x44250000 >> 16)
    /* 1CB458 002CB458 00088244 */  mtc1       $2, $f1
    /* 1CB45C 002CB45C 000020C6 */  lwc1       $f0, 0x0($17)
    /* 1CB460 002CB460 000B0046 */  add.s      $f12, $f1, $f0
    /* 1CB464 002CB464 9000A427 */  addiu      $4, $29, 0x90
    /* 1CB468 002CB468 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1CB46C 002CB46C 5CCA0A0C */  jal        func_002b2970
    /* 1CB470 002CB470 00000000 */   nop
    /* 1CB474 002CB474 8800A427 */  addiu      $4, $29, 0x88
    /* 1CB478 002CB478 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1CB47C 002CB47C 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1CB480 002CB480 5CCA0A0C */  jal        func_002b2970
    /* 1CB484 002CB484 00000000 */   nop
    /* 1CB488 002CB488 800C048E */  lw         $4, 0xC80($16)
    /* 1CB48C 002CB48C 9000A5DF */  ld         $5, 0x90($29)
    /* 1CB490 002CB490 8800A6DF */  ld         $6, 0x88($29)
    /* 1CB494 002CB494 2D380000 */  daddu      $7, $0, $0
    /* 1CB498 002CB498 04000824 */  addiu      $8, $0, 0x4
    /* 1CB49C 002CB49C 06000924 */  addiu      $9, $0, 0x6
    /* 1CB4A0 002CB4A0 88810B0C */  jal        func_002e0620
    /* 1CB4A4 002CB4A4 00000000 */   nop
    /* 1CB4A8 002CB4A8 6400113C */  lui        $17, %hi(D_0063F5D0)
    /* 1CB4AC 002CB4AC D0F53126 */  addiu      $17, $17, %lo(D_0063F5D0)
    /* 1CB4B0 002CB4B0 2544023C */  lui        $2, (0x44250000 >> 16)
    /* 1CB4B4 002CB4B4 00088244 */  mtc1       $2, $f1
    /* 1CB4B8 002CB4B8 000020C6 */  lwc1       $f0, 0x0($17)
    /* 1CB4BC 002CB4BC 000B0046 */  add.s      $f12, $f1, $f0
    /* 1CB4C0 002CB4C0 8000A427 */  addiu      $4, $29, 0x80
    /* 1CB4C4 002CB4C4 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1CB4C8 002CB4C8 5CCA0A0C */  jal        func_002b2970
    /* 1CB4CC 002CB4CC 00000000 */   nop
    /* 1CB4D0 002CB4D0 7800A427 */  addiu      $4, $29, 0x78
    /* 1CB4D4 002CB4D4 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1CB4D8 002CB4D8 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1CB4DC 002CB4DC 5CCA0A0C */  jal        func_002b2970
    /* 1CB4E0 002CB4E0 00000000 */   nop
    /* 1CB4E4 002CB4E4 700C048E */  lw         $4, 0xC70($16)
    /* 1CB4E8 002CB4E8 8000A5DF */  ld         $5, 0x80($29)
    /* 1CB4EC 002CB4EC 7800A6DF */  ld         $6, 0x78($29)
    /* 1CB4F0 002CB4F0 2D380000 */  daddu      $7, $0, $0
    /* 1CB4F4 002CB4F4 04000824 */  addiu      $8, $0, 0x4
    /* 1CB4F8 002CB4F8 06000924 */  addiu      $9, $0, 0x6
    /* 1CB4FC 002CB4FC 88810B0C */  jal        func_002e0620
    /* 1CB500 002CB500 00000000 */   nop
    /* 1CB504 002CB504 9AFD0224 */  addiu      $2, $0, -0x266
    /* 1CB508 002CB508 00008244 */  mtc1       $2, $f0
    /* 1CB50C 002CB50C 00000000 */  nop
    /* 1CB510 002CB510 20038046 */  cvt.s.w    $f12, $f0
    /* 1CB514 002CB514 7243023C */  lui        $2, (0x43720000 >> 16)
    /* 1CB518 002CB518 00688244 */  mtc1       $2, $f13
    /* 1CB51C 002CB51C 7000A427 */  addiu      $4, $29, 0x70
    /* 1CB520 002CB520 5CCA0A0C */  jal        func_002b2970
    /* 1CB524 002CB524 00000000 */   nop
    /* 1CB528 002CB528 AC42023C */  lui        $2, (0x42AC0000 >> 16)
    /* 1CB52C 002CB52C 00608244 */  mtc1       $2, $f12
    /* 1CB530 002CB530 7243023C */  lui        $2, (0x43720000 >> 16)
    /* 1CB534 002CB534 00688244 */  mtc1       $2, $f13
    /* 1CB538 002CB538 6800A427 */  addiu      $4, $29, 0x68
    /* 1CB53C 002CB53C 5CCA0A0C */  jal        func_002b2970
    /* 1CB540 002CB540 00000000 */   nop
    /* 1CB544 002CB544 800E048E */  lw         $4, 0xE80($16)
    /* 1CB548 002CB548 7000A5DF */  ld         $5, 0x70($29)
    /* 1CB54C 002CB54C 6800A6DF */  ld         $6, 0x68($29)
    /* 1CB550 002CB550 2D380000 */  daddu      $7, $0, $0
    /* 1CB554 002CB554 04000824 */  addiu      $8, $0, 0x4
    /* 1CB558 002CB558 06000924 */  addiu      $9, $0, 0x6
    /* 1CB55C 002CB55C 88810B0C */  jal        func_002e0620
    /* 1CB560 002CB560 00000000 */   nop
    /* 1CB564 002CB564 6400113C */  lui        $17, %hi(D_0063F5F8)
    /* 1CB568 002CB568 F8F53126 */  addiu      $17, $17, %lo(D_0063F5F8)
    /* 1CB56C 002CB56C 000021C6 */  lwc1       $f1, 0x0($17)
    /* 1CB570 002CB570 2F44023C */  lui        $2, (0x442F0000 >> 16)
    /* 1CB574 002CB574 00008244 */  mtc1       $2, $f0
    /* 1CB578 002CB578 00000000 */  nop
    /* 1CB57C 002CB57C 010B0046 */  sub.s      $f12, $f1, $f0
    /* 1CB580 002CB580 6000A427 */  addiu      $4, $29, 0x60
    /* 1CB584 002CB584 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1CB588 002CB588 5CCA0A0C */  jal        func_002b2970
    /* 1CB58C 002CB58C 00000000 */   nop
    /* 1CB590 002CB590 5800A427 */  addiu      $4, $29, 0x58
    /* 1CB594 002CB594 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1CB598 002CB598 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1CB59C 002CB59C 5CCA0A0C */  jal        func_002b2970
    /* 1CB5A0 002CB5A0 00000000 */   nop
    /* 1CB5A4 002CB5A4 840C048E */  lw         $4, 0xC84($16)
    /* 1CB5A8 002CB5A8 6000A5DF */  ld         $5, 0x60($29)
    /* 1CB5AC 002CB5AC 5800A6DF */  ld         $6, 0x58($29)
    /* 1CB5B0 002CB5B0 2D380000 */  daddu      $7, $0, $0
    /* 1CB5B4 002CB5B4 04000824 */  addiu      $8, $0, 0x4
    /* 1CB5B8 002CB5B8 06000924 */  addiu      $9, $0, 0x6
    /* 1CB5BC 002CB5BC 88810B0C */  jal        func_002e0620
    /* 1CB5C0 002CB5C0 00000000 */   nop
    /* 1CB5C4 002CB5C4 6400113C */  lui        $17, %hi(D_0063F5D8)
    /* 1CB5C8 002CB5C8 D8F53126 */  addiu      $17, $17, %lo(D_0063F5D8)
    /* 1CB5CC 002CB5CC 000021C6 */  lwc1       $f1, 0x0($17)
    /* 1CB5D0 002CB5D0 2F44023C */  lui        $2, (0x442F0000 >> 16)
    /* 1CB5D4 002CB5D4 00008244 */  mtc1       $2, $f0
    /* 1CB5D8 002CB5D8 00000000 */  nop
    /* 1CB5DC 002CB5DC 010B0046 */  sub.s      $f12, $f1, $f0
    /* 1CB5E0 002CB5E0 5000A427 */  addiu      $4, $29, 0x50
    /* 1CB5E4 002CB5E4 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1CB5E8 002CB5E8 5CCA0A0C */  jal        func_002b2970
    /* 1CB5EC 002CB5EC 00000000 */   nop
    /* 1CB5F0 002CB5F0 4800A427 */  addiu      $4, $29, 0x48
    /* 1CB5F4 002CB5F4 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1CB5F8 002CB5F8 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1CB5FC 002CB5FC 5CCA0A0C */  jal        func_002b2970
    /* 1CB600 002CB600 00000000 */   nop
    /* 1CB604 002CB604 740C048E */  lw         $4, 0xC74($16)
    /* 1CB608 002CB608 5000A5DF */  ld         $5, 0x50($29)
    /* 1CB60C 002CB60C 4800A6DF */  ld         $6, 0x48($29)
    /* 1CB610 002CB610 2D380000 */  daddu      $7, $0, $0
    /* 1CB614 002CB614 04000824 */  addiu      $8, $0, 0x4
    /* 1CB618 002CB618 06000924 */  addiu      $9, $0, 0x6
    /* 1CB61C 002CB61C 88810B0C */  jal        func_002e0620
    /* 1CB620 002CB620 00000000 */   nop
    /* 1CB624 002CB624 6400113C */  lui        $17, %hi(D_0063F5E0)
    /* 1CB628 002CB628 E0F53126 */  addiu      $17, $17, %lo(D_0063F5E0)
    /* 1CB62C 002CB62C 000021C6 */  lwc1       $f1, 0x0($17)
    /* 1CB630 002CB630 2F44023C */  lui        $2, (0x442F0000 >> 16)
    /* 1CB634 002CB634 00008244 */  mtc1       $2, $f0
    /* 1CB638 002CB638 00000000 */  nop
    /* 1CB63C 002CB63C 010B0046 */  sub.s      $f12, $f1, $f0
    /* 1CB640 002CB640 4000A427 */  addiu      $4, $29, 0x40
    /* 1CB644 002CB644 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1CB648 002CB648 5CCA0A0C */  jal        func_002b2970
    /* 1CB64C 002CB64C 00000000 */   nop
    /* 1CB650 002CB650 3800A427 */  addiu      $4, $29, 0x38
    /* 1CB654 002CB654 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1CB658 002CB658 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1CB65C 002CB65C 5CCA0A0C */  jal        func_002b2970
    /* 1CB660 002CB660 00000000 */   nop
    /* 1CB664 002CB664 780C048E */  lw         $4, 0xC78($16)
    /* 1CB668 002CB668 4000A5DF */  ld         $5, 0x40($29)
    /* 1CB66C 002CB66C 3800A6DF */  ld         $6, 0x38($29)
    /* 1CB670 002CB670 2D380000 */  daddu      $7, $0, $0
    /* 1CB674 002CB674 04000824 */  addiu      $8, $0, 0x4
    /* 1CB678 002CB678 06000924 */  addiu      $9, $0, 0x6
    /* 1CB67C 002CB67C 88810B0C */  jal        func_002e0620
    /* 1CB680 002CB680 00000000 */   nop
    /* 1CB684 002CB684 2000BFDF */  ld         $31, 0x20($29)
    /* 1CB688 002CB688 1000B17B */  lq         $17, 0x10($29)
    /* 1CB68C 002CB68C 0000B07B */  lq         $16, 0x0($29)
    /* 1CB690 002CB690 3001BD27 */  addiu      $29, $29, 0x130
    /* 1CB694 002CB694 0800E003 */  jr         $31
    /* 1CB698 002CB698 00000000 */   nop
    /* 1CB69C 002CB69C 00000000 */  nop
.size func_002caef0, 0x7b0
