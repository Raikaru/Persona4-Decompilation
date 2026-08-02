.section .text
.set noat
.set noreorder
glabel func_002aa2b0
    /* 1AA2B0 002AA2B0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 1AA2B4 002AA2B4 1000BFFF */  sd         $31, 0x10($29)
    /* 1AA2B8 002AA2B8 0000B07F */  sq         $16, 0x0($29)
    /* 1AA2BC 002AA2BC 2D808000 */  daddu      $16, $4, $0
    /* 1AA2C0 002AA2C0 A403848C */  lw         $4, 0x3A4($4)
    /* 1AA2C4 002AA2C4 04008010 */  beqz       $4, .L002AA2D8
    /* 1AA2C8 002AA2C8 00000000 */   nop
    /* 1AA2CC 002AA2CC F452110C */  jal        func_00454bd0
    /* 1AA2D0 002AA2D0 00000000 */   nop
    /* 1AA2D4 002AA2D4 A40300AE */  sw         $0, 0x3A4($16)
  .L002AA2D8:
    /* 1AA2D8 002AA2D8 2D200002 */  daddu      $4, $16, $0
    /* 1AA2DC 002AA2DC 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 1AA2E0 002AA2E0 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 1AA2E4 002AA2E4 09F84000 */  jalr       $2
    /* 1AA2E8 002AA2E8 00000000 */   nop
    /* 1AA2EC 002AA2EC 1000BFDF */  ld         $31, 0x10($29)
    /* 1AA2F0 002AA2F0 0000B07B */  lq         $16, 0x0($29)
    /* 1AA2F4 002AA2F4 2000BD27 */  addiu      $29, $29, 0x20
    /* 1AA2F8 002AA2F8 0800E003 */  jr         $31
    /* 1AA2FC 002AA2FC 00000000 */   nop
.size func_002aa2b0, 0x50
