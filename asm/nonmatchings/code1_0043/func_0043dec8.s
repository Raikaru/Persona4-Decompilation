.section .text
.set noat
.set noreorder
glabel func_0043dec8
    /* 33DEC8 0043DEC8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 33DECC 0043DECC 0800B1FF */  sd         $17, 0x8($29)
    /* 33DED0 0043DED0 0000B0FF */  sd         $16, 0x0($29)
    /* 33DED4 0043DED4 1000BFFF */  sd         $31, 0x10($29)
    /* 33DED8 0043DED8 38008F8C */  lw         $15, 0x38($4)
    /* 33DEDC 0043DEDC 0300E015 */  bnez       $15, .L0043DEEC
    /* 33DEE0 0043DEE0 2D888000 */   daddu     $17, $4, $0
    /* 33DEE4 0043DEE4 F8F7100C */  jal        func_0043dfe0
    /* 33DEE8 0043DEE8 00000000 */   nop
  .L0043DEEC:
    /* 33DEEC 0043DEEC D8013026 */  addiu      $16, $17, 0x1D8
  .L0043DEF0:
    /* 33DEF0 0043DEF0 04000E8E */  lw         $14, 0x4($16)
    /* 33DEF4 0043DEF4 FFFFCE25 */  addiu      $14, $14, -0x1
    /* 33DEF8 0043DEF8 0600C005 */  bltz       $14, .L0043DF14
    /* 33DEFC 0043DEFC 08000D8E */   lw        $13, 0x8($16)
  .L0043DF00:
    /* 33DF00 0043DF00 0C00AF85 */  lh         $15, 0xC($13)
    /* 33DF04 0043DF04 1500E011 */  beqz       $15, .L0043DF5C
    /* 33DF08 0043DF08 FFFFCE25 */   addiu     $14, $14, -0x1
    /* 33DF0C 0043DF0C FCFFC105 */  bgez       $14, .L0043DF00
    /* 33DF10 0043DF10 5800AD25 */   addiu     $13, $13, 0x58
  .L0043DF14:
    /* 33DF14 0043DF14 0000028E */  lw         $2, 0x0($16)
    /* 33DF18 0043DF18 F5FF4054 */  bnel       $2, $0, .L0043DEF0
    /* 33DF1C 0043DF1C 2D804000 */   daddu     $16, $2, $0
    /* 33DF20 0043DF20 2D202002 */  daddu      $4, $17, $0
    /* 33DF24 0043DF24 96F7100C */  jal        func_0043de58
    /* 33DF28 0043DF28 04000524 */   addiu     $5, $0, 0x4
    /* 33DF2C 0043DF2C 03004010 */  beqz       $2, .L0043DF3C
    /* 33DF30 0043DF30 000002AE */   sw        $2, 0x0($16)
    /* 33DF34 0043DF34 EEFF0010 */  b          .L0043DEF0
    /* 33DF38 0043DF38 2D804000 */   daddu     $16, $2, $0
  .L0043DF3C:
    /* 33DF3C 0043DF3C 0C000F24 */  addiu      $15, $0, 0xC
    /* 33DF40 0043DF40 2D100000 */  daddu      $2, $0, $0
    /* 33DF44 0043DF44 00002FAE */  sw         $15, 0x0($17)
  .L0043DF48:
    /* 33DF48 0043DF48 0000B0DF */  ld         $16, 0x0($29)
    /* 33DF4C 0043DF4C 0800B1DF */  ld         $17, 0x8($29)
    /* 33DF50 0043DF50 1000BFDF */  ld         $31, 0x10($29)
    /* 33DF54 0043DF54 0800E003 */  jr         $31
    /* 33DF58 0043DF58 2000BD27 */   addiu     $29, $29, 0x20
  .L0043DF5C:
    /* 33DF5C 0043DF5C 01000F24 */  addiu      $15, $0, 0x1
    /* 33DF60 0043DF60 5400B1AD */  sw         $17, 0x54($13)
    /* 33DF64 0043DF64 0C00AFA5 */  sh         $15, 0xC($13)
    /* 33DF68 0043DF68 2D10A001 */  daddu      $2, $13, $0
    /* 33DF6C 0043DF6C 0000A0AD */  sw         $0, 0x0($13)
    /* 33DF70 0043DF70 FFFF0F24 */  addiu      $15, $0, -0x1
    /* 33DF74 0043DF74 0800A0AD */  sw         $0, 0x8($13)
    /* 33DF78 0043DF78 0E00AFA5 */  sh         $15, 0xE($13)
    /* 33DF7C 0043DF7C 0400A0AD */  sw         $0, 0x4($13)
    /* 33DF80 0043DF80 1000A0AD */  sw         $0, 0x10($13)
    /* 33DF84 0043DF84 1400A0AD */  sw         $0, 0x14($13)
    /* 33DF88 0043DF88 1800A0AD */  sw         $0, 0x18($13)
    /* 33DF8C 0043DF8C 3000A0AD */  sw         $0, 0x30($13)
    /* 33DF90 0043DF90 3400A0AD */  sw         $0, 0x34($13)
    /* 33DF94 0043DF94 4400A0AD */  sw         $0, 0x44($13)
    /* 33DF98 0043DF98 EBFF0010 */  b          .L0043DF48
    /* 33DF9C 0043DF9C 4800A0AD */   sw        $0, 0x48($13)
  alabel func_0043DFA0
    /* 33DFA0 0043DFA0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 33DFA4 0043DFA4 4400053C */  lui        $5, %hi(func_0043dce8)
    /* 33DFA8 0043DFA8 0000BFFF */  sd         $31, 0x0($29)
    /* 33DFAC 0043DFAC E8DCA524 */  addiu      $5, $5, %lo(func_0043dce8)
    /* 33DFB0 0043DFB0 0000BFDF */  ld         $31, 0x0($29)
    /* 33DFB4 0043DFB4 74FA1008 */  j          func_0043e9d0
    /* 33DFB8 0043DFB8 1000BD27 */   addiu     $29, $29, 0x10
    /* 33DFBC 0043DFBC 00000000 */  nop
.size func_0043dec8, 0xf8
