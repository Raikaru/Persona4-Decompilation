.section .text
.set noat
.set noreorder
glabel func_004a5ab0
    /* 3A5AB0 004A5AB0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3A5AB4 004A5AB4 1000BFFF */  sd         $31, 0x10($29)
    /* 3A5AB8 004A5AB8 0000B07F */  sq         $16, 0x0($29)
    /* 3A5ABC 004A5ABC 2D808000 */  daddu      $16, $4, $0
    /* 3A5AC0 004A5AC0 3800838C */  lw         $3, 0x38($4)
    /* 3A5AC4 004A5AC4 C0100300 */  sll        $2, $3, 3
    /* 3A5AC8 004A5AC8 23104300 */  subu       $2, $2, $3
    /* 3A5ACC 004A5ACC 80180200 */  sll        $3, $2, 2
    /* 3A5AD0 004A5AD0 7100023C */  lui        $2, %hi(D_00714140)
    /* 3A5AD4 004A5AD4 40414224 */  addiu      $2, $2, %lo(D_00714140)
    /* 3A5AD8 004A5AD8 21104300 */  addu       $2, $2, $3
    /* 3A5ADC 004A5ADC 0000428C */  lw         $2, 0x0($2)
    /* 3A5AE0 004A5AE0 09F84000 */  jalr       $2
    /* 3A5AE4 004A5AE4 00000000 */   nop
    /* 3A5AE8 004A5AE8 3400038E */  lw         $3, 0x34($16)
    /* 3A5AEC 004A5AEC 01006324 */  addiu      $3, $3, 0x1
    /* 3A5AF0 004A5AF0 340003AE */  sw         $3, 0x34($16)
    /* 3A5AF4 004A5AF4 0C006018 */  blez       $3, .L004A5B28
    /* 3A5AF8 004A5AF8 00000000 */   nop
    /* 3A5AFC 004A5AFC 2D200002 */  daddu      $4, $16, $0
    /* 3A5B00 004A5B00 3800038E */  lw         $3, 0x38($16)
    /* 3A5B04 004A5B04 C0100300 */  sll        $2, $3, 3
    /* 3A5B08 004A5B08 23104300 */  subu       $2, $2, $3
    /* 3A5B0C 004A5B0C 80180200 */  sll        $3, $2, 2
    /* 3A5B10 004A5B10 7100023C */  lui        $2, %hi(D_00714144)
    /* 3A5B14 004A5B14 44414224 */  addiu      $2, $2, %lo(D_00714144)
    /* 3A5B18 004A5B18 21104300 */  addu       $2, $2, $3
    /* 3A5B1C 004A5B1C 0000428C */  lw         $2, 0x0($2)
    /* 3A5B20 004A5B20 09F84000 */  jalr       $2
    /* 3A5B24 004A5B24 00000000 */   nop
  .L004A5B28:
    /* 3A5B28 004A5B28 1000BFDF */  ld         $31, 0x10($29)
    /* 3A5B2C 004A5B2C 0000B07B */  lq         $16, 0x0($29)
    /* 3A5B30 004A5B30 2000BD27 */  addiu      $29, $29, 0x20
    /* 3A5B34 004A5B34 0800E003 */  jr         $31
    /* 3A5B38 004A5B38 00000000 */   nop
    /* 3A5B3C 004A5B3C 00000000 */  nop
.size func_004a5ab0, 0x90
