.section .text
.set noat
.set noreorder
glabel func_003ca270
    /* 2CA270 003CA270 90FFBD27 */  addiu      $29, $29, -0x70
    /* 2CA274 003CA274 6000BFFF */  sd         $31, 0x60($29)
    /* 2CA278 003CA278 5000B57F */  sq         $21, 0x50($29)
    /* 2CA27C 003CA27C 4000B47F */  sq         $20, 0x40($29)
    /* 2CA280 003CA280 2DA88000 */  daddu      $21, $4, $0
    /* 2CA284 003CA284 3000B37F */  sq         $19, 0x30($29)
    /* 2CA288 003CA288 2DA0A000 */  daddu      $20, $5, $0
    /* 2CA28C 003CA28C 2000B27F */  sq         $18, 0x20($29)
    /* 2CA290 003CA290 2D98C000 */  daddu      $19, $6, $0
    /* 2CA294 003CA294 1000B17F */  sq         $17, 0x10($29)
    /* 2CA298 003CA298 0000B07F */  sq         $16, 0x0($29)
    /* 2CA29C 003CA29C 1400908C */  lw         $16, 0x14($4)
    /* 2CA2A0 003CA2A0 2A101000 */  slt        $2, $0, $16
    /* 2CA2A4 003CA2A4 03004014 */  bnez       $2, .L003CA2B4
    /* 2CA2A8 003CA2A8 2D900000 */   daddu     $18, $0, $0
  .L003CA2AC:
    /* 2CA2AC 003CA2AC 11000010 */  b          .L003CA2F4
    /* 2CA2B0 003CA2B0 2D10A002 */   daddu     $2, $21, $0
  .L003CA2B4:
    /* 2CA2B4 003CA2B4 2D880000 */  daddu      $17, $0, $0
  .L003CA2B8:
    /* 2CA2B8 003CA2B8 1000A28E */  lw         $2, 0x10($21)
    /* 2CA2BC 003CA2BC 21105100 */  addu       $2, $2, $17
    /* 2CA2C0 003CA2C0 0000448C */  lw         $4, 0x0($2)
    /* 2CA2C4 003CA2C4 09F88002 */  jalr       $20
    /* 2CA2C8 003CA2C8 2D286002 */   daddu     $5, $19, $0
    /* 2CA2CC 003CA2CC 03004014 */  bnez       $2, .L003CA2DC
    /* 2CA2D0 003CA2D0 00000000 */   nop
    /* 2CA2D4 003CA2D4 07000010 */  b          .L003CA2F4
    /* 2CA2D8 003CA2D8 2D10A002 */   daddu     $2, $21, $0
  .L003CA2DC:
    /* 2CA2DC 003CA2DC 01005226 */  addiu      $18, $18, 0x1
    /* 2CA2E0 003CA2E0 2A105002 */  slt        $2, $18, $16
    /* 2CA2E4 003CA2E4 F4FF4014 */  bnez       $2, .L003CA2B8
    /* 2CA2E8 003CA2E8 04003126 */   addiu     $17, $17, 0x4
    /* 2CA2EC 003CA2EC EFFF0010 */  b          .L003CA2AC
    /* 2CA2F0 003CA2F0 00000000 */   nop
  .L003CA2F4:
    /* 2CA2F4 003CA2F4 6000BFDF */  ld         $31, 0x60($29)
    /* 2CA2F8 003CA2F8 5000B57B */  lq         $21, 0x50($29)
    /* 2CA2FC 003CA2FC 4000B47B */  lq         $20, 0x40($29)
    /* 2CA300 003CA300 3000B37B */  lq         $19, 0x30($29)
    /* 2CA304 003CA304 2000B27B */  lq         $18, 0x20($29)
    /* 2CA308 003CA308 1000B17B */  lq         $17, 0x10($29)
    /* 2CA30C 003CA30C 0000B07B */  lq         $16, 0x0($29)
    /* 2CA310 003CA310 0800E003 */  jr         $31
    /* 2CA314 003CA314 7000BD27 */   addiu     $29, $29, 0x70
    /* 2CA318 003CA318 00000000 */  nop
    /* 2CA31C 003CA31C 00000000 */  nop
.size func_003ca270, 0xb0
