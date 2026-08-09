.section .text
.set noat
.set noreorder
glabel func_0035ef80
    /* 25EF80 0035EF80 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 25EF84 0035EF84 0000BFFF */  sd         $31, 0x0($29)
    /* 25EF88 0035EF88 24008384 */  lh         $3, 0x24($4)
    /* 25EF8C 0035EF8C 26008284 */  lh         $2, 0x26($4)
    /* 25EF90 0035EF90 21186200 */  addu       $3, $3, $2
    /* 25EF94 0035EF94 40100300 */  sll        $2, $3, 1
    /* 25EF98 0035EF98 21104300 */  addu       $2, $2, $3
    /* 25EF9C 0035EF9C 80100200 */  sll        $2, $2, 2
    /* 25EFA0 0035EFA0 21104400 */  addu       $2, $2, $4
    /* 25EFA4 0035EFA4 38004580 */  lb         $5, 0x38($2)
    /* 25EFA8 0035EFA8 2D300000 */  daddu      $6, $0, $0
    /* 25EFAC 0035EFAC 4000438C */  lw         $3, 0x40($2)
    /* 25EFB0 0035EFB0 01000224 */  addiu      $2, $0, 0x1
    /* 25EFB4 0035EFB4 0F006210 */  beq        $3, $2, .L0035EFF4
    /* 25EFB8 0035EFB8 00000000 */   nop
    /* 25EFBC 0035EFBC 03000224 */  addiu      $2, $0, 0x3
    /* 25EFC0 0035EFC0 09006210 */  beq        $3, $2, .L0035EFE8
    /* 25EFC4 0035EFC4 00000000 */   nop
    /* 25EFC8 0035EFC8 02000224 */  addiu      $2, $0, 0x2
    /* 25EFCC 0035EFCC 03006210 */  beq        $3, $2, .L0035EFDC
    /* 25EFD0 0035EFD0 00000000 */   nop
    /* 25EFD4 0035EFD4 08000010 */  b          .L0035EFF8
    /* 25EFD8 0035EFD8 00000000 */   nop
  .L0035EFDC:
    /* 25EFDC 0035EFDC 0100C634 */  ori        $6, $6, 0x1
    /* 25EFE0 0035EFE0 05000010 */  b          .L0035EFF8
    /* 25EFE4 0035EFE4 00000000 */   nop
  .L0035EFE8:
    /* 25EFE8 0035EFE8 0200C634 */  ori        $6, $6, 0x2
    /* 25EFEC 0035EFEC 02000010 */  b          .L0035EFF8
    /* 25EFF0 0035EFF0 00000000 */   nop
  .L0035EFF4:
    /* 25EFF4 0035EFF4 0400C634 */  ori        $6, $6, 0x4
  .L0035EFF8:
    /* 25EFF8 0035EFF8 0C13848C */  lw         $4, 0x130C($4)
    /* 25EFFC 0035EFFC 046F0D0C */  jal        func_0035bc10
    /* 25F000 0035F000 00000000 */   nop
    /* 25F004 0035F004 0000BFDF */  ld         $31, 0x0($29)
    /* 25F008 0035F008 1000BD27 */  addiu      $29, $29, 0x10
    /* 25F00C 0035F00C 0800E003 */  jr         $31
    /* 25F010 0035F010 00000000 */   nop
    /* 25F014 0035F014 00000000 */  nop
    /* 25F018 0035F018 00000000 */  nop
    /* 25F01C 0035F01C 00000000 */  nop
.size func_0035ef80, 0xa0
