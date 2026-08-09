.section .text
.set noat
.set noreorder
glabel func_001f9c40
    /* F9C40 001F9C40 F0FFBD27 */  addiu      $29, $29, -0x10
    /* F9C44 001F9C44 0000BFFF */  sd         $31, 0x0($29)
    /* F9C48 001F9C48 ACB3838F */  lw         $3, -0x4C54($28)
    /* F9C4C 001F9C4C 340B648C */  lw         $4, 0xB34($3)
    /* F9C50 001F9C50 0B008010 */  beqz       $4, .L001F9C80
    /* F9C54 001F9C54 00000000 */   nop
    /* F9C58 001F9C58 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* F9C5C 001F9C5C EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* F9C60 001F9C60 09F84000 */  jalr       $2
    /* F9C64 001F9C64 00000000 */   nop
    /* F9C68 001F9C68 ACB3838F */  lw         $3, -0x4C54($28)
    /* F9C6C 001F9C6C 340B60AC */  sw         $0, 0xB34($3)
    /* F9C70 001F9C70 ACB3848F */  lw         $4, -0x4C54($28)
    /* F9C74 001F9C74 2E0B8394 */  lhu        $3, 0xB2E($4)
    /* F9C78 001F9C78 FEFF6330 */  andi       $3, $3, 0xFFFE
    /* F9C7C 001F9C7C 2E0B83A4 */  sh         $3, 0xB2E($4)
  .L001F9C80:
    /* F9C80 001F9C80 ACB3838F */  lw         $3, -0x4C54($28)
    /* F9C84 001F9C84 3C0B648C */  lw         $4, 0xB3C($3)
    /* F9C88 001F9C88 0B008010 */  beqz       $4, .L001F9CB8
    /* F9C8C 001F9C8C 00000000 */   nop
    /* F9C90 001F9C90 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* F9C94 001F9C94 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* F9C98 001F9C98 09F84000 */  jalr       $2
    /* F9C9C 001F9C9C 00000000 */   nop
    /* F9CA0 001F9CA0 ACB3838F */  lw         $3, -0x4C54($28)
    /* F9CA4 001F9CA4 3C0B60AC */  sw         $0, 0xB3C($3)
    /* F9CA8 001F9CA8 ACB3848F */  lw         $4, -0x4C54($28)
    /* F9CAC 001F9CAC 380B8394 */  lhu        $3, 0xB38($4)
    /* F9CB0 001F9CB0 FEFF6330 */  andi       $3, $3, 0xFFFE
    /* F9CB4 001F9CB4 380B83A4 */  sh         $3, 0xB38($4)
  .L001F9CB8:
    /* F9CB8 001F9CB8 0000BFDF */  ld         $31, 0x0($29)
    /* F9CBC 001F9CBC 1000BD27 */  addiu      $29, $29, 0x10
    /* F9CC0 001F9CC0 0800E003 */  jr         $31
    /* F9CC4 001F9CC4 00000000 */   nop
    /* F9CC8 001F9CC8 00000000 */  nop
    /* F9CCC 001F9CCC 00000000 */  nop
.size func_001f9c40, 0x90
