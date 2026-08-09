.section .text
.set noat
.set noreorder
glabel func_001f0dd0
    /* F0DD0 001F0DD0 2D100000 */  daddu      $2, $0, $0
    /* F0DD4 001F0DD4 3400A010 */  beqz       $5, .L001F0EA8
    /* F0DD8 001F0DD8 00000000 */   nop
    /* F0DDC 001F0DDC 2D500000 */  daddu      $10, $0, $0
    /* F0DE0 001F0DE0 6A008894 */  lhu        $8, 0x6A($4)
    /* F0DE4 001F0DE4 01000524 */  addiu      $5, $0, 0x1
    /* F0DE8 001F0DE8 29000010 */  b          .L001F0E90
    /* F0DEC 001F0DEC 00000000 */   nop
  .L001F0DF0:
    /* F0DF0 001F0DF0 FFFF4331 */  andi       $3, $10, 0xFFFF
    /* F0DF4 001F0DF4 80180300 */  sll        $3, $3, 2
    /* F0DF8 001F0DF8 21188300 */  addu       $3, $4, $3
    /* F0DFC 001F0DFC 3800678C */  lw         $7, 0x38($3)
    /* F0E00 001F0E00 E400E38C */  lw         $3, 0xE4($7)
    /* F0E04 001F0E04 04006010 */  beqz       $3, .L001F0E18
    /* F0E08 001F0E08 00000000 */   nop
    /* F0E0C 001F0E0C 2D100000 */  daddu      $2, $0, $0
    /* F0E10 001F0E10 55000010 */  b          .L001F0F68
    /* F0E14 001F0E14 00000000 */   nop
  .L001F0E18:
    /* F0E18 001F0E18 DC00E394 */  lhu        $3, 0xDC($7)
    /* F0E1C 001F0E1C 00056330 */  andi       $3, $3, 0x500
    /* F0E20 001F0E20 04006010 */  beqz       $3, .L001F0E34
    /* F0E24 001F0E24 00000000 */   nop
    /* F0E28 001F0E28 2D100000 */  daddu      $2, $0, $0
    /* F0E2C 001F0E2C 4E000010 */  b          .L001F0F68
    /* F0E30 001F0E30 00000000 */   nop
  .L001F0E34:
    /* F0E34 001F0E34 14004014 */  bnez       $2, .L001F0E88
    /* F0E38 001F0E38 00000000 */   nop
    /* F0E3C 001F0E3C D900E690 */  lbu        $6, 0xD9($7)
    /* F0E40 001F0E40 2D480000 */  daddu      $9, $0, $0
    /* F0E44 001F0E44 0C000010 */  b          .L001F0E78
    /* F0E48 001F0E48 00000000 */   nop
  .L001F0E4C:
    /* F0E4C 001F0E4C FFFF2331 */  andi       $3, $9, 0xFFFF
    /* F0E50 001F0E50 40190300 */  sll        $3, $3, 5
    /* F0E54 001F0E54 2118E300 */  addu       $3, $7, $3
    /* F0E58 001F0E58 F000638C */  lw         $3, 0xF0($3)
    /* F0E5C 001F0E5C 04006104 */  bgez       $3, .L001F0E70
    /* F0E60 001F0E60 00000000 */   nop
    /* F0E64 001F0E64 2D10A000 */  daddu      $2, $5, $0
    /* F0E68 001F0E68 07000010 */  b          .L001F0E88
    /* F0E6C 001F0E6C 00000000 */   nop
  .L001F0E70:
    /* F0E70 001F0E70 01002325 */  addiu      $3, $9, 0x1
    /* F0E74 001F0E74 FFFF6930 */  andi       $9, $3, 0xFFFF
  .L001F0E78:
    /* F0E78 001F0E78 FFFF2331 */  andi       $3, $9, 0xFFFF
    /* F0E7C 001F0E7C 2A186600 */  slt        $3, $3, $6
    /* F0E80 001F0E80 F2FF6014 */  bnez       $3, .L001F0E4C
    /* F0E84 001F0E84 00000000 */   nop
  .L001F0E88:
    /* F0E88 001F0E88 01004325 */  addiu      $3, $10, 0x1
    /* F0E8C 001F0E8C FFFF6A30 */  andi       $10, $3, 0xFFFF
  .L001F0E90:
    /* F0E90 001F0E90 FFFF4331 */  andi       $3, $10, 0xFFFF
    /* F0E94 001F0E94 2A186800 */  slt        $3, $3, $8
    /* F0E98 001F0E98 D5FF6014 */  bnez       $3, .L001F0DF0
    /* F0E9C 001F0E9C 00000000 */   nop
    /* F0EA0 001F0EA0 31000010 */  b          .L001F0F68
    /* F0EA4 001F0EA4 00000000 */   nop
  .L001F0EA8:
    /* F0EA8 001F0EA8 2D500000 */  daddu      $10, $0, $0
    /* F0EAC 001F0EAC 6A008894 */  lhu        $8, 0x6A($4)
    /* F0EB0 001F0EB0 29000010 */  b          .L001F0F58
    /* F0EB4 001F0EB4 00000000 */   nop
  .L001F0EB8:
    /* F0EB8 001F0EB8 FFFF4331 */  andi       $3, $10, 0xFFFF
    /* F0EBC 001F0EBC 80180300 */  sll        $3, $3, 2
    /* F0EC0 001F0EC0 21188300 */  addu       $3, $4, $3
    /* F0EC4 001F0EC4 3800678C */  lw         $7, 0x38($3)
    /* F0EC8 001F0EC8 DC00E394 */  lhu        $3, 0xDC($7)
    /* F0ECC 001F0ECC 06016330 */  andi       $3, $3, 0x106
    /* F0ED0 001F0ED0 04006010 */  beqz       $3, .L001F0EE4
    /* F0ED4 001F0ED4 00000000 */   nop
    /* F0ED8 001F0ED8 01000224 */  addiu      $2, $0, 0x1
    /* F0EDC 001F0EDC 22000010 */  b          .L001F0F68
    /* F0EE0 001F0EE0 00000000 */   nop
  .L001F0EE4:
    /* F0EE4 001F0EE4 D900E690 */  lbu        $6, 0xD9($7)
    /* F0EE8 001F0EE8 2D480000 */  daddu      $9, $0, $0
    /* F0EEC 001F0EEC 14000010 */  b          .L001F0F40
    /* F0EF0 001F0EF0 00000000 */   nop
  .L001F0EF4:
    /* F0EF4 001F0EF4 FFFF2331 */  andi       $3, $9, 0xFFFF
    /* F0EF8 001F0EF8 40190300 */  sll        $3, $3, 5
    /* F0EFC 001F0EFC 2128E300 */  addu       $5, $7, $3
    /* F0F00 001F0F00 F000A38C */  lw         $3, 0xF0($5)
    /* F0F04 001F0F04 07006014 */  bnez       $3, .L001F0F24
    /* F0F08 001F0F08 00000000 */   nop
    /* F0F0C 001F0F0C F800A38C */  lw         $3, 0xF8($5)
    /* F0F10 001F0F10 09006010 */  beqz       $3, .L001F0F38
    /* F0F14 001F0F14 00000000 */   nop
    /* F0F18 001F0F18 01000224 */  addiu      $2, $0, 0x1
    /* F0F1C 001F0F1C 12000010 */  b          .L001F0F68
    /* F0F20 001F0F20 00000000 */   nop
  .L001F0F24:
    /* F0F24 001F0F24 04006104 */  bgez       $3, .L001F0F38
    /* F0F28 001F0F28 00000000 */   nop
    /* F0F2C 001F0F2C 01000224 */  addiu      $2, $0, 0x1
    /* F0F30 001F0F30 0D000010 */  b          .L001F0F68
    /* F0F34 001F0F34 00000000 */   nop
  .L001F0F38:
    /* F0F38 001F0F38 01002325 */  addiu      $3, $9, 0x1
    /* F0F3C 001F0F3C FFFF6930 */  andi       $9, $3, 0xFFFF
  .L001F0F40:
    /* F0F40 001F0F40 FFFF2331 */  andi       $3, $9, 0xFFFF
    /* F0F44 001F0F44 2A186600 */  slt        $3, $3, $6
    /* F0F48 001F0F48 EAFF6014 */  bnez       $3, .L001F0EF4
    /* F0F4C 001F0F4C 00000000 */   nop
    /* F0F50 001F0F50 01004325 */  addiu      $3, $10, 0x1
    /* F0F54 001F0F54 FFFF6A30 */  andi       $10, $3, 0xFFFF
  .L001F0F58:
    /* F0F58 001F0F58 FFFF4331 */  andi       $3, $10, 0xFFFF
    /* F0F5C 001F0F5C 2A186800 */  slt        $3, $3, $8
    /* F0F60 001F0F60 D5FF6014 */  bnez       $3, .L001F0EB8
    /* F0F64 001F0F64 00000000 */   nop
  .L001F0F68:
    /* F0F68 001F0F68 0800E003 */  jr         $31
    /* F0F6C 001F0F6C 00000000 */   nop
.size func_001f0dd0, 0x1a0
