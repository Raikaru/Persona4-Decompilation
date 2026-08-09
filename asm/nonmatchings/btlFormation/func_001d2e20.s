.section .text
.set noat
.set noreorder
glabel func_001d2e20
    /* D2E20 001D2E20 70FFBD27 */  addiu      $29, $29, -0x90
    /* D2E24 001D2E24 6000BFFF */  sd         $31, 0x60($29)
    /* D2E28 001D2E28 5000B57F */  sq         $21, 0x50($29)
    /* D2E2C 001D2E2C 4000B47F */  sq         $20, 0x40($29)
    /* D2E30 001D2E30 3000B37F */  sq         $19, 0x30($29)
    /* D2E34 001D2E34 2000B27F */  sq         $18, 0x20($29)
    /* D2E38 001D2E38 1000B17F */  sq         $17, 0x10($29)
    /* D2E3C 001D2E3C 0000B07F */  sq         $16, 0x0($29)
    /* D2E40 001D2E40 2DA08000 */  daddu      $20, $4, $0
    /* D2E44 001D2E44 0000938C */  lw         $19, 0x0($4)
    /* D2E48 001D2E48 0400828C */  lw         $2, 0x4($4)
    /* D2E4C 001D2E4C 3000528C */  lw         $18, 0x30($2)
    /* D2E50 001D2E50 0C008384 */  lh         $3, 0xC($4)
    /* D2E54 001D2E54 0800828C */  lw         $2, 0x8($4)
    /* D2E58 001D2E58 2B800200 */  sltu       $16, $0, $2
    /* D2E5C 001D2E5C 2DA86000 */  daddu      $21, $3, $0
    /* D2E60 001D2E60 2D206002 */  daddu      $4, $19, $0
    /* D2E64 001D2E64 2D284002 */  daddu      $5, $18, $0
    /* D2E68 001D2E68 2D30A002 */  daddu      $6, $21, $0
    /* D2E6C 001D2E6C 2D380002 */  daddu      $7, $16, $0
    /* D2E70 001D2E70 4067060C */  jal        func_00199d00
    /* D2E74 001D2E74 00000000 */   nop
    /* D2E78 001D2E78 3C8C0200 */  dsll32     $17, $2, 16
    /* D2E7C 001D2E7C 3F8C1100 */  dsra32     $17, $17, 16
    /* D2E80 001D2E80 2D206002 */  daddu      $4, $19, $0
    /* D2E84 001D2E84 2D28A002 */  daddu      $5, $21, $0
    /* D2E88 001D2E88 2D300002 */  daddu      $6, $16, $0
    /* D2E8C 001D2E8C 84C4070C */  jal        func_001f1210
    /* D2E90 001D2E90 00000000 */   nop
    /* D2E94 001D2E94 34004014 */  bnez       $2, .L001D2F68
    /* D2E98 001D2E98 00000000 */   nop
    /* D2E9C 001D2E9C 2D206002 */  daddu      $4, $19, $0
    /* D2EA0 001D2EA0 2D284002 */  daddu      $5, $18, $0
    /* D2EA4 001D2EA4 2D30A002 */  daddu      $6, $21, $0
    /* D2EA8 001D2EA8 2D380002 */  daddu      $7, $16, $0
    /* D2EAC 001D2EAC 4067060C */  jal        func_00199d00
    /* D2EB0 001D2EB0 00000000 */   nop
    /* D2EB4 001D2EB4 3C1C0200 */  dsll32     $3, $2, 16
    /* D2EB8 001D2EB8 3F1C0300 */  dsra32     $3, $3, 16
    /* D2EBC 001D2EBC 03000224 */  addiu      $2, $0, 0x3
    /* D2EC0 001D2EC0 16006210 */  beq        $3, $2, .L001D2F1C
    /* D2EC4 001D2EC4 00000000 */   nop
    /* D2EC8 001D2EC8 01000224 */  addiu      $2, $0, 0x1
    /* D2ECC 001D2ECC 13006210 */  beq        $3, $2, .L001D2F1C
    /* D2ED0 001D2ED0 00000000 */   nop
    /* D2ED4 001D2ED4 02000224 */  addiu      $2, $0, 0x2
    /* D2ED8 001D2ED8 05006210 */  beq        $3, $2, .L001D2EF0
    /* D2EDC 001D2EDC 00000000 */   nop
    /* D2EE0 001D2EE0 03006010 */  beqz       $3, .L001D2EF0
    /* D2EE4 001D2EE4 00000000 */   nop
    /* D2EE8 001D2EE8 15000010 */  b          .L001D2F40
    /* D2EEC 001D2EEC 00000000 */   nop
  .L001D2EF0:
    /* D2EF0 001D2EF0 2D206002 */  daddu      $4, $19, $0
    /* D2EF4 001D2EF4 2D284002 */  daddu      $5, $18, $0
    /* D2EF8 001D2EF8 2D300000 */  daddu      $6, $0, $0
    /* D2EFC 001D2EFC 2D382002 */  daddu      $7, $17, $0
    /* D2F00 001D2F00 8000A827 */  addiu      $8, $29, 0x80
    /* D2F04 001D2F04 7000A927 */  addiu      $9, $29, 0x70
    /* D2F08 001D2F08 2D500000 */  daddu      $10, $0, $0
    /* D2F0C 001D2F0C 7C54060C */  jal        func_001951f0
    /* D2F10 001D2F10 00000000 */   nop
    /* D2F14 001D2F14 0A000010 */  b          .L001D2F40
    /* D2F18 001D2F18 00000000 */   nop
  .L001D2F1C:
    /* D2F1C 001D2F1C 2D206002 */  daddu      $4, $19, $0
    /* D2F20 001D2F20 2D284002 */  daddu      $5, $18, $0
    /* D2F24 001D2F24 2D300000 */  daddu      $6, $0, $0
    /* D2F28 001D2F28 2D382002 */  daddu      $7, $17, $0
    /* D2F2C 001D2F2C 8000A827 */  addiu      $8, $29, 0x80
    /* D2F30 001D2F30 7000A927 */  addiu      $9, $29, 0x70
    /* D2F34 001D2F34 01000A24 */  addiu      $10, $0, 0x1
    /* D2F38 001D2F38 7C54060C */  jal        func_001951f0
    /* D2F3C 001D2F3C 00000000 */   nop
  .L001D2F40:
    /* D2F40 001D2F40 2D206002 */  daddu      $4, $19, $0
    /* D2F44 001D2F44 7000A527 */  addiu      $5, $29, 0x70
    /* D2F48 001D2F48 C453060C */  jal        func_00194f10
    /* D2F4C 001D2F4C 00000000 */   nop
    /* D2F50 001D2F50 2D206002 */  daddu      $4, $19, $0
    /* D2F54 001D2F54 8000A527 */  addiu      $5, $29, 0x80
    /* D2F58 001D2F58 B853060C */  jal        func_00194ee0
    /* D2F5C 001D2F5C 00000000 */   nop
    /* D2F60 001D2F60 13000010 */  b          .L001D2FB0
    /* D2F64 001D2F64 00000000 */   nop
  .L001D2F68:
    /* D2F68 001D2F68 0800828E */  lw         $2, 0x8($20)
    /* D2F6C 001D2F6C 2D206002 */  daddu      $4, $19, $0
    /* D2F70 001D2F70 2D284002 */  daddu      $5, $18, $0
    /* D2F74 001D2F74 3000468C */  lw         $6, 0x30($2)
    /* D2F78 001D2F78 2D382002 */  daddu      $7, $17, $0
    /* D2F7C 001D2F7C 8000A827 */  addiu      $8, $29, 0x80
    /* D2F80 001D2F80 7000A927 */  addiu      $9, $29, 0x70
    /* D2F84 001D2F84 02000A24 */  addiu      $10, $0, 0x2
    /* D2F88 001D2F88 7C54060C */  jal        func_001951f0
    /* D2F8C 001D2F8C 00000000 */   nop
    /* D2F90 001D2F90 2D206002 */  daddu      $4, $19, $0
    /* D2F94 001D2F94 7000A527 */  addiu      $5, $29, 0x70
    /* D2F98 001D2F98 C453060C */  jal        func_00194f10
    /* D2F9C 001D2F9C 00000000 */   nop
    /* D2FA0 001D2FA0 2D206002 */  daddu      $4, $19, $0
    /* D2FA4 001D2FA4 8000A527 */  addiu      $5, $29, 0x80
    /* D2FA8 001D2FA8 B853060C */  jal        func_00194ee0
    /* D2FAC 001D2FAC 00000000 */   nop
  .L001D2FB0:
    /* D2FB0 001D2FB0 01000224 */  addiu      $2, $0, 0x1
    /* D2FB4 001D2FB4 6000BFDF */  ld         $31, 0x60($29)
    /* D2FB8 001D2FB8 5000B57B */  lq         $21, 0x50($29)
    /* D2FBC 001D2FBC 4000B47B */  lq         $20, 0x40($29)
    /* D2FC0 001D2FC0 3000B37B */  lq         $19, 0x30($29)
    /* D2FC4 001D2FC4 2000B27B */  lq         $18, 0x20($29)
    /* D2FC8 001D2FC8 1000B17B */  lq         $17, 0x10($29)
    /* D2FCC 001D2FCC 0000B07B */  lq         $16, 0x0($29)
    /* D2FD0 001D2FD0 9000BD27 */  addiu      $29, $29, 0x90
    /* D2FD4 001D2FD4 0800E003 */  jr         $31
    /* D2FD8 001D2FD8 00000000 */   nop
    /* D2FDC 001D2FDC 00000000 */  nop
.size func_001d2e20, 0x1c0
