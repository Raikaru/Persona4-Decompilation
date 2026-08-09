.section .text
.set noat
.set noreorder
glabel func_002bbe90
    /* 1BBE90 002BBE90 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 1BBE94 002BBE94 1000BFFF */  sd         $31, 0x10($29)
    /* 1BBE98 002BBE98 0000B07F */  sq         $16, 0x0($29)
    /* 1BBE9C 002BBE9C 3C1E0400 */  dsll32     $3, $4, 24
    /* 1BBEA0 002BBEA0 3F1E0300 */  dsra32     $3, $3, 24
    /* 1BBEA4 002BBEA4 80200300 */  sll        $4, $3, 2
    /* 1BBEA8 002BBEA8 8800033C */  lui        $3, %hi(D_00882F40)
    /* 1BBEAC 002BBEAC 402F6324 */  addiu      $3, $3, %lo(D_00882F40)
    /* 1BBEB0 002BBEB0 21806400 */  addu       $16, $3, $4
    /* 1BBEB4 002BBEB4 0000038E */  lw         $3, 0x0($16)
    /* 1BBEB8 002BBEB8 24006010 */  beqz       $3, .L002BBF4C
    /* 1BBEBC 002BBEBC 00000000 */   nop
    /* 1BBEC0 002BBEC0 1600A010 */  beqz       $5, .L002BBF1C
    /* 1BBEC4 002BBEC4 00000000 */   nop
    /* 1BBEC8 002BBEC8 0000648C */  lw         $4, 0x0($3)
    /* 1BBECC 002BBECC 8000053C */  lui        $5, (0x800000 >> 16)
    /* 1BBED0 002BBED0 78E0090C */  jal        func_002781e0
    /* 1BBED4 002BBED4 00000000 */   nop
    /* 1BBED8 002BBED8 0000028E */  lw         $2, 0x0($16)
    /* 1BBEDC 002BBEDC 0000448C */  lw         $4, 0x0($2)
    /* 1BBEE0 002BBEE0 1000053C */  lui        $5, (0x100000 >> 16)
    /* 1BBEE4 002BBEE4 78E0090C */  jal        func_002781e0
    /* 1BBEE8 002BBEE8 00000000 */   nop
    /* 1BBEEC 002BBEEC 0000028E */  lw         $2, 0x0($16)
    /* 1BBEF0 002BBEF0 050040A0 */  sb         $0, 0x5($2)
    /* 1BBEF4 002BBEF4 0000028E */  lw         $2, 0x0($16)
    /* 1BBEF8 002BBEF8 0000448C */  lw         $4, 0x0($2)
    /* 1BBEFC 002BBEFC 01000524 */  addiu      $5, $0, 0x1
    /* 1BBF00 002BBF00 9CDB090C */  jal        func_00276e70
    /* 1BBF04 002BBF04 00000000 */   nop
    /* 1BBF08 002BBF08 01000424 */  addiu      $4, $0, 0x1
    /* 1BBF0C 002BBF0C 0000038E */  lw         $3, 0x0($16)
    /* 1BBF10 002BBF10 040064A0 */  sb         $4, 0x4($3)
    /* 1BBF14 002BBF14 0D000010 */  b          .L002BBF4C
    /* 1BBF18 002BBF18 00000000 */   nop
  .L002BBF1C:
    /* 1BBF1C 002BBF1C 0000648C */  lw         $4, 0x0($3)
    /* 1BBF20 002BBF20 8000053C */  lui        $5, (0x800000 >> 16)
    /* 1BBF24 002BBF24 5CE0090C */  jal        func_00278170
    /* 1BBF28 002BBF28 00000000 */   nop
    /* 1BBF2C 002BBF2C 0000028E */  lw         $2, 0x0($16)
    /* 1BBF30 002BBF30 0000448C */  lw         $4, 0x0($2)
    /* 1BBF34 002BBF34 1000053C */  lui        $5, (0x100000 >> 16)
    /* 1BBF38 002BBF38 5CE0090C */  jal        func_00278170
    /* 1BBF3C 002BBF3C 00000000 */   nop
    /* 1BBF40 002BBF40 01000424 */  addiu      $4, $0, 0x1
    /* 1BBF44 002BBF44 0000038E */  lw         $3, 0x0($16)
    /* 1BBF48 002BBF48 050064A0 */  sb         $4, 0x5($3)
  .L002BBF4C:
    /* 1BBF4C 002BBF4C 1000BFDF */  ld         $31, 0x10($29)
    /* 1BBF50 002BBF50 0000B07B */  lq         $16, 0x0($29)
    /* 1BBF54 002BBF54 2000BD27 */  addiu      $29, $29, 0x20
    /* 1BBF58 002BBF58 0800E003 */  jr         $31
    /* 1BBF5C 002BBF5C 00000000 */   nop
.size func_002bbe90, 0xd0
