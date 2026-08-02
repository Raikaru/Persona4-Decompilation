.section .text
.set noat
.set noreorder
glabel func_002e29a0
    /* 1E29A0 002E29A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1E29A4 002E29A4 0000BFFF */  sd         $31, 0x0($29)
    /* 1E29A8 002E29A8 8CB5848F */  lw         $4, -0x4A74($28)
    /* 1E29AC 002E29AC 04008010 */  beqz       $4, .L002E29C0
    /* 1E29B0 002E29B0 00000000 */   nop
    /* 1E29B4 002E29B4 2048110C */  jal        func_00452080
    /* 1E29B8 002E29B8 00000000 */   nop
    /* 1E29BC 002E29BC 8CB580AF */  sw         $0, -0x4A74($28)
  .L002E29C0:
    /* 1E29C0 002E29C0 0000BFDF */  ld         $31, 0x0($29)
    /* 1E29C4 002E29C4 1000BD27 */  addiu      $29, $29, 0x10
    /* 1E29C8 002E29C8 0800E003 */  jr         $31
    /* 1E29CC 002E29CC 00000000 */   nop
.size func_002e29a0, 0x30
