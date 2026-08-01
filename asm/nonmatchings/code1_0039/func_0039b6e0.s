.section .text
.set noat
.set noreorder
glabel func_0039b6e0
    /* 29B6E0 0039B6E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 29B6E4 0039B6E4 2D288000 */  daddu      $5, $4, $0
    /* 29B6E8 0039B6E8 8800043C */  lui        $4, %hi(D_00884ACC)
    /* 29B6EC 0039B6EC 0000BFFF */  sd         $31, 0x0($29)
    /* 29B6F0 0039B6F0 DC6E0E0C */  jal        func_0039bb70
    /* 29B6F4 0039B6F4 CC4A8424 */   addiu     $4, $4, %lo(D_00884ACC)
    /* 29B6F8 0039B6F8 03004010 */  beqz       $2, .L0039B708
    /* 29B6FC 0039B6FC 00000000 */   nop
    /* 29B700 0039B700 02000010 */  b          .L0039B70C
    /* 29B704 0039B704 1000428C */   lw        $2, 0x10($2)
  .L0039B708:
    /* 29B708 0039B708 2D100000 */  daddu      $2, $0, $0
  .L0039B70C:
    /* 29B70C 0039B70C 0000BFDF */  ld         $31, 0x0($29)
    /* 29B710 0039B710 0800E003 */  jr         $31
    /* 29B714 0039B714 1000BD27 */   addiu     $29, $29, 0x10
    /* 29B718 0039B718 00000000 */  nop
    /* 29B71C 0039B71C 00000000 */  nop
.size func_0039b6e0, 0x40
