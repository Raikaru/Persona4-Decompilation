.section .text
.set noat
.set noreorder
glabel func_001b6a20
    /* B6A20 001B6A20 E0FFBD27 */  addiu      $29, $29, -0x20
    /* B6A24 001B6A24 1000BFFF */  sd         $31, 0x10($29)
    /* B6A28 001B6A28 0000B07F */  sq         $16, 0x0($29)
    /* B6A2C 001B6A2C ACB3908F */  lw         $16, -0x4C54($28)
    /* B6A30 001B6A30 0C00038E */  lw         $3, 0xC($16)
    /* B6A34 001B6A34 02006330 */  andi       $3, $3, 0x2
    /* B6A38 001B6A38 16006010 */  beqz       $3, .L001B6A94
    /* B6A3C 001B6A3C 00000000 */   nop
    /* B6A40 001B6A40 342B050C */  jal        func_0014acd0
    /* B6A44 001B6A44 00000000 */   nop
    /* B6A48 001B6A48 EC0103C6 */  lwc1       $f3, 0x1EC($16)
    /* B6A4C 001B6A4C F00102C6 */  lwc1       $f2, 0x1F0($16)
    /* B6A50 001B6A50 F40101C6 */  lwc1       $f1, 0x1F4($16)
    /* B6A54 001B6A54 F80100C6 */  lwc1       $f0, 0x1F8($16)
    /* B6A58 001B6A58 000043E4 */  swc1       $f3, 0x0($2)
    /* B6A5C 001B6A5C 040042E4 */  swc1       $f2, 0x4($2)
    /* B6A60 001B6A60 080041E4 */  swc1       $f1, 0x8($2)
    /* B6A64 001B6A64 0C0040E4 */  swc1       $f0, 0xC($2)
    /* B6A68 001B6A68 ACB3908F */  lw         $16, -0x4C54($28)
    /* B6A6C 001B6A6C 442B050C */  jal        func_0014ad10
    /* B6A70 001B6A70 00000000 */   nop
    /* B6A74 001B6A74 FC0103C6 */  lwc1       $f3, 0x1FC($16)
    /* B6A78 001B6A78 000202C6 */  lwc1       $f2, 0x200($16)
    /* B6A7C 001B6A7C 040201C6 */  lwc1       $f1, 0x204($16)
    /* B6A80 001B6A80 080200C6 */  lwc1       $f0, 0x208($16)
    /* B6A84 001B6A84 000043E4 */  swc1       $f3, 0x0($2)
    /* B6A88 001B6A88 040042E4 */  swc1       $f2, 0x4($2)
    /* B6A8C 001B6A8C 080041E4 */  swc1       $f1, 0x8($2)
    /* B6A90 001B6A90 0C0040E4 */  swc1       $f0, 0xC($2)
  .L001B6A94:
    /* B6A94 001B6A94 1000BFDF */  ld         $31, 0x10($29)
    /* B6A98 001B6A98 0000B07B */  lq         $16, 0x0($29)
    /* B6A9C 001B6A9C 2000BD27 */  addiu      $29, $29, 0x20
    /* B6AA0 001B6AA0 0800E003 */  jr         $31
    /* B6AA4 001B6AA4 00000000 */   nop
    /* B6AA8 001B6AA8 00000000 */  nop
    /* B6AAC 001B6AAC 00000000 */  nop
.size func_001b6a20, 0x90
