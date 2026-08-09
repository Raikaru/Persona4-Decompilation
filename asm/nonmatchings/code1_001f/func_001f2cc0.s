.section .text
.set noat
.set noreorder
glabel func_001f2cc0
    /* F2CC0 001F2CC0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* F2CC4 001F2CC4 2000BFFF */  sd         $31, 0x20($29)
    /* F2CC8 001F2CC8 1000B17F */  sq         $17, 0x10($29)
    /* F2CCC 001F2CCC 0000B07F */  sq         $16, 0x0($29)
    /* F2CD0 001F2CD0 2D888000 */  daddu      $17, $4, $0
    /* F2CD4 001F2CD4 1A008394 */  lhu        $3, 0x1A($4)
    /* F2CD8 001F2CD8 01006330 */  andi       $3, $3, 0x1
    /* F2CDC 001F2CDC 6E006010 */  beqz       $3, .L001F2E98
    /* F2CE0 001F2CE0 00000000 */   nop
    /* F2CE4 001F2CE4 3000308E */  lw         $16, 0x30($17)
    /* F2CE8 001F2CE8 A2000492 */  lbu        $4, 0xA2($16)
    /* F2CEC 001F2CEC 01000324 */  addiu      $3, $0, 0x1
    /* F2CF0 001F2CF0 69008314 */  bne        $4, $3, .L001F2E98
    /* F2CF4 001F2CF4 00000000 */   nop
    /* F2CF8 001F2CF8 A4000396 */  lhu        $3, 0xA4($16)
    /* F2CFC 001F2CFC 50016328 */  slti       $3, $3, 0x150
    /* F2D00 001F2D00 06006014 */  bnez       $3, .L001F2D1C
    /* F2D04 001F2D04 00000000 */   nop
    /* F2D08 001F2D08 6100043C */  lui        $4, %hi(D_0060AB08)
    /* F2D0C 001F2D0C 08AB8424 */  addiu      $4, $4, %lo(D_0060AB08)
    /* F2D10 001F2D10 F5040524 */  addiu      $5, $0, 0x4F5
    /* F2D14 001F2D14 CCB5110C */  jal        func_0046d730
    /* F2D18 001F2D18 00000000 */   nop
  .L001F2D1C:
    /* F2D1C 001F2D1C 1A002496 */  lhu        $4, 0x1A($17)
    /* F2D20 001F2D20 20008330 */  andi       $3, $4, 0x20
    /* F2D24 001F2D24 5C006014 */  bnez       $3, .L001F2E98
    /* F2D28 001F2D28 00000000 */   nop
    /* F2D2C 001F2D2C 20008234 */  ori        $2, $4, 0x20
    /* F2D30 001F2D30 1A0022A6 */  sh         $2, 0x1A($17)
    /* F2D34 001F2D34 640A048E */  lw         $4, 0xA64($16)
    /* F2D38 001F2D38 540E090C */  jal        func_00243950
    /* F2D3C 001F2D3C 00000000 */   nop
    /* F2D40 001F2D40 ACB3848F */  lw         $4, -0x4C54($28)
    /* F2D44 001F2D44 B00C838C */  lw         $3, 0xCB0($4)
    /* F2D48 001F2D48 21106200 */  addu       $2, $3, $2
    /* F2D4C 001F2D4C B00C82AC */  sw         $2, 0xCB0($4)
    /* F2D50 001F2D50 640A048E */  lw         $4, 0xA64($16)
    /* F2D54 001F2D54 700E090C */  jal        func_002439c0
    /* F2D58 001F2D58 00000000 */   nop
    /* F2D5C 001F2D5C ACB3848F */  lw         $4, -0x4C54($28)
    /* F2D60 001F2D60 B40C838C */  lw         $3, 0xCB4($4)
    /* F2D64 001F2D64 21106200 */  addu       $2, $3, $2
    /* F2D68 001F2D68 B40C82AC */  sw         $2, 0xCB4($4)
    /* F2D6C 001F2D6C 640A048E */  lw         $4, 0xA64($16)
    /* F2D70 001F2D70 3C00A527 */  addiu      $5, $29, 0x3C
    /* F2D74 001F2D74 8C0E090C */  jal        func_00243a30
    /* F2D78 001F2D78 00000000 */   nop
    /* F2D7C 001F2D7C FFFF5030 */  andi       $16, $2, 0xFFFF
    /* F2D80 001F2D80 3C00A48F */  lw         $4, 0x3C($29)
    /* F2D84 001F2D84 01000324 */  addiu      $3, $0, 0x1
    /* F2D88 001F2D88 0D008310 */  beq        $4, $3, .L001F2DC0
    /* F2D8C 001F2D8C 00000000 */   nop
    /* F2D90 001F2D90 80002396 */  lhu        $3, 0x80($17)
    /* F2D94 001F2D94 0A006010 */  beqz       $3, .L001F2DC0
    /* F2D98 001F2D98 00000000 */   nop
    /* F2D9C 001F2D9C 64000424 */  addiu      $4, $0, 0x64
    /* F2DA0 001F2DA0 5CC7080C */  jal        func_00231d70
    /* F2DA4 001F2DA4 00000000 */   nop
    /* F2DA8 001F2DA8 FF004430 */  andi       $4, $2, 0xFF
    /* F2DAC 001F2DAC 82002392 */  lbu        $3, 0x82($17)
    /* F2DB0 001F2DB0 2A088300 */  slt        $1, $4, $3
    /* F2DB4 001F2DB4 02002010 */  beqz       $1, .L001F2DC0
    /* F2DB8 001F2DB8 00000000 */   nop
    /* F2DBC 001F2DBC 80003096 */  lhu        $16, 0x80($17)
  .L001F2DC0:
    /* F2DC0 001F2DC0 FFFF0632 */  andi       $6, $16, 0xFFFF
    /* F2DC4 001F2DC4 3400C010 */  beqz       $6, .L001F2E98
    /* F2DC8 001F2DC8 00000000 */   nop
    /* F2DCC 001F2DCC 2D380000 */  daddu      $7, $0, $0
    /* F2DD0 001F2DD0 2D400000 */  daddu      $8, $0, $0
    /* F2DD4 001F2DD4 ACB3858F */  lw         $5, -0x4C54($28)
    /* F2DD8 001F2DD8 0F000010 */  b          .L001F2E18
    /* F2DDC 001F2DDC 00000000 */   nop
  .L001F2DE0:
    /* F2DE0 001F2DE0 FFFF0331 */  andi       $3, $8, 0xFFFF
    /* F2DE4 001F2DE4 80180300 */  sll        $3, $3, 2
    /* F2DE8 001F2DE8 2120A300 */  addu       $4, $5, $3
    /* F2DEC 001F2DEC D00C8394 */  lhu        $3, 0xCD0($4)
    /* F2DF0 001F2DF0 07006614 */  bne        $3, $6, .L001F2E10
    /* F2DF4 001F2DF4 00000000 */   nop
    /* F2DF8 001F2DF8 D20C8384 */  lh         $3, 0xCD2($4)
    /* F2DFC 001F2DFC 01006324 */  addiu      $3, $3, 0x1
    /* F2E00 001F2E00 D20C83A4 */  sh         $3, 0xCD2($4)
    /* F2E04 001F2E04 01000724 */  addiu      $7, $0, 0x1
    /* F2E08 001F2E08 07000010 */  b          .L001F2E28
    /* F2E0C 001F2E0C 00000000 */   nop
  .L001F2E10:
    /* F2E10 001F2E10 01000325 */  addiu      $3, $8, 0x1
    /* F2E14 001F2E14 FFFF6830 */  andi       $8, $3, 0xFFFF
  .L001F2E18:
    /* F2E18 001F2E18 FFFF0331 */  andi       $3, $8, 0xFFFF
    /* F2E1C 001F2E1C 03006328 */  slti       $3, $3, 0x3
    /* F2E20 001F2E20 EFFF6014 */  bnez       $3, .L001F2DE0
    /* F2E24 001F2E24 00000000 */   nop
  .L001F2E28:
    /* F2E28 001F2E28 1B00E014 */  bnez       $7, .L001F2E98
    /* F2E2C 001F2E2C 00000000 */   nop
    /* F2E30 001F2E30 2D400000 */  daddu      $8, $0, $0
    /* F2E34 001F2E34 ACB3878F */  lw         $7, -0x4C54($28)
    /* F2E38 001F2E38 13000010 */  b          .L001F2E88
    /* F2E3C 001F2E3C 00000000 */   nop
  .L001F2E40:
    /* F2E40 001F2E40 FFFF0331 */  andi       $3, $8, 0xFFFF
    /* F2E44 001F2E44 80300300 */  sll        $6, $3, 2
    /* F2E48 001F2E48 2128E600 */  addu       $5, $7, $6
    /* F2E4C 001F2E4C D00CA394 */  lhu        $3, 0xCD0($5)
    /* F2E50 001F2E50 0B006014 */  bnez       $3, .L001F2E80
    /* F2E54 001F2E54 00000000 */   nop
    /* F2E58 001F2E58 D00CB0A4 */  sh         $16, 0xCD0($5)
    /* F2E5C 001F2E5C 01000524 */  addiu      $5, $0, 0x1
    /* F2E60 001F2E60 ACB3838F */  lw         $3, -0x4C54($28)
    /* F2E64 001F2E64 2118C300 */  addu       $3, $6, $3
    /* F2E68 001F2E68 D20C65A4 */  sh         $5, 0xCD2($3)
    /* F2E6C 001F2E6C 01008424 */  addiu      $4, $4, 0x1
    /* F2E70 001F2E70 ACB3838F */  lw         $3, -0x4C54($28)
    /* F2E74 001F2E74 DC0C64AC */  sw         $4, 0xCDC($3)
    /* F2E78 001F2E78 07000010 */  b          .L001F2E98
    /* F2E7C 001F2E7C 00000000 */   nop
  .L001F2E80:
    /* F2E80 001F2E80 01000325 */  addiu      $3, $8, 0x1
    /* F2E84 001F2E84 FFFF6830 */  andi       $8, $3, 0xFFFF
  .L001F2E88:
    /* F2E88 001F2E88 FFFF0431 */  andi       $4, $8, 0xFFFF
    /* F2E8C 001F2E8C 03008328 */  slti       $3, $4, 0x3
    /* F2E90 001F2E90 EBFF6014 */  bnez       $3, .L001F2E40
    /* F2E94 001F2E94 00000000 */   nop
  .L001F2E98:
    /* F2E98 001F2E98 2000BFDF */  ld         $31, 0x20($29)
    /* F2E9C 001F2E9C 1000B17B */  lq         $17, 0x10($29)
    /* F2EA0 001F2EA0 0000B07B */  lq         $16, 0x0($29)
    /* F2EA4 001F2EA4 4000BD27 */  addiu      $29, $29, 0x40
    /* F2EA8 001F2EA8 0800E003 */  jr         $31
    /* F2EAC 001F2EAC 00000000 */   nop
.size func_001f2cc0, 0x1f0
