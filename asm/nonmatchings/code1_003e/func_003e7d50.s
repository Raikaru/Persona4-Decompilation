.section .text
.set noat
.set noreorder
glabel func_003e7d50
    /* 2E7D50 003E7D50 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2E7D54 003E7D54 00BF033C */  lui        $3, (0xBF000000 >> 16)
    /* 2E7D58 003E7D58 1000BFFF */  sd         $31, 0x10($29)
    /* 2E7D5C 003E7D5C 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* 2E7D60 003E7D60 0000B07F */  sq         $16, 0x0($29)
    /* 2E7D64 003E7D64 00488344 */  mtc1       $3, $f9
    /* 2E7D68 003E7D68 0400878C */  lw         $7, 0x4($4)
    /* 2E7D6C 003E7D6C 700085C4 */  lwc1       $f5, 0x70($4)
    /* 2E7D70 003E7D70 2D808000 */  daddu      $16, $4, $0
    /* 2E7D74 003E7D74 2D280000 */  daddu      $5, $0, $0
    /* 2E7D78 003E7D78 780081C4 */  lwc1       $f1, 0x78($4)
    /* 2E7D7C 003E7D7C 20000626 */  addiu      $6, $16, 0x20
    /* 2E7D80 003E7D80 00408044 */  mtc1       $0, $f8
    /* 2E7D84 003E7D84 00388244 */  mtc1       $2, $f7
    /* 2E7D88 003E7D88 42490546 */  mul.s      $f5, $f9, $f5
    /* 2E7D8C 003E7D8C 5400E3C4 */  lwc1       $f3, 0x54($7)
    /* 2E7D90 003E7D90 5800E2C4 */  lwc1       $f2, 0x58($7)
    /* 2E7D94 003E7D94 5000E4C4 */  lwc1       $f4, 0x50($7)
    /* 2E7D98 003E7D98 42280146 */  mul.s      $f1, $f5, $f1
    /* 2E7D9C 003E7D9C 87090046 */  neg.s      $f6, $f1
    /* 2E7DA0 003E7DA0 7000E0C4 */  lwc1       $f0, 0x70($7)
    /* 2E7DA4 003E7DA4 C2180546 */  mul.s      $f3, $f3, $f5
    /* 2E7DA8 003E7DA8 82100546 */  mul.s      $f2, $f2, $f5
    /* 2E7DAC 003E7DAC 1A200546 */  mula.s     $f4, $f5
    /* 2E7DB0 003E7DB0 5C010646 */  madd.s     $f5, $f0, $f6
    /* 2E7DB4 003E7DB4 7400E1C4 */  lwc1       $f1, 0x74($7)
    /* 2E7DB8 003E7DB8 7800E0C4 */  lwc1       $f0, 0x78($7)
    /* 2E7DBC 003E7DBC 18400346 */  adda.s     $f8, $f3
    /* 2E7DC0 003E7DC0 1C090646 */  madd.s     $f4, $f1, $f6
    /* 2E7DC4 003E7DC4 18400246 */  adda.s     $f8, $f2
    /* 2E7DC8 003E7DC8 200085E4 */  swc1       $f5, 0x20($4)
    /* 2E7DCC 003E7DCC DC000646 */  madd.s     $f3, $f0, $f6
    /* 2E7DD0 003E7DD0 300084E4 */  swc1       $f4, 0x30($4)
    /* 2E7DD4 003E7DD4 400083E4 */  swc1       $f3, 0x40($4)
    /* 2E7DD8 003E7DD8 8400E0C4 */  lwc1       $f0, 0x84($7)
    /* 2E7DDC 003E7DDC 8000E1C4 */  lwc1       $f1, 0x80($7)
    /* 2E7DE0 003E7DE0 8800E2C4 */  lwc1       $f2, 0x88($7)
    /* 2E7DE4 003E7DE4 1A000446 */  mula.s     $f0, $f4
    /* 2E7DE8 003E7DE8 1E080546 */  madda.s    $f1, $f5
    /* 2E7DEC 003E7DEC 1C100346 */  madd.s     $f0, $f2, $f3
    /* 2E7DF0 003E7DF0 00300046 */  add.s      $f0, $f6, $f0
    /* 2E7DF4 003E7DF4 01380046 */  sub.s      $f0, $f7, $f0
    /* 2E7DF8 003E7DF8 500080E4 */  swc1       $f0, 0x50($4)
    /* 2E7DFC 003E7DFC 740085C4 */  lwc1       $f5, 0x74($4)
    /* 2E7E00 003E7E00 6400E3C4 */  lwc1       $f3, 0x64($7)
    /* 2E7E04 003E7E04 6800E2C4 */  lwc1       $f2, 0x68($7)
    /* 2E7E08 003E7E08 7C0081C4 */  lwc1       $f1, 0x7C($4)
    /* 2E7E0C 003E7E0C 6000E4C4 */  lwc1       $f4, 0x60($7)
    /* 2E7E10 003E7E10 7000E0C4 */  lwc1       $f0, 0x70($7)
    /* 2E7E14 003E7E14 42490546 */  mul.s      $f5, $f9, $f5
    /* 2E7E18 003E7E18 82290146 */  mul.s      $f6, $f5, $f1
    /* 2E7E1C 003E7E1C C2180546 */  mul.s      $f3, $f3, $f5
    /* 2E7E20 003E7E20 82100546 */  mul.s      $f2, $f2, $f5
    /* 2E7E24 003E7E24 1A200546 */  mula.s     $f4, $f5
    /* 2E7E28 003E7E28 5C010646 */  madd.s     $f5, $f0, $f6
    /* 2E7E2C 003E7E2C 7400E1C4 */  lwc1       $f1, 0x74($7)
    /* 2E7E30 003E7E30 7800E0C4 */  lwc1       $f0, 0x78($7)
    /* 2E7E34 003E7E34 18400346 */  adda.s     $f8, $f3
    /* 2E7E38 003E7E38 1C090646 */  madd.s     $f4, $f1, $f6
    /* 2E7E3C 003E7E3C 18400246 */  adda.s     $f8, $f2
    /* 2E7E40 003E7E40 240085E4 */  swc1       $f5, 0x24($4)
    /* 2E7E44 003E7E44 DC000646 */  madd.s     $f3, $f0, $f6
    /* 2E7E48 003E7E48 340084E4 */  swc1       $f4, 0x34($4)
    /* 2E7E4C 003E7E4C 440083E4 */  swc1       $f3, 0x44($4)
    /* 2E7E50 003E7E50 8400E0C4 */  lwc1       $f0, 0x84($7)
    /* 2E7E54 003E7E54 8000E1C4 */  lwc1       $f1, 0x80($7)
    /* 2E7E58 003E7E58 8800E2C4 */  lwc1       $f2, 0x88($7)
    /* 2E7E5C 003E7E5C 1A000446 */  mula.s     $f0, $f4
    /* 2E7E60 003E7E60 1E080546 */  madda.s    $f1, $f5
    /* 2E7E64 003E7E64 1C100346 */  madd.s     $f0, $f2, $f3
    /* 2E7E68 003E7E68 00300046 */  add.s      $f0, $f6, $f0
    /* 2E7E6C 003E7E6C 01380046 */  sub.s      $f0, $f7, $f0
    /* 2E7E70 003E7E70 540080E4 */  swc1       $f0, 0x54($4)
    /* 2E7E74 003E7E74 7000E0C4 */  lwc1       $f0, 0x70($7)
    /* 2E7E78 003E7E78 280080E4 */  swc1       $f0, 0x28($4)
    /* 2E7E7C 003E7E7C 7400E0C4 */  lwc1       $f0, 0x74($7)
    /* 2E7E80 003E7E80 380080E4 */  swc1       $f0, 0x38($4)
    /* 2E7E84 003E7E84 7800E0C4 */  lwc1       $f0, 0x78($7)
    /* 2E7E88 003E7E88 480080E4 */  swc1       $f0, 0x48($4)
    /* 2E7E8C 003E7E8C 8400E1C4 */  lwc1       $f1, 0x84($7)
    /* 2E7E90 003E7E90 7400E0C4 */  lwc1       $f0, 0x74($7)
    /* 2E7E94 003E7E94 8000E3C4 */  lwc1       $f3, 0x80($7)
    /* 2E7E98 003E7E98 7000E2C4 */  lwc1       $f2, 0x70($7)
    /* 2E7E9C 003E7E9C 8800E5C4 */  lwc1       $f5, 0x88($7)
    /* 2E7EA0 003E7EA0 7800E4C4 */  lwc1       $f4, 0x78($7)
    /* 2E7EA4 003E7EA4 1A080046 */  mula.s     $f1, $f0
    /* 2E7EA8 003E7EA8 1E180246 */  madda.s    $f3, $f2
    /* 2E7EAC 003E7EAC 1C280446 */  madd.s     $f0, $f5, $f4
    /* 2E7EB0 003E7EB0 07000046 */  neg.s      $f0, $f0
    /* 2E7EB4 003E7EB4 580080E4 */  swc1       $f0, 0x58($4)
    /* 2E7EB8 003E7EB8 F8800F0C */  jal        func_003e03e0
    /* 2E7EBC 003E7EBC 2D20C000 */   daddu     $4, $6, $0
    /* 2E7EC0 003E7EC0 2D100002 */  daddu      $2, $16, $0
    /* 2E7EC4 003E7EC4 1000BFDF */  ld         $31, 0x10($29)
    /* 2E7EC8 003E7EC8 0000B07B */  lq         $16, 0x0($29)
    /* 2E7ECC 003E7ECC 0800E003 */  jr         $31
    /* 2E7ED0 003E7ED0 2000BD27 */   addiu     $29, $29, 0x20
    /* 2E7ED4 003E7ED4 00000000 */  nop
    /* 2E7ED8 003E7ED8 00000000 */  nop
    /* 2E7EDC 003E7EDC 00000000 */  nop
.size func_003e7d50, 0x190
