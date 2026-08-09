.section .text
.set noat
.set noreorder
glabel func_001d7f10
    /* D7F10 001D7F10 E0FFBD27 */  addiu      $29, $29, -0x20
    /* D7F14 001D7F14 1000BFFF */  sd         $31, 0x10($29)
    /* D7F18 001D7F18 0000B07F */  sq         $16, 0x0($29)
    /* D7F1C 001D7F1C 2D80C000 */  daddu      $16, $6, $0
    /* D7F20 001D7F20 2E00A010 */  beqz       $5, .L001D7FDC
    /* D7F24 001D7F24 00000000 */   nop
    /* D7F28 001D7F28 FFFF0332 */  andi       $3, $16, 0xFFFF
    /* D7F2C 001D7F2C 80100300 */  sll        $2, $3, 2
    /* D7F30 001D7F30 21104300 */  addu       $2, $2, $3
    /* D7F34 001D7F34 C0480200 */  sll        $9, $2, 3
    /* D7F38 001D7F38 B8B3888F */  lw         $8, -0x4C48($28)
    /* D7F3C 001D7F3C 21102801 */  addu       $2, $9, $8
    /* D7F40 001D7F40 09004690 */  lbu        $6, 0x9($2)
    /* D7F44 001D7F44 0A004A90 */  lbu        $10, 0xA($2)
    /* D7F48 001D7F48 1F00E010 */  beqz       $7, .L001D7FC8
    /* D7F4C 001D7F4C 00000000 */   nop
    /* D7F50 001D7F50 FF00C730 */  andi       $7, $6, 0xFF
    /* D7F54 001D7F54 0100E330 */  andi       $3, $7, 0x1
    /* D7F58 001D7F58 0A006010 */  beqz       $3, .L001D7F84
    /* D7F5C 001D7F5C 00000000 */   nop
    /* D7F60 001D7F60 0200E230 */  andi       $2, $7, 0x2
    /* D7F64 001D7F64 07004014 */  bnez       $2, .L001D7F84
    /* D7F68 001D7F68 00000000 */   nop
    /* D7F6C 001D7F6C FE00C230 */  andi       $2, $6, 0xFE
    /* D7F70 001D7F70 FF004230 */  andi       $2, $2, 0xFF
    /* D7F74 001D7F74 02004234 */  ori        $2, $2, 0x2
    /* D7F78 001D7F78 FF004630 */  andi       $6, $2, 0xFF
    /* D7F7C 001D7F7C 0A000010 */  b          .L001D7FA8
    /* D7F80 001D7F80 00000000 */   nop
  .L001D7F84:
    /* D7F84 001D7F84 0200E230 */  andi       $2, $7, 0x2
    /* D7F88 001D7F88 07004010 */  beqz       $2, .L001D7FA8
    /* D7F8C 001D7F8C 00000000 */   nop
    /* D7F90 001D7F90 05006014 */  bnez       $3, .L001D7FA8
    /* D7F94 001D7F94 00000000 */   nop
    /* D7F98 001D7F98 FD00C230 */  andi       $2, $6, 0xFD
    /* D7F9C 001D7F9C FF004230 */  andi       $2, $2, 0xFF
    /* D7FA0 001D7FA0 01004234 */  ori        $2, $2, 0x1
    /* D7FA4 001D7FA4 FF004630 */  andi       $6, $2, 0xFF
  .L001D7FA8:
    /* D7FA8 001D7FA8 FF004231 */  andi       $2, $10, 0xFF
    /* D7FAC 001D7FAC 01004230 */  andi       $2, $2, 0x1
    /* D7FB0 001D7FB0 05004010 */  beqz       $2, .L001D7FC8
    /* D7FB4 001D7FB4 00000000 */   nop
    /* D7FB8 001D7FB8 FE004231 */  andi       $2, $10, 0xFE
    /* D7FBC 001D7FBC FF004230 */  andi       $2, $2, 0xFF
    /* D7FC0 001D7FC0 02004234 */  ori        $2, $2, 0x2
    /* D7FC4 001D7FC4 FF004A30 */  andi       $10, $2, 0xFF
  .L001D7FC8:
    /* D7FC8 001D7FC8 21102801 */  addu       $2, $9, $8
    /* D7FCC 001D7FCC 0C004894 */  lhu        $8, 0xC($2)
    /* D7FD0 001D7FD0 2D384001 */  daddu      $7, $10, $0
    /* D7FD4 001D7FD4 185F070C */  jal        func_001d7c60
    /* D7FD8 001D7FD8 00000000 */   nop
  .L001D7FDC:
    /* D7FDC 001D7FDC B8B3848F */  lw         $4, -0x4C48($28)
    /* D7FE0 001D7FE0 FFFF0332 */  andi       $3, $16, 0xFFFF
    /* D7FE4 001D7FE4 80100300 */  sll        $2, $3, 2
    /* D7FE8 001D7FE8 21104300 */  addu       $2, $2, $3
    /* D7FEC 001D7FEC C0100200 */  sll        $2, $2, 3
    /* D7FF0 001D7FF0 21104400 */  addu       $2, $2, $4
    /* D7FF4 001D7FF4 08004290 */  lbu        $2, 0x8($2)
    /* D7FF8 001D7FF8 1000BFDF */  ld         $31, 0x10($29)
    /* D7FFC 001D7FFC 0000B07B */  lq         $16, 0x0($29)
    /* D8000 001D8000 2000BD27 */  addiu      $29, $29, 0x20
    /* D8004 001D8004 0800E003 */  jr         $31
    /* D8008 001D8008 00000000 */   nop
    /* D800C 001D800C 00000000 */  nop
.size func_001d7f10, 0x100
