.section .text
.set noat
.set noreorder
glabel func_0024ab70
    /* 14AB70 0024AB70 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 14AB74 0024AB74 0000BFFF */  sd         $31, 0x0($29)
    /* 14AB78 0024AB78 2D200000 */  daddu      $4, $0, $0
    /* 14AB7C 0024AB7C 00730A0C */  jal        func_0029cc00
    /* 14AB80 0024AB80 00000000 */   nop
    /* 14AB84 0024AB84 04004014 */  bnez       $2, .L0024AB98
    /* 14AB88 0024AB88 00000000 */   nop
    /* 14AB8C 0024AB8C 8423040C */  jal        func_00108e10
    /* 14AB90 0024AB90 00000000 */   nop
    /* 14AB94 0024AB94 FFFF4230 */  andi       $2, $2, 0xFFFF
  .L0024AB98:
    /* 14AB98 0024AB98 3C240200 */  dsll32     $4, $2, 16
    /* 14AB9C 0024AB9C 3F240400 */  dsra32     $4, $4, 16
    /* 14ABA0 0024ABA0 081E090C */  jal        func_00247820
    /* 14ABA4 0024ABA4 00000000 */   nop
    /* 14ABA8 0024ABA8 3C240200 */  dsll32     $4, $2, 16
    /* 14ABAC 0024ABAC 3F240400 */  dsra32     $4, $4, 16
    /* 14ABB0 0024ABB0 05008010 */  beqz       $4, .L0024ABC8
    /* 14ABB4 0024ABB4 00000000 */   nop
    /* 14ABB8 0024ABB8 D4730A0C */  jal        func_0029cf50
    /* 14ABBC 0024ABBC 00000000 */   nop
    /* 14ABC0 0024ABC0 04000010 */  b          .L0024ABD4
    /* 14ABC4 0024ABC4 00000000 */   nop
  .L0024ABC8:
    /* 14ABC8 0024ABC8 2D200000 */  daddu      $4, $0, $0
    /* 14ABCC 0024ABCC D4730A0C */  jal        func_0029cf50
    /* 14ABD0 0024ABD0 00000000 */   nop
  .L0024ABD4:
    /* 14ABD4 0024ABD4 01000224 */  addiu      $2, $0, 0x1
    /* 14ABD8 0024ABD8 0000BFDF */  ld         $31, 0x0($29)
    /* 14ABDC 0024ABDC 1000BD27 */  addiu      $29, $29, 0x10
    /* 14ABE0 0024ABE0 0800E003 */  jr         $31
    /* 14ABE4 0024ABE4 00000000 */   nop
    /* 14ABE8 0024ABE8 00000000 */  nop
    /* 14ABEC 0024ABEC 00000000 */  nop
.size func_0024ab70, 0x80
