.section .text
.set noat
.set noreorder
glabel func_0011fd50
    /* 1FD50 0011FD50 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 1FD54 0011FD54 0000BFFF */  sd         $31, 0x0($29)
    /* 1FD58 0011FD58 1800A4FF */  sd         $4, 0x18($29)
    /* 1FD5C 0011FD5C 2D40E000 */  daddu      $8, $7, $0
    /* 1FD60 0011FD60 0800C78C */  lw         $7, 0x8($6)
    /* 1FD64 0011FD64 03000324 */  addiu      $3, $0, 0x3
    /* 1FD68 0011FD68 1900E310 */  beq        $7, $3, .L0011FDD0
    /* 1FD6C 0011FD6C 00000000 */   nop
    /* 1FD70 0011FD70 02000324 */  addiu      $3, $0, 0x2
    /* 1FD74 0011FD74 1100E310 */  beq        $7, $3, .L0011FDBC
    /* 1FD78 0011FD78 00000000 */   nop
    /* 1FD7C 0011FD7C 01000324 */  addiu      $3, $0, 0x1
    /* 1FD80 0011FD80 0900E310 */  beq        $7, $3, .L0011FDA8
    /* 1FD84 0011FD84 00000000 */   nop
    /* 1FD88 0011FD88 0300E010 */  beqz       $7, .L0011FD98
    /* 1FD8C 0011FD8C 00000000 */   nop
    /* 1FD90 0011FD90 12000010 */  b          .L0011FDDC
    /* 1FD94 0011FD94 00000000 */   nop
  .L0011FD98:
    /* 1FD98 0011FD98 7C7F040C */  jal        func_0011fdf0
    /* 1FD9C 0011FD9C 00000000 */   nop
    /* 1FDA0 0011FDA0 0E000010 */  b          .L0011FDDC
    /* 1FDA4 0011FDA4 00000000 */   nop
  .L0011FDA8:
    /* 1FDA8 0011FDA8 2D380000 */  daddu      $7, $0, $0
    /* 1FDAC 0011FDAC E880040C */  jal        func_001203a0
    /* 1FDB0 0011FDB0 00000000 */   nop
    /* 1FDB4 0011FDB4 09000010 */  b          .L0011FDDC
    /* 1FDB8 0011FDB8 00000000 */   nop
  .L0011FDBC:
    /* 1FDBC 0011FDBC 2D380000 */  daddu      $7, $0, $0
    /* 1FDC0 0011FDC0 E880040C */  jal        func_001203a0
    /* 1FDC4 0011FDC4 00000000 */   nop
    /* 1FDC8 0011FDC8 04000010 */  b          .L0011FDDC
    /* 1FDCC 0011FDCC 00000000 */   nop
  .L0011FDD0:
    /* 1FDD0 0011FDD0 01000724 */  addiu      $7, $0, 0x1
    /* 1FDD4 0011FDD4 E880040C */  jal        func_001203a0
    /* 1FDD8 0011FDD8 00000000 */   nop
  .L0011FDDC:
    /* 1FDDC 0011FDDC 0000BFDF */  ld         $31, 0x0($29)
    /* 1FDE0 0011FDE0 2000BD27 */  addiu      $29, $29, 0x20
    /* 1FDE4 0011FDE4 0800E003 */  jr         $31
    /* 1FDE8 0011FDE8 00000000 */   nop
    /* 1FDEC 0011FDEC 00000000 */  nop
.size func_0011fd50, 0xa0
