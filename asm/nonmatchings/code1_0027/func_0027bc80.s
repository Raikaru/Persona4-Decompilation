.section .text
.set noat
.set noreorder
glabel func_0027bc80
    /* 17BC80 0027BC80 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 17BC84 0027BC84 1000BFFF */  sd         $31, 0x10($29)
    /* 17BC88 0027BC88 0000B07F */  sq         $16, 0x0($29)
    /* 17BC8C 0027BC8C 2D808000 */  daddu      $16, $4, $0
    /* 17BC90 0027BC90 10DE090C */  jal        func_00277840
    /* 17BC94 0027BC94 00000000 */   nop
    /* 17BC98 0027BC98 2D200002 */  daddu      $4, $16, $0
    /* 17BC9C 0027BC9C 10DE090C */  jal        func_00277840
    /* 17BCA0 0027BCA0 00000000 */   nop
    /* 17BCA4 0027BCA4 0000428C */  lw         $2, 0x0($2)
    /* 17BCA8 0027BCA8 07004010 */  beqz       $2, .L0027BCC8
    /* 17BCAC 0027BCAC 00000000 */   nop
    /* 17BCB0 0027BCB0 2D200002 */  daddu      $4, $16, $0
    /* 17BCB4 0027BCB4 0C000524 */  addiu      $5, $0, 0xC
    /* 17BCB8 0027BCB8 09F84000 */  jalr       $2
    /* 17BCBC 0027BCBC 00000000 */   nop
    /* 17BCC0 0027BCC0 02000010 */  b          .L0027BCCC
    /* 17BCC4 0027BCC4 00000000 */   nop
  .L0027BCC8:
    /* 17BCC8 0027BCC8 01000224 */  addiu      $2, $0, 0x1
  .L0027BCCC:
    /* 17BCCC 0027BCCC 1000BFDF */  ld         $31, 0x10($29)
    /* 17BCD0 0027BCD0 0000B07B */  lq         $16, 0x0($29)
    /* 17BCD4 0027BCD4 2000BD27 */  addiu      $29, $29, 0x20
    /* 17BCD8 0027BCD8 0800E003 */  jr         $31
    /* 17BCDC 0027BCDC 00000000 */   nop
.size func_0027bc80, 0x60
