.section .text
.set noat
.set noreorder
glabel func_003bbb60
    /* 2BBB60 003BBB60 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2BBB64 003BBB64 1000BFFF */  sd         $31, 0x10($29)
    /* 2BBB68 003BBB68 0000B07F */  sq         $16, 0x0($29)
    /* 2BBB6C 003BBB6C 2D808000 */  daddu      $16, $4, $0
    /* 2BBB70 003BBB70 1400848C */  lw         $4, 0x14($4)
    /* 2BBB74 003BBB74 06008010 */  beqz       $4, .L003BBB90
    /* 2BBB78 003BBB78 00000000 */   nop
    /* 2BBB7C 003BBB7C 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2BBB80 003BBB80 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2BBB84 003BBB84 09F84000 */  jalr       $2
    /* 2BBB88 003BBB88 00000000 */   nop
    /* 2BBB8C 003BBB8C 140000AE */  sw         $0, 0x14($16)
  .L003BBB90:
    /* 2BBB90 003BBB90 1000048E */  lw         $4, 0x10($16)
    /* 2BBB94 003BBB94 06008010 */  beqz       $4, .L003BBBB0
    /* 2BBB98 003BBB98 00000000 */   nop
    /* 2BBB9C 003BBB9C 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2BBBA0 003BBBA0 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2BBBA4 003BBBA4 09F84000 */  jalr       $2
    /* 2BBBA8 003BBBA8 00000000 */   nop
    /* 2BBBAC 003BBBAC 100000AE */  sw         $0, 0x10($16)
  .L003BBBB0:
    /* 2BBBB0 003BBBB0 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2BBBB4 003BBBB4 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2BBBB8 003BBBB8 09F84000 */  jalr       $2
    /* 2BBBBC 003BBBBC 2D200002 */   daddu     $4, $16, $0
    /* 2BBBC0 003BBBC0 1000BFDF */  ld         $31, 0x10($29)
    /* 2BBBC4 003BBBC4 01000224 */  addiu      $2, $0, 0x1
    /* 2BBBC8 003BBBC8 0000B07B */  lq         $16, 0x0($29)
    /* 2BBBCC 003BBBCC 0800E003 */  jr         $31
    /* 2BBBD0 003BBBD0 2000BD27 */   addiu     $29, $29, 0x20
    /* 2BBBD4 003BBBD4 00000000 */  nop
    /* 2BBBD8 003BBBD8 00000000 */  nop
    /* 2BBBDC 003BBBDC 00000000 */  nop
.size func_003bbb60, 0x80
