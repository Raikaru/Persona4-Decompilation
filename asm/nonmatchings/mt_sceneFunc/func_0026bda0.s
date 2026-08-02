.section .text
.set noat
.set noreorder
glabel func_0026bda0
    /* 16BDA0 0026BDA0 90FFBD27 */  addiu      $29, $29, -0x70
    /* 16BDA4 0026BDA4 6000BFFF */  sd         $31, 0x60($29)
    /* 16BDA8 0026BDA8 5000B57F */  sq         $21, 0x50($29)
    /* 16BDAC 0026BDAC 4000B47F */  sq         $20, 0x40($29)
    /* 16BDB0 0026BDB0 3000B37F */  sq         $19, 0x30($29)
    /* 16BDB4 0026BDB4 2000B27F */  sq         $18, 0x20($29)
    /* 16BDB8 0026BDB8 1000B17F */  sq         $17, 0x10($29)
    /* 16BDBC 0026BDBC 0000B07F */  sq         $16, 0x0($29)
    /* 16BDC0 0026BDC0 2DA8A000 */  daddu      $21, $5, $0
    /* 16BDC4 0026BDC4 2DA0C000 */  daddu      $20, $6, $0
    /* 16BDC8 0026BDC8 2D98E000 */  daddu      $19, $7, $0
    /* 16BDCC 0026BDCC 2D900001 */  daddu      $18, $8, $0
    /* 16BDD0 0026BDD0 2D882001 */  daddu      $17, $9, $0
    /* 16BDD4 0026BDD4 9C14050C */  jal        func_00145270
    /* 16BDD8 0026BDD8 00000000 */   nop
    /* 16BDDC 0026BDDC 04004014 */  bnez       $2, .L0026BDF0
    /* 16BDE0 0026BDE0 00000000 */   nop
    /* 16BDE4 0026BDE4 2D100000 */  daddu      $2, $0, $0
    /* 16BDE8 0026BDE8 13000010 */  b          .L0026BE38
    /* 16BDEC 0026BDEC 00000000 */   nop
  .L0026BDF0:
    /* 16BDF0 0026BDF0 04004014 */  bnez       $2, .L0026BE04
    /* 16BDF4 0026BDF4 00000000 */   nop
    /* 16BDF8 0026BDF8 2D100000 */  daddu      $2, $0, $0
    /* 16BDFC 0026BDFC 0E000010 */  b          .L0026BE38
    /* 16BE00 0026BE00 00000000 */   nop
  .L0026BE04:
    /* 16BE04 0026BE04 E8005024 */  addiu      $16, $2, 0xE8
    /* 16BE08 0026BE08 2D200002 */  daddu      $4, $16, $0
    /* 16BE0C 0026BE0C 2D280000 */  daddu      $5, $0, $0
    /* 16BE10 0026BE10 0A000624 */  addiu      $6, $0, 0xA
    /* 16BE14 0026BE14 72FE100C */  jal        func_0043f9c8
    /* 16BE18 0026BE18 00000000 */   nop
    /* 16BE1C 0026BE1C 000015A2 */  sb         $21, 0x0($16)
    /* 16BE20 0026BE20 010000A2 */  sb         $0, 0x1($16)
    /* 16BE24 0026BE24 030014A2 */  sb         $20, 0x3($16)
    /* 16BE28 0026BE28 060013A6 */  sh         $19, 0x6($16)
    /* 16BE2C 0026BE2C 080012A6 */  sh         $18, 0x8($16)
    /* 16BE30 0026BE30 020011A2 */  sb         $17, 0x2($16)
    /* 16BE34 0026BE34 01000224 */  addiu      $2, $0, 0x1
  .L0026BE38:
    /* 16BE38 0026BE38 6000BFDF */  ld         $31, 0x60($29)
    /* 16BE3C 0026BE3C 5000B57B */  lq         $21, 0x50($29)
    /* 16BE40 0026BE40 4000B47B */  lq         $20, 0x40($29)
    /* 16BE44 0026BE44 3000B37B */  lq         $19, 0x30($29)
    /* 16BE48 0026BE48 2000B27B */  lq         $18, 0x20($29)
    /* 16BE4C 0026BE4C 1000B17B */  lq         $17, 0x10($29)
    /* 16BE50 0026BE50 0000B07B */  lq         $16, 0x0($29)
    /* 16BE54 0026BE54 7000BD27 */  addiu      $29, $29, 0x70
    /* 16BE58 0026BE58 0800E003 */  jr         $31
    /* 16BE5C 0026BE5C 00000000 */   nop
.size func_0026bda0, 0xc0
