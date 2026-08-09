.section .text
.set noat
.set noreorder
glabel func_002b2aa0
    /* 1B2AA0 002B2AA0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 1B2AA4 002B2AA4 1000BFFF */  sd         $31, 0x10($29)
    /* 1B2AA8 002B2AA8 0400B5E7 */  swc1       $f21, 0x4($29)
    /* 1B2AAC 002B2AAC 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 1B2AB0 002B2AB0 06650046 */  mov.s      $f20, $f12
    /* 1B2AB4 002B2AB4 466D0046 */  mov.s      $f21, $f13
    /* 1B2AB8 002B2AB8 32700F46 */  c.eq.s     $f14, $f15
    /* 1B2ABC 002B2ABC 04000045 */  bc1f       .L002B2AD0
    /* 1B2AC0 002B2AC0 00000000 */   nop
    /* 1B2AC4 002B2AC4 06A80046 */  mov.s      $f0, $f21
    /* 1B2AC8 002B2AC8 3B000010 */  b          .L002B2BB8
    /* 1B2ACC 002B2ACC 00000000 */   nop
  .L002B2AD0:
    /* 1B2AD0 002B2AD0 3C1E0400 */  dsll32     $3, $4, 24
    /* 1B2AD4 002B2AD4 3F1E0300 */  dsra32     $3, $3, 24
    /* 1B2AD8 002B2AD8 02000224 */  addiu      $2, $0, 0x2
    /* 1B2ADC 002B2ADC 22006210 */  beq        $3, $2, .L002B2B68
    /* 1B2AE0 002B2AE0 00000000 */   nop
    /* 1B2AE4 002B2AE4 01000224 */  addiu      $2, $0, 0x1
    /* 1B2AE8 002B2AE8 0D006210 */  beq        $3, $2, .L002B2B20
    /* 1B2AEC 002B2AEC 00000000 */   nop
    /* 1B2AF0 002B2AF0 03006010 */  beqz       $3, .L002B2B00
    /* 1B2AF4 002B2AF4 00000000 */   nop
    /* 1B2AF8 002B2AF8 2D000010 */  b          .L002B2BB0
    /* 1B2AFC 002B2AFC 00000000 */   nop
  .L002B2B00:
    /* 1B2B00 002B2B00 01A81446 */  sub.s      $f0, $f21, $f20
    /* 1B2B04 002B2B04 02700046 */  mul.s      $f0, $f14, $f0
    /* 1B2B08 002B2B08 03000F46 */  div.s      $f0, $f0, $f15
    /* 1B2B0C 002B2B0C 00000000 */  nop
    /* 1B2B10 002B2B10 00000000 */  nop
    /* 1B2B14 002B2B14 00A00046 */  add.s      $f0, $f20, $f0
    /* 1B2B18 002B2B18 27000010 */  b          .L002B2BB8
    /* 1B2B1C 002B2B1C 00000000 */   nop
  .L002B2B20:
    /* 1B2B20 002B2B20 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1B2B24 002B2B24 00008244 */  mtc1       $2, $f0
    /* 1B2B28 002B2B28 00000000 */  nop
    /* 1B2B2C 002B2B2C 42000F46 */  mul.s      $f1, $f0, $f15
    /* 1B2B30 002B2B30 FC8280C7 */  lwc1       $f0, -0x7D04($28)
    /* 1B2B34 002B2B34 03000146 */  div.s      $f0, $f0, $f1
    /* 1B2B38 002B2B38 00000000 */  nop
    /* 1B2B3C 002B2B3C 00000000 */  nop
    /* 1B2B40 002B2B40 02030E46 */  mul.s      $f12, $f0, $f14
    /* 1B2B44 002B2B44 EC2D110C */  jal        func_0044b7b0
    /* 1B2B48 002B2B48 00000000 */   nop
    /* 1B2B4C 002B2B4C 81A81446 */  sub.s      $f2, $f21, $f20
    /* 1B2B50 002B2B50 00088044 */  mtc1       $0, $f1
    /* 1B2B54 002B2B54 00000000 */  nop
    /* 1B2B58 002B2B58 18081446 */  adda.s     $f1, $f20
    /* 1B2B5C 002B2B5C 1C100046 */  madd.s     $f0, $f2, $f0
    /* 1B2B60 002B2B60 15000010 */  b          .L002B2BB8
    /* 1B2B64 002B2B64 00000000 */   nop
  .L002B2B68:
    /* 1B2B68 002B2B68 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1B2B6C 002B2B6C 00008244 */  mtc1       $2, $f0
    /* 1B2B70 002B2B70 00000000 */  nop
    /* 1B2B74 002B2B74 42000F46 */  mul.s      $f1, $f0, $f15
    /* 1B2B78 002B2B78 FC8280C7 */  lwc1       $f0, -0x7D04($28)
    /* 1B2B7C 002B2B7C 03000146 */  div.s      $f0, $f0, $f1
    /* 1B2B80 002B2B80 00000000 */  nop
    /* 1B2B84 002B2B84 00000000 */  nop
    /* 1B2B88 002B2B88 02030E46 */  mul.s      $f12, $f0, $f14
    /* 1B2B8C 002B2B8C 842D110C */  jal        func_0044b610
    /* 1B2B90 002B2B90 00000000 */   nop
    /* 1B2B94 002B2B94 81A81446 */  sub.s      $f2, $f21, $f20
    /* 1B2B98 002B2B98 00088044 */  mtc1       $0, $f1
    /* 1B2B9C 002B2B9C 00000000 */  nop
    /* 1B2BA0 002B2BA0 18081546 */  adda.s     $f1, $f21
    /* 1B2BA4 002B2BA4 1D100046 */  msub.s     $f0, $f2, $f0
    /* 1B2BA8 002B2BA8 03000010 */  b          .L002B2BB8
    /* 1B2BAC 002B2BAC 00000000 */   nop
  .L002B2BB0:
    /* 1B2BB0 002B2BB0 80BF023C */  lui        $2, (0xBF800000 >> 16)
    /* 1B2BB4 002B2BB4 00008244 */  mtc1       $2, $f0
  .L002B2BB8:
    /* 1B2BB8 002B2BB8 1000BFDF */  ld         $31, 0x10($29)
    /* 1B2BBC 002B2BBC 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* 1B2BC0 002B2BC0 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 1B2BC4 002B2BC4 2000BD27 */  addiu      $29, $29, 0x20
    /* 1B2BC8 002B2BC8 0800E003 */  jr         $31
    /* 1B2BCC 002B2BCC 00000000 */   nop
.size func_002b2aa0, 0x130
