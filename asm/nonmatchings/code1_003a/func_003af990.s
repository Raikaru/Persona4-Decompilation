.section .text
.set noat
.set noreorder
glabel func_003af990
    /* 2AF990 003AF990 D0FEBD27 */  addiu      $29, $29, -0x130
    /* 2AF994 003AF994 9000BFFF */  sd         $31, 0x90($29)
    /* 2AF998 003AF998 8000BE7F */  sq         $30, 0x80($29)
    /* 2AF99C 003AF99C 7000B77F */  sq         $23, 0x70($29)
    /* 2AF9A0 003AF9A0 6000B67F */  sq         $22, 0x60($29)
    /* 2AF9A4 003AF9A4 2DB8E000 */  daddu      $23, $7, $0
    /* 2AF9A8 003AF9A8 5000B57F */  sq         $21, 0x50($29)
    /* 2AF9AC 003AF9AC 2DB0C000 */  daddu      $22, $6, $0
    /* 2AF9B0 003AF9B0 4000B47F */  sq         $20, 0x40($29)
    /* 2AF9B4 003AF9B4 2DA8A000 */  daddu      $21, $5, $0
    /* 2AF9B8 003AF9B8 3000B37F */  sq         $19, 0x30($29)
    /* 2AF9BC 003AF9BC 2DA00001 */  daddu      $20, $8, $0
    /* 2AF9C0 003AF9C0 2000B27F */  sq         $18, 0x20($29)
    /* 2AF9C4 003AF9C4 1000B17F */  sq         $17, 0x10($29)
    /* 2AF9C8 003AF9C8 0000B07F */  sq         $16, 0x0($29)
    /* 2AF9CC 003AF9CC 0800038D */  lw         $3, 0x8($8)
    /* 2AF9D0 003AF9D0 0000918C */  lw         $17, 0x0($4)
    /* 2AF9D4 003AF9D4 0400138D */  lw         $19, 0x4($8)
    /* 2AF9D8 003AF9D8 3400128D */  lw         $18, 0x34($8)
    /* 2AF9DC 003AF9DC 1C00108D */  lw         $16, 0x1C($8)
    /* 2AF9E0 003AF9E0 D000A37F */  sq         $3, 0xD0($29)
    /* 2AF9E4 003AF9E4 3800038D */  lw         $3, 0x38($8)
    /* 2AF9E8 003AF9E8 C000A37F */  sq         $3, 0xC0($29)
    /* 2AF9EC 003AF9EC 2000038D */  lw         $3, 0x20($8)
    /* 2AF9F0 003AF9F0 B000A37F */  sq         $3, 0xB0($29)
    /* 2AF9F4 003AF9F4 0400838C */  lw         $3, 0x4($4)
    /* 2AF9F8 003AF9F8 D000A47B */  lq         $4, 0xD0($29)
    /* 2AF9FC 003AF9FC 7E038314 */  bne        $4, $3, .L003B07F8
    /* 2AFA00 003AFA00 A000A37F */   sq        $3, 0xA0($29)
    /* 2AFA04 003AFA04 9886100C */  jal        func_00421a60
    /* 2AFA08 003AFA08 2D200000 */   daddu     $4, $0, $0
    /* 2AFA0C 003AFA0C 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AFA10 003AFA10 00D0648C */  lw         $4, -0x3000($3)
    /* 2AFA14 003AFA14 00018430 */  andi       $4, $4, 0x100
    /* 2AFA18 003AFA18 0C008010 */  beqz       $4, .L003AFA4C
    /* 2AFA1C 003AFA1C 00000000 */   nop
    /* 2AFA20 003AFA20 00010424 */  addiu      $4, $0, 0x100
    /* 2AFA24 003AFA24 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2AFA28 003AFA28 0F000000 */  sync
    /* 2AFA2C 003AFA2C 0F040000 */  sync.p
  .L003AFA30:
    /* 2AFA30 003AFA30 00000000 */  nop
    /* 2AFA34 003AFA34 00000000 */  nop
    /* 2AFA38 003AFA38 00000000 */  nop
    /* 2AFA3C 003AFA3C 00000000 */  nop
    /* 2AFA40 003AFA40 00000000 */  nop
    /* 2AFA44 003AFA44 FAFF0041 */  bc0f       .L003AFA30 /* handwritten instruction */
    /* 2AFA48 003AFA48 00000000 */   nop
  .L003AFA4C:
    /* 2AFA4C 003AFA4C 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AFA50 003AFA50 00D4648C */  lw         $4, -0x2C00($3)
    /* 2AFA54 003AFA54 00018430 */  andi       $4, $4, 0x100
    /* 2AFA58 003AFA58 15008010 */  beqz       $4, .L003AFAB0
    /* 2AFA5C 003AFA5C 00000000 */   nop
    /* 2AFA60 003AFA60 00020424 */  addiu      $4, $0, 0x200
    /* 2AFA64 003AFA64 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2AFA68 003AFA68 0F000000 */  sync
    /* 2AFA6C 003AFA6C 0F040000 */  sync.p
  .L003AFA70:
    /* 2AFA70 003AFA70 00000000 */  nop
    /* 2AFA74 003AFA74 00000000 */  nop
    /* 2AFA78 003AFA78 00000000 */  nop
    /* 2AFA7C 003AFA7C 00000000 */  nop
    /* 2AFA80 003AFA80 00000000 */  nop
    /* 2AFA84 003AFA84 FAFF0041 */  bc0f       .L003AFA70 /* handwritten instruction */
    /* 2AFA88 003AFA88 00000000 */   nop
    /* 2AFA8C 003AFA8C 0110033C */  lui        $3, (0x10010000 >> 16)
  .L003AFA90:
    /* 2AFA90 003AFA90 00D4648C */  lw         $4, -0x2C00($3)
    /* 2AFA94 003AFA94 00018430 */  andi       $4, $4, 0x100
    /* 2AFA98 003AFA98 00000000 */  nop
    /* 2AFA9C 003AFA9C 00000000 */  nop
    /* 2AFAA0 003AFAA0 00000000 */  nop
    /* 2AFAA4 003AFAA4 FAFF8014 */  bnez       $4, .L003AFA90
    /* 2AFAA8 003AFAA8 00000000 */   nop
    /* 2AFAAC 003AFAAC 00000000 */  nop
  .L003AFAB0:
    /* 2AFAB0 003AFAB0 0070043C */  lui        $4, (0x70003F58 >> 16)
    /* 2AFAB4 003AFAB4 680080C6 */  lwc1       $f0, 0x68($20)
    /* 2AFAB8 003AFAB8 603F8334 */  ori        $3, $4, (0x70003F60 & 0xFFFF)
    /* 2AFABC 003AFABC E000A3AF */  sw         $3, 0xE0($29)
    /* 2AFAC0 003AFAC0 403F8634 */  ori        $6, $4, (0x70003F40 & 0xFFFF)
    /* 2AFAC4 003AFAC4 003F033C */  lui        $3, (0x3F000000 >> 16)
    /* 2AFAC8 003AFAC8 503F8534 */  ori        $5, $4, (0x70003F50 & 0xFFFF)
    /* 2AFACC 003AFACC 00088344 */  mtc1       $3, $f1
    /* 2AFAD0 003AFAD0 A03F8F34 */  ori        $15, $4, (0x70003FA0 & 0xFFFF)
    /* 2AFAD4 003AFAD4 0100033C */  lui        $3, (0x10000 >> 16)
    /* 2AFAD8 003AFAD8 603F80E4 */  swc1       $f0, (0x70003F60 & 0xFFFF)($4)
    /* 2AFADC 003AFADC 6C0080C6 */  lwc1       $f0, 0x6C($20)
    /* 2AFAE0 003AFAE0 643F80E4 */  swc1       $f0, (0x70003F64 & 0xFFFF)($4)
    /* 2AFAE4 003AFAE4 680080C6 */  lwc1       $f0, 0x68($20)
    /* 2AFAE8 003AFAE8 683F80E4 */  swc1       $f0, (0x70003F68 & 0xFFFF)($4)
    /* 2AFAEC 003AFAEC 6C0080C6 */  lwc1       $f0, 0x6C($20)
    /* 2AFAF0 003AFAF0 6C3F80E4 */  swc1       $f0, (0x70003F6C & 0xFFFF)($4)
    /* 2AFAF4 003AFAF4 0000A0C6 */  lwc1       $f0, 0x0($21)
    /* 2AFAF8 003AFAF8 02080046 */  mul.s      $f0, $f1, $f0
    /* 2AFAFC 003AFAFC 403F80E4 */  swc1       $f0, (0x70003F40 & 0xFFFF)($4)
    /* 2AFB00 003AFB00 0400A0C6 */  lwc1       $f0, 0x4($21)
    /* 2AFB04 003AFB04 02080046 */  mul.s      $f0, $f1, $f0
    /* 2AFB08 003AFB08 443F80E4 */  swc1       $f0, (0x70003F44 & 0xFFFF)($4)
    /* 2AFB0C 003AFB0C 0800A0C6 */  lwc1       $f0, 0x8($21)
    /* 2AFB10 003AFB10 02080046 */  mul.s      $f0, $f1, $f0
    /* 2AFB14 003AFB14 483F80E4 */  swc1       $f0, (0x70003F48 & 0xFFFF)($4)
    /* 2AFB18 003AFB18 0000C0C6 */  lwc1       $f0, 0x0($22)
    /* 2AFB1C 003AFB1C 02080046 */  mul.s      $f0, $f1, $f0
    /* 2AFB20 003AFB20 503F80E4 */  swc1       $f0, (0x70003F50 & 0xFFFF)($4)
    /* 2AFB24 003AFB24 0400C0C6 */  lwc1       $f0, 0x4($22)
    /* 2AFB28 003AFB28 02080046 */  mul.s      $f0, $f1, $f0
    /* 2AFB2C 003AFB2C 543F80E4 */  swc1       $f0, (0x70003F54 & 0xFFFF)($4)
    /* 2AFB30 003AFB30 0800C0C6 */  lwc1       $f0, 0x8($22)
    /* 2AFB34 003AFB34 02080046 */  mul.s      $f0, $f1, $f0
    /* 2AFB38 003AFB38 583F80E4 */  swc1       $f0, (0x70003F58 & 0xFFFF)($4)
  .L003AFB3C:
    /* 2AFB3C 003AFB3C 39000042 */  di /* handwritten instruction */
    /* 2AFB40 003AFB40 0F040000 */  sync.p
    /* 2AFB44 003AFB44 00600440 */  mfc0       $4, $12 /* handwritten instruction */
    /* 2AFB48 003AFB48 24208300 */  and        $4, $4, $3
    /* 2AFB4C 003AFB4C 00000000 */  nop
    /* 2AFB50 003AFB50 FAFF8014 */  bnez       $4, .L003AFB3C
    /* 2AFB54 003AFB54 00000000 */   nop
    /* 2AFB58 003AFB58 C93F013C */  lui        $1, (0x3FC90FDB >> 16)
    /* 2AFB5C 003AFB5C DB0F2334 */  ori        $3, $1, (0x3FC90FDB & 0xFFFF)
    /* 2AFB60 003AFB60 00008344 */  mtc1       $3, $f0
    /* 2AFB64 003AFB64 00000344 */  mfc1       $3, $f0
    /* 2AFB68 003AFB68 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2AFB6C 003AFB6C FF02004A */  vnop
    /* 2AFB70 003AFB70 FF02004A */  vnop
    /* 2AFB74 003AFB74 A202004B */  vaddi.x    $vf10, $vf0, $I
    /* 2AFB78 003AFB78 4940013C */  lui        $1, (0x40490FDB >> 16)
    /* 2AFB7C 003AFB7C DB0F2434 */  ori        $4, $1, (0x40490FDB & 0xFFFF)
    /* 2AFB80 003AFB80 00008444 */  mtc1       $4, $f0
    /* 2AFB84 003AFB84 00000344 */  mfc1       $3, $f0
    /* 2AFB88 003AFB88 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2AFB8C 003AFB8C FF02004A */  vnop
    /* 2AFB90 003AFB90 FF02004A */  vnop
    /* 2AFB94 003AFB94 A202804A */  vaddi.y    $vf10, $vf0, $I
    /* 2AFB98 003AFB98 0940013C */  lui        $1, (0x40090FDB >> 16)
    /* 2AFB9C 003AFB9C DB0F2334 */  ori        $3, $1, (0x40090FDB & 0xFFFF)
    /* 2AFBA0 003AFBA0 00008344 */  mtc1       $3, $f0
    /* 2AFBA4 003AFBA4 00000344 */  mfc1       $3, $f0
    /* 2AFBA8 003AFBA8 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2AFBAC 003AFBAC FF02004A */  vnop
    /* 2AFBB0 003AFBB0 FF02004A */  vnop
    /* 2AFBB4 003AFBB4 A202404A */  vaddi.z    $vf10, $vf0, $I
    /* 2AFBB8 003AFBB8 00008444 */  mtc1       $4, $f0
    /* 2AFBBC 003AFBBC 07000046 */  neg.s      $f0, $f0
    /* 2AFBC0 003AFBC0 00000344 */  mfc1       $3, $f0
    /* 2AFBC4 003AFBC4 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2AFBC8 003AFBC8 FF02004A */  vnop
    /* 2AFBCC 003AFBCC FF02004A */  vnop
    /* 2AFBD0 003AFBD0 E202004B */  vaddi.x    $vf11, $vf0, $I
    /* 2AFBD4 003AFBD4 8440013C */  lui        $1, (0x408487ED >> 16)
    /* 2AFBD8 003AFBD8 ED872334 */  ori        $3, $1, (0x408487ED & 0xFFFF)
    /* 2AFBDC 003AFBDC 00008344 */  mtc1       $3, $f0
    /* 2AFBE0 003AFBE0 07000046 */  neg.s      $f0, $f0
    /* 2AFBE4 003AFBE4 00000344 */  mfc1       $3, $f0
    /* 2AFBE8 003AFBE8 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2AFBEC 003AFBEC FF02004A */  vnop
    /* 2AFBF0 003AFBF0 FF02004A */  vnop
    /* 2AFBF4 003AFBF4 E202804A */  vaddi.y    $vf11, $vf0, $I
    /* 2AFBF8 003AFBF8 00000334 */  ori        $3, $0, 0x0
    /* 2AFBFC 003AFBFC 381C0300 */  dsll       $3, $3, 16
    /* 2AFC00 003AFC00 381C0300 */  dsll       $3, $3, 16
    /* 2AFC04 003AFC04 4FB96334 */  ori        $3, $3, 0xB94F
    /* 2AFC08 003AFC08 381C0300 */  dsll       $3, $3, 16
    /* 2AFC0C 003AFC0C 1FB26334 */  ori        $3, $3, 0xB21F
    /* 2AFC10 003AFC10 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2AFC14 003AFC14 FF02004A */  vnop
    /* 2AFC18 003AFC18 FF02004A */  vnop
    /* 2AFC1C 003AFC1C E202404A */  vaddi.z    $vf11, $vf0, $I
    /* 2AFC20 003AFC20 00000334 */  ori        $3, $0, 0x0
    /* 2AFC24 003AFC24 381C0300 */  dsll       $3, $3, 16
    /* 2AFC28 003AFC28 381C0300 */  dsll       $3, $3, 16
    /* 2AFC2C 003AFC2C 2ABE6334 */  ori        $3, $3, 0xBE2A
    /* 2AFC30 003AFC30 381C0300 */  dsll       $3, $3, 16
    /* 2AFC34 003AFC34 A4AA6334 */  ori        $3, $3, 0xAAA4
    /* 2AFC38 003AFC38 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2AFC3C 003AFC3C FF02004A */  vnop
    /* 2AFC40 003AFC40 FF02004A */  vnop
    /* 2AFC44 003AFC44 2203004B */  vaddi.x    $vf12, $vf0, $I
    /* 2AFC48 003AFC48 083C013C */  lui        $1, (0x3C08873E >> 16)
    /* 2AFC4C 003AFC4C 3E872334 */  ori        $3, $1, (0x3C08873E & 0xFFFF)
    /* 2AFC50 003AFC50 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2AFC54 003AFC54 FF02004A */  vnop
    /* 2AFC58 003AFC58 FF02004A */  vnop
    /* 2AFC5C 003AFC5C 2203804A */  vaddi.y    $vf12, $vf0, $I
    /* 2AFC60 003AFC60 2E36013C */  lui        $1, (0x362E9C14 >> 16)
    /* 2AFC64 003AFC64 149C2334 */  ori        $3, $1, (0x362E9C14 & 0xFFFF)
    /* 2AFC68 003AFC68 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2AFC6C 003AFC6C FF02004A */  vnop
    /* 2AFC70 003AFC70 FF02004A */  vnop
    /* 2AFC74 003AFC74 2203404A */  vaddi.z    $vf12, $vf0, $I
    /* 2AFC78 003AFC78 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* 2AFC7C 003AFC7C 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2AFC80 003AFC80 FF02004A */  vnop
    /* 2AFC84 003AFC84 FF02004A */  vnop
    /* 2AFC88 003AFC88 6203004B */  vaddi.x    $vf13, $vf0, $I
    /* 2AFC8C 003AFC8C 38000042 */  ei /* handwritten instruction */
    /* 2AFC90 003AFC90 0100033C */  lui        $3, (0x10000 >> 16)
  .L003AFC94:
    /* 2AFC94 003AFC94 39000042 */  di /* handwritten instruction */
    /* 2AFC98 003AFC98 0F040000 */  sync.p
    /* 2AFC9C 003AFC9C 00600440 */  mfc0       $4, $12 /* handwritten instruction */
    /* 2AFCA0 003AFCA0 24208300 */  and        $4, $4, $3
    /* 2AFCA4 003AFCA4 00000000 */  nop
    /* 2AFCA8 003AFCA8 FAFF8014 */  bnez       $4, .L003AFC94
    /* 2AFCAC 003AFCAC 00000000 */   nop
    /* 2AFCB0 003AFCB0 0000C8D8 */  lqc2       $vf8, 0x0($6)
    /* 2AFCB4 003AFCB4 0000A9D8 */  lqc2       $vf9, 0x0($5)
    /* 2AFCB8 003AFCB8 E000A38F */  lw         $3, 0xE0($29)
    /* 2AFCBC 003AFCBC 00006FD8 */  lqc2       $vf15, 0x0($3)
    /* 2AFCC0 003AFCC0 38000042 */  ei /* handwritten instruction */
    /* 2AFCC4 003AFCC4 B000E32A */  slti       $3, $23, 0xB0
    /* 2AFCC8 003AFCC8 2B016014 */  bnez       $3, .L003B0178
    /* 2AFCCC 003AFCCC 00000000 */   nop
    /* 2AFCD0 003AFCD0 0070083C */  lui        $8, (0x70001340 >> 16)
    /* 2AFCD4 003AFCD4 0110043C */  lui        $4, (0x10010000 >> 16)
    /* 2AFCD8 003AFCD8 00010D24 */  addiu      $13, $0, 0x100
    /* 2AFCDC 003AFCDC 00020C24 */  addiu      $12, $0, 0x200
    /* 2AFCE0 003AFCE0 2C000B24 */  addiu      $11, $0, 0x2C
    /* 2AFCE4 003AFCE4 C0020A24 */  addiu      $10, $0, 0x2C0
    /* 2AFCE8 003AFCE8 58000924 */  addiu      $9, $0, 0x58
    /* 2AFCEC 003AFCEC 40081E24 */  addiu      $30, $0, 0x840
    /* 2AFCF0 003AFCF0 C0020735 */  ori        $7, $8, (0x700002C0 & 0xFFFF)
    /* 2AFCF4 003AFCF4 40080635 */  ori        $6, $8, (0x70000840 & 0xFFFF)
    /* 2AFCF8 003AFCF8 40130535 */  ori        $5, $8, (0x70001340 & 0xFFFF)
  .L003AFCFC:
    /* 2AFCFC 003AFCFC 00D0838C */  lw         $3, -0x3000($4)
    /* 2AFD00 003AFD00 00016330 */  andi       $3, $3, 0x100
    /* 2AFD04 003AFD04 0C006010 */  beqz       $3, .L003AFD38
    /* 2AFD08 003AFD08 00000000 */   nop
    /* 2AFD0C 003AFD0C 20E08DAC */  sw         $13, -0x1FE0($4)
    /* 2AFD10 003AFD10 0F000000 */  sync
    /* 2AFD14 003AFD14 0F040000 */  sync.p
  .L003AFD18:
    /* 2AFD18 003AFD18 00000000 */  nop
    /* 2AFD1C 003AFD1C 00000000 */  nop
    /* 2AFD20 003AFD20 00000000 */  nop
    /* 2AFD24 003AFD24 00000000 */  nop
    /* 2AFD28 003AFD28 00000000 */  nop
    /* 2AFD2C 003AFD2C FAFF0041 */  bc0f       .L003AFD18 /* handwritten instruction */
    /* 2AFD30 003AFD30 00000000 */   nop
    /* 2AFD34 003AFD34 00000000 */  nop
  .L003AFD38:
    /* 2AFD38 003AFD38 00D4838C */  lw         $3, -0x2C00($4)
    /* 2AFD3C 003AFD3C 00016330 */  andi       $3, $3, 0x100
    /* 2AFD40 003AFD40 15006010 */  beqz       $3, .L003AFD98
    /* 2AFD44 003AFD44 00000000 */   nop
    /* 2AFD48 003AFD48 20E08CAC */  sw         $12, -0x1FE0($4)
    /* 2AFD4C 003AFD4C 0F000000 */  sync
    /* 2AFD50 003AFD50 0F040000 */  sync.p
    /* 2AFD54 003AFD54 00000000 */  nop
  .L003AFD58:
    /* 2AFD58 003AFD58 00000000 */  nop
    /* 2AFD5C 003AFD5C 00000000 */  nop
    /* 2AFD60 003AFD60 00000000 */  nop
    /* 2AFD64 003AFD64 00000000 */  nop
    /* 2AFD68 003AFD68 00000000 */  nop
    /* 2AFD6C 003AFD6C FAFF0041 */  bc0f       .L003AFD58 /* handwritten instruction */
    /* 2AFD70 003AFD70 00000000 */   nop
    /* 2AFD74 003AFD74 00000000 */  nop
  .L003AFD78:
    /* 2AFD78 003AFD78 00D4838C */  lw         $3, -0x2C00($4)
    /* 2AFD7C 003AFD7C 00016330 */  andi       $3, $3, 0x100
    /* 2AFD80 003AFD80 00000000 */  nop
    /* 2AFD84 003AFD84 00000000 */  nop
    /* 2AFD88 003AFD88 00000000 */  nop
    /* 2AFD8C 003AFD8C FAFF6014 */  bnez       $3, .L003AFD78
    /* 2AFD90 003AFD90 00000000 */   nop
    /* 2AFD94 003AFD94 00000000 */  nop
  .L003AFD98:
    /* 2AFD98 003AFD98 10E08CAC */  sw         $12, -0x1FF0($4)
    /* 2AFD9C 003AFD9C 80D480AC */  sw         $0, -0x2B80($4)
    /* 2AFDA0 003AFDA0 10D492AC */  sw         $18, -0x2BF0($4)
    /* 2AFDA4 003AFDA4 20D48BAC */  sw         $11, -0x2BE0($4)
    /* 2AFDA8 003AFDA8 00D48DAC */  sw         $13, -0x2C00($4)
    /* 2AFDAC 003AFDAC 0F000000 */  sync
    /* 2AFDB0 003AFDB0 0F040000 */  sync.p
    /* 2AFDB4 003AFDB4 00D4838C */  lw         $3, -0x2C00($4)
    /* 2AFDB8 003AFDB8 00016330 */  andi       $3, $3, 0x100
    /* 2AFDBC 003AFDBC 14006010 */  beqz       $3, .L003AFE10
    /* 2AFDC0 003AFDC0 00000000 */   nop
    /* 2AFDC4 003AFDC4 20E08CAC */  sw         $12, -0x1FE0($4)
    /* 2AFDC8 003AFDC8 0F000000 */  sync
    /* 2AFDCC 003AFDCC 0F040000 */  sync.p
  .L003AFDD0:
    /* 2AFDD0 003AFDD0 00000000 */  nop
    /* 2AFDD4 003AFDD4 00000000 */  nop
    /* 2AFDD8 003AFDD8 00000000 */  nop
    /* 2AFDDC 003AFDDC 00000000 */  nop
    /* 2AFDE0 003AFDE0 00000000 */  nop
    /* 2AFDE4 003AFDE4 FAFF0041 */  bc0f       .L003AFDD0 /* handwritten instruction */
    /* 2AFDE8 003AFDE8 00000000 */   nop
    /* 2AFDEC 003AFDEC 00000000 */  nop
  .L003AFDF0:
    /* 2AFDF0 003AFDF0 00D4838C */  lw         $3, -0x2C00($4)
    /* 2AFDF4 003AFDF4 00016330 */  andi       $3, $3, 0x100
    /* 2AFDF8 003AFDF8 00000000 */  nop
    /* 2AFDFC 003AFDFC 00000000 */  nop
    /* 2AFE00 003AFE00 00000000 */  nop
    /* 2AFE04 003AFE04 FAFF6014 */  bnez       $3, .L003AFDF0
    /* 2AFE08 003AFE08 00000000 */   nop
    /* 2AFE0C 003AFE0C 00000000 */  nop
  .L003AFE10:
    /* 2AFE10 003AFE10 10E08CAC */  sw         $12, -0x1FF0($4)
    /* 2AFE14 003AFE14 80D48AAC */  sw         $10, -0x2B80($4)
    /* 2AFE18 003AFE18 10D490AC */  sw         $16, -0x2BF0($4)
    /* 2AFE1C 003AFE1C 20D489AC */  sw         $9, -0x2BE0($4)
    /* 2AFE20 003AFE20 00D48DAC */  sw         $13, -0x2C00($4)
    /* 2AFE24 003AFE24 0F000000 */  sync
    /* 2AFE28 003AFE28 0F040000 */  sync.p
    /* 2AFE2C 003AFE2C 00D4838C */  lw         $3, -0x2C00($4)
    /* 2AFE30 003AFE30 00016330 */  andi       $3, $3, 0x100
    /* 2AFE34 003AFE34 14006010 */  beqz       $3, .L003AFE88
    /* 2AFE38 003AFE38 00000000 */   nop
    /* 2AFE3C 003AFE3C 20E08CAC */  sw         $12, -0x1FE0($4)
    /* 2AFE40 003AFE40 0F000000 */  sync
    /* 2AFE44 003AFE44 0F040000 */  sync.p
  .L003AFE48:
    /* 2AFE48 003AFE48 00000000 */  nop
    /* 2AFE4C 003AFE4C 00000000 */  nop
    /* 2AFE50 003AFE50 00000000 */  nop
    /* 2AFE54 003AFE54 00000000 */  nop
    /* 2AFE58 003AFE58 00000000 */  nop
    /* 2AFE5C 003AFE5C FAFF0041 */  bc0f       .L003AFE48 /* handwritten instruction */
    /* 2AFE60 003AFE60 00000000 */   nop
    /* 2AFE64 003AFE64 00000000 */  nop
  .L003AFE68:
    /* 2AFE68 003AFE68 00D4838C */  lw         $3, -0x2C00($4)
    /* 2AFE6C 003AFE6C 00016330 */  andi       $3, $3, 0x100
    /* 2AFE70 003AFE70 00000000 */  nop
    /* 2AFE74 003AFE74 00000000 */  nop
    /* 2AFE78 003AFE78 00000000 */  nop
    /* 2AFE7C 003AFE7C FAFF6014 */  bnez       $3, .L003AFE68
    /* 2AFE80 003AFE80 00000000 */   nop
    /* 2AFE84 003AFE84 00000000 */  nop
  .L003AFE88:
    /* 2AFE88 003AFE88 10E08CAC */  sw         $12, -0x1FF0($4)
    /* 2AFE8C 003AFE8C 80D49EAC */  sw         $30, -0x2B80($4)
    /* 2AFE90 003AFE90 B0000324 */  addiu      $3, $0, 0xB0
    /* 2AFE94 003AFE94 10D493AC */  sw         $19, -0x2BF0($4)
    /* 2AFE98 003AFE98 20D483AC */  sw         $3, -0x2BE0($4)
    /* 2AFE9C 003AFE9C 00D48DAC */  sw         $13, -0x2C00($4)
    /* 2AFEA0 003AFEA0 0F000000 */  sync
    /* 2AFEA4 003AFEA4 0F040000 */  sync.p
    /* 2AFEA8 003AFEA8 00D4838C */  lw         $3, -0x2C00($4)
    /* 2AFEAC 003AFEAC 00016330 */  andi       $3, $3, 0x100
    /* 2AFEB0 003AFEB0 15006010 */  beqz       $3, .L003AFF08
    /* 2AFEB4 003AFEB4 00000000 */   nop
    /* 2AFEB8 003AFEB8 20E08CAC */  sw         $12, -0x1FE0($4)
    /* 2AFEBC 003AFEBC 0F000000 */  sync
    /* 2AFEC0 003AFEC0 0F040000 */  sync.p
    /* 2AFEC4 003AFEC4 00000000 */  nop
  .L003AFEC8:
    /* 2AFEC8 003AFEC8 00000000 */  nop
    /* 2AFECC 003AFECC 00000000 */  nop
    /* 2AFED0 003AFED0 00000000 */  nop
    /* 2AFED4 003AFED4 00000000 */  nop
    /* 2AFED8 003AFED8 00000000 */  nop
    /* 2AFEDC 003AFEDC FAFF0041 */  bc0f       .L003AFEC8 /* handwritten instruction */
    /* 2AFEE0 003AFEE0 00000000 */   nop
    /* 2AFEE4 003AFEE4 00000000 */  nop
  .L003AFEE8:
    /* 2AFEE8 003AFEE8 00D4838C */  lw         $3, -0x2C00($4)
    /* 2AFEEC 003AFEEC 00016330 */  andi       $3, $3, 0x100
    /* 2AFEF0 003AFEF0 00000000 */  nop
    /* 2AFEF4 003AFEF4 00000000 */  nop
    /* 2AFEF8 003AFEF8 00000000 */  nop
    /* 2AFEFC 003AFEFC FAFF6014 */  bnez       $3, .L003AFEE8
    /* 2AFF00 003AFF00 00000000 */   nop
    /* 2AFF04 003AFF04 00000000 */  nop
  .L003AFF08:
    /* 2AFF08 003AFF08 2DA80001 */  daddu      $21, $8, $0
    /* 2AFF0C 003AFF0C 2DA0E000 */  daddu      $20, $7, $0
    /* 2AFF10 003AFF10 2DC8C000 */  daddu      $25, $6, $0
    /* 2AFF14 003AFF14 2DC0A000 */  daddu      $24, $5, $0
    /* 2AFF18 003AFF18 2DB00000 */  daddu      $22, $0, $0
    /* 2AFF1C 003AFF1C 00000000 */  nop
  .L003AFF20:
    /* 2AFF20 003AFF20 0000A0C6 */  lwc1       $f0, (0x70000000 & 0xFFFF)($21)
    /* 2AFF24 003AFF24 0000E0E5 */  swc1       $f0, 0x0($15)
    /* 2AFF28 003AFF28 0400A0C6 */  lwc1       $f0, (0x70000004 & 0xFFFF)($21)
    /* 2AFF2C 003AFF2C 0400E0E5 */  swc1       $f0, 0x4($15)
    /* 2AFF30 003AFF30 0000A0C6 */  lwc1       $f0, (0x70000000 & 0xFFFF)($21)
    /* 2AFF34 003AFF34 0800E0E5 */  swc1       $f0, 0x8($15)
    /* 2AFF38 003AFF38 0400A0C6 */  lwc1       $f0, (0x70000004 & 0xFFFF)($21)
    /* 2AFF3C 003AFF3C 0C00E0E5 */  swc1       $f0, 0xC($15)
  .L003AFF40:
    /* 2AFF40 003AFF40 39000042 */  di /* handwritten instruction */
    /* 2AFF44 003AFF44 0F040000 */  sync.p
    /* 2AFF48 003AFF48 00600E40 */  mfc0       $14, $12 /* handwritten instruction */
    /* 2AFF4C 003AFF4C 0100033C */  lui        $3, (0x10000 >> 16)
    /* 2AFF50 003AFF50 2470C301 */  and        $14, $14, $3
    /* 2AFF54 003AFF54 00000000 */  nop
    /* 2AFF58 003AFF58 F9FFC015 */  bnez       $14, .L003AFF40
    /* 2AFF5C 003AFF5C 00000000 */   nop
    /* 2AFF60 003AFF60 0000E1D9 */  lqc2       $vf1, 0x0($15)
    /* 2AFF64 003AFF64 FD09874B */  vabs.xy    $vf7, $vf1
    /* 2AFF68 003AFF68 3C00EA4B */  vaddax.xyzw $ACC, $vf0, $vf10x
    /* 2AFF6C 003AFF6C CF39804B */  vmsubw.xy  $vf7, $vf7, $vf0w
    /* 2AFF70 003AFF70 3D00CA4B */  vadday.xyz $ACC, $vf0, $vf10y
    /* 2AFF74 003AFF74 3E002A4A */  vaddaz.w   $ACC, $vf0, $vf10z
    /* 2AFF78 003AFF78 8F08604A */  vmsubw.zw  $vf2, $vf1, $vf0w
    /* 2AFF7C 003AFF7C 3C00CB4B */  vaddax.xyz $ACC, $vf0, $vf11x
    /* 2AFF80 003AFF80 3D002B4A */  vadday.w   $ACC, $vf0, $vf11y
    /* 2AFF84 003AFF84 CF08604A */  vmsubw.zw  $vf3, $vf1, $vf0w
    /* 2AFF88 003AFF88 AF08624A */  vmini.zw   $vf2, $vf1, $vf2
    /* 2AFF8C 003AFF8C EB11634A */  vmax.zw    $vf7, $vf2, $vf3
    /* 2AFF90 003AFF90 AA38E74B */  vmul.xyzw  $vf2, $vf7, $vf7
    /* 2AFF94 003AFF94 9A39EB4B */  vmulz.xyzw $vf6, $vf7, $vf11z
    /* 2AFF98 003AFF98 1839EC4B */  vmulx.xyzw $vf4, $vf7, $vf12x
    /* 2AFF9C 003AFF9C 5939EC4B */  vmuly.xyzw $vf5, $vf7, $vf12y
    /* 2AFFA0 003AFFA0 EA10E24B */  vmul.xyzw  $vf3, $vf2, $vf2
    /* 2AFFA4 003AFFA4 AA31E24B */  vmul.xyzw  $vf6, $vf6, $vf2
    /* 2AFFA8 003AFFA8 BE22E24B */  vmula.xyzw $ACC, $vf4, $vf2
    /* 2AFFAC 003AFFAC 1A39EC4B */  vmulz.xyzw $vf4, $vf7, $vf12z
    /* 2AFFB0 003AFFB0 AA18E34B */  vmul.xyzw  $vf2, $vf3, $vf3
    /* 2AFFB4 003AFFB4 BD32E34B */  vmadda.xyzw $ACC, $vf6, $vf3
    /* 2AFFB8 003AFFB8 BD2AE34B */  vmadda.xyzw $ACC, $vf5, $vf3
    /* 2AFFBC 003AFFBC BC38ED4B */  vmaddax.xyzw $ACC, $vf7, $vf13x
    /* 2AFFC0 003AFFC0 E921E24B */  vmadd.xyzw $vf7, $vf4, $vf2
    /* 2AFFC4 003AFFC4 000034DB */  lqc2       $vf20, 0x0($25)
    /* 2AFFC8 003AFFC8 10003BDB */  lqc2       $vf27, 0x10($25)
    /* 2AFFCC 003AFFCC 00008EDA */  lqc2       $vf14, 0x0($20)
    /* 2AFFD0 003AFFD0 BC41E74B */  vmulax.xyzw $ACC, $vf8, $vf7x
    /* 2AFFD4 003AFFD4 8E4CE74B */  vmsubz.xyzw $vf18, $vf9, $vf7z
    /* 2AFFD8 003AFFD8 A878EE4B */  vadd.xyzw  $vf2, $vf15, $vf14
    /* 2AFFDC 003AFFDC EC78EE4B */  vsub.xyzw  $vf3, $vf15, $vf14
    /* 2AFFE0 003AFFE0 BC49E74B */  vmulax.xyzw $ACC, $vf9, $vf7x
    /* 2AFFE4 003AFFE4 CA44E74B */  vmaddz.xyzw $vf19, $vf8, $vf7z
    /* 2AFFE8 003AFFE8 BD41E74B */  vmulay.xyzw $ACC, $vf8, $vf7y
    /* 2AFFEC 003AFFEC 4F4EE74B */  vmsubw.xyzw $vf25, $vf9, $vf7w
    /* 2AFFF0 003AFFF0 BD49E74B */  vmulay.xyzw $ACC, $vf9, $vf7y
    /* 2AFFF4 003AFFF4 8B46E74B */  vmaddw.xyzw $vf26, $vf8, $vf7w
    /* 2AFFF8 003AFFF8 BC91E34B */  vmulax.xyzw $ACC, $vf18, $vf3x
    /* 2AFFFC 003AFFFC 499DE34B */  vmaddy.xyzw $vf21, $vf19, $vf3y
    /* 2B0000 003B0000 BC91E24B */  vmulax.xyzw $ACC, $vf18, $vf2x
    /* 2B0004 003B0004 899DE34B */  vmaddy.xyzw $vf22, $vf19, $vf3y
    /* 2B0008 003B0008 BC91E24B */  vmulax.xyzw $ACC, $vf18, $vf2x
    /* 2B000C 003B000C C99DE24B */  vmaddy.xyzw $vf23, $vf19, $vf2y
    /* 2B0010 003B0010 BC91E34B */  vmulax.xyzw $ACC, $vf18, $vf3x
    /* 2B0014 003B0014 099EE24B */  vmaddy.xyzw $vf24, $vf19, $vf2y
    /* 2B0018 003B0018 BEC9E34B */  vmulaz.xyzw $ACC, $vf25, $vf3z
    /* 2B001C 003B001C 0BD7E34B */  vmaddw.xyzw $vf28, $vf26, $vf3w
    /* 2B0020 003B0020 BEC9E24B */  vmulaz.xyzw $ACC, $vf25, $vf2z
    /* 2B0024 003B0024 4BD7E34B */  vmaddw.xyzw $vf29, $vf26, $vf3w
    /* 2B0028 003B0028 BEC9E24B */  vmulaz.xyzw $ACC, $vf25, $vf2z
    /* 2B002C 003B002C 8BD7E24B */  vmaddw.xyzw $vf30, $vf26, $vf2w
    /* 2B0030 003B0030 BEC9E34B */  vmulaz.xyzw $ACC, $vf25, $vf3z
    /* 2B0034 003B0034 CBD7E24B */  vmaddw.xyzw $vf31, $vf26, $vf2w
    /* 2B0038 003B0038 68ADF44B */  vadd.xyzw  $vf21, $vf21, $vf20
    /* 2B003C 003B003C A8B5F44B */  vadd.xyzw  $vf22, $vf22, $vf20
    /* 2B0040 003B0040 E8BDF44B */  vadd.xyzw  $vf23, $vf23, $vf20
    /* 2B0044 003B0044 28C6F44B */  vadd.xyzw  $vf24, $vf24, $vf20
    /* 2B0048 003B0048 28E7FB4B */  vadd.xyzw  $vf28, $vf28, $vf27
    /* 2B004C 003B004C 68EFFB4B */  vadd.xyzw  $vf29, $vf29, $vf27
    /* 2B0050 003B0050 A8F7FB4B */  vadd.xyzw  $vf30, $vf30, $vf27
    /* 2B0054 003B0054 E8FFFB4B */  vadd.xyzw  $vf31, $vf31, $vf27
    /* 2B0058 003B0058 000015FB */  sqc2       $vf21, 0x0($24)
    /* 2B005C 003B005C 100016FB */  sqc2       $vf22, 0x10($24)
    /* 2B0060 003B0060 200017FB */  sqc2       $vf23, 0x20($24)
    /* 2B0064 003B0064 300018FB */  sqc2       $vf24, 0x30($24)
    /* 2B0068 003B0068 40001CFB */  sqc2       $vf28, 0x40($24)
    /* 2B006C 003B006C 50001DFB */  sqc2       $vf29, 0x50($24)
    /* 2B0070 003B0070 60001EFB */  sqc2       $vf30, 0x60($24)
    /* 2B0074 003B0074 70001FFB */  sqc2       $vf31, 0x70($24)
    /* 2B0078 003B0078 38000042 */  ei /* handwritten instruction */
    /* 2B007C 003B007C 0200D626 */  addiu      $22, $22, 0x2
    /* 2B0080 003B0080 B000C32A */  slti       $3, $22, 0xB0
    /* 2B0084 003B0084 20003927 */  addiu      $25, $25, 0x20
    /* 2B0088 003B0088 10009426 */  addiu      $20, $20, 0x10
    /* 2B008C 003B008C 0800B526 */  addiu      $21, $21, %lo(D_70000008)
    /* 2B0090 003B0090 A3FF6014 */  bnez       $3, .L003AFF20
    /* 2B0094 003B0094 80001827 */   addiu     $24, $24, 0x80
    /* 2B0098 003B0098 00D0838C */  lw         $3, -0x3000($4)
    /* 2B009C 003B009C 00016330 */  andi       $3, $3, 0x100
    /* 2B00A0 003B00A0 0D006010 */  beqz       $3, .L003B00D8
    /* 2B00A4 003B00A4 00000000 */   nop
    /* 2B00A8 003B00A8 20E08DAC */  sw         $13, -0x1FE0($4)
    /* 2B00AC 003B00AC 0F000000 */  sync
    /* 2B00B0 003B00B0 0F040000 */  sync.p
    /* 2B00B4 003B00B4 00000000 */  nop
  .L003B00B8:
    /* 2B00B8 003B00B8 00000000 */  nop
    /* 2B00BC 003B00BC 00000000 */  nop
    /* 2B00C0 003B00C0 00000000 */  nop
    /* 2B00C4 003B00C4 00000000 */  nop
    /* 2B00C8 003B00C8 00000000 */  nop
    /* 2B00CC 003B00CC FAFF0041 */  bc0f       .L003B00B8 /* handwritten instruction */
    /* 2B00D0 003B00D0 00000000 */   nop
    /* 2B00D4 003B00D4 00000000 */  nop
  .L003B00D8:
    /* 2B00D8 003B00D8 00D4838C */  lw         $3, -0x2C00($4)
    /* 2B00DC 003B00DC 00016330 */  andi       $3, $3, 0x100
    /* 2B00E0 003B00E0 15006010 */  beqz       $3, .L003B0138
    /* 2B00E4 003B00E4 00000000 */   nop
    /* 2B00E8 003B00E8 20E08CAC */  sw         $12, -0x1FE0($4)
    /* 2B00EC 003B00EC 0F000000 */  sync
    /* 2B00F0 003B00F0 0F040000 */  sync.p
    /* 2B00F4 003B00F4 00000000 */  nop
  .L003B00F8:
    /* 2B00F8 003B00F8 00000000 */  nop
    /* 2B00FC 003B00FC 00000000 */  nop
    /* 2B0100 003B0100 00000000 */  nop
    /* 2B0104 003B0104 00000000 */  nop
    /* 2B0108 003B0108 00000000 */  nop
    /* 2B010C 003B010C FAFF0041 */  bc0f       .L003B00F8 /* handwritten instruction */
    /* 2B0110 003B0110 00000000 */   nop
    /* 2B0114 003B0114 00000000 */  nop
  .L003B0118:
    /* 2B0118 003B0118 00D4838C */  lw         $3, -0x2C00($4)
    /* 2B011C 003B011C 00016330 */  andi       $3, $3, 0x100
    /* 2B0120 003B0120 00000000 */  nop
    /* 2B0124 003B0124 00000000 */  nop
    /* 2B0128 003B0128 00000000 */  nop
    /* 2B012C 003B012C FAFF6014 */  bnez       $3, .L003B0118
    /* 2B0130 003B0130 00000000 */   nop
    /* 2B0134 003B0134 00000000 */  nop
  .L003B0138:
    /* 2B0138 003B0138 10E08DAC */  sw         $13, -0x1FF0($4)
    /* 2B013C 003B013C 40130324 */  addiu      $3, $0, 0x1340
    /* 2B0140 003B0140 80D083AC */  sw         $3, -0x2F80($4)
    /* 2B0144 003B0144 10D091AC */  sw         $17, -0x2FF0($4)
    /* 2B0148 003B0148 20D08AAC */  sw         $10, -0x2FE0($4)
    /* 2B014C 003B014C 00D08DAC */  sw         $13, -0x3000($4)
    /* 2B0150 003B0150 0F000000 */  sync
    /* 2B0154 003B0154 0F040000 */  sync.p
    /* 2B0158 003B0158 50FFF726 */  addiu      $23, $23, -0xB0
    /* 2B015C 003B015C 000B7326 */  addiu      $19, $19, 0xB00
    /* 2B0160 003B0160 B000E12A */  slti       $1, $23, 0xB0
    /* 2B0164 003B0164 002C3126 */  addiu      $17, $17, 0x2C00
    /* 2B0168 003B0168 C0025226 */  addiu      $18, $18, 0x2C0
    /* 2B016C 003B016C E3FE2010 */  beqz       $1, .L003AFCFC
    /* 2B0170 003B0170 80051026 */   addiu     $16, $16, 0x580
    /* 2B0174 003B0174 00000000 */  nop
  .L003B0178:
    /* 2B0178 003B0178 0400E12A */  slti       $1, $23, 0x4
    /* 2B017C 003B017C 48012014 */  bnez       $1, .L003B06A0
    /* 2B0180 003B0180 00000000 */   nop
    /* 2B0184 003B0184 0300E106 */  bgez       $23, .L003B0194
    /* 2B0188 003B0188 83181700 */   sra       $3, $23, 2
    /* 2B018C 003B018C 0300E326 */  addiu      $3, $23, 0x3
    /* 2B0190 003B0190 83180300 */  sra        $3, $3, 2
  .L003B0194:
    /* 2B0194 003B0194 0110043C */  lui        $4, (0x10010000 >> 16)
    /* 2B0198 003B0198 00D0858C */  lw         $5, -0x3000($4)
    /* 2B019C 003B019C 0001A530 */  andi       $5, $5, 0x100
    /* 2B01A0 003B01A0 0C00A010 */  beqz       $5, .L003B01D4
    /* 2B01A4 003B01A4 80180300 */   sll       $3, $3, 2
    /* 2B01A8 003B01A8 00010524 */  addiu      $5, $0, 0x100
    /* 2B01AC 003B01AC 20E085AC */  sw         $5, -0x1FE0($4)
    /* 2B01B0 003B01B0 0F000000 */  sync
    /* 2B01B4 003B01B4 0F040000 */  sync.p
  .L003B01B8:
    /* 2B01B8 003B01B8 00000000 */  nop
    /* 2B01BC 003B01BC 00000000 */  nop
    /* 2B01C0 003B01C0 00000000 */  nop
    /* 2B01C4 003B01C4 00000000 */  nop
    /* 2B01C8 003B01C8 00000000 */  nop
    /* 2B01CC 003B01CC FAFF0041 */  bc0f       .L003B01B8 /* handwritten instruction */
    /* 2B01D0 003B01D0 00000000 */   nop
  .L003B01D4:
    /* 2B01D4 003B01D4 0110043C */  lui        $4, (0x10010000 >> 16)
    /* 2B01D8 003B01D8 00D4858C */  lw         $5, -0x2C00($4)
    /* 2B01DC 003B01DC 0001A530 */  andi       $5, $5, 0x100
    /* 2B01E0 003B01E0 1500A010 */  beqz       $5, .L003B0238
    /* 2B01E4 003B01E4 00000000 */   nop
    /* 2B01E8 003B01E8 00020524 */  addiu      $5, $0, 0x200
    /* 2B01EC 003B01EC 20E085AC */  sw         $5, -0x1FE0($4)
    /* 2B01F0 003B01F0 0F000000 */  sync
    /* 2B01F4 003B01F4 0F040000 */  sync.p
  .L003B01F8:
    /* 2B01F8 003B01F8 00000000 */  nop
    /* 2B01FC 003B01FC 00000000 */  nop
    /* 2B0200 003B0200 00000000 */  nop
    /* 2B0204 003B0204 00000000 */  nop
    /* 2B0208 003B0208 00000000 */  nop
    /* 2B020C 003B020C FAFF0041 */  bc0f       .L003B01F8 /* handwritten instruction */
    /* 2B0210 003B0210 00000000 */   nop
    /* 2B0214 003B0214 0110043C */  lui        $4, (0x10010000 >> 16)
  .L003B0218:
    /* 2B0218 003B0218 00D4858C */  lw         $5, -0x2C00($4)
    /* 2B021C 003B021C 0001A530 */  andi       $5, $5, 0x100
    /* 2B0220 003B0220 00000000 */  nop
    /* 2B0224 003B0224 00000000 */  nop
    /* 2B0228 003B0228 00000000 */  nop
    /* 2B022C 003B022C FAFFA014 */  bnez       $5, .L003B0218
    /* 2B0230 003B0230 00000000 */   nop
    /* 2B0234 003B0234 00000000 */  nop
  .L003B0238:
    /* 2B0238 003B0238 00020524 */  addiu      $5, $0, 0x200
    /* 2B023C 003B023C 0110043C */  lui        $4, (0x10010000 >> 16)
    /* 2B0240 003B0240 83300300 */  sra        $6, $3, 2
    /* 2B0244 003B0244 10E085AC */  sw         $5, -0x1FF0($4)
    /* 2B0248 003B0248 80D480AC */  sw         $0, -0x2B80($4)
    /* 2B024C 003B024C 03006104 */  bgez       $3, .L003B025C
    /* 2B0250 003B0250 10D492AC */   sw        $18, -0x2BF0($4)
    /* 2B0254 003B0254 03006424 */  addiu      $4, $3, 0x3
    /* 2B0258 003B0258 83300400 */  sra        $6, $4, 2
  .L003B025C:
    /* 2B025C 003B025C 0110043C */  lui        $4, (0x10010000 >> 16)
    /* 2B0260 003B0260 00010524 */  addiu      $5, $0, 0x100
    /* 2B0264 003B0264 20D486AC */  sw         $6, -0x2BE0($4)
    /* 2B0268 003B0268 00D485AC */  sw         $5, -0x2C00($4)
    /* 2B026C 003B026C 0F000000 */  sync
    /* 2B0270 003B0270 0F040000 */  sync.p
    /* 2B0274 003B0274 00D4858C */  lw         $5, -0x2C00($4)
    /* 2B0278 003B0278 0001A530 */  andi       $5, $5, 0x100
    /* 2B027C 003B027C 1400A010 */  beqz       $5, .L003B02D0
    /* 2B0280 003B0280 00000000 */   nop
    /* 2B0284 003B0284 00020524 */  addiu      $5, $0, 0x200
    /* 2B0288 003B0288 20E085AC */  sw         $5, -0x1FE0($4)
    /* 2B028C 003B028C 0F000000 */  sync
    /* 2B0290 003B0290 0F040000 */  sync.p
  .L003B0294:
    /* 2B0294 003B0294 00000000 */  nop
    /* 2B0298 003B0298 00000000 */  nop
    /* 2B029C 003B029C 00000000 */  nop
    /* 2B02A0 003B02A0 00000000 */  nop
    /* 2B02A4 003B02A4 00000000 */  nop
    /* 2B02A8 003B02A8 FAFF0041 */  bc0f       .L003B0294 /* handwritten instruction */
    /* 2B02AC 003B02AC 00000000 */   nop
    /* 2B02B0 003B02B0 0110043C */  lui        $4, (0x10010000 >> 16)
  .L003B02B4:
    /* 2B02B4 003B02B4 00D4858C */  lw         $5, -0x2C00($4)
    /* 2B02B8 003B02B8 0001A530 */  andi       $5, $5, 0x100
    /* 2B02BC 003B02BC 00000000 */  nop
    /* 2B02C0 003B02C0 00000000 */  nop
    /* 2B02C4 003B02C4 00000000 */  nop
    /* 2B02C8 003B02C8 FAFFA014 */  bnez       $5, .L003B02B4
    /* 2B02CC 003B02CC 00000000 */   nop
  .L003B02D0:
    /* 2B02D0 003B02D0 00020624 */  addiu      $6, $0, 0x200
    /* 2B02D4 003B02D4 0110043C */  lui        $4, (0x10010000 >> 16)
    /* 2B02D8 003B02D8 C0020524 */  addiu      $5, $0, 0x2C0
    /* 2B02DC 003B02DC 10E086AC */  sw         $6, -0x1FF0($4)
    /* 2B02E0 003B02E0 80D485AC */  sw         $5, -0x2B80($4)
    /* 2B02E4 003B02E4 43300300 */  sra        $6, $3, 1
    /* 2B02E8 003B02E8 03006104 */  bgez       $3, .L003B02F8
    /* 2B02EC 003B02EC 10D490AC */   sw        $16, -0x2BF0($4)
    /* 2B02F0 003B02F0 01006424 */  addiu      $4, $3, 0x1
    /* 2B02F4 003B02F4 43300400 */  sra        $6, $4, 1
  .L003B02F8:
    /* 2B02F8 003B02F8 0110043C */  lui        $4, (0x10010000 >> 16)
    /* 2B02FC 003B02FC 00010524 */  addiu      $5, $0, 0x100
    /* 2B0300 003B0300 20D486AC */  sw         $6, -0x2BE0($4)
    /* 2B0304 003B0304 00D485AC */  sw         $5, -0x2C00($4)
    /* 2B0308 003B0308 0F000000 */  sync
    /* 2B030C 003B030C 0F040000 */  sync.p
    /* 2B0310 003B0310 00D4858C */  lw         $5, -0x2C00($4)
    /* 2B0314 003B0314 0001A530 */  andi       $5, $5, 0x100
    /* 2B0318 003B0318 1500A010 */  beqz       $5, .L003B0370
    /* 2B031C 003B031C 00000000 */   nop
    /* 2B0320 003B0320 00020524 */  addiu      $5, $0, 0x200
    /* 2B0324 003B0324 20E085AC */  sw         $5, -0x1FE0($4)
    /* 2B0328 003B0328 0F000000 */  sync
    /* 2B032C 003B032C 0F040000 */  sync.p
  .L003B0330:
    /* 2B0330 003B0330 00000000 */  nop
    /* 2B0334 003B0334 00000000 */  nop
    /* 2B0338 003B0338 00000000 */  nop
    /* 2B033C 003B033C 00000000 */  nop
    /* 2B0340 003B0340 00000000 */  nop
    /* 2B0344 003B0344 FAFF0041 */  bc0f       .L003B0330 /* handwritten instruction */
    /* 2B0348 003B0348 00000000 */   nop
    /* 2B034C 003B034C 0110043C */  lui        $4, (0x10010000 >> 16)
  .L003B0350:
    /* 2B0350 003B0350 00D4858C */  lw         $5, -0x2C00($4)
    /* 2B0354 003B0354 0001A530 */  andi       $5, $5, 0x100
    /* 2B0358 003B0358 00000000 */  nop
    /* 2B035C 003B035C 00000000 */  nop
    /* 2B0360 003B0360 00000000 */  nop
    /* 2B0364 003B0364 FAFFA014 */  bnez       $5, .L003B0350
    /* 2B0368 003B0368 00000000 */   nop
    /* 2B036C 003B036C 00000000 */  nop
  .L003B0370:
    /* 2B0370 003B0370 00020724 */  addiu      $7, $0, 0x200
    /* 2B0374 003B0374 0110043C */  lui        $4, (0x10010000 >> 16)
    /* 2B0378 003B0378 40080624 */  addiu      $6, $0, 0x840
    /* 2B037C 003B037C 10E087AC */  sw         $7, -0x1FF0($4)
    /* 2B0380 003B0380 00010524 */  addiu      $5, $0, 0x100
    /* 2B0384 003B0384 80D486AC */  sw         $6, -0x2B80($4)
    /* 2B0388 003B0388 10D493AC */  sw         $19, -0x2BF0($4)
    /* 2B038C 003B038C 20D483AC */  sw         $3, -0x2BE0($4)
    /* 2B0390 003B0390 00D485AC */  sw         $5, -0x2C00($4)
    /* 2B0394 003B0394 0F000000 */  sync
    /* 2B0398 003B0398 0F040000 */  sync.p
    /* 2B039C 003B039C 00D4858C */  lw         $5, -0x2C00($4)
    /* 2B03A0 003B03A0 0001A530 */  andi       $5, $5, 0x100
    /* 2B03A4 003B03A4 1400A010 */  beqz       $5, .L003B03F8
    /* 2B03A8 003B03A8 00000000 */   nop
    /* 2B03AC 003B03AC 20E087AC */  sw         $7, -0x1FE0($4)
    /* 2B03B0 003B03B0 0F000000 */  sync
    /* 2B03B4 003B03B4 0F040000 */  sync.p
  .L003B03B8:
    /* 2B03B8 003B03B8 00000000 */  nop
    /* 2B03BC 003B03BC 00000000 */  nop
    /* 2B03C0 003B03C0 00000000 */  nop
    /* 2B03C4 003B03C4 00000000 */  nop
    /* 2B03C8 003B03C8 00000000 */  nop
    /* 2B03CC 003B03CC FAFF0041 */  bc0f       .L003B03B8 /* handwritten instruction */
    /* 2B03D0 003B03D0 00000000 */   nop
    /* 2B03D4 003B03D4 0110043C */  lui        $4, (0x10010000 >> 16)
  .L003B03D8:
    /* 2B03D8 003B03D8 00D4858C */  lw         $5, -0x2C00($4)
    /* 2B03DC 003B03DC 0001A530 */  andi       $5, $5, 0x100
    /* 2B03E0 003B03E0 00000000 */  nop
    /* 2B03E4 003B03E4 00000000 */  nop
    /* 2B03E8 003B03E8 00000000 */  nop
    /* 2B03EC 003B03EC FAFFA014 */  bnez       $5, .L003B03D8
    /* 2B03F0 003B03F0 00000000 */   nop
    /* 2B03F4 003B03F4 00000000 */  nop
  .L003B03F8:
    /* 2B03F8 003B03F8 0070073C */  lui        $7, (0x70001340 >> 16)
    /* 2B03FC 003B03FC 2A080300 */  slt        $1, $0, $3
    /* 2B0400 003B0400 C002F434 */  ori        $20, $7, (0x700002C0 & 0xFFFF)
    /* 2B0404 003B0404 4008F934 */  ori        $25, $7, (0x70000840 & 0xFFFF)
    /* 2B0408 003B0408 4013F834 */  ori        $24, $7, (0x70001340 & 0xFFFF)
    /* 2B040C 003B040C 60002010 */  beqz       $1, .L003B0590
    /* 2B0410 003B0410 2D300000 */   daddu     $6, $0, $0
    /* 2B0414 003B0414 0100053C */  lui        $5, (0x10000 >> 16)
  .L003B0418:
    /* 2B0418 003B0418 0000E0C4 */  lwc1       $f0, (0x70000000 & 0xFFFF)($7)
    /* 2B041C 003B041C 0000E0E5 */  swc1       $f0, 0x0($15)
    /* 2B0420 003B0420 0400E0C4 */  lwc1       $f0, (0x70000004 & 0xFFFF)($7)
    /* 2B0424 003B0424 0400E0E5 */  swc1       $f0, 0x4($15)
    /* 2B0428 003B0428 0000E0C4 */  lwc1       $f0, (0x70000000 & 0xFFFF)($7)
    /* 2B042C 003B042C 0800E0E5 */  swc1       $f0, 0x8($15)
    /* 2B0430 003B0430 0400E0C4 */  lwc1       $f0, (0x70000004 & 0xFFFF)($7)
    /* 2B0434 003B0434 0C00E0E5 */  swc1       $f0, 0xC($15)
  .L003B0438:
    /* 2B0438 003B0438 39000042 */  di /* handwritten instruction */
    /* 2B043C 003B043C 0F040000 */  sync.p
    /* 2B0440 003B0440 00600440 */  mfc0       $4, $12 /* handwritten instruction */
    /* 2B0444 003B0444 24208500 */  and        $4, $4, $5
    /* 2B0448 003B0448 00000000 */  nop
    /* 2B044C 003B044C FAFF8014 */  bnez       $4, .L003B0438
    /* 2B0450 003B0450 00000000 */   nop
    /* 2B0454 003B0454 0000E1D9 */  lqc2       $vf1, 0x0($15)
    /* 2B0458 003B0458 FD09874B */  vabs.xy    $vf7, $vf1
    /* 2B045C 003B045C 3C00EA4B */  vaddax.xyzw $ACC, $vf0, $vf10x
    /* 2B0460 003B0460 CF39804B */  vmsubw.xy  $vf7, $vf7, $vf0w
    /* 2B0464 003B0464 3D00CA4B */  vadday.xyz $ACC, $vf0, $vf10y
    /* 2B0468 003B0468 3E002A4A */  vaddaz.w   $ACC, $vf0, $vf10z
    /* 2B046C 003B046C 8F08604A */  vmsubw.zw  $vf2, $vf1, $vf0w
    /* 2B0470 003B0470 3C00CB4B */  vaddax.xyz $ACC, $vf0, $vf11x
    /* 2B0474 003B0474 3D002B4A */  vadday.w   $ACC, $vf0, $vf11y
    /* 2B0478 003B0478 CF08604A */  vmsubw.zw  $vf3, $vf1, $vf0w
    /* 2B047C 003B047C AF08624A */  vmini.zw   $vf2, $vf1, $vf2
    /* 2B0480 003B0480 EB11634A */  vmax.zw    $vf7, $vf2, $vf3
    /* 2B0484 003B0484 AA38E74B */  vmul.xyzw  $vf2, $vf7, $vf7
    /* 2B0488 003B0488 9A39EB4B */  vmulz.xyzw $vf6, $vf7, $vf11z
    /* 2B048C 003B048C 1839EC4B */  vmulx.xyzw $vf4, $vf7, $vf12x
    /* 2B0490 003B0490 5939EC4B */  vmuly.xyzw $vf5, $vf7, $vf12y
    /* 2B0494 003B0494 EA10E24B */  vmul.xyzw  $vf3, $vf2, $vf2
    /* 2B0498 003B0498 AA31E24B */  vmul.xyzw  $vf6, $vf6, $vf2
    /* 2B049C 003B049C BE22E24B */  vmula.xyzw $ACC, $vf4, $vf2
    /* 2B04A0 003B04A0 1A39EC4B */  vmulz.xyzw $vf4, $vf7, $vf12z
    /* 2B04A4 003B04A4 AA18E34B */  vmul.xyzw  $vf2, $vf3, $vf3
    /* 2B04A8 003B04A8 BD32E34B */  vmadda.xyzw $ACC, $vf6, $vf3
    /* 2B04AC 003B04AC BD2AE34B */  vmadda.xyzw $ACC, $vf5, $vf3
    /* 2B04B0 003B04B0 BC38ED4B */  vmaddax.xyzw $ACC, $vf7, $vf13x
    /* 2B04B4 003B04B4 E921E24B */  vmadd.xyzw $vf7, $vf4, $vf2
    /* 2B04B8 003B04B8 000034DB */  lqc2       $vf20, 0x0($25)
    /* 2B04BC 003B04BC 10003BDB */  lqc2       $vf27, 0x10($25)
    /* 2B04C0 003B04C0 00008EDA */  lqc2       $vf14, 0x0($20)
    /* 2B04C4 003B04C4 BC41E74B */  vmulax.xyzw $ACC, $vf8, $vf7x
    /* 2B04C8 003B04C8 8E4CE74B */  vmsubz.xyzw $vf18, $vf9, $vf7z
    /* 2B04CC 003B04CC A878EE4B */  vadd.xyzw  $vf2, $vf15, $vf14
    /* 2B04D0 003B04D0 EC78EE4B */  vsub.xyzw  $vf3, $vf15, $vf14
    /* 2B04D4 003B04D4 BC49E74B */  vmulax.xyzw $ACC, $vf9, $vf7x
    /* 2B04D8 003B04D8 CA44E74B */  vmaddz.xyzw $vf19, $vf8, $vf7z
    /* 2B04DC 003B04DC BD41E74B */  vmulay.xyzw $ACC, $vf8, $vf7y
    /* 2B04E0 003B04E0 4F4EE74B */  vmsubw.xyzw $vf25, $vf9, $vf7w
    /* 2B04E4 003B04E4 BD49E74B */  vmulay.xyzw $ACC, $vf9, $vf7y
    /* 2B04E8 003B04E8 8B46E74B */  vmaddw.xyzw $vf26, $vf8, $vf7w
    /* 2B04EC 003B04EC BC91E34B */  vmulax.xyzw $ACC, $vf18, $vf3x
    /* 2B04F0 003B04F0 499DE34B */  vmaddy.xyzw $vf21, $vf19, $vf3y
    /* 2B04F4 003B04F4 BC91E24B */  vmulax.xyzw $ACC, $vf18, $vf2x
    /* 2B04F8 003B04F8 899DE34B */  vmaddy.xyzw $vf22, $vf19, $vf3y
    /* 2B04FC 003B04FC BC91E24B */  vmulax.xyzw $ACC, $vf18, $vf2x
    /* 2B0500 003B0500 C99DE24B */  vmaddy.xyzw $vf23, $vf19, $vf2y
    /* 2B0504 003B0504 BC91E34B */  vmulax.xyzw $ACC, $vf18, $vf3x
    /* 2B0508 003B0508 099EE24B */  vmaddy.xyzw $vf24, $vf19, $vf2y
    /* 2B050C 003B050C BEC9E34B */  vmulaz.xyzw $ACC, $vf25, $vf3z
    /* 2B0510 003B0510 0BD7E34B */  vmaddw.xyzw $vf28, $vf26, $vf3w
    /* 2B0514 003B0514 BEC9E24B */  vmulaz.xyzw $ACC, $vf25, $vf2z
    /* 2B0518 003B0518 4BD7E34B */  vmaddw.xyzw $vf29, $vf26, $vf3w
    /* 2B051C 003B051C BEC9E24B */  vmulaz.xyzw $ACC, $vf25, $vf2z
    /* 2B0520 003B0520 8BD7E24B */  vmaddw.xyzw $vf30, $vf26, $vf2w
    /* 2B0524 003B0524 BEC9E34B */  vmulaz.xyzw $ACC, $vf25, $vf3z
    /* 2B0528 003B0528 CBD7E24B */  vmaddw.xyzw $vf31, $vf26, $vf2w
    /* 2B052C 003B052C 68ADF44B */  vadd.xyzw  $vf21, $vf21, $vf20
    /* 2B0530 003B0530 A8B5F44B */  vadd.xyzw  $vf22, $vf22, $vf20
    /* 2B0534 003B0534 E8BDF44B */  vadd.xyzw  $vf23, $vf23, $vf20
    /* 2B0538 003B0538 28C6F44B */  vadd.xyzw  $vf24, $vf24, $vf20
    /* 2B053C 003B053C 28E7FB4B */  vadd.xyzw  $vf28, $vf28, $vf27
    /* 2B0540 003B0540 68EFFB4B */  vadd.xyzw  $vf29, $vf29, $vf27
    /* 2B0544 003B0544 A8F7FB4B */  vadd.xyzw  $vf30, $vf30, $vf27
    /* 2B0548 003B0548 E8FFFB4B */  vadd.xyzw  $vf31, $vf31, $vf27
    /* 2B054C 003B054C 000015FB */  sqc2       $vf21, 0x0($24)
    /* 2B0550 003B0550 100016FB */  sqc2       $vf22, 0x10($24)
    /* 2B0554 003B0554 200017FB */  sqc2       $vf23, 0x20($24)
    /* 2B0558 003B0558 300018FB */  sqc2       $vf24, 0x30($24)
    /* 2B055C 003B055C 40001CFB */  sqc2       $vf28, 0x40($24)
    /* 2B0560 003B0560 50001DFB */  sqc2       $vf29, 0x50($24)
    /* 2B0564 003B0564 60001EFB */  sqc2       $vf30, 0x60($24)
    /* 2B0568 003B0568 70001FFB */  sqc2       $vf31, 0x70($24)
    /* 2B056C 003B056C 38000042 */  ei /* handwritten instruction */
    /* 2B0570 003B0570 0200C624 */  addiu      $6, $6, 0x2
    /* 2B0574 003B0574 2A20C300 */  slt        $4, $6, $3
    /* 2B0578 003B0578 20003927 */  addiu      $25, $25, 0x20
    /* 2B057C 003B057C 10009426 */  addiu      $20, $20, 0x10
    /* 2B0580 003B0580 0800E724 */  addiu      $7, $7, %lo(D_70000008)
    /* 2B0584 003B0584 A4FF8014 */  bnez       $4, .L003B0418
    /* 2B0588 003B0588 80001827 */   addiu     $24, $24, 0x80
    /* 2B058C 003B058C 00000000 */  nop
  .L003B0590:
    /* 2B0590 003B0590 0110043C */  lui        $4, (0x10010000 >> 16)
    /* 2B0594 003B0594 00D0858C */  lw         $5, -0x3000($4)
    /* 2B0598 003B0598 0001A530 */  andi       $5, $5, 0x100
    /* 2B059C 003B059C 0C00A010 */  beqz       $5, .L003B05D0
    /* 2B05A0 003B05A0 00000000 */   nop
    /* 2B05A4 003B05A4 00010524 */  addiu      $5, $0, 0x100
    /* 2B05A8 003B05A8 20E085AC */  sw         $5, -0x1FE0($4)
    /* 2B05AC 003B05AC 0F000000 */  sync
    /* 2B05B0 003B05B0 0F040000 */  sync.p
  .L003B05B4:
    /* 2B05B4 003B05B4 00000000 */  nop
    /* 2B05B8 003B05B8 00000000 */  nop
    /* 2B05BC 003B05BC 00000000 */  nop
    /* 2B05C0 003B05C0 00000000 */  nop
    /* 2B05C4 003B05C4 00000000 */  nop
    /* 2B05C8 003B05C8 FAFF0041 */  bc0f       .L003B05B4 /* handwritten instruction */
    /* 2B05CC 003B05CC 00000000 */   nop
  .L003B05D0:
    /* 2B05D0 003B05D0 0110043C */  lui        $4, (0x10010000 >> 16)
    /* 2B05D4 003B05D4 00D4858C */  lw         $5, -0x2C00($4)
    /* 2B05D8 003B05D8 0001A530 */  andi       $5, $5, 0x100
    /* 2B05DC 003B05DC 1400A010 */  beqz       $5, .L003B0630
    /* 2B05E0 003B05E0 00000000 */   nop
    /* 2B05E4 003B05E4 00020524 */  addiu      $5, $0, 0x200
    /* 2B05E8 003B05E8 20E085AC */  sw         $5, -0x1FE0($4)
    /* 2B05EC 003B05EC 0F000000 */  sync
    /* 2B05F0 003B05F0 0F040000 */  sync.p
  .L003B05F4:
    /* 2B05F4 003B05F4 00000000 */  nop
    /* 2B05F8 003B05F8 00000000 */  nop
    /* 2B05FC 003B05FC 00000000 */  nop
    /* 2B0600 003B0600 00000000 */  nop
    /* 2B0604 003B0604 00000000 */  nop
    /* 2B0608 003B0608 FAFF0041 */  bc0f       .L003B05F4 /* handwritten instruction */
    /* 2B060C 003B060C 00000000 */   nop
    /* 2B0610 003B0610 0110043C */  lui        $4, (0x10010000 >> 16)
  .L003B0614:
    /* 2B0614 003B0614 00D4858C */  lw         $5, -0x2C00($4)
    /* 2B0618 003B0618 0001A530 */  andi       $5, $5, 0x100
    /* 2B061C 003B061C 00000000 */  nop
    /* 2B0620 003B0620 00000000 */  nop
    /* 2B0624 003B0624 00000000 */  nop
    /* 2B0628 003B0628 FAFFA014 */  bnez       $5, .L003B0614
    /* 2B062C 003B062C 00000000 */   nop
  .L003B0630:
    /* 2B0630 003B0630 00010724 */  addiu      $7, $0, 0x100
    /* 2B0634 003B0634 0110043C */  lui        $4, (0x10010000 >> 16)
    /* 2B0638 003B0638 40130624 */  addiu      $6, $0, 0x1340
    /* 2B063C 003B063C 10E087AC */  sw         $7, -0x1FF0($4)
    /* 2B0640 003B0640 80280300 */  sll        $5, $3, 2
    /* 2B0644 003B0644 80D086AC */  sw         $6, -0x2F80($4)
    /* 2B0648 003B0648 10D091AC */  sw         $17, -0x2FF0($4)
    /* 2B064C 003B064C 20D085AC */  sw         $5, -0x2FE0($4)
    /* 2B0650 003B0650 00D087AC */  sw         $7, -0x3000($4)
    /* 2B0654 003B0654 0F000000 */  sync
    /* 2B0658 003B0658 0F040000 */  sync.p
    /* 2B065C 003B065C 00210500 */  sll        $4, $5, 4
    /* 2B0660 003B0660 00290300 */  sll        $5, $3, 4
    /* 2B0664 003B0664 21882402 */  addu       $17, $17, $4
    /* 2B0668 003B0668 21986502 */  addu       $19, $19, $5
    /* 2B066C 003B066C 03006104 */  bgez       $3, .L003B067C
    /* 2B0670 003B0670 83200300 */   sra       $4, $3, 2
    /* 2B0674 003B0674 03006424 */  addiu      $4, $3, 0x3
    /* 2B0678 003B0678 83200400 */  sra        $4, $4, 2
  .L003B067C:
    /* 2B067C 003B067C 00290400 */  sll        $5, $4, 4
    /* 2B0680 003B0680 43200300 */  sra        $4, $3, 1
    /* 2B0684 003B0684 03006104 */  bgez       $3, .L003B0694
    /* 2B0688 003B0688 21904502 */   addu      $18, $18, $5
    /* 2B068C 003B068C 01006424 */  addiu      $4, $3, 0x1
    /* 2B0690 003B0690 43200400 */  sra        $4, $4, 1
  .L003B0694:
    /* 2B0694 003B0694 00210400 */  sll        $4, $4, 4
    /* 2B0698 003B0698 23B8E302 */  subu       $23, $23, $3
    /* 2B069C 003B069C 21800402 */  addu       $16, $16, $4
  .L003B06A0:
    /* 2B06A0 003B06A0 2A081700 */  slt        $1, $0, $23
    /* 2B06A4 003B06A4 2A012010 */  beqz       $1, .L003B0B50
    /* 2B06A8 003B06A8 2D300000 */   daddu     $6, $0, $0
    /* 2B06AC 003B06AC A000A37B */  lq         $3, 0xA0($29)
    /* 2B06B0 003B06B0 0100053C */  lui        $5, (0x10000 >> 16)
    /* 2B06B4 003B06B4 80200300 */  sll        $4, $3, 2
  .L003B06B8:
    /* 2B06B8 003B06B8 000040C6 */  lwc1       $f0, 0x0($18)
    /* 2B06BC 003B06BC E000A38F */  lw         $3, 0xE0($29)
    /* 2B06C0 003B06C0 0000E0E5 */  swc1       $f0, 0x0($15)
    /* 2B06C4 003B06C4 000040C6 */  lwc1       $f0, 0x0($18)
    /* 2B06C8 003B06C8 0800E0E5 */  swc1       $f0, 0x8($15)
    /* 2B06CC 003B06CC 000000C6 */  lwc1       $f0, 0x0($16)
    /* 2B06D0 003B06D0 000060E4 */  swc1       $f0, 0x0($3)
    /* 2B06D4 003B06D4 040000C6 */  lwc1       $f0, 0x4($16)
    /* 2B06D8 003B06D8 040060E4 */  swc1       $f0, 0x4($3)
    /* 2B06DC 003B06DC 00000000 */  nop
  .L003B06E0:
    /* 2B06E0 003B06E0 39000042 */  di /* handwritten instruction */
    /* 2B06E4 003B06E4 0F040000 */  sync.p
    /* 2B06E8 003B06E8 00600340 */  mfc0       $3, $12 /* handwritten instruction */
    /* 2B06EC 003B06EC 24186500 */  and        $3, $3, $5
    /* 2B06F0 003B06F0 00000000 */  nop
    /* 2B06F4 003B06F4 FAFF6014 */  bnez       $3, .L003B06E0
    /* 2B06F8 003B06F8 00000000 */   nop
    /* 2B06FC 003B06FC 0000E1D9 */  lqc2       $vf1, 0x0($15)
    /* 2B0700 003B0700 FD09874B */  vabs.xy    $vf7, $vf1
    /* 2B0704 003B0704 3C00EA4B */  vaddax.xyzw $ACC, $vf0, $vf10x
    /* 2B0708 003B0708 CF39804B */  vmsubw.xy  $vf7, $vf7, $vf0w
    /* 2B070C 003B070C 3D00CA4B */  vadday.xyz $ACC, $vf0, $vf10y
    /* 2B0710 003B0710 3E002A4A */  vaddaz.w   $ACC, $vf0, $vf10z
    /* 2B0714 003B0714 8F08604A */  vmsubw.zw  $vf2, $vf1, $vf0w
    /* 2B0718 003B0718 3C00CB4B */  vaddax.xyz $ACC, $vf0, $vf11x
    /* 2B071C 003B071C 3D002B4A */  vadday.w   $ACC, $vf0, $vf11y
    /* 2B0720 003B0720 CF08604A */  vmsubw.zw  $vf3, $vf1, $vf0w
    /* 2B0724 003B0724 AF08624A */  vmini.zw   $vf2, $vf1, $vf2
    /* 2B0728 003B0728 EB11634A */  vmax.zw    $vf7, $vf2, $vf3
    /* 2B072C 003B072C AA38E74B */  vmul.xyzw  $vf2, $vf7, $vf7
    /* 2B0730 003B0730 9A39EB4B */  vmulz.xyzw $vf6, $vf7, $vf11z
    /* 2B0734 003B0734 1839EC4B */  vmulx.xyzw $vf4, $vf7, $vf12x
    /* 2B0738 003B0738 5939EC4B */  vmuly.xyzw $vf5, $vf7, $vf12y
    /* 2B073C 003B073C EA10E24B */  vmul.xyzw  $vf3, $vf2, $vf2
    /* 2B0740 003B0740 AA31E24B */  vmul.xyzw  $vf6, $vf6, $vf2
    /* 2B0744 003B0744 BE22E24B */  vmula.xyzw $ACC, $vf4, $vf2
    /* 2B0748 003B0748 1A39EC4B */  vmulz.xyzw $vf4, $vf7, $vf12z
    /* 2B074C 003B074C AA18E34B */  vmul.xyzw  $vf2, $vf3, $vf3
    /* 2B0750 003B0750 BD32E34B */  vmadda.xyzw $ACC, $vf6, $vf3
    /* 2B0754 003B0754 BD2AE34B */  vmadda.xyzw $ACC, $vf5, $vf3
    /* 2B0758 003B0758 BC38ED4B */  vmaddax.xyzw $ACC, $vf7, $vf13x
    /* 2B075C 003B075C E921E24B */  vmadd.xyzw $vf7, $vf4, $vf2
    /* 2B0760 003B0760 000074DA */  lqc2       $vf20, 0x0($19)
    /* 2B0764 003B0764 E000A38F */  lw         $3, 0xE0($29)
    /* 2B0768 003B0768 00006ED8 */  lqc2       $vf14, 0x0($3)
    /* 2B076C 003B076C BC41E74B */  vmulax.xyzw $ACC, $vf8, $vf7x
    /* 2B0770 003B0770 8E4CE74B */  vmsubz.xyzw $vf18, $vf9, $vf7z
    /* 2B0774 003B0774 A878EE4B */  vadd.xyzw  $vf2, $vf15, $vf14
    /* 2B0778 003B0778 EC78EE4B */  vsub.xyzw  $vf3, $vf15, $vf14
    /* 2B077C 003B077C BC49E74B */  vmulax.xyzw $ACC, $vf9, $vf7x
    /* 2B0780 003B0780 CA44E74B */  vmaddz.xyzw $vf19, $vf8, $vf7z
    /* 2B0784 003B0784 BC91E34B */  vmulax.xyzw $ACC, $vf18, $vf3x
    /* 2B0788 003B0788 499DE34B */  vmaddy.xyzw $vf21, $vf19, $vf3y
    /* 2B078C 003B078C BC91E24B */  vmulax.xyzw $ACC, $vf18, $vf2x
    /* 2B0790 003B0790 899DE34B */  vmaddy.xyzw $vf22, $vf19, $vf3y
    /* 2B0794 003B0794 BC91E24B */  vmulax.xyzw $ACC, $vf18, $vf2x
    /* 2B0798 003B0798 C99DE24B */  vmaddy.xyzw $vf23, $vf19, $vf2y
    /* 2B079C 003B079C BC91E34B */  vmulax.xyzw $ACC, $vf18, $vf3x
    /* 2B07A0 003B07A0 099EE24B */  vmaddy.xyzw $vf24, $vf19, $vf2y
    /* 2B07A4 003B07A4 68ADF44B */  vadd.xyzw  $vf21, $vf21, $vf20
    /* 2B07A8 003B07A8 A8B5F44B */  vadd.xyzw  $vf22, $vf22, $vf20
    /* 2B07AC 003B07AC E8BDF44B */  vadd.xyzw  $vf23, $vf23, $vf20
    /* 2B07B0 003B07B0 28C6F44B */  vadd.xyzw  $vf24, $vf24, $vf20
    /* 2B07B4 003B07B4 000035FA */  sqc2       $vf21, 0x0($17)
    /* 2B07B8 003B07B8 100036FA */  sqc2       $vf22, 0x10($17)
    /* 2B07BC 003B07BC 200037FA */  sqc2       $vf23, 0x20($17)
    /* 2B07C0 003B07C0 300038FA */  sqc2       $vf24, 0x30($17)
    /* 2B07C4 003B07C4 38000042 */  ei /* handwritten instruction */
    /* 2B07C8 003B07C8 0100C624 */  addiu      $6, $6, 0x1
    /* 2B07CC 003B07CC D000A37B */  lq         $3, 0xD0($29)
    /* 2B07D0 003B07D0 21986302 */  addu       $19, $19, $3
    /* 2B07D4 003B07D4 B000A37B */  lq         $3, 0xB0($29)
    /* 2B07D8 003B07D8 21800302 */  addu       $16, $16, $3
    /* 2B07DC 003B07DC C000A37B */  lq         $3, 0xC0($29)
    /* 2B07E0 003B07E0 21904302 */  addu       $18, $18, $3
    /* 2B07E4 003B07E4 2A18D700 */  slt        $3, $6, $23
    /* 2B07E8 003B07E8 B3FF6014 */  bnez       $3, .L003B06B8
    /* 2B07EC 003B07EC 21882402 */   addu      $17, $17, $4
    /* 2B07F0 003B07F0 D7000010 */  b          .L003B0B50
    /* 2B07F4 003B07F4 00000000 */   nop
  .L003B07F8:
    /* 2B07F8 003B07F8 0000A2C6 */  lwc1       $f2, 0x0($21)
    /* 2B07FC 003B07FC 003F043C */  lui        $4, (0x3F000000 >> 16)
    /* 2B0800 003B0800 0400A1C6 */  lwc1       $f1, 0x4($21)
    /* 2B0804 003B0804 0401A327 */  addiu      $3, $29, 0x104
    /* 2B0808 003B0808 0800A0C6 */  lwc1       $f0, 0x8($21)
    /* 2B080C 003B080C 00188444 */  mtc1       $4, $f3
    /* 2B0810 003B0810 680085C6 */  lwc1       $f5, 0x68($20)
    /* 2B0814 003B0814 6C0084C6 */  lwc1       $f4, 0x6C($20)
    /* 2B0818 003B0818 0100043C */  lui        $4, (0x10000 >> 16)
    /* 2B081C 003B081C 82180246 */  mul.s      $f2, $f3, $f2
    /* 2B0820 003B0820 42180146 */  mul.s      $f1, $f3, $f1
    /* 2B0824 003B0824 02180046 */  mul.s      $f0, $f3, $f0
    /* 2B0828 003B0828 40290546 */  add.s      $f5, $f5, $f5
    /* 2B082C 003B082C 00210446 */  add.s      $f4, $f4, $f4
    /* 2B0830 003B0830 2001A2E7 */  swc1       $f2, 0x120($29)
    /* 2B0834 003B0834 2401A1E7 */  swc1       $f1, 0x124($29)
    /* 2B0838 003B0838 2801A0E7 */  swc1       $f0, 0x128($29)
    /* 2B083C 003B083C 0000C2C6 */  lwc1       $f2, 0x0($22)
    /* 2B0840 003B0840 0400C1C6 */  lwc1       $f1, 0x4($22)
    /* 2B0844 003B0844 0800C0C6 */  lwc1       $f0, 0x8($22)
    /* 2B0848 003B0848 0001A5E7 */  swc1       $f5, 0x100($29)
    /* 2B084C 003B084C 0801A5E7 */  swc1       $f5, 0x108($29)
    /* 2B0850 003B0850 0C01A4E7 */  swc1       $f4, 0x10C($29)
    /* 2B0854 003B0854 82180246 */  mul.s      $f2, $f3, $f2
    /* 2B0858 003B0858 42180146 */  mul.s      $f1, $f3, $f1
    /* 2B085C 003B085C 02180046 */  mul.s      $f0, $f3, $f0
    /* 2B0860 003B0860 000064E4 */  swc1       $f4, 0x0($3)
    /* 2B0864 003B0864 1001A2E7 */  swc1       $f2, 0x110($29)
    /* 2B0868 003B0868 1401A1E7 */  swc1       $f1, 0x114($29)
    /* 2B086C 003B086C 1801A0E7 */  swc1       $f0, 0x118($29)
  .L003B0870:
    /* 2B0870 003B0870 39000042 */  di /* handwritten instruction */
    /* 2B0874 003B0874 0F040000 */  sync.p
    /* 2B0878 003B0878 00600540 */  mfc0       $5, $12 /* handwritten instruction */
    /* 2B087C 003B087C 2428A400 */  and        $5, $5, $4
    /* 2B0880 003B0880 00000000 */  nop
    /* 2B0884 003B0884 FAFFA014 */  bnez       $5, .L003B0870
    /* 2B0888 003B0888 00000000 */   nop
    /* 2B088C 003B088C C93F013C */  lui        $1, (0x3FC90FDB >> 16)
    /* 2B0890 003B0890 DB0F2434 */  ori        $4, $1, (0x3FC90FDB & 0xFFFF)
    /* 2B0894 003B0894 00008444 */  mtc1       $4, $f0
    /* 2B0898 003B0898 00000444 */  mfc1       $4, $f0
    /* 2B089C 003B089C 00A8C448 */  ctc2.ni    $4, $vi21
    /* 2B08A0 003B08A0 FF02004A */  vnop
    /* 2B08A4 003B08A4 FF02004A */  vnop
    /* 2B08A8 003B08A8 A202004B */  vaddi.x    $vf10, $vf0, $I
    /* 2B08AC 003B08AC 4940013C */  lui        $1, (0x40490FDB >> 16)
    /* 2B08B0 003B08B0 DB0F2534 */  ori        $5, $1, (0x40490FDB & 0xFFFF)
    /* 2B08B4 003B08B4 00008544 */  mtc1       $5, $f0
    /* 2B08B8 003B08B8 00000444 */  mfc1       $4, $f0
    /* 2B08BC 003B08BC 00A8C448 */  ctc2.ni    $4, $vi21
    /* 2B08C0 003B08C0 FF02004A */  vnop
    /* 2B08C4 003B08C4 FF02004A */  vnop
    /* 2B08C8 003B08C8 A202804A */  vaddi.y    $vf10, $vf0, $I
    /* 2B08CC 003B08CC 0940013C */  lui        $1, (0x40090FDB >> 16)
    /* 2B08D0 003B08D0 DB0F2434 */  ori        $4, $1, (0x40090FDB & 0xFFFF)
    /* 2B08D4 003B08D4 00008444 */  mtc1       $4, $f0
    /* 2B08D8 003B08D8 00000444 */  mfc1       $4, $f0
    /* 2B08DC 003B08DC 00A8C448 */  ctc2.ni    $4, $vi21
    /* 2B08E0 003B08E0 FF02004A */  vnop
    /* 2B08E4 003B08E4 FF02004A */  vnop
    /* 2B08E8 003B08E8 A202404A */  vaddi.z    $vf10, $vf0, $I
    /* 2B08EC 003B08EC 00008544 */  mtc1       $5, $f0
    /* 2B08F0 003B08F0 07000046 */  neg.s      $f0, $f0
    /* 2B08F4 003B08F4 00000444 */  mfc1       $4, $f0
    /* 2B08F8 003B08F8 00A8C448 */  ctc2.ni    $4, $vi21
    /* 2B08FC 003B08FC FF02004A */  vnop
    /* 2B0900 003B0900 FF02004A */  vnop
    /* 2B0904 003B0904 E202004B */  vaddi.x    $vf11, $vf0, $I
    /* 2B0908 003B0908 8440013C */  lui        $1, (0x408487ED >> 16)
    /* 2B090C 003B090C ED872434 */  ori        $4, $1, (0x408487ED & 0xFFFF)
    /* 2B0910 003B0910 00008444 */  mtc1       $4, $f0
    /* 2B0914 003B0914 07000046 */  neg.s      $f0, $f0
    /* 2B0918 003B0918 00000444 */  mfc1       $4, $f0
    /* 2B091C 003B091C 00A8C448 */  ctc2.ni    $4, $vi21
    /* 2B0920 003B0920 FF02004A */  vnop
    /* 2B0924 003B0924 FF02004A */  vnop
    /* 2B0928 003B0928 E202804A */  vaddi.y    $vf11, $vf0, $I
    /* 2B092C 003B092C 00000434 */  ori        $4, $0, 0x0
    /* 2B0930 003B0930 38240400 */  dsll       $4, $4, 16
    /* 2B0934 003B0934 38240400 */  dsll       $4, $4, 16
    /* 2B0938 003B0938 4FB98434 */  ori        $4, $4, 0xB94F
    /* 2B093C 003B093C 38240400 */  dsll       $4, $4, 16
    /* 2B0940 003B0940 1FB28434 */  ori        $4, $4, 0xB21F
    /* 2B0944 003B0944 00A8C448 */  ctc2.ni    $4, $vi21
    /* 2B0948 003B0948 FF02004A */  vnop
    /* 2B094C 003B094C FF02004A */  vnop
    /* 2B0950 003B0950 E202404A */  vaddi.z    $vf11, $vf0, $I
    /* 2B0954 003B0954 00000434 */  ori        $4, $0, 0x0
    /* 2B0958 003B0958 38240400 */  dsll       $4, $4, 16
    /* 2B095C 003B095C 38240400 */  dsll       $4, $4, 16
    /* 2B0960 003B0960 2ABE8434 */  ori        $4, $4, 0xBE2A
    /* 2B0964 003B0964 38240400 */  dsll       $4, $4, 16
    /* 2B0968 003B0968 A4AA8434 */  ori        $4, $4, 0xAAA4
    /* 2B096C 003B096C 00A8C448 */  ctc2.ni    $4, $vi21
    /* 2B0970 003B0970 FF02004A */  vnop
    /* 2B0974 003B0974 FF02004A */  vnop
    /* 2B0978 003B0978 2203004B */  vaddi.x    $vf12, $vf0, $I
    /* 2B097C 003B097C 083C013C */  lui        $1, (0x3C08873E >> 16)
    /* 2B0980 003B0980 3E872434 */  ori        $4, $1, (0x3C08873E & 0xFFFF)
    /* 2B0984 003B0984 00A8C448 */  ctc2.ni    $4, $vi21
    /* 2B0988 003B0988 FF02004A */  vnop
    /* 2B098C 003B098C FF02004A */  vnop
    /* 2B0990 003B0990 2203804A */  vaddi.y    $vf12, $vf0, $I
    /* 2B0994 003B0994 2E36013C */  lui        $1, (0x362E9C14 >> 16)
    /* 2B0998 003B0998 149C2434 */  ori        $4, $1, (0x362E9C14 & 0xFFFF)
    /* 2B099C 003B099C 00A8C448 */  ctc2.ni    $4, $vi21
    /* 2B09A0 003B09A0 FF02004A */  vnop
    /* 2B09A4 003B09A4 FF02004A */  vnop
    /* 2B09A8 003B09A8 2203404A */  vaddi.z    $vf12, $vf0, $I
    /* 2B09AC 003B09AC 803F043C */  lui        $4, (0x3F800000 >> 16)
    /* 2B09B0 003B09B0 00A8C448 */  ctc2.ni    $4, $vi21
    /* 2B09B4 003B09B4 FF02004A */  vnop
    /* 2B09B8 003B09B8 FF02004A */  vnop
    /* 2B09BC 003B09BC 6203004B */  vaddi.x    $vf13, $vf0, $I
    /* 2B09C0 003B09C0 38000042 */  ei /* handwritten instruction */
    /* 2B09C4 003B09C4 0100043C */  lui        $4, (0x10000 >> 16)
  .L003B09C8:
    /* 2B09C8 003B09C8 39000042 */  di /* handwritten instruction */
    /* 2B09CC 003B09CC 0F040000 */  sync.p
    /* 2B09D0 003B09D0 00600540 */  mfc0       $5, $12 /* handwritten instruction */
    /* 2B09D4 003B09D4 2428A400 */  and        $5, $5, $4
    /* 2B09D8 003B09D8 00000000 */  nop
    /* 2B09DC 003B09DC FAFFA014 */  bnez       $5, .L003B09C8
    /* 2B09E0 003B09E0 00000000 */   nop
    /* 2B09E4 003B09E4 2001A527 */  addiu      $5, $29, 0x120
    /* 2B09E8 003B09E8 1001A427 */  addiu      $4, $29, 0x110
    /* 2B09EC 003B09EC 0001A927 */  addiu      $9, $29, 0x100
    /* 2B09F0 003B09F0 0000A8D8 */  lqc2       $vf8, 0x0($5)
    /* 2B09F4 003B09F4 000089D8 */  lqc2       $vf9, 0x0($4)
    /* 2B09F8 003B09F8 00002FD9 */  lqc2       $vf15, 0x0($9)
    /* 2B09FC 003B09FC 38000042 */  ei /* handwritten instruction */
    /* 2B0A00 003B0A00 2A081700 */  slt        $1, $0, $23
    /* 2B0A04 003B0A04 52002010 */  beqz       $1, .L003B0B50
    /* 2B0A08 003B0A08 2D500000 */   daddu     $10, $0, $0
    /* 2B0A0C 003B0A0C A000A47B */  lq         $4, 0xA0($29)
    /* 2B0A10 003B0A10 F800A827 */  addiu      $8, $29, 0xF8
    /* 2B0A14 003B0A14 F000A627 */  addiu      $6, $29, 0xF0
    /* 2B0A18 003B0A18 0100073C */  lui        $7, (0x10000 >> 16)
    /* 2B0A1C 003B0A1C 80280400 */  sll        $5, $4, 2
  .L003B0A20:
    /* 2B0A20 003B0A20 000042C6 */  lwc1       $f2, 0x0($18)
    /* 2B0A24 003B0A24 000001C6 */  lwc1       $f1, 0x0($16)
    /* 2B0A28 003B0A28 040000C6 */  lwc1       $f0, 0x4($16)
    /* 2B0A2C 003B0A2C F000A2E7 */  swc1       $f2, 0xF0($29)
    /* 2B0A30 003B0A30 000002E5 */  swc1       $f2, 0x0($8)
    /* 2B0A34 003B0A34 0001A1E7 */  swc1       $f1, 0x100($29)
    /* 2B0A38 003B0A38 000060E4 */  swc1       $f0, 0x0($3)
    /* 2B0A3C 003B0A3C 00000000 */  nop
  .L003B0A40:
    /* 2B0A40 003B0A40 39000042 */  di /* handwritten instruction */
    /* 2B0A44 003B0A44 0F040000 */  sync.p
    /* 2B0A48 003B0A48 00600440 */  mfc0       $4, $12 /* handwritten instruction */
    /* 2B0A4C 003B0A4C 24208700 */  and        $4, $4, $7
    /* 2B0A50 003B0A50 00000000 */  nop
    /* 2B0A54 003B0A54 FAFF8014 */  bnez       $4, .L003B0A40
    /* 2B0A58 003B0A58 00000000 */   nop
    /* 2B0A5C 003B0A5C 0000C1D8 */  lqc2       $vf1, 0x0($6)
    /* 2B0A60 003B0A60 FD09874B */  vabs.xy    $vf7, $vf1
    /* 2B0A64 003B0A64 3C00EA4B */  vaddax.xyzw $ACC, $vf0, $vf10x
    /* 2B0A68 003B0A68 CF39804B */  vmsubw.xy  $vf7, $vf7, $vf0w
    /* 2B0A6C 003B0A6C 3D00CA4B */  vadday.xyz $ACC, $vf0, $vf10y
    /* 2B0A70 003B0A70 3E002A4A */  vaddaz.w   $ACC, $vf0, $vf10z
    /* 2B0A74 003B0A74 8F08604A */  vmsubw.zw  $vf2, $vf1, $vf0w
    /* 2B0A78 003B0A78 3C00CB4B */  vaddax.xyz $ACC, $vf0, $vf11x
    /* 2B0A7C 003B0A7C 3D002B4A */  vadday.w   $ACC, $vf0, $vf11y
    /* 2B0A80 003B0A80 CF08604A */  vmsubw.zw  $vf3, $vf1, $vf0w
    /* 2B0A84 003B0A84 AF08624A */  vmini.zw   $vf2, $vf1, $vf2
    /* 2B0A88 003B0A88 EB11634A */  vmax.zw    $vf7, $vf2, $vf3
    /* 2B0A8C 003B0A8C AA38E74B */  vmul.xyzw  $vf2, $vf7, $vf7
    /* 2B0A90 003B0A90 9A39EB4B */  vmulz.xyzw $vf6, $vf7, $vf11z
    /* 2B0A94 003B0A94 1839EC4B */  vmulx.xyzw $vf4, $vf7, $vf12x
    /* 2B0A98 003B0A98 5939EC4B */  vmuly.xyzw $vf5, $vf7, $vf12y
    /* 2B0A9C 003B0A9C EA10E24B */  vmul.xyzw  $vf3, $vf2, $vf2
    /* 2B0AA0 003B0AA0 AA31E24B */  vmul.xyzw  $vf6, $vf6, $vf2
    /* 2B0AA4 003B0AA4 BE22E24B */  vmula.xyzw $ACC, $vf4, $vf2
    /* 2B0AA8 003B0AA8 1A39EC4B */  vmulz.xyzw $vf4, $vf7, $vf12z
    /* 2B0AAC 003B0AAC AA18E34B */  vmul.xyzw  $vf2, $vf3, $vf3
    /* 2B0AB0 003B0AB0 BD32E34B */  vmadda.xyzw $ACC, $vf6, $vf3
    /* 2B0AB4 003B0AB4 BD2AE34B */  vmadda.xyzw $ACC, $vf5, $vf3
    /* 2B0AB8 003B0AB8 BC38ED4B */  vmaddax.xyzw $ACC, $vf7, $vf13x
    /* 2B0ABC 003B0ABC E921E24B */  vmadd.xyzw $vf7, $vf4, $vf2
    /* 2B0AC0 003B0AC0 000074DA */  lqc2       $vf20, 0x0($19)
    /* 2B0AC4 003B0AC4 00002ED9 */  lqc2       $vf14, 0x0($9)
    /* 2B0AC8 003B0AC8 BC41E74B */  vmulax.xyzw $ACC, $vf8, $vf7x
    /* 2B0ACC 003B0ACC 8E4CE74B */  vmsubz.xyzw $vf18, $vf9, $vf7z
    /* 2B0AD0 003B0AD0 A878EE4B */  vadd.xyzw  $vf2, $vf15, $vf14
    /* 2B0AD4 003B0AD4 EC78EE4B */  vsub.xyzw  $vf3, $vf15, $vf14
    /* 2B0AD8 003B0AD8 BC49E74B */  vmulax.xyzw $ACC, $vf9, $vf7x
    /* 2B0ADC 003B0ADC CA44E74B */  vmaddz.xyzw $vf19, $vf8, $vf7z
    /* 2B0AE0 003B0AE0 BC91E34B */  vmulax.xyzw $ACC, $vf18, $vf3x
    /* 2B0AE4 003B0AE4 499DE34B */  vmaddy.xyzw $vf21, $vf19, $vf3y
    /* 2B0AE8 003B0AE8 BC91E24B */  vmulax.xyzw $ACC, $vf18, $vf2x
    /* 2B0AEC 003B0AEC 899DE34B */  vmaddy.xyzw $vf22, $vf19, $vf3y
    /* 2B0AF0 003B0AF0 BC91E24B */  vmulax.xyzw $ACC, $vf18, $vf2x
    /* 2B0AF4 003B0AF4 C99DE24B */  vmaddy.xyzw $vf23, $vf19, $vf2y
    /* 2B0AF8 003B0AF8 BC91E34B */  vmulax.xyzw $ACC, $vf18, $vf3x
    /* 2B0AFC 003B0AFC 099EE24B */  vmaddy.xyzw $vf24, $vf19, $vf2y
    /* 2B0B00 003B0B00 68ADF44B */  vadd.xyzw  $vf21, $vf21, $vf20
    /* 2B0B04 003B0B04 A8B5F44B */  vadd.xyzw  $vf22, $vf22, $vf20
    /* 2B0B08 003B0B08 E8BDF44B */  vadd.xyzw  $vf23, $vf23, $vf20
    /* 2B0B0C 003B0B0C 28C6F44B */  vadd.xyzw  $vf24, $vf24, $vf20
    /* 2B0B10 003B0B10 000035FA */  sqc2       $vf21, 0x0($17)
    /* 2B0B14 003B0B14 100036FA */  sqc2       $vf22, 0x10($17)
    /* 2B0B18 003B0B18 200037FA */  sqc2       $vf23, 0x20($17)
    /* 2B0B1C 003B0B1C 300038FA */  sqc2       $vf24, 0x30($17)
    /* 2B0B20 003B0B20 38000042 */  ei /* handwritten instruction */
    /* 2B0B24 003B0B24 01004A25 */  addiu      $10, $10, 0x1
    /* 2B0B28 003B0B28 D000A47B */  lq         $4, 0xD0($29)
    /* 2B0B2C 003B0B2C 21986402 */  addu       $19, $19, $4
    /* 2B0B30 003B0B30 B000A47B */  lq         $4, 0xB0($29)
    /* 2B0B34 003B0B34 21800402 */  addu       $16, $16, $4
    /* 2B0B38 003B0B38 C000A47B */  lq         $4, 0xC0($29)
    /* 2B0B3C 003B0B3C 21904402 */  addu       $18, $18, $4
    /* 2B0B40 003B0B40 2A205701 */  slt        $4, $10, $23
    /* 2B0B44 003B0B44 B6FF8014 */  bnez       $4, .L003B0A20
    /* 2B0B48 003B0B48 21882502 */   addu      $17, $17, $5
    /* 2B0B4C 003B0B4C 00000000 */  nop
  .L003B0B50:
    /* 2B0B50 003B0B50 9000BFDF */  ld         $31, 0x90($29)
    /* 2B0B54 003B0B54 8000BE7B */  lq         $30, 0x80($29)
    /* 2B0B58 003B0B58 7000B77B */  lq         $23, 0x70($29)
    /* 2B0B5C 003B0B5C 6000B67B */  lq         $22, 0x60($29)
    /* 2B0B60 003B0B60 5000B57B */  lq         $21, 0x50($29)
    /* 2B0B64 003B0B64 4000B47B */  lq         $20, 0x40($29)
    /* 2B0B68 003B0B68 3000B37B */  lq         $19, 0x30($29)
    /* 2B0B6C 003B0B6C 2000B27B */  lq         $18, 0x20($29)
    /* 2B0B70 003B0B70 1000B17B */  lq         $17, 0x10($29)
    /* 2B0B74 003B0B74 0000B07B */  lq         $16, 0x0($29)
    /* 2B0B78 003B0B78 0800E003 */  jr         $31
    /* 2B0B7C 003B0B7C 3001BD27 */   addiu     $29, $29, 0x130
.size func_003af990, 0x11f0
