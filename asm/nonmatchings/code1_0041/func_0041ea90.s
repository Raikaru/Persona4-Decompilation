.section .text
.set noat
.set noreorder
glabel func_0041ea90
    /* 31EA90 0041EA90 2D388000 */  daddu      $7, $4, $0
    /* 31EA94 0041EA94 04000B24 */  addiu      $11, $0, 0x4
    /* 31EA98 0041EA98 8401E98C */  lw         $9, 0x184($7)
    /* 31EA9C 0041EA9C 02000C24 */  addiu      $12, $0, 0x2
    /* 31EAA0 0041EAA0 6001EA8C */  lw         $10, 0x160($7)
    /* 31EAA4 0041EAA4 2D400000 */  daddu      $8, $0, $0
    /* 31EAA8 0041EAA8 03002239 */  xori       $2, $9, 0x3
    /* 31EAAC 0041EAAC 2D680000 */  daddu      $13, $0, $0
    /* 31EAB0 0041EAB0 03000E24 */  addiu      $14, $0, 0x3
    /* 31EAB4 0041EAB4 44004E15 */  bne        $10, $14, .L0041EBC8
    /* 31EAB8 0041EAB8 0A588201 */   movz      $11, $12, $2
    /* 31EABC 0041EABC B400E28C */  lw         $2, 0xB4($7)
    /* 31EAC0 0041EAC0 B800E38C */  lw         $3, 0xB8($7)
    /* 31EAC4 0041EAC4 D401E58C */  lw         $5, 0x1D4($7)
    /* 31EAC8 0041EAC8 E401E68C */  lw         $6, 0x1E4($7)
    /* 31EACC 0041EACC 21104300 */  addu       $2, $2, $3
    /* 31EAD0 0041EAD0 F401E48C */  lw         $4, 0x1F4($7)
    /* 31EAD4 0041EAD4 2A104B00 */  slt        $2, $2, $11
    /* 31EAD8 0041EAD8 D001E5AC */  sw         $5, 0x1D0($7)
    /* 31EADC 0041EADC E001E6AC */  sw         $6, 0x1E0($7)
    /* 31EAE0 0041EAE0 04004014 */  bnez       $2, .L0041EAF4
    /* 31EAE4 0041EAE4 F001E4AC */   sw        $4, 0x1F0($7)
    /* 31EAE8 0041EAE8 FC00E0AC */  sw         $0, 0xFC($7)
    /* 31EAEC 0041EAEC B801E0AC */  sw         $0, 0x1B8($7)
    /* 31EAF0 0041EAF0 B401E0AC */  sw         $0, 0x1B4($7)
  .L0041EAF4:
    /* 31EAF4 0041EAF4 FC00E28C */  lw         $2, 0xFC($7)
    /* 31EAF8 0041EAF8 05004054 */  bnel       $2, $0, .L0041EB10
    /* 31EAFC 0041EAFC B401E28C */   lw        $2, 0x1B4($7)
    /* 31EB00 0041EB00 B801E28C */  lw         $2, 0x1B8($7)
    /* 31EB04 0041EB04 0C004050 */  beql       $2, $0, .L0041EB38
    /* 31EB08 0041EB08 FC00E0AC */   sw        $0, 0xFC($7)
    /* 31EB0C 0041EB0C B401E28C */  lw         $2, 0x1B4($7)
  .L0041EB10:
    /* 31EB10 0041EB10 09004054 */  bnel       $2, $0, .L0041EB38
    /* 31EB14 0041EB14 FC00E0AC */   sw        $0, 0xFC($7)
    /* 31EB18 0041EB18 C801E28C */  lw         $2, 0x1C8($7)
    /* 31EB1C 0041EB1C D801E48C */  lw         $4, 0x1D8($7)
    /* 31EB20 0041EB20 280040AC */  sw         $0, 0x28($2)
    /* 31EB24 0041EB24 E801E38C */  lw         $3, 0x1E8($7)
    /* 31EB28 0041EB28 280080AC */  sw         $0, 0x28($4)
    /* 31EB2C 0041EB2C 280060AC */  sw         $0, 0x28($3)
    /* 31EB30 0041EB30 8401E98C */  lw         $9, 0x184($7)
    /* 31EB34 0041EB34 FC00E0AC */  sw         $0, 0xFC($7)
  .L0041EB38:
    /* 31EB38 0041EB38 03000224 */  addiu      $2, $0, 0x3
    /* 31EB3C 0041EB3C 0B002215 */  bne        $9, $2, .L0041EB6C
    /* 31EB40 0041EB40 B801E0AC */   sw        $0, 0x1B8($7)
    /* 31EB44 0041EB44 C801E38C */  lw         $3, 0x1C8($7)
    /* 31EB48 0041EB48 01000424 */  addiu      $4, $0, 0x1
    /* 31EB4C 0041EB4C 2800628C */  lw         $2, 0x28($3)
    /* 31EB50 0041EB50 18004450 */  beql       $2, $4, .L0041EBB4
    /* 31EB54 0041EB54 CC01E38C */   lw        $3, 0x1CC($7)
    /* 31EB58 0041EB58 B401E28C */  lw         $2, 0x1B4($7)
    /* 31EB5C 0041EB5C 48004010 */  beqz       $2, .L0041EC80
    /* 31EB60 0041EB60 02000224 */   addiu     $2, $0, 0x2
    /* 31EB64 0041EB64 13000010 */  b          .L0041EBB4
    /* 31EB68 0041EB68 CC01E38C */   lw        $3, 0x1CC($7)
  .L0041EB6C:
    /* 31EB6C 0041EB6C D801E28C */  lw         $2, 0x1D8($7)
    /* 31EB70 0041EB70 01000324 */  addiu      $3, $0, 0x1
    /* 31EB74 0041EB74 2800448C */  lw         $4, 0x28($2)
    /* 31EB78 0041EB78 06008354 */  bnel       $4, $3, .L0041EB94
    /* 31EB7C 0041EB7C B401E28C */   lw        $2, 0x1B4($7)
    /* 31EB80 0041EB80 E801E28C */  lw         $2, 0x1E8($7)
    /* 31EB84 0041EB84 2800438C */  lw         $3, 0x28($2)
    /* 31EB88 0041EB88 05006450 */  beql       $3, $4, .L0041EBA0
    /* 31EB8C 0041EB8C DC01E28C */   lw        $2, 0x1DC($7)
    /* 31EB90 0041EB90 B401E28C */  lw         $2, 0x1B4($7)
  .L0041EB94:
    /* 31EB94 0041EB94 3A004010 */  beqz       $2, .L0041EC80
    /* 31EB98 0041EB98 02000224 */   addiu     $2, $0, 0x2
    /* 31EB9C 0041EB9C DC01E28C */  lw         $2, 0x1DC($7)
  .L0041EBA0:
    /* 31EBA0 0041EBA0 01000324 */  addiu      $3, $0, 0x1
    /* 31EBA4 0041EBA4 2800448C */  lw         $4, 0x28($2)
    /* 31EBA8 0041EBA8 35008314 */  bne        $4, $3, .L0041EC80
    /* 31EBAC 0041EBAC 02000224 */   addiu     $2, $0, 0x2
    /* 31EBB0 0041EBB0 EC01E38C */  lw         $3, 0x1EC($7)
  .L0041EBB4:
    /* 31EBB4 0041EBB4 2D688000 */  daddu      $13, $4, $0
    /* 31EBB8 0041EBB8 2800628C */  lw         $2, 0x28($3)
    /* 31EBBC 0041EBBC 01004238 */  xori       $2, $2, 0x1
    /* 31EBC0 0041EBC0 2E000010 */  b          .L0041EC7C
    /* 31EBC4 0041EBC4 0B680200 */   movn      $13, $0, $2
  .L0041EBC8:
    /* 31EBC8 0041EBC8 0E00A054 */  bnel       $5, $0, .L0041EC04
    /* 31EBCC 0041EBCC CC01E28C */   lw        $2, 0x1CC($7)
    /* 31EBD0 0041EBD0 C801E68C */  lw         $6, 0x1C8($7)
    /* 31EBD4 0041EBD4 CC01E48C */  lw         $4, 0x1CC($7)
    /* 31EBD8 0041EBD8 CC01E6AC */  sw         $6, 0x1CC($7)
    /* 31EBDC 0041EBDC D801E68C */  lw         $6, 0x1D8($7)
    /* 31EBE0 0041EBE0 DC01E38C */  lw         $3, 0x1DC($7)
    /* 31EBE4 0041EBE4 DC01E6AC */  sw         $6, 0x1DC($7)
    /* 31EBE8 0041EBE8 E801E68C */  lw         $6, 0x1E8($7)
    /* 31EBEC 0041EBEC EC01E28C */  lw         $2, 0x1EC($7)
    /* 31EBF0 0041EBF0 C801E4AC */  sw         $4, 0x1C8($7)
    /* 31EBF4 0041EBF4 D801E3AC */  sw         $3, 0x1D8($7)
    /* 31EBF8 0041EBF8 E801E2AC */  sw         $2, 0x1E8($7)
    /* 31EBFC 0041EBFC EC01E6AC */  sw         $6, 0x1EC($7)
    /* 31EC00 0041EC00 CC01E28C */  lw         $2, 0x1CC($7)
  .L0041EC04:
    /* 31EC04 0041EC04 DC01E48C */  lw         $4, 0x1DC($7)
    /* 31EC08 0041EC08 EC01E38C */  lw         $3, 0x1EC($7)
    /* 31EC0C 0041EC0C D001E2AC */  sw         $2, 0x1D0($7)
    /* 31EC10 0041EC10 E001E4AC */  sw         $4, 0x1E0($7)
    /* 31EC14 0041EC14 06002E15 */  bne        $9, $14, .L0041EC30
    /* 31EC18 0041EC18 F001E3AC */   sw        $3, 0x1F0($7)
    /* 31EC1C 0041EC1C 17004C55 */  bnel       $10, $12, .L0041EC7C
    /* 31EC20 0041EC20 01000D24 */   addiu     $13, $0, 0x1
    /* 31EC24 0041EC24 C801E28C */  lw         $2, 0x1C8($7)
    /* 31EC28 0041EC28 10000010 */  b          .L0041EC6C
    /* 31EC2C 0041EC2C 01000424 */   addiu     $4, $0, 0x1
  .L0041EC30:
    /* 31EC30 0041EC30 01002239 */  xori       $2, $9, 0x1
    /* 31EC34 0041EC34 01000624 */  addiu      $6, $0, 0x1
    /* 31EC38 0041EC38 0B188200 */  movn       $3, $4, $2
    /* 31EC3C 0041EC3C 0E004C15 */  bne        $10, $12, .L0041EC78
    /* 31EC40 0041EC40 2D106000 */   daddu     $2, $3, $0
    /* 31EC44 0041EC44 0500A050 */  beql       $5, $0, .L0041EC5C
    /* 31EC48 0041EC48 D801E28C */   lw        $2, 0x1D8($7)
    /* 31EC4C 0041EC4C 2800428C */  lw         $2, 0x28($2)
    /* 31EC50 0041EC50 0A004650 */  beql       $2, $6, .L0041EC7C
    /* 31EC54 0041EC54 01000D24 */   addiu     $13, $0, 0x1
    /* 31EC58 0041EC58 D801E28C */  lw         $2, 0x1D8($7)
  .L0041EC5C:
    /* 31EC5C 0041EC5C 2800448C */  lw         $4, 0x28($2)
    /* 31EC60 0041EC60 07008614 */  bne        $4, $6, .L0041EC80
    /* 31EC64 0041EC64 02000224 */   addiu     $2, $0, 0x2
    /* 31EC68 0041EC68 E801E28C */  lw         $2, 0x1E8($7)
  .L0041EC6C:
    /* 31EC6C 0041EC6C 2800438C */  lw         $3, 0x28($2)
    /* 31EC70 0041EC70 03006414 */  bne        $3, $4, .L0041EC80
    /* 31EC74 0041EC74 02000224 */   addiu     $2, $0, 0x2
  .L0041EC78:
    /* 31EC78 0041EC78 01000D24 */  addiu      $13, $0, 0x1
  .L0041EC7C:
    /* 31EC7C 0041EC7C 02000224 */  addiu      $2, $0, 0x2
  .L0041EC80:
    /* 31EC80 0041EC80 0C002211 */  beq        $9, $2, .L0041ECB4
    /* 31EC84 0041EC84 03002229 */   slti      $2, $9, 0x3
    /* 31EC88 0041EC88 05004010 */  beqz       $2, .L0041ECA0
    /* 31EC8C 0041EC8C 01000224 */   addiu     $2, $0, 0x1
    /* 31EC90 0041EC90 09002251 */  beql       $9, $2, .L0041ECB8
    /* 31EC94 0041EC94 E001E88C */   lw        $8, 0x1E0($7)
    /* 31EC98 0041EC98 08000010 */  b          .L0041ECBC
    /* 31EC9C 0041EC9C 280000AD */   sw        $0, 0x28($8)
  .L0041ECA0:
    /* 31ECA0 0041ECA0 03000224 */  addiu      $2, $0, 0x3
    /* 31ECA4 0041ECA4 04002251 */  beql       $9, $2, .L0041ECB8
    /* 31ECA8 0041ECA8 D001E88C */   lw        $8, 0x1D0($7)
    /* 31ECAC 0041ECAC 03000010 */  b          .L0041ECBC
    /* 31ECB0 0041ECB0 280000AD */   sw        $0, 0x28($8)
  .L0041ECB4:
    /* 31ECB4 0041ECB4 F001E88C */  lw         $8, 0x1F0($7)
  .L0041ECB8:
    /* 31ECB8 0041ECB8 280000AD */  sw         $0, 0x28($8)
  .L0041ECBC:
    /* 31ECBC 0041ECBC 2D10A001 */  daddu      $2, $13, $0
    /* 31ECC0 0041ECC0 3808E3DC */  ld         $3, 0x838($7)
    /* 31ECC4 0041ECC4 6001E48C */  lw         $4, 0x160($7)
    /* 31ECC8 0041ECC8 180003FD */  sd         $3, 0x18($8)
    /* 31ECCC 0041ECCC 2C0004AD */  sw         $4, 0x2C($8)
    /* 31ECD0 0041ECD0 4008E3DC */  ld         $3, 0x840($7)
    /* 31ECD4 0041ECD4 8401E48C */  lw         $4, 0x184($7)
    /* 31ECD8 0041ECD8 200003FD */  sd         $3, 0x20($8)
    /* 31ECDC 0041ECDC 300004AD */  sw         $4, 0x30($8)
    /* 31ECE0 0041ECE0 4C01E38C */  lw         $3, 0x14C($7)
    /* 31ECE4 0041ECE4 340003AD */  sw         $3, 0x34($8)
    /* 31ECE8 0041ECE8 9801E48C */  lw         $4, 0x198($7)
    /* 31ECEC 0041ECEC 380004AD */  sw         $4, 0x38($8)
    /* 31ECF0 0041ECF0 8801E38C */  lw         $3, 0x188($7)
    /* 31ECF4 0041ECF4 3C0003AD */  sw         $3, 0x3C($8)
    /* 31ECF8 0041ECF8 9401E48C */  lw         $4, 0x194($7)
    /* 31ECFC 0041ECFC 400004AD */  sw         $4, 0x40($8)
    /* 31ED00 0041ED00 9C01E38C */  lw         $3, 0x19C($7)
    /* 31ED04 0041ED04 440003AD */  sw         $3, 0x44($8)
    /* 31ED08 0041ED08 A001E48C */  lw         $4, 0x1A0($7)
    /* 31ED0C 0041ED0C 480004AD */  sw         $4, 0x48($8)
    /* 31ED10 0041ED10 A401E38C */  lw         $3, 0x1A4($7)
    /* 31ED14 0041ED14 4C0003AD */  sw         $3, 0x4C($8)
    /* 31ED18 0041ED18 A801E48C */  lw         $4, 0x1A8($7)
    /* 31ED1C 0041ED1C 500004AD */  sw         $4, 0x50($8)
    /* 31ED20 0041ED20 AC01E38C */  lw         $3, 0x1AC($7)
    /* 31ED24 0041ED24 540003AD */  sw         $3, 0x54($8)
    /* 31ED28 0041ED28 B001E48C */  lw         $4, 0x1B0($7)
    /* 31ED2C 0041ED2C 580004AD */  sw         $4, 0x58($8)
    /* 31ED30 0041ED30 5801E38C */  lw         $3, 0x158($7)
    /* 31ED34 0041ED34 5C0003AD */  sw         $3, 0x5C($8)
    /* 31ED38 0041ED38 5C01E48C */  lw         $4, 0x15C($7)
    /* 31ED3C 0041ED3C 0800E003 */  jr         $31
    /* 31ED40 0041ED40 600004AD */   sw        $4, 0x60($8)
    /* 31ED44 0041ED44 00000000 */  nop
.size func_0041ea90, 0x2b8
