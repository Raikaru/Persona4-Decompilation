.section .text
.set noat
.set noreorder
glabel func_003c9d40
    /* 2C9D40 003C9D40 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2C9D44 003C9D44 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2C9D48 003C9D48 1000BFFF */  sd         $31, 0x10($29)
    /* 2C9D4C 003C9D4C E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2C9D50 003C9D50 0000B07F */  sq         $16, 0x0($29)
    /* 2C9D54 003C9D54 00B7838F */  lw         $3, -0x4900($28)
    /* 2C9D58 003C9D58 2D808000 */  daddu      $16, $4, $0
    /* 2C9D5C 003C9D5C 21104300 */  addu       $2, $2, $3
    /* 2C9D60 003C9D60 0400448C */  lw         $4, 0x4($2)
    /* 2C9D64 003C9D64 04004324 */  addiu      $3, $2, 0x4
    /* 2C9D68 003C9D68 37008310 */  beq        $4, $3, .L003C9E48
    /* 2C9D6C 003C9D6C 00000000 */   nop
  .L003C9D70:
    /* 2C9D70 003C9D70 F8FF828C */  lw         $2, -0x8($4)
    /* 2C9D74 003C9D74 11005014 */  bne        $2, $16, .L003C9DBC
    /* 2C9D78 003C9D78 F8FF8524 */   addiu     $5, $4, -0x8
    /* 2C9D7C 003C9D7C 0800A68C */  lw         $6, 0x8($5)
    /* 2C9D80 003C9D80 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2C9D84 003C9D84 0C00A48C */  lw         $4, 0xC($5)
    /* 2C9D88 003C9D88 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2C9D8C 003C9D8C 8800023C */  lui        $2, %hi(jtbl_008873FC)
    /* 2C9D90 003C9D90 000086AC */  sw         $6, 0x0($4)
    /* 2C9D94 003C9D94 0C00A68C */  lw         $6, 0xC($5)
    /* 2C9D98 003C9D98 0800A48C */  lw         $4, 0x8($5)
    /* 2C9D9C 003C9D9C 040086AC */  sw         $6, 0x4($4)
    /* 2C9DA0 003C9DA0 00B7848F */  lw         $4, -0x4900($28)
    /* 2C9DA4 003C9DA4 FC73428C */  lw         $2, %lo(jtbl_008873FC)($2)
    /* 2C9DA8 003C9DA8 21186400 */  addu       $3, $3, $4
    /* 2C9DAC 003C9DAC 09F84000 */  jalr       $2
    /* 2C9DB0 003C9DB0 0000648C */   lw        $4, 0x0($3)
    /* 2C9DB4 003C9DB4 25000010 */  b          .L003C9E4C
    /* 2C9DB8 003C9DB8 2D200002 */   daddu     $4, $16, $0
  .L003C9DBC:
    /* 2C9DBC 003C9DBC 0000848C */  lw         $4, 0x0($4)
    /* 2C9DC0 003C9DC0 EBFF8314 */  bne        $4, $3, .L003C9D70
    /* 2C9DC4 003C9DC4 00000000 */   nop
    /* 2C9DC8 003C9DC8 1F000010 */  b          .L003C9E48
    /* 2C9DCC 003C9DCC 00000000 */   nop
  .L003C9DD0:
    /* 2C9DD0 003C9DD0 03008010 */  beqz       $4, .L003C9DE0
    /* 2C9DD4 003C9DD4 00000000 */   nop
    /* 2C9DD8 003C9DD8 74240F0C */  jal        func_003c91d0
    /* 2C9DDC 003C9DDC 00000000 */   nop
  .L003C9DE0:
    /* 2C9DE0 003C9DE0 7100043C */  lui        $4, %hi(D_0070B060)
    /* 2C9DE4 003C9DE4 2D280002 */  daddu      $5, $16, $0
    /* 2C9DE8 003C9DE8 088F0F0C */  jal        func_003e3c20
    /* 2C9DEC 003C9DEC 60B08424 */   addiu     $4, $4, %lo(D_0070B060)
    /* 2C9DF0 003C9DF0 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2C9DF4 003C9DF4 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2C9DF8 003C9DF8 09F84000 */  jalr       $2
    /* 2C9DFC 003C9DFC 2D200002 */   daddu     $4, $16, $0
    /* 2C9E00 003C9E00 0F000010 */  b          .L003C9E40
    /* 2C9E04 003C9E04 01000224 */   addiu     $2, $0, 0x1
  .L003C9E08:
    /* 2C9E08 003C9E08 1C00048E */  lw         $4, 0x1C($16)
    /* 2C9E0C 003C9E0C 03008010 */  beqz       $4, .L003C9E1C
    /* 2C9E10 003C9E10 00000000 */   nop
    /* 2C9E14 003C9E14 C0240F0C */  jal        func_003c9300
    /* 2C9E18 003C9E18 00000000 */   nop
  .L003C9E1C:
    /* 2C9E1C 003C9E1C 7100043C */  lui        $4, %hi(D_0070B060)
    /* 2C9E20 003C9E20 2D280002 */  daddu      $5, $16, $0
    /* 2C9E24 003C9E24 088F0F0C */  jal        func_003e3c20
    /* 2C9E28 003C9E28 60B08424 */   addiu     $4, $4, %lo(D_0070B060)
    /* 2C9E2C 003C9E2C 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2C9E30 003C9E30 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2C9E34 003C9E34 09F84000 */  jalr       $2
    /* 2C9E38 003C9E38 2D200002 */   daddu     $4, $16, $0
    /* 2C9E3C 003C9E3C 01000224 */  addiu      $2, $0, 0x1
  .L003C9E40:
    /* 2C9E40 003C9E40 0C000010 */  b          .L003C9E74
    /* 2C9E44 003C9E44 1000BFDF */   ld        $31, 0x10($29)
  .L003C9E48:
    /* 2C9E48 003C9E48 2D200002 */  daddu      $4, $16, $0
  .L003C9E4C:
    /* 2C9E4C 003C9E4C A0260F0C */  jal        func_003c9a80
    /* 2C9E50 003C9E50 00000000 */   nop
    /* 2C9E54 003C9E54 68120F0C */  jal        func_003c49a0
    /* 2C9E58 003C9E58 10000426 */   addiu     $4, $16, 0x10
    /* 2C9E5C 003C9E5C 03000292 */  lbu        $2, 0x3($16)
    /* 2C9E60 003C9E60 01004230 */  andi       $2, $2, 0x1
    /* 2C9E64 003C9E64 E8FF4010 */  beqz       $2, .L003C9E08
    /* 2C9E68 003C9E68 00000000 */   nop
    /* 2C9E6C 003C9E6C D8FF0010 */  b          .L003C9DD0
    /* 2C9E70 003C9E70 1C00048E */   lw        $4, 0x1C($16)
  .L003C9E74:
    /* 2C9E74 003C9E74 0000B07B */  lq         $16, 0x0($29)
    /* 2C9E78 003C9E78 0800E003 */  jr         $31
    /* 2C9E7C 003C9E7C 2000BD27 */   addiu     $29, $29, 0x20
.size func_003c9d40, 0x140
