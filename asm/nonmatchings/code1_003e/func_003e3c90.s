.section .text
.set noat
.set noreorder
glabel func_003e3c90
    /* 2E3C90 003E3C90 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 2E3C94 003E3C94 4000BFFF */  sd         $31, 0x40($29)
    /* 2E3C98 003E3C98 3000B37F */  sq         $19, 0x30($29)
    /* 2E3C9C 003E3C9C 2000B27F */  sq         $18, 0x20($29)
    /* 2E3CA0 003E3CA0 2D988000 */  daddu      $19, $4, $0
    /* 2E3CA4 003E3CA4 1000B17F */  sq         $17, 0x10($29)
    /* 2E3CA8 003E3CA8 2D90A000 */  daddu      $18, $5, $0
    /* 2E3CAC 003E3CAC 0000B07F */  sq         $16, 0x0($29)
    /* 2E3CB0 003E3CB0 1000908C */  lw         $16, 0x10($4)
    /* 2E3CB4 003E3CB4 0A000012 */  beqz       $16, .L003E3CE0
    /* 2E3CB8 003E3CB8 2D88C000 */   daddu     $17, $6, $0
  .L003E3CBC:
    /* 2E3CBC 003E3CBC 0000068E */  lw         $6, 0x0($16)
    /* 2E3CC0 003E3CC0 2D204002 */  daddu      $4, $18, $0
    /* 2E3CC4 003E3CC4 0400078E */  lw         $7, 0x4($16)
    /* 2E3CC8 003E3CC8 2800028E */  lw         $2, 0x28($16)
    /* 2E3CCC 003E3CCC 09F84000 */  jalr       $2
    /* 2E3CD0 003E3CD0 2D282002 */   daddu     $5, $17, $0
    /* 2E3CD4 003E3CD4 3000108E */  lw         $16, 0x30($16)
    /* 2E3CD8 003E3CD8 F8FF0016 */  bnez       $16, .L003E3CBC
    /* 2E3CDC 003E3CDC 00000000 */   nop
  .L003E3CE0:
    /* 2E3CE0 003E3CE0 2D106002 */  daddu      $2, $19, $0
    /* 2E3CE4 003E3CE4 4000BFDF */  ld         $31, 0x40($29)
    /* 2E3CE8 003E3CE8 3000B37B */  lq         $19, 0x30($29)
    /* 2E3CEC 003E3CEC 2000B27B */  lq         $18, 0x20($29)
    /* 2E3CF0 003E3CF0 1000B17B */  lq         $17, 0x10($29)
    /* 2E3CF4 003E3CF4 0000B07B */  lq         $16, 0x0($29)
    /* 2E3CF8 003E3CF8 0800E003 */  jr         $31
    /* 2E3CFC 003E3CFC 5000BD27 */   addiu     $29, $29, 0x50
.size func_003e3c90, 0x70
