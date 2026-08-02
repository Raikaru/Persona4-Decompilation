.section .text
.set noat
.set noreorder
glabel func_004ab140
    /* 3AB140 004AB140 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3AB144 004AB144 1000BFFF */  sd         $31, 0x10($29)
    /* 3AB148 004AB148 0000B07F */  sq         $16, 0x0($29)
    /* 3AB14C 004AB14C 2D808000 */  daddu      $16, $4, $0
    /* 3AB150 004AB150 2000848C */  lw         $4, 0x20($4)
    /* 3AB154 004AB154 0B008010 */  beqz       $4, .L004AB184
    /* 3AB158 004AB158 00000000 */   nop
    /* 3AB15C 004AB15C 1800038E */  lw         $3, 0x18($16)
    /* 3AB160 004AB160 40100300 */  sll        $2, $3, 1
    /* 3AB164 004AB164 21104300 */  addu       $2, $2, $3
    /* 3AB168 004AB168 C0180200 */  sll        $3, $2, 3
    /* 3AB16C 004AB16C 7100023C */  lui        $2, %hi(D_00714394)
    /* 3AB170 004AB170 94434224 */  addiu      $2, $2, %lo(D_00714394)
    /* 3AB174 004AB174 21104300 */  addu       $2, $2, $3
    /* 3AB178 004AB178 0000428C */  lw         $2, 0x0($2)
    /* 3AB17C 004AB17C 09F84000 */  jalr       $2
    /* 3AB180 004AB180 00000000 */   nop
  .L004AB184:
    /* 3AB184 004AB184 2800048E */  lw         $4, 0x28($16)
    /* 3AB188 004AB188 03008010 */  beqz       $4, .L004AB198
    /* 3AB18C 004AB18C 00000000 */   nop
    /* 3AB190 004AB190 9CAE120C */  jal        func_004aba70
    /* 3AB194 004AB194 00000000 */   nop
  .L004AB198:
    /* 3AB198 004AB198 2D200002 */  daddu      $4, $16, $0
    /* 3AB19C 004AB19C 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 3AB1A0 004AB1A0 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 3AB1A4 004AB1A4 09F84000 */  jalr       $2
    /* 3AB1A8 004AB1A8 00000000 */   nop
    /* 3AB1AC 004AB1AC 1000BFDF */  ld         $31, 0x10($29)
    /* 3AB1B0 004AB1B0 0000B07B */  lq         $16, 0x0($29)
    /* 3AB1B4 004AB1B4 2000BD27 */  addiu      $29, $29, 0x20
    /* 3AB1B8 004AB1B8 0800E003 */  jr         $31
    /* 3AB1BC 004AB1BC 00000000 */   nop
.size func_004ab140, 0x80
