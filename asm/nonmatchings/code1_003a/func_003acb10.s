.section .text
.set noat
.set noreorder
glabel func_003acb10
    /* 2ACB10 003ACB10 F0FEBD27 */  addiu      $29, $29, -0x110
    /* 2ACB14 003ACB14 9000BFFF */  sd         $31, 0x90($29)
    /* 2ACB18 003ACB18 8000BE7F */  sq         $30, 0x80($29)
    /* 2ACB1C 003ACB1C 7000B77F */  sq         $23, 0x70($29)
    /* 2ACB20 003ACB20 6000B67F */  sq         $22, 0x60($29)
    /* 2ACB24 003ACB24 5000B57F */  sq         $21, 0x50($29)
    /* 2ACB28 003ACB28 2DB0C000 */  daddu      $22, $6, $0
    /* 2ACB2C 003ACB2C 4000B47F */  sq         $20, 0x40($29)
    /* 2ACB30 003ACB30 2DA8A000 */  daddu      $21, $5, $0
    /* 2ACB34 003ACB34 3000B37F */  sq         $19, 0x30($29)
    /* 2ACB38 003ACB38 2DA0E000 */  daddu      $20, $7, $0
    /* 2ACB3C 003ACB3C 2000B27F */  sq         $18, 0x20($29)
    /* 2ACB40 003ACB40 1000B17F */  sq         $17, 0x10($29)
    /* 2ACB44 003ACB44 0000B07F */  sq         $16, 0x0($29)
    /* 2ACB48 003ACB48 0800038D */  lw         $3, 0x8($8)
    /* 2ACB4C 003ACB4C 0000918C */  lw         $17, 0x0($4)
    /* 2ACB50 003ACB50 0400138D */  lw         $19, 0x4($8)
    /* 2ACB54 003ACB54 3400128D */  lw         $18, 0x34($8)
    /* 2ACB58 003ACB58 1C00108D */  lw         $16, 0x1C($8)
    /* 2ACB5C 003ACB5C D000A37F */  sq         $3, 0xD0($29)
    /* 2ACB60 003ACB60 3800038D */  lw         $3, 0x38($8)
    /* 2ACB64 003ACB64 C000A37F */  sq         $3, 0xC0($29)
    /* 2ACB68 003ACB68 2000038D */  lw         $3, 0x20($8)
    /* 2ACB6C 003ACB6C B000A37F */  sq         $3, 0xB0($29)
    /* 2ACB70 003ACB70 0400838C */  lw         $3, 0x4($4)
    /* 2ACB74 003ACB74 D000A47B */  lq         $4, 0xD0($29)
    /* 2ACB78 003ACB78 5D038314 */  bne        $4, $3, .L003AD8F0
    /* 2ACB7C 003ACB7C A000A37F */   sq        $3, 0xA0($29)
    /* 2ACB80 003ACB80 9886100C */  jal        func_00421a60
    /* 2ACB84 003ACB84 2D200000 */   daddu     $4, $0, $0
    /* 2ACB88 003ACB88 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2ACB8C 003ACB8C 00D0648C */  lw         $4, -0x3000($3)
    /* 2ACB90 003ACB90 00018430 */  andi       $4, $4, 0x100
    /* 2ACB94 003ACB94 0C008010 */  beqz       $4, .L003ACBC8
    /* 2ACB98 003ACB98 00000000 */   nop
    /* 2ACB9C 003ACB9C 00010424 */  addiu      $4, $0, 0x100
    /* 2ACBA0 003ACBA0 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2ACBA4 003ACBA4 0F000000 */  sync
    /* 2ACBA8 003ACBA8 0F040000 */  sync.p
  .L003ACBAC:
    /* 2ACBAC 003ACBAC 00000000 */  nop
    /* 2ACBB0 003ACBB0 00000000 */  nop
    /* 2ACBB4 003ACBB4 00000000 */  nop
    /* 2ACBB8 003ACBB8 00000000 */  nop
    /* 2ACBBC 003ACBBC 00000000 */  nop
    /* 2ACBC0 003ACBC0 FAFF0041 */  bc0f       .L003ACBAC /* handwritten instruction */
    /* 2ACBC4 003ACBC4 00000000 */   nop
  .L003ACBC8:
    /* 2ACBC8 003ACBC8 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2ACBCC 003ACBCC 00D4648C */  lw         $4, -0x2C00($3)
    /* 2ACBD0 003ACBD0 00018430 */  andi       $4, $4, 0x100
    /* 2ACBD4 003ACBD4 14008010 */  beqz       $4, .L003ACC28
    /* 2ACBD8 003ACBD8 00000000 */   nop
    /* 2ACBDC 003ACBDC 00020424 */  addiu      $4, $0, 0x200
    /* 2ACBE0 003ACBE0 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2ACBE4 003ACBE4 0F000000 */  sync
    /* 2ACBE8 003ACBE8 0F040000 */  sync.p
  .L003ACBEC:
    /* 2ACBEC 003ACBEC 00000000 */  nop
    /* 2ACBF0 003ACBF0 00000000 */  nop
    /* 2ACBF4 003ACBF4 00000000 */  nop
    /* 2ACBF8 003ACBF8 00000000 */  nop
    /* 2ACBFC 003ACBFC 00000000 */  nop
    /* 2ACC00 003ACC00 FAFF0041 */  bc0f       .L003ACBEC /* handwritten instruction */
    /* 2ACC04 003ACC04 00000000 */   nop
    /* 2ACC08 003ACC08 0110033C */  lui        $3, (0x10010000 >> 16)
  .L003ACC0C:
    /* 2ACC0C 003ACC0C 00D4648C */  lw         $4, -0x2C00($3)
    /* 2ACC10 003ACC10 00018430 */  andi       $4, $4, 0x100
    /* 2ACC14 003ACC14 00000000 */  nop
    /* 2ACC18 003ACC18 00000000 */  nop
    /* 2ACC1C 003ACC1C 00000000 */  nop
    /* 2ACC20 003ACC20 FAFF8014 */  bnez       $4, .L003ACC0C
    /* 2ACC24 003ACC24 00000000 */   nop
  .L003ACC28:
    /* 2ACC28 003ACC28 0070043C */  lui        $4, (0x70003F58 >> 16)
    /* 2ACC2C 003ACC2C 0000A0C6 */  lwc1       $f0, 0x0($21)
    /* 2ACC30 003ACC30 003F033C */  lui        $3, (0x3F000000 >> 16)
    /* 2ACC34 003ACC34 00088344 */  mtc1       $3, $f1
    /* 2ACC38 003ACC38 403F8634 */  ori        $6, $4, (0x70003F40 & 0xFFFF)
    /* 2ACC3C 003ACC3C 503F8534 */  ori        $5, $4, (0x70003F50 & 0xFFFF)
    /* 2ACC40 003ACC40 603F8E34 */  ori        $14, $4, (0x70003F60 & 0xFFFF)
    /* 2ACC44 003ACC44 0100033C */  lui        $3, (0x10000 >> 16)
    /* 2ACC48 003ACC48 02080046 */  mul.s      $f0, $f1, $f0
    /* 2ACC4C 003ACC4C 403F80E4 */  swc1       $f0, (0x70003F40 & 0xFFFF)($4)
    /* 2ACC50 003ACC50 0400A0C6 */  lwc1       $f0, 0x4($21)
    /* 2ACC54 003ACC54 02080046 */  mul.s      $f0, $f1, $f0
    /* 2ACC58 003ACC58 443F80E4 */  swc1       $f0, (0x70003F44 & 0xFFFF)($4)
    /* 2ACC5C 003ACC5C 0800A0C6 */  lwc1       $f0, 0x8($21)
    /* 2ACC60 003ACC60 02080046 */  mul.s      $f0, $f1, $f0
    /* 2ACC64 003ACC64 483F80E4 */  swc1       $f0, (0x70003F48 & 0xFFFF)($4)
    /* 2ACC68 003ACC68 0000C0C6 */  lwc1       $f0, 0x0($22)
    /* 2ACC6C 003ACC6C 02080046 */  mul.s      $f0, $f1, $f0
    /* 2ACC70 003ACC70 503F80E4 */  swc1       $f0, (0x70003F50 & 0xFFFF)($4)
    /* 2ACC74 003ACC74 0400C0C6 */  lwc1       $f0, 0x4($22)
    /* 2ACC78 003ACC78 02080046 */  mul.s      $f0, $f1, $f0
    /* 2ACC7C 003ACC7C 543F80E4 */  swc1       $f0, (0x70003F54 & 0xFFFF)($4)
    /* 2ACC80 003ACC80 0800C0C6 */  lwc1       $f0, 0x8($22)
    /* 2ACC84 003ACC84 02080046 */  mul.s      $f0, $f1, $f0
    /* 2ACC88 003ACC88 583F80E4 */  swc1       $f0, (0x70003F58 & 0xFFFF)($4)
  .L003ACC8C:
    /* 2ACC8C 003ACC8C 39000042 */  di /* handwritten instruction */
    /* 2ACC90 003ACC90 0F040000 */  sync.p
    /* 2ACC94 003ACC94 00600440 */  mfc0       $4, $12 /* handwritten instruction */
    /* 2ACC98 003ACC98 24208300 */  and        $4, $4, $3
    /* 2ACC9C 003ACC9C 00000000 */  nop
    /* 2ACCA0 003ACCA0 FAFF8014 */  bnez       $4, .L003ACC8C
    /* 2ACCA4 003ACCA4 00000000 */   nop
    /* 2ACCA8 003ACCA8 C93F013C */  lui        $1, (0x3FC90FDB >> 16)
    /* 2ACCAC 003ACCAC DB0F2334 */  ori        $3, $1, (0x3FC90FDB & 0xFFFF)
    /* 2ACCB0 003ACCB0 00008344 */  mtc1       $3, $f0
    /* 2ACCB4 003ACCB4 00000344 */  mfc1       $3, $f0
    /* 2ACCB8 003ACCB8 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2ACCBC 003ACCBC FF02004A */  vnop
    /* 2ACCC0 003ACCC0 FF02004A */  vnop
    /* 2ACCC4 003ACCC4 A202004B */  vaddi.x    $vf10, $vf0, $I
    /* 2ACCC8 003ACCC8 4940013C */  lui        $1, (0x40490FDB >> 16)
    /* 2ACCCC 003ACCCC DB0F2434 */  ori        $4, $1, (0x40490FDB & 0xFFFF)
    /* 2ACCD0 003ACCD0 00008444 */  mtc1       $4, $f0
    /* 2ACCD4 003ACCD4 00000344 */  mfc1       $3, $f0
    /* 2ACCD8 003ACCD8 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2ACCDC 003ACCDC FF02004A */  vnop
    /* 2ACCE0 003ACCE0 FF02004A */  vnop
    /* 2ACCE4 003ACCE4 A202804A */  vaddi.y    $vf10, $vf0, $I
    /* 2ACCE8 003ACCE8 0940013C */  lui        $1, (0x40090FDB >> 16)
    /* 2ACCEC 003ACCEC DB0F2334 */  ori        $3, $1, (0x40090FDB & 0xFFFF)
    /* 2ACCF0 003ACCF0 00008344 */  mtc1       $3, $f0
    /* 2ACCF4 003ACCF4 00000344 */  mfc1       $3, $f0
    /* 2ACCF8 003ACCF8 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2ACCFC 003ACCFC FF02004A */  vnop
    /* 2ACD00 003ACD00 FF02004A */  vnop
    /* 2ACD04 003ACD04 A202404A */  vaddi.z    $vf10, $vf0, $I
    /* 2ACD08 003ACD08 00008444 */  mtc1       $4, $f0
    /* 2ACD0C 003ACD0C 07000046 */  neg.s      $f0, $f0
    /* 2ACD10 003ACD10 00000344 */  mfc1       $3, $f0
    /* 2ACD14 003ACD14 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2ACD18 003ACD18 FF02004A */  vnop
    /* 2ACD1C 003ACD1C FF02004A */  vnop
    /* 2ACD20 003ACD20 E202004B */  vaddi.x    $vf11, $vf0, $I
    /* 2ACD24 003ACD24 8440013C */  lui        $1, (0x408487ED >> 16)
    /* 2ACD28 003ACD28 ED872334 */  ori        $3, $1, (0x408487ED & 0xFFFF)
    /* 2ACD2C 003ACD2C 00008344 */  mtc1       $3, $f0
    /* 2ACD30 003ACD30 07000046 */  neg.s      $f0, $f0
    /* 2ACD34 003ACD34 00000344 */  mfc1       $3, $f0
    /* 2ACD38 003ACD38 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2ACD3C 003ACD3C FF02004A */  vnop
    /* 2ACD40 003ACD40 FF02004A */  vnop
    /* 2ACD44 003ACD44 E202804A */  vaddi.y    $vf11, $vf0, $I
    /* 2ACD48 003ACD48 00000334 */  ori        $3, $0, 0x0
    /* 2ACD4C 003ACD4C 381C0300 */  dsll       $3, $3, 16
    /* 2ACD50 003ACD50 381C0300 */  dsll       $3, $3, 16
    /* 2ACD54 003ACD54 4FB96334 */  ori        $3, $3, 0xB94F
    /* 2ACD58 003ACD58 381C0300 */  dsll       $3, $3, 16
    /* 2ACD5C 003ACD5C 1FB26334 */  ori        $3, $3, 0xB21F
    /* 2ACD60 003ACD60 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2ACD64 003ACD64 FF02004A */  vnop
    /* 2ACD68 003ACD68 FF02004A */  vnop
    /* 2ACD6C 003ACD6C E202404A */  vaddi.z    $vf11, $vf0, $I
    /* 2ACD70 003ACD70 00000334 */  ori        $3, $0, 0x0
    /* 2ACD74 003ACD74 381C0300 */  dsll       $3, $3, 16
    /* 2ACD78 003ACD78 381C0300 */  dsll       $3, $3, 16
    /* 2ACD7C 003ACD7C 2ABE6334 */  ori        $3, $3, 0xBE2A
    /* 2ACD80 003ACD80 381C0300 */  dsll       $3, $3, 16
    /* 2ACD84 003ACD84 A4AA6334 */  ori        $3, $3, 0xAAA4
    /* 2ACD88 003ACD88 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2ACD8C 003ACD8C FF02004A */  vnop
    /* 2ACD90 003ACD90 FF02004A */  vnop
    /* 2ACD94 003ACD94 2203004B */  vaddi.x    $vf12, $vf0, $I
    /* 2ACD98 003ACD98 083C013C */  lui        $1, (0x3C08873E >> 16)
    /* 2ACD9C 003ACD9C 3E872334 */  ori        $3, $1, (0x3C08873E & 0xFFFF)
    /* 2ACDA0 003ACDA0 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2ACDA4 003ACDA4 FF02004A */  vnop
    /* 2ACDA8 003ACDA8 FF02004A */  vnop
    /* 2ACDAC 003ACDAC 2203804A */  vaddi.y    $vf12, $vf0, $I
    /* 2ACDB0 003ACDB0 2E36013C */  lui        $1, (0x362E9C14 >> 16)
    /* 2ACDB4 003ACDB4 149C2334 */  ori        $3, $1, (0x362E9C14 & 0xFFFF)
    /* 2ACDB8 003ACDB8 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2ACDBC 003ACDBC FF02004A */  vnop
    /* 2ACDC0 003ACDC0 FF02004A */  vnop
    /* 2ACDC4 003ACDC4 2203404A */  vaddi.z    $vf12, $vf0, $I
    /* 2ACDC8 003ACDC8 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* 2ACDCC 003ACDCC 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2ACDD0 003ACDD0 FF02004A */  vnop
    /* 2ACDD4 003ACDD4 FF02004A */  vnop
    /* 2ACDD8 003ACDD8 6203004B */  vaddi.x    $vf13, $vf0, $I
    /* 2ACDDC 003ACDDC 38000042 */  ei /* handwritten instruction */
    /* 2ACDE0 003ACDE0 0100033C */  lui        $3, (0x10000 >> 16)
  .L003ACDE4:
    /* 2ACDE4 003ACDE4 39000042 */  di /* handwritten instruction */
    /* 2ACDE8 003ACDE8 0F040000 */  sync.p
    /* 2ACDEC 003ACDEC 00600440 */  mfc0       $4, $12 /* handwritten instruction */
    /* 2ACDF0 003ACDF0 24208300 */  and        $4, $4, $3
    /* 2ACDF4 003ACDF4 00000000 */  nop
    /* 2ACDF8 003ACDF8 FAFF8014 */  bnez       $4, .L003ACDE4
    /* 2ACDFC 003ACDFC 00000000 */   nop
    /* 2ACE00 003ACE00 0000C8D8 */  lqc2       $vf8, 0x0($6)
    /* 2ACE04 003ACE04 0000A9D8 */  lqc2       $vf9, 0x0($5)
    /* 2ACE08 003ACE08 38000042 */  ei /* handwritten instruction */
    /* 2ACE0C 003ACE0C B000832A */  slti       $3, $20, 0xB0
    /* 2ACE10 003ACE10 25016014 */  bnez       $3, .L003AD2A8
    /* 2ACE14 003ACE14 00000000 */   nop
    /* 2ACE18 003ACE18 0070083C */  lui        $8, (0x70001340 >> 16)
    /* 2ACE1C 003ACE1C 0110043C */  lui        $4, (0x10010000 >> 16)
    /* 2ACE20 003ACE20 00010C24 */  addiu      $12, $0, 0x100
    /* 2ACE24 003ACE24 00020B24 */  addiu      $11, $0, 0x200
    /* 2ACE28 003ACE28 2C000A24 */  addiu      $10, $0, 0x2C
    /* 2ACE2C 003ACE2C C0020924 */  addiu      $9, $0, 0x2C0
    /* 2ACE30 003ACE30 58001724 */  addiu      $23, $0, 0x58
    /* 2ACE34 003ACE34 40081E24 */  addiu      $30, $0, 0x840
    /* 2ACE38 003ACE38 C0020735 */  ori        $7, $8, (0x700002C0 & 0xFFFF)
    /* 2ACE3C 003ACE3C 40080635 */  ori        $6, $8, (0x70000840 & 0xFFFF)
    /* 2ACE40 003ACE40 40130535 */  ori        $5, $8, (0x70001340 & 0xFFFF)
  .L003ACE44:
    /* 2ACE44 003ACE44 00D0838C */  lw         $3, -0x3000($4)
    /* 2ACE48 003ACE48 00016330 */  andi       $3, $3, 0x100
    /* 2ACE4C 003ACE4C 0C006010 */  beqz       $3, .L003ACE80
    /* 2ACE50 003ACE50 00000000 */   nop
    /* 2ACE54 003ACE54 20E08CAC */  sw         $12, -0x1FE0($4)
    /* 2ACE58 003ACE58 0F000000 */  sync
    /* 2ACE5C 003ACE5C 0F040000 */  sync.p
  .L003ACE60:
    /* 2ACE60 003ACE60 00000000 */  nop
    /* 2ACE64 003ACE64 00000000 */  nop
    /* 2ACE68 003ACE68 00000000 */  nop
    /* 2ACE6C 003ACE6C 00000000 */  nop
    /* 2ACE70 003ACE70 00000000 */  nop
    /* 2ACE74 003ACE74 FAFF0041 */  bc0f       .L003ACE60 /* handwritten instruction */
    /* 2ACE78 003ACE78 00000000 */   nop
    /* 2ACE7C 003ACE7C 00000000 */  nop
  .L003ACE80:
    /* 2ACE80 003ACE80 00D4838C */  lw         $3, -0x2C00($4)
    /* 2ACE84 003ACE84 00016330 */  andi       $3, $3, 0x100
    /* 2ACE88 003ACE88 15006010 */  beqz       $3, .L003ACEE0
    /* 2ACE8C 003ACE8C 00000000 */   nop
    /* 2ACE90 003ACE90 20E08BAC */  sw         $11, -0x1FE0($4)
    /* 2ACE94 003ACE94 0F000000 */  sync
    /* 2ACE98 003ACE98 0F040000 */  sync.p
    /* 2ACE9C 003ACE9C 00000000 */  nop
  .L003ACEA0:
    /* 2ACEA0 003ACEA0 00000000 */  nop
    /* 2ACEA4 003ACEA4 00000000 */  nop
    /* 2ACEA8 003ACEA8 00000000 */  nop
    /* 2ACEAC 003ACEAC 00000000 */  nop
    /* 2ACEB0 003ACEB0 00000000 */  nop
    /* 2ACEB4 003ACEB4 FAFF0041 */  bc0f       .L003ACEA0 /* handwritten instruction */
    /* 2ACEB8 003ACEB8 00000000 */   nop
    /* 2ACEBC 003ACEBC 00000000 */  nop
  .L003ACEC0:
    /* 2ACEC0 003ACEC0 00D4838C */  lw         $3, -0x2C00($4)
    /* 2ACEC4 003ACEC4 00016330 */  andi       $3, $3, 0x100
    /* 2ACEC8 003ACEC8 00000000 */  nop
    /* 2ACECC 003ACECC 00000000 */  nop
    /* 2ACED0 003ACED0 00000000 */  nop
    /* 2ACED4 003ACED4 FAFF6014 */  bnez       $3, .L003ACEC0
    /* 2ACED8 003ACED8 00000000 */   nop
    /* 2ACEDC 003ACEDC 00000000 */  nop
  .L003ACEE0:
    /* 2ACEE0 003ACEE0 10E08BAC */  sw         $11, -0x1FF0($4)
    /* 2ACEE4 003ACEE4 80D480AC */  sw         $0, -0x2B80($4)
    /* 2ACEE8 003ACEE8 10D492AC */  sw         $18, -0x2BF0($4)
    /* 2ACEEC 003ACEEC 20D48AAC */  sw         $10, -0x2BE0($4)
    /* 2ACEF0 003ACEF0 00D48CAC */  sw         $12, -0x2C00($4)
    /* 2ACEF4 003ACEF4 0F000000 */  sync
    /* 2ACEF8 003ACEF8 0F040000 */  sync.p
    /* 2ACEFC 003ACEFC 00D4838C */  lw         $3, -0x2C00($4)
    /* 2ACF00 003ACF00 00016330 */  andi       $3, $3, 0x100
    /* 2ACF04 003ACF04 14006010 */  beqz       $3, .L003ACF58
    /* 2ACF08 003ACF08 00000000 */   nop
    /* 2ACF0C 003ACF0C 20E08BAC */  sw         $11, -0x1FE0($4)
    /* 2ACF10 003ACF10 0F000000 */  sync
    /* 2ACF14 003ACF14 0F040000 */  sync.p
  .L003ACF18:
    /* 2ACF18 003ACF18 00000000 */  nop
    /* 2ACF1C 003ACF1C 00000000 */  nop
    /* 2ACF20 003ACF20 00000000 */  nop
    /* 2ACF24 003ACF24 00000000 */  nop
    /* 2ACF28 003ACF28 00000000 */  nop
    /* 2ACF2C 003ACF2C FAFF0041 */  bc0f       .L003ACF18 /* handwritten instruction */
    /* 2ACF30 003ACF30 00000000 */   nop
    /* 2ACF34 003ACF34 00000000 */  nop
  .L003ACF38:
    /* 2ACF38 003ACF38 00D4838C */  lw         $3, -0x2C00($4)
    /* 2ACF3C 003ACF3C 00016330 */  andi       $3, $3, 0x100
    /* 2ACF40 003ACF40 00000000 */  nop
    /* 2ACF44 003ACF44 00000000 */  nop
    /* 2ACF48 003ACF48 00000000 */  nop
    /* 2ACF4C 003ACF4C FAFF6014 */  bnez       $3, .L003ACF38
    /* 2ACF50 003ACF50 00000000 */   nop
    /* 2ACF54 003ACF54 00000000 */  nop
  .L003ACF58:
    /* 2ACF58 003ACF58 10E08BAC */  sw         $11, -0x1FF0($4)
    /* 2ACF5C 003ACF5C 80D489AC */  sw         $9, -0x2B80($4)
    /* 2ACF60 003ACF60 10D490AC */  sw         $16, -0x2BF0($4)
    /* 2ACF64 003ACF64 20D497AC */  sw         $23, -0x2BE0($4)
    /* 2ACF68 003ACF68 00D48CAC */  sw         $12, -0x2C00($4)
    /* 2ACF6C 003ACF6C 0F000000 */  sync
    /* 2ACF70 003ACF70 0F040000 */  sync.p
    /* 2ACF74 003ACF74 00D4838C */  lw         $3, -0x2C00($4)
    /* 2ACF78 003ACF78 00016330 */  andi       $3, $3, 0x100
    /* 2ACF7C 003ACF7C 14006010 */  beqz       $3, .L003ACFD0
    /* 2ACF80 003ACF80 00000000 */   nop
    /* 2ACF84 003ACF84 20E08BAC */  sw         $11, -0x1FE0($4)
    /* 2ACF88 003ACF88 0F000000 */  sync
    /* 2ACF8C 003ACF8C 0F040000 */  sync.p
  .L003ACF90:
    /* 2ACF90 003ACF90 00000000 */  nop
    /* 2ACF94 003ACF94 00000000 */  nop
    /* 2ACF98 003ACF98 00000000 */  nop
    /* 2ACF9C 003ACF9C 00000000 */  nop
    /* 2ACFA0 003ACFA0 00000000 */  nop
    /* 2ACFA4 003ACFA4 FAFF0041 */  bc0f       .L003ACF90 /* handwritten instruction */
    /* 2ACFA8 003ACFA8 00000000 */   nop
    /* 2ACFAC 003ACFAC 00000000 */  nop
  .L003ACFB0:
    /* 2ACFB0 003ACFB0 00D4838C */  lw         $3, -0x2C00($4)
    /* 2ACFB4 003ACFB4 00016330 */  andi       $3, $3, 0x100
    /* 2ACFB8 003ACFB8 00000000 */  nop
    /* 2ACFBC 003ACFBC 00000000 */  nop
    /* 2ACFC0 003ACFC0 00000000 */  nop
    /* 2ACFC4 003ACFC4 FAFF6014 */  bnez       $3, .L003ACFB0
    /* 2ACFC8 003ACFC8 00000000 */   nop
    /* 2ACFCC 003ACFCC 00000000 */  nop
  .L003ACFD0:
    /* 2ACFD0 003ACFD0 10E08BAC */  sw         $11, -0x1FF0($4)
    /* 2ACFD4 003ACFD4 80D49EAC */  sw         $30, -0x2B80($4)
    /* 2ACFD8 003ACFD8 B0000324 */  addiu      $3, $0, 0xB0
    /* 2ACFDC 003ACFDC 10D493AC */  sw         $19, -0x2BF0($4)
    /* 2ACFE0 003ACFE0 20D483AC */  sw         $3, -0x2BE0($4)
    /* 2ACFE4 003ACFE4 00D48CAC */  sw         $12, -0x2C00($4)
    /* 2ACFE8 003ACFE8 0F000000 */  sync
    /* 2ACFEC 003ACFEC 0F040000 */  sync.p
    /* 2ACFF0 003ACFF0 00D4838C */  lw         $3, -0x2C00($4)
    /* 2ACFF4 003ACFF4 00016330 */  andi       $3, $3, 0x100
    /* 2ACFF8 003ACFF8 15006010 */  beqz       $3, .L003AD050
    /* 2ACFFC 003ACFFC 00000000 */   nop
    /* 2AD000 003AD000 20E08BAC */  sw         $11, -0x1FE0($4)
    /* 2AD004 003AD004 0F000000 */  sync
    /* 2AD008 003AD008 0F040000 */  sync.p
    /* 2AD00C 003AD00C 00000000 */  nop
  .L003AD010:
    /* 2AD010 003AD010 00000000 */  nop
    /* 2AD014 003AD014 00000000 */  nop
    /* 2AD018 003AD018 00000000 */  nop
    /* 2AD01C 003AD01C 00000000 */  nop
    /* 2AD020 003AD020 00000000 */  nop
    /* 2AD024 003AD024 FAFF0041 */  bc0f       .L003AD010 /* handwritten instruction */
    /* 2AD028 003AD028 00000000 */   nop
    /* 2AD02C 003AD02C 00000000 */  nop
  .L003AD030:
    /* 2AD030 003AD030 00D4838C */  lw         $3, -0x2C00($4)
    /* 2AD034 003AD034 00016330 */  andi       $3, $3, 0x100
    /* 2AD038 003AD038 00000000 */  nop
    /* 2AD03C 003AD03C 00000000 */  nop
    /* 2AD040 003AD040 00000000 */  nop
    /* 2AD044 003AD044 FAFF6014 */  bnez       $3, .L003AD030
    /* 2AD048 003AD048 00000000 */   nop
    /* 2AD04C 003AD04C 00000000 */  nop
  .L003AD050:
    /* 2AD050 003AD050 2DA80001 */  daddu      $21, $8, $0
    /* 2AD054 003AD054 2DC8E000 */  daddu      $25, $7, $0
    /* 2AD058 003AD058 2DC0C000 */  daddu      $24, $6, $0
    /* 2AD05C 003AD05C 2D78A000 */  daddu      $15, $5, $0
    /* 2AD060 003AD060 2DB00000 */  daddu      $22, $0, $0
    /* 2AD064 003AD064 00000000 */  nop
  .L003AD068:
    /* 2AD068 003AD068 0000A0C6 */  lwc1       $f0, (0x70000000 & 0xFFFF)($21)
    /* 2AD06C 003AD06C 0000C0E5 */  swc1       $f0, 0x0($14)
    /* 2AD070 003AD070 0400A0C6 */  lwc1       $f0, (0x70000004 & 0xFFFF)($21)
    /* 2AD074 003AD074 0400C0E5 */  swc1       $f0, 0x4($14)
    /* 2AD078 003AD078 0000A0C6 */  lwc1       $f0, (0x70000000 & 0xFFFF)($21)
    /* 2AD07C 003AD07C 0800C0E5 */  swc1       $f0, 0x8($14)
    /* 2AD080 003AD080 0400A0C6 */  lwc1       $f0, (0x70000004 & 0xFFFF)($21)
    /* 2AD084 003AD084 0C00C0E5 */  swc1       $f0, 0xC($14)
  .L003AD088:
    /* 2AD088 003AD088 39000042 */  di /* handwritten instruction */
    /* 2AD08C 003AD08C 0F040000 */  sync.p
    /* 2AD090 003AD090 00600D40 */  mfc0       $13, $12 /* handwritten instruction */
    /* 2AD094 003AD094 0100033C */  lui        $3, (0x10000 >> 16)
    /* 2AD098 003AD098 2468A301 */  and        $13, $13, $3
    /* 2AD09C 003AD09C 00000000 */  nop
    /* 2AD0A0 003AD0A0 F9FFA015 */  bnez       $13, .L003AD088
    /* 2AD0A4 003AD0A4 00000000 */   nop
    /* 2AD0A8 003AD0A8 0000C1D9 */  lqc2       $vf1, 0x0($14)
    /* 2AD0AC 003AD0AC FD09874B */  vabs.xy    $vf7, $vf1
    /* 2AD0B0 003AD0B0 3C00EA4B */  vaddax.xyzw $ACC, $vf0, $vf10x
    /* 2AD0B4 003AD0B4 CF39804B */  vmsubw.xy  $vf7, $vf7, $vf0w
    /* 2AD0B8 003AD0B8 3D00CA4B */  vadday.xyz $ACC, $vf0, $vf10y
    /* 2AD0BC 003AD0BC 3E002A4A */  vaddaz.w   $ACC, $vf0, $vf10z
    /* 2AD0C0 003AD0C0 8F08604A */  vmsubw.zw  $vf2, $vf1, $vf0w
    /* 2AD0C4 003AD0C4 3C00CB4B */  vaddax.xyz $ACC, $vf0, $vf11x
    /* 2AD0C8 003AD0C8 3D002B4A */  vadday.w   $ACC, $vf0, $vf11y
    /* 2AD0CC 003AD0CC CF08604A */  vmsubw.zw  $vf3, $vf1, $vf0w
    /* 2AD0D0 003AD0D0 AF08624A */  vmini.zw   $vf2, $vf1, $vf2
    /* 2AD0D4 003AD0D4 EB11634A */  vmax.zw    $vf7, $vf2, $vf3
    /* 2AD0D8 003AD0D8 AA38E74B */  vmul.xyzw  $vf2, $vf7, $vf7
    /* 2AD0DC 003AD0DC 9A39EB4B */  vmulz.xyzw $vf6, $vf7, $vf11z
    /* 2AD0E0 003AD0E0 1839EC4B */  vmulx.xyzw $vf4, $vf7, $vf12x
    /* 2AD0E4 003AD0E4 5939EC4B */  vmuly.xyzw $vf5, $vf7, $vf12y
    /* 2AD0E8 003AD0E8 EA10E24B */  vmul.xyzw  $vf3, $vf2, $vf2
    /* 2AD0EC 003AD0EC AA31E24B */  vmul.xyzw  $vf6, $vf6, $vf2
    /* 2AD0F0 003AD0F0 BE22E24B */  vmula.xyzw $ACC, $vf4, $vf2
    /* 2AD0F4 003AD0F4 1A39EC4B */  vmulz.xyzw $vf4, $vf7, $vf12z
    /* 2AD0F8 003AD0F8 AA18E34B */  vmul.xyzw  $vf2, $vf3, $vf3
    /* 2AD0FC 003AD0FC BD32E34B */  vmadda.xyzw $ACC, $vf6, $vf3
    /* 2AD100 003AD100 BD2AE34B */  vmadda.xyzw $ACC, $vf5, $vf3
    /* 2AD104 003AD104 BC38ED4B */  vmaddax.xyzw $ACC, $vf7, $vf13x
    /* 2AD108 003AD108 E921E24B */  vmadd.xyzw $vf7, $vf4, $vf2
    /* 2AD10C 003AD10C 000014DB */  lqc2       $vf20, 0x0($24)
    /* 2AD110 003AD110 10001BDB */  lqc2       $vf27, 0x10($24)
    /* 2AD114 003AD114 00002EDB */  lqc2       $vf14, 0x0($25)
    /* 2AD118 003AD118 BC41E74B */  vmulax.xyzw $ACC, $vf8, $vf7x
    /* 2AD11C 003AD11C 8E4CE74B */  vmsubz.xyzw $vf18, $vf9, $vf7z
    /* 2AD120 003AD120 BC49E74B */  vmulax.xyzw $ACC, $vf9, $vf7x
    /* 2AD124 003AD124 CA44E74B */  vmaddz.xyzw $vf19, $vf8, $vf7z
    /* 2AD128 003AD128 BD41E74B */  vmulay.xyzw $ACC, $vf8, $vf7y
    /* 2AD12C 003AD12C 4F4EE74B */  vmsubw.xyzw $vf25, $vf9, $vf7w
    /* 2AD130 003AD130 BD49E74B */  vmulay.xyzw $ACC, $vf9, $vf7y
    /* 2AD134 003AD134 8B46E74B */  vmaddw.xyzw $vf26, $vf8, $vf7w
    /* 2AD138 003AD138 9894EE4B */  vmulx.xyzw $vf18, $vf18, $vf14x
    /* 2AD13C 003AD13C D99CEE4B */  vmuly.xyzw $vf19, $vf19, $vf14y
    /* 2AD140 003AD140 5ACEEE4B */  vmulz.xyzw $vf25, $vf25, $vf14z
    /* 2AD144 003AD144 9BD6EE4B */  vmulw.xyzw $vf26, $vf26, $vf14w
    /* 2AD148 003AD148 6CA5F24B */  vsub.xyzw  $vf21, $vf20, $vf18
    /* 2AD14C 003AD14C A8A5F24B */  vadd.xyzw  $vf22, $vf20, $vf18
    /* 2AD150 003AD150 E8A5F24B */  vadd.xyzw  $vf23, $vf20, $vf18
    /* 2AD154 003AD154 2CA6F24B */  vsub.xyzw  $vf24, $vf20, $vf18
    /* 2AD158 003AD158 6CADF34B */  vsub.xyzw  $vf21, $vf21, $vf19
    /* 2AD15C 003AD15C ACB5F34B */  vsub.xyzw  $vf22, $vf22, $vf19
    /* 2AD160 003AD160 E8BDF34B */  vadd.xyzw  $vf23, $vf23, $vf19
    /* 2AD164 003AD164 28C6F34B */  vadd.xyzw  $vf24, $vf24, $vf19
    /* 2AD168 003AD168 2CDFF94B */  vsub.xyzw  $vf28, $vf27, $vf25
    /* 2AD16C 003AD16C 68DFF94B */  vadd.xyzw  $vf29, $vf27, $vf25
    /* 2AD170 003AD170 A8DFF94B */  vadd.xyzw  $vf30, $vf27, $vf25
    /* 2AD174 003AD174 ECDFF94B */  vsub.xyzw  $vf31, $vf27, $vf25
    /* 2AD178 003AD178 2CE7FA4B */  vsub.xyzw  $vf28, $vf28, $vf26
    /* 2AD17C 003AD17C 6CEFFA4B */  vsub.xyzw  $vf29, $vf29, $vf26
    /* 2AD180 003AD180 A8F7FA4B */  vadd.xyzw  $vf30, $vf30, $vf26
    /* 2AD184 003AD184 E8FFFA4B */  vadd.xyzw  $vf31, $vf31, $vf26
    /* 2AD188 003AD188 0000F5F9 */  sqc2       $vf21, 0x0($15)
    /* 2AD18C 003AD18C 1000F6F9 */  sqc2       $vf22, 0x10($15)
    /* 2AD190 003AD190 2000F7F9 */  sqc2       $vf23, 0x20($15)
    /* 2AD194 003AD194 3000F8F9 */  sqc2       $vf24, 0x30($15)
    /* 2AD198 003AD198 4000FCF9 */  sqc2       $vf28, 0x40($15)
    /* 2AD19C 003AD19C 5000FDF9 */  sqc2       $vf29, 0x50($15)
    /* 2AD1A0 003AD1A0 6000FEF9 */  sqc2       $vf30, 0x60($15)
    /* 2AD1A4 003AD1A4 7000FFF9 */  sqc2       $vf31, 0x70($15)
    /* 2AD1A8 003AD1A8 38000042 */  ei /* handwritten instruction */
    /* 2AD1AC 003AD1AC 0200D626 */  addiu      $22, $22, 0x2
    /* 2AD1B0 003AD1B0 B000C32A */  slti       $3, $22, 0xB0
    /* 2AD1B4 003AD1B4 20001827 */  addiu      $24, $24, 0x20
    /* 2AD1B8 003AD1B8 10003927 */  addiu      $25, $25, 0x10
    /* 2AD1BC 003AD1BC 0800B526 */  addiu      $21, $21, %lo(D_70000008)
    /* 2AD1C0 003AD1C0 A9FF6014 */  bnez       $3, .L003AD068
    /* 2AD1C4 003AD1C4 8000EF25 */   addiu     $15, $15, 0x80
    /* 2AD1C8 003AD1C8 00D0838C */  lw         $3, -0x3000($4)
    /* 2AD1CC 003AD1CC 00016330 */  andi       $3, $3, 0x100
    /* 2AD1D0 003AD1D0 0D006010 */  beqz       $3, .L003AD208
    /* 2AD1D4 003AD1D4 00000000 */   nop
    /* 2AD1D8 003AD1D8 20E08CAC */  sw         $12, -0x1FE0($4)
    /* 2AD1DC 003AD1DC 0F000000 */  sync
    /* 2AD1E0 003AD1E0 0F040000 */  sync.p
    /* 2AD1E4 003AD1E4 00000000 */  nop
  .L003AD1E8:
    /* 2AD1E8 003AD1E8 00000000 */  nop
    /* 2AD1EC 003AD1EC 00000000 */  nop
    /* 2AD1F0 003AD1F0 00000000 */  nop
    /* 2AD1F4 003AD1F4 00000000 */  nop
    /* 2AD1F8 003AD1F8 00000000 */  nop
    /* 2AD1FC 003AD1FC FAFF0041 */  bc0f       .L003AD1E8 /* handwritten instruction */
    /* 2AD200 003AD200 00000000 */   nop
    /* 2AD204 003AD204 00000000 */  nop
  .L003AD208:
    /* 2AD208 003AD208 00D4838C */  lw         $3, -0x2C00($4)
    /* 2AD20C 003AD20C 00016330 */  andi       $3, $3, 0x100
    /* 2AD210 003AD210 15006010 */  beqz       $3, .L003AD268
    /* 2AD214 003AD214 00000000 */   nop
    /* 2AD218 003AD218 20E08BAC */  sw         $11, -0x1FE0($4)
    /* 2AD21C 003AD21C 0F000000 */  sync
    /* 2AD220 003AD220 0F040000 */  sync.p
    /* 2AD224 003AD224 00000000 */  nop
  .L003AD228:
    /* 2AD228 003AD228 00000000 */  nop
    /* 2AD22C 003AD22C 00000000 */  nop
    /* 2AD230 003AD230 00000000 */  nop
    /* 2AD234 003AD234 00000000 */  nop
    /* 2AD238 003AD238 00000000 */  nop
    /* 2AD23C 003AD23C FAFF0041 */  bc0f       .L003AD228 /* handwritten instruction */
    /* 2AD240 003AD240 00000000 */   nop
    /* 2AD244 003AD244 00000000 */  nop
  .L003AD248:
    /* 2AD248 003AD248 00D4838C */  lw         $3, -0x2C00($4)
    /* 2AD24C 003AD24C 00016330 */  andi       $3, $3, 0x100
    /* 2AD250 003AD250 00000000 */  nop
    /* 2AD254 003AD254 00000000 */  nop
    /* 2AD258 003AD258 00000000 */  nop
    /* 2AD25C 003AD25C FAFF6014 */  bnez       $3, .L003AD248
    /* 2AD260 003AD260 00000000 */   nop
    /* 2AD264 003AD264 00000000 */  nop
  .L003AD268:
    /* 2AD268 003AD268 10E08CAC */  sw         $12, -0x1FF0($4)
    /* 2AD26C 003AD26C 40130324 */  addiu      $3, $0, 0x1340
    /* 2AD270 003AD270 80D083AC */  sw         $3, -0x2F80($4)
    /* 2AD274 003AD274 10D091AC */  sw         $17, -0x2FF0($4)
    /* 2AD278 003AD278 20D089AC */  sw         $9, -0x2FE0($4)
    /* 2AD27C 003AD27C 00D08CAC */  sw         $12, -0x3000($4)
    /* 2AD280 003AD280 0F000000 */  sync
    /* 2AD284 003AD284 0F040000 */  sync.p
    /* 2AD288 003AD288 50FF9426 */  addiu      $20, $20, -0xB0
    /* 2AD28C 003AD28C 000B7326 */  addiu      $19, $19, 0xB00
    /* 2AD290 003AD290 B000812A */  slti       $1, $20, 0xB0
    /* 2AD294 003AD294 002C3126 */  addiu      $17, $17, 0x2C00
    /* 2AD298 003AD298 C0025226 */  addiu      $18, $18, 0x2C0
    /* 2AD29C 003AD29C E9FE2010 */  beqz       $1, .L003ACE44
    /* 2AD2A0 003AD2A0 80051026 */   addiu     $16, $16, 0x580
    /* 2AD2A4 003AD2A4 00000000 */  nop
  .L003AD2A8:
    /* 2AD2A8 003AD2A8 0400812A */  slti       $1, $20, 0x4
    /* 2AD2AC 003AD2AC 42012014 */  bnez       $1, .L003AD7B8
    /* 2AD2B0 003AD2B0 00000000 */   nop
    /* 2AD2B4 003AD2B4 03008106 */  bgez       $20, .L003AD2C4
    /* 2AD2B8 003AD2B8 83181400 */   sra       $3, $20, 2
    /* 2AD2BC 003AD2BC 03008326 */  addiu      $3, $20, 0x3
    /* 2AD2C0 003AD2C0 83180300 */  sra        $3, $3, 2
  .L003AD2C4:
    /* 2AD2C4 003AD2C4 0110043C */  lui        $4, (0x10010000 >> 16)
    /* 2AD2C8 003AD2C8 00D0858C */  lw         $5, -0x3000($4)
    /* 2AD2CC 003AD2CC 0001A530 */  andi       $5, $5, 0x100
    /* 2AD2D0 003AD2D0 0C00A010 */  beqz       $5, .L003AD304
    /* 2AD2D4 003AD2D4 80180300 */   sll       $3, $3, 2
    /* 2AD2D8 003AD2D8 00010524 */  addiu      $5, $0, 0x100
    /* 2AD2DC 003AD2DC 20E085AC */  sw         $5, -0x1FE0($4)
    /* 2AD2E0 003AD2E0 0F000000 */  sync
    /* 2AD2E4 003AD2E4 0F040000 */  sync.p
  .L003AD2E8:
    /* 2AD2E8 003AD2E8 00000000 */  nop
    /* 2AD2EC 003AD2EC 00000000 */  nop
    /* 2AD2F0 003AD2F0 00000000 */  nop
    /* 2AD2F4 003AD2F4 00000000 */  nop
    /* 2AD2F8 003AD2F8 00000000 */  nop
    /* 2AD2FC 003AD2FC FAFF0041 */  bc0f       .L003AD2E8 /* handwritten instruction */
    /* 2AD300 003AD300 00000000 */   nop
  .L003AD304:
    /* 2AD304 003AD304 0110043C */  lui        $4, (0x10010000 >> 16)
    /* 2AD308 003AD308 00D4858C */  lw         $5, -0x2C00($4)
    /* 2AD30C 003AD30C 0001A530 */  andi       $5, $5, 0x100
    /* 2AD310 003AD310 1500A010 */  beqz       $5, .L003AD368
    /* 2AD314 003AD314 00000000 */   nop
    /* 2AD318 003AD318 00020524 */  addiu      $5, $0, 0x200
    /* 2AD31C 003AD31C 20E085AC */  sw         $5, -0x1FE0($4)
    /* 2AD320 003AD320 0F000000 */  sync
    /* 2AD324 003AD324 0F040000 */  sync.p
  .L003AD328:
    /* 2AD328 003AD328 00000000 */  nop
    /* 2AD32C 003AD32C 00000000 */  nop
    /* 2AD330 003AD330 00000000 */  nop
    /* 2AD334 003AD334 00000000 */  nop
    /* 2AD338 003AD338 00000000 */  nop
    /* 2AD33C 003AD33C FAFF0041 */  bc0f       .L003AD328 /* handwritten instruction */
    /* 2AD340 003AD340 00000000 */   nop
    /* 2AD344 003AD344 0110043C */  lui        $4, (0x10010000 >> 16)
  .L003AD348:
    /* 2AD348 003AD348 00D4858C */  lw         $5, -0x2C00($4)
    /* 2AD34C 003AD34C 0001A530 */  andi       $5, $5, 0x100
    /* 2AD350 003AD350 00000000 */  nop
    /* 2AD354 003AD354 00000000 */  nop
    /* 2AD358 003AD358 00000000 */  nop
    /* 2AD35C 003AD35C FAFFA014 */  bnez       $5, .L003AD348
    /* 2AD360 003AD360 00000000 */   nop
    /* 2AD364 003AD364 00000000 */  nop
  .L003AD368:
    /* 2AD368 003AD368 00020524 */  addiu      $5, $0, 0x200
    /* 2AD36C 003AD36C 0110043C */  lui        $4, (0x10010000 >> 16)
    /* 2AD370 003AD370 83300300 */  sra        $6, $3, 2
    /* 2AD374 003AD374 10E085AC */  sw         $5, -0x1FF0($4)
    /* 2AD378 003AD378 80D480AC */  sw         $0, -0x2B80($4)
    /* 2AD37C 003AD37C 03006104 */  bgez       $3, .L003AD38C
    /* 2AD380 003AD380 10D492AC */   sw        $18, -0x2BF0($4)
    /* 2AD384 003AD384 03006424 */  addiu      $4, $3, 0x3
    /* 2AD388 003AD388 83300400 */  sra        $6, $4, 2
  .L003AD38C:
    /* 2AD38C 003AD38C 0110043C */  lui        $4, (0x10010000 >> 16)
    /* 2AD390 003AD390 00010524 */  addiu      $5, $0, 0x100
    /* 2AD394 003AD394 20D486AC */  sw         $6, -0x2BE0($4)
    /* 2AD398 003AD398 00D485AC */  sw         $5, -0x2C00($4)
    /* 2AD39C 003AD39C 0F000000 */  sync
    /* 2AD3A0 003AD3A0 0F040000 */  sync.p
    /* 2AD3A4 003AD3A4 00D4858C */  lw         $5, -0x2C00($4)
    /* 2AD3A8 003AD3A8 0001A530 */  andi       $5, $5, 0x100
    /* 2AD3AC 003AD3AC 1400A010 */  beqz       $5, .L003AD400
    /* 2AD3B0 003AD3B0 00000000 */   nop
    /* 2AD3B4 003AD3B4 00020524 */  addiu      $5, $0, 0x200
    /* 2AD3B8 003AD3B8 20E085AC */  sw         $5, -0x1FE0($4)
    /* 2AD3BC 003AD3BC 0F000000 */  sync
    /* 2AD3C0 003AD3C0 0F040000 */  sync.p
  .L003AD3C4:
    /* 2AD3C4 003AD3C4 00000000 */  nop
    /* 2AD3C8 003AD3C8 00000000 */  nop
    /* 2AD3CC 003AD3CC 00000000 */  nop
    /* 2AD3D0 003AD3D0 00000000 */  nop
    /* 2AD3D4 003AD3D4 00000000 */  nop
    /* 2AD3D8 003AD3D8 FAFF0041 */  bc0f       .L003AD3C4 /* handwritten instruction */
    /* 2AD3DC 003AD3DC 00000000 */   nop
    /* 2AD3E0 003AD3E0 0110043C */  lui        $4, (0x10010000 >> 16)
  .L003AD3E4:
    /* 2AD3E4 003AD3E4 00D4858C */  lw         $5, -0x2C00($4)
    /* 2AD3E8 003AD3E8 0001A530 */  andi       $5, $5, 0x100
    /* 2AD3EC 003AD3EC 00000000 */  nop
    /* 2AD3F0 003AD3F0 00000000 */  nop
    /* 2AD3F4 003AD3F4 00000000 */  nop
    /* 2AD3F8 003AD3F8 FAFFA014 */  bnez       $5, .L003AD3E4
    /* 2AD3FC 003AD3FC 00000000 */   nop
  .L003AD400:
    /* 2AD400 003AD400 00020624 */  addiu      $6, $0, 0x200
    /* 2AD404 003AD404 0110043C */  lui        $4, (0x10010000 >> 16)
    /* 2AD408 003AD408 C0020524 */  addiu      $5, $0, 0x2C0
    /* 2AD40C 003AD40C 10E086AC */  sw         $6, -0x1FF0($4)
    /* 2AD410 003AD410 80D485AC */  sw         $5, -0x2B80($4)
    /* 2AD414 003AD414 43300300 */  sra        $6, $3, 1
    /* 2AD418 003AD418 03006104 */  bgez       $3, .L003AD428
    /* 2AD41C 003AD41C 10D490AC */   sw        $16, -0x2BF0($4)
    /* 2AD420 003AD420 01006424 */  addiu      $4, $3, 0x1
    /* 2AD424 003AD424 43300400 */  sra        $6, $4, 1
  .L003AD428:
    /* 2AD428 003AD428 0110043C */  lui        $4, (0x10010000 >> 16)
    /* 2AD42C 003AD42C 00010524 */  addiu      $5, $0, 0x100
    /* 2AD430 003AD430 20D486AC */  sw         $6, -0x2BE0($4)
    /* 2AD434 003AD434 00D485AC */  sw         $5, -0x2C00($4)
    /* 2AD438 003AD438 0F000000 */  sync
    /* 2AD43C 003AD43C 0F040000 */  sync.p
    /* 2AD440 003AD440 00D4858C */  lw         $5, -0x2C00($4)
    /* 2AD444 003AD444 0001A530 */  andi       $5, $5, 0x100
    /* 2AD448 003AD448 1500A010 */  beqz       $5, .L003AD4A0
    /* 2AD44C 003AD44C 00000000 */   nop
    /* 2AD450 003AD450 00020524 */  addiu      $5, $0, 0x200
    /* 2AD454 003AD454 20E085AC */  sw         $5, -0x1FE0($4)
    /* 2AD458 003AD458 0F000000 */  sync
    /* 2AD45C 003AD45C 0F040000 */  sync.p
  .L003AD460:
    /* 2AD460 003AD460 00000000 */  nop
    /* 2AD464 003AD464 00000000 */  nop
    /* 2AD468 003AD468 00000000 */  nop
    /* 2AD46C 003AD46C 00000000 */  nop
    /* 2AD470 003AD470 00000000 */  nop
    /* 2AD474 003AD474 FAFF0041 */  bc0f       .L003AD460 /* handwritten instruction */
    /* 2AD478 003AD478 00000000 */   nop
    /* 2AD47C 003AD47C 0110043C */  lui        $4, (0x10010000 >> 16)
  .L003AD480:
    /* 2AD480 003AD480 00D4858C */  lw         $5, -0x2C00($4)
    /* 2AD484 003AD484 0001A530 */  andi       $5, $5, 0x100
    /* 2AD488 003AD488 00000000 */  nop
    /* 2AD48C 003AD48C 00000000 */  nop
    /* 2AD490 003AD490 00000000 */  nop
    /* 2AD494 003AD494 FAFFA014 */  bnez       $5, .L003AD480
    /* 2AD498 003AD498 00000000 */   nop
    /* 2AD49C 003AD49C 00000000 */  nop
  .L003AD4A0:
    /* 2AD4A0 003AD4A0 00020724 */  addiu      $7, $0, 0x200
    /* 2AD4A4 003AD4A4 0110043C */  lui        $4, (0x10010000 >> 16)
    /* 2AD4A8 003AD4A8 40080624 */  addiu      $6, $0, 0x840
    /* 2AD4AC 003AD4AC 10E087AC */  sw         $7, -0x1FF0($4)
    /* 2AD4B0 003AD4B0 00010524 */  addiu      $5, $0, 0x100
    /* 2AD4B4 003AD4B4 80D486AC */  sw         $6, -0x2B80($4)
    /* 2AD4B8 003AD4B8 10D493AC */  sw         $19, -0x2BF0($4)
    /* 2AD4BC 003AD4BC 20D483AC */  sw         $3, -0x2BE0($4)
    /* 2AD4C0 003AD4C0 00D485AC */  sw         $5, -0x2C00($4)
    /* 2AD4C4 003AD4C4 0F000000 */  sync
    /* 2AD4C8 003AD4C8 0F040000 */  sync.p
    /* 2AD4CC 003AD4CC 00D4858C */  lw         $5, -0x2C00($4)
    /* 2AD4D0 003AD4D0 0001A530 */  andi       $5, $5, 0x100
    /* 2AD4D4 003AD4D4 1400A010 */  beqz       $5, .L003AD528
    /* 2AD4D8 003AD4D8 00000000 */   nop
    /* 2AD4DC 003AD4DC 20E087AC */  sw         $7, -0x1FE0($4)
    /* 2AD4E0 003AD4E0 0F000000 */  sync
    /* 2AD4E4 003AD4E4 0F040000 */  sync.p
  .L003AD4E8:
    /* 2AD4E8 003AD4E8 00000000 */  nop
    /* 2AD4EC 003AD4EC 00000000 */  nop
    /* 2AD4F0 003AD4F0 00000000 */  nop
    /* 2AD4F4 003AD4F4 00000000 */  nop
    /* 2AD4F8 003AD4F8 00000000 */  nop
    /* 2AD4FC 003AD4FC FAFF0041 */  bc0f       .L003AD4E8 /* handwritten instruction */
    /* 2AD500 003AD500 00000000 */   nop
    /* 2AD504 003AD504 0110043C */  lui        $4, (0x10010000 >> 16)
  .L003AD508:
    /* 2AD508 003AD508 00D4858C */  lw         $5, -0x2C00($4)
    /* 2AD50C 003AD50C 0001A530 */  andi       $5, $5, 0x100
    /* 2AD510 003AD510 00000000 */  nop
    /* 2AD514 003AD514 00000000 */  nop
    /* 2AD518 003AD518 00000000 */  nop
    /* 2AD51C 003AD51C FAFFA014 */  bnez       $5, .L003AD508
    /* 2AD520 003AD520 00000000 */   nop
    /* 2AD524 003AD524 00000000 */  nop
  .L003AD528:
    /* 2AD528 003AD528 0070073C */  lui        $7, (0x70001340 >> 16)
    /* 2AD52C 003AD52C 2A080300 */  slt        $1, $0, $3
    /* 2AD530 003AD530 C002F934 */  ori        $25, $7, (0x700002C0 & 0xFFFF)
    /* 2AD534 003AD534 4008F834 */  ori        $24, $7, (0x70000840 & 0xFFFF)
    /* 2AD538 003AD538 4013EF34 */  ori        $15, $7, (0x70001340 & 0xFFFF)
    /* 2AD53C 003AD53C 5A002010 */  beqz       $1, .L003AD6A8
    /* 2AD540 003AD540 2D300000 */   daddu     $6, $0, $0
    /* 2AD544 003AD544 0100053C */  lui        $5, (0x10000 >> 16)
  .L003AD548:
    /* 2AD548 003AD548 0000E0C4 */  lwc1       $f0, (0x70000000 & 0xFFFF)($7)
    /* 2AD54C 003AD54C 0000C0E5 */  swc1       $f0, 0x0($14)
    /* 2AD550 003AD550 0400E0C4 */  lwc1       $f0, (0x70000004 & 0xFFFF)($7)
    /* 2AD554 003AD554 0400C0E5 */  swc1       $f0, 0x4($14)
    /* 2AD558 003AD558 0000E0C4 */  lwc1       $f0, (0x70000000 & 0xFFFF)($7)
    /* 2AD55C 003AD55C 0800C0E5 */  swc1       $f0, 0x8($14)
    /* 2AD560 003AD560 0400E0C4 */  lwc1       $f0, (0x70000004 & 0xFFFF)($7)
    /* 2AD564 003AD564 0C00C0E5 */  swc1       $f0, 0xC($14)
  .L003AD568:
    /* 2AD568 003AD568 39000042 */  di /* handwritten instruction */
    /* 2AD56C 003AD56C 0F040000 */  sync.p
    /* 2AD570 003AD570 00600440 */  mfc0       $4, $12 /* handwritten instruction */
    /* 2AD574 003AD574 24208500 */  and        $4, $4, $5
    /* 2AD578 003AD578 00000000 */  nop
    /* 2AD57C 003AD57C FAFF8014 */  bnez       $4, .L003AD568
    /* 2AD580 003AD580 00000000 */   nop
    /* 2AD584 003AD584 0000C1D9 */  lqc2       $vf1, 0x0($14)
    /* 2AD588 003AD588 FD09874B */  vabs.xy    $vf7, $vf1
    /* 2AD58C 003AD58C 3C00EA4B */  vaddax.xyzw $ACC, $vf0, $vf10x
    /* 2AD590 003AD590 CF39804B */  vmsubw.xy  $vf7, $vf7, $vf0w
    /* 2AD594 003AD594 3D00CA4B */  vadday.xyz $ACC, $vf0, $vf10y
    /* 2AD598 003AD598 3E002A4A */  vaddaz.w   $ACC, $vf0, $vf10z
    /* 2AD59C 003AD59C 8F08604A */  vmsubw.zw  $vf2, $vf1, $vf0w
    /* 2AD5A0 003AD5A0 3C00CB4B */  vaddax.xyz $ACC, $vf0, $vf11x
    /* 2AD5A4 003AD5A4 3D002B4A */  vadday.w   $ACC, $vf0, $vf11y
    /* 2AD5A8 003AD5A8 CF08604A */  vmsubw.zw  $vf3, $vf1, $vf0w
    /* 2AD5AC 003AD5AC AF08624A */  vmini.zw   $vf2, $vf1, $vf2
    /* 2AD5B0 003AD5B0 EB11634A */  vmax.zw    $vf7, $vf2, $vf3
    /* 2AD5B4 003AD5B4 AA38E74B */  vmul.xyzw  $vf2, $vf7, $vf7
    /* 2AD5B8 003AD5B8 9A39EB4B */  vmulz.xyzw $vf6, $vf7, $vf11z
    /* 2AD5BC 003AD5BC 1839EC4B */  vmulx.xyzw $vf4, $vf7, $vf12x
    /* 2AD5C0 003AD5C0 5939EC4B */  vmuly.xyzw $vf5, $vf7, $vf12y
    /* 2AD5C4 003AD5C4 EA10E24B */  vmul.xyzw  $vf3, $vf2, $vf2
    /* 2AD5C8 003AD5C8 AA31E24B */  vmul.xyzw  $vf6, $vf6, $vf2
    /* 2AD5CC 003AD5CC BE22E24B */  vmula.xyzw $ACC, $vf4, $vf2
    /* 2AD5D0 003AD5D0 1A39EC4B */  vmulz.xyzw $vf4, $vf7, $vf12z
    /* 2AD5D4 003AD5D4 AA18E34B */  vmul.xyzw  $vf2, $vf3, $vf3
    /* 2AD5D8 003AD5D8 BD32E34B */  vmadda.xyzw $ACC, $vf6, $vf3
    /* 2AD5DC 003AD5DC BD2AE34B */  vmadda.xyzw $ACC, $vf5, $vf3
    /* 2AD5E0 003AD5E0 BC38ED4B */  vmaddax.xyzw $ACC, $vf7, $vf13x
    /* 2AD5E4 003AD5E4 E921E24B */  vmadd.xyzw $vf7, $vf4, $vf2
    /* 2AD5E8 003AD5E8 000014DB */  lqc2       $vf20, 0x0($24)
    /* 2AD5EC 003AD5EC 10001BDB */  lqc2       $vf27, 0x10($24)
    /* 2AD5F0 003AD5F0 00002EDB */  lqc2       $vf14, 0x0($25)
    /* 2AD5F4 003AD5F4 BC41E74B */  vmulax.xyzw $ACC, $vf8, $vf7x
    /* 2AD5F8 003AD5F8 8E4CE74B */  vmsubz.xyzw $vf18, $vf9, $vf7z
    /* 2AD5FC 003AD5FC BC49E74B */  vmulax.xyzw $ACC, $vf9, $vf7x
    /* 2AD600 003AD600 CA44E74B */  vmaddz.xyzw $vf19, $vf8, $vf7z
    /* 2AD604 003AD604 BD41E74B */  vmulay.xyzw $ACC, $vf8, $vf7y
    /* 2AD608 003AD608 4F4EE74B */  vmsubw.xyzw $vf25, $vf9, $vf7w
    /* 2AD60C 003AD60C BD49E74B */  vmulay.xyzw $ACC, $vf9, $vf7y
    /* 2AD610 003AD610 8B46E74B */  vmaddw.xyzw $vf26, $vf8, $vf7w
    /* 2AD614 003AD614 9894EE4B */  vmulx.xyzw $vf18, $vf18, $vf14x
    /* 2AD618 003AD618 D99CEE4B */  vmuly.xyzw $vf19, $vf19, $vf14y
    /* 2AD61C 003AD61C 5ACEEE4B */  vmulz.xyzw $vf25, $vf25, $vf14z
    /* 2AD620 003AD620 9BD6EE4B */  vmulw.xyzw $vf26, $vf26, $vf14w
    /* 2AD624 003AD624 6CA5F24B */  vsub.xyzw  $vf21, $vf20, $vf18
    /* 2AD628 003AD628 A8A5F24B */  vadd.xyzw  $vf22, $vf20, $vf18
    /* 2AD62C 003AD62C E8A5F24B */  vadd.xyzw  $vf23, $vf20, $vf18
    /* 2AD630 003AD630 2CA6F24B */  vsub.xyzw  $vf24, $vf20, $vf18
    /* 2AD634 003AD634 6CADF34B */  vsub.xyzw  $vf21, $vf21, $vf19
    /* 2AD638 003AD638 ACB5F34B */  vsub.xyzw  $vf22, $vf22, $vf19
    /* 2AD63C 003AD63C E8BDF34B */  vadd.xyzw  $vf23, $vf23, $vf19
    /* 2AD640 003AD640 28C6F34B */  vadd.xyzw  $vf24, $vf24, $vf19
    /* 2AD644 003AD644 2CDFF94B */  vsub.xyzw  $vf28, $vf27, $vf25
    /* 2AD648 003AD648 68DFF94B */  vadd.xyzw  $vf29, $vf27, $vf25
    /* 2AD64C 003AD64C A8DFF94B */  vadd.xyzw  $vf30, $vf27, $vf25
    /* 2AD650 003AD650 ECDFF94B */  vsub.xyzw  $vf31, $vf27, $vf25
    /* 2AD654 003AD654 2CE7FA4B */  vsub.xyzw  $vf28, $vf28, $vf26
    /* 2AD658 003AD658 6CEFFA4B */  vsub.xyzw  $vf29, $vf29, $vf26
    /* 2AD65C 003AD65C A8F7FA4B */  vadd.xyzw  $vf30, $vf30, $vf26
    /* 2AD660 003AD660 E8FFFA4B */  vadd.xyzw  $vf31, $vf31, $vf26
    /* 2AD664 003AD664 0000F5F9 */  sqc2       $vf21, 0x0($15)
    /* 2AD668 003AD668 1000F6F9 */  sqc2       $vf22, 0x10($15)
    /* 2AD66C 003AD66C 2000F7F9 */  sqc2       $vf23, 0x20($15)
    /* 2AD670 003AD670 3000F8F9 */  sqc2       $vf24, 0x30($15)
    /* 2AD674 003AD674 4000FCF9 */  sqc2       $vf28, 0x40($15)
    /* 2AD678 003AD678 5000FDF9 */  sqc2       $vf29, 0x50($15)
    /* 2AD67C 003AD67C 6000FEF9 */  sqc2       $vf30, 0x60($15)
    /* 2AD680 003AD680 7000FFF9 */  sqc2       $vf31, 0x70($15)
    /* 2AD684 003AD684 38000042 */  ei /* handwritten instruction */
    /* 2AD688 003AD688 0200C624 */  addiu      $6, $6, 0x2
    /* 2AD68C 003AD68C 2A20C300 */  slt        $4, $6, $3
    /* 2AD690 003AD690 20001827 */  addiu      $24, $24, 0x20
    /* 2AD694 003AD694 10003927 */  addiu      $25, $25, 0x10
    /* 2AD698 003AD698 0800E724 */  addiu      $7, $7, %lo(D_70000008)
    /* 2AD69C 003AD69C AAFF8014 */  bnez       $4, .L003AD548
    /* 2AD6A0 003AD6A0 8000EF25 */   addiu     $15, $15, 0x80
    /* 2AD6A4 003AD6A4 00000000 */  nop
  .L003AD6A8:
    /* 2AD6A8 003AD6A8 0110043C */  lui        $4, (0x10010000 >> 16)
    /* 2AD6AC 003AD6AC 00D0858C */  lw         $5, -0x3000($4)
    /* 2AD6B0 003AD6B0 0001A530 */  andi       $5, $5, 0x100
    /* 2AD6B4 003AD6B4 0C00A010 */  beqz       $5, .L003AD6E8
    /* 2AD6B8 003AD6B8 00000000 */   nop
    /* 2AD6BC 003AD6BC 00010524 */  addiu      $5, $0, 0x100
    /* 2AD6C0 003AD6C0 20E085AC */  sw         $5, -0x1FE0($4)
    /* 2AD6C4 003AD6C4 0F000000 */  sync
    /* 2AD6C8 003AD6C8 0F040000 */  sync.p
  .L003AD6CC:
    /* 2AD6CC 003AD6CC 00000000 */  nop
    /* 2AD6D0 003AD6D0 00000000 */  nop
    /* 2AD6D4 003AD6D4 00000000 */  nop
    /* 2AD6D8 003AD6D8 00000000 */  nop
    /* 2AD6DC 003AD6DC 00000000 */  nop
    /* 2AD6E0 003AD6E0 FAFF0041 */  bc0f       .L003AD6CC /* handwritten instruction */
    /* 2AD6E4 003AD6E4 00000000 */   nop
  .L003AD6E8:
    /* 2AD6E8 003AD6E8 0110043C */  lui        $4, (0x10010000 >> 16)
    /* 2AD6EC 003AD6EC 00D4858C */  lw         $5, -0x2C00($4)
    /* 2AD6F0 003AD6F0 0001A530 */  andi       $5, $5, 0x100
    /* 2AD6F4 003AD6F4 1400A010 */  beqz       $5, .L003AD748
    /* 2AD6F8 003AD6F8 00000000 */   nop
    /* 2AD6FC 003AD6FC 00020524 */  addiu      $5, $0, 0x200
    /* 2AD700 003AD700 20E085AC */  sw         $5, -0x1FE0($4)
    /* 2AD704 003AD704 0F000000 */  sync
    /* 2AD708 003AD708 0F040000 */  sync.p
  .L003AD70C:
    /* 2AD70C 003AD70C 00000000 */  nop
    /* 2AD710 003AD710 00000000 */  nop
    /* 2AD714 003AD714 00000000 */  nop
    /* 2AD718 003AD718 00000000 */  nop
    /* 2AD71C 003AD71C 00000000 */  nop
    /* 2AD720 003AD720 FAFF0041 */  bc0f       .L003AD70C /* handwritten instruction */
    /* 2AD724 003AD724 00000000 */   nop
    /* 2AD728 003AD728 0110043C */  lui        $4, (0x10010000 >> 16)
  .L003AD72C:
    /* 2AD72C 003AD72C 00D4858C */  lw         $5, -0x2C00($4)
    /* 2AD730 003AD730 0001A530 */  andi       $5, $5, 0x100
    /* 2AD734 003AD734 00000000 */  nop
    /* 2AD738 003AD738 00000000 */  nop
    /* 2AD73C 003AD73C 00000000 */  nop
    /* 2AD740 003AD740 FAFFA014 */  bnez       $5, .L003AD72C
    /* 2AD744 003AD744 00000000 */   nop
  .L003AD748:
    /* 2AD748 003AD748 00010724 */  addiu      $7, $0, 0x100
    /* 2AD74C 003AD74C 0110043C */  lui        $4, (0x10010000 >> 16)
    /* 2AD750 003AD750 40130624 */  addiu      $6, $0, 0x1340
    /* 2AD754 003AD754 10E087AC */  sw         $7, -0x1FF0($4)
    /* 2AD758 003AD758 80280300 */  sll        $5, $3, 2
    /* 2AD75C 003AD75C 80D086AC */  sw         $6, -0x2F80($4)
    /* 2AD760 003AD760 10D091AC */  sw         $17, -0x2FF0($4)
    /* 2AD764 003AD764 20D085AC */  sw         $5, -0x2FE0($4)
    /* 2AD768 003AD768 00D087AC */  sw         $7, -0x3000($4)
    /* 2AD76C 003AD76C 0F000000 */  sync
    /* 2AD770 003AD770 0F040000 */  sync.p
    /* 2AD774 003AD774 00210500 */  sll        $4, $5, 4
    /* 2AD778 003AD778 00290300 */  sll        $5, $3, 4
    /* 2AD77C 003AD77C 21882402 */  addu       $17, $17, $4
    /* 2AD780 003AD780 21986502 */  addu       $19, $19, $5
    /* 2AD784 003AD784 03006104 */  bgez       $3, .L003AD794
    /* 2AD788 003AD788 83200300 */   sra       $4, $3, 2
    /* 2AD78C 003AD78C 03006424 */  addiu      $4, $3, 0x3
    /* 2AD790 003AD790 83200400 */  sra        $4, $4, 2
  .L003AD794:
    /* 2AD794 003AD794 00290400 */  sll        $5, $4, 4
    /* 2AD798 003AD798 43200300 */  sra        $4, $3, 1
    /* 2AD79C 003AD79C 03006104 */  bgez       $3, .L003AD7AC
    /* 2AD7A0 003AD7A0 21904502 */   addu      $18, $18, $5
    /* 2AD7A4 003AD7A4 01006424 */  addiu      $4, $3, 0x1
    /* 2AD7A8 003AD7A8 43200400 */  sra        $4, $4, 1
  .L003AD7AC:
    /* 2AD7AC 003AD7AC 00210400 */  sll        $4, $4, 4
    /* 2AD7B0 003AD7B0 23A08302 */  subu       $20, $20, $3
    /* 2AD7B4 003AD7B4 21800402 */  addu       $16, $16, $4
  .L003AD7B8:
    /* 2AD7B8 003AD7B8 2A081400 */  slt        $1, $0, $20
    /* 2AD7BC 003AD7BC 12012010 */  beqz       $1, .L003ADC08
    /* 2AD7C0 003AD7C0 2D300000 */   daddu     $6, $0, $0
    /* 2AD7C4 003AD7C4 A000A37B */  lq         $3, 0xA0($29)
    /* 2AD7C8 003AD7C8 0100053C */  lui        $5, (0x10000 >> 16)
    /* 2AD7CC 003AD7CC 80200300 */  sll        $4, $3, 2
  .L003AD7D0:
    /* 2AD7D0 003AD7D0 000040C6 */  lwc1       $f0, 0x0($18)
    /* 2AD7D4 003AD7D4 0000C0E5 */  swc1       $f0, 0x0($14)
    /* 2AD7D8 003AD7D8 000000C6 */  lwc1       $f0, 0x0($16)
    /* 2AD7DC 003AD7DC 0400C0E5 */  swc1       $f0, 0x4($14)
    /* 2AD7E0 003AD7E0 000040C6 */  lwc1       $f0, 0x0($18)
    /* 2AD7E4 003AD7E4 0800C0E5 */  swc1       $f0, 0x8($14)
    /* 2AD7E8 003AD7E8 040000C6 */  lwc1       $f0, 0x4($16)
    /* 2AD7EC 003AD7EC 0C00C0E5 */  swc1       $f0, 0xC($14)
  .L003AD7F0:
    /* 2AD7F0 003AD7F0 39000042 */  di /* handwritten instruction */
    /* 2AD7F4 003AD7F4 0F040000 */  sync.p
    /* 2AD7F8 003AD7F8 00600340 */  mfc0       $3, $12 /* handwritten instruction */
    /* 2AD7FC 003AD7FC 24186500 */  and        $3, $3, $5
    /* 2AD800 003AD800 00000000 */  nop
    /* 2AD804 003AD804 FAFF6014 */  bnez       $3, .L003AD7F0
    /* 2AD808 003AD808 00000000 */   nop
    /* 2AD80C 003AD80C 0000C1D9 */  lqc2       $vf1, 0x0($14)
    /* 2AD810 003AD810 FD09874B */  vabs.xy    $vf7, $vf1
    /* 2AD814 003AD814 3C00EA4B */  vaddax.xyzw $ACC, $vf0, $vf10x
    /* 2AD818 003AD818 CF39804B */  vmsubw.xy  $vf7, $vf7, $vf0w
    /* 2AD81C 003AD81C 3D00CA4B */  vadday.xyz $ACC, $vf0, $vf10y
    /* 2AD820 003AD820 3E002A4A */  vaddaz.w   $ACC, $vf0, $vf10z
    /* 2AD824 003AD824 8F08604A */  vmsubw.zw  $vf2, $vf1, $vf0w
    /* 2AD828 003AD828 3C00CB4B */  vaddax.xyz $ACC, $vf0, $vf11x
    /* 2AD82C 003AD82C 3D002B4A */  vadday.w   $ACC, $vf0, $vf11y
    /* 2AD830 003AD830 CF08604A */  vmsubw.zw  $vf3, $vf1, $vf0w
    /* 2AD834 003AD834 AF08624A */  vmini.zw   $vf2, $vf1, $vf2
    /* 2AD838 003AD838 EB11634A */  vmax.zw    $vf7, $vf2, $vf3
    /* 2AD83C 003AD83C AA38E74B */  vmul.xyzw  $vf2, $vf7, $vf7
    /* 2AD840 003AD840 9A39EB4B */  vmulz.xyzw $vf6, $vf7, $vf11z
    /* 2AD844 003AD844 1839EC4B */  vmulx.xyzw $vf4, $vf7, $vf12x
    /* 2AD848 003AD848 5939EC4B */  vmuly.xyzw $vf5, $vf7, $vf12y
    /* 2AD84C 003AD84C EA10E24B */  vmul.xyzw  $vf3, $vf2, $vf2
    /* 2AD850 003AD850 AA31E24B */  vmul.xyzw  $vf6, $vf6, $vf2
    /* 2AD854 003AD854 BE22E24B */  vmula.xyzw $ACC, $vf4, $vf2
    /* 2AD858 003AD858 1A39EC4B */  vmulz.xyzw $vf4, $vf7, $vf12z
    /* 2AD85C 003AD85C AA18E34B */  vmul.xyzw  $vf2, $vf3, $vf3
    /* 2AD860 003AD860 BD32E34B */  vmadda.xyzw $ACC, $vf6, $vf3
    /* 2AD864 003AD864 BD2AE34B */  vmadda.xyzw $ACC, $vf5, $vf3
    /* 2AD868 003AD868 BC38ED4B */  vmaddax.xyzw $ACC, $vf7, $vf13x
    /* 2AD86C 003AD86C E921E24B */  vmadd.xyzw $vf7, $vf4, $vf2
    /* 2AD870 003AD870 000074DA */  lqc2       $vf20, 0x0($19)
    /* 2AD874 003AD874 BC41E74B */  vmulax.xyzw $ACC, $vf8, $vf7x
    /* 2AD878 003AD878 8E4CE74B */  vmsubz.xyzw $vf18, $vf9, $vf7z
    /* 2AD87C 003AD87C 9994E14B */  vmuly.xyzw $vf18, $vf18, $vf1y
    /* 2AD880 003AD880 BC49E74B */  vmulax.xyzw $ACC, $vf9, $vf7x
    /* 2AD884 003AD884 CA44E74B */  vmaddz.xyzw $vf19, $vf8, $vf7z
    /* 2AD888 003AD888 DB9CE14B */  vmulw.xyzw $vf19, $vf19, $vf1w
    /* 2AD88C 003AD88C 6CA5F24B */  vsub.xyzw  $vf21, $vf20, $vf18
    /* 2AD890 003AD890 A8A5F24B */  vadd.xyzw  $vf22, $vf20, $vf18
    /* 2AD894 003AD894 E8A5F24B */  vadd.xyzw  $vf23, $vf20, $vf18
    /* 2AD898 003AD898 2CA6F24B */  vsub.xyzw  $vf24, $vf20, $vf18
    /* 2AD89C 003AD89C 6CADF34B */  vsub.xyzw  $vf21, $vf21, $vf19
    /* 2AD8A0 003AD8A0 ACB5F34B */  vsub.xyzw  $vf22, $vf22, $vf19
    /* 2AD8A4 003AD8A4 E8BDF34B */  vadd.xyzw  $vf23, $vf23, $vf19
    /* 2AD8A8 003AD8A8 28C6F34B */  vadd.xyzw  $vf24, $vf24, $vf19
    /* 2AD8AC 003AD8AC 000035FA */  sqc2       $vf21, 0x0($17)
    /* 2AD8B0 003AD8B0 100036FA */  sqc2       $vf22, 0x10($17)
    /* 2AD8B4 003AD8B4 200037FA */  sqc2       $vf23, 0x20($17)
    /* 2AD8B8 003AD8B8 300038FA */  sqc2       $vf24, 0x30($17)
    /* 2AD8BC 003AD8BC 38000042 */  ei /* handwritten instruction */
    /* 2AD8C0 003AD8C0 0100C624 */  addiu      $6, $6, 0x1
    /* 2AD8C4 003AD8C4 D000A37B */  lq         $3, 0xD0($29)
    /* 2AD8C8 003AD8C8 21986302 */  addu       $19, $19, $3
    /* 2AD8CC 003AD8CC B000A37B */  lq         $3, 0xB0($29)
    /* 2AD8D0 003AD8D0 21800302 */  addu       $16, $16, $3
    /* 2AD8D4 003AD8D4 C000A37B */  lq         $3, 0xC0($29)
    /* 2AD8D8 003AD8D8 21904302 */  addu       $18, $18, $3
    /* 2AD8DC 003AD8DC 2A18D400 */  slt        $3, $6, $20
    /* 2AD8E0 003AD8E0 BBFF6014 */  bnez       $3, .L003AD7D0
    /* 2AD8E4 003AD8E4 21882402 */   addu      $17, $17, $4
    /* 2AD8E8 003AD8E8 C7000010 */  b          .L003ADC08
    /* 2AD8EC 003AD8EC 00000000 */   nop
  .L003AD8F0:
    /* 2AD8F0 003AD8F0 0000A5C6 */  lwc1       $f5, 0x0($21)
    /* 2AD8F4 003AD8F4 003F043C */  lui        $4, (0x3F000000 >> 16)
    /* 2AD8F8 003AD8F8 0400A4C6 */  lwc1       $f4, 0x4($21)
    /* 2AD8FC 003AD8FC 0100033C */  lui        $3, (0x10000 >> 16)
    /* 2AD900 003AD900 0800A3C6 */  lwc1       $f3, 0x8($21)
    /* 2AD904 003AD904 0000C2C6 */  lwc1       $f2, 0x0($22)
    /* 2AD908 003AD908 00308444 */  mtc1       $4, $f6
    /* 2AD90C 003AD90C 0400C1C6 */  lwc1       $f1, 0x4($22)
    /* 2AD910 003AD910 0800C0C6 */  lwc1       $f0, 0x8($22)
    /* 2AD914 003AD914 42310546 */  mul.s      $f5, $f6, $f5
    /* 2AD918 003AD918 02310446 */  mul.s      $f4, $f6, $f4
    /* 2AD91C 003AD91C C2300346 */  mul.s      $f3, $f6, $f3
    /* 2AD920 003AD920 82300246 */  mul.s      $f2, $f6, $f2
    /* 2AD924 003AD924 42300146 */  mul.s      $f1, $f6, $f1
    /* 2AD928 003AD928 02300046 */  mul.s      $f0, $f6, $f0
    /* 2AD92C 003AD92C 0001A5E7 */  swc1       $f5, 0x100($29)
    /* 2AD930 003AD930 0401A4E7 */  swc1       $f4, 0x104($29)
    /* 2AD934 003AD934 0801A3E7 */  swc1       $f3, 0x108($29)
    /* 2AD938 003AD938 F000A2E7 */  swc1       $f2, 0xF0($29)
    /* 2AD93C 003AD93C F400A1E7 */  swc1       $f1, 0xF4($29)
    /* 2AD940 003AD940 F800A0E7 */  swc1       $f0, 0xF8($29)
  .L003AD944:
    /* 2AD944 003AD944 39000042 */  di /* handwritten instruction */
    /* 2AD948 003AD948 0F040000 */  sync.p
    /* 2AD94C 003AD94C 00600440 */  mfc0       $4, $12 /* handwritten instruction */
    /* 2AD950 003AD950 24208300 */  and        $4, $4, $3
    /* 2AD954 003AD954 00000000 */  nop
    /* 2AD958 003AD958 FAFF8014 */  bnez       $4, .L003AD944
    /* 2AD95C 003AD95C 00000000 */   nop
    /* 2AD960 003AD960 C93F013C */  lui        $1, (0x3FC90FDB >> 16)
    /* 2AD964 003AD964 DB0F2334 */  ori        $3, $1, (0x3FC90FDB & 0xFFFF)
    /* 2AD968 003AD968 00008344 */  mtc1       $3, $f0
    /* 2AD96C 003AD96C 00000344 */  mfc1       $3, $f0
    /* 2AD970 003AD970 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2AD974 003AD974 FF02004A */  vnop
    /* 2AD978 003AD978 FF02004A */  vnop
    /* 2AD97C 003AD97C A202004B */  vaddi.x    $vf10, $vf0, $I
    /* 2AD980 003AD980 4940013C */  lui        $1, (0x40490FDB >> 16)
    /* 2AD984 003AD984 DB0F2434 */  ori        $4, $1, (0x40490FDB & 0xFFFF)
    /* 2AD988 003AD988 00008444 */  mtc1       $4, $f0
    /* 2AD98C 003AD98C 00000344 */  mfc1       $3, $f0
    /* 2AD990 003AD990 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2AD994 003AD994 FF02004A */  vnop
    /* 2AD998 003AD998 FF02004A */  vnop
    /* 2AD99C 003AD99C A202804A */  vaddi.y    $vf10, $vf0, $I
    /* 2AD9A0 003AD9A0 0940013C */  lui        $1, (0x40090FDB >> 16)
    /* 2AD9A4 003AD9A4 DB0F2334 */  ori        $3, $1, (0x40090FDB & 0xFFFF)
    /* 2AD9A8 003AD9A8 00008344 */  mtc1       $3, $f0
    /* 2AD9AC 003AD9AC 00000344 */  mfc1       $3, $f0
    /* 2AD9B0 003AD9B0 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2AD9B4 003AD9B4 FF02004A */  vnop
    /* 2AD9B8 003AD9B8 FF02004A */  vnop
    /* 2AD9BC 003AD9BC A202404A */  vaddi.z    $vf10, $vf0, $I
    /* 2AD9C0 003AD9C0 00008444 */  mtc1       $4, $f0
    /* 2AD9C4 003AD9C4 07000046 */  neg.s      $f0, $f0
    /* 2AD9C8 003AD9C8 00000344 */  mfc1       $3, $f0
    /* 2AD9CC 003AD9CC 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2AD9D0 003AD9D0 FF02004A */  vnop
    /* 2AD9D4 003AD9D4 FF02004A */  vnop
    /* 2AD9D8 003AD9D8 E202004B */  vaddi.x    $vf11, $vf0, $I
    /* 2AD9DC 003AD9DC 8440013C */  lui        $1, (0x408487ED >> 16)
    /* 2AD9E0 003AD9E0 ED872334 */  ori        $3, $1, (0x408487ED & 0xFFFF)
    /* 2AD9E4 003AD9E4 00008344 */  mtc1       $3, $f0
    /* 2AD9E8 003AD9E8 07000046 */  neg.s      $f0, $f0
    /* 2AD9EC 003AD9EC 00000344 */  mfc1       $3, $f0
    /* 2AD9F0 003AD9F0 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2AD9F4 003AD9F4 FF02004A */  vnop
    /* 2AD9F8 003AD9F8 FF02004A */  vnop
    /* 2AD9FC 003AD9FC E202804A */  vaddi.y    $vf11, $vf0, $I
    /* 2ADA00 003ADA00 00000334 */  ori        $3, $0, 0x0
    /* 2ADA04 003ADA04 381C0300 */  dsll       $3, $3, 16
    /* 2ADA08 003ADA08 381C0300 */  dsll       $3, $3, 16
    /* 2ADA0C 003ADA0C 4FB96334 */  ori        $3, $3, 0xB94F
    /* 2ADA10 003ADA10 381C0300 */  dsll       $3, $3, 16
    /* 2ADA14 003ADA14 1FB26334 */  ori        $3, $3, 0xB21F
    /* 2ADA18 003ADA18 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2ADA1C 003ADA1C FF02004A */  vnop
    /* 2ADA20 003ADA20 FF02004A */  vnop
    /* 2ADA24 003ADA24 E202404A */  vaddi.z    $vf11, $vf0, $I
    /* 2ADA28 003ADA28 00000334 */  ori        $3, $0, 0x0
    /* 2ADA2C 003ADA2C 381C0300 */  dsll       $3, $3, 16
    /* 2ADA30 003ADA30 381C0300 */  dsll       $3, $3, 16
    /* 2ADA34 003ADA34 2ABE6334 */  ori        $3, $3, 0xBE2A
    /* 2ADA38 003ADA38 381C0300 */  dsll       $3, $3, 16
    /* 2ADA3C 003ADA3C A4AA6334 */  ori        $3, $3, 0xAAA4
    /* 2ADA40 003ADA40 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2ADA44 003ADA44 FF02004A */  vnop
    /* 2ADA48 003ADA48 FF02004A */  vnop
    /* 2ADA4C 003ADA4C 2203004B */  vaddi.x    $vf12, $vf0, $I
    /* 2ADA50 003ADA50 083C013C */  lui        $1, (0x3C08873E >> 16)
    /* 2ADA54 003ADA54 3E872334 */  ori        $3, $1, (0x3C08873E & 0xFFFF)
    /* 2ADA58 003ADA58 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2ADA5C 003ADA5C FF02004A */  vnop
    /* 2ADA60 003ADA60 FF02004A */  vnop
    /* 2ADA64 003ADA64 2203804A */  vaddi.y    $vf12, $vf0, $I
    /* 2ADA68 003ADA68 2E36013C */  lui        $1, (0x362E9C14 >> 16)
    /* 2ADA6C 003ADA6C 149C2334 */  ori        $3, $1, (0x362E9C14 & 0xFFFF)
    /* 2ADA70 003ADA70 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2ADA74 003ADA74 FF02004A */  vnop
    /* 2ADA78 003ADA78 FF02004A */  vnop
    /* 2ADA7C 003ADA7C 2203404A */  vaddi.z    $vf12, $vf0, $I
    /* 2ADA80 003ADA80 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* 2ADA84 003ADA84 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2ADA88 003ADA88 FF02004A */  vnop
    /* 2ADA8C 003ADA8C FF02004A */  vnop
    /* 2ADA90 003ADA90 6203004B */  vaddi.x    $vf13, $vf0, $I
    /* 2ADA94 003ADA94 38000042 */  ei /* handwritten instruction */
    /* 2ADA98 003ADA98 0100033C */  lui        $3, (0x10000 >> 16)
  .L003ADA9C:
    /* 2ADA9C 003ADA9C 39000042 */  di /* handwritten instruction */
    /* 2ADAA0 003ADAA0 0F040000 */  sync.p
    /* 2ADAA4 003ADAA4 00600440 */  mfc0       $4, $12 /* handwritten instruction */
    /* 2ADAA8 003ADAA8 24208300 */  and        $4, $4, $3
    /* 2ADAAC 003ADAAC 00000000 */  nop
    /* 2ADAB0 003ADAB0 FAFF8014 */  bnez       $4, .L003ADA9C
    /* 2ADAB4 003ADAB4 00000000 */   nop
    /* 2ADAB8 003ADAB8 0001A427 */  addiu      $4, $29, 0x100
    /* 2ADABC 003ADABC F000A327 */  addiu      $3, $29, 0xF0
    /* 2ADAC0 003ADAC0 000088D8 */  lqc2       $vf8, 0x0($4)
    /* 2ADAC4 003ADAC4 000069D8 */  lqc2       $vf9, 0x0($3)
    /* 2ADAC8 003ADAC8 38000042 */  ei /* handwritten instruction */
    /* 2ADACC 003ADACC 2A081400 */  slt        $1, $0, $20
    /* 2ADAD0 003ADAD0 4D002010 */  beqz       $1, .L003ADC08
    /* 2ADAD4 003ADAD4 2D500000 */   daddu     $10, $0, $0
    /* 2ADAD8 003ADAD8 A000A37B */  lq         $3, 0xA0($29)
    /* 2ADADC 003ADADC E400A927 */  addiu      $9, $29, 0xE4
    /* 2ADAE0 003ADAE0 E800A827 */  addiu      $8, $29, 0xE8
    /* 2ADAE4 003ADAE4 EC00A727 */  addiu      $7, $29, 0xEC
    /* 2ADAE8 003ADAE8 E000A527 */  addiu      $5, $29, 0xE0
    /* 2ADAEC 003ADAEC 0100063C */  lui        $6, (0x10000 >> 16)
    /* 2ADAF0 003ADAF0 80200300 */  sll        $4, $3, 2
  .L003ADAF4:
    /* 2ADAF4 003ADAF4 000042C6 */  lwc1       $f2, 0x0($18)
    /* 2ADAF8 003ADAF8 000001C6 */  lwc1       $f1, 0x0($16)
    /* 2ADAFC 003ADAFC 040000C6 */  lwc1       $f0, 0x4($16)
    /* 2ADB00 003ADB00 E000A2E7 */  swc1       $f2, 0xE0($29)
    /* 2ADB04 003ADB04 000002E5 */  swc1       $f2, 0x0($8)
    /* 2ADB08 003ADB08 000021E5 */  swc1       $f1, 0x0($9)
    /* 2ADB0C 003ADB0C 0000E0E4 */  swc1       $f0, 0x0($7)
  .L003ADB10:
    /* 2ADB10 003ADB10 39000042 */  di /* handwritten instruction */
    /* 2ADB14 003ADB14 0F040000 */  sync.p
    /* 2ADB18 003ADB18 00600340 */  mfc0       $3, $12 /* handwritten instruction */
    /* 2ADB1C 003ADB1C 24186600 */  and        $3, $3, $6
    /* 2ADB20 003ADB20 00000000 */  nop
    /* 2ADB24 003ADB24 FAFF6014 */  bnez       $3, .L003ADB10
    /* 2ADB28 003ADB28 00000000 */   nop
    /* 2ADB2C 003ADB2C 0000A1D8 */  lqc2       $vf1, 0x0($5)
    /* 2ADB30 003ADB30 FD09874B */  vabs.xy    $vf7, $vf1
    /* 2ADB34 003ADB34 3C00EA4B */  vaddax.xyzw $ACC, $vf0, $vf10x
    /* 2ADB38 003ADB38 CF39804B */  vmsubw.xy  $vf7, $vf7, $vf0w
    /* 2ADB3C 003ADB3C 3D00CA4B */  vadday.xyz $ACC, $vf0, $vf10y
    /* 2ADB40 003ADB40 3E002A4A */  vaddaz.w   $ACC, $vf0, $vf10z
    /* 2ADB44 003ADB44 8F08604A */  vmsubw.zw  $vf2, $vf1, $vf0w
    /* 2ADB48 003ADB48 3C00CB4B */  vaddax.xyz $ACC, $vf0, $vf11x
    /* 2ADB4C 003ADB4C 3D002B4A */  vadday.w   $ACC, $vf0, $vf11y
    /* 2ADB50 003ADB50 CF08604A */  vmsubw.zw  $vf3, $vf1, $vf0w
    /* 2ADB54 003ADB54 AF08624A */  vmini.zw   $vf2, $vf1, $vf2
    /* 2ADB58 003ADB58 EB11634A */  vmax.zw    $vf7, $vf2, $vf3
    /* 2ADB5C 003ADB5C AA38E74B */  vmul.xyzw  $vf2, $vf7, $vf7
    /* 2ADB60 003ADB60 9A39EB4B */  vmulz.xyzw $vf6, $vf7, $vf11z
    /* 2ADB64 003ADB64 1839EC4B */  vmulx.xyzw $vf4, $vf7, $vf12x
    /* 2ADB68 003ADB68 5939EC4B */  vmuly.xyzw $vf5, $vf7, $vf12y
    /* 2ADB6C 003ADB6C EA10E24B */  vmul.xyzw  $vf3, $vf2, $vf2
    /* 2ADB70 003ADB70 AA31E24B */  vmul.xyzw  $vf6, $vf6, $vf2
    /* 2ADB74 003ADB74 BE22E24B */  vmula.xyzw $ACC, $vf4, $vf2
    /* 2ADB78 003ADB78 1A39EC4B */  vmulz.xyzw $vf4, $vf7, $vf12z
    /* 2ADB7C 003ADB7C AA18E34B */  vmul.xyzw  $vf2, $vf3, $vf3
    /* 2ADB80 003ADB80 BD32E34B */  vmadda.xyzw $ACC, $vf6, $vf3
    /* 2ADB84 003ADB84 BD2AE34B */  vmadda.xyzw $ACC, $vf5, $vf3
    /* 2ADB88 003ADB88 BC38ED4B */  vmaddax.xyzw $ACC, $vf7, $vf13x
    /* 2ADB8C 003ADB8C E921E24B */  vmadd.xyzw $vf7, $vf4, $vf2
    /* 2ADB90 003ADB90 000074DA */  lqc2       $vf20, 0x0($19)
    /* 2ADB94 003ADB94 BC41E74B */  vmulax.xyzw $ACC, $vf8, $vf7x
    /* 2ADB98 003ADB98 8E4CE74B */  vmsubz.xyzw $vf18, $vf9, $vf7z
    /* 2ADB9C 003ADB9C 9994E14B */  vmuly.xyzw $vf18, $vf18, $vf1y
    /* 2ADBA0 003ADBA0 BC49E74B */  vmulax.xyzw $ACC, $vf9, $vf7x
    /* 2ADBA4 003ADBA4 CA44E74B */  vmaddz.xyzw $vf19, $vf8, $vf7z
    /* 2ADBA8 003ADBA8 DB9CE14B */  vmulw.xyzw $vf19, $vf19, $vf1w
    /* 2ADBAC 003ADBAC 6CA5F24B */  vsub.xyzw  $vf21, $vf20, $vf18
    /* 2ADBB0 003ADBB0 A8A5F24B */  vadd.xyzw  $vf22, $vf20, $vf18
    /* 2ADBB4 003ADBB4 E8A5F24B */  vadd.xyzw  $vf23, $vf20, $vf18
    /* 2ADBB8 003ADBB8 2CA6F24B */  vsub.xyzw  $vf24, $vf20, $vf18
    /* 2ADBBC 003ADBBC 6CADF34B */  vsub.xyzw  $vf21, $vf21, $vf19
    /* 2ADBC0 003ADBC0 ACB5F34B */  vsub.xyzw  $vf22, $vf22, $vf19
    /* 2ADBC4 003ADBC4 E8BDF34B */  vadd.xyzw  $vf23, $vf23, $vf19
    /* 2ADBC8 003ADBC8 28C6F34B */  vadd.xyzw  $vf24, $vf24, $vf19
    /* 2ADBCC 003ADBCC 000035FA */  sqc2       $vf21, 0x0($17)
    /* 2ADBD0 003ADBD0 100036FA */  sqc2       $vf22, 0x10($17)
    /* 2ADBD4 003ADBD4 200037FA */  sqc2       $vf23, 0x20($17)
    /* 2ADBD8 003ADBD8 300038FA */  sqc2       $vf24, 0x30($17)
    /* 2ADBDC 003ADBDC 38000042 */  ei /* handwritten instruction */
    /* 2ADBE0 003ADBE0 01004A25 */  addiu      $10, $10, 0x1
    /* 2ADBE4 003ADBE4 D000A37B */  lq         $3, 0xD0($29)
    /* 2ADBE8 003ADBE8 21986302 */  addu       $19, $19, $3
    /* 2ADBEC 003ADBEC B000A37B */  lq         $3, 0xB0($29)
    /* 2ADBF0 003ADBF0 21800302 */  addu       $16, $16, $3
    /* 2ADBF4 003ADBF4 C000A37B */  lq         $3, 0xC0($29)
    /* 2ADBF8 003ADBF8 21904302 */  addu       $18, $18, $3
    /* 2ADBFC 003ADBFC 2A185401 */  slt        $3, $10, $20
    /* 2ADC00 003ADC00 BCFF6014 */  bnez       $3, .L003ADAF4
    /* 2ADC04 003ADC04 21882402 */   addu      $17, $17, $4
  .L003ADC08:
    /* 2ADC08 003ADC08 9000BFDF */  ld         $31, 0x90($29)
    /* 2ADC0C 003ADC0C 8000BE7B */  lq         $30, 0x80($29)
    /* 2ADC10 003ADC10 7000B77B */  lq         $23, 0x70($29)
    /* 2ADC14 003ADC14 6000B67B */  lq         $22, 0x60($29)
    /* 2ADC18 003ADC18 5000B57B */  lq         $21, 0x50($29)
    /* 2ADC1C 003ADC1C 4000B47B */  lq         $20, 0x40($29)
    /* 2ADC20 003ADC20 3000B37B */  lq         $19, 0x30($29)
    /* 2ADC24 003ADC24 2000B27B */  lq         $18, 0x20($29)
    /* 2ADC28 003ADC28 1000B17B */  lq         $17, 0x10($29)
    /* 2ADC2C 003ADC2C 0000B07B */  lq         $16, 0x0($29)
    /* 2ADC30 003ADC30 0800E003 */  jr         $31
    /* 2ADC34 003ADC34 1001BD27 */   addiu     $29, $29, 0x110
    /* 2ADC38 003ADC38 00000000 */  nop
    /* 2ADC3C 003ADC3C 00000000 */  nop
.size func_003acb10, 0x1130
