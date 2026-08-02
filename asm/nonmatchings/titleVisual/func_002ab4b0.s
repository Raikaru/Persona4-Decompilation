.section .text
.set noat
.set noreorder
glabel func_002ab4b0
    /* 1AB4B0 002AB4B0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 1AB4B4 002AB4B4 3000BFFF */  sd         $31, 0x30($29)
    /* 1AB4B8 002AB4B8 2000B27F */  sq         $18, 0x20($29)
    /* 1AB4BC 002AB4BC 1000B17F */  sq         $17, 0x10($29)
    /* 1AB4C0 002AB4C0 0000B07F */  sq         $16, 0x0($29)
    /* 1AB4C4 002AB4C4 2D80A000 */  daddu      $16, $5, $0
    /* 1AB4C8 002AB4C8 0000A38C */  lw         $3, 0x0($5)
    /* 1AB4CC 002AB4CC 02160300 */  srl        $2, $3, 24
    /* 1AB4D0 002AB4D0 4C00A2A3 */  sb         $2, 0x4C($29)
    /* 1AB4D4 002AB4D4 02140300 */  srl        $2, $3, 16
    /* 1AB4D8 002AB4D8 4D00A2A3 */  sb         $2, 0x4D($29)
    /* 1AB4DC 002AB4DC 02120300 */  srl        $2, $3, 8
    /* 1AB4E0 002AB4E0 4E00A2A3 */  sb         $2, 0x4E($29)
    /* 1AB4E4 002AB4E4 4F00A3A3 */  sb         $3, 0x4F($29)
    /* 1AB4E8 002AB4E8 5400B28C */  lw         $18, 0x54($5)
    /* 1AB4EC 002AB4EC D800518E */  lw         $17, 0xD8($18)
    /* 1AB4F0 002AB4F0 5000A28C */  lw         $2, 0x50($5)
    /* 1AB4F4 002AB4F4 D80042AE */  sw         $2, 0xD8($18)
    /* 1AB4F8 002AB4F8 2D204002 */  daddu      $4, $18, $0
    /* 1AB4FC 002AB4FC 10000526 */  addiu      $5, $16, 0x10
    /* 1AB500 002AB500 2D300000 */  daddu      $6, $0, $0
    /* 1AB504 002AB504 70E8110C */  jal        func_0047a1c0
    /* 1AB508 002AB508 00000000 */   nop
    /* 1AB50C 002AB50C 2D204002 */  daddu      $4, $18, $0
    /* 1AB510 002AB510 4C00A527 */  addiu      $5, $29, 0x4C
    /* 1AB514 002AB514 54AD0A0C */  jal        func_002ab550
    /* 1AB518 002AB518 00000000 */   nop
    /* 1AB51C 002AB51C D80051AE */  sw         $17, 0xD8($18)
    /* 1AB520 002AB520 2D200002 */  daddu      $4, $16, $0
    /* 1AB524 002AB524 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 1AB528 002AB528 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 1AB52C 002AB52C 09F84000 */  jalr       $2
    /* 1AB530 002AB530 00000000 */   nop
    /* 1AB534 002AB534 3000BFDF */  ld         $31, 0x30($29)
    /* 1AB538 002AB538 2000B27B */  lq         $18, 0x20($29)
    /* 1AB53C 002AB53C 1000B17B */  lq         $17, 0x10($29)
    /* 1AB540 002AB540 0000B07B */  lq         $16, 0x0($29)
    /* 1AB544 002AB544 5000BD27 */  addiu      $29, $29, 0x50
    /* 1AB548 002AB548 0800E003 */  jr         $31
    /* 1AB54C 002AB54C 00000000 */   nop
.size func_002ab4b0, 0xa0
