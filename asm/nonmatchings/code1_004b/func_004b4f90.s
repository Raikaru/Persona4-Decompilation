.section .text
.set noat
.set noreorder
glabel func_004b4f90
    /* 3B4F90 004B4F90 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3B4F94 004B4F94 1000BFFF */  sd         $31, 0x10($29)
    /* 3B4F98 004B4F98 0000B07F */  sq         $16, 0x0($29)
    /* 3B4F9C 004B4F9C 2D808000 */  daddu      $16, $4, $0
    /* 3B4FA0 004B4FA0 1800838C */  lw         $3, 0x18($4)
    /* 3B4FA4 004B4FA4 40100300 */  sll        $2, $3, 1
    /* 3B4FA8 004B4FA8 21104300 */  addu       $2, $2, $3
    /* 3B4FAC 004B4FAC C0180200 */  sll        $3, $2, 3
    /* 3B4FB0 004B4FB0 7100023C */  lui        $2, %hi(D_0071465C)
    /* 3B4FB4 004B4FB4 5C464224 */  addiu      $2, $2, %lo(D_0071465C)
    /* 3B4FB8 004B4FB8 21104300 */  addu       $2, $2, $3
    /* 3B4FBC 004B4FBC 0000428C */  lw         $2, 0x0($2)
    /* 3B4FC0 004B4FC0 09F84000 */  jalr       $2
    /* 3B4FC4 004B4FC4 00000000 */   nop
    /* 3B4FC8 004B4FC8 1400038E */  lw         $3, 0x14($16)
    /* 3B4FCC 004B4FCC 01006324 */  addiu      $3, $3, 0x1
    /* 3B4FD0 004B4FD0 140003AE */  sw         $3, 0x14($16)
    /* 3B4FD4 004B4FD4 1000BFDF */  ld         $31, 0x10($29)
    /* 3B4FD8 004B4FD8 0000B07B */  lq         $16, 0x0($29)
    /* 3B4FDC 004B4FDC 2000BD27 */  addiu      $29, $29, 0x20
    /* 3B4FE0 004B4FE0 0800E003 */  jr         $31
    /* 3B4FE4 004B4FE4 00000000 */   nop
    /* 3B4FE8 004B4FE8 00000000 */  nop
    /* 3B4FEC 004B4FEC 00000000 */  nop
.size func_004b4f90, 0x60
