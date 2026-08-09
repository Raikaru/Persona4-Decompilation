.section .text
.set noat
.set noreorder
glabel func_004bdec0
    /* 3BDEC0 004BDEC0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BDEC4 004BDEC4 0000B0FF */  sd         $16, 0x0($29)
    /* 3BDEC8 004BDEC8 2D808000 */  daddu      $16, $4, $0
    /* 3BDECC 004BDECC 0800BFFF */  sd         $31, 0x8($29)
    /* 3BDED0 004BDED0 0400028E */  lw         $2, 0x4($16)
    /* 3BDED4 004BDED4 04004010 */  beqz       $2, .L004BDEE8
    /* 3BDED8 004BDED8 2D204000 */   daddu     $4, $2, $0
    /* 3BDEDC 004BDEDC 364F130C */  jal        func_004d3cd8
    /* 3BDEE0 004BDEE0 00000000 */   nop
    /* 3BDEE4 004BDEE4 040000AE */  sw         $0, 0x4($16)
  .L004BDEE8:
    /* 3BDEE8 004BDEE8 0000B0DF */  ld         $16, 0x0($29)
    /* 3BDEEC 004BDEEC 0800BFDF */  ld         $31, 0x8($29)
    /* 3BDEF0 004BDEF0 0800E003 */  jr         $31
    /* 3BDEF4 004BDEF4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004bdec0, 0x38
