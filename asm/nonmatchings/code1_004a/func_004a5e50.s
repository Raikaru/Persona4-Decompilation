.section .text
.set noat
.set noreorder
glabel func_004a5e50
    /* 3A5E50 004A5E50 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3A5E54 004A5E54 2000BFFF */  sd         $31, 0x20($29)
    /* 3A5E58 004A5E58 1000B17F */  sq         $17, 0x10($29)
    /* 3A5E5C 004A5E5C 0000B07F */  sq         $16, 0x0($29)
    /* 3A5E60 004A5E60 2D888000 */  daddu      $17, $4, $0
    /* 3A5E64 004A5E64 2D200000 */  daddu      $4, $0, $0
    /* 3A5E68 004A5E68 EC96120C */  jal        func_004a5bb0
    /* 3A5E6C 004A5E6C 00000000 */   nop
    /* 3A5E70 004A5E70 2D804000 */  daddu      $16, $2, $0
    /* 3A5E74 004A5E74 C800248E */  lw         $4, 0xC8($17)
    /* 3A5E78 004A5E78 9C0C120C */  jal        func_00483270
    /* 3A5E7C 004A5E7C 00000000 */   nop
    /* 3A5E80 004A5E80 C80002AE */  sw         $2, 0xC8($16)
    /* 3A5E84 004A5E84 1000428C */  lw         $2, 0x10($2)
    /* 3A5E88 004A5E88 1800428C */  lw         $2, 0x18($2)
    /* 3A5E8C 004A5E8C 3000438C */  lw         $3, 0x30($2)
    /* 3A5E90 004A5E90 FFFF0224 */  addiu      $2, $0, -0x1
    /* 3A5E94 004A5E94 000062AC */  sw         $2, 0x0($3)
    /* 3A5E98 004A5E98 040062AC */  sw         $2, 0x4($3)
    /* 3A5E9C 004A5E9C 080062AC */  sw         $2, 0x8($3)
    /* 3A5EA0 004A5EA0 0C0062AC */  sw         $2, 0xC($3)
    /* 3A5EA4 004A5EA4 30000426 */  addiu      $4, $16, 0x30
    /* 3A5EA8 004A5EA8 30002526 */  addiu      $5, $17, 0x30
    /* 3A5EAC 004A5EAC 98000624 */  addiu      $6, $0, 0x98
    /* 3A5EB0 004A5EB0 04FE100C */  jal        func_0043f810
    /* 3A5EB4 004A5EB4 00000000 */   nop
    /* 3A5EB8 004A5EB8 2D200002 */  daddu      $4, $16, $0
    /* 3A5EBC 004A5EBC 2D282002 */  daddu      $5, $17, $0
    /* 3A5EC0 004A5EC0 BC97120C */  jal        func_004a5ef0
    /* 3A5EC4 004A5EC4 00000000 */   nop
    /* 3A5EC8 004A5EC8 2D100002 */  daddu      $2, $16, $0
    /* 3A5ECC 004A5ECC 2000BFDF */  ld         $31, 0x20($29)
    /* 3A5ED0 004A5ED0 1000B17B */  lq         $17, 0x10($29)
    /* 3A5ED4 004A5ED4 0000B07B */  lq         $16, 0x0($29)
    /* 3A5ED8 004A5ED8 3000BD27 */  addiu      $29, $29, 0x30
    /* 3A5EDC 004A5EDC 0800E003 */  jr         $31
    /* 3A5EE0 004A5EE0 00000000 */   nop
    /* 3A5EE4 004A5EE4 00000000 */  nop
    /* 3A5EE8 004A5EE8 00000000 */  nop
    /* 3A5EEC 004A5EEC 00000000 */  nop
.size func_004a5e50, 0xa0
