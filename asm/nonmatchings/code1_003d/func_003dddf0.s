.section .text
.set noat
.set noreorder
glabel func_003dddf0
    /* 2DDDF0 003DDDF0 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 2DDDF4 003DDDF4 5000BFFF */  sd         $31, 0x50($29)
    /* 2DDDF8 003DDDF8 4000B47F */  sq         $20, 0x40($29)
    /* 2DDDFC 003DDDFC 3000B37F */  sq         $19, 0x30($29)
    /* 2DDE00 003DDE00 2DA00000 */  daddu      $20, $0, $0
    /* 2DDE04 003DDE04 2000B27F */  sq         $18, 0x20($29)
    /* 2DDE08 003DDE08 2D988000 */  daddu      $19, $4, $0
    /* 2DDE0C 003DDE0C 1000B17F */  sq         $17, 0x10($29)
    /* 2DDE10 003DDE10 2D90A000 */  daddu      $18, $5, $0
    /* 2DDE14 003DDE14 0000B07F */  sq         $16, 0x0($29)
    /* 2DDE18 003DDE18 2D204002 */  daddu      $4, $18, $0
    /* 2DDE1C 003DDE1C 3CAB8527 */  addiu      $5, $28, -0x54C4
    /* 2DDE20 003DDE20 2D880000 */  daddu      $17, $0, $0
    /* 2DDE24 003DDE24 040C110C */  jal        func_00443010
    /* 2DDE28 003DDE28 2D800000 */   daddu     $16, $0, $0
    /* 2DDE2C 003DDE2C 02004010 */  beqz       $2, .L003DDE38
    /* 2DDE30 003DDE30 00000000 */   nop
    /* 2DDE34 003DDE34 01001124 */  addiu      $17, $0, 0x1
  .L003DDE38:
    /* 2DDE38 003DDE38 2D204002 */  daddu      $4, $18, $0
    /* 2DDE3C 003DDE3C 040C110C */  jal        func_00443010
    /* 2DDE40 003DDE40 40AB8527 */   addiu     $5, $28, -0x54C0
    /* 2DDE44 003DDE44 02004010 */  beqz       $2, .L003DDE50
    /* 2DDE48 003DDE48 00000000 */   nop
    /* 2DDE4C 003DDE4C 01001024 */  addiu      $16, $0, 0x1
  .L003DDE50:
    /* 2DDE50 003DDE50 2D204002 */  daddu      $4, $18, $0
    /* 2DDE54 003DDE54 040C110C */  jal        func_00443010
    /* 2DDE58 003DDE58 44AB8527 */   addiu     $5, $28, -0x54BC
    /* 2DDE5C 003DDE5C 05004010 */  beqz       $2, .L003DDE74
    /* 2DDE60 003DDE60 00000000 */   nop
    /* 2DDE64 003DDE64 03002012 */  beqz       $17, .L003DDE74
    /* 2DDE68 003DDE68 01009436 */   ori       $20, $20, 0x1
    /* 2DDE6C 003DDE6C 02008236 */  ori        $2, $20, 0x2
    /* 2DDE70 003DDE70 08005434 */  ori        $20, $2, 0x8
  .L003DDE74:
    /* 2DDE74 003DDE74 2D204002 */  daddu      $4, $18, $0
    /* 2DDE78 003DDE78 040C110C */  jal        func_00443010
    /* 2DDE7C 003DDE7C 48AB8527 */   addiu     $5, $28, -0x54B8
    /* 2DDE80 003DDE80 05004010 */  beqz       $2, .L003DDE98
    /* 2DDE84 003DDE84 00000000 */   nop
    /* 2DDE88 003DDE88 02008236 */  ori        $2, $20, 0x2
    /* 2DDE8C 003DDE8C 02002012 */  beqz       $17, .L003DDE98
    /* 2DDE90 003DDE90 04005434 */   ori       $20, $2, 0x4
    /* 2DDE94 003DDE94 01009436 */  ori        $20, $20, 0x1
  .L003DDE98:
    /* 2DDE98 003DDE98 2D204002 */  daddu      $4, $18, $0
    /* 2DDE9C 003DDE9C 040C110C */  jal        func_00443010
    /* 2DDEA0 003DDEA0 4CAB8527 */   addiu     $5, $28, -0x54B4
    /* 2DDEA4 003DDEA4 08004010 */  beqz       $2, .L003DDEC8
    /* 2DDEA8 003DDEA8 00000000 */   nop
    /* 2DDEAC 003DDEAC 02008236 */  ori        $2, $20, 0x2
    /* 2DDEB0 003DDEB0 02002012 */  beqz       $17, .L003DDEBC
    /* 2DDEB4 003DDEB4 08005434 */   ori       $20, $2, 0x8
    /* 2DDEB8 003DDEB8 01009436 */  ori        $20, $20, 0x1
  .L003DDEBC:
    /* 2DDEBC 003DDEBC 02000012 */  beqz       $16, .L003DDEC8
    /* 2DDEC0 003DDEC0 00000000 */   nop
    /* 2DDEC4 003DDEC4 04009436 */  ori        $20, $20, 0x4
  .L003DDEC8:
    /* 2DDEC8 003DDEC8 28770F0C */  jal        func_003ddca0
    /* 2DDECC 003DDECC 2D206002 */   daddu     $4, $19, $0
    /* 2DDED0 003DDED0 09004010 */  beqz       $2, .L003DDEF8
    /* 2DDED4 003DDED4 00000000 */   nop
    /* 2DDED8 003DDED8 2D286002 */  daddu      $5, $19, $0
    /* 2DDEDC 003DDEDC 2D308002 */  daddu      $6, $20, $0
    /* 2DDEE0 003DDEE0 2D204000 */  daddu      $4, $2, $0
    /* 2DDEE4 003DDEE4 2D380000 */  daddu      $7, $0, $0
    /* 2DDEE8 003DDEE8 94760F0C */  jal        func_003dda50
    /* 2DDEEC 003DDEEC 2D400000 */   daddu     $8, $0, $0
    /* 2DDEF0 003DDEF0 03000010 */  b          .L003DDF00
    /* 2DDEF4 003DDEF4 5000BFDF */   ld        $31, 0x50($29)
  .L003DDEF8:
    /* 2DDEF8 003DDEF8 2D100000 */  daddu      $2, $0, $0
    /* 2DDEFC 003DDEFC 5000BFDF */  ld         $31, 0x50($29)
  .L003DDF00:
    /* 2DDF00 003DDF00 4000B47B */  lq         $20, 0x40($29)
    /* 2DDF04 003DDF04 3000B37B */  lq         $19, 0x30($29)
    /* 2DDF08 003DDF08 2000B27B */  lq         $18, 0x20($29)
    /* 2DDF0C 003DDF0C 1000B17B */  lq         $17, 0x10($29)
    /* 2DDF10 003DDF10 0000B07B */  lq         $16, 0x0($29)
    /* 2DDF14 003DDF14 0800E003 */  jr         $31
    /* 2DDF18 003DDF18 6000BD27 */   addiu     $29, $29, 0x60
    /* 2DDF1C 003DDF1C 00000000 */  nop
.size func_003dddf0, 0x130
