.section .text
.set noat
.set noreorder
glabel func_004a1aa0
    /* 3A1AA0 004A1AA0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3A1AA4 004A1AA4 1000BFFF */  sd         $31, 0x10($29)
    /* 3A1AA8 004A1AA8 0000B07F */  sq         $16, 0x0($29)
    /* 3A1AAC 004A1AAC 2D808000 */  daddu      $16, $4, $0
    /* 3A1AB0 004A1AB0 3800838C */  lw         $3, 0x38($4)
    /* 3A1AB4 004A1AB4 C0100300 */  sll        $2, $3, 3
    /* 3A1AB8 004A1AB8 23104300 */  subu       $2, $2, $3
    /* 3A1ABC 004A1ABC 80180200 */  sll        $3, $2, 2
    /* 3A1AC0 004A1AC0 7100023C */  lui        $2, %hi(D_00714010)
    /* 3A1AC4 004A1AC4 10404224 */  addiu      $2, $2, %lo(D_00714010)
    /* 3A1AC8 004A1AC8 21104300 */  addu       $2, $2, $3
    /* 3A1ACC 004A1ACC 0000428C */  lw         $2, 0x0($2)
    /* 3A1AD0 004A1AD0 09F84000 */  jalr       $2
    /* 3A1AD4 004A1AD4 00000000 */   nop
    /* 3A1AD8 004A1AD8 340000AE */  sw         $0, 0x34($16)
    /* 3A1ADC 004A1ADC 1000BFDF */  ld         $31, 0x10($29)
    /* 3A1AE0 004A1AE0 0000B07B */  lq         $16, 0x0($29)
    /* 3A1AE4 004A1AE4 2000BD27 */  addiu      $29, $29, 0x20
    /* 3A1AE8 004A1AE8 0800E003 */  jr         $31
    /* 3A1AEC 004A1AEC 00000000 */   nop
.size func_004a1aa0, 0x50
