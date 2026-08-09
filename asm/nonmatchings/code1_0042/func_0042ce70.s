.section .text
.set noat
.set noreorder
glabel func_0042ce70
    /* 32CE70 0042CE70 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 32CE74 0042CE74 1000B1FF */  sd         $17, 0x10($29)
    /* 32CE78 0042CE78 0000B0FF */  sd         $16, 0x0($29)
    /* 32CE7C 0042CE7C 2D88A000 */  daddu      $17, $5, $0
    /* 32CE80 0042CE80 2000B2FF */  sd         $18, 0x20($29)
    /* 32CE84 0042CE84 3000BFFF */  sd         $31, 0x30($29)
    /* 32CE88 0042CE88 88AE100C */  jal        func_0042ba20
    /* 32CE8C 0042CE8C 2D808000 */   daddu     $16, $4, $0
    /* 32CE90 0042CE90 2D200002 */  daddu      $4, $16, $0
    /* 32CE94 0042CE94 2D904000 */  daddu      $18, $2, $0
    /* 32CE98 0042CE98 88B3100C */  jal        func_0042ce20
    /* 32CE9C 0042CE9C 2D282002 */   daddu     $5, $17, $0
    /* 32CEA0 0042CEA0 03004012 */  beqz       $18, .L0042CEB0
    /* 32CEA4 0042CEA4 2D804000 */   daddu     $16, $2, $0
    /* 32CEA8 0042CEA8 9CAE100C */  jal        func_0042ba70
    /* 32CEAC 0042CEAC 00000000 */   nop
  .L0042CEB0:
    /* 32CEB0 0042CEB0 2D100002 */  daddu      $2, $16, $0
    /* 32CEB4 0042CEB4 3000BFDF */  ld         $31, 0x30($29)
    /* 32CEB8 0042CEB8 2000B2DF */  ld         $18, 0x20($29)
    /* 32CEBC 0042CEBC 1000B1DF */  ld         $17, 0x10($29)
    /* 32CEC0 0042CEC0 0000B0DF */  ld         $16, 0x0($29)
    /* 32CEC4 0042CEC4 0800E003 */  jr         $31
    /* 32CEC8 0042CEC8 4000BD27 */   addiu     $29, $29, 0x40
    /* 32CECC 0042CECC 00000000 */  nop
.size func_0042ce70, 0x60
