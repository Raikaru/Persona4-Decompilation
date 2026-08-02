.section .text
.set noat
.set noreorder
glabel func_004afc80
    /* 3AFC80 004AFC80 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3AFC84 004AFC84 3000BFFF */  sd         $31, 0x30($29)
    /* 3AFC88 004AFC88 2000B17F */  sq         $17, 0x20($29)
    /* 3AFC8C 004AFC8C 1000B07F */  sq         $16, 0x10($29)
    /* 3AFC90 004AFC90 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 3AFC94 004AFC94 2D888000 */  daddu      $17, $4, $0
    /* 3AFC98 004AFC98 2D80A000 */  daddu      $16, $5, $0
    /* 3AFC9C 004AFC9C 0C0094C4 */  lwc1       $f20, 0xC($4)
    /* 3AFCA0 004AFCA0 2D200000 */  daddu      $4, $0, $0
    /* 3AFCA4 004AFCA4 2CF4120C */  jal        func_004bd0b0
    /* 3AFCA8 004AFCA8 00000000 */   nop
    /* 3AFCAC 004AFCAC 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 3AFCB0 004AFCB0 00088244 */  mtc1       $2, $f1
    /* 3AFCB4 004AFCB4 00000000 */  nop
    /* 3AFCB8 004AFCB8 81081446 */  sub.s      $f2, $f1, $f20
    /* 3AFCBC 004AFCBC 00088044 */  mtc1       $0, $f1
    /* 3AFCC0 004AFCC0 00000000 */  nop
    /* 3AFCC4 004AFCC4 18080246 */  adda.s     $f1, $f2
    /* 3AFCC8 004AFCC8 1CA50046 */  madd.s     $f20, $f20, $f0
    /* 3AFCCC 004AFCCC 2D200000 */  daddu      $4, $0, $0
    /* 3AFCD0 004AFCD0 2CF4120C */  jal        func_004bd0b0
    /* 3AFCD4 004AFCD4 00000000 */   nop
    /* 3AFCD8 004AFCD8 808081C7 */  lwc1       $f1, -0x7F80($28)
    /* 3AFCDC 004AFCDC 02080046 */  mul.s      $f0, $f1, $f0
    /* 3AFCE0 004AFCE0 000000E6 */  swc1       $f0, 0x0($16)
    /* 3AFCE4 004AFCE4 2D200000 */  daddu      $4, $0, $0
    /* 3AFCE8 004AFCE8 2CF4120C */  jal        func_004bd0b0
    /* 3AFCEC 004AFCEC 00000000 */   nop
    /* 3AFCF0 004AFCF0 808081C7 */  lwc1       $f1, -0x7F80($28)
    /* 3AFCF4 004AFCF4 02080046 */  mul.s      $f0, $f1, $f0
    /* 3AFCF8 004AFCF8 0C0000E6 */  swc1       $f0, 0xC($16)
    /* 3AFCFC 004AFCFC 2D200000 */  daddu      $4, $0, $0
    /* 3AFD00 004AFD00 2CF4120C */  jal        func_004bd0b0
    /* 3AFD04 004AFD04 00000000 */   nop
    /* 3AFD08 004AFD08 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* 3AFD0C 004AFD0C 00108244 */  mtc1       $2, $f2
    /* 3AFD10 004AFD10 00088044 */  mtc1       $0, $f1
    /* 3AFD14 004AFD14 00000000 */  nop
    /* 3AFD18 004AFD18 18080246 */  adda.s     $f1, $f2
    /* 3AFD1C 004AFD1C 5C100046 */  madd.s     $f1, $f2, $f0
    /* 3AFD20 004AFD20 180020C6 */  lwc1       $f0, 0x18($17)
    /* 3AFD24 004AFD24 02000146 */  mul.s      $f0, $f0, $f1
    /* 3AFD28 004AFD28 040000E6 */  swc1       $f0, 0x4($16)
    /* 3AFD2C 004AFD2C 2D200000 */  daddu      $4, $0, $0
    /* 3AFD30 004AFD30 2CF4120C */  jal        func_004bd0b0
    /* 3AFD34 004AFD34 00000000 */   nop
    /* 3AFD38 004AFD38 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* 3AFD3C 004AFD3C 00108244 */  mtc1       $2, $f2
    /* 3AFD40 004AFD40 00088044 */  mtc1       $0, $f1
    /* 3AFD44 004AFD44 00000000 */  nop
    /* 3AFD48 004AFD48 18080246 */  adda.s     $f1, $f2
    /* 3AFD4C 004AFD4C 5C100046 */  madd.s     $f1, $f2, $f0
    /* 3AFD50 004AFD50 180020C6 */  lwc1       $f0, 0x18($17)
    /* 3AFD54 004AFD54 02000146 */  mul.s      $f0, $f0, $f1
    /* 3AFD58 004AFD58 100000E6 */  swc1       $f0, 0x10($16)
    /* 3AFD5C 004AFD5C 2D200000 */  daddu      $4, $0, $0
    /* 3AFD60 004AFD60 2CF4120C */  jal        func_004bd0b0
    /* 3AFD64 004AFD64 00000000 */   nop
    /* 3AFD68 004AFD68 988083C7 */  lwc1       $f3, -0x7F68($28)
    /* 3AFD6C 004AFD6C 9C8082C7 */  lwc1       $f2, -0x7F64($28)
    /* 3AFD70 004AFD70 00088044 */  mtc1       $0, $f1
    /* 3AFD74 004AFD74 00000000 */  nop
    /* 3AFD78 004AFD78 18080246 */  adda.s     $f1, $f2
    /* 3AFD7C 004AFD7C 5C180046 */  madd.s     $f1, $f3, $f0
    /* 3AFD80 004AFD80 100020C6 */  lwc1       $f0, 0x10($17)
    /* 3AFD84 004AFD84 02000146 */  mul.s      $f0, $f0, $f1
    /* 3AFD88 004AFD88 02A00046 */  mul.s      $f0, $f20, $f0
    /* 3AFD8C 004AFD8C 080000E6 */  swc1       $f0, 0x8($16)
    /* 3AFD90 004AFD90 2D200000 */  daddu      $4, $0, $0
    /* 3AFD94 004AFD94 2CF4120C */  jal        func_004bd0b0
    /* 3AFD98 004AFD98 00000000 */   nop
    /* 3AFD9C 004AFD9C 988083C7 */  lwc1       $f3, -0x7F68($28)
    /* 3AFDA0 004AFDA0 9C8082C7 */  lwc1       $f2, -0x7F64($28)
    /* 3AFDA4 004AFDA4 00088044 */  mtc1       $0, $f1
    /* 3AFDA8 004AFDA8 00000000 */  nop
    /* 3AFDAC 004AFDAC 18080246 */  adda.s     $f1, $f2
    /* 3AFDB0 004AFDB0 5C180046 */  madd.s     $f1, $f3, $f0
    /* 3AFDB4 004AFDB4 140020C6 */  lwc1       $f0, 0x14($17)
    /* 3AFDB8 004AFDB8 02000146 */  mul.s      $f0, $f0, $f1
    /* 3AFDBC 004AFDBC 02A00046 */  mul.s      $f0, $f20, $f0
    /* 3AFDC0 004AFDC0 140000E6 */  swc1       $f0, 0x14($16)
    /* 3AFDC4 004AFDC4 240034C6 */  lwc1       $f20, 0x24($17)
    /* 3AFDC8 004AFDC8 2D200000 */  daddu      $4, $0, $0
    /* 3AFDCC 004AFDCC 2CF4120C */  jal        func_004bd0b0
    /* 3AFDD0 004AFDD0 00000000 */   nop
    /* 3AFDD4 004AFDD4 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* 3AFDD8 004AFDD8 00088344 */  mtc1       $3, $f1
    /* 3AFDDC 004AFDDC 00000000 */  nop
    /* 3AFDE0 004AFDE0 81081446 */  sub.s      $f2, $f1, $f20
    /* 3AFDE4 004AFDE4 00088044 */  mtc1       $0, $f1
    /* 3AFDE8 004AFDE8 00000000 */  nop
    /* 3AFDEC 004AFDEC 18080246 */  adda.s     $f1, $f2
    /* 3AFDF0 004AFDF0 1CA00046 */  madd.s     $f0, $f20, $f0
    /* 3AFDF4 004AFDF4 180000E6 */  swc1       $f0, 0x18($16)
    /* 3AFDF8 004AFDF8 3000BFDF */  ld         $31, 0x30($29)
    /* 3AFDFC 004AFDFC 2000B17B */  lq         $17, 0x20($29)
    /* 3AFE00 004AFE00 1000B07B */  lq         $16, 0x10($29)
    /* 3AFE04 004AFE04 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 3AFE08 004AFE08 4000BD27 */  addiu      $29, $29, 0x40
    /* 3AFE0C 004AFE0C 0800E003 */  jr         $31
    /* 3AFE10 004AFE10 00000000 */   nop
    /* 3AFE14 004AFE14 00000000 */  nop
    /* 3AFE18 004AFE18 00000000 */  nop
    /* 3AFE1C 004AFE1C 00000000 */  nop
.size func_004afc80, 0x1a0
