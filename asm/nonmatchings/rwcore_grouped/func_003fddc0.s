.section .text
.set noat
.set noreorder
glabel func_003fddc0
    /* 2FDDC0 003FDDC0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 2FDDC4 003FDDC4 0300023C */  lui        $2, (0x37002 >> 16)
    /* 2FDDC8 003FDDC8 3000BFFF */  sd         $31, 0x30($29)
    /* 2FDDCC 003FDDCC 08000624 */  addiu      $6, $0, 0x8
    /* 2FDDD0 003FDDD0 2000B27F */  sq         $18, 0x20($29)
    /* 2FDDD4 003FDDD4 02704734 */  ori        $7, $2, (0x37002 & 0xFFFF)
    /* 2FDDD8 003FDDD8 1000B17F */  sq         $17, 0x10($29)
    /* 2FDDDC 003FDDDC 2D908000 */  daddu      $18, $4, $0
    /* 2FDDE0 003FDDE0 0000B07F */  sq         $16, 0x0($29)
    /* 2FDDE4 003FDDE4 2D88A000 */  daddu      $17, $5, $0
    /* 2FDDE8 003FDDE8 0000B08C */  lw         $16, 0x0($5)
    /* 2FDDEC 003FDDEC 37000824 */  addiu      $8, $0, 0x37
    /* 2FDDF0 003FDDF0 FC7B0F0C */  jal        func_003deff0
    /* 2FDDF4 003FDDF4 01000524 */   addiu     $5, $0, 0x1
    /* 2FDDF8 003FDDF8 03004014 */  bnez       $2, .L003FDE08
    /* 2FDDFC 003FDDFC 00000000 */   nop
    /* 2FDE00 003FDE00 40000010 */  b          .L003FDF04
    /* 2FDE04 003FDE04 2D100000 */   daddu     $2, $0, $0
  .L003FDE08:
    /* 2FDE08 003FDE08 4800A427 */  addiu      $4, $29, 0x48
    /* 2FDE0C 003FDE0C 08AC8527 */  addiu      $5, $28, -0x53F8
    /* 2FDE10 003FDE10 04FE100C */  jal        func_0043f810
    /* 2FDE14 003FDE14 04000624 */   addiu     $6, $0, 0x4
    /* 2FDE18 003FDE18 5000278E */  lw         $7, 0x50($17)
    /* 2FDE1C 003FDE1C 2D204002 */  daddu      $4, $18, $0
    /* 2FDE20 003FDE20 4800A527 */  addiu      $5, $29, 0x48
    /* 2FDE24 003FDE24 08000624 */  addiu      $6, $0, 0x8
    /* 2FDE28 003FDE28 000FE230 */  andi       $2, $7, 0xF00
    /* 2FDE2C 003FDE2C FF00E830 */  andi       $8, $7, 0xFF
    /* 2FDE30 003FDE30 021A0200 */  srl        $3, $2, 8
    /* 2FDE34 003FDE34 00F0E230 */  andi       $2, $7, 0xF000
    /* 2FDE38 003FDE38 023B0200 */  srl        $7, $2, 12
    /* 2FDE3C 003FDE3C 0F006230 */  andi       $2, $3, 0xF
    /* 2FDE40 003FDE40 001A0200 */  sll        $3, $2, 8
    /* 2FDE44 003FDE44 0F00E230 */  andi       $2, $7, 0xF
    /* 2FDE48 003FDE48 25180301 */  or         $3, $8, $3
    /* 2FDE4C 003FDE4C 00130200 */  sll        $2, $2, 12
    /* 2FDE50 003FDE50 25104300 */  or         $2, $2, $3
    /* 2FDE54 003FDE54 AC8A0F0C */  jal        func_003e2ab0
    /* 2FDE58 003FDE58 4C00A2AF */   sw        $2, 0x4C($29)
    /* 2FDE5C 003FDE5C 03004014 */  bnez       $2, .L003FDE6C
    /* 2FDE60 003FDE60 00000000 */   nop
    /* 2FDE64 003FDE64 27000010 */  b          .L003FDF04
    /* 2FDE68 003FDE68 2D100000 */   daddu     $2, $0, $0
  .L003FDE6C:
    /* 2FDE6C 003FDE6C 10002426 */  addiu      $4, $17, 0x10
    /* 2FDE70 003FDE70 C8920F0C */  jal        func_003e4b20
    /* 2FDE74 003FDE74 2D284002 */   daddu     $5, $18, $0
    /* 2FDE78 003FDE78 03004014 */  bnez       $2, .L003FDE88
    /* 2FDE7C 003FDE7C 00000000 */   nop
    /* 2FDE80 003FDE80 20000010 */  b          .L003FDF04
    /* 2FDE84 003FDE84 2D100000 */   daddu     $2, $0, $0
  .L003FDE88:
    /* 2FDE88 003FDE88 30002426 */  addiu      $4, $17, 0x30
    /* 2FDE8C 003FDE8C C8920F0C */  jal        func_003e4b20
    /* 2FDE90 003FDE90 2D284002 */   daddu     $5, $18, $0
    /* 2FDE94 003FDE94 03004014 */  bnez       $2, .L003FDEA4
    /* 2FDE98 003FDE98 00000000 */   nop
    /* 2FDE9C 003FDE9C 19000010 */  b          .L003FDF04
    /* 2FDEA0 003FDEA0 2D100000 */   daddu     $2, $0, $0
  .L003FDEA4:
    /* 2FDEA4 003FDEA4 38B9838F */  lw         $3, -0x46C8($28)
    /* 2FDEA8 003FDEA8 0300023C */  lui        $2, (0x37002 >> 16)
    /* 2FDEAC 003FDEAC 02704734 */  ori        $7, $2, (0x37002 & 0xFFFF)
    /* 2FDEB0 003FDEB0 4C000624 */  addiu      $6, $0, 0x4C
    /* 2FDEB4 003FDEB4 2D204002 */  daddu      $4, $18, $0
    /* 2FDEB8 003FDEB8 01000524 */  addiu      $5, $0, 0x1
    /* 2FDEBC 003FDEBC 37000824 */  addiu      $8, $0, 0x37
    /* 2FDEC0 003FDEC0 21100302 */  addu       $2, $16, $3
    /* 2FDEC4 003FDEC4 2800438C */  lw         $3, 0x28($2)
    /* 2FDEC8 003FDEC8 2C00428C */  lw         $2, 0x2C($2)
    /* 2FDECC 003FDECC 21106200 */  addu       $2, $3, $2
    /* 2FDED0 003FDED0 0C004224 */  addiu      $2, $2, 0xC
    /* 2FDED4 003FDED4 2188C200 */  addu       $17, $6, $2
    /* 2FDED8 003FDED8 FC7B0F0C */  jal        func_003deff0
    /* 2FDEDC 003FDEDC 2D302002 */   daddu     $6, $17, $0
    /* 2FDEE0 003FDEE0 03004014 */  bnez       $2, .L003FDEF0
    /* 2FDEE4 003FDEE4 00000000 */   nop
    /* 2FDEE8 003FDEE8 06000010 */  b          .L003FDF04
    /* 2FDEEC 003FDEEC 2D100000 */   daddu     $2, $0, $0
  .L003FDEF0:
    /* 2FDEF0 003FDEF0 2D204002 */  daddu      $4, $18, $0
    /* 2FDEF4 003FDEF4 2D280002 */  daddu      $5, $16, $0
    /* 2FDEF8 003FDEF8 A4F50F0C */  jal        func_003fd690
    /* 2FDEFC 003FDEFC 2D302002 */   daddu     $6, $17, $0
    /* 2FDF00 003FDF00 2B100200 */  sltu       $2, $0, $2
  .L003FDF04:
    /* 2FDF04 003FDF04 3000BFDF */  ld         $31, 0x30($29)
    /* 2FDF08 003FDF08 2000B27B */  lq         $18, 0x20($29)
    /* 2FDF0C 003FDF0C 1000B17B */  lq         $17, 0x10($29)
    /* 2FDF10 003FDF10 0000B07B */  lq         $16, 0x0($29)
    /* 2FDF14 003FDF14 0800E003 */  jr         $31
    /* 2FDF18 003FDF18 5000BD27 */   addiu     $29, $29, 0x50
    /* 2FDF1C 003FDF1C 00000000 */  nop
.size func_003fddc0, 0x160
