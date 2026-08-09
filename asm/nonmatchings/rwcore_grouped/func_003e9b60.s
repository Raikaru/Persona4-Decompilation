.section .text
.set noat
.set noreorder
glabel func_003e9b60
    /* 2E9B60 003E9B60 90FFBD27 */  addiu      $29, $29, -0x70
    /* 2E9B64 003E9B64 6000BFFF */  sd         $31, 0x60($29)
    /* 2E9B68 003E9B68 5000B57F */  sq         $21, 0x50($29)
    /* 2E9B6C 003E9B6C 4000B47F */  sq         $20, 0x40($29)
    /* 2E9B70 003E9B70 3000B37F */  sq         $19, 0x30($29)
    /* 2E9B74 003E9B74 2000B27F */  sq         $18, 0x20($29)
    /* 2E9B78 003E9B78 1000B17F */  sq         $17, 0x10($29)
    /* 2E9B7C 003E9B7C 0000B07F */  sq         $16, 0x0($29)
    /* 2E9B80 003E9B80 9800958C */  lw         $21, 0x98($4)
    /* 2E9B84 003E9B84 1800A012 */  beqz       $21, .L003E9BE8
    /* 2E9B88 003E9B88 01001424 */   addiu     $20, $0, 0x1
  .L003E9B8C:
    /* 2E9B8C 003E9B8C 9800B38E */  lw         $19, 0x98($21)
    /* 2E9B90 003E9B90 11006012 */  beqz       $19, .L003E9BD8
    /* 2E9B94 003E9B94 01001224 */   addiu     $18, $0, 0x1
  .L003E9B98:
    /* 2E9B98 003E9B98 9800718E */  lw         $17, 0x98($19)
    /* 2E9B9C 003E9B9C 0A002012 */  beqz       $17, .L003E9BC8
    /* 2E9BA0 003E9BA0 01001024 */   addiu     $16, $0, 0x1
    /* 2E9BA4 003E9BA4 00000000 */  nop
  .L003E9BA8:
    /* 2E9BA8 003E9BA8 D8A60F0C */  jal        func_003e9b60
    /* 2E9BAC 003E9BAC 2D202002 */   daddu     $4, $17, $0
    /* 2E9BB0 003E9BB0 9C00318E */  lw         $17, 0x9C($17)
    /* 2E9BB4 003E9BB4 21800202 */  addu       $16, $16, $2
    /* 2E9BB8 003E9BB8 00000000 */  nop
    /* 2E9BBC 003E9BBC FAFF2016 */  bnez       $17, .L003E9BA8
    /* 2E9BC0 003E9BC0 00000000 */   nop
    /* 2E9BC4 003E9BC4 00000000 */  nop
  .L003E9BC8:
    /* 2E9BC8 003E9BC8 9C00738E */  lw         $19, 0x9C($19)
    /* 2E9BCC 003E9BCC F2FF6016 */  bnez       $19, .L003E9B98
    /* 2E9BD0 003E9BD0 21905002 */   addu      $18, $18, $16
    /* 2E9BD4 003E9BD4 00000000 */  nop
  .L003E9BD8:
    /* 2E9BD8 003E9BD8 9C00B58E */  lw         $21, 0x9C($21)
    /* 2E9BDC 003E9BDC EBFFA016 */  bnez       $21, .L003E9B8C
    /* 2E9BE0 003E9BE0 21A09202 */   addu      $20, $20, $18
    /* 2E9BE4 003E9BE4 00000000 */  nop
  .L003E9BE8:
    /* 2E9BE8 003E9BE8 2D108002 */  daddu      $2, $20, $0
    /* 2E9BEC 003E9BEC 6000BFDF */  ld         $31, 0x60($29)
    /* 2E9BF0 003E9BF0 5000B57B */  lq         $21, 0x50($29)
    /* 2E9BF4 003E9BF4 4000B47B */  lq         $20, 0x40($29)
    /* 2E9BF8 003E9BF8 3000B37B */  lq         $19, 0x30($29)
    /* 2E9BFC 003E9BFC 2000B27B */  lq         $18, 0x20($29)
    /* 2E9C00 003E9C00 1000B17B */  lq         $17, 0x10($29)
    /* 2E9C04 003E9C04 0000B07B */  lq         $16, 0x0($29)
    /* 2E9C08 003E9C08 0800E003 */  jr         $31
    /* 2E9C0C 003E9C0C 7000BD27 */   addiu     $29, $29, 0x70
.size func_003e9b60, 0xb0
