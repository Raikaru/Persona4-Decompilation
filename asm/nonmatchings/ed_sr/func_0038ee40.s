.section .text
.set noat
.set noreorder
glabel func_0038ee40
    /* 28EE40 0038EE40 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 28EE44 0038EE44 1000BFFF */  sd         $31, 0x10($29)
    /* 28EE48 0038EE48 0000B07F */  sq         $16, 0x0($29)
    /* 28EE4C 0038EE4C B8B5838F */  lw         $3, -0x4A48($28)
    /* 28EE50 0038EE50 05006014 */  bnez       $3, .L0038EE68
    /* 28EE54 0038EE54 00000000 */   nop
    /* 28EE58 0038EE58 F0A98427 */  addiu      $4, $28, -0x5610
    /* 28EE5C 0038EE5C 64000524 */  addiu      $5, $0, 0x64
    /* 28EE60 0038EE60 CCB5110C */  jal        func_0046d730
    /* 28EE64 0038EE64 00000000 */   nop
  .L0038EE68:
    /* 28EE68 0038EE68 B8B5908F */  lw         $16, -0x4A48($28)
    /* 28EE6C 0038EE6C 0000038E */  lw         $3, 0x0($16)
    /* 28EE70 0038EE70 27186000 */  not        $3, $3
    /* 28EE74 0038EE74 01006330 */  andi       $3, $3, 0x1
    /* 28EE78 0038EE78 5D006014 */  bnez       $3, .L0038EFF0
    /* 28EE7C 0038EE7C 00000000 */   nop
    /* 28EE80 0038EE80 4C12038E */  lw         $3, 0x124C($16)
    /* 28EE84 0038EE84 03000224 */  addiu      $2, $0, 0x3
    /* 28EE88 0038EE88 4D006210 */  beq        $3, $2, .L0038EFC0
    /* 28EE8C 0038EE8C 00000000 */   nop
    /* 28EE90 0038EE90 02000224 */  addiu      $2, $0, 0x2
    /* 28EE94 0038EE94 14006210 */  beq        $3, $2, .L0038EEE8
    /* 28EE98 0038EE98 00000000 */   nop
    /* 28EE9C 0038EE9C 01000224 */  addiu      $2, $0, 0x1
    /* 28EEA0 0038EEA0 0D006210 */  beq        $3, $2, .L0038EED8
    /* 28EEA4 0038EEA4 00000000 */   nop
    /* 28EEA8 0038EEA8 03006010 */  beqz       $3, .L0038EEB8
    /* 28EEAC 0038EEAC 00000000 */   nop
    /* 28EEB0 0038EEB0 4B000010 */  b          .L0038EFE0
    /* 28EEB4 0038EEB4 00000000 */   nop
  .L0038EEB8:
    /* 28EEB8 0038EEB8 203E0E0C */  jal        func_0038f880
    /* 28EEBC 0038EEBC 00000000 */   nop
    /* 28EEC0 0038EEC0 47004014 */  bnez       $2, .L0038EFE0
    /* 28EEC4 0038EEC4 00000000 */   nop
    /* 28EEC8 0038EEC8 01000224 */  addiu      $2, $0, 0x1
    /* 28EECC 0038EECC 4C1202AE */  sw         $2, 0x124C($16)
    /* 28EED0 0038EED0 43000010 */  b          .L0038EFE0
    /* 28EED4 0038EED4 00000000 */   nop
  .L0038EED8:
    /* 28EED8 0038EED8 043C0E0C */  jal        func_0038f010
    /* 28EEDC 0038EEDC 00000000 */   nop
    /* 28EEE0 0038EEE0 3F000010 */  b          .L0038EFE0
    /* 28EEE4 0038EEE4 00000000 */   nop
  .L0038EEE8:
    /* 28EEE8 0038EEE8 5412028E */  lw         $2, 0x1254($16)
    /* 28EEEC 0038EEEC 01004224 */  addiu      $2, $2, 0x1
    /* 28EEF0 0038EEF0 541202AE */  sw         $2, 0x1254($16)
    /* 28EEF4 0038EEF4 72140424 */  addiu      $4, $0, 0x1472
    /* 28EEF8 0038EEF8 CC18040C */  jal        func_00106330
    /* 28EEFC 0038EEFC 00000000 */   nop
    /* 28EF00 0038EF00 0A004010 */  beqz       $2, .L0038EF2C
    /* 28EF04 0038EF04 00000000 */   nop
    /* 28EF08 0038EF08 B0A8110C */  jal        func_0046a2c0
    /* 28EF0C 0038EF0C 00000000 */   nop
    /* 28EF10 0038EF10 C60C0324 */  addiu      $3, $0, 0xCC6
    /* 28EF14 0038EF14 0F004314 */  bne        $2, $3, .L0038EF54
    /* 28EF18 0038EF18 00000000 */   nop
    /* 28EF1C 0038EF1C A4370E0C */  jal        func_0038de90
    /* 28EF20 0038EF20 00000000 */   nop
    /* 28EF24 0038EF24 0B000010 */  b          .L0038EF54
    /* 28EF28 0038EF28 00000000 */   nop
  .L0038EF2C:
    /* 28EF2C 0038EF2C 5412038E */  lw         $3, 0x1254($16)
    /* 28EF30 0038EF30 01000224 */  addiu      $2, $0, 0x1
    /* 28EF34 0038EF34 07006214 */  bne        $3, $2, .L0038EF54
    /* 28EF38 0038EF38 00000000 */   nop
    /* 28EF3C 0038EF3C A4370E0C */  jal        func_0038de90
    /* 28EF40 0038EF40 00000000 */   nop
    /* 28EF44 0038EF44 23000424 */  addiu      $4, $0, 0x23
    /* 28EF48 0038EF48 01000524 */  addiu      $5, $0, 0x1
    /* 28EF4C 0038EF4C F868110C */  jal        func_0045a3e0
    /* 28EF50 0038EF50 00000000 */   nop
  .L0038EF54:
    /* 28EF54 0038EF54 C4370E0C */  jal        func_0038df10
    /* 28EF58 0038EF58 00000000 */   nop
    /* 28EF5C 0038EF5C 20004014 */  bnez       $2, .L0038EFE0
    /* 28EF60 0038EF60 00000000 */   nop
    /* 28EF64 0038EF64 5012048E */  lw         $4, 0x1250($16)
    /* 28EF68 0038EF68 2449110C */  jal        func_00452490
    /* 28EF6C 0038EF6C 00000000 */   nop
    /* 28EF70 0038EF70 1B004014 */  bnez       $2, .L0038EFE0
    /* 28EF74 0038EF74 00000000 */   nop
    /* 28EF78 0038EF78 E889040C */  jal        func_001227a0
    /* 28EF7C 0038EF7C 00000000 */   nop
    /* 28EF80 0038EF80 2D204000 */  daddu      $4, $2, $0
    /* 28EF84 0038EF84 0A000524 */  addiu      $5, $0, 0xA
    /* 28EF88 0038EF88 4889040C */  jal        func_00122520
    /* 28EF8C 0038EF8C 00000000 */   nop
    /* 28EF90 0038EF90 03000224 */  addiu      $2, $0, 0x3
    /* 28EF94 0038EF94 4C1202AE */  sw         $2, 0x124C($16)
    /* 28EF98 0038EF98 72140424 */  addiu      $4, $0, 0x1472
    /* 28EF9C 0038EF9C CC18040C */  jal        func_00106330
    /* 28EFA0 0038EFA0 00000000 */   nop
    /* 28EFA4 0038EFA4 0E004014 */  bnez       $2, .L0038EFE0
    /* 28EFA8 0038EFA8 00000000 */   nop
    /* 28EFAC 0038EFAC 3C000424 */  addiu      $4, $0, 0x3C
    /* 28EFB0 0038EFB0 3866110C */  jal        func_004598e0
    /* 28EFB4 0038EFB4 00000000 */   nop
    /* 28EFB8 0038EFB8 09000010 */  b          .L0038EFE0
    /* 28EFBC 0038EFBC 00000000 */   nop
  .L0038EFC0:
    /* 28EFC0 0038EFC0 C889040C */  jal        func_00122720
    /* 28EFC4 0038EFC4 00000000 */   nop
    /* 28EFC8 0038EFC8 05004010 */  beqz       $2, .L0038EFE0
    /* 28EFCC 0038EFCC 00000000 */   nop
    /* 28EFD0 0038EFD0 0000038E */  lw         $3, 0x0($16)
    /* 28EFD4 0038EFD4 FEFF0224 */  addiu      $2, $0, -0x2
    /* 28EFD8 0038EFD8 24106200 */  and        $2, $3, $2
    /* 28EFDC 0038EFDC 000002AE */  sw         $2, 0x0($16)
  .L0038EFE0:
    /* 28EFE0 0038EFE0 A03D0E0C */  jal        func_0038f680
    /* 28EFE4 0038EFE4 00000000 */   nop
    /* 28EFE8 0038EFE8 D8370E0C */  jal        func_0038df60
    /* 28EFEC 0038EFEC 00000000 */   nop
  .L0038EFF0:
    /* 28EFF0 0038EFF0 1000BFDF */  ld         $31, 0x10($29)
    /* 28EFF4 0038EFF4 0000B07B */  lq         $16, 0x0($29)
    /* 28EFF8 0038EFF8 2000BD27 */  addiu      $29, $29, 0x20
    /* 28EFFC 0038EFFC 0800E003 */  jr         $31
    /* 28F000 0038F000 00000000 */   nop
    /* 28F004 0038F004 00000000 */  nop
    /* 28F008 0038F008 00000000 */  nop
    /* 28F00C 0038F00C 00000000 */  nop
.size func_0038ee40, 0x1d0
