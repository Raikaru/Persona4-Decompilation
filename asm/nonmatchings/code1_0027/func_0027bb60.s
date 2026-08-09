.section .text
.set noat
.set noreorder
glabel func_0027bb60
    /* 17BB60 0027BB60 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 17BB64 0027BB64 1000BFFF */  sd         $31, 0x10($29)
    /* 17BB68 0027BB68 0000B07F */  sq         $16, 0x0($29)
    /* 17BB6C 0027BB6C 2D808000 */  daddu      $16, $4, $0
    /* 17BB70 0027BB70 10DE090C */  jal        func_00277840
    /* 17BB74 0027BB74 00000000 */   nop
    /* 17BB78 0027BB78 2D200002 */  daddu      $4, $16, $0
    /* 17BB7C 0027BB7C 10DE090C */  jal        func_00277840
    /* 17BB80 0027BB80 00000000 */   nop
    /* 17BB84 0027BB84 0000428C */  lw         $2, 0x0($2)
    /* 17BB88 0027BB88 07004010 */  beqz       $2, .L0027BBA8
    /* 17BB8C 0027BB8C 00000000 */   nop
    /* 17BB90 0027BB90 2D200002 */  daddu      $4, $16, $0
    /* 17BB94 0027BB94 09000524 */  addiu      $5, $0, 0x9
    /* 17BB98 0027BB98 09F84000 */  jalr       $2
    /* 17BB9C 0027BB9C 00000000 */   nop
    /* 17BBA0 0027BBA0 02000010 */  b          .L0027BBAC
    /* 17BBA4 0027BBA4 00000000 */   nop
  .L0027BBA8:
    /* 17BBA8 0027BBA8 01000224 */  addiu      $2, $0, 0x1
  .L0027BBAC:
    /* 17BBAC 0027BBAC 1000BFDF */  ld         $31, 0x10($29)
    /* 17BBB0 0027BBB0 0000B07B */  lq         $16, 0x0($29)
    /* 17BBB4 0027BBB4 2000BD27 */  addiu      $29, $29, 0x20
    /* 17BBB8 0027BBB8 0800E003 */  jr         $31
    /* 17BBBC 0027BBBC 00000000 */   nop
.size func_0027bb60, 0x60
