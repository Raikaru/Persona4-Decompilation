.section .text
.set noat
.set noreorder
glabel func_0042dcb0
    /* 32DCB0 0042DCB0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 32DCB4 0042DCB4 1000B1FF */  sd         $17, 0x10($29)
    /* 32DCB8 0042DCB8 2D888000 */  daddu      $17, $4, $0
    /* 32DCBC 0042DCBC 2000BFFF */  sd         $31, 0x20($29)
    /* 32DCC0 0042DCC0 0000B0FF */  sd         $16, 0x0($29)
    /* 32DCC4 0042DCC4 F2B9100C */  jal        func_0042e7c8
    /* 32DCC8 0042DCC8 01000424 */   addiu     $4, $0, 0x1
    /* 32DCCC 0042DCCC 0D004014 */  bnez       $2, .L0042DD04
    /* 32DCD0 0042DCD0 2D100000 */   daddu     $2, $0, $0
    /* 32DCD4 0042DCD4 88AE100C */  jal        func_0042ba20
    /* 32DCD8 0042DCD8 00000000 */   nop
    /* 32DCDC 0042DCDC 8900033C */  lui        $3, %hi(D_00894C80)
    /* 32DCE0 0042DCE0 8900043C */  lui        $4, %hi(D_00894C84)
    /* 32DCE4 0042DCE4 804C708C */  lw         $16, %lo(D_00894C80)($3)
    /* 32DCE8 0042DCE8 804C71AC */  sw         $17, %lo(D_00894C80)($3)
    /* 32DCEC 0042DCEC 844C9CAC */  sw         $28, %lo(D_00894C84)($4)
    /* 32DCF0 0042DCF0 04004010 */  beqz       $2, .L0042DD04
    /* 32DCF4 0042DCF4 2D100002 */   daddu     $2, $16, $0
    /* 32DCF8 0042DCF8 9CAE100C */  jal        func_0042ba70
    /* 32DCFC 0042DCFC 00000000 */   nop
    /* 32DD00 0042DD00 2D100002 */  daddu      $2, $16, $0
  .L0042DD04:
    /* 32DD04 0042DD04 2000BFDF */  ld         $31, 0x20($29)
    /* 32DD08 0042DD08 1000B1DF */  ld         $17, 0x10($29)
    /* 32DD0C 0042DD0C 0000B0DF */  ld         $16, 0x0($29)
    /* 32DD10 0042DD10 0800E003 */  jr         $31
    /* 32DD14 0042DD14 3000BD27 */   addiu     $29, $29, 0x30
.size func_0042dcb0, 0x68
