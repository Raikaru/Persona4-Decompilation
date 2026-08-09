.section .text
.set noat
.set noreorder
glabel func_0050aea8
    /* 40AEA8 0050AEA8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40AEAC 0050AEAC 0000BFFF */  sd         $31, 0x0($29)
    /* 40AEB0 0050AEB0 A639140C */  jal        func_0050e698
    /* 40AEB4 0050AEB4 B800858C */   lw        $5, 0xB8($4)
    /* 40AEB8 0050AEB8 2D184000 */  daddu      $3, $2, $0
    /* 40AEBC 0050AEBC 51000224 */  addiu      $2, $0, 0x51
    /* 40AEC0 0050AEC0 03006210 */  beq        $3, $2, .L0050AED0
    /* 40AEC4 0050AEC4 61000424 */   addiu     $4, $0, 0x61
    /* 40AEC8 0050AEC8 03006414 */  bne        $3, $4, .L0050AED8
    /* 40AECC 0050AECC 0000BFDF */   ld        $31, 0x0($29)
  .L0050AED0:
    /* 40AED0 0050AED0 41000324 */  addiu      $3, $0, 0x41
    /* 40AED4 0050AED4 0000BFDF */  ld         $31, 0x0($29)
  .L0050AED8:
    /* 40AED8 0050AED8 2D106000 */  daddu      $2, $3, $0
    /* 40AEDC 0050AEDC 0800E003 */  jr         $31
    /* 40AEE0 0050AEE0 1000BD27 */   addiu     $29, $29, 0x10
    /* 40AEE4 0050AEE4 00000000 */  nop
.size func_0050aea8, 0x40
