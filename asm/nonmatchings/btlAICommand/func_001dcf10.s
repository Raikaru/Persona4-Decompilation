.section .text
.set noat
.set noreorder
glabel func_001dcf10
    /* DCF10 001DCF10 E0FFBD27 */  addiu      $29, $29, -0x20
    /* DCF14 001DCF14 1000BFFF */  sd         $31, 0x10($29)
    /* DCF18 001DCF18 0000B07F */  sq         $16, 0x0($29)
    /* DCF1C 001DCF1C 2D808000 */  daddu      $16, $4, $0
    /* DCF20 001DCF20 98000526 */  addiu      $5, $16, 0x98
    /* DCF24 001DCF24 6E008694 */  lhu        $6, 0x6E($4)
    /* DCF28 001DCF28 2D380000 */  daddu      $7, $0, $0
    /* DCF2C 001DCF2C C45F070C */  jal        func_001d7f10
    /* DCF30 001DCF30 00000000 */   nop
    /* DCF34 001DCF34 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* DCF38 001DCF38 14004010 */  beqz       $2, .L001DCF8C
    /* DCF3C 001DCF3C 00000000 */   nop
    /* DCF40 001DCF40 2D200000 */  daddu      $4, $0, $0
    /* DCF44 001DCF44 08000010 */  b          .L001DCF68
    /* DCF48 001DCF48 00000000 */   nop
  .L001DCF4C:
    /* DCF4C 001DCF4C FFFF8230 */  andi       $2, $4, 0xFFFF
    /* DCF50 001DCF50 80100200 */  sll        $2, $2, 2
    /* DCF54 001DCF54 21180202 */  addu       $3, $16, $2
    /* DCF58 001DCF58 9800628C */  lw         $2, 0x98($3)
    /* DCF5C 001DCF5C 380062AC */  sw         $2, 0x38($3)
    /* DCF60 001DCF60 01008224 */  addiu      $2, $4, 0x1
    /* DCF64 001DCF64 FFFF4430 */  andi       $4, $2, 0xFFFF
  .L001DCF68:
    /* DCF68 001DCF68 D0000396 */  lhu        $3, 0xD0($16)
    /* DCF6C 001DCF6C FFFF8230 */  andi       $2, $4, 0xFFFF
    /* DCF70 001DCF70 2A104300 */  slt        $2, $2, $3
    /* DCF74 001DCF74 F5FF4014 */  bnez       $2, .L001DCF4C
    /* DCF78 001DCF78 00000000 */   nop
    /* DCF7C 001DCF7C 6A0003A6 */  sh         $3, 0x6A($16)
    /* DCF80 001DCF80 01000224 */  addiu      $2, $0, 0x1
    /* DCF84 001DCF84 0B000010 */  b          .L001DCFB4
    /* DCF88 001DCF88 00000000 */   nop
  .L001DCF8C:
    /* DCF8C 001DCF8C D0000496 */  lhu        $4, 0xD0($16)
    /* DCF90 001DCF90 5CC7080C */  jal        func_00231d70
    /* DCF94 001DCF94 00000000 */   nop
    /* DCF98 001DCF98 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* DCF9C 001DCF9C 80100200 */  sll        $2, $2, 2
    /* DCFA0 001DCFA0 21105000 */  addu       $2, $2, $16
    /* DCFA4 001DCFA4 9800428C */  lw         $2, 0x98($2)
    /* DCFA8 001DCFA8 380002AE */  sw         $2, 0x38($16)
    /* DCFAC 001DCFAC 01000224 */  addiu      $2, $0, 0x1
    /* DCFB0 001DCFB0 6A0002A6 */  sh         $2, 0x6A($16)
  .L001DCFB4:
    /* DCFB4 001DCFB4 1000BFDF */  ld         $31, 0x10($29)
    /* DCFB8 001DCFB8 0000B07B */  lq         $16, 0x0($29)
    /* DCFBC 001DCFBC 2000BD27 */  addiu      $29, $29, 0x20
    /* DCFC0 001DCFC0 0800E003 */  jr         $31
    /* DCFC4 001DCFC4 00000000 */   nop
    /* DCFC8 001DCFC8 00000000 */  nop
    /* DCFCC 001DCFCC 00000000 */  nop
.size func_001dcf10, 0xc0
