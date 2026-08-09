.section .text
.set noat
.set noreorder
glabel func_0051eb30
    /* 41EB30 0051EB30 000080AC */  sw         $0, 0x0($4)
    /* 41EB34 0051EB34 10000524 */  addiu      $5, $0, 0x10
    /* 41EB38 0051EB38 040080AC */  sw         $0, 0x4($4)
    /* 41EB3C 0051EB3C 10008824 */  addiu      $8, $4, 0x10
    /* 41EB40 0051EB40 080080AC */  sw         $0, 0x8($4)
    /* 41EB44 0051EB44 0C008724 */  addiu      $7, $4, 0xC
    /* 41EB48 0051EB48 0C0080AC */  sw         $0, 0xC($4)
    /* 41EB4C 0051EB4C 0F000624 */  addiu      $6, $0, 0xF
    /* 41EB50 0051EB50 100080AC */  sw         $0, 0x10($4)
    /* 41EB54 0051EB54 140080AC */  sw         $0, 0x14($4)
    /* 41EB58 0051EB58 180080AC */  sw         $0, 0x18($4)
    /* 41EB5C 0051EB5C 00000000 */  nop
  .L0051EB60:
    /* 41EB60 0051EB60 2110E500 */  addu       $2, $7, $5
    /* 41EB64 0051EB64 21180501 */  addu       $3, $8, $5
    /* 41EB68 0051EB68 FFFFC624 */  addiu      $6, $6, -0x1
    /* 41EB6C 0051EB6C 000040AC */  sw         $0, 0x0($2)
    /* 41EB70 0051EB70 000060AC */  sw         $0, 0x0($3)
    /* 41EB74 0051EB74 FAFFC104 */  bgez       $6, .L0051EB60
    /* 41EB78 0051EB78 0800A524 */   addiu     $5, $5, 0x8
    /* 41EB7C 0051EB7C 0800E003 */  jr         $31
    /* 41EB80 0051EB80 00000000 */   nop
    /* 41EB84 0051EB84 00000000 */  nop
.size func_0051eb30, 0x58
