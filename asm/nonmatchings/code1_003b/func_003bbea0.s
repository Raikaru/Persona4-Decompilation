.section .text
.set noat
.set noreorder
glabel func_003bbea0
    /* 2BBEA0 003BBEA0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 2BBEA4 003BBEA4 4000BFFF */  sd         $31, 0x40($29)
    /* 2BBEA8 003BBEA8 3000B37F */  sq         $19, 0x30($29)
    /* 2BBEAC 003BBEAC 2000B27F */  sq         $18, 0x20($29)
    /* 2BBEB0 003BBEB0 2D988000 */  daddu      $19, $4, $0
    /* 2BBEB4 003BBEB4 1000B17F */  sq         $17, 0x10($29)
    /* 2BBEB8 003BBEB8 0000B07F */  sq         $16, 0x0($29)
    /* 2BBEBC 003BBEBC 0000848C */  lw         $4, 0x0($4)
    /* 2BBEC0 003BBEC0 06008010 */  beqz       $4, .L003BBEDC
    /* 2BBEC4 003BBEC4 00000000 */   nop
    /* 2BBEC8 003BBEC8 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2BBECC 003BBECC EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2BBED0 003BBED0 09F84000 */  jalr       $2
    /* 2BBED4 003BBED4 00000000 */   nop
    /* 2BBED8 003BBED8 000060AE */  sw         $0, 0x0($19)
  .L003BBEDC:
    /* 2BBEDC 003BBEDC 0400648E */  lw         $4, 0x4($19)
    /* 2BBEE0 003BBEE0 03000324 */  addiu      $3, $0, 0x3
    /* 2BBEE4 003BBEE4 14008314 */  bne        $4, $3, .L003BBF38
    /* 2BBEE8 003BBEE8 00000000 */   nop
    /* 2BBEEC 003BBEEC 0800638E */  lw         $3, 0x8($19)
    /* 2BBEF0 003BBEF0 0C00718E */  lw         $17, 0xC($19)
    /* 2BBEF4 003BBEF4 2A080300 */  slt        $1, $0, $3
    /* 2BBEF8 003BBEF8 0F002010 */  beqz       $1, .L003BBF38
    /* 2BBEFC 003BBEFC 2D900000 */   daddu     $18, $0, $0
    /* 2BBF00 003BBF00 8800103C */  lui        $16, %hi(jtbl_008873EC)
    /* 2BBF04 003BBF04 EC731026 */  addiu      $16, $16, %lo(jtbl_008873EC)
  .L003BBF08:
    /* 2BBF08 003BBF08 0000248E */  lw         $4, 0x0($17)
    /* 2BBF0C 003BBF0C 04008010 */  beqz       $4, .L003BBF20
    /* 2BBF10 003BBF10 00000000 */   nop
    /* 2BBF14 003BBF14 0000028E */  lw         $2, 0x0($16)
    /* 2BBF18 003BBF18 09F84000 */  jalr       $2
    /* 2BBF1C 003BBF1C 00000000 */   nop
  .L003BBF20:
    /* 2BBF20 003BBF20 0800638E */  lw         $3, 0x8($19)
    /* 2BBF24 003BBF24 01005226 */  addiu      $18, $18, 0x1
    /* 2BBF28 003BBF28 2A184302 */  slt        $3, $18, $3
    /* 2BBF2C 003BBF2C F6FF6014 */  bnez       $3, .L003BBF08
    /* 2BBF30 003BBF30 04003126 */   addiu     $17, $17, 0x4
    /* 2BBF34 003BBF34 00000000 */  nop
  .L003BBF38:
    /* 2BBF38 003BBF38 0C00648E */  lw         $4, 0xC($19)
    /* 2BBF3C 003BBF3C 06008010 */  beqz       $4, .L003BBF58
    /* 2BBF40 003BBF40 00000000 */   nop
    /* 2BBF44 003BBF44 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2BBF48 003BBF48 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2BBF4C 003BBF4C 09F84000 */  jalr       $2
    /* 2BBF50 003BBF50 00000000 */   nop
    /* 2BBF54 003BBF54 0C0060AE */  sw         $0, 0xC($19)
  .L003BBF58:
    /* 2BBF58 003BBF58 4000BFDF */  ld         $31, 0x40($29)
    /* 2BBF5C 003BBF5C 3000B37B */  lq         $19, 0x30($29)
    /* 2BBF60 003BBF60 2000B27B */  lq         $18, 0x20($29)
    /* 2BBF64 003BBF64 1000B17B */  lq         $17, 0x10($29)
    /* 2BBF68 003BBF68 0000B07B */  lq         $16, 0x0($29)
    /* 2BBF6C 003BBF6C 0800E003 */  jr         $31
    /* 2BBF70 003BBF70 5000BD27 */   addiu     $29, $29, 0x50
    /* 2BBF74 003BBF74 00000000 */  nop
    /* 2BBF78 003BBF78 00000000 */  nop
    /* 2BBF7C 003BBF7C 00000000 */  nop
.size func_003bbea0, 0xe0
