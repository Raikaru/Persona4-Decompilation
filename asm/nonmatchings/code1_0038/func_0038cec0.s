.section .text
.set noat
.set noreorder
glabel func_0038cec0
    /* 28CEC0 0038CEC0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 28CEC4 0038CEC4 3000BFFF */  sd         $31, 0x30($29)
    /* 28CEC8 0038CEC8 2000B27F */  sq         $18, 0x20($29)
    /* 28CECC 0038CECC 1000B17F */  sq         $17, 0x10($29)
    /* 28CED0 0038CED0 0000B07F */  sq         $16, 0x0($29)
    /* 28CED4 0038CED4 2D908000 */  daddu      $18, $4, $0
    /* 28CED8 0038CED8 6500043C */  lui        $4, %hi(D_0064F0E0)
    /* 28CEDC 0038CEDC E0F08424 */  addiu      $4, $4, %lo(D_0064F0E0)
    /* 28CEE0 0038CEE0 9D050524 */  addiu      $5, $0, 0x59D
    /* 28CEE4 0038CEE4 A43A110C */  jal        func_0044ea90
    /* 28CEE8 0038CEE8 00000000 */   nop
    /* 28CEEC 0038CEEC 01000424 */  addiu      $4, $0, 0x1
    /* 28CEF0 0038CEF0 B8010524 */  addiu      $5, $0, 0x1B8
    /* 28CEF4 0038CEF4 0400063C */  lui        $6, (0x40000 >> 16)
    /* 28CEF8 0038CEF8 8800023C */  lui        $2, %hi(D_008873F4)
    /* 28CEFC 0038CEFC F473428C */  lw         $2, %lo(D_008873F4)($2)
    /* 28CF00 0038CF00 09F84000 */  jalr       $2
    /* 28CF04 0038CF04 00000000 */   nop
    /* 28CF08 0038CF08 2D884000 */  daddu      $17, $2, $0
    /* 28CF0C 0038CF0C 06002016 */  bnez       $17, .L0038CF28
    /* 28CF10 0038CF10 00000000 */   nop
    /* 28CF14 0038CF14 6500043C */  lui        $4, %hi(D_0064F0E0)
    /* 28CF18 0038CF18 E0F08424 */  addiu      $4, $4, %lo(D_0064F0E0)
    /* 28CF1C 0038CF1C 9E050524 */  addiu      $5, $0, 0x59E
    /* 28CF20 0038CF20 CCB5110C */  jal        func_0046d730
    /* 28CF24 0038CF24 00000000 */   nop
  .L0038CF28:
    /* 28CF28 0038CF28 2D204002 */  daddu      $4, $18, $0
    /* 28CF2C 0038CF2C 6500053C */  lui        $5, %hi(D_0064EED0)
    /* 28CF30 0038CF30 D0EEA524 */  addiu      $5, $5, %lo(D_0064EED0)
    /* 28CF34 0038CF34 13000624 */  addiu      $6, $0, 0x13
    /* 28CF38 0038CF38 2D380000 */  daddu      $7, $0, $0
    /* 28CF3C 0038CF3C 2D400000 */  daddu      $8, $0, $0
    /* 28CF40 0038CF40 3900093C */  lui        $9, %hi(func_0038ce30)
    /* 28CF44 0038CF44 30CE2925 */  addiu      $9, $9, %lo(func_0038ce30)
    /* 28CF48 0038CF48 39000A3C */  lui        $10, %hi(func_0038ce90)
    /* 28CF4C 0038CF4C 90CE4A25 */  addiu      $10, $10, %lo(func_0038ce90)
    /* 28CF50 0038CF50 2D582002 */  daddu      $11, $17, $0
    /* 28CF54 0038CF54 F047110C */  jal        func_00451fc0
    /* 28CF58 0038CF58 00000000 */   nop
    /* 28CF5C 0038CF5C 2D804000 */  daddu      $16, $2, $0
    /* 28CF60 0038CF60 06000016 */  bnez       $16, .L0038CF7C
    /* 28CF64 0038CF64 00000000 */   nop
    /* 28CF68 0038CF68 6500043C */  lui        $4, %hi(D_0064F0E0)
    /* 28CF6C 0038CF6C E0F08424 */  addiu      $4, $4, %lo(D_0064F0E0)
    /* 28CF70 0038CF70 A8050524 */  addiu      $5, $0, 0x5A8
    /* 28CF74 0038CF74 CCB5110C */  jal        func_0046d730
    /* 28CF78 0038CF78 00000000 */   nop
  .L0038CF7C:
    /* 28CF7C 0038CF7C 2D204002 */  daddu      $4, $18, $0
    /* 28CF80 0038CF80 44BA0D0C */  jal        func_0036e910
    /* 28CF84 0038CF84 00000000 */   nop
    /* 28CF88 0038CF88 000022AE */  sw         $2, 0x0($17)
    /* 28CF8C 0038CF8C 2D202002 */  daddu      $4, $17, $0
    /* 28CF90 0038CF90 F8280E0C */  jal        func_0038a3e0
    /* 28CF94 0038CF94 00000000 */   nop
    /* 28CF98 0038CF98 2D202002 */  daddu      $4, $17, $0
    /* 28CF9C 0038CF9C 2C270E0C */  jal        func_00389cb0
    /* 28CFA0 0038CFA0 00000000 */   nop
    /* 28CFA4 0038CFA4 08002426 */  addiu      $4, $17, 0x8
    /* 28CFA8 0038CFA8 2D280000 */  daddu      $5, $0, $0
    /* 28CFAC 0038CFAC 30000624 */  addiu      $6, $0, 0x30
    /* 28CFB0 0038CFB0 72FE100C */  jal        func_0043f9c8
    /* 28CFB4 0038CFB4 00000000 */   nop
    /* 28CFB8 0038CFB8 3900023C */  lui        $2, %hi(func_0038b490)
    /* 28CFBC 0038CFBC 90B44224 */  addiu      $2, $2, %lo(func_0038b490)
    /* 28CFC0 0038CFC0 100022AE */  sw         $2, 0x10($17)
    /* 28CFC4 0038CFC4 180031AE */  sw         $17, 0x18($17)
    /* 28CFC8 0038CFC8 38002426 */  addiu      $4, $17, 0x38
    /* 28CFCC 0038CFCC 2D280000 */  daddu      $5, $0, $0
    /* 28CFD0 0038CFD0 30000624 */  addiu      $6, $0, 0x30
    /* 28CFD4 0038CFD4 72FE100C */  jal        func_0043f9c8
    /* 28CFD8 0038CFD8 00000000 */   nop
    /* 28CFDC 0038CFDC 3900023C */  lui        $2, %hi(func_0038cd70)
    /* 28CFE0 0038CFE0 70CD4224 */  addiu      $2, $2, %lo(func_0038cd70)
    /* 28CFE4 0038CFE4 400022AE */  sw         $2, 0x40($17)
    /* 28CFE8 0038CFE8 480031AE */  sw         $17, 0x48($17)
    /* 28CFEC 0038CFEC 2D200002 */  daddu      $4, $16, $0
    /* 28CFF0 0038CFF0 08340E0C */  jal        func_0038d020
    /* 28CFF4 0038CFF4 00000000 */   nop
    /* 28CFF8 0038CFF8 2D100002 */  daddu      $2, $16, $0
    /* 28CFFC 0038CFFC 3000BFDF */  ld         $31, 0x30($29)
    /* 28D000 0038D000 2000B27B */  lq         $18, 0x20($29)
    /* 28D004 0038D004 1000B17B */  lq         $17, 0x10($29)
    /* 28D008 0038D008 0000B07B */  lq         $16, 0x0($29)
    /* 28D00C 0038D00C 4000BD27 */  addiu      $29, $29, 0x40
    /* 28D010 0038D010 0800E003 */  jr         $31
    /* 28D014 0038D014 00000000 */   nop
    /* 28D018 0038D018 00000000 */  nop
    /* 28D01C 0038D01C 00000000 */  nop
.size func_0038cec0, 0x160
