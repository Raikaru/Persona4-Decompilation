.section .text
.set noat
.set noreorder
glabel func_003cc6e0
    /* 2CC6E0 003CC6E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2CC6E4 003CC6E4 0000BFFF */  sd         $31, 0x0($29)
    /* 2CC6E8 003CC6E8 1800838C */  lw         $3, 0x18($4)
    /* 2CC6EC 003CC6EC 03006014 */  bnez       $3, .L003CC6FC
    /* 2CC6F0 003CC6F0 00000000 */   nop
  .L003CC6F4:
    /* 2CC6F4 003CC6F4 07000010 */  b          .L003CC714
    /* 2CC6F8 003CC6F8 0000BFDF */   ld        $31, 0x0($29)
  .L003CC6FC:
    /* 2CC6FC 003CC6FC B4CC0F0C */  jal        func_003f32d0
    /* 2CC700 003CC700 00000000 */   nop
    /* 2CC704 003CC704 B4CC0F0C */  jal        func_003f32d0
    /* 2CC708 003CC708 00000000 */   nop
    /* 2CC70C 003CC70C F9FF0010 */  b          .L003CC6F4
    /* 2CC710 003CC710 00000000 */   nop
  .L003CC714:
    /* 2CC714 003CC714 0800E003 */  jr         $31
    /* 2CC718 003CC718 1000BD27 */   addiu     $29, $29, 0x10
    /* 2CC71C 003CC71C 00000000 */  nop
.size func_003cc6e0, 0x40
