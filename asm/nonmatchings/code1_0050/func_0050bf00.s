.section .text
.set noat
.set noreorder
glabel func_0050bf00
    /* 40BF00 0050BF00 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 40BF04 0050BF04 0000B0FF */  sd         $16, 0x0($29)
    /* 40BF08 0050BF08 2D808000 */  daddu      $16, $4, $0
    /* 40BF0C 0050BF0C 0800B1FF */  sd         $17, 0x8($29)
    /* 40BF10 0050BF10 1000BFFF */  sd         $31, 0x10($29)
    /* 40BF14 0050BF14 F42C140C */  jal        func_0050b3d0
    /* 40BF18 0050BF18 80021126 */   addiu     $17, $16, 0x280
    /* 40BF1C 0050BF1C 3C00028E */  lw         $2, 0x3C($16)
    /* 40BF20 0050BF20 1F004010 */  beqz       $2, .L0050BFA0
    /* 40BF24 0050BF24 2D200002 */   daddu     $4, $16, $0
    /* 40BF28 0050BF28 6A24140C */  jal        func_005091a8
    /* 40BF2C 0050BF2C 00000000 */   nop
    /* 40BF30 0050BF30 07004010 */  beqz       $2, .L0050BF50
    /* 40BF34 0050BF34 1000BFDF */   ld        $31, 0x10($29)
    /* 40BF38 0050BF38 7600043C */  lui        $4, %hi(D_0075ED28)
    /* 40BF3C 0050BF3C 0000B0DF */  ld         $16, 0x0($29)
    /* 40BF40 0050BF40 0800B1DF */  ld         $17, 0x8($29)
    /* 40BF44 0050BF44 28ED8424 */  addiu      $4, $4, %lo(D_0075ED28)
    /* 40BF48 0050BF48 88441408 */  j          func_00511220
    /* 40BF4C 0050BF4C 2000BD27 */   addiu     $29, $29, 0x20
  .L0050BF50:
    /* 40BF50 0050BF50 3843140C */  jal        func_00510ce0
    /* 40BF54 0050BF54 2D200002 */   daddu     $4, $16, $0
    /* 40BF58 0050BF58 6C3C140C */  jal        func_0050f1b0
    /* 40BF5C 0050BF5C 2D200002 */   daddu     $4, $16, $0
    /* 40BF60 0050BF60 4C3C140C */  jal        func_0050f130
    /* 40BF64 0050BF64 2D200002 */   daddu     $4, $16, $0
    /* 40BF68 0050BF68 09004010 */  beqz       $2, .L0050BF90
    /* 40BF6C 0050BF6C 2D200002 */   daddu     $4, $16, $0
    /* 40BF70 0050BF70 7600043C */  lui        $4, %hi(D_0075ED58)
    /* 40BF74 0050BF74 0000B0DF */  ld         $16, 0x0($29)
    /* 40BF78 0050BF78 0800B1DF */  ld         $17, 0x8($29)
    /* 40BF7C 0050BF7C 58ED8424 */  addiu      $4, $4, %lo(D_0075ED58)
    /* 40BF80 0050BF80 1000BFDF */  ld         $31, 0x10($29)
    /* 40BF84 0050BF84 88441408 */  j          func_00511220
    /* 40BF88 0050BF88 2000BD27 */   addiu     $29, $29, 0x20
    /* 40BF8C 0050BF8C 00000000 */  nop
  .L0050BF90:
    /* 40BF90 0050BF90 643C140C */  jal        func_0050f190
    /* 40BF94 0050BF94 00000000 */   nop
    /* 40BF98 0050BF98 EE2B140C */  jal        func_0050afb8
    /* 40BF9C 0050BF9C 2D200002 */   daddu     $4, $16, $0
  .L0050BFA0:
    /* 40BFA0 0050BFA0 FE2F140C */  jal        func_0050bff8
    /* 40BFA4 0050BFA4 2D200002 */   daddu     $4, $16, $0
    /* 40BFA8 0050BFA8 602F140C */  jal        func_0050bd80
    /* 40BFAC 0050BFAC 2D200002 */   daddu     $4, $16, $0
    /* 40BFB0 0050BFB0 2D200002 */  daddu      $4, $16, $0
    /* 40BFB4 0050BFB4 F830140C */  jal        func_0050c3e0
    /* 40BFB8 0050BFB8 72000582 */   lb        $5, 0x72($16)
    /* 40BFBC 0050BFBC 2D202002 */  daddu      $4, $17, $0
    /* 40BFC0 0050BFC0 A642140C */  jal        func_00510a98
    /* 40BFC4 0050BFC4 01000524 */   addiu     $5, $0, 0x1
    /* 40BFC8 0050BFC8 4442140C */  jal        func_00510910
    /* 40BFCC 0050BFCC 2D202002 */   daddu     $4, $17, $0
    /* 40BFD0 0050BFD0 840000AE */  sw         $0, 0x84($16)
    /* 40BFD4 0050BFD4 01000224 */  addiu      $2, $0, 0x1
    /* 40BFD8 0050BFD8 A80200AE */  sw         $0, 0x2A8($16)
    /* 40BFDC 0050BFDC 040002AE */  sw         $2, 0x4($16)
    /* 40BFE0 0050BFE0 710000A2 */  sb         $0, 0x71($16)
    /* 40BFE4 0050BFE4 0800B1DF */  ld         $17, 0x8($29)
    /* 40BFE8 0050BFE8 0000B0DF */  ld         $16, 0x0($29)
    /* 40BFEC 0050BFEC 1000BFDF */  ld         $31, 0x10($29)
    /* 40BFF0 0050BFF0 0800E003 */  jr         $31
    /* 40BFF4 0050BFF4 2000BD27 */   addiu     $29, $29, 0x20
.size func_0050bf00, 0xf8
