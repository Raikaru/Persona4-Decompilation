.section .text
.set noat
.set noreorder
glabel func_001f7d90
    /* F7D90 001F7D90 60FFBD27 */  addiu      $29, $29, -0xA0
    /* F7D94 001F7D94 1000BFFF */  sd         $31, 0x10($29)
    /* F7D98 001F7D98 0000B07F */  sq         $16, 0x0($29)
    /* F7D9C 001F7D9C 2D808000 */  daddu      $16, $4, $0
    /* F7DA0 001F7DA0 0C008394 */  lhu        $3, 0xC($4)
    /* F7DA4 001F7DA4 01006330 */  andi       $3, $3, 0x1
    /* F7DA8 001F7DA8 15006014 */  bnez       $3, .L001F7E00
    /* F7DAC 001F7DAC 00000000 */   nop
    /* F7DB0 001F7DB0 04000796 */  lhu        $7, 0x4($16)
    /* F7DB4 001F7DB4 2000A427 */  addiu      $4, $29, 0x20
    /* F7DB8 001F7DB8 6200053C */  lui        $5, %hi(D_00624F30)
    /* F7DBC 001F7DBC 304FA524 */  addiu      $5, $5, %lo(D_00624F30)
    /* F7DC0 001F7DC0 F8A48627 */  addiu      $6, $28, -0x5B08
    /* F7DC4 001F7DC4 2208110C */  jal        func_00442088
    /* F7DC8 001F7DC8 00000000 */   nop
    /* F7DCC 001F7DCC F0A48427 */  addiu      $4, $28, -0x5B10
    /* F7DD0 001F7DD0 6200053C */  lui        $5, %hi(D_00624F20)
    /* F7DD4 001F7DD4 204FA524 */  addiu      $5, $5, %lo(D_00624F20)
    /* F7DD8 001F7DD8 74020624 */  addiu      $6, $0, 0x274
    /* F7DDC 001F7DDC DA02110C */  jal        func_00440b68
    /* F7DE0 001F7DE0 00000000 */   nop
    /* F7DE4 001F7DE4 2000A427 */  addiu      $4, $29, 0x20
    /* F7DE8 001F7DE8 2D280000 */  daddu      $5, $0, $0
    /* F7DEC 001F7DEC 9852110C */  jal        func_00454a60
    /* F7DF0 001F7DF0 00000000 */   nop
    /* F7DF4 001F7DF4 080002AE */  sw         $2, 0x8($16)
    /* F7DF8 001F7DF8 02000010 */  b          .L001F7E04
    /* F7DFC 001F7DFC 00000000 */   nop
  .L001F7E00:
    /* F7E00 001F7E00 080000AE */  sw         $0, 0x8($16)
  .L001F7E04:
    /* F7E04 001F7E04 01000324 */  addiu      $3, $0, 0x1
    /* F7E08 001F7E08 060003A6 */  sh         $3, 0x6($16)
    /* F7E0C 001F7E0C 000000AE */  sw         $0, 0x0($16)
    /* F7E10 001F7E10 1000BFDF */  ld         $31, 0x10($29)
    /* F7E14 001F7E14 0000B07B */  lq         $16, 0x0($29)
    /* F7E18 001F7E18 A000BD27 */  addiu      $29, $29, 0xA0
    /* F7E1C 001F7E1C 0800E003 */  jr         $31
    /* F7E20 001F7E20 00000000 */   nop
    /* F7E24 001F7E24 00000000 */  nop
    /* F7E28 001F7E28 00000000 */  nop
    /* F7E2C 001F7E2C 00000000 */  nop
.size func_001f7d90, 0xa0
