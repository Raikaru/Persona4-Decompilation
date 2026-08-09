.section .text
.set noat
.set noreorder
glabel func_001d7c60
    /* D7C60 001D7C60 50FFBD27 */  addiu      $29, $29, -0xB0
    /* D7C64 001D7C64 9000BFFF */  sd         $31, 0x90($29)
    /* D7C68 001D7C68 8000BE7F */  sq         $30, 0x80($29)
    /* D7C6C 001D7C6C 7000B77F */  sq         $23, 0x70($29)
    /* D7C70 001D7C70 6000B67F */  sq         $22, 0x60($29)
    /* D7C74 001D7C74 5000B57F */  sq         $21, 0x50($29)
    /* D7C78 001D7C78 4000B47F */  sq         $20, 0x40($29)
    /* D7C7C 001D7C7C 3000B37F */  sq         $19, 0x30($29)
    /* D7C80 001D7C80 2000B27F */  sq         $18, 0x20($29)
    /* D7C84 001D7C84 1000B17F */  sq         $17, 0x10($29)
    /* D7C88 001D7C88 0000B07F */  sq         $16, 0x0($29)
    /* D7C8C 001D7C8C 2DA08000 */  daddu      $20, $4, $0
    /* D7C90 001D7C90 2D98A000 */  daddu      $19, $5, $0
    /* D7C94 001D7C94 2DA8C000 */  daddu      $21, $6, $0
    /* D7C98 001D7C98 2DB0E000 */  daddu      $22, $7, $0
    /* D7C9C 001D7C9C 2D900001 */  daddu      $18, $8, $0
    /* D7CA0 001D7CA0 2D206002 */  daddu      $4, $19, $0
    /* D7CA4 001D7CA4 2D280000 */  daddu      $5, $0, $0
    /* D7CA8 001D7CA8 30000624 */  addiu      $6, $0, 0x30
    /* D7CAC 001D7CAC 72FE100C */  jal        func_0043f9c8
    /* D7CB0 001D7CB0 00000000 */   nop
    /* D7CB4 001D7CB4 380060A6 */  sh         $0, 0x38($19)
    /* D7CB8 001D7CB8 3A0060A6 */  sh         $0, 0x3A($19)
    /* D7CBC 001D7CBC 3C0060A2 */  sb         $0, 0x3C($19)
    /* D7CC0 001D7CC0 3C006392 */  lbu        $3, 0x3C($19)
    /* D7CC4 001D7CC4 01006334 */  ori        $3, $3, 0x1
    /* D7CC8 001D7CC8 3C0063A2 */  sb         $3, 0x3C($19)
    /* D7CCC 001D7CCC 12008012 */  beqz       $20, .L001D7D18
    /* D7CD0 001D7CD0 00000000 */   nop
    /* D7CD4 001D7CD4 3000838E */  lw         $3, 0x30($20)
    /* D7CD8 001D7CD8 A2006490 */  lbu        $4, 0xA2($3)
    /* D7CDC 001D7CDC 01000324 */  addiu      $3, $0, 0x1
    /* D7CE0 001D7CE0 09008310 */  beq        $4, $3, .L001D7D08
    /* D7CE4 001D7CE4 00000000 */   nop
    /* D7CE8 001D7CE8 03008010 */  beqz       $4, .L001D7CF8
    /* D7CEC 001D7CEC 00000000 */   nop
    /* D7CF0 001D7CF0 0B000010 */  b          .L001D7D20
    /* D7CF4 001D7CF4 00000000 */   nop
  .L001D7CF8:
    /* D7CF8 001D7CF8 FFFF7130 */  andi       $17, $3, 0xFFFF
    /* D7CFC 001D7CFC 02001064 */  daddiu     $16, $0, 0x2
    /* D7D00 001D7D00 07000010 */  b          .L001D7D20
    /* D7D04 001D7D04 00000000 */   nop
  .L001D7D08:
    /* D7D08 001D7D08 02001164 */  daddiu     $17, $0, 0x2
    /* D7D0C 001D7D0C FFFF7030 */  andi       $16, $3, 0xFFFF
    /* D7D10 001D7D10 03000010 */  b          .L001D7D20
    /* D7D14 001D7D14 00000000 */   nop
  .L001D7D18:
    /* D7D18 001D7D18 01001164 */  daddiu     $17, $0, 0x1
    /* D7D1C 001D7D1C 02001064 */  daddiu     $16, $0, 0x2
  .L001D7D20:
    /* D7D20 001D7D20 2D280000 */  daddu      $5, $0, $0
    /* D7D24 001D7D24 FF00A432 */  andi       $4, $21, 0xFF
    /* D7D28 001D7D28 01008330 */  andi       $3, $4, 0x1
    /* D7D2C 001D7D2C 03006010 */  beqz       $3, .L001D7D3C
    /* D7D30 001D7D30 00000000 */   nop
    /* D7D34 001D7D34 2518B100 */  or         $3, $5, $17
    /* D7D38 001D7D38 FFFF6530 */  andi       $5, $3, 0xFFFF
  .L001D7D3C:
    /* D7D3C 001D7D3C 02008330 */  andi       $3, $4, 0x2
    /* D7D40 001D7D40 03006010 */  beqz       $3, .L001D7D50
    /* D7D44 001D7D44 00000000 */   nop
    /* D7D48 001D7D48 2518B000 */  or         $3, $5, $16
    /* D7D4C 001D7D4C FFFF6530 */  andi       $5, $3, 0xFFFF
  .L001D7D50:
    /* D7D50 001D7D50 04008330 */  andi       $3, $4, 0x4
    /* D7D54 001D7D54 03006010 */  beqz       $3, .L001D7D64
    /* D7D58 001D7D58 00000000 */   nop
    /* D7D5C 001D7D5C 0400A334 */  ori        $3, $5, 0x4
    /* D7D60 001D7D60 FFFF6530 */  andi       $5, $3, 0xFFFF
  .L001D7D64:
    /* D7D64 001D7D64 FF00C432 */  andi       $4, $22, 0xFF
    /* D7D68 001D7D68 01008330 */  andi       $3, $4, 0x1
    /* D7D6C 001D7D6C 06006010 */  beqz       $3, .L001D7D88
    /* D7D70 001D7D70 00000000 */   nop
    /* D7D74 001D7D74 000074AE */  sw         $20, 0x0($19)
    /* D7D78 001D7D78 01000324 */  addiu      $3, $0, 0x1
    /* D7D7C 001D7D7C 380063A6 */  sh         $3, 0x38($19)
    /* D7D80 001D7D80 54000010 */  b          .L001D7ED4
    /* D7D84 001D7D84 00000000 */   nop
  .L001D7D88:
    /* D7D88 001D7D88 ACB3838F */  lw         $3, -0x4C54($28)
    /* D7D8C 001D7D8C 7401758C */  lw         $21, 0x174($3)
    /* D7D90 001D7D90 FFFFB130 */  andi       $17, $5, 0xFFFF
    /* D7D94 001D7D94 04003632 */  andi       $22, $17, 0x4
    /* D7D98 001D7D98 02009730 */  andi       $23, $4, 0x2
    /* D7D9C 001D7D9C 04009E30 */  andi       $30, $4, 0x4
    /* D7DA0 001D7DA0 08008330 */  andi       $3, $4, 0x8
    /* D7DA4 001D7DA4 A000A37F */  sq         $3, 0xA0($29)
    /* D7DA8 001D7DA8 48000010 */  b          .L001D7ECC
    /* D7DAC 001D7DAC 00000000 */   nop
  .L001D7DB0:
    /* D7DB0 001D7DB0 05008012 */  beqz       $20, .L001D7DC8
    /* D7DB4 001D7DB4 00000000 */   nop
    /* D7DB8 001D7DB8 1A00A396 */  lhu        $3, 0x1A($21)
    /* D7DBC 001D7DBC 08006330 */  andi       $3, $3, 0x8
    /* D7DC0 001D7DC0 41006010 */  beqz       $3, .L001D7EC8
    /* D7DC4 001D7DC4 00000000 */   nop
  .L001D7DC8:
    /* D7DC8 001D7DC8 1A00A396 */  lhu        $3, 0x1A($21)
    /* D7DCC 001D7DCC 01006330 */  andi       $3, $3, 0x1
    /* D7DD0 001D7DD0 3D006010 */  beqz       $3, .L001D7EC8
    /* D7DD4 001D7DD4 00000000 */   nop
    /* D7DD8 001D7DD8 3000B08E */  lw         $16, 0x30($21)
    /* D7DDC 001D7DDC A2000492 */  lbu        $4, 0xA2($16)
    /* D7DE0 001D7DE0 02000324 */  addiu      $3, $0, 0x2
    /* D7DE4 001D7DE4 05008310 */  beq        $4, $3, .L001D7DFC
    /* D7DE8 001D7DE8 00000000 */   nop
    /* D7DEC 001D7DEC 9C00038E */  lw         $3, 0x9C($16)
    /* D7DF0 001D7DF0 08006330 */  andi       $3, $3, 0x8
    /* D7DF4 001D7DF4 34006010 */  beqz       $3, .L001D7EC8
    /* D7DF8 001D7DF8 00000000 */   nop
  .L001D7DFC:
    /* D7DFC 001D7DFC 01000324 */  addiu      $3, $0, 0x1
    /* D7E00 001D7E00 04188300 */  sllv       $3, $3, $4
    /* D7E04 001D7E04 24182302 */  and        $3, $17, $3
    /* D7E08 001D7E08 2F006010 */  beqz       $3, .L001D7EC8
    /* D7E0C 001D7E0C 00000000 */   nop
    /* D7E10 001D7E10 2600C016 */  bnez       $22, .L001D7EAC
    /* D7E14 001D7E14 00000000 */   nop
    /* D7E18 001D7E18 0300E012 */  beqz       $23, .L001D7E28
    /* D7E1C 001D7E1C 00000000 */   nop
    /* D7E20 001D7E20 29009512 */  beq        $20, $21, .L001D7EC8
    /* D7E24 001D7E24 00000000 */   nop
  .L001D7E28:
    /* D7E28 001D7E28 0700C017 */  bnez       $30, .L001D7E48
    /* D7E2C 001D7E2C 00000000 */   nop
    /* D7E30 001D7E30 640A048E */  lw         $4, 0xA64($16)
    /* D7E34 001D7E34 2D280000 */  daddu      $5, $0, $0
    /* D7E38 001D7E38 3C0A090C */  jal        func_002428f0
    /* D7E3C 001D7E3C 00000000 */   nop
    /* D7E40 001D7E40 21004014 */  bnez       $2, .L001D7EC8
    /* D7E44 001D7E44 00000000 */   nop
  .L001D7E48:
    /* D7E48 001D7E48 A000A37B */  lq         $3, 0xA0($29)
    /* D7E4C 001D7E4C 09006010 */  beqz       $3, .L001D7E74
    /* D7E50 001D7E50 00000000 */   nop
    /* D7E54 001D7E54 640A048E */  lw         $4, 0xA64($16)
    /* D7E58 001D7E58 1000053C */  lui        $5, (0x100000 >> 16)
    /* D7E5C 001D7E5C C4C9080C */  jal        func_00232710
    /* D7E60 001D7E60 00000000 */   nop
    /* D7E64 001D7E64 11004014 */  bnez       $2, .L001D7EAC
    /* D7E68 001D7E68 00000000 */   nop
    /* D7E6C 001D7E6C 16000010 */  b          .L001D7EC8
    /* D7E70 001D7E70 00000000 */   nop
  .L001D7E74:
    /* D7E74 001D7E74 0D004012 */  beqz       $18, .L001D7EAC
    /* D7E78 001D7E78 00000000 */   nop
    /* D7E7C 001D7E7C 640A048E */  lw         $4, 0xA64($16)
    /* D7E80 001D7E80 0C00858C */  lw         $5, 0xC($4)
    /* D7E84 001D7E84 EFFF033C */  lui        $3, (0xFFEFFFFF >> 16)
    /* D7E88 001D7E88 FFFF6334 */  ori        $3, $3, (0xFFEFFFFF & 0xFFFF)
    /* D7E8C 001D7E8C 2418A300 */  and        $3, $5, $3
    /* D7E90 001D7E90 0D006010 */  beqz       $3, .L001D7EC8
    /* D7E94 001D7E94 00000000 */   nop
    /* D7E98 001D7E98 2D284002 */  daddu      $5, $18, $0
    /* D7E9C 001D7E9C C4C9080C */  jal        func_00232710
    /* D7EA0 001D7EA0 00000000 */   nop
    /* D7EA4 001D7EA4 08004014 */  bnez       $2, .L001D7EC8
    /* D7EA8 001D7EA8 00000000 */   nop
  .L001D7EAC:
    /* D7EAC 001D7EAC 38006396 */  lhu        $3, 0x38($19)
    /* D7EB0 001D7EB0 80180300 */  sll        $3, $3, 2
    /* D7EB4 001D7EB4 21186302 */  addu       $3, $19, $3
    /* D7EB8 001D7EB8 000075AC */  sw         $21, 0x0($3)
    /* D7EBC 001D7EBC 38006396 */  lhu        $3, 0x38($19)
    /* D7EC0 001D7EC0 01006324 */  addiu      $3, $3, 0x1
    /* D7EC4 001D7EC4 380063A6 */  sh         $3, 0x38($19)
  .L001D7EC8:
    /* D7EC8 001D7EC8 5004B58E */  lw         $21, 0x450($21)
  .L001D7ECC:
    /* D7ECC 001D7ECC B8FFA016 */  bnez       $21, .L001D7DB0
    /* D7ED0 001D7ED0 00000000 */   nop
  .L001D7ED4:
    /* D7ED4 001D7ED4 9000BFDF */  ld         $31, 0x90($29)
    /* D7ED8 001D7ED8 8000BE7B */  lq         $30, 0x80($29)
    /* D7EDC 001D7EDC 7000B77B */  lq         $23, 0x70($29)
    /* D7EE0 001D7EE0 6000B67B */  lq         $22, 0x60($29)
    /* D7EE4 001D7EE4 5000B57B */  lq         $21, 0x50($29)
    /* D7EE8 001D7EE8 4000B47B */  lq         $20, 0x40($29)
    /* D7EEC 001D7EEC 3000B37B */  lq         $19, 0x30($29)
    /* D7EF0 001D7EF0 2000B27B */  lq         $18, 0x20($29)
    /* D7EF4 001D7EF4 1000B17B */  lq         $17, 0x10($29)
    /* D7EF8 001D7EF8 0000B07B */  lq         $16, 0x0($29)
    /* D7EFC 001D7EFC B000BD27 */  addiu      $29, $29, 0xB0
    /* D7F00 001D7F00 0800E003 */  jr         $31
    /* D7F04 001D7F04 00000000 */   nop
    /* D7F08 001D7F08 00000000 */  nop
    /* D7F0C 001D7F0C 00000000 */  nop
.size func_001d7c60, 0x2b0
