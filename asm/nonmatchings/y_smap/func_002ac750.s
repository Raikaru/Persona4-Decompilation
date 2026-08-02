.section .text
.set noat
.set noreorder
glabel func_002ac750
    /* 1AC750 002AC750 70FEBD27 */  addiu      $29, $29, -0x190
    /* 1AC754 002AC754 9000BFFF */  sd         $31, 0x90($29)
    /* 1AC758 002AC758 8000BE7F */  sq         $30, 0x80($29)
    /* 1AC75C 002AC75C 7000B77F */  sq         $23, 0x70($29)
    /* 1AC760 002AC760 6000B67F */  sq         $22, 0x60($29)
    /* 1AC764 002AC764 5000B57F */  sq         $21, 0x50($29)
    /* 1AC768 002AC768 4000B47F */  sq         $20, 0x40($29)
    /* 1AC76C 002AC76C 3000B37F */  sq         $19, 0x30($29)
    /* 1AC770 002AC770 2000B27F */  sq         $18, 0x20($29)
    /* 1AC774 002AC774 1000B17F */  sq         $17, 0x10($29)
    /* 1AC778 002AC778 0000B07F */  sq         $16, 0x0($29)
    /* 1AC77C 002AC77C 2DA08000 */  daddu      $20, $4, $0
    /* 1AC780 002AC780 2D98A000 */  daddu      $19, $5, $0
    /* 1AC784 002AC784 FF007232 */  andi       $18, $19, 0xFF
    /* 1AC788 002AC788 008A1200 */  sll        $17, $18, 8
    /* 1AC78C 002AC78C FF008232 */  andi       $2, $20, 0xFF
    /* 1AC790 002AC790 00810200 */  sll        $16, $2, 4
    /* 1AC794 002AC794 A054050C */  jal        func_00155280
    /* 1AC798 002AC798 00000000 */   nop
    /* 1AC79C 002AC79C 21105100 */  addu       $2, $2, $17
    /* 1AC7A0 002AC7A0 21105000 */  addu       $2, $2, $16
    /* 1AC7A4 002AC7A4 58004290 */  lbu        $2, 0x58($2)
    /* 1AC7A8 002AC7A8 07004128 */  slti       $1, $2, 0x7
    /* 1AC7AC 002AC7AC DB012010 */  beqz       $1, .L002ACF1C
    /* 1AC7B0 002AC7B0 00000000 */   nop
    /* 1AC7B4 002AC7B4 A054050C */  jal        func_00155280
    /* 1AC7B8 002AC7B8 00000000 */   nop
    /* 1AC7BC 002AC7BC 21185100 */  addu       $3, $2, $17
    /* 1AC7C0 002AC7C0 21187000 */  addu       $3, $3, $16
    /* 1AC7C4 002AC7C4 58006490 */  lbu        $4, 0x58($3)
    /* 1AC7C8 002AC7C8 02000324 */  addiu      $3, $0, 0x2
    /* 1AC7CC 002AC7CC C7018314 */  bne        $4, $3, .L002ACEEC
    /* 1AC7D0 002AC7D0 00000000 */   nop
    /* 1AC7D4 002AC7D4 A054050C */  jal        func_00155280
    /* 1AC7D8 002AC7D8 00000000 */   nop
    /* 1AC7DC 002AC7DC 21105100 */  addu       $2, $2, $17
    /* 1AC7E0 002AC7E0 21105000 */  addu       $2, $2, $16
    /* 1AC7E4 002AC7E4 55004490 */  lbu        $4, 0x55($2)
    /* 1AC7E8 002AC7E8 3CB70A0C */  jal        func_002adcf0
    /* 1AC7EC 002AC7EC 00000000 */   nop
    /* 1AC7F0 002AC7F0 3C1E0200 */  dsll32     $3, $2, 24
    /* 1AC7F4 002AC7F4 3F1E0300 */  dsra32     $3, $3, 24
    /* 1AC7F8 002AC7F8 01000224 */  addiu      $2, $0, 0x1
    /* 1AC7FC 002AC7FC A3016214 */  bne        $3, $2, .L002ACE8C
    /* 1AC800 002AC800 00000000 */   nop
    /* 1AC804 002AC804 A054050C */  jal        func_00155280
    /* 1AC808 002AC808 00000000 */   nop
    /* 1AC80C 002AC80C 21105100 */  addu       $2, $2, $17
    /* 1AC810 002AC810 21105000 */  addu       $2, $2, $16
    /* 1AC814 002AC814 55004290 */  lbu        $2, 0x55($2)
    /* 1AC818 002AC818 0F004330 */  andi       $3, $2, 0xF
    /* 1AC81C 002AC81C 01000224 */  addiu      $2, $0, 0x1
    /* 1AC820 002AC820 E3006214 */  bne        $3, $2, .L002ACBB0
    /* 1AC824 002AC824 00000000 */   nop
    /* 1AC828 002AC828 FF009432 */  andi       $20, $20, 0xFF
    /* 1AC82C 002AC82C 04108202 */  sllv       $2, $2, $20
    /* 1AC830 002AC830 FFFF5530 */  andi       $21, $2, 0xFFFF
    /* 1AC834 002AC834 40901200 */  sll        $18, $18, 1
    /* 1AC838 002AC838 68B5828F */  lw         $2, -0x4A98($28)
    /* 1AC83C 002AC83C 21185200 */  addu       $3, $2, $18
    /* 1AC840 002AC840 00006294 */  lhu        $2, 0x0($3)
    /* 1AC844 002AC844 25105500 */  or         $2, $2, $21
    /* 1AC848 002AC848 000062A4 */  sh         $2, 0x0($3)
    /* 1AC84C 002AC84C FF007332 */  andi       $19, $19, 0xFF
    /* 1AC850 002AC850 00B21300 */  sll        $22, $19, 8
    /* 1AC854 002AC854 A054050C */  jal        func_00155280
    /* 1AC858 002AC858 00000000 */   nop
    /* 1AC85C 002AC85C 21105600 */  addu       $2, $2, $22
    /* 1AC860 002AC860 21105000 */  addu       $2, $2, $16
    /* 1AC864 002AC864 58FF4390 */  lbu        $3, -0xA8($2)
    /* 1AC868 002AC868 02000224 */  addiu      $2, $0, 0x2
    /* 1AC86C 002AC86C 2D006214 */  bne        $3, $2, .L002AC924
    /* 1AC870 002AC870 00000000 */   nop
    /* 1AC874 002AC874 A054050C */  jal        func_00155280
    /* 1AC878 002AC878 00000000 */   nop
    /* 1AC87C 002AC87C 21105100 */  addu       $2, $2, $17
    /* 1AC880 002AC880 21105000 */  addu       $2, $2, $16
    /* 1AC884 002AC884 5E004290 */  lbu        $2, 0x5E($2)
    /* 1AC888 002AC888 01004230 */  andi       $2, $2, 0x1
    /* 1AC88C 002AC88C 25004010 */  beqz       $2, .L002AC924
    /* 1AC890 002AC890 00000000 */   nop
    /* 1AC894 002AC894 A054050C */  jal        func_00155280
    /* 1AC898 002AC898 00000000 */   nop
    /* 1AC89C 002AC89C 21105100 */  addu       $2, $2, $17
    /* 1AC8A0 002AC8A0 21105000 */  addu       $2, $2, $16
    /* 1AC8A4 002AC8A4 5F004290 */  lbu        $2, 0x5F($2)
    /* 1AC8A8 002AC8A8 01004230 */  andi       $2, $2, 0x1
    /* 1AC8AC 002AC8AC 14004010 */  beqz       $2, .L002AC900
    /* 1AC8B0 002AC8B0 00000000 */   nop
    /* 1AC8B4 002AC8B4 A054050C */  jal        func_00155280
    /* 1AC8B8 002AC8B8 00000000 */   nop
    /* 1AC8BC 002AC8BC 21105100 */  addu       $2, $2, $17
    /* 1AC8C0 002AC8C0 21105000 */  addu       $2, $2, $16
    /* 1AC8C4 002AC8C4 5F004290 */  lbu        $2, 0x5F($2)
    /* 1AC8C8 002AC8C8 10004230 */  andi       $2, $2, 0x10
    /* 1AC8CC 002AC8CC 15004010 */  beqz       $2, .L002AC924
    /* 1AC8D0 002AC8D0 00000000 */   nop
    /* 1AC8D4 002AC8D4 FFFF6226 */  addiu      $2, $19, -0x1
    /* 1AC8D8 002AC8D8 FF004230 */  andi       $2, $2, 0xFF
    /* 1AC8DC 002AC8DC 40180200 */  sll        $3, $2, 1
    /* 1AC8E0 002AC8E0 68B5828F */  lw         $2, -0x4A98($28)
    /* 1AC8E4 002AC8E4 21204300 */  addu       $4, $2, $3
    /* 1AC8E8 002AC8E8 FFFFA332 */  andi       $3, $21, 0xFFFF
    /* 1AC8EC 002AC8EC 00008294 */  lhu        $2, 0x0($4)
    /* 1AC8F0 002AC8F0 25104300 */  or         $2, $2, $3
    /* 1AC8F4 002AC8F4 000082A4 */  sh         $2, 0x0($4)
    /* 1AC8F8 002AC8F8 0A000010 */  b          .L002AC924
    /* 1AC8FC 002AC8FC 00000000 */   nop
  .L002AC900:
    /* 1AC900 002AC900 FFFF6226 */  addiu      $2, $19, -0x1
    /* 1AC904 002AC904 FF004230 */  andi       $2, $2, 0xFF
    /* 1AC908 002AC908 40180200 */  sll        $3, $2, 1
    /* 1AC90C 002AC90C 68B5828F */  lw         $2, -0x4A98($28)
    /* 1AC910 002AC910 21204300 */  addu       $4, $2, $3
    /* 1AC914 002AC914 FFFFA332 */  andi       $3, $21, 0xFFFF
    /* 1AC918 002AC918 00008294 */  lhu        $2, 0x0($4)
    /* 1AC91C 002AC91C 25104300 */  or         $2, $2, $3
    /* 1AC920 002AC920 000082A4 */  sh         $2, 0x0($4)
  .L002AC924:
    /* 1AC924 002AC924 A054050C */  jal        func_00155280
    /* 1AC928 002AC928 00000000 */   nop
    /* 1AC92C 002AC92C 21105600 */  addu       $2, $2, $22
    /* 1AC930 002AC930 21105000 */  addu       $2, $2, $16
    /* 1AC934 002AC934 58014390 */  lbu        $3, 0x158($2)
    /* 1AC938 002AC938 02000224 */  addiu      $2, $0, 0x2
    /* 1AC93C 002AC93C 2D006214 */  bne        $3, $2, .L002AC9F4
    /* 1AC940 002AC940 00000000 */   nop
    /* 1AC944 002AC944 A054050C */  jal        func_00155280
    /* 1AC948 002AC948 00000000 */   nop
    /* 1AC94C 002AC94C 21105100 */  addu       $2, $2, $17
    /* 1AC950 002AC950 21105000 */  addu       $2, $2, $16
    /* 1AC954 002AC954 5E004290 */  lbu        $2, 0x5E($2)
    /* 1AC958 002AC958 04004230 */  andi       $2, $2, 0x4
    /* 1AC95C 002AC95C 25004010 */  beqz       $2, .L002AC9F4
    /* 1AC960 002AC960 00000000 */   nop
    /* 1AC964 002AC964 A054050C */  jal        func_00155280
    /* 1AC968 002AC968 00000000 */   nop
    /* 1AC96C 002AC96C 21105100 */  addu       $2, $2, $17
    /* 1AC970 002AC970 21105000 */  addu       $2, $2, $16
    /* 1AC974 002AC974 5F004290 */  lbu        $2, 0x5F($2)
    /* 1AC978 002AC978 04004230 */  andi       $2, $2, 0x4
    /* 1AC97C 002AC97C 14004010 */  beqz       $2, .L002AC9D0
    /* 1AC980 002AC980 00000000 */   nop
    /* 1AC984 002AC984 A054050C */  jal        func_00155280
    /* 1AC988 002AC988 00000000 */   nop
    /* 1AC98C 002AC98C 21105100 */  addu       $2, $2, $17
    /* 1AC990 002AC990 21105000 */  addu       $2, $2, $16
    /* 1AC994 002AC994 5F004290 */  lbu        $2, 0x5F($2)
    /* 1AC998 002AC998 40004230 */  andi       $2, $2, 0x40
    /* 1AC99C 002AC99C 15004010 */  beqz       $2, .L002AC9F4
    /* 1AC9A0 002AC9A0 00000000 */   nop
    /* 1AC9A4 002AC9A4 01006226 */  addiu      $2, $19, 0x1
    /* 1AC9A8 002AC9A8 FF004230 */  andi       $2, $2, 0xFF
    /* 1AC9AC 002AC9AC 40180200 */  sll        $3, $2, 1
    /* 1AC9B0 002AC9B0 68B5828F */  lw         $2, -0x4A98($28)
    /* 1AC9B4 002AC9B4 21204300 */  addu       $4, $2, $3
    /* 1AC9B8 002AC9B8 FFFFA332 */  andi       $3, $21, 0xFFFF
    /* 1AC9BC 002AC9BC 00008294 */  lhu        $2, 0x0($4)
    /* 1AC9C0 002AC9C0 25104300 */  or         $2, $2, $3
    /* 1AC9C4 002AC9C4 000082A4 */  sh         $2, 0x0($4)
    /* 1AC9C8 002AC9C8 0A000010 */  b          .L002AC9F4
    /* 1AC9CC 002AC9CC 00000000 */   nop
  .L002AC9D0:
    /* 1AC9D0 002AC9D0 01006226 */  addiu      $2, $19, 0x1
    /* 1AC9D4 002AC9D4 FF004230 */  andi       $2, $2, 0xFF
    /* 1AC9D8 002AC9D8 40180200 */  sll        $3, $2, 1
    /* 1AC9DC 002AC9DC 68B5828F */  lw         $2, -0x4A98($28)
    /* 1AC9E0 002AC9E0 21204300 */  addu       $4, $2, $3
    /* 1AC9E4 002AC9E4 FFFFA332 */  andi       $3, $21, 0xFFFF
    /* 1AC9E8 002AC9E8 00008294 */  lhu        $2, 0x0($4)
    /* 1AC9EC 002AC9EC 25104300 */  or         $2, $2, $3
    /* 1AC9F0 002AC9F0 000082A4 */  sh         $2, 0x0($4)
  .L002AC9F4:
    /* 1AC9F4 002AC9F4 00991400 */  sll        $19, $20, 4
    /* 1AC9F8 002AC9F8 A054050C */  jal        func_00155280
    /* 1AC9FC 002AC9FC 00000000 */   nop
    /* 1ACA00 002ACA00 21105100 */  addu       $2, $2, $17
    /* 1ACA04 002ACA04 21105300 */  addu       $2, $2, $19
    /* 1ACA08 002ACA08 68004390 */  lbu        $3, 0x68($2)
    /* 1ACA0C 002ACA0C 02000224 */  addiu      $2, $0, 0x2
    /* 1ACA10 002ACA10 2F006214 */  bne        $3, $2, .L002ACAD0
    /* 1ACA14 002ACA14 00000000 */   nop
    /* 1ACA18 002ACA18 A054050C */  jal        func_00155280
    /* 1ACA1C 002ACA1C 00000000 */   nop
    /* 1ACA20 002ACA20 21105100 */  addu       $2, $2, $17
    /* 1ACA24 002ACA24 21105000 */  addu       $2, $2, $16
    /* 1ACA28 002ACA28 5E004290 */  lbu        $2, 0x5E($2)
    /* 1ACA2C 002ACA2C 08004230 */  andi       $2, $2, 0x8
    /* 1ACA30 002ACA30 27004010 */  beqz       $2, .L002ACAD0
    /* 1ACA34 002ACA34 00000000 */   nop
    /* 1ACA38 002ACA38 A054050C */  jal        func_00155280
    /* 1ACA3C 002ACA3C 00000000 */   nop
    /* 1ACA40 002ACA40 21105100 */  addu       $2, $2, $17
    /* 1ACA44 002ACA44 21105000 */  addu       $2, $2, $16
    /* 1ACA48 002ACA48 5F004290 */  lbu        $2, 0x5F($2)
    /* 1ACA4C 002ACA4C 08004230 */  andi       $2, $2, 0x8
    /* 1ACA50 002ACA50 15004010 */  beqz       $2, .L002ACAA8
    /* 1ACA54 002ACA54 00000000 */   nop
    /* 1ACA58 002ACA58 A054050C */  jal        func_00155280
    /* 1ACA5C 002ACA5C 00000000 */   nop
    /* 1ACA60 002ACA60 21105100 */  addu       $2, $2, $17
    /* 1ACA64 002ACA64 21105000 */  addu       $2, $2, $16
    /* 1ACA68 002ACA68 5F004290 */  lbu        $2, 0x5F($2)
    /* 1ACA6C 002ACA6C 80004230 */  andi       $2, $2, 0x80
    /* 1ACA70 002ACA70 17004010 */  beqz       $2, .L002ACAD0
    /* 1ACA74 002ACA74 00000000 */   nop
    /* 1ACA78 002ACA78 01008226 */  addiu      $2, $20, 0x1
    /* 1ACA7C 002ACA7C FF004330 */  andi       $3, $2, 0xFF
    /* 1ACA80 002ACA80 01000224 */  addiu      $2, $0, 0x1
    /* 1ACA84 002ACA84 04106200 */  sllv       $2, $2, $3
    /* 1ACA88 002ACA88 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* 1ACA8C 002ACA8C 68B5828F */  lw         $2, -0x4A98($28)
    /* 1ACA90 002ACA90 21185200 */  addu       $3, $2, $18
    /* 1ACA94 002ACA94 00006294 */  lhu        $2, 0x0($3)
    /* 1ACA98 002ACA98 25104400 */  or         $2, $2, $4
    /* 1ACA9C 002ACA9C 000062A4 */  sh         $2, 0x0($3)
    /* 1ACAA0 002ACAA0 0B000010 */  b          .L002ACAD0
    /* 1ACAA4 002ACAA4 00000000 */   nop
  .L002ACAA8:
    /* 1ACAA8 002ACAA8 01008226 */  addiu      $2, $20, 0x1
    /* 1ACAAC 002ACAAC FF004330 */  andi       $3, $2, 0xFF
    /* 1ACAB0 002ACAB0 01000224 */  addiu      $2, $0, 0x1
    /* 1ACAB4 002ACAB4 04106200 */  sllv       $2, $2, $3
    /* 1ACAB8 002ACAB8 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* 1ACABC 002ACABC 68B5828F */  lw         $2, -0x4A98($28)
    /* 1ACAC0 002ACAC0 21185200 */  addu       $3, $2, $18
    /* 1ACAC4 002ACAC4 00006294 */  lhu        $2, 0x0($3)
    /* 1ACAC8 002ACAC8 25104400 */  or         $2, $2, $4
    /* 1ACACC 002ACACC 000062A4 */  sh         $2, 0x0($3)
  .L002ACAD0:
    /* 1ACAD0 002ACAD0 A054050C */  jal        func_00155280
    /* 1ACAD4 002ACAD4 00000000 */   nop
    /* 1ACAD8 002ACAD8 21185100 */  addu       $3, $2, $17
    /* 1ACADC 002ACADC 21187300 */  addu       $3, $3, $19
    /* 1ACAE0 002ACAE0 48006490 */  lbu        $4, 0x48($3)
    /* 1ACAE4 002ACAE4 02000324 */  addiu      $3, $0, 0x2
    /* 1ACAE8 002ACAE8 71048314 */  bne        $4, $3, .L002ADCB0
    /* 1ACAEC 002ACAEC 00000000 */   nop
    /* 1ACAF0 002ACAF0 A054050C */  jal        func_00155280
    /* 1ACAF4 002ACAF4 00000000 */   nop
    /* 1ACAF8 002ACAF8 21185100 */  addu       $3, $2, $17
    /* 1ACAFC 002ACAFC 21187000 */  addu       $3, $3, $16
    /* 1ACB00 002ACB00 5E006390 */  lbu        $3, 0x5E($3)
    /* 1ACB04 002ACB04 02006330 */  andi       $3, $3, 0x2
    /* 1ACB08 002ACB08 69046010 */  beqz       $3, .L002ADCB0
    /* 1ACB0C 002ACB0C 00000000 */   nop
    /* 1ACB10 002ACB10 A054050C */  jal        func_00155280
    /* 1ACB14 002ACB14 00000000 */   nop
    /* 1ACB18 002ACB18 21185100 */  addu       $3, $2, $17
    /* 1ACB1C 002ACB1C 21187000 */  addu       $3, $3, $16
    /* 1ACB20 002ACB20 5F006390 */  lbu        $3, 0x5F($3)
    /* 1ACB24 002ACB24 02006330 */  andi       $3, $3, 0x2
    /* 1ACB28 002ACB28 15006010 */  beqz       $3, .L002ACB80
    /* 1ACB2C 002ACB2C 00000000 */   nop
    /* 1ACB30 002ACB30 A054050C */  jal        func_00155280
    /* 1ACB34 002ACB34 00000000 */   nop
    /* 1ACB38 002ACB38 21185100 */  addu       $3, $2, $17
    /* 1ACB3C 002ACB3C 21187000 */  addu       $3, $3, $16
    /* 1ACB40 002ACB40 5F006390 */  lbu        $3, 0x5F($3)
    /* 1ACB44 002ACB44 20006330 */  andi       $3, $3, 0x20
    /* 1ACB48 002ACB48 59046010 */  beqz       $3, .L002ADCB0
    /* 1ACB4C 002ACB4C 00000000 */   nop
    /* 1ACB50 002ACB50 FFFF8326 */  addiu      $3, $20, -0x1
    /* 1ACB54 002ACB54 FF006430 */  andi       $4, $3, 0xFF
    /* 1ACB58 002ACB58 01000324 */  addiu      $3, $0, 0x1
    /* 1ACB5C 002ACB5C 04188300 */  sllv       $3, $3, $4
    /* 1ACB60 002ACB60 FFFF6530 */  andi       $5, $3, 0xFFFF
    /* 1ACB64 002ACB64 68B5838F */  lw         $3, -0x4A98($28)
    /* 1ACB68 002ACB68 21207200 */  addu       $4, $3, $18
    /* 1ACB6C 002ACB6C 00008394 */  lhu        $3, 0x0($4)
    /* 1ACB70 002ACB70 25186500 */  or         $3, $3, $5
    /* 1ACB74 002ACB74 000083A4 */  sh         $3, 0x0($4)
    /* 1ACB78 002ACB78 4D040010 */  b          .L002ADCB0
    /* 1ACB7C 002ACB7C 00000000 */   nop
  .L002ACB80:
    /* 1ACB80 002ACB80 FFFF8326 */  addiu      $3, $20, -0x1
    /* 1ACB84 002ACB84 FF006430 */  andi       $4, $3, 0xFF
    /* 1ACB88 002ACB88 01000324 */  addiu      $3, $0, 0x1
    /* 1ACB8C 002ACB8C 04188300 */  sllv       $3, $3, $4
    /* 1ACB90 002ACB90 FFFF6530 */  andi       $5, $3, 0xFFFF
    /* 1ACB94 002ACB94 68B5838F */  lw         $3, -0x4A98($28)
    /* 1ACB98 002ACB98 21207200 */  addu       $4, $3, $18
    /* 1ACB9C 002ACB9C 00008394 */  lhu        $3, 0x0($4)
    /* 1ACBA0 002ACBA0 25186500 */  or         $3, $3, $5
    /* 1ACBA4 002ACBA4 000083A4 */  sh         $3, 0x0($4)
    /* 1ACBA8 002ACBA8 41040010 */  b          .L002ADCB0
    /* 1ACBAC 002ACBAC 00000000 */   nop
  .L002ACBB0:
    /* 1ACBB0 002ACBB0 2D900000 */  daddu      $18, $0, $0
    /* 1ACBB4 002ACBB4 FF006232 */  andi       $2, $19, 0xFF
    /* 1ACBB8 002ACBB8 6001A2AF */  sw         $2, 0x160($29)
    /* 1ACBBC 002ACBBC FF008232 */  andi       $2, $20, 0xFF
    /* 1ACBC0 002ACBC0 5001A2AF */  sw         $2, 0x150($29)
    /* 1ACBC4 002ACBC4 21B83002 */  addu       $23, $17, $16
    /* 1ACBC8 002ACBC8 47000010 */  b          .L002ACCE8
    /* 1ACBCC 002ACBCC 00000000 */   nop
  .L002ACBD0:
    /* 1ACBD0 002ACBD0 6001A48F */  lw         $4, 0x160($29)
    /* 1ACBD4 002ACBD4 01000624 */  addiu      $6, $0, 0x1
    /* 1ACBD8 002ACBD8 18000724 */  addiu      $7, $0, 0x18
    /* 1ACBDC 002ACBDC 2D40C000 */  daddu      $8, $6, $0
    /* 1ACBE0 002ACBE0 40CB0A0C */  jal        func_002b2d00
    /* 1ACBE4 002ACBE4 00000000 */   nop
    /* 1ACBE8 002ACBE8 3C160200 */  dsll32     $2, $2, 24
    /* 1ACBEC 002ACBEC 3F160200 */  dsra32     $2, $2, 24
    /* 1ACBF0 002ACBF0 4001A27F */  sq         $2, 0x140($29)
    /* 1ACBF4 002ACBF4 2DB00000 */  daddu      $22, $0, $0
    /* 1ACBF8 002ACBF8 00120200 */  sll        $2, $2, 8
    /* 1ACBFC 002ACBFC 3001A27F */  sq         $2, 0x130($29)
    /* 1ACC00 002ACC00 31000010 */  b          .L002ACCC8
    /* 1ACC04 002ACC04 00000000 */   nop
  .L002ACC08:
    /* 1ACC08 002ACC08 5001A48F */  lw         $4, 0x150($29)
    /* 1ACC0C 002ACC0C 01000624 */  addiu      $6, $0, 0x1
    /* 1ACC10 002ACC10 10000724 */  addiu      $7, $0, 0x10
    /* 1ACC14 002ACC14 2D40C000 */  daddu      $8, $6, $0
    /* 1ACC18 002ACC18 40CB0A0C */  jal        func_002b2d00
    /* 1ACC1C 002ACC1C 00000000 */   nop
    /* 1ACC20 002ACC20 3C160200 */  dsll32     $2, $2, 24
    /* 1ACC24 002ACC24 3F160200 */  dsra32     $2, $2, 24
    /* 1ACC28 002ACC28 2001A27F */  sq         $2, 0x120($29)
    /* 1ACC2C 002ACC2C 00110200 */  sll        $2, $2, 4
    /* 1ACC30 002ACC30 1001A27F */  sq         $2, 0x110($29)
    /* 1ACC34 002ACC34 A054050C */  jal        func_00155280
    /* 1ACC38 002ACC38 00000000 */   nop
    /* 1ACC3C 002ACC3C 3001A37B */  lq         $3, 0x130($29)
    /* 1ACC40 002ACC40 21186200 */  addu       $3, $3, $2
    /* 1ACC44 002ACC44 1001A27B */  lq         $2, 0x110($29)
    /* 1ACC48 002ACC48 21106200 */  addu       $2, $3, $2
    /* 1ACC4C 002ACC4C 55004290 */  lbu        $2, 0x55($2)
    /* 1ACC50 002ACC50 0F004330 */  andi       $3, $2, 0xF
    /* 1ACC54 002ACC54 01000224 */  addiu      $2, $0, 0x1
    /* 1ACC58 002ACC58 18006214 */  bne        $3, $2, .L002ACCBC
    /* 1ACC5C 002ACC5C 00000000 */   nop
    /* 1ACC60 002ACC60 A054050C */  jal        func_00155280
    /* 1ACC64 002ACC64 00000000 */   nop
    /* 1ACC68 002ACC68 3001A37B */  lq         $3, 0x130($29)
    /* 1ACC6C 002ACC6C 21186200 */  addu       $3, $3, $2
    /* 1ACC70 002ACC70 1001A27B */  lq         $2, 0x110($29)
    /* 1ACC74 002ACC74 21106200 */  addu       $2, $3, $2
    /* 1ACC78 002ACC78 58004290 */  lbu        $2, 0x58($2)
    /* 1ACC7C 002ACC7C 0001A27F */  sq         $2, 0x100($29)
    /* 1ACC80 002ACC80 A054050C */  jal        func_00155280
    /* 1ACC84 002ACC84 00000000 */   nop
    /* 1ACC88 002ACC88 2110E202 */  addu       $2, $23, $2
    /* 1ACC8C 002ACC8C 58004390 */  lbu        $3, 0x58($2)
    /* 1ACC90 002ACC90 0001A27B */  lq         $2, 0x100($29)
    /* 1ACC94 002ACC94 09004314 */  bne        $2, $3, .L002ACCBC
    /* 1ACC98 002ACC98 00000000 */   nop
    /* 1ACC9C 002ACC9C 2001A27B */  lq         $2, 0x120($29)
    /* 1ACCA0 002ACCA0 3CF60200 */  dsll32     $30, $2, 24
    /* 1ACCA4 002ACCA4 3FF61E00 */  dsra32     $30, $30, 24
    /* 1ACCA8 002ACCA8 4001A27B */  lq         $2, 0x140($29)
    /* 1ACCAC 002ACCAC 3CAE0200 */  dsll32     $21, $2, 24
    /* 1ACCB0 002ACCB0 3FAE1500 */  dsra32     $21, $21, 24
    /* 1ACCB4 002ACCB4 09000010 */  b          .L002ACCDC
    /* 1ACCB8 002ACCB8 00000000 */   nop
  .L002ACCBC:
    /* 1ACCBC 002ACCBC 0100C226 */  addiu      $2, $22, 0x1
    /* 1ACCC0 002ACCC0 3CB40200 */  dsll32     $22, $2, 16
    /* 1ACCC4 002ACCC4 3FB41600 */  dsra32     $22, $22, 16
  .L002ACCC8:
    /* 1ACCC8 002ACCC8 3C2C1600 */  dsll32     $5, $22, 16
    /* 1ACCCC 002ACCCC 3F2C0500 */  dsra32     $5, $5, 16
    /* 1ACCD0 002ACCD0 0200A228 */  slti       $2, $5, 0x2
    /* 1ACCD4 002ACCD4 CCFF4014 */  bnez       $2, .L002ACC08
    /* 1ACCD8 002ACCD8 00000000 */   nop
  .L002ACCDC:
    /* 1ACCDC 002ACCDC 01004226 */  addiu      $2, $18, 0x1
    /* 1ACCE0 002ACCE0 3C940200 */  dsll32     $18, $2, 16
    /* 1ACCE4 002ACCE4 3F941200 */  dsra32     $18, $18, 16
  .L002ACCE8:
    /* 1ACCE8 002ACCE8 3C2C1200 */  dsll32     $5, $18, 16
    /* 1ACCEC 002ACCEC 3F2C0500 */  dsra32     $5, $5, 16
    /* 1ACCF0 002ACCF0 0200A228 */  slti       $2, $5, 0x2
    /* 1ACCF4 002ACCF4 B6FF4014 */  bnez       $2, .L002ACBD0
    /* 1ACCF8 002ACCF8 00000000 */   nop
    /* 1ACCFC 002ACCFC A054050C */  jal        func_00155280
    /* 1ACD00 002ACD00 00000000 */   nop
    /* 1ACD04 002ACD04 21185100 */  addu       $3, $2, $17
    /* 1ACD08 002ACD08 21187000 */  addu       $3, $3, $16
    /* 1ACD0C 002ACD0C 59006490 */  lbu        $4, 0x59($3)
    /* 1ACD10 002ACD10 03000324 */  addiu      $3, $0, 0x3
    /* 1ACD14 002ACD14 36008310 */  beq        $4, $3, .L002ACDF0
    /* 1ACD18 002ACD18 00000000 */   nop
    /* 1ACD1C 002ACD1C 01000324 */  addiu      $3, $0, 0x1
    /* 1ACD20 002ACD20 33008310 */  beq        $4, $3, .L002ACDF0
    /* 1ACD24 002ACD24 00000000 */   nop
    /* 1ACD28 002ACD28 02000324 */  addiu      $3, $0, 0x2
    /* 1ACD2C 002ACD2C 05008310 */  beq        $4, $3, .L002ACD44
    /* 1ACD30 002ACD30 00000000 */   nop
    /* 1ACD34 002ACD34 03008010 */  beqz       $4, .L002ACD44
    /* 1ACD38 002ACD38 00000000 */   nop
    /* 1ACD3C 002ACD3C DC030010 */  b          .L002ADCB0
    /* 1ACD40 002ACD40 00000000 */   nop
  .L002ACD44:
    /* 1ACD44 002ACD44 2D880000 */  daddu      $17, $0, $0
    /* 1ACD48 002ACD48 FF008332 */  andi       $3, $20, 0xFF
    /* 1ACD4C 002ACD4C 00B10300 */  sll        $22, $3, 4
    /* 1ACD50 002ACD50 3C861500 */  dsll32     $16, $21, 24
    /* 1ACD54 002ACD54 3F861000 */  dsra32     $16, $16, 24
    /* 1ACD58 002ACD58 01000424 */  addiu      $4, $0, 0x1
    /* 1ACD5C 002ACD5C 5001A38F */  lw         $3, 0x150($29)
    /* 1ACD60 002ACD60 04186400 */  sllv       $3, $4, $3
    /* 1ACD64 002ACD64 FFFF7430 */  andi       $20, $3, 0xFFFF
    /* 1ACD68 002ACD68 40981000 */  sll        $19, $16, 1
    /* 1ACD6C 002ACD6C 19000010 */  b          .L002ACDD4
    /* 1ACD70 002ACD70 00000000 */   nop
  .L002ACD74:
    /* 1ACD74 002ACD74 A054050C */  jal        func_00155280
    /* 1ACD78 002ACD78 00000000 */   nop
    /* 1ACD7C 002ACD7C 2118C202 */  addu       $3, $22, $2
    /* 1ACD80 002ACD80 21101202 */  addu       $2, $16, $18
    /* 1ACD84 002ACD84 00120200 */  sll        $2, $2, 8
    /* 1ACD88 002ACD88 21106200 */  addu       $2, $3, $2
    /* 1ACD8C 002ACD8C 58005590 */  lbu        $21, 0x58($2)
    /* 1ACD90 002ACD90 A054050C */  jal        func_00155280
    /* 1ACD94 002ACD94 00000000 */   nop
    /* 1ACD98 002ACD98 2118E202 */  addu       $3, $23, $2
    /* 1ACD9C 002ACD9C 58006390 */  lbu        $3, 0x58($3)
    /* 1ACDA0 002ACDA0 0900A316 */  bne        $21, $3, .L002ACDC8
    /* 1ACDA4 002ACDA4 00000000 */   nop
    /* 1ACDA8 002ACDA8 68B5838F */  lw         $3, -0x4A98($28)
    /* 1ACDAC 002ACDAC 21206302 */  addu       $4, $19, $3
    /* 1ACDB0 002ACDB0 40181200 */  sll        $3, $18, 1
    /* 1ACDB4 002ACDB4 21288300 */  addu       $5, $4, $3
    /* 1ACDB8 002ACDB8 FFFF8432 */  andi       $4, $20, 0xFFFF
    /* 1ACDBC 002ACDBC 0000A394 */  lhu        $3, 0x0($5)
    /* 1ACDC0 002ACDC0 25186400 */  or         $3, $3, $4
    /* 1ACDC4 002ACDC4 0000A3A4 */  sh         $3, 0x0($5)
  .L002ACDC8:
    /* 1ACDC8 002ACDC8 01002326 */  addiu      $3, $17, 0x1
    /* 1ACDCC 002ACDCC 3C8C0300 */  dsll32     $17, $3, 16
    /* 1ACDD0 002ACDD0 3F8C1100 */  dsra32     $17, $17, 16
  .L002ACDD4:
    /* 1ACDD4 002ACDD4 3C941100 */  dsll32     $18, $17, 16
    /* 1ACDD8 002ACDD8 3F941200 */  dsra32     $18, $18, 16
    /* 1ACDDC 002ACDDC 0200432A */  slti       $3, $18, 0x2
    /* 1ACDE0 002ACDE0 E4FF6014 */  bnez       $3, .L002ACD74
    /* 1ACDE4 002ACDE4 00000000 */   nop
    /* 1ACDE8 002ACDE8 B1030010 */  b          .L002ADCB0
    /* 1ACDEC 002ACDEC 00000000 */   nop
  .L002ACDF0:
    /* 1ACDF0 002ACDF0 2D800000 */  daddu      $16, $0, $0
    /* 1ACDF4 002ACDF4 FF006332 */  andi       $3, $19, 0xFF
    /* 1ACDF8 002ACDF8 00AA0300 */  sll        $21, $3, 8
    /* 1ACDFC 002ACDFC 3C9E1E00 */  dsll32     $19, $30, 24
    /* 1ACE00 002ACE00 3F9E1300 */  dsra32     $19, $19, 24
    /* 1ACE04 002ACE04 40900300 */  sll        $18, $3, 1
    /* 1ACE08 002ACE08 19000010 */  b          .L002ACE70
    /* 1ACE0C 002ACE0C 00000000 */   nop
  .L002ACE10:
    /* 1ACE10 002ACE10 21886402 */  addu       $17, $19, $4
    /* 1ACE14 002ACE14 A054050C */  jal        func_00155280
    /* 1ACE18 002ACE18 00000000 */   nop
    /* 1ACE1C 002ACE1C 2118A202 */  addu       $3, $21, $2
    /* 1ACE20 002ACE20 00111100 */  sll        $2, $17, 4
    /* 1ACE24 002ACE24 21106200 */  addu       $2, $3, $2
    /* 1ACE28 002ACE28 58005490 */  lbu        $20, 0x58($2)
    /* 1ACE2C 002ACE2C A054050C */  jal        func_00155280
    /* 1ACE30 002ACE30 00000000 */   nop
    /* 1ACE34 002ACE34 2118E202 */  addu       $3, $23, $2
    /* 1ACE38 002ACE38 58006390 */  lbu        $3, 0x58($3)
    /* 1ACE3C 002ACE3C 09008316 */  bne        $20, $3, .L002ACE64
    /* 1ACE40 002ACE40 00000000 */   nop
    /* 1ACE44 002ACE44 01000324 */  addiu      $3, $0, 0x1
    /* 1ACE48 002ACE48 04182302 */  sllv       $3, $3, $17
    /* 1ACE4C 002ACE4C FFFF6530 */  andi       $5, $3, 0xFFFF
    /* 1ACE50 002ACE50 68B5838F */  lw         $3, -0x4A98($28)
    /* 1ACE54 002ACE54 21204302 */  addu       $4, $18, $3
    /* 1ACE58 002ACE58 00008394 */  lhu        $3, 0x0($4)
    /* 1ACE5C 002ACE5C 25186500 */  or         $3, $3, $5
    /* 1ACE60 002ACE60 000083A4 */  sh         $3, 0x0($4)
  .L002ACE64:
    /* 1ACE64 002ACE64 01000326 */  addiu      $3, $16, 0x1
    /* 1ACE68 002ACE68 3C840300 */  dsll32     $16, $3, 16
    /* 1ACE6C 002ACE6C 3F841000 */  dsra32     $16, $16, 16
  .L002ACE70:
    /* 1ACE70 002ACE70 3C241000 */  dsll32     $4, $16, 16
    /* 1ACE74 002ACE74 3F240400 */  dsra32     $4, $4, 16
    /* 1ACE78 002ACE78 02008328 */  slti       $3, $4, 0x2
    /* 1ACE7C 002ACE7C E4FF6014 */  bnez       $3, .L002ACE10
    /* 1ACE80 002ACE80 00000000 */   nop
    /* 1ACE84 002ACE84 8A030010 */  b          .L002ADCB0
    /* 1ACE88 002ACE88 00000000 */   nop
  .L002ACE8C:
    /* 1ACE8C 002ACE8C A054050C */  jal        func_00155280
    /* 1ACE90 002ACE90 00000000 */   nop
    /* 1ACE94 002ACE94 21105100 */  addu       $2, $2, $17
    /* 1ACE98 002ACE98 21105000 */  addu       $2, $2, $16
    /* 1ACE9C 002ACE9C 55004490 */  lbu        $4, 0x55($2)
    /* 1ACEA0 002ACEA0 3CB70A0C */  jal        func_002adcf0
    /* 1ACEA4 002ACEA4 00000000 */   nop
    /* 1ACEA8 002ACEA8 3C260200 */  dsll32     $4, $2, 24
    /* 1ACEAC 002ACEAC 3F260400 */  dsra32     $4, $4, 24
    /* 1ACEB0 002ACEB0 02000324 */  addiu      $3, $0, 0x2
    /* 1ACEB4 002ACEB4 7E038314 */  bne        $4, $3, .L002ADCB0
    /* 1ACEB8 002ACEB8 00000000 */   nop
    /* 1ACEBC 002ACEBC FF008432 */  andi       $4, $20, 0xFF
    /* 1ACEC0 002ACEC0 01000324 */  addiu      $3, $0, 0x1
    /* 1ACEC4 002ACEC4 04188300 */  sllv       $3, $3, $4
    /* 1ACEC8 002ACEC8 FFFF6530 */  andi       $5, $3, 0xFFFF
    /* 1ACECC 002ACECC 40201200 */  sll        $4, $18, 1
    /* 1ACED0 002ACED0 68B5838F */  lw         $3, -0x4A98($28)
    /* 1ACED4 002ACED4 21206400 */  addu       $4, $3, $4
    /* 1ACED8 002ACED8 00008394 */  lhu        $3, 0x0($4)
    /* 1ACEDC 002ACEDC 25186500 */  or         $3, $3, $5
    /* 1ACEE0 002ACEE0 000083A4 */  sh         $3, 0x0($4)
    /* 1ACEE4 002ACEE4 72030010 */  b          .L002ADCB0
    /* 1ACEE8 002ACEE8 00000000 */   nop
  .L002ACEEC:
    /* 1ACEEC 002ACEEC FF008432 */  andi       $4, $20, 0xFF
    /* 1ACEF0 002ACEF0 01000324 */  addiu      $3, $0, 0x1
    /* 1ACEF4 002ACEF4 04188300 */  sllv       $3, $3, $4
    /* 1ACEF8 002ACEF8 FFFF6530 */  andi       $5, $3, 0xFFFF
    /* 1ACEFC 002ACEFC 40201200 */  sll        $4, $18, 1
    /* 1ACF00 002ACF00 68B5838F */  lw         $3, -0x4A98($28)
    /* 1ACF04 002ACF04 21206400 */  addu       $4, $3, $4
    /* 1ACF08 002ACF08 00008394 */  lhu        $3, 0x0($4)
    /* 1ACF0C 002ACF0C 25186500 */  or         $3, $3, $5
    /* 1ACF10 002ACF10 000083A4 */  sh         $3, 0x0($4)
    /* 1ACF14 002ACF14 66030010 */  b          .L002ADCB0
    /* 1ACF18 002ACF18 00000000 */   nop
  .L002ACF1C:
    /* 1ACF1C 002ACF1C A054050C */  jal        func_00155280
    /* 1ACF20 002ACF20 00000000 */   nop
    /* 1ACF24 002ACF24 21105100 */  addu       $2, $2, $17
    /* 1ACF28 002ACF28 21105000 */  addu       $2, $2, $16
    /* 1ACF2C 002ACF2C 58004290 */  lbu        $2, 0x58($2)
    /* 1ACF30 002ACF30 09004128 */  slti       $1, $2, 0x9
    /* 1ACF34 002ACF34 D7002010 */  beqz       $1, .L002AD294
    /* 1ACF38 002ACF38 00000000 */   nop
    /* 1ACF3C 002ACF3C FF008432 */  andi       $4, $20, 0xFF
    /* 1ACF40 002ACF40 01000524 */  addiu      $5, $0, 0x1
    /* 1ACF44 002ACF44 04108500 */  sllv       $2, $5, $4
    /* 1ACF48 002ACF48 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* 1ACF4C 002ACF4C 40181200 */  sll        $3, $18, 1
    /* 1ACF50 002ACF50 68B5828F */  lw         $2, -0x4A98($28)
    /* 1ACF54 002ACF54 21184300 */  addu       $3, $2, $3
    /* 1ACF58 002ACF58 00006294 */  lhu        $2, 0x0($3)
    /* 1ACF5C 002ACF5C 25104600 */  or         $2, $2, $6
    /* 1ACF60 002ACF60 000062A4 */  sh         $2, 0x0($3)
    /* 1ACF64 002ACF64 02009E24 */  addiu      $30, $4, 0x2
    /* 1ACF68 002ACF68 2D30A000 */  daddu      $6, $5, $0
    /* 1ACF6C 002ACF6C 2D38C003 */  daddu      $7, $30, $0
    /* 1ACF70 002ACF70 2D40A000 */  daddu      $8, $5, $0
    /* 1ACF74 002ACF74 40CB0A0C */  jal        func_002b2d00
    /* 1ACF78 002ACF78 00000000 */   nop
    /* 1ACF7C 002ACF7C 3CB60200 */  dsll32     $22, $2, 24
    /* 1ACF80 002ACF80 3FB61600 */  dsra32     $22, $22, 24
    /* 1ACF84 002ACF84 00921200 */  sll        $18, $18, 8
    /* 1ACF88 002ACF88 00A91600 */  sll        $21, $22, 4
    /* 1ACF8C 002ACF8C A054050C */  jal        func_00155280
    /* 1ACF90 002ACF90 00000000 */   nop
    /* 1ACF94 002ACF94 21105200 */  addu       $2, $2, $18
    /* 1ACF98 002ACF98 21105500 */  addu       $2, $2, $21
    /* 1ACF9C 002ACF9C 58005790 */  lbu        $23, 0x58($2)
    /* 1ACFA0 002ACFA0 A054050C */  jal        func_00155280
    /* 1ACFA4 002ACFA4 00000000 */   nop
    /* 1ACFA8 002ACFA8 21105200 */  addu       $2, $2, $18
    /* 1ACFAC 002ACFAC 21105000 */  addu       $2, $2, $16
    /* 1ACFB0 002ACFB0 58004290 */  lbu        $2, 0x58($2)
    /* 1ACFB4 002ACFB4 2900E216 */  bne        $23, $2, .L002AD05C
    /* 1ACFB8 002ACFB8 00000000 */   nop
    /* 1ACFBC 002ACFBC A054050C */  jal        func_00155280
    /* 1ACFC0 002ACFC0 00000000 */   nop
    /* 1ACFC4 002ACFC4 21185100 */  addu       $3, $2, $17
    /* 1ACFC8 002ACFC8 21187500 */  addu       $3, $3, $21
    /* 1ACFCC 002ACFCC 55006390 */  lbu        $3, 0x55($3)
    /* 1ACFD0 002ACFD0 0F006330 */  andi       $3, $3, 0xF
    /* 1ACFD4 002ACFD4 01000824 */  addiu      $8, $0, 0x1
    /* 1ACFD8 002ACFD8 20006814 */  bne        $3, $8, .L002AD05C
    /* 1ACFDC 002ACFDC 00000000 */   nop
    /* 1ACFE0 002ACFE0 3C2E1600 */  dsll32     $5, $22, 24
    /* 1ACFE4 002ACFE4 3F2E0500 */  dsra32     $5, $5, 24
    /* 1ACFE8 002ACFE8 0418A800 */  sllv       $3, $8, $5
    /* 1ACFEC 002ACFEC FFFF6730 */  andi       $7, $3, 0xFFFF
    /* 1ACFF0 002ACFF0 FF006332 */  andi       $3, $19, 0xFF
    /* 1ACFF4 002ACFF4 40300300 */  sll        $6, $3, 1
    /* 1ACFF8 002ACFF8 68B5838F */  lw         $3, -0x4A98($28)
    /* 1ACFFC 002ACFFC 21206600 */  addu       $4, $3, $6
    /* 1AD000 002AD000 00008394 */  lhu        $3, 0x0($4)
    /* 1AD004 002AD004 25186700 */  or         $3, $3, $7
    /* 1AD008 002AD008 000083A4 */  sh         $3, 0x0($4)
    /* 1AD00C 002AD00C 0100A324 */  addiu      $3, $5, 0x1
    /* 1AD010 002AD010 04186800 */  sllv       $3, $8, $3
    /* 1AD014 002AD014 FFFF6530 */  andi       $5, $3, 0xFFFF
    /* 1AD018 002AD018 68B5838F */  lw         $3, -0x4A98($28)
    /* 1AD01C 002AD01C 21206600 */  addu       $4, $3, $6
    /* 1AD020 002AD020 00008394 */  lhu        $3, 0x0($4)
    /* 1AD024 002AD024 25186500 */  or         $3, $3, $5
    /* 1AD028 002AD028 000083A4 */  sh         $3, 0x0($4)
    /* 1AD02C 002AD02C 68B5838F */  lw         $3, -0x4A98($28)
    /* 1AD030 002AD030 2120C300 */  addu       $4, $6, $3
    /* 1AD034 002AD034 02008394 */  lhu        $3, 0x2($4)
    /* 1AD038 002AD038 25186700 */  or         $3, $3, $7
    /* 1AD03C 002AD03C 020083A4 */  sh         $3, 0x2($4)
    /* 1AD040 002AD040 68B5838F */  lw         $3, -0x4A98($28)
    /* 1AD044 002AD044 2120C300 */  addu       $4, $6, $3
    /* 1AD048 002AD048 02008394 */  lhu        $3, 0x2($4)
    /* 1AD04C 002AD04C 25186500 */  or         $3, $3, $5
    /* 1AD050 002AD050 020083A4 */  sh         $3, 0x2($4)
    /* 1AD054 002AD054 16030010 */  b          .L002ADCB0
    /* 1AD058 002AD058 00000000 */   nop
  .L002AD05C:
    /* 1AD05C 002AD05C FF006432 */  andi       $4, $19, 0xFF
    /* 1AD060 002AD060 02009724 */  addiu      $23, $4, 0x2
    /* 1AD064 002AD064 01000524 */  addiu      $5, $0, 0x1
    /* 1AD068 002AD068 2D30A000 */  daddu      $6, $5, $0
    /* 1AD06C 002AD06C 2D38E002 */  daddu      $7, $23, $0
    /* 1AD070 002AD070 2D40A000 */  daddu      $8, $5, $0
    /* 1AD074 002AD074 40CB0A0C */  jal        func_002b2d00
    /* 1AD078 002AD078 00000000 */   nop
    /* 1AD07C 002AD07C 3C960200 */  dsll32     $18, $2, 24
    /* 1AD080 002AD080 3F961200 */  dsra32     $18, $18, 24
    /* 1AD084 002AD084 FF008232 */  andi       $2, $20, 0xFF
    /* 1AD088 002AD088 00A90200 */  sll        $21, $2, 4
    /* 1AD08C 002AD08C 00B21200 */  sll        $22, $18, 8
    /* 1AD090 002AD090 A054050C */  jal        func_00155280
    /* 1AD094 002AD094 00000000 */   nop
    /* 1AD098 002AD098 21105600 */  addu       $2, $2, $22
    /* 1AD09C 002AD09C 21105500 */  addu       $2, $2, $21
    /* 1AD0A0 002AD0A0 58004290 */  lbu        $2, 0x58($2)
    /* 1AD0A4 002AD0A4 F000A27F */  sq         $2, 0xF0($29)
    /* 1AD0A8 002AD0A8 A054050C */  jal        func_00155280
    /* 1AD0AC 002AD0AC 00000000 */   nop
    /* 1AD0B0 002AD0B0 21105100 */  addu       $2, $2, $17
    /* 1AD0B4 002AD0B4 21105500 */  addu       $2, $2, $21
    /* 1AD0B8 002AD0B8 58004390 */  lbu        $3, 0x58($2)
    /* 1AD0BC 002AD0BC F000A27B */  lq         $2, 0xF0($29)
    /* 1AD0C0 002AD0C0 29004314 */  bne        $2, $3, .L002AD168
    /* 1AD0C4 002AD0C4 00000000 */   nop
    /* 1AD0C8 002AD0C8 A054050C */  jal        func_00155280
    /* 1AD0CC 002AD0CC 00000000 */   nop
    /* 1AD0D0 002AD0D0 21185600 */  addu       $3, $2, $22
    /* 1AD0D4 002AD0D4 21187000 */  addu       $3, $3, $16
    /* 1AD0D8 002AD0D8 55006390 */  lbu        $3, 0x55($3)
    /* 1AD0DC 002AD0DC 0F006330 */  andi       $3, $3, 0xF
    /* 1AD0E0 002AD0E0 01000824 */  addiu      $8, $0, 0x1
    /* 1AD0E4 002AD0E4 20006814 */  bne        $3, $8, .L002AD168
    /* 1AD0E8 002AD0E8 00000000 */   nop
    /* 1AD0EC 002AD0EC FF008532 */  andi       $5, $20, 0xFF
    /* 1AD0F0 002AD0F0 0418A800 */  sllv       $3, $8, $5
    /* 1AD0F4 002AD0F4 FFFF6730 */  andi       $7, $3, 0xFFFF
    /* 1AD0F8 002AD0F8 3C1E1200 */  dsll32     $3, $18, 24
    /* 1AD0FC 002AD0FC 3F1E0300 */  dsra32     $3, $3, 24
    /* 1AD100 002AD100 40300300 */  sll        $6, $3, 1
    /* 1AD104 002AD104 68B5838F */  lw         $3, -0x4A98($28)
    /* 1AD108 002AD108 21206600 */  addu       $4, $3, $6
    /* 1AD10C 002AD10C 00008394 */  lhu        $3, 0x0($4)
    /* 1AD110 002AD110 25186700 */  or         $3, $3, $7
    /* 1AD114 002AD114 000083A4 */  sh         $3, 0x0($4)
    /* 1AD118 002AD118 0100A324 */  addiu      $3, $5, 0x1
    /* 1AD11C 002AD11C 04186800 */  sllv       $3, $8, $3
    /* 1AD120 002AD120 FFFF6530 */  andi       $5, $3, 0xFFFF
    /* 1AD124 002AD124 68B5838F */  lw         $3, -0x4A98($28)
    /* 1AD128 002AD128 21206600 */  addu       $4, $3, $6
    /* 1AD12C 002AD12C 00008394 */  lhu        $3, 0x0($4)
    /* 1AD130 002AD130 25186500 */  or         $3, $3, $5
    /* 1AD134 002AD134 000083A4 */  sh         $3, 0x0($4)
    /* 1AD138 002AD138 68B5838F */  lw         $3, -0x4A98($28)
    /* 1AD13C 002AD13C 2120C300 */  addu       $4, $6, $3
    /* 1AD140 002AD140 02008394 */  lhu        $3, 0x2($4)
    /* 1AD144 002AD144 25186700 */  or         $3, $3, $7
    /* 1AD148 002AD148 020083A4 */  sh         $3, 0x2($4)
    /* 1AD14C 002AD14C 68B5838F */  lw         $3, -0x4A98($28)
    /* 1AD150 002AD150 2120C300 */  addu       $4, $6, $3
    /* 1AD154 002AD154 02008394 */  lhu        $3, 0x2($4)
    /* 1AD158 002AD158 25186500 */  or         $3, $3, $5
    /* 1AD15C 002AD15C 020083A4 */  sh         $3, 0x2($4)
    /* 1AD160 002AD160 D3020010 */  b          .L002ADCB0
    /* 1AD164 002AD164 00000000 */   nop
  .L002AD168:
    /* 1AD168 002AD168 FF008432 */  andi       $4, $20, 0xFF
    /* 1AD16C 002AD16C 01000524 */  addiu      $5, $0, 0x1
    /* 1AD170 002AD170 2D30A000 */  daddu      $6, $5, $0
    /* 1AD174 002AD174 2D38C003 */  daddu      $7, $30, $0
    /* 1AD178 002AD178 2D40A000 */  daddu      $8, $5, $0
    /* 1AD17C 002AD17C 40CB0A0C */  jal        func_002b2d00
    /* 1AD180 002AD180 00000000 */   nop
    /* 1AD184 002AD184 3CAE0200 */  dsll32     $21, $2, 24
    /* 1AD188 002AD188 3FAE1500 */  dsra32     $21, $21, 24
    /* 1AD18C 002AD18C FF006432 */  andi       $4, $19, 0xFF
    /* 1AD190 002AD190 01000524 */  addiu      $5, $0, 0x1
    /* 1AD194 002AD194 2D30A000 */  daddu      $6, $5, $0
    /* 1AD198 002AD198 2D38E002 */  daddu      $7, $23, $0
    /* 1AD19C 002AD19C 2D40A000 */  daddu      $8, $5, $0
    /* 1AD1A0 002AD1A0 40CB0A0C */  jal        func_002b2d00
    /* 1AD1A4 002AD1A4 00000000 */   nop
    /* 1AD1A8 002AD1A8 3CA60200 */  dsll32     $20, $2, 24
    /* 1AD1AC 002AD1AC 3FA61400 */  dsra32     $20, $20, 24
    /* 1AD1B0 002AD1B0 009A1400 */  sll        $19, $20, 8
    /* 1AD1B4 002AD1B4 3C161500 */  dsll32     $2, $21, 24
    /* 1AD1B8 002AD1B8 3F160200 */  dsra32     $2, $2, 24
    /* 1AD1BC 002AD1BC 00910200 */  sll        $18, $2, 4
    /* 1AD1C0 002AD1C0 A054050C */  jal        func_00155280
    /* 1AD1C4 002AD1C4 00000000 */   nop
    /* 1AD1C8 002AD1C8 21105300 */  addu       $2, $2, $19
    /* 1AD1CC 002AD1CC 21105200 */  addu       $2, $2, $18
    /* 1AD1D0 002AD1D0 58005690 */  lbu        $22, 0x58($2)
    /* 1AD1D4 002AD1D4 A054050C */  jal        func_00155280
    /* 1AD1D8 002AD1D8 00000000 */   nop
    /* 1AD1DC 002AD1DC 21185100 */  addu       $3, $2, $17
    /* 1AD1E0 002AD1E0 21187000 */  addu       $3, $3, $16
    /* 1AD1E4 002AD1E4 58006390 */  lbu        $3, 0x58($3)
    /* 1AD1E8 002AD1E8 B102C316 */  bne        $22, $3, .L002ADCB0
    /* 1AD1EC 002AD1EC 00000000 */   nop
    /* 1AD1F0 002AD1F0 A054050C */  jal        func_00155280
    /* 1AD1F4 002AD1F4 00000000 */   nop
    /* 1AD1F8 002AD1F8 21185300 */  addu       $3, $2, $19
    /* 1AD1FC 002AD1FC 21187200 */  addu       $3, $3, $18
    /* 1AD200 002AD200 55006390 */  lbu        $3, 0x55($3)
    /* 1AD204 002AD204 0F006330 */  andi       $3, $3, 0xF
    /* 1AD208 002AD208 01000824 */  addiu      $8, $0, 0x1
    /* 1AD20C 002AD20C A8026814 */  bne        $3, $8, .L002ADCB0
    /* 1AD210 002AD210 00000000 */   nop
    /* 1AD214 002AD214 3C2E1500 */  dsll32     $5, $21, 24
    /* 1AD218 002AD218 3F2E0500 */  dsra32     $5, $5, 24
    /* 1AD21C 002AD21C 0418A800 */  sllv       $3, $8, $5
    /* 1AD220 002AD220 FFFF6730 */  andi       $7, $3, 0xFFFF
    /* 1AD224 002AD224 3C1E1400 */  dsll32     $3, $20, 24
    /* 1AD228 002AD228 3F1E0300 */  dsra32     $3, $3, 24
    /* 1AD22C 002AD22C 40300300 */  sll        $6, $3, 1
    /* 1AD230 002AD230 68B5838F */  lw         $3, -0x4A98($28)
    /* 1AD234 002AD234 21206600 */  addu       $4, $3, $6
    /* 1AD238 002AD238 00008394 */  lhu        $3, 0x0($4)
    /* 1AD23C 002AD23C 25186700 */  or         $3, $3, $7
    /* 1AD240 002AD240 000083A4 */  sh         $3, 0x0($4)
    /* 1AD244 002AD244 0100A324 */  addiu      $3, $5, 0x1
    /* 1AD248 002AD248 04186800 */  sllv       $3, $8, $3
    /* 1AD24C 002AD24C FFFF6530 */  andi       $5, $3, 0xFFFF
    /* 1AD250 002AD250 68B5838F */  lw         $3, -0x4A98($28)
    /* 1AD254 002AD254 21206600 */  addu       $4, $3, $6
    /* 1AD258 002AD258 00008394 */  lhu        $3, 0x0($4)
    /* 1AD25C 002AD25C 25186500 */  or         $3, $3, $5
    /* 1AD260 002AD260 000083A4 */  sh         $3, 0x0($4)
    /* 1AD264 002AD264 68B5838F */  lw         $3, -0x4A98($28)
    /* 1AD268 002AD268 2120C300 */  addu       $4, $6, $3
    /* 1AD26C 002AD26C 02008394 */  lhu        $3, 0x2($4)
    /* 1AD270 002AD270 25186700 */  or         $3, $3, $7
    /* 1AD274 002AD274 020083A4 */  sh         $3, 0x2($4)
    /* 1AD278 002AD278 68B5838F */  lw         $3, -0x4A98($28)
    /* 1AD27C 002AD27C 2120C300 */  addu       $4, $6, $3
    /* 1AD280 002AD280 02008394 */  lhu        $3, 0x2($4)
    /* 1AD284 002AD284 25186500 */  or         $3, $3, $5
    /* 1AD288 002AD288 020083A4 */  sh         $3, 0x2($4)
    /* 1AD28C 002AD28C 88020010 */  b          .L002ADCB0
    /* 1AD290 002AD290 00000000 */   nop
  .L002AD294:
    /* 1AD294 002AD294 A054050C */  jal        func_00155280
    /* 1AD298 002AD298 00000000 */   nop
    /* 1AD29C 002AD29C 21185100 */  addu       $3, $2, $17
    /* 1AD2A0 002AD2A0 21187000 */  addu       $3, $3, $16
    /* 1AD2A4 002AD2A4 58006390 */  lbu        $3, 0x58($3)
    /* 1AD2A8 002AD2A8 F7FF6324 */  addiu      $3, $3, -0x9
    /* 1AD2AC 002AD2AC 0600612C */  sltiu      $1, $3, 0x6
    /* 1AD2B0 002AD2B0 7F022010 */  beqz       $1, .L002ADCB0
    /* 1AD2B4 002AD2B4 00000000 */   nop
    /* 1AD2B8 002AD2B8 7500043C */  lui        $4, %hi(jtbl_007487E0)
    /* 1AD2BC 002AD2BC E0878424 */  addiu      $4, $4, %lo(jtbl_007487E0)
    /* 1AD2C0 002AD2C0 80180300 */  sll        $3, $3, 2
    /* 1AD2C4 002AD2C4 21186400 */  addu       $3, $3, $4
    /* 1AD2C8 002AD2C8 0000638C */  lw         $3, 0x0($3)
    /* 1AD2CC 002AD2CC 08006000 */  jr         $3
    /* 1AD2D0 002AD2D0 00000000 */   nop
    /* 1AD2D4 002AD2D4 A054050C */  jal        func_00155280
    /* 1AD2D8 002AD2D8 00000000 */   nop
    /* 1AD2DC 002AD2DC 21105100 */  addu       $2, $2, $17
    /* 1AD2E0 002AD2E0 21105000 */  addu       $2, $2, $16
    /* 1AD2E4 002AD2E4 55004490 */  lbu        $4, 0x55($2)
    /* 1AD2E8 002AD2E8 3CB70A0C */  jal        func_002adcf0
    /* 1AD2EC 002AD2EC 00000000 */   nop
    /* 1AD2F0 002AD2F0 3C1E0200 */  dsll32     $3, $2, 24
    /* 1AD2F4 002AD2F4 3F1E0300 */  dsra32     $3, $3, 24
    /* 1AD2F8 002AD2F8 01000424 */  addiu      $4, $0, 0x1
    /* 1AD2FC 002AD2FC 0C006414 */  bne        $3, $4, .L002AD330
    /* 1AD300 002AD300 00000000 */   nop
    /* 1AD304 002AD304 FF008332 */  andi       $3, $20, 0xFF
    /* 1AD308 002AD308 04186400 */  sllv       $3, $4, $3
    /* 1AD30C 002AD30C FFFF6530 */  andi       $5, $3, 0xFFFF
    /* 1AD310 002AD310 40201200 */  sll        $4, $18, 1
    /* 1AD314 002AD314 68B5838F */  lw         $3, -0x4A98($28)
    /* 1AD318 002AD318 21206400 */  addu       $4, $3, $4
    /* 1AD31C 002AD31C 00008394 */  lhu        $3, 0x0($4)
    /* 1AD320 002AD320 25186500 */  or         $3, $3, $5
    /* 1AD324 002AD324 000083A4 */  sh         $3, 0x0($4)
    /* 1AD328 002AD328 61020010 */  b          .L002ADCB0
    /* 1AD32C 002AD32C 00000000 */   nop
  .L002AD330:
    /* 1AD330 002AD330 A054050C */  jal        func_00155280
    /* 1AD334 002AD334 00000000 */   nop
    /* 1AD338 002AD338 21105100 */  addu       $2, $2, $17
    /* 1AD33C 002AD33C 21105000 */  addu       $2, $2, $16
    /* 1AD340 002AD340 55004490 */  lbu        $4, 0x55($2)
    /* 1AD344 002AD344 3CB70A0C */  jal        func_002adcf0
    /* 1AD348 002AD348 00000000 */   nop
    /* 1AD34C 002AD34C 3C260200 */  dsll32     $4, $2, 24
    /* 1AD350 002AD350 3F260400 */  dsra32     $4, $4, 24
    /* 1AD354 002AD354 02000324 */  addiu      $3, $0, 0x2
    /* 1AD358 002AD358 55028314 */  bne        $4, $3, .L002ADCB0
    /* 1AD35C 002AD35C 00000000 */   nop
    /* 1AD360 002AD360 FF008432 */  andi       $4, $20, 0xFF
    /* 1AD364 002AD364 01000524 */  addiu      $5, $0, 0x1
    /* 1AD368 002AD368 04108500 */  sllv       $2, $5, $4
    /* 1AD36C 002AD36C FFFF4630 */  andi       $6, $2, 0xFFFF
    /* 1AD370 002AD370 40181200 */  sll        $3, $18, 1
    /* 1AD374 002AD374 68B5828F */  lw         $2, -0x4A98($28)
    /* 1AD378 002AD378 21184300 */  addu       $3, $2, $3
    /* 1AD37C 002AD37C 00006294 */  lhu        $2, 0x0($3)
    /* 1AD380 002AD380 25104600 */  or         $2, $2, $6
    /* 1AD384 002AD384 000062A4 */  sh         $2, 0x0($3)
    /* 1AD388 002AD388 2D300000 */  daddu      $6, $0, $0
    /* 1AD38C 002AD38C 2D380000 */  daddu      $7, $0, $0
    /* 1AD390 002AD390 2D40A000 */  daddu      $8, $5, $0
    /* 1AD394 002AD394 40CB0A0C */  jal        func_002b2d00
    /* 1AD398 002AD398 00000000 */   nop
    /* 1AD39C 002AD39C 3C860200 */  dsll32     $16, $2, 24
    /* 1AD3A0 002AD3A0 3F861000 */  dsra32     $16, $16, 24
    /* 1AD3A4 002AD3A4 2D204002 */  daddu      $4, $18, $0
    /* 1AD3A8 002AD3A8 01000524 */  addiu      $5, $0, 0x1
    /* 1AD3AC 002AD3AC 2D300000 */  daddu      $6, $0, $0
    /* 1AD3B0 002AD3B0 2D380000 */  daddu      $7, $0, $0
    /* 1AD3B4 002AD3B4 2D40A000 */  daddu      $8, $5, $0
    /* 1AD3B8 002AD3B8 40CB0A0C */  jal        func_002b2d00
    /* 1AD3BC 002AD3BC 00000000 */   nop
    /* 1AD3C0 002AD3C0 3CAE0200 */  dsll32     $21, $2, 24
    /* 1AD3C4 002AD3C4 3FAE1500 */  dsra32     $21, $21, 24
    /* 1AD3C8 002AD3C8 2D900000 */  daddu      $18, $0, $0
    /* 1AD3CC 002AD3CC 3C861000 */  dsll32     $16, $16, 24
    /* 1AD3D0 002AD3D0 3F861000 */  dsra32     $16, $16, 24
    /* 1AD3D4 002AD3D4 3F000010 */  b          .L002AD4D4
    /* 1AD3D8 002AD3D8 00000000 */   nop
  .L002AD3DC:
    /* 1AD3DC 002AD3DC 2D880000 */  daddu      $17, $0, $0
    /* 1AD3E0 002AD3E0 3CA61500 */  dsll32     $20, $21, 24
    /* 1AD3E4 002AD3E4 3FA61400 */  dsra32     $20, $20, 24
    /* 1AD3E8 002AD3E8 00AA1400 */  sll        $21, $20, 8
    /* 1AD3EC 002AD3EC 40B01400 */  sll        $22, $20, 1
    /* 1AD3F0 002AD3F0 27000010 */  b          .L002AD490
    /* 1AD3F4 002AD3F4 00000000 */   nop
  .L002AD3F8:
    /* 1AD3F8 002AD3F8 2D200002 */  daddu      $4, $16, $0
    /* 1AD3FC 002AD3FC 2D286002 */  daddu      $5, $19, $0
    /* 1AD400 002AD400 10000624 */  addiu      $6, $0, 0x10
    /* 1AD404 002AD404 2D380000 */  daddu      $7, $0, $0
    /* 1AD408 002AD408 01000824 */  addiu      $8, $0, 0x1
    /* 1AD40C 002AD40C 2CCB0A0C */  jal        func_002b2cb0
    /* 1AD410 002AD410 00000000 */   nop
    /* 1AD414 002AD414 00B90200 */  sll        $23, $2, 4
    /* 1AD418 002AD418 A054050C */  jal        func_00155280
    /* 1AD41C 002AD41C 00000000 */   nop
    /* 1AD420 002AD420 2110A202 */  addu       $2, $21, $2
    /* 1AD424 002AD424 21105700 */  addu       $2, $2, $23
    /* 1AD428 002AD428 55004490 */  lbu        $4, 0x55($2)
    /* 1AD42C 002AD42C 3CB70A0C */  jal        func_002adcf0
    /* 1AD430 002AD430 00000000 */   nop
    /* 1AD434 002AD434 3C1E0200 */  dsll32     $3, $2, 24
    /* 1AD438 002AD438 3F1E0300 */  dsra32     $3, $3, 24
    /* 1AD43C 002AD43C 02000224 */  addiu      $2, $0, 0x2
    /* 1AD440 002AD440 10006214 */  bne        $3, $2, .L002AD484
    /* 1AD444 002AD444 00000000 */   nop
    /* 1AD448 002AD448 2D200002 */  daddu      $4, $16, $0
    /* 1AD44C 002AD44C 2D286002 */  daddu      $5, $19, $0
    /* 1AD450 002AD450 10000624 */  addiu      $6, $0, 0x10
    /* 1AD454 002AD454 2D380000 */  daddu      $7, $0, $0
    /* 1AD458 002AD458 01000824 */  addiu      $8, $0, 0x1
    /* 1AD45C 002AD45C 2CCB0A0C */  jal        func_002b2cb0
    /* 1AD460 002AD460 00000000 */   nop
    /* 1AD464 002AD464 01000324 */  addiu      $3, $0, 0x1
    /* 1AD468 002AD468 04104300 */  sllv       $2, $3, $2
    /* 1AD46C 002AD46C FFFF4430 */  andi       $4, $2, 0xFFFF
    /* 1AD470 002AD470 68B5828F */  lw         $2, -0x4A98($28)
    /* 1AD474 002AD474 2118C202 */  addu       $3, $22, $2
    /* 1AD478 002AD478 00006294 */  lhu        $2, 0x0($3)
    /* 1AD47C 002AD47C 25104400 */  or         $2, $2, $4
    /* 1AD480 002AD480 000062A4 */  sh         $2, 0x0($3)
  .L002AD484:
    /* 1AD484 002AD484 01002226 */  addiu      $2, $17, 0x1
    /* 1AD488 002AD488 3C8C0200 */  dsll32     $17, $2, 16
    /* 1AD48C 002AD48C 3F8C1100 */  dsra32     $17, $17, 16
  .L002AD490:
    /* 1AD490 002AD490 3C9C1100 */  dsll32     $19, $17, 16
    /* 1AD494 002AD494 3F9C1300 */  dsra32     $19, $19, 16
    /* 1AD498 002AD498 0300622A */  slti       $2, $19, 0x3
    /* 1AD49C 002AD49C D6FF4014 */  bnez       $2, .L002AD3F8
    /* 1AD4A0 002AD4A0 00000000 */   nop
    /* 1AD4A4 002AD4A4 2D208002 */  daddu      $4, $20, $0
    /* 1AD4A8 002AD4A8 01000524 */  addiu      $5, $0, 0x1
    /* 1AD4AC 002AD4AC 18000624 */  addiu      $6, $0, 0x18
    /* 1AD4B0 002AD4B0 2D380000 */  daddu      $7, $0, $0
    /* 1AD4B4 002AD4B4 2D40A000 */  daddu      $8, $5, $0
    /* 1AD4B8 002AD4B8 2CCB0A0C */  jal        func_002b2cb0
    /* 1AD4BC 002AD4BC 00000000 */   nop
    /* 1AD4C0 002AD4C0 3CAE0200 */  dsll32     $21, $2, 24
    /* 1AD4C4 002AD4C4 3FAE1500 */  dsra32     $21, $21, 24
    /* 1AD4C8 002AD4C8 01004326 */  addiu      $3, $18, 0x1
    /* 1AD4CC 002AD4CC 3C940300 */  dsll32     $18, $3, 16
    /* 1AD4D0 002AD4D0 3F941200 */  dsra32     $18, $18, 16
  .L002AD4D4:
    /* 1AD4D4 002AD4D4 3C1C1200 */  dsll32     $3, $18, 16
    /* 1AD4D8 002AD4D8 3F1C0300 */  dsra32     $3, $3, 16
    /* 1AD4DC 002AD4DC 03006328 */  slti       $3, $3, 0x3
    /* 1AD4E0 002AD4E0 BEFF6014 */  bnez       $3, .L002AD3DC
    /* 1AD4E4 002AD4E4 00000000 */   nop
    /* 1AD4E8 002AD4E8 F1010010 */  b          .L002ADCB0
    /* 1AD4EC 002AD4EC 00000000 */   nop
    /* 1AD4F0 002AD4F0 A054050C */  jal        func_00155280
    /* 1AD4F4 002AD4F4 00000000 */   nop
    /* 1AD4F8 002AD4F8 21105100 */  addu       $2, $2, $17
    /* 1AD4FC 002AD4FC 21105000 */  addu       $2, $2, $16
    /* 1AD500 002AD500 55004490 */  lbu        $4, 0x55($2)
    /* 1AD504 002AD504 3CB70A0C */  jal        func_002adcf0
    /* 1AD508 002AD508 00000000 */   nop
    /* 1AD50C 002AD50C 3C1E0200 */  dsll32     $3, $2, 24
    /* 1AD510 002AD510 3F1E0300 */  dsra32     $3, $3, 24
    /* 1AD514 002AD514 01000224 */  addiu      $2, $0, 0x1
    /* 1AD518 002AD518 D8006214 */  bne        $3, $2, .L002AD87C
    /* 1AD51C 002AD51C 00000000 */   nop
    /* 1AD520 002AD520 A054050C */  jal        func_00155280
    /* 1AD524 002AD524 00000000 */   nop
    /* 1AD528 002AD528 21185100 */  addu       $3, $2, $17
    /* 1AD52C 002AD52C 21187000 */  addu       $3, $3, $16
    /* 1AD530 002AD530 55006390 */  lbu        $3, 0x55($3)
    /* 1AD534 002AD534 0F006330 */  andi       $3, $3, 0xF
    /* 1AD538 002AD538 01000424 */  addiu      $4, $0, 0x1
    /* 1AD53C 002AD53C 18006414 */  bne        $3, $4, .L002AD5A0
    /* 1AD540 002AD540 00000000 */   nop
    /* 1AD544 002AD544 FF008332 */  andi       $3, $20, 0xFF
    /* 1AD548 002AD548 04186400 */  sllv       $3, $4, $3
    /* 1AD54C 002AD54C FFFF6630 */  andi       $6, $3, 0xFFFF
    /* 1AD550 002AD550 40201200 */  sll        $4, $18, 1
    /* 1AD554 002AD554 68B5838F */  lw         $3, -0x4A98($28)
    /* 1AD558 002AD558 21206400 */  addu       $4, $3, $4
    /* 1AD55C 002AD55C 00008394 */  lhu        $3, 0x0($4)
    /* 1AD560 002AD560 25186600 */  or         $3, $3, $6
    /* 1AD564 002AD564 000083A4 */  sh         $3, 0x0($4)
    /* 1AD568 002AD568 2D184002 */  daddu      $3, $18, $0
    /* 1AD56C 002AD56C 40280300 */  sll        $5, $3, 1
    /* 1AD570 002AD570 68B5838F */  lw         $3, -0x4A98($28)
    /* 1AD574 002AD574 2120A300 */  addu       $4, $5, $3
    /* 1AD578 002AD578 02008394 */  lhu        $3, 0x2($4)
    /* 1AD57C 002AD57C 25186600 */  or         $3, $3, $6
    /* 1AD580 002AD580 020083A4 */  sh         $3, 0x2($4)
    /* 1AD584 002AD584 68B5838F */  lw         $3, -0x4A98($28)
    /* 1AD588 002AD588 2120A300 */  addu       $4, $5, $3
    /* 1AD58C 002AD58C 04008394 */  lhu        $3, 0x4($4)
    /* 1AD590 002AD590 25186600 */  or         $3, $3, $6
    /* 1AD594 002AD594 040083A4 */  sh         $3, 0x4($4)
    /* 1AD598 002AD598 C5010010 */  b          .L002ADCB0
    /* 1AD59C 002AD59C 00000000 */   nop
  .L002AD5A0:
    /* 1AD5A0 002AD5A0 2DB00000 */  daddu      $22, $0, $0
    /* 1AD5A4 002AD5A4 2D104002 */  daddu      $2, $18, $0
    /* 1AD5A8 002AD5A8 8001A2AF */  sw         $2, 0x180($29)
    /* 1AD5AC 002AD5AC FF008232 */  andi       $2, $20, 0xFF
    /* 1AD5B0 002AD5B0 7001A2AF */  sw         $2, 0x170($29)
    /* 1AD5B4 002AD5B4 21903002 */  addu       $18, $17, $16
    /* 1AD5B8 002AD5B8 47000010 */  b          .L002AD6D8
    /* 1AD5BC 002AD5BC 00000000 */   nop
  .L002AD5C0:
    /* 1AD5C0 002AD5C0 8001A48F */  lw         $4, 0x180($29)
    /* 1AD5C4 002AD5C4 01000624 */  addiu      $6, $0, 0x1
    /* 1AD5C8 002AD5C8 18000724 */  addiu      $7, $0, 0x18
    /* 1AD5CC 002AD5CC 2D40C000 */  daddu      $8, $6, $0
    /* 1AD5D0 002AD5D0 40CB0A0C */  jal        func_002b2d00
    /* 1AD5D4 002AD5D4 00000000 */   nop
    /* 1AD5D8 002AD5D8 3C160200 */  dsll32     $2, $2, 24
    /* 1AD5DC 002AD5DC 3F160200 */  dsra32     $2, $2, 24
    /* 1AD5E0 002AD5E0 E000A27F */  sq         $2, 0xE0($29)
    /* 1AD5E4 002AD5E4 2DB80000 */  daddu      $23, $0, $0
    /* 1AD5E8 002AD5E8 00120200 */  sll        $2, $2, 8
    /* 1AD5EC 002AD5EC D000A27F */  sq         $2, 0xD0($29)
    /* 1AD5F0 002AD5F0 31000010 */  b          .L002AD6B8
    /* 1AD5F4 002AD5F4 00000000 */   nop
  .L002AD5F8:
    /* 1AD5F8 002AD5F8 7001A48F */  lw         $4, 0x170($29)
    /* 1AD5FC 002AD5FC 01000624 */  addiu      $6, $0, 0x1
    /* 1AD600 002AD600 10000724 */  addiu      $7, $0, 0x10
    /* 1AD604 002AD604 2D40C000 */  daddu      $8, $6, $0
    /* 1AD608 002AD608 40CB0A0C */  jal        func_002b2d00
    /* 1AD60C 002AD60C 00000000 */   nop
    /* 1AD610 002AD610 3C160200 */  dsll32     $2, $2, 24
    /* 1AD614 002AD614 3F160200 */  dsra32     $2, $2, 24
    /* 1AD618 002AD618 C000A27F */  sq         $2, 0xC0($29)
    /* 1AD61C 002AD61C 00110200 */  sll        $2, $2, 4
    /* 1AD620 002AD620 B000A27F */  sq         $2, 0xB0($29)
    /* 1AD624 002AD624 A054050C */  jal        func_00155280
    /* 1AD628 002AD628 00000000 */   nop
    /* 1AD62C 002AD62C D000A37B */  lq         $3, 0xD0($29)
    /* 1AD630 002AD630 21186200 */  addu       $3, $3, $2
    /* 1AD634 002AD634 B000A27B */  lq         $2, 0xB0($29)
    /* 1AD638 002AD638 21106200 */  addu       $2, $3, $2
    /* 1AD63C 002AD63C 55004290 */  lbu        $2, 0x55($2)
    /* 1AD640 002AD640 0F004330 */  andi       $3, $2, 0xF
    /* 1AD644 002AD644 01000224 */  addiu      $2, $0, 0x1
    /* 1AD648 002AD648 18006214 */  bne        $3, $2, .L002AD6AC
    /* 1AD64C 002AD64C 00000000 */   nop
    /* 1AD650 002AD650 A054050C */  jal        func_00155280
    /* 1AD654 002AD654 00000000 */   nop
    /* 1AD658 002AD658 D000A37B */  lq         $3, 0xD0($29)
    /* 1AD65C 002AD65C 21186200 */  addu       $3, $3, $2
    /* 1AD660 002AD660 B000A27B */  lq         $2, 0xB0($29)
    /* 1AD664 002AD664 21106200 */  addu       $2, $3, $2
    /* 1AD668 002AD668 58004290 */  lbu        $2, 0x58($2)
    /* 1AD66C 002AD66C A000A27F */  sq         $2, 0xA0($29)
    /* 1AD670 002AD670 A054050C */  jal        func_00155280
    /* 1AD674 002AD674 00000000 */   nop
    /* 1AD678 002AD678 21104202 */  addu       $2, $18, $2
    /* 1AD67C 002AD67C 58004390 */  lbu        $3, 0x58($2)
    /* 1AD680 002AD680 A000A27B */  lq         $2, 0xA0($29)
    /* 1AD684 002AD684 09004314 */  bne        $2, $3, .L002AD6AC
    /* 1AD688 002AD688 00000000 */   nop
    /* 1AD68C 002AD68C C000A27B */  lq         $2, 0xC0($29)
    /* 1AD690 002AD690 3CF60200 */  dsll32     $30, $2, 24
    /* 1AD694 002AD694 3FF61E00 */  dsra32     $30, $30, 24
    /* 1AD698 002AD698 E000A27B */  lq         $2, 0xE0($29)
    /* 1AD69C 002AD69C 3CAE0200 */  dsll32     $21, $2, 24
    /* 1AD6A0 002AD6A0 3FAE1500 */  dsra32     $21, $21, 24
    /* 1AD6A4 002AD6A4 09000010 */  b          .L002AD6CC
    /* 1AD6A8 002AD6A8 00000000 */   nop
  .L002AD6AC:
    /* 1AD6AC 002AD6AC 0100E226 */  addiu      $2, $23, 0x1
    /* 1AD6B0 002AD6B0 3CBC0200 */  dsll32     $23, $2, 16
    /* 1AD6B4 002AD6B4 3FBC1700 */  dsra32     $23, $23, 16
  .L002AD6B8:
    /* 1AD6B8 002AD6B8 3C2C1700 */  dsll32     $5, $23, 16
    /* 1AD6BC 002AD6BC 3F2C0500 */  dsra32     $5, $5, 16
    /* 1AD6C0 002AD6C0 0300A228 */  slti       $2, $5, 0x3
    /* 1AD6C4 002AD6C4 CCFF4014 */  bnez       $2, .L002AD5F8
    /* 1AD6C8 002AD6C8 00000000 */   nop
  .L002AD6CC:
    /* 1AD6CC 002AD6CC 0100C226 */  addiu      $2, $22, 0x1
    /* 1AD6D0 002AD6D0 3CB40200 */  dsll32     $22, $2, 16
    /* 1AD6D4 002AD6D4 3FB41600 */  dsra32     $22, $22, 16
  .L002AD6D8:
    /* 1AD6D8 002AD6D8 3C2C1600 */  dsll32     $5, $22, 16
    /* 1AD6DC 002AD6DC 3F2C0500 */  dsra32     $5, $5, 16
    /* 1AD6E0 002AD6E0 0300A228 */  slti       $2, $5, 0x3
    /* 1AD6E4 002AD6E4 B6FF4014 */  bnez       $2, .L002AD5C0
    /* 1AD6E8 002AD6E8 00000000 */   nop
    /* 1AD6EC 002AD6EC A054050C */  jal        func_00155280
    /* 1AD6F0 002AD6F0 00000000 */   nop
    /* 1AD6F4 002AD6F4 21185100 */  addu       $3, $2, $17
    /* 1AD6F8 002AD6F8 21187000 */  addu       $3, $3, $16
    /* 1AD6FC 002AD6FC 59006490 */  lbu        $4, 0x59($3)
    /* 1AD700 002AD700 03000324 */  addiu      $3, $0, 0x3
    /* 1AD704 002AD704 36008310 */  beq        $4, $3, .L002AD7E0
    /* 1AD708 002AD708 00000000 */   nop
    /* 1AD70C 002AD70C 01000324 */  addiu      $3, $0, 0x1
    /* 1AD710 002AD710 33008310 */  beq        $4, $3, .L002AD7E0
    /* 1AD714 002AD714 00000000 */   nop
    /* 1AD718 002AD718 02000324 */  addiu      $3, $0, 0x2
    /* 1AD71C 002AD71C 05008310 */  beq        $4, $3, .L002AD734
    /* 1AD720 002AD720 00000000 */   nop
    /* 1AD724 002AD724 03008010 */  beqz       $4, .L002AD734
    /* 1AD728 002AD728 00000000 */   nop
    /* 1AD72C 002AD72C 60010010 */  b          .L002ADCB0
    /* 1AD730 002AD730 00000000 */   nop
  .L002AD734:
    /* 1AD734 002AD734 2D880000 */  daddu      $17, $0, $0
    /* 1AD738 002AD738 FF008332 */  andi       $3, $20, 0xFF
    /* 1AD73C 002AD73C 00B90300 */  sll        $23, $3, 4
    /* 1AD740 002AD740 3C861500 */  dsll32     $16, $21, 24
    /* 1AD744 002AD744 3F861000 */  dsra32     $16, $16, 24
    /* 1AD748 002AD748 01000424 */  addiu      $4, $0, 0x1
    /* 1AD74C 002AD74C 7001A38F */  lw         $3, 0x170($29)
    /* 1AD750 002AD750 04186400 */  sllv       $3, $4, $3
    /* 1AD754 002AD754 FFFF7530 */  andi       $21, $3, 0xFFFF
    /* 1AD758 002AD758 40A01000 */  sll        $20, $16, 1
    /* 1AD75C 002AD75C 19000010 */  b          .L002AD7C4
    /* 1AD760 002AD760 00000000 */   nop
  .L002AD764:
    /* 1AD764 002AD764 A054050C */  jal        func_00155280
    /* 1AD768 002AD768 00000000 */   nop
    /* 1AD76C 002AD76C 2118E202 */  addu       $3, $23, $2
    /* 1AD770 002AD770 21101302 */  addu       $2, $16, $19
    /* 1AD774 002AD774 00120200 */  sll        $2, $2, 8
    /* 1AD778 002AD778 21106200 */  addu       $2, $3, $2
    /* 1AD77C 002AD77C 58005690 */  lbu        $22, 0x58($2)
    /* 1AD780 002AD780 A054050C */  jal        func_00155280
    /* 1AD784 002AD784 00000000 */   nop
    /* 1AD788 002AD788 21184202 */  addu       $3, $18, $2
    /* 1AD78C 002AD78C 58006390 */  lbu        $3, 0x58($3)
    /* 1AD790 002AD790 0900C316 */  bne        $22, $3, .L002AD7B8
    /* 1AD794 002AD794 00000000 */   nop
    /* 1AD798 002AD798 68B5838F */  lw         $3, -0x4A98($28)
    /* 1AD79C 002AD79C 21208302 */  addu       $4, $20, $3
    /* 1AD7A0 002AD7A0 40181300 */  sll        $3, $19, 1
    /* 1AD7A4 002AD7A4 21288300 */  addu       $5, $4, $3
    /* 1AD7A8 002AD7A8 FFFFA432 */  andi       $4, $21, 0xFFFF
    /* 1AD7AC 002AD7AC 0000A394 */  lhu        $3, 0x0($5)
    /* 1AD7B0 002AD7B0 25186400 */  or         $3, $3, $4
    /* 1AD7B4 002AD7B4 0000A3A4 */  sh         $3, 0x0($5)
  .L002AD7B8:
    /* 1AD7B8 002AD7B8 01002326 */  addiu      $3, $17, 0x1
    /* 1AD7BC 002AD7BC 3C8C0300 */  dsll32     $17, $3, 16
    /* 1AD7C0 002AD7C0 3F8C1100 */  dsra32     $17, $17, 16
  .L002AD7C4:
    /* 1AD7C4 002AD7C4 3C9C1100 */  dsll32     $19, $17, 16
    /* 1AD7C8 002AD7C8 3F9C1300 */  dsra32     $19, $19, 16
    /* 1AD7CC 002AD7CC 0300632A */  slti       $3, $19, 0x3
    /* 1AD7D0 002AD7D0 E4FF6014 */  bnez       $3, .L002AD764
    /* 1AD7D4 002AD7D4 00000000 */   nop
    /* 1AD7D8 002AD7D8 35010010 */  b          .L002ADCB0
    /* 1AD7DC 002AD7DC 00000000 */   nop
  .L002AD7E0:
    /* 1AD7E0 002AD7E0 2D800000 */  daddu      $16, $0, $0
    /* 1AD7E4 002AD7E4 FF006332 */  andi       $3, $19, 0xFF
    /* 1AD7E8 002AD7E8 00B20300 */  sll        $22, $3, 8
    /* 1AD7EC 002AD7EC 3CA61E00 */  dsll32     $20, $30, 24
    /* 1AD7F0 002AD7F0 3FA61400 */  dsra32     $20, $20, 24
    /* 1AD7F4 002AD7F4 40980300 */  sll        $19, $3, 1
    /* 1AD7F8 002AD7F8 19000010 */  b          .L002AD860
    /* 1AD7FC 002AD7FC 00000000 */   nop
  .L002AD800:
    /* 1AD800 002AD800 21888402 */  addu       $17, $20, $4
    /* 1AD804 002AD804 A054050C */  jal        func_00155280
    /* 1AD808 002AD808 00000000 */   nop
    /* 1AD80C 002AD80C 2118C202 */  addu       $3, $22, $2
    /* 1AD810 002AD810 00111100 */  sll        $2, $17, 4
    /* 1AD814 002AD814 21106200 */  addu       $2, $3, $2
    /* 1AD818 002AD818 58005590 */  lbu        $21, 0x58($2)
    /* 1AD81C 002AD81C A054050C */  jal        func_00155280
    /* 1AD820 002AD820 00000000 */   nop
    /* 1AD824 002AD824 21184202 */  addu       $3, $18, $2
    /* 1AD828 002AD828 58006390 */  lbu        $3, 0x58($3)
    /* 1AD82C 002AD82C 0900A316 */  bne        $21, $3, .L002AD854
    /* 1AD830 002AD830 00000000 */   nop
    /* 1AD834 002AD834 01000324 */  addiu      $3, $0, 0x1
    /* 1AD838 002AD838 04182302 */  sllv       $3, $3, $17
    /* 1AD83C 002AD83C FFFF6530 */  andi       $5, $3, 0xFFFF
    /* 1AD840 002AD840 68B5838F */  lw         $3, -0x4A98($28)
    /* 1AD844 002AD844 21206302 */  addu       $4, $19, $3
    /* 1AD848 002AD848 00008394 */  lhu        $3, 0x0($4)
    /* 1AD84C 002AD84C 25186500 */  or         $3, $3, $5
    /* 1AD850 002AD850 000083A4 */  sh         $3, 0x0($4)
  .L002AD854:
    /* 1AD854 002AD854 01000326 */  addiu      $3, $16, 0x1
    /* 1AD858 002AD858 3C840300 */  dsll32     $16, $3, 16
    /* 1AD85C 002AD85C 3F841000 */  dsra32     $16, $16, 16
  .L002AD860:
    /* 1AD860 002AD860 3C241000 */  dsll32     $4, $16, 16
    /* 1AD864 002AD864 3F240400 */  dsra32     $4, $4, 16
    /* 1AD868 002AD868 03008328 */  slti       $3, $4, 0x3
    /* 1AD86C 002AD86C E4FF6014 */  bnez       $3, .L002AD800
    /* 1AD870 002AD870 00000000 */   nop
    /* 1AD874 002AD874 0E010010 */  b          .L002ADCB0
    /* 1AD878 002AD878 00000000 */   nop
  .L002AD87C:
    /* 1AD87C 002AD87C A054050C */  jal        func_00155280
    /* 1AD880 002AD880 00000000 */   nop
    /* 1AD884 002AD884 21105100 */  addu       $2, $2, $17
    /* 1AD888 002AD888 21105000 */  addu       $2, $2, $16
    /* 1AD88C 002AD88C 55004490 */  lbu        $4, 0x55($2)
    /* 1AD890 002AD890 3CB70A0C */  jal        func_002adcf0
    /* 1AD894 002AD894 00000000 */   nop
    /* 1AD898 002AD898 3C260200 */  dsll32     $4, $2, 24
    /* 1AD89C 002AD89C 3F260400 */  dsra32     $4, $4, 24
    /* 1AD8A0 002AD8A0 02000324 */  addiu      $3, $0, 0x2
    /* 1AD8A4 002AD8A4 02018314 */  bne        $4, $3, .L002ADCB0
    /* 1AD8A8 002AD8A8 00000000 */   nop
    /* 1AD8AC 002AD8AC FF008432 */  andi       $4, $20, 0xFF
    /* 1AD8B0 002AD8B0 01000524 */  addiu      $5, $0, 0x1
    /* 1AD8B4 002AD8B4 04108500 */  sllv       $2, $5, $4
    /* 1AD8B8 002AD8B8 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* 1AD8BC 002AD8BC 40181200 */  sll        $3, $18, 1
    /* 1AD8C0 002AD8C0 68B5828F */  lw         $2, -0x4A98($28)
    /* 1AD8C4 002AD8C4 21184300 */  addu       $3, $2, $3
    /* 1AD8C8 002AD8C8 00006294 */  lhu        $2, 0x0($3)
    /* 1AD8CC 002AD8CC 25104600 */  or         $2, $2, $6
    /* 1AD8D0 002AD8D0 000062A4 */  sh         $2, 0x0($3)
    /* 1AD8D4 002AD8D4 2D300000 */  daddu      $6, $0, $0
    /* 1AD8D8 002AD8D8 2D380000 */  daddu      $7, $0, $0
    /* 1AD8DC 002AD8DC 2D40A000 */  daddu      $8, $5, $0
    /* 1AD8E0 002AD8E0 40CB0A0C */  jal        func_002b2d00
    /* 1AD8E4 002AD8E4 00000000 */   nop
    /* 1AD8E8 002AD8E8 3C860200 */  dsll32     $16, $2, 24
    /* 1AD8EC 002AD8EC 3F861000 */  dsra32     $16, $16, 24
    /* 1AD8F0 002AD8F0 2D204002 */  daddu      $4, $18, $0
    /* 1AD8F4 002AD8F4 01000524 */  addiu      $5, $0, 0x1
    /* 1AD8F8 002AD8F8 2D300000 */  daddu      $6, $0, $0
    /* 1AD8FC 002AD8FC 2D380000 */  daddu      $7, $0, $0
    /* 1AD900 002AD900 2D40A000 */  daddu      $8, $5, $0
    /* 1AD904 002AD904 40CB0A0C */  jal        func_002b2d00
    /* 1AD908 002AD908 00000000 */   nop
    /* 1AD90C 002AD90C 3C260200 */  dsll32     $4, $2, 24
    /* 1AD910 002AD910 3F260400 */  dsra32     $4, $4, 24
    /* 1AD914 002AD914 2D880000 */  daddu      $17, $0, $0
    /* 1AD918 002AD918 3CA61000 */  dsll32     $20, $16, 24
    /* 1AD91C 002AD91C 3FA61400 */  dsra32     $20, $20, 24
    /* 1AD920 002AD920 3F000010 */  b          .L002ADA20
    /* 1AD924 002AD924 00000000 */   nop
  .L002AD928:
    /* 1AD928 002AD928 2D800000 */  daddu      $16, $0, $0
    /* 1AD92C 002AD92C 3C9E0400 */  dsll32     $19, $4, 24
    /* 1AD930 002AD930 3F9E1300 */  dsra32     $19, $19, 24
    /* 1AD934 002AD934 00AA1300 */  sll        $21, $19, 8
    /* 1AD938 002AD938 40B01300 */  sll        $22, $19, 1
    /* 1AD93C 002AD93C 27000010 */  b          .L002AD9DC
    /* 1AD940 002AD940 00000000 */   nop
  .L002AD944:
    /* 1AD944 002AD944 2D208002 */  daddu      $4, $20, $0
    /* 1AD948 002AD948 2D284002 */  daddu      $5, $18, $0
    /* 1AD94C 002AD94C 10000624 */  addiu      $6, $0, 0x10
    /* 1AD950 002AD950 2D380000 */  daddu      $7, $0, $0
    /* 1AD954 002AD954 01000824 */  addiu      $8, $0, 0x1
    /* 1AD958 002AD958 2CCB0A0C */  jal        func_002b2cb0
    /* 1AD95C 002AD95C 00000000 */   nop
    /* 1AD960 002AD960 00B90200 */  sll        $23, $2, 4
    /* 1AD964 002AD964 A054050C */  jal        func_00155280
    /* 1AD968 002AD968 00000000 */   nop
    /* 1AD96C 002AD96C 2110A202 */  addu       $2, $21, $2
    /* 1AD970 002AD970 21105700 */  addu       $2, $2, $23
    /* 1AD974 002AD974 55004490 */  lbu        $4, 0x55($2)
    /* 1AD978 002AD978 3CB70A0C */  jal        func_002adcf0
    /* 1AD97C 002AD97C 00000000 */   nop
    /* 1AD980 002AD980 3C1E0200 */  dsll32     $3, $2, 24
    /* 1AD984 002AD984 3F1E0300 */  dsra32     $3, $3, 24
    /* 1AD988 002AD988 02000224 */  addiu      $2, $0, 0x2
    /* 1AD98C 002AD98C 10006214 */  bne        $3, $2, .L002AD9D0
    /* 1AD990 002AD990 00000000 */   nop
    /* 1AD994 002AD994 2D208002 */  daddu      $4, $20, $0
    /* 1AD998 002AD998 2D284002 */  daddu      $5, $18, $0
    /* 1AD99C 002AD99C 10000624 */  addiu      $6, $0, 0x10
    /* 1AD9A0 002AD9A0 2D380000 */  daddu      $7, $0, $0
    /* 1AD9A4 002AD9A4 01000824 */  addiu      $8, $0, 0x1
    /* 1AD9A8 002AD9A8 2CCB0A0C */  jal        func_002b2cb0
    /* 1AD9AC 002AD9AC 00000000 */   nop
    /* 1AD9B0 002AD9B0 01000324 */  addiu      $3, $0, 0x1
    /* 1AD9B4 002AD9B4 04104300 */  sllv       $2, $3, $2
    /* 1AD9B8 002AD9B8 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* 1AD9BC 002AD9BC 68B5828F */  lw         $2, -0x4A98($28)
    /* 1AD9C0 002AD9C0 2118C202 */  addu       $3, $22, $2
    /* 1AD9C4 002AD9C4 00006294 */  lhu        $2, 0x0($3)
    /* 1AD9C8 002AD9C8 25104400 */  or         $2, $2, $4
    /* 1AD9CC 002AD9CC 000062A4 */  sh         $2, 0x0($3)
  .L002AD9D0:
    /* 1AD9D0 002AD9D0 01000226 */  addiu      $2, $16, 0x1
    /* 1AD9D4 002AD9D4 3C840200 */  dsll32     $16, $2, 16
    /* 1AD9D8 002AD9D8 3F841000 */  dsra32     $16, $16, 16
  .L002AD9DC:
    /* 1AD9DC 002AD9DC 3C941000 */  dsll32     $18, $16, 16
    /* 1AD9E0 002AD9E0 3F941200 */  dsra32     $18, $18, 16
    /* 1AD9E4 002AD9E4 0300422A */  slti       $2, $18, 0x3
    /* 1AD9E8 002AD9E8 D6FF4014 */  bnez       $2, .L002AD944
    /* 1AD9EC 002AD9EC 00000000 */   nop
    /* 1AD9F0 002AD9F0 2D206002 */  daddu      $4, $19, $0
    /* 1AD9F4 002AD9F4 01000524 */  addiu      $5, $0, 0x1
    /* 1AD9F8 002AD9F8 18000624 */  addiu      $6, $0, 0x18
    /* 1AD9FC 002AD9FC 2D380000 */  daddu      $7, $0, $0
    /* 1ADA00 002ADA00 2D40A000 */  daddu      $8, $5, $0
    /* 1ADA04 002ADA04 2CCB0A0C */  jal        func_002b2cb0
    /* 1ADA08 002ADA08 00000000 */   nop
    /* 1ADA0C 002ADA0C 3C260200 */  dsll32     $4, $2, 24
    /* 1ADA10 002ADA10 3F260400 */  dsra32     $4, $4, 24
    /* 1ADA14 002ADA14 01002326 */  addiu      $3, $17, 0x1
    /* 1ADA18 002ADA18 3C8C0300 */  dsll32     $17, $3, 16
    /* 1ADA1C 002ADA1C 3F8C1100 */  dsra32     $17, $17, 16
  .L002ADA20:
    /* 1ADA20 002ADA20 3C1C1100 */  dsll32     $3, $17, 16
    /* 1ADA24 002ADA24 3F1C0300 */  dsra32     $3, $3, 16
    /* 1ADA28 002ADA28 03006328 */  slti       $3, $3, 0x3
    /* 1ADA2C 002ADA2C BEFF6014 */  bnez       $3, .L002AD928
    /* 1ADA30 002ADA30 00000000 */   nop
    /* 1ADA34 002ADA34 9E000010 */  b          .L002ADCB0
    /* 1ADA38 002ADA38 00000000 */   nop
    /* 1ADA3C 002ADA3C A054050C */  jal        func_00155280
    /* 1ADA40 002ADA40 00000000 */   nop
    /* 1ADA44 002ADA44 21105100 */  addu       $2, $2, $17
    /* 1ADA48 002ADA48 21105000 */  addu       $2, $2, $16
    /* 1ADA4C 002ADA4C 55004490 */  lbu        $4, 0x55($2)
    /* 1ADA50 002ADA50 3CB70A0C */  jal        func_002adcf0
    /* 1ADA54 002ADA54 00000000 */   nop
    /* 1ADA58 002ADA58 3C1E0200 */  dsll32     $3, $2, 24
    /* 1ADA5C 002ADA5C 3F1E0300 */  dsra32     $3, $3, 24
    /* 1ADA60 002ADA60 01000424 */  addiu      $4, $0, 0x1
    /* 1ADA64 002ADA64 0C006414 */  bne        $3, $4, .L002ADA98
    /* 1ADA68 002ADA68 00000000 */   nop
    /* 1ADA6C 002ADA6C FF008332 */  andi       $3, $20, 0xFF
    /* 1ADA70 002ADA70 04186400 */  sllv       $3, $4, $3
    /* 1ADA74 002ADA74 FFFF6530 */  andi       $5, $3, 0xFFFF
    /* 1ADA78 002ADA78 40201200 */  sll        $4, $18, 1
    /* 1ADA7C 002ADA7C 68B5838F */  lw         $3, -0x4A98($28)
    /* 1ADA80 002ADA80 21206400 */  addu       $4, $3, $4
    /* 1ADA84 002ADA84 00008394 */  lhu        $3, 0x0($4)
    /* 1ADA88 002ADA88 25186500 */  or         $3, $3, $5
    /* 1ADA8C 002ADA8C 000083A4 */  sh         $3, 0x0($4)
    /* 1ADA90 002ADA90 87000010 */  b          .L002ADCB0
    /* 1ADA94 002ADA94 00000000 */   nop
  .L002ADA98:
    /* 1ADA98 002ADA98 A054050C */  jal        func_00155280
    /* 1ADA9C 002ADA9C 00000000 */   nop
    /* 1ADAA0 002ADAA0 21105100 */  addu       $2, $2, $17
    /* 1ADAA4 002ADAA4 21105000 */  addu       $2, $2, $16
    /* 1ADAA8 002ADAA8 55004490 */  lbu        $4, 0x55($2)
    /* 1ADAAC 002ADAAC 3CB70A0C */  jal        func_002adcf0
    /* 1ADAB0 002ADAB0 00000000 */   nop
    /* 1ADAB4 002ADAB4 3C260200 */  dsll32     $4, $2, 24
    /* 1ADAB8 002ADAB8 3F260400 */  dsra32     $4, $4, 24
    /* 1ADABC 002ADABC 03000324 */  addiu      $3, $0, 0x3
    /* 1ADAC0 002ADAC0 0D008314 */  bne        $4, $3, .L002ADAF8
    /* 1ADAC4 002ADAC4 00000000 */   nop
    /* 1ADAC8 002ADAC8 FF008432 */  andi       $4, $20, 0xFF
    /* 1ADACC 002ADACC 01000324 */  addiu      $3, $0, 0x1
    /* 1ADAD0 002ADAD0 04188300 */  sllv       $3, $3, $4
    /* 1ADAD4 002ADAD4 FFFF6530 */  andi       $5, $3, 0xFFFF
    /* 1ADAD8 002ADAD8 40201200 */  sll        $4, $18, 1
    /* 1ADADC 002ADADC 68B5838F */  lw         $3, -0x4A98($28)
    /* 1ADAE0 002ADAE0 21206400 */  addu       $4, $3, $4
    /* 1ADAE4 002ADAE4 00008394 */  lhu        $3, 0x0($4)
    /* 1ADAE8 002ADAE8 25186500 */  or         $3, $3, $5
    /* 1ADAEC 002ADAEC 000083A4 */  sh         $3, 0x0($4)
    /* 1ADAF0 002ADAF0 6F000010 */  b          .L002ADCB0
    /* 1ADAF4 002ADAF4 00000000 */   nop
  .L002ADAF8:
    /* 1ADAF8 002ADAF8 A054050C */  jal        func_00155280
    /* 1ADAFC 002ADAFC 00000000 */   nop
    /* 1ADB00 002ADB00 21105100 */  addu       $2, $2, $17
    /* 1ADB04 002ADB04 21105000 */  addu       $2, $2, $16
    /* 1ADB08 002ADB08 55004490 */  lbu        $4, 0x55($2)
    /* 1ADB0C 002ADB0C 3CB70A0C */  jal        func_002adcf0
    /* 1ADB10 002ADB10 00000000 */   nop
    /* 1ADB14 002ADB14 3C260200 */  dsll32     $4, $2, 24
    /* 1ADB18 002ADB18 3F260400 */  dsra32     $4, $4, 24
    /* 1ADB1C 002ADB1C 02000324 */  addiu      $3, $0, 0x2
    /* 1ADB20 002ADB20 63008314 */  bne        $4, $3, .L002ADCB0
    /* 1ADB24 002ADB24 00000000 */   nop
    /* 1ADB28 002ADB28 FF008432 */  andi       $4, $20, 0xFF
    /* 1ADB2C 002ADB2C 01000524 */  addiu      $5, $0, 0x1
    /* 1ADB30 002ADB30 04108500 */  sllv       $2, $5, $4
    /* 1ADB34 002ADB34 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* 1ADB38 002ADB38 40181200 */  sll        $3, $18, 1
    /* 1ADB3C 002ADB3C 68B5828F */  lw         $2, -0x4A98($28)
    /* 1ADB40 002ADB40 21184300 */  addu       $3, $2, $3
    /* 1ADB44 002ADB44 00006294 */  lhu        $2, 0x0($3)
    /* 1ADB48 002ADB48 25104600 */  or         $2, $2, $6
    /* 1ADB4C 002ADB4C 000062A4 */  sh         $2, 0x0($3)
    /* 1ADB50 002ADB50 2D300000 */  daddu      $6, $0, $0
    /* 1ADB54 002ADB54 2D380000 */  daddu      $7, $0, $0
    /* 1ADB58 002ADB58 2D40A000 */  daddu      $8, $5, $0
    /* 1ADB5C 002ADB5C 40CB0A0C */  jal        func_002b2d00
    /* 1ADB60 002ADB60 00000000 */   nop
    /* 1ADB64 002ADB64 3C860200 */  dsll32     $16, $2, 24
    /* 1ADB68 002ADB68 3F861000 */  dsra32     $16, $16, 24
    /* 1ADB6C 002ADB6C 2D204002 */  daddu      $4, $18, $0
    /* 1ADB70 002ADB70 01000524 */  addiu      $5, $0, 0x1
    /* 1ADB74 002ADB74 2D300000 */  daddu      $6, $0, $0
    /* 1ADB78 002ADB78 2D380000 */  daddu      $7, $0, $0
    /* 1ADB7C 002ADB7C 2D40A000 */  daddu      $8, $5, $0
    /* 1ADB80 002ADB80 40CB0A0C */  jal        func_002b2d00
    /* 1ADB84 002ADB84 00000000 */   nop
    /* 1ADB88 002ADB88 3C260200 */  dsll32     $4, $2, 24
    /* 1ADB8C 002ADB8C 3F260400 */  dsra32     $4, $4, 24
    /* 1ADB90 002ADB90 2D880000 */  daddu      $17, $0, $0
    /* 1ADB94 002ADB94 3CA61000 */  dsll32     $20, $16, 24
    /* 1ADB98 002ADB98 3FA61400 */  dsra32     $20, $20, 24
    /* 1ADB9C 002ADB9C 3F000010 */  b          .L002ADC9C
    /* 1ADBA0 002ADBA0 00000000 */   nop
  .L002ADBA4:
    /* 1ADBA4 002ADBA4 2D800000 */  daddu      $16, $0, $0
    /* 1ADBA8 002ADBA8 3C9E0400 */  dsll32     $19, $4, 24
    /* 1ADBAC 002ADBAC 3F9E1300 */  dsra32     $19, $19, 24
    /* 1ADBB0 002ADBB0 00AA1300 */  sll        $21, $19, 8
    /* 1ADBB4 002ADBB4 40B01300 */  sll        $22, $19, 1
    /* 1ADBB8 002ADBB8 27000010 */  b          .L002ADC58
    /* 1ADBBC 002ADBBC 00000000 */   nop
  .L002ADBC0:
    /* 1ADBC0 002ADBC0 2D208002 */  daddu      $4, $20, $0
    /* 1ADBC4 002ADBC4 2D284002 */  daddu      $5, $18, $0
    /* 1ADBC8 002ADBC8 10000624 */  addiu      $6, $0, 0x10
    /* 1ADBCC 002ADBCC 2D380000 */  daddu      $7, $0, $0
    /* 1ADBD0 002ADBD0 01000824 */  addiu      $8, $0, 0x1
    /* 1ADBD4 002ADBD4 2CCB0A0C */  jal        func_002b2cb0
    /* 1ADBD8 002ADBD8 00000000 */   nop
    /* 1ADBDC 002ADBDC 00B90200 */  sll        $23, $2, 4
    /* 1ADBE0 002ADBE0 A054050C */  jal        func_00155280
    /* 1ADBE4 002ADBE4 00000000 */   nop
    /* 1ADBE8 002ADBE8 2110A202 */  addu       $2, $21, $2
    /* 1ADBEC 002ADBEC 21105700 */  addu       $2, $2, $23
    /* 1ADBF0 002ADBF0 55004490 */  lbu        $4, 0x55($2)
    /* 1ADBF4 002ADBF4 3CB70A0C */  jal        func_002adcf0
    /* 1ADBF8 002ADBF8 00000000 */   nop
    /* 1ADBFC 002ADBFC 3C1E0200 */  dsll32     $3, $2, 24
    /* 1ADC00 002ADC00 3F1E0300 */  dsra32     $3, $3, 24
    /* 1ADC04 002ADC04 02000224 */  addiu      $2, $0, 0x2
    /* 1ADC08 002ADC08 10006214 */  bne        $3, $2, .L002ADC4C
    /* 1ADC0C 002ADC0C 00000000 */   nop
    /* 1ADC10 002ADC10 2D208002 */  daddu      $4, $20, $0
    /* 1ADC14 002ADC14 2D284002 */  daddu      $5, $18, $0
    /* 1ADC18 002ADC18 10000624 */  addiu      $6, $0, 0x10
    /* 1ADC1C 002ADC1C 2D380000 */  daddu      $7, $0, $0
    /* 1ADC20 002ADC20 01000824 */  addiu      $8, $0, 0x1
    /* 1ADC24 002ADC24 2CCB0A0C */  jal        func_002b2cb0
    /* 1ADC28 002ADC28 00000000 */   nop
    /* 1ADC2C 002ADC2C 01000324 */  addiu      $3, $0, 0x1
    /* 1ADC30 002ADC30 04104300 */  sllv       $2, $3, $2
    /* 1ADC34 002ADC34 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* 1ADC38 002ADC38 68B5828F */  lw         $2, -0x4A98($28)
    /* 1ADC3C 002ADC3C 2118C202 */  addu       $3, $22, $2
    /* 1ADC40 002ADC40 00006294 */  lhu        $2, 0x0($3)
    /* 1ADC44 002ADC44 25104400 */  or         $2, $2, $4
    /* 1ADC48 002ADC48 000062A4 */  sh         $2, 0x0($3)
  .L002ADC4C:
    /* 1ADC4C 002ADC4C 01000226 */  addiu      $2, $16, 0x1
    /* 1ADC50 002ADC50 3C840200 */  dsll32     $16, $2, 16
    /* 1ADC54 002ADC54 3F841000 */  dsra32     $16, $16, 16
  .L002ADC58:
    /* 1ADC58 002ADC58 3C941000 */  dsll32     $18, $16, 16
    /* 1ADC5C 002ADC5C 3F941200 */  dsra32     $18, $18, 16
    /* 1ADC60 002ADC60 0300422A */  slti       $2, $18, 0x3
    /* 1ADC64 002ADC64 D6FF4014 */  bnez       $2, .L002ADBC0
    /* 1ADC68 002ADC68 00000000 */   nop
    /* 1ADC6C 002ADC6C 2D206002 */  daddu      $4, $19, $0
    /* 1ADC70 002ADC70 01000524 */  addiu      $5, $0, 0x1
    /* 1ADC74 002ADC74 18000624 */  addiu      $6, $0, 0x18
    /* 1ADC78 002ADC78 2D380000 */  daddu      $7, $0, $0
    /* 1ADC7C 002ADC7C 2D40A000 */  daddu      $8, $5, $0
    /* 1ADC80 002ADC80 2CCB0A0C */  jal        func_002b2cb0
    /* 1ADC84 002ADC84 00000000 */   nop
    /* 1ADC88 002ADC88 3C260200 */  dsll32     $4, $2, 24
    /* 1ADC8C 002ADC8C 3F260400 */  dsra32     $4, $4, 24
    /* 1ADC90 002ADC90 01002326 */  addiu      $3, $17, 0x1
    /* 1ADC94 002ADC94 3C8C0300 */  dsll32     $17, $3, 16
    /* 1ADC98 002ADC98 3F8C1100 */  dsra32     $17, $17, 16
  .L002ADC9C:
    /* 1ADC9C 002ADC9C 3C1C1100 */  dsll32     $3, $17, 16
    /* 1ADCA0 002ADCA0 3F1C0300 */  dsra32     $3, $3, 16
    /* 1ADCA4 002ADCA4 03006328 */  slti       $3, $3, 0x3
    /* 1ADCA8 002ADCA8 BEFF6014 */  bnez       $3, .L002ADBA4
    /* 1ADCAC 002ADCAC 00000000 */   nop
  .L002ADCB0:
    /* 1ADCB0 002ADCB0 9000BFDF */  ld         $31, 0x90($29)
    /* 1ADCB4 002ADCB4 8000BE7B */  lq         $30, 0x80($29)
    /* 1ADCB8 002ADCB8 7000B77B */  lq         $23, 0x70($29)
    /* 1ADCBC 002ADCBC 6000B67B */  lq         $22, 0x60($29)
    /* 1ADCC0 002ADCC0 5000B57B */  lq         $21, 0x50($29)
    /* 1ADCC4 002ADCC4 4000B47B */  lq         $20, 0x40($29)
    /* 1ADCC8 002ADCC8 3000B37B */  lq         $19, 0x30($29)
    /* 1ADCCC 002ADCCC 2000B27B */  lq         $18, 0x20($29)
    /* 1ADCD0 002ADCD0 1000B17B */  lq         $17, 0x10($29)
    /* 1ADCD4 002ADCD4 0000B07B */  lq         $16, 0x0($29)
    /* 1ADCD8 002ADCD8 9001BD27 */  addiu      $29, $29, 0x190
    /* 1ADCDC 002ADCDC 0800E003 */  jr         $31
    /* 1ADCE0 002ADCE0 00000000 */   nop
    /* 1ADCE4 002ADCE4 00000000 */  nop
    /* 1ADCE8 002ADCE8 00000000 */  nop
    /* 1ADCEC 002ADCEC 00000000 */  nop
.size func_002ac750, 0x15a0
