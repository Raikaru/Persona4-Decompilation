.section .text
.set noat
.set noreorder
glabel func_001b69c0
    /* B69C0 001B69C0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* B69C4 001B69C4 0000BFFF */  sd         $31, 0x0($29)
    /* B69C8 001B69C8 ACB3828F */  lw         $2, -0x4C54($28)
    /* B69CC 001B69CC 780E40AC */  sw         $0, 0xE78($2)
    /* B69D0 001B69D0 ACB3848F */  lw         $4, -0x4C54($28)
    /* B69D4 001B69D4 0C00838C */  lw         $3, 0xC($4)
    /* B69D8 001B69D8 FDFF0224 */  addiu      $2, $0, -0x3
    /* B69DC 001B69DC 24106200 */  and        $2, $3, $2
    /* B69E0 001B69E0 0C0082AC */  sw         $2, 0xC($4)
    /* B69E4 001B69E4 2014050C */  jal        func_00145080
    /* B69E8 001B69E8 00000000 */   nop
    /* B69EC 001B69EC 0000BFDF */  ld         $31, 0x0($29)
    /* B69F0 001B69F0 1000BD27 */  addiu      $29, $29, 0x10
    /* B69F4 001B69F4 0800E003 */  jr         $31
    /* B69F8 001B69F8 00000000 */   nop
    /* B69FC 001B69FC 00000000 */  nop
.size func_001b69c0, 0x40
