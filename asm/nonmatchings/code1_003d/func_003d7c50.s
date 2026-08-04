.section .text
.set noat
.set noreorder
glabel func_003d7c50
    /* 2D7C50 003D7C50 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2D7C54 003D7C54 1000BFFF */  sd         $31, 0x10($29)
    /* 2D7C58 003D7C58 0000B07F */  sq         $16, 0x0($29)
    /* 2D7C5C 003D7C5C 1400838C */  lw         $3, 0x14($4)
    /* 2D7C60 003D7C60 4000628C */  lw         $2, 0x40($3)
    /* 2D7C64 003D7C64 FFFF4224 */  addiu      $2, $2, -0x1
    /* 2D7C68 003D7C68 400062AC */  sw         $2, 0x40($3)
    /* 2D7C6C 003D7C6C 4000628C */  lw         $2, 0x40($3)
    /* 2D7C70 003D7C70 06004010 */  beqz       $2, .L003D7C8C
    /* 2D7C74 003D7C74 2D808000 */   daddu     $16, $4, $0
    /* 2D7C78 003D7C78 2D100000 */  daddu      $2, $0, $0
  .L003D7C7C:
    /* 2D7C7C 003D7C7C 0A004014 */  bnez       $2, .L003D7CA8
    /* 2D7C80 003D7C80 00000000 */   nop
  .L003D7C84:
    /* 2D7C84 003D7C84 0C000010 */  b          .L003D7CB8
    /* 2D7C88 003D7C88 01000224 */   addiu     $2, $0, 0x1
  .L003D7C8C:
    /* 2D7C8C 003D7C8C 8800023C */  lui        $2, %hi(jtbl_008873FC)
    /* 2D7C90 003D7C90 FC73428C */  lw         $2, %lo(jtbl_008873FC)($2)
    /* 2D7C94 003D7C94 1400058E */  lw         $5, 0x14($16)
    /* 2D7C98 003D7C98 09F84000 */  jalr       $2
    /* 2D7C9C 003D7C9C 48B7848F */   lw        $4, -0x48B8($28)
    /* 2D7CA0 003D7CA0 F6FF0010 */  b          .L003D7C7C
    /* 2D7CA4 003D7CA4 01000224 */   addiu     $2, $0, 0x1
  .L003D7CA8:
    /* 2D7CA8 003D7CA8 C0540F0C */  jal        func_003d5300
    /* 2D7CAC 003D7CAC 2D200002 */   daddu     $4, $16, $0
    /* 2D7CB0 003D7CB0 F4FF0010 */  b          .L003D7C84
    /* 2D7CB4 003D7CB4 00000000 */   nop
  .L003D7CB8:
    /* 2D7CB8 003D7CB8 1000BFDF */  ld         $31, 0x10($29)
    /* 2D7CBC 003D7CBC 0000B07B */  lq         $16, 0x0($29)
    /* 2D7CC0 003D7CC0 0800E003 */  jr         $31
    /* 2D7CC4 003D7CC4 2000BD27 */   addiu     $29, $29, 0x20
    /* 2D7CC8 003D7CC8 00000000 */  nop
    /* 2D7CCC 003D7CCC 00000000 */  nop
.size func_003d7c50, 0x80
