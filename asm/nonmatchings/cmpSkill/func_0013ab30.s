.section .text
.set noat
.set noreorder
glabel func_0013ab30
    /* 3AB30 0013AB30 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3AB34 0013AB34 3000BFFF */  sd         $31, 0x30($29)
    /* 3AB38 0013AB38 2000B27F */  sq         $18, 0x20($29)
    /* 3AB3C 0013AB3C 1000B17F */  sq         $17, 0x10($29)
    /* 3AB40 0013AB40 0000B07F */  sq         $16, 0x0($29)
    /* 3AB44 0013AB44 2D908000 */  daddu      $18, $4, $0
    /* 3AB48 0013AB48 2D880000 */  daddu      $17, $0, $0
    /* 3AB4C 0013AB4C 0B000010 */  b          .L0013AB7C
    /* 3AB50 0013AB50 00000000 */   nop
  .L0013AB54:
    /* 3AB54 0013AB54 80181100 */  sll        $3, $17, 2
    /* 3AB58 0013AB58 21184302 */  addu       $3, $18, $3
    /* 3AB5C 0013AB5C 44127024 */  addiu      $16, $3, 0x1244
    /* 3AB60 0013AB60 4412648C */  lw         $4, 0x1244($3)
    /* 3AB64 0013AB64 04008010 */  beqz       $4, .L0013AB78
    /* 3AB68 0013AB68 00000000 */   nop
    /* 3AB6C 0013AB6C A0B4110C */  jal        func_0046d280
    /* 3AB70 0013AB70 00000000 */   nop
    /* 3AB74 0013AB74 000000AE */  sw         $0, 0x0($16)
  .L0013AB78:
    /* 3AB78 0013AB78 01003126 */  addiu      $17, $17, 0x1
  .L0013AB7C:
    /* 3AB7C 0013AB7C 3C00232A */  slti       $3, $17, 0x3C
    /* 3AB80 0013AB80 F4FF6014 */  bnez       $3, .L0013AB54
    /* 3AB84 0013AB84 00000000 */   nop
    /* 3AB88 0013AB88 1C0040AE */  sw         $0, 0x1C($18)
    /* 3AB8C 0013AB8C 3000BFDF */  ld         $31, 0x30($29)
    /* 3AB90 0013AB90 2000B27B */  lq         $18, 0x20($29)
    /* 3AB94 0013AB94 1000B17B */  lq         $17, 0x10($29)
    /* 3AB98 0013AB98 0000B07B */  lq         $16, 0x0($29)
    /* 3AB9C 0013AB9C 4000BD27 */  addiu      $29, $29, 0x40
    /* 3ABA0 0013ABA0 0800E003 */  jr         $31
    /* 3ABA4 0013ABA4 00000000 */   nop
    /* 3ABA8 0013ABA8 00000000 */  nop
    /* 3ABAC 0013ABAC 00000000 */  nop
.size func_0013ab30, 0x80
