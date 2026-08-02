.section .text
.set noat
.set noreorder
glabel func_001de800
    /* DE800 001DE800 80FFBD27 */  addiu      $29, $29, -0x80
    /* DE804 001DE804 6000BFFF */  sd         $31, 0x60($29)
    /* DE808 001DE808 5000B57F */  sq         $21, 0x50($29)
    /* DE80C 001DE80C 4000B47F */  sq         $20, 0x40($29)
    /* DE810 001DE810 3000B37F */  sq         $19, 0x30($29)
    /* DE814 001DE814 2000B27F */  sq         $18, 0x20($29)
    /* DE818 001DE818 1000B17F */  sq         $17, 0x10($29)
    /* DE81C 001DE81C 0000B07F */  sq         $16, 0x0($29)
    /* DE820 001DE820 2D808000 */  daddu      $16, $4, $0
    /* DE824 001DE824 3000828C */  lw         $2, 0x30($4)
    /* DE828 001DE828 A4004394 */  lhu        $3, 0xA4($2)
    /* DE82C 001DE82C 80100300 */  sll        $2, $3, 2
    /* DE830 001DE830 21104300 */  addu       $2, $2, $3
    /* DE834 001DE834 C0100200 */  sll        $2, $2, 3
    /* DE838 001DE838 21104300 */  addu       $2, $2, $3
    /* DE83C 001DE83C 80180200 */  sll        $3, $2, 2
    /* DE840 001DE840 D0B3828F */  lw         $2, -0x4C30($28)
    /* DE844 001DE844 21984300 */  addu       $19, $2, $3
    /* DE848 001DE848 2DA80000 */  daddu      $21, $0, $0
    /* DE84C 001DE84C 7F000010 */  b          .L001DEA4C
    /* DE850 001DE850 00000000 */   nop
  .L001DE854:
    /* DE854 001DE854 FFFFA332 */  andi       $3, $21, 0xFFFF
    /* DE858 001DE858 80100300 */  sll        $2, $3, 2
    /* DE85C 001DE85C 21104300 */  addu       $2, $2, $3
    /* DE860 001DE860 80100200 */  sll        $2, $2, 2
    /* DE864 001DE864 21106202 */  addu       $2, $19, $2
    /* DE868 001DE868 04005224 */  addiu      $18, $2, 0x4
    /* DE86C 001DE86C 2DA00000 */  daddu      $20, $0, $0
    /* DE870 001DE870 1D000010 */  b          .L001DE8E8
    /* DE874 001DE874 00000000 */   nop
  .L001DE878:
    /* DE878 001DE878 FFFF8232 */  andi       $2, $20, 0xFFFF
    /* DE87C 001DE87C 80880200 */  sll        $17, $2, 2
    /* DE880 001DE880 21105102 */  addu       $2, $18, $17
    /* DE884 001DE884 0000448C */  lw         $4, 0x0($2)
    /* DE888 001DE888 00FF023C */  lui        $2, (0xFF000000 >> 16)
    /* DE88C 001DE88C 24108200 */  and        $2, $4, $2
    /* DE890 001DE890 021E0200 */  srl        $3, $2, 24
    /* DE894 001DE894 3C2A0400 */  dsll32     $5, $4, 8
    /* DE898 001DE898 3E2A0500 */  dsrl32     $5, $5, 8
    /* DE89C 001DE89C 04006014 */  bnez       $3, .L001DE8B0
    /* DE8A0 001DE8A0 00000000 */   nop
    /* DE8A4 001DE8A4 2D100000 */  daddu      $2, $0, $0
    /* DE8A8 001DE8A8 0B000010 */  b          .L001DE8D8
    /* DE8AC 001DE8AC 00000000 */   nop
  .L001DE8B0:
    /* DE8B0 001DE8B0 2D200002 */  daddu      $4, $16, $0
    /* DE8B4 001DE8B4 40100300 */  sll        $2, $3, 1
    /* DE8B8 001DE8B8 21104300 */  addu       $2, $2, $3
    /* DE8BC 001DE8BC 80180200 */  sll        $3, $2, 2
    /* DE8C0 001DE8C0 6100023C */  lui        $2, %hi(D_00609850)
    /* DE8C4 001DE8C4 50984224 */  addiu      $2, $2, %lo(D_00609850)
    /* DE8C8 001DE8C8 21104300 */  addu       $2, $2, $3
    /* DE8CC 001DE8CC 0000428C */  lw         $2, 0x0($2)
    /* DE8D0 001DE8D0 09F84000 */  jalr       $2
    /* DE8D4 001DE8D4 00000000 */   nop
  .L001DE8D8:
    /* DE8D8 001DE8D8 21183D02 */  addu       $3, $17, $29
    /* DE8DC 001DE8DC 700062AC */  sw         $2, 0x70($3)
    /* DE8E0 001DE8E0 01008226 */  addiu      $2, $20, 0x1
    /* DE8E4 001DE8E4 FFFF5430 */  andi       $20, $2, 0xFFFF
  .L001DE8E8:
    /* DE8E8 001DE8E8 FFFF8232 */  andi       $2, $20, 0xFFFF
    /* DE8EC 001DE8EC 03004228 */  slti       $2, $2, 0x3
    /* DE8F0 001DE8F0 E1FF4014 */  bnez       $2, .L001DE878
    /* DE8F4 001DE8F4 00000000 */   nop
    /* DE8F8 001DE8F8 7000A28F */  lw         $2, 0x70($29)
    /* DE8FC 001DE8FC 0D004010 */  beqz       $2, .L001DE934
    /* DE900 001DE900 00000000 */   nop
    /* DE904 001DE904 7400A28F */  lw         $2, 0x74($29)
    /* DE908 001DE908 0A004010 */  beqz       $2, .L001DE934
    /* DE90C 001DE90C 00000000 */   nop
    /* DE910 001DE910 7800A28F */  lw         $2, 0x78($29)
    /* DE914 001DE914 07004010 */  beqz       $2, .L001DE934
    /* DE918 001DE918 00000000 */   nop
    /* DE91C 001DE91C 0C004292 */  lbu        $2, 0xC($18)
    /* DE920 001DE920 08000324 */  addiu      $3, $0, 0x8
    /* DE924 001DE924 03004310 */  beq        $2, $3, .L001DE934
    /* DE928 001DE928 00000000 */   nop
    /* DE92C 001DE92C 4C000010 */  b          .L001DEA60
    /* DE930 001DE930 00000000 */   nop
  .L001DE934:
    /* DE934 001DE934 7000A28F */  lw         $2, 0x70($29)
    /* DE938 001DE938 0A004010 */  beqz       $2, .L001DE964
    /* DE93C 001DE93C 00000000 */   nop
    /* DE940 001DE940 7400A28F */  lw         $2, 0x74($29)
    /* DE944 001DE944 07004010 */  beqz       $2, .L001DE964
    /* DE948 001DE948 00000000 */   nop
    /* DE94C 001DE94C 0D004292 */  lbu        $2, 0xD($18)
    /* DE950 001DE950 08000324 */  addiu      $3, $0, 0x8
    /* DE954 001DE954 03004310 */  beq        $2, $3, .L001DE964
    /* DE958 001DE958 00000000 */   nop
    /* DE95C 001DE95C 40000010 */  b          .L001DEA60
    /* DE960 001DE960 00000000 */   nop
  .L001DE964:
    /* DE964 001DE964 7000A28F */  lw         $2, 0x70($29)
    /* DE968 001DE968 0A004010 */  beqz       $2, .L001DE994
    /* DE96C 001DE96C 00000000 */   nop
    /* DE970 001DE970 7800A28F */  lw         $2, 0x78($29)
    /* DE974 001DE974 07004010 */  beqz       $2, .L001DE994
    /* DE978 001DE978 00000000 */   nop
    /* DE97C 001DE97C 0E004292 */  lbu        $2, 0xE($18)
    /* DE980 001DE980 08000324 */  addiu      $3, $0, 0x8
    /* DE984 001DE984 03004310 */  beq        $2, $3, .L001DE994
    /* DE988 001DE988 00000000 */   nop
    /* DE98C 001DE98C 34000010 */  b          .L001DEA60
    /* DE990 001DE990 00000000 */   nop
  .L001DE994:
    /* DE994 001DE994 7400A48F */  lw         $4, 0x74($29)
    /* DE998 001DE998 0A008010 */  beqz       $4, .L001DE9C4
    /* DE99C 001DE99C 00000000 */   nop
    /* DE9A0 001DE9A0 7800A28F */  lw         $2, 0x78($29)
    /* DE9A4 001DE9A4 07004010 */  beqz       $2, .L001DE9C4
    /* DE9A8 001DE9A8 00000000 */   nop
    /* DE9AC 001DE9AC 0F004292 */  lbu        $2, 0xF($18)
    /* DE9B0 001DE9B0 08000324 */  addiu      $3, $0, 0x8
    /* DE9B4 001DE9B4 03004310 */  beq        $2, $3, .L001DE9C4
    /* DE9B8 001DE9B8 00000000 */   nop
    /* DE9BC 001DE9BC 28000010 */  b          .L001DEA60
    /* DE9C0 001DE9C0 00000000 */   nop
  .L001DE9C4:
    /* DE9C4 001DE9C4 7000A28F */  lw         $2, 0x70($29)
    /* DE9C8 001DE9C8 07004010 */  beqz       $2, .L001DE9E8
    /* DE9CC 001DE9CC 00000000 */   nop
    /* DE9D0 001DE9D0 10004292 */  lbu        $2, 0x10($18)
    /* DE9D4 001DE9D4 08000324 */  addiu      $3, $0, 0x8
    /* DE9D8 001DE9D8 03004310 */  beq        $2, $3, .L001DE9E8
    /* DE9DC 001DE9DC 00000000 */   nop
    /* DE9E0 001DE9E0 1F000010 */  b          .L001DEA60
    /* DE9E4 001DE9E4 00000000 */   nop
  .L001DE9E8:
    /* DE9E8 001DE9E8 07008010 */  beqz       $4, .L001DEA08
    /* DE9EC 001DE9EC 00000000 */   nop
    /* DE9F0 001DE9F0 11004292 */  lbu        $2, 0x11($18)
    /* DE9F4 001DE9F4 08000324 */  addiu      $3, $0, 0x8
    /* DE9F8 001DE9F8 03004310 */  beq        $2, $3, .L001DEA08
    /* DE9FC 001DE9FC 00000000 */   nop
    /* DEA00 001DEA00 17000010 */  b          .L001DEA60
    /* DEA04 001DEA04 00000000 */   nop
  .L001DEA08:
    /* DEA08 001DEA08 7800A28F */  lw         $2, 0x78($29)
    /* DEA0C 001DEA0C 07004010 */  beqz       $2, .L001DEA2C
    /* DEA10 001DEA10 00000000 */   nop
    /* DEA14 001DEA14 12004292 */  lbu        $2, 0x12($18)
    /* DEA18 001DEA18 08000324 */  addiu      $3, $0, 0x8
    /* DEA1C 001DEA1C 03004310 */  beq        $2, $3, .L001DEA2C
    /* DEA20 001DEA20 00000000 */   nop
    /* DEA24 001DEA24 0E000010 */  b          .L001DEA60
    /* DEA28 001DEA28 00000000 */   nop
  .L001DEA2C:
    /* DEA2C 001DEA2C 13004292 */  lbu        $2, 0x13($18)
    /* DEA30 001DEA30 08000324 */  addiu      $3, $0, 0x8
    /* DEA34 001DEA34 03004310 */  beq        $2, $3, .L001DEA44
    /* DEA38 001DEA38 00000000 */   nop
    /* DEA3C 001DEA3C 08000010 */  b          .L001DEA60
    /* DEA40 001DEA40 00000000 */   nop
  .L001DEA44:
    /* DEA44 001DEA44 0100A226 */  addiu      $2, $21, 0x1
    /* DEA48 001DEA48 FFFF5530 */  andi       $21, $2, 0xFFFF
  .L001DEA4C:
    /* DEA4C 001DEA4C FFFFA232 */  andi       $2, $21, 0xFFFF
    /* DEA50 001DEA50 02004228 */  slti       $2, $2, 0x2
    /* DEA54 001DEA54 7FFF4014 */  bnez       $2, .L001DE854
    /* DEA58 001DEA58 00000000 */   nop
    /* DEA5C 001DEA5C 2D100000 */  daddu      $2, $0, $0
  .L001DEA60:
    /* DEA60 001DEA60 6000BFDF */  ld         $31, 0x60($29)
    /* DEA64 001DEA64 5000B57B */  lq         $21, 0x50($29)
    /* DEA68 001DEA68 4000B47B */  lq         $20, 0x40($29)
    /* DEA6C 001DEA6C 3000B37B */  lq         $19, 0x30($29)
    /* DEA70 001DEA70 2000B27B */  lq         $18, 0x20($29)
    /* DEA74 001DEA74 1000B17B */  lq         $17, 0x10($29)
    /* DEA78 001DEA78 0000B07B */  lq         $16, 0x0($29)
    /* DEA7C 001DEA7C 8000BD27 */  addiu      $29, $29, 0x80
    /* DEA80 001DEA80 0800E003 */  jr         $31
    /* DEA84 001DEA84 00000000 */   nop
    /* DEA88 001DEA88 00000000 */  nop
    /* DEA8C 001DEA8C 00000000 */  nop
.size func_001de800, 0x290
