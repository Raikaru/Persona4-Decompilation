.section .text
.set noat
.set noreorder
glabel func_003fe630
    /* 2FE630 003FE630 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2FE634 003FE634 5C000424 */  addiu      $4, $0, 0x5C
    /* 2FE638 003FE638 0000BFFF */  sd         $31, 0x0($29)
    /* 2FE63C 003FE63C 0C040524 */  addiu      $5, $0, 0x40C
    /* 2FE640 003FE640 2D300000 */  daddu      $6, $0, $0
    /* 2FE644 003FE644 2D380000 */  daddu      $7, $0, $0
    /* 2FE648 003FE648 E8B00F0C */  jal        func_003ec3a0
    /* 2FE64C 003FE64C 2D400000 */   daddu     $8, $0, $0
    /* 2FE650 003FE650 38B982AF */  sw         $2, -0x46C8($28)
    /* 2FE654 003FE654 2A104000 */  slt        $2, $2, $0
    /* 2FE658 003FE658 01004238 */  xori       $2, $2, 0x1
    /* 2FE65C 003FE65C 03004014 */  bnez       $2, .L003FE66C
    /* 2FE660 003FE660 00000000 */   nop
  .L003FE664:
    /* 2FE664 003FE664 24000010 */  b          .L003FE6F8
    /* 2FE668 003FE668 0000BFDF */   ld        $31, 0x0($29)
  .L003FE66C:
    /* 2FE66C 003FE66C D8000424 */  addiu      $4, $0, 0xD8
    /* 2FE670 003FE670 0C040524 */  addiu      $5, $0, 0x40C
    /* 2FE674 003FE674 2D300000 */  daddu      $6, $0, $0
    /* 2FE678 003FE678 2D380000 */  daddu      $7, $0, $0
    /* 2FE67C 003FE67C 04A10F0C */  jal        func_003e8410
    /* 2FE680 003FE680 2D400000 */   daddu     $8, $0, $0
    /* 2FE684 003FE684 34B982AF */  sw         $2, -0x46CC($28)
    /* 2FE688 003FE688 2A104000 */  slt        $2, $2, $0
    /* 2FE68C 003FE68C 01004238 */  xori       $2, $2, 0x1
    /* 2FE690 003FE690 18004010 */  beqz       $2, .L003FE6F4
    /* 2FE694 003FE694 00000000 */   nop
    /* 2FE698 003FE698 2D200000 */  daddu      $4, $0, $0
    /* 2FE69C 003FE69C 10010524 */  addiu      $5, $0, 0x110
    /* 2FE6A0 003FE6A0 2D300000 */  daddu      $6, $0, $0
    /* 2FE6A4 003FE6A4 2D380000 */  daddu      $7, $0, $0
    /* 2FE6A8 003FE6A8 24BE0F0C */  jal        func_003ef890
    /* 2FE6AC 003FE6AC 2D400000 */   daddu     $8, $0, $0
    /* 2FE6B0 003FE6B0 30B982AF */  sw         $2, -0x46D0($28)
    /* 2FE6B4 003FE6B4 2A104000 */  slt        $2, $2, $0
    /* 2FE6B8 003FE6B8 01004238 */  xori       $2, $2, 0x1
    /* 2FE6BC 003FE6BC 0D004010 */  beqz       $2, .L003FE6F4
    /* 2FE6C0 003FE6C0 00000000 */   nop
    /* 2FE6C4 003FE6C4 3F00053C */  lui        $5, %hi(func_003f6910)
    /* 2FE6C8 003FE6C8 3F00063C */  lui        $6, %hi(func_003f6990)
    /* 2FE6CC 003FE6CC 3F00073C */  lui        $7, %hi(func_003f69f0)
    /* 2FE6D0 003FE6D0 10010424 */  addiu      $4, $0, 0x110
    /* 2FE6D4 003FE6D4 1069A524 */  addiu      $5, $5, %lo(func_003f6910)
    /* 2FE6D8 003FE6D8 9069C624 */  addiu      $6, $6, %lo(func_003f6990)
    /* 2FE6DC 003FE6DC 84980F0C */  jal        func_003e6210
    /* 2FE6E0 003FE6E0 F069E724 */   addiu     $7, $7, %lo(func_003f69f0)
    /* 2FE6E4 003FE6E4 30B982AF */  sw         $2, -0x46D0($28)
    /* 2FE6E8 003FE6E8 2A104000 */  slt        $2, $2, $0
    /* 2FE6EC 003FE6EC DDFF0010 */  b          .L003FE664
    /* 2FE6F0 003FE6F0 01004238 */   xori      $2, $2, 0x1
  .L003FE6F4:
    /* 2FE6F4 003FE6F4 0000BFDF */  ld         $31, 0x0($29)
  .L003FE6F8:
    /* 2FE6F8 003FE6F8 0800E003 */  jr         $31
    /* 2FE6FC 003FE6FC 1000BD27 */   addiu     $29, $29, 0x10
.size func_003fe630, 0xd0
