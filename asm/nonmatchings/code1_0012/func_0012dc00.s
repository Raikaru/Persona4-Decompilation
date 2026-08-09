.section .text
.set noat
.set noreorder
glabel func_0012dc00
    /* 2DC00 0012DC00 1000858C */  lw         $5, 0x10($4)
    /* 2DC04 0012DC04 14008A8C */  lw         $10, 0x14($4)
    /* 2DC08 0012DC08 3800838C */  lw         $3, 0x38($4)
    /* 2DC0C 0012DC0C FFFF6924 */  addiu      $9, $3, -0x1
    /* 2DC10 0012DC10 23400900 */  negu       $8, $9
    /* 2DC14 0012DC14 2338AA00 */  subu       $7, $5, $10
    /* 2DC18 0012DC18 2D580000 */  daddu      $11, $0, $0
    /* 2DC1C 0012DC1C 08000010 */  b          .L0012DC40
    /* 2DC20 0012DC20 00000000 */   nop
  .L0012DC24:
    /* 2DC24 0012DC24 40300B00 */  sll        $6, $11, 1
    /* 2DC28 0012DC28 2130CB00 */  addu       $6, $6, $11
    /* 2DC2C 0012DC2C 00310600 */  sll        $6, $6, 4
    /* 2DC30 0012DC30 21308600 */  addu       $6, $4, $6
    /* 2DC34 0012DC34 BC00C0AC */  sw         $0, 0xBC($6)
    /* 2DC38 0012DC38 C000C0AC */  sw         $0, 0xC0($6)
    /* 2DC3C 0012DC3C 01006B25 */  addiu      $11, $11, 0x1
  .L0012DC40:
    /* 2DC40 0012DC40 0B006629 */  slti       $6, $11, 0xB
    /* 2DC44 0012DC44 F7FFC014 */  bnez       $6, .L0012DC24
    /* 2DC48 0012DC48 00000000 */   nop
    /* 2DC4C 0012DC4C 01000624 */  addiu      $6, $0, 0x1
    /* 2DC50 0012DC50 1F00E614 */  bne        $7, $6, .L0012DCD0
    /* 2DC54 0012DC54 00000000 */   nop
    /* 2DC58 0012DC58 40180A00 */  sll        $3, $10, 1
    /* 2DC5C 0012DC5C 21186A00 */  addu       $3, $3, $10
    /* 2DC60 0012DC60 00190300 */  sll        $3, $3, 4
    /* 2DC64 0012DC64 21186400 */  addu       $3, $3, $4
    /* 2DC68 0012DC68 9C0060AC */  sw         $0, 0x9C($3)
    /* 2DC6C 0012DC6C 980060AC */  sw         $0, 0x98($3)
    /* 2DC70 0012DC70 A00060AC */  sw         $0, 0xA0($3)
    /* 2DC74 0012DC74 FF000624 */  addiu      $6, $0, 0xFF
    /* 2DC78 0012DC78 AC0066A0 */  sb         $6, 0xAC($3)
    /* 2DC7C 0012DC7C AD0066A0 */  sb         $6, 0xAD($3)
    /* 2DC80 0012DC80 C00060AC */  sw         $0, 0xC0($3)
    /* 2DC84 0012DC84 40180500 */  sll        $3, $5, 1
    /* 2DC88 0012DC88 21186500 */  addu       $3, $3, $5
    /* 2DC8C 0012DC8C 00190300 */  sll        $3, $3, 4
    /* 2DC90 0012DC90 21286400 */  addu       $5, $3, $4
    /* 2DC94 0012DC94 9C00A0AC */  sw         $0, 0x9C($5)
    /* 2DC98 0012DC98 70C1033C */  lui        $3, (0xC1700000 >> 16)
    /* 2DC9C 0012DC9C 9800A3AC */  sw         $3, 0x98($5)
    /* 2DCA0 0012DCA0 B040033C */  lui        $3, (0x40B00000 >> 16)
    /* 2DCA4 0012DCA4 A000A3AC */  sw         $3, 0xA0($5)
    /* 2DCA8 0012DCA8 7F000324 */  addiu      $3, $0, 0x7F
    /* 2DCAC 0012DCAC AC00A3A0 */  sb         $3, 0xAC($5)
    /* 2DCB0 0012DCB0 AD00A6A0 */  sb         $6, 0xAD($5)
    /* 2DCB4 0012DCB4 03000324 */  addiu      $3, $0, 0x3
    /* 2DCB8 0012DCB8 C000A3AC */  sw         $3, 0xC0($5)
    /* 2DCBC 0012DCBC 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* 2DCC0 0012DCC0 780283AC */  sw         $3, 0x278($4)
    /* 2DCC4 0012DCC4 800283AC */  sw         $3, 0x280($4)
    /* 2DCC8 0012DCC8 71000010 */  b          .L0012DE90
    /* 2DCCC 0012DCCC 00000000 */   nop
  .L0012DCD0:
    /* 2DCD0 0012DCD0 FFFF0624 */  addiu      $6, $0, -0x1
    /* 2DCD4 0012DCD4 1E00E614 */  bne        $7, $6, .L0012DD50
    /* 2DCD8 0012DCD8 00000000 */   nop
    /* 2DCDC 0012DCDC 40180A00 */  sll        $3, $10, 1
    /* 2DCE0 0012DCE0 21186A00 */  addu       $3, $3, $10
    /* 2DCE4 0012DCE4 00190300 */  sll        $3, $3, 4
    /* 2DCE8 0012DCE8 21186400 */  addu       $3, $3, $4
    /* 2DCEC 0012DCEC 9C0060AC */  sw         $0, 0x9C($3)
    /* 2DCF0 0012DCF0 980060AC */  sw         $0, 0x98($3)
    /* 2DCF4 0012DCF4 A00060AC */  sw         $0, 0xA0($3)
    /* 2DCF8 0012DCF8 FF000624 */  addiu      $6, $0, 0xFF
    /* 2DCFC 0012DCFC AC0066A0 */  sb         $6, 0xAC($3)
    /* 2DD00 0012DD00 AD0066A0 */  sb         $6, 0xAD($3)
    /* 2DD04 0012DD04 C00060AC */  sw         $0, 0xC0($3)
    /* 2DD08 0012DD08 40180500 */  sll        $3, $5, 1
    /* 2DD0C 0012DD0C 21186500 */  addu       $3, $3, $5
    /* 2DD10 0012DD10 00190300 */  sll        $3, $3, 4
    /* 2DD14 0012DD14 21286400 */  addu       $5, $3, $4
    /* 2DD18 0012DD18 9C00A0AC */  sw         $0, 0x9C($5)
    /* 2DD1C 0012DD1C 7041033C */  lui        $3, (0x41700000 >> 16)
    /* 2DD20 0012DD20 9800A3AC */  sw         $3, 0x98($5)
    /* 2DD24 0012DD24 B0C0033C */  lui        $3, (0xC0B00000 >> 16)
    /* 2DD28 0012DD28 A000A3AC */  sw         $3, 0xA0($5)
    /* 2DD2C 0012DD2C 7F000324 */  addiu      $3, $0, 0x7F
    /* 2DD30 0012DD30 AC00A3A0 */  sb         $3, 0xAC($5)
    /* 2DD34 0012DD34 AD00A6A0 */  sb         $6, 0xAD($5)
    /* 2DD38 0012DD38 03000324 */  addiu      $3, $0, 0x3
    /* 2DD3C 0012DD3C C000A3AC */  sw         $3, 0xC0($5)
    /* 2DD40 0012DD40 780280AC */  sw         $0, 0x278($4)
    /* 2DD44 0012DD44 800280AC */  sw         $0, 0x280($4)
    /* 2DD48 0012DD48 51000010 */  b          .L0012DE90
    /* 2DD4C 0012DD4C 00000000 */   nop
  .L0012DD50:
    /* 2DD50 0012DD50 2900E914 */  bne        $7, $9, .L0012DDF8
    /* 2DD54 0012DD54 00000000 */   nop
    /* 2DD58 0012DD58 2D600000 */  daddu      $12, $0, $0
    /* 2DD5C 0012DD5C FF000824 */  addiu      $8, $0, 0xFF
    /* 2DD60 0012DD60 70C10B3C */  lui        $11, (0xC1700000 >> 16)
    /* 2DD64 0012DD64 B0400A3C */  lui        $10, (0x40B00000 >> 16)
    /* 2DD68 0012DD68 7F000924 */  addiu      $9, $0, 0x7F
    /* 2DD6C 0012DD6C 03000724 */  addiu      $7, $0, 0x3
    /* 2DD70 0012DD70 19000010 */  b          .L0012DDD8
    /* 2DD74 0012DD74 00000000 */   nop
  .L0012DD78:
    /* 2DD78 0012DD78 0C008515 */  bne        $12, $5, .L0012DDAC
    /* 2DD7C 0012DD7C 00000000 */   nop
    /* 2DD80 0012DD80 40300C00 */  sll        $6, $12, 1
    /* 2DD84 0012DD84 2130CC00 */  addu       $6, $6, $12
    /* 2DD88 0012DD88 00310600 */  sll        $6, $6, 4
    /* 2DD8C 0012DD8C 21308600 */  addu       $6, $4, $6
    /* 2DD90 0012DD90 9800CBAC */  sw         $11, 0x98($6)
    /* 2DD94 0012DD94 A000CAAC */  sw         $10, 0xA0($6)
    /* 2DD98 0012DD98 AC00C9A0 */  sb         $9, 0xAC($6)
    /* 2DD9C 0012DD9C AD00C8A0 */  sb         $8, 0xAD($6)
    /* 2DDA0 0012DDA0 C000C7AC */  sw         $7, 0xC0($6)
    /* 2DDA4 0012DDA4 0B000010 */  b          .L0012DDD4
    /* 2DDA8 0012DDA8 00000000 */   nop
  .L0012DDAC:
    /* 2DDAC 0012DDAC 40300C00 */  sll        $6, $12, 1
    /* 2DDB0 0012DDB0 2130CC00 */  addu       $6, $6, $12
    /* 2DDB4 0012DDB4 00310600 */  sll        $6, $6, 4
    /* 2DDB8 0012DDB8 21308600 */  addu       $6, $4, $6
    /* 2DDBC 0012DDBC 9C00C0AC */  sw         $0, 0x9C($6)
    /* 2DDC0 0012DDC0 9800C0AC */  sw         $0, 0x98($6)
    /* 2DDC4 0012DDC4 A000C0AC */  sw         $0, 0xA0($6)
    /* 2DDC8 0012DDC8 AC00C8A0 */  sb         $8, 0xAC($6)
    /* 2DDCC 0012DDCC AD00C8A0 */  sb         $8, 0xAD($6)
    /* 2DDD0 0012DDD0 C000C0AC */  sw         $0, 0xC0($6)
  .L0012DDD4:
    /* 2DDD4 0012DDD4 01008C25 */  addiu      $12, $12, 0x1
  .L0012DDD8:
    /* 2DDD8 0012DDD8 2A308301 */  slt        $6, $12, $3
    /* 2DDDC 0012DDDC E6FFC014 */  bnez       $6, .L0012DD78
    /* 2DDE0 0012DDE0 00000000 */   nop
    /* 2DDE4 0012DDE4 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* 2DDE8 0012DDE8 780283AC */  sw         $3, 0x278($4)
    /* 2DDEC 0012DDEC 800283AC */  sw         $3, 0x280($4)
    /* 2DDF0 0012DDF0 27000010 */  b          .L0012DE90
    /* 2DDF4 0012DDF4 00000000 */   nop
  .L0012DDF8:
    /* 2DDF8 0012DDF8 2500E814 */  bne        $7, $8, .L0012DE90
    /* 2DDFC 0012DDFC 00000000 */   nop
    /* 2DE00 0012DE00 2D580000 */  daddu      $11, $0, $0
    /* 2DE04 0012DE04 FF000824 */  addiu      $8, $0, 0xFF
    /* 2DE08 0012DE08 70410A3C */  lui        $10, (0x41700000 >> 16)
    /* 2DE0C 0012DE0C B0C0093C */  lui        $9, (0xC0B00000 >> 16)
    /* 2DE10 0012DE10 03000724 */  addiu      $7, $0, 0x3
    /* 2DE14 0012DE14 19000010 */  b          .L0012DE7C
    /* 2DE18 0012DE18 00000000 */   nop
  .L0012DE1C:
    /* 2DE1C 0012DE1C 0C006515 */  bne        $11, $5, .L0012DE50
    /* 2DE20 0012DE20 00000000 */   nop
    /* 2DE24 0012DE24 40300B00 */  sll        $6, $11, 1
    /* 2DE28 0012DE28 2130CB00 */  addu       $6, $6, $11
    /* 2DE2C 0012DE2C 00310600 */  sll        $6, $6, 4
    /* 2DE30 0012DE30 21308600 */  addu       $6, $4, $6
    /* 2DE34 0012DE34 9800CAAC */  sw         $10, 0x98($6)
    /* 2DE38 0012DE38 A000C9AC */  sw         $9, 0xA0($6)
    /* 2DE3C 0012DE3C AC00C0A0 */  sb         $0, 0xAC($6)
    /* 2DE40 0012DE40 AD00C8A0 */  sb         $8, 0xAD($6)
    /* 2DE44 0012DE44 C000C7AC */  sw         $7, 0xC0($6)
    /* 2DE48 0012DE48 0B000010 */  b          .L0012DE78
    /* 2DE4C 0012DE4C 00000000 */   nop
  .L0012DE50:
    /* 2DE50 0012DE50 40300B00 */  sll        $6, $11, 1
    /* 2DE54 0012DE54 2130CB00 */  addu       $6, $6, $11
    /* 2DE58 0012DE58 00310600 */  sll        $6, $6, 4
    /* 2DE5C 0012DE5C 21308600 */  addu       $6, $4, $6
    /* 2DE60 0012DE60 9C00C0AC */  sw         $0, 0x9C($6)
    /* 2DE64 0012DE64 9800C0AC */  sw         $0, 0x98($6)
    /* 2DE68 0012DE68 A000C0AC */  sw         $0, 0xA0($6)
    /* 2DE6C 0012DE6C AC00C8A0 */  sb         $8, 0xAC($6)
    /* 2DE70 0012DE70 AD00C8A0 */  sb         $8, 0xAD($6)
    /* 2DE74 0012DE74 C000C0AC */  sw         $0, 0xC0($6)
  .L0012DE78:
    /* 2DE78 0012DE78 01006B25 */  addiu      $11, $11, 0x1
  .L0012DE7C:
    /* 2DE7C 0012DE7C 2A306301 */  slt        $6, $11, $3
    /* 2DE80 0012DE80 E6FFC014 */  bnez       $6, .L0012DE1C
    /* 2DE84 0012DE84 00000000 */   nop
    /* 2DE88 0012DE88 780280AC */  sw         $0, 0x278($4)
    /* 2DE8C 0012DE8C 800280AC */  sw         $0, 0x280($4)
  .L0012DE90:
    /* 2DE90 0012DE90 0C0080A4 */  sh         $0, 0xC($4)
    /* 2DE94 0012DE94 0800E003 */  jr         $31
    /* 2DE98 0012DE98 00000000 */   nop
    /* 2DE9C 0012DE9C 00000000 */  nop
.size func_0012dc00, 0x2a0
