.section .text
.set noat
.set noreorder
glabel func_004ab1c0
    /* 3AB1C0 004AB1C0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3AB1C4 004AB1C4 2000BFFF */  sd         $31, 0x20($29)
    /* 3AB1C8 004AB1C8 1000B17F */  sq         $17, 0x10($29)
    /* 3AB1CC 004AB1CC 0000B07F */  sq         $16, 0x0($29)
    /* 3AB1D0 004AB1D0 2D888000 */  daddu      $17, $4, $0
    /* 3AB1D4 004AB1D4 18008494 */  lhu        $4, 0x18($4)
    /* 3AB1D8 004AB1D8 2400258E */  lw         $5, 0x24($17)
    /* 3AB1DC 004AB1DC B8AB120C */  jal        func_004aaee0
    /* 3AB1E0 004AB1E0 00000000 */   nop
    /* 3AB1E4 004AB1E4 2D804000 */  daddu      $16, $2, $0
    /* 3AB1E8 004AB1E8 2800248E */  lw         $4, 0x28($17)
    /* 3AB1EC 004AB1EC 0E008010 */  beqz       $4, .L004AB228
    /* 3AB1F0 004AB1F0 00000000 */   nop
    /* 3AB1F4 004AB1F4 1800038E */  lw         $3, 0x18($16)
    /* 3AB1F8 004AB1F8 40100300 */  sll        $2, $3, 1
    /* 3AB1FC 004AB1FC 21104300 */  addu       $2, $2, $3
    /* 3AB200 004AB200 C0180200 */  sll        $3, $2, 3
    /* 3AB204 004AB204 7100023C */  lui        $2, %hi(D_007143A0)
    /* 3AB208 004AB208 A0434224 */  addiu      $2, $2, %lo(D_007143A0)
    /* 3AB20C 004AB20C 21104300 */  addu       $2, $2, $3
    /* 3AB210 004AB210 00004280 */  lb         $2, 0x0($2)
    /* 3AB214 004AB214 04004010 */  beqz       $2, .L004AB228
    /* 3AB218 004AB218 00000000 */   nop
    /* 3AB21C 004AB21C C0AE120C */  jal        func_004abb00
    /* 3AB220 004AB220 00000000 */   nop
    /* 3AB224 004AB224 280002AE */  sw         $2, 0x28($16)
  .L004AB228:
    /* 3AB228 004AB228 2D100002 */  daddu      $2, $16, $0
    /* 3AB22C 004AB22C 2000BFDF */  ld         $31, 0x20($29)
    /* 3AB230 004AB230 1000B17B */  lq         $17, 0x10($29)
    /* 3AB234 004AB234 0000B07B */  lq         $16, 0x0($29)
    /* 3AB238 004AB238 3000BD27 */  addiu      $29, $29, 0x30
    /* 3AB23C 004AB23C 0800E003 */  jr         $31
    /* 3AB240 004AB240 00000000 */   nop
    /* 3AB244 004AB244 00000000 */  nop
    /* 3AB248 004AB248 00000000 */  nop
    /* 3AB24C 004AB24C 00000000 */  nop
.size func_004ab1c0, 0x90
