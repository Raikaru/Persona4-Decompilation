.section .text
.set noat
.set noreorder
glabel func_003bf360
    /* 2BF360 003BF360 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2BF364 003BF364 2000BFFF */  sd         $31, 0x20($29)
    /* 2BF368 003BF368 1000B17F */  sq         $17, 0x10($29)
    /* 2BF36C 003BF36C 0000B07F */  sq         $16, 0x0($29)
    /* 2BF370 003BF370 2D888000 */  daddu      $17, $4, $0
    /* 2BF374 003BF374 0000A28C */  lw         $2, 0x0($5)
    /* 2BF378 003BF378 7100043C */  lui        $4, %hi(D_0070AF70)
    /* 2BF37C 003BF37C 2D80A000 */  daddu      $16, $5, $0
    /* 2BF380 003BF380 70AF8424 */  addiu      $4, $4, %lo(D_0070AF70)
    /* 2BF384 003BF384 0C004224 */  addiu      $2, $2, 0xC
    /* 2BF388 003BF388 0000A2AC */  sw         $2, 0x0($5)
    /* 2BF38C 003BF38C 0000A28C */  lw         $2, 0x0($5)
    /* 2BF390 003BF390 1C004224 */  addiu      $2, $2, 0x1C
    /* 2BF394 003BF394 0000A2AC */  sw         $2, 0x0($5)
    /* 2BF398 003BF398 DC8C0F0C */  jal        func_003e3370
    /* 2BF39C 003BF39C 2D282002 */   daddu     $5, $17, $0
    /* 2BF3A0 003BF3A0 0000038E */  lw         $3, 0x0($16)
    /* 2BF3A4 003BF3A4 0C004424 */  addiu      $4, $2, 0xC
    /* 2BF3A8 003BF3A8 2D102002 */  daddu      $2, $17, $0
    /* 2BF3AC 003BF3AC 21186400 */  addu       $3, $3, $4
    /* 2BF3B0 003BF3B0 000003AE */  sw         $3, 0x0($16)
    /* 2BF3B4 003BF3B4 2000BFDF */  ld         $31, 0x20($29)
    /* 2BF3B8 003BF3B8 1000B17B */  lq         $17, 0x10($29)
    /* 2BF3BC 003BF3BC 0000B07B */  lq         $16, 0x0($29)
    /* 2BF3C0 003BF3C0 0800E003 */  jr         $31
    /* 2BF3C4 003BF3C4 3000BD27 */   addiu     $29, $29, 0x30
    /* 2BF3C8 003BF3C8 00000000 */  nop
    /* 2BF3CC 003BF3CC 00000000 */  nop
.size func_003bf360, 0x70
