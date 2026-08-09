.section .text
.set noat
.set noreorder
glabel func_003c3e90
    /* 2C3E90 003C3E90 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2C3E94 003C3E94 8800083C */  lui        $8, %hi(D_00886550)
    /* 2C3E98 003C3E98 1000BFFF */  sd         $31, 0x10($29)
    /* 2C3E9C 003C3E9C 7100023C */  lui        $2, %hi(D_0070AFD0)
    /* 2C3EA0 003C3EA0 0000B07F */  sq         $16, 0x0($29)
    /* 2C3EA4 003C3EA4 10000624 */  addiu      $6, $0, 0x10
    /* 2C3EA8 003C3EA8 2D808000 */  daddu      $16, $4, $0
    /* 2C3EAC 003C3EAC D0B685AF */  sw         $5, -0x4930($28)
    /* 2C3EB0 003C3EB0 D0AF448C */  lw         $4, %lo(D_0070AFD0)($2)
    /* 2C3EB4 003C3EB4 50650825 */  addiu      $8, $8, %lo(D_00886550)
    /* 2C3EB8 003C3EB8 98AA858F */  lw         $5, -0x5568($28)
    /* 2C3EBC 003C3EBC 9CAA878F */  lw         $7, -0x5564($28)
    /* 2C3EC0 003C3EC0 0400023C */  lui        $2, (0x40012 >> 16)
    /* 2C3EC4 003C3EC4 88840F0C */  jal        func_003e1220
    /* 2C3EC8 003C3EC8 12004934 */   ori       $9, $2, (0x40012 & 0xFFFF)
    /* 2C3ECC 003C3ECC D0B6848F */  lw         $4, -0x4930($28)
    /* 2C3ED0 003C3ED0 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2C3ED4 003C3ED4 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2C3ED8 003C3ED8 21186400 */  addu       $3, $3, $4
    /* 2C3EDC 003C3EDC 000062AC */  sw         $2, 0x0($3)
    /* 2C3EE0 003C3EE0 0000628C */  lw         $2, 0x0($3)
    /* 2C3EE4 003C3EE4 03004014 */  bnez       $2, .L003C3EF4
    /* 2C3EE8 003C3EE8 00000000 */   nop
    /* 2C3EEC 003C3EEC 05000010 */  b          .L003C3F04
    /* 2C3EF0 003C3EF0 2D100000 */   daddu     $2, $0, $0
  .L003C3EF4:
    /* 2C3EF4 003C3EF4 D4B6838F */  lw         $3, -0x492C($28)
    /* 2C3EF8 003C3EF8 2D100002 */  daddu      $2, $16, $0
    /* 2C3EFC 003C3EFC 01006324 */  addiu      $3, $3, 0x1
    /* 2C3F00 003C3F00 D4B683AF */  sw         $3, -0x492C($28)
  .L003C3F04:
    /* 2C3F04 003C3F04 1000BFDF */  ld         $31, 0x10($29)
    /* 2C3F08 003C3F08 0000B07B */  lq         $16, 0x0($29)
    /* 2C3F0C 003C3F0C 0800E003 */  jr         $31
    /* 2C3F10 003C3F10 2000BD27 */   addiu     $29, $29, 0x20
    /* 2C3F14 003C3F14 00000000 */  nop
    /* 2C3F18 003C3F18 00000000 */  nop
    /* 2C3F1C 003C3F1C 00000000 */  nop
.size func_003c3e90, 0x90
