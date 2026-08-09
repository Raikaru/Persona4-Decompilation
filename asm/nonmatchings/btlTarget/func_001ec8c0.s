.section .text
.set noat
.set noreorder
glabel func_001ec8c0
    /* EC8C0 001EC8C0 A0FFBD27 */  addiu      $29, $29, -0x60
    /* EC8C4 001EC8C4 4000BFFF */  sd         $31, 0x40($29)
    /* EC8C8 001EC8C8 3000B27F */  sq         $18, 0x30($29)
    /* EC8CC 001EC8CC 2000B17F */  sq         $17, 0x20($29)
    /* EC8D0 001EC8D0 1000B07F */  sq         $16, 0x10($29)
    /* EC8D4 001EC8D4 0000B4E7 */  swc1       $f20, 0x0($29)
    /* EC8D8 001EC8D8 2D908000 */  daddu      $18, $4, $0
    /* EC8DC 001EC8DC 2D88A000 */  daddu      $17, $5, $0
    /* EC8E0 001EC8E0 2D80C000 */  daddu      $16, $6, $0
    /* EC8E4 001EC8E4 06650046 */  mov.s      $f20, $f12
    /* EC8E8 001EC8E8 000081C4 */  lwc1       $f1, 0x0($4)
    /* EC8EC 001EC8EC 0000A0C4 */  lwc1       $f0, 0x0($5)
    /* EC8F0 001EC8F0 01080046 */  sub.s      $f0, $f1, $f0
    /* EC8F4 001EC8F4 5800A0E7 */  swc1       $f0, 0x58($29)
    /* EC8F8 001EC8F8 040081C4 */  lwc1       $f1, 0x4($4)
    /* EC8FC 001EC8FC 0400A0C4 */  lwc1       $f0, 0x4($5)
    /* EC900 001EC900 01080046 */  sub.s      $f0, $f1, $f0
    /* EC904 001EC904 5C00A0E7 */  swc1       $f0, 0x5C($29)
    /* EC908 001EC908 5800A427 */  addiu      $4, $29, 0x58
    /* EC90C 001EC90C 2D288000 */  daddu      $5, $4, $0
    /* EC910 001EC910 78900F0C */  jal        func_003e41e0
    /* EC914 001EC914 00000000 */   nop
    /* EC918 001EC918 000048C6 */  lwc1       $f8, 0x0($18)
    /* EC91C 001EC91C 000006C6 */  lwc1       $f6, 0x0($16)
    /* EC920 001EC920 41310846 */  sub.s      $f5, $f6, $f8
    /* EC924 001EC924 040047C6 */  lwc1       $f7, 0x4($18)
    /* EC928 001EC928 040004C6 */  lwc1       $f4, 0x4($16)
    /* EC92C 001EC92C C1200746 */  sub.s      $f3, $f4, $f7
    /* EC930 001EC930 5800A0C7 */  lwc1       $f0, 0x58($29)
    /* EC934 001EC934 87000046 */  neg.s      $f2, $f0
    /* EC938 001EC938 5C00A1C7 */  lwc1       $f1, 0x5C($29)
    /* EC93C 001EC93C 1A180246 */  mula.s     $f3, $f2
    /* EC940 001EC940 00008044 */  mtc1       $0, $f0
    /* EC944 001EC944 00000000 */  nop
    /* EC948 001EC948 5C290146 */  madd.s     $f5, $f5, $f1
    /* EC94C 001EC94C 18000646 */  adda.s     $f0, $f6
    /* EC950 001EC950 DD280146 */  msub.s     $f3, $f5, $f1
    /* EC954 001EC954 18000446 */  adda.s     $f0, $f4
    /* EC958 001EC958 5D280246 */  msub.s     $f1, $f5, $f2
    /* EC95C 001EC95C 34400346 */  c.lt.s     $f8, $f3
    /* EC960 001EC960 05000145 */  bc1t       .L001EC978
    /* EC964 001EC964 00000000 */   nop
    /* EC968 001EC968 000020C6 */  lwc1       $f0, 0x0($17)
    /* EC96C 001EC96C 36000346 */  c.le.s     $f0, $f3
    /* EC970 001EC970 08000145 */  bc1t       .L001EC994
    /* EC974 001EC974 00000000 */   nop
  .L001EC978:
    /* EC978 001EC978 36400346 */  c.le.s     $f8, $f3
    /* EC97C 001EC97C 13000045 */  bc1f       .L001EC9CC
    /* EC980 001EC980 00000000 */   nop
    /* EC984 001EC984 000020C6 */  lwc1       $f0, 0x0($17)
    /* EC988 001EC988 34000346 */  c.lt.s     $f0, $f3
    /* EC98C 001EC98C 0F000145 */  bc1t       .L001EC9CC
    /* EC990 001EC990 00000000 */   nop
  .L001EC994:
    /* EC994 001EC994 34380146 */  c.lt.s     $f7, $f1
    /* EC998 001EC998 05000145 */  bc1t       .L001EC9B0
    /* EC99C 001EC99C 00000000 */   nop
    /* EC9A0 001EC9A0 040020C6 */  lwc1       $f0, 0x4($17)
    /* EC9A4 001EC9A4 36000146 */  c.le.s     $f0, $f1
    /* EC9A8 001EC9A8 0B000145 */  bc1t       .L001EC9D8
    /* EC9AC 001EC9AC 00000000 */   nop
  .L001EC9B0:
    /* EC9B0 001EC9B0 36380146 */  c.le.s     $f7, $f1
    /* EC9B4 001EC9B4 05000045 */  bc1f       .L001EC9CC
    /* EC9B8 001EC9B8 00000000 */   nop
    /* EC9BC 001EC9BC 040020C6 */  lwc1       $f0, 0x4($17)
    /* EC9C0 001EC9C0 34000146 */  c.lt.s     $f0, $f1
    /* EC9C4 001EC9C4 04000045 */  bc1f       .L001EC9D8
    /* EC9C8 001EC9C8 00000000 */   nop
  .L001EC9CC:
    /* EC9CC 001EC9CC 2D100000 */  daddu      $2, $0, $0
    /* EC9D0 001EC9D0 07000010 */  b          .L001EC9F0
    /* EC9D4 001EC9D4 00000000 */   nop
  .L001EC9D8:
    /* EC9D8 001EC9D8 05280046 */  abs.s      $f0, $f5
    /* EC9DC 001EC9DC 34001446 */  c.lt.s     $f0, $f20
    /* EC9E0 001EC9E0 01000224 */  addiu      $2, $0, 0x1
    /* EC9E4 001EC9E4 02000145 */  bc1t       .L001EC9F0
    /* EC9E8 001EC9E8 00000000 */   nop
    /* EC9EC 001EC9EC 2D100000 */  daddu      $2, $0, $0
  .L001EC9F0:
    /* EC9F0 001EC9F0 4000BFDF */  ld         $31, 0x40($29)
    /* EC9F4 001EC9F4 3000B27B */  lq         $18, 0x30($29)
    /* EC9F8 001EC9F8 2000B17B */  lq         $17, 0x20($29)
    /* EC9FC 001EC9FC 1000B07B */  lq         $16, 0x10($29)
    /* ECA00 001ECA00 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* ECA04 001ECA04 6000BD27 */  addiu      $29, $29, 0x60
    /* ECA08 001ECA08 0800E003 */  jr         $31
    /* ECA0C 001ECA0C 00000000 */   nop
.size func_001ec8c0, 0x150
