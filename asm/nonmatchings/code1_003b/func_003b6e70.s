.section .text
.set noat
.set noreorder
glabel func_003b6e70
    /* 2B6E70 003B6E70 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2B6E74 003B6E74 0400023C */  lui        $2, (0x4010C >> 16)
    /* 2B6E78 003B6E78 1000BFFF */  sd         $31, 0x10($29)
    /* 2B6E7C 003B6E7C 0C014534 */  ori        $5, $2, (0x4010C & 0xFFFF)
    /* 2B6E80 003B6E80 0000B07F */  sq         $16, 0x0($29)
    /* 2B6E84 003B6E84 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 2B6E88 003B6E88 E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 2B6E8C 003B6E8C 2D808000 */  daddu      $16, $4, $0
    /* 2B6E90 003B6E90 09F84000 */  jalr       $2
    /* 2B6E94 003B6E94 7C000424 */   addiu     $4, $0, 0x7C
    /* 2B6E98 003B6E98 18B6848F */  lw         $4, -0x49E8($28)
    /* 2B6E9C 003B6E9C 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2B6EA0 003B6EA0 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2B6EA4 003B6EA4 21286400 */  addu       $5, $3, $4
    /* 2B6EA8 003B6EA8 0000A2AC */  sw         $2, 0x0($5)
    /* 2B6EAC 003B6EAC 0000A28C */  lw         $2, 0x0($5)
    /* 2B6EB0 003B6EB0 0D004010 */  beqz       $2, .L003B6EE8
    /* 2B6EB4 003B6EB4 00000000 */   nop
    /* 2B6EB8 003B6EB8 0C004324 */  addiu      $3, $2, 0xC
    /* 2B6EBC 003B6EBC 319A023C */  lui        $2, (0x9A319039 >> 16)
    /* 2B6EC0 003B6EC0 0400A3AC */  sw         $3, 0x4($5)
    /* 2B6EC4 003B6EC4 39904434 */  ori        $4, $2, (0x9A319039 & 0xFFFF)
    /* 2B6EC8 003B6EC8 0000A28C */  lw         $2, 0x0($5)
    /* 2B6ECC 003B6ECC 0800A2AC */  sw         $2, 0x8($5)
    /* 2B6ED0 003B6ED0 0000A28C */  lw         $2, 0x0($5)
    /* 2B6ED4 003B6ED4 7C004224 */  addiu      $2, $2, 0x7C
    /* 2B6ED8 003B6ED8 C0DB0E0C */  jal        func_003b6f00
    /* 2B6EDC 003B6EDC 0C00A2AC */   sw        $2, 0xC($5)
    /* 2B6EE0 003B6EE0 02000010 */  b          .L003B6EEC
    /* 2B6EE4 003B6EE4 2D100002 */   daddu     $2, $16, $0
  .L003B6EE8:
    /* 2B6EE8 003B6EE8 2D100000 */  daddu      $2, $0, $0
  .L003B6EEC:
    /* 2B6EEC 003B6EEC 1000BFDF */  ld         $31, 0x10($29)
    /* 2B6EF0 003B6EF0 0000B07B */  lq         $16, 0x0($29)
    /* 2B6EF4 003B6EF4 0800E003 */  jr         $31
    /* 2B6EF8 003B6EF8 2000BD27 */   addiu     $29, $29, 0x20
    /* 2B6EFC 003B6EFC 00000000 */  nop
.size func_003b6e70, 0x90
