.section .text
.set noat
.set noreorder
glabel func_002b69b0
    /* 1B69B0 002B69B0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 1B69B4 002B69B4 0000BFFF */  sd         $31, 0x0($29)
    /* 1B69B8 002B69B8 1000A5FF */  sd         $5, 0x10($29)
    /* 1B69BC 002B69BC 1800A6FF */  sd         $6, 0x18($29)
    /* 1B69C0 002B69C0 3800828C */  lw         $2, 0x38($4)
    /* 1B69C4 002B69C4 3C4C0900 */  dsll32     $9, $9, 16
    /* 1B69C8 002B69C8 3F4C0900 */  dsra32     $9, $9, 16
    /* 1B69CC 002B69CC 10004424 */  addiu      $4, $2, 0x10
    /* 1B69D0 002B69D0 9CE00A0C */  jal        func_002b8270
    /* 1B69D4 002B69D4 00000000 */   nop
    /* 1B69D8 002B69D8 0000BFDF */  ld         $31, 0x0($29)
    /* 1B69DC 002B69DC 2000BD27 */  addiu      $29, $29, 0x20
    /* 1B69E0 002B69E0 0800E003 */  jr         $31
    /* 1B69E4 002B69E4 00000000 */   nop
    /* 1B69E8 002B69E8 00000000 */  nop
    /* 1B69EC 002B69EC 00000000 */  nop
.size func_002b69b0, 0x40
