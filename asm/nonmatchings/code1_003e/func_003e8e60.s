.section .text
.set noat
.set noreorder
glabel func_003e8e60
    /* 2E8E60 003E8E60 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2E8E64 003E8E64 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2E8E68 003E8E68 1000BFFF */  sd         $31, 0x10($29)
    /* 2E8E6C 003E8E6C E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2E8E70 003E8E70 0000B07F */  sq         $16, 0x0($29)
    /* 2E8E74 003E8E74 C0B7838F */  lw         $3, -0x4840($28)
    /* 2E8E78 003E8E78 2D808000 */  daddu      $16, $4, $0
    /* 2E8E7C 003E8E7C 21104300 */  addu       $2, $2, $3
    /* 2E8E80 003E8E80 0000448C */  lw         $4, 0x0($2)
    /* 2E8E84 003E8E84 08008010 */  beqz       $4, .L003E8EA8
    /* 2E8E88 003E8E88 00000000 */   nop
    /* 2E8E8C 003E8E8C BC840F0C */  jal        func_003e12f0
    /* 2E8E90 003E8E90 00000000 */   nop
    /* 2E8E94 003E8E94 C0B7838F */  lw         $3, -0x4840($28)
    /* 2E8E98 003E8E98 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2E8E9C 003E8E9C E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2E8EA0 003E8EA0 21104300 */  addu       $2, $2, $3
    /* 2E8EA4 003E8EA4 000040AC */  sw         $0, 0x0($2)
  .L003E8EA8:
    /* 2E8EA8 003E8EA8 C4B7838F */  lw         $3, -0x483C($28)
    /* 2E8EAC 003E8EAC 2D100002 */  daddu      $2, $16, $0
    /* 2E8EB0 003E8EB0 FFFF6324 */  addiu      $3, $3, -0x1
    /* 2E8EB4 003E8EB4 C4B783AF */  sw         $3, -0x483C($28)
    /* 2E8EB8 003E8EB8 1000BFDF */  ld         $31, 0x10($29)
    /* 2E8EBC 003E8EBC 0000B07B */  lq         $16, 0x0($29)
    /* 2E8EC0 003E8EC0 0800E003 */  jr         $31
    /* 2E8EC4 003E8EC4 2000BD27 */   addiu     $29, $29, 0x20
    /* 2E8EC8 003E8EC8 00000000 */  nop
    /* 2E8ECC 003E8ECC 00000000 */  nop
.size func_003e8e60, 0x70
