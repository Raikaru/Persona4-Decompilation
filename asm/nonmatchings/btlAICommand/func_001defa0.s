.section .text
.set noat
.set noreorder
glabel func_001defa0
    /* DEFA0 001DEFA0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* DEFA4 001DEFA4 1000BFFF */  sd         $31, 0x10($29)
    /* DEFA8 001DEFA8 0000B07F */  sq         $16, 0x0($29)
    /* DEFAC 001DEFAC 14740A0C */  jal        func_0029d050
    /* DEFB0 001DEFB0 00000000 */   nop
    /* DEFB4 001DEFB4 2D804000 */  daddu      $16, $2, $0
    /* DEFB8 001DEFB8 2D200000 */  daddu      $4, $0, $0
    /* DEFBC 001DEFBC 00730A0C */  jal        func_0029cc00
    /* DEFC0 001DEFC0 00000000 */   nop
    /* DEFC4 001DEFC4 08004014 */  bnez       $2, .L001DEFE8
    /* DEFC8 001DEFC8 00000000 */   nop
    /* DEFCC 001DEFCC 2D200002 */  daddu      $4, $16, $0
    /* DEFD0 001DEFD0 38000526 */  addiu      $5, $16, 0x38
    /* DEFD4 001DEFD4 00800634 */  ori        $6, $0, 0x8000
    /* DEFD8 001DEFD8 9079070C */  jal        func_001de640
    /* DEFDC 001DEFDC 00000000 */   nop
    /* DEFE0 001DEFE0 0F000010 */  b          .L001DF020
    /* DEFE4 001DEFE4 00000000 */   nop
  .L001DEFE8:
    /* DEFE8 001DEFE8 08004018 */  blez       $2, .L001DF00C
    /* DEFEC 001DEFEC 00000000 */   nop
    /* DEFF0 001DEFF0 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* DEFF4 001DEFF4 2D200002 */  daddu      $4, $16, $0
    /* DEFF8 001DEFF8 38000526 */  addiu      $5, $16, 0x38
    /* DEFFC 001DEFFC 9079070C */  jal        func_001de640
    /* DF000 001DF000 00000000 */   nop
    /* DF004 001DF004 06000010 */  b          .L001DF020
    /* DF008 001DF008 00000000 */   nop
  .L001DF00C:
    /* DF00C 001DF00C 2D200002 */  daddu      $4, $16, $0
    /* DF010 001DF010 38000526 */  addiu      $5, $16, 0x38
    /* DF014 001DF014 02800634 */  ori        $6, $0, 0x8002
    /* DF018 001DF018 9079070C */  jal        func_001de640
    /* DF01C 001DF01C 00000000 */   nop
  .L001DF020:
    /* DF020 001DF020 01000224 */  addiu      $2, $0, 0x1
    /* DF024 001DF024 1000BFDF */  ld         $31, 0x10($29)
    /* DF028 001DF028 0000B07B */  lq         $16, 0x0($29)
    /* DF02C 001DF02C 2000BD27 */  addiu      $29, $29, 0x20
    /* DF030 001DF030 0800E003 */  jr         $31
    /* DF034 001DF034 00000000 */   nop
    /* DF038 001DF038 00000000 */  nop
    /* DF03C 001DF03C 00000000 */  nop
.size func_001defa0, 0xa0
