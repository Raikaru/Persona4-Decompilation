.section .text
.set noat
.set noreorder
glabel func_003e59e0
    /* 2E59E0 003E59E0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2E59E4 003E59E4 1000BFFF */  sd         $31, 0x10($29)
    /* 2E59E8 003E59E8 0000B07F */  sq         $16, 0x0($29)
    /* 2E59EC 003E59EC 0400828C */  lw         $2, 0x4($4)
    /* 2E59F0 003E59F0 03004014 */  bnez       $2, .L003E5A00
    /* 2E59F4 003E59F4 2D808000 */   daddu     $16, $4, $0
  .L003E59F8:
    /* 2E59F8 003E59F8 07000010 */  b          .L003E5A18
    /* 2E59FC 003E59FC 2D100002 */   daddu     $2, $16, $0
  .L003E5A00:
    /* 2E5A00 003E5A00 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2E5A04 003E5A04 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2E5A08 003E5A08 09F84000 */  jalr       $2
    /* 2E5A0C 003E5A0C 0000048E */   lw        $4, 0x0($16)
    /* 2E5A10 003E5A10 F9FF0010 */  b          .L003E59F8
    /* 2E5A14 003E5A14 00000000 */   nop
  .L003E5A18:
    /* 2E5A18 003E5A18 1000BFDF */  ld         $31, 0x10($29)
    /* 2E5A1C 003E5A1C 0000B07B */  lq         $16, 0x0($29)
    /* 2E5A20 003E5A20 0800E003 */  jr         $31
    /* 2E5A24 003E5A24 2000BD27 */   addiu     $29, $29, 0x20
    /* 2E5A28 003E5A28 00000000 */  nop
    /* 2E5A2C 003E5A2C 00000000 */  nop
.size func_003e59e0, 0x50
