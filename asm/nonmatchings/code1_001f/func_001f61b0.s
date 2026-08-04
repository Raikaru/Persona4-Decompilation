.section .text
.set noat
.set noreorder
glabel func_001f61b0
    /* F61B0 001F61B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* F61B4 001F61B4 0000BFFF */  sd         $31, 0x0($29)
    /* F61B8 001F61B8 ACB3828F */  lw         $2, -0x4C54($28)
    /* F61BC 001F61BC 540A448C */  lw         $4, 0xA54($2)
    /* F61C0 001F61C0 0B008010 */  beqz       $4, .L001F61F0
    /* F61C4 001F61C4 00000000 */   nop
    /* F61C8 001F61C8 F452110C */  jal        func_00454bd0
    /* F61CC 001F61CC 00000000 */   nop
    /* F61D0 001F61D0 ACB3828F */  lw         $2, -0x4C54($28)
    /* F61D4 001F61D4 540A40AC */  sw         $0, 0xA54($2)
    /* F61D8 001F61D8 ACB3848F */  lw         $4, -0x4C54($28)
    /* F61DC 001F61DC 0C00838C */  lw         $3, 0xC($4)
    /* F61E0 001F61E0 FFFE023C */  lui        $2, (0xFEFFFFFF >> 16)
    /* F61E4 001F61E4 FFFF4234 */  ori        $2, $2, (0xFEFFFFFF & 0xFFFF)
    /* F61E8 001F61E8 24106200 */  and        $2, $3, $2
    /* F61EC 001F61EC 0C0082AC */  sw         $2, 0xC($4)
  .L001F61F0:
    /* F61F0 001F61F0 ACB3838F */  lw         $3, -0x4C54($28)
    /* F61F4 001F61F4 4E0A6294 */  lhu        $2, 0xA4E($3)
    /* F61F8 001F61F8 FEFF4230 */  andi       $2, $2, 0xFFFE
    /* F61FC 001F61FC 4E0A62A4 */  sh         $2, 0xA4E($3)
    /* F6200 001F6200 F0F40A0C */  jal        func_002bd3c0
    /* F6204 001F6204 00000000 */   nop
    /* F6208 001F6208 0000BFDF */  ld         $31, 0x0($29)
    /* F620C 001F620C 1000BD27 */  addiu      $29, $29, 0x10
    /* F6210 001F6210 0800E003 */  jr         $31
    /* F6214 001F6214 00000000 */   nop
    /* F6218 001F6218 00000000 */  nop
    /* F621C 001F621C 00000000 */  nop
.size func_001f61b0, 0x70
