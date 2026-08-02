.section .text
.set noat
.set noreorder
glabel func_0017e9b0
    /* 7E9B0 0017E9B0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 7E9B4 0017E9B4 1000BFFF */  sd         $31, 0x10($29)
    /* 7E9B8 0017E9B8 0000B07F */  sq         $16, 0x0($29)
    /* 7E9BC 0017E9BC 3800908C */  lw         $16, 0x38($4)
    /* 7E9C0 0017E9C0 1000028E */  lw         $2, 0x10($16)
    /* 7E9C4 0017E9C4 28074494 */  lhu        $4, 0x728($2)
    /* 7E9C8 0017E9C8 40BF050C */  jal        func_0016fd00
    /* 7E9CC 0017E9CC 00000000 */   nop
    /* 7E9D0 0017E9D0 3C340200 */  dsll32     $6, $2, 16
    /* 7E9D4 0017E9D4 3F340600 */  dsra32     $6, $6, 16
    /* 7E9D8 0017E9D8 1000028E */  lw         $2, 0x10($16)
    /* 7E9DC 0017E9DC 5000448C */  lw         $4, 0x50($2)
    /* 7E9E0 0017E9E0 2D280000 */  daddu      $5, $0, $0
    /* 7E9E4 0017E9E4 2D380000 */  daddu      $7, $0, $0
    /* 7E9E8 0017E9E8 01000824 */  addiu      $8, $0, 0x1
    /* 7E9EC 0017E9EC 50E6110C */  jal        func_00479940
    /* 7E9F0 0017E9F0 00000000 */   nop
    /* 7E9F4 0017E9F4 0C0000AE */  sw         $0, 0xC($16)
    /* 7E9F8 0017E9F8 1000BFDF */  ld         $31, 0x10($29)
    /* 7E9FC 0017E9FC 0000B07B */  lq         $16, 0x0($29)
    /* 7EA00 0017EA00 2000BD27 */  addiu      $29, $29, 0x20
    /* 7EA04 0017EA04 0800E003 */  jr         $31
    /* 7EA08 0017EA08 00000000 */   nop
    /* 7EA0C 0017EA0C 00000000 */  nop
.size func_0017e9b0, 0x60
