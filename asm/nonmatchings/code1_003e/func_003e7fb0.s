.section .text
.set noat
.set noreorder
glabel func_003e7fb0
    /* 2E7FB0 003E7FB0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2E7FB4 003E7FB4 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2E7FB8 003E7FB8 1000BFFF */  sd         $31, 0x10($29)
    /* 2E7FBC 003E7FBC 0000B07F */  sq         $16, 0x0($29)
    /* 2E7FC0 003E7FC0 2D808000 */  daddu      $16, $4, $0
    /* 2E7FC4 003E7FC4 F8B50F0C */  jal        func_003ed7e0
    /* 2E7FC8 003E7FC8 E07250AC */   sw        $16, %lo(D_008872E0)($2)
    /* 2E7FCC 003E7FCC 8800023C */  lui        $2, %hi(D_0088732C)
    /* 2E7FD0 003E7FD0 2D200000 */  daddu      $4, $0, $0
    /* 2E7FD4 003E7FD4 2C73428C */  lw         $2, %lo(D_0088732C)($2)
    /* 2E7FD8 003E7FD8 2D280002 */  daddu      $5, $16, $0
    /* 2E7FDC 003E7FDC 09F84000 */  jalr       $2
    /* 2E7FE0 003E7FE0 2D300000 */   daddu     $6, $0, $0
    /* 2E7FE4 003E7FE4 03004014 */  bnez       $2, .L003E7FF4
    /* 2E7FE8 003E7FE8 00000000 */   nop
    /* 2E7FEC 003E7FEC 04000010 */  b          .L003E8000
    /* 2E7FF0 003E7FF0 2D100000 */   daddu     $2, $0, $0
  .L003E7FF4:
    /* 2E7FF4 003E7FF4 D043100C */  jal        func_00410f40
    /* 2E7FF8 003E7FF8 2D200002 */   daddu     $4, $16, $0
    /* 2E7FFC 003E7FFC 2D100002 */  daddu      $2, $16, $0
  .L003E8000:
    /* 2E8000 003E8000 1000BFDF */  ld         $31, 0x10($29)
    /* 2E8004 003E8004 0000B07B */  lq         $16, 0x0($29)
    /* 2E8008 003E8008 0800E003 */  jr         $31
    /* 2E800C 003E800C 2000BD27 */   addiu     $29, $29, 0x20
.size func_003e7fb0, 0x60
