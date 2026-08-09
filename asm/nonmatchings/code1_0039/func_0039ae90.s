.section .text
.set noat
.set noreorder
glabel func_0039ae90
    /* 29AE90 0039AE90 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 29AE94 0039AE94 4000BFFF */  sd         $31, 0x40($29)
    /* 29AE98 0039AE98 3000B37F */  sq         $19, 0x30($29)
    /* 29AE9C 0039AE9C 2000B27F */  sq         $18, 0x20($29)
    /* 29AEA0 0039AEA0 2D988000 */  daddu      $19, $4, $0
    /* 29AEA4 0039AEA4 1000B17F */  sq         $17, 0x10($29)
    /* 29AEA8 0039AEA8 0000B07F */  sq         $16, 0x0($29)
    /* 29AEAC 0039AEAC F0B5828F */  lw         $2, -0x4A10($28)
    /* 29AEB0 0039AEB0 2180A200 */  addu       $16, $5, $2
    /* 29AEB4 0039AEB4 0000048E */  lw         $4, 0x0($16)
    /* 29AEB8 0039AEB8 0300801C */  bgtz       $4, .L0039AEC8
    /* 29AEBC 0039AEBC 21886202 */   addu      $17, $19, $2
  .L0039AEC0:
    /* 29AEC0 0039AEC0 18000010 */  b          .L0039AF24
    /* 29AEC4 0039AEC4 2D106002 */   daddu     $2, $19, $0
  .L0039AEC8:
    /* 29AEC8 0039AEC8 0300023C */  lui        $2, (0x30105 >> 16)
    /* 29AECC 0039AECC 80180400 */  sll        $3, $4, 2
    /* 29AED0 0039AED0 05014534 */  ori        $5, $2, (0x30105 & 0xFFFF)
    /* 29AED4 0039AED4 21186400 */  addu       $3, $3, $4
    /* 29AED8 0039AED8 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 29AEDC 0039AEDC 80900300 */  sll        $18, $3, 2
    /* 29AEE0 0039AEE0 E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 29AEE4 0039AEE4 09F84000 */  jalr       $2
    /* 29AEE8 0039AEE8 2D204002 */   daddu     $4, $18, $0
    /* 29AEEC 0039AEEC 080022AE */  sw         $2, 0x8($17)
    /* 29AEF0 0039AEF0 0800228E */  lw         $2, 0x8($17)
    /* 29AEF4 0039AEF4 03004014 */  bnez       $2, .L0039AF04
    /* 29AEF8 0039AEF8 00000000 */   nop
    /* 29AEFC 0039AEFC 09000010 */  b          .L0039AF24
    /* 29AF00 0039AF00 2D100000 */   daddu     $2, $0, $0
  .L0039AF04:
    /* 29AF04 0039AF04 0000028E */  lw         $2, 0x0($16)
    /* 29AF08 0039AF08 0800058E */  lw         $5, 0x8($16)
    /* 29AF0C 0039AF0C 000022AE */  sw         $2, 0x0($17)
    /* 29AF10 0039AF10 0800248E */  lw         $4, 0x8($17)
    /* 29AF14 0039AF14 04FE100C */  jal        func_0043f810
    /* 29AF18 0039AF18 2D304002 */   daddu     $6, $18, $0
    /* 29AF1C 0039AF1C E8FF0010 */  b          .L0039AEC0
    /* 29AF20 0039AF20 00000000 */   nop
  .L0039AF24:
    /* 29AF24 0039AF24 4000BFDF */  ld         $31, 0x40($29)
    /* 29AF28 0039AF28 3000B37B */  lq         $19, 0x30($29)
    /* 29AF2C 0039AF2C 2000B27B */  lq         $18, 0x20($29)
    /* 29AF30 0039AF30 1000B17B */  lq         $17, 0x10($29)
    /* 29AF34 0039AF34 0000B07B */  lq         $16, 0x0($29)
    /* 29AF38 0039AF38 0800E003 */  jr         $31
    /* 29AF3C 0039AF3C 5000BD27 */   addiu     $29, $29, 0x50
.size func_0039ae90, 0xb0
