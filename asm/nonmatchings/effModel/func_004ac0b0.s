.section .text
.set noat
.set noreorder
glabel func_004ac0b0
    /* 3AC0B0 004AC0B0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3AC0B4 004AC0B4 1000BFFF */  sd         $31, 0x10($29)
    /* 3AC0B8 004AC0B8 0000B07F */  sq         $16, 0x0($29)
    /* 3AC0BC 004AC0BC 2D808000 */  daddu      $16, $4, $0
    /* 3AC0C0 004AC0C0 9400848C */  lw         $4, 0x94($4)
    /* 3AC0C4 004AC0C4 03008010 */  beqz       $4, .L004AC0D4
    /* 3AC0C8 004AC0C8 00000000 */   nop
    /* 3AC0CC 004AC0CC F8E1110C */  jal        func_004787e0
    /* 3AC0D0 004AC0D0 00000000 */   nop
  .L004AC0D4:
    /* 3AC0D4 004AC0D4 2D200002 */  daddu      $4, $16, $0
    /* 3AC0D8 004AC0D8 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 3AC0DC 004AC0DC EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 3AC0E0 004AC0E0 09F84000 */  jalr       $2
    /* 3AC0E4 004AC0E4 00000000 */   nop
    /* 3AC0E8 004AC0E8 1000BFDF */  ld         $31, 0x10($29)
    /* 3AC0EC 004AC0EC 0000B07B */  lq         $16, 0x0($29)
    /* 3AC0F0 004AC0F0 2000BD27 */  addiu      $29, $29, 0x20
    /* 3AC0F4 004AC0F4 0800E003 */  jr         $31
    /* 3AC0F8 004AC0F8 00000000 */   nop
    /* 3AC0FC 004AC0FC 00000000 */  nop
.size func_004ac0b0, 0x50
