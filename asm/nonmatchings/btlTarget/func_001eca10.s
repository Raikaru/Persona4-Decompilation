.section .text
.set noat
.set noreorder
glabel func_001eca10
    /* ECA10 001ECA10 50FFBD27 */  addiu      $29, $29, -0xB0
    /* ECA14 001ECA14 9000BFFF */  sd         $31, 0x90($29)
    /* ECA18 001ECA18 8000BE7F */  sq         $30, 0x80($29)
    /* ECA1C 001ECA1C 7000B77F */  sq         $23, 0x70($29)
    /* ECA20 001ECA20 6000B67F */  sq         $22, 0x60($29)
    /* ECA24 001ECA24 5000B57F */  sq         $21, 0x50($29)
    /* ECA28 001ECA28 4000B47F */  sq         $20, 0x40($29)
    /* ECA2C 001ECA2C 3000B37F */  sq         $19, 0x30($29)
    /* ECA30 001ECA30 2000B27F */  sq         $18, 0x20($29)
    /* ECA34 001ECA34 1000B17F */  sq         $17, 0x10($29)
    /* ECA38 001ECA38 0000B07F */  sq         $16, 0x0($29)
    /* ECA3C 001ECA3C 2D888000 */  daddu      $17, $4, $0
    /* ECA40 001ECA40 2D80A000 */  daddu      $16, $5, $0
    /* ECA44 001ECA44 2DA00000 */  daddu      $20, $0, $0
    /* ECA48 001ECA48 ACB3828F */  lw         $2, -0x4C54($28)
    /* ECA4C 001ECA4C 1803558C */  lw         $21, 0x318($2)
    /* ECA50 001ECA50 CE000010 */  b          .L001ECD8C
    /* ECA54 001ECA54 00000000 */   nop
  .L001ECA58:
    /* ECA58 001ECA58 2D980000 */  daddu      $19, $0, $0
    /* ECA5C 001ECA5C 65000010 */  b          .L001ECBF4
    /* ECA60 001ECA60 00000000 */   nop
  .L001ECA64:
    /* ECA64 001ECA64 C0101300 */  sll        $2, $19, 3
    /* ECA68 001ECA68 21105300 */  addu       $2, $2, $19
    /* ECA6C 001ECA6C 40100200 */  sll        $2, $2, 1
    /* ECA70 001ECA70 21105300 */  addu       $2, $2, $19
    /* ECA74 001ECA74 00110200 */  sll        $2, $2, 4
    /* ECA78 001ECA78 2110A202 */  addu       $2, $21, $2
    /* ECA7C 001ECA7C 1C0041C4 */  lwc1       $f1, 0x1C($2)
    /* ECA80 001ECA80 00008044 */  mtc1       $0, $f0
    /* ECA84 001ECA84 00000000 */  nop
    /* ECA88 001ECA88 36080046 */  c.le.s     $f1, $f0
    /* ECA8C 001ECA8C 58000145 */  bc1t       .L001ECBF0
    /* ECA90 001ECA90 00000000 */   nop
    /* ECA94 001ECA94 08005624 */  addiu      $22, $2, 0x8
    /* ECA98 001ECA98 5500D112 */  beq        $22, $17, .L001ECBF0
    /* ECA9C 001ECA9C 00000000 */   nop
    /* ECAA0 001ECAA0 5300D012 */  beq        $22, $16, .L001ECBF0
    /* ECAA4 001ECAA4 00000000 */   nop
    /* ECAA8 001ECAA8 10005224 */  addiu      $18, $2, 0x10
    /* ECAAC 001ECAAC 100041C4 */  lwc1       $f1, 0x10($2)
    /* ECAB0 001ECAB0 080020C6 */  lwc1       $f0, 0x8($17)
    /* ECAB4 001ECAB4 01080046 */  sub.s      $f0, $f1, $f0
    /* ECAB8 001ECAB8 A800A0E7 */  swc1       $f0, 0xA8($29)
    /* ECABC 001ECABC 14005724 */  addiu      $23, $2, 0x14
    /* ECAC0 001ECAC0 140041C4 */  lwc1       $f1, 0x14($2)
    /* ECAC4 001ECAC4 0C0020C6 */  lwc1       $f0, 0xC($17)
    /* ECAC8 001ECAC8 01080046 */  sub.s      $f0, $f1, $f0
    /* ECACC 001ECACC AC00A0E7 */  swc1       $f0, 0xAC($29)
    /* ECAD0 001ECAD0 A800A427 */  addiu      $4, $29, 0xA8
    /* ECAD4 001ECAD4 6C900F0C */  jal        func_003e41b0
    /* ECAD8 001ECAD8 00000000 */   nop
    /* ECADC 001ECADC 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* ECAE0 001ECAE0 00088244 */  mtc1       $2, $f1
    /* ECAE4 001ECAE4 00000000 */  nop
    /* ECAE8 001ECAE8 34000146 */  c.lt.s     $f0, $f1
    /* ECAEC 001ECAEC 40000145 */  bc1t       .L001ECBF0
    /* ECAF0 001ECAF0 00000000 */   nop
    /* ECAF4 001ECAF4 000041C6 */  lwc1       $f1, 0x0($18)
    /* ECAF8 001ECAF8 080000C6 */  lwc1       $f0, 0x8($16)
    /* ECAFC 001ECAFC 01080046 */  sub.s      $f0, $f1, $f0
    /* ECB00 001ECB00 A800A0E7 */  swc1       $f0, 0xA8($29)
    /* ECB04 001ECB04 0000E1C6 */  lwc1       $f1, 0x0($23)
    /* ECB08 001ECB08 0C0000C6 */  lwc1       $f0, 0xC($16)
    /* ECB0C 001ECB0C 01080046 */  sub.s      $f0, $f1, $f0
    /* ECB10 001ECB10 AC00A0E7 */  swc1       $f0, 0xAC($29)
    /* ECB14 001ECB14 A800A427 */  addiu      $4, $29, 0xA8
    /* ECB18 001ECB18 6C900F0C */  jal        func_003e41b0
    /* ECB1C 001ECB1C 00000000 */   nop
    /* ECB20 001ECB20 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* ECB24 001ECB24 00088244 */  mtc1       $2, $f1
    /* ECB28 001ECB28 00000000 */  nop
    /* ECB2C 001ECB2C 34000146 */  c.lt.s     $f0, $f1
    /* ECB30 001ECB30 2F000145 */  bc1t       .L001ECBF0
    /* ECB34 001ECB34 00000000 */   nop
    /* ECB38 001ECB38 C0101300 */  sll        $2, $19, 3
    /* ECB3C 001ECB3C 21105300 */  addu       $2, $2, $19
    /* ECB40 001ECB40 40100200 */  sll        $2, $2, 1
    /* ECB44 001ECB44 21105300 */  addu       $2, $2, $19
    /* ECB48 001ECB48 00110200 */  sll        $2, $2, 4
    /* ECB4C 001ECB4C 2110A202 */  addu       $2, $21, $2
    /* ECB50 001ECB50 1800528C */  lw         $18, 0x18($2)
    /* ECB54 001ECB54 08005724 */  addiu      $23, $2, 0x8
    /* ECB58 001ECB58 2D20E002 */  daddu      $4, $23, $0
    /* ECB5C 001ECB5C 2D284002 */  daddu      $5, $18, $0
    /* ECB60 001ECB60 08002626 */  addiu      $6, $17, 0x8
    /* ECB64 001ECB64 78B3070C */  jal        func_001ecde0
    /* ECB68 001ECB68 00000000 */   nop
    /* ECB6C 001ECB6C 2DF04000 */  daddu      $30, $2, $0
    /* ECB70 001ECB70 2D20E002 */  daddu      $4, $23, $0
    /* ECB74 001ECB74 2D284002 */  daddu      $5, $18, $0
    /* ECB78 001ECB78 08000626 */  addiu      $6, $16, 0x8
    /* ECB7C 001ECB7C 78B3070C */  jal        func_001ecde0
    /* ECB80 001ECB80 00000000 */   nop
    /* ECB84 001ECB84 1400C213 */  beq        $30, $2, .L001ECBD8
    /* ECB88 001ECB88 00000000 */   nop
    /* ECB8C 001ECB8C 08002426 */  addiu      $4, $17, 0x8
    /* ECB90 001ECB90 08000526 */  addiu      $5, $16, 0x8
    /* ECB94 001ECB94 2D30C002 */  daddu      $6, $22, $0
    /* ECB98 001ECB98 78B3070C */  jal        func_001ecde0
    /* ECB9C 001ECB9C 00000000 */   nop
    /* ECBA0 001ECBA0 2DB04000 */  daddu      $22, $2, $0
    /* ECBA4 001ECBA4 08002426 */  addiu      $4, $17, 0x8
    /* ECBA8 001ECBA8 08000526 */  addiu      $5, $16, 0x8
    /* ECBAC 001ECBAC 2D304002 */  daddu      $6, $18, $0
    /* ECBB0 001ECBB0 78B3070C */  jal        func_001ecde0
    /* ECBB4 001ECBB4 00000000 */   nop
    /* ECBB8 001ECBB8 0400C212 */  beq        $22, $2, .L001ECBCC
    /* ECBBC 001ECBBC 00000000 */   nop
    /* ECBC0 001ECBC0 01000224 */  addiu      $2, $0, 0x1
    /* ECBC4 001ECBC4 05000010 */  b          .L001ECBDC
    /* ECBC8 001ECBC8 00000000 */   nop
  .L001ECBCC:
    /* ECBCC 001ECBCC 2D100000 */  daddu      $2, $0, $0
    /* ECBD0 001ECBD0 02000010 */  b          .L001ECBDC
    /* ECBD4 001ECBD4 00000000 */   nop
  .L001ECBD8:
    /* ECBD8 001ECBD8 2D100000 */  daddu      $2, $0, $0
  .L001ECBDC:
    /* ECBDC 001ECBDC 04004010 */  beqz       $2, .L001ECBF0
    /* ECBE0 001ECBE0 00000000 */   nop
    /* ECBE4 001ECBE4 01001424 */  addiu      $20, $0, 0x1
    /* ECBE8 001ECBE8 05000010 */  b          .L001ECC00
    /* ECBEC 001ECBEC 00000000 */   nop
  .L001ECBF0:
    /* ECBF0 001ECBF0 01007326 */  addiu      $19, $19, 0x1
  .L001ECBF4:
    /* ECBF4 001ECBF4 0400622A */  slti       $2, $19, 0x4
    /* ECBF8 001ECBF8 9AFF4014 */  bnez       $2, .L001ECA64
    /* ECBFC 001ECBFC 00000000 */   nop
  .L001ECC00:
    /* ECC00 001ECC00 61008016 */  bnez       $20, .L001ECD88
    /* ECC04 001ECC04 00000000 */   nop
    /* ECC08 001ECC08 080022C6 */  lwc1       $f2, 0x8($17)
    /* ECC0C 001ECC0C 0800A3C6 */  lwc1       $f3, 0x8($21)
    /* ECC10 001ECC10 34180246 */  c.lt.s     $f3, $f2
    /* ECC14 001ECC14 0E000045 */  bc1f       .L001ECC50
    /* ECC18 001ECC18 00000000 */   nop
    /* ECC1C 001ECC1C 0C0021C6 */  lwc1       $f1, 0xC($17)
    /* ECC20 001ECC20 0C00A0C6 */  lwc1       $f0, 0xC($21)
    /* ECC24 001ECC24 34000146 */  c.lt.s     $f0, $f1
    /* ECC28 001ECC28 09000045 */  bc1f       .L001ECC50
    /* ECC2C 001ECC2C 00000000 */   nop
    /* ECC30 001ECC30 6802A0C6 */  lwc1       $f0, 0x268($21)
    /* ECC34 001ECC34 36000246 */  c.le.s     $f0, $f2
    /* ECC38 001ECC38 05000145 */  bc1t       .L001ECC50
    /* ECC3C 001ECC3C 00000000 */   nop
    /* ECC40 001ECC40 6C02A0C6 */  lwc1       $f0, 0x26C($21)
    /* ECC44 001ECC44 36000146 */  c.le.s     $f0, $f1
    /* ECC48 001ECC48 4F000045 */  bc1f       .L001ECD88
    /* ECC4C 001ECC4C 00000000 */   nop
  .L001ECC50:
    /* ECC50 001ECC50 080002C6 */  lwc1       $f2, 0x8($16)
    /* ECC54 001ECC54 34180246 */  c.lt.s     $f3, $f2
    /* ECC58 001ECC58 0E000045 */  bc1f       .L001ECC94
    /* ECC5C 001ECC5C 00000000 */   nop
    /* ECC60 001ECC60 0C0001C6 */  lwc1       $f1, 0xC($16)
    /* ECC64 001ECC64 0C00A0C6 */  lwc1       $f0, 0xC($21)
    /* ECC68 001ECC68 34000146 */  c.lt.s     $f0, $f1
    /* ECC6C 001ECC6C 09000045 */  bc1f       .L001ECC94
    /* ECC70 001ECC70 00000000 */   nop
    /* ECC74 001ECC74 6802A0C6 */  lwc1       $f0, 0x268($21)
    /* ECC78 001ECC78 36000246 */  c.le.s     $f0, $f2
    /* ECC7C 001ECC7C 05000145 */  bc1t       .L001ECC94
    /* ECC80 001ECC80 00000000 */   nop
    /* ECC84 001ECC84 6C02A0C6 */  lwc1       $f0, 0x26C($21)
    /* ECC88 001ECC88 36000146 */  c.le.s     $f0, $f1
    /* ECC8C 001ECC8C 3E000045 */  bc1f       .L001ECD88
    /* ECC90 001ECC90 00000000 */   nop
  .L001ECC94:
    /* ECC94 001ECC94 2D900000 */  daddu      $18, $0, $0
    /* ECC98 001ECC98 38000010 */  b          .L001ECD7C
    /* ECC9C 001ECC9C 00000000 */   nop
  .L001ECCA0:
    /* ECCA0 001ECCA0 01004226 */  addiu      $2, $18, 0x1
    /* ECCA4 001ECCA4 03004330 */  andi       $3, $2, 0x3
    /* ECCA8 001ECCA8 C0100300 */  sll        $2, $3, 3
    /* ECCAC 001ECCAC 21104300 */  addu       $2, $2, $3
    /* ECCB0 001ECCB0 40100200 */  sll        $2, $2, 1
    /* ECCB4 001ECCB4 21104300 */  addu       $2, $2, $3
    /* ECCB8 001ECCB8 00110200 */  sll        $2, $2, 4
    /* ECCBC 001ECCBC 2110A202 */  addu       $2, $21, $2
    /* ECCC0 001ECCC0 08005324 */  addiu      $19, $2, 0x8
    /* ECCC4 001ECCC4 C0101200 */  sll        $2, $18, 3
    /* ECCC8 001ECCC8 21105200 */  addu       $2, $2, $18
    /* ECCCC 001ECCCC 40100200 */  sll        $2, $2, 1
    /* ECCD0 001ECCD0 21105200 */  addu       $2, $2, $18
    /* ECCD4 001ECCD4 00110200 */  sll        $2, $2, 4
    /* ECCD8 001ECCD8 2110A202 */  addu       $2, $21, $2
    /* ECCDC 001ECCDC 08005624 */  addiu      $22, $2, 0x8
    /* ECCE0 001ECCE0 2D20C002 */  daddu      $4, $22, $0
    /* ECCE4 001ECCE4 2D286002 */  daddu      $5, $19, $0
    /* ECCE8 001ECCE8 08002626 */  addiu      $6, $17, 0x8
    /* ECCEC 001ECCEC 78B3070C */  jal        func_001ecde0
    /* ECCF0 001ECCF0 00000000 */   nop
    /* ECCF4 001ECCF4 2DB84000 */  daddu      $23, $2, $0
    /* ECCF8 001ECCF8 2D20C002 */  daddu      $4, $22, $0
    /* ECCFC 001ECCFC 2D286002 */  daddu      $5, $19, $0
    /* ECD00 001ECD00 08000626 */  addiu      $6, $16, 0x8
    /* ECD04 001ECD04 78B3070C */  jal        func_001ecde0
    /* ECD08 001ECD08 00000000 */   nop
    /* ECD0C 001ECD0C 1400E212 */  beq        $23, $2, .L001ECD60
    /* ECD10 001ECD10 00000000 */   nop
    /* ECD14 001ECD14 08002426 */  addiu      $4, $17, 0x8
    /* ECD18 001ECD18 08000526 */  addiu      $5, $16, 0x8
    /* ECD1C 001ECD1C 2D30C002 */  daddu      $6, $22, $0
    /* ECD20 001ECD20 78B3070C */  jal        func_001ecde0
    /* ECD24 001ECD24 00000000 */   nop
    /* ECD28 001ECD28 2DB04000 */  daddu      $22, $2, $0
    /* ECD2C 001ECD2C 08002426 */  addiu      $4, $17, 0x8
    /* ECD30 001ECD30 08000526 */  addiu      $5, $16, 0x8
    /* ECD34 001ECD34 2D306002 */  daddu      $6, $19, $0
    /* ECD38 001ECD38 78B3070C */  jal        func_001ecde0
    /* ECD3C 001ECD3C 00000000 */   nop
    /* ECD40 001ECD40 0400C212 */  beq        $22, $2, .L001ECD54
    /* ECD44 001ECD44 00000000 */   nop
    /* ECD48 001ECD48 01000224 */  addiu      $2, $0, 0x1
    /* ECD4C 001ECD4C 05000010 */  b          .L001ECD64
    /* ECD50 001ECD50 00000000 */   nop
  .L001ECD54:
    /* ECD54 001ECD54 2D100000 */  daddu      $2, $0, $0
    /* ECD58 001ECD58 02000010 */  b          .L001ECD64
    /* ECD5C 001ECD5C 00000000 */   nop
  .L001ECD60:
    /* ECD60 001ECD60 2D100000 */  daddu      $2, $0, $0
  .L001ECD64:
    /* ECD64 001ECD64 04004010 */  beqz       $2, .L001ECD78
    /* ECD68 001ECD68 00000000 */   nop
    /* ECD6C 001ECD6C 01001424 */  addiu      $20, $0, 0x1
    /* ECD70 001ECD70 05000010 */  b          .L001ECD88
    /* ECD74 001ECD74 00000000 */   nop
  .L001ECD78:
    /* ECD78 001ECD78 01005226 */  addiu      $18, $18, 0x1
  .L001ECD7C:
    /* ECD7C 001ECD7C 0400422A */  slti       $2, $18, 0x4
    /* ECD80 001ECD80 C7FF4014 */  bnez       $2, .L001ECCA0
    /* ECD84 001ECD84 00000000 */   nop
  .L001ECD88:
    /* ECD88 001ECD88 CC04B58E */  lw         $21, 0x4CC($21)
  .L001ECD8C:
    /* ECD8C 001ECD8C 0300A012 */  beqz       $21, .L001ECD9C
    /* ECD90 001ECD90 00000000 */   nop
    /* ECD94 001ECD94 30FF8012 */  beqz       $20, .L001ECA58
    /* ECD98 001ECD98 00000000 */   nop
  .L001ECD9C:
    /* ECD9C 001ECD9C 2D108002 */  daddu      $2, $20, $0
    /* ECDA0 001ECDA0 9000BFDF */  ld         $31, 0x90($29)
    /* ECDA4 001ECDA4 8000BE7B */  lq         $30, 0x80($29)
    /* ECDA8 001ECDA8 7000B77B */  lq         $23, 0x70($29)
    /* ECDAC 001ECDAC 6000B67B */  lq         $22, 0x60($29)
    /* ECDB0 001ECDB0 5000B57B */  lq         $21, 0x50($29)
    /* ECDB4 001ECDB4 4000B47B */  lq         $20, 0x40($29)
    /* ECDB8 001ECDB8 3000B37B */  lq         $19, 0x30($29)
    /* ECDBC 001ECDBC 2000B27B */  lq         $18, 0x20($29)
    /* ECDC0 001ECDC0 1000B17B */  lq         $17, 0x10($29)
    /* ECDC4 001ECDC4 0000B07B */  lq         $16, 0x0($29)
    /* ECDC8 001ECDC8 B000BD27 */  addiu      $29, $29, 0xB0
    /* ECDCC 001ECDCC 0800E003 */  jr         $31
    /* ECDD0 001ECDD0 00000000 */   nop
    /* ECDD4 001ECDD4 00000000 */  nop
    /* ECDD8 001ECDD8 00000000 */  nop
    /* ECDDC 001ECDDC 00000000 */  nop
.size func_001eca10, 0x3d0
