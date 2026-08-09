.section .text
.set noat
.set noreorder
glabel func_003ec840
    /* 2EC840 003EC840 2348C500 */  subu       $9, $6, $5
    /* 2EC844 003EC844 8037033C */  lui        $3, (0x37800000 >> 16)
    /* 2EC848 003EC848 00088944 */  mtc1       $9, $f1
    /* 2EC84C 003EC84C 033C0700 */  sra        $7, $7, 16
    /* 2EC850 003EC850 00008344 */  mtc1       $3, $f0
    /* 2EC854 003EC854 03540500 */  sra        $10, $5, 16
    /* 2EC858 003EC858 60088046 */  cvt.s.w    $f1, $f1
    /* 2EC85C 003EC85C 1000838C */  lw         $3, 0x10($4)
    /* 2EC860 003EC860 42000146 */  mul.s      $f1, $f0, $f1
    /* 2EC864 003EC864 1848E300 */  mult       $9, $7, $3
    /* 2EC868 003EC868 1400878C */  lw         $7, 0x14($4)
    /* 2EC86C 003EC86C 80180A00 */  sll        $3, $10, 2
    /* 2EC870 003EC870 2138E900 */  addu       $7, $7, $9
    /* 2EC874 003EC874 03240600 */  sra        $4, $6, 16
    /* 2EC878 003EC878 AC004411 */  beq        $10, $4, .L003ECB2C
    /* 2EC87C 003EC87C 2118E300 */   addu      $3, $7, $3
    /* 2EC880 003EC880 00006990 */  lbu        $9, 0x0($3)
    /* 2EC884 003EC884 01004725 */  addiu      $7, $10, 0x1
    /* 2EC888 003EC888 04002005 */  bltz       $9, .L003EC89C
    /* 2EC88C 003EC88C 003C0700 */   sll       $7, $7, 16
    /* 2EC890 003EC890 00008944 */  mtc1       $9, $f0
    /* 2EC894 003EC894 08000010 */  b          .L003EC8B8
    /* 2EC898 003EC898 A0008046 */   cvt.s.w   $f2, $f0
  .L003EC89C:
    /* 2EC89C 003EC89C 42500900 */  srl        $10, $9, 1
    /* 2EC8A0 003EC8A0 01002931 */  andi       $9, $9, 0x1
    /* 2EC8A4 003EC8A4 25504901 */  or         $10, $10, $9
    /* 2EC8A8 003EC8A8 00008A44 */  mtc1       $10, $f0
    /* 2EC8AC 003EC8AC 00000000 */  nop
    /* 2EC8B0 003EC8B0 A0008046 */  cvt.s.w    $f2, $f0
    /* 2EC8B4 003EC8B4 80100246 */  add.s      $f2, $f2, $f2
  .L003EC8B8:
    /* 2EC8B8 003EC8B8 803B093C */  lui        $9, (0x3B808081 >> 16)
    /* 2EC8BC 003EC8BC 81802935 */  ori        $9, $9, (0x3B808081 & 0xFFFF)
    /* 2EC8C0 003EC8C0 00008944 */  mtc1       $9, $f0
    /* 2EC8C4 003EC8C4 00000000 */  nop
    /* 2EC8C8 003EC8C8 02000246 */  mul.s      $f0, $f0, $f2
    /* 2EC8CC 003EC8CC 000000E5 */  swc1       $f0, 0x0($8)
    /* 2EC8D0 003EC8D0 01006990 */  lbu        $9, 0x1($3)
    /* 2EC8D4 003EC8D4 04002005 */  bltz       $9, .L003EC8E8
    /* 2EC8D8 003EC8D8 00000000 */   nop
    /* 2EC8DC 003EC8DC 00008944 */  mtc1       $9, $f0
    /* 2EC8E0 003EC8E0 08000010 */  b          .L003EC904
    /* 2EC8E4 003EC8E4 A0008046 */   cvt.s.w   $f2, $f0
  .L003EC8E8:
    /* 2EC8E8 003EC8E8 42500900 */  srl        $10, $9, 1
    /* 2EC8EC 003EC8EC 01002931 */  andi       $9, $9, 0x1
    /* 2EC8F0 003EC8F0 25504901 */  or         $10, $10, $9
    /* 2EC8F4 003EC8F4 00008A44 */  mtc1       $10, $f0
    /* 2EC8F8 003EC8F8 00000000 */  nop
    /* 2EC8FC 003EC8FC A0008046 */  cvt.s.w    $f2, $f0
    /* 2EC900 003EC900 80100246 */  add.s      $f2, $f2, $f2
  .L003EC904:
    /* 2EC904 003EC904 803B093C */  lui        $9, (0x3B808081 >> 16)
    /* 2EC908 003EC908 81802935 */  ori        $9, $9, (0x3B808081 & 0xFFFF)
    /* 2EC90C 003EC90C 00008944 */  mtc1       $9, $f0
    /* 2EC910 003EC910 00000000 */  nop
    /* 2EC914 003EC914 02000246 */  mul.s      $f0, $f0, $f2
    /* 2EC918 003EC918 040000E5 */  swc1       $f0, 0x4($8)
    /* 2EC91C 003EC91C 02006990 */  lbu        $9, 0x2($3)
    /* 2EC920 003EC920 04002005 */  bltz       $9, .L003EC934
    /* 2EC924 003EC924 00000000 */   nop
    /* 2EC928 003EC928 00008944 */  mtc1       $9, $f0
    /* 2EC92C 003EC92C 08000010 */  b          .L003EC950
    /* 2EC930 003EC930 A0008046 */   cvt.s.w   $f2, $f0
  .L003EC934:
    /* 2EC934 003EC934 42500900 */  srl        $10, $9, 1
    /* 2EC938 003EC938 01002931 */  andi       $9, $9, 0x1
    /* 2EC93C 003EC93C 25504901 */  or         $10, $10, $9
    /* 2EC940 003EC940 00008A44 */  mtc1       $10, $f0
    /* 2EC944 003EC944 00000000 */  nop
    /* 2EC948 003EC948 A0008046 */  cvt.s.w    $f2, $f0
    /* 2EC94C 003EC94C 80100246 */  add.s      $f2, $f2, $f2
  .L003EC950:
    /* 2EC950 003EC950 803B093C */  lui        $9, (0x3B808081 >> 16)
    /* 2EC954 003EC954 81802935 */  ori        $9, $9, (0x3B808081 & 0xFFFF)
    /* 2EC958 003EC958 00008944 */  mtc1       $9, $f0
    /* 2EC95C 003EC95C 00000000 */  nop
    /* 2EC960 003EC960 02000246 */  mul.s      $f0, $f0, $f2
    /* 2EC964 003EC964 080000E5 */  swc1       $f0, 0x8($8)
    /* 2EC968 003EC968 03006990 */  lbu        $9, 0x3($3)
    /* 2EC96C 003EC96C 04002005 */  bltz       $9, .L003EC980
    /* 2EC970 003EC970 00000000 */   nop
    /* 2EC974 003EC974 00008944 */  mtc1       $9, $f0
    /* 2EC978 003EC978 08000010 */  b          .L003EC99C
    /* 2EC97C 003EC97C E0008046 */   cvt.s.w   $f3, $f0
  .L003EC980:
    /* 2EC980 003EC980 42500900 */  srl        $10, $9, 1
    /* 2EC984 003EC984 01002931 */  andi       $9, $9, 0x1
    /* 2EC988 003EC988 25504901 */  or         $10, $10, $9
    /* 2EC98C 003EC98C 00008A44 */  mtc1       $10, $f0
    /* 2EC990 003EC990 00000000 */  nop
    /* 2EC994 003EC994 E0008046 */  cvt.s.w    $f3, $f0
    /* 2EC998 003EC998 C0180346 */  add.s      $f3, $f3, $f3
  .L003EC99C:
    /* 2EC99C 003EC99C 2328E500 */  subu       $5, $7, $5
    /* 2EC9A0 003EC9A0 035C0700 */  sra        $11, $7, 16
    /* 2EC9A4 003EC9A4 00108544 */  mtc1       $5, $f2
    /* 2EC9A8 003EC9A8 04006324 */  addiu      $3, $3, 0x4
    /* 2EC9AC 003EC9AC 20118046 */  cvt.s.w    $f4, $f2
    /* 2EC9B0 003EC9B0 803B053C */  lui        $5, (0x3B808081 >> 16)
    /* 2EC9B4 003EC9B4 8180A934 */  ori        $9, $5, (0x3B808081 & 0xFFFF)
    /* 2EC9B8 003EC9B8 8037053C */  lui        $5, (0x37800000 >> 16)
    /* 2EC9BC 003EC9BC 00008944 */  mtc1       $9, $f0
    /* 2EC9C0 003EC9C0 00000000 */  nop
    /* 2EC9C4 003EC9C4 82000346 */  mul.s      $f2, $f0, $f3
    /* 2EC9C8 003EC9C8 0C0002E5 */  swc1       $f2, 0xC($8)
    /* 2EC9CC 003EC9CC 00188544 */  mtc1       $5, $f3
    /* 2EC9D0 003EC9D0 000002C5 */  lwc1       $f2, 0x0($8)
    /* 2EC9D4 003EC9D4 C2180446 */  mul.s      $f3, $f3, $f4
    /* 2EC9D8 003EC9D8 82100346 */  mul.s      $f2, $f2, $f3
    /* 2EC9DC 003EC9DC 000002E5 */  swc1       $f2, 0x0($8)
    /* 2EC9E0 003EC9E0 040002C5 */  lwc1       $f2, 0x4($8)
    /* 2EC9E4 003EC9E4 82100346 */  mul.s      $f2, $f2, $f3
    /* 2EC9E8 003EC9E8 040002E5 */  swc1       $f2, 0x4($8)
    /* 2EC9EC 003EC9EC 080002C5 */  lwc1       $f2, 0x8($8)
    /* 2EC9F0 003EC9F0 82100346 */  mul.s      $f2, $f2, $f3
    /* 2EC9F4 003EC9F4 080002E5 */  swc1       $f2, 0x8($8)
    /* 2EC9F8 003EC9F8 0C0002C5 */  lwc1       $f2, 0xC($8)
    /* 2EC9FC 003EC9FC 82100346 */  mul.s      $f2, $f2, $f3
    /* 2ECA00 003ECA00 B2006411 */  beq        $11, $4, .L003ECCCC
    /* 2ECA04 003ECA04 0C0002E5 */   swc1      $f2, 0xC($8)
    /* 2ECA08 003ECA08 00188044 */  mtc1       $0, $f3
    /* 2ECA0C 003ECA0C 0100053C */  lui        $5, (0x10000 >> 16)
  .L003ECA10:
    /* 2ECA10 003ECA10 01006990 */  lbu        $9, 0x1($3)
    /* 2ECA14 003ECA14 04002005 */  bltz       $9, .L003ECA28
    /* 2ECA18 003ECA18 00000000 */   nop
    /* 2ECA1C 003ECA1C 00108944 */  mtc1       $9, $f2
    /* 2ECA20 003ECA20 08000010 */  b          .L003ECA44
    /* 2ECA24 003ECA24 A0108046 */   cvt.s.w   $f2, $f2
  .L003ECA28:
    /* 2ECA28 003ECA28 42500900 */  srl        $10, $9, 1
    /* 2ECA2C 003ECA2C 01002931 */  andi       $9, $9, 0x1
    /* 2ECA30 003ECA30 25504901 */  or         $10, $10, $9
    /* 2ECA34 003ECA34 00108A44 */  mtc1       $10, $f2
    /* 2ECA38 003ECA38 00000000 */  nop
    /* 2ECA3C 003ECA3C A0108046 */  cvt.s.w    $f2, $f2
    /* 2ECA40 003ECA40 80100246 */  add.s      $f2, $f2, $f2
  .L003ECA44:
    /* 2ECA44 003ECA44 02006990 */  lbu        $9, 0x2($3)
    /* 2ECA48 003ECA48 04002005 */  bltz       $9, .L003ECA5C
    /* 2ECA4C 003ECA4C 42010246 */   mul.s     $f5, $f0, $f2
    /* 2ECA50 003ECA50 00108944 */  mtc1       $9, $f2
    /* 2ECA54 003ECA54 08000010 */  b          .L003ECA78
    /* 2ECA58 003ECA58 A0108046 */   cvt.s.w   $f2, $f2
  .L003ECA5C:
    /* 2ECA5C 003ECA5C 42500900 */  srl        $10, $9, 1
    /* 2ECA60 003ECA60 01002931 */  andi       $9, $9, 0x1
    /* 2ECA64 003ECA64 25504901 */  or         $10, $10, $9
    /* 2ECA68 003ECA68 00108A44 */  mtc1       $10, $f2
    /* 2ECA6C 003ECA6C 00000000 */  nop
    /* 2ECA70 003ECA70 A0108046 */  cvt.s.w    $f2, $f2
    /* 2ECA74 003ECA74 80100246 */  add.s      $f2, $f2, $f2
  .L003ECA78:
    /* 2ECA78 003ECA78 03006990 */  lbu        $9, 0x3($3)
    /* 2ECA7C 003ECA7C 04002005 */  bltz       $9, .L003ECA90
    /* 2ECA80 003ECA80 82010246 */   mul.s     $f6, $f0, $f2
    /* 2ECA84 003ECA84 00108944 */  mtc1       $9, $f2
    /* 2ECA88 003ECA88 08000010 */  b          .L003ECAAC
    /* 2ECA8C 003ECA8C A0108046 */   cvt.s.w   $f2, $f2
  .L003ECA90:
    /* 2ECA90 003ECA90 42500900 */  srl        $10, $9, 1
    /* 2ECA94 003ECA94 01002931 */  andi       $9, $9, 0x1
    /* 2ECA98 003ECA98 25504901 */  or         $10, $10, $9
    /* 2ECA9C 003ECA9C 00108A44 */  mtc1       $10, $f2
    /* 2ECAA0 003ECAA0 00000000 */  nop
    /* 2ECAA4 003ECAA4 A0108046 */  cvt.s.w    $f2, $f2
    /* 2ECAA8 003ECAA8 80100246 */  add.s      $f2, $f2, $f2
  .L003ECAAC:
    /* 2ECAAC 003ECAAC 00006990 */  lbu        $9, 0x0($3)
    /* 2ECAB0 003ECAB0 04002005 */  bltz       $9, .L003ECAC4
    /* 2ECAB4 003ECAB4 C2010246 */   mul.s     $f7, $f0, $f2
    /* 2ECAB8 003ECAB8 00108944 */  mtc1       $9, $f2
    /* 2ECABC 003ECABC 08000010 */  b          .L003ECAE0
    /* 2ECAC0 003ECAC0 20118046 */   cvt.s.w   $f4, $f2
  .L003ECAC4:
    /* 2ECAC4 003ECAC4 42500900 */  srl        $10, $9, 1
    /* 2ECAC8 003ECAC8 01002931 */  andi       $9, $9, 0x1
    /* 2ECACC 003ECACC 25504901 */  or         $10, $10, $9
    /* 2ECAD0 003ECAD0 00108A44 */  mtc1       $10, $f2
    /* 2ECAD4 003ECAD4 00000000 */  nop
    /* 2ECAD8 003ECAD8 20118046 */  cvt.s.w    $f4, $f2
    /* 2ECADC 003ECADC 00210446 */  add.s      $f4, $f4, $f4
  .L003ECAE0:
    /* 2ECAE0 003ECAE0 000002C5 */  lwc1       $f2, 0x0($8)
    /* 2ECAE4 003ECAE4 01006B25 */  addiu      $11, $11, 0x1
    /* 2ECAE8 003ECAE8 04006324 */  addiu      $3, $3, 0x4
    /* 2ECAEC 003ECAEC 2138E500 */  addu       $7, $7, $5
    /* 2ECAF0 003ECAF0 18180246 */  adda.s     $f3, $f2
    /* 2ECAF4 003ECAF4 9C000446 */  madd.s     $f2, $f0, $f4
    /* 2ECAF8 003ECAF8 000002E5 */  swc1       $f2, 0x0($8)
    /* 2ECAFC 003ECAFC 040002C5 */  lwc1       $f2, 0x4($8)
    /* 2ECB00 003ECB00 80100546 */  add.s      $f2, $f2, $f5
    /* 2ECB04 003ECB04 040002E5 */  swc1       $f2, 0x4($8)
    /* 2ECB08 003ECB08 080002C5 */  lwc1       $f2, 0x8($8)
    /* 2ECB0C 003ECB0C 80100646 */  add.s      $f2, $f2, $f6
    /* 2ECB10 003ECB10 080002E5 */  swc1       $f2, 0x8($8)
    /* 2ECB14 003ECB14 0C0002C5 */  lwc1       $f2, 0xC($8)
    /* 2ECB18 003ECB18 80100746 */  add.s      $f2, $f2, $f7
    /* 2ECB1C 003ECB1C BCFF6415 */  bne        $11, $4, .L003ECA10
    /* 2ECB20 003ECB20 0C0002E5 */   swc1      $f2, 0xC($8)
    /* 2ECB24 003ECB24 6A000010 */  b          .L003ECCD0
    /* 2ECB28 003ECB28 00006490 */   lbu       $4, 0x0($3)
  .L003ECB2C:
    /* 2ECB2C 003ECB2C 00006490 */  lbu        $4, 0x0($3)
    /* 2ECB30 003ECB30 04008004 */  bltz       $4, .L003ECB44
    /* 2ECB34 003ECB34 00000000 */   nop
    /* 2ECB38 003ECB38 00008444 */  mtc1       $4, $f0
    /* 2ECB3C 003ECB3C 08000010 */  b          .L003ECB60
    /* 2ECB40 003ECB40 A0008046 */   cvt.s.w   $f2, $f0
  .L003ECB44:
    /* 2ECB44 003ECB44 42280400 */  srl        $5, $4, 1
    /* 2ECB48 003ECB48 01008430 */  andi       $4, $4, 0x1
    /* 2ECB4C 003ECB4C 2528A400 */  or         $5, $5, $4
    /* 2ECB50 003ECB50 00008544 */  mtc1       $5, $f0
    /* 2ECB54 003ECB54 00000000 */  nop
    /* 2ECB58 003ECB58 A0008046 */  cvt.s.w    $f2, $f0
    /* 2ECB5C 003ECB5C 80100246 */  add.s      $f2, $f2, $f2
  .L003ECB60:
    /* 2ECB60 003ECB60 803B043C */  lui        $4, (0x3B808081 >> 16)
    /* 2ECB64 003ECB64 81808434 */  ori        $4, $4, (0x3B808081 & 0xFFFF)
    /* 2ECB68 003ECB68 00008444 */  mtc1       $4, $f0
    /* 2ECB6C 003ECB6C 00000000 */  nop
    /* 2ECB70 003ECB70 02000246 */  mul.s      $f0, $f0, $f2
    /* 2ECB74 003ECB74 000000E5 */  swc1       $f0, 0x0($8)
    /* 2ECB78 003ECB78 01006490 */  lbu        $4, 0x1($3)
    /* 2ECB7C 003ECB7C 04008004 */  bltz       $4, .L003ECB90
    /* 2ECB80 003ECB80 00000000 */   nop
    /* 2ECB84 003ECB84 00008444 */  mtc1       $4, $f0
    /* 2ECB88 003ECB88 08000010 */  b          .L003ECBAC
    /* 2ECB8C 003ECB8C A0008046 */   cvt.s.w   $f2, $f0
  .L003ECB90:
    /* 2ECB90 003ECB90 42280400 */  srl        $5, $4, 1
    /* 2ECB94 003ECB94 01008430 */  andi       $4, $4, 0x1
    /* 2ECB98 003ECB98 2528A400 */  or         $5, $5, $4
    /* 2ECB9C 003ECB9C 00008544 */  mtc1       $5, $f0
    /* 2ECBA0 003ECBA0 00000000 */  nop
    /* 2ECBA4 003ECBA4 A0008046 */  cvt.s.w    $f2, $f0
    /* 2ECBA8 003ECBA8 80100246 */  add.s      $f2, $f2, $f2
  .L003ECBAC:
    /* 2ECBAC 003ECBAC 803B043C */  lui        $4, (0x3B808081 >> 16)
    /* 2ECBB0 003ECBB0 81808434 */  ori        $4, $4, (0x3B808081 & 0xFFFF)
    /* 2ECBB4 003ECBB4 00008444 */  mtc1       $4, $f0
    /* 2ECBB8 003ECBB8 00000000 */  nop
    /* 2ECBBC 003ECBBC 02000246 */  mul.s      $f0, $f0, $f2
    /* 2ECBC0 003ECBC0 040000E5 */  swc1       $f0, 0x4($8)
    /* 2ECBC4 003ECBC4 02006490 */  lbu        $4, 0x2($3)
    /* 2ECBC8 003ECBC8 04008004 */  bltz       $4, .L003ECBDC
    /* 2ECBCC 003ECBCC 00000000 */   nop
    /* 2ECBD0 003ECBD0 00008444 */  mtc1       $4, $f0
    /* 2ECBD4 003ECBD4 08000010 */  b          .L003ECBF8
    /* 2ECBD8 003ECBD8 A0008046 */   cvt.s.w   $f2, $f0
  .L003ECBDC:
    /* 2ECBDC 003ECBDC 42280400 */  srl        $5, $4, 1
    /* 2ECBE0 003ECBE0 01008430 */  andi       $4, $4, 0x1
    /* 2ECBE4 003ECBE4 2528A400 */  or         $5, $5, $4
    /* 2ECBE8 003ECBE8 00008544 */  mtc1       $5, $f0
    /* 2ECBEC 003ECBEC 00000000 */  nop
    /* 2ECBF0 003ECBF0 A0008046 */  cvt.s.w    $f2, $f0
    /* 2ECBF4 003ECBF4 80100246 */  add.s      $f2, $f2, $f2
  .L003ECBF8:
    /* 2ECBF8 003ECBF8 803B043C */  lui        $4, (0x3B808081 >> 16)
    /* 2ECBFC 003ECBFC 81808434 */  ori        $4, $4, (0x3B808081 & 0xFFFF)
    /* 2ECC00 003ECC00 00008444 */  mtc1       $4, $f0
    /* 2ECC04 003ECC04 00000000 */  nop
    /* 2ECC08 003ECC08 02000246 */  mul.s      $f0, $f0, $f2
    /* 2ECC0C 003ECC0C 080000E5 */  swc1       $f0, 0x8($8)
    /* 2ECC10 003ECC10 03006390 */  lbu        $3, 0x3($3)
    /* 2ECC14 003ECC14 04006004 */  bltz       $3, .L003ECC28
    /* 2ECC18 003ECC18 00000000 */   nop
    /* 2ECC1C 003ECC1C 00008344 */  mtc1       $3, $f0
    /* 2ECC20 003ECC20 08000010 */  b          .L003ECC44
    /* 2ECC24 003ECC24 A0008046 */   cvt.s.w   $f2, $f0
  .L003ECC28:
    /* 2ECC28 003ECC28 42200300 */  srl        $4, $3, 1
    /* 2ECC2C 003ECC2C 01006330 */  andi       $3, $3, 0x1
    /* 2ECC30 003ECC30 25208300 */  or         $4, $4, $3
    /* 2ECC34 003ECC34 00008444 */  mtc1       $4, $f0
    /* 2ECC38 003ECC38 00000000 */  nop
    /* 2ECC3C 003ECC3C A0008046 */  cvt.s.w    $f2, $f0
    /* 2ECC40 003ECC40 80100246 */  add.s      $f2, $f2, $f2
  .L003ECC44:
    /* 2ECC44 003ECC44 803B033C */  lui        $3, (0x3B808081 >> 16)
    /* 2ECC48 003ECC48 81806334 */  ori        $3, $3, (0x3B808081 & 0xFFFF)
    /* 2ECC4C 003ECC4C 00008344 */  mtc1       $3, $f0
    /* 2ECC50 003ECC50 00000000 */  nop
    /* 2ECC54 003ECC54 02000246 */  mul.s      $f0, $f0, $f2
    /* 2ECC58 003ECC58 0C0000E5 */  swc1       $f0, 0xC($8)
    /* 2ECC5C 003ECC5C 000000C5 */  lwc1       $f0, 0x0($8)
    /* 2ECC60 003ECC60 02000146 */  mul.s      $f0, $f0, $f1
    /* 2ECC64 003ECC64 000000E5 */  swc1       $f0, 0x0($8)
    /* 2ECC68 003ECC68 040000C5 */  lwc1       $f0, 0x4($8)
    /* 2ECC6C 003ECC6C 02000146 */  mul.s      $f0, $f0, $f1
    /* 2ECC70 003ECC70 040000E5 */  swc1       $f0, 0x4($8)
    /* 2ECC74 003ECC74 080000C5 */  lwc1       $f0, 0x8($8)
    /* 2ECC78 003ECC78 02000146 */  mul.s      $f0, $f0, $f1
    /* 2ECC7C 003ECC7C 080000E5 */  swc1       $f0, 0x8($8)
    /* 2ECC80 003ECC80 0C0000C5 */  lwc1       $f0, 0xC($8)
    /* 2ECC84 003ECC84 02000146 */  mul.s      $f0, $f0, $f1
    /* 2ECC88 003ECC88 0C0000E5 */  swc1       $f0, 0xC($8)
  .L003ECC8C:
    /* 2ECC8C 003ECC8C 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* 2ECC90 003ECC90 00108344 */  mtc1       $3, $f2
    /* 2ECC94 003ECC94 000000C5 */  lwc1       $f0, 0x0($8)
    /* 2ECC98 003ECC98 43100146 */  div.s      $f1, $f2, $f1
    /* 2ECC9C 003ECC9C 02000146 */  mul.s      $f0, $f0, $f1
    /* 2ECCA0 003ECCA0 000000E5 */  swc1       $f0, 0x0($8)
    /* 2ECCA4 003ECCA4 040000C5 */  lwc1       $f0, 0x4($8)
    /* 2ECCA8 003ECCA8 02000146 */  mul.s      $f0, $f0, $f1
    /* 2ECCAC 003ECCAC 040000E5 */  swc1       $f0, 0x4($8)
    /* 2ECCB0 003ECCB0 080000C5 */  lwc1       $f0, 0x8($8)
    /* 2ECCB4 003ECCB4 02000146 */  mul.s      $f0, $f0, $f1
    /* 2ECCB8 003ECCB8 080000E5 */  swc1       $f0, 0x8($8)
    /* 2ECCBC 003ECCBC 0C0000C5 */  lwc1       $f0, 0xC($8)
    /* 2ECCC0 003ECCC0 02000146 */  mul.s      $f0, $f0, $f1
    /* 2ECCC4 003ECCC4 59000010 */  b          .L003ECE2C
    /* 2ECCC8 003ECCC8 0C0000E5 */   swc1      $f0, 0xC($8)
  .L003ECCCC:
    /* 2ECCCC 003ECCCC 00006490 */  lbu        $4, 0x0($3)
  .L003ECCD0:
    /* 2ECCD0 003ECCD0 04008004 */  bltz       $4, .L003ECCE4
    /* 2ECCD4 003ECCD4 00000000 */   nop
    /* 2ECCD8 003ECCD8 00008444 */  mtc1       $4, $f0
    /* 2ECCDC 003ECCDC 08000010 */  b          .L003ECD00
    /* 2ECCE0 003ECCE0 A0008046 */   cvt.s.w   $f2, $f0
  .L003ECCE4:
    /* 2ECCE4 003ECCE4 42280400 */  srl        $5, $4, 1
    /* 2ECCE8 003ECCE8 01008430 */  andi       $4, $4, 0x1
    /* 2ECCEC 003ECCEC 2528A400 */  or         $5, $5, $4
    /* 2ECCF0 003ECCF0 00008544 */  mtc1       $5, $f0
    /* 2ECCF4 003ECCF4 00000000 */  nop
    /* 2ECCF8 003ECCF8 A0008046 */  cvt.s.w    $f2, $f0
    /* 2ECCFC 003ECCFC 80100246 */  add.s      $f2, $f2, $f2
  .L003ECD00:
    /* 2ECD00 003ECD00 803B053C */  lui        $5, (0x3B808081 >> 16)
    /* 2ECD04 003ECD04 01006490 */  lbu        $4, 0x1($3)
    /* 2ECD08 003ECD08 8180A534 */  ori        $5, $5, (0x3B808081 & 0xFFFF)
    /* 2ECD0C 003ECD0C 00008544 */  mtc1       $5, $f0
    /* 2ECD10 003ECD10 04008004 */  bltz       $4, .L003ECD24
    /* 2ECD14 003ECD14 02010246 */   mul.s     $f4, $f0, $f2
    /* 2ECD18 003ECD18 00008444 */  mtc1       $4, $f0
    /* 2ECD1C 003ECD1C 08000010 */  b          .L003ECD40
    /* 2ECD20 003ECD20 A0008046 */   cvt.s.w   $f2, $f0
  .L003ECD24:
    /* 2ECD24 003ECD24 42280400 */  srl        $5, $4, 1
    /* 2ECD28 003ECD28 01008430 */  andi       $4, $4, 0x1
    /* 2ECD2C 003ECD2C 2528A400 */  or         $5, $5, $4
    /* 2ECD30 003ECD30 00008544 */  mtc1       $5, $f0
    /* 2ECD34 003ECD34 00000000 */  nop
    /* 2ECD38 003ECD38 A0008046 */  cvt.s.w    $f2, $f0
    /* 2ECD3C 003ECD3C 80100246 */  add.s      $f2, $f2, $f2
  .L003ECD40:
    /* 2ECD40 003ECD40 803B053C */  lui        $5, (0x3B808081 >> 16)
    /* 2ECD44 003ECD44 02006490 */  lbu        $4, 0x2($3)
    /* 2ECD48 003ECD48 8180A534 */  ori        $5, $5, (0x3B808081 & 0xFFFF)
    /* 2ECD4C 003ECD4C 00008544 */  mtc1       $5, $f0
    /* 2ECD50 003ECD50 04008004 */  bltz       $4, .L003ECD64
    /* 2ECD54 003ECD54 C2010246 */   mul.s     $f7, $f0, $f2
    /* 2ECD58 003ECD58 00008444 */  mtc1       $4, $f0
    /* 2ECD5C 003ECD5C 08000010 */  b          .L003ECD80
    /* 2ECD60 003ECD60 A0008046 */   cvt.s.w   $f2, $f0
  .L003ECD64:
    /* 2ECD64 003ECD64 42280400 */  srl        $5, $4, 1
    /* 2ECD68 003ECD68 01008430 */  andi       $4, $4, 0x1
    /* 2ECD6C 003ECD6C 2528A400 */  or         $5, $5, $4
    /* 2ECD70 003ECD70 00008544 */  mtc1       $5, $f0
    /* 2ECD74 003ECD74 00000000 */  nop
    /* 2ECD78 003ECD78 A0008046 */  cvt.s.w    $f2, $f0
    /* 2ECD7C 003ECD7C 80100246 */  add.s      $f2, $f2, $f2
  .L003ECD80:
    /* 2ECD80 003ECD80 803B043C */  lui        $4, (0x3B808081 >> 16)
    /* 2ECD84 003ECD84 03006390 */  lbu        $3, 0x3($3)
    /* 2ECD88 003ECD88 81808434 */  ori        $4, $4, (0x3B808081 & 0xFFFF)
    /* 2ECD8C 003ECD8C 00008444 */  mtc1       $4, $f0
    /* 2ECD90 003ECD90 04006004 */  bltz       $3, .L003ECDA4
    /* 2ECD94 003ECD94 02020246 */   mul.s     $f8, $f0, $f2
    /* 2ECD98 003ECD98 00008344 */  mtc1       $3, $f0
    /* 2ECD9C 003ECD9C 08000010 */  b          .L003ECDC0
    /* 2ECDA0 003ECDA0 E0008046 */   cvt.s.w   $f3, $f0
  .L003ECDA4:
    /* 2ECDA4 003ECDA4 42200300 */  srl        $4, $3, 1
    /* 2ECDA8 003ECDA8 01006330 */  andi       $3, $3, 0x1
    /* 2ECDAC 003ECDAC 25208300 */  or         $4, $4, $3
    /* 2ECDB0 003ECDB0 00008444 */  mtc1       $4, $f0
    /* 2ECDB4 003ECDB4 00000000 */  nop
    /* 2ECDB8 003ECDB8 E0008046 */  cvt.s.w    $f3, $f0
    /* 2ECDBC 003ECDBC C0180346 */  add.s      $f3, $f3, $f3
  .L003ECDC0:
    /* 2ECDC0 003ECDC0 803B033C */  lui        $3, (0x3B808081 >> 16)
    /* 2ECDC4 003ECDC4 2320C700 */  subu       $4, $6, $7
    /* 2ECDC8 003ECDC8 81806534 */  ori        $5, $3, (0x3B808081 & 0xFFFF)
    /* 2ECDCC 003ECDCC 00108544 */  mtc1       $5, $f2
    /* 2ECDD0 003ECDD0 8037033C */  lui        $3, (0x37800000 >> 16)
    /* 2ECDD4 003ECDD4 00008444 */  mtc1       $4, $f0
    /* 2ECDD8 003ECDD8 82110346 */  mul.s      $f6, $f2, $f3
    /* 2ECDDC 003ECDDC E0008046 */  cvt.s.w    $f3, $f0
    /* 2ECDE0 003ECDE0 00108344 */  mtc1       $3, $f2
    /* 2ECDE4 003ECDE4 000000C5 */  lwc1       $f0, 0x0($8)
    /* 2ECDE8 003ECDE8 42110346 */  mul.s      $f5, $f2, $f3
    /* 2ECDEC 003ECDEC 82200546 */  mul.s      $f2, $f4, $f5
    /* 2ECDF0 003ECDF0 00000246 */  add.s      $f0, $f0, $f2
    /* 2ECDF4 003ECDF4 000000E5 */  swc1       $f0, 0x0($8)
    /* 2ECDF8 003ECDF8 040000C5 */  lwc1       $f0, 0x4($8)
    /* 2ECDFC 003ECDFC 02390546 */  mul.s      $f4, $f7, $f5
    /* 2ECE00 003ECE00 00000446 */  add.s      $f0, $f0, $f4
    /* 2ECE04 003ECE04 040000E5 */  swc1       $f0, 0x4($8)
    /* 2ECE08 003ECE08 080000C5 */  lwc1       $f0, 0x8($8)
    /* 2ECE0C 003ECE0C C2400546 */  mul.s      $f3, $f8, $f5
    /* 2ECE10 003ECE10 00000346 */  add.s      $f0, $f0, $f3
    /* 2ECE14 003ECE14 080000E5 */  swc1       $f0, 0x8($8)
    /* 2ECE18 003ECE18 0C0000C5 */  lwc1       $f0, 0xC($8)
    /* 2ECE1C 003ECE1C 82300546 */  mul.s      $f2, $f6, $f5
    /* 2ECE20 003ECE20 00000246 */  add.s      $f0, $f0, $f2
    /* 2ECE24 003ECE24 99FF0010 */  b          .L003ECC8C
    /* 2ECE28 003ECE28 0C0000E5 */   swc1      $f0, 0xC($8)
  .L003ECE2C:
    /* 2ECE2C 003ECE2C 0800E003 */  jr         $31
    /* 2ECE30 003ECE30 00000000 */   nop
    /* 2ECE34 003ECE34 00000000 */  nop
    /* 2ECE38 003ECE38 00000000 */  nop
    /* 2ECE3C 003ECE3C 00000000 */  nop
.size func_003ec840, 0x600
