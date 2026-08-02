.section .text
.set noat
.set noreorder
glabel func_0036ccc0
    /* 26CCC0 0036CCC0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 26CCC4 0036CCC4 1000BFFF */  sd         $31, 0x10($29)
    /* 26CCC8 0036CCC8 0000B07F */  sq         $16, 0x0($29)
    /* 26CCCC 0036CCCC ACB5828F */  lw         $2, -0x4A54($28)
    /* 26CCD0 0036CCD0 06004014 */  bnez       $2, .L0036CCEC
    /* 26CCD4 0036CCD4 00000000 */   nop
    /* 26CCD8 0036CCD8 6500043C */  lui        $4, %hi(D_0064E4E0)
    /* 26CCDC 0036CCDC E0E48424 */  addiu      $4, $4, %lo(D_0064E4E0)
    /* 26CCE0 0036CCE0 75000524 */  addiu      $5, $0, 0x75
    /* 26CCE4 0036CCE4 CCB5110C */  jal        func_0046d730
    /* 26CCE8 0036CCE8 00000000 */   nop
  .L0036CCEC:
    /* 26CCEC 0036CCEC ACB5838F */  lw         $3, -0x4A54($28)
    /* 26CCF0 0036CCF0 2D800000 */  daddu      $16, $0, $0
    /* 26CCF4 0036CCF4 0B000010 */  b          .L0036CD24
    /* 26CCF8 0036CCF8 00000000 */   nop
  .L0036CCFC:
    /* 26CCFC 0036CCFC 80101000 */  sll        $2, $16, 2
    /* 26CD00 0036CD00 21105000 */  addu       $2, $2, $16
    /* 26CD04 0036CD04 80100200 */  sll        $2, $2, 2
    /* 26CD08 0036CD08 21106200 */  addu       $2, $3, $2
    /* 26CD0C 0036CD0C 5400428C */  lw         $2, 0x54($2)
    /* 26CD10 0036CD10 27104000 */  not        $2, $2
    /* 26CD14 0036CD14 01004230 */  andi       $2, $2, 0x1
    /* 26CD18 0036CD18 05004014 */  bnez       $2, .L0036CD30
    /* 26CD1C 0036CD1C 00000000 */   nop
    /* 26CD20 0036CD20 01001026 */  addiu      $16, $16, 0x1
  .L0036CD24:
    /* 26CD24 0036CD24 1000022A */  slti       $2, $16, 0x10
    /* 26CD28 0036CD28 F4FF4014 */  bnez       $2, .L0036CCFC
    /* 26CD2C 0036CD2C 00000000 */   nop
  .L0036CD30:
    /* 26CD30 0036CD30 1000022A */  slti       $2, $16, 0x10
    /* 26CD34 0036CD34 06004014 */  bnez       $2, .L0036CD50
    /* 26CD38 0036CD38 00000000 */   nop
    /* 26CD3C 0036CD3C 6500043C */  lui        $4, %hi(D_0064E4E0)
    /* 26CD40 0036CD40 E0E48424 */  addiu      $4, $4, %lo(D_0064E4E0)
    /* 26CD44 0036CD44 F0020524 */  addiu      $5, $0, 0x2F0
    /* 26CD48 0036CD48 CCB5110C */  jal        func_0046d730
    /* 26CD4C 0036CD4C 00000000 */   nop
  .L0036CD50:
    /* 26CD50 0036CD50 2D100002 */  daddu      $2, $16, $0
    /* 26CD54 0036CD54 1000BFDF */  ld         $31, 0x10($29)
    /* 26CD58 0036CD58 0000B07B */  lq         $16, 0x0($29)
    /* 26CD5C 0036CD5C 2000BD27 */  addiu      $29, $29, 0x20
    /* 26CD60 0036CD60 0800E003 */  jr         $31
    /* 26CD64 0036CD64 00000000 */   nop
    /* 26CD68 0036CD68 00000000 */  nop
    /* 26CD6C 0036CD6C 00000000 */  nop
.size func_0036ccc0, 0xb0
