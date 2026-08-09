.section .text
.set noat
.set noreorder
glabel func_0047ddd0
    /* 37DDD0 0047DDD0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 37DDD4 0047DDD4 0000BFFF */  sd         $31, 0x0($29)
    /* 37DDD8 0047DDD8 0400848C */  lw         $4, 0x4($4)
    /* 37DDDC 0047DDDC 03008010 */  beqz       $4, .L0047DDEC
    /* 37DDE0 0047DDE0 00000000 */   nop
    /* 37DDE4 0047DDE4 E0D7120C */  jal        func_004b5f80
    /* 37DDE8 0047DDE8 00000000 */   nop
  .L0047DDEC:
    /* 37DDEC 0047DDEC 0000BFDF */  ld         $31, 0x0($29)
    /* 37DDF0 0047DDF0 1000BD27 */  addiu      $29, $29, 0x10
    /* 37DDF4 0047DDF4 0800E003 */  jr         $31
    /* 37DDF8 0047DDF8 00000000 */   nop
    /* 37DDFC 0047DDFC 00000000 */  nop
.size func_0047ddd0, 0x30
