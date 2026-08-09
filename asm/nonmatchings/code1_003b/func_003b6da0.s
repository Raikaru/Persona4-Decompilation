.section .text
.set noat
.set noreorder
glabel func_003b6da0
    /* 2B6DA0 003B6DA0 8800033C */  lui        $3, %hi(D_00885A90)
    /* 2B6DA4 003B6DA4 01008634 */  ori        $6, $4, 0x1
    /* 2B6DA8 003B6DA8 905A6324 */  addiu      $3, $3, %lo(D_00885A90)
    /* 2B6DAC 003B6DAC 7CAA80AF */  sw         $0, -0x5584($28)
    /* 2B6DB0 003B6DB0 04006524 */  addiu      $5, $3, 0x4
    /* 2B6DB4 003B6DB4 70020324 */  addiu      $3, $0, 0x270
    /* 2B6DB8 003B6DB8 FFFF6424 */  addiu      $4, $3, -0x1
    /* 2B6DBC 003B6DBC 8800033C */  lui        $3, %hi(D_00885A90)
    /* 2B6DC0 003B6DC0 0B008010 */  beqz       $4, .L003B6DF0
    /* 2B6DC4 003B6DC4 905A66AC */   sw        $6, %lo(D_00885A90)($3)
    /* 2B6DC8 003B6DC8 0100033C */  lui        $3, (0x10DCD >> 16)
    /* 2B6DCC 003B6DCC CD0D6334 */  ori        $3, $3, (0x10DCD & 0xFFFF)
  .L003B6DD0:
    /* 2B6DD0 003B6DD0 1830C300 */  mult       $6, $6, $3
    /* 2B6DD4 003B6DD4 FFFF8424 */  addiu      $4, $4, -0x1
    /* 2B6DD8 003B6DD8 0000A6AC */  sw         $6, 0x0($5)
    /* 2B6DDC 003B6DDC 0400A524 */  addiu      $5, $5, 0x4
    /* 2B6DE0 003B6DE0 00000000 */  nop
    /* 2B6DE4 003B6DE4 FAFF8014 */  bnez       $4, .L003B6DD0
    /* 2B6DE8 003B6DE8 00000000 */   nop
    /* 2B6DEC 003B6DEC 00000000 */  nop
  .L003B6DF0:
    /* 2B6DF0 003B6DF0 0800E003 */  jr         $31
    /* 2B6DF4 003B6DF4 00000000 */   nop
    /* 2B6DF8 003B6DF8 00000000 */  nop
    /* 2B6DFC 003B6DFC 00000000 */  nop
.size func_003b6da0, 0x60
