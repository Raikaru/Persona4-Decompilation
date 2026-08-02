.section .text
.set noat
.set noreorder
glabel func_0036bb60
    /* 26BB60 0036BB60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 26BB64 0036BB64 0000BFFF */  sd         $31, 0x0($29)
    /* 26BB68 0036BB68 ACB5828F */  lw         $2, -0x4A54($28)
    /* 26BB6C 0036BB6C 06004014 */  bnez       $2, .L0036BB88
    /* 26BB70 0036BB70 00000000 */   nop
    /* 26BB74 0036BB74 6500043C */  lui        $4, %hi(D_0064E4E0)
    /* 26BB78 0036BB78 E0E48424 */  addiu      $4, $4, %lo(D_0064E4E0)
    /* 26BB7C 0036BB7C 75000524 */  addiu      $5, $0, 0x75
    /* 26BB80 0036BB80 CCB5110C */  jal        func_0046d730
    /* 26BB84 0036BB84 00000000 */   nop
  .L0036BB88:
    /* 26BB88 0036BB88 ACB5838F */  lw         $3, -0x4A54($28)
    /* 26BB8C 0036BB8C 2D200000 */  daddu      $4, $0, $0
    /* 26BB90 0036BB90 0C000010 */  b          .L0036BBC4
    /* 26BB94 0036BB94 00000000 */   nop
  .L0036BB98:
    /* 26BB98 0036BB98 C0100400 */  sll        $2, $4, 3
    /* 26BB9C 0036BB9C 21104400 */  addu       $2, $2, $4
    /* 26BBA0 0036BBA0 C0100200 */  sll        $2, $2, 3
    /* 26BBA4 0036BBA4 21104400 */  addu       $2, $2, $4
    /* 26BBA8 0036BBA8 80100200 */  sll        $2, $2, 2
    /* 26BBAC 0036BBAC 21106200 */  addu       $2, $3, $2
    /* 26BBB0 0036BBB0 9402428C */  lw         $2, 0x294($2)
    /* 26BBB4 0036BBB4 01004230 */  andi       $2, $2, 0x1
    /* 26BBB8 0036BBB8 05004014 */  bnez       $2, .L0036BBD0
    /* 26BBBC 0036BBBC 00000000 */   nop
    /* 26BBC0 0036BBC0 01008424 */  addiu      $4, $4, 0x1
  .L0036BBC4:
    /* 26BBC4 0036BBC4 20008228 */  slti       $2, $4, 0x20
    /* 26BBC8 0036BBC8 F3FF4014 */  bnez       $2, .L0036BB98
    /* 26BBCC 0036BBCC 00000000 */   nop
  .L0036BBD0:
    /* 26BBD0 0036BBD0 20008228 */  slti       $2, $4, 0x20
    /* 26BBD4 0036BBD4 0000BFDF */  ld         $31, 0x0($29)
    /* 26BBD8 0036BBD8 1000BD27 */  addiu      $29, $29, 0x10
    /* 26BBDC 0036BBDC 0800E003 */  jr         $31
    /* 26BBE0 0036BBE0 00000000 */   nop
    /* 26BBE4 0036BBE4 00000000 */  nop
    /* 26BBE8 0036BBE8 00000000 */  nop
    /* 26BBEC 0036BBEC 00000000 */  nop
.size func_0036bb60, 0x90
