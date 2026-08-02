.section .text
.set noat
.set noreorder
glabel func_004aba70
    /* 3ABA70 004ABA70 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3ABA74 004ABA74 1000BFFF */  sd         $31, 0x10($29)
    /* 3ABA78 004ABA78 0000B07F */  sq         $16, 0x0($29)
    /* 3ABA7C 004ABA7C 2D808000 */  daddu      $16, $4, $0
    /* 3ABA80 004ABA80 0400838C */  lw         $3, 0x4($4)
    /* 3ABA84 004ABA84 06006014 */  bnez       $3, .L004ABAA0
    /* 3ABA88 004ABA88 00000000 */   nop
    /* 3ABA8C 004ABA8C 7100043C */  lui        $4, %hi(D_00714380)
    /* 3ABA90 004ABA90 80438424 */  addiu      $4, $4, %lo(D_00714380)
    /* 3ABA94 004ABA94 C5070524 */  addiu      $5, $0, 0x7C5
    /* 3ABA98 004ABA98 CCB5110C */  jal        func_0046d730
    /* 3ABA9C 004ABA9C 00000000 */   nop
  .L004ABAA0:
    /* 3ABAA0 004ABAA0 0400038E */  lw         $3, 0x4($16)
    /* 3ABAA4 004ABAA4 FFFF6324 */  addiu      $3, $3, -0x1
    /* 3ABAA8 004ABAA8 040003AE */  sw         $3, 0x4($16)
    /* 3ABAAC 004ABAAC 0D006014 */  bnez       $3, .L004ABAE4
    /* 3ABAB0 004ABAB0 00000000 */   nop
    /* 3ABAB4 004ABAB4 0000038E */  lw         $3, 0x0($16)
    /* 3ABAB8 004ABAB8 04000224 */  addiu      $2, $0, 0x4
    /* 3ABABC 004ABABC 04006210 */  beq        $3, $2, .L004ABAD0
    /* 3ABAC0 004ABAC0 00000000 */   nop
    /* 3ABAC4 004ABAC4 0800048E */  lw         $4, 0x8($16)
    /* 3ABAC8 004ABAC8 E8BC0F0C */  jal        func_003ef3a0
    /* 3ABACC 004ABACC 00000000 */   nop
  .L004ABAD0:
    /* 3ABAD0 004ABAD0 2D200002 */  daddu      $4, $16, $0
    /* 3ABAD4 004ABAD4 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 3ABAD8 004ABAD8 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 3ABADC 004ABADC 09F84000 */  jalr       $2
    /* 3ABAE0 004ABAE0 00000000 */   nop
  .L004ABAE4:
    /* 3ABAE4 004ABAE4 1000BFDF */  ld         $31, 0x10($29)
    /* 3ABAE8 004ABAE8 0000B07B */  lq         $16, 0x0($29)
    /* 3ABAEC 004ABAEC 2000BD27 */  addiu      $29, $29, 0x20
    /* 3ABAF0 004ABAF0 0800E003 */  jr         $31
    /* 3ABAF4 004ABAF4 00000000 */   nop
    /* 3ABAF8 004ABAF8 00000000 */  nop
    /* 3ABAFC 004ABAFC 00000000 */  nop
.size func_004aba70, 0x90
