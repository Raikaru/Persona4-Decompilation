.section .text
.set noat
.set noreorder
glabel func_001f8b90
    /* F8B90 001F8B90 E0FFBD27 */  addiu      $29, $29, -0x20
    /* F8B94 001F8B94 1000BFFF */  sd         $31, 0x10($29)
    /* F8B98 001F8B98 0000B07F */  sq         $16, 0x0($29)
    /* F8B9C 001F8B9C 3000838C */  lw         $3, 0x30($4)
    /* F8BA0 001F8BA0 A2006290 */  lbu        $2, 0xA2($3)
    /* F8BA4 001F8BA4 04004010 */  beqz       $2, .L001F8BB8
    /* F8BA8 001F8BA8 00000000 */   nop
    /* F8BAC 001F8BAC FFFF0224 */  addiu      $2, $0, -0x1
    /* F8BB0 001F8BB0 13000010 */  b          .L001F8C00
    /* F8BB4 001F8BB4 00000000 */   nop
  .L001F8BB8:
    /* F8BB8 001F8BB8 ACB3828F */  lw         $2, -0x4C54($28)
    /* F8BBC 001F8BBC 7001428C */  lw         $2, 0x170($2)
    /* F8BC0 001F8BC0 04004414 */  bne        $2, $4, .L001F8BD4
    /* F8BC4 001F8BC4 00000000 */   nop
    /* F8BC8 001F8BC8 FFFF0224 */  addiu      $2, $0, -0x1
    /* F8BCC 001F8BCC 0C000010 */  b          .L001F8C00
    /* F8BD0 001F8BD0 00000000 */   nop
  .L001F8BD4:
    /* F8BD4 001F8BD4 A4006294 */  lhu        $2, 0xA4($3)
    /* F8BD8 001F8BD8 40180200 */  sll        $3, $2, 1
    /* F8BDC 001F8BDC 6200023C */  lui        $2, %hi(D_00624FC0)
    /* F8BE0 001F8BE0 C04F4224 */  addiu      $2, $2, %lo(D_00624FC0)
    /* F8BE4 001F8BE4 21104300 */  addu       $2, $2, $3
    /* F8BE8 001F8BE8 00004294 */  lhu        $2, 0x0($2)
    /* F8BEC 001F8BEC 63005024 */  addiu      $16, $2, 0x63
    /* F8BF0 001F8BF0 03000424 */  addiu      $4, $0, 0x3
    /* F8BF4 001F8BF4 5CC7080C */  jal        func_00231d70
    /* F8BF8 001F8BF8 00000000 */   nop
    /* F8BFC 001F8BFC 21100202 */  addu       $2, $16, $2
  .L001F8C00:
    /* F8C00 001F8C00 1000BFDF */  ld         $31, 0x10($29)
    /* F8C04 001F8C04 0000B07B */  lq         $16, 0x0($29)
    /* F8C08 001F8C08 2000BD27 */  addiu      $29, $29, 0x20
    /* F8C0C 001F8C0C 0800E003 */  jr         $31
    /* F8C10 001F8C10 00000000 */   nop
    /* F8C14 001F8C14 00000000 */  nop
    /* F8C18 001F8C18 00000000 */  nop
    /* F8C1C 001F8C1C 00000000 */  nop
.size func_001f8b90, 0x90
