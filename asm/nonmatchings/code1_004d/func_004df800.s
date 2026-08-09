.section .text
.set noat
.set noreorder
glabel func_004df800
    /* 3DF800 004DF800 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3DF804 004DF804 7300023C */  lui        $2, %hi(D_0072ACBC)
    /* 3DF808 004DF808 0800B1FF */  sd         $17, 0x8($29)
    /* 3DF80C 004DF80C BCAC5124 */  addiu      $17, $2, %lo(D_0072ACBC)
    /* 3DF810 004DF810 0000B0FF */  sd         $16, 0x0($29)
    /* 3DF814 004DF814 2D808000 */  daddu      $16, $4, $0
    /* 3DF818 004DF818 1000BFFF */  sd         $31, 0x10($29)
    /* 3DF81C 004DF81C 9EC4130C */  jal        func_004f1278
    /* 3DF820 004DF820 2D202002 */   daddu     $4, $17, $0
    /* 3DF824 004DF824 04004010 */  beqz       $2, .L004DF838
    /* 3DF828 004DF828 2D200002 */   daddu     $4, $16, $0
    /* 3DF82C 004DF82C 147E130C */  jal        func_004df850
    /* 3DF830 004DF830 00000000 */   nop
    /* 3DF834 004DF834 000020AE */  sw         $0, 0x0($17)
  .L004DF838:
    /* 3DF838 004DF838 0000B0DF */  ld         $16, 0x0($29)
    /* 3DF83C 004DF83C 0800B1DF */  ld         $17, 0x8($29)
    /* 3DF840 004DF840 1000BFDF */  ld         $31, 0x10($29)
    /* 3DF844 004DF844 0800E003 */  jr         $31
    /* 3DF848 004DF848 2000BD27 */   addiu     $29, $29, 0x20
    /* 3DF84C 004DF84C 00000000 */  nop
.size func_004df800, 0x50
