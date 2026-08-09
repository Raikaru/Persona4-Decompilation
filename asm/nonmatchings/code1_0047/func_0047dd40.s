.section .text
.set noat
.set noreorder
glabel func_0047dd40
    /* 37DD40 0047DD40 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 37DD44 0047DD44 0000BFFF */  sd         $31, 0x0($29)
    /* 37DD48 0047DD48 0400848C */  lw         $4, 0x4($4)
    /* 37DD4C 0047DD4C 03008010 */  beqz       $4, .L0047DD5C
    /* 37DD50 0047DD50 00000000 */   nop
    /* 37DD54 0047DD54 00D6120C */  jal        func_004b5800
    /* 37DD58 0047DD58 00000000 */   nop
  .L0047DD5C:
    /* 37DD5C 0047DD5C 0000BFDF */  ld         $31, 0x0($29)
    /* 37DD60 0047DD60 1000BD27 */  addiu      $29, $29, 0x10
    /* 37DD64 0047DD64 0800E003 */  jr         $31
    /* 37DD68 0047DD68 00000000 */   nop
    /* 37DD6C 0047DD6C 00000000 */  nop
.size func_0047dd40, 0x30
