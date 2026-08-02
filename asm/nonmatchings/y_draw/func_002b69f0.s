.section .text
.set noat
.set noreorder
glabel func_002b69f0
    /* 1B69F0 002B69F0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 1B69F4 002B69F4 0000BFFF */  sd         $31, 0x0($29)
    /* 1B69F8 002B69F8 1000A5FF */  sd         $5, 0x10($29)
    /* 1B69FC 002B69FC 1800A6FF */  sd         $6, 0x18($29)
    /* 1B6A00 002B6A00 74B5828F */  lw         $2, -0x4A8C($28)
    /* 1B6A04 002B6A04 3800438C */  lw         $3, 0x38($2)
    /* 1B6A08 002B6A08 3C140400 */  dsll32     $2, $4, 16
    /* 1B6A0C 002B6A0C 3F140200 */  dsra32     $2, $2, 16
    /* 1B6A10 002B6A10 00120200 */  sll        $2, $2, 8
    /* 1B6A14 002B6A14 21106200 */  addu       $2, $3, $2
    /* 1B6A18 002B6A18 3C4C0900 */  dsll32     $9, $9, 16
    /* 1B6A1C 002B6A1C 3F4C0900 */  dsra32     $9, $9, 16
    /* 1B6A20 002B6A20 14004424 */  addiu      $4, $2, 0x14
    /* 1B6A24 002B6A24 9CE00A0C */  jal        func_002b8270
    /* 1B6A28 002B6A28 00000000 */   nop
    /* 1B6A2C 002B6A2C 0000BFDF */  ld         $31, 0x0($29)
    /* 1B6A30 002B6A30 2000BD27 */  addiu      $29, $29, 0x20
    /* 1B6A34 002B6A34 0800E003 */  jr         $31
    /* 1B6A38 002B6A38 00000000 */   nop
    /* 1B6A3C 002B6A3C 00000000 */  nop
.size func_002b69f0, 0x50
