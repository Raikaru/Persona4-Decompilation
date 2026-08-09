.section .text
.set noat
.set noreorder
glabel func_0027bbc0
    /* 17BBC0 0027BBC0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 17BBC4 0027BBC4 1000BFFF */  sd         $31, 0x10($29)
    /* 17BBC8 0027BBC8 0000B07F */  sq         $16, 0x0($29)
    /* 17BBCC 0027BBCC 2D808000 */  daddu      $16, $4, $0
    /* 17BBD0 0027BBD0 10DE090C */  jal        func_00277840
    /* 17BBD4 0027BBD4 00000000 */   nop
    /* 17BBD8 0027BBD8 2D200002 */  daddu      $4, $16, $0
    /* 17BBDC 0027BBDC 10DE090C */  jal        func_00277840
    /* 17BBE0 0027BBE0 00000000 */   nop
    /* 17BBE4 0027BBE4 0000428C */  lw         $2, 0x0($2)
    /* 17BBE8 0027BBE8 07004010 */  beqz       $2, .L0027BC08
    /* 17BBEC 0027BBEC 00000000 */   nop
    /* 17BBF0 0027BBF0 2D200002 */  daddu      $4, $16, $0
    /* 17BBF4 0027BBF4 0A000524 */  addiu      $5, $0, 0xA
    /* 17BBF8 0027BBF8 09F84000 */  jalr       $2
    /* 17BBFC 0027BBFC 00000000 */   nop
    /* 17BC00 0027BC00 02000010 */  b          .L0027BC0C
    /* 17BC04 0027BC04 00000000 */   nop
  .L0027BC08:
    /* 17BC08 0027BC08 01000224 */  addiu      $2, $0, 0x1
  .L0027BC0C:
    /* 17BC0C 0027BC0C 1000BFDF */  ld         $31, 0x10($29)
    /* 17BC10 0027BC10 0000B07B */  lq         $16, 0x0($29)
    /* 17BC14 0027BC14 2000BD27 */  addiu      $29, $29, 0x20
    /* 17BC18 0027BC18 0800E003 */  jr         $31
    /* 17BC1C 0027BC1C 00000000 */   nop
.size func_0027bbc0, 0x60
