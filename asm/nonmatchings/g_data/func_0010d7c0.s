.section .text
.set noat
.set noreorder
glabel func_0010d7c0
    /* D7C0 0010D7C0 20FFBD27 */  addiu      $29, $29, -0xE0
    /* D7C4 0010D7C4 8000BFFF */  sd         $31, 0x80($29)
    /* D7C8 0010D7C8 7000B77F */  sq         $23, 0x70($29)
    /* D7CC 0010D7CC 6000B67F */  sq         $22, 0x60($29)
    /* D7D0 0010D7D0 5000B57F */  sq         $21, 0x50($29)
    /* D7D4 0010D7D4 4000B47F */  sq         $20, 0x40($29)
    /* D7D8 0010D7D8 3000B37F */  sq         $19, 0x30($29)
    /* D7DC 0010D7DC 2000B27F */  sq         $18, 0x20($29)
    /* D7E0 0010D7E0 1000B17F */  sq         $17, 0x10($29)
    /* D7E4 0010D7E4 0000B07F */  sq         $16, 0x0($29)
    /* D7E8 0010D7E8 9C00A4AF */  sw         $4, 0x9C($29)
    /* D7EC 0010D7EC 2DB8A000 */  daddu      $23, $5, $0
    /* D7F0 0010D7F0 2D98C000 */  daddu      $19, $6, $0
    /* D7F4 0010D7F4 B09D848F */  lw         $4, -0x6250($28)
    /* D7F8 0010D7F8 0000838C */  lw         $3, 0x0($4)
    /* D7FC 0010D7FC 7A00023C */  lui        $2, %hi(D_0079B698)
    /* D800 0010D800 98B643AC */  sw         $3, %lo(D_0079B698)($2)
    /* D804 0010D804 0400838C */  lw         $3, 0x4($4)
    /* D808 0010D808 7A00023C */  lui        $2, %hi(D_0079B69C)
    /* D80C 0010D80C 9CB643AC */  sw         $3, %lo(D_0079B69C)($2)
    /* D810 0010D810 5868050C */  jal        func_0015a160
    /* D814 0010D814 00000000 */   nop
    /* D818 0010D818 7A00033C */  lui        $3, %hi(D_0079B6A0)
    /* D81C 0010D81C A0B662AC */  sw         $2, %lo(D_0079B6A0)($3)
    /* D820 0010D820 5E00043C */  lui        $4, %hi(D_005E4298)
    /* D824 0010D824 98428424 */  addiu      $4, $4, %lo(D_005E4298)
    /* D828 0010D828 21070524 */  addiu      $5, $0, 0x721
    /* D82C 0010D82C A43A110C */  jal        func_0044ea90
    /* D830 0010D830 00000000 */   nop
    /* D834 0010D834 01000424 */  addiu      $4, $0, 0x1
    /* D838 0010D838 0200023C */  lui        $2, (0x2A000 >> 16)
    /* D83C 0010D83C 00A04534 */  ori        $5, $2, (0x2A000 & 0xFFFF)
    /* D840 0010D840 0400063C */  lui        $6, (0x40000 >> 16)
    /* D844 0010D844 8800023C */  lui        $2, %hi(D_008873F4)
    /* D848 0010D848 F473428C */  lw         $2, %lo(D_008873F4)($2)
    /* D84C 0010D84C 09F84000 */  jalr       $2
    /* D850 0010D850 00000000 */   nop
    /* D854 0010D854 2D904000 */  daddu      $18, $2, $0
    /* D858 0010D858 D800A0AF */  sw         $0, 0xD8($29)
    /* D85C 0010D85C 2D800000 */  daddu      $16, $0, $0
    /* D860 0010D860 2D204002 */  daddu      $4, $18, $0
    /* D864 0010D864 9C00A527 */  addiu      $5, $29, 0x9C
    /* D868 0010D868 04000624 */  addiu      $6, $0, 0x4
    /* D86C 0010D86C 04FE100C */  jal        func_0043f810
    /* D870 0010D870 00000000 */   nop
    /* D874 0010D874 9CB1838F */  lw         $3, -0x4E64($28)
    /* D878 0010D878 A400A3AF */  sw         $3, 0xA4($29)
    /* D87C 0010D87C 7A00023C */  lui        $2, %hi(D_0079B67C)
    /* D880 0010D880 7CB643AC */  sw         $3, %lo(D_0079B67C)($2)
    /* D884 0010D884 7900023C */  lui        $2, %hi(D_00797B7A)
    /* D888 0010D888 7A7B4284 */  lh         $2, %lo(D_00797B7A)($2)
    /* D88C 0010D88C A000A2A7 */  sh         $2, 0xA0($29)
    /* D890 0010D890 7900023C */  lui        $2, %hi(D_00797B7C)
    /* D894 0010D894 7C7B4290 */  lbu        $2, %lo(D_00797B7C)($2)
    /* D898 0010D898 A200A2A7 */  sh         $2, 0xA2($29)
    /* D89C 0010D89C 2D280000 */  daddu      $5, $0, $0
    /* D8A0 0010D8A0 7900043C */  lui        $4, %hi(D_007973A0)
    /* D8A4 0010D8A4 A0738424 */  addiu      $4, $4, %lo(D_007973A0)
    /* D8A8 0010D8A8 06000010 */  b          .L0010D8C4
    /* D8AC 0010D8AC 00000000 */   nop
  .L0010D8B0:
    /* D8B0 0010D8B0 21108500 */  addu       $2, $4, $5
    /* D8B4 0010D8B4 00004380 */  lb         $3, 0x0($2)
    /* D8B8 0010D8B8 2110BD00 */  addu       $2, $5, $29
    /* D8BC 0010D8BC AC0043A0 */  sb         $3, 0xAC($2)
    /* D8C0 0010D8C0 0100A524 */  addiu      $5, $5, 0x1
  .L0010D8C4:
    /* D8C4 0010D8C4 1200A22C */  sltiu      $2, $5, 0x12
    /* D8C8 0010D8C8 F9FF4014 */  bnez       $2, .L0010D8B0
    /* D8CC 0010D8CC 00000000 */   nop
    /* D8D0 0010D8D0 2D280000 */  daddu      $5, $0, $0
    /* D8D4 0010D8D4 7900043C */  lui        $4, %hi(D_007973A0)
    /* D8D8 0010D8D8 A0738424 */  addiu      $4, $4, %lo(D_007973A0)
    /* D8DC 0010D8DC 06000010 */  b          .L0010D8F8
    /* D8E0 0010D8E0 00000000 */   nop
  .L0010D8E4:
    /* D8E4 0010D8E4 21108500 */  addu       $2, $4, $5
    /* D8E8 0010D8E8 12004380 */  lb         $3, 0x12($2)
    /* D8EC 0010D8EC 2110BD00 */  addu       $2, $5, $29
    /* D8F0 0010D8F0 BE0043A0 */  sb         $3, 0xBE($2)
    /* D8F4 0010D8F4 0100A524 */  addiu      $5, $5, 0x1
  .L0010D8F8:
    /* D8F8 0010D8F8 1200A22C */  sltiu      $2, $5, 0x12
    /* D8FC 0010D8FC F9FF4014 */  bnez       $2, .L0010D8E4
    /* D900 0010D900 00000000 */   nop
    /* D904 0010D904 B09D838F */  lw         $3, -0x6250($28)
    /* D908 0010D908 0000628C */  lw         $2, 0x0($3)
    /* D90C 0010D90C D000A2A3 */  sb         $2, 0xD0($29)
    /* D910 0010D910 0400628C */  lw         $2, 0x4($3)
    /* D914 0010D914 D100A2A3 */  sb         $2, 0xD1($29)
    /* D918 0010D918 7900023C */  lui        $2, %hi(D_00797400)
    /* D91C 0010D91C 0074448C */  lw         $4, %lo(D_00797400)($2)
    /* D920 0010D920 2D280000 */  daddu      $5, $0, $0
    /* D924 0010D924 2D300000 */  daddu      $6, $0, $0
    /* D928 0010D928 5E00033C */  lui        $3, %hi(D_005DD6E0)
    /* D92C 0010D92C E0D66324 */  addiu      $3, $3, %lo(D_005DD6E0)
    /* D930 0010D930 0F000010 */  b          .L0010D970
    /* D934 0010D934 00000000 */   nop
  .L0010D938:
    /* D938 0010D938 FF00C230 */  andi       $2, $6, 0xFF
    /* D93C 0010D93C 80100200 */  sll        $2, $2, 2
    /* D940 0010D940 21106200 */  addu       $2, $3, $2
    /* D944 0010D944 0000428C */  lw         $2, 0x0($2)
    /* D948 0010D948 2A088200 */  slt        $1, $4, $2
    /* D94C 0010D94C 04002010 */  beqz       $1, .L0010D960
    /* D950 0010D950 00000000 */   nop
    /* D954 0010D954 FF00A230 */  andi       $2, $5, 0xFF
    /* D958 0010D958 0A000010 */  b          .L0010D984
    /* D95C 0010D95C 00000000 */   nop
  .L0010D960:
    /* D960 0010D960 0100A224 */  addiu      $2, $5, 0x1
    /* D964 0010D964 FF004530 */  andi       $5, $2, 0xFF
    /* D968 0010D968 0100C224 */  addiu      $2, $6, 0x1
    /* D96C 0010D96C FF004630 */  andi       $6, $2, 0xFF
  .L0010D970:
    /* D970 0010D970 FF00C230 */  andi       $2, $6, 0xFF
    /* D974 0010D974 63004228 */  slti       $2, $2, 0x63
    /* D978 0010D978 EFFF4014 */  bnez       $2, .L0010D938
    /* D97C 0010D97C 00000000 */   nop
    /* D980 0010D980 63000264 */  daddiu     $2, $0, 0x63
  .L0010D984:
    /* D984 0010D984 A800A2A3 */  sb         $2, 0xA8($29)
    /* D988 0010D988 1841040C */  jal        func_00110460
    /* D98C 0010D98C 00000000 */   nop
    /* D990 0010D990 AA00A2A3 */  sb         $2, 0xAA($29)
    /* D994 0010D994 7A00023C */  lui        $2, %hi(D_0079B3CC)
    /* D998 0010D998 CCB3438C */  lw         $3, %lo(D_0079B3CC)($2)
    /* D99C 0010D99C 0100023C */  lui        $2, (0x10000 >> 16)
    /* D9A0 0010D9A0 24106200 */  and        $2, $3, $2
    /* D9A4 0010D9A4 04004010 */  beqz       $2, .L0010D9B8
    /* D9A8 0010D9A8 00000000 */   nop
    /* D9AC 0010D9AC A900A0A3 */  sb         $0, 0xA9($29)
    /* D9B0 0010D9B0 0B000010 */  b          .L0010D9E0
    /* D9B4 0010D9B4 00000000 */   nop
  .L0010D9B8:
    /* D9B8 0010D9B8 0200023C */  lui        $2, (0x20000 >> 16)
    /* D9BC 0010D9BC 24106200 */  and        $2, $3, $2
    /* D9C0 0010D9C0 05004010 */  beqz       $2, .L0010D9D8
    /* D9C4 0010D9C4 00000000 */   nop
    /* D9C8 0010D9C8 02000224 */  addiu      $2, $0, 0x2
    /* D9CC 0010D9CC A900A2A3 */  sb         $2, 0xA9($29)
    /* D9D0 0010D9D0 03000010 */  b          .L0010D9E0
    /* D9D4 0010D9D4 00000000 */   nop
  .L0010D9D8:
    /* D9D8 0010D9D8 01000224 */  addiu      $2, $0, 0x1
    /* D9DC 0010D9DC A900A2A3 */  sb         $2, 0xA9($29)
  .L0010D9E0:
    /* D9E0 0010D9E0 A000A327 */  addiu      $3, $29, 0xA0
    /* D9E4 0010D9E4 2D280000 */  daddu      $5, $0, $0
    /* D9E8 0010D9E8 2D200000 */  daddu      $4, $0, $0
    /* D9EC 0010D9EC 06000010 */  b          .L0010DA08
    /* D9F0 0010D9F0 00000000 */   nop
  .L0010D9F4:
    /* D9F4 0010D9F4 21106400 */  addu       $2, $3, $4
    /* D9F8 0010D9F8 00004290 */  lbu        $2, 0x0($2)
    /* D9FC 0010D9FC 2110A200 */  addu       $2, $5, $2
    /* DA00 0010DA00 FF004530 */  andi       $5, $2, 0xFF
    /* DA04 0010DA04 01008424 */  addiu      $4, $4, 0x1
  .L0010DA08:
    /* DA08 0010DA08 3200822C */  sltiu      $2, $4, 0x32
    /* DA0C 0010DA0C F9FF4014 */  bnez       $2, .L0010D9F4
    /* DA10 0010DA10 00000000 */   nop
    /* DA14 0010DA14 FF00A230 */  andi       $2, $5, 0xFF
    /* DA18 0010DA18 D200A2A7 */  sh         $2, 0xD2($29)
    /* DA1C 0010DA1C 04004426 */  addiu      $4, $18, 0x4
    /* DA20 0010DA20 A000A527 */  addiu      $5, $29, 0xA0
    /* DA24 0010DA24 34000624 */  addiu      $6, $0, 0x34
    /* DA28 0010DA28 04FE100C */  jal        func_0043f810
    /* DA2C 0010DA2C 00000000 */   nop
    /* DA30 0010DA30 38005626 */  addiu      $22, $18, 0x38
    /* DA34 0010DA34 01000224 */  addiu      $2, $0, 0x1
    /* DA38 0010DA38 D800A2AF */  sw         $2, 0xD8($29)
    /* DA3C 0010DA3C 2D20C002 */  daddu      $4, $22, $0
    /* DA40 0010DA40 D800A527 */  addiu      $5, $29, 0xD8
    /* DA44 0010DA44 04000624 */  addiu      $6, $0, 0x4
    /* DA48 0010DA48 04FE100C */  jal        func_0043f810
    /* DA4C 0010DA4C 00000000 */   nop
    /* DA50 0010DA50 24000224 */  addiu      $2, $0, 0x24
    /* DA54 0010DA54 D400A2AF */  sw         $2, 0xD4($29)
    /* DA58 0010DA58 3C004426 */  addiu      $4, $18, 0x3C
    /* DA5C 0010DA5C D400A527 */  addiu      $5, $29, 0xD4
    /* DA60 0010DA60 04000624 */  addiu      $6, $0, 0x4
    /* DA64 0010DA64 04FE100C */  jal        func_0043f810
    /* DA68 0010DA68 00000000 */   nop
    /* DA6C 0010DA6C 40004426 */  addiu      $4, $18, 0x40
    /* DA70 0010DA70 7900053C */  lui        $5, %hi(D_007973A0)
    /* DA74 0010DA74 A073A524 */  addiu      $5, $5, %lo(D_007973A0)
    /* DA78 0010DA78 24000624 */  addiu      $6, $0, 0x24
    /* DA7C 0010DA7C 04FE100C */  jal        func_0043f810
    /* DA80 0010DA80 00000000 */   nop
    /* DA84 0010DA84 02000224 */  addiu      $2, $0, 0x2
    /* DA88 0010DA88 D800A2AF */  sw         $2, 0xD8($29)
    /* DA8C 0010DA8C 64004426 */  addiu      $4, $18, 0x64
    /* DA90 0010DA90 D800A527 */  addiu      $5, $29, 0xD8
    /* DA94 0010DA94 04000624 */  addiu      $6, $0, 0x4
    /* DA98 0010DA98 04FE100C */  jal        func_0043f810
    /* DA9C 0010DA9C 00000000 */   nop
    /* DAA0 0010DAA0 48000224 */  addiu      $2, $0, 0x48
    /* DAA4 0010DAA4 D400A2AF */  sw         $2, 0xD4($29)
    /* DAA8 0010DAA8 68004426 */  addiu      $4, $18, 0x68
    /* DAAC 0010DAAC D400A527 */  addiu      $5, $29, 0xD4
    /* DAB0 0010DAB0 04000624 */  addiu      $6, $0, 0x4
    /* DAB4 0010DAB4 04FE100C */  jal        func_0043f810
    /* DAB8 0010DAB8 00000000 */   nop
    /* DABC 0010DABC 6C004426 */  addiu      $4, $18, 0x6C
    /* DAC0 0010DAC0 7900053C */  lui        $5, %hi(D_007973C4)
    /* DAC4 0010DAC4 C473A524 */  addiu      $5, $5, %lo(D_007973C4)
    /* DAC8 0010DAC8 48000624 */  addiu      $6, $0, 0x48
    /* DACC 0010DACC 04FE100C */  jal        func_0043f810
    /* DAD0 0010DAD0 00000000 */   nop
    /* DAD4 0010DAD4 03000224 */  addiu      $2, $0, 0x3
    /* DAD8 0010DAD8 D800A2AF */  sw         $2, 0xD8($29)
    /* DADC 0010DADC B4004426 */  addiu      $4, $18, 0xB4
    /* DAE0 0010DAE0 D800A527 */  addiu      $5, $29, 0xD8
    /* DAE4 0010DAE4 04000624 */  addiu      $6, $0, 0x4
    /* DAE8 0010DAE8 04FE100C */  jal        func_0043f810
    /* DAEC 0010DAEC 00000000 */   nop
    /* DAF0 0010DAF0 58010224 */  addiu      $2, $0, 0x158
    /* DAF4 0010DAF4 D400A2AF */  sw         $2, 0xD4($29)
    /* DAF8 0010DAF8 B8004426 */  addiu      $4, $18, 0xB8
    /* DAFC 0010DAFC D400A527 */  addiu      $5, $29, 0xD4
    /* DB00 0010DB00 04000624 */  addiu      $6, $0, 0x4
    /* DB04 0010DB04 04FE100C */  jal        func_0043f810
    /* DB08 0010DB08 00000000 */   nop
    /* DB0C 0010DB0C BC004426 */  addiu      $4, $18, 0xBC
    /* DB10 0010DB10 7900053C */  lui        $5, %hi(D_0079740C)
    /* DB14 0010DB14 0C74A524 */  addiu      $5, $5, %lo(D_0079740C)
    /* DB18 0010DB18 58010624 */  addiu      $6, $0, 0x158
    /* DB1C 0010DB1C 04FE100C */  jal        func_0043f810
    /* DB20 0010DB20 00000000 */   nop
    /* DB24 0010DB24 04000624 */  addiu      $6, $0, 0x4
    /* DB28 0010DB28 D800A6AF */  sw         $6, 0xD8($29)
    /* DB2C 0010DB2C 14024426 */  addiu      $4, $18, 0x214
    /* DB30 0010DB30 D800A527 */  addiu      $5, $29, 0xD8
    /* DB34 0010DB34 04FE100C */  jal        func_0043f810
    /* DB38 0010DB38 00000000 */   nop
    /* DB3C 0010DB3C 10000224 */  addiu      $2, $0, 0x10
    /* DB40 0010DB40 D400A2AF */  sw         $2, 0xD4($29)
    /* DB44 0010DB44 18024426 */  addiu      $4, $18, 0x218
    /* DB48 0010DB48 D400A527 */  addiu      $5, $29, 0xD4
    /* DB4C 0010DB4C 04000624 */  addiu      $6, $0, 0x4
    /* DB50 0010DB50 04FE100C */  jal        func_0043f810
    /* DB54 0010DB54 00000000 */   nop
    /* DB58 0010DB58 1C024426 */  addiu      $4, $18, 0x21C
    /* DB5C 0010DB5C 7900053C */  lui        $5, %hi(D_00797564)
    /* DB60 0010DB60 6475A524 */  addiu      $5, $5, %lo(D_00797564)
    /* DB64 0010DB64 10000624 */  addiu      $6, $0, 0x10
    /* DB68 0010DB68 04FE100C */  jal        func_0043f810
    /* DB6C 0010DB6C 00000000 */   nop
    /* DB70 0010DB70 05000224 */  addiu      $2, $0, 0x5
    /* DB74 0010DB74 D800A2AF */  sw         $2, 0xD8($29)
    /* DB78 0010DB78 2C024426 */  addiu      $4, $18, 0x22C
    /* DB7C 0010DB7C D800A527 */  addiu      $5, $29, 0xD8
    /* DB80 0010DB80 04000624 */  addiu      $6, $0, 0x4
    /* DB84 0010DB84 04FE100C */  jal        func_0043f810
    /* DB88 0010DB88 00000000 */   nop
    /* DB8C 0010DB8C 06000224 */  addiu      $2, $0, 0x6
    /* DB90 0010DB90 D400A2AF */  sw         $2, 0xD4($29)
    /* DB94 0010DB94 30024426 */  addiu      $4, $18, 0x230
    /* DB98 0010DB98 D400A527 */  addiu      $5, $29, 0xD4
    /* DB9C 0010DB9C 04000624 */  addiu      $6, $0, 0x4
    /* DBA0 0010DBA0 04FE100C */  jal        func_0043f810
    /* DBA4 0010DBA4 00000000 */   nop
    /* DBA8 0010DBA8 34024426 */  addiu      $4, $18, 0x234
    /* DBAC 0010DBAC 7900053C */  lui        $5, %hi(D_00797574)
    /* DBB0 0010DBB0 7475A524 */  addiu      $5, $5, %lo(D_00797574)
    /* DBB4 0010DBB4 06000624 */  addiu      $6, $0, 0x6
    /* DBB8 0010DBB8 04FE100C */  jal        func_0043f810
    /* DBBC 0010DBBC 00000000 */   nop
    /* DBC0 0010DBC0 06000224 */  addiu      $2, $0, 0x6
    /* DBC4 0010DBC4 D800A2AF */  sw         $2, 0xD8($29)
    /* DBC8 0010DBC8 3A024426 */  addiu      $4, $18, 0x23A
    /* DBCC 0010DBCC D800A527 */  addiu      $5, $29, 0xD8
    /* DBD0 0010DBD0 04000624 */  addiu      $6, $0, 0x4
    /* DBD4 0010DBD4 04FE100C */  jal        func_0043f810
    /* DBD8 0010DBD8 00000000 */   nop
    /* DBDC 0010DBDC 00060224 */  addiu      $2, $0, 0x600
    /* DBE0 0010DBE0 D400A2AF */  sw         $2, 0xD4($29)
    /* DBE4 0010DBE4 3E024426 */  addiu      $4, $18, 0x23E
    /* DBE8 0010DBE8 D400A527 */  addiu      $5, $29, 0xD4
    /* DBEC 0010DBEC 04000624 */  addiu      $6, $0, 0x4
    /* DBF0 0010DBF0 04FE100C */  jal        func_0043f810
    /* DBF4 0010DBF4 00000000 */   nop
    /* DBF8 0010DBF8 42024426 */  addiu      $4, $18, 0x242
    /* DBFC 0010DBFC 7900053C */  lui        $5, %hi(D_0079757A)
    /* DC00 0010DC00 7A75A524 */  addiu      $5, $5, %lo(D_0079757A)
    /* DC04 0010DC04 00060624 */  addiu      $6, $0, 0x600
    /* DC08 0010DC08 04FE100C */  jal        func_0043f810
    /* DC0C 0010DC0C 00000000 */   nop
    /* DC10 0010DC10 08000224 */  addiu      $2, $0, 0x8
    /* DC14 0010DC14 D800A2AF */  sw         $2, 0xD8($29)
    /* DC18 0010DC18 42084426 */  addiu      $4, $18, 0x842
    /* DC1C 0010DC1C D800A527 */  addiu      $5, $29, 0xD8
    /* DC20 0010DC20 04000624 */  addiu      $6, $0, 0x4
    /* DC24 0010DC24 04FE100C */  jal        func_0043f810
    /* DC28 0010DC28 00000000 */   nop
    /* DC2C 0010DC2C 02000224 */  addiu      $2, $0, 0x2
    /* DC30 0010DC30 D400A2AF */  sw         $2, 0xD4($29)
    /* DC34 0010DC34 46084426 */  addiu      $4, $18, 0x846
    /* DC38 0010DC38 D400A527 */  addiu      $5, $29, 0xD4
    /* DC3C 0010DC3C 04000624 */  addiu      $6, $0, 0x4
    /* DC40 0010DC40 04FE100C */  jal        func_0043f810
    /* DC44 0010DC44 00000000 */   nop
    /* DC48 0010DC48 4A084426 */  addiu      $4, $18, 0x84A
    /* DC4C 0010DC4C 7900053C */  lui        $5, %hi(D_00797B7A)
    /* DC50 0010DC50 7A7BA524 */  addiu      $5, $5, %lo(D_00797B7A)
    /* DC54 0010DC54 02000624 */  addiu      $6, $0, 0x2
    /* DC58 0010DC58 04FE100C */  jal        func_0043f810
    /* DC5C 0010DC5C 00000000 */   nop
    /* DC60 0010DC60 09000224 */  addiu      $2, $0, 0x9
    /* DC64 0010DC64 D800A2AF */  sw         $2, 0xD8($29)
    /* DC68 0010DC68 4C084426 */  addiu      $4, $18, 0x84C
    /* DC6C 0010DC6C D800A527 */  addiu      $5, $29, 0xD8
    /* DC70 0010DC70 04000624 */  addiu      $6, $0, 0x4
    /* DC74 0010DC74 04FE100C */  jal        func_0043f810
    /* DC78 0010DC78 00000000 */   nop
    /* DC7C 0010DC7C 01000224 */  addiu      $2, $0, 0x1
    /* DC80 0010DC80 D400A2AF */  sw         $2, 0xD4($29)
    /* DC84 0010DC84 50084426 */  addiu      $4, $18, 0x850
    /* DC88 0010DC88 D400A527 */  addiu      $5, $29, 0xD4
    /* DC8C 0010DC8C 04000624 */  addiu      $6, $0, 0x4
    /* DC90 0010DC90 04FE100C */  jal        func_0043f810
    /* DC94 0010DC94 00000000 */   nop
    /* DC98 0010DC98 54084426 */  addiu      $4, $18, 0x854
    /* DC9C 0010DC9C 7900053C */  lui        $5, %hi(D_00797B7C)
    /* DCA0 0010DCA0 7C7BA524 */  addiu      $5, $5, %lo(D_00797B7C)
    /* DCA4 0010DCA4 01000624 */  addiu      $6, $0, 0x1
    /* DCA8 0010DCA8 04FE100C */  jal        func_0043f810
    /* DCAC 0010DCAC 00000000 */   nop
    /* DCB0 0010DCB0 0A000224 */  addiu      $2, $0, 0xA
    /* DCB4 0010DCB4 D800A2AF */  sw         $2, 0xD8($29)
    /* DCB8 0010DCB8 55084426 */  addiu      $4, $18, 0x855
    /* DCBC 0010DCBC D800A527 */  addiu      $5, $29, 0xD8
    /* DCC0 0010DCC0 04000624 */  addiu      $6, $0, 0x4
    /* DCC4 0010DCC4 04FE100C */  jal        func_0043f810
    /* DCC8 0010DCC8 00000000 */   nop
    /* DCCC 0010DCCC 04000624 */  addiu      $6, $0, 0x4
    /* DCD0 0010DCD0 D400A6AF */  sw         $6, 0xD4($29)
    /* DCD4 0010DCD4 59084426 */  addiu      $4, $18, 0x859
    /* DCD8 0010DCD8 D400A527 */  addiu      $5, $29, 0xD4
    /* DCDC 0010DCDC 04FE100C */  jal        func_0043f810
    /* DCE0 0010DCE0 00000000 */   nop
    /* DCE4 0010DCE4 5D084426 */  addiu      $4, $18, 0x85D
    /* DCE8 0010DCE8 7900053C */  lui        $5, %hi(D_00797B80)
    /* DCEC 0010DCEC 807BA524 */  addiu      $5, $5, %lo(D_00797B80)
    /* DCF0 0010DCF0 04000624 */  addiu      $6, $0, 0x4
    /* DCF4 0010DCF4 04FE100C */  jal        func_0043f810
    /* DCF8 0010DCF8 00000000 */   nop
    /* DCFC 0010DCFC 0B000224 */  addiu      $2, $0, 0xB
    /* DD00 0010DD00 D800A2AF */  sw         $2, 0xD8($29)
    /* DD04 0010DD04 61084426 */  addiu      $4, $18, 0x861
    /* DD08 0010DD08 D800A527 */  addiu      $5, $29, 0xD8
    /* DD0C 0010DD0C 04000624 */  addiu      $6, $0, 0x4
    /* DD10 0010DD10 04FE100C */  jal        func_0043f810
    /* DD14 0010DD14 00000000 */   nop
    /* DD18 0010DD18 02000224 */  addiu      $2, $0, 0x2
    /* DD1C 0010DD1C D400A2AF */  sw         $2, 0xD4($29)
    /* DD20 0010DD20 65084426 */  addiu      $4, $18, 0x865
    /* DD24 0010DD24 D400A527 */  addiu      $5, $29, 0xD4
    /* DD28 0010DD28 04000624 */  addiu      $6, $0, 0x4
    /* DD2C 0010DD2C 04FE100C */  jal        func_0043f810
    /* DD30 0010DD30 00000000 */   nop
    /* DD34 0010DD34 69084426 */  addiu      $4, $18, 0x869
    /* DD38 0010DD38 7900053C */  lui        $5, %hi(D_00797B84)
    /* DD3C 0010DD3C 847BA524 */  addiu      $5, $5, %lo(D_00797B84)
    /* DD40 0010DD40 02000624 */  addiu      $6, $0, 0x2
    /* DD44 0010DD44 04FE100C */  jal        func_0043f810
    /* DD48 0010DD48 00000000 */   nop
    /* DD4C 0010DD4C 0C000224 */  addiu      $2, $0, 0xC
    /* DD50 0010DD50 D800A2AF */  sw         $2, 0xD8($29)
    /* DD54 0010DD54 6B084426 */  addiu      $4, $18, 0x86B
    /* DD58 0010DD58 D800A527 */  addiu      $5, $29, 0xD8
    /* DD5C 0010DD5C 04000624 */  addiu      $6, $0, 0x4
    /* DD60 0010DD60 04FE100C */  jal        func_0043f810
    /* DD64 0010DD64 00000000 */   nop
    /* DD68 0010DD68 01000224 */  addiu      $2, $0, 0x1
    /* DD6C 0010DD6C D400A2AF */  sw         $2, 0xD4($29)
    /* DD70 0010DD70 6F084426 */  addiu      $4, $18, 0x86F
    /* DD74 0010DD74 D400A527 */  addiu      $5, $29, 0xD4
    /* DD78 0010DD78 04000624 */  addiu      $6, $0, 0x4
    /* DD7C 0010DD7C 04FE100C */  jal        func_0043f810
    /* DD80 0010DD80 00000000 */   nop
    /* DD84 0010DD84 73084426 */  addiu      $4, $18, 0x873
    /* DD88 0010DD88 7900053C */  lui        $5, %hi(D_00797B86)
    /* DD8C 0010DD8C 867BA524 */  addiu      $5, $5, %lo(D_00797B86)
    /* DD90 0010DD90 01000624 */  addiu      $6, $0, 0x1
    /* DD94 0010DD94 04FE100C */  jal        func_0043f810
    /* DD98 0010DD98 00000000 */   nop
    /* DD9C 0010DD9C 0D000224 */  addiu      $2, $0, 0xD
    /* DDA0 0010DDA0 D800A2AF */  sw         $2, 0xD8($29)
    /* DDA4 0010DDA4 74084426 */  addiu      $4, $18, 0x874
    /* DDA8 0010DDA8 D800A527 */  addiu      $5, $29, 0xD8
    /* DDAC 0010DDAC 04000624 */  addiu      $6, $0, 0x4
    /* DDB0 0010DDB0 04FE100C */  jal        func_0043f810
    /* DDB4 0010DDB4 00000000 */   nop
    /* DDB8 0010DDB8 00040224 */  addiu      $2, $0, 0x400
    /* DDBC 0010DDBC D400A2AF */  sw         $2, 0xD4($29)
    /* DDC0 0010DDC0 78084426 */  addiu      $4, $18, 0x878
    /* DDC4 0010DDC4 D400A527 */  addiu      $5, $29, 0xD4
    /* DDC8 0010DDC8 04000624 */  addiu      $6, $0, 0x4
    /* DDCC 0010DDCC 04FE100C */  jal        func_0043f810
    /* DDD0 0010DDD0 00000000 */   nop
    /* DDD4 0010DDD4 7C084426 */  addiu      $4, $18, 0x87C
    /* DDD8 0010DDD8 7900053C */  lui        $5, %hi(D_00797B87)
    /* DDDC 0010DDDC 877BA524 */  addiu      $5, $5, %lo(D_00797B87)
    /* DDE0 0010DDE0 00040624 */  addiu      $6, $0, 0x400
    /* DDE4 0010DDE4 04FE100C */  jal        func_0043f810
    /* DDE8 0010DDE8 00000000 */   nop
    /* DDEC 0010DDEC 0E000224 */  addiu      $2, $0, 0xE
    /* DDF0 0010DDF0 D800A2AF */  sw         $2, 0xD8($29)
    /* DDF4 0010DDF4 7C0C4426 */  addiu      $4, $18, 0xC7C
    /* DDF8 0010DDF8 D800A527 */  addiu      $5, $29, 0xD8
    /* DDFC 0010DDFC 04000624 */  addiu      $6, $0, 0x4
    /* DE00 0010DE00 04FE100C */  jal        func_0043f810
    /* DE04 0010DE04 00000000 */   nop
    /* DE08 0010DE08 02000224 */  addiu      $2, $0, 0x2
    /* DE0C 0010DE0C D400A2AF */  sw         $2, 0xD4($29)
    /* DE10 0010DE10 800C4426 */  addiu      $4, $18, 0xC80
    /* DE14 0010DE14 D400A527 */  addiu      $5, $29, 0xD4
    /* DE18 0010DE18 04000624 */  addiu      $6, $0, 0x4
    /* DE1C 0010DE1C 04FE100C */  jal        func_0043f810
    /* DE20 0010DE20 00000000 */   nop
    /* DE24 0010DE24 840C4426 */  addiu      $4, $18, 0xC84
    /* DE28 0010DE28 7900053C */  lui        $5, %hi(D_00797F88)
    /* DE2C 0010DE2C 887FA524 */  addiu      $5, $5, %lo(D_00797F88)
    /* DE30 0010DE30 02000624 */  addiu      $6, $0, 0x2
    /* DE34 0010DE34 04FE100C */  jal        func_0043f810
    /* DE38 0010DE38 00000000 */   nop
    /* DE3C 0010DE3C 0F000224 */  addiu      $2, $0, 0xF
    /* DE40 0010DE40 D800A2AF */  sw         $2, 0xD8($29)
    /* DE44 0010DE44 860C4426 */  addiu      $4, $18, 0xC86
    /* DE48 0010DE48 D800A527 */  addiu      $5, $29, 0xD8
    /* DE4C 0010DE4C 04000624 */  addiu      $6, $0, 0x4
    /* DE50 0010DE50 04FE100C */  jal        func_0043f810
    /* DE54 0010DE54 00000000 */   nop
    /* DE58 0010DE58 40020224 */  addiu      $2, $0, 0x240
    /* DE5C 0010DE5C D400A2AF */  sw         $2, 0xD4($29)
    /* DE60 0010DE60 8A0C4426 */  addiu      $4, $18, 0xC8A
    /* DE64 0010DE64 D400A527 */  addiu      $5, $29, 0xD4
    /* DE68 0010DE68 04000624 */  addiu      $6, $0, 0x4
    /* DE6C 0010DE6C 04FE100C */  jal        func_0043f810
    /* DE70 0010DE70 00000000 */   nop
    /* DE74 0010DE74 8E0C4426 */  addiu      $4, $18, 0xC8E
    /* DE78 0010DE78 7900053C */  lui        $5, %hi(D_00797F8C)
    /* DE7C 0010DE7C 8C7FA524 */  addiu      $5, $5, %lo(D_00797F8C)
    /* DE80 0010DE80 40020624 */  addiu      $6, $0, 0x240
    /* DE84 0010DE84 04FE100C */  jal        func_0043f810
    /* DE88 0010DE88 00000000 */   nop
    /* DE8C 0010DE8C 10000224 */  addiu      $2, $0, 0x10
    /* DE90 0010DE90 D800A2AF */  sw         $2, 0xD8($29)
    /* DE94 0010DE94 CE0E4426 */  addiu      $4, $18, 0xECE
    /* DE98 0010DE98 D800A527 */  addiu      $5, $29, 0xD8
    /* DE9C 0010DE9C 04000624 */  addiu      $6, $0, 0x4
    /* DEA0 0010DEA0 04FE100C */  jal        func_0043f810
    /* DEA4 0010DEA4 00000000 */   nop
    /* DEA8 0010DEA8 00300224 */  addiu      $2, $0, 0x3000
    /* DEAC 0010DEAC D400A2AF */  sw         $2, 0xD4($29)
    /* DEB0 0010DEB0 D20E4426 */  addiu      $4, $18, 0xED2
    /* DEB4 0010DEB4 D400A527 */  addiu      $5, $29, 0xD4
    /* DEB8 0010DEB8 04000624 */  addiu      $6, $0, 0x4
    /* DEBC 0010DEBC 04FE100C */  jal        func_0043f810
    /* DEC0 0010DEC0 00000000 */   nop
    /* DEC4 0010DEC4 D60E4426 */  addiu      $4, $18, 0xED6
    /* DEC8 0010DEC8 7A00053C */  lui        $5, %hi(D_007981CC)
    /* DECC 0010DECC CC81A524 */  addiu      $5, $5, %lo(D_007981CC)
    /* DED0 0010DED0 00300624 */  addiu      $6, $0, 0x3000
    /* DED4 0010DED4 04FE100C */  jal        func_0043f810
    /* DED8 0010DED8 00000000 */   nop
    /* DEDC 0010DEDC 11000224 */  addiu      $2, $0, 0x11
    /* DEE0 0010DEE0 D800A2AF */  sw         $2, 0xD8($29)
    /* DEE4 0010DEE4 D63E4426 */  addiu      $4, $18, 0x3ED6
    /* DEE8 0010DEE8 D800A527 */  addiu      $5, $29, 0xD8
    /* DEEC 0010DEEC 04000624 */  addiu      $6, $0, 0x4
    /* DEF0 0010DEF0 04FE100C */  jal        func_0043f810
    /* DEF4 0010DEF4 00000000 */   nop
    /* DEF8 0010DEF8 C0020224 */  addiu      $2, $0, 0x2C0
    /* DEFC 0010DEFC D400A2AF */  sw         $2, 0xD4($29)
    /* DF00 0010DF00 DA3E4426 */  addiu      $4, $18, 0x3EDA
    /* DF04 0010DF04 D400A527 */  addiu      $5, $29, 0xD4
    /* DF08 0010DF08 04000624 */  addiu      $6, $0, 0x4
    /* DF0C 0010DF0C 04FE100C */  jal        func_0043f810
    /* DF10 0010DF10 00000000 */   nop
    /* DF14 0010DF14 DE3E4426 */  addiu      $4, $18, 0x3EDE
    /* DF18 0010DF18 7A00053C */  lui        $5, %hi(D_0079B1CC)
    /* DF1C 0010DF1C CCB1A524 */  addiu      $5, $5, %lo(D_0079B1CC)
    /* DF20 0010DF20 C0020624 */  addiu      $6, $0, 0x2C0
    /* DF24 0010DF24 04FE100C */  jal        func_0043f810
    /* DF28 0010DF28 00000000 */   nop
    /* DF2C 0010DF2C 12000224 */  addiu      $2, $0, 0x12
    /* DF30 0010DF30 D800A2AF */  sw         $2, 0xD8($29)
    /* DF34 0010DF34 9E414426 */  addiu      $4, $18, 0x419E
    /* DF38 0010DF38 D800A527 */  addiu      $5, $29, 0xD8
    /* DF3C 0010DF3C 04000624 */  addiu      $6, $0, 0x4
    /* DF40 0010DF40 04FE100C */  jal        func_0043f810
    /* DF44 0010DF44 00000000 */   nop
    /* DF48 0010DF48 04000624 */  addiu      $6, $0, 0x4
    /* DF4C 0010DF4C D400A6AF */  sw         $6, 0xD4($29)
    /* DF50 0010DF50 A2414426 */  addiu      $4, $18, 0x41A2
    /* DF54 0010DF54 D400A527 */  addiu      $5, $29, 0xD4
    /* DF58 0010DF58 04FE100C */  jal        func_0043f810
    /* DF5C 0010DF5C 00000000 */   nop
    /* DF60 0010DF60 A6414426 */  addiu      $4, $18, 0x41A6
    /* DF64 0010DF64 7A00053C */  lui        $5, %hi(D_0079B68C)
    /* DF68 0010DF68 8CB6A524 */  addiu      $5, $5, %lo(D_0079B68C)
    /* DF6C 0010DF6C 04000624 */  addiu      $6, $0, 0x4
    /* DF70 0010DF70 04FE100C */  jal        func_0043f810
    /* DF74 0010DF74 00000000 */   nop
    /* DF78 0010DF78 13000224 */  addiu      $2, $0, 0x13
    /* DF7C 0010DF7C D800A2AF */  sw         $2, 0xD8($29)
    /* DF80 0010DF80 AA414426 */  addiu      $4, $18, 0x41AA
    /* DF84 0010DF84 D800A527 */  addiu      $5, $29, 0xD8
    /* DF88 0010DF88 04000624 */  addiu      $6, $0, 0x4
    /* DF8C 0010DF8C 04FE100C */  jal        func_0043f810
    /* DF90 0010DF90 00000000 */   nop
    /* DF94 0010DF94 08000224 */  addiu      $2, $0, 0x8
    /* DF98 0010DF98 D400A2AF */  sw         $2, 0xD4($29)
    /* DF9C 0010DF9C AE414426 */  addiu      $4, $18, 0x41AE
    /* DFA0 0010DFA0 D400A527 */  addiu      $5, $29, 0xD4
    /* DFA4 0010DFA4 04000624 */  addiu      $6, $0, 0x4
    /* DFA8 0010DFA8 04FE100C */  jal        func_0043f810
    /* DFAC 0010DFAC 00000000 */   nop
    /* DFB0 0010DFB0 B2414426 */  addiu      $4, $18, 0x41B2
    /* DFB4 0010DFB4 7A00053C */  lui        $5, %hi(D_0079B690)
    /* DFB8 0010DFB8 90B6A524 */  addiu      $5, $5, %lo(D_0079B690)
    /* DFBC 0010DFBC 08000624 */  addiu      $6, $0, 0x8
    /* DFC0 0010DFC0 04FE100C */  jal        func_0043f810
    /* DFC4 0010DFC4 00000000 */   nop
    /* DFC8 0010DFC8 15000224 */  addiu      $2, $0, 0x15
    /* DFCC 0010DFCC D800A2AF */  sw         $2, 0xD8($29)
    /* DFD0 0010DFD0 BA414426 */  addiu      $4, $18, 0x41BA
    /* DFD4 0010DFD4 D800A527 */  addiu      $5, $29, 0xD8
    /* DFD8 0010DFD8 04000624 */  addiu      $6, $0, 0x4
    /* DFDC 0010DFDC 04FE100C */  jal        func_0043f810
    /* DFE0 0010DFE0 00000000 */   nop
    /* DFE4 0010DFE4 04000624 */  addiu      $6, $0, 0x4
    /* DFE8 0010DFE8 D400A6AF */  sw         $6, 0xD4($29)
    /* DFEC 0010DFEC BE414426 */  addiu      $4, $18, 0x41BE
    /* DFF0 0010DFF0 D400A527 */  addiu      $5, $29, 0xD4
    /* DFF4 0010DFF4 04FE100C */  jal        func_0043f810
    /* DFF8 0010DFF8 00000000 */   nop
    /* DFFC 0010DFFC C2414426 */  addiu      $4, $18, 0x41C2
    /* E000 0010E000 7A00053C */  lui        $5, %hi(D_0079B698)
    /* E004 0010E004 98B6A524 */  addiu      $5, $5, %lo(D_0079B698)
    /* E008 0010E008 04000624 */  addiu      $6, $0, 0x4
    /* E00C 0010E00C 04FE100C */  jal        func_0043f810
    /* E010 0010E010 00000000 */   nop
    /* E014 0010E014 16000224 */  addiu      $2, $0, 0x16
    /* E018 0010E018 D800A2AF */  sw         $2, 0xD8($29)
    /* E01C 0010E01C C6414426 */  addiu      $4, $18, 0x41C6
    /* E020 0010E020 D800A527 */  addiu      $5, $29, 0xD8
    /* E024 0010E024 04000624 */  addiu      $6, $0, 0x4
    /* E028 0010E028 04FE100C */  jal        func_0043f810
    /* E02C 0010E02C 00000000 */   nop
    /* E030 0010E030 04000624 */  addiu      $6, $0, 0x4
    /* E034 0010E034 D400A6AF */  sw         $6, 0xD4($29)
    /* E038 0010E038 CA414426 */  addiu      $4, $18, 0x41CA
    /* E03C 0010E03C D400A527 */  addiu      $5, $29, 0xD4
    /* E040 0010E040 04FE100C */  jal        func_0043f810
    /* E044 0010E044 00000000 */   nop
    /* E048 0010E048 CE414426 */  addiu      $4, $18, 0x41CE
    /* E04C 0010E04C 7A00053C */  lui        $5, %hi(D_0079B69C)
    /* E050 0010E050 9CB6A524 */  addiu      $5, $5, %lo(D_0079B69C)
    /* E054 0010E054 04000624 */  addiu      $6, $0, 0x4
    /* E058 0010E058 04FE100C */  jal        func_0043f810
    /* E05C 0010E05C 00000000 */   nop
    /* E060 0010E060 17000224 */  addiu      $2, $0, 0x17
    /* E064 0010E064 D800A2AF */  sw         $2, 0xD8($29)
    /* E068 0010E068 D2414426 */  addiu      $4, $18, 0x41D2
    /* E06C 0010E06C D800A527 */  addiu      $5, $29, 0xD8
    /* E070 0010E070 04000624 */  addiu      $6, $0, 0x4
    /* E074 0010E074 04FE100C */  jal        func_0043f810
    /* E078 0010E078 00000000 */   nop
    /* E07C 0010E07C 04000624 */  addiu      $6, $0, 0x4
    /* E080 0010E080 D400A6AF */  sw         $6, 0xD4($29)
    /* E084 0010E084 D6414426 */  addiu      $4, $18, 0x41D6
    /* E088 0010E088 D400A527 */  addiu      $5, $29, 0xD4
    /* E08C 0010E08C 04FE100C */  jal        func_0043f810
    /* E090 0010E090 00000000 */   nop
    /* E094 0010E094 DA414426 */  addiu      $4, $18, 0x41DA
    /* E098 0010E098 7A00053C */  lui        $5, %hi(D_0079B6A0)
    /* E09C 0010E09C A0B6A524 */  addiu      $5, $5, %lo(D_0079B6A0)
    /* E0A0 0010E0A0 04000624 */  addiu      $6, $0, 0x4
    /* E0A4 0010E0A4 04FE100C */  jal        func_0043f810
    /* E0A8 0010E0A8 00000000 */   nop
    /* E0AC 0010E0AC 18000224 */  addiu      $2, $0, 0x18
    /* E0B0 0010E0B0 D800A2AF */  sw         $2, 0xD8($29)
    /* E0B4 0010E0B4 DE414426 */  addiu      $4, $18, 0x41DE
    /* E0B8 0010E0B8 D800A527 */  addiu      $5, $29, 0xD8
    /* E0BC 0010E0BC 04000624 */  addiu      $6, $0, 0x4
    /* E0C0 0010E0C0 04FE100C */  jal        func_0043f810
    /* E0C4 0010E0C4 00000000 */   nop
    /* E0C8 0010E0C8 54010224 */  addiu      $2, $0, 0x154
    /* E0CC 0010E0CC D400A2AF */  sw         $2, 0xD4($29)
    /* E0D0 0010E0D0 E2414426 */  addiu      $4, $18, 0x41E2
    /* E0D4 0010E0D4 D400A527 */  addiu      $5, $29, 0xD4
    /* E0D8 0010E0D8 04000624 */  addiu      $6, $0, 0x4
    /* E0DC 0010E0DC 04FE100C */  jal        func_0043f810
    /* E0E0 0010E0E0 00000000 */   nop
    /* E0E4 0010E0E4 E6414426 */  addiu      $4, $18, 0x41E6
    /* E0E8 0010E0E8 7A00053C */  lui        $5, %hi(D_0079BCD8)
    /* E0EC 0010E0EC D8BCA524 */  addiu      $5, $5, %lo(D_0079BCD8)
    /* E0F0 0010E0F0 54010624 */  addiu      $6, $0, 0x154
    /* E0F4 0010E0F4 04FE100C */  jal        func_0043f810
    /* E0F8 0010E0F8 00000000 */   nop
    /* E0FC 0010E0FC 19000224 */  addiu      $2, $0, 0x19
    /* E100 0010E100 D800A2AF */  sw         $2, 0xD8($29)
    /* E104 0010E104 3A434426 */  addiu      $4, $18, 0x433A
    /* E108 0010E108 D800A527 */  addiu      $5, $29, 0xD8
    /* E10C 0010E10C 04000624 */  addiu      $6, $0, 0x4
    /* E110 0010E110 04FE100C */  jal        func_0043f810
    /* E114 0010E114 00000000 */   nop
    /* E118 0010E118 00020224 */  addiu      $2, $0, 0x200
    /* E11C 0010E11C D400A2AF */  sw         $2, 0xD4($29)
    /* E120 0010E120 3E434426 */  addiu      $4, $18, 0x433E
    /* E124 0010E124 D400A527 */  addiu      $5, $29, 0xD4
    /* E128 0010E128 04000624 */  addiu      $6, $0, 0x4
    /* E12C 0010E12C 04FE100C */  jal        func_0043f810
    /* E130 0010E130 00000000 */   nop
    /* E134 0010E134 42434426 */  addiu      $4, $18, 0x4342
    /* E138 0010E138 7A00053C */  lui        $5, %hi(D_0079B48C)
    /* E13C 0010E13C 8CB4A524 */  addiu      $5, $5, %lo(D_0079B48C)
    /* E140 0010E140 00020624 */  addiu      $6, $0, 0x200
    /* E144 0010E144 04FE100C */  jal        func_0043f810
    /* E148 0010E148 00000000 */   nop
    /* E14C 0010E14C 1A000224 */  addiu      $2, $0, 0x1A
    /* E150 0010E150 D800A2AF */  sw         $2, 0xD8($29)
    /* E154 0010E154 42454426 */  addiu      $4, $18, 0x4542
    /* E158 0010E158 D800A527 */  addiu      $5, $29, 0xD8
    /* E15C 0010E15C 04000624 */  addiu      $6, $0, 0x4
    /* E160 0010E160 04FE100C */  jal        func_0043f810
    /* E164 0010E164 00000000 */   nop
    /* E168 0010E168 00060224 */  addiu      $2, $0, 0x600
    /* E16C 0010E16C D400A2AF */  sw         $2, 0xD4($29)
    /* E170 0010E170 46454426 */  addiu      $4, $18, 0x4546
    /* E174 0010E174 D400A527 */  addiu      $5, $29, 0xD4
    /* E178 0010E178 04000624 */  addiu      $6, $0, 0x4
    /* E17C 0010E17C 04FE100C */  jal        func_0043f810
    /* E180 0010E180 00000000 */   nop
    /* E184 0010E184 4A454426 */  addiu      $4, $18, 0x454A
    /* E188 0010E188 7A00053C */  lui        $5, %hi(D_0079B6D8)
    /* E18C 0010E18C D8B6A524 */  addiu      $5, $5, %lo(D_0079B6D8)
    /* E190 0010E190 00060624 */  addiu      $6, $0, 0x600
    /* E194 0010E194 04FE100C */  jal        func_0043f810
    /* E198 0010E198 00000000 */   nop
    /* E19C 0010E19C 1B000224 */  addiu      $2, $0, 0x1B
    /* E1A0 0010E1A0 D800A2AF */  sw         $2, 0xD8($29)
    /* E1A4 0010E1A4 4A4B4426 */  addiu      $4, $18, 0x4B4A
    /* E1A8 0010E1A8 D800A527 */  addiu      $5, $29, 0xD8
    /* E1AC 0010E1AC 04000624 */  addiu      $6, $0, 0x4
    /* E1B0 0010E1B0 04FE100C */  jal        func_0043f810
    /* E1B4 0010E1B4 00000000 */   nop
    /* E1B8 0010E1B8 34000224 */  addiu      $2, $0, 0x34
    /* E1BC 0010E1BC D400A2AF */  sw         $2, 0xD4($29)
    /* E1C0 0010E1C0 4E4B4426 */  addiu      $4, $18, 0x4B4E
    /* E1C4 0010E1C4 D400A527 */  addiu      $5, $29, 0xD4
    /* E1C8 0010E1C8 04000624 */  addiu      $6, $0, 0x4
    /* E1CC 0010E1CC 04FE100C */  jal        func_0043f810
    /* E1D0 0010E1D0 00000000 */   nop
    /* E1D4 0010E1D4 524B4426 */  addiu      $4, $18, 0x4B52
    /* E1D8 0010E1D8 7A00053C */  lui        $5, %hi(D_0079B6A4)
    /* E1DC 0010E1DC A4B6A524 */  addiu      $5, $5, %lo(D_0079B6A4)
    /* E1E0 0010E1E0 34000624 */  addiu      $6, $0, 0x34
    /* E1E4 0010E1E4 04FE100C */  jal        func_0043f810
    /* E1E8 0010E1E8 00000000 */   nop
    /* E1EC 0010E1EC 22000224 */  addiu      $2, $0, 0x22
    /* E1F0 0010E1F0 D800A2AF */  sw         $2, 0xD8($29)
    /* E1F4 0010E1F4 864B4426 */  addiu      $4, $18, 0x4B86
    /* E1F8 0010E1F8 D800A527 */  addiu      $5, $29, 0xD8
    /* E1FC 0010E1FC 04000624 */  addiu      $6, $0, 0x4
    /* E200 0010E200 04FE100C */  jal        func_0043f810
    /* E204 0010E204 00000000 */   nop
    /* E208 0010E208 01000224 */  addiu      $2, $0, 0x1
    /* E20C 0010E20C D400A2AF */  sw         $2, 0xD4($29)
    /* E210 0010E210 8A4B4426 */  addiu      $4, $18, 0x4B8A
    /* E214 0010E214 D400A527 */  addiu      $5, $29, 0xD4
    /* E218 0010E218 04000624 */  addiu      $6, $0, 0x4
    /* E21C 0010E21C 04FE100C */  jal        func_0043f810
    /* E220 0010E220 00000000 */   nop
    /* E224 0010E224 8E4B4426 */  addiu      $4, $18, 0x4B8E
    /* E228 0010E228 7900053C */  lui        $5, %hi(D_00797B7C)
    /* E22C 0010E22C 7C7BA524 */  addiu      $5, $5, %lo(D_00797B7C)
    /* E230 0010E230 01000624 */  addiu      $6, $0, 0x1
    /* E234 0010E234 04FE100C */  jal        func_0043f810
    /* E238 0010E238 00000000 */   nop
    /* E23C 0010E23C 23000224 */  addiu      $2, $0, 0x23
    /* E240 0010E240 D800A2AF */  sw         $2, 0xD8($29)
    /* E244 0010E244 8F4B4426 */  addiu      $4, $18, 0x4B8F
    /* E248 0010E248 D800A527 */  addiu      $5, $29, 0xD8
    /* E24C 0010E24C 04000624 */  addiu      $6, $0, 0x4
    /* E250 0010E250 04FE100C */  jal        func_0043f810
    /* E254 0010E254 00000000 */   nop
    /* E258 0010E258 04000624 */  addiu      $6, $0, 0x4
    /* E25C 0010E25C D400A6AF */  sw         $6, 0xD4($29)
    /* E260 0010E260 934B4426 */  addiu      $4, $18, 0x4B93
    /* E264 0010E264 D400A527 */  addiu      $5, $29, 0xD4
    /* E268 0010E268 04FE100C */  jal        func_0043f810
    /* E26C 0010E26C 00000000 */   nop
    /* E270 0010E270 974B4426 */  addiu      $4, $18, 0x4B97
    /* E274 0010E274 7A00053C */  lui        $5, %hi(D_0079BEF4)
    /* E278 0010E278 F4BEA524 */  addiu      $5, $5, %lo(D_0079BEF4)
    /* E27C 0010E27C 04000624 */  addiu      $6, $0, 0x4
    /* E280 0010E280 04FE100C */  jal        func_0043f810
    /* E284 0010E284 00000000 */   nop
    /* E288 0010E288 9B4B5126 */  addiu      $17, $18, 0x4B9B
    /* E28C 0010E28C 9B4B1026 */  addiu      $16, $16, 0x4B9B
    /* E290 0010E290 3F006016 */  bnez       $19, .L0010E390
    /* E294 0010E294 00000000 */   nop
    /* E298 0010E298 25000224 */  addiu      $2, $0, 0x25
    /* E29C 0010E29C D800A2AF */  sw         $2, 0xD8($29)
    /* E2A0 0010E2A0 2D202002 */  daddu      $4, $17, $0
    /* E2A4 0010E2A4 D800A527 */  addiu      $5, $29, 0xD8
    /* E2A8 0010E2A8 04000624 */  addiu      $6, $0, 0x4
    /* E2AC 0010E2AC 04FE100C */  jal        func_0043f810
    /* E2B0 0010E2B0 00000000 */   nop
    /* E2B4 0010E2B4 04000624 */  addiu      $6, $0, 0x4
    /* E2B8 0010E2B8 D400A6AF */  sw         $6, 0xD4($29)
    /* E2BC 0010E2BC 04002426 */  addiu      $4, $17, 0x4
    /* E2C0 0010E2C0 D400A527 */  addiu      $5, $29, 0xD4
    /* E2C4 0010E2C4 04FE100C */  jal        func_0043f810
    /* E2C8 0010E2C8 00000000 */   nop
    /* E2CC 0010E2CC 08002426 */  addiu      $4, $17, 0x8
    /* E2D0 0010E2D0 B4B18527 */  addiu      $5, $28, -0x4E4C
    /* E2D4 0010E2D4 04000624 */  addiu      $6, $0, 0x4
    /* E2D8 0010E2D8 04FE100C */  jal        func_0043f810
    /* E2DC 0010E2DC 00000000 */   nop
    /* E2E0 0010E2E0 26000224 */  addiu      $2, $0, 0x26
    /* E2E4 0010E2E4 D800A2AF */  sw         $2, 0xD8($29)
    /* E2E8 0010E2E8 0C002426 */  addiu      $4, $17, 0xC
    /* E2EC 0010E2EC D800A527 */  addiu      $5, $29, 0xD8
    /* E2F0 0010E2F0 04000624 */  addiu      $6, $0, 0x4
    /* E2F4 0010E2F4 04FE100C */  jal        func_0043f810
    /* E2F8 0010E2F8 00000000 */   nop
    /* E2FC 0010E2FC 04000624 */  addiu      $6, $0, 0x4
    /* E300 0010E300 D400A6AF */  sw         $6, 0xD4($29)
    /* E304 0010E304 10002426 */  addiu      $4, $17, 0x10
    /* E308 0010E308 D400A527 */  addiu      $5, $29, 0xD4
    /* E30C 0010E30C 04FE100C */  jal        func_0043f810
    /* E310 0010E310 00000000 */   nop
    /* E314 0010E314 14002426 */  addiu      $4, $17, 0x14
    /* E318 0010E318 B8B18527 */  addiu      $5, $28, -0x4E48
    /* E31C 0010E31C 04000624 */  addiu      $6, $0, 0x4
    /* E320 0010E320 04FE100C */  jal        func_0043f810
    /* E324 0010E324 00000000 */   nop
    /* E328 0010E328 27000224 */  addiu      $2, $0, 0x27
    /* E32C 0010E32C D800A2AF */  sw         $2, 0xD8($29)
    /* E330 0010E330 18002426 */  addiu      $4, $17, 0x18
    /* E334 0010E334 D800A527 */  addiu      $5, $29, 0xD8
    /* E338 0010E338 04000624 */  addiu      $6, $0, 0x4
    /* E33C 0010E33C 04FE100C */  jal        func_0043f810
    /* E340 0010E340 00000000 */   nop
    /* E344 0010E344 0100023C */  lui        $2, (0x15000 >> 16)
    /* E348 0010E348 00504234 */  ori        $2, $2, (0x15000 & 0xFFFF)
    /* E34C 0010E34C D400A2AF */  sw         $2, 0xD4($29)
    /* E350 0010E350 1C002426 */  addiu      $4, $17, 0x1C
    /* E354 0010E354 D400A527 */  addiu      $5, $29, 0xD4
    /* E358 0010E358 04000624 */  addiu      $6, $0, 0x4
    /* E35C 0010E35C 04FE100C */  jal        func_0043f810
    /* E360 0010E360 00000000 */   nop
    /* E364 0010E364 20002426 */  addiu      $4, $17, 0x20
    /* E368 0010E368 7C00053C */  lui        $5, %hi(D_007BBF00)
    /* E36C 0010E36C 00BFA524 */  addiu      $5, $5, %lo(D_007BBF00)
    /* E370 0010E370 0100023C */  lui        $2, (0x15000 >> 16)
    /* E374 0010E374 00504634 */  ori        $6, $2, (0x15000 & 0xFFFF)
    /* E378 0010E378 04FE100C */  jal        func_0043f810
    /* E37C 0010E37C 00000000 */   nop
    /* E380 0010E380 0100023C */  lui        $2, (0x15020 >> 16)
    /* E384 0010E384 20504234 */  ori        $2, $2, (0x15020 & 0xFFFF)
    /* E388 0010E388 21882202 */  addu       $17, $17, $2
    /* E38C 0010E38C 21800202 */  addu       $16, $16, $2
  .L0010E390:
    /* E390 0010E390 28000224 */  addiu      $2, $0, 0x28
    /* E394 0010E394 D800A2AF */  sw         $2, 0xD8($29)
    /* E398 0010E398 2D202002 */  daddu      $4, $17, $0
    /* E39C 0010E39C D800A527 */  addiu      $5, $29, 0xD8
    /* E3A0 0010E3A0 04000624 */  addiu      $6, $0, 0x4
    /* E3A4 0010E3A4 04FE100C */  jal        func_0043f810
    /* E3A8 0010E3A8 00000000 */   nop
    /* E3AC 0010E3AC C8000224 */  addiu      $2, $0, 0xC8
    /* E3B0 0010E3B0 D400A2AF */  sw         $2, 0xD4($29)
    /* E3B4 0010E3B4 04002426 */  addiu      $4, $17, 0x4
    /* E3B8 0010E3B8 D400A527 */  addiu      $5, $29, 0xD4
    /* E3BC 0010E3BC 04000624 */  addiu      $6, $0, 0x4
    /* E3C0 0010E3C0 04FE100C */  jal        func_0043f810
    /* E3C4 0010E3C4 00000000 */   nop
    /* E3C8 0010E3C8 08002426 */  addiu      $4, $17, 0x8
    /* E3CC 0010E3CC 7A00053C */  lui        $5, %hi(D_0079BE2C)
    /* E3D0 0010E3D0 2CBEA524 */  addiu      $5, $5, %lo(D_0079BE2C)
    /* E3D4 0010E3D4 C8000624 */  addiu      $6, $0, 0xC8
    /* E3D8 0010E3D8 04FE100C */  jal        func_0043f810
    /* E3DC 0010E3DC 00000000 */   nop
    /* E3E0 0010E3E0 29000224 */  addiu      $2, $0, 0x29
    /* E3E4 0010E3E4 D800A2AF */  sw         $2, 0xD8($29)
    /* E3E8 0010E3E8 D0002426 */  addiu      $4, $17, 0xD0
    /* E3EC 0010E3EC D800A527 */  addiu      $5, $29, 0xD8
    /* E3F0 0010E3F0 04000624 */  addiu      $6, $0, 0x4
    /* E3F4 0010E3F4 04FE100C */  jal        func_0043f810
    /* E3F8 0010E3F8 00000000 */   nop
    /* E3FC 0010E3FC A869050C */  jal        func_0015a6a0
    /* E400 0010E400 00000000 */   nop
    /* E404 0010E404 D400A2AF */  sw         $2, 0xD4($29)
    /* E408 0010E408 D4002426 */  addiu      $4, $17, 0xD4
    /* E40C 0010E40C D400A527 */  addiu      $5, $29, 0xD4
    /* E410 0010E410 04000624 */  addiu      $6, $0, 0x4
    /* E414 0010E414 04FE100C */  jal        func_0043f810
    /* E418 0010E418 00000000 */   nop
    /* E41C 0010E41C D8003126 */  addiu      $17, $17, 0xD8
    /* E420 0010E420 D8001326 */  addiu      $19, $16, 0xD8
    /* E424 0010E424 A469050C */  jal        func_0015a690
    /* E428 0010E428 00000000 */   nop
    /* E42C 0010E42C 2D804000 */  daddu      $16, $2, $0
    /* E430 0010E430 A869050C */  jal        func_0015a6a0
    /* E434 0010E434 00000000 */   nop
    /* E438 0010E438 2D202002 */  daddu      $4, $17, $0
    /* E43C 0010E43C 2D280002 */  daddu      $5, $16, $0
    /* E440 0010E440 2D304000 */  daddu      $6, $2, $0
    /* E444 0010E444 04FE100C */  jal        func_0043f810
    /* E448 0010E448 00000000 */   nop
    /* E44C 0010E44C A869050C */  jal        func_0015a6a0
    /* E450 0010E450 00000000 */   nop
    /* E454 0010E454 21882202 */  addu       $17, $17, $2
    /* E458 0010E458 A869050C */  jal        func_0015a6a0
    /* E45C 0010E45C 00000000 */   nop
    /* E460 0010E460 21806202 */  addu       $16, $19, $2
    /* E464 0010E464 2DA80000 */  daddu      $21, $0, $0
    /* E468 0010E468 68000010 */  b          .L0010E60C
    /* E46C 0010E46C 00000000 */   nop
  .L0010E470:
    /* E470 0010E470 00A21500 */  sll        $20, $21, 8
    /* E474 0010E474 00018226 */  addiu      $2, $20, 0x100
    /* E478 0010E478 D800A2AF */  sw         $2, 0xD8($29)
    /* E47C 0010E47C 2D202002 */  daddu      $4, $17, $0
    /* E480 0010E480 D800A527 */  addiu      $5, $29, 0xD8
    /* E484 0010E484 04000624 */  addiu      $6, $0, 0x4
    /* E488 0010E488 04FE100C */  jal        func_0043f810
    /* E48C 0010E48C 00000000 */   nop
    /* E490 0010E490 04000624 */  addiu      $6, $0, 0x4
    /* E494 0010E494 D400A6AF */  sw         $6, 0xD4($29)
    /* E498 0010E498 04002426 */  addiu      $4, $17, 0x4
    /* E49C 0010E49C D400A527 */  addiu      $5, $29, 0xD4
    /* E4A0 0010E4A0 04FE100C */  jal        func_0043f810
    /* E4A4 0010E4A4 00000000 */   nop
    /* E4A8 0010E4A8 00111500 */  sll        $2, $21, 4
    /* E4AC 0010E4AC 21105500 */  addu       $2, $2, $21
    /* E4B0 0010E4B0 C0180200 */  sll        $3, $2, 3
    /* E4B4 0010E4B4 7900023C */  lui        $2, %hi(D_00796E50)
    /* E4B8 0010E4B8 506E4224 */  addiu      $2, $2, %lo(D_00796E50)
    /* E4BC 0010E4BC 21984300 */  addu       $19, $2, $3
    /* E4C0 0010E4C0 08002426 */  addiu      $4, $17, 0x8
    /* E4C4 0010E4C4 2D286002 */  daddu      $5, $19, $0
    /* E4C8 0010E4C8 04000624 */  addiu      $6, $0, 0x4
    /* E4CC 0010E4CC 04FE100C */  jal        func_0043f810
    /* E4D0 0010E4D0 00000000 */   nop
    /* E4D4 0010E4D4 01018226 */  addiu      $2, $20, 0x101
    /* E4D8 0010E4D8 D800A2AF */  sw         $2, 0xD8($29)
    /* E4DC 0010E4DC 0C002426 */  addiu      $4, $17, 0xC
    /* E4E0 0010E4E0 D800A527 */  addiu      $5, $29, 0xD8
    /* E4E4 0010E4E4 04000624 */  addiu      $6, $0, 0x4
    /* E4E8 0010E4E8 04FE100C */  jal        func_0043f810
    /* E4EC 0010E4EC 00000000 */   nop
    /* E4F0 0010E4F0 48000224 */  addiu      $2, $0, 0x48
    /* E4F4 0010E4F4 D400A2AF */  sw         $2, 0xD4($29)
    /* E4F8 0010E4F8 10002426 */  addiu      $4, $17, 0x10
    /* E4FC 0010E4FC D400A527 */  addiu      $5, $29, 0xD4
    /* E500 0010E500 04000624 */  addiu      $6, $0, 0x4
    /* E504 0010E504 04FE100C */  jal        func_0043f810
    /* E508 0010E508 00000000 */   nop
    /* E50C 0010E50C 14002426 */  addiu      $4, $17, 0x14
    /* E510 0010E510 04006526 */  addiu      $5, $19, 0x4
    /* E514 0010E514 48000624 */  addiu      $6, $0, 0x48
    /* E518 0010E518 04FE100C */  jal        func_0043f810
    /* E51C 0010E51C 00000000 */   nop
    /* E520 0010E520 02018226 */  addiu      $2, $20, 0x102
    /* E524 0010E524 D800A2AF */  sw         $2, 0xD8($29)
    /* E528 0010E528 5C002426 */  addiu      $4, $17, 0x5C
    /* E52C 0010E52C D800A527 */  addiu      $5, $29, 0xD8
    /* E530 0010E530 04000624 */  addiu      $6, $0, 0x4
    /* E534 0010E534 04FE100C */  jal        func_0043f810
    /* E538 0010E538 00000000 */   nop
    /* E53C 0010E53C 06000224 */  addiu      $2, $0, 0x6
    /* E540 0010E540 D400A2AF */  sw         $2, 0xD4($29)
    /* E544 0010E544 60002426 */  addiu      $4, $17, 0x60
    /* E548 0010E548 D400A527 */  addiu      $5, $29, 0xD4
    /* E54C 0010E54C 04000624 */  addiu      $6, $0, 0x4
    /* E550 0010E550 04FE100C */  jal        func_0043f810
    /* E554 0010E554 00000000 */   nop
    /* E558 0010E558 64002426 */  addiu      $4, $17, 0x64
    /* E55C 0010E55C 4C006526 */  addiu      $5, $19, 0x4C
    /* E560 0010E560 06000624 */  addiu      $6, $0, 0x6
    /* E564 0010E564 04FE100C */  jal        func_0043f810
    /* E568 0010E568 00000000 */   nop
    /* E56C 0010E56C 05018226 */  addiu      $2, $20, 0x105
    /* E570 0010E570 D800A2AF */  sw         $2, 0xD8($29)
    /* E574 0010E574 6A002426 */  addiu      $4, $17, 0x6A
    /* E578 0010E578 D800A527 */  addiu      $5, $29, 0xD8
    /* E57C 0010E57C 04000624 */  addiu      $6, $0, 0x4
    /* E580 0010E580 04FE100C */  jal        func_0043f810
    /* E584 0010E584 00000000 */   nop
    /* E588 0010E588 30000224 */  addiu      $2, $0, 0x30
    /* E58C 0010E58C D400A2AF */  sw         $2, 0xD4($29)
    /* E590 0010E590 6E002426 */  addiu      $4, $17, 0x6E
    /* E594 0010E594 D400A527 */  addiu      $5, $29, 0xD4
    /* E598 0010E598 04000624 */  addiu      $6, $0, 0x4
    /* E59C 0010E59C 04FE100C */  jal        func_0043f810
    /* E5A0 0010E5A0 00000000 */   nop
    /* E5A4 0010E5A4 72002426 */  addiu      $4, $17, 0x72
    /* E5A8 0010E5A8 54006526 */  addiu      $5, $19, 0x54
    /* E5AC 0010E5AC 30000624 */  addiu      $6, $0, 0x30
    /* E5B0 0010E5B0 04FE100C */  jal        func_0043f810
    /* E5B4 0010E5B4 00000000 */   nop
    /* E5B8 0010E5B8 0B018226 */  addiu      $2, $20, 0x10B
    /* E5BC 0010E5BC D800A2AF */  sw         $2, 0xD8($29)
    /* E5C0 0010E5C0 A2002426 */  addiu      $4, $17, 0xA2
    /* E5C4 0010E5C4 D800A527 */  addiu      $5, $29, 0xD8
    /* E5C8 0010E5C8 04000624 */  addiu      $6, $0, 0x4
    /* E5CC 0010E5CC 04FE100C */  jal        func_0043f810
    /* E5D0 0010E5D0 00000000 */   nop
    /* E5D4 0010E5D4 04000624 */  addiu      $6, $0, 0x4
    /* E5D8 0010E5D8 D400A6AF */  sw         $6, 0xD4($29)
    /* E5DC 0010E5DC A6002426 */  addiu      $4, $17, 0xA6
    /* E5E0 0010E5E0 D400A527 */  addiu      $5, $29, 0xD4
    /* E5E4 0010E5E4 04FE100C */  jal        func_0043f810
    /* E5E8 0010E5E8 00000000 */   nop
    /* E5EC 0010E5EC AA002426 */  addiu      $4, $17, 0xAA
    /* E5F0 0010E5F0 84006526 */  addiu      $5, $19, 0x84
    /* E5F4 0010E5F4 04000624 */  addiu      $6, $0, 0x4
    /* E5F8 0010E5F8 04FE100C */  jal        func_0043f810
    /* E5FC 0010E5FC 00000000 */   nop
    /* E600 0010E600 AE003126 */  addiu      $17, $17, 0xAE
    /* E604 0010E604 AE001026 */  addiu      $16, $16, 0xAE
    /* E608 0010E608 0100B526 */  addiu      $21, $21, 0x1
  .L0010E60C:
    /* E60C 0010E60C 0A00A22E */  sltiu      $2, $21, 0xA
    /* E610 0010E610 97FF4014 */  bnez       $2, .L0010E470
    /* E614 0010E614 00000000 */   nop
    /* E618 0010E618 DF00A0A3 */  sb         $0, 0xDF($29)
    /* E61C 0010E61C 2D280000 */  daddu      $5, $0, $0
    /* E620 0010E620 C8FF0426 */  addiu      $4, $16, -0x38
    /* E624 0010E624 07000010 */  b          .L0010E644
    /* E628 0010E628 00000000 */   nop
  .L0010E62C:
    /* E62C 0010E62C 2110C502 */  addu       $2, $22, $5
    /* E630 0010E630 DF00A393 */  lbu        $3, 0xDF($29)
    /* E634 0010E634 00004290 */  lbu        $2, 0x0($2)
    /* E638 0010E638 21106200 */  addu       $2, $3, $2
    /* E63C 0010E63C DF00A2A3 */  sb         $2, 0xDF($29)
    /* E640 0010E640 0100A524 */  addiu      $5, $5, 0x1
  .L0010E644:
    /* E644 0010E644 2B10A400 */  sltu       $2, $5, $4
    /* E648 0010E648 F8FF4014 */  bnez       $2, .L0010E62C
    /* E64C 0010E64C 00000000 */   nop
    /* E650 0010E650 00200224 */  addiu      $2, $0, 0x2000
    /* E654 0010E654 D800A2AF */  sw         $2, 0xD8($29)
    /* E658 0010E658 2D202002 */  daddu      $4, $17, $0
    /* E65C 0010E65C D800A527 */  addiu      $5, $29, 0xD8
    /* E660 0010E660 04000624 */  addiu      $6, $0, 0x4
    /* E664 0010E664 04FE100C */  jal        func_0043f810
    /* E668 0010E668 00000000 */   nop
    /* E66C 0010E66C 01000224 */  addiu      $2, $0, 0x1
    /* E670 0010E670 D400A2AF */  sw         $2, 0xD4($29)
    /* E674 0010E674 04002426 */  addiu      $4, $17, 0x4
    /* E678 0010E678 D400A527 */  addiu      $5, $29, 0xD4
    /* E67C 0010E67C 04000624 */  addiu      $6, $0, 0x4
    /* E680 0010E680 04FE100C */  jal        func_0043f810
    /* E684 0010E684 00000000 */   nop
    /* E688 0010E688 08002426 */  addiu      $4, $17, 0x8
    /* E68C 0010E68C DF00A527 */  addiu      $5, $29, 0xDF
    /* E690 0010E690 01000624 */  addiu      $6, $0, 0x1
    /* E694 0010E694 04FE100C */  jal        func_0043f810
    /* E698 0010E698 00000000 */   nop
    /* E69C 0010E69C FFFF0224 */  addiu      $2, $0, -0x1
    /* E6A0 0010E6A0 D800A2AF */  sw         $2, 0xD8($29)
    /* E6A4 0010E6A4 09002426 */  addiu      $4, $17, 0x9
    /* E6A8 0010E6A8 D800A527 */  addiu      $5, $29, 0xD8
    /* E6AC 0010E6AC 04000624 */  addiu      $6, $0, 0x4
    /* E6B0 0010E6B0 04FE100C */  jal        func_0043f810
    /* E6B4 0010E6B4 00000000 */   nop
    /* E6B8 0010E6B8 0D000526 */  addiu      $5, $16, 0xD
    /* E6BC 0010E6BC 0000E5AE */  sw         $5, 0x0($23)
    /* E6C0 0010E6C0 5E00043C */  lui        $4, %hi(D_005E45A0)
    /* E6C4 0010E6C4 A0458424 */  addiu      $4, $4, %lo(D_005E45A0)
    /* E6C8 0010E6C8 DA02110C */  jal        func_00440b68
    /* E6CC 0010E6CC 00000000 */   nop
    /* E6D0 0010E6D0 2D104002 */  daddu      $2, $18, $0
    /* E6D4 0010E6D4 8000BFDF */  ld         $31, 0x80($29)
    /* E6D8 0010E6D8 7000B77B */  lq         $23, 0x70($29)
    /* E6DC 0010E6DC 6000B67B */  lq         $22, 0x60($29)
    /* E6E0 0010E6E0 5000B57B */  lq         $21, 0x50($29)
    /* E6E4 0010E6E4 4000B47B */  lq         $20, 0x40($29)
    /* E6E8 0010E6E8 3000B37B */  lq         $19, 0x30($29)
    /* E6EC 0010E6EC 2000B27B */  lq         $18, 0x20($29)
    /* E6F0 0010E6F0 1000B17B */  lq         $17, 0x10($29)
    /* E6F4 0010E6F4 0000B07B */  lq         $16, 0x0($29)
    /* E6F8 0010E6F8 E000BD27 */  addiu      $29, $29, 0xE0
    /* E6FC 0010E6FC 0800E003 */  jr         $31
    /* E700 0010E700 00000000 */   nop
    /* E704 0010E704 00000000 */  nop
    /* E708 0010E708 00000000 */  nop
    /* E70C 0010E70C 00000000 */  nop
.size func_0010d7c0, 0xf50
