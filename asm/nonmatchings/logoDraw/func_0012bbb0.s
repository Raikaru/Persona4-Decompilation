.section .text
.set noat
.set noreorder
glabel func_0012bbb0
    /* 2BBB0 0012BBB0 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 2BBB4 0012BBB4 5000BFFF */  sd         $31, 0x50($29)
    /* 2BBB8 0012BBB8 4000B37F */  sq         $19, 0x40($29)
    /* 2BBBC 0012BBBC 3000B27F */  sq         $18, 0x30($29)
    /* 2BBC0 0012BBC0 2000B17F */  sq         $17, 0x20($29)
    /* 2BBC4 0012BBC4 1000B07F */  sq         $16, 0x10($29)
    /* 2BBC8 0012BBC8 2D888000 */  daddu      $17, $4, $0
    /* 2BBCC 0012BBCC 5849110C */  jal        func_00452560
    /* 2BBD0 0012BBD0 00000000 */   nop
    /* 2BBD4 0012BBD4 2D804000 */  daddu      $16, $2, $0
    /* 2BBD8 0012BBD8 0000428C */  lw         $2, 0x0($2)
    /* 2BBDC 0012BBDC 0B00412C */  sltiu      $1, $2, 0xB
    /* 2BBE0 0012BBE0 DF002010 */  beqz       $1, .L0012BF60
    /* 2BBE4 0012BBE4 00000000 */   nop
    /* 2BBE8 0012BBE8 7400033C */  lui        $3, %hi(jtbl_007467E0)
    /* 2BBEC 0012BBEC E0676324 */  addiu      $3, $3, %lo(jtbl_007467E0)
    /* 2BBF0 0012BBF0 80100200 */  sll        $2, $2, 2
    /* 2BBF4 0012BBF4 21104300 */  addu       $2, $2, $3
    /* 2BBF8 0012BBF8 0000428C */  lw         $2, 0x0($2)
    /* 2BBFC 0012BBFC 08004000 */  jr         $2
    /* 2BC00 0012BC00 00000000 */   nop
    /* 2BC04 0012BC04 01000224 */  addiu      $2, $0, 0x1
    /* 2BC08 0012BC08 000002AE */  sw         $2, 0x0($16)
    /* 2BC0C 0012BC0C 02000224 */  addiu      $2, $0, 0x2
    /* 2BC10 0012BC10 000002AE */  sw         $2, 0x0($16)
    /* 2BC14 0012BC14 A89C8427 */  addiu      $4, $28, -0x6358
    /* 2BC18 0012BC18 5E00053C */  lui        $5, %hi(D_005E5730)
    /* 2BC1C 0012BC1C 3057A524 */  addiu      $5, $5, %lo(D_005E5730)
    /* 2BC20 0012BC20 B5000624 */  addiu      $6, $0, 0xB5
    /* 2BC24 0012BC24 DA02110C */  jal        func_00440b68
    /* 2BC28 0012BC28 00000000 */   nop
    /* 2BC2C 0012BC2C 5E00043C */  lui        $4, %hi(D_005E5760)
    /* 2BC30 0012BC30 60578424 */  addiu      $4, $4, %lo(D_005E5760)
    /* 2BC34 0012BC34 01000524 */  addiu      $5, $0, 0x1
    /* 2BC38 0012BC38 9852110C */  jal        func_00454a60
    /* 2BC3C 0012BC3C 00000000 */   nop
    /* 2BC40 0012BC40 0C0002AE */  sw         $2, 0xC($16)
    /* 2BC44 0012BC44 0C00048E */  lw         $4, 0xC($16)
    /* 2BC48 0012BC48 F054110C */  jal        func_004553c0
    /* 2BC4C 0012BC4C 00000000 */   nop
    /* 2BC50 0012BC50 C3004010 */  beqz       $2, .L0012BF60
    /* 2BC54 0012BC54 00000000 */   nop
    /* 2BC58 0012BC58 03000224 */  addiu      $2, $0, 0x3
    /* 2BC5C 0012BC5C 000002AE */  sw         $2, 0x0($16)
    /* 2BC60 0012BC60 5E00043C */  lui        $4, %hi(D_005E5730)
    /* 2BC64 0012BC64 30578424 */  addiu      $4, $4, %lo(D_005E5730)
    /* 2BC68 0012BC68 4D000524 */  addiu      $5, $0, 0x4D
    /* 2BC6C 0012BC6C A43A110C */  jal        func_0044ea90
    /* 2BC70 0012BC70 00000000 */   nop
    /* 2BC74 0012BC74 8800123C */  lui        $18, %hi(D_008873F4)
    /* 2BC78 0012BC78 F4735226 */  addiu      $18, $18, %lo(D_008873F4)
    /* 2BC7C 0012BC7C 01000424 */  addiu      $4, $0, 0x1
    /* 2BC80 0012BC80 0C000524 */  addiu      $5, $0, 0xC
    /* 2BC84 0012BC84 0400063C */  lui        $6, (0x40000 >> 16)
    /* 2BC88 0012BC88 0000428E */  lw         $2, 0x0($18)
    /* 2BC8C 0012BC8C 09F84000 */  jalr       $2
    /* 2BC90 0012BC90 00000000 */   nop
    /* 2BC94 0012BC94 2D984000 */  daddu      $19, $2, $0
    /* 2BC98 0012BC98 000040AC */  sw         $0, 0x0($2)
    /* 2BC9C 0012BC9C 0000A0FF */  sd         $0, 0x0($29)
    /* 2BCA0 0012BCA0 0800A0FF */  sd         $0, 0x8($29)
    /* 2BCA4 0012BCA4 2D200000 */  daddu      $4, $0, $0
    /* 2BCA8 0012BCA8 5E00053C */  lui        $5, %hi(D_005E5770)
    /* 2BCAC 0012BCAC 7057A524 */  addiu      $5, $5, %lo(D_005E5770)
    /* 2BCB0 0012BCB0 2D300000 */  daddu      $6, $0, $0
    /* 2BCB4 0012BCB4 2D380000 */  daddu      $7, $0, $0
    /* 2BCB8 0012BCB8 2D400000 */  daddu      $8, $0, $0
    /* 2BCBC 0012BCBC 2D480000 */  daddu      $9, $0, $0
    /* 2BCC0 0012BCC0 2D500000 */  daddu      $10, $0, $0
    /* 2BCC4 0012BCC4 2D580000 */  daddu      $11, $0, $0
    /* 2BCC8 0012BCC8 F499110C */  jal        func_004667d0
    /* 2BCCC 0012BCCC 00000000 */   nop
    /* 2BCD0 0012BCD0 040062AE */  sw         $2, 0x4($19)
    /* 2BCD4 0012BCD4 989C8427 */  addiu      $4, $28, -0x6368
    /* 2BCD8 0012BCD8 00010524 */  addiu      $5, $0, 0x100
    /* 2BCDC 0012BCDC 2D300000 */  daddu      $6, $0, $0
    /* 2BCE0 0012BCE0 2D380000 */  daddu      $7, $0, $0
    /* 2BCE4 0012BCE4 1300083C */  lui        $8, %hi(func_0012b890)
    /* 2BCE8 0012BCE8 90B80825 */  addiu      $8, $8, %lo(func_0012b890)
    /* 2BCEC 0012BCEC 1300093C */  lui        $9, %hi(func_0012b940)
    /* 2BCF0 0012BCF0 40B92925 */  addiu      $9, $9, %lo(func_0012b940)
    /* 2BCF4 0012BCF4 2D506002 */  daddu      $10, $19, $0
    /* 2BCF8 0012BCF8 7847110C */  jal        func_00451de0
    /* 2BCFC 0012BCFC 00000000 */   nop
    /* 2BD00 0012BD00 100002AE */  sw         $2, 0x10($16)
    /* 2BD04 0012BD04 5E00043C */  lui        $4, %hi(D_005E5730)
    /* 2BD08 0012BD08 30578424 */  addiu      $4, $4, %lo(D_005E5730)
    /* 2BD0C 0012BD0C 4D000524 */  addiu      $5, $0, 0x4D
    /* 2BD10 0012BD10 A43A110C */  jal        func_0044ea90
    /* 2BD14 0012BD14 00000000 */   nop
    /* 2BD18 0012BD18 01000424 */  addiu      $4, $0, 0x1
    /* 2BD1C 0012BD1C 0C000524 */  addiu      $5, $0, 0xC
    /* 2BD20 0012BD20 0400063C */  lui        $6, (0x40000 >> 16)
    /* 2BD24 0012BD24 0000428E */  lw         $2, 0x0($18)
    /* 2BD28 0012BD28 09F84000 */  jalr       $2
    /* 2BD2C 0012BD2C 00000000 */   nop
    /* 2BD30 0012BD30 2D904000 */  daddu      $18, $2, $0
    /* 2BD34 0012BD34 000040AC */  sw         $0, 0x0($2)
    /* 2BD38 0012BD38 0000A0FF */  sd         $0, 0x0($29)
    /* 2BD3C 0012BD3C 0800A0FF */  sd         $0, 0x8($29)
    /* 2BD40 0012BD40 2D200000 */  daddu      $4, $0, $0
    /* 2BD44 0012BD44 5E00053C */  lui        $5, %hi(D_005E5790)
    /* 2BD48 0012BD48 9057A524 */  addiu      $5, $5, %lo(D_005E5790)
    /* 2BD4C 0012BD4C 2D300000 */  daddu      $6, $0, $0
    /* 2BD50 0012BD50 2D380000 */  daddu      $7, $0, $0
    /* 2BD54 0012BD54 2D400000 */  daddu      $8, $0, $0
    /* 2BD58 0012BD58 2D480000 */  daddu      $9, $0, $0
    /* 2BD5C 0012BD5C 2D500000 */  daddu      $10, $0, $0
    /* 2BD60 0012BD60 2D580000 */  daddu      $11, $0, $0
    /* 2BD64 0012BD64 F499110C */  jal        func_004667d0
    /* 2BD68 0012BD68 00000000 */   nop
    /* 2BD6C 0012BD6C 040042AE */  sw         $2, 0x4($18)
    /* 2BD70 0012BD70 989C8427 */  addiu      $4, $28, -0x6368
    /* 2BD74 0012BD74 00010524 */  addiu      $5, $0, 0x100
    /* 2BD78 0012BD78 2D300000 */  daddu      $6, $0, $0
    /* 2BD7C 0012BD7C 2D380000 */  daddu      $7, $0, $0
    /* 2BD80 0012BD80 1300083C */  lui        $8, %hi(func_0012b890)
    /* 2BD84 0012BD84 90B80825 */  addiu      $8, $8, %lo(func_0012b890)
    /* 2BD88 0012BD88 1300093C */  lui        $9, %hi(func_0012b940)
    /* 2BD8C 0012BD8C 40B92925 */  addiu      $9, $9, %lo(func_0012b940)
    /* 2BD90 0012BD90 2D504002 */  daddu      $10, $18, $0
    /* 2BD94 0012BD94 7847110C */  jal        func_00451de0
    /* 2BD98 0012BD98 00000000 */   nop
    /* 2BD9C 0012BD9C 140002AE */  sw         $2, 0x14($16)
    /* 2BDA0 0012BDA0 6F000010 */  b          .L0012BF60
    /* 2BDA4 0012BDA4 00000000 */   nop
    /* 2BDA8 0012BDA8 1000138E */  lw         $19, 0x10($16)
    /* 2BDAC 0012BDAC 2D206002 */  daddu      $4, $19, $0
    /* 2BDB0 0012BDB0 5849110C */  jal        func_00452560
    /* 2BDB4 0012BDB4 00000000 */   nop
    /* 2BDB8 0012BDB8 2D904000 */  daddu      $18, $2, $0
    /* 2BDBC 0012BDBC 2D206002 */  daddu      $4, $19, $0
    /* 2BDC0 0012BDC0 2449110C */  jal        func_00452490
    /* 2BDC4 0012BDC4 00000000 */   nop
    /* 2BDC8 0012BDC8 04004014 */  bnez       $2, .L0012BDDC
    /* 2BDCC 0012BDCC 00000000 */   nop
    /* 2BDD0 0012BDD0 2D100000 */  daddu      $2, $0, $0
    /* 2BDD4 0012BDD4 09000010 */  b          .L0012BDFC
    /* 2BDD8 0012BDD8 00000000 */   nop
  .L0012BDDC:
    /* 2BDDC 0012BDDC 0000438E */  lw         $3, 0x0($18)
    /* 2BDE0 0012BDE0 03000224 */  addiu      $2, $0, 0x3
    /* 2BDE4 0012BDE4 04006214 */  bne        $3, $2, .L0012BDF8
    /* 2BDE8 0012BDE8 00000000 */   nop
    /* 2BDEC 0012BDEC 01000224 */  addiu      $2, $0, 0x1
    /* 2BDF0 0012BDF0 02000010 */  b          .L0012BDFC
    /* 2BDF4 0012BDF4 00000000 */   nop
  .L0012BDF8:
    /* 2BDF8 0012BDF8 2D100000 */  daddu      $2, $0, $0
  .L0012BDFC:
    /* 2BDFC 0012BDFC 58004010 */  beqz       $2, .L0012BF60
    /* 2BE00 0012BE00 00000000 */   nop
    /* 2BE04 0012BE04 1400138E */  lw         $19, 0x14($16)
    /* 2BE08 0012BE08 2D206002 */  daddu      $4, $19, $0
    /* 2BE0C 0012BE0C 5849110C */  jal        func_00452560
    /* 2BE10 0012BE10 00000000 */   nop
    /* 2BE14 0012BE14 2D904000 */  daddu      $18, $2, $0
    /* 2BE18 0012BE18 2D206002 */  daddu      $4, $19, $0
    /* 2BE1C 0012BE1C 2449110C */  jal        func_00452490
    /* 2BE20 0012BE20 00000000 */   nop
    /* 2BE24 0012BE24 04004014 */  bnez       $2, .L0012BE38
    /* 2BE28 0012BE28 00000000 */   nop
    /* 2BE2C 0012BE2C 2D100000 */  daddu      $2, $0, $0
    /* 2BE30 0012BE30 09000010 */  b          .L0012BE58
    /* 2BE34 0012BE34 00000000 */   nop
  .L0012BE38:
    /* 2BE38 0012BE38 0000438E */  lw         $3, 0x0($18)
    /* 2BE3C 0012BE3C 03000224 */  addiu      $2, $0, 0x3
    /* 2BE40 0012BE40 04006214 */  bne        $3, $2, .L0012BE54
    /* 2BE44 0012BE44 00000000 */   nop
    /* 2BE48 0012BE48 01000224 */  addiu      $2, $0, 0x1
    /* 2BE4C 0012BE4C 02000010 */  b          .L0012BE58
    /* 2BE50 0012BE50 00000000 */   nop
  .L0012BE54:
    /* 2BE54 0012BE54 2D100000 */  daddu      $2, $0, $0
  .L0012BE58:
    /* 2BE58 0012BE58 41004010 */  beqz       $2, .L0012BF60
    /* 2BE5C 0012BE5C 00000000 */   nop
    /* 2BE60 0012BE60 04000224 */  addiu      $2, $0, 0x4
    /* 2BE64 0012BE64 000002AE */  sw         $2, 0x0($16)
    /* 2BE68 0012BE68 3D000010 */  b          .L0012BF60
    /* 2BE6C 0012BE6C 00000000 */   nop
    /* 2BE70 0012BE70 05000224 */  addiu      $2, $0, 0x5
    /* 2BE74 0012BE74 000002AE */  sw         $2, 0x0($16)
    /* 2BE78 0012BE78 080000AE */  sw         $0, 0x8($16)
    /* 2BE7C 0012BE7C 2D200000 */  daddu      $4, $0, $0
    /* 2BE80 0012BE80 0A000524 */  addiu      $5, $0, 0xA
    /* 2BE84 0012BE84 9089040C */  jal        func_00122640
    /* 2BE88 0012BE88 00000000 */   nop
    /* 2BE8C 0012BE8C 0800028E */  lw         $2, 0x8($16)
    /* 2BE90 0012BE90 01004224 */  addiu      $2, $2, 0x1
    /* 2BE94 0012BE94 080002AE */  sw         $2, 0x8($16)
    /* 2BE98 0012BE98 46004228 */  slti       $2, $2, 0x46
    /* 2BE9C 0012BE9C 30004014 */  bnez       $2, .L0012BF60
    /* 2BEA0 0012BEA0 00000000 */   nop
    /* 2BEA4 0012BEA4 06000224 */  addiu      $2, $0, 0x6
    /* 2BEA8 0012BEA8 000002AE */  sw         $2, 0x0($16)
    /* 2BEAC 0012BEAC 01000424 */  addiu      $4, $0, 0x1
    /* 2BEB0 0012BEB0 0A000524 */  addiu      $5, $0, 0xA
    /* 2BEB4 0012BEB4 4889040C */  jal        func_00122520
    /* 2BEB8 0012BEB8 00000000 */   nop
    /* 2BEBC 0012BEBC 28000010 */  b          .L0012BF60
    /* 2BEC0 0012BEC0 00000000 */   nop
    /* 2BEC4 0012BEC4 C889040C */  jal        func_00122720
    /* 2BEC8 0012BEC8 00000000 */   nop
    /* 2BECC 0012BECC 24004010 */  beqz       $2, .L0012BF60
    /* 2BED0 0012BED0 00000000 */   nop
    /* 2BED4 0012BED4 07000224 */  addiu      $2, $0, 0x7
    /* 2BED8 0012BED8 000002AE */  sw         $2, 0x0($16)
    /* 2BEDC 0012BEDC 08000224 */  addiu      $2, $0, 0x8
    /* 2BEE0 0012BEE0 000002AE */  sw         $2, 0x0($16)
    /* 2BEE4 0012BEE4 080000AE */  sw         $0, 0x8($16)
    /* 2BEE8 0012BEE8 2D200000 */  daddu      $4, $0, $0
    /* 2BEEC 0012BEEC 0A000524 */  addiu      $5, $0, 0xA
    /* 2BEF0 0012BEF0 9089040C */  jal        func_00122640
    /* 2BEF4 0012BEF4 00000000 */   nop
    /* 2BEF8 0012BEF8 0800028E */  lw         $2, 0x8($16)
    /* 2BEFC 0012BEFC 01004224 */  addiu      $2, $2, 0x1
    /* 2BF00 0012BF00 080002AE */  sw         $2, 0x8($16)
    /* 2BF04 0012BF04 46004228 */  slti       $2, $2, 0x46
    /* 2BF08 0012BF08 15004014 */  bnez       $2, .L0012BF60
    /* 2BF0C 0012BF0C 00000000 */   nop
    /* 2BF10 0012BF10 09000224 */  addiu      $2, $0, 0x9
    /* 2BF14 0012BF14 000002AE */  sw         $2, 0x0($16)
    /* 2BF18 0012BF18 01000424 */  addiu      $4, $0, 0x1
    /* 2BF1C 0012BF1C 0A000524 */  addiu      $5, $0, 0xA
    /* 2BF20 0012BF20 4889040C */  jal        func_00122520
    /* 2BF24 0012BF24 00000000 */   nop
    /* 2BF28 0012BF28 0D000010 */  b          .L0012BF60
    /* 2BF2C 0012BF2C 00000000 */   nop
    /* 2BF30 0012BF30 C889040C */  jal        func_00122720
    /* 2BF34 0012BF34 00000000 */   nop
    /* 2BF38 0012BF38 09004010 */  beqz       $2, .L0012BF60
    /* 2BF3C 0012BF3C 00000000 */   nop
    /* 2BF40 0012BF40 0A000224 */  addiu      $2, $0, 0xA
    /* 2BF44 0012BF44 000002AE */  sw         $2, 0x0($16)
    /* 2BF48 0012BF48 C889040C */  jal        func_00122720
    /* 2BF4C 0012BF4C 00000000 */   nop
    /* 2BF50 0012BF50 03004010 */  beqz       $2, .L0012BF60
    /* 2BF54 0012BF54 00000000 */   nop
    /* 2BF58 0012BF58 01000224 */  addiu      $2, $0, 0x1
    /* 2BF5C 0012BF5C 040002AE */  sw         $2, 0x4($16)
  .L0012BF60:
    /* 2BF60 0012BF60 6482110C */  jal        func_00460990
    /* 2BF64 0012BF64 00000000 */   nop
    /* 2BF68 0012BF68 2D284000 */  daddu      $5, $2, $0
    /* 2BF6C 0012BF6C 1300033C */  lui        $3, %hi(func_0012b9a0)
    /* 2BF70 0012BF70 A0B96324 */  addiu      $3, $3, %lo(func_0012b9a0)
    /* 2BF74 0012BF74 080043AC */  sw         $3, 0x8($2)
    /* 2BF78 0012BF78 100051AC */  sw         $17, 0x10($2)
    /* 2BF7C 0012BF7C 7900043C */  lui        $4, %hi(D_00795E60)
    /* 2BF80 0012BF80 605E8424 */  addiu      $4, $4, %lo(D_00795E60)
    /* 2BF84 0012BF84 B082110C */  jal        func_00460ac0
    /* 2BF88 0012BF88 00000000 */   nop
    /* 2BF8C 0012BF8C 2D100000 */  daddu      $2, $0, $0
    /* 2BF90 0012BF90 5000BFDF */  ld         $31, 0x50($29)
    /* 2BF94 0012BF94 4000B37B */  lq         $19, 0x40($29)
    /* 2BF98 0012BF98 3000B27B */  lq         $18, 0x30($29)
    /* 2BF9C 0012BF9C 2000B17B */  lq         $17, 0x20($29)
    /* 2BFA0 0012BFA0 1000B07B */  lq         $16, 0x10($29)
    /* 2BFA4 0012BFA4 6000BD27 */  addiu      $29, $29, 0x60
    /* 2BFA8 0012BFA8 0800E003 */  jr         $31
    /* 2BFAC 0012BFAC 00000000 */   nop
.size func_0012bbb0, 0x400
