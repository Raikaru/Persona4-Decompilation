.section .text
.set noat
.set noreorder
glabel func_0036fbe0
    /* 26FBE0 0036FBE0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 26FBE4 0036FBE4 4000BFFF */  sd         $31, 0x40($29)
    /* 26FBE8 0036FBE8 3000B37F */  sq         $19, 0x30($29)
    /* 26FBEC 0036FBEC 2000B27F */  sq         $18, 0x20($29)
    /* 26FBF0 0036FBF0 1000B17F */  sq         $17, 0x10($29)
    /* 26FBF4 0036FBF4 0000B07F */  sq         $16, 0x0($29)
    /* 26FBF8 0036FBF8 FFFF9130 */  andi       $17, $4, 0xFFFF
    /* 26FBFC 0036FBFC 0B002012 */  beqz       $17, .L0036FC2C
    /* 26FC00 0036FC00 00000000 */   nop
    /* 26FC04 0036FC04 01000424 */  addiu      $4, $0, 0x1
    /* 26FC08 0036FC08 7013040C */  jal        func_00104dc0
    /* 26FC0C 0036FC0C 00000000 */   nop
    /* 26FC10 0036FC10 3C2C0200 */  dsll32     $5, $2, 16
    /* 26FC14 0036FC14 3F2C0500 */  dsra32     $5, $5, 16
    /* 26FC18 0036FC18 01000424 */  addiu      $4, $0, 0x1
    /* 26FC1C 0036FC1C B815040C */  jal        func_001056e0
    /* 26FC20 0036FC20 00000000 */   nop
    /* 26FC24 0036FC24 05000010 */  b          .L0036FC3C
    /* 26FC28 0036FC28 00000000 */   nop
  .L0036FC2C:
    /* 26FC2C 0036FC2C 01000424 */  addiu      $4, $0, 0x1
    /* 26FC30 0036FC30 2D288000 */  daddu      $5, $4, $0
    /* 26FC34 0036FC34 B815040C */  jal        func_001056e0
    /* 26FC38 0036FC38 00000000 */   nop
  .L0036FC3C:
    /* 26FC3C 0036FC3C 2D980000 */  daddu      $19, $0, $0
    /* 26FC40 0036FC40 21000010 */  b          .L0036FCC8
    /* 26FC44 0036FC44 00000000 */   nop
  .L0036FC48:
    /* 26FC48 0036FC48 B817040C */  jal        func_00105ee0
    /* 26FC4C 0036FC4C 00000000 */   nop
    /* 26FC50 0036FC50 FFFF5030 */  andi       $16, $2, 0xFFFF
    /* 26FC54 0036FC54 1A000012 */  beqz       $16, .L0036FCC0
    /* 26FC58 0036FC58 00000000 */   nop
    /* 26FC5C 0036FC5C 3C941000 */  dsll32     $18, $16, 16
    /* 26FC60 0036FC60 3F941200 */  dsra32     $18, $18, 16
    /* 26FC64 0036FC64 2D204002 */  daddu      $4, $18, $0
    /* 26FC68 0036FC68 8415040C */  jal        func_00105610
    /* 26FC6C 0036FC6C 00000000 */   nop
    /* 26FC70 0036FC70 13004014 */  bnez       $2, .L0036FCC0
    /* 26FC74 0036FC74 00000000 */   nop
    /* 26FC78 0036FC78 0D002012 */  beqz       $17, .L0036FCB0
    /* 26FC7C 0036FC7C 00000000 */   nop
    /* 26FC80 0036FC80 3C841000 */  dsll32     $16, $16, 16
    /* 26FC84 0036FC84 3F841000 */  dsra32     $16, $16, 16
    /* 26FC88 0036FC88 2D200002 */  daddu      $4, $16, $0
    /* 26FC8C 0036FC8C 7013040C */  jal        func_00104dc0
    /* 26FC90 0036FC90 00000000 */   nop
    /* 26FC94 0036FC94 3C2C0200 */  dsll32     $5, $2, 16
    /* 26FC98 0036FC98 3F2C0500 */  dsra32     $5, $5, 16
    /* 26FC9C 0036FC9C 2D200002 */  daddu      $4, $16, $0
    /* 26FCA0 0036FCA0 B815040C */  jal        func_001056e0
    /* 26FCA4 0036FCA4 00000000 */   nop
    /* 26FCA8 0036FCA8 05000010 */  b          .L0036FCC0
    /* 26FCAC 0036FCAC 00000000 */   nop
  .L0036FCB0:
    /* 26FCB0 0036FCB0 2D204002 */  daddu      $4, $18, $0
    /* 26FCB4 0036FCB4 01000524 */  addiu      $5, $0, 0x1
    /* 26FCB8 0036FCB8 B815040C */  jal        func_001056e0
    /* 26FCBC 0036FCBC 00000000 */   nop
  .L0036FCC0:
    /* 26FCC0 0036FCC0 01006226 */  addiu      $2, $19, 0x1
    /* 26FCC4 0036FCC4 FFFF5330 */  andi       $19, $2, 0xFFFF
  .L0036FCC8:
    /* 26FCC8 0036FCC8 FFFF6432 */  andi       $4, $19, 0xFFFF
    /* 26FCCC 0036FCCC 04008228 */  slti       $2, $4, 0x4
    /* 26FCD0 0036FCD0 DDFF4014 */  bnez       $2, .L0036FC48
    /* 26FCD4 0036FCD4 00000000 */   nop
    /* 26FCD8 0036FCD8 01000224 */  addiu      $2, $0, 0x1
    /* 26FCDC 0036FCDC 4000BFDF */  ld         $31, 0x40($29)
    /* 26FCE0 0036FCE0 3000B37B */  lq         $19, 0x30($29)
    /* 26FCE4 0036FCE4 2000B27B */  lq         $18, 0x20($29)
    /* 26FCE8 0036FCE8 1000B17B */  lq         $17, 0x10($29)
    /* 26FCEC 0036FCEC 0000B07B */  lq         $16, 0x0($29)
    /* 26FCF0 0036FCF0 5000BD27 */  addiu      $29, $29, 0x50
    /* 26FCF4 0036FCF4 0800E003 */  jr         $31
    /* 26FCF8 0036FCF8 00000000 */   nop
    /* 26FCFC 0036FCFC 00000000 */  nop
.size func_0036fbe0, 0x120
