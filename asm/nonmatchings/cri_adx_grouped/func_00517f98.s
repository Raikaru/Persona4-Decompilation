.section .text
.set noat
.set noreorder
glabel func_00517f98
    /* 417F98 00517F98 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 417F9C 00517F9C 0000BFFF */  sd         $31, 0x0($29)
    /* 417FA0 00517FA0 0260140C */  jal        func_00518008
    /* 417FA4 00517FA4 00000000 */   nop
    /* 417FA8 00517FA8 09004010 */  beqz       $2, .L00517FD0
    /* 417FAC 00517FAC 9300053C */   lui       $5, %hi(D_00933F60)
  .L00517FB0:
    /* 417FB0 00517FB0 00000000 */  nop
    /* 417FB4 00517FB4 00000000 */  nop
    /* 417FB8 00517FB8 00000000 */  nop
    /* 417FBC 00517FBC 00000000 */  nop
    /* 417FC0 00517FC0 00000000 */  nop
    /* 417FC4 00517FC4 FAFF0010 */  b          .L00517FB0
    /* 417FC8 00517FC8 00000000 */   nop
    /* 417FCC 00517FCC 00000000 */  nop
  .L00517FD0:
    /* 417FD0 00517FD0 08000424 */  addiu      $4, $0, 0x8
    /* 417FD4 00517FD4 B20D140C */  jal        func_005036c8
    /* 417FD8 00517FD8 603FA524 */   addiu     $5, $5, %lo(D_00933F60)
    /* 417FDC 00517FDC 06004010 */  beqz       $2, .L00517FF8
    /* 417FE0 00517FE0 0000BFDF */   ld        $31, 0x0($29)
    /* 417FE4 00517FE4 00FF053C */  lui        $5, (0xFF000D01 >> 16)
    /* 417FE8 00517FE8 2D200000 */  daddu      $4, $0, $0
    /* 417FEC 00517FEC 010DA534 */  ori        $5, $5, (0xFF000D01 & 0xFFFF)
    /* 417FF0 00517FF0 B45E1408 */  j          func_00517ad0
    /* 417FF4 00517FF4 1000BD27 */   addiu     $29, $29, 0x10
  .L00517FF8:
    /* 417FF8 00517FF8 7400033C */  lui        $3, %hi(D_00745AE8)
    /* 417FFC 00517FFC E85A60AC */  sw         $0, %lo(D_00745AE8)($3)
    /* 418000 00518000 0800E003 */  jr         $31
    /* 418004 00518004 1000BD27 */   addiu     $29, $29, 0x10
.size func_00517f98, 0x70
