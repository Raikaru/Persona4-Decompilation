.section .text
.set noat
.set noreorder
glabel func_003e7f50
    /* 2E7F50 003E7F50 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2E7F54 003E7F54 8800023C */  lui        $2, %hi(D_00887350)
    /* 2E7F58 003E7F58 1000BFFF */  sd         $31, 0x10($29)
    /* 2E7F5C 003E7F5C 2D300000 */  daddu      $6, $0, $0
    /* 2E7F60 003E7F60 0000B07F */  sq         $16, 0x0($29)
    /* 2E7F64 003E7F64 5073428C */  lw         $2, %lo(D_00887350)($2)
    /* 2E7F68 003E7F68 2D808000 */  daddu      $16, $4, $0
    /* 2E7F6C 003E7F6C 2D200000 */  daddu      $4, $0, $0
    /* 2E7F70 003E7F70 09F84000 */  jalr       $2
    /* 2E7F74 003E7F74 2D280002 */   daddu     $5, $16, $0
    /* 2E7F78 003E7F78 03004014 */  bnez       $2, .L003E7F88
    /* 2E7F7C 003E7F7C 00000000 */   nop
    /* 2E7F80 003E7F80 04000010 */  b          .L003E7F94
    /* 2E7F84 003E7F84 2D100000 */   daddu     $2, $0, $0
  .L003E7F88:
    /* 2E7F88 003E7F88 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2E7F8C 003E7F8C 2D100002 */  daddu      $2, $16, $0
    /* 2E7F90 003E7F90 E07260AC */  sw         $0, %lo(D_008872E0)($3)
  .L003E7F94:
    /* 2E7F94 003E7F94 1000BFDF */  ld         $31, 0x10($29)
    /* 2E7F98 003E7F98 0000B07B */  lq         $16, 0x0($29)
    /* 2E7F9C 003E7F9C 0800E003 */  jr         $31
    /* 2E7FA0 003E7FA0 2000BD27 */   addiu     $29, $29, 0x20
    /* 2E7FA4 003E7FA4 00000000 */  nop
    /* 2E7FA8 003E7FA8 00000000 */  nop
    /* 2E7FAC 003E7FAC 00000000 */  nop
.size func_003e7f50, 0x60
