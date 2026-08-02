.section .text
.set noat
.set noreorder
glabel func_0014eed0
    /* 4EED0 0014EED0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 4EED4 0014EED4 0000BFFF */  sd         $31, 0x0($29)
    /* 4EED8 0014EED8 00B2838F */  lw         $3, -0x4E00($28)
    /* 4EEDC 0014EEDC 13006014 */  bnez       $3, .L0014EF2C
    /* 4EEE0 0014EEE0 00000000 */   nop
    /* 4EEE4 0014EEE4 FFFF8630 */  andi       $6, $4, 0xFFFF
    /* 4EEE8 0014EEE8 FFFFA730 */  andi       $7, $5, 0xFFFF
    /* 4EEEC 0014EEEC 1000A427 */  addiu      $4, $29, 0x10
    /* 4EEF0 0014EEF0 5F00053C */  lui        $5, %hi(D_005EFC60)
    /* 4EEF4 0014EEF4 60FCA524 */  addiu      $5, $5, %lo(D_005EFC60)
    /* 4EEF8 0014EEF8 2208110C */  jal        func_00442088
    /* 4EEFC 0014EEFC 00000000 */   nop
    /* 4EF00 0014EF00 F09D8427 */  addiu      $4, $28, -0x6210
    /* 4EF04 0014EF04 5F00053C */  lui        $5, %hi(D_005EFC80)
    /* 4EF08 0014EF08 80FCA524 */  addiu      $5, $5, %lo(D_005EFC80)
    /* 4EF0C 0014EF0C 9E000624 */  addiu      $6, $0, 0x9E
    /* 4EF10 0014EF10 DA02110C */  jal        func_00440b68
    /* 4EF14 0014EF14 00000000 */   nop
    /* 4EF18 0014EF18 1000A427 */  addiu      $4, $29, 0x10
    /* 4EF1C 0014EF1C 01000524 */  addiu      $5, $0, 0x1
    /* 4EF20 0014EF20 9852110C */  jal        func_00454a60
    /* 4EF24 0014EF24 00000000 */   nop
    /* 4EF28 0014EF28 00B282AF */  sw         $2, -0x4E00($28)
  .L0014EF2C:
    /* 4EF2C 0014EF2C 0000BFDF */  ld         $31, 0x0($29)
    /* 4EF30 0014EF30 5000BD27 */  addiu      $29, $29, 0x50
    /* 4EF34 0014EF34 0800E003 */  jr         $31
    /* 4EF38 0014EF38 00000000 */   nop
    /* 4EF3C 0014EF3C 00000000 */  nop
.size func_0014eed0, 0x70
