.section .text
.set noat
.set noreorder
glabel func_001f8c20
    /* F8C20 001F8C20 E0FFBD27 */  addiu      $29, $29, -0x20
    /* F8C24 001F8C24 1000BFFF */  sd         $31, 0x10($29)
    /* F8C28 001F8C28 0000B07F */  sq         $16, 0x0($29)
    /* F8C2C 001F8C2C 3000838C */  lw         $3, 0x30($4)
    /* F8C30 001F8C30 A2006290 */  lbu        $2, 0xA2($3)
    /* F8C34 001F8C34 04004010 */  beqz       $2, .L001F8C48
    /* F8C38 001F8C38 00000000 */   nop
    /* F8C3C 001F8C3C FFFF0224 */  addiu      $2, $0, -0x1
    /* F8C40 001F8C40 22000010 */  b          .L001F8CCC
    /* F8C44 001F8C44 00000000 */   nop
  .L001F8C48:
    /* F8C48 001F8C48 ACB3828F */  lw         $2, -0x4C54($28)
    /* F8C4C 001F8C4C 7001428C */  lw         $2, 0x170($2)
    /* F8C50 001F8C50 04004414 */  bne        $2, $4, .L001F8C64
    /* F8C54 001F8C54 00000000 */   nop
    /* F8C58 001F8C58 FFFF0224 */  addiu      $2, $0, -0x1
    /* F8C5C 001F8C5C 1B000010 */  b          .L001F8CCC
    /* F8C60 001F8C60 00000000 */   nop
  .L001F8C64:
    /* F8C64 001F8C64 0E00A010 */  beqz       $5, .L001F8CA0
    /* F8C68 001F8C68 00000000 */   nop
    /* F8C6C 001F8C6C A4006294 */  lhu        $2, 0xA4($3)
    /* F8C70 001F8C70 40180200 */  sll        $3, $2, 1
    /* F8C74 001F8C74 6200023C */  lui        $2, %hi(D_00624FC0)
    /* F8C78 001F8C78 C04F4224 */  addiu      $2, $2, %lo(D_00624FC0)
    /* F8C7C 001F8C7C 21104300 */  addu       $2, $2, $3
    /* F8C80 001F8C80 00004294 */  lhu        $2, 0x0($2)
    /* F8C84 001F8C84 6F005024 */  addiu      $16, $2, 0x6F
    /* F8C88 001F8C88 03000424 */  addiu      $4, $0, 0x3
    /* F8C8C 001F8C8C 5CC7080C */  jal        func_00231d70
    /* F8C90 001F8C90 00000000 */   nop
    /* F8C94 001F8C94 21100202 */  addu       $2, $16, $2
    /* F8C98 001F8C98 0C000010 */  b          .L001F8CCC
    /* F8C9C 001F8C9C 00000000 */   nop
  .L001F8CA0:
    /* F8CA0 001F8CA0 A4006294 */  lhu        $2, 0xA4($3)
    /* F8CA4 001F8CA4 40180200 */  sll        $3, $2, 1
    /* F8CA8 001F8CA8 6200023C */  lui        $2, %hi(D_00624FC0)
    /* F8CAC 001F8CAC C04F4224 */  addiu      $2, $2, %lo(D_00624FC0)
    /* F8CB0 001F8CB0 21104300 */  addu       $2, $2, $3
    /* F8CB4 001F8CB4 00004294 */  lhu        $2, 0x0($2)
    /* F8CB8 001F8CB8 72005024 */  addiu      $16, $2, 0x72
    /* F8CBC 001F8CBC 03000424 */  addiu      $4, $0, 0x3
    /* F8CC0 001F8CC0 5CC7080C */  jal        func_00231d70
    /* F8CC4 001F8CC4 00000000 */   nop
    /* F8CC8 001F8CC8 21100202 */  addu       $2, $16, $2
  .L001F8CCC:
    /* F8CCC 001F8CCC 1000BFDF */  ld         $31, 0x10($29)
    /* F8CD0 001F8CD0 0000B07B */  lq         $16, 0x0($29)
    /* F8CD4 001F8CD4 2000BD27 */  addiu      $29, $29, 0x20
    /* F8CD8 001F8CD8 0800E003 */  jr         $31
    /* F8CDC 001F8CDC 00000000 */   nop
.size func_001f8c20, 0xc0
