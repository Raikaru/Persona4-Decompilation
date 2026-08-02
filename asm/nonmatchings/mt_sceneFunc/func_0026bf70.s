.section .text
.set noat
.set noreorder
glabel func_0026bf70
    /* 16BF70 0026BF70 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 16BF74 0026BF74 0000BFFF */  sd         $31, 0x0($29)
    /* 16BF78 0026BF78 FFFF8530 */  andi       $5, $4, 0xFFFF
    /* 16BF7C 0026BF7C 0F00033C */  lui        $3, (0xFFC00 >> 16)
    /* 16BF80 0026BF80 00FC6334 */  ori        $3, $3, (0xFFC00 & 0xFFFF)
    /* 16BF84 0026BF84 2418A300 */  and        $3, $5, $3
    /* 16BF88 0026BF88 832A0300 */  sra        $5, $3, 10
    /* 16BF8C 0026BF8C 07000324 */  addiu      $3, $0, 0x7
    /* 16BF90 0026BF90 0700A314 */  bne        $5, $3, .L0026BFB0
    /* 16BF94 0026BF94 00000000 */   nop
    /* 16BF98 0026BF98 9C14050C */  jal        func_00145270
    /* 16BF9C 0026BF9C 00000000 */   nop
    /* 16BFA0 0026BFA0 03004010 */  beqz       $2, .L0026BFB0
    /* 16BFA4 0026BFA4 00000000 */   nop
    /* 16BFA8 0026BFA8 4C0140A4 */  sh         $0, 0x14C($2)
    /* 16BFAC 0026BFAC 440140AC */  sw         $0, 0x144($2)
  .L0026BFB0:
    /* 16BFB0 0026BFB0 0000BFDF */  ld         $31, 0x0($29)
    /* 16BFB4 0026BFB4 1000BD27 */  addiu      $29, $29, 0x10
    /* 16BFB8 0026BFB8 0800E003 */  jr         $31
    /* 16BFBC 0026BFBC 00000000 */   nop
.size func_0026bf70, 0x50
