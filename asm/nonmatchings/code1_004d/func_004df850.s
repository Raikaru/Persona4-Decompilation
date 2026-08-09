.section .text
.set noat
.set noreorder
glabel func_004df850
    /* 3DF850 004DF850 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3DF854 004DF854 1000B0FF */  sd         $16, 0x10($29)
    /* 3DF858 004DF858 2D808000 */  daddu      $16, $4, $0
    /* 3DF85C 004DF85C 3000B4FF */  sd         $20, 0x30($29)
    /* 3DF860 004DF860 0C001426 */  addiu      $20, $16, 0xC
    /* 3DF864 004DF864 1800B1FF */  sd         $17, 0x18($29)
    /* 3DF868 004DF868 2000B2FF */  sd         $18, 0x20($29)
    /* 3DF86C 004DF86C 2800B3FF */  sd         $19, 0x28($29)
    /* 3DF870 004DF870 3800BFFF */  sd         $31, 0x38($29)
    /* 3DF874 004DF874 06000016 */  bnez       $16, .L004DF890
    /* 3DF878 004DF878 0400138E */   lw        $19, 0x4($16)
    /* 3DF87C 004DF87C 7600043C */  lui        $4, %hi(D_00759B80)
    /* 3DF880 004DF880 B078130C */  jal        func_004de2c0
    /* 3DF884 004DF884 809B8424 */   addiu     $4, $4, %lo(D_00759B80)
    /* 3DF888 004DF888 E4000010 */  b          .L004DFC1C
    /* 3DF88C 004DF88C 1000B0DF */   ld        $16, 0x10($29)
  .L004DF890:
    /* 3DF890 004DF890 01001182 */  lb         $17, 0x1($16)
    /* 3DF894 004DF894 01000224 */  addiu      $2, $0, 0x1
    /* 3DF898 004DF898 A9002216 */  bne        $17, $2, .L004DFB40
    /* 3DF89C 004DF89C 01000392 */   lbu       $3, 0x1($16)
    /* 3DF8A0 004DF8A0 1680130C */  jal        func_004e0058
    /* 3DF8A4 004DF8A4 01000524 */   addiu     $5, $0, 0x1
    /* 3DF8A8 004DF8A8 AC01028E */  lw         $2, 0x1AC($16)
    /* 3DF8AC 004DF8AC 92004014 */  bnez       $2, .L004DFAF8
    /* 3DF8B0 004DF8B0 00000000 */   nop
    /* 3DF8B4 004DF8B4 DC01028E */  lw         $2, 0x1DC($16)
    /* 3DF8B8 004DF8B8 0200422C */  sltiu      $2, $2, 0x2
    /* 3DF8BC 004DF8BC 6E004010 */  beqz       $2, .L004DFA78
    /* 3DF8C0 004DF8C0 00000000 */   nop
    /* 3DF8C4 004DF8C4 FE47130C */  jal        func_004d1ff8
    /* 3DF8C8 004DF8C8 0800048E */   lw        $4, 0x8($16)
    /* 3DF8CC 004DF8CC E080130C */  jal        func_004e0380
    /* 3DF8D0 004DF8D0 2D904000 */   daddu     $18, $2, $0
    /* 3DF8D4 004DF8D4 B2010282 */  lb         $2, 0x1B2($16)
    /* 3DF8D8 004DF8D8 09005114 */  bne        $2, $17, .L004DF900
    /* 3DF8DC 004DF8DC 02000224 */   addiu     $2, $0, 0x2
    /* 3DF8E0 004DF8E0 07004212 */  beq        $18, $2, .L004DF900
    /* 3DF8E4 004DF8E4 00000000 */   nop
    /* 3DF8E8 004DF8E8 E680130C */  jal        func_004e0398
    /* 3DF8EC 004DF8EC B20100A2 */   sb        $0, 0x1B2($16)
    /* 3DF8F0 004DF8F0 C27D130C */  jal        func_004df708
    /* 3DF8F4 004DF8F4 2D200002 */   daddu     $4, $16, $0
    /* 3DF8F8 004DF8F8 03000010 */  b          .L004DF908
    /* 3DF8FC 004DF8FC 00000000 */   nop
  .L004DF900:
    /* 3DF900 004DF900 E680130C */  jal        func_004e0398
    /* 3DF904 004DF904 00000000 */   nop
  .L004DF908:
    /* 3DF908 004DF908 6481130C */  jal        func_004e0590
    /* 3DF90C 004DF90C 2D206002 */   daddu     $4, $19, $0
    /* 3DF910 004DF910 02000324 */  addiu      $3, $0, 0x2
    /* 3DF914 004DF914 8A004354 */  bnel       $2, $3, .L004DFB40
    /* 3DF918 004DF918 01000392 */   lbu       $3, 0x1($16)
    /* 3DF91C 004DF91C 7E81130C */  jal        func_004e05f8
    /* 3DF920 004DF920 2D206002 */   daddu     $4, $19, $0
    /* 3DF924 004DF924 CA81130C */  jal        func_004e0728
    /* 3DF928 004DF928 2D206002 */   daddu     $4, $19, $0
    /* 3DF92C 004DF92C 2D884000 */  daddu      $17, $2, $0
    /* 3DF930 004DF930 05002012 */  beqz       $17, .L004DF948
    /* 3DF934 004DF934 01000224 */   addiu     $2, $0, 0x1
    /* 3DF938 004DF938 37002252 */  beql       $17, $2, .L004DFA18
    /* 3DF93C 004DF93C 0800048E */   lw        $4, 0x8($16)
    /* 3DF940 004DF940 4B000010 */  b          .L004DFA70
    /* 3DF944 004DF944 01000392 */   lbu       $3, 0x1($16)
  .L004DF948:
    /* 3DF948 004DF948 C001118E */  lw         $17, 0x1C0($16)
    /* 3DF94C 004DF94C 06002006 */  bltz       $17, .L004DF968
    /* 3DF950 004DF950 BC0111AE */   sw        $17, 0x1BC($16)
    /* 3DF954 004DF954 8881130C */  jal        func_004e0620
    /* 3DF958 004DF958 0400048E */   lw        $4, 0x4($16)
    /* 3DF95C 004DF95C 2A102202 */  slt        $2, $17, $2
    /* 3DF960 004DF960 05004014 */  bnez       $2, .L004DF978
    /* 3DF964 004DF964 2D30A003 */   daddu     $6, $29, $0
  .L004DF968:
    /* 3DF968 004DF968 03000224 */  addiu      $2, $0, 0x3
    /* 3DF96C 004DF96C AA000010 */  b          .L004DFC18
    /* 3DF970 004DF970 010002A2 */   sb        $2, 0x1($16)
    /* 3DF974 004DF974 00000000 */  nop
  .L004DF978:
    /* 3DF978 004DF978 0400A727 */  addiu      $7, $29, 0x4
    /* 3DF97C 004DF97C 2D282002 */  daddu      $5, $17, $0
    /* 3DF980 004DF980 9681130C */  jal        func_004e0658
    /* 3DF984 004DF984 2D206002 */   daddu     $4, $19, $0
    /* 3DF988 004DF988 0800048E */  lw         $4, 0x8($16)
    /* 3DF98C 004DF98C 0000A58F */  lw         $5, 0x0($29)
    /* 3DF990 004DF990 FF07A324 */  addiu      $3, $5, 0x7FF
    /* 3DF994 004DF994 0000A228 */  slti       $2, $5, 0x0
    /* 3DF998 004DF998 0B286200 */  movn       $5, $3, $2
    /* 3DF99C 004DF99C 0E48130C */  jal        func_004d2038
    /* 3DF9A0 004DF9A0 C32A0500 */   sra       $5, $5, 11
    /* 3DF9A4 004DF9A4 0800048E */  lw         $4, 0x8($16)
    /* 3DF9A8 004DF9A8 0400A28F */  lw         $2, 0x4($29)
    /* 3DF9AC 004DF9AC 0000A58F */  lw         $5, 0x0($29)
    /* 3DF9B0 004DF9B0 2128A200 */  addu       $5, $5, $2
    /* 3DF9B4 004DF9B4 FF07A324 */  addiu      $3, $5, 0x7FF
    /* 3DF9B8 004DF9B8 0000A228 */  slti       $2, $5, 0x0
    /* 3DF9BC 004DF9BC 0B286200 */  movn       $5, $3, $2
    /* 3DF9C0 004DF9C0 EA48130C */  jal        func_004d23a8
    /* 3DF9C4 004DF9C4 C32A0500 */   sra       $5, $5, 11
    /* 3DF9C8 004DF9C8 2D206002 */  daddu      $4, $19, $0
    /* 3DF9CC 004DF9CC 7A81130C */  jal        func_004e05e8
    /* 3DF9D0 004DF9D0 2D280000 */   daddu     $5, $0, $0
    /* 3DF9D4 004DF9D4 B0010282 */  lb         $2, 0x1B0($16)
    /* 3DF9D8 004DF9D8 01000324 */  addiu      $3, $0, 0x1
    /* 3DF9DC 004DF9DC 05004310 */  beq        $2, $3, .L004DF9F4
    /* 3DF9E0 004DF9E0 2D206002 */   daddu     $4, $19, $0
    /* 3DF9E4 004DF9E4 B1010282 */  lb         $2, 0x1B1($16)
    /* 3DF9E8 004DF9E8 05004314 */  bne        $2, $3, .L004DFA00
    /* 3DF9EC 004DF9EC 2D200002 */   daddu     $4, $16, $0
    /* 3DF9F0 004DF9F0 2D206002 */  daddu      $4, $19, $0
  .L004DF9F4:
    /* 3DF9F4 004DF9F4 7C81130C */  jal        func_004e05f0
    /* 3DF9F8 004DF9F8 01000524 */   addiu     $5, $0, 0x1
    /* 3DF9FC 004DF9FC 2D200002 */  daddu      $4, $16, $0
  .L004DFA00:
    /* 3DFA00 004DFA00 5680130C */  jal        func_004e0158
    /* 3DFA04 004DFA04 01000524 */   addiu     $5, $0, 0x1
    /* 3DFA08 004DFA08 3680130C */  jal        func_004e00d8
    /* 3DFA0C 004DFA0C 2D200002 */   daddu     $4, $16, $0
    /* 3DFA10 004DFA10 16000010 */  b          .L004DFA6C
    /* 3DFA14 004DFA14 01000224 */   addiu     $2, $0, 0x1
  .L004DFA18:
    /* 3DFA18 004DFA18 EA48130C */  jal        func_004d23a8
    /* 3DFA1C 004DFA1C FFFF0524 */   addiu     $5, $0, -0x1
    /* 3DFA20 004DFA20 2D206002 */  daddu      $4, $19, $0
    /* 3DFA24 004DFA24 7A81130C */  jal        func_004e05e8
    /* 3DFA28 004DFA28 2D280000 */   daddu     $5, $0, $0
    /* 3DFA2C 004DFA2C B0010282 */  lb         $2, 0x1B0($16)
    /* 3DFA30 004DFA30 05005110 */  beq        $2, $17, .L004DFA48
    /* 3DFA34 004DFA34 2D206002 */   daddu     $4, $19, $0
    /* 3DFA38 004DFA38 B1010282 */  lb         $2, 0x1B1($16)
    /* 3DFA3C 004DFA3C 05005154 */  bnel       $2, $17, .L004DFA54
    /* 3DFA40 004DFA40 0C00048E */   lw        $4, 0xC($16)
    /* 3DFA44 004DFA44 2D206002 */  daddu      $4, $19, $0
  .L004DFA48:
    /* 3DFA48 004DFA48 7C81130C */  jal        func_004e05f0
    /* 3DFA4C 004DFA4C 01000524 */   addiu     $5, $0, 0x1
    /* 3DFA50 004DFA50 0C00048E */  lw         $4, 0xC($16)
  .L004DFA54:
    /* 3DFA54 004DFA54 6E59130C */  jal        func_004d65b8
    /* 3DFA58 004DFA58 01000524 */   addiu     $5, $0, 0x1
    /* 3DFA5C 004DFA5C 0000848E */  lw         $4, 0x0($20)
    /* 3DFA60 004DFA60 5C50130C */  jal        func_004d4170
    /* 3DFA64 004DFA64 9400058E */   lw        $5, 0x94($16)
    /* 3DFA68 004DFA68 01000224 */  addiu      $2, $0, 0x1
  .L004DFA6C:
    /* 3DFA6C 004DFA6C 01000392 */  lbu        $3, 0x1($16)
  .L004DFA70:
    /* 3DFA70 004DFA70 33000010 */  b          .L004DFB40
    /* 3DFA74 004DFA74 AC0102AE */   sw        $2, 0x1AC($16)
  .L004DFA78:
    /* 3DFA78 004DFA78 6481130C */  jal        func_004e0590
    /* 3DFA7C 004DFA7C 2D206002 */   daddu     $4, $19, $0
    /* 3DFA80 004DFA80 2D184000 */  daddu      $3, $2, $0
    /* 3DFA84 004DFA84 16006014 */  bnez       $3, .L004DFAE0
    /* 3DFA88 004DFA88 02000224 */   addiu     $2, $0, 0x2
    /* 3DFA8C 004DFA8C 03000282 */  lb         $2, 0x3($16)
    /* 3DFA90 004DFA90 2A106200 */  slt        $2, $3, $2
    /* 3DFA94 004DFA94 0D004010 */  beqz       $2, .L004DFACC
    /* 3DFA98 004DFA98 2D900000 */   daddu     $18, $0, $0
    /* 3DFA9C 004DFA9C 94001126 */  addiu      $17, $16, 0x94
    /* 3DFAA0 004DFAA0 0000248E */  lw         $4, 0x0($17)
    /* 3DFAA4 004DFAA4 00000000 */  nop
  .L004DFAA8:
    /* 3DFAA8 004DFAA8 04003126 */  addiu      $17, $17, 0x4
    /* 3DFAAC 004DFAAC 0000828C */  lw         $2, 0x0($4)
    /* 3DFAB0 004DFAB0 1400438C */  lw         $3, 0x14($2)
    /* 3DFAB4 004DFAB4 09F86000 */  jalr       $3
    /* 3DFAB8 004DFAB8 01005226 */   addiu     $18, $18, 0x1
    /* 3DFABC 004DFABC 03000282 */  lb         $2, 0x3($16)
    /* 3DFAC0 004DFAC0 2A104202 */  slt        $2, $18, $2
    /* 3DFAC4 004DFAC4 F8FF4054 */  bnel       $2, $0, .L004DFAA8
    /* 3DFAC8 004DFAC8 0000248E */   lw        $4, 0x0($17)
  .L004DFACC:
    /* 3DFACC 004DFACC 6681130C */  jal        func_004e0598
    /* 3DFAD0 004DFAD0 2D206002 */   daddu     $4, $19, $0
    /* 3DFAD4 004DFAD4 1A000010 */  b          .L004DFB40
    /* 3DFAD8 004DFAD8 01000392 */   lbu       $3, 0x1($16)
    /* 3DFADC 004DFADC 00000000 */  nop
  .L004DFAE0:
    /* 3DFAE0 004DFAE0 17006254 */  bnel       $3, $2, .L004DFB40
    /* 3DFAE4 004DFAE4 01000392 */   lbu       $3, 0x1($16)
    /* 3DFAE8 004DFAE8 3680130C */  jal        func_004e00d8
    /* 3DFAEC 004DFAEC 2D200002 */   daddu     $4, $16, $0
    /* 3DFAF0 004DFAF0 12000010 */  b          .L004DFB3C
    /* 3DFAF4 004DFAF4 AC0111AE */   sw        $17, 0x1AC($16)
  .L004DFAF8:
    /* 3DFAF8 004DFAF8 7080130C */  jal        func_004e01c0
    /* 3DFAFC 004DFAFC 2D200002 */   daddu     $4, $16, $0
    /* 3DFB00 004DFB00 0F005154 */  bnel       $2, $17, .L004DFB40
    /* 3DFB04 004DFB04 01000392 */   lbu       $3, 0x1($16)
    /* 3DFB08 004DFB08 E080130C */  jal        func_004e0380
    /* 3DFB0C 004DFB0C 00000000 */   nop
    /* 3DFB10 004DFB10 A801028E */  lw         $2, 0x1A8($16)
    /* 3DFB14 004DFB14 03004014 */  bnez       $2, .L004DFB24
    /* 3DFB18 004DFB18 2D200002 */   daddu     $4, $16, $0
    /* 3DFB1C 004DFB1C 1680130C */  jal        func_004e0058
    /* 3DFB20 004DFB20 2D280000 */   daddu     $5, $0, $0
  .L004DFB24:
    /* 3DFB24 004DFB24 C67B130C */  jal        func_004def18
    /* 3DFB28 004DFB28 2D200002 */   daddu     $4, $16, $0
    /* 3DFB2C 004DFB2C 02000224 */  addiu      $2, $0, 0x2
    /* 3DFB30 004DFB30 010002A2 */  sb         $2, 0x1($16)
    /* 3DFB34 004DFB34 E680130C */  jal        func_004e0398
    /* 3DFB38 004DFB38 AC0100AE */   sw        $0, 0x1AC($16)
  .L004DFB3C:
    /* 3DFB3C 004DFB3C 01000392 */  lbu        $3, 0x1($16)
  .L004DFB40:
    /* 3DFB40 004DFB40 00160300 */  sll        $2, $3, 24
    /* 3DFB44 004DFB44 02000324 */  addiu      $3, $0, 0x2
    /* 3DFB48 004DFB48 038E0200 */  sra        $17, $2, 24
    /* 3DFB4C 004DFB4C 25002316 */  bne        $17, $3, .L004DFBE4
    /* 3DFB50 004DFB50 00000000 */   nop
    /* 3DFB54 004DFB54 CA81130C */  jal        func_004e0728
    /* 3DFB58 004DFB58 2D206002 */   daddu     $4, $19, $0
    /* 3DFB5C 004DFB5C 2D184000 */  daddu      $3, $2, $0
    /* 3DFB60 004DFB60 05006010 */  beqz       $3, .L004DFB78
    /* 3DFB64 004DFB64 01000224 */   addiu     $2, $0, 0x1
    /* 3DFB68 004DFB68 11006210 */  beq        $3, $2, .L004DFBB0
    /* 3DFB6C 004DFB6C 00000000 */   nop
    /* 3DFB70 004DFB70 1C000010 */  b          .L004DFBE4
    /* 3DFB74 004DFB74 00000000 */   nop
  .L004DFB78:
    /* 3DFB78 004DFB78 6481130C */  jal        func_004e0590
    /* 3DFB7C 004DFB7C 2D206002 */   daddu     $4, $19, $0
    /* 3DFB80 004DFB80 2D884000 */  daddu      $17, $2, $0
    /* 3DFB84 004DFB84 03000224 */  addiu      $2, $0, 0x3
    /* 3DFB88 004DFB88 16002216 */  bne        $17, $2, .L004DFBE4
    /* 3DFB8C 004DFB8C 00000000 */   nop
    /* 3DFB90 004DFB90 9A80130C */  jal        func_004e0268
    /* 3DFB94 004DFB94 2D200002 */   daddu     $4, $16, $0
    /* 3DFB98 004DFB98 01000324 */  addiu      $3, $0, 0x1
    /* 3DFB9C 004DFB9C 11004350 */  beql       $2, $3, .L004DFBE4
    /* 3DFBA0 004DFBA0 010011A2 */   sb        $17, 0x1($16)
    /* 3DFBA4 004DFBA4 0F000010 */  b          .L004DFBE4
    /* 3DFBA8 004DFBA8 00000000 */   nop
    /* 3DFBAC 004DFBAC 00000000 */  nop
  .L004DFBB0:
    /* 3DFBB0 004DFBB0 FE47130C */  jal        func_004d1ff8
    /* 3DFBB4 004DFBB4 0800048E */   lw        $4, 0x8($16)
    /* 3DFBB8 004DFBB8 0A005110 */  beq        $2, $17, .L004DFBE4
    /* 3DFBBC 004DFBBC 00000000 */   nop
    /* 3DFBC0 004DFBC0 FE50130C */  jal        func_004d43f8
    /* 3DFBC4 004DFBC4 0C00048E */   lw        $4, 0xC($16)
    /* 3DFBC8 004DFBC8 2D184000 */  daddu      $3, $2, $0
    /* 3DFBCC 004DFBCC 05000224 */  addiu      $2, $0, 0x5
    /* 3DFBD0 004DFBD0 03006210 */  beq        $3, $2, .L004DFBE0
    /* 3DFBD4 004DFBD4 03000224 */   addiu     $2, $0, 0x3
    /* 3DFBD8 004DFBD8 02006014 */  bnez       $3, .L004DFBE4
    /* 3DFBDC 004DFBDC 00000000 */   nop
  .L004DFBE0:
    /* 3DFBE0 004DFBE0 010002A2 */  sb         $2, 0x1($16)
  .L004DFBE4:
    /* 3DFBE4 004DFBE4 E080130C */  jal        func_004e0380
    /* 3DFBE8 004DFBE8 00000000 */   nop
    /* 3DFBEC 004DFBEC 0800048E */  lw         $4, 0x8($16)
    /* 3DFBF0 004DFBF0 07008010 */  beqz       $4, .L004DFC10
    /* 3DFBF4 004DFBF4 00000000 */   nop
    /* 3DFBF8 004DFBF8 FE47130C */  jal        func_004d1ff8
    /* 3DFBFC 004DFBFC 00000000 */   nop
    /* 3DFC00 004DFC00 2D184000 */  daddu      $3, $2, $0
    /* 3DFC04 004DFC04 04000224 */  addiu      $2, $0, 0x4
    /* 3DFC08 004DFC08 01006250 */  beql       $3, $2, .L004DFC10
    /* 3DFC0C 004DFC0C 010003A2 */   sb        $3, 0x1($16)
  .L004DFC10:
    /* 3DFC10 004DFC10 E680130C */  jal        func_004e0398
    /* 3DFC14 004DFC14 00000000 */   nop
  .L004DFC18:
    /* 3DFC18 004DFC18 1000B0DF */  ld         $16, 0x10($29)
  .L004DFC1C:
    /* 3DFC1C 004DFC1C 1800B1DF */  ld         $17, 0x18($29)
    /* 3DFC20 004DFC20 2000B2DF */  ld         $18, 0x20($29)
    /* 3DFC24 004DFC24 2800B3DF */  ld         $19, 0x28($29)
    /* 3DFC28 004DFC28 3000B4DF */  ld         $20, 0x30($29)
    /* 3DFC2C 004DFC2C 3800BFDF */  ld         $31, 0x38($29)
    /* 3DFC30 004DFC30 0800E003 */  jr         $31
    /* 3DFC34 004DFC34 4000BD27 */   addiu     $29, $29, 0x40
.size func_004df850, 0x3e8
