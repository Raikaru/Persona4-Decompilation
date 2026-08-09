.section .text
.set noat
.set noreorder
glabel func_004a1ba0
    /* 3A1BA0 004A1BA0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3A1BA4 004A1BA4 1000BFFF */  sd         $31, 0x10($29)
    /* 3A1BA8 004A1BA8 0000B07F */  sq         $16, 0x0($29)
    /* 3A1BAC 004A1BAC 2D808000 */  daddu      $16, $4, $0
    /* 3A1BB0 004A1BB0 3800838C */  lw         $3, 0x38($4)
    /* 3A1BB4 004A1BB4 C0100300 */  sll        $2, $3, 3
    /* 3A1BB8 004A1BB8 23104300 */  subu       $2, $2, $3
    /* 3A1BBC 004A1BBC 80180200 */  sll        $3, $2, 2
    /* 3A1BC0 004A1BC0 7100023C */  lui        $2, %hi(D_00714020)
    /* 3A1BC4 004A1BC4 20404224 */  addiu      $2, $2, %lo(D_00714020)
    /* 3A1BC8 004A1BC8 21104300 */  addu       $2, $2, $3
    /* 3A1BCC 004A1BCC 0000428C */  lw         $2, 0x0($2)
    /* 3A1BD0 004A1BD0 09F84000 */  jalr       $2
    /* 3A1BD4 004A1BD4 00000000 */   nop
    /* 3A1BD8 004A1BD8 3400038E */  lw         $3, 0x34($16)
    /* 3A1BDC 004A1BDC 01006324 */  addiu      $3, $3, 0x1
    /* 3A1BE0 004A1BE0 340003AE */  sw         $3, 0x34($16)
    /* 3A1BE4 004A1BE4 0C006018 */  blez       $3, .L004A1C18
    /* 3A1BE8 004A1BE8 00000000 */   nop
    /* 3A1BEC 004A1BEC 2D200002 */  daddu      $4, $16, $0
    /* 3A1BF0 004A1BF0 3800038E */  lw         $3, 0x38($16)
    /* 3A1BF4 004A1BF4 C0100300 */  sll        $2, $3, 3
    /* 3A1BF8 004A1BF8 23104300 */  subu       $2, $2, $3
    /* 3A1BFC 004A1BFC 80180200 */  sll        $3, $2, 2
    /* 3A1C00 004A1C00 7100023C */  lui        $2, %hi(D_00714024)
    /* 3A1C04 004A1C04 24404224 */  addiu      $2, $2, %lo(D_00714024)
    /* 3A1C08 004A1C08 21104300 */  addu       $2, $2, $3
    /* 3A1C0C 004A1C0C 0000428C */  lw         $2, 0x0($2)
    /* 3A1C10 004A1C10 09F84000 */  jalr       $2
    /* 3A1C14 004A1C14 00000000 */   nop
  .L004A1C18:
    /* 3A1C18 004A1C18 1000BFDF */  ld         $31, 0x10($29)
    /* 3A1C1C 004A1C1C 0000B07B */  lq         $16, 0x0($29)
    /* 3A1C20 004A1C20 2000BD27 */  addiu      $29, $29, 0x20
    /* 3A1C24 004A1C24 0800E003 */  jr         $31
    /* 3A1C28 004A1C28 00000000 */   nop
    /* 3A1C2C 004A1C2C 00000000 */  nop
.size func_004a1ba0, 0x90
