.section .text
.set noat
.set noreorder
glabel func_0043bcb8
    /* 33BCB8 0043BCB8 71000C3C */  lui        $12, %hi(D_0070FC58)
    /* 33BCBC 0043BCBC FFFF023C */  lui        $2, (0xFFFFFFF0 >> 16)
    /* 33BCC0 0043BCC0 0F008424 */  addiu      $4, $4, 0xF
    /* 33BCC4 0043BCC4 F0FF4234 */  ori        $2, $2, (0xFFFFFFF0 & 0xFFFF)
    /* 33BCC8 0043BCC8 58FC888D */  lw         $8, %lo(D_0070FC58)($12)
    /* 33BCCC 0043BCCC 24588200 */  and        $11, $4, $2
    /* 33BCD0 0043BCD0 2D480000 */  daddu      $9, $0, $0
    /* 33BCD4 0043BCD4 04000010 */  b          .L0043BCE8
    /* 33BCD8 0043BCD8 71000D3C */   lui       $13, %hi(D_0070FC78)
    /* 33BCDC 0043BCDC 00000000 */  nop
  .L0043BCE0:
    /* 33BCE0 0043BCE0 3A000011 */  beqz       $8, .L0043BDCC
    /* 33BCE4 0043BCE4 00000000 */   nop
  .L0043BCE8:
    /* 33BCE8 0043BCE8 0000058D */  lw         $5, 0x0($8)
    /* 33BCEC 0043BCEC 3500A104 */  bgez       $5, .L0043BDC4
    /* 33BCF0 0043BCF0 2D300001 */   daddu     $6, $8, $0
    /* 33BCF4 0043BCF4 0400068D */  lw         $6, 0x4($8)
    /* 33BCF8 0043BCF8 0300CB14 */  bne        $6, $11, .L0043BD08
    /* 33BCFC 0043BCFC 2B106601 */   sltu      $2, $11, $6
    /* 33BD00 0043BD00 2F000010 */  b          .L0043BDC0
    /* 33BD04 0043BD04 2D480001 */   daddu     $9, $8, $0
  .L0043BD08:
    /* 33BD08 0043BD08 2D004010 */  beqz       $2, .L0043BDC0
    /* 33BD0C 0043BD0C FFFF0A24 */   addiu     $10, $0, -0x1
    /* 33BD10 0043BD10 7100093C */  lui        $9, %hi(D_0070FC64)
    /* 33BD14 0043BD14 64FC228D */  lw         $2, %lo(D_0070FC64)($9)
    /* 33BD18 0043BD18 FFFF4224 */  addiu      $2, $2, -0x1
    /* 33BD1C 0043BD1C 15004018 */  blez       $2, .L0043BD74
    /* 33BD20 0043BD20 2D380000 */   daddu     $7, $0, $0
    /* 33BD24 0043BD24 58FC828D */  lw         $2, %lo(D_0070FC58)($12)
    /* 33BD28 0043BD28 0000438C */  lw         $3, 0x0($2)
    /* 33BD2C 0043BD2C 04006014 */  bnez       $3, .L0043BD40
    /* 33BD30 0043BD30 00000000 */   nop
    /* 33BD34 0043BD34 0F000010 */  b          .L0043BD74
    /* 33BD38 0043BD38 2D500000 */   daddu     $10, $0, $0
    /* 33BD3C 0043BD3C 00000000 */  nop
  .L0043BD40:
    /* 33BD40 0043BD40 64FC228D */  lw         $2, %lo(D_0070FC64)($9)
    /* 33BD44 0043BD44 0100E724 */  addiu      $7, $7, 0x1
    /* 33BD48 0043BD48 FFFF4224 */  addiu      $2, $2, -0x1
    /* 33BD4C 0043BD4C 2A10E200 */  slt        $2, $7, $2
    /* 33BD50 0043BD50 08004010 */  beqz       $2, .L0043BD74
    /* 33BD54 0043BD54 0C000224 */   addiu     $2, $0, 0xC
    /* 33BD58 0043BD58 58FC848D */  lw         $4, %lo(D_0070FC58)($12)
    /* 33BD5C 0043BD5C 1810E200 */  mult       $2, $7, $2
    /* 33BD60 0043BD60 21104400 */  addu       $2, $2, $4
    /* 33BD64 0043BD64 0000438C */  lw         $3, 0x0($2)
    /* 33BD68 0043BD68 F5FF6014 */  bnez       $3, .L0043BD40
    /* 33BD6C 0043BD6C 00000000 */   nop
    /* 33BD70 0043BD70 2D50E000 */  daddu      $10, $7, $0
  .L0043BD74:
    /* 33BD74 0043BD74 10004005 */  bltz       $10, .L0043BDB8
    /* 33BD78 0043BD78 0C000424 */   addiu     $4, $0, 0xC
    /* 33BD7C 0043BD7C 58FC838D */  lw         $3, %lo(D_0070FC58)($12)
    /* 33BD80 0043BD80 18204401 */  mult       $4, $10, $4
    /* 33BD84 0043BD84 0800078D */  lw         $7, 0x8($8)
    /* 33BD88 0043BD88 2128AB00 */  addu       $5, $5, $11
    /* 33BD8C 0043BD8C 0080023C */  lui        $2, (0x80000000 >> 16)
    /* 33BD90 0043BD90 2528A200 */  or         $5, $5, $2
    /* 33BD94 0043BD94 2330CB00 */  subu       $6, $6, $11
    /* 33BD98 0043BD98 2D480001 */  daddu      $9, $8, $0
    /* 33BD9C 0043BD9C 21186400 */  addu       $3, $3, $4
    /* 33BDA0 0043BDA0 000065AC */  sw         $5, 0x0($3)
    /* 33BDA4 0043BDA4 040066AC */  sw         $6, 0x4($3)
    /* 33BDA8 0043BDA8 080067AC */  sw         $7, 0x8($3)
    /* 33BDAC 0043BDAC 080003AD */  sw         $3, 0x8($8)
    /* 33BDB0 0043BDB0 03000010 */  b          .L0043BDC0
    /* 33BDB4 0043BDB4 04000BAD */   sw        $11, 0x4($8)
  .L0043BDB8:
    /* 33BDB8 0043BDB8 2D480001 */  daddu      $9, $8, $0
    /* 33BDBC 0043BDBC 04002BAD */  sw         $11, 0x4($9)
  .L0043BDC0:
    /* 33BDC0 0043BDC0 2D300001 */  daddu      $6, $8, $0
  .L0043BDC4:
    /* 33BDC4 0043BDC4 C6FF2011 */  beqz       $9, .L0043BCE0
    /* 33BDC8 0043BDC8 0800C88C */   lw        $8, 0x8($6)
  .L0043BDCC:
    /* 33BDCC 0043BDCC 2D002055 */  bnel       $9, $0, .L0043BE84
    /* 33BDD0 0043BDD0 0000238D */   lw        $3, 0x0($9)
    /* 33BDD4 0043BDD4 78FCA325 */  addiu      $3, $13, %lo(D_0070FC78)
    /* 33BDD8 0043BDD8 0400628C */  lw         $2, 0x4($3)
    /* 33BDDC 0043BDDC 2B104B00 */  sltu       $2, $2, $11
    /* 33BDE0 0043BDE0 25004014 */  bnez       $2, .L0043BE78
    /* 33BDE4 0043BDE4 7100053C */   lui       $5, %hi(D_0070FC64)
    /* 33BDE8 0043BDE8 FFFF0A24 */  addiu      $10, $0, -0x1
    /* 33BDEC 0043BDEC 64FCA28C */  lw         $2, %lo(D_0070FC64)($5)
    /* 33BDF0 0043BDF0 FFFF4224 */  addiu      $2, $2, -0x1
    /* 33BDF4 0043BDF4 2A102201 */  slt        $2, $9, $2
    /* 33BDF8 0043BDF8 14004010 */  beqz       $2, .L0043BE4C
    /* 33BDFC 0043BDFC 2D380000 */   daddu     $7, $0, $0
    /* 33BE00 0043BE00 58FC828D */  lw         $2, %lo(D_0070FC58)($12)
    /* 33BE04 0043BE04 0000438C */  lw         $3, 0x0($2)
    /* 33BE08 0043BE08 03006014 */  bnez       $3, .L0043BE18
    /* 33BE0C 0043BE0C 00000000 */   nop
    /* 33BE10 0043BE10 0E000010 */  b          .L0043BE4C
    /* 33BE14 0043BE14 2D500000 */   daddu     $10, $0, $0
  .L0043BE18:
    /* 33BE18 0043BE18 64FCA28C */  lw         $2, %lo(D_0070FC64)($5)
    /* 33BE1C 0043BE1C 0100E724 */  addiu      $7, $7, 0x1
    /* 33BE20 0043BE20 FFFF4224 */  addiu      $2, $2, -0x1
    /* 33BE24 0043BE24 2A10E200 */  slt        $2, $7, $2
    /* 33BE28 0043BE28 08004010 */  beqz       $2, .L0043BE4C
    /* 33BE2C 0043BE2C 0C000224 */   addiu     $2, $0, 0xC
    /* 33BE30 0043BE30 58FC848D */  lw         $4, %lo(D_0070FC58)($12)
    /* 33BE34 0043BE34 1810E200 */  mult       $2, $7, $2
    /* 33BE38 0043BE38 21104400 */  addu       $2, $2, $4
    /* 33BE3C 0043BE3C 0000438C */  lw         $3, 0x0($2)
    /* 33BE40 0043BE40 F5FF6014 */  bnez       $3, .L0043BE18
    /* 33BE44 0043BE44 00000000 */   nop
    /* 33BE48 0043BE48 2D50E000 */  daddu      $10, $7, $0
  .L0043BE4C:
    /* 33BE4C 0043BE4C 0A004005 */  bltz       $10, .L0043BE78
    /* 33BE50 0043BE50 0C000224 */   addiu     $2, $0, 0xC
    /* 33BE54 0043BE54 58FC838D */  lw         $3, %lo(D_0070FC58)($12)
    /* 33BE58 0043BE58 18104201 */  mult       $2, $10, $2
    /* 33BE5C 0043BE5C 78FCA58D */  lw         $5, %lo(D_0070FC78)($13)
    /* 33BE60 0043BE60 21486200 */  addu       $9, $3, $2
    /* 33BE64 0043BE64 080020AD */  sw         $0, 0x8($9)
    /* 33BE68 0043BE68 000025AD */  sw         $5, 0x0($9)
    /* 33BE6C 0043BE6C 04002BAD */  sw         $11, 0x4($9)
    /* 33BE70 0043BE70 03000010 */  b          .L0043BE80
    /* 33BE74 0043BE74 0800C9AC */   sw        $9, 0x8($6)
  .L0043BE78:
    /* 33BE78 0043BE78 0800E003 */  jr         $31
    /* 33BE7C 0043BE7C FFFF0224 */   addiu     $2, $0, -0x1
  .L0043BE80:
    /* 33BE80 0043BE80 0000238D */  lw         $3, 0x0($9)
  .L0043BE84:
    /* 33BE84 0043BE84 FF7F023C */  lui        $2, (0x7FFFFFFF >> 16)
    /* 33BE88 0043BE88 FFFF4234 */  ori        $2, $2, (0x7FFFFFFF & 0xFFFF)
    /* 33BE8C 0043BE8C 0400248D */  lw         $4, 0x4($9)
    /* 33BE90 0043BE90 24186200 */  and        $3, $3, $2
    /* 33BE94 0043BE94 000023AD */  sw         $3, 0x0($9)
    /* 33BE98 0043BE98 21206400 */  addu       $4, $3, $4
    /* 33BE9C 0043BE9C 78FCA28D */  lw         $2, %lo(D_0070FC78)($13)
    /* 33BEA0 0043BEA0 2B104400 */  sltu       $2, $2, $4
    /* 33BEA4 0043BEA4 06004010 */  beqz       $2, .L0043BEC0
    /* 33BEA8 0043BEA8 78FCA525 */   addiu     $5, $13, %lo(D_0070FC78)
    /* 33BEAC 0043BEAC 7100033C */  lui        $3, %hi(D_0070FC70)
    /* 33BEB0 0043BEB0 78FCA4AD */  sw         $4, %lo(D_0070FC78)($13)
    /* 33BEB4 0043BEB4 70FC628C */  lw         $2, %lo(D_0070FC70)($3)
    /* 33BEB8 0043BEB8 23104400 */  subu       $2, $2, $4
    /* 33BEBC 0043BEBC 0400A2AC */  sw         $2, 0x4($5)
  .L0043BEC0:
    /* 33BEC0 0043BEC0 0800E003 */  jr         $31
    /* 33BEC4 0043BEC4 0000228D */   lw        $2, 0x0($9)
.size func_0043bcb8, 0x210
