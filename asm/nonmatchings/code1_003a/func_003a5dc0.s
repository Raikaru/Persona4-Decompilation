.section .text
.set noat
.set noreorder
glabel func_003a5dc0
    /* 2A5DC0 003A5DC0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2A5DC4 003A5DC4 10000324 */  addiu      $3, $0, 0x10
    /* 2A5DC8 003A5DC8 0000BFFF */  sd         $31, 0x0($29)
    /* 2A5DCC 003A5DCC 9000D824 */  addiu      $24, $6, 0x90
    /* 2A5DD0 003A5DD0 04008E8C */  lw         $14, 0x4($4)
    /* 2A5DD4 003A5DD4 00008F8C */  lw         $15, 0x0($4)
    /* 2A5DD8 003A5DD8 6F00C311 */  beq        $14, $3, .L003A5F98
    /* 2A5DDC 003A5DDC 9800CD24 */   addiu     $13, $6, 0x98
    /* 2A5DE0 003A5DE0 2A080500 */  slt        $1, $0, $5
    /* 2A5DE4 003A5DE4 6A002010 */  beqz       $1, .L003A5F90
    /* 2A5DE8 003A5DE8 2DC80000 */   daddu     $25, $0, $0
    /* 2A5DEC 003A5DEC 0900A128 */  slti       $1, $5, 0x9
    /* 2A5DF0 003A5DF0 57002014 */  bnez       $1, .L003A5F50
    /* 2A5DF4 003A5DF4 F8FFAC24 */   addiu     $12, $5, -0x8
    /* 2A5DF8 003A5DF8 2A08A000 */  slt        $1, $5, $0
    /* 2A5DFC 003A5DFC 07002014 */  bnez       $1, .L003A5E1C
    /* 2A5E00 003A5E00 2D180000 */   daddu     $3, $0, $0
    /* 2A5E04 003A5E04 FF7F013C */  lui        $1, (0x7FFFFFFF >> 16)
    /* 2A5E08 003A5E08 FFFF2134 */  ori        $1, $1, (0x7FFFFFFF & 0xFFFF)
    /* 2A5E0C 003A5E0C 2A08A100 */  slt        $1, $5, $1
    /* 2A5E10 003A5E10 02002010 */  beqz       $1, .L003A5E1C
    /* 2A5E14 003A5E14 00000000 */   nop
    /* 2A5E18 003A5E18 01000324 */  addiu      $3, $0, 0x1
  .L003A5E1C:
    /* 2A5E1C 003A5E1C 4C006010 */  beqz       $3, .L003A5F50
    /* 2A5E20 003A5E20 00000000 */   nop
  .L003A5E24:
    /* 2A5E24 003A5E24 000000C7 */  lwc1       $f0, 0x0($24)
    /* 2A5E28 003A5E28 2158EE01 */  addu       $11, $15, $14
    /* 2A5E2C 003A5E2C 21506E01 */  addu       $10, $11, $14
    /* 2A5E30 003A5E30 08003927 */  addiu      $25, $25, 0x8
    /* 2A5E34 003A5E34 21484E01 */  addu       $9, $10, $14
    /* 2A5E38 003A5E38 2A182C03 */  slt        $3, $25, $12
    /* 2A5E3C 003A5E3C 21402E01 */  addu       $8, $9, $14
    /* 2A5E40 003A5E40 21380E01 */  addu       $7, $8, $14
    /* 2A5E44 003A5E44 2130EE00 */  addu       $6, $7, $14
    /* 2A5E48 003A5E48 0000E0E5 */  swc1       $f0, 0x0($15)
    /* 2A5E4C 003A5E4C 2120CE00 */  addu       $4, $6, $14
    /* 2A5E50 003A5E50 040000C7 */  lwc1       $f0, 0x4($24)
    /* 2A5E54 003A5E54 0400E0E5 */  swc1       $f0, 0x4($15)
    /* 2A5E58 003A5E58 0000A0C5 */  lwc1       $f0, 0x0($13)
    /* 2A5E5C 003A5E5C 0800E0E5 */  swc1       $f0, 0x8($15)
    /* 2A5E60 003A5E60 0400A0C5 */  lwc1       $f0, 0x4($13)
    /* 2A5E64 003A5E64 0C00E0E5 */  swc1       $f0, 0xC($15)
    /* 2A5E68 003A5E68 000000C7 */  lwc1       $f0, 0x0($24)
    /* 2A5E6C 003A5E6C 21788E00 */  addu       $15, $4, $14
    /* 2A5E70 003A5E70 000060E5 */  swc1       $f0, 0x0($11)
    /* 2A5E74 003A5E74 040000C7 */  lwc1       $f0, 0x4($24)
    /* 2A5E78 003A5E78 040060E5 */  swc1       $f0, 0x4($11)
    /* 2A5E7C 003A5E7C 0000A0C5 */  lwc1       $f0, 0x0($13)
    /* 2A5E80 003A5E80 080060E5 */  swc1       $f0, 0x8($11)
    /* 2A5E84 003A5E84 0400A0C5 */  lwc1       $f0, 0x4($13)
    /* 2A5E88 003A5E88 0C0060E5 */  swc1       $f0, 0xC($11)
    /* 2A5E8C 003A5E8C 000000C7 */  lwc1       $f0, 0x0($24)
    /* 2A5E90 003A5E90 000040E5 */  swc1       $f0, 0x0($10)
    /* 2A5E94 003A5E94 040000C7 */  lwc1       $f0, 0x4($24)
    /* 2A5E98 003A5E98 040040E5 */  swc1       $f0, 0x4($10)
    /* 2A5E9C 003A5E9C 0000A0C5 */  lwc1       $f0, 0x0($13)
    /* 2A5EA0 003A5EA0 080040E5 */  swc1       $f0, 0x8($10)
    /* 2A5EA4 003A5EA4 0400A0C5 */  lwc1       $f0, 0x4($13)
    /* 2A5EA8 003A5EA8 0C0040E5 */  swc1       $f0, 0xC($10)
    /* 2A5EAC 003A5EAC 000000C7 */  lwc1       $f0, 0x0($24)
    /* 2A5EB0 003A5EB0 000020E5 */  swc1       $f0, 0x0($9)
    /* 2A5EB4 003A5EB4 040000C7 */  lwc1       $f0, 0x4($24)
    /* 2A5EB8 003A5EB8 040020E5 */  swc1       $f0, 0x4($9)
    /* 2A5EBC 003A5EBC 0000A0C5 */  lwc1       $f0, 0x0($13)
    /* 2A5EC0 003A5EC0 080020E5 */  swc1       $f0, 0x8($9)
    /* 2A5EC4 003A5EC4 0400A0C5 */  lwc1       $f0, 0x4($13)
    /* 2A5EC8 003A5EC8 0C0020E5 */  swc1       $f0, 0xC($9)
    /* 2A5ECC 003A5ECC 000000C7 */  lwc1       $f0, 0x0($24)
    /* 2A5ED0 003A5ED0 000000E5 */  swc1       $f0, 0x0($8)
    /* 2A5ED4 003A5ED4 040000C7 */  lwc1       $f0, 0x4($24)
    /* 2A5ED8 003A5ED8 040000E5 */  swc1       $f0, 0x4($8)
    /* 2A5EDC 003A5EDC 0000A0C5 */  lwc1       $f0, 0x0($13)
    /* 2A5EE0 003A5EE0 080000E5 */  swc1       $f0, 0x8($8)
    /* 2A5EE4 003A5EE4 0400A0C5 */  lwc1       $f0, 0x4($13)
    /* 2A5EE8 003A5EE8 0C0000E5 */  swc1       $f0, 0xC($8)
    /* 2A5EEC 003A5EEC 000000C7 */  lwc1       $f0, 0x0($24)
    /* 2A5EF0 003A5EF0 0000E0E4 */  swc1       $f0, 0x0($7)
    /* 2A5EF4 003A5EF4 040000C7 */  lwc1       $f0, 0x4($24)
    /* 2A5EF8 003A5EF8 0400E0E4 */  swc1       $f0, 0x4($7)
    /* 2A5EFC 003A5EFC 0000A0C5 */  lwc1       $f0, 0x0($13)
    /* 2A5F00 003A5F00 0800E0E4 */  swc1       $f0, 0x8($7)
    /* 2A5F04 003A5F04 0400A0C5 */  lwc1       $f0, 0x4($13)
    /* 2A5F08 003A5F08 0C00E0E4 */  swc1       $f0, 0xC($7)
    /* 2A5F0C 003A5F0C 000000C7 */  lwc1       $f0, 0x0($24)
    /* 2A5F10 003A5F10 0000C0E4 */  swc1       $f0, 0x0($6)
    /* 2A5F14 003A5F14 040000C7 */  lwc1       $f0, 0x4($24)
    /* 2A5F18 003A5F18 0400C0E4 */  swc1       $f0, 0x4($6)
    /* 2A5F1C 003A5F1C 0000A0C5 */  lwc1       $f0, 0x0($13)
    /* 2A5F20 003A5F20 0800C0E4 */  swc1       $f0, 0x8($6)
    /* 2A5F24 003A5F24 0400A0C5 */  lwc1       $f0, 0x4($13)
    /* 2A5F28 003A5F28 0C00C0E4 */  swc1       $f0, 0xC($6)
    /* 2A5F2C 003A5F2C 000000C7 */  lwc1       $f0, 0x0($24)
    /* 2A5F30 003A5F30 000080E4 */  swc1       $f0, 0x0($4)
    /* 2A5F34 003A5F34 040000C7 */  lwc1       $f0, 0x4($24)
    /* 2A5F38 003A5F38 040080E4 */  swc1       $f0, 0x4($4)
    /* 2A5F3C 003A5F3C 0000A0C5 */  lwc1       $f0, 0x0($13)
    /* 2A5F40 003A5F40 080080E4 */  swc1       $f0, 0x8($4)
    /* 2A5F44 003A5F44 0400A0C5 */  lwc1       $f0, 0x4($13)
    /* 2A5F48 003A5F48 B6FF6014 */  bnez       $3, .L003A5E24
    /* 2A5F4C 003A5F4C 0C0080E4 */   swc1      $f0, 0xC($4)
  .L003A5F50:
    /* 2A5F50 003A5F50 2A082503 */  slt        $1, $25, $5
    /* 2A5F54 003A5F54 0E002010 */  beqz       $1, .L003A5F90
    /* 2A5F58 003A5F58 00000000 */   nop
  .L003A5F5C:
    /* 2A5F5C 003A5F5C 000000C7 */  lwc1       $f0, 0x0($24)
    /* 2A5F60 003A5F60 01003927 */  addiu      $25, $25, 0x1
    /* 2A5F64 003A5F64 2A182503 */  slt        $3, $25, $5
    /* 2A5F68 003A5F68 0000E0E5 */  swc1       $f0, 0x0($15)
    /* 2A5F6C 003A5F6C 040000C7 */  lwc1       $f0, 0x4($24)
    /* 2A5F70 003A5F70 0400E0E5 */  swc1       $f0, 0x4($15)
    /* 2A5F74 003A5F74 0000A0C5 */  lwc1       $f0, 0x0($13)
    /* 2A5F78 003A5F78 0800E0E5 */  swc1       $f0, 0x8($15)
    /* 2A5F7C 003A5F7C 0400A0C5 */  lwc1       $f0, 0x4($13)
    /* 2A5F80 003A5F80 0C00E0E5 */  swc1       $f0, 0xC($15)
    /* 2A5F84 003A5F84 F5FF6014 */  bnez       $3, .L003A5F5C
    /* 2A5F88 003A5F88 2178EE01 */   addu      $15, $15, $14
    /* 2A5F8C 003A5F8C 00000000 */  nop
  .L003A5F90:
    /* 2A5F90 003A5F90 0F000010 */  b          .L003A5FD0
    /* 2A5F94 003A5F94 0000BFDF */   ld        $31, 0x0($29)
  .L003A5F98:
    /* 2A5F98 003A5F98 9000C0C4 */  lwc1       $f0, 0x90($6)
    /* 2A5F9C 003A5F9C 1000A0E7 */  swc1       $f0, 0x10($29)
    /* 2A5FA0 003A5FA0 9400C0C4 */  lwc1       $f0, 0x94($6)
    /* 2A5FA4 003A5FA4 1400A0E7 */  swc1       $f0, 0x14($29)
    /* 2A5FA8 003A5FA8 9800C0C4 */  lwc1       $f0, 0x98($6)
    /* 2A5FAC 003A5FAC 1800A0E7 */  swc1       $f0, 0x18($29)
    /* 2A5FB0 003A5FB0 9C00C0C4 */  lwc1       $f0, 0x9C($6)
    /* 2A5FB4 003A5FB4 1C00A0E7 */  swc1       $f0, 0x1C($29)
    /* 2A5FB8 003A5FB8 1828AE00 */  mult       $5, $5, $14
    /* 2A5FBC 003A5FBC 2D20E001 */  daddu      $4, $15, $0
    /* 2A5FC0 003A5FC0 14920E0C */  jal        func_003a4850
    /* 2A5FC4 003A5FC4 1000A627 */   addiu     $6, $29, 0x10
    /* 2A5FC8 003A5FC8 F1FF0010 */  b          .L003A5F90
    /* 2A5FCC 003A5FCC 00000000 */   nop
  .L003A5FD0:
    /* 2A5FD0 003A5FD0 0800E003 */  jr         $31
    /* 2A5FD4 003A5FD4 2000BD27 */   addiu     $29, $29, 0x20
    /* 2A5FD8 003A5FD8 00000000 */  nop
    /* 2A5FDC 003A5FDC 00000000 */  nop
.size func_003a5dc0, 0x220
