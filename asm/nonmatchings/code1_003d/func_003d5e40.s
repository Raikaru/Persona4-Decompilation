.section .text
.set noat
.set noreorder
glabel func_003d5e40
    /* 2D5E40 003D5E40 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2D5E44 003D5E44 0000BFFF */  sd         $31, 0x0($29)
    /* 2D5E48 003D5E48 00008044 */  mtc1       $0, $f0
    /* 2D5E4C 003D5E4C 040081C4 */  lwc1       $f1, 0x4($4)
    /* 2D5E50 003D5E50 01630146 */  sub.s      $f12, $f12, $f1
    /* 2D5E54 003D5E54 34600046 */  c.lt.s     $f12, $f0
    /* 2D5E58 003D5E58 05000045 */  bc1f       .L003D5E70
    /* 2D5E5C 003D5E5C 00000000 */   nop
    /* 2D5E60 003D5E60 74560F0C */  jal        func_003d59d0
    /* 2D5E64 003D5E64 07630046 */   neg.s     $f12, $f12
    /* 2D5E68 003D5E68 04000010 */  b          .L003D5E7C
    /* 2D5E6C 003D5E6C 0000BFDF */   ld        $31, 0x0($29)
  .L003D5E70:
    /* 2D5E70 003D5E70 F0560F0C */  jal        func_003d5bc0
    /* 2D5E74 003D5E74 00000000 */   nop
    /* 2D5E78 003D5E78 0000BFDF */  ld         $31, 0x0($29)
  .L003D5E7C:
    /* 2D5E7C 003D5E7C 01000224 */  addiu      $2, $0, 0x1
    /* 2D5E80 003D5E80 0800E003 */  jr         $31
    /* 2D5E84 003D5E84 1000BD27 */   addiu     $29, $29, 0x10
    /* 2D5E88 003D5E88 00000000 */  nop
    /* 2D5E8C 003D5E8C 00000000 */  nop
.size func_003d5e40, 0x50
