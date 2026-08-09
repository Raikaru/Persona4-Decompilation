.section .text
.set noat
.set noreorder
glabel func_001dace0
    /* DACE0 001DACE0 90FFBD27 */  addiu      $29, $29, -0x70
    /* DACE4 001DACE4 6000BFFF */  sd         $31, 0x60($29)
    /* DACE8 001DACE8 5000B57F */  sq         $21, 0x50($29)
    /* DACEC 001DACEC 4000B47F */  sq         $20, 0x40($29)
    /* DACF0 001DACF0 3000B37F */  sq         $19, 0x30($29)
    /* DACF4 001DACF4 2000B27F */  sq         $18, 0x20($29)
    /* DACF8 001DACF8 1000B17F */  sq         $17, 0x10($29)
    /* DACFC 001DACFC 0000B07F */  sq         $16, 0x0($29)
    /* DAD00 001DAD00 2D80A000 */  daddu      $16, $5, $0
    /* DAD04 001DAD04 3000828C */  lw         $2, 0x30($4)
    /* DAD08 001DAD08 A2004390 */  lbu        $3, 0xA2($2)
    /* DAD0C 001DAD0C 01000224 */  addiu      $2, $0, 0x1
    /* DAD10 001DAD10 04106200 */  sllv       $2, $2, $3
    /* DAD14 001DAD14 FFFF5230 */  andi       $18, $2, 0xFFFF
    /* DAD18 001DAD18 2DA00000 */  daddu      $20, $0, $0
    /* DAD1C 001DAD1C 2D980000 */  daddu      $19, $0, $0
    /* DAD20 001DAD20 ACB3828F */  lw         $2, -0x4C54($28)
    /* DAD24 001DAD24 7401558C */  lw         $21, 0x174($2)
    /* DAD28 001DAD28 20000010 */  b          .L001DADAC
    /* DAD2C 001DAD2C 00000000 */   nop
  .L001DAD30:
    /* DAD30 001DAD30 1A00A396 */  lhu        $3, 0x1A($21)
    /* DAD34 001DAD34 01006230 */  andi       $2, $3, 0x1
    /* DAD38 001DAD38 1B004010 */  beqz       $2, .L001DADA8
    /* DAD3C 001DAD3C 00000000 */   nop
    /* DAD40 001DAD40 08006230 */  andi       $2, $3, 0x8
    /* DAD44 001DAD44 18004010 */  beqz       $2, .L001DADA8
    /* DAD48 001DAD48 00000000 */   nop
    /* DAD4C 001DAD4C 3000B18E */  lw         $17, 0x30($21)
    /* DAD50 001DAD50 A2002392 */  lbu        $3, 0xA2($17)
    /* DAD54 001DAD54 01000224 */  addiu      $2, $0, 0x1
    /* DAD58 001DAD58 04106200 */  sllv       $2, $2, $3
    /* DAD5C 001DAD5C 24104202 */  and        $2, $18, $2
    /* DAD60 001DAD60 11004010 */  beqz       $2, .L001DADA8
    /* DAD64 001DAD64 00000000 */   nop
    /* DAD68 001DAD68 640A248E */  lw         $4, 0xA64($17)
    /* DAD6C 001DAD6C 2D280000 */  daddu      $5, $0, $0
    /* DAD70 001DAD70 3C0A090C */  jal        func_002428f0
    /* DAD74 001DAD74 00000000 */   nop
    /* DAD78 001DAD78 0B004014 */  bnez       $2, .L001DADA8
    /* DAD7C 001DAD7C 00000000 */   nop
    /* DAD80 001DAD80 640A248E */  lw         $4, 0xA64($17)
    /* DAD84 001DAD84 B4C7080C */  jal        func_00231ed0
    /* DAD88 001DAD88 00000000 */   nop
    /* DAD8C 001DAD8C FFFF4230 */  andi       $2, $2, 0xFFFF
    /* DAD90 001DAD90 21A08202 */  addu       $20, $20, $2
    /* DAD94 001DAD94 640A248E */  lw         $4, 0xA64($17)
    /* DAD98 001DAD98 E0C7080C */  jal        func_00231f80
    /* DAD9C 001DAD9C 00000000 */   nop
    /* DADA0 001DADA0 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* DADA4 001DADA4 21986202 */  addu       $19, $19, $2
  .L001DADA8:
    /* DADA8 001DADA8 5004B58E */  lw         $21, 0x450($21)
  .L001DADAC:
    /* DADAC 001DADAC E0FFA016 */  bnez       $21, .L001DAD30
    /* DADB0 001DADB0 00000000 */   nop
    /* DADB4 001DADB4 80101400 */  sll        $2, $20, 2
    /* DADB8 001DADB8 21185400 */  addu       $3, $2, $20
    /* DADBC 001DADBC 80100300 */  sll        $2, $3, 2
    /* DADC0 001DADC0 21106200 */  addu       $2, $3, $2
    /* DADC4 001DADC4 80180200 */  sll        $3, $2, 2
    /* DADC8 001DADC8 18107002 */  mult       $2, $19, $16
    /* DADCC 001DADCC 2B104300 */  sltu       $2, $2, $3
    /* DADD0 001DADD0 01004238 */  xori       $2, $2, 0x1
    /* DADD4 001DADD4 6000BFDF */  ld         $31, 0x60($29)
    /* DADD8 001DADD8 5000B57B */  lq         $21, 0x50($29)
    /* DADDC 001DADDC 4000B47B */  lq         $20, 0x40($29)
    /* DADE0 001DADE0 3000B37B */  lq         $19, 0x30($29)
    /* DADE4 001DADE4 2000B27B */  lq         $18, 0x20($29)
    /* DADE8 001DADE8 1000B17B */  lq         $17, 0x10($29)
    /* DADEC 001DADEC 0000B07B */  lq         $16, 0x0($29)
    /* DADF0 001DADF0 7000BD27 */  addiu      $29, $29, 0x70
    /* DADF4 001DADF4 0800E003 */  jr         $31
    /* DADF8 001DADF8 00000000 */   nop
    /* DADFC 001DADFC 00000000 */  nop
.size func_001dace0, 0x120
