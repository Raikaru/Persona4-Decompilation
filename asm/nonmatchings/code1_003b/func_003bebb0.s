.section .text
.set noat
.set noreorder
glabel func_003bebb0
    /* 2BEBB0 003BEBB0 80FFBD27 */  addiu      $29, $29, -0x80
    /* 2BEBB4 003BEBB4 6000BFFF */  sd         $31, 0x60($29)
    /* 2BEBB8 003BEBB8 5000B57F */  sq         $21, 0x50($29)
    /* 2BEBBC 003BEBBC 4000B47F */  sq         $20, 0x40($29)
    /* 2BEBC0 003BEBC0 3000B37F */  sq         $19, 0x30($29)
    /* 2BEBC4 003BEBC4 2000B27F */  sq         $18, 0x20($29)
    /* 2BEBC8 003BEBC8 2D98A000 */  daddu      $19, $5, $0
    /* 2BEBCC 003BEBCC 1000B17F */  sq         $17, 0x10($29)
    /* 2BEBD0 003BEBD0 0000B07F */  sq         $16, 0x0($29)
    /* 2BEBD4 003BEBD4 2D808000 */  daddu      $16, $4, $0
    /* 2BEBD8 003BEBD8 98FF0E0C */  jal        func_003bfe60
    /* 2BEBDC 003BEBDC 2D206002 */   daddu     $4, $19, $0
    /* 2BEBE0 003BEBE0 2300401C */  bgtz       $2, .L003BEC70
    /* 2BEBE4 003BEBE4 00000000 */   nop
    /* 2BEBE8 003BEBE8 000000AE */  sw         $0, 0x0($16)
  .L003BEBEC:
    /* 2BEBEC 003BEBEC 040000AE */  sw         $0, 0x4($16)
    /* 2BEBF0 003BEBF0 08007226 */  addiu      $18, $19, 0x8
    /* 2BEBF4 003BEBF4 0800748E */  lw         $20, 0x8($19)
    /* 2BEBF8 003BEBF8 1B009212 */  beq        $20, $18, .L003BEC68
    /* 2BEBFC 003BEBFC 0000158E */   lw        $21, 0x0($16)
    /* 2BEC00 003BEC00 04001126 */  addiu      $17, $16, 0x4
  .L003BEC04:
    /* 2BEC04 003BEC04 0000238E */  lw         $3, 0x0($17)
    /* 2BEC08 003BEC08 D8FF938E */  lw         $19, -0x28($20)
    /* 2BEC0C 003BEC0C 2A080300 */  slt        $1, $0, $3
    /* 2BEC10 003BEC10 0D002010 */  beqz       $1, .L003BEC48
    /* 2BEC14 003BEC14 2D280000 */   daddu     $5, $0, $0
    /* 2BEC18 003BEC18 0000048E */  lw         $4, 0x0($16)
    /* 2BEC1C 003BEC1C 00000000 */  nop
  .L003BEC20:
    /* 2BEC20 003BEC20 0000828C */  lw         $2, 0x0($4)
    /* 2BEC24 003BEC24 04005314 */  bne        $2, $19, .L003BEC38
    /* 2BEC28 003BEC28 00000000 */   nop
    /* 2BEC2C 003BEC2C 08000010 */  b          .L003BEC50
    /* 2BEC30 003BEC30 01000224 */   addiu     $2, $0, 0x1
    /* 2BEC34 003BEC34 00000000 */  nop
  .L003BEC38:
    /* 2BEC38 003BEC38 0100A524 */  addiu      $5, $5, 0x1
    /* 2BEC3C 003BEC3C 2A10A300 */  slt        $2, $5, $3
    /* 2BEC40 003BEC40 F7FF4014 */  bnez       $2, .L003BEC20
    /* 2BEC44 003BEC44 04008424 */   addiu     $4, $4, 0x4
  .L003BEC48:
    /* 2BEC48 003BEC48 2D100000 */  daddu      $2, $0, $0
    /* 2BEC4C 003BEC4C 00000000 */  nop
  .L003BEC50:
    /* 2BEC50 003BEC50 1D004010 */  beqz       $2, .L003BECC8
    /* 2BEC54 003BEC54 00000000 */   nop
  .L003BEC58:
    /* 2BEC58 003BEC58 0000948E */  lw         $20, 0x0($20)
    /* 2BEC5C 003BEC5C E9FF9216 */  bne        $20, $18, .L003BEC04
    /* 2BEC60 003BEC60 00000000 */   nop
    /* 2BEC64 003BEC64 00000000 */  nop
  .L003BEC68:
    /* 2BEC68 003BEC68 1F000010 */  b          .L003BECE8
    /* 2BEC6C 003BEC6C 2D100002 */   daddu     $2, $16, $0
  .L003BEC70:
    /* 2BEC70 003BEC70 80880200 */  sll        $17, $2, 2
    /* 2BEC74 003BEC74 0300023C */  lui        $2, (0x3000F >> 16)
    /* 2BEC78 003BEC78 0F004534 */  ori        $5, $2, (0x3000F & 0xFFFF)
    /* 2BEC7C 003BEC7C 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 2BEC80 003BEC80 E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 2BEC84 003BEC84 09F84000 */  jalr       $2
    /* 2BEC88 003BEC88 2D202002 */   daddu     $4, $17, $0
    /* 2BEC8C 003BEC8C 000002AE */  sw         $2, 0x0($16)
    /* 2BEC90 003BEC90 0000028E */  lw         $2, 0x0($16)
    /* 2BEC94 003BEC94 D5FF4014 */  bnez       $2, .L003BEBEC
    /* 2BEC98 003BEC98 00000000 */   nop
    /* 2BEC9C 003BEC9C 02000224 */  addiu      $2, $0, 0x2
    /* 2BECA0 003BECA0 2D282002 */  daddu      $5, $17, $0
    /* 2BECA4 003BECA4 7800A2AF */  sw         $2, 0x78($29)
    /* 2BECA8 003BECA8 0080023C */  lui        $2, (0x80000013 >> 16)
    /* 2BECAC 003BECAC 647D0F0C */  jal        func_003df590
    /* 2BECB0 003BECB0 13004434 */   ori       $4, $2, (0x80000013 & 0xFFFF)
    /* 2BECB4 003BECB4 7C00A2AF */  sw         $2, 0x7C($29)
    /* 2BECB8 003BECB8 347D0F0C */  jal        func_003df4d0
    /* 2BECBC 003BECBC 7800A427 */   addiu     $4, $29, 0x78
    /* 2BECC0 003BECC0 09000010 */  b          .L003BECE8
    /* 2BECC4 003BECC4 2D100000 */   daddu     $2, $0, $0
  .L003BECC8:
    /* 2BECC8 003BECC8 980A0F0C */  jal        func_003c2a60
    /* 2BECCC 003BECCC 2D206002 */   daddu     $4, $19, $0
    /* 2BECD0 003BECD0 0000B3AE */  sw         $19, 0x0($21)
    /* 2BECD4 003BECD4 0400028E */  lw         $2, 0x4($16)
    /* 2BECD8 003BECD8 0400B526 */  addiu      $21, $21, 0x4
    /* 2BECDC 003BECDC 01004224 */  addiu      $2, $2, 0x1
    /* 2BECE0 003BECE0 DDFF0010 */  b          .L003BEC58
    /* 2BECE4 003BECE4 040002AE */   sw        $2, 0x4($16)
  .L003BECE8:
    /* 2BECE8 003BECE8 6000BFDF */  ld         $31, 0x60($29)
    /* 2BECEC 003BECEC 5000B57B */  lq         $21, 0x50($29)
    /* 2BECF0 003BECF0 4000B47B */  lq         $20, 0x40($29)
    /* 2BECF4 003BECF4 3000B37B */  lq         $19, 0x30($29)
    /* 2BECF8 003BECF8 2000B27B */  lq         $18, 0x20($29)
    /* 2BECFC 003BECFC 1000B17B */  lq         $17, 0x10($29)
    /* 2BED00 003BED00 0000B07B */  lq         $16, 0x0($29)
    /* 2BED04 003BED04 0800E003 */  jr         $31
    /* 2BED08 003BED08 8000BD27 */   addiu     $29, $29, 0x80
    /* 2BED0C 003BED0C 00000000 */  nop
.size func_003bebb0, 0x160
