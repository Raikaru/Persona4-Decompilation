.section .text
.set noat
.set noreorder
glabel func_002df020
    /* 1DF020 002DF020 40FFBD27 */  addiu      $29, $29, -0xC0
    /* 1DF024 002DF024 5000BFFF */  sd         $31, 0x50($29)
    /* 1DF028 002DF028 4000B37F */  sq         $19, 0x40($29)
    /* 1DF02C 002DF02C 3000B27F */  sq         $18, 0x30($29)
    /* 1DF030 002DF030 2000B17F */  sq         $17, 0x20($29)
    /* 1DF034 002DF034 1000B07F */  sq         $16, 0x10($29)
    /* 1DF038 002DF038 2D98A000 */  daddu      $19, $5, $0
    /* 1DF03C 002DF03C 2D90C000 */  daddu      $18, $6, $0
    /* 1DF040 002DF040 3800918C */  lw         $17, 0x38($4)
    /* 1DF044 002DF044 11002382 */  lb         $3, 0x11($17)
    /* 1DF048 002DF048 02000224 */  addiu      $2, $0, 0x2
    /* 1DF04C 002DF04C 44006210 */  beq        $3, $2, .L002DF160
    /* 1DF050 002DF050 00000000 */   nop
    /* 1DF054 002DF054 01000224 */  addiu      $2, $0, 0x1
    /* 1DF058 002DF058 1F006210 */  beq        $3, $2, .L002DF0D8
    /* 1DF05C 002DF05C 00000000 */   nop
    /* 1DF060 002DF060 03006010 */  beqz       $3, .L002DF070
    /* 1DF064 002DF064 00000000 */   nop
    /* 1DF068 002DF068 55000010 */  b          .L002DF1C0
    /* 1DF06C 002DF06C 00000000 */   nop
  .L002DF070:
    /* 1DF070 002DF070 C242023C */  lui        $2, (0x42C20000 >> 16)
    /* 1DF074 002DF074 00608244 */  mtc1       $2, $f12
    /* 1DF078 002DF078 3243023C */  lui        $2, (0x43320000 >> 16)
    /* 1DF07C 002DF07C 00688244 */  mtc1       $2, $f13
    /* 1DF080 002DF080 A000A427 */  addiu      $4, $29, 0xA0
    /* 1DF084 002DF084 5CCA0A0C */  jal        func_002b2970
    /* 1DF088 002DF088 00000000 */   nop
    /* 1DF08C 002DF08C 2D200000 */  daddu      $4, $0, $0
    /* 1DF090 002DF090 2D000524 */  addiu      $5, $0, 0x2D
    /* 1DF094 002DF094 2D30A000 */  daddu      $6, $5, $0
    /* 1DF098 002DF098 2D38A000 */  daddu      $7, $5, $0
    /* 1DF09C 002DF09C 8CCA0A0C */  jal        func_002b2a30
    /* 1DF0A0 002DF0A0 00000000 */   nop
    /* 1DF0A4 002DF0A4 5041033C */  lui        $3, (0x41500000 >> 16)
    /* 1DF0A8 002DF0A8 00608344 */  mtc1       $3, $f12
    /* 1DF0AC 002DF0AC 1A000424 */  addiu      $4, $0, 0x1A
    /* 1DF0B0 002DF0B0 A000A5DF */  ld         $5, 0xA0($29)
    /* 1DF0B4 002DF0B4 2D304000 */  daddu      $6, $2, $0
    /* 1DF0B8 002DF0B8 FF000724 */  addiu      $7, $0, 0xFF
    /* 1DF0BC 002DF0BC 2D400000 */  daddu      $8, $0, $0
    /* 1DF0C0 002DF0C0 7900093C */  lui        $9, %hi(D_00795E30)
    /* 1DF0C4 002DF0C4 305E2925 */  addiu      $9, $9, %lo(D_00795E30)
    /* 1DF0C8 002DF0C8 28830B0C */  jal        func_002e0ca0
    /* 1DF0CC 002DF0CC 00000000 */   nop
    /* 1DF0D0 002DF0D0 3B000010 */  b          .L002DF1C0
    /* 1DF0D4 002DF0D4 00000000 */   nop
  .L002DF0D8:
    /* 1DF0D8 002DF0D8 2D206002 */  daddu      $4, $19, $0
    /* 1DF0DC 002DF0DC 201A040C */  jal        func_00106880
    /* 1DF0E0 002DF0E0 00000000 */   nop
    /* 1DF0E4 002DF0E4 3C240200 */  dsll32     $4, $2, 16
    /* 1DF0E8 002DF0E8 3F240400 */  dsra32     $4, $4, 16
    /* 1DF0EC 002DF0EC CC530B0C */  jal        func_002d4f30
    /* 1DF0F0 002DF0F0 00000000 */   nop
    /* 1DF0F4 002DF0F4 FFFF5030 */  andi       $16, $2, 0xFFFF
    /* 1DF0F8 002DF0F8 C242023C */  lui        $2, (0x42C20000 >> 16)
    /* 1DF0FC 002DF0FC 00608244 */  mtc1       $2, $f12
    /* 1DF100 002DF100 3243023C */  lui        $2, (0x43320000 >> 16)
    /* 1DF104 002DF104 00688244 */  mtc1       $2, $f13
    /* 1DF108 002DF108 9800A427 */  addiu      $4, $29, 0x98
    /* 1DF10C 002DF10C 5CCA0A0C */  jal        func_002b2970
    /* 1DF110 002DF110 00000000 */   nop
    /* 1DF114 002DF114 2D200000 */  daddu      $4, $0, $0
    /* 1DF118 002DF118 2D000524 */  addiu      $5, $0, 0x2D
    /* 1DF11C 002DF11C 2D30A000 */  daddu      $6, $5, $0
    /* 1DF120 002DF120 2D38A000 */  daddu      $7, $5, $0
    /* 1DF124 002DF124 8CCA0A0C */  jal        func_002b2a30
    /* 1DF128 002DF128 00000000 */   nop
    /* 1DF12C 002DF12C 5041033C */  lui        $3, (0x41500000 >> 16)
    /* 1DF130 002DF130 00608344 */  mtc1       $3, $f12
    /* 1DF134 002DF134 2D200002 */  daddu      $4, $16, $0
    /* 1DF138 002DF138 9800A5DF */  ld         $5, 0x98($29)
    /* 1DF13C 002DF13C 2D304000 */  daddu      $6, $2, $0
    /* 1DF140 002DF140 FF000724 */  addiu      $7, $0, 0xFF
    /* 1DF144 002DF144 2D400000 */  daddu      $8, $0, $0
    /* 1DF148 002DF148 7900093C */  lui        $9, %hi(D_00795E30)
    /* 1DF14C 002DF14C 305E2925 */  addiu      $9, $9, %lo(D_00795E30)
    /* 1DF150 002DF150 C8820B0C */  jal        func_002e0b20
    /* 1DF154 002DF154 00000000 */   nop
    /* 1DF158 002DF158 19000010 */  b          .L002DF1C0
    /* 1DF15C 002DF15C 00000000 */   nop
  .L002DF160:
    /* 1DF160 002DF160 C242023C */  lui        $2, (0x42C20000 >> 16)
    /* 1DF164 002DF164 00608244 */  mtc1       $2, $f12
    /* 1DF168 002DF168 3243023C */  lui        $2, (0x43320000 >> 16)
    /* 1DF16C 002DF16C 00688244 */  mtc1       $2, $f13
    /* 1DF170 002DF170 9000A427 */  addiu      $4, $29, 0x90
    /* 1DF174 002DF174 5CCA0A0C */  jal        func_002b2970
    /* 1DF178 002DF178 00000000 */   nop
    /* 1DF17C 002DF17C 2D200000 */  daddu      $4, $0, $0
    /* 1DF180 002DF180 2D000524 */  addiu      $5, $0, 0x2D
    /* 1DF184 002DF184 2D30A000 */  daddu      $6, $5, $0
    /* 1DF188 002DF188 2D38A000 */  daddu      $7, $5, $0
    /* 1DF18C 002DF18C 8CCA0A0C */  jal        func_002b2a30
    /* 1DF190 002DF190 00000000 */   nop
    /* 1DF194 002DF194 5041033C */  lui        $3, (0x41500000 >> 16)
    /* 1DF198 002DF198 00608344 */  mtc1       $3, $f12
    /* 1DF19C 002DF19C 1B000424 */  addiu      $4, $0, 0x1B
    /* 1DF1A0 002DF1A0 9000A5DF */  ld         $5, 0x90($29)
    /* 1DF1A4 002DF1A4 2D304000 */  daddu      $6, $2, $0
    /* 1DF1A8 002DF1A8 FF000724 */  addiu      $7, $0, 0xFF
    /* 1DF1AC 002DF1AC 2D400000 */  daddu      $8, $0, $0
    /* 1DF1B0 002DF1B0 7900093C */  lui        $9, %hi(D_00795E30)
    /* 1DF1B4 002DF1B4 305E2925 */  addiu      $9, $9, %lo(D_00795E30)
    /* 1DF1B8 002DF1B8 28830B0C */  jal        func_002e0ca0
    /* 1DF1BC 002DF1BC 00000000 */   nop
  .L002DF1C0:
    /* 1DF1C0 002DF1C0 2D000424 */  addiu      $4, $0, 0x2D
    /* 1DF1C4 002DF1C4 2D288000 */  daddu      $5, $4, $0
    /* 1DF1C8 002DF1C8 2D308000 */  daddu      $6, $4, $0
    /* 1DF1CC 002DF1CC FF000724 */  addiu      $7, $0, 0xFF
    /* 1DF1D0 002DF1D0 8CCA0A0C */  jal        func_002b2a30
    /* 1DF1D4 002DF1D4 00000000 */   nop
    /* 1DF1D8 002DF1D8 2D804000 */  daddu      $16, $2, $0
    /* 1DF1DC 002DF1DC 0C43023C */  lui        $2, (0x430C0000 >> 16)
    /* 1DF1E0 002DF1E0 00608244 */  mtc1       $2, $f12
    /* 1DF1E4 002DF1E4 3243023C */  lui        $2, (0x43320000 >> 16)
    /* 1DF1E8 002DF1E8 00688244 */  mtc1       $2, $f13
    /* 1DF1EC 002DF1EC 8800A427 */  addiu      $4, $29, 0x88
    /* 1DF1F0 002DF1F0 5CCA0A0C */  jal        func_002b2970
    /* 1DF1F4 002DF1F4 00000000 */   nop
    /* 1DF1F8 002DF1F8 8800A1C7 */  lwc1       $f1, 0x88($29)
    /* 1DF1FC 002DF1FC 8C00A0C7 */  lwc1       $f0, 0x8C($29)
    /* 1DF200 002DF200 6800A1E7 */  swc1       $f1, 0x68($29)
    /* 1DF204 002DF204 6C00A0E7 */  swc1       $f0, 0x6C($29)
    /* 1DF208 002DF208 2D206002 */  daddu      $4, $19, $0
    /* 1DF20C 002DF20C FC19040C */  jal        func_001067f0
    /* 1DF210 002DF210 00000000 */   nop
    /* 1DF214 002DF214 5041033C */  lui        $3, (0x41500000 >> 16)
    /* 1DF218 002DF218 00708344 */  mtc1       $3, $f14
    /* 1DF21C 002DF21C 6800ACC7 */  lwc1       $f12, 0x68($29)
    /* 1DF220 002DF220 6C00ADC7 */  lwc1       $f13, 0x6C($29)
    /* 1DF224 002DF224 2D200002 */  daddu      $4, $16, $0
    /* 1DF228 002DF228 2D280000 */  daddu      $5, $0, $0
    /* 1DF22C 002DF22C 01000624 */  addiu      $6, $0, 0x1
    /* 1DF230 002DF230 2D384000 */  daddu      $7, $2, $0
    /* 1DF234 002DF234 2D400000 */  daddu      $8, $0, $0
    /* 1DF238 002DF238 2D480000 */  daddu      $9, $0, $0
    /* 1DF23C 002DF23C 79000A3C */  lui        $10, %hi(D_00795E30)
    /* 1DF240 002DF240 305E4A25 */  addiu      $10, $10, %lo(D_00795E30)
    /* 1DF244 002DF244 FFFF0B24 */  addiu      $11, $0, -0x1
    /* 1DF248 002DF248 A0D5090C */  jal        func_00275680
    /* 1DF24C 002DF24C 00000000 */   nop
    /* 1DF250 002DF250 3C241300 */  dsll32     $4, $19, 16
    /* 1DF254 002DF254 3F240400 */  dsra32     $4, $4, 16
    /* 1DF258 002DF258 A41A040C */  jal        func_00106a90
    /* 1DF25C 002DF25C 00000000 */   nop
    /* 1DF260 002DF260 05000324 */  addiu      $3, $0, 0x5
    /* 1DF264 002DF264 1B004300 */  divu       $0, $2, $3
    /* 1DF268 002DF268 12800000 */  mflo       $16
    /* 1DF26C 002DF26C E043023C */  lui        $2, (0x43E00000 >> 16)
    /* 1DF270 002DF270 00608244 */  mtc1       $2, $f12
    /* 1DF274 002DF274 3943023C */  lui        $2, (0x43390000 >> 16)
    /* 1DF278 002DF278 00688244 */  mtc1       $2, $f13
    /* 1DF27C 002DF27C 8000A427 */  addiu      $4, $29, 0x80
    /* 1DF280 002DF280 5CCA0A0C */  jal        func_002b2970
    /* 1DF284 002DF284 00000000 */   nop
    /* 1DF288 002DF288 BC00A427 */  addiu      $4, $29, 0xBC
    /* 1DF28C 002DF28C 2D000524 */  addiu      $5, $0, 0x2D
    /* 1DF290 002DF290 2D30A000 */  daddu      $6, $5, $0
    /* 1DF294 002DF294 2D38A000 */  daddu      $7, $5, $0
    /* 1DF298 002DF298 FF000824 */  addiu      $8, $0, 0xFF
    /* 1DF29C 002DF29C 98CA0A0C */  jal        func_002b2a60
    /* 1DF2A0 002DF2A0 00000000 */   nop
    /* 1DF2A4 002DF2A4 6400043C */  lui        $4, %hi(D_0063FB50)
    /* 1DF2A8 002DF2A8 50FB8424 */  addiu      $4, $4, %lo(D_0063FB50)
    /* 1DF2AC 002DF2AC DCA9110C */  jal        func_0046a770
    /* 1DF2B0 002DF2B0 00000000 */   nop
    /* 1DF2B4 002DF2B4 280F238E */  lw         $3, 0xF28($17)
    /* 1DF2B8 002DF2B8 0000A3FF */  sd         $3, 0x0($29)
    /* 1DF2BC 002DF2BC A9000324 */  addiu      $3, $0, 0xA9
    /* 1DF2C0 002DF2C0 0800A3FF */  sd         $3, 0x8($29)
    /* 1DF2C4 002DF2C4 5041033C */  lui        $3, (0x41500000 >> 16)
    /* 1DF2C8 002DF2C8 00608344 */  mtc1       $3, $f12
    /* 1DF2CC 002DF2CC 8000A4DF */  ld         $4, 0x80($29)
    /* 1DF2D0 002DF2D0 BC00A58F */  lw         $5, 0xBC($29)
    /* 1DF2D4 002DF2D4 10000624 */  addiu      $6, $0, 0x10
    /* 1DF2D8 002DF2D8 05000724 */  addiu      $7, $0, 0x5
    /* 1DF2DC 002DF2DC 2D400002 */  daddu      $8, $16, $0
    /* 1DF2E0 002DF2E0 09000924 */  addiu      $9, $0, 0x9
    /* 1DF2E4 002DF2E4 7B000A24 */  addiu      $10, $0, 0x7B
    /* 1DF2E8 002DF2E8 2D584000 */  daddu      $11, $2, $0
    /* 1DF2EC 002DF2EC 342B0B0C */  jal        func_002cacd0
    /* 1DF2F0 002DF2F0 00000000 */   nop
    /* 1DF2F4 002DF2F4 EE43023C */  lui        $2, (0x43EE0000 >> 16)
    /* 1DF2F8 002DF2F8 00608244 */  mtc1       $2, $f12
    /* 1DF2FC 002DF2FC 3B43023C */  lui        $2, (0x433B0000 >> 16)
    /* 1DF300 002DF300 00688244 */  mtc1       $2, $f13
    /* 1DF304 002DF304 7800A427 */  addiu      $4, $29, 0x78
    /* 1DF308 002DF308 5CCA0A0C */  jal        func_002b2970
    /* 1DF30C 002DF30C 00000000 */   nop
    /* 1DF310 002DF310 2D000424 */  addiu      $4, $0, 0x2D
    /* 1DF314 002DF314 2D288000 */  daddu      $5, $4, $0
    /* 1DF318 002DF318 2D308000 */  daddu      $6, $4, $0
    /* 1DF31C 002DF31C 2D388000 */  daddu      $7, $4, $0
    /* 1DF320 002DF320 8CCA0A0C */  jal        func_002b2a30
    /* 1DF324 002DF324 00000000 */   nop
    /* 1DF328 002DF328 5041033C */  lui        $3, (0x41500000 >> 16)
    /* 1DF32C 002DF32C 00608344 */  mtc1       $3, $f12
    /* 1DF330 002DF330 47000424 */  addiu      $4, $0, 0x47
    /* 1DF334 002DF334 7800A5DF */  ld         $5, 0x78($29)
    /* 1DF338 002DF338 2D304000 */  daddu      $6, $2, $0
    /* 1DF33C 002DF33C FF000724 */  addiu      $7, $0, 0xFF
    /* 1DF340 002DF340 2D400000 */  daddu      $8, $0, $0
    /* 1DF344 002DF344 7900093C */  lui        $9, %hi(D_00795E60)
    /* 1DF348 002DF348 605E2925 */  addiu      $9, $9, %lo(D_00795E60)
    /* 1DF34C 002DF34C C8820B0C */  jal        func_002e0b20
    /* 1DF350 002DF350 00000000 */   nop
    /* 1DF354 002DF354 88A882DF */  ld         $2, -0x5778($28)
    /* 1DF358 002DF358 A800A2FF */  sd         $2, 0xA8($29)
    /* 1DF35C 002DF35C 12002286 */  lh         $2, 0x12($17)
    /* 1DF360 002DF360 0A004128 */  slti       $1, $2, 0xA
    /* 1DF364 002DF364 07002010 */  beqz       $1, .L002DF384
    /* 1DF368 002DF368 00000000 */   nop
    /* 1DF36C 002DF36C A800A1C7 */  lwc1       $f1, 0xA8($29)
    /* 1DF370 002DF370 0041023C */  lui        $2, (0x41000000 >> 16)
    /* 1DF374 002DF374 00008244 */  mtc1       $2, $f0
    /* 1DF378 002DF378 00000000 */  nop
    /* 1DF37C 002DF37C 01080046 */  sub.s      $f0, $f1, $f0
    /* 1DF380 002DF380 A800A0E7 */  swc1       $f0, 0xA8($29)
  .L002DF384:
    /* 1DF384 002DF384 B800A427 */  addiu      $4, $29, 0xB8
    /* 1DF388 002DF388 2D000524 */  addiu      $5, $0, 0x2D
    /* 1DF38C 002DF38C 2D30A000 */  daddu      $6, $5, $0
    /* 1DF390 002DF390 2D38A000 */  daddu      $7, $5, $0
    /* 1DF394 002DF394 FF000824 */  addiu      $8, $0, 0xFF
    /* 1DF398 002DF398 98CA0A0C */  jal        func_002b2a60
    /* 1DF39C 002DF39C 00000000 */   nop
    /* 1DF3A0 002DF3A0 6400043C */  lui        $4, %hi(D_0063FB50)
    /* 1DF3A4 002DF3A4 50FB8424 */  addiu      $4, $4, %lo(D_0063FB50)
    /* 1DF3A8 002DF3A8 DCA9110C */  jal        func_0046a770
    /* 1DF3AC 002DF3AC 00000000 */   nop
    /* 1DF3B0 002DF3B0 280F238E */  lw         $3, 0xF28($17)
    /* 1DF3B4 002DF3B4 0000A3FF */  sd         $3, 0x0($29)
    /* 1DF3B8 002DF3B8 A9000324 */  addiu      $3, $0, 0xA9
    /* 1DF3BC 002DF3BC 0800A3FF */  sd         $3, 0x8($29)
    /* 1DF3C0 002DF3C0 5041033C */  lui        $3, (0x41500000 >> 16)
    /* 1DF3C4 002DF3C4 00608344 */  mtc1       $3, $f12
    /* 1DF3C8 002DF3C8 12002886 */  lh         $8, 0x12($17)
    /* 1DF3CC 002DF3CC A800A4DF */  ld         $4, 0xA8($29)
    /* 1DF3D0 002DF3D0 B800A58F */  lw         $5, 0xB8($29)
    /* 1DF3D4 002DF3D4 10000624 */  addiu      $6, $0, 0x10
    /* 1DF3D8 002DF3D8 05000724 */  addiu      $7, $0, 0x5
    /* 1DF3DC 002DF3DC 09000924 */  addiu      $9, $0, 0x9
    /* 1DF3E0 002DF3E0 7B000A24 */  addiu      $10, $0, 0x7B
    /* 1DF3E4 002DF3E4 2D584000 */  daddu      $11, $2, $0
    /* 1DF3E8 002DF3E8 342B0B0C */  jal        func_002cacd0
    /* 1DF3EC 002DF3EC 00000000 */   nop
    /* 1DF3F0 002DF3F0 F1010224 */  addiu      $2, $0, 0x1F1
    /* 1DF3F4 002DF3F4 00008244 */  mtc1       $2, $f0
    /* 1DF3F8 002DF3F8 00000000 */  nop
    /* 1DF3FC 002DF3FC 20038046 */  cvt.s.w    $f12, $f0
    /* 1DF400 002DF400 7743023C */  lui        $2, (0x43770000 >> 16)
    /* 1DF404 002DF404 00688244 */  mtc1       $2, $f13
    /* 1DF408 002DF408 7000A427 */  addiu      $4, $29, 0x70
    /* 1DF40C 002DF40C 5CCA0A0C */  jal        func_002b2970
    /* 1DF410 002DF410 00000000 */   nop
    /* 1DF414 002DF414 C80C248E */  lw         $4, 0xCC8($17)
    /* 1DF418 002DF418 38810B0C */  jal        func_002e04e0
    /* 1DF41C 002DF41C 00000000 */   nop
    /* 1DF420 002DF420 B400A427 */  addiu      $4, $29, 0xB4
    /* 1DF424 002DF424 DF000524 */  addiu      $5, $0, 0xDF
    /* 1DF428 002DF428 6C000624 */  addiu      $6, $0, 0x6C
    /* 1DF42C 002DF42C 2D380000 */  daddu      $7, $0, $0
    /* 1DF430 002DF430 62004890 */  lbu        $8, 0x62($2)
    /* 1DF434 002DF434 98CA0A0C */  jal        func_002b2a60
    /* 1DF438 002DF438 00000000 */   nop
    /* 1DF43C 002DF43C 6400043C */  lui        $4, %hi(D_0063FAA0)
    /* 1DF440 002DF440 A0FA8424 */  addiu      $4, $4, %lo(D_0063FAA0)
    /* 1DF444 002DF444 DCA9110C */  jal        func_0046a770
    /* 1DF448 002DF448 00000000 */   nop
    /* 1DF44C 002DF44C 2D804000 */  daddu      $16, $2, $0
    /* 1DF450 002DF450 6400043C */  lui        $4, %hi(D_0063FAA0)
    /* 1DF454 002DF454 A0FA8424 */  addiu      $4, $4, %lo(D_0063FAA0)
    /* 1DF458 002DF458 DCA9110C */  jal        func_0046a770
    /* 1DF45C 002DF45C 00000000 */   nop
    /* 1DF460 002DF460 0000A2FF */  sd         $2, 0x0($29)
    /* 1DF464 002DF464 A9000224 */  addiu      $2, $0, 0xA9
    /* 1DF468 002DF468 0800A2FF */  sd         $2, 0x8($29)
    /* 1DF46C 002DF46C 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1DF470 002DF470 00608244 */  mtc1       $2, $f12
    /* 1DF474 002DF474 FF004832 */  andi       $8, $18, 0xFF
    /* 1DF478 002DF478 7000A4DF */  ld         $4, 0x70($29)
    /* 1DF47C 002DF47C B400A58F */  lw         $5, 0xB4($29)
    /* 1DF480 002DF480 1B000624 */  addiu      $6, $0, 0x1B
    /* 1DF484 002DF484 2D380000 */  daddu      $7, $0, $0
    /* 1DF488 002DF488 2F000924 */  addiu      $9, $0, 0x2F
    /* 1DF48C 002DF48C 2D500000 */  daddu      $10, $0, $0
    /* 1DF490 002DF490 2D580002 */  daddu      $11, $16, $0
    /* 1DF494 002DF494 342B0B0C */  jal        func_002cacd0
    /* 1DF498 002DF498 00000000 */   nop
    /* 1DF49C 002DF49C 5000BFDF */  ld         $31, 0x50($29)
    /* 1DF4A0 002DF4A0 4000B37B */  lq         $19, 0x40($29)
    /* 1DF4A4 002DF4A4 3000B27B */  lq         $18, 0x30($29)
    /* 1DF4A8 002DF4A8 2000B17B */  lq         $17, 0x20($29)
    /* 1DF4AC 002DF4AC 1000B07B */  lq         $16, 0x10($29)
    /* 1DF4B0 002DF4B0 C000BD27 */  addiu      $29, $29, 0xC0
    /* 1DF4B4 002DF4B4 0800E003 */  jr         $31
    /* 1DF4B8 002DF4B8 00000000 */   nop
    /* 1DF4BC 002DF4BC 00000000 */  nop
.size func_002df020, 0x4a0
