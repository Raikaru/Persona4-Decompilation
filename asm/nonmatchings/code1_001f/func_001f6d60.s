.section .text
.set noat
.set noreorder
glabel func_001f6d60
    /* F6D60 001F6D60 D0FFBD27 */  addiu      $29, $29, -0x30
    /* F6D64 001F6D64 2000BFFF */  sd         $31, 0x20($29)
    /* F6D68 001F6D68 1000B17F */  sq         $17, 0x10($29)
    /* F6D6C 001F6D6C 0000B07F */  sq         $16, 0x0($29)
    /* F6D70 001F6D70 3000828C */  lw         $2, 0x30($4)
    /* F6D74 001F6D74 640A518C */  lw         $17, 0xA64($2)
    /* F6D78 001F6D78 2D800000 */  daddu      $16, $0, $0
    /* F6D7C 001F6D7C 2D202002 */  daddu      $4, $17, $0
    /* F6D80 001F6D80 B0C9080C */  jal        func_002326c0
    /* F6D84 001F6D84 00000000 */   nop
    /* F6D88 001F6D88 40000324 */  addiu      $3, $0, 0x40
    /* F6D8C 001F6D8C 52004310 */  beq        $2, $3, .L001F6ED8
    /* F6D90 001F6D90 00000000 */   nop
    /* F6D94 001F6D94 20000324 */  addiu      $3, $0, 0x20
    /* F6D98 001F6D98 03004310 */  beq        $2, $3, .L001F6DA8
    /* F6D9C 001F6D9C 00000000 */   nop
    /* F6DA0 001F6DA0 66000010 */  b          .L001F6F3C
    /* F6DA4 001F6DA4 00000000 */   nop
  .L001F6DA8:
    /* F6DA8 001F6DA8 2D202002 */  daddu      $4, $17, $0
    /* F6DAC 001F6DAC E0C7080C */  jal        func_00231f80
    /* F6DB0 001F6DB0 00000000 */   nop
    /* F6DB4 001F6DB4 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* F6DB8 001F6DB8 00002296 */  lhu        $2, 0x0($17)
    /* F6DBC 001F6DBC 04004230 */  andi       $2, $2, 0x4
    /* F6DC0 001F6DC0 0F004014 */  bnez       $2, .L001F6E00
    /* F6DC4 001F6DC4 00000000 */   nop
    /* F6DC8 001F6DC8 FFFF8330 */  andi       $3, $4, 0xFFFF
    /* F6DCC 001F6DCC 80100300 */  sll        $2, $3, 2
    /* F6DD0 001F6DD0 21184300 */  addu       $3, $2, $3
    /* F6DD4 001F6DD4 80100300 */  sll        $2, $3, 2
    /* F6DD8 001F6DD8 21106200 */  addu       $2, $3, $2
    /* F6DDC 001F6DDC 80100200 */  sll        $2, $2, 2
    /* F6DE0 001F6DE0 23180200 */  negu       $3, $2
    /* F6DE4 001F6DE4 E8030224 */  addiu      $2, $0, 0x3E8
    /* F6DE8 001F6DE8 1A006200 */  div        $0, $3, $2
    /* F6DEC 001F6DEC 12100000 */  mflo       $2
    /* F6DF0 001F6DF0 3C840200 */  dsll32     $16, $2, 16
    /* F6DF4 001F6DF4 3F841000 */  dsra32     $16, $16, 16
    /* F6DF8 001F6DF8 26000010 */  b          .L001F6E94
    /* F6DFC 001F6DFC 00000000 */   nop
  .L001F6E00:
    /* F6E00 001F6E00 02002396 */  lhu        $3, 0x2($17)
    /* F6E04 001F6E04 00110300 */  sll        $2, $3, 4
    /* F6E08 001F6E08 23104300 */  subu       $2, $2, $3
    /* F6E0C 001F6E0C 80180200 */  sll        $3, $2, 2
    /* F6E10 001F6E10 C4B3828F */  lw         $2, -0x4C3C($28)
    /* F6E14 001F6E14 21104300 */  addu       $2, $2, $3
    /* F6E18 001F6E18 00004394 */  lhu        $3, 0x0($2)
    /* F6E1C 001F6E1C 00046230 */  andi       $2, $3, 0x400
    /* F6E20 001F6E20 04004010 */  beqz       $2, .L001F6E34
    /* F6E24 001F6E24 00000000 */   nop
    /* F6E28 001F6E28 CEFF1024 */  addiu      $16, $0, -0x32
    /* F6E2C 001F6E2C 13000010 */  b          .L001F6E7C
    /* F6E30 001F6E30 00000000 */   nop
  .L001F6E34:
    /* F6E34 001F6E34 00086230 */  andi       $2, $3, 0x800
    /* F6E38 001F6E38 04004010 */  beqz       $2, .L001F6E4C
    /* F6E3C 001F6E3C 00000000 */   nop
    /* F6E40 001F6E40 9CFF1024 */  addiu      $16, $0, -0x64
    /* F6E44 001F6E44 0D000010 */  b          .L001F6E7C
    /* F6E48 001F6E48 00000000 */   nop
  .L001F6E4C:
    /* F6E4C 001F6E4C FFFF8330 */  andi       $3, $4, 0xFFFF
    /* F6E50 001F6E50 80100300 */  sll        $2, $3, 2
    /* F6E54 001F6E54 21184300 */  addu       $3, $2, $3
    /* F6E58 001F6E58 80100300 */  sll        $2, $3, 2
    /* F6E5C 001F6E5C 21106200 */  addu       $2, $3, $2
    /* F6E60 001F6E60 80100200 */  sll        $2, $2, 2
    /* F6E64 001F6E64 23180200 */  negu       $3, $2
    /* F6E68 001F6E68 E8030224 */  addiu      $2, $0, 0x3E8
    /* F6E6C 001F6E6C 1A006200 */  div        $0, $3, $2
    /* F6E70 001F6E70 12100000 */  mflo       $2
    /* F6E74 001F6E74 3C840200 */  dsll32     $16, $2, 16
    /* F6E78 001F6E78 3F841000 */  dsra32     $16, $16, 16
  .L001F6E7C:
    /* F6E7C 001F6E7C 3C141000 */  dsll32     $2, $16, 16
    /* F6E80 001F6E80 3F140200 */  dsra32     $2, $2, 16
    /* F6E84 001F6E84 E8034128 */  slti       $1, $2, 0x3E8
    /* F6E88 001F6E88 02002014 */  bnez       $1, .L001F6E94
    /* F6E8C 001F6E8C 00000000 */   nop
    /* F6E90 001F6E90 E7031024 */  addiu      $16, $0, 0x3E7
  .L001F6E94:
    /* F6E94 001F6E94 3C2C1000 */  dsll32     $5, $16, 16
    /* F6E98 001F6E98 3F2C0500 */  dsra32     $5, $5, 16
    /* F6E9C 001F6E9C 2D202002 */  daddu      $4, $17, $0
    /* F6EA0 001F6EA0 3C0A090C */  jal        func_002428f0
    /* F6EA4 001F6EA4 00000000 */   nop
    /* F6EA8 001F6EA8 24004010 */  beqz       $2, .L001F6F3C
    /* F6EAC 001F6EAC 00000000 */   nop
    /* F6EB0 001F6EB0 2D202002 */  daddu      $4, $17, $0
    /* F6EB4 001F6EB4 B4C7080C */  jal        func_00231ed0
    /* F6EB8 001F6EB8 00000000 */   nop
    /* F6EBC 001F6EBC FFFF4230 */  andi       $2, $2, 0xFFFF
    /* F6EC0 001F6EC0 FFFF4224 */  addiu      $2, $2, -0x1
    /* F6EC4 001F6EC4 23100200 */  negu       $2, $2
    /* F6EC8 001F6EC8 3C840200 */  dsll32     $16, $2, 16
    /* F6ECC 001F6ECC 3F841000 */  dsra32     $16, $16, 16
    /* F6ED0 001F6ED0 1A000010 */  b          .L001F6F3C
    /* F6ED4 001F6ED4 00000000 */   nop
  .L001F6ED8:
    /* F6ED8 001F6ED8 2D202002 */  daddu      $4, $17, $0
    /* F6EDC 001F6EDC A4C8080C */  jal        func_00232290
    /* F6EE0 001F6EE0 00000000 */   nop
    /* F6EE4 001F6EE4 FFFF5030 */  andi       $16, $2, 0xFFFF
    /* F6EE8 001F6EE8 2D202002 */  daddu      $4, $17, $0
    /* F6EEC 001F6EEC B8C7080C */  jal        func_00231ee0
    /* F6EF0 001F6EF0 00000000 */   nop
    /* F6EF4 001F6EF4 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* F6EF8 001F6EF8 FFFF0332 */  andi       $3, $16, 0xFFFF
    /* F6EFC 001F6EFC 80100300 */  sll        $2, $3, 2
    /* F6F00 001F6F00 21184300 */  addu       $3, $2, $3
    /* F6F04 001F6F04 80100300 */  sll        $2, $3, 2
    /* F6F08 001F6F08 21106200 */  addu       $2, $3, $2
    /* F6F0C 001F6F0C 80100200 */  sll        $2, $2, 2
    /* F6F10 001F6F10 23180200 */  negu       $3, $2
    /* F6F14 001F6F14 E8030224 */  addiu      $2, $0, 0x3E8
    /* F6F18 001F6F18 1A006200 */  div        $0, $3, $2
    /* F6F1C 001F6F1C 12100000 */  mflo       $2
    /* F6F20 001F6F20 3C840200 */  dsll32     $16, $2, 16
    /* F6F24 001F6F24 3F841000 */  dsra32     $16, $16, 16
    /* F6F28 001F6F28 2A089000 */  slt        $1, $4, $16
    /* F6F2C 001F6F2C 03002010 */  beqz       $1, .L001F6F3C
    /* F6F30 001F6F30 00000000 */   nop
    /* F6F34 001F6F34 3C840400 */  dsll32     $16, $4, 16
    /* F6F38 001F6F38 3F841000 */  dsra32     $16, $16, 16
  .L001F6F3C:
    /* F6F3C 001F6F3C 2D100002 */  daddu      $2, $16, $0
    /* F6F40 001F6F40 2000BFDF */  ld         $31, 0x20($29)
    /* F6F44 001F6F44 1000B17B */  lq         $17, 0x10($29)
    /* F6F48 001F6F48 0000B07B */  lq         $16, 0x0($29)
    /* F6F4C 001F6F4C 3000BD27 */  addiu      $29, $29, 0x30
    /* F6F50 001F6F50 0800E003 */  jr         $31
    /* F6F54 001F6F54 00000000 */   nop
    /* F6F58 001F6F58 00000000 */  nop
    /* F6F5C 001F6F5C 00000000 */  nop
.size func_001f6d60, 0x200
