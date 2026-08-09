.section .text
.set noat
.set noreorder
glabel func_0026fba0
    /* 16FBA0 0026FBA0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 16FBA4 0026FBA4 1000BFFF */  sd         $31, 0x10($29)
    /* 16FBA8 0026FBA8 0000B07F */  sq         $16, 0x0($29)
    /* 16FBAC 0026FBAC 2D80A000 */  daddu      $16, $5, $0
    /* 16FBB0 0026FBB0 A8D1090C */  jal        func_002746a0
    /* 16FBB4 0026FBB4 00000000 */   nop
    /* 16FBB8 0026FBB8 04004010 */  beqz       $2, .L0026FBCC
    /* 16FBBC 0026FBBC 00000000 */   nop
    /* 16FBC0 0026FBC0 2D100000 */  daddu      $2, $0, $0
    /* 16FBC4 0026FBC4 11000010 */  b          .L0026FC0C
    /* 16FBC8 0026FBC8 00000000 */   nop
  .L0026FBCC:
    /* 16FBCC 0026FBCC 01000424 */  addiu      $4, $0, 0x1
    /* 16FBD0 0026FBD0 9835040C */  jal        func_0010d660
    /* 16FBD4 0026FBD4 00000000 */   nop
    /* 16FBD8 0026FBD8 2000A427 */  addiu      $4, $29, 0x20
    /* 16FBDC 0026FBDC 34A78527 */  addiu      $5, $28, -0x58CC
    /* 16FBE0 0026FBE0 2D304000 */  daddu      $6, $2, $0
    /* 16FBE4 0026FBE4 2208110C */  jal        func_00442088
    /* 16FBE8 0026FBE8 00000000 */   nop
    /* 16FBEC 0026FBEC 2D200002 */  daddu      $4, $16, $0
    /* 16FBF0 0026FBF0 DCCF090C */  jal        func_00273f70
    /* 16FBF4 0026FBF4 00000000 */   nop
    /* 16FBF8 0026FBF8 2000A427 */  addiu      $4, $29, 0x20
    /* 16FBFC 0026FBFC 2D280002 */  daddu      $5, $16, $0
    /* 16FC00 0026FC00 30CF090C */  jal        func_00273cc0
    /* 16FC04 0026FC04 00000000 */   nop
    /* 16FC08 0026FC08 2D100000 */  daddu      $2, $0, $0
  .L0026FC0C:
    /* 16FC0C 0026FC0C 1000BFDF */  ld         $31, 0x10($29)
    /* 16FC10 0026FC10 0000B07B */  lq         $16, 0x0($29)
    /* 16FC14 0026FC14 4000BD27 */  addiu      $29, $29, 0x40
    /* 16FC18 0026FC18 0800E003 */  jr         $31
    /* 16FC1C 0026FC1C 00000000 */   nop
.size func_0026fba0, 0x80
