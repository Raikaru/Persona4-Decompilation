.section .text
.set noat
.set noreorder
glabel func_001cbf80
    /* CBF80 001CBF80 E0FFBD27 */  addiu      $29, $29, -0x20
    /* CBF84 001CBF84 1000BFFF */  sd         $31, 0x10($29)
    /* CBF88 001CBF88 0000B07F */  sq         $16, 0x0($29)
    /* CBF8C 001CBF8C 2D808000 */  daddu      $16, $4, $0
    /* CBF90 001CBF90 E000838C */  lw         $3, 0xE0($4)
    /* CBF94 001CBF94 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* CBF98 001CBF98 00608244 */  mtc1       $2, $f12
    /* CBF9C 001CBF9C 3000648C */  lw         $4, 0x30($3)
    /* CBFA0 001CBFA0 04000524 */  addiu      $5, $0, 0x4
    /* CBFA4 001CBFA4 7064060C */  jal        func_001991c0
    /* CBFA8 001CBFA8 00000000 */   nop
    /* CBFAC 001CBFAC 0E0102A6 */  sh         $2, 0x10E($16)
    /* CBFB0 001CBFB0 E000038E */  lw         $3, 0xE0($16)
    /* CBFB4 001CBFB4 3800638C */  lw         $3, 0x38($3)
    /* CBFB8 001CBFB8 000103AE */  sw         $3, 0x100($16)
    /* CBFBC 001CBFBC 0C0100A6 */  sh         $0, 0x10C($16)
    /* CBFC0 001CBFC0 1000BFDF */  ld         $31, 0x10($29)
    /* CBFC4 001CBFC4 0000B07B */  lq         $16, 0x0($29)
    /* CBFC8 001CBFC8 2000BD27 */  addiu      $29, $29, 0x20
    /* CBFCC 001CBFCC 0800E003 */  jr         $31
    /* CBFD0 001CBFD0 00000000 */   nop
    /* CBFD4 001CBFD4 00000000 */  nop
    /* CBFD8 001CBFD8 00000000 */  nop
    /* CBFDC 001CBFDC 00000000 */  nop
.size func_001cbf80, 0x60
