.section .text
.set noat
.set noreorder
glabel func_003bdd00
    /* 2BDD00 003BDD00 40FFBD27 */  addiu      $29, $29, -0xC0
    /* 2BDD04 003BDD04 6000BFFF */  sd         $31, 0x60($29)
    /* 2BDD08 003BDD08 5000B57F */  sq         $21, 0x50($29)
    /* 2BDD0C 003BDD0C 4000B47F */  sq         $20, 0x40($29)
    /* 2BDD10 003BDD10 2DA88000 */  daddu      $21, $4, $0
    /* 2BDD14 003BDD14 3000B37F */  sq         $19, 0x30($29)
    /* 2BDD18 003BDD18 2DA0A000 */  daddu      $20, $5, $0
    /* 2BDD1C 003BDD1C 2000B27F */  sq         $18, 0x20($29)
    /* 2BDD20 003BDD20 2D98C000 */  daddu      $19, $6, $0
    /* 2BDD24 003BDD24 1000B17F */  sq         $17, 0x10($29)
    /* 2BDD28 003BDD28 2D90E000 */  daddu      $18, $7, $0
    /* 2BDD2C 003BDD2C 0000B07F */  sq         $16, 0x0($29)
    /* 2BDD30 003BDD30 BC00A627 */  addiu      $6, $29, 0xBC
    /* 2BDD34 003BDD34 01001024 */  addiu      $16, $0, 0x1
    /* 2BDD38 003BDD38 B800A727 */  addiu      $7, $29, 0xB8
    /* 2BDD3C 003BDD3C 147C0F0C */  jal        func_003df050
    /* 2BDD40 003BDD40 2D280002 */   daddu     $5, $16, $0
    /* 2BDD44 003BDD44 16004010 */  beqz       $2, .L003BDDA0
    /* 2BDD48 003BDD48 00000000 */   nop
    /* 2BDD4C 003BDD4C B800A38F */  lw         $3, 0xB8($29)
    /* 2BDD50 003BDD50 0300023C */  lui        $2, (0x35000 >> 16)
    /* 2BDD54 003BDD54 00504234 */  ori        $2, $2, (0x35000 & 0xFFFF)
    /* 2BDD58 003BDD58 2B106200 */  sltu       $2, $3, $2
    /* 2BDD5C 003BDD5C 06004014 */  bnez       $2, .L003BDD78
    /* 2BDD60 003BDD60 00000000 */   nop
    /* 2BDD64 003BDD64 0300013C */  lui        $1, (0x37003 >> 16)
    /* 2BDD68 003BDD68 03702134 */  ori        $1, $1, (0x37003 & 0xFFFF)
    /* 2BDD6C 003BDD6C 2B086100 */  sltu       $1, $3, $1
    /* 2BDD70 003BDD70 0D002014 */  bnez       $1, .L003BDDA8
    /* 2BDD74 003BDD74 00000000 */   nop
  .L003BDD78:
    /* 2BDD78 003BDD78 02000324 */  addiu      $3, $0, 0x2
    /* 2BDD7C 003BDD7C 0080023C */  lui        $2, (0x80000004 >> 16)
    /* 2BDD80 003BDD80 B000A3AF */  sw         $3, 0xB0($29)
    /* 2BDD84 003BDD84 647D0F0C */  jal        func_003df590
    /* 2BDD88 003BDD88 04004434 */   ori       $4, $2, (0x80000004 & 0xFFFF)
    /* 2BDD8C 003BDD8C B400A2AF */  sw         $2, 0xB4($29)
    /* 2BDD90 003BDD90 347D0F0C */  jal        func_003df4d0
    /* 2BDD94 003BDD94 B000A427 */   addiu     $4, $29, 0xB0
    /* 2BDD98 003BDD98 ED000010 */  b          .L003BE150
    /* 2BDD9C 003BDD9C 2D100000 */   daddu     $2, $0, $0
  .L003BDDA0:
    /* 2BDDA0 003BDDA0 EB000010 */  b          .L003BE150
    /* 2BDDA4 003BDDA4 2D100000 */   daddu     $2, $0, $0
  .L003BDDA8:
    /* 2BDDA8 003BDDA8 7000A427 */  addiu      $4, $29, 0x70
    /* 2BDDAC 003BDDAC 2D280000 */  daddu      $5, $0, $0
    /* 2BDDB0 003BDDB0 72FE100C */  jal        func_0043f9c8
    /* 2BDDB4 003BDDB4 18000624 */   addiu     $6, $0, 0x18
    /* 2BDDB8 003BDDB8 BC00B18F */  lw         $17, 0xBC($29)
    /* 2BDDBC 003BDDBC 2D20A002 */  daddu      $4, $21, $0
    /* 2BDDC0 003BDDC0 7000A527 */  addiu      $5, $29, 0x70
    /* 2BDDC4 003BDDC4 448A0F0C */  jal        func_003e2910
    /* 2BDDC8 003BDDC8 2D302002 */   daddu     $6, $17, $0
    /* 2BDDCC 003BDDCC D2002216 */  bne        $17, $2, .L003BE118
    /* 2BDDD0 003BDDD0 00000000 */   nop
    /* 2BDDD4 003BDDD4 0000918E */  lw         $17, 0x0($20)
    /* 2BDDD8 003BDDD8 18002226 */  addiu      $2, $17, 0x18
    /* 2BDDDC 003BDDDC D0002012 */  beqz       $17, .L003BE120
    /* 2BDDE0 003BDDE0 000082AE */   sw        $2, 0x0($20)
    /* 2BDDE4 003BDDE4 7000A48F */  lw         $4, 0x70($29)
    /* 2BDDE8 003BDDE8 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 2BDDEC 003BDDEC 7400A327 */  addiu      $3, $29, 0x74
    /* 2BDDF0 003BDDF0 24104202 */  and        $2, $18, $2
    /* 2BDDF4 003BDDF4 000024AE */  sw         $4, 0x0($17)
    /* 2BDDF8 003BDDF8 000060C4 */  lwc1       $f0, 0x0($3)
    /* 2BDDFC 003BDDFC 06004010 */  beqz       $2, .L003BDE18
    /* 2BDE00 003BDE00 040020E6 */   swc1      $f0, 0x4($17)
    /* 2BDE04 003BDE04 8000A0C7 */  lwc1       $f0, 0x80($29)
    /* 2BDE08 003BDE08 100020E6 */  swc1       $f0, 0x10($17)
    /* 2BDE0C 003BDE0C 8400A0C7 */  lwc1       $f0, 0x84($29)
    /* 2BDE10 003BDE10 05000010 */  b          .L003BDE28
    /* 2BDE14 003BDE14 140020E6 */   swc1      $f0, 0x14($17)
  .L003BDE18:
    /* 2BDE18 003BDE18 000060C4 */  lwc1       $f0, 0x0($3)
    /* 2BDE1C 003BDE1C 100020E6 */  swc1       $f0, 0x10($17)
    /* 2BDE20 003BDE20 000060C4 */  lwc1       $f0, 0x0($3)
    /* 2BDE24 003BDE24 140020E6 */  swc1       $f0, 0x14($17)
  .L003BDE28:
    /* 2BDE28 003BDE28 7800A28F */  lw         $2, 0x78($29)
    /* 2BDE2C 003BDE2C 2A004010 */  beqz       $2, .L003BDED8
    /* 2BDE30 003BDE30 00000000 */   nop
    /* 2BDE34 003BDE34 2D20A002 */  daddu      $4, $21, $0
    /* 2BDE38 003BDE38 09000524 */  addiu      $5, $0, 0x9
    /* 2BDE3C 003BDE3C 2D300000 */  daddu      $6, $0, $0
    /* 2BDE40 003BDE40 147C0F0C */  jal        func_003df050
    /* 2BDE44 003BDE44 B800A727 */   addiu     $7, $29, 0xB8
    /* 2BDE48 003BDE48 02004014 */  bnez       $2, .L003BDE54
    /* 2BDE4C 003BDE4C 00000000 */   nop
    /* 2BDE50 003BDE50 2D800000 */  daddu      $16, $0, $0
  .L003BDE54:
    /* 2BDE54 003BDE54 15000012 */  beqz       $16, .L003BDEAC
    /* 2BDE58 003BDE58 00000000 */   nop
    /* 2BDE5C 003BDE5C B800A38F */  lw         $3, 0xB8($29)
    /* 2BDE60 003BDE60 0300023C */  lui        $2, (0x35000 >> 16)
    /* 2BDE64 003BDE64 00504234 */  ori        $2, $2, (0x35000 & 0xFFFF)
    /* 2BDE68 003BDE68 2B106200 */  sltu       $2, $3, $2
    /* 2BDE6C 003BDE6C 06004014 */  bnez       $2, .L003BDE88
    /* 2BDE70 003BDE70 00000000 */   nop
    /* 2BDE74 003BDE74 0300013C */  lui        $1, (0x37003 >> 16)
    /* 2BDE78 003BDE78 03702134 */  ori        $1, $1, (0x37003 & 0xFFFF)
    /* 2BDE7C 003BDE7C 2B086100 */  sltu       $1, $3, $1
    /* 2BDE80 003BDE80 0A002014 */  bnez       $1, .L003BDEAC
    /* 2BDE84 003BDE84 00000000 */   nop
  .L003BDE88:
    /* 2BDE88 003BDE88 02000324 */  addiu      $3, $0, 0x2
    /* 2BDE8C 003BDE8C 0080023C */  lui        $2, (0x80000004 >> 16)
    /* 2BDE90 003BDE90 A000A3AF */  sw         $3, 0xA0($29)
    /* 2BDE94 003BDE94 647D0F0C */  jal        func_003df590
    /* 2BDE98 003BDE98 04004434 */   ori       $4, $2, (0x80000004 & 0xFFFF)
    /* 2BDE9C 003BDE9C A400A2AF */  sw         $2, 0xA4($29)
    /* 2BDEA0 003BDEA0 347D0F0C */  jal        func_003df4d0
    /* 2BDEA4 003BDEA4 A000A427 */   addiu     $4, $29, 0xA0
    /* 2BDEA8 003BDEA8 2D800000 */  daddu      $16, $0, $0
  .L003BDEAC:
    /* 2BDEAC 003BDEAC 32000012 */  beqz       $16, .L003BDF78
    /* 2BDEB0 003BDEB0 00000000 */   nop
    /* 2BDEB4 003BDEB4 2D20A002 */  daddu      $4, $21, $0
    /* 2BDEB8 003BDEB8 2D288002 */  daddu      $5, $20, $0
    /* 2BDEBC 003BDEBC 2D306002 */  daddu      $6, $19, $0
    /* 2BDEC0 003BDEC0 ACF50E0C */  jal        func_003bd6b0
    /* 2BDEC4 003BDEC4 2D384002 */   daddu     $7, $18, $0
    /* 2BDEC8 003BDEC8 2B004014 */  bnez       $2, .L003BDF78
    /* 2BDECC 003BDECC 080022AE */   sw        $2, 0x8($17)
    /* 2BDED0 003BDED0 29000010 */  b          .L003BDF78
    /* 2BDED4 003BDED4 2D800000 */   daddu     $16, $0, $0
  .L003BDED8:
    /* 2BDED8 003BDED8 2D20A002 */  daddu      $4, $21, $0
    /* 2BDEDC 003BDEDC 0A000524 */  addiu      $5, $0, 0xA
    /* 2BDEE0 003BDEE0 2D300000 */  daddu      $6, $0, $0
    /* 2BDEE4 003BDEE4 147C0F0C */  jal        func_003df050
    /* 2BDEE8 003BDEE8 B800A727 */   addiu     $7, $29, 0xB8
    /* 2BDEEC 003BDEEC 02004014 */  bnez       $2, .L003BDEF8
    /* 2BDEF0 003BDEF0 00000000 */   nop
    /* 2BDEF4 003BDEF4 2D800000 */  daddu      $16, $0, $0
  .L003BDEF8:
    /* 2BDEF8 003BDEF8 15000012 */  beqz       $16, .L003BDF50
    /* 2BDEFC 003BDEFC 00000000 */   nop
    /* 2BDF00 003BDF00 B800A38F */  lw         $3, 0xB8($29)
    /* 2BDF04 003BDF04 0300023C */  lui        $2, (0x35000 >> 16)
    /* 2BDF08 003BDF08 00504234 */  ori        $2, $2, (0x35000 & 0xFFFF)
    /* 2BDF0C 003BDF0C 2B106200 */  sltu       $2, $3, $2
    /* 2BDF10 003BDF10 06004014 */  bnez       $2, .L003BDF2C
    /* 2BDF14 003BDF14 00000000 */   nop
    /* 2BDF18 003BDF18 0300013C */  lui        $1, (0x37003 >> 16)
    /* 2BDF1C 003BDF1C 03702134 */  ori        $1, $1, (0x37003 & 0xFFFF)
    /* 2BDF20 003BDF20 2B086100 */  sltu       $1, $3, $1
    /* 2BDF24 003BDF24 0A002014 */  bnez       $1, .L003BDF50
    /* 2BDF28 003BDF28 00000000 */   nop
  .L003BDF2C:
    /* 2BDF2C 003BDF2C 02000324 */  addiu      $3, $0, 0x2
    /* 2BDF30 003BDF30 0080023C */  lui        $2, (0x80000004 >> 16)
    /* 2BDF34 003BDF34 9800A3AF */  sw         $3, 0x98($29)
    /* 2BDF38 003BDF38 647D0F0C */  jal        func_003df590
    /* 2BDF3C 003BDF3C 04004434 */   ori       $4, $2, (0x80000004 & 0xFFFF)
    /* 2BDF40 003BDF40 9C00A2AF */  sw         $2, 0x9C($29)
    /* 2BDF44 003BDF44 347D0F0C */  jal        func_003df4d0
    /* 2BDF48 003BDF48 9800A427 */   addiu     $4, $29, 0x98
    /* 2BDF4C 003BDF4C 2D800000 */  daddu      $16, $0, $0
  .L003BDF50:
    /* 2BDF50 003BDF50 09000012 */  beqz       $16, .L003BDF78
    /* 2BDF54 003BDF54 00000000 */   nop
    /* 2BDF58 003BDF58 2D20A002 */  daddu      $4, $21, $0
    /* 2BDF5C 003BDF5C 2D288002 */  daddu      $5, $20, $0
    /* 2BDF60 003BDF60 2D306002 */  daddu      $6, $19, $0
    /* 2BDF64 003BDF64 40F70E0C */  jal        func_003bdd00
    /* 2BDF68 003BDF68 2D384002 */   daddu     $7, $18, $0
    /* 2BDF6C 003BDF6C 02004014 */  bnez       $2, .L003BDF78
    /* 2BDF70 003BDF70 080022AE */   sw        $2, 0x8($17)
    /* 2BDF74 003BDF74 2D800000 */  daddu      $16, $0, $0
  .L003BDF78:
    /* 2BDF78 003BDF78 55000012 */  beqz       $16, .L003BE0D0
    /* 2BDF7C 003BDF7C 00000000 */   nop
    /* 2BDF80 003BDF80 7C00A28F */  lw         $2, 0x7C($29)
    /* 2BDF84 003BDF84 2A004010 */  beqz       $2, .L003BE030
    /* 2BDF88 003BDF88 00000000 */   nop
    /* 2BDF8C 003BDF8C 2D20A002 */  daddu      $4, $21, $0
    /* 2BDF90 003BDF90 09000524 */  addiu      $5, $0, 0x9
    /* 2BDF94 003BDF94 2D300000 */  daddu      $6, $0, $0
    /* 2BDF98 003BDF98 147C0F0C */  jal        func_003df050
    /* 2BDF9C 003BDF9C B800A727 */   addiu     $7, $29, 0xB8
    /* 2BDFA0 003BDFA0 02004014 */  bnez       $2, .L003BDFAC
    /* 2BDFA4 003BDFA4 00000000 */   nop
    /* 2BDFA8 003BDFA8 2D800000 */  daddu      $16, $0, $0
  .L003BDFAC:
    /* 2BDFAC 003BDFAC 15000012 */  beqz       $16, .L003BE004
    /* 2BDFB0 003BDFB0 00000000 */   nop
    /* 2BDFB4 003BDFB4 B800A38F */  lw         $3, 0xB8($29)
    /* 2BDFB8 003BDFB8 0300023C */  lui        $2, (0x35000 >> 16)
    /* 2BDFBC 003BDFBC 00504234 */  ori        $2, $2, (0x35000 & 0xFFFF)
    /* 2BDFC0 003BDFC0 2B106200 */  sltu       $2, $3, $2
    /* 2BDFC4 003BDFC4 06004014 */  bnez       $2, .L003BDFE0
    /* 2BDFC8 003BDFC8 00000000 */   nop
    /* 2BDFCC 003BDFCC 0300013C */  lui        $1, (0x37003 >> 16)
    /* 2BDFD0 003BDFD0 03702134 */  ori        $1, $1, (0x37003 & 0xFFFF)
    /* 2BDFD4 003BDFD4 2B086100 */  sltu       $1, $3, $1
    /* 2BDFD8 003BDFD8 0A002014 */  bnez       $1, .L003BE004
    /* 2BDFDC 003BDFDC 00000000 */   nop
  .L003BDFE0:
    /* 2BDFE0 003BDFE0 02000324 */  addiu      $3, $0, 0x2
    /* 2BDFE4 003BDFE4 0080023C */  lui        $2, (0x80000004 >> 16)
    /* 2BDFE8 003BDFE8 9000A3AF */  sw         $3, 0x90($29)
    /* 2BDFEC 003BDFEC 647D0F0C */  jal        func_003df590
    /* 2BDFF0 003BDFF0 04004434 */   ori       $4, $2, (0x80000004 & 0xFFFF)
    /* 2BDFF4 003BDFF4 9400A2AF */  sw         $2, 0x94($29)
    /* 2BDFF8 003BDFF8 347D0F0C */  jal        func_003df4d0
    /* 2BDFFC 003BDFFC 9000A427 */   addiu     $4, $29, 0x90
    /* 2BE000 003BE000 2D800000 */  daddu      $16, $0, $0
  .L003BE004:
    /* 2BE004 003BE004 32000012 */  beqz       $16, .L003BE0D0
    /* 2BE008 003BE008 00000000 */   nop
    /* 2BE00C 003BE00C 2D20A002 */  daddu      $4, $21, $0
    /* 2BE010 003BE010 2D288002 */  daddu      $5, $20, $0
    /* 2BE014 003BE014 2D384002 */  daddu      $7, $18, $0
    /* 2BE018 003BE018 ACF50E0C */  jal        func_003bd6b0
    /* 2BE01C 003BE01C 2D306002 */   daddu     $6, $19, $0
    /* 2BE020 003BE020 2B004014 */  bnez       $2, .L003BE0D0
    /* 2BE024 003BE024 0C0022AE */   sw        $2, 0xC($17)
    /* 2BE028 003BE028 29000010 */  b          .L003BE0D0
    /* 2BE02C 003BE02C 2D800000 */   daddu     $16, $0, $0
  .L003BE030:
    /* 2BE030 003BE030 2D20A002 */  daddu      $4, $21, $0
    /* 2BE034 003BE034 0A000524 */  addiu      $5, $0, 0xA
    /* 2BE038 003BE038 2D300000 */  daddu      $6, $0, $0
    /* 2BE03C 003BE03C 147C0F0C */  jal        func_003df050
    /* 2BE040 003BE040 B800A727 */   addiu     $7, $29, 0xB8
    /* 2BE044 003BE044 02004014 */  bnez       $2, .L003BE050
    /* 2BE048 003BE048 00000000 */   nop
    /* 2BE04C 003BE04C 2D800000 */  daddu      $16, $0, $0
  .L003BE050:
    /* 2BE050 003BE050 15000012 */  beqz       $16, .L003BE0A8
    /* 2BE054 003BE054 00000000 */   nop
    /* 2BE058 003BE058 B800A38F */  lw         $3, 0xB8($29)
    /* 2BE05C 003BE05C 0300023C */  lui        $2, (0x35000 >> 16)
    /* 2BE060 003BE060 00504234 */  ori        $2, $2, (0x35000 & 0xFFFF)
    /* 2BE064 003BE064 2B106200 */  sltu       $2, $3, $2
    /* 2BE068 003BE068 06004014 */  bnez       $2, .L003BE084
    /* 2BE06C 003BE06C 00000000 */   nop
    /* 2BE070 003BE070 0300013C */  lui        $1, (0x37003 >> 16)
    /* 2BE074 003BE074 03702134 */  ori        $1, $1, (0x37003 & 0xFFFF)
    /* 2BE078 003BE078 2B086100 */  sltu       $1, $3, $1
    /* 2BE07C 003BE07C 0A002014 */  bnez       $1, .L003BE0A8
    /* 2BE080 003BE080 00000000 */   nop
  .L003BE084:
    /* 2BE084 003BE084 02000324 */  addiu      $3, $0, 0x2
    /* 2BE088 003BE088 0080023C */  lui        $2, (0x80000004 >> 16)
    /* 2BE08C 003BE08C 8800A3AF */  sw         $3, 0x88($29)
    /* 2BE090 003BE090 647D0F0C */  jal        func_003df590
    /* 2BE094 003BE094 04004434 */   ori       $4, $2, (0x80000004 & 0xFFFF)
    /* 2BE098 003BE098 8C00A2AF */  sw         $2, 0x8C($29)
    /* 2BE09C 003BE09C 347D0F0C */  jal        func_003df4d0
    /* 2BE0A0 003BE0A0 8800A427 */   addiu     $4, $29, 0x88
    /* 2BE0A4 003BE0A4 2D800000 */  daddu      $16, $0, $0
  .L003BE0A8:
    /* 2BE0A8 003BE0A8 09000012 */  beqz       $16, .L003BE0D0
    /* 2BE0AC 003BE0AC 00000000 */   nop
    /* 2BE0B0 003BE0B0 2D20A002 */  daddu      $4, $21, $0
    /* 2BE0B4 003BE0B4 2D288002 */  daddu      $5, $20, $0
    /* 2BE0B8 003BE0B8 2D384002 */  daddu      $7, $18, $0
    /* 2BE0BC 003BE0BC 40F70E0C */  jal        func_003bdd00
    /* 2BE0C0 003BE0C0 2D306002 */   daddu     $6, $19, $0
    /* 2BE0C4 003BE0C4 02004014 */  bnez       $2, .L003BE0D0
    /* 2BE0C8 003BE0C8 0C0022AE */   sw        $2, 0xC($17)
    /* 2BE0CC 003BE0CC 2D800000 */  daddu      $16, $0, $0
  .L003BE0D0:
    /* 2BE0D0 003BE0D0 1E000016 */  bnez       $16, .L003BE14C
    /* 2BE0D4 003BE0D4 00000000 */   nop
    /* 2BE0D8 003BE0D8 0800248E */  lw         $4, 0x8($17)
    /* 2BE0DC 003BE0DC 0C008010 */  beqz       $4, .L003BE110
    /* 2BE0E0 003BE0E0 00000000 */   nop
    /* 2BE0E4 003BE0E4 03006292 */  lbu        $2, 0x3($19)
    /* 2BE0E8 003BE0E8 01004230 */  andi       $2, $2, 0x1
    /* 2BE0EC 003BE0EC 05004010 */  beqz       $2, .L003BE104
    /* 2BE0F0 003BE0F0 00000000 */   nop
    /* 2BE0F4 003BE0F4 74240F0C */  jal        func_003c91d0
    /* 2BE0F8 003BE0F8 00000000 */   nop
    /* 2BE0FC 003BE0FC 04000010 */  b          .L003BE110
    /* 2BE100 003BE100 080020AE */   sw        $0, 0x8($17)
  .L003BE104:
    /* 2BE104 003BE104 C0240F0C */  jal        func_003c9300
    /* 2BE108 003BE108 00000000 */   nop
    /* 2BE10C 003BE10C 080020AE */  sw         $0, 0x8($17)
  .L003BE110:
    /* 2BE110 003BE110 0F000010 */  b          .L003BE150
    /* 2BE114 003BE114 2D100000 */   daddu     $2, $0, $0
  .L003BE118:
    /* 2BE118 003BE118 0D000010 */  b          .L003BE150
    /* 2BE11C 003BE11C 2D100000 */   daddu     $2, $0, $0
  .L003BE120:
    /* 2BE120 003BE120 02000324 */  addiu      $3, $0, 0x2
    /* 2BE124 003BE124 0080023C */  lui        $2, (0x80000013 >> 16)
    /* 2BE128 003BE128 A800A3AF */  sw         $3, 0xA8($29)
    /* 2BE12C 003BE12C 13004434 */  ori        $4, $2, (0x80000013 & 0xFFFF)
    /* 2BE130 003BE130 647D0F0C */  jal        func_003df590
    /* 2BE134 003BE134 18000524 */   addiu     $5, $0, 0x18
    /* 2BE138 003BE138 AC00A2AF */  sw         $2, 0xAC($29)
    /* 2BE13C 003BE13C 347D0F0C */  jal        func_003df4d0
    /* 2BE140 003BE140 A800A427 */   addiu     $4, $29, 0xA8
    /* 2BE144 003BE144 02000010 */  b          .L003BE150
    /* 2BE148 003BE148 2D100000 */   daddu     $2, $0, $0
  .L003BE14C:
    /* 2BE14C 003BE14C 2D102002 */  daddu      $2, $17, $0
  .L003BE150:
    /* 2BE150 003BE150 6000BFDF */  ld         $31, 0x60($29)
    /* 2BE154 003BE154 5000B57B */  lq         $21, 0x50($29)
    /* 2BE158 003BE158 4000B47B */  lq         $20, 0x40($29)
    /* 2BE15C 003BE15C 3000B37B */  lq         $19, 0x30($29)
    /* 2BE160 003BE160 2000B27B */  lq         $18, 0x20($29)
    /* 2BE164 003BE164 1000B17B */  lq         $17, 0x10($29)
    /* 2BE168 003BE168 0000B07B */  lq         $16, 0x0($29)
    /* 2BE16C 003BE16C 0800E003 */  jr         $31
    /* 2BE170 003BE170 C000BD27 */   addiu     $29, $29, 0xC0
    /* 2BE174 003BE174 00000000 */  nop
    /* 2BE178 003BE178 00000000 */  nop
    /* 2BE17C 003BE17C 00000000 */  nop
.size func_003bdd00, 0x480
