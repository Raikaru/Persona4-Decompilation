.section .text
.set noat
.set noreorder
glabel func_0019fa40
    /* 9FA40 0019FA40 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 9FA44 0019FA44 1000BFFF */  sd         $31, 0x10($29)
    /* 9FA48 0019FA48 0000B07F */  sq         $16, 0x0($29)
    /* 9FA4C 0019FA4C ACB3838F */  lw         $3, -0x4C54($28)
    /* 9FA50 0019FA50 7401708C */  lw         $16, 0x174($3)
    /* 9FA54 0019FA54 1E000010 */  b          .L0019FAD0
    /* 9FA58 0019FA58 00000000 */   nop
  .L0019FA5C:
    /* 9FA5C 0019FA5C 1A000496 */  lhu        $4, 0x1A($16)
    /* 9FA60 0019FA60 00028330 */  andi       $3, $4, 0x200
    /* 9FA64 0019FA64 19006010 */  beqz       $3, .L0019FACC
    /* 9FA68 0019FA68 00000000 */   nop
    /* 9FA6C 0019FA6C 01008330 */  andi       $3, $4, 0x1
    /* 9FA70 0019FA70 16006010 */  beqz       $3, .L0019FACC
    /* 9FA74 0019FA74 00000000 */   nop
    /* 9FA78 0019FA78 3000048E */  lw         $4, 0x30($16)
    /* 9FA7C 0019FA7C 9C00838C */  lw         $3, 0x9C($4)
    /* 9FA80 0019FA80 08006330 */  andi       $3, $3, 0x8
    /* 9FA84 0019FA84 11006010 */  beqz       $3, .L0019FACC
    /* 9FA88 0019FA88 00000000 */   nop
    /* 9FA8C 0019FA8C D45A060C */  jal        func_00196b50
    /* 9FA90 0019FA90 00000000 */   nop
    /* 9FA94 0019FA94 0D004014 */  bnez       $2, .L0019FACC
    /* 9FA98 0019FA98 00000000 */   nop
    /* 9FA9C 0019FA9C 0C000496 */  lhu        $4, 0xC($16)
    /* 9FAA0 0019FAA0 05000324 */  addiu      $3, $0, 0x5
    /* 9FAA4 0019FAA4 06008310 */  beq        $4, $3, .L0019FAC0
    /* 9FAA8 0019FAA8 00000000 */   nop
    /* 9FAAC 0019FAAC 01000324 */  addiu      $3, $0, 0x1
    /* 9FAB0 0019FAB0 03008310 */  beq        $4, $3, .L0019FAC0
    /* 9FAB4 0019FAB4 00000000 */   nop
    /* 9FAB8 0019FAB8 04000010 */  b          .L0019FACC
    /* 9FABC 0019FABC 00000000 */   nop
  .L0019FAC0:
    /* 9FAC0 0019FAC0 2D200002 */  daddu      $4, $16, $0
    /* 9FAC4 0019FAC4 287E060C */  jal        func_0019f8a0
    /* 9FAC8 0019FAC8 00000000 */   nop
  .L0019FACC:
    /* 9FACC 0019FACC 5004108E */  lw         $16, 0x450($16)
  .L0019FAD0:
    /* 9FAD0 0019FAD0 E2FF0016 */  bnez       $16, .L0019FA5C
    /* 9FAD4 0019FAD4 00000000 */   nop
    /* 9FAD8 0019FAD8 1000BFDF */  ld         $31, 0x10($29)
    /* 9FADC 0019FADC 0000B07B */  lq         $16, 0x0($29)
    /* 9FAE0 0019FAE0 2000BD27 */  addiu      $29, $29, 0x20
    /* 9FAE4 0019FAE4 0800E003 */  jr         $31
    /* 9FAE8 0019FAE8 00000000 */   nop
    /* 9FAEC 0019FAEC 00000000 */  nop
.size func_0019fa40, 0xb0
