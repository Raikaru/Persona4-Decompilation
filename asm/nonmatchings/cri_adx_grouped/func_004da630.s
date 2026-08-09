.section .text
.set noat
.set noreorder
glabel func_004da630
    /* 3DA630 004DA630 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3DA634 004DA634 0800B1FF */  sd         $17, 0x8($29)
    /* 3DA638 004DA638 2D88A000 */  daddu      $17, $5, $0
    /* 3DA63C 004DA63C 01000524 */  addiu      $5, $0, 0x1
    /* 3DA640 004DA640 0000B0FF */  sd         $16, 0x0($29)
    /* 3DA644 004DA644 1000BFFF */  sd         $31, 0x10($29)
    /* 3DA648 004DA648 F265130C */  jal        func_004d97c8
    /* 3DA64C 004DA64C 2D808000 */   daddu     $16, $4, $0
    /* 3DA650 004DA650 2D200002 */  daddu      $4, $16, $0
    /* 3DA654 004DA654 000022AE */  sw         $2, 0x0($17)
    /* 3DA658 004DA658 F265130C */  jal        func_004d97c8
    /* 3DA65C 004DA65C 02000524 */   addiu     $5, $0, 0x2
    /* 3DA660 004DA660 04000324 */  addiu      $3, $0, 0x4
    /* 3DA664 004DA664 23186200 */  subu       $3, $3, $2
    /* 3DA668 004DA668 2D200002 */  daddu      $4, $16, $0
    /* 3DA66C 004DA66C 040023AE */  sw         $3, 0x4($17)
    /* 3DA670 004DA670 F265130C */  jal        func_004d97c8
    /* 3DA674 004DA674 01000524 */   addiu     $5, $0, 0x1
    /* 3DA678 004DA678 2D200002 */  daddu      $4, $16, $0
    /* 3DA67C 004DA67C 0100422C */  sltiu      $2, $2, 0x1
    /* 3DA680 004DA680 04000524 */  addiu      $5, $0, 0x4
    /* 3DA684 004DA684 F265130C */  jal        func_004d97c8
    /* 3DA688 004DA688 080022AE */   sw        $2, 0x8($17)
    /* 3DA68C 004DA68C 2D200002 */  daddu      $4, $16, $0
    /* 3DA690 004DA690 0C0022AE */  sw         $2, 0xC($17)
    /* 3DA694 004DA694 F265130C */  jal        func_004d97c8
    /* 3DA698 004DA698 02000524 */   addiu     $5, $0, 0x2
    /* 3DA69C 004DA69C 2D200002 */  daddu      $4, $16, $0
    /* 3DA6A0 004DA6A0 100022AE */  sw         $2, 0x10($17)
    /* 3DA6A4 004DA6A4 F265130C */  jal        func_004d97c8
    /* 3DA6A8 004DA6A8 01000524 */   addiu     $5, $0, 0x1
    /* 3DA6AC 004DA6AC 2D200002 */  daddu      $4, $16, $0
    /* 3DA6B0 004DA6B0 140022AE */  sw         $2, 0x14($17)
    /* 3DA6B4 004DA6B4 F265130C */  jal        func_004d97c8
    /* 3DA6B8 004DA6B8 01000524 */   addiu     $5, $0, 0x1
    /* 3DA6BC 004DA6BC 2D200002 */  daddu      $4, $16, $0
    /* 3DA6C0 004DA6C0 180022AE */  sw         $2, 0x18($17)
    /* 3DA6C4 004DA6C4 F265130C */  jal        func_004d97c8
    /* 3DA6C8 004DA6C8 02000524 */   addiu     $5, $0, 0x2
    /* 3DA6CC 004DA6CC 2D200002 */  daddu      $4, $16, $0
    /* 3DA6D0 004DA6D0 1C0022AE */  sw         $2, 0x1C($17)
    /* 3DA6D4 004DA6D4 F265130C */  jal        func_004d97c8
    /* 3DA6D8 004DA6D8 02000524 */   addiu     $5, $0, 0x2
    /* 3DA6DC 004DA6DC 2D200002 */  daddu      $4, $16, $0
    /* 3DA6E0 004DA6E0 200022AE */  sw         $2, 0x20($17)
    /* 3DA6E4 004DA6E4 F265130C */  jal        func_004d97c8
    /* 3DA6E8 004DA6E8 01000524 */   addiu     $5, $0, 0x1
    /* 3DA6EC 004DA6EC 2D200002 */  daddu      $4, $16, $0
    /* 3DA6F0 004DA6F0 240022AE */  sw         $2, 0x24($17)
    /* 3DA6F4 004DA6F4 F265130C */  jal        func_004d97c8
    /* 3DA6F8 004DA6F8 01000524 */   addiu     $5, $0, 0x1
    /* 3DA6FC 004DA6FC 2D200002 */  daddu      $4, $16, $0
    /* 3DA700 004DA700 280022AE */  sw         $2, 0x28($17)
    /* 3DA704 004DA704 F265130C */  jal        func_004d97c8
    /* 3DA708 004DA708 02000524 */   addiu     $5, $0, 0x2
    /* 3DA70C 004DA70C 1C00248E */  lw         $4, 0x1C($17)
    /* 3DA710 004DA710 03000324 */  addiu      $3, $0, 0x3
    /* 3DA714 004DA714 2C0022AE */  sw         $2, 0x2C($17)
    /* 3DA718 004DA718 04008314 */  bne        $4, $3, .L004DA72C
    /* 3DA71C 004DA71C 2D100000 */   daddu     $2, $0, $0
    /* 3DA720 004DA720 2000238E */  lw         $3, 0x20($17)
    /* 3DA724 004DA724 03006010 */  beqz       $3, .L004DA734
    /* 3DA728 004DA728 0000B0DF */   ld        $16, 0x0($29)
  .L004DA72C:
    /* 3DA72C 004DA72C FFFF0224 */  addiu      $2, $0, -0x1
    /* 3DA730 004DA730 0000B0DF */  ld         $16, 0x0($29)
  .L004DA734:
    /* 3DA734 004DA734 0800B1DF */  ld         $17, 0x8($29)
    /* 3DA738 004DA738 1000BFDF */  ld         $31, 0x10($29)
    /* 3DA73C 004DA73C 0800E003 */  jr         $31
    /* 3DA740 004DA740 2000BD27 */   addiu     $29, $29, 0x20
    /* 3DA744 004DA744 00000000 */  nop
.size func_004da630, 0x118
