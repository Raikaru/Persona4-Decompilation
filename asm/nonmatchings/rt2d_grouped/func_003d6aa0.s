.section .text
.set noat
.set noreorder
glabel func_003d6aa0
    /* 2D6AA0 003D6AA0 1400A4C4 */  lwc1       $f4, 0x14($5)
    /* 2D6AA4 003D6AA4 08008424 */  addiu      $4, $4, 0x8
    /* 2D6AA8 003D6AA8 0800A0C4 */  lwc1       $f0, 0x8($5)
    /* 2D6AAC 003D6AAC 1000A5C4 */  lwc1       $f5, 0x10($5)
    /* 2D6AB0 003D6AB0 0C00A1C4 */  lwc1       $f1, 0xC($5)
    /* 2D6AB4 003D6AB4 00488044 */  mtc1       $0, $f9
    /* 2D6AB8 003D6AB8 1A000446 */  mula.s     $f0, $f4
    /* 2D6ABC 003D6ABC DD080546 */  msub.s     $f3, $f1, $f5
    /* 2D6AC0 003D6AC0 32180946 */  c.eq.s     $f3, $f9
    /* 2D6AC4 003D6AC4 0A000045 */  bc1f       .L003D6AF0
    /* 2D6AC8 003D6AC8 0800A624 */   addiu     $6, $5, 0x8
  .L003D6ACC:
    /* 2D6ACC 003D6ACC 1000C1C4 */  lwc1       $f1, 0x10($6)
    /* 2D6AD0 003D6AD0 100080C4 */  lwc1       $f0, 0x10($4)
    /* 2D6AD4 003D6AD4 01000146 */  sub.s      $f0, $f0, $f1
    /* 2D6AD8 003D6AD8 100080E4 */  swc1       $f0, 0x10($4)
    /* 2D6ADC 003D6ADC 1400C1C4 */  lwc1       $f1, 0x14($6)
    /* 2D6AE0 003D6AE0 140080C4 */  lwc1       $f0, 0x14($4)
    /* 2D6AE4 003D6AE4 01000146 */  sub.s      $f0, $f0, $f1
    /* 2D6AE8 003D6AE8 1E000010 */  b          .L003D6B64
    /* 2D6AEC 003D6AEC 140080E4 */   swc1      $f0, 0x14($4)
  .L003D6AF0:
    /* 2D6AF0 003D6AF0 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* 2D6AF4 003D6AF4 00108344 */  mtc1       $3, $f2
    /* 2D6AF8 003D6AF8 07280046 */  neg.s      $f0, $f5
    /* 2D6AFC 003D6AFC 83100346 */  div.s      $f2, $f2, $f3
    /* 2D6B00 003D6B00 42210246 */  mul.s      $f5, $f4, $f2
    /* 2D6B04 003D6B04 47080046 */  neg.s      $f1, $f1
    /* 2D6B08 003D6B08 080086C4 */  lwc1       $f6, 0x8($4)
    /* 2D6B0C 003D6B0C 42080246 */  mul.s      $f1, $f1, $f2
    /* 2D6B10 003D6B10 02010246 */  mul.s      $f4, $f0, $f2
    /* 2D6B14 003D6B14 0C0083C4 */  lwc1       $f3, 0xC($4)
    /* 2D6B18 003D6B18 02080646 */  mul.s      $f0, $f1, $f6
    /* 2D6B1C 003D6B1C 82080346 */  mul.s      $f2, $f1, $f3
    /* 2D6B20 003D6B20 18480046 */  adda.s     $f9, $f0
    /* 2D6B24 003D6B24 000088C4 */  lwc1       $f8, 0x0($4)
    /* 2D6B28 003D6B28 02200346 */  mul.s      $f0, $f4, $f3
    /* 2D6B2C 003D6B2C DC280846 */  madd.s     $f3, $f5, $f8
    /* 2D6B30 003D6B30 040087C4 */  lwc1       $f7, 0x4($4)
    /* 2D6B34 003D6B34 18480246 */  adda.s     $f9, $f2
    /* 2D6B38 003D6B38 42200646 */  mul.s      $f1, $f4, $f6
    /* 2D6B3C 003D6B3C 9C280746 */  madd.s     $f2, $f5, $f7
    /* 2D6B40 003D6B40 18480146 */  adda.s     $f9, $f1
    /* 2D6B44 003D6B44 000083E4 */  swc1       $f3, 0x0($4)
    /* 2D6B48 003D6B48 5C200846 */  madd.s     $f1, $f4, $f8
    /* 2D6B4C 003D6B4C 040082E4 */  swc1       $f2, 0x4($4)
    /* 2D6B50 003D6B50 18480046 */  adda.s     $f9, $f0
    /* 2D6B54 003D6B54 1C200746 */  madd.s     $f0, $f4, $f7
    /* 2D6B58 003D6B58 080081E4 */  swc1       $f1, 0x8($4)
    /* 2D6B5C 003D6B5C DBFF0010 */  b          .L003D6ACC
    /* 2D6B60 003D6B60 0C0080E4 */   swc1      $f0, 0xC($4)
  .L003D6B64:
    /* 2D6B64 003D6B64 0800E003 */  jr         $31
    /* 2D6B68 003D6B68 00000000 */   nop
    /* 2D6B6C 003D6B6C 00000000 */  nop
.size func_003d6aa0, 0xd0
