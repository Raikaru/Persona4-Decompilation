.section .text
.set noat
.set noreorder
glabel func_0050eec8
    /* 40EEC8 0050EEC8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 40EECC 0050EECC 0000B0FF */  sd         $16, 0x0($29)
    /* 40EED0 0050EED0 2D808000 */  daddu      $16, $4, $0
    /* 40EED4 0050EED4 0800B1FF */  sd         $17, 0x8($29)
    /* 40EED8 0050EED8 1000BFFF */  sd         $31, 0x10($29)
    /* 40EEDC 0050EEDC 0A35140C */  jal        func_0050d428
    /* 40EEE0 0050EEE0 2D88A000 */   daddu     $17, $5, $0
    /* 40EEE4 0050EEE4 01000324 */  addiu      $3, $0, 0x1
    /* 40EEE8 0050EEE8 09004310 */  beq        $2, $3, .L0050EF10
    /* 40EEEC 0050EEEC 2D200002 */   daddu     $4, $16, $0
    /* 40EEF0 0050EEF0 7600043C */  lui        $4, %hi(D_0075F980)
    /* 40EEF4 0050EEF4 0000B0DF */  ld         $16, 0x0($29)
    /* 40EEF8 0050EEF8 0800B1DF */  ld         $17, 0x8($29)
    /* 40EEFC 0050EEFC 80F98424 */  addiu      $4, $4, %lo(D_0075F980)
    /* 40EF00 0050EF00 1000BFDF */  ld         $31, 0x10($29)
    /* 40EF04 0050EF04 88441408 */  j          func_00511220
    /* 40EF08 0050EF08 2000BD27 */   addiu     $29, $29, 0x20
    /* 40EF0C 0050EF0C 00000000 */  nop
  .L0050EF10:
    /* 40EF10 0050EF10 2E39140C */  jal        func_0050e4b8
    /* 40EF14 0050EF14 00000000 */   nop
    /* 40EF18 0050EF18 2D282002 */  daddu      $5, $17, $0
    /* 40EF1C 0050EF1C 0000B0DF */  ld         $16, 0x0($29)
    /* 40EF20 0050EF20 2D204000 */  daddu      $4, $2, $0
    /* 40EF24 0050EF24 0800B1DF */  ld         $17, 0x8($29)
    /* 40EF28 0050EF28 1000BFDF */  ld         $31, 0x10($29)
    /* 40EF2C 0050EF2C EEAE1408 */  j          func_0052bbb8
    /* 40EF30 0050EF30 2000BD27 */   addiu     $29, $29, 0x20
    /* 40EF34 0050EF34 00000000 */  nop
.size func_0050eec8, 0x70
