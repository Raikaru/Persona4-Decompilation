.section .text
.set noat
.set noreorder
glabel func_002dfec0
    /* 1DFEC0 002DFEC0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 1DFEC4 002DFEC4 4000BFFF */  sd         $31, 0x40($29)
    /* 1DFEC8 002DFEC8 3000B37F */  sq         $19, 0x30($29)
    /* 1DFECC 002DFECC 2000B27F */  sq         $18, 0x20($29)
    /* 1DFED0 002DFED0 1000B17F */  sq         $17, 0x10($29)
    /* 1DFED4 002DFED4 0000B07F */  sq         $16, 0x0($29)
    /* 1DFED8 002DFED8 2D98A000 */  daddu      $19, $5, $0
    /* 1DFEDC 002DFEDC 2D90C000 */  daddu      $18, $6, $0
    /* 1DFEE0 002DFEE0 2D88E000 */  daddu      $17, $7, $0
    /* 1DFEE4 002DFEE4 3800828C */  lw         $2, 0x38($4)
    /* 1DFEE8 002DFEE8 2C0F428C */  lw         $2, 0xF2C($2)
    /* 1DFEEC 002DFEEC 1001448C */  lw         $4, 0x110($2)
    /* 1DFEF0 002DFEF0 E0EA0A0C */  jal        func_002bab80
    /* 1DFEF4 002DFEF4 00000000 */   nop
    /* 1DFEF8 002DFEF8 3C860200 */  dsll32     $16, $2, 24
    /* 1DFEFC 002DFEFC 3F861000 */  dsra32     $16, $16, 24
    /* 1DFF00 002DFF00 06004012 */  beqz       $18, .L002DFF1C
    /* 1DFF04 002DFF04 00000000 */   nop
    /* 1DFF08 002DFF08 2D200002 */  daddu      $4, $16, $0
    /* 1DFF0C 002DFF0C 2D280000 */  daddu      $5, $0, $0
    /* 1DFF10 002DFF10 2D304002 */  daddu      $6, $18, $0
    /* 1DFF14 002DFF14 60EF0A0C */  jal        func_002bbd80
    /* 1DFF18 002DFF18 00000000 */   nop
  .L002DFF1C:
    /* 1DFF1C 002DFF1C 3C2C1300 */  dsll32     $5, $19, 16
    /* 1DFF20 002DFF20 3F2C0500 */  dsra32     $5, $5, 16
    /* 1DFF24 002DFF24 2D200002 */  daddu      $4, $16, $0
    /* 1DFF28 002DFF28 70EB0A0C */  jal        func_002badc0
    /* 1DFF2C 002DFF2C 00000000 */   nop
    /* 1DFF30 002DFF30 3C1E1100 */  dsll32     $3, $17, 24
    /* 1DFF34 002DFF34 3F1E0300 */  dsra32     $3, $3, 24
    /* 1DFF38 002DFF38 01000224 */  addiu      $2, $0, 0x1
    /* 1DFF3C 002DFF3C 0B006214 */  bne        $3, $2, .L002DFF6C
    /* 1DFF40 002DFF40 00000000 */   nop
    /* 1DFF44 002DFF44 2D200002 */  daddu      $4, $16, $0
    /* 1DFF48 002DFF48 2D280000 */  daddu      $5, $0, $0
    /* 1DFF4C 002DFF4C F0EB0A0C */  jal        func_002bafc0
    /* 1DFF50 002DFF50 00000000 */   nop
    /* 1DFF54 002DFF54 2D200002 */  daddu      $4, $16, $0
    /* 1DFF58 002DFF58 2D280000 */  daddu      $5, $0, $0
    /* 1DFF5C 002DFF5C 28EC0A0C */  jal        func_002bb0a0
    /* 1DFF60 002DFF60 00000000 */   nop
    /* 1DFF64 002DFF64 D8EF0A0C */  jal        func_002bbf60
    /* 1DFF68 002DFF68 00000000 */   nop
  .L002DFF6C:
    /* 1DFF6C 002DFF6C 2D100002 */  daddu      $2, $16, $0
    /* 1DFF70 002DFF70 4000BFDF */  ld         $31, 0x40($29)
    /* 1DFF74 002DFF74 3000B37B */  lq         $19, 0x30($29)
    /* 1DFF78 002DFF78 2000B27B */  lq         $18, 0x20($29)
    /* 1DFF7C 002DFF7C 1000B17B */  lq         $17, 0x10($29)
    /* 1DFF80 002DFF80 0000B07B */  lq         $16, 0x0($29)
    /* 1DFF84 002DFF84 5000BD27 */  addiu      $29, $29, 0x50
    /* 1DFF88 002DFF88 0800E003 */  jr         $31
    /* 1DFF8C 002DFF8C 00000000 */   nop
.size func_002dfec0, 0xd0
