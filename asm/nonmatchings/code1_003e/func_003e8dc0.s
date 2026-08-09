.section .text
.set noat
.set noreorder
glabel func_003e8dc0
    /* 2E8DC0 003E8DC0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2E8DC4 003E8DC4 8900083C */  lui        $8, %hi(D_0088B2E0)
    /* 2E8DC8 003E8DC8 1000BFFF */  sd         $31, 0x10($29)
    /* 2E8DCC 003E8DCC 7100023C */  lui        $2, %hi(D_0070B7A0)
    /* 2E8DD0 003E8DD0 0000B07F */  sq         $16, 0x0($29)
    /* 2E8DD4 003E8DD4 10000624 */  addiu      $6, $0, 0x10
    /* 2E8DD8 003E8DD8 2D808000 */  daddu      $16, $4, $0
    /* 2E8DDC 003E8DDC C0B785AF */  sw         $5, -0x4840($28)
    /* 2E8DE0 003E8DE0 A0B7448C */  lw         $4, %lo(D_0070B7A0)($2)
    /* 2E8DE4 003E8DE4 E0B20825 */  addiu      $8, $8, %lo(D_0088B2E0)
    /* 2E8DE8 003E8DE8 94AB858F */  lw         $5, -0x546C($28)
    /* 2E8DEC 003E8DEC 98AB878F */  lw         $7, -0x5468($28)
    /* 2E8DF0 003E8DF0 0400023C */  lui        $2, (0x4000E >> 16)
    /* 2E8DF4 003E8DF4 88840F0C */  jal        func_003e1220
    /* 2E8DF8 003E8DF8 0E004934 */   ori       $9, $2, (0x4000E & 0xFFFF)
    /* 2E8DFC 003E8DFC C0B7848F */  lw         $4, -0x4840($28)
    /* 2E8E00 003E8E00 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2E8E04 003E8E04 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2E8E08 003E8E08 21186400 */  addu       $3, $3, $4
    /* 2E8E0C 003E8E0C 000062AC */  sw         $2, 0x0($3)
    /* 2E8E10 003E8E10 0000628C */  lw         $2, 0x0($3)
    /* 2E8E14 003E8E14 03004014 */  bnez       $2, .L003E8E24
    /* 2E8E18 003E8E18 00000000 */   nop
    /* 2E8E1C 003E8E1C 0A000010 */  b          .L003E8E48
    /* 2E8E20 003E8E20 2D100000 */   daddu     $2, $0, $0
  .L003E8E24:
    /* 2E8E24 003E8E24 8800043C */  lui        $4, %hi(D_0088739C)
    /* 2E8E28 003E8E28 8800033C */  lui        $3, %hi(D_008873A0)
    /* 2E8E2C 003E8E2C 9C738424 */  addiu      $4, $4, %lo(D_0088739C)
    /* 2E8E30 003E8E30 2D100002 */  daddu      $2, $16, $0
    /* 2E8E34 003E8E34 A07364AC */  sw         $4, %lo(D_008873A0)($3)
    /* 2E8E38 003E8E38 C4B7838F */  lw         $3, -0x483C($28)
    /* 2E8E3C 003E8E3C 000084AC */  sw         $4, 0x0($4)
    /* 2E8E40 003E8E40 01006324 */  addiu      $3, $3, 0x1
    /* 2E8E44 003E8E44 C4B783AF */  sw         $3, -0x483C($28)
  .L003E8E48:
    /* 2E8E48 003E8E48 1000BFDF */  ld         $31, 0x10($29)
    /* 2E8E4C 003E8E4C 0000B07B */  lq         $16, 0x0($29)
    /* 2E8E50 003E8E50 0800E003 */  jr         $31
    /* 2E8E54 003E8E54 2000BD27 */   addiu     $29, $29, 0x20
    /* 2E8E58 003E8E58 00000000 */  nop
    /* 2E8E5C 003E8E5C 00000000 */  nop
.size func_003e8dc0, 0xa0
