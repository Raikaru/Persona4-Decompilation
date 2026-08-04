.section .text
.set noat
.set noreorder
glabel func_003bd590
    /* 2BD590 003BD590 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2BD594 003BD594 04000624 */  addiu      $6, $0, 0x4
    /* 2BD598 003BD598 2000BFFF */  sd         $31, 0x20($29)
    /* 2BD59C 003BD59C 1000B17F */  sq         $17, 0x10($29)
    /* 2BD5A0 003BD5A0 0000B07F */  sq         $16, 0x0($29)
    /* 2BD5A4 003BD5A4 2D888000 */  daddu      $17, $4, $0
    /* 2BD5A8 003BD5A8 2D80A000 */  daddu      $16, $5, $0
    /* 2BD5AC 003BD5AC D87C0F0C */  jal        func_003df360
    /* 2BD5B0 003BD5B0 9CB68527 */   addiu     $5, $28, -0x4964
    /* 2BD5B4 003BD5B4 06004010 */  beqz       $2, .L003BD5D0
    /* 2BD5B8 003BD5B8 00000000 */   nop
    /* 2BD5BC 003BD5BC 08000224 */  addiu      $2, $0, 0x8
    /* 2BD5C0 003BD5C0 05000212 */  beq        $16, $2, .L003BD5D8
    /* 2BD5C4 003BD5C4 00000000 */   nop
  .L003BD5C8:
    /* 2BD5C8 003BD5C8 0A000010 */  b          .L003BD5F4
    /* 2BD5CC 003BD5CC 2D102002 */   daddu     $2, $17, $0
  .L003BD5D0:
    /* 2BD5D0 003BD5D0 08000010 */  b          .L003BD5F4
    /* 2BD5D4 003BD5D4 2D100000 */   daddu     $2, $0, $0
  .L003BD5D8:
    /* 2BD5D8 003BD5D8 2D202002 */  daddu      $4, $17, $0
    /* 2BD5DC 003BD5DC 98B68527 */  addiu      $5, $28, -0x4968
    /* 2BD5E0 003BD5E0 D87C0F0C */  jal        func_003df360
    /* 2BD5E4 003BD5E4 04000624 */   addiu     $6, $0, 0x4
    /* 2BD5E8 003BD5E8 F7FF4014 */  bnez       $2, .L003BD5C8
    /* 2BD5EC 003BD5EC 00000000 */   nop
    /* 2BD5F0 003BD5F0 2D100000 */  daddu      $2, $0, $0
  .L003BD5F4:
    /* 2BD5F4 003BD5F4 2000BFDF */  ld         $31, 0x20($29)
    /* 2BD5F8 003BD5F8 1000B17B */  lq         $17, 0x10($29)
    /* 2BD5FC 003BD5FC 0000B07B */  lq         $16, 0x0($29)
    /* 2BD600 003BD600 0800E003 */  jr         $31
    /* 2BD604 003BD604 3000BD27 */   addiu     $29, $29, 0x30
    /* 2BD608 003BD608 00000000 */  nop
    /* 2BD60C 003BD60C 00000000 */  nop
.size func_003bd590, 0x80
