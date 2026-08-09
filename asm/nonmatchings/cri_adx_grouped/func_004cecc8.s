.section .text
.set noat
.set noreorder
glabel func_004cecc8
    /* 3CECC8 004CECC8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3CECCC 004CECCC 0800B1FF */  sd         $17, 0x8($29)
    /* 3CECD0 004CECD0 2D88A000 */  daddu      $17, $5, $0
    /* 3CECD4 004CECD4 0000B0FF */  sd         $16, 0x0($29)
    /* 3CECD8 004CECD8 1000BFFF */  sd         $31, 0x10($29)
    /* 3CECDC 004CECDC 2A15130C */  jal        func_004c54a8
    /* 3CECE0 004CECE0 2D808000 */   daddu     $16, $4, $0
    /* 3CECE4 004CECE4 0600205A */  blezl      $17, .L004CED00
    /* 3CECE8 004CECE8 A400028E */   lw        $2, 0xA4($16)
    /* 3CECEC 004CECEC A000028E */  lw         $2, 0xA0($16)
    /* 3CECF0 004CECF0 21105100 */  addu       $2, $2, $17
    /* 3CECF4 004CECF4 04000010 */  b          .L004CED08
    /* 3CECF8 004CECF8 A00002AE */   sw        $2, 0xA0($16)
    /* 3CECFC 004CECFC 00000000 */  nop
  .L004CED00:
    /* 3CED00 004CED00 23105100 */  subu       $2, $2, $17
    /* 3CED04 004CED04 A40002AE */  sw         $2, 0xA4($16)
  .L004CED08:
    /* 3CED08 004CED08 3015130C */  jal        func_004c54c0
    /* 3CED0C 004CED0C 00000000 */   nop
    /* 3CED10 004CED10 2D102002 */  daddu      $2, $17, $0
    /* 3CED14 004CED14 0000B0DF */  ld         $16, 0x0($29)
    /* 3CED18 004CED18 0800B1DF */  ld         $17, 0x8($29)
    /* 3CED1C 004CED1C 1000BFDF */  ld         $31, 0x10($29)
    /* 3CED20 004CED20 0800E003 */  jr         $31
    /* 3CED24 004CED24 2000BD27 */   addiu     $29, $29, 0x20
.size func_004cecc8, 0x60
