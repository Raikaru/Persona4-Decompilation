.section .text
.set noat
.set noreorder
glabel func_004a5de0
    /* 3A5DE0 004A5DE0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3A5DE4 004A5DE4 1000BFFF */  sd         $31, 0x10($29)
    /* 3A5DE8 004A5DE8 0000B07F */  sq         $16, 0x0($29)
    /* 3A5DEC 004A5DEC 2D808000 */  daddu      $16, $4, $0
    /* 3A5DF0 004A5DF0 CC00848C */  lw         $4, 0xCC($4)
    /* 3A5DF4 004A5DF4 03008010 */  beqz       $4, .L004A5E04
    /* 3A5DF8 004A5DF8 00000000 */   nop
    /* 3A5DFC 004A5DFC 700A120C */  jal        func_004829c0
    /* 3A5E00 004A5E00 00000000 */   nop
  .L004A5E04:
    /* 3A5E04 004A5E04 D000048E */  lw         $4, 0xD0($16)
    /* 3A5E08 004A5E08 03008010 */  beqz       $4, .L004A5E18
    /* 3A5E0C 004A5E0C 00000000 */   nop
    /* 3A5E10 004A5E10 B807120C */  jal        func_00481ee0
    /* 3A5E14 004A5E14 00000000 */   nop
  .L004A5E18:
    /* 3A5E18 004A5E18 C800048E */  lw         $4, 0xC8($16)
    /* 3A5E1C 004A5E1C FC0C120C */  jal        func_004833f0
    /* 3A5E20 004A5E20 00000000 */   nop
    /* 3A5E24 004A5E24 2D200002 */  daddu      $4, $16, $0
    /* 3A5E28 004A5E28 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 3A5E2C 004A5E2C EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 3A5E30 004A5E30 09F84000 */  jalr       $2
    /* 3A5E34 004A5E34 00000000 */   nop
    /* 3A5E38 004A5E38 1000BFDF */  ld         $31, 0x10($29)
    /* 3A5E3C 004A5E3C 0000B07B */  lq         $16, 0x0($29)
    /* 3A5E40 004A5E40 2000BD27 */  addiu      $29, $29, 0x20
    /* 3A5E44 004A5E44 0800E003 */  jr         $31
    /* 3A5E48 004A5E48 00000000 */   nop
    /* 3A5E4C 004A5E4C 00000000 */  nop
.size func_004a5de0, 0x70
