.section .text
.set noat
.set noreorder
glabel func_001cf730
    /* CF730 001CF730 E0FEBD27 */  addiu      $29, $29, -0x120
    /* CF734 001CF734 3000BFFF */  sd         $31, 0x30($29)
    /* CF738 001CF738 2000B17F */  sq         $17, 0x20($29)
    /* CF73C 001CF73C 1000B07F */  sq         $16, 0x10($29)
    /* CF740 001CF740 0400B5E7 */  swc1       $f21, 0x4($29)
    /* CF744 001CF744 0000B4E7 */  swc1       $f20, 0x0($29)
    /* CF748 001CF748 2D808000 */  daddu      $16, $4, $0
    /* CF74C 001CF74C ACB3828F */  lw         $2, -0x4C54($28)
    /* CF750 001CF750 7001428C */  lw         $2, 0x170($2)
    /* CF754 001CF754 3000518C */  lw         $17, 0x30($2)
    /* CF758 001CF758 02000424 */  addiu      $4, $0, 0x2
    /* CF75C 001CF75C 01000524 */  addiu      $5, $0, 0x1
    /* CF760 001CF760 D000A627 */  addiu      $6, $29, 0xD0
    /* CF764 001CF764 2D380000 */  daddu      $7, $0, $0
    /* CF768 001CF768 2D400000 */  daddu      $8, $0, $0
    /* CF76C 001CF76C 2D48A000 */  daddu      $9, $5, $0
    /* CF770 001CF770 1058060C */  jal        func_00196040
    /* CF774 001CF774 00000000 */   nop
    /* CF778 001CF778 46050046 */  mov.s      $f21, $f0
    /* CF77C 001CF77C 2D202002 */  daddu      $4, $17, $0
    /* CF780 001CF780 1001A527 */  addiu      $5, $29, 0x110
    /* CF784 001CF784 3C56060C */  jal        func_001958f0
    /* CF788 001CF788 00000000 */   nop
    /* CF78C 001CF78C 1001A1C7 */  lwc1       $f1, 0x110($29)
    /* CF790 001CF790 D000A0C7 */  lwc1       $f0, 0xD0($29)
    /* CF794 001CF794 01080046 */  sub.s      $f0, $f1, $f0
    /* CF798 001CF798 0001A0E7 */  swc1       $f0, 0x100($29)
    /* CF79C 001CF79C 1401A1C7 */  lwc1       $f1, 0x114($29)
    /* CF7A0 001CF7A0 D400A0C7 */  lwc1       $f0, 0xD4($29)
    /* CF7A4 001CF7A4 01080046 */  sub.s      $f0, $f1, $f0
    /* CF7A8 001CF7A8 0401A0E7 */  swc1       $f0, 0x104($29)
    /* CF7AC 001CF7AC 1801A1C7 */  lwc1       $f1, 0x118($29)
    /* CF7B0 001CF7B0 D800A0C7 */  lwc1       $f0, 0xD8($29)
    /* CF7B4 001CF7B4 01080046 */  sub.s      $f0, $f1, $f0
    /* CF7B8 001CF7B8 0801A0E7 */  swc1       $f0, 0x108($29)
    /* CF7BC 001CF7BC 0001A427 */  addiu      $4, $29, 0x100
    /* CF7C0 001CF7C0 2D288000 */  daddu      $5, $4, $0
    /* CF7C4 001CF7C4 2C900F0C */  jal        func_003e40b0
    /* CF7C8 001CF7C8 00000000 */   nop
    /* CF7CC 001CF7CC 3C8081C7 */  lwc1       $f1, -0x7FC4($28)
    /* CF7D0 001CF7D0 42080046 */  mul.s      $f1, $f1, $f0
    /* CF7D4 001CF7D4 0001A0C7 */  lwc1       $f0, 0x100($29)
    /* CF7D8 001CF7D8 C2000146 */  mul.s      $f3, $f0, $f1
    /* CF7DC 001CF7DC F000A3E7 */  swc1       $f3, 0xF0($29)
    /* CF7E0 001CF7E0 0401A0C7 */  lwc1       $f0, 0x104($29)
    /* CF7E4 001CF7E4 82000146 */  mul.s      $f2, $f0, $f1
    /* CF7E8 001CF7E8 F400A2E7 */  swc1       $f2, 0xF4($29)
    /* CF7EC 001CF7EC 0801A0C7 */  lwc1       $f0, 0x108($29)
    /* CF7F0 001CF7F0 42000146 */  mul.s      $f1, $f0, $f1
    /* CF7F4 001CF7F4 F800A1E7 */  swc1       $f1, 0xF8($29)
    /* CF7F8 001CF7F8 D000A0C7 */  lwc1       $f0, 0xD0($29)
    /* CF7FC 001CF7FC 00000346 */  add.s      $f0, $f0, $f3
    /* CF800 001CF800 E000A0E7 */  swc1       $f0, 0xE0($29)
    /* CF804 001CF804 D400A0C7 */  lwc1       $f0, 0xD4($29)
    /* CF808 001CF808 00000246 */  add.s      $f0, $f0, $f2
    /* CF80C 001CF80C E400A0E7 */  swc1       $f0, 0xE4($29)
    /* CF810 001CF810 D800A0C7 */  lwc1       $f0, 0xD8($29)
    /* CF814 001CF814 00000146 */  add.s      $f0, $f0, $f1
    /* CF818 001CF818 E800A0E7 */  swc1       $f0, 0xE8($29)
    /* CF81C 001CF81C E143023C */  lui        $2, (0x43E10000 >> 16)
    /* CF820 001CF820 00008244 */  mtc1       $2, $f0
    /* CF824 001CF824 00000000 */  nop
    /* CF828 001CF828 34A80046 */  c.lt.s     $f21, $f0
    /* CF82C 001CF82C 02000045 */  bc1f       .L001CF838
    /* CF830 001CF830 00000000 */   nop
    /* CF834 001CF834 46050046 */  mov.s      $f21, $f0
  .L001CF838:
    /* CF838 001CF838 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CF83C 001CF83C 00088244 */  mtc1       $2, $f1
    /* CF840 001CF840 B80000C6 */  lwc1       $f0, 0xB8($16)
    /* CF844 001CF844 42080046 */  mul.s      $f1, $f1, $f0
    /* CF848 001CF848 108180C7 */  lwc1       $f0, -0x7EF0($28)
    /* CF84C 001CF84C 02030146 */  mul.s      $f12, $f0, $f1
    /* CF850 001CF850 1A2E110C */  jal        func_0044b868
    /* CF854 001CF854 00000000 */   nop
    /* CF858 001CF858 00000000 */  nop
    /* CF85C 001CF85C 00000000 */  nop
    /* CF860 001CF860 03AD0046 */  div.s      $f20, $f21, $f0
    /* CF864 001CF864 0C42023C */  lui        $2, (0x420C0000 >> 16)
    /* CF868 001CF868 00608244 */  mtc1       $2, $f12
    /* CF86C 001CF86C 8000A427 */  addiu      $4, $29, 0x80
    /* CF870 001CF870 6100053C */  lui        $5, %hi(D_0060A0D0)
    /* CF874 001CF874 D0A0A524 */  addiu      $5, $5, %lo(D_0060A0D0)
    /* CF878 001CF878 2D300000 */  daddu      $6, $0, $0
    /* CF87C 001CF87C 1C820F0C */  jal        func_003e0870
    /* CF880 001CF880 00000000 */   nop
    /* CF884 001CF884 F000A427 */  addiu      $4, $29, 0xF0
    /* CF888 001CF888 6100053C */  lui        $5, %hi(D_0060A100)
    /* CF88C 001CF88C 00A1A524 */  addiu      $5, $5, %lo(D_0060A100)
    /* CF890 001CF890 8000A627 */  addiu      $6, $29, 0x80
    /* CF894 001CF894 C8900F0C */  jal        func_003e4320
    /* CF898 001CF898 00000000 */   nop
    /* CF89C 001CF89C 0001A427 */  addiu      $4, $29, 0x100
    /* CF8A0 001CF8A0 F000A527 */  addiu      $5, $29, 0xF0
    /* CF8A4 001CF8A4 01000624 */  addiu      $6, $0, 0x1
    /* CF8A8 001CF8A8 1C002726 */  addiu      $7, $17, 0x1C
    /* CF8AC 001CF8AC D0720F0C */  jal        func_003dcb40
    /* CF8B0 001CF8B0 00000000 */   nop
    /* CF8B4 001CF8B4 0001A0C7 */  lwc1       $f0, 0x100($29)
    /* CF8B8 001CF8B8 02001546 */  mul.s      $f0, $f0, $f21
    /* CF8BC 001CF8BC 1001A0E7 */  swc1       $f0, 0x110($29)
    /* CF8C0 001CF8C0 0401A0C7 */  lwc1       $f0, 0x104($29)
    /* CF8C4 001CF8C4 02001546 */  mul.s      $f0, $f0, $f21
    /* CF8C8 001CF8C8 1401A0E7 */  swc1       $f0, 0x114($29)
    /* CF8CC 001CF8CC 0801A0C7 */  lwc1       $f0, 0x108($29)
    /* CF8D0 001CF8D0 02001546 */  mul.s      $f0, $f0, $f21
    /* CF8D4 001CF8D4 1801A0E7 */  swc1       $f0, 0x118($29)
    /* CF8D8 001CF8D8 6800A427 */  addiu      $4, $29, 0x68
    /* CF8DC 001CF8DC 1001A527 */  addiu      $5, $29, 0x110
    /* CF8E0 001CF8E0 E000A627 */  addiu      $6, $29, 0xE0
    /* CF8E4 001CF8E4 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* CF8E8 001CF8E8 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* CF8EC 001CF8EC E0F5060C */  jal        func_001bd780
    /* CF8F0 001CF8F0 00000000 */   nop
    /* CF8F4 001CF8F4 F000A427 */  addiu      $4, $29, 0xF0
    /* CF8F8 001CF8F8 6100053C */  lui        $5, %hi(D_0060A100)
    /* CF8FC 001CF8FC 00A1A524 */  addiu      $5, $5, %lo(D_0060A100)
    /* CF900 001CF900 01000624 */  addiu      $6, $0, 0x1
    /* CF904 001CF904 6800A727 */  addiu      $7, $29, 0x68
    /* CF908 001CF908 D0720F0C */  jal        func_003dcb40
    /* CF90C 001CF90C 00000000 */   nop
    /* CF910 001CF910 4842023C */  lui        $2, (0x42480000 >> 16)
    /* CF914 001CF914 00008244 */  mtc1       $2, $f0
    /* CF918 001CF918 00000000 */  nop
    /* CF91C 001CF91C 40001446 */  add.s      $f1, $f0, $f20
    /* CF920 001CF920 F000A0C7 */  lwc1       $f0, 0xF0($29)
    /* CF924 001CF924 02000146 */  mul.s      $f0, $f0, $f1
    /* CF928 001CF928 0001A0E7 */  swc1       $f0, 0x100($29)
    /* CF92C 001CF92C F400A0C7 */  lwc1       $f0, 0xF4($29)
    /* CF930 001CF930 02000146 */  mul.s      $f0, $f0, $f1
    /* CF934 001CF934 0401A0E7 */  swc1       $f0, 0x104($29)
    /* CF938 001CF938 F800A0C7 */  lwc1       $f0, 0xF8($29)
    /* CF93C 001CF93C 02000146 */  mul.s      $f0, $f0, $f1
    /* CF940 001CF940 0801A0E7 */  swc1       $f0, 0x108($29)
    /* CF944 001CF944 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CF948 001CF948 00088244 */  mtc1       $2, $f1
    /* CF94C 001CF94C B80000C6 */  lwc1       $f0, 0xB8($16)
    /* CF950 001CF950 42080046 */  mul.s      $f1, $f1, $f0
    /* CF954 001CF954 108180C7 */  lwc1       $f0, -0x7EF0($28)
    /* CF958 001CF958 02030146 */  mul.s      $f12, $f0, $f1
    /* CF95C 001CF95C 1A2E110C */  jal        func_0044b868
    /* CF960 001CF960 00000000 */   nop
    /* CF964 001CF964 42A00046 */  mul.s      $f1, $f20, $f0
    /* CF968 001CF968 603E023C */  lui        $2, (0x3E600000 >> 16)
    /* CF96C 001CF96C 00008244 */  mtc1       $2, $f0
    /* CF970 001CF970 00000000 */  nop
    /* CF974 001CF974 42080046 */  mul.s      $f1, $f1, $f0
    /* CF978 001CF978 E88080C7 */  lwc1       $f0, -0x7F18($28)
    /* CF97C 001CF97C 420D0046 */  mul.s      $f21, $f1, $f0
    /* CF980 001CF980 0001A0C7 */  lwc1       $f0, 0x100($29)
    /* CF984 001CF984 C800A0E7 */  swc1       $f0, 0xC8($29)
    /* CF988 001CF988 0801A0C7 */  lwc1       $f0, 0x108($29)
    /* CF98C 001CF98C CC00A0E7 */  swc1       $f0, 0xCC($29)
    /* CF990 001CF990 C800A427 */  addiu      $4, $29, 0xC8
    /* CF994 001CF994 2D288000 */  daddu      $5, $4, $0
    /* CF998 001CF998 78900F0C */  jal        func_003e41e0
    /* CF99C 001CF99C 00000000 */   nop
    /* CF9A0 001CF9A0 CC00A1C7 */  lwc1       $f1, 0xCC($29)
    /* CF9A4 001CF9A4 E000A0C7 */  lwc1       $f0, 0xE0($29)
    /* CF9A8 001CF9A8 00608044 */  mtc1       $0, $f12
    /* CF9AC 001CF9AC 00000000 */  nop
    /* CF9B0 001CF9B0 18600046 */  adda.s     $f12, $f0
    /* CF9B4 001CF9B4 9C091546 */  madd.s     $f6, $f1, $f21
    /* CF9B8 001CF9B8 E000A6E7 */  swc1       $f6, 0xE0($29)
    /* CF9BC 001CF9BC C800A1C7 */  lwc1       $f1, 0xC8($29)
    /* CF9C0 001CF9C0 E800A0C7 */  lwc1       $f0, 0xE8($29)
    /* CF9C4 001CF9C4 18600046 */  adda.s     $f12, $f0
    /* CF9C8 001CF9C8 5D091546 */  msub.s     $f5, $f1, $f21
    /* CF9CC 001CF9CC E800A5E7 */  swc1       $f5, 0xE8($29)
    /* CF9D0 001CF9D0 0001A0C7 */  lwc1       $f0, 0x100($29)
    /* CF9D4 001CF9D4 00300046 */  add.s      $f0, $f6, $f0
    /* CF9D8 001CF9D8 5C00A0E7 */  swc1       $f0, 0x5C($29)
    /* CF9DC 001CF9DC E400A4C7 */  lwc1       $f4, 0xE4($29)
    /* CF9E0 001CF9E0 0401A0C7 */  lwc1       $f0, 0x104($29)
    /* CF9E4 001CF9E4 00200046 */  add.s      $f0, $f4, $f0
    /* CF9E8 001CF9E8 6000A0E7 */  swc1       $f0, 0x60($29)
    /* CF9EC 001CF9EC 0801A0C7 */  lwc1       $f0, 0x108($29)
    /* CF9F0 001CF9F0 00280046 */  add.s      $f0, $f5, $f0
    /* CF9F4 001CF9F4 6400A0E7 */  swc1       $f0, 0x64($29)
    /* CF9F8 001CF9F8 6800A3C7 */  lwc1       $f3, 0x68($29)
    /* CF9FC 001CF9FC 6C00A2C7 */  lwc1       $f2, 0x6C($29)
    /* CFA00 001CFA00 7000A1C7 */  lwc1       $f1, 0x70($29)
    /* CFA04 001CFA04 7400A0C7 */  lwc1       $f0, 0x74($29)
    /* CFA08 001CFA08 4C00A3E7 */  swc1       $f3, 0x4C($29)
    /* CFA0C 001CFA0C 5000A2E7 */  swc1       $f2, 0x50($29)
    /* CFA10 001CFA10 5400A1E7 */  swc1       $f1, 0x54($29)
    /* CFA14 001CFA14 5800A0E7 */  swc1       $f0, 0x58($29)
    /* CFA18 001CFA18 4842023C */  lui        $2, (0x42480000 >> 16)
    /* CFA1C 001CFA1C 00008244 */  mtc1       $2, $f0
    /* CFA20 001CFA20 00000000 */  nop
    /* CFA24 001CFA24 41A00046 */  sub.s      $f1, $f20, $f0
    /* CFA28 001CFA28 F000A0C7 */  lwc1       $f0, 0xF0($29)
    /* CFA2C 001CFA2C C2000146 */  mul.s      $f3, $f0, $f1
    /* CFA30 001CFA30 0001A3E7 */  swc1       $f3, 0x100($29)
    /* CFA34 001CFA34 F400A0C7 */  lwc1       $f0, 0xF4($29)
    /* CFA38 001CFA38 82000146 */  mul.s      $f2, $f0, $f1
    /* CFA3C 001CFA3C 0401A2E7 */  swc1       $f2, 0x104($29)
    /* CFA40 001CFA40 F800A0C7 */  lwc1       $f0, 0xF8($29)
    /* CFA44 001CFA44 42000146 */  mul.s      $f1, $f0, $f1
    /* CFA48 001CFA48 0801A1E7 */  swc1       $f1, 0x108($29)
    /* CFA4C 001CFA4C 00300346 */  add.s      $f0, $f6, $f3
    /* CFA50 001CFA50 4000A0E7 */  swc1       $f0, 0x40($29)
    /* CFA54 001CFA54 00200246 */  add.s      $f0, $f4, $f2
    /* CFA58 001CFA58 4400A0E7 */  swc1       $f0, 0x44($29)
    /* CFA5C 001CFA5C 00280146 */  add.s      $f0, $f5, $f1
    /* CFA60 001CFA60 4800A0E7 */  swc1       $f0, 0x48($29)
    /* CFA64 001CFA64 2D200000 */  daddu      $4, $0, $0
    /* CFA68 001CFA68 2D280000 */  daddu      $5, $0, $0
    /* CFA6C 001CFA6C 2D300000 */  daddu      $6, $0, $0
    /* CFA70 001CFA70 00010724 */  addiu      $7, $0, 0x100
    /* CFA74 001CFA74 50F3060C */  jal        func_001bcd40
    /* CFA78 001CFA78 00000000 */   nop
    /* CFA7C 001CFA7C 2D200002 */  daddu      $4, $16, $0
    /* CFA80 001CFA80 4000A527 */  addiu      $5, $29, 0x40
    /* CFA84 001CFA84 5C00A627 */  addiu      $6, $29, 0x5C
    /* CFA88 001CFA88 01000724 */  addiu      $7, $0, 0x1
    /* CFA8C 001CFA8C 08EB060C */  jal        func_001bac20
    /* CFA90 001CFA90 00000000 */   nop
    /* CFA94 001CFA94 6040023C */  lui        $2, (0x40600000 >> 16)
    /* CFA98 001CFA98 00608244 */  mtc1       $2, $f12
    /* CFA9C 001CFA9C 2D200002 */  daddu      $4, $16, $0
    /* CFAA0 001CFAA0 BCEF060C */  jal        func_001bbef0
    /* CFAA4 001CFAA4 00000000 */   nop
    /* CFAA8 001CFAA8 3000BFDF */  ld         $31, 0x30($29)
    /* CFAAC 001CFAAC 2000B17B */  lq         $17, 0x20($29)
    /* CFAB0 001CFAB0 1000B07B */  lq         $16, 0x10($29)
    /* CFAB4 001CFAB4 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* CFAB8 001CFAB8 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* CFABC 001CFABC 2001BD27 */  addiu      $29, $29, 0x120
    /* CFAC0 001CFAC0 0800E003 */  jr         $31
    /* CFAC4 001CFAC4 00000000 */   nop
    /* CFAC8 001CFAC8 00000000 */  nop
    /* CFACC 001CFACC 00000000 */  nop
.size func_001cf730, 0x3a0
