.section .text
.set noat
.set noreorder
glabel func_004c0f88
    /* 3C0F88 004C0F88 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C0F8C 004C0F8C 0000B0FF */  sd         $16, 0x0($29)
    /* 3C0F90 004C0F90 2D808000 */  daddu      $16, $4, $0
    /* 3C0F94 004C0F94 0800BFFF */  sd         $31, 0x8($29)
    /* 3C0F98 004C0F98 0400028E */  lw         $2, 0x4($16)
    /* 3C0F9C 004C0F9C 04004010 */  beqz       $2, .L004C0FB0
    /* 3C0FA0 004C0FA0 2D204000 */   daddu     $4, $2, $0
    /* 3C0FA4 004C0FA4 C8F5120C */  jal        func_004bd720
    /* 3C0FA8 004C0FA8 00000000 */   nop
    /* 3C0FAC 004C0FAC 040000AE */  sw         $0, 0x4($16)
  .L004C0FB0:
    /* 3C0FB0 004C0FB0 0000B0DF */  ld         $16, 0x0($29)
    /* 3C0FB4 004C0FB4 0800BFDF */  ld         $31, 0x8($29)
    /* 3C0FB8 004C0FB8 0800E003 */  jr         $31
    /* 3C0FBC 004C0FBC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c0f88, 0x38
