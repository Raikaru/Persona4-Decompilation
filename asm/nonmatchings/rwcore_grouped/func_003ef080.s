.section .text
.set noat
.set noreorder
glabel func_003ef080
    /* 2EF080 003EF080 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2EF084 003EF084 1000BFFF */  sd         $31, 0x10($29)
    /* 2EF088 003EF088 0000B07F */  sq         $16, 0x0($29)
    /* 2EF08C 003EF08C 0800A010 */  beqz       $5, .L003EF0B0
    /* 2EF090 003EF090 2D808000 */   daddu     $16, $4, $0
    /* 2EF094 003EF094 8800023C */  lui        $2, %hi(D_00887348)
    /* 2EF098 003EF098 4873428C */  lw         $2, %lo(D_00887348)($2)
    /* 2EF09C 003EF09C 09F84000 */  jalr       $2
    /* 2EF0A0 003EF0A0 2D300000 */   daddu     $6, $0, $0
    /* 2EF0A4 003EF0A4 0A800200 */  movz       $16, $0, $2
    /* 2EF0A8 003EF0A8 03000010 */  b          .L003EF0B8
    /* 2EF0AC 003EF0AC 2D100002 */   daddu     $2, $16, $0
  .L003EF0B0:
    /* 2EF0B0 003EF0B0 000000AE */  sw         $0, 0x0($16)
    /* 2EF0B4 003EF0B4 2D100002 */  daddu      $2, $16, $0
  .L003EF0B8:
    /* 2EF0B8 003EF0B8 1000BFDF */  ld         $31, 0x10($29)
    /* 2EF0BC 003EF0BC 0000B07B */  lq         $16, 0x0($29)
    /* 2EF0C0 003EF0C0 0800E003 */  jr         $31
    /* 2EF0C4 003EF0C4 2000BD27 */   addiu     $29, $29, 0x20
    /* 2EF0C8 003EF0C8 00000000 */  nop
    /* 2EF0CC 003EF0CC 00000000 */  nop
.size func_003ef080, 0x50
