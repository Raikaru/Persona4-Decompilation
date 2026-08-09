.section .text
.set noat
.set noreorder
glabel func_004ed648
    /* 3ED648 004ED648 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3ED64C 004ED64C 7400063C */  lui        $6, %hi(D_0073DB08)
    /* 3ED650 004ED650 08DBC224 */  addiu      $2, $6, %lo(D_0073DB08)
    /* 3ED654 004ED654 0000B0FF */  sd         $16, 0x0($29)
    /* 3ED658 004ED658 0800BFFF */  sd         $31, 0x8($29)
    /* 3ED65C 004ED65C 04004324 */  addiu      $3, $2, 0x4
    /* 3ED660 004ED660 2D408000 */  daddu      $8, $4, $0
    /* 3ED664 004ED664 2D200000 */  daddu      $4, $0, $0
    /* 3ED668 004ED668 0000628C */  lw         $2, 0x0($3)
    /* 3ED66C 004ED66C 0B004010 */  beqz       $2, .L004ED69C
    /* 3ED670 004ED670 2D38A000 */   daddu     $7, $5, $0
    /* 3ED674 004ED674 01008424 */  addiu      $4, $4, 0x1
  .L004ED678:
    /* 3ED678 004ED678 20008228 */  slti       $2, $4, 0x20
    /* 3ED67C 004ED67C 07004010 */  beqz       $2, .L004ED69C
    /* 3ED680 004ED680 24006324 */   addiu     $3, $3, 0x24
    /* 3ED684 004ED684 0000628C */  lw         $2, 0x0($3)
    /* 3ED688 004ED688 00000000 */  nop
    /* 3ED68C 004ED68C 00000000 */  nop
    /* 3ED690 004ED690 00000000 */  nop
    /* 3ED694 004ED694 F8FF4054 */  bnel       $2, $0, .L004ED678
    /* 3ED698 004ED698 01008424 */   addiu     $4, $4, 0x1
  .L004ED69C:
    /* 3ED69C 004ED69C 20000324 */  addiu      $3, $0, 0x20
    /* 3ED6A0 004ED6A0 17008310 */  beq        $4, $3, .L004ED700
    /* 3ED6A4 004ED6A4 2D100000 */   daddu     $2, $0, $0
    /* 3ED6A8 004ED6A8 C0800400 */  sll        $16, $4, 3
    /* 3ED6AC 004ED6AC 08DBC224 */  addiu      $2, $6, %lo(D_0073DB08)
    /* 3ED6B0 004ED6B0 21800402 */  addu       $16, $16, $4
    /* 3ED6B4 004ED6B4 7400033C */  lui        $3, %hi(D_0073DAD0)
    /* 3ED6B8 004ED6B8 80801000 */  sll        $16, $16, 2
    /* 3ED6BC 004ED6BC 7600063C */  lui        $6, %hi(D_0075CC10)
    /* 3ED6C0 004ED6C0 4F00053C */  lui        $5, %hi(func_004ed498)
    /* 3ED6C4 004ED6C4 21800202 */  addu       $16, $16, $2
    /* 3ED6C8 004ED6C8 D0DA6324 */  addiu      $3, $3, %lo(D_0073DAD0)
    /* 3ED6CC 004ED6CC 10CCC624 */  addiu      $6, $6, %lo(D_0075CC10)
    /* 3ED6D0 004ED6D0 01000224 */  addiu      $2, $0, 0x1
    /* 3ED6D4 004ED6D4 98D4A524 */  addiu      $5, $5, %lo(func_004ed498)
    /* 3ED6D8 004ED6D8 040002AE */  sw         $2, 0x4($16)
    /* 3ED6DC 004ED6DC 2D200002 */  daddu      $4, $16, $0
    /* 3ED6E0 004ED6E0 000003AE */  sw         $3, 0x0($16)
    /* 3ED6E4 004ED6E4 140008AE */  sw         $8, 0x14($16)
    /* 3ED6E8 004ED6E8 180007AE */  sw         $7, 0x18($16)
    /* 3ED6EC 004ED6EC 080006AE */  sw         $6, 0x8($16)
    /* 3ED6F0 004ED6F0 1C0005AE */  sw         $5, 0x1C($16)
    /* 3ED6F4 004ED6F4 4EB6130C */  jal        func_004ed938
    /* 3ED6F8 004ED6F8 200010AE */   sw        $16, 0x20($16)
    /* 3ED6FC 004ED6FC 2D100002 */  daddu      $2, $16, $0
  .L004ED700:
    /* 3ED700 004ED700 0000B0DF */  ld         $16, 0x0($29)
    /* 3ED704 004ED704 0800BFDF */  ld         $31, 0x8($29)
    /* 3ED708 004ED708 0800E003 */  jr         $31
    /* 3ED70C 004ED70C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004ed648, 0xc8
