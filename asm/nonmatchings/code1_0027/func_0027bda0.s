.section .text
.set noat
.set noreorder
glabel func_0027bda0
    /* 17BDA0 0027BDA0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 17BDA4 0027BDA4 1000BFFF */  sd         $31, 0x10($29)
    /* 17BDA8 0027BDA8 0000B07F */  sq         $16, 0x0($29)
    /* 17BDAC 0027BDAC 2D808000 */  daddu      $16, $4, $0
    /* 17BDB0 0027BDB0 10DE090C */  jal        func_00277840
    /* 17BDB4 0027BDB4 00000000 */   nop
    /* 17BDB8 0027BDB8 2D200002 */  daddu      $4, $16, $0
    /* 17BDBC 0027BDBC 10DE090C */  jal        func_00277840
    /* 17BDC0 0027BDC0 00000000 */   nop
    /* 17BDC4 0027BDC4 0000428C */  lw         $2, 0x0($2)
    /* 17BDC8 0027BDC8 07004010 */  beqz       $2, .L0027BDE8
    /* 17BDCC 0027BDCC 00000000 */   nop
    /* 17BDD0 0027BDD0 2D200002 */  daddu      $4, $16, $0
    /* 17BDD4 0027BDD4 11000524 */  addiu      $5, $0, 0x11
    /* 17BDD8 0027BDD8 09F84000 */  jalr       $2
    /* 17BDDC 0027BDDC 00000000 */   nop
    /* 17BDE0 0027BDE0 02000010 */  b          .L0027BDEC
    /* 17BDE4 0027BDE4 00000000 */   nop
  .L0027BDE8:
    /* 17BDE8 0027BDE8 01000224 */  addiu      $2, $0, 0x1
  .L0027BDEC:
    /* 17BDEC 0027BDEC 1000BFDF */  ld         $31, 0x10($29)
    /* 17BDF0 0027BDF0 0000B07B */  lq         $16, 0x0($29)
    /* 17BDF4 0027BDF4 2000BD27 */  addiu      $29, $29, 0x20
    /* 17BDF8 0027BDF8 0800E003 */  jr         $31
    /* 17BDFC 0027BDFC 00000000 */   nop
.size func_0027bda0, 0x60
