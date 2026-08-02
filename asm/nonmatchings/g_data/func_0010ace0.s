.section .text
.set noat
.set noreorder
glabel func_0010ace0
    /* ACE0 0010ACE0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* ACE4 0010ACE4 1000BFFF */  sd         $31, 0x10($29)
    /* ACE8 0010ACE8 0000B07F */  sq         $16, 0x0($29)
    /* ACEC 0010ACEC 3C840400 */  dsll32     $16, $4, 16
    /* ACF0 0010ACF0 3F841000 */  dsra32     $16, $16, 16
    /* ACF4 0010ACF4 07000006 */  bltz       $16, .L0010AD14
    /* ACF8 0010ACF8 00000000 */   nop
    /* ACFC 0010ACFC 6C2D040C */  jal        func_0010b5b0
    /* AD00 0010AD00 00000000 */   nop
    /* AD04 0010AD04 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* AD08 0010AD08 2A100202 */  slt        $2, $16, $2
    /* AD0C 0010AD0C 06004014 */  bnez       $2, .L0010AD28
    /* AD10 0010AD10 00000000 */   nop
  .L0010AD14:
    /* AD14 0010AD14 5E00043C */  lui        $4, %hi(D_005E4318)
    /* AD18 0010AD18 18438424 */  addiu      $4, $4, %lo(D_005E4318)
    /* AD1C 0010AD1C FE030524 */  addiu      $5, $0, 0x3FE
    /* AD20 0010AD20 CCB5110C */  jal        func_0046d730
    /* AD24 0010AD24 00000000 */   nop
  .L0010AD28:
    /* AD28 0010AD28 40101000 */  sll        $2, $16, 1
    /* AD2C 0010AD2C 21105000 */  addu       $2, $2, $16
    /* AD30 0010AD30 00190200 */  sll        $3, $2, 4
    /* AD34 0010AD34 7900023C */  lui        $2, %hi(D_00797F8C)
    /* AD38 0010AD38 8C7F4224 */  addiu      $2, $2, %lo(D_00797F8C)
    /* AD3C 0010AD3C 21104300 */  addu       $2, $2, $3
    /* AD40 0010AD40 00004294 */  lhu        $2, 0x0($2)
    /* AD44 0010AD44 01004230 */  andi       $2, $2, 0x1
    /* AD48 0010AD48 04004014 */  bnez       $2, .L0010AD5C
    /* AD4C 0010AD4C 00000000 */   nop
    /* AD50 0010AD50 2D100000 */  daddu      $2, $0, $0
    /* AD54 0010AD54 05000010 */  b          .L0010AD6C
    /* AD58 0010AD58 00000000 */   nop
  .L0010AD5C:
    /* AD5C 0010AD5C 7900023C */  lui        $2, %hi(D_007973A0)
    /* AD60 0010AD60 A0734224 */  addiu      $2, $2, %lo(D_007973A0)
    /* AD64 0010AD64 21104300 */  addu       $2, $2, $3
    /* AD68 0010AD68 EC0B4224 */  addiu      $2, $2, 0xBEC
  .L0010AD6C:
    /* AD6C 0010AD6C 1000BFDF */  ld         $31, 0x10($29)
    /* AD70 0010AD70 0000B07B */  lq         $16, 0x0($29)
    /* AD74 0010AD74 2000BD27 */  addiu      $29, $29, 0x20
    /* AD78 0010AD78 0800E003 */  jr         $31
    /* AD7C 0010AD7C 00000000 */   nop
.size func_0010ace0, 0xa0
