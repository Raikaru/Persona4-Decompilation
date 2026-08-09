.section .text
.set noat
.set noreorder
glabel func_003e8a10
    /* 2E8A10 003E8A10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2E8A14 003E8A14 2D408000 */  daddu      $8, $4, $0
    /* 2E8A18 003E8A18 8800043C */  lui        $4, %hi(D_008872F0)
    /* 2E8A1C 003E8A1C 0000BFFF */  sd         $31, 0x0($29)
    /* 2E8A20 003E8A20 F0728424 */  addiu      $4, $4, %lo(D_008872F0)
    /* 2E8A24 003E8A24 07000524 */  addiu      $5, $0, 0x7
    /* 2E8A28 003E8A28 2D300000 */  daddu      $6, $0, $0
    /* 2E8A2C 003E8A2C FCA10F0C */  jal        func_003e87f0
    /* 2E8A30 003E8A30 2D380000 */   daddu     $7, $0, $0
    /* 2E8A34 003E8A34 0000BFDF */  ld         $31, 0x0($29)
    /* 2E8A38 003E8A38 2B100200 */  sltu       $2, $0, $2
    /* 2E8A3C 003E8A3C 0800E003 */  jr         $31
    /* 2E8A40 003E8A40 1000BD27 */   addiu     $29, $29, 0x10
    /* 2E8A44 003E8A44 00000000 */  nop
    /* 2E8A48 003E8A48 00000000 */  nop
    /* 2E8A4C 003E8A4C 00000000 */  nop
.size func_003e8a10, 0x40
