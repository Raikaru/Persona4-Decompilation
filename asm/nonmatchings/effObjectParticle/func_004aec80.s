.section .text
.set noat
.set noreorder
glabel func_004aec80
    /* 3AEC80 004AEC80 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 3AEC84 004AEC84 5000BFFF */  sd         $31, 0x50($29)
    /* 3AEC88 004AEC88 4000B47F */  sq         $20, 0x40($29)
    /* 3AEC8C 004AEC8C 3000B37F */  sq         $19, 0x30($29)
    /* 3AEC90 004AEC90 2000B27F */  sq         $18, 0x20($29)
    /* 3AEC94 004AEC94 1000B17F */  sq         $17, 0x10($29)
    /* 3AEC98 004AEC98 0000B07F */  sq         $16, 0x0($29)
    /* 3AEC9C 004AEC9C 2D988000 */  daddu      $19, $4, $0
    /* 3AECA0 004AECA0 5800848C */  lw         $4, 0x58($4)
    /* 3AECA4 004AECA4 444B120C */  jal        func_00492d10
    /* 3AECA8 004AECA8 00000000 */   nop
    /* 3AECAC 004AECAC 5800648E */  lw         $4, 0x58($19)
    /* 3AECB0 004AECB0 0800908C */  lw         $16, 0x8($4)
    /* 3AECB4 004AECB4 23000012 */  beqz       $16, .L004AED44
    /* 3AECB8 004AECB8 00000000 */   nop
    /* 3AECBC 004AECBC 1000838C */  lw         $3, 0x10($4)
    /* 3AECC0 004AECC0 20006010 */  beqz       $3, .L004AED44
    /* 3AECC4 004AECC4 00000000 */   nop
    /* 3AECC8 004AECC8 1800928C */  lw         $18, 0x18($4)
    /* 3AECCC 004AECCC 5C00718E */  lw         $17, 0x5C($19)
    /* 3AECD0 004AECD0 0C006496 */  lhu        $4, 0xC($19)
    /* 3AECD4 004AECD4 03000324 */  addiu      $3, $0, 0x3
    /* 3AECD8 004AECD8 03008310 */  beq        $4, $3, .L004AECE8
    /* 3AECDC 004AECDC 00000000 */   nop
    /* 3AECE0 004AECE0 13000010 */  b          .L004AED30
    /* 3AECE4 004AECE4 00000000 */   nop
  .L004AECE8:
    /* 3AECE8 004AECE8 2DA00000 */  daddu      $20, $0, $0
    /* 3AECEC 004AECEC 0B000010 */  b          .L004AED1C
    /* 3AECF0 004AECF0 00000000 */   nop
  .L004AECF4:
    /* 3AECF4 004AECF4 1000438E */  lw         $3, 0x10($18)
    /* 3AECF8 004AECF8 05006014 */  bnez       $3, .L004AED10
    /* 3AECFC 004AECFC 00000000 */   nop
    /* 3AED00 004AED00 2D206002 */  daddu      $4, $19, $0
    /* 3AED04 004AED04 2D282002 */  daddu      $5, $17, $0
    /* 3AED08 004AED08 28B8120C */  jal        func_004ae0a0
    /* 3AED0C 004AED0C 00000000 */   nop
  .L004AED10:
    /* 3AED10 004AED10 01009426 */  addiu      $20, $20, 0x1
    /* 3AED14 004AED14 20005226 */  addiu      $18, $18, 0x20
    /* 3AED18 004AED18 18003126 */  addiu      $17, $17, 0x18
  .L004AED1C:
    /* 3AED1C 004AED1C 2A189002 */  slt        $3, $20, $16
    /* 3AED20 004AED20 F4FF6014 */  bnez       $3, .L004AECF4
    /* 3AED24 004AED24 00000000 */   nop
    /* 3AED28 004AED28 06000010 */  b          .L004AED44
    /* 3AED2C 004AED2C 00000000 */   nop
  .L004AED30:
    /* 3AED30 004AED30 7100043C */  lui        $4, %hi(D_00714520)
    /* 3AED34 004AED34 20458424 */  addiu      $4, $4, %lo(D_00714520)
    /* 3AED38 004AED38 13020524 */  addiu      $5, $0, 0x213
    /* 3AED3C 004AED3C CCB5110C */  jal        func_0046d730
    /* 3AED40 004AED40 00000000 */   nop
  .L004AED44:
    /* 3AED44 004AED44 5000BFDF */  ld         $31, 0x50($29)
    /* 3AED48 004AED48 4000B47B */  lq         $20, 0x40($29)
    /* 3AED4C 004AED4C 3000B37B */  lq         $19, 0x30($29)
    /* 3AED50 004AED50 2000B27B */  lq         $18, 0x20($29)
    /* 3AED54 004AED54 1000B17B */  lq         $17, 0x10($29)
    /* 3AED58 004AED58 0000B07B */  lq         $16, 0x0($29)
    /* 3AED5C 004AED5C 6000BD27 */  addiu      $29, $29, 0x60
    /* 3AED60 004AED60 0800E003 */  jr         $31
    /* 3AED64 004AED64 00000000 */   nop
    /* 3AED68 004AED68 00000000 */  nop
    /* 3AED6C 004AED6C 00000000 */  nop
.size func_004aec80, 0xf0
