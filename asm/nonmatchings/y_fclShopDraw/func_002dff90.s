.section .text
.set noat
.set noreorder
glabel func_002dff90
    /* 1DFF90 002DFF90 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 1DFF94 002DFF94 5000BFFF */  sd         $31, 0x50($29)
    /* 1DFF98 002DFF98 4000B47F */  sq         $20, 0x40($29)
    /* 1DFF9C 002DFF9C 3000B37F */  sq         $19, 0x30($29)
    /* 1DFFA0 002DFFA0 2000B27F */  sq         $18, 0x20($29)
    /* 1DFFA4 002DFFA4 1000B17F */  sq         $17, 0x10($29)
    /* 1DFFA8 002DFFA8 0000B07F */  sq         $16, 0x0($29)
    /* 1DFFAC 002DFFAC 2DA0A000 */  daddu      $20, $5, $0
    /* 1DFFB0 002DFFB0 2D98C000 */  daddu      $19, $6, $0
    /* 1DFFB4 002DFFB4 2D90E000 */  daddu      $18, $7, $0
    /* 1DFFB8 002DFFB8 2D880001 */  daddu      $17, $8, $0
    /* 1DFFBC 002DFFBC 3800828C */  lw         $2, 0x38($4)
    /* 1DFFC0 002DFFC0 2C0F428C */  lw         $2, 0xF2C($2)
    /* 1DFFC4 002DFFC4 1001448C */  lw         $4, 0x110($2)
    /* 1DFFC8 002DFFC8 E0EA0A0C */  jal        func_002bab80
    /* 1DFFCC 002DFFCC 00000000 */   nop
    /* 1DFFD0 002DFFD0 3C860200 */  dsll32     $16, $2, 24
    /* 1DFFD4 002DFFD4 3F861000 */  dsra32     $16, $16, 24
    /* 1DFFD8 002DFFD8 2D200002 */  daddu      $4, $16, $0
    /* 1DFFDC 002DFFDC 2D280000 */  daddu      $5, $0, $0
    /* 1DFFE0 002DFFE0 2D306002 */  daddu      $6, $19, $0
    /* 1DFFE4 002DFFE4 60EF0A0C */  jal        func_002bbd80
    /* 1DFFE8 002DFFE8 00000000 */   nop
    /* 1DFFEC 002DFFEC 2D200002 */  daddu      $4, $16, $0
    /* 1DFFF0 002DFFF0 01000524 */  addiu      $5, $0, 0x1
    /* 1DFFF4 002DFFF4 2D304002 */  daddu      $6, $18, $0
    /* 1DFFF8 002DFFF8 60EF0A0C */  jal        func_002bbd80
    /* 1DFFFC 002DFFFC 00000000 */   nop
    /* 1E0000 002E0000 3C2C1400 */  dsll32     $5, $20, 16
    /* 1E0004 002E0004 3F2C0500 */  dsra32     $5, $5, 16
    /* 1E0008 002E0008 2D200002 */  daddu      $4, $16, $0
    /* 1E000C 002E000C 70EB0A0C */  jal        func_002badc0
    /* 1E0010 002E0010 00000000 */   nop
    /* 1E0014 002E0014 3C1E1100 */  dsll32     $3, $17, 24
    /* 1E0018 002E0018 3F1E0300 */  dsra32     $3, $3, 24
    /* 1E001C 002E001C 01000224 */  addiu      $2, $0, 0x1
    /* 1E0020 002E0020 0B006214 */  bne        $3, $2, .L002E0050
    /* 1E0024 002E0024 00000000 */   nop
    /* 1E0028 002E0028 2D200002 */  daddu      $4, $16, $0
    /* 1E002C 002E002C 2D280000 */  daddu      $5, $0, $0
    /* 1E0030 002E0030 F0EB0A0C */  jal        func_002bafc0
    /* 1E0034 002E0034 00000000 */   nop
    /* 1E0038 002E0038 2D200002 */  daddu      $4, $16, $0
    /* 1E003C 002E003C 2D280000 */  daddu      $5, $0, $0
    /* 1E0040 002E0040 28EC0A0C */  jal        func_002bb0a0
    /* 1E0044 002E0044 00000000 */   nop
    /* 1E0048 002E0048 D8EF0A0C */  jal        func_002bbf60
    /* 1E004C 002E004C 00000000 */   nop
  .L002E0050:
    /* 1E0050 002E0050 2D100002 */  daddu      $2, $16, $0
    /* 1E0054 002E0054 5000BFDF */  ld         $31, 0x50($29)
    /* 1E0058 002E0058 4000B47B */  lq         $20, 0x40($29)
    /* 1E005C 002E005C 3000B37B */  lq         $19, 0x30($29)
    /* 1E0060 002E0060 2000B27B */  lq         $18, 0x20($29)
    /* 1E0064 002E0064 1000B17B */  lq         $17, 0x10($29)
    /* 1E0068 002E0068 0000B07B */  lq         $16, 0x0($29)
    /* 1E006C 002E006C 6000BD27 */  addiu      $29, $29, 0x60
    /* 1E0070 002E0070 0800E003 */  jr         $31
    /* 1E0074 002E0074 00000000 */   nop
    /* 1E0078 002E0078 00000000 */  nop
    /* 1E007C 002E007C 00000000 */  nop
.size func_002dff90, 0xf0
