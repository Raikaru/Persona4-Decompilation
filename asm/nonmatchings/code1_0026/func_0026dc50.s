.section .text
.set noat
.set noreorder
glabel func_0026dc50
    /* 16DC50 0026DC50 10FFBD27 */  addiu      $29, $29, -0xF0
    /* 16DC54 0026DC54 3000BFFF */  sd         $31, 0x30($29)
    /* 16DC58 0026DC58 2000B17F */  sq         $17, 0x20($29)
    /* 16DC5C 0026DC5C 1000B07F */  sq         $16, 0x10($29)
    /* 16DC60 0026DC60 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 16DC64 0026DC64 2D888000 */  daddu      $17, $4, $0
    /* 16DC68 0026DC68 2D80A000 */  daddu      $16, $5, $0
    /* 16DC6C 0026DC6C 485C110C */  jal        func_00457120
    /* 16DC70 0026DC70 00000000 */   nop
    /* 16DC74 0026DC74 0400448C */  lw         $4, 0x4($2)
    /* 16DC78 0026DC78 C0A50F0C */  jal        func_003e9700
    /* 16DC7C 0026DC7C 00000000 */   nop
    /* 16DC80 0026DC80 300042C4 */  lwc1       $f2, 0x30($2)
    /* 16DC84 0026DC84 340041C4 */  lwc1       $f1, 0x34($2)
    /* 16DC88 0026DC88 380040C4 */  lwc1       $f0, 0x38($2)
    /* 16DC8C 0026DC8C C000A2E7 */  swc1       $f2, 0xC0($29)
    /* 16DC90 0026DC90 C400A1E7 */  swc1       $f1, 0xC4($29)
    /* 16DC94 0026DC94 C800A0E7 */  swc1       $f0, 0xC8($29)
    /* 16DC98 0026DC98 0000108E */  lw         $16, 0x0($16)
    /* 16DC9C 0026DC9C 0000228E */  lw         $2, 0x0($17)
    /* 16DCA0 0026DCA0 4401448C */  lw         $4, 0x144($2)
    /* 16DCA4 0026DCA4 8000A527 */  addiu      $5, $29, 0x80
    /* 16DCA8 0026DCA8 1CC5120C */  jal        func_004b1470
    /* 16DCAC 0026DCAC 00000000 */   nop
    /* 16DCB0 0026DCB0 4401048E */  lw         $4, 0x144($16)
    /* 16DCB4 0026DCB4 4000A527 */  addiu      $5, $29, 0x40
    /* 16DCB8 0026DCB8 1CC5120C */  jal        func_004b1470
    /* 16DCBC 0026DCBC 00000000 */   nop
    /* 16DCC0 0026DCC0 B000A327 */  addiu      $3, $29, 0xB0
    /* 16DCC4 0026DCC4 7000A227 */  addiu      $2, $29, 0x70
    /* 16DCC8 0026DCC8 000060C4 */  lwc1       $f0, 0x0($3)
    /* 16DCCC 0026DCCC C000A3C7 */  lwc1       $f3, 0xC0($29)
    /* 16DCD0 0026DCD0 01000346 */  sub.s      $f0, $f0, $f3
    /* 16DCD4 0026DCD4 E000A0E7 */  swc1       $f0, 0xE0($29)
    /* 16DCD8 0026DCD8 C400A2C7 */  lwc1       $f2, 0xC4($29)
    /* 16DCDC 0026DCDC 040060C4 */  lwc1       $f0, 0x4($3)
    /* 16DCE0 0026DCE0 01000246 */  sub.s      $f0, $f0, $f2
    /* 16DCE4 0026DCE4 E400A0E7 */  swc1       $f0, 0xE4($29)
    /* 16DCE8 0026DCE8 C800A1C7 */  lwc1       $f1, 0xC8($29)
    /* 16DCEC 0026DCEC 080060C4 */  lwc1       $f0, 0x8($3)
    /* 16DCF0 0026DCF0 01000146 */  sub.s      $f0, $f0, $f1
    /* 16DCF4 0026DCF4 E800A0E7 */  swc1       $f0, 0xE8($29)
    /* 16DCF8 0026DCF8 000040C4 */  lwc1       $f0, 0x0($2)
    /* 16DCFC 0026DCFC 01000346 */  sub.s      $f0, $f0, $f3
    /* 16DD00 0026DD00 D000A0E7 */  swc1       $f0, 0xD0($29)
    /* 16DD04 0026DD04 040040C4 */  lwc1       $f0, 0x4($2)
    /* 16DD08 0026DD08 01000246 */  sub.s      $f0, $f0, $f2
    /* 16DD0C 0026DD0C D400A0E7 */  swc1       $f0, 0xD4($29)
    /* 16DD10 0026DD10 080040C4 */  lwc1       $f0, 0x8($2)
    /* 16DD14 0026DD14 01000146 */  sub.s      $f0, $f0, $f1
    /* 16DD18 0026DD18 D800A0E7 */  swc1       $f0, 0xD8($29)
    /* 16DD1C 0026DD1C E000A427 */  addiu      $4, $29, 0xE0
    /* 16DD20 0026DD20 60900F0C */  jal        func_003e4180
    /* 16DD24 0026DD24 00000000 */   nop
    /* 16DD28 0026DD28 06050046 */  mov.s      $f20, $f0
    /* 16DD2C 0026DD2C D000A427 */  addiu      $4, $29, 0xD0
    /* 16DD30 0026DD30 60900F0C */  jal        func_003e4180
    /* 16DD34 0026DD34 00000000 */   nop
    /* 16DD38 0026DD38 01A00046 */  sub.s      $f0, $f20, $f0
    /* 16DD3C 0026DD3C 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 16DD40 0026DD40 00000244 */  mfc1       $2, $f0
    /* 16DD44 0026DD44 3000BFDF */  ld         $31, 0x30($29)
    /* 16DD48 0026DD48 2000B17B */  lq         $17, 0x20($29)
    /* 16DD4C 0026DD4C 1000B07B */  lq         $16, 0x10($29)
    /* 16DD50 0026DD50 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 16DD54 0026DD54 F000BD27 */  addiu      $29, $29, 0xF0
    /* 16DD58 0026DD58 0800E003 */  jr         $31
    /* 16DD5C 0026DD5C 00000000 */   nop
.size func_0026dc50, 0x110
