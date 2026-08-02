.section .text
.set noat
.set noreorder
glabel func_004ab7a0
    /* 3AB7A0 004AB7A0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3AB7A4 004AB7A4 1000BFFF */  sd         $31, 0x10($29)
    /* 3AB7A8 004AB7A8 0000B07F */  sq         $16, 0x0($29)
    /* 3AB7AC 004AB7AC 2D808000 */  daddu      $16, $4, $0
    /* 3AB7B0 004AB7B0 1800838C */  lw         $3, 0x18($4)
    /* 3AB7B4 004AB7B4 40100300 */  sll        $2, $3, 1
    /* 3AB7B8 004AB7B8 21104300 */  addu       $2, $2, $3
    /* 3AB7BC 004AB7BC C0180200 */  sll        $3, $2, 3
    /* 3AB7C0 004AB7C0 7100023C */  lui        $2, %hi(D_00714468)
    /* 3AB7C4 004AB7C4 68444224 */  addiu      $2, $2, %lo(D_00714468)
    /* 3AB7C8 004AB7C8 21104300 */  addu       $2, $2, $3
    /* 3AB7CC 004AB7CC 0000428C */  lw         $2, 0x0($2)
    /* 3AB7D0 004AB7D0 09F84000 */  jalr       $2
    /* 3AB7D4 004AB7D4 00000000 */   nop
    /* 3AB7D8 004AB7D8 1C00038E */  lw         $3, 0x1C($16)
    /* 3AB7DC 004AB7DC 01006324 */  addiu      $3, $3, 0x1
    /* 3AB7E0 004AB7E0 1C0003AE */  sw         $3, 0x1C($16)
    /* 3AB7E4 004AB7E4 1000BFDF */  ld         $31, 0x10($29)
    /* 3AB7E8 004AB7E8 0000B07B */  lq         $16, 0x0($29)
    /* 3AB7EC 004AB7EC 2000BD27 */  addiu      $29, $29, 0x20
    /* 3AB7F0 004AB7F0 0800E003 */  jr         $31
    /* 3AB7F4 004AB7F4 00000000 */   nop
    /* 3AB7F8 004AB7F8 00000000 */  nop
    /* 3AB7FC 004AB7FC 00000000 */  nop
.size func_004ab7a0, 0x60
