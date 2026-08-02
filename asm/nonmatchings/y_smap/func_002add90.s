.section .text
.set noat
.set noreorder
glabel func_002add90
    /* 1ADD90 002ADD90 20FFBD27 */  addiu      $29, $29, -0xE0
    /* 1ADD94 002ADD94 8000BFFF */  sd         $31, 0x80($29)
    /* 1ADD98 002ADD98 7000B77F */  sq         $23, 0x70($29)
    /* 1ADD9C 002ADD9C 6000B67F */  sq         $22, 0x60($29)
    /* 1ADDA0 002ADDA0 5000B57F */  sq         $21, 0x50($29)
    /* 1ADDA4 002ADDA4 4000B47F */  sq         $20, 0x40($29)
    /* 1ADDA8 002ADDA8 3000B37F */  sq         $19, 0x30($29)
    /* 1ADDAC 002ADDAC 2000B27F */  sq         $18, 0x20($29)
    /* 1ADDB0 002ADDB0 1000B17F */  sq         $17, 0x10($29)
    /* 1ADDB4 002ADDB4 0000B07F */  sq         $16, 0x0($29)
    /* 1ADDB8 002ADDB8 2DA88000 */  daddu      $21, $4, $0
    /* 1ADDBC 002ADDBC 3800918C */  lw         $17, 0x38($4)
    /* 1ADDC0 002ADDC0 7F00023C */  lui        $2, %hi(D_007EFA04)
    /* 1ADDC4 002ADDC4 04FA428C */  lw         $2, %lo(D_007EFA04)($2)
    /* 1ADDC8 002ADDC8 B800A427 */  addiu      $4, $29, 0xB8
    /* 1ADDCC 002ADDCC 2002458C */  lw         $5, 0x220($2)
    /* 1ADDD0 002ADDD0 FCA1050C */  jal        func_001687f0
    /* 1ADDD4 002ADDD4 00000000 */   nop
    /* 1ADDD8 002ADDD8 B800A2C7 */  lwc1       $f2, 0xB8($29)
    /* 1ADDDC 002ADDDC BC00A1C7 */  lwc1       $f1, 0xBC($29)
    /* 1ADDE0 002ADDE0 C000A0C7 */  lwc1       $f0, 0xC0($29)
    /* 1ADDE4 002ADDE4 C800A2E7 */  swc1       $f2, 0xC8($29)
    /* 1ADDE8 002ADDE8 CC00A1E7 */  swc1       $f1, 0xCC($29)
    /* 1ADDEC 002ADDEC D000A0E7 */  swc1       $f0, 0xD0($29)
    /* 1ADDF0 002ADDF0 6482110C */  jal        func_00460990
    /* 1ADDF4 002ADDF4 00000000 */   nop
    /* 1ADDF8 002ADDF8 2D284000 */  daddu      $5, $2, $0
    /* 1ADDFC 002ADDFC 2B00033C */  lui        $3, %hi(func_002add10)
    /* 1ADE00 002ADE00 10DD6324 */  addiu      $3, $3, %lo(func_002add10)
    /* 1ADE04 002ADE04 080043AC */  sw         $3, 0x8($2)
    /* 1ADE08 002ADE08 100051AC */  sw         $17, 0x10($2)
    /* 1ADE0C 002ADE0C 7900043C */  lui        $4, %hi(D_00794C30)
    /* 1ADE10 002ADE10 304C8424 */  addiu      $4, $4, %lo(D_00794C30)
    /* 1ADE14 002ADE14 B082110C */  jal        func_00460ac0
    /* 1ADE18 002ADE18 00000000 */   nop
    /* 1ADE1C 002ADE1C 6482110C */  jal        func_00460990
    /* 1ADE20 002ADE20 00000000 */   nop
    /* 1ADE24 002ADE24 2D284000 */  daddu      $5, $2, $0
    /* 1ADE28 002ADE28 2B00033C */  lui        $3, %hi(func_002add60)
    /* 1ADE2C 002ADE2C 60DD6324 */  addiu      $3, $3, %lo(func_002add60)
    /* 1ADE30 002ADE30 080043AC */  sw         $3, 0x8($2)
    /* 1ADE34 002ADE34 100051AC */  sw         $17, 0x10($2)
    /* 1ADE38 002ADE38 7900043C */  lui        $4, %hi(D_00794E10)
    /* 1ADE3C 002ADE3C 104E8424 */  addiu      $4, $4, %lo(D_00794E10)
    /* 1ADE40 002ADE40 B082110C */  jal        func_00460ac0
    /* 1ADE44 002ADE44 00000000 */   nop
    /* 1ADE48 002ADE48 04002282 */  lb         $2, 0x4($17)
    /* 1ADE4C 002ADE4C 0800412C */  sltiu      $1, $2, 0x8
    /* 1ADE50 002ADE50 A3012010 */  beqz       $1, .L002AE4E0
    /* 1ADE54 002ADE54 00000000 */   nop
    /* 1ADE58 002ADE58 7500033C */  lui        $3, %hi(jtbl_00748800)
    /* 1ADE5C 002ADE5C 00886324 */  addiu      $3, $3, %lo(jtbl_00748800)
    /* 1ADE60 002ADE60 80100200 */  sll        $2, $2, 2
    /* 1ADE64 002ADE64 21104300 */  addu       $2, $2, $3
    /* 1ADE68 002ADE68 0000428C */  lw         $2, 0x0($2)
    /* 1ADE6C 002ADE6C 08004000 */  jr         $2
    /* 1ADE70 002ADE70 00000000 */   nop
    /* 1ADE74 002ADE74 2D20A002 */  daddu      $4, $21, $0
    /* 1ADE78 002ADE78 A4C80A0C */  jal        func_002b2290
    /* 1ADE7C 002ADE7C 00000000 */   nop
    /* 1ADE80 002ADE80 04002282 */  lb         $2, 0x4($17)
    /* 1ADE84 002ADE84 01004224 */  addiu      $2, $2, 0x1
    /* 1ADE88 002ADE88 040022A2 */  sb         $2, 0x4($17)
    /* 1ADE8C 002ADE8C 94010010 */  b          .L002AE4E0
    /* 1ADE90 002ADE90 00000000 */   nop
    /* 1ADE94 002ADE94 66072486 */  lh         $4, 0x766($17)
    /* 1ADE98 002ADE98 01000524 */  addiu      $5, $0, 0x1
    /* 1ADE9C 002ADE9C 05000624 */  addiu      $6, $0, 0x5
    /* 1ADEA0 002ADEA0 2D380000 */  daddu      $7, $0, $0
    /* 1ADEA4 002ADEA4 2D40A000 */  daddu      $8, $5, $0
    /* 1ADEA8 002ADEA8 2CCB0A0C */  jal        func_002b2cb0
    /* 1ADEAC 002ADEAC 00000000 */   nop
    /* 1ADEB0 002ADEB0 660722A6 */  sh         $2, 0x766($17)
    /* 1ADEB4 002ADEB4 4807248E */  lw         $4, 0x748($17)
    /* 1ADEB8 002ADEB8 14DA0A0C */  jal        func_002b6850
    /* 1ADEBC 002ADEBC 00000000 */   nop
    /* 1ADEC0 002ADEC0 3C160200 */  dsll32     $2, $2, 24
    /* 1ADEC4 002ADEC4 3F160200 */  dsra32     $2, $2, 24
    /* 1ADEC8 002ADEC8 06004014 */  bnez       $2, .L002ADEE4
    /* 1ADECC 002ADECC 00000000 */   nop
    /* 1ADED0 002ADED0 4807248E */  lw         $4, 0x748($17)
    /* 1ADED4 002ADED4 2D280000 */  daddu      $5, $0, $0
    /* 1ADED8 002ADED8 01000624 */  addiu      $6, $0, 0x1
    /* 1ADEDC 002ADEDC E8D90A0C */  jal        func_002b67a0
    /* 1ADEE0 002ADEE0 00000000 */   nop
  .L002ADEE4:
    /* 1ADEE4 002ADEE4 4C07248E */  lw         $4, 0x74C($17)
    /* 1ADEE8 002ADEE8 14DA0A0C */  jal        func_002b6850
    /* 1ADEEC 002ADEEC 00000000 */   nop
    /* 1ADEF0 002ADEF0 3C160200 */  dsll32     $2, $2, 24
    /* 1ADEF4 002ADEF4 3F160200 */  dsra32     $2, $2, 24
    /* 1ADEF8 002ADEF8 06004014 */  bnez       $2, .L002ADF14
    /* 1ADEFC 002ADEFC 00000000 */   nop
    /* 1ADF00 002ADF00 4C07248E */  lw         $4, 0x74C($17)
    /* 1ADF04 002ADF04 2D280000 */  daddu      $5, $0, $0
    /* 1ADF08 002ADF08 01000624 */  addiu      $6, $0, 0x1
    /* 1ADF0C 002ADF0C E8D90A0C */  jal        func_002b67a0
    /* 1ADF10 002ADF10 00000000 */   nop
  .L002ADF14:
    /* 1ADF14 002ADF14 64072486 */  lh         $4, 0x764($17)
    /* 1ADF18 002ADF18 01000524 */  addiu      $5, $0, 0x1
    /* 1ADF1C 002ADF1C 0A000624 */  addiu      $6, $0, 0xA
    /* 1ADF20 002ADF20 2D380000 */  daddu      $7, $0, $0
    /* 1ADF24 002ADF24 2D40A000 */  daddu      $8, $5, $0
    /* 1ADF28 002ADF28 2CCB0A0C */  jal        func_002b2cb0
    /* 1ADF2C 002ADF2C 00000000 */   nop
    /* 1ADF30 002ADF30 640722A6 */  sh         $2, 0x764($17)
    /* 1ADF34 002ADF34 B80020A2 */  sb         $0, 0xB8($17)
    /* 1ADF38 002ADF38 2D800000 */  daddu      $16, $0, $0
    /* 1ADF3C 002ADF3C 1F000010 */  b          .L002ADFBC
    /* 1ADF40 002ADF40 00000000 */   nop
  .L002ADF44:
    /* 1ADF44 002ADF44 2D200000 */  daddu      $4, $0, $0
    /* 1ADF48 002ADF48 50070224 */  addiu      $2, $0, 0x750
    /* 1ADF4C 002ADF4C 18180202 */  mult       $3, $16, $2
    /* 1ADF50 002ADF50 7F00023C */  lui        $2, %hi(D_007E8C00)
    /* 1ADF54 002ADF54 008C4224 */  addiu      $2, $2, %lo(D_007E8C00)
    /* 1ADF58 002ADF58 21184300 */  addu       $3, $2, $3
    /* 1ADF5C 002ADF5C 4800628C */  lw         $2, 0x48($3)
    /* 1ADF60 002ADF60 05004010 */  beqz       $2, .L002ADF78
    /* 1ADF64 002ADF64 00000000 */   nop
    /* 1ADF68 002ADF68 5400628C */  lw         $2, 0x54($3)
    /* 1ADF6C 002ADF6C 02004010 */  beqz       $2, .L002ADF78
    /* 1ADF70 002ADF70 00000000 */   nop
    /* 1ADF74 002ADF74 01000424 */  addiu      $4, $0, 0x1
  .L002ADF78:
    /* 1ADF78 002ADF78 2B180400 */  sltu       $3, $0, $4
    /* 1ADF7C 002ADF7C 01000224 */  addiu      $2, $0, 0x1
    /* 1ADF80 002ADF80 0D006214 */  bne        $3, $2, .L002ADFB8
    /* 1ADF84 002ADF84 00000000 */   nop
    /* 1ADF88 002ADF88 80101000 */  sll        $2, $16, 2
    /* 1ADF8C 002ADF8C 21102202 */  addu       $2, $17, $2
    /* 1ADF90 002ADF90 D8005224 */  addiu      $18, $2, 0xD8
    /* 1ADF94 002ADF94 D800428C */  lw         $2, 0xD8($2)
    /* 1ADF98 002ADF98 07004014 */  bnez       $2, .L002ADFB8
    /* 1ADF9C 002ADF9C 00000000 */   nop
    /* 1ADFA0 002ADFA0 3C2E1000 */  dsll32     $5, $16, 24
    /* 1ADFA4 002ADFA4 3F2E0500 */  dsra32     $5, $5, 24
    /* 1ADFA8 002ADFA8 2D20A002 */  daddu      $4, $21, $0
    /* 1ADFAC 002ADFAC 84D20A0C */  jal        func_002b4a10
    /* 1ADFB0 002ADFB0 00000000 */   nop
    /* 1ADFB4 002ADFB4 000042AE */  sw         $2, 0x0($18)
  .L002ADFB8:
    /* 1ADFB8 002ADFB8 01001026 */  addiu      $16, $16, 0x1
  .L002ADFBC:
    /* 1ADFBC 002ADFBC 0F00022A */  slti       $2, $16, 0xF
    /* 1ADFC0 002ADFC0 E0FF4014 */  bnez       $2, .L002ADF44
    /* 1ADFC4 002ADFC4 00000000 */   nop
    /* 1ADFC8 002ADFC8 C800A427 */  addiu      $4, $29, 0xC8
    /* 1ADFCC 002ADFCC 70C40A0C */  jal        func_002b11c0
    /* 1ADFD0 002ADFD0 00000000 */   nop
    /* 1ADFD4 002ADFD4 FF005230 */  andi       $18, $2, 0xFF
    /* 1ADFD8 002ADFD8 C800A427 */  addiu      $4, $29, 0xC8
    /* 1ADFDC 002ADFDC 84C40A0C */  jal        func_002b1210
    /* 1ADFE0 002ADFE0 00000000 */   nop
    /* 1ADFE4 002ADFE4 FF005430 */  andi       $20, $2, 0xFF
    /* 1ADFE8 002ADFE8 2D204002 */  daddu      $4, $18, $0
    /* 1ADFEC 002ADFEC 2D288002 */  daddu      $5, $20, $0
    /* 1ADFF0 002ADFF0 D4B10A0C */  jal        func_002ac750
    /* 1ADFF4 002ADFF4 00000000 */   nop
    /* 1ADFF8 002ADFF8 FF008232 */  andi       $2, $20, 0xFF
    /* 1ADFFC 002ADFFC 00820200 */  sll        $16, $2, 8
    /* 1AE000 002AE000 FF005332 */  andi       $19, $18, 0xFF
    /* 1AE004 002AE004 00B91300 */  sll        $23, $19, 4
    /* 1AE008 002AE008 A054050C */  jal        func_00155280
    /* 1AE00C 002AE00C 00000000 */   nop
    /* 1AE010 002AE010 21105000 */  addu       $2, $2, $16
    /* 1AE014 002AE014 21105700 */  addu       $2, $2, $23
    /* 1AE018 002AE018 64004390 */  lbu        $3, 0x64($2)
    /* 1AE01C 002AE01C 01000224 */  addiu      $2, $0, 0x1
    /* 1AE020 002AE020 26006214 */  bne        $3, $2, .L002AE0BC
    /* 1AE024 002AE024 00000000 */   nop
    /* 1AE028 002AE028 2DB0E002 */  daddu      $22, $23, $0
    /* 1AE02C 002AE02C A054050C */  jal        func_00155280
    /* 1AE030 002AE030 00000000 */   nop
    /* 1AE034 002AE034 21105000 */  addu       $2, $2, $16
    /* 1AE038 002AE038 21105600 */  addu       $2, $2, $22
    /* 1AE03C 002AE03C 5E004290 */  lbu        $2, 0x5E($2)
    /* 1AE040 002AE040 08004230 */  andi       $2, $2, 0x8
    /* 1AE044 002AE044 1D004010 */  beqz       $2, .L002AE0BC
    /* 1AE048 002AE048 00000000 */   nop
    /* 1AE04C 002AE04C A054050C */  jal        func_00155280
    /* 1AE050 002AE050 00000000 */   nop
    /* 1AE054 002AE054 21105000 */  addu       $2, $2, $16
    /* 1AE058 002AE058 21105600 */  addu       $2, $2, $22
    /* 1AE05C 002AE05C 5F004290 */  lbu        $2, 0x5F($2)
    /* 1AE060 002AE060 08004230 */  andi       $2, $2, 0x8
    /* 1AE064 002AE064 10004010 */  beqz       $2, .L002AE0A8
    /* 1AE068 002AE068 00000000 */   nop
    /* 1AE06C 002AE06C A054050C */  jal        func_00155280
    /* 1AE070 002AE070 00000000 */   nop
    /* 1AE074 002AE074 21105000 */  addu       $2, $2, $16
    /* 1AE078 002AE078 21105600 */  addu       $2, $2, $22
    /* 1AE07C 002AE07C 5F004290 */  lbu        $2, 0x5F($2)
    /* 1AE080 002AE080 80004230 */  andi       $2, $2, 0x80
    /* 1AE084 002AE084 0D004010 */  beqz       $2, .L002AE0BC
    /* 1AE088 002AE088 00000000 */   nop
    /* 1AE08C 002AE08C 01006226 */  addiu      $2, $19, 0x1
    /* 1AE090 002AE090 FF004430 */  andi       $4, $2, 0xFF
    /* 1AE094 002AE094 2D288002 */  daddu      $5, $20, $0
    /* 1AE098 002AE098 D4B10A0C */  jal        func_002ac750
    /* 1AE09C 002AE09C 00000000 */   nop
    /* 1AE0A0 002AE0A0 06000010 */  b          .L002AE0BC
    /* 1AE0A4 002AE0A4 00000000 */   nop
  .L002AE0A8:
    /* 1AE0A8 002AE0A8 01006226 */  addiu      $2, $19, 0x1
    /* 1AE0AC 002AE0AC FF004430 */  andi       $4, $2, 0xFF
    /* 1AE0B0 002AE0B0 2D288002 */  daddu      $5, $20, $0
    /* 1AE0B4 002AE0B4 D4B10A0C */  jal        func_002ac750
    /* 1AE0B8 002AE0B8 00000000 */   nop
  .L002AE0BC:
    /* 1AE0BC 002AE0BC A054050C */  jal        func_00155280
    /* 1AE0C0 002AE0C0 00000000 */   nop
    /* 1AE0C4 002AE0C4 21105000 */  addu       $2, $2, $16
    /* 1AE0C8 002AE0C8 21105700 */  addu       $2, $2, $23
    /* 1AE0CC 002AE0CC 44004390 */  lbu        $3, 0x44($2)
    /* 1AE0D0 002AE0D0 01000224 */  addiu      $2, $0, 0x1
    /* 1AE0D4 002AE0D4 27006214 */  bne        $3, $2, .L002AE174
    /* 1AE0D8 002AE0D8 00000000 */   nop
    /* 1AE0DC 002AE0DC FF004232 */  andi       $2, $18, 0xFF
    /* 1AE0E0 002AE0E0 00B10200 */  sll        $22, $2, 4
    /* 1AE0E4 002AE0E4 A054050C */  jal        func_00155280
    /* 1AE0E8 002AE0E8 00000000 */   nop
    /* 1AE0EC 002AE0EC 21105000 */  addu       $2, $2, $16
    /* 1AE0F0 002AE0F0 21105600 */  addu       $2, $2, $22
    /* 1AE0F4 002AE0F4 5E004290 */  lbu        $2, 0x5E($2)
    /* 1AE0F8 002AE0F8 02004230 */  andi       $2, $2, 0x2
    /* 1AE0FC 002AE0FC 1D004010 */  beqz       $2, .L002AE174
    /* 1AE100 002AE100 00000000 */   nop
    /* 1AE104 002AE104 A054050C */  jal        func_00155280
    /* 1AE108 002AE108 00000000 */   nop
    /* 1AE10C 002AE10C 21105000 */  addu       $2, $2, $16
    /* 1AE110 002AE110 21105600 */  addu       $2, $2, $22
    /* 1AE114 002AE114 5F004290 */  lbu        $2, 0x5F($2)
    /* 1AE118 002AE118 02004230 */  andi       $2, $2, 0x2
    /* 1AE11C 002AE11C 10004010 */  beqz       $2, .L002AE160
    /* 1AE120 002AE120 00000000 */   nop
    /* 1AE124 002AE124 A054050C */  jal        func_00155280
    /* 1AE128 002AE128 00000000 */   nop
    /* 1AE12C 002AE12C 21105000 */  addu       $2, $2, $16
    /* 1AE130 002AE130 21105600 */  addu       $2, $2, $22
    /* 1AE134 002AE134 5F004290 */  lbu        $2, 0x5F($2)
    /* 1AE138 002AE138 20004230 */  andi       $2, $2, 0x20
    /* 1AE13C 002AE13C 0D004010 */  beqz       $2, .L002AE174
    /* 1AE140 002AE140 00000000 */   nop
    /* 1AE144 002AE144 FFFF6226 */  addiu      $2, $19, -0x1
    /* 1AE148 002AE148 FF004430 */  andi       $4, $2, 0xFF
    /* 1AE14C 002AE14C 2D288002 */  daddu      $5, $20, $0
    /* 1AE150 002AE150 D4B10A0C */  jal        func_002ac750
    /* 1AE154 002AE154 00000000 */   nop
    /* 1AE158 002AE158 06000010 */  b          .L002AE174
    /* 1AE15C 002AE15C 00000000 */   nop
  .L002AE160:
    /* 1AE160 002AE160 FFFF6226 */  addiu      $2, $19, -0x1
    /* 1AE164 002AE164 FF004430 */  andi       $4, $2, 0xFF
    /* 1AE168 002AE168 2D288002 */  daddu      $5, $20, $0
    /* 1AE16C 002AE16C D4B10A0C */  jal        func_002ac750
    /* 1AE170 002AE170 00000000 */   nop
  .L002AE174:
    /* 1AE174 002AE174 FF009432 */  andi       $20, $20, 0xFF
    /* 1AE178 002AE178 00B21400 */  sll        $22, $20, 8
    /* 1AE17C 002AE17C FF004232 */  andi       $2, $18, 0xFF
    /* 1AE180 002AE180 00990200 */  sll        $19, $2, 4
    /* 1AE184 002AE184 A054050C */  jal        func_00155280
    /* 1AE188 002AE188 00000000 */   nop
    /* 1AE18C 002AE18C 21105600 */  addu       $2, $2, $22
    /* 1AE190 002AE190 21105300 */  addu       $2, $2, $19
    /* 1AE194 002AE194 54FF4390 */  lbu        $3, -0xAC($2)
    /* 1AE198 002AE198 01000224 */  addiu      $2, $0, 0x1
    /* 1AE19C 002AE19C 25006214 */  bne        $3, $2, .L002AE234
    /* 1AE1A0 002AE1A0 00000000 */   nop
    /* 1AE1A4 002AE1A4 A054050C */  jal        func_00155280
    /* 1AE1A8 002AE1A8 00000000 */   nop
    /* 1AE1AC 002AE1AC 21105000 */  addu       $2, $2, $16
    /* 1AE1B0 002AE1B0 21105300 */  addu       $2, $2, $19
    /* 1AE1B4 002AE1B4 5E004290 */  lbu        $2, 0x5E($2)
    /* 1AE1B8 002AE1B8 01004230 */  andi       $2, $2, 0x1
    /* 1AE1BC 002AE1BC 1D004010 */  beqz       $2, .L002AE234
    /* 1AE1C0 002AE1C0 00000000 */   nop
    /* 1AE1C4 002AE1C4 A054050C */  jal        func_00155280
    /* 1AE1C8 002AE1C8 00000000 */   nop
    /* 1AE1CC 002AE1CC 21105000 */  addu       $2, $2, $16
    /* 1AE1D0 002AE1D0 21105300 */  addu       $2, $2, $19
    /* 1AE1D4 002AE1D4 5F004290 */  lbu        $2, 0x5F($2)
    /* 1AE1D8 002AE1D8 01004230 */  andi       $2, $2, 0x1
    /* 1AE1DC 002AE1DC 10004010 */  beqz       $2, .L002AE220
    /* 1AE1E0 002AE1E0 00000000 */   nop
    /* 1AE1E4 002AE1E4 A054050C */  jal        func_00155280
    /* 1AE1E8 002AE1E8 00000000 */   nop
    /* 1AE1EC 002AE1EC 21105000 */  addu       $2, $2, $16
    /* 1AE1F0 002AE1F0 21105300 */  addu       $2, $2, $19
    /* 1AE1F4 002AE1F4 5F004290 */  lbu        $2, 0x5F($2)
    /* 1AE1F8 002AE1F8 10004230 */  andi       $2, $2, 0x10
    /* 1AE1FC 002AE1FC 0D004010 */  beqz       $2, .L002AE234
    /* 1AE200 002AE200 00000000 */   nop
    /* 1AE204 002AE204 FFFF8226 */  addiu      $2, $20, -0x1
    /* 1AE208 002AE208 FF004530 */  andi       $5, $2, 0xFF
    /* 1AE20C 002AE20C 2D204002 */  daddu      $4, $18, $0
    /* 1AE210 002AE210 D4B10A0C */  jal        func_002ac750
    /* 1AE214 002AE214 00000000 */   nop
    /* 1AE218 002AE218 06000010 */  b          .L002AE234
    /* 1AE21C 002AE21C 00000000 */   nop
  .L002AE220:
    /* 1AE220 002AE220 FFFF8226 */  addiu      $2, $20, -0x1
    /* 1AE224 002AE224 FF004530 */  andi       $5, $2, 0xFF
    /* 1AE228 002AE228 2D204002 */  daddu      $4, $18, $0
    /* 1AE22C 002AE22C D4B10A0C */  jal        func_002ac750
    /* 1AE230 002AE230 00000000 */   nop
  .L002AE234:
    /* 1AE234 002AE234 A054050C */  jal        func_00155280
    /* 1AE238 002AE238 00000000 */   nop
    /* 1AE23C 002AE23C 21105600 */  addu       $2, $2, $22
    /* 1AE240 002AE240 21105300 */  addu       $2, $2, $19
    /* 1AE244 002AE244 54014390 */  lbu        $3, 0x154($2)
    /* 1AE248 002AE248 01000224 */  addiu      $2, $0, 0x1
    /* 1AE24C 002AE24C 25006214 */  bne        $3, $2, .L002AE2E4
    /* 1AE250 002AE250 00000000 */   nop
    /* 1AE254 002AE254 A054050C */  jal        func_00155280
    /* 1AE258 002AE258 00000000 */   nop
    /* 1AE25C 002AE25C 21105000 */  addu       $2, $2, $16
    /* 1AE260 002AE260 21105300 */  addu       $2, $2, $19
    /* 1AE264 002AE264 5E004290 */  lbu        $2, 0x5E($2)
    /* 1AE268 002AE268 04004230 */  andi       $2, $2, 0x4
    /* 1AE26C 002AE26C 1D004010 */  beqz       $2, .L002AE2E4
    /* 1AE270 002AE270 00000000 */   nop
    /* 1AE274 002AE274 A054050C */  jal        func_00155280
    /* 1AE278 002AE278 00000000 */   nop
    /* 1AE27C 002AE27C 21105000 */  addu       $2, $2, $16
    /* 1AE280 002AE280 21105300 */  addu       $2, $2, $19
    /* 1AE284 002AE284 5F004290 */  lbu        $2, 0x5F($2)
    /* 1AE288 002AE288 04004230 */  andi       $2, $2, 0x4
    /* 1AE28C 002AE28C 10004010 */  beqz       $2, .L002AE2D0
    /* 1AE290 002AE290 00000000 */   nop
    /* 1AE294 002AE294 A054050C */  jal        func_00155280
    /* 1AE298 002AE298 00000000 */   nop
    /* 1AE29C 002AE29C 21105000 */  addu       $2, $2, $16
    /* 1AE2A0 002AE2A0 21105300 */  addu       $2, $2, $19
    /* 1AE2A4 002AE2A4 5F004290 */  lbu        $2, 0x5F($2)
    /* 1AE2A8 002AE2A8 40004230 */  andi       $2, $2, 0x40
    /* 1AE2AC 002AE2AC 0D004010 */  beqz       $2, .L002AE2E4
    /* 1AE2B0 002AE2B0 00000000 */   nop
    /* 1AE2B4 002AE2B4 01008226 */  addiu      $2, $20, 0x1
    /* 1AE2B8 002AE2B8 FF004530 */  andi       $5, $2, 0xFF
    /* 1AE2BC 002AE2BC 2D204002 */  daddu      $4, $18, $0
    /* 1AE2C0 002AE2C0 D4B10A0C */  jal        func_002ac750
    /* 1AE2C4 002AE2C4 00000000 */   nop
    /* 1AE2C8 002AE2C8 06000010 */  b          .L002AE2E4
    /* 1AE2CC 002AE2CC 00000000 */   nop
  .L002AE2D0:
    /* 1AE2D0 002AE2D0 01008226 */  addiu      $2, $20, 0x1
    /* 1AE2D4 002AE2D4 FF004530 */  andi       $5, $2, 0xFF
    /* 1AE2D8 002AE2D8 2D204002 */  daddu      $4, $18, $0
    /* 1AE2DC 002AE2DC D4B10A0C */  jal        func_002ac750
    /* 1AE2E0 002AE2E0 00000000 */   nop
  .L002AE2E4:
    /* 1AE2E4 002AE2E4 A800A427 */  addiu      $4, $29, 0xA8
    /* 1AE2E8 002AE2E8 08002526 */  addiu      $5, $17, 0x8
    /* 1AE2EC 002AE2EC C800A627 */  addiu      $6, $29, 0xC8
    /* 1AE2F0 002AE2F0 68CC0A0C */  jal        func_002b31a0
    /* 1AE2F4 002AE2F4 00000000 */   nop
    /* 1AE2F8 002AE2F8 A800A1C7 */  lwc1       $f1, 0xA8($29)
    /* 1AE2FC 002AE2FC F88480C7 */  lwc1       $f0, -0x7B08($28)
    /* 1AE300 002AE300 03080046 */  div.s      $f0, $f1, $f0
    /* 1AE304 002AE304 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1AE308 002AE308 20008046 */  cvt.s.w    $f0, $f0
    /* 1AE30C 002AE30C D800A0E7 */  swc1       $f0, 0xD8($29)
    /* 1AE310 002AE310 9800A427 */  addiu      $4, $29, 0x98
    /* 1AE314 002AE314 08002526 */  addiu      $5, $17, 0x8
    /* 1AE318 002AE318 C800A627 */  addiu      $6, $29, 0xC8
    /* 1AE31C 002AE31C 68CC0A0C */  jal        func_002b31a0
    /* 1AE320 002AE320 00000000 */   nop
    /* 1AE324 002AE324 A000A1C7 */  lwc1       $f1, 0xA0($29)
    /* 1AE328 002AE328 F88480C7 */  lwc1       $f0, -0x7B08($28)
    /* 1AE32C 002AE32C 03080046 */  div.s      $f0, $f1, $f0
    /* 1AE330 002AE330 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1AE334 002AE334 20008046 */  cvt.s.w    $f0, $f0
    /* 1AE338 002AE338 DC00A0E7 */  swc1       $f0, 0xDC($29)
    /* 1AE33C 002AE33C 2D900000 */  daddu      $18, $0, $0
    /* 1AE340 002AE340 47000010 */  b          .L002AE460
    /* 1AE344 002AE344 00000000 */   nop
  .L002AE348:
    /* 1AE348 002AE348 2D980000 */  daddu      $19, $0, $0
    /* 1AE34C 002AE34C 40000010 */  b          .L002AE450
    /* 1AE350 002AE350 00000000 */   nop
  .L002AE354:
    /* 1AE354 002AE354 7F00023C */  lui        $2, %hi(D_007EFA04)
    /* 1AE358 002AE358 04FA428C */  lw         $2, %lo(D_007EFA04)($2)
    /* 1AE35C 002AE35C 2002448C */  lw         $4, 0x220($2)
    /* 1AE360 002AE360 F4A1050C */  jal        func_001687d0
    /* 1AE364 002AE364 00000000 */   nop
    /* 1AE368 002AE368 FAFF4224 */  addiu      $2, $2, -0x6
    /* 1AE36C 002AE36C 21104202 */  addu       $2, $18, $2
    /* 1AE370 002AE370 3CA40200 */  dsll32     $20, $2, 16
    /* 1AE374 002AE374 3FA41400 */  dsra32     $20, $20, 16
    /* 1AE378 002AE378 7F00023C */  lui        $2, %hi(D_007EFA04)
    /* 1AE37C 002AE37C 04FA428C */  lw         $2, %lo(D_007EFA04)($2)
    /* 1AE380 002AE380 2002448C */  lw         $4, 0x220($2)
    /* 1AE384 002AE384 F8A1050C */  jal        func_001687e0
    /* 1AE388 002AE388 00000000 */   nop
    /* 1AE38C 002AE38C FAFF4224 */  addiu      $2, $2, -0x6
    /* 1AE390 002AE390 21106202 */  addu       $2, $19, $2
    /* 1AE394 002AE394 3C140200 */  dsll32     $2, $2, 16
    /* 1AE398 002AE398 3F140200 */  dsra32     $2, $2, 16
    /* 1AE39C 002AE39C 3C241400 */  dsll32     $4, $20, 16
    /* 1AE3A0 002AE3A0 3F240400 */  dsra32     $4, $4, 16
    /* 1AE3A4 002AE3A4 29008018 */  blez       $4, .L002AE44C
    /* 1AE3A8 002AE3A8 00000000 */   nop
    /* 1AE3AC 002AE3AC 3C840200 */  dsll32     $16, $2, 16
    /* 1AE3B0 002AE3B0 3F841000 */  dsra32     $16, $16, 16
    /* 1AE3B4 002AE3B4 2500001A */  blez       $16, .L002AE44C
    /* 1AE3B8 002AE3B8 00000000 */   nop
    /* 1AE3BC 002AE3BC 10008128 */  slti       $1, $4, 0x10
    /* 1AE3C0 002AE3C0 22002010 */  beqz       $1, .L002AE44C
    /* 1AE3C4 002AE3C4 00000000 */   nop
    /* 1AE3C8 002AE3C8 1800012A */  slti       $1, $16, 0x18
    /* 1AE3CC 002AE3CC 1F002010 */  beqz       $1, .L002AE44C
    /* 1AE3D0 002AE3D0 00000000 */   nop
    /* 1AE3D4 002AE3D4 80111000 */  sll        $2, $16, 6
    /* 1AE3D8 002AE3D8 21182202 */  addu       $3, $17, $2
    /* 1AE3DC 002AE3DC 80100400 */  sll        $2, $4, 2
    /* 1AE3E0 002AE3E0 21106200 */  addu       $2, $3, $2
    /* 1AE3E4 002AE3E4 48015624 */  addiu      $22, $2, 0x148
    /* 1AE3E8 002AE3E8 4801448C */  lw         $4, 0x148($2)
    /* 1AE3EC 002AE3EC 2449110C */  jal        func_00452490
    /* 1AE3F0 002AE3F0 00000000 */   nop
    /* 1AE3F4 002AE3F4 01000524 */  addiu      $5, $0, 0x1
    /* 1AE3F8 002AE3F8 14004514 */  bne        $2, $5, .L002AE44C
    /* 1AE3FC 002AE3FC 00000000 */   nop
    /* 1AE400 002AE400 3C341400 */  dsll32     $6, $20, 16
    /* 1AE404 002AE404 3F340600 */  dsra32     $6, $6, 16
    /* 1AE408 002AE408 0410C500 */  sllv       $2, $5, $6
    /* 1AE40C 002AE40C FFFF4430 */  andi       $4, $2, 0xFFFF
    /* 1AE410 002AE410 40181000 */  sll        $3, $16, 1
    /* 1AE414 002AE414 68B5828F */  lw         $2, -0x4A98($28)
    /* 1AE418 002AE418 21104300 */  addu       $2, $2, $3
    /* 1AE41C 002AE41C 00004294 */  lhu        $2, 0x0($2)
    /* 1AE420 002AE420 24108200 */  and        $2, $4, $2
    /* 1AE424 002AE424 0710C200 */  srav       $2, $2, $6
    /* 1AE428 002AE428 04004514 */  bne        $2, $5, .L002AE43C
    /* 1AE42C 002AE42C 00000000 */   nop
    /* 1AE430 002AE430 0000C48E */  lw         $4, 0x0($22)
    /* 1AE434 002AE434 38C40A0C */  jal        func_002b10e0
    /* 1AE438 002AE438 00000000 */   nop
  .L002AE43C:
    /* 1AE43C 002AE43C 0000C48E */  lw         $4, 0x0($22)
    /* 1AE440 002AE440 D800A5DF */  ld         $5, 0xD8($29)
    /* 1AE444 002AE444 28C40A0C */  jal        func_002b10a0
    /* 1AE448 002AE448 00000000 */   nop
  .L002AE44C:
    /* 1AE44C 002AE44C 01007326 */  addiu      $19, $19, 0x1
  .L002AE450:
    /* 1AE450 002AE450 0D00622A */  slti       $2, $19, 0xD
    /* 1AE454 002AE454 BFFF4014 */  bnez       $2, .L002AE354
    /* 1AE458 002AE458 00000000 */   nop
    /* 1AE45C 002AE45C 01005226 */  addiu      $18, $18, 0x1
  .L002AE460:
    /* 1AE460 002AE460 0D00422A */  slti       $2, $18, 0xD
    /* 1AE464 002AE464 B8FF4014 */  bnez       $2, .L002AE348
    /* 1AE468 002AE468 00000000 */   nop
    /* 1AE46C 002AE46C 2D20A002 */  daddu      $4, $21, $0
    /* 1AE470 002AE470 90C80A0C */  jal        func_002b2240
    /* 1AE474 002AE474 00000000 */   nop
    /* 1AE478 002AE478 19000010 */  b          .L002AE4E0
    /* 1AE47C 002AE47C 00000000 */   nop
    /* 1AE480 002AE480 66072486 */  lh         $4, 0x766($17)
    /* 1AE484 002AE484 01000524 */  addiu      $5, $0, 0x1
    /* 1AE488 002AE488 05000624 */  addiu      $6, $0, 0x5
    /* 1AE48C 002AE48C 2D380000 */  daddu      $7, $0, $0
    /* 1AE490 002AE490 2D40A000 */  daddu      $8, $5, $0
    /* 1AE494 002AE494 2CCB0A0C */  jal        func_002b2cb0
    /* 1AE498 002AE498 00000000 */   nop
    /* 1AE49C 002AE49C 660722A6 */  sh         $2, 0x766($17)
    /* 1AE4A0 002AE4A0 64072486 */  lh         $4, 0x764($17)
    /* 1AE4A4 002AE4A4 01000524 */  addiu      $5, $0, 0x1
    /* 1AE4A8 002AE4A8 05000624 */  addiu      $6, $0, 0x5
    /* 1AE4AC 002AE4AC 2D380000 */  daddu      $7, $0, $0
    /* 1AE4B0 002AE4B0 2D40A000 */  daddu      $8, $5, $0
    /* 1AE4B4 002AE4B4 2CCB0A0C */  jal        func_002b2cb0
    /* 1AE4B8 002AE4B8 00000000 */   nop
    /* 1AE4BC 002AE4BC 640722A6 */  sh         $2, 0x764($17)
    /* 1AE4C0 002AE4C0 2D20A002 */  daddu      $4, $21, $0
    /* 1AE4C4 002AE4C4 90C80A0C */  jal        func_002b2240
    /* 1AE4C8 002AE4C8 00000000 */   nop
    /* 1AE4CC 002AE4CC 04000010 */  b          .L002AE4E0
    /* 1AE4D0 002AE4D0 00000000 */   nop
    /* 1AE4D4 002AE4D4 FFFF0224 */  addiu      $2, $0, -0x1
    /* 1AE4D8 002AE4D8 02000010 */  b          .L002AE4E4
    /* 1AE4DC 002AE4DC 00000000 */   nop
  .L002AE4E0:
    /* 1AE4E0 002AE4E0 2D100000 */  daddu      $2, $0, $0
  .L002AE4E4:
    /* 1AE4E4 002AE4E4 8000BFDF */  ld         $31, 0x80($29)
    /* 1AE4E8 002AE4E8 7000B77B */  lq         $23, 0x70($29)
    /* 1AE4EC 002AE4EC 6000B67B */  lq         $22, 0x60($29)
    /* 1AE4F0 002AE4F0 5000B57B */  lq         $21, 0x50($29)
    /* 1AE4F4 002AE4F4 4000B47B */  lq         $20, 0x40($29)
    /* 1AE4F8 002AE4F8 3000B37B */  lq         $19, 0x30($29)
    /* 1AE4FC 002AE4FC 2000B27B */  lq         $18, 0x20($29)
    /* 1AE500 002AE500 1000B17B */  lq         $17, 0x10($29)
    /* 1AE504 002AE504 0000B07B */  lq         $16, 0x0($29)
    /* 1AE508 002AE508 E000BD27 */  addiu      $29, $29, 0xE0
    /* 1AE50C 002AE50C 0800E003 */  jr         $31
    /* 1AE510 002AE510 00000000 */   nop
    /* 1AE514 002AE514 00000000 */  nop
    /* 1AE518 002AE518 00000000 */  nop
    /* 1AE51C 002AE51C 00000000 */  nop
.size func_002add90, 0x790
