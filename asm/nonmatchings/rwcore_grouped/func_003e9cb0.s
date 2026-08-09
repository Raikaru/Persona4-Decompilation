.section .text
.set noat
.set noreorder
glabel func_003e9cb0
    /* 2E9CB0 003E9CB0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2E9CB4 003E9CB4 1000BFFF */  sd         $31, 0x10($29)
    /* 2E9CB8 003E9CB8 0000B07F */  sq         $16, 0x0($29)
    /* 2E9CBC 003E9CBC 2D808000 */  daddu      $16, $4, $0
    /* 2E9CC0 003E9CC0 88830F0C */  jal        func_003e0e20
    /* 2E9CC4 003E9CC4 10000426 */   addiu     $4, $16, 0x10
    /* 2E9CC8 003E9CC8 A000038E */  lw         $3, 0xA0($16)
    /* 2E9CCC 003E9CCC 03006590 */  lbu        $5, 0x3($3)
    /* 2E9CD0 003E9CD0 0300A230 */  andi       $2, $5, 0x3
    /* 2E9CD4 003E9CD4 09004010 */  beqz       $2, .L003E9CFC
    /* 2E9CD8 003E9CD8 00000000 */   nop
  .L003E9CDC:
    /* 2E9CDC 003E9CDC A000038E */  lw         $3, 0xA0($16)
    /* 2E9CE0 003E9CE0 0300A434 */  ori        $4, $5, 0x3
    /* 2E9CE4 003E9CE4 2D100002 */  daddu      $2, $16, $0
    /* 2E9CE8 003E9CE8 030064A0 */  sb         $4, 0x3($3)
    /* 2E9CEC 003E9CEC 03000392 */  lbu        $3, 0x3($16)
    /* 2E9CF0 003E9CF0 0C006334 */  ori        $3, $3, 0xC
    /* 2E9CF4 003E9CF4 0F000010 */  b          .L003E9D34
    /* 2E9CF8 003E9CF8 030003A2 */   sb        $3, 0x3($16)
  .L003E9CFC:
    /* 2E9CFC 003E9CFC 8800043C */  lui        $4, %hi(D_0088739C)
    /* 2E9D00 003E9D00 9C738424 */  addiu      $4, $4, %lo(D_0088739C)
    /* 2E9D04 003E9D04 0000828C */  lw         $2, 0x0($4)
    /* 2E9D08 003E9D08 080062AC */  sw         $2, 0x8($3)
    /* 2E9D0C 003E9D0C A000028E */  lw         $2, 0xA0($16)
    /* 2E9D10 003E9D10 0C0044AC */  sw         $4, 0xC($2)
    /* 2E9D14 003E9D14 A000038E */  lw         $3, 0xA0($16)
    /* 2E9D18 003E9D18 0000828C */  lw         $2, 0x0($4)
    /* 2E9D1C 003E9D1C 08006324 */  addiu      $3, $3, 0x8
    /* 2E9D20 003E9D20 040043AC */  sw         $3, 0x4($2)
    /* 2E9D24 003E9D24 A000028E */  lw         $2, 0xA0($16)
    /* 2E9D28 003E9D28 08004224 */  addiu      $2, $2, 0x8
    /* 2E9D2C 003E9D2C EBFF0010 */  b          .L003E9CDC
    /* 2E9D30 003E9D30 000082AC */   sw        $2, 0x0($4)
  .L003E9D34:
    /* 2E9D34 003E9D34 1000BFDF */  ld         $31, 0x10($29)
    /* 2E9D38 003E9D38 0000B07B */  lq         $16, 0x0($29)
    /* 2E9D3C 003E9D3C 0800E003 */  jr         $31
    /* 2E9D40 003E9D40 2000BD27 */   addiu     $29, $29, 0x20
    /* 2E9D44 003E9D44 00000000 */  nop
    /* 2E9D48 003E9D48 00000000 */  nop
    /* 2E9D4C 003E9D4C 00000000 */  nop
.size func_003e9cb0, 0xa0
