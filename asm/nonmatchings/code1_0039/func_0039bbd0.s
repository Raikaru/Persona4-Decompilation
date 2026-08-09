.section .text
.set noat
.set noreorder
glabel func_0039bbd0
    /* 29BBD0 0039BBD0 70FFBD27 */  addiu      $29, $29, -0x90
    /* 29BBD4 0039BBD4 7000BFFF */  sd         $31, 0x70($29)
    /* 29BBD8 0039BBD8 6000B67F */  sq         $22, 0x60($29)
    /* 29BBDC 0039BBDC 5000B57F */  sq         $21, 0x50($29)
    /* 29BBE0 0039BBE0 4000B47F */  sq         $20, 0x40($29)
    /* 29BBE4 0039BBE4 3000B37F */  sq         $19, 0x30($29)
    /* 29BBE8 0039BBE8 2DA08000 */  daddu      $20, $4, $0
    /* 29BBEC 0039BBEC 2000B27F */  sq         $18, 0x20($29)
    /* 29BBF0 0039BBF0 1000B17F */  sq         $17, 0x10($29)
    /* 29BBF4 0039BBF4 7445100C */  jal        func_004115d0
    /* 29BBF8 0039BBF8 0000B07F */   sq        $16, 0x0($29)
    /* 29BBFC 0039BBFC 0000838E */  lw         $3, 0x0($20)
    /* 29BC00 0039BC00 2DA84000 */  daddu      $21, $2, $0
    /* 29BC04 0039BC04 2D20A002 */  daddu      $4, $21, $0
    /* 29BC08 0039BC08 2C0043AC */  sw         $3, 0x2C($2)
    /* 29BC0C 0039BC0C 0400838E */  lw         $3, 0x4($20)
    /* 29BC10 0039BC10 284B100C */  jal        func_00412ca0
    /* 29BC14 0039BC14 300043AC */   sw        $3, 0x30($2)
    /* 29BC18 0039BC18 A04E0F0C */  jal        func_003d3a80
    /* 29BC1C 0039BC1C 2D804000 */   daddu     $16, $2, $0
    /* 29BC20 0039BC20 2D984000 */  daddu      $19, $2, $0
    /* 29BC24 0039BC24 2D200002 */  daddu      $4, $16, $0
    /* 29BC28 0039BC28 2D280000 */  daddu      $5, $0, $0
    /* 29BC2C 0039BC2C 2D306002 */  daddu      $6, $19, $0
    /* 29BC30 0039BC30 EC4B100C */  jal        func_00412fb0
    /* 29BC34 0039BC34 2D380000 */   daddu     $7, $0, $0
    /* 29BC38 0039BC38 0000658E */  lw         $5, 0x0($19)
    /* 29BC3C 0039BC3C 2DB04000 */  daddu      $22, $2, $0
    /* 29BC40 0039BC40 2D20C002 */  daddu      $4, $22, $0
    /* 29BC44 0039BC44 2D300000 */  daddu      $6, $0, $0
    /* 29BC48 0039BC48 A44B100C */  jal        func_00412e90
    /* 29BC4C 0039BC4C 2D380000 */   daddu     $7, $0, $0
    /* 29BC50 0039BC50 2D904000 */  daddu      $18, $2, $0
    /* 29BC54 0039BC54 2D880000 */  daddu      $17, $0, $0
    /* 29BC58 0039BC58 2D808002 */  daddu      $16, $20, $0
  .L0039BC5C:
    /* 29BC5C 0039BC5C 0A00212E */  sltiu      $1, $17, 0xA
    /* 29BC60 0039BC60 4D002010 */  beqz       $1, .L0039BD98
    /* 29BC64 0039BC64 00000000 */   nop
    /* 29BC68 0039BC68 0800058E */  lw         $5, 0x8($16)
    /* 29BC6C 0039BC6C 4A00A010 */  beqz       $5, .L0039BD98
    /* 29BC70 0039BC70 00000000 */   nop
    /* 29BC74 0039BC74 0C00068E */  lw         $6, 0xC($16)
    /* 29BC78 0039BC78 4C4C0F0C */  jal        func_003d3130
    /* 29BC7C 0039BC7C 2D204002 */   daddu     $4, $18, $0
    /* 29BC80 0039BC80 08001026 */  addiu      $16, $16, 0x8
    /* 29BC84 0039BC84 F5FF0010 */  b          .L0039BC5C
    /* 29BC88 0039BC88 01003126 */   addiu     $17, $17, 0x1
    /* 29BC8C 0039BC8C 00000000 */  nop
    /* 29BC90 0039BC90 5C00858E */  lw         $5, 0x5C($20)
    /* 29BC94 0039BC94 6000868E */  lw         $6, 0x60($20)
    /* 29BC98 0039BC98 6400878E */  lw         $7, 0x64($20)
    /* 29BC9C 0039BC9C 7C4D0F0C */  jal        func_003d35f0
    /* 29BCA0 0039BCA0 2D204002 */   daddu     $4, $18, $0
    /* 29BCA4 0039BCA4 16000010 */  b          .L0039BD00
    /* 29BCA8 0039BCA8 2D20C002 */   daddu     $4, $22, $0
    /* 29BCAC 0039BCAC 5C00858E */  lw         $5, 0x5C($20)
    /* 29BCB0 0039BCB0 6000868E */  lw         $6, 0x60($20)
    /* 29BCB4 0039BCB4 6400878E */  lw         $7, 0x64($20)
    /* 29BCB8 0039BCB8 184D0F0C */  jal        func_003d3460
    /* 29BCBC 0039BCBC 2D204002 */   daddu     $4, $18, $0
    /* 29BCC0 0039BCC0 0E000010 */  b          .L0039BCFC
    /* 29BCC4 0039BCC4 00000000 */   nop
    /* 29BCC8 0039BCC8 5C00858E */  lw         $5, 0x5C($20)
    /* 29BCCC 0039BCCC 6000868E */  lw         $6, 0x60($20)
    /* 29BCD0 0039BCD0 E04D0F0C */  jal        func_003d3780
    /* 29BCD4 0039BCD4 2D204002 */   daddu     $4, $18, $0
    /* 29BCD8 0039BCD8 08000010 */  b          .L0039BCFC
    /* 29BCDC 0039BCDC 00000000 */   nop
  .L0039BCE0:
    /* 29BCE0 0039BCE0 31010224 */  addiu      $2, $0, 0x131
    /* 29BCE4 0039BCE4 2D200000 */  daddu      $4, $0, $0
    /* 29BCE8 0039BCE8 647D0F0C */  jal        func_003df590
    /* 29BCEC 0039BCEC 8800A2AF */   sw        $2, 0x88($29)
    /* 29BCF0 0039BCF0 8C00A2AF */  sw         $2, 0x8C($29)
    /* 29BCF4 0039BCF4 347D0F0C */  jal        func_003df4d0
    /* 29BCF8 0039BCF8 8800A427 */   addiu     $4, $29, 0x88
  .L0039BCFC:
    /* 29BCFC 0039BCFC 2D20C002 */  daddu      $4, $22, $0
  .L0039BD00:
    /* 29BD00 0039BD00 7849100C */  jal        func_004125e0
    /* 29BD04 0039BD04 00000000 */   nop
    /* 29BD08 0039BD08 0000658E */  lw         $5, 0x0($19)
    /* 29BD0C 0039BD0C 2D204000 */  daddu      $4, $2, $0
    /* 29BD10 0039BD10 2D300000 */  daddu      $6, $0, $0
    /* 29BD14 0039BD14 A44B100C */  jal        func_00412e90
    /* 29BD18 0039BD18 2D380000 */   daddu     $7, $0, $0
    /* 29BD1C 0039BD1C 6800858E */  lw         $5, 0x68($20)
    /* 29BD20 0039BD20 384E0F0C */  jal        func_003d38e0
    /* 29BD24 0039BD24 2D204000 */   daddu     $4, $2, $0
    /* 29BD28 0039BD28 2D804000 */  daddu      $16, $2, $0
    /* 29BD2C 0039BD2C 6C00828E */  lw         $2, 0x6C($20)
    /* 29BD30 0039BD30 0000458C */  lw         $5, 0x0($2)
    /* 29BD34 0039BD34 0400468C */  lw         $6, 0x4($2)
    /* 29BD38 0039BD38 484E0F0C */  jal        func_003d3920
    /* 29BD3C 0039BD3C 2D200002 */   daddu     $4, $16, $0
    /* 29BD40 0039BD40 7000868E */  lw         $6, 0x70($20)
    /* 29BD44 0039BD44 2D200002 */  daddu      $4, $16, $0
    /* 29BD48 0039BD48 684E0F0C */  jal        func_003d39a0
    /* 29BD4C 0039BD4C 01000524 */   addiu     $5, $0, 0x1
    /* 29BD50 0039BD50 7400868E */  lw         $6, 0x74($20)
    /* 29BD54 0039BD54 2D204000 */  daddu      $4, $2, $0
    /* 29BD58 0039BD58 684E0F0C */  jal        func_003d39a0
    /* 29BD5C 0039BD5C 02000524 */   addiu     $5, $0, 0x2
    /* 29BD60 0039BD60 7800868E */  lw         $6, 0x78($20)
    /* 29BD64 0039BD64 2D204000 */  daddu      $4, $2, $0
    /* 29BD68 0039BD68 684E0F0C */  jal        func_003d39a0
    /* 29BD6C 0039BD6C 03000524 */   addiu     $5, $0, 0x3
    /* 29BD70 0039BD70 7C00868E */  lw         $6, 0x7C($20)
    /* 29BD74 0039BD74 2D204000 */  daddu      $4, $2, $0
    /* 29BD78 0039BD78 684E0F0C */  jal        func_003d39a0
    /* 29BD7C 0039BD7C 04000524 */   addiu     $5, $0, 0x4
    /* 29BD80 0039BD80 8000868E */  lw         $6, 0x80($20)
    /* 29BD84 0039BD84 2D204000 */  daddu      $4, $2, $0
    /* 29BD88 0039BD88 684E0F0C */  jal        func_003d39a0
    /* 29BD8C 0039BD8C 05000524 */   addiu     $5, $0, 0x5
    /* 29BD90 0039BD90 0C000010 */  b          .L0039BDC4
    /* 29BD94 0039BD94 2D10A002 */   daddu     $2, $21, $0
  .L0039BD98:
    /* 29BD98 0039BD98 5800838E */  lw         $3, 0x58($20)
    /* 29BD9C 0039BD9C 0700612C */  sltiu      $1, $3, 0x7
    /* 29BDA0 0039BDA0 CFFF2010 */  beqz       $1, .L0039BCE0
    /* 29BDA4 0039BDA4 00000000 */   nop
    /* 29BDA8 0039BDA8 7500043C */  lui        $4, %hi(jtbl_00752D00)
    /* 29BDAC 0039BDAC 80180300 */  sll        $3, $3, 2
    /* 29BDB0 0039BDB0 002D8424 */  addiu      $4, $4, %lo(jtbl_00752D00)
    /* 29BDB4 0039BDB4 21186400 */  addu       $3, $3, $4
    /* 29BDB8 0039BDB8 0000638C */  lw         $3, 0x0($3)
    /* 29BDBC 0039BDBC 08006000 */  jr         $3
    /* 29BDC0 0039BDC0 00000000 */   nop
  .L0039BDC4:
    /* 29BDC4 0039BDC4 7000BFDF */  ld         $31, 0x70($29)
    /* 29BDC8 0039BDC8 6000B67B */  lq         $22, 0x60($29)
    /* 29BDCC 0039BDCC 5000B57B */  lq         $21, 0x50($29)
    /* 29BDD0 0039BDD0 4000B47B */  lq         $20, 0x40($29)
    /* 29BDD4 0039BDD4 3000B37B */  lq         $19, 0x30($29)
    /* 29BDD8 0039BDD8 2000B27B */  lq         $18, 0x20($29)
    /* 29BDDC 0039BDDC 1000B17B */  lq         $17, 0x10($29)
    /* 29BDE0 0039BDE0 0000B07B */  lq         $16, 0x0($29)
    /* 29BDE4 0039BDE4 0800E003 */  jr         $31
    /* 29BDE8 0039BDE8 9000BD27 */   addiu     $29, $29, 0x90
    /* 29BDEC 0039BDEC 00000000 */  nop
.size func_0039bbd0, 0x220
