.section .text
.set noat
.set noreorder
glabel func_001dae00
    /* DAE00 001DAE00 90FFBD27 */  addiu      $29, $29, -0x70
    /* DAE04 001DAE04 6000BFFF */  sd         $31, 0x60($29)
    /* DAE08 001DAE08 5000B57F */  sq         $21, 0x50($29)
    /* DAE0C 001DAE0C 4000B47F */  sq         $20, 0x40($29)
    /* DAE10 001DAE10 3000B37F */  sq         $19, 0x30($29)
    /* DAE14 001DAE14 2000B27F */  sq         $18, 0x20($29)
    /* DAE18 001DAE18 1000B17F */  sq         $17, 0x10($29)
    /* DAE1C 001DAE1C 0000B07F */  sq         $16, 0x0($29)
    /* DAE20 001DAE20 2D80A000 */  daddu      $16, $5, $0
    /* DAE24 001DAE24 3000828C */  lw         $2, 0x30($4)
    /* DAE28 001DAE28 A2004290 */  lbu        $2, 0xA2($2)
    /* DAE2C 001DAE2C 04004014 */  bnez       $2, .L001DAE40
    /* DAE30 001DAE30 00000000 */   nop
    /* DAE34 001DAE34 01000224 */  addiu      $2, $0, 0x1
    /* DAE38 001DAE38 02000010 */  b          .L001DAE44
    /* DAE3C 001DAE3C 00000000 */   nop
  .L001DAE40:
    /* DAE40 001DAE40 2D100000 */  daddu      $2, $0, $0
  .L001DAE44:
    /* DAE44 001DAE44 FFFF4330 */  andi       $3, $2, 0xFFFF
    /* DAE48 001DAE48 01000224 */  addiu      $2, $0, 0x1
    /* DAE4C 001DAE4C 04106200 */  sllv       $2, $2, $3
    /* DAE50 001DAE50 FFFF5230 */  andi       $18, $2, 0xFFFF
    /* DAE54 001DAE54 2DA00000 */  daddu      $20, $0, $0
    /* DAE58 001DAE58 2D980000 */  daddu      $19, $0, $0
    /* DAE5C 001DAE5C ACB3828F */  lw         $2, -0x4C54($28)
    /* DAE60 001DAE60 7401558C */  lw         $21, 0x174($2)
    /* DAE64 001DAE64 20000010 */  b          .L001DAEE8
    /* DAE68 001DAE68 00000000 */   nop
  .L001DAE6C:
    /* DAE6C 001DAE6C 1A00A396 */  lhu        $3, 0x1A($21)
    /* DAE70 001DAE70 01006230 */  andi       $2, $3, 0x1
    /* DAE74 001DAE74 1B004010 */  beqz       $2, .L001DAEE4
    /* DAE78 001DAE78 00000000 */   nop
    /* DAE7C 001DAE7C 08006230 */  andi       $2, $3, 0x8
    /* DAE80 001DAE80 18004010 */  beqz       $2, .L001DAEE4
    /* DAE84 001DAE84 00000000 */   nop
    /* DAE88 001DAE88 3000B18E */  lw         $17, 0x30($21)
    /* DAE8C 001DAE8C A2002392 */  lbu        $3, 0xA2($17)
    /* DAE90 001DAE90 01000224 */  addiu      $2, $0, 0x1
    /* DAE94 001DAE94 04106200 */  sllv       $2, $2, $3
    /* DAE98 001DAE98 24104202 */  and        $2, $18, $2
    /* DAE9C 001DAE9C 11004010 */  beqz       $2, .L001DAEE4
    /* DAEA0 001DAEA0 00000000 */   nop
    /* DAEA4 001DAEA4 640A248E */  lw         $4, 0xA64($17)
    /* DAEA8 001DAEA8 2D280000 */  daddu      $5, $0, $0
    /* DAEAC 001DAEAC 3C0A090C */  jal        func_002428f0
    /* DAEB0 001DAEB0 00000000 */   nop
    /* DAEB4 001DAEB4 0B004014 */  bnez       $2, .L001DAEE4
    /* DAEB8 001DAEB8 00000000 */   nop
    /* DAEBC 001DAEBC 640A248E */  lw         $4, 0xA64($17)
    /* DAEC0 001DAEC0 B4C7080C */  jal        func_00231ed0
    /* DAEC4 001DAEC4 00000000 */   nop
    /* DAEC8 001DAEC8 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* DAECC 001DAECC 21A08202 */  addu       $20, $20, $2
    /* DAED0 001DAED0 640A248E */  lw         $4, 0xA64($17)
    /* DAED4 001DAED4 E0C7080C */  jal        func_00231f80
    /* DAED8 001DAED8 00000000 */   nop
    /* DAEDC 001DAEDC FFFF4230 */  andi       $2, $2, 0xFFFF
    /* DAEE0 001DAEE0 21986202 */  addu       $19, $19, $2
  .L001DAEE4:
    /* DAEE4 001DAEE4 5004B58E */  lw         $21, 0x450($21)
  .L001DAEE8:
    /* DAEE8 001DAEE8 E0FFA016 */  bnez       $21, .L001DAE6C
    /* DAEEC 001DAEEC 00000000 */   nop
    /* DAEF0 001DAEF0 80101400 */  sll        $2, $20, 2
    /* DAEF4 001DAEF4 21185400 */  addu       $3, $2, $20
    /* DAEF8 001DAEF8 80100300 */  sll        $2, $3, 2
    /* DAEFC 001DAEFC 21106200 */  addu       $2, $3, $2
    /* DAF00 001DAF00 80180200 */  sll        $3, $2, 2
    /* DAF04 001DAF04 18107002 */  mult       $2, $19, $16
    /* DAF08 001DAF08 2B104300 */  sltu       $2, $2, $3
    /* DAF0C 001DAF0C 01004238 */  xori       $2, $2, 0x1
    /* DAF10 001DAF10 6000BFDF */  ld         $31, 0x60($29)
    /* DAF14 001DAF14 5000B57B */  lq         $21, 0x50($29)
    /* DAF18 001DAF18 4000B47B */  lq         $20, 0x40($29)
    /* DAF1C 001DAF1C 3000B37B */  lq         $19, 0x30($29)
    /* DAF20 001DAF20 2000B27B */  lq         $18, 0x20($29)
    /* DAF24 001DAF24 1000B17B */  lq         $17, 0x10($29)
    /* DAF28 001DAF28 0000B07B */  lq         $16, 0x0($29)
    /* DAF2C 001DAF2C 7000BD27 */  addiu      $29, $29, 0x70
    /* DAF30 001DAF30 0800E003 */  jr         $31
    /* DAF34 001DAF34 00000000 */   nop
    /* DAF38 001DAF38 00000000 */  nop
    /* DAF3C 001DAF3C 00000000 */  nop
.size func_001dae00, 0x140
