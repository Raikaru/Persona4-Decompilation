.section .text
.set noat
.set noreorder
glabel func_003e1ea0
    /* 2E1EA0 003E1EA0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2E1EA4 003E1EA4 1000BFFF */  sd         $31, 0x10($29)
    /* 2E1EA8 003E1EA8 0000B07F */  sq         $16, 0x0($29)
    /* 2E1EAC 003E1EAC 1400828C */  lw         $2, 0x14($4)
    /* 2E1EB0 003E1EB0 03004010 */  beqz       $2, .L003E1EC0
    /* 2E1EB4 003E1EB4 2D808000 */   daddu     $16, $4, $0
    /* 2E1EB8 003E1EB8 09F84000 */  jalr       $2
    /* 2E1EBC 003E1EBC 00000000 */   nop
  .L003E1EC0:
    /* 2E1EC0 003E1EC0 1000028E */  lw         $2, 0x10($16)
    /* 2E1EC4 003E1EC4 02004010 */  beqz       $2, .L003E1ED0
    /* 2E1EC8 003E1EC8 00000000 */   nop
    /* 2E1ECC 003E1ECC 000040AC */  sw         $0, 0x0($2)
  .L003E1ED0:
    /* 2E1ED0 003E1ED0 0000058E */  lw         $5, 0x0($16)
    /* 2E1ED4 003E1ED4 1200A010 */  beqz       $5, .L003E1F20
    /* 2E1ED8 003E1ED8 00000000 */   nop
    /* 2E1EDC 003E1EDC 0400038E */  lw         $3, 0x4($16)
    /* 2E1EE0 003E1EE0 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2E1EE4 003E1EE4 E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2E1EE8 003E1EE8 2D200002 */  daddu      $4, $16, $0
    /* 2E1EEC 003E1EEC 000065AC */  sw         $5, 0x0($3)
    /* 2E1EF0 003E1EF0 0400058E */  lw         $5, 0x4($16)
    /* 2E1EF4 003E1EF4 0000038E */  lw         $3, 0x0($16)
    /* 2E1EF8 003E1EF8 040065AC */  sw         $5, 0x4($3)
    /* 2E1EFC 003E1EFC 80B7838F */  lw         $3, -0x4880($28)
    /* 2E1F00 003E1F00 0800058E */  lw         $5, 0x8($16)
    /* 2E1F04 003E1F04 21184300 */  addu       $3, $2, $3
    /* 2E1F08 003E1F08 0400628C */  lw         $2, 0x4($3)
    /* 2E1F0C 003E1F0C 23104500 */  subu       $2, $2, $5
    /* 2E1F10 003E1F10 48910F0C */  jal        func_003e4520
    /* 2E1F14 003E1F14 040062AC */   sw        $2, 0x4($3)
  .L003E1F18:
    /* 2E1F18 003E1F18 07000010 */  b          .L003E1F38
    /* 2E1F1C 003E1F1C 01000224 */   addiu     $2, $0, 0x1
  .L003E1F20:
    /* 2E1F20 003E1F20 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2E1F24 003E1F24 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2E1F28 003E1F28 09F84000 */  jalr       $2
    /* 2E1F2C 003E1F2C 2D200002 */   daddu     $4, $16, $0
    /* 2E1F30 003E1F30 F9FF0010 */  b          .L003E1F18
    /* 2E1F34 003E1F34 00000000 */   nop
  .L003E1F38:
    /* 2E1F38 003E1F38 1000BFDF */  ld         $31, 0x10($29)
    /* 2E1F3C 003E1F3C 0000B07B */  lq         $16, 0x0($29)
    /* 2E1F40 003E1F40 0800E003 */  jr         $31
    /* 2E1F44 003E1F44 2000BD27 */   addiu     $29, $29, 0x20
    /* 2E1F48 003E1F48 00000000 */  nop
    /* 2E1F4C 003E1F4C 00000000 */  nop
.size func_003e1ea0, 0xb0
