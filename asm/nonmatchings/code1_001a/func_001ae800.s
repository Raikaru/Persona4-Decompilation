.section .text
.set noat
.set noreorder
glabel func_001ae800
    /* AE800 001AE800 C0FFBD27 */  addiu      $29, $29, -0x40
    /* AE804 001AE804 2000BFFF */  sd         $31, 0x20($29)
    /* AE808 001AE808 1000B17F */  sq         $17, 0x10($29)
    /* AE80C 001AE80C 0000B07F */  sq         $16, 0x0($29)
    /* AE810 001AE810 2D808000 */  daddu      $16, $4, $0
    /* AE814 001AE814 2404828C */  lw         $2, 0x424($4)
    /* AE818 001AE818 4C004014 */  bnez       $2, .L001AE94C
    /* AE81C 001AE81C 00000000 */   nop
    /* AE820 001AE820 000C0424 */  addiu      $4, $0, 0xC00
    /* AE824 001AE824 344F060C */  jal        func_00193cd0
    /* AE828 001AE828 00000000 */   nop
    /* AE82C 001AE82C F5004014 */  bnez       $2, .L001AEC04
    /* AE830 001AE830 00000000 */   nop
    /* AE834 001AE834 040C0424 */  addiu      $4, $0, 0xC04
    /* AE838 001AE838 344F060C */  jal        func_00193cd0
    /* AE83C 001AE83C 00000000 */   nop
    /* AE840 001AE840 F0004014 */  bnez       $2, .L001AEC04
    /* AE844 001AE844 00000000 */   nop
    /* AE848 001AE848 3000A0A7 */  sh         $0, 0x30($29)
    /* AE84C 001AE84C 2D300000 */  daddu      $6, $0, $0
    /* AE850 001AE850 ACB3858F */  lw         $5, -0x4C54($28)
    /* AE854 001AE854 0C000010 */  b          .L001AE888
    /* AE858 001AE858 00000000 */   nop
  .L001AE85C:
    /* AE85C 001AE85C FFFFC430 */  andi       $4, $6, 0xFFFF
    /* AE860 001AE860 80100400 */  sll        $2, $4, 2
    /* AE864 001AE864 2110A200 */  addu       $2, $5, $2
    /* AE868 001AE868 480C428C */  lw         $2, 0xC48($2)
    /* AE86C 001AE86C 3000428C */  lw         $2, 0x30($2)
    /* AE870 001AE870 A4004394 */  lhu        $3, 0xA4($2)
    /* AE874 001AE874 40100400 */  sll        $2, $4, 1
    /* AE878 001AE878 21105D00 */  addu       $2, $2, $29
    /* AE87C 001AE87C 320043A4 */  sh         $3, 0x32($2)
    /* AE880 001AE880 0100C224 */  addiu      $2, $6, 0x1
    /* AE884 001AE884 FFFF4630 */  andi       $6, $2, 0xFFFF
  .L001AE888:
    /* AE888 001AE888 FFFFC230 */  andi       $2, $6, 0xFFFF
    /* AE88C 001AE88C 580CA394 */  lhu        $3, 0xC58($5)
    /* AE890 001AE890 2A104300 */  slt        $2, $2, $3
    /* AE894 001AE894 F1FF4014 */  bnez       $2, .L001AE85C
    /* AE898 001AE898 00000000 */   nop
    /* AE89C 001AE89C 3800A3A7 */  sh         $3, 0x38($29)
    /* AE8A0 001AE8A0 3000A427 */  addiu      $4, $29, 0x30
    /* AE8A4 001AE8A4 44E8070C */  jal        func_001fa110
    /* AE8A8 001AE8A8 00000000 */   nop
    /* AE8AC 001AE8AC 2D204000 */  daddu      $4, $2, $0
    /* AE8B0 001AE8B0 01000524 */  addiu      $5, $0, 0x1
    /* AE8B4 001AE8B4 6451060C */  jal        func_00194590
    /* AE8B8 001AE8B8 00000000 */   nop
    /* AE8BC 001AE8BC 3CEA070C */  jal        func_001fa8f0
    /* AE8C0 001AE8C0 00000000 */   nop
    /* AE8C4 001AE8C4 2D204000 */  daddu      $4, $2, $0
    /* AE8C8 001AE8C8 2C040386 */  lh         $3, 0x42C($16)
    /* AE8CC 001AE8CC 480043A4 */  sh         $3, 0x48($2)
    /* AE8D0 001AE8D0 01000524 */  addiu      $5, $0, 0x1
    /* AE8D4 001AE8D4 6451060C */  jal        func_00194590
    /* AE8D8 001AE8D8 00000000 */   nop
    /* AE8DC 001AE8DC 1B00043C */  lui        $4, %hi(func_001ae3c0)
    /* AE8E0 001AE8E0 C0E38424 */  addiu      $4, $4, %lo(func_001ae3c0)
    /* AE8E4 001AE8E4 2D280002 */  daddu      $5, $16, $0
    /* AE8E8 001AE8E8 2453060C */  jal        func_00194c90
    /* AE8EC 001AE8EC 00000000 */   nop
    /* AE8F0 001AE8F0 2D884000 */  daddu      $17, $2, $0
    /* AE8F4 001AE8F4 2C040386 */  lh         $3, 0x42C($16)
    /* AE8F8 001AE8F8 480043A4 */  sh         $3, 0x48($2)
    /* AE8FC 001AE8FC 2D202002 */  daddu      $4, $17, $0
    /* AE900 001AE900 01000524 */  addiu      $5, $0, 0x1
    /* AE904 001AE904 6451060C */  jal        func_00194590
    /* AE908 001AE908 00000000 */   nop
    /* AE90C 001AE90C ACB3828F */  lw         $2, -0x4C54($28)
    /* AE910 001AE910 8C0D448C */  lw         $4, 0xD8C($2)
    /* AE914 001AE914 3000058E */  lw         $5, 0x30($16)
    /* AE918 001AE918 2D300000 */  daddu      $6, $0, $0
    /* AE91C 001AE91C 580027DE */  ld         $7, 0x58($17)
    /* AE920 001AE920 00800834 */  ori        $8, $0, 0x8000
    /* AE924 001AE924 7459070C */  jal        func_001d65d0
    /* AE928 001AE928 00000000 */   nop
    /* AE92C 001AE92C 2D204000 */  daddu      $4, $2, $0
    /* AE930 001AE930 2C040386 */  lh         $3, 0x42C($16)
    /* AE934 001AE934 480043A4 */  sh         $3, 0x48($2)
    /* AE938 001AE938 02000524 */  addiu      $5, $0, 0x2
    /* AE93C 001AE93C 6451060C */  jal        func_00194590
    /* AE940 001AE940 00000000 */   nop
    /* AE944 001AE944 01000224 */  addiu      $2, $0, 0x1
    /* AE948 001AE948 240402AE */  sw         $2, 0x424($16)
  .L001AE94C:
    /* AE94C 001AE94C 2004028E */  lw         $2, 0x420($16)
    /* AE950 001AE950 0F004014 */  bnez       $2, .L001AE990
    /* AE954 001AE954 00000000 */   nop
    /* AE958 001AE958 2C040286 */  lh         $2, 0x42C($16)
    /* AE95C 001AE95C 0A00401C */  bgtz       $2, .L001AE988
    /* AE960 001AE960 00000000 */   nop
    /* AE964 001AE964 ACB3828F */  lw         $2, -0x4C54($28)
    /* AE968 001AE968 D40D448C */  lw         $4, 0xDD4($2)
    /* AE96C 001AE96C 1C04058E */  lw         $5, 0x41C($16)
    /* AE970 001AE970 5860080C */  jal        func_00218160
    /* AE974 001AE974 00000000 */   nop
    /* AE978 001AE978 01000224 */  addiu      $2, $0, 0x1
    /* AE97C 001AE97C 200402AE */  sw         $2, 0x420($16)
    /* AE980 001AE980 03000010 */  b          .L001AE990
    /* AE984 001AE984 00000000 */   nop
  .L001AE988:
    /* AE988 001AE988 FFFF4224 */  addiu      $2, $2, -0x1
    /* AE98C 001AE98C 2C0402A6 */  sh         $2, 0x42C($16)
  .L001AE990:
    /* AE990 001AE990 000004DE */  ld         $4, 0x0($16)
    /* AE994 001AE994 FF3F023C */  lui        $2, (0x3FFFFFFF >> 16)
    /* AE998 001AE998 FFFF4234 */  ori        $2, $2, (0x3FFFFFFF & 0xFFFF)
    /* AE99C 001AE99C 3C180200 */  dsll32     $3, $2, 0
    /* AE9A0 001AE9A0 FFFF0234 */  ori        $2, $0, 0xFFFF
    /* AE9A4 001AE9A4 38140200 */  dsll       $2, $2, 16
    /* AE9A8 001AE9A8 FFFF4234 */  ori        $2, $2, 0xFFFF
    /* AE9AC 001AE9AC 25284300 */  or         $5, $2, $3
    /* AE9B0 001AE9B0 FC4E060C */  jal        func_00193bf0
    /* AE9B4 001AE9B4 00000000 */   nop
    /* AE9B8 001AE9B8 92004014 */  bnez       $2, .L001AEC04
    /* AE9BC 001AE9BC 00000000 */   nop
    /* AE9C0 001AE9C0 2804038E */  lw         $3, 0x428($16)
    /* AE9C4 001AE9C4 77006014 */  bnez       $3, .L001AEBA4
    /* AE9C8 001AE9C8 00000000 */   nop
    /* AE9CC 001AE9CC ACB3828F */  lw         $2, -0x4C54($28)
    /* AE9D0 001AE9D0 D40D448C */  lw         $4, 0xDD4($2)
    /* AE9D4 001AE9D4 8060080C */  jal        func_00218200
    /* AE9D8 001AE9D8 00000000 */   nop
    /* AE9DC 001AE9DC 89004010 */  beqz       $2, .L001AEC04
    /* AE9E0 001AE9E0 00000000 */   nop
    /* AE9E4 001AE9E4 ACB3828F */  lw         $2, -0x4C54($28)
    /* AE9E8 001AE9E8 D40D448C */  lw         $4, 0xDD4($2)
    /* AE9EC 001AE9EC 8C60080C */  jal        func_00218230
    /* AE9F0 001AE9F0 00000000 */   nop
    /* AE9F4 001AE9F4 30004014 */  bnez       $2, .L001AEAB8
    /* AE9F8 001AE9F8 00000000 */   nop
    /* AE9FC 001AE9FC 2D200002 */  daddu      $4, $16, $0
    /* AEA00 001AEA00 02000524 */  addiu      $5, $0, 0x2
    /* AEA04 001AEA04 1CCE070C */  jal        func_001f3870
    /* AEA08 001AEA08 00000000 */   nop
    /* AEA0C 001AEA0C 2D204000 */  daddu      $4, $2, $0
    /* AEA10 001AEA10 000003DE */  ld         $3, 0x0($16)
    /* AEA14 001AEA14 600043FC */  sd         $3, 0x60($2)
    /* AEA18 001AEA18 01000524 */  addiu      $5, $0, 0x1
    /* AEA1C 001AEA1C 6451060C */  jal        func_00194590
    /* AEA20 001AEA20 00000000 */   nop
    /* AEA24 001AEA24 1C04038E */  lw         $3, 0x41C($16)
    /* AEA28 001AEA28 ACB3828F */  lw         $2, -0x4C54($28)
    /* AEA2C 001AEA2C 7001428C */  lw         $2, 0x170($2)
    /* AEA30 001AEA30 340443AC */  sw         $3, 0x434($2)
    /* AEA34 001AEA34 1F000324 */  addiu      $3, $0, 0x1F
    /* AEA38 001AEA38 ACB3828F */  lw         $2, -0x4C54($28)
    /* AEA3C 001AEA3C 7001428C */  lw         $2, 0x170($2)
    /* AEA40 001AEA40 160043A4 */  sh         $3, 0x16($2)
    /* AEA44 001AEA44 ACB3828F */  lw         $2, -0x4C54($28)
    /* AEA48 001AEA48 7001448C */  lw         $4, 0x170($2)
    /* AEA4C 001AEA4C 8CC3060C */  jal        func_001b0e30
    /* AEA50 001AEA50 00000000 */   nop
    /* AEA54 001AEA54 50C5060C */  jal        func_001b1540
    /* AEA58 001AEA58 00000000 */   nop
    /* AEA5C 001AEA5C 3000438C */  lw         $3, 0x30($2)
    /* AEA60 001AEA60 A2006390 */  lbu        $3, 0xA2($3)
    /* AEA64 001AEA64 07006014 */  bnez       $3, .L001AEA84
    /* AEA68 001AEA68 00000000 */   nop
    /* AEA6C 001AEA6C 28004390 */  lbu        $3, 0x28($2)
    /* AEA70 001AEA70 04006010 */  beqz       $3, .L001AEA84
    /* AEA74 001AEA74 00000000 */   nop
    /* AEA78 001AEA78 18004394 */  lhu        $3, 0x18($2)
    /* AEA7C 001AEA7C 00806334 */  ori        $3, $3, 0x8000
    /* AEA80 001AEA80 180043A4 */  sh         $3, 0x18($2)
  .L001AEA84:
    /* AEA84 001AEA84 1C04048E */  lw         $4, 0x41C($16)
    /* AEA88 001AEA88 06000524 */  addiu      $5, $0, 0x6
    /* AEA8C 001AEA8C 01000624 */  addiu      $6, $0, 0x1
    /* AEA90 001AEA90 2D380000 */  daddu      $7, $0, $0
    /* AEA94 001AEA94 2D400000 */  daddu      $8, $0, $0
    /* AEA98 001AEA98 70E6070C */  jal        func_001f99c0
    /* AEA9C 001AEA9C 00000000 */   nop
    /* AEAA0 001AEAA0 2D204000 */  daddu      $4, $2, $0
    /* AEAA4 001AEAA4 01000524 */  addiu      $5, $0, 0x1
    /* AEAA8 001AEAA8 6451060C */  jal        func_00194590
    /* AEAAC 001AEAAC 00000000 */   nop
    /* AEAB0 001AEAB0 14000010 */  b          .L001AEB04
    /* AEAB4 001AEAB4 00000000 */   nop
  .L001AEAB8:
    /* AEAB8 001AEAB8 1C04048E */  lw         $4, 0x41C($16)
    /* AEABC 001AEABC 06000524 */  addiu      $5, $0, 0x6
    /* AEAC0 001AEAC0 2D300000 */  daddu      $6, $0, $0
    /* AEAC4 001AEAC4 2D380000 */  daddu      $7, $0, $0
    /* AEAC8 001AEAC8 2D400000 */  daddu      $8, $0, $0
    /* AEACC 001AEACC 70E6070C */  jal        func_001f99c0
    /* AEAD0 001AEAD0 00000000 */   nop
    /* AEAD4 001AEAD4 2D204000 */  daddu      $4, $2, $0
    /* AEAD8 001AEAD8 01000524 */  addiu      $5, $0, 0x1
    /* AEADC 001AEADC 6451060C */  jal        func_00194590
    /* AEAE0 001AEAE0 00000000 */   nop
    /* AEAE4 001AEAE4 14E9070C */  jal        func_001fa450
    /* AEAE8 001AEAE8 00000000 */   nop
    /* AEAEC 001AEAEC 2D204000 */  daddu      $4, $2, $0
    /* AEAF0 001AEAF0 000003DE */  ld         $3, 0x0($16)
    /* AEAF4 001AEAF4 600043FC */  sd         $3, 0x60($2)
    /* AEAF8 001AEAF8 01000524 */  addiu      $5, $0, 0x1
    /* AEAFC 001AEAFC 6451060C */  jal        func_00194590
    /* AEB00 001AEB00 00000000 */   nop
  .L001AEB04:
    /* AEB04 001AEB04 98EA070C */  jal        func_001faa60
    /* AEB08 001AEB08 00000000 */   nop
    /* AEB0C 001AEB0C 2D204000 */  daddu      $4, $2, $0
    /* AEB10 001AEB10 000003DE */  ld         $3, 0x0($16)
    /* AEB14 001AEB14 600043FC */  sd         $3, 0x60($2)
    /* AEB18 001AEB18 01000524 */  addiu      $5, $0, 0x1
    /* AEB1C 001AEB1C 6451060C */  jal        func_00194590
    /* AEB20 001AEB20 00000000 */   nop
    /* AEB24 001AEB24 2D200000 */  daddu      $4, $0, $0
    /* AEB28 001AEB28 01000524 */  addiu      $5, $0, 0x1
    /* AEB2C 001AEB2C F079060C */  jal        func_0019e7c0
    /* AEB30 001AEB30 00000000 */   nop
    /* AEB34 001AEB34 2D204000 */  daddu      $4, $2, $0
    /* AEB38 001AEB38 000003DE */  ld         $3, 0x0($16)
    /* AEB3C 001AEB3C 600043FC */  sd         $3, 0x60($2)
    /* AEB40 001AEB40 01000524 */  addiu      $5, $0, 0x1
    /* AEB44 001AEB44 6451060C */  jal        func_00194590
    /* AEB48 001AEB48 00000000 */   nop
    /* AEB4C 001AEB4C 18000296 */  lhu        $2, 0x18($16)
    /* AEB50 001AEB50 F7FF4230 */  andi       $2, $2, 0xFFF7
    /* AEB54 001AEB54 180002A6 */  sh         $2, 0x18($16)
    /* AEB58 001AEB58 18AE070C */  jal        func_001eb860
    /* AEB5C 001AEB5C 00000000 */   nop
    /* AEB60 001AEB60 01000524 */  addiu      $5, $0, 0x1
    /* AEB64 001AEB64 09004514 */  bne        $2, $5, .L001AEB8C
    /* AEB68 001AEB68 00000000 */   nop
    /* AEB6C 001AEB6C ACB3838F */  lw         $3, -0x4C54($28)
    /* AEB70 001AEB70 0C00628C */  lw         $2, 0xC($3)
    /* AEB74 001AEB74 00204234 */  ori        $2, $2, 0x2000
    /* AEB78 001AEB78 0C0062AC */  sw         $2, 0xC($3)
    /* AEB7C 001AEB7C ACB3828F */  lw         $2, -0x4C54($28)
    /* AEB80 001AEB80 D40D448C */  lw         $4, 0xDD4($2)
    /* AEB84 001AEB84 9048080C */  jal        func_00212240
    /* AEB88 001AEB88 00000000 */   nop
  .L001AEB8C:
    /* AEB8C 001AEB8C 01000324 */  addiu      $3, $0, 0x1
    /* AEB90 001AEB90 280403AE */  sw         $3, 0x428($16)
    /* AEB94 001AEB94 06000324 */  addiu      $3, $0, 0x6
    /* AEB98 001AEB98 2E0403A6 */  sh         $3, 0x42E($16)
    /* AEB9C 001AEB9C 19000010 */  b          .L001AEC04
    /* AEBA0 001AEBA0 00000000 */   nop
  .L001AEBA4:
    /* AEBA4 001AEBA4 2E040396 */  lhu        $3, 0x42E($16)
    /* AEBA8 001AEBA8 14006014 */  bnez       $3, .L001AEBFC
    /* AEBAC 001AEBAC 00000000 */   nop
    /* AEBB0 001AEBB0 ACB3828F */  lw         $2, -0x4C54($28)
    /* AEBB4 001AEBB4 D40D448C */  lw         $4, 0xDD4($2)
    /* AEBB8 001AEBB8 9860080C */  jal        func_00218260
    /* AEBBC 001AEBBC 00000000 */   nop
    /* AEBC0 001AEBC0 ACB3848F */  lw         $4, -0x4C54($28)
    /* AEBC4 001AEBC4 0C00838C */  lw         $3, 0xC($4)
    /* AEBC8 001AEBC8 4000023C */  lui        $2, (0x400000 >> 16)
    /* AEBCC 001AEBCC 25106200 */  or         $2, $3, $2
    /* AEBD0 001AEBD0 0C0082AC */  sw         $2, 0xC($4)
    /* AEBD4 001AEBD4 ACB3838F */  lw         $3, -0x4C54($28)
    /* AEBD8 001AEBD8 18006294 */  lhu        $2, 0x18($3)
    /* AEBDC 001AEBDC 07004234 */  ori        $2, $2, 0x7
    /* AEBE0 001AEBE0 180062A4 */  sh         $2, 0x18($3)
    /* AEBE4 001AEBE4 2D200002 */  daddu      $4, $16, $0
    /* AEBE8 001AEBE8 20000524 */  addiu      $5, $0, 0x20
    /* AEBEC 001AEBEC 00C2060C */  jal        func_001b0800
    /* AEBF0 001AEBF0 00000000 */   nop
    /* AEBF4 001AEBF4 03000010 */  b          .L001AEC04
    /* AEBF8 001AEBF8 00000000 */   nop
  .L001AEBFC:
    /* AEBFC 001AEBFC FFFF6324 */  addiu      $3, $3, -0x1
    /* AEC00 001AEC00 2E0403A6 */  sh         $3, 0x42E($16)
  .L001AEC04:
    /* AEC04 001AEC04 2000BFDF */  ld         $31, 0x20($29)
    /* AEC08 001AEC08 1000B17B */  lq         $17, 0x10($29)
    /* AEC0C 001AEC0C 0000B07B */  lq         $16, 0x0($29)
    /* AEC10 001AEC10 4000BD27 */  addiu      $29, $29, 0x40
    /* AEC14 001AEC14 0800E003 */  jr         $31
    /* AEC18 001AEC18 00000000 */   nop
    /* AEC1C 001AEC1C 00000000 */  nop
.size func_001ae800, 0x420
