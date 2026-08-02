.section .text
.set noat
.set noreorder
glabel func_004ab680
    /* 3AB680 004AB680 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3AB684 004AB684 1000BFFF */  sd         $31, 0x10($29)
    /* 3AB688 004AB688 0000B07F */  sq         $16, 0x0($29)
    /* 3AB68C 004AB68C 2D808000 */  daddu      $16, $4, $0
    /* 3AB690 004AB690 2000848C */  lw         $4, 0x20($4)
    /* 3AB694 004AB694 0B008010 */  beqz       $4, .L004AB6C4
    /* 3AB698 004AB698 00000000 */   nop
    /* 3AB69C 004AB69C 1800038E */  lw         $3, 0x18($16)
    /* 3AB6A0 004AB6A0 40100300 */  sll        $2, $3, 1
    /* 3AB6A4 004AB6A4 21104300 */  addu       $2, $2, $3
    /* 3AB6A8 004AB6A8 C0180200 */  sll        $3, $2, 3
    /* 3AB6AC 004AB6AC 7100023C */  lui        $2, %hi(D_00714464)
    /* 3AB6B0 004AB6B0 64444224 */  addiu      $2, $2, %lo(D_00714464)
    /* 3AB6B4 004AB6B4 21104300 */  addu       $2, $2, $3
    /* 3AB6B8 004AB6B8 0000428C */  lw         $2, 0x0($2)
    /* 3AB6BC 004AB6BC 09F84000 */  jalr       $2
    /* 3AB6C0 004AB6C0 00000000 */   nop
  .L004AB6C4:
    /* 3AB6C4 004AB6C4 2800048E */  lw         $4, 0x28($16)
    /* 3AB6C8 004AB6C8 03008010 */  beqz       $4, .L004AB6D8
    /* 3AB6CC 004AB6CC 00000000 */   nop
    /* 3AB6D0 004AB6D0 9CAE120C */  jal        func_004aba70
    /* 3AB6D4 004AB6D4 00000000 */   nop
  .L004AB6D8:
    /* 3AB6D8 004AB6D8 2D200002 */  daddu      $4, $16, $0
    /* 3AB6DC 004AB6DC 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 3AB6E0 004AB6E0 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 3AB6E4 004AB6E4 09F84000 */  jalr       $2
    /* 3AB6E8 004AB6E8 00000000 */   nop
    /* 3AB6EC 004AB6EC 1000BFDF */  ld         $31, 0x10($29)
    /* 3AB6F0 004AB6F0 0000B07B */  lq         $16, 0x0($29)
    /* 3AB6F4 004AB6F4 2000BD27 */  addiu      $29, $29, 0x20
    /* 3AB6F8 004AB6F8 0800E003 */  jr         $31
    /* 3AB6FC 004AB6FC 00000000 */   nop
.size func_004ab680, 0x80
