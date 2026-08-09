.section .text
.set noat
.set noreorder
glabel func_0042cf80
    /* 32CF80 0042CF80 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 32CF84 0042CF84 0000B0FF */  sd         $16, 0x0($29)
    /* 32CF88 0042CF88 1000B1FF */  sd         $17, 0x10($29)
    /* 32CF8C 0042CF8C 2000BFFF */  sd         $31, 0x20($29)
    /* 32CF90 0042CF90 88AE100C */  jal        func_0042ba20
    /* 32CF94 0042CF94 2D808000 */   daddu     $16, $4, $0
    /* 32CF98 0042CF98 2D200002 */  daddu      $4, $16, $0
    /* 32CF9C 0042CF9C B4B3100C */  jal        func_0042ced0
    /* 32CFA0 0042CFA0 2D884000 */   daddu     $17, $2, $0
    /* 32CFA4 0042CFA4 03002012 */  beqz       $17, .L0042CFB4
    /* 32CFA8 0042CFA8 2D804000 */   daddu     $16, $2, $0
    /* 32CFAC 0042CFAC 9CAE100C */  jal        func_0042ba70
    /* 32CFB0 0042CFB0 00000000 */   nop
  .L0042CFB4:
    /* 32CFB4 0042CFB4 2D100002 */  daddu      $2, $16, $0
    /* 32CFB8 0042CFB8 2000BFDF */  ld         $31, 0x20($29)
    /* 32CFBC 0042CFBC 1000B1DF */  ld         $17, 0x10($29)
    /* 32CFC0 0042CFC0 0000B0DF */  ld         $16, 0x0($29)
    /* 32CFC4 0042CFC4 0800E003 */  jr         $31
    /* 32CFC8 0042CFC8 3000BD27 */   addiu     $29, $29, 0x30
    /* 32CFCC 0042CFCC 00000000 */  nop
.size func_0042cf80, 0x50
