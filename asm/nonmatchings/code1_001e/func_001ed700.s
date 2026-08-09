.section .text
.set noat
.set noreorder
glabel func_001ed700
    /* ED700 001ED700 00FFBD27 */  addiu      $29, $29, -0x100
    /* ED704 001ED704 A000BFFF */  sd         $31, 0xA0($29)
    /* ED708 001ED708 9000B77F */  sq         $23, 0x90($29)
    /* ED70C 001ED70C 8000B67F */  sq         $22, 0x80($29)
    /* ED710 001ED710 7000B57F */  sq         $21, 0x70($29)
    /* ED714 001ED714 6000B47F */  sq         $20, 0x60($29)
    /* ED718 001ED718 5000B37F */  sq         $19, 0x50($29)
    /* ED71C 001ED71C 4000B27F */  sq         $18, 0x40($29)
    /* ED720 001ED720 3000B17F */  sq         $17, 0x30($29)
    /* ED724 001ED724 2000B07F */  sq         $16, 0x20($29)
    /* ED728 001ED728 1800BAE7 */  swc1       $f26, 0x18($29)
    /* ED72C 001ED72C 1400B9E7 */  swc1       $f25, 0x14($29)
    /* ED730 001ED730 1000B8E7 */  swc1       $f24, 0x10($29)
    /* ED734 001ED734 0C00B7E7 */  swc1       $f23, 0xC($29)
    /* ED738 001ED738 0800B6E7 */  swc1       $f22, 0x8($29)
    /* ED73C 001ED73C 0400B5E7 */  swc1       $f21, 0x4($29)
    /* ED740 001ED740 0000B4E7 */  swc1       $f20, 0x0($29)
    /* ED744 001ED744 86660046 */  mov.s      $f26, $f12
    /* ED748 001ED748 2D300000 */  daddu      $6, $0, $0
    /* ED74C 001ED74C ACB3828F */  lw         $2, -0x4C54($28)
    /* ED750 001ED750 1803428C */  lw         $2, 0x318($2)
    /* ED754 001ED754 01000524 */  addiu      $5, $0, 0x1
    /* ED758 001ED758 50000010 */  b          .L001ED89C
    /* ED75C 001ED75C 00000000 */   nop
  .L001ED760:
    /* ED760 001ED760 1300C014 */  bnez       $6, .L001ED7B0
    /* ED764 001ED764 00000000 */   nop
    /* ED768 001ED768 00004384 */  lh         $3, 0x0($2)
    /* ED76C 001ED76C CC00A3A7 */  sh         $3, 0xCC($29)
    /* ED770 001ED770 C800A3A7 */  sh         $3, 0xC8($29)
    /* ED774 001ED774 C400A3A7 */  sh         $3, 0xC4($29)
    /* ED778 001ED778 C000A3A7 */  sh         $3, 0xC0($29)
    /* ED77C 001ED77C 02004384 */  lh         $3, 0x2($2)
    /* ED780 001ED780 CE00A3A7 */  sh         $3, 0xCE($29)
    /* ED784 001ED784 CA00A3A7 */  sh         $3, 0xCA($29)
    /* ED788 001ED788 C600A3A7 */  sh         $3, 0xC6($29)
    /* ED78C 001ED78C C200A3A7 */  sh         $3, 0xC2($29)
    /* ED790 001ED790 040040C4 */  lwc1       $f0, 0x4($2)
    /* ED794 001ED794 BC00A0E7 */  swc1       $f0, 0xBC($29)
    /* ED798 001ED798 B800A0E7 */  swc1       $f0, 0xB8($29)
    /* ED79C 001ED79C B400A0E7 */  swc1       $f0, 0xB4($29)
    /* ED7A0 001ED7A0 B000A0E7 */  swc1       $f0, 0xB0($29)
    /* ED7A4 001ED7A4 2D30A000 */  daddu      $6, $5, $0
    /* ED7A8 001ED7A8 3B000010 */  b          .L001ED898
    /* ED7AC 001ED7AC 00000000 */   nop
  .L001ED7B0:
    /* ED7B0 001ED7B0 00004884 */  lh         $8, 0x0($2)
    /* ED7B4 001ED7B4 02004784 */  lh         $7, 0x2($2)
    /* ED7B8 001ED7B8 C000A387 */  lh         $3, 0xC0($29)
    /* ED7BC 001ED7BC 2A186800 */  slt        $3, $3, $8
    /* ED7C0 001ED7C0 0B006014 */  bnez       $3, .L001ED7F0
    /* ED7C4 001ED7C4 00000000 */   nop
    /* ED7C8 001ED7C8 C200A487 */  lh         $4, 0xC2($29)
    /* ED7CC 001ED7CC 3C1C0700 */  dsll32     $3, $7, 16
    /* ED7D0 001ED7D0 3F1C0300 */  dsra32     $3, $3, 16
    /* ED7D4 001ED7D4 2A188300 */  slt        $3, $4, $3
    /* ED7D8 001ED7D8 05006014 */  bnez       $3, .L001ED7F0
    /* ED7DC 001ED7DC 00000000 */   nop
    /* ED7E0 001ED7E0 C000A8A7 */  sh         $8, 0xC0($29)
    /* ED7E4 001ED7E4 C200A7A7 */  sh         $7, 0xC2($29)
    /* ED7E8 001ED7E8 040040C4 */  lwc1       $f0, 0x4($2)
    /* ED7EC 001ED7EC B000A0E7 */  swc1       $f0, 0xB0($29)
  .L001ED7F0:
    /* ED7F0 001ED7F0 C400A387 */  lh         $3, 0xC4($29)
    /* ED7F4 001ED7F4 2A080301 */  slt        $1, $8, $3
    /* ED7F8 001ED7F8 0B002014 */  bnez       $1, .L001ED828
    /* ED7FC 001ED7FC 00000000 */   nop
    /* ED800 001ED800 C600A487 */  lh         $4, 0xC6($29)
    /* ED804 001ED804 3C1C0700 */  dsll32     $3, $7, 16
    /* ED808 001ED808 3F1C0300 */  dsra32     $3, $3, 16
    /* ED80C 001ED80C 2A188300 */  slt        $3, $4, $3
    /* ED810 001ED810 05006014 */  bnez       $3, .L001ED828
    /* ED814 001ED814 00000000 */   nop
    /* ED818 001ED818 C400A8A7 */  sh         $8, 0xC4($29)
    /* ED81C 001ED81C C600A7A7 */  sh         $7, 0xC6($29)
    /* ED820 001ED820 040040C4 */  lwc1       $f0, 0x4($2)
    /* ED824 001ED824 B400A0E7 */  swc1       $f0, 0xB4($29)
  .L001ED828:
    /* ED828 001ED828 C800A387 */  lh         $3, 0xC8($29)
    /* ED82C 001ED82C 2A080301 */  slt        $1, $8, $3
    /* ED830 001ED830 0B002014 */  bnez       $1, .L001ED860
    /* ED834 001ED834 00000000 */   nop
    /* ED838 001ED838 CA00A487 */  lh         $4, 0xCA($29)
    /* ED83C 001ED83C 3C1C0700 */  dsll32     $3, $7, 16
    /* ED840 001ED840 3F1C0300 */  dsra32     $3, $3, 16
    /* ED844 001ED844 2A086400 */  slt        $1, $3, $4
    /* ED848 001ED848 05002014 */  bnez       $1, .L001ED860
    /* ED84C 001ED84C 00000000 */   nop
    /* ED850 001ED850 C800A8A7 */  sh         $8, 0xC8($29)
    /* ED854 001ED854 CA00A7A7 */  sh         $7, 0xCA($29)
    /* ED858 001ED858 040040C4 */  lwc1       $f0, 0x4($2)
    /* ED85C 001ED85C B800A0E7 */  swc1       $f0, 0xB8($29)
  .L001ED860:
    /* ED860 001ED860 CC00A387 */  lh         $3, 0xCC($29)
    /* ED864 001ED864 2A186800 */  slt        $3, $3, $8
    /* ED868 001ED868 0B006014 */  bnez       $3, .L001ED898
    /* ED86C 001ED86C 00000000 */   nop
    /* ED870 001ED870 CE00A487 */  lh         $4, 0xCE($29)
    /* ED874 001ED874 3C1C0700 */  dsll32     $3, $7, 16
    /* ED878 001ED878 3F1C0300 */  dsra32     $3, $3, 16
    /* ED87C 001ED87C 2A086400 */  slt        $1, $3, $4
    /* ED880 001ED880 05002014 */  bnez       $1, .L001ED898
    /* ED884 001ED884 00000000 */   nop
    /* ED888 001ED888 CC00A8A7 */  sh         $8, 0xCC($29)
    /* ED88C 001ED88C CE00A7A7 */  sh         $7, 0xCE($29)
    /* ED890 001ED890 040040C4 */  lwc1       $f0, 0x4($2)
    /* ED894 001ED894 BC00A0E7 */  swc1       $f0, 0xBC($29)
  .L001ED898:
    /* ED898 001ED898 CC04428C */  lw         $2, 0x4CC($2)
  .L001ED89C:
    /* ED89C 001ED89C B0FF4014 */  bnez       $2, .L001ED760
    /* ED8A0 001ED8A0 00000000 */   nop
    /* ED8A4 001ED8A4 2D480000 */  daddu      $9, $0, $0
    /* ED8A8 001ED8A8 01000324 */  addiu      $3, $0, 0x1
    /* ED8AC 001ED8AC 02000424 */  addiu      $4, $0, 0x2
    /* ED8B0 001ED8B0 FA43023C */  lui        $2, (0x43FA0000 >> 16)
    /* ED8B4 001ED8B4 00088244 */  mtc1       $2, $f1
    /* ED8B8 001ED8B8 19000624 */  addiu      $6, $0, 0x19
    /* ED8BC 001ED8BC 03000524 */  addiu      $5, $0, 0x3
    /* ED8C0 001ED8C0 85000010 */  b          .L001EDAD8
    /* ED8C4 001ED8C4 00000000 */   nop
  .L001ED8C8:
    /* ED8C8 001ED8C8 80100900 */  sll        $2, $9, 2
    /* ED8CC 001ED8CC 21105D00 */  addu       $2, $2, $29
    /* ED8D0 001ED8D0 B00040C4 */  lwc1       $f0, 0xB0($2)
    /* ED8D4 001ED8D4 00080046 */  add.s      $f0, $f1, $f0
    /* ED8D8 001ED8D8 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* ED8DC 001ED8DC 00000A44 */  mfc1       $10, $f0
    /* ED8E0 001ED8E0 00000000 */  nop
    /* ED8E4 001ED8E4 1A004601 */  div        $0, $10, $6
    /* ED8E8 001ED8E8 12100000 */  mflo       $2
    /* ED8EC 001ED8EC 3C5C0200 */  dsll32     $11, $2, 16
    /* ED8F0 001ED8F0 3F5C0B00 */  dsra32     $11, $11, 16
    /* ED8F4 001ED8F4 1A004601 */  div        $0, $10, $6
    /* ED8F8 001ED8F8 10100000 */  mfhi       $2
    /* ED8FC 001ED8FC 04004010 */  beqz       $2, .L001ED910
    /* ED900 001ED900 00000000 */   nop
    /* ED904 001ED904 01006225 */  addiu      $2, $11, 0x1
    /* ED908 001ED908 3C5C0200 */  dsll32     $11, $2, 16
    /* ED90C 001ED90C 3F5C0B00 */  dsra32     $11, $11, 16
  .L001ED910:
    /* ED910 001ED910 41002511 */  beq        $9, $5, .L001EDA18
    /* ED914 001ED914 00000000 */   nop
    /* ED918 001ED918 30002411 */  beq        $9, $4, .L001ED9DC
    /* ED91C 001ED91C 00000000 */   nop
    /* ED920 001ED920 1C002311 */  beq        $9, $3, .L001ED994
    /* ED924 001ED924 00000000 */   nop
    /* ED928 001ED928 03002011 */  beqz       $9, .L001ED938
    /* ED92C 001ED92C 00000000 */   nop
    /* ED930 001ED930 49000010 */  b          .L001EDA58
    /* ED934 001ED934 00000000 */   nop
  .L001ED938:
    /* ED938 001ED938 80100900 */  sll        $2, $9, 2
    /* ED93C 001ED93C 21105D00 */  addu       $2, $2, $29
    /* ED940 001ED940 C0004A24 */  addiu      $10, $2, 0xC0
    /* ED944 001ED944 3C3C0B00 */  dsll32     $7, $11, 16
    /* ED948 001ED948 3F3C0700 */  dsra32     $7, $7, 16
    /* ED94C 001ED94C 00004285 */  lh         $2, 0x0($10)
    /* ED950 001ED950 23104700 */  subu       $2, $2, $7
    /* ED954 001ED954 3C440200 */  dsll32     $8, $2, 16
    /* ED958 001ED958 3F440800 */  dsra32     $8, $8, 16
    /* ED95C 001ED95C 02004285 */  lh         $2, 0x2($10)
    /* ED960 001ED960 23104700 */  subu       $2, $2, $7
    /* ED964 001ED964 3C3C0200 */  dsll32     $7, $2, 16
    /* ED968 001ED968 3F3C0700 */  dsra32     $7, $7, 16
    /* ED96C 001ED96C 02000105 */  bgez       $8, .L001ED978
    /* ED970 001ED970 00000000 */   nop
    /* ED974 001ED974 2D400000 */  daddu      $8, $0, $0
  .L001ED978:
    /* ED978 001ED978 3C140700 */  dsll32     $2, $7, 16
    /* ED97C 001ED97C 3F140200 */  dsra32     $2, $2, 16
    /* ED980 001ED980 35004104 */  bgez       $2, .L001EDA58
    /* ED984 001ED984 00000000 */   nop
    /* ED988 001ED988 2D380000 */  daddu      $7, $0, $0
    /* ED98C 001ED98C 32000010 */  b          .L001EDA58
    /* ED990 001ED990 00000000 */   nop
  .L001ED994:
    /* ED994 001ED994 80100900 */  sll        $2, $9, 2
    /* ED998 001ED998 21105D00 */  addu       $2, $2, $29
    /* ED99C 001ED99C C0004A24 */  addiu      $10, $2, 0xC0
    /* ED9A0 001ED9A0 3C3C0B00 */  dsll32     $7, $11, 16
    /* ED9A4 001ED9A4 3F3C0700 */  dsra32     $7, $7, 16
    /* ED9A8 001ED9A8 00004285 */  lh         $2, 0x0($10)
    /* ED9AC 001ED9AC 2110E200 */  addu       $2, $7, $2
    /* ED9B0 001ED9B0 3C440200 */  dsll32     $8, $2, 16
    /* ED9B4 001ED9B4 3F440800 */  dsra32     $8, $8, 16
    /* ED9B8 001ED9B8 02004285 */  lh         $2, 0x2($10)
    /* ED9BC 001ED9BC 23104700 */  subu       $2, $2, $7
    /* ED9C0 001ED9C0 3C3C0200 */  dsll32     $7, $2, 16
    /* ED9C4 001ED9C4 3F3C0700 */  dsra32     $7, $7, 16
    /* ED9C8 001ED9C8 2300E104 */  bgez       $7, .L001EDA58
    /* ED9CC 001ED9CC 00000000 */   nop
    /* ED9D0 001ED9D0 2D380000 */  daddu      $7, $0, $0
    /* ED9D4 001ED9D4 20000010 */  b          .L001EDA58
    /* ED9D8 001ED9D8 00000000 */   nop
  .L001ED9DC:
    /* ED9DC 001ED9DC 80100900 */  sll        $2, $9, 2
    /* ED9E0 001ED9E0 21105D00 */  addu       $2, $2, $29
    /* ED9E4 001ED9E4 C0004A24 */  addiu      $10, $2, 0xC0
    /* ED9E8 001ED9E8 3C3C0B00 */  dsll32     $7, $11, 16
    /* ED9EC 001ED9EC 3F3C0700 */  dsra32     $7, $7, 16
    /* ED9F0 001ED9F0 00004285 */  lh         $2, 0x0($10)
    /* ED9F4 001ED9F4 2110E200 */  addu       $2, $7, $2
    /* ED9F8 001ED9F8 3C440200 */  dsll32     $8, $2, 16
    /* ED9FC 001ED9FC 3F440800 */  dsra32     $8, $8, 16
    /* EDA00 001EDA00 02004285 */  lh         $2, 0x2($10)
    /* EDA04 001EDA04 2110E200 */  addu       $2, $7, $2
    /* EDA08 001EDA08 3C3C0200 */  dsll32     $7, $2, 16
    /* EDA0C 001EDA0C 3F3C0700 */  dsra32     $7, $7, 16
    /* EDA10 001EDA10 11000010 */  b          .L001EDA58
    /* EDA14 001EDA14 00000000 */   nop
  .L001EDA18:
    /* EDA18 001EDA18 80100900 */  sll        $2, $9, 2
    /* EDA1C 001EDA1C 21105D00 */  addu       $2, $2, $29
    /* EDA20 001EDA20 C0004A24 */  addiu      $10, $2, 0xC0
    /* EDA24 001EDA24 3C3C0B00 */  dsll32     $7, $11, 16
    /* EDA28 001EDA28 3F3C0700 */  dsra32     $7, $7, 16
    /* EDA2C 001EDA2C 00004285 */  lh         $2, 0x0($10)
    /* EDA30 001EDA30 23104700 */  subu       $2, $2, $7
    /* EDA34 001EDA34 3C440200 */  dsll32     $8, $2, 16
    /* EDA38 001EDA38 3F440800 */  dsra32     $8, $8, 16
    /* EDA3C 001EDA3C 02004285 */  lh         $2, 0x2($10)
    /* EDA40 001EDA40 2110E200 */  addu       $2, $7, $2
    /* EDA44 001EDA44 3C3C0200 */  dsll32     $7, $2, 16
    /* EDA48 001EDA48 3F3C0700 */  dsra32     $7, $7, 16
    /* EDA4C 001EDA4C 02000105 */  bgez       $8, .L001EDA58
    /* EDA50 001EDA50 00000000 */   nop
    /* EDA54 001EDA54 2D400000 */  daddu      $8, $0, $0
  .L001EDA58:
    /* EDA58 001EDA58 C0100900 */  sll        $2, $9, 3
    /* EDA5C 001EDA5C 21104900 */  addu       $2, $2, $9
    /* EDA60 001EDA60 40100200 */  sll        $2, $2, 1
    /* EDA64 001EDA64 21104900 */  addu       $2, $2, $9
    /* EDA68 001EDA68 00110200 */  sll        $2, $2, 4
    /* EDA6C 001EDA6C 3C5C0800 */  dsll32     $11, $8, 16
    /* EDA70 001EDA70 3F5C0B00 */  dsra32     $11, $11, 16
    /* EDA74 001EDA74 80500B00 */  sll        $10, $11, 2
    /* EDA78 001EDA78 21584B01 */  addu       $11, $10, $11
    /* EDA7C 001EDA7C 80500B00 */  sll        $10, $11, 2
    /* EDA80 001EDA80 21506A01 */  addu       $10, $11, $10
    /* EDA84 001EDA84 2AF94A25 */  addiu      $10, $10, -0x6D6
    /* EDA88 001EDA88 00008A44 */  mtc1       $10, $f0
    /* EDA8C 001EDA8C 00000000 */  nop
    /* EDA90 001EDA90 20008046 */  cvt.s.w    $f0, $f0
    /* EDA94 001EDA94 ACB38A8F */  lw         $10, -0x4C54($28)
    /* EDA98 001EDA98 21504201 */  addu       $10, $10, $2
    /* EDA9C 001EDA9C 1C0340E5 */  swc1       $f0, 0x31C($10)
    /* EDAA0 001EDAA0 3C5C0700 */  dsll32     $11, $7, 16
    /* EDAA4 001EDAA4 3F5C0B00 */  dsra32     $11, $11, 16
    /* EDAA8 001EDAA8 80500B00 */  sll        $10, $11, 2
    /* EDAAC 001EDAAC 21584B01 */  addu       $11, $10, $11
    /* EDAB0 001EDAB0 80500B00 */  sll        $10, $11, 2
    /* EDAB4 001EDAB4 21506A01 */  addu       $10, $11, $10
    /* EDAB8 001EDAB8 2AF94A25 */  addiu      $10, $10, -0x6D6
    /* EDABC 001EDABC 00008A44 */  mtc1       $10, $f0
    /* EDAC0 001EDAC0 00000000 */  nop
    /* EDAC4 001EDAC4 20008046 */  cvt.s.w    $f0, $f0
    /* EDAC8 001EDAC8 ACB38A8F */  lw         $10, -0x4C54($28)
    /* EDACC 001EDACC 21104201 */  addu       $2, $10, $2
    /* EDAD0 001EDAD0 200340E4 */  swc1       $f0, 0x320($2)
    /* EDAD4 001EDAD4 01002925 */  addiu      $9, $9, 0x1
  .L001EDAD8:
    /* EDAD8 001EDAD8 04002229 */  slti       $2, $9, 0x4
    /* EDADC 001EDADC 7AFF4014 */  bnez       $2, .L001ED8C8
    /* EDAE0 001EDAE0 00000000 */   nop
    /* EDAE4 001EDAE4 ACB3828F */  lw         $2, -0x4C54($28)
    /* EDAE8 001EDAE8 1803518C */  lw         $17, 0x318($2)
    /* EDAEC 001EDAEC E3000010 */  b          .L001EDE7C
    /* EDAF0 001EDAF0 00000000 */   nop
  .L001EDAF4:
    /* EDAF4 001EDAF4 2D800000 */  daddu      $16, $0, $0
    /* EDAF8 001EDAF8 DC000010 */  b          .L001EDE6C
    /* EDAFC 001EDAFC 00000000 */   nop
  .L001EDB00:
    /* EDB00 001EDB00 2DA80000 */  daddu      $21, $0, $0
    /* EDB04 001EDB04 581B0224 */  addiu      $2, $0, 0x1B58
    /* EDB08 001EDB08 00008244 */  mtc1       $2, $f0
    /* EDB0C 001EDB0C 00000000 */  nop
    /* EDB10 001EDB10 20068046 */  cvt.s.w    $f24, $f0
    /* EDB14 001EDB14 C0181000 */  sll        $3, $16, 3
    /* EDB18 001EDB18 21107000 */  addu       $2, $3, $16
    /* EDB1C 001EDB1C 40100200 */  sll        $2, $2, 1
    /* EDB20 001EDB20 21105000 */  addu       $2, $2, $16
    /* EDB24 001EDB24 00110200 */  sll        $2, $2, 4
    /* EDB28 001EDB28 21902202 */  addu       $18, $17, $2
    /* EDB2C 001EDB2C 080041C6 */  lwc1       $f1, 0x8($18)
    /* EDB30 001EDB30 0C0040C6 */  lwc1       $f0, 0xC($18)
    /* EDB34 001EDB34 F800A1E7 */  swc1       $f1, 0xF8($29)
    /* EDB38 001EDB38 FC00A0E7 */  swc1       $f0, 0xFC($29)
    /* EDB3C 001EDB3C ACB3828F */  lw         $2, -0x4C54($28)
    /* EDB40 001EDB40 1803548C */  lw         $20, 0x318($2)
    /* EDB44 001EDB44 FC00B5C7 */  lwc1       $f21, 0xFC($29)
    /* EDB48 001EDB48 6100023C */  lui        $2, %hi(D_0060A120)
    /* EDB4C 001EDB4C 20A14224 */  addiu      $2, $2, %lo(D_0060A120)
    /* EDB50 001EDB50 21B04300 */  addu       $22, $2, $3
    /* EDB54 001EDB54 48000010 */  b          .L001EDC78
    /* EDB58 001EDB58 00000000 */   nop
  .L001EDB5C:
    /* EDB5C 001EDB5C 45003412 */  beq        $17, $20, .L001EDC74
    /* EDB60 001EDB60 00000000 */   nop
    /* EDB64 001EDB64 2D980000 */  daddu      $19, $0, $0
    /* EDB68 001EDB68 3F000010 */  b          .L001EDC68
    /* EDB6C 001EDB6C 00000000 */   nop
  .L001EDB70:
    /* EDB70 001EDB70 C0101300 */  sll        $2, $19, 3
    /* EDB74 001EDB74 21105300 */  addu       $2, $2, $19
    /* EDB78 001EDB78 40100200 */  sll        $2, $2, 1
    /* EDB7C 001EDB7C 21105300 */  addu       $2, $2, $19
    /* EDB80 001EDB80 00110200 */  sll        $2, $2, 4
    /* EDB84 001EDB84 21B88202 */  addu       $23, $20, $2
    /* EDB88 001EDB88 0800E1C6 */  lwc1       $f1, 0x8($23)
    /* EDB8C 001EDB8C F800A0C7 */  lwc1       $f0, 0xF8($29)
    /* EDB90 001EDB90 01080046 */  sub.s      $f0, $f1, $f0
    /* EDB94 001EDB94 E800A0E7 */  swc1       $f0, 0xE8($29)
    /* EDB98 001EDB98 0C00E0C6 */  lwc1       $f0, 0xC($23)
    /* EDB9C 001EDB9C 01001546 */  sub.s      $f0, $f0, $f21
    /* EDBA0 001EDBA0 EC00A0E7 */  swc1       $f0, 0xEC($29)
    /* EDBA4 001EDBA4 F000A427 */  addiu      $4, $29, 0xF0
    /* EDBA8 001EDBA8 E800A527 */  addiu      $5, $29, 0xE8
    /* EDBAC 001EDBAC 78900F0C */  jal        func_003e41e0
    /* EDBB0 001EDBB0 00000000 */   nop
    /* EDBB4 001EDBB4 06050046 */  mov.s      $f20, $f0
    /* EDBB8 001EDBB8 F000A3C7 */  lwc1       $f3, 0xF0($29)
    /* EDBBC 001EDBBC 0000C2C6 */  lwc1       $f2, 0x0($22)
    /* EDBC0 001EDBC0 F400A1C7 */  lwc1       $f1, 0xF4($29)
    /* EDBC4 001EDBC4 0400C0C6 */  lwc1       $f0, 0x4($22)
    /* EDBC8 001EDBC8 1A080046 */  mula.s     $f1, $f0
    /* EDBCC 001EDBCC 5C180246 */  madd.s     $f1, $f3, $f2
    /* EDBD0 001EDBD0 308380C7 */  lwc1       $f0, -0x7CD0($28)
    /* EDBD4 001EDBD4 36080046 */  c.le.s     $f1, $f0
    /* EDBD8 001EDBD8 22000145 */  bc1t       .L001EDC64
    /* EDBDC 001EDBDC 00000000 */   nop
    /* EDBE0 001EDBE0 34A01846 */  c.lt.s     $f20, $f24
    /* EDBE4 001EDBE4 1F000045 */  bc1f       .L001EDC64
    /* EDBE8 001EDBE8 00000000 */   nop
    /* EDBEC 001EDBEC 0800F726 */  addiu      $23, $23, 0x8
    /* EDBF0 001EDBF0 08004426 */  addiu      $4, $18, 0x8
    /* EDBF4 001EDBF4 2D28E002 */  daddu      $5, $23, $0
    /* EDBF8 001EDBF8 18B4070C */  jal        func_001ed060
    /* EDBFC 001EDBFC 00000000 */   nop
    /* EDC00 001EDC00 18004014 */  bnez       $2, .L001EDC64
    /* EDC04 001EDC04 00000000 */   nop
    /* EDC08 001EDC08 F000A2DF */  ld         $2, 0xF0($29)
    /* EDC0C 001EDC0C E000A2FF */  sd         $2, 0xE0($29)
    /* EDC10 001EDC10 2DA8E002 */  daddu      $21, $23, $0
    /* EDC14 001EDC14 06A60046 */  mov.s      $f24, $f20
    /* EDC18 001EDC18 00008386 */  lh         $3, 0x0($20)
    /* EDC1C 001EDC1C 80100300 */  sll        $2, $3, 2
    /* EDC20 001EDC20 21184300 */  addu       $3, $2, $3
    /* EDC24 001EDC24 80100300 */  sll        $2, $3, 2
    /* EDC28 001EDC28 21106200 */  addu       $2, $3, $2
    /* EDC2C 001EDC2C 2AF94224 */  addiu      $2, $2, -0x6D6
    /* EDC30 001EDC30 00008244 */  mtc1       $2, $f0
    /* EDC34 001EDC34 00000000 */  nop
    /* EDC38 001EDC38 E0058046 */  cvt.s.w    $f23, $f0
    /* EDC3C 001EDC3C 02008386 */  lh         $3, 0x2($20)
    /* EDC40 001EDC40 80100300 */  sll        $2, $3, 2
    /* EDC44 001EDC44 21184300 */  addu       $3, $2, $3
    /* EDC48 001EDC48 80100300 */  sll        $2, $3, 2
    /* EDC4C 001EDC4C 21106200 */  addu       $2, $3, $2
    /* EDC50 001EDC50 2AF94224 */  addiu      $2, $2, -0x6D6
    /* EDC54 001EDC54 00008244 */  mtc1       $2, $f0
    /* EDC58 001EDC58 00000000 */  nop
    /* EDC5C 001EDC5C A0058046 */  cvt.s.w    $f22, $f0
    /* EDC60 001EDC60 040099C6 */  lwc1       $f25, 0x4($20)
  .L001EDC64:
    /* EDC64 001EDC64 01007326 */  addiu      $19, $19, 0x1
  .L001EDC68:
    /* EDC68 001EDC68 0400622A */  slti       $2, $19, 0x4
    /* EDC6C 001EDC6C C0FF4014 */  bnez       $2, .L001EDB70
    /* EDC70 001EDC70 00000000 */   nop
  .L001EDC74:
    /* EDC74 001EDC74 CC04948E */  lw         $20, 0x4CC($20)
  .L001EDC78:
    /* EDC78 001EDC78 B8FF8016 */  bnez       $20, .L001EDB5C
    /* EDC7C 001EDC7C 00000000 */   nop
    /* EDC80 001EDC80 2D980000 */  daddu      $19, $0, $0
    /* EDC84 001EDC84 38000010 */  b          .L001EDD68
    /* EDC88 001EDC88 00000000 */   nop
  .L001EDC8C:
    /* EDC8C 001EDC8C ACB3838F */  lw         $3, -0x4C54($28)
    /* EDC90 001EDC90 C0101300 */  sll        $2, $19, 3
    /* EDC94 001EDC94 21105300 */  addu       $2, $2, $19
    /* EDC98 001EDC98 40100200 */  sll        $2, $2, 1
    /* EDC9C 001EDC9C 21105300 */  addu       $2, $2, $19
    /* EDCA0 001EDCA0 00A10200 */  sll        $20, $2, 4
    /* EDCA4 001EDCA4 21107400 */  addu       $2, $3, $20
    /* EDCA8 001EDCA8 1C0341C4 */  lwc1       $f1, 0x31C($2)
    /* EDCAC 001EDCAC F800A0C7 */  lwc1       $f0, 0xF8($29)
    /* EDCB0 001EDCB0 01080046 */  sub.s      $f0, $f1, $f0
    /* EDCB4 001EDCB4 E800A0E7 */  swc1       $f0, 0xE8($29)
    /* EDCB8 001EDCB8 200340C4 */  lwc1       $f0, 0x320($2)
    /* EDCBC 001EDCBC 01001546 */  sub.s      $f0, $f0, $f21
    /* EDCC0 001EDCC0 EC00A0E7 */  swc1       $f0, 0xEC($29)
    /* EDCC4 001EDCC4 F000A427 */  addiu      $4, $29, 0xF0
    /* EDCC8 001EDCC8 E800A527 */  addiu      $5, $29, 0xE8
    /* EDCCC 001EDCCC 78900F0C */  jal        func_003e41e0
    /* EDCD0 001EDCD0 00000000 */   nop
    /* EDCD4 001EDCD4 06050046 */  mov.s      $f20, $f0
    /* EDCD8 001EDCD8 F000A3C7 */  lwc1       $f3, 0xF0($29)
    /* EDCDC 001EDCDC 0000C2C6 */  lwc1       $f2, 0x0($22)
    /* EDCE0 001EDCE0 F400A1C7 */  lwc1       $f1, 0xF4($29)
    /* EDCE4 001EDCE4 0400C0C6 */  lwc1       $f0, 0x4($22)
    /* EDCE8 001EDCE8 1A080046 */  mula.s     $f1, $f0
    /* EDCEC 001EDCEC 5C180246 */  madd.s     $f1, $f3, $f2
    /* EDCF0 001EDCF0 308380C7 */  lwc1       $f0, -0x7CD0($28)
    /* EDCF4 001EDCF4 36080046 */  c.le.s     $f1, $f0
    /* EDCF8 001EDCF8 1A000145 */  bc1t       .L001EDD64
    /* EDCFC 001EDCFC 00000000 */   nop
    /* EDD00 001EDD00 34A01846 */  c.lt.s     $f20, $f24
    /* EDD04 001EDD04 17000045 */  bc1f       .L001EDD64
    /* EDD08 001EDD08 00000000 */   nop
    /* EDD0C 001EDD0C ACB3828F */  lw         $2, -0x4C54($28)
    /* EDD10 001EDD10 21105400 */  addu       $2, $2, $20
    /* EDD14 001EDD14 08004426 */  addiu      $4, $18, 0x8
    /* EDD18 001EDD18 1C034524 */  addiu      $5, $2, 0x31C
    /* EDD1C 001EDD1C 18B4070C */  jal        func_001ed060
    /* EDD20 001EDD20 00000000 */   nop
    /* EDD24 001EDD24 0F004014 */  bnez       $2, .L001EDD64
    /* EDD28 001EDD28 00000000 */   nop
    /* EDD2C 001EDD2C F000A2DF */  ld         $2, 0xF0($29)
    /* EDD30 001EDD30 E000A2FF */  sd         $2, 0xE0($29)
    /* EDD34 001EDD34 C0101300 */  sll        $2, $19, 3
    /* EDD38 001EDD38 21105300 */  addu       $2, $2, $19
    /* EDD3C 001EDD3C 40100200 */  sll        $2, $2, 1
    /* EDD40 001EDD40 21105300 */  addu       $2, $2, $19
    /* EDD44 001EDD44 00190200 */  sll        $3, $2, 4
    /* EDD48 001EDD48 ACB3828F */  lw         $2, -0x4C54($28)
    /* EDD4C 001EDD4C 21104300 */  addu       $2, $2, $3
    /* EDD50 001EDD50 1C035524 */  addiu      $21, $2, 0x31C
    /* EDD54 001EDD54 06A60046 */  mov.s      $f24, $f20
    /* EDD58 001EDD58 1C0357C4 */  lwc1       $f23, 0x31C($2)
    /* EDD5C 001EDD5C 200356C4 */  lwc1       $f22, 0x320($2)
    /* EDD60 001EDD60 00C88044 */  mtc1       $0, $f25
  .L001EDD64:
    /* EDD64 001EDD64 01007326 */  addiu      $19, $19, 0x1
  .L001EDD68:
    /* EDD68 001EDD68 0400622A */  slti       $2, $19, 0x4
    /* EDD6C 001EDD6C C7FF4014 */  bnez       $2, .L001EDC8C
    /* EDD70 001EDD70 00000000 */   nop
    /* EDD74 001EDD74 3A00A012 */  beqz       $21, .L001EDE60
    /* EDD78 001EDD78 00000000 */   nop
    /* EDD7C 001EDD7C 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* EDD80 001EDD80 00008244 */  mtc1       $2, $f0
    /* EDD84 001EDD84 00000000 */  nop
    /* EDD88 001EDD88 82001846 */  mul.s      $f2, $f0, $f24
    /* EDD8C 001EDD8C E000A0C7 */  lwc1       $f0, 0xE0($29)
    /* EDD90 001EDD90 42000246 */  mul.s      $f1, $f0, $f2
    /* EDD94 001EDD94 E000A1E7 */  swc1       $f1, 0xE0($29)
    /* EDD98 001EDD98 E400A0C7 */  lwc1       $f0, 0xE4($29)
    /* EDD9C 001EDD9C 02000246 */  mul.s      $f0, $f0, $f2
    /* EDDA0 001EDDA0 E400A0E7 */  swc1       $f0, 0xE4($29)
    /* EDDA4 001EDDA4 C0101000 */  sll        $2, $16, 3
    /* EDDA8 001EDDA8 21105000 */  addu       $2, $2, $16
    /* EDDAC 001EDDAC 40100200 */  sll        $2, $2, 1
    /* EDDB0 001EDDB0 21105000 */  addu       $2, $2, $16
    /* EDDB4 001EDDB4 00110200 */  sll        $2, $2, 4
    /* EDDB8 001EDDB8 21902202 */  addu       $18, $17, $2
    /* EDDBC 001EDDBC F800A0C7 */  lwc1       $f0, 0xF8($29)
    /* EDDC0 001EDDC0 00000146 */  add.s      $f0, $f0, $f1
    /* EDDC4 001EDDC4 100040E6 */  swc1       $f0, 0x10($18)
    /* EDDC8 001EDDC8 E400A0C7 */  lwc1       $f0, 0xE4($29)
    /* EDDCC 001EDDCC 00A80046 */  add.s      $f0, $f21, $f0
    /* EDDD0 001EDDD0 140040E6 */  swc1       $f0, 0x14($18)
    /* EDDD4 001EDDD4 180055AE */  sw         $21, 0x18($18)
    /* EDDD8 001EDDD8 1C0058E6 */  swc1       $f24, 0x1C($18)
    /* EDDDC 001EDDDC 00002386 */  lh         $3, 0x0($17)
    /* EDDE0 001EDDE0 80100300 */  sll        $2, $3, 2
    /* EDDE4 001EDDE4 21184300 */  addu       $3, $2, $3
    /* EDDE8 001EDDE8 80100300 */  sll        $2, $3, 2
    /* EDDEC 001EDDEC 21106200 */  addu       $2, $3, $2
    /* EDDF0 001EDDF0 2AF94224 */  addiu      $2, $2, -0x6D6
    /* EDDF4 001EDDF4 00008244 */  mtc1       $2, $f0
    /* EDDF8 001EDDF8 00000000 */  nop
    /* EDDFC 001EDDFC A0008046 */  cvt.s.w    $f2, $f0
    /* EDE00 001EDE00 E800A2E7 */  swc1       $f2, 0xE8($29)
    /* EDE04 001EDE04 02002386 */  lh         $3, 0x2($17)
    /* EDE08 001EDE08 80100300 */  sll        $2, $3, 2
    /* EDE0C 001EDE0C 21184300 */  addu       $3, $2, $3
    /* EDE10 001EDE10 80100300 */  sll        $2, $3, 2
    /* EDE14 001EDE14 21106200 */  addu       $2, $3, $2
    /* EDE18 001EDE18 2AF94224 */  addiu      $2, $2, -0x6D6
    /* EDE1C 001EDE1C 00008244 */  mtc1       $2, $f0
    /* EDE20 001EDE20 00000000 */  nop
    /* EDE24 001EDE24 60008046 */  cvt.s.w    $f1, $f0
    /* EDE28 001EDE28 EC00A1E7 */  swc1       $f1, 0xEC($29)
    /* EDE2C 001EDE2C 01101746 */  sub.s      $f0, $f2, $f23
    /* EDE30 001EDE30 E800A0E7 */  swc1       $f0, 0xE8($29)
    /* EDE34 001EDE34 01081646 */  sub.s      $f0, $f1, $f22
    /* EDE38 001EDE38 EC00A0E7 */  swc1       $f0, 0xEC($29)
    /* EDE3C 001EDE3C E800A427 */  addiu      $4, $29, 0xE8
    /* EDE40 001EDE40 6C900F0C */  jal        func_003e41b0
    /* EDE44 001EDE44 00000000 */   nop
    /* EDE48 001EDE48 040021C6 */  lwc1       $f1, 0x4($17)
    /* EDE4C 001EDE4C 40081946 */  add.s      $f1, $f1, $f25
    /* EDE50 001EDE50 01000146 */  sub.s      $f0, $f0, $f1
    /* EDE54 001EDE54 200040E6 */  swc1       $f0, 0x20($18)
    /* EDE58 001EDE58 03000010 */  b          .L001EDE68
    /* EDE5C 001EDE5C 00000000 */   nop
  .L001EDE60:
    /* EDE60 001EDE60 80BF023C */  lui        $2, (0xBF800000 >> 16)
    /* EDE64 001EDE64 1C0042AE */  sw         $2, 0x1C($18)
  .L001EDE68:
    /* EDE68 001EDE68 01001026 */  addiu      $16, $16, 0x1
  .L001EDE6C:
    /* EDE6C 001EDE6C 0400022A */  slti       $2, $16, 0x4
    /* EDE70 001EDE70 23FF4014 */  bnez       $2, .L001EDB00
    /* EDE74 001EDE74 00000000 */   nop
    /* EDE78 001EDE78 CC04318E */  lw         $17, 0x4CC($17)
  .L001EDE7C:
    /* EDE7C 001EDE7C 1DFF2016 */  bnez       $17, .L001EDAF4
    /* EDE80 001EDE80 00000000 */   nop
    /* EDE84 001EDE84 2DA00000 */  daddu      $20, $0, $0
    /* EDE88 001EDE88 6D000010 */  b          .L001EE040
    /* EDE8C 001EDE8C 00000000 */   nop
  .L001EDE90:
    /* EDE90 001EDE90 2D980000 */  daddu      $19, $0, $0
    /* EDE94 001EDE94 581B0224 */  addiu      $2, $0, 0x1B58
    /* EDE98 001EDE98 00008244 */  mtc1       $2, $f0
    /* EDE9C 001EDE9C 00000000 */  nop
    /* EDEA0 001EDEA0 20058046 */  cvt.s.w    $f20, $f0
    /* EDEA4 001EDEA4 ACB3838F */  lw         $3, -0x4C54($28)
    /* EDEA8 001EDEA8 C0101400 */  sll        $2, $20, 3
    /* EDEAC 001EDEAC 21105400 */  addu       $2, $2, $20
    /* EDEB0 001EDEB0 40100200 */  sll        $2, $2, 1
    /* EDEB4 001EDEB4 21105400 */  addu       $2, $2, $20
    /* EDEB8 001EDEB8 00810200 */  sll        $16, $2, 4
    /* EDEBC 001EDEBC 21107000 */  addu       $2, $3, $16
    /* EDEC0 001EDEC0 1C0341C4 */  lwc1       $f1, 0x31C($2)
    /* EDEC4 001EDEC4 200340C4 */  lwc1       $f0, 0x320($2)
    /* EDEC8 001EDEC8 D800A1E7 */  swc1       $f1, 0xD8($29)
    /* EDECC 001EDECC DC00A0E7 */  swc1       $f0, 0xDC($29)
    /* EDED0 001EDED0 1803728C */  lw         $18, 0x318($3)
    /* EDED4 001EDED4 DC00B5C7 */  lwc1       $f21, 0xDC($29)
    /* EDED8 001EDED8 23000010 */  b          .L001EDF68
    /* EDEDC 001EDEDC 00000000 */   nop
  .L001EDEE0:
    /* EDEE0 001EDEE0 2D880000 */  daddu      $17, $0, $0
    /* EDEE4 001EDEE4 1C000010 */  b          .L001EDF58
    /* EDEE8 001EDEE8 00000000 */   nop
  .L001EDEEC:
    /* EDEEC 001EDEEC C0101100 */  sll        $2, $17, 3
    /* EDEF0 001EDEF0 21105100 */  addu       $2, $2, $17
    /* EDEF4 001EDEF4 40100200 */  sll        $2, $2, 1
    /* EDEF8 001EDEF8 21105100 */  addu       $2, $2, $17
    /* EDEFC 001EDEFC 00110200 */  sll        $2, $2, 4
    /* EDF00 001EDF00 21A84202 */  addu       $21, $18, $2
    /* EDF04 001EDF04 0800A1C6 */  lwc1       $f1, 0x8($21)
    /* EDF08 001EDF08 D800A0C7 */  lwc1       $f0, 0xD8($29)
    /* EDF0C 001EDF0C 01080046 */  sub.s      $f0, $f1, $f0
    /* EDF10 001EDF10 E800A0E7 */  swc1       $f0, 0xE8($29)
    /* EDF14 001EDF14 0C00A0C6 */  lwc1       $f0, 0xC($21)
    /* EDF18 001EDF18 01001546 */  sub.s      $f0, $f0, $f21
    /* EDF1C 001EDF1C EC00A0E7 */  swc1       $f0, 0xEC($29)
    /* EDF20 001EDF20 E800A427 */  addiu      $4, $29, 0xE8
    /* EDF24 001EDF24 6C900F0C */  jal        func_003e41b0
    /* EDF28 001EDF28 00000000 */   nop
    /* EDF2C 001EDF2C 86050046 */  mov.s      $f22, $f0
    /* EDF30 001EDF30 34B01446 */  c.lt.s     $f22, $f20
    /* EDF34 001EDF34 07000045 */  bc1f       .L001EDF54
    /* EDF38 001EDF38 00000000 */   nop
    /* EDF3C 001EDF3C E000A427 */  addiu      $4, $29, 0xE0
    /* EDF40 001EDF40 E800A527 */  addiu      $5, $29, 0xE8
    /* EDF44 001EDF44 78900F0C */  jal        func_003e41e0
    /* EDF48 001EDF48 00000000 */   nop
    /* EDF4C 001EDF4C 0800B326 */  addiu      $19, $21, 0x8
    /* EDF50 001EDF50 06B50046 */  mov.s      $f20, $f22
  .L001EDF54:
    /* EDF54 001EDF54 01003126 */  addiu      $17, $17, 0x1
  .L001EDF58:
    /* EDF58 001EDF58 0400222A */  slti       $2, $17, 0x4
    /* EDF5C 001EDF5C E3FF4014 */  bnez       $2, .L001EDEEC
    /* EDF60 001EDF60 00000000 */   nop
    /* EDF64 001EDF64 CC04528E */  lw         $18, 0x4CC($18)
  .L001EDF68:
    /* EDF68 001EDF68 DDFF4016 */  bnez       $18, .L001EDEE0
    /* EDF6C 001EDF6C 00000000 */   nop
    /* EDF70 001EDF70 2E006012 */  beqz       $19, .L001EE02C
    /* EDF74 001EDF74 00000000 */   nop
    /* EDF78 001EDF78 ACB3828F */  lw         $2, -0x4C54($28)
    /* EDF7C 001EDF7C 21285000 */  addu       $5, $2, $16
    /* EDF80 001EDF80 1000638E */  lw         $3, 0x10($19)
    /* EDF84 001EDF84 1C03A224 */  addiu      $2, $5, 0x31C
    /* EDF88 001EDF88 24006210 */  beq        $3, $2, .L001EE01C
    /* EDF8C 001EDF8C 00000000 */   nop
    /* EDF90 001EDF90 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* EDF94 001EDF94 00008244 */  mtc1       $2, $f0
    /* EDF98 001EDF98 00000000 */  nop
    /* EDF9C 001EDF9C 82001446 */  mul.s      $f2, $f0, $f20
    /* EDFA0 001EDFA0 E000A0C7 */  lwc1       $f0, 0xE0($29)
    /* EDFA4 001EDFA4 42000246 */  mul.s      $f1, $f0, $f2
    /* EDFA8 001EDFA8 E000A1E7 */  swc1       $f1, 0xE0($29)
    /* EDFAC 001EDFAC E400A0C7 */  lwc1       $f0, 0xE4($29)
    /* EDFB0 001EDFB0 02000246 */  mul.s      $f0, $f0, $f2
    /* EDFB4 001EDFB4 E400A0E7 */  swc1       $f0, 0xE4($29)
    /* EDFB8 001EDFB8 C0101400 */  sll        $2, $20, 3
    /* EDFBC 001EDFBC 21105400 */  addu       $2, $2, $20
    /* EDFC0 001EDFC0 40100200 */  sll        $2, $2, 1
    /* EDFC4 001EDFC4 21105400 */  addu       $2, $2, $20
    /* EDFC8 001EDFC8 00210200 */  sll        $4, $2, 4
    /* EDFCC 001EDFCC D800A0C7 */  lwc1       $f0, 0xD8($29)
    /* EDFD0 001EDFD0 00000146 */  add.s      $f0, $f0, $f1
    /* EDFD4 001EDFD4 2403A0E4 */  swc1       $f0, 0x324($5)
    /* EDFD8 001EDFD8 E400A0C7 */  lwc1       $f0, 0xE4($29)
    /* EDFDC 001EDFDC 00A80046 */  add.s      $f0, $f21, $f0
    /* EDFE0 001EDFE0 ACB3828F */  lw         $2, -0x4C54($28)
    /* EDFE4 001EDFE4 21104400 */  addu       $2, $2, $4
    /* EDFE8 001EDFE8 280340E4 */  swc1       $f0, 0x328($2)
    /* EDFEC 001EDFEC ACB3828F */  lw         $2, -0x4C54($28)
    /* EDFF0 001EDFF0 21104400 */  addu       $2, $2, $4
    /* EDFF4 001EDFF4 2C0353AC */  sw         $19, 0x32C($2)
    /* EDFF8 001EDFF8 ACB3828F */  lw         $2, -0x4C54($28)
    /* EDFFC 001EDFFC 21104400 */  addu       $2, $2, $4
    /* EE000 001EE000 300354E4 */  swc1       $f20, 0x330($2)
    /* EE004 001EE004 FA43033C */  lui        $3, (0x43FA0000 >> 16)
    /* EE008 001EE008 ACB3828F */  lw         $2, -0x4C54($28)
    /* EE00C 001EE00C 21104400 */  addu       $2, $2, $4
    /* EE010 001EE010 340343AC */  sw         $3, 0x334($2)
    /* EE014 001EE014 09000010 */  b          .L001EE03C
    /* EE018 001EE018 00000000 */   nop
  .L001EE01C:
    /* EE01C 001EE01C 80BF023C */  lui        $2, (0xBF800000 >> 16)
    /* EE020 001EE020 3003A2AC */  sw         $2, 0x330($5)
    /* EE024 001EE024 05000010 */  b          .L001EE03C
    /* EE028 001EE028 00000000 */   nop
  .L001EE02C:
    /* EE02C 001EE02C 80BF033C */  lui        $3, (0xBF800000 >> 16)
    /* EE030 001EE030 ACB3828F */  lw         $2, -0x4C54($28)
    /* EE034 001EE034 21105000 */  addu       $2, $2, $16
    /* EE038 001EE038 300343AC */  sw         $3, 0x330($2)
  .L001EE03C:
    /* EE03C 001EE03C 01009426 */  addiu      $20, $20, 0x1
  .L001EE040:
    /* EE040 001EE040 0400822A */  slti       $2, $20, 0x4
    /* EE044 001EE044 92FF4014 */  bnez       $2, .L001EDE90
    /* EE048 001EE048 00000000 */   nop
    /* EE04C 001EE04C ACB3828F */  lw         $2, -0x4C54($28)
    /* EE050 001EE050 1803518C */  lw         $17, 0x318($2)
    /* EE054 001EE054 20000010 */  b          .L001EE0D8
    /* EE058 001EE058 00000000 */   nop
  .L001EE05C:
    /* EE05C 001EE05C 2D800000 */  daddu      $16, $0, $0
    /* EE060 001EE060 19000010 */  b          .L001EE0C8
    /* EE064 001EE064 00000000 */   nop
  .L001EE068:
    /* EE068 001EE068 C0101000 */  sll        $2, $16, 3
    /* EE06C 001EE06C 21105000 */  addu       $2, $2, $16
    /* EE070 001EE070 40100200 */  sll        $2, $2, 1
    /* EE074 001EE074 21105000 */  addu       $2, $2, $16
    /* EE078 001EE078 00110200 */  sll        $2, $2, 4
    /* EE07C 001EE07C 21102202 */  addu       $2, $17, $2
    /* EE080 001EE080 08004424 */  addiu      $4, $2, 0x8
    /* EE084 001EE084 1C0041C4 */  lwc1       $f1, 0x1C($2)
    /* EE088 001EE088 00008044 */  mtc1       $0, $f0
    /* EE08C 001EE08C 00000000 */  nop
    /* EE090 001EE090 36080046 */  c.le.s     $f1, $f0
    /* EE094 001EE094 0A000145 */  bc1t       .L001EE0C0
    /* EE098 001EE098 00000000 */   nop
    /* EE09C 001EE09C 180080C4 */  lwc1       $f0, 0x18($4)
    /* EE0A0 001EE0A0 34001A46 */  c.lt.s     $f0, $f26
    /* EE0A4 001EE0A4 06000145 */  bc1t       .L001EE0C0
    /* EE0A8 001EE0A8 00000000 */   nop
    /* EE0AC 001EE0AC 06D30046 */  mov.s      $f12, $f26
    /* EE0B0 001EE0B0 E8B4070C */  jal        func_001ed3a0
    /* EE0B4 001EE0B4 00000000 */   nop
    /* EE0B8 001EE0B8 02000010 */  b          .L001EE0C4
    /* EE0BC 001EE0BC 00000000 */   nop
  .L001EE0C0:
    /* EE0C0 001EE0C0 300080AC */  sw         $0, 0x30($4)
  .L001EE0C4:
    /* EE0C4 001EE0C4 01001026 */  addiu      $16, $16, 0x1
  .L001EE0C8:
    /* EE0C8 001EE0C8 0400022A */  slti       $2, $16, 0x4
    /* EE0CC 001EE0CC E6FF4014 */  bnez       $2, .L001EE068
    /* EE0D0 001EE0D0 00000000 */   nop
    /* EE0D4 001EE0D4 CC04318E */  lw         $17, 0x4CC($17)
  .L001EE0D8:
    /* EE0D8 001EE0D8 E0FF2016 */  bnez       $17, .L001EE05C
    /* EE0DC 001EE0DC 00000000 */   nop
    /* EE0E0 001EE0E0 2D800000 */  daddu      $16, $0, $0
    /* EE0E4 001EE0E4 16000010 */  b          .L001EE140
    /* EE0E8 001EE0E8 00000000 */   nop
  .L001EE0EC:
    /* EE0EC 001EE0EC C0101000 */  sll        $2, $16, 3
    /* EE0F0 001EE0F0 21105000 */  addu       $2, $2, $16
    /* EE0F4 001EE0F4 40100200 */  sll        $2, $2, 1
    /* EE0F8 001EE0F8 21105000 */  addu       $2, $2, $16
    /* EE0FC 001EE0FC 00190200 */  sll        $3, $2, 4
    /* EE100 001EE100 ACB3828F */  lw         $2, -0x4C54($28)
    /* EE104 001EE104 21104300 */  addu       $2, $2, $3
    /* EE108 001EE108 1C034424 */  addiu      $4, $2, 0x31C
    /* EE10C 001EE10C 300341C4 */  lwc1       $f1, 0x330($2)
    /* EE110 001EE110 00008044 */  mtc1       $0, $f0
    /* EE114 001EE114 00000000 */  nop
    /* EE118 001EE118 36080046 */  c.le.s     $f1, $f0
    /* EE11C 001EE11C 06000145 */  bc1t       .L001EE138
    /* EE120 001EE120 00000000 */   nop
    /* EE124 001EE124 06D30046 */  mov.s      $f12, $f26
    /* EE128 001EE128 E8B4070C */  jal        func_001ed3a0
    /* EE12C 001EE12C 00000000 */   nop
    /* EE130 001EE130 02000010 */  b          .L001EE13C
    /* EE134 001EE134 00000000 */   nop
  .L001EE138:
    /* EE138 001EE138 300080AC */  sw         $0, 0x30($4)
  .L001EE13C:
    /* EE13C 001EE13C 01001026 */  addiu      $16, $16, 0x1
  .L001EE140:
    /* EE140 001EE140 0400022A */  slti       $2, $16, 0x4
    /* EE144 001EE144 E9FF4014 */  bnez       $2, .L001EE0EC
    /* EE148 001EE148 00000000 */   nop
    /* EE14C 001EE14C ACB3828F */  lw         $2, -0x4C54($28)
    /* EE150 001EE150 DC074424 */  addiu      $4, $2, 0x7DC
    /* EE154 001EE154 06D30046 */  mov.s      $f12, $f26
    /* EE158 001EE158 E8B4070C */  jal        func_001ed3a0
    /* EE15C 001EE15C 00000000 */   nop
    /* EE160 001EE160 ACB3828F */  lw         $2, -0x4C54($28)
    /* EE164 001EE164 0C094424 */  addiu      $4, $2, 0x90C
    /* EE168 001EE168 06D30046 */  mov.s      $f12, $f26
    /* EE16C 001EE16C E8B4070C */  jal        func_001ed3a0
    /* EE170 001EE170 00000000 */   nop
    /* EE174 001EE174 A000BFDF */  ld         $31, 0xA0($29)
    /* EE178 001EE178 9000B77B */  lq         $23, 0x90($29)
    /* EE17C 001EE17C 8000B67B */  lq         $22, 0x80($29)
    /* EE180 001EE180 7000B57B */  lq         $21, 0x70($29)
    /* EE184 001EE184 6000B47B */  lq         $20, 0x60($29)
    /* EE188 001EE188 5000B37B */  lq         $19, 0x50($29)
    /* EE18C 001EE18C 4000B27B */  lq         $18, 0x40($29)
    /* EE190 001EE190 3000B17B */  lq         $17, 0x30($29)
    /* EE194 001EE194 2000B07B */  lq         $16, 0x20($29)
    /* EE198 001EE198 1800BAC7 */  lwc1       $f26, 0x18($29)
    /* EE19C 001EE19C 1400B9C7 */  lwc1       $f25, 0x14($29)
    /* EE1A0 001EE1A0 1000B8C7 */  lwc1       $f24, 0x10($29)
    /* EE1A4 001EE1A4 0C00B7C7 */  lwc1       $f23, 0xC($29)
    /* EE1A8 001EE1A8 0800B6C7 */  lwc1       $f22, 0x8($29)
    /* EE1AC 001EE1AC 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* EE1B0 001EE1B0 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* EE1B4 001EE1B4 0001BD27 */  addiu      $29, $29, 0x100
    /* EE1B8 001EE1B8 0800E003 */  jr         $31
    /* EE1BC 001EE1BC 00000000 */   nop
.size func_001ed700, 0xac0
