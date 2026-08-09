.section .text
.set noat
.set noreorder
glabel func_0050ed78
    /* 40ED78 0050ED78 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 40ED7C 0050ED7C 0000B0FF */  sd         $16, 0x0($29)
    /* 40ED80 0050ED80 2D808000 */  daddu      $16, $4, $0
    /* 40ED84 0050ED84 0800B1FF */  sd         $17, 0x8($29)
    /* 40ED88 0050ED88 2D88A000 */  daddu      $17, $5, $0
    /* 40ED8C 0050ED8C 1000B2FF */  sd         $18, 0x10($29)
    /* 40ED90 0050ED90 1800BFFF */  sd         $31, 0x18($29)
    /* 40ED94 0050ED94 0A35140C */  jal        func_0050d428
    /* 40ED98 0050ED98 2D90C000 */   daddu     $18, $6, $0
    /* 40ED9C 0050ED9C 01000324 */  addiu      $3, $0, 0x1
    /* 40EDA0 0050EDA0 09004310 */  beq        $2, $3, .L0050EDC8
    /* 40EDA4 0050EDA4 2D200002 */   daddu     $4, $16, $0
    /* 40EDA8 0050EDA8 7600043C */  lui        $4, %hi(D_0075F908)
    /* 40EDAC 0050EDAC 0000B0DF */  ld         $16, 0x0($29)
    /* 40EDB0 0050EDB0 0800B1DF */  ld         $17, 0x8($29)
    /* 40EDB4 0050EDB4 08F98424 */  addiu      $4, $4, %lo(D_0075F908)
    /* 40EDB8 0050EDB8 1000B2DF */  ld         $18, 0x10($29)
    /* 40EDBC 0050EDBC 1800BFDF */  ld         $31, 0x18($29)
    /* 40EDC0 0050EDC0 88441408 */  j          func_00511220
    /* 40EDC4 0050EDC4 2000BD27 */   addiu     $29, $29, 0x20
  .L0050EDC8:
    /* 40EDC8 0050EDC8 2E39140C */  jal        func_0050e4b8
    /* 40EDCC 0050EDCC 00000000 */   nop
    /* 40EDD0 0050EDD0 2D282002 */  daddu      $5, $17, $0
    /* 40EDD4 0050EDD4 2D304002 */  daddu      $6, $18, $0
    /* 40EDD8 0050EDD8 1000B2DF */  ld         $18, 0x10($29)
    /* 40EDDC 0050EDDC 0000B0DF */  ld         $16, 0x0($29)
    /* 40EDE0 0050EDE0 2D204000 */  daddu      $4, $2, $0
    /* 40EDE4 0050EDE4 0800B1DF */  ld         $17, 0x8($29)
    /* 40EDE8 0050EDE8 1800BFDF */  ld         $31, 0x18($29)
    /* 40EDEC 0050EDEC 98AE1408 */  j          func_0052ba60
    /* 40EDF0 0050EDF0 2000BD27 */   addiu     $29, $29, 0x20
    /* 40EDF4 0050EDF4 00000000 */  nop
.size func_0050ed78, 0x80
