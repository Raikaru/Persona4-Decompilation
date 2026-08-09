.section .text
.set noat
.set noreorder
glabel func_0043a978
    /* 33A978 0043A978 40FFBD27 */  addiu      $29, $29, -0xC0
    /* 33A97C 0043A97C 01000324 */  addiu      $3, $0, 0x1
    /* 33A980 0043A980 A000BEFF */  sd         $30, 0xA0($29)
    /* 33A984 0043A984 B000BFFF */  sd         $31, 0xB0($29)
    /* 33A988 0043A988 71001E3C */  lui        $30, %hi(D_0070FC40)
    /* 33A98C 0043A98C 9000B7FF */  sd         $23, 0x90($29)
    /* 33A990 0043A990 8000B6FF */  sd         $22, 0x80($29)
    /* 33A994 0043A994 7000B5FF */  sd         $21, 0x70($29)
    /* 33A998 0043A998 6000B4FF */  sd         $20, 0x60($29)
    /* 33A99C 0043A99C 5000B3FF */  sd         $19, 0x50($29)
    /* 33A9A0 0043A9A0 4000B2FF */  sd         $18, 0x40($29)
    /* 33A9A4 0043A9A4 3000B1FF */  sd         $17, 0x30($29)
    /* 33A9A8 0043A9A8 2000B0FF */  sd         $16, 0x20($29)
    /* 33A9AC 0043A9AC 40FCC28F */  lw         $2, %lo(D_0070FC40)($30)
    /* 33A9B0 0043A9B0 03004314 */  bne        $2, $3, .L0043A9C0
    /* 33A9B4 0043A9B4 8C00173C */   lui       $23, %hi(D_008BE280)
    /* 33A9B8 0043A9B8 8B000010 */  b          .L0043ABE8
    /* 33A9BC 0043A9BC 01000224 */   addiu     $2, $0, 0x1
  .L0043A9C0:
    /* 33A9C0 0043A9C0 2D200000 */  daddu      $4, $0, $0
    /* 33A9C4 0043A9C4 CA93100C */  jal        func_00424f28
    /* 33A9C8 0043A9C8 80E2E0AE */   sw        $0, %lo(D_008BE280)($23)
    /* 33A9CC 0043A9CC 0B000010 */  b          .L0043A9FC
    /* 33A9D0 0043A9D0 8C00113C */   lui       $17, %hi(D_008BD9C0)
    /* 33A9D4 0043A9D4 00000000 */  nop
  .L0043A9D8:
    /* 33A9D8 0043A9D8 FFFF0224 */  addiu      $2, $0, -0x1
    /* 33A9DC 0043A9DC 00000000 */  nop
  .L0043A9E0:
    /* 33A9E0 0043A9E0 FFFF6324 */  addiu      $3, $3, %lo(D_FFFF)
    /* 33A9E4 0043A9E4 00000000 */  nop
    /* 33A9E8 0043A9E8 00000000 */  nop
    /* 33A9EC 0043A9EC 00000000 */  nop
    /* 33A9F0 0043A9F0 00000000 */  nop
    /* 33A9F4 0043A9F4 FAFF6214 */  bne        $3, $2, .L0043A9E0
    /* 33A9F8 0043A9F8 00000000 */   nop
  .L0043A9FC:
    /* 33A9FC 0043A9FC C0D93026 */  addiu      $16, $17, %lo(D_008BD9C0)
    /* 33AA00 0043AA00 0080053C */  lui        $5, (0x80001300 >> 16)
    /* 33AA04 0043AA04 2D200002 */  daddu      $4, $16, $0
    /* 33AA08 0043AA08 0013A534 */  ori        $5, $5, (0x80001300 & 0xFFFF)
    /* 33AA0C 0043AA0C B495100C */  jal        func_004256d0
    /* 33AA10 0043AA10 2D300000 */   daddu     $6, $0, $0
    /* 33AA14 0043AA14 5A004004 */  bltz       $2, .L0043AB80
    /* 33AA18 0043AA18 7500043C */   lui       $4, %hi(D_00754A60)
    /* 33AA1C 0043AA1C 2400028E */  lw         $2, 0x24($16)
    /* 33AA20 0043AA20 EDFF4010 */  beqz       $2, .L0043A9D8
    /* 33AA24 0043AA24 0100033C */   lui       $3, %hi(D_FFFF)
    /* 33AA28 0043AA28 48EA100C */  jal        func_0043a920
    /* 33AA2C 0043AA2C 00000000 */   nop
    /* 33AA30 0043AA30 2D804000 */  daddu      $16, $2, $0
    /* 33AA34 0043AA34 32000324 */  addiu      $3, $0, 0x32
    /* 33AA38 0043AA38 03111000 */  sra        $2, $16, 4
    /* 33AA3C 0043AA3C 0C004310 */  beq        $2, $3, .L0043AA70
    /* 33AA40 0043AA40 7500043C */   lui       $4, %hi(D_00754A78)
    /* 33AA44 0043AA44 3291100C */  jal        func_004244c8
    /* 33AA48 0043AA48 784A8424 */   addiu     $4, $4, %lo(D_00754A78)
    /* 33AA4C 0043AA4C 7500043C */  lui        $4, %hi(D_00754AA0)
    /* 33AA50 0043AA50 FF000832 */  andi       $8, $16, 0xFF
    /* 33AA54 0043AA54 A04A8424 */  addiu      $4, $4, %lo(D_00754AA0)
    /* 33AA58 0043AA58 03000524 */  addiu      $5, $0, 0x3
    /* 33AA5C 0043AA5C 20000624 */  addiu      $6, $0, 0x20
    /* 33AA60 0043AA60 3291100C */  jal        func_004244c8
    /* 33AA64 0043AA64 033A1000 */   sra       $7, $16, 8
    /* 33AA68 0043AA68 5F000010 */  b          .L0043ABE8
    /* 33AA6C 0043AA6C 2D100000 */   daddu     $2, $0, $0
  .L0043AA70:
    /* 33AA70 0043AA70 0A000010 */  b          .L0043AA9C
    /* 33AA74 0043AA74 8C00113C */   lui       $17, %hi(D_008BDA10)
  .L0043AA78:
    /* 33AA78 0043AA78 0100033C */  lui        $3, %hi(D_FFFF)
    /* 33AA7C 0043AA7C FFFF0224 */  addiu      $2, $0, -0x1
  .L0043AA80:
    /* 33AA80 0043AA80 FFFF6324 */  addiu      $3, $3, %lo(D_FFFF)
    /* 33AA84 0043AA84 00000000 */  nop
    /* 33AA88 0043AA88 00000000 */  nop
    /* 33AA8C 0043AA8C 00000000 */  nop
    /* 33AA90 0043AA90 00000000 */  nop
    /* 33AA94 0043AA94 FAFF6214 */  bne        $3, $2, .L0043AA80
    /* 33AA98 0043AA98 00000000 */   nop
  .L0043AA9C:
    /* 33AA9C 0043AA9C 10DA3026 */  addiu      $16, $17, %lo(D_008BDA10)
    /* 33AAA0 0043AAA0 0080053C */  lui        $5, (0x8000131C >> 16)
    /* 33AAA4 0043AAA4 2D200002 */  daddu      $4, $16, $0
    /* 33AAA8 0043AAA8 1C13A534 */  ori        $5, $5, (0x8000131C & 0xFFFF)
    /* 33AAAC 0043AAAC B495100C */  jal        func_004256d0
    /* 33AAB0 0043AAB0 2D300000 */   daddu     $6, $0, $0
    /* 33AAB4 0043AAB4 32004004 */  bltz       $2, .L0043AB80
    /* 33AAB8 0043AAB8 7500043C */   lui       $4, %hi(D_00754A60)
    /* 33AABC 0043AABC 2400028E */  lw         $2, 0x24($16)
    /* 33AAC0 0043AAC0 EDFF4010 */  beqz       $2, .L0043AA78
    /* 33AAC4 0043AAC4 8C00023C */   lui       $2, %hi(D_008BDA38)
    /* 33AAC8 0043AAC8 0080133C */  lui        $19, (0x8000131E >> 16)
    /* 33AACC 0043AACC 38DA5624 */  addiu      $22, $2, %lo(D_008BDA38)
    /* 33AAD0 0043AAD0 2D900000 */  daddu      $18, $0, $0
    /* 33AAD4 0043AAD4 1E137336 */  ori        $19, $19, (0x8000131E & 0xFFFF)
    /* 33AAD8 0043AAD8 2400D526 */  addiu      $21, $22, 0x24
    /* 33AADC 0043AADC 2DA00000 */  daddu      $20, $0, $0
  .L0043AAE0:
    /* 33AAE0 0043AAE0 2D888002 */  daddu      $17, $20, $0
    /* 33AAE4 0043AAE4 0B000010 */  b          .L0043AB14
    /* 33AAE8 0043AAE8 2D80A002 */   daddu     $16, $21, $0
    /* 33AAEC 0043AAEC 00000000 */  nop
  .L0043AAF0:
    /* 33AAF0 0043AAF0 FFFF0224 */  addiu      $2, $0, -0x1
    /* 33AAF4 0043AAF4 00000000 */  nop
  .L0043AAF8:
    /* 33AAF8 0043AAF8 FFFF6324 */  addiu      $3, $3, %lo(D_FFFF)
    /* 33AAFC 0043AAFC 00000000 */  nop
    /* 33AB00 0043AB00 00000000 */  nop
    /* 33AB04 0043AB04 00000000 */  nop
    /* 33AB08 0043AB08 00000000 */  nop
    /* 33AB0C 0043AB0C FAFF6214 */  bne        $3, $2, .L0043AAF8
    /* 33AB10 0043AB10 00000000 */   nop
  .L0043AB14:
    /* 33AB14 0043AB14 21203602 */  addu       $4, $17, $22
    /* 33AB18 0043AB18 21285302 */  addu       $5, $18, $19
    /* 33AB1C 0043AB1C B495100C */  jal        func_004256d0
    /* 33AB20 0043AB20 2D300000 */   daddu     $6, $0, $0
    /* 33AB24 0043AB24 16004004 */  bltz       $2, .L0043AB80
    /* 33AB28 0043AB28 7500043C */   lui       $4, %hi(D_00754A60)
    /* 33AB2C 0043AB2C 0000028E */  lw         $2, 0x0($16)
    /* 33AB30 0043AB30 EFFF4010 */  beqz       $2, .L0043AAF0
    /* 33AB34 0043AB34 0100033C */   lui       $3, %hi(D_FFFF)
    /* 33AB38 0043AB38 01005226 */  addiu      $18, $18, 0x1
    /* 33AB3C 0043AB3C 2800B526 */  addiu      $21, $21, 0x28
    /* 33AB40 0043AB40 0200422A */  slti       $2, $18, 0x2
    /* 33AB44 0043AB44 E6FF4014 */  bnez       $2, .L0043AAE0
    /* 33AB48 0043AB48 28009426 */   addiu     $20, $20, 0x28
    /* 33AB4C 0043AB4C 7500023C */  lui        $2, %hi(D_00754AD0)
    /* 33AB50 0043AB50 01000324 */  addiu      $3, $0, 0x1
    /* 33AB54 0043AB54 D04A4224 */  addiu      $2, $2, %lo(D_00754AD0)
    /* 33AB58 0043AB58 7F000524 */  addiu      $5, $0, 0x7F
    /* 33AB5C 0043AB5C 0800A3AF */  sw         $3, 0x8($29)
    /* 33AB60 0043AB60 2D20A003 */  daddu      $4, $29, $0
    /* 33AB64 0043AB64 0400A5AF */  sw         $5, 0x4($29)
    /* 33AB68 0043AB68 F885100C */  jal        func_004217e0
    /* 33AB6C 0043AB6C 1400A2AF */   sw        $2, 0x14($29)
    /* 33AB70 0043AB70 07004104 */  bgez       $2, .L0043AB90
    /* 33AB74 0043AB74 80E2E2AE */   sw        $2, %lo(D_008BE280)($23)
    /* 33AB78 0043AB78 1B000010 */  b          .L0043ABE8
    /* 33AB7C 0043AB7C 2D100000 */   daddu     $2, $0, $0
  .L0043AB80:
    /* 33AB80 0043AB80 D2EE100C */  jal        func_0043bb48
    /* 33AB84 0043AB84 604A8424 */   addiu     $4, $4, %lo(D_00754A60)
    /* 33AB88 0043AB88 17000010 */  b          .L0043ABE8
    /* 33AB8C 0043AB8C 2D100000 */   daddu     $2, $0, $0
  .L0043AB90:
    /* 33AB90 0043AB90 8C00023C */  lui        $2, %hi(D_008BE240)
    /* 33AB94 0043AB94 0F000324 */  addiu      $3, $0, 0xF
    /* 33AB98 0043AB98 40E24224 */  addiu      $2, $2, %lo(D_008BE240)
    /* 33AB9C 0043AB9C 3C004224 */  addiu      $2, $2, 0x3C
  .L0043ABA0:
    /* 33ABA0 0043ABA0 000040AC */  sw         $0, 0x0($2)
    /* 33ABA4 0043ABA4 FFFF6324 */  addiu      $3, $3, -0x1
    /* 33ABA8 0043ABA8 FCFF4224 */  addiu      $2, $2, -0x4
    /* 33ABAC 0043ABAC 00000000 */  nop
    /* 33ABB0 0043ABB0 00000000 */  nop
    /* 33ABB4 0043ABB4 FAFF6104 */  bgez       $3, .L0043ABA0
    /* 33ABB8 0043ABB8 00000000 */   nop
    /* 33ABBC 0043ABBC 8C00103C */  lui        $16, %hi(D_008BE1C0)
    /* 33ABC0 0043ABC0 7500043C */  lui        $4, %hi(D_00754AE0)
    /* 33ABC4 0043ABC4 C0E11026 */  addiu      $16, $16, %lo(D_008BE1C0)
    /* 33ABC8 0043ABC8 E04A8424 */  addiu      $4, $4, %lo(D_00754AE0)
    /* 33ABCC 0043ABCC D2EE100C */  jal        func_0043bb48
    /* 33ABD0 0043ABD0 2D280002 */   daddu     $5, $16, $0
    /* 33ABD4 0043ABD4 30EB100C */  jal        func_0043acc0
    /* 33ABD8 0043ABD8 2D200002 */   daddu     $4, $16, $0
    /* 33ABDC 0043ABDC 01000324 */  addiu      $3, $0, 0x1
    /* 33ABE0 0043ABE0 01000224 */  addiu      $2, $0, 0x1
    /* 33ABE4 0043ABE4 40FCC3AF */  sw         $3, %lo(D_0070FC40)($30)
  .L0043ABE8:
    /* 33ABE8 0043ABE8 B000BFDF */  ld         $31, 0xB0($29)
    /* 33ABEC 0043ABEC A000BEDF */  ld         $30, 0xA0($29)
    /* 33ABF0 0043ABF0 9000B7DF */  ld         $23, 0x90($29)
    /* 33ABF4 0043ABF4 8000B6DF */  ld         $22, 0x80($29)
    /* 33ABF8 0043ABF8 7000B5DF */  ld         $21, 0x70($29)
    /* 33ABFC 0043ABFC 6000B4DF */  ld         $20, 0x60($29)
    /* 33AC00 0043AC00 5000B3DF */  ld         $19, 0x50($29)
    /* 33AC04 0043AC04 4000B2DF */  ld         $18, 0x40($29)
    /* 33AC08 0043AC08 3000B1DF */  ld         $17, 0x30($29)
    /* 33AC0C 0043AC0C 2000B0DF */  ld         $16, 0x20($29)
    /* 33AC10 0043AC10 0800E003 */  jr         $31
    /* 33AC14 0043AC14 C000BD27 */   addiu     $29, $29, 0xC0
.size func_0043a978, 0x2a0
