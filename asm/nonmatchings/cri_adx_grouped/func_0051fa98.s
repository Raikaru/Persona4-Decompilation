.section .text
.set noat
.set noreorder
glabel func_0051fa98
    /* 41FA98 0051FA98 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 41FA9C 0051FA9C 1000B0FF */  sd         $16, 0x10($29)
    /* 41FAA0 0051FAA0 2D808000 */  daddu      $16, $4, $0
    /* 41FAA4 0051FAA4 1800BFFF */  sd         $31, 0x18($29)
    /* 41FAA8 0051FAA8 645F140C */  jal        func_00517d90
    /* 41FAAC 0051FAAC 2D20A003 */   daddu     $4, $29, $0
    /* 41FAB0 0051FAB0 2D200002 */  daddu      $4, $16, $0
    /* 41FAB4 0051FAB4 4800038E */  lw         $3, 0x48($16)
    /* 41FAB8 0051FAB8 04000224 */  addiu      $2, $0, 0x4
    /* 41FABC 0051FABC 0400A527 */  addiu      $5, $29, 0x4
    /* 41FAC0 0051FAC0 03006210 */  beq        $3, $2, .L0051FAD0
    /* 41FAC4 0051FAC4 0800A627 */   addiu     $6, $29, 0x8
    /* 41FAC8 0051FAC8 12000010 */  b          .L0051FB14
    /* 41FACC 0051FACC 0800A0AF */   sw        $0, 0x8($29)
  .L0051FAD0:
    /* 41FAD0 0051FAD0 CC7E140C */  jal        func_0051fb30
    /* 41FAD4 0051FAD4 00000000 */   nop
    /* 41FAD8 0051FAD8 2D200002 */  daddu      $4, $16, $0
    /* 41FADC 0051FADC 0800A28F */  lw         $2, 0x8($29)
    /* 41FAE0 0051FAE0 0C004010 */  beqz       $2, .L0051FB14
    /* 41FAE4 0051FAE4 0F000524 */   addiu     $5, $0, 0xF
    /* 41FAE8 0051FAE8 2694140C */  jal        func_00525098
    /* 41FAEC 0051FAEC 00000000 */   nop
    /* 41FAF0 0051FAF0 08004010 */  beqz       $2, .L0051FB14
    /* 41FAF4 0051FAF4 2D200002 */   daddu     $4, $16, $0
    /* 41FAF8 0051FAF8 0800A28F */  lw         $2, 0x8($29)
    /* 41FAFC 0051FAFC 3C00468C */  lw         $6, 0x3C($2)
    /* 41FB00 0051FB00 D49A140C */  jal        func_00526b50
    /* 41FB04 0051FB04 3800458C */   lw        $5, 0x38($2)
    /* 41FB08 0051FB08 0800A38F */  lw         $3, 0x8($29)
    /* 41FB0C 0051FB0C 0A180200 */  movz       $3, $0, $2
    /* 41FB10 0051FB10 0800A3AF */  sw         $3, 0x8($29)
  .L0051FB14:
    /* 41FB14 0051FB14 6A5F140C */  jal        func_00517da8
    /* 41FB18 0051FB18 2D20A003 */   daddu     $4, $29, $0
    /* 41FB1C 0051FB1C 0800A28F */  lw         $2, 0x8($29)
    /* 41FB20 0051FB20 1000B0DF */  ld         $16, 0x10($29)
    /* 41FB24 0051FB24 1800BFDF */  ld         $31, 0x18($29)
    /* 41FB28 0051FB28 0800E003 */  jr         $31
    /* 41FB2C 0051FB2C 2000BD27 */   addiu     $29, $29, 0x20
.size func_0051fa98, 0x98
