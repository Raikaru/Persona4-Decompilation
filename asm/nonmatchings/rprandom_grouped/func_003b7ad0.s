.section .text
.set noat
.set noreorder
glabel func_003b7ad0
    /* 2B7AD0 003B7AD0 8800023C */  lui        $2, %hi(D_00886494)
    /* 2B7AD4 003B7AD4 9464428C */  lw         $2, %lo(D_00886494)($2)
    /* 2B7AD8 003B7AD8 21188200 */  addu       $3, $4, $2
    /* 2B7ADC 003B7ADC 0000628C */  lw         $2, 0x0($3)
    /* 2B7AE0 003B7AE0 02004010 */  beqz       $2, .L003B7AEC
    /* 2B7AE4 003B7AE4 00000000 */   nop
    /* 2B7AE8 003B7AE8 000060AC */  sw         $0, 0x0($3)
  .L003B7AEC:
    /* 2B7AEC 003B7AEC 0800E003 */  jr         $31
    /* 2B7AF0 003B7AF0 2D108000 */   daddu     $2, $4, $0
    /* 2B7AF4 003B7AF4 00000000 */  nop
    /* 2B7AF8 003B7AF8 00000000 */  nop
    /* 2B7AFC 003B7AFC 00000000 */  nop
.size func_003b7ad0, 0x30
