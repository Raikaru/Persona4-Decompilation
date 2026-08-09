.section .text
.set noat
.set noreorder
glabel func_003cbf30
    /* 2CBF30 003CBF30 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 2CBF34 003CBF34 5000BFFF */  sd         $31, 0x50($29)
    /* 2CBF38 003CBF38 4000B47F */  sq         $20, 0x40($29)
    /* 2CBF3C 003CBF3C 3000B37F */  sq         $19, 0x30($29)
    /* 2CBF40 003CBF40 2000B27F */  sq         $18, 0x20($29)
    /* 2CBF44 003CBF44 2D98A000 */  daddu      $19, $5, $0
    /* 2CBF48 003CBF48 1000B17F */  sq         $17, 0x10($29)
    /* 2CBF4C 003CBF4C 0000B07F */  sq         $16, 0x0($29)
    /* 2CBF50 003CBF50 2C007126 */  addiu      $17, $19, 0x2C
    /* 2CBF54 003CBF54 14B7828F */  lw         $2, -0x48EC($28)
    /* 2CBF58 003CBF58 21106202 */  addu       $2, $19, $2
    /* 2CBF5C 003CBF5C 000040AC */  sw         $0, 0x0($2)
    /* 2CBF60 003CBF60 2C00B28C */  lw         $18, 0x2C($5)
    /* 2CBF64 003CBF64 1A005112 */  beq        $18, $17, .L003CBFD0
    /* 2CBF68 003CBF68 2DA08000 */   daddu     $20, $4, $0
    /* 2CBF6C 003CBF6C 8800103C */  lui        $16, %hi(jtbl_008873FC)
    /* 2CBF70 003CBF70 FC731026 */  addiu      $16, $16, %lo(jtbl_008873FC)
  .L003CBF74:
    /* 2CBF74 003CBF74 F4FF4526 */  addiu      $5, $18, -0xC
    /* 2CBF78 003CBF78 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2CBF7C 003CBF7C 0000528E */  lw         $18, 0x0($18)
    /* 2CBF80 003CBF80 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2CBF84 003CBF84 0C00A48C */  lw         $4, 0xC($5)
    /* 2CBF88 003CBF88 1000A28C */  lw         $2, 0x10($5)
    /* 2CBF8C 003CBF8C 000044AC */  sw         $4, 0x0($2)
    /* 2CBF90 003CBF90 1000A48C */  lw         $4, 0x10($5)
    /* 2CBF94 003CBF94 0C00A28C */  lw         $2, 0xC($5)
    /* 2CBF98 003CBF98 040044AC */  sw         $4, 0x4($2)
    /* 2CBF9C 003CBF9C 0000A48C */  lw         $4, 0x0($5)
    /* 2CBFA0 003CBFA0 0400A28C */  lw         $2, 0x4($5)
    /* 2CBFA4 003CBFA4 000044AC */  sw         $4, 0x0($2)
    /* 2CBFA8 003CBFA8 0400A48C */  lw         $4, 0x4($5)
    /* 2CBFAC 003CBFAC 0000A28C */  lw         $2, 0x0($5)
    /* 2CBFB0 003CBFB0 040044AC */  sw         $4, 0x4($2)
    /* 2CBFB4 003CBFB4 18B7848F */  lw         $4, -0x48E8($28)
    /* 2CBFB8 003CBFB8 0000028E */  lw         $2, 0x0($16)
    /* 2CBFBC 003CBFBC 21186400 */  addu       $3, $3, $4
    /* 2CBFC0 003CBFC0 09F84000 */  jalr       $2
    /* 2CBFC4 003CBFC4 0400648C */   lw        $4, 0x4($3)
    /* 2CBFC8 003CBFC8 EAFF5116 */  bne        $18, $17, .L003CBF74
    /* 2CBFCC 003CBFCC 00000000 */   nop
  .L003CBFD0:
    /* 2CBFD0 003CBFD0 3400648E */  lw         $4, 0x34($19)
    /* 2CBFD4 003CBFD4 3800638E */  lw         $3, 0x38($19)
    /* 2CBFD8 003CBFD8 2D108002 */  daddu      $2, $20, $0
    /* 2CBFDC 003CBFDC 000064AC */  sw         $4, 0x0($3)
    /* 2CBFE0 003CBFE0 3800648E */  lw         $4, 0x38($19)
    /* 2CBFE4 003CBFE4 3400638E */  lw         $3, 0x34($19)
    /* 2CBFE8 003CBFE8 040064AC */  sw         $4, 0x4($3)
    /* 2CBFEC 003CBFEC 5000BFDF */  ld         $31, 0x50($29)
    /* 2CBFF0 003CBFF0 4000B47B */  lq         $20, 0x40($29)
    /* 2CBFF4 003CBFF4 3000B37B */  lq         $19, 0x30($29)
    /* 2CBFF8 003CBFF8 2000B27B */  lq         $18, 0x20($29)
    /* 2CBFFC 003CBFFC 1000B17B */  lq         $17, 0x10($29)
    /* 2CC000 003CC000 0000B07B */  lq         $16, 0x0($29)
    /* 2CC004 003CC004 0800E003 */  jr         $31
    /* 2CC008 003CC008 6000BD27 */   addiu     $29, $29, 0x60
    /* 2CC00C 003CC00C 00000000 */  nop
.size func_003cbf30, 0xe0
